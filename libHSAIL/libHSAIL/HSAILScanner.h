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
#include "HSAILTypeUtilities.h"
#include "HSAILUtilities.h"
#include "HSAILSRef.h"
#include "HSAILFloats.h"
#include "HSAILConvertors.h"

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

class StreamScannerBase
{
    StreamScannerBase& operator=(const StreamScannerBase&);
public:
    typedef std::vector<char>         BufferContainer;

protected:
    const char *m_tokStart;
    const char *m_curPos;
    const char *m_end;

    std::istream&   m_is;
    //bool            m_eof;
    BufferContainer m_buffer;

    void readChars(int n);
    std::streamoff  streamPosAt(const char *i) const;

public:
    StreamScannerBase(std::istream& is);

    std::streamoff streamPos() const { return streamPosAt(m_tokStart); } // streamoff at start of current token
};

namespace HSAIL_ASM
{

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
    EKWVersion,
    EKWKernel,
    EKWFunction,
    EKWPragma,
    EKWSection,
    EKWRTI,
    EKWLoc,
    EKWConst,
    EKWAlign,
    EKWExtension,
    EKWFile,

    EKWImageWidth,
    EKWImageHeight,
    EKWImageDepth,
    EKWImageFormat,
    EKWImageOrder,

    ESamplerFirstProp,
    EKWSamplerBoundaryU = ESamplerFirstProp,
    EKWSamplerBoundaryV,
    EKWSamplerBoundaryW,
    EKWSamplerCoord,
    EKWSamplerFilter,
    ESamplerLastProp = EKWSamplerFilter,

    ESamplerBoundaryMode,
    ESamplerCoord,
    ESamplerFilter,

    EKWBlockStart,
    EKWBlockNum,
    EKWBlockStr,
    EKWBlockEnd,

    EKWFBar,
    EKWLabelTargets,
    EKWSignature,
    EKWWidthAll,
    EKWFbarrier,

    // constants
    EDecimalNumber,
    EOctalNumber,
    EHexNumber,
    EHlfHexNumber,
    ESglHexNumber,
    EDblHexNumber,
    EHlfNumber,
    ESglNumber,
    EDblNumber,
    EHlfC99Number,
    ESglC99Number,
    EDblC99Number,
    EPackedLiteral,

    // user names
    ELabel,
    EIDStatic,
    EIDLocal,
    ERegister,

    EAttribute,
    ESegment,

    // other
    EId,
    EWaveSizeMacro,
    EControl,
    ETargetMachine,
    ETargetProfile,
    ETargetSftz,

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
    EInstAtomicImage,
    EInstQueryImage,

    EInstSkip, // TBD remove

    EInstruction,
    EInstruction_Vx,

    // modifiers
    EMType,
    EMPacking,
    EMMemoryOrder,
    EMMemoryScope,
    EMAtomicOp,
    EMSegment,
    EMWidth,
    EMVector,
    EMEquiv,
    EMRound,
    EMFTZ,
    EMHi,
    EMCompare,
    EMGeom,
    EMImageModifier,
    EMFBar,
    EMAligned,
    EMMemoryFence,
    EMSkip, // TBD remove
    EMNone
};

class Scanner : public StreamScannerBase
{


public:
    explicit Scanner(std::istream& is,bool disableComments=true);

    ETokens            token()  const { return m_token; }
    int                brigId() const { return m_brigId; }
    SRef               stringValue() const { return SRef(m_tokStart,m_curPos); }

    ETokens                   scan();
    ETokens                   scanTargetOption();
    ETokens                   scanModifier();
    Brig::BrigImageOrder8_t  scanImageOrder();
    Brig::BrigImageFormat8_t scanImageFormat();

    void readSingleStringLiteral(std::string *outString);

    SRef readStringValue() {
        SRef res(m_tokStart,m_curPos);
        scan();
        return res;
    }

    template <typename DstBrigType,
              template<typename, typename> class Convertor>
    typename DstBrigType::CType readIntValue();

    template <typename DstBrigType,
              template<typename, typename> class Convertor>
    typename DstBrigType::CType readValue();

    bool hasComments() const { return !m_comments.empty(); }

    std::string grabComment() {
        if (!hasComments()) {
            return std::string();
        }
        std::string const res = m_comments.front();
        m_comments.pop_front();
        return res;
    }

    SrcLoc srcLoc() const { // SrcLoc at start of current token
        SrcLoc const res = { m_lineNum, static_cast<int>(streamPos() - m_lineStart) };
        return res;
    }

    void syntaxError(const std::string& message, const SrcLoc& srcLoc) const {
        throw SyntaxError(message, srcLoc);
    }

    void syntaxError(const std::string& message) const {
        syntaxError(message, srcLoc());
    }

    void expect(ETokens t, const char* message=NULL) {
        if (token() != t) {
            throwTokenExpected(t, message);
        }
    }

    void eatToken(ETokens token, const char* message=NULL) {
        expect(token, message);
        scan();
    }

    bool tryEatToken(ETokens t) {
        if (token() == t) {
            scan();
            return true;
        }
        return false;
    }

    template <typename Value>
    Value eatModifier(ETokens token, const char *errMsg=NULL) {
        expect(token,errMsg);
        Value const ret = brigId();
        scanModifier();
        return ret;
    }

    unsigned eatModifier(ETokens token, const char *errMsg=NULL) {
        return eatModifier<unsigned>(token,errMsg);
    }

    template <typename Value>
    Optional<Value> tryEatModifier(ETokens expectedModifier)
    {
        Optional<unsigned> res;
        if (token()==expectedModifier) {
            res = brigId();
            scanModifier();
        }
        return res;
    }

    Optional<unsigned> tryEatModifier(ETokens expectedModifier) {
        return tryEatModifier<unsigned>(expectedModifier);
    }

    void throwTokenExpected(ETokens token, const char* message);

private:
    Scanner& operator=(const Scanner&);

    bool        m_disableComments;
    ETokens     m_token;
    int         m_brigId;

    int            m_lineNum;
    std::streamoff m_lineStart;

    void nextLine();

    std::list<std::string> m_comments;

    class istringstreamalert;

    class Variant;
    Variant readValueVariant();

    void newComment(const char *init=NULL) {
        if (!m_disableComments) {
            m_comments.push_back(init ? std::string(init) : std::string());
        }
    }
    void appendComment(const char *begin, const char *end) {
        if (!m_disableComments) {
            assert(!m_comments.empty());
            m_comments.back().append(begin,end);
        }
    }

    void skipWhitespaces();
    void skipOneLinearComment();
    void skipMultilineComment();
};

class Scanner::Variant
{
    union {
        int64_t  m_int64;
        uint64_t m_uint64;
        uint16_t m_f16x;
        uint32_t m_f32x;
        uint64_t m_f64x;
    };
    enum EKind {
        EInvalid,
        EInt64,
        EUInt64,
        EF16,
        EF32,
        EF64
    } m_kind;

public:
    Variant() : m_kind(EInvalid) {}
    explicit Variant(int64_t  i64)  : m_int64(i64), m_kind(EInt64) {}
    explicit Variant(uint64_t u64)  : m_uint64(u64), m_kind(EUInt64) {}
    explicit Variant(f16_t    f16)  : m_f16x(f16.rawBits()), m_kind(EF16) {}
    explicit Variant(f32_t    f32)  : m_f32x(f32.rawBits()), m_kind(EF32) {}
    explicit Variant(f64_t    f64)  : m_f64x(f64.rawBits()), m_kind(EF64) {}

    bool isInteger() const {
        return m_kind == EInt64 || m_kind == EUInt64;
    }

    template <typename DstBrigType,
              template<typename, typename> class Convertor>
    typename DstBrigType::CType convertInt() const {
        switch(m_kind) {
        case EInt64:  return ::HSAIL_ASM::convert<DstBrigType, BrigType<Brig::BRIG_TYPE_S64>, Convertor>(m_int64);
        case EUInt64: return ::HSAIL_ASM::convert<DstBrigType, BrigType<Brig::BRIG_TYPE_U64>, Convertor>(m_uint64);
        default: assert(false);
        }
        return typename DstBrigType::CType();
    }

    template <typename DstBrigType,
              template<typename, typename> class Convertor>
    typename DstBrigType::CType convert() const {
        switch(m_kind) {
        case EInt64:
        case EUInt64: return convertInt<DstBrigType,Convertor>();
        case EF16:    return ::HSAIL_ASM::convert<DstBrigType, BrigType<Brig::BRIG_TYPE_F16>, Convertor>(f16_t::fromRawBits(m_f16x));
        case EF32:    return ::HSAIL_ASM::convert<DstBrigType, BrigType<Brig::BRIG_TYPE_F32>, Convertor>(f32_t::fromRawBits(m_f32x));
        case EF64:    return ::HSAIL_ASM::convert<DstBrigType, BrigType<Brig::BRIG_TYPE_F64>, Convertor>(f64_t::fromRawBits(m_f64x));
        default: assert(false);
        }
        return typename DstBrigType::CType();;
    }
};

template <typename DstBrigType,
          template<typename, typename> class Convertor>
typename DstBrigType::CType Scanner::readIntValue() {
    try {
        Variant const v = readValueVariant();
        if (!v.isInteger()) {
            syntaxError("integer constant expected");
        }
        typename DstBrigType::CType const res = v.convertInt<DstBrigType,Convertor>();
        scan();
        return res;
    } catch (const ConversionError& e) {
        syntaxError(e.what()); // translate it to syntax error
    }
    return typename DstBrigType::CType();
}

// more generic version
template <typename DstBrigType,
          template<typename, typename> class Convertor>
typename DstBrigType::CType Scanner::readValue() {
    try {
        Variant const v = readValueVariant();
        typename DstBrigType::CType const res = v.convert<DstBrigType,Convertor>();
        scan();
        return res;
    } catch (const ConversionError& e) {
        syntaxError(e.what()); // translate it to syntax error
    }
    return typename DstBrigType::CType();
}

} // end namespace

#endif // INCLUDED_HSAIL_SCANNER_H
