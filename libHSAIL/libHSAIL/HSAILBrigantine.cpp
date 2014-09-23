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
#include "HSAILBrigantine.h"

#include <strstream>


namespace HSAIL_ASM
{


unsigned getRegisterType(const SRef& name)
{
    assert(name.length() > 0);
    if (name.begin[0]!=0) {
        assert(name.length() > 1);
        switch(name.begin[1]) {
        case 'c' : return Brig::BRIG_TYPE_B1;
        case 's' : return Brig::BRIG_TYPE_B32;
        case 'q' : return Brig::BRIG_TYPE_B128;
        case 'd' :
        default:;
        }
    }
    return Brig::BRIG_TYPE_B64;
}


// Brigantine

void BrigantineNoEx::handleError(const SyntaxError& e)
{
    m_errHolder = e;
    m_err = &m_errHolder;
}

void Brigantine::handleError(const SyntaxError& e)
{
    throw e;
}

void Brigantine::brigWriteError(const char *errMsg, const SourceInfo* srcInfo)
{
    if (srcInfo!=NULL) {
        SrcLoc const sl = { srcInfo->line, srcInfo->column };
        handleError(SyntaxError(errMsg, sl));
    } else
        handleError(SyntaxError(errMsg));
}

void Brigantine::startProgram()
{
    assert(m_globalScope.get() == 0);
    m_globalScope.reset(new Scope(&m_container));
}

void Brigantine::endProgram()
{
    m_globalScope.reset();
    m_container.patchDecl2Defs();
}

DirectiveVersion Brigantine::version(
    Brig::BrigVersion32_t major,
    Brig::BrigVersion32_t minor,
    Brig::BrigMachineModel8_t machineModel,
    Brig::BrigProfile8_t profile,
    const SourceInfo* srcInfo)
{
    DirectiveVersion version = m_container.append<DirectiveVersion>();
    annotate(version,srcInfo);
    version.hsailMajor() = major;
    version.hsailMinor() = minor;
    version.brigMajor()  = Brig::BRIG_VERSION_BRIG_MAJOR;
    version.brigMinor()  = Brig::BRIG_VERSION_BRIG_MINOR;
    version.machineModel() = machineModel;
    version.profile() = profile;
    m_profile = profile;
    m_machine = machineModel;
    return version;
}

DirectiveFunction Brigantine::declFunc(const SRef& name, const SourceInfo* srcInfo)
{
    DirectiveFunction func= m_container.append<DirectiveFunction>();
    func.modifier().isDefinition() = false; // will be true on startBody later
    return declFuncCommon(func,name,srcInfo);
}

DirectiveIndirectFunction Brigantine::declIndirectFunc(const SRef& name, const SourceInfo* srcInfo)
{
    DirectiveIndirectFunction func= m_container.append<DirectiveIndirectFunction>();
    func.modifier().isDefinition() = false; // will be true on startBody later
    return declFuncCommon(func,name,srcInfo);
}

DirectiveKernel Brigantine::declKernel(const SRef& name, const SourceInfo* srcInfo)
{
    DirectiveKernel kern= m_container.append<DirectiveKernel>();
    return declFuncCommon(kern,name,srcInfo);
}

DirectiveSignature Brigantine::declSignature(const SRef& name, const SourceInfo* srcInfo)
{
    DirectiveSignature sig = m_container.append<DirectiveSignature>();
    sig.modifier().isDefinition() = true;
    return declFuncCommon(sig,name,srcInfo);
}

DirectiveExecutable Brigantine::declFuncCommon(DirectiveExecutable func,const SRef& name, const SourceInfo* srcInfo)
{
    annotate(func,srcInfo);
    func.name() = name;
    func.codeBlockEntryCount() = 0;
    func.nextModuleEntry() = m_container.code().end();
    func.firstCodeBlockEntry() = m_container.code().end();
    func.firstInArg() = m_container.code().end();
    if (!m_globalScope->get<DirectiveExecutable>(name)) {
        addSymbolToGlobalScope(func);
    }
    m_func = func;
    return func;
}

void Brigantine::addOutputParameter(DirectiveVariable sym)
{
    assert(m_func && sym);
    sym.linkage() = Brig::BRIG_LINKAGE_NONE;
    sym.allocation() = Brig::BRIG_ALLOCATION_NONE;
    sym.modifier().isDefinition() = 1;
    if (sym.modifier().isArray() && sym.dim() == 0) sym.modifier().isFlexArray() = true;

    DirectiveExecutable func = m_func;
    assert(func);
    func.outArgCount() = func.outArgCount() + 1;
    func.nextModuleEntry() = m_container.code().end();
    func.firstCodeBlockEntry() = m_container.code().end();
    func.firstInArg() = m_container.code().end();
}

void Brigantine::addInputParameter(DirectiveVariable sym)
{
    assert(m_func && sym);
    sym.linkage() = Brig::BRIG_LINKAGE_NONE;
    sym.allocation() = Brig::BRIG_ALLOCATION_NONE;
    sym.modifier().isDefinition() = 1;
    if (sym.modifier().isArray() && sym.dim() == 0) sym.modifier().isFlexArray() = true;

    DirectiveExecutable func = m_func;
    func.inArgCount() = func.inArgCount() + 1;
    func.nextModuleEntry() = m_container.code().end();
    func.firstCodeBlockEntry() = m_container.code().end();
}

void Brigantine::startBody()
{
    assert(m_func && m_funcScope.get()==NULL);

    m_func.modifier().isDefinition() = true;
    m_funcScope.reset(new Scope(&m_container));
    m_func.firstCodeBlockEntry() = m_container.code().end();

    DirectiveExecutable func = m_func;
    if (func && func.outArgCount() > 0) {
        Code cur = func.next();
        for(uint32_t i=func.outArgCount(); i>0; --i) {
            DirectiveVariable sym = cur;
            assert(sym);
            addSymbolToFunctionScope(sym);
            cur = cur.next();
        }
    }
    if (m_func.inArgCount() > 0) {
        Code cur = m_func.firstInArg();
        for(uint32_t i=m_func.inArgCount(); i>0; --i) {
            DirectiveVariable sym = cur;
            assert(sym);
            addSymbolToFunctionScope(sym);
            cur = cur.next();
        }
    }
}

bool Brigantine::endBody()
{
    assert(m_func && m_funcScope.get()!=NULL);
    if (!checkForUnboundLabels()) {
        return false;
    }

    m_func.nextModuleEntry() = m_container.code().end();

    unsigned cnt = 0;
    for (Code i = m_func.firstCodeBlockEntry(); i != m_func.nextModuleEntry(); i = i.next()) ++cnt;
    m_func.codeBlockEntryCount() = cnt;

    m_funcScope.reset();
    DirectiveExecutable fx = m_func;
    m_func = Directive();
    return true;
}

bool Brigantine::checkForUnboundLabels()
{
    if (!m_labelMap.empty()) {
        const RefList& list = (*m_labelMap.begin()).second;
        brigWriteError("label doesn't exist", &list.front().second);
        return false;
    }
    return true;
}

DirectiveArgBlockStart Brigantine::startArgScope(const SourceInfo* srcInfo)
{
    if (m_argScope.get()!=NULL) {
        brigWriteError("Nested argument scope is not allowed",srcInfo);
        return DirectiveArgBlockStart();
    }

    DirectiveArgBlockStart s = m_container.append<DirectiveArgBlockStart>();
    annotate(s,srcInfo);

    m_argScope.reset(new Scope(&m_container));
    return s;
}

DirectiveArgBlockEnd Brigantine::endArgScope(const SourceInfo* srcInfo)
{
    m_argScope.reset();
    DirectiveArgBlockEnd e = m_container.append<DirectiveArgBlockEnd>();
    annotate(e,srcInfo);
    return e;
}

void Brigantine::recordLabelRef(ItemRef<Code> ref, const SRef& name, const SourceInfo* srcInfo)
{
    if (!m_funcScope.get()) {
      brigWriteError("labels cannot be used outside of code blocks",srcInfo);
      return;
    }
    DirectiveLabel lbl = m_funcScope->get<DirectiveLabel>(name);
    if (lbl) {
        ref = lbl;
    } else {
        Offset const nameOfs = m_container.addString(name);
        m_labelMap[nameOfs].push_back(std::make_pair(ref,srcInfo ? *srcInfo : SourceInfo()));
    }
}

void Brigantine::patchLabelRefs(DirectiveLabel label)
{
    LabelMap::iterator l = m_labelMap.find(label.name().deref());
    if (l!=m_labelMap.end()) {
        const RefList &refList = (*l).second;
        for(RefList::const_iterator i=refList.begin(), e=refList.end(); i!=e; ++i) {
            ItemRef<Code> ref = (*i).first;
            ref = label;
        }
        m_labelMap.erase(l);
    }
}

DirectiveVariable Brigantine::addSymbol(DirectiveVariable sym)
{
    if (isLocalName(sym.name())) {
        if (localScope()!=NULL) {
            addSymbolToLocalScope(sym);
        }
    } else {
        addSymbolToGlobalScope(sym);
    }
    return sym;
}

DirectiveVariable Brigantine::addVariable(
    const SRef& name,
    Brig::BrigSegment8_t segment,
    unsigned dType,
    const SourceInfo* srcInfo)
{
    DirectiveVariable sym = m_container.append<DirectiveVariable>();
    annotate(sym,srcInfo);
    sym.name() = name;
    sym.segment() = segment;
    sym.type() = dType;
    addSymbol(sym);
    return sym;
}

DirectiveVariable Brigantine::addArrayVariable(
    const SRef& name,
    uint64_t size,
    Brig::BrigSegment8_t segment,
    unsigned dType,
    const SourceInfo* srcInfo)
{
    DirectiveVariable sym = addVariable(name,segment,dType,srcInfo);
    sym.modifier().isArray() = true;
    sym.dim() = size;
    return sym;
}

DirectiveVariable Brigantine::addImage(
    const SRef& name,
    Brig::BrigSegment8_t segment,
    const SourceInfo* srcInfo)
{
    return addVariable(name,segment,Brig::BRIG_TYPE_RWIMG,srcInfo);
}

DirectiveVariable Brigantine::addSampler(
    const SRef& name,
    Brig::BrigSegment8_t segment,
    const SourceInfo* srcInfo)
{
    return addVariable(name,segment,Brig::BRIG_TYPE_SAMP,srcInfo);
}

DirectiveFbarrier Brigantine::addFbarrier(const SRef& name,const SourceInfo* srcInfo) {
    Scope *s = NULL;
    if (isLocalName(name)) {
        s = m_funcScope.get();
        if (s==NULL) {
            brigWriteError("local symbol declared at global scope",srcInfo);
            return DirectiveFbarrier();
        }
    } else {
        s = m_globalScope.get();
    }
    assert(s);

    DirectiveFbarrier fbar = m_container.append<DirectiveFbarrier>();
    annotate(fbar,srcInfo);
    fbar.name() = name;
    s->add(name, fbar);
    return fbar;
}

DirectiveLabel Brigantine::addLabelInternal(const SRef& name,const SourceInfo* srcInfo)
{
    DirectiveLabel lbl = m_funcScope->get<DirectiveLabel>(name);
    if (lbl) {
        brigWriteError("Duplicate label declaration",srcInfo);
        return DirectiveLabel();
    }
    lbl = m_container.append<DirectiveLabel>();
    annotate(lbl,srcInfo);
    lbl.name() = name;
    m_funcScope->add(name,lbl);
    return lbl;
}

DirectiveLabel Brigantine::addLabel(const SRef& name,const SourceInfo* srcInfo)
{
    DirectiveLabel lbl = addLabelInternal(name,srcInfo);
    if (lbl) {
        patchLabelRefs(lbl);
    }
    return lbl;
}

DirectiveComment Brigantine::addComment(const char *comment,const SourceInfo* srcInfo)
{
    DirectiveComment cmt = m_container.append<DirectiveComment>();
    annotate(cmt,srcInfo);
    cmt.name() = comment;
    return cmt;
}

DirectiveLabel Brigantine::addExtension(const char *name,const SourceInfo* srcInfo)
{
    DirectiveExtension ext = m_container.append<DirectiveExtension>();
    annotate(ext,srcInfo);
    ext.name() = name;
    return ext;
}

/*
OperandFunctionList Brigantine::createFuncList(const SourceInfo* srcInfo)
{
    OperandFunctionList list = m_container.append<OperandFunctionList>();
    annotate(list,srcInfo);
    return list;
}

OperandArgumentList Brigantine::createArgList(const SourceInfo* srcInfo)
{
    OperandArgumentList list = m_container.append<OperandArgumentList>();
    annotate(list,srcInfo);
    return list;
}
*/

OperandData Brigantine::createWidthOperand(const Optional<uint32_t>& width,const SourceInfo* srcInfo) {
    uint32_t bits = width.value(0);
    return createImmed(SRef::array(&bits), srcInfo);
}

OperandReg Brigantine::createOperandReg(const SRef& name,const SourceInfo* srcInfo) {
    OperandReg operand = m_container.append<OperandReg>();
    annotate(operand,srcInfo);
    assert(name.length() > 2);
    assert(name[0] == '$');
    switch(name[1]) {
    case 'c': operand.regKind() = Brig::BRIG_REGISTER_CONTROL; break;
    case 's': operand.regKind() = Brig::BRIG_REGISTER_SINGLE; break;
    case 'd': operand.regKind() = Brig::BRIG_REGISTER_DOUBLE; break;
    case 'q': operand.regKind() = Brig::BRIG_REGISTER_QUAD; break;
    default:
      assert(!"invalid register name");
    }
    std::istrstream is(name.substr(2).begin, name.substr(2).length());
    int num;
    is >> num;
    operand.regNum() = num;
    return operand;
}

/*
OperandOperandList Brigantine::createOperandVector(const SourceInfo* srcInfo) {
    OperandOperandList operand = m_container.append<OperandOperandList>();
    annotate(operand,srcInfo);
    return operand;
}

OperandRegVector Brigantine::createOperandRegVec(
    std::string o[],unsigned num,
    const SourceInfo* srcInfo) {
    if (num < 2 || num > 4) {
        brigWriteError("vector operand must contain 2, 3 or 4 registers",srcInfo);
    }
    OperandRegVector operand = m_container.append<OperandRegVector>();
    annotate(operand,srcInfo);
    for(unsigned i=0; i<num; ++i)
        operand.regs().push_back(o[i]);
    return operand;
}
*/

OperandCodeRef Brigantine::createExecutableRef(const SRef& name, const SourceInfo* srcInfo) {
    DirectiveExecutable fn = m_globalScope->get<DirectiveExecutable>(name);
    if (!fn) {
        brigWriteError("Unknown executable reference",srcInfo);
        return OperandCodeRef();
    }
    return createCodeRef(fn,srcInfo);
}

/*OperandSignatureRef Brigantine::createSigRef(DirectiveSignature sig, const SourceInfo* srcInfo) {
    OperandSignatureRef operand = m_container.append<OperandSignatureRef>();
    annotate(operand,srcInfo);
    operand.sig() = sig;
    return operand;
}
*/
OperandCodeRef Brigantine::createSigRef(const SRef& fnName, const SourceInfo* srcInfo) {
    DirectiveSignature sig = m_globalScope->get<DirectiveSignature>(fnName);
    if (!sig) {
        brigWriteError("Unknown signature",srcInfo);
        return OperandCodeRef();
    }
    return createCodeRef(sig,srcInfo);
}

OperandWavesize Brigantine::createWaveSz(const SourceInfo* srcInfo) {
    OperandWavesize res = m_container.append<OperandWavesize>();
    annotate(res,srcInfo);
    return res;
}

Operand Brigantine::createLabelRef(const SRef& labelName, const SourceInfo* srcInfo) {
    OperandCodeRef operand = append<OperandCodeRef>(srcInfo);
    recordLabelRef(operand.ref(),labelName,srcInfo);
    return operand;
}

Operand Brigantine::createLabelList(const std::vector<SRef>& labels, const SourceInfo* srcInfo) {
    OperandCodeList operand = append<OperandCodeList>(srcInfo);
    ListRef<Code> ref = operand.elements();
    ItemList dummy;
    for(unsigned i=0; i<labels.size(); ++i) {
      dummy.push_back(Code());
    }
    ref = dummy;
    for(unsigned i = 0; i<labels.size(); ++i) {
      recordLabelRef(ref.writeAccess(i), labels[i], srcInfo);
    }
    return operand;
}

OperandData Brigantine::createImmed(const SourceInfo* srcInfo) {
    OperandData operand = m_container.append<OperandData>();
    annotate(operand,srcInfo);
    return operand;
}

OperandData Brigantine::createImmed(SRef data, const SourceInfo* srcInfo) {
    OperandData operand = createImmed(srcInfo);
    operand.data() = data;
    return operand;
}


OperandAddress Brigantine::createRef(
    const SRef& symName,
    OperandReg reg,
    int64_t offset,
    const SourceInfo* srcInfo) {

    OperandAddress operand = m_container.append<OperandAddress>();
    annotate(operand,srcInfo);

    if (!symName.empty()) {
        DirectiveVariable nameDS = findInScopes<DirectiveVariable>(symName);
        if (!nameDS) {
            std::string name = symName;
            brigWriteError(("Symbol not found: " + name).c_str(),srcInfo);
            return OperandAddress();
        }
        operand.symbol() = nameDS;
    }
    operand.reg() = reg;
    operand.offset() = (uint64_t)offset;
    return operand;
}


OperandCodeRef Brigantine::createDirectiveRef(const SRef& name,const SourceInfo* srcInfo)
{
    Directive d = findInScopes<Directive>(name);
    if (!d) {
        brigWriteError("identifier not found",srcInfo);
        return OperandCodeRef();
    }
    return createCodeRef(d, srcInfo);
}

OperandCodeRef Brigantine::createCodeRef(Code c,const SourceInfo* srcInfo)
{
    OperandCodeRef operand = append<OperandCodeRef>();
    annotate(operand,srcInfo);
    operand.ref() = c;
    return operand;
}

void Brigantine::addSymbolToGlobalScope(DirectiveExecutable sym) {
    assert(isGlobalName(sym.name()));
    assert(m_globalScope.get()!=NULL);
    m_globalScope->add(sym.name(), sym);
}

void Brigantine::addSymbolToGlobalScope(DirectiveVariable sym) {
    assert(isGlobalName(sym.name()));
    assert(m_globalScope.get()!=NULL);
    m_globalScope->add(sym.name(), sym);
}

void Brigantine::addSymbolToFunctionScope(DirectiveVariable sym) {
    assert(isLocalName(sym.name()));
    assert(m_funcScope.get());
    sym.linkage() = Brig::BRIG_LINKAGE_FUNCTION;
    sym.allocation() = Brig::BRIG_ALLOCATION_AUTOMATIC;
    m_funcScope->add(sym.name(), sym);
}

void Brigantine::addSymbolToLocalScope(DirectiveVariable sym) {
    assert(isLocalName(sym.name()));
    if (sym.segment()!=Brig::BRIG_SEGMENT_ARG) {
        assert(m_funcScope.get());
        m_funcScope->add(sym.name(), sym);
    } else
    if (m_argScope.get()) {
        m_argScope->add(sym.name(), sym);
    } else {
        brigWriteError("no argument scope available at this location",sym.srcInfo());
    }
}

// **NB** This function should only be called by Parser. Lowering code should use setOperandEx

void Brigantine::setOperands(Inst inst, ItemList operands)
{
    inst.operands() = operands;

}

// Brigantine end
}
