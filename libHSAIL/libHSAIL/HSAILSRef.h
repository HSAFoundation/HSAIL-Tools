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
#ifndef _INCLUDED_HSAIL_SREF_H
#define _INCLUDED_HSAIL_SREF_H

#include <string>
#include <cstddef>
#include <cstring>
#include <iosfwd>

namespace HSAIL_ASM {

struct SRef
{
    const char *begin;
    const char *end;
    SRef(const char *begin_, const char *end_) : begin(begin_), end(end_) { }
    template<size_t N>
    SRef(const char (&rhs)[N]) : begin(rhs), end(rhs + N - 1) { }
    SRef() : begin(0), end(0) { }
    SRef(const std::string& rhs) : begin(rhs.data()), end(rhs.data() + rhs.size()) { }
    explicit SRef(const char *begin_) : begin(begin_), end(begin_ + strlen(begin_)) { }
    bool empty() const { return begin == end; }
    ptrdiff_t length() const { return end - begin; }
    static int compare(const SRef& lhs, const SRef& rhs) {
        ptrdiff_t lhsLen = lhs.end-lhs.begin;
        ptrdiff_t rhsLen = rhs.end-rhs.begin;
        int rc = memcmp(lhs.begin, rhs.begin, (std::min)(lhsLen, rhsLen));
        if (rc) return rc;
        return (int)(lhsLen-rhsLen);
    }
    static int compare(const char* lhs, const SRef& rhs) {
        ptrdiff_t rhsLen = rhs.end-rhs.begin;
        int rc = strncmp(lhs, rhs.begin, rhsLen);
        if (rc) return rc;
        return lhs[rhsLen] == 0 ? 0 : 1;
    }
    operator std::string() const { return std::string(begin,end); }
};

inline bool operator>(const SRef& lhs, const SRef& rhs)  { return SRef::compare(lhs, rhs) > 0; }
inline bool operator>=(const SRef& lhs, const SRef& rhs) { return SRef::compare(lhs, rhs) >= 0; }
inline bool operator<=(const SRef& lhs, const SRef& rhs) { return SRef::compare(lhs, rhs) <= 0; }
inline bool operator<(const SRef& lhs, const SRef& rhs)  { return SRef::compare(lhs, rhs) < 0; }
inline bool operator==(const SRef& lhs, const SRef& rhs) { return SRef::compare(lhs, rhs) == 0; }
inline bool operator!=(const SRef& lhs, const SRef& rhs) { return SRef::compare(lhs, rhs) != 0; }

inline bool operator>(const char* lhs, const SRef& rhs)  { return SRef::compare(lhs, rhs) > 0; }
inline bool operator>=(const char* lhs, const SRef& rhs) { return SRef::compare(lhs, rhs) >= 0; }
inline bool operator<=(const char* lhs, const SRef& rhs) { return SRef::compare(lhs, rhs) <= 0; }
inline bool operator<(const char* lhs, const SRef& rhs)  { return SRef::compare(lhs, rhs) < 0; }
inline bool operator==(const char* lhs, const SRef& rhs) { return SRef::compare(lhs, rhs) == 0; }
inline bool operator!=(const char* lhs, const SRef& rhs) { return SRef::compare(lhs, rhs) != 0; }

inline bool operator>(const SRef& lhs, const char* rhs)  { return SRef::compare(rhs, lhs) < 0; }
inline bool operator>=(const SRef& lhs, const char* rhs) { return SRef::compare(rhs, lhs) <= 0; }
inline bool operator<=(const SRef& lhs, const char* rhs) { return SRef::compare(rhs, lhs) >= 0; }
inline bool operator<(const SRef& lhs, const char* rhs)  { return SRef::compare(rhs, lhs) > 0; }
inline bool operator==(const SRef& lhs, const char* rhs) { return SRef::compare(rhs, lhs) == 0; }
inline bool operator!=(const SRef& lhs, const char* rhs) { return SRef::compare(rhs, lhs) != 0; }

std::ostream& operator<<(std::ostream& os, const SRef& s);

};


#endif
