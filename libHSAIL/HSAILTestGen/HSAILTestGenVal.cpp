#include "HSAILTestGenVal.h"
#include "HSAILUtilities.h"

#include <iomanip>

using std::setprecision;

using HSAIL_ASM::isSignedType;
using HSAIL_ASM::isUnsignedType;
using HSAIL_ASM::isPackedType;
using HSAIL_ASM::isUnrPacking;
using HSAIL_ASM::packedType2baseType;
using HSAIL_ASM::packedType2elementType;
using HSAIL_ASM::getPackingControl;
using HSAIL_ASM::pack2str;

namespace TESTGEN {

//=============================================================================
//=============================================================================
//=============================================================================
// Decoder of IEEE 754 float properties

// IEEE 754 (32-bit)
//
//         S   (E-127)       23
// F = (-1) * 2        (1+M/2  )
//
// S - sign 
// E - exponent
// M - mantissa
//
// Special cases:
//  ----------------------------------------------
//  | S EXP MANTISSA  | MEANING         | NOTES  |
//  ----------------------------------------------
//  | 0 000 00.....0  | +0              |        |
//  | 1 000 00.....0  | -0              |        |
//  | 0 111 00.....0  | +INF            |        |
//  | 1 111 00.....0  | -INF            |        |
//  | X 111 1?.....?  | NAN (quiet)     |        |
//  | X 111 0?.....?  | NAN (signaling) | M != 0 |
//  | X 000 ??.....?  | SUBNORMAL       | M != 0 |
//  ----------------------------------------------
// 

template<typename T, T sign_mask, T exponent_mask, T mantissa_mask, T nanType_mask, unsigned exponentBias, unsigned mantissaWidth> 
class IEEE754
{
private:
    static const T SIGN_MASK     = sign_mask;
    static const T EXPONENT_MASK = exponent_mask;
    static const T MANTISSA_MASK = mantissa_mask;
    static const T NAN_TYPE_MASK = nanType_mask;

    static const unsigned EXPONENT_BIAS  = exponentBias;
    static const unsigned MANTISSA_WIDTH = mantissaWidth;

private:
    const T bits;

public:
    IEEE754(T val) : bits(val) {}

private:
    T getSign()      const { return bits & SIGN_MASK; }
    T getMantissa()  const { return bits & MANTISSA_MASK; }
    T getExponent()  const { return bits & EXPONENT_MASK; }
    T getNanType()   const { return bits & NAN_TYPE_MASK; }

public:
    bool isPositive()          const { return getSign() == 0; }
    bool isNegative()          const { return getSign() != 0; }

    bool isZero()              const { return getExponent() == 0 && getMantissa() == 0; }
    bool isPositiveZero()      const { return isZero() && isPositive();  }
    bool isNegativeZero()      const { return isZero() && !isPositive(); }
                               
    bool isInf()               const { return getExponent() == EXPONENT_MASK && getMantissa() == 0; }
    bool isPositiveInf()       const { return isInf() && isPositive();  }
    bool isNegativeInf()       const { return isInf() && !isPositive(); }
                               
    bool isNan()               const { return getExponent() == EXPONENT_MASK && getMantissa() != 0; }
    bool isQuietNan()          const { return isNan() && getNanType() != 0; }
    bool isSignalingNan()      const { return isNan() && getNanType() == 0; }

    bool isSubnormal()         const { return getExponent() == 0 && getMantissa() != 0; }
    bool isPositiveSubnormal() const { return isSubnormal() && isPositive(); }
    bool isNegativeSubnormal() const { return isSubnormal() && !isPositive(); }

    bool isRegularPositive()   const { return isPositive() && !isZero() && !isNan() && !isInf(); }
    bool isRegularNegative()   const { return isNegative() && !isZero() && !isNan() && !isInf(); }

                                                // Natural = (fraction == 0)
                                                // getNormalizedFract() return 0 for small numbers so there is exponent check for this case
    bool isNatural()           const { return isZero() || (getNormalizedFract() == 0 && (getExponent() >> MANTISSA_WIDTH) >= EXPONENT_BIAS); }

public:
    static T getQuietNan()     { return EXPONENT_MASK | NAN_TYPE_MASK; }
    static T getNegativeZero() { return SIGN_MASK; }
    static T getPositiveZero() { return 0; }
    static T getNegativeInf()  { return SIGN_MASK | EXPONENT_MASK; }
    static T getPositiveInf()  { return             EXPONENT_MASK; }

public:
    // Return fractional part of fp number 
    // normalized so that x-th digit is at (63-x)-th bit of u64_t
    u64_t getNormalizedFract(int x = 0) const
    {
        if (isZero() || isInf() || isNan()) return 0;

        u64_t mantissa = getMantissa() | (MANTISSA_MASK + 1); // Highest bit of mantissa is not encoded but assumed
        int exponent = static_cast<int>(getExponent() >> MANTISSA_WIDTH);
        
        // Compute shift required to place 1st fract bit at 63d bit of u64_t
        int width = static_cast<int>(sizeof(u64_t) * 8);
        int shift = (exponent - EXPONENT_BIAS) + (width - MANTISSA_WIDTH) + x;
        if (shift <= -width || width <= shift) return 0;
        return (shift >= 0)? mantissa << shift : mantissa >> (-shift);
    }

    T copySign(T v) const { return (v & SIGN_MASK) | getExponent() | getMantissa(); }

    T normalize() const // Clear NaN payload
    {
        if (isQuietNan()) return getSign() | getExponent() | getNanType();
        return bits;
    }
};

//=============================================================================
//=============================================================================
//=============================================================================
// Decoders for IEEE 754 float and double numbers

typedef IEEE754
    <
        u32_t, 
        0x80000000,  // Sign       
        0x7f800000,  // Exponent       
        0x007fffff,  // Mantissa       
        0x00400000,  // NAN type
        127,         // Exponent bias
        23           // Mantissa width
    > FloatProp32; 

typedef IEEE754
    <
        u64_t, 
        0x8000000000000000ULL,  // Sign     
        0x7ff0000000000000ULL,  // Exponent 
        0x000fffffffffffffULL,  // Mantissa 
        0x0008000000000000ULL,  // NAN type
        1023,                   // Exponent bias
        52                      // Mantissa width
    > FloatProp64; 

//=============================================================================
//=============================================================================
//=============================================================================
// ValVector - a container for values stored in vector operands

class ValVector
{
private:
    Val val[4];         // Up to 4 values
    unsigned dim;       // Number of stores values
    unsigned refCount;  // Number of owners; used for deallocation

private:
    ValVector(const ValVector&); // non-copyable
    ValVector &operator=(const ValVector &); // not assignable

public:
    ValVector(unsigned dim, Val v0, Val v1, Val v2, Val v3)
    { 
        assert(2 <= dim && dim <= 4);
        assert(!v0.empty() && !v1.empty());
        assert(!v0.isVector() && !v1.isVector() && !v2.isVector() && !v3.isVector());

        this->dim = dim;
        refCount = 0;

        val[0] = v0; 
        val[1] = v1; 
        val[2] = v2; 
        val[3] = v3; 
    }

public:
    unsigned getDim()          const { return dim; }
    unsigned getType()         const { return val[0].getType(); }
    Val operator[](unsigned i) const { assert(i < dim); return val[i]; }

public:
    unsigned lock()   {                       return ++refCount; }
    unsigned unlock() { assert(refCount > 0); return --refCount; }
};

//=============================================================================
//=============================================================================
//=============================================================================
// Val initialization, destruction and related operations

void Val::clean()
{
    if (isVector()) 
    {
        if (vector->unlock() == 0) delete vector;
        vector = 0;
    }
}

void Val::copy(const Val& val)
{
    setProps(val.type); 

    if (val.isVector()) {
        vector = val.vector;
        vector->lock();
    } else {
        num = val.num;
    }
}

Val::~Val()
{
    clean();
}

Val::Val(unsigned dim, Val v0, Val v1, Val v2, Val v3)
{
    assert(2 <= dim && dim <= 4);
    
    setProps(Brig::BRIG_TYPE_NONE);
    num.clear();

    vector = new ValVector(dim, v0, v1, v2, v3);
    assert(vector);
    vector->lock();

    for (unsigned i = 1; i < dim; ++i) 
    {
        assert((*vector)[0].getType() == (*vector)[i].getType());
    }
}

Val::Val(const Val& val)
{
    copy(val);
}

Val& Val::operator=(const Val& val)
{
    if (this != &val) 
    {
        clean();
        copy(val);
    }
    return *this;
}

unsigned Val::getDim() const
{
    return isVector()? vector->getDim() : 1;
}

unsigned Val::getVecType() const 
{ 
    return isVector()? vector->getType() : Brig::BRIG_TYPE_NONE; 
}

Val Val::operator[](unsigned i) const
{
    if (isVector()) {
        assert(i < getDim());
        return (*vector)[i];
    } else {
        assert(i == 0);
        return *this;
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Operations with packed values

u64_t Val::getElement(unsigned idx) const       
{ 
    assert(isPacked());
    assert(idx < getPackedTypeDim(getType()));

    return num.getElement(packedType2elementType(getType()), idx); 
}

void  Val::setElement(unsigned idx, u64_t val)
{ 
    assert(isPacked());
    assert(idx < getPackedTypeDim(getType()));

    num.setElement(val, packedType2elementType(getType()), idx);
}

Val Val::getPackedElement(unsigned elementIdx, unsigned packing /*=BRIG_PACK_P*/, unsigned srcOperandIdx /*=0*/) const
{
    assert(srcOperandIdx == 0 || srcOperandIdx == 1);
    assert(pack2str(packing));

    if (empty())
    {
        assert(srcOperandIdx == 1 && isUnrPacking(packing));
        return *this;
    }
    else if (isPacked())
    {
        assert(elementIdx < getPackedTypeDim(getType()));

        unsigned idx = (getPackingControl(srcOperandIdx, packing) == 'p')? elementIdx : 0;
        u64_t element = getElement(idx);
        return Val(packedType2baseType(getType()), element);
    }
    else // Special case for SHL/SHR
    {
        assert(getType() == Brig::BRIG_TYPE_U32);
        assert(packing == Brig::BRIG_PACK_PP);
        return *this; // shift all elements by the same amount
    }
}

void Val::setPackedElement(unsigned elementIdx, Val dst)
{
    assert(isPacked());
    assert(!dst.isPacked());
    assert(dst.getType() == packedType2baseType(getType()));
    assert(elementIdx < getPackedTypeDim(getType()));

    // It is assumed that dst does not need sign-extension
    setElement(elementIdx, dst.num.get<u64_t>());
}

//=============================================================================
//=============================================================================
//=============================================================================
// Operations on scalar floating-point values

#define GET_FLOAT_PROP(x) \
    bool Val::x() const   \
    {                     \
        assert(!isF16()); \
        return isFloat() && (isF64()? FloatProp64(num.get<u64_t>()).x()   \
                                    : FloatProp32(num.get<u32_t>()).x()); \
    }

GET_FLOAT_PROP(isPositive)
GET_FLOAT_PROP(isNegative)
GET_FLOAT_PROP(isZero)
GET_FLOAT_PROP(isPositiveZero)
GET_FLOAT_PROP(isNegativeZero)
GET_FLOAT_PROP(isInf)
GET_FLOAT_PROP(isPositiveInf) 
GET_FLOAT_PROP(isNegativeInf) 
GET_FLOAT_PROP(isNan)
GET_FLOAT_PROP(isQuietNan)
GET_FLOAT_PROP(isSignalingNan)
GET_FLOAT_PROP(isSubnormal)
GET_FLOAT_PROP(isPositiveSubnormal)
GET_FLOAT_PROP(isNegativeSubnormal)
GET_FLOAT_PROP(isRegularPositive)
GET_FLOAT_PROP(isRegularNegative)
GET_FLOAT_PROP(isNatural)
    
#define GET_FLOAT_NUMBER(x) \
    Val Val::x() const      \
    {                       \
        assert(isFloat());  \
        assert(!isF16());   \
        return isF64()? Val(getType(), FloatProp64::x())  \
                      : Val(getType(), FloatProp32::x()); \
    }

GET_FLOAT_NUMBER(getQuietNan)
GET_FLOAT_NUMBER(getNegativeZero)
GET_FLOAT_NUMBER(getPositiveZero)
GET_FLOAT_NUMBER(getNegativeInf)
GET_FLOAT_NUMBER(getPositiveInf)

u64_t Val::getNormalizedFract(int delta /*=0*/) const 
{ 
    assert(isFloat());  
    assert(!isF16());
    return isF64()? FloatProp64(num.get<u64_t>()).getNormalizedFract(delta)
                  : FloatProp32(num.get<u32_t>()).getNormalizedFract(delta);
}

Val Val::copySign(Val v) const 
{
    assert(isFloat());  
    assert(!isF16());
    assert(getType() == v.getType());

    return isF64()? Val(getType(), FloatProp64(num.get<u64_t>()).copySign(v.num.get<u64_t>()))
                  : Val(getType(), FloatProp32(num.get<u32_t>()).copySign(v.num.get<u32_t>()));
}

//=============================================================================
//=============================================================================
//=============================================================================
// Operations on scalar/packed floating-point values

struct op_normalize  // Clear NaN payload
{ 
    Val operator()(Val v) 
    {
        assert(!v.isF16());
        if (!v.isFloat()) return v;
        return Val(v.getType(), v.isF64()? FloatProp64(v.getAsB64()).normalize() : FloatProp32(v.getAsB32()).normalize());
    }
};

struct op_ftz   // Force subnormals to 0
{ 
    Val operator()(Val v) 
    {
        assert(!v.isF16());
        if (v.isNegativeSubnormal()) return v.getNegativeZero();
        if (v.isPositiveSubnormal()) return v.getPositiveZero();
        return v;
    }
};

Val Val::normalize() const { return transform(op_normalize()); }
Val Val::ftz()       const { return transform(op_ftz()); }

//=============================================================================
//=============================================================================
//=============================================================================
// Randomization

struct op_s2q  // Replace Signaling NaNs with Quiet ones
{ 
    Val operator()(Val v) 
    {
        assert(!v.isF16());
        if (v.isSignalingNan()) return v.getQuietNan();
        return v;
    }
};

Val Val::randomize() const
{
    assert(!empty() && !isVector());

    Val res = *this;
    unsigned dim = getSize() / 8; // NB: 0 for b1; it is ok

    for (unsigned i = 0; i < dim; ++i) res.num.setElement(rand(), Brig::BRIG_TYPE_U8, i);
    
    res = res.transform(op_s2q());  // Signaling NaNs are not supported, replace with quiet
    res = res.normalize();          // Clear NaN payload
    return res;
}

//=============================================================================
//=============================================================================
//=============================================================================
// Val dumping

static unsigned getTextWidth(unsigned type)
{
    if (type == Brig::BRIG_TYPE_F32) return 16;
    if (type == Brig::BRIG_TYPE_F64) return 24;

    switch (getTypeSize(type))
    {
    case 8:  return 4;
    case 16: return 6;
    case 32: return 11;
    case 64: return 20;
    default: return 0;  // handled separately
    }
}

string Val::luaStr(unsigned idx /*=0*/) const
{
    using namespace Brig;

    assert(!isPackedFloat());
    assert(0 <= idx && idx <= 3);
    assert(!empty() && !isVector());
    assert(!isF16());

    ostringstream s;

    unsigned w = getTextWidth(getType());
    if (isFloat()) w += 2;
    s << setw(w);

    if (isSpecialFloat())
    {
        s << nan2str();
    }
    else
    {    
        char buffer[32];    
    
        switch (getType())
        {
        case BRIG_TYPE_F32: sprintf(buffer,  "\"%.6A\"", f32()); s << string(buffer); break;
        case BRIG_TYPE_F64: sprintf(buffer, "\"%.13A\"", f64()); s << string(buffer); break;

        case BRIG_TYPE_S8:  s << static_cast<s32_t>(s8());     break;
        case BRIG_TYPE_S16: s << s16();                        break;
        case BRIG_TYPE_S32: s << s32();                        break;
        
        default: s << setw(getTextWidth(BRIG_TYPE_U32)) << getAsB32(idx); break;
        }
    }

    return s.str();
}

string Val::decDump() const
{
    using namespace Brig;
    assert(!empty() && !isVector());
    assert(getSize() != 128);
    assert(!isPacked());
    assert(!isF16());

    ostringstream s;

    s << setw(getTextWidth(getType()));

    if (isSpecialFloat())
    {
        s << nan2str();
    }
    else
    {
        switch (getType())
        {
        case BRIG_TYPE_F32: s << setprecision(9)  << f32(); break;
        case BRIG_TYPE_F64: s << setprecision(17) << f64(); break;

        case BRIG_TYPE_S8:  s << static_cast<s32_t>(s8());  break;
        case BRIG_TYPE_S16: s << s16();                     break;
        case BRIG_TYPE_S32: s << s32();                     break;
        case BRIG_TYPE_S64: s << s64();                     break;

        default:            s << getAsB64();                break;
        }
    }

    return s.str();
}

string Val::hexDump() const
{
    using namespace Brig;
    assert(!empty() && !isVector());
    assert(getSize() != 128);
    assert(!isPacked());
    assert(!isF16());

    ostringstream s;
    s << "0x" << setbase(16) << setfill('0') << setw(getSize() / 4);

    switch (getType())
    {
    case BRIG_TYPE_S8:   s << (s8() & 0xFF);            break;
    case BRIG_TYPE_S16:  s << s16();                    break;
    case BRIG_TYPE_S32:  s << s32();                    break;
    case BRIG_TYPE_S64:  s << s64();                    break;
    default:             s << getAsB64();               break;
    }

    return s.str();
}

string Val::dump() const
{
    assert(!empty());

    if (isVector()) 
    {
        string sval;
        string hval;
        for (unsigned i = 0; i < vector->getDim(); ++i)
        {
            const char* pref = (i > 0)? ", " : "";
            sval += pref + (*vector)[i].decDump();
            hval += pref + (*vector)[i].hexDump();
        }
        return "(" + sval + ") [" + hval + "]";
    } 
    else if (getType() == Brig::BRIG_TYPE_B128)
    {
        return b128().hexDump(); 
    }
    else if (isPackedType(getType()))
    {
        return dumpPacked();
    }
    else 
    {
        return decDump() + " [" + hexDump() + "]";
    }
}

string Val::dumpPacked() const
{
    assert(!empty());
    assert(!isVector());

    ostringstream s;
    ostringstream h;

    unsigned etype = getElementType();
    unsigned dim   = getPackedTypeDim(getType());
    unsigned width = getTypeSize(getType()) / dim;

    if      (isSignedType(etype))   s << "_s";
    else if (isUnsignedType(etype)) s << "_u";
    else                            s << "_f";

    s << width << "x" << dim << "(";
    h << setbase(16) << setfill('0') << "[";

    for (unsigned i = 0; i < dim; ++i)
    {
        if (i > 0) { s << ", "; h << ", "; }
        
        Val val(etype, getElement(dim - i - 1));

        s << val.decDump();
        h << val.hexDump();
    }

    s << ")";
    h << "]";

    return s.str() + " " + h.str();
}

string Val::nan2str() const
{
    assert(isSpecialFloat());
    assert(!isSignalingNan());

    return isNan()? "NAN" : isPositiveInf()? "INF" : "-INF";
}

//=============================================================================
//=============================================================================
//=============================================================================

} // namespace TESTGEN

