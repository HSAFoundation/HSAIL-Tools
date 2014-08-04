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
#include <iostream>
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

// ============================================================================
// ============================================================================
//============================================================================

namespace HSAIL_ASM {

//============================================================================
// BRIG Sections

enum {
    BRIG_SEC_CODE        = 0,
    BRIG_SEC_OPERANDS    = 1,
    BRIG_SEC_DATA        = 2,

    BRIG_NUM_SECTIONS    = 3,
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
            throw BrigFormatError(BRIG_SEC_OPERANDS, opr.brigOffset(), msg, code);
        }
        else
        {
            throw BrigFormatError(BRIG_SEC_CODE, inst.brigOffset(), msg, code);
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
    case ROUND_ATTR_NEAR:       return BRIG_ROUND_FLOAT_NEAR_EVEN;
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

    static bool isSbr(Directive d)
    {
        return DirectiveExecutable(d);
    }

    static bool isFunc(Directive d)
    {
        return DirectiveFunction(d) || DirectiveIndirectFunction(d);
    }

    static bool isSignature(Directive d)
    {
        return DirectiveSignature(d);
    }

    static bool isKernel(Directive d)
    {
        return DirectiveKernel(d);
    }

    static bool isVar(Directive d)
    {
        return DirectiveVariable(d);
    }

    static bool isFbar(Directive d)
    {
        return DirectiveFbarrier(d);
    }

    static bool isLabel(Directive d)
    {
        return DirectiveLabel(d);
    }

public: // Brig Object Properties

    static char getNamePref(Directive d)
    {
        string name = getName(d);
        return name.empty()? 0 : name[0];
    }

    static bool isArgSeg(Directive d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_ARG;
    }

    static bool isKernArgSeg(Directive d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_KERNARG;
    }

    static bool isSpillSeg(Directive d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_SPILL;
    }

    static bool isGlobalSeg(Directive d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_GLOBAL;
    }

    static bool isGroupSeg(Directive d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_GROUP;
    }

    static bool isPrivateSeg(Directive d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_PRIVATE;
    }

    static bool isReadonlySeg(Directive d)
    {
        assert(isVar(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_READONLY;
    }

    static bool isProgLinkage(Directive d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_PROGRAM;
    }

    static bool isModuleLinkage(Directive d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_MODULE;
    }

    static bool isFuncLinkage(Directive d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_FUNCTION;
    }

    static bool isArgLinkage(Directive d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_ARG;
    }

    static bool isNoneLinkage(Directive d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_NONE;
    }

    static uint64_t getArraySize(Directive d)
    {
        if (DirectiveVariable sym = d) return sym.dim();
        assert(false);
        return 0;
    }

    static unsigned getAlignment(Directive d)
    {
        assert(isVar(d));
        if (DirectiveVariable sym = d) return sym.align();
        assert(false);
        return Brig::BRIG_ALIGNMENT_LAST;
    }

    static unsigned getAllocation(Directive d)
    {
        assert(isVar(d) || isFbar(d));
        if (DirectiveVariable sym = d) return sym.allocation();
        return Brig::BRIG_ALLOCATION_NONE;
    }

    static bool isConst(Directive d)
    {
        if (DirectiveVariable sym = d) return sym.modifier().isConst();
        assert(false);
        return false;
    }

    static bool isArray(Directive d)
    {
        if (DirectiveVariable sym = d) return sym.modifier().isArray();
        assert(false);
        return false;
    }

    static bool isFlex(Directive d)
    {
        if (DirectiveVariable sym = d) return sym.modifier().isFlexArray();
        assert(false);
        return false;
    }

    static bool isInitialized(Directive d)
    {
        if (DirectiveVariable sym = d) return sym.init();
        return false;
    }

    static Directive getInitializer(Directive d)
    {
        assert(isVar(d));

        if (DirectiveVariable sym = d) return sym.init();
        return Directive();
    }

    static unsigned getParamNum(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.inArgCount() + exec.outArgCount();

        assert(false);
        return 0;
    }

    static unsigned getInParamNum(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.inArgCount();

        assert(false);
        return 0;
    }

    static unsigned getOutParamNum(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.outArgCount();

        assert(false);
        return 0;
    }

    static Code getFirstInParam(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.firstInArg();

        assert(false);
        return Directive();
    }

    static Code getFirstOutParam(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.next();

        assert(false);
        return Directive();
    }

    static unsigned getScopedSize(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.codeBlockEntryCount();

        assert(false);
        return 0;
    }

    static Code getFirstScoped(Directive d)
    {
    	if (DirectiveExecutable dfc = d) return dfc.firstCodeBlockEntry();

        assert(false);
        return d.next();
    }

    static Code getNextTopLevel(Directive d)
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
    typedef map<SRef, Directive> NameMap;
    typedef map<Offset, Inst> LabelMap;

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
    BrigContainer &brig;        // BRIG container being validated //F should validate module, not container

private: // Context state
    State    state;     // context state: module/sbr/block scope
    unsigned callsNum;  // number of call instructions in the current code block

private: // Enabled extensions
    unsigned extensions;     // enabled extensions

    // Labels may be defined in two places:
    // - in an argument block.
    //   Instructions in this block may only refer these labels.
    // - in func/kernel body, but outside of argument blocks.
    //   Instructions func/kernel body may only refer these labels.
    //   These labels may be used ONLY by directives and code outside of argument blocks.
    // A weird thing is both kinds of labels share a single namespace, so
    // a label with the same name cannot be defined both inside and outside of an argument block.
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
        : brig(c), state(STATE_INVALID), callsNum(0)
    {}

public:
    //-------------------------------------------------------------------------
    // PUBLIC API TO CONTROL CONTEXT
    //-------------------------------------------------------------------------
    // Validation of order:
    // 1. annotations
    // 2. version
    // 3. extension and annotations
    // 4. statements and annotations

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
        startCodeBlock();
    }

    void notifyArgBlkEnd(Code c)
    {
        validate(c, isArgScope(), "Missing arg block start");
        endCodeBlock(c);
        state = STATE_SBR_STT_SCOPE;
    }

    void notifyInst(Code c)
    {
        if      (isSbrScope()) state = STATE_SBR_STT_SCOPE;
        else if (isArgScope()) state = STATE_ARG_STT_SCOPE;
        else                   assert(false);
    }

    void notifyLabel(Code c) { notifyInst(c); }

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

    void startSbr(Directive d)
    {
        notifySbrStart();

        sbrStartOffset = d.brigOffset();
        sbrEndOffset   = getNextTopLevel(d).brigOffset();

        Directive arg = d.next();
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
    }

    void endSbr()
    {
        assert(isSbrScope());
        validateLabels();
        clearLabels();
        clearSymbols();
        notifySbrEnd();
    }

    void startCodeBlock()
    {
        callsNum = 0;
    }

    void endCodeBlock(Code c)
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

    //F Pass reference to instruction to refer it in case of an error
    void checkLabelUse(Code owner, DirectiveLabel lab)
    {
        assert(owner);
        assert(lab);

        if (!isLabelDefined(lab))
        {
            setForwLabelRef(owner, lab);
        }
    }

    void defineOutArg(Directive d, Directive owner)
    {
        if (isFunc(owner)) outArgDefs.insert(d.brigOffset());
        defineVar(d, owner);
    }

    void defineInArg(Directive d, Directive owner)
    {
        if (isFunc(owner)) inArgDefs.insert(d.brigOffset());
        defineVar(d, owner);
    }

    void defineVar(Directive d, Directive owner = Directive())
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
                validate(d, getAllocation(d) == BRIG_ALLOCATION_NONE, "Formal arguments of function/kernel declaration and sinatures must have none allocation");
            }
            else
            {
                validate(d, isFuncLinkage(d), "Formal arguments of function/kernel definitions must have function linkage");
                validate(d, getAllocation(d) == BRIG_ALLOCATION_AUTOMATIC, "Formal arguments of function/kernel definitions must have automatic allocation");
            }
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
        }

        if (getName(d).length() == 0)
        {
            validate(d, isSignature(owner), "Empty name is only allowed for signature arguments");
        }
        else if (getNamePref(d) == '%')
        {
            addLocalSym(d, owner);
        }
        else
        {
            addGlobalSym(d);
        }
    }

    void checkVarUse(Operand opr, Directive d)
    {
        assert(isVar(d) || isFbar(d));

        checkSymUse(opr, d);
    }

    //FF
    // General requirements:
    //     + within an arg block there must be exactly one call operation
    // Requirements for formal arguments:
    //     - For input formal arguments, it is undefined if they are accessed by any operation other than a st operation.
    //     - For the output formal argument, it is undefined if it is accessed by any operation other than a ld operation.
    // Requirements for actual arguments:
    //     - For actual arguments that correspond to the input formal arguments, it is undefined
    //       if they are accessed by any operation other than a st operation that is post-dominated by the call operation.
    //     - For the actual argument that corresponds to the output formal argument, it is undefined if it is accessed
    //       by any operation other than a ld operation that is dominated by the call operation.
    //     + Each actual argument must appear exactly once as either an input actual
    //       argument or output actual argument of the call operation. It is an error if an actual
    //       argument does not appear as one of the call operations input or output arguments,
    //       appears more than once as an input or output argument, or appears as both an input
    //       and output argument.

    bool isTransientArg(Directive d) // True for arg variables defined inside an arg scope
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

    void registerCallArg(Inst inst, Directive arg, bool isOutArgs)
    {
        Offset off = arg.brigOffset();

        validate(inst, isTransientArg(arg), "Call arguments must be defined in arg scope");
        validate(inst, callArgs.count(off) == 1, "Each variable must appear exactly once in the list of call arguments");

        callArgs.erase(off);
    }

    void defineSbr(Directive d)
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

    void markSymUsed(Directive d)
    {
        assert(d);
        assert(isVar(d) || isFbar(d) || isSbr(d));

        modSymUsed.insert(getName(d));
    }

public:
    // Register a definition or declaration of a global symbol.
    // The purpose is to identify directive which should be used for all references
    // to this symbol - the first definition (or first declaration if there are no definitions).
    void registerGlobalSym(Directive d)
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
    bool isValidGlobalReference(Directive d)
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
            //F: should refer invalid instruction rather than the label itself
            validate(it->second, defs.count(it->first) > 0,
                     "Invalid reference to label defined in another scope");
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

    void dumpDefinedLabels()
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
    }

private:
    //-------------------------------------------------------------------------
    // Implementation: VARIABLES, FUNCTIONS, KERNELS
    //-------------------------------------------------------------------------

    // Local symbols cannot be declared, only defined.
    // Consequently, we only check that the symbol is defined only once.
    void addLocalSym(Directive d, bool isArgument)
    {
        assert(isVar(d) || isFbar(d));

        validate(d, isSbrScope() || isArgScope(),
                 "Variables starting with '%' must be defined in kernels or functions");

        if (isArgScope()) // Add BOTH arg and non-arg variables
        {
            validate(d, argVarNames.count(getName(d)) == 0, "Invalid variable redefinition");
            argVarDefs.insert(d.brigOffset());
            argVarNames.insert(getName(d));
            callArgs.insert(d.brigOffset());
        }

        // NB: non-arg variables defined in an arg scope logically belong to both
        //     arg scope and sbr scope, so these variables are added to BOTH lists

        if (isArgument || !isArgSeg(d)) // Add all variables except for args defined in arg scope
        {
            validate(d, sbrVarNames.count(getName(d)) == 0, SRef(isArgument? "Duplicate argument declaration" : "Invalid variable redefinition"));
            sbrVarDefs.insert(d.brigOffset());
            sbrVarNames.insert(getName(d));
        }
    }

    // Global symbols can be both declared and defined.
    // Consequently, we check that:
    // - the symbol is defined only once;
    // - if there are several declarations (and possibly a definition), they are identical.
    void addGlobalSym(Directive d)
    {
        assert(isVar(d) || isFbar(d) || isSbr(d));

        validate(d, isMdlScope(),
                 "Identifiers starting with '&' must be defined outside of kernels and functions");

        validateDecl(d, modSymDesc);
    }

    void validateDecl(Directive d, NameMap &desc)
    {
        assert(isVar(d) || isFbar(d) || isSbr(d));

        if (desc.count(getName(d)) == 0)    // This is the first definition/declaration
        {
            desc[getName(d)] = d;
        }
        else                                // This must be a redefinition of the same entity
        {
            Directive prev = desc[getName(d)];

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

    void checkSymUse(Operand opr, Directive d)
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

    bool eqDecl(Directive d1, Directive d2)
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
    bool eqSbrDecl(Directive sbr1, Directive sbr2)
    {
        if (getSymLinkage(sbr1) != getSymLinkage(sbr2)) return false;

        if (getInParamNum(sbr1)  == getInParamNum(sbr2) &&
            getOutParamNum(sbr1) == getOutParamNum(sbr2))
        {
            Directive arg1 = sbr1.next();
            Directive arg2 = sbr2.next();

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
            getSegment(var1)   != getSegment(var2)  ||
            getDataType(var1)  != getDataType(var2) ||
            getAlignment(var1) != getAlignment(var2)) return false;

        if (isFlex(var1) != isFlex(var2)) return false;

        if (isConst(var1) != isConst(var2) ||
            isArray(var1) != isArray(var2))
            return false;

        if (!isArg) //FF add note to issues
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
            Directive d = it->second;
            if (isDecl(d) && isModuleLinkage(d) && modSymUsed.count(getName(d)) > 0)
            {
                if (isKernel(d)) validate(d,  false, "Kernel must be defined because it is used by module code");
                if (isFunc(d))   validate(d,  false, "Function must be defined because it is used by module code");
                if (isVar(d))    validate(d,  false, "Variable must be defined because it is used by module code");
                if (isFbar(d))   validate(d,  false, "Fbarrier must be defined because it is used by module code");
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
        if (!cond) throw BrigFormatError(BRIG_SEC_CODE, c.brigOffset(), msg);
    }

    void validate(Operand opr, bool cond, SRef msg) const
    {
        if (!cond) throw BrigFormatError(BRIG_SEC_OPERANDS, opr.brigOffset(), msg);
    }
};

//=============================================================================
//=============================================================================
//=============================================================================
// Validator implementation

static const char* ALPHA    = "_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const char* ALPHANUM = "_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

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

        if (is && si)
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
        ///F add validation of:
        ///F - module struct
        ///F - BrigSectionHeader

        validateSection(BRIG_SEC_DATA);
        validateSection(BRIG_SEC_CODE);
        validateSection(BRIG_SEC_OPERANDS);
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

                if (DirectiveVersion ver = code)
                {
                    validate(ver, !versionFound, "Duplicate version directive");

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

    void initBrigVersion()
    {
        DirectiveVersion v;
        Code start = brig.code().begin();

        for(Code code = start; !v && code != brig.code().end(); code = code.next()) v = code;

        validate(start, v, "Missing Version directive");

        major = v.hsailMajor();
        minor = v.hsailMinor();

        validate(v, major         == Brig::BRIG_VERSION_HSAIL_MAJOR, "Unsupported major HSAIL version");
        validate(v, minor         <= Brig::BRIG_VERSION_HSAIL_MINOR, "Unsupported minor HSAIL version");
        validate(v, v.brigMajor() == Brig::BRIG_VERSION_BRIG_MAJOR,  "Unsupported major BRIG version");
        validate(v, v.brigMinor() <= Brig::BRIG_VERSION_BRIG_MINOR,  "Unsupported minor BRIG version");
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
                validate(inst, inst.operands().size() <= 5, "Instruction cannot have more than 5 operands");

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
                    validateDef(d, context);
                }
            }

            code = next;
        }

        context.endModule();
    }

    void validateSbr(Directive d, ValidatorContext &context) const
    {
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

                validateDef(scoped, context);
            }
            else if (Inst i = p)
            {
                context.validateExtensionOpcode(i);

                // Check that all symbols referred to by operands are visible in the current context
                unsigned numOperands  = i.operands().size();
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
                unreachableCode = (i.opcode() == Brig::BRIG_OPCODE_BR || i.opcode() == Brig::BRIG_OPCODE_RET);
            }
        }
        context.endSbr();
    }

    void validateOrder(Code c, ValidatorContext &context) const
    {
        if      (isAnnotation(c))           context.notifyAnnotation(c);
        else if (DirectiveVersion(c))       context.notifyVersion(c);
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

    void validateDef(Directive d, ValidatorContext &context) const
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
            unsigned len = p.operands().size();

            for (unsigned i = 0; i < len; ++i)
            {
                Operand opr = p.operands()[i];
                if (OperandCodeRef ref = opr)
                {
                    Directive sym = ref.ref();
                    validateSymUse(d, opr, sym, context);
                }
            }
        }

    }

    void validateUse(Inst inst, Operand opr, ValidatorContext &context) const
    {
        switch (opr.kind())
        {
        case Brig::BRIG_KIND_OPERAND_ADDRESS:
            if (Directive sym = OperandAddress(opr).symbol())
            {
                validateSymUse(inst, opr, sym, context);
                if (context.isInArg(sym))       validateArgUse(inst, sym, true);
                else if (context.isOutArg(sym)) validateArgUse(inst, sym, false);
            }
            break;

        case Brig::BRIG_KIND_OPERAND_CODE_REF:
            validateSymUse(inst, opr, OperandCodeRef(opr).ref(), context);
            break;

        case Brig::BRIG_KIND_OPERAND_CODE_LIST:
            validateListUse(inst, opr, context);
            break;

        case Brig::BRIG_KIND_OPERAND_OPERAND_LIST: // Vector, image and sampler initializers
        case Brig::BRIG_KIND_OPERAND_REG:
        case Brig::BRIG_KIND_OPERAND_DATA:
        case Brig::BRIG_KIND_OPERAND_STRING:
        case Brig::BRIG_KIND_OPERAND_WAVESIZE:
        case Brig::BRIG_KIND_OPERAND_IMAGE_PROPERTIES:
        case Brig::BRIG_KIND_OPERAND_SAMPLER_PROPERTIES:
            // Nothing to validate
            break;

        default:
            assert(false);
            break;
        }
    }

    void validateSymUse(Code owner, Operand opr, Directive sym, ValidatorContext &context) const
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
        if (isImageExtType(sym.type())) return; //F this is a temporary patch

        if (isInputArg) validate(inst, inst.opcode() == Brig::BRIG_OPCODE_LD, "Input arguments may only be accessed by ld operations");
        else            validate(inst, inst.opcode() == Brig::BRIG_OPCODE_ST, "Output argument may only be accessed by st operations");
    }

    void validateListUse(Code owner, OperandCodeList list, ValidatorContext &context) const
    {
        assert(list);

        unsigned size = list.elements().size();
        for (unsigned i = 0; i < size; ++i)
        {
            Directive sym = list.elements()[i];
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
            Directive ref = arglist.elements()[n];
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
        else if (i.opcode() == Brig::BRIG_OPCODE_ALLOCA)
        {
            validate(i, !context.isArgScope(), "Instruction alloca cannot be used in an argument scope");
        }
    }

    //-------------------------------------------------------------------------
    // Low-level Brig format validation

    void validateSection(int section)
    {
        Brig::BrigSectionHeader* header = getSectionHeader(section);

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
        if (section == BRIG_SEC_DATA)
        {
            uint32_t dataSize = getSectionData<uint32_t>(section, offset);
            uint32_t itemSize = ((dataSize + 7) / 4) * 4;

            for (unsigned i = offset + 4 + dataSize; i < offset + itemSize; ++i)
            {
                validate(section, offset, getSectionData<uint8_t>(section, i) == 0, "Padding bytes at the end of string elements must be 0");
            }
        }
    }

    unsigned getItemSize(int section, unsigned offset) const
    {
        if (section == BRIG_SEC_DATA)
        {
            return ((getSectionData<uint32_t>(section, offset) + 7) / 4) * 4;
        }
        else
        {
            return getSectionData<uint16_t>(section, offset);
        }
    }

    unsigned getMinItemSize(int section, unsigned offset) const
    {
        if (section == BRIG_SEC_DATA) return BRIG_MIN_DATA_ITEM_SIZE;

        uint16_t itemKind = getSectionData<uint16_t>(section, offset + sizeof(uint16_t));
        int result = size_of_brig_record(itemKind);
        validate(section, offset, result > 0, "Invalid item kind");
        return result;
    }

    //-------------------------------------------------------------------------
    // Validation of Complex Items

    // Validate reference to data in string section:
    // - offset must be a valid offset to string section
    // - required data size = item data size
    //void validateStringData(Directive d, unsigned offset, unsigned type, unsigned length, const char* structName, const char* fieldName)
    //{
    //    assert(type != Brig::BRIG_TYPE_B1); // b1 is not allowed in initializers and block directives
    //
    //    validateOffset(d, BRIG_SEC_DATA, offset, structName, fieldName);
    //
    //    uint32_t dataSize = getSectionData<uint32_t>(BRIG_SEC_DATA, offset);
    //
    //    if ((getBrigTypeNumBits(type) / 8 ) * length != dataSize) validate(d, false, "Expected size of " + string(structName) + "." + fieldName + " does not match actual data size");
    //}

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
            if (OperandData imm = opr)
            {
                assert(type == BRIG_TYPE_U32 || type == BRIG_TYPE_U64);

                validate(imm, getImmSize(imm) == getBrigTypeNumBits(type), "Invalid size of immediate value");
                SRef data = imm.data();
                uint64_t val = (type == BRIG_TYPE_U32)? *(uint32_t*)data.begin : *(uint64_t*)data.begin; //F
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
            OperandData imm = d.operands()[0];
            assert(imm);

            SRef data = imm.data();
            uint32_t val = *(uint32_t*)data.begin; //F

            validate(d, (val & 0x1F) == 0, "Exception bits 0 to 4 must be zero for the base profile");
        }

        validate(d, getCtlDirOperandType(d.control(), i) == BRIG_TYPE_NONE, "Insufficient number of operands");
    }

    void validatePragma(DirectivePragma d)
    {
        unsigned len = d.operands().size();

        validate(d, len > 0, "Pragma must have at least one operand");

        for (unsigned i = 0; i < len; ++i)
        {
            Operand opr = d.operands()[i];

            if (OperandData imm = opr)
            {
                validate(d, getImmSize(imm) == 64, "Invalid immediate operand of pragma directive; expected a 64-bit value");
            }
            else if (OperandCodeRef ref = opr)
            {
                Directive sym = ref.ref();
                validate(d, DirectiveVariable(sym) ||
                            DirectiveFbarrier(sym) ||
                            DirectiveLabel(sym) ||
                            DirectiveExecutable(sym), "Invalid operand of pragma directive");
            }
            else
            {
                validate(d, OperandString(opr), "Invalid operand of pragma directive");
            }
        }
    }

    void validateDirective(Directive d)
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
        case BRIG_KIND_DIRECTIVE_VERSION:           break;

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

    void validateComplexInst(Inst i) const
    {
        // Validate that there is a kernel/function which uses this instruction
        validate(i, usedInst.count(i.brigOffset()) > 0, "Instruction does not belong to any kernel/function");

        switch(i.opcode())
        {
        case Brig::BRIG_OPCODE_CALL:  validateDirectCall(i); break;
        case Brig::BRIG_OPCODE_SCALL: validateSwitchCall(i); break;
        case Brig::BRIG_OPCODE_ICALL: validateIndirectCall(i); break;
        case Brig::BRIG_OPCODE_MEMFENCE: validateMemFence(i); break;

        default: break;
        }
    }

    void validateOperandAddress(OperandAddress addr) const
    {
        assert(addr);

        // This is a low-level check to make sure that operand refers a DirectiveVariable
        if (addr.brig()->symbol) validate(addr, isDirectiveKind<DirectiveVariable>(addr.symbol()), "Invalid symbol reference");

        // This is a low-level check to validate register name
        if (addr.reg()) validateReg(addr, addr.reg());

        // Make sure all address elements specify the same size
        unsigned addrSize = getAddrSize(addr, isLargeModel()); // 32 or 64; 0 if both are valid
        if (addrSize == 0) return; // nothing to validate

        if (addr.symbol())
        {
#if !ENABLE_ADDRESS_SIZE_CHECK
            // This is a temporary workaround for lowering
            if (!isLargeModel() || getSegAddrSize(addr.symbol().segment(), isLargeModel()) != 32 || addrSize == 32)
#endif
            validate(addr, addrSize == getSegAddrSize(addr.symbol().segment(), isLargeModel()),
                     "Malformed address: segment size does not match register or offset size");
        }

        if (addr.reg()) validate(addr, addrSize == getRegBits(addr.reg().regKind()), "Malformed address: register size does not match segment or offset size");
    }

    unsigned validateReg(Operand opr, OperandReg reg) const
    {
        unsigned regNum = reg.regNum();
        unsigned regBits = getRegBits(reg.regKind());
        SRef invalidIndex = "Invalid register index";

        switch(regBits)
        {
        case  1:  validate(opr, regNum <= 7,   invalidIndex); break;
        case 32:  validate(opr, regNum <= 127, invalidIndex); break;
        case 64:  validate(opr, regNum <= 63,  invalidIndex); break;
        case 128: validate(opr, regNum <= 31,  invalidIndex); break;
        default:
            assert(0); // Validated on previous steps
            return 0;
        }

        return regBits;
    }

    void validateOperandReg(OperandReg r) const
    {
        assert(r);
        validateReg(r, r);
    }

    template <class DirectiveName> bool isDirectiveKind(Directive d) const
    {
        return DirectiveName(d);
    }

    void validateOperand(Operand opr)
    {
        assert(opr);

        switch (opr.kind())
        {
        case Brig::BRIG_KIND_OPERAND_ADDRESS:
            validateOperandAddress(opr);
            break;

        case Brig::BRIG_KIND_OPERAND_REG:
            validateOperandReg(opr);
            break;

        case Brig::BRIG_KIND_OPERAND_CODE_LIST:
        case Brig::BRIG_KIND_OPERAND_CODE_REF:
        case Brig::BRIG_KIND_OPERAND_OPERAND_LIST:
        case Brig::BRIG_KIND_OPERAND_WAVESIZE:
        case Brig::BRIG_KIND_OPERAND_DATA:
        case Brig::BRIG_KIND_OPERAND_STRING:
        case Brig::BRIG_KIND_OPERAND_IMAGE_PROPERTIES:
        case Brig::BRIG_KIND_OPERAND_SAMPLER_PROPERTIES:
            break; // Nothing to do

        default:
            // should not get here!
            assert(false);
            validate(opr, false, "Unsupported operand kind");
            break;
        }
    }

    //-------------------------------------------------------------------------

    void validateName(Directive d, const char* pref) const
    {
        string name = getName(d);

        if (name.length() == 0) return; // empty names are validated elsewhere

        validate(d, name.find_first_of(pref) == 0, "Invalid identifier prefix");

        // validate(d, name.find("__hsa") != 1, "Identifiers must not start with the characters '__hsa'");

        validate(d, name.length() > 1 &&
                    name.find_first_of(ALPHA, 1) == 1 &&
                   (name.length() == 2 || name.find_first_not_of(ALPHANUM, 2) == string::npos), "Invalid identifier");
    }

    bool isImage(Directive d) const {
        DirectiveVariable v = d;
        return isImageOrSampler(d) && !isSampler(d);
    }

    bool isSampler(Directive d) const {
        DirectiveVariable v = d;
        return v && v.type() == Brig::BRIG_TYPE_SAMP;
    }

    bool isImageOrSampler(Directive d) const {
        DirectiveVariable v = d;
        return v && isImageExtType(v.type());
    }

    bool isSignal(Directive d) const {
        DirectiveVariable v = d;
        return v && (v.type() == Brig::BRIG_TYPE_SIG32 || v.type() == Brig::BRIG_TYPE_SIG64);
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

    void validateDefDecl(Directive d)
    {
        // NB: Validation of arg and kernarg segment variables depends on context (see defineVar)

        if (isDecl(d))
        {
            if      (isSignature(d))           validate(d, false,                 "Signatures have no declarations");
            else if (isFunc(d) || isKernel(d)) validate(d, getScopedSize(d) == 0, "Kernel/function declaration cannot have a body");
        }
    }

    void validateLinkage(Directive d)
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

        // Flexible arrays assume that 'array' property is also set. This is checked on first phase

        // Flexible arrays may be declared only as last function argument (formal)
        validate(d, !isFlex(d) || isArgSeg(d), "Array without specified size may only be defined as the last function argument");

        // If the object is an array, the size of the array must be specified in the
        // definition but can be omitted in the declaration.
        if (isArray(d))
        {
            if (isFlex(d))
            {
                validate(d, getArraySize(d) == 0, "Array without specified size must have dim = 0");
            }
            else if (isDef(d))
            {
                validate(d, getArraySize(d) > 0, "Array definitions must have dim > 0");
            }
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

    void validateVarType(DirectiveVariable var) const
    {
        validate(var, isValidVarType(var.type()), "Invalid variable type");
    }

    void validateAlign(Directive d) const
    {
        assert(isVar(d));
        validate(d, isValidAlignment(getAlignment(d), getDataType(d)),
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

            if      (isImage(sym))   validateOpaqueInit<OperandImageProperties>  (sym, "Invalid initializer, expected OperandImageProperties");
            else if (isSampler(sym)) validateOpaqueInit<OperandSamplerProperties>(sym, "Invalid initializer, expected OperandSamplerProperties");
            else if (isSignal(sym))  validateSignalInit(sym);
            else                     validateNumInit(sym);
        }
        else
        {
            validate(sym, isDecl(sym) || !isConst(sym), "Const variable definitions must have an initializer");
        }
    }

    template<class T> void validateOpaqueInit(DirectiveVariable sym, SRef invalidInitializerMsg)
    {
        uint64_t dim = getArraySize(sym);

        if (dim == 0)
        {
            T init = sym.init();
            validate(sym, init, invalidInitializerMsg);
        }
        else
        {
            OperandOperandList init = sym.init();
            validate(sym, init, "Invalid array initializer, expected OperandOperandList");

            uint64_t elementCount = (dim == 0) ? 1 : dim; // scalars have dim=0 and 1 value
            unsigned size = init.elements().size();

            validate(init, size > 0, "Invalid initializer: must include at least one value");
            validate(init, elementCount >= size, "Invalid initializer: too many initial values");

            for (unsigned i = 0; i < size; ++i)
            {
                T elementInit = init.elements()[i];
                validate(init, elementInit, invalidInitializerMsg);
            }
        }
    }

    void validateSignalInit(DirectiveVariable sym)
    {
        validateNumInit(sym);
        SRef data = OperandData(sym.init()).data();

        for (unsigned i = 0; i < data.length(); ++i)
        {
            validate(sym, data[i] == 0, "Signal handles may only be initialized with 0");
        }
    }

    void validateNumInit(DirectiveVariable sym)
    {
        OperandData init = sym.init();
        uint64_t dim = getArraySize(sym);

        validate(sym, init, "Invalid initializer, expected OperandData");

        SRef data = init.data();
        uint64_t elementCount = (dim == 0) ? 1 : dim; // scalars have dim=0 and 1 value

        uint64_t typeSize = getBrigTypeNumBits(getDataType(sym)) / 8;
        validate(init, (data.length() % typeSize) == 0, "Invalid initializer length, must be a multiple of type size");
        validate(init, data.length() > 0, "Invalid initializer: must include at least one value");
        validate(init, elementCount >= data.length() / typeSize, "Invalid initializer: too many initial values");
    }

    void validateArgs(Directive d)
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

    Code validateSbrArgs(Directive sbr, Code next, Code argStart, unsigned paramNum, bool isInputArgs)
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

            if (isFlex(arg))
            {
                validate(arg, !isKernel(sbr),    "Kernel array arguments must have fixed size");
                validate(arg, isInputArgs,       "Output array argument must have fixed size");
                validate(arg, i == paramNum - 1, "Only last input argument of function/signature may be an array with no specified size");
            }

            validate(arg, !isInitialized(arg), "Arguments cannot have initializer");
            validate(arg, !isConst(arg),       "Arguments cannot be const");

            //validateInit(arg); // This is necessary only to avoid cryptic error msg
            arg = arg.next();
        }
        return arg;
    }

    void validateScoped(Directive sbr)
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
            //F validate ordering if it is not validated elsewhere (code elements follow each other without gaps)
            //F Is there a guarantee that code.next() returns offset of next item? This should be validated by an assert

            if (isDirective(it.kind()))
            {
                validate(it, isBodyStatement(it), "Directive is not allowed inside kernel or function");
                validate(it, !isVar(it) || !isFlex(it),
                         "Array without specified size may only be defined as the last function argument");
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

        validate(out, fn.outArgCount() == out.elementCount(), "Invalid number of output arguments");

        DirectiveVariable formalArg = fn.next();
        for (unsigned i = 0; i < fn.outArgCount(); ++i)
        {
            assert(formalArg); // Validated on previous steps

            validateCallArg(out, out.elements(i), formalArg);
            formalArg = formalArg.next();
        }

        //FF: make a separate function
        validate(in, fn.inArgCount() == in.elementCount(), "Invalid number of input arguments");

        formalArg = fn.firstInArg();
        for (unsigned i = 0; i < fn.inArgCount(); ++i)
        {
            assert(formalArg); // Validated on previous steps

            validateCallArg(in, in.elements(i), formalArg);
            formalArg = formalArg.next();
        }
    }

    // An actual argument is compatible with a formal parameter if one of these three
    // properties hold:
    // - The two have identical properties, type, size, and alignment.
    // - Both are arrays with the same size and alignment and the elements have identical properties.
    // - Both are arrays with elements that have identical properties, both arrays have
    //   the same alignment, and the formal is a flexible array (of no specified size).
    void validateCallArg(OperandCodeList list, Directive var, DirectiveVariable formal) const
    {
        DirectiveVariable actual = var;

        validate(list, actual && isArgSeg(actual), "Call arguments must be variables defined in arg segment");

        validate(list, formal.type() == actual.type(),   "Incompatible types of formal and actual arguments");
        validate(list, formal.align() == actual.align(), "Incompatible alignment of formal and actual arguments");

        if (isArray(formal))  // may be either array or flexible array
        {
            validate(list, isArray(actual), "Actual parameter must be an array");
            validate(list, !isFlex(actual), "Actual array parameter must have fixed size");
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
        assert(section == BRIG_SEC_OPERANDS   ||
               section == BRIG_SEC_CODE       ||
               section == BRIG_SEC_DATA);

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
        case BRIG_SEC_OPERANDS:   msg = "hsa_operand"; break;
        case BRIG_SEC_CODE:       msg = "hsa_code";    break;
        case BRIG_SEC_DATA:       msg = "hsa_data";    break;
        default:
            assert(false);
            break;
        }

        validate(item, false, "Invalid offset to " + msg + " section: " + structName + "." + fieldName + " " + errMsg);
    }

    template<class T> void validate_BrigCodeOffset(T item, unsigned offset, const char* structName, const char* fieldName) const
    {
        bool z = OperandAddress(item);
        validateOffset(item, BRIG_SEC_CODE, offset, structName, "code", z, true); //F should it be 'false', 'false'?
    }

    template<class T> void validate_BrigOperandOffset(T item, unsigned offset, const char* structName, const char* fieldName) const
    {
        validateOffset(item, BRIG_SEC_OPERANDS, offset, structName, fieldName, true); //F should it be 'false'?
    }

    template<class T> void validate_BrigDataOffsetString(T item, unsigned offset, const char* structName, const char* fieldName) const
    {
        validateOffset(item, BRIG_SEC_DATA, offset, structName, fieldName);
    }

    void validate_BrigDataOffsetCodeList(Operand item, unsigned offset, const char* structName, const char* fieldName) const
    {
        validateOffset(item, BRIG_SEC_DATA, offset, structName, fieldName);
        validateList(item, offset, BRIG_SEC_CODE, structName, fieldName);
    }

    template<class T> void validate_BrigDataOffsetOperandList(T item, unsigned offset, const char* structName, const char* fieldName) const
    {
        validateOffset(item, BRIG_SEC_DATA, offset, structName, fieldName);
        validateList(item, offset, BRIG_SEC_OPERANDS, structName, fieldName);
    }

    template<class T> void validateList(T item, unsigned offset, unsigned section, const char* structName, const char* fieldName) const
    {
        uint32_t byteCount = getSectionData<uint32_t>(BRIG_SEC_DATA, offset);

        validate(item, (byteCount & 0x3) == 0, "Invalid array of offsets, size must be a multiple of 4");

        for (unsigned pos = offset + 4; pos <= offset + byteCount; pos += 4)
        {
            uint32_t elementOffset = getSectionData<uint32_t>(BRIG_SEC_DATA, pos);
            validateOffset(item, section, elementOffset, structName, fieldName);
            if (section == BRIG_SEC_CODE)
            {
                uint16_t id = getSectionData<uint16_t>(section, elementOffset + sizeof(uint16_t)); //F use struct
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

    void validate_BrigExecutableModifier(Directive item, Brig::BrigExecutableModifier val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned mod = val.allBits;
        unsigned mask = BRIG_EXECUTABLE_DEFINITION;

        validate(item, (mod & ~mask) == 0, "Invalid executable modifier value", mod);
    }

    void validate_BrigLinkage(Directive item, unsigned linkage, const char* structName, const char* fieldName) const
    {
        validate(item, linkage2str(linkage) != NULL, "Invalid linkage value", linkage);
    }

    void validate_BrigVariableModifier(Directive item, Brig::BrigVariableModifier val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned mod = val.allBits;
        unsigned mask = BRIG_SYMBOL_DEFINITION | BRIG_SYMBOL_CONST | BRIG_SYMBOL_ARRAY | BRIG_SYMBOL_FLEX_ARRAY;

        validate(item, (mod & ~mask) == 0, "Invalid variable modifier value", mod);
        validate(item, (mod & BRIG_SYMBOL_FLEX_ARRAY) == 0 || (mod & BRIG_SYMBOL_ARRAY) != 0, "Invalid variable modifier value ('flex' = 1, but 'array' = 0)", mod);
    }

    void validate_BrigAllocation(Directive item, unsigned allocation, const char* structName, const char* fieldName) const
    {
        validate(item, allocation2str(allocation) != NULL, "Invalid allocation value", allocation);
    }

    void validate_BrigAluModifier(Inst item, Brig::BrigAluModifier val, const char* structName, const char* fieldName) const
    {
        using namespace Brig;

        unsigned mod = val.allBits;
        validate(item, (mod & ~(BRIG_ALU_ROUND | BRIG_ALU_FTZ)) == 0, "Invalid ALU modifier value", mod);
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

    void validate_BrigControlDirective(Directive item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, controlDirective2str(val) != NULL, "Invalid control type value", val);
    }

    void validate_BrigImageChannelOrder(Operand item, unsigned val, const char* structName, const char* fieldName) const
    {
        const char* s = imageChannelOrder2str(val);
        validate(item, s != NULL , "Invalid image channel order value", val);
        validate(item, *s != 0,    "Unspecified image channel order");

        using namespace Brig;
        OperandImageProperties prop = item;
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

    void validate_BrigProfile(Directive item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, profile2str(val) != NULL, "Invalid version profile value", val);
    }

    void validate_BrigMachineModel(Directive item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, machineModel2str(val) != NULL, "Invalid machine model value", val);
    }

    void validate_BrigSamplerCoordNormalization(Operand item, Brig::BrigSamplerCoordNormalization8_t val, const char* structName, const char* fieldName) const
    {
        validate(item, samplerCoordNormalization2str(val) != NULL, "Invalid sampler coord value", val);

        // It is an error if unnormalized mode is specified with an addressing mode of repeat or mirrored_repeat.

        OperandSamplerProperties init = item;
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

    void validate_ImageDim(OperandImageProperties item, BrigUInt64 val, const char* name,  bool isPositive) const
    {
        uint64_t dim = (((uint64_t)val.hi) << 32) + val.lo;
        string geom = imageGeometry2str(item.geometry());
        const char* msg = isPositive? " must be positive" : " must be 0";
        validate(item, (dim > 0) == isPositive, "Invalid " + geom + " image initializer; " + name + msg);
    }

    void validate_fld_Width(OperandImageProperties item, BrigUInt64 val, const char* structName, const char* fieldName) const
    {
        validate_ImageDim(item, val, fieldName,  true);
    }

    void validate_fld_Height(OperandImageProperties item, BrigUInt64 val, const char* structName, const char* fieldName) const
    {
        unsigned geom = OperandImageProperties(item).geometry();
        validate_ImageDim(item, val, fieldName,
            geom == Brig::BRIG_GEOMETRY_2D      ||
            geom == Brig::BRIG_GEOMETRY_3D      ||
            geom == Brig::BRIG_GEOMETRY_2DA     ||
            geom == Brig::BRIG_GEOMETRY_2DDEPTH ||
            geom == Brig::BRIG_GEOMETRY_2DADEPTH);
    }

    void validate_fld_Depth(OperandImageProperties item, BrigUInt64 val, const char* structName, const char* fieldName) const
    {
        unsigned geom = OperandImageProperties(item).geometry();
        validate_ImageDim(item, val,  fieldName,  geom == Brig::BRIG_GEOMETRY_3D);
    }

    void validate_fld_Array(OperandImageProperties item, BrigUInt64 val, const char* structName, const char* fieldName) const
    {
        unsigned geom = OperandImageProperties(item).geometry();
        validate_ImageDim(item, val,  fieldName,
            geom == Brig::BRIG_GEOMETRY_1DA     ||
            geom == Brig::BRIG_GEOMETRY_2DA     ||
            geom == Brig::BRIG_GEOMETRY_2DADEPTH);
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

    void validate_fld_Line(Directive item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, val > 0, "Invalid loc directive, line number must be greater than 0");
    }

    void validate_fld_Column(Directive item, unsigned val, const char* structName, const char* fieldName) const
    {
        validate(item, val > 0, "Invalid loc directive, column number must be greater than 0");
    }

    //-------------------------------------------------------------------------
    // Low-level BRIG validation (functions used by autogenerated code)

    void validate_fld_Dim(Directive item, BrigUInt64 val, const char* structName, const char* fieldName) const {}         // Nothing to do
    void validate_fld_Offset(Operand item, BrigUInt64 val, const char* structName, const char* fieldName) const {}        // Nothing to do
    void validate_fld_EquivClass(Inst item, unsigned val, const char* structName, const char* fieldName) const {}         // Nothing to do
    void validate_fld_InArgCount(Directive item, unsigned val, const char* structName, const char* fieldName) const {}    // Nothing to do
    void validate_BrigVersion(Directive item, unsigned val, const char* structName, const char* fieldName) const {}       // Validated elsewhere
    void validate_fld_OutArgCount(Directive item, unsigned val, const char* structName, const char* fieldName) const {}   // Validated elsewhere
    void validate_fld_CodeBlockEntryCount(Directive item, unsigned val, const char* structName, const char* fieldName) const {} // Validated elsewhere
    void validate_fld_RegNum(Operand item, unsigned val, const char* structName, const char* fieldName) const {}          // Validated elsewhere

    //-------------------------------------------------------------------------
    // Access to Brig sections

    string getExpectedSectionName(int section) const
    {
        switch(section)
        {
        case BRIG_SEC_DATA:       return "hsa_data";
        case BRIG_SEC_CODE:       return "hsa_code";
        case BRIG_SEC_OPERANDS:   return "hsa_operand";
        default:                  return "";
        }
    }

    template<typename T>
    T getSectionData(int section, unsigned offset) const
    {
        assert(sizeof(T) <= 4);
        return *(reinterpret_cast<const T*>(getSectionAddr(section) + offset));
    }

    const char* getSectionAddr(int section) const
    {
        switch(section) //F access via module header
        {
        case BRIG_SEC_DATA:       return brig.strings().getData(0);
        case BRIG_SEC_CODE:       return brig.code().getData(0);
        case BRIG_SEC_OPERANDS:   return brig.operands().getData(0);
        default:
            assert(false);
            return 0;
        }
    }

    Brig::BrigSectionHeader* getSectionHeader(int section) const
    {
        return (Brig::BrigSectionHeader*)getSectionAddr(section);
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
        const char* name = reinterpret_cast<char*>(&getSectionHeader(section)->name);
        return SRef(name, name + len);
    }

    const SourceInfo* getSourceInfo(int section, unsigned offset) const
    {
        if (section == BRIG_SEC_CODE && offset > 0)
        {
            return brig.code().sourceInfo(offset);
        }
        else if (section == BRIG_SEC_OPERANDS && offset > 0)
        {
            return brig.operands().sourceInfo(offset);
        }
        return NULL;
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
        if (!cond) throw BrigFormatError(BRIG_SEC_CODE, c.brigOffset(), msg);
    }

    void validate(Operand opr, bool cond, SRef msg) const
    {
        assert(opr);
        if (!cond) throw BrigFormatError(BRIG_SEC_OPERANDS, opr.brigOffset(), msg);
    }

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

        if (disasmOnError)
        {
            Disassembler disasm(brig);

            if (section == BRIG_SEC_CODE && offset > 0) //F
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
            else if (section == BRIG_SEC_OPERANDS && offset > 0) //F
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

    bool isLargeModel()                   const { return mModel == Brig::BRIG_MACHINE_LARGE; }
    bool isTopLevelStatement(Directive d) const { return !isBodyOnly(d);     }
    bool isBodyStatement(Directive d)     const { return !isToplevelOnly(d); }

}; // class ValidatorImpl

// ============================================================================
// Low-level BRIG validation (autogenerated)

#include "HSAILBrigValidation_gen.hpp"

// ============================================================================
// Public Validator API

Validator::Validator(BrigContainer &c) { impl = new ValidatorImpl(c); }
Validator::~Validator()                { delete impl; }

bool   Validator::validate(bool disasmOnError /*= false*/) const { return impl->validate(disasmOnError); }
string Validator::getErrorMsg(istream *is)       const { return impl->getErrorMsg(is); }
int    Validator::getErrorCode()                 const { return impl->getErrorCode(); }

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


//F EXTENSIONS:
//F - BrigImageChannelType: Values 16 through 64 are available for extensions
//F - BrigImageGeometry: Values 6 through 255 are available for extensions
//F - BrigImageChannelOrder: Values 17 through 255 are available for extensions
//F - BrigSamplerAddressing: Values 5 through 255 are available for extensions.
//F - BrigSamplerCoordNormalization: Values 5 through 255 are available for extensions.
//F - BrigSamplerFilter: Values 2 through 63 are available for extensions
//F - BrigSegment: Values 9 through 16 are available for extensions
//F MISC:
//F - Src operand of stof and ftos can no longer be WAVESIZE

//F TODO
//F validate new flags such as isDecl (their correlation with other props) ::: create random BRIG tests on all combinations of flags
//F Improve errors reporting for "Invalid reference to label defined in another scope"

//F POSTPONED FEATURES
//F The s, d, and q registers in HSAIL share a single pool of resources.
//F add support of querysamplerboundary (added in April)

//F TEMPORARILY DISABLED FEATURES
//F - identifiers must not start with "__hsa" (currently, this check is disabled)
//F - addresses of 32-bit segments must have b32 type and 's' register, if any (currently, addresses may have both b32 and b64 type; both 's' and 'd' registers and allowed)
//F - images and samplers must be passed to operations in 'd' registers (currently, addresses are allowed as well)

//F MINOR PENDING FEATURES
//F - nop
//F - The s, d, and q registers in HSAIL share a single pool of resources.

//F MAJOR PENDING FEATURES
//F - constants conversions and validation (4.10.4 How Text Format Constants Are Converted to Bit String Constants)
//F - labeltargets (lack tests and checks in validator because of planned redesign)
//F - some requirements on control directives (e.g. "If multiple control directives are present in the kernel or the functions it calls, they must all have the same values")
//F - Support of GCN extension has not been tested yet
//F - validation of debug section + disasm
//F - for linkage we currently encode modifiers which are present in HSAIL (e.g. 'none' if there is no modifier specified). Instead, we should encode actual linkage (e.g. 'extern' if no modifiers specified)
//F - All operands are typed
//F - If the same symbol (variable, image, sampler, or function) is both declared and defined
//F   in the same compilation unit, all references to the symbol in the Brig representation
//F   must refer to the definition, even if the definition comes after the use. If there are
//F   multiple declarations and no definitions, then all uses must refer to the first declaration
//F   in lexical order
//F - profile-specific req


/////////////////////////
// TODO
//
// variable name namy be empty but for signatures only
//
//
// Add tests:
// - Flexible array in kernel args