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
#include "HSAILFloats.h"
#include "HSAILSRef.h"
#include <strstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cassert>

#include <cmath> // for tests

namespace HSAIL_ASM
{

const char* IEEE754BasicTraits<f16_t>::suffix = "h";
const char* IEEE754BasicTraits<f32_t>::suffix = "f";
const char* IEEE754BasicTraits<double>::suffix = "";

uint16_t f16_t::singles2halfp(f32_t src)
{
    typedef IEEE754Traits<f16_t> F16T;
    typedef IEEE754Traits<f32_t> F32T;

    F32T::RawBitsType const srcBits = *reinterpret_cast<const F32T::RawBitsType*>(&src);
    F16T::RawBitsType const f16signBit = (srcBits & F32T::signMask) >> 16;

    if( (srcBits & ~F32T::signMask) == 0 ) {
        return f16signBit;
    }

    int exp = static_cast<int>((srcBits & F32T::expMask) >> F32T::mntsWidth) - F32T::expBias;
    F32T::RawBitsType mntsBits = srcBits & F32T::mntsMask;

    if ( exp >= F16T::maxExp ) {
        if (exp==F32T::maxExp && mntsBits!=0) {
           return 0xFE00u;
        }
        return (f16signBit | F16T::expMask);
    } else if ( exp <= F16T::minExp ) {
        int const denormShift = F16T::minExp - exp;
        if ( denormShift > F16T::mntsWidth ) {
            return f16signBit;
        }
        exp = F16T::minExp;
        mntsBits = (mntsBits | (1u << F32T::mntsWidth)) >> (denormShift+1);
    }

    F16T::RawBitsType const res = f16signBit
        | (static_cast<F16T::RawBitsType>(exp+F16T::expBias) << F16T::mntsWidth)
        | static_cast<F16T::RawBitsType>(mntsBits >> (F32T::mntsWidth - F16T::mntsWidth));

    return mntsBits & (1u << (F32T::mntsWidth - F16T::mntsWidth - 1)) ? res + static_cast<F16T::RawBitsType>(1u) : res;
}

f32_t f16_t::halfp2singles(uint16_t src)
{
    typedef IEEE754Traits<f16_t> F16T;
    typedef IEEE754Traits<f32_t> F32T;

    F32T::RawBitsType const f32signBit = (static_cast<F32T::RawBitsType>(src) << 16) & F32T::signMask;
    if( (src & ~F16T::signMask)==0 ) {
        return *reinterpret_cast<const float*>(&f32signBit);
    }

    int exp = (static_cast<int>(src & F16T::expMask) >> F16T::mntsWidth) - F16T::expBias;
    F32T::RawBitsType f32mntsBits = (static_cast<F32T::RawBitsType>(src) << (F32T::mntsWidth - F16T::mntsWidth)) & F32T::mntsMask;

    if( exp == F16T::maxExp ) {
        F32T::RawBitsType const res = f32mntsBits == 0 ?
            (f32signBit | F32T::expMask) :
            0xFFC00000u;
        return *reinterpret_cast<const float*>(&res);

    } else if( exp == F16T::minExp ) {
        f32mntsBits <<= 1;
        while( (f32mntsBits & F32T::expMask) == 0 ) {
            f32mntsBits <<= 1;
            --exp;
        }
        f32mntsBits &= F32T::mntsMask;
    }

    return makeFloat<f32_t>(f32signBit,exp,f32mntsBits);
}

template <typename Float>
std::string toC99str(Float v)
{
    typedef IEEE754Traits<Float> Traits;

    typename Traits::RawBitsType const srcBits = *reinterpret_cast<const typename Traits::RawBitsType*>(&v);
    std::ostringstream res;

    if (srcBits & Traits::signMask) {
        res << "-";
    }

    if( (srcBits & ~Traits::signMask) == 0 ) {
        res << "0.0"  << Traits::suffix;
        return res.str();
    }

    const int mntsHDWidth = (Traits::mntsWidth/4) + ((Traits::mntsWidth%4)!=0 ? 1 : 0);

    typename Traits::RawBitsType mntsBits = (srcBits & Traits::mntsMask) << (mntsHDWidth*4 - Traits::mntsWidth);
    int termZeroes = 0;
    if (mntsBits!=0) {
        while (!(mntsBits & 0xF)) {
            mntsBits >>= 4;
            ++termZeroes;
        }
    } else termZeroes = mntsHDWidth-1;

    int const exp = static_cast<int>((srcBits & Traits::expMask) >> Traits::mntsWidth) - Traits::expBias;
    if (exp==Traits::minExp) {
        res << "0x0." << std::setw(mntsHDWidth-termZeroes);
    } else {
        res << "0x1." << std::setw(1);
    }

    res << std::setfill('0') << std::hex << std::uppercase << mntsBits << "p" << std::dec << std::setw(1) << exp << Traits::suffix;

    return res.str();
}

static inline int digitValue(int c)
{
    c = tolower(c);
    if (c>='0' && c<='9') {
        return c - '0';
    } else if (c>='a' && c<='f') {
        return c - 'a' + 10;
    }
    return -1;
}

static inline int digitValueBitLen(int c)
{
    if (c>=8) return 4;
    if (c>=4) return 3;
    if (c>=2) return 2;
    return 1;
}

// this routine assumes valid input sequence (checked by re2c rules)
template <typename Float>
Float readC99(const SRef& s)
{
    typedef IEEE754Traits<Float> Traits;
    const char * const end = s.end;
    const char *p = s.begin;

    typename Traits::RawBitsType sign = 0;
    switch(*p) { // optional sign
    default: assert(false); break;
    case '-': sign = Traits::signMask; // fallthrough
    case '+': ++p;     // fallthrough
    case '0': p += 2;  // fallthrough
    }

    typename Traits::RawBitsType mntsBits = 0;
    int exp=0;

    while (*p=='0') ++p; // skip leading zeroes

    if (tolower(*p)!='p') {
        int const maxBits = Traits::mntsWidth + 1;
        int bitCount=0, expShift=0;
        if (*p=='.') { // no bits before dot
            ++p;
            while (*p=='0') expShift -=4, ++p; // shift exp until first bit

            if (tolower(*p)!='p') {
                int const digit = digitValue(*p++); // read first nonzero digit
                mntsBits = digit;
                int const digBitLen = digitValueBitLen(digit);
                bitCount += digBitLen;
                expShift -= 4-digBitLen;
            }
        } else {
            int const digit = digitValue(tolower(*p++));
            mntsBits = digit;
            int const digBitLen = digitValueBitLen(digit);
            bitCount += digBitLen;
            expShift += digBitLen;

            // read mantissa before dot
            while (tolower(*p)!='p' && *p!='.' && bitCount < maxBits) {
                int const digit = digitValue(*p);
                mntsBits = (mntsBits << 4) | digit;
                bitCount += 4;
                expShift += 4;
                ++p;
            }
            // if we ran out of mantissa need to skip until dot shifting exponent
            while (tolower(*p)!='p' && *p!='.') expShift +=4 , ++p;
            if (*p=='.') ++p;
        }

        // after dot
        while (tolower(*p)!='p' && bitCount < maxBits) { // read the rest of mantissa
            int const digit = digitValue(*p);
            mntsBits = (mntsBits << 4) | digit;
            bitCount += 4;
            ++p;
        }

        if (mntsBits) {
            while (tolower(*p)!='p') ++p; // skip the rest of digits until 'p'

            ++p;
            std::istrstream(p,end-p) >> std::dec >> exp;  // read decimal exponent
            exp += expShift - 1;

            if (bitCount > maxBits) {
                mntsBits >>= bitCount-maxBits; // shift back to fit max mantissa len
            } else {
                mntsBits <<= maxBits-bitCount; // shift forward to normalize mantissa
            }
        }
    }

    if (!mntsBits) {
        return *reinterpret_cast<const Float*>(&sign);
    }

    if (exp >= Traits::maxExp) {
        typename Traits::RawBitsType const res = (sign | Traits::expMask); // Signed Inf
        return *reinterpret_cast<const Float*>(&res);
    } else if (exp <= Traits::minExp) {
        int const denormShift = Traits::minExp - exp;
        if ( denormShift > Traits::mntsWidth ) { // mantissa shifted all the way off
            return *reinterpret_cast<const Float*>(&sign); // signed zero
        }
        exp = Traits::minExp;
        mntsBits >>= denormShift; // shifting denormalized mantissa
    }

    return makeFloat<Float>(sign,exp,mntsBits);
}


using ::ldexp; // to include ldexp from global namespace
static f16_t ldexp(f16_t v, int exp)
{
    f32_t sf = v;
    return static_cast<f16_t>(::ldexp(static_cast<float>(sf),exp));
}

template <typename Float>
int testc99()
{
    typedef IEEE754Traits<Float> Traits;

    static int const shift = IEEE754Traits<double>::mntsWidth-Traits::mntsWidth;

    static Float const m[] = {
        makeFloat<Float>(0,               0,(0x15555555555555ULL >> shift)),
        makeFloat<Float>(0,               0,(0x1AAAAAAAAAAAAAULL >> shift)),
        makeFloat<Float>(Traits::signMask,0,(0x15555555555555ULL >> shift)),
        makeFloat<Float>(Traits::signMask,0,(0x1AAAAAAAAAAAAAULL >> shift)),
        makeFloat<Float>(0,               0,(0x15f5f5f5f5f5f5ULL >> shift)),
        makeFloat<Float>(0,               0,(0x1A0A0A0A0A0A0AULL >> shift)),
        makeFloat<Float>(Traits::signMask,0,(0x15f5f5f5f5f5f5ULL >> shift)),
        makeFloat<Float>(Traits::signMask,0,(0x1A0A0A0A0A0A0AULL >> shift))
    };

    int errors = 0;
    for(int e=Traits::maxExp-1; e>Traits::minExp - Traits::mntsWidth; --e) {
        for (unsigned i=0; i<(sizeof m/sizeof m[0]); ++i) {
            Float const v = ldexp(m[i],e);
            std::string r = toC99str(v);
            Float const res = readC99<Float>(SRef(&r[0],&r[0] + r.length()));
            if (res!=v) {
                ++errors;
                std::cerr << "C99 test failed on e=" << e << ", value=" << v << std::endl;
            }
        }
    }
    return errors;
}

int testf16vsf32()
{
    typedef IEEE754Traits<f16_t> F16T;
    typedef IEEE754Traits<f32_t> F32T;

    static float const m[] = {
        makeFloat<f32_t>(0,             0,0x1555555U),
        makeFloat<f32_t>(0,             0,0x1AAAAAAU),
        makeFloat<f32_t>(F32T::signMask,0,0x1555555U),
        makeFloat<f32_t>(F32T::signMask,0,0x1AAAAAAU),
    };

    int errors = 0;
    for(int e=F16T::maxExp-1; e >= (F16T::minExp - F16T::mntsWidth); --e) {
        for (unsigned i=0; i<(sizeof m/sizeof m[0]); ++i) {
            float const src = ldexp(m[i],e);
            f16_t const f16 = f16_t(src);
            f32_t const f32 = f16;
            float const diff = f32-src;
            float const treshould = ldexp(1.0f,std::max(e-F16T::mntsWidth,F16T::minExp - F16T::mntsWidth));
            if ( fabs(diff) > treshould ) {
                ++errors;
                std::cerr << "testf16vsf32 test failed on e=" << e << ", value=" << src << std::endl;
            }
        }
    }
    return errors;
}

template int testc99<double>();
template int testc99<f32_t>();
template int testc99<f16_t>();

template std::string toC99str(f16_t v);
template std::string toC99str(f32_t v);
template std::string toC99str(double v);

template f16_t  readC99(const SRef& s);
template f32_t  readC99(const SRef& s);
template double readC99(const SRef& s);

int testFloatRelatedCode() {
     return testc99<double>()
     + testc99<f32_t>()
     + testc99<f16_t>()
     + testf16vsf32();
}

} // end namespace
