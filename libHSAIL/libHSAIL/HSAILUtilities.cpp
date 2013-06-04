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
#include "HSAILUtilities.h"
#include "HSAILItems.h"
#include "HSAILValidator.h"

#include <cassert>
#include <string>

namespace HSAIL_ASM {

std::ostream& operator<<(std::ostream& os, const SRef& s) {
    os.write(s.begin,s.length());
    return os;
}
size_t align(size_t s, size_t pow2)
{
    assert( (pow2 & (pow2-1))==0 );
    size_t const m = pow2-1;
    return (s + m) & ~m;
}

/// zero rightpadded copy. Copies min(len,room) elements from src to dst,
/// if len < room fills the gap with zeroes. returns min(len,room).
size_t zeroPaddedCopy(void *dst, const void* src, size_t len, size_t room)
{
    size_t const toCopy = std::min(len,room);
    memcpy(dst,src,toCopy);
    size_t const pad = room-toCopy;
    if (pad > 0) memset(reinterpret_cast<char*>(dst)+toCopy,0,pad);
    return toCopy;
}

unsigned getDefWidth(Inst inst)
{
    using namespace Brig;
    switch(inst.opcode())
    {
    case BRIG_OPCODE_LD:
    case BRIG_OPCODE_CBR:
        return BRIG_WIDTH_1;

    case BRIG_OPCODE_BARRIER:
        return BRIG_WIDTH_ALL;

    case BRIG_OPCODE_JOINFBAR:
    case BRIG_OPCODE_WAITFBAR:
    case BRIG_OPCODE_ARRIVEFBAR:
    case BRIG_OPCODE_LEAVEFBAR:
        return BRIG_WIDTH_WAVESIZE;

    case BRIG_OPCODE_ST:
    case BRIG_OPCODE_INITFBAR:
    case BRIG_OPCODE_RELEASEFBAR:
    case BRIG_OPCODE_SYNC:
        return BRIG_WIDTH_NONE;

    case BRIG_OPCODE_BRN:
    case BRIG_OPCODE_CALL:
        return (inst.operand(0) && inst.operand(0).kind() == BRIG_OPERAND_REG)? BRIG_WIDTH_1 : BRIG_WIDTH_ALL;

    default:
        //FIXME DP assert(false);
        return BRIG_WIDTH_NONE;
    }
}

unsigned getDefRounding(unsigned opCode, unsigned type)
{
    using namespace Brig;
    if (isFloatType(type) || isFloatPackedType(type))
    {
        switch(opCode)
        {
        case BRIG_OPCODE_ADD:
        case BRIG_OPCODE_DIV:
        case BRIG_OPCODE_FMA:
        case BRIG_OPCODE_MUL:
        case BRIG_OPCODE_SQRT:
        case BRIG_OPCODE_SUB:
            return BRIG_ROUND_FLOAT_NEAR_EVEN;

        default:
            break;
        }
    }
    return BRIG_ROUND_NONE;
}

unsigned getDefRoundingForCvt(unsigned srcType, unsigned dstType)
{
    using namespace Brig;
    if (isFloatType(srcType) && isFloatType(dstType) && getBitSize(srcType) > getBitSize(dstType))
    {
        return BRIG_ROUND_FLOAT_NEAR_EVEN;
    }
    else if (isIntType(srcType) && !isBitType(srcType) && isFloatType(dstType))
    {
        return BRIG_ROUND_FLOAT_NEAR_EVEN;
    }
    else if (isFloatType(srcType) && isIntType(dstType) && !isBitType(dstType))
    {
        return BRIG_ROUND_INTEGER_ZERO;
    }
    else
    {
        return BRIG_ROUND_NONE;
    }
}

bool isIntType(unsigned type)
{
    using namespace Brig;
    switch((Brig::BrigTypeX)type)
    {
    case BRIG_TYPE_B1:
    case BRIG_TYPE_B8:
    case BRIG_TYPE_B16:
    case BRIG_TYPE_B32:
    case BRIG_TYPE_B64:
    case BRIG_TYPE_B128:

    case BRIG_TYPE_S8:
    case BRIG_TYPE_S16:
    case BRIG_TYPE_S32:
    case BRIG_TYPE_S64:

    case BRIG_TYPE_U8:
    case BRIG_TYPE_U16:
    case BRIG_TYPE_U32:
    case BRIG_TYPE_U64:
        return true;

    default:
        return false;
    }
}

bool isBitType(unsigned type)
{
    using namespace Brig;
    switch((Brig::BrigTypeX)type)
    {
    case BRIG_TYPE_B1:
    case BRIG_TYPE_B8:
    case BRIG_TYPE_B16:
    case BRIG_TYPE_B32:
    case BRIG_TYPE_B64:
    case BRIG_TYPE_B128:
        return true;

    default:
        return false;
    }
}

bool isFloatType(unsigned type)
{
    using namespace Brig;
    return type == BRIG_TYPE_F16 || type == BRIG_TYPE_F32 || type == BRIG_TYPE_F64;
}

bool isPackedType(unsigned type)
{
    return isIntPackedType(type) || isFloatPackedType(type);
}

bool isIntPackedType(unsigned type)
{
    using namespace Brig;
    switch(type)
    {
    case BRIG_TYPE_U8X4:
    case BRIG_TYPE_S8X4:
    case BRIG_TYPE_U16X2:
    case BRIG_TYPE_S16X2:
    case BRIG_TYPE_U8X8:
    case BRIG_TYPE_S8X8:
    case BRIG_TYPE_U16X4:
    case BRIG_TYPE_S16X4:
    case BRIG_TYPE_U32X2:
    case BRIG_TYPE_S32X2:
    case BRIG_TYPE_U8X16:
    case BRIG_TYPE_S8X16:
    case BRIG_TYPE_U16X8:
    case BRIG_TYPE_S16X8:
    case BRIG_TYPE_U32X4:
    case BRIG_TYPE_S32X4:
    case BRIG_TYPE_U64X2:
    case BRIG_TYPE_S64X2:
        return true;

    default:
        return false;
    }
}

bool isFloatPackedType(unsigned type)
{
    using namespace Brig;
    switch(type)
    {
    case BRIG_TYPE_F16X2:
    case BRIG_TYPE_F16X4:
    case BRIG_TYPE_F32X2:
    case BRIG_TYPE_F16X8:
    case BRIG_TYPE_F32X4:
    case BRIG_TYPE_F64X2:
        return true;
    default:
        return false;
    }
}

unsigned convType2BitType(unsigned type)
{
    using namespace Brig;
    switch((Brig::BrigTypeX)type)
    {
    case BRIG_TYPE_B1:     return BRIG_TYPE_B1;
    case BRIG_TYPE_B8:     return BRIG_TYPE_B8;
    case BRIG_TYPE_B16:    return BRIG_TYPE_B16;
    case BRIG_TYPE_B32:    return BRIG_TYPE_B32;
    case BRIG_TYPE_B64:    return BRIG_TYPE_B64;
    case BRIG_TYPE_B128:   return BRIG_TYPE_B128;

    case BRIG_TYPE_S8:     return BRIG_TYPE_B8;
    case BRIG_TYPE_S16:    return BRIG_TYPE_B16;
    case BRIG_TYPE_S32:    return BRIG_TYPE_B32;
    case BRIG_TYPE_S64:    return BRIG_TYPE_B64;

    case BRIG_TYPE_U8:     return BRIG_TYPE_B8;
    case BRIG_TYPE_U16:    return BRIG_TYPE_B16;
    case BRIG_TYPE_U32:    return BRIG_TYPE_B32;
    case BRIG_TYPE_U64:    return BRIG_TYPE_B64;

    case BRIG_TYPE_F16:    return BRIG_TYPE_B16;
    case BRIG_TYPE_F32:    return BRIG_TYPE_B32;
    case BRIG_TYPE_F64:    return BRIG_TYPE_B64;

    case BRIG_TYPE_U8X4:   return BRIG_TYPE_B32;
    case BRIG_TYPE_S8X4:   return BRIG_TYPE_B32;
    case BRIG_TYPE_U16X2:  return BRIG_TYPE_B32;
    case BRIG_TYPE_S16X2:  return BRIG_TYPE_B32;
    case BRIG_TYPE_F16X2:  return BRIG_TYPE_B32;
    case BRIG_TYPE_U8X8:   return BRIG_TYPE_B64;
    case BRIG_TYPE_S8X8:   return BRIG_TYPE_B64;
    case BRIG_TYPE_U16X4:  return BRIG_TYPE_B64;
    case BRIG_TYPE_S16X4:  return BRIG_TYPE_B64;
    case BRIG_TYPE_F16X4:  return BRIG_TYPE_B64;
    case BRIG_TYPE_U32X2:  return BRIG_TYPE_B64;
    case BRIG_TYPE_S32X2:  return BRIG_TYPE_B64;
    case BRIG_TYPE_F32X2:  return BRIG_TYPE_B64;
    case BRIG_TYPE_U8X16:  return BRIG_TYPE_B128;
    case BRIG_TYPE_S8X16:  return BRIG_TYPE_B128;
    case BRIG_TYPE_U16X8:  return BRIG_TYPE_B128;
    case BRIG_TYPE_S16X8:  return BRIG_TYPE_B128;
    case BRIG_TYPE_F16X8:  return BRIG_TYPE_B128;
    case BRIG_TYPE_U32X4:  return BRIG_TYPE_B128;
    case BRIG_TYPE_S32X4:  return BRIG_TYPE_B128;
    case BRIG_TYPE_F32X4:  return BRIG_TYPE_B128;
    case BRIG_TYPE_U64X2:  return BRIG_TYPE_B128;
    case BRIG_TYPE_S64X2:  return BRIG_TYPE_B128;
    case BRIG_TYPE_F64X2:  return BRIG_TYPE_B128;

    default:
        assert(false);
        return BRIG_TYPE_SAMP;
    }
}

int getBitSize(unsigned type)
{
    unsigned const bType = convType2BitType(type);
    switch((Brig::BrigTypeX)bType) {
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B8:   return 8;
    case Brig::BRIG_TYPE_B16:  return 16;
    case Brig::BRIG_TYPE_B32:  return 32;
    case Brig::BRIG_TYPE_B64:  return 64;
    case Brig::BRIG_TYPE_B128: return 128;
    default: assert(false);
    }
    return 0;
}

unsigned getTypeSize(unsigned t)
{
    int result = HSAIL_ASM::brigtype_get_length(t);

    if (result)
    {
        return result;
    }
    else
    {
        switch(t)
        {
        case Brig::BRIG_TYPE_ROIMG:
        case Brig::BRIG_TYPE_RWIMG:
        case Brig::BRIG_TYPE_SAMP:
            return 64;

        default:
            assert(false);
            return 0;
        }
    }
}

unsigned getSegAddrSize(unsigned segment, bool isLargeModel)
{
    switch (segment)
    {
    case Brig::BRIG_SEGMENT_FLAT:
    case Brig::BRIG_SEGMENT_GLOBAL:
    case Brig::BRIG_SEGMENT_READONLY:
    case Brig::BRIG_SEGMENT_KERNARG:
        return isLargeModel? 64 : 32;

    default:
        return 32;
    }
}

unsigned getSegment(Inst inst)
{
    assert(inst);
    if      (InstAddr   i = inst) return i.segment();
    else if (InstMem    i = inst) return i.segment();
    else if (InstSeg    i = inst) return i.segment();
    else if (InstAtomic i = inst) return i.segment();
    else                          return Brig::BRIG_SEGMENT_NONE;
}

// This function provides no information if operandIdx may be an immediate.
// It only specifies the type of immediate assuming that it is a valid operand.
// No information about hidden 'width' operands are provided as well.
// No information is provided for "width" operand as it has special encoding/decoding rules
unsigned getImmOperandType(Inst inst, unsigned operandIdx, unsigned machineType)
{

    using namespace Brig;

    switch (inst.opcode()) {
    case BRIG_OPCODE_CVT:
        if (operandIdx == 1) return ((InstCvt)inst).sourceType();
        break;

    case BRIG_OPCODE_CMP:
        if (operandIdx == 1 || operandIdx == 2) return InstCmp(inst).sourceType();
        break;

    case BRIG_OPCODE_POPCOUNT:
    case BRIG_OPCODE_FIRSTBIT:
    case BRIG_OPCODE_LASTBIT:
    case BRIG_OPCODE_EXPAND:
        if (operandIdx == 1) return InstSourceType(inst).sourceType();
        break;

    case BRIG_OPCODE_CLASS:
        if (operandIdx == 1) return InstSourceType(inst).sourceType();
        if (operandIdx == 2) return BRIG_TYPE_U32;
        break;

        break;

    case BRIG_OPCODE_PACK:
        if (operandIdx == 2) return InstSourceType(inst).sourceType();
        if (operandIdx == 3) return Brig::BRIG_TYPE_B32;
        break;

    case BRIG_OPCODE_UNPACK:
        if (operandIdx == 1) return InstSourceType(inst).sourceType();
        if (operandIdx == 2) return Brig::BRIG_TYPE_U32;
        break;

    case BRIG_OPCODE_SAD:
    case BRIG_OPCODE_SADHI:
        if (operandIdx == 1 || operandIdx == 2) return InstSourceType(inst).sourceType();
        if (operandIdx == 3) return Brig::BRIG_TYPE_U32;
        break;

    case BRIG_OPCODE_PACKCVT:
        if (operandIdx >= 1) return InstSourceType(inst).sourceType();
        break;

    case BRIG_OPCODE_UNPACKCVT:
        if (operandIdx == 1) return InstSourceType(inst).sourceType();
        if (operandIdx == 2) return Brig::BRIG_TYPE_U32;
        break;

    case BRIG_OPCODE_BITMASK:
        if (operandIdx == 1 || operandIdx == 2) return BRIG_TYPE_U32;
        break;

    case BRIG_OPCODE_BITEXTRACT:
        if (operandIdx == 2 || operandIdx == 3) return BRIG_TYPE_U32;
        break;

    case BRIG_OPCODE_BITINSERT:
        if (operandIdx == 3 || operandIdx == 4) return BRIG_TYPE_U32;
        break;

    case BRIG_OPCODE_SHL:
    case BRIG_OPCODE_SHR:
        if (operandIdx == 2) return BRIG_TYPE_U32;
        break;

    case BRIG_OPCODE_CMOV:
        if (operandIdx == 1 && !isPackedType(inst.type())) return BRIG_TYPE_B1;
        break;

    case BRIG_OPCODE_SEGMENTP:
    case BRIG_OPCODE_FTOS:
    case BRIG_OPCODE_STOF:
        if (operandIdx == 1) return InstSeg(inst).sourceType();
        break;

    case BRIG_OPCODE_MASKLANE:
    case BRIG_OPCODE_COUNTLANE:
        if (operandIdx == 1) return BRIG_TYPE_B32;
        break;

    case BRIG_OPCODE_SENDLANE:
    case BRIG_OPCODE_RECEIVELANE:
        if (operandIdx == 1 || operandIdx == 2) return BRIG_TYPE_B32;
        break;

    case BRIG_OPCODE_ALLOCA:
        if (operandIdx == 1) return BRIG_TYPE_B32;
        break;

    case BRIG_OPCODE_CURRENTWORKGROUPSIZE:
    case BRIG_OPCODE_GRIDGROUPS:
    case BRIG_OPCODE_GRIDSIZE:
    case BRIG_OPCODE_WORKITEMID:
    case BRIG_OPCODE_WORKITEMABSID:
    case BRIG_OPCODE_WORKGROUPID:
    case BRIG_OPCODE_WORKGROUPSIZE:
        if (operandIdx == 1) return BRIG_TYPE_U32;
        break;

    case BRIG_OPCODE_DEBUGTRAP:
        if (operandIdx == 0) return BRIG_TYPE_U32;
        break;

    // ==================
    // GCN INSTRUCTIONS
    // ==================

    case BRIG_OPCODE_GCNMADU:
        if (operandIdx == 3) return BRIG_TYPE_U64;
        break;

    case BRIG_OPCODE_GCNMADS:
        if (operandIdx == 3) return BRIG_TYPE_S64;
        break;

    case BRIG_OPCODE_GCNFLDEXP:
        if (operandIdx == 2) return BRIG_TYPE_S32;
        break;

    case BRIG_OPCODE_GCNTRIG_PREOP:
        if (operandIdx == 2) return BRIG_TYPE_U32;
        break;

    case BRIG_OPCODE_GCNMQSAD:
        if (operandIdx == 2) return BRIG_TYPE_B32;
        break;

    case BRIG_OPCODE_GCNMQSAD4:
        if (operandIdx == 1) return BRIG_TYPE_B64;
        break;

    default:
        break;
    }

    if (isa<InstSourceType>(inst) && operandIdx>0) {
        return InstSourceType(inst).sourceType();
    }

    return inst.type();
}

unsigned getOperandType(Operand opr)
{
    assert(opr);

    switch (opr.brig()->kind)
    {
    case Brig::BRIG_OPERAND_ADDRESS:      return OperandAddress(opr).type();
    case Brig::BRIG_OPERAND_REG:          return OperandReg(opr).type();
    case Brig::BRIG_OPERAND_REG_VECTOR:   return OperandRegVector(opr).type();
    case Brig::BRIG_OPERAND_IMMED:        return OperandImmed(opr).type();
    case Brig::BRIG_OPERAND_WAVESIZE:     return OperandWavesize(opr).type();
    default:
        return (unsigned)-1;
    }
}

unsigned getOperandType(Operand opr, bool isLargeModel)
{
    assert(opr);

    switch (opr.brig()->kind)
    {
    case Brig::BRIG_OPERAND_LABEL_REF:
    case Brig::BRIG_OPERAND_FUNCTION_REF:
        return isLargeModel? Brig::BRIG_TYPE_B64 : Brig::BRIG_TYPE_B32;

    default:
        return getOperandType(opr);
    }
}

static void operandError(Inst inst, int oprIdx, const char* msg1, const char* msg2 = "")
{
    std::string errHdr = (oprIdx == -1)? "Instruction" : (std::string("Operand ") + (char)('0' + oprIdx)); //F FIXME: use table of operand names (see all places)

    Validator::validate(inst, oprIdx, errHdr + " " + msg1 + msg2, false);
}

bool validateSrcOperand(Inst inst, int oprIdx, bool enableIntExp, bool enableFloatExp, bool instType, bool isAssert) // FIXME: optimize for TestGen
{
    Operand opr = inst.operand(oprIdx);

    if (!opr)
    {
        if (isAssert) operandError(inst, oprIdx, "is missing");
        return false;
    }

    unsigned type = instType? getType(inst) : getSrcType(inst); //F get rid of getSrcType if possible
    const char* sizeName = instType? "operation size" : "source type size";
    if (InstImage(inst) || InstAtomicImage(inst)) sizeName = "coord type size";

    if (OperandWavesize(opr) && !isIntType(type))
    {
        if (isAssert) operandError(inst, oprIdx, "cannot be wavesize: incompatible with ", instType? "operation type" : "source type");
        return false;
    }

    int iSize = getTypeSize(type);
    bool isSubWord = (iSize == 8) || (iSize == 16);
    bool isInteger = isIntType(type) && (!isBitType(type) || type == Brig::BRIG_TYPE_B1);
    bool isFloat   = isFloatType(type);

    unsigned oType = getOperandType(opr);
    if (oType == (unsigned)-1) return true; // nothing to check

    int oSize = getTypeSize(oType);

    switch(opr.brig()->kind)
    {
    case Brig::BRIG_OPERAND_REG:
    case Brig::BRIG_OPERAND_REG_VECTOR:

        if (oSize == iSize || (isSubWord && oSize == 32))
        {
            return true;
        }
        else if ((isInteger && enableIntExp) || (isFloat && enableFloatExp))
        {
            if (oSize <= iSize)
            {
                if (isAssert) operandError(inst, oprIdx, "size does not match ", sizeName);
                return false;
            }

            if (oSize >= 128)
            {
                if (isAssert) operandError(inst, oprIdx, "size does not match ", sizeName);
                return false;
            }
            return true;
        }
        else
        {
            if (isAssert) operandError(inst, oprIdx, "size does not match ", sizeName);
            return false;
        }

    case Brig::BRIG_OPERAND_WAVESIZE:
    case Brig::BRIG_OPERAND_IMMED:

        if (oSize != iSize)
        {
            if (isAssert) operandError(inst, oprIdx, "size does not match ", sizeName);
            return false;
        }
        return true;

    default:
        return true; // nothing to check
    }
}

bool validateDstVector(OperandRegVector vector)
{
    if (!vector) return true;

    assert(2 <= vector.regCount() && vector.regCount() <= 4);

    // Check that all registers in destination vector are unique
    for (int i = 0, c = vector.regCount(); i < c; ++i)
    {
        SRef name1 = vector.regs(i);
        for (int j = i + 1; j < c; ++j)
        {
            SRef name2 = vector.regs(j);
            if (name1 == name2) return false; // TODO: replace with offset check
        }
    }
    return true;
}

bool validateDstOperand(Inst inst, int oprIdx, bool enableIntExp, bool enableFloatExp, bool isAssert) // FIXME: optimize for TestGen
{
    Operand opr = inst.operand(oprIdx);

    if (!opr)
    {
        if (isAssert) operandError(inst, oprIdx, "is missing");
        return false;
    }

    unsigned type = getType(inst);
    int iSize = getTypeSize(type);
    bool isSubWord = (iSize == 8) || (iSize == 16);
    bool isInteger = isIntType(type) && (!isBitType(type) || type == Brig::BRIG_TYPE_B1);
    bool isFloat   = isFloatType(type);

    unsigned oType = getOperandType(opr);
    if (oType == (unsigned)-1) return true; // nothing to check

    int oSize = getTypeSize(oType);

    switch(opr.brig()->kind)
    {
    case Brig::BRIG_OPERAND_REG:
    case Brig::BRIG_OPERAND_REG_VECTOR:
        break;

    default:
        if (isAssert) operandError(inst, oprIdx, "must be a register or a vector");
        return false;
    }

    if (oSize == iSize || (isSubWord && oSize == 32)) return true;

    if (oSize <= iSize)
    {
        if (isAssert) operandError(inst, oprIdx, "size does not match operation size");
        return false;
    }
    if (oSize >= 128)
    {
        if (isAssert) operandError(inst, oprIdx, "size does not match operation size");
        return false;
    }
    if (!(isInteger && enableIntExp) && !(isFloat && enableFloatExp))
    {
        if (isAssert) operandError(inst, oprIdx, "size does not match operation size");
        return false;
    }

    return true;
}

bool validateMachineType(Inst inst, int oprIdx, unsigned machineType, bool isSrcType, bool isUnsigned, bool isAssert)
{
    const char* errInfo;
    const char* reason;

    unsigned type = machineType;
    if (machineType == Brig::BRIG_TYPE_B32)  // FIXME: optimize for TestGen
    {
        reason = " when used with small model";
        errInfo = isUnsigned? "must have u32 type" : "must have b32 type";
        if (isUnsigned) type = Brig::BRIG_TYPE_U32;
    }
    else
    {
        reason = " when used with large model";
        errInfo = isUnsigned? "must have u64 type" : "must have b64 type";
        if (isUnsigned) type = Brig::BRIG_TYPE_U64;
    }

    if (oprIdx == -1)
    {
        if ((!isSrcType && inst.type() != type) || (isSrcType && getSrcType(inst) != type))
        {
            if (isAssert)
            {
                Validator::validate(inst, -1, std::string(isSrcType? "Src" : "Instruction") + " type must be " + typeX2str(type) + reason, false);
            }
            return false;
        }
    }
    else
    {
        Operand opr = inst.operand(oprIdx);
        if (!opr)
        {
            if (isAssert) operandError(inst, oprIdx, " is missing");
            return false;
        }

        if (getOperandType(opr, machineType == Brig::BRIG_TYPE_B64) != type)
        {
            if (isAssert) operandError(inst, oprIdx, errInfo, reason);
            return false;
        }
    }

    return true;
}

unsigned getType(Inst i)
{
    return i.brig()->type;
}

unsigned getSrcType(Inst i)
{
    switch(i.brig()->kind)
    {
    case Brig::BRIG_INST_CVT:
        return InstCvt(i).sourceType();

    case Brig::BRIG_INST_CMP:
        return InstCmp(i).sourceType();

    case Brig::BRIG_INST_SEG:
        return InstSeg(i).sourceType();

    case Brig::BRIG_INST_SOURCE_TYPE:
        return InstSourceType(i).sourceType();

    case Brig::BRIG_INST_IMAGE:
        return InstImage(i).coordType();

    case Brig::BRIG_INST_ATOMIC_IMAGE:
        return InstAtomicImage(i).coordType();

    default:
        return (unsigned)-1;
    }
}

const char* width2str(unsigned val)
{
    using namespace Brig;

    switch(val)
    {
    case BRIG_WIDTH_1                   : return "width(1)";
    case BRIG_WIDTH_1024                : return "width(1024)";
    case BRIG_WIDTH_1048576             : return "width(1048576)";
    case BRIG_WIDTH_1073741824          : return "width(1073741824)";
    case BRIG_WIDTH_128                 : return "width(128)";
    case BRIG_WIDTH_131072              : return "width(131072)";
    case BRIG_WIDTH_134217728           : return "width(134217728)";
    case BRIG_WIDTH_16                  : return "width(16)";
    case BRIG_WIDTH_16384               : return "width(16384)";
    case BRIG_WIDTH_16777216            : return "width(16777216)";
    case BRIG_WIDTH_2                   : return "width(2)";
    case BRIG_WIDTH_2048                : return "width(2048)";
    case BRIG_WIDTH_2097152             : return "width(2097152)";
    case BRIG_WIDTH_2147483648          : return "width(2147483648)";
    case BRIG_WIDTH_256                 : return "width(256)";
    case BRIG_WIDTH_262144              : return "width(262144)";
    case BRIG_WIDTH_268435456           : return "width(268435456)";
    case BRIG_WIDTH_32                  : return "width(32)";
    case BRIG_WIDTH_32768               : return "width(32768)";
    case BRIG_WIDTH_33554432            : return "width(33554432)";
    case BRIG_WIDTH_4                   : return "width(4)";
    case BRIG_WIDTH_4096                : return "width(4096)";
    case BRIG_WIDTH_4194304             : return "width(4194304)";
    case BRIG_WIDTH_512                 : return "width(512)";
    case BRIG_WIDTH_524288              : return "width(524288)";
    case BRIG_WIDTH_536870912           : return "width(536870912)";
    case BRIG_WIDTH_64                  : return "width(64)";
    case BRIG_WIDTH_65536               : return "width(65536)";
    case BRIG_WIDTH_67108864            : return "width(67108864)";
    case BRIG_WIDTH_8                   : return "width(8)";
    case BRIG_WIDTH_8192                : return "width(8192)";
    case BRIG_WIDTH_8388608             : return "width(8388608)";
    case BRIG_WIDTH_ALL                 : return "width(all)";
    case BRIG_WIDTH_WAVESIZE            : return "width(WAVESIZE)";
    case BRIG_WIDTH_NONE                : return "";
    default:
        return NULL;
    }
}

} // end namespace

