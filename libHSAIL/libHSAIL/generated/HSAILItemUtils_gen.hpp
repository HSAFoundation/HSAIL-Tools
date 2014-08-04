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
inline bool instSupportsFtz(Brig::BrigOpcode16_t arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ABS                : return true;
    case BRIG_OPCODE_ADD                : return true;
    case BRIG_OPCODE_CEIL               : return true;
    case BRIG_OPCODE_CMP                : return true;
    case BRIG_OPCODE_COPYSIGN           : return true;
    case BRIG_OPCODE_CVT                : return true;
    case BRIG_OPCODE_DIV                : return true;
    case BRIG_OPCODE_FLOOR              : return true;
    case BRIG_OPCODE_FMA                : return true;
    case BRIG_OPCODE_FRACT              : return true;
    case BRIG_OPCODE_MAX                : return true;
    case BRIG_OPCODE_MIN                : return true;
    case BRIG_OPCODE_MUL                : return true;
    case BRIG_OPCODE_MULHI              : return true;
    case BRIG_OPCODE_NEG                : return true;
    case BRIG_OPCODE_RINT               : return true;
    case BRIG_OPCODE_SQRT               : return true;
    case BRIG_OPCODE_SUB                : return true;
    case BRIG_OPCODE_TRUNC              : return true;
    default : return false;
    }
}

template <typename RetType, typename Visitor> RetType visitOpcode_gen(HSAIL_ASM::Inst inst, Visitor& vis) {
  using namespace Brig;
  switch( inst.opcode() ) {
    case BRIG_OPCODE_ABS                : return vis.visitOpcode_ABS                            (inst);
    case BRIG_OPCODE_ACTIVELANECOUNT    : return vis.visitOpcode_ACTIVELANECOUNT                (HSAIL_ASM::InstLane(inst));
    case BRIG_OPCODE_ACTIVELANEID       : return vis.visitOpcode_ACTIVELANEID                   (HSAIL_ASM::InstLane(inst));
    case BRIG_OPCODE_ACTIVELANEMASK     : return vis.visitOpcode_ACTIVELANEMASK                 (HSAIL_ASM::InstLane(inst));
    case BRIG_OPCODE_ACTIVELANESHUFFLE  : return vis.visitOpcode_ACTIVELANESHUFFLE              (HSAIL_ASM::InstLane(inst));
    case BRIG_OPCODE_ADD                : return vis.visitOpcode_ADD                            (inst);
    case BRIG_OPCODE_ADDQUEUEWRITEINDEX : return vis.visitOpcode_ADDQUEUEWRITEINDEX             (HSAIL_ASM::InstQueue(inst));
    case BRIG_OPCODE_AGENTCOUNT         : return vis.visitOpcode_AGENTCOUNT                     (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_AGENTID            : return vis.visitOpcode_AGENTID                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_ALLOCA             : return vis.visitOpcode_ALLOCA                         (HSAIL_ASM::InstMem(inst));
    case BRIG_OPCODE_AND                : return vis.visitOpcode_AND                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_ARRIVEFBAR         : return vis.visitOpcode_ARRIVEFBAR                     (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_ATOMIC             : return vis.visitOpcode_ATOMIC                         (HSAIL_ASM::InstAtomic(inst));
    case BRIG_OPCODE_ATOMICNORET        : return vis.visitOpcode_ATOMICNORET                    (HSAIL_ASM::InstAtomic(inst));
    case BRIG_OPCODE_BARRIER            : return vis.visitOpcode_BARRIER                        (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_BITALIGN           : return vis.visitOpcode_BITALIGN                       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITEXTRACT         : return vis.visitOpcode_BITEXTRACT                     (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITINSERT          : return vis.visitOpcode_BITINSERT                      (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITMASK            : return vis.visitOpcode_BITMASK                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITREV             : return vis.visitOpcode_BITREV                         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITSELECT          : return vis.visitOpcode_BITSELECT                      (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BORROW             : return vis.visitOpcode_BORROW                         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BR                 : return vis.visitOpcode_BR                             (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_BYTEALIGN          : return vis.visitOpcode_BYTEALIGN                      (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CALL               : return vis.visitOpcode_CALL                           (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_CARRY              : return vis.visitOpcode_CARRY                          (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CASQUEUEWRITEINDEX : return vis.visitOpcode_CASQUEUEWRITEINDEX             (HSAIL_ASM::InstQueue(inst));
    case BRIG_OPCODE_CBR                : return vis.visitOpcode_CBR                            (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_CEIL               : return vis.visitOpcode_CEIL                           (inst);
    case BRIG_OPCODE_CLASS              : return vis.visitOpcode_CLASS                          (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_CLEARDETECTEXCEPT  : return vis.visitOpcode_CLEARDETECTEXCEPT              (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CLOCK              : return vis.visitOpcode_CLOCK                          (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CMOV               : return vis.visitOpcode_CMOV                           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CMP                : return vis.visitOpcode_CMP                            (HSAIL_ASM::InstCmp(inst));
    case BRIG_OPCODE_COMBINE            : return vis.visitOpcode_COMBINE                        (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_COPYSIGN           : return vis.visitOpcode_COPYSIGN                       (inst);
    case BRIG_OPCODE_CUID               : return vis.visitOpcode_CUID                           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CURRENTWORKGROUPSIZE : return vis.visitOpcode_CURRENTWORKGROUPSIZE           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CVT                : return vis.visitOpcode_CVT                            (HSAIL_ASM::InstCvt(inst));
    case BRIG_OPCODE_DEBUGTRAP          : return vis.visitOpcode_DEBUGTRAP                      (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_DIM                : return vis.visitOpcode_DIM                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_DIV                : return vis.visitOpcode_DIV                            (inst);
    case BRIG_OPCODE_EXPAND             : return vis.visitOpcode_EXPAND                         (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_FIRSTBIT           : return vis.visitOpcode_FIRSTBIT                       (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_FLOOR              : return vis.visitOpcode_FLOOR                          (inst);
    case BRIG_OPCODE_FMA                : return vis.visitOpcode_FMA                            (inst);
    case BRIG_OPCODE_FRACT              : return vis.visitOpcode_FRACT                          (inst);
    case BRIG_OPCODE_FTOS               : return vis.visitOpcode_FTOS                           (HSAIL_ASM::InstSegCvt(inst));
    case BRIG_OPCODE_GCNAPPEND          : return vis.visitOpcode_GCNAPPEND                      (HSAIL_ASM::InstAddr(inst));
    case BRIG_OPCODE_GCNATOMIC          : return vis.visitOpcode_GCNATOMIC                      (HSAIL_ASM::InstAtomic(inst));
    case BRIG_OPCODE_GCNATOMICNORET     : return vis.visitOpcode_GCNATOMICNORET                 (HSAIL_ASM::InstAtomic(inst));
    case BRIG_OPCODE_GCNB32XCHG         : return vis.visitOpcode_GCNB32XCHG                     (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNB4XCHG          : return vis.visitOpcode_GCNB4XCHG                      (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNBFM             : return vis.visitOpcode_GCNBFM                         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNCONSUME         : return vis.visitOpcode_GCNCONSUME                     (HSAIL_ASM::InstAddr(inst));
    case BRIG_OPCODE_GCNFLDEXP          : return vis.visitOpcode_GCNFLDEXP                      (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNFREXP_EXP       : return vis.visitOpcode_GCNFREXP_EXP                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNFREXP_MANT      : return vis.visitOpcode_GCNFREXP_MANT                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNLD              : return vis.visitOpcode_GCNLD                          (HSAIL_ASM::InstMem(inst));
    case BRIG_OPCODE_GCNMADS            : return vis.visitOpcode_GCNMADS                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNMADU            : return vis.visitOpcode_GCNMADU                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNMAX             : return vis.visitOpcode_GCNMAX                         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNMAX3            : return vis.visitOpcode_GCNMAX3                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNMED3            : return vis.visitOpcode_GCNMED3                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNMIN             : return vis.visitOpcode_GCNMIN                         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNMIN3            : return vis.visitOpcode_GCNMIN3                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNMQSAD           : return vis.visitOpcode_GCNMQSAD                       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNMQSAD4          : return vis.visitOpcode_GCNMQSAD4                      (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNMSAD            : return vis.visitOpcode_GCNMSAD                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNPRIORITY        : return vis.visitOpcode_GCNPRIORITY                    (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNQSAD            : return vis.visitOpcode_GCNQSAD                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNREGIONALLOC     : return vis.visitOpcode_GCNREGIONALLOC                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNSADD            : return vis.visitOpcode_GCNSADD                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNSADW            : return vis.visitOpcode_GCNSADW                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNSLEEP           : return vis.visitOpcode_GCNSLEEP                       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GCNST              : return vis.visitOpcode_GCNST                          (HSAIL_ASM::InstMem(inst));
    case BRIG_OPCODE_GCNTRIG_PREOP      : return vis.visitOpcode_GCNTRIG_PREOP                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GETDETECTEXCEPT    : return vis.visitOpcode_GETDETECTEXCEPT                (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GRIDGROUPS         : return vis.visitOpcode_GRIDGROUPS                     (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GRIDSIZE           : return vis.visitOpcode_GRIDSIZE                       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GROUPBASEPTR       : return vis.visitOpcode_GROUPBASEPTR                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_ICALL              : return vis.visitOpcode_ICALL                          (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_INITFBAR           : return vis.visitOpcode_INITFBAR                       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_JOINFBAR           : return vis.visitOpcode_JOINFBAR                       (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_KERNARGBASEPTR     : return vis.visitOpcode_KERNARGBASEPTR                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_LANEID             : return vis.visitOpcode_LANEID                         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_LASTBIT            : return vis.visitOpcode_LASTBIT                        (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_LD                 : return vis.visitOpcode_LD                             (HSAIL_ASM::InstMem(inst));
    case BRIG_OPCODE_LDA                : return vis.visitOpcode_LDA                            (HSAIL_ASM::InstAddr(inst));
    case BRIG_OPCODE_LDF                : return vis.visitOpcode_LDF                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_LDI                : return vis.visitOpcode_LDI                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_LDIMAGE            : return vis.visitOpcode_LDIMAGE                        (HSAIL_ASM::InstImage(inst));
    case BRIG_OPCODE_LDK                : return vis.visitOpcode_LDK                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_LDQUEUEREADINDEX   : return vis.visitOpcode_LDQUEUEREADINDEX               (HSAIL_ASM::InstQueue(inst));
    case BRIG_OPCODE_LDQUEUEWRITEINDEX  : return vis.visitOpcode_LDQUEUEWRITEINDEX              (HSAIL_ASM::InstQueue(inst));
    case BRIG_OPCODE_LEAVEFBAR          : return vis.visitOpcode_LEAVEFBAR                      (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_LERP               : return vis.visitOpcode_LERP                           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAD                : return vis.visitOpcode_MAD                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAD24              : return vis.visitOpcode_MAD24                          (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAD24HI            : return vis.visitOpcode_MAD24HI                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAX                : return vis.visitOpcode_MAX                            (inst);
    case BRIG_OPCODE_MAXCUID            : return vis.visitOpcode_MAXCUID                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAXWAVEID          : return vis.visitOpcode_MAXWAVEID                      (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MEMFENCE           : return vis.visitOpcode_MEMFENCE                       (HSAIL_ASM::InstMemFence(inst));
    case BRIG_OPCODE_MIN                : return vis.visitOpcode_MIN                            (inst);
    case BRIG_OPCODE_MOV                : return vis.visitOpcode_MOV                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MUL                : return vis.visitOpcode_MUL                            (inst);
    case BRIG_OPCODE_MUL24              : return vis.visitOpcode_MUL24                          (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MUL24HI            : return vis.visitOpcode_MUL24HI                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MULHI              : return vis.visitOpcode_MULHI                          (inst);
    case BRIG_OPCODE_NCOS               : return vis.visitOpcode_NCOS                           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NEG                : return vis.visitOpcode_NEG                            (inst);
    case BRIG_OPCODE_NEXP2              : return vis.visitOpcode_NEXP2                          (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NFMA               : return vis.visitOpcode_NFMA                           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NLOG2              : return vis.visitOpcode_NLOG2                          (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NOP                : return vis.visitOpcode_NOP                            (inst);
    case BRIG_OPCODE_NOT                : return vis.visitOpcode_NOT                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NRCP               : return vis.visitOpcode_NRCP                           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NRSQRT             : return vis.visitOpcode_NRSQRT                         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NSIN               : return vis.visitOpcode_NSIN                           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NSQRT              : return vis.visitOpcode_NSQRT                          (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NULLPTR            : return vis.visitOpcode_NULLPTR                        (HSAIL_ASM::InstSeg(inst));
    case BRIG_OPCODE_OR                 : return vis.visitOpcode_OR                             (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_PACK               : return vis.visitOpcode_PACK                           (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_PACKCVT            : return vis.visitOpcode_PACKCVT                        (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_PACKETCOMPLETIONSIG : return vis.visitOpcode_PACKETCOMPLETIONSIG            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_PACKETID           : return vis.visitOpcode_PACKETID                       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_POPCOUNT           : return vis.visitOpcode_POPCOUNT                       (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_QUERYIMAGE         : return vis.visitOpcode_QUERYIMAGE                     (HSAIL_ASM::InstQueryImage(inst));
    case BRIG_OPCODE_QUERYSAMPLER       : return vis.visitOpcode_QUERYSAMPLER                   (HSAIL_ASM::InstQuerySampler(inst));
    case BRIG_OPCODE_QUEUEID            : return vis.visitOpcode_QUEUEID                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_QUEUEPTR           : return vis.visitOpcode_QUEUEPTR                       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_RDIMAGE            : return vis.visitOpcode_RDIMAGE                        (HSAIL_ASM::InstImage(inst));
    case BRIG_OPCODE_RELEASEFBAR        : return vis.visitOpcode_RELEASEFBAR                    (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_REM                : return vis.visitOpcode_REM                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_RET                : return vis.visitOpcode_RET                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_RINT               : return vis.visitOpcode_RINT                           (inst);
    case BRIG_OPCODE_SAD                : return vis.visitOpcode_SAD                            (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_SADHI              : return vis.visitOpcode_SADHI                          (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_SBR                : return vis.visitOpcode_SBR                            (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_SCALL              : return vis.visitOpcode_SCALL                          (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_SEGMENTP           : return vis.visitOpcode_SEGMENTP                       (HSAIL_ASM::InstSegCvt(inst));
    case BRIG_OPCODE_SETDETECTEXCEPT    : return vis.visitOpcode_SETDETECTEXCEPT                (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_SHL                : return vis.visitOpcode_SHL                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_SHR                : return vis.visitOpcode_SHR                            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_SHUFFLE            : return vis.visitOpcode_SHUFFLE                        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_SIGNAL             : return vis.visitOpcode_SIGNAL                         (HSAIL_ASM::InstSignal(inst));
    case BRIG_OPCODE_SIGNALNORET        : return vis.visitOpcode_SIGNALNORET                    (HSAIL_ASM::InstSignal(inst));
    case BRIG_OPCODE_SQRT               : return vis.visitOpcode_SQRT                           (inst);
    case BRIG_OPCODE_ST                 : return vis.visitOpcode_ST                             (HSAIL_ASM::InstMem(inst));
    case BRIG_OPCODE_STIMAGE            : return vis.visitOpcode_STIMAGE                        (HSAIL_ASM::InstImage(inst));
    case BRIG_OPCODE_STOF               : return vis.visitOpcode_STOF                           (HSAIL_ASM::InstSegCvt(inst));
    case BRIG_OPCODE_STQUEUEREADINDEX   : return vis.visitOpcode_STQUEUEREADINDEX               (HSAIL_ASM::InstQueue(inst));
    case BRIG_OPCODE_STQUEUEWRITEINDEX  : return vis.visitOpcode_STQUEUEWRITEINDEX              (HSAIL_ASM::InstQueue(inst));
    case BRIG_OPCODE_SUB                : return vis.visitOpcode_SUB                            (inst);
    case BRIG_OPCODE_TRUNC              : return vis.visitOpcode_TRUNC                          (inst);
    case BRIG_OPCODE_UNPACK             : return vis.visitOpcode_UNPACK                         (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_UNPACKCVT          : return vis.visitOpcode_UNPACKCVT                      (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_UNPACKHI           : return vis.visitOpcode_UNPACKHI                       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_UNPACKLO           : return vis.visitOpcode_UNPACKLO                       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WAITFBAR           : return vis.visitOpcode_WAITFBAR                       (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_WAVEBARRIER        : return vis.visitOpcode_WAVEBARRIER                    (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_WAVEID             : return vis.visitOpcode_WAVEID                         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKGROUPID        : return vis.visitOpcode_WORKGROUPID                    (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKGROUPSIZE      : return vis.visitOpcode_WORKGROUPSIZE                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKITEMABSID      : return vis.visitOpcode_WORKITEMABSID                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKITEMFLATABSID  : return vis.visitOpcode_WORKITEMFLATABSID              (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKITEMFLATID     : return vis.visitOpcode_WORKITEMFLATID                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKITEMID         : return vis.visitOpcode_WORKITEMID                     (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_XOR                : return vis.visitOpcode_XOR                            (HSAIL_ASM::InstBasic(inst));
    default : return RetType();
    }
}

