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

void visitBrigProps(Inst inst)
{
    using namespace Brig;
    using namespace HSAIL_PROPS;

    switch(inst.kind())
    {
        case BRIG_KIND_INST_ADDR:
        {
            InstAddr it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SEGMENT, it.segment());
        }
        break;

        case BRIG_KIND_INST_ATOMIC:
        {
            InstAtomic it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SEGMENT, it.segment());
            visitProp(inst, PROP_MEMORYORDER, it.memoryOrder());
            visitProp(inst, PROP_MEMORYSCOPE, it.memoryScope());
            visitProp(inst, PROP_ATOMICOPERATION, it.atomicOperation());
            visitProp(inst, PROP_EQUIVCLASS, it.equivClass());
        }
        break;

        case BRIG_KIND_INST_BASIC:
        {
            InstBasic it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
        }
        break;

        case BRIG_KIND_INST_BR:
        {
            InstBr it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_WIDTH, it.width());
        }
        break;

        case BRIG_KIND_INST_CMP:
        {
            InstCmp it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SOURCETYPE, it.sourceType());
            visitProp(inst, PROP_ROUND, it.modifier().round());
            visitProp(inst, PROP_FTZ, it.modifier().ftz());
            visitProp(inst, PROP_COMPARE, it.compare());
            visitProp(inst, PROP_PACK, it.pack());
        }
        break;

        case BRIG_KIND_INST_CVT:
        {
            InstCvt it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SOURCETYPE, it.sourceType());
            visitProp(inst, PROP_ROUND, it.modifier().round());
            visitProp(inst, PROP_FTZ, it.modifier().ftz());
        }
        break;

        case BRIG_KIND_INST_IMAGE:
        {
            InstImage it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_IMAGETYPE, it.imageType());
            visitProp(inst, PROP_COORDTYPE, it.coordType());
            visitProp(inst, PROP_GEOMETRY, it.geometry());
            visitProp(inst, PROP_EQUIVCLASS, it.equivClass());
        }
        break;

        case BRIG_KIND_INST_LANE:
        {
            InstLane it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SOURCETYPE, it.sourceType());
            visitProp(inst, PROP_WIDTH, it.width());
        }
        break;

        case BRIG_KIND_INST_MEM:
        {
            InstMem it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SEGMENT, it.segment());
            visitProp(inst, PROP_ALIGN, it.align());
            visitProp(inst, PROP_EQUIVCLASS, it.equivClass());
            visitProp(inst, PROP_WIDTH, it.width());
            visitProp(inst, PROP_ISCONST, it.modifier().isConst());
        }
        break;

        case BRIG_KIND_INST_MEM_FENCE:
        {
            InstMemFence it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_MEMORYORDER, it.memoryOrder());
            visitProp(inst, PROP_GLOBALSEGMENTMEMORYSCOPE, it.globalSegmentMemoryScope());
            visitProp(inst, PROP_GROUPSEGMENTMEMORYSCOPE, it.groupSegmentMemoryScope());
            visitProp(inst, PROP_IMAGESEGMENTMEMORYSCOPE, it.imageSegmentMemoryScope());
        }
        break;

        case BRIG_KIND_INST_MOD:
        {
            InstMod it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_ROUND, it.modifier().round());
            visitProp(inst, PROP_FTZ, it.modifier().ftz());
            visitProp(inst, PROP_PACK, it.pack());
        }
        break;

        case BRIG_KIND_INST_QUERY_IMAGE:
        {
            InstQueryImage it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_IMAGETYPE, it.imageType());
            visitProp(inst, PROP_GEOMETRY, it.geometry());
            visitProp(inst, PROP_IMAGEQUERY, it.imageQuery());
        }
        break;

        case BRIG_KIND_INST_QUERY_SAMPLER:
        {
            InstQuerySampler it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SAMPLERQUERY, it.samplerQuery());
        }
        break;

        case BRIG_KIND_INST_QUEUE:
        {
            InstQueue it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SEGMENT, it.segment());
            visitProp(inst, PROP_MEMORYORDER, it.memoryOrder());
        }
        break;

        case BRIG_KIND_INST_SEG:
        {
            InstSeg it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SEGMENT, it.segment());
        }
        break;

        case BRIG_KIND_INST_SEG_CVT:
        {
            InstSegCvt it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SOURCETYPE, it.sourceType());
            visitProp(inst, PROP_SEGMENT, it.segment());
            visitProp(inst, PROP_ISNONULL, it.modifier().isNoNull());
        }
        break;

        case BRIG_KIND_INST_SIGNAL:
        {
            InstSignal it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SIGNALTYPE, it.signalType());
            visitProp(inst, PROP_MEMORYORDER, it.memoryOrder());
            visitProp(inst, PROP_SIGNALOPERATION, it.signalOperation());
        }
        break;

        case BRIG_KIND_INST_SOURCE_TYPE:
        {
            InstSourceType it = inst;

            visitProp(inst, PROP_OPCODE, it.opcode());
            visitProp(inst, PROP_TYPE, it.type());
            visitProp(inst, PROP_SOURCETYPE, it.sourceType());
        }
        break;

        default:
            assert(false); // Invalid format
            break;
    }
}

