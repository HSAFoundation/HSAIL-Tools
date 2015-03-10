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
#include "HSAILUtilities.h"
#include "HSAILParser.h"
#include "HSAILFloats.h"
#include "HSAILDump.h"
#include <iosfwd>
#include <sstream>
#include <iosfwd>

namespace HSAIL_ASM
{

using namespace std;

typedef Optional<unsigned> OptionalU;

struct ModuleStatementPrefix
{
    OptionalU decl, linkage, indirect, alloc;
};

// Mnemo parsers


Brig::BrigWidth toBrigWidth(uint32_t v)
{
    assert( (v & (v-1))==0 ); // must be a power of two
    switch(v) {
    case 1u          : return Brig::BRIG_WIDTH_1;
    case 2u          : return Brig::BRIG_WIDTH_2;
    case 4u          : return Brig::BRIG_WIDTH_4;
    case 8u          : return Brig::BRIG_WIDTH_8;
    case 16u         : return Brig::BRIG_WIDTH_16;
    case 32u         : return Brig::BRIG_WIDTH_32;
    case 64u         : return Brig::BRIG_WIDTH_64;
    case 128u        : return Brig::BRIG_WIDTH_128;
    case 256u        : return Brig::BRIG_WIDTH_256;
    case 512u        : return Brig::BRIG_WIDTH_512;
    case 1024u       : return Brig::BRIG_WIDTH_1024;
    case 2048u       : return Brig::BRIG_WIDTH_2048;
    case 4096u       : return Brig::BRIG_WIDTH_4096;
    case 8192u       : return Brig::BRIG_WIDTH_8192;
    case 16384u      : return Brig::BRIG_WIDTH_16384;
    case 32768u      : return Brig::BRIG_WIDTH_32768;
    case 65536u      : return Brig::BRIG_WIDTH_65536;
    case 131072u     : return Brig::BRIG_WIDTH_131072;
    case 262144u     : return Brig::BRIG_WIDTH_262144;
    case 524288u     : return Brig::BRIG_WIDTH_524288;
    case 1048576u    : return Brig::BRIG_WIDTH_1048576;
    case 2097152u    : return Brig::BRIG_WIDTH_2097152;
    case 4194304u    : return Brig::BRIG_WIDTH_4194304;
    case 8388608u    : return Brig::BRIG_WIDTH_8388608;
    case 16777216u   : return Brig::BRIG_WIDTH_16777216;
    case 33554432u   : return Brig::BRIG_WIDTH_33554432;
    case 67108864u   : return Brig::BRIG_WIDTH_67108864;
    case 134217728u  : return Brig::BRIG_WIDTH_134217728;
    case 268435456u  : return Brig::BRIG_WIDTH_268435456;
    case 536870912u  : return Brig::BRIG_WIDTH_536870912;
    case 1073741824u : return Brig::BRIG_WIDTH_1073741824;
    case 2147483648u : return Brig::BRIG_WIDTH_2147483648;
    default: assert(false);
    }
    return Brig::BRIG_WIDTH_NONE;
}

OptionalU tryParseWidthModifier(Scanner& scanner) {
    OptionalU res;
    if (scanner.tryEatToken(EMWidth)) {
        scanner.eatToken(ELParen);
        switch(scanner.peek().kind()) {
        case EKWWidthAll:    scanner.scan(); res = Brig::BRIG_WIDTH_ALL;      break;
        case EWaveSizeMacro: scanner.scan(); res = Brig::BRIG_WIDTH_WAVESIZE; break;
        default:
            uint64_t const width = scanner.readIntLiteral();
            if (width < 1ull || width > 2147483648ull) {
                scanner.syntaxError("Invalid width");
            }
            if (width & (width-1)) {
                scanner.syntaxError("Width must be a power of two");
            }
            res = toBrigWidth((uint32_t)width);
            break;
        }
        scanner.eatToken(ERParen);
    }
    return res;
}

static unsigned parseAlign(Scanner& scanner) {
    scanner.eatToken(ELParen);
    unsigned res = num2align(scanner.readIntLiteral());
    if (res == Brig::BRIG_ALIGNMENT_LAST) {
        scanner.syntaxError("Invalid alignment");
    }
    scanner.eatToken(ERParen);
    return res;
}

OptionalU tryParseEquiv(Scanner& scanner) {
    if (scanner.tryEatToken(EMEquiv)) {
        scanner.eatToken(ELParen);
        uint64_t equivClass = scanner.readIntLiteral();
        if (equivClass >= 256) {
            scanner.syntaxError("equivalence class should be in the 0..255 range");
        }
        scanner.eatToken(ERParen);
        return OptionalU((unsigned)equivClass);
    }
    return OptionalU();
}

Inst parseMnemoBasic(Scanner& scanner, Brigantine& bw, bool expectType) {
    unsigned const opCode = scanner.eatToken(EInstruction);

    OptionalU type;
    if (expectType) type = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstBasic inst = bw.addInst<InstBasic>(opCode);
    inst.type() = type.isInitialized() ? Brig::BrigTypeX(type.value()) : Brig::BRIG_TYPE_NONE;
    return inst;
}

Inst parseMnemoBasic(Scanner& scanner, Brigantine& bw, int*) {
    return parseMnemoBasic(scanner,bw,true);
}

Inst parseMnemoBasicNoType(Scanner& scanner, Brigantine& bw, int*) {
    Inst res = parseMnemoBasic(scanner,bw,false);
    if (isGcnInst(res.opcode())) res.type() = Brig::BRIG_TYPE_B32; // default type for GCN
    return res;
}

Inst parseMnemoBasicOrMod(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode  = scanner.eatToken(EInstruction);
    OptionalU const ftz     = scanner.tryEatToken(EMFTZ);
    OptionalU const round   = scanner.tryEatToken(EMRound);
    OptionalU const packing = scanner.tryEatToken(EMPacking);
    unsigned  const type    = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    if (ftz.isInitialized() || round.isInitialized() || packing.isInitialized()) {
        InstMod inst = bw.addInst<InstMod>(opCode);
        inst.modifier().ftz() = ftz.isInitialized();
        inst.pack() = packing.isInitialized() ? Brig::BrigPack(packing.value()) : Brig::BRIG_PACK_NONE;
        inst.type() = type;

        // NB: getDefRounding must be called after all other fields are initialized
        inst.round() = round.isInitialized() ? round.value() : getDefRounding(inst, bw.getMachineModel(), bw.getProfile());

        return inst;
    } else {
        InstBasic inst = bw.addInst<InstBasic>(opCode);
        inst.type() = type;
        return inst;
    }
}

Inst parseMnemoSourceType(Scanner& scanner, Brigantine& bw, int* outVector/* out */) {
    unsigned  const opCode  = scanner.eatToken(EInstruction);
    OptionalU const vector = scanner.tryEatToken(EMVector);
    unsigned  const dtype  = scanner.eatToken(EMType);
    unsigned  const stype  = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstSourceType inst = bw.addInst<InstSourceType>(opCode);
    inst.sourceType() = stype;
    inst.type() = dtype;
    if (outVector!=NULL) {
        *outVector = vector.isInitialized() ? vector.value() : 1;
    }
    return inst;
}

Inst parseMnemoSeg(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const  opCode = scanner.eatToken(EInstruction);
    OptionalU const segment = scanner.tryEatToken(EMSegment);
    unsigned  const    type = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstSeg inst = bw.addInst<InstSeg>(opCode);
    inst.segment() = segment.isInitialized()  ? Brig::BrigSegment(segment.value()) : Brig::BRIG_SEGMENT_FLAT;
    inst.type() = type;
    return inst;
}

Inst parseMnemoAddr(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const  opCode = scanner.eatToken(EInstruction);
    OptionalU const segment = scanner.tryEatToken(EMSegment);
    unsigned  const    type = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstAddr inst = bw.addInst<InstAddr>(opCode);
    inst.segment() = segment.isInitialized() ?
        segment.value() :
        isGcnInst(inst.opcode())? Brig::BRIG_SEGMENT_AMD_GCN : Brig::BRIG_SEGMENT_FLAT;
    inst.type() = type;
    return inst;
}

Inst parseMnemoMem(Scanner& scanner, Brigantine& bw, int* outVector/* out */) {
    unsigned  const opCode     = scanner.eatToken(EInstruction);
    OptionalU const vector     = scanner.tryEatToken(EMVector);
    OptionalU       segment    = scanner.tryEatToken(EMSegment);

    if (opCode==Brig::BRIG_OPCODE_ALLOCA && segment.isInitialized()) {
        scanner.syntaxError("segment modifier is not supported");
    }

    OptionalU align;
    if (scanner.tryEatToken(EMAlign).isInitialized()) {
        align = parseAlign(scanner);
    }
    OptionalU const isConst    = scanner.tryEatToken(EMConst);
    OptionalU const equivClass = tryParseEquiv(scanner);

    if (opCode==Brig::BRIG_OPCODE_ALLOCA && equivClass.isInitialized()) {
        scanner.syntaxError("equiv modifier is not supported");
    }

    OptionalU const width      = tryParseWidthModifier(scanner);
    unsigned  const type       = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstMem inst = bw.addInst<InstMem>(opCode);
    inst.type()       = type;
    inst.segment()    = segment.isInitialized() ?    Brig::BrigSegment(segment.value())    : Brig::BRIG_SEGMENT_FLAT;
    inst.equivClass() = equivClass.isInitialized() ? equivClass.value() : 0;
    inst.width()      = width.isInitialized() ?      width.value()      : getDefWidth(inst, bw.getMachineModel(), bw.getProfile());
    inst.align()      = align.isInitialized() ?      align.value()      : Brig::BRIG_ALIGNMENT_1;
    inst.modifier().isConst()  = isConst.isInitialized();

    if (opCode==Brig::BRIG_OPCODE_ALLOCA) {
        inst.segment() = Brig::BRIG_SEGMENT_PRIVATE;
    }

    if (outVector!=NULL) {
        *outVector = vector.isInitialized() ? vector.value() : 1;
    }
    return inst;
}

Inst parseMnemoBr(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode = scanner.eatToken(EInstruction);
    OptionalU const  width = tryParseWidthModifier(scanner);
    if (width.isInitialized()) {
        if (opCode==Brig::BRIG_OPCODE_WAVEBARRIER ||
            opCode==Brig::BRIG_OPCODE_CALL ||
            opCode==Brig::BRIG_OPCODE_BR) {
            scanner.syntaxError("width modifier is not supported");
        }
    }
    OptionalU const type = scanner.tryEatToken(EMType);
    if (type.isInitialized() && !instHasType(opCode)) {
        scanner.syntaxError("instruction has no type");
    }

    scanner.eatToken(EMNone);
    // parse done

    InstBr inst = bw.addInst<InstBr>(opCode,Brig::BRIG_TYPE_NONE);

    inst.type() = type.isInitialized() ? type.value() : Brig::BRIG_TYPE_NONE;

    if (width.isInitialized()) {
        inst.width() = Brig::BrigWidth(width.value());
    } else {
        inst.width() = getDefWidth(inst, bw.getMachineModel(), bw.getProfile());
    }

    return inst;
}

Inst parseMnemoCmp(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode  = scanner.eatToken(EInstruction);
    unsigned  const compOp  = scanner.eatToken(EMCompare);
    OptionalU const ftz     = scanner.tryEatToken(EMFTZ);
    OptionalU const packing = scanner.tryEatToken(EMPacking);
    unsigned  const dstType = scanner.eatToken(EMType, "destination type");
    unsigned  const srcType = scanner.eatToken(EMType, "source type");
    scanner.eatToken(EMNone);
    // parse done

    InstCmp inst = bw.addInst<InstCmp>(opCode,dstType);
    inst.compare()        = compOp;
    inst.sourceType()     = srcType;
    inst.modifier().ftz() = ftz.isInitialized();
    inst.pack()           = packing.isInitialized() ? Brig::BrigPack(packing.value()) : Brig::BRIG_PACK_NONE;
    return inst;
}

Inst parseMnemoCvt(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode  = scanner.eatToken(EInstruction);
    OptionalU const ftz     = scanner.tryEatToken(EMFTZ); // TBD
    OptionalU const round   = scanner.tryEatToken(EMRound); // TBD is this correct?
    unsigned  const dstType = scanner.eatToken(EMType, "destination type");
    unsigned  const srcType = scanner.eatToken(EMType, "source type");
    scanner.eatToken(EMNone);
    // parse done

    InstCvt inst = bw.addInst<InstCvt>(opCode,dstType);
    inst.sourceType()       = srcType;
    inst.modifier().ftz()   = ftz.isInitialized();

    // NB: getDefRounding must be called after all other fields are initialized
    inst.round() = round.isInitialized() ? round.value() : getDefRounding(inst, bw.getMachineModel(), bw.getProfile());

    return inst;
}

Inst parseMnemoAtomic(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode          = scanner.eatToken(EInstruction);
    unsigned  const atomicOperation = scanner.eatToken(EMAtomicOp);
    OptionalU const segment         = scanner.tryEatToken(EMSegment);
    unsigned  const memoryOrder     = scanner.eatToken(EMMemoryOrder);
    unsigned  const memoryScope     = scanner.eatToken(EMMemoryScope);
    OptionalU const equivClass      = tryParseEquiv(scanner);
    unsigned  const type            = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstAtomic inst = bw.addInst<InstAtomic>(opCode,type);
    inst.atomicOperation() = atomicOperation;
    inst.segment()         = segment.isInitialized() ? Brig::BrigSegment(segment.value()) : Brig::BRIG_SEGMENT_FLAT;
    inst.equivClass()      = equivClass.isInitialized() ? equivClass.value() : 0;
    inst.memoryOrder()     = memoryOrder;
    inst.memoryScope()     = memoryScope;
    return inst;
}

Inst parseMnemoMemFence(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode      = scanner.eatToken(EInstruction);
    unsigned  const memoryOrder = scanner.eatToken(EMMemoryOrder);
    unsigned  const memoryScope = scanner.eatToken(EMMemoryScope);
    scanner.eatToken(EMNone);
    // parse done

    InstMemFence inst = bw.addInst<InstMemFence>(opCode,Brig::BRIG_TYPE_NONE);

    inst.memoryOrder()              = memoryOrder;
    inst.globalSegmentMemoryScope() = memoryScope;
    inst.groupSegmentMemoryScope()  = memoryScope;
    inst.imageSegmentMemoryScope()  = Brig::BRIG_MEMORY_SCOPE_NONE;
    return inst;
}

Inst parseMnemoImage(Scanner& scanner, Brigantine& bw, int* outVector/* out */) {
    unsigned  const opCode  = scanner.eatToken(EInstruction);
    OptionalU const vector     = scanner.tryEatToken(EMVector);
    unsigned  const geom       = scanner.eatToken(EMGeom);
    OptionalU const equivClass = tryParseEquiv(scanner);
    unsigned  const dstType    = scanner.eatToken(EMType);
    unsigned  const imgType    = scanner.eatToken(EMType);
    unsigned  const coordType  = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstImage inst    = bw.addInst<InstImage>(opCode,dstType);
    inst.equivClass() = equivClass.isInitialized() ? equivClass.value() : 0;
    inst.geometry()   = geom;
    inst.imageType()  = imgType;
    inst.coordType()  = coordType;

    if (outVector!=NULL) {
        *outVector = vector.isInitialized() ? vector.value() : 1;
    }

    return inst;
}

Inst parseMnemoQueryImage(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode          = scanner.eatToken(EInstruction);
    unsigned  const geom            = scanner.eatToken(EMGeom);
    unsigned  const query           = scanner.eatToken(EMImageQuery);
    unsigned  const dstType         = scanner.eatToken(EMType);
    unsigned  const imgType         = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstQueryImage inst    = bw.addInst<InstQueryImage>(opCode,dstType);
    inst.geometry()        = geom;
    inst.imageQuery()      = query;
    inst.imageType()       = imgType;
    return inst;
}

Inst parseMnemoQuerySampler(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode          = scanner.eatToken(EInstruction);
    unsigned  const query           = scanner.eatToken(EMSamplerQuery);
    unsigned  const dstType         = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstQuerySampler inst  = bw.addInst<InstQuerySampler>(opCode,dstType);
    inst.samplerQuery()    = query;
    return inst;
}

Inst parseMnemoLane(Scanner& scanner, Brigantine& bw, int* outVector/* out */) {
    unsigned  const opCode  = scanner.eatToken(EInstruction);
    OptionalU const vector = scanner.tryEatToken(EMVector);
    OptionalU const width  = tryParseWidthModifier(scanner);
    unsigned  const dtype  = scanner.eatToken(EMType);
    OptionalU const stype  = scanner.tryEatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstLane inst = bw.addInst<InstLane>(opCode);
    inst.sourceType() = stype.isInitialized() ? stype.value() : Brig::BRIG_TYPE_NONE;
    inst.width() = width.isInitialized() ? width.value() : getDefWidth(inst, bw.getMachineModel(), bw.getProfile());
    inst.type() = dtype;

    if (outVector!=NULL) {
        *outVector = vector.isInitialized() ? vector.value() : 1;
    }
    return inst;
}

Inst parseMnemoNop(Scanner& scanner, Brigantine& bw, int*) {
    scanner.eatToken(EInstruction);
    InstBasic inst = bw.addInst<InstBasic>(Brig::BRIG_OPCODE_NOP);
    inst.type() = Brig::BRIG_TYPE_NONE;
    return inst;
}

Inst parseMnemoQueue(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode      = scanner.eatToken(EInstruction);
    OptionalU const segment     = scanner.tryEatToken(EMSegment);
    unsigned  const memoryOrder = scanner.eatToken(EMMemoryOrder);
    unsigned  const type        = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstQueue inst = bw.addInst<InstQueue>(opCode);
    inst.segment() = segment.isInitialized()  ? Brig::BrigSegment(segment.value()) : Brig::BRIG_SEGMENT_FLAT;
    inst.memoryOrder() = memoryOrder;
    inst.type() = type;
    return inst;
}

Inst parseMnemoSignal(Scanner& scanner, Brigantine& bw, int*) {
    unsigned const opCode          = scanner.eatToken(EInstruction);
    unsigned const signalOperation = scanner.eatToken(EMAtomicOp);
    unsigned const memoryOrder     = scanner.eatToken(EMMemoryOrder);
    unsigned const type            = scanner.eatToken(EMType);
    unsigned const signalType      = scanner.eatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstSignal inst = bw.addInst<InstSignal>(opCode);
    inst.signalOperation() = signalOperation;
    inst.memoryOrder() = memoryOrder;
    inst.type() = type;
    inst.signalType() = signalType;
    return inst;
}

Inst parseMnemoSegCvt(Scanner& scanner, Brigantine& bw, int*) {
    unsigned  const opCode   = scanner.eatToken(EInstruction);
    OptionalU const segment  = scanner.tryEatToken(EMSegment);
    OptionalU const isNoNull = scanner.tryEatToken(EMNoNull);
    unsigned  const dtype    = scanner.eatToken(EMType);
    OptionalU const stype    = scanner.tryEatToken(EMType);
    scanner.eatToken(EMNone);
    // parse done

    InstSegCvt inst = bw.addInst<InstSegCvt>(opCode);
    inst.sourceType() = stype.isInitialized() ? Brig::BrigTypeX(stype.value()) : Brig::BRIG_TYPE_NONE;
    inst.segment() = segment.isInitialized()  ? Brig::BrigSegment(segment.value()) : Brig::BRIG_SEGMENT_FLAT;
    inst.modifier().isNoNull() = isNoNull.isInitialized();
    inst.type() = dtype;
    return inst;
}

typedef Inst (*OpcodeParser)(Scanner&, Brigantine &, int*);
OpcodeParser getOpcodeParser(Brig::BrigOpcode16_t opcode); // generated
int vecOpndIndex(Brig::BrigOpcode16_t arg); // generated;

Inst parseMnemo(Scanner& scanner, Brigantine& bw, int* outVector) {
    Inst res;
    OpcodeParser const parser = getOpcodeParser(scanner.peek().brigId());
    if (!parser) {
          scanner.syntaxError("unknown instruction");
    }
    return parser(scanner,bw, outVector);
}

Inst parseMnemo(const char* str, Brigantine& bw) {
    std::istringstream instr(str);
    Scanner scanner(instr);
    return parseMnemo(scanner,bw, NULL);
}

// Parser

/*
struct ParseGuard {
    const char* m_fn;
    ParseGuard(const char* fn) : m_fn(fn) {
        std::cout << "<" << fn << "> ";
    }
    ~ParseGuard() { std::cout << "</" << m_fn << "> "; }
};

#define PDBG ParseGuard pdbg__(__FUNCTION__);
*/
#define PDBG

Parser::Parser(Scanner& scanner, BrigContainer& container)
    : m_scanner(scanner)
    , m_bw(container)
    , m_gcnEnabled(false)
{
}

void Parser::parseSource(bool saveSource)
{
    PDBG;

    do {
        parseProgram();
    } while (peek().kind()!=EEndOfSource);

    if (saveSource) {
        std::unique_ptr<BrigSectionImpl> sec(new BrigSectionRaw(SRef("source")));
        SRef const t = m_scanner.getPlainText();
        sec->insertData(sec->secHeader()->headerByteCount, t.begin, t.end);
        m_bw.container().addSection(std::move(sec));
    }
}

void Parser::parseProgram()
{
    PDBG;
    m_bw.startProgram();

    m_gcnEnabled = false;

    while (peek().kind()!=EEndOfSource) {
        parseTopLevelStatement();
    }
    m_bw.endProgram();
}


void Parser::parseModule()
{
    PDBG;

    eatToken(EKWModule);
    eatToken(EIDStatic);

    SourceInfo const srcInfo = sourceInfo(token());
    SRef const name = token().text();

    eatToken(EColon);
    uint64_t const major = m_scanner.readIntLiteral();
    eatToken(EColon);
    uint64_t const minor = m_scanner.readIntLiteral();
    eatToken(EColon);
    unsigned const profile = eatToken(ETargetProfile);
    eatToken(EColon);
    unsigned const machineModel = eatToken(ETargetMachine);
    eatToken(EColon);
    unsigned const defaultRound = eatToken(EDefaultRound);
    eatToken(ESemi);

    if (major > 0xFFFFFFFF) syntaxError("Invalid major version number");
    if (minor > 0xFFFFFFFF) syntaxError("Invalid minor version number");

    m_bw.module(name, (uint32_t)major,(uint32_t)minor,machineModel,profile,defaultRound,&srcInfo);
}

inline static bool isVariableStart(ETokens t)
{
    return (t==EKWConst || t==EKWAlign || t==ESegment || t==EKWAlloc);
}

void Parser::parseSLComment()
{
    eatToken(ESLComment);
    DirectiveComment cmt = m_bw.container().append<DirectiveComment>();
    cmt.name() = token().text();
}

void Parser::parseMLComment()
{
    eatToken(EMLCommentStart);
    while(m_scanner.continueMLComment()) {
        DirectiveComment cmt = m_bw.container().append<DirectiveComment>();
        // \todo1.0 zero copy
        cmt.name() = std::string("//") + std::string(token().text());
    }
}



void Parser::parseTopLevelStatement()
{
    PDBG;

    switch (peek().kind()) {
    case ESLComment:      parseSLComment();break;
    case EMLCommentStart: parseMLComment(); break;
    case EKWModule:       parseModule();break;
    case EKWExtension:    parseExtension();break;
    case EKWPragma:       parsePragma();break;
    case EControl:        parseControl();break;
    case EKWLoc:          parseLocation(); break;
    default:              {
        ModuleStatementPrefix modPfx;
        modPfx.decl = tryEatToken(EKWDecl);
        modPfx.linkage = tryEatToken(ELinkage);
        modPfx.indirect = tryEatToken(EKWIndirect);
        if (modPfx.indirect.isInitialized()) {
            return parseExecutable(EKWFunction, &modPfx);
        }
        ETokens t = peek().kind();
        switch(t) {
        case EKWFunction:
        case EKWKernel:
        case EKWSignature: return parseExecutable(t, &modPfx);
        case EKWFbarrier:  return parseFbarrier(&modPfx);
        default:
            if (isVariableStart(peek().kind())) {
                parseVariable(true, &modPfx);
                eatToken(ESemi);
                return;
            } else {
                syntaxError("Unexpected token in module statement", peek());
            }
        }
                          }
    }
}

/*Optional<uint16_t> Parser::tryParseFBar()
{
    Optional<uint16_t> res;
    if (tryEatToken(EColon)) {
        eatToken(EKWFbarrier);
        eatToken(ELParen);
        res = readNonNegativeInt<Brig::BRIG_TYPE_U16>(m_scanner);
        eatToken(ERParen);
    }
    return res;
}*/

int Parser::parseCodeBlock()
{
    PDBG;
    eatToken(ELCurl);

    m_bw.startBody();

    int numInsts = 0;
    while (!tryEatToken(ERCurl)) {
        numInsts += parseBodyStatement();
    }

    m_bw.endBody();
    return numInsts;
}

int Parser::parseBodyStatement()
{
    PDBG;
    int numInsts = 0;
    switch (peek().kind()) {
    case ESLComment:       parseSLComment();break;
    case EMLCommentStart:  parseMLComment(); break;
    case ELabel:           parseLabel(); break;
    case EKWPragma:        parsePragma(); break;
    case EEmbeddedText:    parseEmbeddedText(); break;
    case EKWSection:       parseDebug(); break;
    case EKWLoc:           parseLocation(); break;
    case EControl:         parseControl();break;
    case EKWFbarrier:      parseFbarrier();break;
    case ELCurl:           numInsts += parseArgScope(); break;
    case EInstruction: {
        Inst i = parseInst();
        ++numInsts;
    } break;
    default:
        if (isVariableStart(peek().kind())) {
            parseVariable();
            eatToken(ESemi);
        } else {
            syntaxError("Unexpected token in body statement", peek());
        }
    }
    return numInsts;
}

int Parser::parseArgScope()
{
    eatToken(ELCurl);
    {
        SourceInfo const srcInfo = sourceInfo(token());
        m_bw.startArgScope(&srcInfo);
    }

    int numInsts = 0;
    while (peek().kind()!=ERCurl) {
        numInsts += parseBodyStatement();
    };

    eatToken(ERCurl);
    {
        SourceInfo const srcInfo = sourceInfo(token());
        m_bw.endArgScope(&srcInfo);
    }
    return numInsts;
}

void Parser::parseLabel()
{
    PDBG;
    eatToken(ELabel);
    SourceInfo const srcInfo = sourceInfo(token());
    SRef const name = token().text();
    eatToken(EColon);

    m_bw.addLabel(name,&srcInfo);
}

Operand Parser::parseOpaqueObject() {
    assert(peek().kind() == EKWImage || peek().kind() == EKWSampler);

    SourceInfo const srcInfo = sourceInfo(peek());
    unsigned const initType = eatToken(peek().kind() == EKWImage? EKWImage : EKWSampler);

    if (peek().kind() == ELBrace) {
        ItemList list;
        parseOpaqueArray(list, initType);
        return m_bw.createConstantOperandList(list, initType, &srcInfo);
    } else if (initType == Brig::BRIG_TYPE_SAMP) {
        return parseSamplerProperties();
    } else {
        return parseImageProperties(initType);
    } 
}

void Parser::parseAndUnfoldOpaqueObject(ItemList& list) {
    assert(peek().kind() == EKWImage || peek().kind() == EKWSampler);

    SourceInfo const srcInfo = sourceInfo(peek());
    unsigned const initType = eatToken(peek().kind() == EKWImage? EKWImage : EKWSampler);

    if (peek().kind() == ELBrace) {
        parseOpaqueArray(list, initType);
    } else if (initType == Brig::BRIG_TYPE_SAMP) {
        list.push_back(parseSamplerProperties());
    } else {
        list.push_back(parseImageProperties(initType));
    } 
}

void Parser::parseOpaqueArray(ItemList& list, unsigned expectedType)
{
    using namespace Brig;

    eatToken(ELBrace);
    eatToken(ERBrace);
    eatToken(ELParen);

    do {
        unsigned const elementType = eatToken(expectedType == BRIG_TYPE_SAMP? EKWSampler : EKWImage);
        if (elementType != expectedType) {
            switch(expectedType)
            {
            case BRIG_TYPE_ROIMG: syntaxError("roimg constant expected");  break;
            case BRIG_TYPE_RWIMG: syntaxError("rwimg constant expected"); break;
            case BRIG_TYPE_WOIMG: syntaxError("woimg constant expected"); break;
            case BRIG_TYPE_SAMP:  syntaxError("samp constant expected");          break;
            default:
                assert(false);
                break;
            }
        }
        Operand element = (elementType == BRIG_TYPE_SAMP) ?
                          parseSamplerProperties() : 
                          parseImageProperties(elementType);
        list.push_back(element);
    } while (tryEatToken(EComma));

    eatToken(ERParen);
}

Operand Parser::parseImageProperties(unsigned type)
{
    SourceInfo const srcInfo = sourceInfo(token());
    OperandConstantImage props = m_bw.append<OperandConstantImage>(&srcInfo);
    props.type() = type;

    eatToken(ELParen);

    do {
        ETokens const t = scan().kind();
        SourceInfo const srcInfo = sourceInfo(token());
        eatToken(EEqual);
        switch(t) {
        case EKWImageWidth:
            if (0 != props.width()) {
                syntaxError("width already set");
            }
            props.width() = m_scanner.readIntLiteral();
            if (props.width() == 0) syntaxError("width must be positive");
            break;
        case EKWImageHeight:
            if (0 != props.height()) {
                syntaxError("height already set");
            }
            props.height() = m_scanner.readIntLiteral();
            if (props.height() == 0) syntaxError("height must be positive");
            break;
        case EKWImageDepth:
            if (0 != props.depth()) {
                syntaxError("depth already set");
            }
            props.depth() = m_scanner.readIntLiteral();
            if (props.depth() == 0) syntaxError("depth must be positive");
            break;
        case EKWImageArray:
            if (0 != props.array()) {
                syntaxError("array already set");
            }
            props.array() = m_scanner.readIntLiteral();
            if (props.array() == 0) syntaxError("array must be positive");
            break;
        case EKWImageChannelType:
            if (props.channelType() != Brig::BRIG_CHANNEL_TYPE_UNKNOWN) {
                syntaxError("Channel type already set");
            }
            props.channelType() = eatToken(EImageFormat);
            break;
        case EKWImageChannelOrder:
            if (props.channelOrder() != Brig::BRIG_CHANNEL_ORDER_UNKNOWN) {
                syntaxError("Channel order already set");
            }
            props.channelOrder() = eatToken(EImageOrder);
            break;
        case EKWImageGeometry:
            if (props.geometry() != Brig::BRIG_GEOMETRY_UNKNOWN) {
                syntaxError("Geometry already set");
            }
            props.geometry() = eatToken(EImageGeometry);
            break;
        default:
            syntaxError("Invalid image property name",&srcInfo);
        }
    } while (tryEatToken(EComma));
    eatToken(ERParen);

    if (props.geometry()     == Brig::BRIG_GEOMETRY_UNKNOWN)      syntaxError("Missing image geometry",      &srcInfo);
    if (props.channelOrder() == Brig::BRIG_CHANNEL_ORDER_UNKNOWN) syntaxError("Missing image channel order", &srcInfo);
    if (props.channelType()  == Brig::BRIG_CHANNEL_TYPE_UNKNOWN)  syntaxError("Missing image channel type",  &srcInfo);
    if (props.width()        == 0)                                syntaxError("Missing image width",         &srcInfo);

    unsigned geom = props.geometry();

    if (geom == Brig::BRIG_GEOMETRY_2D      ||
        geom == Brig::BRIG_GEOMETRY_3D      ||
        geom == Brig::BRIG_GEOMETRY_2DA     ||
        geom == Brig::BRIG_GEOMETRY_2DDEPTH ||
        geom == Brig::BRIG_GEOMETRY_2DADEPTH) {
        if (props.height() == 0) syntaxError("Missing image height", &srcInfo);
    } else {
        if (props.height() > 0) syntaxError("Image height cannot be specified for this image geometry", &srcInfo);
    }

    if (geom == Brig::BRIG_GEOMETRY_3D) {
        if (props.depth() == 0) syntaxError("Missing image depth", &srcInfo);
    } else {
        if (props.depth() > 0) syntaxError("Image depth cannot be specified for this image geometry", &srcInfo);
    }

    if (geom == Brig::BRIG_GEOMETRY_1DA     ||
        geom == Brig::BRIG_GEOMETRY_2DA     ||
        geom == Brig::BRIG_GEOMETRY_2DADEPTH) {
        if (props.array() == 0) syntaxError("Missing image array", &srcInfo);
    } else {
        if (props.array() > 0) syntaxError("Image array cannot be specified for this image geometry", &srcInfo);
    }

    return props;
}

Operand Parser::parseSamplerProperties()
{
    SourceInfo const srcInfo = sourceInfo(token());
    OperandConstantSampler props = m_bw.append<OperandConstantSampler>(&srcInfo);
    props.type() = Brig::BRIG_TYPE_SAMP;

    eatToken(ELParen);

    unsigned propMask = 0;
    do {
        ETokens const t = scan().kind();
        SourceInfo const srcInfo = sourceInfo(token());
        eatToken(EEqual);
        if (t >= ESamplerFirstProp && t <= ESamplerLastProp) {
            unsigned bit = (1 << (t - ESamplerFirstProp));
            if (propMask & bit) {
                syntaxError("Duplicate sampler property");
            }
            propMask |= bit;
        }
        switch(t) {
        case EKWSamplerAddressing:
            props.addressing() = eatToken(ESamplerAddressingMode);
            break;
        case EKWSamplerCoord:
            props.coord() = eatToken(ESamplerCoord);
            break;
        case EKWSamplerFilter:
            props.filter() = eatToken(ESamplerFilter);
            break;
        default:
            syntaxError("Invalid sampler object property name",&srcInfo);
        }
    } while (tryEatToken(EComma));
    eatToken(ERParen);
    // TBD simplify
    for(unsigned prop = ESamplerFirstProp; prop <= ESamplerLastProp; ++prop) {
        if (propMask & (1 << (prop - ESamplerFirstProp))) {
            continue;
        }
        switch(prop) {
        case EKWSamplerAddressing:
            syntaxError("addressing value missing");
            break;
        case EKWSamplerCoord:
            syntaxError("coord value missing");
            break;
        case EKWSamplerFilter:
            syntaxError("filter value missing");
            break;
        }
    }
    return props;
}

void Parser::parseExecutable(ETokens kw, const ModuleStatementPrefix* modPfx)
{
    PDBG;
    eatToken(kw);
    eatToken(EIDStatic);

    SourceInfo const srcInfo = sourceInfo(token());
    SRef const name = token().text();

    DirectiveExecutable exe;
    switch(kw) {
    case EKWFunction:
        if (modPfx->indirect.isInitialized()) {
            exe = m_bw.declIndirectFunc(name,&srcInfo);
        } else {
            exe = m_bw.declFunc(name,&srcInfo);
        }
        break;
    case EKWKernel:
        if (modPfx->indirect.isInitialized()) syntaxError("indirect kernels are not supported");
        exe = m_bw.declKernel(name, &srcInfo);
        break;
    case EKWSignature:
        if (modPfx->indirect.isInitialized()) syntaxError("indirect signatures are not supported");
        exe = m_bw.declSignature(name, &srcInfo);
        break;
    default:
        assert(0);
    }

    if (modPfx->linkage.isInitialized()) {
        exe.linkage() = modPfx->linkage.value();
    } else if (kw == EKWFunction || kw == EKWKernel) {
        exe.linkage() = Brig::BRIG_LINKAGE_MODULE;
    }

    if (kw == EKWFunction || kw == EKWSignature) {
        eatToken(ELParen);

        if (!tryEatToken(ERParen)) {
            Directive first = parseVariable(kw != EKWSignature);
            if (first) {
                m_bw.addOutputParameter(first);
                while(tryEatToken(EComma)) {
                    m_bw.addOutputParameter(parseVariable(kw != EKWSignature));
                }
            }
            eatToken(ERParen);
        }
    }

    eatToken(ELParen);

    if (!tryEatToken(ERParen)) {
        Directive first = parseVariable(kw != EKWSignature);
        if (first) {
            m_bw.addInputParameter(first);
            while(tryEatToken(EComma)) {
                m_bw.addInputParameter(parseVariable(kw != EKWSignature));
            }
        }
        eatToken(ERParen);
    }

    if (!exe.firstInArg()) {
        exe.firstInArg() = m_bw.container().code().end();
    }

    if (kw == EKWSignature) {
        if (modPfx->decl.isInitialized()) syntaxError("signatures cannot have declarations");
        exe.modifier().isDefinition() = true;
    } else if (modPfx->decl.isInitialized()) {
        exe.firstCodeBlockEntry() = m_bw.container().code().end();
        exe.modifier().isDefinition() = false;
    } else {
        exe.modifier().isDefinition() = true;
        parseCodeBlock();
    }

    eatToken(ESemi);
}

Operand Parser::parseAggregateOperand()
{
    eatToken(ELCurl);
    SourceInfo const srcInfo = sourceInfo(token());
    ItemList list;
    do {
        // TBD length excess
        switch(peek().kind()) {
        case EKWAlign: {
            eatToken(EKWAlign);
            SourceInfo const srcInfo = sourceInfo(token());
            unsigned const align = parseAlign(m_scanner);
            OperandAlign oa = m_bw.append<OperandAlign>();
            oa.annotate(srcInfo);
            oa.align() = align;
            list.push_back(oa);
            break;
        }
        case EKWImage:
        case EKWSampler:
            parseAndUnfoldOpaqueObject(list);
            break;
        default: {
            SourceInfo const srcInfo = sourceInfo(peek());
            ArbitraryData values;
            unsigned literalType = parseImmediate(&values, Brig::BRIG_TYPE_NONE, 0, TYPED_IMM); //F1.0 how to avoid passing BRIG_TYPE_NONE?
            list.push_back(
               m_bw.createOperandConstantBytes(values.toSRef(),
                                               arrayElementType(literalType), isArrayType(literalType),
                                               &srcInfo));
            break;
        }
        }
    } while(tryEatToken(EComma));
    eatToken(ERCurl);
    OperandConstantOperandList aggregate = m_bw.createConstantOperandList(list, Brig::BRIG_TYPE_NONE, &srcInfo);
    if (getAggregateNumBytes(aggregate) == 0) {
        syntaxError("An aggregate constant cannot consist of only alignment request elements");
    }
    return aggregate;
}

DirectiveVariable Parser::parseVariable(bool nameRequired /*=true*/, const ModuleStatementPrefix* modPfx)
{
    OptionalU allocKind, align, hasConst;
    if (tryEatToken(EKWAlloc)) {
        eatToken(ELParen);
        allocKind = eatToken(EAllocKind);
        eatToken(ERParen);
    }
    if (tryEatToken(EKWAlign)) {
        align = parseAlign(m_scanner);
    }
    hasConst = tryEatToken(EKWConst);

    unsigned const segment = eatToken(ESegment, "variable segment");

    // set position for signature args which have no name
    SourceInfo srcInfo = sourceInfo(token());

    unsigned const expectedType = eatToken(EMType, "variable type");

    SRef name;
    if (nameRequired) {
        eatToken(modPfx ? EIDStatic : EIDLocal);
        name = token().text();
    } else {
        OptionalU arg = tryEatToken(EIDLocal);
        name = arg.isInitialized()? token().text() : SRef("");
    }

    // set position for args which have a name
    if (!name.empty()) {
        srcInfo = sourceInfo(token());
    }

    DirectiveVariable sym;
    switch(expectedType) {
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_WOIMG:
        sym = m_bw.addImage(name,segment,&srcInfo);
        sym.type() = expectedType;
        break;
    case Brig::BRIG_TYPE_SAMP:
        sym = m_bw.addSampler(name,segment,&srcInfo);
        break;
    default:
        sym = m_bw.addVariable(name,segment,expectedType,&srcInfo);
    }

    if (align.isInitialized())
        sym.align() = align.value();

    if (hasConst.isInitialized())
        sym.modifier().isConst() = true;

    if (modPfx && modPfx->linkage.isInitialized())
        sym.linkage() = modPfx->linkage.value();

    if (allocKind.isInitialized()) {
        if (segment == Brig::BRIG_SEGMENT_READONLY) 
            syntaxError("Allocation cannot be specified because readonly "
                        "segment variables have implicit agent allocation");
        sym.allocation() = allocKind.value();
    }

    const bool isArray = tryEatToken(ELBrace);
    bool isFlexArray = false;
    if (isArray) {
        sym.type() = elementType2arrayType(sym.type());
        isFlexArray = peek().kind() == ERBrace;
        if (!isFlexArray) {
            sym.dim() = m_scanner.readIntLiteral();
            if (sym.dim() == 0) syntaxError("Arrays must have dim > 0");
        }
        eatToken(ERBrace);
    }

    if (tryEatToken(EEqual)) {
        
        uint64_t dim;

        if (peek().kind() == EKWImage || peek().kind() == EKWSampler) {
            sym.init() = parseOpaqueObject();
            OperandConstantOperandList list = sym.init();
            dim = list ? list.elements().size() : 1;
        } else if (peek().kind() == ELCurl) { // this is an aggregate
            sym.init() = parseAggregateOperand();
            assert(getAggregateNumBytes(sym.init()) > 0);
            dim = getAggregateNumBytes(sym.init()) / getBrigTypeNumBytes(sym.elementType());
        } else {
            SourceInfo const srcInfo = sourceInfo(peek());
            ArbitraryData values;

            unsigned literalType = parseImmediate(&values, isArray? elementType2arrayType(expectedType) : expectedType, 0);

            if (isBitType(expectedType) && !isArrayType(literalType) && 
                getBrigTypeNumBytes(expectedType) == getBrigTypeNumBytes(literalType)) {
                literalType = bitType2uType(expectedType);
            }

            sym.init() = m_bw.createOperandConstantBytes(values.toSRef(), 
                                                            arrayElementType(literalType), 
                                                            isArrayType(literalType), 
                                                            &srcInfo);
            dim = values.numBytes() / getBrigTypeNumBytes(expectedType);
        }

        if (isFlexArray) sym.dim() = dim;
    }

    sym.modifier().isDefinition() = !(modPfx && modPfx->decl.isInitialized());
    return sym;
}

void Parser::parseFbarrier(const ModuleStatementPrefix* modPfx) {
    PDBG;
    eatToken(EKWFbarrier);

    eatToken(modPfx ? EIDStatic : EIDLocal);
    SourceInfo const srcInfo = sourceInfo(token());
    SRef const name = token().text();

    DirectiveFbarrier fbar = m_bw.addFbarrier(name,&srcInfo);

    if (modPfx && modPfx->linkage.isInitialized()) {
        fbar.linkage() = modPfx->linkage.value();
    } else if (modPfx) {
        fbar.linkage() = Brig::BRIG_LINKAGE_MODULE;
    } else {
        fbar.linkage() = Brig::BRIG_LINKAGE_FUNCTION;
    }

    fbar.modifier().isDefinition() = !(modPfx && modPfx->decl.isInitialized());

    eatToken(ESemi);
}

static std::string parseStringLiteral(Scanner&);

// Instruction parsing

Inst Parser::parseInst()
{
    PDBG;
    Inst res;
    SourceInfo const srcInfo = sourceInfo(peek());
    int vx = -1;
    res = parseMnemo(m_scanner, m_bw, &vx);

    const char* errMsg = preValidateInst(res, m_bw.getMachineModel(), m_bw.getProfile());
    if (errMsg) syntaxError(errMsg);

    res.annotate(srcInfo);

    if (res.kind()!=Brig::BRIG_KIND_NONE) {
        OperandParser const parser = getOperandParser(res.opcode());
        assert(parser);
        m_bw.setOperands(res, (this->*parser)(res));
        eatToken(ESemi);

        int idx = vecOpndIndex(res.opcode());
        if (idx >= 0) {
          checkVxIsValid(vx, res.operand(idx));
        }
    } else {
        eatToken(ESemi);
    }

    if (!m_gcnEnabled && isGcnInst(res.opcode())) {
        syntaxError("Gcn extension isn't enabled");
    }
    return res;
}

void Parser::checkVxIsValid(int vx, Operand o)
{
  // check whether modifier v2/v3/v4 corresponds to 1st operand
  const SourceInfo* const srcInfo = o.srcInfo();

  assert(vx > 0);
  if (vx == 1) {
    if ( isa<OperandOperandList>(o)) {
      syntaxError("Unexpected vector operand (or missing _vX suffix)",srcInfo);
    }
  } else {
    if (!o) {
      std::stringstream ss;
      ss << "Insufficient number of operands";
      syntaxError(ss.str(),srcInfo);
    } else if (!isa<OperandOperandList>(o)) {
      std::stringstream ss;
      ss << "Expected vector operand (to match _v" << vx << " suffix)";
      syntaxError(ss.str(),srcInfo);
    } else if (OperandOperandList(o).elements().size() != vx) {
      std::stringstream ss;
      ss << "Number of vector elements does not match _v" << vx << " suffix";
      syntaxError(ss.str(),srcInfo);
    }
  }
}

// Operand parsing

ItemList Parser::parseOperands(Inst inst)
{
    PDBG;
    ItemList list;

    if (peek().kind()!=ESemi) {
        int i=0;
        do {
            list.push_back(parseOperandGeneric(inst,i++));
        } while(tryEatToken(EComma));
    }
    return list;
}

Operand Parser::parseActualParamList()
{
    PDBG;
    eatToken(ELParen);
    SourceInfo const srcInfo = sourceInfo(token());

    ItemList list;

    while(!tryEatToken(ERParen)) {
        eatToken(EIDLocal);
        SRef const argName = token().text();
        SourceInfo const srcInfo = sourceInfo(token());

        DirectiveVariable arg = m_bw.findInScopes<DirectiveVariable>(argName);
        if (!arg) {
            syntaxError("Symbol not found", &srcInfo);
        }
        list.push_back(arg);

        tryEatToken(EComma);
    }
    return m_bw.createCodeList(list, &srcInfo);
}

ItemList Parser::parseCallOperands(Inst inst)
{
    PDBG;
    ItemList list;

    Operand outArgs;
    Operand inArgs;

    unsigned type = inst.type();
    Operand target = parseOperandGeneric(isUnsignedType(type) ? type : Brig::BRIG_TYPE_U64);

    if (peek().kind()==ELParen) {
        outArgs = parseActualParamList();
        if (peek().kind()==ELParen) {
           inArgs = parseActualParamList();
        } else {
            syntaxError("missing call argument list",peek());
        }
    } else {
        syntaxError("missing call argument list",peek());
    }

    list.push_back(outArgs);
    list.push_back(target);
    list.push_back(inArgs);

    if (inst.opcode() != Brig::BRIG_OPCODE_CALL && peek().kind()!=ESemi) {
        if (tryEatToken(ELBrace)) {
            SourceInfo const srcInfo = sourceInfo(token());
            ItemList targets;
            do {
                SRef const fnName = scan().text();
                DirectiveExecutable func = m_bw.findInScopes<DirectiveFunction>(fnName);
                if (!func) {
                    func = m_bw.findInScopes<DirectiveIndirectFunction>(fnName);
                }
                if (!func) {
                    syntaxError("function not found");
                }
                targets.push_back(func);
            } while (tryEatToken(EComma));
            eatToken(ERBrace);
            list.push_back(m_bw.createCodeList(targets, &srcInfo));
        } else {
            list.push_back(parseSigRef());
        }
    }
    return list;
}

ItemList Parser::parseSbrOperands(Inst inst)
{
  ItemList operands;
  operands.push_back(parseOperandGeneric(inst.type()));

  std::vector<SRef> targets;
  eatToken(ELBrace);
  SourceInfo const srcInfo = sourceInfo(token());
  do {
    eatToken(ELabel);
    targets.push_back(token().text());
  } while(tryEatToken(EComma));
  eatToken(ERBrace);

  operands.push_back(m_bw.createLabelList(targets, &srcInfo));
  return operands;
}

Operand Parser::parseOperandGeneric(Inst inst, unsigned opndIdx)
{
    return parseOperandGeneric(getOperandType(inst, opndIdx, m_bw.getMachineModel(), m_bw.getProfile()));
}

//F1.0 Make this function really generic - parse all types of operands. Let clients (or validator) decide which operands are allowed
Operand Parser::parseOperandGeneric(unsigned requiredType)
{
    PDBG;
    Operand res;

    assert(!isArrayType(requiredType));

    switch (peek().kind()) {
    case ELBrace:
        res = parseOperandInBraces(requiredType);
        break;

    case ELParen: // see mov instruction
        res = parseOperandVector(requiredType);
        break;

    case EPlus:
    case EMinus:
    case EIntLiteral:
    case EF16Literal:
    case EF32Literal:
    case EF64Literal:
    case ETypedLiteral:
        res = parseConstantGeneric(requiredType);
        break;

    case EWaveSizeMacro:
        {
            scan();
            SourceInfo const srcInfo = sourceInfo(token());
            res = m_bw.createWaveSz(&srcInfo);
        }
        break;

    case EIDLocal:
    case EIDStatic:
        res = parseOperandRef();
        break;

    case ELabel:
        res = parseLabelOperand();
        break;

    case ERegister:
        res = parseOperandReg();
        break;

    default:
        syntaxError("invalid operand", peek());
    }
    return res;
}

OperandCodeRef Parser::parseOperandRef()
{
    PDBG;
    scan();
    assert(token().kind()==EIDLocal || token().kind()==EIDStatic);
    SourceInfo const srcInfo = sourceInfo(token());
    SRef const name = token().text();
    return m_bw.createDirectiveRef(name,&srcInfo);
}

OperandRegister Parser::parseOperandReg()
{
    PDBG;
    eatToken(ERegister);
    SourceInfo const srcInfo = sourceInfo(token());
    SRef const name = token().text();

    return m_bw.createOperandReg(name,&srcInfo);
}

Operand Parser::parseOperandVector(unsigned requiredType)
{
    eatToken(ELParen);
    SourceInfo const srcInfo = sourceInfo(token());

    ItemList opnds;
    while (true) {
        Operand o = parseOperandGeneric(requiredType);
        if (!isa<OperandRegister>(o) && !isa<OperandConstantBytes>(o) && !isa<OperandWavesize>(o)) {
            syntaxError("register, wavesize or immediate constant value expected");
        }
        opnds.push_back(o);

        if (!tryEatToken(EComma)) {
            break;
        } else if (opnds.size()==4) {
            syntaxError("vector cannot contain more than 4 elements");
        }
    }
    eatToken(ERParen);

    return m_bw.createOperandList(opnds, &srcInfo);
}

OperandCodeRef Parser::parseFunctionRef()
{
    eatToken(EIDStatic);
    SRef const fnName = token().text();
    SourceInfo const srcInfo = sourceInfo(token());
    return m_bw.createExecutableRef(fnName,&srcInfo);
}

Operand Parser::parseSigRef()
{
    eatToken(EIDStatic);
    SRef const sigName = token().text();
    SourceInfo const srcInfo = sourceInfo(token());
    return m_bw.createSigRef(sigName,&srcInfo);
}

Operand Parser::parseLabelOperand()
{
    eatToken(ELabel);
    SRef const labelName = token().text();
    SourceInfo const srcInfo = sourceInfo(token());

    return m_bw.createLabelRef(labelName,&srcInfo);
}

template<typename R> void parseFloatImmediate(
    ArbitraryData *data,
    unsigned requiredType,
    size_t pos,
    Scanner& scanner,
    R (Scanner::*scanFunc)(),
    bool hasMinus,
    const char* litKind)
{
    unsigned brigType  = CType2Brig<R, 1>::value;

    if (isArrayType(requiredType) ||
        requiredType == Brig::BRIG_TYPE_INVALID ||
        requiredType == Brig::BRIG_TYPE_NONE) { // Malformed instruction; type cannot be identified
        requiredType = brigType; // Use actual literal type and let validator handle errors
    }
    assert(!isArrayType(requiredType));

    R value = (scanner.*scanFunc)(); // NB: error reporting must follow literal scanning to show correct position in scr code

    if (requiredType != brigType && requiredType != getBitType(getBrigTypeNumBits(brigType))) {
        scanner.syntaxError(std::string(litKind) + " literal cannot initialize " + typeX2str(requiredType)); //F1.0 unify err reporting
    }
    data->write(hasMinus ? value.neg().rawBits() : value.rawBits(), pos);
    return;
}

unsigned Parser::parseImmediate(ArbitraryData *data, unsigned requiredType, size_t pos, unsigned expectedImmKind /*=ANY_IMM*/)
{
    ETokens tokenAhead = peek().kind();

    SourceInfo signSI;
    bool hasMinus = false;
    if (tokenAhead == EPlus || tokenAhead == EMinus) {
        hasMinus = tokenAhead == EMinus;
        eatToken(tokenAhead);
        signSI = sourceInfo(token());
        tokenAhead = peek().kind();
    }

    if (expectedImmKind == TYPED_IMM && tokenAhead != ETypedLiteral) {
        eatToken(tokenAhead);
        syntaxError("Expected a typed constant");
    } else if (expectedImmKind == UNTYPED_IMM && tokenAhead == ETypedLiteral) {
        eatToken(tokenAhead);
        syntaxError("Typed constants are not allowed");
    }

    switch(tokenAhead) {
    case ETypedLiteral:
        {
            unsigned const typeFromToken = eatToken(ETypedLiteral);

            if (tryEatToken(ELBrace)) {  // This is an array

                if (signSI.column >= 0) {
                    syntaxError("Sign is not allowed before an array", &signSI);
                }
                eatToken(ERBrace);
                eatToken(ELParen);
                do {
                    unsigned elementType = parseImmediate(data, typeFromToken, data->numBytes());
                    validateTypedImmConversion(typeFromToken, elementType);
                } while(tryEatToken(EComma));
                eatToken(ERParen);

                return elementType2arrayType(typeFromToken);
            
            } else { // This is a scalar

                if (signSI.column >= 0) {
                    syntaxError("Sign is not allowed before a typed literal", &signSI); //F1.0 unify err reporting
                }

                if (isArrayType(requiredType) ||
                    requiredType == Brig::BRIG_TYPE_INVALID ||
                    requiredType == Brig::BRIG_TYPE_NONE) { // Malformed instruction; type cannot be identified
                    requiredType = typeFromToken; // Use actual literal type and let validator handle errors
                }

                validateTypedImmConversion(requiredType, typeFromToken);

                eatToken(ELParen);
                unsigned elementType = typeFromToken & Brig::BRIG_TYPE_BASE_MASK;
                unsigned elementBytes = getBrigTypeNumBytes(elementType);
                unsigned numPackElem = getBrigTypeNumBits(typeFromToken) / getBrigTypeNumBits(elementType);
                assert(numPackElem != 0);

                for(unsigned i = 0; i < numPackElem; ++i) {
                    if (i) {
                        eatToken(EComma);
                    }
                    parseImmediate(data, elementType, pos + (numPackElem - i - 1) * elementBytes, UNTYPED_IMM);
                }
                eatToken(ERParen);

                return typeFromToken;
            }
        }
    case EF16Literal:
        parseFloatImmediate(data, requiredType, pos, m_scanner, &Scanner::readF16Literal, hasMinus, "f16");
        return Brig::BRIG_TYPE_F16;
    case EF32Literal:
        parseFloatImmediate(data, requiredType, pos, m_scanner, &Scanner::readF32Literal, hasMinus, "f32");
        return Brig::BRIG_TYPE_F32;
    case EF64Literal:
        parseFloatImmediate(data, requiredType, pos, m_scanner, &Scanner::readF64Literal, hasMinus, "f64");
        return Brig::BRIG_TYPE_F64;
    case EIntLiteral:
        {
            uint64_t value = m_scanner.readIntLiteral(); // NB: error reporting must follow literal scanning to show correct position in scr code

            if (isArrayType(requiredType) ||
                requiredType == Brig::BRIG_TYPE_INVALID ||
                requiredType == Brig::BRIG_TYPE_NONE) { // Malformed instruction; type cannot be identified
                requiredType = Brig::BRIG_TYPE_U64; // Use actual literal type and let validator handle errors
            } else if (isPackedType(requiredType) || 
                       isFloatType(requiredType)  || 
                       getBrigTypeNumBits(requiredType) > 64) {
                syntaxError(std::string("Integer literal cannot initialize ") + typeX2str(requiredType)); //F1.0 unify err reporting
            }

            if (hasMinus) { value = (uint64_t) -(int64_t)value; }

            switch(requiredType) {
            case Brig::BRIG_TYPE_B1:
                value = value ? 1 : 0;
                break;
            case Brig::BRIG_TYPE_SIG32:
            case Brig::BRIG_TYPE_SIG64:
                if (value != 0) {
                    syntaxError("Signal handle can only be initialized with 0");
                }
                break;
            default:
                break;
            }
            data->write(&value, getBrigTypeNumBytes(requiredType), pos);

            return isSignedType(requiredType)? requiredType : 
                   isBitType(requiredType)?    bitType2uType(requiredType) :
                                               getUnsignedType(getBrigTypeNumBits(requiredType));
        }
    case EKWImage:
    case EKWSampler:    // This code is only needed to improve diagnostic
        {   
            assert(!isImageType(requiredType));
            assert(!isSamplerType(requiredType));

            SourceInfo const srcInfo = sourceInfo(peek());
            unsigned const typeFromToken = eatToken(peek().kind() == EKWImage? EKWImage : EKWSampler);
            validateTypedImmConversion(requiredType, typeFromToken);
            assert(false);
            return Brig::BRIG_TYPE_NONE;
        }
    
    default:
        eatToken(tokenAhead); // set error position
        if (tokenAhead == ELCurl && requiredType != Brig::BRIG_TYPE_NONE) {
            syntaxError(std::string("Aggregate constant cannot be converted to ") + type2str(requiredType));
        } else {
            syntaxError("Constant value expected");
        }
        return Brig::BRIG_TYPE_NONE;
    }
}

//F1.0 Replace all conversion checks with this function
//F1.0 Add version for untyped constants (which allow truncation)
void Parser::validateTypedImmConversion(unsigned requiredType, unsigned actualType)
{
    assert(!isBitType(actualType));

    if (requiredType == actualType) return;
    if (requiredType == Brig::BRIG_TYPE_NONE) return; // No specific type expected

    //F1.0 convert required type from 'b' to 'u' to improve diagnostics

    unsigned const requiredTypeSize = isArrayType(requiredType)? 0 : getBrigTypeNumBits(requiredType);
    unsigned const actualTypeSize   = isArrayType(actualType)?   0 : getBrigTypeNumBits(actualType);

    if (isPackedType(actualType)) { 
        if (isPackedType(requiredType) && actualType == requiredType) return;
        if (isBitType(requiredType) && requiredTypeSize == actualTypeSize) return;
    } else if (isFloatType(actualType)) {
        if (isFloatType(requiredType) && actualType == requiredType) return;
        if (isBitType(requiredType) && requiredTypeSize == actualTypeSize) return;
    } else if (isSignedType(actualType) || isUnsignedType(actualType)) {
        if ((isSignedType(requiredType) || isUnsignedType(requiredType)) && actualType == requiredType) return;
        if (isBitType(requiredType) && requiredTypeSize == actualTypeSize) return;
    }

    syntaxError(std::string(type2str(actualType)) + " constant cannot be converted to " + type2str(requiredType));
}

Operand Parser::parseConstantGeneric(unsigned requiredType)
{
    PDBG;
    assert(!isArrayType(requiredType));
    SourceInfo const srcInfo = sourceInfo(peek());
    ArbitraryData data;
    unsigned literalType = parseImmediate(&data, requiredType, 0);

    if (isArrayType(literalType)) {
        syntaxError("array typed constants are not allowed as operands");
    }

    if (isBitType(requiredType) && !isArrayType(literalType) && 
        getBrigTypeNumBytes(requiredType) == getBrigTypeNumBytes(literalType)) {
        literalType = bitType2uType(requiredType);
    }

    return m_bw.createImmed(data.toSRef(), literalType, &srcInfo);
}

void Parser::parseAddress(SRef& reg, int64_t& offset)
{
    if (tryEatToken(ERegister)) {
        reg = token().text();
        ETokens const tokenAhead = peek().kind();
        if (tokenAhead==EPlus || tokenAhead==EMinus) {
            scan();
            uint64_t value = m_scanner.readIntLiteral();
            if (tokenAhead==EMinus) {
                offset = -(int64_t)value;
            } else {
                offset = (int64_t)value;
            }
        } else {
            offset = 0;
        }
    } else if (peek().kind() == EPlus || peek().kind() == EMinus) {
        ETokens const tokenAhead = scan().kind();
        reg = SRef();
        uint64_t value = m_scanner.readIntLiteral();
        if (tokenAhead==EMinus) {
            offset = -(int64_t)value;
        } else {
            offset = (int64_t)value;
        }
    } else if (peek().kind() == EIntLiteral) {
        reg = SRef();
        offset = m_scanner.readIntLiteral();
    } else {
        syntaxError("Register or offset expected", peek());
    }
}

Operand Parser::parseOperandInBraces(unsigned requiredType)
{
    PDBG;
    eatToken(ELBrace);
    SourceInfo const srcInfo = sourceInfo(token());

    ETokens const tokenAhead = peek().kind();

    if (tokenAhead==ERBrace) syntaxError("Invalid operand", peek()); // This is to avoid incorrect diagnostics

    if (tokenAhead==ELabel) {
        Operand res = parseLabelOperand();
        eatToken(ERBrace);
        return res;
    }

    SRef      name,reg;
    int64_t   offset = 0;
    if (tokenAhead==EIDStatic || tokenAhead==EIDLocal) {
        name = scan().text();
        eatToken(ERBrace);
        if (tryEatToken(ELBrace)) {
            parseAddress(reg, offset);
            eatToken(ERBrace);
        }
    } else {
        parseAddress(reg, offset);
        eatToken(ERBrace);
    }
    return m_bw.createRef(name, reg, offset, requiredType == Brig::BRIG_TYPE_U32, &srcInfo);
}



// Stubs


void Parser::parsePragma()
{
    PDBG;
    eatToken(EKWPragma);
    SourceInfo const srcInfo = sourceInfo(token());
    ItemList list;

    //F1.0 Try merging with parseOperandGeneric

    int i=0;
    do {
        Operand opr;
        switch (peek().kind()) 
        {
        case EQuot:    
            opr = m_bw.createOperandString(parseStringLiteral(m_scanner)); 
            break;
        case EKWImage:
        case EKWSampler:
            opr = parseOpaqueObject();
            break;
        case EIDLocal:
        case EIDStatic:
            opr = parseOperandRef();
            break;
        case ELabel:
            opr = parseLabelOperand();
            break;
        case ERegister:
            opr = parseOperandReg();
            break;
        case ELCurl: // aggregate
            opr = parseAggregateOperand();
            break;
        case EWaveSizeMacro: {
                scan();
                SourceInfo const oprSrcInfo = sourceInfo(token());
                opr = m_bw.createWaveSz(&oprSrcInfo);
            }
            break;
        default: {
                ArbitraryData values;
                SourceInfo const oprSrcInfo = sourceInfo(peek());
                unsigned literalType = parseImmediate(&values, Brig::BRIG_TYPE_NONE, 0); //F1.0 how to avoid passing BRIG_TYPE_NONE?
                opr = m_bw.createOperandConstantBytes(values.toSRef(),
                                                      arrayElementType(literalType), isArrayType(literalType),
                                                      &oprSrcInfo);
            }
            break;
        }
        list.push_back(opr);
    } while(tryEatToken(EComma));

    eatToken(ESemi);
    DirectivePragma pgm = m_bw.append<DirectivePragma>(&srcInfo);
    pgm.operands() = list;
}

// \todo remove this
void Parser::parseEmbeddedText()
{
    PDBG;
    eatToken(EEmbeddedText);
    SourceInfo const srcInfo = sourceInfo(token());

    SRef text = token().text();
    // HACK: strip delimeters
    text.begin += 2;
    text.end -= 2;
    DirectivePragma pgm = m_bw.append<DirectivePragma>(&srcInfo);
    ItemList list;
    list.push_back(m_bw.createOperandString("<!!>"));
    list.push_back(m_bw.createOperandString(text));
    pgm.operands() = list;
}

void Parser::parseDebug()
{
    PDBG;
    eatToken(EKWSection);
    eatToken(ESemi);
}

void Parser::parseExtension()
{
    PDBG;
    eatToken(EKWExtension);
    SourceInfo const srcInfo = sourceInfo(token());
    std::string const name = parseStringLiteral(m_scanner);
    eatToken(ESemi);

    DirectiveExtension dir = m_bw.append<DirectiveExtension>(&srcInfo);
    dir.name() = name;

    if (name=="amd:gcn") {
        m_gcnEnabled = true;
    }
}

void Parser::parseLocation()
{
    PDBG;
    eatToken(EKWLoc);
    SourceInfo const srcInfo = sourceInfo(token());

    uint64_t const sourceLine = m_scanner.readIntLiteral();
    uint64_t sourceColumn = 1;
    if (peek().kind() == EIntLiteral) {
        sourceColumn = m_scanner.readIntLiteral();
    }
    if (peek().kind() == EQuot) {
      m_srcFileName = parseStringLiteral(m_scanner);
    }
    eatToken(ESemi);

    if (sourceLine   > 0xFFFFFFFF) syntaxError("invalid source line");
    if (sourceColumn > 0xFFFFFFFF) syntaxError("invalid source column");

    DirectiveLoc loc = m_bw.append<DirectiveLoc>(&srcInfo);
    // \todo: add to Brigantine high-level API for adding DirectiveLoc
    loc.filename() = m_srcFileName;
    loc.line()     = (uint32_t)sourceLine;
    loc.column()   = (uint32_t)sourceColumn;
}

void Parser::parseControl()
{
    PDBG;
    unsigned const ctrlId = eatToken(EControl);
    DirectiveControl ctrl = m_bw.container().append<DirectiveControl>(sourceInfo(token()));
    ctrl.control() = ctrlId;

    ItemList values;
    unsigned idx = 0;
    if (peek().kind() != ESemi) do { // arguments are optional

        // dp: added WAVESIZE support + disabled negative int values
        SourceInfo const srcInfo = sourceInfo(peek());

        Operand res;
        unsigned type = getCtlDirOperandType(ctrlId, idx);
        if (type == Brig::BRIG_TYPE_NONE) {
            if (idx == 0) {
                syntaxError("directive has no arguments");
            } else {
                syntaxError("no more arguments expected");
            }
        } else if (tryEatToken(EWaveSizeMacro)) {
            res = m_bw.createWaveSz(&srcInfo);
        } else {
            res = parseConstantGeneric(type);
        }
        values.push_back( res );
        idx++;
    } while (tryEatToken(EComma));
    ctrl.operands() = values;
    eatToken(ESemi);
}

// ----------------------------------------------------------------------------
// Helper code

static std::string parseStringLiteral(Scanner& scanner) {
    std::string ret;
    do {
        scanner.eatToken(EQuot);
        scanner.readSingleStringLiteral(ret);
        scanner.eatToken(EQuot);
    } while(scanner.peek().kind() == EQuot);
    return ret;
}

#include "HSAILParserUtilities_gen.hpp"

} // end namespace
