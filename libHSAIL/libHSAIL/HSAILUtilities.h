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
// Operations with Brig properties

void     setBrigProp(Inst inst, unsigned propId, unsigned val, bool ignoreErrors = false);
unsigned getBrigProp(Inst inst, unsigned propId, bool ignoreErrors = false, unsigned defaultVal = 0);
const char* validateProp(unsigned propId, unsigned val, unsigned* vals, unsigned length, unsigned model, unsigned profile);
const char* validateProp(unsigned propId, unsigned val, unsigned model, unsigned profile, bool imageExt);
const char* validateProp(Inst inst, unsigned propId, unsigned model, unsigned profile, bool imageExt);

bool hasImageExtProps(Inst inst);     // checks opcode, type and operands

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
unsigned getDefWidth(Inst inst, unsigned machineModel, unsigned profile);
unsigned getDefRounding(Inst inst, unsigned machineModel, unsigned profile);

// This function returns type of the specified operand based on values of instruction fields,
// machineModel (BRIG_MACHINE_SMALL or BRIG_MACHINE_LARGE) and profile (BRIG_PROFILE_BASE or BRIG_PROFILE_FULL).
// The specified instruction must be properly formed with all fields containing valid values.
// It is recommended to call 'preValidateInst' before using this function.
// The returned value is BRIG_TYPE_NONE in the following cases:
// - the specified operand is not supported and must be null;
// - the specified operand is optional (e.g. list of call targets);
// - the specified operand is supported, but has no type (e.g. list of call arguments);
// The returned value is BRIG_TYPE_INVALID in the following cases:
// - type cannot be determined because of malformed instruction.
unsigned   getOperandType(Inst inst, unsigned operandIdx, unsigned machineModel, unsigned profile);

// This function may be used to validate instruction before requesting type of operands.
// It returns 0 for properly formed instructions and a string containing an error
// message for malformed instructions.
//
// This function should be used to avoid cryptic error messages in case of malformed instructions.
// For example, "masklane_b64 $d1, 1" has missing src type, as a result, 'getOperandType' will
// return NONE for 2d operand which will result in 'unexpected operand' message
//
const char* preValidateInst(Inst inst, unsigned machineModel, unsigned profile);

Inst appendInst(BrigContainer &container, unsigned instFormat);

bool isImageInst(unsigned opcode);  // checks opcode only
inline bool isGcnInst(unsigned opcode) { return (opcode & (1<<15))!=0; }
bool isCallInst(unsigned opcode);
bool isBranchInst(unsigned opcode);

// True for instructions which unconditionally change control flow
// so that next instruction is only reachable via a jump
bool isTermInst(unsigned opcode);

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
bool                isValidAlignment(unsigned align, unsigned type);

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

