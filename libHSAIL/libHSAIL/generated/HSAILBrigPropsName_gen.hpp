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

static const char* getBrigPropName(unsigned prop)
{
    switch(prop)
    {
    case PROP_ALIGN: return "align";
    case PROP_ATOMICOPERATION: return "atomicOperation";
    case PROP_COMPARE: return "compare";
    case PROP_COORDTYPE: return "coordType";
    case PROP_EQUIVCLASS: return "equivClass";
    case PROP_FTZ: return "ftz";
    case PROP_GEOMETRY: return "geometry";
    case PROP_IMAGETYPE: return "imageType";
    case PROP_ISCONST: return "isConst";
    case PROP_ISNONULL: return "isNoNull";
    case PROP_MEMORYORDER: return "memoryOrder";
    case PROP_MEMORYSCOPE: return "memoryScope";
    case PROP_OPCODE: return "opcode";
    case PROP_PACK: return "pack";
    case PROP_ROUND: return "round";
    case PROP_SEGMENT: return "segment";
    case PROP_SEGMENTS: return "segments";
    case PROP_SIGNALOPERATION: return "signalOperation";
    case PROP_SIGNALTYPE: return "signalType";
    case PROP_SOURCETYPE: return "sourceType";
    case PROP_TYPE: return "type";
    case PROP_WIDTH: return "width";
    default: 
        assert(false);
        return "";
    }
}
