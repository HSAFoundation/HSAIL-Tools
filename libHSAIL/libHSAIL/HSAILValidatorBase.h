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

#include "HSAILInstProps.h"

#include <string.h>

using std::string;

using namespace HSAIL_PROPS;

//============================================================================
//============================================================================
//============================================================================
// Instruction Validator

namespace HSAIL_ASM {

//============================================================================

class PropValidator
{
private:
    static unsigned machineType;
    static bool expandOperands;

    //==========================================================================
public:
    PropValidator(unsigned type)                        { machineType = type; expandOperands = true; }
    static unsigned getMachineType()                    { return machineType; }
    static bool isLargeModel()                          { return machineType == Brig::BRIG_TYPE_B64; }
    static void setMachineType(unsigned type)           { machineType = type; }
    static void enableOperandsExpansion(bool enable)    { expandOperands = enable; }

    //==========================================================================
    // Interface with HDL-generated code
public: 
    static void validate(Inst inst, int idx, bool cond, SRef msg) { Validator::validate(inst, idx, msg, cond); }
    static void validate(Inst inst, bool cond, SRef msg) { validate(inst, -1, cond, msg); }

    static void invalidVariant(Inst inst, unsigned prop);
    static void invalidVariant(Inst inst, unsigned prop1, unsigned prop2);

    static void brigPropError(Inst inst, unsigned prop, unsigned value, unsigned* vals, unsigned length);
    static void invalidFormat(Inst inst, const char* msg);

    static bool validateOperand(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);

    static bool validateTypeSz(Inst inst, bool isSrcType, unsigned val, bool isAssert = true);
    static bool validateTypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);
    static bool validateStypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);

    static bool validateEqclass(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);

    //==========================================================================
public:
    static unsigned    getOperandIdx(unsigned prop);
    static string      prop2str(unsigned prop);
    static const char* prop2key(unsigned prop);
    static const char* val2str(unsigned prop, unsigned val);

    //==========================================================================
public:
    static const char* operand2str(unsigned val);
    static const char* operandKind2str(unsigned kind);

    //==========================================================================
    // Accessors for BRIG properties (used by generated code)
public: 
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
    template<class T> static unsigned getWidth(T inst)    { assert(inst); return inst.width(); }

    template<class T> static unsigned getMemfnc(T inst)   { assert(inst); return inst.memoryFence(); }
    template<class T> static unsigned getMemord(T inst)   { assert(inst); return inst.memoryOrder(); }
    template<class T> static unsigned getMemscp(T inst)   { assert(inst); return inst.memoryScope(); }

    template<class T> static unsigned getPacking(T inst)
    {
        if      (InstCmp   i = inst) return i.pack();
        else if (InstMod   i = inst) return i.pack();
        else if (InstBasic i = inst) return Brig::BRIG_PACK_NONE;
        assert(false);               return Brig::BRIG_PACK_NONE;
    }

    template<class T> static unsigned getRounding(T inst)
    {
        if      (InstCmp   i = inst) return i.modifier().round(); 
        else if (InstCvt   i = inst) return i.modifier().round();
        else if (InstMod   i = inst) return i.modifier().round();
        else if (InstBasic i = inst) return getDefRounding(i.opcode(), i.type());
        assert(false);               return Brig::BRIG_ROUND_NONE;
    }

    template<class T> static unsigned getFtz(T inst)
    {
        if      (InstCmp   i = inst) return i.modifier().ftz(); 
        else if (InstCvt   i = inst) return i.modifier().ftz();
        else if (InstMod   i = inst) return i.modifier().ftz();
        else if (InstBasic i = inst) return 0;
        assert(false);               return 0;
    }

    //==========================================================================
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

    static bool eqTypes(unsigned type1, unsigned type2) { return getTypeSize(type1) == getTypeSize(type2); }

    static void propError(Inst inst, unsigned prop, string value, unsigned* vals, unsigned length);

}; // class PropValidator

} // namespace HSAIL_ASM

#endif // INCLUDED_HSAIL_VALIDATOR_BASE_H