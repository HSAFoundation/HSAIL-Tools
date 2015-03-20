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
#ifndef INCLUDED_HSAIL_CONVERTORS_H
#define INCLUDED_HSAIL_CONVERTORS_H

#include "HSAILTypeUtilities.h"
#include "HSAILb128_t.h"
#include "HSAILFloats.h"
#include <string>
#include <limits>
#include <stdexcept>

namespace HSAIL_ASM
{

struct ConversionError : std::logic_error
{
    ConversionError(const char * errorMessage) : std::logic_error(errorMessage) {}
};

template <typename DstBrigType, typename SrcBrigType,
          template<typename, typename> class Convertor,
          typename SrcCType>
typename DstBrigType::CType convert(SrcCType src) {

    // commented out until gcc is >= 4.3
    //static_assert( are_types_equal<typename SrcBrigType::CType, SrcCType>::value==true,
    //               "actual type of source should match SrcBrigType::CType");

    Convertor<DstBrigType, SrcBrigType> const cvt = {src};
    return cvt.visit(reinterpret_cast<DstBrigType*>(NULL), reinterpret_cast<SrcBrigType*>(NULL));
}

template <typename DstBrigType, typename SrcBrigType,
          template<typename, typename> class Convertor,
          typename SrcCType>
bool assign(typename DstBrigType::CType* dst,SrcCType src, const char** errMsg=NULL) {
    try {
        *dst = convert<DstBrigType,SrcBrigType,Convertor,SrcCType>(src);
    } catch (const ConversionError& e) {
        if (errMsg) {
            *errMsg = e.what();
        }
        return false;
    }
    return true;
}

template <typename DstBrigType,
          template<typename, typename> class Convertor,
          typename SrcCType>
bool assign(typename DstBrigType::CType* dst,SrcCType src, const char** errMsg=NULL) {
    return assign< DstBrigType, CType2Brig< SrcCType >, Convertor, SrcCType >(dst,src,errMsg);
}

// assigns raw bits of src into dst even if sizes doesnt match
template<typename DstBrigType, typename SrcBrigType>
struct UnsafeCastConvert {

    typedef typename DstBrigType::CType DstType;
    typedef typename SrcBrigType::CType SrcType;
    SrcType src;

    DstType getBits(true_type*) const { // when sizeof(DstType) > sizeof(SrcType)
        DstType dst = DstType();
        *reinterpret_cast<SrcType*>(&dst) = src;
        return dst;
    }
    DstType getBits(false_type*) const { // when sizeof(DstType) <= sizeof(SrcType)
        return *reinterpret_cast<const DstType*>(&src);
    }

    DstType visit(...) const {
        return getBits( reinterpret_cast< typename bool2type<(sizeof(DstType) > sizeof(SrcType))>::type* >(NULL) );
    }
};

// assigns raw bits of src into dst if sizes match
template<typename DstBrigType, typename SrcBrigType>
struct LengthOnlyRuleConvert {

    typedef typename DstBrigType::CType DstType;
    typedef typename SrcBrigType::CType SrcType;
    SrcType src;

    DstType getBits(true_type*) const {  // when sizeof(DstType) == sizeof(SrcType)
        return *reinterpret_cast<const DstType*>(&src);
    }
    DstType getBits(false_type*) const { // when sizeof(DstType) != sizeof(SrcType)
        throw ConversionError("literal size must match size of operand type");
    }

    DstType visit(...) const {
        return getBits( reinterpret_cast< typename bool2type<(sizeof(DstType) == sizeof(SrcType))>::type* >(NULL) );
    }
};

template<typename DstBrigType, typename SrcBrigType>
struct TruncateRuleConvert {

    typedef typename DstBrigType::CType DstType;
    typedef typename SrcBrigType::CType SrcType;
    SrcType src;

    DstType getBits(true_type*) const {  // when sizeof(DstType) <= sizeof(SrcType)
        return *reinterpret_cast<const DstType*>(&src);
    }
    DstType getBits(false_type*) const { // when sizeof(DstType) > sizeof(SrcType)
        throw ConversionError("literal size must match or exceed size of operand type");
    }

    DstType visit(...) const {
        return getBits( reinterpret_cast< typename bool2type<(sizeof(DstType) <= sizeof(SrcType))>::type* >(NULL) );
    }
};


// simple static conversion
template<typename DstBrigType, typename SrcBrigType>
struct StaticCastConvert {

    typedef typename DstBrigType::CType DstType;
    typedef typename SrcBrigType::CType SrcType;
    SrcType src;

    DstType visit(...) const { return static_cast<DstType>(src); }
};

// convert src to dst preserving all significant bits of src
template<typename DstBrigType, typename SrcBrigType>
struct LosslessConvert {

    typedef typename DstBrigType::CType DstType;
    typedef typename SrcBrigType::CType SrcType;
    SrcType src;

    // float = int
    DstType visit(BrigTypeF*, BrigTypeNF*) const {
        typedef typename IEEE754Traits<DstType>::NativeType NativeType;
        NativeType s = static_cast<NativeType>(src);
        DstType res(&s);
        if ((SrcType)(res.floatValue()) != src) {
            throw ConversionError("conversion loses precision, use float literal");
        }
        return res;
    }
    // int = int
    DstType visit(BrigTypeNF*, BrigTypeNF*) const {
    	 if (src > (std::numeric_limits< typename make_unsigned<DstType>::type >::max)()) {
            throw ConversionError("value doesn't fit into destination");
        }
        return static_cast<DstType>(src);
    }
    // int = signed int
    DstType visit(BrigTypeNF*, BrigTypeS*) const {
        typedef typename   make_signed<DstType>::type SgnDstType;
        typedef typename make_unsigned<DstType>::type UnsDstType;
        typedef typename make_unsigned<SrcType>::type UnsSrcType;
        if ( (src < 0 && src < (std::numeric_limits<SgnDstType>::min)() ) ||
             (src > 0 && (static_cast<UnsSrcType>(src) > (std::numeric_limits<UnsDstType>::max)())) ) {
            throw ConversionError("value doesn't fit into destination");
        }
        return static_cast<DstType>(static_cast<SgnDstType>(src));
    }

    DstType visit(BrigTypeNF*, BrigTypeTraits<BRIG_TYPE_B128>*) const {
        throw ConversionError("conversion of b128 not supported yet");
    }

    DstType visit(BrigTypeNF*, BrigTypeTraits<BRIG_TYPE_B1>*) const {
        return src!=0 ? 1 : 0;
    }

    DstType visit(BrigTypeF*, BrigTypeTraits<BRIG_TYPE_B128>*) const {
        throw ConversionError("conversion not supported");
    }
    DstType visit(BrigTypeF*, BrigTypeTraits<BRIG_TYPE_B1>*) const {
        throw ConversionError("conversion not supported");
    }

    DstType visit(BrigTypeTraits<BRIG_TYPE_B128>*, BrigTypeNF*) const { return convert<DstBrigType,SrcBrigType,StaticCastConvert>(src); }
    DstType visit(BrigTypeTraits<BRIG_TYPE_B128>*, BrigTypeS*)  const { return convert<DstBrigType,SrcBrigType,StaticCastConvert>(src); }

    DstType visit(...) const { // error for all the rest combinations of types
        throw ConversionError("invalid operand type");
    }
};

// rules for converting literals to immediate values
template<typename DstBrigType, typename SrcBrigType>
struct ConvertImmediate {

    typedef typename DstBrigType::CType DstType;
    typedef typename SrcBrigType::CType SrcType;
    SrcType src;

    template <template <typename,typename> class Convertor>
    DstType use() const { return convert<DstBrigType,SrcBrigType,Convertor>(src); }

    // \todo this conversion is never selected if non-template conversions are available
    template <typename T>
    DstType visit(T*, T*) { return src; }

    // bitstring = anything
    DstType visit(BrigTypeB*, ...) const { return use<LengthOnlyRuleConvert>(); }

    // int or float = int
    DstType visit(BrigTypeNonPacked*, BrigTypeNF*) const { return use<TruncateRuleConvert>(); }
    DstType visit(BrigTypeNF*, BrigTypeNF*) const { return use<TruncateRuleConvert>(); }

    // special overload to resolve overload conflict with assign(BrigTypeB*, ...)
    DstType visit(BrigTypeB*, BrigTypeNF*) const { return use<TruncateRuleConvert>(); }

    // b1 = int
    DstType visit(BrigTypeTraits<BRIG_TYPE_B1>*, BrigTypeNF*) const { return src!=0; }


    // float = float
    DstType visit(BrigTypeTraits<BRIG_TYPE_F32>*, BrigTypeTraits<BRIG_TYPE_F32>*) const { return src; }
    DstType visit(BrigTypeTraits<BRIG_TYPE_F64>*, BrigTypeTraits<BRIG_TYPE_F64>*) const { return src; }
    DstType visit(BrigTypeTraits<BRIG_TYPE_F16>*, BrigTypeTraits<BRIG_TYPE_F16>*) const { return src; }
    DstType visit(BrigTypeF*, BrigTypeF*) const {
        // \todo this needs special handling of QNAN/SNAN during conversion
        typedef typename ::HSAIL_ASM::IEEE754Traits<DstType>::NativeType NativeType;
        NativeType res = static_cast<NativeType>(src.floatValue());
        return DstType(&res);
    }

    // packed[N] = int
    template <typename DstElemType,size_t N>
    DstType visit(BrigTypePacked<DstElemType,N>*, BrigTypeNF*) const {
        return use<TruncateRuleConvert>();
    }

    // packed[N] = packed[N]
    template <typename DstElemType,typename SrcElemType,size_t N>
    DstType visit(BrigTypePacked<DstElemType,N>*, BrigTypePacked<SrcElemType,N>*) const {
        DstType res;
        for(size_t i=0; i<N; ++i) {
            res[i] = convert<DstElemType,SrcElemType,::HSAIL_ASM::ConvertImmediate>(src[i]);
        }
        return res;
    }

    // packed[M] = packed[N], M!=N
    template <typename DstElemType,size_t M,typename SrcElemType,size_t N>
    DstType visit(BrigTypePacked<DstElemType,M>*, BrigTypePacked<SrcElemType,N>*) const {
        throw ConversionError("dimensions of packed destination and source should match");
    }

    DstType visit(...) const { // error for all the rest combinations of types
        throw ConversionError("invalid operand type");
    }
};

// convert src to dst if src fits into [max,min] of DstType
template<typename DstBrigType, typename SrcBrigType>
struct BoundCheckedConvert
{
    typedef typename DstBrigType::CType DstType;
    typedef typename SrcBrigType::CType SrcType;
    SrcType src;

    static void throwError() { throw ConversionError("value is out of bounds"); }

    // intX_t = intX_t
    DstType visit(BrigTypeS*,BrigTypeS*) const {
        if (src > (std::numeric_limits<DstType>::max)() ||
           src < (std::numeric_limits<DstType>::min)()) {
            throwError();
        }
        return static_cast<DstType>(src);
    }
    // uintX_t = intX_t
    DstType visit(BrigTypeU*,BrigTypeS*) const {
        if (src < 0 ||
                static_cast<typename make_unsigned<SrcType>::type>(src) > (std::numeric_limits<DstType>::max)() ) {
            throwError();
        }
        return static_cast<DstType>(src);
    }
    // (u)intX_t = uintX_t
    DstType visit(BrigTypeInt*,BrigTypeU*) const {
        if (src > static_cast<typename make_unsigned<DstType>::type>((std::numeric_limits<DstType>::max)())) {
            throwError();
        }
        return static_cast<DstType>(src);
    }
};

// the same as BoundCheckedConvert but require positive src
template<typename DstBrigType, typename SrcBrigType>
struct ConvertIfNonNegativeInt {

    typedef typename DstBrigType::CType DstType;
    typedef typename SrcBrigType::CType SrcType;
    SrcType src;

    // (u)intX_t = intX_t
    DstType visit(BrigTypeInt*,BrigTypeS*) const {
        if (src < SrcType()) {
            throw ConversionError("positive value or zero is expected");
        }
        return convert<DstBrigType,SrcBrigType,BoundCheckedConvert>(src);
    }
    // (u)intX_t = uintX_t
    DstType visit(BrigTypeInt*,BrigTypeU*) const {
        return convert<DstBrigType,SrcBrigType,BoundCheckedConvert>(src);
    }
};

// the same as ConvertIfNonNegativeInt plus require nonzero src
template<typename DstBrigType, typename SrcBrigType>
struct ConvertIfPositiveInt {

    typedef typename DstBrigType::CType DstType;
    typedef typename SrcBrigType::CType SrcType;
    SrcType src;

    DstType visit(...) const {
        if (src <= SrcType()) {
            throw ConversionError("positive value is expected");
        }
        return convert<DstBrigType,SrcBrigType,ConvertIfNonNegativeInt>(src);
    }
};

} // end namespace

#endif
