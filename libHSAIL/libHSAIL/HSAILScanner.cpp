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
#include "HSAILScanner.h"

#include <cassert>
#include <sstream>
#include <algorithm>
#include <limits>
#include <utility>
#include <strstream>

StreamScannerBase::StreamScannerBase(std::istream& is)
    : m_end(0)
    , m_is(is)
{
    readBuffer();
}

void StreamScannerBase::readChars(int )
{
}

void StreamScannerBase::readBuffer()
{
    m_buffer.clear();
    m_is.clear();
    m_is.seekg (0, std::ios::end);
    std::streamoff const length = m_is.tellg();
    m_is.seekg (0, std::ios::beg);

    if (length < 0) { return; }

    m_buffer.resize((BufferContainer::size_type)(length+1));
    m_end = &m_buffer[0];

    m_is.read(&m_buffer[0],length);
    unsigned n = (unsigned)m_is.gcount();
    m_end += static_cast<ptrdiff_t>(n);
    m_buffer[n] = 0;
}

std::streamoff StreamScannerBase::streamPosAt(const char *from) const
{
    if (m_buffer.empty()) {
        return 0;
    }
    return static_cast<std::streamoff>(from - &m_buffer[0]);
}

void chop(std::string& str)
{
    if (!str.empty()) {
        if (str[str.length() - 1] == '\r') {
            str.resize(str.length() - 1);
    }
    }
}

// too long context string is truncated from the beginning, so 'second' in the resulting pair
// is the srcLoc column in the truncated string
std::pair<std::string,unsigned> getContextString(std::istream& is, const SrcLoc& srcLoc)
{
    using namespace std;
    is.clear();
    is.seekg(0,ios::beg);
    assert(!is.fail());

    for(int lineNum = 0; lineNum < srcLoc.line; ++lineNum) {
        is.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    assert(!is.fail());

    pair<string,unsigned> res;

    int const lineLen = 80;
    if (srcLoc.column < lineLen) {
        res.second = srcLoc.column;
    } else {
        int const pfxLen = lineLen/2;
        is.ignore(srcLoc.column - pfxLen);
        assert(!is.fail());
        res.second = pfxLen;
    }

    char line[lineLen+1];
    is.get(&line[0],sizeof line,'\n');

    res.first = line;
    chop(res.first);
    return res;
}

void printError(std::ostream& os, std::istream& is, const SrcLoc& errLoc, const char* message)
{
    using namespace std;
    pair<string,unsigned> const ctxInfo = getContextString(is,errLoc);
    const std::string& ctxStr = ctxInfo.first;
    unsigned const ctxStrPos = ctxInfo.second;

    // TBD remove extra newline which is to avoid intermixing
    // with any debug printout
    os << endl << "> " << ctxStr << endl;
    os << "> ";
    assert(ctxStrPos <= ctxStr.length());
    for(string::const_iterator i=ctxStr.begin(), e = ctxStr.begin() + ctxStrPos; i<e; ++i) {
        os << ((*i=='\t') ? '\t' : ' ');
    }
    os << '^' << endl;
    os << "input" << '(' << errLoc.line+1 << ',' <<  errLoc.column+1 << "): " << message << endl;
}



namespace HSAIL_ASM
{

class Scanner::istringstreamalert : public std::istrstream {
public:
    istringstreamalert(const SRef& s)
        : std::istrstream(s.begin,s.length()) {
        exceptions(std::ios::failbit | std::ios::badbit);
    }
};

Scanner::Scanner(std::istream& is,bool disableComments)
    : StreamScannerBase(is)
    , m_peekToken(NULL)
    , m_lineNum(0)
    , m_lineStart(0)
    , m_disableComments(disableComments)
{

    m_pool[0].m_scanner = this;
    m_pool[1].m_scanner = this;

    Token &t = m_pool[0];
    t.m_kind = EEmpty;
    t.m_text.begin = t.m_text.end = &m_buffer[0];

    m_curToken = &t;
}

EScanContext Scanner::getTokenContext(ETokens token)
{
    if (token >= EModifiers) {
        switch(token) {
        case EMAtomicOp: return EInstModifierInstAtomicContext;
        case EMImageQuery: return EInstModifierInstQueryContext;
        case EMMemoryScope:
        default: return EInstModifierContext;
        }
    } else {
        switch(token) {
        case EImageOrder: return EImageOrderContext;
        default:;
        }
    }
    return EDefaultContext;
}

Scanner::CToken& Scanner::peek(EScanContext ctx)
{
    // rescan if needed
    if (m_peekToken==NULL || m_peekToken->kind()==EEmpty || getTokenContext(m_peekToken->kind()) != ctx) {
        m_peekToken = &scanNext(ctx);
    }
    return *m_peekToken;
}

Scanner::CToken& Scanner::scan(EScanContext ctx)
{
    if (m_peekToken==NULL) {
        m_curToken = &scanNext(ctx);
    } else {
        peek(ctx); // rescan if needed
        m_curToken  = m_peekToken;
        m_peekToken = NULL;
    }
    return *m_curToken;
}

Scanner::Token& Scanner::newToken() {
    Scanner::Token& t = m_pool[ m_curToken==&m_pool[0] ? 1:0 ];
    return t;
}

void Scanner::readSingleStringLiteral(std::string& outString) {
    Token& t = newToken();
    t.m_lineStart = m_lineStart;
    t.m_lineNum = m_lineNum;
    t.m_text.begin = t.m_text.end = m_curToken->m_text.end;
    readSingleStringLiteral(t, outString);
    t.m_kind = EStringLiteral;
    m_curToken = &t;
}

Scanner::Token& Scanner::scanNext(EScanContext ctx)
{
    const char* const curPos = m_curToken->m_text.end;
    Token& t = newToken();
    t.m_lineStart = m_lineStart;
    t.m_lineNum = m_lineNum;
    t.m_text.begin = t.m_text.end = curPos;

    if (ctx >= EInstModifierContext) {
        t.m_kind = scanModifier(/*in*/ctx, /*in/out*/t);
    } else {
        skipWhitespaces(t);
        t.m_lineStart = m_lineStart;
        t.m_lineNum = m_lineNum;
        t.m_kind = scanDefault(/*in*/ctx, /*in/out*/t);
    }
    return t;
}

void Scanner::nextLine(const char *atPos)
{
    m_lineStart = streamPosAt(atPos);
    ++m_lineNum;
}

SrcLoc Scanner::srcLoc(const char* pos) const {
    std::streamoff const posOfs = streamPosAt(pos);
    assert(posOfs >= m_lineStart);
    SrcLoc const res = { m_lineNum, static_cast<int>(posOfs - m_lineStart) };
    return res;
}

uint64_t Scanner::readIntLiteral()
{
    using namespace std;
    uint64_t v;
    switch(eatToken(EIntLiteral)) {
    case ELitDecimal:
        istringstreamalert(m_curToken->text()) >> dec >> v;        break;
    case ELitOctal:
        istringstreamalert(m_curToken->text().substr(1)) >> oct >> v; break;
    case ELitHex:
        istringstreamalert(m_curToken->text().substr(2)) >> hex >> v; break;
    default:
        assert(0);
    }
    return v;
}

f16_t Scanner::readF16Literal()
{
    using namespace std;
    switch(eatToken(EF16Literal)) {
    case ELitDecimal:
        {
            float v;
            istringstreamalert(m_curToken->text()) >> v;
            return f16_t(f32_t(&v));
        }
    case ELitDecimalWithSuffix:
        {
            float v;
            istringstreamalert(m_curToken->text().rsubstr(1)) >> v;
            return f16_t(f32_t(&v));
        }
    case ELitHex:
        {
            IEEE754Traits<f16_t>::RawBitsType v;
            istringstreamalert(m_curToken->text().substr(2)) >> hex >> v;
            return f16_t::fromRawBits(v);
        }
    case ELitC99:
        {
            return readC99<f16_t>(m_curToken->text());
        }
    default:
        assert(0);
    }
    return f16_t();
}

f32_t Scanner::readF32Literal()
{
    using namespace std;
    switch(eatToken(EF32Literal)) {
    case ELitDecimal:
        {
            float v;
            istringstreamalert(m_curToken->text()) >> v;
            return f32_t(&v);
        }
    case ELitDecimalWithSuffix:
        {
            float v;
            istringstreamalert(m_curToken->text().rsubstr(1)) >> v;
            return f32_t(&v);
        }
    case ELitHex:
        {
            IEEE754Traits<f32_t>::RawBitsType v;
            istringstreamalert(m_curToken->text().substr(2)) >> hex >> v;
            return f32_t::fromRawBits(v);
        }
    case ELitC99:
        {
            return readC99<f32_t>(m_curToken->text());
        }
    default:
        assert(0);
    }
    return f32_t();
}

f64_t Scanner::readF64Literal()
{
    using namespace std;
    switch(eatToken(EF64Literal)) {
    case ELitDecimal:
        {
            double v;
            istringstreamalert(m_curToken->text()) >> v;
            return f64_t(&v);
        }
    case ELitDecimalWithSuffix:
        {
            double v;
            istringstreamalert(m_curToken->text().rsubstr(1)) >> v;
            return f64_t(&v);
        }
    case ELitHex:
        {
            IEEE754Traits<f64_t>::RawBitsType v;
            istringstreamalert(m_curToken->text().substr(2)) >> hex >> v;
            return f64_t::fromRawBits(v);
        }
    case ELitC99:
        {
            return readC99<f64_t>(m_curToken->text());
        }
    default:
        assert(0);
    }
    return f64_t();
}


/*
Scanner::Variant Scanner::readValueVariant()
{
    using namespace std;
    try {
        bool minus = false;
        switch(scan().kind()) {
        case EMinus:
            {
                minus = true;
            } // fall through
        case EPlus:
            {
                eatToken(EDecimalNumber, "decimal constant");
            } // fall through
        case EDecimalNumber:
            {
                SRef const &litrl = m_curToken->text();
                uint64_t ull;
                istringstreamalert(litrl) >> dec >> ull;
                if (minus) {
                    return Variant(-(int64_t)ull);
                } else {
                    return Variant(ull);
                }
            }
        case EOctalNumber:
            {
                uint64_t v;
                istringstreamalert(m_curToken->text().mid(1)) >> oct >> v;
                return Variant(v);
            }
        case EHexNumber:
            {
                uint64_t v;
                istringstreamalert(m_curToken->text().mid(2)) >> hex >> v;
                return Variant(v);
            }
        case EHlfNumber:
            {
                float v;
                istringstreamalert(m_curToken->text()) >> v;
                return Variant(f16_t(f32_t(&v)));
            }
        case EHlfHexNumber:
            {
                IEEE754Traits<f16_t>::RawBitsType v;
                istringstreamalert(m_curToken->text().mid(2)) >> hex >> v;
                return Variant(f16_t::fromRawBits(v));
            }
        case EHlfC99Number:
            {
                f16_t const v = readC99<f16_t>(m_curToken->text());
                return Variant(v);
            }
        case ESglNumber:
            {
                float v;
                istringstreamalert(m_curToken->text()) >> v;
                return Variant(&v);
            }
        case ESglHexNumber:
            {
                IEEE754Traits<f32_t>::RawBitsType pad;
                istringstreamalert(m_curToken->text().mid(2)) >> hex >> pad;
                return Variant(f32_t::fromRawBits(pad));
            }
        case ESglC99Number:
            {
                f32_t v = readC99<f32_t>(m_curToken->text());
                return Variant(v);
            }
        case EDblNumber:
            {
                double v;
                istringstreamalert(m_curToken->text()) >> v;
                return Variant(f64_t(&v));
            }
        case EDblHexNumber:
            {
                IEEE754Traits<f64_t>::RawBitsType pad;
                istringstreamalert(m_curToken->text().mid(2)) >> hex >> pad;
                return Variant(f64_t::fromRawBits(pad));
            }
        case EDblC99Number:
            {
                f64_t const v = readC99<f64_t>(m_curToken->text());
                return Variant(v);
            }
        default:
            syntaxError("constant value literal expected");
        }
    } catch (const istringstream::failure& ) {
        //std::ostringstream ss;
        //ss << "iss failure, token = " << m_token;
        //syntaxError(ss.str());
        syntaxError("invalid literal");
    }
    return Variant();
}
*/

void Scanner::throwTokenExpected(ETokens token, const char* message, const SrcLoc& loc) {
    if (!message) {
        switch(token) {
        case ERParen:         message = "')'"; break;
        case ELParen:         message = "'('"; break;
        case EMSegment:
        case ESegment:        message = "memory segment"; break;
        case EIDStatic:       message = "global identifier"; break;
        case EIDLocal:        message = "local identifier"; break;
        case ELabel:          message = "label"; break;
        case ESemi:           message = "';'"; break;
        case EKWModule:       message = "'module'"; break;
        case EColon:          message = "':'"; break;
        case ELCurl:          message = "'{'"; break;
        case ERCurl:          message = "'}'"; break;
        case EComma:          message = "','"; break;
        case EEqual:          message = "'='"; break;
        case ELBrace:         message = "'['"; break;
        case ERBrace:         message = "']'"; break;
        case EMAtomicOp:      message = "atomic operation"; break;
        case EMType:          message = "data type"; break;
        case EMPacking:       message = "packing control"; break;
        case EMCompare:       message = "compare modifier"; break;
        case EMGeom:          message = "geometry modifier"; break;
        case EMVector:        message = "vector size specifier"; break;
        case EMNone:          message = "no more modifiers"; break;
        case EQuot:           message = "\""; break;
        case ESamplerFilter:  message = "sampler filter"; break;
        case ERAngle:         message = ">"; break;
        case ESamplerCoord:   message = "sampler coord value"; break;
        case EMMemoryOrder:   message = "memory order value"; break;
        case EMMemoryScope:   message = "memory scope value"; break;
        case ETargetMachine:  message = "machine model"; break;
        case ETargetProfile:  message = "target profile"; break;
        case EDefaultRound:   message = "default rounding"; break;
        case ESamplerAddressingMode: message = "sampler addressing mode value"; break;
        case EImageFormat:    message = "image channel type"; break;
        case EImageOrder:     message = "image channel order"; break;
        case EImageGeometry:  message = "image geometry"; break;
        case EKWImage:        message = "image constant"; break;
        case EKWSampler:      message = "sampler constant"; break;
        case EKWFunction:     message = "function"; break;
        case EMImageQuery:    message = "image query"; break;
        case EMSamplerQuery:  message = "sampler query"; break;
        case EIntLiteral:     message = "integer constant"; break;
        case EF16Literal:     message = "f16 constant"; break;
        case EF32Literal:     message = "f32 constant"; break;
        case EF64Literal:     message = "f64 constant"; break;
        case EAllocKind:      message = "allocation kind"; break;
        case EInstruction:    message = "instruction"; break;
        default:  {
            assert(0);
            std::stringstream ss;
            ss << "ETokens(" << token << ")";
            syntaxError(ss.str() + " expected");
                 }
        }
    }
    syntaxError(std::string(message) + " expected", loc);
}




} // end namespace

