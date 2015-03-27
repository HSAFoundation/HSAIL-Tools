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
#ifndef INCLUDED_HSAIL_b128_t_H
#define INCLUDED_HSAIL_b128_t_H

#include "HSAILTypeUtilities.h"
#include <iosfwd>
#include <stdint.h>

namespace HSAIL_ASM
{

class b128_t
{
    uint64_t m_value[2];

    template <typename UnsT>
    void uset(UnsT v ) {
        m_value[0] = v;
        m_value[1] = 0;
    }

    template <typename SignT>
    void sset(SignT v) {
        m_value[0] = static_cast<int64_t>(v);
        m_value[1] = v < 0 ? -1LL : 0;
    }

public:

    b128_t() {
        m_value[0] = 0;
        m_value[1] = 0;
    }

    b128_t(uint64_t lowPart, uint64_t highPart) {
        m_value[0] = lowPart;
        m_value[1] = highPart;
    }

    explicit b128_t(uint64_t (&v)[2]) {
        m_value[0] = v[0];
        m_value[1] = v[1];
    }

    explicit b128_t(uint8_t  v) { uset(v); }
    explicit b128_t(uint16_t v) { uset(v); }
    explicit b128_t(uint32_t v) { uset(v); }
    explicit b128_t(uint64_t v) { uset(v); }
    explicit b128_t(int8_t   v) { sset(v); }
    explicit b128_t(int16_t  v) { sset(v); }
    explicit b128_t(int32_t  v) { sset(v); }
    explicit b128_t(int64_t  v) { sset(v); }

    void operator=(uint8_t  v) { uset(v); }
    void operator=(uint16_t v) { uset(v); }
    void operator=(uint32_t v) { uset(v); }
    void operator=(uint64_t v) { uset(v); }
    void operator=(int8_t   v) { sset(v); }
    void operator=(int16_t  v) { sset(v); }
    void operator=(int32_t  v) { sset(v); }
    void operator=(int64_t  v) { sset(v); }

    friend uint64_t lowPart(const b128_t& v);
    friend uint64_t hiPart(const b128_t& v);

    operator uint8_t()  const { return static_cast<uint8_t>(m_value[0]); }
    operator uint16_t() const { return static_cast<uint16_t>(m_value[0]); }
    operator uint32_t() const { return static_cast<uint32_t>(m_value[0]); }
    operator uint64_t() const { return static_cast<uint64_t>(m_value[0]); }
};

template <> struct value_class<b128_t>  : unsigned_int_class {};

inline uint64_t lowPart(const b128_t& v) { return v.m_value[0]; }
inline uint64_t hiPart(const b128_t& v)  { return v.m_value[1]; }

template <typename OS>
inline OS& operator << (OS& os,const b128_t& v) {
    os << hiPart(v);
    os << lowPart(v);
    return os;
}

}

#endif