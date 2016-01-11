// University of Illinois/NCSA
// Open Source License
//
// Copyright (c) 2013-2015, Advanced Micro Devices, Inc.
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

    unsigned getMachineSize() const { return isLargeModel()? 64 : 32; }
    bool isLargeModel()       const { return mModel   == BRIG_MACHINE_LARGE; }
    bool isFullProfile()      const { return mProfile == BRIG_PROFILE_FULL; }

    //==========================================================================
    // Interface with HDL-generated code
protected:
    virtual void validate(Inst inst, int idx, bool cond, SRef msg) const ;
    virtual void validate(Inst inst, bool cond, SRef msg) const { validate(inst, -1, cond, msg); }

    virtual void invalidVariant(Inst inst, unsigned prop) const;
    virtual void invalidVariant(Inst inst, unsigned prop1, unsigned prop2) const;
    virtual void invalidVariant(Inst inst, unsigned prop1, unsigned prop2, unsigned prop3) const;
    virtual void brigPropError(Inst inst, unsigned prop, unsigned value, unsigned* vals, unsigned length) const;
    virtual void invalidFormat(Inst inst, const char* msg) const;

    virtual bool validateOperand(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true) const;
    virtual bool validateTypeSz(Inst inst, unsigned propVal, unsigned type, const char* typeName, bool isAssert = true) const;
    virtual bool validateTypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true) const;
    virtual bool validateStypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true) const;
    virtual bool validateEqclass(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert = true) const;
    virtual bool validateSpecialProp(Inst inst, unsigned prop, unsigned val, unsigned* vals, unsigned length, bool isAssert = true) const;
    virtual bool validateFtz(Inst inst, unsigned prop, unsigned val, unsigned* vals, unsigned length, bool isAssert = true) const;
    virtual bool validateRound(Inst inst, unsigned prop, unsigned val, unsigned* vals, unsigned length, bool isAssert = true) const;

    //==========================================================================
public:
    virtual const char* type2name(unsigned val)             const { return propVal2mnemo(PROP_TYPE,            val); };
    virtual const char* pack2str(unsigned val)              const { return propVal2mnemo(PROP_PACK,            val); };
    virtual const char* width2str(unsigned val)             const { return propVal2mnemo(PROP_WIDTH,           val); };
    virtual const char* memoryOrder2str(unsigned val)       const { return propVal2mnemo(PROP_MEMORYORDER,     val); };
    virtual const char* memoryScope2str(unsigned val)       const { return propVal2mnemo(PROP_MEMORYSCOPE,     val); };
    virtual const char* round2str(unsigned val)             const { return propVal2mnemo(PROP_ROUND,           val); };
    virtual const char* segment2str(unsigned val)           const { return propVal2mnemo(PROP_SEGMENT,         val); };
    virtual const char* align2str(unsigned val)             const { return propVal2mnemo(PROP_ALIGN,           val); };
    virtual const char* compareOperation2str(unsigned val)  const { return propVal2mnemo(PROP_COMPARE,         val); };
    virtual const char* atomicOperation2str(unsigned val)   const { return propVal2mnemo(PROP_ATOMICOPERATION, val); };
    virtual const char* imageGeometry2str(unsigned val)     const { return propVal2mnemo(PROP_GEOMETRY,        val); };
    virtual const char* imageQuery2str(unsigned val)        const { return propVal2mnemo(PROP_IMAGEQUERY,      val); };
    virtual const char* samplerQuery2str(unsigned val)      const { return propVal2mnemo(PROP_SAMPLERQUERY,    val); };
    virtual const char* opcode2str(unsigned val)            const { return propVal2mnemo(PROP_OPCODE,          val); };

    virtual const char* propVal2str(unsigned prop, unsigned val) const 
    { 
        const char* s = HSAIL_ASM::stdPropVal2str(prop, val);
        return s? s : propValExt2mnemo(prop, val);
    }

    virtual const char* propVal2mnemo(unsigned prop, unsigned val) const 
    { 
        const char* s = HSAIL_ASM::stdPropVal2mnemo(prop, val);
        return s? s : propValExt2mnemo(prop, val);
    }

    //==========================================================================
    // Methods typically overloaded by extensions
public:
    virtual const char* propValExt2mnemo(unsigned prop, unsigned val) const { return 0; };
    virtual unsigned    getSegAddrSize(unsigned seg, bool isL)        const { return HSAIL_ASM::getSegAddrSize(seg, isL); }
    virtual bool        isAddressableSeg(unsigned seg)                const { return HSAIL_ASM::isAddressableSeg(seg); }

    //==========================================================================
public:
    virtual const char* operand2str(unsigned valId)           const { return HSAIL_ASM::operand2str(valId); }
    virtual const char* operandKind2str(unsigned kind)        const { return HSAIL_ASM::operandKind2str(kind); }
    virtual unsigned    attr2type(Inst inst, unsigned attr)   const { return HSAIL_ASM::attr2type(inst, attr); }
    virtual string      prop2str(unsigned prop)               const { return HSAIL_ASM::prop2str(prop); }
    virtual const char* prop2key(unsigned prop)               const { return HSAIL_ASM::prop2key(prop); }

    //==========================================================================
public:
    virtual unsigned  getBrigTypeNumBits(unsigned type)       const { return HSAIL_ASM::getBrigTypeNumBits(type); }
    virtual bool      eqTypes(unsigned type1, unsigned type2) const { return getBrigTypeNumBits(type1) == getBrigTypeNumBits(type2); }

    //==========================================================================
public:
    virtual unsigned getRoundAttr(Inst inst)                        const { assert(false); return ROUND_ATTR_INVALID; }
    virtual unsigned getWidthAttr(Inst inst)                        const { assert(false); return WIDTH_ATTR_INVALID; }
    virtual unsigned getOperandAttr(Inst inst, unsigned operandIdx) const { assert(false); return OPERAND_ATTR_INVALID; }

    virtual unsigned operandAttr2Type(Inst inst, unsigned attr) const;
    virtual unsigned attr2DefWidth(Inst inst, unsigned attr) const;
    virtual unsigned attr2DefRounding(Inst inst, unsigned attr) const;
    virtual const char* validateOperandDeps(Inst inst, unsigned attr) const;

    virtual unsigned getDefRounding(Inst inst) const { assert(inst); return attr2DefRounding(inst, getRoundAttr(inst)); }
    virtual unsigned getDefWidth(Inst inst)    const { assert(inst); return attr2DefWidth   (inst, getWidthAttr(inst)); }

    virtual const char* preValidateInst(Inst inst) const
    {
        assert(inst);

        for (unsigned idx = 0; idx < MAX_OPERANDS_NUM; ++idx)
        {
            const char* err = validateOperandDeps(inst, getOperandAttr(inst, idx));
            if (err) return err;
        }
        return 0;
    }

    virtual unsigned getOperandType(Inst inst, unsigned operandIdx) const
    {
        assert(inst);
        assert(operandIdx < MAX_OPERANDS_NUM);

        return operandAttr2Type(inst, getOperandAttr(inst, operandIdx));
    }

    //==========================================================================
    // Special accessors for BRIG properties with default values (used by HDL-generated code)
public:

    template<class T> unsigned getPackEx(T inst) const
    {
        if      (InstCmp   i = inst) return i.pack();
        else if (InstMod   i = inst) return i.pack();
        else if (InstBasic i = inst) return BRIG_PACK_NONE;
        assert(false);               return BRIG_PACK_NONE;
    }

    template<class T> unsigned getRoundEx(T inst) const
    {
        if      (InstCvt   i = inst) return i.round();
        else if (InstMod   i = inst) return i.round();
        else if (InstBasic i = inst) return getDefRounding(i);
        assert(false);               return BRIG_ROUND_NONE;
    }

    template<class T> unsigned getFtzEx(T inst) const
    {
        if      (InstCmp   i = inst) return i.modifier().ftz();
        else if (InstCvt   i = inst) return i.modifier().ftz();
        else if (InstMod   i = inst) return i.modifier().ftz();
        else if (InstBasic i = inst) return 0;
        assert(false);               return 0;
    }

    //==========================================================================
protected:
    virtual bool validateOperandAttr(Inst inst, unsigned idx, unsigned attr, bool isDst, bool isAssert) const;
    virtual bool checkOperandKind(Inst inst, unsigned idx, unsigned* vals, unsigned length, bool isAssert) const;
    virtual bool checkAddrSeg(Inst inst, unsigned operandIdx, bool isAssert) const;
    virtual bool checkAddrTSeg(Inst inst, unsigned operandIdx, bool isAssert) const;

protected:
    static bool isVector(Operand opr, unsigned size);
    static bool isArgList(Operand opr);
    static bool isCallTab(Operand opr);
    static bool isJumpTab(Operand opr);
    static bool isImm(Operand opr);
    static bool isImmInRange(Operand opr, unsigned low, unsigned high);
    
    //==========================================================================
protected:
    virtual bool validateDstVector(Inst inst, OperandOperandList vector, unsigned oprIdx, bool isAssert) const;
    virtual bool validateOperandType(Inst inst, unsigned oprIdx, bool isDst, unsigned attr, bool isAssert) const;
    virtual bool validateOperandReg(Inst inst, OperandRegister opr, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert) const;
    virtual bool validateOperandImmed(Inst inst, OperandConstantBytes opr, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert) const;
    virtual bool validateOperandWavesize(Inst inst, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert) const;
    virtual bool validateOperandVector(Inst inst, OperandOperandList opr, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert) const;
    virtual bool validateInstTypeSize(Inst inst, unsigned type, const char* typeName, bool isAssert) const;
    virtual bool validateAtomicTypeSize(Inst inst, bool isAssert) const;

    //==========================================================================
protected:
    virtual string getErrHeader(unsigned oprIdx, const char* oprPref) const;
    virtual void operandError(Inst inst, unsigned oprIdx, string msg1, string msg2 = "") const;
    virtual void wavesizeError(Inst inst, unsigned oprIdx, unsigned type, unsigned attr) const;
    virtual void operandSizeError(Inst inst, unsigned oprIdx, unsigned type, unsigned attr) const;
    virtual void immTypeError(Inst inst, unsigned oprIdx, unsigned type, unsigned expectedType, bool isB1Error) const;
    virtual void propError(Inst inst, unsigned prop, const char* value, unsigned* vals, unsigned length) const;

}; // class PropValidator

} // namespace HSAIL_ASM

#endif // INCLUDED_HSAIL_VALIDATOR_BASE_H
