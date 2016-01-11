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
//===-- HSAILValidatorBase.cpp - HSAIL Validator Base------------------------------===//

#include "HSAILValidatorBase.h"
#include "HSAILItems.h"
#include "Brig.h"

#include <iosfwd>
#include <sstream>

#include <string.h>

using std::string;
using std::ostringstream;

// ============================================================================
// ============================================================================
//============================================================================
// Instruction Validator

namespace HSAIL_ASM {

//============================================================================

bool PropValidator::isVector(Operand opr, unsigned size)
{
    if (OperandOperandList list = opr)
    {
        unsigned sz = list.elements().size();
        if (sz != size) return false;

        for (unsigned idx = 0; idx < sz; ++idx)
        {
            Operand e = list.elements()[idx];
            if (!OperandRegister(e) && !OperandConstantBytes(e) && !OperandWavesize(e)) return false;
        }

        return true;
    }
    return false;
}

bool PropValidator::isArgList(Operand opr)
{
    if (OperandCodeList list = opr)
    {
        unsigned sz = list.elements().size(); // might be zero

        for (unsigned idx = 0; idx < sz; ++idx)
        {
            DirectiveVariable arg = list.elements()[idx];
            if (!arg) return false;
        }

        return true;
    }
    return false;
}

bool PropValidator::isCallTab(Operand opr)
{
    if (OperandCodeList list = opr)
    {
        unsigned sz = list.elements().size();
        if (sz == 0) return false;

        for (unsigned idx = 0; idx < sz; ++idx)
        {
            DirectiveExecutable f = list.elements()[idx];
            if (!f) return false;
            if (!DirectiveFunction(f) && !DirectiveIndirectFunction(f)) return false;
        }

        return true;
    }
    return false;
}

bool PropValidator::isJumpTab(Operand opr)
{
    if (OperandCodeList list = opr)
    {
        unsigned sz = list.elements().size();
        if (sz == 0) return false;

        for (unsigned idx = 0; idx < sz; ++idx)
        {
            DirectiveLabel lab = list.elements()[idx];
            if (!lab) return false;
        }

        return true;
    }
    return false;
}

void PropValidator::invalidFormat(Inst inst, const char* msg) const
{
    validate(inst, false, "Invalid instruction format, expected " + string(msg));
}

void PropValidator::brigPropError(Inst inst, unsigned prop, unsigned value, unsigned* vals, unsigned length) const
{
    ostringstream s;
    const char* svalue = propVal2str(prop, value);
    if (svalue) s << svalue; else s << value;
    propError(inst, prop, s.str().c_str(), vals, length);
}

void PropValidator::propError(Inst inst, unsigned prop, const char* val, unsigned* vals, unsigned length) const
{
    assert(inst);
    assert(vals && length > 0);
    assert(PROP_MINID < prop && prop < PROP_MAXID);
    assert(prop != PROP_TYPESIZE && prop != PROP_STYPESIZE); // metaproperties are special
    assert(propVal2str(prop, vals[0])); // generated values must be valid

    string s = propVal2str(prop, vals[0]);
    for (unsigned i = 1; i < length; ++i)
    {
        assert(propVal2str(prop, vals[i])); // generated values must be valid
        s = s + ", " + propVal2str(prop, vals[i]);
    }

    unsigned operandIdx = getOperandIdx(prop);
    string expected = (length == 1)? ", expected: " : ", expected one of: ";

    if (operandIdx < MAX_OPERANDS_NUM) // operand property
    {
        if (!inst.operand(operandIdx))
        {
            validate(inst, operandIdx, false, "Missing " + prop2str(prop) + expected + s);
        }
        else
        {
            validate(inst, operandIdx, false, "Invalid " + prop2str(prop) + expected + s);
        }
    }
    else // non-operand property
    {
        string value = (val == 0)? "" : val;
        if (value.length() > 0) value = " (" + value + ")";
        validate(inst, false, "Instruction has invalid " + prop2str(prop) + value + expected + s);
    }
}

bool PropValidator::validateTypeSz(Inst inst, unsigned propVal, unsigned type, const char* typeName, bool isAssert /*=true*/) const
{
    assert(inst);

    switch (propVal)
    {
    case TYPESIZE_VAL_SEG:
        if ((unsigned)getBrigTypeNumBits(type) == getSegAddrSize(getSegment(inst), isLargeModel())) return true;
        if (isAssert) validate(inst, false, string(typeName) + " must match segment kind and machine model");
        break;

    case TYPESIZE_VAL_MODEL:
        return validateInstTypeSize(inst, type, typeName, isAssert);

    case TYPESIZE_VAL_SIGNAL:
        if (type == BRIG_TYPE_SIG64 && isLargeModel())  return true;
        if (type == BRIG_TYPE_SIG32 && !isLargeModel()) return true;
        if (isAssert) validate(inst, false, "Instruction type must match machine model");
        break;

    case TYPESIZE_VAL_ATOMIC:
        return validateAtomicTypeSize(inst, isAssert);

    default:
        assert(false);
        break;
    }
    return false;
}

bool PropValidator::validateTypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert /*=true*/) const
{
    assert(length == 1);
    assert(attr == TYPESIZE_ATTR_NONE);

    return validateTypeSz(inst, vals[0], inst.type(), "Instruction type", isAssert);
}

bool PropValidator::validateStypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert /*=true*/) const
{
    assert(length == 1);
    assert(attr == STYPESIZE_ATTR_NONE);

    return validateTypeSz(inst, vals[0], getSrcType(inst), "Source type", isAssert);
}

bool PropValidator::validateOperandAttr(Inst inst, unsigned operandIdx, unsigned attr, bool isDst, bool isAssert) const
{
    assert(inst);
    assert(operandIdx < MAX_OPERANDS_NUM);
    assert(ATTR_MINID < attr && attr < ATTR_MAXID);
    assert(inst.operand(operandIdx));

    switch (attr)
    {
    case OPERAND_ATTR_DTYPE:
    case OPERAND_ATTR_STYPE:
    case OPERAND_ATTR_CTYPE:
    case OPERAND_ATTR_B1:
    case OPERAND_ATTR_B8:
    case OPERAND_ATTR_B16:
    case OPERAND_ATTR_B32:
    case OPERAND_ATTR_B64:
    case OPERAND_ATTR_B128:
    case OPERAND_ATTR_U8:
    case OPERAND_ATTR_U16:
    case OPERAND_ATTR_U32:
    case OPERAND_ATTR_U64:
    case OPERAND_ATTR_S8:
    case OPERAND_ATTR_S16:
    case OPERAND_ATTR_S32:
    case OPERAND_ATTR_S64:
    case OPERAND_ATTR_F16:
    case OPERAND_ATTR_F32:
    case OPERAND_ATTR_F64:
    case OPERAND_ATTR_SAMP:
    case OPERAND_ATTR_SIG32:
    case OPERAND_ATTR_SIG64:
    case OPERAND_ATTR_ITYPE:
    case OPERAND_ATTR_P2U:    return validateOperandType(inst, operandIdx, isDst, attr, isAssert);

    case OPERAND_ATTR_SEG:    return checkAddrSeg(inst, operandIdx, isAssert);
    case OPERAND_ATTR_TSEG:   return checkAddrTSeg(inst, operandIdx, isAssert);

    default:
        assert(false);
        return false;
    }
}

// 1) address size must match _instruction_ segment size;
// 2) if inst.segment=flat, address must be flat
// 3) addresses in arg and spill segments must include a symbol
// 4) if address includes a symbol, symbol.segment must be the same as instr.segment
bool PropValidator::checkAddrSeg(Inst inst, unsigned operandIdx, bool isAssert) const
{
    assert(inst);
    assert(operandIdx < MAX_OPERANDS_NUM);

    OperandAddress opr = inst.operand(operandIdx);
    assert(opr);

    if (getSegment(inst) == BRIG_SEGMENT_FLAT && opr.symbol())
    {
        if (isAssert) validate(inst, operandIdx, false, "Address segment does not match instruction segment (expected flat address)");
        return false;
    }

    if (opr.symbol() && opr.symbol().segment() != getSegment(inst))
    {
        if (isAssert) validate(inst, operandIdx, false, "Address segment does not match instruction segment");
        return false;
    }

    if (!opr.symbol() && !isAddressableSeg(getSegment(inst)))
    {
        if (isAssert) validate(inst, operandIdx, false, "Flat address cannot be used with arg and spill segments");
        return false;
    }

    unsigned addrSize = getAddrSize(opr, isLargeModel()); // 32 or 64; 0 if both are valid
    unsigned segAddrSize = getSegAddrSize(getSegment(inst), isLargeModel());
    if (addrSize != 0 && addrSize != segAddrSize)
    {
        if (isAssert) validate(inst, operandIdx, false, "Address size does not match segment size");
        return false;
    }

    if (segAddrSize == 32 && opr.offset().hi() != 0)
    {
        if (isAssert) validate(inst, operandIdx, false, "32-bit OperandAddress must have zero offset.hi");
        return false;
    }

    return true;
}

// 1+2+3+4
// 5) opaque symbols used in address must match instruction type
bool PropValidator::checkAddrTSeg(Inst inst, unsigned operandIdx, bool isAssert) const
{
    assert(inst);
    assert(operandIdx < MAX_OPERANDS_NUM);

    if (!checkAddrSeg(inst, operandIdx, isAssert)) return false;

    OperandAddress opr = inst.operand(operandIdx);
    assert(opr);

    if (!opr.symbol()) return true;

    unsigned type = inst.type();
    unsigned otype = opr.symbol().elementType();

    if (type == otype) return true;

    if (isOpaqueType(type))
    {
        if (isAssert) validate(inst, operandIdx, false, "Instruction type does not match address symbol type");
        return false;
    }

    if (isOpaqueType(otype))
    {
        if (isAssert) validate(inst, operandIdx, false, "Opaque symbol used in address does not match instruction type");
        return false;
    }

    return true;
}

bool PropValidator::isImm(Operand opr)
{
    if (OperandConstantBytes imm = opr)
    {
        unsigned sz = getImmSize(imm);
        if (0 < sz && sz <= 128) return true;
    }
    return false;
}

bool PropValidator::isImmInRange(Operand opr, unsigned low, unsigned high)
{
    if (OperandConstantBytes imm = opr)
    {
        if (getImmSize(imm) != 32) return false;

        unsigned val = getImmAsU32(imm);
        return low <= val && val <= high;
    }
    return false;
}

bool PropValidator::checkOperandKind(Inst inst, unsigned operandIdx, unsigned* vals, unsigned length, bool isAssert) const
{
    assert(inst);
    assert(operandIdx < MAX_OPERANDS_NUM);
    assert(vals && length > 0);

    Operand opr = inst.operand(operandIdx);

    for (unsigned i = 0; i < length; ++i)
    {
        switch(vals[i])
        {
        case OPERAND_VAL_NULL:      if (!opr) return true; break;

        case OPERAND_VAL_ADDR:      if (OperandAddress(opr))                                    return true; break;
        case OPERAND_VAL_LAB:       if (isCodeRef(opr, BRIG_KIND_DIRECTIVE_LABEL))              return true; break;
        case OPERAND_VAL_FUNC:      if (isCodeRef(opr, BRIG_KIND_DIRECTIVE_FUNCTION) ||
                                        isCodeRef(opr, BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION))  return true; break;
        case OPERAND_VAL_IFUNC:     if (isCodeRef(opr, BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION))  return true; break;
        case OPERAND_VAL_KERNEL:    if (isCodeRef(opr, BRIG_KIND_DIRECTIVE_KERNEL))             return true; break;
        case OPERAND_VAL_SIGNATURE: if (isCodeRef(opr, BRIG_KIND_DIRECTIVE_SIGNATURE))          return true; break;
        case OPERAND_VAL_FBARRIER:  if (isCodeRef(opr, BRIG_KIND_DIRECTIVE_FBARRIER))           return true; break;
        case OPERAND_VAL_ARGLIST:   if (isArgList(opr))                                         return true; break;
        case OPERAND_VAL_CALLTAB:   if (isCallTab(opr))                                         return true; break;
        case OPERAND_VAL_JUMPTAB:   if (isJumpTab(opr))                                         return true; break;

        case OPERAND_VAL_IMM:       if (isImm(opr) || OperandWavesize(opr))                     return true; break;
        case OPERAND_VAL_CNST:      if (isImm(opr))                                             return true; break;
        case OPERAND_VAL_IMM0T2:    if (isImmInRange(opr, 0, 2))                                return true; break;
        case OPERAND_VAL_IMM0T3:    if (isImmInRange(opr, 0, 3))                                return true; break;

        case OPERAND_VAL_REG:       if (OperandRegister(opr))                                   return true; break;
        case OPERAND_VAL_VEC_2:     if (isVector(opr, 2))                                       return true; break;
        case OPERAND_VAL_VEC_3:     if (isVector(opr, 3))                                       return true; break;
        case OPERAND_VAL_VEC_4:     if (isVector(opr, 4))                                       return true; break;

        default:
            assert(false);
            break;
        }
    }

    return false;
}

bool PropValidator::validateOperand(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert /*=true*/) const
{
    assert(inst);
    assert(vals && length > 0);
    assert(PROP_MINID < prop && prop < PROP_MAXID);
    assert(ATTR_MINID < attr && attr < ATTR_MAXID);

    bool isDst = (prop == PROP_D0 || prop == PROP_D1);
    unsigned oprIdx = getOperandIdx(prop);
    assert(oprIdx < MAX_OPERANDS_NUM);

    if (!checkOperandKind(inst, oprIdx, vals, length, isAssert))
    {
        if (isAssert) propError(inst, prop, "", vals, length); // FIXME: decode 'val'
        return false;
    }

    OperandOperandList vec = inst.operand(oprIdx);
    if (isDst && vec && !validateDstVector(inst, vec, oprIdx, isAssert)) return false;

    if (attr != OPERAND_ATTR_NONE)
    {
        return validateOperandAttr(inst, oprIdx, attr, isDst, isAssert);
    }
    return true;
}

bool PropValidator::validateEqclass(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert /*=true*/) const
{
    assert(prop == PROP_EQUIVCLASS);
    assert(attr == EQCLASS_ATTR_NONE);
    assert(length == 1);

    if (vals[0] == EQCLASS_VAL_ANY)
    {
        return true;
    }
    else if (vals[0] == EQCLASS_VAL_0)
    {
        if (getEqClass(inst) == 0) return true;
        if (isAssert)
        {
            ostringstream s;
            s << "Instruction has invalid equivClass " << getEqClass(inst) << ", expected: 0";
            validate(inst, false, s.str());
        }
        return false;
    }
    else
    {
        assert(false);
        return false;
    }
}

bool PropValidator::validateRound(Inst inst, unsigned prop, unsigned val, unsigned* vals, unsigned length, bool isAssert /*=true*/) const
{
    assert(prop == PROP_ROUND);
    assert(length > 0);

    return validateSpecialProp(inst, prop, val, vals, length, isAssert);
}

bool PropValidator::validateFtz(Inst inst, unsigned prop, unsigned val, unsigned* vals, unsigned length, bool isAssert /*=true*/) const
{
    assert(prop == PROP_FTZ);
    assert(val == 0 || val == 1);
    assert(length == 1 || length == 2);

    return validateSpecialProp(inst, prop, val, vals, length, isAssert);
}

bool PropValidator::validateSpecialProp(Inst inst, unsigned prop, unsigned val, unsigned* vals, unsigned length, bool isAssert /*=true*/) const
{
    assert(inst);

    const char* msg = validateProp(prop, val, vals, length, mModel, mProfile);
    if (msg)
    {
        if (isAssert) validate(inst, !msg, SRef(msg));
        return false;
    }

    for (unsigned i = 0; i < length; ++i)
    {
        if (vals[i] == val) return true;
    }

    if (isAssert) brigPropError(inst, prop, val, vals, length);
    return false;
}

void PropValidator::invalidVariant(Inst inst, unsigned prop) const
{
    validate(inst, false, "Instruction has invalid " + prop2str(prop));
}

void PropValidator::invalidVariant(Inst inst, unsigned prop1, unsigned prop2) const
{
    validate(inst, false, "Instruction has invalid combination of " + prop2str(prop1) + " and " + prop2str(prop2));
}

void PropValidator::invalidVariant(Inst inst, unsigned prop1, unsigned prop2, unsigned prop3) const
{
    validate(inst, false, "Instruction has invalid combination of " + prop2str(prop1) + " and " + prop2str(prop2) + " and " + prop2str(prop3));
}

//-----------------------------------------------------------------------------

static string getOperandTypeName(unsigned attr)
{
    switch(attr)
    {
    case OPERAND_ATTR_DTYPE:    return "operation";
    case OPERAND_ATTR_STYPE:    return "source";
    case OPERAND_ATTR_CTYPE:    return "coord";
    default:                    return ""; // operand has fixed type
    }
}

static string getExpectedTypeName(unsigned type)
{
    return "(" + string(type2name(type)) + ")";
}

string PropValidator::getErrHeader(unsigned oprIdx, const char* oprPref) const
{
    assert(oprIdx < MAX_OPERANDS_NUM);
    return string(oprPref) + " " + static_cast<char>('0' + oprIdx);
}

void PropValidator::operandError(Inst inst, unsigned oprIdx, string msg1, string msg2 /*=""*/) const
{
    assert(oprIdx < MAX_OPERANDS_NUM);

    string errHdr = getErrHeader(oprIdx, "Operand");
    validate(inst, oprIdx, false, errHdr + " " + msg1 + msg2);
}

void PropValidator::operandSizeError(Inst inst, unsigned oprIdx, unsigned type, unsigned attr) const
{
    assert(inst);
    assert(oprIdx < MAX_OPERANDS_NUM);

    string err = getOperandTypeName(attr);
    if (!err.empty()) // empty if operand has fixed type, otherwise "operation", "source", etc
    {
        operandError(inst, oprIdx, "size does not match ", err + ((attr == OPERAND_ATTR_DTYPE)? " size" : " type size"));
        return;
    }

    Operand opr = inst.operand(oprIdx);
    string errHdr = getErrHeader(oprIdx, "Invalid operand");

    string errMsg = "";
    if (OperandConstantBytes(opr) || OperandOperandList(opr))
    {
        switch(getBrigTypeNumBits(type))
        {
        case 1:   errMsg = "an 1-bit";  break;
        case 8:   errMsg = "a 8-bit";   break;
        case 16:  errMsg = "a 16-bit";  break;
        case 32:  errMsg = "a 32-bit";  break;
        case 64:  errMsg = "a 64-bit";  break;
        case 128: errMsg = "a 128-bit"; break;
        default:
            assert(false);
            break;
        }
        errMsg += OperandConstantBytes(opr)? " immediate" : " vector";
    }
    else if (OperandRegister(opr))
    {
        switch(getBrigTypeNumBits(type))
        {
        case 1:   errMsg = "a 'c' register";  break;
        case 32:  errMsg = "an 's' register"; break;
        case 64:  errMsg = "a 'd' register";  break;
        case 128: errMsg = "a 'q' register";  break;
        default:
            assert(false);
            break;
        }
    }
    else
    {
        assert(false);
    }

    validate(inst, oprIdx, false, errHdr + " size: expected " + errMsg);
}

//F1.0 print actual type
//F1.0 print only expected type in BRIG
void PropValidator::immTypeError(Inst inst, unsigned oprIdx, unsigned actualType, unsigned expectedType, bool isB1Error) const
{
    assert(inst);
    assert(oprIdx < MAX_OPERANDS_NUM);

    //F1.0
    //string brigType;
    //if (type != expectedType)
    //{
    //    brigType = string(" (") + type2str(expectedType) + " in BRIG)";
    //}

    if (isB1Error)
    {
        assert(OperandConstantBytes(inst.operand(oprIdx))); // cannot be a vector

        string errHdr = getErrHeader(oprIdx, "Invalid value of immediate operand");
        validate(inst, oprIdx, false, errHdr + ": expected 0 or 1");
    }
    else if (OperandOperandList(inst.operand(oprIdx)))
    {
        string errHdr = getErrHeader(oprIdx, "Vector operand");
        validate(inst, oprIdx, false, errHdr + " has invalid type of immediate value (" + type2name(actualType) + "); expected " + type2name(expectedType));
    }
    else
    {
        string errHdr = getErrHeader(oprIdx, "Invalid type of immediate operand");
        validate(inst, oprIdx, false, errHdr + " (" + type2name(actualType) + "); expected " + type2name(expectedType));
    }
}

void PropValidator::wavesizeError(Inst inst, unsigned oprIdx, unsigned type, unsigned attr) const
{
    assert(inst);
    assert(oprIdx < MAX_OPERANDS_NUM);

    Operand opr = inst.operand(oprIdx);

    assert(OperandWavesize(opr) || OperandOperandList(opr));

    string typeInfo = getOperandTypeName(attr); // empty if operand has fixed type, otherwise "operation", "source", etc
    typeInfo += typeInfo.empty()? ("expected operand type " + getExpectedTypeName(type)) : " type";
    string operandInfo = OperandWavesize(opr)? "cannot be" : "cannot include";
    operandError(inst, oprIdx, operandInfo + " wavesize: incompatible with ", typeInfo);
}

bool PropValidator::validateOperandVector(Inst inst, OperandOperandList opr, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert) const
{
    unsigned size = opr.elements().size();
    for (unsigned i = 0; i < size; ++i)
    {
        Operand elem = opr.elements()[i];

        if (OperandRegister x = elem)
        {
            if (!validateOperandReg(inst, x, oprIdx, type, attr, isAssert)) return false;
        }
        else if (OperandConstantBytes x = elem)
        {
            if (!validateOperandImmed(inst, x, oprIdx, type, attr, isAssert)) return false;
        }
        else if (OperandWavesize(elem))
        {
            if (!validateOperandWavesize(inst, oprIdx, type, attr, isAssert)) return false;
        }
        else
        {
            assert(false); // validated by 'isVector'
            return false;
        }
    }
    return true;
}

bool PropValidator::validateOperandReg(Inst inst, OperandRegister opr, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert) const
{
    assert(opr == inst.operand(oprIdx) || OperandOperandList(inst.operand(oprIdx)));

    unsigned iSize = getBrigTypeNumBits(type);
    bool isSubWord = (iSize == 8) || (iSize == 16);

    unsigned oSize = getRegBits(opr.regKind());
    if (iSize == oSize || (isSubWord && oSize == 32)) return true;
    if (isAssert) operandSizeError(inst, oprIdx, type, attr);
    return false;
}

bool PropValidator::validateOperandImmed(Inst inst, OperandConstantBytes opr, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert) const
{
    assert(opr == inst.operand(oprIdx) || OperandOperandList(inst.operand(oprIdx)));

    bool b1Error = (type == BRIG_TYPE_B1 && !isImmB1(opr));
    unsigned expectedType = isBitType(type)? bitType2uType(type) : type;

    if (expectedType == opr.type() && !b1Error) return true;
    if (isAssert) immTypeError(inst, oprIdx, opr.type(), expectedType, b1Error);
    return false;

    //F1.0 Make sure image and sampler initializers are not allowed as operands

    //F1.0
    ///unsigned iSize = getBrigTypeNumBits(type);
    ///unsigned oSize = getImmSize(opr);
    ///
    ///if (iSize == oSize) return true;
    ///if (iSize == 1 && oSize == 8)
    ///{
    ///    if (isImmB1(opr)) return true;
    ///    if (isAssert) operandSizeError(inst, oprIdx, type, attr);
    ///    return false;
    ///}
    ///if (isAssert) operandSizeError(inst, oprIdx, type, attr);
    ///return false;
}

bool PropValidator::validateOperandWavesize(Inst inst, unsigned oprIdx, unsigned type, unsigned attr, bool isAssert) const
{
    assert(OperandWavesize(inst.operand(oprIdx)) || OperandOperandList(inst.operand(oprIdx)));

    if (isIntType(type) && type != BRIG_TYPE_B128) return true;
    if (isAssert) wavesizeError(inst, oprIdx, type, attr);
    return false;
}

bool PropValidator::validateOperandType(Inst inst, unsigned oprIdx, bool isDst, unsigned attr, bool isAssert) const
{
    assert(inst);
    assert(oprIdx < MAX_OPERANDS_NUM);

    Operand opr   = inst.operand(oprIdx);
    unsigned type = attr2type(inst, attr);

    if (!opr)
    {
        if (isAssert) operandError(inst, oprIdx, "is missing");
        return false;
    }

    if (isDst && !OperandRegister(opr) && !OperandOperandList(opr))
    {
        if (isAssert) operandError(inst, oprIdx, "must be a register or a vector");
        return false;
    }

    if (OperandRegister(opr))
    {
        return validateOperandReg(inst, opr, oprIdx, type, attr, isAssert);
    }
    else if (OperandOperandList(opr))
    {
        return validateOperandVector(inst, opr, oprIdx, type, attr, isAssert);
    }
    else if (OperandConstantBytes(opr))
    {
        return validateOperandImmed(inst, opr, oprIdx, type, attr, isAssert);
    }
    else if (OperandWavesize(opr))
    {
        return validateOperandWavesize(inst, oprIdx, type, attr, isAssert);
    }
    else
    {
        return true; // nothing to check
    }
}

bool PropValidator::validateDstVector(Inst inst, OperandOperandList vector, unsigned oprIdx, bool isAssert) const
{
    assert(vector);
    unsigned size = vector.elements().size();
    assert(2 <= size && size <= 4);

    for (unsigned i = 0; i < size; ++i) // Check that all registers in destination vector are unique
    {
        if (OperandRegister ri = vector.elements()[i])
        {
            for (unsigned j = i + 1; j < size; ++j)
            {
                if (OperandRegister rj = vector.elements()[j])
                {
                    if (ri.regNum() == rj.regNum())
                    {
                        if (isAssert) validate(inst, oprIdx, false, "Destination vector operand must not include the same register more than once");
                        return false;
                    }
                }
            }
        }
        else
        {
            if (isAssert) validate(inst, oprIdx, false, "Destination vector operand must not include immediate values or wavesize");
            return false;
        }
    }
    return true;
}

bool PropValidator::validateAtomicTypeSize(Inst inst, bool isAssert) const
{
    assert(inst);

    // \todo 1.0p: temporarily removed restriction on 64-bit atomics in 32-bit mode
    // if (getBrigTypeNumBits(inst.type()) == 64 && !isLargeModel())
    // {
    //     if (isAssert) validate(inst, -1, false, "Instruction type size 64 is not allowed with small machine model");
    //     return false;
    // }
    return true;
}

bool PropValidator::validateInstTypeSize(Inst inst, unsigned type, const char* typeName, bool isAssert) const
{
    assert(inst);

    unsigned typeSize = getMachineSize();

    if (getBrigTypeNumBits(type) != typeSize)
    {
        if (isAssert) validate(inst, -1, false, string(typeName) + " size must match machine model");
        return false;
    }
    return true;
}

//============================================================================
// Operations with operands

unsigned PropValidator::operandAttr2Type(Inst inst, unsigned attr) const
{
    assert(inst);
    assert(ATTR_MINID < attr && attr < ATTR_MAXID); 

    using namespace HSAIL_PROPS;

    switch(attr)
    {
    case OPERAND_ATTR_INVALID:  return BRIG_TYPE_INVALID;
    case OPERAND_ATTR_NONE:     return BRIG_TYPE_NONE;

    case OPERAND_ATTR_SEG:
    case OPERAND_ATTR_TSEG:     return getSegAddrSize(getSegment(inst), mModel == BRIG_MACHINE_LARGE) == 32? BRIG_TYPE_U32 : BRIG_TYPE_U64;

    default:                    return PropValidator::attr2type(inst, attr);
    }
}

unsigned PropValidator::attr2DefWidth(Inst inst, unsigned attr) const
{
    assert(inst);
    assert(ATTR_MINID < attr && attr < ATTR_MAXID); 

    switch(attr)
    {
    case WIDTH_ATTR_NONE:       return BRIG_WIDTH_NONE;
    case WIDTH_ATTR_ALL:        return BRIG_WIDTH_ALL;
    case WIDTH_ATTR_WAVESIZE:   return BRIG_WIDTH_WAVESIZE;
    case WIDTH_ATTR_1:          return BRIG_WIDTH_1;

    // Instruction is either malformed or does not support 'width'
    // Should be assert'ed, but this would break generation of negative tests
    case WIDTH_ATTR_INVALID:    return BRIG_WIDTH_NONE;

    default:
        assert(false);
        return BRIG_WIDTH_NONE;
    }
}

unsigned PropValidator::attr2DefRounding(Inst inst, unsigned attr) const
{
    assert(inst);
    assert(ATTR_MINID < attr && attr < ATTR_MAXID); 

    switch(attr)
    {
    case ROUND_ATTR_NONE:       return BRIG_ROUND_NONE;
    case ROUND_ATTR_DEFAULT:    return BRIG_ROUND_FLOAT_DEFAULT;
    case ROUND_ATTR_ZERO:       return BRIG_ROUND_INTEGER_ZERO;

    // Instruction is either malformed or does not support 'rounding'
    // Should be assert'ed, but this would break generation of negative tests
    case ROUND_ATTR_INVALID:    return BRIG_ROUND_NONE;

    default:
        assert(false);
        return BRIG_WIDTH_NONE;
    }
}

const char* PropValidator::validateOperandDeps(Inst inst, unsigned attr) const
{
    assert(inst);
    assert(ATTR_MINID < attr && attr < ATTR_MAXID); 

    switch(attr)
    {
    case OPERAND_ATTR_NONE:     return 0; // Cannot report anything as there are optional operands //F Could it be improved?
    case OPERAND_ATTR_INVALID:  return 0; // Refrain reporting an error as validator will provide better explanation

    case OPERAND_ATTR_P2U:
    case OPERAND_ATTR_DTYPE:    if (!type2str(inst.type()))             return "Invalid instruction type";
                                if (inst.type() == BRIG_TYPE_NONE)      return "Missing instruction type";
                                break;

    case OPERAND_ATTR_STYPE:    if (!type2str(getSrcType(inst)))        return "Invalid source type";
                                if (getSrcType(inst) == BRIG_TYPE_NONE) return "Missing source type";
                                break;

    case OPERAND_ATTR_CTYPE:    if (!type2str(getCrdType(inst)))        return "Invalid coord type";
                                if (getCrdType(inst) == BRIG_TYPE_NONE) return "Missing coord type";
                                break;

    case OPERAND_ATTR_ITYPE:    if (!type2str(getImgType(inst)))        return "Invalid image type";
                                if (getImgType(inst) == BRIG_TYPE_NONE) return "Missing image type";
                                break;

    case OPERAND_ATTR_SEG:
    case OPERAND_ATTR_TSEG:     if (!segment2str(getSegment(inst)))          return "Invalid segment";
                                if (getSegment(inst) == BRIG_SEGMENT_NONE)   return "Missing segment";
                                break;

    default:
        break;
    }

    return 0;
}

//-----------------------------------------------------------------------------

} // namespace HSAIL_ASM
