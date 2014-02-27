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

void registerBrigProps(Inst inst)
{
    using namespace Brig;

    switch(inst.kind())
    {
        case BRIG_INST_ADDR:
        {
            InstAddr it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SEGMENT, it.segment());
        }
        break;

        case BRIG_INST_ATOMIC:
        {
            InstAtomic it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SEGMENT, it.segment());
            addProp(inst, PROP_MEMORYORDER, it.memoryOrder());
            addProp(inst, PROP_MEMORYSCOPE, it.memoryScope());
            addProp(inst, PROP_ATOMICOPERATION, it.atomicOperation());
            addProp(inst, PROP_EQUIVCLASS, it.equivClass());
        }
        break;

        case BRIG_INST_ATOMIC_IMAGE:
        {
            InstAtomicImage it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_IMAGETYPE, it.imageType());
            addProp(inst, PROP_COORDTYPE, it.coordType());
            addProp(inst, PROP_GEOMETRY, it.geometry());
            addProp(inst, PROP_ATOMICOPERATION, it.atomicOperation());
            addProp(inst, PROP_EQUIVCLASS, it.equivClass());
        }
        break;

        case BRIG_INST_BASIC:
        {
            InstBasic it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
        }
        break;

        case BRIG_INST_BR:
        {
            InstBr it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_WIDTH, it.width());
        }
        break;

        case BRIG_INST_CMP:
        {
            InstCmp it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SOURCETYPE, it.sourceType());
            addProp(inst, PROP_ROUND, it.modifier().round());
            addProp(inst, PROP_FTZ, it.modifier().ftz());
            addProp(inst, PROP_COMPARE, it.compare());
            addProp(inst, PROP_PACK, it.pack());
        }
        break;

        case BRIG_INST_CVT:
        {
            InstCvt it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SOURCETYPE, it.sourceType());
            addProp(inst, PROP_ROUND, it.modifier().round());
            addProp(inst, PROP_FTZ, it.modifier().ftz());
        }
        break;

        case BRIG_INST_IMAGE:
        {
            InstImage it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_IMAGETYPE, it.imageType());
            addProp(inst, PROP_COORDTYPE, it.coordType());
            addProp(inst, PROP_GEOMETRY, it.geometry());
            addProp(inst, PROP_EQUIVCLASS, it.equivClass());
        }
        break;

        case BRIG_INST_LANE:
        {
            InstLane it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SOURCETYPE, it.sourceType());
            addProp(inst, PROP_WIDTH, it.width());
        }
        break;

        case BRIG_INST_MEM:
        {
            InstMem it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SEGMENT, it.segment());
            addProp(inst, PROP_ALIGN, it.align());
            addProp(inst, PROP_EQUIVCLASS, it.equivClass());
            addProp(inst, PROP_WIDTH, it.width());
            addProp(inst, PROP_ISCONST, it.modifier().isConst());
        }
        break;

        case BRIG_INST_MEM_FENCE:
        {
            InstMemFence it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SEGMENTS, it.segments());
            addProp(inst, PROP_MEMORYORDER, it.memoryOrder());
            addProp(inst, PROP_MEMORYSCOPE, it.memoryScope());
        }
        break;

        case BRIG_INST_MOD:
        {
            InstMod it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_ROUND, it.modifier().round());
            addProp(inst, PROP_FTZ, it.modifier().ftz());
            addProp(inst, PROP_PACK, it.pack());
        }
        break;

        case BRIG_INST_QUEUE:
        {
            InstQueue it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SEGMENT, it.segment());
            addProp(inst, PROP_MEMORYORDER, it.memoryOrder());
        }
        break;

        case BRIG_INST_SEG:
        {
            InstSeg it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SEGMENT, it.segment());
        }
        break;

        case BRIG_INST_SEG_CVT:
        {
            InstSegCvt it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SOURCETYPE, it.sourceType());
            addProp(inst, PROP_SEGMENT, it.segment());
            addProp(inst, PROP_ISNONULL, it.modifier().isNoNull());
        }
        break;

        case BRIG_INST_SIGNAL:
        {
            InstSignal it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SIGNALTYPE, it.signalType());
            addProp(inst, PROP_MEMORYORDER, it.memoryOrder());
            addProp(inst, PROP_SIGNALOPERATION, it.signalOperation());
        }
        break;

        case BRIG_INST_SOURCE_TYPE:
        {
            InstSourceType it = inst;
        
            addProp(inst, PROP_OPCODE, it.opcode());
            addProp(inst, PROP_TYPE, it.type());
            addProp(inst, PROP_SOURCETYPE, it.sourceType());
        }
        break;

        default:
            assert(false);
            break;
    }
}

