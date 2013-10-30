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
    : m_is(is)
{
    m_tokStart = m_curPos = m_end = 0;
}

void StreamScannerBase::readChars(int )
{
    if (!m_buffer.empty()) {
        return;
    }

    m_is.clear();
    m_is.seekg (0, std::ios::end);
    std::streamoff const length = m_is.tellg();
    m_is.seekg (0, std::ios::beg);

    if (length < 0) { return; }

    m_buffer.resize((BufferContainer::size_type)(length+1));
    m_tokStart = m_curPos = m_end = &m_buffer[0];

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
    , m_disableComments(disableComments)
    , m_token(EEmpty)
    , m_lineNum(0)
    , m_lineStart(0)
{
    scan();
}

Scanner::Variant Scanner::readValueVariant()
{
    using namespace std;
    try {
        bool minus = false;
        switch(m_token) {
        case EMinus:
            {
                minus = true;
            } // fall through
        case EPlus:
            {
                scan();
                if (m_token != EDecimalNumber) {
                    syntaxError("decimal constant expected");
                }
            } // fall through
        case EDecimalNumber:
            {
                SRef const litrl(m_tokStart,m_curPos);
                istrstream is(litrl.begin,litrl.length());
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
                istringstreamalert(SRef(m_tokStart+1,m_curPos)) >> oct >> v;
                return Variant(v);
            }
        case EHexNumber:
            {
                uint64_t v;
                istringstreamalert(SRef(m_tokStart+2,m_curPos)) >> hex >> v;
                return Variant(v);
            }
        case EHlfNumber:
            {
                float v;
                istringstreamalert(SRef(m_tokStart,m_curPos)) >> v;
                return Variant(f16_t(f32_t(&v)));
            }
        case ESglNumber:
            {
                float v;
                istringstreamalert(SRef(m_tokStart,m_curPos)) >> v;
                return Variant(&v);
            }
        case EDblNumber:
            {
                double v;
                istringstreamalert(SRef(m_tokStart,m_curPos)) >> v;
                return Variant(f64_t(&v));
            }
        case EHlfHexNumber:
            {
                IEEE754Traits<f16_t>::RawBitsType v;
                istringstreamalert(SRef(m_tokStart+2,m_curPos)) >> hex >> v;
                return Variant(f16_t::fromRawBits(v));
            }
        case ESglHexNumber:
            {
                IEEE754Traits<f32_t>::RawBitsType pad;
                istringstreamalert(SRef(m_tokStart+2,m_curPos)) >> hex >> pad;
                return Variant(f32_t::fromRawBits(pad));
            }
        case EDblHexNumber:
            {
                IEEE754Traits<f64_t>::RawBitsType pad;
                istringstreamalert(SRef(m_tokStart+2,m_curPos)) >> hex >> pad;
                return Variant(f64_t::fromRawBits(pad));
            }
        case EHlfC99Number:
            {
                f16_t const v = readC99<f16_t>(SRef(m_tokStart,m_curPos));
                return Variant(v);
            }
        case ESglC99Number:
            {
                f32_t v = readC99<f32_t>(SRef(m_tokStart,m_curPos));
                return Variant(v);
            }
        case EDblC99Number:
            {
                f64_t const v = readC99<f64_t>(SRef(m_tokStart,m_curPos));
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

void Scanner::throwTokenExpected(ETokens token, const char* message) {
    if (!message) {
        switch(token) {
        case ERParen:     message = "')'"; break;
        case ELParen:     message = "'('"; break;
        case EMSegment:
        case ESegment:    message = "memory segment"; break;
        case EIDStatic:   message = "global identifier"; break;
        case EIDLocal:    message = "local identifier"; break;
        case ELabel:      message = "label"; break;
        case ESemi:       message = "';'"; break;
        case EKWVersion:  message = "'version'"; break;
        case EColon:      message = "':'"; break;
        case ELCurl:      message = "'{'"; break;
        case ERCurl:      message = "'}'"; break;
        case EComma:      message = "','"; break;
        case EEqual:      message = "'='"; break;
        case ELBrace:     message = "'['"; break;
        case ERBrace:     message = "']'"; break;
        case EMAtomicOp:  message = "atomic operation"; break;
        case EMType:      message = "data type"; break;
        case EMPacking:   message = "packing control"; break;
        case EMCompare:   message = "compare modifier"; break;
        case EMGeom:      message = "geometry modifier"; break;
        case EMImageModifier: message = "image modifier"; break;
        case EMVector:    message = "vector size specifier"; break;
        case EMNone:      message = "no more modifiers"; break;
        case EQuot:       message = "\""; break;
        case ESamplerFilter:
                          message = "sampler filter"; break;
        case ERAngle:     message = ">"; break;
        case ESamplerBoundaryMode:
                          message = "sampler boundary mode value"; break;
        case ESamplerCoord:
                          message = "sampler coord value"; break;
        default:  {
            assert(0);
            std::stringstream ss;
            ss << "ETokens(" << token << ")";
            syntaxError(ss.str() + " expected");
                 }
        }
    }
    syntaxError(std::string(message) + " expected");
}




} // end namespace

