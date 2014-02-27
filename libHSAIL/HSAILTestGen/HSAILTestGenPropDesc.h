//===-- HSAILTestGenPropDesc.h - HSAIL Test Generator - Description of HDL properties ===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_PROP_DESC_H
#define INCLUDED_HSAIL_TESTGEN_PROP_DESC_H

#include "HSAILItems.h"

using HSAIL_ASM::Inst;

namespace TESTGEN {

//==============================================================================
//==============================================================================
//==============================================================================
// Interface with HDL-generated description of HSAIL instructions

class PropDesc
{
public:
    static void init(unsigned machineModel);
    static void clean();

public:
    static const unsigned* getPropVals(unsigned propId, unsigned& num);                 // Return all possible values 'propId' may take

    static       bool      isBrigProp(unsigned propId);                                 // Return true if 'propId' is a Brig property; return false otherwise

public:
    static const unsigned* getOpcodes(unsigned& num);                                   // Return all HDL-described opcodes

    static       unsigned  getFormat(unsigned opcode);                                  // Return format of specified opcode

    static const unsigned* getProps(unsigned opcode, unsigned& prm, unsigned& sec);     // Return all properties which describe specified instruction (primary and secondary)
                                                                                        // The order of primary properties is important and must be preserved. 
                                                                                        // Primary properties have to be assigned and validated in the specified order. 
                                                                                        // Note that meta-properties are not included in this list because TestGen
                                                                                        // does not work with these properties _directly_.

    static const unsigned* getPropVals(unsigned opcode, unsigned propId, unsigned& num);// Return all positive values for 'propId' of specified instruction

public:
    static bool isValidProp(Inst inst, unsigned propId);                                // Return true if 'propId' has a valid value for instruction 'inst', false otherwise.
                                                                                        // This function is able to validate each property independently of each other but 
                                                                                        // assumes sertain order of validation. Namely, primary properties must be assigned 
                                                                                        // and validated in the same order as specified by getProps because validation of some 
                                                                                        // properties may include implicit checks of other properties.
                                                                                        // Note that this validation may be incomplete. Full validation of all necessary 
                                                                                        // conditions for all primary properties is performed only as part of validation for
                                                                                        // last primary property (this also includes validation of meta-properties).
                                                                                        // Also note that secondary properties only depend on primary properties.

    static bool validatePrimaryProps(Inst inst);                                        // Return true if all primary properties have valid values. This is the complete check.

    static bool isValidInst(Inst inst);                                                 // Return true if instruction has valid values for all props.
                                                                                        // This function duplicates functionality of InstValidator (used for debugging only).
};

//==============================================================================
//==============================================================================
//==============================================================================

}; // namespace TESTGEN

#endif // INCLUDED_HSAIL_TESTGEN_PROP_DESC_H
