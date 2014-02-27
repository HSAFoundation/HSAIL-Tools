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

// The i386 calling convention does not preserve 32-bit SNAN constants on
// return. The SYSTEM V ABI for i386 says that float values must be returned in
// %st(0) as 80-bit extended precision doubles. On x86 architectures converting
// a SNAN from floating point type to another replaces the SNAN with the
// corresponding QNAN. For example the float 0fff800001 will be transformed into
// 0fffc00001. To avoid loss of information, we wrap all floats in a
// structure. The i386 calling convention says that structures will be returned
// in memory regardless of their contents. The wrapping has no performance
// impact on x86-64, since the structure will be returned in the xmm0 register
// exactly as though it were a naked float.
//
// Here is a simple hsail program demonstrating the problem:
//
// version 0:96:$full:$small;
// global_f32 &n = 0fff800001;
// kernel &__OpenCL_Global_Initializer_kernel(
//         kernarg_u32 %r)
// {
// @__OpenCL_Global_Initializer_kernel_entry:
//         ld_kernarg_u32 $s2, [%r];
//         ld_global_u32  $s1, [&n];
//         st_global_u32  $s1, [$s2];
//         ret;
// };
// 
// 64-bit SNAN constants are not preserved by fld and fstp.
// So struct f64_t and its union comparable type f64u_t are used
// to work around this to copy double vars as uint64_t
// Hsail example for 64-bit SNAN
// version 0:96:$full:$small;
// global_f64 &n = 0d7ff7000000000000;
// kernel &__OpenCL_Global_Initializer_kernel(
//         kernarg_u32 %r)
// {
// @__OpenCL_Global_Initializer_kernel_entry:
//         ld_kernarg_u32 $s2, [%r];
//         ld_global_u64  $d1, [&n];
//         st_global_u64  $d1, [$s2];
//         ret;
// };


template<typename T> struct FloatBits;

class f32_t 
{
public:
    f32_t() : m_uint32(0) {}
    f32_t(const float* rhs) : m_uint32(*reinterpret_cast<const uint32_t*>(rhs)) {}
    bool operator==(const f32_t& rv) const { return m_uint32 == rv.m_uint32; }
    bool operator!=(const f32_t& rv) const { return !(*this==rv); }
    uint32_t rawBits() { return m_uint32; }
    static f32_t fromRawBits(uint32_t bits) { 
      f32_t res;
      res.m_uint32 = bits;
      return res;
    }

    float floatValue() const { return m_value; }

private:
    // Although the m_uin32_t field is never used, it is necessary
    // prevent the copy constructor from using the fld and fst. The
    // gcc 4.1 compiler that ships with CentOS 5 tries to use the fld
    // and fst instructions in the copy constructor on x86-64. These
    // instructions silently replace SNANs with the corresponding
    // QNAN. The union forces the compiler to do a bitwise copy,
    // avoiding the problematic instructions.
    union {
      float m_value;
      uint32_t m_uint32;
    };
};

class f64_t 
{
public:
    f64_t() : m_uint64(0) {}
    f64_t(const double* rhs) : m_uint64(*reinterpret_cast<const uint64_t*>(rhs)) { }
    bool operator==(const f64_t& rv) const { return m_uint64==rv.m_uint64; }
    bool operator!=(const f64_t& rv) const { return !(*this==rv); }
    uint64_t rawBits() { return m_uint64; }
    static f64_t fromRawBits(uint64_t bits) { 
      f64_t res;
      res.m_uint64 = bits;
      return res;
    }

    double floatValue() const { return m_value; }

private:
    union {
      double m_value;
      uint64_t m_uint64;
    };
};

class f16_t
{
public:
    f16_t() : m_value(0) {}
    explicit f16_t(f32_t v)    : m_value(singles2halfp(v)) {}
    explicit f16_t(const float *v)    : m_value(singles2halfp(f32_t(v))) {}
    f32_t f32() const { return halfp2singles(m_value); }

    bool operator==(const f16_t& rv) const { return m_value==rv.m_value; }
    bool operator!=(const f16_t& rv) const { return !(*this==rv); }

    uint16_t rawBits() const { return m_value; }

    static f16_t fromRawBits(uint16_t v) {
        f16_t res;
        res.m_value = v;
        return res;
    }

    float floatValue() const { return f32().floatValue(); }

private:
    uint16_t m_value;

    static uint16_t singles2halfp(f32_t src);
    static f32_t halfp2singles(uint16_t src);
};

template <> struct value_class<f16_t>  : float_class {};

template <typename Float>
std::string toC99str(Float v);

struct SRef;

template <typename Float>
Float readC99(const SRef& s);

template <typename Float> struct IEEE754BasicTraits;

template <> struct IEEE754BasicTraits<f16_t>
{
    typedef uint16_t RawBitsType;
    typedef float NativeType;
    static const int mntsWidth = 10;
    static const char* suffix;
    static const char* hexPrefix;
};

template <> struct IEEE754BasicTraits<f32_t>
{
    typedef uint32_t RawBitsType;
    typedef float NativeType;
    static const int mntsWidth = 23;
    static const char* suffix;
    static const char* hexPrefix;
};

template <> struct IEEE754BasicTraits<f64_t>
{
    typedef uint64_t RawBitsType;
    typedef double NativeType;
    static const int mntsWidth = 52;
    static const char* suffix;
    static const char* hexPrefix;
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

    return Float::fromRawBits(
        (sign
        | ((static_cast<typename Traits::RawBitsType>(exp+Traits::expBias)) << Traits::mntsWidth) // bias the exponent
        | (mnts & Traits::mntsMask)));
}

} // end namespace

#endif
