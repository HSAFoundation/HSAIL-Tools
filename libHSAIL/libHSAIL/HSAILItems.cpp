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
#include "HSAILItems.h"

namespace HSAIL_ASM
{

void setImmedImpl(OperandImmed op, const void * v, size_t numBytes, Brig::BrigType16_t type) {
    size_t const reqSize = offsetof(Brig::BrigOperandImmed,bytes) + numBytes;
    if (grow(op,reqSize) < reqSize) {
        assert(false);
    }
    memcpy(&op.brig()->bytes[0],v,numBytes);
    op.byteCount() = static_cast<uint16_t>(numBytes); //dp
    op.type() = type;
}

void setImmed(OperandImmed op, const void * v, Brig::BrigType16_t type) {
	setImmedImpl(op,v,getByteSize(type),convType2BitType(type));
}

template <typename T>
void setImmed(OperandImmed op, T v) {
	setImmedImpl(op,&v,sizeof v,CType2Brig<T>::asBitType::value);
}

template <typename T, size_t N>
void setImmed(OperandImmed op, const T (&v)[N])
{
	setImmedImpl(op,&v,sizeof v,CType2Brig<T,N>::asBitType::value);
}

template <>
void setImmed<bool>(OperandImmed op, bool v) {
    uint8_t t = v;
    setImmedImpl(op,&t,sizeof t,Brig::BRIG_TYPE_B1);
}

template void setImmed(OperandImmed, uint8_t);
template void setImmed(OperandImmed, uint16_t);
template void setImmed(OperandImmed, uint32_t);
template void setImmed(OperandImmed, uint64_t);
template void setImmed(OperandImmed, int8_t);
template void setImmed(OperandImmed, int16_t);
template void setImmed(OperandImmed, int32_t);
template void setImmed(OperandImmed, int64_t);
template void setImmed(OperandImmed, f16_t);
template void setImmed(OperandImmed, float);
template void setImmed(OperandImmed, double);
template void setImmed(OperandImmed, b128_t);

template void setImmed(OperandImmed, const float    (&)[2]);
template void setImmed(OperandImmed, const float    (&)[4]);
template void setImmed(OperandImmed, const double   (&)[2]);

template void setImmed(OperandImmed, const uint8_t  (&)[4]);
template void setImmed(OperandImmed, const uint8_t  (&)[8]);
template void setImmed(OperandImmed, const uint8_t  (&)[16]);
template void setImmed(OperandImmed, const uint16_t (&)[2]);
template void setImmed(OperandImmed, const uint16_t (&)[4]);
template void setImmed(OperandImmed, const uint16_t (&)[8]);
template void setImmed(OperandImmed, const uint32_t (&)[2]);
template void setImmed(OperandImmed, const uint32_t (&)[4]);
template void setImmed(OperandImmed, const uint64_t (&)[2]);

template void setImmed(OperandImmed, const int8_t   (&)[4]);
template void setImmed(OperandImmed, const int8_t   (&)[8]);
template void setImmed(OperandImmed, const int8_t   (&)[16]);
template void setImmed(OperandImmed, const int16_t  (&)[2]);
template void setImmed(OperandImmed, const int16_t  (&)[4]);
template void setImmed(OperandImmed, const int16_t  (&)[8]);
template void setImmed(OperandImmed, const int32_t  (&)[2]);
template void setImmed(OperandImmed, const int32_t  (&)[4]);
template void setImmed(OperandImmed, const int64_t  (&)[2]);

template void setImmed(OperandImmed, const f16_t (&)[2]);
template void setImmed(OperandImmed, const f16_t (&)[4]);
template void setImmed(OperandImmed, const f16_t (&)[8]);


#if 1 // define when really needed (eats a lot of compile time)

template <typename SrcBrigType>
class SetImmediate
{
    OperandImmed m_operand;
    typename SrcBrigType::CType m_value;
    SetImmediate& operator=(const SetImmediate&);
public:
    SetImmediate(OperandImmed operand,typename SrcBrigType::CType value)
        : m_operand(operand),m_value(value) {}
    template <typename ReqBrigType> void visit() {
        setImmed(m_operand,convert< ReqBrigType, SrcBrigType, ConvertImmediate>(m_value));
    }
    void visitNone(unsigned) const { assert(0); }
};

template <typename T> // this routine converts Value v to the requested brig type and save it into immediate
void setImmed(OperandImmed op, T v, Brig::BrigType16_t reqType) {
    SetImmediate< CType2Brig<T> > setImmediate(op,v);
    dispatchByType(reqType,setImmediate);
}

/*
class SetImmediateFromVoid
{
    OperandImmed           m_operand;
    const void *           m_value;
    Brig::BrigType16_t m_dstType;

public:
    SetImmediateFromVoid(OperandImmed operand,const void *value,Brig::BrigType16_t dstType)
        : m_operand(operand)
        , m_value(value)
        , m_dstType(dstType)
    {}
    template <typename SrcBrigType> void visit() {
        SetImmediate< SrcBrigType > setImmed(m_operand,*reinterpret_cast<const typename SrcBrigType::CType*>(m_value));
        dispatchByType(m_dstType,setImmed);
    }
    void visitNone(unsigned) const { assert(0); }
};

void setImmed(
    OperandImmed op,
    const void *v,
    Brig::BrigType16_t dstType,
    Brig::BrigType16_t srcType)
{
    SetImmediateFromVoid setImmed(op,v,dstType);
    dispatchByType(srcType,setImmed);
}*/

template void setImmed(OperandImmed, uint8_t,               Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, uint16_t,              Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, uint32_t,              Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, uint64_t,              Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, int8_t,                Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, int16_t,               Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, int32_t,               Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, int64_t,               Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, f16_t,                 Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, float,                 Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, double,                Brig::BrigType16_t  reqType);

template void setImmed(OperandImmed, const float    (&)[2], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const float    (&)[4], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const double   (&)[2], Brig::BrigType16_t  reqType);

template void setImmed(OperandImmed, const uint8_t  (&)[4], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const uint8_t  (&)[8], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const uint8_t  (&)[16], Brig::BrigType16_t reqType);
template void setImmed(OperandImmed, const uint16_t (&)[2], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const uint16_t (&)[4], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const uint16_t (&)[8], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const uint32_t (&)[2], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const uint32_t (&)[4], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const uint64_t (&)[2], Brig::BrigType16_t  reqType);

template void setImmed(OperandImmed, const int8_t   (&)[4], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const int8_t   (&)[8], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const int8_t   (&)[16], Brig::BrigType16_t reqType);
template void setImmed(OperandImmed, const int16_t  (&)[2], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const int16_t  (&)[4], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const int16_t  (&)[8], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const int32_t  (&)[2], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const int32_t  (&)[4], Brig::BrigType16_t  reqType);
template void setImmed(OperandImmed, const int64_t  (&)[2], Brig::BrigType16_t  reqType);

template void setImmed(OperandImmed, const f16_t (&)[2], Brig::BrigType16_t     reqType);
template void setImmed(OperandImmed, const f16_t (&)[4], Brig::BrigType16_t     reqType);
template void setImmed(OperandImmed, const f16_t (&)[8], Brig::BrigType16_t     reqType);

#endif

#include "generated/HSAILBrigStaticChecks_gen.hpp"
#include "generated/HSAILBrigUtilities_gen.hpp"
#include "generated/HSAILInitBrig_gen.hpp"

}