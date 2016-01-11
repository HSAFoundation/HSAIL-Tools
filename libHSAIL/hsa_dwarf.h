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
#ifndef __HSA_DWARF_H_INCLUDED__
#define __HSA_DWARF_H_INCLUDED__

#define DW_TAG_HSA_argument_scope 0x8000 /* HSA */

#define DW_AT_HSA_is_kernel         0x3000 /* HSA. flag, constant, boolean.  Is this DW_TAG_subprogram a kernel (if not, it's a plain function)? */
#define DW_AT_HSA_is_outParam       0x3001 /* HSA. flag, constant, boolean.  Is this DW_TAG_formal_parameter an output parameter? */
#define DW_AT_HSA_workitemid_offset 0x3002 /* Used for ISA DWARF only */
#define DW_AT_HSA_isa_memory_region 0x3003 /* Used for ISA DWARF only */
#define DW_AT_HSA_brig_offset       0x3004 /* Used for ISA DWARF only */

#define DW_LANG_HSA_Assembly      0x9000
#define DW_LANG_BRIG              0x9001

enum {
  __R_HSA_NONE = 0,
  __R_HSA_DWARF_32 = 3,
  __R_HSA_DWARF_TO_BRIG_CODE32 = 4,
  __R_HSA_DWARF_TO_BRIG_DIRECTIVES32 = 5,
  __R_HSA_DWARF_64 = 6,
  __R_HSA_DWARF_TO_BRIG_CODE64 = 7,
  __R_HSA_DWARF_TO_BRIG_DIRECTIVES64 = 8,
};

#ifndef EM_HSAIL
#define EM_HSAIL 0xAF5A
#endif

#define NT_AMDGPU_HSA_PRODUCER            4
#define NT_AMDGPU_HSA_PRODUCER_OPTIONS    5
#define NT_AMDGPU_HSA_HLDEBUG_DEBUG     101

#endif // #ifndef __HSA_DWARF_H_INCLUDED__
