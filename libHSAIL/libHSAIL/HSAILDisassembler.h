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
//===-- HSAILDisassembler.h  - BRIG Disassembler ----------------------===//

#ifndef INCLUDED_HSAIL_DISASSEMBLER_H
#define INCLUDED_HSAIL_DISASSEMBLER_H

#include "HSAILBrigContainer.h"
#include "HSAILItems.h"
#include "HSAILUtilities.h"
#include "HSAILFloats.h"

#include <iosfwd>
#include <sstream>

namespace HSAIL_ASM {

class Disassembler {
public:
    enum FloatDisassemblyMode {
        RawBits,
        C99,
        Decimal
    };

private:
    BrigContainer&        brig;
    std::ostream*         err;

    mutable std::ostream *stream;
    mutable int           indent;
    mutable bool          hasErr;
    mutable unsigned      machineModel;
    FloatDisassemblyMode  m_fmode;

    static const int BRIG_OPERANDS_NUM = 5;

    Disassembler(const Disassembler&); // non-copyable
    const Disassembler &operator=(const Disassembler &);  // not assignable

    class ValueListPrinter;

    //-------------------------------------------------------------------------
    // Public Disassembler API
public:
    Disassembler(BrigContainer& c,FloatDisassemblyMode fmode=RawBits)
        : brig(c), err(0), stream(0), indent(0), hasErr(false), machineModel(Brig::BRIG_MACHINE_LARGE)
        , m_fmode(fmode)
    {}

    int run(std::ostream &s) const;   // Disassemble all BRIG container to stream
    int run(const char* path) const; // Disassemble all BRIG container to file
    std::string get(Directive d) const;   // Disassemble one directive as string
    std::string get(Inst i) const;        // Disassemble one instruction as string

    void log(std::ostream &s);  // Request errors logging into stream s
    bool hasError() const { return hasErr; }   // Return error flag
    void clrError()       { hasErr = false; }  // Clear error flag

    //-------------------------------------------------------------------------
    // Directives
private:

    void printDirectiveFmt(Directive d) const;
    void printDirective(Directive d) const;

    void printDirective(DirectiveVersion d) const;
    void printDirective(DirectiveKernel d) const;
    void printDirective(DirectiveFunction d) const;
    void printDirective(DirectiveLabel d) const;
    void printDirective(DirectiveComment d) const;
    void printDirective(DirectiveControl d) const;
    void printDirective(DirectiveFile d) const;
    void printDirective(DirectiveLoc d) const;
    void printDirective(DirectiveExtension d) const;
    void printDirective(DirectivePragma d) const;
    void printDirective(DirectiveSignature d) const;
    void printDirective(DirectiveLabelList d) const;
    void printDirective(DirectiveArgScopeStart d) const;
    void printDirective(DirectiveArgScopeEnd d) const;
    void printDirective(BlockStart d) const;
    void printDirective(BlockEnd d) const;
    void printDirective(BlockNumeric d) const;
    void printDirective(BlockString d) const;

    void printDirective(DirectiveVariable d) const;
    void printDirective(DirectiveImage d) const;
    void printDirective(DirectiveSampler d) const;
    void printDirective(DirectiveVariableInit d) const;
    void printDirective(DirectiveLabelInit d) const;
    void printDirective(DirectiveImageInit d) const;
    void printDirective(DirectiveSamplerInit d) const;
    void printDirective(DirectiveFbarrier d) const;


    Directive printArgs(Directive arg, unsigned paramNum, Directive scoped) const;
    void printLabelList(LabelList list) const;

    void printBody(Inst inst, unsigned instNum, Directive start, Directive end) const;
    Directive printContextDir(Offset off, Directive start, Directive end) const;

    void printSymDecl(DirectiveSymbol d) const;
    void printArgDecl(Directive d) const;

    void printProtoType(DirectiveSignatureArgument type) const;

    void printValueList(DataItem data, Brig::BrigType16_t type, unsigned maxElements) const;

    void printStringLiteral(SRef s) const;
    void printComment(SRef s) const;

    Directive next(Directive d) const;

    //-------------------------------------------------------------------------
    // Initializers

    template<typename T> void printInitializer(DirectiveSymbol s) const;

    //-------------------------------------------------------------------------
    // Instructions

    void printInstFmt(Inst i) const;
    void printInst(Inst i) const;

    void printInst(InstBasic i) const;
    void printInst(InstMod i) const;
    void printInst(InstAddr i) const;
    void printInst(InstBr i) const;
    void printInst(InstFbar i) const;
    void printInst(InstMem i) const;
    void printInst(InstCmp i) const;
    void printInst(InstCvt i) const;
    void printInst(InstAtomic i) const;
    void printInst(InstImage i) const;
    void printInst(InstAtomicImage i) const;
    void printInst(InstBar i) const;
    void printInst(InstSeg i) const;
    void printInst(InstSourceType i) const;
    void printNop() const;

    void printCallArgs(Inst i) const;
    void printInstArgs(Inst i, int firstArg = 0, int lastArg = BRIG_OPERANDS_NUM) const;
    template<class T> void print_width(T inst) const;
    void print_v(Inst i) const;

    template <typename Inst>
    void print_rounding(Inst i) const;

    //-------------------------------------------------------------------------
    // Operands

    void printOperand(Inst i, unsigned operandIdx) const;
    void printOperand(Operand opr) const;

    void printOperand(OperandReg opr) const;
    void printOperand(OperandRegVector opr) const;
    void printOperand(OperandWavesize opr) const;
    void printOperand(OperandAddress opr) const;
    void printOperand(OperandLabelRef opr) const;
    void printOperand(OperandFunctionRef opr) const;
    void printOperand(OperandArgumentList opr) const;
    void printOperand(OperandArgumentRef opr) const;
    void printOperand(OperandFunctionList opr) const;
    void printOperand(OperandSignatureRef opr) const;
    void printOperand(OperandFbarrierRef opr) const;

    void printOperandImmed(Inst inst, unsigned operandIdx) const;

    template<class T> void printOperandRegV(T operand, int size) const;
    SRef getSymbolName(Directive d) const;

    //-------------------------------------------------------------------------
    // BRIG properties

    const char* opcode2str(unsigned opcode) const;
    const char* type2str(unsigned t) const;
    const char* pack2str(unsigned t) const;
    const char* seg2str(Brig::BrigSegment8_t  segment, bool omitFlat = true, bool isGcn = false) const;
    const char* sem2str(unsigned semantic) const;
    const char* cmpOp2str(unsigned opcode) const;
    const char* atomicOperation2str(unsigned op) const;
    const char* imageGeometry2str(unsigned g) const;
    const char* imgMod2str(unsigned im) const;
    const char* machineModel2str(unsigned machineModel) const;
    const char* profile2str(unsigned profile) const;
    const char* ftz2str(unsigned ftz) const;
    const char* round2str(unsigned val) const;
    const char* memoryFence2str(unsigned flags) const;
    const char* class2str(unsigned val) const;
    const char* v2str(Operand opr) const;
    const char* imageFormat2str(Brig::BrigImageFormat8_t fmt) const;
    const char* imageOrder2str(Brig::BrigImageOrder8_t order) const;
    const char* filter2str(uint8_t val) const;
    const char* coord2str(bool inUnnormalized) const;
    const char* boundaryMode2str(uint8_t val) const;
    const char* width2str(unsigned val) const;
    const char* aligned2str(unsigned val) const;

    std::string attr2str_(Brig::BrigLinkage8_t attr) const;
    const char* const2str_(bool isConst) const;
    std::string      align2str_(unsigned align) const;
    std::string      equiv2str(unsigned val) const;
    std::string      modifiers2str(AluModifier mod) const;

    bool hasType(Inst i) const;
    bool isCall(Inst i) const;
    bool isBranch(Inst i) const;
    bool isGcnInst(Inst i) const;
    bool isLabelRef(Operand opr) const;

    unsigned getMachineType() const;

    //-------------------------------------------------------------------------
    // Formatting

    template<typename T>
    void printValue(T val) const { *stream << val; }

    void printValue(char arg) const { *stream << (int)arg; }
    void printValue(unsigned char arg) const { *stream << (int)arg; }
    void printValue(signed char arg) const { *stream << (int)arg; }

    void printValue(f16_t val) const { printFloatValue(val); }
    void printValue(float val) const { printFloatValue(val); }
    void printValue(double val) const { printFloatValue(val); }
    void printValue(const b128_t& val) const;

    template<typename T, size_t N>
    void printValue(const MySmallArray<T,N>& v) const {
        printPackedValue(v.arrayType());
    }

    void printRawFloatValue(f16_t val) const;
    void printRawFloatValue(float val) const;
    void printRawFloatValue(double val) const;

    template <typename Float>
    void printFloatValue(Float val) const {
        switch(m_fmode) {
        case RawBits: printRawFloatValue(val); break;
        case C99:     *stream << toC99str(val); break;
        case Decimal: *stream << val << IEEE754Traits<Float>::suffix; break;
        }
    }

    template<typename T, size_t N>
    void printPackedValue(const T (&val)[N]) const {
        *stream << '_' << typeX2str(CType2Brig<T,N>::value) << '(';
        for(int i=N-1; i>0; --i) {
            printValue(val[i]);
            *stream << ',';
        }
        printValue(val[0]);
        *stream << ')';
    }

    class DisassembleOperandImmed;

    template<typename T1>
    void print(T1 val1) const { *stream << val1; }
    template<typename T1, typename T2>
    void print(T1 val1, T2 val2) const { *stream << val1 << val2; }
    template<typename T1, typename T2, typename T3>
    void print(T1 val1, T2 val2, T3 val3) const { *stream << val1 << val2 << val3; }
    template<typename T1, typename T2, typename T3, typename T4>
    void print(T1 val1, T2 val2, T3 val3, T4 val4) const { *stream << val1 << val2 << val3 << val4; }
    template<typename T1, typename T2, typename T3, typename T4, typename T5>
    void print(T1 val1, T2 val2, T3 val3, T4 val4, T5 val5) const { *stream << val1 << val2 << val3 << val4 << val5; }

    void print_(const char* s) const { assert(s); if (*s) *stream << '_' << s; }
    void print_(std::string s)      const { if (!s.empty()) *stream << '_' << s; }
    template<typename T1>
    void print_(const char* s, T1 val1) const { assert(s); if (*s) { *stream << '_' << s; } *stream << val1; }

    template<typename T1>
    void printq(bool cond, T1 val1) const { if (cond) *stream << val1; }
    template<typename T1, typename T2>
    void printq(bool cond, T1 val1, T2 val2) const { if (cond) *stream << val1 << val2; }
    template<typename T1, typename T2, typename T3>
    void printq(bool cond, T1 val1, T2 val2, T3 val3) const { if (cond) *stream << val1 << val2 << val3; }

    void printIndent()    const { for (int i = indent; i > 0; --i) *stream << "\t"; }
    void printSeparator() const { *stream << '\t'; }
    void printEOL()       const { *stream << '\n'; }

    void add2ValList(std::string &res, const char* valName = NULL, const std::string& val = "") const {
        if (valName) {
            if (!val.empty()) {
                if (res.empty()) {
                    res = " = {";
                } else {
                    res += ", ";
                }
                res += valName + (" = " + val);
            }
        } else {
            if (!res.empty()) res += "}";
        }
    }

    void add2ValList(std::string &res, const char* valName, unsigned val) const {
        if (val == 0) return;
        std::ostringstream s;
        s << val;
        add2ValList(res, valName, s.str());
    }

    //-------------------------------------------------------------------------
    // Shortcuts

    template<class T>
    std::string getImpl(T d) const {
        /*
        std::string res;
        raw_string_ostream os(res);
        */
        std::ostringstream os;
        stream = &os;
        if (d) printBrig(d);
        return os.str();
    }
    void printBrig(Directive d) const { printDirective(d); }
    void printBrig(Inst i)      const { printInst(i); }

    bool wantsExtraNewLineBefore(Directive d) const {
        return (    (d.brig()->kind == Brig::BRIG_DIRECTIVE_LABEL)
                 || (d.brig()->kind == Brig::BRIG_DIRECTIVE_KERNEL)
                 || (d.brig()->kind == Brig::BRIG_DIRECTIVE_FUNCTION));
    }

    //-------------------------------------------------------------------------
    // Errors handling

    template<class T>
    void error(T brigObj, const char* msg, unsigned val) const {
        hasErr = true;
        if (err) *err << msg << ' ' << val << " at offset " << brigObj.brigOffset() << '\n';
        print("/* ", msg, ' ', val, " */");
    }

    const char* invalid(const char* type, unsigned val) const {
        hasErr = true;
        if (err) *err << "Invalid Brig::" << type << " value " << val << '\n';
        return "/*INVALID*/";
    }

    //-------------------------------------------------------------------------
};

} // namespace HSAIL_ASM

#endif
