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
//===-- HSAILValidator.cpp - HSAIL Validator ------------------------------===//

#include "HSAILValidatorBase.h"
#include "HSAILValidator.h"
#include "HSAILDisassembler.h"
#include "HSAILScanner.h" // using SyntaxError utilities
#include "HSAILItems.h"
#include "HSAILUtilities.h"
#include "Brig.h"

#include <ctype.h>
#include <iosfwd>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <map>

using std::map;
using std::set;
using std::vector;
using std::string;
using std::ostringstream;

using Brig::BRIG_MACHINE_LARGE;
using Brig::BRIG_PROFILE_FULL;
using Brig::BrigUInt64;

using Brig::BRIG_SECTION_INDEX_DATA;
using Brig::BRIG_SECTION_INDEX_CODE;
using Brig::BRIG_SECTION_INDEX_OPERAND;

// ============================================================================
// ============================================================================
//============================================================================

namespace HSAIL_ASM {

//============================================================================
// BRIG Sections

enum {
    BRIG_NUM_SECTIONS       = Brig::BRIG_SECTION_INDEX_BEGIN_IMPLEMENTATION_DEFINED,
    BRIG_MIN_DATA_ITEM_SIZE = 4
};

//============================================================================
// Exceptions

class BrigFormatError
{
public:
    static const int ERRCODE_STD  = 100; // Generic Validator error code
    static const int ERRCODE_INST = 101; // Instruction Validator error code

private:
    string msg;
    int errCode;
    int section;
    unsigned offset;

public:
    BrigFormatError() {}
    BrigFormatError(SRef s, int code = ERRCODE_STD) :
        msg(s.begin, s.end), errCode(code), section(-1), offset(0)
    { };
    BrigFormatError(int sec, unsigned off, SRef s, int code = ERRCODE_STD) :
        msg(s.begin, s.end), errCode(code), section(sec), offset(off)
    {
        assert(0 <= section && section < BRIG_NUM_SECTIONS);
    };
    ~BrigFormatError() {}

public:
    const char *what()    const { return msg.c_str(); };
    int getSection()      const { return section; }
    unsigned getOffset()  const { return offset; }
    unsigned getErrCode() const { return errCode; }
    bool empty()          const { return msg.empty(); }
    void clear()                { msg.clear(); }
};

void PropValidator::validate(Inst inst, int operandIdx, bool cond, SRef msg)
{
    assert(inst);

    if (!cond)
    {
        int code = BrigFormatError::ERRCODE_INST;
        if (0 <= operandIdx && operandIdx <= 4 && inst.operand(operandIdx))
        {
            Operand opr = inst.operand(operandIdx);
            throw BrigFormatError(BRIG_SECTION_INDEX_OPERAND, opr.brigOffset(), msg, code);
        }
        else
        {
            throw BrigFormatError(BRIG_SECTION_INDEX_CODE, inst.brigOffset(), msg, code);
        }
    }
}

} // namespace HSAIL_ASM

//============================================================================
//============================================================================
//============================================================================
// Instruction Validator

//F Make it a separate component

#include "HSAILInstValidation_gen.hpp"

//============================================================================
//============================================================================
//============================================================================

namespace HSAIL_ASM {

static unsigned getOperandAttr(InstValidator& prop, Inst inst, unsigned operandIdx, unsigned machineModel)
{
    switch(operandIdx)
    {
    case 0: return prop.getOperand0Attr(inst);
    case 1: return prop.getOperand1Attr(inst);
    case 2: return prop.getOperand2Attr(inst);
    case 3: return prop.getOperand3Attr(inst);
    case 4: return prop.getOperand4Attr(inst);
    default:
        assert(false);
        return OPERAND_ATTR_INVALID;
    }
}

unsigned getOperandType(Inst inst, unsigned operandIdx, unsigned machineModel, unsigned profile)
{
    using namespace Brig;
    assert(operandIdx < 5);
    assert(machineModel == BRIG_MACHINE_SMALL || machineModel == BRIG_MACHINE_LARGE);
    assert(profile == Brig::BRIG_PROFILE_BASE  || profile == Brig::BRIG_PROFILE_FULL);

    InstValidator prop(machineModel, profile);
    unsigned attr = getOperandAttr(prop, inst, operandIdx, machineModel);

    switch(attr)
    {
    case OPERAND_ATTR_INVALID:  return BRIG_TYPE_INVALID;
    case OPERAND_ATTR_NONE:     return BRIG_TYPE_NONE;

    case OPERAND_ATTR_SEG:
    case OPERAND_ATTR_TSEG:     return getSegAddrSize(getSegment(inst), machineModel == BRIG_MACHINE_LARGE) == 32? BRIG_TYPE_U32 : BRIG_TYPE_U64;

    default:                    return prop.attr2type(inst, operandIdx, attr);
    }
}

// Validate values of instruction fields which affect possible operand types
static const char* validateOperandDeps(Inst inst, unsigned operandIdx, unsigned machineModel, unsigned profile)
{
    using namespace Brig;
    assert(operandIdx < 5);
    assert(machineModel == BRIG_MACHINE_SMALL || machineModel == BRIG_MACHINE_LARGE);

    InstValidator prop(machineModel, profile);
    unsigned attr = getOperandAttr(prop, inst, operandIdx, machineModel);

    switch(attr)
    {
    case OPERAND_ATTR_NONE:     return 0; // Cannot report anything as there are optional operands //F Could it be improved?
    case OPERAND_ATTR_INVALID:  return 0; // Refrain reporting an error as validator will provide better explanation

    case OPERAND_ATTR_P2U:
    case OPERAND_ATTR_DTYPE:    if (!typeX2str(inst.type()))       return "Invalid instruction type";
                                if (inst.type() == BRIG_TYPE_NONE) return "Missing instruction type";
                                break;

    case OPERAND_ATTR_STYPE:    if (!typeX2str(getSrcType(inst)))       return "Invalid source type";
                                if (getSrcType(inst) == BRIG_TYPE_NONE) return "Missing source type";
                                break;

    case OPERAND_ATTR_CTYPE:    if (!typeX2str(getCrdType(inst)))       return "Invalid coord type";
                                if (getCrdType(inst) == BRIG_TYPE_NONE) return "Missing coord type";
                                break;

    case OPERAND_ATTR_ITYPE:    if (!typeX2str(getImgType(inst)))       return "Invalid image type";
                                if (getImgType(inst) == BRIG_TYPE_NONE) return "Missing image type";
                                break;

    case OPERAND_ATTR_SEG:
    case OPERAND_ATTR_TSEG:     if (!segment2str(getSegment(inst)))        return "Invalid segment";
                                if (getSegment(inst) == BRIG_SEGMENT_NONE) return "Missing segment";
                                break;

    default:
        break;
    }

    return 0;
}

const char* preValidateInst(Inst inst, unsigned machineModel, unsigned profile)
{
    for (unsigned idx = 0; idx < 5; ++idx)
    {
        const char* err = validateOperandDeps(inst, idx, machineModel, profile);
        if (err) return err;
    }
    return 0;
}

//============================================================================
//============================================================================
//============================================================================

unsigned getDefWidth(Inst inst, unsigned machineModel, unsigned profile)
{
    using namespace Brig;
    assert(machineModel == BRIG_MACHINE_SMALL || machineModel == BRIG_MACHINE_LARGE);

    InstValidator prop(machineModel, profile);
    unsigned attr = prop.getWidthAttr(inst);

    switch(attr)
    {
    case WIDTH_ATTR_NONE:       return BRIG_WIDTH_NONE;
    case WIDTH_ATTR_ALL:        return BRIG_WIDTH_ALL;
    case WIDTH_ATTR_WAVESIZE:   return BRIG_WIDTH_WAVESIZE;
    case WIDTH_ATTR_1:          return BRIG_WIDTH_1;

    // Instruction is either malformed or does not support 'width'
    // Should be assert'ed, but this would break generation of negative tests
    case WIDTH_ATTR_INVALID:    return BRIG_WIDTH_NONE;

    default:
        assert(false);
        return BRIG_WIDTH_NONE;
    }
}

unsigned getDefRounding(Inst inst, unsigned machineModel, unsigned profile)
{
    using namespace Brig;
    assert(machineModel == BRIG_MACHINE_SMALL || machineModel == BRIG_MACHINE_LARGE);

    InstValidator prop(machineModel, profile);
    unsigned attr = prop.getRoundAttr(inst);

    switch(attr)
    {
    case ROUND_ATTR_NONE:       return BRIG_ROUND_NONE;
    case ROUND_ATTR_DEFAULT:    return BRIG_ROUND_FLOAT_DEFAULT;
    case ROUND_ATTR_ZERO:       return BRIG_ROUND_INTEGER_ZERO;

    // Instruction is either malformed or does not support 'rounding'
    // Should be assert'ed, but this would break generation of negative tests
    case ROUND_ATTR_INVALID:    return BRIG_ROUND_NONE;

    default:
        assert(false);
        return BRIG_WIDTH_NONE;
    }
}

//============================================================================
//============================================================================
//============================================================================

struct BrigHelper
{
public: // Brig Object Kind Identification

    static bool isSbr(Code d)
    {
        return DirectiveExecutable(d);
    }

    static bool isFunc(Code d)
    {
        return DirectiveFunction(d) || DirectiveIndirectFunction(d);
    }

    static bool isSignature(Code d)
    {
        return DirectiveSignature(d);
    }

    static bool isKernel(Code d)
    {
        return DirectiveKernel(d);
    }

    static bool isVar(Code d)
    {
        return DirectiveVariable(d);
    }

    static bool isFbar(Code d)
    {
        return DirectiveFbarrier(d);
    }

    static bool isLabel(Code d)
    {
        return DirectiveLabel(d);
    }

public: // Brig Object Properties

    static char getNamePref(Code d)
    {
        string name = getName(d);
        return name.empty()? 0 : name[0];
    }

    static bool isArgSeg(Code d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(Directive(d)) == Brig::BRIG_SEGMENT_ARG;
    }

    static bool isKernArgSeg(Code d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(Directive(d)) == Brig::BRIG_SEGMENT_KERNARG;
    }

    static bool isSpillSeg(Code d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(Directive(d)) == Brig::BRIG_SEGMENT_SPILL;
    }

    static bool isGlobalSeg(Code d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(Directive(d)) == Brig::BRIG_SEGMENT_GLOBAL;
    }

    static bool isGroupSeg(Code d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(Directive(d)) == Brig::BRIG_SEGMENT_GROUP;
    }

    static bool isPrivateSeg(Code d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(Directive(d)) == Brig::BRIG_SEGMENT_PRIVATE;
    }

    static bool isReadonlySeg(Code d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(Directive(d)) == Brig::BRIG_SEGMENT_READONLY;
    }

    static bool isProgLinkage(Code d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_PROGRAM;
    }

    static bool isModuleLinkage(Code d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_MODULE;
    }

    static bool isFuncLinkage(Code d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_FUNCTION;
    }

    static bool isArgLinkage(Code d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_ARG;
    }

    static bool isNoneLinkage(Code d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_NONE;
    }

    static uint64_t getArraySize(Code d) //F1.0 rename
    {
        if (DirectiveVariable sym = d) return sym.dim();
        assert(false);
        return 0;
    }

    static unsigned getAlignment(Code d)
    {
        assert(isVar(d));
        if (DirectiveVariable sym = d) return sym.align();
        assert(false);
        return Brig::BRIG_ALIGNMENT_LAST;
    }

    static unsigned getAllocation(Code d)
    {
        assert(isVar(d) || isFbar(d));
        if (DirectiveVariable sym = d) return sym.allocation();
        return Brig::BRIG_ALLOCATION_NONE;
    }

    static bool isConst(Code d)
    {
        if (DirectiveVariable sym = d) return sym.modifier().isConst();
        assert(false);
        return false;
    }

    static bool isArray(Code d)
    {
        if (DirectiveVariable sym = d) return sym.isArray();
        assert(false);
        return false;
    }

    static bool isInitialized(Code d)
    {
        if (DirectiveVariable sym = d) return sym.init();
        return false;
    }

/*    static Directive getInitializer(Code d)
    {
        assert(isVar(d));

        if (DirectiveVariable sym = d) return sym.init();
        return Directive();
    }
*/
    static unsigned getParamNum(Code d)
    {
        if (DirectiveExecutable exec = d) return exec.inArgCount() + exec.outArgCount();

        assert(false);
        return 0;
    }

    static unsigned getInParamNum(Code d)
    {
        if (DirectiveExecutable exec = d) return exec.inArgCount();

        assert(false);
        return 0;
    }

    static unsigned getOutParamNum(Code d)
    {
        if (DirectiveExecutable exec = d) return exec.outArgCount();

        assert(false);
        return 0;
    }

    static Code getFirstInParam(Code d)
    {
        if (DirectiveExecutable exec = d) return exec.firstInArg();

        assert(false);
        return Code();
    }

    static Code getFirstOutParam(Code d)
    {
        if (DirectiveExecutable exec = d) return exec.next();

        assert(false);
        return Code();
    }

    static unsigned getScopedSize(Code d)
    {
        if (DirectiveExecutable exec = d)
        {
            //F1.0
            unsigned cnt = 0;
            for (Code i = exec.firstCodeBlockEntry(); i != exec.nextModuleEntry(); i = i.next()) ++cnt;
            return cnt;
        }

        assert(false);
        return 0;
    }

    static Code getFirstScoped(Code d)
    {
    	if (DirectiveExecutable dfc = d) return dfc.firstCodeBlockEntry();

        assert(false);
        return d.next();
    }

    static Code getNextTopLevel(Code d)
    {
        if (DirectiveExecutable exec = d) return exec.nextModuleEntry();
        else return d.next();
    }

};

//=============================================================================
// THE PURPOSE OF THIS CLASS IS TO PERFORM CONTEXT-SENSITIVE DEF-USE VALIDATION
//=============================================================================
//
// For proper validation, client must ensure:
//
// - correct context switching;
// - registration of all definitions;
// - registration of all uses.
//
// See description of public API below.

class ValidatorContext : public BrigHelper
{
private:
    typedef set<SRef> NameSet;
    typedef map<SRef, Code> NameMap;
    typedef map<Offset, Inst> LabelMap;

    enum // See HSAIL limits
    {
        MAX_CTL_POOL_SIZE = 128,
        MAX_REG_POOL_SIZE = 2048
    };

    enum State
    {
        STATE_INVALID,
        STATE_ANN_SCOPE,        // Annotation scope (before version directive)
        STATE_VER_SCOPE,        // Version scope (after version directive but before declarations and definitions)
        STATE_MDL_SCOPE,        // Module scope (starts with first declaration or definition)
        STATE_SBR_CTL_SCOPE,    // Subroutine (Kernel/Function) scope before first var/fbar definition
        STATE_SBR_DEF_SCOPE,    // Subroutine (Kernel/Function) scope before first statement
        STATE_SBR_STT_SCOPE,    // Subroutine (Kernel/Function) scope after first statement
        STATE_ARG_DEF_SCOPE,    // Argument scope before first statement
        STATE_ARG_STT_SCOPE     // Argument scope after first statement
    };

    enum Extension
    {
        EXTENSIONS_NONE   = 0, // No extensions

        EXTENSION_CORE    = 1, // CORE extension
        EXTENSION_IMAGE   = 2, // IMAGE extension
        EXTENSION_GCN     = 4, // GCN extension
        EXTENSION_UNKNOWN = 8  // Unknown extension
    };

private:
    unsigned sbrStartOffset;    // Start offset of current function/kernel scope
    unsigned sbrEndOffset;      // End offset of current function/kernel scope

private:
    BrigContainer &brig;        // BRIG container being validated

private: // Context state
    State    state;         // Context state: module/sbr/block scope
    unsigned callsNum;      // Number of call instructions in the current code block
    int64_t  cRegMax;       // Max index of used 'c' registers
    int64_t  sRegMax;       // Max index of used 's' registers
    int64_t  dRegMax;       // Max index of used 'd' registers
    int64_t  qRegMax;       // Max index of used 'q' registers

private: // Enabled extensions
    unsigned extensions;     // enabled extensions

    // Labels may be defined in two places:
    // - in an argument block.
    // - in func/kernel body, but outside of argument blocks.
    //
    // Instructions in an arg block may only refer labels defined in the same arg block.
    // Instructions outside of arg blocks may only refer labels defined outside arg blocks.
    // Pragma directive placed inside a code block may refer any labels defined in this block
    //
    // Note that labels share a single namespace, so a label with the same name
    // cannot be defined both inside and outside of an argument block.
    // Consequently, there is only one 'labelNames'
private:
    set<Offset> argLabelsDef;   // d-offset of visible arg-scope label definition
    LabelMap    argLabelsUse;   // d-offset of visible arg-scope label definition set at first FORWARD reference
    set<Offset> sbrLabelsDef;   // d-offset of visible sbr-scope label definition
    LabelMap    sbrLabelsUse;   // d-offset of visible sbr-scope label definition set at first FORWARD reference
    NameSet     labelNames;     // names of all labels in the current func/kernel

    // This set is used for validation of 'call' arguments:
    // - to ensure that each variable defined in arg block is used exactly once in the list of call arguments
private:
    set<Offset> callArgs;       // d-offset of call args

private:
    set<Offset> inArgDefs;      // d-offset of input args
    set<Offset> outArgDefs;     // d-offset of output args

private: // Local variables (sbr-scoped and blk-scoped)
    set<Offset> argVarDefs;     // d-offsets of visible arg-scoped symbols
    set<Offset> sbrVarDefs;     // d-offsets of visible sbr-scoped symbols
    NameSet     argVarNames;    // names of visible arg-scoped symbols
    NameSet     sbrVarNames;    // names of visible sbr-scoped symbols

private: // Global (module-scope) identifiers (variables, functions, kernels)
    NameSet     modSymUsed;     // symbols used by module (to check that used module symbols are defined)
    NameMap     modSymDesc;     // pairs [name, directive] - used to validate that symbols are defined/declared before use
    NameMap     modSymRef;      // pairs [name, directive] - used to identify def/decl of module symbols which should be referred to by operands
                                //                           (either definition or first declaration if not defined)

private:
    ValidatorContext(const ValidatorContext&); // non-copyable
    const ValidatorContext &operator=(const ValidatorContext &);  // not assignable

public:
    ValidatorContext(BrigContainer &c)
        : brig(c), state(STATE_INVALID), callsNum(0) {}

public:
    //-------------------------------------------------------------------------
    // PUBLIC API TO CONTROL CONTEXT
    //-------------------------------------------------------------------------
    // Validation of order in a module:
    // 1. annotations
    // 2. version
    // 3. extension and annotations
    // 4. statements and annotations
    //-------------------------------------------------------------------------
    // Validation of order in a code block:
    // 1. control directives and annotations
    // 2. variable/fbarrier devinition and annotations
    // 3. extension and annotations
    // 4. statements and annotations
    //-------------------------------------------------------------------------
    // Validation of order in an arg block:
    // 1. variable devinition and annotations
    // 2. statements and annotations
    //-------------------------------------------------------------------------

    void notifyModuleStart()        { assert(state == STATE_INVALID);        state = STATE_ANN_SCOPE;       }
    void notifyModuleEnd()          { assert(isMdlScope());                  state = STATE_INVALID;         }
    void notifySbrStart()           { assert(isMdlScope());                  state = STATE_SBR_CTL_SCOPE;   }
    void notifySbrEnd()             { assert(isSbrScope());                  state = STATE_MDL_SCOPE;       }
    void notifyVersion(Code c)      { assert(state == STATE_ANN_SCOPE);      state = STATE_VER_SCOPE;       }
    void notifyAnnotation(Code c)   {}

    void notifyExtension(Code c)
    {
        validate(c, state == STATE_VER_SCOPE, "Extension directives must appear after version directive but before other directives");
        addExtension(c);
    }

    void notifyDefDecl(Code c)
    {
        validate(c, state != STATE_ANN_SCOPE,                                     "Missing version directive");
        validate(c, state != STATE_SBR_STT_SCOPE && state != STATE_ARG_STT_SCOPE, "Variable declarations must precede labels and instructions");

        if      (state == STATE_VER_SCOPE     || state == STATE_MDL_SCOPE)     state = STATE_MDL_SCOPE;
        else if (state == STATE_SBR_CTL_SCOPE || state == STATE_SBR_DEF_SCOPE) state = STATE_SBR_DEF_SCOPE;
        else if (state == STATE_ARG_DEF_SCOPE)                                 state = STATE_ARG_DEF_SCOPE;
    }

    void notifyControl(Code c)
    {
        validate(c, state == STATE_SBR_CTL_SCOPE, "Control directive(s) must appear before other directives and operations in code block");
    }

    void notifyArgBlkStart(Code c)
    {
        validate(c, isSbrScope(), "Nested arg blocks are not supported");
        state = STATE_ARG_DEF_SCOPE;
        startArgBlock();
    }

    void notifyArgBlkEnd(Code c)
    {
        validate(c, isArgScope(), "Missing arg block start");
        endArgBlock(c);
        state = STATE_SBR_STT_SCOPE;
    }

    void notifyInst(Code c)
    {
        if      (isSbrScope()) state = STATE_SBR_STT_SCOPE;
        else if (isArgScope()) state = STATE_ARG_STT_SCOPE;
        else                   assert(false);
    }

    void notifyLabel(Code c) { notifyInst(c); }

    void notifyRegister(OperandRegister reg)
    {
        assert(isSbrScope() || isArgScope());
        assert(reg);

        updateRegPool(reg.regKind(), reg.regNum());
    }

public:
    //-------------------------------------------------------------------------
    // PUBLIC API TO CHECK CURRENT CONTEXT
    //-------------------------------------------------------------------------
    bool isMdlScope() const { return state == STATE_VER_SCOPE     || state == STATE_MDL_SCOPE; }
    bool isSbrScope() const { return state == STATE_SBR_CTL_SCOPE || state == STATE_SBR_DEF_SCOPE || state == STATE_SBR_STT_SCOPE; }
    bool isArgScope() const { return state == STATE_ARG_DEF_SCOPE || state == STATE_ARG_STT_SCOPE; }

public:
    //-------------------------------------------------------------------------
    // PUBLIC API TO CONTROL AND SWITCH MODULE CONTEXT
    //-------------------------------------------------------------------------

    void startModule()
    {
        notifyModuleStart();
        clearExtensions();
    }

    void endModule()
    {
        notifyModuleEnd();
        validateModuleDefs(); // NB: must go first!
        clearSymbols();
    }

    void startSbr(DirectiveExecutable d)
    {
        assert(d);

        notifySbrStart();

        sbrStartOffset = d.brigOffset();
        sbrEndOffset   = getNextTopLevel(d).brigOffset();

        Code arg = d.next();
        for (unsigned argsNum = getOutParamNum(d); argsNum > 0; --argsNum)
        {
            assert(arg);
            defineOutArg(arg, d);
            arg = arg.next();
        }
        for (unsigned argsNum = getInParamNum(d); argsNum > 0; --argsNum)
        {
            assert(arg);
            defineInArg(arg, d);
            arg = arg.next();
        }

        clearRegPool();
    }

    void endSbr(DirectiveExecutable d)
    {
        assert(d);
        assert(isSbrScope());

        validateLabels();
        validateRegPoolSize(d);

        clearLabels();
        clearSymbols();
        notifySbrEnd();
    }

    void startArgBlock()
    {
        callsNum = 0;
    }

    void endArgBlock(Code c)
    {
        validate(c, callsNum == 1, "Arg block must include exactly one call operation");
        validateLabels();
        clearLabels();
        clearSymbols();
        clearArgs(c);
    }

    void startCall(Inst i)
    {
        assert(isArgScope());
        validate(i, callsNum == 0, "Arg block cannot include more than one call operation");
    }

    void endCall(Inst i)
    {
        assert(isArgScope());
        ++callsNum;
    }

public:
    //-------------------------------------------------------------------------
    // PUBLIC API TO DEFINE SYMBOLS AND VALIDATE THEIR USE IN CODE
    //-------------------------------------------------------------------------

    void defineLabel(DirectiveLabel lab)
    {
        assert(!isLabelDefined(lab));
        setLabelDef(lab);
    }

    void checkLabelUse(Code owner, DirectiveLabel lab)
    {
        assert(owner);
        assert(lab);

        if (!isLabelDefined(lab))
        {
            setForwLabelRef(owner, lab);
        }
    }

    void defineOutArg(Code d, Code owner)
    {
        if (isFunc(owner)) outArgDefs.insert(d.brigOffset());
        defineVar(d, owner);
    }

    void defineInArg(Code d, Code owner)
    {
        if (isFunc(owner)) inArgDefs.insert(d.brigOffset());
        defineVar(d, owner);
    }

    void defineVar(Code d, Code owner = Code())
    {
        assert(isVar(d) || isFbar(d));

        using namespace Brig;

        bool isArgument = owner;
        bool isSigScope = owner && (isDecl(owner) || isSignature(owner));

        if (isKernArgSeg(d))
        {
            validate(d, isKernel(owner), "Kernarg segment variables must be declared as kernel arguments");
        }
        else if (isArgSeg(d))
        {
            validate(d, isArgument || isArgScope(),
                     "Arg segment variables must be declared as function/signature arguments or defined in an arg scope");
        }

        if (isArgument)
        {
            validate(d, isDef(d), "Formal arguments are implicitly definitions and cannot have declarations");

            if (isSigScope)
            {
                validate(d, isNoneLinkage(d), "Formal arguments of function/kernel declaration and sinatures must have none linkage");
            }
            else
            {
                validate(d, isFuncLinkage(d), "Formal arguments of function/kernel definitions must have function linkage");
            }

            validate(d, getAllocation(d) == BRIG_ALLOCATION_AUTOMATIC, "Formal arguments of functions, kernels and sinatures must have automatic allocation");
        }
        else if (isArgScope())
        {
            validate(d, !isFbar(d),      "Fbarrier cannot be defined in an arg scope");
            validate(d, isArgSeg(d),     "Only arg segment variables may be defined in an arg scope");
            validate(d, isDef(d),        "Arg scope variables cannot have declarations");
            validate(d, isArgLinkage(d), "Arg scope variables must have arg linkage");
            validate(d, getAllocation(d) == BRIG_ALLOCATION_AUTOMATIC, "Arg scope variables must have automatic allocation");
        }
        else if (isSbrScope())
        {
            validate(d, isDef(d),         "Function scope variables and fbarriers cannot have declarations");
            validate(d, isFuncLinkage(d), "Function scope variables and fbarriers must have function linkage");
        }
        else
        {
            validate(d, isProgLinkage(d) || isModuleLinkage(d), "Module scope variables and fbarriers must have program or module linkage");
            
            if (isVar(d) && isArray(d) && getArraySize(d) == 0) // Formal arguments and scoped definitions are validated elsewhere
            {
                validate(d, isDecl(d), "Module scope array without specified size may only be a declaration");
            }
        }

        if (getName(d).length() == 0)
        {
            validate(d, isSignature(owner), "Empty name is only allowed for signature arguments");
        }
        else if (getNamePref(d) == '%')
        {
            addLocalSym(d, isArgument);
        }
        else
        {
            addGlobalSym(d);
        }
    }

    void checkVarUse(Operand opr, Code d)
    {
        assert(isVar(d) || isFbar(d));

        checkSymUse(opr, d);
    }

    bool isTransientArg(Code d) // True for arg variables defined inside an arg scope
    {
        assert(isVar(d));
        Offset off = d.brigOffset();
        return isArgSeg(d) && argVarDefs.count(off) > 0;
    }

    bool isInArg(DirectiveVariable d)
    {
        assert(d);
        return inArgDefs.count(d.brigOffset()) != 0;
    }

    bool isOutArg(DirectiveVariable d)
    {
        assert(d);
        return outArgDefs.count(d.brigOffset()) != 0;
    }

    void registerCallArg(Inst inst, Code arg, bool isOutArgs)
    {
        Offset off = arg.brigOffset();

        validate(inst, isTransientArg(arg), "Call arguments must be defined in arg scope");
        validate(inst, callArgs.count(off) == 1, "Each variable must appear exactly once in the list of call arguments");

        callArgs.erase(off);
    }

    void defineSbr(Code d)
    {
        assert(d);
        assert(isMdlScope());
        addGlobalSym(d);
    }

    void checkSbrUse(Operand opr, DirectiveExecutable f)
    {
        assert(f);
        checkSymUse(opr, f);
    }

    void markSymUsed(Code d)
    {
        assert(d);
        assert(isVar(d) || isFbar(d) || isSbr(d));

        modSymUsed.insert(getName(d));
    }

public:
    // Register a definition or declaration of a global symbol.
    // The purpose is to identify directive which should be used for all references
    // to this symbol - the first definition (or first declaration if there are no definitions).
    void registerGlobalSym(Code d)
    {
        assert(isVar(d) || isFbar(d) || isSbr(d));

        NameMap &desc = modSymRef;

        if (desc.count(getName(d)) == 0 || isDef(d))  // This is the first definition/declaration
        {
            desc[getName(d)] = d;
        }
    }

    // Check if the specified directive is the one which must be used for
    // all references to the corresponding symbol
    bool isValidGlobalReference(Code d)
    {
        assert(isVar(d) || isFbar(d) || isSbr(d));

        NameMap &desc = modSymRef;
        return desc.count(getName(d)) > 0 && desc[getName(d)] == d;
    }

public: // Extensions
    void addExtension(DirectiveExtension ext)
    {
        if (ext.name() == "CORE")
        {
            validate(ext, extensions == EXTENSIONS_NONE || extensions == EXTENSION_CORE, "'CORE' extension is incompatible with any other extension");
            extensions = EXTENSION_CORE;
        }
        else
        {
            validate(ext, extensions == EXTENSIONS_NONE || extensions != EXTENSION_CORE, "No extensions are compatible with 'CORE' extension");

            if      (ext.name() == "amd:gcn") extensions |= EXTENSION_GCN;
            else if (ext.name() == "IMAGE")   extensions |= EXTENSION_IMAGE;
            else                              extensions |= EXTENSION_UNKNOWN;
        }
    }

    void clearExtensions() { extensions = EXTENSIONS_NONE; }

    void validateExtensionOpcode(Inst inst)
    {
        if      (isGcnInst(inst.opcode()))   validate(inst, (extensions & EXTENSION_GCN) != 0,   "GCN extension is not enabled");
        else if (isImageInst(inst.opcode())) validate(inst, (extensions & EXTENSION_IMAGE) != 0, "IMAGE extension is not enabled");
    }

private:
    //-------------------------------------------------------------------------
    // Implementation: REGISTER POOL
    //-------------------------------------------------------------------------

    void clearRegPool()
    {
        cRegMax = -1;
        sRegMax = -1;
        dRegMax = -1;
        qRegMax = -1;
    }

    void updateRegPool(unsigned type, int64_t idx)
    {
        using namespace Brig;

        switch(type)
        {
        case BRIG_REGISTER_KIND_CONTROL: cRegMax = std::max(cRegMax, idx); break;
        case BRIG_REGISTER_KIND_SINGLE:  sRegMax = std::max(sRegMax, idx); break;
        case BRIG_REGISTER_KIND_DOUBLE:  dRegMax = std::max(dRegMax, idx); break;
        case BRIG_REGISTER_KIND_QUAD:    qRegMax = std::max(qRegMax, idx); break;
        default:
            assert(0); // Validated on previous steps
            break;
        }
    }

    string regPoolError(DirectiveExecutable d, bool isCtlError)
    {
        string msg = isCtlError? "Number of control registers " : "Number of 's', 'd' and 'q' registers ";
        return msg + (isKernel(d)? "in kernel " : "in function ") + d.name().str() + " exceeds current HSAIL limitation";
    }

    void validateRegPoolSize(DirectiveExecutable d)
    {
        if ((cRegMax + 1) > MAX_CTL_POOL_SIZE)
        {
            validate(d, false, regPoolError(d, true));
        }
        else if ((sRegMax + 1) + 2 * (dRegMax + 1) + 4 * (qRegMax + 1) > MAX_REG_POOL_SIZE)
        {
            validate(d, false, regPoolError(d, false));
        }
    }

private:
    //-------------------------------------------------------------------------
    // Implementation: LABELS
    //-------------------------------------------------------------------------

    set<Offset>& getLabelDefs()
    {
        return isArgScope()? argLabelsDef : sbrLabelsDef;
    }

    LabelMap& getLabelUses()
    {
        return isArgScope()? argLabelsUse : sbrLabelsUse;
    }

    bool isLabelDefined(DirectiveLabel lab)
    {
        return getLabelDefs().count(lab.brigOffset()) > 0;
    }

    void setLabelDef(DirectiveLabel lab)
    {
        assert(!isLabelDefined(lab));

        validate(lab, labelNames.count(lab.name()) == 0, "Duplicate label name");

        labelNames.insert(lab.name());
        getLabelDefs().insert(lab.brigOffset());
    }

    void setForwLabelRef(Code owner, DirectiveLabel lab)
    {
        assert(!isLabelDefined(lab));
        if (DirectivePragma p = owner) // labels have function scope and pragma may refer any label defined in current sbr
        {
            unsigned labOffset = lab.brigOffset();
            validate(owner, sbrStartOffset <= labOffset && labOffset < sbrEndOffset, "Invalid reference to label defined in another scope");
        }
        else
        {
            assert(Inst(owner));
            getLabelUses()[lab.brigOffset()] = owner;
        }
    }

    void validateLabels()
    {
        set<Offset> &defs = getLabelDefs();
        LabelMap &uses = getLabelUses();

        for (LabelMap::iterator it = uses.begin(); it != uses.end(); ++it)
        {
            validate(it->second, defs.count(it->first) > 0, "Invalid reference to label defined in another scope");
        }
    }

    void clearLabels()
    {
        getLabelDefs().clear();
        getLabelUses().clear();
        if (!isArgScope())
        {
            labelNames.clear();
        }
    }

    /*void dumpDefinedLabels()
    {
        set<Offset> &defs = getLabelDefs();

        std::cerr << "=====================================================\n";
        std::cerr << "Labels defined in this scope:\n";
        std::cerr << "\n";

        for (set<Offset>::iterator it = defs.begin(); it != defs.end(); ++it)
        {
            DirectiveLabel lab(&brig, *it);
            std::cerr << "    " << lab.name() << " = &(" << lab.next().brigOffset() << ")\n";
        }
        std::cerr << "\n";
    }*/

private:
    //-------------------------------------------------------------------------
    // Implementation: VARIABLES, FUNCTIONS, KERNELS
    //-------------------------------------------------------------------------

    // Local symbols cannot be declared, only defined.
    // Consequently, we only check that the symbol is not redefined
    void addLocalSym(Code d, bool isArgument)
    {
        assert(isVar(d) || isFbar(d));

        validate(d, isSbrScope() || isArgScope(),
                 "Variables starting with '%' must be defined in kernels or functions");

        if (isArgScope())
        {
            assert(isArgSeg(d)); // already validated

            validate(d, argVarNames.count(getName(d)) == 0, "Invalid variable redefinition");
            argVarDefs.insert(d.brigOffset());
            argVarNames.insert(getName(d));
            callArgs.insert(d.brigOffset());
        }
        else
        {
            assert(isArgument || !isArgSeg(d));

            validate(d, sbrVarNames.count(getName(d)) == 0, SRef(isArgument? "Duplicate argument declaration" : "Invalid variable redefinition"));
            sbrVarDefs.insert(d.brigOffset());
            sbrVarNames.insert(getName(d));
        }
    }

    // Global symbols can be both declared and defined.
    // Consequently, we check that:
    // - the symbol is defined only once;
    // - if there are several declarations (and possibly a definition), they are identical.
    void addGlobalSym(Code d)
    {
        assert(isVar(d) || isFbar(d) || isSbr(d));

        validate(d, isMdlScope(),
                 "Identifiers starting with '&' must be defined outside of kernels and functions");

        validateDecl(d, modSymDesc);
    }

    void validateDecl(Code d, NameMap &desc)
    {
        assert(isVar(d) || isFbar(d) || isSbr(d));

        if (desc.count(getName(d)) == 0)    // This is the first definition/declaration
        {
            desc[getName(d)] = d;
        }
        else                                // This must be a redefinition of the same entity
        {
            Code prev = desc[getName(d)];

            validate(d, d.kind() == prev.kind(),
                     "Invalid identifier redefinition");

            // There may be only one definition
            validate(d, isDecl(d) || isDecl(prev),
                     "Invalid identifier redefinition");

            // validate that both decl are identical
            validate(d, eqDecl(d, prev),
                     "Incompatible identifier declarations");

            if (isDef(d))
            {
                desc[getName(d)] = d;       // Replace declaration with definition
            }
        }
    }

    void checkSymUse(Operand opr, Code d)
    {
        assert(isVar(d) || isFbar(d) || isSbr(d));

        Offset off = d.brigOffset();

        if (getNamePref(d) == '&') // There are special rules for references to global identifiers
        {
            // Make sure that there is a declaration or definition of this symbol visible in the current scope
            validate(opr, modSymDesc.count(getName(d)) > 0, "Identifier is not defined/declared or is not visible in the current scope");

            // Make sure that reference goes to definition (or first declaration if there is no definition)
            validate(opr, isValidGlobalReference(d), "Invalid reference to identifier; must refer definition (or first declaration if not defined)");
        }
        else // Local identifiers are simpler to check as they have one definition and no declarations
        {
            // Make sure that there is a definition of this symbol visible in the current scope
            validate(opr, argVarDefs.count(off) > 0 ||
                          sbrVarDefs.count(off) > 0,
                          "Identifier is not defined/declared or is not visible in the current scope");

            // If there are 2 symbols with the same name, one defined outside of an arg block,
            // and another inside the block, the latter hides the former and the latter
            // should be used for all references to that name in the arg block.
            if (isArgScope() && argVarNames.count(getName(d)) > 0)
            {
                validate(opr, argVarDefs.count(off) > 0, "Invalid reference to symbol hidden in arg scope by an argument");
            }
        }
    }

    bool eqDecl(Code d1, Code d2)
    {
        assert(d1.kind() == d2.kind());

        if (isVar(d1))
        {
            return eqSymDecl(d1, d2);
        }
        else if (isFbar(d1))
        {
            return eqFbarDecl(d1, d2);
        }
        else if (isSbr(d1))
        {
            return eqSbrDecl(d1, d2);
        }
        else if (isSignature(d1))
        {
            return false;
        }
        else
        {
            assert(false);
            return false;
        }
    }

    // Module declarations are compatible only with Module declarations and definitions
    // Program declarations are compatible only with program declarations and definitions (this is checked elsewhere)
    bool eqSbrDecl(Code sbr1, Code sbr2)
    {
        if (getSymLinkage(sbr1) != getSymLinkage(sbr2)) return false;

        if (getInParamNum(sbr1)  == getInParamNum(sbr2) &&
            getOutParamNum(sbr1) == getOutParamNum(sbr2))
        {
            Code arg1 = sbr1.next();
            Code arg2 = sbr2.next();

            for (unsigned i = getParamNum(sbr1); i > 0; --i)
            {
                if (!eqSymDecl(arg1, arg2, true)) return false;

                arg1 = arg1.next();
                arg2 = arg2.next();
            }
            return true;
        }
        return false;
    }

    bool eqSymDecl(DirectiveVariable var1, DirectiveVariable var2, bool isArg = false) const
    {
        if (var1.kind()        != var2.kind()       ||
            var1.type()        != var2.type()       ||
            getSegment(var1)   != getSegment(var2)  ||
            getAlignment(var1) != getAlignment(var2)) return false;

        if (isArg && getArraySize(var1) != getArraySize(var2)) return false; //F1.0 could it be removed?

        if (isConst(var1) != isConst(var2) ||
            isArray(var1) != isArray(var2))
            return false;

        // NB: linkage and allocation rules for formal arguments are different
        //     for function/kernel definitions and declarations.
        //     These rules are validated elsewhere
        if (!isArg)
        {
            if (var1.allocation()   != var2.allocation())   return false;
            if (getSymLinkage(var1) != getSymLinkage(var2)) return false;
        }

        if (isArray(var1) && !isArgSeg(var1) && !isKernArgSeg(var1))
        {
            // Special rules for non-argument arrays. Specification states:
            //     "If the object is an array, the size of the array must be specified
            //      in the definition but can be omitted in the declaration."
            // This rule does not apply to symbols declared/defined in Arg/Kernarg segments
            return getArraySize(var1) == 0 ||
                   getArraySize(var2) == 0 ||
                   getArraySize(var1) == getArraySize(var2);
        }

        // for arguments and non-arrays, arg1.dim must be the same as arg2.dim

        return getArraySize(var1) == getArraySize(var2);

        // NB: other attributes are irrelevant (for declarations)
    }

    bool eqFbarDecl(DirectiveFbarrier arg1, DirectiveFbarrier arg2) const
    {
        return arg1.kind() == arg2.kind() && getSymLinkage(arg1) == getSymLinkage(arg2);
    }

    void validateModuleDefs()
    {
        // Module symbol must be defined if it is used
        NameMap::iterator it = modSymDesc.begin();
        for (; it != modSymDesc.end(); ++it)
        {
            Code d = it->second;
            if (isDecl(d) && isModuleLinkage(d)) // && modSymUsed.count(getName(d)) > 0) //F1.0 remove modSymUsed?
            {
                if (isKernel(d)) validate(d, false, "Kernel must have a definition because it is declared with module linkage"); //F1.0: optimize
                if (isFunc(d))   validate(d, false, "Function must have a definition because it is declared with module linkage");
                if (isVar(d))    validate(d, false, "Variable must have a definition because it is declared with module linkage");
                if (isFbar(d))   validate(d, false, "Fbarrier must have a definition because it is declared with module linkage");
                assert(false);
            }
        }
    }

    void clearSymbols()
    {
        clearSymDefs();
        clearSymNames();
    }

    void clearArgs(Code c)
    {
        validate(c, callArgs.empty(), "There are unused variables defined in the current arg block");
    }

    void clearSymDefs()
    {
        if (isArgScope())
        {
            argVarDefs.clear();
        }
        else if (isSbrScope())
        {
            sbrVarDefs.clear();
            outArgDefs.clear();
            inArgDefs.clear();
        }
    }

    void clearSymNames()
    {
        if (isArgScope())      argVarNames.clear();
        else if (isSbrScope()) sbrVarNames.clear();
        else
        {
            modSymDesc.clear();
            modSymUsed.clear();
            modSymRef.clear();
        }
    }

private:
    void validate(Code c, bool cond, SRef msg) const
    {
        if (!cond) throw BrigFormatError(BRIG_SECTION_INDEX_CODE, c.brigOffset(), msg);
    }

    void validate(Operand opr, bool cond, SRef msg) const
    {
        if (!cond) throw BrigFormatError(BRIG_SECTION_INDEX_OPERAND, opr.brigOffset(), msg);
    }
};

//=============================================================================
//=============================================================================
//=============================================================================
// Validator implementation

static const char* ALPHA    = "_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const char* ALPHANUM = "_.ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

class ValidatorImpl : public BrigHelper
{
private:
    BrigContainer &brig;
    vector<unsigned> map[BRIG_NUM_SECTIONS];
    set<Offset> usedInst;

    bool imageExtEnabled;
    unsigned mModel;
    unsigned mProfile;
    unsigned major;
    unsigned minor;

    mutable BrigFormatError err;
    bool disasmOnError;

    static const int AVR_ITEM_SIZE = 32; //F: customize for each section

public:
    //-------------------------------------------------------------------------
    // Public API Implementation

    ValidatorImpl(BrigContainer &c) : brig(c), imageExtEnabled(false), mModel(BRIG_MACHINE_LARGE), mProfile(BRIG_PROFILE_FULL), disasmOnError(false) {}

    bool validate(bool disasm)
    {
        disasmOnError = disasm;

        try
        {
            // Low-level validation
            validateBrigFormat();           // Validation of sections structure
            validateBrigFields();           // Validation of item field values

            // Version validation
            initBrigVersion();

            // High-level validation
            validateBrigItems();            // Validation of dependencies between item fields
            validateBrigDefs();             // Validation of def/use and context
        }
        catch (BrigFormatError &e)
        {
            err = e;
            return false;
        }
        err.clear();
        return true;
    }

    string getErrorMsg(istream *is) const
    {
        if (err.empty()) return "";

        int section = err.getSection();
        unsigned offset = err.getOffset();
        const SourceInfo* si = getSourceInfo(section, offset);

        if (section == -1)
        {
            return err.what();
        }
        else if (is && si)
        {
            ostringstream s;
            SrcLoc const srcLoc = { si->line, si->column };
            printError(s, *is, srcLoc, err.what());
            return s.str();
        }
        else
        {
            return getErrorPos(section, offset) + err.what() + dumpItem(section, offset);
        }
    }

    int getErrorCode() const { return err.empty()? 0 : err.getErrCode(); }

private:

    //-------------------------------------------------------------------------
    // Low-level validation

    void validateBrigFormat()
    {
        validateModule();
        validateSection(BRIG_SECTION_INDEX_DATA);
        validateSection(BRIG_SECTION_INDEX_CODE);
        validateSection(BRIG_SECTION_INDEX_OPERAND);
    }

    //-------------------------------------------------------------------------
    // Validation of individual item fields

    void validateBrigFields()
    {
        bool versionFound = false;

        for(Code code = brig.code().begin(); code != brig.code().end(); code = code.next())
        {
            validate(code, isDirective(code.kind()) || isInstruction(code.kind()), "Invalid item in code section");

            if (isDirective(code.kind()))
            {
                validate(code, ValidateBrigDirectiveFields(code), "Invalid directive kind");

                // Init profile, model and extension to validate limitations on some HSAIL types. See validate_BrigType
                if (DirectiveExtension ext = code) imageExtEnabled |= (ext.name() == "IMAGE");

                if (DirectiveModule ver = code)
                {
                    validate(ver, !versionFound, "Duplicate version directive"); //F1.0 update error message

                    mProfile     = ver.profile();
                    mModel       = ver.machineModel();
                    versionFound = true;
                }
            }
            else
            {
                assert(isInstruction(code.kind()));
                Inst inst = code;

                validate(inst, ValidateBrigInstFields(inst), "Invalid instruction kind");
            }
        }

        validate(brig.code().begin(), versionFound, "Missing version directive");

        for(Operand o = brig.operands().begin(); o != brig.operands().end(); o = o.next())
        {
            validate(o, ValidateBrigOperandFields(o), "Invalid operand kind");
        }
    }

    //-------------------------------------------------------------------------
    // Validation of version directive

    void initBrigVersion() //F1.0 rename
    {
        DirectiveModule v;
        Code start = brig.code().begin();

        for(Code code = start; !v && code != brig.code().end(); code = code.next()) v = code;

        validate(start, v, "Missing Version directive");//F1.0 update error message

        major = v.hsailMajor();
        minor = v.hsailMinor();

        validate(v, major         == Brig::BRIG_VERSION_HSAIL_MAJOR, "Unsupported major HSAIL version");
        validate(v, minor         <= Brig::BRIG_VERSION_HSAIL_MINOR, "Unsupported minor HSAIL version");
        ///F1.0 validate(v, v.brigMajor() == Brig::BRIG_VERSION_BRIG_MAJOR,  "Unsupported major BRIG version");
        ///F1.0 validate(v, v.brigMinor() <= Brig::BRIG_VERSION_BRIG_MINOR,  "Unsupported minor BRIG version");

        //F1.0 validate module name and default rounding
    }

    //-------------------------------------------------------------------------
    // Validation of dependencies between item fields

    void validateBrigItems()
    {
        InstValidator instValidator(mModel, mProfile);

        for(Code code = brig.code().begin();
            code != brig.code().end();
            code = code.next())
        {
            if (isDirective(code.kind())) validateDirective(code);
        }

        for(Operand o = brig.operands().begin();
            o != brig.operands().end();
            o = o.next())
        {
            validateOperand(o);
        }

        for(Code code = brig.code().begin();
            code != brig.code().end();
            code = code.next())
        {
            if (Inst inst = code)
            {
                validate(inst, getOperandsNum(inst) <= 5, "Instruction cannot have more than 5 operands");

                instValidator.validateInst(inst);

                validateComplexInst(inst);
            }
        }
    }

    //-------------------------------------------------------------------------
    // Validation of definitions and declarations
    // NB: the code below should register all def/uses of HSAIL symbols
    //     in accordance with ValidatorContext requirements

    void validateBrigDefs() const
    {
        ValidatorContext context(brig);

        // Find all definitions and declarations of module identifiers
        // (functions, variables, images, samplers, fbarriers);
        // for each identifier, find decl/def directive which must be used
        // for all references to this identifier (according with spec requirements)
        analyzeModuleSymbols(context);

        context.startModule();

        Code end = brig.code().end();
        for (Code code = brig.code().begin(); code != end; )
        {
            Code next = code.next();

            if (Directive d = code)
            {
                validate(d, isTopLevelStatement(d), "Directive is not allowed at top level");
                validateOrder(d, context);

                if (isSbr(d))
                {
                    validateSbr(d, context);
                    next = getNextTopLevel(d);
                }
                else
                {
                    validateDefUse(d, context);
                }
            }

            code = next;
        }

        context.endModule();
    }

    void validateSbr(DirectiveExecutable d, ValidatorContext &context) const
    {
        assert(d);

        bool unreachableCode = false;

        context.defineSbr(d);
        context.startSbr(d); // Define arguments

        // Scan body
        Code p = getFirstScoped(d);
        Code end = getNextTopLevel(d);

        for (p = getFirstScoped(d); p != end; p = p.next())
        {
            validateOrder(p, context);

            if (Directive scoped = p)
            {
                if (DirectiveLabel(scoped)) unreachableCode = false;

                validateDefUse(scoped, context);
            }
            else if (Inst i = p)
            {
                context.validateExtensionOpcode(i);

                // Check that all symbols referred to by operands are visible in the current context
                unsigned numOperands  = getOperandsNum(i);
                for (unsigned idx = 0; idx < numOperands; ++idx)
                {
                    Operand opr = i.operand(idx);
                    assert(opr);

                    validateUse(i, opr, context);
                }

                // Validate additional context-sensitive requirements
                // NB: ORDER IS IMPORTANT!
                // NB: validate instructions after arguments (important for calls)
                validateSpecInst(i, context);

                // Set flag indicating if next instruction is unreachable
                unreachableCode = isTermInst(i.opcode());
            }
        }

        context.endSbr(d);
    }

    void validateOrder(Code c, ValidatorContext &context) const
    {
        if      (isAnnotation(c))           context.notifyAnnotation(c);
        else if (DirectiveModule(c))        context.notifyVersion(c); //F1.0 rename
        else if (DirectiveExtension(c))     context.notifyExtension(c);
        else if (isDefDecl(c))              context.notifyDefDecl(c);
        else if (DirectiveControl(c))       context.notifyControl(c);
        else if (DirectiveLabel(c))         context.notifyLabel(c);
        else if (DirectiveArgBlockStart(c)) context.notifyArgBlkStart(c);
        else if (DirectiveArgBlockEnd(c))   context.notifyArgBlkEnd(c);
        else if (Inst(c))                   context.notifyInst(c);
        else                                assert(false);
    }

    bool isAnnotation(Code c) const { return DirectiveComment(c) || DirectiveLoc(c) || DirectivePragma(c); }
    bool isDefDecl(Code c)    const { return DirectiveVariable(c) || DirectiveFbarrier(c) || DirectiveExecutable(c); }

    // Analyze module definitions and register first def/decl
    void analyzeModuleSymbols(ValidatorContext &context) const
    {
        Code end = brig.code().end();
        for (Code d = brig.code().begin(); d != end ; d = analyzeGlobalSym(d, context));
    }

    // Analyze global definition and register first def/decl
    Code analyzeGlobalSym(Code d, ValidatorContext &context) const
    {
        if (isVar(d) || isFbar(d) || isSbr(d))
        {
            context.registerGlobalSym(d);
            return getNextTopLevel(d);
        }
        return d.next();
    }

    void validateDefUse(Code d, ValidatorContext &context) const
    {
        if (isLabel(d))
        {
            context.defineLabel(d);
        }
        else if (isVar(d) || isFbar(d))
        {
            context.defineVar(d);
        }
        else if (DirectivePragma p = d)
        {
            //F1.0
            // verify scope of registers and identifiers
            // verify limitations on register pool

            unsigned len = p.operands().size();

            for (unsigned i = 0; i < len; ++i)
            {
                Operand opr = p.operands()[i];
                if (OperandCodeRef ref = opr)
                {
                    validateSymUse(d, opr, ref.ref(), context);
                }
                else if (OperandRegister reg = opr)
                {
                    validate(reg, context.isSbrScope() || context.isArgScope(), "Pragma must be in a code block to refer registers");
                }
            }
        }
    }

    void validateUse(Inst inst, Operand opr, ValidatorContext &context) const
    {
        using namespace Brig;

        switch (opr.kind())
        {
        case BRIG_KIND_OPERAND_ADDRESS:
            if (Directive sym = OperandAddress(opr).symbol())
            {
                validateSymUse(inst, opr, sym, context);
                if (context.isInArg(sym))       validateArgUse(inst, sym, true);
                else if (context.isOutArg(sym)) validateArgUse(inst, sym, false);
            }
            if (OperandRegister reg = OperandAddress(opr).reg())
            {
                context.notifyRegister(reg);
            }
            break;

        case BRIG_KIND_OPERAND_CODE_REF:
            validateSymUse(inst, opr, OperandCodeRef(opr).ref(), context);
            break;

        case BRIG_KIND_OPERAND_CODE_LIST:
            validateListUse(inst, opr, context);
            break;

        case BRIG_KIND_OPERAND_REGISTER:
            context.notifyRegister(opr);
            break;

        case BRIG_KIND_OPERAND_OPERAND_LIST:            // Vector
        case BRIG_KIND_OPERAND_CONSTANT_OPERAND_LIST:   // Aggregate, image and sampler initializers
        case BRIG_KIND_OPERAND_CONSTANT_BYTES:
        case BRIG_KIND_OPERAND_STRING:
        case BRIG_KIND_OPERAND_WAVESIZE:
        case BRIG_KIND_OPERAND_CONSTANT_IMAGE:
        case BRIG_KIND_OPERAND_CONSTANT_SAMPLER:
        case BRIG_KIND_OPERAND_ALIGN:
            // Nothing to validate
            break;

        default:
            assert(false);
            break;
        }
    }

    void validateSymUse(Code owner, Operand opr, Code sym, ValidatorContext &context) const
    {
        if (isSbr(sym))
        {
            context.checkSbrUse(opr, sym);
            context.markSymUsed(sym);
        }
        else if (isVar(sym) || isFbar(sym))
        {
            context.checkVarUse(opr, sym);
            context.markSymUsed(sym);
        }
        else if (isLabel(sym))
        {
            context.checkLabelUse(owner, sym);
        }
        else
        {
            assert(false);
        }
    }

    void validateArgUse(Inst inst, DirectiveVariable sym, bool isInputArg) const
    {
        if (isInputArg) validate(inst, inst.opcode() == Brig::BRIG_OPCODE_LD, "Input arguments may only be accessed by ld operations");
        else            validate(inst, inst.opcode() == Brig::BRIG_OPCODE_ST, "Output argument may only be accessed by st operations");
    }

    void validateListUse(Code owner, OperandCodeList list, ValidatorContext &context) const
    {
        assert(list);

        unsigned size = list.elements().size();
        for (unsigned i = 0; i < size; ++i)
        {
            Code sym = list.elements()[i];
            assert(sym); // already validated on first steps

            if (isFunc(sym) || isVar(sym) || isLabel(sym))
            {
                validateSymUse(owner, list, sym, context);
            }
            else
            {
                // we should not get here unless there are unused OperandCodeLists
                // which can include references to any directives
            }
        }
    }

    void validateCallArgScope(Inst inst, ValidatorContext &context, OperandCodeList arglist, bool isOutArgs) const
    {
        unsigned size = arglist.elements().size();
        for (unsigned n = 0; n < size; ++n)
        {
            Code ref = arglist.elements()[n];
            context.registerCallArg(inst, ref, isOutArgs);
        }
    }

    // This function is called to check context-specific requirements which 'validateUse' cannot handle.
    void validateSpecInst(Inst i, ValidatorContext &context) const
    {
        if (isCallInst(i.opcode()))
        {
            validate(i, context.isArgScope(), "Calls cannot be used outside of an argument scope");

            context.startCall(i);

            // validate that all arguments are defined in the current scope
            if (i.operand(0)) validateCallArgScope(i, context, i.operand(0), true);  // output
            if (i.operand(2)) validateCallArgScope(i, context, i.operand(2), false); // input

            context.endCall(i);
        }
        else if (i.opcode() == Brig::BRIG_OPCODE_RET)
        {
            validate(i, !context.isArgScope(), "Instruction ret cannot be used in an argument scope");
        }
        else if (i.opcode() == Brig::BRIG_OPCODE_ALLOCA)
        {
            validate(i, !context.isArgScope(), "Instruction alloca cannot be used in an argument scope");
        }
    }

    //-------------------------------------------------------------------------
    // Low-level Brig format validation

    void validateModule() const
    {
        const Brig::BrigModule* module = getBrigModule();

        if (module->sectionCount < 3) throw BrigFormatError("Module must include at least 3 sections");
    }

    void validateSection(int section)
    {
        const Brig::BrigSectionHeader* header = getSectionHeader(section);

        uint32_t secSize = header->byteCount;
        uint32_t hdrSize = header->headerByteCount;
        uint32_t nameLength = header->nameLength;

        validate(section, 0, (secSize & 0x3) == 0, "Section size must be a multiple of 4");
        validate(section, 0, (hdrSize & 0x3) == 0, "Section header size must be a multiple of 4");
        validate(section, 0, hdrSize <= secSize,   "Section header must not be greater than total section size");
        validate(section, 0, nameLength <= hdrSize - 3 * sizeof(uint32_t), "Section name does not fit in section header");
        validate(section, 0, getSectionName(section) == getExpectedSectionName(section), "Invalid section name");

        map[section].reserve(secSize / AVR_ITEM_SIZE);

        uint32_t offset = hdrSize;

        while(offset < secSize)
        {
            validate(section, offset,
                     offset + 4 <= secSize, // Each entry must start with 32-bit header
                     "Last item does not fit in section");

            unsigned itemSize    = getItemSize(section, offset);
            unsigned minItemSize = getMinItemSize(section, offset);

            validate(section, offset, (itemSize & 0x3) == 0,        "Item size must be a multiple of 4");
            validate(section, offset, minItemSize <= itemSize,      "Invalid item size");
            validate(section, offset, offset + itemSize > offset,   "Item does not fit in section"); // no overflow
            validate(section, offset, offset + itemSize <= secSize, "Item does not fit in section");

            validatePadding(section, offset);

            map[section].push_back(offset);

            offset += itemSize;
        }

        assert(offset == secSize);
    }

    void validatePadding(int section, unsigned offset) const
    {
        if (section == BRIG_SECTION_INDEX_DATA)
        {
            const Brig::BrigData* data = getDataItem(offset);
            unsigned size = getItemSize(section, offset) - offsetof(Brig::BrigData, bytes);

            for (unsigned i = data->byteCount; i < size; ++i)
            {
                validate(section, offset, data->bytes[i] == 0, "Padding bytes at the end of hsa_data items must be 0");
            }
        }
    }

    unsigned getMinItemSize(int section, unsigned offset) const
    {
        if (section == BRIG_SECTION_INDEX_DATA) return BRIG_MIN_DATA_ITEM_SIZE;

        int size = size_of_brig_record(getItemKind(section, offset));
        validate(section, offset, size > 0, "Invalid item kind");
        return size;
    }

    //-------------------------------------------------------------------------
    // Validation of Complex Items

    void validateControlDirective(DirectiveControl d)
    {
        using namespace Brig;

        unsigned len = d.operands().size();
        bool isWsValid = allowCtlDirOperandWs(d.control());

        unsigned i = 0;
        for (; i < len; ++i)
        {
            unsigned type = getCtlDirOperandType(d.control(), i);

            validate(d, type != BRIG_TYPE_NONE, "Too many operands");

            Operand opr = d.operands()[i];
            if (OperandConstantBytes imm = opr) //F1.0
            {
                assert(type == BRIG_TYPE_U32 || type == BRIG_TYPE_U64);

                validate(imm, getImmSize(imm) == getBrigTypeNumBits(type), "Invalid size of immediate value");
                uint64_t val = (type == BRIG_TYPE_U32)? getImmAsU32(imm) : getImmAsU64(imm);
                const char* err = validateCtlDirOperandBounds(d.control(), i, val);
                if (err) validate(opr, false, SRef(err));
            }
            else if (OperandWavesize ws = opr)
            {
                validate(ws, isWsValid, "Invalid operand of control directive (wavesize is not allowed)");
            }
            else
            {
                validate(d, false, "Invalid operand of control directive");
            }
        }

        if (mProfile == BRIG_PROFILE_BASE &&
            (d.control() == BRIG_CONTROL_ENABLEBREAKEXCEPTIONS ||
             d.control() == BRIG_CONTROL_ENABLEDETECTEXCEPTIONS))
        {
            OperandConstantBytes imm = d.operands()[0]; //F1.0
            assert(imm);

            uint32_t val = getImmAsU32(imm);

            validate(d, (val & 0x1F) == 0, "Exception bits 0 to 4 must be zero for the base profile");
        }

        validate(d, getCtlDirOperandType(d.control(), i) == BRIG_TYPE_NONE, "Insufficient number of operands");
    }

    void validatePragma(DirectivePragma d)
    {
        using namespace Brig;

        unsigned len = d.operands().size();

        validate(d, len > 0, "Pragma must have at least one operand");

        for (unsigned i = 0; i < len; ++i)
        {
            Operand opr = d.operands()[i];

            switch (opr.kind())
            {
            case BRIG_KIND_OPERAND_CONSTANT_BYTES:          // Numeric constants and arrays
            case BRIG_KIND_OPERAND_CONSTANT_OPERAND_LIST:   // Aggregate, image and sampler initializers
            case BRIG_KIND_OPERAND_CONSTANT_IMAGE:
            case BRIG_KIND_OPERAND_CONSTANT_SAMPLER:
            case BRIG_KIND_OPERAND_REGISTER:
            case BRIG_KIND_OPERAND_WAVESIZE:
            case BRIG_KIND_OPERAND_STRING:
                break; // Nothing to do

            case BRIG_KIND_OPERAND_CODE_REF: {
                OperandCodeRef ref = opr;
                Code sym = ref.ref();
                validate(d, DirectiveVariable(sym) ||
                            DirectiveFbarrier(sym) ||
                            DirectiveLabel(sym) ||
                            DirectiveExecutable(sym), "Invalid operand of pragma directive");
                }
                break;

            default:
                validate(d, OperandString(opr), "Invalid operand of pragma directive");
                break;
            }
        }
    }

    void validateDirective(Code d)
    {
        assert(d);

        using namespace Brig;
        switch (d.kind())
        {
        case BRIG_KIND_DIRECTIVE_KERNEL:
        case BRIG_KIND_DIRECTIVE_FUNCTION:
        case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION:
        case BRIG_KIND_DIRECTIVE_SIGNATURE:
            {
                validateName(d, "&");
                validateDefDecl(d);
                validateLinkage(d);
                validateArgs(d);
                validateScoped(d);
            }
            break;
        case BRIG_KIND_DIRECTIVE_VARIABLE:
            {
                validateVarType(DirectiveVariable(d));
                validateName(d, "%&");
                validateDefDecl(d);
                validateLinkage(d);
                validateSegment(d);
                validateSymAttr(d);
                validateAlign(d);
                validateAllocation(d);
                validateInit(d);
            }
            break;
        case BRIG_KIND_DIRECTIVE_LABEL:
            {
                validateName(d, "@");
            }
            break;
        case BRIG_KIND_DIRECTIVE_FBARRIER:
            {
                validateName(d, "%&");
                validateDefDecl(d);
                validateLinkage(d);
            }
            break;
        case BRIG_KIND_DIRECTIVE_CONTROL:
            {
                validateControlDirective(d);
            }
            break;

        case BRIG_KIND_DIRECTIVE_COMMENT:
            {
                DirectiveComment c = d;
                string text = SRef(c.name());
                validate(c, text.find("//") == 0, "Comment must start with \"//\"");
            }
            break;

        case BRIG_KIND_DIRECTIVE_PRAGMA:
            validatePragma(d);
            break;

        // Need no additional checks
        case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START:   break;
        case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END:     break;
        case BRIG_KIND_DIRECTIVE_EXTENSION:         break;
        case BRIG_KIND_DIRECTIVE_LOC:               break;
        case BRIG_KIND_DIRECTIVE_MODULE:            break;

        default:
            // should not get here!
            assert(false);
            validate(d, false, "Unsupported directive kind");
            break;
        }
    }

    template<class T, typename BrigStruct> void validateLabelList(T list)
    {
        validate(list, list.elementCount() > 0, "Empty list of labels");

        // directive size must be large enough to hold all array elements
        unsigned available = list.brig()->size - offsetof(BrigStruct, labels);
        validate(list, sizeof(Offset) * list.elementCount() <= available, "Invalid DirectiveLabelList size");

        for (unsigned i = 0; i < list.elementCount(); ++i)
        {
            // Offsets in this array have not been validated yet
            validate_BrigDirectiveOffset(list, list.brig()->labels[i], DirectiveLabelInit(list)? "DirectiveLabelInit" : "DirectiveLabelTargets", "labels[*]");

            // Each element must refer DirectiveLabel
            validate(list, isDirectiveKind<DirectiveLabel>(list.labels(i)), "Invalid reference to label");
        }
    }

    void validateDirectCall(Inst inst) const
    {
        assert(inst.opcode() == Brig::BRIG_OPCODE_CALL);

        OperandCodeRef funcRef = inst.operand(1);
        assert(funcRef);    // validated on previous steps (hdl)

        DirectiveExecutable fn = funcRef.ref();
        assert(isFunc(fn)); // validated on previous steps (hdl)

        validateFuncArgs(inst, fn, inst.operand(0), inst.operand(2));
    }

    void validateSwitchCall(Inst inst) const
    {
        assert(inst.opcode() == Brig::BRIG_OPCODE_SCALL);

        OperandCodeList list = inst.operand(3);
        assert(list); // validated on previous steps (hdl)

        unsigned sz = list.elements().size();

        for (unsigned idx = 0; idx < sz; ++idx)
        {
            DirectiveExecutable fn = list.elements()[idx];
            assert(fn); // validated on previous steps (hdl)

            validateFuncArgs(inst, fn, inst.operand(0), inst.operand(2));
        }
    }

    void validateIndirectCall(Inst inst) const
    {
        assert(inst.opcode() == Brig::BRIG_OPCODE_ICALL);

        validate(inst, mProfile != Brig::BRIG_PROFILE_BASE, "Base profile does not support icall instruction");

        OperandCodeRef sigRef = inst.operand(3);
        assert(sigRef); // validated on previous steps (hdl)

        DirectiveSignature sig = sigRef.ref();
        assert(sig); // validated on previous steps (hdl)

        validateFuncArgs(inst, sig, inst.operand(0), inst.operand(2));
    }

    void validateMemFence(InstMemFence inst) const
    {
        const char* err = validateProp(HSAIL_PROPS::PROP_IMAGESEGMENTMEMORYSCOPE, inst.imageSegmentMemoryScope(), mModel, mProfile, imageExtEnabled);
        if (err) validate(inst, false, SRef(err));
    }

    void validateMemAccess(Inst inst, unsigned oprAddrIdx, unsigned oprDataIdx) const
    {
        assert(inst);

        OperandAddress addr =  inst.operand(oprAddrIdx);
        OperandOperandList vector = inst.operand(oprDataIdx);
        unsigned accessDim = vector? vector.elements().size() : 1;

        assert(1 <= accessDim && accessDim <= 4);
        assert(addr);

        DirectiveVariable var = addr.symbol();

        if (!var || addr.reg()) return;
        if (var.isArray() && var.dim() == 0) return;  // var is defined in another module
        if (var.segment() == Brig::BRIG_SEGMENT_KERNARG) return; // kernarg is a special case

        uint64_t memSize = getBrigTypeNumBytes(var.elementType()) * (var.isArray()? var.dim() : 1ULL); //F1.0: '*' may cause overflow; add positive tests

        validate(addr, addr.offset() < memSize, "Address offset exceeds variable size");

        validate(addr, addr.offset() + getBrigTypeNumBytes(inst.type()) * accessDim <= memSize, 
                 "Address is outside of memory allocated for variable");
    }

    void validateComplexInst(Inst i) const
    {
        // Validate that there is a kernel/function which uses this instruction
        validate(i, usedInst.count(i.brigOffset()) > 0, "Instruction does not belong to any kernel/function");

        using namespace Brig;
        switch(i.opcode())
        {
        case BRIG_OPCODE_CALL:        validateDirectCall(i); break;
        case BRIG_OPCODE_SCALL:       validateSwitchCall(i); break;
        case BRIG_OPCODE_ICALL:       validateIndirectCall(i); break;
        case BRIG_OPCODE_MEMFENCE:    validateMemFence(i);     break;

        case BRIG_OPCODE_ATOMIC:      validateMemAccess(i, 1, 0); break;
        case BRIG_OPCODE_ATOMICNORET: validateMemAccess(i, 0, 1); break;
        case BRIG_OPCODE_LD:          validateMemAccess(i, 1, 0); break;
        case BRIG_OPCODE_ST:          validateMemAccess(i, 1, 0); break;

        default: break;
        }
    }

    void validateOperandAddress(OperandAddress addr) const
    {
        assert(addr);

        // This is a low-level check to make sure that operand refers a DirectiveVariable
        if (addr.brig()->symbol) validate(addr, isDirectiveKind<DirectiveVariable>(addr.symbol()), "Invalid symbol reference");

        if (addr.brig()->reg) 
        {
            // This is a low-level check to make sure that operand refers an OperandRegister
            validate(addr, isOperandKind<OperandRegister>(addr.reg()), "Invalid register reference");
        }

        // Make sure all address elements specify the same size
        unsigned addrSize = getAddrSize(addr, isLargeModel()); // 32 or 64; 0 if both are valid
        if (addrSize == 0) return; // nothing to validate

        if (addr.symbol())
        {
            validate(addr, addrSize == getSegAddrSize(addr.symbol().segment(), isLargeModel()),
                     "Malformed address: segment size does not match register size");
        }

        if (addr.reg()) validate(addr, addrSize == getRegBits(addr.reg().regKind()), 
                                 "Malformed address: register size does not match segment size");
    }

    template <class DirectiveKind> bool isDirectiveKind(Code d)  const { return DirectiveKind(d); }
    template <class OperandKind>   bool isOperandKind(Operand d) const { return OperandKind(d); }

    void validateOperand(Operand opr)
    {
        assert(opr);

        using namespace Brig;

        switch (opr.kind())
        {
        case BRIG_KIND_OPERAND_ADDRESS:
            validateOperandAddress(opr);
            break;

        case BRIG_KIND_OPERAND_CONSTANT_BYTES:
            {
                OperandConstantBytes c = opr;
                unsigned type     = isArrayType(c.type())? arrayType2elementType(c.type()) : c.type();
                unsigned typeSize = getBrigTypeNumBytes(type);
                SRef     data     = c.bytes();

                validate(opr, data.length() > 0, "OperandConstantBytes must include at least one value");
                validate(opr, isUnsignedType(type) ||
                              isSignedType(type)   ||
                              isFloatType(type)    ||
                              isPackedType(type)   ||
                              isSignalType(type),
                              "Invalid type of OperandConstantBytes");
                validate(opr, (data.length() % typeSize) == 0, "Invalid OperandConstantBytes: data size must be a multiple of type size");
            }
            break;

        case BRIG_KIND_OPERAND_CONSTANT_IMAGE:
            validate(opr, isImageType(OperandConstantImage(opr).type()), "Invalid type of OperandConstantSampler");
            break;

        case BRIG_KIND_OPERAND_CONSTANT_SAMPLER:
            validate(opr, OperandConstantSampler(opr).type() == BRIG_TYPE_SAMP, "Invalid type of OperandConstantSampler");
            break;

        case BRIG_KIND_OPERAND_CONSTANT_OPERAND_LIST:   // Aggregate, image and sampler initializers
            validate(opr, OperandConstantOperandList(opr).type() == BRIG_TYPE_SAMP_ARRAY  ||
                          OperandConstantOperandList(opr).type() == BRIG_TYPE_ROIMG_ARRAY ||
                          OperandConstantOperandList(opr).type() == BRIG_TYPE_WOIMG_ARRAY ||
                          OperandConstantOperandList(opr).type() == BRIG_TYPE_RWIMG_ARRAY ||
                          OperandConstantOperandList(opr).type() == BRIG_TYPE_NONE,
                          "Invalid type of OperandConstantOperandList");
            validate(opr, OperandConstantOperandList(opr).elements().size() > 0, 
                          "Invalid initializer: must include at least one value");
            //F1.0 validate type of list and types of operands in it
            //F1.0 validate that all elements are valid Operands (was it checked in 0.99 for OperandList?)
            break;

        case BRIG_KIND_OPERAND_REGISTER:
        case BRIG_KIND_OPERAND_CODE_LIST:       //F1.0 validate that all elements are valid refs to code (was it checked in 0.99?)
        case BRIG_KIND_OPERAND_CODE_REF:
        case BRIG_KIND_OPERAND_OPERAND_LIST:    //F1.0 validate that all elements are valid refs to operands (was it checked in 0.99?)
        case BRIG_KIND_OPERAND_WAVESIZE:
        case BRIG_KIND_OPERAND_STRING:
        case BRIG_KIND_OPERAND_ALIGN:
            break; // Nothing to do

        default:
            // should not get here!
            assert(false);
            validate(opr, false, "Unsupported operand kind");
            break;
        }
    }

    //-------------------------------------------------------------------------

    void validateName(Code d, const char* pref) const
    {
        string name = getName(d);

        if (name.length() == 0) return; // empty names are validated elsewhere

        validate(d, name.find_first_of(pref) == 0, "Invalid identifier prefix");

        // validate(d, name.find("__hsa") != 1, "Identifiers must not start with the characters '__hsa'");

        validate(d, name.length() > 1 &&
                    name.find_first_of(ALPHA, 1) == 1 &&
                   (name.length() == 2 || name.find_first_not_of(ALPHANUM, 2) == string::npos), "Invalid identifier");
    }

    bool isImage(Code d) const {
        DirectiveVariable v = d;
        return isImageOrSampler(d) && !isSampler(d);
    }

    bool isSampler(Code d) const {
        DirectiveVariable v = d;
        return v && v.elementType() == Brig::BRIG_TYPE_SAMP;
    }

    bool isImageOrSampler(Code d) const {
        DirectiveVariable v = d;
        return v && isImageExtType(v.elementType());
    }

    bool isSignal(Code d) const {
        DirectiveVariable v = d;
        return v && (v.elementType() == Brig::BRIG_TYPE_SIG32 || v.elementType() == Brig::BRIG_TYPE_SIG64);
    }

    void validateSegment(DirectiveVariable d) const
    {
        unsigned segment = getSegment(d);

        if (segment == Brig::BRIG_SEGMENT_ARG)
        {
            validate(d, getName(d).length() == 0 || getNamePref(d) == '%',
                     "Only formal arguments and local variables can be defined in arg segment");
        }
        else if (segment == Brig::BRIG_SEGMENT_KERNARG)
        {
            validate(d, getNamePref(d) == '%',
                     "Only formal arguments of kernel can be defined in kernarg segment");
        }
        else if (segment == Brig::BRIG_SEGMENT_SPILL)
        {
            validate(d, getNamePref(d) == '%',
                     "Only local variables can be defined in spill segment");
        }

        if (isImageOrSampler(d))
        {
            validate(d, isArgSeg(d) || isKernArgSeg(d) || isGlobalSeg(d) || isReadonlySeg(d),
                        "Images and samplers may only be defined in arg, kernarg, global and readonly segments");
        }
    }

    void validateDefDecl(Code d)
    {
        // NB: Validation of arg and kernarg segment variables depends on context (see defineVar)

        if (isDecl(d))
        {
            if      (isSignature(d))           validate(d, false,                 "Signatures have no declarations");
            else if (isFunc(d) || isKernel(d)) validate(d, getScopedSize(d) == 0, "Kernel/function declaration cannot have a body");
        }
    }

    void validateLinkage(Code d)
    {
        using namespace Brig;

        // NB: Validation of arg and kernarg segment variables depends on context (see defineVar)

        if      (isSignature(d))           validate(d, isNoneLinkage(d),                       "Signatures must have none linkage");
        else if (isFunc(d) || isKernel(d)) validate(d, isProgLinkage(d) || isModuleLinkage(d), "Kernels and functions must have program or module linkage");
    }

    // Agent allocation is only available for global segment variables, in both module and function scopes.
    // If omitted defaults to:
    //   - agent allocation for readonly segment variables;
    //   - program allocation for global segment variables;
    //   - none allocation for kernel declaration, function declaration and signature definition formal argument variables;
    //   - automatic allocation for all other segment variables.
    void validateAllocation(DirectiveVariable d)
    {
        using namespace Brig;

        // NB: Validation of arg and kernarg segment variables depends on context (see defineVar)

        unsigned alloc = d.allocation();

        if      (isGlobalSeg(d))   validate(d, alloc == BRIG_ALLOCATION_AGENT ||
                                               alloc == BRIG_ALLOCATION_PROGRAM,  "Global segment variables must have program or agent allocation");
        else if (isReadonlySeg(d)) validate(d, alloc == BRIG_ALLOCATION_AGENT,    "Readonly segment variables must have agent allocation");
        else if (isSpillSeg(d) ||
                 isGroupSeg(d) ||
                 isPrivateSeg(d))  validate(d, alloc == BRIG_ALLOCATION_AUTOMATIC, "Group, private and spill segment variables must have automatic allocation");

        if (isImageOrSampler(d) && d.init()) validate(d, alloc == BRIG_ALLOCATION_AGENT, "Initialized images and samplers must have agent allocation");
    }

    void validateSymAttr(DirectiveVariable d) const
    {
        assert(isVar(d));

        // If the object is an array, the size of the array must be specified in the
        // definition but can be omitted in the declaration.
        if (isArray(d))
        {
        ///F1.0    if (isDef(d))
        ///F1.0    {
        ///F1.0        validate(d, getArraySize(d) > 0, "Array definitions must have dim > 0");
        ///F1.0    }
        }
        else
        {
            validate(d, getArraySize(d) == 0, "Scalars must have dim = 0");
        }

        if (isConst(d))
        {
            validate(d, isGlobalSeg(d) || isReadonlySeg(d),
                     "Only variables in global and readonly segments may be labelled as const");
        }
    }

    //F1.0 validate that variables with dim > 0 have array type
    void validateVarType(DirectiveVariable var) const
    {
        validate(var, isValidVarType(var.type()), "Invalid variable type");
    }

    void validateAlign(DirectiveVariable d) const
    {
        assert(d);
        validate(d, isValidAlignment(getAlignment(d), d.elementType()),
                 "Specified alignment must be greater than or equal to natural alignment");
    }

    void validateInit(DirectiveVariable sym)
    {
        assert(sym);

        if (sym.init())
        {
            validate(sym, isDef(sym), "Variable declaration cannot have initializer");
            validate(sym, isGlobalSeg(sym) || isReadonlySeg(sym),
                     "Only variables in global and readonly segments may be initialized");

            bool isBitArray = sym.isArray() && isBitType(sym.elementType());

            if      (isImage(sym))   validateOpaqueInit<OperandConstantImage>  (sym);
            else if (isSampler(sym)) validateOpaqueInit<OperandConstantSampler>(sym);
            else if (isSignal(sym))  validateSignalInit(sym);
            else if (isBitArray)     validateAggregateInit(sym);
            else                     validateNumInit(sym);
        }
        else
        {
            validate(sym, isDecl(sym) || !isConst(sym), "Const variable definitions must have an initializer");
        }
    }

    template<class T> void validateOpaqueInit(DirectiveVariable sym)
    {
        assert(sym);
        assert(sym.init());

        uint64_t dim = getArraySize(sym);

        if (dim == 0)
        {
            validateInitializerType<T>(sym.init(), sym.type());
        }
        else
        {
            validateInitializerType<OperandConstantOperandList>(sym.init(), sym.type());

            OperandConstantOperandList init = sym.init();
            unsigned size = init.elements().size();

            validate(init, dim == size, "Initializer size does not match array size");

            for (unsigned i = 0; i < size; ++i)
            {
                assert(init.elements()[i]);
                validateInitializerType<T>(init.elements()[i], sym.elementType());
            }
        }
    }

    void validateSignalInit(DirectiveVariable sym)
    {
        validateNumInit(sym);

        OperandConstantBytes init = sym.init();
        assert(init);

        SRef data = init.bytes();
        for (unsigned i = 0; i < data.length(); ++i)
        {
            validate(sym, data[i] == 0, "Signal handles may only be initialized with 0");
        }
    }

    void validateNumInit(DirectiveVariable sym)
    {
        assert(sym);
        assert(sym.init());

        uint64_t dim = getArraySize(sym);
        unsigned expectedType = type2immType(sym.elementType(), sym.isArray());
        
        validateInitializerType<OperandConstantBytes>(sym.init(), expectedType);

        OperandConstantBytes init = sym.init();
        assert(init);
        
        SRef data = init.bytes();
        uint64_t elementCount = (dim == 0) ? 1 : dim; // scalars have dim=0 and 1 value
        unsigned typeSize = getBrigTypeNumBytes(sym.elementType());

        validate(init, elementCount == data.length() / typeSize, "Initializer size does not match array size");
    }

    void validateAggregateInit(DirectiveVariable sym)
    {
        assert(sym);
        assert(sym.init());

        validateInitializerType<OperandConstantOperandList>(sym.init(), Brig::BRIG_TYPE_NONE);

        OperandConstantOperandList init = sym.init();
        assert(init);

        uint64_t dim           = getArraySize(sym);        
        unsigned elemSize      = getBrigTypeNumBytes(sym.elementType());
        uint64_t aggregateSize = getAggregateNumBytes(sym.init());

        validate(init, (aggregateSize % elemSize) == 0, "Invalid initializer size, must be a multiple of array element type size");
        validate(init, sym.dim() * elemSize == aggregateSize, "Initializer size does not match array size"); //F1.0 "sym.dim() * elemSize" may cause overflow; add positive tests
    }

    template<class T> void validateInitializerType(Operand opr, unsigned expectedType)
    {
        assert(opr);

        T init = opr;
         
        if (!init || init.type() != expectedType)
        {
            ostringstream s;
            s << "Invalid initializer, expected ";
            if (expectedType == Brig::BRIG_TYPE_NONE) {
                s << "an aggregate constant";
                if (init) s << " (OperandConstantOperandList with type 'none')";
            } else if (isArrayType(expectedType)) {
                s << typeX2str(arrayType2elementType(expectedType)) << " array constant";
            } else {
                s << typeX2str(expectedType) << " constant";
            }
            validate(opr, false, s.str());
        }
    }

    void validateArgs(Code d)
    {
        if (isKernel(d))
        {
            validate(d, getOutParamNum(d) == 0, "Kernels cannot have output arguments");
        }
        else
        {
            validate(d, getOutParamNum(d) <= 1, "Functions and signatures cannot have more than one output parameter");
        }

        Code next;
        next = validateSbrArgs(d, d.next(), getFirstOutParam(d), getOutParamNum(d), false);
        next = validateSbrArgs(d, next,     getFirstInParam(d),  getInParamNum(d),  true);

        validate(d, next.brigOffset() == getFirstScoped(d).brigOffset(), "Invalid reference to first scoped directive");
    }

    Code validateSbrArgs(Code sbr, Code next, Code argStart, unsigned paramNum, bool isInputArgs)
    {
        unsigned seg = isKernel(sbr)? Brig::BRIG_SEGMENT_KERNARG : Brig::BRIG_SEGMENT_ARG;

        validate(sbr, next.brigOffset() == argStart.brigOffset(), "Invalid reference to first argument");

        // NB: arguments being checked here are not validated yet!

        Code arg = next;
        for (unsigned i = 0; i < paramNum; ++i)
        {
            validate(sbr, arg,        "Insufficient number of formal arguments");
            validate(arg, isVar(arg), "Invalid directive, expected formal argument");

            if (isKernel(sbr))
            {
                validate(arg, getSegment(Directive(arg)) == seg, "Kernel arguments must be declared in kernarg segment");
            }
            else
            {
                validate(arg, getSegment(Directive(arg)) == seg, "Function/signature arguments must be declared in arg segment");
            }

            if (isArray(arg) && getArraySize(arg) == 0)
            {
                validate(arg, !isKernel(sbr),    "Kernel array arguments must have fixed size");
                validate(arg, isInputArgs,       "Output array argument must have fixed size");
                validate(arg, i == paramNum - 1, "Only last input argument of function/signature may be an array with no specified size");
            }

            validate(arg, !isInitialized(arg), "Argument cannot have initializer");
            validate(arg, !isConst(arg),       "Arguments cannot be const");

            arg = arg.next();
        }
        return arg;
    }

    void validateScoped(Code sbr)
    {
        Code it  = getFirstScoped(sbr);
        Code end = getNextTopLevel(sbr);

        if (isSignature(sbr))
        {
            validate(sbr, it.brigOffset() == end.brigOffset(), "Signature must not have scoped directives");
            validate(sbr, getScopedSize(sbr) == 0,             "Signature cannot have a body");
            return;
        }

        if (isDecl(sbr))
        {
            validate(sbr, it.brigOffset() == end.brigOffset(), "Kernel and function declarations must not have scoped directives");
        }
        else
        {
            validate(sbr, it.brigOffset() <= end.brigOffset(), "Invalid reference to next toplevel directive");
        }

        // NB: directives being checked here are not validated yet!

        for (; it != end; it = it.next())
        {
            if (isDirective(it.kind()))
            {
                validate(it, isBodyStatement(it), "Directive is not allowed inside kernel or function");
                validate(it, !isVar(it) || !isArray(it) || getArraySize(it) > 0, "Only last input argument of function may be an array with no specified size"); //F1.0 could it be removed?
            }
        }

        unsigned idx = getScopedSize(sbr);
        for (it = getFirstScoped(sbr); it != end; it = it.next())
        {
            if (isInstruction(it.kind()))
            {
                usedInst.insert(it.brigOffset()); // Mark as used
            }
            --idx;
        }
        validate(sbr, idx == 0, "Actual size of kernel/function code block does not match expected size");
    }

    void validateFuncArgs(Inst inst, DirectiveExecutable fn, OperandCodeList out, OperandCodeList in) const
    {
        validate(inst, out, "Missing list of output arguments");
        validate(inst, in,  "Missing list of input arguments");

        validateFuncArgList(fn.next(),       fn.outArgCount(), out, "Invalid number of output arguments");
        validateFuncArgList(fn.firstInArg(), fn.inArgCount(),   in, "Invalid number of input arguments");
    }

    void validateFuncArgList(DirectiveVariable formal, unsigned formalArgCount, OperandCodeList actualArgList, SRef msg) const
    {
        validate(actualArgList, formalArgCount == actualArgList.elementCount(), msg);

        for (unsigned i = 0; i < formalArgCount; ++i)
        {
            DirectiveVariable actual = actualArgList.elements(i);

            assert(formal); // Validated on previous steps
            assert(actual); // Validated on previous steps

            validateCallArg(actualArgList, actual, formal);
            formal = formal.next();
        }
    }

    // An actual argument is compatible with a formal parameter if one of these three
    // properties hold:
    // - The two have identical properties, type, size, and alignment.
    // - Both are arrays with the same size and alignment and the elements have identical properties.
    // - Both are arrays with elements that have identical properties, both arrays have
    //   the same alignment, and the formal has dim=0.
    void validateCallArg(OperandCodeList list, Code var, DirectiveVariable formal) const
    {
        DirectiveVariable actual = var;

        validate(list, actual && isArgSeg(actual), "Call arguments must be variables defined in arg segment");

        validate(list, formal.elementType() == actual.elementType(), "Incompatible types of formal and actual arguments");
        validate(list, formal.align()       == actual.align(),       "Incompatible alignment of formal and actual arguments");

        if (isArray(formal))  // may be an array with or without a specified size
        {
            validate(list, isArray(actual), "Actual parameter must be an array");
            validate(list, getArraySize(actual) > 0, "Actual array parameter must have fixed size");
            validate(list, getArraySize(formal) == 0 || getArraySize(formal) == getArraySize(actual), "Incompatible formal and actual arguments: arrays must have the same size");
        }
        else
        {
            validate(list, !isArray(actual), "Actual parameter must be scalar (not array)");
        }
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    // Low-level BRIG validation (functions used by autogenerated code)

    template<class T> void validateOffset(T item, int section, unsigned offset, const char* structName, const char* fieldName, bool z = false, bool ex = false) const
    {
        assert(section == BRIG_SECTION_INDEX_OPERAND   ||
               section == BRIG_SECTION_INDEX_CODE      ||
               section == BRIG_SECTION_INDEX_DATA);

        unsigned size = getSectionSize(section);

        if (offset == 0 && !z)                        invalidOffset(item, section, structName, fieldName, "cannot be 0");
        if (offset > size || (offset == size && !ex)) invalidOffset(item, section, structName, fieldName, "is out of section");

        if (offset > 0 && offset < size && !std::binary_search(map[section].begin(), map[section].end(), offset))
        {
            invalidOffset(item, section, structName, fieldName, "points at the middle of an item");
        }
    }

    template<class T> void invalidOffset(T item, int section, const char* structName, const char* fieldName, const char* errMsg) const
    {
        string msg = "";

        switch(section)
        {
        case BRIG_SECTION_INDEX_OPERAND:   msg = "hsa_operand"; break;
        case BRIG_SECTION_INDEX_CODE:      msg = "hsa_code";    break;
        case BRIG_SECTION_INDEX_DATA:      msg = "hsa_data";    break;
        default:
            assert(false);
            break;
        }

        validate(item, false, "Invalid offset to " + msg + " section: " + structName + "." + fieldName + " " + errMsg);
    }

    template<class T> void validate_BrigCodeOffset(T item, unsigned offset, const char* structName, const char* fieldName) const
    {
        bool z  = OperandAddress(item);
        bool ex = !OperandAddress(item);
        validateOffset(item, BRIG_SECTION_INDEX_CODE, offset, structName, "code", z, ex);
    }

    template<class T> void validate_BrigOperandOffset(T item, unsigned offset, const char* structName, const char* fieldName) const
    {
        validateOffset(item, BRIG_SECTION_INDEX_OPERAND, offset, structName, fieldName, true);
    }

    template<class T> void validate_BrigDataOffsetString(T item, unsigned offset, const char* structName, const char* fieldName) const
    {
        validateOffset(item, BRIG_SECTION_INDEX_DATA, offset, structName, fieldName);
    }

    void validate_BrigDataOffsetCodeList(Operand item, unsigned offset, const char* structName, const char* fieldName) const
    {
        validateOffset(item, BRIG_SECTION_INDEX_DATA, offset, structName, fieldName);
        validateList(item, offset, BRIG_SECTION_INDEX_CODE, structName, fieldName);
    }

    template<class T> void validate_BrigDataOffsetOperandList(T item, unsigned offset, const char* structName, const char* fieldName) const
    {
        validateOffset(item, BRIG_SECTION_INDEX_DATA, offset, structName, fieldName);
        validateList(item, offset, BRIG_SECTION_INDEX_OPERAND, structName, fieldName);
    }

    template<class T> void validateList(T item, unsigned offset, unsigned section, const char* structName, const char* fieldName) const
    {
        const Brig::BrigData* data = getDataItem(offset);
        uint32_t* elements = (uint32_t*)data->bytes;

        validate(item, (data->byteCount & 0x3) == 0, "Invalid array of offsets, size must be a multiple of 4");

        unsigned size = data->byteCount / 4;
        for (unsigned i = 0; i < size; ++i)
        {
            uint32_t elementOffset = elements[i];
            validateOffset(item, section, elementOffset, structName, fieldName);
            if (section == BRIG_SECTION_INDEX_CODE)
            {
                uint16_t id = getItemKind(section, elementOffset);
                validate(item, isDirective(id), "Invalid OperandCodeList, all list elements must refer directives");
            }
        }
    }

    //-------------------------------------------------------------------------
    //F improve diagnostics for this and subsequent checks

    template<class T> void validate_BrigType(T item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, typeX2str(val) != NULL, "Invalid data type value", val);

        const char* err = validateProp(PROP_TYPE, val, mModel, mProfile, imageExtEnabled);
        if (err) validate(item, false, SRef(err));
    }

    template<class T> void validate_BrigSegment(T item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, segment2str(val) != NULL, "Invalid segment value", val);
    }

    template<class T> void validate_BrigAlignment(T item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, align2str(val) != NULL, "Invalid alignment value", val);
    }

    template<class T> void validate_BrigImageGeometry(T item, unsigned val, const char* structName, const char* fieldName) const
    {
        const char* s = imageGeometry2str(val);
        validate(item, s != NULL, "Invalid image geometry value", val);
        validate(item, *s != 0,   "Unspecified image geometry");
    }

    void validate_BrigExecutableModifier(Code item, Brig::BrigExecutableModifier val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned mod = val.allBits;
        unsigned mask = BRIG_EXECUTABLE_DEFINITION;

        validate(item, (mod & ~mask) == 0, "Invalid executable modifier value", mod);
    }

    void validate_BrigLinkage(Code item, unsigned linkage, const char* structName, const char* fieldName) const
    {
        validate(item, linkage2str(linkage) != NULL, "Invalid linkage value", linkage);
    }

    void validate_BrigVariableModifier(Code item, Brig::BrigVariableModifier val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned mod = val.allBits;
        unsigned mask = BRIG_VARIABLE_DEFINITION | BRIG_VARIABLE_CONST;

        validate(item, (mod & ~mask) == 0, "Invalid variable modifier value", mod);
    }

    void validate_BrigAllocation(Code item, unsigned allocation, const char* structName, const char* fieldName) const
    {
        validate(item, allocation2str(allocation) != NULL, "Invalid allocation value", allocation);
    }

    void validate_BrigAluModifier(Inst item, Brig::BrigAluModifier val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned mod = val.allBits;
        validate(item, (mod & ~BRIG_ALU_FTZ) == 0, "Invalid ALU modifier value", mod);
    }

    template<class T> void validate_BrigRound(T item, unsigned val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        validate(item, val == BRIG_ROUND_NONE || 
                       val == BRIG_ROUND_FLOAT_DEFAULT || 
                       round2str(val) != NULL, "Invalid rounding value", val);
    }

    void validate_BrigMemoryModifier(Inst item, Brig::BrigMemoryModifier val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned mod = val.allBits;
        validate(item, (mod & ~BRIG_MEMORY_CONST) == 0, "Invalid memory modifier (const) value", mod);
    }

    void validate_BrigSegCvtModifier(Inst item, Brig::BrigSegCvtModifier val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned mod = val.allBits;
        validate(item, (mod & ~BRIG_SEG_CVT_NONULL) == 0, "Invalid segcvt modifier value", mod);
    }

    void validate_BrigControlDirective(Code item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, controlDirective2str(val) != NULL, "Invalid control type value", val);
    }

    void validate_BrigImageChannelOrder(Operand item, unsigned val, const char* structName, const char* fieldName) const
    {
        const char* s = imageChannelOrder2str(val);
        validate(item, s != NULL , "Invalid image channel order value", val);
        validate(item, *s != 0,    "Unspecified image channel order");

        using namespace Brig;
        OperandConstantImage prop = item;
        bool depthGeometry = (prop.geometry() == BRIG_GEOMETRY_2DDEPTH || prop.geometry() == BRIG_GEOMETRY_2DADEPTH);
        bool depthOrder    = (val == BRIG_CHANNEL_ORDER_DEPTH || val == BRIG_CHANNEL_ORDER_DEPTH_STENCIL);
        validate(item, depthGeometry == depthOrder, "Incompatible image channel order and geometry");
    }

    void validate_BrigImageChannelType(Operand item, unsigned val, const char* structName, const char* fieldName) const
    {
        const char* s = imageChannelType2str(val);
        validate(item, s != NULL, "Invalid image channel type value", val);
        validate(item, *s != 0,   "Unspecified image channel type");
    }

    void validate_BrigProfile(Code item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, profile2str(val) != NULL, "Invalid version profile value", val);
    }

    void validate_BrigMachineModel(Code item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, machineModel2str(val) != NULL, "Invalid machine model value", val);
    }

    void validate_BrigSamplerCoordNormalization(Operand item, Brig::BrigSamplerCoordNormalization8_t val, const char* structName, const char* fieldName) const
    {
        validate(item, samplerCoordNormalization2str(val) != NULL, "Invalid sampler coord value", val);

        // It is an error if unnormalized mode is specified with an addressing mode of repeat or mirrored_repeat.

        OperandConstantSampler init = item;
        if (init.coord() == Brig::BRIG_COORD_UNNORMALIZED)
        {
            uint8_t addr = init.addressing();

            validate(init, addr == Brig::BRIG_ADDRESSING_UNDEFINED     ||
                           addr == Brig::BRIG_ADDRESSING_CLAMP_TO_EDGE ||
                           addr == Brig::BRIG_ADDRESSING_CLAMP_TO_BORDER,
                           "Unnormalized coordinates mode requires 'edge', 'border' or 'undefined' addressing");
        }
    }

    void validate_BrigSamplerFilter(Operand item, Brig::BrigSamplerFilter8_t val, const char* structName, const char* fieldName) const
    {
        validate(item, samplerFilter2str(val) != NULL, "Invalid sampler filter value", val);
    }

    void validate_BrigSamplerAddressing(Operand item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, samplerAddressing2str(val) != NULL, "Invalid sampler boundary value", val);
    }

    void validate_BrigOpcode(Inst item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, opcode2str(val) != NULL, "Invalid opcode value", val);
    }

    void validate_BrigMemoryOrder(Inst item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, memoryOrder2str(val) != NULL, "Invalid memoryOrder value", val);
    }

    void validate_BrigMemoryScope(Inst item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, memoryScope2str(val) != NULL, "Invalid memoryScope value", val);
    }

    void validate_BrigAtomicOperation(Inst item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, atomicOperation2str(val) != NULL, "Invalid atomicOperation value", val);
    }

    void validate_BrigWidth(Inst item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, width2str(val) != NULL, "Invalid width value", val);
    }

    void validate_BrigCompareOperation(Inst item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, compareOperation2str(val) != NULL, "Invalid compare operation value", val);
    }

    void validate_BrigPack(Inst item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, pack2str(val) != NULL, "Invalid pack value", val);
    }

    void validate_ImageDim(OperandConstantImage item, BrigUInt64 val, const char* name,  bool isPositive) const
    {
        uint64_t dim = (((uint64_t)val.hi) << 32) + val.lo;
        string geom = imageGeometry2str(item.geometry());
        const char* msg = isPositive? " must be positive" : " must be 0";
        validate(item, (dim > 0) == isPositive, "Invalid " + geom + " image initializer; " + name + msg);
    }

    void validate_fld_Width(OperandConstantImage item, BrigUInt64 val, const char* structName, const char* fieldName) const
    {
        validate_ImageDim(item, val, fieldName,  true);
    }

    void validate_fld_Height(OperandConstantImage item, BrigUInt64 val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned geom = OperandConstantImage(item).geometry();
        validate_ImageDim(item, val, fieldName,
            geom == BRIG_GEOMETRY_2D      ||
            geom == BRIG_GEOMETRY_3D      ||
            geom == BRIG_GEOMETRY_2DA     ||
            geom == BRIG_GEOMETRY_2DDEPTH ||
            geom == BRIG_GEOMETRY_2DADEPTH);
    }

    void validate_fld_Depth(OperandConstantImage item, BrigUInt64 val, const char* structName, const char* fieldName) const
    {
        unsigned geom = OperandConstantImage(item).geometry();
        validate_ImageDim(item, val,  fieldName,  geom == Brig::BRIG_GEOMETRY_3D);
    }

    void validate_fld_Array(OperandConstantImage item, BrigUInt64 val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned geom = OperandConstantImage(item).geometry();
        validate_ImageDim(item, val,  fieldName,
            geom == BRIG_GEOMETRY_1DA     ||
            geom == BRIG_GEOMETRY_2DA     ||
            geom == BRIG_GEOMETRY_2DADEPTH);
    }

    void validate_BrigImageQuery(Inst item, unsigned val, const char* structName, const char* fieldName) const
    {
        const char* s = imageQuery2str(val);
        validate(item, s != NULL, "Invalid image query value", val);
        validate(item, *s != 0,   "Unspecified image query");
    }

    void validate_BrigSamplerQuery(Inst item, unsigned val, const char* structName, const char* fieldName) const
    {
        const char* s = samplerQuery2str(val);
        validate(item, s != NULL, "Invalid sampler query value", val);
        validate(item, *s != 0,   "Unspecified sampler query");
    }

    template<class T> void validate_fld_Reserved(T item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, val == 0, "Invalid reserved field value", val);
    }

    void validate_BrigRegisterKind(Operand item, unsigned kind, const char* structName, const char* fieldName) const
    {
        validate(item, registerKind2str(kind) != NULL, "Invalid register kind value", kind);
    }

    void validate_fld_Line(Code item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, val > 0, "Invalid loc directive, line number must be greater than 0");
    }

    void validate_fld_Column(Code item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, val > 0, "Invalid loc directive, column number must be greater than 0");
    }

    //-------------------------------------------------------------------------
    // Low-level BRIG validation (functions used by autogenerated code)

    void validate_fld_Dim(Code item, BrigUInt64 val, const char* structName, const char* fieldName) const {}         // Nothing to do
    void validate_fld_Offset(Operand item, BrigUInt64 val, const char* structName, const char* fieldName) const {}   // Nothing to do
    void validate_fld_EquivClass(Inst item, unsigned val, const char* structName, const char* fieldName) const {}    // Nothing to do
    void validate_fld_InArgCount(Code item, unsigned val, const char* structName, const char* fieldName) const {}    // Nothing to do
    void validate_BrigVersion(Code item, unsigned val, const char* structName, const char* fieldName) const {}       // Validated elsewhere
    void validate_fld_OutArgCount(Code item, unsigned val, const char* structName, const char* fieldName) const {}   // Validated elsewhere
    void validate_fld_RegNum(Operand item, unsigned val, const char* structName, const char* fieldName) const {}     // Validated elsewhere


    //-------------------------------------------------------------------------
    // Access to Brig module

    const Brig::BrigModule* getBrigModule() const { return brig.getBrigModule(); }

    //-------------------------------------------------------------------------
    // Access to Brig sections

    const Brig::BrigSectionHeader* getSectionHeader(int section) const
    {
        assert(0 <= section && section < BRIG_NUM_SECTIONS);
        return getBrigModule()->section[section];
    }

    const char* getSectionAddr(int section, unsigned offset) const
    {
        return reinterpret_cast<const char*>(getSectionHeader(section)) + offset;
    }

    template<typename T>
    T getSectionData(int section, unsigned offset) const
    {
        assert(sizeof(T) <= 4);
        return *reinterpret_cast<const T*>(getSectionAddr(section, offset));
    }

    unsigned getSectionStartOffset(int section) const
    {
        return getSectionHeader(section)->headerByteCount;
    }

    unsigned getSectionSize(int section) const
    {
        return getSectionHeader(section)->byteCount;
    }

    string getSectionName(int section) const
    {
        uint32_t len = getSectionHeader(section)->nameLength;
        const char* name = reinterpret_cast<const char*>(&getSectionHeader(section)->name);
        return SRef(name, name + len);
    }

    string getExpectedSectionName(int section) const
    {
        switch(section)
        {
        case BRIG_SECTION_INDEX_DATA:      return "hsa_data";
        case BRIG_SECTION_INDEX_CODE:      return "hsa_code";
        case BRIG_SECTION_INDEX_OPERAND:   return "hsa_operand";
        default:                           return "";
        }
    }

    const SourceInfo* getSourceInfo(int section, unsigned offset) const
    {
        if (section == BRIG_SECTION_INDEX_CODE && offset > 0)
        {
            return brig.code().sourceInfo(offset);
        }
        else if (section == BRIG_SECTION_INDEX_OPERAND && offset > 0)
        {
            return brig.operands().sourceInfo(offset);
        }
        return NULL;
    }

    //-------------------------------------------------------------------------
    // Access to Brig items

    const Brig::BrigData* getDataItem(unsigned offset) const
    {
        return reinterpret_cast<const Brig::BrigData*>(getSectionAddr(BRIG_SECTION_INDEX_DATA, offset));
    }

    const Brig::BrigBase* getSectionItem(int section, unsigned offset) const
    {
        assert(section == BRIG_SECTION_INDEX_CODE || section == BRIG_SECTION_INDEX_OPERAND);
        return reinterpret_cast<const Brig::BrigBase*>(getSectionAddr(section, offset));
    }

    unsigned getItemSize(int section, unsigned offset) const
    {
        if (section == BRIG_SECTION_INDEX_DATA)
        {
            return ((getDataItem(offset)->byteCount + 7) / 4) * 4;
        }
        else
        {
            assert(section == BRIG_SECTION_INDEX_CODE || section == BRIG_SECTION_INDEX_OPERAND);
            return getSectionItem(section, offset)->byteCount;
        }
    }

    unsigned getItemDataSize(int section, unsigned offset) const
    {
        if (section == BRIG_SECTION_INDEX_DATA)
        {
            return getDataItem(offset)->byteCount;
        }
        else
        {
            assert(section == BRIG_SECTION_INDEX_CODE || section == BRIG_SECTION_INDEX_OPERAND);
            return getSectionItem(section, offset)->byteCount;
        }
    }

    unsigned getItemKind(int section, unsigned offset) const
    {
        assert(section == BRIG_SECTION_INDEX_CODE || section == BRIG_SECTION_INDEX_OPERAND);
        return getSectionItem(section, offset)->kind;
    }

    //-------------------------------------------------------------------------
    // Errors handling

    void validate(int section, unsigned offset, bool cond, SRef msg) const
    {
        assert(0 <= section && section < BRIG_NUM_SECTIONS);
        if (!cond) throw BrigFormatError(section, offset, msg);
    }

    void validate(Code c, bool cond, SRef msg) const
    {
        assert(c);
        if (!cond) throw BrigFormatError(BRIG_SECTION_INDEX_CODE, c.brigOffset(), msg);
    }

    void validate(Operand opr, bool cond, SRef msg) const
    {
        assert(opr);
        if (!cond) throw BrigFormatError(BRIG_SECTION_INDEX_OPERAND, opr.brigOffset(), msg);
    }

    void validate(Code c, bool cond, const char* msg)    const { validate(c, cond, SRef(msg)); }
    void validate(Operand c, bool cond, const char* msg) const { validate(c, cond, SRef(msg)); }

    template<class T>
    void validate(T item, bool cond, SRef msg, unsigned val) const
    {
        if (!cond)
        {
            ostringstream s;
            s << msg << " = " << val;
            validate(item, cond, s.str());
        }
    }

    string getErrorPos(int section, unsigned offset) const
    {
        ostringstream s;
        string sec = getSectionName(section);
        if (!sec.empty())
        {
            s << "Error in " << sec << " section, at offset " << offset << ":\n";
        }
        return s.str();
    }

    string dumpItem(int section, unsigned offset) const
    {
        ostringstream s;

        if (disasmOnError &&
            offset >= getSectionStartOffset(section) &&
            offset < getSectionSize(section))
        {
            Disassembler disasm(brig);

            if (section == BRIG_SECTION_INDEX_CODE)
            {
                Code code = Code(&brig, offset);
                if (Inst inst = code)
                {
                    s << ": " << disasm.get(inst, mModel, mProfile);
                }
                else if (Directive d = code)
                {
                    s << ": " << disasm.get(d, mModel, mProfile);
                }
            }
            else if (section == BRIG_SECTION_INDEX_OPERAND)
            {
                if (Operand opr = Operand(&brig, offset))
                {
                    s << ": " << disasm.get(opr, mModel, mProfile);
                }
            }
        }
        return s.str();
    }

    //-------------------------------------------------------------------------
    // Declaration of auto-generated routines for low-level BRIG validation

    bool ValidateBrigDirectiveFields(Directive item) const;
    bool ValidateBrigInstFields(Inst item) const;
    bool ValidateBrigOperandFields(Operand item) const;

    //-------------------------------------------------------------------------
    // Helpers

    bool isLargeModel()              const { return mModel == Brig::BRIG_MACHINE_LARGE; }
    bool isTopLevelStatement(Code d) const { return !isBodyOnly(d);     }
    bool isBodyStatement(Code d)     const { return !isToplevelOnly(d); }

}; // class ValidatorImpl

// ============================================================================
// Low-level BRIG validation (autogenerated)

#include "HSAILBrigValidation_gen.hpp"

// ============================================================================
// Public Validator API

Validator::Validator(BrigContainer &c) { impl = new ValidatorImpl(c); }
Validator::~Validator()                { delete impl; }

bool   Validator::validate(bool disasmOnError /*= false*/) const { return impl->validate(disasmOnError); }
string Validator::getErrorMsg(istream *is)                 const { return impl->getErrorMsg(is); }
int    Validator::getErrorCode()                           const { return impl->getErrorCode(); }

// ============================================================================
} // HSAIL_ASM namespace

///////========================================================================
///////========================================================================
///////========================================================================
/////// STEPS IN PORTING LIBHSAIL TO NEW SPEC
///////
/////// - update brig_new.h
/////// - update HSAILBrigInstr.hdl (to make 'getOperandType')
/////// - update Scanner and Parser
/////// - update disassembler
/////// - update HSAILUtilities.cpp
/////// - update Validator
///////   - HSAILValidator.cpp
///////     - class BrigHelper
///////     - Low-level BRIG validation
///////     - high-level validation if necessary
///////   - HSAILValidatorBase.h
///////     - special accessors get*Ex
///////   - HSAILValidatorBase.cpp
///////     - prop2key
///////     - prop2str
///////     - other code in case of complex changes
/////// - update hand-written tests, fix bugs
/////// - Update TestGen
///////   - HSAILTestGenUtilities
///////   - HSAILTestGenContext.cpp
///////   - HSAILTestGenProp.* (if operands have to be added/removed)
///////   - HSAILTestGenNavigator.cpp (getCategoryName and relevant code)
/////// - update generated tests, fix bugs
/////// - Update Emulator
///////   - HSAILTestGenEmulator.cpp
///////   - HSAILTestGenTestData.h
/////// - update LUA tests, fix bugs
///////
///////========================================================================
///////========================================================================
///////========================================================================

//F1.0 how to check?
//F EXTENSIONS:
//F - BrigImageChannelType: Values 16 through 64 are available for extensions
//F - BrigImageGeometry: Values 6 through 255 are available for extensions
//F - BrigImageChannelOrder: Values 17 through 255 are available for extensions
//F - BrigSamplerAddressing: Values 5 through 255 are available for extensions.
//F - BrigSamplerCoordNormalization: Values 5 through 255 are available for extensions.
//F - BrigSamplerFilter: Values 2 through 63 are available for extensions
//F - BrigSegment: Values 9 through 16 are available for extensions

//F TODO
//F create random BRIG tests on all combinations of flags such as isConst, isDecl, etc
//F Improve errors reporting

//F TEMPORARILY DISABLED FEATURES
//F - identifiers must not start with "__hsa" (currently, this check is disabled)
//F - addresses of 32-bit segments must have b32 type and 's' register, if any (currently, addresses may have both b32 and b64 type; both 's' and 'd' registers and allowed)
//F - images and samplers must be passed to operations in 'd' registers (currently, addresses are allowed as well)

//F MAJOR PENDING FEATURES
//F - Support of GCN extension has not been tested yet
//F - The s, d, and q registers in HSAIL share a single pool of resources.


