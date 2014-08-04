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
void AluModifier::initBrig() {
  brig()->allBits = 0;
}

void DirectiveArgBlockEnd::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveArgBlockEnd);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_END;
}

void DirectiveArgBlockStart::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveArgBlockStart);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_START;
}

void DirectiveComment::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveComment);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_COMMENT;
  brig()->name = 0;
}

void DirectiveControl::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveControl);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_CONTROL;
  brig()->reserved = 0;
  brig()->operands = 0;
}

void DirectiveFunction::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveFunction);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_FUNCTION;
  brig()->name = 0;
  brig()->outArgCount = 0;
  brig()->inArgCount = 0;
  brig()->firstInArg = 0;
  brig()->firstCodeBlockEntry = 0;
  brig()->nextModuleEntry = 0;
  brig()->codeBlockEntryCount = 0;
  modifier().initBrig();
  brig()->linkage = Brig::BRIG_LINKAGE_NONE;
  brig()->reserved = 0;
}

void DirectiveIndirectFunction::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveIndirectFunction);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION;
  brig()->name = 0;
  brig()->outArgCount = 0;
  brig()->inArgCount = 0;
  brig()->firstInArg = 0;
  brig()->firstCodeBlockEntry = 0;
  brig()->nextModuleEntry = 0;
  brig()->codeBlockEntryCount = 0;
  modifier().initBrig();
  brig()->linkage = Brig::BRIG_LINKAGE_NONE;
  brig()->reserved = 0;
}

void DirectiveKernel::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveKernel);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_KERNEL;
  brig()->name = 0;
  brig()->outArgCount = 0;
  brig()->inArgCount = 0;
  brig()->firstInArg = 0;
  brig()->firstCodeBlockEntry = 0;
  brig()->nextModuleEntry = 0;
  brig()->codeBlockEntryCount = 0;
  modifier().initBrig();
  brig()->linkage = Brig::BRIG_LINKAGE_NONE;
  brig()->reserved = 0;
}

void DirectiveSignature::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveSignature);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_SIGNATURE;
  brig()->name = 0;
  brig()->outArgCount = 0;
  brig()->inArgCount = 0;
  brig()->firstInArg = 0;
  brig()->firstCodeBlockEntry = 0;
  brig()->nextModuleEntry = 0;
  brig()->codeBlockEntryCount = 0;
  modifier().initBrig();
  brig()->linkage = Brig::BRIG_LINKAGE_NONE;
  brig()->reserved = 0;
}

void DirectiveExtension::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveExtension);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_EXTENSION;
  brig()->name = 0;
}

void DirectiveFbarrier::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveFbarrier);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_FBARRIER;
  brig()->name = 0;
  modifier().initBrig();
  brig()->linkage = Brig::BRIG_LINKAGE_NONE;
  brig()->reserved = 0;
}

void DirectiveLabel::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveLabel);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_LABEL;
  brig()->name = 0;
}

void DirectiveLoc::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveLoc);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_LOC;
  brig()->filename = 0;
  brig()->column = 1;
}

void DirectiveNone::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveNone);
  brig()->kind = Brig::BRIG_KIND_NONE;
}

void DirectivePragma::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectivePragma);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_PRAGMA;
  brig()->operands = 0;
}

void DirectiveVariable::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveVariable);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_VARIABLE;
  brig()->name = 0;
  brig()->init = 0;
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  brig()->align = Brig::BRIG_ALIGNMENT_NONE;
  dim().initBrig();
  modifier().initBrig();
  brig()->linkage = Brig::BRIG_LINKAGE_NONE;
  brig()->allocation = Brig::BRIG_ALLOCATION_NONE;
  brig()->reserved = 0;
}

void DirectiveVersion::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigDirectiveVersion);
  brig()->kind = Brig::BRIG_KIND_DIRECTIVE_VERSION;
  brig()->profile = Brig::BRIG_PROFILE_FULL;
  brig()->machineModel = Brig::BRIG_MACHINE_LARGE;
  brig()->reserved = 0;
}

void InstAddr::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstAddr);
  brig()->kind = Brig::BRIG_KIND_INST_ADDR;
  brig()->operands = 0;
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstAtomic::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstAtomic);
  brig()->kind = Brig::BRIG_KIND_INST_ATOMIC;
  brig()->operands = 0;
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
  brig()->memoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstBasic::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstBasic);
  brig()->kind = Brig::BRIG_KIND_INST_BASIC;
  brig()->operands = 0;
}

void InstBr::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstBr);
  brig()->kind = Brig::BRIG_KIND_INST_BR;
  brig()->operands = 0;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstCmp::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstCmp);
  brig()->kind = Brig::BRIG_KIND_INST_CMP;
  brig()->operands = 0;
  modifier().initBrig();
  brig()->pack = Brig::BRIG_PACK_NONE;
  brig()->reserved = 0;
}

void InstCvt::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstCvt);
  brig()->kind = Brig::BRIG_KIND_INST_CVT;
  brig()->operands = 0;
  modifier().initBrig();
}

void InstImage::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstImage);
  brig()->kind = Brig::BRIG_KIND_INST_IMAGE;
  brig()->operands = 0;
  brig()->geometry = Brig::BRIG_GEOMETRY_UNKNOWN;
  brig()->reserved = 0;
}

void InstLane::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstLane);
  brig()->kind = Brig::BRIG_KIND_INST_LANE;
  brig()->operands = 0;
  brig()->reserved = 0;
}

void InstMem::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstMem);
  brig()->kind = Brig::BRIG_KIND_INST_MEM;
  brig()->operands = 0;
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  brig()->align = Brig::BRIG_ALIGNMENT_NONE;
  modifier().initBrig();
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstMemFence::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstMemFence);
  brig()->kind = Brig::BRIG_KIND_INST_MEM_FENCE;
  brig()->operands = 0;
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
  brig()->globalSegmentMemoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
  brig()->groupSegmentMemoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
  brig()->imageSegmentMemoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
}

void InstMod::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstMod);
  brig()->kind = Brig::BRIG_KIND_INST_MOD;
  brig()->operands = 0;
  modifier().initBrig();
  brig()->pack = Brig::BRIG_PACK_NONE;
  brig()->reserved = 0;
}

void InstQueryImage::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstQueryImage);
  brig()->kind = Brig::BRIG_KIND_INST_QUERY_IMAGE;
  brig()->operands = 0;
  brig()->geometry = Brig::BRIG_GEOMETRY_UNKNOWN;
}

void InstQuerySampler::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstQuerySampler);
  brig()->kind = Brig::BRIG_KIND_INST_QUERY_SAMPLER;
  brig()->operands = 0;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstQueue::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstQueue);
  brig()->kind = Brig::BRIG_KIND_INST_QUEUE;
  brig()->operands = 0;
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
  brig()->reserved = 0;
}

void InstSeg::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstSeg);
  brig()->kind = Brig::BRIG_KIND_INST_SEG;
  brig()->operands = 0;
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstSegCvt::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstSegCvt);
  brig()->kind = Brig::BRIG_KIND_INST_SEG_CVT;
  brig()->operands = 0;
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  modifier().initBrig();
}

void InstSignal::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstSignal);
  brig()->kind = Brig::BRIG_KIND_INST_SIGNAL;
  brig()->operands = 0;
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
}

void InstSourceType::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigInstSourceType);
  brig()->kind = Brig::BRIG_KIND_INST_SOURCE_TYPE;
  brig()->operands = 0;
  brig()->reserved = 0;
}

void ExecutableModifier::initBrig() {
  brig()->allBits = 0;
}

void MemoryModifier::initBrig() {
  brig()->allBits = 0;
}

void OperandAddress::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandAddress);
  brig()->kind = Brig::BRIG_KIND_OPERAND_ADDRESS;
  brig()->symbol = 0;
  brig()->reg = 0;
  offset().initBrig();
}

void OperandCodeList::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandCodeList);
  brig()->kind = Brig::BRIG_KIND_OPERAND_CODE_LIST;
  brig()->elements = 0;
}

void OperandCodeRef::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandCodeRef);
  brig()->kind = Brig::BRIG_KIND_OPERAND_CODE_REF;
  brig()->ref = 0;
}

void OperandData::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandData);
  brig()->kind = Brig::BRIG_KIND_OPERAND_DATA;
  brig()->data = 0;
}

void OperandImageProperties::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandImageProperties);
  brig()->kind = Brig::BRIG_KIND_OPERAND_IMAGE_PROPERTIES;
  width().initBrig();
  height().initBrig();
  depth().initBrig();
  array().initBrig();
  brig()->geometry = Brig::BRIG_GEOMETRY_UNKNOWN;
  brig()->channelOrder = Brig::BRIG_CHANNEL_ORDER_UNKNOWN;
  brig()->channelType = Brig::BRIG_CHANNEL_TYPE_UNKNOWN;
  brig()->reserved = 0;
}

void OperandOperandList::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandOperandList);
  brig()->kind = Brig::BRIG_KIND_OPERAND_OPERAND_LIST;
  brig()->elements = 0;
}

void OperandReg::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandReg);
  brig()->kind = Brig::BRIG_KIND_OPERAND_REG;
}

void OperandSamplerProperties::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandSamplerProperties);
  brig()->kind = Brig::BRIG_KIND_OPERAND_SAMPLER_PROPERTIES;
  brig()->addressing = Brig::BRIG_ADDRESSING_CLAMP_TO_EDGE;
  brig()->reserved = 0;
}

void OperandString::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandString);
  brig()->kind = Brig::BRIG_KIND_OPERAND_STRING;
  brig()->string = 0;
}

void OperandWavesize::initBrig() {
  brig()->byteCount = sizeof(Brig::BrigOperandWavesize);
  brig()->kind = Brig::BRIG_KIND_OPERAND_WAVESIZE;
}

void SegCvtModifier::initBrig() {
  brig()->allBits = 0;
}

void UInt64::initBrig() {
  brig()->lo = 0;
  brig()->hi = 0;
}

void VariableModifier::initBrig() {
  brig()->allBits = 0;
}

