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
#ifndef INCLUDED_HSAIL_FLOATS_H
#define INCLUDED_HSAIL_FLOATS_H

#include "HSAILTypeUtilities.h"
#include <string>
#include <stdint.h>

namespace HSAIL_ASM
{

class f16_t
{
public:
    f16_t() : m_value(0) {}
    explicit f16_t(float v)    : m_value(singles2halfp(v)) {}
    explicit f16_t(double v)   : m_value(singles2halfp(static_cast<float>(v))) {}

    explicit f16_t(int8_t v)  : m_value(singles2halfp(static_cast<float>(v))) {}
    explicit f16_t(int16_t v)  : m_value(singles2halfp(static_cast<float>(v))) {}
    explicit f16_t(int32_t v)  : m_value(singles2halfp(static_cast<float>(v))) {}
    explicit f16_t(int64_t v)  : m_value(singles2halfp(static_cast<float>(v))) {}

    explicit f16_t(uint8_t v) : m_value(singles2halfp(static_cast<float>(v))) {}
    explicit f16_t(uint16_t v) : m_value(singles2halfp(static_cast<float>(v))) {}
    explicit f16_t(uint32_t v) : m_value(singles2halfp(static_cast<float>(v))) {}
    explicit f16_t(uint64_t v) : m_value(singles2halfp(static_cast<float>(v))) {}

    operator float()  const { return halfp2singles(m_value); }
    operator double() const { return halfp2singles(m_value); }

    operator int8_t()    const { return static_cast<int8_t>(halfp2singles(m_value)); }
    operator int16_t()   const { return static_cast<int16_t>(halfp2singles(m_value)); }
    operator int32_t()   const { return static_cast<int32_t>(halfp2singles(m_value)); }
    operator int64_t()   const { return static_cast<int64_t>(halfp2singles(m_value)); }

    operator uint8_t()    const { return static_cast<uint8_t>(halfp2singles(m_value)); }
    operator uint16_t()   const { return static_cast<uint16_t>(halfp2singles(m_value)); }
    operator uint32_t()   const { return static_cast<uint32_t>(halfp2singles(m_value)); }
    operator uint64_t()   const { return static_cast<uint64_t>(halfp2singles(m_value)); }

    bool operator==(const f16_t& rv) const { return m_value==rv.m_value; }
    bool operator!=(const f16_t& rv) const { return !(*this==rv); }

    uint16_t rawBits() const { return m_value; }

    static f16_t fromRawBits(uint16_t v) {
        f16_t res;
        res.m_value = v;
        return res;
    }

private:
	uint16_t m_value;

    static uint16_t singles2halfp(float src);
    static float halfp2singles(uint16_t src);
};



template <> struct value_class<f16_t>  : float_class {};

template <typename OS>
inline OS& operator << (OS& os, f16_t v) {
    os << static_cast<float>(v);
    return os;
}

template <typename Float>
std::string toC99str(Float v);

struct SRef;

template <typename Float>
Float readC99(const SRef& s);

template <typename Float> struct IEEE754BasicTraits;

template <> struct IEEE754BasicTraits<f16_t>
{
    typedef uint16_t RawBitsType;
    static const int mntsWidth = 10;
    static const char* suffix;
};

template <> struct IEEE754BasicTraits<float>
{
    typedef uint32_t RawBitsType;
    static const int mntsWidth = 23;
    static const char* suffix;
};

template <> struct IEEE754BasicTraits<double>
{
    typedef uint64_t RawBitsType;
    static const int mntsWidth = 52;
    static const char* suffix;
};

template <typename Float> struct IEEE754Traits : IEEE754BasicTraits<Float>
{
    typedef IEEE754BasicTraits<Float> Base;

    static const int width    = sizeof(typename Base::RawBitsType)*8;
    static const int expWidth = width - Base::mntsWidth - 1;

    static const typename Base::RawBitsType signMask  = (static_cast<typename Base::RawBitsType>(1) << (width-1));
    static const typename Base::RawBitsType mntsMask  = (static_cast<typename Base::RawBitsType>(1) << Base::mntsWidth) - 1;
    static const typename Base::RawBitsType expMask   = ((static_cast<typename Base::RawBitsType>(1) << expWidth) - 1) << Base::mntsWidth;

    static const int expBias = (1 << expWidth)/2 - 1;
    static const int minExp  = -expBias;
    static const int maxExp  = expBias + 1;
};

template <typename Float>
Float makeFloat(typename IEEE754Traits<Float>::RawBitsType sign, int exp, typename IEEE754Traits<Float>::RawBitsType mnts) {
    typedef IEEE754Traits<Float> Traits;

    typename Traits::RawBitsType const res =
        (sign
        | ((static_cast<typename Traits::RawBitsType>(exp+Traits::expBias)) << Traits::mntsWidth) // bias the exponent
        | (mnts & Traits::mntsMask));

    return *reinterpret_cast<const Float*>(&res);
}

} // end namespace

#endif
