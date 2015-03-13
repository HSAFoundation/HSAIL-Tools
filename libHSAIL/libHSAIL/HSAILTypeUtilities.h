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
#ifndef INCLUDED_HSAIL_TYPEUTILITIES_H
#define INCLUDED_HSAIL_TYPEUTILITIES_H

#include "Brig.h"

#include <cstddef>
#include <cassert>

namespace HSAIL_ASM {

class f32_t;
class f64_t;

struct true_type  { static const bool value = true; };
struct false_type { static const bool value = false; };

template <bool v> struct bool2type { typedef false_type type; };
template <> struct bool2type<true> { typedef true_type type; };

inline true_type  operator && (true_type,true_type)   {return true_type(); }
inline false_type operator && (true_type,false_type)  {return false_type();}
inline false_type operator && (false_type,true_type)  {return false_type();}
inline false_type operator && (false_type,false_type) {return false_type();}

inline true_type  operator || (true_type,true_type)   {return true_type(); }
inline true_type  operator || (true_type,false_type)  {return true_type(); }
inline true_type  operator || (false_type,true_type)  {return true_type(); }
inline false_type operator || (false_type,false_type) {return false_type();}


template <typename T> struct make_unsigned;
template <> struct make_unsigned<signed char>        { typedef unsigned char type; };
template <> struct make_unsigned<char>               { typedef unsigned char type; };
template <> struct make_unsigned<short>              { typedef unsigned short type; };
template <> struct make_unsigned<int>                { typedef unsigned int type; };
template <> struct make_unsigned<long>               { typedef unsigned long type; };
template <> struct make_unsigned<long long>          { typedef unsigned long long type; };
template <> struct make_unsigned<unsigned char>      { typedef unsigned char type; };
template <> struct make_unsigned<unsigned short>     { typedef unsigned short type; };
template <> struct make_unsigned<unsigned int>       { typedef unsigned int type; };
template <> struct make_unsigned<unsigned long>      { typedef unsigned long type; };
template <> struct make_unsigned<unsigned long long> { typedef unsigned long long type; };

template <typename T> struct make_signed;
template <> struct make_signed<signed char>        { typedef signed char type; };
template <> struct make_signed<char>               { typedef signed char type; };
template <> struct make_signed<short>              { typedef signed short type; };
template <> struct make_signed<int>                { typedef signed int type; };
template <> struct make_signed<long>               { typedef signed long type; };
template <> struct make_signed<long long>          { typedef signed long long type; };
template <> struct make_signed<unsigned char>      { typedef signed char type; };
template <> struct make_signed<unsigned short>     { typedef signed short type; };
template <> struct make_signed<unsigned int>       { typedef signed int type; };
template <> struct make_signed<unsigned long>      { typedef signed long type; };
template <> struct make_signed<unsigned long long> { typedef signed long long type; };


template <unsigned highestBit> struct containing_uint;

template <> struct containing_uint<0u>  { typedef uint8_t type; };
template <> struct containing_uint<1u>  { typedef uint8_t type; };
template <> struct containing_uint<2u>  { typedef uint8_t type; };
template <> struct containing_uint<3u>  { typedef uint8_t type; };
template <> struct containing_uint<4u>  { typedef uint8_t type; };
template <> struct containing_uint<5u>  { typedef uint8_t type; };
template <> struct containing_uint<6u>  { typedef uint8_t type; };
template <> struct containing_uint<7u>  { typedef uint8_t type; };

template <> struct containing_uint<8u>  { typedef uint16_t type; };
template <> struct containing_uint<9u>  { typedef uint16_t type; };
template <> struct containing_uint<10u> { typedef uint16_t type; };
template <> struct containing_uint<11u> { typedef uint16_t type; };
template <> struct containing_uint<12u> { typedef uint16_t type; };
template <> struct containing_uint<13u> { typedef uint16_t type; };
template <> struct containing_uint<14u> { typedef uint16_t type; };
template <> struct containing_uint<15u> { typedef uint16_t type; };

template <> struct containing_uint<16u> { typedef uint32_t type; };
template <> struct containing_uint<17u> { typedef uint32_t type; };
template <> struct containing_uint<18u> { typedef uint32_t type; };
template <> struct containing_uint<19u> { typedef uint32_t type; };
template <> struct containing_uint<20u> { typedef uint32_t type; };
template <> struct containing_uint<21u> { typedef uint32_t type; };
template <> struct containing_uint<22u> { typedef uint32_t type; };
template <> struct containing_uint<23u> { typedef uint32_t type; };
template <> struct containing_uint<24u> { typedef uint32_t type; };
template <> struct containing_uint<25u> { typedef uint32_t type; };
template <> struct containing_uint<26u> { typedef uint32_t type; };
template <> struct containing_uint<27u> { typedef uint32_t type; };
template <> struct containing_uint<28u> { typedef uint32_t type; };
template <> struct containing_uint<29u> { typedef uint32_t type; };
template <> struct containing_uint<30u> { typedef uint32_t type; };
template <> struct containing_uint<31u> { typedef uint32_t type; };

template <> struct containing_uint<32u> { typedef uint64_t type; };
template <> struct containing_uint<33u> { typedef uint64_t type; };
template <> struct containing_uint<34u> { typedef uint64_t type; };
template <> struct containing_uint<35u> { typedef uint64_t type; };
template <> struct containing_uint<36u> { typedef uint64_t type; };
template <> struct containing_uint<37u> { typedef uint64_t type; };
template <> struct containing_uint<38u> { typedef uint64_t type; };
template <> struct containing_uint<39u> { typedef uint64_t type; };
template <> struct containing_uint<40u> { typedef uint64_t type; };
template <> struct containing_uint<41u> { typedef uint64_t type; };
template <> struct containing_uint<42u> { typedef uint64_t type; };
template <> struct containing_uint<43u> { typedef uint64_t type; };
template <> struct containing_uint<44u> { typedef uint64_t type; };
template <> struct containing_uint<45u> { typedef uint64_t type; };
template <> struct containing_uint<46u> { typedef uint64_t type; };
template <> struct containing_uint<47u> { typedef uint64_t type; };
template <> struct containing_uint<48u> { typedef uint64_t type; };
template <> struct containing_uint<49u> { typedef uint64_t type; };
template <> struct containing_uint<50u> { typedef uint64_t type; };
template <> struct containing_uint<51u> { typedef uint64_t type; };
template <> struct containing_uint<52u> { typedef uint64_t type; };
template <> struct containing_uint<53u> { typedef uint64_t type; };
template <> struct containing_uint<54u> { typedef uint64_t type; };
template <> struct containing_uint<55u> { typedef uint64_t type; };
template <> struct containing_uint<56u> { typedef uint64_t type; };
template <> struct containing_uint<57u> { typedef uint64_t type; };
template <> struct containing_uint<58u> { typedef uint64_t type; };
template <> struct containing_uint<59u> { typedef uint64_t type; };
template <> struct containing_uint<60u> { typedef uint64_t type; };
template <> struct containing_uint<61u> { typedef uint64_t type; };
template <> struct containing_uint<62u> { typedef uint64_t type; };
template <> struct containing_uint<63u> { typedef uint64_t type; };


template <typename T1, typename T2>
class is_1st_descendant_or_same_of_2nd
{
    static char fx(T2*);
    static double fx(...);
public:
    enum { value = sizeof(char) == sizeof(fx((T1*)0)) };
    typedef bool2type< value > type;
};

template<typename T1, typename T2> struct are_types_equal : false_type {};
template<typename T> struct are_types_equal<T,T> : true_type {};

struct undef_class { typedef undef_class* ptr; };
struct int_class   { typedef int_class* ptr; };
struct signed_int_class : int_class   { typedef signed_int_class* ptr; };
struct unsigned_int_class : int_class { typedef unsigned_int_class* ptr; };
struct float_class { typedef float_class* ptr; };

template <typename T> struct value_class : undef_class {};

template <> struct value_class<f32_t>  : float_class {};
template <> struct value_class<f64_t> : float_class {};
template <> struct value_class<long double> : float_class {};

template <> struct value_class<char>             : signed_int_class   {};

template <> struct value_class<signed char>      : signed_int_class   {};
template <> struct value_class<signed short>     : signed_int_class   {};
template <> struct value_class<signed int>       : signed_int_class   {};
template <> struct value_class<signed long>      : signed_int_class   {};
template <> struct value_class<signed long long> : signed_int_class   {};

template <> struct value_class<unsigned char>      : unsigned_int_class {};
template <> struct value_class<unsigned short>     : unsigned_int_class {};
template <> struct value_class<unsigned int>       : unsigned_int_class {};
template <> struct value_class<unsigned long>      : unsigned_int_class {};
template <> struct value_class<unsigned long long> : unsigned_int_class {};

template <typename T> struct is_int          : is_1st_descendant_or_same_of_2nd< value_class<T>, int_class          >::type {};
template <typename T> struct is_signed_int   : is_1st_descendant_or_same_of_2nd< value_class<T>, signed_int_class   >::type {};
template <typename T> struct is_unsigned_int : is_1st_descendant_or_same_of_2nd< value_class<T>, unsigned_int_class >::type {};
template <typename T> struct is_float        : is_1st_descendant_or_same_of_2nd< value_class<T>, float_class        >::type {};


template <BrigType BrigTypeId> struct BrigTypeTraits;

struct BrigTypeAny {};

struct BrigTypeNonPacked : BrigTypeAny {};
struct BrigTypeAnyPacked : BrigTypeAny {};

struct BrigTypeNF   : BrigTypeNonPacked {};
struct BrigTypeF    : BrigTypeNonPacked {};

struct BrigTypeB    : BrigTypeNF  {};
struct BrigTypeInt  : BrigTypeNF  {};
struct BrigTypeU    : BrigTypeInt {};
struct BrigTypeS    : BrigTypeInt {};



template <typename T,size_t>
class MySmallArray;

template <typename BrigElementType, size_t N>
struct BrigTypePacked : BrigTypeAnyPacked {
    typedef BrigElementType ElementType;
    static size_t const Size = N;
    typedef MySmallArray<typename ElementType::CType,N> CType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_SIG32>   : BrigTypeAny {
    static const BrigType value = BRIG_TYPE_SIG32;
    typedef uint64_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_SIG64>   : BrigTypeAny {
    static const BrigType value = BRIG_TYPE_SIG64;
    typedef uint64_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};


// bitstrings
template <> struct BrigTypeTraits<BRIG_TYPE_B1>   : BrigTypeB {
    static const BrigType value = BRIG_TYPE_B1;
    typedef bool CType;
    typedef BrigTypeTraits<BRIG_TYPE_B1>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_B8>   : BrigTypeB {
    static const BrigType value = BRIG_TYPE_B8;
    typedef uint8_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B8>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_B16>  : BrigTypeB {
    static const BrigType value = BRIG_TYPE_B16;
    typedef uint16_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B16>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_B32>  : BrigTypeB {
    static const BrigType value = BRIG_TYPE_B32;
    typedef uint32_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B32>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_B64>  : BrigTypeB {
    static const BrigType value = BRIG_TYPE_B64;
    typedef uint64_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

class b128_t;
template <> struct BrigTypeTraits<BRIG_TYPE_B128> : BrigTypeB {
    static const BrigType value = BRIG_TYPE_B128;
    typedef b128_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B128>  asBitType;
};

// signed ints
template <> struct BrigTypeTraits<BRIG_TYPE_S8>  : BrigTypeS {
    static const BrigType value = BRIG_TYPE_S8;
    typedef int8_t  CType;
    typedef BrigTypeTraits<BRIG_TYPE_B8>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_S16> : BrigTypeS {
    static const BrigType value = BRIG_TYPE_S16;
    typedef int16_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B16>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_S32> : BrigTypeS {
    static const BrigType value = BRIG_TYPE_S32;
    typedef int32_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B32>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_S64> : BrigTypeS {
    static const BrigType value = BRIG_TYPE_S64;
    typedef int64_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

// unsigned ints
template <> struct BrigTypeTraits<BRIG_TYPE_U8>  : BrigTypeU {
    static const BrigType value = BRIG_TYPE_U8;
    typedef uint8_t  CType;
    typedef BrigTypeTraits<BRIG_TYPE_B8>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_U16> : BrigTypeU {
    static const BrigType value = BRIG_TYPE_U16;
    typedef uint16_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B16>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_U32> : BrigTypeU {
    static const BrigType value = BRIG_TYPE_U32;
    typedef uint32_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B32>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_U64> : BrigTypeU {
    static const BrigType value = BRIG_TYPE_U64;
    typedef uint64_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

// floats
class f16_t;
template <> struct BrigTypeTraits<BRIG_TYPE_F16> : BrigTypeF {
    static const BrigType value = BRIG_TYPE_F16;
    typedef f16_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B16>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_F32> : BrigTypeF {
    static const BrigType value = BRIG_TYPE_F32;
    typedef f32_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B32>  asBitType;
};
template <> struct BrigTypeTraits<BRIG_TYPE_F64> : BrigTypeF {
    static const BrigType value = BRIG_TYPE_F64;
    typedef f64_t CType;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

// packed

template <> struct BrigTypeTraits<BRIG_TYPE_U8X4>   : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_U8>, 4> {
    static const BrigType value = BRIG_TYPE_U8X4;
    typedef BrigTypeTraits<BRIG_TYPE_B32>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_U8X8>   : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_U8>, 8> {
    static const BrigType value = BRIG_TYPE_U8X8;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_U8X16>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_U8>, 16> {
    static const BrigType value = BRIG_TYPE_U8X16;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_U16X2>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_U16>, 2> {
    static const BrigType value = BRIG_TYPE_U16X2;
    typedef BrigTypeTraits<BRIG_TYPE_B32>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_U16X4>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_U16>, 4> {
    static const BrigType value = BRIG_TYPE_U16X4;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_U16X8>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_U16>, 8> {
    static const BrigType value = BRIG_TYPE_U16X8;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_U32X2>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_U32>, 2> {
    static const BrigType value = BRIG_TYPE_U32X2;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_U32X4>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_U32>, 4> {
    static const BrigType value = BRIG_TYPE_U32X4;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_U64X2>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_U64>, 2> {
    static const BrigType value = BRIG_TYPE_U64X2;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};





template <> struct BrigTypeTraits<BRIG_TYPE_S8X4>   : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_S8>, 4> {
    static const BrigType value = BRIG_TYPE_S8X4;
    typedef BrigTypeTraits<BRIG_TYPE_B32>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_S8X8>   : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_S8>, 8> {
    static const BrigType value = BRIG_TYPE_S8X8;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_S8X16>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_S8>, 16> {
    static const BrigType value = BRIG_TYPE_S8X16;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_S16X2>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_S16>, 2> {
    static const BrigType value = BRIG_TYPE_S16X2;
    typedef BrigTypeTraits<BRIG_TYPE_B32>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_S16X4>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_S16>, 4> {
    static const BrigType value = BRIG_TYPE_S16X4;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_S16X8>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_S16>, 8> {
    static const BrigType value = BRIG_TYPE_S16X8;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_S32X2>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_S32>, 2> {
    static const BrigType value = BRIG_TYPE_S32X2;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_S32X4>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_S32>, 4> {
    static const BrigType value = BRIG_TYPE_S32X4;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_S64X2>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_S64>, 2> {
    static const BrigType value = BRIG_TYPE_S64X2;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};


template <> struct BrigTypeTraits<BRIG_TYPE_F16X2>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_F16>, 2> {
    static const BrigType value = BRIG_TYPE_F16X2;
    typedef BrigTypeTraits<BRIG_TYPE_B32>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_F16X4>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_F16>, 4> {
    static const BrigType value = BRIG_TYPE_F16X4;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_F16X8>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_F16>, 8> {
    static const BrigType value = BRIG_TYPE_F16X8;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_F32X2>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_F32>, 2> {
    static const BrigType value = BRIG_TYPE_F32X2;
    typedef BrigTypeTraits<BRIG_TYPE_B64>  asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_F32X4>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_F32>, 4> {
    static const BrigType value = BRIG_TYPE_F32X4;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};

template <> struct BrigTypeTraits<BRIG_TYPE_F64X2>  : BrigTypePacked< BrigTypeTraits<BRIG_TYPE_F64>, 2> {
    static const BrigType value = BRIG_TYPE_F64X2;
    typedef BrigTypeTraits<BRIG_TYPE_B128> asBitType;
};


// CType -> BrigType
template <typename T,size_t N=1> struct CType2Brig;

template <typename Elem, size_t N>
class MySmallArray;

template <typename T,size_t N>
struct CType2Brig< MySmallArray<T,N> > : CType2Brig<T,N> {};

template <typename T,size_t N>
struct CType2Brig< const T (&)[N] > : CType2Brig<T,N> {};

template <typename T,size_t N>
struct CType2Brig< const T (*)[N] > : CType2Brig<T,N> {};

template <> struct CType2Brig< int8_t,1u>    : BrigTypeTraits<BRIG_TYPE_S8>  {};
template <> struct CType2Brig< int16_t,1u>   : BrigTypeTraits<BRIG_TYPE_S16> {};
template <> struct CType2Brig< int32_t,1u>   : BrigTypeTraits<BRIG_TYPE_S32> {};
template <> struct CType2Brig< int64_t,1u>   : BrigTypeTraits<BRIG_TYPE_S64> {};

template <> struct CType2Brig< uint8_t,1u>   : BrigTypeTraits<BRIG_TYPE_U8>  {};
template <> struct CType2Brig< uint16_t,1u>  : BrigTypeTraits<BRIG_TYPE_U16> {};
template <> struct CType2Brig< uint32_t,1u>  : BrigTypeTraits<BRIG_TYPE_U32> {};
template <> struct CType2Brig< uint64_t,1u>  : BrigTypeTraits<BRIG_TYPE_U64> {};

template <> struct CType2Brig< b128_t,1u>    : BrigTypeTraits<BRIG_TYPE_B128> {};

template <> struct CType2Brig< f16_t,1u>     : BrigTypeTraits<BRIG_TYPE_F16> {};
template <> struct CType2Brig< f32_t,1u>     : BrigTypeTraits<BRIG_TYPE_F32> {};
template <> struct CType2Brig< f64_t,1u>    : BrigTypeTraits<BRIG_TYPE_F64> {};

template <> struct CType2Brig< int8_t,4u >   : BrigTypeTraits<BRIG_TYPE_S8X4>  {};
template <> struct CType2Brig< int8_t,8u >   : BrigTypeTraits<BRIG_TYPE_S8X8>  {};
template <> struct CType2Brig< int8_t,16u >  : BrigTypeTraits<BRIG_TYPE_S8X16> {};
template <> struct CType2Brig< int16_t,2u >  : BrigTypeTraits<BRIG_TYPE_S16X2> {};
template <> struct CType2Brig< int16_t,4u >  : BrigTypeTraits<BRIG_TYPE_S16X4> {};
template <> struct CType2Brig< int16_t,8u >  : BrigTypeTraits<BRIG_TYPE_S16X8> {};
template <> struct CType2Brig< int32_t,2u >  : BrigTypeTraits<BRIG_TYPE_S32X2> {};
template <> struct CType2Brig< int32_t,4u >  : BrigTypeTraits<BRIG_TYPE_S32X4> {};
template <> struct CType2Brig< int64_t,2u >  : BrigTypeTraits<BRIG_TYPE_S64X2> {};

template <> struct CType2Brig< uint8_t,4u >  : BrigTypeTraits<BRIG_TYPE_U8X4>  {};
template <> struct CType2Brig< uint8_t,8u >  : BrigTypeTraits<BRIG_TYPE_U8X8>  {};
template <> struct CType2Brig< uint8_t,16u > : BrigTypeTraits<BRIG_TYPE_U8X16> {};
template <> struct CType2Brig< uint16_t,2u > : BrigTypeTraits<BRIG_TYPE_U16X2> {};
template <> struct CType2Brig< uint16_t,4u > : BrigTypeTraits<BRIG_TYPE_U16X4> {};
template <> struct CType2Brig< uint16_t,8u > : BrigTypeTraits<BRIG_TYPE_U16X8> {};
template <> struct CType2Brig< uint32_t,2u > : BrigTypeTraits<BRIG_TYPE_U32X2> {};
template <> struct CType2Brig< uint32_t,4u > : BrigTypeTraits<BRIG_TYPE_U32X4> {};
template <> struct CType2Brig< uint64_t,2u > : BrigTypeTraits<BRIG_TYPE_U64X2> {};

template <> struct CType2Brig< f16_t,2u >    : BrigTypeTraits<BRIG_TYPE_F16X2> {};
template <> struct CType2Brig< f16_t,4u >    : BrigTypeTraits<BRIG_TYPE_F16X4> {};
template <> struct CType2Brig< f16_t,8u >    : BrigTypeTraits<BRIG_TYPE_F16X8> {};
template <> struct CType2Brig< f32_t,2u >    : BrigTypeTraits<BRIG_TYPE_F32X2> {};
template <> struct CType2Brig< f32_t,4u >    : BrigTypeTraits<BRIG_TYPE_F32X4> {};
template <> struct CType2Brig< f64_t,2u >   : BrigTypeTraits<BRIG_TYPE_F64X2> {};


#include "HSAILTemplateUtilities_gen.hpp"

template<typename RetType, typename Visitor>
inline RetType dispatchByType(unsigned type, const Visitor& v) {
    return dispatchByType_gen<RetType, const Visitor>(type, v);
}

template<typename RetType, typename Visitor>
inline RetType dispatchByType(unsigned type, Visitor& v) {
    return dispatchByType_gen<RetType, Visitor>(type, v);
}

template<typename Visitor>
inline void dispatchByType(unsigned type, const Visitor& v) {
    dispatchByType_gen<void,const Visitor>(type, v);
}

template<typename Visitor>
inline void dispatchByType(unsigned type, Visitor& v) {
    dispatchByType_gen<void,Visitor>(type, v);
}



template <typename Elem, size_t N>
class MySmallArray
{
    Elem data[N];
public:
    MySmallArray() {}
    MySmallArray(const Elem (&v)[N]) {
        *this = v;
    }

    Elem& operator[](size_t i) { return data[i]; }
    const Elem& operator[](size_t i) const { return data[i]; }

    const Elem (&arrayType() const)[N] { return data; }
    Elem (&arrayType())[N] { return data; }

    MySmallArray& operator=(const Elem (&v)[N]) {
        for(size_t i =0; i<N; ++i) data[i] = v[i];
        return *this;
    }
};



template <typename Value>
class Optional
{
    Value m_value;
    bool m_initialized;

    typedef void (Optional::*bool_type)() const;
    void toCompare() const {}

public:
    Optional() : m_value(), m_initialized(false) {};

    Optional(Value v) : m_value(v), m_initialized(true) {};

    Optional& operator=(Value newValue) {
        m_value = newValue;
        m_initialized = true;
        return *this;
    }

    bool isInitialized() const { return m_initialized; }
    operator bool_type() const { return isInitialized() ? &Optional::toCompare : NULL; }

    Value value() const { assert(m_initialized); return m_value; }
    Value value(Value def) const { return m_initialized? m_value : def; }
};

} // end namespace

#endif
