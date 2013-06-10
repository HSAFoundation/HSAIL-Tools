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
template <typename RetType, typename Visitor> RetType visitOpcode_gen(HSAIL_ASM::Inst inst, Visitor& vis) {
  using namespace Brig;
  switch( inst.opcode() ) {
    case BRIG_OPCODE_ABS                : return vis.template visitOpcode<BRIG_OPCODE_ABS>                   (inst);
    case BRIG_OPCODE_ADD                : return vis.template visitOpcode<BRIG_OPCODE_ADD>                   (inst);
    case BRIG_OPCODE_ALLOCA             : return vis.template visitOpcode<BRIG_OPCODE_ALLOCA>                (HSAIL_ASM::InstSeg(inst));
    case BRIG_OPCODE_AND                : return vis.template visitOpcode<BRIG_OPCODE_AND>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_ARRIVEFBAR         : return vis.template visitOpcode<BRIG_OPCODE_ARRIVEFBAR>            (HSAIL_ASM::InstFbar(inst));
    case BRIG_OPCODE_ATOMIC             : return vis.template visitOpcode<BRIG_OPCODE_ATOMIC>                (HSAIL_ASM::InstAtomic(inst));
    case BRIG_OPCODE_ATOMICIMAGE        : return vis.template visitOpcode<BRIG_OPCODE_ATOMICIMAGE>           (HSAIL_ASM::InstAtomicImage(inst));
    case BRIG_OPCODE_ATOMICIMAGENORET   : return vis.template visitOpcode<BRIG_OPCODE_ATOMICIMAGENORET>      (HSAIL_ASM::InstAtomicImage(inst));
    case BRIG_OPCODE_ATOMICNORET        : return vis.template visitOpcode<BRIG_OPCODE_ATOMICNORET>           (HSAIL_ASM::InstAtomic(inst));
    case BRIG_OPCODE_BARRIER            : return vis.template visitOpcode<BRIG_OPCODE_BARRIER>               (HSAIL_ASM::InstBar(inst));
    case BRIG_OPCODE_BITALIGN           : return vis.template visitOpcode<BRIG_OPCODE_BITALIGN>              (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITEXTRACT         : return vis.template visitOpcode<BRIG_OPCODE_BITEXTRACT>            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITINSERT          : return vis.template visitOpcode<BRIG_OPCODE_BITINSERT>             (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITMASK            : return vis.template visitOpcode<BRIG_OPCODE_BITMASK>               (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITREV             : return vis.template visitOpcode<BRIG_OPCODE_BITREV>                (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BITSELECT          : return vis.template visitOpcode<BRIG_OPCODE_BITSELECT>             (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BORROW             : return vis.template visitOpcode<BRIG_OPCODE_BORROW>                (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_BRN                : return vis.template visitOpcode<BRIG_OPCODE_BRN>                   (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_BYTEALIGN          : return vis.template visitOpcode<BRIG_OPCODE_BYTEALIGN>             (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CALL               : return vis.template visitOpcode<BRIG_OPCODE_CALL>                  (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_CARRY              : return vis.template visitOpcode<BRIG_OPCODE_CARRY>                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CBR                : return vis.template visitOpcode<BRIG_OPCODE_CBR>                   (HSAIL_ASM::InstBr(inst));
    case BRIG_OPCODE_CEIL               : return vis.template visitOpcode<BRIG_OPCODE_CEIL>                  (inst);
    case BRIG_OPCODE_CLASS              : return vis.template visitOpcode<BRIG_OPCODE_CLASS>                 (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_CLEARDETECTEXCEPT  : return vis.template visitOpcode<BRIG_OPCODE_CLEARDETECTEXCEPT>     (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CLOCK              : return vis.template visitOpcode<BRIG_OPCODE_CLOCK>                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CMOV               : return vis.template visitOpcode<BRIG_OPCODE_CMOV>                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CMP                : return vis.template visitOpcode<BRIG_OPCODE_CMP>                   (HSAIL_ASM::InstCmp(inst));
    case BRIG_OPCODE_COMBINE            : return vis.template visitOpcode<BRIG_OPCODE_COMBINE>               (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_COPYSIGN           : return vis.template visitOpcode<BRIG_OPCODE_COPYSIGN>              (inst);
    case BRIG_OPCODE_COUNTLANE          : return vis.template visitOpcode<BRIG_OPCODE_COUNTLANE>             (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_COUNTUPLANE        : return vis.template visitOpcode<BRIG_OPCODE_COUNTUPLANE>           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CUID               : return vis.template visitOpcode<BRIG_OPCODE_CUID>                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CURRENTWORKGROUPSIZE : return vis.template visitOpcode<BRIG_OPCODE_CURRENTWORKGROUPSIZE>  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_CVT                : return vis.template visitOpcode<BRIG_OPCODE_CVT>                   (HSAIL_ASM::InstCvt(inst));
    case BRIG_OPCODE_DEBUGTRAP          : return vis.template visitOpcode<BRIG_OPCODE_DEBUGTRAP>             (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_DIM                : return vis.template visitOpcode<BRIG_OPCODE_DIM>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_DISPATCHID         : return vis.template visitOpcode<BRIG_OPCODE_DISPATCHID>            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_DISPATCHPTR        : return vis.template visitOpcode<BRIG_OPCODE_DISPATCHPTR>           (HSAIL_ASM::InstSeg(inst));
    case BRIG_OPCODE_DIV                : return vis.template visitOpcode<BRIG_OPCODE_DIV>                   (inst);
    case BRIG_OPCODE_EXPAND             : return vis.template visitOpcode<BRIG_OPCODE_EXPAND>                (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_FIRSTBIT           : return vis.template visitOpcode<BRIG_OPCODE_FIRSTBIT>              (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_FLOOR              : return vis.template visitOpcode<BRIG_OPCODE_FLOOR>                 (inst);
    case BRIG_OPCODE_FMA                : return vis.template visitOpcode<BRIG_OPCODE_FMA>                   (inst);
    case BRIG_OPCODE_FRACT              : return vis.template visitOpcode<BRIG_OPCODE_FRACT>                 (inst);
    case BRIG_OPCODE_FTOS               : return vis.template visitOpcode<BRIG_OPCODE_FTOS>                  (HSAIL_ASM::InstSeg(inst));
    case BRIG_OPCODE_GETDETECTEXCEPT    : return vis.template visitOpcode<BRIG_OPCODE_GETDETECTEXCEPT>       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GRIDGROUPS         : return vis.template visitOpcode<BRIG_OPCODE_GRIDGROUPS>            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_GRIDSIZE           : return vis.template visitOpcode<BRIG_OPCODE_GRIDSIZE>              (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_INITFBAR           : return vis.template visitOpcode<BRIG_OPCODE_INITFBAR>              (HSAIL_ASM::InstFbar(inst));
    case BRIG_OPCODE_JOINFBAR           : return vis.template visitOpcode<BRIG_OPCODE_JOINFBAR>              (HSAIL_ASM::InstFbar(inst));
    case BRIG_OPCODE_LANEID             : return vis.template visitOpcode<BRIG_OPCODE_LANEID>                (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_LASTBIT            : return vis.template visitOpcode<BRIG_OPCODE_LASTBIT>               (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_LD                 : return vis.template visitOpcode<BRIG_OPCODE_LD>                    (HSAIL_ASM::InstMem(inst));
    case BRIG_OPCODE_LDA                : return vis.template visitOpcode<BRIG_OPCODE_LDA>                   (HSAIL_ASM::InstAddr(inst));
    case BRIG_OPCODE_LDC                : return vis.template visitOpcode<BRIG_OPCODE_LDC>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_LDF                : return vis.template visitOpcode<BRIG_OPCODE_LDF>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_LDIMAGE            : return vis.template visitOpcode<BRIG_OPCODE_LDIMAGE>               (HSAIL_ASM::InstImage(inst));
    case BRIG_OPCODE_LEAVEFBAR          : return vis.template visitOpcode<BRIG_OPCODE_LEAVEFBAR>             (HSAIL_ASM::InstFbar(inst));
    case BRIG_OPCODE_LERP               : return vis.template visitOpcode<BRIG_OPCODE_LERP>                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAD                : return vis.template visitOpcode<BRIG_OPCODE_MAD>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAD24              : return vis.template visitOpcode<BRIG_OPCODE_MAD24>                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAD24HI            : return vis.template visitOpcode<BRIG_OPCODE_MAD24HI>               (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MASKLANE           : return vis.template visitOpcode<BRIG_OPCODE_MASKLANE>              (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAX                : return vis.template visitOpcode<BRIG_OPCODE_MAX>                   (inst);
    case BRIG_OPCODE_MAXCUID            : return vis.template visitOpcode<BRIG_OPCODE_MAXCUID>               (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MAXWAVEID          : return vis.template visitOpcode<BRIG_OPCODE_MAXWAVEID>             (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MIN                : return vis.template visitOpcode<BRIG_OPCODE_MIN>                   (inst);
    case BRIG_OPCODE_MOV                : return vis.template visitOpcode<BRIG_OPCODE_MOV>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MUL                : return vis.template visitOpcode<BRIG_OPCODE_MUL>                   (inst);
    case BRIG_OPCODE_MUL24              : return vis.template visitOpcode<BRIG_OPCODE_MUL24>                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MUL24HI            : return vis.template visitOpcode<BRIG_OPCODE_MUL24HI>               (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_MULHI              : return vis.template visitOpcode<BRIG_OPCODE_MULHI>                 (inst);
    case BRIG_OPCODE_NCOS               : return vis.template visitOpcode<BRIG_OPCODE_NCOS>                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NEG                : return vis.template visitOpcode<BRIG_OPCODE_NEG>                   (inst);
    case BRIG_OPCODE_NEXP2              : return vis.template visitOpcode<BRIG_OPCODE_NEXP2>                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NFMA               : return vis.template visitOpcode<BRIG_OPCODE_NFMA>                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NLOG2              : return vis.template visitOpcode<BRIG_OPCODE_NLOG2>                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NOP                : return vis.template visitOpcode<BRIG_OPCODE_NOP>                   (inst);
    case BRIG_OPCODE_NOT                : return vis.template visitOpcode<BRIG_OPCODE_NOT>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NRCP               : return vis.template visitOpcode<BRIG_OPCODE_NRCP>                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NRSQRT             : return vis.template visitOpcode<BRIG_OPCODE_NRSQRT>                (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NSIN               : return vis.template visitOpcode<BRIG_OPCODE_NSIN>                  (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NSQRT              : return vis.template visitOpcode<BRIG_OPCODE_NSQRT>                 (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_NULLPTR            : return vis.template visitOpcode<BRIG_OPCODE_NULLPTR>               (HSAIL_ASM::InstSeg(inst));
    case BRIG_OPCODE_OR                 : return vis.template visitOpcode<BRIG_OPCODE_OR>                    (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_PACK               : return vis.template visitOpcode<BRIG_OPCODE_PACK>                  (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_PACKCVT            : return vis.template visitOpcode<BRIG_OPCODE_PACKCVT>               (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_POPCOUNT           : return vis.template visitOpcode<BRIG_OPCODE_POPCOUNT>              (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_QID                : return vis.template visitOpcode<BRIG_OPCODE_QID>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_QPTR               : return vis.template visitOpcode<BRIG_OPCODE_QPTR>                  (HSAIL_ASM::InstSeg(inst));
    case BRIG_OPCODE_QUERYIMAGEARRAY    : return vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEARRAY>       (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_QUERYIMAGEDEPTH    : return vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEDEPTH>       (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_QUERYIMAGEFORMAT   : return vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEFORMAT>      (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_QUERYIMAGEHEIGHT   : return vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEHEIGHT>      (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_QUERYIMAGEORDER    : return vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEORDER>       (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_QUERYIMAGEWIDTH    : return vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEWIDTH>       (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_QUERYSAMPLERCOORD  : return vis.template visitOpcode<BRIG_OPCODE_QUERYSAMPLERCOORD>     (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_QUERYSAMPLERFILTER : return vis.template visitOpcode<BRIG_OPCODE_QUERYSAMPLERFILTER>    (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_RDIMAGE            : return vis.template visitOpcode<BRIG_OPCODE_RDIMAGE>               (HSAIL_ASM::InstImage(inst));
    case BRIG_OPCODE_RECEIVELANE        : return vis.template visitOpcode<BRIG_OPCODE_RECEIVELANE>           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_RELEASEFBAR        : return vis.template visitOpcode<BRIG_OPCODE_RELEASEFBAR>           (HSAIL_ASM::InstFbar(inst));
    case BRIG_OPCODE_REM                : return vis.template visitOpcode<BRIG_OPCODE_REM>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_RET                : return vis.template visitOpcode<BRIG_OPCODE_RET>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_RINT               : return vis.template visitOpcode<BRIG_OPCODE_RINT>                  (inst);
    case BRIG_OPCODE_SAD                : return vis.template visitOpcode<BRIG_OPCODE_SAD>                   (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_SADHI              : return vis.template visitOpcode<BRIG_OPCODE_SADHI>                 (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_SEGMENTP           : return vis.template visitOpcode<BRIG_OPCODE_SEGMENTP>              (HSAIL_ASM::InstSeg(inst));
    case BRIG_OPCODE_SENDLANE           : return vis.template visitOpcode<BRIG_OPCODE_SENDLANE>              (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_SETDETECTEXCEPT    : return vis.template visitOpcode<BRIG_OPCODE_SETDETECTEXCEPT>       (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_SHL                : return vis.template visitOpcode<BRIG_OPCODE_SHL>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_SHR                : return vis.template visitOpcode<BRIG_OPCODE_SHR>                   (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_SHUFFLE            : return vis.template visitOpcode<BRIG_OPCODE_SHUFFLE>               (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_SQRT               : return vis.template visitOpcode<BRIG_OPCODE_SQRT>                  (inst);
    case BRIG_OPCODE_ST                 : return vis.template visitOpcode<BRIG_OPCODE_ST>                    (HSAIL_ASM::InstMem(inst));
    case BRIG_OPCODE_STIMAGE            : return vis.template visitOpcode<BRIG_OPCODE_STIMAGE>               (HSAIL_ASM::InstImage(inst));
    case BRIG_OPCODE_STOF               : return vis.template visitOpcode<BRIG_OPCODE_STOF>                  (HSAIL_ASM::InstSeg(inst));
    case BRIG_OPCODE_SUB                : return vis.template visitOpcode<BRIG_OPCODE_SUB>                   (inst);
    case BRIG_OPCODE_SYNC               : return vis.template visitOpcode<BRIG_OPCODE_SYNC>                  (HSAIL_ASM::InstBar(inst));
    case BRIG_OPCODE_SYSCALL            : return vis.template visitOpcode<BRIG_OPCODE_SYSCALL>               (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_TRUNC              : return vis.template visitOpcode<BRIG_OPCODE_TRUNC>                 (inst);
    case BRIG_OPCODE_UNPACK             : return vis.template visitOpcode<BRIG_OPCODE_UNPACK>                (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_UNPACKCVT          : return vis.template visitOpcode<BRIG_OPCODE_UNPACKCVT>             (HSAIL_ASM::InstSourceType(inst));
    case BRIG_OPCODE_UNPACKHI           : return vis.template visitOpcode<BRIG_OPCODE_UNPACKHI>              (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_UNPACKLO           : return vis.template visitOpcode<BRIG_OPCODE_UNPACKLO>              (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WAITFBAR           : return vis.template visitOpcode<BRIG_OPCODE_WAITFBAR>              (HSAIL_ASM::InstFbar(inst));
    case BRIG_OPCODE_WAVEID             : return vis.template visitOpcode<BRIG_OPCODE_WAVEID>                (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKGROUPID        : return vis.template visitOpcode<BRIG_OPCODE_WORKGROUPID>           (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKGROUPSIZE      : return vis.template visitOpcode<BRIG_OPCODE_WORKGROUPSIZE>         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKITEMABSID      : return vis.template visitOpcode<BRIG_OPCODE_WORKITEMABSID>         (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKITEMFLATABSID  : return vis.template visitOpcode<BRIG_OPCODE_WORKITEMFLATABSID>     (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKITEMFLATID     : return vis.template visitOpcode<BRIG_OPCODE_WORKITEMFLATID>        (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_WORKITEMID         : return vis.template visitOpcode<BRIG_OPCODE_WORKITEMID>            (HSAIL_ASM::InstBasic(inst));
    case BRIG_OPCODE_XOR                : return vis.template visitOpcode<BRIG_OPCODE_XOR>                   (HSAIL_ASM::InstBasic(inst));
    default : return RetType();
    }
}

