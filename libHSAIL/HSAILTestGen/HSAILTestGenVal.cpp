#include "HSAILTestGenVal.h"

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
    // normalized so that x-th digit is at 63d bit of u64_t
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

    T normalize() const
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
        if (val_vec->unlock() == 0) delete val_vec;
        val_vec = 0;
    }
}

void Val::copy(const Val& val)
{
    setProps(val.type, val.signExpEnabled()); 

    if (val.isVector()) {
        val_vec = val.val_vec;
        val_vec->lock();
    } else {
        val_u64 = val.val_u64;
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
    val_vec = new ValVector(dim, v0, v1, v2, v3);
    assert(val_vec);
    val_vec->lock();

    for (unsigned i = 1; i < dim; ++i) 
    {
        assert((*val_vec)[0].getType() == (*val_vec)[i].getType());
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
    return isVector()? val_vec->getDim() : 1;
}

unsigned Val::getVecType() const 
{ 
    return isVector()? val_vec->getType() : Brig::BRIG_TYPE_NONE; 
}

Val Val::operator[](unsigned i) const
{
    if (isVector()) {
        assert(i < getDim());
        return (*val_vec)[i];
    } else {
        assert(i == 0);
        return *this;
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// FP-specific Val operations

#define GET_FLOAT_PROP(prop)  bool Val::prop() const { return isFloat() && (isX64()? FloatProp64(val_u64).prop() : FloatProp32(val_u32).prop()); }

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
    
u64_t Val::getNormalizedFract(int delta /*=0*/) const 
{ 
    assert(isFloat());  
    return isX64()? FloatProp64(val_u64).getNormalizedFract(delta) : FloatProp32(val_u32).getNormalizedFract(delta); 
}

Val Val::copySign(Val v) const 
{
    assert(isFloat());  
    assert(getType() == v.getType());  

    if (isX64()) 
    {
        return Val(getType(), FloatProp64(val_u64).copySign(v.val_u64));
    }
    else
    {
        return Val(getType(), FloatProp32(val_u32).copySign(v.val_u32));
    }
}

Val Val::normalize() const 
{ 
    if (isFloat())
    {
        return Val(getType(), isX64()? FloatProp64(val_u64).normalize() : FloatProp32(val_u32).normalize());
    }
    return *this;
}

Val Val::ftz() const 
{ 
    if (isFloat())
    {
        if (isNegativeSubnormal()) return getNegativeZero();
        if (isPositiveSubnormal()) return getPositiveZero();
    }
    return *this;
}

Val Val::getQuietNan()     const { assert(isFloat()); return isX64()? Val(getType(), FloatProp64::getQuietNan())     : Val(getType(), FloatProp32::getQuietNan());     }
Val Val::getNegativeZero() const { assert(isFloat()); return isX64()? Val(getType(), FloatProp64::getNegativeZero()) : Val(getType(), FloatProp32::getNegativeZero()); }
Val Val::getPositiveZero() const { assert(isFloat()); return isX64()? Val(getType(), FloatProp64::getPositiveZero()) : Val(getType(), FloatProp32::getPositiveZero()); }
Val Val::getNegativeInf()  const { assert(isFloat()); return isX64()? Val(getType(), FloatProp64::getNegativeInf())  : Val(getType(), FloatProp32::getNegativeInf());  }
Val Val::getPositiveInf()  const { assert(isFloat()); return isX64()? Val(getType(), FloatProp64::getPositiveInf())  : Val(getType(), FloatProp32::getPositiveInf());  }

//=============================================================================
//=============================================================================
//=============================================================================
// Val conversions 

u64_t Val::conv2b64(bool expandSignedInt /*=true*/, bool convFloat /*=false*/) const
{
    using namespace Brig;
    assert(!empty() && !isVector());

    u64_t res = 0;

    if (isSignedInt() && expandSignedInt && signExpEnabled())
    {
        switch(getType())
        {
        case BRIG_TYPE_S8:  res = static_cast<u64_t>(static_cast<s64_t>(s8()));  break;
        case BRIG_TYPE_S16: res = static_cast<u64_t>(static_cast<s64_t>(s16())); break;
        case BRIG_TYPE_S32: res = static_cast<u64_t>(static_cast<s64_t>(s32())); break;
        case BRIG_TYPE_S64: res = static_cast<u64_t>(static_cast<s64_t>(s64())); break;
        default: assert(false); return 0;
        }
    }
    else if (isFloat() && convFloat)
    {
        switch(getType())
        {
        case BRIG_TYPE_F32: res = Val(static_cast<f64_t>(f32())).b64(); break;
        case BRIG_TYPE_F64: res = b64();                                break;
        default: assert(false); return 0;
        }
    }
    else
    {
        switch(getTypeSize(getType()))
        {
        case 1:  res = static_cast<u64_t>(val_u8);  break;
        case 8:  res = static_cast<u64_t>(val_u8);  break;
        case 16: res = static_cast<u64_t>(val_u16); break;
        case 32: res = static_cast<u64_t>(val_u32); break;
        case 64: res = static_cast<u64_t>(val_u64); break;
        default: 
            assert(false); return 0;
        }
    }

    return res;
}

u32_t Val::conv2b32(bool expandSignedInt /*=true*/, bool convFloat /*=false*/) const
{
    return static_cast<u32_t>(conv2b64(expandSignedInt, convFloat));
}

u32_t Val::conv2b32hi(bool expandSignedInt /*=true*/, bool convFloat /*=false*/) const
{
    return static_cast<u32_t>(conv2b64(expandSignedInt, convFloat) >> 32);
}

//=============================================================================
//=============================================================================
//=============================================================================
// 

void Val::randomize() // FIXME
{
    assert(!empty() && !isVector());

    val_u64 = ((((u64_t)rand()) & 0xFF) << 56)
            | ((((u64_t)rand()) & 0xFF) << 48)
            | ((((u64_t)rand()) & 0xFF) << 40)
            | ((((u64_t)rand()) & 0xFF) << 32)
            | ((((u64_t)rand()) & 0xFF) << 24)
            | ((((u64_t)rand()) & 0xFF) << 16)
            | ((((u64_t)rand()) & 0xFF) << 8)
            |  (((u64_t)rand()) & 0xFF);
}

//=============================================================================
//=============================================================================
//=============================================================================
// Val dumping

string Val::str() const
{
    using namespace Brig;
    assert(!empty() && !isVector());

    if (isSpecialFloat()) return nan2str();

    ostringstream s;

    switch (getType())
    {
    case BRIG_TYPE_S8:  s << static_cast<s32_t>(s8()); break;
    case BRIG_TYPE_S16: s << s16();                    break;
    case BRIG_TYPE_S32: s << s32();                    break;
    case BRIG_TYPE_S64: s << s64();                    break;
    case BRIG_TYPE_F32: s << f32();                    break;
    case BRIG_TYPE_F64: s << f64();                    break;
    default:            s << conv2b64();               break;
    }

    return s.str();
}

string Val::hexStr() const
{
    using namespace Brig;
    assert(!empty() && !isVector());

    ostringstream s;
    s << "0x" << setbase(16);

    switch (getType())
    {
    case BRIG_TYPE_S8:  s << (s8() & 0xFF);            break;
    case BRIG_TYPE_S16: s << s16();                    break;
    case BRIG_TYPE_S32: s << s32();                    break;
    case BRIG_TYPE_S64: s << s64();                    break;
    default:            s << conv2b64();               break;
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
        for (unsigned i = 0; i < val_vec->getDim(); ++i) 
        {
            const char* pref = (i > 0)? ", " : "";
            sval += pref + (*val_vec)[i].str();
            hval += pref + (*val_vec)[i].hexStr();
        }
        return "(" + sval + ") [" + hval + "]";
    } 
    else 
    {
        return str() + " [" + hexStr() + "]";
    }
}

string Val::nan2str() const
{
    assert(isSpecialFloat());

    return string(isNegative()? "Negative " : "Positive ") + (isNan()? (isSignalingNan()? "Signaling NaN"  : "Quiet NaN") : "Infinity");
}

//=============================================================================
//=============================================================================
//=============================================================================

} // namespace TESTGEN

