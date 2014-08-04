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
template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(Code item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END: return vis(DirectiveArgBlockEnd(item));
	case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START: return vis(DirectiveArgBlockStart(item));
	case BRIG_KIND_DIRECTIVE_COMMENT: return vis(DirectiveComment(item));
	case BRIG_KIND_DIRECTIVE_CONTROL: return vis(DirectiveControl(item));
	case BRIG_KIND_DIRECTIVE_EXTENSION: return vis(DirectiveExtension(item));
	case BRIG_KIND_DIRECTIVE_FBARRIER: return vis(DirectiveFbarrier(item));
	case BRIG_KIND_DIRECTIVE_FUNCTION: return vis(DirectiveFunction(item));
	case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION: return vis(DirectiveIndirectFunction(item));
	case BRIG_KIND_DIRECTIVE_KERNEL: return vis(DirectiveKernel(item));
	case BRIG_KIND_DIRECTIVE_LABEL: return vis(DirectiveLabel(item));
	case BRIG_KIND_DIRECTIVE_LOC: return vis(DirectiveLoc(item));
	case BRIG_KIND_DIRECTIVE_PRAGMA: return vis(DirectivePragma(item));
	case BRIG_KIND_DIRECTIVE_SIGNATURE: return vis(DirectiveSignature(item));
	case BRIG_KIND_DIRECTIVE_VARIABLE: return vis(DirectiveVariable(item));
	case BRIG_KIND_DIRECTIVE_VERSION: return vis(DirectiveVersion(item));
	case BRIG_KIND_INST_ADDR: return vis(InstAddr(item));
	case BRIG_KIND_INST_ATOMIC: return vis(InstAtomic(item));
	case BRIG_KIND_INST_BASIC: return vis(InstBasic(item));
	case BRIG_KIND_INST_BR: return vis(InstBr(item));
	case BRIG_KIND_INST_CMP: return vis(InstCmp(item));
	case BRIG_KIND_INST_CVT: return vis(InstCvt(item));
	case BRIG_KIND_INST_IMAGE: return vis(InstImage(item));
	case BRIG_KIND_INST_LANE: return vis(InstLane(item));
	case BRIG_KIND_INST_MEM: return vis(InstMem(item));
	case BRIG_KIND_INST_MEM_FENCE: return vis(InstMemFence(item));
	case BRIG_KIND_INST_MOD: return vis(InstMod(item));
	case BRIG_KIND_INST_QUERY_IMAGE: return vis(InstQueryImage(item));
	case BRIG_KIND_INST_QUERY_SAMPLER: return vis(InstQuerySampler(item));
	case BRIG_KIND_INST_QUEUE: return vis(InstQueue(item));
	case BRIG_KIND_INST_SEG: return vis(InstSeg(item));
	case BRIG_KIND_INST_SEG_CVT: return vis(InstSegCvt(item));
	case BRIG_KIND_INST_SIGNAL: return vis(InstSignal(item));
	case BRIG_KIND_INST_SOURCE_TYPE: return vis(InstSourceType(item));
	case BRIG_KIND_NONE: return vis(DirectiveNone(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(Directive item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END: return vis(DirectiveArgBlockEnd(item));
	case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START: return vis(DirectiveArgBlockStart(item));
	case BRIG_KIND_DIRECTIVE_COMMENT: return vis(DirectiveComment(item));
	case BRIG_KIND_DIRECTIVE_CONTROL: return vis(DirectiveControl(item));
	case BRIG_KIND_DIRECTIVE_EXTENSION: return vis(DirectiveExtension(item));
	case BRIG_KIND_DIRECTIVE_FBARRIER: return vis(DirectiveFbarrier(item));
	case BRIG_KIND_DIRECTIVE_FUNCTION: return vis(DirectiveFunction(item));
	case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION: return vis(DirectiveIndirectFunction(item));
	case BRIG_KIND_DIRECTIVE_KERNEL: return vis(DirectiveKernel(item));
	case BRIG_KIND_DIRECTIVE_LABEL: return vis(DirectiveLabel(item));
	case BRIG_KIND_DIRECTIVE_LOC: return vis(DirectiveLoc(item));
	case BRIG_KIND_DIRECTIVE_PRAGMA: return vis(DirectivePragma(item));
	case BRIG_KIND_DIRECTIVE_SIGNATURE: return vis(DirectiveSignature(item));
	case BRIG_KIND_DIRECTIVE_VARIABLE: return vis(DirectiveVariable(item));
	case BRIG_KIND_DIRECTIVE_VERSION: return vis(DirectiveVersion(item));
	case BRIG_KIND_NONE: return vis(DirectiveNone(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(DirectiveExecutable item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_KIND_DIRECTIVE_FUNCTION: return vis(DirectiveFunction(item));
	case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION: return vis(DirectiveIndirectFunction(item));
	case BRIG_KIND_DIRECTIVE_KERNEL: return vis(DirectiveKernel(item));
	case BRIG_KIND_DIRECTIVE_SIGNATURE: return vis(DirectiveSignature(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(Inst item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_KIND_INST_ADDR: return vis(InstAddr(item));
	case BRIG_KIND_INST_ATOMIC: return vis(InstAtomic(item));
	case BRIG_KIND_INST_BASIC: return vis(InstBasic(item));
	case BRIG_KIND_INST_BR: return vis(InstBr(item));
	case BRIG_KIND_INST_CMP: return vis(InstCmp(item));
	case BRIG_KIND_INST_CVT: return vis(InstCvt(item));
	case BRIG_KIND_INST_IMAGE: return vis(InstImage(item));
	case BRIG_KIND_INST_LANE: return vis(InstLane(item));
	case BRIG_KIND_INST_MEM: return vis(InstMem(item));
	case BRIG_KIND_INST_MEM_FENCE: return vis(InstMemFence(item));
	case BRIG_KIND_INST_MOD: return vis(InstMod(item));
	case BRIG_KIND_INST_QUERY_IMAGE: return vis(InstQueryImage(item));
	case BRIG_KIND_INST_QUERY_SAMPLER: return vis(InstQuerySampler(item));
	case BRIG_KIND_INST_QUEUE: return vis(InstQueue(item));
	case BRIG_KIND_INST_SEG: return vis(InstSeg(item));
	case BRIG_KIND_INST_SEG_CVT: return vis(InstSegCvt(item));
	case BRIG_KIND_INST_SIGNAL: return vis(InstSignal(item));
	case BRIG_KIND_INST_SOURCE_TYPE: return vis(InstSourceType(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(Operand item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_KIND_OPERAND_ADDRESS: return vis(OperandAddress(item));
	case BRIG_KIND_OPERAND_CODE_LIST: return vis(OperandCodeList(item));
	case BRIG_KIND_OPERAND_CODE_REF: return vis(OperandCodeRef(item));
	case BRIG_KIND_OPERAND_DATA: return vis(OperandData(item));
	case BRIG_KIND_OPERAND_IMAGE_PROPERTIES: return vis(OperandImageProperties(item));
	case BRIG_KIND_OPERAND_OPERAND_LIST: return vis(OperandOperandList(item));
	case BRIG_KIND_OPERAND_REG: return vis(OperandReg(item));
	case BRIG_KIND_OPERAND_SAMPLER_PROPERTIES: return vis(OperandSamplerProperties(item));
	case BRIG_KIND_OPERAND_STRING: return vis(OperandString(item));
	case BRIG_KIND_OPERAND_WAVESIZE: return vis(OperandWavesize(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename Visitor> void enumerateFields_gen(AluModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.round(),"round");
  vis(obj.ftz(),"ftz");
}

template <typename Visitor> void enumerateFields_gen(DirectiveArgBlockEnd obj,  Visitor & vis) {
}

template <typename Visitor> void enumerateFields_gen(DirectiveArgBlockStart obj,  Visitor & vis) {
}

template <typename Visitor> void enumerateFields_gen(DirectiveComment obj,  Visitor & vis) {
  vis(obj.name(),"name");
}

template <typename Visitor> void enumerateFields_gen(DirectiveControl obj,  Visitor & vis) {
  vis(obj.control(),"control");
  vis(obj.operands(),"operands");
}

template <typename Visitor> void enumerateFields_gen(DirectiveFunction obj,  Visitor & vis) {
  vis(obj.name(),"name");
  vis(obj.outArgCount(),"outArgCount");
  vis(obj.inArgCount(),"inArgCount");
  vis(obj.firstInArg(),"firstInArg");
  vis(obj.firstCodeBlockEntry(),"firstCodeBlockEntry");
  vis(obj.nextModuleEntry(),"nextModuleEntry");
  vis(obj.codeBlockEntryCount(),"codeBlockEntryCount");
  enumerateFields(obj.modifier(), vis);
  vis(obj.linkage(),"linkage");
}

template <typename Visitor> void enumerateFields_gen(DirectiveIndirectFunction obj,  Visitor & vis) {
  vis(obj.name(),"name");
  vis(obj.outArgCount(),"outArgCount");
  vis(obj.inArgCount(),"inArgCount");
  vis(obj.firstInArg(),"firstInArg");
  vis(obj.firstCodeBlockEntry(),"firstCodeBlockEntry");
  vis(obj.nextModuleEntry(),"nextModuleEntry");
  vis(obj.codeBlockEntryCount(),"codeBlockEntryCount");
  enumerateFields(obj.modifier(), vis);
  vis(obj.linkage(),"linkage");
}

template <typename Visitor> void enumerateFields_gen(DirectiveKernel obj,  Visitor & vis) {
  vis(obj.name(),"name");
  vis(obj.outArgCount(),"outArgCount");
  vis(obj.inArgCount(),"inArgCount");
  vis(obj.firstInArg(),"firstInArg");
  vis(obj.firstCodeBlockEntry(),"firstCodeBlockEntry");
  vis(obj.nextModuleEntry(),"nextModuleEntry");
  vis(obj.codeBlockEntryCount(),"codeBlockEntryCount");
  enumerateFields(obj.modifier(), vis);
  vis(obj.linkage(),"linkage");
}

template <typename Visitor> void enumerateFields_gen(DirectiveSignature obj,  Visitor & vis) {
  vis(obj.name(),"name");
  vis(obj.outArgCount(),"outArgCount");
  vis(obj.inArgCount(),"inArgCount");
  vis(obj.firstInArg(),"firstInArg");
  vis(obj.firstCodeBlockEntry(),"firstCodeBlockEntry");
  vis(obj.nextModuleEntry(),"nextModuleEntry");
  vis(obj.codeBlockEntryCount(),"codeBlockEntryCount");
  enumerateFields(obj.modifier(), vis);
  vis(obj.linkage(),"linkage");
}

template <typename Visitor> void enumerateFields_gen(DirectiveExtension obj,  Visitor & vis) {
  vis(obj.name(),"name");
}

template <typename Visitor> void enumerateFields_gen(DirectiveFbarrier obj,  Visitor & vis) {
  vis(obj.name(),"name");
  enumerateFields(obj.modifier(), vis);
  vis(obj.linkage(),"linkage");
}

template <typename Visitor> void enumerateFields_gen(DirectiveLabel obj,  Visitor & vis) {
  vis(obj.name(),"name");
}

template <typename Visitor> void enumerateFields_gen(DirectiveLoc obj,  Visitor & vis) {
  vis(obj.filename(),"filename");
  vis(obj.line(),"line");
  vis(obj.column(),"column");
}

template <typename Visitor> void enumerateFields_gen(DirectiveNone obj,  Visitor & vis) {
}

template <typename Visitor> void enumerateFields_gen(DirectivePragma obj,  Visitor & vis) {
  vis(obj.operands(),"operands");
}

template <typename Visitor> void enumerateFields_gen(DirectiveVariable obj,  Visitor & vis) {
  vis(obj.name(),"name");
  vis(obj.init(),"init");
  vis(obj.type(),"type");
  vis(obj.segment(),"segment");
  vis(obj.align(),"align");
  enumerateFields(obj.dim(), vis);
  enumerateFields(obj.modifier(), vis);
  vis(obj.linkage(),"linkage");
  vis(obj.allocation(),"allocation");
}

template <typename Visitor> void enumerateFields_gen(DirectiveVersion obj,  Visitor & vis) {
  vis(obj.hsailMajor(),"hsailMajor");
  vis(obj.hsailMinor(),"hsailMinor");
  vis(obj.brigMajor(),"brigMajor");
  vis(obj.brigMinor(),"brigMinor");
  vis(obj.profile(),"profile");
  vis(obj.machineModel(),"machineModel");
}

template <typename Visitor> void enumerateFields_gen(InstAddr obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.segment(),"segment");
}

template <typename Visitor> void enumerateFields_gen(InstAtomic obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.segment(),"segment");
  vis(obj.memoryOrder(),"memoryOrder");
  vis(obj.memoryScope(),"memoryScope");
  vis(obj.atomicOperation(),"atomicOperation");
  vis(obj.equivClass(),"equivClass");
}

template <typename Visitor> void enumerateFields_gen(InstBasic obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
}

template <typename Visitor> void enumerateFields_gen(InstBr obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.width(),"width");
}

template <typename Visitor> void enumerateFields_gen(InstCmp obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.sourceType(),"sourceType");
  enumerateFields(obj.modifier(), vis);
  vis(obj.compare(),"compare");
  vis(obj.pack(),"pack");
}

template <typename Visitor> void enumerateFields_gen(InstCvt obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.sourceType(),"sourceType");
  enumerateFields(obj.modifier(), vis);
}

template <typename Visitor> void enumerateFields_gen(InstImage obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.imageType(),"imageType");
  vis(obj.coordType(),"coordType");
  vis(obj.geometry(),"geometry");
  vis(obj.equivClass(),"equivClass");
}

template <typename Visitor> void enumerateFields_gen(InstLane obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.sourceType(),"sourceType");
  vis(obj.width(),"width");
}

template <typename Visitor> void enumerateFields_gen(InstMem obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.segment(),"segment");
  vis(obj.align(),"align");
  vis(obj.equivClass(),"equivClass");
  vis(obj.width(),"width");
  enumerateFields(obj.modifier(), vis);
}

template <typename Visitor> void enumerateFields_gen(InstMemFence obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.memoryOrder(),"memoryOrder");
  vis(obj.globalSegmentMemoryScope(),"globalSegmentMemoryScope");
  vis(obj.groupSegmentMemoryScope(),"groupSegmentMemoryScope");
  vis(obj.imageSegmentMemoryScope(),"imageSegmentMemoryScope");
}

template <typename Visitor> void enumerateFields_gen(InstMod obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  enumerateFields(obj.modifier(), vis);
  vis(obj.pack(),"pack");
}

template <typename Visitor> void enumerateFields_gen(InstQueryImage obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.imageType(),"imageType");
  vis(obj.geometry(),"geometry");
  vis(obj.imageQuery(),"imageQuery");
}

template <typename Visitor> void enumerateFields_gen(InstQuerySampler obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.samplerQuery(),"samplerQuery");
}

template <typename Visitor> void enumerateFields_gen(InstQueue obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.segment(),"segment");
  vis(obj.memoryOrder(),"memoryOrder");
}

template <typename Visitor> void enumerateFields_gen(InstSeg obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.segment(),"segment");
}

template <typename Visitor> void enumerateFields_gen(InstSegCvt obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.sourceType(),"sourceType");
  vis(obj.segment(),"segment");
  enumerateFields(obj.modifier(), vis);
}

template <typename Visitor> void enumerateFields_gen(InstSignal obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.signalType(),"signalType");
  vis(obj.memoryOrder(),"memoryOrder");
  vis(obj.signalOperation(),"signalOperation");
}

template <typename Visitor> void enumerateFields_gen(InstSourceType obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  vis(obj.operands(),"operands");
  vis(obj.sourceType(),"sourceType");
}

template <typename Visitor> void enumerateFields_gen(ExecutableModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.isDefinition(),"isDefinition");
}

template <typename Visitor> void enumerateFields_gen(MemoryModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.isConst(),"isConst");
}

template <typename Visitor> void enumerateFields_gen(OperandAddress obj,  Visitor & vis) {
  vis(obj.symbol(),"symbol");
  vis(obj.reg(),"reg");
  enumerateFields(obj.offset(), vis);
}

template <typename Visitor> void enumerateFields_gen(OperandCodeList obj,  Visitor & vis) {
  vis(obj.elements(),"elements");
}

template <typename Visitor> void enumerateFields_gen(OperandCodeRef obj,  Visitor & vis) {
  vis(obj.ref(),"ref");
}

template <typename Visitor> void enumerateFields_gen(OperandData obj,  Visitor & vis) {
  vis(obj.data(),"data");
}

template <typename Visitor> void enumerateFields_gen(OperandImageProperties obj,  Visitor & vis) {
  enumerateFields(obj.width(), vis);
  enumerateFields(obj.height(), vis);
  enumerateFields(obj.depth(), vis);
  enumerateFields(obj.array(), vis);
  vis(obj.geometry(),"geometry");
  vis(obj.channelOrder(),"channelOrder");
  vis(obj.channelType(),"channelType");
}

template <typename Visitor> void enumerateFields_gen(OperandOperandList obj,  Visitor & vis) {
  vis(obj.elements(),"elements");
}

template <typename Visitor> void enumerateFields_gen(OperandReg obj,  Visitor & vis) {
  vis(obj.regKind(),"regKind");
  vis(obj.regNum(),"regNum");
}

template <typename Visitor> void enumerateFields_gen(OperandSamplerProperties obj,  Visitor & vis) {
  vis(obj.coord(),"coord");
  vis(obj.filter(),"filter");
  vis(obj.addressing(),"addressing");
}

template <typename Visitor> void enumerateFields_gen(OperandString obj,  Visitor & vis) {
  vis(obj.string(),"string");
}

template <typename Visitor> void enumerateFields_gen(OperandWavesize obj,  Visitor & vis) {
}

template <typename Visitor> void enumerateFields_gen(SegCvtModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.isNoNull(),"isNoNull");
}

template <typename Visitor> void enumerateFields_gen(UInt64 obj,  Visitor & vis) {
  vis(obj.lo(),"lo");
  vis(obj.hi(),"hi");
}

template <typename Visitor> void enumerateFields_gen(VariableModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.isDefinition(),"isDefinition");
  vis(obj.isConst(),"isConst");
  vis(obj.isArray(),"isArray");
  vis(obj.isFlexArray(),"isFlexArray");
}

