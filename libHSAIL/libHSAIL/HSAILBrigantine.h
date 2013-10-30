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
#ifndef INCLUDED_HSAIL_BRIGANTINE_H
#define INCLUDED_HSAIL_BRIGANTINE_H

#include "HSAILScanner.h" // TBD remove - Optional
#include "HSAILUtilities.h"
#include "HSAILBrigContainer.h"
#include "HSAILItems.h"
#include "HSAILScope.h"

#include <memory>
#include <map>
#include <vector>

/// @defgroup Directives


namespace HSAIL_ASM
{

/// BRIG creator class. Methods of this class form HSAIL program
/// writing corresponding Brig entities to an input BrigContainer.
class Brigantine
{
    BrigContainer&          m_container;
    std::auto_ptr<Scope>    m_globalScope;
    std::auto_ptr<Scope>    m_funcScope;
    std::auto_ptr<Scope>    m_argScope;
    DirectiveExecutable     m_func;
    unsigned                m_machine;

    typedef std::vector< std::pair< ItemRef<DirectiveLabel>, SourceInfo > > RefList;
    typedef std::map<Brig::BrigStringOffset32_t, RefList> LabelMap;

    LabelMap m_labelMap; // string offset -> array of label refs

    Brigantine& operator=(const Brigantine&);

public:
    /// create Brigantine object with input BrigContainer.
    /// @param container - the container to store Brig in.
    /// Note that Brigantine is unaware of contents of the specified container and
    /// won't syncronize it's state with it and therefore it is up to the user to
    /// supply the container in a state that allows to 'continue' writing consistently.
    /// Most common case is an empty Brig container.
    Brigantine(BrigContainer& container) : m_container(container), m_machine(0) {}
    virtual ~Brigantine() {}

    /// start HSAIL program. While it doesn't write anything to the container it
    /// prepares Brigantine's state to begin Brig emitting.
    void startProgram();
    /// end HSAIL program.
    /// Perform Brigantine's state cleanup.
    void endProgram();

    /// @name Directives
    /// @{

    /// emit DirectiveVersion to the container. Should be called after startProgram call.
    /// @param major - major version number
    /// @param minor - minor version number
    /// @param machineModel - one of Brig::BrigMachineModel enum values
    /// @param profile - one of Brig::BrigProfile enum values
    /// @param srcInfo - (optional) source location
    DirectiveVersion version(unsigned short major,unsigned short minor,
        Brig::BrigMachineModel8_t machineModel,Brig::BrigProfile8_t profile,
        const SourceInfo* srcInfo=NULL);

    /// emit DirectiveFunction to the container.
    /// @param name - function name, should include '&' in front.
    /// @param declPfx - declaration prefix (see struct DeclPrefix)
    /// @param srcInfo - (optional) source location
    DirectiveFunction declFunc(const SRef& name,const SourceInfo* srcInfo=NULL);

    /// emit DirectiveKernel to the container.
    /// @param name - kernel name, should include '&' in front.
    /// @param declPfx - declaration prefix (see struct DeclPrefix)
    /// @param srcInfo - (optional) source location
    DirectiveKernel declKernel(const SRef& name,const SourceInfo* srcInfo=NULL);

    /// emit DirectiveSignature to the container.
    /// @param name - prototype name, should include '&' in front.
    /// @param srcInfo - (optional) source location
    DirectiveSignature declSignature(const SRef& name, const SourceInfo* srcInfo=NULL);

    /// add output param to function. Should be called after declFunc
    /// and before startBody.
    /// @param sym - symbol directive, returned from addSymbol
    void addOutputParameter(DirectiveVariable sym);

    /// add input param to function/kernel. Should be called after declFunc/declKernel
    /// and before startBody.
    /// @param sym - symbol directive, returned from addSymbol
    void addInputParameter(DirectiveVariable sym);

    /// start function/kernel body.
    ///
    void startBody();

    /// end function/kernel body.
    ///
    bool endBody();

    /// start argument scope.
    /// @param srcInfo - (optional) source location
    DirectiveArgScopeStart startArgScope(const SourceInfo* srcInfo=NULL);

    /// end argument scope.
    /// @param srcInfo - (optional) source location
    DirectiveArgScopeEnd endArgScope(const SourceInfo* srcInfo=NULL);

    /// @}


    /// @name Symbols
    /// emit DirectiveVariable.
    /// @param name - symbol name
    /// @param srcInfo - (optional) source location
    /// @{

    DirectiveVariable   addSymbol(DirectiveVariable sym);

    DirectiveVariable addVariable(const SRef& name, Brig::BrigSegment8_t segment, unsigned dType,const SourceInfo* srcInfo=NULL);
    DirectiveVariable addArrayVariable(const SRef& name, uint64_t size, Brig::BrigSegment8_t segment, unsigned dType,const SourceInfo* srcInfo=NULL);

    DirectiveVariable addImage   (const SRef& name, Brig::BrigSegment8_t segment=Brig::BRIG_SEGMENT_GLOBAL, const SourceInfo* srcInfo=NULL);
    DirectiveVariable addSampler (const SRef& name, Brig::BrigSegment8_t segment=Brig::BRIG_SEGMENT_GLOBAL, const SourceInfo* srcInfo=NULL);

    DirectiveFbarrier addFbarrier(const SRef& name,const SourceInfo* srcInfo=NULL);

    /// emit DirectiveVariableInit.
    /// @param type - Brig type of values stored in the initializer, should match type
    /// of symbol
    /// @param srcInfo - (optional) source location
    DirectiveVariableInit createVariableInitializer(Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    DirectiveImageInit    createImageInitializer(const SourceInfo* srcInfo=NULL);
    DirectiveSamplerInit  createSamplerInitializer(const SourceInfo* srcInfo=NULL);

    /// append trailing zeroes to a symbol initializer. This is required by spec to match
    /// initializer size with declared dimension of symbol. If the symbol doesn't have associated initializer
    /// this routine creates one with type specified for the symbol. For nonarray symbols single zero value
    /// initializer is created.
    /// @param sym - DirectiveVariable. 
    void             appendTrailingZeroes(DirectiveVariable sym);

    /// @}

    /// emits DirectiveLabel. Should be called before instruction the label refer.
    /// This method also resolves all forward references to the label name.
    /// @param name - label name.
    DirectiveLabel   addLabel(const SRef& name,const SourceInfo* srcInfo=NULL);

    DirectiveLabelInit    createLabelInit(const SourceInfo* srcInfo=NULL);
    DirectiveLabelTargets createLabelTargets(const SRef& labelName, const SourceInfo* srcInfo=NULL);

    /// append label reference to the label list.
    /// @param list - list of label references.
    /// @param name - name of label being referenced, can be forward reference
    /// (this is label with the name is not created yet)
    /// @param srcInfo - (optional) source location.
    bool             appendLabelRef(LabelTargetsList list,const SRef& name, const SourceInfo* srcInfo=NULL);
    bool             appendLabelRef(LabelInitList list,const SRef& name, const SourceInfo* srcInfo=NULL);

private:
    template <typename List> bool appendLabelRef(List list,const SRef& name, const SourceInfo* srcInfo);

public:

    /// emit comment for the following instruction.
    /// @param comment - any text.
    /// @param srcInfo - (optional) source location.
    DirectiveComment addComment(const char *comment,const SourceInfo* srcInfo=NULL);

    /// emit extension for the following instruction.
    /// @param name - any text.
    /// @param srcInfo - (optional) source location.
    DirectiveLabel   addExtension(const char *name,const SourceInfo* srcInfo=NULL);

    // TBD make private
    template <typename Dir>
    Dir              createCodeRefDir(const SourceInfo* srcInfo=NULL);

    // TBD095 replace with addSampler, createSamplerInitializer
    /*void CreateSampler(const SRef& name,const int normalized,const Brig::BrigSamplerFilter filter,
                       const Brig::BrigSamplerBoundaryMode mode);*/

    /// @name Instructions
    /// emit instruction.
    /// @param InstItem - type of instruction brig item.
    /// @param opCode - instruction opcode.
    /// @param type - Brig type.
    /// @param srcInfo - (optional) source location.
    /// @{
    template <typename InstItem>
    InstItem addInst(unsigned opCode, const SourceInfo* srcInfo=NULL);

    template <typename InstItem>
    InstItem addInst(unsigned opCode, unsigned type, const SourceInfo* srcInfo=NULL);

    Inst addNop(const SourceInfo* srcInfo=NULL);
    /// @}


    void setOperand(Inst inst, int i, Operand opnd);
    void setOperandEx(Inst inst, int i, Operand opnd);
    void appendOperand(Inst inst, Operand opnd);

    /// @name Register operands
    /// emit OperandReg.
    /// @param name - register name including '$'.
    /// @param srcInfo - (optional) source location.
    OperandReg          createOperandReg(const SRef& name, const SourceInfo* srcInfo=NULL);

    /// @name Register vectors
    /// emit OperandRegVx.
    /// @param o1..o4 - registers.
    /// @param srcInfo - (optional) source location.
    /// @{
    OperandRegVector    createOperandRegVec(std::string o[],unsigned num,const SourceInfo* srcInfo=NULL);
    /// @}

    /// @name Argument list
    /// emit list of OperandArgumentRef.
    /// @param list - ItemRange of OperandArgumentRef.
    /// @param Iterator - type of iterator that supply OperandArgumentRef.
    /// @param from - begin iterator
    /// @param till - end iterator
    /// @param srcInfo - (optional) source location.
    /// @{
    OperandArgumentList createArgList(const SourceInfo* srcInfo=NULL);
    /*OperandArgumentList createArgList(const ItemRange<DirectiveVariable>& list, const SourceInfo* srcInfo=NULL);*/
    template <typename Iterator>
    OperandArgumentList createArgList(Iterator from, Iterator till, const SourceInfo* srcInfo=NULL);
    /// @}

    OperandFunctionList createFuncList(const SourceInfo* srcInfo);

    /// emit operand that reference label by name. Can reference forward labels. References to forward
    /// labels are recorded by brigantine and resolved at the moment when label created.
    /// @param labelName - label name
    /// @param srcInfo - (optional) source location.
    Operand             createLabelRef(const SRef& labelName, const SourceInfo* srcInfo=NULL);

    /// @name Function references
    /// emit function reference. Used for calls.
    /// @param fn - DirectiveFunction.
    /// @param fnName - function name including '&' (global name search)
    /// @param srcInfo - (optional) source location.
    /// @{
    OperandFunctionRef  createFuncRef(DirectiveFunction fn, const SourceInfo* srcInfo=NULL);
    OperandFunctionRef  createFuncRef(const SRef& fnName, const SourceInfo* srcInfo=NULL);
    /// @}

    /// @name Function signature references
    /// emit function signature reference. Used for indirect calls.
    /// @param sig - DirectiveSignature.
    /// @param fnName - signature name including '&' (global name search)
    /// @param srcInfo - (optional) source location.
    /// @{
    OperandSignatureRef  createSigRef(DirectiveSignature sig, const SourceInfo* srcInfo=NULL);
    OperandSignatureRef  createSigRef(const SRef& fnName, const SourceInfo* srcInfo=NULL);
    /// @}

    /// emit function reference list. Used for indirect calls to enumerate possible call targets.
    /// @param list - ItemRange of Operand.
    /// @param srcInfo - (optional) source location.
    //OperandFunctionList createOperandFunctionList(const ItemRange<DirectiveFunction>& list, const SourceInfo* srcInfo=NULL);

    /// @name Immediate value creators.
    /// Group of methods that create operand with immediate value v converting it to the specified 'type',
    /// using setImmed function.
    /// Each method has:
    /// @param v - immediate value.
    /// @param type - Brig type for the value.
    /// @param srcInfo - (optional) source location.
    /// @{
    OperandImmed       createImmed(int8_t   v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(int16_t  v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(int32_t  v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(int64_t  v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(uint8_t  v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(uint16_t v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(uint32_t v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(uint64_t v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(f32_t    v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(f64_t    v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    OperandImmed       createImmed(const void * v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);
    /// @}

    /// creates unitialized OperandImmed.
    /// @param srcInfo - (optional) source location
    OperandImmed       createImmed(const SourceInfo* srcInfo=NULL);

    /// @name Memory access operands creators.

    /// generic memory access operand creator.
    /// @param symName - name for symbol including '&' or '%' (optional).
    /// @param reg - name for register including '$' (optional).
    /// @param offset - offset (optional, that is 0).
    /// @param srcInfo - (optional) source location.
    /// at least one of symName,reg, offset should be supplied upon call.
    OperandAddress     createRef(const SRef& symName, const SRef& reg, int64_t offset=0, const SourceInfo* srcInfo=NULL);
    OperandAddress     createRef(const SRef& symName, int64_t offset=0, const SourceInfo* srcInfo=NULL) {
        return createRef(symName, SRef(), offset, srcInfo);
    }

    OperandRef         createDirectiveRef(const SRef& name,const SourceInfo* srcInfo=NULL);
    OperandRef         createDirectiveRef(Directive d,const SourceInfo* srcInfo=NULL);

    /// create 'width' operand.
    /// @param srcInfo - (optional) source location.
    OperandImmed       createWidthOperand(const Optional<uint32_t>& width,const SourceInfo* srcInfo=NULL);

    /// create 'Wavesize' operand.
    /// @param srcInfo - (optional) source location.
    OperandWavesize    createWaveSz(Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);

    /// @name Miscelaneous members
    /// @{
    BrigContainer& container() const { return m_container; } // TBD remove direct refs to this from parser code

    /// return current local scope. Can be argument scope or function scope.
    /// Returns NULL if called outside of function or kernel scope.
    Scope*         localScope() const {
        return m_argScope.get()!=NULL ? m_argScope.get() : m_funcScope.get();
    }

    /// search a name starting from innermost scope to outermost.
    /// @param Dir - cast found symbol to this type.
    /// @param name - name including '&' or '%'.
    template <typename Dir>
    Dir            findInScopes(const SRef& name) const;

    /// return model.
    unsigned       getMachineType() const;

    /// store DWARF data.
    /// @param dwarfData - data.
    /// @param dwarfDataSize - size.
    void           storeDWARF(const void* dwarfData, size_t dwarfDataSize);

    /// store DWARF data.
    /// @param dwarf - vector of data
    template <typename T>
    void           storeDWARF(const std::vector<T>& dwarf);
    /// @}

    DataItem       createData();

private:
    Inst addInst(Inst i);

    template <typename Item>
    static void annotate(Item i, const SourceInfo* srcInfo) {
        if (srcInfo) {
            i.annotate(*srcInfo);
        }
    }

    DirectiveExecutable declFuncCommon(DirectiveExecutable func, const SRef& name, const SourceInfo* srcInfo);

    void addSymbolToLocalScope(DirectiveVariable sym);
    void addSymbolToFunctionScope(DirectiveVariable sym);
    void addSymbolToGlobalScope(DirectiveExecutable sym);
    void addSymbolToGlobalScope(DirectiveVariable sym);

    bool checkForUnboundLabels();
    void recordLabelRef(ItemRef<DirectiveLabel> ref, const SRef& name, const SourceInfo*);
    void patchLabelRefs(DirectiveLabel label);

    DirectiveLabel addLabelInternal(const SRef& name,const SourceInfo* srcInfo);

    template <typename Value> // this routine converts Value v to the requested brig type and save it into immediate
    OperandImmed createImmedT(Value v, Brig::BrigType16_t type, const SourceInfo* srcInfo=NULL);

    void brigWriteError(const char *errMsg, const SourceInfo* srcInfo);

    virtual void handleError(const SyntaxError& e);
};

/// version of Brigantine class that doesnt throw exceptions.
class BrigantineNoEx : public Brigantine
{
public:
    BrigantineNoEx(BrigContainer& container) : Brigantine(container), m_err(NULL) {}
    const SyntaxError* getLastError() const { return m_err; }
    void clearLastError() { m_err = NULL; }
private:
    const SyntaxError* m_err;
    SyntaxError m_errHolder;
    virtual void handleError(const SyntaxError& e);
};

inline bool isGlobalName(const char* name) {
    return name[0]=='&';
}

inline bool isGlobalName(const SRef& name) {
    return name.begin[0]=='&';
}

inline bool isLocalName(const char *name) {
    return name[0]=='%';
}

inline bool isLocalName(const SRef& name) {
    return name.begin[0]=='%';
}

template <typename S>
S Brigantine::findInScopes(const SRef& name) const {
    // TBD check name len and validity
    if (isGlobalName(name)) {
        return m_globalScope->get<S>(name);
    }
    S res;
    if (m_argScope.get()!=NULL) {
        res = m_argScope->get<S>(name);
    }
    if (!res) {
        assert(m_funcScope.get()!=NULL);
        res = m_funcScope->get<S>(name);
    }
    return res;
}

template <typename Dir>
Dir Brigantine::createCodeRefDir(const SourceInfo* srcInfo)
{
    Dir d = m_container.append<Dir>();
    annotate(d,srcInfo);
    d.code() = m_container.insts().end();
    return d;
}

template <typename InstItem>
InstItem Brigantine::addInst(unsigned opCode,const SourceInfo* srcInfo) {
    InstItem inst = m_container.append<InstItem>();
    annotate(inst,srcInfo);
    inst.opcode() = opCode;
    inst.type() = Brig::BRIG_TYPE_B32;
    return addInst(inst);
}

template <typename InstItem>
InstItem Brigantine::addInst(unsigned opCode,unsigned type,const SourceInfo* srcInfo) {
    InstItem inst = addInst<InstItem>(opCode,srcInfo);
    inst.type() = type;
    return inst;
}

template<typename T> inline
void Brigantine::storeDWARF(const std::vector<T>& dwarf) {
    if (!dwarf.empty()) {
        storeDWARF(&dwarf[0], dwarf.size() * sizeof(T));
    }
}

template <typename Iterator>
OperandArgumentList Brigantine::createArgList(Iterator from, Iterator till,const SourceInfo* srcInfo)
{
    OperandArgumentList list = m_container.append<OperandArgumentList>();
    annotate(list,srcInfo);
    Offset const size = (Offset)std::distance(from,till);
    if (size != list.elements().resize(size)) {
        brigWriteError("OperandArgumentList overflow", srcInfo);
    }

    Offset i = 0;
    Iterator a = from;
    while (a!=till) {
        list.elements(i++) = *a++;
    }
    return list;
}

inline int getOperandsNum(Inst inst)
{
    int i=0;
    while (i<5 && inst.operand(i)) ++i;
    return i;
}


}

#endif
