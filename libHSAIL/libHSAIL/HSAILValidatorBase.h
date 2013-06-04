// University of Illinois/NCSA
// Open Source License
// 
// Copyright (c) 2013, Advanced Micro Devices, Inc.
// All rights reserved.
// 
// Developed by:
// 
//     HSA Team
// 
//     Advanced Micro Devices, Inc
// 
//     www.amd.com
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal with
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
// 
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimers.
// 
//     * Redistributions in binary form must reproduce the above copyright notice,
//       this list of conditions and the following disclaimers in the
//       documentation and/or other materials provided with the distribution.
// 
//     * Neither the names of the LLVM Team, University of Illinois at
//       Urbana-Champaign, nor the names of its contributors may be used to
//       endorse or promote products derived from this Software without specific
//       prior written permission.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE
// SOFTWARE.
//===-- HSAILValidatorBase.cpp - HSAIL Validator ------------------------------===//

#ifndef INCLUDED_HSAIL_VALIDATOR_BASE_H
#define INCLUDED_HSAIL_VALIDATOR_BASE_H

#include "HSAILItems.h"
#include "HSAILUtilities.h"
#include "HSAILValidator.h"
#include "HSAILSRef.h"
#include "Brig.h"

#include <string.h>

using std::string;

// ============================================================================
// ============================================================================
//============================================================================
namespace HSAIL_PROPS
{

enum
{
    PROP_MINID = 0,
    PROP_NONE  = 0,

    // Brig properties

    PROP_OPCODE, // FIXME: do we really need this property?

    PROP_TYPE,
    PROP_STYPE,
    PROP_ITYPE,
    PROP_CTYPE,

    PROP_PACKING,
    PROP_OPERATOR,
    PROP_ROUNDING,
    PROP_FTZ,
    PROP_ALIGN,
    PROP_ATMOP,
    PROP_MSEM,
    PROP_GEOM,
    PROP_SYNC,
    PROP_SEGMENT,
    PROP_WIDTH,
    PROP_EQCLASS,

    // Non-Brig properties

    PROP_TYPESIZE,
    PROP_STYPESIZE,

    PROP_D0,
    PROP_D1,

    PROP_S0,
    PROP_S1,
    PROP_S2,
    PROP_S3,
    PROP_S4,

    PROP_OPERAND, // FIXME: SHOULD WE REMOVE IT?

    PROP_MAXID
};

enum
{
    ATTR_MINID = 0,

    OPERAND_ATTR_NONE,
    OPERAND_ATTR_CTYPE,
    OPERAND_ATTR_STYPE,
    OPERAND_ATTR_MODEL,
    OPERAND_ATTR_EXP,
    OPERAND_ATTR_SEXP,
    OPERAND_ATTR_NOEXP,

    TYPESIZE_ATTR_NONE,
    STYPESIZE_ATTR_NONE,

    ATTR_MAXID
};

enum
{
    VAL_MINID = 0,

    OPERAND_VAL_NULL,

    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4,

    OPERAND_VAL_IMM,
    OPERAND_VAL_LAB,
    OPERAND_VAL_ADDR_SEG,
    OPERAND_VAL_ADDR_TSEG,
    OPERAND_VAL_FUNC,
    OPERAND_VAL_ARGLIST,
    OPERAND_VAL_JUMPTAB,
    OPERAND_VAL_CALLTAB,
    OPERAND_VAL_FBARRIER,

    OPERAND_VAL_ROIMAGE,
    OPERAND_VAL_RWIMAGE,
    OPERAND_VAL_SAMPLER,

    OPERAND_VAL_REG_1,
    OPERAND_VAL_REG_64,
    OPERAND_VAL_REG_32,
    OPERAND_VAL_REG_128,

    OPERAND_VAL_IMM_1,
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_IMM_64,
    OPERAND_VAL_IMM_128,

    OPERAND_VAL_IMM_0_1_2,
    OPERAND_VAL_IMM_0_1_2_3,

    OPERAND_VAL_REG_V2_1,
    OPERAND_VAL_REG_V2_32,
    OPERAND_VAL_REG_V2_64,
    OPERAND_VAL_REG_V2_128,

    OPERAND_VAL_REG_V3_1,
    OPERAND_VAL_REG_V3_32,
    OPERAND_VAL_REG_V3_64,
    OPERAND_VAL_REG_V3_128,

    OPERAND_VAL_REG_V4_1,
    OPERAND_VAL_REG_V4_32,
    OPERAND_VAL_REG_V4_64,
    OPERAND_VAL_REG_V4_128,

    OPERAND_VAL_INVALID,

    TYPESIZE_VAL_MODEL,
    TYPESIZE_VAL_SEG,
    STYPESIZE_VAL_MODEL = TYPESIZE_VAL_MODEL,
    STYPESIZE_VAL_SEG   = TYPESIZE_VAL_SEG,

    VAL_MAXID
};

};

using namespace HSAIL_PROPS;

// ============================================================================
// ============================================================================
//============================================================================
// Instruction Validator

namespace HSAIL_ASM {

//============================================================================

class InstValidatorBase
{
private:
    static unsigned machineType; // FIXME: changed to static for TestGen

public:
    InstValidatorBase(unsigned type) /* : machineType(type) */ { machineType = type;}
    static unsigned getMachineType() { return machineType; }
    static bool isLargeModel() { return machineType == Brig::BRIG_TYPE_B64; }
    static void setMachineType(unsigned type) { machineType = type; } // FIXME

public: // Interface with HDL-generated code
    static void validate(Inst inst, int idx, bool cond, SRef msg) { Validator::validate(inst, idx, msg, cond); }
    static void validate(Inst inst, bool cond, SRef msg) { validate(inst, -1, cond, msg); }

    static void invalidVariant(Inst inst, unsigned prop);
    static void invalidVariant(Inst inst, unsigned prop1, unsigned prop2);

    static void brigPropError(Inst inst, unsigned prop, unsigned value, unsigned* vals, unsigned length);
    static void invalidFormat(Inst inst, const char* msg);

    static bool validateOperand(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);

    static bool validateTypeSize(Inst inst, bool isSrcType, unsigned val, bool isAssert = true);
    static bool validateTypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);
    static bool validateStypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);

private:
    static bool validateOperandAttr(Inst inst, unsigned idx, unsigned attr, bool isDst, bool isAssert);
    static bool checkOperandKind(Inst inst, unsigned idx, unsigned* vals, unsigned length, bool isAssert);

    static bool checkAddrSeg(Inst inst, unsigned operandIdx, bool isAssert);
    static bool checkAddrTSeg(Inst inst, unsigned operandIdx, bool isAssert);
    static bool isImage(Operand addr, bool isRW = false);
    static bool isSampler(Operand addr);
    static bool isJumpTab(Inst inst, unsigned operandIdx, bool isAssert);
    static bool isCallTab(Inst inst, unsigned operandIdx, bool isAssert);
    static bool isImmInRange(OperandImmed imm, unsigned low, unsigned high);

private:
    static bool eqTypes(unsigned type1, unsigned type2) { return getTypeSize(type1) == getTypeSize(type2); }

private:
    static unsigned getOperandIdx(unsigned prop);
    static string      prop2str(unsigned prop);
    static const char* val2str(unsigned prop, unsigned val);

    static const char* operand2str(unsigned val);

    static void propError(Inst inst, unsigned prop, string value, unsigned* vals, unsigned length);

protected: // Accessors for BRIG properties (used by generated code)
    template<class T> static unsigned getType(T inst)     { assert(inst); return inst.type(); }
    template<class T> static unsigned getStype(T inst)    { assert(inst); return inst.sourceType(); }
    template<class T> static unsigned getItype(T inst)    { assert(inst); return inst.imageType(); }
    template<class T> static unsigned getCtype(T inst)    { assert(inst); return inst.coordType(); }
    template<class T> static unsigned getEqclass(T inst)  { assert(inst); return inst.equivClass(); }
    template<class T> static unsigned getAlign(T inst)    { assert(inst); return inst.modifier().aligned(); }
    template<class T> static unsigned getOperator(T inst) { assert(inst); return inst.compare(); }
    template<class T> static unsigned getSegment(T inst)  { assert(inst); return inst.segment(); }
    template<class T> static unsigned getAtmop(T inst)    { assert(inst); return inst.atomicOperation(); }
    template<class T> static unsigned getGeom(T inst)     { assert(inst); return inst.geometry(); }
    template<class T> static unsigned getSync(T inst)     { assert(inst); return inst.memoryFence(); }
    template<class T> static unsigned getWidth(T inst)    { assert(inst); return inst.width(); }

    template<class T> static unsigned getMsem(T inst)
    {
        assert(inst);
        if      (InstAtomic i = inst) return i.memorySemantic();
        else if (InstMem    i = inst) return i.modifier().semantic();
        assert(false);                return Brig::BRIG_SEMANTIC_NONE;
    }

    template<class T> static unsigned getPacking(T inst)
    {
        if      (InstCmp   i = inst) return i.pack();
        else if (InstMod   i = inst) return i.pack();
        else if (InstBasic i = inst) return Brig::BRIG_PACK_NONE;
        assert(false);               return Brig::BRIG_PACK_NONE;
    }

    template<class T> static unsigned getRounding(T inst)
    {
        if      (InstBr    i = inst) return i.modifier().round();
        else if (InstCmp   i = inst) return i.modifier().round();
        else if (InstCvt   i = inst) return i.modifier().round();
        else if (InstMod   i = inst) return i.modifier().round();
        else if (InstBasic i = inst) return getDefRounding(i.opcode(), i.type());
        assert(false);               return Brig::BRIG_ROUND_NONE;
    }

    template<class T> static unsigned getFtz(T inst)
    {
        if      (InstBr    i = inst) return i.modifier().ftz();
        else if (InstCmp   i = inst) return i.modifier().ftz();
        else if (InstCvt   i = inst) return i.modifier().ftz();
        else if (InstMod   i = inst) return i.modifier().ftz();
        else if (InstBasic i = inst) return 0;
        assert(false);               return 0;
    }

}; // class InstValidatorBase

} // namespace HSAIL_ASM

#endif // INCLUDED_HSAIL_VALIDATOR_BASE_H