//===-- HSAILTestGenSample.h - HSAIL Test Generator Sample --------------===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_SAMPLE_H
#define INCLUDED_HSAIL_TESTGEN_SAMPLE_H

#include "HSAILBrigContainer.h"
#include "HSAILItems.h"
#include "Brig.h"

#include "HSAILInstProps.h"

#include <cassert>

using HSAIL_ASM::BrigContainer;

using HSAIL_ASM::Inst;
using HSAIL_ASM::InstBasic;
using HSAIL_ASM::InstAddr;
using HSAIL_ASM::InstAtomic;
using HSAIL_ASM::InstAtomicImage;
using HSAIL_ASM::InstLane;
using HSAIL_ASM::InstCmp;
using HSAIL_ASM::InstCvt;
using HSAIL_ASM::InstImage;
using HSAIL_ASM::InstMem;
using HSAIL_ASM::InstMod;
using HSAIL_ASM::InstBr;
using HSAIL_ASM::InstSeg;
using HSAIL_ASM::InstSourceType;
using HSAIL_ASM::InstMemFence;
using HSAIL_ASM::InstSegCvt;
using HSAIL_ASM::InstSignal;
using HSAIL_ASM::InstQueue;

using namespace HSAIL_PROPS;

namespace TESTGEN {

class Context;

//==============================================================================
//==============================================================================
//==============================================================================
// Test sample which comprise of test instruction and a context 
// (required operands and symbols)

class Sample
{
private:
    mutable Inst inst; // mutable because Inst provides no const interface
    Context* ctx;

    //==========================================================================
public:
    Sample() : ctx(0) {}
    Sample(Context* c, Inst buf, unsigned opcode) : ctx(c), inst(buf) { setOpcode(opcode); }

    Sample(const Sample& s) 
    {
        if (!s.isEmpty()) 
        {
            ctx  = s.ctx;
            inst = s.inst;
        } 
        else 
        {
            ctx = 0;
        }
    }

    const Sample &operator=(const Sample &s) 
    {
        if (this == &s) 
        {
            return *this;
        }
        else if (!s.isEmpty()) 
        {
            ctx  = s.ctx;
            inst = s.inst;
        } 
        else 
        {
            ctx = 0;
            inst.reset();
        }
        return *this;
    }

    //==========================================================================

public:

    unsigned get(unsigned propId) const;
    void     set(unsigned propId, unsigned val);

    bool     isEmpty()         const { return !inst; }
    unsigned getFormat()       const { assert(!isEmpty()); return inst.brig()->kind; }
    unsigned getOpcode()       const { assert(!isEmpty()); return get(PROP_OPCODE); }
    Inst     getInst()         const { assert(!isEmpty()); return inst; }
    Context* getContext()      const { assert(!isEmpty()); return ctx; }
    void     setOpcode(unsigned opc) { assert(!isEmpty()); set(PROP_OPCODE, opc); }

    void     copyFrom(const Sample s);

    //==========================================================================
};

//==============================================================================
//==============================================================================
//==============================================================================

}; // namespace TESTGEN

#endif // INCLUDED_HSAIL_TESTGEN_SAMPLE_H
