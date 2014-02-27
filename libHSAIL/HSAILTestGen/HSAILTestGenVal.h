//===-- HSAILTestGenSample.h - HSAIL Test Generator Val Container ---------===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_VAL_H
#define INCLUDED_HSAIL_TESTGEN_VAL_H

#include "Brig.h"
#include "HSAILUtilities.h"
#include "HSAILItems.h"

#include <assert.h>
#include <string>
#include <sstream>
#include <iomanip>

using std::string;
using std::ostringstream;
using std::setbase;
using std::setw;
using std::setfill;

using Brig::BRIG_PACK_P;
using Brig::BRIG_TYPE_NONE;

using HSAIL_ASM::Directive;
using HSAIL_ASM::Inst;
using HSAIL_ASM::Operand;

using HSAIL_ASM::isPackedType;
using HSAIL_ASM::getTypeSize;
using HSAIL_ASM::getPackedTypeDim;
using HSAIL_ASM::packedType2elementType;

#include <stdint.h>

namespace TESTGEN {

// ============================================================================
// ============================================================================
// ============================================================================
// HSAIL s/u/f Types

typedef int8_t   s8_t;
typedef int16_t  s16_t;
typedef int32_t  s32_t;
typedef int64_t  s64_t;

typedef uint8_t  u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;

typedef float    f32_t;
typedef double   f64_t;

// ============================================================================
// ============================================================================
// ============================================================================
// HSAIL Type Helpers

class b128_t
{
private:
    u64_t  data[2];

public:
    void clear() { set<u64_t>(0, 0); set<u64_t>(0, 1); }
    template<typename T> void init(T val) { clear(); set(val); }

    template<typename T> 
    T get(unsigned idx = 0) const 
    { 
        assert(idx < 16 / sizeof(T));
        return reinterpret_cast<const T*>(this)[idx];
    }

    template<typename T> 
    void set(T val, unsigned idx = 0) 
    { 
        assert(idx < 16 / sizeof(T));
        reinterpret_cast<T*>(this)[idx] = val;
    }

public:
    // Get value with sign-extension
    u64_t getElement(unsigned type, unsigned idx = 0) const 
    { 
        using namespace Brig;

        assert(idx < 128 / getTypeSize(type));

        switch(type)
        {
        case BRIG_TYPE_S8:  return static_cast<s64_t>(get<s8_t> (idx));
        case BRIG_TYPE_S16: return static_cast<s64_t>(get<s16_t>(idx));
        case BRIG_TYPE_S32: return static_cast<s64_t>(get<s32_t>(idx));
        case BRIG_TYPE_S64: return static_cast<s64_t>(get<s64_t>(idx));

        case BRIG_TYPE_U8:  return get<u8_t>(idx);
        case BRIG_TYPE_U16: return get<u16_t>(idx);
        case BRIG_TYPE_U32: return get<u32_t>(idx);
        case BRIG_TYPE_U64: return get<u64_t>(idx);

        case BRIG_TYPE_F32: return get<u32_t>(idx);
        case BRIG_TYPE_F64: return get<u64_t>(idx);

        case BRIG_TYPE_F16:
        default:
            assert(false);
            return 0;
        }
    }

    void setElement(u64_t val, unsigned type, unsigned idx = 0)
    { 
        using namespace Brig;

        assert(idx < 128 / getTypeSize(type));

        switch(type)
        {
        case BRIG_TYPE_S8:  set(static_cast<s8_t> (val), idx); return;
        case BRIG_TYPE_S16: set(static_cast<s16_t>(val), idx); return;
        case BRIG_TYPE_S32: set(static_cast<s32_t>(val), idx); return;
        case BRIG_TYPE_S64: set(static_cast<s64_t>(val), idx); return;

        case BRIG_TYPE_U8:  set(static_cast<u8_t> (val), idx); return;
        case BRIG_TYPE_U16: set(static_cast<u16_t>(val), idx); return;
        case BRIG_TYPE_U32: set(static_cast<u32_t>(val), idx); return;
        case BRIG_TYPE_U64: set(static_cast<u64_t>(val), idx); return;

        case BRIG_TYPE_F32: set(static_cast<u32_t>(val), idx); return;
        case BRIG_TYPE_F64: set(static_cast<u64_t>(val), idx); return;

        case BRIG_TYPE_F16:
        default:
            assert(false);
            return;
        }
    }

public:
    bool operator==(const b128_t& rhs) const { return (get<u64_t>(0) == rhs.get<u64_t>(0)) && (get<u64_t>(1) == rhs.get<u64_t>(1)); }

    string hexDump() const 
    { 
        ostringstream s; 
        s << "_b128(";
        s << setbase(16) << setfill('0');
        s << "0x" << setw(8) << get<u32_t>(3) << ",";
        s << "0x" << setw(8) << get<u32_t>(2) << ",";
        s << "0x" << setw(8) << get<u32_t>(1) << ",";
        s << "0x" << setw(8) << get<u32_t>(0) << ")";
        return s.str(); 
    }
};

template <typename OS> inline OS& operator <<(OS& os, const b128_t& v) { os << v.hexDump(); return os; }

// ============================================================================
// ============================================================================
// ============================================================================
// HSAIL Type Class

template<typename T, typename E, unsigned HsailTypeId>
struct HsailType
{
public:
    typedef T BaseType;
    typedef E ElemType;
    static const unsigned typeId = HsailTypeId;

private:
    BaseType val;

public:
    HsailType() {}
    HsailType(const BaseType v) : val(v) {}
    bool operator==(const HsailType& rhs) const { return val == rhs.val; }
    operator BaseType() const { return val; }
    BaseType get() const { return val; }
};

// ============================================================================
// ============================================================================
// ============================================================================
// HSAIL Bit Types

typedef HsailType<u8_t,  u8_t,  Brig::BRIG_TYPE_B1>  b1_t;
typedef HsailType<u8_t,  u8_t,  Brig::BRIG_TYPE_B8>  b8_t;
typedef HsailType<u16_t, u16_t, Brig::BRIG_TYPE_B16> b16_t;
typedef HsailType<u32_t, u32_t, Brig::BRIG_TYPE_B32> b32_t;
typedef HsailType<u64_t, u64_t, Brig::BRIG_TYPE_B64> b64_t;

//=============================================================================
//=============================================================================
//=============================================================================
// HSAIL Packed Types

typedef HsailType<u32_t,  u8_t,  Brig::BRIG_TYPE_U8X4 > u8x4_t;
typedef HsailType<u32_t,  u16_t, Brig::BRIG_TYPE_U16X2> u16x2_t;
typedef HsailType<u64_t,  u8_t,  Brig::BRIG_TYPE_U8X8 > u8x8_t;
typedef HsailType<u64_t,  u16_t, Brig::BRIG_TYPE_U16X4> u16x4_t;
typedef HsailType<u64_t,  u32_t, Brig::BRIG_TYPE_U32X2> u32x2_t;
typedef HsailType<b128_t, u8_t,  Brig::BRIG_TYPE_U8X16> u8x16_t;
typedef HsailType<b128_t, u16_t, Brig::BRIG_TYPE_U16X8> u16x8_t;
typedef HsailType<b128_t, u32_t, Brig::BRIG_TYPE_U32X4> u32x4_t;
typedef HsailType<b128_t, u64_t, Brig::BRIG_TYPE_U64X2> u64x2_t;

typedef HsailType<u32_t,  s8_t,  Brig::BRIG_TYPE_S8X4 > s8x4_t;
typedef HsailType<u32_t,  s16_t, Brig::BRIG_TYPE_S16X2> s16x2_t;
typedef HsailType<u64_t,  s8_t,  Brig::BRIG_TYPE_S8X8 > s8x8_t;
typedef HsailType<u64_t,  s16_t, Brig::BRIG_TYPE_S16X4> s16x4_t;
typedef HsailType<u64_t,  s32_t, Brig::BRIG_TYPE_S32X2> s32x2_t;
typedef HsailType<b128_t, s8_t,  Brig::BRIG_TYPE_S8X16> s8x16_t;
typedef HsailType<b128_t, s16_t, Brig::BRIG_TYPE_S16X8> s16x8_t;
typedef HsailType<b128_t, s32_t, Brig::BRIG_TYPE_S32X4> s32x4_t;
typedef HsailType<b128_t, s64_t, Brig::BRIG_TYPE_S64X2> s64x2_t;

//typedef HsailType<u32_t,  f16_t, Brig::BRIG_TYPE_F16X2> f16x2_t;
//typedef HsailType<u64_t,  f16_t, Brig::BRIG_TYPE_F16X4> f16x4_t;
typedef HsailType<u64_t,  f32_t, Brig::BRIG_TYPE_F32X2> f32x2_t;
//typedef HsailType<b128_t, f16_t, Brig::BRIG_TYPE_F16X8> f16x8_t;
typedef HsailType<b128_t, f32_t, Brig::BRIG_TYPE_F32X4> f32x4_t;
typedef HsailType<b128_t, f64_t, Brig::BRIG_TYPE_F64X2> f64x2_t;

// ============================================================================
// ============================================================================
// ============================================================================
// Packing routines for packed data

inline b128_t b128(u64_t lo, u64_t hi) { b128_t res; res.set(lo, 0); res.set(hi, 1); return res; }

template<typename T, typename E>
inline T pack(E x0,     E x1,     E x2 = 0,  E x3 = 0,  E x4 = 0,  E x5 = 0,  E x6 = 0,  E x7 = 0,
              E x8 = 0, E x9 = 0, E x10 = 0, E x11 = 0, E x12 = 0, E x13 = 0, E x14 = 0, E x15 = 0) 
{ 
    b128_t res; 
    unsigned dim = sizeof(T) / sizeof(E);
    E data[16] = {x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15};

    for (unsigned i = 0; i < dim; ++i) res.set(data[i], dim - i - 1);
    for (unsigned i = dim; i < 16; ++i) { assert(data[i] == (E)0); }

    return res.get<T>(); 
}

template<typename T, typename E>
inline T fillBits(E x, unsigned mask = 0xFFFFFFFF) 
{ 
    b128_t res; 
    unsigned dim = sizeof(T) / sizeof(E);
    
    for (unsigned i = 0; i < dim; ++i, mask >>= 1) res.set(static_cast<E>(x * (i + 1) * (mask & 0x1)), i);

    return res.get<T>(); 
}

#define u8x4  pack<u8x4_t,  u8_t>
#define u8x8  pack<u8x8_t,  u8_t>
#define u8x16 pack<u8x16_t, u8_t>
#define u16x2 pack<u16x2_t, u16_t>
#define u16x4 pack<u16x4_t, u16_t>
#define u16x8 pack<u16x8_t, u16_t>
#define u32x2 pack<u32x2_t, u32_t>
#define u32x4 pack<u32x4_t, u32_t>
#define u64x2 pack<u64x2_t, u64_t>

#define s8x4  pack<s8x4_t,  s8_t>
#define s8x8  pack<s8x8_t,  s8_t>
#define s8x16 pack<s8x16_t, s8_t>
#define s16x2 pack<s16x2_t, s16_t>
#define s16x4 pack<s16x4_t, s16_t>
#define s16x8 pack<s16x8_t, s16_t>
#define s32x2 pack<s32x2_t, s32_t>
#define s32x4 pack<s32x4_t, s32_t>
#define s64x2 pack<s64x2_t, s64_t>

//#define f16x2 pack<f16x2_t, f16_t>
//#define f16x4 pack<f16x4_t, f16_t>
//#define f16x8 pack<f16x8_t, f16_t>
#define f32x2 pack<f32x2_t, f32_t>
#define f32x4 pack<f32x4_t, f32_t>
#define f64x2 pack<f64x2_t, f64_t>


#define fill_u8x4  fillBits<u8x4_t,  u8_t>
#define fill_u8x8  fillBits<u8x8_t,  u8_t>
#define fill_u8x16 fillBits<u8x16_t, u8_t>
#define fill_u16x2 fillBits<u16x2_t, u16_t>
#define fill_u16x4 fillBits<u16x4_t, u16_t>
#define fill_u16x8 fillBits<u16x8_t, u16_t>
#define fill_u32x2 fillBits<u32x2_t, u32_t>
#define fill_u32x4 fillBits<u32x4_t, u32_t>
#define fill_u64x2 fillBits<u64x2_t, u64_t>

#define fill_s8x4  fillBits<s8x4_t,  s8_t>
#define fill_s8x8  fillBits<s8x8_t,  s8_t>
#define fill_s8x16 fillBits<s8x16_t, s8_t>
#define fill_s16x2 fillBits<s16x2_t, s16_t>
#define fill_s16x4 fillBits<s16x4_t, s16_t>
#define fill_s16x8 fillBits<s16x8_t, s16_t>
#define fill_s32x2 fillBits<s32x2_t, s32_t>
#define fill_s32x4 fillBits<s32x4_t, s32_t>
#define fill_s64x2 fillBits<s64x2_t, s64_t>

//#define fill_f16x2 fillBits<f16x2_t, f16_t>
//#define fill_f16x4 fillBits<f16x4_t, f16_t>
//#define fill_f16x8 fillBits<f16x8_t, f16_t>
#define fill_f32x2 fillBits<f32x2_t, f32_t>
#define fill_f32x4 fillBits<f32x4_t, f32_t>
#define fill_f64x2 fillBits<f64x2_t, f64_t>

//=============================================================================
//=============================================================================
//=============================================================================
// Container for test values (used by LUA backend)

class ValVector;

class Val
{
    //==========================================================================
private:
    union 
    {                       
        b128_t     num;    // Values for scalar operands. Unused bits must be zero!
        ValVector* vector; // values for vector operands
    };

    uint16_t type;          // set to BRIG_TYPE_NONE for empty values and for vector operands

    //==========================================================================
private:
    void setProps(unsigned t) 
    {
        type = static_cast<uint16_t>(t);
        assert(t == type);
    }

private:
    void assign(u8_t  val) { setProps(Brig::BRIG_TYPE_U8);   num.set(val); }
    void assign(u16_t val) { setProps(Brig::BRIG_TYPE_U16);  num.set(val); }
    void assign(u32_t val) { setProps(Brig::BRIG_TYPE_U32);  num.set(val); }
    void assign(u64_t val) { setProps(Brig::BRIG_TYPE_U64);  num.set(val); }

    void assign(s8_t  val) { setProps(Brig::BRIG_TYPE_S8);   num.set(val); }
    void assign(s16_t val) { setProps(Brig::BRIG_TYPE_S16);  num.set(val); }
    void assign(s32_t val) { setProps(Brig::BRIG_TYPE_S32);  num.set(val); }
    void assign(s64_t val) { setProps(Brig::BRIG_TYPE_S64);  num.set(val); }

    void assign(f32_t val) { setProps(Brig::BRIG_TYPE_F32);  num.set(val); }
    void assign(f64_t val) { setProps(Brig::BRIG_TYPE_F64);  num.set(val); }

    void assign(b1_t   val){ setProps(Brig::BRIG_TYPE_B1);   num.set<b1_t>(val & 0x1); }
    void assign(b128_t val){ setProps(Brig::BRIG_TYPE_B128); num = val; }

    template<typename T> void assign(T val){ assign(val.get()); setProps(T::typeId); }

private:
    u8_t   get_u8()   const { assert(getType() == Brig::BRIG_TYPE_U8);   return num.get<u8_t>();  }
    u16_t  get_u16()  const { assert(getType() == Brig::BRIG_TYPE_U16);  return num.get<u16_t>(); }
    u32_t  get_u32()  const { assert(getType() == Brig::BRIG_TYPE_U32);  return num.get<u32_t>(); }
    u64_t  get_u64()  const { assert(getType() == Brig::BRIG_TYPE_U64);  return num.get<u64_t>(); }

    s8_t   get_s8()   const { assert(getType() == Brig::BRIG_TYPE_S8);   return num.get<s8_t>();  }
    s16_t  get_s16()  const { assert(getType() == Brig::BRIG_TYPE_S16);  return num.get<s16_t>(); }
    s32_t  get_s32()  const { assert(getType() == Brig::BRIG_TYPE_S32);  return num.get<s32_t>(); }
    s64_t  get_s64()  const { assert(getType() == Brig::BRIG_TYPE_S64);  return num.get<s64_t>(); }

    f32_t  get_f32()  const { assert(getType() == Brig::BRIG_TYPE_F32);  return num.get<f32_t>(); }
    f64_t  get_f64()  const { assert(getType() == Brig::BRIG_TYPE_F64);  return num.get<f64_t>(); }

    b1_t   get_b1()   const { assert(getType() == Brig::BRIG_TYPE_B1);   return num.get<b1_t>(); }
    b8_t   get_b8()   const { assert(getType() == Brig::BRIG_TYPE_B8);   return num.get<b8_t>(); }
    b16_t  get_b16()  const { assert(getType() == Brig::BRIG_TYPE_B16);  return num.get<b16_t>(); }
    b32_t  get_b32()  const { assert(getType() == Brig::BRIG_TYPE_B32);  return num.get<b32_t>(); }
    b64_t  get_b64()  const { assert(getType() == Brig::BRIG_TYPE_B64);  return num.get<b64_t>(); }
    b128_t get_b128() const { assert(getType() == Brig::BRIG_TYPE_B128); return num; }

    //==========================================================================
private:
    void clean();
    void copy(const Val& val);
    u64_t getMask() const { assert(getType() != BRIG_TYPE_NONE); return (getSize() < 64)? (1ULL << getSize()) - 1 : -1; }

    //==========================================================================
public:
    Val()                       { setProps(BRIG_TYPE_NONE); num.clear(); }
    Val(unsigned t, u64_t val)  { setProps(t); assert(getType() != BRIG_TYPE_NONE); num.init(val & getMask()); }
    Val(unsigned t, b128_t val) { setProps(t); assert(getType() != BRIG_TYPE_NONE); num = val; }
    Val(unsigned dim, Val v0, Val v1, Val v2, Val v3);
    ~Val();

public:
    Val(const Val&);
    template<typename T> Val(T val) { num.clear(); assign(val); }

    Val& operator=(const Val& val);

    //==========================================================================
public:
    u8_t   u8()   const { return get_u8();  }
    u16_t  u16()  const { return get_u16(); }
    u32_t  u32()  const { return get_u32(); }
    u64_t  u64()  const { return get_u64(); }

    s8_t   s8()   const { return get_s8();  }
    s16_t  s16()  const { return get_s16(); }
    s32_t  s32()  const { return get_s32(); }
    s64_t  s64()  const { return get_s64(); }

    f32_t  f32()  const { return get_f32(); }
    f64_t  f64()  const { return get_f64(); }

    b1_t   b1()   const { return get_b1();  }
    b8_t   b8()   const { return get_b8();  }
    b16_t  b16()  const { return get_b16(); }
    b32_t  b32()  const { return get_b32(); }
    b64_t  b64()  const { return get_b64(); }
    b128_t b128() const { return get_b128(); }

public:
    operator u8_t()   const { return get_u8();  }
    operator u16_t()  const { return get_u16(); }
    operator u32_t()  const { return get_u32(); }
    operator u64_t()  const { return get_u64(); }

    operator s8_t()   const { return get_s8();  }
    operator s16_t()  const { return get_s16(); }
    operator s32_t()  const { return get_s32(); }
    operator s64_t()  const { return get_s64(); }

    operator f32_t()  const { return get_f32(); }
    operator f64_t()  const { return get_f64(); }

    operator b128_t() const { return get_b128(); }

    template<typename T> operator T() const { assert(getType() == T::typeId); return num.get<T>(); }

    //==========================================================================
public:
    bool empty()               const { return getType() == BRIG_TYPE_NONE && !vector; }
    bool isVector()            const { return getType() == BRIG_TYPE_NONE && vector; }
    unsigned getDim()          const;
    unsigned getVecType()      const;

    Val operator[](unsigned i) const;

    unsigned getType()         const { return type; }
    unsigned getElementType()  const { assert(isPackedType(type)); return packedType2elementType(type); }
    unsigned getElementSize()  const { assert(isPackedType(type)); return getTypeSize(getElementType()); }
    unsigned getSize()         const { return getTypeSize(getType()); }
    bool     isF64()           const { return isFloat() && getSize() == 64; }
    bool     isF32()           const { return isFloat() && getSize() == 32; }
    bool     isF16()           const { return isFloat() && getSize() == 16; }

public:
    bool isInt()               const { return HSAIL_ASM::isIntType(getType()); }
    bool isSignedInt()         const { return HSAIL_ASM::isSignedType(getType()); }
    bool isUnsignedInt()       const { return HSAIL_ASM::isUnsignedType(getType()); }

    bool isFloat()             const { return HSAIL_ASM::isFloatType(getType()); }
    bool isRegularFloat()      const { return isFloat() && !isInf() && !isNan(); }
    bool isSpecialFloat()      const { return isFloat() && (isInf() || isNan()); }

    bool isPacked()            const { return HSAIL_ASM::isPackedType(getType()); }
    bool isPackedFloat()       const { return HSAIL_ASM::isFloatPackedType(getType()); }

public:
    u64_t getElement(unsigned idx) const;
    void setElement(unsigned idx, u64_t val);
    Val  getPackedElement(unsigned elementIdx, unsigned packing = BRIG_PACK_P, unsigned srcOperandIdx = 0) const;
    void setPackedElement(unsigned elementIdx, Val dst);

    //==========================================================================
private:
    template<class T>
    Val transform(T op) const // apply operation to regular/packed data
    { 
        Val res = *this;
        unsigned dim = getPackedTypeDim(getType());

        if (dim == 0) return op(res);

        for (unsigned i = 0; i < dim; ++i)
        {
            res.setPackedElement(i, op(res.getPackedElement(i)));
        }

        return res;
    }

    //==========================================================================
    // Operations on scalar floating-point values
public:
    bool isPositive() const;
    bool isNegative() const;
    bool isZero() const;
    bool isPositiveZero() const;
    bool isNegativeZero() const;
    bool isInf() const;
    bool isPositiveInf() const; 
    bool isNegativeInf() const; 
    bool isNan() const;
    bool isQuietNan() const;
    bool isSignalingNan() const;
    bool isSubnormal() const;
    bool isPositiveSubnormal() const;
    bool isNegativeSubnormal() const;
    bool isRegularPositive() const;
    bool isRegularNegative() const;
    bool isNatural() const;
    
    u64_t getNormalizedFract(int delta = 0) const;
    Val copySign(Val v) const;

public:
    Val getQuietNan()     const;
    Val getNegativeZero() const;
    Val getPositiveZero() const;
    Val getNegativeInf()  const;
    Val getPositiveInf()  const;

    //==========================================================================
    // Operations on scalar/packed floating-point values
public:
    Val normalize() const;              // Clear NaN payload
    Val ftz() const;                    // Force subnormals to 0

    //==========================================================================
public:
    s32_t getAsS32()                 const { return static_cast<s32_t>(num.getElement(getType())); }    // Get value with zero/sign-extension
    u32_t getAsB32(unsigned idx = 0) const { return num.get<u32_t>(idx); }                              // Get value with zero-extension

    s64_t getAsS64()                 const { return num.getElement(getType()); }                        // Get value with zero/sign extension
    u64_t getAsB64(unsigned idx = 0) const { return num.get<u64_t>(idx); }                              // Get value with zero-extension

    Val randomize() const;

    //==========================================================================
public:
    string dump() const;
    string luaStr(unsigned idx = 0) const;

private:
    string decDump() const;
    string hexDump() const;
    string dumpPacked() const;
    string nan2str() const;

    //==========================================================================
private:
    static unsigned getTypeSize(unsigned t) { return HSAIL_ASM::brigtype_get_length(t); }

};

//=============================================================================
//=============================================================================
//=============================================================================

} // namespace TESTGEN

// ============================================================================

#endif // INCLUDED_HSAIL_TESTGEN_VAL_H
