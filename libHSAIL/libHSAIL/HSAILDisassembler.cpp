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

#include "HSAILUtilities.h"
#include "HSAILDisassembler.h"

#include <fstream>
#include <iomanip>

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

    for (Directive d = brig.directives().begin(); d != brig.directives().end(); d = next(d))
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

string Disassembler::get(Directive d, unsigned model)  { machineModel = model; return getImpl(d); }
string Disassembler::get(Inst i, unsigned model)       { machineModel = model; return getImpl(i); }
string Disassembler::get(Operand i, unsigned model)    { machineModel = model; return getImpl(i); }

void Disassembler::log(std::ostream &s) { err = &s; }

// ============================================================================
// Directives
// ============================================================================

void Disassembler::printDirectiveFmt(Directive d) const
{
    using namespace Brig;
    assert(d);

    unsigned kind = d.brig()->kind;

    if (kind == BRIG_DIRECTIVE_VERSION)
    {
        machineModel = DirectiveVersion(d).machineModel();
    }

    switch (kind)
    {
    // Skip directives which are used internally and should not be displayed
    case BRIG_DIRECTIVE_VARIABLE_INIT:
    case BRIG_DIRECTIVE_LABEL_INIT:
    case BRIG_DIRECTIVE_IMAGE_INIT:
    case BRIG_DIRECTIVE_SAMPLER_INIT:
        break;

    default:
        if (wantsExtraNewLineBefore(d)) printEOL();

        if (kind == BRIG_DIRECTIVE_ARG_SCOPE_END && indent > 0) --indent;
        if (kind != BRIG_DIRECTIVE_LABEL)                       printIndent();
        if (kind == BRIG_DIRECTIVE_ARG_SCOPE_START)             ++indent;

        printDirective(d);
        printEOL();
    }
}

void Disassembler::printDirective(Directive d) const
{
    using namespace Brig;
    assert(d);

    switch (d.brig()->kind)
    {
    case BRIG_DIRECTIVE_VERSION:         printDirective(DirectiveVersion(d));   break;
    case BRIG_DIRECTIVE_KERNEL:          printDirective(DirectiveKernel(d));    break;
    case BRIG_DIRECTIVE_FUNCTION:        printDirective(DirectiveFunction(d));  break;
    case BRIG_DIRECTIVE_VARIABLE:        printDirective(DirectiveVariable(d));  break;
    case BRIG_DIRECTIVE_LABEL:           printDirective(DirectiveLabel(d));     break;
    case BRIG_DIRECTIVE_COMMENT:         printDirective(DirectiveComment(d));   break;
    case BRIG_DIRECTIVE_CONTROL:         printDirective(DirectiveControl(d));   break;
    case BRIG_DIRECTIVE_EXTENSION:       printDirective(DirectiveExtension(d)); break;
    case BRIG_DIRECTIVE_LOC:             printDirective(DirectiveLoc(d));       break;
    case BRIG_DIRECTIVE_PRAGMA:          printDirective(DirectivePragma(d));    break;
    case BRIG_DIRECTIVE_SIGNATURE:       printDirective(DirectiveSignature(d)); break;
    case BRIG_DIRECTIVE_LABEL_TARGETS:   printDirective(DirectiveLabelTargets(d)); break;
    case BRIG_DIRECTIVE_FBARRIER:        printDirective(DirectiveFbarrier(d));  break;
    case BRIG_DIRECTIVE_BLOCK_START:     printDirective(BlockStart(d));         break;
    case BRIG_DIRECTIVE_BLOCK_END:       printDirective(BlockEnd(d));           break;
    case BRIG_DIRECTIVE_BLOCK_NUMERIC:   printDirective(BlockNumeric(d));       break;
    case BRIG_DIRECTIVE_BLOCK_STRING:    printDirective(BlockString(d));        break;

    case BRIG_DIRECTIVE_ARG_SCOPE_START: printDirective(DirectiveArgScopeStart(d)); break;
    case BRIG_DIRECTIVE_ARG_SCOPE_END:   printDirective(DirectiveArgScopeEnd(d));   break;

    // The following directives should only be displayed as part of other directives
    case BRIG_DIRECTIVE_VARIABLE_INIT:   assert(false); printDirective(DirectiveVariableInit(d));  break;
    case BRIG_DIRECTIVE_LABEL_INIT:      assert(false); printDirective(DirectiveLabelInit(d));     break;
    case BRIG_DIRECTIVE_IMAGE_INIT:      assert(false); printDirective(DirectiveImageInit(d));     break;
    case BRIG_DIRECTIVE_SAMPLER_INIT:    assert(false); printDirective(DirectiveSamplerInit(d));   break;

    default: error(d, "Unsupported Directive Kind", d.brig()->kind); break;
    }
}

void Disassembler::printDirective(DirectiveVersion d) const
{
    print("version ");
    print(d.hsailMajor(), ':');
    print(d.hsailMinor(), ':');
    print(profile2str(d.profile()), ':');
    print(machineModel2str(d.machineModel()), ';');
}

void Disassembler::printDirective(DirectiveComment d) const
{
    printComment(d.name());
}

void Disassembler::printDirective(DirectiveControl d) const
{
    unsigned len = d.elementCount();
    print(controlDirective2str(d.control()));
    printq(len > 0, ' ');

    for (unsigned i = 0; i < len; ++i)
    {
        printq(i != 0, ", ");
        Operand opr = d.values(i);
        if (OperandImmed imm = opr)         printOperandImmed(imm, Brig::BRIG_TYPE_U32);
        else if (OperandWavesize ws = opr)  printOperand(ws);
        else                                error(opr, "Unsupported Operand Kind", opr.kind());
    }

    print(';');
}

void Disassembler::printDirective(BlockStart d) const
{
    print("block ");
    printStringLiteral(d.name());
}

void Disassembler::printDirective(BlockString d) const
{
    print("blockstring ");
    printStringLiteral(d.string());
    print(';');
}

void Disassembler::printDirective(BlockNumeric d) const
{
    print("blocknumeric");
    print_(type2str(d.type()), ' ');
    printValueList(d.data(), d.type(), d.elementCount());
    print(';');
}

void Disassembler::printDirective(BlockEnd d) const
{
    print("endblock;");
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
    printStringLiteral(d.name());
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
        if (DirectiveVariableInit init = d.init()) 
        {
            if (d.modifier().isArray()) print("{");
            printValueList(init.data(), d.type(), init.elementCount());
            if (d.modifier().isArray()) print("}");
        }
        else if (DirectiveLabelInit init = d.init()) 
        {
            print("{");
            printDirective(init);
            print("}");
        }
        else if (DirectiveImageInit init = d.init()) 
        {
            print("{");
            printDirective(init);
            print("}");
        }
        else if (DirectiveSamplerInit init = d.init()) 
        {
            print("{");
            printDirective(init);
            print("}");
        }
    }
    print(';');
}

void Disassembler::printDirective(DirectiveFbarrier d) const
{
    print("fbarrier ", d.name(), ';');
}

void Disassembler::printDirective(DirectiveVariableInit d) const
{
    printValueList(d.data(), d.type(), d.elementCount());
}

void Disassembler::printDirective(DirectiveLabelInit d) const
{
    printLabelList(d.labels());
}

void Disassembler::printDirective(DirectiveImageInit d) const
{
    string valList;
    add2ValList(valList, "geometry",  imageGeometry2str(d.geometry()));
    add2ValList(valList, "width",     d.width());
    add2ValList(valList, "height",    d.height());
    add2ValList(valList, "depth",     d.depth());
    add2ValList(valList, "array",     d.array());
    add2ValList(valList, "format",    imageFormat2str(d.format()));
    add2ValList(valList, "order",     imageOrder2str(d.order()));
    print(valList);
}

void Disassembler::printDirective(DirectiveSamplerInit d) const
{
    string valList;
    add2ValList(valList, "coord",        coord2str(d.modifier().isUnnormalized()));
    add2ValList(valList, "filter",       filter2str(d.modifier().filter()));
    add2ValList(valList, "boundaryu",    boundaryMode2str(d.boundaryU()));
    add2ValList(valList, "boundaryv",    boundaryMode2str(d.boundaryV()));
    add2ValList(valList, "boundaryw",    boundaryMode2str(d.boundaryW()));
    print(valList);
}

void Disassembler::printDirective(DirectiveArgScopeStart d) const
{
    print("{");
}

void Disassembler::printDirective(DirectiveArgScopeEnd d) const
{
    print("}");
}

void Disassembler::printProtoType(DirectiveSignatureArgument arg) const
{
    print(align2str_(arg.align(), arg.type()), "arg");
    print_(type2str(arg.type()));
    if (arg.modifier().isArray())
    {
        print("[");
        if (!arg.modifier().isFlexArray()) print(arg.dim());
        print("]");
    }
}

void Disassembler::printDirective(DirectiveSignature d) const
{
    print("signature ", d.name());
    print("(");
    unsigned i=0;
    if (d.outCount())
    {
        assert(d.outCount() == 1);
        printProtoType(d.args(i++));
    }
    print(")(");
    if (d.inCount())
    {
        for(unsigned const e = d.outCount()+d.inCount()-1; i < e; ++i)
        {
            printProtoType(d.args(i));
            print(", ");
        }
        printProtoType(d.args(i));
    }
    print(")");
    print(";");
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

void Disassembler::printDirective(DirectiveLabelTargets d) const 
{
    print("labeltargets ", d.name(), " = {");
    printLabelList(d.labels());
    print("};");
}

void Disassembler::printDirective(DirectiveKernel d) const
{
    Directive scoped = d.next(); // First directive scoped to this kernel

    print("kernel ", d.name());
    scoped = printArgs(d.firstInArg(), d.inArgCount(), scoped);
    printBody(d.code(), d.instCount(), scoped, d.nextTopLevelDirective());
}

void Disassembler::printDirective(DirectiveFunction d) const
{
    Directive scoped = d.next(); // First directive scoped to this function

    print(attr2str_(d.modifier().linkage()), "function ", d.name());
    scoped = printArgs(d.next(),  d.outArgCount(),  scoped);
    scoped = printArgs(d.firstInArg(),   d.inArgCount(),   scoped);
    printBody(d.code(), d.instCount(), scoped, d.nextTopLevelDirective(), d.modifier().isDeclaration());
}

Directive Disassembler::printArgs(Directive arg, unsigned argNum, Directive scoped) const
{
    print("(");
    if (argNum == 1)
    {
        assert(arg);
        printArgDecl(arg);
        scoped = arg.next();
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
        scoped = arg;
    }
    print(")");
    return scoped;
}



void Disassembler::printBody(Inst inst, unsigned instNum, Directive start, Directive end, bool isDecl /*=false*/) const
{
    if (!isDecl)
    {
        ++indent;
        printEOL();
        print("{");
        printEOL();
        Directive d = start;
        for (int cnt = instNum; cnt > 0; --cnt)
        {
            assert(inst && inst != brig.insts().end());
            // Print scoped directives which are linked to code
            d = printContextDir(inst.brigOffset(), d, end);
            printInstFmt(inst);
            inst = inst.next();
        }

        // This is a special case for handling end of argument scope.
        // In this case the DirectiveScope refers the first instruction AFTER the scope.
        printContextDir(inst.brigOffset(), d, end);
        print("}");
        --indent;
    }
    print(";");
}

// print all directives linked with the specified offset in .code section
Directive Disassembler::printContextDir(Offset off, Directive start, Directive end) const
{
    Directive d = start;
    for(; d && d != end; d = d.next())
    {
        if (DirectiveCode(d) && DirectiveCode(d).code().brigOffset() > off) break;
        printDirectiveFmt(d);
    }

    return d;
}

void Disassembler::printArgDecl(Directive d) const
{
    using namespace Brig;
    assert(d);
    printSymDecl(DirectiveVariable(d));
}

void Disassembler::printSymDecl(DirectiveVariable s) const 
{
    // print space-separated attributes which go before name:
    // extern, static, const, align
    print(attr2str_(s.modifier().linkage()));
    print(const2str_(s.modifier().isConst()));
    print(align2str_(s.align(), s.type()));

    // print symbol segment and type (separated with "_")
    print(seg2str(s.segment()));
    print_(type2str(s.type()), ' ');

    // print symbol name and dimensions (if any)
    print(s.name());

    // dimension
    if (s.modifier().isFlexArray() || (s.dim() == 0 && s.modifier().isArray() && s.modifier().isDeclaration()))
    {
        print("[]");
    }
    else if (s.modifier().isArray())
    {
        print('[', s.dim(), ']');
    }
}

class Disassembler::ValueListPrinter
{
    const Disassembler *m_dasm;
    DataItem            m_data;
    unsigned            m_max;
public:
    ValueListPrinter (const Disassembler* dasm, DataItem data, unsigned max)
        : m_dasm(dasm), m_data(data), m_max(max) { }

    template<typename BrigType>
    void visit() const
    {
        DataItemT< typename BrigType::CType > data = m_data;
        unsigned total = std::min(data.numElements(), m_max);
        if (total > 0)
        {
            unsigned i = 0;
            for(; i < (total - 1); ++i)
            {
                m_dasm->printValue(data[i]);
                m_dasm->print(", ");
            }
            m_dasm->printValue(data[i]);
        }
    }

    void visitNone(unsigned type) const
    {
        assert(false); // TBD095 - Disassembler::ValueListPrinter::visitNone
        //m_dasm->error(sym, "Invalid Initializer Type", type);
    }
};

void Disassembler::printValueList(DataItem data, Brig::BrigType16_t type, unsigned maxElements) const
{
    dispatchByType(type, ValueListPrinter(this, data, maxElements));
}

Directive Disassembler::next(Directive d) const
{
    if (DirectiveExecutable sub = d)
    {
        return sub.nextTopLevelDirective();
    }
    return d.next();
}

// ============================================================================
// INSTRUCTIONS
// ============================================================================

void Disassembler::printInstFmt(Inst i) const
{
    if (i.opcode() == Brig::BRIG_OPCODE_CODEBLOCKEND) return;

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

    switch(i.brig()->kind)
    {
    case BRIG_INST_BASIC:        printInst(InstBasic(i));       break;
    case BRIG_INST_ADDR:         printInst(InstAddr(i));        break;
    case BRIG_INST_MOD:          printInst(InstMod(i));         break;
    case BRIG_INST_CVT:          printInst(InstCvt(i));         break;
    case BRIG_INST_MEM_FENCE:    printInst(InstMemFence(i));    break;
    case BRIG_INST_CMP:          printInst(InstCmp(i));         break;
    case BRIG_INST_MEM:          printInst(InstMem(i));         break;
    case BRIG_INST_BR:           printInst(InstBr(i));          break;
    case BRIG_INST_ATOMIC:       printInst(InstAtomic(i));      break;
    case BRIG_INST_ATOMIC_IMAGE: printInst(InstAtomicImage(i)); break;
    case BRIG_INST_IMAGE:        printInst(InstImage(i));       break;
    case BRIG_INST_LANE:         printInst(InstLane(i));        break;
    case BRIG_INST_QUEUE:        printInst(InstQueue(i));       break;
    case BRIG_INST_SEG:          printInst(InstSeg(i));         break;
    case BRIG_INST_SEG_CVT:      printInst(InstSegCvt(i));      break;
    case BRIG_INST_SOURCE_TYPE:  printInst(InstSourceType(i));  break;
    case BRIG_INST_SIGNAL:       printInst(InstSignal(i));      break;
    case BRIG_INST_NONE:         printNop();                    break;
    default: error(i, "Unsupported Instruction Format", i.brig()->kind); break;
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
    AluModifier am = i.modifier();
    unsigned rounding = am.round();
    unsigned defaultRounding = getDefRounding(i);
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
    if (!isGcnInst(i)) print_(seg2str(i.segment()));
    print_(type2str(i.type()));
    printInstArgs(i);
}

void Disassembler::printInst(InstBr i) const
{
    print(opcode2str(i.opcode()));
    print_width(i);
    if (instHasType(i.opcode())) print_(type2str(i.type()));
    if (isCall(i)) printCallArgs(i);
    else printInstArgs(i);
}

void Disassembler::printInst(InstMem i) const
{
    print(opcode2str(i.opcode()));
    print_v(i);
    print_(seg2str(i.segment()));
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
    print_rounding(i);
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
    print_width(i);
    print_(type2str(i.type()));
    if (i.sourceType() != Brig::BRIG_TYPE_NONE) print_(type2str(i.sourceType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstAtomicImage i) const
{
    print(opcode2str(i.opcode()));
    print_(atomicOperation2str(i.atomicOperation()));
    print_(imageGeometry2str(i.geometry()));
    print_(equiv2str(i.equivClass()));
    print_(type2str(i.type()));
    print_(type2str(i.imageType()));
    print_(type2str(i.coordType()));
    printInstArgs(i);
}

void Disassembler::printInst(InstMemFence i) const
{
    print(opcode2str(i.opcode()));

    print_(memoryFenceSegments2str(i.segments()));
    print_(memoryOrder2str(i.memoryOrder()));
    print_(memoryScope2str(i.memoryScope()));

    if (instHasType(i.opcode())) print_(type2str(i.type()));
    printInstArgs(i);
}

void Disassembler::printInst(InstSignal i) const 
{
    print(opcode2str(i.opcode()));
    print_(signalOperation2str(i.signalOperation()));
    print_(memoryOrder2str(i.memoryOrder()));
    print_(type2str(i.type()));
    print_(type2str(i.signalType()));
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
    if (getDefWidth(inst) != inst.width())
    {
        print_(width2str(inst.width()));
    }
}

void Disassembler::printInstArgs(Inst i, int firstArg /*=0*/, int lastArg /*=BRIG_OPERANDS_NUM*/) const
{
    if (i.operand(firstArg))
    {
        printSeparator();
        for (int k = firstArg; k < lastArg && i.operand(k); ++k)
        {
            printq(k > firstArg, ", ");
            printOperand(i, k);
        }
    }
}

void Disassembler::printCallArgs(Inst i) const
{
    assert(i.opcode() == Brig::BRIG_OPCODE_CALL);
    assert(i.operand(1));

    printSeparator();
    printOperand(i, 1); // target

    if (OperandArgumentList list = i.operand(0))   // output args
    {
        if (list.elementCount() > 0)
        {
            print(' ');
            printOperand(i, 0);
        }
    }
    if (i.operand(2))   // input args
    {
        print(' '); printOperand(i, 2);
    }
    if (i.operand(3))   // list of possible targets
    {
        print(' '); printOperand(i, 3);
    }
}

// ============================================================================
// OPERANDS
// ============================================================================

void Disassembler::printOperand(Inst inst, unsigned operandIdx) const
{
    using namespace Brig;
    assert(inst && operandIdx <= 4);

    Operand opr = inst.operand(operandIdx);
    assert(opr);

    if (OperandImmed(opr)) {
        printOperandImmed(inst, operandIdx);
    } else {
        printOperand(opr);
    }
}

void Disassembler::printOperand(Operand opr) const 
{
    using namespace Brig;
    assert(opr);

    switch (opr.brig()->kind)
    {
    case BRIG_OPERAND_REG:                printOperand(OperandReg(opr));              break;
    case BRIG_OPERAND_REG_VECTOR:         printOperand(OperandRegVector(opr));        break;
    case BRIG_OPERAND_ADDRESS:            printOperand(OperandAddress(opr));          break;
    case BRIG_OPERAND_WAVESIZE:           printOperand(OperandWavesize(opr));         break;
                                                                                      
    case BRIG_OPERAND_LABEL_REF:          printOperand(OperandLabelRef(opr));         break;
    case BRIG_OPERAND_LABEL_TARGETS_REF:  printOperand(OperandLabelTargetsRef(opr));  break;
    case BRIG_OPERAND_LABEL_VARIABLE_REF: printOperand(OperandLabelVariableRef(opr)); break;
    case BRIG_OPERAND_FUNCTION_REF:       printOperand(OperandFunctionRef(opr));      break;
    case BRIG_OPERAND_SIGNATURE_REF:      printOperand(OperandSignatureRef(opr));     break;
    case BRIG_OPERAND_FBARRIER_REF:       printOperand(OperandFbarrierRef(opr));      break;
                                                                                      
    case BRIG_OPERAND_ARGUMENT_LIST:      printOperand(OperandArgumentList(opr));     break;
    case BRIG_OPERAND_FUNCTION_LIST:      printOperand(OperandFunctionList(opr));     break;
                                          
//    case BRIG_OPERAND_IMMED:              printOperandImmed(opr, OperandImmed(opr).type()); break;

    default: error(opr, "Unsupported Operand Kind", opr.brig()->kind); break;
    }
}

void Disassembler::printOperand(OperandReg opr) const
{
    assert(opr);
    print(opr.reg());
}

void Disassembler::printOperand(OperandRegVector operand) const
{
    print('(');

    for(int i = 0; i < operand.regCount(); i++)
    {
        printq(i > 0, ',');
        print(operand.regs(i));
    }

    print(')');
}

void Disassembler::printOperand(OperandWavesize opr) const { print("WAVESIZE"); }

void Disassembler::printOperand(OperandAddress opr) const
{
    assert(machineModel == Brig::BRIG_MACHINE_SMALL || machineModel == Brig::BRIG_MACHINE_LARGE);

    DirectiveVariable name = opr.symbol();
    int64_t offset = (machineModel == Brig::BRIG_MACHINE_LARGE)
      ? (int64_t)opr.offset()
      : (int32_t)opr.offsetLo();
    uint64_t uoffset = (machineModel == Brig::BRIG_MACHINE_LARGE)
      ? (uint64_t)opr.offset()
      : (uint32_t)opr.offsetLo();
    StrRef reg = opr.reg();

    if (name)
    {
        print('[', getSymbolName(name), ']');
    }

    if (reg.deref())
    {
        print('[', reg);
        printq(offset > 0, '+',  offset);
        printq(offset < 0, '-', -offset);
        print(']');
    }
    // if there is no register, we always print the offset as unsigned
    else if (offset != 0 || !name)  // [0] is a special case
    {
        print('[', uoffset, ']');
    }
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

class Disassembler::DisassembleOperandImmed
{
    const Disassembler& m_self;
    OperandImmed  m_op;

public:
    DisassembleOperandImmed(const Disassembler& self, OperandImmed op) : m_self(self), m_op(op) {}

    template <typename BrigType>
    void visit()
    {
        m_self.printValue(*reinterpret_cast<const typename BrigType::CType*>(&m_op.brig()->bytes[0]));
    }

    void visitNone(unsigned type) const { m_self.error(m_op, "Unsupported Imm Operand Type", type); }
};

template <>
void Disassembler::DisassembleOperandImmed::visit< BrigType<Brig::BRIG_TYPE_B1> >() // special case for bool
{
    m_self.printValue(m_op.bytes(0) & 0x1U);
}

void Disassembler::printOperandImmed(Inst inst, unsigned operandIdx) const
{
    assert(inst && operandIdx <= 4);
    assert(machineModel == Brig::BRIG_MACHINE_SMALL || machineModel == Brig::BRIG_MACHINE_LARGE);

    unsigned requiredType = getOperandType(inst, operandIdx, machineModel);
    if (!isValidImmType(requiredType))
    {
        // This BRIG is invalid as there are no imm values for these types.
        // Replace it with some valid type to avoid failing in printOperandImmed.
        requiredType = Brig::BRIG_TYPE_B32;
    }
    else if (requiredType == Brig::BRIG_TYPE_B128)
    {
        // There are no b128 imm operands, only packed imms may be 128 bit wide.
        // So replace b128 with any 128-bit packed type
        requiredType = Brig::BRIG_TYPE_U8X16; 
    }
    printOperandImmed(inst.operand(operandIdx), requiredType);
}

void Disassembler::printOperandImmed(OperandImmed imm, unsigned requiredType) const
{
    assert(imm);
    DisassembleOperandImmed disassembleOperandImmed(*this, imm);
    dispatchByType(requiredType, disassembleOperandImmed);
}

void Disassembler::printOperand(OperandLabelRef opr) const
{
    assert(opr.ref());

    Directive d = opr.ref();

    if (DirectiveLabel lab = d)
    {
        print(lab.name());
    }
    else
    {
        assert(false);
    }
}

void Disassembler::printOperand(OperandLabelTargetsRef opr) const 
{
    assert(opr.ref());

    Directive d = opr.ref();

    if (DirectiveLabelTargets targets = d)
    {
        print(targets.name());
    }
    else
    {
        assert(false);
    }
}

void Disassembler::printOperand(OperandLabelVariableRef opr) const 
{
    assert(opr.ref());

    Directive d = opr.ref();

    if (DirectiveVariable var = d)
    {
        print(var.name());
    }
    else
    {
        assert(false);
    }
}

void Disassembler::printOperand(OperandFunctionRef opr) const
{
    assert(opr.fn());
    if (DirectiveFunction fx = opr.fn())
    {
        print(fx.name());
    }
    else
    {
        assert(false);
    }
}

void Disassembler::printOperand(OperandSignatureRef opr) const
{
    assert(opr.sig());
    if (DirectiveSignature sig = opr.sig())
    {
        print(sig.name());
    }
    else
    {
        assert(false);
    }
}

void Disassembler::printOperand(OperandArgumentList opr) const
{
    print('(');

    unsigned size = opr.elementCount();
    if (size == 1 && !opr.elements()[0]) size = 0; // special case - an empty list

    for (unsigned i = 0; i < size; ++i)
    {
        printq(i != 0, ", ");
        print(getSymbolName(opr.elements(i)));
    }

    print(')');
}

void Disassembler::printOperand(OperandFunctionList opr) const
{
    print('[');

    for (unsigned i = 0; i < opr.elementCount(); ++i)
    {
        printq(i != 0, ", ");
        DirectiveFunction fn = opr.elements(i);
        if (fn) print(fn.name());
    }

    print(']');
}

void Disassembler::printOperand(OperandFbarrierRef opr) const
{
    print(getSymbolName(opr.fbar()));
}

SRef Disassembler::getSymbolName(Directive d) const
{
    if (DirectiveFunction      sym = d) return sym.name();
    else if (DirectiveKernel   sym = d) return sym.name();
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
    default:               return invalid("Machine", model);
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

const char* Disassembler::seg2str(Brig::BrigSegment8_t segment) const 
{
    const char *result = HSAIL_ASM::segment2str(segment);
    if (result != NULL) return result;
    else return invalid("Segment", segment);
}

const char* Disassembler::type2str(unsigned t) const
{
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
    else return invalid("Geom", g);
}

const char* Disassembler::memoryOrder2str(unsigned memOrder) const 
{
    const char* result=HSAIL_ASM::memoryOrder2str(memOrder);
    if (result != NULL) return result;
    else return invalid("MemoryOrder", memOrder);
}

const char* Disassembler::memoryFenceSegments2str(unsigned segments) const
{
  switch(segments) {
  case Brig::BRIG_MEMORY_FENCE_GROUP:
    return segment2str(Brig::BRIG_SEGMENT_GROUP);
  case Brig::BRIG_MEMORY_FENCE_GLOBAL:
    return segment2str(Brig::BRIG_SEGMENT_GLOBAL);
  default:
    return "";
  }
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

const char* Disassembler::signalOperation2str(unsigned op) const
{
    const char* result=HSAIL_ASM::signalOperation2str(op);
    if (result != NULL) return result;
    else return invalid("SignalOperation", op);
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
    else return invalid("round aluModifiers", val);
}

string Disassembler::modifiers2str(AluModifier mod) const
{
    ostringstream s;
    if (mod.ftz()) s << "_ftz";
    return s.str().c_str();
}

const char* Disassembler::v2str(Operand opr) const
{
    if (OperandRegVector vec = opr)
    {
        switch(vec.regCount())
        {
        case 2: return "v2";
        case 3: return "v3";
        case 4: return "v4";
        default: return invalid("vX register count", vec.regCount());
        }
    }
    else if (OperandReg(opr) || OperandImmed(opr) || OperandWavesize(opr))
    {
        return "";
    }
    return invalid("vX operand", opr? opr.kind() : -1);
}

const char* Disassembler::imageFormat2str(Brig::BrigImageFormat8_t fmt) const
{
    const char *result = HSAIL_ASM::imageFormat2str(fmt);
    if (result != NULL) return result;
    else return invalid("ImageFormat", fmt);
}

const char* Disassembler::imageOrder2str(Brig::BrigImageOrder8_t order) const
{
    const char *result = HSAIL_ASM::imageOrder2str(order);
    if (result != NULL) return result;
    else return invalid("ImageOrder", order);
}

const char* Disassembler::filter2str(uint8_t val) const
{
    switch (val)
    {
    case Brig::BRIG_FILTER_LINEAR:  return "linear";
    case Brig::BRIG_FILTER_NEAREST: return "nearest";
    default: return "";
    }
}

const char* Disassembler::coord2str(bool inUnnormalized) const
{
    return inUnnormalized ? "unnormalized" : "normalized";
}

const char* Disassembler::boundaryMode2str(uint8_t val) const
{
    switch (val)
    {
    case Brig::BRIG_BOUNDARY_UNDEFINED:  return "undefined";
    case Brig::BRIG_BOUNDARY_CLAMP:      return "clamp";
    case Brig::BRIG_BOUNDARY_WRAP:       return "wrap";
    case Brig::BRIG_BOUNDARY_MIRROR:     return "mirror";
    case Brig::BRIG_BOUNDARY_MIRRORONCE: return "mirroronce";
    case Brig::BRIG_BOUNDARY_BORDER:     return "border";
    default: return "";
    }
}

string Disassembler::equiv2str(unsigned val) const
{
    ostringstream s;
    if (val != 0) s << "equiv(" << val << ')';
    return s.str();
}


string Disassembler::attr2str_(Brig::BrigLinkage8_t attr) const
{
    ostringstream s;
    const char *c_str = HSAIL_ASM::linkage2str(attr);
    if (c_str != NULL)
    {
        if (strlen(c_str) > 0) s << c_str << " ";
        else {} // keep s empty
    }
    else s << invalid("Attribute", attr) << " ";
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
    const char *result = HSAIL_ASM::align2str(val);
    if (result != NULL)
    {
        if (strlen(result) > 0 && val != (unsigned) getNaturalAlignment(type))
        {
            return string("align ") + result + ' ';
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

bool Disassembler::isCall(Inst i) const
{
    return i.opcode() == Brig::BRIG_OPCODE_CALL;
}

bool Disassembler::isBranch(Inst i) const
{
    return i.opcode() == Brig::BRIG_OPCODE_CBR || i.opcode() == Brig::BRIG_OPCODE_BRN;
}

bool Disassembler::isGcnInst(Inst i) const
{
    using namespace Brig;
    assert(i);

    switch(i.opcode())
    {
    case BRIG_OPCODE_GCNMADU:
    case BRIG_OPCODE_GCNMADS:
    case BRIG_OPCODE_GCNMAX3:
    case BRIG_OPCODE_GCNMIN3:
    case BRIG_OPCODE_GCNMED3:
    case BRIG_OPCODE_GCNFLDEXP:
    case BRIG_OPCODE_GCNFREXP_EXP:
    case BRIG_OPCODE_GCNFREXP_MANT:
    case BRIG_OPCODE_GCNTRIG_PREOP:
    case BRIG_OPCODE_GCNBFM:
    case BRIG_OPCODE_GCNLD:
    case BRIG_OPCODE_GCNST:
    case BRIG_OPCODE_GCNATOMIC:
    case BRIG_OPCODE_GCNATOMICNORET:
    case BRIG_OPCODE_GCNSLEEP:
    case BRIG_OPCODE_GCNPRIORITY:
    case BRIG_OPCODE_GCNREGIONALLOC:
    case BRIG_OPCODE_GCNMSAD:
    case BRIG_OPCODE_GCNQSAD:
    case BRIG_OPCODE_GCNMQSAD:
    case BRIG_OPCODE_GCNMQSAD4:
    case BRIG_OPCODE_GCNSADW:
    case BRIG_OPCODE_GCNSADD:
    case BRIG_OPCODE_GCNCONSUME:
    case BRIG_OPCODE_GCNAPPEND:
        return true;
    default:
        return false;
    }
}

} // namespace HSAIL_ASM

// ============================================================================
// FIXME
// - disassemble 'debug' section!
