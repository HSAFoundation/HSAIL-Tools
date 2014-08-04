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

void setBrigProp(Inst inst, unsigned propId, unsigned val, bool ignoreErrors)
{
    using namespace Brig;
    using namespace HSAIL_PROPS;

    switch(inst.kind())
    {
        case BRIG_KIND_INST_ADDR:
        {
            InstAddr it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SEGMENT: it.segment() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_ATOMIC:
        {
            InstAtomic it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SEGMENT: it.segment() = val; break;
            case PROP_MEMORYORDER: it.memoryOrder() = val; break;
            case PROP_MEMORYSCOPE: it.memoryScope() = val; break;
            case PROP_ATOMICOPERATION: it.atomicOperation() = val; break;
            case PROP_EQUIVCLASS: it.equivClass() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_BASIC:
        {
            InstBasic it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_BR:
        {
            InstBr it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_WIDTH: it.width() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_CMP:
        {
            InstCmp it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SOURCETYPE: it.sourceType() = val; break;
            case PROP_ROUND: it.modifier().round() = val; break;
            case PROP_FTZ: it.modifier().ftz() = (val != 0); break;
            case PROP_COMPARE: it.compare() = val; break;
            case PROP_PACK: it.pack() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_CVT:
        {
            InstCvt it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SOURCETYPE: it.sourceType() = val; break;
            case PROP_ROUND: it.modifier().round() = val; break;
            case PROP_FTZ: it.modifier().ftz() = (val != 0); break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_IMAGE:
        {
            InstImage it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_IMAGETYPE: it.imageType() = val; break;
            case PROP_COORDTYPE: it.coordType() = val; break;
            case PROP_GEOMETRY: it.geometry() = val; break;
            case PROP_EQUIVCLASS: it.equivClass() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_LANE:
        {
            InstLane it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SOURCETYPE: it.sourceType() = val; break;
            case PROP_WIDTH: it.width() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_MEM:
        {
            InstMem it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SEGMENT: it.segment() = val; break;
            case PROP_ALIGN: it.align() = val; break;
            case PROP_EQUIVCLASS: it.equivClass() = val; break;
            case PROP_WIDTH: it.width() = val; break;
            case PROP_ISCONST: it.modifier().isConst() = (val != 0); break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_MEM_FENCE:
        {
            InstMemFence it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_MEMORYORDER: it.memoryOrder() = val; break;
            case PROP_GLOBALSEGMENTMEMORYSCOPE: it.globalSegmentMemoryScope() = val; break;
            case PROP_GROUPSEGMENTMEMORYSCOPE: it.groupSegmentMemoryScope() = val; break;
            case PROP_IMAGESEGMENTMEMORYSCOPE: it.imageSegmentMemoryScope() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_MOD:
        {
            InstMod it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_ROUND: it.modifier().round() = val; break;
            case PROP_FTZ: it.modifier().ftz() = (val != 0); break;
            case PROP_PACK: it.pack() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_QUERY_IMAGE:
        {
            InstQueryImage it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_IMAGETYPE: it.imageType() = val; break;
            case PROP_GEOMETRY: it.geometry() = val; break;
            case PROP_IMAGEQUERY: it.imageQuery() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_QUERY_SAMPLER:
        {
            InstQuerySampler it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SAMPLERQUERY: it.samplerQuery() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_QUEUE:
        {
            InstQueue it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SEGMENT: it.segment() = val; break;
            case PROP_MEMORYORDER: it.memoryOrder() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_SEG:
        {
            InstSeg it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SEGMENT: it.segment() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_SEG_CVT:
        {
            InstSegCvt it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SOURCETYPE: it.sourceType() = val; break;
            case PROP_SEGMENT: it.segment() = val; break;
            case PROP_ISNONULL: it.modifier().isNoNull() = (val != 0); break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_SIGNAL:
        {
            InstSignal it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SIGNALTYPE: it.signalType() = val; break;
            case PROP_MEMORYORDER: it.memoryOrder() = val; break;
            case PROP_SIGNALOPERATION: it.signalOperation() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_SOURCE_TYPE:
        {
            InstSourceType it = inst;

            switch(propId)
            {
            case PROP_OPCODE: it.opcode() = val; break;
            case PROP_TYPE: it.type() = val; break;
            case PROP_SOURCETYPE: it.sourceType() = val; break;
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        default:
            assert(false); // Invalid format
            break;
    }
}

unsigned getBrigProp(Inst inst, unsigned propId, bool ignoreErrors, unsigned defaultVal)
{
    using namespace Brig;
    using namespace HSAIL_PROPS;

    switch(inst.kind())
    {
        case BRIG_KIND_INST_ADDR:
        {
            InstAddr it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SEGMENT: return it.segment();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_ATOMIC:
        {
            InstAtomic it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SEGMENT: return it.segment();
            case PROP_MEMORYORDER: return it.memoryOrder();
            case PROP_MEMORYSCOPE: return it.memoryScope();
            case PROP_ATOMICOPERATION: return it.atomicOperation();
            case PROP_EQUIVCLASS: return it.equivClass();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_BASIC:
        {
            InstBasic it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_BR:
        {
            InstBr it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_WIDTH: return it.width();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_CMP:
        {
            InstCmp it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SOURCETYPE: return it.sourceType();
            case PROP_ROUND: return it.modifier().round();
            case PROP_FTZ: return it.modifier().ftz();
            case PROP_COMPARE: return it.compare();
            case PROP_PACK: return it.pack();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_CVT:
        {
            InstCvt it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SOURCETYPE: return it.sourceType();
            case PROP_ROUND: return it.modifier().round();
            case PROP_FTZ: return it.modifier().ftz();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_IMAGE:
        {
            InstImage it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_IMAGETYPE: return it.imageType();
            case PROP_COORDTYPE: return it.coordType();
            case PROP_GEOMETRY: return it.geometry();
            case PROP_EQUIVCLASS: return it.equivClass();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_LANE:
        {
            InstLane it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SOURCETYPE: return it.sourceType();
            case PROP_WIDTH: return it.width();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_MEM:
        {
            InstMem it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SEGMENT: return it.segment();
            case PROP_ALIGN: return it.align();
            case PROP_EQUIVCLASS: return it.equivClass();
            case PROP_WIDTH: return it.width();
            case PROP_ISCONST: return it.modifier().isConst();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_MEM_FENCE:
        {
            InstMemFence it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_MEMORYORDER: return it.memoryOrder();
            case PROP_GLOBALSEGMENTMEMORYSCOPE: return it.globalSegmentMemoryScope();
            case PROP_GROUPSEGMENTMEMORYSCOPE: return it.groupSegmentMemoryScope();
            case PROP_IMAGESEGMENTMEMORYSCOPE: return it.imageSegmentMemoryScope();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_MOD:
        {
            InstMod it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_ROUND: return it.modifier().round();
            case PROP_FTZ: return it.modifier().ftz();
            case PROP_PACK: return it.pack();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_QUERY_IMAGE:
        {
            InstQueryImage it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_IMAGETYPE: return it.imageType();
            case PROP_GEOMETRY: return it.geometry();
            case PROP_IMAGEQUERY: return it.imageQuery();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_QUERY_SAMPLER:
        {
            InstQuerySampler it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SAMPLERQUERY: return it.samplerQuery();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_QUEUE:
        {
            InstQueue it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SEGMENT: return it.segment();
            case PROP_MEMORYORDER: return it.memoryOrder();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_SEG:
        {
            InstSeg it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SEGMENT: return it.segment();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_SEG_CVT:
        {
            InstSegCvt it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SOURCETYPE: return it.sourceType();
            case PROP_SEGMENT: return it.segment();
            case PROP_ISNONULL: return it.modifier().isNoNull();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_SIGNAL:
        {
            InstSignal it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SIGNALTYPE: return it.signalType();
            case PROP_MEMORYORDER: return it.memoryOrder();
            case PROP_SIGNALOPERATION: return it.signalOperation();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        case BRIG_KIND_INST_SOURCE_TYPE:
        {
            InstSourceType it = inst;

            switch(propId)
            {
            case PROP_OPCODE: return it.opcode();
            case PROP_TYPE: return it.type();
            case PROP_SOURCETYPE: return it.sourceType();
            default:
                assert(ignoreErrors);
                break;
            }
        }
        break;

        default:
            assert(false); // Invalid format
            break;
    }
    assert(ignoreErrors);
    return defaultVal;
}
