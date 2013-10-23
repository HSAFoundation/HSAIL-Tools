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
}

DirectiveVersion Brigantine::version(
    unsigned short  major,
    unsigned short  minor,
    Brig::BrigMachineModel8_t machineModel,
    Brig::BrigProfile8_t profile,
    const SourceInfo* srcInfo)
{
    DirectiveVersion version = m_container.append<DirectiveVersion>();
    annotate(version,srcInfo);
    version.code() = m_container.insts().end();
    version.hsailMajor() = major;
    version.hsailMinor() = minor;
    version.brigMajor()  = Brig::BRIG_VERSION_BRIG_MAJOR;
    version.brigMinor()  = Brig::BRIG_VERSION_BRIG_MINOR;
    version.machineModel() = machineModel;
    version.profile() = profile;
    m_machine = machineModel;
    return version;
}

DirectiveSignature Brigantine::declSignature(const SRef& name, const SourceInfo* srcInfo) {
    DirectiveSignature sig = container().append<DirectiveSignature>();
    annotate(sig,srcInfo);
    sig.code() = m_container.insts().end();
    sig.name() = name;
    assert(isGlobalName(name));
    assert(m_globalScope.get()!=NULL);
    m_globalScope->add(name, sig);
    return sig;
}

DirectiveFunction Brigantine::declFunc(const SRef& name, const SourceInfo* srcInfo)
{
    DirectiveFunction func= m_container.append<DirectiveFunction>();
    func.modifier().linkage() = Brig::BRIG_LINKAGE_NONE;
    return declFuncCommon(func,name,srcInfo);
}

DirectiveKernel Brigantine::declKernel(const SRef& name, const SourceInfo* srcInfo)
{
    DirectiveKernel kern= m_container.append<DirectiveKernel>();
    kern.modifier().linkage() = Brig::BRIG_LINKAGE_NONE;
    return declFuncCommon(kern,name,srcInfo);
}

DirectiveExecutable Brigantine::declFuncCommon(DirectiveExecutable func,const SRef& name, const SourceInfo* srcInfo)
{
    annotate(func,srcInfo);
    func.name() = name;
    func.code() = m_container.insts().end();
    func.instCount() = 0;
    func.nextTopLevelDirective() = m_container.directives().end();
    func.firstScopedDirective() = m_container.directives().end();
    func.firstInArg() = m_container.directives().end();
    if (!m_globalScope->get<DirectiveExecutable>(name)) {
        addSymbolToGlobalScope(func);
    }
    m_func = func;
    return func;
}

void Brigantine::addOutputParameter(DirectiveSymbol sym)
{
    assert(m_func && sym);
    DirectiveFunction func = m_func;
    assert(func);
    func.outArgCount() = func.outArgCount() + 1;
    func.nextTopLevelDirective() = m_container.directives().end();
    func.firstScopedDirective() = m_container.directives().end();
    func.firstInArg() = m_container.directives().end();
}

void Brigantine::addInputParameter(DirectiveSymbol sym)
{
    assert(m_func && sym);
    sym.modifier().isDeclaration() = 1;
    DirectiveExecutable func = m_func;
    func.inArgCount() = func.inArgCount() + 1;
    func.nextTopLevelDirective() = m_container.directives().end();
    func.firstScopedDirective() = m_container.directives().end();
}

void Brigantine::startBody()
{
    assert(m_func && m_funcScope.get()==NULL);

    m_funcScope.reset(new Scope(&m_container));
    m_func.firstScopedDirective() = m_container.directives().end();

    DirectiveFunction func = m_func;
    if (func && func.outArgCount() > 0) {
        DirectiveSymbol sym = func.next();
        for(uint32_t i=func.outArgCount(); i>0; --i) {
            assert(sym);
            addSymbolToFunctionScope(sym);
            sym = sym.next();
        }
    }
    if (m_func.inArgCount() > 0) {
        DirectiveSymbol sym = m_func.firstInArg();
        for(uint32_t i=m_func.inArgCount(); i>0; --i) {
            assert(sym);
            addSymbolToFunctionScope(sym);
            sym = sym.next();
        }
    }
}

bool Brigantine::endBody()
{
    assert(m_func && m_funcScope.get()!=NULL);
    if (!checkForUnboundLabels()) {
        return false;
    }
    m_func.nextTopLevelDirective() = m_container.directives().end();
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

DirectiveArgScopeStart Brigantine::startArgScope(const SourceInfo* srcInfo)
{
    if (m_argScope.get()!=NULL) {
        brigWriteError("Nested argument scope is not allowed",srcInfo);
        return DirectiveArgScopeStart();
    }

    DirectiveArgScopeStart s = m_container.append<DirectiveArgScopeStart>();
    annotate(s,srcInfo);
    s.code() = m_container.insts().end();

    m_argScope.reset(new Scope(&m_container));
    return s;
}

DirectiveArgScopeEnd Brigantine::endArgScope(const SourceInfo* srcInfo)
{
    m_argScope.reset();
    DirectiveArgScopeEnd e = m_container.append<DirectiveArgScopeEnd>();
    annotate(e,srcInfo);
    e.code() = m_container.insts().end();
    return e;
}

DirectiveLabelTargets Brigantine::findTargets(DirectiveLabel lbl) {
    DirectiveLabelTargets tgts;
    Directive d = lbl.next();
    if (d!=m_container.directives().end()) {
        tgts = d;
        assert(!tgts || tgts.label()==lbl);
    }
    return tgts;
}

void Brigantine::recordLabelRef(ItemRef<Directive> ref, const SRef& name, const SourceInfo* srcInfo)
{
    DirectiveLabel lbl = m_funcScope->get<DirectiveLabel>(name);
    if (lbl) {
        if (DirectiveLabelTargets tgts = findTargets(lbl)) {
            ref = tgts;
        } else {
            ref = lbl;
        }
    } else {
        Offset const nameOfs = m_container.addString(name);
        m_labelMap[nameOfs].push_back(std::make_pair(ref,srcInfo ? *srcInfo : SourceInfo()));
    }
}

void Brigantine::patchLabelRefs(DirectiveLabel label)
{
    LabelMap::iterator l = m_labelMap.find(label.name().deref());
    if (l!=m_labelMap.end()) {
        DirectiveLabelTargets tgts = findTargets(label);
        Directive res = tgts ? static_cast<Directive>(tgts) : static_cast<Directive>(label);
        const RefList &refList = (*l).second;
        for(RefList::const_iterator i=refList.begin(), e=refList.end(); i!=e; ++i) {
            ItemRef<Directive> ref = (*i).first;
            ref = res;
        }
        m_labelMap.erase(l);
    }
}

DirectiveSymbol Brigantine::addSymbol(DirectiveSymbol sym)
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
    DirectiveVariable sym = createCodeRefDir<DirectiveVariable>(srcInfo);
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

DirectiveImage Brigantine::addImage(
    const SRef& name,
    Brig::BrigSegment8_t segment,
    const SourceInfo* srcInfo)
{
    DirectiveImage sym = createCodeRefDir<DirectiveImage>(srcInfo);
    sym.name() = name;
    sym.segment() = segment;
    sym.type() = Brig::BRIG_TYPE_RWIMG;
    addSymbol(sym);
    return sym;
}

DirectiveSampler Brigantine::addSampler(
    const SRef& name,
    Brig::BrigSegment8_t segment,
    const SourceInfo* srcInfo)
{
    DirectiveSampler sym = createCodeRefDir<DirectiveSampler>(srcInfo);
    sym.name() = name;
    sym.segment() = segment;
    sym.type() = Brig::BRIG_TYPE_SAMP;
    addSymbol(sym);
    return sym;
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
    DirectiveFbarrier fbar = createCodeRefDir<DirectiveFbarrier>(srcInfo);
    fbar.name() = name;
    s->add(name, fbar);
    return fbar;
}

DirectiveVariableInit Brigantine::createVariableInitializer(Brig::BrigType16_t type, const SourceInfo* srcInfo)
{
    DirectiveVariableInit init = createCodeRefDir<DirectiveVariableInit>(srcInfo);
    init.type() = convType2BitType(type);
    return init;
}

DirectiveImageInit    Brigantine::createImageInitializer(const SourceInfo* srcInfo)
{
    return createCodeRefDir<DirectiveImageInit>(srcInfo);
    DirectiveImageInit init = m_container.append<DirectiveImageInit>();
    annotate(init,srcInfo);
    init.code() = m_container.insts().end();
    return init;
}

DirectiveSamplerInit  Brigantine::createSamplerInitializer(const SourceInfo* srcInfo)
{
    DirectiveSamplerInit init = m_container.append<DirectiveSamplerInit>();
    annotate(init,srcInfo);
    //init.code() = m_container.insts().end(); // TBD095 is this missing in spec?
    return init;
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
    lbl.code() = m_container.insts().end();
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
    cmt.code() = m_container.insts().end();
    return cmt;
}

DirectiveLabel Brigantine::addExtension(const char *name,const SourceInfo* srcInfo)
{
    DirectiveExtension ext = m_container.append<DirectiveExtension>();
    annotate(ext,srcInfo);
    ext.name() = name;
    ext.code() = m_container.insts().end();
    return ext;
}


OperandArgumentRef Brigantine::createArgRef(const SRef& argName, const SourceInfo* srcInfo)
{
    DirectiveSymbol const argDir = findInScopes<DirectiveSymbol>(argName);
    if (!argDir) {
        brigWriteError("argument symbol not found",srcInfo);
        return OperandArgumentRef();
    }
    return createArgRef(argDir,srcInfo);
}

OperandArgumentRef Brigantine::createArgRef(DirectiveSymbol arg, const SourceInfo* srcInfo)
{
    OperandArgumentRef opndRef = m_container.append<OperandArgumentRef>();
    annotate(opndRef,srcInfo);
    opndRef.arg() = arg;
    return opndRef;
}

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

Inst Brigantine::addInst(Inst i)
{
    if (!m_func.code()) {
        m_func.code() = i;
        m_func.instCount() = 1;
    } else {
        m_func.instCount() = m_func.instCount() + 1;
    }
    return i;
}

template <typename Value> // this routine converts Value v to the requested brig type and save it into immediate
inline OperandImmed Brigantine::createImmedT(Value v, Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    OperandImmed imm = createImmed(srcInfo);
    setImmed(imm,v,type);
    return imm;
}

OperandImmed Brigantine::createImmed(int8_t v,  Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createImmed(int16_t v,  Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createImmed(int32_t v,  Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createImmed(int64_t v,  Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createImmed(uint8_t  v, Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createImmed(uint16_t v, Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createImmed(uint32_t v, Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createImmed(uint64_t v, Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createImmed(f32_t v,    Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createImmed(f64_t v,   Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

// simple reinterpret
OperandImmed Brigantine::createImmed(const void * v, Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    return createImmedT(v,type,srcInfo);
}

OperandImmed Brigantine::createWidthOperand(const Optional<uint32_t>& width,const SourceInfo* srcInfo) {
    return createImmedT(width.value(0), Brig::BRIG_TYPE_B32, srcInfo);
}

OperandReg Brigantine::createOperandReg(const SRef& name,const SourceInfo* srcInfo) {
    OperandReg operand = m_container.append<OperandReg>();
    annotate(operand,srcInfo);
    operand.reg() = name;
    operand.type() = getRegisterType(name);
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
    operand.type() = getRegisterType(SRef(o[0]));
    return operand;
}

OperandFunctionRef Brigantine::createFuncRef(DirectiveFunction fn, const SourceInfo* srcInfo) {
    OperandFunctionRef operand = m_container.append<OperandFunctionRef>();
    annotate(operand,srcInfo);
    operand.fn() = fn;
    return operand;
}

OperandFunctionRef Brigantine::createFuncRef(const SRef& fnName, const SourceInfo* srcInfo) {
    DirectiveFunction fn = m_globalScope->get<DirectiveFunction>(fnName);
    if (!fn) {
        brigWriteError("Unknown function",srcInfo);
        return OperandFunctionRef();
    }
    return createFuncRef(fn,srcInfo);
}

OperandSignatureRef Brigantine::createSigRef(DirectiveSignature sig, const SourceInfo* srcInfo) {
    OperandSignatureRef operand = m_container.append<OperandSignatureRef>();
    annotate(operand,srcInfo);
    operand.sig() = sig;
    return operand;
}

OperandSignatureRef Brigantine::createSigRef(const SRef& fnName, const SourceInfo* srcInfo) {
    DirectiveSignature sig = m_globalScope->get<DirectiveSignature>(fnName);
    if (!sig) {
        brigWriteError("Unknown signature",srcInfo);
        return OperandFunctionRef();
    }
    return createSigRef(sig);
}

OperandWavesize Brigantine::createWaveSz(Brig::BrigType16_t type, const SourceInfo* srcInfo) {
    OperandWavesize res = m_container.append<OperandWavesize>();
    res.type() = convType2BitType(type);
    annotate(res,srcInfo);
    return res;
}

Operand Brigantine::createLabelRef(const SRef& labelName, const SourceInfo* srcInfo) {

    OperandLabelRef operand = m_container.append<OperandLabelRef>();
    annotate(operand,srcInfo);
    recordLabelRef(operand.ref(),labelName,srcInfo);
    return operand;
}

bool Brigantine::appendLabelRef(LabelList list,const SRef& name, const SourceInfo* srcInfo)
{
    if (!list.push_back(DirectiveLabel())) {
        brigWriteError("LabelList is full",srcInfo);
        return false;
    }
    ItemRef<DirectiveLabel> r = list[ list.size()-1 ];
    recordLabelRef(r.asRefTo<Directive>(),name,srcInfo);
    return true;
}

DirectiveLabelInit Brigantine::createLabelInitList(const SourceInfo* srcInfo) {
    return createCodeRefDir<DirectiveLabelInit>(srcInfo);
}

DirectiveLabelTargets Brigantine::createLabelTargets(const SRef& labelName, const SourceInfo* srcInfo) {
    DirectiveLabel lbl = addLabelInternal(labelName,srcInfo);
    DirectiveLabelTargets tgts;
    if (lbl) {
        tgts = createCodeRefDir<DirectiveLabelTargets>(srcInfo);
        tgts.label() = lbl;
        patchLabelRefs(lbl);
    }
    return tgts;
}


OperandImmed Brigantine::createImmed(const SourceInfo* srcInfo) {
    OperandImmed operand = m_container.append<OperandImmed>();
    annotate(operand,srcInfo);
    return operand;
}

unsigned Brigantine::getMachineType() const {
    return (m_machine == Brig::BRIG_MACHINE_SMALL)? Brig::BRIG_TYPE_B32 : Brig::BRIG_TYPE_B64;
}

OperandAddress Brigantine::createRef(
    const SRef& symName,
    const SRef& reg,
    int32_t offset,
    const SourceInfo* srcInfo) {

    OperandAddress operand = m_container.append<OperandAddress>();
    annotate(operand,srcInfo);

    if (!symName.empty()) {
        DirectiveSymbol nameDS = findInScopes<DirectiveSymbol>(symName);
        if (!nameDS) {
            brigWriteError("Symbol not found",srcInfo);
            return OperandAddress();
        }
        operand.symbol() = nameDS;
    }
    if (!reg.empty()) {
        operand.reg() = reg;
    }
    operand.offset() = offset;

    //dp operand.type()   = getMachineType();
    //dp: this is a patch; operand type may depend on instruction as well!
    //dp start ----------------------------
    if (reg.length() > 1) {
        std::string name = reg;
        operand.type() = (name[1] == 'd')? Brig::BRIG_TYPE_B64 : Brig::BRIG_TYPE_B32;
    } else if (!symName.empty()) {
        operand.type() =
            getSegAddrSize(operand.symbol().segment(), m_machine == Brig::BRIG_MACHINE_LARGE) == 32?
                Brig::BRIG_TYPE_B32 :
                Brig::BRIG_TYPE_B64;
    } else {
        operand.type() = getMachineType(); //dp: actually type depends on context
    }
    //dp end ----------------------------
    return operand;
}


class CreateDirectiveRef
{
    BrigContainer& m_container;
public:
    CreateDirectiveRef(BrigContainer& c) : m_container(c) {}

    OperandRef operator()(DirectiveFunction fn) const {
        OperandFunctionRef r = m_container.append<OperandFunctionRef>();
        r.fn() = fn;
        return r;
    }

    OperandRef operator()(DirectiveFbarrier fbar) const {
        OperandFbarrierRef r = m_container.append<OperandFbarrierRef>();
        r.fbar() = fbar;
        return r;
    }

    template <typename Dir>
    OperandRef operator()(Dir) const { return OperandRef(); }
};

OperandRef Brigantine::createDirectiveRef(const SRef& name,const SourceInfo* srcInfo)
{
    Directive d = findInScopes<Directive>(name);
    if (!d) {
        brigWriteError("identifier not found",srcInfo);
        return OperandRef();
    }
    return createDirectiveRef(d,srcInfo);
}

OperandRef Brigantine::createDirectiveRef(Directive sym,const SourceInfo* srcInfo)
{
    OperandRef res = dispatchByItemKind<OperandRef>(sym,CreateDirectiveRef(m_container));
    if (!res) {
        brigWriteError("invalid symbol reference",srcInfo);
        return res;
    }
    annotate(res,srcInfo);
    return res;
}

void Brigantine::addSymbolToGlobalScope(DirectiveExecutable sym) {
    assert(isGlobalName(sym.name()));
    assert(m_globalScope.get()!=NULL);
    m_globalScope->add(sym.name(), sym);
}

void Brigantine::addSymbolToGlobalScope(DirectiveSymbol sym) {
    assert(isGlobalName(sym.name()));
    assert(m_globalScope.get()!=NULL);
    m_globalScope->add(sym.name(), sym);
}

void Brigantine::addSymbolToFunctionScope(DirectiveSymbol sym) {
    assert(isLocalName(sym.name()));
    assert(m_funcScope.get());
    m_funcScope->add(sym.name(), sym);
}

void Brigantine::addSymbolToLocalScope(DirectiveSymbol sym) {
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

void Brigantine::storeDWARF(const void* dwarfData, size_t dwarfDataSize)
{
  HSAIL_ASM::BrigSectionImpl& sec = m_container.debugChunks();

  HSAIL_ASM::BlockStart blockStart = sec.append< HSAIL_ASM::BlockStart >();
  blockStart.name() = "debug";

  HSAIL_ASM::BlockString blockString = sec.append< HSAIL_ASM::BlockString >();
  blockString.string() = "hsa_dwarf_debug";

  size_t bytesRemaining = dwarfDataSize;
  const char *src = static_cast<const char*>(dwarfData);
  while ( bytesRemaining > 0 ) {
      HSAIL_ASM::BlockNumeric blockNumeric = sec.append<HSAIL_ASM::BlockNumeric>();
      blockNumeric.type() = Brig::BRIG_TYPE_B8;
      size_t maxStringLen = StringSection::maxStringLen;
      size_t bytesToCopy = (std::min)(bytesRemaining,maxStringLen);
      blockNumeric.data() = SRef(src, src + bytesToCopy);
      src += bytesToCopy;
      bytesRemaining -= bytesToCopy;
  }

  sec.append< HSAIL_ASM::BlockEnd >();
}

// **NB** This function should only be called by Parser. Lowering code should use setOperandEx
void Brigantine::setOperand(Inst inst, int oprIdx, Operand opnd)
{
    inst.operand(oprIdx) = opnd;

    // Set default width value for branch/call instructions.
    // This is only possible after target address operand is assigned,
    // because default width value depends on wether branch/call is indirect
    if (InstBr br = inst) {
        if (br.width() == Brig::BRIG_WIDTH_NONE) {      // BRIG_WIDTH_NONE is a special value indicating
            unsigned opcode = br.opcode();              // that instruction has no explicitly specified width
            if ((opcode == Brig::BRIG_OPCODE_BRN  && oprIdx == 0) ||
                (opcode == Brig::BRIG_OPCODE_CBR  && oprIdx == 1) ||
                (opcode == Brig::BRIG_OPCODE_CALL && oprIdx == 1)) {
                 br.width() = getDefWidth(br);
            }
        }
    }

    if (OperandAddress addr = opnd) {
        if (!addr.symbol() && !addr.reg()) {
            // Set size of address operands which have neither symbol no register.
            // Size of these operands should be set based on segment in instruction which uses them.
            if (getSegAddrSize(getSegment(inst), m_machine == Brig::BRIG_MACHINE_LARGE) == 32) {
                addr.type() = Brig::BRIG_TYPE_B32;
            } else {
                addr.type() = Brig::BRIG_TYPE_B64;
            }
        } else if (!addr.reg() && addr.symbol() && m_machine == Brig::BRIG_MACHINE_LARGE && getSegAddrSize(addr.symbol().segment(), true) == 32) {
            //FIXME: this is a temporary patch (currently, LLVM cannot generate 32-bit addresses for large model)
            addr.type() = Brig::BRIG_TYPE_B64;
        }
    }
}

// **NB** This function should only be called by lowering code. Parser should use setOperand
void Brigantine::setOperandEx(Inst inst, int oprIdx, Operand opnd)
{
    setOperand(inst,oprIdx,opnd);

    // This is a lowering-specific patch to sync symbol segment with instruction segment
    if (OperandAddress addr = opnd) {
        DirectiveSymbol sym = addr.symbol();
        if (sym && sym.segment() == Brig::BRIG_SEGMENT_READONLY) {
            if (InstMem im = inst) {
                im.segment() = Brig::BRIG_SEGMENT_READONLY;
            } else if (InstAddr ia = inst) {
                ia.segment() = Brig::BRIG_SEGMENT_READONLY;
            }
        }
    }
}

void Brigantine::appendOperand(Inst inst, Operand opnd)
{
    int i=getOperandsNum(inst);

    if (i<5) {
        setOperand(inst,i,opnd);
        inst.operand(i) = opnd;
    } else {
        brigWriteError("not more than 5 operands allowed",inst.srcInfo());
    }
}

/*
class FillWithZeroes {
    unsigned      m_numZeroes;
    DirectiveVariableInit m_init;
public:
    FillWithZeroes(unsigned numZeroes,DirectiveVariableInit init)
        : m_numZeroes(numZeroes), m_init(init) {}
    template <typename DstBrigType>
    void visit() {
        typedef typename DstBrigType::CType DstCType;
        DirectiveInitValues<DstCType> values = m_init.values<DstCType>();
        const DstCType zero = DstCType();
        for(unsigned i = m_numZeroes; i>0; --i) {
            values.push_back(zero);
        }
    }
    void visitNone(...) {}
};

void Brigantine::appendTrailingZeroes(HSAIL_ASM::DirectiveSymbol sym)
{
    if (!sym.init()) {
        sym.init() = createInitializer(sym.type());
    }
    DirectiveVariableInit init = sym.init();
    if (init) {
        uint32_t const reqElems = sym.dim();
        uint32_t const elems = init.elementCount();

        if (sym.attribute() & Brig::BRIG_SYMBOL_ARRAY) {
            if ( reqElems > elems ) {
                FillWithZeroes fillWithZeroes(reqElems - elems,sym.init());
                dispatchByType(sym.type(),fillWithZeroes);
            }
        } else {
            if ( elems==0 ) {
                FillWithZeroes fillWithZeroes(1,sym.init());
                dispatchByType(sym.type(),fillWithZeroes);
            }
        }

    }
}*/

// TBD095 replace with addSampler, createSamplerInitializer
/*
void Brigantine::CreateSampler(
    const SRef& name,
    const int normalized,
    const Brig::BrigSamplerFilter filter,
    const Brig::BrigSamplerBoundaryMode mode) {

    DirectiveSymbol sym = createCodeRefDir<DirectiveSymbol>();
    sym.type() = Brig::BRIG_TYPE_SAMP;
    sym.name() = name;
    sym.segment() = Brig::BRIG_SEGMENT_GLOBAL;

    DirectiveSamplerInit init = m_container.append<DirectiveSamplerInit>();
    init.modifier().filter() = filter;
    init.modifier().isUnnormalized() = normalized==0;
    init.boundaryU() = mode;
    init.boundaryV() = mode;
    init.boundaryW() = mode;

    sym.init() = init;
    addSymbolToGlobalScope(sym);
}*/

// Brigantine end
}
