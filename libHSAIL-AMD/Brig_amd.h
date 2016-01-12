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

//.ignore{

#ifndef INCLUDED_BRIG_AMD_H
#define INCLUDED_BRIG_AMD_H

#include "Brig.h"

#define AMD_GCN_EXTENSION_NAME              "amd:gcn"
#define AMD_GCN_EXTENSION_OPCODE_PREFIX     "amd_gcn"

#define AMD_MIPMAP_EXTENSION_NAME           "amd:mipmap"
#define AMD_MIPMAP_EXTENSION_OPCODE_PREFIX  "amd_mipmap"

#define AMD_DG_EXTENSION_NAME               "amd:dg"
#define AMD_DG_EXTENSION_OPCODE_PREFIX      "amd_dg"

#define AMD_GCN_SEGMENT_NAME                "region"
#define AMD_MIPMAP_QUERY                    "nummiplevels"

//}

enum BrigOpcodeAmdGcn {
    BRIG_OPCODE_AMD_GCN_MADU             = BRIG_OPCODE_FIRST_USER_DEFINED,
    BRIG_OPCODE_AMD_GCN_MADS,
    BRIG_OPCODE_AMD_GCN_MAX3,
    BRIG_OPCODE_AMD_GCN_MIN3,
    BRIG_OPCODE_AMD_GCN_MED3,
    BRIG_OPCODE_AMD_GCN_FLDEXP,
    BRIG_OPCODE_AMD_GCN_FREXP_EXP,
    BRIG_OPCODE_AMD_GCN_FREXP_MANT,
    BRIG_OPCODE_AMD_GCN_TRIG_PREOP,
    BRIG_OPCODE_AMD_GCN_BFM,
    BRIG_OPCODE_AMD_GCN_LD,
    BRIG_OPCODE_AMD_GCN_ST,
    BRIG_OPCODE_AMD_GCN_ATOMIC,
    BRIG_OPCODE_AMD_GCN_ATOMICNORET,
    BRIG_OPCODE_AMD_GCN_SLEEP,
    BRIG_OPCODE_AMD_GCN_PRIORITY,
    BRIG_OPCODE_AMD_GCN_REGIONALLOC,
    BRIG_OPCODE_AMD_GCN_MSAD,
    BRIG_OPCODE_AMD_GCN_QSAD,
    BRIG_OPCODE_AMD_GCN_MQSAD,
    BRIG_OPCODE_AMD_GCN_MQSAD4,
    BRIG_OPCODE_AMD_GCN_SADW,
    BRIG_OPCODE_AMD_GCN_SADD,
    BRIG_OPCODE_AMD_GCN_CONSUME,
    BRIG_OPCODE_AMD_GCN_APPEND,
    BRIG_OPCODE_AMD_GCN_B4XCHG,
    BRIG_OPCODE_AMD_GCN_B32XCHG,
    BRIG_OPCODE_AMD_GCN_MAX,
    BRIG_OPCODE_AMD_GCN_MIN,
    BRIG_OPCODE_AMD_GCN_DIVRELAXED,
    BRIG_OPCODE_AMD_GCN_DIVRELAXEDNARROW,

    BRIG_OPCODE_AMD_GCN_FIRST_UNUSED
};

enum BrigOpcodeAmdMipmap {
    BRIG_OPCODE_AMD_MIPMAP_RDIMAGELOD    = BRIG_OPCODE_AMD_GCN_FIRST_UNUSED,
    BRIG_OPCODE_AMD_MIPMAP_RDIMAGEGRAD,
    BRIG_OPCODE_AMD_MIPMAP_LDIMAGEMIP,
    BRIG_OPCODE_AMD_MIPMAP_STIMAGEMIP,
    BRIG_OPCODE_AMD_MIPMAP_QUERYIMAGE,

    BRIG_OPCODE_AMD_MIPMAP_FIRST_UNUSED
};

enum BrigOpcodeAmdDg {
    BRIG_OPCODE_AMD_DG_GROUPSTATICSIZE   = BRIG_OPCODE_AMD_MIPMAP_FIRST_UNUSED,
    BRIG_OPCODE_AMD_DG_GROUPTOTALSIZE,

    BRIG_OPCODE_AMD_DG_FIRST_UNUSED
};

enum BrigSegmentAmdGcn {
    BRIG_SEGMENT_AMD_GCN = BRIG_SEGMENT_FIRST_USER_DEFINED,
};

enum BrigImageQueryAmdMipmap {
    BRIG_IMAGE_QUERY_AMD_MIPMAP_NUMMIPLEVELS = BRIG_IMAGE_QUERY_FIRST_USER_DEFINED,
};

//.ignore{

#endif

//}
