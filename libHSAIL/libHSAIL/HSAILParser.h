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
#ifndef INCLUDED_HSAIL_PARSER_H
#define INCLUDED_HSAIL_PARSER_H

#include "HSAILScanner.h"
#include "HSAILItems.h"
#include "HSAILBrigantine.h"

#include <stdexcept>
#include <memory>

namespace HSAIL_ASM
{

Inst parseMnemo(const char* str, Brigantine& bw);

struct ModuleStatementPrefix;

class Parser
{
public:
    Parser(Scanner& scanner, BrigContainer& container);

    void parseSource(bool saveSource=false);

private:
    enum ImmKind {
        TYPED_IMM = 1,
        UNTYPED_IMM = 2,
        ANY_IMM = TYPED_IMM | UNTYPED_IMM
    };

private:
    Scanner&    m_scanner;
    Brigantine  m_bw;
    bool        m_gcnEnabled;
    std::string m_srcFileName;

    Parser& operator=(const Parser&);

    Scanner::CToken& scan()  { return m_scanner.scan(); }
    Scanner::CToken& peek()  { return m_scanner.peek(); }
    Scanner::CToken& token() { return m_scanner.token(); }

    unsigned           eatToken(ETokens token, const char* message = 0) { return m_scanner.eatToken(token, message); }
    Optional<unsigned> tryEatToken(ETokens token)                       { return m_scanner.tryEatToken(token); }

    void syntaxError(const std::string& message, const SourceInfo* srcInfo=NULL);
    void syntaxError(const std::string& message, Scanner::CToken& token);

    //void    scan();
    //void    expect(ETokens token, const char* message = 0);
    //void    throwTokenExpected(ETokens token, const char* message);
    //SourceInfo tokenSourceInfo() const;

    void parseProgram();
    void parseModule();
    void parseTopLevelStatement();
    Optional<uint16_t> tryParseFBar();
    //void parseSigArgs(Scanner& s,DirectiveSignatureArguments types, DirectiveSignatureArguments::ArgKind argKind);
    //void parseSignature();
    int  parseCodeBlock(); // returns the number of instructions inside
    int  parseBodyStatement(); // returns the number of instructions inside
    void parseLabel();
    Inst parseInst();

    Operand    parseOpaqueObject();
    void       parseAndUnfoldOpaqueObject(ItemList& list);
    Operand    parseImageProperties(unsigned type);
    Operand    parseSamplerProperties();
    void       parseOpaqueArray(ItemList& list, unsigned expectedType);


    void parseExecutable(ETokens kw, const ModuleStatementPrefix* modPfx);
    DirectiveVariable parseVariable(bool nameRequired = true, const ModuleStatementPrefix* modPfx = 0);
    void parseFbarrier(const ModuleStatementPrefix* modPfx = 0);

    void parseDebug();
    void parsePragma();
    void parseEmbeddedText();
    void parseRTI();
    void parseLocation();
    void parseExtension();
    void parseFileDecl();
    void parseControl();

    typedef ItemList (Parser::*OperandParser)(Inst);
    static OperandParser getOperandParser(Brig::BrigOpcode16_t opcode);

    Inst parseInstLdSt();
    Inst parseInstLane();
    Inst parseInstCombineExpand(unsigned operandIdx);
    Inst parseInstImage();

    int  parseArgScope();

    void skipInst();

    void checkVxIsValid(int Vx, Operand o);

    ItemList parseOperands(Inst inst);
    ItemList parseCallOperands(Inst inst);
    ItemList parseSbrOperands(Inst inst);
    ItemList parseNoOperands(Inst inst);

    Operand parseOperandGeneric(unsigned requiredType);

    Operand parseAggregateOperand();
    Operand parseOperandGeneric(Inst inst, unsigned opndIdx);
    Operand parseConstantGeneric(unsigned requiredType);

    unsigned parseImmediate(ArbitraryData *data, unsigned requiredType, size_t pos, unsigned expectedImmKind = ANY_IMM);
    void validateTypedImmConversion(unsigned requiredType, unsigned actualType);

    OperandCodeRef parseOperandRef();
    OperandRegister parseOperandReg();
    Operand parseOperandVector(unsigned requiredType);

    Operand parseLabelOperand();
    OperandCodeRef parseFunctionRef();
    Operand parseSigRef();

    Operand parseOperandInBraces(unsigned requiredType);
    Operand parseActualParamList();

    void parseAddress(SRef& reg, int64_t& offset);

    void parseSLComment();
    void parseMLComment();
};

inline void Parser::syntaxError(const std::string& message,const SourceInfo* srcInfo) {
    if (srcInfo) {
        SrcLoc const srcLoc = { srcInfo->line, srcInfo->column };
        m_scanner.syntaxError(message,srcLoc);
    } else {
        m_scanner.syntaxError(message);
    }
}

inline SourceInfo sourceInfo(const Scanner::Token& t) {
    SrcLoc const srcLoc = t.srcLoc();
    return SourceInfo(srcLoc.line,srcLoc.column);
}

inline void Parser::syntaxError(const std::string& message, Scanner::CToken& token) {
    SourceInfo const srcInfo = sourceInfo(token);
    syntaxError(message, &srcInfo);
}

} // end namespace

#endif

