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
class DirectiveVariable;
class DirectiveExecutable;
class BrigContainer;
class OperandReg;
class OperandRegVector;
class OperandAddress;
class OperandImmed;
struct SRef;

size_t     align(size_t s, size_t pow2);

/// zero rightpadded copy. Copies min(len,room) elements from src to dst,
/// if len < room fills the gap with zeroes. returns min(len,room).
size_t     zeroPaddedCopy(void *dst, const void* src, size_t len, size_t room);

unsigned   getType(Inst i);
unsigned   getSrcType(Inst inst);
unsigned   getImgType(Inst inst);
unsigned   getSegment(Inst inst);
unsigned   getPacking(Inst inst);
unsigned   getEqClass(Inst inst);

unsigned   getDefWidth(Inst inst);
unsigned   getDefRounding(Inst inst);
           
bool       isFloatType(unsigned type);
bool       isIntType(unsigned type);
bool       isSignedType(unsigned type);
bool       isUnsignedType(unsigned type);
bool       isPackedType(unsigned type);
bool       isIntPackedType(unsigned type);
bool       isFloatPackedType(unsigned type);
bool       isBitType(unsigned type);
bool       isOpaqueType(unsigned type);
bool       isValidImmType(unsigned type);
bool       isValidVarType(unsigned type);
unsigned   convType2BitType(unsigned type);
unsigned   convPackedType2U(unsigned type);

unsigned   getBitSize(unsigned type);
unsigned   getBitType(unsigned size);
unsigned   getSignedType(unsigned size);
unsigned   getUnsignedType(unsigned size);
inline unsigned getByteSize(unsigned type) { return getBitSize(type) / 8; }
unsigned   getTypeSize(unsigned type);
unsigned   getSegAddrSize(unsigned segment, bool isLargeModel);

// This function returns type of the specified operand based on values of instruction fields 
// and machineModel (BRIG_MACHINE_SMALL or BRIG_MACHINE_LARGE). 
// The specified instruction must be properly formed with all fields containing valid values.
// It is recommended to call 'preValidateInst' before using this function.
// The returned value is BRIG_TYPE_NONE in the following cases:
// - the specified operand is not supported and must be null;
// - the specified operand is optional (e.g. list of call targets);
// - the specified operand is supported, but has no type (e.g. list of call arguments);
// The returned value is BRIG_TYPE_INVALID in the following cases:
// - type cannot be determined because of malformed instruction.
unsigned   getOperandType(Inst inst, unsigned operandIdx, unsigned machineModel);

// This function may be used to validate instruction before requesting type of operands.
// It returns 0 for properly formed instructions and a string containing an error
// message for malformed instructions.
// 
// This function should be used to avoid cryptic error messages in case of malformed instructions.
// For example, "masklane_b64 $d1, 1" has missing src type, as a result, 'getOperandType' will 
// return NONE for 2d operand which will result in 'unexpected operand' message
//
const char* preValidateInst(Inst inst, unsigned machineModel);

unsigned   getRegSize(SRef opr);
unsigned   getRegSize(Operand opr);
unsigned   getImmSize(OperandImmed opr);
unsigned   isImmB1(OperandImmed imm);
unsigned   getAddrSize(OperandAddress addr, bool isLargeModel);

DirectiveVariable getInputArg(DirectiveExecutable kernel, unsigned idx); 

bool isImageInst(unsigned opcode);

inline bool isGcnInst(unsigned opcode) {
    return (opcode & (1<<15))!=0; 
}

const char* width2str(unsigned val);
const char* align2str(unsigned val);
Brig::BrigAlignment num2align(unsigned val);
unsigned align2num(unsigned val);
Brig::BrigAlignment getNaturalAlignment(unsigned type);
bool        isValidAlignment(unsigned align, unsigned type);
const char* memoryFenceSeg2str(unsigned arg);

bool       isSatPacking(unsigned packing);
bool       isUnrPacking(unsigned packing);
bool       isBinPacking(unsigned packing);
unsigned   getPackedTypeDim(unsigned type);
char       getPackingControl(unsigned srcOperandIdx, unsigned packing);
unsigned   packedType2baseType(unsigned type);
unsigned   packedType2elementType(unsigned type);
unsigned   expandSubwordType(unsigned type);
unsigned   getPackedDstDim(unsigned type, unsigned packing);

} // end namespace

#endif

