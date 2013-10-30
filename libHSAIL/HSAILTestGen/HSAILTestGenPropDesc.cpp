
#include "HSAILTestGenPropDesc.h"
#include "HSAILValidatorBase.h"

#include "HSAILItems.h"
#include "Brig.h"

#include "generated/HSAILTestGen_gen.hpp" 

using HSAIL_ASM::PropDescImpl;

namespace TESTGEN {

//==============================================================================
//==============================================================================
//==============================================================================

      bool      PropDesc::isBrigProp(unsigned propId)                                 { return PropDescImpl::isBrigProp(propId); }
const unsigned* PropDesc::getPropVals(unsigned propId, unsigned& num)                 { return PropDescImpl::getPropVals(propId, num); }
const unsigned* PropDesc::getOpcodes(unsigned& num)                                   { return PropDescImpl::getOpcodes(num); }
const unsigned* PropDesc::getProps(unsigned opcode, unsigned& prm, unsigned& sec)     { return PropDescImpl::getProps(opcode, prm, sec); }
const unsigned* PropDesc::getPropVals(unsigned opcode, unsigned propId, unsigned& num){ return PropDescImpl::getPropVals(opcode, propId, num); }
      unsigned  PropDesc::getFormat(unsigned opcode)                                  { return PropDescImpl::getFormat(opcode); }
      bool      PropDesc::isValidProp(Inst inst, unsigned propId)                     { return PropDescImpl::isValidProp(inst, propId); }
      bool      PropDesc::validatePrimaryProps(Inst inst)                             { return PropDescImpl::validatePrimaryProps(inst); }
      bool      PropDesc::isValidInst(Inst inst)                                      { return PropDescImpl::isValidInst(inst); }

//==============================================================================
//==============================================================================
//==============================================================================

}; // namespace TESTGEN 

