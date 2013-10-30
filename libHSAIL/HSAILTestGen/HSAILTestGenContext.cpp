#include "HSAILTestGenContext.h"

namespace TESTGEN {

//=============================================================================
//=============================================================================
//=============================================================================

#define IMM_DEFAULT

#ifdef IMM_DEFAULT
static const uint64_t imm1_x   = 0xFFFFFFFFFFFFFFFFULL;
static const uint64_t imm8_x   = 0xFFFFFFFFFFFFFFFFULL;
static const uint64_t imm16_x  = 0xFFFFFFFFFFFFFFFFULL;
static const uint64_t imm32_x  = 0xFFFFFFFFFFFFFFFFULL;
static const uint64_t imm64_x  = 0xFFFFFFFFFFFFFFFFULL;
static const uint64_t imm128_h = 0x0;
static const uint64_t imm128_l = 7777777777777777777ULL;
#else
static const uint64_t imm1_x   = 0x1U;
static const uint64_t imm8_x   = 0x7FU;
static const uint64_t imm16_x  = 0x7FFFU;
static const uint64_t imm32_x  = 0x7FFFFFFFU;
static const uint64_t imm64_x  = 0x7FFFFFFFFFFFFFFFULL;
static const uint64_t imm128_h = 0x7FFFFFFFFFFFFFFFULL;
static const uint64_t imm128_l = 0xFFFFFFFFFFFFFFFFULL;
#endif

//=============================================================================
//=============================================================================
//=============================================================================

Operand Context::getOperand(unsigned oprId)
{
    assert(O_MINID < oprId && oprId < O_MAXID);

    using namespace Brig;

    if (isOperandCreated(oprId)) return operandTab[oprId];

    Operand opr = Operand();
    unsigned machineType = (machineModel == MODEL_LARGE)? BRIG_TYPE_B64 : BRIG_TYPE_B32;

    switch(oprId)
    {
    case O_NULL:          opr = Operand(&getContainer(), 0);       break; // FIXME: revise using and creating O_NULL

    case O_CREG:          opr = emitReg(BRIG_TYPE_B1);             break;
    case O_SREG:          opr = emitReg(BRIG_TYPE_B32);            break;
    case O_DREG:          opr = emitReg(BRIG_TYPE_B64);            break;
    case O_QREG:          opr = emitReg(BRIG_TYPE_B128);           break;

    case O_IMM1_X:        opr = emitImm(BRIG_TYPE_B1,   imm1_x );  break;
    case O_IMM8_X:        opr = emitImm(BRIG_TYPE_B8,   imm8_x );  break;
    case O_IMM16_X:       opr = emitImm(BRIG_TYPE_B16,  imm16_x);  break;
    case O_IMM32_X:       opr = emitImm(BRIG_TYPE_B32,  imm32_x);  break;
    case O_IMM64_X:       opr = emitImm(BRIG_TYPE_B64,  imm64_x);  break;
    case O_IMM128_X:      opr = emitImm(BRIG_TYPE_B128, imm128_l, imm128_h); break;

    case O_IMM32_0:       opr = emitImm(BRIG_TYPE_B32,  0);         break;
    case O_IMM32_1:       opr = emitImm(BRIG_TYPE_B32,  1);         break;
    case O_IMM32_2:       opr = emitImm(BRIG_TYPE_B32,  2);         break;
    case O_IMM32_3:       opr = emitImm(BRIG_TYPE_B32,  3);         break;
    case O_IMM32_4:       opr = emitImm(BRIG_TYPE_B32,  4);         break;

    case O_CREGV2_SRC:    opr = emitRegVector(2, BRIG_TYPE_B1);           break;
    case O_SREGV2_SRC:    opr = emitRegVector(2, BRIG_TYPE_B32);          break;
    case O_DREGV2_SRC:    opr = emitRegVector(2, BRIG_TYPE_B64);          break;

    case O_CREGV3_SRC:    opr = emitRegVector(3, BRIG_TYPE_B1);           break;
    case O_SREGV3_SRC:    opr = emitRegVector(3, BRIG_TYPE_B32);          break;
    case O_DREGV3_SRC:    opr = emitRegVector(3, BRIG_TYPE_B64);          break;

    case O_CREGV4_SRC:    opr = emitRegVector(4, BRIG_TYPE_B1);           break;
    case O_SREGV4_SRC:    opr = emitRegVector(4, BRIG_TYPE_B32);          break;
    case O_DREGV4_SRC:    opr = emitRegVector(4, BRIG_TYPE_B64);          break;

    case O_CREGV2_DST:    opr = emitRegVector(2, BRIG_TYPE_B1 , false);   break;
    case O_SREGV2_DST:    opr = emitRegVector(2, BRIG_TYPE_B32, false);   break;
    case O_DREGV2_DST:    opr = emitRegVector(2, BRIG_TYPE_B64, false);   break;

    case O_CREGV3_DST:    opr = emitRegVector(3, BRIG_TYPE_B1 , false);   break;
    case O_SREGV3_DST:    opr = emitRegVector(3, BRIG_TYPE_B32, false);   break;
    case O_DREGV3_DST:    opr = emitRegVector(3, BRIG_TYPE_B64, false);   break;

    case O_CREGV4_DST:    opr = emitRegVector(4, BRIG_TYPE_B1 , false);   break;
    case O_SREGV4_DST:    opr = emitRegVector(4, BRIG_TYPE_B32, false);   break;
    case O_DREGV4_DST:    opr = emitRegVector(4, BRIG_TYPE_B64, false);   break;

    case O_WAVESIZE:      opr = emitWavesize();                           break;

    case O_FUNCTIONREF:   opr = emitFuncRef(sym_func);                    break;
    case O_FBARRIERREF:   opr = emitFBarrierRef(sym_fbarrier);            break;
    case O_LABELREF:      opr = emitLabelRef(NAME_LABEL);                 break;

    case O_ADDRESS_FLAT_REG:        opr = emitAddrRef(Directive(),      machineType, 0);       break;
    case O_ADDRESS_FLAT_OFF:        opr = emitAddrRef(Directive(),      machineType, -1, 0);   break;
    case O_ADDRESS_GLOBAL_VAR:      opr = emitAddrRef(sym_global_var,   machineType);          break;
    case O_ADDRESS_READONLY_VAR:    opr = emitAddrRef(sym_readonly_var, machineType);          break;

    case O_ADDRESS_GROUP_VAR:       opr = emitAddrRef(sym_group_var,   BRIG_TYPE_B32);    break;
    case O_ADDRESS_PRIVATE_VAR:     opr = emitAddrRef(sym_private_var, BRIG_TYPE_B32);    break;

    case O_ADDRESS_GLOBAL_ROIMG:    opr = emitAddrRef(sym_global_roimg, machineType);     break;
    case O_ADDRESS_GLOBAL_RWIMG:    opr = emitAddrRef(sym_global_rwimg, machineType);     break;
    case O_ADDRESS_GLOBAL_SAMP:     opr = emitAddrRef(sym_global_samp,  machineType);     break;
                                      
    case O_ADDRESS_READONLY_ROIMG:  opr = emitAddrRef(sym_readonly_roimg, machineType);   break;
    case O_ADDRESS_READONLY_RWIMG:  opr = emitAddrRef(sym_readonly_rwimg, machineType);   break;
    case O_ADDRESS_READONLY_SAMP:   opr = emitAddrRef(sym_readonly_samp,  machineType);   break;
                                      
    case O_JUMPTAB: assert(false); break; // Currently not used
    case O_CALLTAB: assert(false); break; // Currently not used

    }

    operandTab[oprId] = opr;
    return opr;
}

void Context::genSymbols()
{
    genSymbol(O_FUNCTIONREF);
    genSymbol(O_ADDRESS_GLOBAL_VAR);
    genSymbol(O_ADDRESS_GROUP_VAR);
    genSymbol(O_ADDRESS_PRIVATE_VAR);
    genSymbol(O_ADDRESS_READONLY_VAR);
    genSymbol(O_ADDRESS_GLOBAL_ROIMG);
    genSymbol(O_ADDRESS_GLOBAL_RWIMG);
    genSymbol(O_ADDRESS_READONLY_ROIMG);
    genSymbol(O_ADDRESS_READONLY_RWIMG);
    genSymbol(O_ADDRESS_GLOBAL_SAMP);
    genSymbol(O_ADDRESS_READONLY_SAMP);
    genSymbol(O_FBARRIERREF);
}

void Context::genSymbol(unsigned operandId)
{
    using namespace Brig;

    switch(operandId)
    {
    case O_ADDRESS_GLOBAL_VAR:      if (!sym_global_var)     { sym_global_var     = emitSymbol(BRIG_TYPE_S32,   NAME_GLOBAL_VAR,     BRIG_SEGMENT_GLOBAL);   } break;
    case O_ADDRESS_READONLY_VAR:    if (!sym_readonly_var)   { sym_readonly_var   = emitSymbol(BRIG_TYPE_S32,   NAME_READONLY_VAR,   BRIG_SEGMENT_READONLY); } break;
    case O_ADDRESS_GROUP_VAR:       if (!sym_group_var)      { sym_group_var      = emitSymbol(BRIG_TYPE_S32,   NAME_GROUP_VAR,      BRIG_SEGMENT_GROUP);    } break;
    case O_ADDRESS_PRIVATE_VAR:     if (!sym_private_var)    { sym_private_var    = emitSymbol(BRIG_TYPE_S32,   NAME_PRIVATE_VAR,    BRIG_SEGMENT_PRIVATE);  } break;
    case O_ADDRESS_GLOBAL_ROIMG:    if (!sym_global_roimg)   { sym_global_roimg   = emitSymbol(BRIG_TYPE_ROIMG, NAME_GLOBAL_ROIMG,   BRIG_SEGMENT_GLOBAL);   } break;
    case O_ADDRESS_READONLY_ROIMG:  if (!sym_readonly_roimg) { sym_readonly_roimg = emitSymbol(BRIG_TYPE_ROIMG, NAME_READONLY_ROIMG, BRIG_SEGMENT_READONLY); } break;
    case O_ADDRESS_GLOBAL_RWIMG:    if (!sym_global_rwimg)   { sym_global_rwimg   = emitSymbol(BRIG_TYPE_RWIMG, NAME_GLOBAL_RWIMG,   BRIG_SEGMENT_GLOBAL);   } break;
    case O_ADDRESS_READONLY_RWIMG:  if (!sym_readonly_rwimg) { sym_readonly_rwimg = emitSymbol(BRIG_TYPE_RWIMG, NAME_READONLY_RWIMG, BRIG_SEGMENT_READONLY); } break;
    case O_ADDRESS_GLOBAL_SAMP:     if (!sym_global_samp)    { sym_global_samp    = emitSymbol(BRIG_TYPE_SAMP,  NAME_GLOBAL_SAMP,    BRIG_SEGMENT_GLOBAL);   } break;
    case O_ADDRESS_READONLY_SAMP:   if (!sym_readonly_samp)  { sym_readonly_samp  = emitSymbol(BRIG_TYPE_SAMP,  NAME_READONLY_SAMP,  BRIG_SEGMENT_READONLY); } break;
    case O_FBARRIERREF:             if (!sym_fbarrier)       { sym_fbarrier       = emitFBarrier(NAME_FBARRIER);                                             } break;
    case O_FUNCTIONREF:             if (!sym_func)           { sym_func = emitFuncStart(NAME_FUNC, 0, 0); emitFuncEnd(sym_func);                             } break;
    }
}

//==============================================================================
//==============================================================================
//==============================================================================

} // namespace TESTGEN