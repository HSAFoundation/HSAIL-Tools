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
#ifndef INCLUDED_HSAIL_UTILITIES_H
#define INCLUDED_HSAIL_UTILITIES_H

#include "HSAILTypeUtilities.h"
#include <iosfwd>
#include <stdint.h>
#include <cassert>

namespace HSAIL_ASM
{

class Inst;
class Operand;
class Directive;
class BrigContainer;
class OperandRegVector;

size_t     align(size_t s, size_t pow2);

/// zero rightpadded copy. Copies min(len,room) elements from src to dst,
/// if len < room fills the gap with zeroes. returns min(len,room).
size_t     zeroPaddedCopy(void *dst, const void* src, size_t len, size_t room);

unsigned   getSrcType(Inst inst);
unsigned   getType(Inst i);

unsigned   getDefWidth(Inst inst);
unsigned   getDefRounding(unsigned opCode, unsigned type);
unsigned   getDefRoundingForCvt(unsigned srcType, unsigned dstType);

bool       isFloatType(unsigned type);
bool       isIntType(unsigned type);
bool       isUnsignedType(unsigned type);
bool       isPackedType(unsigned type);
bool       isIntPackedType(unsigned type);
bool       isFloatPackedType(unsigned type);
bool       isBitType(unsigned type);
unsigned   convType2BitType(unsigned type);

int        getBitSize(unsigned type);
inline int getByteSize(unsigned type) { return getBitSize(type) / 8; }
unsigned   getTypeSize(unsigned type);
unsigned   getSegAddrSize(unsigned segment, bool isLargeModel);
unsigned   getSegment(Inst inst);

unsigned   getImmOperandType(Inst inst, unsigned operandIdx, unsigned machineType);
unsigned   getOperandType(Operand opr);
unsigned   getOperandType(Operand opr, bool isLargeModel);

bool validateDstVector(OperandRegVector vector);

bool validateSrcOperand(Inst inst, int oprIdx, bool enableIntExp, bool enableFloatExp, bool instType, bool isAssert);
bool validateDstOperand(Inst inst, int oprIdx, bool enableIntExp, bool enableFloatExp, bool isAssert);
bool validateMachineType(Inst inst, int oprIdx, unsigned machineType, bool isSrcType, bool isUnsigned, bool isAssert);

inline bool isGcnInst(unsigned opcode) {
    return (opcode & (1<<16))!=0;
}

const char* width2str(unsigned val);

} // end namespace

#endif
