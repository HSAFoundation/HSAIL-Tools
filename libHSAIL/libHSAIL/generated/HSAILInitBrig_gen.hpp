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

void Code::initBrig() {
}

void Directive::initBrig() {
  Code::initBrig();
}

void DirectiveArgBlockEnd::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveArgBlockEnd), Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_END);
  Directive::initBrig();
}

void DirectiveArgBlockStart::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveArgBlockStart), Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_START);
  Directive::initBrig();
}

void DirectiveComment::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveComment), Brig::BRIG_KIND_DIRECTIVE_COMMENT);
  Directive::initBrig();
  brig()->name = 0;
}

void DirectiveControl::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveControl), Brig::BRIG_KIND_DIRECTIVE_CONTROL);
  Directive::initBrig();
  brig()->reserved = 0;
  brig()->operands = 0;
}

void DirectiveExecutable::initBrig() {
  Directive::initBrig();
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

void DirectiveFunction::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveExecutable), Brig::BRIG_KIND_DIRECTIVE_FUNCTION);
  DirectiveExecutable::initBrig();
}

void DirectiveIndirectFunction::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveExecutable), Brig::BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION);
  DirectiveExecutable::initBrig();
}

void DirectiveKernel::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveExecutable), Brig::BRIG_KIND_DIRECTIVE_KERNEL);
  DirectiveExecutable::initBrig();
}

void DirectiveSignature::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveExecutable), Brig::BRIG_KIND_DIRECTIVE_SIGNATURE);
  DirectiveExecutable::initBrig();
}

void DirectiveExtension::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveExtension), Brig::BRIG_KIND_DIRECTIVE_EXTENSION);
  Directive::initBrig();
  brig()->name = 0;
}

void DirectiveFbarrier::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveFbarrier), Brig::BRIG_KIND_DIRECTIVE_FBARRIER);
  Directive::initBrig();
  brig()->name = 0;
  modifier().initBrig();
  brig()->linkage = Brig::BRIG_LINKAGE_NONE;
  brig()->reserved = 0;
}

void DirectiveLabel::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveLabel), Brig::BRIG_KIND_DIRECTIVE_LABEL);
  Directive::initBrig();
  brig()->name = 0;
}

void DirectiveLoc::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveLoc), Brig::BRIG_KIND_DIRECTIVE_LOC);
  Directive::initBrig();
  brig()->filename = 0;
  brig()->column = 1;
}

void DirectiveNone::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveNone), Brig::BRIG_KIND_NONE);
  Directive::initBrig();
}

void DirectivePragma::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectivePragma), Brig::BRIG_KIND_DIRECTIVE_PRAGMA);
  Directive::initBrig();
  brig()->operands = 0;
}

void DirectiveVariable::initBrig() {
  initBrigBase(sizeof(Brig::BrigDirectiveVariable), Brig::BRIG_KIND_DIRECTIVE_VARIABLE);
  Directive::initBrig();
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
  initBrigBase(sizeof(Brig::BrigDirectiveVersion), Brig::BRIG_KIND_DIRECTIVE_VERSION);
  Directive::initBrig();
  brig()->profile = Brig::BRIG_PROFILE_FULL;
  brig()->machineModel = Brig::BRIG_MACHINE_LARGE;
  brig()->reserved = 0;
}

void Inst::initBrig() {
  Code::initBrig();
  brig()->operands = 0;
}

void InstAddr::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstAddr), Brig::BRIG_KIND_INST_ADDR);
  Inst::initBrig();
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstAtomic::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstAtomic), Brig::BRIG_KIND_INST_ATOMIC);
  Inst::initBrig();
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
  brig()->memoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstBasic::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstBasic), Brig::BRIG_KIND_INST_BASIC);
  Inst::initBrig();
}

void InstBr::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstBr), Brig::BRIG_KIND_INST_BR);
  Inst::initBrig();
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstCmp::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstCmp), Brig::BRIG_KIND_INST_CMP);
  Inst::initBrig();
  modifier().initBrig();
  brig()->pack = Brig::BRIG_PACK_NONE;
  brig()->reserved = 0;
}

void InstCvt::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstCvt), Brig::BRIG_KIND_INST_CVT);
  Inst::initBrig();
  modifier().initBrig();
}

void InstImage::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstImage), Brig::BRIG_KIND_INST_IMAGE);
  Inst::initBrig();
  brig()->geometry = Brig::BRIG_GEOMETRY_UNKNOWN;
  brig()->reserved = 0;
}

void InstLane::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstLane), Brig::BRIG_KIND_INST_LANE);
  Inst::initBrig();
  brig()->reserved = 0;
}

void InstMem::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstMem), Brig::BRIG_KIND_INST_MEM);
  Inst::initBrig();
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  brig()->align = Brig::BRIG_ALIGNMENT_NONE;
  modifier().initBrig();
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstMemFence::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstMemFence), Brig::BRIG_KIND_INST_MEM_FENCE);
  Inst::initBrig();
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
  brig()->globalSegmentMemoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
  brig()->groupSegmentMemoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
  brig()->imageSegmentMemoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
}

void InstMod::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstMod), Brig::BRIG_KIND_INST_MOD);
  Inst::initBrig();
  modifier().initBrig();
  brig()->pack = Brig::BRIG_PACK_NONE;
  brig()->reserved = 0;
}

void InstQueryImage::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstQueryImage), Brig::BRIG_KIND_INST_QUERY_IMAGE);
  Inst::initBrig();
  brig()->geometry = Brig::BRIG_GEOMETRY_UNKNOWN;
}

void InstQuerySampler::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstQuerySampler), Brig::BRIG_KIND_INST_QUERY_SAMPLER);
  Inst::initBrig();
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstQueue::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstQueue), Brig::BRIG_KIND_INST_QUEUE);
  Inst::initBrig();
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
  brig()->reserved = 0;
}

void InstSeg::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstSeg), Brig::BRIG_KIND_INST_SEG);
  Inst::initBrig();
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstSegCvt::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstSegCvt), Brig::BRIG_KIND_INST_SEG_CVT);
  Inst::initBrig();
  brig()->segment = Brig::BRIG_SEGMENT_NONE;
  modifier().initBrig();
}

void InstSignal::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstSignal), Brig::BRIG_KIND_INST_SIGNAL);
  Inst::initBrig();
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
}

void InstSourceType::initBrig() {
  initBrigBase(sizeof(Brig::BrigInstSourceType), Brig::BRIG_KIND_INST_SOURCE_TYPE);
  Inst::initBrig();
  brig()->reserved = 0;
}

void ExecutableModifier::initBrig() {
  brig()->allBits = 0;
}

void MemoryModifier::initBrig() {
  brig()->allBits = 0;
}

void Operand::initBrig() {
}

void OperandAddress::initBrig() {
  initBrigBase(sizeof(Brig::BrigOperandAddress), Brig::BRIG_KIND_OPERAND_ADDRESS);
  Operand::initBrig();
  brig()->symbol = 0;
  brig()->reg = 0;
  offset().initBrig();
}

void OperandCodeList::initBrig() {
  initBrigBase(sizeof(Brig::BrigOperandCodeList), Brig::BRIG_KIND_OPERAND_CODE_LIST);
  Operand::initBrig();
  brig()->elements = 0;
}

void OperandCodeRef::initBrig() {
  initBrigBase(sizeof(Brig::BrigOperandCodeRef), Brig::BRIG_KIND_OPERAND_CODE_REF);
  Operand::initBrig();
  brig()->ref = 0;
}

void OperandData::initBrig() {
  initBrigBase(sizeof(Brig::BrigOperandData), Brig::BRIG_KIND_OPERAND_DATA);
  Operand::initBrig();
  brig()->data = 0;
}

void OperandImageProperties::initBrig() {
  initBrigBase(sizeof(Brig::BrigOperandImageProperties), Brig::BRIG_KIND_OPERAND_IMAGE_PROPERTIES);
  Operand::initBrig();
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
  initBrigBase(sizeof(Brig::BrigOperandOperandList), Brig::BRIG_KIND_OPERAND_OPERAND_LIST);
  Operand::initBrig();
  brig()->elements = 0;
}

void OperandReg::initBrig() {
  initBrigBase(sizeof(Brig::BrigOperandReg), Brig::BRIG_KIND_OPERAND_REG);
  Operand::initBrig();
}

void OperandSamplerProperties::initBrig() {
  initBrigBase(sizeof(Brig::BrigOperandSamplerProperties), Brig::BRIG_KIND_OPERAND_SAMPLER_PROPERTIES);
  Operand::initBrig();
  brig()->addressing = Brig::BRIG_ADDRESSING_CLAMP_TO_EDGE;
  brig()->reserved = 0;
}

void OperandString::initBrig() {
  initBrigBase(sizeof(Brig::BrigOperandString), Brig::BRIG_KIND_OPERAND_STRING);
  Operand::initBrig();
  brig()->string = 0;
}

void OperandWavesize::initBrig() {
  initBrigBase(sizeof(Brig::BrigOperandWavesize), Brig::BRIG_KIND_OPERAND_WAVESIZE);
  Operand::initBrig();
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

