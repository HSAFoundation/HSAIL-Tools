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

Inst appendInst(BrigContainer &container, unsigned instFormat)
{
    using namespace Brig;

    switch(instFormat)
    {
    case BRIG_KIND_INST_ADDR: return container.append<InstAddr>();
    case BRIG_KIND_INST_ATOMIC: return container.append<InstAtomic>();
    case BRIG_KIND_INST_BASIC: return container.append<InstBasic>();
    case BRIG_KIND_INST_BR: return container.append<InstBr>();
    case BRIG_KIND_INST_CMP: return container.append<InstCmp>();
    case BRIG_KIND_INST_CVT: return container.append<InstCvt>();
    case BRIG_KIND_INST_IMAGE: return container.append<InstImage>();
    case BRIG_KIND_INST_LANE: return container.append<InstLane>();
    case BRIG_KIND_INST_MEM: return container.append<InstMem>();
    case BRIG_KIND_INST_MEM_FENCE: return container.append<InstMemFence>();
    case BRIG_KIND_INST_MOD: return container.append<InstMod>();
    case BRIG_KIND_INST_QUERY_IMAGE: return container.append<InstQueryImage>();
    case BRIG_KIND_INST_QUERY_SAMPLER: return container.append<InstQuerySampler>();
    case BRIG_KIND_INST_QUEUE: return container.append<InstQueue>();
    case BRIG_KIND_INST_SEG: return container.append<InstSeg>();
    case BRIG_KIND_INST_SEG_CVT: return container.append<InstSegCvt>();
    case BRIG_KIND_INST_SIGNAL: return container.append<InstSignal>();
    case BRIG_KIND_INST_SOURCE_TYPE: return container.append<InstSourceType>();
    default:
        assert(false);
        return Inst();
    }
}
