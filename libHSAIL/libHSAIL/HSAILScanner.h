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
#pragma once
#ifndef INCLUDED_HSAIL_SCANNER_H
#define INCLUDED_HSAIL_SCANNER_H

/*
struct Guard {
    const char **m_beg;
    const char **m_pos;
    Guard(const char **beg, const char **pos)
    : m_beg(beg), m_pos(pos) { }
    ~Guard() {
            std::cout << "\"";
            for(const char *p = *m_beg; p != *m_pos; ++p) {
                    std::cout << *p;
            }
            std::cout << "\" ";
    }
};
*/


#include "Brig.h"
#include "HSAILItems.h"
#include "HSAILTypeUtilities.h"
#include "HSAILUtilities.h"
#include "HSAILSRef.h"
#include "HSAILFloats.h"
#include "HSAILExtManager.h"

#include <memory>
#include <vector>
#include <string>
#include <list>
#include <iosfwd>
#include <cassert>

struct SrcLoc
{
    int line;
    int column;
};

void printError(std::ostream& os, std::istream& is, const SrcLoc& errLoc, const char* message);

class SyntaxError
{
protected:
    std::string m_errorMessage;
    SrcLoc      m_srcLoc;

public:
    SyntaxError() {
        m_srcLoc.line = 0;
        m_srcLoc.column = 0;
    }
    SyntaxError(const std::string& errorMessage)
        : m_errorMessage(errorMessage)
    {
        m_srcLoc.line = 0;
        m_srcLoc.column = 0;
    }
    SyntaxError(const std::string& errorMessage,const SrcLoc& srcLoc)
        : m_errorMessage(errorMessage)
        , m_srcLoc(srcLoc)
    {
    }
    const std::string& what() const { return m_errorMessage; }
    const SrcLoc& where() const { return m_srcLoc; }
    void print(std::ostream& os, std::istream& is) const {
        printError(os,is,m_srcLoc,m_errorMessage.c_str());
    }
};

class LexError : public SyntaxError
{
public:
    LexError(const std::string& errorMessage,const SrcLoc& srcLoc) : SyntaxError(errorMessage, srcLoc) {}
};

class StreamScannerBase
{
    StreamScannerBase& operator=(const StreamScannerBase&);
public:
    typedef std::vector<char>         BufferContainer;

protected:
    const char *m_end;

    std::istream&   m_is;
    BufferContainer m_buffer;

    void readChars(int n);
    void readBuffer();
    std::streamoff  streamPosAt(const char *i) const;

public:
    StreamScannerBase(std::istream& is);

    HSAIL_ASM::SRef getPlainText() const { return HSAIL_ASM::SRef(m_buffer); }
};

namespace HSAIL_ASM
{

enum ELitKinds
{
    ELitDecimal,
    ELitDecimalWithSuffix,
    ELitHex,
    ELitOctal,
    ELitC99
};

enum ETokens
{
    EEmpty,
    EEndOfSource,

    // delimiters
    EQuot,
    ELCurl,
    ERCurl,
    ELParen,
    ERParen,
    ELBrace,
    ERBrace,
    ELAngle,
    ERAngle,
    EDot,
    EComma,
    ESemi,
    EColon,
    EPlus,
    EMinus,
    EEqual,

    // Keywords
    EKWModule,
    EKWKernel,
    EKWFunction,
    EKWPragma,
    EKWSection,
    EKWRTI,
    EKWLoc,
    EKWConst,
    EKWAlign,
    EKWAlloc,
    EAllocKind,
    EKWExtension,
    ELinkage,
    EKWDecl,
    EKWIndirect,

    EKWImageWidth,
    EKWImageHeight,
    EKWImageDepth,
    EKWImageChannelType,
    EKWImageChannelOrder,
    EKWImageGeometry,
    EKWImageArray,

    ESamplerFirstProp,
    EKWSamplerAddressing = ESamplerFirstProp,
    EKWSamplerCoord,
    EKWSamplerFilter,
    ESamplerLastProp = EKWSamplerFilter,

    ESamplerAddressingMode,
    ESamplerCoord,
    ESamplerFilter,

    EKWBlockStart,
    EKWBlockNum,
    EKWBlockStr,
    EKWBlockEnd,

    EKWWidthAll,

    EKWSignature,
    EKWFbarrier,
    EKWImage,
    EKWSampler,

    // constants

    EIntLiteral,
    EF16Literal,
    EF32Literal,
    EF64Literal,
    ETypedLiteral,
    EStringLiteral,
    EEmbeddedText,

    // user names
    ELabel,
    EIDStatic,
    EIDLocal,
    ERegister,

    ESegment,

    // other
    ESLComment,
    EMLCommentStart,
    EId,
    EWaveSizeMacro,
    EControl,
    ETargetMachine,
    ETargetProfile,
    ETargetSftz,
    EDefaultRound,
    EImageFormat,
    EImageOrder,
    EImageGeometry,

    // insts
    EInstNoType,
    EInstBase,
    EInstLdSt,
    EInstAtomic,
    EInstCvt,
    EInstCmp,
    EInstLdc,
    EInstAddrSpace,
    EInstBranch,
    EInstBarrierSync,
    EInstCall,
    EInstModAlu,
    EInstReadImage,
    EInstLdStImage,
    EInstQueryImage,

    EExtInstName,
    EExtInstSuff,

    EInstSkip, // TBD remove

    EInstruction,

    // modifiers
    EModifiers,
    EMType = EModifiers,
    EMPacking,
    EMMemoryOrder,
    EMMemoryScope,
    EMAtomicOp,
    EMSegment,
    EMNoNull,
    EMWidth,
    EMAlign,
    EMVector,
    EMEquiv,
    EMRound,
    EMFTZ,
    EMHi,
    EMCompare,
    EMGeom,
    EMFBar,
    EMConst,
    EMImageQuery,
    EMSamplerQuery,
    EMSkip, // TBD remove
    EMNone
};

enum EScanContext {
    EDefaultContext,
    EImageOrderContext,
    EInstModifierContext,
    EInstModifierInstAtomicContext,
    EInstModifierInstQueryContext,
};

class Scanner : public StreamScannerBase
{
public:
    explicit Scanner(std::istream& is, const ExtManager& extMgr = registeredExtensions(), bool disableComments = true);

    class Token {
        friend class Scanner;
        Scanner       *m_scanner;
        std::streamoff m_lineStart;
        int            m_lineNum;
        SRef           m_text;
        int            m_brigId;
        ETokens        m_kind;

    public:
        SRef    text()   const { return m_text; }
        int     brigId() const { return m_brigId; }
        ETokens kind()   const { return m_kind; }
        SrcLoc  srcLoc() const;
    };

    typedef const Token CToken;

    CToken& token() const { return *m_curToken; }

    SrcLoc srcLoc(const CToken& t) const {
      std::streamoff const posOfs = streamPosAt(t.m_text.begin);
      assert(posOfs >= t.m_lineStart);
      SrcLoc const res = { t.m_lineNum, static_cast<int>(posOfs - t.m_lineStart) };
      return res;
    }

    CToken& peek(EScanContext ctx=EDefaultContext);
    CToken& scan(EScanContext ctx=EDefaultContext);

    void readSingleStringLiteral(std::string& outString);

    void syntaxError(const std::string& message, const SrcLoc& srcLoc) const {
        throw SyntaxError(message, srcLoc);
    }

    void syntaxError(const std::string& message, CToken* t) const {
        syntaxError(message, t->srcLoc());
    }

    void syntaxError(const std::string& message) const {
        syntaxError(message, m_curToken ? m_curToken->srcLoc() : SrcLoc());
    }

    void throwTokenExpected(ETokens token, const char* message, const SrcLoc& loc);

    static EScanContext getTokenContext(ETokens token);

    unsigned eatToken(ETokens token, const char* message=NULL) {
        try {
            CToken& t = scan(getTokenContext(token));
            if (t.kind()!=token) {
                throwTokenExpected(token, message, t.srcLoc());
            }
            return t.brigId();
        } catch (const LexError& e) {
            syntaxError(e.what(), e.where());
            return EEmpty;
        } catch (const SyntaxError& e) {
            throwTokenExpected(token, message, e.where());
            return EEmpty;
        }
    }

    Optional<unsigned> tryEatToken(ETokens token) {
        EScanContext const ctx = getTokenContext(token);
        Optional<unsigned> res;
        if (peek(ctx).kind()==token) {
            res = scan(ctx).brigId();
        }
        return res;
    }

    uint64_t readIntLiteral();
    f16_t    readF16Literal();
    f32_t    readF32Literal();
    f64_t    readF64Literal();
    bool     continueMLComment();

    ExtManager& extMgr() { return m_extMgr; }

    static bool isAlpha(char ch);
    static bool isAlphaNum(char ch);

private:
    Scanner& operator=(const Scanner&);

    Token   m_pool[2]; // circular pool - one for current, one for peek
    Token*  m_curToken;
    Token*  m_peekToken;

    int                        m_lineNum;
    std::streamoff             m_lineStart;
    bool                       m_disableComments;

    ExtManager m_extMgr;

    class istringstreamalert;
    class Variant;

    Token&       newToken();
    Token&       scanNext(EScanContext ctx);

    void         readSingleStringLiteral(Token &t, std::string& outString);
    ETokens      scanDefault(EScanContext ctx, Token &t);
    ETokens      scanModifier(EScanContext ctx, Token &t);
    Variant      readValueVariant();
    void         nextLine(const char *atPos);
    void         skipWhitespaces(Token& t);
    const char*  skipOneLinearComment(const char* from, Token& t);
    const char*  skipMultilineComment(const char* from, Token& t);
    void         scanEmbeddedText(Token &t);
//    bool         continueMLComment(Token &t);

    SrcLoc       srcLoc(const char* pos) const;

    void syntaxError(const char* pos, const std::string& message) const {
        syntaxError(message, srcLoc(pos));
    }
};

inline SrcLoc Scanner::Token::srcLoc() const {
    return m_scanner->srcLoc(*this);
}

} // end namespace

#endif // INCLUDED_HSAIL_SCANNER_H
