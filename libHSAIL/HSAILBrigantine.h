// University of Illinois/NCSA
// Open Source License
//
// Copyright (c) 2013-2015, Advanced Micro Devices, Inc.
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
    std::unique_ptr<Scope>    m_globalScope;
    std::unique_ptr<Scope>    m_funcScope;
    std::unique_ptr<Scope>    m_argScope;
    DirectiveExecutable     m_func;
    unsigned                m_machine;
    unsigned                m_profile;

    typedef std::vector< std::pair< ItemRef<Code>, SourceInfo > > RefList;
    typedef std::map<BrigStringOffset32_t, RefList> LabelMap;

    LabelMap m_labelMap; // string offset -> array of label refs

    Brigantine& operator=(const Brigantine&);

public:
    /// create Brigantine object with input BrigContainer.
    /// @param container - the container to store Brig in.
    /// Note that Brigantine is unaware of contents of the specified container and
    /// won't syncronize it's state with it and therefore it is up to the user to
    /// supply the container in a state that allows to 'continue' writing consistently.
    /// Most common case is an empty Brig container.
    Brigantine(BrigContainer& container) : m_container(container), m_machine(BRIG_MACHINE_UNDEF), m_profile(BRIG_PROFILE_UNDEF) {}
    virtual ~Brigantine() {}

    /// start HSAIL program. While it doesn't write anything to the container it
    /// prepares Brigantine's state to begin Brig emitting.
    void startProgram();
    /// end HSAIL program.
    /// Perform Brigantine's state cleanup.
    void endProgram();

    /// @name Directives
    /// @{

    /// emit DirectiveModule to the container. Should be called after startProgram call.
    /// @param name - module name
    /// @param major - major version number
    /// @param minor - minor version number
    /// @param machineModel - one of BrigMachineModel enum values
    /// @param profile - one of BrigProfile enum values
    /// @param defaultRounding - default rounding mode
    /// @param srcInfo - (optional) source location
    DirectiveModule module(const SRef& name,BrigVersion32_t major,BrigVersion32_t minor,
        BrigMachineModel8_t machineModel,BrigProfile8_t profile,BrigRound8_t defaultRounding,
        const SourceInfo* srcInfo=NULL);

    /// emit DirectiveFunction to the container.
    /// @param name - function name, should include '&' in front.
    /// @param srcInfo - (optional) source location
    DirectiveFunction declFunc(const SRef& name,const SourceInfo* srcInfo=NULL);

    /// emit DirectiveIndirectFunction to the container.
    /// @param name - function name, should include '&' in front.
    /// @param srcInfo - (optional) source location
    DirectiveIndirectFunction declIndirectFunc(const SRef& name,const SourceInfo* srcInfo=NULL);

    /// emit DirectiveKernel to the container.
    /// @param name - kernel name, should include '&' in front.
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
    DirectiveArgBlockStart startArgScope(const SourceInfo* srcInfo=NULL);

    /// end argument scope.
    /// @param srcInfo - (optional) source location
    DirectiveArgBlockEnd endArgScope(const SourceInfo* srcInfo=NULL);

    /// @}


    /// @name Symbols
    /// emit DirectiveVariable.
    /// @param name - symbol name
    /// @param srcInfo - (optional) source location
    /// @{

    DirectiveVariable addSymbol(DirectiveVariable sym);

    DirectiveVariable addVariable(const SRef& name, BrigSegment8_t segment, unsigned scalarType,const SourceInfo* srcInfo=NULL);
    DirectiveVariable addArrayVariable(const SRef& name, uint64_t size, BrigSegment8_t segment, unsigned elemType,const SourceInfo* srcInfo=NULL);

    DirectiveVariable addImage   (const SRef& name, BrigSegment8_t segment=BRIG_SEGMENT_GLOBAL, const SourceInfo* srcInfo=NULL);
    DirectiveVariable addSampler (const SRef& name, BrigSegment8_t segment=BRIG_SEGMENT_GLOBAL, const SourceInfo* srcInfo=NULL);

    DirectiveFbarrier addFbarrier(const SRef& name,const SourceInfo* srcInfo=NULL);

    /// @}

    /// emits DirectiveLabel. Should be called before instruction the label refer.
    /// This method also resolves all forward references to the label name.
    /// @param name - label name.
    DirectiveLabel   addLabel(const SRef& name,const SourceInfo* srcInfo=NULL);

    /// emit comment for the following instruction.
    /// @param comment - any text.
    /// @param srcInfo - (optional) source location.
    DirectiveComment addComment(const char *comment,const SourceInfo* srcInfo=NULL);

    /// emit extension for the following instruction.
    /// @param name - any text.
    /// @param srcInfo - (optional) source location.
    DirectiveExtension addExtension(const char *name,const SourceInfo* srcInfo=NULL);

    // TBD095 replace with addSampler, createSamplerInitializer
    /*void CreateSampler(const SRef& name,const int normalized,const BrigSamplerFilter filter,
                       const BrigSamplerBoundaryMode mode);*/

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


    void setOperands(Inst inst, ItemList operands);
    //void setOperandEx(Inst inst, int i, Operand opnd);

    template<typename Item>
    Item append(const SourceInfo* srcInfo = NULL) {
      Item item = m_container.append<Item>();
      annotate(item,srcInfo);
      return item;
    }

    template <typename ListOperand>
    ListOperand createListOperand(const ItemList& list,const SourceInfo* srcInfo)
    {
      ListOperand operand = m_container.append<ListOperand>();
      annotate(operand,srcInfo);
      operand.elements() = list;
      return operand;
    }

    OperandCodeList createCodeList(const ItemList& list, const SourceInfo* srcInfo=NULL) {
      return createListOperand<OperandCodeList>(list, srcInfo);
    }

    OperandOperandList createOperandList(const ItemList& list, const SourceInfo* srcInfo=NULL) {
      return createListOperand<OperandOperandList>(list, srcInfo);
    }

    OperandConstantOperandList createConstantOperandList(const ItemList& list, unsigned elementType, const SourceInfo* srcInfo=NULL) {
      assert(!isArrayType(elementType));
      OperandConstantOperandList opr = createListOperand<OperandConstantOperandList>(list, srcInfo);
      opr.type() = elementType2arrayType(elementType);
      return opr;
    }

    OperandConstantBytes createOperandConstantBytes(SRef data, unsigned elementType, bool isArray, const SourceInfo* srcInfo=NULL) {
        assert(!isArrayType(elementType));

        unsigned type = type2immType(elementType, isArray);
        OperandConstantBytes operand = m_container.append<OperandConstantBytes>();
        annotate(operand, srcInfo);
        operand.bytes() = data;
        operand.type() = type;
        return operand;
    }

    /// @name Register operands
    /// emit OperandRegister.
    /// @param name - register name including '$'.
    /// @param srcInfo - (optional) source location.
    OperandRegister createOperandReg(const SRef& name, const SourceInfo* srcInfo=NULL);

    /// @name Register vectors
    /// emit OperandRegVx.
    /// @param o1..o4 - registers.
    /// @param srcInfo - (optional) source location.
    /// @{
    //OperandRegVector    createOperandRegVec(std::string o[],unsigned num,const SourceInfo* srcInfo=NULL);
    //OperandOperandList       createOperandVector(const SourceInfo* srcInfo=NULL);
    /// @}

    /// @name Argument list
    /// emit list of OperandArgumentRef.
    /// @param list - ItemRange of OperandArgumentRef.
    /// @param Iterator - type of iterator that supply OperandArgumentRef.
    /// @param from - begin iterator
    /// @param till - end iterator
    /// @param srcInfo - (optional) source location.
    /// @{
    /*OperandCodeList createArgList(const SourceInfo* srcInfo=NULL);
    OperandCodeList createArgList(const ItemRange<DirectiveVariable>& list, const SourceInfo* srcInfo=NULL);
    template <typename Iterator>
    OperandCodeList createArgList(Iterator from, Iterator till, const SourceInfo* srcInfo=NULL);
    /// @}
    */

    OperandCodeList createFuncList(const SourceInfo* srcInfo);

    /// emit operand that reference label by name. Can reference forward labels. References to forward
    /// labels are recorded by brigantine and resolved at the moment when label created.
    /// @param labelName - label name
    /// @param srcInfo - (optional) source location.
    Operand             createLabelRef(const SRef& labelName, const SourceInfo* srcInfo=NULL);

    /// emit operand that reference label by name. Can reference forward labels. References to forward
    /// labels are recorded by brigantine and resolved at the moment when label created.
    /// @param labelName - label name
    /// @param srcInfo - (optional) source location.
    Operand             createLabelList(const std::vector<SRef>& labels, const SourceInfo* srcInfo=NULL);

    /// @name Function references
    /// emit function reference. Used for calls.
    /// @param fn - DirectiveFunction.
    /// @param fnName - function name including '&' (global name search)
    /// @param srcInfo - (optional) source location.
    /// @{
    OperandCodeRef  createExecutableRef(const SRef& name, const SourceInfo* srcInfo=NULL);
    /// @}

    OperandCodeRef createSigRef(const SRef& fnName, const SourceInfo* srcInfo=NULL);

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

    OperandConstantBytes createImmed(int64_t  v, BrigType16_t type, const SourceInfo* srcInfo=NULL) {
      int numBytes = getBrigTypeNumBytes(type);
      assert(numBytes <= 8);
      return createImmed(SRef((const char*)&v, (const char*)&v + numBytes), type, srcInfo);
    }
    OperandConstantBytes createImmed(f16_t    v, BrigType16_t type, const SourceInfo* srcInfo=NULL) {
      int numBytes = getBrigTypeNumBytes(type);
      assert(numBytes == 2);
      return createImmed(SRef((const char*)&v, (const char*)&v + sizeof(f16_t)), type, srcInfo);
    }
    OperandConstantBytes createImmed(f32_t    v, BrigType16_t type, const SourceInfo* srcInfo=NULL) {
      assert(getBrigTypeNumBytes(type) == 4);
      return createImmed(SRef((const char*)&v, (const char*)&v + sizeof(f32_t)), type, srcInfo);
    }
    OperandConstantBytes createImmed(f64_t    v, BrigType16_t type, const SourceInfo* srcInfo=NULL) {
      assert(getBrigTypeNumBytes(type) == 8);
      return createImmed(SRef((const char*)&v, (const char*)&v + sizeof(f64_t)), type, srcInfo);
    }

    /// @}

    /// creates unitialized OperandConstantBytes.
    /// @param srcInfo - (optional) source location
    ///OperandConstantBytes createImmed(const SourceInfo* srcInfo=NULL);
    OperandConstantBytes createImmed(SRef data, unsigned type, const SourceInfo* srcInfo=NULL);

    /// @name Memory access operands creators.

    /// generic memory access operand creator.
    /// @param symName - name for symbol including '&' or '%' (optional).
    /// @param reg - name for register including '$' (optional).
    /// @param offset - offset (optional, that is 0).
    /// @param srcInfo - (optional) source location.
    /// at least one of symName,reg, offset should be supplied upon call.
    OperandAddress     createRef(const SRef& symName, OperandRegister reg, int64_t offset=0, bool is32BitAddr = false, const SourceInfo* srcInfo=NULL);
    OperandAddress     createRef(const SRef& symName, int64_t offset=0, bool is32BitAddr = false, const SourceInfo* srcInfo=NULL) {
        return createRef(symName, OperandRegister(), offset, is32BitAddr, srcInfo);
    }
    OperandAddress     createRef(const SRef& symName, SRef& reg, int64_t offset=0, bool is32BitAddr = false, const SourceInfo* srcInfo=NULL) {
        return createRef(symName, reg.empty() ? OperandRegister() : createOperandReg(reg, srcInfo), offset, is32BitAddr, srcInfo);
    }

    OperandAddress     createRef(DirectiveVariable var, OperandRegister reg=OperandRegister(), int64_t offset=0, bool is32BitAddr = false, const SourceInfo* srcInfo=NULL);

    OperandCodeRef     createDirectiveRef(const SRef& name,const SourceInfo* srcInfo=NULL);
    OperandCodeRef     createCodeRef(Code c,const SourceInfo* srcInfo=NULL);

    OperandString createOperandString(const SRef& string, const SourceInfo* srcInfo=NULL) {
        OperandString operand = append<OperandString>(srcInfo);
        operand.string() = string;
        return operand;
    }

    /// create 'width' operand.
    /// @param srcInfo - (optional) source location.
    OperandConstantBytes createWidthOperand(const Optional<uint32_t>& width,const SourceInfo* srcInfo=NULL);

    /// create 'Wavesize' operand.
    /// @param srcInfo - (optional) source location.
    OperandWavesize    createWaveSz(const SourceInfo* srcInfo=NULL);

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
    unsigned       getMachineModel() const { assert(m_machine == BRIG_MACHINE_SMALL || m_machine == BRIG_MACHINE_LARGE); return m_machine; }
    unsigned       getProfile()      const { assert(m_profile == BRIG_PROFILE_BASE  || m_profile == BRIG_PROFILE_FULL);  return m_profile; }

private:
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
    void addSymbolToGlobalScope(DirectiveModule sym);

    bool checkForUnboundLabels();
    void recordLabelRef(ItemRef<Code> ref, const SRef& name, const SourceInfo*);
    void patchLabelRefs(DirectiveLabel label);

    DirectiveLabel addLabelInternal(const SRef& name,const SourceInfo* srcInfo);

//    template <typename Value> // this routine converts Value v to the requested brig type and save it into immediate
//    OperandConstantBytes createImmedT(Value v, BrigType16_t type, const SourceInfo* srcInfo=NULL);

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
    return name[0]=='%' || name[0]==0; // Signature arg names can be empty
}

inline bool isLocalName(const SRef& name) {
    return name.length() == 0 || name.begin[0]=='%'; // Signature arg names can be empty
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

template <typename InstItem>
InstItem Brigantine::addInst(unsigned opCode,const SourceInfo* srcInfo) {
    InstItem inst = m_container.append<InstItem>();
    annotate(inst,srcInfo);
    inst.opcode() = opCode;
    inst.type() = BRIG_TYPE_B32;
    return inst;
}

template <typename InstItem>
InstItem Brigantine::addInst(unsigned opCode,unsigned type,const SourceInfo* srcInfo) {
    InstItem inst = addInst<InstItem>(opCode,srcInfo);
    inst.type() = type;
    return inst;
}

}

#endif
