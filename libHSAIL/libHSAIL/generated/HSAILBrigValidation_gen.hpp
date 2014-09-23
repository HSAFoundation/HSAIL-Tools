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


bool ValidatorImpl::ValidateBrigDirectiveFields(Directive item) const
{
    using namespace Brig;

    unsigned kind = item.kind();

    switch (kind)
    {
       case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END:
       {
           DirectiveArgBlockEnd it = item;

       }
       break;

       case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START:
       {
           DirectiveArgBlockStart it = item;

       }
       break;

       case BRIG_KIND_DIRECTIVE_COMMENT:
       {
           DirectiveComment it = item;

           validate_BrigDataOffsetString(item, it.brig()->name, "DirectiveComment", "name");
       }
       break;

       case BRIG_KIND_DIRECTIVE_CONTROL:
       {
           DirectiveControl it = item;

           validate_BrigControlDirective(item, it.brig()->control, "DirectiveControl", "control");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveControl", "reserved");
           validate_BrigDataOffsetOperandList(item, it.brig()->operands, "DirectiveControl", "operands");
       }
       break;

       case BRIG_KIND_DIRECTIVE_FUNCTION:
       {
           DirectiveFunction it = item;

           validate_BrigDataOffsetString(item, it.brig()->name, "DirectiveFunction", "name");
           validate_fld_OutArgCount(item, it.brig()->outArgCount, "DirectiveFunction", "outArgCount");
           validate_fld_InArgCount(item, it.brig()->inArgCount, "DirectiveFunction", "inArgCount");
           validate_BrigCodeOffset(item, it.brig()->firstInArg, "DirectiveFunction", "firstInArg");
           validate_BrigCodeOffset(item, it.brig()->firstCodeBlockEntry, "DirectiveFunction", "firstCodeBlockEntry");
           validate_BrigCodeOffset(item, it.brig()->nextModuleEntry, "DirectiveFunction", "nextModuleEntry");
           validate_fld_CodeBlockEntryCount(item, it.brig()->codeBlockEntryCount, "DirectiveFunction", "codeBlockEntryCount");
           validate_BrigExecutableModifier(item, it.brig()->modifier, "DirectiveFunction", "modifier");
           validate_BrigLinkage(item, it.brig()->linkage, "DirectiveFunction", "linkage");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveFunction", "reserved");
       }
       break;

       case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION:
       {
           DirectiveIndirectFunction it = item;

           validate_BrigDataOffsetString(item, it.brig()->name, "DirectiveIndirectFunction", "name");
           validate_fld_OutArgCount(item, it.brig()->outArgCount, "DirectiveIndirectFunction", "outArgCount");
           validate_fld_InArgCount(item, it.brig()->inArgCount, "DirectiveIndirectFunction", "inArgCount");
           validate_BrigCodeOffset(item, it.brig()->firstInArg, "DirectiveIndirectFunction", "firstInArg");
           validate_BrigCodeOffset(item, it.brig()->firstCodeBlockEntry, "DirectiveIndirectFunction", "firstCodeBlockEntry");
           validate_BrigCodeOffset(item, it.brig()->nextModuleEntry, "DirectiveIndirectFunction", "nextModuleEntry");
           validate_fld_CodeBlockEntryCount(item, it.brig()->codeBlockEntryCount, "DirectiveIndirectFunction", "codeBlockEntryCount");
           validate_BrigExecutableModifier(item, it.brig()->modifier, "DirectiveIndirectFunction", "modifier");
           validate_BrigLinkage(item, it.brig()->linkage, "DirectiveIndirectFunction", "linkage");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveIndirectFunction", "reserved");
       }
       break;

       case BRIG_KIND_DIRECTIVE_KERNEL:
       {
           DirectiveKernel it = item;

           validate_BrigDataOffsetString(item, it.brig()->name, "DirectiveKernel", "name");
           validate_fld_OutArgCount(item, it.brig()->outArgCount, "DirectiveKernel", "outArgCount");
           validate_fld_InArgCount(item, it.brig()->inArgCount, "DirectiveKernel", "inArgCount");
           validate_BrigCodeOffset(item, it.brig()->firstInArg, "DirectiveKernel", "firstInArg");
           validate_BrigCodeOffset(item, it.brig()->firstCodeBlockEntry, "DirectiveKernel", "firstCodeBlockEntry");
           validate_BrigCodeOffset(item, it.brig()->nextModuleEntry, "DirectiveKernel", "nextModuleEntry");
           validate_fld_CodeBlockEntryCount(item, it.brig()->codeBlockEntryCount, "DirectiveKernel", "codeBlockEntryCount");
           validate_BrigExecutableModifier(item, it.brig()->modifier, "DirectiveKernel", "modifier");
           validate_BrigLinkage(item, it.brig()->linkage, "DirectiveKernel", "linkage");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveKernel", "reserved");
       }
       break;

       case BRIG_KIND_DIRECTIVE_SIGNATURE:
       {
           DirectiveSignature it = item;

           validate_BrigDataOffsetString(item, it.brig()->name, "DirectiveSignature", "name");
           validate_fld_OutArgCount(item, it.brig()->outArgCount, "DirectiveSignature", "outArgCount");
           validate_fld_InArgCount(item, it.brig()->inArgCount, "DirectiveSignature", "inArgCount");
           validate_BrigCodeOffset(item, it.brig()->firstInArg, "DirectiveSignature", "firstInArg");
           validate_BrigCodeOffset(item, it.brig()->firstCodeBlockEntry, "DirectiveSignature", "firstCodeBlockEntry");
           validate_BrigCodeOffset(item, it.brig()->nextModuleEntry, "DirectiveSignature", "nextModuleEntry");
           validate_fld_CodeBlockEntryCount(item, it.brig()->codeBlockEntryCount, "DirectiveSignature", "codeBlockEntryCount");
           validate_BrigExecutableModifier(item, it.brig()->modifier, "DirectiveSignature", "modifier");
           validate_BrigLinkage(item, it.brig()->linkage, "DirectiveSignature", "linkage");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveSignature", "reserved");
       }
       break;

       case BRIG_KIND_DIRECTIVE_EXTENSION:
       {
           DirectiveExtension it = item;

           validate_BrigDataOffsetString(item, it.brig()->name, "DirectiveExtension", "name");
       }
       break;

       case BRIG_KIND_DIRECTIVE_FBARRIER:
       {
           DirectiveFbarrier it = item;

           validate_BrigDataOffsetString(item, it.brig()->name, "DirectiveFbarrier", "name");
           validate_BrigExecutableModifier(item, it.brig()->modifier, "DirectiveFbarrier", "modifier");
           validate_BrigLinkage(item, it.brig()->linkage, "DirectiveFbarrier", "linkage");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveFbarrier", "reserved");
       }
       break;

       case BRIG_KIND_DIRECTIVE_LABEL:
       {
           DirectiveLabel it = item;

           validate_BrigDataOffsetString(item, it.brig()->name, "DirectiveLabel", "name");
       }
       break;

       case BRIG_KIND_DIRECTIVE_LOC:
       {
           DirectiveLoc it = item;

           validate_BrigDataOffsetString(item, it.brig()->filename, "DirectiveLoc", "filename");
           validate_fld_Line(item, it.brig()->line, "DirectiveLoc", "line");
           validate_fld_Column(item, it.brig()->column, "DirectiveLoc", "column");
       }
       break;

       case BRIG_KIND_NONE:
       {
           DirectiveNone it = item;

       }
       break;

       case BRIG_KIND_DIRECTIVE_PRAGMA:
       {
           DirectivePragma it = item;

           validate_BrigDataOffsetOperandList(item, it.brig()->operands, "DirectivePragma", "operands");
       }
       break;

       case BRIG_KIND_DIRECTIVE_VARIABLE:
       {
           DirectiveVariable it = item;

           validate_BrigDataOffsetString(item, it.brig()->name, "DirectiveVariable", "name");
           validate_BrigOperandOffset(item, it.brig()->init, "DirectiveVariable", "init");
           validate_BrigType(item, it.brig()->type, "DirectiveVariable", "type");
           validate_BrigSegment(item, it.brig()->segment, "DirectiveVariable", "segment");
           validate_BrigAlignment(item, it.brig()->align, "DirectiveVariable", "align");
           validate_fld_Dim(item, it.brig()->dim, "DirectiveVariable", "dim");
           validate_BrigVariableModifier(item, it.brig()->modifier, "DirectiveVariable", "modifier");
           validate_BrigLinkage(item, it.brig()->linkage, "DirectiveVariable", "linkage");
           validate_BrigAllocation(item, it.brig()->allocation, "DirectiveVariable", "allocation");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveVariable", "reserved");
       }
       break;

       case BRIG_KIND_DIRECTIVE_VERSION:
       {
           DirectiveVersion it = item;

           validate_BrigVersion(item, it.brig()->hsailMajor, "DirectiveVersion", "hsailMajor");
           validate_BrigVersion(item, it.brig()->hsailMinor, "DirectiveVersion", "hsailMinor");
           validate_BrigVersion(item, it.brig()->brigMajor, "DirectiveVersion", "brigMajor");
           validate_BrigVersion(item, it.brig()->brigMinor, "DirectiveVersion", "brigMinor");
           validate_BrigProfile(item, it.brig()->profile, "DirectiveVersion", "profile");
           validate_BrigMachineModel(item, it.brig()->machineModel, "DirectiveVersion", "machineModel");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveVersion", "reserved");
       }
       break;

    default:
        return false; // not found

    } // switch

    return true; // found and validated
}


bool ValidatorImpl::ValidateBrigInstFields(Inst item) const
{
    using namespace Brig;

    unsigned kind = item.kind();

    switch (kind)
    {
       case BRIG_KIND_INST_ADDR:
       {
           InstAddr it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstAddr", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstAddr", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstAddr", "operands");
           validate_BrigSegment(item, it.brig()->segment, "InstAddr", "segment");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "InstAddr", "reserved");
           }
       }
       break;

       case BRIG_KIND_INST_ATOMIC:
       {
           InstAtomic it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstAtomic", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstAtomic", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstAtomic", "operands");
           validate_BrigSegment(item, it.brig()->segment, "InstAtomic", "segment");
           validate_BrigMemoryOrder(item, it.brig()->memoryOrder, "InstAtomic", "memoryOrder");
           validate_BrigMemoryScope(item, it.brig()->memoryScope, "InstAtomic", "memoryScope");
           validate_BrigAtomicOperation(item, it.brig()->atomicOperation, "InstAtomic", "atomicOperation");
           validate_fld_EquivClass(item, it.brig()->equivClass, "InstAtomic", "equivClass");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "InstAtomic", "reserved");
           }
       }
       break;

       case BRIG_KIND_INST_BASIC:
       {
           InstBasic it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstBasic", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstBasic", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstBasic", "operands");
       }
       break;

       case BRIG_KIND_INST_BR:
       {
           InstBr it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstBr", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstBr", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstBr", "operands");
           validate_BrigWidth(item, it.brig()->width, "InstBr", "width");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "InstBr", "reserved");
           }
       }
       break;

       case BRIG_KIND_INST_CMP:
       {
           InstCmp it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstCmp", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstCmp", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstCmp", "operands");
           validate_BrigType(item, it.brig()->sourceType, "InstCmp", "sourceType");
           validate_BrigAluModifier(item, it.brig()->modifier, "InstCmp", "modifier");
           validate_BrigCompareOperation(item, it.brig()->compare, "InstCmp", "compare");
           validate_BrigPack(item, it.brig()->pack, "InstCmp", "pack");
           validate_fld_Reserved(item, it.brig()->reserved, "InstCmp", "reserved");
       }
       break;

       case BRIG_KIND_INST_CVT:
       {
           InstCvt it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstCvt", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstCvt", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstCvt", "operands");
           validate_BrigType(item, it.brig()->sourceType, "InstCvt", "sourceType");
           validate_BrigAluModifier(item, it.brig()->modifier, "InstCvt", "modifier");
       }
       break;

       case BRIG_KIND_INST_IMAGE:
       {
           InstImage it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstImage", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstImage", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstImage", "operands");
           validate_BrigType(item, it.brig()->imageType, "InstImage", "imageType");
           validate_BrigType(item, it.brig()->coordType, "InstImage", "coordType");
           validate_BrigImageGeometry(item, it.brig()->geometry, "InstImage", "geometry");
           validate_fld_EquivClass(item, it.brig()->equivClass, "InstImage", "equivClass");
           validate_fld_Reserved(item, it.brig()->reserved, "InstImage", "reserved");
       }
       break;

       case BRIG_KIND_INST_LANE:
       {
           InstLane it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstLane", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstLane", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstLane", "operands");
           validate_BrigType(item, it.brig()->sourceType, "InstLane", "sourceType");
           validate_BrigWidth(item, it.brig()->width, "InstLane", "width");
           validate_fld_Reserved(item, it.brig()->reserved, "InstLane", "reserved");
       }
       break;

       case BRIG_KIND_INST_MEM:
       {
           InstMem it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstMem", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstMem", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstMem", "operands");
           validate_BrigSegment(item, it.brig()->segment, "InstMem", "segment");
           validate_BrigAlignment(item, it.brig()->align, "InstMem", "align");
           validate_fld_EquivClass(item, it.brig()->equivClass, "InstMem", "equivClass");
           validate_BrigWidth(item, it.brig()->width, "InstMem", "width");
           validate_BrigMemoryModifier(item, it.brig()->modifier, "InstMem", "modifier");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "InstMem", "reserved");
           }
       }
       break;

       case BRIG_KIND_INST_MEM_FENCE:
       {
           InstMemFence it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstMemFence", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstMemFence", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstMemFence", "operands");
           validate_BrigMemoryOrder(item, it.brig()->memoryOrder, "InstMemFence", "memoryOrder");
           validate_BrigMemoryScope(item, it.brig()->globalSegmentMemoryScope, "InstMemFence", "globalSegmentMemoryScope");
           validate_BrigMemoryScope(item, it.brig()->groupSegmentMemoryScope, "InstMemFence", "groupSegmentMemoryScope");
           validate_BrigMemoryScope(item, it.brig()->imageSegmentMemoryScope, "InstMemFence", "imageSegmentMemoryScope");
       }
       break;

       case BRIG_KIND_INST_MOD:
       {
           InstMod it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstMod", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstMod", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstMod", "operands");
           validate_BrigAluModifier(item, it.brig()->modifier, "InstMod", "modifier");
           validate_BrigPack(item, it.brig()->pack, "InstMod", "pack");
           validate_fld_Reserved(item, it.brig()->reserved, "InstMod", "reserved");
       }
       break;

       case BRIG_KIND_INST_QUERY_IMAGE:
       {
           InstQueryImage it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstQueryImage", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstQueryImage", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstQueryImage", "operands");
           validate_BrigType(item, it.brig()->imageType, "InstQueryImage", "imageType");
           validate_BrigImageGeometry(item, it.brig()->geometry, "InstQueryImage", "geometry");
           validate_BrigImageQuery(item, it.brig()->imageQuery, "InstQueryImage", "imageQuery");
       }
       break;

       case BRIG_KIND_INST_QUERY_SAMPLER:
       {
           InstQuerySampler it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstQuerySampler", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstQuerySampler", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstQuerySampler", "operands");
           validate_BrigSamplerQuery(item, it.brig()->samplerQuery, "InstQuerySampler", "samplerQuery");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "InstQuerySampler", "reserved");
           }
       }
       break;

       case BRIG_KIND_INST_QUEUE:
       {
           InstQueue it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstQueue", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstQueue", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstQueue", "operands");
           validate_BrigSegment(item, it.brig()->segment, "InstQueue", "segment");
           validate_BrigMemoryOrder(item, it.brig()->memoryOrder, "InstQueue", "memoryOrder");
           validate_fld_Reserved(item, it.brig()->reserved, "InstQueue", "reserved");
       }
       break;

       case BRIG_KIND_INST_SEG:
       {
           InstSeg it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstSeg", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstSeg", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstSeg", "operands");
           validate_BrigSegment(item, it.brig()->segment, "InstSeg", "segment");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "InstSeg", "reserved");
           }
       }
       break;

       case BRIG_KIND_INST_SEG_CVT:
       {
           InstSegCvt it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstSegCvt", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstSegCvt", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstSegCvt", "operands");
           validate_BrigType(item, it.brig()->sourceType, "InstSegCvt", "sourceType");
           validate_BrigSegment(item, it.brig()->segment, "InstSegCvt", "segment");
           validate_BrigSegCvtModifier(item, it.brig()->modifier, "InstSegCvt", "modifier");
       }
       break;

       case BRIG_KIND_INST_SIGNAL:
       {
           InstSignal it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstSignal", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstSignal", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstSignal", "operands");
           validate_BrigType(item, it.brig()->signalType, "InstSignal", "signalType");
           validate_BrigMemoryOrder(item, it.brig()->memoryOrder, "InstSignal", "memoryOrder");
           validate_BrigAtomicOperation(item, it.brig()->signalOperation, "InstSignal", "signalOperation");
       }
       break;

       case BRIG_KIND_INST_SOURCE_TYPE:
       {
           InstSourceType it = item;

           validate_BrigOpcode(item, it.brig()->base.opcode, "InstSourceType", "opcode");
           validate_BrigType(item, it.brig()->base.type, "InstSourceType", "type");
           validate_BrigDataOffsetOperandList(item, it.brig()->base.operands, "InstSourceType", "operands");
           validate_BrigType(item, it.brig()->sourceType, "InstSourceType", "sourceType");
           validate_fld_Reserved(item, it.brig()->reserved, "InstSourceType", "reserved");
       }
       break;

    default:
        return false; // not found

    } // switch

    return true; // found and validated
}


bool ValidatorImpl::ValidateBrigOperandFields(Operand item) const
{
    using namespace Brig;

    unsigned kind = item.kind();

    switch (kind)
    {
       case BRIG_KIND_OPERAND_ADDRESS:
       {
           OperandAddress it = item;

           validate_BrigCodeOffset(item, it.brig()->symbol, "OperandAddress", "symbol");
           validate_BrigOperandOffset(item, it.brig()->reg, "OperandAddress", "reg");
           validate_fld_Offset(item, it.brig()->offset, "OperandAddress", "offset");
       }
       break;

       case BRIG_KIND_OPERAND_CODE_LIST:
       {
           OperandCodeList it = item;

           validate_BrigDataOffsetCodeList(item, it.brig()->elements, "OperandCodeList", "elements");
       }
       break;

       case BRIG_KIND_OPERAND_CODE_REF:
       {
           OperandCodeRef it = item;

           validate_BrigCodeOffset(item, it.brig()->ref, "OperandCodeRef", "ref");
       }
       break;

       case BRIG_KIND_OPERAND_DATA:
       {
           OperandData it = item;

           validate_BrigDataOffsetString(item, it.brig()->data, "OperandData", "data");
       }
       break;

       case BRIG_KIND_OPERAND_IMAGE_PROPERTIES:
       {
           OperandImageProperties it = item;

           validate_fld_Width(item, it.brig()->width, "OperandImageProperties", "width");
           validate_fld_Height(item, it.brig()->height, "OperandImageProperties", "height");
           validate_fld_Depth(item, it.brig()->depth, "OperandImageProperties", "depth");
           validate_fld_Array(item, it.brig()->array, "OperandImageProperties", "array");
           validate_BrigImageGeometry(item, it.brig()->geometry, "OperandImageProperties", "geometry");
           validate_BrigImageChannelOrder(item, it.brig()->channelOrder, "OperandImageProperties", "channelOrder");
           validate_BrigImageChannelType(item, it.brig()->channelType, "OperandImageProperties", "channelType");
           validate_fld_Reserved(item, it.brig()->reserved, "OperandImageProperties", "reserved");
       }
       break;

       case BRIG_KIND_OPERAND_OPERAND_LIST:
       {
           OperandOperandList it = item;

           validate_BrigDataOffsetOperandList(item, it.brig()->elements, "OperandOperandList", "elements");
       }
       break;

       case BRIG_KIND_OPERAND_REG:
       {
           OperandReg it = item;

           validate_BrigRegisterKind(item, it.brig()->regKind, "OperandReg", "regKind");
           validate_fld_RegNum(item, it.brig()->regNum, "OperandReg", "regNum");
       }
       break;

       case BRIG_KIND_OPERAND_SAMPLER_PROPERTIES:
       {
           OperandSamplerProperties it = item;

           validate_BrigSamplerCoordNormalization(item, it.brig()->coord, "OperandSamplerProperties", "coord");
           validate_BrigSamplerFilter(item, it.brig()->filter, "OperandSamplerProperties", "filter");
           validate_BrigSamplerAddressing(item, it.brig()->addressing, "OperandSamplerProperties", "addressing");
           validate_fld_Reserved(item, it.brig()->reserved, "OperandSamplerProperties", "reserved");
       }
       break;

       case BRIG_KIND_OPERAND_STRING:
       {
           OperandString it = item;

           validate_BrigDataOffsetString(item, it.brig()->string, "OperandString", "string");
       }
       break;

       case BRIG_KIND_OPERAND_WAVESIZE:
       {
           OperandWavesize it = item;

       }
       break;

    default:
        return false; // not found

    } // switch

    return true; // found and validated
}
