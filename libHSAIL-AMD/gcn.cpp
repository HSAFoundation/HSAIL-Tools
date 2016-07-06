// University of Illinois/NCSA
// Open Source License
//
// Copyright (c) 2013-2015, Advanced Micro Devices, Inc.
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

#include "Brig_amd.h"

#include "HSAILScanner.h"
#include "HSAILParser.h"
#include "HSAILItems.h"
#include "HSAILBrigantine.h"
#include "HSAILInstProps.h"
#include "HSAILGenericExtension.h"

#include "HSAILValidatorBase.h"

#include <sstream>

using namespace HSAIL_ASM;
using namespace HSAIL_PROPS;

using std::ostringstream;

namespace amd { namespace hsail { namespace gcn {

//=============================================================================
//=============================================================================
//=============================================================================

#include "InstValidation_gcn_gen.hpp"

static const char* seg2mnemo(unsigned prop, unsigned val)
{
    return (prop == PROP_SEGMENT && val == BRIG_SEGMENT_AMD_GCN)? AMD_GCN_SEGMENT_NAME : 0;
}

class GcnInstValidator : public amd::hsail::gcn::InstValidator
{
public:
    GcnInstValidator(unsigned model, unsigned profile) : InstValidator(model, profile) {}

public:
    virtual const char* propValExt2mnemo(unsigned prop, unsigned val) const { return seg2mnemo(prop, val); }
    virtual unsigned getSegAddrSize(unsigned seg, bool isL)  const 
    { 
        return (seg == BRIG_SEGMENT_AMD_GCN)? 32 : InstValidator::getSegAddrSize(seg, isL); 
    }
};

//=============================================================================
//=============================================================================
//=============================================================================

#define AMD_GCN_SEGMENT_SUFF            "_" AMD_GCN_SEGMENT_NAME

Inst parseMnemoGcnMem(unsigned opCode, Scanner& scanner, Brigantine& bw, int*);
Inst parseMnemoGcnAtomic(unsigned opCode, Scanner& scanner, Brigantine& bw, int*);
Inst parseMnemoGcnAddr(unsigned opCode, Scanner& scanner, Brigantine& bw, int*);

const ExtInstDesc gcnDescTab[] =
{
    {"amd_gcn_madu",                BRIG_OPCODE_AMD_GCN_MADU,                parseMnemoBasicNoType,  -1},
    {"amd_gcn_mads",                BRIG_OPCODE_AMD_GCN_MADS,                parseMnemoBasicNoType,  -1},
    {"amd_gcn_min",                 BRIG_OPCODE_AMD_GCN_MIN,                 parseMnemoBasic,        -1},
    {"amd_gcn_max",                 BRIG_OPCODE_AMD_GCN_MAX,                 parseMnemoBasic,        -1},
    {"amd_gcn_min3",                BRIG_OPCODE_AMD_GCN_MIN3,                parseMnemoBasic,        -1},
    {"amd_gcn_med3",                BRIG_OPCODE_AMD_GCN_MED3,                parseMnemoBasic,        -1},
    {"amd_gcn_max3",                BRIG_OPCODE_AMD_GCN_MAX3,                parseMnemoBasic,        -1},
    {"amd_gcn_bfm",                 BRIG_OPCODE_AMD_GCN_BFM,                 parseMnemoBasic,        -1},
    {"amd_gcn_divrelaxed",          BRIG_OPCODE_AMD_GCN_DIVRELAXED,          parseMnemoBasicOrMod,   -1},
    {"amd_gcn_divrelaxednarrow",    BRIG_OPCODE_AMD_GCN_DIVRELAXEDNARROW,    parseMnemoBasic,        -1},
    {"amd_gcn_fldexp",              BRIG_OPCODE_AMD_GCN_FLDEXP,              parseMnemoBasicOrMod,   -1},
    {"amd_gcn_frexp_exp",           BRIG_OPCODE_AMD_GCN_FREXP_EXP,           parseMnemoBasicOrMod,   -1},
    {"amd_gcn_frexp_mant",          BRIG_OPCODE_AMD_GCN_FREXP_MANT,          parseMnemoBasicOrMod,   -1},
    {"amd_gcn_trig_preop",          BRIG_OPCODE_AMD_GCN_TRIG_PREOP,          parseMnemoBasicOrMod,   -1},
    {"amd_gcn_region_alloc",        BRIG_OPCODE_AMD_GCN_REGIONALLOC,         parseMnemoBasicNoType,  -1},
    {"amd_gcn_ld",                  BRIG_OPCODE_AMD_GCN_LD,                  parseMnemoGcnMem,        0},
    {"amd_gcn_st",                  BRIG_OPCODE_AMD_GCN_ST,                  parseMnemoGcnMem,        0},
    {"amd_gcn_atomic",              BRIG_OPCODE_AMD_GCN_ATOMIC,              parseMnemoGcnAtomic,    -1},
    {"amd_gcn_atomicNoRet",         BRIG_OPCODE_AMD_GCN_ATOMICNORET,         parseMnemoGcnAtomic,    -1},
    {"amd_gcn_atomic_append",       BRIG_OPCODE_AMD_GCN_APPEND,              parseMnemoGcnAddr,      -1},
    {"amd_gcn_atomic_consume",      BRIG_OPCODE_AMD_GCN_CONSUME,             parseMnemoGcnAddr,      -1},
    {"amd_gcn_msad",                BRIG_OPCODE_AMD_GCN_MSAD,                parseMnemoBasic,        -1},
    {"amd_gcn_qsad",                BRIG_OPCODE_AMD_GCN_QSAD,                parseMnemoBasic,        -1},
    {"amd_gcn_mqsad",               BRIG_OPCODE_AMD_GCN_MQSAD,               parseMnemoBasic,        -1},
    {"amd_gcn_mqsad4",              BRIG_OPCODE_AMD_GCN_MQSAD4,              parseMnemoBasicNoType,  -1},
    {"amd_gcn_sadw",                BRIG_OPCODE_AMD_GCN_SADW,                parseMnemoBasic,        -1},
    {"amd_gcn_sadd",                BRIG_OPCODE_AMD_GCN_SADD,                parseMnemoBasic,        -1},
    {"amd_gcn_sleep",               BRIG_OPCODE_AMD_GCN_SLEEP,               parseMnemoBasic,        -1},
    {"amd_gcn_priority",            BRIG_OPCODE_AMD_GCN_PRIORITY,            parseMnemoBasic,        -1},
    {"amd_gcn_b4xchg",              BRIG_OPCODE_AMD_GCN_B4XCHG,              parseMnemoBasic,        -1},
    {"amd_gcn_b32xchg",             BRIG_OPCODE_AMD_GCN_B32XCHG,             parseMnemoBasic,        -1},
};

#define GCN_DESC_SIZE (sizeof(gcnDescTab) / sizeof(ExtInstDesc))

class GcnExtension : public GenericExtension<GcnInstValidator>
{
    //=============================================================================
    //=============================================================================
    //=============================================================================
public:

    virtual const char* getName() const 
    {
        return AMD_GCN_EXTENSION_NAME;
    }

    virtual bool isMnemoPrefix(const string& prefix) const
    {
        return (prefix == AMD_GCN_EXTENSION_OPCODE_PREFIX);
    }

    virtual Inst parseInstMnemo(const string& prefix, Scanner& scanner, Brigantine& bw, int* vx) const
    {
        Inst res = GenericExtension::parseInstMnemo(prefix, scanner, bw, vx);
        const ExtInstDesc* desc = getInstDesc(res.opcode());
        if (desc->parser == parseMnemoBasicNoType) res.type() = BRIG_TYPE_B32;
        return res;
    }

    virtual string getMnemo(Inst inst) const
    {
        assert(inst);
        unsigned opcode = inst.opcode();
        const ExtInstDesc* desc = getInstDesc(opcode);

        if (opcode == BRIG_OPCODE_AMD_GCN_APPEND || opcode == BRIG_OPCODE_AMD_GCN_CONSUME)
        {
            return string(desc->name) + "_" + type2str(inst.type());
        }
        else if (desc->parser == parseMnemoBasicNoType)
        {
            return string(desc->name);
        }
        else
        {
            return "";
        }
    }

    virtual unsigned getDstOperandsNum(unsigned opcode) const 
    { 
        switch(opcode)
        {
        case BRIG_OPCODE_AMD_GCN_ST:
        case BRIG_OPCODE_AMD_GCN_ATOMICNORET:
        case BRIG_OPCODE_AMD_GCN_REGIONALLOC:
        case BRIG_OPCODE_AMD_GCN_SLEEP:
        case BRIG_OPCODE_AMD_GCN_PRIORITY:
            return 0;
        default:
            return 1;
        }
    }

    string type2str(unsigned val) const { return stdPropVal2mnemo(PROP_TYPE, val, BRIG_TYPE_NONE); }

    virtual const char* propVal2mnemo(unsigned prop, unsigned val) const
    {
        const char* s = seg2mnemo(prop, val);
        return s? s : GenericExtension::propVal2mnemo(prop, val);
    }

    virtual const string propVal2enum(unsigned prop, unsigned val) const
    {
        if (prop == PROP_SEGMENT)
        {
            if (val == BRIG_SEGMENT_AMD_GCN) return "BRIG_SEGMENT_AMD_GCN";
        }
        else if (prop == PROP_OPCODE)
        {
            if (val == BRIG_OPCODE_AMD_GCN_REGIONALLOC) return "BRIG_OPCODE_AMD_GCN_REGIONALLOC";
            if (val == BRIG_OPCODE_AMD_GCN_APPEND)      return "BRIG_OPCODE_AMD_GCN_APPEND";
            if (val == BRIG_OPCODE_AMD_GCN_CONSUME)     return "BRIG_OPCODE_AMD_GCN_CONSUME";
        }
        return GenericExtension::propVal2enum(prop, val);
    }

    //=============================================================================
    //=============================================================================
    //=============================================================================
protected:
    virtual const char*         getMnemoSuffix(const char* name) const { return name + strlen(AMD_GCN_EXTENSION_OPCODE_PREFIX); }
    virtual const ExtInstDesc*  getInstDescByIdx(unsigned idx)   const { return gcnDescTab + idx; }
    virtual       unsigned      getInstNum()                     const { return GCN_DESC_SIZE; }
};

//=============================================================================
//=============================================================================
//=============================================================================

Inst parseMnemoGcnMem(unsigned opCode, Scanner& scanner, Brigantine& bw, int* vx) 
{
    OptionalU const vector  = scanner.tryEatToken(EMVector);
    string    const segment = scanner.scan().text();

    if (segment != AMD_GCN_SEGMENT_SUFF) scanner.syntaxError("missing or invalid segment name");

    int vx2 = -1;
    InstMem res = parseMnemoMem(opCode, scanner, bw, &vx2);
    if (res.segment() != BRIG_SEGMENT_FLAT) scanner.syntaxError("invalid segment");
    if (vx2 != 1) scanner.syntaxError("invalid vX suffix");

    res.segment() = BRIG_SEGMENT_AMD_GCN;
    if (vx) *vx = vector.isInitialized() ? vector.value() : 1;

    return res;
}

Inst parseMnemoGcnAtomic(unsigned opCode, Scanner& scanner, Brigantine& bw, int*)
{
    unsigned  const atomicOperation = scanner.eatToken(EMAtomicOp);
    OptionalU const segment         = scanner.tryEatToken(EMSegment);
    unsigned  const memoryOrder     = scanner.eatToken(EMMemoryOrder);
    unsigned  const memoryScope     = scanner.eatToken(EMMemoryScope);
    OptionalU const equivClass      = tryParseEquiv(scanner);
    unsigned  const type            = scanner.eatToken(EMType);
    
    scanner.eatToken(EMNone);

    InstAtomic res = bw.addInst<InstAtomic>(opCode,type);

    res.atomicOperation() = atomicOperation;
    res.segment()         = BrigSegment(segment.isInitialized() ? segment.value() : BRIG_SEGMENT_AMD_GCN);
    res.equivClass()      = equivClass.isInitialized() ? equivClass.value() : 0;
    res.memoryOrder()     = memoryOrder;
    res.memoryScope()     = memoryScope;
    return res;
}

Inst parseMnemoGcnAddr(unsigned opCode, Scanner& scanner, Brigantine& bw, int* vx)
{
    unsigned const type = scanner.eatToken(EMType);
    
    scanner.eatToken(EMNone);

    InstAddr res = bw.addInst<InstAddr>(opCode);

    res.segment() = BRIG_SEGMENT_AMD_GCN;
    res.type() = type;

    return res;
}

//=============================================================================
//=============================================================================
//=============================================================================

const Extension* getExtension()
{
  static const GcnExtension gcn;
  return &gcn;
}

//=============================================================================
//=============================================================================
//=============================================================================

}}} // end of namespaces

