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
       case BRIG_DIRECTIVE_ARG_SCOPE_END:
       {
           DirectiveArgScopeEnd it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveArgScopeEnd", "code");
       }
       break;

       case BRIG_DIRECTIVE_ARG_SCOPE_START:
       {
           DirectiveArgScopeStart it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveArgScopeStart", "code");
       }
       break;

       case BRIG_DIRECTIVE_FUNCTION:
       {
           DirectiveFunction it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveFunction", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectiveFunction", "name");
           validate_fld_InArgCount(item, it.brig()->inArgCount, "DirectiveFunction", "inArgCount");
           validate_fld_OutArgCount(item, it.brig()->outArgCount, "DirectiveFunction", "outArgCount");
           validate_BrigDirectiveOffset(item, it.brig()->firstInArg, "DirectiveFunction", "firstInArg");
           validate_BrigDirectiveOffset(item, it.brig()->firstScopedDirective, "DirectiveFunction", "firstScopedDirective");
           validate_BrigDirectiveOffset(item, it.brig()->nextTopLevelDirective, "DirectiveFunction", "nextTopLevelDirective");
           validate_fld_InstCount(item, it.brig()->instCount, "DirectiveFunction", "instCount");
           validate_BrigExecutableModifier(item, it.brig()->modifier, "DirectiveFunction", "modifier");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "DirectiveFunction", "reserved");
           }
       }
       break;

       case BRIG_DIRECTIVE_KERNEL:
       {
           DirectiveKernel it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveKernel", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectiveKernel", "name");
           validate_fld_InArgCount(item, it.brig()->inArgCount, "DirectiveKernel", "inArgCount");
           validate_fld_OutArgCount(item, it.brig()->outArgCount, "DirectiveKernel", "outArgCount");
           validate_BrigDirectiveOffset(item, it.brig()->firstInArg, "DirectiveKernel", "firstInArg");
           validate_BrigDirectiveOffset(item, it.brig()->firstScopedDirective, "DirectiveKernel", "firstScopedDirective");
           validate_BrigDirectiveOffset(item, it.brig()->nextTopLevelDirective, "DirectiveKernel", "nextTopLevelDirective");
           validate_fld_InstCount(item, it.brig()->instCount, "DirectiveKernel", "instCount");
           validate_BrigExecutableModifier(item, it.brig()->modifier, "DirectiveKernel", "modifier");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "DirectiveKernel", "reserved");
           }
       }
       break;

       case BRIG_DIRECTIVE_SIGNATURE:
       {
           DirectiveSignature it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveSignature", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectiveSignature", "name");
           validate_fld_InArgCount(item, it.brig()->inArgCount, "DirectiveSignature", "inArgCount");
           validate_fld_OutArgCount(item, it.brig()->outArgCount, "DirectiveSignature", "outArgCount");
       }
       break;

       case BRIG_DIRECTIVE_COMMENT:
       {
           DirectiveComment it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveComment", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectiveComment", "name");
       }
       break;

       case BRIG_DIRECTIVE_CONTROL:
       {
           DirectiveControl it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveControl", "code");
           validate_BrigControlDirective(item, it.brig()->control, "DirectiveControl", "control");
           validate_BrigType(item, it.brig()->type, "DirectiveControl", "type");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveControl", "reserved");
           validate_fld_ValueCount(item, it.brig()->valueCount, "DirectiveControl", "valueCount");
       }
       break;

       case BRIG_DIRECTIVE_EXTENSION:
       {
           DirectiveExtension it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveExtension", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectiveExtension", "name");
       }
       break;

       case BRIG_DIRECTIVE_FBARRIER:
       {
           DirectiveFbarrier it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveFbarrier", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectiveFbarrier", "name");
       }
       break;

       case BRIG_DIRECTIVE_IMAGE_INIT:
       {
           DirectiveImageInit it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveImageInit", "code");
           validate_fld_Width(item, it.brig()->width, "DirectiveImageInit", "width");
           validate_fld_Height(item, it.brig()->height, "DirectiveImageInit", "height");
           validate_fld_Depth(item, it.brig()->depth, "DirectiveImageInit", "depth");
           validate_fld_Array(item, it.brig()->array, "DirectiveImageInit", "array");
           validate_BrigImageGeometry(item, it.brig()->geometry, "DirectiveImageInit", "geometry");
           validate_BrigImageOrder(item, it.brig()->order, "DirectiveImageInit", "order");
           validate_BrigImageFormat(item, it.brig()->format, "DirectiveImageInit", "format");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveImageInit", "reserved");
       }
       break;

       case BRIG_DIRECTIVE_LABEL:
       {
           DirectiveLabel it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveLabel", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectiveLabel", "name");
       }
       break;

       case BRIG_DIRECTIVE_LABEL_INIT:
       {
           DirectiveLabelInit it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveLabelInit", "code");
           validate_fld_LabelCount(item, it.brig()->labelCount, "DirectiveLabelInit", "labelCount");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveLabelInit", "reserved");
       }
       break;

       case BRIG_DIRECTIVE_LABEL_TARGETS:
       {
           DirectiveLabelTargets it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveLabelTargets", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectiveLabelTargets", "name");
           validate_fld_LabelCount(item, it.brig()->labelCount, "DirectiveLabelTargets", "labelCount");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveLabelTargets", "reserved");
       }
       break;

       case BRIG_DIRECTIVE_LOC:
       {
           DirectiveLoc it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveLoc", "code");
           validate_BrigStringOffset(item, it.brig()->filename, "DirectiveLoc", "filename");
           validate_fld_Line(item, it.brig()->line, "DirectiveLoc", "line");
           validate_fld_Column(item, it.brig()->column, "DirectiveLoc", "column");
       }
       break;

       case BRIG_DIRECTIVE_PRAGMA:
       {
           DirectivePragma it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectivePragma", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectivePragma", "name");
       }
       break;

       case BRIG_DIRECTIVE_VARIABLE:
       {
           DirectiveVariable it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveVariable", "code");
           validate_BrigStringOffset(item, it.brig()->name, "DirectiveVariable", "name");
           validate_BrigDirectiveOffset(item, it.brig()->init, "DirectiveVariable", "init");
           validate_BrigType(item, it.brig()->type, "DirectiveVariable", "type");
           validate_BrigSegment(item, it.brig()->segment, "DirectiveVariable", "segment");
           validate_BrigAlignment(item, it.brig()->align, "DirectiveVariable", "align");
           validate_fld_DimLo(item, it.brig()->dimLo, "DirectiveVariable", "dimLo");
           validate_fld_DimHi(item, it.brig()->dimHi, "DirectiveVariable", "dimHi");
           validate_BrigSymbolModifier(item, it.brig()->modifier, "DirectiveVariable", "modifier");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "DirectiveVariable", "reserved");
           }
       }
       break;

       case BRIG_DIRECTIVE_VARIABLE_INIT:
       {
           DirectiveVariableInit it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveVariableInit", "code");
           validate_BrigDataOffset(item, it.brig()->data, "DirectiveVariableInit", "data");
           validate_fld_ElementCount(item, it.brig()->elementCount, "DirectiveVariableInit", "elementCount");
           validate_BrigType(item, it.brig()->type, "DirectiveVariableInit", "type");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveVariableInit", "reserved");
       }
       break;

       case BRIG_DIRECTIVE_VERSION:
       {
           DirectiveVersion it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "DirectiveVersion", "code");
           validate_BrigVersion(item, it.brig()->hsailMajor, "DirectiveVersion", "hsailMajor");
           validate_BrigVersion(item, it.brig()->hsailMinor, "DirectiveVersion", "hsailMinor");
           validate_BrigVersion(item, it.brig()->brigMajor, "DirectiveVersion", "brigMajor");
           validate_BrigVersion(item, it.brig()->brigMinor, "DirectiveVersion", "brigMinor");
           validate_BrigProfile(item, it.brig()->profile, "DirectiveVersion", "profile");
           validate_BrigMachineModel(item, it.brig()->machineModel, "DirectiveVersion", "machineModel");
           validate_fld_Reserved(item, it.brig()->reserved, "DirectiveVersion", "reserved");
       }
       break;

       case BRIG_DIRECTIVE_SAMPLER_INIT:
       {
           DirectiveSamplerInit it = item;

           validate_BrigSamplerModifier(item, it.brig()->modifier, "DirectiveSamplerInit", "modifier");
           validate_BrigSamplerBoundaryMode(item, it.brig()->boundaryU, "DirectiveSamplerInit", "boundaryU");
           validate_BrigSamplerBoundaryMode(item, it.brig()->boundaryV, "DirectiveSamplerInit", "boundaryV");
           validate_BrigSamplerBoundaryMode(item, it.brig()->boundaryW, "DirectiveSamplerInit", "boundaryW");
       }
       break;

    default:
        return false; // not found

    } // switch

    return true; // found and validated
}


bool ValidatorImpl::ValidateBrigBlockFields(Directive item) const
{
    using namespace Brig;

    unsigned kind = item.kind();

    switch (kind)
    {
       case BRIG_DIRECTIVE_BLOCK_END:
       {
           BlockEnd it = item;

       }
       break;

       case BRIG_DIRECTIVE_BLOCK_NUMERIC:
       {
           BlockNumeric it = item;

           validate_BrigType(item, it.brig()->type, "BlockNumeric", "type");
           validate_fld_Reserved(item, it.brig()->reserved, "BlockNumeric", "reserved");
           validate_fld_ElementCount(item, it.brig()->elementCount, "BlockNumeric", "elementCount");
           validate_BrigDataOffset(item, it.brig()->data, "BlockNumeric", "data");
       }
       break;

       case BRIG_DIRECTIVE_BLOCK_STRING:
       {
           BlockString it = item;

           validate_BrigStringOffset(item, it.brig()->string, "BlockString", "string");
       }
       break;

       case BRIG_DIRECTIVE_BLOCK_START:
       {
           BlockStart it = item;

           validate_BrigCodeOffset(item, it.brig()->code, "BlockStart", "code");
           validate_BrigStringOffset(item, it.brig()->name, "BlockStart", "name");
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
       case BRIG_INST_ADDR:
       {
           InstAddr it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstAddr", "opcode");
           validate_BrigType(item, it.brig()->type, "InstAddr", "type");
           validate_BrigSegment(item, it.brig()->segment, "InstAddr", "segment");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "InstAddr", "reserved");
           }
       }
       break;

       case BRIG_INST_ATOMIC:
       {
           InstAtomic it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstAtomic", "opcode");
           validate_BrigType(item, it.brig()->type, "InstAtomic", "type");
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

       case BRIG_INST_ATOMIC_IMAGE:
       {
           InstAtomicImage it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstAtomicImage", "opcode");
           validate_BrigType(item, it.brig()->type, "InstAtomicImage", "type");
           validate_BrigType(item, it.brig()->imageType, "InstAtomicImage", "imageType");
           validate_BrigType(item, it.brig()->coordType, "InstAtomicImage", "coordType");
           validate_BrigImageGeometry(item, it.brig()->geometry, "InstAtomicImage", "geometry");
           validate_BrigAtomicOperation(item, it.brig()->atomicOperation, "InstAtomicImage", "atomicOperation");
           validate_fld_EquivClass(item, it.brig()->equivClass, "InstAtomicImage", "equivClass");
           validate_fld_Reserved(item, it.brig()->reserved, "InstAtomicImage", "reserved");
       }
       break;

       case BRIG_INST_BASIC:
       {
           InstBasic it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstBasic", "opcode");
           validate_BrigType(item, it.brig()->type, "InstBasic", "type");
       }
       break;

       case BRIG_INST_BR:
       {
           InstBr it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstBr", "opcode");
           validate_BrigType(item, it.brig()->type, "InstBr", "type");
           validate_BrigWidth(item, it.brig()->width, "InstBr", "width");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "InstBr", "reserved");
           }
       }
       break;

       case BRIG_INST_CMP:
       {
           InstCmp it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstCmp", "opcode");
           validate_BrigType(item, it.brig()->type, "InstCmp", "type");
           validate_BrigType(item, it.brig()->sourceType, "InstCmp", "sourceType");
           validate_BrigAluModifier(item, it.brig()->modifier, "InstCmp", "modifier");
           validate_BrigCompareOperation(item, it.brig()->compare, "InstCmp", "compare");
           validate_BrigPack(item, it.brig()->pack, "InstCmp", "pack");
           validate_fld_Reserved(item, it.brig()->reserved, "InstCmp", "reserved");
       }
       break;

       case BRIG_INST_CVT:
       {
           InstCvt it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstCvt", "opcode");
           validate_BrigType(item, it.brig()->type, "InstCvt", "type");
           validate_BrigType(item, it.brig()->sourceType, "InstCvt", "sourceType");
           validate_BrigAluModifier(item, it.brig()->modifier, "InstCvt", "modifier");
       }
       break;

       case BRIG_INST_IMAGE:
       {
           InstImage it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstImage", "opcode");
           validate_BrigType(item, it.brig()->type, "InstImage", "type");
           validate_BrigType(item, it.brig()->imageType, "InstImage", "imageType");
           validate_BrigType(item, it.brig()->coordType, "InstImage", "coordType");
           validate_BrigImageGeometry(item, it.brig()->geometry, "InstImage", "geometry");
           validate_fld_EquivClass(item, it.brig()->equivClass, "InstImage", "equivClass");
           validate_fld_Reserved(item, it.brig()->reserved, "InstImage", "reserved");
       }
       break;

       case BRIG_INST_LANE:
       {
           InstLane it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstLane", "opcode");
           validate_BrigType(item, it.brig()->type, "InstLane", "type");
           validate_BrigType(item, it.brig()->sourceType, "InstLane", "sourceType");
           validate_BrigWidth(item, it.brig()->width, "InstLane", "width");
           validate_fld_Reserved(item, it.brig()->reserved, "InstLane", "reserved");
       }
       break;

       case BRIG_INST_MEM:
       {
           InstMem it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstMem", "opcode");
           validate_BrigType(item, it.brig()->type, "InstMem", "type");
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

       case BRIG_INST_MEM_FENCE:
       {
           InstMemFence it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstMemFence", "opcode");
           validate_BrigType(item, it.brig()->type, "InstMemFence", "type");
           validate_BrigMemoryFenceSegments(item, it.brig()->segments, "InstMemFence", "segments");
           validate_BrigMemoryOrder(item, it.brig()->memoryOrder, "InstMemFence", "memoryOrder");
           validate_BrigMemoryScope(item, it.brig()->memoryScope, "InstMemFence", "memoryScope");
           validate_fld_Reserved(item, it.brig()->reserved, "InstMemFence", "reserved");
       }
       break;

       case BRIG_INST_MOD:
       {
           InstMod it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstMod", "opcode");
           validate_BrigType(item, it.brig()->type, "InstMod", "type");
           validate_BrigAluModifier(item, it.brig()->modifier, "InstMod", "modifier");
           validate_BrigPack(item, it.brig()->pack, "InstMod", "pack");
           validate_fld_Reserved(item, it.brig()->reserved, "InstMod", "reserved");
       }
       break;

       case BRIG_INST_QUEUE:
       {
           InstQueue it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstQueue", "opcode");
           validate_BrigType(item, it.brig()->type, "InstQueue", "type");
           validate_BrigSegment(item, it.brig()->segment, "InstQueue", "segment");
           validate_BrigMemoryOrder(item, it.brig()->memoryOrder, "InstQueue", "memoryOrder");
           validate_fld_Reserved(item, it.brig()->reserved, "InstQueue", "reserved");
       }
       break;

       case BRIG_INST_SEG:
       {
           InstSeg it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstSeg", "opcode");
           validate_BrigType(item, it.brig()->type, "InstSeg", "type");
           validate_BrigSegment(item, it.brig()->segment, "InstSeg", "segment");
           for (unsigned i = 0; i < 3; i++) {
               validate_fld_Reserved(item, it.brig()->reserved[i], "InstSeg", "reserved");
           }
       }
       break;

       case BRIG_INST_SEG_CVT:
       {
           InstSegCvt it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstSegCvt", "opcode");
           validate_BrigType(item, it.brig()->type, "InstSegCvt", "type");
           validate_BrigType(item, it.brig()->sourceType, "InstSegCvt", "sourceType");
           validate_BrigSegment(item, it.brig()->segment, "InstSegCvt", "segment");
           validate_BrigSegCvtModifier(item, it.brig()->modifier, "InstSegCvt", "modifier");
       }
       break;

       case BRIG_INST_SIGNAL:
       {
           InstSignal it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstSignal", "opcode");
           validate_BrigType(item, it.brig()->type, "InstSignal", "type");
           validate_BrigType(item, it.brig()->signalType, "InstSignal", "signalType");
           validate_BrigMemoryOrder(item, it.brig()->memoryOrder, "InstSignal", "memoryOrder");
           validate_BrigSignalOperation(item, it.brig()->signalOperation, "InstSignal", "signalOperation");
       }
       break;

       case BRIG_INST_SOURCE_TYPE:
       {
           InstSourceType it = item;

           validate_BrigOpcode(item, it.brig()->opcode, "InstSourceType", "opcode");
           validate_BrigType(item, it.brig()->type, "InstSourceType", "type");
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
       case BRIG_OPERAND_ADDRESS:
       {
           OperandAddress it = item;

           validate_BrigDirectiveOffset(item, it.brig()->symbol, "OperandAddress", "symbol");
           validate_BrigStringOffset(item, it.brig()->reg, "OperandAddress", "reg");
           validate_fld_OffsetLo(item, it.brig()->offsetLo, "OperandAddress", "offsetLo");
           validate_fld_OffsetHi(item, it.brig()->offsetHi, "OperandAddress", "offsetHi");
       }
       break;

       case BRIG_OPERAND_IMMED:
       {
           OperandImmed it = item;

           validate_fld_Reserved(item, it.brig()->reserved, "OperandImmed", "reserved");
           validate_fld_ByteCount(item, it.brig()->byteCount, "OperandImmed", "byteCount");
           validate_fld_Bytes(item, it.brig()->bytes, "OperandImmed", "bytes");
       }
       break;

       case BRIG_OPERAND_ARGUMENT_LIST:
       {
           OperandArgumentList it = item;

           validate_fld_Reserved(item, it.brig()->reserved, "OperandArgumentList", "reserved");
           validate_fld_ElementCount(item, it.brig()->elementCount, "OperandArgumentList", "elementCount");
       }
       break;

       case BRIG_OPERAND_FUNCTION_LIST:
       {
           OperandFunctionList it = item;

           validate_fld_Reserved(item, it.brig()->reserved, "OperandFunctionList", "reserved");
           validate_fld_ElementCount(item, it.brig()->elementCount, "OperandFunctionList", "elementCount");
       }
       break;

       case BRIG_OPERAND_FBARRIER_REF:
       {
           OperandFbarrierRef it = item;

           validate_BrigDirectiveOffset(item, it.brig()->ref, "OperandFbarrierRef", "ref");
       }
       break;

       case BRIG_OPERAND_FUNCTION_REF:
       {
           OperandFunctionRef it = item;

           validate_BrigDirectiveOffset(item, it.brig()->ref, "OperandFunctionRef", "ref");
       }
       break;

       case BRIG_OPERAND_LABEL_REF:
       {
           OperandLabelRef it = item;

           validate_BrigDirectiveOffset(item, it.brig()->label, "OperandLabelRef", "label");
       }
       break;

       case BRIG_OPERAND_LABEL_TARGETS_REF:
       {
           OperandLabelTargetsRef it = item;

           validate_BrigDirectiveOffset(item, it.brig()->targets, "OperandLabelTargetsRef", "targets");
       }
       break;

       case BRIG_OPERAND_LABEL_VARIABLE_REF:
       {
           OperandLabelVariableRef it = item;

           validate_BrigDirectiveOffset(item, it.brig()->symbol, "OperandLabelVariableRef", "symbol");
       }
       break;

       case BRIG_OPERAND_SIGNATURE_REF:
       {
           OperandSignatureRef it = item;

           validate_BrigDirectiveOffset(item, it.brig()->ref, "OperandSignatureRef", "ref");
       }
       break;

       case BRIG_OPERAND_REG:
       {
           OperandReg it = item;

           validate_BrigStringOffset(item, it.brig()->reg, "OperandReg", "reg");
       }
       break;

       case BRIG_OPERAND_REG_VECTOR:
       {
           OperandRegVector it = item;

           validate_fld_Reserved(item, it.brig()->reserved, "OperandRegVector", "reserved");
           validate_fld_RegCount(item, it.brig()->regCount, "OperandRegVector", "regCount");
       }
       break;

       case BRIG_OPERAND_WAVESIZE:
       {
           OperandWavesize it = item;

       }
       break;

    default:
        return false; // not found

    } // switch

    return true; // found and validated
}
