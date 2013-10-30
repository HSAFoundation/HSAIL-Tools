//===-- HSAILTestGenEmulator.h - HSAIL Instructions Emulator ------------===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_EMULATOR_H
#define INCLUDED_HSAIL_TESTGEN_EMULATOR_H

#include "HSAILTestGenVal.h"

namespace TESTGEN {

// ============================================================================
// HSAIL Instructions Emulator

// Instructions Emulator computes result of HSAIL instruction execution 
// based on input values arg0..arg4.
// This result depends on instruction and may include:
// - value placed into destination register
// - value placed into memory

// Check generic limitations on instruction being tested
bool testableInst(Inst inst);

// Emulate execution of instruction 'inst' using provided input values.
// Return value stored into destination register or an empty value 
// if there is no destination or if emulation failed.
Val emulateDstVal(Inst inst, Val arg0, Val arg1, Val arg2, Val arg3, Val arg4);

// Emulate execution of instruction 'inst' using provided input values.
// Return value stored into memory or an empty value if this 
// instruction does not modify memory or if emulation failed.
Val emulateMemVal(Inst inst, Val arg0, Val arg1, Val arg2, Val arg3, Val arg4);

// Return precision of result computation for this instruction.
// Return 0 for results computed with infinite precision.
// This is a property of target HW, not emulator!
double getPrecision(Inst inst);

// ============================================================================

} // namespace TESTGEN

#endif // INCLUDED_HSAIL_TESTGEN_EMULATOR_H
