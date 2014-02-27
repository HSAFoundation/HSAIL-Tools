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

enum 
{
    BRIG_PROP_MIN_ID = 0,

    // Brig instruction properties

    PROP_ALIGN,               // type = BrigAlignment8_t,               acc = align()
    PROP_ATOMICOPERATION,     // type = BrigAtomicOperation8_t,         acc = atomicOperation()
    PROP_COMPARE,             // type = BrigCompareOperation8_t,        acc = compare()
    PROP_COORDTYPE,           // type = BrigType16_t,                   acc = coordType()
    PROP_EQUIVCLASS,          // type = uint8_t,                        acc = equivClass()
    PROP_FTZ,                 // type = bool,                           acc = modifier().ftz()
    PROP_GEOMETRY,            // type = BrigImageGeometry8_t,           acc = geometry()
    PROP_IMAGETYPE,           // type = BrigType16_t,                   acc = imageType()
    PROP_ISCONST,             // type = bool,                           acc = modifier().isConst()
    PROP_ISNONULL,            // type = bool,                           acc = modifier().isNoNull()
    PROP_MEMORYORDER,         // type = BrigMemoryOrder8_t,             acc = memoryOrder()
    PROP_MEMORYSCOPE,         // type = BrigMemoryScope8_t,             acc = memoryScope()
    PROP_OPCODE,              // type = BrigOpcode16_t,                 acc = opcode()
    PROP_PACK,                // type = BrigPack8_t,                    acc = pack()
    PROP_ROUND,               // type = BrigRound8_t,                   acc = modifier().round()
    PROP_SEGMENT,             // type = BrigSegment8_t,                 acc = segment()
    PROP_SEGMENTS,            // type = BrigMemoryFenceSegments8_t,     acc = segments()
    PROP_SIGNALOPERATION,     // type = BrigSignalOperation8_t,         acc = signalOperation()
    PROP_SIGNALTYPE,          // type = BrigType16_t,                   acc = signalType()
    PROP_SOURCETYPE,          // type = BrigType16_t,                   acc = sourceType()
    PROP_TYPE,                // type = BrigType16_t,                   acc = type()
    PROP_WIDTH,               // type = BrigWidth8_t,                   acc = width()

    EXT_PROP_MIN_ID
};

//enum BrigInstAddrProps // BRIG_INST_ADDR
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SEGMENT,
//};


//enum BrigInstAtomicProps // BRIG_INST_ATOMIC
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SEGMENT,
//    PROP_MEMORYORDER,
//    PROP_MEMORYSCOPE,
//    PROP_ATOMICOPERATION,
//    PROP_EQUIVCLASS,
//};


//enum BrigInstAtomicImageProps // BRIG_INST_ATOMIC_IMAGE
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_IMAGETYPE,
//    PROP_COORDTYPE,
//    PROP_GEOMETRY,
//    PROP_ATOMICOPERATION,
//    PROP_EQUIVCLASS,
//};


//enum BrigInstBasicProps // BRIG_INST_BASIC
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//};


//enum BrigInstBrProps // BRIG_INST_BR
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_WIDTH,
//};


//enum BrigInstCmpProps // BRIG_INST_CMP
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SOURCETYPE,
//    PROP_ROUND,
//    PROP_FTZ,
//    PROP_COMPARE,
//    PROP_PACK,
//};


//enum BrigInstCvtProps // BRIG_INST_CVT
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SOURCETYPE,
//    PROP_ROUND,
//    PROP_FTZ,
//};


//enum BrigInstImageProps // BRIG_INST_IMAGE
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_IMAGETYPE,
//    PROP_COORDTYPE,
//    PROP_GEOMETRY,
//    PROP_EQUIVCLASS,
//};


//enum BrigInstLaneProps // BRIG_INST_LANE
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SOURCETYPE,
//    PROP_WIDTH,
//};


//enum BrigInstMemProps // BRIG_INST_MEM
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SEGMENT,
//    PROP_ALIGN,
//    PROP_EQUIVCLASS,
//    PROP_WIDTH,
//    PROP_ISCONST,
//};


//enum BrigInstMemFenceProps // BRIG_INST_MEM_FENCE
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SEGMENTS,
//    PROP_MEMORYORDER,
//    PROP_MEMORYSCOPE,
//};


//enum BrigInstModProps // BRIG_INST_MOD
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_ROUND,
//    PROP_FTZ,
//    PROP_PACK,
//};


//enum BrigInstQueueProps // BRIG_INST_QUEUE
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SEGMENT,
//    PROP_MEMORYORDER,
//};


//enum BrigInstSegProps // BRIG_INST_SEG
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SEGMENT,
//};


//enum BrigInstSegCvtProps // BRIG_INST_SEG_CVT
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SOURCETYPE,
//    PROP_SEGMENT,
//    PROP_ISNONULL,
//};


//enum BrigInstSignalProps // BRIG_INST_SIGNAL
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SIGNALTYPE,
//    PROP_MEMORYORDER,
//    PROP_SIGNALOPERATION,
//};


//enum BrigInstSourceTypeProps // BRIG_INST_SOURCE_TYPE
//{
//    PROP_OPCODE,
//    PROP_TYPE,
//    PROP_SOURCETYPE,
//};

