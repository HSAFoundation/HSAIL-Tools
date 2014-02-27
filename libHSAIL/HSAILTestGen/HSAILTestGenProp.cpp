
#include "HSAILTestGenProp.h"
#include "HSAILTestGenPropDesc.h"
#include "HSAILValidatorBase.h"
#include "HSAILTestGenOptions.h"

#include <algorithm>

using namespace HSAIL_ASM;

namespace TESTGEN {

//=============================================================================
//=============================================================================
//=============================================================================
// Mappings of abstract HDL values of extended properties to actual Brig values

// FIXME: ADD "HDL" PREFIX FOR HDL-GENERATED VALUES (THINK OVER UNIFICATION OF PREFIXES FOR HDL AND TGEN)
static const unsigned valMapDesc[] = // from HDL to TestGen
{
// FIXME: note that keys in this map may be used as indices to an array that hold expanded values (??? use array instead of map???)

    OPERAND_VAL_NULL,       O_NULL, 0,

    OPERAND_VAL_REG,        O_CREG, O_SREG, O_DREG, O_QREG, 0,
    OPERAND_VAL_REG_V2,     O_CREGV2_SRC, O_SREGV2_SRC, O_DREGV2_SRC, O_CREGV2_DST, O_SREGV2_DST, O_DREGV2_DST, 0,
    OPERAND_VAL_REG_V3,     O_CREGV3_SRC, O_SREGV3_SRC, O_DREGV3_SRC, O_CREGV3_DST, O_SREGV3_DST, O_DREGV3_DST, 0,
    OPERAND_VAL_REG_V4,     O_CREGV4_SRC, O_SREGV4_SRC, O_DREGV4_SRC, O_CREGV4_DST, O_SREGV4_DST, O_DREGV4_DST, 0,

    OPERAND_VAL_IMM,        O_IMM1_X, O_IMM8_X, O_IMM16_X, O_IMM32_X, O_IMM64_X, O_IMM128_X, O_WAVESIZE, 0,
    OPERAND_VAL_LAB,        O_LABELREF, 0,
    OPERAND_VAL_ADDR,       O_ADDRESS_FLAT_REG, O_ADDRESS_FLAT_OFF, 
                            O_ADDRESS_GLOBAL_VAR, O_ADDRESS_READONLY_VAR, O_ADDRESS_GROUP_VAR, O_ADDRESS_PRIVATE_VAR,
                            O_ADDRESS_GLOBAL_ROIMG, O_ADDRESS_GLOBAL_RWIMG, O_ADDRESS_GLOBAL_SAMP, O_ADDRESS_GLOBAL_SIG32, O_ADDRESS_GLOBAL_SIG64,
                            O_ADDRESS_READONLY_ROIMG, O_ADDRESS_READONLY_RWIMG, O_ADDRESS_READONLY_SAMP, O_ADDRESS_READONLY_SIG32, O_ADDRESS_READONLY_SIG64, 0,
    OPERAND_VAL_FUNC,       O_FUNCTIONREF, 0,

    OPERAND_VAL_ARGLIST,    0,
    OPERAND_VAL_JUMPTAB,    0,
    OPERAND_VAL_CALLTAB,    0,
    OPERAND_VAL_FBARRIER,   O_FBARRIERREF, 0,

    OPERAND_VAL_ROIMAGE,    O_ADDRESS_GLOBAL_ROIMG, O_ADDRESS_READONLY_ROIMG, 0, 
    OPERAND_VAL_RWIMAGE,    O_ADDRESS_GLOBAL_RWIMG, O_ADDRESS_READONLY_RWIMG, 0, 
    OPERAND_VAL_SAMPLER,    O_ADDRESS_GLOBAL_SAMP,  O_ADDRESS_READONLY_SAMP,  0,

    OPERAND_VAL_IMM0T2,     O_IMM32_0, O_IMM32_1, O_IMM32_2, 0, 
    OPERAND_VAL_IMM0T3,     O_IMM32_0, O_IMM32_1, O_IMM32_2, O_IMM32_3, 0,

    OPERAND_VAL_INVALID,    0,
    
    EQCLASS_VAL_0,          EQCLASS_0, 0,
    EQCLASS_VAL_ANY,        EQCLASS_0, EQCLASS_1, EQCLASS_2, EQCLASS_255, 0,
    EQCLASS_VAL_INVALID,    0,
};

const unsigned* getValMapDesc(unsigned* size) { *size = sizeof(valMapDesc) / sizeof(unsigned); return valMapDesc; };

//=============================================================================
//=============================================================================
//=============================================================================

const char* NAME_FUNC            = "&TestFunc";
const char* NAME_GLOBAL_VAR      = "&GlobalVar";
const char* NAME_GROUP_VAR       = "&GroupVar";
const char* NAME_PRIVATE_VAR     = "&PrivateVar";
const char* NAME_READONLY_VAR    = "&ReadonlyVar";
const char* NAME_GLOBAL_ROIMG    = "&GlobalROImg";
const char* NAME_GLOBAL_RWIMG    = "&GlobalRWImg";
const char* NAME_READONLY_ROIMG  = "&ReadonlyROImg";
const char* NAME_READONLY_RWIMG  = "&ReadonlyRWImg";
const char* NAME_GLOBAL_SAMP     = "&GlobalSamp"; 
const char* NAME_READONLY_SAMP   = "&ReadonlySamp";
const char* NAME_GLOBAL_SIG32    = "&GlobalSig32"; 
const char* NAME_READONLY_SIG32  = "&ReadonlySig32";
const char* NAME_GLOBAL_SIG64    = "&GlobalSig64"; 
const char* NAME_READONLY_SIG64  = "&ReadonlySig64";
const char* NAME_FBARRIER        = "&Fbarrier";
const char* NAME_LABEL           = "@TestLabel";

//=============================================================================
//=============================================================================
//=============================================================================

string prop2str(unsigned id)
{
    return PropValidator::prop2str(id);
}

string operand2str(unsigned id)
{
    switch(id)
    {
    case O_NULL:           return "none";
    case O_CREG:           return "$c0";
    case O_SREG:           return "$s0";
    case O_DREG:           return "$d0";
    case O_QREG:           return "$q0";
    case O_CREGV2_SRC:     return "($c0, $c0)";
    case O_SREGV2_SRC:     return "($s0, $s0)";
    case O_DREGV2_SRC:     return "($d0, $d0)";
    case O_CREGV3_SRC:     return "($c0, $c0, $c0)";
    case O_SREGV3_SRC:     return "($s0, $s0, $s0)";
    case O_DREGV3_SRC:     return "($d0, $d0, $d0)";
    case O_CREGV4_SRC:     return "($c0, $c0, $c0, $c0)";
    case O_SREGV4_SRC:     return "($s0, $s0, $s0, $s0)";
    case O_DREGV4_SRC:     return "($d0, $d0, $d0, $d0)";
    case O_CREGV2_DST:     return "($c0, $c1)";
    case O_SREGV2_DST:     return "($s0, $s1)";
    case O_DREGV2_DST:     return "($d0, $d1)";
    case O_CREGV3_DST:     return "($c0, $c1, $c2)";
    case O_SREGV3_DST:     return "($s0, $s1, $s2)";
    case O_DREGV3_DST:     return "($d0, $d1, $d2)";
    case O_CREGV4_DST:     return "($c0, $c1, $c2, $c3)";
    case O_SREGV4_DST:     return "($s0, $s1, $s2, $s3)";
    case O_DREGV4_DST:     return "($d0, $d1, $d2, $d3)";
    case O_IMM1_X:         return "IMM#b1";
    case O_IMM8_X:         return "IMM#b8";
    case O_IMM16_X:        return "IMM#b16";
    case O_IMM32_X:        return "IMM#b32";
    case O_IMM64_X:        return "IMM#b64";
    case O_IMM128_X:       return "IMM#b128";

    case O_IMM32_0:        return "0";
    case O_IMM32_1:        return "1";
    case O_IMM32_2:        return "2";
    case O_IMM32_3:        return "3";

    case O_WAVESIZE:       return "WAVESIZE";
    case O_LABELREF:       return NAME_LABEL;
    case O_FUNCTIONREF:    return NAME_FUNC;
    case O_FBARRIERREF:    return NAME_FBARRIER;

    case O_ADDRESS_FLAT_REG:            return (machineModel == BRIG_MACHINE_LARGE)? "[$d0]" : "[$s0]";
    case O_ADDRESS_FLAT_OFF:            return "[0]";

    case O_ADDRESS_GLOBAL_VAR:          return string("[") + NAME_GLOBAL_VAR     + "]";
    case O_ADDRESS_READONLY_VAR:        return string("[") + NAME_READONLY_VAR   + "]";
    case O_ADDRESS_GROUP_VAR:           return string("[") + NAME_GROUP_VAR      + "]";
    case O_ADDRESS_PRIVATE_VAR:         return string("[") + NAME_PRIVATE_VAR    + "]";

    case O_ADDRESS_GLOBAL_ROIMG:        return string("[") + NAME_GLOBAL_ROIMG   + "]";
    case O_ADDRESS_GLOBAL_RWIMG:        return string("[") + NAME_GLOBAL_RWIMG   + "]";
    case O_ADDRESS_GLOBAL_SAMP:         return string("[") + NAME_GLOBAL_SAMP    + "]";
    case O_ADDRESS_GLOBAL_SIG32:        return string("[") + NAME_GLOBAL_SIG32   + "]";
    case O_ADDRESS_GLOBAL_SIG64:        return string("[") + NAME_GLOBAL_SIG64   + "]";

    case O_ADDRESS_READONLY_ROIMG:      return string("[") + NAME_READONLY_ROIMG + "]";
    case O_ADDRESS_READONLY_RWIMG:      return string("[") + NAME_READONLY_RWIMG + "]";
    case O_ADDRESS_READONLY_SAMP:       return string("[") + NAME_READONLY_SAMP  + "]";
    case O_ADDRESS_READONLY_SIG32:      return string("[") + NAME_READONLY_SIG32 + "]";
    case O_ADDRESS_READONLY_SIG64:      return string("[") + NAME_READONLY_SIG64 + "]";
    
    case O_JUMPTAB:                     return "[Jumptab]"; // currently unused
    case O_CALLTAB:                     return "[Calltab]"; // currently unused

    default: assert(false); return "";
    }
}

string eqclass2str(unsigned id)
{
    switch(id)
    {
    case EQCLASS_0:         return "0";
    case EQCLASS_1:         return "1";
    case EQCLASS_2:         return "2";
    case EQCLASS_255:       return "255";

    default: assert(false); return "";
    }
}

string val2str(unsigned id, unsigned val)
{
    if (PROP_D0 <= id && id <= PROP_S4) // TestGen-specific
    {
        return operand2str(val);
    }
    else if (id == PROP_EQUIVCLASS)        // TestGen-specific
    {
        return eqclass2str(val);
    }
    else
    {
        return PropValidator::val2str(id, val);
    }
}

//=============================================================================
//=============================================================================
//=============================================================================

static bool isOperandProp(unsigned propId)
{
    switch(propId)
    {
    case PROP_D0:
    case PROP_D1:                 
    case PROP_S0:
    case PROP_S1:
    case PROP_S2:
    case PROP_S3:
    case PROP_S4:
        return true;
    default: 
        return false;
    }
}

static bool isImmOperandId(unsigned val)
{
    switch(val)
    {
    case O_IMM1_X:
    case O_IMM8_X:
    case O_IMM16_X:
    case O_IMM32_X:
    case O_IMM64_X:
    case O_IMM128_X:
        return true;
    case O_IMM32_0:
    case O_IMM32_1:
    case O_IMM32_2:
    case O_IMM32_3:
        return true;
    case O_WAVESIZE:
        return true;

    default: 
        return false;
    }
}

//=============================================================================
//=============================================================================
//=============================================================================

struct ImmOperandDetector { bool operator()(unsigned val) { return isImmOperandId(val); }};
    
// This is not a generic soultion but rather a hack.
// It is because removal of imm operands may cause TestGen fail finding valid combinations of opernads.
void Prop::tryRemoveImmOperands()
{
    vector<unsigned> copy = pValues;

    pValues.erase(std::remove_if(pValues.begin(), pValues.end(), ImmOperandDetector()), pValues.end());
    
    // There are instructions which accept imm operands only - for these keep operand list unchanged.
    if (pValues.empty()) pValues = copy;
}

void Prop::init(const unsigned* pVals, unsigned pValsNum, const unsigned* nVals, unsigned nValsNum)
{
    for (unsigned i = 0; i < pValsNum; ++i) appendPositive(pVals[i]);
    for (unsigned i = 0; i < nValsNum; ++i) appendNegative(nVals[i]); // NB: positive values may be excluded for neutral props 

    if (!enableImmOperands && isOperandProp(propId)) tryRemoveImmOperands();

    // This is to minimize deps from HDL-generated code
    std::sort(pValues.begin(), pValues.end());
    std::sort(nValues.begin(), nValues.end());
}

Prop* Prop::create(unsigned propId, const unsigned* pVals, unsigned pValsNum, const unsigned* nVals, unsigned nValsNum)
{
    Prop* prop;
    if (PropDesc::isBrigProp(propId))
    {
        prop = new Prop(propId);
    }
    else 
    {
        prop = new ExtProp(propId);
    }
    prop->init(pVals, pValsNum, nVals, nValsNum);
    return prop;
}

map<unsigned, const unsigned*> ExtProp::valMap;

//=============================================================================
//=============================================================================
//=============================================================================

}; // namespace TESTGEN
