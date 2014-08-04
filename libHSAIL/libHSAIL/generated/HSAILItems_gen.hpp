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
class AluModifier;
class Code;
class Directive;
class DirectiveArgBlockEnd;
class DirectiveArgBlockStart;
class DirectiveComment;
class DirectiveControl;
class DirectiveExecutable;
class DirectiveFunction;
class DirectiveIndirectFunction;
class DirectiveKernel;
class DirectiveSignature;
class DirectiveExtension;
class DirectiveFbarrier;
class DirectiveLabel;
class DirectiveLoc;
class DirectiveNone;
class DirectivePragma;
class DirectiveVariable;
class DirectiveVersion;
class Inst;
class InstAddr;
class InstAtomic;
class InstBasic;
class InstBr;
class InstCmp;
class InstCvt;
class InstImage;
class InstLane;
class InstMem;
class InstMemFence;
class InstMod;
class InstQueryImage;
class InstQuerySampler;
class InstQueue;
class InstSeg;
class InstSegCvt;
class InstSignal;
class InstSourceType;
class ExecutableModifier;
class MemoryModifier;
class Operand;
class OperandAddress;
class OperandCodeList;
class OperandCodeRef;
class OperandData;
class OperandImageProperties;
class OperandOperandList;
class OperandReg;
class OperandSamplerProperties;
class OperandString;
class OperandWavesize;
class SegCvtModifier;
class UInt64;
class VariableModifier;


class AluModifier : public ItemBase {
public:

	/// accessors
	ValRef<uint16_t>                                   allBits();
	BFValRef<Brig::BrigRound8_t,0,5>                   round();
	BitValRef<5>                                       ftz();


	/// constructors
	AluModifier()                           : ItemBase() { } 
	AluModifier(MySection* s, Offset o)     : ItemBase(s, o) { } 
	AluModifier(const AluModifier& rhs) : ItemBase(rhs) { } 
	AluModifier& operator=(const AluModifier& rhs) { reset(rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigAluModifier BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "AluModifier"; }
	void initBrig(); 
};

class Code : public ItemBase {
    // children: BrigDirectiveLabel,BrigInstSignal,BrigDirectiveExtension,BrigDirectiveVariable,BrigDirectiveArgBlockStart,BrigInstMemFence,BrigDirectiveControl,BrigDirectiveSignature,BrigDirectiveVersion,BrigInstAtomic,BrigDirectiveNone,BrigInstSourceType,BrigInstImage,BrigInstBr,BrigDirectiveKernel,BrigInstSeg,BrigInstMem,BrigInstCmp,BrigDirectiveExecutable,BrigDirectiveIndirectFunction,BrigInst,BrigDirective,BrigInstSegCvt,BrigDirectiveFunction,BrigInstAddr,BrigInstCvt,BrigInstQuerySampler,BrigDirectiveArgBlockEnd,BrigDirectiveLoc,BrigInstQueryImage,BrigInstMod,BrigInstBasic,BrigDirectiveComment,BrigDirectivePragma,BrigDirectiveFbarrier,BrigInstQueue,BrigInstLane
public:

	typedef Code Kind;

	enum { SECTION = Brig::BRIG_SECTION_INDEX_CODE };

	/// accessors
	ValRef<uint16_t>                                   byteCount();
	EnumValRef<Brig::BrigKinds,uint16_t>               kind();


	/// constructors
	Code()                           : ItemBase() { } 
	Code(MySection* s, Offset o)     : ItemBase(s, o) { } 
	Code(BrigContainer* c, Offset o) : ItemBase(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_LABEL
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_SIGNAL
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_EXTENSION
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_VARIABLE
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_START
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_MEM_FENCE
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_CONTROL
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_SIGNATURE
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_VERSION
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_ATOMIC
		    || rhs.brig()->kind == Brig::BRIG_KIND_NONE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_SOURCE_TYPE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_IMAGE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_BR
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_KERNEL
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_SEG
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_MEM
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_CMP
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_SEG_CVT
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_FUNCTION
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_ADDR
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_CVT
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_QUERY_SAMPLER
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_END
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_LOC
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_QUERY_IMAGE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_MOD
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_BASIC
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_COMMENT
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_PRAGMA
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_FBARRIER
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_QUEUE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_LANE;
	}
	Code(const ItemBase& rhs) { assignItem(*this,rhs); } 
	Code& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigCode BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// root utilities
	Offset  brigSize() const { return brig()->byteCount; }
	Code next() const { return Code(section(), brigOffset() + brigSize()); }
};

class Directive : public Code {
    // children: BrigDirectiveLabel,BrigDirectiveExtension,BrigDirectiveVariable,BrigDirectiveArgBlockStart,BrigDirectiveControl,BrigDirectiveFunction,BrigDirectiveSignature,BrigDirectiveArgBlockEnd,BrigDirectiveLoc,BrigDirectiveVersion,BrigDirectiveNone,BrigDirectiveComment,BrigDirectivePragma,BrigDirectiveFbarrier,BrigDirectiveKernel,BrigDirectiveIndirectFunction,BrigDirectiveExecutable
public:

	/// accessors


	/// constructors
	Directive()                           : Code() { } 
	Directive(MySection* s, Offset o)     : Code(s, o) { } 
	Directive(BrigContainer* c, Offset o) : Code(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_LABEL
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_EXTENSION
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_VARIABLE
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_START
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_CONTROL
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_FUNCTION
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_SIGNATURE
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_END
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_LOC
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_VERSION
		    || rhs.brig()->kind == Brig::BRIG_KIND_NONE
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_COMMENT
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_PRAGMA
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_FBARRIER
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_KERNEL
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION;
	}
	Directive(const ItemBase& rhs) { assignItem(*this,rhs); } 
	Directive& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirective BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }
};

class DirectiveArgBlockEnd : public Directive {
public:

	/// accessors


	/// constructors
	DirectiveArgBlockEnd()                           : Directive() { } 
	DirectiveArgBlockEnd(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveArgBlockEnd(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_END;
	}
	DirectiveArgBlockEnd(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveArgBlockEnd& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveArgBlockEnd BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveArgBlockEnd"; }
	void initBrig(); 
};

class DirectiveArgBlockStart : public Directive {
public:

	/// accessors


	/// constructors
	DirectiveArgBlockStart()                           : Directive() { } 
	DirectiveArgBlockStart(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveArgBlockStart(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_ARG_BLOCK_START;
	}
	DirectiveArgBlockStart(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveArgBlockStart& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveArgBlockStart BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveArgBlockStart"; }
	void initBrig(); 
};

class DirectiveComment : public Directive {
public:

	/// accessors
	StrRef                                             name();


	/// constructors
	DirectiveComment()                           : Directive() { } 
	DirectiveComment(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveComment(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_COMMENT;
	}
	DirectiveComment(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveComment& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveComment BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveComment"; }
	void initBrig(); 
};

class DirectiveControl : public Directive {
public:

	/// accessors
	EnumValRef<Brig::BrigControlDirective,uint16_t>    control();
	ListRef<Operand>                                   operands();


	/// constructors
	DirectiveControl()                           : Directive() { } 
	DirectiveControl(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveControl(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_CONTROL;
	}
	DirectiveControl(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveControl& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveControl BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveControl"; }
	void initBrig(); 
};

class DirectiveExecutable : public Directive {
    // children: BrigDirectiveKernel,BrigDirectiveSignature,BrigDirectiveIndirectFunction,BrigDirectiveFunction
public:

	/// accessors
	StrRef                                             name();
	ValRef<uint16_t>                                   outArgCount();
	ValRef<uint16_t>                                   inArgCount();
	ItemRef<Code>                                      firstInArg();
	ItemRef<Code>                                      firstCodeBlockEntry();
	ItemRef<Code>                                      nextModuleEntry();
	ValRef<uint32_t>                                   codeBlockEntryCount();
	ExecutableModifier                                 modifier();
	EnumValRef<Brig::BrigLinkage,uint8_t>              linkage();


	/// constructors
	DirectiveExecutable()                           : Directive() { } 
	DirectiveExecutable(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveExecutable(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_KERNEL
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_SIGNATURE
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION
		    || rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_FUNCTION;
	}
	DirectiveExecutable(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveExecutable& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveExecutable BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }
};

class DirectiveFunction : public DirectiveExecutable {
public:

	/// accessors


	/// constructors
	DirectiveFunction()                           : DirectiveExecutable() { } 
	DirectiveFunction(MySection* s, Offset o)     : DirectiveExecutable(s, o) { } 
	DirectiveFunction(BrigContainer* c, Offset o) : DirectiveExecutable(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_FUNCTION;
	}
	DirectiveFunction(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveFunction& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveFunction BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveFunction"; }
	void initBrig(); 
};

class DirectiveIndirectFunction : public DirectiveExecutable {
public:

	/// accessors


	/// constructors
	DirectiveIndirectFunction()                           : DirectiveExecutable() { } 
	DirectiveIndirectFunction(MySection* s, Offset o)     : DirectiveExecutable(s, o) { } 
	DirectiveIndirectFunction(BrigContainer* c, Offset o) : DirectiveExecutable(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION;
	}
	DirectiveIndirectFunction(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveIndirectFunction& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveIndirectFunction BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveIndirectFunction"; }
	void initBrig(); 
};

class DirectiveKernel : public DirectiveExecutable {
public:

	/// accessors


	/// constructors
	DirectiveKernel()                           : DirectiveExecutable() { } 
	DirectiveKernel(MySection* s, Offset o)     : DirectiveExecutable(s, o) { } 
	DirectiveKernel(BrigContainer* c, Offset o) : DirectiveExecutable(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_KERNEL;
	}
	DirectiveKernel(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveKernel& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveKernel BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveKernel"; }
	void initBrig(); 
};

class DirectiveSignature : public DirectiveExecutable {
public:

	/// accessors


	/// constructors
	DirectiveSignature()                           : DirectiveExecutable() { } 
	DirectiveSignature(MySection* s, Offset o)     : DirectiveExecutable(s, o) { } 
	DirectiveSignature(BrigContainer* c, Offset o) : DirectiveExecutable(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_SIGNATURE;
	}
	DirectiveSignature(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveSignature& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveSignature BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveSignature"; }
	void initBrig(); 
};

class DirectiveExtension : public Directive {
public:

	/// accessors
	StrRef                                             name();


	/// constructors
	DirectiveExtension()                           : Directive() { } 
	DirectiveExtension(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveExtension(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_EXTENSION;
	}
	DirectiveExtension(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveExtension& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveExtension BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveExtension"; }
	void initBrig(); 
};

class DirectiveFbarrier : public Directive {
public:

	/// accessors
	StrRef                                             name();
	ExecutableModifier                                 modifier();
	EnumValRef<Brig::BrigLinkage,uint8_t>              linkage();


	/// constructors
	DirectiveFbarrier()                           : Directive() { } 
	DirectiveFbarrier(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveFbarrier(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_FBARRIER;
	}
	DirectiveFbarrier(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveFbarrier& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveFbarrier BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveFbarrier"; }
	void initBrig(); 
};

class DirectiveLabel : public Directive {
public:

	/// accessors
	StrRef                                             name();


	/// constructors
	DirectiveLabel()                           : Directive() { } 
	DirectiveLabel(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveLabel(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_LABEL;
	}
	DirectiveLabel(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveLabel& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveLabel BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveLabel"; }
	void initBrig(); 
};

class DirectiveLoc : public Directive {
public:

	/// accessors
	StrRef                                             filename();
	ValRef<uint32_t>                                   line();
	ValRef<uint32_t>                                   column();


	/// constructors
	DirectiveLoc()                           : Directive() { } 
	DirectiveLoc(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveLoc(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_LOC;
	}
	DirectiveLoc(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveLoc& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveLoc BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveLoc"; }
	void initBrig(); 
};

class DirectiveNone : public Directive {
public:

	/// accessors


	/// constructors
	DirectiveNone()                           : Directive() { } 
	DirectiveNone(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveNone(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_NONE;
	}
	DirectiveNone(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveNone& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveNone BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveNone"; }
	void initBrig(); 
};

class DirectivePragma : public Directive {
public:

	/// accessors
	ListRef<Operand>                                   operands();


	/// constructors
	DirectivePragma()                           : Directive() { } 
	DirectivePragma(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectivePragma(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_PRAGMA;
	}
	DirectivePragma(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectivePragma& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectivePragma BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectivePragma"; }
	void initBrig(); 
};

class DirectiveVariable : public Directive {
public:

	/// accessors
	StrRef                                             name();
	ItemRef<Operand>                                   init();
	ValRef<uint16_t>                                   type();
	EnumValRef<Brig::BrigSegment,uint8_t>              segment();
	EnumValRef<Brig::BrigAlignment,uint8_t>            align();
	UInt64                                             dim();
	VariableModifier                                   modifier();
	EnumValRef<Brig::BrigLinkage,uint8_t>              linkage();
	EnumValRef<Brig::BrigAllocation,uint8_t>           allocation();


	/// constructors
	DirectiveVariable()                           : Directive() { } 
	DirectiveVariable(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveVariable(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_VARIABLE;
	}
	DirectiveVariable(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveVariable& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveVariable BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveVariable"; }
	void initBrig(); 
};

class DirectiveVersion : public Directive {
public:

	/// accessors
	ValRef<uint32_t>                                   hsailMajor();
	ValRef<uint32_t>                                   hsailMinor();
	ValRef<uint32_t>                                   brigMajor();
	ValRef<uint32_t>                                   brigMinor();
	EnumValRef<Brig::BrigProfile,uint8_t>              profile();
	EnumValRef<Brig::BrigMachineModel,uint8_t>         machineModel();


	/// constructors
	DirectiveVersion()                           : Directive() { } 
	DirectiveVersion(MySection* s, Offset o)     : Directive(s, o) { } 
	DirectiveVersion(BrigContainer* c, Offset o) : Directive(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_DIRECTIVE_VERSION;
	}
	DirectiveVersion(const ItemBase& rhs) { assignItem(*this,rhs); } 
	DirectiveVersion& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigDirectiveVersion BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "DirectiveVersion"; }
	void initBrig(); 
};

class Inst : public Code {
    // children: BrigInstSignal,BrigInstMemFence,BrigInstSegCvt,BrigInstAddr,BrigInstCvt,BrigInstQuerySampler,BrigInstQueryImage,BrigInstMod,BrigInstBasic,BrigInstAtomic,BrigInstSourceType,BrigInstImage,BrigInstBr,BrigInstMem,BrigInstSeg,BrigInstQueue,BrigInstCmp,BrigInstLane
public:

	/// accessors
	EnumValRef<Brig::BrigOpcode,uint16_t>              opcode();
	ValRef<uint16_t>                                   type();
	ListRef<Operand>                                   operands();
	Operand operand(int index);


	/// constructors
	Inst()                           : Code() { } 
	Inst(MySection* s, Offset o)     : Code(s, o) { } 
	Inst(BrigContainer* c, Offset o) : Code(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_SIGNAL
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_MEM_FENCE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_SEG_CVT
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_ADDR
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_CVT
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_QUERY_SAMPLER
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_QUERY_IMAGE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_MOD
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_BASIC
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_ATOMIC
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_SOURCE_TYPE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_IMAGE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_BR
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_MEM
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_SEG
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_QUEUE
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_CMP
		    || rhs.brig()->kind == Brig::BRIG_KIND_INST_LANE;
	}
	Inst(const ItemBase& rhs) { assignItem(*this,rhs); } 
	Inst& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInst BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }
};

class InstAddr : public Inst {
public:

	/// accessors
	EnumValRef<Brig::BrigSegment,uint8_t>              segment();


	/// constructors
	InstAddr()                           : Inst() { } 
	InstAddr(MySection* s, Offset o)     : Inst(s, o) { } 
	InstAddr(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_ADDR;
	}
	InstAddr(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstAddr& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstAddr BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstAddr"; }
	void initBrig(); 
};

class InstAtomic : public Inst {
public:

	/// accessors
	EnumValRef<Brig::BrigSegment,uint8_t>              segment();
	EnumValRef<Brig::BrigMemoryOrder,uint8_t>          memoryOrder();
	EnumValRef<Brig::BrigMemoryScope,uint8_t>          memoryScope();
	EnumValRef<Brig::BrigAtomicOperation,uint8_t>      atomicOperation();
	ValRef<uint8_t>                                    equivClass();


	/// constructors
	InstAtomic()                           : Inst() { } 
	InstAtomic(MySection* s, Offset o)     : Inst(s, o) { } 
	InstAtomic(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_ATOMIC;
	}
	InstAtomic(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstAtomic& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstAtomic BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstAtomic"; }
	void initBrig(); 
};

class InstBasic : public Inst {
public:

	/// accessors


	/// constructors
	InstBasic()                           : Inst() { } 
	InstBasic(MySection* s, Offset o)     : Inst(s, o) { } 
	InstBasic(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_BASIC;
	}
	InstBasic(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstBasic& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstBasic BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstBasic"; }
	void initBrig(); 
};

class InstBr : public Inst {
public:

	/// accessors
	EnumValRef<Brig::BrigWidth,uint8_t>                width();


	/// constructors
	InstBr()                           : Inst() { } 
	InstBr(MySection* s, Offset o)     : Inst(s, o) { } 
	InstBr(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_BR;
	}
	InstBr(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstBr& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstBr BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstBr"; }
	void initBrig(); 
};

class InstCmp : public Inst {
public:

	/// accessors
	ValRef<uint16_t>                                   sourceType();
	AluModifier                                        modifier();
	EnumValRef<Brig::BrigCompareOperation,uint8_t>     compare();
	EnumValRef<Brig::BrigPack,uint8_t>                 pack();


	/// constructors
	InstCmp()                           : Inst() { } 
	InstCmp(MySection* s, Offset o)     : Inst(s, o) { } 
	InstCmp(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_CMP;
	}
	InstCmp(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstCmp& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstCmp BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstCmp"; }
	void initBrig(); 
};

class InstCvt : public Inst {
public:

	/// accessors
	ValRef<uint16_t>                                   sourceType();
	AluModifier                                        modifier();


	/// constructors
	InstCvt()                           : Inst() { } 
	InstCvt(MySection* s, Offset o)     : Inst(s, o) { } 
	InstCvt(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_CVT;
	}
	InstCvt(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstCvt& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstCvt BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstCvt"; }
	void initBrig(); 
};

class InstImage : public Inst {
public:

	/// accessors
	ValRef<uint16_t>                                   imageType();
	ValRef<uint16_t>                                   coordType();
	EnumValRef<Brig::BrigImageGeometry,uint8_t>        geometry();
	ValRef<uint8_t>                                    equivClass();


	/// constructors
	InstImage()                           : Inst() { } 
	InstImage(MySection* s, Offset o)     : Inst(s, o) { } 
	InstImage(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_IMAGE;
	}
	InstImage(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstImage& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstImage BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstImage"; }
	void initBrig(); 
};

class InstLane : public Inst {
public:

	/// accessors
	ValRef<uint16_t>                                   sourceType();
	EnumValRef<Brig::BrigWidth,uint8_t>                width();


	/// constructors
	InstLane()                           : Inst() { } 
	InstLane(MySection* s, Offset o)     : Inst(s, o) { } 
	InstLane(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_LANE;
	}
	InstLane(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstLane& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstLane BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstLane"; }
	void initBrig(); 
};

class InstMem : public Inst {
public:

	/// accessors
	EnumValRef<Brig::BrigSegment,uint8_t>              segment();
	EnumValRef<Brig::BrigAlignment,uint8_t>            align();
	ValRef<uint8_t>                                    equivClass();
	EnumValRef<Brig::BrigWidth,uint8_t>                width();
	MemoryModifier                                     modifier();


	/// constructors
	InstMem()                           : Inst() { } 
	InstMem(MySection* s, Offset o)     : Inst(s, o) { } 
	InstMem(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_MEM;
	}
	InstMem(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstMem& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstMem BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstMem"; }
	void initBrig(); 
};

class InstMemFence : public Inst {
public:

	/// accessors
	EnumValRef<Brig::BrigMemoryOrder,uint8_t>          memoryOrder();
	EnumValRef<Brig::BrigMemoryScope,uint8_t>          globalSegmentMemoryScope();
	EnumValRef<Brig::BrigMemoryScope,uint8_t>          groupSegmentMemoryScope();
	EnumValRef<Brig::BrigMemoryScope,uint8_t>          imageSegmentMemoryScope();


	/// constructors
	InstMemFence()                           : Inst() { } 
	InstMemFence(MySection* s, Offset o)     : Inst(s, o) { } 
	InstMemFence(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_MEM_FENCE;
	}
	InstMemFence(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstMemFence& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstMemFence BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstMemFence"; }
	void initBrig(); 
};

class InstMod : public Inst {
public:

	/// accessors
	AluModifier                                        modifier();
	EnumValRef<Brig::BrigPack,uint8_t>                 pack();


	/// constructors
	InstMod()                           : Inst() { } 
	InstMod(MySection* s, Offset o)     : Inst(s, o) { } 
	InstMod(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_MOD;
	}
	InstMod(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstMod& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstMod BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstMod"; }
	void initBrig(); 
};

class InstQueryImage : public Inst {
public:

	/// accessors
	ValRef<uint16_t>                                   imageType();
	EnumValRef<Brig::BrigImageGeometry,uint8_t>        geometry();
	EnumValRef<Brig::BrigImageQuery,uint8_t>           imageQuery();


	/// constructors
	InstQueryImage()                           : Inst() { } 
	InstQueryImage(MySection* s, Offset o)     : Inst(s, o) { } 
	InstQueryImage(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_QUERY_IMAGE;
	}
	InstQueryImage(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstQueryImage& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstQueryImage BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstQueryImage"; }
	void initBrig(); 
};

class InstQuerySampler : public Inst {
public:

	/// accessors
	EnumValRef<Brig::BrigSamplerQuery,uint8_t>         samplerQuery();


	/// constructors
	InstQuerySampler()                           : Inst() { } 
	InstQuerySampler(MySection* s, Offset o)     : Inst(s, o) { } 
	InstQuerySampler(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_QUERY_SAMPLER;
	}
	InstQuerySampler(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstQuerySampler& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstQuerySampler BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstQuerySampler"; }
	void initBrig(); 
};

class InstQueue : public Inst {
public:

	/// accessors
	EnumValRef<Brig::BrigSegment,uint8_t>              segment();
	EnumValRef<Brig::BrigMemoryOrder,uint8_t>          memoryOrder();


	/// constructors
	InstQueue()                           : Inst() { } 
	InstQueue(MySection* s, Offset o)     : Inst(s, o) { } 
	InstQueue(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_QUEUE;
	}
	InstQueue(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstQueue& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstQueue BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstQueue"; }
	void initBrig(); 
};

class InstSeg : public Inst {
public:

	/// accessors
	EnumValRef<Brig::BrigSegment,uint8_t>              segment();


	/// constructors
	InstSeg()                           : Inst() { } 
	InstSeg(MySection* s, Offset o)     : Inst(s, o) { } 
	InstSeg(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_SEG;
	}
	InstSeg(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstSeg& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstSeg BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstSeg"; }
	void initBrig(); 
};

class InstSegCvt : public Inst {
public:

	/// accessors
	ValRef<uint16_t>                                   sourceType();
	EnumValRef<Brig::BrigSegment,uint8_t>              segment();
	SegCvtModifier                                     modifier();


	/// constructors
	InstSegCvt()                           : Inst() { } 
	InstSegCvt(MySection* s, Offset o)     : Inst(s, o) { } 
	InstSegCvt(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_SEG_CVT;
	}
	InstSegCvt(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstSegCvt& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstSegCvt BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstSegCvt"; }
	void initBrig(); 
};

class InstSignal : public Inst {
public:

	/// accessors
	ValRef<uint16_t>                                   signalType();
	EnumValRef<Brig::BrigMemoryOrder,uint8_t>          memoryOrder();
	EnumValRef<Brig::BrigAtomicOperation,uint8_t>      signalOperation();


	/// constructors
	InstSignal()                           : Inst() { } 
	InstSignal(MySection* s, Offset o)     : Inst(s, o) { } 
	InstSignal(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_SIGNAL;
	}
	InstSignal(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstSignal& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstSignal BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstSignal"; }
	void initBrig(); 
};

class InstSourceType : public Inst {
public:

	/// accessors
	ValRef<uint16_t>                                   sourceType();


	/// constructors
	InstSourceType()                           : Inst() { } 
	InstSourceType(MySection* s, Offset o)     : Inst(s, o) { } 
	InstSourceType(BrigContainer* c, Offset o) : Inst(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_INST_SOURCE_TYPE;
	}
	InstSourceType(const ItemBase& rhs) { assignItem(*this,rhs); } 
	InstSourceType& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigInstSourceType BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "InstSourceType"; }
	void initBrig(); 
};

class ExecutableModifier : public ItemBase {
public:

	/// accessors
	ValRef<uint8_t>                                    allBits();
	BitValRef<0>                                       isDefinition();


	/// constructors
	ExecutableModifier()                           : ItemBase() { } 
	ExecutableModifier(MySection* s, Offset o)     : ItemBase(s, o) { } 
	ExecutableModifier(const ExecutableModifier& rhs) : ItemBase(rhs) { } 
	ExecutableModifier& operator=(const ExecutableModifier& rhs) { reset(rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigExecutableModifier BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "ExecutableModifier"; }
	void initBrig(); 
};

class MemoryModifier : public ItemBase {
public:

	/// accessors
	ValRef<uint8_t>                                    allBits();
	BitValRef<0>                                       isConst();


	/// constructors
	MemoryModifier()                           : ItemBase() { } 
	MemoryModifier(MySection* s, Offset o)     : ItemBase(s, o) { } 
	MemoryModifier(const MemoryModifier& rhs) : ItemBase(rhs) { } 
	MemoryModifier& operator=(const MemoryModifier& rhs) { reset(rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigMemoryModifier BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "MemoryModifier"; }
	void initBrig(); 
};

class Operand : public ItemBase {
    // children: BrigOperandAddress,BrigOperandImageProperties,BrigOperandSamplerProperties,BrigOperandCodeList,BrigOperandData,BrigOperandOperandList,BrigOperandReg,BrigOperandString,BrigOperandWavesize,BrigOperandCodeRef
public:

	typedef Operand Kind;

	enum { SECTION = Brig::BRIG_SECTION_INDEX_OPERAND };

	/// accessors
	ValRef<uint16_t>                                   byteCount();
	EnumValRef<Brig::BrigKinds,uint16_t>               kind();


	/// constructors
	Operand()                           : ItemBase() { } 
	Operand(MySection* s, Offset o)     : ItemBase(s, o) { } 
	Operand(BrigContainer* c, Offset o) : ItemBase(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_ADDRESS
		    || rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_IMAGE_PROPERTIES
		    || rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_SAMPLER_PROPERTIES
		    || rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_CODE_LIST
		    || rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_DATA
		    || rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_OPERAND_LIST
		    || rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_REG
		    || rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_STRING
		    || rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_WAVESIZE
		    || rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_CODE_REF;
	}
	Operand(const ItemBase& rhs) { assignItem(*this,rhs); } 
	Operand& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperand BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// root utilities
	Offset  brigSize() const { return brig()->byteCount; }
	Operand next() const { return Operand(section(), brigOffset() + brigSize()); }
};

class OperandAddress : public Operand {
public:

	/// accessors
	ItemRef<DirectiveVariable>                         symbol();
	ItemRef<OperandReg>                                reg();
	UInt64                                             offset();


	/// constructors
	OperandAddress()                           : Operand() { } 
	OperandAddress(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandAddress(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_ADDRESS;
	}
	OperandAddress(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandAddress& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandAddress BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandAddress"; }
	void initBrig(); 
};

class OperandCodeList : public Operand {
public:

	/// accessors
	ListRef<Code>                                      elements();
	unsigned elementCount();
	Code elements(int index);


	/// constructors
	OperandCodeList()                           : Operand() { } 
	OperandCodeList(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandCodeList(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_CODE_LIST;
	}
	OperandCodeList(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandCodeList& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandCodeList BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandCodeList"; }
	void initBrig(); 
};

class OperandCodeRef : public Operand {
public:

	/// accessors
	ItemRef<Code>                                      ref();


	/// constructors
	OperandCodeRef()                           : Operand() { } 
	OperandCodeRef(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandCodeRef(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_CODE_REF;
	}
	OperandCodeRef(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandCodeRef& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandCodeRef BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandCodeRef"; }
	void initBrig(); 
};

class OperandData : public Operand {
public:

	/// accessors
	StrRef                                             data();


	/// constructors
	OperandData()                           : Operand() { } 
	OperandData(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandData(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_DATA;
	}
	OperandData(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandData& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandData BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandData"; }
	void initBrig(); 
};

class OperandImageProperties : public Operand {
public:

	/// accessors
	UInt64                                             width();
	UInt64                                             height();
	UInt64                                             depth();
	UInt64                                             array();
	EnumValRef<Brig::BrigImageGeometry,uint8_t>        geometry();
	EnumValRef<Brig::BrigImageChannelOrder,uint8_t>    channelOrder();
	EnumValRef<Brig::BrigImageChannelType,uint8_t>     channelType();


	/// constructors
	OperandImageProperties()                           : Operand() { } 
	OperandImageProperties(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandImageProperties(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_IMAGE_PROPERTIES;
	}
	OperandImageProperties(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandImageProperties& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandImageProperties BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandImageProperties"; }
	void initBrig(); 
};

class OperandOperandList : public Operand {
public:

	/// accessors
	ListRef<Operand>                                   elements();
	unsigned elementCount();
	Operand elements(int index);


	/// constructors
	OperandOperandList()                           : Operand() { } 
	OperandOperandList(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandOperandList(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_OPERAND_LIST;
	}
	OperandOperandList(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandOperandList& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandOperandList BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandOperandList"; }
	void initBrig(); 
};

class OperandReg : public Operand {
public:

	/// accessors
	EnumValRef<Brig::BrigRegisterKind,uint16_t>        regKind();
	ValRef<uint16_t>                                   regNum();


	/// constructors
	OperandReg()                           : Operand() { } 
	OperandReg(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandReg(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_REG;
	}
	OperandReg(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandReg& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandReg BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandReg"; }
	void initBrig(); 
};

class OperandSamplerProperties : public Operand {
public:

	/// accessors
	EnumValRef<Brig::BrigSamplerCoordNormalization,uint8_t> coord();
	EnumValRef<Brig::BrigSamplerFilter,uint8_t>        filter();
	EnumValRef<Brig::BrigSamplerAddressing,uint8_t>    addressing();


	/// constructors
	OperandSamplerProperties()                           : Operand() { } 
	OperandSamplerProperties(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandSamplerProperties(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_SAMPLER_PROPERTIES;
	}
	OperandSamplerProperties(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandSamplerProperties& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandSamplerProperties BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandSamplerProperties"; }
	void initBrig(); 
};

class OperandString : public Operand {
public:

	/// accessors
	StrRef                                             string();


	/// constructors
	OperandString()                           : Operand() { } 
	OperandString(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandString(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_STRING;
	}
	OperandString(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandString& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandString BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandString"; }
	void initBrig(); 
};

class OperandWavesize : public Operand {
public:

	/// accessors


	/// constructors
	OperandWavesize()                           : Operand() { } 
	OperandWavesize(MySection* s, Offset o)     : Operand(s, o) { } 
	OperandWavesize(BrigContainer* c, Offset o) : Operand(&c->sectionById(SECTION), o) { } 

	/// assignment
	static bool isAssignable(const ItemBase& rhs) {
		return rhs.brig()->kind == Brig::BRIG_KIND_OPERAND_WAVESIZE;
	}
	OperandWavesize(const ItemBase& rhs) { assignItem(*this,rhs); } 
	OperandWavesize& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigOperandWavesize BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "OperandWavesize"; }
	void initBrig(); 
};

class SegCvtModifier : public ItemBase {
public:

	/// accessors
	ValRef<uint8_t>                                    allBits();
	BitValRef<0>                                       isNoNull();


	/// constructors
	SegCvtModifier()                           : ItemBase() { } 
	SegCvtModifier(MySection* s, Offset o)     : ItemBase(s, o) { } 
	SegCvtModifier(const SegCvtModifier& rhs) : ItemBase(rhs) { } 
	SegCvtModifier& operator=(const SegCvtModifier& rhs) { reset(rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigSegCvtModifier BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "SegCvtModifier"; }
	void initBrig(); 
};

class UInt64 : public ItemBase {
public:

	/// accessors
	ValRef<uint32_t>                                   lo();
	ValRef<uint32_t>                                   hi();
	UInt64& operator=(uint64_t rhs);
	operator uint64_t();


	/// constructors
	UInt64()                           : ItemBase() { } 
	UInt64(MySection* s, Offset o)     : ItemBase(s, o) { } 
	UInt64(const UInt64& rhs) : ItemBase(rhs) { } 
	UInt64& operator=(const UInt64& rhs) { reset(rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigUInt64 BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "UInt64"; }
	void initBrig(); 
};

class VariableModifier : public ItemBase {
public:

	/// accessors
	ValRef<uint8_t>                                    allBits();
	BitValRef<0>                                       isDefinition();
	BitValRef<1>                                       isConst();
	BitValRef<2>                                       isArray();
	BitValRef<3>                                       isFlexArray();


	/// constructors
	VariableModifier()                           : ItemBase() { } 
	VariableModifier(MySection* s, Offset o)     : ItemBase(s, o) { } 
	VariableModifier(const VariableModifier& rhs) : ItemBase(rhs) { } 
	VariableModifier& operator=(const VariableModifier& rhs) { reset(rhs); return *this; }

	/// raw brig access
	typedef Brig::BrigVariableModifier BrigStruct;
	      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
	const BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }

	/// final utilities
	static const char *kindName() { return "VariableModifier"; }
	void initBrig(); 
};

