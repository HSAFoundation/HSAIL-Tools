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
Parser::OperandParser Parser::getOperandParser(Brig::BrigOpcode16_t arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_CALL               : return &Parser::parseCallOperands;
    case BRIG_OPCODE_ICALL              : return &Parser::parseCallOperands;
    case BRIG_OPCODE_SBR                : return &Parser::parseSbrOperands;
    case BRIG_OPCODE_SCALL              : return &Parser::parseCallOperands;
    default : return &Parser::parseOperands;
    }
}

OpcodeParser getOpcodeParser(Brig::BrigOpcode16_t arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ABS                : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_ACTIVELANECOUNT    : return parseMnemoLane;
    case BRIG_OPCODE_ACTIVELANEID       : return parseMnemoLane;
    case BRIG_OPCODE_ACTIVELANEMASK     : return parseMnemoLane;
    case BRIG_OPCODE_ACTIVELANESHUFFLE  : return parseMnemoLane;
    case BRIG_OPCODE_ADD                : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_ADDQUEUEWRITEINDEX : return parseMnemoQueue;
    case BRIG_OPCODE_ALLOCA             : return parseMnemoMem;
    case BRIG_OPCODE_ARRIVEFBAR         : return parseMnemoBr;
    case BRIG_OPCODE_ATOMIC             : return parseMnemoAtomic;
    case BRIG_OPCODE_ATOMICNORET        : return parseMnemoAtomic;
    case BRIG_OPCODE_BARRIER            : return parseMnemoBr;
    case BRIG_OPCODE_BR                 : return parseMnemoBr;
    case BRIG_OPCODE_CALL               : return parseMnemoBr;
    case BRIG_OPCODE_CASQUEUEWRITEINDEX : return parseMnemoQueue;
    case BRIG_OPCODE_CBR                : return parseMnemoBr;
    case BRIG_OPCODE_CEIL               : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_CLASS              : return parseMnemoSourceType;
    case BRIG_OPCODE_CMP                : return parseMnemoCmp;
    case BRIG_OPCODE_COMBINE            : return parseMnemoSourceType;
    case BRIG_OPCODE_COPYSIGN           : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_CVT                : return parseMnemoCvt;
    case BRIG_OPCODE_DIV                : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_EXPAND             : return parseMnemoSourceType;
    case BRIG_OPCODE_FIRSTBIT           : return parseMnemoSourceType;
    case BRIG_OPCODE_FLOOR              : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_FMA                : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_FRACT              : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_FTOS               : return parseMnemoSegCvt;
    case BRIG_OPCODE_GCNAPPEND          : return parseMnemoAddr;
    case BRIG_OPCODE_GCNATOMIC          : return parseMnemoAtomic;
    case BRIG_OPCODE_GCNATOMICNORET     : return parseMnemoAtomic;
    case BRIG_OPCODE_GCNCONSUME         : return parseMnemoAddr;
    case BRIG_OPCODE_GCNLD              : return parseMnemoMem;
    case BRIG_OPCODE_GCNMADS            : return parseMnemoBasicNoType;
    case BRIG_OPCODE_GCNMADU            : return parseMnemoBasicNoType;
    case BRIG_OPCODE_GCNMQSAD4          : return parseMnemoBasicNoType;
    case BRIG_OPCODE_GCNREGIONALLOC     : return parseMnemoBasicNoType;
    case BRIG_OPCODE_GCNST              : return parseMnemoMem;
    case BRIG_OPCODE_ICALL              : return parseMnemoBr;
    case BRIG_OPCODE_INITFBAR           : return parseMnemoBasicNoType;
    case BRIG_OPCODE_JOINFBAR           : return parseMnemoBr;
    case BRIG_OPCODE_LASTBIT            : return parseMnemoSourceType;
    case BRIG_OPCODE_LD                 : return parseMnemoMem;
    case BRIG_OPCODE_LDA                : return parseMnemoAddr;
    case BRIG_OPCODE_LDIMAGE            : return parseMnemoImage;
    case BRIG_OPCODE_LDQUEUEREADINDEX   : return parseMnemoQueue;
    case BRIG_OPCODE_LDQUEUEWRITEINDEX  : return parseMnemoQueue;
    case BRIG_OPCODE_LEAVEFBAR          : return parseMnemoBr;
    case BRIG_OPCODE_MAX                : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_MEMFENCE           : return parseMnemoMemFence;
    case BRIG_OPCODE_MIN                : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_MUL                : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_MULHI              : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_NEG                : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_NOP                : return parseMnemoNop;
    case BRIG_OPCODE_NULLPTR            : return parseMnemoSeg;
    case BRIG_OPCODE_PACK               : return parseMnemoSourceType;
    case BRIG_OPCODE_PACKCVT            : return parseMnemoSourceType;
    case BRIG_OPCODE_POPCOUNT           : return parseMnemoSourceType;
    case BRIG_OPCODE_QUERYIMAGE         : return parseMnemoQueryImage;
    case BRIG_OPCODE_QUERYSAMPLER       : return parseMnemoQuerySampler;
    case BRIG_OPCODE_RDIMAGE            : return parseMnemoImage;
    case BRIG_OPCODE_RELEASEFBAR        : return parseMnemoBasicNoType;
    case BRIG_OPCODE_RET                : return parseMnemoBasicNoType;
    case BRIG_OPCODE_RINT               : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_SAD                : return parseMnemoSourceType;
    case BRIG_OPCODE_SADHI              : return parseMnemoSourceType;
    case BRIG_OPCODE_SBR                : return parseMnemoBr;
    case BRIG_OPCODE_SCALL              : return parseMnemoBr;
    case BRIG_OPCODE_SEGMENTP           : return parseMnemoSegCvt;
    case BRIG_OPCODE_SIGNAL             : return parseMnemoSignal;
    case BRIG_OPCODE_SIGNALNORET        : return parseMnemoSignal;
    case BRIG_OPCODE_SQRT               : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_ST                 : return parseMnemoMem;
    case BRIG_OPCODE_STIMAGE            : return parseMnemoImage;
    case BRIG_OPCODE_STOF               : return parseMnemoSegCvt;
    case BRIG_OPCODE_STQUEUEREADINDEX   : return parseMnemoQueue;
    case BRIG_OPCODE_STQUEUEWRITEINDEX  : return parseMnemoQueue;
    case BRIG_OPCODE_SUB                : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_TRUNC              : return parseMnemoBasicOrMod;
    case BRIG_OPCODE_UNPACK             : return parseMnemoSourceType;
    case BRIG_OPCODE_UNPACKCVT          : return parseMnemoSourceType;
    case BRIG_OPCODE_WAITFBAR           : return parseMnemoBr;
    case BRIG_OPCODE_WAVEBARRIER        : return parseMnemoBr;
    default : return parseMnemoBasic;
    }
}

int vecOpndIndex(Brig::BrigOpcode16_t arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ACTIVELANEMASK     : return 0;
    case BRIG_OPCODE_COMBINE            : return 1;
    case BRIG_OPCODE_EXPAND             : return 0;
    case BRIG_OPCODE_GCNLD              : return 0;
    case BRIG_OPCODE_GCNST              : return 0;
    case BRIG_OPCODE_LD                 : return 0;
    case BRIG_OPCODE_LDIMAGE            : return 0;
    case BRIG_OPCODE_RDIMAGE            : return 0;
    case BRIG_OPCODE_ST                 : return 0;
    case BRIG_OPCODE_STIMAGE            : return 0;
    default : return -1;
    }
}

