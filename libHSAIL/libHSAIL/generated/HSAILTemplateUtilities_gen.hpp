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
template<typename RetType, typename Visitor>
RetType dispatchByType_gen(unsigned type, Visitor& v) {
  using namespace Brig;
  switch( type ) {
    case BRIG_TYPE_B1                   : return v.template visit< BrigType<BRIG_TYPE_B1> >();
    case BRIG_TYPE_B128                 : return v.template visit< BrigType<BRIG_TYPE_B128> >();
    case BRIG_TYPE_B16                  : return v.template visit< BrigType<BRIG_TYPE_B16> >();
    case BRIG_TYPE_B32                  : return v.template visit< BrigType<BRIG_TYPE_B32> >();
    case BRIG_TYPE_B64                  : return v.template visit< BrigType<BRIG_TYPE_B64> >();
    case BRIG_TYPE_B8                   : return v.template visit< BrigType<BRIG_TYPE_B8> >();
    case BRIG_TYPE_F16                  : return v.template visit< BrigType<BRIG_TYPE_F16> >();
    case BRIG_TYPE_F16X2                : return v.template visit< BrigType<BRIG_TYPE_F16X2> >();
    case BRIG_TYPE_F16X4                : return v.template visit< BrigType<BRIG_TYPE_F16X4> >();
    case BRIG_TYPE_F16X8                : return v.template visit< BrigType<BRIG_TYPE_F16X8> >();
    case BRIG_TYPE_F32                  : return v.template visit< BrigType<BRIG_TYPE_F32> >();
    case BRIG_TYPE_F32X2                : return v.template visit< BrigType<BRIG_TYPE_F32X2> >();
    case BRIG_TYPE_F32X4                : return v.template visit< BrigType<BRIG_TYPE_F32X4> >();
    case BRIG_TYPE_F64                  : return v.template visit< BrigType<BRIG_TYPE_F64> >();
    case BRIG_TYPE_F64X2                : return v.template visit< BrigType<BRIG_TYPE_F64X2> >();
    case BRIG_TYPE_S16                  : return v.template visit< BrigType<BRIG_TYPE_S16> >();
    case BRIG_TYPE_S16X2                : return v.template visit< BrigType<BRIG_TYPE_S16X2> >();
    case BRIG_TYPE_S16X4                : return v.template visit< BrigType<BRIG_TYPE_S16X4> >();
    case BRIG_TYPE_S16X8                : return v.template visit< BrigType<BRIG_TYPE_S16X8> >();
    case BRIG_TYPE_S32                  : return v.template visit< BrigType<BRIG_TYPE_S32> >();
    case BRIG_TYPE_S32X2                : return v.template visit< BrigType<BRIG_TYPE_S32X2> >();
    case BRIG_TYPE_S32X4                : return v.template visit< BrigType<BRIG_TYPE_S32X4> >();
    case BRIG_TYPE_S64                  : return v.template visit< BrigType<BRIG_TYPE_S64> >();
    case BRIG_TYPE_S64X2                : return v.template visit< BrigType<BRIG_TYPE_S64X2> >();
    case BRIG_TYPE_S8                   : return v.template visit< BrigType<BRIG_TYPE_S8> >();
    case BRIG_TYPE_S8X16                : return v.template visit< BrigType<BRIG_TYPE_S8X16> >();
    case BRIG_TYPE_S8X4                 : return v.template visit< BrigType<BRIG_TYPE_S8X4> >();
    case BRIG_TYPE_S8X8                 : return v.template visit< BrigType<BRIG_TYPE_S8X8> >();
    case BRIG_TYPE_U16                  : return v.template visit< BrigType<BRIG_TYPE_U16> >();
    case BRIG_TYPE_U16X2                : return v.template visit< BrigType<BRIG_TYPE_U16X2> >();
    case BRIG_TYPE_U16X4                : return v.template visit< BrigType<BRIG_TYPE_U16X4> >();
    case BRIG_TYPE_U16X8                : return v.template visit< BrigType<BRIG_TYPE_U16X8> >();
    case BRIG_TYPE_U32                  : return v.template visit< BrigType<BRIG_TYPE_U32> >();
    case BRIG_TYPE_U32X2                : return v.template visit< BrigType<BRIG_TYPE_U32X2> >();
    case BRIG_TYPE_U32X4                : return v.template visit< BrigType<BRIG_TYPE_U32X4> >();
    case BRIG_TYPE_U64                  : return v.template visit< BrigType<BRIG_TYPE_U64> >();
    case BRIG_TYPE_U64X2                : return v.template visit< BrigType<BRIG_TYPE_U64X2> >();
    case BRIG_TYPE_U8                   : return v.template visit< BrigType<BRIG_TYPE_U8> >();
    case BRIG_TYPE_U8X16                : return v.template visit< BrigType<BRIG_TYPE_U8X16> >();
    case BRIG_TYPE_U8X4                 : return v.template visit< BrigType<BRIG_TYPE_U8X4> >();
    case BRIG_TYPE_U8X8                 : return v.template visit< BrigType<BRIG_TYPE_U8X8> >();
    default : return v.visitNone(type);
    }
}

