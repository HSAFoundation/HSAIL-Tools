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
//===-- HSAILValidatorBase.cpp - HSAIL Validator Base------------------------------===//

#include "HSAILValidatorBase.h"
#include "HSAILItems.h"
#include "Brig.h"

#include <string.h>

using std::string;

// ============================================================================
// ============================================================================
//============================================================================
// Instruction Validator

namespace HSAIL_ASM {

//============================================================================

unsigned InstValidatorBase::machineType; // FIXME: changed to static for TestGen

//============================================================================

bool InstValidatorBase::isImage(Operand opr, bool isRW /*=false*/)
{
    OperandAddress addr = opr;
    return addr &&
           addr.symbol() &&
           DirectiveImage(addr.symbol()) &&
           (!isRW || DirectiveImage(addr.symbol()).type() == Brig::BRIG_TYPE_RWIMG);
}

bool InstValidatorBase::isSampler(Operand opr)
{
    OperandAddress addr = opr;
    return addr &&
           addr.symbol() &&
           DirectiveSampler(addr.symbol());
}

bool InstValidatorBase::isJumpTab(Inst inst, unsigned operandIdx, bool isAssert)
{
    assert(inst);
    assert(0 <= operandIdx && operandIdx <= 4);

    Operand opr = inst.operand(operandIdx);
    // NB: opr might be null!

    // NB: 'isAssert' and 'validate' should be used with great care!
    // - even it isAssert=true, this call is only a probe (there may be several variants for an operand)
    // - use 'validate' only if operand looks like a list of jump targets
    // - use 'validate' only to improve errors reporting

    using namespace Brig;

    if (OperandAddress addr = opr)
    {
        unsigned btype = isLargeModel()? BRIG_TYPE_B64 : BRIG_TYPE_B32;
        unsigned utype = isLargeModel()? BRIG_TYPE_U64 : BRIG_TYPE_U32;

        if (DirectiveSymbol sym = addr.symbol())
        {
            if (!sym.modifier().isArray())
            {
                if (isAssert) validate(inst, operandIdx, false, "Invalid descriprion of jump targets; expected an array of labels");
                return false;
            }
            if (sym.modifier().isDeclaration())
            {
                if (isAssert) validate(inst, operandIdx, false, "Invalid descriprion of jump targets; expected a reference to array definition");
                return false;
            }
            if (sym.dim() == 0 || sym.modifier().isFlexArray())
            {
                if (isAssert) validate(inst, operandIdx, false, "Invalid descriprion of jump targets; expected a non-empty array of labels");
                return false;
            }
            if (sym.type() != BRIG_TYPE_U64 && sym.type() != BRIG_TYPE_U32)
            {
                if (isAssert) validate(inst, operandIdx, false, "Array of labels must have type u32 or u64");
                return false;
            }
            if (sym.type() != utype)
            {
                if (isAssert) validate(inst, operandIdx, false, "Array type does not match machine model");
                return false;
            }

            DirectiveLabelList list = sym.init();
            if (!list)
            {
                if (isAssert) validate(inst, operandIdx, false, "Invalid descriprion of jump targets; expected an array initialized with labels");
                return false;
            }

            if (list.elementCount() == 0)
            {
                if (isAssert) validate(inst, operandIdx, false, "Invalid descriprion of jump targets; expected a non-empty array of labels");
                return false;
            }
        }

        if (addr.type() != btype)
        {
            if (isAssert) validate(inst, operandIdx, false, "Address type does not match machine model");
            return false;
        }

    }
    else if (OperandLabelRef labref = opr)
    {
        DirectiveLabelTargets list = labref.ref();

        if (!list)
        {
            if (isAssert) validate(inst, operandIdx, false, "Invalid reference to labeltargets statement");
            return false;
        }

        if (list.elementCount() == 0)
        {
            if (isAssert) validate(inst, operandIdx, false, "Invalid labeltargets statement; must include at least one label");
            return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}

bool InstValidatorBase::isCallTab(Inst inst, unsigned operandIdx, bool isAssert)
{
    assert(inst);
    assert(0 <= operandIdx && operandIdx <= 4);

    Operand opr = inst.operand(operandIdx);
    // opr might be null!

    // NB: 'isAssert' and 'validate' should be used with great care!
    // - even it isAssert=true, this call is only a probe (there may be several variants for an operand)
    // - use 'validate' only if operand looks like a list of call targets
    // - use 'validate' only to improve errors reporting

    using namespace Brig;

    if (OperandFunctionList list = opr)
    {
        if (list.elementCount() == 0) return false;
        //F
    }
    else if (OperandSignatureRef ref = opr)
    {
        DirectiveSignature signature = ref.ref();
        if (!signature) return false;
        //F
    }
    else
    {
        return false;
    }
    return true;
}

const char* InstValidatorBase::operand2str(unsigned valId)
{
    switch(valId)
    {
    case OPERAND_VAL_NULL:      return "null";

    case OPERAND_VAL_REG:       return "a register";
    case OPERAND_VAL_REG_V2:    return "a vector of 2 registers";
    case OPERAND_VAL_REG_V3:    return "a vector of 3 registers";
    case OPERAND_VAL_REG_V4:    return "a vector of 4 registers";

    // NB: wavesize may be rejected later by attr checks
    case OPERAND_VAL_IMM:       return "an immediate or wavesize";
    case OPERAND_VAL_LAB:       return "a label";
    case OPERAND_VAL_ADDR_SEG:  return "an address";
    case OPERAND_VAL_ADDR_TSEG: return "an address";
    case OPERAND_VAL_FUNC:      return "a function";
    case OPERAND_VAL_ARGLIST:   return "a list of arguments";
    case OPERAND_VAL_JUMPTAB:   return "a list of jump targets";
    case OPERAND_VAL_CALLTAB:   return "a list of call targets";
    case OPERAND_VAL_FBARRIER:  return "an fbarrier";

    case OPERAND_VAL_IMAGE:     return "an image";
    case OPERAND_VAL_IMAGE_RW:  return "a read-write image";
    case OPERAND_VAL_SAMPLER:   return "a sampler";

    case OPERAND_VAL_REG_1:     return "a 'c' register";
    case OPERAND_VAL_REG_32:    return "an 's' register";
    case OPERAND_VAL_REG_64:    return "a 'd' register";
    case OPERAND_VAL_REG_128:   return "a 'q' register";

    // NB: wavesize may be rejected later by attr checks
    case OPERAND_VAL_IMM_1:     return "an 1-bit immediate or wavesize";
    case OPERAND_VAL_IMM_32:    return "a 32-bit immediate or wavesize";
    case OPERAND_VAL_IMM_64:    return "a 64-bit immediate or wavesize";
    case OPERAND_VAL_IMM_128:   return "a 128-bit immediate or wavesize";

    case OPERAND_VAL_REG_V2_1:   return "a vector of 2 'c' registers";
    case OPERAND_VAL_REG_V2_32:  return "a vector of 2 's' registers";
    case OPERAND_VAL_REG_V2_64:  return "a vector of 2 'd' registers";
    case OPERAND_VAL_REG_V2_128: return "a vector of 2 'q' registers";

    case OPERAND_VAL_REG_V3_1:   return "a vector of 3 'c' registers";
    case OPERAND_VAL_REG_V3_32:  return "a vector of 3 's' registers";
    case OPERAND_VAL_REG_V3_64:  return "a vector of 3 'd' registers";
    case OPERAND_VAL_REG_V3_128: return "a vector of 3 'q' registers";

    case OPERAND_VAL_REG_V4_1:   return "a vector of 4 'c' registers";
    case OPERAND_VAL_REG_V4_32:  return "a vector of 4 's' registers";
    case OPERAND_VAL_REG_V4_64:  return "a vector of 4 'd' registers";
    case OPERAND_VAL_REG_V4_128: return "a vector of 4 'q' registers";

    default:
        assert(false);
        return "?";
    }
}

const char* InstValidatorBase::val2str(unsigned prop, unsigned val)
{
    const char* res = 0;

    using namespace Brig;
    switch(prop)
    {
    case PROP_TYPE:         res = typeX2str(val); break;
    case PROP_STYPE:        res = typeX2str(val); break;
    case PROP_ITYPE:        res = typeX2str(val); break;
    case PROP_CTYPE:        res = typeX2str(val); break;

    case PROP_OPERATOR:     res = compareOperation2str(val); break;
    case PROP_FTZ:          res = val? "ftz" : "none";           break;
    case PROP_ALIGN:        res = val? "ftz" : "none";           break;
    case PROP_ATMOP:        res = atomicOperation2str(val); break;
    case PROP_MSEM:         res = memorySemantic2str(val);  break;
    case PROP_GEOM:         res = imageGeometry2str(val);   break;
    case PROP_PACKING:      res = (val == BRIG_PACK_NONE)?    "no packing" : pack2str(val);   break;
    case PROP_ROUNDING:     res = (val == BRIG_ROUND_NONE)?   "none" : round2str(val);        break;
    case PROP_SYNC:         res = (val == BRIG_FENCE_NONE)?   "none" : memoryFence2str(val);  break;
    case PROP_SEGMENT:      res = (val == BRIG_SEGMENT_NONE)? "none" : segment2str(val);      break;
    case PROP_WIDTH:        res = (val == BRIG_WIDTH_NONE)?   "none" : width2str(val);        break;
    case PROP_EQCLASS:      res = "";  break; // no sense printing as any value would be valid

    case PROP_D0:
    case PROP_D1:

    case PROP_S0:
    case PROP_S1:
    case PROP_S2:
    case PROP_S3:
    case PROP_S4:           res = operand2str(val); break;

    case PROP_TYPESIZE:  // A special case
    case PROP_STYPESIZE: // A special case
    case PROP_OPERAND:
    default:
        assert(false);
        break;
    }

    assert(res);
    return res;
}

unsigned InstValidatorBase::getOperandIdx(unsigned prop)
{
    switch(prop)
    {
    case PROP_D0: return 0;
    case PROP_D1: return 1;

    case PROP_S0: return 0;
    case PROP_S1: return 1;
    case PROP_S2: return 2;
    case PROP_S3: return 3;
    case PROP_S4: return 4;

    default:
        return (unsigned)-1;
    }
}

string InstValidatorBase::prop2str(unsigned prop)
{
    switch(prop)
    {
    case PROP_TYPE:        return "type";
    case PROP_STYPE:       return "src type";
    case PROP_ITYPE:       return "image type";
    case PROP_CTYPE:       return "coord type";

    case PROP_PACKING:     return "packing";
    case PROP_OPERATOR:    return "comparison operator";
    case PROP_ROUNDING:    return "rounding";
    case PROP_FTZ:         return "modifier";
    case PROP_ALIGN:       return "aligned";
    case PROP_ATMOP:       return "atomic operation";
    case PROP_MSEM:        return "memory semantic";
    case PROP_GEOM:        return "geom";
    case PROP_SYNC:        return "sync flags";
    case PROP_SEGMENT:     return "storage class";
    case PROP_WIDTH:       return "width";
    case PROP_EQCLASS:     return "equivalence class";

    case PROP_D0:          return "operand 0";
    case PROP_D1:          return "operand 1";

    case PROP_S0:          return "operand 0";
    case PROP_S1:          return "operand 1";
    case PROP_S2:          return "operand 2";
    case PROP_S3:          return "operand 3";
    case PROP_S4:          return "operand 4";

    case PROP_TYPESIZE:  // A special case
    case PROP_STYPESIZE: // A special case
    case PROP_OPERAND:
    default:
        assert(false);
        return "";
    }
};

void InstValidatorBase::invalidFormat(Inst inst, const char* msg)
{
    validate(inst, false, "Invalid instruction format, expected " + string(msg));
}

void InstValidatorBase::brigPropError(Inst inst, unsigned prop, unsigned value, unsigned* vals, unsigned length)
{
    propError(inst, prop, val2str(prop, value), vals, length);
}

void InstValidatorBase::propError(Inst inst, unsigned prop, string value, unsigned* vals, unsigned length)
{
    assert(inst);
    assert(vals && length > 0);
    assert(PROP_MINID < prop && prop < PROP_MAXID);
    assert(prop != PROP_TYPESIZE && prop != PROP_STYPESIZE); // metaproperties are special

    string s = val2str(prop, vals[0]);
    for (unsigned i = 1; i < length; ++i) s = s + ", " + val2str(prop, vals[i]);

    unsigned operandIdx = getOperandIdx(prop);
    string expected = (length == 1)? ", expected: " : ", expected one of: ";
    if (operandIdx <= 4)
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
    else
    {
        if (value.length() > 0) value = " (" + value + ")";
        validate(inst, false, "Instruction has invalid " + prop2str(prop) + value + expected + s);
    }
}

bool InstValidatorBase::validateTypeSize(Inst inst, bool isSrcType, unsigned val, bool isAssert /*=true*/)
{
    assert(inst);

    unsigned type = isSrcType? getSrcType(inst) : inst.type();

    switch (val)
    {
    case TYPESIZE_VAL_SEG:
        if (getTypeSize(type) == getSegAddrSize(HSAIL_ASM::getSegment(inst), isLargeModel())) return true;
        if (isAssert) validate(inst, false, "Instruction type must match segment kind and machine model");
        break;

    case TYPESIZE_VAL_MODEL:
        return validateMachineType(inst, -1, getMachineType(), isSrcType, true, isAssert);

    default:
        assert(false);
        break;
    }
    return false;
}

bool InstValidatorBase::validateTypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert /*=true*/)
{
    assert(length == 1);
    assert(attr == TYPESIZE_ATTR_NONE);

    return validateTypeSize(inst, false, vals[0], isAssert);
}

bool InstValidatorBase::validateStypesize(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert /*=true*/)
{
    assert(length == 1);
    assert(attr == STYPESIZE_ATTR_NONE);

    return validateTypeSize(inst, true, vals[0], isAssert);
}

bool InstValidatorBase::validateOperandAttr(Inst inst, unsigned operandIdx, unsigned attr, bool isDst, bool isAssert)
{
    assert(inst);
    assert(operandIdx <= 4);
    assert(ATTR_MINID < attr && attr < ATTR_MAXID);
    assert(inst.operand(operandIdx));

    // This block is solely for optimization
    // These typical cases account for 30% of validation time
    //F
    //F if (attr == OPERAND_ATTR_EXP || attr == OPERAND_ATTR_NOEXP)
    //F {
    //F     if (OperandReg reg = inst.operand(operandIdx))
    //F     {
    //F         if (eqTypes(inst.type(), reg.type())) return true;
    //F     }
    //F     else if (OperandImmed imm = inst.operand(operandIdx))
    //F     {
    //F         // skip 'width' case
    //F         if (!isDst && operandIdx > 0 && eqTypes(inst.type(), imm.type())) return true;
    //F     }
    //F }

    if (attr == OPERAND_ATTR_MODEL)
    {
        return HSAIL_ASM::validateMachineType(inst, operandIdx, getMachineType(), false, false, isAssert);
    }

    // Default values
    bool enableIntExp   = false;
    bool enableFloatExp = false;
    bool instType       = true;

    switch (attr)
    {
    case OPERAND_ATTR_NOEXP:                                          break; // default
    case OPERAND_ATTR_STYPE:  instType = false;                       break;
    case OPERAND_ATTR_CTYPE:  instType = false;                       break;
    case OPERAND_ATTR_SEXP:   instType = false; enableIntExp = true;  break;
    case OPERAND_ATTR_EXP:                      enableIntExp = true;  break;
    default:
        assert(false);
        break;
    }

    if (isDst)
    {
        return validateDstOperand(inst, operandIdx, enableIntExp, enableFloatExp, isAssert);
    }
    else
    {
        return validateSrcOperand(inst, operandIdx, enableIntExp, enableFloatExp, instType, isAssert);
    }
}

// 1) address size must match _instruction_ segment size;
// 2) if inst.segment=flat, address must be flat
// 3) if address includes a symbol, symbol.segment must be the same as instr.segment
bool InstValidatorBase::checkAddrSeg(Inst inst, unsigned operandIdx, bool isAssert)
{
    assert(inst);
    assert(0 <= operandIdx && operandIdx <= 4);

    OperandAddress opr = inst.operand(operandIdx);
    assert(opr);

    if (HSAIL_ASM::getSegment(inst) == Brig::BRIG_SEGMENT_FLAT && opr.symbol())
    {
        if (isAssert) validate(inst, operandIdx, false, "Address segment does not match instruction segment (expected flat address)");
        return false;
    }
    if (opr.symbol() && opr.symbol().segment() != HSAIL_ASM::getSegment(inst))
    {
        if (isAssert) validate(inst, operandIdx, false, "Address segment does not match instruction segment");
        return false;
    }
    if (getTypeSize(opr.type()) != getSegAddrSize(HSAIL_ASM::getSegment(inst), isLargeModel()))
    {
        if (isAssert) validate(inst, operandIdx, false, "Address size does not match instruction type");
        return false;
    }

    return true;
}

// 4) opaque symbols used in address must match instruction type (rwimg, roimg, samp)
bool InstValidatorBase::checkAddrTSeg(Inst inst, unsigned operandIdx, bool isAssert)
{
    assert(inst);
    assert(0 <= operandIdx && operandIdx <= 4);

    OperandAddress opr = inst.operand(operandIdx);
    assert(opr);

    if (!checkAddrSeg(inst, opr, isAssert)) return false;

    using namespace Brig;
    unsigned type = inst.type();
    unsigned otype = opr.symbol()? opr.symbol().type().value() : BRIG_TYPE_NONE;

    if (type == otype) return true;

    if (type == BRIG_TYPE_SAMP  || type == BRIG_TYPE_RWIMG  || type == BRIG_TYPE_ROIMG ||
        otype == BRIG_TYPE_SAMP || otype == BRIG_TYPE_RWIMG || otype == BRIG_TYPE_ROIMG)
    {
        if (isAssert) validate(inst, operandIdx, false, "Opaque symbol used in address must match instruction type");
        return false;
    }

    return true;
}

bool InstValidatorBase::checkOperandKind(Inst inst, unsigned operandIdx, unsigned* vals, unsigned length, bool isAssert)
{
    assert(inst);
    assert(operandIdx <= 4);
    assert(vals && length > 0);

    Operand opr = inst.operand(operandIdx);
    unsigned kind = (unsigned)-1;
    unsigned size = 0;

    if (opr)
    {
        kind = opr.kind();
        unsigned type = getOperandType(opr);
        if (type != (unsigned)-1)
        {
            size = getTypeSize(type);
        }
    }

    for (unsigned i = 0; i < length; ++i)
    {
        switch(vals[i])
        {
        case OPERAND_VAL_NULL:      if (!opr) return true; break; //F get rid of breaks, return value immediately

        //NB: According with current design, explicitly specified operand size also assumes integer type => wavesize is allowed
        case OPERAND_VAL_IMM_1:     if ((kind == Brig::BRIG_OPERAND_WAVESIZE || kind == Brig::BRIG_OPERAND_IMMED) && size == 1)   return true; break;
        case OPERAND_VAL_IMM_32:    if ((kind == Brig::BRIG_OPERAND_WAVESIZE || kind == Brig::BRIG_OPERAND_IMMED) && size == 32)  return true; break;
        case OPERAND_VAL_IMM_64:    if ((kind == Brig::BRIG_OPERAND_WAVESIZE || kind == Brig::BRIG_OPERAND_IMMED) && size == 64)  return true; break;
        case OPERAND_VAL_IMM_128:   if ((kind == Brig::BRIG_OPERAND_WAVESIZE || kind == Brig::BRIG_OPERAND_IMMED) && size == 128) return true; break;

        case OPERAND_VAL_REG_1:     if (kind == Brig::BRIG_OPERAND_REG && size == 1)   return true; break;
        case OPERAND_VAL_REG_32:    if (kind == Brig::BRIG_OPERAND_REG && size == 32)  return true; break;
        case OPERAND_VAL_REG_64:    if (kind == Brig::BRIG_OPERAND_REG && size == 64)  return true; break;
        case OPERAND_VAL_REG_128:   if (kind == Brig::BRIG_OPERAND_REG && size == 128) return true; break;

        case OPERAND_VAL_REG_V2_1:   if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 2 && size == 1)   return true; break;
        case OPERAND_VAL_REG_V2_32:  if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 2 && size == 32)  return true; break;
        case OPERAND_VAL_REG_V2_64:  if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 2 && size == 64)  return true; break;
        case OPERAND_VAL_REG_V2_128: if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 2 && size == 128) return true; break;

        case OPERAND_VAL_REG_V3_1:   if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 3 && size == 1)   return true; break;
        case OPERAND_VAL_REG_V3_32:  if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 3 && size == 32)  return true; break;
        case OPERAND_VAL_REG_V3_64:  if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 3 && size == 64)  return true; break;
        case OPERAND_VAL_REG_V3_128: if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 3 && size == 128) return true; break;

        case OPERAND_VAL_REG_V4_1:   if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 4 && size == 1)   return true; break;
        case OPERAND_VAL_REG_V4_32:  if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 4 && size == 32)  return true; break;
        case OPERAND_VAL_REG_V4_64:  if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 4 && size == 64)  return true; break;
        case OPERAND_VAL_REG_V4_128: if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 4 && size == 128) return true; break;

        case OPERAND_VAL_ADDR_SEG:  if (kind == Brig::BRIG_OPERAND_ADDRESS && checkAddrSeg(inst, operandIdx, isAssert))                 return true; break;
        case OPERAND_VAL_ADDR_TSEG: if (kind == Brig::BRIG_OPERAND_ADDRESS && checkAddrTSeg(inst, operandIdx, isAssert))                return true; break;
        case OPERAND_VAL_LAB:       if (kind == Brig::BRIG_OPERAND_LABEL_REF && DirectiveLabel(OperandLabelRef(opr).ref()))             return true; break;
        case OPERAND_VAL_FUNC:      if (kind == Brig::BRIG_OPERAND_FUNCTION_REF)  return true; break;
        case OPERAND_VAL_ARGLIST:   if (kind == Brig::BRIG_OPERAND_ARGUMENT_LIST) return true; break;
        case OPERAND_VAL_JUMPTAB:   if (isJumpTab(inst, operandIdx, isAssert)) return true; break;
        case OPERAND_VAL_CALLTAB:   if (isCallTab(inst, operandIdx, isAssert)) return true; break;
        case OPERAND_VAL_FBARRIER:  if (kind == Brig::BRIG_OPERAND_FBARRIER_REF)  return true; break;

        case OPERAND_VAL_IMAGE:     if (isImage(opr, false)) return true; break;
        case OPERAND_VAL_IMAGE_RW:  if (isImage(opr, true))  return true; break;
        case OPERAND_VAL_SAMPLER:   if (isSampler(opr))      return true; break;

        case OPERAND_VAL_IMM:       if (kind == Brig::BRIG_OPERAND_IMMED ||
                                        kind == Brig::BRIG_OPERAND_WAVESIZE) return true; break;

        case OPERAND_VAL_REG:       if (kind == Brig::BRIG_OPERAND_REG)   return true; break;
        case OPERAND_VAL_REG_V2:    if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 2) return true; break;
        case OPERAND_VAL_REG_V3:    if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 3) return true; break;
        case OPERAND_VAL_REG_V4:    if (kind == Brig::BRIG_OPERAND_REG_VECTOR && OperandRegVector(opr).regCount() == 4) return true; break;

        default:
            assert(false);
            break;
        }
    }

    return false;
}

bool InstValidatorBase::validateOperand(Inst inst, unsigned prop, unsigned attr, unsigned* vals, unsigned length, bool isAssert /*=true*/)
{
    assert(inst);
    assert(vals && length > 0);
    assert(PROP_MINID < prop && prop < PROP_MAXID);
    assert(ATTR_MINID < attr && attr < ATTR_MAXID);

    bool isDst = (prop == PROP_D0 || prop == PROP_D1);
    unsigned operandIdx = getOperandIdx(prop);
    bool res = checkOperandKind(inst, operandIdx, vals, length, isAssert);

    if (!res)
    {
        if (isAssert) propError(inst, prop, "", vals, length); // FIXME: decode 'val'
        return res;
    }

    res = !isDst || validateDstVector(inst.operand(operandIdx));
    if (isAssert && !res) validate(inst, operandIdx, res, "Destination vector " + prop2str(prop) + " must not include the same register more than once");
    if (!res) return res;

    if (attr != OPERAND_ATTR_NONE)
    {
        return validateOperandAttr(inst, operandIdx, attr, isDst, isAssert);
    }
    return true;
}

void InstValidatorBase::invalidVariant(Inst inst, unsigned prop)
{
    validate(inst, false, "Instruction has invalid " + prop2str(prop));
}

void InstValidatorBase::invalidVariant(Inst inst, unsigned prop1, unsigned prop2)
{
    validate(inst, false, "Instruction has invalid combination of " + prop2str(prop1) + " and " + prop2str(prop2));
}

} // namespace HSAIL_ASM
