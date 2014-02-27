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
## tn: BrigType16_t sourceType
[0] BrigType16_t BrigInstCmp::sourceType
[0] BrigType16_t BrigInstCvt::sourceType
[0] BrigType16_t BrigInstLane::sourceType
[0] BrigType16_t BrigInstSegCvt::sourceType
[0] BrigType16_t BrigInstSourceType::sourceType
## tn: BrigSymbolModifier8_t allBits
## tn: BrigCodeOffset32_t code
## tn: BrigDataOffset32_t dataAs
## tn: bool ftz
## tn: BrigSamplerModifier8_t allBits
## tn: BrigSamplerFilter filter
## tn: BrigType16_t imageType
[0] BrigType16_t BrigInstAtomicImage::imageType
[0] BrigType16_t BrigInstImage::imageType
## tn: BrigDirectiveOffset32_t elements
## tn: BrigDirectiveOffset32_t targets
## tn: BrigSymbolModifier modifier
## tn: BrigControlDirective16_t control
## tn: BrigSegCvtModifier modifier
[0] BrigSegCvtModifier BrigInstSegCvt::modifier
## tn: BrigType16_t coordType
[0] BrigType16_t BrigInstAtomicImage::coordType
[0] BrigType16_t BrigInstImage::coordType
## tn: uint32_t line
## tn: uint16_t inArgCount
## tn: BrigType16_t signalType
[0] BrigType16_t BrigInstSignal::signalType
## tn: uint16_t elementCount
## tn: BrigAluModifier16_t allBits
## tn: uint32_t height
## tn: bool isNoNull
## tn: BrigSamplerBoundaryMode8_t boundaryU
## tn: uint16_t outArgCount
## tn: BrigStringOffset32_t name
## tn: BrigDirectiveOffset32_t nextTopLevelDirective
## tn: BrigVersion32_t hsailMajor
## tn: BrigMemoryOrder8_t memoryOrder
[0] BrigMemoryOrder8_t BrigInstAtomic::memoryOrder
[0] BrigMemoryOrder8_t BrigInstMemFence::memoryOrder
[0] BrigMemoryOrder8_t BrigInstQueue::memoryOrder
[0] BrigMemoryOrder8_t BrigInstSignal::memoryOrder
## tn: BrigDirectiveOffset32_t init
## tn: BrigVersion32_t hsailMinor
## tn: BrigDirectiveOffset32_t firstScopedDirective
## tn: BrigLinkage linkage
## tn: BrigDirectiveOffset32_t labels
## tn: BrigStringOffset32_t reg
## tn: uint32_t array
## tn: BrigAtomicOperation8_t atomicOperation
[0] BrigAtomicOperation8_t BrigInstAtomic::atomicOperation
[0] BrigAtomicOperation8_t BrigInstAtomicImage::atomicOperation
## tn: BrigImageFormat8_t format
## tn: bool isConst
## tn: BrigAluModifier modifier
[0] BrigAluModifier BrigInstCmp::modifier
[0] BrigAluModifier BrigInstCvt::modifier
[0] BrigAluModifier BrigInstMod::modifier
## tn: uint8_t bytes
## tn: bool isArray
## tn: uint16_t regCount
## tn: BrigProfile8_t profile
## tn: uint64_t offset
## tn: uint8_t equivClass
[0] uint8_t BrigInstAtomic::equivClass
[0] uint8_t BrigInstAtomicImage::equivClass
[0] uint8_t BrigInstImage::equivClass
[0] uint8_t BrigInstMem::equivClass
## tn: BrigDataOffset32_t data
## tn: BrigMemoryFenceSegments8_t segments
[0] BrigMemoryFenceSegments8_t BrigInstMemFence::segments
## tn: BrigOperandOffset32_t values
## tn: BrigDirectiveOffset32_t symbol
## tn: uint32_t dimLo
## tn: uint32_t depth
## tn: BrigStringOffset32_t filename
## tn: uint16_t valueCount
## tn: BrigDirectiveOffset32_t ref
## tn: uint16_t byteCount
## tn: BrigPack8_t pack
[0] BrigPack8_t BrigInstCmp::pack
[0] BrigPack8_t BrigInstMod::pack
## tn: uint32_t instCount
## tn: BrigVersion32_t brigMinor
## tn: BrigMemoryModifier8_t allBits
## tn: BrigWidth8_t width
[0] BrigWidth8_t BrigInstBr::width
[0] BrigWidth8_t BrigInstLane::width
[0] BrigWidth8_t BrigInstMem::width
## tn: uint64_t dim
## tn: BrigExecutableModifier8_t allBits
## tn: BrigSegCvtModifier8_t allBits
## tn: BrigExecutableModifier modifier
## tn: bool isFlexArray
## tn: BrigMemoryScope8_t memoryScope
[0] BrigMemoryScope8_t BrigInstAtomic::memoryScope
[0] BrigMemoryScope8_t BrigInstMemFence::memoryScope
## tn: uint32_t offsetHi
## tn: BrigDirectiveSignatureArgument args
## tn: bool isDeclaration
## tn: BrigMachineModel8_t machineModel
## tn: BrigRound8_t round
## tn: BrigVersion32_t brigMajor
## tn: uint32_t column
## tn: BrigMemoryModifier modifier
[0] BrigMemoryModifier BrigInstMem::modifier
## tn: BrigDirectiveOffset32_t firstInArg
## tn: BrigDirectiveOffset32_t label
## tn: BrigSamplerBoundaryMode8_t boundaryV
## tn: uint32_t offsetLo
## tn: BrigStringOffset32_t regs
## tn: BrigImageGeometry8_t geometry
[0] BrigImageGeometry8_t BrigInstAtomicImage::geometry
[0] BrigImageGeometry8_t BrigInstImage::geometry
## tn: uint32_t elementCount
## tn: BrigSamplerBoundaryMode8_t boundaryW
## tn: bool isUnnormalized
## tn: BrigStringOffset32_t string
## tn: BrigSegment8_t segment
[0] BrigSegment8_t BrigInstAddr::segment
[0] BrigSegment8_t BrigInstAtomic::segment
[0] BrigSegment8_t BrigInstMem::segment
[0] BrigSegment8_t BrigInstQueue::segment
[0] BrigSegment8_t BrigInstSeg::segment
[0] BrigSegment8_t BrigInstSegCvt::segment
## tn: BrigCompareOperation8_t compare
[0] BrigCompareOperation8_t BrigInstCmp::compare
## tn: uint32_t width
## tn: BrigImageOrder8_t order
## tn: BrigSignalOperation8_t signalOperation
[0] BrigSignalOperation8_t BrigInstSignal::signalOperation
## tn: uint32_t dimHi
## tn: BrigAlignment8_t align
[0] BrigAlignment8_t BrigInstMem::align
## tn: BrigSamplerModifier modifier
## tn: uint16_t labelCount
