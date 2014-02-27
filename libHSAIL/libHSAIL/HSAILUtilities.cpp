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
#include "HSAILUtilities.h"
#include "HSAILItems.h"
#include "HSAILValidator.h"

#include <cassert>
#include <string>

using std::string;

namespace HSAIL_ASM {
    
std::ostream& operator<<(std::ostream& os, const SRef& s) {
    os.write(s.begin,s.length());
    return os;
}
size_t align(size_t s, size_t pow2) 
{
    assert( (pow2 & (pow2-1))==0 );
    size_t const m = pow2-1;
    return (s + m) & ~m;
}

/// zero rightpadded copy. Copies min(len,room) elements from src to dst,
/// if len < room fills the gap with zeroes. returns min(len,room).
size_t zeroPaddedCopy(void *dst, const void* src, size_t len, size_t room)
{
    size_t const toCopy = std::min(len,room);
    memcpy(dst,src,toCopy);
    size_t const pad = room-toCopy;
    if (pad > 0) memset(reinterpret_cast<char*>(dst)+toCopy,0,pad);
    return toCopy;
}

unsigned getDefWidth(Inst inst)
{
    using namespace Brig;
    switch(inst.opcode()) 
    {
    case BRIG_OPCODE_LD:
    case BRIG_OPCODE_GCNLD:
    case BRIG_OPCODE_CBR:
    case BRIG_OPCODE_ACTIVELANESHUFFLE:
    case BRIG_OPCODE_ACTIVELANEID:
    case BRIG_OPCODE_ACTIVELANEMASK:
    case BRIG_OPCODE_ACTIVELANECOUNT:
        return BRIG_WIDTH_1;

    case BRIG_OPCODE_BARRIER:
        return BRIG_WIDTH_ALL;

    case BRIG_OPCODE_JOINFBAR:
    case BRIG_OPCODE_WAITFBAR:
    case BRIG_OPCODE_ARRIVEFBAR:
    case BRIG_OPCODE_LEAVEFBAR:
    case BRIG_OPCODE_WAVEBARRIER:
        return BRIG_WIDTH_WAVESIZE;

    case BRIG_OPCODE_ST:
    case BRIG_OPCODE_GCNST:
    case BRIG_OPCODE_INITFBAR:
    case BRIG_OPCODE_RELEASEFBAR:
        return BRIG_WIDTH_NONE;

    case BRIG_OPCODE_BRN:
    case BRIG_OPCODE_CALL:
        return (inst.operand(0) && inst.operand(0).kind() == BRIG_OPERAND_REG)? BRIG_WIDTH_1 : BRIG_WIDTH_ALL;

    default:
        return BRIG_WIDTH_NONE;
    }
}

unsigned getDefRounding(Inst inst)
{
    using namespace Brig;

    unsigned dstType = inst.type();

    switch(inst.opcode()) 
    {
    case BRIG_OPCODE_ADD:
    case BRIG_OPCODE_DIV:
    case BRIG_OPCODE_FMA:
    case BRIG_OPCODE_MUL:
    case BRIG_OPCODE_SQRT:
    case BRIG_OPCODE_SUB:
        if (isFloatType(dstType) || isFloatPackedType(dstType)) return BRIG_ROUND_FLOAT_NEAR_EVEN;
        break;

    case BRIG_OPCODE_CVT:
        {
            unsigned srcType = InstCvt(inst).sourceType();

            if (isFloatType(srcType) && isFloatType(dstType) && getBitSize(srcType) > getBitSize(dstType)) 
            {
                return BRIG_ROUND_FLOAT_NEAR_EVEN;
            } 
            else if (isIntType(srcType) && !isBitType(srcType) && isFloatType(dstType)) 
            {
                return BRIG_ROUND_FLOAT_NEAR_EVEN;
            } 
            else if (isFloatType(srcType) && isIntType(dstType) && !isBitType(dstType)) 
            {
                return BRIG_ROUND_INTEGER_ZERO;
            } 
        }
        break;

    default:
        break;
    }

    return BRIG_ROUND_NONE;
}

bool isIntType(unsigned type) 
{
    using namespace Brig;
    switch(type) 
    {
    case BRIG_TYPE_B1:  
    case BRIG_TYPE_B8:  
    case BRIG_TYPE_B16: 
    case BRIG_TYPE_B32: 
    case BRIG_TYPE_B64: 
    case BRIG_TYPE_B128: 

    case BRIG_TYPE_S8:  
    case BRIG_TYPE_S16: 
    case BRIG_TYPE_S32: 
    case BRIG_TYPE_S64: 

    case BRIG_TYPE_U8:  
    case BRIG_TYPE_U16: 
    case BRIG_TYPE_U32: 
    case BRIG_TYPE_U64: 
        return true;

    default:  
        return false;
    }
}

bool isSignedType(unsigned type) 
{
    using namespace Brig;

    switch(type) 
    {
    case BRIG_TYPE_S8:  
    case BRIG_TYPE_S16: 
    case BRIG_TYPE_S32: 
    case BRIG_TYPE_S64: 
        return true;

    default:  
        return false;
    }
}

bool isUnsignedType(unsigned type) 
{
    using namespace Brig;

    switch(type) 
    {
    case BRIG_TYPE_U8:  
    case BRIG_TYPE_U16: 
    case BRIG_TYPE_U32: 
    case BRIG_TYPE_U64: 
        return true;

    default:  
        return false;
    }
}

bool isBitType(unsigned type) 
{
    using namespace Brig;
    switch(type) 
    {
    case BRIG_TYPE_B1:  
    case BRIG_TYPE_B8:  
    case BRIG_TYPE_B16: 
    case BRIG_TYPE_B32: 
    case BRIG_TYPE_B64: 
    case BRIG_TYPE_B128: 
        return true;

    default:  
        return false;
    }
}

bool isOpaqueType(unsigned type) 
{
    using namespace Brig;
    switch(type) 
    {
    case BRIG_TYPE_SAMP:
    case BRIG_TYPE_ROIMG: 
    case BRIG_TYPE_RWIMG: 
    case BRIG_TYPE_SIG32: 
    case BRIG_TYPE_SIG64: 
        return true;

    default:  
        return false;
    }
}

bool isValidImmType(unsigned type) 
{
    return type != Brig::BRIG_TYPE_NONE && !isOpaqueType(type);
}

bool isValidVarType(unsigned type) 
{
    return type != Brig::BRIG_TYPE_NONE && type != Brig::BRIG_TYPE_B1;
}

bool isFloatType(unsigned type)
{
    using namespace Brig;
    return type == BRIG_TYPE_F16 || type == BRIG_TYPE_F32 || type == BRIG_TYPE_F64;
}

bool isPackedType(unsigned type)
{
    return isIntPackedType(type) || isFloatPackedType(type);
}

bool isIntPackedType(unsigned type)
{
    using namespace Brig;
    switch(type) 
    {
    case BRIG_TYPE_U8X4:
    case BRIG_TYPE_S8X4:
    case BRIG_TYPE_U16X2:
    case BRIG_TYPE_S16X2:
    case BRIG_TYPE_U8X8:
    case BRIG_TYPE_S8X8:
    case BRIG_TYPE_U16X4:
    case BRIG_TYPE_S16X4:
    case BRIG_TYPE_U32X2:
    case BRIG_TYPE_S32X2:
    case BRIG_TYPE_U8X16:
    case BRIG_TYPE_S8X16:
    case BRIG_TYPE_U16X8:
    case BRIG_TYPE_S16X8:
    case BRIG_TYPE_U32X4:
    case BRIG_TYPE_S32X4:
    case BRIG_TYPE_U64X2:
    case BRIG_TYPE_S64X2:
        return true;

    default:  
        return false;
    }
}

bool isFloatPackedType(unsigned type)
{
    using namespace Brig;
    switch(type) 
    {
    case BRIG_TYPE_F16X2:
    case BRIG_TYPE_F16X4:
    case BRIG_TYPE_F32X2:
    case BRIG_TYPE_F16X8:
    case BRIG_TYPE_F32X4:
    case BRIG_TYPE_F64X2:
        return true;
    default:  
        return false;
    }
}

unsigned convType2BitType(unsigned type)
{
    using namespace Brig;
    switch(type) 
    {
    case BRIG_TYPE_B1:     return BRIG_TYPE_B1;
    case BRIG_TYPE_B8:     return BRIG_TYPE_B8;
    case BRIG_TYPE_B16:    return BRIG_TYPE_B16;
    case BRIG_TYPE_B32:    return BRIG_TYPE_B32;
    case BRIG_TYPE_B64:    return BRIG_TYPE_B64;
    case BRIG_TYPE_B128:   return BRIG_TYPE_B128;
                    
    case BRIG_TYPE_S8:     return BRIG_TYPE_B8;
    case BRIG_TYPE_S16:    return BRIG_TYPE_B16;
    case BRIG_TYPE_S32:    return BRIG_TYPE_B32;
    case BRIG_TYPE_S64:    return BRIG_TYPE_B64;
                            
    case BRIG_TYPE_U8:     return BRIG_TYPE_B8;
    case BRIG_TYPE_U16:    return BRIG_TYPE_B16;
    case BRIG_TYPE_U32:    return BRIG_TYPE_B32;
    case BRIG_TYPE_U64:    return BRIG_TYPE_B64;
                            
    case BRIG_TYPE_F16:    return BRIG_TYPE_B16;
    case BRIG_TYPE_F32:    return BRIG_TYPE_B32;
    case BRIG_TYPE_F64:    return BRIG_TYPE_B64;
                            
    case BRIG_TYPE_U8X4:   return BRIG_TYPE_B32;
    case BRIG_TYPE_S8X4:   return BRIG_TYPE_B32;
    case BRIG_TYPE_U16X2:  return BRIG_TYPE_B32;
    case BRIG_TYPE_S16X2:  return BRIG_TYPE_B32;
    case BRIG_TYPE_F16X2:  return BRIG_TYPE_B32;
    case BRIG_TYPE_U8X8:   return BRIG_TYPE_B64;
    case BRIG_TYPE_S8X8:   return BRIG_TYPE_B64;
    case BRIG_TYPE_U16X4:  return BRIG_TYPE_B64;
    case BRIG_TYPE_S16X4:  return BRIG_TYPE_B64;
    case BRIG_TYPE_F16X4:  return BRIG_TYPE_B64;
    case BRIG_TYPE_U32X2:  return BRIG_TYPE_B64;
    case BRIG_TYPE_S32X2:  return BRIG_TYPE_B64;
    case BRIG_TYPE_F32X2:  return BRIG_TYPE_B64;
    case BRIG_TYPE_U8X16:  return BRIG_TYPE_B128;
    case BRIG_TYPE_S8X16:  return BRIG_TYPE_B128;
    case BRIG_TYPE_U16X8:  return BRIG_TYPE_B128;
    case BRIG_TYPE_S16X8:  return BRIG_TYPE_B128;
    case BRIG_TYPE_F16X8:  return BRIG_TYPE_B128;
    case BRIG_TYPE_U32X4:  return BRIG_TYPE_B128;
    case BRIG_TYPE_S32X4:  return BRIG_TYPE_B128;
    case BRIG_TYPE_F32X4:  return BRIG_TYPE_B128;
    case BRIG_TYPE_U64X2:  return BRIG_TYPE_B128;
    case BRIG_TYPE_S64X2:  return BRIG_TYPE_B128;
    case BRIG_TYPE_F64X2:  return BRIG_TYPE_B128;

    case BRIG_TYPE_SAMP:   
    case BRIG_TYPE_ROIMG:  
    case BRIG_TYPE_RWIMG:  
    case BRIG_TYPE_SIG32: 
    case BRIG_TYPE_SIG64:  return BRIG_TYPE_B64;


    default:  
        return BRIG_TYPE_NONE;
    }
}

unsigned convPackedType2U(unsigned type)
{
    using namespace Brig;
    switch(type) 
    {
    case BRIG_TYPE_U8X4:   return BRIG_TYPE_U8X4; 
    case BRIG_TYPE_S8X4:   return BRIG_TYPE_U8X4; 
    case BRIG_TYPE_U16X2:  return BRIG_TYPE_U16X2;
    case BRIG_TYPE_S16X2:  return BRIG_TYPE_U16X2;
    case BRIG_TYPE_F16X2:  return BRIG_TYPE_U16X2;
    case BRIG_TYPE_U8X8:   return BRIG_TYPE_U8X8; 
    case BRIG_TYPE_S8X8:   return BRIG_TYPE_U8X8; 
    case BRIG_TYPE_U16X4:  return BRIG_TYPE_U16X4;
    case BRIG_TYPE_S16X4:  return BRIG_TYPE_U16X4;
    case BRIG_TYPE_F16X4:  return BRIG_TYPE_U16X4;
    case BRIG_TYPE_U32X2:  return BRIG_TYPE_U32X2;
    case BRIG_TYPE_S32X2:  return BRIG_TYPE_U32X2;
    case BRIG_TYPE_F32X2:  return BRIG_TYPE_U32X2;
    case BRIG_TYPE_U8X16:  return BRIG_TYPE_U8X16;
    case BRIG_TYPE_S8X16:  return BRIG_TYPE_U8X16;
    case BRIG_TYPE_U16X8:  return BRIG_TYPE_U16X8;
    case BRIG_TYPE_S16X8:  return BRIG_TYPE_U16X8;
    case BRIG_TYPE_F16X8:  return BRIG_TYPE_U16X8;
    case BRIG_TYPE_U32X4:  return BRIG_TYPE_U32X4;
    case BRIG_TYPE_S32X4:  return BRIG_TYPE_U32X4;
    case BRIG_TYPE_F32X4:  return BRIG_TYPE_U32X4;
    case BRIG_TYPE_U64X2:  return BRIG_TYPE_U64X2;
    case BRIG_TYPE_S64X2:  return BRIG_TYPE_U64X2;
    case BRIG_TYPE_F64X2:  return BRIG_TYPE_U64X2;

    default:  
        return BRIG_TYPE_NONE;
    }
}

unsigned getBitSize(unsigned type)
{
    using namespace Brig;

    unsigned const bType = convType2BitType(type);
    switch(bType) {
    case BRIG_TYPE_B1:
    case BRIG_TYPE_B8:   return 8;
    case BRIG_TYPE_B16:  return 16;
    case BRIG_TYPE_B32:  return 32;
    case BRIG_TYPE_B64:  return 64;
    case BRIG_TYPE_B128: return 128;
    default: assert(false);
    }
    return 0;
}

unsigned getBitType(unsigned size)
{
    using namespace Brig;

    switch(size) {
    case 1:   return BRIG_TYPE_B1;
    case 8:   return BRIG_TYPE_B8;
    case 16:  return BRIG_TYPE_B16;
    case 32:  return BRIG_TYPE_B32;
    case 64:  return BRIG_TYPE_B64;
    case 128: return BRIG_TYPE_B128;
    default: 
        assert(false);
        return BRIG_TYPE_NONE;
    }
}

unsigned getSignedType(unsigned size)
{
    using namespace Brig;

    switch(size) {
    case 8:   return BRIG_TYPE_S8;
    case 16:  return BRIG_TYPE_S16;
    case 32:  return BRIG_TYPE_S32;
    case 64:  return BRIG_TYPE_S64;
    default: 
        assert(false);
        return BRIG_TYPE_NONE;
    }
}

unsigned getUnsignedType(unsigned size)
{
    using namespace Brig;

    switch(size) {
    case 8:   return BRIG_TYPE_U8;
    case 16:  return BRIG_TYPE_U16;
    case 32:  return BRIG_TYPE_U32;
    case 64:  return BRIG_TYPE_U64;
    default: 
        assert(false);
        return BRIG_TYPE_NONE;
    }
}

unsigned getTypeSize(unsigned type)
{
    if (isOpaqueType(type)) return 64;
    int result = brigtype_get_length(type);
    assert(result);
    return result;
}

unsigned getSegAddrSize(unsigned segment, bool isLargeModel)
{
    using namespace Brig;

    switch (segment)
    {
    case BRIG_SEGMENT_FLAT:
    case BRIG_SEGMENT_GLOBAL:
    case BRIG_SEGMENT_READONLY:
    case BRIG_SEGMENT_KERNARG:
        return isLargeModel? 64 : 32;

    default:
        return 32;
    }
}

unsigned getAddrSize(OperandAddress addr, bool isLargeModel)
{
    assert(addr);
    if (addr.reg()) return getRegSize(addr.reg());
    if (addr.symbol()) return getSegAddrSize(addr.symbol().segment(), isLargeModel);
    if (addr.offsetHi() != 0) return 64;
    return 0; // unknown, both 32 and 64 are possible
}

unsigned getRegSize(SRef regName)
{
    string name = regName;

    if (name.empty()) return 0;

    switch(name[1])
    {
    case 'c': return 1;
    case 's': return 32;
    case 'd': return 64;
    case 'q': return 128;
    default:  return 0;
    }
}

unsigned getRegSize(Operand opr)
{
    if (OperandReg reg = opr)       return getRegSize(reg.reg());
    if (OperandRegVector reg = opr) return getRegSize(reg.regs(0));
    assert(false);
    return 0;
}

unsigned getImmSize(OperandImmed imm)
{
    assert(imm);
    return OperandImmed(imm).byteCount() * 8;
}

unsigned isImmB1(OperandImmed imm)
{
    assert(imm);
    return imm.byteCount() == 1 && (imm.bytes(0) == 0 || imm.bytes(0) == 1);
}

DirectiveVariable getInputArg(DirectiveExecutable sbr, unsigned idx)
{
    assert(idx < sbr.inArgCount());

    Directive arg;
    for (arg = sbr.firstInArg(); idx-- > 0; arg = arg.next());

    assert(arg);
    assert(DirectiveVariable(arg));

    return arg;
}

const char* width2str(unsigned val)
{
    using namespace Brig;

    switch(val) 
    {
    case BRIG_WIDTH_1                   : return "width(1)";
    case BRIG_WIDTH_1024                : return "width(1024)";
    case BRIG_WIDTH_1048576             : return "width(1048576)";
    case BRIG_WIDTH_1073741824          : return "width(1073741824)";
    case BRIG_WIDTH_128                 : return "width(128)";
    case BRIG_WIDTH_131072              : return "width(131072)";
    case BRIG_WIDTH_134217728           : return "width(134217728)";
    case BRIG_WIDTH_16                  : return "width(16)";
    case BRIG_WIDTH_16384               : return "width(16384)";
    case BRIG_WIDTH_16777216            : return "width(16777216)";
    case BRIG_WIDTH_2                   : return "width(2)";
    case BRIG_WIDTH_2048                : return "width(2048)";
    case BRIG_WIDTH_2097152             : return "width(2097152)";
    case BRIG_WIDTH_2147483648          : return "width(2147483648)";
    case BRIG_WIDTH_256                 : return "width(256)";
    case BRIG_WIDTH_262144              : return "width(262144)";
    case BRIG_WIDTH_268435456           : return "width(268435456)";
    case BRIG_WIDTH_32                  : return "width(32)";
    case BRIG_WIDTH_32768               : return "width(32768)";
    case BRIG_WIDTH_33554432            : return "width(33554432)";
    case BRIG_WIDTH_4                   : return "width(4)";
    case BRIG_WIDTH_4096                : return "width(4096)";
    case BRIG_WIDTH_4194304             : return "width(4194304)";
    case BRIG_WIDTH_512                 : return "width(512)";
    case BRIG_WIDTH_524288              : return "width(524288)";
    case BRIG_WIDTH_536870912           : return "width(536870912)";
    case BRIG_WIDTH_64                  : return "width(64)";
    case BRIG_WIDTH_65536               : return "width(65536)";
    case BRIG_WIDTH_67108864            : return "width(67108864)";
    case BRIG_WIDTH_8                   : return "width(8)";
    case BRIG_WIDTH_8192                : return "width(8192)";
    case BRIG_WIDTH_8388608             : return "width(8388608)";
    case BRIG_WIDTH_ALL                 : return "width(all)";
    case BRIG_WIDTH_WAVESIZE            : return "width(WAVESIZE)";
    case BRIG_WIDTH_NONE                : return "";
    default: 
        return NULL;
    }
}

const char* align2str(unsigned val)
{
    using namespace Brig;

    switch(val) 
    {
    case BRIG_ALIGNMENT_1:       return "";
    case BRIG_ALIGNMENT_2:       return "2";
    case BRIG_ALIGNMENT_4:       return "4";
    case BRIG_ALIGNMENT_8:       return "8";
    case BRIG_ALIGNMENT_16:      return "16";
    case BRIG_ALIGNMENT_32:      return "32";
    case BRIG_ALIGNMENT_64:      return "64";
    case BRIG_ALIGNMENT_128:     return "128";
    default : return NULL;
    }
}

unsigned align2num(unsigned val)
{
    using namespace Brig;

    switch(val) 
    {
    case BRIG_ALIGNMENT_1:       return 1;
    case BRIG_ALIGNMENT_2:       return 2;
    case BRIG_ALIGNMENT_4:       return 4;
    case BRIG_ALIGNMENT_8:       return 8;
    case BRIG_ALIGNMENT_16:      return 16;
    case BRIG_ALIGNMENT_32:      return 32;
    case BRIG_ALIGNMENT_64:      return 64;
    case BRIG_ALIGNMENT_128:     return 128;
    default : assert(false);     return -1;
    }
}

Brig::BrigAlignment num2align(unsigned val)
{
    using namespace Brig;

    switch(val) 
    {
    case 1:   return BRIG_ALIGNMENT_1;
    case 2:   return BRIG_ALIGNMENT_2;
    case 4:   return BRIG_ALIGNMENT_4;
    case 8:   return BRIG_ALIGNMENT_8;
    case 16:  return BRIG_ALIGNMENT_16;
    case 32:  return BRIG_ALIGNMENT_32;
    case 64:  return BRIG_ALIGNMENT_64;
    case 128: return BRIG_ALIGNMENT_128;
    default:  return BRIG_ALIGNMENT_NONE;
    }
}

Brig::BrigAlignment getNaturalAlignment(unsigned type)
{
    using namespace Brig;
    assert(typeX2str(type));

    switch(getTypeSize(type))
    {
    case 1:   return BRIG_ALIGNMENT_1;
    case 8:   return BRIG_ALIGNMENT_1;
    case 16:  return BRIG_ALIGNMENT_2;
    case 32:  return BRIG_ALIGNMENT_4;
    case 64:  return BRIG_ALIGNMENT_8;
    case 128: return BRIG_ALIGNMENT_16;
    default:  
        assert(false);
        return BRIG_ALIGNMENT_NONE;
    }
}

bool isValidAlignment(unsigned align, unsigned type)
{
    return align2num(getNaturalAlignment(type)) <= align2num(align);
}

const char* memoryFenceSeg2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_FENCE_BOTH         : return "both";
    case BRIG_MEMORY_FENCE_GLOBAL       : return "global";
    case BRIG_MEMORY_FENCE_GROUP        : return "group";
    case BRIG_MEMORY_FENCE_NONE         : return "none";
    default : return NULL;
    }
}

bool isImageInst(unsigned opcode)
{
    using namespace Brig;

    switch(opcode)
    {
    case BRIG_OPCODE_RDIMAGE:
    case BRIG_OPCODE_LDIMAGE:
    case BRIG_OPCODE_STIMAGE:
    case BRIG_OPCODE_ATOMICIMAGE:
    case BRIG_OPCODE_ATOMICIMAGENORET:
    case BRIG_OPCODE_QUERYIMAGEARRAY:
    case BRIG_OPCODE_QUERYIMAGEDEPTH:
    case BRIG_OPCODE_QUERYIMAGEFORMAT:
    case BRIG_OPCODE_QUERYIMAGEHEIGHT:
    case BRIG_OPCODE_QUERYIMAGEORDER:
    case BRIG_OPCODE_QUERYIMAGEWIDTH:
    case BRIG_OPCODE_QUERYSAMPLERBOUNDARY:
    case BRIG_OPCODE_QUERYSAMPLERCOORD:
    case BRIG_OPCODE_QUERYSAMPLERFILTER:
        return true;
    default: 
        return false;
    }
}

unsigned getType(Inst i)
{
    return i.brig()->type;
}

unsigned getSrcType(Inst i)
{
    using namespace Brig;

    switch(i.brig()->kind) 
    {
    case BRIG_INST_CVT:
        return InstCvt(i).sourceType();

    case BRIG_INST_CMP:
        return InstCmp(i).sourceType();

    case BRIG_INST_SEG_CVT:
        return InstSegCvt(i).sourceType();

    case BRIG_INST_SOURCE_TYPE:
        return InstSourceType(i).sourceType();

    case BRIG_INST_IMAGE:
        return InstImage(i).coordType();

    case BRIG_INST_LANE:
        return InstLane(i).sourceType();

    case BRIG_INST_ATOMIC_IMAGE:
        return InstAtomicImage(i).coordType();

    case BRIG_INST_SIGNAL:
        return InstSignal(i).signalType();

    default:
        return BRIG_TYPE_NONE;
    }
}

unsigned getImgType(Inst i)
{
    using namespace Brig;

    switch(i.brig()->kind) 
    {
    case BRIG_INST_IMAGE:
        return InstImage(i).imageType();

    case BRIG_INST_ATOMIC_IMAGE:
        return InstAtomicImage(i).imageType();

    default:
        return BRIG_TYPE_NONE;
    }
}

unsigned getSegment(Inst inst)
{
    assert(inst);
    if      (InstAddr   i = inst) return i.segment();
    else if (InstMem    i = inst) return i.segment();
    else if (InstSeg    i = inst) return i.segment();
    else if (InstSegCvt i = inst) return i.segment();
    else if (InstAtomic i = inst) return i.segment();
    else if (InstQueue  i = inst) return i.segment();
    else                          return Brig::BRIG_SEGMENT_NONE;
}

unsigned getPacking(Inst inst)
{
    assert(inst);

    if      (InstCmp i = inst) return i.pack();
    else if (InstMod i = inst) return i.pack();
    else                       return Brig::BRIG_PACK_NONE;
}

unsigned getEqClass(Inst inst)
{
    assert(inst);

    if      (InstAtomic i = inst)      return i.equivClass();
    else if (InstAtomicImage i = inst) return i.equivClass();
    else if (InstImage i = inst)       return i.equivClass();
    else if (InstMem i = inst)         return i.equivClass();

    assert(false);
    return 0;
}

bool isSatPacking(unsigned packing)
{
    using namespace Brig;

    switch(packing)
    {
    case BRIG_PACK_PP:
    case BRIG_PACK_PS:
    case BRIG_PACK_SP:
    case BRIG_PACK_SS:
    case BRIG_PACK_S: 
    case BRIG_PACK_P: 
        return false;

    case BRIG_PACK_PPSAT:
    case BRIG_PACK_PSSAT:
    case BRIG_PACK_SPSAT:
    case BRIG_PACK_SSSAT:
    case BRIG_PACK_SSAT: 
    case BRIG_PACK_PSAT: 
        return true;

    default: 
        assert(false);
        return false;
    }
}

bool isUnrPacking(unsigned packing)
{
    using namespace Brig;

    switch(packing)
    {
    case BRIG_PACK_S: 
    case BRIG_PACK_P: 
    case BRIG_PACK_SSAT: 
    case BRIG_PACK_PSAT: 
        return true;

    case BRIG_PACK_PP:
    case BRIG_PACK_PS:
    case BRIG_PACK_SP:
    case BRIG_PACK_SS:
    case BRIG_PACK_PPSAT:
    case BRIG_PACK_PSSAT:
    case BRIG_PACK_SPSAT:
    case BRIG_PACK_SSSAT:
        return false;

    default: 
        assert(false);
        return false;
    }
}

bool isBinPacking(unsigned packing)
{
    return !isUnrPacking(packing);
}

unsigned getPackedTypeDim(unsigned type)
{
    using namespace Brig;

    switch(type) 
    {
    case BRIG_TYPE_U16X2:
    case BRIG_TYPE_S16X2:
    case BRIG_TYPE_F16X2:
    case BRIG_TYPE_U32X2:
    case BRIG_TYPE_S32X2:
    case BRIG_TYPE_F32X2:
    case BRIG_TYPE_U64X2:
    case BRIG_TYPE_S64X2:
    case BRIG_TYPE_F64X2:  return 2;

    case BRIG_TYPE_U8X4:  
    case BRIG_TYPE_S8X4:  
    case BRIG_TYPE_U16X4:
    case BRIG_TYPE_S16X4:
    case BRIG_TYPE_F16X4:
    case BRIG_TYPE_U32X4:
    case BRIG_TYPE_S32X4:
    case BRIG_TYPE_F32X4:  return 4;

    case BRIG_TYPE_U8X8: 
    case BRIG_TYPE_S8X8: 
    case BRIG_TYPE_U16X8:
    case BRIG_TYPE_S16X8:
    case BRIG_TYPE_F16X8:  return 8;

    case BRIG_TYPE_U8X16:
    case BRIG_TYPE_S8X16:  return 16;

    default:               return 0;
    }
}

char getPackingControl(unsigned srcOperandIdx, unsigned packing)
{
    assert(srcOperandIdx == 0 || srcOperandIdx == 1);

    using namespace Brig;

    const char* ctl;
    switch(packing) {
    case BRIG_PACK_NONE:    ctl = "  "; break;
    case BRIG_PACK_P:       ctl = "p "; break;
    case BRIG_PACK_PP:      ctl = "pp"; break;
    case BRIG_PACK_PPSAT:   ctl = "pp"; break;
    case BRIG_PACK_PS:      ctl = "ps"; break;
    case BRIG_PACK_PSAT:    ctl = "p "; break;
    case BRIG_PACK_PSSAT:   ctl = "ps"; break;
    case BRIG_PACK_S:       ctl = "s "; break;
    case BRIG_PACK_SP:      ctl = "sp"; break;
    case BRIG_PACK_SPSAT:   ctl = "sp"; break;
    case BRIG_PACK_SS:      ctl = "ss"; break;
    case BRIG_PACK_SSAT:    ctl = "s "; break;
    case BRIG_PACK_SSSAT:   ctl = "ss"; break;
    default:                ctl = "  "; break;
    }

    return ctl[srcOperandIdx];
}

unsigned getPackedDstDim(unsigned type, unsigned packing)
{
    assert(isPackedType(type));

    return (getPackingControl(0, packing) == 'p' || getPackingControl(1, packing) == 'p')? getPackedTypeDim(type) : 1;
}

unsigned expandSubwordType(unsigned type)
{
    using namespace Brig;

    switch(type) 
    {
    case BRIG_TYPE_B1:  assert(false);

    case BRIG_TYPE_B8:
    case BRIG_TYPE_B16: return BRIG_TYPE_B32;

    case BRIG_TYPE_U8:
    case BRIG_TYPE_U16: return BRIG_TYPE_U32;

    case BRIG_TYPE_S8:
    case BRIG_TYPE_S16: return BRIG_TYPE_S32;

    default:            return type;
    }
}

unsigned packedType2elementType(unsigned type)
{
    using namespace Brig;

    switch(type) 
    {
    case BRIG_TYPE_U8X4:
    case BRIG_TYPE_U8X8:
    case BRIG_TYPE_U8X16:   return BRIG_TYPE_U8;

    case BRIG_TYPE_U16X2:
    case BRIG_TYPE_U16X4:
    case BRIG_TYPE_U16X8:   return BRIG_TYPE_U16;

    case BRIG_TYPE_U32X2:
    case BRIG_TYPE_U32X4:   return BRIG_TYPE_U32;

    case BRIG_TYPE_U64X2:   return BRIG_TYPE_U64;

    case BRIG_TYPE_S8X4:
    case BRIG_TYPE_S8X8:
    case BRIG_TYPE_S8X16:   return BRIG_TYPE_S8;

    case BRIG_TYPE_S16X2:
    case BRIG_TYPE_S16X4:
    case BRIG_TYPE_S16X8:   return BRIG_TYPE_S16;

    case BRIG_TYPE_S32X2:
    case BRIG_TYPE_S32X4:   return BRIG_TYPE_S32;

    case BRIG_TYPE_S64X2:   return BRIG_TYPE_S64;

    case BRIG_TYPE_F16X2:
    case BRIG_TYPE_F16X4:
    case BRIG_TYPE_F16X8:   return BRIG_TYPE_F16;

    case BRIG_TYPE_F32X2:
    case BRIG_TYPE_F32X4:   return BRIG_TYPE_F32;

    case BRIG_TYPE_F64X2:   return BRIG_TYPE_F64;

    default:                
        assert(false);
        return BRIG_TYPE_NONE;
    }
}

unsigned packedType2baseType(unsigned type)
{
    return expandSubwordType(packedType2elementType(type));
}

} // end namespace

