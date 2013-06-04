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


// ============================================================================
// ============================================================================
//============================================================================
// Instruction Validator

namespace HSAIL_ASM {

//============================================================================

enum {
    BRIG_SEC_DIRECTIVES  = 0,
    BRIG_SEC_CODE        = 1,
    BRIG_SEC_OPERANDS    = 2,
    BRIG_SEC_DEBUG       = 3,
    BRIG_SEC_STRTAB      = 4,

    BRIG_NUM_SECTIONS    = 5,
    BRIG_NUM_BYTES_RESERVED = 4
};

//============================================================================
// Exceptions

class BrigFormatError
{
public:
    static const int ERRCODE_STD  = 100;
    static const int ERRCODE_INST = 101;

private:
    string msg;
    int errCode;
    int section;
    unsigned offset;

public:
    BrigFormatError() {}
    BrigFormatError(int sec, unsigned off, SRef s, int code = ERRCODE_STD) :
        section(sec), offset(off), msg(s.begin, s.end), errCode(code)
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

} // namespace HSAIL_ASM

//============================================================================
//============================================================================
//============================================================================

//F Make it a separate component

#include "generated/HSAILInstValidation_gen.hpp"

//============================================================================
//============================================================================
//============================================================================

namespace HSAIL_ASM {

struct BrigHelper
{
public: // Brig Object Kind Identification


    static bool isSbr(Directive d)
    {
        return DirectiveExecutable(d);
    }

    static bool isFunc(Directive d)
    {
        return DirectiveFunction(d);
    }

    static bool isProto(Directive d)
    {
        return DirectiveSignature(d);
    }

    static bool isKernel(Directive d)
    {
        return DirectiveKernel(d);
    }

    static bool isSym(Directive d)
    {
        return DirectiveSymbol(d); // variable, image or a sampler
    }

    static bool isFbar(Directive d)
    {
        return DirectiveFbarrier(d);
    }

    static bool isLabel(Directive d)
    {
        return DirectiveLabel(d);
    }

    static unsigned getKind(Directive d) //F: merge with similar code using templates
    {
        return d.brig()->kind;
    }

public: // Brig Object Properties

    static unsigned getKind(Operand opr)
    {
        return opr.brig()->kind;
    }

    static SRef getName(Directive d)
    {
        if      (DirectiveExecutable dn = d) return dn.name();
        else if (DirectiveSymbol     dn = d) return dn.name();
        else if (DirectiveLabel      dn = d) return dn.name();
        else if (DirectiveSignature  dn = d) return dn.name();
        else if (DirectiveFbarrier   dn = d) return dn.name();

        assert(false);
        return SRef();
    }

    static char getNamePref(Directive d)
    {
        string name = getName(d);
        return name[0];
    }

    static unsigned getDataType(Directive d)
    {
        assert(d);
        if      (DirectiveSymbol       sym  = d) return sym.type();
        else if (DirectiveVariableInit init = d) return sym.type();

        assert(false);
        return 0;
    }

    static unsigned getSegment(Inst inst)
    {
        return HSAIL_ASM::getSegment(inst);
    }

    static unsigned getSegment(Operand opr)
    {
        assert(opr);

        if (OperandAddress addr = opr)
        {
            if (addr.symbol()) return getSegment(addr.symbol());
        }
        assert(false);
        return (unsigned)-1;
    }

    static unsigned getSegment(Directive d)
    {
        if (DirectiveSymbol sym = d) return sym.segment();
        else if (isFbar(d))          return Brig::BRIG_SEGMENT_GROUP;

        assert(false);
        return (unsigned)-1;
    }

    static bool isArgSeg(Directive d) {
        assert(isSym(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_ARG;
    }

    static bool isKernArgSeg(Directive d) {
        assert(isSym(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_KERNARG;
    }

    static bool isSpillSeg(Directive d) {
        assert(isSym(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_SPILL;
    }

    static bool isGlobalSeg(Directive d) {
        assert(isSym(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_GLOBAL;
    }

    static bool isGroupSeg(Directive d) {
        assert(isSym(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_GROUP;
    }

    static bool isPrivateSeg(Directive d) {
        assert(isSym(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_PRIVATE;
    }

    static bool isReadonlySeg(Directive d) {
        assert(isSym(d) || isFbar(d));
        return getSegment(d) == Brig::BRIG_SEGMENT_READONLY;
    }

    static unsigned getSymLinkage(Directive d)
    {
        // TBD: Do signatures and fbarriers have static linkage? Assime it for now
        // This is necessary to process signatures and fbarriers just like other symbols

        if      (DirectiveSymbol     ds = d) return ds.modifier().linkage();
        else if (DirectiveExecutable ds = d) return ds.modifier().linkage();
        else if (isProto(d) || isFbar(d))    return Brig::BRIG_LINKAGE_STATIC; // this is to process signatures and fbarriers just like other symbols
        return Brig::BRIG_LINKAGE_NONE;
    }

    static bool isExtern(Directive d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_EXTERN;
    }

    static bool isStatic(Directive d)
    {
        return getSymLinkage(d) == Brig::BRIG_LINKAGE_STATIC;
    }

    static bool isDecl(Directive d)
    {
        if      (DirectiveSymbol     ds = d) return ds.modifier().isDeclaration();
        else if (DirectiveExecutable ds = d) return ds.modifier().isDeclaration();
        else if (DirectiveSignature  ds = d) return true;
        else if (DirectiveFbarrier   ds = d) return false;

        assert(false);
        return false;
    }

    static bool isDef(Directive d)
    {
        return !isDecl(d);
    }

    static uint64_t getArraySize(Directive d)
    {
        if (DirectiveSymbol sym = d) return sym.dim();
        assert(false);
        return 0;
    }

    static unsigned getAlignment(Directive d)
    {
        assert(isSym(d));
        if (DirectiveSymbol sym = d) return sym.align();
        assert(false);
        return 0;
    }

    static unsigned getNaturalAlignment(unsigned type)
    {
        assert(HSAIL_ASM::typeX2str(type));
        switch(getTypeSize(type))
        {
        case 16:  return 2;
        case 32:  return 4;
        case 64:  return 8;
        case 128: return 16;
        default:  return 1;
        }
    }

    static unsigned getPhysicalAlignment(unsigned type, unsigned align)
    {
        assert(align == 0 || align == 1 || align >= getNaturalAlignment(type));
        return (align == 0)? getNaturalAlignment(type) : align;
    }

    static unsigned getPhysicalAlignment(Directive d)
    {
        assert(isSym(d));
        return getPhysicalAlignment(getDataType(d), getAlignment(d));
    }

    bool checkAlign(unsigned align, unsigned type) const
    {
        return align == 0 || getNaturalAlignment(type) <= align;
    }

    static bool isConst(Directive d)
    {
        if (DirectiveSymbol sym = d) return sym.modifier().isConst();
        assert(false);
        return false;
    }

    static bool isArray(Directive d)
    {
        if (DirectiveSymbol sym = d) return sym.modifier().isArray();
        assert(false);
        return false;
    }

    static bool isFlex(Directive d)
    {
        if (DirectiveSymbol sym = d) return sym.modifier().isFlexArray();
        assert(false);
        return false;
    }

    static bool isInitialized(Directive d)
    {
        if (DirectiveSymbol sym = d) return sym.init();
        return false;
    }

    static Directive getInitializer(Directive d)
    {
        assert(isSym(d));

        if (DirectiveSymbol sym = d) return sym.init();
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

    static Directive getFirstInParam(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.firstInArg();

        assert(false);
        return Directive();
    }

    static Directive getFirstOutParam(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.next();

        assert(false);
        return Directive();
    }

    static unsigned getOperationNum(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.instCount();

        assert(false);
        return 0;
    }

    static Directive getFirstScoped(Directive d)
    {
    	if (DirectiveExecutable dfc = d) return dfc.firstScopedDirective();

        assert(false);
        return d.next();
    }

    static Directive getNextTopLevel(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.nextTopLevelDirective();

        assert(false);
        return d.next();
    }

    static Inst getFirstOperation(Directive d)
    {
        if (DirectiveExecutable exec = d) return exec.code();

        assert(false);
        return Inst();
    }

    static bool isGcnInst(Inst inst)
    {
        assert(inst);
        return HSAIL_ASM::isGcnInst(inst.opcode());
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

    enum State {
        STATE_PRG_SCOPE,    // Program (global) scope
        STATE_SBR_SCOPE,    // Subroutine (Kernel/Function) scope
        STATE_ARG_SCOPE     // Argument scope
    };

private:
    BrigContainer &brig;        // BRIG container being validated
    const bool isLinkedCode;    // True when called for validation of linked code

private: // Context state
    State    state;     // context state: program/sbr/block scope
    bool     isBlock;   // true while processing block directives; false otherwise
    unsigned callsNum;  // number of call instructions in the current code block

private: // File id
    set<unsigned> fileIds; // Registered file ids

    // Labels may be defined in two places:
    // - in an argument block.
    //   These labels may be used ONLY by directives and code of this block.
    // - in func/kernel body, but outside of argument blocks.
    //   These labels may be used ONLY by directives and code outside of argument blocks.
    // A weird thing is both kinds of labels share a single namespace, so
    // a label with the same name cannot be defined both inside and outside of an argument block.
    // Consequently, there is only one 'labelNames'
private:
    set<Offset> blkLabelsDef;   // d-offset of visible blk-scope label definition
    set<Offset> blkLabelsUse;   // d-offset of visible blk-scope label definition set at first FORWARD reference
    set<Offset> sbrLabelsDef;   // d-offset of visible sbr-scope label definition
    set<Offset> sbrLabelsUse;   // d-offset of visible sbr-scope label definition set at first FORWARD reference
    NameSet     labelNames;     // names of all labels in the current func/kernel

    // These two sets are used for validation of 'call' arguments:
    // - to ensure that input call args are not used as output args abd vice versa
    // - to ensure that input call args are not accessed after the call
private:
    set<Offset> inputArgs;      // d-offset of input call args
    set<Offset> outputArgs;     // d-offset of output call args

private: // Local variables (sbr-scoped and blk-scoped)
         // !NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!
         // !NB!NB!NB! non-arg variables defined in an arg scope logically belong to both
         // !NB!NB!NB! arg scope and sbr scope, so these variables are added to BOTH lists
         // !NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!NB!
    set<Offset> blkVarDefs;     // d-offsets of visible blk-scoped symbols, includes non-arg variables defined in arg scope
    set<Offset> sbrVarDefs;     // d-offsets of visible sbr-scoped symbols, includes non-arg variables defined in arg scope
    NameSet     blkVarNames;    // names of visible blk-scoped symbols, includes non-arg variables defined in arg scope (searched before sbr-scoped symbols)
    NameSet     sbrVarNames;    // names of visible sbr-scoped symbols, includes non-arg variables defined in arg scope

private: // Global (program-scope) identifiers (variables, functions, kernels)
    set<Offset> prgSymDefs;     // d-offsets of visible symbols
    NameSet     prgSymUsed;     // names of functions used by program (to check that used static fns are defined)
    NameMap     prgSymDesc;     // pairs [name, directive]

private: // Externally-visible identifiers (variables, functions, kernels)
    NameMap     extSymDesc;     // pairs [name, directive]

private:
    ValidatorContext(const ValidatorContext&); // non-copyable
    const ValidatorContext &operator=(const ValidatorContext &);  // not assignable

public:
    //-------------------------------------------------------------------------
    // PUBLIC API TO CONTROL AND SWITCH PROGRAM CONTEXT
    //-------------------------------------------------------------------------

    ValidatorContext(BrigContainer &c, const bool mode_linked)
        : brig(c), isLinkedCode(mode_linked), state(STATE_PRG_SCOPE), callsNum(0), isBlock(false)
    {}

    void startProgram()
    {
        assert(isPrgScope());
    }

    void endProgram()
    {
        assert(isPrgScope());
        validateStaticDefs(); // NB: must go first!
        clearSymbols();
        clearFileIds();
    }

    void startSbr(Directive d)
    {
        assert(isPrgScope());
        state = STATE_SBR_SCOPE;

        Directive arg = d.next();
        for (unsigned argsNum = getParamNum(d); argsNum > 0; --argsNum) {
            assert(arg);
            defineVar(arg, true, isKernel(d));
            arg = arg.next();
        }
    }

    void endSbr()
    {
        assert(isSbrScope());
        validateLabels();
        clearLabels();
        clearSymbols();
        state = STATE_PRG_SCOPE;
    }

    void startCodeBlock()
    {
        assert(isSbrScope());

        state = STATE_ARG_SCOPE;
        callsNum = 0;
    }

    void endCodeBlock()
    {
        assert(isArgScope());

        validateLabels();
        clearLabels();
        clearSymbols();
        clearArgs();
        state = STATE_SBR_SCOPE;
    }

    void startCall(Inst i)
    {
        assert(isArgScope());
        validate(i, callsNum == 0, "Code block must not include more than one call operation");
    }

    void endCall(Inst i)
    {
        assert(isArgScope());
        ++callsNum;
    }

    void startBlockSection() { assert(!isBlock); isBlock = true; }
    void endBlockSection()   { assert(isBlock);  isBlock = false; }
    bool isBlockSection()    { return isBlock; }

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
    void checkLabelUse(DirectiveLabel lab)
    {
        assert(lab);

        if (!isLabelDefined(lab))
        {
            setForwLabelRef(lab);
        }
    }

    void defineVar(Directive d, bool isArgument = false, bool isKernelArgument = false)
    {
        assert(isSym(d) || isFbar(d));

        if (isKernArgSeg(d))
        {
            validate(d, isKernelArgument,
                     "Kernarg segment variables must be defined as kernel parameters");
        }
        else if (isArgSeg(d))
        {
            validate(d, isArgument || isArgScope(),
                     "Arg segment variables must be defined as function parameters or in an arg scope");
        }

        if (getNamePref(d) == '%')
        {
            addLocalSym(d, isArgument);
        }
        else
        {
            addGlobalSym(d);
        }
    }

    void checkVarUse(Operand opr, Directive d)
    {
        assert(isSym(d) || isFbar(d));

        checkSymUse(opr, d);

        if (isArgScope() && callsNum > 0) // Validate use of arguments after the call
        {
            validate(opr, inputArgs.count(d.brigOffset()) == 0, "Input arguments cannot be used after the call");
        }
    }

    bool isTransientArg(Directive d) // True for arg variables defined inside an arg scope
    {
        assert(isSym(d));
        Offset off = d.brigOffset();
        return isArgSeg(d) && blkVarDefs.count(off) > 0; // NB: blkVarDefs includes ALL variables defined in arg scope (not only arguments)
    }

    void registerArg(Inst inst, Directive arg, bool isOutArgs)
    {
        Offset off = arg.brigOffset();

        set<Offset> &current = isOutArgs? outputArgs : inputArgs;
        set<Offset> &another = isOutArgs? inputArgs : outputArgs;

        validate(inst, isTransientArg(arg), "Call arguments must be defined in arg scope");
        validate(arg, another.count(off) == 0, "Variable cannot be used as both an input and an output argument");
        current.insert(off);
    }

    void defineSbr(Directive d)
    {
        assert(d);
        assert(isPrgScope());
        addGlobalSym(d);
    }

    void checkSbrUse(Operand opr, DirectiveFunction f)
    {
        assert(f);
        checkSymUse(opr, f);
    }

    void markFuncUsed(DirectiveFunction d)
    {
        assert(d);
        prgSymUsed.insert(getName(d));
    }

    void defineProto(Directive d)
    {
        assert(d);
        assert(isPrgScope());
        addGlobalSym(d);
    }

    void checkProtoUse(Operand opr, DirectiveSignature f)
    {
        assert(f);
        checkSymUse(opr, f);
    }

public:
    bool isPrgScope() const { return state == STATE_PRG_SCOPE; }
    bool isSbrScope() const { return state == STATE_SBR_SCOPE; }
    bool isArgScope() const { return state == STATE_ARG_SCOPE; }

public:
    bool registerFileId(unsigned id)
    {
        if (fileIds.count(id) != 0) return false;
        fileIds.insert(id);
        return true;
    }

    bool checkFileId(unsigned id)
    {
        return fileIds.count(id) != 0;
    }

    void clearFileIds()
    {
        fileIds.clear();
    }

private:
    //-------------------------------------------------------------------------
    // Implementation: LABELS
    //-------------------------------------------------------------------------

    set<Offset>& getLabelDefs()
    {
        return isArgScope()? blkLabelsDef : sbrLabelsDef;
    }

    set<Offset>& getLabelUses()
    {
        return isArgScope()? blkLabelsUse : sbrLabelsUse;
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

    void setForwLabelRef(DirectiveLabel lab)
    {
        assert(!isLabelDefined(lab));
        getLabelUses().insert(lab.brigOffset());
    }

    void validateLabels()
    {
        set<Offset> &defs = getLabelDefs();
        set<Offset> &uses = getLabelUses();

        for (set<Offset>::iterator it = uses.begin(); it != uses.end(); ++it)
        {
            //F: should refer invalid instruction rather than the label itself
            validate(Directive(&brig, *it), defs.count(*it) > 0,
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
            std::cerr << "    " << lab.name() << " = &(" << lab.code().brigOffset() << ")\n";
        }
        std::cerr << "\n";
    }

private:
    //-------------------------------------------------------------------------
    // Implementation: VARIABLES, FUNCTIONS, KERNELS
    //-------------------------------------------------------------------------

    void addLocalSym(Directive d, bool isArgument)
    {
        assert(isSym(d) || isFbar(d));

        validate(d, isSbrScope() || isArgScope(),
                 "Variables starting with '%' must be defined in kernels or functions");

        if (isArgScope()) // Add BOTH arg and non-arg variables
        {
            validate(d, blkVarNames.count(getName(d)) == 0, "Variable redefinition");
            blkVarDefs.insert(d.brigOffset());
            blkVarNames.insert(getName(d));
        }

        // NB: non-arg variables defined in an arg scope logically belong to both
        //     arg scope and sbr scope, so these variables are added to BOTH lists

        if (isArgument || !isArgSeg(d)) // Add all variables except for args defined in arg scope
        {
            validate(d, sbrVarNames.count(getName(d)) == 0, SRef(isArgument? "Duplicate argument declaration" : "Variable redefinition"));
            sbrVarDefs.insert(d.brigOffset());
            sbrVarNames.insert(getName(d));
        }
    }

    void addGlobalSym(Directive d)
    {
        assert(isSym(d) || isFbar(d) || isSbr(d) || isProto(d));

        validate(d, isPrgScope(),
                 "Identifiers starting with '&' must be defined outside of kernels and functions");

        validateDecl(d, prgSymDesc);

        prgSymDefs.insert(d.brigOffset());

        // Special handling for identifiers visible in other compilation units
        if (!isStatic(d)) // Might be a kernel
        {
            validateDecl(d, extSymDesc);
        }
    }

    void validateDecl(Directive d, NameMap &desc)
    {
        assert(isSym(d) || isFbar(d) || isSbr(d) || isProto(d));

        if (desc.count(getName(d)) == 0)
        {
            // This is the first definition/declaration
            desc[getName(d)] = d;
        }
        else // This must be a redefinition of the same entity
        {
            Directive prev = desc[getName(d)];

            validate(d, getKind(d) == getKind(prev),
                     "Invalid identifier redefinition");

            // There may be only one definition
            validate(d, isDecl(d) || isDecl(prev),
                     "Invalid identifier redefinition");

            // validate that both decl are identical
            validate(d, eqDecl(d, prev),
                     "Invalid identifier redefinition");

            if (isDef(d))
            {
                desc[getName(d)] = d; // Replace declaration with definition
            }
        }
    }

    void checkSymUse(Operand opr, Directive d)
    {
        assert(isSym(d) || isFbar(d) || isFunc(d) || isProto(d));

        Offset off = d.brigOffset();

//std::cerr << "Offset = " << off << "\n";

        if (isLinkedCode && getNamePref(d) == '&' && prgSymDefs.count(off) == 0 && !isProto(d) && !isFbar(d))
        {
            // This is a special case because linked code may refer another program.
            // In this case validate the following conditions:
            // 1. This is a definition of a symbol;
            // 2. There is a declaration of a symbol with the same name visible in the current scope;
            // 3. Definition and declaration are compatible

            validate(opr, isDef(d), "Invalid linked reference to declaration");
            validate(opr, prgSymDesc.count(getName(d)) > 0 && isDecl(prgSymDesc[getName(d)]), "Linked reference to symbol without declaration");
            validate(opr, eqDecl(d, prgSymDesc[getName(d)]), "Linked symbol definition is incompatible with declaration");
            return;
        }

        validate(opr, blkVarDefs.count(off) > 0 ||
                      sbrVarDefs.count(off) > 0 ||
                      prgSymDefs.count(off) > 0,
                      "Identifier is not defined/declared or is not visible in the current scope");


        // If there are 2 symbols with the same name, one defined outside of an arg block,
        // and another inside the block, the latter hides the former and the latter
        // should be used for all references to that name in the arg block.
        // Improvement should look like this:
        if (isArgScope() && blkVarNames.count(getName(d)) > 0)
        {
            validate(opr, blkVarDefs.count(off) > 0, "Invalid reference to symbol hidden in arg scope by an argument");
        }
    }

    bool eqDecl(Directive d1, Directive d2)
    {
        assert(getKind(d1) == getKind(d2));

        if (isSym(d1)) {
            return eqSymDecl(d1, d2);
        } else if (isSbr(d1)) {
            return eqSbrDecl(d1, d2);
        } else if (isProto(d1)) {
            return eqProto(d1, d2);
        } else {
            assert(false);
            return false;
        }
    }

    // static declarations are compatible only with static declarations and definitions
    // non-static declarations are compatible only with non-static declarations and definitions
    // extern declarations are compatible only with extern declarations (this is checked elsewhere)
    bool eqSbrDecl(Directive sbr1, Directive sbr2)
    {
        // Check only 'static' attribute ('extern' and 'none' are compatible)
        if (isStatic(sbr1) != isStatic(sbr2)) return false;

        if (getInParamNum(sbr1)  == getInParamNum(sbr2) &&
            getOutParamNum(sbr1) == getOutParamNum(sbr2))
        {
            Directive arg1 = sbr1.next();
            Directive arg2 = sbr2.next();

            for (unsigned i = getParamNum(sbr1); i > 0; --i)
            {
                if (!eqSymDecl(arg1, arg2)) return false;

                arg1 = arg1.next();
                arg2 = arg2.next();
            }
            return true;
        }
        return false;
    }

    bool eqAlignment(Directive arg1, Directive arg2) const
    {
        return (getPhysicalAlignment(arg1) == getPhysicalAlignment(arg2));
    }

    bool eqSymDecl(Directive arg1, Directive arg2) const
    {
        // Check only 'static' attribute ('extern' and 'none' are compatible)
        if (isStatic(arg1) != isStatic(arg2)) return false;

        if (getKind(arg1)     != getKind(arg2)     ||
            getSegment(arg1)  != getSegment(arg2)  ||
            getDataType(arg1) != getDataType(arg2) ||
            !eqAlignment(arg1, arg2)) return false;

        if (isFlex(arg1) != isFlex(arg2)) return false;

        if (isConst(arg1) != isConst(arg2) ||
            isArray(arg1) != isArray(arg2))
            return false;

        if (isArray(arg1) && !isArgSeg(arg1) && !isKernArgSeg(arg1))
        {
            // Special rules for non-argument arrays. Specification states:
            //     "If the object is an array, the size of the array must be specified
            //      in the definition but can be omitted in the declaration."
            // This rule does not apply to symbols declared/defined in Arg/Kernarg segments
            return getArraySize(arg1) == 0 ||
                   getArraySize(arg2) == 0 ||
                   getArraySize(arg1) == getArraySize(arg2);
        }

        // for arguments and non-arrays, arg1.dim must be the same as arg2.dim

        return getArraySize(arg1) == getArraySize(arg2);

        // NB: other attributes are irrelevant (for declarations)
    }

    bool eqProto(DirectiveSignature p1, DirectiveSignature p2)
    {
        if (p1.outCount() != p2.outCount()) return false;
        if (p1.inCount()  != p2.inCount())  return false;

        unsigned len = p1.outCount() + p1.inCount();

        for (unsigned i = 0; i < len; ++i)
        {
            if (p1.args(i).type() != p2.args(i).type()) return false;
            if (p1.args(i).modifier().allBits() != p2.args(i).modifier().allBits()) return false;
            if (p1.args(i).modifier().isArray() && p1.args(i).dim() != p2.args(i).dim()) return false;
            if (getPhysicalAlignment(p1.args(i).type(), p1.args(i).align()) !=
                getPhysicalAlignment(p2.args(i).type(), p2.args(i).align())) return false;
        }

        return true;
    }

    void validateStaticDefs()
    {
        // Static function must be defined if it is used
        NameMap::iterator it = prgSymDesc.begin();
        for (; it != prgSymDesc.end(); ++it)
        {
            if (DirectiveFunction f = it->second)
            {
                if (!isDef(f) && isStatic(f))
                {
                    validate(f, prgSymUsed.count(getName(f)) == 0, "Undefined static function");
                }
            }
        }
    }

    void clearSymbols()
    {
        clearSymDefs();
        clearSymNames();
    }

    void clearArgs()
    {
        inputArgs.clear();
        outputArgs.clear();
    }

    void clearSymDefs()
    {
        if (isArgScope())      blkVarDefs.clear();
        else if (isSbrScope()) sbrVarDefs.clear();
        else                   prgSymDefs.clear();
    }

    void clearSymNames()
    {
        if (isArgScope())      blkVarNames.clear();
        else if (isSbrScope()) sbrVarNames.clear();
        else
        {
            prgSymDesc.clear();
            prgSymUsed.clear();
        }
    }

private:
    void validate(Directive d, bool cond, SRef msg) const
    {
        if (!cond) throw BrigFormatError(BRIG_SEC_DIRECTIVES, d.brigOffset(), msg);
    }

    void validate(Operand opr, bool cond, SRef msg) const
    {
        if (!cond) throw BrigFormatError(BRIG_SEC_OPERANDS, opr.brigOffset(), msg);
    }

    void validate(Inst inst, bool cond, SRef msg) const
    {
        if (!cond) throw BrigFormatError(BRIG_SEC_CODE, inst.brigOffset(), msg);
    }
};

//=============================================================================

class DirectivesRange {
private:
    Inst currentInst;
    unsigned remainingInst;
    Directive currentDir;
    Directive sentinelDir;

public:
    DirectivesRange(Directive dStart, Directive dEnd, Inst code, unsigned iNum) :
                   currentInst(code), remainingInst(iNum), currentDir(dStart), sentinelDir(dEnd)
    {
        assert(dStart);
        assert(dEnd);
    }

    bool empty()
    {
        return dirEnded() && remainingInst == 0;
    }

    Inst getNextInst()
    {
        Inst res;
        if (remainingInst > 0 && (dirEnded() || getDirectiveCode() > currentInst.brigOffset()))
        {
            --remainingInst;
            res = currentInst;
            currentInst = currentInst.next();
        }
        return res;
    }

    Directive peekNextDirective()
    {
        if (dirEnded() || (remainingInst > 0 && getDirectiveCode() > currentInst.brigOffset())) return Directive();
        return getDirective();
    }

    Directive getNextDirective()
    {
        Directive res = peekNextDirective();
        if (res) currentDir = currentDir.next();
        return res;
    }

    bool isTrailingDirective() // True if code block ends with a directive
    {
        return remainingInst == 0;
    }

private:
    Directive getDirective()
    {
        if (dirEnded()) return Directive();
        return currentDir;
    }

    Offset getDirectiveCode()
    {
        DirectiveCode dc = getDirective();
        return dc? dc.code().brigOffset() : 0;
    }

    bool dirEnded()  { return currentDir.brigOffset() == sentinelDir.brigOffset(); }
};

//=============================================================================

static const char* ALPHA    = "_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const char* ALPHANUM = "_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

class ValidatorImpl : public BrigHelper
{
private:
    BrigContainer &brig;
    vector<unsigned> map[BRIG_NUM_SECTIONS];
    set<Offset> usedInst;

    unsigned machineModel;
    unsigned profile;
    unsigned major;
    unsigned minor;

    mutable BrigFormatError err;

    static const int AVR_ITEM_SIZE = 32; //F: customize for each section

public:
    //-------------------------------------------------------------------------
    // Public API Implementation

    ValidatorImpl(BrigContainer &c) : brig(c), machineModel(Brig::BRIG_MACHINE_LARGE) {}

    bool validate(const Validator::ValidationMode vMode)
    {
        try
        {
            // Low-level validation
            validateBrigFormat();
            validateBrigFields();

            // High-level validation
            initBrigVersion();

            validateBrigItems();
            validateBrigDefs(vMode);
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
            printError(s,*is,srcLoc,err.what());
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
        validateStringSection();

        validateSection(BRIG_SEC_DIRECTIVES);
        validateSection(BRIG_SEC_CODE);
        validateSection(BRIG_SEC_OPERANDS);
    }

    //-------------------------------------------------------------------------
    // Validation of individual item fields

    void validateBrigFields() const
    {
        for(Directive d = brig.directives().begin();
            d != brig.directives().end();
            d = d.next())
        {
            ValidateDirectiveFields(d);
        }

        for(Inst i = brig.insts().begin();
            i != brig.insts().end();
            i = i.next())
        {
            ValidateInstFields(i);
        }

        for(Operand o = brig.operands().begin();
            o != brig.operands().end();
            o = o.next())
        {
            ValidateOperandFields(o);
        }
    }

    //-------------------------------------------------------------------------
    // Validation of version directive

    void initBrigVersion()
    {
        Directive d = brig.directives().begin();
        DirectiveVersion v = d;
        validate(d, v, "Program must start with Version directive");

        major        = v.hsailMajor();
        minor        = v.hsailMinor();
        machineModel = v.machineModel();
        profile      = v.profile();

        validate(d, major         == Brig::BRIG_VERSION_HSAIL_MAJOR, "Unsupported major HSAIL version");
        validate(d, minor         <= Brig::BRIG_VERSION_HSAIL_MINOR, "Unsupported minor HSAIL version");
        validate(d, v.brigMajor() == Brig::BRIG_VERSION_BRIG_MAJOR,  "Unsupported major BRIG version");
        validate(d, v.brigMinor() <= Brig::BRIG_VERSION_BRIG_MINOR,  "Unsupported minor BRIG version");
    }

    void validateBrigVersion(DirectiveVersion v) const
    {
        // TBD: Spec is contradictory about minor hsail versions, but I believe the following check is sane.
        validate(v, v.hsailMinor() <= Brig::BRIG_VERSION_HSAIL_MINOR, "Unsupported minor HSAIL version");

        validate(v, major == v.hsailMajor(), "Version statements have incompatible major numbers");
        validate(v, machineModel == v.machineModel(), "Version statements have incompatible machine models");
        validate(v, profile == v.profile(), "Version statements have incompatible profiles");
    }

    //-------------------------------------------------------------------------
    // Validation of dependencies between item fields

    void validateBrigItems()
    {
        InstValidator instValidator(getMachineType());

        validateDirectivesOrder();

        for(Directive d = brig.directives().begin();
            d != brig.directives().end();
            d = d.next())
        {
            validateDirective(d);
        }

        for(Operand o = brig.operands().begin();
            o != brig.operands().end();
            o = o.next())
        {
            validateOperand(o);
        }

        for(Inst i = brig.insts().begin();
            i != brig.insts().end();
            i = i.next())
        {
            instValidator.validateInst(i);
            validateComplexInst(i);
        }
    }

    //-------------------------------------------------------------------------
    // Validation of definitions and declarations
    // NB: the code below should register all def/uses of HSAIL symbols
    //     in accordance with ValidatorContext requirements

    void validateExtension(DirectiveExtension ext, DirectiveExtension lastExt) const
    {
        if (ext.name() == "CORE")
        {
            validate(ext, !lastExt || ext.name() == lastExt.name(), "'CORE' extension is incompatible with any other extension");
        }
        else
        {
            validate(ext, !lastExt || lastExt.name() != "CORE", "No extensions are compatible with 'CORE' extension");
        }
    }

    void validateBrigDefs(const Validator::ValidationMode vMode) const
    {
        ValidatorContext context(brig, vMode == Validator::VM_BrigLinked);

        bool defStart = false;
        DirectiveExtension lastExt;
        Directive end = brig.directives().end();
        for (Directive d = brig.directives().begin(); d != end; )
        {
            Directive next = d.next();
            defStart |= isSym(d) | isSbr(d) | isProto(d) | isFbar(d);

            validate(d, isTopLevelStatement(d), "Directive is not allowed at top level");

            validateBlockSections(d, context);

            if (isSbr(d))
            {
                validateSbr(d, context);
                next = getNextTopLevel(d);
            }
            else if (DirectiveVersion dv = d)
            {
                if (d != brig.directives().begin())
                {
                    context.endProgram();
                    validateBrigVersion(dv);
                }
                context.startProgram();
                lastExt = DirectiveExtension();
                defStart = false;

                //F enable GCN instructions iif 'gcn' extension is specified
            }
            else if (DirectiveExtension ext = d)
            {
                validate(ext, !defStart, "Extension directive(s) must appear after version directive but before first definition or declaration");
                validateExtension(ext, lastExt);
                lastExt = ext;
            }
            else
            {
                validateDef(d, context);
            }

            d = next;
        }
        context.endProgram();
    }

    void validateSbr(Directive d, ValidatorContext &context) const
    {
        bool unreachableCode = false;

        context.defineSbr(d);
        context.startSbr(d); // Define arguments

        // Scan body
        DirectivesRange range(getFirstScoped(d), getNextTopLevel(d), getFirstOperation(d), getOperationNum(d));

        while (!range.empty())
        {
            while (Directive scoped = range.getNextDirective())
            {
                if (DirectiveLabel(scoped)) unreachableCode = false;

                validateBlockSections(scoped, context);

                if (DirectiveArgScopeStart ds = scoped)
                {
                    validate(ds, !context.isArgScope(), "Nested argument scope is not allowed");
                    context.startCodeBlock();
                }
                else if (DirectiveArgScopeEnd de = scoped)
                {
                    validate(scoped, context.isArgScope(), "Unpaired argument scope brackets");
                    context.endCodeBlock();
                }
                else
                {
                    if (DirectiveLabel(scoped)) validate(scoped, !range.isTrailingDirective(), "Trailing labels are not allowed");
                    validateDef(scoped, context);
                }
            }
            while (Inst i = range.getNextInst())
            {
                //F: checks for unreachable code are incomplete.
                //F: check that labels are really used as jump targets
                validate(i, !unreachableCode, "Unreachable code");

                for (unsigned idx = 0; idx < 5; ++idx)
                {
                    Operand opr = i.operand(idx);
                    if (opr) validateUse(opr, context);
                }

                // NB: ORDER IS IMPORTANT!
                // NB: validate instructions after arguments (important for calls)
                validateSpecInst(i, context);

                // Set flag indicating if next instruction is unreachable
                unreachableCode = (i.opcode() == Brig::BRIG_OPCODE_BRN || i.opcode() == Brig::BRIG_OPCODE_RET);
            }
        }
        context.endSbr();
    }

    void validateDef(Directive d, ValidatorContext &context) const
    {
        if (isLabel(d))
        {
            context.defineLabel(d);
        }
        else if (isSym(d) || DirectiveFbarrier(d))
        {
            context.defineVar(d);
        }
        else if (DirectiveSignature(d))
        {
            context.defineProto(d);
        }
        else if (DirectiveFile(d))
        {
            validate(d, context.registerFileId(DirectiveFile(d).fileid()), "File id must be unique");
        }
        else if (DirectiveLoc(d))
        {
            validate(d, context.checkFileId(DirectiveLoc(d).fileid()), "DirectiveLoc refers undefined file id");
        }
        else if (DirectiveLabelList(d))
        {
            /*
            DirectiveLabelList list = d;

            for (unsigned i = 0; i < list.elementCount(); ++i)
            {
                DirectiveLabel lab = list.labels(i);
                context.checkLabelUse(lab);
            }
            */
        }
    }

    void validateUse(Operand opr, ValidatorContext &context) const
    {
        switch (getKind(opr))
        {
        case Brig::BRIG_OPERAND_LABEL_REF:
            {
                Directive d = OperandLabelRef(opr).ref();
                if (DirectiveLabel lab = d)
                {
                    context.checkLabelUse(lab);
                }
                else if (DirectiveLabelTargets targets = d)
                {
                    unsigned len = targets.elementCount();
                    for (unsigned i = 0; i < len; ++i)
                    {
                        context.checkLabelUse(targets.labels(i));
                    }
                }
                else
                {
                    assert(false);
                }
            }
            break;

        case Brig::BRIG_OPERAND_ADDRESS:
            if (OperandAddress(opr).symbol())
            {
                context.checkVarUse(opr, OperandAddress(opr).symbol());
            }
            break;

        case Brig::BRIG_OPERAND_ARGUMENT_REF:
            //context.checkVarUse(opr, OperandArgumentRef(opr).arg());
            assert(false);
            break;

        case Brig::BRIG_OPERAND_FUNCTION_REF:
            {
                Directive d = OperandFunctionRef(opr).ref();
                assert(isFunc(d));
                context.checkSbrUse(opr, d);
            }
            break;
        case Brig::BRIG_OPERAND_ARGUMENT_LIST:
            validateListUse(OperandArgumentList(opr), context);
            break;

        case Brig::BRIG_OPERAND_FUNCTION_LIST:
            validateListUse(OperandFunctionList(opr), context);
            break;

        case Brig::BRIG_OPERAND_SIGNATURE_REF:
            {
                Directive d = OperandSignatureRef(opr).ref();
                assert(isProto(d));
                context.checkProtoUse(opr, d);
            }
            break;

        case Brig::BRIG_OPERAND_FBARRIER_REF:
            context.checkVarUse(opr, OperandFbarrierRef(opr).ref());
            break;

        case Brig::BRIG_OPERAND_REG:
        case Brig::BRIG_OPERAND_REG_VECTOR:
        case Brig::BRIG_OPERAND_IMMED:
        case Brig::BRIG_OPERAND_WAVESIZE:
            // Nothing to validate
            break;
        default:
            assert(false);
            break;
        }
    }

    template<class T>
    void validateListUse(T list, ValidatorContext &context) const
    {
        for (unsigned i = 0; i < list.elementCount(); ++i)
        {
            Directive d = list.elements(i);
            assert(d);

            if (isFunc(d))
            {
                context.checkSbrUse(list, d);
            }
            else if (isSym(d))
            {
                context.checkVarUse(list, d);
            }
            else
            {
                assert(false);
            }
        }
    }

    void validateCallArgScope(Inst inst, ValidatorContext &context, OperandArgumentList arglist, bool isOutArgs) const
    {
        for (unsigned n = 0; n < arglist.elementCount(); ++n)
        {
            Directive ref = arglist.elements(n);
            context.checkVarUse(arglist, ref); //F Remove this check? Looks like it is already validated at validateListUse
            context.registerArg(inst, ref, isOutArgs);
        }
    }

    // NB: THIS FUNCTION MUST CHECK ALL INSTRUCTIONS WHICH MIGHT REFER SYMBOLS, AND REGISTER THEIR USE.
    // SYMBOLS INCLUDE: FUNCTIONS, SIGNATURES, LABELS, VARIABLES, FBARRIERS
    void validateSpecInst(Inst i, ValidatorContext &context) const
    {
        if (i.opcode() == Brig::BRIG_OPCODE_CALL)
        {
            validate(i, context.isArgScope(), "Calls cannot be used outside of an argument scope");

            context.startCall(i);

            // validate that all arguments are defined in the current scope
            if (i.operand(0)) validateCallArgScope(i, context, i.operand(0), true);  // output
            if (i.operand(2)) validateCallArgScope(i, context, i.operand(2), false); // input

            // Make sure static functions are defined if they are called
            if (OperandFunctionRef funcRef = i.operand(1))
            {
                context.markFuncUsed(funcRef.fn());
            }

            context.endCall(i);
            //F
            // add validation of optional last argument of call
            // - functions and signatures must be visible
        }
        else if (i.opcode() == Brig::BRIG_OPCODE_LDA)
        {
            // lda cannot be used to take the address of an arg variable allocated in the current scope
            Operand opr = i.operand(1);
            assert(opr);

            SRef msg = "Cannot take address of an arg variable which is not a formal parameter";
            if (OperandAddress addr = opr)
            {
                DirectiveSymbol sym = addr.symbol();
                validate(opr, !sym || !context.isTransientArg(sym), msg);
            }
            else
            {
                //F is this checked after instruction validation?
                assert(false);
            }
        }
        else if (i.opcode() == Brig::BRIG_OPCODE_LDC)
        {
            // Make sure static functions are defined if they are referred to
            if (OperandFunctionRef funcRef = i.operand(1))
            {
                context.markFuncUsed(funcRef.fn());
            }
        }
        else if (i.opcode() == Brig::BRIG_OPCODE_BRN || i.opcode() == Brig::BRIG_OPCODE_CBR)
        {
            validateJumpTargets(i, context);
        }
    }

    void validateJumpTargets(Inst i, ValidatorContext &context) const
    {
        unsigned oprIdx = (i.opcode() == Brig::BRIG_OPCODE_BRN)? 1 : 2;
        Operand opr = i.operand(oprIdx);

        if (OperandAddress addr = opr)
        {
            DirectiveVariable sym = addr.symbol();
            assert(sym);

            if (DirectiveLabelList list = sym.init())
            {
                unsigned len = list.elementCount();
                for (unsigned i = 0; i < len; ++i)
                {
                    context.checkLabelUse(list.labels(i));
                }
            }
        }
        else
        {
            //F
        }
    }

    void validateBlockSections(Directive d, ValidatorContext &context) const
    {
        bool isBlockSection = context.isBlockSection();

        switch (getKind(d))
        {
        case Brig::BRIG_DIRECTIVE_BLOCK_START:
            validate(d, !isBlockSection, "Nested block sections are not allowed");
            validate(d, !BlockEnd(d.next()), "Empty block sections are not allowed");
            context.startBlockSection();
            break;
        case Brig::BRIG_DIRECTIVE_BLOCK_NUMERIC:
            validate(d, isBlockSection, "blocknumeric is allowed only inside block sections");
            break;
        case Brig::BRIG_DIRECTIVE_BLOCK_STRING:
            validate(d, isBlockSection, "blockstring is allowed only inside block sections");
            break;
        case Brig::BRIG_DIRECTIVE_BLOCK_END:
            validate(d, isBlockSection, "endblock without starting block directive");
            context.endBlockSection();
            break;
        default:
            validate(d, !isBlockSection, "Block sections may include only blockstring and blocknumeric directives");
            break;
        }
    }

    //-------------------------------------------------------------------------
    // Low-level Brig format validation

    void validateAlignment(unsigned offset, int section) const
    {
        validate(section, offset, (offset & 0x3) == 0, "All items in the section must be 32-bit aligned");
    }

    void validateSection(int section)
    {
        unsigned offset = 0;
        unsigned size = getSectionSize(section);

        map[section].reserve(size / AVR_ITEM_SIZE);

        validate(section, 0, getSectionData<uint32_t>(section, 0) == size, "Section must start with 32-bit section size");

        for (offset = BRIG_NUM_BYTES_RESERVED; offset < size; )
        {
            validateAlignment(offset, section);
            validate(section, offset,
                     offset + 2 * sizeof(uint16_t) <= size, // Each entry must start with 2 16-bit fields
                     "Last item does not fit in section");

            uint16_t itemSize = getSectionData<uint16_t>(section, offset);
            uint16_t itemKind = getSectionData<uint16_t>(section, offset + sizeof(uint16_t));
            size_t   minItemSize = getMinItemSize(section, offset, itemKind);

            validate(section, offset, (itemSize & 0x3) == 0, "Item size must be a multiple of 4");
            validate(section, offset, minItemSize <= itemSize, "Invalid item size");
            validate(section, offset, offset + itemSize <= size, "Item does not fit in section");

            map[section].push_back(offset);

            offset += itemSize;
        }

        assert(offset == size);
    }

    void validateStringSection()
    {
        unsigned offset = 0;
        int section = BRIG_SEC_STRTAB;
        unsigned size = getSectionSize(section);

        map[section].reserve(size / AVR_ITEM_SIZE);

        validate(section, 0, getSectionData<uint32_t>(section, 0) == size, "Section must start with 32-bit section size");

        for (offset = BRIG_NUM_BYTES_RESERVED; offset < size; )
        {
            validateAlignment(offset, section);
            validate(section, offset,
                     offset + sizeof(uint32_t) <= size, // Each entry must start with a 32-bit field
                     "Last item does not fit in section");

            uint32_t dataSize = getSectionData<uint32_t>(section, offset);
            uint32_t itemSize = ((dataSize + 7) / 4) * 4;

            validate(section, offset, offset + itemSize <= size, "Item does not fit in section");

            for (unsigned i = offset + 4 + dataSize; i < offset + itemSize; ++i)
            {
                validate(section, offset, getSectionData<uint8_t>(section, i) == 0, "Padding bytes at the end of string elements must be 0");
            }

            map[section].push_back(offset);

            offset += itemSize;
        }

        assert(offset == size);

        // Validate that all items are unique
        for (unsigned i = 0; i < map[section].size(); ++i)
        {
            uint32_t    mSize = getSectionData<uint32_t>(section, map[section][i]);
            const char* mData = getSectionAddr(section) + map[section][i] + 4;
            for (unsigned j = i + 1; j < map[section].size(); ++j)
            {
                uint32_t size = getSectionData<uint32_t>(section, map[section][j]);
                if (mSize == size)
                {
                    const char* data = getSectionAddr(section) + map[section][j] + 4;
                    validate(BRIG_SEC_STRTAB, map[section][i], memcmp(mData, data, size) != 0, "Identical entries in string section are not allowed");
                }
            }
        }
    }

    //-------------------------------------------------------------------------
    // Validation of Complex Items

    void validateDirectivesOrder()
    {
        Offset codePos = BRIG_NUM_BYTES_RESERVED;

        for(Directive d = brig.directives().begin();
            d != brig.directives().end();
            d = d.next())
        {
            if (DirectiveCode dc = d)
            {
                validate(dc, codePos <= dc.code().brigOffset(), "Directives must be ordered with respect to 'code' values");
                codePos = dc.code().brigOffset();
            }
        }
    }

    // validate that:
    // - offset is a valid offset to string section
    // - required data size = item data size
    void validateStringData(Directive d, unsigned offset, unsigned type, unsigned length, const char* structName, const char* fieldName)
    {
        validateOffset(d, BRIG_SEC_STRTAB, offset, structName, fieldName);

        uint32_t dataSize = getSectionData<uint32_t>(BRIG_SEC_STRTAB, offset);

        if ((getTypeSize(type) / 8 ) * length != dataSize) validate(d, false, "Expected size of " + string(structName) + "." + fieldName + " does not match actual data size");
    }

    void validateControlArgs(DirectiveControl d, unsigned argNum, bool isWsValid = false, unsigned min = 0, unsigned max = 0xFFFFFFFF)
    {
        unsigned len = d.elementCount();
        validate(d, len == argNum, "Control directive has invalid number of operands");

        // directive size must be large enough to hold all array elements
        unsigned available = d.brig()->size - offsetof(Brig::BrigDirectiveControl, values);  //F refactoring needed: this code is used several times
        validate(d, sizeof(Offset) * len <= available, "Invalid DirectiveControl size");

        for (unsigned i = 0; i < len; ++i)
        {
            Operand opr = d.values(i);
            if (OperandImmed imm = opr)
            {
                unsigned val = *reinterpret_cast<const uint32_t*>(&imm.brig()->bytes[0]);
                validate(imm, imm.type() == Brig::BRIG_TYPE_B32, "Invalid operand of control directive (expected u32 immediate)");
                validate(imm, min <= val && val <= max, "Invalid operand of control directive (incorrect immediate value)");
            }
            else if (OperandWavesize ws = opr)
            {
                validate(ws, isWsValid, "Invalid operand of control directive (wavesize is not accepted)");
                validate(ws, ws.type() == Brig::BRIG_TYPE_B32, "Invalid operand of control directive (expected u32 wavesize)");
            }
            else
            {
                validate(d, false, "Control directive has an invalid operand");
            }
        }
    }

    void validateDirective(Directive d)
    {
        assert(d);

        using namespace Brig;
        switch (getKind(d))
        {
        case BRIG_DIRECTIVE_KERNEL:
        case BRIG_DIRECTIVE_FUNCTION:
            {
                validateName(d, "&");
                validateArgs(d);
                validateSbrAttr(d);
                validateScopedDirectives(d);
                validateCode(d);
            }
            break;
        case BRIG_DIRECTIVE_VARIABLE:
        case BRIG_DIRECTIVE_IMAGE:
        case BRIG_DIRECTIVE_SAMPLER:
            {
                validateType(d);
                validateName(d, "%&");
                validateSegment(d);
                validateSymAttr(d);
                validateAlign(d);
                validateInit(d);
            }
            break;
        case BRIG_DIRECTIVE_LABEL:
            {
                validateName(d, "@");
            }
            break;
        case BRIG_DIRECTIVE_FBARRIER:
            {
                validateName(d, "%&");
            }
            break;
        case BRIG_DIRECTIVE_VARIABLE_INIT:
            {
                DirectiveVariableInit init = d;

                validateInitType(init);
                if (init.elementCount())
                {
                    validateStringData(init, init.brig()->data, init.type(), init.elementCount(), "DirectiveVariableInit", "data");
                }
                else
                {
                    validate(init, init.brig()->data == 0, "Empty initializer must have data = 0");
                }
            }
            break;
        case BRIG_DIRECTIVE_IMAGE_INIT:
            // Nothing to validate
            break;
        case BRIG_DIRECTIVE_SAMPLER_INIT:
            // Nothing to validate
            break;
        case BRIG_DIRECTIVE_CONTROL:
            {
                DirectiveControl dc = d;
                switch (dc.control())
                {
                case BRIG_CONTROL_REQUIREDWORKGROUPSIZE:
                    validateControlArgs(d, 3, true, 1);
                    break;

                case BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU:
                    validateControlArgs(d, 1, false, 1);
                    break;

                case BRIG_CONTROL_ENABLEBREAKEXCEPTIONS:
                case BRIG_CONTROL_ENABLEDETECTEXCEPTIONS:
                    validateControlArgs(d, 1);
                    break;

                case BRIG_CONTROL_MAXDYNAMICGROUPSIZE:
                    validateControlArgs(d, 1);
                    break;

                case BRIG_CONTROL_MAXFLATGRIDSIZE:
                    validateControlArgs(d, 1, true, 1);
                    break;

                case BRIG_CONTROL_MAXFLATWORKGROUPSIZE:
                    validateControlArgs(d, 1, true, 1);
                    break;

                case BRIG_CONTROL_REQUIREDDIM:
                    validateControlArgs(d, 1, false, 1, 3);
                    break;

                case BRIG_CONTROL_REQUIREDGRIDSIZE:
                    validateControlArgs(d, 3, true, 1);
                    break;

                case BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS:
                    validateControlArgs(d, 0);
                    break;

                default:
                    assert(false);
                }
            }
            break;

        case BRIG_DIRECTIVE_ARG_SCOPE_START:   break;
        case BRIG_DIRECTIVE_ARG_SCOPE_END:     break;

        case BRIG_DIRECTIVE_LABEL_INIT:
            validateLabelList<DirectiveLabelInit, Brig::BrigDirectiveLabelInit>(d);
            break;

        case BRIG_DIRECTIVE_LABEL_TARGETS:
            //F check validation of labeltargets
            validateLabelList<DirectiveLabelTargets, Brig::BrigDirectiveLabelTargets>(d);
            break;

        case BRIG_DIRECTIVE_COMMENT:
            {
                DirectiveComment c = d;
                string text = SRef(c.name());
                validate(c, text.find("//") == 0, "Comment must start with \"//\"");
            }
            break;

        case BRIG_DIRECTIVE_FILE:
            // Nothing to validate
            break;

        case BRIG_DIRECTIVE_SIGNATURE:
            {
                DirectiveSignature proto = d;
                validateName(d, "&");
                validate(d, proto.outCount() <= 1, "Signature cannot have more than one output parameter");

                // directive size must be large enough to hold all array elements
                unsigned len = proto.outCount() + proto.inCount();
                unsigned available = proto.brig()->size - offsetof(Brig::BrigDirectiveSignature, args);
                validate(proto, sizeof(BrigDirectiveSignatureArgument) * len <= available, "Invalid DirectiveSignature size");

                for (unsigned i = 0; i < len; ++i)
                {
                    unsigned type      = proto.args(i).type();
                    unsigned align     = proto.args(i).align();
                    uint64_t dim       = proto.args(i).dim();
                    SymbolModifier mod = proto.args(i).modifier();

                    // type must be any valid type except for b1.
                    validate(d, HSAIL_ASM::typeX2str(type) != 0 && type != Brig::BRIG_TYPE_B1, "Invalid argument type");

                    // align must be one of the following values: 1, 2, 4, 8
                    validate_Alignment(d, align);

                    validate(d, checkAlign(align, type),
                             "Specified alignment must be greater than or equal to natural alignment");

                    validate(d, mod.isDeclaration(), "Signature arguments cannot be defined, only declared");
                    validate(d, mod.linkage() == Brig::BRIG_LINKAGE_NONE, "Signature arguments must have linkage none");
                    validate(d, !mod.isConst(), "Signature arguments cannot be const");

                    if (mod.isArray())
                    {
                        if (mod.isFlexArray())
                        {
                            validate(d, i == len - 1, "Only last argument of signature may be a flexible array");
                            validate(d, dim == 0,     "Flexible arrays must have dim = 0");
                        }
                        else
                        {
                            validate(d, dim > 0, "Array declarations must have dim > 0");
                        }
                    }
                    else
                    {
                        validate(d, dim == 0, "Scalars must have dim = 0");
                    }

                }
            }
            break;

        // Need no additional checks
        case BRIG_DIRECTIVE_VERSION:    break;
        case BRIG_DIRECTIVE_EXTENSION:  break;

        case BRIG_DIRECTIVE_LOC:        break;
        case BRIG_DIRECTIVE_PRAGMA:     break;

        case Brig::BRIG_DIRECTIVE_BLOCK_START:
            validate(d, BlockStart(d).name() == "rti", "Invalid block section name, expected \"rti\"");
            break;

        case Brig::BRIG_DIRECTIVE_BLOCK_NUMERIC:
            {
                BlockNumeric blkNum = d;

                validate(d, blkNum.elementCount() > 0, "Empty blocknumeric, expected at least one value");

                switch (blkNum.type())
                {
                case BRIG_TYPE_NONE:
                case BRIG_TYPE_B1:
                case BRIG_TYPE_B128:
                case BRIG_TYPE_SAMP:
                case BRIG_TYPE_ROIMG:
                case BRIG_TYPE_RWIMG:
                case BRIG_TYPE_FBAR:
                    validate(d, false, "Invalid blocknumeric type");
                    break;

                default:
                    break;
                }

                validateStringData(d, blkNum.brig()->data, blkNum.type(), blkNum.elementCount(), "BlockNumeric", "data");
            }
            break;

        case Brig::BRIG_DIRECTIVE_BLOCK_STRING:
            // nothing to check
            break;

        case Brig::BRIG_DIRECTIVE_BLOCK_END:
            // nothing to check
            break;

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
            validate_dOffset(list, list.brig()->labels[i], DirectiveLabelInit(list)? "DirectiveLabelInit" : "DirectiveLabelTargets", "labels[*]");

            // Each element must refer DirectiveLabel
            Directive d(list.container(), list.brig()->labels[i]);
            validate(list, DirectiveLabel(d), "Invalid reference to label");
        }
    }

    void validateCall(Inst inst) const
    {
        assert(inst.opcode() == Brig::BRIG_OPCODE_CALL);

        OperandFunctionRef funcRef = inst.operand(1);

        if (funcRef)
        {
            // Call operands must be compatible with formal args
            validateFuncArgs(inst, funcRef.fn(), inst.operand(0), inst.operand(2));

            //validate(inst, !inst.operand(3), "Operand 3 is not accepted (too many operands)");
        }
        else if (inst.operand(3)) // indirect call with a list of targets or a signature
        {
            assert(OperandReg(inst.operand(1)));

            if (OperandFunctionList targets = inst.operand(3))
            {
                for (unsigned idx = 0; idx < targets.elementCount(); ++idx)
                {
                    DirectiveFunction fn = targets.elements(idx);
                    assert(fn); // validated on previous steps

                    validateFuncArgs(inst, fn, inst.operand(0), inst.operand(2));
                }
            }
            else if (OperandSignatureRef ref = inst.operand(3))
            {
                validateProtoArgs(inst, ref.ref(), inst.operand(0), inst.operand(2));
            }
            else
            {
                validate(inst, false, "Operand 3 must be a list of functions or a signature");
            }
        }
    }

    void validateComplexInst(Inst i) const
    {
        // Validate that there is a kernel/function which used this instruction
        validate(i, usedInst.count(i.brigOffset()) > 0, "Instruction does not belong to any kernel/function");

        switch(i.opcode())
        {
        case Brig::BRIG_OPCODE_CALL:  validateCall(i); break;

        default: break;
        }
    }

    void validateOperandAddress(OperandAddress addr) const
    {
        assert(addr);

        validate(addr, addr.type() == Brig::BRIG_TYPE_B32 ||
                       addr.type() == Brig::BRIG_TYPE_B64, "Invalid address type; must be b32 or b64");

        if (addr.brig()->symbol)
        {
            // This is a low-level check to make sure that operand refers a DirectiveSymbol
            Directive d(addr.container(), addr.brig()->symbol);
            validate(addr, d && DirectiveSymbol(d), "Invalid symbol reference");

#if !ENABLE_ADDRESS_SIZE_CHECK
            // This is a temporary workaround for lowering
            if (!isLargeModel() || getSegAddrSize(DirectiveSymbol(d).segment(), isLargeModel()) != 32 || getTypeSize(addr.type()) != 64)
#endif
            validate(addr, getTypeSize(addr.type()) == getSegAddrSize(DirectiveSymbol(d).segment(), isLargeModel()),
                     "Address type does not match segment address size");
        }

        if (addr.brig()->reg) validateAddrRef(addr, addr.type(), addr.reg());
    }

    unsigned validateRegName(Operand opr, SRef reg) const
    {
        string name = reg;

        SRef invalidName  = "Invalid register name";

        validate(opr, name.length() >= 3 && name.length() <= 5, invalidName);             // check length (max is '$s127')
        validate(opr, name[0] == '$' && name.find_first_of("csdq", 1) == 1, invalidName); // check prefixes
        validate(opr, name[2] != '0' || name.length() == 3, invalidName);                 // disable leading '0', e.g. $x00

        unsigned regNum = 0;
        for (unsigned i = 2; i < name.length(); ++i)
        {
            validate(opr, isdigit(name[i]) != 0, invalidName);
            regNum = regNum * 10 + (name[i] - '0');
        }

        SRef invalidIndex = "Invalid register index";

        switch(name[1])
        {
        case 'c': validate(opr, regNum <= 7,   invalidIndex); return Brig::BRIG_TYPE_B1;
        case 's': validate(opr, regNum <= 127, invalidIndex); return Brig::BRIG_TYPE_B32;
        case 'd': validate(opr, regNum <= 63,  invalidIndex); return Brig::BRIG_TYPE_B64;
        case 'q': validate(opr, regNum <= 31,  invalidIndex); return Brig::BRIG_TYPE_B128;
        default:
            validate(opr, false, "Invalid register type");
            return Brig::BRIG_TYPE_NONE;
        }
    }

    void validateOperandReg(OperandReg r) const
    {
        assert(r);
        validate(r, r.brig()->reg != 0, "Missing register reference in OperandReg");

        unsigned type = validateRegName(r, r.reg());
        validate(r, r.type() == type, "Invalid register type");
    }

    void validateRegV(OperandRegVector vector)
    {
        assert(vector);

        unsigned size = vector.elementCount();
        validate(vector, size == 2 || size == 3 || size == 4, "Vector must include 2, 3 or 4 registers");

        unsigned vtype = vector.type();
        validate(vector, vtype == Brig::BRIG_TYPE_B1
                      || vtype == Brig::BRIG_TYPE_B32
                      || vtype == Brig::BRIG_TYPE_B64, "Invalid vector type, expected b1, b32 or b64");

        // directive size must be large enough to hold all array elements
        unsigned available = vector.brig()->size - offsetof(Brig::BrigOperandRegVector, regs);
        validate(vector, sizeof(Offset) * vector.elementCount() <= available, "Invalid OperandRegVector size");

        unsigned rtype = Brig::BRIG_TYPE_NONE;
        for (unsigned i = 0; i < size; ++i)
        {
            // This is a low-level check to make sure array of offsets refer register names
            validate_sOffset(vector, vector.brig()->regs[i], "OperandRegVector", "regs[*]");

            unsigned type = validateRegName(vector, vector.regs(i));
            if (i == 0) rtype = type;

            validate(vector, rtype == type , "All registers in a vector must be of the same type");
        }

        validate(vector, vtype == rtype, "Registers in a vector must have the same type as the vector");
    }

    void validateImm(OperandImmed imm) const
    {
        assert(imm);
        validate(imm, isBitType(imm.type()), "Invalid type of immediate operand");

        validate(imm, std::max(1U, getTypeSize(imm.type()) / 8) == imm.byteCount(), // 1 byte for b1
                      "Immediate operand size does not match its type");

        unsigned available = imm.brig()->size - offsetof(Brig::BrigOperandImmed, bytes);
        validate(imm, imm.byteCount() <= available, "Invalid OperandImmed size");

        // The b1 type uses a single byte which must be either be 0 or 1.
        if (imm.type() == Brig::BRIG_TYPE_B1)
        {
            validate(imm, imm.bytes(0) == 0 || imm.bytes(0) == 1, "Immediate value of b1 type must be either 0 or 1");
        }
    }

    void validateAddrRef(Operand parent, unsigned type, SRef reg) const
    {
        assert(parent);
        assert(!reg.empty());

        unsigned regType = validateRegName(parent, reg);
        validate(parent, regType == type, "Register type does not match address type");
    }

    void validateOperandList(OperandList list)
    {
        assert(list);
        bool isArgList = OperandArgumentList(list);

        unsigned available = list.brig()->size - offsetof(Brig::BrigOperandList, elements);
        validate(list, sizeof(Offset) * list.elementCount() <= available, "Invalid OperandList size");

        if (list.elementCount() == 0)
        {
            // This is not stated in the spec, but implicitly assumed
            validate(list, isArgList, "List of functions must include at least one element");

            // First array element is ALWAYS present. It should refer 0 if the list is empty
            //F validate(list, list.brig()->elements[0] == 0, "First element of an empty argument list must be 0");
            return;
        }

        for (unsigned i = 0; i < list.elementCount(); ++i)
        {
            // make sure offset to an operand is valid
            validate_dOffset(list, list.brig()->elements[i], isArgList? "OperandArgumentList" : "OperandFunctionList", "elements[*]");

            // all elements in the list must be of the same kind
            Directive d = list.elements(i);
            validate(d, isArgList? (bool)DirectiveSymbol(d) : (bool)DirectiveFunction(d), "Invalid element kind");
        }
    }

    bool chkAddrSize(unsigned type, unsigned segment) const
    {
        switch (segment)
        {
        case Brig::BRIG_SEGMENT_FLAT:
        case Brig::BRIG_SEGMENT_GLOBAL:
        case Brig::BRIG_SEGMENT_READONLY:
        case Brig::BRIG_SEGMENT_KERNARG:
            return type == (isLargeModel()? Brig::BRIG_TYPE_B64 : Brig::BRIG_TYPE_B32);

        default:
            return type == Brig::BRIG_TYPE_B32;
        }
    }

    template<class DirectiveType>
    void validateOperandRef(OperandRef opr, SRef msg)
    {
        // This is a low-level check to make sure operand refers proper directive
        Directive d(opr.container(), opr.brig()->ref);
        validate(opr, DirectiveType(d), msg);
    }

    void validateLabelRef(OperandRef opr)
    {
        // This is a low-level check to make sure operand refers proper directive
        Directive d(opr.container(), opr.brig()->ref);
        validate(opr, DirectiveLabel(d) || DirectiveLabelTargets(d), "Invalid reference to DirectiveLabel or DirectiveLabelTargets");
    }

    void validateOperand(Operand opr)
    {
        assert(opr);

        switch (getKind(opr))
        {
        case Brig::BRIG_OPERAND_ADDRESS:
            validateOperandAddress(opr);
            break;

        case Brig::BRIG_OPERAND_IMMED:
            validateImm(opr);
            break;

        case Brig::BRIG_OPERAND_ARGUMENT_LIST:
            validateOperandList(opr);
            break;

        case Brig::BRIG_OPERAND_FUNCTION_LIST:
            validateOperandList(opr);
            break;

        case Brig::BRIG_OPERAND_LABEL_REF:
            //F check validation of labeltargets
            validateLabelRef(opr);
            break;

        case Brig::BRIG_OPERAND_FUNCTION_REF:
            validateOperandRef<DirectiveFunction>(opr, "Invalid reference to function");
            break;

        case Brig::BRIG_OPERAND_SIGNATURE_REF:
            validateOperandRef<DirectiveSignature>(opr, "Invalid reference to signature");
            break;

        case Brig::BRIG_OPERAND_FBARRIER_REF:
            validateOperandRef<DirectiveFbarrier>(opr, "Invalid reference to fbarrier");
            break;

        case Brig::BRIG_OPERAND_ARGUMENT_REF: // delme
            //F delme
            assert(false);
            break;

        case Brig::BRIG_OPERAND_REG:
            validateOperandReg(opr);
            break;

        case Brig::BRIG_OPERAND_REG_VECTOR:
            validateRegV(opr); // includes low-level checks
            break;

        case Brig::BRIG_OPERAND_WAVESIZE:
            {
                unsigned type = OperandWavesize(opr).type();
                validate(opr, isBitType(type) && type != Brig::BRIG_TYPE_B128, "Invalid wavesize type");
            }
            break;

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
        validate(d, name.find_first_of(pref) == 0, "Invalid identifier prefix");

        // FIXME: temporarily disabled
        //validate(d, name.find("__hsa") != 1, "Identifiers must not start with the characters '__hsa'");

        validate(d, name.length() > 1 &&
                    name.find_first_of(ALPHA, 1) == 1 &&
                   (name.length() == 2 || name.find_first_not_of(ALPHANUM, 2) == string::npos), "Invalid identifier");
    }

    void validateSegment(Directive d) const
    {
        unsigned segment = getSegment(d);

        if (segment == Brig::BRIG_SEGMENT_ARG ||
            segment == Brig::BRIG_SEGMENT_KERNARG ||
            segment == Brig::BRIG_SEGMENT_SPILL)
        {
            validate(d, getNamePref(d) == '%',
                     "Only kernel/function scoped variables can be defined in Arg, Kernarg and Spill segments");
        }

        // Image and Sampler objects can be declared as either a global variable or a kernarg variable
        if (DirectiveImage(d) || DirectiveSampler(d))
        {
            validate(d, isArgSeg(d) || isKernArgSeg(d) || isGlobalSeg(d) || isReadonlySeg(d),
                     "Images and samplers may only be defined in arg, kernarg, global and readonly segments");
        }
    }

    void validateSymAttr(DirectiveSymbol d) const
    {
        assert(isSym(d));

        if (isDef(d))
        {
            validate(d, !isExtern(d), "Variable definition cannot be extern");
            validate(d, !isKernArgSeg(d), "Kernarg segment variables must be defined as kernel parameters");
        }

        // Flexible arrays assume that 'array' propoerty is also set. This is checked on first phase

        // Flexible arrays may be declared only as last function argument (formal)
        validate(d, !isFlex(d) || (isArgSeg(d) && isDecl(d)),
                    "A flexible array may only be declared as the last function argument");

        // Static/extern declarations and definitions have file scope
        validate(d, !isStatic(d) || getNamePref(d) == '&', "Variable defined in a kernel or a function cannot be static");
        validate(d, !isStatic(d) || isDef(d),              "Variable declaration cannot be static");
        validate(d, !isExtern(d) || getNamePref(d) == '&', "Variable defined in a kernel or a function cannot be extern");


        // Static symbols must be defined or declared in global, group, private, or readonly segments
        validate(d, !isStatic(d) || isGlobalSeg(d) || isGroupSeg(d) || isPrivateSeg(d) || isReadonlySeg(d),
                    "Static variables must be defined or declared in global, group, private, or readonly segments");

        // If the object is an array, the size of the array must be specified in the
        // definition but can be omitted in the declaration.
        if (isArray(d))
        {
            if (isDef(d))
            {
                validate(d, getArraySize(d) > 0, "Array definitions must have dim > 0");
            }
            else if (isFlex(d))
            {
                validate(d, getArraySize(d) == 0, "Flexible arrays must have dim = 0");
            }
        }
        else
        {
            validate(d, getArraySize(d) == 0, "Scalars must have dim = 0");
        }
    }

    void validateSbrAttr(Directive d) const
    {
        assert(isSbr(d));

        if (isKernel(d))
        {
            // Kernels have linkage none (neither external nor static),
            // because they can only be accessed from a dispatch call.

            validate(d, !isExtern(d), "Kernels cannot be extern");
            validate(d, !isStatic(d), "Kernels cannot be static");
            validate(d, isDef(d),     "Kernels cannot have declarations");
        }
        else
        {
            assert(isFunc(d));

            if (isDef(d))
            {
                validate(d, !isExtern(d), "Function definition cannot be extern");
            }
            else
            {
                validate(d, getOperationNum(d) == 0, "Function declaration cannot have a body");
            }
        }
    }

    void validateType(Directive d) const
    {
        assert(isSym(d));

        unsigned type = getDataType(d);

        if (DirectiveVariable(d))
        {
            validate(d, type != Brig::BRIG_TYPE_RWIMG &&
                        type != Brig::BRIG_TYPE_ROIMG &&
                        type != Brig::BRIG_TYPE_SAMP,
                        "Invalid symbol type");

            validate(d, type != Brig::BRIG_TYPE_B1, "b1 is not a valid type for arguments and variables");
        }
        else if (DirectiveImage(d))
        {
            validate(d, type == Brig::BRIG_TYPE_RWIMG || type == Brig::BRIG_TYPE_ROIMG,
                     "Image type must be either RWImg or ROImg");
        }
        else if (DirectiveSampler(d))
        {
            validate(d, type == Brig::BRIG_TYPE_SAMP, "Sampler must have Samp type");
        }
        else
        {
            assert(false);
        }
    }

    void validateAlign(Directive d) const
    {
        assert(isSym(d));
        validate(d, checkAlign(getAlignment(d), getDataType(d)),
                 "Specified alignment must be greater than or equal to natural alignment");
    }

    void validateInitType(DirectiveVariableInit init)
    {
        // NB: b1 is not allowed as array/variable type
        validate(init, isBitType(init.type()) && init.type() != Brig::BRIG_TYPE_B1,
                       "Invalid DirectiveVariableInit type, expected b8, b16, b32, b64 or b128");
    }

    void validateInit(DirectiveSymbol sym)
    {
        assert(sym);

        Directive d = sym.init();
        // This is a low-level check to make sure that initializer (if any) has the correct type
        validate(sym, !d ||
                      isa<DirectiveVariableInit>(d) || //F use for all low-level checks
                      isa<DirectiveImageInit>(d) ||
                      isa<DirectiveSamplerInit>(d) ||
                      isa<DirectiveLabelInit>(d),
                     "Invalid initializer type");

        if (isConst(sym))
        {
            validate(sym, isGlobalSeg(sym) || isReadonlySeg(sym),
                        "Only variables in global and readonly segments may be labelled as const");
        }

        if (d)
        {
            validate(sym, isDef(sym), "Variable declaration cannot have initializer");
            validate(sym, isGlobalSeg(sym) || isReadonlySeg(sym),
                     "Only variables in global and readonly segments may be initialized");
        }
        else // No initializer
        {
            ///if (isArgSeg(sym) || isKernArgSeg(sym)) // This check is added to improve error reporting
            ///{
            ///    validate(sym, !isConst(sym), "Arguments cannot be const");
            ///}
            ///else // const definition => must have initializer
            ///{
            ///    //F According to new spec, initializer is optional
            ///    //F if (isConst(sym)) validate(sym, isDecl(sym), "Const variable definitions must have initializer");
            ///}
        }

        if (!d)
        {
            return; // nothing to validate
        }
        else if (DirectiveVariableInit init = d)
        {
            validate(sym, DirectiveVariable(sym), "Images and Samplers cannot be initialized with VariableInit");

            // NB: DirectiveVariableInit being checked here may not be validated yet
            // Validate init type - this is important for code below
            validateInitType(init);

            validate(init, getTypeSize(init.type()) == getTypeSize(getDataType(sym)), "Invalid initializer type; does not match variable type");

            uint64_t dim = getArraySize(sym);
            uint64_t elementCount = (dim == 0) ? 1 : dim; // scalars have dim=0 and 1 value
            validate(init, elementCount >= init.elementCount(), "Invalid initializer; too many initial values");
        }
        else if (DirectiveLabelInit init = d)
        {
            unsigned type = sym.type();
            validate(sym, DirectiveVariable(sym), "Images and Samplers cannot be initialized with LabelInit");

            uint64_t dim = getArraySize(sym);
            validate(sym, dim > 0, "Empty array of labels is not allowed");
            validate(sym, type == Brig::BRIG_TYPE_U64 || type == Brig::BRIG_TYPE_U32, "Invalid type of array of labels, expected u32 or u64");
            validate(sym, type == (isLargeModel()? Brig::BRIG_TYPE_U64 : Brig::BRIG_TYPE_U32), "Invalid type of array of labels, must match machine model");
            validate(sym, dim == init.elementCount(), "Invalid number of labels, must match array size");
        }
        else if (DirectiveImageInit init = d)
        {
            validate(sym, DirectiveImage(sym), "Variables and Samplers cannot be initialized with ImageInit");
            validate(sym, getArraySize(sym) <= 1, "Arrays of images with dim > 1 cannot be initialized");

            validate(sym, isGlobalSeg(sym) || isReadonlySeg(sym), "Image properties may only be defined in global and readonly segments");
        }
        else if (DirectiveSamplerInit init = d)
        {
            validate(sym, DirectiveSampler(sym), "Variables and Images cannot be initialized with SamplerInit");
            validate(sym, getArraySize(sym) <= 1, "Arrays of images with dim > 1 cannot be initialized");

            validate(sym, isGlobalSeg(sym) || isReadonlySeg(sym), "Sampler properties may only be defined in global and readonly segments");

            // Wrap, mirror and mirroronce require normalized coordinates
            uint8_t u = init.boundaryU();
            uint8_t v = init.boundaryV();
            uint8_t w = init.boundaryW();

            if (u == Brig::BRIG_BOUNDARY_WRAP || u == Brig::BRIG_BOUNDARY_MIRROR || u == Brig::BRIG_BOUNDARY_MIRRORONCE ||
                v == Brig::BRIG_BOUNDARY_WRAP || v == Brig::BRIG_BOUNDARY_MIRROR || v == Brig::BRIG_BOUNDARY_MIRRORONCE ||
                w == Brig::BRIG_BOUNDARY_WRAP || w == Brig::BRIG_BOUNDARY_MIRROR || w == Brig::BRIG_BOUNDARY_MIRRORONCE)
            {
                validate(sym, !init.modifier().isUnnormalized(), "Wrap, mirror and mirroronce require normalized coordinates");
            }
        }
    }

    void validateArgs(Directive d)
    {
        if (isKernel(d)) {
            validate(d, getOutParamNum(d) == 0, "Kernels cannot have output parameters");
        } else {
            validate(d, getOutParamNum(d) <= 1, "Functions cannot have more than one output parameter");
        }

        Directive next;
        next = validateSbrArgs(d, d.next(), getFirstOutParam(d), getOutParamNum(d), false);
        next = validateSbrArgs(d, next,     getFirstInParam(d),  getInParamNum(d),  true);

        validate(d, next.brigOffset() == getFirstScoped(d).brigOffset(), "Invalid reference to first scoped directive");
    }

    Directive validateSbrArgs(Directive sbr, Directive next, Directive arg, unsigned paramNum, bool isInputArgs)
    {
        unsigned seg = isFunc(sbr)? Brig::BRIG_SEGMENT_ARG : Brig::BRIG_SEGMENT_KERNARG;

        validate(sbr, next.brigOffset() == arg.brigOffset(), "Invalid reference to first argument");

        // NB: arguments being checked here are not validated yet!

        arg = next;
        for (unsigned i = 0; i < paramNum; ++i)
        {
            validate(sbr, arg,        "Insufficient number of parameters");
            validate(arg, isSym(arg), "Invalid directive, expected kernel/function parameter");
            validate(arg, getSegment(arg) == seg, "Invalid segment");

            if (isFlex(arg)) validate(arg, isInputArgs && i == paramNum - 1, "Flexible array is only allowed as the last function argument");

            validateInit(arg); // This is necessary only to avoid cryptic error msg
            arg = arg.next();
        }
        return arg;
    }

    void validateScopedDirectives(Directive sbr) const
    {
        Directive ds  = getFirstScoped(sbr);
        Directive end = getNextTopLevel(sbr);

        if (isDecl(sbr))
        {
            validate(sbr, ds.brigOffset() == end.brigOffset(), "Declarations must not have scoped directives");
        }
        else
        {
            validate(sbr, ds.brigOffset() <= end.brigOffset(), "Invalid reference to next toplevel directive");
        }

        // NB: directives being checked here are not validated yet!

        for (; ds != end; ds = ds.next())
        {
            validate(ds, isBodyStatement(ds), "Directive is not allowed inside kernel or function");
            validate(ds, (!DirectiveImage(ds) && !DirectiveSampler(ds)) || isArgSeg(ds),
                     "Images and samplers defined in kernel/function body must be allocated in arg segment");
            validate(ds, !isSym(ds) || !isFlex(ds),
                     "Flexible array may only be defined as the last function argument");
        }
    }

    void validateCode(Directive d)
    {
        // NB: instructions being checked here are not validated yet!

        Inst i = getFirstOperation(d);
        for (unsigned idx = getOperationNum(d); idx > 0; --idx)
        {
            validate(d, i, "Kernel/function body has insufficient number of instructions");
            usedInst.insert(i.brigOffset()); // Mark as used
            i = i.next();
        }
    }

    void validateFuncArgs(Inst inst, DirectiveFunction fn, OperandArgumentList out, OperandArgumentList in) const
    {
        validate(inst, out, "Missing list of output arguments");
        validate(inst, in,  "Missing list of input arguments");

        if (out.elementCount() > 0) // output args are optional
        {
            validate(out, fn.outArgCount() == out.elementCount(), "Invalid number of output parameters");

            DirectiveSymbol formalArg = fn.next();
            for (unsigned i = 0; i < fn.outArgCount(); ++i)
            {
                assert(formalArg);                          // Validated on previous steps
                assert(DirectiveSymbol(out.elements(i)));   // Validated on previous steps

                validateCallArg(out, out.elements(i), formalArg);
                formalArg = formalArg.next();
            }
        }

        validate(in, fn.inArgCount() == in.elementCount(), "Invalid number of input parameters");

        DirectiveSymbol formalArg = fn.firstInArg(); // It is already validated that arguments are symbols
        for (unsigned i = 0; i < fn.inArgCount(); ++i)
        {
            assert(formalArg);                          // Validated on previous steps
            assert(DirectiveSymbol(in.elements(i)));    // Validated on previous steps

            validateCallArg(in, in.elements(i), formalArg);
            formalArg = formalArg.next();
        }
    }

    void validateProtoArgs(Inst inst, DirectiveSignature proto, OperandArgumentList out, OperandArgumentList in) const
    {
        assert(inst);
        assert(proto); // Validated on previous steps
        validate(inst, out, "Missing list of output arguments");
        validate(inst, in,  "Missing list of input arguments");

        if (out.elementCount() > 0) // output args are optional
        {
            validate(inst, proto.outCount() == out.elementCount(), "Invalid number of output parameters");

            for (unsigned idx = 0; idx < proto.outCount(); ++idx)
            {
                validateCallArg(out, out.elements(idx), proto.args(idx).type(), proto.args(idx).align(), proto.args(idx).modifier().isArray(), proto.args(idx).dim());
            }
        }

        validate(inst, proto.inCount() == in.elementCount(), "Invalid number of input parameters");

        for (unsigned idx = 0, pos = proto.outCount(); idx < proto.inCount(); ++idx, ++pos)
        {
            validateCallArg(in, in.elements(idx), proto.args(pos).type(), proto.args(pos).align(), proto.args(pos).modifier().isArray(), proto.args(pos).dim());
        }
    }

    void validateCallArg(OperandArgumentList list, DirectiveSymbol actual, DirectiveSymbol formal) const
    {
        validateCallArg(list, actual, formal.type(), formal.align(), isArray(formal), formal.dim());
    }

    // An actual argument is compatible with a formal parameter if one of these three
    // properties hold:
    // - The two have identical properties, type, size, and alignment.
    // - Both are arrays with the same size and alignment and the elements have identical properties.
    // - Both are arrays with elements that have identical properties, both arrays have
    //   the same alignment, and the formal is a flexible array (of no specified size).
    void validateCallArg(OperandArgumentList list, DirectiveSymbol actual, unsigned formalType, unsigned formalAlign, bool formalIsArray, uint64_t formalDim) const
    {
        assert(actual);

        validate(list, isArgSeg(actual), "Call arguments must be defined in arg segment");

        validate(list, formalType == actual.type(), "Incompatible types of formal and actual parameters");
        validate(list, getPhysicalAlignment(formalType, formalAlign) == getPhysicalAlignment(actual), "Incompatible alignment of formal and actual parameters");

        if (formalIsArray) { // may be either array or flexible array
            validate(list, isArray(actual), "Actual parameter must be an array");
            validate(list, !isFlex(actual), "Actual parameter must have fixed size (cannot be flexible array)");
            validate(list, formalDim == 0 || formalDim == actual.dim(), "Incompatible formal and actual parameters: arrays must have the same length");
        } else {
            validate(list, !isArray(actual), "Actual parameter must be scalar (not array)");
        }
    }

    //-------------------------------------------------------------------------
    // Basic Field Validation

    template<class T> void validate_sOffset(T item, Brig::BrigStringOffset32_t offset, const char* structName, const char* fieldName, bool z = false) const
    {
        validateOffset(item, BRIG_SEC_STRTAB, offset, structName, fieldName, z);
    }
    template<class T> void validate_dOffset(T item, Brig::BrigDirectiveOffset32_t offset, const char* structName, const char* fieldName, bool z = false, bool ex = false) const
    {
        validateOffset(item, BRIG_SEC_DIRECTIVES, offset, structName, fieldName, z, ex);
    }
    template<class T> void validate_cOffset(T item, Brig::BrigCodeOffset32_t offset, const char* structName, const char* fieldName, bool z = false, bool ex = false) const
    {
        validateOffset(item, BRIG_SEC_CODE, offset, structName, "code", z, ex);
    }
    template<class T> void validate_oOffset(T item, Brig::BrigOperandOffset32_t offset, const char* structName, const char* fieldName, bool z = false) const
    {
        validateOffset(item, BRIG_SEC_OPERANDS, offset, structName, fieldName, z);
    }

    template<class T> void validateOffset(T item, int section, unsigned offset, const char* structName, const char* fieldName, bool z = false, bool ex = false) const
    {
        assert(section == BRIG_SEC_DIRECTIVES ||
               section == BRIG_SEC_OPERANDS   ||
               section == BRIG_SEC_CODE       ||
               section == BRIG_SEC_STRTAB);

        unsigned size = getSectionSize(section);

        if (offset == 0 && !z)                        invalidOffset(item, section, structName, fieldName, "cannot be 0");
        if (offset > size || (offset == size && !ex)) invalidOffset(item, section, structName, fieldName, "is out of section");

        if (offset > 0 && offset < size && !std::binary_search(map[section].begin(), map[section].end(), offset)) {
            invalidOffset(item, section, structName, fieldName, "points at the middle of an item");
        }
    }

    template<class T> void invalidOffset(T item, int section, const char* structName, const char* fieldName, const char* errMsg) const
    {
        string msg = "";

        switch(section)
        {
        case BRIG_SEC_DIRECTIVES: msg = "directives"; break;
        case BRIG_SEC_OPERANDS:   msg = "operands";   break;
        case BRIG_SEC_CODE:       msg = "code";       break;
        case BRIG_SEC_STRTAB:     msg = "string";     break;
        default:
            assert(false);
            break;
        }

        validate(item, false, "Invalid offset to " + msg + " section: " + structName + "." + fieldName + " " + errMsg);
    }

    template<class T> void validate_ControlType(T item, unsigned type) const
    {
        using namespace Brig;
        switch(type)
        {
        case BRIG_CONTROL_ENABLEBREAKEXCEPTIONS:
        case BRIG_CONTROL_ENABLEDETECTEXCEPTIONS:
        case BRIG_CONTROL_MAXDYNAMICGROUPSIZE:
        case BRIG_CONTROL_MAXFLATGRIDSIZE:
        case BRIG_CONTROL_MAXFLATWORKGROUPSIZE:
        case BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU:
        case BRIG_CONTROL_REQUIREDDIM:
        case BRIG_CONTROL_REQUIREDGRIDSIZE:
        case BRIG_CONTROL_REQUIREDWORKGROUPSIZE:
        case BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS:
            return;
        default:
            validate(item, false, "Invalid ControlType value");
        }
    }

    template<class T> void validateLinkage(T item, unsigned linkage) const
    {
        using namespace Brig;
        validate(item, linkage == BRIG_LINKAGE_EXTERN || linkage == BRIG_LINKAGE_STATIC || linkage == BRIG_LINKAGE_NONE, "Invalid Linkage value");
    }

    template<class T> void validate_ExecMod(T item, unsigned mod) const
    {
        using namespace Brig;
        unsigned linkage = mod & BRIG_EXECUTABLE_LINKAGE;
        unsigned mask = BRIG_EXECUTABLE_LINKAGE | BRIG_EXECUTABLE_DECLARATION;

        validate(item, (mod & ~mask) == 0, "Invalid ExecutableModifier value");
        validateLinkage(item, linkage);
    }

    template<class T> void validate_SymMod(T item, unsigned mod) const
    {
        using namespace Brig;
        unsigned linkage = mod & BRIG_SYMBOL_LINKAGE;
        unsigned mask = BRIG_SYMBOL_LINKAGE | BRIG_SYMBOL_DECLARATION | BRIG_SYMBOL_CONST | BRIG_SYMBOL_ARRAY | BRIG_SYMBOL_FLEX_ARRAY;

        validate(item, (mod & ~mask) == 0, "Invalid SymbolModifier value");
        validate(item, (mod & BRIG_SYMBOL_FLEX_ARRAY) == 0 || (mod & BRIG_SYMBOL_ARRAY) != 0, "Invalid SymbolModifier value: 'flex' = 1, but 'array' = 0");
        validateLinkage(item, linkage);
    }

    template<class T> void validate_Segment(T item, unsigned seg) const
    {
        validate(item, HSAIL_ASM::segment2str(seg) != NULL, "Invalid StorageClass value");
    }

    template<class T> void validate_DataType(T item, unsigned type) const
    {
        validate(item, HSAIL_ASM::typeX2str(type) != NULL, "Invalid DataType value");
    }

    template<class T> void validate_ImageOrder(T item, unsigned order) const
    {
        validate(item, HSAIL_ASM::imageOrder2str(order) != NULL, "Invalid ImageOrder value");
    }

    template<class T> void validate_ImageFormat(T item, unsigned format) const
    {
        validate(item, HSAIL_ASM::imageFormat2str(format) != NULL, "Invalid ImageFormat value");
    }

    template<class T> void validate_Machine(T item, unsigned machineModel) const
    {
        validate(item, HSAIL_ASM::machineModel2str(machineModel) != NULL, "Invalid Machine Model value");
    }

    template<class T> void validate_Profile(T item, unsigned profile) const
    {
        validate(item, HSAIL_ASM::profile2str(profile) != NULL, "Invalid Version Profile value");
    }

    template<class T> void validate_Opcode  (T item, unsigned opcode) const
    {
        validate(item, HSAIL_ASM::opcode2str(opcode) != NULL, "Invalid Opcode value");
    }

    template<class T> void validate_AtomicOp(T item, unsigned opr) const
    {
        validate(item, HSAIL_ASM::atomicOperation2str(opr) != NULL, "Invalid AtomicOperation");
    }

    template<class T> void validate_MemSem(T item, unsigned sem) const
    {
        validate(item, HSAIL_ASM::memorySemantic2str(sem) != NULL, "Invalid MemorySemantic value");
    }

    template<class T> void validate_Geom(T item, unsigned geom) const
    {
        validate(item, HSAIL_ASM::imageGeometry2str(geom) != NULL, "Invalid Geom value");
    }

    template<class T> void validate_CmpOp(T item, unsigned opr) const
    {
        validate(item, HSAIL_ASM::compareOperation2str(opr) != NULL, "Invalid CompareOperation");
    }

    template<class T> void validate_Packing(T item, unsigned packing) const
    {
        validate(item, HSAIL_ASM::pack2str(packing) != NULL, "Invalid Packing value");
    }

    template<class T> void validate_EquivalenceClass(T item, unsigned equiv) const
    {
        validate(item, equiv <= 255, "Invalid Equivalence Class value");
    }

    void validate_SamplerModifier(Directive item, unsigned val) const
    {
        using namespace Brig;
        validate(item, (val & ~(BRIG_SAMPLER_FILTER | BRIG_SAMPLER_COORD)) == 0, "Invalid Sampler modifier");
    }

    template<class T> void validate_MemMod(T item, unsigned val) const
    {
        using namespace Brig;
        validate(item, (val & ~(BRIG_MEMORY_SEMANTIC | BRIG_MEMORY_ALIGNED)) == 0, "Invalid Memory modifier");
    }

    void validate_SamplerBoundary(Directive item, uint8_t boundary) const
    {
        using namespace Brig;

        validate(item, boundary == BRIG_BOUNDARY_CLAMP
                    || boundary == BRIG_BOUNDARY_WRAP
                    || boundary == BRIG_BOUNDARY_MIRROR
                    || boundary == BRIG_BOUNDARY_MIRRORONCE
                    || boundary == BRIG_BOUNDARY_BORDER, "Invalid Sampler 'boundary' value");
    }

    template<class T> void validate_Alignment(T item, unsigned val) const
    {
        validate(item, val == 0 || val == 1 || val == 2 || val == 4 || val == 8 || val == 16, "Invalid alignment value, expected 0, 1, 2, 4, 8 or 16");
    }

    template<class T> void validate_Fence(T item, unsigned val) const
    {
        using namespace Brig;
        validate(item, val == BRIG_FENCE_NONE         ||
                       val == BRIG_FENCE_GROUP        ||
                       val == BRIG_FENCE_GLOBAL       ||
                       val == BRIG_FENCE_BOTH         ||
                       val == BRIG_FENCE_PARTIAL      ||
                       val == BRIG_FENCE_PARTIAL_BOTH, "Invalid SyncFlags value");
    }

    template<class T> void validate_Width(T item, unsigned val) const
    {
        validate(item, HSAIL_ASM::width2str(val) != NULL, "Invalid Width value");
    }

    template<class T> void validate_AluMod(T item, unsigned val) const
    {
        using namespace Brig;
        validate(item, (val & ~(BRIG_ALU_ROUND | BRIG_ALU_FTZ)) == 0, "Invalid SymbolModifier value");
    }

    template<class T> void validate_Reserved(T item, unsigned reserved) const
    {
        validate(item, reserved == 0, "Invalid reserved field value; must be 0");
    }

    //-------------------------------------------------------------------------
    //

    size_t getMinItemSize(int section, unsigned offset, unsigned itemKind) const
    {
        int result = 0;
        if (section == BRIG_SEC_DIRECTIVES)
        {
            result = HSAIL_ASM::size_of_directive(itemKind);
        }
        else if (section == BRIG_SEC_CODE)
        {
            result = HSAIL_ASM::size_of_inst(itemKind);
        }
        else if (section == BRIG_SEC_OPERANDS)
        {
            result = HSAIL_ASM::size_of_operand(itemKind);
        }
        validate(section, offset, result > 0, "Invalid item kind");
        return result;
    }

    bool isTopLevelStatement(Directive d) const
    {
        return !HSAIL_ASM::isBodyOnly(d);
    }

    // Note that images and samplers may be defined as kernarg objects
    bool isBodyStatement(Directive d) const
    {
        return !HSAIL_ASM::isToplevelOnly(d);
    }

    //-------------------------------------------------------------------------
    // Access to Brig sections

    string getSectionName(int section) const
    {
        switch(section) {
        case BRIG_SEC_STRTAB:     return ".strtab";
        case BRIG_SEC_DIRECTIVES: return ".directives";
        case BRIG_SEC_CODE:       return ".code";
        case BRIG_SEC_OPERANDS:   return ".operands";
        case BRIG_SEC_DEBUG:      return ".debug";
        default:                  return "";
        }
    }

    template<typename T>
    T getSectionData(int section, unsigned offset)
    {
        return *(reinterpret_cast<const T*>(getSectionAddr(section) + offset));
    }

    const char* getSectionAddr(int section) const
    {
        switch(section) {
        case BRIG_SEC_STRTAB:     return brig.strings().getData(0);
        case BRIG_SEC_DIRECTIVES: return brig.directives().getData(0);
        case BRIG_SEC_CODE:       return brig.insts().getData(0);
        case BRIG_SEC_OPERANDS:   return brig.operands().getData(0);
        case BRIG_SEC_DEBUG:      return brig.debugChunks().getData(0);
        default:
            assert(false);
            return 0;
        }
    }

    unsigned getSectionSize(int section) const
    {
        switch(section) {
        case BRIG_SEC_STRTAB:     return (unsigned)brig.strings().size();
        case BRIG_SEC_DIRECTIVES: return (unsigned)brig.directives().size();
        case BRIG_SEC_CODE:       return (unsigned)brig.insts().size();
        case BRIG_SEC_OPERANDS:   return (unsigned)brig.operands().size();
        case BRIG_SEC_DEBUG:      return (unsigned)brig.debugChunks().size();
        default:
            assert(false);
            return 0;
        }
    }

    const SourceInfo* getSourceInfo(int section, unsigned offset) const
    {
        if (section == BRIG_SEC_DIRECTIVES && offset >= BRIG_NUM_BYTES_RESERVED)
        {
            return brig.directives().sourceInfo(offset);
        }
        else if (section == BRIG_SEC_CODE && offset >= BRIG_NUM_BYTES_RESERVED)
        {
            return brig.insts().sourceInfo(offset);
        }
        else if (section == BRIG_SEC_OPERANDS && offset >= BRIG_NUM_BYTES_RESERVED)
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

    void validate(Directive d, bool cond, SRef msg) const
    {
        assert(d);
        if (!cond) throw BrigFormatError(BRIG_SEC_DIRECTIVES, d.brigOffset(), msg);
    }

    void validate(Inst inst, bool cond, SRef msg) const
    {
        assert(inst);
        if (!cond) throw BrigFormatError(BRIG_SEC_CODE, inst.brigOffset(), msg);
    }

    void validate(Operand opr, bool cond, SRef msg) const
    {
        assert(opr);
        if (!cond) throw BrigFormatError(BRIG_SEC_OPERANDS, opr.brigOffset(), msg);
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
        /*
        if (DumpFormatError)
        {
            s << '\n';
            if (section == BRIG_SEC_DIRECTIVES && offset >= BRIG_NUM_BYTES_RESERVED)
            {
                Directive d(&brig, offset);
                //F
                // TBD!!! d.dump(s);
            }
            else if (section == BRIG_SEC_CODE && offset >= BRIG_NUM_BYTES_RESERVED)
            {
                Inst i(&brig, offset);
                //F
                // TBD!!! i.dump(s);
            }
            else if (section == BRIG_SEC_OPERANDS && offset >= BRIG_NUM_BYTES_RESERVED)
            {
                Operand o(&brig, offset);
                //F
                // TBD!!! o.dump(s);
            }
        }
        */
        return s.str();
    }

    //-------------------------------------------------------------------------

    void ValidateInstFields(Inst sect) const;
    void ValidateOperandFields(Operand sect) const;
    void ValidateDirectiveFields(Directive sect) const;

    //-------------------------------------------------------------------------

    unsigned getMachineType() const
    {
        return (machineModel == Brig::BRIG_MACHINE_SMALL)? Brig::BRIG_TYPE_B32 : Brig::BRIG_TYPE_B64;
    }

    bool isLargeModel() const { return machineModel == Brig::BRIG_MACHINE_LARGE; }


}; // class ValidatorImpl

// ============================================================================
// Public Validator API

Validator::Validator(BrigContainer &c) { impl = new ValidatorImpl(c); }
Validator::~Validator()                { delete impl; }

bool   Validator::validate(ValidationMode vMode) const { return impl->validate(vMode); }
string Validator::getErrorMsg(istream *is)       const { return impl->getErrorMsg(is); }
int    Validator::getErrorCode()                 const { return impl->getErrorCode(); }

void Validator::validate(Inst inst, int operandIdx, SRef msg, bool cond)
{
    assert(inst);

    if (!cond)
    {

        int code = BrigFormatError::ERRCODE_INST;
        if (0 <= operandIdx && operandIdx <= 4 && inst.operand(operandIdx)) {
            Operand opr = inst.operand(operandIdx);
            throw BrigFormatError(BRIG_SEC_OPERANDS, opr.brigOffset(), msg, code);
        } else {
            throw BrigFormatError(BRIG_SEC_CODE, inst.brigOffset(), msg, code);
        }
    }
}

// ============================================================================
} // HSAIL_ASM namespace

// ============================================================================

namespace HSAIL_ASM {

    void ValidatorImpl::ValidateDirectiveFields(Directive dir) const
    {
        using namespace Brig;

        unsigned kind = dir.brig()->kind;

        switch (kind)
        {
        case BRIG_DIRECTIVE_ARG_SCOPE_END:
            {
                DirectiveArgScopeEnd d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectiveArgScopeEnd", "code", false, true);
            }
            break;

        case BRIG_DIRECTIVE_ARG_SCOPE_START:
            {
                DirectiveArgScopeStart d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectiveArgScopeStart", "code", false, true);
            }
            break;

        case BRIG_DIRECTIVE_BLOCK_END:
            {
                // Nothing to validate
            }
            break;

        case BRIG_DIRECTIVE_BLOCK_NUMERIC:
            {
                BlockNumeric d = dir;

                validate_DataType(dir, d.brig()->type);
                validate_Reserved(dir, d.brig()->reserved);

                // This is a variable-size structure
                // Validation of trailing data is done on next steps
            }
            break;

        case BRIG_DIRECTIVE_BLOCK_START:
            {
                BlockStart d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectiveBlockStart", "code", false, true);
                validate_sOffset(dir, d.brig()->name, "DirectiveBlockStart", "name");
            }
            break;

        case BRIG_DIRECTIVE_BLOCK_STRING:
            {
                BlockString d = dir;

                validate_sOffset(dir, d.brig()->string, "DirectiveBlockString", "string");
            }
            break;

        case BRIG_DIRECTIVE_COMMENT:
            {
                DirectiveComment d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectiveComment", "code", false, true);
                validate_sOffset(dir, d.brig()->name, "DirectiveComment", "name");
            }
            break;

        case BRIG_DIRECTIVE_CONTROL:
            {
                DirectiveControl d = dir;

                validate_cOffset    (dir, d.brig()->code, "DirectiveControl", "code", false, true);
                validate_ControlType(dir, d.brig()->control);
                validate_DataType   (dir, d.brig()->type);
                validate_Reserved   (dir, d.brig()->reserved);

                // This is a variable-size structure
                // Validation of trailing data is done on next steps
            }
            break;

        case BRIG_DIRECTIVE_EXTENSION:
            {
                DirectiveExtension d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectiveExtension", "code", false, true);
                validate_sOffset(dir, d.brig()->name, "DirectiveExtension", "name");
            }
            break;

        case BRIG_DIRECTIVE_FBARRIER:
            {
                DirectiveFbarrier d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectiveFbarrier", "code", false, true);
                validate_sOffset(dir, d.brig()->name, "DirectiveFbarrier", "name");
            }
            break;

        case BRIG_DIRECTIVE_FILE:
            {
                DirectiveFile d = dir;

                validate_cOffset(dir, d.brig()->code,     "DirectiveFile", "code", false, true);
                validate_sOffset(dir, d.brig()->filename, "DirectiveFile", "filename");
                validate        (dir, d.brig()->fileid > 0, "Invalid DirectiveFile; file id must be positive");
            }
            break;

        case BRIG_DIRECTIVE_FUNCTION:
        case BRIG_DIRECTIVE_KERNEL:
            {
                DirectiveExecutable d = dir;
                const char* structName = (kind == BRIG_DIRECTIVE_KERNEL)? "DirectiveKernel" : "DirectiveFunction";

                validate_cOffset  (dir, d.brig()->code,                  structName, "code", false, true);
                validate_sOffset  (dir, d.brig()->name,                  structName, "name");
                validate_dOffset  (dir, d.brig()->firstInArg,            structName, "firstInArg",            false, true);
                validate_dOffset  (dir, d.brig()->firstScopedDirective,  structName, "firstScopedDirective",  false, true);
                validate_dOffset  (dir, d.brig()->nextTopLevelDirective, structName, "nextTopLevelDirective", false, true);
                validate_ExecMod  (dir, d.brig()->modifier.allBits);
                validate_Reserved (dir, d.brig()->reserved[0]);
                validate_Reserved (dir, d.brig()->reserved[1]);
                validate_Reserved (dir, d.brig()->reserved[2]);
            }
            break;

        case BRIG_DIRECTIVE_VARIABLE:
        case BRIG_DIRECTIVE_SAMPLER:
        case BRIG_DIRECTIVE_IMAGE:
            {
                DirectiveSymbol d = dir;

                const char* structName = (kind == BRIG_DIRECTIVE_VARIABLE)?
                                             "DirectiveVariable" :
                                             ((kind == BRIG_DIRECTIVE_SAMPLER)?
                                                "DirectiveSampler" :
                                                "DirectiveImage");

                validate_cOffset  (dir, d.brig()->code, structName, "code", false, true);
                validate_sOffset  (dir, d.brig()->name, structName, "name");
                validate_dOffset  (dir, d.brig()->init, structName, "init", true);
                validate_DataType (dir, d.brig()->type);
                validate_Alignment(dir, d.brig()->align);
                validate_Segment  (dir, d.brig()->segment);
                validate_SymMod   (dir, d.brig()->modifier.allBits);
                validate_Reserved (dir, d.brig()->reserved[0]);
                validate_Reserved (dir, d.brig()->reserved[1]);
                validate_Reserved (dir, d.brig()->reserved[2]);
            }
            break;

        case BRIG_DIRECTIVE_IMAGE_INIT:
            {
                DirectiveImageInit d = dir;

                validate_cOffset    (dir, d.brig()->code, "DirectiveImageInit", "code", false, true);
                validate            (dir, d.brig()->array > 0, "Invalid image initializer; 'array' value must be positive");
                validate_ImageOrder (dir, d.brig()->order);
                validate_ImageFormat(dir, d.brig()->format);
                validate_Reserved   (dir, d.brig()->reserved);
            }
            break;

        case BRIG_DIRECTIVE_LABEL:
            {
                DirectiveLabel d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectiveLabel", "code", false, true);
                validate_sOffset(dir, d.brig()->name, "DirectiveLabel", "name");
            }
            break;

        case BRIG_DIRECTIVE_LABEL_TARGETS:
        case BRIG_DIRECTIVE_LABEL_INIT:
            {
                DirectiveLabelList d = dir;
                const char* structName = (kind == BRIG_DIRECTIVE_LABEL_INIT)? "DirectiveLabelInit" : "DirectiveLabelTargets";

                validate_cOffset (dir, d.brig()->code, structName, "code", false, true);
                validate_dOffset (dir, d.brig()->label, structName, "label", true);
                validate_Reserved(dir, d.brig()->reserved);

                // This is a variable-size structure
                // Validation of d_labels is done on next steps
            }
            break;

        case BRIG_DIRECTIVE_LOC:
            {
                DirectiveLoc d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectiveLoc", "code", false, true);
                validate(dir, d.brig()->fileid > 0, "Invalid DirectiveLoc; file id must be positive");
            }
            break;

        case BRIG_DIRECTIVE_PRAGMA:
            {
                DirectivePragma d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectivePragma", "code", false, true);
                validate_sOffset(dir, d.brig()->name, "DirectivePragma", "name");
            }
            break;

        case BRIG_DIRECTIVE_SAMPLER_INIT:
            {
                DirectiveSamplerInit d = dir;

                validate_SamplerModifier(dir, d.brig()->modifier.allBits);
                validate_SamplerBoundary(dir, d.boundaryU());
                validate_SamplerBoundary(dir, d.boundaryV());
                validate_SamplerBoundary(dir, d.boundaryW());
            }
            break;

        case BRIG_DIRECTIVE_SCOPE: //F Looks like this value is unused and should be deleted
            assert(false);
            break;

        case BRIG_DIRECTIVE_SIGNATURE:
            {
                DirectiveSignature d = dir;

                validate_cOffset(dir, d.brig()->code, "DirectiveSignature", "code", false, true);
                validate_sOffset(dir, d.brig()->name, "DirectiveSignature", "name");

                // This is a variable-size structure
                // Validation of types is done on next steps
            }
            break;

        case BRIG_DIRECTIVE_VARIABLE_INIT:
            {
                DirectiveVariableInit d = dir;

                validate_cOffset (dir, d.brig()->code, "DirectiveVariableInit", "code", false, true);
                validate_sOffset (dir, d.brig()->data, "DirectiveVariableInit", "data");
                validate_DataType(dir, d.brig()->type);
                validate_Reserved(dir, d.brig()->reserved);

                // This is a variable-size structure
                // Validation of data is done on next steps
            }
            break;

        case BRIG_DIRECTIVE_VERSION:
            {
                DirectiveVersion d = dir;

                validate_cOffset (dir, d.brig()->code, "DirectiveVersion", "code", false, true);
                validate_Machine (dir, d.brig()->machineModel);
                validate_Profile (dir, d.brig()->profile);
                validate_Reserved(dir, d.brig()->reserved);

                // Version numbers are validated separately
            }
            break;

        default:
            validate(dir, false, "Invalid directive kind");

        } // switch

    } // ValidateDirectiveFields

    void ValidatorImpl::ValidateOperandFields(Operand opr) const
    {
        using namespace Brig;

        switch (opr.brig()->kind)
        {

        case BRIG_OPERAND_IMMED:
            {
                OperandImmed o = opr;

                validate_DataType(opr, o.brig()->type);

                // This is a variable-size structure
                // Validation of data is done on next steps
            }
            break;

        case BRIG_OPERAND_WAVESIZE:
            {
                OperandWavesize o = opr;

                validate_DataType(opr, o.brig()->type);
                validate_Reserved(opr, o.brig()->reserved);
            }
            break;

        case BRIG_OPERAND_REG:
            {
                OperandReg o = opr;

                validate_sOffset (opr, o.brig()->reg, "OperandReg", "reg");
                validate_DataType(opr, o.brig()->type);
                validate_Reserved(opr, o.brig()->reserved);
            }
            break;

        case BRIG_OPERAND_REG_VECTOR:
            {
                OperandRegVector o = opr;

                validate_DataType(opr, o.brig()->type);

                // This is a variable-size structure
                // Validation of data is done on next steps
            }
            break;

        case BRIG_OPERAND_ADDRESS:
            {
                OperandAddress o = opr;

                validate_dOffset (opr, o.brig()->symbol, "OperandAddress", "symbol", true);
                validate_sOffset (opr, o.brig()->reg,    "OperandAddress", "reg",    true);
                validate_DataType(opr, o.brig()->type);
                validate_Reserved(opr, o.brig()->reserved);
            }
            break;

case BRIG_OPERAND_ARGUMENT_REF: assert(false); break;

        case BRIG_OPERAND_LABEL_REF:      { OperandRef o = opr; validate_dOffset(opr, o.brig()->ref, "OperandLabelRef",     "ref"); } break;
        case BRIG_OPERAND_FUNCTION_REF:   { OperandRef o = opr; validate_dOffset(opr, o.brig()->ref, "OperandFunctionRef",  "ref"); } break;
        case BRIG_OPERAND_SIGNATURE_REF:  { OperandRef o = opr; validate_dOffset(opr, o.brig()->ref, "OperandSignatureRef", "ref"); } break;
        case BRIG_OPERAND_FBARRIER_REF:   { OperandRef o = opr; validate_dOffset(opr, o.brig()->ref, "OperandFbarrierRef",  "ref"); } break;


        case BRIG_OPERAND_ARGUMENT_LIST:
        case BRIG_OPERAND_FUNCTION_LIST:
            {
                OperandList o = opr;

                validate_Reserved(opr, o.brig()->reserved);

                // This is a variable-size structure
                // Validation of data is done on next steps
            }
            break;

        default:
            validate(opr, false, "Invalid operand kind");
        } // switch

    } // ValidateOperandFields

    void ValidatorImpl::ValidateInstFields(Inst inst) const
    {
        using namespace Brig;

        for (int i = 0; i < 5; ++i)
        {
            validate_oOffset(inst, inst.brig()->operands[i], "Inst", "operands[*]", true);
        }

        switch (inst.brig()->kind)
        {
        case BRIG_INST_BASIC:
            {
                InstBasic it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
            }
            break;

        case BRIG_INST_ATOMIC:
            {
                InstAtomic it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_Segment (inst, it.brig()->segment);
                validate_MemSem  (inst, it.brig()->memorySemantic);
                validate_AtomicOp(inst, it.brig()->atomicOperation);
                validate_Reserved(inst, it.brig()->reserved);
            }
            break;

        case BRIG_INST_ATOMIC_IMAGE:
            {
                InstAtomicImage it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_DataType(inst, it.brig()->imageType);
                validate_DataType(inst, it.brig()->coordType);
                validate_Geom    (inst, it.brig()->geometry);
                validate_AtomicOp(inst, it.brig()->atomicOperation);
                validate_Reserved(inst, it.brig()->reserved);
            }
            break;

        case BRIG_INST_CVT:
            {
                InstCvt it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_DataType(inst, it.brig()->sourceType);
                validate_AluMod  (inst, it.brig()->modifier.allBits);
            }
            break;

        case BRIG_INST_BAR:
            {
                InstBar it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_Fence   (inst, it.brig()->memoryFence);
                validate_Width   (inst, it.brig()->width);
                validate_Reserved(inst, it.brig()->reserved);
            }
            break;

        case BRIG_INST_BR:
            {
                InstBr it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_AluMod  (inst, it.brig()->modifier.allBits);
                validate_Width   (inst, it.brig()->width);
                validate_Reserved(inst, it.brig()->reserved);
            }
            break;

        case BRIG_INST_CMP:
            {
                InstCmp it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_DataType(inst, it.brig()->sourceType);
                validate_AluMod  (inst, it.brig()->modifier.allBits);
                validate_CmpOp   (inst, it.brig()->compare);
                validate_Packing (inst, it.brig()->pack);
                validate_Reserved(inst, it.brig()->reserved);
            }
            break;

        case BRIG_INST_FBAR:
            {
                InstFbar it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_Fence   (inst, it.brig()->memoryFence);
                validate_Width   (inst, it.brig()->width);
                validate_Reserved(inst, it.brig()->reserved);
            }
            break;

        case BRIG_INST_IMAGE:
            {
                InstImage it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_DataType(inst, it.brig()->imageType);
                validate_DataType(inst, it.brig()->coordType);
                validate_Geom    (inst, it.brig()->geometry);
                validate_Reserved(inst, it.brig()->reserved[0]);
                validate_Reserved(inst, it.brig()->reserved[1]);
                validate_Reserved(inst, it.brig()->reserved[2]);
            }
            break;

        case BRIG_INST_MEM:
            {
                InstMem it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_Segment (inst, it.brig()->segment);
                validate_MemMod  (inst, it.brig()->modifier.allBits);
                validate_Width   (inst, it.brig()->width);
            }
            break;

        case BRIG_INST_ADDR:
            {
                InstAddr it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_Segment (inst, it.brig()->segment);
                validate_Reserved(inst, it.brig()->reserved[0]);
                validate_Reserved(inst, it.brig()->reserved[1]);
                validate_Reserved(inst, it.brig()->reserved[2]);
            }
            break;

        case BRIG_INST_MOD:
            {
                InstMod it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_AluMod  (inst, it.brig()->modifier.allBits);
                validate_Packing (inst, it.brig()->pack);
                validate_Reserved(inst, it.brig()->reserved);
            }
            break;

        case BRIG_INST_SEG:
            {
                InstSeg it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_DataType(inst, it.brig()->sourceType);
                validate_Segment (inst, it.brig()->segment);
                validate_Reserved(inst, it.brig()->reserved);
            }
            break;

        case BRIG_INST_SOURCE_TYPE:
            {
                InstSourceType it = inst;

                validate_Opcode  (inst, it.brig()->opcode);
                validate_DataType(inst, it.brig()->type);
                validate_DataType(inst, it.brig()->sourceType);
                validate_Reserved(inst, it.brig()->reserved);
            }
            break;

        default:
            validate(inst, false, "Invalid instruction kind");
        } // switch

    } // ValidateInstFields

} // HSAIL_ASM namespace


//F EXTENSIONS:
//F - BrigImageFormat: Values 16 through 64 are available for extensions
//F - BrigImageGeometry: Values 6 through 255 are available for extensions
//F - BrigImageOrder: Values 17 through 255 are available for extensions
//F - BrigSamplerBoundaryMode: Values 5 through 255 are available for extensions.
//F - BrigSamplerCoord: Values 5 through 255 are available for extensions.
//F - BrigSamplerFilter: Values 2 through 63 are available for extensions
//F - BrigSegment: Values 9 through 16 are available for extensions
//F MISC:
//F - Src operand of stof and ftos can no longer be WAVESIZE

//F TODO
//F validate new flags such as isDecl (their correlation with other props) ::: create random BRIG tests on all combinations of flags

//F POSTPONED FEATURES
//F The s, d, and q registers in HSAIL share a single pool of resources.
//F add support of querysamplerboundary (added in April)


//F MINOR PENDING FEATURES
//F - nop
//F - The s, d, and q registers in HSAIL share a single pool of resources.
//F - Section  Header: The first entry in every section must be BrigSectionHeader, which consists of a 32-bit word that is the byte size of the section.

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
