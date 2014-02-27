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
RetType dispatchByItemKind_gen(Directive item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_DIRECTIVE_ARG_SCOPE_END: return vis(DirectiveArgScopeEnd(item));
	case BRIG_DIRECTIVE_ARG_SCOPE_START: return vis(DirectiveArgScopeStart(item));
	case BRIG_DIRECTIVE_BLOCK_END: return vis(BlockEnd(item));
	case BRIG_DIRECTIVE_BLOCK_NUMERIC: return vis(BlockNumeric(item));
	case BRIG_DIRECTIVE_BLOCK_START: return vis(BlockStart(item));
	case BRIG_DIRECTIVE_BLOCK_STRING: return vis(BlockString(item));
	case BRIG_DIRECTIVE_COMMENT: return vis(DirectiveComment(item));
	case BRIG_DIRECTIVE_CONTROL: return vis(DirectiveControl(item));
	case BRIG_DIRECTIVE_EXTENSION: return vis(DirectiveExtension(item));
	case BRIG_DIRECTIVE_FBARRIER: return vis(DirectiveFbarrier(item));
	case BRIG_DIRECTIVE_FUNCTION: return vis(DirectiveFunction(item));
	case BRIG_DIRECTIVE_IMAGE_INIT: return vis(DirectiveImageInit(item));
	case BRIG_DIRECTIVE_KERNEL: return vis(DirectiveKernel(item));
	case BRIG_DIRECTIVE_LABEL: return vis(DirectiveLabel(item));
	case BRIG_DIRECTIVE_LABEL_INIT: return vis(DirectiveLabelInit(item));
	case BRIG_DIRECTIVE_LABEL_TARGETS: return vis(DirectiveLabelTargets(item));
	case BRIG_DIRECTIVE_LOC: return vis(DirectiveLoc(item));
	case BRIG_DIRECTIVE_PRAGMA: return vis(DirectivePragma(item));
	case BRIG_DIRECTIVE_SAMPLER_INIT: return vis(DirectiveSamplerInit(item));
	case BRIG_DIRECTIVE_SIGNATURE: return vis(DirectiveSignature(item));
	case BRIG_DIRECTIVE_VARIABLE: return vis(DirectiveVariable(item));
	case BRIG_DIRECTIVE_VARIABLE_INIT: return vis(DirectiveVariableInit(item));
	case BRIG_DIRECTIVE_VERSION: return vis(DirectiveVersion(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(DirectiveCode item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_DIRECTIVE_ARG_SCOPE_END: return vis(DirectiveArgScopeEnd(item));
	case BRIG_DIRECTIVE_ARG_SCOPE_START: return vis(DirectiveArgScopeStart(item));
	case BRIG_DIRECTIVE_BLOCK_START: return vis(BlockStart(item));
	case BRIG_DIRECTIVE_COMMENT: return vis(DirectiveComment(item));
	case BRIG_DIRECTIVE_CONTROL: return vis(DirectiveControl(item));
	case BRIG_DIRECTIVE_EXTENSION: return vis(DirectiveExtension(item));
	case BRIG_DIRECTIVE_FBARRIER: return vis(DirectiveFbarrier(item));
	case BRIG_DIRECTIVE_FUNCTION: return vis(DirectiveFunction(item));
	case BRIG_DIRECTIVE_IMAGE_INIT: return vis(DirectiveImageInit(item));
	case BRIG_DIRECTIVE_KERNEL: return vis(DirectiveKernel(item));
	case BRIG_DIRECTIVE_LABEL: return vis(DirectiveLabel(item));
	case BRIG_DIRECTIVE_LABEL_INIT: return vis(DirectiveLabelInit(item));
	case BRIG_DIRECTIVE_LABEL_TARGETS: return vis(DirectiveLabelTargets(item));
	case BRIG_DIRECTIVE_LOC: return vis(DirectiveLoc(item));
	case BRIG_DIRECTIVE_PRAGMA: return vis(DirectivePragma(item));
	case BRIG_DIRECTIVE_SIGNATURE: return vis(DirectiveSignature(item));
	case BRIG_DIRECTIVE_VARIABLE: return vis(DirectiveVariable(item));
	case BRIG_DIRECTIVE_VARIABLE_INIT: return vis(DirectiveVariableInit(item));
	case BRIG_DIRECTIVE_VERSION: return vis(DirectiveVersion(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(DirectiveCallableBase item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_DIRECTIVE_FUNCTION: return vis(DirectiveFunction(item));
	case BRIG_DIRECTIVE_KERNEL: return vis(DirectiveKernel(item));
	case BRIG_DIRECTIVE_SIGNATURE: return vis(DirectiveSignature(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(DirectiveExecutable item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_DIRECTIVE_FUNCTION: return vis(DirectiveFunction(item));
	case BRIG_DIRECTIVE_KERNEL: return vis(DirectiveKernel(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(Inst item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_INST_ADDR: return vis(InstAddr(item));
	case BRIG_INST_ATOMIC: return vis(InstAtomic(item));
	case BRIG_INST_ATOMIC_IMAGE: return vis(InstAtomicImage(item));
	case BRIG_INST_BASIC: return vis(InstBasic(item));
	case BRIG_INST_BR: return vis(InstBr(item));
	case BRIG_INST_CMP: return vis(InstCmp(item));
	case BRIG_INST_CVT: return vis(InstCvt(item));
	case BRIG_INST_IMAGE: return vis(InstImage(item));
	case BRIG_INST_LANE: return vis(InstLane(item));
	case BRIG_INST_MEM: return vis(InstMem(item));
	case BRIG_INST_MEM_FENCE: return vis(InstMemFence(item));
	case BRIG_INST_MOD: return vis(InstMod(item));
	case BRIG_INST_QUEUE: return vis(InstQueue(item));
	case BRIG_INST_SEG: return vis(InstSeg(item));
	case BRIG_INST_SEG_CVT: return vis(InstSegCvt(item));
	case BRIG_INST_SIGNAL: return vis(InstSignal(item));
	case BRIG_INST_SOURCE_TYPE: return vis(InstSourceType(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(Operand item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_OPERAND_ADDRESS: return vis(OperandAddress(item));
	case BRIG_OPERAND_ARGUMENT_LIST: return vis(OperandArgumentList(item));
	case BRIG_OPERAND_FBARRIER_REF: return vis(OperandFbarrierRef(item));
	case BRIG_OPERAND_FUNCTION_LIST: return vis(OperandFunctionList(item));
	case BRIG_OPERAND_FUNCTION_REF: return vis(OperandFunctionRef(item));
	case BRIG_OPERAND_IMMED: return vis(OperandImmed(item));
	case BRIG_OPERAND_LABEL_REF: return vis(OperandLabelRef(item));
	case BRIG_OPERAND_LABEL_TARGETS_REF: return vis(OperandLabelTargetsRef(item));
	case BRIG_OPERAND_LABEL_VARIABLE_REF: return vis(OperandLabelVariableRef(item));
	case BRIG_OPERAND_REG: return vis(OperandReg(item));
	case BRIG_OPERAND_REG_VECTOR: return vis(OperandRegVector(item));
	case BRIG_OPERAND_SIGNATURE_REF: return vis(OperandSignatureRef(item));
	case BRIG_OPERAND_WAVESIZE: return vis(OperandWavesize(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(OperandList item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_OPERAND_ARGUMENT_LIST: return vis(OperandArgumentList(item));
	case BRIG_OPERAND_FUNCTION_LIST: return vis(OperandFunctionList(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename RetType, typename Visitor>
RetType dispatchByItemKind_gen(OperandRef item,Visitor& vis) {
	using namespace Brig;
	switch(item.brig()->kind) {
	case BRIG_OPERAND_FBARRIER_REF: return vis(OperandFbarrierRef(item));
	case BRIG_OPERAND_FUNCTION_REF: return vis(OperandFunctionRef(item));
	case BRIG_OPERAND_LABEL_REF: return vis(OperandLabelRef(item));
	case BRIG_OPERAND_LABEL_TARGETS_REF: return vis(OperandLabelTargetsRef(item));
	case BRIG_OPERAND_LABEL_VARIABLE_REF: return vis(OperandLabelVariableRef(item));
	case BRIG_OPERAND_SIGNATURE_REF: return vis(OperandSignatureRef(item));
	default: assert(false); break;
	}
	return RetType();
}

template <typename Visitor> void enumerateFields_gen(AluModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.round(),"round");
  vis(obj.ftz(),"ftz");
}

template <typename Visitor> void enumerateFields_gen(BlockEnd obj,  Visitor & vis) {
}

template <typename Visitor> void enumerateFields_gen(BlockNumeric obj,  Visitor & vis) {
  vis(obj.type(),"type");
  vis(obj.elementCount(),"elementCount");
}

template <typename Visitor> void enumerateFields_gen(BlockString obj,  Visitor & vis) {
  vis(obj.string(),"string");
}

template <typename Visitor> void enumerateFields_gen(BlockStart obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
}

template <typename Visitor> void enumerateFields_gen(DirectiveArgScopeEnd obj,  Visitor & vis) {
  vis(obj.code(),"code");
}

template <typename Visitor> void enumerateFields_gen(DirectiveArgScopeStart obj,  Visitor & vis) {
  vis(obj.code(),"code");
}

template <typename Visitor> void enumerateFields_gen(DirectiveFunction obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
  vis(obj.inArgCount(),"inArgCount");
  vis(obj.outArgCount(),"outArgCount");
  vis(obj.firstInArg(),"firstInArg");
  vis(obj.firstScopedDirective(),"firstScopedDirective");
  vis(obj.nextTopLevelDirective(),"nextTopLevelDirective");
  vis(obj.instCount(),"instCount");
  enumerateFields(obj.modifier(), vis);
}

template <typename Visitor> void enumerateFields_gen(DirectiveKernel obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
  vis(obj.inArgCount(),"inArgCount");
  vis(obj.outArgCount(),"outArgCount");
  vis(obj.firstInArg(),"firstInArg");
  vis(obj.firstScopedDirective(),"firstScopedDirective");
  vis(obj.nextTopLevelDirective(),"nextTopLevelDirective");
  vis(obj.instCount(),"instCount");
  enumerateFields(obj.modifier(), vis);
}

template <typename Visitor> void enumerateFields_gen(DirectiveSignature obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
  vis(obj.inCount(),"inArgCount");
  vis(obj.outCount(),"outArgCount");
  vis(obj.args(),"args");
}

template <typename Visitor> void enumerateFields_gen(DirectiveComment obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
}

template <typename Visitor> void enumerateFields_gen(DirectiveControl obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.control(),"control");
  vis(obj.type(),"type");
  vis(obj.elementCount(),"valueCount");
  vis(obj.values(),"values");
}

template <typename Visitor> void enumerateFields_gen(DirectiveExtension obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
}

template <typename Visitor> void enumerateFields_gen(DirectiveFbarrier obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
}

template <typename Visitor> void enumerateFields_gen(DirectiveImageInit obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.width(),"width");
  vis(obj.height(),"height");
  vis(obj.depth(),"depth");
  vis(obj.array(),"array");
  vis(obj.geometry(),"geometry");
  vis(obj.order(),"order");
  vis(obj.format(),"format");
}

template <typename Visitor> void enumerateFields_gen(DirectiveLabel obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
}

template <typename Visitor> void enumerateFields_gen(DirectiveLabelInit obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.elementCount(),"labelCount");
  vis(obj.labels(),"labels");
}

template <typename Visitor> void enumerateFields_gen(DirectiveLabelTargets obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
  vis(obj.elementCount(),"labelCount");
  vis(obj.labels(),"labels");
}

template <typename Visitor> void enumerateFields_gen(DirectiveLoc obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.filename(),"filename");
  vis(obj.line(),"line");
  vis(obj.column(),"column");
}

template <typename Visitor> void enumerateFields_gen(DirectivePragma obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
}

template <typename Visitor> void enumerateFields_gen(DirectiveVariable obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.name(),"name");
  vis(obj.init(),"init");
  vis(obj.type(),"type");
  vis(obj.segment(),"segment");
  vis(obj.align(),"align");
  vis(obj.dimLo(),"dimLo");
  vis(obj.dim(),"dim");
  vis(obj.dimHi(),"dimHi");
  enumerateFields(obj.modifier(), vis);
}

template <typename Visitor> void enumerateFields_gen(DirectiveVariableInit obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.elementCount(),"elementCount");
  vis(obj.type(),"type");
}

template <typename Visitor> void enumerateFields_gen(DirectiveVersion obj,  Visitor & vis) {
  vis(obj.code(),"code");
  vis(obj.profile(),"profile");
  vis(obj.machineModel(),"machineModel");
}

template <typename Visitor> void enumerateFields_gen(DirectiveSamplerInit obj,  Visitor & vis) {
  enumerateFields(obj.modifier(), vis);
  vis(obj.boundaryU(),"boundaryU");
  vis(obj.boundaryV(),"boundaryV");
  vis(obj.boundaryW(),"boundaryW");
}

template <typename Visitor> void enumerateFields_gen(DirectiveSignatureArgument obj,  Visitor & vis) {
  vis(obj.type(),"type");
  vis(obj.align(),"align");
  enumerateFields(obj.modifier(), vis);
  vis(obj.dimLo(),"dimLo");
  vis(obj.dim(),"dim");
  vis(obj.dimHi(),"dimHi");
}

template <typename Visitor> void enumerateFields_gen(ExecutableModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.linkage(),"linkage");
  vis(obj.isDeclaration(),"isDeclaration");
}

template <typename Visitor> void enumerateFields_gen(InstAddr obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.segment(),"segment");
}

template <typename Visitor> void enumerateFields_gen(InstAtomic obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.segment(),"segment");
  vis(obj.memoryOrder(),"memoryOrder");
  vis(obj.memoryScope(),"memoryScope");
  vis(obj.atomicOperation(),"atomicOperation");
  vis(obj.equivClass(),"equivClass");
}

template <typename Visitor> void enumerateFields_gen(InstAtomicImage obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.imageType(),"imageType");
  vis(obj.coordType(),"coordType");
  vis(obj.geometry(),"geometry");
  vis(obj.atomicOperation(),"atomicOperation");
  vis(obj.equivClass(),"equivClass");
}

template <typename Visitor> void enumerateFields_gen(InstBasic obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
}

template <typename Visitor> void enumerateFields_gen(InstBr obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.width(),"width");
}

template <typename Visitor> void enumerateFields_gen(InstCmp obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.sourceType(),"sourceType");
  enumerateFields(obj.modifier(), vis);
  vis(obj.compare(),"compare");
  vis(obj.pack(),"pack");
}

template <typename Visitor> void enumerateFields_gen(InstCvt obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.sourceType(),"sourceType");
  enumerateFields(obj.modifier(), vis);
}

template <typename Visitor> void enumerateFields_gen(InstImage obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.imageType(),"imageType");
  vis(obj.coordType(),"coordType");
  vis(obj.geometry(),"geometry");
  vis(obj.equivClass(),"equivClass");
}

template <typename Visitor> void enumerateFields_gen(InstLane obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.sourceType(),"sourceType");
  vis(obj.width(),"width");
}

template <typename Visitor> void enumerateFields_gen(InstMem obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.segment(),"segment");
  vis(obj.align(),"align");
  vis(obj.equivClass(),"equivClass");
  vis(obj.width(),"width");
  enumerateFields(obj.modifier(), vis);
}

template <typename Visitor> void enumerateFields_gen(InstMemFence obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.segments(),"segments");
  vis(obj.memoryOrder(),"memoryOrder");
  vis(obj.memoryScope(),"memoryScope");
}

template <typename Visitor> void enumerateFields_gen(InstMod obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  enumerateFields(obj.modifier(), vis);
  vis(obj.pack(),"pack");
}

template <typename Visitor> void enumerateFields_gen(InstQueue obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operands(i),"operands", i);
  }
  vis(obj.segment(),"segment");
  vis(obj.memoryOrder(),"memoryOrder");
}

template <typename Visitor> void enumerateFields_gen(InstSeg obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.segment(),"segment");
}

template <typename Visitor> void enumerateFields_gen(InstSegCvt obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operands(i),"operands", i);
  }
  vis(obj.sourceType(),"sourceType");
  vis(obj.segment(),"segment");
  enumerateFields(obj.modifier(), vis);
}

template <typename Visitor> void enumerateFields_gen(InstSignal obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operand(i),"operands", i);
  }
  vis(obj.signalType(),"signalType");
  vis(obj.memoryOrder(),"memoryOrder");
  vis(obj.signalOperation(),"signalOperation");
}

template <typename Visitor> void enumerateFields_gen(InstSourceType obj,  Visitor & vis) {
  vis(obj.opcode(),"opcode");
  vis(obj.type(),"type");
  for (unsigned i=0;i<5;i++) {
    vis(obj.operands(i),"operands", i);
  }
  vis(obj.sourceType(),"sourceType");
}

template <typename Visitor> void enumerateFields_gen(InstNone obj,  Visitor & vis) {
}

template <typename Visitor> void enumerateFields_gen(MemoryModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.isConst(),"isConst");
}

template <typename Visitor> void enumerateFields_gen(OperandAddress obj,  Visitor & vis) {
  vis(obj.symbol(),"symbol");
  vis(obj.reg(),"reg");
  vis(obj.offsetLo(),"offsetLo");
  vis(obj.offset(),"offset");
  vis(obj.offsetHi(),"offsetHi");
}

template <typename Visitor> void enumerateFields_gen(OperandImmed obj,  Visitor & vis) {
  vis(obj.byteCount(),"byteCount");
}

template <typename Visitor> void enumerateFields_gen(OperandArgumentList obj,  Visitor & vis) {
  vis(obj.elementCount(),"elementCount");
  vis(obj.elements(),"elements");
}

template <typename Visitor> void enumerateFields_gen(OperandFunctionList obj,  Visitor & vis) {
  vis(obj.elementCount(),"elementCount");
  vis(obj.elements(),"elements");
}

template <typename Visitor> void enumerateFields_gen(OperandFbarrierRef obj,  Visitor & vis) {
  vis(obj.fbar(),"ref");
}

template <typename Visitor> void enumerateFields_gen(OperandFunctionRef obj,  Visitor & vis) {
  vis(obj.fn(),"ref");
}

template <typename Visitor> void enumerateFields_gen(OperandLabelRef obj,  Visitor & vis) {
  vis(obj.label(),"label");
}

template <typename Visitor> void enumerateFields_gen(OperandLabelTargetsRef obj,  Visitor & vis) {
  vis(obj.targets(),"targets");
}

template <typename Visitor> void enumerateFields_gen(OperandLabelVariableRef obj,  Visitor & vis) {
  vis(obj.symbol(),"symbol");
}

template <typename Visitor> void enumerateFields_gen(OperandSignatureRef obj,  Visitor & vis) {
  vis(obj.sig(),"ref");
}

template <typename Visitor> void enumerateFields_gen(OperandReg obj,  Visitor & vis) {
  vis(obj.reg(),"reg");
}

template <typename Visitor> void enumerateFields_gen(OperandRegVector obj,  Visitor & vis) {
  vis(obj.regCount(),"regCount");
  vis(obj.elementCount(),"elementCount");
  vis(obj.regs(),"regs");
}

template <typename Visitor> void enumerateFields_gen(OperandWavesize obj,  Visitor & vis) {
}

template <typename Visitor> void enumerateFields_gen(SamplerModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.filter(),"filter");
  vis(obj.isUnnormalized(),"isUnnormalized");
}

template <typename Visitor> void enumerateFields_gen(SegCvtModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.isNoNull(),"isNoNull");
}

template <typename Visitor> void enumerateFields_gen(SymbolModifier obj,  Visitor & vis) {
  vis(obj.allBits(),"allBits");
  vis(obj.linkage(),"linkage");
  vis(obj.isDeclaration(),"isDeclaration");
  vis(obj.isConst(),"isConst");
  vis(obj.isArray(),"isArray");
  vis(obj.isFlexArray(),"isFlexArray");
}

