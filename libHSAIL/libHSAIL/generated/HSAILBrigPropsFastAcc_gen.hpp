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

template<class T> static unsigned getAlign(T inst) { assert(inst); return inst.align(); }
template<class T> static unsigned getAtomicOperation(T inst) { assert(inst); return inst.atomicOperation(); }
template<class T> static unsigned getCompare(T inst) { assert(inst); return inst.compare(); }
template<class T> static unsigned getCoordType(T inst) { assert(inst); return inst.coordType(); }
template<class T> static unsigned getEquivClass(T inst) { assert(inst); return inst.equivClass(); }
template<class T> static unsigned getFtz(T inst) { assert(inst); return inst.modifier().ftz(); }
template<class T> static unsigned getGeometry(T inst) { assert(inst); return inst.geometry(); }
template<class T> static unsigned getImageType(T inst) { assert(inst); return inst.imageType(); }
template<class T> static unsigned getIsConst(T inst) { assert(inst); return inst.modifier().isConst(); }
template<class T> static unsigned getIsNoNull(T inst) { assert(inst); return inst.modifier().isNoNull(); }
template<class T> static unsigned getMemoryOrder(T inst) { assert(inst); return inst.memoryOrder(); }
template<class T> static unsigned getMemoryScope(T inst) { assert(inst); return inst.memoryScope(); }
template<class T> static unsigned getOpcode(T inst) { assert(inst); return inst.opcode(); }
template<class T> static unsigned getPack(T inst) { assert(inst); return inst.pack(); }
template<class T> static unsigned getRound(T inst) { assert(inst); return inst.modifier().round(); }
template<class T> static unsigned getSegment(T inst) { assert(inst); return inst.segment(); }
template<class T> static unsigned getSegments(T inst) { assert(inst); return inst.segments(); }
template<class T> static unsigned getSignalOperation(T inst) { assert(inst); return inst.signalOperation(); }
template<class T> static unsigned getSignalType(T inst) { assert(inst); return inst.signalType(); }
template<class T> static unsigned getSourceType(T inst) { assert(inst); return inst.sourceType(); }
template<class T> static unsigned getType(T inst) { assert(inst); return inst.type(); }
template<class T> static unsigned getWidth(T inst) { assert(inst); return inst.width(); }
