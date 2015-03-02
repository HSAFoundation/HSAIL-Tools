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
//===-- HSAILDisassembler.cpp  - BRIG Disassembler ----------------------===//

#include "HSAILDisassembler.h"
#include "HSAILUtilities.h"
#include "HSAILb128_t.h"

#include <fstream>
#include <iomanip>
#include <cmath>

// ============================================================================
// Public API
// ============================================================================

namespace
{
    struct PrintHex
    {
        const uint8_t*  data;
        const size_t numBytes;

        PrintHex(const void* data_, size_t numBytes_)
            : data(static_cast<const uint8_t*>(data_)), numBytes(numBytes_) {}
        template<typename T> PrintHex(const T& val);
    };

    template<typename T> PrintHex::PrintHex(const T& val)
        : data(reinterpret_cast<const uint8_t*>(&val)), numBytes(sizeof(val)) {}

    inline void printHexDigit(std::ostream& os, int value)
    {
        os.put(value >= 10 ? 'a'+value-10 : '0'+value);
    }

    std::ostream& operator<<(std::ostream& os, const PrintHex& ph)
    {
        size_t i = ph.numBytes;
        while(i-- > 0)
        {
            unsigned byte = ph.data[i];
            printHexDigit(os, 0xF & (byte >> 4));
            printHexDigit(os, 0xF & (byte >> 0));
        }
        return os;
    }

} // noname namespace

namespace HSAIL_ASM
{

using std::string;
using std::ostringstream;

template <typename Float>
inline void printFloatValueImpl(std::ostream& stream, int mode, Float val) {
    switch(mode) {
    case FloatDisassemblyModeRawBits:
      stream << IEEE754Traits<Float>::hexPrefix << PrintHex(val.rawBits()); break;
    case FloatDisassemblyModeC99:
      stream << toC99str(val); break;
    case FloatDisassemblyModeDecimal:
      // \todo this might require explicit NaN processing in case the standard library is unable to print it properly
      stream.setf(std::ios::showpoint);
      stream << val.floatValue() << IEEE754Traits<Float>::suffix; break;
    default:
      assert(0);
    }
}

void printFloatValue(std::ostream& stream, int mode, f32_t val) {
  return printFloatValueImpl(stream, mode, val);
}
void printFloatValue(std::ostream& stream, int mode, f64_t val) {
  return printFloatValueImpl(stream, mode, val);
}
void printFloatValue(std::ostream& stream, int mode, f16_t val) {
  return printFloatValueImpl(stream, mode, val);
}


int Disassembler::run(std::ostream &s) const
{
    stream = &s;

    for (Code d = brig.code().begin(); d != brig.code().end(); d = next(d))
    {
        printDirectiveFmt(d);
    }
    return hasError();
}

int Disassembler::run(const char* path) const
{
    assert(path);

    std::string ErrorInfo;
    std::ofstream os(path);

    if (!ErrorInfo.empty()) return 1;

    run(os);
    os.close();
    return hasError() || os.bad(); //TBD
}

string Disassembler::get(Directive d, unsigned model, unsigned profile)  { mModel = model; mProfile = profile; return getImpl(d); }
string Disassembler::get(Inst i,      unsigned model, unsigned profile)  { mModel = model; mProfile = profile; return getImpl(i); }
string Disassembler::get(Operand i,   unsigned model, unsigned profile)  { mModel = model; mProfile = profile; return getImpl(i); }

void Disassembler::log(std::ostream &s) { err = &s; }

// ============================================================================
// Directives
// ============================================================================

void Disassembler::printDirectiveFmt(Code d) const
{
    using namespace Brig;
    assert(d);

    unsigned kind = d.kind();

    if (kind == BRIG_KIND_DIRECTIVE_MODULE)
    {
        mModel = DirectiveModule(d).machineModel();
    }

    if (wantsExtraNewLineBefore(d)) printEOL();

    if (kind == BRIG_KIND_DIRECTIVE_ARG_BLOCK_END && indent > 0) --indent;
    if (kind != BRIG_KIND_DIRECTIVE_LABEL)                       printIndent();
    if (kind == BRIG_KIND_DIRECTIVE_ARG_BLOCK_START)             ++indent;

    printDirective(Directive(d));
    printEOL();
}

void Disassembler::printDirective(Directive d, bool dump /*=false*/) const
{
    using namespace Brig;
    assert(d);

    switch (d.kind())
    {
    case BRIG_KIND_DIRECTIVE_MODULE:            printDirective(DirectiveModule(d));        break;
    case BRIG_KIND_DIRECTIVE_KERNEL:
    case BRIG_KIND_DIRECTIVE_FUNCTION:
    case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION: printDirective(DirectiveExecutable(d));     break;
    case BRIG_KIND_DIRECTIVE_VARIABLE:          printDirective(DirectiveVariable(d));       break;
    case BRIG_KIND_DIRECTIVE_LABEL:             printDirective(DirectiveLabel(d));          break;
    case BRIG_KIND_DIRECTIVE_COMMENT:           printDirective(DirectiveComment(d));        break;
    case BRIG_KIND_DIRECTIVE_CONTROL:           printDirective(DirectiveControl(d));        break;
    case BRIG_KIND_DIRECTIVE_EXTENSION:         printDirective(DirectiveExtension(d));      break;
    case BRIG_KIND_DIRECTIVE_LOC:               printDirective(DirectiveLoc(d));            break;
    case BRIG_KIND_DIRECTIVE_PRAGMA:            printDirective(DirectivePragma(d));         break;
    case BRIG_KIND_DIRECTIVE_SIGNATURE:         printDirective(DirectiveSignature(d));      break;
    case BRIG_KIND_DIRECTIVE_FBARRIER:          printDirective(DirectiveFbarrier(d));       break;

    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START:   printDirective(DirectiveArgBlockStart(d));  break;
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END:     printDirective(DirectiveArgBlockEnd(d));    break;

    default: error(d, "Unsupported Directive Kind", d.kind());                        break;
    }
}

void Disassembler::printDirective(DirectiveModule d) const
{
    print("module ");
    print(d.name(), ':');
    print(d.hsailMajor(), ':');
    print(d.hsailMinor(), ':');
    print(profile2str(d.profile()), ':');
    print(machineModel2str(d.machineModel()), ':');
    print(defaultRound2str(d.defaultFloatRound()), ';');
}

void Disassembler::printDirective(DirectiveComment d) const
{
    printComment(d.name());
}

void Disassembler::printDirective(DirectiveControl d) const
{
    unsigned len = d.operands().size();
    print(controlDirective2str(d.control()));
    printq(len > 0, ' ');

    for (unsigned i = 0; i < len; ++i)
    {
        printq(i != 0, ", ");
        Operand opr = d.operands()[i];
        printOperand(opr);
    }

    print(';');
}

void Disassembler::printDirective(DirectiveLoc d) const
{
    print("loc ");
    print(d.line());
    printq(d.column() != 1, ' ', d.column());
    print(' ');
    printStringLiteral(d.filename());
    print(';');
}

void Disassembler::printDirective(DirectiveExtension d) const
{
    print("extension ");
    printStringLiteral(d.name());
    print(';');
}

void Disassembler::printDirective(DirectivePragma d) const
{
    print("pragma ");
    printListOfOperands(d.operands(), true, true, false); //F1.0 should not print in single line
    print(';');
}

void Disassembler::printDirective(DirectiveLabel d) const
{
    print(d.name(), ':');
}

void Disassembler::printDirective(DirectiveVariable d) const
{
    printSymDecl(d);
    if (d.init())
    {
        print(" = ");
        if (OperandConstantBytes init = d.init())
        {
            printOperandConstantBytes(init);
        }
        else if (OperandConstantOperandList init = d.init())
        {
            printOperandConstantOperandList(init);
        }
        else if (OperandConstantImage init = d.init())
        {
            printOperandConstantImage(init);
        }
        else if (OperandConstantSampler init = d.init())
        {
            printOperandConstantSampler(init);
        }
        else
        {
            print("***INVALID VARIABLE INITIALIZER***");
        }
    }
    print(';');
}

void Disassembler::printDirective(DirectiveFbarrier d) const
{
    print(decl2str_(!d.modifier().isDefinition()));
    print(attr2str_(d.linkage()));
    print("fbarrier ", d.name(), ';');
}

void Disassembler::printOperandConstantImage(OperandConstantImage d) const
{
    assert(!isArrayType(d.type()));

    string valList;
    add2ValList(valList, "geometry",      imageGeometry2str(d.geometry()));
    add2ValList(valList, "width",         d.width());
    add2ValList(valList, "height",        d.height());
    add2ValList(valList, "depth",         d.depth());
    add2ValList(valList, "array",         d.array());
    add2ValList(valList, "channel_type",  imageChannelType2str(d.channelType()));
    add2ValList(valList, "channel_order", imageChannelOrder2str(d.channelOrder()));

    print(string(typeX2str(d.type())) + "(" + valList + ")");
}

void Disassembler::printOperandConstantSampler(OperandConstantSampler d) const
{
    assert(!isArrayType(d.type()));

    string valList;
    add2ValList(valList, "coord",        samplerCoordNormalization2str(d.coord()));
    add2ValList(valList, "filter",       samplerFilter2str(d.filter()));
    add2ValList(valList, "addressing",   samplerAddressing2str(d.addressing()));

    print(string(typeX2str(d.type())) + "(" + valList + ")");
}

void Disassembler::printListOfOperands(ListRef<Operand> operands, bool singleLine /*=true*/, bool typed /*=false*/, bool strict /*=true*/) const
{
    unsigned size = operands.size();
    for (unsigned i = 0; i < size; ++i)
    {
        if (i > 0) print(", ");
        if (!singleLine && size > 1) { printEOL(); printIndent(); printSeparator(); }
        Operand opnd = operands[i];
        if (typed) printTypedOperand(opnd, strict); 
        else       printOperand(opnd);
    }
    if (!singleLine && size > 1) printEOL();
}

void Disassembler::printTypedOperand(Operand operand, bool strict /*=true*/) const
{
    OperandConstantBytes cnst = operand;
    if (cnst)
    {       
        unsigned type = cnst.type();
        bool implicitlyTyped = isIntType(type) || isFloatType(type);
        bool implicitTypeAllowed = !strict && (type == Brig::BRIG_TYPE_U64 || isFloatType(type));

        if (implicitlyTyped && !implicitTypeAllowed) // explicit type suffix required
        {
            print(typeX2str(cnst.type()), "(");
            printOperand(operand);
            print(")");
        }
        else 
        {
            printOperand(operand);
        }
    } 
    else 
    {
        printOperand(operand);
    }
}

void Disassembler::printOperandConstantOperandList(OperandConstantOperandList opr) const
{
    if (opr.type() == Brig::BRIG_TYPE_NONE)
    {
        print("{");
        printListOfOperands(opr.elements(), false, true);
        print("}");
    }
    else
    {
        print(typeX2str(arrayElementType(opr.type())), "[](");
        printListOfOperands(opr.elements(), false);
        printIndent();
        print(")");
    }
}

void Disassembler::printDirective(DirectiveArgBlockStart d) const
{
    print("{");
}

void Disassembler::printDirective(DirectiveArgBlockEnd d) const
{
    print("}");
}

template <typename List>
void Disassembler::printLabelList(List list) const
{
    unsigned const size = list.size();
    if (size > 0)
    {
        unsigned i;
        for(i = 0; i < size - 1; ++i)
        {
            print(list[i].name(), ", ");
        }
        print(list[i].name());
    }
}

void Disassembler::printDirective(DirectiveExecutable d) const
{
    print(decl2str_(!d.modifier().isDefinition()));
    print(attr2str_(d.linkage()));
    print(exec2str_(d));
    print(d.name());
    if (!DirectiveKernel(d)) printArgs(d.next(), d.outArgCount());
    printArgs(d.firstInArg(), d.inArgCount());
    printBody(d.firstCodeBlockEntry(), d.nextModuleEntry(), d.modifier().isDefinition() && !DirectiveSignature(d));
}

void Disassembler::printArgs(Directive arg, unsigned argNum) const
{
    print("(");
    if (argNum == 1)
    {
        assert(arg);
        printArgDecl(arg);
    }
    else if (argNum > 1)
    {
        ++indent;
        for (int i = argNum; i > 0; --i)
        {
            assert(arg);
            printEOL();
            printIndent();
            printArgDecl(arg);
            printq(i > 1, ',');
            arg = arg.next();
        }
        --indent;
    }
    print(")");
}



void Disassembler::printBody(Code start, Code end, bool isDefinition /* = true */) const
{
    if (start && isDefinition) //F
    {
        ++indent;
        printEOL();
        print("{");
        printEOL();
        for(Code c = start; c != end; c = c.next())
        {
            if (Directive dir = c) {
                printDirectiveFmt(dir);
            } else {
                Inst inst = c;
                printInstFmt(inst);
            }
        }
        print("}");
        --indent;
    }
    print(";");
}

void Disassembler::printArgDecl(Directive d) const
{
    using namespace Brig;
    assert(d);
    printSymDecl(DirectiveVariable(d), true);
}

void Disassembler::printSymDecl(DirectiveVariable s, bool isArg /*=false*/) const
{
    // print space-separated attributes which go before name
    print(decl2str_(!s.modifier().isDefinition()));
    print(attr2str_(s.linkage()));
    print(alloc2str_(s.allocation(), s.segment()));
    print(align2str_(s.align(), s.elementType()));
    print(const2str_(s.modifier().isConst()));

    // print symbol segment and type (separated with "_")
    print(seg2str(s.segment()));
    print_(type2str(s.elementType()));

    // print symbol name and dimensions (if any)
    printq(!SRef(s.name()).empty(), ' ', s.name());

    // dimension
    if (s.isArray() && s.dim() == 0)
    {
        print("[]");
    }
    else if (s.isArray())
    {
        print('[', s.dim(), ']');
    }
}

class Disassembler::ValuePrinter
{
    const Disassembler *m_self;
    SRef                m_data;
public:
    ValuePrinter (const Disassembler* dasm, SRef data)
        : m_self(dasm), m_data(data) { }

    template<typename BrigType>
    void visit() const
    {
        typedef typename BrigType::CType CType;
        const CType* data = (const CType*)m_data.begin;
        std::size_t total = m_data.length() / sizeof(CType);
        assert(total * sizeof(CType) == m_data.length());
        if (total > 0)
        {
            unsigned i = 0;
            for(; i < (total - 1); ++i)
            {
                m_self->printValue(data[i]);
                m_self->print(", ");
            }
            m_self->printValue(data[i]);
        }
    }

    void visitNone(unsigned type) const { assert(false); }

//F1.0 remove
template<typename BrigType>
void print(const char* pref) const
{
    typedef typename BrigType::CType CType;
    const CType* data = (const CType*)m_data.begin;
    std::size_t total = m_data.length() / sizeof(CType);
    assert(total * sizeof(CType) == m_data.length());
    if (total > 0)
    {
        unsigned i = 0;
        for(; i < (total - 1); ++i)
        {
            printValue(pref, data[i]);
            m_self->print(", ");
        }
        printValue(pref, data[i]);
    }
}

//F1.0 remove
template<typename Type>
void printValue(const char* pref, Type val) const
{
    m_self->printq(pref != 0, pref);
    m_self->printValue(val);
    m_self->printq(pref != 0, ")");
}


};

template <>
void Disassembler::ValuePrinter::visit< BrigType<Brig::BRIG_TYPE_B1> >() const // special case for bool
{
    m_self->printValue((int)(m_data.begin[0] & 0x1U));
}

//F1.0 remove
template <>
void Disassembler::ValuePrinter::visit< BrigType<Brig::BRIG_TYPE_SIG32> >() const
{
    print< BrigType<Brig::BRIG_TYPE_SIG32> >("sig32("); //F1.0 should be removed; define CType for signals (see how packed types are handled)
}

//F1.0 remove
template <>
void Disassembler::ValuePrinter::visit< BrigType<Brig::BRIG_TYPE_SIG64> >() const
{
    print< BrigType<Brig::BRIG_TYPE_SIG64> >("sig64(");
}

void Disassembler::printOperandConstantBytes(OperandConstantBytes opr) const
{
    unsigned type = opr.type();
    unsigned elementType = arrayElementType(type);
    
    if (isArrayType(type)) print(typeX2str(elementType), "[](");

    if (elementType == Brig::BRIG_TYPE_B128)
    {
        // There are no b128 imm operands, only packed imms may be 128 bit wide.
        // So replace b128 with any 128-bit packed type
        elementType = Brig::BRIG_TYPE_U8X16;
    }

    dispatchByType(elementType, ValuePrinter(this, opr.bytes()));

    if (isArrayType(type)) print(")");
}

Code Disassembler::next(Code d) const
{
    if (DirectiveExecutable sub = d)
    {
        return sub.nextModuleEntry();
    }
    return d.next();
}

// ============================================================================
// INSTRUCTIONS
// ============================================================================

void Disassembler::printInstFmt(Inst i) const
{
    printIndent();
    if (m_options & PrintInstOffset) {
        print("/* I@",i.brigOffset()," */\t");
    }
    printInst(i);
    printEOL();
}

void Disassembler::printInst(Inst i) const
{
    using namespace Brig;
    assert(i);

    switch(i.kind())
    {
    case BRIG_KIND_INST_BASIC:         printInst(InstBasic(i));        break;
    case BRIG_KIND_INST_ADDR:          printInst(InstAddr(i));         break;
    case BRIG_KIND_INST_MOD:           printInst(InstMod(i));          break;
    case BRIG_KIND_INST_CVT:           printInst(InstCvt(i));          break;
    case BRIG_KIND_INST_MEM_FENCE:     printInst(InstMemFence(i));     break;
    case BRIG_KIND_INST_CMP:           printInst(InstCmp(i));          break;
    case BRIG_KIND_INST_MEM:           printInst(InstMem(i));          break;
    case BRIG_KIND_INST_BR:            printInst(InstBr(i));           break;
    case BRIG_KIND_INST_ATOMIC:        printInst(InstAtomic(i));       break;
    case BRIG_KIND_INST_IMAGE:         printInst(InstImage(i));        break;
    case BRIG_KIND_INST_LANE:          printInst(InstLane(i));         break;
    case BRIG_KIND_INST_QUEUE:         printInst(InstQueue(i));        break;
    case BRIG_KIND_INST_SEG:           printInst(InstSeg(i));          break;
    case BRIG_KIND_INST_SEG_CVT:       printInst(InstSegCvt(i));       break;
    case BRIG_KIND_INST_SOURCE_TYPE:   printInst(InstSourceType(i));   break;
    case BRIG_KIND_INST_SIGNAL:        printInst(InstSignal(i));       break;
    case BRIG_KIND_INST_QUERY_IMAGE:   printInst(InstQueryImage(i));   break;
    case BRIG_KIND_INST_QUERY_SAMPLER: printInst(InstQuerySampler(i)); break;
    default: error(i, "Unsupported Instruction Format", i.kind()); break;
    }
    print(';');
}

void Disassembler::printInst(InstBasic i) const
{
    print(opcode2str(i.opcode()));
    if (instHasType(i.opcode())) print_(type2str(i.type()));
    printInstArgs(i);
}

template <typename Inst>
void Disassembler::print_rounding(Inst i) const
{
    unsigned rounding = i.round();
    unsigned defaultRounding = getDefRounding(i, mModel, mProfile);
    if (rounding != defaultRounding) print_(round2str(rounding));
}

void Disassembler::printInst(InstMod i) const
 {
    print(opcode2str(i.opcode()));

    print(modifiers2str(i.modifier()));
    print_rounding(i);
    print_(pack2str(i.pack()));
    if (instHasType(i.opcode())) print_(type2str(i.type()));

    printInstArgs(i);
}

void Disassembler::printInst(InstAddr i) const
{
    print(opcode2str(i.opcode()));
    if (!isGcnInst(i.opcode())) print_(seg2str(i.segment()));
    print_(type2str(i.type()));
    printInstArgs(i);
}

void Disassembler::printInst(InstBr i) const
{
    print(opcode2str(i.opcode()));
    print_width(i);
    if (instHasType(i.opcode())) print_(type2str(i.type()));

    if (isCallInst(i.opcode())) printCallArgs(i);
    else if (i.opcode() == Brig::BRIG_OPCODE_SBR) printSbrArgs(i);
    else printInstArgs(i);
}

void Disassembler::printInst(InstMem i) const
{
    print(opcode2str(i.opcode()));
    print_v(i);
    if (i.opcode() != Brig::BRIG_OPCODE_ALLOCA) print_(seg2str(i.segment()));
    print_(align2str(i.align()));
    print_(const2str(i.modifier().isConst()));
    print_(equiv2str(i.equivClass()));
    print_width(i);

    print_(type2str(i.type()));
    printInstArgs(i);
}

void Disassembler::printInst(InstSeg i) const
{
    print(opcode2str(i.opcode()));
    print_(seg2str(i.segment()));
    print_(type2str(i.type()));
    printInstArgs(i);
}

void Disassembler::printInst(InstSegCvt i) const
{
    print(opcode2str(i.opcode()));
    print_(seg2str(i.segment()));
    print_(nonull2str(i.modifier().isNoNull()));
    print_(type2str(i.type()));
    print_(type2str(i.sourceType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstQueue i) const
{
    print(opcode2str(i.opcode()));
    print_(seg2str(i.segment()));
    print_(memoryOrder2str(i.memoryOrder()));
    print_(type2str(i.type()));
    printInstArgs(i);
}

void Disassembler::printInst(InstSourceType i) const
{
    print(opcode2str(i.opcode()));
    print_v(i);
    print_(type2str(i.type()));
    print_(type2str(i.sourceType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstCmp i) const
{
    print(opcode2str(i.opcode()));
    print_(cmpOp2str(i.compare()));
    print(modifiers2str(i.modifier()));
    print_(pack2str(i.pack()));
    print_(type2str(i.type()));
    print_(type2str(i.sourceType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstCvt i) const
{
    print(opcode2str(i.opcode()));
    print(modifiers2str(i.modifier()));
    print_rounding(i);
    print_(type2str(i.type()));
    print_(type2str(i.sourceType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstAtomic i) const
{
    print(opcode2str(i.opcode()));
    print_(atomicOperation2str(i.atomicOperation()));
    print_(seg2str(i.segment()));
    print_(memoryOrder2str(i.memoryOrder()));
    print_(memoryScope2str(i.memoryScope()));
    print_(equiv2str(i.equivClass()));
    print_(type2str(i.type()));
    printInstArgs(i);
}

void Disassembler::printInst(InstImage i) const
{
    print(opcode2str(i.opcode()));
    print_v(i);
    print_(imageGeometry2str(i.geometry()));
    print_(equiv2str(i.equivClass()));
    print_(type2str(i.type()));
    print_(type2str(i.imageType()));
    print_(type2str(i.coordType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstLane i) const
{
    print(opcode2str(i.opcode()));
    print_v(i);
    print_width(i);
    print_(type2str(i.type()));
    if (i.sourceType() != Brig::BRIG_TYPE_NONE) print_(type2str(i.sourceType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstMemFence i) const
{
    print(opcode2str(i.opcode()));
    print_(memoryOrder2str(i.memoryOrder()));
    print_(memoryScope2str(i.globalSegmentMemoryScope()));
    if (instHasType(i.opcode())) print_(type2str(i.type()));
    printInstArgs(i);
}

void Disassembler::printInst(InstSignal i) const
{
    print(opcode2str(i.opcode()));
    print_(atomicOperation2str(i.signalOperation()));
    print_(memoryOrder2str(i.memoryOrder()));
    print_(type2str(i.type()));
    print_(type2str(i.signalType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstQueryImage i) const
{
    print(opcode2str(i.opcode()));
    print_(imageGeometry2str(i.geometry()));

    print_(imageQuery2str(i.imageQuery()));

    print_(type2str(i.type()));
    print_(type2str(i.imageType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstQuerySampler i) const
{
    print(opcode2str(i.opcode()));

    print_(samplerQuery2str(i.samplerQuery()));

    print_(type2str(i.type()));
    printInstArgs(i);
}

void Disassembler::printNop() const
{
    // Nothing to print
}

void Disassembler::print_v(Inst i) const
{
    switch (i.opcode())
    {
    case Brig::BRIG_OPCODE_LD:
    case Brig::BRIG_OPCODE_GCNLD:
    case Brig::BRIG_OPCODE_ST:
    case Brig::BRIG_OPCODE_GCNST:
    case Brig::BRIG_OPCODE_EXPAND:
    case Brig::BRIG_OPCODE_RDIMAGE:
    case Brig::BRIG_OPCODE_LDIMAGE:
    case Brig::BRIG_OPCODE_STIMAGE:
    case Brig::BRIG_OPCODE_ACTIVELANEMASK:
        print_(v2str(i.operand(0)));
        break;
    case Brig::BRIG_OPCODE_COMBINE:
        print_(v2str(i.operand(1)));
        break;
    default:
        break;
    }
}

template<class T>
void Disassembler::print_width(T inst) const
{
    if (getDefWidth(inst, mModel, mProfile) != inst.width())
    {
        print_(width2str(inst.width()));
    }
}

void Disassembler::printInstArgs(Inst i, int firstArg /*=0*/, int lastArg /*=BRIG_OPERANDS_NUM*/) const
{
    if (i.operands().size() > firstArg)
    {
        printSeparator();
        for (int k = firstArg; k < lastArg && k < i.operands().size(); ++k)
        {
            printq(k > firstArg, ", ");
            if (i.operands()[k])
            {
                printInstOperand(i, k);
            }
            else
            {
                print("NULL"); // NB: Important for TestGen (see emitTestDescription) //F
            }
        }
    }
}

void Disassembler::printCallArgs(Inst i) const
{
    assert(isCallInst(i.opcode()));
    assert(i.operand(1));

    printSeparator();
    printInstOperand(i, 1); // target

    if (OperandCodeList(i.operand(0)))   // output args
    {
        print(' ');
        printInstOperand(i, 0);
    }
    if (OperandCodeList(i.operand(2)))   // input args
    {
        print(' ');
        printInstOperand(i, 2);
    }

    if (OperandCodeList opr = i.operand(3))   // list of functions
    {
        print(" [");
        for (int idx = 0; idx < opr.elements().size(); ++idx)
        {
            printq(idx != 0, ", ");
            print(getSymbolName(opr.elements()[idx]));
        }
        print("]");
    }
    else if (OperandCodeRef opr = i.operand(3))   // signature
    {
        print(' ');
        print(getSymbolName(opr.ref()));
    }
}

void Disassembler::printSbrArgs(Inst i) const
{
    assert(i.opcode() == Brig::BRIG_OPCODE_SBR);
    assert(i.operand(0));
    assert(i.operand(1));
    assert(!i.operand(2));

    printSeparator();
    printInstOperand(i, 0);
    print(" ");

    if (OperandCodeList opr = i.operand(1)) //F merge with similar code in printCallArgs
    {
        print('[');
        for (int idx = 0; idx < opr.elements().size(); ++idx)
        {
            printq(idx != 0, ", ");
            print(getSymbolName(opr.elements()[idx]));
        }
        print(']');
    }
}

// ============================================================================
// OPERANDS
// ============================================================================

void Disassembler::printInstOperand(Inst inst, unsigned operandIdx) const
{
    using namespace Brig;
    assert(inst && operandIdx <= 4);

    Operand opr = inst.operand(operandIdx);
    assert(opr);

    printOperand(opr);
}

void Disassembler::printOperand(Operand opr, bool dump /*=false*/) const
{
    using namespace Brig;
    assert(opr);

    switch (opr.kind())
    {
    case BRIG_KIND_OPERAND_REGISTER:                printOperandReg(opr);                     break;
    case BRIG_KIND_OPERAND_ADDRESS:                 printOperandAddress(opr);                 break;
    case BRIG_KIND_OPERAND_WAVESIZE:                printOperandWavesize(opr);                break;
    case BRIG_KIND_OPERAND_CONSTANT_BYTES:          printOperandConstantBytes(opr);           break;
    case BRIG_KIND_OPERAND_CODE_LIST:               printOperandCodeList(opr);                break;
    case BRIG_KIND_OPERAND_CODE_REF:                printOperandCodeRef(opr);                 break;
    case BRIG_KIND_OPERAND_CONSTANT_IMAGE:          printOperandConstantImage(opr);           break;
    case BRIG_KIND_OPERAND_OPERAND_LIST:            printVector(opr);                         break;
    case BRIG_KIND_OPERAND_CONSTANT_OPERAND_LIST:   printOperandConstantOperandList(opr);     break;
    case BRIG_KIND_OPERAND_CONSTANT_SAMPLER:        printOperandConstantSampler(opr);         break;
    case BRIG_KIND_OPERAND_STRING:                  printOperandString(opr);                  break;
    case BRIG_KIND_OPERAND_ALIGN:                   printOperandAlign(opr);                   break;

    default:
        error(opr, "Unsupported Operand Kind", opr.kind());
        break;
    }
}

void Disassembler::printOperandString(OperandString opr) const
{
    assert(opr);
    printStringLiteral(opr.string());
}

void Disassembler::printOperandAlign(OperandAlign opr) const
{
    assert(opr);
    print(align2str(opr.align()));
}

void Disassembler::printOperandReg(OperandRegister opr) const
{
    assert(opr);
    string regKind = registerKind2str(opr.regKind());
    int regNum = opr.regNum();
    print(regKind, regNum);
}

void Disassembler::printOperandWavesize(OperandWavesize opr) const { print("WAVESIZE"); }

void Disassembler::printOperandAddress(OperandAddress opr) const
{
    DirectiveVariable name = opr.symbol();
    int64_t offset = (int64_t)opr.offset();
    OperandRegister reg = opr.reg();

    if (getAddrSize(opr, mModel == Brig::BRIG_MACHINE_LARGE) == 32) 
    {
        offset = (int32_t)offset; // sign-extend 32-bit offset
    }

    if (name)
    {
        print('[', getSymbolName(name), ']');
    }

    if (reg)
    {
        print('[');
        printOperandReg(reg);
        printq(offset > 0, '+',  offset);
        printq(offset < 0, '-', -offset);
        print(']');
    }
    else if (offset != 0 || !name)  // [0] is a special case
    {
        if (name && offset < 0) print('[', '-', -offset, ']'); // [%name][-4]
        else                    print('[', (uint64_t)opr.offset(), ']');
    }
}

void Disassembler::printVector(OperandOperandList opr) const
{
    assert(opr);

    print('(');

    printListOfOperands(opr.elements());

    print(')');
}

void Disassembler::printValue(const b128_t& val) const
{
    uint64_t const hi = hiPart(val);
    uint64_t const lo = lowPart(val);
    if (hi != 0)
    {
        *stream << "0X" << PrintHex(val);
    }
    else
    {
        *stream << lo;
    }
}

void Disassembler::printOperandCodeRef(OperandCodeRef opr) const
{
    assert(opr);
    assert(opr.ref());
    print(getSymbolName(opr.ref()));
}

void Disassembler::printOperandCodeList(OperandCodeList opr) const
{
    print('(');
    for (int idx = 0; idx < opr.elements().size(); ++idx)
    {
        printq(idx != 0, ", ");
        print(getSymbolName(opr.elements()[idx]));
    }
    print(')');
}

SRef Disassembler::getSymbolName(Directive d) const
{
    if (DirectiveExecutable    sym = d) return sym.name();
    else if (DirectiveVariable sym = d) return sym.name();
    else if (DirectiveLabel    sym = d) return sym.name();
    else if (DirectiveFbarrier sym = d) return sym.name();
    else assert(false);                 return SRef();
}

// ============================================================================
// BRIG PROPERTIES
// ============================================================================

const char* Disassembler::machineModel2str(unsigned model) const
{
    switch(model)
    {
    case Brig::BRIG_MACHINE_LARGE: return "$large";
    case Brig::BRIG_MACHINE_SMALL: return "$small";
    default:               return invalid("MachineModel", model);
    }
}

const char* Disassembler::profile2str(unsigned profile) const
{
    switch(profile)
    {
    case Brig::BRIG_PROFILE_FULL: return "$full";
    case Brig::BRIG_PROFILE_BASE: return "$base";
    default:                      return invalid("Profile", profile);
    }
}

const char* Disassembler::defaultRound2str(unsigned round) const
{
    switch(round)
    {
    case Brig::BRIG_ROUND_FLOAT_DEFAULT:   return "$default";
    case Brig::BRIG_ROUND_FLOAT_NEAR_EVEN: return "$near";
    case Brig::BRIG_ROUND_FLOAT_ZERO:      return "$zero";
    default:                               return invalid("DefaultFloatRound", round);
    }
}

const char* Disassembler::seg2str(Brig::BrigSegment8_t segment) const
{
    const char *result = HSAIL_ASM::segment2str(segment);
    if (result != NULL) return result;
    else return invalid("Segment", segment);
}

const char* Disassembler::type2str(unsigned t) const
{
    assert(!isArrayType(t));

    const char *result = HSAIL_ASM::typeX2str(t);
    if (result != NULL)
    {
        return strcmp(result, "none") == 0? "" : result;
    }
    else
    {
        return invalid("Type", t);
    }
}

const char* Disassembler::pack2str(unsigned t) const
{
    const char *result = HSAIL_ASM::pack2str(t);
    if (result != NULL) return result;
    else return invalid("Packing", t);
}

const char* Disassembler::const2str(bool isConst) const
{
    return isConst? "const" : "";
}

const char* Disassembler::nonull2str(bool isNoNull) const
{
    return isNoNull ? "nonull" : "";
}

const char* Disassembler::cmpOp2str(unsigned opcode) const
{
    const char* result=HSAIL_ASM::compareOperation2str(opcode);
    if (result != NULL) return result;
    else return invalid("CompareOperation", opcode);
}

const char* Disassembler::imageGeometry2str(unsigned g) const
{
    const char* result=HSAIL_ASM::imageGeometry2str(g);
    if (result != NULL) return result;
    else return invalid("ImageGeom", g);
}

const char* Disassembler::samplerCoordNormalization2str(unsigned val) const
{
    const char* result=HSAIL_ASM::samplerCoordNormalization2str(val);
    if (result != NULL) return result;
    else return invalid("SamplerCoord", val);
}
const char* Disassembler::samplerFilter2str(unsigned val) const
{
    const char* result=HSAIL_ASM::samplerFilter2str(val);
    if (result != NULL) return result;
    else return invalid("SamplerFilter", val);
}
const char* Disassembler::samplerAddressing2str(unsigned val) const
{
    const char* result=HSAIL_ASM::samplerAddressing2str(val);
    if (result != NULL) return result;
    else return invalid("SamplerAddressing", val);
}

const char* Disassembler::samplerQuery2str(unsigned g) const
{
    const char* result=HSAIL_ASM::samplerQuery2str(g);
    if (result != NULL) return result;
    else return invalid("SamplerQuery", g);
}

const char* Disassembler::imageQuery2str(unsigned g) const
{
    const char* result=HSAIL_ASM::imageQuery2str(g);
    if (result != NULL) return result;
    else return invalid("ImageQuery", g);
}

const char* Disassembler::memoryOrder2str(unsigned memOrder) const
{
    const char* result=HSAIL_ASM::memoryOrder2str(memOrder);
    if (result != NULL) return result;
    else return invalid("MemoryOrder", memOrder);
}

const char* Disassembler::memoryScope2str(unsigned flags) const
{
    const char* result=HSAIL_ASM::memoryScope2str(flags);
    if (result != NULL) return result;
    else return "";
}

const char* Disassembler::atomicOperation2str(unsigned op) const
{
    const char* result=HSAIL_ASM::atomicOperation2str(op);
    if (result != NULL) return result;
    else return invalid("AtomicOperation", op);
}

const char* Disassembler::opcode2str(unsigned opcode) const
{
    const char *result = HSAIL_ASM::opcode2str(opcode);
    if (result != NULL) return result;
    else return invalid("Opcode", opcode);
}

const char* Disassembler::round2str(unsigned val) const
{
    const char *result = HSAIL_ASM::round2str(val);
    if (result != NULL) return result;
    else if (val == Brig::BRIG_ROUND_NONE) return "";
    else if (val == Brig::BRIG_ROUND_FLOAT_DEFAULT) return "";
    else return invalid("Rounding", val);
}

string Disassembler::modifiers2str(AluModifier mod) const
{
    ostringstream s;
    if (mod.ftz()) s << "_ftz";
    return s.str().c_str();
}

string Disassembler::registerKind2str(unsigned val) const
{
    const char *result = HSAIL_ASM::registerKind2str(val);
    if (result != NULL) return result;
    else return invalid("RegisterKind", val);
}

string Disassembler::controlDirective2str(unsigned val) const
{
    const char *result = HSAIL_ASM::controlDirective2str(val);
    if (result != NULL) return result;
    else return invalid("ControlDirective", val);
}

const char* Disassembler::v2str(Operand opr) const
{
    if (OperandOperandList vec = opr)
    {
        int vx = vec.elements().size();
        switch(vx)
        {
        case 2: return "v2";
        case 3: return "v3";
        case 4: return "v4";
        default: return invalid("vX register count", vx);
        }
    }
    else if (OperandRegister(opr) || OperandConstantBytes(opr) || OperandWavesize(opr))
    {
        return "";
    }
    return invalid("vX operand", opr? opr.kind() : -1);
}

const char* Disassembler::imageChannelType2str(Brig::BrigImageChannelType8_t fmt) const
{
    const char *result = HSAIL_ASM::imageChannelType2str(fmt);
    if (result != NULL) return result;
    else return invalid("ImageChannelType", fmt);
}

const char* Disassembler::imageChannelOrder2str(Brig::BrigImageChannelOrder8_t order) const
{
    const char *result = HSAIL_ASM::imageChannelOrder2str(order);
    if (result != NULL) return result;
    else return invalid("ImageChannelOrder", order);
}

string Disassembler::equiv2str(unsigned val) const
{
    ostringstream s;
    if (val != 0) s << "equiv(" << val << ')';
    return s.str();
}

string Disassembler::decl2str_(bool isDecl) const
{
    return isDecl? "decl " : "";
}

string Disassembler::exec2str_(DirectiveExecutable d) const
{
    if (DirectiveKernel(d))           return "kernel ";
    if (DirectiveFunction(d))         return "function ";
    if (DirectiveIndirectFunction(d)) return "indirect function ";
    if (DirectiveSignature(d))        return "signature ";

    assert(false);
    return "";
}

string Disassembler::attr2str_(Brig::BrigLinkage8_t attr) const
{
    ostringstream s;
    const char *c_str = HSAIL_ASM::linkage2str(attr);
    if (c_str != NULL)
    {
        if (attr == Brig::BRIG_LINKAGE_PROGRAM) s << "prog ";
    }
    else s << invalid("Linkage", attr) << " ";
    return s.str();
}

string Disassembler::alloc2str_(unsigned alloc, unsigned segment) const
{
    ostringstream s;
    const char *c_str = HSAIL_ASM::allocation2str(alloc);
    if (c_str != NULL)
    {
        if (alloc == Brig::BRIG_ALLOCATION_AGENT && segment != Brig::BRIG_SEGMENT_READONLY) s << "alloc(agent) ";
    }
    else s << invalid("Allocation", alloc) << " ";
    return s.str();
}

const char* Disassembler::const2str_(bool isConst) const
{
    return isConst? "const " : "";
}

string Disassembler::align2str(unsigned val) const
{
    const char *result = HSAIL_ASM::align2str(val);
    if (result != NULL)
    {
        if (strlen(result) > 0)
        {
            return string("align(") + result + ')';
        }
        return "";
    }
    return invalid("align", val);
}

string Disassembler::align2str_(unsigned val, unsigned type) const
{
    assert(!isArrayType(type));
    const char *result = HSAIL_ASM::align2str(val);
    if (result != NULL)
    {
        if (strlen(result) > 0 && val != (unsigned) getNaturalAlignment(type))
        {
            return string("align(") + result + ") ";
        }
        return "";
    }
    return invalid("align", val);
}

const char* Disassembler::width2str(unsigned val) const
{
    const char *result = HSAIL_ASM::width2str(val);
    if (result != NULL) return result;
    return invalid("width", val);
}

void Disassembler::printStringLiteral(SRef s) const
{
    // TBD split when too long
    print('"');
    for(const char *p = s.begin; p != s.end; ++p)
    {
        unsigned char c = (unsigned char)*p;
        switch (c)
        {
        case '\a': print("\\a"); break;
        case '\b': print("\\b"); break;
        case '\f': print("\\f"); break;
        case '\n': print("\\n"); break;
        case '\r': print("\\r"); break;
        case '\t': print("\\t"); break;
        case '\"': print("\\\""); break;
        case '\\': print("\\\\"); break;
        default:
            if (c  >= 32 && c < 127)
            {
                print(c);
            }
            else
            {
                *stream << "\\x" << PrintHex(c);
                //print(format("\\x%02X", c));
            }
            break;
        }
    }
    print('"');
}

void Disassembler::printComment(SRef s) const
{
    for(const char *p = s.begin; p != s.end; ++p)
    {
        unsigned char c = (unsigned char)*p;
        if (c  >= 32 && c < 127)
        {
            print(c);
        }
        else
        {
            print('.');
        }
    }
}

} // namespace HSAIL_ASM

// ============================================================================
// FIXME
// - disassemble 'debug' section!
