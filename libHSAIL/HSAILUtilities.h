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
#ifndef INCLUDED_HSAIL_UTILITIES_H
#define INCLUDED_HSAIL_UTILITIES_H

#include "HSAILTypeUtilities.h"
#include <iosfwd>
#include <stdint.h>
#include <cassert>
#include <string>

using std::string;

namespace HSAIL_ASM
{

class Inst;
class Operand;
class Directive;
class DirectiveVariable;
class DirectiveExecutable;
class BrigContainer;
class OperandRegister;
class OperandAddress;
class OperandConstantBytes;
class OperandConstantOperandList;
class OperandCodeRef;
struct SRef;

//============================================================================
// Operations with directives

bool     isDirective(unsigned id);
SRef     getName(Directive d);
unsigned getSegment(Directive d);
unsigned getSymLinkage(Directive d);
bool     isDecl(Directive d);
bool     isDef(Directive d);
DirectiveVariable getInputArg(DirectiveExecutable kernel, unsigned idx);
uint64_t getVariableNumBytes(DirectiveVariable var);
unsigned getVariableAlignment(DirectiveVariable var);
unsigned getCtlDirOperandType(unsigned kind, unsigned idx);
const char* validateCtlDirOperandBounds(unsigned kind, unsigned idx, uint64_t val);
bool allowCtlDirOperandWs(unsigned kind);

//============================================================================
// Operations with instructions

bool     isInstruction(unsigned id);
unsigned getType(Inst i);
unsigned getSrcType(Inst inst);
unsigned getCrdType(Inst inst);
unsigned getSigType(Inst inst);
unsigned getImgType(Inst inst);
unsigned getSegment(Inst inst);
unsigned getPacking(Inst inst);
unsigned getEqClass(Inst inst);

unsigned getOperandsNum(Inst inst);

Inst appendInst(BrigContainer &container, unsigned instFormat);

bool isCoreInst(Inst inst);
bool isImageInst(Inst inst);
bool isCoreOpcode(unsigned opcode);
bool isImageOpcode(unsigned opcode);

bool isImageInstFormat(unsigned fmt);
bool isFtzFormat(unsigned fmt);

bool isCallOpcode(unsigned opcode);
bool isBranchOpcode(unsigned opcode);
bool isIntArithOpcode(unsigned opcode);
bool isIntShiftOpcode(unsigned opcode);
bool isBitArithOpcode(unsigned opcode);

// True for instructions which unconditionally change control flow
// so that next instruction is only reachable via a jump
bool isTerminalOpcode(unsigned opcode);

//============================================================================
// Operations with operands

bool     isOperand(unsigned id);
bool     isCodeRef(OperandCodeRef cr, unsigned targetKind);

unsigned getAddrSize(OperandAddress addr, bool isLargeModel);
unsigned getSegAddrSize(unsigned segment, bool isLargeModel);
bool     isAddressableSeg(unsigned segment);

unsigned getRegKind(SRef opr);
unsigned getRegSize(OperandRegister reg);
string getRegName(OperandRegister reg);

unsigned getImmSize(OperandConstantBytes opr);
bool     isImmB1(OperandConstantBytes imm);
uint32_t getImmAsU32(OperandConstantBytes opr, unsigned index = 0);
uint64_t getImmAsU64(OperandConstantBytes opr);

uint64_t getAggregateNumBytes(OperandConstantOperandList opr);

const char* operandKind2str(unsigned kind);

//============================================================================
// Operations with types

bool       isFloatType(unsigned type);
bool       isIntType(unsigned type);
bool       isSignedType(unsigned type);
bool       isUnsignedType(unsigned type);
bool       isPackedType(unsigned type);
bool       isIntPackedType(unsigned type);
bool       isFloatPackedType(unsigned type);
bool       isBitType(unsigned type);
bool       isOpaqueType(unsigned type);
bool       isImageExtType(unsigned type);
bool       isImageType(unsigned type);
bool       isSamplerType(unsigned type);
bool       isSignalType(unsigned type);
bool       isFullProfileOnlyType(unsigned type);

unsigned   packedType2baseType(unsigned type);
unsigned   packedType2elementType(unsigned type);
unsigned   packedType2uType(unsigned type);
unsigned   arrayElementType(unsigned type);

unsigned   type2immType(unsigned elementType, bool isArray);
bool       isValidImmType(unsigned elementType);
bool       isValidVarType(unsigned type);

unsigned   expandSubwordType(unsigned type);
unsigned   type2bitType(unsigned type);
unsigned   bitType2uType(unsigned type);
unsigned   getBitType(unsigned size);
unsigned   getSignedType(unsigned size);
unsigned   getUnsignedType(unsigned size);

//============================================================================
// Operations with packing

bool       isSatPacking(unsigned packing);
bool       isUnrPacking(unsigned packing);
bool       isBinPacking(unsigned packing);
unsigned   getPackedTypeDim(unsigned type);
char       getPackingControl(unsigned srcOperandIdx, unsigned packing);

unsigned   getPackedDstDim(unsigned type, unsigned packing);

//============================================================================
// Operations with alignment

BrigAlignment getNaturalAlignment(unsigned type);
BrigAlignment getMaxAlignment();
bool          isValidAlignment(unsigned align, unsigned type);

//============================================================================
// Misc operations

const char* width2str(unsigned val);

size_t     align(size_t s, size_t pow2);

/// zero rightpadded copy. Copies min(len,room) elements from src to dst,
/// if len < room fills the gap with zeroes. returns min(len,room).
size_t     zeroPaddedCopy(void *dst, const void* src, size_t len, size_t room);

//============================================================================

const BrigSectionHeader* getBrigSection(
    BrigModule_t brigModule,
    unsigned index);

inline 
const BrigSectionHeader* getBrigSection(
    const BrigModuleHeader& brigModule,
    unsigned index) {
    // TODO remove const_cast
    return getBrigSection(const_cast<BrigModuleHeader*>(&brigModule),
                          index);
}

} // end namespace

#endif

