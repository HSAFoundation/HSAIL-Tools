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

using HSAIL_ASM::Directive;
using HSAIL_ASM::Inst;
using HSAIL_ASM::Operand;

#include <stdint.h>

namespace TESTGEN {

// ============================================================================
// ============================================================================
// ============================================================================
// HSAIL Data Types

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

class b1_t
{
private:
    uint8_t val;

public:
    explicit b1_t() {}
    b1_t(uint8_t v) : val(v) {}
    operator uint8_t() const { return val; }
};

class b8_t
{
private:
    uint8_t val;

public:
    explicit b8_t() {}
    b8_t(uint8_t v) : val(v) {}
    operator uint8_t() const { return val; }
};

class b16_t
{
private:
    uint16_t val;

public:
    explicit b16_t() {}
    b16_t(uint16_t v) : val(v) {}
    operator uint16_t() const { return val; }
};

class b32_t
{
private:
    uint32_t val;

public:
    explicit b32_t() {}
    b32_t(uint32_t v) : val(v) {}
    operator uint32_t() const { return val; }
};

class b64_t
{
private:
    uint64_t val;

public:
    explicit b64_t() {}
    b64_t(uint64_t v) : val(v) {}
    operator uint64_t() const { return val; }
};

// typedef int16_t  f16_t; // Postponed
// typedef int32_t  s8x4;  // Postponed
// ...

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
    {                       // Values for scalar operands
        u8_t  val_u8;
        u16_t val_u16;
        u32_t val_u32;
        u64_t val_u64;

        s8_t  val_s8;
        s16_t val_s16;
        s32_t val_s32;
        s64_t val_s64;

        f32_t val_f32;
        f64_t val_f64;

        ValVector* val_vec; // values for vector operands
    };

    uint16_t type;          // set to BRIG_TYPE_NONE for empty values and for vector operands
    uint16_t signExp;       // controls sign-extension for s8 and s16 (false for cvt results only)

    //==========================================================================
private:
    void setProps(unsigned t, unsigned sgnExt = 1) 
    { 
        type    = static_cast<uint16_t>(t);
        signExp = static_cast<uint16_t>(sgnExt);
    }

private:
    void assign(u8_t  val) { setProps(Brig::BRIG_TYPE_U8);  val_u8 = val; }
    void assign(u16_t val) { setProps(Brig::BRIG_TYPE_U16); val_u16 = val; }
    void assign(u32_t val) { setProps(Brig::BRIG_TYPE_U32); val_u32 = val; }
    void assign(u64_t val) { setProps(Brig::BRIG_TYPE_U64); val_u64 = val; }

    void assign(s8_t  val) { setProps(Brig::BRIG_TYPE_S8);  val_s8 = val; }
    void assign(s16_t val) { setProps(Brig::BRIG_TYPE_S16); val_s16 = val; }
    void assign(s32_t val) { setProps(Brig::BRIG_TYPE_S32); val_s32 = val; }
    void assign(s64_t val) { setProps(Brig::BRIG_TYPE_S64); val_s64 = val; }

    void assign(f32_t val) { setProps(Brig::BRIG_TYPE_F32); val_f32 = val; }
    void assign(f64_t val) { setProps(Brig::BRIG_TYPE_F64); val_f64 = val; }

    void assign(b1_t val)  { setProps(Brig::BRIG_TYPE_B1);  val_u8 = (val & 0x1); }
    void assign(b8_t val)  { setProps(Brig::BRIG_TYPE_B8);  val_u8 = val; }
    void assign(b16_t val) { setProps(Brig::BRIG_TYPE_B16); val_u16 = val; }
    void assign(b32_t val) { setProps(Brig::BRIG_TYPE_B32); val_u32 = val; }
    void assign(b64_t val) { setProps(Brig::BRIG_TYPE_B64); val_u64 = val; }

private:
    u8_t  get_u8()  const { assert(getType() == Brig::BRIG_TYPE_U8);  return val_u8; }
    u16_t get_u16() const { assert(getType() == Brig::BRIG_TYPE_U16); return val_u16; }
    u32_t get_u32() const { assert(getType() == Brig::BRIG_TYPE_U32); return val_u32; }
    u64_t get_u64() const { assert(getType() == Brig::BRIG_TYPE_U64); return val_u64; }

    s8_t  get_s8()  const { assert(getType() == Brig::BRIG_TYPE_S8);  return val_s8; }
    s16_t get_s16() const { assert(getType() == Brig::BRIG_TYPE_S16); return val_s16; }
    s32_t get_s32() const { assert(getType() == Brig::BRIG_TYPE_S32); return val_s32; }
    s64_t get_s64() const { assert(getType() == Brig::BRIG_TYPE_S64); return val_s64; }

    f32_t get_f32() const { assert(getType() == Brig::BRIG_TYPE_F32); return val_f32; }
    f64_t get_f64() const { assert(getType() == Brig::BRIG_TYPE_F64); return val_f64; }

    b1_t  get_b1()  const { assert(getType() == Brig::BRIG_TYPE_B1);  return b1_t(val_u8); }
    b8_t  get_b8()  const { assert(getType() == Brig::BRIG_TYPE_B8);  return b8_t(val_u8); }
    b16_t get_b16() const { assert(getType() == Brig::BRIG_TYPE_B16); return b16_t(val_u16); }
    b32_t get_b32() const { assert(getType() == Brig::BRIG_TYPE_B32); return b32_t(val_u32); }
    b64_t get_b64() const { assert(getType() == Brig::BRIG_TYPE_B64); return b64_t(val_u64); }

    //==========================================================================
private:
    void clean();
    void copy(const Val& val);

    //==========================================================================
public:
    Val()                      : val_vec(0)   { setProps(Brig::BRIG_TYPE_NONE); }
    Val(unsigned t, u64_t val) : val_u64(val) { setProps(t); assert(getType() != Brig::BRIG_TYPE_NONE); }
    Val(unsigned dim, Val v0, Val v1, Val v2, Val v3);
    ~Val();

public:
    Val(const Val&);
    template<typename T> Val(T val) { assign(val); } // For integral types only (see 'assign')
    Val& operator=(const Val& val);

    //==========================================================================
public:
    u8_t  u8()  const { return get_u8();  }
    u16_t u16() const { return get_u16(); }
    u32_t u32() const { return get_u32(); }
    u64_t u64() const { return get_u64(); }

    s8_t  s8()  const { return get_s8();  }
    s16_t s16() const { return get_s16(); }
    s32_t s32() const { return get_s32(); }
    s64_t s64() const { return get_s64(); }

    f32_t f32() const { return get_f32(); }
    f64_t f64() const { return get_f64(); }

    b1_t  b1()  const { return get_b1();  }
    b8_t  b8()  const { return get_b8();  }
    b16_t b16() const { return get_b16(); }
    b32_t b32() const { return get_b32(); }

    b64_t b64() const { return get_b64(); }

public:
    operator u8_t()  const { return get_u8();  }
    operator u16_t() const { return get_u16(); }
    operator u32_t() const { return get_u32(); }
    operator u64_t() const { return get_u64(); }

    operator s8_t()  const { return get_s8();  }
    operator s16_t() const { return get_s16(); }
    operator s32_t() const { return get_s32(); }
    operator s64_t() const { return get_s64(); }

    operator f32_t() const { return get_f32(); }
    operator f64_t() const { return get_f64(); }

    operator b1_t()  const { return get_b1();  }
    operator b8_t()  const { return get_b8();  }
    operator b16_t() const { return get_b16(); }
    operator b32_t() const { return get_b32(); }
    operator b64_t() const { return get_b64(); }

    //==========================================================================
public:
    bool empty()            const { return getType() == Brig::BRIG_TYPE_NONE && !val_vec; }
    bool isVector()         const { return getType() == Brig::BRIG_TYPE_NONE && val_vec; }
    unsigned getDim()       const;
    unsigned getVecType()   const;

    Val operator[](unsigned i) const;

    unsigned getType()      const { return type; }
    unsigned getSize()      const { return getTypeSize(getType()); }
    bool     isX64()        const { return getSize() == 64; }

    bool signExpEnabled()   const { return signExp != 0; }
    void disableSignExp()         { signExp = 0; }

public:
    bool isSignedInt()      const { return HSAIL_ASM::isSignedType(getType()); }
    bool isUnsignedInt()    const { return HSAIL_ASM::isUnsignedType(getType()); }
    bool isFloat()          const { return HSAIL_ASM::isFloatType(getType()); }
    bool isRegularFloat()   const { return isFloat() && !isInf() && !isNan(); }
    bool isSpecialFloat()   const { return isFloat() && (isInf() || isNan()); }

    //==========================================================================

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
    Val normalize() const;
    Val ftz() const;

public:
    Val getQuietNan()     const;
    Val getNegativeZero() const;
    Val getPositiveZero() const;
    Val getNegativeInf()  const;
    Val getPositiveInf()  const;

    //==========================================================================
public:
    u64_t conv2b64(bool expandSignedInt = true, bool convFloat = false) const;
    u32_t conv2b32(bool expandSignedInt = true, bool convFloat = false) const;
    u32_t conv2b32hi(bool expandSignedInt = true, bool convFloat = false) const;

    void randomize();

    //==========================================================================
public:
    string str() const;
    string hexStr() const;
    string dump() const;

private:
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
