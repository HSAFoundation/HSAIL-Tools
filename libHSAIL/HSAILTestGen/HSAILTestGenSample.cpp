
#include "HSAILTestGenSample.h"
#include "HSAILTestGenContext.h"

namespace TESTGEN {

//==============================================================================
//==============================================================================
//==============================================================================

unsigned Sample::get(unsigned propId) const
{
    assert(PROP_MINID < propId && propId < PROP_MAXID);
    assert(!isEmpty());

    switch(propId)
    {
    case PROP_OPCODE:  return (unsigned) inst.brig()->opcode;
    case PROP_TYPE:    return (unsigned) inst.brig()->type;

    case PROP_D0:
    case PROP_S0:      return getContext()->operand2id(inst.operand(0));
    case PROP_D1:      
    case PROP_S1:      return getContext()->operand2id(inst.operand(1));
    case PROP_S2:      return getContext()->operand2id(inst.operand(2));
    case PROP_S3:      return getContext()->operand2id(inst.operand(3));
    case PROP_S4:      return getContext()->operand2id(inst.operand(4));
    }

    switch(inst.brig()->kind) {
    case Brig::BRIG_INST_BASIC:        return get(InstBasic(inst),       propId);
    case Brig::BRIG_INST_ADDR:         return get(InstAddr(inst),        propId);
    case Brig::BRIG_INST_ATOMIC:       return get(InstAtomic(inst),      propId);
    case Brig::BRIG_INST_ATOMIC_IMAGE: return get(InstAtomicImage(inst), propId);
    case Brig::BRIG_INST_BAR:          return get(InstBar(inst),         propId);
    case Brig::BRIG_INST_BR:           return get(InstBr(inst),          propId);
    case Brig::BRIG_INST_CMP:          return get(InstCmp(inst),         propId);
    case Brig::BRIG_INST_CVT:          return get(InstCvt(inst),         propId);
    case Brig::BRIG_INST_LANE:         return get(InstLane(inst),        propId);
    case Brig::BRIG_INST_IMAGE:        return get(InstImage(inst),       propId);
    case Brig::BRIG_INST_MEM:          return get(InstMem(inst),         propId);
    case Brig::BRIG_INST_MOD:          return get(InstMod(inst),         propId);
    case Brig::BRIG_INST_SEG:          return get(InstSeg(inst),         propId);
    case Brig::BRIG_INST_SOURCE_TYPE:  return get(InstSourceType(inst),  propId);
    default: assert(false); return 0;
    }
}

unsigned Sample::get(InstBasic i, unsigned propId) const
{
    assert(i);
    assert(false); // nothing to read
    return 0;
}

unsigned Sample::get(InstAddr i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_SEGMENT: return (unsigned) i.segment();
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstAtomic i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_SEGMENT: return (unsigned) i.segment();
    case PROP_MEMORD:  return (unsigned) i.memoryOrder();
    case PROP_MEMSCP:  return (unsigned) i.memoryScope();
    case PROP_ATMOP:   return (unsigned) i.atomicOperation();
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstAtomicImage i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_ITYPE: return (unsigned) i.imageType();
    case PROP_CTYPE: return (unsigned) i.coordType();
    case PROP_GEOM:  return (unsigned) i.geometry();
    case PROP_ATMOP: return (unsigned) i.atomicOperation();
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstBar i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_MEMORD: return (unsigned) i.memoryOrder();
    case PROP_MEMSCP: return (unsigned) i.memoryScope();
    case PROP_MEMFNC: return (unsigned) i.memoryFence();
    case PROP_WIDTH:  return (unsigned) i.width();
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstBr i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_WIDTH:    return (unsigned) i.width();           
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstCmp i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE:    return (unsigned) i.sourceType();      
    case PROP_ROUNDING: return (unsigned) i.modifier().round();
    case PROP_FTZ:      return (unsigned) i.modifier().ftz();  
    case PROP_OPERATOR: return (unsigned) i.compare();         
    case PROP_PACKING:  return (unsigned) i.pack();             

    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstCvt i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE:    return (unsigned) i.sourceType();      
    case PROP_ROUNDING: return (unsigned) i.modifier().round();
    case PROP_FTZ:      return (unsigned) i.modifier().ftz();  
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstLane i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE: return (unsigned) i.sourceType();
    case PROP_WIDTH: return (unsigned) i.width();
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstImage i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_ITYPE: return (unsigned) i.imageType();
    case PROP_CTYPE: return (unsigned) i.coordType();
    case PROP_GEOM:  return (unsigned) i.geometry();
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstMem i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_SEGMENT: return (unsigned) i.segment();
    case PROP_ALIGN:   return (unsigned) i.modifier().aligned();
    case PROP_EQCLASS: return (unsigned) getContext()->eqclass2id(i.equivClass());
    case PROP_WIDTH:   return (unsigned) i.width();
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstMod i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_ROUNDING: return (unsigned) i.modifier().round();
    case PROP_FTZ:      return (unsigned) i.modifier().ftz();  
    case PROP_PACKING:  return (unsigned) i.pack();

    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstSeg i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE:   return (unsigned) i.sourceType();      
    case PROP_SEGMENT: return (unsigned) i.segment();
    default:
        assert(false);
        return 0;
    }
}

unsigned Sample::get(InstSourceType i, unsigned propId) const
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE: return (unsigned) i.sourceType();      
    default:
        assert(false);
        return 0;
    }
}

//==============================================================================
//==============================================================================
//==============================================================================

void Sample::set(unsigned propId, unsigned val)
{
    assert(PROP_MINID < propId && propId < PROP_MAXID);
    assert(!isEmpty());

    switch(propId)
    {
    case PROP_OPCODE: inst.brig()->opcode = (Brig::BrigOpcode) val; return;
    case PROP_TYPE:   inst.brig()->type   = (Brig::BrigTypeX)  val; return;

    case PROP_D0:
    case PROP_S0:   inst.operand(0) = getContext()->id2operand(val);    return;
    case PROP_D1:
    case PROP_S1:   inst.operand(1) = getContext()->id2operand(val);    return;
    case PROP_S2:   inst.operand(2) = getContext()->id2operand(val);    return;
    case PROP_S3:   inst.operand(3) = getContext()->id2operand(val);    return;
    case PROP_S4:   inst.operand(4) = getContext()->id2operand(val);    return;
    }

    switch(inst.brig()->kind) {
    case Brig::BRIG_INST_BASIC:        set(InstBasic(inst),       propId, val);  break;
    case Brig::BRIG_INST_ADDR:         set(InstAddr(inst),        propId, val);  break;
    case Brig::BRIG_INST_ATOMIC:       set(InstAtomic(inst),      propId, val);  break;
    case Brig::BRIG_INST_ATOMIC_IMAGE: set(InstAtomicImage(inst), propId, val);  break;
    case Brig::BRIG_INST_BAR:          set(InstBar(inst),         propId, val);  break;
    case Brig::BRIG_INST_BR:           set(InstBr(inst),          propId, val);  break;
    case Brig::BRIG_INST_CMP:          set(InstCmp(inst),         propId, val);  break;
    case Brig::BRIG_INST_CVT:          set(InstCvt(inst),         propId, val);  break;
    case Brig::BRIG_INST_LANE:         set(InstLane(inst),        propId, val);  break;
    case Brig::BRIG_INST_IMAGE:        set(InstImage(inst),       propId, val);  break;
    case Brig::BRIG_INST_MEM:          set(InstMem(inst),         propId, val);  break;
    case Brig::BRIG_INST_MOD:          set(InstMod(inst),         propId, val);  break;
    case Brig::BRIG_INST_SEG:          set(InstSeg(inst),         propId, val);  break;
    case Brig::BRIG_INST_SOURCE_TYPE:  set(InstSourceType(inst),  propId, val);  break;
    default: assert(false); break;
    }
}


void Sample::set(InstBasic i, unsigned propId, unsigned val)
{
    assert(i);
    assert(false); // nothing to set
}

void Sample::set(InstAddr i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_SEGMENT:  i.segment() = (Brig::BrigSegment) val; break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstAtomic i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_SEGMENT:  i.segment()         = (Brig::BrigSegment)         val; break;
    case PROP_MEMORD:   i.memoryOrder()     = (Brig::BrigMemoryOrder)     val; break;
    case PROP_MEMSCP:   i.memoryScope()     = (Brig::BrigMemoryScope)     val; break;
    case PROP_ATMOP:    i.atomicOperation() = (Brig::BrigAtomicOperation) val; break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstAtomicImage i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_ITYPE:    i.imageType()       = (Brig::BrigTypeX)           val; break;
    case PROP_CTYPE:    i.coordType()       = (Brig::BrigTypeX)           val; break;
    case PROP_ATMOP:    i.atomicOperation() = (Brig::BrigAtomicOperation) val; break;
    case PROP_GEOM:     i.geometry()        = (Brig::BrigImageGeometry)   val; break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstBar i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_MEMORD: i.memoryOrder() = (Brig::BrigMemoryOrder) val; break;
    case PROP_MEMSCP: i.memoryScope() = (Brig::BrigMemoryScope) val; break;
    case PROP_MEMFNC: i.memoryFence() = (Brig::BrigMemoryFence) val; break;
    case PROP_WIDTH:  i.width()       = (Brig::BrigWidth)       val; break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstBr i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_WIDTH:    i.width()            = (Brig::BrigWidth) val;      break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstCvt i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE:    i.sourceType()       = (Brig::BrigTypeX) val;      break;
    case PROP_ROUNDING: i.modifier().round() = (Brig::BrigRound) val;      break;
    case PROP_FTZ:      i.modifier().ftz()   =                   val != 0; break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstCmp i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE:    i.sourceType()       = (Brig::BrigTypeX)            val;      break;
    case PROP_ROUNDING: i.modifier().round() = (Brig::BrigRound)            val;      break;
    case PROP_FTZ:      i.modifier().ftz()   =                              val != 0; break;
    case PROP_OPERATOR: i.compare()          = (Brig::BrigCompareOperation) val;      break;
    case PROP_PACKING:  i.pack()             = (Brig::BrigPack)             val;      break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstLane i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE: i.sourceType() = (Brig::BrigTypeX) val; break;
    case PROP_WIDTH: i.width()      = (Brig::BrigWidth) val; break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstImage i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_ITYPE:    i.imageType()       = (Brig::BrigTypeX)           val; break;
    case PROP_CTYPE:    i.coordType()       = (Brig::BrigTypeX)           val; break;
    case PROP_GEOM:     i.geometry()        = (Brig::BrigImageGeometry)   val; break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstMem i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_SEGMENT:  i.segment()             = (Brig::BrigSegment) val;                 break;
    case PROP_ALIGN:    i.modifier().aligned()  =                     val != 0;            break;
    case PROP_WIDTH:    i.width()               = (Brig::BrigWidth)   val;                 break;
    case PROP_EQCLASS:  i.equivClass()          = (uint8_t) getContext()->id2eqclass(val); break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstMod i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_ROUNDING: i.modifier().round() = (Brig::BrigRound) val;       break;
    case PROP_FTZ:      i.modifier().ftz()   =                   val != 0;  break;
    case PROP_PACKING:  i.pack()             = (Brig::BrigPack)  val;       break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstSeg i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE:    i.sourceType() = (Brig::BrigTypeX)   val; break;
    case PROP_SEGMENT:  i.segment()    = (Brig::BrigSegment) val; break;
    default:
        assert(false); break;
    }
}

void Sample::set(InstSourceType i, unsigned propId, unsigned val)
{
    assert(i);
    switch(propId)
    {
    case PROP_STYPE: i.sourceType() = (Brig::BrigTypeX) val; break;
    default:
        assert(false); break;
    }
}

void Sample::copyFrom(const Sample s)
{
    assert(!s.isEmpty());
    assert(inst.brig()->kind == s.inst.brig()->kind);

    memcpy(inst.brig(), s.inst.brig(), s.inst.brig()->size);
}

//==============================================================================
//==============================================================================
//==============================================================================

} // namespace TESTGEN
