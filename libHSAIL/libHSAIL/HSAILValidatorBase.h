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
    const unsigned mModel;
    const unsigned mProfile;

    //==========================================================================
public:
    PropValidator(unsigned model, unsigned profile) : mModel(model), mProfile(profile) {}

    unsigned getMachineSize()  { return isLargeModel()? 64 : 32; }
    bool isLargeModel()        { return mModel   == Brig::BRIG_MACHINE_LARGE; }
    bool isFullProfile()       { return mProfile == Brig::BRIG_PROFILE_FULL; }

    //==========================================================================
    // Interface with HDL-generated code
protected:
    void validate(Inst inst, int idx, bool cond, SRef msg);
    void validate(Inst inst, bool cond, SRef msg) { validate(inst, -1, cond, msg); }

    void invalidVariant(Inst inst, unsigned prop);
    void invalidVariant(Inst inst, unsigned prop1, unsigned prop2);
    void invalidVariant(Inst inst, unsigned prop1, unsigned prop2, unsigned prop3);
    void brigPropError(Inst inst, unsigned prop, unsigned value, unsigned* vals, unsigned length);
    void invalidFormat(Inst inst, const char* msg);

    bool validateOperand(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);
    bool validateTypeSz(Inst inst, unsigned propVal, unsigned type, const char* typeName, bool isAssert = true);
    bool validateTypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);
    bool validateStypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);
    bool validateEqclass(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true);
    bool validateSpecialProp(Inst inst, unsigned prop, unsigned val, unsigned* vals, unsigned length, bool isAssert = true);
    bool validateFtz(Inst inst, unsigned prop, unsigned val, unsigned* vals, unsigned length, bool isAssert = true);
    bool validateRound(Inst inst, unsigned prop, unsigned val, unsigned* vals, unsigned length, bool isAssert = true);

    //==========================================================================
public:
    static unsigned    attr2type(Inst inst, unsigned idx, unsigned attr);
    static string      prop2str(unsigned prop);
    static const char* prop2key(unsigned prop);
    static const char* val2str(unsigned prop, unsigned val);
    static const char* operand2str(unsigned val);
    static const char* operandKind2str(unsigned kind);

    //==========================================================================
    // Autogenerated accessors for BRIG properties (used by HDL-generated code)
public:

#include "HSAILBrigPropsFastAcc_gen.hpp"

    //==========================================================================
    // Special accessors for BRIG properties with default values (used by HDL-generated code)
public:

    template<class T> unsigned getPackEx(T inst)
    {
        if      (InstCmp   i = inst) return i.pack();
        else if (InstMod   i = inst) return i.pack();
        else if (InstBasic i = inst) return Brig::BRIG_PACK_NONE;
        assert(false);               return Brig::BRIG_PACK_NONE;
    }

    template<class T> unsigned getRoundEx(T inst)
    {
        if      (InstCmp   i = inst) return i.modifier().round();
        else if (InstCvt   i = inst) return i.modifier().round();
        else if (InstMod   i = inst) return i.modifier().round();
        else if (InstBasic i = inst) return getDefRounding(i, mModel, mProfile);
        assert(false);               return Brig::BRIG_ROUND_NONE;
    }

    template<class T> unsigned getFtzEx(T inst)
    {
        if      (InstCmp   i = inst) return i.modifier().ftz();
        else if (InstCvt   i = inst) return i.modifier().ftz();
        else if (InstMod   i = inst) return i.modifier().ftz();
        else if (InstBasic i = inst) return 0;
        assert(false);               return 0;
    }

    //==========================================================================
private:
    bool validateOperandAttr(Inst inst, unsigned idx, unsigned attr, bool isDst, bool isAssert);
    bool checkOperandKind(Inst inst, unsigned idx, unsigned* vals, unsigned length, bool isAssert);
    bool checkAddrSeg(Inst inst, unsigned operandIdx, bool isAssert);
    bool checkAddrTSeg(Inst inst, unsigned operandIdx, bool isAssert);

    static bool isVector(Operand opr, unsigned size);
    static bool isArgList(Operand opr);
    static bool isCallTab(Operand opr);
    static bool isJumpTab(Operand opr);
    static bool isImm(Operand opr);
    static bool isImmInRange(Operand opr, unsigned low, unsigned high);
    static bool eqTypes(unsigned type1, unsigned type2) { return getBrigTypeNumBits(type1) == getBrigTypeNumBits(type2); }
    void propError(Inst inst, unsigned prop, string value, unsigned* vals, unsigned length);

    //==========================================================================
private:
    bool validateDstVector(Inst inst, OperandOperandList vector, unsigned oprIdx, bool isAssert);
    bool validateOperandType(Inst inst, unsigned oprIdx, bool isDst, unsigned attr, bool isAssert);
    bool validateOperandReg(Inst inst, OperandReg opr, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert);
    bool validateOperandImmed(Inst inst, OperandData opr, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert);
    bool validateOperandWavesize(Inst inst, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert);
    bool validateOperandVector(Inst inst, OperandOperandList opr, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert);
    bool validateInstTypeSize(Inst inst, unsigned type, const char* typeName, bool isAssert);
    bool validateAtomicTypeSize(Inst inst, bool isAssert);

    //==========================================================================
private:
    string getErrHeader(unsigned oprIdx, const char* oprPref);
    void operandError(Inst inst, unsigned oprIdx, string msg1, string msg2 = "");
    void wavesizeError(Inst inst, unsigned oprIdx, unsigned type, unsigned attr);
    void operandTypeError(Inst inst, unsigned oprIdx, unsigned type);
    void operandSizeError(Inst inst, unsigned oprIdx, unsigned type, unsigned attr);

}; // class PropValidator

} // namespace HSAIL_ASM

#endif // INCLUDED_HSAIL_VALIDATOR_BASE_H