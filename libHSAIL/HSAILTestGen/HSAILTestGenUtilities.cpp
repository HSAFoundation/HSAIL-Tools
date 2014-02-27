#include "HSAILTestGenUtilities.h"

#include "HSAILBrigContainer.h"
#include "HSAILItems.h"
#include "Brig.h"

#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

using HSAIL_ASM::DirectiveVersion;
using HSAIL_ASM::DirectiveKernel;
using HSAIL_ASM::DirectiveFunction;
using HSAIL_ASM::DirectiveExecutable;
using HSAIL_ASM::DirectiveVariable;
using HSAIL_ASM::DirectiveLabel;
using HSAIL_ASM::DirectiveComment;
using HSAIL_ASM::DirectiveExtension;
using HSAIL_ASM::DirectiveArgScopeStart;
using HSAIL_ASM::DirectiveArgScopeEnd;
using HSAIL_ASM::DirectiveFbarrier;

using HSAIL_ASM::InstBasic;
using HSAIL_ASM::InstAtomic;
using HSAIL_ASM::InstAtomicImage;
using HSAIL_ASM::InstCmp;
using HSAIL_ASM::InstCvt;
using HSAIL_ASM::InstImage;
using HSAIL_ASM::InstMem;
using HSAIL_ASM::InstMod;
using HSAIL_ASM::InstBr;
using HSAIL_ASM::InstAddr;

using HSAIL_ASM::OperandReg;
using HSAIL_ASM::OperandRegVector;
using HSAIL_ASM::OperandImmed;
using HSAIL_ASM::OperandWavesize;
using HSAIL_ASM::OperandAddress;
using HSAIL_ASM::OperandArgumentList;
using HSAIL_ASM::OperandFunctionRef;
using HSAIL_ASM::OperandLabelRef;
using HSAIL_ASM::OperandFbarrierRef;

using HSAIL_ASM::getTypeSize;
using HSAIL_ASM::isSignedType;
using HSAIL_ASM::isFloatType;
using HSAIL_ASM::isOpaqueType;

namespace TESTGEN {

//=============================================================================
//=============================================================================
//=============================================================================

void BrigContext::emitVersion()
{
    using namespace Brig;

    DirectiveVersion version = container.append<DirectiveVersion>();

    version.hsailMajor()   = BRIG_VERSION_HSAIL_MAJOR;
    version.hsailMinor()   = BRIG_VERSION_HSAIL_MINOR;
    version.brigMajor()    = BRIG_VERSION_BRIG_MAJOR;
    version.brigMinor()    = BRIG_VERSION_BRIG_MINOR;

    version.machineModel() = isSmallModel? BRIG_MACHINE_SMALL : BRIG_MACHINE_LARGE;
    version.profile()      = BRIG_PROFILE_FULL;
    version.code()         = container.insts().end();
}

void BrigContext::emitExtension(const char* name)
{
    DirectiveExtension ext = container.append<DirectiveExtension>();
    ext.name() = name;
    ext.code() = container.insts().end();
}

Operand BrigContext::emitLabelRef(const char* name)
{
    DirectiveLabel lbl = container.append<DirectiveLabel>();
    lbl.name() = name;
    lbl.code() = container.insts().end();

    OperandLabelRef operand = container.append<OperandLabelRef>();
    operand.ref() = lbl;

    return operand;
}

void BrigContext::emitAuxLabel()
{
    ostringstream labName;
    labName << "@aux_label_" << labCount++;
    DirectiveLabel lbl = getContainer().append<DirectiveLabel>();
    lbl.name() = labName.str();
    lbl.code() = getContainer().insts().end();
}

void BrigContext::emitComment(string s)
{
    if (!disableComments) {
        DirectiveComment cmt = getContainer().append<DirectiveComment>();
        cmt.name() = s.c_str();
        cmt.code() = getContainer().insts().end();
    }
}

//=============================================================================
//=============================================================================
//=============================================================================

void BrigContext::emitRet()
{
    Inst inst = container.append<InstBasic>();
    inst.opcode() = Brig::BRIG_OPCODE_RET;
    inst.type() = Brig::BRIG_TYPE_NONE;
}

void BrigContext::emitCodeBlockEnd()
{
    Inst inst = container.append<InstBasic>();
    inst.opcode() = Brig::BRIG_OPCODE_CODEBLOCKEND;
    inst.type() = Brig::BRIG_TYPE_NONE;
}

void BrigContext::emitSt(unsigned type, unsigned segment, Operand from, Operand to)
{
    InstMem inst = getContainer().append<InstMem>();

    inst.opcode()     = Brig::BRIG_OPCODE_ST;
    inst.segment()    = segment;
    inst.type()       = conv2LdStType(type);
    inst.align()      = Brig::BRIG_ALIGNMENT_1;
    inst.width()      = Brig::BRIG_WIDTH_NONE;
    inst.equivClass() = 0;
    inst.modifier().isConst() = false;

    inst.operand(0) = from;
    inst.operand(1) = to;
}

void BrigContext::emitLd(unsigned type, unsigned segment, Operand to, Operand from, unsigned width /*=Brig::BRIG_WIDTH_1*/)
{
    InstMem inst = getContainer().append<InstMem>();

    inst.opcode()     = Brig::BRIG_OPCODE_LD;
    inst.segment()    = segment;
    inst.type()       = conv2LdStType(type);
    inst.width()      = width;
    inst.equivClass() = 0;
    inst.align()      = Brig::BRIG_ALIGNMENT_1;
    inst.modifier().isConst() = false;

    inst.operand(0) = to;
    inst.operand(1) = from;
}

void BrigContext::emitShl(unsigned type, Operand res, Operand src, unsigned shift)
{
    InstBasic inst = getContainer().append<InstBasic>();

    inst.opcode()     = Brig::BRIG_OPCODE_SHL;
    inst.type()       = type;

    inst.operand(0) = res;
    inst.operand(1) = src;
    inst.operand(2) = emitImm(32, shift);
}

void BrigContext::emitMul(unsigned type, Operand res, Operand src, unsigned multiplier)
{
    InstBasic inst = getContainer().append<InstBasic>();

    inst.opcode()     = Brig::BRIG_OPCODE_MUL;
    inst.type()       = type;

    inst.operand(0) = res;
    inst.operand(1) = src;
    inst.operand(2) = emitImm(getTypeSize(type), multiplier);
}

void BrigContext::emitMov(unsigned type, Operand to, Operand from)
{
    InstBasic inst = getContainer().append<InstBasic>();
    inst.opcode()  = Brig::BRIG_OPCODE_MOV;
    inst.type()    = type;

    inst.operand(0) = to;
    inst.operand(1) = from;
}

void BrigContext::emitAdd(unsigned type, Operand res, Operand op1, Operand op2)
{
    InstBasic inst = getContainer().append<InstBasic>();
    inst.opcode()  = Brig::BRIG_OPCODE_ADD;
    inst.type()    = type;

    inst.operand(0) = res;
    inst.operand(1) = op1;
    inst.operand(2) = op2;
}

void BrigContext::emitSub(unsigned type, Operand res, Operand op1, Operand op2)
{
    InstBasic inst = getContainer().append<InstBasic>();
    inst.opcode()  = Brig::BRIG_OPCODE_SUB;
    inst.type()    = type;

    inst.operand(0) = res;
    inst.operand(1) = op1;
    inst.operand(2) = op2;
}

void BrigContext::emitGetWorkItemId(Operand res, unsigned dim)
{
    InstBasic inst   = getContainer().append<InstBasic>();
    inst.opcode()   = Brig::BRIG_OPCODE_WORKITEMABSID;
    inst.type()     = Brig::BRIG_TYPE_U32;
    inst.operand(0) = res;
    inst.operand(1) = emitImm(32, dim);
}

void BrigContext::emitCvt(unsigned dstType, unsigned srcType, OperandReg to, OperandReg from)
{
    InstCvt cvt = getContainer().append<InstCvt>();
    cvt.opcode()     = Brig::BRIG_OPCODE_CVT;
    cvt.type()       = dstType;
    cvt.sourceType() = srcType;

    cvt.operand(0) = to;
    cvt.operand(1) = from;
}

void BrigContext::emitLda(OperandReg dst, DirectiveVariable var)
{
    assert(dst);
    assert(var);

    InstAddr lda = getContainer().append<InstAddr>();

    lda.opcode()    = Brig::BRIG_OPCODE_LDA;
    lda.type()      = getSegAddrType(var.segment());
    lda.segment()   = var.segment();

    lda.operand(0)  = dst;
    lda.operand(1)  = emitAddrRef(var);
}

//=============================================================================
//=============================================================================
//=============================================================================

string BrigContext::getRegName(unsigned size, unsigned idx)
{
    ostringstream name;

    switch(size)
    {
    case 1:      name << "$c";  break;
    case 32:     name << "$s";  break;
    case 64:     name << "$d";  break;
    case 128:    name << "$q";  break;
    default: 
        assert(false);       
        name << "ERR"; 
        break;
    }
    name << idx;

    return name.str();
}

Operand BrigContext::emitReg(SRef regName)
{
    OperandReg opr = getContainer().append<OperandReg>();
    opr.reg()      = regName;
    return opr;
}

Operand BrigContext::emitReg(unsigned size, unsigned idx /*=0*/)
{
    OperandReg opr = getContainer().append<OperandReg>();
    opr.reg()      = getRegName(size, idx);
    return opr;
}

Operand BrigContext::emitRegVector(unsigned cnt, unsigned size, unsigned idx0)
{
    OperandRegVector opr = getContainer().append<OperandRegVector>();

    for(unsigned i = 0; i < cnt; ++i)
    {
        opr.regs().push_back(getRegName(size, idx0 + i));
    }

    return opr;
}

Operand BrigContext::emitRegVector(unsigned cnt, unsigned size, bool isSrc /*=true*/)
{
    assert(2 <= cnt && cnt <= 4);

    OperandRegVector opr = getContainer().append<OperandRegVector>();

    for(unsigned i = 0; i < cnt; ++i)
    {
        opr.regs().push_back(getRegName(size, isSrc? 0 : i));
    }

    return opr;
}

Operand BrigContext::emitWavesize()
{
    OperandWavesize ws = getContainer().append<OperandWavesize>();
    return ws;
}

Operand BrigContext::emitImm(unsigned size /*=32*/, uint64_t lVal /*=0*/, uint64_t hVal /*=0*/)
{
    OperandImmed imm = getContainer().append<OperandImmed>();

    switch(size)
    {
    case 1:      setImmed(imm, (uint8_t)(lVal? 1 : 0)); break;
    case 8:      setImmed(imm, (uint8_t)lVal);          break;
    case 16:     setImmed(imm, (uint16_t)lVal);         break;
    case 32:     setImmed(imm, (uint32_t)lVal);         break;
    case 64:     setImmed(imm, (uint64_t)lVal);         break;
    case 128:    setImmed(imm, HSAIL_ASM::b128_t(lVal, hVal)); break;

    default:
        assert(false);
    }

    return imm;
}

Operand BrigContext::emitFBarrierRef(DirectiveFbarrier fb)
{
    OperandFbarrierRef opr = getContainer().append<OperandFbarrierRef>();
    opr.ref() = fb;

    return opr;
}

Operand BrigContext::emitFuncRef(DirectiveFunction func)
{
    assert(func);

    OperandFunctionRef ref = getContainer().append<OperandFunctionRef>();
    ref.fn() = func;

    return ref;
}

Operand BrigContext::emitAddrRef(Directive var, OperandReg reg, unsigned offset /*=0*/)
{
    assert(reg);

    OperandAddress addr = emitAddrRef(var);
    addr.reg()    = static_cast<SRef>(reg.reg());
    addr.offset() = offset;
    return addr;
}

Operand BrigContext::emitAddrRef(Directive var, unsigned offset /*=0*/)
{
    OperandAddress addr = getContainer().append<OperandAddress>();

    addr.symbol() = var;
    addr.offset() = offset;
    return addr;
}

Operand BrigContext::emitAddrRef(OperandReg reg, uint64_t offset)
{
    assert(reg);

    OperandAddress addr = getContainer().append<OperandAddress>();
    
    addr.reg()    = static_cast<SRef>(reg.reg());
    addr.offset() = offset;
    return addr;
}

Operand BrigContext::emitAddrRef(uint64_t offset)
{
    OperandAddress addr = getContainer().append<OperandAddress>();
    
    addr.offset() = offset;
    return addr;
}

//=============================================================================
//=============================================================================
//=============================================================================

void BrigContext::initSbrDef(DirectiveExecutable sbr, string name)
{
    sbr.name()                     = name;
    sbr.outArgCount()              = 0;
    sbr.inArgCount()               = 0;
    sbr.firstInArg()               = container.directives().end(); // no params
    sbr.modifier().linkage()       = Brig::BRIG_LINKAGE_NONE;
    sbr.modifier().isDeclaration() = false;
    sbr.firstScopedDirective()     = getContainer().directives().end();
    sbr.nextTopLevelDirective()    = getContainer().directives().end();
    sbr.code()                     = getContainer().insts().end();
    sbr.instCount()                = 0;
}

DirectiveKernel BrigContext::emitKernel(string name)
{
    kernel = getContainer().append<DirectiveKernel>();
    initSbrDef(kernel, name);
    return kernel;
}

void BrigContext::registerSbrArgs(DirectiveExecutable sbr)
{
    assert(sbr);

    if (sbr.next() != getContainer().directives().end())
    {
        unsigned params = 0;
        for (Directive d = sbr.next(); d != getContainer().directives().end(); d = d.next()) 
        {
            // firstInArg has been initialized for case outArgCount=0.
            // The following code is used when outArgCount=1.
            if (++params == sbr.outArgCount()) sbr.firstInArg() = d.next();
        }

        assert(sbr.inArgCount() == 0 || (sbr.inArgCount() + sbr.outArgCount()) == params);

        sbr.inArgCount() = params - sbr.outArgCount();
        sbr.firstScopedDirective()  = getContainer().directives().end();
        sbr.nextTopLevelDirective() = getContainer().directives().end();
    }
    else
    {
        assert(sbr.inArgCount() + sbr.outArgCount() == 0);
    }
}

void BrigContext::endSbrBody(DirectiveExecutable sbr)
{
    assert(sbr);

    // This footer is necessary to avoid hanging labels
    // which refer past the end of the code section
    emitAuxLabel();
    emitRet();
    emitCodeBlockEnd();

    unsigned ops = 0;
    for (Inst i = sbr.code(); i != container.insts().end(); i = i.next()) ++ops;
    assert(ops > 0);

    sbr.instCount() = ops;
    sbr.nextTopLevelDirective() = getContainer().directives().end();
}

DirectiveVariable BrigContext::emitArg(unsigned type, string name, unsigned segment /*=Brig::BRIG_SEGMENT_ARG*/)
{
    DirectiveVariable arg = emitSymbol(type, name, segment);
    arg.modifier().isDeclaration() = true;
    return arg;
}

DirectiveVariable BrigContext::emitFuncParams(unsigned num, bool isInputParam)
{
    DirectiveVariable res;
    for (unsigned i = 0; i < num; ++i)
    {
        ostringstream s;
        s << (isInputParam? "%in_arg" : "%out_arg") << i;
        DirectiveVariable arg = emitArg(Brig::BRIG_TYPE_U32, s.str());
        if (!res) res = arg;
    }
    return res;
}

DirectiveFunction BrigContext::emitFuncStart(const char* name, unsigned outParams, unsigned inParams)
{
    DirectiveFunction func = getContainer().append<DirectiveFunction>();
    initSbrDef(func, name);

    func.inArgCount()  = inParams;
    func.outArgCount() = outParams;

    emitFuncParams(outParams, false);
    emitFuncParams(inParams,  true);

    func.code()                  = getContainer().insts().end();
    func.firstScopedDirective()  = getContainer().directives().end();
    func.nextTopLevelDirective() = getContainer().directives().end();

    registerSbrArgs(func);

    return func;
}

void BrigContext::emitFuncEnd(DirectiveFunction func)
{
    endSbrBody(func);
}

Operand BrigContext::emitArgList(unsigned num, bool isInputArg)
{
    using namespace Brig;
    OperandArgumentList list = getContainer().append<OperandArgumentList>();

    if (list.elements().resize(num) != num) {
        throw TestGenError("OperandArgumentList overflow");
    }

    for (unsigned i = 0; i < num; ++i)
    {
        ostringstream s;
        s << (isInputArg? "%iarg" : "%oarg") << i;
        DirectiveVariable arg = emitArg(BRIG_TYPE_U32, s.str());

        list.elements(i) = arg;

        if (isInputArg) // Generate initialization code
        {
            emitSt(BRIG_TYPE_U32, Brig::BRIG_SEGMENT_ARG, emitImm(), emitAddrRef(arg));
        }
    }
    return list;
}

void BrigContext::emitCall(DirectiveFunction func, unsigned outArgs, unsigned inArgs)
{
    DirectiveArgScopeStart s1 = getContainer().append<DirectiveArgScopeStart>();
    s1.code() = getContainer().insts().end();
    {
        OperandFunctionRef target = getContainer().append<OperandFunctionRef>();
        target.fn() = func;

        Operand outList = emitArgList(outArgs, false);
        Operand inList  = emitArgList(inArgs, true);

        InstBr inst = getContainer().append<InstBr>();
        inst.opcode() = Brig::BRIG_OPCODE_CALL;
        inst.type()   = Brig::BRIG_TYPE_NONE;

        inst.operand(0) = outList;
        inst.operand(1) = target;
        inst.operand(2) = inList;

        inst.width()    = getDefWidth(inst); // Depends on operand 1
    }
    DirectiveArgScopeEnd e1 = getContainer().append<DirectiveArgScopeEnd>();
    e1.code() = getContainer().insts().end();
}

unsigned BrigContext::conv2LdStType(unsigned type) // Convert to type supported by ld/st
{
    using namespace Brig;

    if (isSignedType(type) || isFloatType(type) || isOpaqueType(type)) return type;

    switch(getTypeSize(type)) 
    {
    case 8:      return BRIG_TYPE_U8;
    case 16:     return BRIG_TYPE_U16;
    case 32:     return BRIG_TYPE_U32;
    case 64:     return BRIG_TYPE_U64;
    case 128:    return BRIG_TYPE_B128;

    default: 
        assert(false); 
        return BRIG_TYPE_NONE;
    }
}

//=============================================================================
//=============================================================================
//=============================================================================

} // namespace TESTGEN
