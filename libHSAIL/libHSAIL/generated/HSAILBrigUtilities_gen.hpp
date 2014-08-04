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
unsigned align2num(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ALIGNMENT_1               : return 1;
    case BRIG_ALIGNMENT_128             : return 128;
    case BRIG_ALIGNMENT_16              : return 16;
    case BRIG_ALIGNMENT_2               : return 2;
    case BRIG_ALIGNMENT_256             : return 256;
    case BRIG_ALIGNMENT_32              : return 32;
    case BRIG_ALIGNMENT_4               : return 4;
    case BRIG_ALIGNMENT_64              : return 64;
    case BRIG_ALIGNMENT_8               : return 8;
    default : assert(false); return -1;
    }
}

const char* align2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ALIGNMENT_1               : return "";
    case BRIG_ALIGNMENT_128             : return "128";
    case BRIG_ALIGNMENT_16              : return "16";
    case BRIG_ALIGNMENT_2               : return "2";
    case BRIG_ALIGNMENT_256             : return "256";
    case BRIG_ALIGNMENT_32              : return "32";
    case BRIG_ALIGNMENT_4               : return "4";
    case BRIG_ALIGNMENT_64              : return "64";
    case BRIG_ALIGNMENT_8               : return "8";
    default : return NULL;
    }
}

Brig::BrigAlignment num2align(uint64_t arg) {
  using namespace Brig;
  switch( arg ) {
    case 1                              : return BRIG_ALIGNMENT_1;
    case 128                            : return BRIG_ALIGNMENT_128;
    case 16                             : return BRIG_ALIGNMENT_16;
    case 2                              : return BRIG_ALIGNMENT_2;
    case 256                            : return BRIG_ALIGNMENT_256;
    case 32                             : return BRIG_ALIGNMENT_32;
    case 4                              : return BRIG_ALIGNMENT_4;
    case 64                             : return BRIG_ALIGNMENT_64;
    case 8                              : return BRIG_ALIGNMENT_8;
    default : return BRIG_ALIGNMENT_LAST;
    }
}

const char* allocation2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ALLOCATION_AGENT          : return "agent";
    case BRIG_ALLOCATION_AUTOMATIC      : return "automatic";
    case BRIG_ALLOCATION_NONE           : return "";
    case BRIG_ALLOCATION_PROGRAM        : return "program";
    default : return NULL;
    }
}

const char* atomicOperation2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ATOMIC_ADD                : return "add";
    case BRIG_ATOMIC_AND                : return "and";
    case BRIG_ATOMIC_CAS                : return "cas";
    case BRIG_ATOMIC_EXCH               : return "exch";
    case BRIG_ATOMIC_LD                 : return "ld";
    case BRIG_ATOMIC_MAX                : return "max";
    case BRIG_ATOMIC_MIN                : return "min";
    case BRIG_ATOMIC_OR                 : return "or";
    case BRIG_ATOMIC_ST                 : return "st";
    case BRIG_ATOMIC_SUB                : return "sub";
    case BRIG_ATOMIC_WAITTIMEOUT_EQ     : return "waittimeout_eq";
    case BRIG_ATOMIC_WAITTIMEOUT_GTE    : return "waittimeout_gte";
    case BRIG_ATOMIC_WAITTIMEOUT_LT     : return "waittimeout_lt";
    case BRIG_ATOMIC_WAITTIMEOUT_NE     : return "waittimeout_ne";
    case BRIG_ATOMIC_WAIT_EQ            : return "wait_eq";
    case BRIG_ATOMIC_WAIT_GTE           : return "wait_gte";
    case BRIG_ATOMIC_WAIT_LT            : return "wait_lt";
    case BRIG_ATOMIC_WAIT_NE            : return "wait_ne";
    case BRIG_ATOMIC_WRAPDEC            : return "wrapdec";
    case BRIG_ATOMIC_WRAPINC            : return "wrapinc";
    case BRIG_ATOMIC_XOR                : return "xor";
    default : return NULL;
    }
}

const char* compareOperation2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_COMPARE_EQ                : return "eq";
    case BRIG_COMPARE_EQU               : return "equ";
    case BRIG_COMPARE_GE                : return "ge";
    case BRIG_COMPARE_GEU               : return "geu";
    case BRIG_COMPARE_GT                : return "gt";
    case BRIG_COMPARE_GTU               : return "gtu";
    case BRIG_COMPARE_LE                : return "le";
    case BRIG_COMPARE_LEU               : return "leu";
    case BRIG_COMPARE_LT                : return "lt";
    case BRIG_COMPARE_LTU               : return "ltu";
    case BRIG_COMPARE_NAN               : return "nan";
    case BRIG_COMPARE_NE                : return "ne";
    case BRIG_COMPARE_NEU               : return "neu";
    case BRIG_COMPARE_NUM               : return "num";
    case BRIG_COMPARE_SEQ               : return "seq";
    case BRIG_COMPARE_SEQU              : return "sequ";
    case BRIG_COMPARE_SGE               : return "sge";
    case BRIG_COMPARE_SGEU              : return "sgeu";
    case BRIG_COMPARE_SGT               : return "sgt";
    case BRIG_COMPARE_SGTU              : return "sgtu";
    case BRIG_COMPARE_SLE               : return "sle";
    case BRIG_COMPARE_SLEU              : return "sleu";
    case BRIG_COMPARE_SLT               : return "slt";
    case BRIG_COMPARE_SLTU              : return "sltu";
    case BRIG_COMPARE_SNAN              : return "snan";
    case BRIG_COMPARE_SNE               : return "sne";
    case BRIG_COMPARE_SNEU              : return "sneu";
    case BRIG_COMPARE_SNUM              : return "snum";
    default : return NULL;
    }
}

const char* controlDirective2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_CONTROL_ENABLEBREAKEXCEPTIONS : return "enablebreakexceptions";
    case BRIG_CONTROL_ENABLEDETECTEXCEPTIONS : return "enabledetectexceptions";
    case BRIG_CONTROL_MAXDYNAMICGROUPSIZE : return "maxdynamicgroupsize";
    case BRIG_CONTROL_MAXFLATGRIDSIZE   : return "maxflatgridsize";
    case BRIG_CONTROL_MAXFLATWORKGROUPSIZE : return "maxflatworkgroupsize";
    case BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU : return "requestedworkgroupspercu";
    case BRIG_CONTROL_REQUIREDDIM       : return "requireddim";
    case BRIG_CONTROL_REQUIREDGRIDSIZE  : return "requiredgridsize";
    case BRIG_CONTROL_REQUIREDWORKGROUPSIZE : return "requiredworkgroupsize";
    case BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS : return "requirenopartialworkgroups";
    default : return NULL;
    }
}

const char* imageChannelOrder2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_CHANNEL_ORDER_A           : return "a";
    case BRIG_CHANNEL_ORDER_ABGR        : return "abgr";
    case BRIG_CHANNEL_ORDER_ARGB        : return "argb";
    case BRIG_CHANNEL_ORDER_BGRA        : return "bgra";
    case BRIG_CHANNEL_ORDER_DEPTH       : return "depth";
    case BRIG_CHANNEL_ORDER_DEPTH_STENCIL : return "depth_stencil";
    case BRIG_CHANNEL_ORDER_INTENSITY   : return "intensity";
    case BRIG_CHANNEL_ORDER_LUMINANCE   : return "luminance";
    case BRIG_CHANNEL_ORDER_R           : return "r";
    case BRIG_CHANNEL_ORDER_RA          : return "ra";
    case BRIG_CHANNEL_ORDER_RG          : return "rg";
    case BRIG_CHANNEL_ORDER_RGB         : return "rgb";
    case BRIG_CHANNEL_ORDER_RGBA        : return "rgba";
    case BRIG_CHANNEL_ORDER_RGBX        : return "rgbx";
    case BRIG_CHANNEL_ORDER_RGX         : return "rgx";
    case BRIG_CHANNEL_ORDER_RX          : return "rx";
    case BRIG_CHANNEL_ORDER_SBGRA       : return "sbgra";
    case BRIG_CHANNEL_ORDER_SRGB        : return "srgb";
    case BRIG_CHANNEL_ORDER_SRGBA       : return "srgba";
    case BRIG_CHANNEL_ORDER_SRGBX       : return "srgbx";
    case BRIG_CHANNEL_ORDER_UNKNOWN     : return "";
    default : return NULL;
    }
}

const char* imageChannelType2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_CHANNEL_TYPE_FLOAT        : return "float";
    case BRIG_CHANNEL_TYPE_HALF_FLOAT   : return "half_float";
    case BRIG_CHANNEL_TYPE_SIGNED_INT16 : return "signed_int16";
    case BRIG_CHANNEL_TYPE_SIGNED_INT32 : return "signed_int32";
    case BRIG_CHANNEL_TYPE_SIGNED_INT8  : return "signed_int8";
    case BRIG_CHANNEL_TYPE_SNORM_INT16  : return "snorm_int16";
    case BRIG_CHANNEL_TYPE_SNORM_INT8   : return "snorm_int8";
    case BRIG_CHANNEL_TYPE_UNKNOWN      : return "";
    case BRIG_CHANNEL_TYPE_UNORM_INT16  : return "unorm_int16";
    case BRIG_CHANNEL_TYPE_UNORM_INT24  : return "unorm_int24";
    case BRIG_CHANNEL_TYPE_UNORM_INT8   : return "unorm_int8";
    case BRIG_CHANNEL_TYPE_UNORM_INT_101010 : return "unorm_int_101010";
    case BRIG_CHANNEL_TYPE_UNORM_SHORT_555 : return "unorm_short_555";
    case BRIG_CHANNEL_TYPE_UNORM_SHORT_565 : return "unorm_short_565";
    case BRIG_CHANNEL_TYPE_UNSIGNED_INT16 : return "unsigned_int16";
    case BRIG_CHANNEL_TYPE_UNSIGNED_INT32 : return "unsigned_int32";
    case BRIG_CHANNEL_TYPE_UNSIGNED_INT8 : return "unsigned_int8";
    default : return NULL;
    }
}

const char* imageGeometry2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_GEOMETRY_1D               : return "1d";
    case BRIG_GEOMETRY_1DA              : return "1da";
    case BRIG_GEOMETRY_1DB              : return "1db";
    case BRIG_GEOMETRY_2D               : return "2d";
    case BRIG_GEOMETRY_2DA              : return "2da";
    case BRIG_GEOMETRY_2DADEPTH         : return "2dadepth";
    case BRIG_GEOMETRY_2DDEPTH          : return "2ddepth";
    case BRIG_GEOMETRY_3D               : return "3d";
    case BRIG_GEOMETRY_UNKNOWN          : return "";
    default : return NULL;
    }
}

const char* imageQuery2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_IMAGE_QUERY_ARRAY         : return "array";
    case BRIG_IMAGE_QUERY_CHANNELORDER  : return "channelorder";
    case BRIG_IMAGE_QUERY_CHANNELTYPE   : return "channeltype";
    case BRIG_IMAGE_QUERY_DEPTH         : return "depth";
    case BRIG_IMAGE_QUERY_HEIGHT        : return "height";
    case BRIG_IMAGE_QUERY_WIDTH         : return "width";
    default : return NULL;
    }
}

const char* kinds2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END : return "DirectiveArgBlockEnd";
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START : return "DirectiveArgBlockStart";
    case BRIG_KIND_DIRECTIVE_COMMENT    : return "DirectiveComment";
    case BRIG_KIND_DIRECTIVE_CONTROL    : return "DirectiveControl";
    case BRIG_KIND_DIRECTIVE_EXTENSION  : return "DirectiveExtension";
    case BRIG_KIND_DIRECTIVE_FBARRIER   : return "DirectiveFbarrier";
    case BRIG_KIND_DIRECTIVE_FUNCTION   : return "DirectiveFunction";
    case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION : return "DirectiveIndirectFunction";
    case BRIG_KIND_DIRECTIVE_KERNEL     : return "DirectiveKernel";
    case BRIG_KIND_DIRECTIVE_LABEL      : return "DirectiveLabel";
    case BRIG_KIND_DIRECTIVE_LOC        : return "DirectiveLoc";
    case BRIG_KIND_DIRECTIVE_PRAGMA     : return "DirectivePragma";
    case BRIG_KIND_DIRECTIVE_SIGNATURE  : return "DirectiveSignature";
    case BRIG_KIND_DIRECTIVE_VARIABLE   : return "DirectiveVariable";
    case BRIG_KIND_DIRECTIVE_VERSION    : return "DirectiveVersion";
    case BRIG_KIND_INST_ADDR            : return "InstAddr";
    case BRIG_KIND_INST_ATOMIC          : return "InstAtomic";
    case BRIG_KIND_INST_BASIC           : return "InstBasic";
    case BRIG_KIND_INST_BR              : return "InstBr";
    case BRIG_KIND_INST_CMP             : return "InstCmp";
    case BRIG_KIND_INST_CVT             : return "InstCvt";
    case BRIG_KIND_INST_IMAGE           : return "InstImage";
    case BRIG_KIND_INST_LANE            : return "InstLane";
    case BRIG_KIND_INST_MEM             : return "InstMem";
    case BRIG_KIND_INST_MEM_FENCE       : return "InstMemFence";
    case BRIG_KIND_INST_MOD             : return "InstMod";
    case BRIG_KIND_INST_QUERY_IMAGE     : return "InstQueryImage";
    case BRIG_KIND_INST_QUERY_SAMPLER   : return "InstQuerySampler";
    case BRIG_KIND_INST_QUEUE           : return "InstQueue";
    case BRIG_KIND_INST_SEG             : return "InstSeg";
    case BRIG_KIND_INST_SEG_CVT         : return "InstSegCvt";
    case BRIG_KIND_INST_SIGNAL          : return "InstSignal";
    case BRIG_KIND_INST_SOURCE_TYPE     : return "InstSourceType";
    case BRIG_KIND_OPERAND_ADDRESS      : return "OperandAddress";
    case BRIG_KIND_OPERAND_CODE_LIST    : return "OperandCodeList";
    case BRIG_KIND_OPERAND_CODE_REF     : return "OperandCodeRef";
    case BRIG_KIND_OPERAND_DATA         : return "OperandData";
    case BRIG_KIND_OPERAND_IMAGE_PROPERTIES : return "OperandImageProperties";
    case BRIG_KIND_OPERAND_OPERAND_LIST : return "OperandOperandList";
    case BRIG_KIND_OPERAND_REG          : return "OperandReg";
    case BRIG_KIND_OPERAND_SAMPLER_PROPERTIES : return "OperandSamplerProperties";
    case BRIG_KIND_OPERAND_STRING       : return "OperandString";
    case BRIG_KIND_OPERAND_WAVESIZE     : return "OperandWavesize";
    default : return NULL;
    }
}

int size_of_brig_record(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END : return sizeof(BrigDirectiveArgBlockEnd);
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START : return sizeof(BrigDirectiveArgBlockStart);
    case BRIG_KIND_DIRECTIVE_COMMENT    : return sizeof(BrigDirectiveComment);
    case BRIG_KIND_DIRECTIVE_CONTROL    : return sizeof(BrigDirectiveControl);
    case BRIG_KIND_DIRECTIVE_EXTENSION  : return sizeof(BrigDirectiveExtension);
    case BRIG_KIND_DIRECTIVE_FBARRIER   : return sizeof(BrigDirectiveFbarrier);
    case BRIG_KIND_DIRECTIVE_FUNCTION   : return sizeof(BrigDirectiveFunction);
    case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION : return sizeof(BrigDirectiveIndirectFunction);
    case BRIG_KIND_DIRECTIVE_KERNEL     : return sizeof(BrigDirectiveKernel);
    case BRIG_KIND_DIRECTIVE_LABEL      : return sizeof(BrigDirectiveLabel);
    case BRIG_KIND_DIRECTIVE_LOC        : return sizeof(BrigDirectiveLoc);
    case BRIG_KIND_DIRECTIVE_PRAGMA     : return sizeof(BrigDirectivePragma);
    case BRIG_KIND_DIRECTIVE_SIGNATURE  : return sizeof(BrigDirectiveSignature);
    case BRIG_KIND_DIRECTIVE_VARIABLE   : return sizeof(BrigDirectiveVariable);
    case BRIG_KIND_DIRECTIVE_VERSION    : return sizeof(BrigDirectiveVersion);
    case BRIG_KIND_INST_ADDR            : return sizeof(BrigInstAddr);
    case BRIG_KIND_INST_ATOMIC          : return sizeof(BrigInstAtomic);
    case BRIG_KIND_INST_BASIC           : return sizeof(BrigInstBasic);
    case BRIG_KIND_INST_BR              : return sizeof(BrigInstBr);
    case BRIG_KIND_INST_CMP             : return sizeof(BrigInstCmp);
    case BRIG_KIND_INST_CVT             : return sizeof(BrigInstCvt);
    case BRIG_KIND_INST_IMAGE           : return sizeof(BrigInstImage);
    case BRIG_KIND_INST_LANE            : return sizeof(BrigInstLane);
    case BRIG_KIND_INST_MEM             : return sizeof(BrigInstMem);
    case BRIG_KIND_INST_MEM_FENCE       : return sizeof(BrigInstMemFence);
    case BRIG_KIND_INST_MOD             : return sizeof(BrigInstMod);
    case BRIG_KIND_INST_QUERY_IMAGE     : return sizeof(BrigInstQueryImage);
    case BRIG_KIND_INST_QUERY_SAMPLER   : return sizeof(BrigInstQuerySampler);
    case BRIG_KIND_INST_QUEUE           : return sizeof(BrigInstQueue);
    case BRIG_KIND_INST_SEG             : return sizeof(BrigInstSeg);
    case BRIG_KIND_INST_SEG_CVT         : return sizeof(BrigInstSegCvt);
    case BRIG_KIND_INST_SIGNAL          : return sizeof(BrigInstSignal);
    case BRIG_KIND_INST_SOURCE_TYPE     : return sizeof(BrigInstSourceType);
    case BRIG_KIND_OPERAND_ADDRESS      : return sizeof(BrigOperandAddress);
    case BRIG_KIND_OPERAND_CODE_LIST    : return sizeof(BrigOperandCodeList);
    case BRIG_KIND_OPERAND_CODE_REF     : return sizeof(BrigOperandCodeRef);
    case BRIG_KIND_OPERAND_DATA         : return sizeof(BrigOperandData);
    case BRIG_KIND_OPERAND_IMAGE_PROPERTIES : return sizeof(BrigOperandImageProperties);
    case BRIG_KIND_OPERAND_OPERAND_LIST : return sizeof(BrigOperandOperandList);
    case BRIG_KIND_OPERAND_REG          : return sizeof(BrigOperandReg);
    case BRIG_KIND_OPERAND_SAMPLER_PROPERTIES : return sizeof(BrigOperandSamplerProperties);
    case BRIG_KIND_OPERAND_STRING       : return sizeof(BrigOperandString);
    case BRIG_KIND_OPERAND_WAVESIZE     : return sizeof(BrigOperandWavesize);
    default : return -1;
    }
}

bool isToplevelOnly(Directive d) {
  using namespace Brig;
  switch( d.brig()->kind ) {
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END : return false;
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START : return false;
    case BRIG_KIND_DIRECTIVE_COMMENT    : return false;
    case BRIG_KIND_DIRECTIVE_CONTROL    : return false;
    case BRIG_KIND_DIRECTIVE_EXTENSION  : return true;
    case BRIG_KIND_DIRECTIVE_FBARRIER   : return false;
    case BRIG_KIND_DIRECTIVE_FUNCTION   : return true;
    case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION : return true;
    case BRIG_KIND_DIRECTIVE_KERNEL     : return true;
    case BRIG_KIND_DIRECTIVE_LABEL      : return false;
    case BRIG_KIND_DIRECTIVE_LOC        : return false;
    case BRIG_KIND_DIRECTIVE_PRAGMA     : return false;
    case BRIG_KIND_DIRECTIVE_SIGNATURE  : return true;
    case BRIG_KIND_DIRECTIVE_VARIABLE   : return false;
    case BRIG_KIND_DIRECTIVE_VERSION    : return true;
    case BRIG_KIND_INST_ADDR            : return false;
    case BRIG_KIND_INST_ATOMIC          : return false;
    case BRIG_KIND_INST_BASIC           : return false;
    case BRIG_KIND_INST_BR              : return false;
    case BRIG_KIND_INST_CMP             : return false;
    case BRIG_KIND_INST_CVT             : return false;
    case BRIG_KIND_INST_IMAGE           : return false;
    case BRIG_KIND_INST_LANE            : return false;
    case BRIG_KIND_INST_MEM             : return false;
    case BRIG_KIND_INST_MEM_FENCE       : return false;
    case BRIG_KIND_INST_MOD             : return false;
    case BRIG_KIND_INST_QUERY_IMAGE     : return false;
    case BRIG_KIND_INST_QUERY_SAMPLER   : return false;
    case BRIG_KIND_INST_QUEUE           : return false;
    case BRIG_KIND_INST_SEG             : return false;
    case BRIG_KIND_INST_SEG_CVT         : return false;
    case BRIG_KIND_INST_SIGNAL          : return false;
    case BRIG_KIND_INST_SOURCE_TYPE     : return false;
    case BRIG_KIND_OPERAND_ADDRESS      : return false;
    case BRIG_KIND_OPERAND_CODE_LIST    : return false;
    case BRIG_KIND_OPERAND_CODE_REF     : return false;
    case BRIG_KIND_OPERAND_DATA         : return false;
    case BRIG_KIND_OPERAND_IMAGE_PROPERTIES : return false;
    case BRIG_KIND_OPERAND_OPERAND_LIST : return false;
    case BRIG_KIND_OPERAND_REG          : return false;
    case BRIG_KIND_OPERAND_SAMPLER_PROPERTIES : return false;
    case BRIG_KIND_OPERAND_STRING       : return false;
    case BRIG_KIND_OPERAND_WAVESIZE     : return false;
    default : assert(false); return false;
    }
}

bool isBodyOnly(Directive d) {
  using namespace Brig;
  switch( d.brig()->kind ) {
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END : return true;
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START : return true;
    case BRIG_KIND_DIRECTIVE_COMMENT    : return false;
    case BRIG_KIND_DIRECTIVE_CONTROL    : return true;
    case BRIG_KIND_DIRECTIVE_EXTENSION  : return false;
    case BRIG_KIND_DIRECTIVE_FBARRIER   : return false;
    case BRIG_KIND_DIRECTIVE_FUNCTION   : return false;
    case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION : return false;
    case BRIG_KIND_DIRECTIVE_KERNEL     : return false;
    case BRIG_KIND_DIRECTIVE_LABEL      : return true;
    case BRIG_KIND_DIRECTIVE_LOC        : return false;
    case BRIG_KIND_DIRECTIVE_PRAGMA     : return false;
    case BRIG_KIND_DIRECTIVE_SIGNATURE  : return false;
    case BRIG_KIND_DIRECTIVE_VARIABLE   : return false;
    case BRIG_KIND_DIRECTIVE_VERSION    : return false;
    case BRIG_KIND_INST_ADDR            : return false;
    case BRIG_KIND_INST_ATOMIC          : return false;
    case BRIG_KIND_INST_BASIC           : return false;
    case BRIG_KIND_INST_BR              : return false;
    case BRIG_KIND_INST_CMP             : return false;
    case BRIG_KIND_INST_CVT             : return false;
    case BRIG_KIND_INST_IMAGE           : return false;
    case BRIG_KIND_INST_LANE            : return false;
    case BRIG_KIND_INST_MEM             : return false;
    case BRIG_KIND_INST_MEM_FENCE       : return false;
    case BRIG_KIND_INST_MOD             : return false;
    case BRIG_KIND_INST_QUERY_IMAGE     : return false;
    case BRIG_KIND_INST_QUERY_SAMPLER   : return false;
    case BRIG_KIND_INST_QUEUE           : return false;
    case BRIG_KIND_INST_SEG             : return false;
    case BRIG_KIND_INST_SEG_CVT         : return false;
    case BRIG_KIND_INST_SIGNAL          : return false;
    case BRIG_KIND_INST_SOURCE_TYPE     : return false;
    case BRIG_KIND_OPERAND_ADDRESS      : return false;
    case BRIG_KIND_OPERAND_CODE_LIST    : return false;
    case BRIG_KIND_OPERAND_CODE_REF     : return false;
    case BRIG_KIND_OPERAND_DATA         : return false;
    case BRIG_KIND_OPERAND_IMAGE_PROPERTIES : return false;
    case BRIG_KIND_OPERAND_OPERAND_LIST : return false;
    case BRIG_KIND_OPERAND_REG          : return false;
    case BRIG_KIND_OPERAND_SAMPLER_PROPERTIES : return false;
    case BRIG_KIND_OPERAND_STRING       : return false;
    case BRIG_KIND_OPERAND_WAVESIZE     : return false;
    default : assert(false); return false;
    }
}

const char* linkage2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_LINKAGE_ARG               : return "arg";
    case BRIG_LINKAGE_FUNCTION          : return "function";
    case BRIG_LINKAGE_MODULE            : return "module";
    case BRIG_LINKAGE_NONE              : return "";
    case BRIG_LINKAGE_PROGRAM           : return "program";
    default : return NULL;
    }
}

const char* machineModel2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MACHINE_LARGE             : return "$large";
    case BRIG_MACHINE_SMALL             : return "$small";
    default : return NULL;
    }
}

const char* memoryFenceSegments2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_FENCE_SEGMENT_GLOBAL : return "global";
    case BRIG_MEMORY_FENCE_SEGMENT_GROUP : return "group";
    case BRIG_MEMORY_FENCE_SEGMENT_IMAGE : return "image";
    default : return NULL;
    }
}

const char* memoryOrder2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_ORDER_NONE         : return "";
    case BRIG_MEMORY_ORDER_RELAXED      : return "rlx";
    case BRIG_MEMORY_ORDER_SC_ACQUIRE   : return "scacq";
    case BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE : return "scar";
    case BRIG_MEMORY_ORDER_SC_RELEASE   : return "screl";
    default : return NULL;
    }
}

const char* memoryScope2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_SCOPE_COMPONENT    : return "cmp";
    case BRIG_MEMORY_SCOPE_NONE         : return "";
    case BRIG_MEMORY_SCOPE_SYSTEM       : return "sys";
    case BRIG_MEMORY_SCOPE_WAVEFRONT    : return "wv";
    case BRIG_MEMORY_SCOPE_WORKGROUP    : return "wg";
    case BRIG_MEMORY_SCOPE_WORKITEM     : return "wi";
    default : return NULL;
    }
}

const char* memoryScope22str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_SCOPE2_COMPONENT   : return "cmp";
    case BRIG_MEMORY_SCOPE2_NONE        : return "";
    case BRIG_MEMORY_SCOPE2_SYSTEM      : return "sys";
    case BRIG_MEMORY_SCOPE2_WAVEFRONT   : return "wv";
    case BRIG_MEMORY_SCOPE2_WORKGROUP   : return "wg";
    case BRIG_MEMORY_SCOPE2_WORKITEM    : return "wi";
    default : return NULL;
    }
}

const char* opcode2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ABS                : return "abs";
    case BRIG_OPCODE_ACTIVELANECOUNT    : return "activelanecount";
    case BRIG_OPCODE_ACTIVELANEID       : return "activelaneid";
    case BRIG_OPCODE_ACTIVELANEMASK     : return "activelanemask";
    case BRIG_OPCODE_ACTIVELANESHUFFLE  : return "activelaneshuffle";
    case BRIG_OPCODE_ADD                : return "add";
    case BRIG_OPCODE_ADDQUEUEWRITEINDEX : return "addqueuewriteindex";
    case BRIG_OPCODE_AGENTCOUNT         : return "agentcount";
    case BRIG_OPCODE_AGENTID            : return "agentid";
    case BRIG_OPCODE_ALLOCA             : return "alloca";
    case BRIG_OPCODE_AND                : return "and";
    case BRIG_OPCODE_ARRIVEFBAR         : return "arrivefbar";
    case BRIG_OPCODE_ATOMIC             : return "atomic";
    case BRIG_OPCODE_ATOMICNORET        : return "atomicnoret";
    case BRIG_OPCODE_BARRIER            : return "barrier";
    case BRIG_OPCODE_BITALIGN           : return "bitalign";
    case BRIG_OPCODE_BITEXTRACT         : return "bitextract";
    case BRIG_OPCODE_BITINSERT          : return "bitinsert";
    case BRIG_OPCODE_BITMASK            : return "bitmask";
    case BRIG_OPCODE_BITREV             : return "bitrev";
    case BRIG_OPCODE_BITSELECT          : return "bitselect";
    case BRIG_OPCODE_BORROW             : return "borrow";
    case BRIG_OPCODE_BR                 : return "br";
    case BRIG_OPCODE_BYTEALIGN          : return "bytealign";
    case BRIG_OPCODE_CALL               : return "call";
    case BRIG_OPCODE_CARRY              : return "carry";
    case BRIG_OPCODE_CASQUEUEWRITEINDEX : return "casqueuewriteindex";
    case BRIG_OPCODE_CBR                : return "cbr";
    case BRIG_OPCODE_CEIL               : return "ceil";
    case BRIG_OPCODE_CLASS              : return "class";
    case BRIG_OPCODE_CLEARDETECTEXCEPT  : return "cleardetectexcept";
    case BRIG_OPCODE_CLOCK              : return "clock";
    case BRIG_OPCODE_CMOV               : return "cmov";
    case BRIG_OPCODE_CMP                : return "cmp";
    case BRIG_OPCODE_COMBINE            : return "combine";
    case BRIG_OPCODE_COPYSIGN           : return "copysign";
    case BRIG_OPCODE_CUID               : return "cuid";
    case BRIG_OPCODE_CURRENTWORKGROUPSIZE : return "currentworkgroupsize";
    case BRIG_OPCODE_CVT                : return "cvt";
    case BRIG_OPCODE_DEBUGTRAP          : return "debugtrap";
    case BRIG_OPCODE_DIM                : return "dim";
    case BRIG_OPCODE_DIV                : return "div";
    case BRIG_OPCODE_EXPAND             : return "expand";
    case BRIG_OPCODE_FIRSTBIT           : return "firstbit";
    case BRIG_OPCODE_FLOOR              : return "floor";
    case BRIG_OPCODE_FMA                : return "fma";
    case BRIG_OPCODE_FRACT              : return "fract";
    case BRIG_OPCODE_FTOS               : return "ftos";
    case BRIG_OPCODE_GCNAPPEND          : return "gcn_atomic_append";
    case BRIG_OPCODE_GCNATOMIC          : return "gcn_atomic";
    case BRIG_OPCODE_GCNATOMICNORET     : return "gcn_atomicNoRet";
    case BRIG_OPCODE_GCNB32XCHG         : return "gcn_b32xchg";
    case BRIG_OPCODE_GCNB4XCHG          : return "gcn_b4xchg";
    case BRIG_OPCODE_GCNBFM             : return "gcn_bfm";
    case BRIG_OPCODE_GCNCONSUME         : return "gcn_atomic_consume";
    case BRIG_OPCODE_GCNFLDEXP          : return "gcn_fldexp";
    case BRIG_OPCODE_GCNFREXP_EXP       : return "gcn_frexp_exp";
    case BRIG_OPCODE_GCNFREXP_MANT      : return "gcn_frexp_mant";
    case BRIG_OPCODE_GCNLD              : return "gcn_ld";
    case BRIG_OPCODE_GCNMADS            : return "gcn_mads";
    case BRIG_OPCODE_GCNMADU            : return "gcn_madu";
    case BRIG_OPCODE_GCNMAX             : return "gcn_max";
    case BRIG_OPCODE_GCNMAX3            : return "gcn_max3";
    case BRIG_OPCODE_GCNMED3            : return "gcn_med3";
    case BRIG_OPCODE_GCNMIN             : return "gcn_min";
    case BRIG_OPCODE_GCNMIN3            : return "gcn_min3";
    case BRIG_OPCODE_GCNMQSAD           : return "gcn_mqsad";
    case BRIG_OPCODE_GCNMQSAD4          : return "gcn_mqsad4";
    case BRIG_OPCODE_GCNMSAD            : return "gcn_msad";
    case BRIG_OPCODE_GCNPRIORITY        : return "gcn_priority";
    case BRIG_OPCODE_GCNQSAD            : return "gcn_qsad";
    case BRIG_OPCODE_GCNREGIONALLOC     : return "gcn_region_alloc";
    case BRIG_OPCODE_GCNSADD            : return "gcn_sadd";
    case BRIG_OPCODE_GCNSADW            : return "gcn_sadw";
    case BRIG_OPCODE_GCNSLEEP           : return "gcn_sleep";
    case BRIG_OPCODE_GCNST              : return "gcn_st";
    case BRIG_OPCODE_GCNTRIG_PREOP      : return "gcn_trig_preop";
    case BRIG_OPCODE_GETDETECTEXCEPT    : return "getdetectexcept";
    case BRIG_OPCODE_GRIDGROUPS         : return "gridgroups";
    case BRIG_OPCODE_GRIDSIZE           : return "gridsize";
    case BRIG_OPCODE_GROUPBASEPTR       : return "groupbaseptr";
    case BRIG_OPCODE_ICALL              : return "icall";
    case BRIG_OPCODE_INITFBAR           : return "initfbar";
    case BRIG_OPCODE_JOINFBAR           : return "joinfbar";
    case BRIG_OPCODE_KERNARGBASEPTR     : return "kernargbaseptr";
    case BRIG_OPCODE_LANEID             : return "laneid";
    case BRIG_OPCODE_LASTBIT            : return "lastbit";
    case BRIG_OPCODE_LD                 : return "ld";
    case BRIG_OPCODE_LDA                : return "lda";
    case BRIG_OPCODE_LDF                : return "ldf";
    case BRIG_OPCODE_LDI                : return "ldi";
    case BRIG_OPCODE_LDIMAGE            : return "ldimage";
    case BRIG_OPCODE_LDK                : return "ldk";
    case BRIG_OPCODE_LDQUEUEREADINDEX   : return "ldqueuereadindex";
    case BRIG_OPCODE_LDQUEUEWRITEINDEX  : return "ldqueuewriteindex";
    case BRIG_OPCODE_LEAVEFBAR          : return "leavefbar";
    case BRIG_OPCODE_LERP               : return "lerp";
    case BRIG_OPCODE_MAD                : return "mad";
    case BRIG_OPCODE_MAD24              : return "mad24";
    case BRIG_OPCODE_MAD24HI            : return "mad24hi";
    case BRIG_OPCODE_MAX                : return "max";
    case BRIG_OPCODE_MAXCUID            : return "maxcuid";
    case BRIG_OPCODE_MAXWAVEID          : return "maxwaveid";
    case BRIG_OPCODE_MEMFENCE           : return "memfence";
    case BRIG_OPCODE_MIN                : return "min";
    case BRIG_OPCODE_MOV                : return "mov";
    case BRIG_OPCODE_MUL                : return "mul";
    case BRIG_OPCODE_MUL24              : return "mul24";
    case BRIG_OPCODE_MUL24HI            : return "mul24hi";
    case BRIG_OPCODE_MULHI              : return "mulhi";
    case BRIG_OPCODE_NCOS               : return "ncos";
    case BRIG_OPCODE_NEG                : return "neg";
    case BRIG_OPCODE_NEXP2              : return "nexp2";
    case BRIG_OPCODE_NFMA               : return "nfma";
    case BRIG_OPCODE_NLOG2              : return "nlog2";
    case BRIG_OPCODE_NOP                : return "nop";
    case BRIG_OPCODE_NOT                : return "not";
    case BRIG_OPCODE_NRCP               : return "nrcp";
    case BRIG_OPCODE_NRSQRT             : return "nrsqrt";
    case BRIG_OPCODE_NSIN               : return "nsin";
    case BRIG_OPCODE_NSQRT              : return "nsqrt";
    case BRIG_OPCODE_NULLPTR            : return "nullptr";
    case BRIG_OPCODE_OR                 : return "or";
    case BRIG_OPCODE_PACK               : return "pack";
    case BRIG_OPCODE_PACKCVT            : return "packcvt";
    case BRIG_OPCODE_PACKETCOMPLETIONSIG : return "packetcompletionsig";
    case BRIG_OPCODE_PACKETID           : return "packetid";
    case BRIG_OPCODE_POPCOUNT           : return "popcount";
    case BRIG_OPCODE_QUERYIMAGE         : return "queryimage";
    case BRIG_OPCODE_QUERYSAMPLER       : return "querysampler";
    case BRIG_OPCODE_QUEUEID            : return "queueid";
    case BRIG_OPCODE_QUEUEPTR           : return "queueptr";
    case BRIG_OPCODE_RDIMAGE            : return "rdimage";
    case BRIG_OPCODE_RELEASEFBAR        : return "releasefbar";
    case BRIG_OPCODE_REM                : return "rem";
    case BRIG_OPCODE_RET                : return "ret";
    case BRIG_OPCODE_RINT               : return "rint";
    case BRIG_OPCODE_SAD                : return "sad";
    case BRIG_OPCODE_SADHI              : return "sadhi";
    case BRIG_OPCODE_SBR                : return "sbr";
    case BRIG_OPCODE_SCALL              : return "scall";
    case BRIG_OPCODE_SEGMENTP           : return "segmentp";
    case BRIG_OPCODE_SETDETECTEXCEPT    : return "setdetectexcept";
    case BRIG_OPCODE_SHL                : return "shl";
    case BRIG_OPCODE_SHR                : return "shr";
    case BRIG_OPCODE_SHUFFLE            : return "shuffle";
    case BRIG_OPCODE_SIGNAL             : return "signal";
    case BRIG_OPCODE_SIGNALNORET        : return "signalnoret";
    case BRIG_OPCODE_SQRT               : return "sqrt";
    case BRIG_OPCODE_ST                 : return "st";
    case BRIG_OPCODE_STIMAGE            : return "stimage";
    case BRIG_OPCODE_STOF               : return "stof";
    case BRIG_OPCODE_STQUEUEREADINDEX   : return "stqueuereadindex";
    case BRIG_OPCODE_STQUEUEWRITEINDEX  : return "stqueuewriteindex";
    case BRIG_OPCODE_SUB                : return "sub";
    case BRIG_OPCODE_TRUNC              : return "trunc";
    case BRIG_OPCODE_UNPACK             : return "unpack";
    case BRIG_OPCODE_UNPACKCVT          : return "unpackcvt";
    case BRIG_OPCODE_UNPACKHI           : return "unpackhi";
    case BRIG_OPCODE_UNPACKLO           : return "unpacklo";
    case BRIG_OPCODE_WAITFBAR           : return "waitfbar";
    case BRIG_OPCODE_WAVEBARRIER        : return "wavebarrier";
    case BRIG_OPCODE_WAVEID             : return "waveid";
    case BRIG_OPCODE_WORKGROUPID        : return "workgroupid";
    case BRIG_OPCODE_WORKGROUPSIZE      : return "workgroupsize";
    case BRIG_OPCODE_WORKITEMABSID      : return "workitemabsid";
    case BRIG_OPCODE_WORKITEMFLATABSID  : return "workitemflatabsid";
    case BRIG_OPCODE_WORKITEMFLATID     : return "workitemflatid";
    case BRIG_OPCODE_WORKITEMID         : return "workitemid";
    case BRIG_OPCODE_XOR                : return "xor";
    default : return NULL;
    }
}

bool instHasType(Brig::BrigOpcode16_t arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ARRIVEFBAR         : return false;
    case BRIG_OPCODE_BARRIER            : return false;
    case BRIG_OPCODE_BR                 : return false;
    case BRIG_OPCODE_CALL               : return false;
    case BRIG_OPCODE_GCNMADS            : return false;
    case BRIG_OPCODE_GCNMADU            : return false;
    case BRIG_OPCODE_GCNMQSAD4          : return false;
    case BRIG_OPCODE_GCNREGIONALLOC     : return false;
    case BRIG_OPCODE_INITFBAR           : return false;
    case BRIG_OPCODE_JOINFBAR           : return false;
    case BRIG_OPCODE_LEAVEFBAR          : return false;
    case BRIG_OPCODE_NOP                : return false;
    case BRIG_OPCODE_RELEASEFBAR        : return false;
    case BRIG_OPCODE_RET                : return false;
    case BRIG_OPCODE_WAITFBAR           : return false;
    case BRIG_OPCODE_WAVEBARRIER        : return false;
    default : return true;
    }
}

int instNumDstOperands(Brig::BrigOpcode16_t arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ARRIVEFBAR         : return 0;
    case BRIG_OPCODE_ATOMICNORET        : return 0;
    case BRIG_OPCODE_BARRIER            : return 0;
    case BRIG_OPCODE_BR                 : return 0;
    case BRIG_OPCODE_CALL               : return 0;
    case BRIG_OPCODE_CBR                : return 0;
    case BRIG_OPCODE_CLEARDETECTEXCEPT  : return 0;
    case BRIG_OPCODE_DEBUGTRAP          : return 0;
    case BRIG_OPCODE_ICALL              : return 0;
    case BRIG_OPCODE_INITFBAR           : return 0;
    case BRIG_OPCODE_JOINFBAR           : return 0;
    case BRIG_OPCODE_LEAVEFBAR          : return 0;
    case BRIG_OPCODE_MEMFENCE           : return 0;
    case BRIG_OPCODE_RELEASEFBAR        : return 0;
    case BRIG_OPCODE_SBR                : return 0;
    case BRIG_OPCODE_SCALL              : return 0;
    case BRIG_OPCODE_SETDETECTEXCEPT    : return 0;
    case BRIG_OPCODE_SIGNALNORET        : return 0;
    case BRIG_OPCODE_ST                 : return 0;
    case BRIG_OPCODE_STIMAGE            : return 0;
    case BRIG_OPCODE_STQUEUEREADINDEX   : return 0;
    case BRIG_OPCODE_STQUEUEWRITEINDEX  : return 0;
    case BRIG_OPCODE_WAITFBAR           : return 0;
    case BRIG_OPCODE_WAVEBARRIER        : return 0;
    default : return 1;
    }
}

const char* pack2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_PACK_NONE                 : return "";
    case BRIG_PACK_P                    : return "p";
    case BRIG_PACK_PP                   : return "pp";
    case BRIG_PACK_PPSAT                : return "pp_sat";
    case BRIG_PACK_PS                   : return "ps";
    case BRIG_PACK_PSAT                 : return "p_sat";
    case BRIG_PACK_PSSAT                : return "ps_sat";
    case BRIG_PACK_S                    : return "s";
    case BRIG_PACK_SP                   : return "sp";
    case BRIG_PACK_SPSAT                : return "sp_sat";
    case BRIG_PACK_SS                   : return "ss";
    case BRIG_PACK_SSAT                 : return "s_sat";
    case BRIG_PACK_SSSAT                : return "ss_sat";
    default : return NULL;
    }
}

const char* profile2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_PROFILE_BASE              : return "$base";
    case BRIG_PROFILE_FULL              : return "$full";
    default : return NULL;
    }
}

const char* registerKind2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_REGISTER_CONTROL          : return "$c";
    case BRIG_REGISTER_DOUBLE           : return "$d";
    case BRIG_REGISTER_QUAD             : return "$q";
    case BRIG_REGISTER_SINGLE           : return "$s";
    default : return NULL;
    }
}

unsigned getRegBits(Brig::BrigRegisterKind16_t arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_REGISTER_CONTROL          : return 1;
    case BRIG_REGISTER_DOUBLE           : return 64;
    case BRIG_REGISTER_QUAD             : return 128;
    case BRIG_REGISTER_SINGLE           : return 32;
    default : return (unsigned)-1;
    }
}

const char* round2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ROUND_FLOAT_MINUS_INFINITY : return "down";
    case BRIG_ROUND_FLOAT_NEAR_EVEN     : return "near";
    case BRIG_ROUND_FLOAT_PLUS_INFINITY : return "up";
    case BRIG_ROUND_FLOAT_ZERO          : return "zero";
    case BRIG_ROUND_INTEGER_MINUS_INFINITY : return "downi";
    case BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT : return "downi_sat";
    case BRIG_ROUND_INTEGER_NEAR_EVEN   : return "neari";
    case BRIG_ROUND_INTEGER_NEAR_EVEN_SAT : return "neari_sat";
    case BRIG_ROUND_INTEGER_PLUS_INFINITY : return "upi";
    case BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT : return "upi_sat";
    case BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY : return "sdowni";
    case BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY_SAT : return "sdowni_sat";
    case BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN : return "sneari";
    case BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN_SAT : return "sneari_sat";
    case BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY : return "supi";
    case BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY_SAT : return "supi_sat";
    case BRIG_ROUND_INTEGER_SIGNALLING_ZERO : return "szeroi";
    case BRIG_ROUND_INTEGER_SIGNALLING_ZERO_SAT : return "szeroi_sat";
    case BRIG_ROUND_INTEGER_ZERO        : return "zeroi";
    case BRIG_ROUND_INTEGER_ZERO_SAT    : return "zeroi_sat";
    default : return NULL;
    }
}

const char* samplerAddressing2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ADDRESSING_CLAMP_TO_BORDER : return "clamp_to_border";
    case BRIG_ADDRESSING_CLAMP_TO_EDGE  : return "clamp_to_edge";
    case BRIG_ADDRESSING_MIRRORED_REPEAT : return "mirrored_repeat";
    case BRIG_ADDRESSING_REPEAT         : return "repeat";
    case BRIG_ADDRESSING_UNDEFINED      : return "undefined";
    default : return NULL;
    }
}

const char* samplerCoordNormalization2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_COORD_NORMALIZED          : return "normalized";
    case BRIG_COORD_UNNORMALIZED        : return "unnormalized";
    default : return NULL;
    }
}

const char* samplerFilter2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_FILTER_LINEAR             : return "linear";
    case BRIG_FILTER_NEAREST            : return "nearest";
    default : return NULL;
    }
}

const char* samplerQuery2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SAMPLER_QUERY_ADDRESSING  : return "addressing";
    case BRIG_SAMPLER_QUERY_COORD       : return "coord";
    case BRIG_SAMPLER_QUERY_FILTER      : return "filter";
    default : return NULL;
    }
}

const char* sectionIndex2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SECTION_INDEX_BEGIN_IMPLEMENTATION_DEFINED : return "hsa_begin_implementation_defined";
    case BRIG_SECTION_INDEX_CODE        : return "hsa_code";
    case BRIG_SECTION_INDEX_DATA        : return "hsa_data";
    case BRIG_SECTION_INDEX_OPERAND     : return "hsa_operand";
    default : return NULL;
    }
}

const char* segment2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SEGMENT_ARG               : return "arg";
    case BRIG_SEGMENT_EXTSPACE0         : return "region";
    case BRIG_SEGMENT_FLAT              : return "";
    case BRIG_SEGMENT_GLOBAL            : return "global";
    case BRIG_SEGMENT_GROUP             : return "group";
    case BRIG_SEGMENT_KERNARG           : return "kernarg";
    case BRIG_SEGMENT_NONE              : return "";
    case BRIG_SEGMENT_PRIVATE           : return "private";
    case BRIG_SEGMENT_READONLY          : return "readonly";
    case BRIG_SEGMENT_SPILL             : return "spill";
    default : return NULL;
    }
}

const char* typeX2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_TYPE_B1                   : return "b1";
    case BRIG_TYPE_B128                 : return "b128";
    case BRIG_TYPE_B16                  : return "b16";
    case BRIG_TYPE_B32                  : return "b32";
    case BRIG_TYPE_B64                  : return "b64";
    case BRIG_TYPE_B8                   : return "b8";
    case BRIG_TYPE_F16                  : return "f16";
    case BRIG_TYPE_F16X2                : return "f16x2";
    case BRIG_TYPE_F16X4                : return "f16x4";
    case BRIG_TYPE_F16X8                : return "f16x8";
    case BRIG_TYPE_F32                  : return "f32";
    case BRIG_TYPE_F32X2                : return "f32x2";
    case BRIG_TYPE_F32X4                : return "f32x4";
    case BRIG_TYPE_F64                  : return "f64";
    case BRIG_TYPE_F64X2                : return "f64x2";
    case BRIG_TYPE_NONE                 : return "";
    case BRIG_TYPE_ROIMG                : return "roimg";
    case BRIG_TYPE_RWIMG                : return "rwimg";
    case BRIG_TYPE_S16                  : return "s16";
    case BRIG_TYPE_S16X2                : return "s16x2";
    case BRIG_TYPE_S16X4                : return "s16x4";
    case BRIG_TYPE_S16X8                : return "s16x8";
    case BRIG_TYPE_S32                  : return "s32";
    case BRIG_TYPE_S32X2                : return "s32x2";
    case BRIG_TYPE_S32X4                : return "s32x4";
    case BRIG_TYPE_S64                  : return "s64";
    case BRIG_TYPE_S64X2                : return "s64x2";
    case BRIG_TYPE_S8                   : return "s8";
    case BRIG_TYPE_S8X16                : return "s8x16";
    case BRIG_TYPE_S8X4                 : return "s8x4";
    case BRIG_TYPE_S8X8                 : return "s8x8";
    case BRIG_TYPE_SAMP                 : return "samp";
    case BRIG_TYPE_SIG32                : return "sig32";
    case BRIG_TYPE_SIG64                : return "sig64";
    case BRIG_TYPE_U16                  : return "u16";
    case BRIG_TYPE_U16X2                : return "u16x2";
    case BRIG_TYPE_U16X4                : return "u16x4";
    case BRIG_TYPE_U16X8                : return "u16x8";
    case BRIG_TYPE_U32                  : return "u32";
    case BRIG_TYPE_U32X2                : return "u32x2";
    case BRIG_TYPE_U32X4                : return "u32x4";
    case BRIG_TYPE_U64                  : return "u64";
    case BRIG_TYPE_U64X2                : return "u64x2";
    case BRIG_TYPE_U8                   : return "u8";
    case BRIG_TYPE_U8X16                : return "u8x16";
    case BRIG_TYPE_U8X4                 : return "u8x4";
    case BRIG_TYPE_U8X8                 : return "u8x8";
    case BRIG_TYPE_WOIMG                : return "woimg";
    default : return NULL;
    }
}

unsigned getBrigTypeNumBits(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_TYPE_B1                   : return 1;
    case BRIG_TYPE_B128                 : return 128;
    case BRIG_TYPE_B16                  : return 16;
    case BRIG_TYPE_B32                  : return 32;
    case BRIG_TYPE_B64                  : return 64;
    case BRIG_TYPE_B8                   : return 8;
    case BRIG_TYPE_F16                  : return 16;
    case BRIG_TYPE_F16X2                : return 32;
    case BRIG_TYPE_F16X4                : return 64;
    case BRIG_TYPE_F16X8                : return 128;
    case BRIG_TYPE_F32                  : return 32;
    case BRIG_TYPE_F32X2                : return 64;
    case BRIG_TYPE_F32X4                : return 128;
    case BRIG_TYPE_F64                  : return 64;
    case BRIG_TYPE_F64X2                : return 128;
    case BRIG_TYPE_ROIMG                : return 64;
    case BRIG_TYPE_RWIMG                : return 64;
    case BRIG_TYPE_S16                  : return 16;
    case BRIG_TYPE_S16X2                : return 32;
    case BRIG_TYPE_S16X4                : return 64;
    case BRIG_TYPE_S16X8                : return 128;
    case BRIG_TYPE_S32                  : return 32;
    case BRIG_TYPE_S32X2                : return 64;
    case BRIG_TYPE_S32X4                : return 128;
    case BRIG_TYPE_S64                  : return 64;
    case BRIG_TYPE_S64X2                : return 128;
    case BRIG_TYPE_S8                   : return 8;
    case BRIG_TYPE_S8X16                : return 128;
    case BRIG_TYPE_S8X4                 : return 32;
    case BRIG_TYPE_S8X8                 : return 64;
    case BRIG_TYPE_SAMP                 : return 64;
    case BRIG_TYPE_SIG32                : return 64;
    case BRIG_TYPE_SIG64                : return 64;
    case BRIG_TYPE_U16                  : return 16;
    case BRIG_TYPE_U16X2                : return 32;
    case BRIG_TYPE_U16X4                : return 64;
    case BRIG_TYPE_U16X8                : return 128;
    case BRIG_TYPE_U32                  : return 32;
    case BRIG_TYPE_U32X2                : return 64;
    case BRIG_TYPE_U32X4                : return 128;
    case BRIG_TYPE_U64                  : return 64;
    case BRIG_TYPE_U64X2                : return 128;
    case BRIG_TYPE_U8                   : return 8;
    case BRIG_TYPE_U8X16                : return 128;
    case BRIG_TYPE_U8X4                 : return 32;
    case BRIG_TYPE_U8X8                 : return 64;
    case BRIG_TYPE_WOIMG                : return 64;
    default : assert(0); return 0;
    }
}

unsigned getBrigTypeNumBytes(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_TYPE_B1                   : return 1;
    case BRIG_TYPE_B128                 : return 16;
    case BRIG_TYPE_B16                  : return 2;
    case BRIG_TYPE_B32                  : return 4;
    case BRIG_TYPE_B64                  : return 8;
    case BRIG_TYPE_B8                   : return 1;
    case BRIG_TYPE_F16                  : return 2;
    case BRIG_TYPE_F16X2                : return 4;
    case BRIG_TYPE_F16X4                : return 8;
    case BRIG_TYPE_F16X8                : return 16;
    case BRIG_TYPE_F32                  : return 4;
    case BRIG_TYPE_F32X2                : return 8;
    case BRIG_TYPE_F32X4                : return 16;
    case BRIG_TYPE_F64                  : return 8;
    case BRIG_TYPE_F64X2                : return 16;
    case BRIG_TYPE_ROIMG                : return 8;
    case BRIG_TYPE_RWIMG                : return 8;
    case BRIG_TYPE_S16                  : return 2;
    case BRIG_TYPE_S16X2                : return 4;
    case BRIG_TYPE_S16X4                : return 8;
    case BRIG_TYPE_S16X8                : return 16;
    case BRIG_TYPE_S32                  : return 4;
    case BRIG_TYPE_S32X2                : return 8;
    case BRIG_TYPE_S32X4                : return 16;
    case BRIG_TYPE_S64                  : return 8;
    case BRIG_TYPE_S64X2                : return 16;
    case BRIG_TYPE_S8                   : return 1;
    case BRIG_TYPE_S8X16                : return 16;
    case BRIG_TYPE_S8X4                 : return 4;
    case BRIG_TYPE_S8X8                 : return 8;
    case BRIG_TYPE_SAMP                 : return 8;
    case BRIG_TYPE_SIG32                : return 8;
    case BRIG_TYPE_SIG64                : return 8;
    case BRIG_TYPE_U16                  : return 2;
    case BRIG_TYPE_U16X2                : return 4;
    case BRIG_TYPE_U16X4                : return 8;
    case BRIG_TYPE_U16X8                : return 16;
    case BRIG_TYPE_U32                  : return 4;
    case BRIG_TYPE_U32X2                : return 8;
    case BRIG_TYPE_U32X4                : return 16;
    case BRIG_TYPE_U64                  : return 8;
    case BRIG_TYPE_U64X2                : return 16;
    case BRIG_TYPE_U8                   : return 1;
    case BRIG_TYPE_U8X16                : return 16;
    case BRIG_TYPE_U8X4                 : return 4;
    case BRIG_TYPE_U8X8                 : return 8;
    case BRIG_TYPE_WOIMG                : return 8;
    default : assert(0); return 0;
    }
}

const char* anyEnum2str( Brig::BrigAlignment arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ALIGNMENT_1               : return "BRIG_ALIGNMENT_1";
    case BRIG_ALIGNMENT_128             : return "BRIG_ALIGNMENT_128";
    case BRIG_ALIGNMENT_16              : return "BRIG_ALIGNMENT_16";
    case BRIG_ALIGNMENT_2               : return "BRIG_ALIGNMENT_2";
    case BRIG_ALIGNMENT_256             : return "BRIG_ALIGNMENT_256";
    case BRIG_ALIGNMENT_32              : return "BRIG_ALIGNMENT_32";
    case BRIG_ALIGNMENT_4               : return "BRIG_ALIGNMENT_4";
    case BRIG_ALIGNMENT_64              : return "BRIG_ALIGNMENT_64";
    case BRIG_ALIGNMENT_8               : return "BRIG_ALIGNMENT_8";
    case BRIG_ALIGNMENT_NONE            : return "BRIG_ALIGNMENT_NONE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigAllocation arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ALLOCATION_AGENT          : return "BRIG_ALLOCATION_AGENT";
    case BRIG_ALLOCATION_AUTOMATIC      : return "BRIG_ALLOCATION_AUTOMATIC";
    case BRIG_ALLOCATION_NONE           : return "BRIG_ALLOCATION_NONE";
    case BRIG_ALLOCATION_PROGRAM        : return "BRIG_ALLOCATION_PROGRAM";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigAluModifierMask arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ALU_FTZ                   : return "BRIG_ALU_FTZ";
    case BRIG_ALU_ROUND                 : return "BRIG_ALU_ROUND";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigAtomicOperation arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ATOMIC_ADD                : return "BRIG_ATOMIC_ADD";
    case BRIG_ATOMIC_AND                : return "BRIG_ATOMIC_AND";
    case BRIG_ATOMIC_CAS                : return "BRIG_ATOMIC_CAS";
    case BRIG_ATOMIC_EXCH               : return "BRIG_ATOMIC_EXCH";
    case BRIG_ATOMIC_LD                 : return "BRIG_ATOMIC_LD";
    case BRIG_ATOMIC_MAX                : return "BRIG_ATOMIC_MAX";
    case BRIG_ATOMIC_MIN                : return "BRIG_ATOMIC_MIN";
    case BRIG_ATOMIC_OR                 : return "BRIG_ATOMIC_OR";
    case BRIG_ATOMIC_ST                 : return "BRIG_ATOMIC_ST";
    case BRIG_ATOMIC_SUB                : return "BRIG_ATOMIC_SUB";
    case BRIG_ATOMIC_WAITTIMEOUT_EQ     : return "BRIG_ATOMIC_WAITTIMEOUT_EQ";
    case BRIG_ATOMIC_WAITTIMEOUT_GTE    : return "BRIG_ATOMIC_WAITTIMEOUT_GTE";
    case BRIG_ATOMIC_WAITTIMEOUT_LT     : return "BRIG_ATOMIC_WAITTIMEOUT_LT";
    case BRIG_ATOMIC_WAITTIMEOUT_NE     : return "BRIG_ATOMIC_WAITTIMEOUT_NE";
    case BRIG_ATOMIC_WAIT_EQ            : return "BRIG_ATOMIC_WAIT_EQ";
    case BRIG_ATOMIC_WAIT_GTE           : return "BRIG_ATOMIC_WAIT_GTE";
    case BRIG_ATOMIC_WAIT_LT            : return "BRIG_ATOMIC_WAIT_LT";
    case BRIG_ATOMIC_WAIT_NE            : return "BRIG_ATOMIC_WAIT_NE";
    case BRIG_ATOMIC_WRAPDEC            : return "BRIG_ATOMIC_WRAPDEC";
    case BRIG_ATOMIC_WRAPINC            : return "BRIG_ATOMIC_WRAPINC";
    case BRIG_ATOMIC_XOR                : return "BRIG_ATOMIC_XOR";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigCompareOperation arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_COMPARE_EQ                : return "BRIG_COMPARE_EQ";
    case BRIG_COMPARE_EQU               : return "BRIG_COMPARE_EQU";
    case BRIG_COMPARE_GE                : return "BRIG_COMPARE_GE";
    case BRIG_COMPARE_GEU               : return "BRIG_COMPARE_GEU";
    case BRIG_COMPARE_GT                : return "BRIG_COMPARE_GT";
    case BRIG_COMPARE_GTU               : return "BRIG_COMPARE_GTU";
    case BRIG_COMPARE_LE                : return "BRIG_COMPARE_LE";
    case BRIG_COMPARE_LEU               : return "BRIG_COMPARE_LEU";
    case BRIG_COMPARE_LT                : return "BRIG_COMPARE_LT";
    case BRIG_COMPARE_LTU               : return "BRIG_COMPARE_LTU";
    case BRIG_COMPARE_NAN               : return "BRIG_COMPARE_NAN";
    case BRIG_COMPARE_NE                : return "BRIG_COMPARE_NE";
    case BRIG_COMPARE_NEU               : return "BRIG_COMPARE_NEU";
    case BRIG_COMPARE_NUM               : return "BRIG_COMPARE_NUM";
    case BRIG_COMPARE_SEQ               : return "BRIG_COMPARE_SEQ";
    case BRIG_COMPARE_SEQU              : return "BRIG_COMPARE_SEQU";
    case BRIG_COMPARE_SGE               : return "BRIG_COMPARE_SGE";
    case BRIG_COMPARE_SGEU              : return "BRIG_COMPARE_SGEU";
    case BRIG_COMPARE_SGT               : return "BRIG_COMPARE_SGT";
    case BRIG_COMPARE_SGTU              : return "BRIG_COMPARE_SGTU";
    case BRIG_COMPARE_SLE               : return "BRIG_COMPARE_SLE";
    case BRIG_COMPARE_SLEU              : return "BRIG_COMPARE_SLEU";
    case BRIG_COMPARE_SLT               : return "BRIG_COMPARE_SLT";
    case BRIG_COMPARE_SLTU              : return "BRIG_COMPARE_SLTU";
    case BRIG_COMPARE_SNAN              : return "BRIG_COMPARE_SNAN";
    case BRIG_COMPARE_SNE               : return "BRIG_COMPARE_SNE";
    case BRIG_COMPARE_SNEU              : return "BRIG_COMPARE_SNEU";
    case BRIG_COMPARE_SNUM              : return "BRIG_COMPARE_SNUM";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigControlDirective arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_CONTROL_ENABLEBREAKEXCEPTIONS : return "BRIG_CONTROL_ENABLEBREAKEXCEPTIONS";
    case BRIG_CONTROL_ENABLEDETECTEXCEPTIONS : return "BRIG_CONTROL_ENABLEDETECTEXCEPTIONS";
    case BRIG_CONTROL_MAXDYNAMICGROUPSIZE : return "BRIG_CONTROL_MAXDYNAMICGROUPSIZE";
    case BRIG_CONTROL_MAXFLATGRIDSIZE   : return "BRIG_CONTROL_MAXFLATGRIDSIZE";
    case BRIG_CONTROL_MAXFLATWORKGROUPSIZE : return "BRIG_CONTROL_MAXFLATWORKGROUPSIZE";
    case BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU : return "BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU";
    case BRIG_CONTROL_REQUIREDDIM       : return "BRIG_CONTROL_REQUIREDDIM";
    case BRIG_CONTROL_REQUIREDGRIDSIZE  : return "BRIG_CONTROL_REQUIREDGRIDSIZE";
    case BRIG_CONTROL_REQUIREDWORKGROUPSIZE : return "BRIG_CONTROL_REQUIREDWORKGROUPSIZE";
    case BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS : return "BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigImageChannelOrder arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_CHANNEL_ORDER_A           : return "BRIG_CHANNEL_ORDER_A";
    case BRIG_CHANNEL_ORDER_ABGR        : return "BRIG_CHANNEL_ORDER_ABGR";
    case BRIG_CHANNEL_ORDER_ARGB        : return "BRIG_CHANNEL_ORDER_ARGB";
    case BRIG_CHANNEL_ORDER_BGRA        : return "BRIG_CHANNEL_ORDER_BGRA";
    case BRIG_CHANNEL_ORDER_DEPTH       : return "BRIG_CHANNEL_ORDER_DEPTH";
    case BRIG_CHANNEL_ORDER_DEPTH_STENCIL : return "BRIG_CHANNEL_ORDER_DEPTH_STENCIL";
    case BRIG_CHANNEL_ORDER_INTENSITY   : return "BRIG_CHANNEL_ORDER_INTENSITY";
    case BRIG_CHANNEL_ORDER_LUMINANCE   : return "BRIG_CHANNEL_ORDER_LUMINANCE";
    case BRIG_CHANNEL_ORDER_R           : return "BRIG_CHANNEL_ORDER_R";
    case BRIG_CHANNEL_ORDER_RA          : return "BRIG_CHANNEL_ORDER_RA";
    case BRIG_CHANNEL_ORDER_RG          : return "BRIG_CHANNEL_ORDER_RG";
    case BRIG_CHANNEL_ORDER_RGB         : return "BRIG_CHANNEL_ORDER_RGB";
    case BRIG_CHANNEL_ORDER_RGBA        : return "BRIG_CHANNEL_ORDER_RGBA";
    case BRIG_CHANNEL_ORDER_RGBX        : return "BRIG_CHANNEL_ORDER_RGBX";
    case BRIG_CHANNEL_ORDER_RGX         : return "BRIG_CHANNEL_ORDER_RGX";
    case BRIG_CHANNEL_ORDER_RX          : return "BRIG_CHANNEL_ORDER_RX";
    case BRIG_CHANNEL_ORDER_SBGRA       : return "BRIG_CHANNEL_ORDER_SBGRA";
    case BRIG_CHANNEL_ORDER_SRGB        : return "BRIG_CHANNEL_ORDER_SRGB";
    case BRIG_CHANNEL_ORDER_SRGBA       : return "BRIG_CHANNEL_ORDER_SRGBA";
    case BRIG_CHANNEL_ORDER_SRGBX       : return "BRIG_CHANNEL_ORDER_SRGBX";
    case BRIG_CHANNEL_ORDER_UNKNOWN     : return "BRIG_CHANNEL_ORDER_UNKNOWN";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigImageChannelType arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_CHANNEL_TYPE_FLOAT        : return "BRIG_CHANNEL_TYPE_FLOAT";
    case BRIG_CHANNEL_TYPE_HALF_FLOAT   : return "BRIG_CHANNEL_TYPE_HALF_FLOAT";
    case BRIG_CHANNEL_TYPE_SIGNED_INT16 : return "BRIG_CHANNEL_TYPE_SIGNED_INT16";
    case BRIG_CHANNEL_TYPE_SIGNED_INT32 : return "BRIG_CHANNEL_TYPE_SIGNED_INT32";
    case BRIG_CHANNEL_TYPE_SIGNED_INT8  : return "BRIG_CHANNEL_TYPE_SIGNED_INT8";
    case BRIG_CHANNEL_TYPE_SNORM_INT16  : return "BRIG_CHANNEL_TYPE_SNORM_INT16";
    case BRIG_CHANNEL_TYPE_SNORM_INT8   : return "BRIG_CHANNEL_TYPE_SNORM_INT8";
    case BRIG_CHANNEL_TYPE_UNKNOWN      : return "BRIG_CHANNEL_TYPE_UNKNOWN";
    case BRIG_CHANNEL_TYPE_UNORM_INT16  : return "BRIG_CHANNEL_TYPE_UNORM_INT16";
    case BRIG_CHANNEL_TYPE_UNORM_INT24  : return "BRIG_CHANNEL_TYPE_UNORM_INT24";
    case BRIG_CHANNEL_TYPE_UNORM_INT8   : return "BRIG_CHANNEL_TYPE_UNORM_INT8";
    case BRIG_CHANNEL_TYPE_UNORM_INT_101010 : return "BRIG_CHANNEL_TYPE_UNORM_INT_101010";
    case BRIG_CHANNEL_TYPE_UNORM_SHORT_555 : return "BRIG_CHANNEL_TYPE_UNORM_SHORT_555";
    case BRIG_CHANNEL_TYPE_UNORM_SHORT_565 : return "BRIG_CHANNEL_TYPE_UNORM_SHORT_565";
    case BRIG_CHANNEL_TYPE_UNSIGNED_INT16 : return "BRIG_CHANNEL_TYPE_UNSIGNED_INT16";
    case BRIG_CHANNEL_TYPE_UNSIGNED_INT32 : return "BRIG_CHANNEL_TYPE_UNSIGNED_INT32";
    case BRIG_CHANNEL_TYPE_UNSIGNED_INT8 : return "BRIG_CHANNEL_TYPE_UNSIGNED_INT8";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigImageGeometry arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_GEOMETRY_1D               : return "BRIG_GEOMETRY_1D";
    case BRIG_GEOMETRY_1DA              : return "BRIG_GEOMETRY_1DA";
    case BRIG_GEOMETRY_1DB              : return "BRIG_GEOMETRY_1DB";
    case BRIG_GEOMETRY_2D               : return "BRIG_GEOMETRY_2D";
    case BRIG_GEOMETRY_2DA              : return "BRIG_GEOMETRY_2DA";
    case BRIG_GEOMETRY_2DADEPTH         : return "BRIG_GEOMETRY_2DADEPTH";
    case BRIG_GEOMETRY_2DDEPTH          : return "BRIG_GEOMETRY_2DDEPTH";
    case BRIG_GEOMETRY_3D               : return "BRIG_GEOMETRY_3D";
    case BRIG_GEOMETRY_UNKNOWN          : return "BRIG_GEOMETRY_UNKNOWN";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigImageQuery arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_IMAGE_QUERY_ARRAY         : return "BRIG_IMAGE_QUERY_ARRAY";
    case BRIG_IMAGE_QUERY_CHANNELORDER  : return "BRIG_IMAGE_QUERY_CHANNELORDER";
    case BRIG_IMAGE_QUERY_CHANNELTYPE   : return "BRIG_IMAGE_QUERY_CHANNELTYPE";
    case BRIG_IMAGE_QUERY_DEPTH         : return "BRIG_IMAGE_QUERY_DEPTH";
    case BRIG_IMAGE_QUERY_HEIGHT        : return "BRIG_IMAGE_QUERY_HEIGHT";
    case BRIG_IMAGE_QUERY_WIDTH         : return "BRIG_IMAGE_QUERY_WIDTH";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigKinds arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_END : return "BRIG_KIND_DIRECTIVE_ARG_BLOCK_END";
    case BRIG_KIND_DIRECTIVE_ARG_BLOCK_START : return "BRIG_KIND_DIRECTIVE_ARG_BLOCK_START";
    case BRIG_KIND_DIRECTIVE_COMMENT    : return "BRIG_KIND_DIRECTIVE_COMMENT";
    case BRIG_KIND_DIRECTIVE_CONTROL    : return "BRIG_KIND_DIRECTIVE_CONTROL";
    case BRIG_KIND_DIRECTIVE_EXTENSION  : return "BRIG_KIND_DIRECTIVE_EXTENSION";
    case BRIG_KIND_DIRECTIVE_FBARRIER   : return "BRIG_KIND_DIRECTIVE_FBARRIER";
    case BRIG_KIND_DIRECTIVE_FUNCTION   : return "BRIG_KIND_DIRECTIVE_FUNCTION";
    case BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION : return "BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION";
    case BRIG_KIND_DIRECTIVE_KERNEL     : return "BRIG_KIND_DIRECTIVE_KERNEL";
    case BRIG_KIND_DIRECTIVE_LABEL      : return "BRIG_KIND_DIRECTIVE_LABEL";
    case BRIG_KIND_DIRECTIVE_LOC        : return "BRIG_KIND_DIRECTIVE_LOC";
    case BRIG_KIND_DIRECTIVE_PRAGMA     : return "BRIG_KIND_DIRECTIVE_PRAGMA";
    case BRIG_KIND_DIRECTIVE_SIGNATURE  : return "BRIG_KIND_DIRECTIVE_SIGNATURE";
    case BRIG_KIND_DIRECTIVE_VARIABLE   : return "BRIG_KIND_DIRECTIVE_VARIABLE";
    case BRIG_KIND_DIRECTIVE_VERSION    : return "BRIG_KIND_DIRECTIVE_VERSION";
    case BRIG_KIND_INST_ADDR            : return "BRIG_KIND_INST_ADDR";
    case BRIG_KIND_INST_ATOMIC          : return "BRIG_KIND_INST_ATOMIC";
    case BRIG_KIND_INST_BASIC           : return "BRIG_KIND_INST_BASIC";
    case BRIG_KIND_INST_BR              : return "BRIG_KIND_INST_BR";
    case BRIG_KIND_INST_CMP             : return "BRIG_KIND_INST_CMP";
    case BRIG_KIND_INST_CVT             : return "BRIG_KIND_INST_CVT";
    case BRIG_KIND_INST_IMAGE           : return "BRIG_KIND_INST_IMAGE";
    case BRIG_KIND_INST_LANE            : return "BRIG_KIND_INST_LANE";
    case BRIG_KIND_INST_MEM             : return "BRIG_KIND_INST_MEM";
    case BRIG_KIND_INST_MEM_FENCE       : return "BRIG_KIND_INST_MEM_FENCE";
    case BRIG_KIND_INST_MOD             : return "BRIG_KIND_INST_MOD";
    case BRIG_KIND_INST_QUERY_IMAGE     : return "BRIG_KIND_INST_QUERY_IMAGE";
    case BRIG_KIND_INST_QUERY_SAMPLER   : return "BRIG_KIND_INST_QUERY_SAMPLER";
    case BRIG_KIND_INST_QUEUE           : return "BRIG_KIND_INST_QUEUE";
    case BRIG_KIND_INST_SEG             : return "BRIG_KIND_INST_SEG";
    case BRIG_KIND_INST_SEG_CVT         : return "BRIG_KIND_INST_SEG_CVT";
    case BRIG_KIND_INST_SIGNAL          : return "BRIG_KIND_INST_SIGNAL";
    case BRIG_KIND_INST_SOURCE_TYPE     : return "BRIG_KIND_INST_SOURCE_TYPE";
    case BRIG_KIND_OPERAND_ADDRESS      : return "BRIG_KIND_OPERAND_ADDRESS";
    case BRIG_KIND_OPERAND_CODE_LIST    : return "BRIG_KIND_OPERAND_CODE_LIST";
    case BRIG_KIND_OPERAND_CODE_REF     : return "BRIG_KIND_OPERAND_CODE_REF";
    case BRIG_KIND_OPERAND_DATA         : return "BRIG_KIND_OPERAND_DATA";
    case BRIG_KIND_OPERAND_IMAGE_PROPERTIES : return "BRIG_KIND_OPERAND_IMAGE_PROPERTIES";
    case BRIG_KIND_OPERAND_OPERAND_LIST : return "BRIG_KIND_OPERAND_OPERAND_LIST";
    case BRIG_KIND_OPERAND_REG          : return "BRIG_KIND_OPERAND_REG";
    case BRIG_KIND_OPERAND_SAMPLER_PROPERTIES : return "BRIG_KIND_OPERAND_SAMPLER_PROPERTIES";
    case BRIG_KIND_OPERAND_STRING       : return "BRIG_KIND_OPERAND_STRING";
    case BRIG_KIND_OPERAND_WAVESIZE     : return "BRIG_KIND_OPERAND_WAVESIZE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigLinkage arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_LINKAGE_ARG               : return "BRIG_LINKAGE_ARG";
    case BRIG_LINKAGE_FUNCTION          : return "BRIG_LINKAGE_FUNCTION";
    case BRIG_LINKAGE_MODULE            : return "BRIG_LINKAGE_MODULE";
    case BRIG_LINKAGE_NONE              : return "BRIG_LINKAGE_NONE";
    case BRIG_LINKAGE_PROGRAM           : return "BRIG_LINKAGE_PROGRAM";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMachineModel arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MACHINE_LARGE             : return "BRIG_MACHINE_LARGE";
    case BRIG_MACHINE_SMALL             : return "BRIG_MACHINE_SMALL";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMemoryFenceSegments arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_FENCE_SEGMENT_GLOBAL : return "BRIG_MEMORY_FENCE_SEGMENT_GLOBAL";
    case BRIG_MEMORY_FENCE_SEGMENT_GROUP : return "BRIG_MEMORY_FENCE_SEGMENT_GROUP";
    case BRIG_MEMORY_FENCE_SEGMENT_IMAGE : return "BRIG_MEMORY_FENCE_SEGMENT_IMAGE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMemoryModifierMask arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_CONST              : return "BRIG_MEMORY_CONST";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMemoryOrder arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_ORDER_NONE         : return "BRIG_MEMORY_ORDER_NONE";
    case BRIG_MEMORY_ORDER_RELAXED      : return "BRIG_MEMORY_ORDER_RELAXED";
    case BRIG_MEMORY_ORDER_SC_ACQUIRE   : return "BRIG_MEMORY_ORDER_SC_ACQUIRE";
    case BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE : return "BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE";
    case BRIG_MEMORY_ORDER_SC_RELEASE   : return "BRIG_MEMORY_ORDER_SC_RELEASE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMemoryScope arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_SCOPE_COMPONENT    : return "BRIG_MEMORY_SCOPE_COMPONENT";
    case BRIG_MEMORY_SCOPE_NONE         : return "BRIG_MEMORY_SCOPE_NONE";
    case BRIG_MEMORY_SCOPE_SYSTEM       : return "BRIG_MEMORY_SCOPE_SYSTEM";
    case BRIG_MEMORY_SCOPE_WAVEFRONT    : return "BRIG_MEMORY_SCOPE_WAVEFRONT";
    case BRIG_MEMORY_SCOPE_WORKGROUP    : return "BRIG_MEMORY_SCOPE_WORKGROUP";
    case BRIG_MEMORY_SCOPE_WORKITEM     : return "BRIG_MEMORY_SCOPE_WORKITEM";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMemoryScope2 arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_SCOPE2_COMPONENT   : return "BRIG_MEMORY_SCOPE2_COMPONENT";
    case BRIG_MEMORY_SCOPE2_NONE        : return "BRIG_MEMORY_SCOPE2_NONE";
    case BRIG_MEMORY_SCOPE2_SYSTEM      : return "BRIG_MEMORY_SCOPE2_SYSTEM";
    case BRIG_MEMORY_SCOPE2_WAVEFRONT   : return "BRIG_MEMORY_SCOPE2_WAVEFRONT";
    case BRIG_MEMORY_SCOPE2_WORKGROUP   : return "BRIG_MEMORY_SCOPE2_WORKGROUP";
    case BRIG_MEMORY_SCOPE2_WORKITEM    : return "BRIG_MEMORY_SCOPE2_WORKITEM";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigOpcode arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ABS                : return "BRIG_OPCODE_ABS";
    case BRIG_OPCODE_ACTIVELANECOUNT    : return "BRIG_OPCODE_ACTIVELANECOUNT";
    case BRIG_OPCODE_ACTIVELANEID       : return "BRIG_OPCODE_ACTIVELANEID";
    case BRIG_OPCODE_ACTIVELANEMASK     : return "BRIG_OPCODE_ACTIVELANEMASK";
    case BRIG_OPCODE_ACTIVELANESHUFFLE  : return "BRIG_OPCODE_ACTIVELANESHUFFLE";
    case BRIG_OPCODE_ADD                : return "BRIG_OPCODE_ADD";
    case BRIG_OPCODE_ADDQUEUEWRITEINDEX : return "BRIG_OPCODE_ADDQUEUEWRITEINDEX";
    case BRIG_OPCODE_AGENTCOUNT         : return "BRIG_OPCODE_AGENTCOUNT";
    case BRIG_OPCODE_AGENTID            : return "BRIG_OPCODE_AGENTID";
    case BRIG_OPCODE_ALLOCA             : return "BRIG_OPCODE_ALLOCA";
    case BRIG_OPCODE_AND                : return "BRIG_OPCODE_AND";
    case BRIG_OPCODE_ARRIVEFBAR         : return "BRIG_OPCODE_ARRIVEFBAR";
    case BRIG_OPCODE_ATOMIC             : return "BRIG_OPCODE_ATOMIC";
    case BRIG_OPCODE_ATOMICNORET        : return "BRIG_OPCODE_ATOMICNORET";
    case BRIG_OPCODE_BARRIER            : return "BRIG_OPCODE_BARRIER";
    case BRIG_OPCODE_BITALIGN           : return "BRIG_OPCODE_BITALIGN";
    case BRIG_OPCODE_BITEXTRACT         : return "BRIG_OPCODE_BITEXTRACT";
    case BRIG_OPCODE_BITINSERT          : return "BRIG_OPCODE_BITINSERT";
    case BRIG_OPCODE_BITMASK            : return "BRIG_OPCODE_BITMASK";
    case BRIG_OPCODE_BITREV             : return "BRIG_OPCODE_BITREV";
    case BRIG_OPCODE_BITSELECT          : return "BRIG_OPCODE_BITSELECT";
    case BRIG_OPCODE_BORROW             : return "BRIG_OPCODE_BORROW";
    case BRIG_OPCODE_BR                 : return "BRIG_OPCODE_BR";
    case BRIG_OPCODE_BYTEALIGN          : return "BRIG_OPCODE_BYTEALIGN";
    case BRIG_OPCODE_CALL               : return "BRIG_OPCODE_CALL";
    case BRIG_OPCODE_CARRY              : return "BRIG_OPCODE_CARRY";
    case BRIG_OPCODE_CASQUEUEWRITEINDEX : return "BRIG_OPCODE_CASQUEUEWRITEINDEX";
    case BRIG_OPCODE_CBR                : return "BRIG_OPCODE_CBR";
    case BRIG_OPCODE_CEIL               : return "BRIG_OPCODE_CEIL";
    case BRIG_OPCODE_CLASS              : return "BRIG_OPCODE_CLASS";
    case BRIG_OPCODE_CLEARDETECTEXCEPT  : return "BRIG_OPCODE_CLEARDETECTEXCEPT";
    case BRIG_OPCODE_CLOCK              : return "BRIG_OPCODE_CLOCK";
    case BRIG_OPCODE_CMOV               : return "BRIG_OPCODE_CMOV";
    case BRIG_OPCODE_CMP                : return "BRIG_OPCODE_CMP";
    case BRIG_OPCODE_COMBINE            : return "BRIG_OPCODE_COMBINE";
    case BRIG_OPCODE_COPYSIGN           : return "BRIG_OPCODE_COPYSIGN";
    case BRIG_OPCODE_CUID               : return "BRIG_OPCODE_CUID";
    case BRIG_OPCODE_CURRENTWORKGROUPSIZE : return "BRIG_OPCODE_CURRENTWORKGROUPSIZE";
    case BRIG_OPCODE_CVT                : return "BRIG_OPCODE_CVT";
    case BRIG_OPCODE_DEBUGTRAP          : return "BRIG_OPCODE_DEBUGTRAP";
    case BRIG_OPCODE_DIM                : return "BRIG_OPCODE_DIM";
    case BRIG_OPCODE_DIV                : return "BRIG_OPCODE_DIV";
    case BRIG_OPCODE_EXPAND             : return "BRIG_OPCODE_EXPAND";
    case BRIG_OPCODE_FIRSTBIT           : return "BRIG_OPCODE_FIRSTBIT";
    case BRIG_OPCODE_FLOOR              : return "BRIG_OPCODE_FLOOR";
    case BRIG_OPCODE_FMA                : return "BRIG_OPCODE_FMA";
    case BRIG_OPCODE_FRACT              : return "BRIG_OPCODE_FRACT";
    case BRIG_OPCODE_FTOS               : return "BRIG_OPCODE_FTOS";
    case BRIG_OPCODE_GCNAPPEND          : return "BRIG_OPCODE_GCNAPPEND";
    case BRIG_OPCODE_GCNATOMIC          : return "BRIG_OPCODE_GCNATOMIC";
    case BRIG_OPCODE_GCNATOMICNORET     : return "BRIG_OPCODE_GCNATOMICNORET";
    case BRIG_OPCODE_GCNB32XCHG         : return "BRIG_OPCODE_GCNB32XCHG";
    case BRIG_OPCODE_GCNB4XCHG          : return "BRIG_OPCODE_GCNB4XCHG";
    case BRIG_OPCODE_GCNBFM             : return "BRIG_OPCODE_GCNBFM";
    case BRIG_OPCODE_GCNCONSUME         : return "BRIG_OPCODE_GCNCONSUME";
    case BRIG_OPCODE_GCNFLDEXP          : return "BRIG_OPCODE_GCNFLDEXP";
    case BRIG_OPCODE_GCNFREXP_EXP       : return "BRIG_OPCODE_GCNFREXP_EXP";
    case BRIG_OPCODE_GCNFREXP_MANT      : return "BRIG_OPCODE_GCNFREXP_MANT";
    case BRIG_OPCODE_GCNLD              : return "BRIG_OPCODE_GCNLD";
    case BRIG_OPCODE_GCNMADS            : return "BRIG_OPCODE_GCNMADS";
    case BRIG_OPCODE_GCNMADU            : return "BRIG_OPCODE_GCNMADU";
    case BRIG_OPCODE_GCNMAX             : return "BRIG_OPCODE_GCNMAX";
    case BRIG_OPCODE_GCNMAX3            : return "BRIG_OPCODE_GCNMAX3";
    case BRIG_OPCODE_GCNMED3            : return "BRIG_OPCODE_GCNMED3";
    case BRIG_OPCODE_GCNMIN             : return "BRIG_OPCODE_GCNMIN";
    case BRIG_OPCODE_GCNMIN3            : return "BRIG_OPCODE_GCNMIN3";
    case BRIG_OPCODE_GCNMQSAD           : return "BRIG_OPCODE_GCNMQSAD";
    case BRIG_OPCODE_GCNMQSAD4          : return "BRIG_OPCODE_GCNMQSAD4";
    case BRIG_OPCODE_GCNMSAD            : return "BRIG_OPCODE_GCNMSAD";
    case BRIG_OPCODE_GCNPRIORITY        : return "BRIG_OPCODE_GCNPRIORITY";
    case BRIG_OPCODE_GCNQSAD            : return "BRIG_OPCODE_GCNQSAD";
    case BRIG_OPCODE_GCNREGIONALLOC     : return "BRIG_OPCODE_GCNREGIONALLOC";
    case BRIG_OPCODE_GCNSADD            : return "BRIG_OPCODE_GCNSADD";
    case BRIG_OPCODE_GCNSADW            : return "BRIG_OPCODE_GCNSADW";
    case BRIG_OPCODE_GCNSLEEP           : return "BRIG_OPCODE_GCNSLEEP";
    case BRIG_OPCODE_GCNST              : return "BRIG_OPCODE_GCNST";
    case BRIG_OPCODE_GCNTRIG_PREOP      : return "BRIG_OPCODE_GCNTRIG_PREOP";
    case BRIG_OPCODE_GETDETECTEXCEPT    : return "BRIG_OPCODE_GETDETECTEXCEPT";
    case BRIG_OPCODE_GRIDGROUPS         : return "BRIG_OPCODE_GRIDGROUPS";
    case BRIG_OPCODE_GRIDSIZE           : return "BRIG_OPCODE_GRIDSIZE";
    case BRIG_OPCODE_GROUPBASEPTR       : return "BRIG_OPCODE_GROUPBASEPTR";
    case BRIG_OPCODE_ICALL              : return "BRIG_OPCODE_ICALL";
    case BRIG_OPCODE_INITFBAR           : return "BRIG_OPCODE_INITFBAR";
    case BRIG_OPCODE_JOINFBAR           : return "BRIG_OPCODE_JOINFBAR";
    case BRIG_OPCODE_KERNARGBASEPTR     : return "BRIG_OPCODE_KERNARGBASEPTR";
    case BRIG_OPCODE_LANEID             : return "BRIG_OPCODE_LANEID";
    case BRIG_OPCODE_LASTBIT            : return "BRIG_OPCODE_LASTBIT";
    case BRIG_OPCODE_LD                 : return "BRIG_OPCODE_LD";
    case BRIG_OPCODE_LDA                : return "BRIG_OPCODE_LDA";
    case BRIG_OPCODE_LDF                : return "BRIG_OPCODE_LDF";
    case BRIG_OPCODE_LDI                : return "BRIG_OPCODE_LDI";
    case BRIG_OPCODE_LDIMAGE            : return "BRIG_OPCODE_LDIMAGE";
    case BRIG_OPCODE_LDK                : return "BRIG_OPCODE_LDK";
    case BRIG_OPCODE_LDQUEUEREADINDEX   : return "BRIG_OPCODE_LDQUEUEREADINDEX";
    case BRIG_OPCODE_LDQUEUEWRITEINDEX  : return "BRIG_OPCODE_LDQUEUEWRITEINDEX";
    case BRIG_OPCODE_LEAVEFBAR          : return "BRIG_OPCODE_LEAVEFBAR";
    case BRIG_OPCODE_LERP               : return "BRIG_OPCODE_LERP";
    case BRIG_OPCODE_MAD                : return "BRIG_OPCODE_MAD";
    case BRIG_OPCODE_MAD24              : return "BRIG_OPCODE_MAD24";
    case BRIG_OPCODE_MAD24HI            : return "BRIG_OPCODE_MAD24HI";
    case BRIG_OPCODE_MAX                : return "BRIG_OPCODE_MAX";
    case BRIG_OPCODE_MAXCUID            : return "BRIG_OPCODE_MAXCUID";
    case BRIG_OPCODE_MAXWAVEID          : return "BRIG_OPCODE_MAXWAVEID";
    case BRIG_OPCODE_MEMFENCE           : return "BRIG_OPCODE_MEMFENCE";
    case BRIG_OPCODE_MIN                : return "BRIG_OPCODE_MIN";
    case BRIG_OPCODE_MOV                : return "BRIG_OPCODE_MOV";
    case BRIG_OPCODE_MUL                : return "BRIG_OPCODE_MUL";
    case BRIG_OPCODE_MUL24              : return "BRIG_OPCODE_MUL24";
    case BRIG_OPCODE_MUL24HI            : return "BRIG_OPCODE_MUL24HI";
    case BRIG_OPCODE_MULHI              : return "BRIG_OPCODE_MULHI";
    case BRIG_OPCODE_NCOS               : return "BRIG_OPCODE_NCOS";
    case BRIG_OPCODE_NEG                : return "BRIG_OPCODE_NEG";
    case BRIG_OPCODE_NEXP2              : return "BRIG_OPCODE_NEXP2";
    case BRIG_OPCODE_NFMA               : return "BRIG_OPCODE_NFMA";
    case BRIG_OPCODE_NLOG2              : return "BRIG_OPCODE_NLOG2";
    case BRIG_OPCODE_NOP                : return "BRIG_OPCODE_NOP";
    case BRIG_OPCODE_NOT                : return "BRIG_OPCODE_NOT";
    case BRIG_OPCODE_NRCP               : return "BRIG_OPCODE_NRCP";
    case BRIG_OPCODE_NRSQRT             : return "BRIG_OPCODE_NRSQRT";
    case BRIG_OPCODE_NSIN               : return "BRIG_OPCODE_NSIN";
    case BRIG_OPCODE_NSQRT              : return "BRIG_OPCODE_NSQRT";
    case BRIG_OPCODE_NULLPTR            : return "BRIG_OPCODE_NULLPTR";
    case BRIG_OPCODE_OR                 : return "BRIG_OPCODE_OR";
    case BRIG_OPCODE_PACK               : return "BRIG_OPCODE_PACK";
    case BRIG_OPCODE_PACKCVT            : return "BRIG_OPCODE_PACKCVT";
    case BRIG_OPCODE_PACKETCOMPLETIONSIG : return "BRIG_OPCODE_PACKETCOMPLETIONSIG";
    case BRIG_OPCODE_PACKETID           : return "BRIG_OPCODE_PACKETID";
    case BRIG_OPCODE_POPCOUNT           : return "BRIG_OPCODE_POPCOUNT";
    case BRIG_OPCODE_QUERYIMAGE         : return "BRIG_OPCODE_QUERYIMAGE";
    case BRIG_OPCODE_QUERYSAMPLER       : return "BRIG_OPCODE_QUERYSAMPLER";
    case BRIG_OPCODE_QUEUEID            : return "BRIG_OPCODE_QUEUEID";
    case BRIG_OPCODE_QUEUEPTR           : return "BRIG_OPCODE_QUEUEPTR";
    case BRIG_OPCODE_RDIMAGE            : return "BRIG_OPCODE_RDIMAGE";
    case BRIG_OPCODE_RELEASEFBAR        : return "BRIG_OPCODE_RELEASEFBAR";
    case BRIG_OPCODE_REM                : return "BRIG_OPCODE_REM";
    case BRIG_OPCODE_RET                : return "BRIG_OPCODE_RET";
    case BRIG_OPCODE_RINT               : return "BRIG_OPCODE_RINT";
    case BRIG_OPCODE_SAD                : return "BRIG_OPCODE_SAD";
    case BRIG_OPCODE_SADHI              : return "BRIG_OPCODE_SADHI";
    case BRIG_OPCODE_SBR                : return "BRIG_OPCODE_SBR";
    case BRIG_OPCODE_SCALL              : return "BRIG_OPCODE_SCALL";
    case BRIG_OPCODE_SEGMENTP           : return "BRIG_OPCODE_SEGMENTP";
    case BRIG_OPCODE_SETDETECTEXCEPT    : return "BRIG_OPCODE_SETDETECTEXCEPT";
    case BRIG_OPCODE_SHL                : return "BRIG_OPCODE_SHL";
    case BRIG_OPCODE_SHR                : return "BRIG_OPCODE_SHR";
    case BRIG_OPCODE_SHUFFLE            : return "BRIG_OPCODE_SHUFFLE";
    case BRIG_OPCODE_SIGNAL             : return "BRIG_OPCODE_SIGNAL";
    case BRIG_OPCODE_SIGNALNORET        : return "BRIG_OPCODE_SIGNALNORET";
    case BRIG_OPCODE_SQRT               : return "BRIG_OPCODE_SQRT";
    case BRIG_OPCODE_ST                 : return "BRIG_OPCODE_ST";
    case BRIG_OPCODE_STIMAGE            : return "BRIG_OPCODE_STIMAGE";
    case BRIG_OPCODE_STOF               : return "BRIG_OPCODE_STOF";
    case BRIG_OPCODE_STQUEUEREADINDEX   : return "BRIG_OPCODE_STQUEUEREADINDEX";
    case BRIG_OPCODE_STQUEUEWRITEINDEX  : return "BRIG_OPCODE_STQUEUEWRITEINDEX";
    case BRIG_OPCODE_SUB                : return "BRIG_OPCODE_SUB";
    case BRIG_OPCODE_TRUNC              : return "BRIG_OPCODE_TRUNC";
    case BRIG_OPCODE_UNPACK             : return "BRIG_OPCODE_UNPACK";
    case BRIG_OPCODE_UNPACKCVT          : return "BRIG_OPCODE_UNPACKCVT";
    case BRIG_OPCODE_UNPACKHI           : return "BRIG_OPCODE_UNPACKHI";
    case BRIG_OPCODE_UNPACKLO           : return "BRIG_OPCODE_UNPACKLO";
    case BRIG_OPCODE_WAITFBAR           : return "BRIG_OPCODE_WAITFBAR";
    case BRIG_OPCODE_WAVEBARRIER        : return "BRIG_OPCODE_WAVEBARRIER";
    case BRIG_OPCODE_WAVEID             : return "BRIG_OPCODE_WAVEID";
    case BRIG_OPCODE_WORKGROUPID        : return "BRIG_OPCODE_WORKGROUPID";
    case BRIG_OPCODE_WORKGROUPSIZE      : return "BRIG_OPCODE_WORKGROUPSIZE";
    case BRIG_OPCODE_WORKITEMABSID      : return "BRIG_OPCODE_WORKITEMABSID";
    case BRIG_OPCODE_WORKITEMFLATABSID  : return "BRIG_OPCODE_WORKITEMFLATABSID";
    case BRIG_OPCODE_WORKITEMFLATID     : return "BRIG_OPCODE_WORKITEMFLATID";
    case BRIG_OPCODE_WORKITEMID         : return "BRIG_OPCODE_WORKITEMID";
    case BRIG_OPCODE_XOR                : return "BRIG_OPCODE_XOR";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigPack arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_PACK_NONE                 : return "BRIG_PACK_NONE";
    case BRIG_PACK_P                    : return "BRIG_PACK_P";
    case BRIG_PACK_PP                   : return "BRIG_PACK_PP";
    case BRIG_PACK_PPSAT                : return "BRIG_PACK_PPSAT";
    case BRIG_PACK_PS                   : return "BRIG_PACK_PS";
    case BRIG_PACK_PSAT                 : return "BRIG_PACK_PSAT";
    case BRIG_PACK_PSSAT                : return "BRIG_PACK_PSSAT";
    case BRIG_PACK_S                    : return "BRIG_PACK_S";
    case BRIG_PACK_SP                   : return "BRIG_PACK_SP";
    case BRIG_PACK_SPSAT                : return "BRIG_PACK_SPSAT";
    case BRIG_PACK_SS                   : return "BRIG_PACK_SS";
    case BRIG_PACK_SSAT                 : return "BRIG_PACK_SSAT";
    case BRIG_PACK_SSSAT                : return "BRIG_PACK_SSSAT";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigProfile arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_PROFILE_BASE              : return "BRIG_PROFILE_BASE";
    case BRIG_PROFILE_FULL              : return "BRIG_PROFILE_FULL";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigRegisterKind arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_REGISTER_CONTROL          : return "BRIG_REGISTER_CONTROL";
    case BRIG_REGISTER_DOUBLE           : return "BRIG_REGISTER_DOUBLE";
    case BRIG_REGISTER_QUAD             : return "BRIG_REGISTER_QUAD";
    case BRIG_REGISTER_SINGLE           : return "BRIG_REGISTER_SINGLE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigRound arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ROUND_FLOAT_MINUS_INFINITY : return "BRIG_ROUND_FLOAT_MINUS_INFINITY";
    case BRIG_ROUND_FLOAT_NEAR_EVEN     : return "BRIG_ROUND_FLOAT_NEAR_EVEN";
    case BRIG_ROUND_FLOAT_PLUS_INFINITY : return "BRIG_ROUND_FLOAT_PLUS_INFINITY";
    case BRIG_ROUND_FLOAT_ZERO          : return "BRIG_ROUND_FLOAT_ZERO";
    case BRIG_ROUND_INTEGER_MINUS_INFINITY : return "BRIG_ROUND_INTEGER_MINUS_INFINITY";
    case BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT : return "BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT";
    case BRIG_ROUND_INTEGER_NEAR_EVEN   : return "BRIG_ROUND_INTEGER_NEAR_EVEN";
    case BRIG_ROUND_INTEGER_NEAR_EVEN_SAT : return "BRIG_ROUND_INTEGER_NEAR_EVEN_SAT";
    case BRIG_ROUND_INTEGER_PLUS_INFINITY : return "BRIG_ROUND_INTEGER_PLUS_INFINITY";
    case BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT : return "BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT";
    case BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY : return "BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY";
    case BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY_SAT : return "BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY_SAT";
    case BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN : return "BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN";
    case BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN_SAT : return "BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN_SAT";
    case BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY : return "BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY";
    case BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY_SAT : return "BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY_SAT";
    case BRIG_ROUND_INTEGER_SIGNALLING_ZERO : return "BRIG_ROUND_INTEGER_SIGNALLING_ZERO";
    case BRIG_ROUND_INTEGER_SIGNALLING_ZERO_SAT : return "BRIG_ROUND_INTEGER_SIGNALLING_ZERO_SAT";
    case BRIG_ROUND_INTEGER_ZERO        : return "BRIG_ROUND_INTEGER_ZERO";
    case BRIG_ROUND_INTEGER_ZERO_SAT    : return "BRIG_ROUND_INTEGER_ZERO_SAT";
    case BRIG_ROUND_NONE                : return "BRIG_ROUND_NONE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSamplerAddressing arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ADDRESSING_CLAMP_TO_BORDER : return "BRIG_ADDRESSING_CLAMP_TO_BORDER";
    case BRIG_ADDRESSING_CLAMP_TO_EDGE  : return "BRIG_ADDRESSING_CLAMP_TO_EDGE";
    case BRIG_ADDRESSING_MIRRORED_REPEAT : return "BRIG_ADDRESSING_MIRRORED_REPEAT";
    case BRIG_ADDRESSING_REPEAT         : return "BRIG_ADDRESSING_REPEAT";
    case BRIG_ADDRESSING_UNDEFINED      : return "BRIG_ADDRESSING_UNDEFINED";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSamplerCoordNormalization arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_COORD_NORMALIZED          : return "BRIG_COORD_NORMALIZED";
    case BRIG_COORD_UNNORMALIZED        : return "BRIG_COORD_UNNORMALIZED";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSamplerFilter arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_FILTER_LINEAR             : return "BRIG_FILTER_LINEAR";
    case BRIG_FILTER_NEAREST            : return "BRIG_FILTER_NEAREST";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSamplerQuery arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SAMPLER_QUERY_ADDRESSING  : return "BRIG_SAMPLER_QUERY_ADDRESSING";
    case BRIG_SAMPLER_QUERY_COORD       : return "BRIG_SAMPLER_QUERY_COORD";
    case BRIG_SAMPLER_QUERY_FILTER      : return "BRIG_SAMPLER_QUERY_FILTER";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSectionIndex arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SECTION_INDEX_BEGIN_IMPLEMENTATION_DEFINED : return "BRIG_SECTION_INDEX_BEGIN_IMPLEMENTATION_DEFINED";
    case BRIG_SECTION_INDEX_CODE        : return "BRIG_SECTION_INDEX_CODE";
    case BRIG_SECTION_INDEX_DATA        : return "BRIG_SECTION_INDEX_DATA";
    case BRIG_SECTION_INDEX_OPERAND     : return "BRIG_SECTION_INDEX_OPERAND";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSegCvtModifierMask arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SEG_CVT_NONULL            : return "BRIG_SEG_CVT_NONULL";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSegment arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SEGMENT_ARG               : return "BRIG_SEGMENT_ARG";
    case BRIG_SEGMENT_EXTSPACE0         : return "BRIG_SEGMENT_EXTSPACE0";
    case BRIG_SEGMENT_FLAT              : return "BRIG_SEGMENT_FLAT";
    case BRIG_SEGMENT_GLOBAL            : return "BRIG_SEGMENT_GLOBAL";
    case BRIG_SEGMENT_GROUP             : return "BRIG_SEGMENT_GROUP";
    case BRIG_SEGMENT_KERNARG           : return "BRIG_SEGMENT_KERNARG";
    case BRIG_SEGMENT_NONE              : return "BRIG_SEGMENT_NONE";
    case BRIG_SEGMENT_PRIVATE           : return "BRIG_SEGMENT_PRIVATE";
    case BRIG_SEGMENT_READONLY          : return "BRIG_SEGMENT_READONLY";
    case BRIG_SEGMENT_SPILL             : return "BRIG_SEGMENT_SPILL";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigTypeX arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_TYPE_B1                   : return "BRIG_TYPE_B1";
    case BRIG_TYPE_B128                 : return "BRIG_TYPE_B128";
    case BRIG_TYPE_B16                  : return "BRIG_TYPE_B16";
    case BRIG_TYPE_B32                  : return "BRIG_TYPE_B32";
    case BRIG_TYPE_B64                  : return "BRIG_TYPE_B64";
    case BRIG_TYPE_B8                   : return "BRIG_TYPE_B8";
    case BRIG_TYPE_F16                  : return "BRIG_TYPE_F16";
    case BRIG_TYPE_F16X2                : return "BRIG_TYPE_F16X2";
    case BRIG_TYPE_F16X4                : return "BRIG_TYPE_F16X4";
    case BRIG_TYPE_F16X8                : return "BRIG_TYPE_F16X8";
    case BRIG_TYPE_F32                  : return "BRIG_TYPE_F32";
    case BRIG_TYPE_F32X2                : return "BRIG_TYPE_F32X2";
    case BRIG_TYPE_F32X4                : return "BRIG_TYPE_F32X4";
    case BRIG_TYPE_F64                  : return "BRIG_TYPE_F64";
    case BRIG_TYPE_F64X2                : return "BRIG_TYPE_F64X2";
    case BRIG_TYPE_NONE                 : return "BRIG_TYPE_NONE";
    case BRIG_TYPE_ROIMG                : return "BRIG_TYPE_ROIMG";
    case BRIG_TYPE_RWIMG                : return "BRIG_TYPE_RWIMG";
    case BRIG_TYPE_S16                  : return "BRIG_TYPE_S16";
    case BRIG_TYPE_S16X2                : return "BRIG_TYPE_S16X2";
    case BRIG_TYPE_S16X4                : return "BRIG_TYPE_S16X4";
    case BRIG_TYPE_S16X8                : return "BRIG_TYPE_S16X8";
    case BRIG_TYPE_S32                  : return "BRIG_TYPE_S32";
    case BRIG_TYPE_S32X2                : return "BRIG_TYPE_S32X2";
    case BRIG_TYPE_S32X4                : return "BRIG_TYPE_S32X4";
    case BRIG_TYPE_S64                  : return "BRIG_TYPE_S64";
    case BRIG_TYPE_S64X2                : return "BRIG_TYPE_S64X2";
    case BRIG_TYPE_S8                   : return "BRIG_TYPE_S8";
    case BRIG_TYPE_S8X16                : return "BRIG_TYPE_S8X16";
    case BRIG_TYPE_S8X4                 : return "BRIG_TYPE_S8X4";
    case BRIG_TYPE_S8X8                 : return "BRIG_TYPE_S8X8";
    case BRIG_TYPE_SAMP                 : return "BRIG_TYPE_SAMP";
    case BRIG_TYPE_SIG32                : return "BRIG_TYPE_SIG32";
    case BRIG_TYPE_SIG64                : return "BRIG_TYPE_SIG64";
    case BRIG_TYPE_U16                  : return "BRIG_TYPE_U16";
    case BRIG_TYPE_U16X2                : return "BRIG_TYPE_U16X2";
    case BRIG_TYPE_U16X4                : return "BRIG_TYPE_U16X4";
    case BRIG_TYPE_U16X8                : return "BRIG_TYPE_U16X8";
    case BRIG_TYPE_U32                  : return "BRIG_TYPE_U32";
    case BRIG_TYPE_U32X2                : return "BRIG_TYPE_U32X2";
    case BRIG_TYPE_U32X4                : return "BRIG_TYPE_U32X4";
    case BRIG_TYPE_U64                  : return "BRIG_TYPE_U64";
    case BRIG_TYPE_U64X2                : return "BRIG_TYPE_U64X2";
    case BRIG_TYPE_U8                   : return "BRIG_TYPE_U8";
    case BRIG_TYPE_U8X16                : return "BRIG_TYPE_U8X16";
    case BRIG_TYPE_U8X4                 : return "BRIG_TYPE_U8X4";
    case BRIG_TYPE_U8X8                 : return "BRIG_TYPE_U8X8";
    case BRIG_TYPE_WOIMG                : return "BRIG_TYPE_WOIMG";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigWidth arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_WIDTH_1                   : return "BRIG_WIDTH_1";
    case BRIG_WIDTH_1024                : return "BRIG_WIDTH_1024";
    case BRIG_WIDTH_1048576             : return "BRIG_WIDTH_1048576";
    case BRIG_WIDTH_1073741824          : return "BRIG_WIDTH_1073741824";
    case BRIG_WIDTH_128                 : return "BRIG_WIDTH_128";
    case BRIG_WIDTH_131072              : return "BRIG_WIDTH_131072";
    case BRIG_WIDTH_134217728           : return "BRIG_WIDTH_134217728";
    case BRIG_WIDTH_16                  : return "BRIG_WIDTH_16";
    case BRIG_WIDTH_16384               : return "BRIG_WIDTH_16384";
    case BRIG_WIDTH_16777216            : return "BRIG_WIDTH_16777216";
    case BRIG_WIDTH_2                   : return "BRIG_WIDTH_2";
    case BRIG_WIDTH_2048                : return "BRIG_WIDTH_2048";
    case BRIG_WIDTH_2097152             : return "BRIG_WIDTH_2097152";
    case BRIG_WIDTH_2147483648          : return "BRIG_WIDTH_2147483648";
    case BRIG_WIDTH_256                 : return "BRIG_WIDTH_256";
    case BRIG_WIDTH_262144              : return "BRIG_WIDTH_262144";
    case BRIG_WIDTH_268435456           : return "BRIG_WIDTH_268435456";
    case BRIG_WIDTH_32                  : return "BRIG_WIDTH_32";
    case BRIG_WIDTH_32768               : return "BRIG_WIDTH_32768";
    case BRIG_WIDTH_33554432            : return "BRIG_WIDTH_33554432";
    case BRIG_WIDTH_4                   : return "BRIG_WIDTH_4";
    case BRIG_WIDTH_4096                : return "BRIG_WIDTH_4096";
    case BRIG_WIDTH_4194304             : return "BRIG_WIDTH_4194304";
    case BRIG_WIDTH_512                 : return "BRIG_WIDTH_512";
    case BRIG_WIDTH_524288              : return "BRIG_WIDTH_524288";
    case BRIG_WIDTH_536870912           : return "BRIG_WIDTH_536870912";
    case BRIG_WIDTH_64                  : return "BRIG_WIDTH_64";
    case BRIG_WIDTH_65536               : return "BRIG_WIDTH_65536";
    case BRIG_WIDTH_67108864            : return "BRIG_WIDTH_67108864";
    case BRIG_WIDTH_8                   : return "BRIG_WIDTH_8";
    case BRIG_WIDTH_8192                : return "BRIG_WIDTH_8192";
    case BRIG_WIDTH_8388608             : return "BRIG_WIDTH_8388608";
    case BRIG_WIDTH_ALL                 : return "BRIG_WIDTH_ALL";
    case BRIG_WIDTH_NONE                : return "BRIG_WIDTH_NONE";
    case BRIG_WIDTH_WAVESIZE            : return "BRIG_WIDTH_WAVESIZE";
    default : return "??";
    }
}

