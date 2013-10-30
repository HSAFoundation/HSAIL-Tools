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
#include "HSAILConvertors.h"
#include <iosfwd>
#include <sstream>

namespace HSAIL_ASM
{

using namespace std;

struct DeclPrefix
{
    Optional<bool>                 hasConst;
    Optional<unsigned>             align;
    Optional<Brig::BrigLinkage8_t> linkage;
};

// Parse helpers


template <Brig::BrigTypeX type>
static typename BrigType<type>::CType readInt(Scanner& s) {
    return s.readIntValue<BrigType<type>,StaticCastConvert>();
}

template <Brig::BrigTypeX type>
static typename BrigType<type>::CType readNonNegativeInt(Scanner& s) {
    return s.readIntValue<BrigType<type>,ConvertIfNonNegativeInt>();
}

template <Brig::BrigTypeX type>
static typename BrigType<type>::CType readPositiveInt(Scanner& s) {
    return s.readIntValue<BrigType<type>,ConvertIfPositiveInt>();
}

template <typename BrigElemType, size_t N>
MySmallArray<typename BrigElemType::CType,N> readPackedLiteralInsideParens(Scanner& scanner)
{
    MySmallArray<typename BrigElemType::CType,N> res;
    for(size_t i=N-1; i > 0; --i) {
        res[i] = scanner.readValue<BrigElemType,ConvertImmediate >();
        scanner.eatToken(EComma);
    }
    res[0] = scanner.readValue<BrigElemType,ConvertImmediate >();
    return res;
}


template <typename DstBrigType, 
          template<typename, typename> class Convertor>
class ReadPackedLiteral
{
    Scanner& m_scanner;

    template <typename T,size_t N>
    typename DstBrigType::CType visitImpl(BrigTypePacked<T,N>*) const {
        return convert<DstBrigType, BrigTypePacked<T,N> ,Convertor>(
            readPackedLiteralInsideParens<T,N>(m_scanner));
    }
    typename DstBrigType::CType visitImpl(...) const {
        assert(false); // no other than packed types expected
        return typename DstBrigType::CType(); 
    }

public:
    ReadPackedLiteral(Scanner& scanner) : m_scanner(scanner) {}
    
    template <typename BrigType>
    typename DstBrigType::CType visit() const {
        return visitImpl(reinterpret_cast<BrigType*>(NULL)); // dispatch
    }
    typename DstBrigType::CType visitNone(unsigned) const { 
        assert(false); 
        return typename DstBrigType::CType();
    }
};


template <typename DstBrigType, 
          template<typename, typename> class Convertor>
typename DstBrigType::CType readPackedLiteral(Scanner& scanner)
{
    assert(scanner.token()==EPackedLiteral);
    SrcLoc const srcLoc = scanner.srcLoc();
    unsigned const typeFromToken = scanner.brigId();

    scanner.scan(); // skiping prefix
    scanner.eatToken(ELParen);
    
    typename DstBrigType::CType res = typename DstBrigType::CType();
    try {
        res = dispatchByType<typename DstBrigType::CType>(typeFromToken,ReadPackedLiteral<DstBrigType,Convertor>(scanner));
    } catch (const ConversionError& e) {
        scanner.syntaxError(e.what(),srcLoc); // translate it to syntax error
    }
    scanner.eatToken(ERParen);
    return res;
}

template <typename DstBrigType, 
          template<typename, typename> class Convertor>
typename DstBrigType::CType  readValueIncludingPacked(Scanner& scanner)
{
    if (scanner.token()==EPackedLiteral) {
        return readPackedLiteral<DstBrigType,Convertor>(scanner);
    }
    return scanner.readValue<DstBrigType,Convertor>();
}


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

Optional<Brig::BrigWidth8_t> tryParseWidthModifier(Scanner& scanner) {
    Optional<Brig::BrigWidth8_t> res;
    if (scanner.token() == EMWidth) {
        scanner.scan();
        scanner.eatToken(ELParen);
        switch(scanner.token()) {
        case EKWWidthAll:    res = Brig::BRIG_WIDTH_ALL; scanner.scan(); break;
        case EWaveSizeMacro: res = Brig::BRIG_WIDTH_WAVESIZE; scanner.scan(); break;
        default:
            uint32_t const width = readInt<Brig::BRIG_TYPE_U32>(scanner);
            if (width < 1u || width > 2147483648u) {
                scanner.syntaxError("Invalid width");
            }
            if (width & (width-1)) {
                scanner.syntaxError("Width must be a power of two");
            }
            res = toBrigWidth(width);
            break;
        }
        scanner.expect(ERParen);
        scanner.scanModifier();
    }
    return res;
}

Optional<unsigned> tryParseEquiv(Scanner& scanner) {
    Optional<unsigned> equivClass;
    if (scanner.token() == EMEquiv) {
        scanner.scan();
        scanner.eatToken(ELParen);
        equivClass = readInt<Brig::BRIG_TYPE_U32>(scanner);
        if (equivClass >= 256) {
            scanner.syntaxError("equivalence class should be in the 0..255 range");
        }
        scanner.expect(ERParen);
        scanner.scanModifier();
    }
    return equivClass;
}

Inst parseMnemoBasic(Scanner& scanner, Brigantine& bw, bool expectType) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    Optional<unsigned> type;
    if (expectType) type = scanner.eatModifier(EMType);

    scanner.expect(EMNone); // parse done

    if (opCode == Brig::BRIG_OPCODE_CODEBLOCKEND) {
        scanner.syntaxError("Instruction codeblockend is not allowed in HSAIL code");
    }
    InstBasic inst = bw.addInst<InstBasic>(opCode);
    inst.type() = type.isInitialized() ? Brig::BrigTypeX(type.value()) : Brig::BRIG_TYPE_NONE;
    return inst;
}

Inst parseMnemoBasic(Scanner& scanner, Brigantine& bw) {
    return parseMnemoBasic(scanner,bw,true);
}

Inst parseMnemoBasicNoType(Scanner& scanner, Brigantine& bw) {
    Inst res = parseMnemoBasic(scanner,bw,false);
    if (isGcnInst(res.opcode())) res.type() = Brig::BRIG_TYPE_B32; // default type for GCN
    return res;
}


Inst parseMnemoBasicOrMod(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    Optional<unsigned> const ftz     = scanner.tryEatModifier(EMFTZ);
    Optional<unsigned> const round   = scanner.tryEatModifier(EMRound);
    Optional<unsigned> const packing = scanner.tryEatModifier(EMPacking);
    unsigned const           type    = scanner.eatModifier(EMType);
    scanner.expect(EMNone); // parse done

    if (ftz.isInitialized() || round.isInitialized() || packing.isInitialized()) {
        InstMod inst = bw.addInst<InstMod>(opCode);
        inst.modifier().ftz() = ftz.isInitialized();
        inst.modifier().round() = round.isInitialized() ? round.value() : getDefRounding(opCode,type);
        inst.pack() = packing.isInitialized() ? Brig::BrigPack(packing.value()) : Brig::BRIG_PACK_NONE;
        inst.type() = type;
        return inst;
    } else {
        InstBasic inst = bw.addInst<InstBasic>(opCode);
        inst.type() = type;
        return inst;
    }
}

Inst parseMnemoSourceType(Scanner& scanner, Brigantine& bw, int* outVector/* out */) {
    assert(scanner.token()==EInstruction || scanner.token()==EInstruction_Vx);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    Optional<unsigned> const vector = scanner.tryEatModifier(EMVector);
    Optional<unsigned> const dtype  = scanner.eatModifier(EMType);
    Optional<unsigned> const stype  = scanner.eatModifier(EMType);
    scanner.expect(EMNone); // parse done

    InstSourceType inst = bw.addInst<InstSourceType>(opCode);
    inst.sourceType() = stype;
    inst.type() = dtype;
    if (outVector!=NULL) {
        *outVector = vector.isInitialized() ? vector.value() : 1;
    }
    return inst;
}

Inst parseMnemoSourceType(Scanner& scanner, Brigantine& bw) {
    return parseMnemoSourceType(scanner,bw,NULL);
}

Inst parseMnemoSeg(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    Optional<unsigned> const segment = scanner.tryEatModifier(EMSegment);
              unsigned const   dtype = scanner.eatModifier(EMType);
    Optional<unsigned> const   stype = scanner.tryEatModifier(EMType);
    scanner.expect(EMNone); // parse done

    InstSeg inst = bw.addInst<InstSeg>(opCode);
    inst.sourceType() = stype.isInitialized() ? Brig::BrigTypeX(stype.value()) : Brig::BRIG_TYPE_NONE;
    inst.segment() = segment.isInitialized()  ? Brig::BrigSegment(segment.value()) : Brig::BRIG_SEGMENT_FLAT;
    inst.type() = dtype;
    return inst;
}

Inst parseMnemoAddr(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    Optional<unsigned> const segment = scanner.tryEatModifier(EMSegment);
              unsigned const    type = scanner.eatModifier(EMType);
    scanner.expect(EMNone); // parse done

    InstAddr inst = bw.addInst<InstAddr>(opCode);
    inst.segment() = segment.isInitialized() ? 
                        segment : 
                        isGcnInst(inst.opcode())? Brig::BRIG_SEGMENT_EXTSPACE0 : Brig::BRIG_SEGMENT_FLAT;
    inst.type() = type;
    return inst;
}


Inst parseMnemoMem(Scanner& scanner, Brigantine& bw, int* outVector/* out */) {
    assert(scanner.token()==EInstruction || scanner.token()==EInstruction_Vx);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    Optional<unsigned>           const vector     = scanner.tryEatModifier(EMVector);
    Optional<Brig::BrigWidth8_t> const width      = tryParseWidthModifier(scanner);
    Optional<unsigned>           const segment    = scanner.tryEatModifier(EMSegment);
    Optional<unsigned>           const aligned    = scanner.tryEatModifier(EMAligned);
    Optional<unsigned>           const equivClass = tryParseEquiv(scanner);
    unsigned                     const type       = scanner.eatModifier(EMType);
    scanner.expect(EMNone); // parse done

    InstMem inst = bw.addInst<InstMem>(opCode);
    inst.type()       = type;
    inst.segment()    = segment.isInitialized() ?    Brig::BrigSegment(segment.value())    : Brig::BRIG_SEGMENT_FLAT;
    inst.equivClass() = equivClass.isInitialized() ? equivClass.value() : 0;
    inst.width()      = width.isInitialized() ?      width.value()      : getDefWidth(inst);
    inst.modifier().aligned()  = aligned.isInitialized();

    if (outVector!=NULL) {
        *outVector = vector.isInitialized() ? vector.value() : 1;
    }
    return inst;
}

Inst parseMnemoMem(Scanner& scanner, Brigantine& bw) {
    return parseMnemoMem(scanner,bw,NULL);
}

Inst parseMnemoBr(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();
    Optional<Brig::BrigWidth8_t> const width = tryParseWidthModifier(scanner);
    scanner.expect(EMNone); // parse done

    InstBr inst = bw.addInst<InstBr>(opCode,Brig::BRIG_TYPE_NONE);

    //dp FIXME: could it be improved?
    //dp: should initialize width using getDefWidth, but it is only possible after parsing branch/call args 
    inst.width() = width.isInitialized() ? Brig::BrigWidth(width.value()) : Brig::BRIG_WIDTH_NONE; // dp: will be fixed later, after parsing operands


    // TBD095 why modifier? its not used
    return inst;
}

Inst parseMnemoCmp(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();
   
    unsigned           const comparisonOperator = scanner.eatModifier(EMCompare);
    Optional<unsigned> const ftz     = scanner.tryEatModifier(EMFTZ); 
    Optional<unsigned> const packing = scanner.tryEatModifier(EMPacking);
    unsigned           const dstType = scanner.eatModifier(EMType, "destination type");
    unsigned           const srcType = scanner.eatModifier(EMType, "source type");
    scanner.expect(EMNone); // parse done

    InstCmp inst = bw.addInst<InstCmp>(opCode,dstType);
    inst.compare()        = comparisonOperator;
    inst.sourceType()     = srcType;
    inst.modifier().ftz() = ftz.isInitialized();
    inst.pack()           = packing.isInitialized() ? Brig::BrigPack(packing.value()) : Brig::BRIG_PACK_NONE;
    return inst;
}

Inst parseMnemoCvt(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    Optional<unsigned> const ftz    = scanner.tryEatModifier(EMFTZ); // TBD
    Optional<unsigned> const round  = scanner.tryEatModifier(EMRound); // TBD is this correct?
    unsigned           const dstType = scanner.eatModifier(EMType, "destination type");
    unsigned           const srcType = scanner.eatModifier(EMType, "source type");
    scanner.expect(EMNone); // parse done

    InstCvt inst = bw.addInst<InstCvt>(opCode,dstType);
    inst.sourceType()       = srcType;
    inst.modifier().ftz()   = ftz.isInitialized();
    inst.modifier().round() = round.isInitialized() ? round.value() : getDefRoundingForCvt(srcType,dstType);
    return inst;
}

Inst parseMnemoAtomic(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    unsigned           const atomicOperation = scanner.eatModifier(EMAtomicOp);
    Optional<unsigned> const segment         = scanner.tryEatModifier(EMSegment);
    Optional<unsigned> const memoryOrder     = scanner.tryEatModifier(EMMemoryOrder);
    Optional<unsigned> const memoryScope     = scanner.tryEatModifier(EMMemoryScope);
    unsigned           const type            = scanner.eatModifier(EMType);
    scanner.expect(EMNone); // parse done

    InstAtomic inst = bw.addInst<InstAtomic>(opCode,type);
    inst.atomicOperation() = atomicOperation;
    inst.segment()         = segment.isInitialized() ? Brig::BrigSegment(segment.value()) : Brig::BRIG_SEGMENT_FLAT;
    inst.memoryOrder()     = memoryOrder.isInitialized() ? memoryOrder.value() : getDefOrder(opCode);
    inst.memoryScope()     = memoryScope.isInitialized() ? memoryScope.value() : getDefScope(opCode);
    return inst;
}

Inst parseMnemoBar(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    Optional<Brig::BrigWidth8_t> const width = tryParseWidthModifier(scanner);
    Optional<unsigned>           const memoryOrder = scanner.tryEatModifier(EMMemoryOrder);
    Optional<unsigned>           const memoryScope = scanner.tryEatModifier(EMMemoryScope);
    Optional<unsigned>           const memoryFence = scanner.tryEatModifier(EMMemoryFence);

    scanner.expect(EMNone); // parse done

    InstBar inst = bw.addInst<InstBar>(opCode,Brig::BRIG_TYPE_NONE);

    inst.width()       = width.isInitialized() ? width.value() : getDefWidth(inst);  // dp
    inst.memoryOrder() = memoryOrder.isInitialized() ? memoryOrder.value() : getDefOrder(opCode);
    inst.memoryScope() = memoryScope.isInitialized() ? memoryScope.value() : getDefScope(opCode);
    inst.memoryFence() = memoryFence.isInitialized() ? memoryFence.value() : getDefFence(opCode);
    return inst;
}

Inst parseMnemoImage(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    unsigned const vector = scanner.eatModifier(EMVector);
    if (vector!=4) {
        scanner.syntaxError("only v4 vector allowed");
    }
     
    unsigned const geom      = scanner.eatModifier(EMGeom);
    unsigned const dstType   = scanner.eatModifier(EMType);
    unsigned const imgType   = scanner.eatModifier(EMType);
    unsigned const coordType = scanner.eatModifier(EMType);
    scanner.expect(EMNone); // parse done

    InstImage inst = bw.addInst<InstImage>(opCode,dstType);
    inst.geometry()  = geom;
    inst.imageType() = imgType;
    inst.coordType() = coordType;
    return inst;
}

Inst parseMnemoAtomicImage(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    unsigned const atomicOperation = scanner.eatModifier(EMAtomicOp);
    unsigned const geom            = scanner.eatModifier(EMGeom);
    unsigned const dstType         = scanner.eatModifier(EMType);
    unsigned const imgType         = scanner.eatModifier(EMType);
    unsigned const coordType       = scanner.eatModifier(EMType);
    scanner.expect(EMNone); // parse done

    InstAtomicImage inst = bw.addInst<InstAtomicImage>(opCode,dstType);
    inst.atomicOperation() = atomicOperation;
    inst.geometry()        = geom;
    inst.imageType()       = imgType;
    inst.coordType()       = coordType;
    return inst;
}

Inst parseMnemoLane(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    Optional<Brig::BrigWidth8_t> const width = tryParseWidthModifier(scanner);
              unsigned const   dtype = scanner.eatModifier(EMType);
    Optional<unsigned> const   stype = scanner.tryEatModifier(EMType);
    scanner.expect(EMNone); // parse done

    InstLane inst = bw.addInst<InstLane>(opCode);
    inst.sourceType() = stype.isInitialized() ? stype.value() : Brig::BRIG_TYPE_NONE;
    inst.width() = width.isInitialized() ? width.value() : getDefWidth(inst);
    inst.type() = dtype;
    return inst;
}

Inst parseMnemoNop(Scanner& scanner, Brigantine& bw) {
    assert(scanner.token()==EInstruction);
    scanner.scanModifier();
    InstBasic inst = bw.addInst<InstBasic>(Brig::BRIG_OPCODE_NOP);
    inst.type() = Brig::BRIG_TYPE_NONE;
    return inst;
}

/*
Inst parseMnemoInstLdSt(Scanner& scanner, Brigantine& bw) {
    return parseMnemoInstLdStVx(scanner,bw);
}

InstImage parseMnemoInstImageVx(Scanner& scanner, Brigantine &bw, int *outVector=NULL) {
    assert(scanner.token()==EInstruction_Vx);
    unsigned const opCode = scanner.brigId();
    scanner.scanModifier();

    int vector = 1;
    switch(scanner.token()) {
    case EMV2:
        vector = 2;
        scanner.scanModifier();
        break;
    case EMV4:
        vector = 4;
        scanner.scanModifier();
        break;
    default:; // do nothing
    }
    if (outVector) {
        *outVector = vector;
    }

    unsigned const geom = scanner.eatModifier(EMGeom);
    unsigned const dstType = scanner.eatModifier(EMType);
    unsigned const srcType = scanner.eatModifier(EMType);
    scanner.expect(EMNone); // parse done

    InstImage inst = bw.addInst<InstImage>(opCode,dstType);
    inst.stype() = srcType;
    inst.geom() = geom;
    return inst;
}

Inst parseMnemoInstImage(Scanner& scanner, Brigantine &bw) {
    return parseMnemoInstImageVx(scanner,bw);
}
*/

typedef Inst (*OpcodeParser)(Scanner&, Brigantine &);
OpcodeParser getOpcodeParser(Brig::BrigOpcode16_t opcode); // generated

Inst parseMnemo(Scanner& scanner, Brigantine& bw) {
    Inst res;
    switch(scanner.token()) {
    case EInstruction: 
    case EInstruction_Vx: {
            OpcodeParser const parser = getOpcodeParser(scanner.brigId());
            if (!parser) {
                 scanner.syntaxError("unknown instruction");
            }
            res = parser(scanner,bw);
        } break;
    
    default:;
    }
    return res;
}

Inst parseMnemo(const char* str, Brigantine& bw) {
    std::istringstream instr(str);
    Scanner scanner(instr);
    return parseMnemo(scanner,bw);
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

void Parser::parseSource()
{
    PDBG;
    while (token()!=EEndOfSource) {
        parseProgram();
    }
}

void Parser::parseProgram()
{
    PDBG;
    m_bw.startProgram();

    m_gcnEnabled = false;

    parseVersion();
    while (token()!=EEndOfSource && token()!=EKWVersion) {
        parseTopLevelStatement();
    }

    storeComments(m_bw.container().insts().end()); // there might be comments before end of the program
    m_bw.endProgram();   
}


void Parser::parseVersion()
{
    PDBG;

    SourceInfo const srcInfo = tokenSourceInfo();
    eatToken(EKWVersion);
    uint16_t const major = readNonNegativeInt<Brig::BRIG_TYPE_U16>(m_scanner);

    eatToken(EColon);
    uint16_t const minor = readNonNegativeInt<Brig::BRIG_TYPE_U16>(m_scanner);

    Optional<Brig::BrigProfile8_t>      profile;
    Optional<Brig::BrigMachineModel8_t> machineModel;

    expect(EColon);

    if (m_scanner.scanTargetOption() != ETargetProfile) {
        syntaxError("Expected target profile");
    }
    profile = m_scanner.brigId();
    scan();

    expect(EColon);

    if (m_scanner.scanTargetOption() != ETargetMachine) {
        syntaxError("Expected machine model");
    }
    machineModel = m_scanner.brigId();
    scan();

    eatToken(ESemi);

    m_bw.version(major,minor,machineModel.value(),profile.value(),&srcInfo);
}

inline static bool IsDeclStart(ETokens t)
{
    return (t==EKWConst || t==EKWAlign || t==ESegment || t==EAttribute);
}

void Parser::storeComments(Inst before)
{
    while (m_scanner.hasComments()) {
        DirectiveComment cmt = m_bw.container().append<DirectiveComment>();
        cmt.name() = m_scanner.grabComment();
        cmt.code() = before;
    }
}



void Parser::parseTopLevelStatement()
{
    PDBG;

    storeComments(m_bw.container().insts().end());

    switch (token()) {
    case EKWKernel:       parseKernel(); break;
    case EKWFunction:     parseFunction(); break;
    case EKWSignature:    parseSignature(); break; 
    case EKWExtension:    parseExtension();break;
    case EKWFile:         parseFileDecl();break;
    case EKWPragma:       parsePragma();break;
    case EKWBlockStart:   parseBlock();break;
    case EKWFbarrier:     parseFbarrier(false);break;
    case EControl:        parseControl();break;
    default:
        if (IsDeclStart(token())) {
            DeclPrefix const declPfx = parseDeclPrefix();
            switch (token()) {
            case EKWKernel:   parseKernel(&declPfx); break;
            case EKWFunction: parseFunction(&declPfx); break;
            case ESegment:
                parseDecl(false,false,declPfx);
                eatToken(ESemi);
            break;
            default:
                syntaxError("Unexpected token after declaration prefix");
            }
        } else {
            syntaxError("Unexpected token at top level");
        }
    }
}

Optional<uint16_t> Parser::tryParseFBar()
{
    Optional<uint16_t> res;
    if (tryEatToken(EColon)) {
        eatToken(EKWFBar);
        eatToken(ELParen);
        res = readNonNegativeInt<Brig::BRIG_TYPE_U16>(m_scanner);
        eatToken(ERParen);
    }
    return res;
}

void Parser::parseKernel(const DeclPrefix* declPrefix) // declPrefix is not used by spec but cannot be ignored
{
    if (declPrefix) {
        if (declPrefix->align.isInitialized())    syntaxError("Align is not allowed with kernels");
        if (declPrefix->hasConst.isInitialized()) syntaxError("Const is not allowed with kernels");
        if (declPrefix->linkage.isInitialized())  syntaxError("Extern/static is not allowed with kernels");
    }
    PDBG;
    assert(token() == EKWKernel);
    SourceInfo const srcInfo = tokenSourceInfo();
    scan();

    expect(EIDStatic);
    SRef const funcName = m_scanner.readStringValue();
    
    DirectiveKernel kern = m_bw.declKernel(funcName,&srcInfo);

    eatToken(ELParen);

    if (!tryEatToken(ERParen)) {
        Directive first = parseDecl(true,true);
        if (first) {
            m_bw.addInputParameter(first);
            while(tryEatToken(EComma)) {
                m_bw.addInputParameter(parseDecl(true,true));
            }
        }
        eatToken(ERParen);
    }

    if (!kern.firstInArg()) {
        kern.firstInArg() = m_bw.container().directives().end();
    }

    if (token() == ELCurl) {
        parseCodeBlock();

        //int const instCount = parseCodeBlock();
        //if (instCount==0) {
        //    syntaxError("empty kernel codeblocks aren't allowed");
        //}

    } else {
        kern.modifier().isDeclaration() = true;
        kern.firstScopedDirective() = m_bw.container().directives().end();
    }

    eatToken(ESemi);
}

void Parser::parseFunction(const DeclPrefix* declPrefix)
{
    if (declPrefix) {
        if (declPrefix->align.isInitialized())    syntaxError("Align is not allowed with functions");
        if (declPrefix->hasConst.isInitialized()) syntaxError("Const is not allowed with functions");
    }

    PDBG;
    assert(token() == EKWFunction);
    SourceInfo const srcInfo = tokenSourceInfo();
    scan();

    expect(EIDStatic);
    SRef const funcName = m_scanner.readStringValue();
    
    DirectiveFunction func = m_bw.declFunc(funcName,&srcInfo);
    if (declPrefix && declPrefix->linkage.isInitialized()) {
        func.modifier().linkage() = declPrefix->linkage;
    }

    eatToken(ELParen);

    if (!tryEatToken(ERParen)) {
        Directive first = parseDecl(true,true);
        if (first) {
            m_bw.addOutputParameter(first);
            while(tryEatToken(EComma)) {
                m_bw.addOutputParameter(parseDecl(true,true));
            }
        }
        eatToken(ERParen);
    }

    eatToken(ELParen);

    if (!tryEatToken(ERParen)) {
        Directive first = parseDecl(true,true);
        if (first) {
            m_bw.addInputParameter(first);
            while(tryEatToken(EComma)) {
                m_bw.addInputParameter(parseDecl(true,true));
            }
        }
        eatToken(ERParen);
    }

    if (!func.firstInArg()) {
        func.firstInArg() = m_bw.container().directives().end();
    }

    if (token() == ELCurl) {
        parseCodeBlock();
    } else {
        func.firstScopedDirective() = m_bw.container().directives().end();
        func.modifier().isDeclaration() = true;
    }

    eatToken(ESemi);
}

void Parser::parseSigArgs(Scanner& s,DirectiveSignatureArguments types, DirectiveSignatureArguments::ArgKind argKind)
{
    eatToken(ELParen);
    if (token()!=ERParen) {
        do { 
            uint8_t align;
            {
                DeclPrefix const declPfx = parseDeclPrefix();
                align = declPfx.align.isInitialized() ? declPfx.align.value() : 0;
            }
    
            expect(ESegment);
            unsigned const segment = m_scanner.brigId();
            if (segment!=Brig::BRIG_SEGMENT_ARG) {
                syntaxError("only arg segment allowed in signature declaration");
            }

            m_scanner.scanModifier();
            expect(EMType, "type");
            unsigned const dType = m_scanner.brigId();
            scan();

            tryEatToken(EIDLocal); // optional arg name (not used)

            Optional<uint64_t> dim;
            if (tryEatToken(ELBrace)) {
                dim = token() != ERBrace ? readPositiveInt<Brig::BRIG_TYPE_U64>(m_scanner) : 0;
                eatToken(ERBrace);
            }
            types.addArg(argKind,dType,dim,align);
        } while (tryEatToken(EComma));
    }
    eatToken(ERParen);
}

void Parser::parseSignature()
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    eatToken(EKWSignature);

    expect(EIDStatic);
    SRef const name = m_scanner.readStringValue();

    DirectiveSignature sig = m_bw.declSignature(name,&srcInfo);

    if (token()==ELParen) {
        parseSigArgs(m_scanner, sig.args(), DirectiveSignatureArguments::Output);
        if (token()==ELParen) {
            parseSigArgs(m_scanner, sig.args(), DirectiveSignatureArguments::Input);
        } else {
            // oops, these were actually input parameters
            sig.inCount() = sig.outCount();
            sig.outCount() = 0;
        }
    }

    eatToken(ESemi);
}

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
    switch (token()) {
    case ELabel:           parseLabel(); break;
    case EKWPragma:        parsePragma(); break;
    case EKWSection:       parseDebug(); break;
    case EKWLoc:           parseLocation(); break;
    case EKWBlockStart:    parseBlock();break;
    case EControl:         parseControl();break;
    case EKWFbarrier:      parseFbarrier(true);break;
    case EKWLabelTargets:  parseLabelTargets(); break;
    case ELCurl:           numInsts += parseArgScope(); break;
    case EInstruction:     
    case EInstruction_Vx:
        // TBD
        // we have to call storeComments before instruction parse for 2 reasons:
        // 1. You can't unconditionally call storeComments before you know you
        // met an instuction, because in case of non-inst m_container.insts().end()
        // will point to uninitialized memory
        // 2. Even if you know you've met an instruction it would be better to get
        // instruction offset after it is successfully parsed and store accumulated
        // comments using that offset. However because parsing always ends with
        // forward scan you may grab comments that actually follow your instruction
        // (scan accumulate comments in scanner)
        storeComments(m_bw.container().insts().end());
        parseInst();
        ++numInsts;
    break;
    default:
        if (IsDeclStart(token())) {
            parseDecl(false,true);
            eatToken(ESemi);
        } else {
            syntaxError("Unexpected token in body statement");
        }
    }
    return numInsts;
}

int Parser::parseArgScope()
{
    {
        SourceInfo const srcInfo = tokenSourceInfo();
        DirectiveArgScopeStart s = m_bw.startArgScope(&srcInfo);
    }

    eatToken(ELCurl);
    int numInsts = 0;
    while (token()!=ERCurl) {
        numInsts += parseBodyStatement();
    };

    {
        SourceInfo const srcInfo = tokenSourceInfo();
        DirectiveArgScopeEnd e = m_bw.endArgScope(&srcInfo);
    }
    scan(); // skip }
    return numInsts;
}

void Parser::parseLabel()
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    SRef const name = m_scanner.readStringValue();
    eatToken(EColon);

    m_bw.addLabel(name,&srcInfo);
}

void Parser::parseLabelTargets() {
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    eatToken(EKWLabelTargets);

    expect(EIDLocal);
    SRef const name = m_scanner.readStringValue();

    eatToken(EEqual);
    eatToken(ELCurl);
    DirectiveLabelTargets list = m_bw.createLabelTargets(name,&srcInfo);

    parseLabelList(list.labels(),0);

    eatToken(ERCurl);
    eatToken(ESemi);
}

template <typename List>
unsigned Parser::parseLabelList(List list, unsigned expectedSize)
{
    unsigned numRead = 0;
    do {
        if (expectedSize && numRead > expectedSize) {
            syntaxError("Too many elements");
        }
        SourceInfo const srcInfo = tokenSourceInfo();
        expect(ELabel);
        const SRef& name = m_scanner.readStringValue();
        ++numRead;
        m_bw.appendLabelRef(list,name,&srcInfo);         
    } while(tryEatToken(EComma));

    if (expectedSize && numRead < expectedSize) {
        syntaxError("more labels expected");
    }
    return numRead;
}

class ParseValueList
{
    Scanner&       m_scanner;
    ArbitraryData& m_data;
    unsigned       m_expElements;

    ParseValueList& operator=(const ParseValueList&);

public:
    ParseValueList(Scanner& scanner, ArbitraryData& data, unsigned expElements)
        : m_scanner(scanner), m_data(data), m_expElements(expElements) {}

    template <typename BrigType> unsigned visit() const {
        typedef typename BrigType::CType CType;
        size_t const numElementsBefore = m_data.numElements<CType>();
        do {
            if (m_expElements && m_data.numElements<CType>() > m_expElements) {
                m_scanner.syntaxError("elements more than expected");
            }
            m_data.push_back(readValueIncludingPacked<BrigType,ConvertImmediate>(m_scanner));
        } while(m_scanner.tryEatToken(EComma));
        return static_cast<unsigned>(m_data.numElements<CType>() - numElementsBefore);
    }

    unsigned visitNone(unsigned ) const {
        assert(false);
        return 0;
    }
};

unsigned Parser::parseValueList(Brig::BrigType16_t type, ArbitraryData& data, unsigned maxValues) {
    return dispatchByType<unsigned>(type,ParseValueList(m_scanner,data,maxValues));
}

Directive Parser::parseVariableInitializer(Brig::BrigType16_t type, bool asArray, unsigned expectedSize)
{   
    Directive res;
    SourceInfo const srcInfo = tokenSourceInfo();
    if (asArray) {
        eatToken(ELCurl);
    }
    if (token()==ELabel) {
        if ( m_bw.localScope()==NULL ) { 
            syntaxError("label initializers can be placed only inside func/kernel body definition");
        }      
        DirectiveLabelInit init = m_bw.createLabelInit(&srcInfo);
        init.elementCount() = parseLabelList(init.labels(),expectedSize);
        res = init;
    } else {
        DirectiveVariableInit init = m_bw.createVariableInitializer(type,&srcInfo);
        ArbitraryData values;
        init.elementCount() = parseValueList(type,values,expectedSize);
        init.data() = values.toSRef();
        res = init;
    }
    if (asArray) {
        eatToken(ERCurl);
    }
    return res;
}

DirectiveImageInit Parser::parseImageInitializer()
{
    SourceInfo const srcInfo = tokenSourceInfo();
    DirectiveImageInit init = m_bw.createImageInitializer(&srcInfo);
    // TBD double initialize field check
    eatToken(ELCurl);
    do {
        SourceInfo const srcInfo = tokenSourceInfo();
        ETokens const t = token();
        scan();
        expect(EEqual); // not using eatToken() to suppress forward scan
        switch(t) {
        case EKWImageWidth:
            scan(); // regular token follows
            if (0 != init.width()) {
                syntaxError("Width already set");
            }
            init.width() = readPositiveInt<Brig::BRIG_TYPE_U32>(m_scanner);
            break; 
        case EKWImageHeight:
            scan(); // regular token follows
            if (0 != init.height()) {
                syntaxError("Height already set");
            }
            init.height() = readPositiveInt<Brig::BRIG_TYPE_U32>(m_scanner);
            break;
        case EKWImageDepth:
            scan(); // regular token follows
            if (0 != init.depth()) {
                syntaxError("Depth already set");
            }
            init.depth() = readPositiveInt<Brig::BRIG_TYPE_U32>(m_scanner);
            break;
        case EKWImageFormat:
            if (init.format() != Brig::BRIG_FORMAT_UNKNOWN) {
                syntaxError("Format already set");
            }
            init.format() = m_scanner.scanImageFormat();
            scan(); // fwd scan
            break;
        case EKWImageOrder:
            if (init.order() != Brig::BRIG_ORDER_UNKNOWN) {
                syntaxError("Order already set");
            }
            init.order() = m_scanner.scanImageOrder();
            scan(); // fwd scan
            break;
        default:
            syntaxError("Invalid image property name",&srcInfo);
        }
    } while (tryEatToken(EComma));
    eatToken(ERCurl);
    return init;
}

DirectiveSamplerInit Parser::parseSamplerInitializer()
{
    SourceInfo const srcInfo = tokenSourceInfo();
    DirectiveSamplerInit init = m_bw.createSamplerInitializer(&srcInfo);
    // TBD default values? double initialize or uninitialized field check
    eatToken(ELCurl);
    unsigned propMask = 0;
    do {
        SourceInfo const srcInfo = tokenSourceInfo();
        ETokens const t = token();
        scan();
        eatToken(EEqual);
        if (t >= ESamplerFirstProp && t <= ESamplerLastProp) {
            unsigned bit = (1 << (t - ESamplerFirstProp));
            if (propMask & bit) {
                syntaxError("Duplicate sampler property");
            }
            propMask |= bit;
        }
        switch(t) {
        case EKWSamplerBoundaryU:          
            eatToken(ESamplerBoundaryMode);
            init.boundaryU() = m_scanner.brigId();
            break;
        case EKWSamplerBoundaryV:
            eatToken(ESamplerBoundaryMode);
            init.boundaryV() = m_scanner.brigId();
            break;
        case EKWSamplerBoundaryW:
            eatToken(ESamplerBoundaryMode);
            init.boundaryW() = m_scanner.brigId();
            break;
        case EKWSamplerCoord:
            eatToken(ESamplerCoord);
            init.modifier().isUnnormalized() = m_scanner.brigId()==0; // TBD wrapper
            break;
        case EKWSamplerFilter:
            eatToken(ESamplerFilter);
            init.modifier().filter() = m_scanner.brigId(); // TBD wrapper
            break;
        default:
            syntaxError("Invalid sampler object property name",&srcInfo);
        }
    } while (tryEatToken(EComma));
    eatToken(ERCurl);
    // TBD simplify
    for(unsigned prop = ESamplerFirstProp; prop <= ESamplerLastProp; ++prop) {
        if (propMask & (1 << (prop - ESamplerFirstProp))) {
            continue;
        }
        switch(prop) {
        case EKWSamplerBoundaryU:
            syntaxError("boundaryU value missing");
            break;
        case EKWSamplerBoundaryV:
            syntaxError("boundaryV value missing");
            break;
        case EKWSamplerBoundaryW:
            syntaxError("boundaryW value missing");
            break;
        case EKWSamplerCoord:
            syntaxError("coord value missing");
            break;
        case EKWSamplerFilter:
            syntaxError("filter value missing");
            break;
        }
    }
    return init;
}

DeclPrefix Parser::parseDeclPrefix()
{
    DeclPrefix res;

    bool exitDo = false;
    do {
        switch(token()) {
        case EKWConst:
            if (res.hasConst.isInitialized()) {
                syntaxError("only one const modificator is allowed");
            }
            res.hasConst = true;
            scan();
            break;
        case EKWAlign:
            if (res.align.isInitialized()) {
                syntaxError("only one align modificator is allowed");
            }
            scan();
            res.align = readPositiveInt<Brig::BRIG_TYPE_U16>(m_scanner);
            break;
        case EAttribute:
            if (res.linkage.isInitialized()) {
                syntaxError("only one attribute is allowed");
            }
            res.linkage = m_scanner.brigId();
            scan();
            break;
        default:
            exitDo = true;
        }
    } while(!exitDo);
    return res;
}

DirectiveVariable Parser::parseDecl(bool isArg, bool isLocal)
{
    PDBG;
    DeclPrefix const declPfx = parseDeclPrefix();
    return parseDecl(isArg,isLocal,declPfx);
}

DirectiveVariable Parser::parseDecl(bool isArg, bool isLocal,const DeclPrefix& declPfx)
{
    SourceInfo const srcInfo = tokenSourceInfo();
    expect(ESegment);
    unsigned const segment = m_scanner.brigId();

    m_scanner.scanModifier();
    expect(EMType, "type");
    unsigned const dType = m_scanner.brigId();
    scan();

    expect(isLocal ? EIDLocal : EIDStatic);
    SRef const name = m_scanner.readStringValue();

    DirectiveVariable sym;
    switch(dType) {
    case Brig::BRIG_TYPE_ROIMG: 
    case Brig::BRIG_TYPE_RWIMG:
        sym = m_bw.addImage(name,segment,&srcInfo);
        sym.type() = dType;
        break;
    case Brig::BRIG_TYPE_SAMP: 
        sym = m_bw.addSampler(name,segment,&srcInfo);
        break;
    default:
        sym = m_bw.addVariable(name,segment,dType,&srcInfo);
    }
   
    if (declPfx.align.isInitialized())
        sym.align() = declPfx.align;

    if (declPfx.hasConst.isInitialized())
        sym.modifier().isConst() = declPfx.hasConst;

    if (declPfx.linkage.isInitialized())
        sym.modifier().linkage() = declPfx.linkage;

    if (tryEatToken(ELBrace)) {
        sym.modifier().isArray() = true;
        if (token() != ERBrace) {
            sym.dim() = readPositiveInt<Brig::BRIG_TYPE_U32>(m_scanner);
        } else {
            sym.modifier().isFlexArray() = 
                sym.modifier().linkage() != Brig::BRIG_LINKAGE_EXTERN;
        }
        eatToken(ERBrace);
    }

    if (tryEatToken(EEqual)) {
        switch(dType) {
        case Brig::BRIG_TYPE_ROIMG:
        case Brig::BRIG_TYPE_RWIMG: sym.init() = parseImageInitializer();   break;
        case Brig::BRIG_TYPE_SAMP:  sym.init() = parseSamplerInitializer(); break;
        default: 
            sym.init() = parseVariableInitializer(dType,sym.modifier().isArray(),static_cast<unsigned>(sym.dim()));  // TBD095 check static_cast
            break; 
        }

        sym.modifier().isFlexArray() = false;
            
        if (sym.modifier().isArray() && sym.dim() == 0) {
            if (DirectiveVariableInit init = sym.init())
                sym.dim() = init.elementCount();
            else if (DirectiveLabelInit init = sym.init())
                sym.dim() = init.elementCount();
            else // Image or Sampler
                sym.dim() = 1;
        }
    }

    sym.modifier().isDeclaration() = (isArg || sym.modifier().linkage() == Brig::BRIG_LINKAGE_EXTERN);

    return sym;
}

DirectiveFbarrier Parser::parseFbarrier(bool isLocal) {
    PDBG;
    eatToken(EKWFbarrier);

    SourceInfo const srcInfo = tokenSourceInfo();
    expect(isLocal ? EIDLocal : EIDStatic);
    SRef const name = m_scanner.readStringValue();

    DirectiveFbarrier fbar = m_bw.addFbarrier(name,&srcInfo);

    eatToken(ESemi);
    return fbar;
}

static std::string parseStringLiteral(Scanner&);

void Parser::parseBlock()
{
    PDBG;
    expect(EKWBlockStart);

    SourceInfo const srcInfo = tokenSourceInfo();
    scan();
    std::string const blockName = parseStringLiteral(m_scanner);

    BrigSectionImpl *section = NULL;
    if (blockName=="rti") {
        section = &m_bw.container().directives();
    }  else if (blockName=="debug") {
        section = &m_bw.container().debugChunks();
    } else {
        syntaxError("unsupported block name");
    }

    BlockStart bs = section->append<BlockStart>(srcInfo);
    bs.name() = blockName;
    bs.code() = m_bw.container().insts().end();

    while (token()!=EKWBlockEnd) {
        switch(token()) {
        case EKWBlockStr: {
            BlockString str = section->append<BlockString>(tokenSourceInfo());
            scan();
            str.string() = parseStringLiteral(m_scanner);
        } break;
        case EKWBlockNum: {
            BlockNumeric num = section->append<BlockNumeric>(tokenSourceInfo());

            m_scanner.scanModifier();
            SourceInfo const typeSI = tokenSourceInfo();
            expect(EMType);
            num.type() = m_scanner.brigId();

            switch(num.type()) 
            {
            case Brig::BRIG_TYPE_ROIMG:
            case Brig::BRIG_TYPE_RWIMG:
            case Brig::BRIG_TYPE_SAMP:
                // this is to avoid parsing values (see below) as opaque types
                syntaxError("invalid blocknumeric type");
            }

            m_scanner.scanModifier();
            expect(EMNone);
            scan();

            ArbitraryData values;
            num.elementCount() = parseValueList(num.type(), values);
            num.data() = values.toSRef();
        } break;
        default:
            syntaxError("unexpected token inside block");
        }
        eatToken(ESemi);
    }

    section->append<BlockEnd>(tokenSourceInfo());
    scan();
    eatToken(ESemi);
}

// Instruction parsing

Inst Parser::parseInst()
{
    PDBG;
    Inst res;
    switch(token()) {
    case EInstruction: {
            SourceInfo const srcInfo = tokenSourceInfo();
            res = parseMnemo(m_scanner, m_bw);
            res.annotate(srcInfo);
            {
                scan();
                if (res.kind()!=Brig::BRIG_INST_NONE) {
                    OperandParser const parser = getOperandParser(res.opcode());
                    assert(parser);
                    (this->*parser)(res);
                }
                eatToken(ESemi);
            }

        } break;
    case EInstruction_Vx: {
            Brig::BrigOpcode16_t const opCode = m_scanner.brigId();
            switch(opCode) {
            case Brig::BRIG_OPCODE_LD:
            case Brig::BRIG_OPCODE_ST: 
            case Brig::BRIG_OPCODE_GCNLD:
            case Brig::BRIG_OPCODE_GCNST: 
                res = parseInstLdSt(); 
            break;

            case Brig::BRIG_OPCODE_COMBINE:
                res = parseInstCombineExpand(1); 
            break;

            case Brig::BRIG_OPCODE_EXPAND: 
                res = parseInstCombineExpand(0); 
            break;

            default: assert(false);
            };
        } break;
    default:;
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

    switch (vx) {
    case 1: if (isa<OperandRegVector>(o)) syntaxError("Unexpected vector operand",srcInfo); break;
    case 2: if (!isa<OperandRegVector>(o) || OperandRegVector(o).regCount() != 2) syntaxError("Expected a 2-element vector operand",srcInfo); break;
    case 3: if (!isa<OperandRegVector>(o) || OperandRegVector(o).regCount() != 3) syntaxError("Expected a 3-element vector operand",srcInfo); break;
    case 4: if (!isa<OperandRegVector>(o) || OperandRegVector(o).regCount() != 4) syntaxError("Expected a 4-element vector operand",srcInfo); break;
    default: assert(false); break;
    } 
}

Inst Parser::parseInstLdSt()
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    int vector=1;
    Inst inst = parseMnemoMem(m_scanner,m_bw,&vector);
    inst.annotate(srcInfo);

    scan();

    parseOperands(inst);
    eatToken(ESemi);

    // check whether modifier v2/v3/v4 corresponds to 1st operand
    checkVxIsValid(vector,inst.operand(0));

    return inst;
}

Inst Parser::parseInstCombineExpand(unsigned operandIdx)
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    int vector=1;
    Inst inst = parseMnemoSourceType(m_scanner,m_bw,&vector);
    inst.annotate(srcInfo);

    scan();

    parseOperands(inst);
    eatToken(ESemi);

    if (vector != 2 && vector != 4) syntaxError("Expected v2 or v4 modifier",&srcInfo);

    // check whether modifier v2/v3/v4 corresponds to 1st operand
    checkVxIsValid(vector,inst.operand(operandIdx));

    return inst;
}

Inst Parser::parseInstImage()
{
    assert(false); // TBD095 - parseInstImage check Vx
    PDBG;
    /*SourceInfo const srcInfo = tokenSourceInfo();
    int vector = 1;
    Inst inst = parseMnemoInstImageVx(m_scanner,m_bw,&vector);
    inst.annotate(srcInfo);

    scan();

    parseOperandGeneric(inst, 0); // TBD use vector?
    eatToken(EComma);
    inst.operand(1) = parseObjectOperand();
    tryEatToken(EComma);
    parseOperandGeneric(inst, 2);

    eatToken(ESemi);

    checkVxIsValid(vector,inst.operand(0));
    return inst;*/
    return Inst();
}

// Operand parsing

inline static bool isIntegerConstant(ETokens t) {
    return (t==EDecimalNumber || t==EOctalNumber || t==EHexNumber);
}

void Parser::parseOperands(Inst inst)
{
    PDBG;
    if (token()==ESemi) {
        return;
    }
    int i=getOperandsNum(inst);
    if (i==5) return;
    do {     
        parseOperandGeneric(inst,i++);
    } while(tryEatToken(EComma) && i < 5);
}

void Parser::parseLdcOperands(Inst inst)
{
    PDBG;
    parseOperandGeneric(inst, 0);
    eatToken(EComma);

    if (token()==EIDStatic) { // this should be a function ref
        // TBD are you sure only functions are allowed here?
        m_bw.setOperand(inst,1,parseFunctionRef());
    } else {
        expect(ELabel);
        m_bw.setOperand(inst,1,parseLabelOperand());
    }
}

Operand Parser::parseActualParamList()
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    eatToken(ELParen);

	OperandArgumentList list = m_bw.createArgList(&srcInfo);

	while(!tryEatToken(ERParen)) {
        if (token() != EIDLocal) {
            syntaxError("unexpected argument");
        }
        SourceInfo const srcInfo = tokenSourceInfo();
        SRef const argName = m_scanner.readStringValue(); 

        DirectiveVariable arg = m_bw.findInScopes<DirectiveVariable>(argName);
		if (!arg) {
			syntaxError("Symbol not found", &srcInfo);
		}
		list.elements().push_back(arg);

        tryEatToken(EComma);
    }
	return list;
}

void Parser::parseCallOperands(Inst inst)
{
    PDBG;
    Operand target;
    bool isIndirectCall = false;
    switch(token()) {
    case ERegister:
        isIndirectCall = true;
        target = parseOperandReg();
        break;
    case EIDStatic:
        target = parseFunctionRef();
        break;
    default: syntaxError("invalid call target");
    }

    m_bw.setOperand(inst,1,target);

    Operand outArgs;
    Operand inArgs;

    if (token()==ELParen) {
        outArgs = parseActualParamList();
        if (token()==ELParen) {
           inArgs = parseActualParamList();
        } else { // If there is only one argument list - it is input argument list
            inArgs = outArgs;
            outArgs = m_bw.createArgList();
        }
    } else { // No arguments specified
        syntaxError("missing call argument list");
    }

    m_bw.setOperand(inst,0,outArgs);
    m_bw.setOperand(inst,2,inArgs);

    if (isIndirectCall && token()!=ESemi) {
        SourceInfo const srcInfo = tokenSourceInfo();
        if (tryEatToken(ELBrace)) {
            OperandFunctionList list = m_bw.createFuncList(&srcInfo);
            do {
                SRef const fnName = m_scanner.readStringValue();
                DirectiveFunction func = m_bw.findInScopes<DirectiveFunction>(fnName);
                if (!func) {
                    syntaxError("function not found");
                }
                if (!list.elements().push_back(func)) {
                    syntaxError("OperandFunctionList overflow");
                }
            } while (tryEatToken(EComma));
            eatToken(ERBrace);
            m_bw.setOperand(inst,3,list);
        } else {
            m_bw.setOperand(inst,3,parseSigRef());
        }
    }
}

/*
void Parser::parseRdImageOperands(Inst inst)
{
    PDBG;
    parseOperandGeneric(inst, 0);
    eatToken(EComma);
    inst.operand(1) = parseObjectOperand();
    tryEatToken(EComma);
    inst.operand(2) = parseObjectOperand();
    tryEatToken(EComma);
    parseOperandGeneric(inst, 3);
}

void Parser::parseAtomicNoRetImageOperands(Inst inst)
{
    PDBG;
    inst.operand(0) = parseObjectOperand();
    tryEatToken(EComma);
    parseOperands(inst);
}

void Parser::parseAtomicImageOperands(Inst inst)
{
    PDBG;
    parseOperandGeneric(inst,0);
    eatToken(EComma);
    inst.operand(1) = parseObjectOperand();
    tryEatToken(EComma);
    parseOperands(inst);
}

void Parser::parseQueryOperands(Inst inst)
{
    PDBG;
    parseOperandGeneric(inst,0);
    eatToken(EComma);
    inst.operand(1) = parseObjectOperand();
}
*/

void Parser::parseNoOperands(Inst )
{
}


void Parser::parseOperandGeneric(Inst inst, unsigned opndIdx)
{
    unsigned const reqType = getImmOperandType(inst, opndIdx, m_bw.getMachineType());
    m_bw.setOperand(inst,opndIdx,parseOperandGeneric(reqType));
}

Operand Parser::parseOperandGeneric(unsigned requiredType)
{
    PDBG;
    Operand res;
    switch (token()) {
    case ELBrace:
        res = parseOperandInBraces();
        break;

    case ELParen: // see mov instruction
        res = parseOperandRegVector();
        break;

    case EPlus:
    case EMinus:
    case EDecimalNumber:
    case EOctalNumber:
    case EHexNumber:    
    case EHlfHexNumber:
    case ESglHexNumber:
    case EDblHexNumber:  
    case EHlfNumber:
    case ESglNumber:   
    case EDblNumber:
    case EHlfC99Number:
    case ESglC99Number:
    case EDblC99Number:

    case EPackedLiteral:
        res = parseConstantGeneric(requiredType);
        break;

    case EWaveSizeMacro:
        {
            SourceInfo const srcInfo = tokenSourceInfo();
            res = m_bw.createWaveSz(requiredType,&srcInfo);
        }
        scan();
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
        syntaxError("unexpected operand");
    }
    return res;
}

OperandRef Parser::parseOperandRef()
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    assert(token()==EIDLocal || token()==EIDStatic);
    SRef const name = m_scanner.readStringValue();
    return m_bw.createDirectiveRef(name,&srcInfo);
}

OperandReg Parser::parseOperandReg()
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    SRef const name = m_scanner.readStringValue();

    return m_bw.createOperandReg(name,&srcInfo);
}

Operand Parser::parseOperandRegVector()
{
    SourceInfo const srcInfo = tokenSourceInfo();
    eatToken(ELParen);

    std::string reg[4];
    unsigned int i = 0;
    do {
        reg[i++] =  m_scanner.readStringValue();
    } while ( i < sizeof reg/sizeof reg[0] && tryEatToken(EComma) );

    Operand res = m_bw.createOperandRegVec(reg,i,&srcInfo);
    eatToken(ERParen);
    return res;
}

OperandFunctionRef Parser::parseFunctionRef()
{
    expect(EIDStatic);
    SourceInfo const srcInfo = tokenSourceInfo();
    SRef const fnName = m_scanner.readStringValue();
    return m_bw.createFuncRef(fnName,&srcInfo);
}

Operand Parser::parseSigRef()
{
    expect(EIDStatic);
    SourceInfo const srcInfo = tokenSourceInfo();
    SRef const sigName = m_scanner.readStringValue();
    return m_bw.createSigRef(sigName,&srcInfo);
}

Operand Parser::parseLabelOperand()
{
    expect(ELabel);
    SourceInfo const srcInfo = tokenSourceInfo();
    SRef const labelName = m_scanner.readStringValue();

    return m_bw.createLabelRef(labelName,&srcInfo);
}

class ReadAndSetImmediate 
{
    Scanner&     m_scanner;
    OperandImmed m_operand;
    ReadAndSetImmediate& operator=(const ReadAndSetImmediate&);
public:
    ReadAndSetImmediate(Scanner& scanner, OperandImmed operand) : m_operand(operand), m_scanner(scanner) {}      
    template <typename ReqBrigType> void visit() { 
        setImmed(m_operand,readValueIncludingPacked<ReqBrigType,ConvertImmediate>(m_scanner));
    }
    void visitNone(unsigned) const { 
        m_scanner.syntaxError("unexpected type"); 
    }
};

Operand Parser::parseConstantGeneric(unsigned requiredType)
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    OperandImmed operand = m_bw.createImmed(&srcInfo);
    ReadAndSetImmediate readAndSetImmediate(m_scanner,operand);
    dispatchByType(requiredType,readAndSetImmediate);
    return operand;
}

void Parser::parseAddress(SRef& reg, int64_t& offset)
{
    if (token()==ERegister) {
        reg = m_scanner.readStringValue();
        if (token()==EPlus || token()==EMinus) {
            ETokens const signTok = token();
            scan();
            uint64_t value = readInt<Brig::BRIG_TYPE_U64>(m_scanner);
            if (signTok==EMinus) {
                offset = -(int64_t)value;
            } else {
                offset = (int64_t)value;
            }
        } else {
            offset = 0;
        }
    } else if (isIntegerConstant(token())) {
        reg = SRef();
        offset = readInt<Brig::BRIG_TYPE_S64>(m_scanner);
    } else {
        syntaxError("Register or offset expected");
    }
}

Operand Parser::parseObjectOperand()
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    eatToken(ELBrace);
    if (token()!=EIDStatic && token()!=EIDLocal) {
        syntaxError("symbol expected");
    }

    SRef const objName = m_scanner.readStringValue();
    SRef reg;
    int64_t offset = 0;
    if (tryEatToken(ELAngle)) {
        parseAddress(reg, offset);
        eatToken(ERAngle);
    }
	eatToken(ERBrace);
	return m_bw.createRef(objName,reg,offset,&srcInfo);
}

Operand Parser::parseOperandInBraces()
{
    PDBG;
    SourceInfo const srcInfo = tokenSourceInfo();
    eatToken(ELBrace);

    if (token()==ERBrace) syntaxError("Invalid operand"); // This is to avoid incorrect diagnostics

    if (token()==ELabel) {
        Operand res = parseLabelOperand();
        eatToken(ERBrace);
        return res;
    }

    SRef      name,reg;
    int64_t   offset = 0;
    if (token()==EIDStatic || token()==EIDLocal) {
        name= m_scanner.readStringValue();
        eatToken(ERBrace);
        if (tryEatToken(ELBrace)) {
            parseAddress(reg, offset);
            eatToken(ERBrace);
        }
    } else {
        parseAddress(reg, offset);
        eatToken(ERBrace);
    }
    return m_bw.createRef(name, reg, offset, &srcInfo);
}



// Stubs


void Parser::parsePragma()
{
    PDBG;
    assert(token() == EKWPragma);
    SourceInfo const srcInfo = tokenSourceInfo();
    scan();
    std::string const name = parseStringLiteral(m_scanner);
    eatToken(ESemi);

    DirectivePragma pgm = m_bw.createCodeRefDir<DirectivePragma>(&srcInfo);
    pgm.name() = name;   
}

void Parser::parseDebug()
{
    PDBG;
    assert(token() == EKWSection);
    scan();
    eatToken(ESemi);
}

void Parser::parseExtension()
{
    PDBG;
    assert(token() == EKWExtension);
    SourceInfo const srcInfo = tokenSourceInfo();
    scan();
    std::string const name = parseStringLiteral(m_scanner);
    eatToken(ESemi);

    DirectiveExtension dir = m_bw.createCodeRefDir<DirectiveExtension>(&srcInfo);
    dir.name() = name;

    if (name=="amd:gcn") {
        m_gcnEnabled = true;
    }
}

void Parser::parseLocation()
{
    PDBG;
    assert(token() == EKWLoc);
    SourceInfo const srcInfo = tokenSourceInfo();
    scan();
    unsigned const sourceFile = readPositiveInt<Brig::BRIG_TYPE_U32>(m_scanner);
    unsigned const sourceLine = readPositiveInt<Brig::BRIG_TYPE_U32>(m_scanner);
    Optional<unsigned> sourceColumn, options;
    if (isIntegerConstant(token())) {
        sourceColumn = readPositiveInt<Brig::BRIG_TYPE_U32>(m_scanner);
        if (isIntegerConstant(token())) {
            options = readPositiveInt<Brig::BRIG_TYPE_U32>(m_scanner);
        }
    }  
    eatToken(ESemi);

    DirectiveLoc loc = m_bw.createCodeRefDir<DirectiveLoc>(&srcInfo);
    loc.fileid() = sourceFile;
    loc.line() = sourceLine;
    if (sourceColumn.isInitialized()) {
        loc.column() = sourceColumn;
    }
    if (options.isInitialized()) {
        if (options!=0) {
            syntaxError("only 0 is currently supported for options");
        }
    }
}

void Parser::parseFileDecl()
{
    PDBG;
    assert(token() == EKWFile);
    DirectiveFile file = m_bw.container().append<DirectiveFile>(tokenSourceInfo());
    file.code() = m_bw.container().insts().end();
    scan();
    file.fileid() = readPositiveInt<Brig::BRIG_TYPE_U32>(m_scanner);
    file.filename() = parseStringLiteral(m_scanner);
    eatToken(ESemi);
}

void Parser::parseControl()
{
    PDBG;
    assert(token() == EControl);
    DirectiveControl ctrl = m_bw.container().append<DirectiveControl>(tokenSourceInfo());
    ctrl.code() = m_bw.container().insts().end();
    scan();
    ctrl.control() = m_scanner.brigId();
    ctrl.type() = Brig::BRIG_TYPE_U32; // Should actually be NONE for directives wo args

    ControlValues values = ctrl.values();
    if (token() != ESemi) do { // arguments are optional
        
        // dp: added WAVESIZE support + disabled negative int values

        Operand res;
        SourceInfo const srcInfo = tokenSourceInfo();
        if (token() == EWaveSizeMacro) {
            res = m_bw.createWaveSz(Brig::BRIG_TYPE_U32,&srcInfo);
            scan();
        } else {
            res = m_bw.createImmed(&srcInfo);
            uint32_t val = readNonNegativeInt<Brig::BRIG_TYPE_U32>(m_scanner);
            setImmed(res, val, Brig::BRIG_TYPE_U32);
        }
        values.push_back( res ); 

//      values.push_back( parseConstantGeneric(Brig::BRIG_TYPE_U32) ); // dp
    } while (tryEatToken(EComma));
    eatToken(ESemi);
}

// ----------------------------------------------------------------------------
// Helper code

static std::string parseStringLiteral(Scanner& scanner) {
    std::string ret;
    do {
        scanner.expect(EQuot);
        scanner.readSingleStringLiteral(&ret);
        scanner.scan();
    } while(scanner.token() == EQuot);
    return ret;
}

// Check if expected and actual types of immediate value are compatible.
// Note that actual = b64 for any integer literal.
/*
void Parser::validateImmType(unsigned expected, unsigned actual)
{
    if ((isIntType(expected) && actual == Brig::BRIG_TYPE_B64)
    ||  (isIntType(expected) && actual == Brig::BRIG_TYPE_B32)
    ||  (expected == Brig::BRIG_TYPE_B64 && actual == Brig::BRIG_TYPE_F64)
    ||  (expected == Brig::BRIG_TYPE_B32 && actual == Brig::BRIG_TYPE_F32)
    ||  (isFloatType(expected) && isFloatType(actual))
    ||  (isIntPackedType(expected) && (actual == Brig::BRIG_TYPE_B64 || expected == actual))
    ||  (isFloatPackedType(expected) && expected == actual)) return;

    // There is no information if operand may be an immediate, 
    // so error message must be generic
    syntaxError("Invalid operand type");
}
*/


#include "generated/HSAILParserUtilities_gen.hpp"

} // end namespace
