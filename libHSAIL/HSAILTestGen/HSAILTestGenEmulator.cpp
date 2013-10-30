//===-- HSAILTestGenEmulator.cpp - HSAIL Instructions Emulator ------------===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#include "HSAILTestGenEmulator.h"
#include "HSAILTestGenUtilities.h"
#include "generated/HSAILBrigUtilities_gen.hpp"

#include <llvm/ADT/APInt.h>
#include <type_traits>
#include <math.h>

using Brig::BRIG_TYPE_B1;
using Brig::BRIG_TYPE_B8;
using Brig::BRIG_TYPE_B32;
using Brig::BRIG_TYPE_B64;
using Brig::BRIG_TYPE_S8;
using Brig::BRIG_TYPE_S16;
using Brig::BRIG_TYPE_S32;
using Brig::BRIG_TYPE_S64;
using Brig::BRIG_TYPE_U8;
using Brig::BRIG_TYPE_U16;
using Brig::BRIG_TYPE_U32;
using Brig::BRIG_TYPE_U64;
using Brig::BRIG_TYPE_F16;
using Brig::BRIG_TYPE_F32;
using Brig::BRIG_TYPE_F64;

using HSAIL_ASM::InstBasic;
using HSAIL_ASM::InstSourceType;
using HSAIL_ASM::InstAtomic;
using HSAIL_ASM::InstAtomicImage;
using HSAIL_ASM::InstBar;
using HSAIL_ASM::InstCmp;
using HSAIL_ASM::InstCvt;
using HSAIL_ASM::InstImage;
using HSAIL_ASM::InstMem;
using HSAIL_ASM::InstMod;
using HSAIL_ASM::InstBr;

using HSAIL_ASM::isBitType;
using HSAIL_ASM::isFloatType;
using HSAIL_ASM::isSignedType;
using HSAIL_ASM::isIntType;
using HSAIL_ASM::getTypeSize;

//=================================================================================================
//=================================================================================================
//=======================      HOW TO ADD NEW INSTRUCTIONS TO EMULATOR      =======================
//=================================================================================================
//=================================================================================================
//
// Take a look at emulator interface defined in HSAILTestGenEmulator.h
// Each of these interface functions should be extended accordingly.
// The following notes describe how to implement emulation code.
//
// 1. Define a functor with appropriate semantics. ALL FUNCTORS MUST TAKE VALUES OF THE SAME TYPE.
//    This rule is enforced to minimize the number of functor selectors (they are described below).
//    If the instruction being emulated has different types of its arguments, some additional code 
//    is required (see discussion of special cases below). The type of returned value MUST match 
//    the type of result expected by instruction. 
//
//    An example:
//
//          struct op_add { 
//              template<typename T> T operator()(T val1, T val2) { return val1 + val2; }
//          };
//
// 2. Choose an appropriate functor selector. Functor selectors convert abstract source values 
//    to specific type and invoke corresponding instantiation of functor. There are many kinds 
//    of selectors which differ in number of arguments and types. 
//    For example:
//
//          emulateUnrOpF       - for f 32/64 unary instructions 
//          emulateBinOpF       - for f 32/64 binary instructions 
//          
//          emulateUnrOpB       - for b 1/32/64 unary instructions 
//          emulateBinOpB       - for b 1/32/64 binary instructions 
//          emulateTrnOpB       - for b 1/32/64 ternary instructions 
//
//    Supported selector types must include all types accepted by instruction being emulated, 
//    BUT MAY BE WIDER. Paths for types not supported by instruction will never be taken.
//    BEFORE WRITING A NEW SELECTOR, TRY USING EXISTING ONES WITH WIDER LIST OF SUPPORTED TYPES. 
//    
//    For example, emulateBinOpBSUF is a suitable selector for instruction "add", though this 
//    instruction does not work with 'b' types.
//
// 3. Invoke functor selector passing it the type of source values together with source values 
//    and the functor. For example:
//
//          static Val emulate_add(unsigned opcode, unsigned type, Val arg1, Val arg2)
//          {
//              return emulateBinOpBSUF(type, arg1, arg2, op_add());
//          }
//
//=================================================================================================
//
// SPECIAL CASES
//
// 1. Functors must take care of special values such as NaN if these values are not handled  
//    by the runtime. For example:
//
//          struct op_max { 
//              template<typename T>
//              T operator()(T val1, T val2) { 
//                  return Val(val1).isNan()? val1 : Val(val2).isNan()? val2 : std::max(val1, val2); 
//              }
//          };
//
// 2. Some instructions have undefined behaviour for special values. 
//    For example, sin(x) has undefined behavior for values out of the range [-TRIG_BND, TRIG_BND].
//    In this case functor should have return type Val and return undefValue when behaviour 
//    is undefined. For example:
//
//          struct op_cos { 
//              template<typename T> 
//              Val operator()(T val) { 
//                  return Val(val).isNan()? 
//                              Val(val) : 
//                              (val < -TRIG_BND || TRIG_BND < val)? undefValue() : Val(cos(val)); 
//              }
//          };
//
// 3. Some instructions have several source arguments with different types. 
//    To emulate these instructions, there are several possibilities:
//
//      a) Convert all arguments to some generic type before passing values to selector.
//
//      b) Implement emulation of this instruction w/o functors and selectors. 
//         Appropriate for very irregular instructions. 
//
//      c) Define a non-standard functor selector. Appropriate for very irregular instructions. 
//
//=================================================================================================

namespace TESTGEN {

//=============================================================================
//=============================================================================
//=============================================================================
// Properties of integer types

struct IntBits
{
    u64_t    allBits;
    unsigned width;
    unsigned shiftMask;
};

static const IntBits intBits32 = 
{
    0x0ffffffffULL, // allBits
    32,             // width
    31              // shiftMask
};

static const IntBits intBits64 = 
{
    0xffffffffffffffffULL,  // allBits
    64,                     // width
    63                      // shiftMask
};

template<typename T> static bool isSigned(T val) { return ((T)-1 < (T)0); }

//=============================================================================
//=============================================================================
//=============================================================================
// Min and max values for integer types (used for saturating rounding)

static const s64_t S8IB  = 0x7f;
static const s64_t S16IB = 0x7fff;
static const s64_t S32IB = 0x7fffffff;
static const s64_t S64IB = 0x7fffffffffffffffLL;
static const u64_t U8IB  = 0xff;
static const u64_t U16IB = 0xffff;
static const u64_t U32IB = 0xffffffff;
static const u64_t U64IB = 0xffffffffffffffffLL;

static u64_t getIntBoundary(unsigned type, bool low)
{
    switch (type)
    {
    case BRIG_TYPE_S8:  return low? -S8IB  - 1 : S8IB;
    case BRIG_TYPE_S16: return low? -S16IB - 1 : S16IB; 
    case BRIG_TYPE_S32: return low? -S32IB - 1 : S32IB; 
    case BRIG_TYPE_S64: return low? -S64IB - 1 : S64IB; 
    case BRIG_TYPE_U8:  return low? 0          : U8IB;  
    case BRIG_TYPE_U16: return low? 0          : U16IB; 
    case BRIG_TYPE_U32: return low? 0          : U32IB; 
    case BRIG_TYPE_U64: return low? 0          : U64IB; 

    default: 
        assert(false); 
        return 0;
    }
}

template<typename T>
static bool checkTypeBoundaries(unsigned type, T val)
{
    switch (type)
    {
    case BRIG_TYPE_S8:   return (-S8IB  - 1 <= val) && (val <= S8IB);  break;
    case BRIG_TYPE_S16:  return (-S16IB - 1 <= val) && (val <= S16IB); break;
    case BRIG_TYPE_S32:  return (-S32IB - 1 <= val) && (val <= S32IB); break;
    case BRIG_TYPE_S64:  return (-S64IB - 1 <= val) && (val <= S64IB); break;
    case BRIG_TYPE_U8:   return (0          <= val) && (val <= U8IB);  break;
    case BRIG_TYPE_U16:  return (0          <= val) && (val <= U16IB); break;
    case BRIG_TYPE_U32:  return (0          <= val) && (val <= U32IB); break;
    case BRIG_TYPE_U64:  return (0          <= val) && (val <= U64IB); break;

    default: 
        assert(false);
        return false;
    }
}

//=============================================================================
//=============================================================================
//=============================================================================

static const f64_t TRIG_BND = (512 * 3.14159265358979323846);   // behavior of sin and cos is unspecified when outside of [-TRIG_BND, TRIG_BND]
static const f64_t LN2      = 0.693147180559945309417;          // ln(2)

//=============================================================================
//=============================================================================
//=============================================================================

static Val emulationFailed()                    // This should not happen
{ 
    assert(false);
    return Val();
}

static Val undefValue()    { return Val(); }    // Value returned for unspecified behaviour
static Val unimplemented() { return Val(); }    // Value returned for unimplemented features
static Val emptyDstValue() { return Val(); }    // Value returned when instruction has no destination register(s)
static Val emptyMemValue() { return Val(); }    // Value returned when instruction does not affect memory

//=============================================================================
//=============================================================================
//=============================================================================
// Functor Selectors for Unary Ops

template<class T>
static Val emulateUnrOpUS(unsigned type, Val arg, T op)
{
    assert(arg.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_U8:  return op(arg.u8());
    case BRIG_TYPE_S8:  return op(arg.s8());
    case BRIG_TYPE_U16: return op(arg.u16());
    case BRIG_TYPE_S16: return op(arg.s16());
    case BRIG_TYPE_U32: return op(arg.u32());
    case BRIG_TYPE_S32: return op(arg.s32());
    case BRIG_TYPE_U64: return op(arg.u64());
    case BRIG_TYPE_S64: return op(arg.s64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateUnrOpSF(unsigned type, Val arg, T op)
{
    assert(arg.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_S32: return op(arg.s32());
    case BRIG_TYPE_S64: return op(arg.s64());
    case BRIG_TYPE_F32: return op(arg.f32());
    case BRIG_TYPE_F64: return op(arg.f64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateUnrOpF(unsigned type, Val arg, T op)
{
    assert(arg.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_F32: return op(arg.f32());
    case BRIG_TYPE_F64: return op(arg.f64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateUnrOpB(unsigned type, Val arg, T op)
{
    assert(arg.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_B1:  return op(arg.b1());
    case BRIG_TYPE_B32: return op(arg.b32());
    case BRIG_TYPE_B64: return op(arg.b64());

    default: return emulationFailed();
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Functor Selectors for Binary Ops

template<class T>
static Val emulateBinOpBSUF(unsigned type, Val arg1, Val arg2, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_B1:  return op(arg1.b1(),  arg2.b1());
    case BRIG_TYPE_B32: return op(arg1.b32(), arg2.b32());
    case BRIG_TYPE_B64: return op(arg1.b64(), arg2.b64());

    case BRIG_TYPE_S32: return op(arg1.s32(), arg2.s32());
    case BRIG_TYPE_S64: return op(arg1.s64(), arg2.s64());

    case BRIG_TYPE_U32: return op(arg1.u32(), arg2.u32());
    case BRIG_TYPE_U64: return op(arg1.u64(), arg2.u64());

    case BRIG_TYPE_F32: return op(arg1.f32(), arg2.f32());
    case BRIG_TYPE_F64: return op(arg1.f64(), arg2.f64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateBinOpF(unsigned type, Val arg1, Val arg2, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_F32: return op(arg1.f32(), arg2.f32());
    case BRIG_TYPE_F64: return op(arg1.f64(), arg2.f64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateBinOpB(unsigned type, Val arg1, Val arg2, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_B1:  return op(arg1.b1(),  arg2.b1());
    case BRIG_TYPE_B32: return op(arg1.b32(), arg2.b32());
    case BRIG_TYPE_B64: return op(arg1.b64(), arg2.b64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateBinOpSU(unsigned type, Val arg1, Val arg2, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_S32: return op(arg1.s32(), arg2.s32());
    case BRIG_TYPE_U32: return op(arg1.u32(), arg2.u32());

    case BRIG_TYPE_S64: return op(arg1.s64(), arg2.s64());
    case BRIG_TYPE_U64: return op(arg1.u64(), arg2.u64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateBinOpSU_U32(unsigned type, Val arg1, Val arg2, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == BRIG_TYPE_U32);

    switch (type)
    {
    case BRIG_TYPE_S32: return op(arg1.s32(), arg2.u32());
    case BRIG_TYPE_U32: return op(arg1.u32(), arg2.u32());

    case BRIG_TYPE_S64: return op(arg1.s64(), arg2.u32());
    case BRIG_TYPE_U64: return op(arg1.u64(), arg2.u32());

    default: return emulationFailed();
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Functor Selectors for Ternary Ops

template<class T>
static Val emulateTrnOpSUF(unsigned type, Val arg1, Val arg2, Val arg3, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == type);
    assert(arg3.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_S32: return op(arg1.s32(), arg2.s32(), arg3.s32());
    case BRIG_TYPE_S64: return op(arg1.s64(), arg2.s64(), arg3.s64());

    case BRIG_TYPE_U32: return op(arg1.u32(), arg2.u32(), arg3.u32());
    case BRIG_TYPE_U64: return op(arg1.u64(), arg2.u64(), arg3.u64());

    case BRIG_TYPE_F32: return op(arg1.f32(), arg2.f32(), arg3.f32());
    case BRIG_TYPE_F64: return op(arg1.f64(), arg2.f64(), arg3.f64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateTrnOpSU(unsigned type, Val arg1, Val arg2, Val arg3, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == type);
    assert(arg3.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_S32: return op(arg1.s32(), arg2.s32(), arg3.s32());
    case BRIG_TYPE_S64: return op(arg1.s64(), arg2.s64(), arg3.s64());

    case BRIG_TYPE_U32: return op(arg1.u32(), arg2.u32(), arg3.u32());
    case BRIG_TYPE_U64: return op(arg1.u64(), arg2.u64(), arg3.u64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateTrnOpB(unsigned type, Val arg1, Val arg2, Val arg3, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == type);
    assert(arg3.getType() == type);

    switch (type)
    {
    case BRIG_TYPE_B1:  return op(arg1.b1(),  arg2.b1(),  arg3.b1());
    case BRIG_TYPE_B32: return op(arg1.b32(), arg2.b32(), arg3.b32());
    case BRIG_TYPE_B64: return op(arg1.b64(), arg2.b64(), arg3.b64());

    default: return emulationFailed();
    }
}

template<class T>
static Val emulateTrnOpSU_U32_U32(unsigned type, Val arg1, Val arg2, Val arg3, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == BRIG_TYPE_U32);
    assert(arg3.getType() == BRIG_TYPE_U32);

    switch (type)
    {
    case BRIG_TYPE_S32: return op(arg1.s32(), arg2.u32(), arg3.u32());
    case BRIG_TYPE_S64: return op(arg1.s64(), arg2.u32(), arg3.u32());

    case BRIG_TYPE_U32: return op(arg1.u32(), arg2.u32(), arg3.u32());
    case BRIG_TYPE_U64: return op(arg1.u64(), arg2.u32(), arg3.u32());

    default: return emulationFailed();
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Functor Selectors for Quaternary Ops

template<class T>
static Val emulateQrnOpSU_U32_U32(unsigned type, Val arg1, Val arg2, Val arg3, Val arg4, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == type);
    assert(arg3.getType() == BRIG_TYPE_U32);
    assert(arg4.getType() == BRIG_TYPE_U32);

    switch (type)
    {
    case BRIG_TYPE_S32: return op(arg1.s32(), arg2.s32(), arg3.u32(), arg4.u32());
    case BRIG_TYPE_S64: return op(arg1.s64(), arg2.s64(), arg3.u32(), arg4.u32());

    case BRIG_TYPE_U32: return op(arg1.u32(), arg2.u32(), arg3.u32(), arg4.u32());
    case BRIG_TYPE_U64: return op(arg1.u64(), arg2.u64(), arg3.u32(), arg4.u32());

    default: return emulationFailed();
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Functors Emulating HSAIL Instructions

struct op_abs    { template<typename T> T operator()(T val)                  { return abs(val); }};
struct op_neg    { template<typename T> T operator()(T val)                  { return -val; }};
                 
struct op_not    { template<typename T> T operator()(T val)                  { return static_cast<T>(val ^ 0xffffffffffffffffULL); }};
                 
struct op_add    { template<typename T> T operator()(T val1, T val2)         { return val1 + val2; }};
struct op_sub    { template<typename T> T operator()(T val1, T val2)         { return val1 - val2; }};
struct op_mul    { template<typename T> T operator()(T val1, T val2)         { return val1 * val2; }};
struct op_div    { template<typename T> T operator()(T val1, T val2)         { return val1 / val2; }};
struct op_rem    { template<typename T> T operator()(T val1, T val2)         { return val1 % val2; }};
struct op_max    { template<typename T> T operator()(T val1, T val2)         { return Val(val1).isNan()? val2 : Val(val2).isNan()? val1 : std::max(val1, val2); }};
struct op_min    { template<typename T> T operator()(T val1, T val2)         { return Val(val1).isNan()? val2 : Val(val2).isNan()? val1 : std::min(val1, val2); }};
struct op_arg1   { template<typename T> T operator()(T val1, T val2)         { return val1; }};
struct op_arg2   { template<typename T> T operator()(T val1, T val2)         { return val2; }};

struct op_and    { template<typename T> T operator()(T val1, T val2)         { return val1 & val2; }};
struct op_or     { template<typename T> T operator()(T val1, T val2)         { return val1 | val2; }};
struct op_xor    { template<typename T> T operator()(T val1, T val2)         { return val1 ^ val2; }};
                 
struct op_inc    { template<typename T> T operator()(T mem, T max)           { return (mem >= max)? 0 : mem + 1; }};
struct op_dec    { template<typename T> T operator()(T mem, T max)           { return (mem == 0 || mem > max)? max : mem - 1; }};
                 
struct op_cas    { template<typename T> T operator()(T mem, T val1, T val2)  { return (mem == val1)? val2 : mem; }};
                 
struct op_cmov   { template<typename T> T operator()(T val1, T val2, T val3) { return val1? val2 : val3; }};
                 
struct op_cmp    { template<typename T> int operator()(T val1, T val2)       { return val1 < val2 ? -1 : val1 > val2 ? 1 : 0; }}; // NB: NaNs are handled separately

struct op_copysign { template<typename T> T operator()(T val1, T val2)       { return Val(val1).copySign(Val(val2)); }};
                                                                            
struct op_carry  { template<typename T> T operator()(T val1, T val2)         { assert(!isSigned(val1)); T res = val1 + val2; return res < val1; }};
struct op_borrow { template<typename T> T operator()(T val1, T val2)         { assert(!isSigned(val1)); return val1 < val2; }};

struct op_shl    { template<typename T> T   operator()(T val, unsigned shift){ return val << (shift & (sizeof(T) == 4? intBits32.shiftMask : intBits64.shiftMask)); }};
struct op_shr    { template<typename T> T   operator()(T val, unsigned shift){ return val >> (shift & (sizeof(T) == 4? intBits32.shiftMask : intBits64.shiftMask)); }};

struct op_mad    { template<typename T> T operator()(T val1, T val2, T val3) { return val1 * val2 + val3; }};

struct op_cos    { template<typename T> Val operator()(T val)                { return Val(val).isNan()? Val(val) : (val < -TRIG_BND || TRIG_BND < val)? undefValue() : Val(cos(val)); }};
struct op_sin    { template<typename T> Val operator()(T val)                { return Val(val).isNan()? Val(val) : (val < -TRIG_BND || TRIG_BND < val)? undefValue() : Val(sin(val)); }};
struct op_sqrt   { template<typename T> T   operator()(T val)                { return sqrt(val); }};
struct op_log2   { template<typename T> T   operator()(T val)                { return log(val) / static_cast<T>(LN2); }};
struct op_exp2   { template<typename T> T   operator()(T val)                { return exp(val * static_cast<T>(LN2)); }};
struct op_rsqrt  { template<typename T> T   operator()(T val)                { return static_cast<T>(1.0) / sqrt(val); }};
struct op_rcp    { template<typename T> T   operator()(T val)                { return static_cast<T>(1.0) / val; }};

struct op_i2f32  { template<typename T> f32_t operator()(T val)              { return 0.0f + val; }};
struct op_i2f64  { template<typename T> f64_t operator()(T val)              { return 0.0  + val; }};

//=============================================================================
//=============================================================================
//=============================================================================

struct op_bitmask 
{ 
    unsigned dstType;
    
    op_bitmask(unsigned type) : dstType(type) {}

    template<typename T> 
    Val operator()(T val1, T val2) 
    { 
        IntBits intBits = (getTypeSize(dstType) == 32)? intBits32 : intBits64;
        u64_t offset    = val1 & intBits.shiftMask;
        u64_t width     = val2 & intBits.shiftMask;
        u64_t mask      = (1ULL << width) - 1;

        if (offset + width > intBits.width) return undefValue();
        
        return Val(dstType, mask << offset);
    }
};
                 
struct op_bitsel { template<typename T> T operator()(T val1, T val2, T val3) { return (val2 & val1) | (val3 & (~val1)); }};
                 
struct op_bitextract
{ 
    template<typename T> 
    Val operator()(T val1, unsigned val2, unsigned val3) 
    { 
        IntBits intBits = (sizeof(T) == 4)? intBits32 : intBits64;
        u64_t offset    = val2 & intBits.shiftMask;
        u64_t width     = val3 & intBits.shiftMask;
        
        if (width == 0) return Val(static_cast<T>(0));
        if (width + offset > intBits.width) return undefValue();

        u64_t shift = intBits.width - width;
        return Val(static_cast<T>((val1 << (shift - offset)) >> shift));
    }
};

struct op_bitinsert
{ 
    template<typename T> 
    Val operator()(T val1, T val2, unsigned val3, unsigned val4) 
    { 
        IntBits intBits = (sizeof(T) == 4)? intBits32 : intBits64;
        u64_t offset    = val3 & intBits.shiftMask;
        u64_t width     = val4 & intBits.shiftMask;
        u64_t mask      = (1ULL << width) - 1;
        
        if (width + offset > intBits.width) return undefValue();

        u64_t res = (val1 & ~(mask << offset)) | ((val2 & mask) << offset);
        return Val(static_cast<T>(res));
    }
};

struct op_bitrev
{ 
    template<typename T> 
    T operator()(T val) 
    { 
        T res = 0;
        for (unsigned i = 0; i < sizeof(T) * 8; i++, val = val >> 1) res = (res << 1) | (val & 0x1);
        return res;
    }
};

struct op_bitalign
{ 
    unsigned shift_mask;
    unsigned element_width;

    op_bitalign(unsigned mask, unsigned width = 1) : shift_mask(mask), element_width(width) {}

    template<typename T> 
    T operator()(T val0, T val1, T val2) 
    { 
        assert(sizeof(T) == 4);

        uint32_t shift = (val2 & shift_mask) * element_width;
        uint64_t value = (static_cast<uint64_t>(val1) << 32) | val0;
        
        return static_cast<uint32_t>((value >> shift) & 0xffffffff);
    }
};

//=============================================================================
//=============================================================================
//=============================================================================

template<typename T> static bool isSU24(T val) 
{ 
    if (isSigned(val)) {
        return -0x400000 <= (signed) val && (signed) val <= 0x3FFFFF; 
    } else {
        return val <= 0x7FFFFF;
    }
}

struct op_mad24  
{ 
    unsigned res_shift;

    op_mad24(unsigned shift) : res_shift(shift) {}

    template<typename T> 
    Val operator()(T val1, T val2, T val3)
    { 
        assert(sizeof(T) == 4);

        if (isSU24(val1) && isSU24(val2) && isSU24(val3)) 
        {
            if (isSigned(val1)) {
                return static_cast<T>(((static_cast<s64_t>(val1) * val2) >> res_shift) + val3);
            } else {
                return static_cast<T>(((static_cast<u64_t>(val1) * val2) >> res_shift) + val3);
            }
        } 
        else 
        {
            return undefValue();
        }
    }
};

struct op_mulhi
{ 
    template<typename T> 
    T operator()(T val1, T val2)         
    {
        using namespace llvm; 
        using namespace APIntOps;

        bool sgn = ((T)-1 < (T)0);
        unsigned bits = sizeof(T) * 8;
        APInt a1(bits * 2, sgn ? (uint64_t)(int64_t)val1 : (uint64_t)val1, sgn);
        APInt a2(bits * 2, sgn ? (uint64_t)(int64_t)val2 : (uint64_t)val2, sgn);
        APInt prod =  a1 * a2;
        return *(const T*)prod.lshr(bits).getRawData(); // truncate as needed
    }
};

//=============================================================================
//=============================================================================
//=============================================================================

struct op_fract  
{ 
    template<typename T> 
    Val operator()(T val)
    { 
        if (Val(val).isNan()) return Val(val); // preserve NaN payload
        if (Val(val).isInf()) return Val(val).getQuietNan();

        T unused; 
        T one = 1;
        T res = modf(val, &unused);

        if (val > 0) return Val(res); 
        if (val < 0 && (one + res) < one) return Val(one + res); 
        return Val((T)0);
    }
};

struct op_ceil  
{ 
    template<typename T> 
    Val operator()(T val)
    { 
        if (Val(val).isNan() || Val(val).isInf()) return Val(val);

        T res; 
        T fract = modf(val, &res);

        if (fract != 0 && val >= 0) return Val(res + 1);
        return Val(res);
    }
};

struct op_floor  
{ 
    template<typename T> 
    Val operator()(T val)
    { 
        if (Val(val).isNan() || Val(val).isInf()) return Val(val);

        T res; 
        T fract = modf(val, &res);

        if (fract != 0 && val < 0) return Val(res - 1);
        return Val(res);
    }
};

struct op_trunc
{ 
    template<typename T> 
    Val operator()(T val)
    { 
        if (Val(val).isNan() || Val(val).isInf()) return Val(val);

        T res; 
        modf(val, &res);
        return Val(res);
    }
};

struct op_rint
{ 
    template<typename T> 
    Val operator()(T val)
    { 
        if (Val(val).isNan() || Val(val).isInf()) return Val(val);

        T res; 
        T fract = abs(modf(val, &res));
        bool isEven = (static_cast<uint64_t>(res) & 1) == 0;

        if (fract < 0.5 || (fract == 0.5 && isEven)) fract = 0;
        else fract = static_cast<T>((val < 0)? -1 : 1);

        return Val(res + fract);
    }
};

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of 'class' Instruction

static Val emulate_class(unsigned stype, Val arg1, Val arg2)
{
    assert(arg1.isFloat());
    assert(arg1.getType() == stype);
    assert(arg2.getType() == BRIG_TYPE_U32);

    u32_t res = 0;
    u32_t flags = arg2.u32();

    if (arg1.isSpecialFloat())
    {
        if ((flags & 0x001) && arg1.isSignalingNan())      res = 1;
        if ((flags & 0x002) && arg1.isQuietNan())          res = 1;
        if ((flags & 0x004) && arg1.isNegativeInf())       res = 1;
        if ((flags & 0x200) && arg1.isPositiveInf())       res = 1;
    }
    else if (arg1.isSubnormal())
    {
        if ((flags & 0x010) && arg1.isNegativeSubnormal()) res = 1;
        if ((flags & 0x080) && arg1.isPositiveSubnormal()) res = 1;
    }
    else if (arg1.isZero())
    {
        if ((flags & 0x020) &&  arg1.isNegativeZero())     res = 1;
        if ((flags & 0x040) &&  arg1.isPositiveZero())     res = 1;
    }
    else
    {
        if ((flags & 0x100) &&  arg1.isPositive())         res = 1;
        if ((flags & 0x008) && !arg1.isPositive())         res = 1;
    }

    return Val(BRIG_TYPE_B1, res);
}

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of Bit String operations

static Val emulate_popcount(unsigned stype, Val arg)
{
    assert(arg.getType() == stype);
    assert(isBitType(stype));

    u32_t count = 0;
    for (u64_t val = arg.conv2b64(); val > 0; val >>= 1)
    {
        if ((val & 0x1) != 0) count++;
    }
    return Val(count);
}

static Val emulate_firstbit(unsigned stype, Val arg)
{
    assert(arg.getType() == stype);

    u64_t firstBit = 0x1ULL << (arg.getSize() - 1);
    s64_t val = static_cast<s64_t>(arg.conv2b64());

    if (arg.isSignedInt() && val < 0) val = ~val;
    if (val == 0) return Val(BRIG_TYPE_U32, -1);
    
    u32_t res = 0;
    for (; (val & firstBit) == 0; ++res, val <<= 1);
    return Val(res);
}

static Val emulate_lastbit(unsigned stype, Val arg)
{
    assert(arg.getType() == stype);

    u64_t val = arg.conv2b64(false); // Disable sign-expansion

    if (val == 0) return Val(BRIG_TYPE_U32, -1);
    
    u32_t res = 0;
    for (; (val & 0x1) == 0; ++res, val >>= 1);
    return Val(res);
}

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of combine/expand Instruction

static Val emulate_combine(unsigned type, unsigned stype, Val arg)
{
    assert(arg.isVector());
    assert(arg.getVecType() == stype);

    if (type == BRIG_TYPE_B64) 
    {
        assert(arg.getDim() == 2);
        assert(stype == BRIG_TYPE_B32);

        return Val(type, (arg[1].conv2b64() << 32) | arg[0].b32());
    } 
    else 
    {
        return unimplemented(); // required b128 support
    }
}

static Val emulate_expand(unsigned type, unsigned stype, Val arg)
{
    assert(!arg.isVector());
    assert(arg.getType() == stype);

    if (stype == BRIG_TYPE_B64) 
    {
        assert(type == BRIG_TYPE_B32);

        return Val(2, Val(type, arg.conv2b32()), Val(type, arg.conv2b32hi()), Val(), Val());
    } 
    else 
    {
        return unimplemented(); // required b128 support
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of cmp Instruction

static Val emulateCmp(unsigned type, unsigned stype, AluMod aluMod, unsigned op, Val arg1, Val arg2)
{
    using namespace Brig;

    assert(arg1.getType() == stype);
    assert(arg2.getType() == stype);

    if (type == BRIG_TYPE_F16) return unimplemented();

    bool isNan = arg1.isNan() || arg2.isNan();
    int cmp = emulateBinOpBSUF(stype, arg1, arg2, op_cmp());

    bool res;
    switch (op)
    {
    case BRIG_COMPARE_EQ:     res = (cmp == 0) && !isNan;     break;
    case BRIG_COMPARE_EQU:    res = (cmp == 0) || isNan;      break;

    case BRIG_COMPARE_NE:     res = (cmp != 0) && !isNan;     break;
    case BRIG_COMPARE_NEU:    res = (cmp != 0) || isNan;      break;

    case BRIG_COMPARE_LT:     res = (cmp == -1) && !isNan;    break;
    case BRIG_COMPARE_LTU:    res = (cmp == -1) || isNan;     break;

    case BRIG_COMPARE_LE:     res = (cmp != 1) && !isNan;     break;
    case BRIG_COMPARE_LEU:    res = (cmp != 1) || isNan;      break;

    case BRIG_COMPARE_GT:     res = (cmp == 1) && !isNan;     break;
    case BRIG_COMPARE_GTU:    res = (cmp == 1) || isNan;      break;

    case BRIG_COMPARE_GE:     res = (cmp != -1) && !isNan;    break;
    case BRIG_COMPARE_GEU:    res = (cmp != -1) || isNan;     break;

    case BRIG_COMPARE_NUM:    res = !isNan;                   break;
    case BRIG_COMPARE_NAN:    res = isNan;                    break;

    default: return unimplemented();
    }

    switch (type)
    {
    case BRIG_TYPE_B1:  return Val(type, res? 1 : 0);

    case BRIG_TYPE_S32:
    case BRIG_TYPE_S64:
    case BRIG_TYPE_U32:
    case BRIG_TYPE_U64: return Val(type, res? -1 : 0);

    case BRIG_TYPE_F32: return Val(res? 1.0f : 0.0f);
    case BRIG_TYPE_F64: return Val(res? 1.0  : 0.0 );

    default: return emulationFailed();
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of cvt Instruction

// Compute delta d for rounding of val so that (val+d) 
// will be rounded to proper value when converted to integer
static int f2i_round(Val val, unsigned rounding)
{
    assert(val.isFloat());
    assert(!val.isNan());

    int round = 0;

    switch (rounding)
    {
    case AluMod::ROUNDING_NEARI:
    case AluMod::ROUNDING_NEARI_SAT:
        if (val.getNormalizedFract() > Val(0.5f).getNormalizedFract())          // Rounds to the nearest representable value
        {
            round = val.isNegative() ? -1 : 1;
        }
        else if (val.getNormalizedFract()  == Val(0.5f).getNormalizedFract() &&  // If there is a tie, round to an even least significant digit
                 val.getNormalizedFract(-1) > Val(0.5f).getNormalizedFract())
        {
            round = val.isNegative() ? -1 : 1;
        }
        break;
    case AluMod::ROUNDING_ZEROI:
    case AluMod::ROUNDING_ZEROI_SAT:
        break;
    case AluMod::ROUNDING_UPI:
    case AluMod::ROUNDING_UPI_SAT:
        if (val.isRegularPositive() && !val.isNatural()) round = 1;
        break;
    case AluMod::ROUNDING_DOWNI:
    case AluMod::ROUNDING_DOWNI_SAT:
        if (val.isRegularNegative() && !val.isNatural()) round = -1;
        break;

    default: return emulationFailed();
    }

    return round;
}

static Val f2i_saturate(unsigned type, bool lowBound)
{
    return Val(type, getIntBoundary(type, lowBound));
}

template<typename T>
static Val f2i_convert(unsigned type, T v, bool isSatRounding)
{
    if (!checkTypeBoundaries(type, v)) return isSatRounding ? f2i_saturate(type, v <= 0) : undefValue();

    assert(isIntType(type));
    return isSignedType(type)? Val(type, static_cast<s64_t>(v)) : Val(type, static_cast<u64_t>(v));
}

template<typename T>
static Val cvt_f2i(unsigned type, AluMod aluMod, Val val)
{
    assert(isIntType(type));

    if (val.isNan()) return aluMod.isSat()? Val(type, 0) : undefValue();

    int round = f2i_round(val, aluMod.getRounding());
    return f2i_convert(type, static_cast<T>(val) + round, aluMod.isSat());
}

static Val cvt_f2x(unsigned type, unsigned stype, AluMod aluMod, Val arg)
{
    assert(isFloatType(stype));

    if (isFloatType(type))
    {
        if (type == BRIG_TYPE_F64 && stype == BRIG_TYPE_F32)
        {
            return static_cast<f64_t>(arg.f32());
        }
        else if (type == BRIG_TYPE_F32 && stype == BRIG_TYPE_F64) 
        {
            if (aluMod.getRounding() == AluMod::ROUNDING_NEAR)  // This is the default MS C++ rounding mode
            {
                return static_cast<f32_t>(arg.f64());
            }
            else
            {
                return unimplemented(); // FIXME: fp rounding is not implemented yet
            }
        }
        
        return unimplemented(); // f16 is not supported yet
    }
    else
    {
        assert(isIntType(type));

        if (stype == BRIG_TYPE_F32) return cvt_f2i<f32_t>(type, aluMod, arg);
        if (stype == BRIG_TYPE_F64) return cvt_f2i<f64_t>(type, aluMod, arg);
        
        return unimplemented();  // f16 is not supported yet
    }
}

static Val cvt_i2f(unsigned type, Val val, AluMod aluMod)
{
    assert(isFloatType(type));

    if (aluMod.getRounding() == AluMod::ROUNDING_NEAR) // This is the default MS C++ rounding mode
    {
        if (type == BRIG_TYPE_F32) return emulateUnrOpUS(val.getType(), val, op_i2f32());
        if (type == BRIG_TYPE_F64) return emulateUnrOpUS(val.getType(), val, op_i2f64());
        return unimplemented(); // f16 is not supported yet
    }
    return unimplemented(); // other fp rounding modes are not supported yet
}

static Val cvt_i2i(unsigned type, u64_t s)
{
    switch (type)
    {
    case BRIG_TYPE_U8:  s = s < 0 ? 0 : s & 0xffULL;           break;
    case BRIG_TYPE_U16: s = s < 0 ? 0 : s & 0xffffULL;         break;
    case BRIG_TYPE_U32: s = s < 0 ? 0 : s & intBits32.allBits; break;
    case BRIG_TYPE_U64: s = s < 0 ? 0 : s;                     break;

    case BRIG_TYPE_S8:  s = s & 0xffULL;           break;
    case BRIG_TYPE_S16: s = s & 0xffffULL;         break;
    case BRIG_TYPE_S32: s = s & intBits32.allBits; break;
    case BRIG_TYPE_S64: break;

    default: return emulationFailed();
    }

    return Val(type, s);
}

static Val cvt_i2x(unsigned type, unsigned stype, AluMod aluMod, Val arg)
{
    assert(isIntType(stype));

    return isIntType(type)? 
            cvt_i2i(type, arg.conv2b64()) : 
            cvt_i2f(type, arg, aluMod);
}

static Val cvt_x2b1(unsigned type, unsigned stype, AluMod aluMod, Val arg)
{
    return isIntType(stype)? 
            Val(type, arg.conv2b64() != 0) : 
            Val(type, !arg.isZero());
}

static Val emulateCvt(unsigned type, unsigned stype, AluMod aluMod, Val arg)
{
    assert(arg.getType() == stype);
    
    if (type == BRIG_TYPE_F16) return unimplemented();

    if (stype == BRIG_TYPE_B1) // to avoid handling this type in other places
    {
        stype = BRIG_TYPE_U32;
        arg = Val(stype, arg.conv2b64());
    }

    if (type == stype)         return arg;
    if (type == BRIG_TYPE_B1)  return cvt_x2b1(type, stype, aluMod, arg);
    else                       return isFloatType(stype)? 
                                      cvt_f2x(type, stype, aluMod, arg) :
                                      cvt_i2x(type, stype, aluMod, arg);
}

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of atomic Instruction

static Val emulateAtomicMem(unsigned type, unsigned atomicOperation, Val arg1, Val arg2, Val arg3)
{
    using namespace Brig;

    assert(arg1.getType() == type);
    assert(BRIG_ATOMIC_ST || arg2.getType() == type);

    switch (atomicOperation)
    {
    case BRIG_ATOMIC_AND:  return emulateBinOpB(type, arg1, arg2, op_and());
    case BRIG_ATOMIC_OR:   return emulateBinOpB(type, arg1, arg2, op_or()); 
    case BRIG_ATOMIC_XOR:  return emulateBinOpB(type, arg1, arg2, op_xor());

    case BRIG_ATOMIC_ADD:  return emulateBinOpSU(type, arg1, arg2, op_add());
    case BRIG_ATOMIC_SUB:  return emulateBinOpSU(type, arg1, arg2, op_sub());
    case BRIG_ATOMIC_MAX:  return emulateBinOpSU(type, arg1, arg2, op_max());
    case BRIG_ATOMIC_MIN:  return emulateBinOpSU(type, arg1, arg2, op_min());

    case BRIG_ATOMIC_INC:  return emulateBinOpSU(type, arg1, arg2, op_inc()); 
    case BRIG_ATOMIC_DEC:  return emulateBinOpSU(type, arg1, arg2, op_dec()); 
    case BRIG_ATOMIC_EXCH: return emulateBinOpB(type, arg1, arg2, op_arg2());
    case BRIG_ATOMIC_CAS:  return emulateTrnOpB(type, arg1, arg2, arg3, op_cas());

    case BRIG_ATOMIC_LD:   assert(arg1.getType() == type); return arg1;
    case BRIG_ATOMIC_ST:   assert(arg2.getType() == type); return arg2;

    default: return emulationFailed();
    }
}

static Val emulateAtomicDst(unsigned opcode, Val arg1)
{
    return (opcode == Brig::BRIG_OPCODE_ATOMIC)? arg1 : emptyDstValue();
}

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of carry/borrow

template<class T>
static Val emulateAluFlag(unsigned type, Val arg1, Val arg2, T op)
{
    assert(arg1.getType() == type);
    assert(arg2.getType() == type);

    unsigned utype = type;

    if (isSignedType(type)) // Convert args to unsigned (to simplify functor implementation)
    {
        utype = (getTypeSize(type) == 32)? BRIG_TYPE_U32 : BRIG_TYPE_U64;

        arg1 = Val(utype, arg1.conv2b64(false)); // copy bits w/o sign-extension
        arg2 = Val(utype, arg2.conv2b64(false)); // copy bits w/o sign-extension
    }

    Val res = emulateBinOpSU(utype, arg1, arg2, op);  

    return Val(type, res.conv2b64()); // Convert back to original type
}

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of Instructions in Basic/Mod Formats

static Val emulateMod(unsigned opcode, unsigned type, AluMod aluMod, unsigned packing, Val arg1, Val arg2, Val arg3, Val arg4)
{
    using namespace Brig;

    if (aluMod.getRounding() != AluMod::ROUNDING_NONE && 
        aluMod.getRounding() != AluMod::ROUNDING_NEAR) return unimplemented();

    switch (opcode)
    {
    case BRIG_OPCODE_ABS:       return emulateUnrOpSF(type, arg1, op_abs());
    case BRIG_OPCODE_NEG:       return emulateUnrOpSF(type, arg1, op_neg());

    case BRIG_OPCODE_NOT:       return emulateUnrOpB(type, arg1, op_not());

    case BRIG_OPCODE_ADD:       return emulateBinOpBSUF(type, arg1, arg2, op_add());  
    case BRIG_OPCODE_SUB:       return emulateBinOpBSUF(type, arg1, arg2, op_sub());  
    case BRIG_OPCODE_MUL:       return emulateBinOpBSUF(type, arg1, arg2, op_mul());  
    case BRIG_OPCODE_MULHI:     return emulateBinOpBSUF(type, arg1, arg2, op_mulhi());
    case BRIG_OPCODE_DIV:       return emulateBinOpBSUF(type, arg1, arg2, op_div());  
    case BRIG_OPCODE_MAX:       return emulateBinOpBSUF(type, arg1, arg2, op_max());  
    case BRIG_OPCODE_MIN:       return emulateBinOpBSUF(type, arg1, arg2, op_min());  

    case BRIG_OPCODE_REM:       return emulateBinOpSU(type, arg1, arg2, op_rem());

    case BRIG_OPCODE_MUL24:     return emulateTrnOpSU(type, arg1, arg2, Val(type, 0), op_mad24(0));
    case BRIG_OPCODE_MUL24HI:   return emulateTrnOpSU(type, arg1, arg2, Val(type, 0), op_mad24(32));

    case BRIG_OPCODE_MAD24:     return emulateTrnOpSU(type, arg1, arg2, arg3, op_mad24(0));
    case BRIG_OPCODE_MAD24HI:   return emulateTrnOpSU(type, arg1, arg2, arg3, op_mad24(32));

    case BRIG_OPCODE_AND:       return emulateBinOpB(type, arg1, arg2, op_and());
    case BRIG_OPCODE_OR:        return emulateBinOpB(type, arg1, arg2, op_or()); 
    case BRIG_OPCODE_XOR:       return emulateBinOpB(type, arg1, arg2, op_xor());

    case BRIG_OPCODE_COPYSIGN:  return emulateBinOpF(type, arg1, arg2, op_copysign());

    case BRIG_OPCODE_CARRY:     return emulateAluFlag(type, arg1, arg2, op_carry()); 
    case BRIG_OPCODE_BORROW:    return emulateAluFlag(type, arg1, arg2, op_borrow());

    case BRIG_OPCODE_SHL:       return emulateBinOpSU_U32(type, arg1, arg2, op_shl());
    case BRIG_OPCODE_SHR:       return emulateBinOpSU_U32(type, arg1, arg2, op_shr());

    case BRIG_OPCODE_FRACT:     return emulateUnrOpF(type, arg1, op_fract());
    case BRIG_OPCODE_CEIL:      return emulateUnrOpF(type, arg1, op_ceil());
    case BRIG_OPCODE_FLOOR:     return emulateUnrOpF(type, arg1, op_floor());
    case BRIG_OPCODE_RINT:      return emulateUnrOpF(type, arg1, op_rint());
    case BRIG_OPCODE_TRUNC:     return emulateUnrOpF(type, arg1, op_trunc());

    case BRIG_OPCODE_SQRT:      return emulateUnrOpF(type, arg1, op_sqrt()); 
    case BRIG_OPCODE_NCOS:      return emulateUnrOpF(type, arg1, op_cos());
    case BRIG_OPCODE_NSIN:      return emulateUnrOpF(type, arg1, op_sin());
    case BRIG_OPCODE_NEXP2:     return emulateUnrOpF(type, arg1, op_exp2()); 
    case BRIG_OPCODE_NLOG2:     return emulateUnrOpF(type, arg1, op_log2()); 
    case BRIG_OPCODE_NSQRT:     return emulateUnrOpF(type, arg1, op_sqrt());
    case BRIG_OPCODE_NRSQRT:    return emulateUnrOpF(type, arg1, op_rsqrt());
    case BRIG_OPCODE_NRCP:      return emulateUnrOpF(type, arg1, op_rcp());
    case BRIG_OPCODE_NFMA:      return emulateTrnOpSUF(type, arg1, arg2, arg3, op_mad());

    case BRIG_OPCODE_MAD:       return emulateTrnOpSUF(type, arg1, arg2, arg3, op_mad());
    case BRIG_OPCODE_FMA:       return emulateTrnOpSUF(type, arg1, arg2, arg3, op_mad());  // the same as mad but fp type

    case BRIG_OPCODE_MOV:       assert(arg1.getType() == type);         return arg1;
    case BRIG_OPCODE_CMOV:      assert(arg1.getType() == BRIG_TYPE_B1); return emulateTrnOpB(type, Val(type, arg1.conv2b32()), arg2, arg3, op_cmov());

    case BRIG_OPCODE_BITMASK:   return emulateBinOpB(arg1.getType(), arg1, arg2, op_bitmask(type));
    case BRIG_OPCODE_BITSELECT: return emulateTrnOpB(type, arg1, arg2, arg3, op_bitsel());

    case BRIG_OPCODE_BITREV:    return emulateUnrOpB(type, arg1, op_bitrev());
    case BRIG_OPCODE_BITEXTRACT:return emulateTrnOpSU_U32_U32(type, arg1, arg2, arg3, op_bitextract());
    case BRIG_OPCODE_BITINSERT: return emulateQrnOpSU_U32_U32(type, arg1, arg2, arg3, arg4, op_bitinsert());

    case BRIG_OPCODE_BITALIGN:  return emulateTrnOpB(type, arg1, arg2, arg3, op_bitalign(31, 1));
    case BRIG_OPCODE_BYTEALIGN: return emulateTrnOpB(type, arg1, arg2, arg3, op_bitalign( 3, 8));

    default: return emulationFailed();
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of Instructions in SourceType Format

static Val emulateSourceType(unsigned opcode, unsigned type, unsigned stype, Val arg1, Val arg2, Val arg3)
{
    using namespace Brig;

    switch (opcode)
    {
    case BRIG_OPCODE_CLASS:     return emulate_class(stype, arg1, arg2);
    case BRIG_OPCODE_POPCOUNT:  return emulate_popcount(stype, arg1);
    case BRIG_OPCODE_FIRSTBIT:  return emulate_firstbit(stype, arg1);
    case BRIG_OPCODE_LASTBIT:   return emulate_lastbit(stype, arg1);

    case BRIG_OPCODE_COMBINE:   return emulate_combine(type, stype, arg1);
    case BRIG_OPCODE_EXPAND:    return emulate_expand(type, stype, arg1);

    default: return emulationFailed();
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Emulation of Instructions in Mem Format (ld/st)

static Val emulateMemDst(unsigned segment, unsigned opcode, Val arg)
{
    using namespace Brig;

    switch (opcode)
    {
    case BRIG_OPCODE_LD:  return arg;
    case BRIG_OPCODE_ST:  return emptyDstValue();

    default: return emulationFailed();
    }
}

static Val emulateMemMem(unsigned segment, unsigned opcode, Val arg0, Val arg1)
{
    using namespace Brig;

    switch (opcode)
    {
    case BRIG_OPCODE_LD:  return arg1;
    case BRIG_OPCODE_ST:  return arg0;

    default: return emulationFailed();
    }
}

//=============================================================================
//=============================================================================
//=============================================================================
// Helpers

// Arrays declared at TOPLEVEL must belong to global, group or private segments.
// NB: Readonly cannot be initialized and so unsuitable for tesing.
static bool isSupportedSegment(unsigned segment)
{
    using namespace Brig;

    switch (segment)
    {
    case BRIG_SEGMENT_GLOBAL:
    case BRIG_SEGMENT_GROUP:
    case BRIG_SEGMENT_PRIVATE:
        return true;
    default:
        return false;
    }
}

static unsigned getRegSize(unsigned type)
{
    unsigned typeSize = getTypeSize(type);
    return (typeSize == 1)? 1 : (typeSize <= 32)? 32 : 64;
}

static bool isOperandExtended(unsigned type, Operand opr)
{
    return getRegSize(type) < getRegSize(getOperandType(opr));
}

void emulateFtz(Inst inst, Val& arg0, Val& arg1, Val& arg2, Val& arg3, Val& arg4)
{
    bool ftz = false;

    if      (InstMod i = inst)  ftz = i.modifier().ftz();
    else if (InstCmp i = inst)  ftz = i.modifier().ftz();
    else if (InstCvt i = inst)  ftz = i.modifier().ftz();

    if (ftz)
    {
        arg0 = arg0.ftz();
        arg1 = arg1.ftz();
        arg2 = arg2.ftz();
        arg3 = arg3.ftz();
        arg4 = arg4.ftz();
    }
}
//=============================================================================
//=============================================================================
//=============================================================================
// Public interface with Emulator

// Check generic limitations on instruction being tested
// NB: Most limitations should be encoded in HSAILTestGenLuaTestData.h
//     This function shall only check limitations which cannot be expressed there
bool testableInst(Inst inst)
{
    using namespace Brig;
    assert(inst);

    if (InstAtomic instAtomic = inst) 
    {
        if (!isSupportedSegment(instAtomic.segment())) return false;
    }
    else if (InstCvt instCvt = inst)
    {
        if (isOperandExtended(instCvt.type(),       instCvt.operand(0))) return false; // Disable dst extension
        if (isOperandExtended(instCvt.sourceType(), instCvt.operand(1))) return false; // Disable src extension
    }
    else if (InstMem instMem = inst)
    {
        if (!isSupportedSegment(instMem.segment())) return false;
        if (isOperandExtended(inst.type(), inst.operand(0))) return false; // Disable dst extension
        if (instMem.width() != BRIG_WIDTH_NONE && instMem.width() != BRIG_WIDTH_1) return false;
        if (instMem.equivClass() != 0) return false;
    }

    return true;
}

// Emulate execution of instruction 'inst' using provided input values.
// Return value stored into destination register or an empty value 
// if there is no destination or if emulation failed.
Val emulateDstVal(Inst inst, Val arg0, Val arg1, Val arg2, Val arg3, Val arg4)
{
    Val res;

    emulateFtz(inst, arg0, arg1, arg2, arg3, arg4);

    if      (InstBasic      i = inst)  res = emulateMod(i.opcode(), i.type(), AluMod(0), Brig::BRIG_PACK_NONE, arg1, arg2, arg3, arg4);
    else if (InstMod        i = inst)  res = emulateMod(i.opcode(), i.type(), AluMod(i.modifier().allBits()), i.pack(), arg1, arg2, arg3, arg4);
    else if (InstCmp        i = inst)  res = emulateCmp(i.type(),   i.sourceType(), AluMod(i.modifier().allBits()), i.compare(), arg1, arg2);
    else if (InstCvt        i = inst)  res = emulateCvt(i.type(),   i.sourceType(), AluMod(i.modifier().allBits()), arg1);
    else if (InstSourceType i = inst)  res = emulateSourceType(i.opcode(), i.type(), i.sourceType(), arg1, arg2, arg3);
    else if (InstAtomic     i = inst)  res = emulateAtomicDst(inst.opcode(), arg1);
    else if (InstMem        i = inst)  res = emulateMemDst(i.segment(), i.opcode(), arg1);
    else                               res = emulationFailed();

    return res.normalize();
}

// Emulate execution of instruction 'inst' using provided input values.
// Return value stored into memory or an empty value if this 
// instruction does not modify memory or if emulation failed.
Val emulateMemVal(Inst inst, Val arg0, Val arg1, Val arg2, Val arg3, Val arg4)
{
    using namespace Brig;

    Val res;

    if (InstAtomic i = inst)
    {
        switch (i.opcode())
        {
        case BRIG_OPCODE_ATOMIC:      res = emulateAtomicMem(i.type(), i.atomicOperation(), arg1, arg2, arg3); break;
        case BRIG_OPCODE_ATOMICNORET: res = emulateAtomicMem(i.type(), i.atomicOperation(), arg0, arg1, arg2); break;
        default:                      res = emulationFailed();                                                 break;
        }
    }
    else if (InstMem i = inst)
    {
        res = emulateMemMem(i.segment(), i.opcode(), arg0, arg1);
    }
    else
    {
        res = emptyMemValue();
    }

    return res.normalize();
}

// Return precision of result computation for this instruction.
// Return 0 for results computed with infinite precision.
// This is a property of target HW, not emulator!
double getPrecision(Inst inst)
{
    using namespace Brig;

    switch(inst.opcode()) // Instructions with HW-specific precision
    {
    case BRIG_OPCODE_NRCP:
    case BRIG_OPCODE_NSQRT:
    case BRIG_OPCODE_NRSQRT:
         if (inst.type() == BRIG_TYPE_F64) return 0.00000002;
         break;
    case BRIG_OPCODE_NEXP2:
    case BRIG_OPCODE_NLOG2:
         if (inst.type() == BRIG_TYPE_F32) return 0.0000005;
         break;
    }

    switch(inst.type()) // Standard precision
    {
    case BRIG_TYPE_F16: assert(false);
    case BRIG_TYPE_F32: return 0.0000001;
    case BRIG_TYPE_F64: return 0.0000000000000005; 
    }

    return 0; // infinite precision
}

//=============================================================================
//=============================================================================
//=============================================================================

} // namespace TESTGEN
