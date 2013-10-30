
#include "HSAILTestGenDump.h"

#include <sstream>
#include <string>
#include <iostream>

using std::string;
using std::ostringstream;

using namespace Brig;
using namespace HSAIL_ASM;

namespace TESTGEN {

//==============================================================================
//==============================================================================
//==============================================================================

void dump(const char* propName, const char* valName, unsigned val)
{
    std::cerr << propName << " = ";
    if (valName) {
        std::cerr << (strlen(valName) == 0? "none" : valName); 
    } else {
        std::cerr << val;
    }
    std::cerr << "\n";
}

string dumpOperand(Operand opr)
{
    ostringstream s;

    if      (!opr)                            { s << "NULL";  }
    else if (OperandReg              o = opr) { s << o.reg(); }
    else if (OperandRegVector        o = opr) { s << "(" << o.regs(0); for (unsigned i = 1; i < o.elementCount(); ++i) s << ", " << o.regs(i); s << ")"; }
    else if (OperandAddress          o = opr) { if (o.symbol()) s << "[" << o.symbol().name() << "]"; if (o.reg().deref()) s << "[" << o.reg() << "]"; if (o.offset() != 0) s << "[" << o.offset() << "]"; s << " // type = " << (o.type()? typeX2str(o.type()) : "?"); }
    else if (OperandWavesize         o = opr) { s << "wavesize // type = " << (o.type()? typeX2str(o.type()) : "?"); }
    else if (OperandLabelRef         o = opr) { s << DirectiveLabel(o.ref()).name(); }
    else if (OperandFunctionRef      o = opr) { s << DirectiveFunction(o.ref()).name(); }
    else if (OperandSignatureRef     o = opr) { s << DirectiveSignature(o.ref()).name(); }
    else if (OperandFbarrierRef      o = opr) { s << DirectiveFbarrier(o.ref()).name(); }
    else if (OperandLabelTargetsRef  o = opr) { s << DirectiveLabelTargets(o.ref()).name(); }
    else if (OperandLabelVariableRef o = opr) { s << DirectiveVariable(o.ref()).name(); }
    else if (OperandArgumentList     o = opr) { s << "("; for (unsigned i = 0; i < o.elementCount(); ++i) s << (i > 0? ", " : "") << DirectiveVariable(o.elements(i)).name(); s << ")"; }
    else if (OperandFunctionList     o = opr) { s << "("; for (unsigned i = 0; i < o.elementCount(); ++i) s << (i > 0? ", " : "") << DirectiveFunction(o.elements(i)).name(); s << ")"; }
    else if (OperandImmed            o = opr) { s << "IMM(" << (unsigned)o.bytes(0); for (unsigned i = 1; i < o.byteCount(); ++i) s << ", " << (unsigned)o.bytes(i); s << ") // type = " << typeX2str(o.type()); }
    else                                      { s << "*UNKNOWN*, kind = " << opr.kind(); }

    return s.str();
}

//F - use val2str
//F - minimize duplication of code

void dumpOpcode(unsigned val)    { dump("Opcode   ", opcode2str(val), val); }
void dumpType(unsigned val)      { dump("Type     ", typeX2str(val),  val); }
void dumpSegment(unsigned val)   { dump("Segment  ", (val == BRIG_SEGMENT_FLAT)? "flat" : segment2str(val), val); }
void dumpMemOrder(unsigned val)  { dump("MemOrder ", (val == BRIG_MEMORY_ORDER_NONE)? "none" : (val == BRIG_MEMORY_ORDER_RELAXED)? "relaxed" : memoryOrder2str(val), val); }
void dumpMemScope(unsigned val)  { dump("MemScope ", (val == BRIG_MEMORY_SCOPE_NONE)? "none" : (val == BRIG_MEMORY_SCOPE_SYSTEM)?  "system"  : memoryScope2str(val), val); }
void dumpMemFence(unsigned val)  { dump("MemFence ", (val == BRIG_MEMORY_FENCE_NONE)? "none" : memoryFence2str(val), val); }
void dumpAtmOp(unsigned val)     { dump("AtmOp    ", atomicOperation2str(val), val); }
void dumpImgType(unsigned val)   { dump("ImgType  ", typeX2str(val), val); }
void dumpCoordType(unsigned val) { dump("CoordType", typeX2str(val), val); }
void dumpGeom(unsigned val)      { dump("Geom     ", imageGeometry2str(val), val); }
void dumpRounding(unsigned val)  { dump("Rounding ", (val == BRIG_ROUND_NONE)? "none" : round2str(val), val); }
void dumpFtz(unsigned val)       { dump("Ftz      ", 0, val); }
void dumpWidth(unsigned val)     { dump("Width    ", width2str(val), val); }
void dumpSrcType(unsigned val)   { dump("SrcType  ", typeX2str(val),  val); }
void dumpCmpOp(unsigned val)     { dump("CmpOp    ", compareOperation2str(val),  val); }
void dumpPack(unsigned val)      { dump("Packing  ", pack2str(val),  val); }
void dumpAlign(unsigned val)     { dump("Align    ", 0, val); }
void dumpEqClass(unsigned val)   { dump("EqClass  ", 0, val); }

void dumpInst(Inst inst)
{
    std::cerr << "==========================================\n";

    dumpOpcode(inst.opcode());
    dumpType(inst.type());

    if      (InstBasic       i = inst) {    }
    else if (InstAddr        i = inst) { dumpSegment(i.segment());  }   
    else if (InstAtomic      i = inst) { dumpSegment(i.segment()); dumpMemOrder(i.memoryOrder()); dumpMemScope(i.memoryScope()); dumpAtmOp(i.atomicOperation());  } 
    else if (InstAtomicImage i = inst) { dumpImgType(i.imageType()); dumpCoordType(i.coordType()); dumpGeom(i.geometry()); dumpAtmOp(i.atomicOperation()); } 
    else if (InstBar         i = inst) { dumpMemOrder(i.memoryOrder()); dumpMemScope(i.memoryScope()); dumpMemFence(i.memoryFence()); dumpWidth(i.width());  } 
    else if (InstBr          i = inst) { dumpWidth(i.width()); } 
    else if (InstCmp         i = inst) { dumpSrcType(i.sourceType()); dumpRounding(i.modifier().round()); dumpFtz(i.modifier().ftz()); dumpCmpOp(i.compare()); dumpPack(i.pack()); }
    else if (InstCvt         i = inst) { dumpSrcType(i.sourceType()); dumpRounding(i.modifier().round()); dumpFtz(i.modifier().ftz()); }    
    else if (InstLane        i = inst) { dumpSrcType(i.sourceType()); dumpWidth(i.width());  } 
    else if (InstImage       i = inst) { dumpImgType(i.imageType()); dumpCoordType(i.coordType()); dumpGeom(i.geometry()); } 
    else if (InstMem         i = inst) { dumpSegment(i.segment()); dumpAlign(i.modifier().aligned()); dumpEqClass(i.equivClass()); dumpWidth(i.width()); } 
    else if (InstMod         i = inst) { dumpRounding(i.modifier().round()); dumpFtz(i.modifier().ftz()); dumpPack(i.pack()); } 
    else if (InstSeg         i = inst) { dumpSrcType(i.sourceType()); dumpSegment(i.segment()); }
    else if (InstSourceType  i = inst) { dumpSrcType(i.sourceType()); }

    dump("Operand 0", dumpOperand(inst.operand(0)).c_str(), 0);
    dump("Operand 1", dumpOperand(inst.operand(1)).c_str(), 0);
    dump("Operand 2", dumpOperand(inst.operand(2)).c_str(), 0);
    dump("Operand 3", dumpOperand(inst.operand(3)).c_str(), 0);
    dump("Operand 4", dumpOperand(inst.operand(4)).c_str(), 0);

}

//==============================================================================
//==============================================================================
//==============================================================================

}; // namespace TESTGEN
