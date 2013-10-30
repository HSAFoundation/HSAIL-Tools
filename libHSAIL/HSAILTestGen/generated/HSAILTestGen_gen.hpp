
namespace HSAIL_ASM {

class PropDescImpl : public PropValidator
{
public:
    static const unsigned* getPropVals(unsigned propId, unsigned& num); // should include XXX_VAL_INVALID for invalid values (non-brig only)
    static bool isBrigProp(unsigned propId);

public:
    static       unsigned  getFormat(unsigned opcode);
    static const unsigned* getOpcodes(unsigned& num);
    static const unsigned* getProps(unsigned opcode, unsigned& prm, unsigned& sec);
    static const unsigned* getPropVals(unsigned opcode, unsigned propId, unsigned& num);

public:
    static bool isValidProp(Inst inst, unsigned propId);
    static bool validatePrimaryProps(Inst inst);
    static bool isValidInst(Inst inst); // for debugging only

private:
    static unsigned OPCODES[];

private:
    static unsigned ALIGN_VALUES_ANY[];
    static unsigned ATMOP_VALUES_GENERIC_EXCH_LD[];
    static unsigned ATMOP_VALUES_GENERIC_EXCH[];
    static unsigned ATMOP_VALUES_GENERIC_ST[];
    static unsigned ATMOP_VALUES_GENERIC[];
    static unsigned ATMOP_VALUES_ADD_SUB_MIN_MAX[];
    static unsigned ATMOP_VALUES_AND_OR_XOR_EXCH[];
    static unsigned ATMOP_VALUES_AND_OR_XOR[];
    static unsigned ATMOP_VALUES_CAS[];
    static unsigned ATMOP_VALUES_INC_DEC[];
    static unsigned ATMOP_VALUES_LD[];
    static unsigned ATMOP_VALUES_ST[];
    static unsigned EQCLASS_VALUES_ANY[];
    static unsigned FTZ_VALUES_NONE[];
    static unsigned FTZ_VALUES_ANY[];
    static unsigned GEOM_VALUES_1D[];
    static unsigned GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA[];
    static unsigned GEOM_VALUES_1D_2D_3D_1DA_2DA[];
    static unsigned GEOM_VALUES_1D_1DB[];
    static unsigned GEOM_VALUES_2D_1DA[];
    static unsigned GEOM_VALUES_3D_2DA[];
    static unsigned MEMFNC_VALUES_ANY[];
    static unsigned MEMFNC_VALUES_NONE[];
    static unsigned MEMORD_VALUES_ANY[];
    static unsigned MEMORD_VALUES_LD[];
    static unsigned MEMORD_VALUES_NONE[];
    static unsigned MEMORD_VALUES_ST[];
    static unsigned MEMSCP_VALUES_ANY[];
    static unsigned MEMSCP_VALUES_NONE[];
    static unsigned OPERAND_VALUES_ADDRSEG[];
    static unsigned OPERAND_VALUES_ADDRTSEG[];
    static unsigned OPERAND_VALUES_ARGLIST[];
    static unsigned OPERAND_VALUES_NULL_CALLTAB[];
    static unsigned OPERAND_VALUES_FBARRIER[];
    static unsigned OPERAND_VALUES_REG32_FBARRIER[];
    static unsigned OPERAND_VALUES_FUNCMODEL[];
    static unsigned OPERAND_VALUES_LAB_FUNC[];
    static unsigned OPERAND_VALUES_REGMODEL_FUNCMODEL[];
    static unsigned OPERAND_VALUES_IMM[];
    static unsigned OPERAND_VALUES_REG_IMM[];
    static unsigned OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP[];
    static unsigned OPERAND_VALUES_IMM012[];
    static unsigned OPERAND_VALUES_IMM0123[];
    static unsigned OPERAND_VALUES_REG1_IMM1[];
    static unsigned OPERAND_VALUES_IMM32[];
    static unsigned OPERAND_VALUES_REG32_IMM32[];
    static unsigned OPERAND_VALUES_REG64_IMM64[];
    static unsigned OPERAND_VALUES_NULL_JUMPTAB[];
    static unsigned OPERAND_VALUES_LABMODEL[];
    static unsigned OPERAND_VALUES_REGMODEL_LABMODEL[];
    static unsigned OPERAND_VALUES_NULL[];
    static unsigned OPERAND_VALUES_REG[];
    static unsigned OPERAND_VALUES_REGEXP_REGVEXP[];
    static unsigned OPERAND_VALUES_REG1[];
    static unsigned OPERAND_VALUES_REG32[];
    static unsigned OPERAND_VALUES_REG64[];
    static unsigned OPERAND_VALUES_REG64_ROIMAGE[];
    static unsigned OPERAND_VALUES_REG64_IMAGE[];
    static unsigned OPERAND_VALUES_REG64_RWIMAGE[];
    static unsigned OPERAND_VALUES_REG64_SAMPLER[];
    static unsigned OPERAND_VALUES_REGV2CTYPE[];
    static unsigned OPERAND_VALUES_REGV3CTYPE[];
    static unsigned OPERAND_VALUES_REGV4[];
    static unsigned OPERAND_VALUES_REGV432[];
    static unsigned OPERATOR_VALUES_0[];
    static unsigned OPERATOR_VALUES_EQ_NE_LT_LE_GT_GE[];
    static unsigned OPERATOR_VALUES_EQ_NE[];
    static unsigned PACKING_VALUES_NONE[];
    static unsigned PACKING_VALUES_P_S[];
    static unsigned PACKING_VALUES_PP[];
    static unsigned PACKING_VALUES_BIN[];
    static unsigned PACKING_VALUES_BINNOSAT[];
    static unsigned ROUNDING_VALUES_FLOAT[];
    static unsigned ROUNDING_VALUES_INT[];
    static unsigned ROUNDING_VALUES_NONE[];
    static unsigned SEGMENT_VALUES_GCN[];
    static unsigned SEGMENT_VALUES_ANY[];
    static unsigned SEGMENT_VALUES_WRITABLE[];
    static unsigned SEGMENT_VALUES_STD[];
    static unsigned SEGMENT_VALUES_GLOBAL_GROUP_FLAT[];
    static unsigned SEGMENT_VALUES_GLOBAL[];
    static unsigned SEGMENT_VALUES_PRIVATE[];
    static unsigned STYPESIZE_VALUES_MODEL[];
    static unsigned STYPESIZE_VALUES_SEG[];
    static unsigned TYPE_VALUES_B1[];
    static unsigned TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_ROIMG_RWIMG_SAMP[];
    static unsigned TYPE_VALUES_B1_B32_B64[];
    static unsigned TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_X[];
    static unsigned TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F[];
    static unsigned TYPE_VALUES_B1_B32_B64_X[];
    static unsigned TYPE_VALUES_B1_S_U_F[];
    static unsigned TYPE_VALUES_B1_S16_U16_S32_U32_S64_U64_F[];
    static unsigned TYPE_VALUES_B1_S8_U8_S16_U16_S32_U32_F[];
    static unsigned TYPE_VALUES_B1_S8_U8_S16_U16_S64_U64_F[];
    static unsigned TYPE_VALUES_B1_S8_U8_S32_U32_S64_U64_F[];
    static unsigned TYPE_VALUES_B1_S32_U32_S64_U64_F_UX[];
    static unsigned TYPE_VALUES_B1_S32_U32_S64_U64_F[];
    static unsigned TYPE_VALUES_B1_S_U[];
    static unsigned TYPE_VALUES_U32_B1[];
    static unsigned TYPE_VALUES_B128[];
    static unsigned TYPE_VALUES_B64_B128[];
    static unsigned TYPE_VALUES_U_S_F_B128_ROIMG_RWIMG_SAMP[];
    static unsigned TYPE_VALUES_U_S_F_B128[];
    static unsigned TYPE_VALUES_B128_ROIMG_RWIMG_SAMP[];
    static unsigned TYPE_VALUES_B32[];
    static unsigned TYPE_VALUES_B32_B64[];
    static unsigned TYPE_VALUES_B32_S32_U32_B64_S64_U64[];
    static unsigned TYPE_VALUES_B64[];
    static unsigned TYPE_VALUES_F16[];
    static unsigned TYPE_VALUES_F_FX[];
    static unsigned TYPE_VALUES_S32_S64_SX_F_FX[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64_F_X[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64_F_FX[];
    static unsigned TYPE_VALUES_F16_F32[];
    static unsigned TYPE_VALUES_F[];
    static unsigned TYPE_VALUES_U_S_F[];
    static unsigned TYPE_VALUES_S32_S64_F[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64_F[];
    static unsigned TYPE_VALUES_F16X[];
    static unsigned TYPE_VALUES_FX[];
    static unsigned TYPE_VALUES_SX_FX[];
    static unsigned TYPE_VALUES_X[];
    static unsigned TYPE_VALUES_X32_X64[];
    static unsigned TYPE_VALUES_S16X2_U16X2_F16X2[];
    static unsigned TYPE_VALUES_S16X4_U16X4_F16X4[];
    static unsigned TYPE_VALUES_S16X8_U16X8_F16X8[];
    static unsigned TYPE_VALUES_F32[];
    static unsigned TYPE_VALUES_F32_F64[];
    static unsigned TYPE_VALUES_S32_F32[];
    static unsigned TYPE_VALUES_S32_U32_F32[];
    static unsigned TYPE_VALUES_F32X[];
    static unsigned TYPE_VALUES_S32X2_U32X2_F32X2[];
    static unsigned TYPE_VALUES_S32X4_U32X4_F32X4[];
    static unsigned TYPE_VALUES_F64[];
    static unsigned TYPE_VALUES_F64X[];
    static unsigned TYPE_VALUES_S64X2_U64X2_F64X2[];
    static unsigned TYPE_VALUES_NONE[];
    static unsigned TYPE_VALUES_ROIMG[];
    static unsigned TYPE_VALUES_ROIMG_RWIMG[];
    static unsigned TYPE_VALUES_RWIMG[];
    static unsigned TYPE_VALUES_S_U[];
    static unsigned TYPE_VALUES_S16_U16[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64_SX_UX[];
    static unsigned TYPE_VALUES_S8X_S16X_S32X_S64X[];
    static unsigned TYPE_VALUES_SX_UX[];
    static unsigned TYPE_VALUES_S8X_S16X_S32X[];
    static unsigned TYPE_VALUES_S32[];
    static unsigned TYPE_VALUES_S32_S64[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64[];
    static unsigned TYPE_VALUES_S32_U32[];
    static unsigned TYPE_VALUES_S64[];
    static unsigned TYPE_VALUES_S64_U64[];
    static unsigned TYPE_VALUES_S64X[];
    static unsigned TYPE_VALUES_S8_U8[];
    static unsigned TYPE_VALUES_S8X16_U8X16[];
    static unsigned TYPE_VALUES_S8X4_U8X4[];
    static unsigned TYPE_VALUES_S8X8_U8X8[];
    static unsigned TYPE_VALUES_SAMP[];
    static unsigned TYPE_VALUES_U16X2[];
    static unsigned TYPE_VALUES_U8X_U16X_U32X_U64X[];
    static unsigned TYPE_VALUES_U8X_U16X_U32X[];
    static unsigned TYPE_VALUES_U32_U8X4_U16X2[];
    static unsigned TYPE_VALUES_U16X4[];
    static unsigned TYPE_VALUES_U16X8[];
    static unsigned TYPE_VALUES_U32[];
    static unsigned TYPE_VALUES_U32_U64[];
    static unsigned TYPE_VALUES_U32X2[];
    static unsigned TYPE_VALUES_U32X4[];
    static unsigned TYPE_VALUES_U64[];
    static unsigned TYPE_VALUES_U64X[];
    static unsigned TYPE_VALUES_U8X16[];
    static unsigned TYPE_VALUES_U8X4[];
    static unsigned TYPE_VALUES_U8X8[];
    static unsigned TYPESIZE_VALUES_ATOMIC[];
    static unsigned TYPESIZE_VALUES_MODEL[];
    static unsigned TYPESIZE_VALUES_SEG[];
    static unsigned WIDTH_VALUES_ANY[];
    static unsigned WIDTH_VALUES_ALL[];
    static unsigned WIDTH_VALUES_NONE[];

private:
    static bool check_align_values_any(unsigned val);
    static bool check_atmop_values_generic_exch_ld(unsigned val);
    static bool check_atmop_values_generic_exch(unsigned val);
    static bool check_atmop_values_generic_st(unsigned val);
    static bool check_atmop_values_generic(unsigned val);
    static bool check_atmop_values_add_sub_min_max(unsigned val);
    static bool check_atmop_values_and_or_xor_exch(unsigned val);
    static bool check_atmop_values_and_or_xor(unsigned val);
    static bool check_atmop_values_cas(unsigned val);
    static bool check_atmop_values_inc_dec(unsigned val);
    static bool check_atmop_values_ld(unsigned val);
    static bool check_atmop_values_st(unsigned val);
    static bool check_ftz_values_none(unsigned val);
    static bool check_ftz_values_any(unsigned val);
    static bool check_geom_values_1d(unsigned val);
    static bool check_geom_values_1d_2d_3d_1db_1da_2da(unsigned val);
    static bool check_geom_values_1d_2d_3d_1da_2da(unsigned val);
    static bool check_geom_values_1d_1db(unsigned val);
    static bool check_geom_values_2d_1da(unsigned val);
    static bool check_geom_values_3d_2da(unsigned val);
    static bool check_memfnc_values_any(unsigned val);
    static bool check_memfnc_values_none(unsigned val);
    static bool check_memord_values_any(unsigned val);
    static bool check_memord_values_ld(unsigned val);
    static bool check_memord_values_none(unsigned val);
    static bool check_memord_values_st(unsigned val);
    static bool check_memscp_values_any(unsigned val);
    static bool check_memscp_values_none(unsigned val);
    static bool check_operator_values_0(unsigned val);
    static bool check_operator_values_eq_ne_lt_le_gt_ge(unsigned val);
    static bool check_operator_values_eq_ne(unsigned val);
    static bool check_packing_values_none(unsigned val);
    static bool check_packing_values_p_s(unsigned val);
    static bool check_packing_values_pp(unsigned val);
    static bool check_packing_values_bin(unsigned val);
    static bool check_packing_values_binnosat(unsigned val);
    static bool check_rounding_values_float(unsigned val);
    static bool check_rounding_values_int(unsigned val);
    static bool check_rounding_values_none(unsigned val);
    static bool check_segment_values_gcn(unsigned val);
    static bool check_segment_values_any(unsigned val);
    static bool check_segment_values_writable(unsigned val);
    static bool check_segment_values_std(unsigned val);
    static bool check_segment_values_global_group_flat(unsigned val);
    static bool check_segment_values_global(unsigned val);
    static bool check_segment_values_private(unsigned val);
    static bool check_type_values_b1(unsigned val);
    static bool check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_roimg_rwimg_samp(unsigned val);
    static bool check_type_values_b1_b32_b64(unsigned val);
    static bool check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(unsigned val);
    static bool check_type_values_b1_b32_s32_u32_b64_s64_u64_f(unsigned val);
    static bool check_type_values_b1_b32_b64_x(unsigned val);
    static bool check_type_values_b1_s_u_f(unsigned val);
    static bool check_type_values_b1_s16_u16_s32_u32_s64_u64_f(unsigned val);
    static bool check_type_values_b1_s8_u8_s16_u16_s32_u32_f(unsigned val);
    static bool check_type_values_b1_s8_u8_s16_u16_s64_u64_f(unsigned val);
    static bool check_type_values_b1_s8_u8_s32_u32_s64_u64_f(unsigned val);
    static bool check_type_values_b1_s32_u32_s64_u64_f_ux(unsigned val);
    static bool check_type_values_b1_s32_u32_s64_u64_f(unsigned val);
    static bool check_type_values_b1_s_u(unsigned val);
    static bool check_type_values_u32_b1(unsigned val);
    static bool check_type_values_b128(unsigned val);
    static bool check_type_values_b64_b128(unsigned val);
    static bool check_type_values_u_s_f_b128_roimg_rwimg_samp(unsigned val);
    static bool check_type_values_u_s_f_b128(unsigned val);
    static bool check_type_values_b128_roimg_rwimg_samp(unsigned val);
    static bool check_type_values_b32(unsigned val);
    static bool check_type_values_b32_b64(unsigned val);
    static bool check_type_values_b32_s32_u32_b64_s64_u64(unsigned val);
    static bool check_type_values_b64(unsigned val);
    static bool check_type_values_f16(unsigned val);
    static bool check_type_values_f_fx(unsigned val);
    static bool check_type_values_s32_s64_sx_f_fx(unsigned val);
    static bool check_type_values_s32_u32_s64_u64_f_x(unsigned val);
    static bool check_type_values_s32_u32_s64_u64_f_fx(unsigned val);
    static bool check_type_values_f16_f32(unsigned val);
    static bool check_type_values_f(unsigned val);
    static bool check_type_values_u_s_f(unsigned val);
    static bool check_type_values_s32_s64_f(unsigned val);
    static bool check_type_values_s32_u32_s64_u64_f(unsigned val);
    static bool check_type_values_f16x(unsigned val);
    static bool check_type_values_fx(unsigned val);
    static bool check_type_values_sx_fx(unsigned val);
    static bool check_type_values_x(unsigned val);
    static bool check_type_values_x32_x64(unsigned val);
    static bool check_type_values_s16x2_u16x2_f16x2(unsigned val);
    static bool check_type_values_s16x4_u16x4_f16x4(unsigned val);
    static bool check_type_values_s16x8_u16x8_f16x8(unsigned val);
    static bool check_type_values_f32(unsigned val);
    static bool check_type_values_f32_f64(unsigned val);
    static bool check_type_values_s32_f32(unsigned val);
    static bool check_type_values_s32_u32_f32(unsigned val);
    static bool check_type_values_f32x(unsigned val);
    static bool check_type_values_s32x2_u32x2_f32x2(unsigned val);
    static bool check_type_values_s32x4_u32x4_f32x4(unsigned val);
    static bool check_type_values_f64(unsigned val);
    static bool check_type_values_f64x(unsigned val);
    static bool check_type_values_s64x2_u64x2_f64x2(unsigned val);
    static bool check_type_values_none(unsigned val);
    static bool check_type_values_roimg(unsigned val);
    static bool check_type_values_roimg_rwimg(unsigned val);
    static bool check_type_values_rwimg(unsigned val);
    static bool check_type_values_s_u(unsigned val);
    static bool check_type_values_s16_u16(unsigned val);
    static bool check_type_values_s32_u32_s64_u64_sx_ux(unsigned val);
    static bool check_type_values_s8x_s16x_s32x_s64x(unsigned val);
    static bool check_type_values_sx_ux(unsigned val);
    static bool check_type_values_s8x_s16x_s32x(unsigned val);
    static bool check_type_values_s32(unsigned val);
    static bool check_type_values_s32_s64(unsigned val);
    static bool check_type_values_s32_u32_s64_u64(unsigned val);
    static bool check_type_values_s32_u32(unsigned val);
    static bool check_type_values_s64(unsigned val);
    static bool check_type_values_s64_u64(unsigned val);
    static bool check_type_values_s64x(unsigned val);
    static bool check_type_values_s8_u8(unsigned val);
    static bool check_type_values_s8x16_u8x16(unsigned val);
    static bool check_type_values_s8x4_u8x4(unsigned val);
    static bool check_type_values_s8x8_u8x8(unsigned val);
    static bool check_type_values_samp(unsigned val);
    static bool check_type_values_u16x2(unsigned val);
    static bool check_type_values_u8x_u16x_u32x_u64x(unsigned val);
    static bool check_type_values_u8x_u16x_u32x(unsigned val);
    static bool check_type_values_u32_u8x4_u16x2(unsigned val);
    static bool check_type_values_u16x4(unsigned val);
    static bool check_type_values_u16x8(unsigned val);
    static bool check_type_values_u32(unsigned val);
    static bool check_type_values_u32_u64(unsigned val);
    static bool check_type_values_u32x2(unsigned val);
    static bool check_type_values_u32x4(unsigned val);
    static bool check_type_values_u64(unsigned val);
    static bool check_type_values_u64x(unsigned val);
    static bool check_type_values_u8x16(unsigned val);
    static bool check_type_values_u8x4(unsigned val);
    static bool check_type_values_u8x8(unsigned val);
    static bool check_width_values_any(unsigned val);
    static bool check_width_values_all(unsigned val);
    static bool check_width_values_none(unsigned val);

private:
    static unsigned PROP_VALUES_WIDTH[];
    static unsigned PROP_VALUES_MEMSCP[];
    static unsigned PROP_VALUES_MEMORD[];
    static unsigned PROP_VALUES_GEOM[];
    static unsigned PROP_VALUES_ATMOP[];
    static unsigned PROP_VALUES_OPERAND[];
    static unsigned PROP_VALUES_SEGMENT[];
    static unsigned PROP_VALUES_OPERATOR[];
    static unsigned PROP_VALUES_TYPESIZE[];
    static unsigned PROP_VALUES_STYPESIZE[];
    static unsigned PROP_VALUES_PACKING[];
    static unsigned PROP_VALUES_ALIGN[];
    static unsigned PROP_VALUES_MEMFNC[];
    static unsigned PROP_VALUES_EQCLASS[];
    static unsigned PROP_VALUES_ROUNDING[];
    static unsigned PROP_VALUES_FTZ[];
    static unsigned PROP_VALUES_TYPE[];

private:
    static unsigned REQ_PROPS_NEG[];
    static unsigned REQ_PROPS_ADD[];
    static unsigned REQ_PROPS_ALLOCA[];
    static unsigned REQ_PROPS_AND[];
    static unsigned REQ_PROPS_FBAR_SYNC_WIDTH[];
    static unsigned REQ_PROPS_ATOMIC[];
    static unsigned REQ_PROPS_ATOMIC_IMAGE[];
    static unsigned REQ_PROPS_ATOMIC_NORET_IMAGE[];
    static unsigned REQ_PROPS_ATOMIC_NORET[];
    static unsigned REQ_PROPS_BARRIER[];
    static unsigned REQ_PROPS_ALIGN[];
    static unsigned REQ_PROPS_BITEXTRACT[];
    static unsigned REQ_PROPS_BITINSERT[];
    static unsigned REQ_PROPS_BITMASK[];
    static unsigned REQ_PROPS_BITREV[];
    static unsigned REQ_PROPS_BITSELECT[];
    static unsigned REQ_PROPS_REM[];
    static unsigned REQ_PROPS_BRN[];
    static unsigned REQ_PROPS_CALL[];
    static unsigned REQ_PROPS_CBR[];
    static unsigned REQ_PROPS_CEIL[];
    static unsigned REQ_PROPS_CLASS[];
    static unsigned REQ_PROPS_SPEC_EXCEPT[];
    static unsigned REQ_PROPS_SPEC_CLOCK[];
    static unsigned REQ_PROPS_CMOV[];
    static unsigned REQ_PROPS_CMP[];
    static unsigned REQ_PROPS_CODEBLOCKEND[];
    static unsigned REQ_PROPS_COMBINE[];
    static unsigned REQ_PROPS_COPYSIGN[];
    static unsigned REQ_PROPS_COUNTLANE[];
    static unsigned REQ_PROPS_COUNTUPLANE[];
    static unsigned REQ_PROPS_SPEC_REG[];
    static unsigned REQ_PROPS_SPEC_REG_DIM[];
    static unsigned REQ_PROPS_CVT[];
    static unsigned REQ_PROPS_DEBUGTRAP[];
    static unsigned REQ_PROPS_AQLPTR[];
    static unsigned REQ_PROPS_DIV[];
    static unsigned REQ_PROPS_EXPAND[];
    static unsigned REQ_PROPS_FIRSTBIT[];
    static unsigned REQ_PROPS_FMA[];
    static unsigned REQ_PROPS_FRACT[];
    static unsigned REQ_PROPS_F2S[];
    static unsigned REQ_PROPS_GCN_APPEND_CONSUME[];
    static unsigned REQ_PROPS_GCN_ATOMIC[];
    static unsigned REQ_PROPS_GCN_ATOMIC_NORET[];
    static unsigned REQ_PROPS_GCN_B4XCHG[];
    static unsigned REQ_PROPS_GCN_BFM[];
    static unsigned REQ_PROPS_GCN_FLDEXP[];
    static unsigned REQ_PROPS_GCN_FREXP_EXP[];
    static unsigned REQ_PROPS_GCN_FREXP_MANT[];
    static unsigned REQ_PROPS_GCN_LD[];
    static unsigned REQ_PROPS_GCN_MAD[];
    static unsigned REQ_PROPS_GCN_MIN_MAX_MED[];
    static unsigned REQ_PROPS_GCN_MQSAD[];
    static unsigned REQ_PROPS_GCN_MQSAD4[];
    static unsigned REQ_PROPS_GCN_MSAD[];
    static unsigned REQ_PROPS_GCN_SLP_PRT[];
    static unsigned REQ_PROPS_GCN_QSAD[];
    static unsigned REQ_PROPS_GCN_REGION_ALLOC[];
    static unsigned REQ_PROPS_GCN_ST[];
    static unsigned REQ_PROPS_GCN_TRIG_PREOP[];
    static unsigned REQ_PROPS_FBAR_NONE[];
    static unsigned REQ_PROPS_FBAR_WIDTH[];
    static unsigned REQ_PROPS_LD[];
    static unsigned REQ_PROPS_LDA[];
    static unsigned REQ_PROPS_LDC[];
    static unsigned REQ_PROPS_LDF[];
    static unsigned REQ_PROPS_LD_IMAGE[];
    static unsigned REQ_PROPS_LERP[];
    static unsigned REQ_PROPS_MAD[];
    static unsigned REQ_PROPS_MAD24[];
    static unsigned REQ_PROPS_MASKLANE[];
    static unsigned REQ_PROPS_MAX[];
    static unsigned REQ_PROPS_MOV[];
    static unsigned REQ_PROPS_MUL[];
    static unsigned REQ_PROPS_MUL24[];
    static unsigned REQ_PROPS_MULHI[];
    static unsigned REQ_PROPS_TRIG32[];
    static unsigned REQ_PROPS_NFMA[];
    static unsigned REQ_PROPS_NOP[];
    static unsigned REQ_PROPS_NOT[];
    static unsigned REQ_PROPS_TRIG[];
    static unsigned REQ_PROPS_NULLPTR[];
    static unsigned REQ_PROPS_PACK[];
    static unsigned REQ_PROPS_PACKCVT[];
    static unsigned REQ_PROPS_POPCOUNT[];
    static unsigned REQ_PROPS_QUERYIMAGE[];
    static unsigned REQ_PROPS_QUERYSAMPLERBOUNDARY[];
    static unsigned REQ_PROPS_QUERYSAMPLER[];
    static unsigned REQ_PROPS_RDIMAGE[];
    static unsigned REQ_PROPS_SENDLANE[];
    static unsigned REQ_PROPS_RET[];
    static unsigned REQ_PROPS_SAD[];
    static unsigned REQ_PROPS_SADHI[];
    static unsigned REQ_PROPS_SEGMENTP[];
    static unsigned REQ_PROPS_SHIFT[];
    static unsigned REQ_PROPS_SHUFFLE[];
    static unsigned REQ_PROPS_SQRT[];
    static unsigned REQ_PROPS_ST[];
    static unsigned REQ_PROPS_ST_IMAGE[];
    static unsigned REQ_PROPS_S2F[];
    static unsigned REQ_PROPS_SYNC[];
    static unsigned REQ_PROPS_SYSCALL[];
    static unsigned REQ_PROPS_UNPACK[];
    static unsigned REQ_PROPS_UNPACKCVT[];
    static unsigned REQ_PROPS_UNPACKX[];

private:
    static unsigned REQ_PROP_VALUES_NEG__TYPE[];
    static unsigned REQ_PROP_VALUES_NEG__PACKING[];
    static unsigned REQ_PROP_VALUES_NEG__D0[];
    static unsigned REQ_PROP_VALUES_NEG__S1[];
    static unsigned REQ_PROP_VALUES_NEG__S2[];
    static unsigned REQ_PROP_VALUES_NEG__S3[];
    static unsigned REQ_PROP_VALUES_NEG__S4[];
    static unsigned REQ_PROP_VALUES_NEG__FTZ[];
    static unsigned REQ_PROP_VALUES_NEG__ROUNDING[];

    static unsigned REQ_PROP_VALUES_ADD__TYPE[];
    static unsigned REQ_PROP_VALUES_ADD__FTZ[];
    static unsigned REQ_PROP_VALUES_ADD__PACKING[];
    static unsigned REQ_PROP_VALUES_ADD__ROUNDING[];
    static unsigned REQ_PROP_VALUES_ADD__D0[];
    static unsigned REQ_PROP_VALUES_ADD__S1[];
    static unsigned REQ_PROP_VALUES_ADD__S2[];
    static unsigned REQ_PROP_VALUES_ADD__S3[];
    static unsigned REQ_PROP_VALUES_ADD__S4[];

    static unsigned REQ_PROP_VALUES_ALLOCA__STYPE[];
    static unsigned REQ_PROP_VALUES_ALLOCA__TYPE[];
    static unsigned REQ_PROP_VALUES_ALLOCA__SEGMENT[];
    static unsigned REQ_PROP_VALUES_ALLOCA__S0[];
    static unsigned REQ_PROP_VALUES_ALLOCA__S1[];
    static unsigned REQ_PROP_VALUES_ALLOCA__S2[];
    static unsigned REQ_PROP_VALUES_ALLOCA__S3[];
    static unsigned REQ_PROP_VALUES_ALLOCA__S4[];

    static unsigned REQ_PROP_VALUES_AND__TYPE[];
    static unsigned REQ_PROP_VALUES_AND__D0[];
    static unsigned REQ_PROP_VALUES_AND__S1[];
    static unsigned REQ_PROP_VALUES_AND__S2[];
    static unsigned REQ_PROP_VALUES_AND__S3[];
    static unsigned REQ_PROP_VALUES_AND__S4[];

    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__TYPE[];
    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S0[];
    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S1[];
    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S2[];
    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S3[];
    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S4[];
    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMFNC[];
    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMORD[];
    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMSCP[];
    static unsigned REQ_PROP_VALUES_FBAR_SYNC_WIDTH__WIDTH[];

    static unsigned REQ_PROP_VALUES_ATOMIC__TYPE[];
    static unsigned REQ_PROP_VALUES_ATOMIC__ATMOP[];
    static unsigned REQ_PROP_VALUES_ATOMIC__SEGMENT[];
    static unsigned REQ_PROP_VALUES_ATOMIC__MEMORD[];
    static unsigned REQ_PROP_VALUES_ATOMIC__S2[];
    static unsigned REQ_PROP_VALUES_ATOMIC__S3[];
    static unsigned REQ_PROP_VALUES_ATOMIC__D0[];
    static unsigned REQ_PROP_VALUES_ATOMIC__S1[];
    static unsigned REQ_PROP_VALUES_ATOMIC__S4[];
    static unsigned REQ_PROP_VALUES_ATOMIC__MEMSCP[];

    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__CTYPE[];
    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__TYPE[];
    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__ATMOP[];
    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__GEOM[];
    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__S2[];
    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__S4[];
    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__D0[];
    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__S1[];
    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__S3[];
    static unsigned REQ_PROP_VALUES_ATOMIC_IMAGE__ITYPE[];

    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__CTYPE[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__TYPE[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__ATMOP[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__GEOM[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S1[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S3[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S0[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S2[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S4[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__ITYPE[];

    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__TYPE[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__ATMOP[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__SEGMENT[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__MEMORD[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__S2[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__S0[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__S1[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__S3[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__S4[];
    static unsigned REQ_PROP_VALUES_ATOMIC_NORET__MEMSCP[];

    static unsigned REQ_PROP_VALUES_BARRIER__TYPE[];
    static unsigned REQ_PROP_VALUES_BARRIER__S0[];
    static unsigned REQ_PROP_VALUES_BARRIER__S1[];
    static unsigned REQ_PROP_VALUES_BARRIER__S2[];
    static unsigned REQ_PROP_VALUES_BARRIER__S3[];
    static unsigned REQ_PROP_VALUES_BARRIER__S4[];
    static unsigned REQ_PROP_VALUES_BARRIER__MEMFNC[];
    static unsigned REQ_PROP_VALUES_BARRIER__MEMORD[];
    static unsigned REQ_PROP_VALUES_BARRIER__MEMSCP[];
    static unsigned REQ_PROP_VALUES_BARRIER__WIDTH[];

    static unsigned REQ_PROP_VALUES_ALIGN__TYPE[];
    static unsigned REQ_PROP_VALUES_ALIGN__D0[];
    static unsigned REQ_PROP_VALUES_ALIGN__S1[];
    static unsigned REQ_PROP_VALUES_ALIGN__S2[];
    static unsigned REQ_PROP_VALUES_ALIGN__S3[];
    static unsigned REQ_PROP_VALUES_ALIGN__S4[];

    static unsigned REQ_PROP_VALUES_BITEXTRACT__TYPE[];
    static unsigned REQ_PROP_VALUES_BITEXTRACT__D0[];
    static unsigned REQ_PROP_VALUES_BITEXTRACT__S1[];
    static unsigned REQ_PROP_VALUES_BITEXTRACT__S2[];
    static unsigned REQ_PROP_VALUES_BITEXTRACT__S3[];
    static unsigned REQ_PROP_VALUES_BITEXTRACT__S4[];

    static unsigned REQ_PROP_VALUES_BITINSERT__TYPE[];
    static unsigned REQ_PROP_VALUES_BITINSERT__D0[];
    static unsigned REQ_PROP_VALUES_BITINSERT__S1[];
    static unsigned REQ_PROP_VALUES_BITINSERT__S2[];
    static unsigned REQ_PROP_VALUES_BITINSERT__S3[];
    static unsigned REQ_PROP_VALUES_BITINSERT__S4[];

    static unsigned REQ_PROP_VALUES_BITMASK__TYPE[];
    static unsigned REQ_PROP_VALUES_BITMASK__D0[];
    static unsigned REQ_PROP_VALUES_BITMASK__S1[];
    static unsigned REQ_PROP_VALUES_BITMASK__S2[];
    static unsigned REQ_PROP_VALUES_BITMASK__S3[];
    static unsigned REQ_PROP_VALUES_BITMASK__S4[];

    static unsigned REQ_PROP_VALUES_BITREV__TYPE[];
    static unsigned REQ_PROP_VALUES_BITREV__D0[];
    static unsigned REQ_PROP_VALUES_BITREV__S1[];
    static unsigned REQ_PROP_VALUES_BITREV__S2[];
    static unsigned REQ_PROP_VALUES_BITREV__S3[];
    static unsigned REQ_PROP_VALUES_BITREV__S4[];

    static unsigned REQ_PROP_VALUES_BITSELECT__TYPE[];
    static unsigned REQ_PROP_VALUES_BITSELECT__D0[];
    static unsigned REQ_PROP_VALUES_BITSELECT__S1[];
    static unsigned REQ_PROP_VALUES_BITSELECT__S2[];
    static unsigned REQ_PROP_VALUES_BITSELECT__S3[];
    static unsigned REQ_PROP_VALUES_BITSELECT__S4[];

    static unsigned REQ_PROP_VALUES_REM__TYPE[];
    static unsigned REQ_PROP_VALUES_REM__D0[];
    static unsigned REQ_PROP_VALUES_REM__S1[];
    static unsigned REQ_PROP_VALUES_REM__S2[];
    static unsigned REQ_PROP_VALUES_REM__S3[];
    static unsigned REQ_PROP_VALUES_REM__S4[];

    static unsigned REQ_PROP_VALUES_BRN__TYPE[];
    static unsigned REQ_PROP_VALUES_BRN__S0[];
    static unsigned REQ_PROP_VALUES_BRN__S1[];
    static unsigned REQ_PROP_VALUES_BRN__WIDTH[];
    static unsigned REQ_PROP_VALUES_BRN__S2[];
    static unsigned REQ_PROP_VALUES_BRN__S3[];
    static unsigned REQ_PROP_VALUES_BRN__S4[];

    static unsigned REQ_PROP_VALUES_CALL__TYPE[];
    static unsigned REQ_PROP_VALUES_CALL__S1[];
    static unsigned REQ_PROP_VALUES_CALL__S3[];
    static unsigned REQ_PROP_VALUES_CALL__WIDTH[];
    static unsigned REQ_PROP_VALUES_CALL__S0[];
    static unsigned REQ_PROP_VALUES_CALL__S2[];
    static unsigned REQ_PROP_VALUES_CALL__S4[];

    static unsigned REQ_PROP_VALUES_CBR__TYPE[];
    static unsigned REQ_PROP_VALUES_CBR__S1[];
    static unsigned REQ_PROP_VALUES_CBR__S2[];
    static unsigned REQ_PROP_VALUES_CBR__S0[];
    static unsigned REQ_PROP_VALUES_CBR__S3[];
    static unsigned REQ_PROP_VALUES_CBR__S4[];
    static unsigned REQ_PROP_VALUES_CBR__WIDTH[];

    static unsigned REQ_PROP_VALUES_CEIL__TYPE[];
    static unsigned REQ_PROP_VALUES_CEIL__PACKING[];
    static unsigned REQ_PROP_VALUES_CEIL__D0[];
    static unsigned REQ_PROP_VALUES_CEIL__S1[];
    static unsigned REQ_PROP_VALUES_CEIL__S2[];
    static unsigned REQ_PROP_VALUES_CEIL__S3[];
    static unsigned REQ_PROP_VALUES_CEIL__S4[];
    static unsigned REQ_PROP_VALUES_CEIL__FTZ[];
    static unsigned REQ_PROP_VALUES_CEIL__ROUNDING[];

    static unsigned REQ_PROP_VALUES_CLASS__STYPE[];
    static unsigned REQ_PROP_VALUES_CLASS__TYPE[];
    static unsigned REQ_PROP_VALUES_CLASS__D0[];
    static unsigned REQ_PROP_VALUES_CLASS__S1[];
    static unsigned REQ_PROP_VALUES_CLASS__S2[];
    static unsigned REQ_PROP_VALUES_CLASS__S3[];
    static unsigned REQ_PROP_VALUES_CLASS__S4[];

    static unsigned REQ_PROP_VALUES_SPEC_EXCEPT__TYPE[];
    static unsigned REQ_PROP_VALUES_SPEC_EXCEPT__S0[];
    static unsigned REQ_PROP_VALUES_SPEC_EXCEPT__S1[];
    static unsigned REQ_PROP_VALUES_SPEC_EXCEPT__S2[];
    static unsigned REQ_PROP_VALUES_SPEC_EXCEPT__S3[];
    static unsigned REQ_PROP_VALUES_SPEC_EXCEPT__S4[];

    static unsigned REQ_PROP_VALUES_SPEC_CLOCK__TYPE[];
    static unsigned REQ_PROP_VALUES_SPEC_CLOCK__D0[];
    static unsigned REQ_PROP_VALUES_SPEC_CLOCK__S1[];
    static unsigned REQ_PROP_VALUES_SPEC_CLOCK__S2[];
    static unsigned REQ_PROP_VALUES_SPEC_CLOCK__S3[];
    static unsigned REQ_PROP_VALUES_SPEC_CLOCK__S4[];

    static unsigned REQ_PROP_VALUES_CMOV__TYPE[];
    static unsigned REQ_PROP_VALUES_CMOV__S1[];
    static unsigned REQ_PROP_VALUES_CMOV__D0[];
    static unsigned REQ_PROP_VALUES_CMOV__S2[];
    static unsigned REQ_PROP_VALUES_CMOV__S3[];
    static unsigned REQ_PROP_VALUES_CMOV__S4[];

    static unsigned REQ_PROP_VALUES_CMP__STYPE[];
    static unsigned REQ_PROP_VALUES_CMP__TYPE[];
    static unsigned REQ_PROP_VALUES_CMP__FTZ[];
    static unsigned REQ_PROP_VALUES_CMP__OPERATOR[];
    static unsigned REQ_PROP_VALUES_CMP__PACKING[];
    static unsigned REQ_PROP_VALUES_CMP__D0[];
    static unsigned REQ_PROP_VALUES_CMP__S1[];
    static unsigned REQ_PROP_VALUES_CMP__S2[];
    static unsigned REQ_PROP_VALUES_CMP__S3[];
    static unsigned REQ_PROP_VALUES_CMP__S4[];
    static unsigned REQ_PROP_VALUES_CMP__ROUNDING[];

    static unsigned REQ_PROP_VALUES_CODEBLOCKEND__TYPE[];
    static unsigned REQ_PROP_VALUES_CODEBLOCKEND__S0[];
    static unsigned REQ_PROP_VALUES_CODEBLOCKEND__S1[];
    static unsigned REQ_PROP_VALUES_CODEBLOCKEND__S2[];
    static unsigned REQ_PROP_VALUES_CODEBLOCKEND__S3[];
    static unsigned REQ_PROP_VALUES_CODEBLOCKEND__S4[];

    static unsigned REQ_PROP_VALUES_COMBINE__STYPE[];
    static unsigned REQ_PROP_VALUES_COMBINE__TYPE[];
    static unsigned REQ_PROP_VALUES_COMBINE__S1[];
    static unsigned REQ_PROP_VALUES_COMBINE__D0[];
    static unsigned REQ_PROP_VALUES_COMBINE__S2[];
    static unsigned REQ_PROP_VALUES_COMBINE__S3[];
    static unsigned REQ_PROP_VALUES_COMBINE__S4[];

    static unsigned REQ_PROP_VALUES_COPYSIGN__TYPE[];
    static unsigned REQ_PROP_VALUES_COPYSIGN__PACKING[];
    static unsigned REQ_PROP_VALUES_COPYSIGN__D0[];
    static unsigned REQ_PROP_VALUES_COPYSIGN__S1[];
    static unsigned REQ_PROP_VALUES_COPYSIGN__S2[];
    static unsigned REQ_PROP_VALUES_COPYSIGN__S3[];
    static unsigned REQ_PROP_VALUES_COPYSIGN__S4[];
    static unsigned REQ_PROP_VALUES_COPYSIGN__FTZ[];
    static unsigned REQ_PROP_VALUES_COPYSIGN__ROUNDING[];

    static unsigned REQ_PROP_VALUES_COUNTLANE__STYPE[];
    static unsigned REQ_PROP_VALUES_COUNTLANE__TYPE[];
    static unsigned REQ_PROP_VALUES_COUNTLANE__D0[];
    static unsigned REQ_PROP_VALUES_COUNTLANE__S1[];
    static unsigned REQ_PROP_VALUES_COUNTLANE__S2[];
    static unsigned REQ_PROP_VALUES_COUNTLANE__S3[];
    static unsigned REQ_PROP_VALUES_COUNTLANE__S4[];
    static unsigned REQ_PROP_VALUES_COUNTLANE__WIDTH[];

    static unsigned REQ_PROP_VALUES_COUNTUPLANE__STYPE[];
    static unsigned REQ_PROP_VALUES_COUNTUPLANE__TYPE[];
    static unsigned REQ_PROP_VALUES_COUNTUPLANE__D0[];
    static unsigned REQ_PROP_VALUES_COUNTUPLANE__S1[];
    static unsigned REQ_PROP_VALUES_COUNTUPLANE__S2[];
    static unsigned REQ_PROP_VALUES_COUNTUPLANE__S3[];
    static unsigned REQ_PROP_VALUES_COUNTUPLANE__S4[];
    static unsigned REQ_PROP_VALUES_COUNTUPLANE__WIDTH[];

    static unsigned REQ_PROP_VALUES_SPEC_REG__TYPE[];
    static unsigned REQ_PROP_VALUES_SPEC_REG__D0[];
    static unsigned REQ_PROP_VALUES_SPEC_REG__S1[];
    static unsigned REQ_PROP_VALUES_SPEC_REG__S2[];
    static unsigned REQ_PROP_VALUES_SPEC_REG__S3[];
    static unsigned REQ_PROP_VALUES_SPEC_REG__S4[];

    static unsigned REQ_PROP_VALUES_SPEC_REG_DIM__TYPE[];
    static unsigned REQ_PROP_VALUES_SPEC_REG_DIM__D0[];
    static unsigned REQ_PROP_VALUES_SPEC_REG_DIM__S1[];
    static unsigned REQ_PROP_VALUES_SPEC_REG_DIM__S2[];
    static unsigned REQ_PROP_VALUES_SPEC_REG_DIM__S3[];
    static unsigned REQ_PROP_VALUES_SPEC_REG_DIM__S4[];

    static unsigned REQ_PROP_VALUES_CVT__STYPE[];
    static unsigned REQ_PROP_VALUES_CVT__TYPE[];
    static unsigned REQ_PROP_VALUES_CVT__FTZ[];
    static unsigned REQ_PROP_VALUES_CVT__ROUNDING[];
    static unsigned REQ_PROP_VALUES_CVT__D0[];
    static unsigned REQ_PROP_VALUES_CVT__S1[];
    static unsigned REQ_PROP_VALUES_CVT__S2[];
    static unsigned REQ_PROP_VALUES_CVT__S3[];
    static unsigned REQ_PROP_VALUES_CVT__S4[];

    static unsigned REQ_PROP_VALUES_DEBUGTRAP__TYPE[];
    static unsigned REQ_PROP_VALUES_DEBUGTRAP__S0[];
    static unsigned REQ_PROP_VALUES_DEBUGTRAP__S1[];
    static unsigned REQ_PROP_VALUES_DEBUGTRAP__S2[];
    static unsigned REQ_PROP_VALUES_DEBUGTRAP__S3[];
    static unsigned REQ_PROP_VALUES_DEBUGTRAP__S4[];

    static unsigned REQ_PROP_VALUES_AQLPTR__STYPE[];
    static unsigned REQ_PROP_VALUES_AQLPTR__TYPE[];
    static unsigned REQ_PROP_VALUES_AQLPTR__SEGMENT[];
    static unsigned REQ_PROP_VALUES_AQLPTR__S0[];
    static unsigned REQ_PROP_VALUES_AQLPTR__S1[];
    static unsigned REQ_PROP_VALUES_AQLPTR__S2[];
    static unsigned REQ_PROP_VALUES_AQLPTR__S3[];
    static unsigned REQ_PROP_VALUES_AQLPTR__S4[];

    static unsigned REQ_PROP_VALUES_DIV__TYPE[];
    static unsigned REQ_PROP_VALUES_DIV__FTZ[];
    static unsigned REQ_PROP_VALUES_DIV__PACKING[];
    static unsigned REQ_PROP_VALUES_DIV__ROUNDING[];
    static unsigned REQ_PROP_VALUES_DIV__D0[];
    static unsigned REQ_PROP_VALUES_DIV__S1[];
    static unsigned REQ_PROP_VALUES_DIV__S2[];
    static unsigned REQ_PROP_VALUES_DIV__S3[];
    static unsigned REQ_PROP_VALUES_DIV__S4[];

    static unsigned REQ_PROP_VALUES_EXPAND__STYPE[];
    static unsigned REQ_PROP_VALUES_EXPAND__TYPE[];
    static unsigned REQ_PROP_VALUES_EXPAND__D0[];
    static unsigned REQ_PROP_VALUES_EXPAND__S1[];
    static unsigned REQ_PROP_VALUES_EXPAND__S2[];
    static unsigned REQ_PROP_VALUES_EXPAND__S3[];
    static unsigned REQ_PROP_VALUES_EXPAND__S4[];

    static unsigned REQ_PROP_VALUES_FIRSTBIT__STYPE[];
    static unsigned REQ_PROP_VALUES_FIRSTBIT__TYPE[];
    static unsigned REQ_PROP_VALUES_FIRSTBIT__D0[];
    static unsigned REQ_PROP_VALUES_FIRSTBIT__S1[];
    static unsigned REQ_PROP_VALUES_FIRSTBIT__S2[];
    static unsigned REQ_PROP_VALUES_FIRSTBIT__S3[];
    static unsigned REQ_PROP_VALUES_FIRSTBIT__S4[];

    static unsigned REQ_PROP_VALUES_FMA__TYPE[];
    static unsigned REQ_PROP_VALUES_FMA__D0[];
    static unsigned REQ_PROP_VALUES_FMA__S1[];
    static unsigned REQ_PROP_VALUES_FMA__S2[];
    static unsigned REQ_PROP_VALUES_FMA__S3[];
    static unsigned REQ_PROP_VALUES_FMA__S4[];
    static unsigned REQ_PROP_VALUES_FMA__FTZ[];
    static unsigned REQ_PROP_VALUES_FMA__PACKING[];
    static unsigned REQ_PROP_VALUES_FMA__ROUNDING[];

    static unsigned REQ_PROP_VALUES_FRACT__TYPE[];
    static unsigned REQ_PROP_VALUES_FRACT__PACKING[];
    static unsigned REQ_PROP_VALUES_FRACT__D0[];
    static unsigned REQ_PROP_VALUES_FRACT__S1[];
    static unsigned REQ_PROP_VALUES_FRACT__S2[];
    static unsigned REQ_PROP_VALUES_FRACT__S3[];
    static unsigned REQ_PROP_VALUES_FRACT__S4[];
    static unsigned REQ_PROP_VALUES_FRACT__FTZ[];
    static unsigned REQ_PROP_VALUES_FRACT__ROUNDING[];

    static unsigned REQ_PROP_VALUES_F2S__STYPE[];
    static unsigned REQ_PROP_VALUES_F2S__TYPE[];
    static unsigned REQ_PROP_VALUES_F2S__SEGMENT[];
    static unsigned REQ_PROP_VALUES_F2S__D0[];
    static unsigned REQ_PROP_VALUES_F2S__S1[];
    static unsigned REQ_PROP_VALUES_F2S__S2[];
    static unsigned REQ_PROP_VALUES_F2S__S3[];
    static unsigned REQ_PROP_VALUES_F2S__S4[];

    static unsigned REQ_PROP_VALUES_GCN_APPEND_CONSUME__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_APPEND_CONSUME__SEGMENT[];
    static unsigned REQ_PROP_VALUES_GCN_APPEND_CONSUME__D0[];
    static unsigned REQ_PROP_VALUES_GCN_APPEND_CONSUME__S1[];
    static unsigned REQ_PROP_VALUES_GCN_APPEND_CONSUME__S2[];
    static unsigned REQ_PROP_VALUES_GCN_APPEND_CONSUME__S3[];
    static unsigned REQ_PROP_VALUES_GCN_APPEND_CONSUME__S4[];

    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__ATMOP[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__SEGMENT[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__MEMORD[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__S2[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__S3[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__D0[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__S1[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__S4[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC__MEMSCP[];

    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__ATMOP[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__SEGMENT[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__MEMORD[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__S2[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__S0[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__S1[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__S3[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__S4[];
    static unsigned REQ_PROP_VALUES_GCN_ATOMIC_NORET__MEMSCP[];

    static unsigned REQ_PROP_VALUES_GCN_B4XCHG__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_B4XCHG__D0[];
    static unsigned REQ_PROP_VALUES_GCN_B4XCHG__S1[];
    static unsigned REQ_PROP_VALUES_GCN_B4XCHG__S2[];
    static unsigned REQ_PROP_VALUES_GCN_B4XCHG__S3[];
    static unsigned REQ_PROP_VALUES_GCN_B4XCHG__S4[];

    static unsigned REQ_PROP_VALUES_GCN_BFM__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_BFM__D0[];
    static unsigned REQ_PROP_VALUES_GCN_BFM__S1[];
    static unsigned REQ_PROP_VALUES_GCN_BFM__S2[];
    static unsigned REQ_PROP_VALUES_GCN_BFM__S3[];
    static unsigned REQ_PROP_VALUES_GCN_BFM__S4[];

    static unsigned REQ_PROP_VALUES_GCN_FLDEXP__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_FLDEXP__D0[];
    static unsigned REQ_PROP_VALUES_GCN_FLDEXP__S1[];
    static unsigned REQ_PROP_VALUES_GCN_FLDEXP__S2[];
    static unsigned REQ_PROP_VALUES_GCN_FLDEXP__S3[];
    static unsigned REQ_PROP_VALUES_GCN_FLDEXP__S4[];

    static unsigned REQ_PROP_VALUES_GCN_FREXP_EXP__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_EXP__D0[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_EXP__S1[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_EXP__S2[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_EXP__S3[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_EXP__S4[];

    static unsigned REQ_PROP_VALUES_GCN_FREXP_MANT__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_MANT__D0[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_MANT__S1[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_MANT__S2[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_MANT__S3[];
    static unsigned REQ_PROP_VALUES_GCN_FREXP_MANT__S4[];

    static unsigned REQ_PROP_VALUES_GCN_LD__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_LD__SEGMENT[];
    static unsigned REQ_PROP_VALUES_GCN_LD__D0[];
    static unsigned REQ_PROP_VALUES_GCN_LD__S1[];
    static unsigned REQ_PROP_VALUES_GCN_LD__S2[];
    static unsigned REQ_PROP_VALUES_GCN_LD__S3[];
    static unsigned REQ_PROP_VALUES_GCN_LD__S4[];
    static unsigned REQ_PROP_VALUES_GCN_LD__ALIGN[];
    static unsigned REQ_PROP_VALUES_GCN_LD__EQCLASS[];
    static unsigned REQ_PROP_VALUES_GCN_LD__WIDTH[];

    static unsigned REQ_PROP_VALUES_GCN_MAD__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_MAD__D0[];
    static unsigned REQ_PROP_VALUES_GCN_MAD__S1[];
    static unsigned REQ_PROP_VALUES_GCN_MAD__S2[];
    static unsigned REQ_PROP_VALUES_GCN_MAD__S3[];
    static unsigned REQ_PROP_VALUES_GCN_MAD__S4[];

    static unsigned REQ_PROP_VALUES_GCN_MIN_MAX_MED__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_MIN_MAX_MED__D0[];
    static unsigned REQ_PROP_VALUES_GCN_MIN_MAX_MED__S1[];
    static unsigned REQ_PROP_VALUES_GCN_MIN_MAX_MED__S2[];
    static unsigned REQ_PROP_VALUES_GCN_MIN_MAX_MED__S3[];
    static unsigned REQ_PROP_VALUES_GCN_MIN_MAX_MED__S4[];

    static unsigned REQ_PROP_VALUES_GCN_MQSAD__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD__D0[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD__S1[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD__S2[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD__S3[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD__S4[];

    static unsigned REQ_PROP_VALUES_GCN_MQSAD4__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD4__D0[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD4__S1[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD4__S2[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD4__S3[];
    static unsigned REQ_PROP_VALUES_GCN_MQSAD4__S4[];

    static unsigned REQ_PROP_VALUES_GCN_MSAD__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_MSAD__D0[];
    static unsigned REQ_PROP_VALUES_GCN_MSAD__S1[];
    static unsigned REQ_PROP_VALUES_GCN_MSAD__S2[];
    static unsigned REQ_PROP_VALUES_GCN_MSAD__S3[];
    static unsigned REQ_PROP_VALUES_GCN_MSAD__S4[];

    static unsigned REQ_PROP_VALUES_GCN_SLP_PRT__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_SLP_PRT__S0[];
    static unsigned REQ_PROP_VALUES_GCN_SLP_PRT__S1[];
    static unsigned REQ_PROP_VALUES_GCN_SLP_PRT__S2[];
    static unsigned REQ_PROP_VALUES_GCN_SLP_PRT__S3[];
    static unsigned REQ_PROP_VALUES_GCN_SLP_PRT__S4[];

    static unsigned REQ_PROP_VALUES_GCN_QSAD__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_QSAD__D0[];
    static unsigned REQ_PROP_VALUES_GCN_QSAD__S1[];
    static unsigned REQ_PROP_VALUES_GCN_QSAD__S2[];
    static unsigned REQ_PROP_VALUES_GCN_QSAD__S3[];
    static unsigned REQ_PROP_VALUES_GCN_QSAD__S4[];

    static unsigned REQ_PROP_VALUES_GCN_REGION_ALLOC__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_REGION_ALLOC__S0[];
    static unsigned REQ_PROP_VALUES_GCN_REGION_ALLOC__S1[];
    static unsigned REQ_PROP_VALUES_GCN_REGION_ALLOC__S2[];
    static unsigned REQ_PROP_VALUES_GCN_REGION_ALLOC__S3[];
    static unsigned REQ_PROP_VALUES_GCN_REGION_ALLOC__S4[];

    static unsigned REQ_PROP_VALUES_GCN_ST__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_ST__SEGMENT[];
    static unsigned REQ_PROP_VALUES_GCN_ST__S0[];
    static unsigned REQ_PROP_VALUES_GCN_ST__S1[];
    static unsigned REQ_PROP_VALUES_GCN_ST__S2[];
    static unsigned REQ_PROP_VALUES_GCN_ST__S3[];
    static unsigned REQ_PROP_VALUES_GCN_ST__S4[];
    static unsigned REQ_PROP_VALUES_GCN_ST__ALIGN[];
    static unsigned REQ_PROP_VALUES_GCN_ST__EQCLASS[];
    static unsigned REQ_PROP_VALUES_GCN_ST__WIDTH[];

    static unsigned REQ_PROP_VALUES_GCN_TRIG_PREOP__TYPE[];
    static unsigned REQ_PROP_VALUES_GCN_TRIG_PREOP__D0[];
    static unsigned REQ_PROP_VALUES_GCN_TRIG_PREOP__S1[];
    static unsigned REQ_PROP_VALUES_GCN_TRIG_PREOP__S2[];
    static unsigned REQ_PROP_VALUES_GCN_TRIG_PREOP__S3[];
    static unsigned REQ_PROP_VALUES_GCN_TRIG_PREOP__S4[];

    static unsigned REQ_PROP_VALUES_FBAR_NONE__TYPE[];
    static unsigned REQ_PROP_VALUES_FBAR_NONE__S0[];
    static unsigned REQ_PROP_VALUES_FBAR_NONE__S1[];
    static unsigned REQ_PROP_VALUES_FBAR_NONE__S2[];
    static unsigned REQ_PROP_VALUES_FBAR_NONE__S3[];
    static unsigned REQ_PROP_VALUES_FBAR_NONE__S4[];
    static unsigned REQ_PROP_VALUES_FBAR_NONE__MEMFNC[];
    static unsigned REQ_PROP_VALUES_FBAR_NONE__MEMORD[];
    static unsigned REQ_PROP_VALUES_FBAR_NONE__MEMSCP[];
    static unsigned REQ_PROP_VALUES_FBAR_NONE__WIDTH[];

    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__TYPE[];
    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__S0[];
    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__S1[];
    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__S2[];
    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__S3[];
    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__S4[];
    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__MEMFNC[];
    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__MEMORD[];
    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__MEMSCP[];
    static unsigned REQ_PROP_VALUES_FBAR_WIDTH__WIDTH[];

    static unsigned REQ_PROP_VALUES_LD__TYPE[];
    static unsigned REQ_PROP_VALUES_LD__SEGMENT[];
    static unsigned REQ_PROP_VALUES_LD__D0[];
    static unsigned REQ_PROP_VALUES_LD__S1[];
    static unsigned REQ_PROP_VALUES_LD__S2[];
    static unsigned REQ_PROP_VALUES_LD__S3[];
    static unsigned REQ_PROP_VALUES_LD__S4[];
    static unsigned REQ_PROP_VALUES_LD__ALIGN[];
    static unsigned REQ_PROP_VALUES_LD__EQCLASS[];
    static unsigned REQ_PROP_VALUES_LD__WIDTH[];

    static unsigned REQ_PROP_VALUES_LDA__TYPE[];
    static unsigned REQ_PROP_VALUES_LDA__SEGMENT[];
    static unsigned REQ_PROP_VALUES_LDA__D0[];
    static unsigned REQ_PROP_VALUES_LDA__S1[];
    static unsigned REQ_PROP_VALUES_LDA__S2[];
    static unsigned REQ_PROP_VALUES_LDA__S3[];
    static unsigned REQ_PROP_VALUES_LDA__S4[];

    static unsigned REQ_PROP_VALUES_LDC__TYPE[];
    static unsigned REQ_PROP_VALUES_LDC__D0[];
    static unsigned REQ_PROP_VALUES_LDC__S1[];
    static unsigned REQ_PROP_VALUES_LDC__S2[];
    static unsigned REQ_PROP_VALUES_LDC__S3[];
    static unsigned REQ_PROP_VALUES_LDC__S4[];

    static unsigned REQ_PROP_VALUES_LDF__TYPE[];
    static unsigned REQ_PROP_VALUES_LDF__S0[];
    static unsigned REQ_PROP_VALUES_LDF__S1[];
    static unsigned REQ_PROP_VALUES_LDF__S2[];
    static unsigned REQ_PROP_VALUES_LDF__S3[];
    static unsigned REQ_PROP_VALUES_LDF__S4[];

    static unsigned REQ_PROP_VALUES_LD_IMAGE__CTYPE[];
    static unsigned REQ_PROP_VALUES_LD_IMAGE__TYPE[];
    static unsigned REQ_PROP_VALUES_LD_IMAGE__GEOM[];
    static unsigned REQ_PROP_VALUES_LD_IMAGE__ITYPE[];
    static unsigned REQ_PROP_VALUES_LD_IMAGE__S1[];
    static unsigned REQ_PROP_VALUES_LD_IMAGE__S2[];
    static unsigned REQ_PROP_VALUES_LD_IMAGE__D0[];
    static unsigned REQ_PROP_VALUES_LD_IMAGE__S3[];
    static unsigned REQ_PROP_VALUES_LD_IMAGE__S4[];

    static unsigned REQ_PROP_VALUES_LERP__TYPE[];
    static unsigned REQ_PROP_VALUES_LERP__D0[];
    static unsigned REQ_PROP_VALUES_LERP__S1[];
    static unsigned REQ_PROP_VALUES_LERP__S2[];
    static unsigned REQ_PROP_VALUES_LERP__S3[];
    static unsigned REQ_PROP_VALUES_LERP__S4[];

    static unsigned REQ_PROP_VALUES_MAD__TYPE[];
    static unsigned REQ_PROP_VALUES_MAD__D0[];
    static unsigned REQ_PROP_VALUES_MAD__S1[];
    static unsigned REQ_PROP_VALUES_MAD__S2[];
    static unsigned REQ_PROP_VALUES_MAD__S3[];
    static unsigned REQ_PROP_VALUES_MAD__S4[];

    static unsigned REQ_PROP_VALUES_MAD24__TYPE[];
    static unsigned REQ_PROP_VALUES_MAD24__D0[];
    static unsigned REQ_PROP_VALUES_MAD24__S1[];
    static unsigned REQ_PROP_VALUES_MAD24__S2[];
    static unsigned REQ_PROP_VALUES_MAD24__S3[];
    static unsigned REQ_PROP_VALUES_MAD24__S4[];

    static unsigned REQ_PROP_VALUES_MASKLANE__STYPE[];
    static unsigned REQ_PROP_VALUES_MASKLANE__TYPE[];
    static unsigned REQ_PROP_VALUES_MASKLANE__D0[];
    static unsigned REQ_PROP_VALUES_MASKLANE__S1[];
    static unsigned REQ_PROP_VALUES_MASKLANE__S2[];
    static unsigned REQ_PROP_VALUES_MASKLANE__S3[];
    static unsigned REQ_PROP_VALUES_MASKLANE__S4[];
    static unsigned REQ_PROP_VALUES_MASKLANE__WIDTH[];

    static unsigned REQ_PROP_VALUES_MAX__TYPE[];
    static unsigned REQ_PROP_VALUES_MAX__FTZ[];
    static unsigned REQ_PROP_VALUES_MAX__PACKING[];
    static unsigned REQ_PROP_VALUES_MAX__D0[];
    static unsigned REQ_PROP_VALUES_MAX__S1[];
    static unsigned REQ_PROP_VALUES_MAX__S2[];
    static unsigned REQ_PROP_VALUES_MAX__S3[];
    static unsigned REQ_PROP_VALUES_MAX__S4[];
    static unsigned REQ_PROP_VALUES_MAX__ROUNDING[];

    static unsigned REQ_PROP_VALUES_MOV__TYPE[];
    static unsigned REQ_PROP_VALUES_MOV__D0[];
    static unsigned REQ_PROP_VALUES_MOV__S1[];
    static unsigned REQ_PROP_VALUES_MOV__S2[];
    static unsigned REQ_PROP_VALUES_MOV__S3[];
    static unsigned REQ_PROP_VALUES_MOV__S4[];

    static unsigned REQ_PROP_VALUES_MUL__TYPE[];
    static unsigned REQ_PROP_VALUES_MUL__FTZ[];
    static unsigned REQ_PROP_VALUES_MUL__PACKING[];
    static unsigned REQ_PROP_VALUES_MUL__ROUNDING[];
    static unsigned REQ_PROP_VALUES_MUL__D0[];
    static unsigned REQ_PROP_VALUES_MUL__S1[];
    static unsigned REQ_PROP_VALUES_MUL__S2[];
    static unsigned REQ_PROP_VALUES_MUL__S3[];
    static unsigned REQ_PROP_VALUES_MUL__S4[];

    static unsigned REQ_PROP_VALUES_MUL24__TYPE[];
    static unsigned REQ_PROP_VALUES_MUL24__D0[];
    static unsigned REQ_PROP_VALUES_MUL24__S1[];
    static unsigned REQ_PROP_VALUES_MUL24__S2[];
    static unsigned REQ_PROP_VALUES_MUL24__S3[];
    static unsigned REQ_PROP_VALUES_MUL24__S4[];

    static unsigned REQ_PROP_VALUES_MULHI__TYPE[];
    static unsigned REQ_PROP_VALUES_MULHI__PACKING[];
    static unsigned REQ_PROP_VALUES_MULHI__D0[];
    static unsigned REQ_PROP_VALUES_MULHI__S1[];
    static unsigned REQ_PROP_VALUES_MULHI__S2[];
    static unsigned REQ_PROP_VALUES_MULHI__S3[];
    static unsigned REQ_PROP_VALUES_MULHI__S4[];
    static unsigned REQ_PROP_VALUES_MULHI__FTZ[];
    static unsigned REQ_PROP_VALUES_MULHI__ROUNDING[];

    static unsigned REQ_PROP_VALUES_TRIG32__TYPE[];
    static unsigned REQ_PROP_VALUES_TRIG32__D0[];
    static unsigned REQ_PROP_VALUES_TRIG32__S1[];
    static unsigned REQ_PROP_VALUES_TRIG32__S2[];
    static unsigned REQ_PROP_VALUES_TRIG32__S3[];
    static unsigned REQ_PROP_VALUES_TRIG32__S4[];

    static unsigned REQ_PROP_VALUES_NFMA__TYPE[];
    static unsigned REQ_PROP_VALUES_NFMA__D0[];
    static unsigned REQ_PROP_VALUES_NFMA__S1[];
    static unsigned REQ_PROP_VALUES_NFMA__S2[];
    static unsigned REQ_PROP_VALUES_NFMA__S3[];
    static unsigned REQ_PROP_VALUES_NFMA__S4[];

    static unsigned REQ_PROP_VALUES_NOP__TYPE[];
    static unsigned REQ_PROP_VALUES_NOP__S0[];
    static unsigned REQ_PROP_VALUES_NOP__S1[];
    static unsigned REQ_PROP_VALUES_NOP__S2[];
    static unsigned REQ_PROP_VALUES_NOP__S3[];
    static unsigned REQ_PROP_VALUES_NOP__S4[];

    static unsigned REQ_PROP_VALUES_NOT__TYPE[];
    static unsigned REQ_PROP_VALUES_NOT__D0[];
    static unsigned REQ_PROP_VALUES_NOT__S1[];
    static unsigned REQ_PROP_VALUES_NOT__S2[];
    static unsigned REQ_PROP_VALUES_NOT__S3[];
    static unsigned REQ_PROP_VALUES_NOT__S4[];

    static unsigned REQ_PROP_VALUES_TRIG__TYPE[];
    static unsigned REQ_PROP_VALUES_TRIG__D0[];
    static unsigned REQ_PROP_VALUES_TRIG__S1[];
    static unsigned REQ_PROP_VALUES_TRIG__S2[];
    static unsigned REQ_PROP_VALUES_TRIG__S3[];
    static unsigned REQ_PROP_VALUES_TRIG__S4[];

    static unsigned REQ_PROP_VALUES_NULLPTR__STYPE[];
    static unsigned REQ_PROP_VALUES_NULLPTR__TYPE[];
    static unsigned REQ_PROP_VALUES_NULLPTR__SEGMENT[];
    static unsigned REQ_PROP_VALUES_NULLPTR__S0[];
    static unsigned REQ_PROP_VALUES_NULLPTR__S1[];
    static unsigned REQ_PROP_VALUES_NULLPTR__S2[];
    static unsigned REQ_PROP_VALUES_NULLPTR__S3[];
    static unsigned REQ_PROP_VALUES_NULLPTR__S4[];

    static unsigned REQ_PROP_VALUES_PACK__STYPE[];
    static unsigned REQ_PROP_VALUES_PACK__TYPE[];
    static unsigned REQ_PROP_VALUES_PACK__D0[];
    static unsigned REQ_PROP_VALUES_PACK__S1[];
    static unsigned REQ_PROP_VALUES_PACK__S2[];
    static unsigned REQ_PROP_VALUES_PACK__S3[];
    static unsigned REQ_PROP_VALUES_PACK__S4[];

    static unsigned REQ_PROP_VALUES_PACKCVT__STYPE[];
    static unsigned REQ_PROP_VALUES_PACKCVT__TYPE[];
    static unsigned REQ_PROP_VALUES_PACKCVT__D0[];
    static unsigned REQ_PROP_VALUES_PACKCVT__S1[];
    static unsigned REQ_PROP_VALUES_PACKCVT__S2[];
    static unsigned REQ_PROP_VALUES_PACKCVT__S3[];
    static unsigned REQ_PROP_VALUES_PACKCVT__S4[];

    static unsigned REQ_PROP_VALUES_POPCOUNT__STYPE[];
    static unsigned REQ_PROP_VALUES_POPCOUNT__TYPE[];
    static unsigned REQ_PROP_VALUES_POPCOUNT__D0[];
    static unsigned REQ_PROP_VALUES_POPCOUNT__S1[];
    static unsigned REQ_PROP_VALUES_POPCOUNT__S2[];
    static unsigned REQ_PROP_VALUES_POPCOUNT__S3[];
    static unsigned REQ_PROP_VALUES_POPCOUNT__S4[];

    static unsigned REQ_PROP_VALUES_QUERYIMAGE__STYPE[];
    static unsigned REQ_PROP_VALUES_QUERYIMAGE__TYPE[];
    static unsigned REQ_PROP_VALUES_QUERYIMAGE__S1[];
    static unsigned REQ_PROP_VALUES_QUERYIMAGE__D0[];
    static unsigned REQ_PROP_VALUES_QUERYIMAGE__S2[];
    static unsigned REQ_PROP_VALUES_QUERYIMAGE__S3[];
    static unsigned REQ_PROP_VALUES_QUERYIMAGE__S4[];

    static unsigned REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__STYPE[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__TYPE[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__D0[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S1[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S2[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S3[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S4[];

    static unsigned REQ_PROP_VALUES_QUERYSAMPLER__STYPE[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLER__TYPE[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLER__D0[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLER__S1[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLER__S2[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLER__S3[];
    static unsigned REQ_PROP_VALUES_QUERYSAMPLER__S4[];

    static unsigned REQ_PROP_VALUES_RDIMAGE__CTYPE[];
    static unsigned REQ_PROP_VALUES_RDIMAGE__TYPE[];
    static unsigned REQ_PROP_VALUES_RDIMAGE__GEOM[];
    static unsigned REQ_PROP_VALUES_RDIMAGE__ITYPE[];
    static unsigned REQ_PROP_VALUES_RDIMAGE__S1[];
    static unsigned REQ_PROP_VALUES_RDIMAGE__S3[];
    static unsigned REQ_PROP_VALUES_RDIMAGE__D0[];
    static unsigned REQ_PROP_VALUES_RDIMAGE__S2[];
    static unsigned REQ_PROP_VALUES_RDIMAGE__S4[];

    static unsigned REQ_PROP_VALUES_SENDLANE__STYPE[];
    static unsigned REQ_PROP_VALUES_SENDLANE__TYPE[];
    static unsigned REQ_PROP_VALUES_SENDLANE__D0[];
    static unsigned REQ_PROP_VALUES_SENDLANE__S1[];
    static unsigned REQ_PROP_VALUES_SENDLANE__S2[];
    static unsigned REQ_PROP_VALUES_SENDLANE__S3[];
    static unsigned REQ_PROP_VALUES_SENDLANE__S4[];
    static unsigned REQ_PROP_VALUES_SENDLANE__WIDTH[];

    static unsigned REQ_PROP_VALUES_RET__TYPE[];
    static unsigned REQ_PROP_VALUES_RET__S0[];
    static unsigned REQ_PROP_VALUES_RET__S1[];
    static unsigned REQ_PROP_VALUES_RET__S2[];
    static unsigned REQ_PROP_VALUES_RET__S3[];
    static unsigned REQ_PROP_VALUES_RET__S4[];

    static unsigned REQ_PROP_VALUES_SAD__STYPE[];
    static unsigned REQ_PROP_VALUES_SAD__TYPE[];
    static unsigned REQ_PROP_VALUES_SAD__D0[];
    static unsigned REQ_PROP_VALUES_SAD__S1[];
    static unsigned REQ_PROP_VALUES_SAD__S2[];
    static unsigned REQ_PROP_VALUES_SAD__S3[];
    static unsigned REQ_PROP_VALUES_SAD__S4[];

    static unsigned REQ_PROP_VALUES_SADHI__STYPE[];
    static unsigned REQ_PROP_VALUES_SADHI__TYPE[];
    static unsigned REQ_PROP_VALUES_SADHI__D0[];
    static unsigned REQ_PROP_VALUES_SADHI__S1[];
    static unsigned REQ_PROP_VALUES_SADHI__S2[];
    static unsigned REQ_PROP_VALUES_SADHI__S3[];
    static unsigned REQ_PROP_VALUES_SADHI__S4[];

    static unsigned REQ_PROP_VALUES_SEGMENTP__STYPE[];
    static unsigned REQ_PROP_VALUES_SEGMENTP__TYPE[];
    static unsigned REQ_PROP_VALUES_SEGMENTP__SEGMENT[];
    static unsigned REQ_PROP_VALUES_SEGMENTP__D0[];
    static unsigned REQ_PROP_VALUES_SEGMENTP__S1[];
    static unsigned REQ_PROP_VALUES_SEGMENTP__S2[];
    static unsigned REQ_PROP_VALUES_SEGMENTP__S3[];
    static unsigned REQ_PROP_VALUES_SEGMENTP__S4[];

    static unsigned REQ_PROP_VALUES_SHIFT__TYPE[];
    static unsigned REQ_PROP_VALUES_SHIFT__D0[];
    static unsigned REQ_PROP_VALUES_SHIFT__S1[];
    static unsigned REQ_PROP_VALUES_SHIFT__S2[];
    static unsigned REQ_PROP_VALUES_SHIFT__S3[];
    static unsigned REQ_PROP_VALUES_SHIFT__S4[];

    static unsigned REQ_PROP_VALUES_SHUFFLE__TYPE[];
    static unsigned REQ_PROP_VALUES_SHUFFLE__D0[];
    static unsigned REQ_PROP_VALUES_SHUFFLE__S1[];
    static unsigned REQ_PROP_VALUES_SHUFFLE__S2[];
    static unsigned REQ_PROP_VALUES_SHUFFLE__S3[];
    static unsigned REQ_PROP_VALUES_SHUFFLE__S4[];

    static unsigned REQ_PROP_VALUES_SQRT__TYPE[];
    static unsigned REQ_PROP_VALUES_SQRT__PACKING[];
    static unsigned REQ_PROP_VALUES_SQRT__D0[];
    static unsigned REQ_PROP_VALUES_SQRT__S1[];
    static unsigned REQ_PROP_VALUES_SQRT__S2[];
    static unsigned REQ_PROP_VALUES_SQRT__S3[];
    static unsigned REQ_PROP_VALUES_SQRT__S4[];
    static unsigned REQ_PROP_VALUES_SQRT__FTZ[];
    static unsigned REQ_PROP_VALUES_SQRT__ROUNDING[];

    static unsigned REQ_PROP_VALUES_ST__TYPE[];
    static unsigned REQ_PROP_VALUES_ST__SEGMENT[];
    static unsigned REQ_PROP_VALUES_ST__S0[];
    static unsigned REQ_PROP_VALUES_ST__S1[];
    static unsigned REQ_PROP_VALUES_ST__S2[];
    static unsigned REQ_PROP_VALUES_ST__S3[];
    static unsigned REQ_PROP_VALUES_ST__S4[];
    static unsigned REQ_PROP_VALUES_ST__ALIGN[];
    static unsigned REQ_PROP_VALUES_ST__EQCLASS[];
    static unsigned REQ_PROP_VALUES_ST__WIDTH[];

    static unsigned REQ_PROP_VALUES_ST_IMAGE__CTYPE[];
    static unsigned REQ_PROP_VALUES_ST_IMAGE__TYPE[];
    static unsigned REQ_PROP_VALUES_ST_IMAGE__GEOM[];
    static unsigned REQ_PROP_VALUES_ST_IMAGE__S2[];
    static unsigned REQ_PROP_VALUES_ST_IMAGE__S0[];
    static unsigned REQ_PROP_VALUES_ST_IMAGE__S1[];
    static unsigned REQ_PROP_VALUES_ST_IMAGE__S3[];
    static unsigned REQ_PROP_VALUES_ST_IMAGE__S4[];
    static unsigned REQ_PROP_VALUES_ST_IMAGE__ITYPE[];

    static unsigned REQ_PROP_VALUES_S2F__STYPE[];
    static unsigned REQ_PROP_VALUES_S2F__TYPE[];
    static unsigned REQ_PROP_VALUES_S2F__SEGMENT[];
    static unsigned REQ_PROP_VALUES_S2F__D0[];
    static unsigned REQ_PROP_VALUES_S2F__S1[];
    static unsigned REQ_PROP_VALUES_S2F__S2[];
    static unsigned REQ_PROP_VALUES_S2F__S3[];
    static unsigned REQ_PROP_VALUES_S2F__S4[];

    static unsigned REQ_PROP_VALUES_SYNC__TYPE[];
    static unsigned REQ_PROP_VALUES_SYNC__S0[];
    static unsigned REQ_PROP_VALUES_SYNC__S1[];
    static unsigned REQ_PROP_VALUES_SYNC__S2[];
    static unsigned REQ_PROP_VALUES_SYNC__S3[];
    static unsigned REQ_PROP_VALUES_SYNC__S4[];
    static unsigned REQ_PROP_VALUES_SYNC__MEMFNC[];
    static unsigned REQ_PROP_VALUES_SYNC__MEMORD[];
    static unsigned REQ_PROP_VALUES_SYNC__MEMSCP[];
    static unsigned REQ_PROP_VALUES_SYNC__WIDTH[];

    static unsigned REQ_PROP_VALUES_SYSCALL__TYPE[];
    static unsigned REQ_PROP_VALUES_SYSCALL__S0[];
    static unsigned REQ_PROP_VALUES_SYSCALL__S1[];
    static unsigned REQ_PROP_VALUES_SYSCALL__S2[];
    static unsigned REQ_PROP_VALUES_SYSCALL__S3[];
    static unsigned REQ_PROP_VALUES_SYSCALL__S4[];

    static unsigned REQ_PROP_VALUES_UNPACK__STYPE[];
    static unsigned REQ_PROP_VALUES_UNPACK__TYPE[];
    static unsigned REQ_PROP_VALUES_UNPACK__D0[];
    static unsigned REQ_PROP_VALUES_UNPACK__S1[];
    static unsigned REQ_PROP_VALUES_UNPACK__S2[];
    static unsigned REQ_PROP_VALUES_UNPACK__S3[];
    static unsigned REQ_PROP_VALUES_UNPACK__S4[];

    static unsigned REQ_PROP_VALUES_UNPACKCVT__STYPE[];
    static unsigned REQ_PROP_VALUES_UNPACKCVT__TYPE[];
    static unsigned REQ_PROP_VALUES_UNPACKCVT__D0[];
    static unsigned REQ_PROP_VALUES_UNPACKCVT__S1[];
    static unsigned REQ_PROP_VALUES_UNPACKCVT__S2[];
    static unsigned REQ_PROP_VALUES_UNPACKCVT__S3[];
    static unsigned REQ_PROP_VALUES_UNPACKCVT__S4[];

    static unsigned REQ_PROP_VALUES_UNPACKX__TYPE[];
    static unsigned REQ_PROP_VALUES_UNPACKX__D0[];
    static unsigned REQ_PROP_VALUES_UNPACKX__S1[];
    static unsigned REQ_PROP_VALUES_UNPACKX__S2[];
    static unsigned REQ_PROP_VALUES_UNPACKX__S3[];
    static unsigned REQ_PROP_VALUES_UNPACKX__S4[];


private:
    template<class T> static bool chkReqPropNeg(T inst, unsigned propId);
    template<class T> static bool chkReqPropAdd(T inst, unsigned propId);
    template<class T> static bool chkReqPropAlloca(T inst, unsigned propId);
    template<class T> static bool chkReqPropAnd(T inst, unsigned propId);
    template<class T> static bool chkReqPropFbar_sync_width(T inst, unsigned propId);
    template<class T> static bool chkReqPropAtomic(T inst, unsigned propId);
    template<class T> static bool chkReqPropAtomic_image(T inst, unsigned propId);
    template<class T> static bool chkReqPropAtomic_noret_image(T inst, unsigned propId);
    template<class T> static bool chkReqPropAtomic_noret(T inst, unsigned propId);
    template<class T> static bool chkReqPropBarrier(T inst, unsigned propId);
    template<class T> static bool chkReqPropAlign(T inst, unsigned propId);
    template<class T> static bool chkReqPropBitextract(T inst, unsigned propId);
    template<class T> static bool chkReqPropBitinsert(T inst, unsigned propId);
    template<class T> static bool chkReqPropBitmask(T inst, unsigned propId);
    template<class T> static bool chkReqPropBitrev(T inst, unsigned propId);
    template<class T> static bool chkReqPropBitselect(T inst, unsigned propId);
    template<class T> static bool chkReqPropRem(T inst, unsigned propId);
    template<class T> static bool chkReqPropBrn(T inst, unsigned propId);
    template<class T> static bool chkReqPropCall(T inst, unsigned propId);
    template<class T> static bool chkReqPropCbr(T inst, unsigned propId);
    template<class T> static bool chkReqPropCeil(T inst, unsigned propId);
    template<class T> static bool chkReqPropClass(T inst, unsigned propId);
    template<class T> static bool chkReqPropSpec_except(T inst, unsigned propId);
    template<class T> static bool chkReqPropSpec_clock(T inst, unsigned propId);
    template<class T> static bool chkReqPropCmov(T inst, unsigned propId);
    template<class T> static bool chkReqPropCmp(T inst, unsigned propId);
    template<class T> static bool chkReqPropCodeblockend(T inst, unsigned propId);
    template<class T> static bool chkReqPropCombine(T inst, unsigned propId);
    template<class T> static bool chkReqPropCopysign(T inst, unsigned propId);
    template<class T> static bool chkReqPropCountlane(T inst, unsigned propId);
    template<class T> static bool chkReqPropCountuplane(T inst, unsigned propId);
    template<class T> static bool chkReqPropSpec_reg(T inst, unsigned propId);
    template<class T> static bool chkReqPropSpec_reg_dim(T inst, unsigned propId);
    template<class T> static bool chkReqPropCvt(T inst, unsigned propId);
    template<class T> static bool chkReqPropDebugtrap(T inst, unsigned propId);
    template<class T> static bool chkReqPropAqlptr(T inst, unsigned propId);
    template<class T> static bool chkReqPropDiv(T inst, unsigned propId);
    template<class T> static bool chkReqPropExpand(T inst, unsigned propId);
    template<class T> static bool chkReqPropFirstbit(T inst, unsigned propId);
    template<class T> static bool chkReqPropFma(T inst, unsigned propId);
    template<class T> static bool chkReqPropFract(T inst, unsigned propId);
    template<class T> static bool chkReqPropF2s(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_append_consume(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_atomic(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_atomic_noret(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_b4xchg(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_bfm(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_fldexp(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_frexp_exp(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_frexp_mant(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_ld(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_mad(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_min_max_med(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_mqsad(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_mqsad4(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_msad(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_slp_prt(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_qsad(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_region_alloc(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_st(T inst, unsigned propId);
    template<class T> static bool chkReqPropGcn_trig_preop(T inst, unsigned propId);
    template<class T> static bool chkReqPropFbar_none(T inst, unsigned propId);
    template<class T> static bool chkReqPropFbar_width(T inst, unsigned propId);
    template<class T> static bool chkReqPropLd(T inst, unsigned propId);
    template<class T> static bool chkReqPropLda(T inst, unsigned propId);
    template<class T> static bool chkReqPropLdc(T inst, unsigned propId);
    template<class T> static bool chkReqPropLdf(T inst, unsigned propId);
    template<class T> static bool chkReqPropLd_image(T inst, unsigned propId);
    template<class T> static bool chkReqPropLerp(T inst, unsigned propId);
    template<class T> static bool chkReqPropMad(T inst, unsigned propId);
    template<class T> static bool chkReqPropMad24(T inst, unsigned propId);
    template<class T> static bool chkReqPropMasklane(T inst, unsigned propId);
    template<class T> static bool chkReqPropMax(T inst, unsigned propId);
    template<class T> static bool chkReqPropMov(T inst, unsigned propId);
    template<class T> static bool chkReqPropMul(T inst, unsigned propId);
    template<class T> static bool chkReqPropMul24(T inst, unsigned propId);
    template<class T> static bool chkReqPropMulhi(T inst, unsigned propId);
    template<class T> static bool chkReqPropTrig32(T inst, unsigned propId);
    template<class T> static bool chkReqPropNfma(T inst, unsigned propId);
    template<class T> static bool chkReqPropNop(T inst, unsigned propId);
    template<class T> static bool chkReqPropNot(T inst, unsigned propId);
    template<class T> static bool chkReqPropTrig(T inst, unsigned propId);
    template<class T> static bool chkReqPropNullptr(T inst, unsigned propId);
    template<class T> static bool chkReqPropPack(T inst, unsigned propId);
    template<class T> static bool chkReqPropPackcvt(T inst, unsigned propId);
    template<class T> static bool chkReqPropPopcount(T inst, unsigned propId);
    template<class T> static bool chkReqPropQueryimage(T inst, unsigned propId);
    template<class T> static bool chkReqPropQuerysamplerboundary(T inst, unsigned propId);
    template<class T> static bool chkReqPropQuerysampler(T inst, unsigned propId);
    template<class T> static bool chkReqPropRdimage(T inst, unsigned propId);
    template<class T> static bool chkReqPropSendlane(T inst, unsigned propId);
    template<class T> static bool chkReqPropRet(T inst, unsigned propId);
    template<class T> static bool chkReqPropSad(T inst, unsigned propId);
    template<class T> static bool chkReqPropSadhi(T inst, unsigned propId);
    template<class T> static bool chkReqPropSegmentp(T inst, unsigned propId);
    template<class T> static bool chkReqPropShift(T inst, unsigned propId);
    template<class T> static bool chkReqPropShuffle(T inst, unsigned propId);
    template<class T> static bool chkReqPropSqrt(T inst, unsigned propId);
    template<class T> static bool chkReqPropSt(T inst, unsigned propId);
    template<class T> static bool chkReqPropSt_image(T inst, unsigned propId);
    template<class T> static bool chkReqPropS2f(T inst, unsigned propId);
    template<class T> static bool chkReqPropSync(T inst, unsigned propId);
    template<class T> static bool chkReqPropSyscall(T inst, unsigned propId);
    template<class T> static bool chkReqPropUnpack(T inst, unsigned propId);
    template<class T> static bool chkReqPropUnpackcvt(T inst, unsigned propId);
    template<class T> static bool chkReqPropUnpackx(T inst, unsigned propId);

private:
    template<class T> static bool validateReqNeg(T inst);
    template<class T> static bool validateReqAdd(T inst);
    template<class T> static bool validateReqAlloca(T inst);
    template<class T> static bool validateReqAnd(T inst);
    template<class T> static bool validateReqFbar_sync_width(T inst);
    template<class T> static bool validateReqAtomic(T inst);
    template<class T> static bool validateReqAtomic_image(T inst);
    template<class T> static bool validateReqAtomic_noret_image(T inst);
    template<class T> static bool validateReqAtomic_noret(T inst);
    template<class T> static bool validateReqBarrier(T inst);
    template<class T> static bool validateReqAlign(T inst);
    template<class T> static bool validateReqBitextract(T inst);
    template<class T> static bool validateReqBitinsert(T inst);
    template<class T> static bool validateReqBitmask(T inst);
    template<class T> static bool validateReqBitrev(T inst);
    template<class T> static bool validateReqBitselect(T inst);
    template<class T> static bool validateReqRem(T inst);
    template<class T> static bool validateReqBrn(T inst);
    template<class T> static bool validateReqCall(T inst);
    template<class T> static bool validateReqCbr(T inst);
    template<class T> static bool validateReqCeil(T inst);
    template<class T> static bool validateReqClass(T inst);
    template<class T> static bool validateReqSpec_except(T inst);
    template<class T> static bool validateReqSpec_clock(T inst);
    template<class T> static bool validateReqCmov(T inst);
    template<class T> static bool validateReqCmp(T inst);
    template<class T> static bool validateReqCodeblockend(T inst);
    template<class T> static bool validateReqCombine(T inst);
    template<class T> static bool validateReqCopysign(T inst);
    template<class T> static bool validateReqCountlane(T inst);
    template<class T> static bool validateReqCountuplane(T inst);
    template<class T> static bool validateReqSpec_reg(T inst);
    template<class T> static bool validateReqSpec_reg_dim(T inst);
    template<class T> static bool validateReqCvt(T inst);
    template<class T> static bool validateReqDebugtrap(T inst);
    template<class T> static bool validateReqAqlptr(T inst);
    template<class T> static bool validateReqDiv(T inst);
    template<class T> static bool validateReqExpand(T inst);
    template<class T> static bool validateReqFirstbit(T inst);
    template<class T> static bool validateReqFma(T inst);
    template<class T> static bool validateReqFract(T inst);
    template<class T> static bool validateReqF2s(T inst);
    template<class T> static bool validateReqGcn_append_consume(T inst);
    template<class T> static bool validateReqGcn_atomic(T inst);
    template<class T> static bool validateReqGcn_atomic_noret(T inst);
    template<class T> static bool validateReqGcn_b4xchg(T inst);
    template<class T> static bool validateReqGcn_bfm(T inst);
    template<class T> static bool validateReqGcn_fldexp(T inst);
    template<class T> static bool validateReqGcn_frexp_exp(T inst);
    template<class T> static bool validateReqGcn_frexp_mant(T inst);
    template<class T> static bool validateReqGcn_ld(T inst);
    template<class T> static bool validateReqGcn_mad(T inst);
    template<class T> static bool validateReqGcn_min_max_med(T inst);
    template<class T> static bool validateReqGcn_mqsad(T inst);
    template<class T> static bool validateReqGcn_mqsad4(T inst);
    template<class T> static bool validateReqGcn_msad(T inst);
    template<class T> static bool validateReqGcn_slp_prt(T inst);
    template<class T> static bool validateReqGcn_qsad(T inst);
    template<class T> static bool validateReqGcn_region_alloc(T inst);
    template<class T> static bool validateReqGcn_st(T inst);
    template<class T> static bool validateReqGcn_trig_preop(T inst);
    template<class T> static bool validateReqFbar_none(T inst);
    template<class T> static bool validateReqFbar_width(T inst);
    template<class T> static bool validateReqLd(T inst);
    template<class T> static bool validateReqLda(T inst);
    template<class T> static bool validateReqLdc(T inst);
    template<class T> static bool validateReqLdf(T inst);
    template<class T> static bool validateReqLd_image(T inst);
    template<class T> static bool validateReqLerp(T inst);
    template<class T> static bool validateReqMad(T inst);
    template<class T> static bool validateReqMad24(T inst);
    template<class T> static bool validateReqMasklane(T inst);
    template<class T> static bool validateReqMax(T inst);
    template<class T> static bool validateReqMov(T inst);
    template<class T> static bool validateReqMul(T inst);
    template<class T> static bool validateReqMul24(T inst);
    template<class T> static bool validateReqMulhi(T inst);
    template<class T> static bool validateReqTrig32(T inst);
    template<class T> static bool validateReqNfma(T inst);
    template<class T> static bool validateReqNop(T inst);
    template<class T> static bool validateReqNot(T inst);
    template<class T> static bool validateReqTrig(T inst);
    template<class T> static bool validateReqNullptr(T inst);
    template<class T> static bool validateReqPack(T inst);
    template<class T> static bool validateReqPackcvt(T inst);
    template<class T> static bool validateReqPopcount(T inst);
    template<class T> static bool validateReqQueryimage(T inst);
    template<class T> static bool validateReqQuerysamplerboundary(T inst);
    template<class T> static bool validateReqQuerysampler(T inst);
    template<class T> static bool validateReqRdimage(T inst);
    template<class T> static bool validateReqSendlane(T inst);
    template<class T> static bool validateReqRet(T inst);
    template<class T> static bool validateReqSad(T inst);
    template<class T> static bool validateReqSadhi(T inst);
    template<class T> static bool validateReqSegmentp(T inst);
    template<class T> static bool validateReqShift(T inst);
    template<class T> static bool validateReqShuffle(T inst);
    template<class T> static bool validateReqSqrt(T inst);
    template<class T> static bool validateReqSt(T inst);
    template<class T> static bool validateReqSt_image(T inst);
    template<class T> static bool validateReqS2f(T inst);
    template<class T> static bool validateReqSync(T inst);
    template<class T> static bool validateReqSyscall(T inst);
    template<class T> static bool validateReqUnpack(T inst);
    template<class T> static bool validateReqUnpackcvt(T inst);
    template<class T> static bool validateReqUnpackx(T inst);
}; // class PropDescImpl 

unsigned PropDescImpl::ALIGN_VALUES_ANY[] = {
    0,
    1
};

unsigned PropDescImpl::ATMOP_VALUES_GENERIC_EXCH_LD[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_LD,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR
};

unsigned PropDescImpl::ATMOP_VALUES_GENERIC_EXCH[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR
};

unsigned PropDescImpl::ATMOP_VALUES_GENERIC_ST[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_ST,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR
};

unsigned PropDescImpl::ATMOP_VALUES_GENERIC[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR
};

unsigned PropDescImpl::ATMOP_VALUES_ADD_SUB_MIN_MAX[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_SUB
};

unsigned PropDescImpl::ATMOP_VALUES_AND_OR_XOR_EXCH[] = {
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_XOR
};

unsigned PropDescImpl::ATMOP_VALUES_AND_OR_XOR[] = {
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_XOR
};

unsigned PropDescImpl::ATMOP_VALUES_CAS[] = {
    Brig::BRIG_ATOMIC_CAS
};

unsigned PropDescImpl::ATMOP_VALUES_INC_DEC[] = {
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_INC
};

unsigned PropDescImpl::ATMOP_VALUES_LD[] = {
    Brig::BRIG_ATOMIC_LD
};

unsigned PropDescImpl::ATMOP_VALUES_ST[] = {
    Brig::BRIG_ATOMIC_ST
};

unsigned PropDescImpl::EQCLASS_VALUES_ANY[] = {
    EQCLASS_VAL_ANY
};

unsigned PropDescImpl::FTZ_VALUES_NONE[] = {
    0
};

unsigned PropDescImpl::FTZ_VALUES_ANY[] = {
    0,
    1
};

unsigned PropDescImpl::GEOM_VALUES_1D[] = {
    Brig::BRIG_GEOMETRY_1D
};

unsigned PropDescImpl::GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA[] = {
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_1DB,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D
};

unsigned PropDescImpl::GEOM_VALUES_1D_2D_3D_1DA_2DA[] = {
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D
};

unsigned PropDescImpl::GEOM_VALUES_1D_1DB[] = {
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DB
};

unsigned PropDescImpl::GEOM_VALUES_2D_1DA[] = {
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_2D
};

unsigned PropDescImpl::GEOM_VALUES_3D_2DA[] = {
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D
};

unsigned PropDescImpl::MEMFNC_VALUES_ANY[] = {
    Brig::BRIG_MEMORY_FENCE_BOTH,
    Brig::BRIG_MEMORY_FENCE_GLOBAL,
    Brig::BRIG_MEMORY_FENCE_GROUP
};

unsigned PropDescImpl::MEMFNC_VALUES_NONE[] = {
    Brig::BRIG_MEMORY_FENCE_NONE
};

unsigned PropDescImpl::MEMORD_VALUES_ANY[] = {
    Brig::BRIG_MEMORY_ORDER_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_ACQUIRE_RELEASE,
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT
};

unsigned PropDescImpl::MEMORD_VALUES_LD[] = {
    Brig::BRIG_MEMORY_ORDER_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT
};

unsigned PropDescImpl::MEMORD_VALUES_NONE[] = {
    Brig::BRIG_MEMORY_ORDER_NONE
};

unsigned PropDescImpl::MEMORD_VALUES_ST[] = {
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT
};

unsigned PropDescImpl::MEMSCP_VALUES_ANY[] = {
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP
};

unsigned PropDescImpl::MEMSCP_VALUES_NONE[] = {
    Brig::BRIG_MEMORY_SCOPE_NONE
};

unsigned PropDescImpl::OPERAND_VALUES_ADDRSEG[] = {
    OPERAND_VAL_ADDR_SEG
};

unsigned PropDescImpl::OPERAND_VALUES_ADDRTSEG[] = {
    OPERAND_VAL_ADDR_TSEG
};

unsigned PropDescImpl::OPERAND_VALUES_ARGLIST[] = {
    OPERAND_VAL_ARGLIST
};

unsigned PropDescImpl::OPERAND_VALUES_NULL_CALLTAB[] = {
    OPERAND_VAL_CALLTAB,
    OPERAND_VAL_NULL
};

unsigned PropDescImpl::OPERAND_VALUES_FBARRIER[] = {
    OPERAND_VAL_FBARRIER
};

unsigned PropDescImpl::OPERAND_VALUES_REG32_FBARRIER[] = {
    OPERAND_VAL_FBARRIER,
    OPERAND_VAL_REG_32
};

unsigned PropDescImpl::OPERAND_VALUES_FUNCMODEL[] = {
    OPERAND_VAL_FUNC
};

unsigned PropDescImpl::OPERAND_VALUES_LAB_FUNC[] = {
    OPERAND_VAL_FUNC,
    OPERAND_VAL_LAB
};

unsigned PropDescImpl::OPERAND_VALUES_REGMODEL_FUNCMODEL[] = {
    OPERAND_VAL_FUNC,
    OPERAND_VAL_REG
};

unsigned PropDescImpl::OPERAND_VALUES_IMM[] = {
    OPERAND_VAL_IMM
};

unsigned PropDescImpl::OPERAND_VALUES_REG_IMM[] = {
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG
};

unsigned PropDescImpl::OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP[] = {
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4
};

unsigned PropDescImpl::OPERAND_VALUES_IMM012[] = {
    OPERAND_VAL_IMM_0_1_2
};

unsigned PropDescImpl::OPERAND_VALUES_IMM0123[] = {
    OPERAND_VAL_IMM_0_1_2_3
};

unsigned PropDescImpl::OPERAND_VALUES_REG1_IMM1[] = {
    OPERAND_VAL_IMM_1,
    OPERAND_VAL_REG_1
};

unsigned PropDescImpl::OPERAND_VALUES_IMM32[] = {
    OPERAND_VAL_IMM_32
};

unsigned PropDescImpl::OPERAND_VALUES_REG32_IMM32[] = {
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32
};

unsigned PropDescImpl::OPERAND_VALUES_REG64_IMM64[] = {
    OPERAND_VAL_IMM_64,
    OPERAND_VAL_REG_64
};

unsigned PropDescImpl::OPERAND_VALUES_NULL_JUMPTAB[] = {
    OPERAND_VAL_JUMPTAB,
    OPERAND_VAL_NULL
};

unsigned PropDescImpl::OPERAND_VALUES_LABMODEL[] = {
    OPERAND_VAL_LAB
};

unsigned PropDescImpl::OPERAND_VALUES_REGMODEL_LABMODEL[] = {
    OPERAND_VAL_LAB,
    OPERAND_VAL_REG
};

unsigned PropDescImpl::OPERAND_VALUES_NULL[] = {
    OPERAND_VAL_NULL
};

unsigned PropDescImpl::OPERAND_VALUES_REG[] = {
    OPERAND_VAL_REG
};

unsigned PropDescImpl::OPERAND_VALUES_REGEXP_REGVEXP[] = {
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4
};

unsigned PropDescImpl::OPERAND_VALUES_REG1[] = {
    OPERAND_VAL_REG_1
};

unsigned PropDescImpl::OPERAND_VALUES_REG32[] = {
    OPERAND_VAL_REG_32
};

unsigned PropDescImpl::OPERAND_VALUES_REG64[] = {
    OPERAND_VAL_REG_64
};

unsigned PropDescImpl::OPERAND_VALUES_REG64_ROIMAGE[] = {
    OPERAND_VAL_REG_64,
    OPERAND_VAL_ROIMAGE
};

unsigned PropDescImpl::OPERAND_VALUES_REG64_IMAGE[] = {
    OPERAND_VAL_REG_64,
    OPERAND_VAL_ROIMAGE,
    OPERAND_VAL_RWIMAGE
};

unsigned PropDescImpl::OPERAND_VALUES_REG64_RWIMAGE[] = {
    OPERAND_VAL_REG_64,
    OPERAND_VAL_RWIMAGE
};

unsigned PropDescImpl::OPERAND_VALUES_REG64_SAMPLER[] = {
    OPERAND_VAL_REG_64,
    OPERAND_VAL_SAMPLER
};

unsigned PropDescImpl::OPERAND_VALUES_REGV2CTYPE[] = {
    OPERAND_VAL_REG_V2
};

unsigned PropDescImpl::OPERAND_VALUES_REGV3CTYPE[] = {
    OPERAND_VAL_REG_V3
};

unsigned PropDescImpl::OPERAND_VALUES_REGV4[] = {
    OPERAND_VAL_REG_V4
};

unsigned PropDescImpl::OPERAND_VALUES_REGV432[] = {
    OPERAND_VAL_REG_V4_32
};

unsigned PropDescImpl::OPERATOR_VALUES_0[] = {
    Brig::BRIG_COMPARE_EQ,
    Brig::BRIG_COMPARE_EQU,
    Brig::BRIG_COMPARE_GE,
    Brig::BRIG_COMPARE_GEU,
    Brig::BRIG_COMPARE_GT,
    Brig::BRIG_COMPARE_GTU,
    Brig::BRIG_COMPARE_LE,
    Brig::BRIG_COMPARE_LEU,
    Brig::BRIG_COMPARE_LT,
    Brig::BRIG_COMPARE_LTU,
    Brig::BRIG_COMPARE_NAN,
    Brig::BRIG_COMPARE_NE,
    Brig::BRIG_COMPARE_NEU,
    Brig::BRIG_COMPARE_NUM,
    Brig::BRIG_COMPARE_SEQ,
    Brig::BRIG_COMPARE_SEQU,
    Brig::BRIG_COMPARE_SGE,
    Brig::BRIG_COMPARE_SGEU,
    Brig::BRIG_COMPARE_SGT,
    Brig::BRIG_COMPARE_SGTU,
    Brig::BRIG_COMPARE_SLE,
    Brig::BRIG_COMPARE_SLEU,
    Brig::BRIG_COMPARE_SLT,
    Brig::BRIG_COMPARE_SLTU,
    Brig::BRIG_COMPARE_SNAN,
    Brig::BRIG_COMPARE_SNE,
    Brig::BRIG_COMPARE_SNEU,
    Brig::BRIG_COMPARE_SNUM
};

unsigned PropDescImpl::OPERATOR_VALUES_EQ_NE_LT_LE_GT_GE[] = {
    Brig::BRIG_COMPARE_EQ,
    Brig::BRIG_COMPARE_GE,
    Brig::BRIG_COMPARE_GT,
    Brig::BRIG_COMPARE_LE,
    Brig::BRIG_COMPARE_LT,
    Brig::BRIG_COMPARE_NE
};

unsigned PropDescImpl::OPERATOR_VALUES_EQ_NE[] = {
    Brig::BRIG_COMPARE_EQ,
    Brig::BRIG_COMPARE_NE
};

unsigned PropDescImpl::PACKING_VALUES_NONE[] = {
    Brig::BRIG_PACK_NONE
};

unsigned PropDescImpl::PACKING_VALUES_P_S[] = {
    Brig::BRIG_PACK_P,
    Brig::BRIG_PACK_S
};

unsigned PropDescImpl::PACKING_VALUES_PP[] = {
    Brig::BRIG_PACK_PP
};

unsigned PropDescImpl::PACKING_VALUES_BIN[] = {
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PPSAT,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_PSSAT,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SPSAT,
    Brig::BRIG_PACK_SS,
    Brig::BRIG_PACK_SSSAT
};

unsigned PropDescImpl::PACKING_VALUES_BINNOSAT[] = {
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SS
};

unsigned PropDescImpl::ROUNDING_VALUES_FLOAT[] = {
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO
};

unsigned PropDescImpl::ROUNDING_VALUES_INT[] = {
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN_SAT,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_ZERO,
    Brig::BRIG_ROUND_INTEGER_ZERO_SAT
};

unsigned PropDescImpl::ROUNDING_VALUES_NONE[] = {
    Brig::BRIG_ROUND_NONE
};

unsigned PropDescImpl::SEGMENT_VALUES_GCN[] = {
    Brig::BRIG_SEGMENT_EXTSPACE0
};

unsigned PropDescImpl::SEGMENT_VALUES_ANY[] = {
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL
};

unsigned PropDescImpl::SEGMENT_VALUES_WRITABLE[] = {
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_SPILL
};

unsigned PropDescImpl::SEGMENT_VALUES_STD[] = {
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL
};

unsigned PropDescImpl::SEGMENT_VALUES_GLOBAL_GROUP_FLAT[] = {
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP
};

unsigned PropDescImpl::SEGMENT_VALUES_GLOBAL[] = {
    Brig::BRIG_SEGMENT_GLOBAL
};

unsigned PropDescImpl::SEGMENT_VALUES_PRIVATE[] = {
    Brig::BRIG_SEGMENT_PRIVATE
};

unsigned PropDescImpl::STYPESIZE_VALUES_MODEL[] = {
    STYPESIZE_VAL_MODEL
};

unsigned PropDescImpl::STYPESIZE_VALUES_SEG[] = {
    STYPESIZE_VAL_SEG
};

unsigned PropDescImpl::TYPE_VALUES_B1[] = {
    Brig::BRIG_TYPE_B1
};

unsigned PropDescImpl::TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_ROIMG_RWIMG_SAMP[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_SAMP,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_B1_B32_B64[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64
};

unsigned PropDescImpl::TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_X[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_B1_B32_B64_X[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_B1_S_U_F[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_B1_S16_U16_S32_U32_S64_U64_F[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_B1_S8_U8_S16_U16_S32_U32_F[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_B1_S8_U8_S16_U16_S64_U64_F[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_B1_S8_U8_S32_U32_S64_U64_F[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_B1_S32_U32_S64_U64_F_UX[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_B1_S32_U32_S64_U64_F[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_B1_S_U[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_U32_B1[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_U32
};

unsigned PropDescImpl::TYPE_VALUES_B128[] = {
    Brig::BRIG_TYPE_B128
};

unsigned PropDescImpl::TYPE_VALUES_B64_B128[] = {
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_B64
};

unsigned PropDescImpl::TYPE_VALUES_U_S_F_B128_ROIMG_RWIMG_SAMP[] = {
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_SAMP,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_U_S_F_B128[] = {
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_B128_ROIMG_RWIMG_SAMP[] = {
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_SAMP
};

unsigned PropDescImpl::TYPE_VALUES_B32[] = {
    Brig::BRIG_TYPE_B32
};

unsigned PropDescImpl::TYPE_VALUES_B32_B64[] = {
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64
};

unsigned PropDescImpl::TYPE_VALUES_B32_S32_U32_B64_S64_U64[] = {
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_B64[] = {
    Brig::BRIG_TYPE_B64
};

unsigned PropDescImpl::TYPE_VALUES_F16[] = {
    Brig::BRIG_TYPE_F16
};

unsigned PropDescImpl::TYPE_VALUES_F_FX[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2
};

unsigned PropDescImpl::TYPE_VALUES_S32_S64_SX_F_FX[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8
};

unsigned PropDescImpl::TYPE_VALUES_S32_U32_S64_U64_F_X[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_S32_U32_S64_U64_F_FX[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_F16_F32[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32
};

unsigned PropDescImpl::TYPE_VALUES_F[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64
};

unsigned PropDescImpl::TYPE_VALUES_U_S_F[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_S32_S64_F[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64
};

unsigned PropDescImpl::TYPE_VALUES_S32_U32_S64_U64_F[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_F16X[] = {
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8
};

unsigned PropDescImpl::TYPE_VALUES_FX[] = {
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64X2
};

unsigned PropDescImpl::TYPE_VALUES_SX_FX[] = {
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8
};

unsigned PropDescImpl::TYPE_VALUES_X[] = {
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_X32_X64[] = {
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_S16X2_U16X2_F16X2[] = {
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_U16X2
};

unsigned PropDescImpl::TYPE_VALUES_S16X4_U16X4_F16X4[] = {
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_U16X4
};

unsigned PropDescImpl::TYPE_VALUES_S16X8_U16X8_F16X8[] = {
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_U16X8
};

unsigned PropDescImpl::TYPE_VALUES_F32[] = {
    Brig::BRIG_TYPE_F32
};

unsigned PropDescImpl::TYPE_VALUES_F32_F64[] = {
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64
};

unsigned PropDescImpl::TYPE_VALUES_S32_F32[] = {
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32
};

unsigned PropDescImpl::TYPE_VALUES_S32_U32_F32[] = {
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32
};

unsigned PropDescImpl::TYPE_VALUES_F32X[] = {
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4
};

unsigned PropDescImpl::TYPE_VALUES_S32X2_U32X2_F32X2[] = {
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_U32X2
};

unsigned PropDescImpl::TYPE_VALUES_S32X4_U32X4_F32X4[] = {
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_U32X4
};

unsigned PropDescImpl::TYPE_VALUES_F64[] = {
    Brig::BRIG_TYPE_F64
};

unsigned PropDescImpl::TYPE_VALUES_F64X[] = {
    Brig::BRIG_TYPE_F64X2
};

unsigned PropDescImpl::TYPE_VALUES_S64X2_U64X2_F64X2[] = {
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_U64X2
};

unsigned PropDescImpl::TYPE_VALUES_NONE[] = {
    Brig::BRIG_TYPE_NONE
};

unsigned PropDescImpl::TYPE_VALUES_ROIMG[] = {
    Brig::BRIG_TYPE_ROIMG
};

unsigned PropDescImpl::TYPE_VALUES_ROIMG_RWIMG[] = {
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG
};

unsigned PropDescImpl::TYPE_VALUES_RWIMG[] = {
    Brig::BRIG_TYPE_RWIMG
};

unsigned PropDescImpl::TYPE_VALUES_S_U[] = {
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_S16_U16[] = {
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_U16
};

unsigned PropDescImpl::TYPE_VALUES_S32_U32_S64_U64_SX_UX[] = {
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_S8X_S16X_S32X_S64X[] = {
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8
};

unsigned PropDescImpl::TYPE_VALUES_SX_UX[] = {
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_S8X_S16X_S32X[] = {
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8
};

unsigned PropDescImpl::TYPE_VALUES_S32[] = {
    Brig::BRIG_TYPE_S32
};

unsigned PropDescImpl::TYPE_VALUES_S32_S64[] = {
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64
};

unsigned PropDescImpl::TYPE_VALUES_S32_U32_S64_U64[] = {
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_S32_U32[] = {
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32
};

unsigned PropDescImpl::TYPE_VALUES_S64[] = {
    Brig::BRIG_TYPE_S64
};

unsigned PropDescImpl::TYPE_VALUES_S64_U64[] = {
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_S64X[] = {
    Brig::BRIG_TYPE_S64X2
};

unsigned PropDescImpl::TYPE_VALUES_S8_U8[] = {
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U8
};

unsigned PropDescImpl::TYPE_VALUES_S8X16_U8X16[] = {
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_U8X16
};

unsigned PropDescImpl::TYPE_VALUES_S8X4_U8X4[] = {
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_U8X4
};

unsigned PropDescImpl::TYPE_VALUES_S8X8_U8X8[] = {
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_SAMP[] = {
    Brig::BRIG_TYPE_SAMP
};

unsigned PropDescImpl::TYPE_VALUES_U16X2[] = {
    Brig::BRIG_TYPE_U16X2
};

unsigned PropDescImpl::TYPE_VALUES_U8X_U16X_U32X_U64X[] = {
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_U8X_U16X_U32X[] = {
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPE_VALUES_U32_U8X4_U16X2[] = {
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U8X4
};

unsigned PropDescImpl::TYPE_VALUES_U16X4[] = {
    Brig::BRIG_TYPE_U16X4
};

unsigned PropDescImpl::TYPE_VALUES_U16X8[] = {
    Brig::BRIG_TYPE_U16X8
};

unsigned PropDescImpl::TYPE_VALUES_U32[] = {
    Brig::BRIG_TYPE_U32
};

unsigned PropDescImpl::TYPE_VALUES_U32_U64[] = {
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_U32X2[] = {
    Brig::BRIG_TYPE_U32X2
};

unsigned PropDescImpl::TYPE_VALUES_U32X4[] = {
    Brig::BRIG_TYPE_U32X4
};

unsigned PropDescImpl::TYPE_VALUES_U64[] = {
    Brig::BRIG_TYPE_U64
};

unsigned PropDescImpl::TYPE_VALUES_U64X[] = {
    Brig::BRIG_TYPE_U64X2
};

unsigned PropDescImpl::TYPE_VALUES_U8X16[] = {
    Brig::BRIG_TYPE_U8X16
};

unsigned PropDescImpl::TYPE_VALUES_U8X4[] = {
    Brig::BRIG_TYPE_U8X4
};

unsigned PropDescImpl::TYPE_VALUES_U8X8[] = {
    Brig::BRIG_TYPE_U8X8
};

unsigned PropDescImpl::TYPESIZE_VALUES_ATOMIC[] = {
    TYPESIZE_VAL_ATOMIC
};

unsigned PropDescImpl::TYPESIZE_VALUES_MODEL[] = {
    TYPESIZE_VAL_MODEL
};

unsigned PropDescImpl::TYPESIZE_VALUES_SEG[] = {
    TYPESIZE_VAL_SEG
};

unsigned PropDescImpl::WIDTH_VALUES_ANY[] = {
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE
};

unsigned PropDescImpl::WIDTH_VALUES_ALL[] = {
    Brig::BRIG_WIDTH_ALL
};

unsigned PropDescImpl::WIDTH_VALUES_NONE[] = {
    Brig::BRIG_WIDTH_NONE
};

bool PropDescImpl::check_align_values_any(unsigned val)
{
    switch(val)
    {    
    case 0:
    case 1:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_generic_exch_ld(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_ADD:
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_CAS:
    case Brig::BRIG_ATOMIC_DEC:
    case Brig::BRIG_ATOMIC_EXCH:
    case Brig::BRIG_ATOMIC_INC:
    case Brig::BRIG_ATOMIC_LD:
    case Brig::BRIG_ATOMIC_MAX:
    case Brig::BRIG_ATOMIC_MIN:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_SUB:
    case Brig::BRIG_ATOMIC_XOR:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_generic_exch(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_ADD:
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_CAS:
    case Brig::BRIG_ATOMIC_DEC:
    case Brig::BRIG_ATOMIC_EXCH:
    case Brig::BRIG_ATOMIC_INC:
    case Brig::BRIG_ATOMIC_MAX:
    case Brig::BRIG_ATOMIC_MIN:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_SUB:
    case Brig::BRIG_ATOMIC_XOR:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_generic_st(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_ADD:
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_CAS:
    case Brig::BRIG_ATOMIC_DEC:
    case Brig::BRIG_ATOMIC_INC:
    case Brig::BRIG_ATOMIC_MAX:
    case Brig::BRIG_ATOMIC_MIN:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_ST:
    case Brig::BRIG_ATOMIC_SUB:
    case Brig::BRIG_ATOMIC_XOR:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_generic(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_ADD:
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_CAS:
    case Brig::BRIG_ATOMIC_DEC:
    case Brig::BRIG_ATOMIC_INC:
    case Brig::BRIG_ATOMIC_MAX:
    case Brig::BRIG_ATOMIC_MIN:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_SUB:
    case Brig::BRIG_ATOMIC_XOR:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_add_sub_min_max(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_ADD:
    case Brig::BRIG_ATOMIC_MAX:
    case Brig::BRIG_ATOMIC_MIN:
    case Brig::BRIG_ATOMIC_SUB:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_and_or_xor_exch(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_EXCH:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_XOR:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_and_or_xor(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_XOR:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_cas(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_CAS:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_inc_dec(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_DEC:
    case Brig::BRIG_ATOMIC_INC:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_ld(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_LD:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_atmop_values_st(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_ST:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_ftz_values_none(unsigned val)
{
    switch(val)
    {    
    case 0:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_ftz_values_any(unsigned val)
{
    switch(val)
    {    
    case 0:
    case 1:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_geom_values_1d(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_GEOMETRY_1D:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_geom_values_1d_2d_3d_1db_1da_2da(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_GEOMETRY_1D:
    case Brig::BRIG_GEOMETRY_1DA:
    case Brig::BRIG_GEOMETRY_1DB:
    case Brig::BRIG_GEOMETRY_2D:
    case Brig::BRIG_GEOMETRY_2DA:
    case Brig::BRIG_GEOMETRY_3D:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_geom_values_1d_2d_3d_1da_2da(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_GEOMETRY_1D:
    case Brig::BRIG_GEOMETRY_1DA:
    case Brig::BRIG_GEOMETRY_2D:
    case Brig::BRIG_GEOMETRY_2DA:
    case Brig::BRIG_GEOMETRY_3D:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_geom_values_1d_1db(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_GEOMETRY_1D:
    case Brig::BRIG_GEOMETRY_1DB:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_geom_values_2d_1da(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_GEOMETRY_1DA:
    case Brig::BRIG_GEOMETRY_2D:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_geom_values_3d_2da(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_GEOMETRY_2DA:
    case Brig::BRIG_GEOMETRY_3D:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_memfnc_values_any(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_MEMORY_FENCE_BOTH:
    case Brig::BRIG_MEMORY_FENCE_GLOBAL:
    case Brig::BRIG_MEMORY_FENCE_GROUP:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_memfnc_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_MEMORY_FENCE_NONE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_memord_values_any(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_MEMORY_ORDER_ACQUIRE:
    case Brig::BRIG_MEMORY_ORDER_ACQUIRE_RELEASE:
    case Brig::BRIG_MEMORY_ORDER_RELAXED:
    case Brig::BRIG_MEMORY_ORDER_RELEASE:
    case Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_memord_values_ld(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_MEMORY_ORDER_ACQUIRE:
    case Brig::BRIG_MEMORY_ORDER_RELAXED:
    case Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_memord_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_MEMORY_ORDER_NONE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_memord_values_st(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_MEMORY_ORDER_RELAXED:
    case Brig::BRIG_MEMORY_ORDER_RELEASE:
    case Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_memscp_values_any(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_MEMORY_SCOPE_COMPONENT:
    case Brig::BRIG_MEMORY_SCOPE_SYSTEM:
    case Brig::BRIG_MEMORY_SCOPE_WORKGROUP:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_memscp_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_MEMORY_SCOPE_NONE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_operator_values_0(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_COMPARE_EQ:
    case Brig::BRIG_COMPARE_EQU:
    case Brig::BRIG_COMPARE_GE:
    case Brig::BRIG_COMPARE_GEU:
    case Brig::BRIG_COMPARE_GT:
    case Brig::BRIG_COMPARE_GTU:
    case Brig::BRIG_COMPARE_LE:
    case Brig::BRIG_COMPARE_LEU:
    case Brig::BRIG_COMPARE_LT:
    case Brig::BRIG_COMPARE_LTU:
    case Brig::BRIG_COMPARE_NAN:
    case Brig::BRIG_COMPARE_NE:
    case Brig::BRIG_COMPARE_NEU:
    case Brig::BRIG_COMPARE_NUM:
    case Brig::BRIG_COMPARE_SEQ:
    case Brig::BRIG_COMPARE_SEQU:
    case Brig::BRIG_COMPARE_SGE:
    case Brig::BRIG_COMPARE_SGEU:
    case Brig::BRIG_COMPARE_SGT:
    case Brig::BRIG_COMPARE_SGTU:
    case Brig::BRIG_COMPARE_SLE:
    case Brig::BRIG_COMPARE_SLEU:
    case Brig::BRIG_COMPARE_SLT:
    case Brig::BRIG_COMPARE_SLTU:
    case Brig::BRIG_COMPARE_SNAN:
    case Brig::BRIG_COMPARE_SNE:
    case Brig::BRIG_COMPARE_SNEU:
    case Brig::BRIG_COMPARE_SNUM:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_operator_values_eq_ne_lt_le_gt_ge(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_COMPARE_EQ:
    case Brig::BRIG_COMPARE_GE:
    case Brig::BRIG_COMPARE_GT:
    case Brig::BRIG_COMPARE_LE:
    case Brig::BRIG_COMPARE_LT:
    case Brig::BRIG_COMPARE_NE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_operator_values_eq_ne(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_COMPARE_EQ:
    case Brig::BRIG_COMPARE_NE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_packing_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_PACK_NONE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_packing_values_p_s(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_PACK_P:
    case Brig::BRIG_PACK_S:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_packing_values_pp(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_PACK_PP:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_packing_values_bin(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_PACK_PP:
    case Brig::BRIG_PACK_PPSAT:
    case Brig::BRIG_PACK_PS:
    case Brig::BRIG_PACK_PSSAT:
    case Brig::BRIG_PACK_SP:
    case Brig::BRIG_PACK_SPSAT:
    case Brig::BRIG_PACK_SS:
    case Brig::BRIG_PACK_SSSAT:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_packing_values_binnosat(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_PACK_PP:
    case Brig::BRIG_PACK_PS:
    case Brig::BRIG_PACK_SP:
    case Brig::BRIG_PACK_SS:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_rounding_values_float(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY:
    case Brig::BRIG_ROUND_FLOAT_NEAR_EVEN:
    case Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY:
    case Brig::BRIG_ROUND_FLOAT_ZERO:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_rounding_values_int(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY:
    case Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT:
    case Brig::BRIG_ROUND_INTEGER_NEAR_EVEN:
    case Brig::BRIG_ROUND_INTEGER_NEAR_EVEN_SAT:
    case Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY:
    case Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT:
    case Brig::BRIG_ROUND_INTEGER_ZERO:
    case Brig::BRIG_ROUND_INTEGER_ZERO_SAT:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_rounding_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ROUND_NONE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_segment_values_gcn(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_EXTSPACE0:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_segment_values_any(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_ARG:
    case Brig::BRIG_SEGMENT_FLAT:
    case Brig::BRIG_SEGMENT_GLOBAL:
    case Brig::BRIG_SEGMENT_GROUP:
    case Brig::BRIG_SEGMENT_KERNARG:
    case Brig::BRIG_SEGMENT_PRIVATE:
    case Brig::BRIG_SEGMENT_READONLY:
    case Brig::BRIG_SEGMENT_SPILL:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_segment_values_writable(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_ARG:
    case Brig::BRIG_SEGMENT_FLAT:
    case Brig::BRIG_SEGMENT_GLOBAL:
    case Brig::BRIG_SEGMENT_GROUP:
    case Brig::BRIG_SEGMENT_PRIVATE:
    case Brig::BRIG_SEGMENT_SPILL:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_segment_values_std(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_ARG:
    case Brig::BRIG_SEGMENT_GLOBAL:
    case Brig::BRIG_SEGMENT_GROUP:
    case Brig::BRIG_SEGMENT_KERNARG:
    case Brig::BRIG_SEGMENT_PRIVATE:
    case Brig::BRIG_SEGMENT_READONLY:
    case Brig::BRIG_SEGMENT_SPILL:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_segment_values_global_group_flat(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_FLAT:
    case Brig::BRIG_SEGMENT_GLOBAL:
    case Brig::BRIG_SEGMENT_GROUP:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_segment_values_global(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_GLOBAL:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_segment_values_private(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_PRIVATE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_roimg_rwimg_samp(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_SAMP:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_b32_b64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_b32_s32_u32_b64_s64_u64_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_b32_b64_x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_s_u_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_s16_u16_s32_u32_s64_u64_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_s8_u8_s16_u16_s32_u32_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_s8_u8_s16_u16_s64_u64_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_s8_u8_s32_u32_s64_u64_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_s32_u32_s64_u64_f_ux(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_s32_u32_s64_u64_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b1_s_u(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u32_b1(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_U32:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b128(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B128:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b64_b128(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_B64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u_s_f_b128_roimg_rwimg_samp(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_SAMP:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u_s_f_b128(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b128_roimg_rwimg_samp(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_SAMP:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B32:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b32_b64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b32_s32_u32_b64_s64_u64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_b64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f16(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f_fx(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_F64X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_s64_sx_f_fx(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_u32_s64_u64_f_x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_u32_s64_u64_f_fx(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f16_f32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u_s_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_s64_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_u32_s64_u64_f(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f16x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_fx(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_sx_fx(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_x32_x64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s16x2_u16x2_f16x2(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_U16X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s16x4_u16x4_f16x4(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_U16X4:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s16x8_u16x8_f16x8(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_U16X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F32:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f32_f64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_f32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_S32:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_u32_f32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_U32:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f32x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32x2_u32x2_f32x2(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_U32X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32x4_u32x4_f32x4(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_U32X4:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_f64x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F64X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s64x2_u64x2_f64x2(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_U64X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_NONE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_roimg(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_ROIMG:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_roimg_rwimg(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_rwimg(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_RWIMG:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s_u(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s16_u16(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_U16:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_u32_s64_u64_sx_ux(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s8x_s16x_s32x_s64x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_sx_ux(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s8x_s16x_s32x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S32:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_s64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_u32_s64_u64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s32_u32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_U32:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s64_u64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s64x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S64X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s8_u8(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_U8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s8x16_u8x16(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_U8X16:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s8x4_u8x4(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_U8X4:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_s8x8_u8x8(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_samp(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_SAMP:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u16x2(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U16X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u8x_u16x_u32x_u64x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u8x_u16x_u32x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u32_u8x4_u16x2(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U8X4:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u16x4(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U16X4:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u16x8(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U16X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U32:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u32_u64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u32x2(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U32X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u32x4(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U32X4:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u64x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U64X2:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u8x16(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U8X16:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u8x4(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U8X4:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_type_values_u8x8(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_width_values_any(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_WIDTH_1:
    case Brig::BRIG_WIDTH_1024:
    case Brig::BRIG_WIDTH_1048576:
    case Brig::BRIG_WIDTH_1073741824:
    case Brig::BRIG_WIDTH_128:
    case Brig::BRIG_WIDTH_131072:
    case Brig::BRIG_WIDTH_134217728:
    case Brig::BRIG_WIDTH_16:
    case Brig::BRIG_WIDTH_16384:
    case Brig::BRIG_WIDTH_16777216:
    case Brig::BRIG_WIDTH_2:
    case Brig::BRIG_WIDTH_2048:
    case Brig::BRIG_WIDTH_2097152:
    case Brig::BRIG_WIDTH_2147483648:
    case Brig::BRIG_WIDTH_256:
    case Brig::BRIG_WIDTH_262144:
    case Brig::BRIG_WIDTH_268435456:
    case Brig::BRIG_WIDTH_32:
    case Brig::BRIG_WIDTH_32768:
    case Brig::BRIG_WIDTH_33554432:
    case Brig::BRIG_WIDTH_4:
    case Brig::BRIG_WIDTH_4096:
    case Brig::BRIG_WIDTH_4194304:
    case Brig::BRIG_WIDTH_512:
    case Brig::BRIG_WIDTH_524288:
    case Brig::BRIG_WIDTH_536870912:
    case Brig::BRIG_WIDTH_64:
    case Brig::BRIG_WIDTH_65536:
    case Brig::BRIG_WIDTH_67108864:
    case Brig::BRIG_WIDTH_8:
    case Brig::BRIG_WIDTH_8192:
    case Brig::BRIG_WIDTH_8388608:
    case Brig::BRIG_WIDTH_ALL:
    case Brig::BRIG_WIDTH_WAVESIZE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_width_values_all(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_WIDTH_ALL:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::check_width_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_WIDTH_NONE:
        return true;
    default: 
        return false;
    }
}

bool PropDescImpl::isBrigProp(unsigned propId)
{
    switch(propId)
    {
    case PROP_WIDTH: return true;
    case PROP_MEMSCP: return true;
    case PROP_MEMORD: return true;
    case PROP_GEOM: return true;
    case PROP_ATMOP: return true;
    case PROP_OPERAND: return false;
    case PROP_SEGMENT: return true;
    case PROP_OPERATOR: return true;
    case PROP_TYPESIZE: return false;
    case PROP_STYPESIZE: return false;
    case PROP_PACKING: return true;
    case PROP_ALIGN: return true;
    case PROP_MEMFNC: return true;
    case PROP_EQCLASS: return false;
    case PROP_ROUNDING: return true;
    case PROP_FTZ: return true;
    case PROP_TYPE: return true;
    case PROP_S1: return false;
    case PROP_CTYPE: return true;
    case PROP_D1: return false;
    case PROP_S4: return false;
    case PROP_STYPE: return true;
    case PROP_S0: return false;
    case PROP_S2: return false;
    case PROP_S3: return false;
    case PROP_D0: return false;
    case PROP_ITYPE: return true;
    }
    assert(false);
    return false;
}

unsigned PropDescImpl::OPCODES[] = 
{
    Brig::BRIG_OPCODE_ADD,
    Brig::BRIG_OPCODE_SUB,
    Brig::BRIG_OPCODE_MAX,
    Brig::BRIG_OPCODE_MIN,
    Brig::BRIG_OPCODE_MUL,
    Brig::BRIG_OPCODE_MULHI,
    Brig::BRIG_OPCODE_DIV,
    Brig::BRIG_OPCODE_REM,
    Brig::BRIG_OPCODE_CARRY,
    Brig::BRIG_OPCODE_BORROW,
    Brig::BRIG_OPCODE_NEG,
    Brig::BRIG_OPCODE_ABS,
    Brig::BRIG_OPCODE_COPYSIGN,
    Brig::BRIG_OPCODE_FRACT,
    Brig::BRIG_OPCODE_SQRT,
    Brig::BRIG_OPCODE_CEIL,
    Brig::BRIG_OPCODE_FLOOR,
    Brig::BRIG_OPCODE_RINT,
    Brig::BRIG_OPCODE_TRUNC,
    Brig::BRIG_OPCODE_MUL24,
    Brig::BRIG_OPCODE_MUL24HI,
    Brig::BRIG_OPCODE_MAD24,
    Brig::BRIG_OPCODE_MAD24HI,
    Brig::BRIG_OPCODE_MAD,
    Brig::BRIG_OPCODE_FMA,
    Brig::BRIG_OPCODE_SHL,
    Brig::BRIG_OPCODE_SHR,
    Brig::BRIG_OPCODE_AND,
    Brig::BRIG_OPCODE_OR,
    Brig::BRIG_OPCODE_XOR,
    Brig::BRIG_OPCODE_NOT,
    Brig::BRIG_OPCODE_POPCOUNT,
    Brig::BRIG_OPCODE_BITMASK,
    Brig::BRIG_OPCODE_BITSELECT,
    Brig::BRIG_OPCODE_BITREV,
    Brig::BRIG_OPCODE_BITEXTRACT,
    Brig::BRIG_OPCODE_BITINSERT,
    Brig::BRIG_OPCODE_FIRSTBIT,
    Brig::BRIG_OPCODE_LASTBIT,
    Brig::BRIG_OPCODE_COMBINE,
    Brig::BRIG_OPCODE_EXPAND,
    Brig::BRIG_OPCODE_MOV,
    Brig::BRIG_OPCODE_LDA,
    Brig::BRIG_OPCODE_LDC,
    Brig::BRIG_OPCODE_SHUFFLE,
    Brig::BRIG_OPCODE_UNPACKLO,
    Brig::BRIG_OPCODE_UNPACKHI,
    Brig::BRIG_OPCODE_PACK,
    Brig::BRIG_OPCODE_UNPACK,
    Brig::BRIG_OPCODE_CMOV,
    Brig::BRIG_OPCODE_CLASS,
    Brig::BRIG_OPCODE_NSIN,
    Brig::BRIG_OPCODE_NCOS,
    Brig::BRIG_OPCODE_NLOG2,
    Brig::BRIG_OPCODE_NEXP2,
    Brig::BRIG_OPCODE_NSQRT,
    Brig::BRIG_OPCODE_NRSQRT,
    Brig::BRIG_OPCODE_NRCP,
    Brig::BRIG_OPCODE_NFMA,
    Brig::BRIG_OPCODE_BITALIGN,
    Brig::BRIG_OPCODE_BYTEALIGN,
    Brig::BRIG_OPCODE_LERP,
    Brig::BRIG_OPCODE_SAD,
    Brig::BRIG_OPCODE_SADHI,
    Brig::BRIG_OPCODE_PACKCVT,
    Brig::BRIG_OPCODE_UNPACKCVT,
    Brig::BRIG_OPCODE_SEGMENTP,
    Brig::BRIG_OPCODE_FTOS,
    Brig::BRIG_OPCODE_STOF,
    Brig::BRIG_OPCODE_CMP,
    Brig::BRIG_OPCODE_CVT,
    Brig::BRIG_OPCODE_LD,
    Brig::BRIG_OPCODE_ST,
    Brig::BRIG_OPCODE_ATOMIC,
    Brig::BRIG_OPCODE_ATOMICNORET,
    Brig::BRIG_OPCODE_RDIMAGE,
    Brig::BRIG_OPCODE_LDIMAGE,
    Brig::BRIG_OPCODE_STIMAGE,
    Brig::BRIG_OPCODE_ATOMICIMAGE,
    Brig::BRIG_OPCODE_ATOMICIMAGENORET,
    Brig::BRIG_OPCODE_QUERYIMAGEWIDTH,
    Brig::BRIG_OPCODE_QUERYIMAGEHEIGHT,
    Brig::BRIG_OPCODE_QUERYIMAGEDEPTH,
    Brig::BRIG_OPCODE_QUERYIMAGEARRAY,
    Brig::BRIG_OPCODE_QUERYIMAGEORDER,
    Brig::BRIG_OPCODE_QUERYIMAGEFORMAT,
    Brig::BRIG_OPCODE_QUERYSAMPLERCOORD,
    Brig::BRIG_OPCODE_QUERYSAMPLERFILTER,
    Brig::BRIG_OPCODE_QUERYSAMPLERBOUNDARY,
    Brig::BRIG_OPCODE_CBR,
    Brig::BRIG_OPCODE_BRN,
    Brig::BRIG_OPCODE_BARRIER,
    Brig::BRIG_OPCODE_INITFBAR,
    Brig::BRIG_OPCODE_RELEASEFBAR,
    Brig::BRIG_OPCODE_JOINFBAR,
    Brig::BRIG_OPCODE_LEAVEFBAR,
    Brig::BRIG_OPCODE_WAITFBAR,
    Brig::BRIG_OPCODE_ARRIVEFBAR,
    Brig::BRIG_OPCODE_LDF,
    Brig::BRIG_OPCODE_SYNC,
    Brig::BRIG_OPCODE_MASKLANE,
    Brig::BRIG_OPCODE_COUNTLANE,
    Brig::BRIG_OPCODE_COUNTUPLANE,
    Brig::BRIG_OPCODE_SENDLANE,
    Brig::BRIG_OPCODE_RECEIVELANE,
    Brig::BRIG_OPCODE_CALL,
    Brig::BRIG_OPCODE_RET,
    Brig::BRIG_OPCODE_SYSCALL,
    Brig::BRIG_OPCODE_ALLOCA,
    Brig::BRIG_OPCODE_CUID,
    Brig::BRIG_OPCODE_DIM,
    Brig::BRIG_OPCODE_GETDETECTEXCEPT,
    Brig::BRIG_OPCODE_LANEID,
    Brig::BRIG_OPCODE_MAXCUID,
    Brig::BRIG_OPCODE_MAXWAVEID,
    Brig::BRIG_OPCODE_QID,
    Brig::BRIG_OPCODE_WAVEID,
    Brig::BRIG_OPCODE_WORKITEMFLATABSID,
    Brig::BRIG_OPCODE_WORKITEMFLATID,
    Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE,
    Brig::BRIG_OPCODE_GRIDGROUPS,
    Brig::BRIG_OPCODE_GRIDSIZE,
    Brig::BRIG_OPCODE_WORKGROUPID,
    Brig::BRIG_OPCODE_WORKGROUPSIZE,
    Brig::BRIG_OPCODE_WORKITEMABSID,
    Brig::BRIG_OPCODE_WORKITEMID,
    Brig::BRIG_OPCODE_CLEARDETECTEXCEPT,
    Brig::BRIG_OPCODE_SETDETECTEXCEPT,
    Brig::BRIG_OPCODE_CLOCK,
    Brig::BRIG_OPCODE_DISPATCHID,
    Brig::BRIG_OPCODE_NOP,
    Brig::BRIG_OPCODE_DISPATCHPTR,
    Brig::BRIG_OPCODE_QPTR,
    Brig::BRIG_OPCODE_NULLPTR,
    Brig::BRIG_OPCODE_DEBUGTRAP,
    Brig::BRIG_OPCODE_CODEBLOCKEND,
    Brig::BRIG_OPCODE_GCNMADU,
    Brig::BRIG_OPCODE_GCNMADS,
    Brig::BRIG_OPCODE_GCNMIN3,
    Brig::BRIG_OPCODE_GCNMED3,
    Brig::BRIG_OPCODE_GCNMAX3,
    Brig::BRIG_OPCODE_GCNBFM,
    Brig::BRIG_OPCODE_GCNFLDEXP,
    Brig::BRIG_OPCODE_GCNFREXP_EXP,
    Brig::BRIG_OPCODE_GCNFREXP_MANT,
    Brig::BRIG_OPCODE_GCNTRIG_PREOP,
    Brig::BRIG_OPCODE_GCNREGIONALLOC,
    Brig::BRIG_OPCODE_GCNLD,
    Brig::BRIG_OPCODE_GCNST,
    Brig::BRIG_OPCODE_GCNATOMIC,
    Brig::BRIG_OPCODE_GCNATOMICNORET,
    Brig::BRIG_OPCODE_GCNAPPEND,
    Brig::BRIG_OPCODE_GCNCONSUME,
    Brig::BRIG_OPCODE_GCNMSAD,
    Brig::BRIG_OPCODE_GCNSADW,
    Brig::BRIG_OPCODE_GCNSADD,
    Brig::BRIG_OPCODE_GCNQSAD,
    Brig::BRIG_OPCODE_GCNMQSAD,
    Brig::BRIG_OPCODE_GCNMQSAD4,
    Brig::BRIG_OPCODE_GCNSLEEP,
    Brig::BRIG_OPCODE_GCNPRIORITY,
    Brig::BRIG_OPCODE_GCNB4XCHG,
    Brig::BRIG_OPCODE_GCNB32XCHG,
};

const unsigned* PropDescImpl::getOpcodes(unsigned& num)
{
    num = sizeof(OPCODES) / sizeof(unsigned);
    return OPCODES;
}

unsigned PropDescImpl::getFormat(unsigned opcode)
{
    switch(opcode)
    {
    case Brig::BRIG_OPCODE_ABS: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_ADD: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_ALLOCA: return Brig::BRIG_INST_SEG;
    case Brig::BRIG_OPCODE_AND: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_ARRIVEFBAR: return Brig::BRIG_INST_BAR;
    case Brig::BRIG_OPCODE_ATOMIC: return Brig::BRIG_INST_ATOMIC;
    case Brig::BRIG_OPCODE_ATOMICIMAGE: return Brig::BRIG_INST_ATOMIC_IMAGE;
    case Brig::BRIG_OPCODE_ATOMICIMAGENORET: return Brig::BRIG_INST_ATOMIC_IMAGE;
    case Brig::BRIG_OPCODE_ATOMICNORET: return Brig::BRIG_INST_ATOMIC;
    case Brig::BRIG_OPCODE_BARRIER: return Brig::BRIG_INST_BAR;
    case Brig::BRIG_OPCODE_BITALIGN: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_BITEXTRACT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_BITINSERT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_BITMASK: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_BITREV: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_BITSELECT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_BORROW: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_BRN: return Brig::BRIG_INST_BR;
    case Brig::BRIG_OPCODE_BYTEALIGN: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_CALL: return Brig::BRIG_INST_BR;
    case Brig::BRIG_OPCODE_CARRY: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_CBR: return Brig::BRIG_INST_BR;
    case Brig::BRIG_OPCODE_CEIL: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_CLASS: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_CLEARDETECTEXCEPT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_CLOCK: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_CMOV: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_CMP: return Brig::BRIG_INST_CMP;
    case Brig::BRIG_OPCODE_CODEBLOCKEND: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_COMBINE: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_COPYSIGN: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_COUNTLANE: return Brig::BRIG_INST_LANE;
    case Brig::BRIG_OPCODE_COUNTUPLANE: return Brig::BRIG_INST_LANE;
    case Brig::BRIG_OPCODE_CUID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_CVT: return Brig::BRIG_INST_CVT;
    case Brig::BRIG_OPCODE_DEBUGTRAP: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_DIM: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_DISPATCHID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_DISPATCHPTR: return Brig::BRIG_INST_SEG;
    case Brig::BRIG_OPCODE_DIV: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_EXPAND: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_FIRSTBIT: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_FLOOR: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_FMA: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_FRACT: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_FTOS: return Brig::BRIG_INST_SEG;
    case Brig::BRIG_OPCODE_GCNAPPEND: return Brig::BRIG_INST_ADDR;
    case Brig::BRIG_OPCODE_GCNATOMIC: return Brig::BRIG_INST_ATOMIC;
    case Brig::BRIG_OPCODE_GCNATOMICNORET: return Brig::BRIG_INST_ATOMIC;
    case Brig::BRIG_OPCODE_GCNB32XCHG: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNB4XCHG: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNBFM: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNCONSUME: return Brig::BRIG_INST_ADDR;
    case Brig::BRIG_OPCODE_GCNFLDEXP: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNFREXP_EXP: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNFREXP_MANT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNLD: return Brig::BRIG_INST_MEM;
    case Brig::BRIG_OPCODE_GCNMADS: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNMADU: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNMAX3: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNMED3: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNMIN3: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNMQSAD: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNMQSAD4: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNMSAD: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNPRIORITY: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNQSAD: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNREGIONALLOC: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNSADD: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNSADW: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNSLEEP: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GCNST: return Brig::BRIG_INST_MEM;
    case Brig::BRIG_OPCODE_GCNTRIG_PREOP: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GETDETECTEXCEPT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GRIDGROUPS: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_GRIDSIZE: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_INITFBAR: return Brig::BRIG_INST_BAR;
    case Brig::BRIG_OPCODE_JOINFBAR: return Brig::BRIG_INST_BAR;
    case Brig::BRIG_OPCODE_LANEID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_LASTBIT: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_LD: return Brig::BRIG_INST_MEM;
    case Brig::BRIG_OPCODE_LDA: return Brig::BRIG_INST_ADDR;
    case Brig::BRIG_OPCODE_LDC: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_LDF: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_LDIMAGE: return Brig::BRIG_INST_IMAGE;
    case Brig::BRIG_OPCODE_LEAVEFBAR: return Brig::BRIG_INST_BAR;
    case Brig::BRIG_OPCODE_LERP: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_MAD: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_MAD24: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_MAD24HI: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_MASKLANE: return Brig::BRIG_INST_LANE;
    case Brig::BRIG_OPCODE_MAX: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_MAXCUID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_MAXWAVEID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_MIN: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_MOV: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_MUL: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_MUL24: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_MUL24HI: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_MULHI: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_NCOS: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NEG: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_NEXP2: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NFMA: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NLOG2: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NOP: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NOT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NRCP: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NRSQRT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NSIN: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NSQRT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_NULLPTR: return Brig::BRIG_INST_SEG;
    case Brig::BRIG_OPCODE_OR: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_PACK: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_PACKCVT: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_POPCOUNT: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_QID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_QPTR: return Brig::BRIG_INST_SEG;
    case Brig::BRIG_OPCODE_QUERYIMAGEARRAY: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_QUERYIMAGEDEPTH: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_QUERYIMAGEFORMAT: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_QUERYIMAGEHEIGHT: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_QUERYIMAGEORDER: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_QUERYIMAGEWIDTH: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_QUERYSAMPLERBOUNDARY: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_QUERYSAMPLERCOORD: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_QUERYSAMPLERFILTER: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_RDIMAGE: return Brig::BRIG_INST_IMAGE;
    case Brig::BRIG_OPCODE_RECEIVELANE: return Brig::BRIG_INST_LANE;
    case Brig::BRIG_OPCODE_RELEASEFBAR: return Brig::BRIG_INST_BAR;
    case Brig::BRIG_OPCODE_REM: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_RET: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_RINT: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_SAD: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_SADHI: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_SEGMENTP: return Brig::BRIG_INST_SEG;
    case Brig::BRIG_OPCODE_SENDLANE: return Brig::BRIG_INST_LANE;
    case Brig::BRIG_OPCODE_SETDETECTEXCEPT: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_SHL: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_SHR: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_SHUFFLE: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_SQRT: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_ST: return Brig::BRIG_INST_MEM;
    case Brig::BRIG_OPCODE_STIMAGE: return Brig::BRIG_INST_IMAGE;
    case Brig::BRIG_OPCODE_STOF: return Brig::BRIG_INST_SEG;
    case Brig::BRIG_OPCODE_SUB: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_SYNC: return Brig::BRIG_INST_BAR;
    case Brig::BRIG_OPCODE_SYSCALL: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_TRUNC: return Brig::BRIG_INST_MOD;
    case Brig::BRIG_OPCODE_UNPACK: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_UNPACKCVT: return Brig::BRIG_INST_SOURCE_TYPE;
    case Brig::BRIG_OPCODE_UNPACKHI: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_UNPACKLO: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_WAITFBAR: return Brig::BRIG_INST_BAR;
    case Brig::BRIG_OPCODE_WAVEID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_WORKGROUPID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_WORKGROUPSIZE: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_WORKITEMABSID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_WORKITEMFLATABSID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_WORKITEMFLATID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_WORKITEMID: return Brig::BRIG_INST_BASIC;
    case Brig::BRIG_OPCODE_XOR: return Brig::BRIG_INST_BASIC;
    }

    assert(false);
    return (unsigned)-1;
}

unsigned PropDescImpl::PROP_VALUES_WIDTH[] = 
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_NONE,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::PROP_VALUES_MEMSCP[] = 
{
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_NONE,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
};

unsigned PropDescImpl::PROP_VALUES_MEMORD[] = 
{
    Brig::BRIG_MEMORY_ORDER_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_ACQUIRE_RELEASE,
    Brig::BRIG_MEMORY_ORDER_NONE,
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT,
};

unsigned PropDescImpl::PROP_VALUES_GEOM[] = 
{
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_1DB,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D,
};

unsigned PropDescImpl::PROP_VALUES_ATMOP[] = 
{
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_LD,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_ST,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR,
};

unsigned PropDescImpl::PROP_VALUES_OPERAND[] = 
{
    OPERAND_VAL_ADDR_SEG,
    OPERAND_VAL_ADDR_TSEG,
    OPERAND_VAL_ARGLIST,
    OPERAND_VAL_CALLTAB,
    OPERAND_VAL_FBARRIER,
    OPERAND_VAL_FUNC,
    OPERAND_VAL_IMM_0_1_2,
    OPERAND_VAL_IMM_0_1_2_3,
    OPERAND_VAL_IMM_1,
    OPERAND_VAL_IMM_128,
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_IMM_64,
    OPERAND_VAL_IMM,
    OPERAND_VAL_JUMPTAB,
    OPERAND_VAL_LAB,
    OPERAND_VAL_NULL,
    OPERAND_VAL_REG_1,
    OPERAND_VAL_REG_128,
    OPERAND_VAL_REG_32,
    OPERAND_VAL_REG_64,
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2_1,
    OPERAND_VAL_REG_V2_128,
    OPERAND_VAL_REG_V2_32,
    OPERAND_VAL_REG_V2_64,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3_1,
    OPERAND_VAL_REG_V3_128,
    OPERAND_VAL_REG_V3_32,
    OPERAND_VAL_REG_V3_64,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4_1,
    OPERAND_VAL_REG_V4_128,
    OPERAND_VAL_REG_V4_32,
    OPERAND_VAL_REG_V4_64,
    OPERAND_VAL_REG_V4,
    OPERAND_VAL_ROIMAGE,
    OPERAND_VAL_RWIMAGE,
    OPERAND_VAL_SAMPLER,
    OPERAND_VAL_INVALID,
};

unsigned PropDescImpl::PROP_VALUES_SEGMENT[] = 
{
    Brig::BRIG_SEGMENT_EXTSPACE0,
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_NONE,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL,
};

unsigned PropDescImpl::PROP_VALUES_OPERATOR[] = 
{
    Brig::BRIG_COMPARE_EQ,
    Brig::BRIG_COMPARE_EQU,
    Brig::BRIG_COMPARE_GE,
    Brig::BRIG_COMPARE_GEU,
    Brig::BRIG_COMPARE_GT,
    Brig::BRIG_COMPARE_GTU,
    Brig::BRIG_COMPARE_LE,
    Brig::BRIG_COMPARE_LEU,
    Brig::BRIG_COMPARE_LT,
    Brig::BRIG_COMPARE_LTU,
    Brig::BRIG_COMPARE_NAN,
    Brig::BRIG_COMPARE_NE,
    Brig::BRIG_COMPARE_NEU,
    Brig::BRIG_COMPARE_NUM,
    Brig::BRIG_COMPARE_SEQ,
    Brig::BRIG_COMPARE_SEQU,
    Brig::BRIG_COMPARE_SGE,
    Brig::BRIG_COMPARE_SGEU,
    Brig::BRIG_COMPARE_SGT,
    Brig::BRIG_COMPARE_SGTU,
    Brig::BRIG_COMPARE_SLE,
    Brig::BRIG_COMPARE_SLEU,
    Brig::BRIG_COMPARE_SLT,
    Brig::BRIG_COMPARE_SLTU,
    Brig::BRIG_COMPARE_SNAN,
    Brig::BRIG_COMPARE_SNE,
    Brig::BRIG_COMPARE_SNEU,
    Brig::BRIG_COMPARE_SNUM,
};

unsigned PropDescImpl::PROP_VALUES_TYPESIZE[] = 
{
    TYPESIZE_VAL_ATOMIC,
    TYPESIZE_VAL_MODEL,
    TYPESIZE_VAL_SEG,
    TYPESIZE_VAL_INVALID,
};

unsigned PropDescImpl::PROP_VALUES_STYPESIZE[] = 
{
    STYPESIZE_VAL_MODEL,
    STYPESIZE_VAL_SEG,
    STYPESIZE_VAL_INVALID,
};

unsigned PropDescImpl::PROP_VALUES_PACKING[] = 
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_P,
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PPSAT,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_PSAT,
    Brig::BRIG_PACK_PSSAT,
    Brig::BRIG_PACK_S,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SPSAT,
    Brig::BRIG_PACK_SS,
    Brig::BRIG_PACK_SSAT,
    Brig::BRIG_PACK_SSSAT,
};

unsigned PropDescImpl::PROP_VALUES_ALIGN[] = 
{
    0,
    1,
};

unsigned PropDescImpl::PROP_VALUES_MEMFNC[] = 
{
    Brig::BRIG_MEMORY_FENCE_BOTH,
    Brig::BRIG_MEMORY_FENCE_GLOBAL,
    Brig::BRIG_MEMORY_FENCE_GROUP,
    Brig::BRIG_MEMORY_FENCE_NONE,
};

unsigned PropDescImpl::PROP_VALUES_EQCLASS[] = 
{
    EQCLASS_VAL_ANY,
    EQCLASS_VAL_INVALID,
};

unsigned PropDescImpl::PROP_VALUES_ROUNDING[] = 
{
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO,
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN_SAT,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_ZERO,
    Brig::BRIG_ROUND_INTEGER_ZERO_SAT,
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::PROP_VALUES_FTZ[] = 
{
    0,
    1,
};

unsigned PropDescImpl::PROP_VALUES_TYPE[] = 
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_B16,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_B8,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_NONE,
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_SAMP,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

const unsigned* PropDescImpl::getPropVals(unsigned propId, unsigned& num) // should include XXX_VAL_INVALID for invalid values (non-brig only)
{
    switch(propId)
    {
    case PROP_ALIGN: 	num = sizeof(PROP_VALUES_ALIGN) / sizeof(unsigned); return PROP_VALUES_ALIGN;

    case PROP_ATMOP: 	num = sizeof(PROP_VALUES_ATMOP) / sizeof(unsigned); return PROP_VALUES_ATMOP;

    case PROP_EQCLASS: 	num = sizeof(PROP_VALUES_EQCLASS) / sizeof(unsigned); return PROP_VALUES_EQCLASS;

    case PROP_FTZ: 	num = sizeof(PROP_VALUES_FTZ) / sizeof(unsigned); return PROP_VALUES_FTZ;

    case PROP_GEOM: 	num = sizeof(PROP_VALUES_GEOM) / sizeof(unsigned); return PROP_VALUES_GEOM;

    case PROP_MEMFNC: 	num = sizeof(PROP_VALUES_MEMFNC) / sizeof(unsigned); return PROP_VALUES_MEMFNC;

    case PROP_MEMORD: 	num = sizeof(PROP_VALUES_MEMORD) / sizeof(unsigned); return PROP_VALUES_MEMORD;

    case PROP_MEMSCP: 	num = sizeof(PROP_VALUES_MEMSCP) / sizeof(unsigned); return PROP_VALUES_MEMSCP;

    case PROP_D0:
    case PROP_D1:
    case PROP_S0:
    case PROP_S1:
    case PROP_S2:
    case PROP_S3:
    case PROP_S4:
    case PROP_OPERAND: 	num = sizeof(PROP_VALUES_OPERAND) / sizeof(unsigned); return PROP_VALUES_OPERAND;

    case PROP_OPERATOR: 	num = sizeof(PROP_VALUES_OPERATOR) / sizeof(unsigned); return PROP_VALUES_OPERATOR;

    case PROP_PACKING: 	num = sizeof(PROP_VALUES_PACKING) / sizeof(unsigned); return PROP_VALUES_PACKING;

    case PROP_ROUNDING: 	num = sizeof(PROP_VALUES_ROUNDING) / sizeof(unsigned); return PROP_VALUES_ROUNDING;

    case PROP_SEGMENT: 	num = sizeof(PROP_VALUES_SEGMENT) / sizeof(unsigned); return PROP_VALUES_SEGMENT;

    case PROP_STYPESIZE: 	num = sizeof(PROP_VALUES_STYPESIZE) / sizeof(unsigned); return PROP_VALUES_STYPESIZE;

    case PROP_CTYPE:
    case PROP_ITYPE:
    case PROP_STYPE:
    case PROP_TYPE: 	num = sizeof(PROP_VALUES_TYPE) / sizeof(unsigned); return PROP_VALUES_TYPE;

    case PROP_TYPESIZE: 	num = sizeof(PROP_VALUES_TYPESIZE) / sizeof(unsigned); return PROP_VALUES_TYPESIZE;

    case PROP_WIDTH: 	num = sizeof(PROP_VALUES_WIDTH) / sizeof(unsigned); return PROP_VALUES_WIDTH;

    }
    assert(false);
    num = 0;
    return 0;
}

unsigned PropDescImpl::REQ_PROPS_NEG[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_PACKING,        // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_FTZ,            // Plain
    PROP_ROUNDING,       // Plain
};

unsigned PropDescImpl::REQ_PROPS_ADD[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_FTZ,            // Conditional
    PROP_PACKING,        // Conditional
    PROP_ROUNDING,       // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_ALLOCA[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_AND[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_FBAR_SYNC_WIDTH[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_MEMFNC,         // Plain
    PROP_MEMORD,         // Plain
    PROP_MEMSCP,         // Plain
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_ATOMIC[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_ATMOP,          // Primary
    PROP_SEGMENT,        // Primary
    PROP_MEMORD,         // Conditional
    PROP_S2,             // Conditional
    PROP_S3,             // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S4,             // Dependent
    PROP_MEMSCP,         // Plain
};

unsigned PropDescImpl::REQ_PROPS_ATOMIC_IMAGE[] =
{
    PROP_CTYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_ATMOP,          // Primary
    PROP_GEOM,           // Primary
    PROP_S2,             // Conditional
    PROP_S4,             // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S3,             // Dependent
    PROP_ITYPE,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_ATOMIC_NORET_IMAGE[] =
{
    PROP_CTYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_ATMOP,          // Primary
    PROP_GEOM,           // Primary
    PROP_S1,             // Conditional
    PROP_S3,             // Conditional
    PROP_S0,             // Dependent
    PROP_S2,             // Dependent
    PROP_S4,             // Dependent
    PROP_ITYPE,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_ATOMIC_NORET[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_ATMOP,          // Primary
    PROP_SEGMENT,        // Primary
    PROP_MEMORD,         // Conditional
    PROP_S2,             // Conditional
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_MEMSCP,         // Plain
};

unsigned PropDescImpl::REQ_PROPS_BARRIER[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_MEMFNC,         // Plain
    PROP_MEMORD,         // Plain
    PROP_MEMSCP,         // Plain
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_ALIGN[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_BITEXTRACT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_BITINSERT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_BITMASK[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_BITREV[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_BITSELECT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_REM[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_BRN[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Primary
    PROP_S1,             // Conditional
    PROP_WIDTH,          // Conditional
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_CALL[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S1,             // Primary
    PROP_S3,             // Conditional
    PROP_WIDTH,          // Conditional
    PROP_S0,             // Dependent
    PROP_S2,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_CBR[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S1,             // Primary
    PROP_S2,             // Conditional
    PROP_S0,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_CEIL[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_PACKING,        // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_FTZ,            // Plain
    PROP_ROUNDING,       // Plain
};

unsigned PropDescImpl::REQ_PROPS_CLASS[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SPEC_EXCEPT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SPEC_CLOCK[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_CMOV[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S1,             // Conditional
    PROP_D0,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_CMP[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_FTZ,            // Conditional
    PROP_OPERATOR,       // Conditional
    PROP_PACKING,        // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_ROUNDING,       // Plain
};

unsigned PropDescImpl::REQ_PROPS_CODEBLOCKEND[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_COMBINE[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_S1,             // Conditional
    PROP_D0,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_COPYSIGN[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_PACKING,        // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_FTZ,            // Plain
    PROP_ROUNDING,       // Plain
};

unsigned PropDescImpl::REQ_PROPS_COUNTLANE[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_COUNTUPLANE[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_SPEC_REG[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SPEC_REG_DIM[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_CVT[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_FTZ,            // Conditional
    PROP_ROUNDING,       // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_DEBUGTRAP[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_AQLPTR[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_DIV[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_FTZ,            // Conditional
    PROP_PACKING,        // Conditional
    PROP_ROUNDING,       // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_EXPAND[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Conditional
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_FIRSTBIT[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_FMA[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_FTZ,            // Plain
    PROP_PACKING,        // Plain
    PROP_ROUNDING,       // Plain
};

unsigned PropDescImpl::REQ_PROPS_FRACT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_PACKING,        // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_FTZ,            // Plain
    PROP_ROUNDING,       // Plain
};

unsigned PropDescImpl::REQ_PROPS_F2S[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_APPEND_CONSUME[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_ATOMIC[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_ATMOP,          // Primary
    PROP_SEGMENT,        // Primary
    PROP_MEMORD,         // Conditional
    PROP_S2,             // Conditional
    PROP_S3,             // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S4,             // Dependent
    PROP_MEMSCP,         // Plain
};

unsigned PropDescImpl::REQ_PROPS_GCN_ATOMIC_NORET[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_ATMOP,          // Primary
    PROP_SEGMENT,        // Primary
    PROP_MEMORD,         // Conditional
    PROP_S2,             // Conditional
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_MEMSCP,         // Plain
};

unsigned PropDescImpl::REQ_PROPS_GCN_B4XCHG[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_BFM[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_FLDEXP[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_FREXP_EXP[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_FREXP_MANT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_LD[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_D0,             // Conditional
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_ALIGN,          // Plain
    PROP_EQCLASS,        // Plain
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_GCN_MAD[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_MIN_MAX_MED[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_MQSAD[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_MQSAD4[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_MSAD[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_SLP_PRT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_QSAD[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_REGION_ALLOC[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_GCN_ST[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_S0,             // Conditional
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_ALIGN,          // Plain
    PROP_EQCLASS,        // Plain
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_GCN_TRIG_PREOP[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_FBAR_NONE[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_MEMFNC,         // Plain
    PROP_MEMORD,         // Plain
    PROP_MEMSCP,         // Plain
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_FBAR_WIDTH[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_MEMFNC,         // Plain
    PROP_MEMORD,         // Plain
    PROP_MEMSCP,         // Plain
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_LD[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_D0,             // Conditional
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_ALIGN,          // Plain
    PROP_EQCLASS,        // Plain
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_LDA[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_LDC[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_LDF[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_LD_IMAGE[] =
{
    PROP_CTYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_GEOM,           // Primary
    PROP_ITYPE,          // Primary
    PROP_S1,             // Conditional
    PROP_S2,             // Conditional
    PROP_D0,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_LERP[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_MAD[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_MAD24[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_MASKLANE[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_MAX[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_FTZ,            // Conditional
    PROP_PACKING,        // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_ROUNDING,       // Plain
};

unsigned PropDescImpl::REQ_PROPS_MOV[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_MUL[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_FTZ,            // Conditional
    PROP_PACKING,        // Conditional
    PROP_ROUNDING,       // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_MUL24[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_MULHI[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_PACKING,        // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_FTZ,            // Plain
    PROP_ROUNDING,       // Plain
};

unsigned PropDescImpl::REQ_PROPS_TRIG32[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_NFMA[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_NOP[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_NOT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_TRIG[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_NULLPTR[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_PACK[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_PACKCVT[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_POPCOUNT[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_QUERYIMAGE[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_S1,             // Conditional
    PROP_D0,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_QUERYSAMPLERBOUNDARY[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_QUERYSAMPLER[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_RDIMAGE[] =
{
    PROP_CTYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_GEOM,           // Primary
    PROP_ITYPE,          // Primary
    PROP_S1,             // Conditional
    PROP_S3,             // Conditional
    PROP_D0,             // Dependent
    PROP_S2,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SENDLANE[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_RET[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SAD[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SADHI[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SEGMENTP[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SHIFT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SHUFFLE[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SQRT[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_PACKING,        // Conditional
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_FTZ,            // Plain
    PROP_ROUNDING,       // Plain
};

unsigned PropDescImpl::REQ_PROPS_ST[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_S0,             // Conditional
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_ALIGN,          // Plain
    PROP_EQCLASS,        // Plain
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_ST_IMAGE[] =
{
    PROP_CTYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_GEOM,           // Primary
    PROP_S2,             // Conditional
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_ITYPE,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_S2F[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_SEGMENT,        // Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_SYNC[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
    PROP_MEMFNC,         // Plain
    PROP_MEMORD,         // Plain
    PROP_MEMSCP,         // Plain
    PROP_WIDTH,          // Plain
};

unsigned PropDescImpl::REQ_PROPS_SYSCALL[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_S0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_UNPACK[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_UNPACKCVT[] =
{
    PROP_STYPE,          // Leading Primary
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

unsigned PropDescImpl::REQ_PROPS_UNPACKX[] =
{
    PROP_TYPE,           // Leading Primary
    PROP_D0,             // Dependent
    PROP_S1,             // Dependent
    PROP_S2,             // Dependent
    PROP_S3,             // Dependent
    PROP_S4,             // Dependent
};

const unsigned* PropDescImpl::getProps(unsigned opcode, unsigned& prm, unsigned& sec) 
{
    switch(opcode)
    {
    case Brig::BRIG_OPCODE_ABS:
    case Brig::BRIG_OPCODE_NEG:
        prm = 1;
        sec = 8;
        return REQ_PROPS_NEG;

    case Brig::BRIG_OPCODE_ADD:
    case Brig::BRIG_OPCODE_SUB:
        prm = 1;
        sec = 8;
        return REQ_PROPS_ADD;

    case Brig::BRIG_OPCODE_ALLOCA:
        prm = 3;
        sec = 5;
        return REQ_PROPS_ALLOCA;

    case Brig::BRIG_OPCODE_AND:
    case Brig::BRIG_OPCODE_OR:
    case Brig::BRIG_OPCODE_XOR:
        prm = 1;
        sec = 5;
        return REQ_PROPS_AND;

    case Brig::BRIG_OPCODE_ARRIVEFBAR:
    case Brig::BRIG_OPCODE_WAITFBAR:
        prm = 1;
        sec = 9;
        return REQ_PROPS_FBAR_SYNC_WIDTH;

    case Brig::BRIG_OPCODE_ATOMIC:
        prm = 3;
        sec = 7;
        return REQ_PROPS_ATOMIC;

    case Brig::BRIG_OPCODE_ATOMICIMAGE:
        prm = 4;
        sec = 6;
        return REQ_PROPS_ATOMIC_IMAGE;

    case Brig::BRIG_OPCODE_ATOMICIMAGENORET:
        prm = 4;
        sec = 6;
        return REQ_PROPS_ATOMIC_NORET_IMAGE;

    case Brig::BRIG_OPCODE_ATOMICNORET:
        prm = 3;
        sec = 7;
        return REQ_PROPS_ATOMIC_NORET;

    case Brig::BRIG_OPCODE_BARRIER:
        prm = 1;
        sec = 9;
        return REQ_PROPS_BARRIER;

    case Brig::BRIG_OPCODE_BITALIGN:
    case Brig::BRIG_OPCODE_BYTEALIGN:
        prm = 1;
        sec = 5;
        return REQ_PROPS_ALIGN;

    case Brig::BRIG_OPCODE_BITEXTRACT:
        prm = 1;
        sec = 5;
        return REQ_PROPS_BITEXTRACT;

    case Brig::BRIG_OPCODE_BITINSERT:
        prm = 1;
        sec = 5;
        return REQ_PROPS_BITINSERT;

    case Brig::BRIG_OPCODE_BITMASK:
        prm = 1;
        sec = 5;
        return REQ_PROPS_BITMASK;

    case Brig::BRIG_OPCODE_BITREV:
        prm = 1;
        sec = 5;
        return REQ_PROPS_BITREV;

    case Brig::BRIG_OPCODE_BITSELECT:
        prm = 1;
        sec = 5;
        return REQ_PROPS_BITSELECT;

    case Brig::BRIG_OPCODE_BORROW:
    case Brig::BRIG_OPCODE_CARRY:
    case Brig::BRIG_OPCODE_REM:
        prm = 1;
        sec = 5;
        return REQ_PROPS_REM;

    case Brig::BRIG_OPCODE_BRN:
        prm = 2;
        sec = 5;
        return REQ_PROPS_BRN;

    case Brig::BRIG_OPCODE_CALL:
        prm = 2;
        sec = 5;
        return REQ_PROPS_CALL;

    case Brig::BRIG_OPCODE_CBR:
        prm = 2;
        sec = 5;
        return REQ_PROPS_CBR;

    case Brig::BRIG_OPCODE_CEIL:
    case Brig::BRIG_OPCODE_FLOOR:
    case Brig::BRIG_OPCODE_RINT:
    case Brig::BRIG_OPCODE_TRUNC:
        prm = 1;
        sec = 8;
        return REQ_PROPS_CEIL;

    case Brig::BRIG_OPCODE_CLASS:
        prm = 2;
        sec = 5;
        return REQ_PROPS_CLASS;

    case Brig::BRIG_OPCODE_CLEARDETECTEXCEPT:
    case Brig::BRIG_OPCODE_SETDETECTEXCEPT:
        prm = 1;
        sec = 5;
        return REQ_PROPS_SPEC_EXCEPT;

    case Brig::BRIG_OPCODE_CLOCK:
    case Brig::BRIG_OPCODE_DISPATCHID:
        prm = 1;
        sec = 5;
        return REQ_PROPS_SPEC_CLOCK;

    case Brig::BRIG_OPCODE_CMOV:
        prm = 1;
        sec = 5;
        return REQ_PROPS_CMOV;

    case Brig::BRIG_OPCODE_CMP:
        prm = 2;
        sec = 9;
        return REQ_PROPS_CMP;

    case Brig::BRIG_OPCODE_CODEBLOCKEND:
        prm = 1;
        sec = 5;
        return REQ_PROPS_CODEBLOCKEND;

    case Brig::BRIG_OPCODE_COMBINE:
        prm = 2;
        sec = 5;
        return REQ_PROPS_COMBINE;

    case Brig::BRIG_OPCODE_COPYSIGN:
        prm = 1;
        sec = 8;
        return REQ_PROPS_COPYSIGN;

    case Brig::BRIG_OPCODE_COUNTLANE:
        prm = 2;
        sec = 6;
        return REQ_PROPS_COUNTLANE;

    case Brig::BRIG_OPCODE_COUNTUPLANE:
        prm = 2;
        sec = 6;
        return REQ_PROPS_COUNTUPLANE;

    case Brig::BRIG_OPCODE_CUID:
    case Brig::BRIG_OPCODE_DIM:
    case Brig::BRIG_OPCODE_GETDETECTEXCEPT:
    case Brig::BRIG_OPCODE_LANEID:
    case Brig::BRIG_OPCODE_MAXCUID:
    case Brig::BRIG_OPCODE_MAXWAVEID:
    case Brig::BRIG_OPCODE_QID:
    case Brig::BRIG_OPCODE_WAVEID:
    case Brig::BRIG_OPCODE_WORKITEMFLATABSID:
    case Brig::BRIG_OPCODE_WORKITEMFLATID:
        prm = 1;
        sec = 5;
        return REQ_PROPS_SPEC_REG;

    case Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE:
    case Brig::BRIG_OPCODE_GRIDGROUPS:
    case Brig::BRIG_OPCODE_GRIDSIZE:
    case Brig::BRIG_OPCODE_WORKGROUPID:
    case Brig::BRIG_OPCODE_WORKGROUPSIZE:
    case Brig::BRIG_OPCODE_WORKITEMABSID:
    case Brig::BRIG_OPCODE_WORKITEMID:
        prm = 1;
        sec = 5;
        return REQ_PROPS_SPEC_REG_DIM;

    case Brig::BRIG_OPCODE_CVT:
        prm = 2;
        sec = 7;
        return REQ_PROPS_CVT;

    case Brig::BRIG_OPCODE_DEBUGTRAP:
        prm = 1;
        sec = 5;
        return REQ_PROPS_DEBUGTRAP;

    case Brig::BRIG_OPCODE_DISPATCHPTR:
    case Brig::BRIG_OPCODE_QPTR:
        prm = 3;
        sec = 5;
        return REQ_PROPS_AQLPTR;

    case Brig::BRIG_OPCODE_DIV:
        prm = 1;
        sec = 8;
        return REQ_PROPS_DIV;

    case Brig::BRIG_OPCODE_EXPAND:
        prm = 2;
        sec = 5;
        return REQ_PROPS_EXPAND;

    case Brig::BRIG_OPCODE_FIRSTBIT:
    case Brig::BRIG_OPCODE_LASTBIT:
        prm = 2;
        sec = 5;
        return REQ_PROPS_FIRSTBIT;

    case Brig::BRIG_OPCODE_FMA:
        prm = 1;
        sec = 8;
        return REQ_PROPS_FMA;

    case Brig::BRIG_OPCODE_FRACT:
        prm = 1;
        sec = 8;
        return REQ_PROPS_FRACT;

    case Brig::BRIG_OPCODE_FTOS:
        prm = 3;
        sec = 5;
        return REQ_PROPS_F2S;

    case Brig::BRIG_OPCODE_GCNAPPEND:
    case Brig::BRIG_OPCODE_GCNCONSUME:
        prm = 2;
        sec = 5;
        return REQ_PROPS_GCN_APPEND_CONSUME;

    case Brig::BRIG_OPCODE_GCNATOMIC:
        prm = 3;
        sec = 7;
        return REQ_PROPS_GCN_ATOMIC;

    case Brig::BRIG_OPCODE_GCNATOMICNORET:
        prm = 3;
        sec = 7;
        return REQ_PROPS_GCN_ATOMIC_NORET;

    case Brig::BRIG_OPCODE_GCNB32XCHG:
    case Brig::BRIG_OPCODE_GCNB4XCHG:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_B4XCHG;

    case Brig::BRIG_OPCODE_GCNBFM:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_BFM;

    case Brig::BRIG_OPCODE_GCNFLDEXP:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_FLDEXP;

    case Brig::BRIG_OPCODE_GCNFREXP_EXP:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_FREXP_EXP;

    case Brig::BRIG_OPCODE_GCNFREXP_MANT:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_FREXP_MANT;

    case Brig::BRIG_OPCODE_GCNLD:
        prm = 2;
        sec = 8;
        return REQ_PROPS_GCN_LD;

    case Brig::BRIG_OPCODE_GCNMADS:
    case Brig::BRIG_OPCODE_GCNMADU:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_MAD;

    case Brig::BRIG_OPCODE_GCNMAX3:
    case Brig::BRIG_OPCODE_GCNMED3:
    case Brig::BRIG_OPCODE_GCNMIN3:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_MIN_MAX_MED;

    case Brig::BRIG_OPCODE_GCNMQSAD:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_MQSAD;

    case Brig::BRIG_OPCODE_GCNMQSAD4:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_MQSAD4;

    case Brig::BRIG_OPCODE_GCNMSAD:
    case Brig::BRIG_OPCODE_GCNSADD:
    case Brig::BRIG_OPCODE_GCNSADW:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_MSAD;

    case Brig::BRIG_OPCODE_GCNPRIORITY:
    case Brig::BRIG_OPCODE_GCNSLEEP:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_SLP_PRT;

    case Brig::BRIG_OPCODE_GCNQSAD:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_QSAD;

    case Brig::BRIG_OPCODE_GCNREGIONALLOC:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_REGION_ALLOC;

    case Brig::BRIG_OPCODE_GCNST:
        prm = 2;
        sec = 8;
        return REQ_PROPS_GCN_ST;

    case Brig::BRIG_OPCODE_GCNTRIG_PREOP:
        prm = 1;
        sec = 5;
        return REQ_PROPS_GCN_TRIG_PREOP;

    case Brig::BRIG_OPCODE_INITFBAR:
    case Brig::BRIG_OPCODE_RELEASEFBAR:
        prm = 1;
        sec = 9;
        return REQ_PROPS_FBAR_NONE;

    case Brig::BRIG_OPCODE_JOINFBAR:
    case Brig::BRIG_OPCODE_LEAVEFBAR:
        prm = 1;
        sec = 9;
        return REQ_PROPS_FBAR_WIDTH;

    case Brig::BRIG_OPCODE_LD:
        prm = 2;
        sec = 8;
        return REQ_PROPS_LD;

    case Brig::BRIG_OPCODE_LDA:
        prm = 2;
        sec = 5;
        return REQ_PROPS_LDA;

    case Brig::BRIG_OPCODE_LDC:
        prm = 1;
        sec = 5;
        return REQ_PROPS_LDC;

    case Brig::BRIG_OPCODE_LDF:
        prm = 1;
        sec = 5;
        return REQ_PROPS_LDF;

    case Brig::BRIG_OPCODE_LDIMAGE:
        prm = 4;
        sec = 5;
        return REQ_PROPS_LD_IMAGE;

    case Brig::BRIG_OPCODE_LERP:
        prm = 1;
        sec = 5;
        return REQ_PROPS_LERP;

    case Brig::BRIG_OPCODE_MAD:
        prm = 1;
        sec = 5;
        return REQ_PROPS_MAD;

    case Brig::BRIG_OPCODE_MAD24:
    case Brig::BRIG_OPCODE_MAD24HI:
        prm = 1;
        sec = 5;
        return REQ_PROPS_MAD24;

    case Brig::BRIG_OPCODE_MASKLANE:
        prm = 2;
        sec = 6;
        return REQ_PROPS_MASKLANE;

    case Brig::BRIG_OPCODE_MAX:
    case Brig::BRIG_OPCODE_MIN:
        prm = 1;
        sec = 8;
        return REQ_PROPS_MAX;

    case Brig::BRIG_OPCODE_MOV:
        prm = 1;
        sec = 5;
        return REQ_PROPS_MOV;

    case Brig::BRIG_OPCODE_MUL:
        prm = 1;
        sec = 8;
        return REQ_PROPS_MUL;

    case Brig::BRIG_OPCODE_MUL24:
    case Brig::BRIG_OPCODE_MUL24HI:
        prm = 1;
        sec = 5;
        return REQ_PROPS_MUL24;

    case Brig::BRIG_OPCODE_MULHI:
        prm = 1;
        sec = 8;
        return REQ_PROPS_MULHI;

    case Brig::BRIG_OPCODE_NCOS:
    case Brig::BRIG_OPCODE_NEXP2:
    case Brig::BRIG_OPCODE_NLOG2:
    case Brig::BRIG_OPCODE_NSIN:
        prm = 1;
        sec = 5;
        return REQ_PROPS_TRIG32;

    case Brig::BRIG_OPCODE_NFMA:
        prm = 1;
        sec = 5;
        return REQ_PROPS_NFMA;

    case Brig::BRIG_OPCODE_NOP:
        prm = 1;
        sec = 5;
        return REQ_PROPS_NOP;

    case Brig::BRIG_OPCODE_NOT:
        prm = 1;
        sec = 5;
        return REQ_PROPS_NOT;

    case Brig::BRIG_OPCODE_NRCP:
    case Brig::BRIG_OPCODE_NRSQRT:
    case Brig::BRIG_OPCODE_NSQRT:
        prm = 1;
        sec = 5;
        return REQ_PROPS_TRIG;

    case Brig::BRIG_OPCODE_NULLPTR:
        prm = 3;
        sec = 5;
        return REQ_PROPS_NULLPTR;

    case Brig::BRIG_OPCODE_PACK:
        prm = 2;
        sec = 5;
        return REQ_PROPS_PACK;

    case Brig::BRIG_OPCODE_PACKCVT:
        prm = 2;
        sec = 5;
        return REQ_PROPS_PACKCVT;

    case Brig::BRIG_OPCODE_POPCOUNT:
        prm = 2;
        sec = 5;
        return REQ_PROPS_POPCOUNT;

    case Brig::BRIG_OPCODE_QUERYIMAGEARRAY:
    case Brig::BRIG_OPCODE_QUERYIMAGEDEPTH:
    case Brig::BRIG_OPCODE_QUERYIMAGEFORMAT:
    case Brig::BRIG_OPCODE_QUERYIMAGEHEIGHT:
    case Brig::BRIG_OPCODE_QUERYIMAGEORDER:
    case Brig::BRIG_OPCODE_QUERYIMAGEWIDTH:
        prm = 2;
        sec = 5;
        return REQ_PROPS_QUERYIMAGE;

    case Brig::BRIG_OPCODE_QUERYSAMPLERBOUNDARY:
        prm = 2;
        sec = 5;
        return REQ_PROPS_QUERYSAMPLERBOUNDARY;

    case Brig::BRIG_OPCODE_QUERYSAMPLERCOORD:
    case Brig::BRIG_OPCODE_QUERYSAMPLERFILTER:
        prm = 2;
        sec = 5;
        return REQ_PROPS_QUERYSAMPLER;

    case Brig::BRIG_OPCODE_RDIMAGE:
        prm = 4;
        sec = 5;
        return REQ_PROPS_RDIMAGE;

    case Brig::BRIG_OPCODE_RECEIVELANE:
    case Brig::BRIG_OPCODE_SENDLANE:
        prm = 2;
        sec = 6;
        return REQ_PROPS_SENDLANE;

    case Brig::BRIG_OPCODE_RET:
        prm = 1;
        sec = 5;
        return REQ_PROPS_RET;

    case Brig::BRIG_OPCODE_SAD:
        prm = 2;
        sec = 5;
        return REQ_PROPS_SAD;

    case Brig::BRIG_OPCODE_SADHI:
        prm = 2;
        sec = 5;
        return REQ_PROPS_SADHI;

    case Brig::BRIG_OPCODE_SEGMENTP:
        prm = 3;
        sec = 5;
        return REQ_PROPS_SEGMENTP;

    case Brig::BRIG_OPCODE_SHL:
    case Brig::BRIG_OPCODE_SHR:
        prm = 1;
        sec = 5;
        return REQ_PROPS_SHIFT;

    case Brig::BRIG_OPCODE_SHUFFLE:
        prm = 1;
        sec = 5;
        return REQ_PROPS_SHUFFLE;

    case Brig::BRIG_OPCODE_SQRT:
        prm = 1;
        sec = 8;
        return REQ_PROPS_SQRT;

    case Brig::BRIG_OPCODE_ST:
        prm = 2;
        sec = 8;
        return REQ_PROPS_ST;

    case Brig::BRIG_OPCODE_STIMAGE:
        prm = 3;
        sec = 6;
        return REQ_PROPS_ST_IMAGE;

    case Brig::BRIG_OPCODE_STOF:
        prm = 3;
        sec = 5;
        return REQ_PROPS_S2F;

    case Brig::BRIG_OPCODE_SYNC:
        prm = 1;
        sec = 9;
        return REQ_PROPS_SYNC;

    case Brig::BRIG_OPCODE_SYSCALL:
        prm = 1;
        sec = 5;
        return REQ_PROPS_SYSCALL;

    case Brig::BRIG_OPCODE_UNPACK:
        prm = 2;
        sec = 5;
        return REQ_PROPS_UNPACK;

    case Brig::BRIG_OPCODE_UNPACKCVT:
        prm = 2;
        sec = 5;
        return REQ_PROPS_UNPACKCVT;

    case Brig::BRIG_OPCODE_UNPACKHI:
    case Brig::BRIG_OPCODE_UNPACKLO:
        prm = 1;
        sec = 5;
        return REQ_PROPS_UNPACKX;

    }

    assert(false);
    prm = 0;
    sec = 0;
    return 0;
}

unsigned PropDescImpl::REQ_PROP_VALUES_NEG__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NEG__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_P,
    Brig::BRIG_PACK_S,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NEG__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NEG__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NEG__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NEG__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NEG__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NEG__FTZ[] =
{
    0,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NEG__ROUNDING[] =
{
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ADD__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ADD__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ADD__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PPSAT,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_PSSAT,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SPSAT,
    Brig::BRIG_PACK_SS,
    Brig::BRIG_PACK_SSSAT,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ADD__ROUNDING[] =
{
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO,
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ADD__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ADD__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ADD__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ADD__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ADD__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALLOCA__STYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALLOCA__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALLOCA__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_PRIVATE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALLOCA__S0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALLOCA__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALLOCA__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALLOCA__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALLOCA__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AND__TYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AND__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AND__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AND__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AND__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AND__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S0[] =
{
    OPERAND_VAL_FBARRIER,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMFNC[] =
{
    Brig::BRIG_MEMORY_FENCE_BOTH,
    Brig::BRIG_MEMORY_FENCE_GLOBAL,
    Brig::BRIG_MEMORY_FENCE_GROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMORD[] =
{
    Brig::BRIG_MEMORY_ORDER_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMSCP[] =
{
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_SYNC_WIDTH__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__ATMOP[] =
{
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_LD,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__MEMORD[] =
{
    Brig::BRIG_MEMORY_ORDER_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_ACQUIRE_RELEASE,
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_NULL,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_NULL,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__S1[] =
{
    OPERAND_VAL_ADDR_SEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC__MEMSCP[] =
{
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__CTYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__ATMOP[] =
{
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__GEOM[] =
{
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_1DB,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__S2[] =
{
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__S4[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_NULL,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__S1[] =
{
    OPERAND_VAL_REG_64,
    OPERAND_VAL_RWIMAGE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_IMAGE__ITYPE[] =
{
    Brig::BRIG_TYPE_RWIMG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__CTYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__ATMOP[] =
{
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__GEOM[] =
{
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_1DB,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S1[] =
{
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_NULL,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S0[] =
{
    OPERAND_VAL_REG_64,
    OPERAND_VAL_RWIMAGE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__ITYPE[] =
{
    Brig::BRIG_TYPE_RWIMG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__ATMOP[] =
{
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_ST,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__MEMORD[] =
{
    Brig::BRIG_MEMORY_ORDER_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_ACQUIRE_RELEASE,
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_NULL,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__S0[] =
{
    OPERAND_VAL_ADDR_SEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ATOMIC_NORET__MEMSCP[] =
{
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__S0[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__MEMFNC[] =
{
    Brig::BRIG_MEMORY_FENCE_BOTH,
    Brig::BRIG_MEMORY_FENCE_GLOBAL,
    Brig::BRIG_MEMORY_FENCE_GROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__MEMORD[] =
{
    Brig::BRIG_MEMORY_ORDER_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__MEMSCP[] =
{
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BARRIER__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALIGN__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALIGN__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALIGN__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALIGN__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALIGN__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ALIGN__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITEXTRACT__TYPE[] =
{
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITEXTRACT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITEXTRACT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITEXTRACT__S2[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITEXTRACT__S3[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITEXTRACT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITINSERT__TYPE[] =
{
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITINSERT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITINSERT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITINSERT__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITINSERT__S3[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITINSERT__S4[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITMASK__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITMASK__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITMASK__S1[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITMASK__S2[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITMASK__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITMASK__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITREV__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITREV__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITREV__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITREV__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITREV__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITREV__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITSELECT__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITSELECT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITSELECT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITSELECT__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITSELECT__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BITSELECT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_REM__TYPE[] =
{
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_REM__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_REM__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_REM__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_REM__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_REM__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BRN__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BRN__S0[] =
{
    OPERAND_VAL_LAB,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BRN__S1[] =
{
    OPERAND_VAL_JUMPTAB,
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BRN__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BRN__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BRN__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_BRN__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CALL__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CALL__S1[] =
{
    OPERAND_VAL_FUNC,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CALL__S3[] =
{
    OPERAND_VAL_CALLTAB,
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CALL__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CALL__S0[] =
{
    OPERAND_VAL_ARGLIST,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CALL__S2[] =
{
    OPERAND_VAL_ARGLIST,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CALL__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CBR__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CBR__S1[] =
{
    OPERAND_VAL_LAB,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CBR__S2[] =
{
    OPERAND_VAL_JUMPTAB,
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CBR__S0[] =
{
    OPERAND_VAL_REG_1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CBR__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CBR__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CBR__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CEIL__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CEIL__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_P,
    Brig::BRIG_PACK_S,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CEIL__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CEIL__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CEIL__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CEIL__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CEIL__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CEIL__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CEIL__ROUNDING[] =
{
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CLASS__STYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CLASS__TYPE[] =
{
    Brig::BRIG_TYPE_B1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CLASS__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CLASS__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CLASS__S2[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CLASS__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CLASS__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_EXCEPT__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_EXCEPT__S0[] =
{
    OPERAND_VAL_IMM,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_EXCEPT__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_EXCEPT__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_EXCEPT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_EXCEPT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_CLOCK__TYPE[] =
{
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_CLOCK__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_CLOCK__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_CLOCK__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_CLOCK__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_CLOCK__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMOV__TYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMOV__S1[] =
{
    OPERAND_VAL_IMM_1,
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG_1,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMOV__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMOV__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMOV__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMOV__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__STYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__TYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__OPERATOR[] =
{
    Brig::BRIG_COMPARE_EQ,
    Brig::BRIG_COMPARE_EQU,
    Brig::BRIG_COMPARE_GE,
    Brig::BRIG_COMPARE_GEU,
    Brig::BRIG_COMPARE_GT,
    Brig::BRIG_COMPARE_GTU,
    Brig::BRIG_COMPARE_LE,
    Brig::BRIG_COMPARE_LEU,
    Brig::BRIG_COMPARE_LT,
    Brig::BRIG_COMPARE_LTU,
    Brig::BRIG_COMPARE_NAN,
    Brig::BRIG_COMPARE_NE,
    Brig::BRIG_COMPARE_NEU,
    Brig::BRIG_COMPARE_NUM,
    Brig::BRIG_COMPARE_SEQ,
    Brig::BRIG_COMPARE_SEQU,
    Brig::BRIG_COMPARE_SGE,
    Brig::BRIG_COMPARE_SGEU,
    Brig::BRIG_COMPARE_SGT,
    Brig::BRIG_COMPARE_SGTU,
    Brig::BRIG_COMPARE_SLE,
    Brig::BRIG_COMPARE_SLEU,
    Brig::BRIG_COMPARE_SLT,
    Brig::BRIG_COMPARE_SLTU,
    Brig::BRIG_COMPARE_SNAN,
    Brig::BRIG_COMPARE_SNE,
    Brig::BRIG_COMPARE_SNEU,
    Brig::BRIG_COMPARE_SNUM,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_PP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CMP__ROUNDING[] =
{
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CODEBLOCKEND__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CODEBLOCKEND__S0[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CODEBLOCKEND__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CODEBLOCKEND__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CODEBLOCKEND__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CODEBLOCKEND__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COMBINE__STYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COMBINE__TYPE[] =
{
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COMBINE__S1[] =
{
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COMBINE__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COMBINE__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COMBINE__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COMBINE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COPYSIGN__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COPYSIGN__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SS,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COPYSIGN__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COPYSIGN__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COPYSIGN__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COPYSIGN__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COPYSIGN__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COPYSIGN__FTZ[] =
{
    0,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COPYSIGN__ROUNDING[] =
{
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTLANE__STYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTLANE__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTLANE__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTLANE__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTLANE__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTLANE__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTLANE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTLANE__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTUPLANE__STYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTUPLANE__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTUPLANE__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTUPLANE__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTUPLANE__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTUPLANE__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTUPLANE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_COUNTUPLANE__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG_DIM__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG_DIM__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG_DIM__S1[] =
{
    OPERAND_VAL_IMM_0_1_2,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG_DIM__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG_DIM__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SPEC_REG_DIM__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CVT__STYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CVT__TYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CVT__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CVT__ROUNDING[] =
{
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO,
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN_SAT,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_ZERO,
    Brig::BRIG_ROUND_INTEGER_ZERO_SAT,
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CVT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CVT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CVT__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CVT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_CVT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DEBUGTRAP__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DEBUGTRAP__S0[] =
{
    OPERAND_VAL_IMM,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DEBUGTRAP__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DEBUGTRAP__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DEBUGTRAP__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DEBUGTRAP__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AQLPTR__STYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AQLPTR__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AQLPTR__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_GLOBAL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AQLPTR__S0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AQLPTR__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AQLPTR__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AQLPTR__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_AQLPTR__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DIV__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DIV__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DIV__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SS,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DIV__ROUNDING[] =
{
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO,
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DIV__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DIV__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DIV__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DIV__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_DIV__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_EXPAND__STYPE[] =
{
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_EXPAND__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_EXPAND__D0[] =
{
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_EXPAND__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_EXPAND__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_EXPAND__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_EXPAND__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FIRSTBIT__STYPE[] =
{
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FIRSTBIT__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FIRSTBIT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FIRSTBIT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FIRSTBIT__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FIRSTBIT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FIRSTBIT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FMA__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FMA__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FMA__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FMA__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FMA__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FMA__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FMA__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FMA__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FMA__ROUNDING[] =
{
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FRACT__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FRACT__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_P,
    Brig::BRIG_PACK_S,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FRACT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FRACT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FRACT__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FRACT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FRACT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FRACT__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FRACT__ROUNDING[] =
{
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_F2S__STYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_F2S__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_F2S__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_F2S__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_F2S__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_F2S__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_F2S__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_F2S__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_APPEND_CONSUME__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_APPEND_CONSUME__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_EXTSPACE0,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_APPEND_CONSUME__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_APPEND_CONSUME__S1[] =
{
    OPERAND_VAL_ADDR_SEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_APPEND_CONSUME__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_APPEND_CONSUME__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_APPEND_CONSUME__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__ATMOP[] =
{
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_LD,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_EXTSPACE0,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__MEMORD[] =
{
    Brig::BRIG_MEMORY_ORDER_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_ACQUIRE_RELEASE,
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_NULL,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_NULL,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__S1[] =
{
    OPERAND_VAL_ADDR_SEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC__MEMSCP[] =
{
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__ATMOP[] =
{
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_INC,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_ST,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_EXTSPACE0,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__MEMORD[] =
{
    Brig::BRIG_MEMORY_ORDER_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_ACQUIRE_RELEASE,
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_NULL,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__S0[] =
{
    OPERAND_VAL_ADDR_SEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ATOMIC_NORET__MEMSCP[] =
{
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_B4XCHG__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_B4XCHG__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_B4XCHG__S1[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_B4XCHG__S2[] =
{
    OPERAND_VAL_IMM_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_B4XCHG__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_B4XCHG__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_BFM__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_BFM__D0[] =
{
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_BFM__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_BFM__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_BFM__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_BFM__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FLDEXP__TYPE[] =
{
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FLDEXP__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FLDEXP__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FLDEXP__S2[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FLDEXP__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FLDEXP__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_EXP__TYPE[] =
{
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_EXP__D0[] =
{
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_EXP__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_EXP__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_EXP__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_EXP__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_MANT__TYPE[] =
{
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_MANT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_MANT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_MANT__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_MANT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_FREXP_MANT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__TYPE[] =
{
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_EXTSPACE0,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__D0[] =
{
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__S1[] =
{
    OPERAND_VAL_ADDR_TSEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__ALIGN[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__EQCLASS[] =
{
    EQCLASS_VAL_ANY,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_LD__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MAD__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MAD__D0[] =
{
    OPERAND_VAL_REG_64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MAD__S1[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MAD__S2[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MAD__S3[] =
{
    OPERAND_VAL_IMM_64,
    OPERAND_VAL_REG_64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MAD__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MIN_MAX_MED__TYPE[] =
{
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MIN_MAX_MED__D0[] =
{
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MIN_MAX_MED__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MIN_MAX_MED__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MIN_MAX_MED__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MIN_MAX_MED__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD__TYPE[] =
{
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD__S2[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD__S3[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD4__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD4__D0[] =
{
    OPERAND_VAL_REG_V4_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD4__S1[] =
{
    OPERAND_VAL_IMM_64,
    OPERAND_VAL_REG_64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD4__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD4__S3[] =
{
    OPERAND_VAL_REG_V4_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MQSAD4__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MSAD__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MSAD__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MSAD__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MSAD__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MSAD__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_MSAD__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_SLP_PRT__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_SLP_PRT__S0[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_SLP_PRT__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_SLP_PRT__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_SLP_PRT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_SLP_PRT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_QSAD__TYPE[] =
{
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_QSAD__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_QSAD__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_QSAD__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_QSAD__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_QSAD__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_REGION_ALLOC__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_REGION_ALLOC__S0[] =
{
    OPERAND_VAL_IMM_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_REGION_ALLOC__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_REGION_ALLOC__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_REGION_ALLOC__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_REGION_ALLOC__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__TYPE[] =
{
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_EXTSPACE0,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__S0[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__S1[] =
{
    OPERAND_VAL_ADDR_TSEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__ALIGN[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__EQCLASS[] =
{
    EQCLASS_VAL_ANY,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_ST__WIDTH[] =
{
    Brig::BRIG_WIDTH_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_TRIG_PREOP__TYPE[] =
{
    Brig::BRIG_TYPE_F64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_TRIG_PREOP__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_TRIG_PREOP__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_TRIG_PREOP__S2[] =
{
    OPERAND_VAL_IMM_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_TRIG_PREOP__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_GCN_TRIG_PREOP__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__S0[] =
{
    OPERAND_VAL_FBARRIER,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__MEMFNC[] =
{
    Brig::BRIG_MEMORY_FENCE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__MEMORD[] =
{
    Brig::BRIG_MEMORY_ORDER_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__MEMSCP[] =
{
    Brig::BRIG_MEMORY_SCOPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_NONE__WIDTH[] =
{
    Brig::BRIG_WIDTH_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__S0[] =
{
    OPERAND_VAL_FBARRIER,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__MEMFNC[] =
{
    Brig::BRIG_MEMORY_FENCE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__MEMORD[] =
{
    Brig::BRIG_MEMORY_ORDER_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__MEMSCP[] =
{
    Brig::BRIG_MEMORY_SCOPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_FBAR_WIDTH__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__TYPE[] =
{
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_SAMP,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__D0[] =
{
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__S1[] =
{
    OPERAND_VAL_ADDR_TSEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__ALIGN[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__EQCLASS[] =
{
    EQCLASS_VAL_ANY,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDA__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDA__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDA__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDA__S1[] =
{
    OPERAND_VAL_ADDR_SEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDA__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDA__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDA__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDC__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDC__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDC__S1[] =
{
    OPERAND_VAL_FUNC,
    OPERAND_VAL_LAB,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDC__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDC__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDC__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDF__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDF__S0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDF__S1[] =
{
    OPERAND_VAL_FBARRIER,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDF__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDF__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LDF__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD_IMAGE__CTYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD_IMAGE__TYPE[] =
{
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD_IMAGE__GEOM[] =
{
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_1DB,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD_IMAGE__ITYPE[] =
{
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD_IMAGE__S1[] =
{
    OPERAND_VAL_REG_64,
    OPERAND_VAL_ROIMAGE,
    OPERAND_VAL_RWIMAGE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD_IMAGE__S2[] =
{
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD_IMAGE__D0[] =
{
    OPERAND_VAL_REG_V4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD_IMAGE__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LD_IMAGE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LERP__TYPE[] =
{
    Brig::BRIG_TYPE_U8X4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LERP__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LERP__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LERP__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LERP__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_LERP__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD__TYPE[] =
{
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD24__TYPE[] =
{
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD24__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD24__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD24__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD24__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAD24__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MASKLANE__STYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MASKLANE__TYPE[] =
{
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MASKLANE__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MASKLANE__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MASKLANE__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MASKLANE__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MASKLANE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MASKLANE__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAX__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAX__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAX__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SS,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAX__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAX__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAX__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAX__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAX__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MAX__ROUNDING[] =
{
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MOV__TYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_SAMP,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MOV__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MOV__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MOV__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MOV__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MOV__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PPSAT,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_PSSAT,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SPSAT,
    Brig::BRIG_PACK_SS,
    Brig::BRIG_PACK_SSSAT,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL__ROUNDING[] =
{
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO,
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL24__TYPE[] =
{
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL24__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL24__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL24__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL24__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MUL24__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MULHI__TYPE[] =
{
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MULHI__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SS,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MULHI__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MULHI__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MULHI__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MULHI__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MULHI__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MULHI__FTZ[] =
{
    0,
};

unsigned PropDescImpl::REQ_PROP_VALUES_MULHI__ROUNDING[] =
{
    Brig::BRIG_ROUND_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG32__TYPE[] =
{
    Brig::BRIG_TYPE_F32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG32__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG32__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG32__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG32__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG32__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NFMA__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NFMA__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NFMA__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NFMA__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NFMA__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NFMA__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOP__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOP__S0[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOP__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOP__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOP__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOP__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOT__TYPE[] =
{
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOT__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NOT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_TRIG__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NULLPTR__STYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NULLPTR__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NULLPTR__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NULLPTR__S0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NULLPTR__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NULLPTR__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NULLPTR__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_NULLPTR__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACK__STYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACK__TYPE[] =
{
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACK__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACK__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACK__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACK__S3[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACK__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACKCVT__STYPE[] =
{
    Brig::BRIG_TYPE_F32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACKCVT__TYPE[] =
{
    Brig::BRIG_TYPE_U8X4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACKCVT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACKCVT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACKCVT__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACKCVT__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_PACKCVT__S4[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_POPCOUNT__STYPE[] =
{
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_POPCOUNT__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_POPCOUNT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_POPCOUNT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_POPCOUNT__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_POPCOUNT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_POPCOUNT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYIMAGE__STYPE[] =
{
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYIMAGE__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYIMAGE__S1[] =
{
    OPERAND_VAL_REG_64,
    OPERAND_VAL_ROIMAGE,
    OPERAND_VAL_RWIMAGE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYIMAGE__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYIMAGE__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYIMAGE__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYIMAGE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__STYPE[] =
{
    Brig::BRIG_TYPE_SAMP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S1[] =
{
    OPERAND_VAL_REG_64,
    OPERAND_VAL_SAMPLER,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S2[] =
{
    OPERAND_VAL_IMM_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLER__STYPE[] =
{
    Brig::BRIG_TYPE_SAMP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLER__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLER__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLER__S1[] =
{
    OPERAND_VAL_REG_64,
    OPERAND_VAL_SAMPLER,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLER__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLER__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_QUERYSAMPLER__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RDIMAGE__CTYPE[] =
{
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RDIMAGE__TYPE[] =
{
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RDIMAGE__GEOM[] =
{
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RDIMAGE__ITYPE[] =
{
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RDIMAGE__S1[] =
{
    OPERAND_VAL_REG_64,
    OPERAND_VAL_ROIMAGE,
    OPERAND_VAL_RWIMAGE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RDIMAGE__S3[] =
{
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RDIMAGE__D0[] =
{
    OPERAND_VAL_REG_V4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RDIMAGE__S2[] =
{
    OPERAND_VAL_REG_64,
    OPERAND_VAL_SAMPLER,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RDIMAGE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SENDLANE__STYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SENDLANE__TYPE[] =
{
    Brig::BRIG_TYPE_B32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SENDLANE__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SENDLANE__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SENDLANE__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SENDLANE__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SENDLANE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SENDLANE__WIDTH[] =
{
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RET__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RET__S0[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RET__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RET__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RET__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_RET__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SAD__STYPE[] =
{
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U8X4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SAD__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SAD__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SAD__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SAD__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SAD__S3[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SAD__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SADHI__STYPE[] =
{
    Brig::BRIG_TYPE_U8X4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SADHI__TYPE[] =
{
    Brig::BRIG_TYPE_U16X2,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SADHI__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SADHI__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SADHI__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SADHI__S3[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SADHI__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SEGMENTP__STYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SEGMENTP__TYPE[] =
{
    Brig::BRIG_TYPE_B1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SEGMENTP__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SEGMENTP__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SEGMENTP__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SEGMENTP__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SEGMENTP__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SEGMENTP__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHIFT__TYPE[] =
{
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHIFT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHIFT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHIFT__S2[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHIFT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHIFT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHUFFLE__TYPE[] =
{
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHUFFLE__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHUFFLE__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHUFFLE__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHUFFLE__S3[] =
{
    OPERAND_VAL_IMM,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SHUFFLE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SQRT__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_F64X2,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SQRT__PACKING[] =
{
    Brig::BRIG_PACK_NONE,
    Brig::BRIG_PACK_P,
    Brig::BRIG_PACK_S,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SQRT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SQRT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SQRT__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SQRT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SQRT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SQRT__FTZ[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SQRT__ROUNDING[] =
{
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__TYPE[] =
{
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_SAMP,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_SPILL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__S0[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__S1[] =
{
    OPERAND_VAL_ADDR_TSEG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__ALIGN[] =
{
    0,
    1,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__EQCLASS[] =
{
    EQCLASS_VAL_ANY,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST__WIDTH[] =
{
    Brig::BRIG_WIDTH_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST_IMAGE__CTYPE[] =
{
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST_IMAGE__TYPE[] =
{
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST_IMAGE__GEOM[] =
{
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_1DB,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST_IMAGE__S2[] =
{
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST_IMAGE__S0[] =
{
    OPERAND_VAL_REG_V4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST_IMAGE__S1[] =
{
    OPERAND_VAL_REG_64,
    OPERAND_VAL_RWIMAGE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST_IMAGE__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST_IMAGE__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_ST_IMAGE__ITYPE[] =
{
    Brig::BRIG_TYPE_RWIMG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_S2F__STYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_S2F__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_S2F__SEGMENT[] =
{
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_S2F__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_S2F__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_S2F__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_S2F__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_S2F__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__TYPE[] =
{
    Brig::BRIG_TYPE_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__S0[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__S1[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__S2[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__MEMFNC[] =
{
    Brig::BRIG_MEMORY_FENCE_BOTH,
    Brig::BRIG_MEMORY_FENCE_GLOBAL,
    Brig::BRIG_MEMORY_FENCE_GROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__MEMORD[] =
{
    Brig::BRIG_MEMORY_ORDER_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_ACQUIRE_RELEASE,
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SEQUENTIALLY_CONSISTENT,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__MEMSCP[] =
{
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYNC__WIDTH[] =
{
    Brig::BRIG_WIDTH_NONE,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYSCALL__TYPE[] =
{
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYSCALL__S0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYSCALL__S1[] =
{
    OPERAND_VAL_IMM,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYSCALL__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYSCALL__S3[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_SYSCALL__S4[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACK__STYPE[] =
{
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U64X2,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACK__TYPE[] =
{
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACK__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACK__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACK__S2[] =
{
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACK__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACK__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKCVT__STYPE[] =
{
    Brig::BRIG_TYPE_U8X4,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKCVT__TYPE[] =
{
    Brig::BRIG_TYPE_F32,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKCVT__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKCVT__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKCVT__S2[] =
{
    OPERAND_VAL_IMM_0_1_2_3,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKCVT__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKCVT__S4[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKX__TYPE[] =
{
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKX__D0[] =
{
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKX__S1[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKX__S2[] =
{
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKX__S3[] =
{
    OPERAND_VAL_NULL,
};

unsigned PropDescImpl::REQ_PROP_VALUES_UNPACKX__S4[] =
{
    OPERAND_VAL_NULL,
};

const unsigned* PropDescImpl::getPropVals(unsigned opcode, unsigned propId, unsigned& num) 
{
    switch(opcode)
    {
    case Brig::BRIG_OPCODE_ABS:
    case Brig::BRIG_OPCODE_NEG:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_NEG__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_NEG__TYPE;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_NEG__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_NEG__PACKING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_NEG__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_NEG__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_NEG__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_NEG__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_NEG__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_NEG__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_NEG__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_NEG__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_NEG__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_NEG__S4;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_NEG__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_NEG__FTZ;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_NEG__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_NEG__ROUNDING;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_ADD:
    case Brig::BRIG_OPCODE_SUB:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_ADD__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ADD__TYPE;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_ADD__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_ADD__FTZ;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_ADD__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_ADD__PACKING;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_ADD__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_ADD__ROUNDING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_ADD__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_ADD__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_ADD__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_ADD__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_ADD__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_ADD__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_ADD__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_ADD__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_ADD__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_ADD__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_ALLOCA:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_ALLOCA__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALLOCA__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_ALLOCA__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALLOCA__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_ALLOCA__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALLOCA__SEGMENT;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_ALLOCA__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALLOCA__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_ALLOCA__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALLOCA__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_ALLOCA__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALLOCA__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_ALLOCA__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALLOCA__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_ALLOCA__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALLOCA__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_AND:
    case Brig::BRIG_OPCODE_OR:
    case Brig::BRIG_OPCODE_XOR:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_AND__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_AND__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_AND__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_AND__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_AND__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_AND__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_AND__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_AND__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_AND__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_AND__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_AND__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_AND__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_ARRIVEFBAR:
    case Brig::BRIG_OPCODE_WAITFBAR:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__S4;
        case PROP_MEMFNC:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMFNC) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMFNC;
        case PROP_MEMORD:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMORD) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMORD;
        case PROP_MEMSCP:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMSCP) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__MEMSCP;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_FBAR_SYNC_WIDTH__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_SYNC_WIDTH__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_ATOMIC:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__TYPE;
        case PROP_ATMOP:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__ATMOP) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__ATMOP;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__SEGMENT;
        case PROP_MEMORD:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__MEMORD) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__MEMORD;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__S3;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__S1;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__S4;
        case PROP_MEMSCP:
            num = sizeof(REQ_PROP_VALUES_ATOMIC__MEMSCP) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC__MEMSCP;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_ATOMICIMAGE:
        switch(propId)
        {
        case PROP_CTYPE:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__CTYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__CTYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__TYPE;
        case PROP_ATMOP:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__ATMOP) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__ATMOP;
        case PROP_GEOM:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__GEOM) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__GEOM;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__S2;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__S4;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__S1;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__S3;
        case PROP_ITYPE:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_IMAGE__ITYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_IMAGE__ITYPE;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_ATOMICIMAGENORET:
        switch(propId)
        {
        case PROP_CTYPE:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__CTYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__CTYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__TYPE;
        case PROP_ATMOP:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__ATMOP) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__ATMOP;
        case PROP_GEOM:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__GEOM) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__GEOM;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S1;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S3;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S0;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S2;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__S4;
        case PROP_ITYPE:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__ITYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET_IMAGE__ITYPE;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_ATOMICNORET:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__TYPE;
        case PROP_ATMOP:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__ATMOP) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__ATMOP;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__SEGMENT;
        case PROP_MEMORD:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__MEMORD) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__MEMORD;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__S2;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__S1;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__S4;
        case PROP_MEMSCP:
            num = sizeof(REQ_PROP_VALUES_ATOMIC_NORET__MEMSCP) / sizeof(unsigned);
            return REQ_PROP_VALUES_ATOMIC_NORET__MEMSCP;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_BARRIER:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_BARRIER__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_BARRIER__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_BARRIER__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_BARRIER__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_BARRIER__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_BARRIER__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__S4;
        case PROP_MEMFNC:
            num = sizeof(REQ_PROP_VALUES_BARRIER__MEMFNC) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__MEMFNC;
        case PROP_MEMORD:
            num = sizeof(REQ_PROP_VALUES_BARRIER__MEMORD) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__MEMORD;
        case PROP_MEMSCP:
            num = sizeof(REQ_PROP_VALUES_BARRIER__MEMSCP) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__MEMSCP;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_BARRIER__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_BARRIER__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_BITALIGN:
    case Brig::BRIG_OPCODE_BYTEALIGN:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_ALIGN__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALIGN__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_ALIGN__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALIGN__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_ALIGN__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALIGN__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_ALIGN__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALIGN__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_ALIGN__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALIGN__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_ALIGN__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_ALIGN__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_BITEXTRACT:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_BITEXTRACT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITEXTRACT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_BITEXTRACT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITEXTRACT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_BITEXTRACT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITEXTRACT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_BITEXTRACT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITEXTRACT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_BITEXTRACT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITEXTRACT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_BITEXTRACT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITEXTRACT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_BITINSERT:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_BITINSERT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITINSERT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_BITINSERT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITINSERT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_BITINSERT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITINSERT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_BITINSERT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITINSERT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_BITINSERT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITINSERT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_BITINSERT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITINSERT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_BITMASK:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_BITMASK__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITMASK__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_BITMASK__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITMASK__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_BITMASK__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITMASK__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_BITMASK__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITMASK__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_BITMASK__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITMASK__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_BITMASK__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITMASK__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_BITREV:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_BITREV__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITREV__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_BITREV__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITREV__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_BITREV__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITREV__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_BITREV__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITREV__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_BITREV__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITREV__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_BITREV__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITREV__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_BITSELECT:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_BITSELECT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITSELECT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_BITSELECT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITSELECT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_BITSELECT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITSELECT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_BITSELECT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITSELECT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_BITSELECT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITSELECT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_BITSELECT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_BITSELECT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_BORROW:
    case Brig::BRIG_OPCODE_CARRY:
    case Brig::BRIG_OPCODE_REM:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_REM__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_REM__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_REM__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_REM__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_REM__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_REM__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_REM__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_REM__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_REM__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_REM__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_REM__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_REM__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_BRN:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_BRN__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_BRN__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_BRN__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_BRN__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_BRN__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_BRN__S1;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_BRN__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_BRN__WIDTH;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_BRN__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_BRN__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_BRN__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_BRN__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_BRN__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_BRN__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CALL:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_CALL__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CALL__TYPE;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_CALL__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_CALL__S1;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_CALL__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_CALL__S3;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_CALL__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_CALL__WIDTH;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_CALL__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_CALL__S0;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_CALL__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_CALL__S2;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_CALL__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_CALL__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CBR:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_CBR__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CBR__TYPE;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_CBR__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_CBR__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_CBR__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_CBR__S2;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_CBR__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_CBR__S0;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_CBR__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_CBR__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_CBR__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_CBR__S4;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_CBR__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_CBR__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CEIL:
    case Brig::BRIG_OPCODE_FLOOR:
    case Brig::BRIG_OPCODE_RINT:
    case Brig::BRIG_OPCODE_TRUNC:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_CEIL__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CEIL__TYPE;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_CEIL__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_CEIL__PACKING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_CEIL__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_CEIL__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_CEIL__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_CEIL__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_CEIL__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_CEIL__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_CEIL__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_CEIL__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_CEIL__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_CEIL__S4;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_CEIL__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_CEIL__FTZ;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_CEIL__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_CEIL__ROUNDING;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CLASS:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_CLASS__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CLASS__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_CLASS__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CLASS__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_CLASS__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_CLASS__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_CLASS__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_CLASS__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_CLASS__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_CLASS__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_CLASS__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_CLASS__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_CLASS__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_CLASS__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CLEARDETECTEXCEPT:
    case Brig::BRIG_OPCODE_SETDETECTEXCEPT:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SPEC_EXCEPT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_EXCEPT__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_SPEC_EXCEPT__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_EXCEPT__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SPEC_EXCEPT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_EXCEPT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SPEC_EXCEPT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_EXCEPT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SPEC_EXCEPT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_EXCEPT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SPEC_EXCEPT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_EXCEPT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CLOCK:
    case Brig::BRIG_OPCODE_DISPATCHID:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SPEC_CLOCK__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_CLOCK__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SPEC_CLOCK__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_CLOCK__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SPEC_CLOCK__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_CLOCK__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SPEC_CLOCK__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_CLOCK__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SPEC_CLOCK__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_CLOCK__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SPEC_CLOCK__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_CLOCK__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CMOV:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_CMOV__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMOV__TYPE;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_CMOV__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMOV__S1;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_CMOV__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMOV__D0;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_CMOV__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMOV__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_CMOV__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMOV__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_CMOV__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMOV__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CMP:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_CMP__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_CMP__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__TYPE;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_CMP__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__FTZ;
        case PROP_OPERATOR:
            num = sizeof(REQ_PROP_VALUES_CMP__OPERATOR) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__OPERATOR;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_CMP__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__PACKING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_CMP__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_CMP__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_CMP__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_CMP__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_CMP__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__S4;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_CMP__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_CMP__ROUNDING;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CODEBLOCKEND:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_CODEBLOCKEND__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CODEBLOCKEND__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_CODEBLOCKEND__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_CODEBLOCKEND__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_CODEBLOCKEND__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_CODEBLOCKEND__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_CODEBLOCKEND__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_CODEBLOCKEND__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_CODEBLOCKEND__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_CODEBLOCKEND__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_CODEBLOCKEND__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_CODEBLOCKEND__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_COMBINE:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_COMBINE__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_COMBINE__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_COMBINE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_COMBINE__TYPE;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_COMBINE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_COMBINE__S1;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_COMBINE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_COMBINE__D0;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_COMBINE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_COMBINE__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_COMBINE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_COMBINE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_COMBINE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_COMBINE__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_COPYSIGN:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_COPYSIGN__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_COPYSIGN__TYPE;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_COPYSIGN__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_COPYSIGN__PACKING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_COPYSIGN__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_COPYSIGN__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_COPYSIGN__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_COPYSIGN__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_COPYSIGN__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_COPYSIGN__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_COPYSIGN__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_COPYSIGN__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_COPYSIGN__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_COPYSIGN__S4;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_COPYSIGN__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_COPYSIGN__FTZ;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_COPYSIGN__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_COPYSIGN__ROUNDING;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_COUNTLANE:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_COUNTLANE__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTLANE__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_COUNTLANE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTLANE__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_COUNTLANE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTLANE__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_COUNTLANE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTLANE__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_COUNTLANE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTLANE__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_COUNTLANE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTLANE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_COUNTLANE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTLANE__S4;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_COUNTLANE__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTLANE__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_COUNTUPLANE:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_COUNTUPLANE__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTUPLANE__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_COUNTUPLANE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTUPLANE__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_COUNTUPLANE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTUPLANE__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_COUNTUPLANE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTUPLANE__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_COUNTUPLANE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTUPLANE__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_COUNTUPLANE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTUPLANE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_COUNTUPLANE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTUPLANE__S4;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_COUNTUPLANE__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_COUNTUPLANE__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CUID:
    case Brig::BRIG_OPCODE_DIM:
    case Brig::BRIG_OPCODE_GETDETECTEXCEPT:
    case Brig::BRIG_OPCODE_LANEID:
    case Brig::BRIG_OPCODE_MAXCUID:
    case Brig::BRIG_OPCODE_MAXWAVEID:
    case Brig::BRIG_OPCODE_QID:
    case Brig::BRIG_OPCODE_WAVEID:
    case Brig::BRIG_OPCODE_WORKITEMFLATABSID:
    case Brig::BRIG_OPCODE_WORKITEMFLATID:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE:
    case Brig::BRIG_OPCODE_GRIDGROUPS:
    case Brig::BRIG_OPCODE_GRIDSIZE:
    case Brig::BRIG_OPCODE_WORKGROUPID:
    case Brig::BRIG_OPCODE_WORKGROUPSIZE:
    case Brig::BRIG_OPCODE_WORKITEMABSID:
    case Brig::BRIG_OPCODE_WORKITEMID:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG_DIM__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG_DIM__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG_DIM__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG_DIM__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG_DIM__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG_DIM__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG_DIM__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG_DIM__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG_DIM__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG_DIM__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SPEC_REG_DIM__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SPEC_REG_DIM__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_CVT:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_CVT__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CVT__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_CVT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_CVT__TYPE;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_CVT__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_CVT__FTZ;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_CVT__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_CVT__ROUNDING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_CVT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_CVT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_CVT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_CVT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_CVT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_CVT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_CVT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_CVT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_CVT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_CVT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_DEBUGTRAP:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_DEBUGTRAP__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_DEBUGTRAP__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_DEBUGTRAP__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_DEBUGTRAP__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_DEBUGTRAP__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_DEBUGTRAP__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_DEBUGTRAP__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_DEBUGTRAP__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_DEBUGTRAP__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_DEBUGTRAP__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_DEBUGTRAP__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_DEBUGTRAP__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_DISPATCHPTR:
    case Brig::BRIG_OPCODE_QPTR:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_AQLPTR__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_AQLPTR__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_AQLPTR__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_AQLPTR__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_AQLPTR__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_AQLPTR__SEGMENT;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_AQLPTR__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_AQLPTR__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_AQLPTR__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_AQLPTR__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_AQLPTR__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_AQLPTR__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_AQLPTR__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_AQLPTR__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_AQLPTR__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_AQLPTR__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_DIV:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_DIV__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_DIV__TYPE;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_DIV__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_DIV__FTZ;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_DIV__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_DIV__PACKING;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_DIV__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_DIV__ROUNDING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_DIV__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_DIV__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_DIV__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_DIV__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_DIV__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_DIV__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_DIV__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_DIV__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_DIV__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_DIV__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_EXPAND:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_EXPAND__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_EXPAND__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_EXPAND__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_EXPAND__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_EXPAND__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_EXPAND__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_EXPAND__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_EXPAND__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_EXPAND__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_EXPAND__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_EXPAND__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_EXPAND__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_EXPAND__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_EXPAND__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_FIRSTBIT:
    case Brig::BRIG_OPCODE_LASTBIT:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_FIRSTBIT__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_FIRSTBIT__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_FIRSTBIT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_FIRSTBIT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_FIRSTBIT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_FIRSTBIT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_FIRSTBIT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_FIRSTBIT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_FIRSTBIT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_FIRSTBIT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_FIRSTBIT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_FIRSTBIT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_FIRSTBIT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_FIRSTBIT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_FMA:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_FMA__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_FMA__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_FMA__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_FMA__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_FMA__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_FMA__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_FMA__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_FMA__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_FMA__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_FMA__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_FMA__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_FMA__S4;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_FMA__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_FMA__FTZ;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_FMA__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_FMA__PACKING;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_FMA__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_FMA__ROUNDING;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_FRACT:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_FRACT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_FRACT__TYPE;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_FRACT__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_FRACT__PACKING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_FRACT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_FRACT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_FRACT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_FRACT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_FRACT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_FRACT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_FRACT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_FRACT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_FRACT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_FRACT__S4;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_FRACT__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_FRACT__FTZ;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_FRACT__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_FRACT__ROUNDING;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_FTOS:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_F2S__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_F2S__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_F2S__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_F2S__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_F2S__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_F2S__SEGMENT;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_F2S__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_F2S__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_F2S__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_F2S__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_F2S__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_F2S__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_F2S__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_F2S__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_F2S__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_F2S__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNAPPEND:
    case Brig::BRIG_OPCODE_GCNCONSUME:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_APPEND_CONSUME__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_APPEND_CONSUME__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_GCN_APPEND_CONSUME__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_APPEND_CONSUME__SEGMENT;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_APPEND_CONSUME__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_APPEND_CONSUME__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_APPEND_CONSUME__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_APPEND_CONSUME__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_APPEND_CONSUME__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_APPEND_CONSUME__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_APPEND_CONSUME__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_APPEND_CONSUME__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_APPEND_CONSUME__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_APPEND_CONSUME__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNATOMIC:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__TYPE;
        case PROP_ATMOP:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__ATMOP) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__ATMOP;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__SEGMENT;
        case PROP_MEMORD:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__MEMORD) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__MEMORD;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__S3;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__S1;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__S4;
        case PROP_MEMSCP:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC__MEMSCP) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC__MEMSCP;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNATOMICNORET:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__TYPE;
        case PROP_ATMOP:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__ATMOP) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__ATMOP;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__SEGMENT;
        case PROP_MEMORD:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__MEMORD) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__MEMORD;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__S2;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__S1;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__S4;
        case PROP_MEMSCP:
            num = sizeof(REQ_PROP_VALUES_GCN_ATOMIC_NORET__MEMSCP) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ATOMIC_NORET__MEMSCP;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNB32XCHG:
    case Brig::BRIG_OPCODE_GCNB4XCHG:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_B4XCHG__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_B4XCHG__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_B4XCHG__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_B4XCHG__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_B4XCHG__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_B4XCHG__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_B4XCHG__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_B4XCHG__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_B4XCHG__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_B4XCHG__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_B4XCHG__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_B4XCHG__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNBFM:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_BFM__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_BFM__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_BFM__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_BFM__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_BFM__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_BFM__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_BFM__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_BFM__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_BFM__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_BFM__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_BFM__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_BFM__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNFLDEXP:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_FLDEXP__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FLDEXP__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_FLDEXP__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FLDEXP__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_FLDEXP__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FLDEXP__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_FLDEXP__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FLDEXP__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_FLDEXP__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FLDEXP__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_FLDEXP__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FLDEXP__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNFREXP_EXP:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_EXP__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_EXP__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_EXP__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_EXP__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_EXP__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_EXP__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_EXP__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_EXP__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_EXP__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_EXP__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_EXP__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_EXP__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNFREXP_MANT:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_MANT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_MANT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_MANT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_MANT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_MANT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_MANT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_MANT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_MANT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_MANT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_MANT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_FREXP_MANT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_FREXP_MANT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNLD:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__SEGMENT;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__S4;
        case PROP_ALIGN:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__ALIGN) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__ALIGN;
        case PROP_EQCLASS:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__EQCLASS) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__EQCLASS;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_GCN_LD__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_LD__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNMADS:
    case Brig::BRIG_OPCODE_GCNMADU:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_MAD__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MAD__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_MAD__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MAD__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_MAD__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MAD__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_MAD__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MAD__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_MAD__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MAD__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_MAD__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MAD__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNMAX3:
    case Brig::BRIG_OPCODE_GCNMED3:
    case Brig::BRIG_OPCODE_GCNMIN3:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_MIN_MAX_MED__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MIN_MAX_MED__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_MIN_MAX_MED__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MIN_MAX_MED__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_MIN_MAX_MED__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MIN_MAX_MED__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_MIN_MAX_MED__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MIN_MAX_MED__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_MIN_MAX_MED__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MIN_MAX_MED__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_MIN_MAX_MED__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MIN_MAX_MED__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNMQSAD:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNMQSAD4:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD4__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD4__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD4__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD4__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD4__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD4__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD4__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD4__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD4__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD4__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_MQSAD4__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MQSAD4__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNMSAD:
    case Brig::BRIG_OPCODE_GCNSADD:
    case Brig::BRIG_OPCODE_GCNSADW:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_MSAD__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MSAD__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_MSAD__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MSAD__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_MSAD__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MSAD__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_MSAD__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MSAD__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_MSAD__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MSAD__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_MSAD__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_MSAD__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNPRIORITY:
    case Brig::BRIG_OPCODE_GCNSLEEP:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_SLP_PRT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_SLP_PRT__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_GCN_SLP_PRT__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_SLP_PRT__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_SLP_PRT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_SLP_PRT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_SLP_PRT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_SLP_PRT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_SLP_PRT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_SLP_PRT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_SLP_PRT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_SLP_PRT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNQSAD:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_QSAD__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_QSAD__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_QSAD__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_QSAD__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_QSAD__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_QSAD__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_QSAD__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_QSAD__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_QSAD__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_QSAD__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_QSAD__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_QSAD__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNREGIONALLOC:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_REGION_ALLOC__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_REGION_ALLOC__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_GCN_REGION_ALLOC__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_REGION_ALLOC__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_REGION_ALLOC__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_REGION_ALLOC__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_REGION_ALLOC__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_REGION_ALLOC__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_REGION_ALLOC__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_REGION_ALLOC__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_REGION_ALLOC__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_REGION_ALLOC__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNST:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__SEGMENT;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__S4;
        case PROP_ALIGN:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__ALIGN) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__ALIGN;
        case PROP_EQCLASS:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__EQCLASS) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__EQCLASS;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_GCN_ST__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_ST__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_GCNTRIG_PREOP:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_GCN_TRIG_PREOP__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_TRIG_PREOP__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_GCN_TRIG_PREOP__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_TRIG_PREOP__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_GCN_TRIG_PREOP__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_TRIG_PREOP__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_GCN_TRIG_PREOP__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_TRIG_PREOP__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_GCN_TRIG_PREOP__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_TRIG_PREOP__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_GCN_TRIG_PREOP__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_GCN_TRIG_PREOP__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_INITFBAR:
    case Brig::BRIG_OPCODE_RELEASEFBAR:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__S4;
        case PROP_MEMFNC:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__MEMFNC) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__MEMFNC;
        case PROP_MEMORD:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__MEMORD) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__MEMORD;
        case PROP_MEMSCP:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__MEMSCP) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__MEMSCP;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_FBAR_NONE__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_NONE__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_JOINFBAR:
    case Brig::BRIG_OPCODE_LEAVEFBAR:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__S4;
        case PROP_MEMFNC:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__MEMFNC) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__MEMFNC;
        case PROP_MEMORD:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__MEMORD) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__MEMORD;
        case PROP_MEMSCP:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__MEMSCP) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__MEMSCP;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_FBAR_WIDTH__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_FBAR_WIDTH__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_LD:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_LD__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_LD__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__SEGMENT;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_LD__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_LD__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_LD__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_LD__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_LD__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__S4;
        case PROP_ALIGN:
            num = sizeof(REQ_PROP_VALUES_LD__ALIGN) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__ALIGN;
        case PROP_EQCLASS:
            num = sizeof(REQ_PROP_VALUES_LD__EQCLASS) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__EQCLASS;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_LD__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_LDA:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_LDA__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDA__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_LDA__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDA__SEGMENT;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_LDA__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDA__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_LDA__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDA__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_LDA__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDA__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_LDA__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDA__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_LDA__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDA__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_LDC:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_LDC__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDC__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_LDC__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDC__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_LDC__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDC__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_LDC__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDC__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_LDC__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDC__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_LDC__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDC__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_LDF:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_LDF__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDF__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_LDF__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDF__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_LDF__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDF__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_LDF__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDF__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_LDF__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDF__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_LDF__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_LDF__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_LDIMAGE:
        switch(propId)
        {
        case PROP_CTYPE:
            num = sizeof(REQ_PROP_VALUES_LD_IMAGE__CTYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD_IMAGE__CTYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_LD_IMAGE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD_IMAGE__TYPE;
        case PROP_GEOM:
            num = sizeof(REQ_PROP_VALUES_LD_IMAGE__GEOM) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD_IMAGE__GEOM;
        case PROP_ITYPE:
            num = sizeof(REQ_PROP_VALUES_LD_IMAGE__ITYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD_IMAGE__ITYPE;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_LD_IMAGE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD_IMAGE__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_LD_IMAGE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD_IMAGE__S2;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_LD_IMAGE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD_IMAGE__D0;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_LD_IMAGE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD_IMAGE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_LD_IMAGE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_LD_IMAGE__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_LERP:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_LERP__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_LERP__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_LERP__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_LERP__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_LERP__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_LERP__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_LERP__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_LERP__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_LERP__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_LERP__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_LERP__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_LERP__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_MAD:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_MAD__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_MAD__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_MAD__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_MAD__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_MAD__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_MAD__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_MAD24:
    case Brig::BRIG_OPCODE_MAD24HI:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_MAD24__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD24__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_MAD24__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD24__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_MAD24__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD24__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_MAD24__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD24__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_MAD24__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD24__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_MAD24__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAD24__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_MASKLANE:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_MASKLANE__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_MASKLANE__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_MASKLANE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_MASKLANE__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_MASKLANE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_MASKLANE__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_MASKLANE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_MASKLANE__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_MASKLANE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_MASKLANE__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_MASKLANE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_MASKLANE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_MASKLANE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_MASKLANE__S4;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_MASKLANE__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_MASKLANE__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_MAX:
    case Brig::BRIG_OPCODE_MIN:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_MAX__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAX__TYPE;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_MAX__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAX__FTZ;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_MAX__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAX__PACKING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_MAX__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAX__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_MAX__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAX__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_MAX__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAX__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_MAX__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAX__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_MAX__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAX__S4;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_MAX__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_MAX__ROUNDING;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_MOV:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_MOV__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_MOV__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_MOV__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_MOV__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_MOV__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_MOV__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_MOV__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_MOV__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_MOV__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_MOV__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_MOV__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_MOV__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_MUL:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_MUL__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL__TYPE;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_MUL__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL__FTZ;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_MUL__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL__PACKING;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_MUL__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL__ROUNDING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_MUL__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_MUL__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_MUL__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_MUL__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_MUL__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_MUL24:
    case Brig::BRIG_OPCODE_MUL24HI:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_MUL24__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL24__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_MUL24__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL24__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_MUL24__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL24__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_MUL24__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL24__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_MUL24__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL24__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_MUL24__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_MUL24__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_MULHI:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_MULHI__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_MULHI__TYPE;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_MULHI__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_MULHI__PACKING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_MULHI__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_MULHI__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_MULHI__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_MULHI__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_MULHI__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_MULHI__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_MULHI__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_MULHI__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_MULHI__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_MULHI__S4;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_MULHI__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_MULHI__FTZ;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_MULHI__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_MULHI__ROUNDING;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_NCOS:
    case Brig::BRIG_OPCODE_NEXP2:
    case Brig::BRIG_OPCODE_NLOG2:
    case Brig::BRIG_OPCODE_NSIN:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_TRIG32__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG32__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_TRIG32__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG32__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_TRIG32__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG32__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_TRIG32__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG32__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_TRIG32__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG32__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_TRIG32__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG32__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_NFMA:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_NFMA__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_NFMA__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_NFMA__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_NFMA__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_NFMA__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_NFMA__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_NFMA__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_NFMA__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_NFMA__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_NFMA__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_NFMA__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_NFMA__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_NOP:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_NOP__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOP__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_NOP__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOP__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_NOP__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOP__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_NOP__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOP__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_NOP__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOP__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_NOP__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOP__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_NOT:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_NOT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_NOT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_NOT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_NOT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_NOT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_NOT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_NOT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_NRCP:
    case Brig::BRIG_OPCODE_NRSQRT:
    case Brig::BRIG_OPCODE_NSQRT:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_TRIG__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_TRIG__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_TRIG__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_TRIG__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_TRIG__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_TRIG__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_TRIG__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_NULLPTR:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_NULLPTR__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_NULLPTR__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_NULLPTR__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_NULLPTR__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_NULLPTR__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_NULLPTR__SEGMENT;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_NULLPTR__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_NULLPTR__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_NULLPTR__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_NULLPTR__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_NULLPTR__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_NULLPTR__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_NULLPTR__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_NULLPTR__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_NULLPTR__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_NULLPTR__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_PACK:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_PACK__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACK__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_PACK__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACK__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_PACK__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACK__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_PACK__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACK__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_PACK__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACK__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_PACK__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACK__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_PACK__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACK__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_PACKCVT:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_PACKCVT__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACKCVT__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_PACKCVT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACKCVT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_PACKCVT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACKCVT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_PACKCVT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACKCVT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_PACKCVT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACKCVT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_PACKCVT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACKCVT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_PACKCVT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_PACKCVT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_POPCOUNT:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_POPCOUNT__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_POPCOUNT__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_POPCOUNT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_POPCOUNT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_POPCOUNT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_POPCOUNT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_POPCOUNT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_POPCOUNT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_POPCOUNT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_POPCOUNT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_POPCOUNT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_POPCOUNT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_POPCOUNT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_POPCOUNT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_QUERYIMAGEARRAY:
    case Brig::BRIG_OPCODE_QUERYIMAGEDEPTH:
    case Brig::BRIG_OPCODE_QUERYIMAGEFORMAT:
    case Brig::BRIG_OPCODE_QUERYIMAGEHEIGHT:
    case Brig::BRIG_OPCODE_QUERYIMAGEORDER:
    case Brig::BRIG_OPCODE_QUERYIMAGEWIDTH:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_QUERYIMAGE__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYIMAGE__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_QUERYIMAGE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYIMAGE__TYPE;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_QUERYIMAGE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYIMAGE__S1;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_QUERYIMAGE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYIMAGE__D0;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_QUERYIMAGE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYIMAGE__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_QUERYIMAGE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYIMAGE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_QUERYIMAGE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYIMAGE__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_QUERYSAMPLERBOUNDARY:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLERBOUNDARY__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_QUERYSAMPLERCOORD:
    case Brig::BRIG_OPCODE_QUERYSAMPLERFILTER:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLER__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLER__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLER__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLER__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLER__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLER__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLER__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLER__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLER__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLER__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLER__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLER__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_QUERYSAMPLER__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_QUERYSAMPLER__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_RDIMAGE:
        switch(propId)
        {
        case PROP_CTYPE:
            num = sizeof(REQ_PROP_VALUES_RDIMAGE__CTYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_RDIMAGE__CTYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_RDIMAGE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_RDIMAGE__TYPE;
        case PROP_GEOM:
            num = sizeof(REQ_PROP_VALUES_RDIMAGE__GEOM) / sizeof(unsigned);
            return REQ_PROP_VALUES_RDIMAGE__GEOM;
        case PROP_ITYPE:
            num = sizeof(REQ_PROP_VALUES_RDIMAGE__ITYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_RDIMAGE__ITYPE;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_RDIMAGE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_RDIMAGE__S1;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_RDIMAGE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_RDIMAGE__S3;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_RDIMAGE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_RDIMAGE__D0;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_RDIMAGE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_RDIMAGE__S2;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_RDIMAGE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_RDIMAGE__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_RECEIVELANE:
    case Brig::BRIG_OPCODE_SENDLANE:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_SENDLANE__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SENDLANE__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SENDLANE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SENDLANE__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SENDLANE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SENDLANE__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SENDLANE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SENDLANE__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SENDLANE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SENDLANE__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SENDLANE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SENDLANE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SENDLANE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SENDLANE__S4;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_SENDLANE__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_SENDLANE__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_RET:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_RET__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_RET__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_RET__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_RET__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_RET__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_RET__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_RET__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_RET__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_RET__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_RET__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_RET__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_RET__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_SAD:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_SAD__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SAD__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SAD__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SAD__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SAD__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SAD__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SAD__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SAD__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SAD__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SAD__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SAD__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SAD__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SAD__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SAD__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_SADHI:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_SADHI__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SADHI__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SADHI__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SADHI__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SADHI__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SADHI__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SADHI__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SADHI__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SADHI__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SADHI__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SADHI__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SADHI__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SADHI__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SADHI__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_SEGMENTP:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_SEGMENTP__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SEGMENTP__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SEGMENTP__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SEGMENTP__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_SEGMENTP__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_SEGMENTP__SEGMENT;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SEGMENTP__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SEGMENTP__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SEGMENTP__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SEGMENTP__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SEGMENTP__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SEGMENTP__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SEGMENTP__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SEGMENTP__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SEGMENTP__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SEGMENTP__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_SHL:
    case Brig::BRIG_OPCODE_SHR:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SHIFT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHIFT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SHIFT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHIFT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SHIFT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHIFT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SHIFT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHIFT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SHIFT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHIFT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SHIFT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHIFT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_SHUFFLE:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SHUFFLE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHUFFLE__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SHUFFLE__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHUFFLE__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SHUFFLE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHUFFLE__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SHUFFLE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHUFFLE__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SHUFFLE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHUFFLE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SHUFFLE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SHUFFLE__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_SQRT:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SQRT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SQRT__TYPE;
        case PROP_PACKING:
            num = sizeof(REQ_PROP_VALUES_SQRT__PACKING) / sizeof(unsigned);
            return REQ_PROP_VALUES_SQRT__PACKING;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_SQRT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SQRT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SQRT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SQRT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SQRT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SQRT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SQRT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SQRT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SQRT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SQRT__S4;
        case PROP_FTZ:
            num = sizeof(REQ_PROP_VALUES_SQRT__FTZ) / sizeof(unsigned);
            return REQ_PROP_VALUES_SQRT__FTZ;
        case PROP_ROUNDING:
            num = sizeof(REQ_PROP_VALUES_SQRT__ROUNDING) / sizeof(unsigned);
            return REQ_PROP_VALUES_SQRT__ROUNDING;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_ST:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_ST__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_ST__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__SEGMENT;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_ST__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_ST__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_ST__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_ST__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_ST__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__S4;
        case PROP_ALIGN:
            num = sizeof(REQ_PROP_VALUES_ST__ALIGN) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__ALIGN;
        case PROP_EQCLASS:
            num = sizeof(REQ_PROP_VALUES_ST__EQCLASS) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__EQCLASS;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_ST__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_STIMAGE:
        switch(propId)
        {
        case PROP_CTYPE:
            num = sizeof(REQ_PROP_VALUES_ST_IMAGE__CTYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST_IMAGE__CTYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_ST_IMAGE__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST_IMAGE__TYPE;
        case PROP_GEOM:
            num = sizeof(REQ_PROP_VALUES_ST_IMAGE__GEOM) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST_IMAGE__GEOM;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_ST_IMAGE__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST_IMAGE__S2;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_ST_IMAGE__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST_IMAGE__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_ST_IMAGE__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST_IMAGE__S1;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_ST_IMAGE__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST_IMAGE__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_ST_IMAGE__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST_IMAGE__S4;
        case PROP_ITYPE:
            num = sizeof(REQ_PROP_VALUES_ST_IMAGE__ITYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_ST_IMAGE__ITYPE;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_STOF:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_S2F__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_S2F__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_S2F__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_S2F__TYPE;
        case PROP_SEGMENT:
            num = sizeof(REQ_PROP_VALUES_S2F__SEGMENT) / sizeof(unsigned);
            return REQ_PROP_VALUES_S2F__SEGMENT;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_S2F__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_S2F__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_S2F__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_S2F__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_S2F__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_S2F__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_S2F__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_S2F__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_S2F__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_S2F__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_SYNC:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SYNC__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_SYNC__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SYNC__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SYNC__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SYNC__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SYNC__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__S4;
        case PROP_MEMFNC:
            num = sizeof(REQ_PROP_VALUES_SYNC__MEMFNC) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__MEMFNC;
        case PROP_MEMORD:
            num = sizeof(REQ_PROP_VALUES_SYNC__MEMORD) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__MEMORD;
        case PROP_MEMSCP:
            num = sizeof(REQ_PROP_VALUES_SYNC__MEMSCP) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__MEMSCP;
        case PROP_WIDTH:
            num = sizeof(REQ_PROP_VALUES_SYNC__WIDTH) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYNC__WIDTH;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_SYSCALL:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_SYSCALL__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYSCALL__TYPE;
        case PROP_S0:
            num = sizeof(REQ_PROP_VALUES_SYSCALL__S0) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYSCALL__S0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_SYSCALL__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYSCALL__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_SYSCALL__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYSCALL__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_SYSCALL__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYSCALL__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_SYSCALL__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_SYSCALL__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_UNPACK:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_UNPACK__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACK__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_UNPACK__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACK__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_UNPACK__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACK__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_UNPACK__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACK__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_UNPACK__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACK__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_UNPACK__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACK__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_UNPACK__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACK__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_UNPACKCVT:
        switch(propId)
        {
        case PROP_STYPE:
            num = sizeof(REQ_PROP_VALUES_UNPACKCVT__STYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKCVT__STYPE;
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_UNPACKCVT__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKCVT__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_UNPACKCVT__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKCVT__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_UNPACKCVT__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKCVT__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_UNPACKCVT__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKCVT__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_UNPACKCVT__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKCVT__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_UNPACKCVT__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKCVT__S4;
        default: 
            assert(false);
            return 0;
        }

    case Brig::BRIG_OPCODE_UNPACKHI:
    case Brig::BRIG_OPCODE_UNPACKLO:
        switch(propId)
        {
        case PROP_TYPE:
            num = sizeof(REQ_PROP_VALUES_UNPACKX__TYPE) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKX__TYPE;
        case PROP_D0:
            num = sizeof(REQ_PROP_VALUES_UNPACKX__D0) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKX__D0;
        case PROP_S1:
            num = sizeof(REQ_PROP_VALUES_UNPACKX__S1) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKX__S1;
        case PROP_S2:
            num = sizeof(REQ_PROP_VALUES_UNPACKX__S2) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKX__S2;
        case PROP_S3:
            num = sizeof(REQ_PROP_VALUES_UNPACKX__S3) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKX__S3;
        case PROP_S4:
            num = sizeof(REQ_PROP_VALUES_UNPACKX__S4) / sizeof(unsigned);
            return REQ_PROP_VALUES_UNPACKX__S4;
        default: 
            assert(false);
            return 0;
        }

    }

    assert(false);
    num = 0;
    return 0;
}

template<class T> bool PropDescImpl::chkReqPropNeg(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_s64_sx_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_s32_s64_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_sx_fx(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_s32_s64_sx_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_s32_s64_f(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_fx(getType<T>(inst))
               )
            {
                if (!check_packing_values_p_s(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_FTZ:
        {
            if (!check_ftz_values_none(getFtz<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_ROUNDING:
        {
            if (!check_rounding_values_none(getRounding<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropAdd(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_FTZ:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
                if (!check_packing_values_bin(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_ROUNDING:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_rounding_values_none(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_rounding_values_float(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
                if (!check_rounding_values_none(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_rounding_values_float(getRounding<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropAlloca(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_none(getStype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_none(getStype<T>(inst))) return false;
            if (!check_segment_values_private(getSegment<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropAnd(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b1_b32_b64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropFbar_sync_width(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_FBARRIER, sizeof(OPERAND_VALUES_REG32_FBARRIER) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMFNC:
        {
            if (!check_memfnc_values_any(getMemfnc<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMORD:
        {
            if (!check_memord_values_none(getMemord<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMSCP:
        {
            if (!check_memscp_values_any(getMemscp<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropAtomic(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_ATMOP:
        {
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
            if (!check_segment_values_global_group_flat(getSegment<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_ld(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_MEMORD:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
            if (!check_segment_values_global_group_flat(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_ld(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_ld(getMemord<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S2:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
            if (!check_segment_values_global_group_flat(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_ld(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S3:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
            if (!check_segment_values_global_group_flat(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_ld(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMSCP:
        {
            if (!check_memscp_values_any(getMemscp<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropAtomic_image(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_CTYPE:
        {
            if (!check_type_values_u32(getCtype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_ATMOP:
        {
            if (!check_atmop_values_generic_exch(getAtmop<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_GEOM:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;
            if (!check_atmop_values_generic_exch(getAtmop<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S2:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;
            if (!check_atmop_values_generic_exch(getAtmop<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S4:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;
            if (!check_atmop_values_generic_exch(getAtmop<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_ITYPE:
        {
            if (!check_type_values_rwimg(getItype<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropAtomic_noret_image(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_CTYPE:
        {
            if (!check_type_values_u32(getCtype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_ATMOP:
        {
            if (!check_atmop_values_generic(getAtmop<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_GEOM:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;
            if (!check_atmop_values_generic(getAtmop<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S1:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;
            if (!check_atmop_values_generic(getAtmop<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S3:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;
            if (!check_atmop_values_generic(getAtmop<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_and_or_xor(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_ITYPE:
        {
            if (!check_type_values_rwimg(getItype<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropAtomic_noret(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_ATMOP:
        {
            if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;
            if (!check_segment_values_global_group_flat(getSegment<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_st(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_MEMORD:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;
            if (!check_segment_values_global_group_flat(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_st(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_st(getMemord<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S2:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;
            if (!check_segment_values_global_group_flat(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_and_or_xor(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_st(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMSCP:
        {
            if (!check_memscp_values_any(getMemscp<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropBarrier(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMFNC:
        {
            if (!check_memfnc_values_any(getMemfnc<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMORD:
        {
            if (!check_memord_values_none(getMemord<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMSCP:
        {
            if (!check_memscp_values_any(getMemscp<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropAlign(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropBitextract(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropBitinsert(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropBitmask(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_b64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropBitrev(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_b64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropBitselect(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_b64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropRem(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropBrn(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_S0:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_LABMODEL, sizeof(OPERAND_VALUES_REGMODEL_LABMODEL) / sizeof(unsigned), false)) return false;

            if (
                validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
               )
            {
            }
            else if (
                validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_LABMODEL, sizeof(OPERAND_VALUES_LABMODEL) / sizeof(unsigned), false)
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S1:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_LABMODEL, sizeof(OPERAND_VALUES_REGMODEL_LABMODEL) / sizeof(unsigned), false)) return false;
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned), false)) return false;

            if (
                validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned), false)) return false;
            }
            else if (
                validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_LABMODEL, sizeof(OPERAND_VALUES_LABMODEL) / sizeof(unsigned), false)
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_WIDTH:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_LABMODEL, sizeof(OPERAND_VALUES_REGMODEL_LABMODEL) / sizeof(unsigned), false)) return false;

            if (
                validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
               )
            {
                if (!check_width_values_any(getWidth<T>(inst))) return false;
            }
            else if (
                validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_LABMODEL, sizeof(OPERAND_VALUES_LABMODEL) / sizeof(unsigned), false)
               )
            {
                if (!check_width_values_all(getWidth<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCall(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_S1:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_FUNCMODEL, sizeof(OPERAND_VALUES_REGMODEL_FUNCMODEL) / sizeof(unsigned), false)) return false;

            if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
               )
            {
            }
            else if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_FUNCMODEL, sizeof(OPERAND_VALUES_FUNCMODEL) / sizeof(unsigned), false)
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S3:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_FUNCMODEL, sizeof(OPERAND_VALUES_REGMODEL_FUNCMODEL) / sizeof(unsigned), false)) return false;
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_CALLTAB, sizeof(OPERAND_VALUES_NULL_CALLTAB) / sizeof(unsigned), false)) return false;

            if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
               )
            {
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_CALLTAB, sizeof(OPERAND_VALUES_NULL_CALLTAB) / sizeof(unsigned), false)) return false;
            }
            else if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_FUNCMODEL, sizeof(OPERAND_VALUES_FUNCMODEL) / sizeof(unsigned), false)
               )
            {
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_WIDTH:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_FUNCMODEL, sizeof(OPERAND_VALUES_REGMODEL_FUNCMODEL) / sizeof(unsigned), false)) return false;

            if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
               )
            {
                if (!check_width_values_any(getWidth<T>(inst))) return false;
            }
            else if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_FUNCMODEL, sizeof(OPERAND_VALUES_FUNCMODEL) / sizeof(unsigned), false)
               )
            {
                if (!check_width_values_all(getWidth<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCbr(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_S1:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_LABMODEL, sizeof(OPERAND_VALUES_REGMODEL_LABMODEL) / sizeof(unsigned), false)) return false;

            if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
               )
            {
            }
            else if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_LABMODEL, sizeof(OPERAND_VALUES_LABMODEL) / sizeof(unsigned), false)
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S2:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_LABMODEL, sizeof(OPERAND_VALUES_REGMODEL_LABMODEL) / sizeof(unsigned), false)) return false;
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned), false)) return false;

            if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned), false)) return false;
            }
            else if (
                validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_LABMODEL, sizeof(OPERAND_VALUES_LABMODEL) / sizeof(unsigned), false)
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG1, sizeof(OPERAND_VALUES_REG1) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCeil(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_packing_values_p_s(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_FTZ:
        {
            if (!check_ftz_values_any(getFtz<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_ROUNDING:
        {
            if (!check_rounding_values_none(getRounding<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropClass(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_f(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b1(getType<T>(inst))) return false;
            if (!check_type_values_f(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSpec_except(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSpec_clock(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCmov(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b1_b32_b64_x(getType<T>(inst))) return false;

            if (
                check_type_values_b1_b32_b64(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_x(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S1:
        {
            if (!check_type_values_b1_b32_b64_x(getType<T>(inst))) return false;

            if (
                check_type_values_b1_b32_b64(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG1_IMM1, sizeof(OPERAND_VALUES_REG1_IMM1) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_x(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCmp(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b1_s32_u32_s64_u64_f_ux(getType<T>(inst))) return false;
            if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(getStype<T>(inst))) return false;

            if (
                check_type_values_b1_b32_s32_u32_b64_s64_u64_f(getStype<T>(inst))
               )
            {
                if (!check_type_values_b1_s32_u32_s64_u64_f(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x4_u8x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x8_u8x8(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x8(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x16_u8x16(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x16(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x2_u16x2_f16x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x2(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x4_u16x4_f16x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x8_u16x8_f16x8(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x8(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s32x2_u32x2_f32x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u32x2(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s32x4_u32x4_f32x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u32x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s64x2_u64x2_f64x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u64x(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_type_values_b1_b32_b64(getStype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_s32_u32_s64_u64(getStype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f(getStype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_sx_ux(getStype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_fx(getStype<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_FTZ:
        {
            if (!check_type_values_b1_s32_u32_s64_u64_f_ux(getType<T>(inst))) return false;
            if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(getStype<T>(inst))) return false;

            if (
                check_type_values_b1_b32_s32_u32_b64_s64_u64_f(getStype<T>(inst))
               )
            {
                if (!check_type_values_b1_s32_u32_s64_u64_f(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x4_u8x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x8_u8x8(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x8(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x16_u8x16(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x16(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x2_u16x2_f16x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x2(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x4_u16x4_f16x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x8_u16x8_f16x8(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x8(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s32x2_u32x2_f32x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u32x2(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s32x4_u32x4_f32x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u32x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s64x2_u64x2_f64x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u64x(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_type_values_b1_b32_b64(getStype<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_s32_u32_s64_u64(getStype<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getStype<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getStype<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getStype<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_OPERATOR:
        {
            if (!check_type_values_b1_s32_u32_s64_u64_f_ux(getType<T>(inst))) return false;
            if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(getStype<T>(inst))) return false;

            if (
                check_type_values_b1_b32_s32_u32_b64_s64_u64_f(getStype<T>(inst))
               )
            {
                if (!check_type_values_b1_s32_u32_s64_u64_f(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x4_u8x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x8_u8x8(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x8(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x16_u8x16(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x16(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x2_u16x2_f16x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x2(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x4_u16x4_f16x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x8_u16x8_f16x8(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x8(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s32x2_u32x2_f32x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u32x2(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s32x4_u32x4_f32x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u32x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s64x2_u64x2_f64x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u64x(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_type_values_b1_b32_b64(getStype<T>(inst))
               )
            {
                if (!check_operator_values_eq_ne(getOperator<T>(inst))) return false;
            }
            else if (
                check_type_values_s32_u32_s64_u64(getStype<T>(inst))
               )
            {
                if (!check_operator_values_eq_ne_lt_le_gt_ge(getOperator<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getStype<T>(inst))
               )
            {
                if (!check_operator_values_0(getOperator<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getStype<T>(inst))
               )
            {
                if (!check_operator_values_eq_ne_lt_le_gt_ge(getOperator<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getStype<T>(inst))
               )
            {
                if (!check_operator_values_0(getOperator<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_b1_s32_u32_s64_u64_f_ux(getType<T>(inst))) return false;
            if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(getStype<T>(inst))) return false;

            if (
                check_type_values_b1_b32_s32_u32_b64_s64_u64_f(getStype<T>(inst))
               )
            {
                if (!check_type_values_b1_s32_u32_s64_u64_f(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x4_u8x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x8_u8x8(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x8(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s8x16_u8x16(getStype<T>(inst))
               )
            {
                if (!check_type_values_u8x16(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x2_u16x2_f16x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x2(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x4_u16x4_f16x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s16x8_u16x8_f16x8(getStype<T>(inst))
               )
            {
                if (!check_type_values_u16x8(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s32x2_u32x2_f32x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u32x2(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s32x4_u32x4_f32x4(getStype<T>(inst))
               )
            {
                if (!check_type_values_u32x4(getType<T>(inst))) return false;
            }
            else if (
                check_type_values_s64x2_u64x2_f64x2(getStype<T>(inst))
               )
            {
                if (!check_type_values_u64x(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_type_values_b1_b32_b64(getStype<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_s32_u32_s64_u64(getStype<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getStype<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getStype<T>(inst))
               )
            {
                if (!check_packing_values_pp(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getStype<T>(inst))
               )
            {
                if (!check_packing_values_pp(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_ROUNDING:
        {
            if (!check_rounding_values_none(getRounding<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCodeblockend(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCombine(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_b32_b64(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b64_b128(getType<T>(inst))) return false;
            if (!check_type_values_b32_b64(getStype<T>(inst))) return false;

            if (
                check_type_values_b64(getType<T>(inst)) &&
                check_type_values_b32(getStype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_b128(getType<T>(inst)) &&
                check_type_values_b64(getStype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_b128(getType<T>(inst)) &&
                check_type_values_b32(getStype<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S1:
        {
            if (!check_type_values_b64_b128(getType<T>(inst))) return false;
            if (!check_type_values_b32_b64(getStype<T>(inst))) return false;

            if (
                check_type_values_b64(getType<T>(inst)) &&
                check_type_values_b32(getStype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_b128(getType<T>(inst)) &&
                check_type_values_b64(getStype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_b128(getType<T>(inst)) &&
                check_type_values_b32(getStype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCopysign(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_FTZ:
        {
            if (!check_ftz_values_none(getFtz<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_ROUNDING:
        {
            if (!check_rounding_values_none(getRounding<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCountlane(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_u32_b1(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_u32_b1(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCountuplane(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_none(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_none(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSpec_reg(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSpec_reg_dim(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM012, sizeof(OPERAND_VALUES_IMM012) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropCvt(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b1_s_u_f(getType<T>(inst))) return false;
            if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;

            if (
                check_type_values_b1(getType<T>(inst))
               )
            {
                if (!check_type_values_u_s_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s8_u8(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s16_u16_s32_u32_s64_u64_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s16_u16(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s8_u8_s32_u32_s64_u64_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s32_u32(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s8_u8_s16_u16_s64_u64_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s64_u64(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s8_u8_s16_u16_s32_u32_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f16(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f32(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f64(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_type_values_b1_s_u(getStype<T>(inst)) &&
                check_type_values_b1_s_u(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_b1(getStype<T>(inst)) &&
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_s_u(getStype<T>(inst)) &&
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f(getStype<T>(inst)) &&
                check_type_values_b1(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f(getStype<T>(inst)) &&
                check_type_values_s_u(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f32(getStype<T>(inst)) &&
                check_type_values_f16(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f64(getStype<T>(inst)) &&
                check_type_values_f16_f32(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f(getStype<T>(inst)) &&
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_FTZ:
        {
            if (!check_type_values_b1_s_u_f(getType<T>(inst))) return false;
            if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;

            if (
                check_type_values_b1(getType<T>(inst))
               )
            {
                if (!check_type_values_u_s_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s8_u8(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s16_u16_s32_u32_s64_u64_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s16_u16(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s8_u8_s32_u32_s64_u64_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s32_u32(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s8_u8_s16_u16_s64_u64_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s64_u64(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s8_u8_s16_u16_s32_u32_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f16(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f32(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f64(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_type_values_b1_s_u(getStype<T>(inst)) &&
                check_type_values_b1_s_u(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_b1(getStype<T>(inst)) &&
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_s_u(getStype<T>(inst)) &&
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getStype<T>(inst)) &&
                check_type_values_b1(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getStype<T>(inst)) &&
                check_type_values_s_u(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f32(getStype<T>(inst)) &&
                check_type_values_f16(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f64(getStype<T>(inst)) &&
                check_type_values_f16_f32(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getStype<T>(inst)) &&
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_ROUNDING:
        {
            if (!check_type_values_b1_s_u_f(getType<T>(inst))) return false;
            if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;

            if (
                check_type_values_b1(getType<T>(inst))
               )
            {
                if (!check_type_values_u_s_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s8_u8(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s16_u16_s32_u32_s64_u64_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s16_u16(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s8_u8_s32_u32_s64_u64_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s32_u32(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s8_u8_s16_u16_s64_u64_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s64_u64(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s8_u8_s16_u16_s32_u32_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f16(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f32(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f64(getType<T>(inst))
               )
            {
                if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            if (
                check_type_values_b1_s_u(getStype<T>(inst)) &&
                check_type_values_b1_s_u(getType<T>(inst))
               )
            {
                if (!check_rounding_values_none(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_b1(getStype<T>(inst)) &&
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_rounding_values_none(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_s_u(getStype<T>(inst)) &&
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_rounding_values_float(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getStype<T>(inst)) &&
                check_type_values_b1(getType<T>(inst))
               )
            {
                if (!check_rounding_values_none(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getStype<T>(inst)) &&
                check_type_values_s_u(getType<T>(inst))
               )
            {
                if (!check_rounding_values_int(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_f32(getStype<T>(inst)) &&
                check_type_values_f16(getType<T>(inst))
               )
            {
                if (!check_rounding_values_float(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_f64(getStype<T>(inst)) &&
                check_type_values_f16_f32(getType<T>(inst))
               )
            {
                if (!check_rounding_values_float(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getStype<T>(inst)) &&
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_rounding_values_none(getRounding<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_EXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_SEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropDebugtrap(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropAqlptr(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_none(getStype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            if (!check_type_values_none(getStype<T>(inst))) return false;
            if (!check_segment_values_global(getSegment<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropDiv(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_FTZ:
        {
            if (!check_type_values_s32_u32_s64_u64_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_s32_u32_s64_u64_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_ROUNDING:
        {
            if (!check_type_values_s32_u32_s64_u64_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_rounding_values_none(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_rounding_values_float(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_rounding_values_float(getRounding<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropExpand(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_b64_b128(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            if (!check_type_values_b64_b128(getStype<T>(inst))) return false;

            if (
                check_type_values_b32(getType<T>(inst)) &&
                check_type_values_b64(getStype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_b32(getType<T>(inst)) &&
                check_type_values_b128(getStype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_b64(getType<T>(inst)) &&
                check_type_values_b128(getStype<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_D0:
        {
            if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            if (!check_type_values_b64_b128(getStype<T>(inst))) return false;

            if (
                check_type_values_b32(getType<T>(inst)) &&
                check_type_values_b64(getStype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_b32(getType<T>(inst)) &&
                check_type_values_b128(getStype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_b64(getType<T>(inst)) &&
                check_type_values_b128(getStype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropFirstbit(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_s32_u32_s64_u64(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_s32_u32_s64_u64(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropFma(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_FTZ:
        {
            if (!check_ftz_values_any(getFtz<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_PACKING:
        {
            if (!check_packing_values_none(getPacking<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_ROUNDING:
        {
            if (!check_rounding_values_float(getRounding<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropFract(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_packing_values_p_s(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_FTZ:
        {
            if (!check_ftz_values_any(getFtz<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_ROUNDING:
        {
            if (!check_rounding_values_none(getRounding<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropF2s(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_u32_u64(getStype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            if (!check_type_values_u32_u64(getStype<T>(inst))) return false;
            if (!check_segment_values_std(getSegment<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;
            if (!validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_MODEL, sizeof(STYPESIZE_VALUES_MODEL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_append_consume(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_atomic(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_ATMOP:
        {
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_ld(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_MEMORD:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_ld(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_ld(getMemord<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S2:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_ld(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S3:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_ld(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMSCP:
        {
            if (!check_memscp_values_any(getMemscp<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_atomic_noret(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_ATMOP:
        {
            if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            }
            else if (
                check_atmop_values_st(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_MEMORD:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_and_or_xor(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!check_memord_values_any(getMemord<T>(inst))) return false;
            }
            else if (
                check_atmop_values_st(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!check_memord_values_st(getMemord<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S2:
        {
            if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
            if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            if (
                check_atmop_values_cas(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_and_or_xor(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_inc_dec(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_atmop_values_st(getAtmop<T>(inst))
               )
            {
                if (!check_type_values_b32_b64(getType<T>(inst))) return false;
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMSCP:
        {
            if (!check_memscp_values_any(getMemscp<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_b4xchg(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_bfm(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32, sizeof(OPERAND_VALUES_REG32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_fldexp(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f32_f64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_frexp_exp(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f32_f64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32, sizeof(OPERAND_VALUES_REG32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_frexp_mant(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f32_f64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_ld(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u_s_f_b128(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u_s_f_b128(getType<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            if (
                check_type_values_u_s_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_b128(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_D0:
        {
            if (!check_type_values_u_s_f_b128(getType<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            if (
                check_type_values_u_s_f(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_b128(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_ALIGN:
        {
            if (!check_align_values_any(getAlign<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_EQCLASS:
        {
            if (!validateEqclass(inst, PROP_EQCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_mad(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMM64, sizeof(OPERAND_VALUES_REG64_IMM64) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_min_max_med(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32, sizeof(OPERAND_VALUES_REG32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_mqsad(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_mqsad4(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REGV432, sizeof(OPERAND_VALUES_REGV432) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMM64, sizeof(OPERAND_VALUES_REG64_IMM64) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REGV432, sizeof(OPERAND_VALUES_REGV432) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_msad(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_slp_prt(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_qsad(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_region_alloc(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_st(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u_s_f_b128(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u_s_f_b128(getType<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            if (
                check_type_values_u_s_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_b128(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S0:
        {
            if (!check_type_values_u_s_f_b128(getType<T>(inst))) return false;
            if (!check_segment_values_gcn(getSegment<T>(inst))) return false;

            if (
                check_type_values_u_s_f(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_b128(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_ALIGN:
        {
            if (!check_align_values_any(getAlign<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_EQCLASS:
        {
            if (!validateEqclass(inst, PROP_EQCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_none(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropGcn_trig_preop(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropFbar_none(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_FBARRIER, sizeof(OPERAND_VALUES_REG32_FBARRIER) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMFNC:
        {
            if (!check_memfnc_values_none(getMemfnc<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMORD:
        {
            if (!check_memord_values_none(getMemord<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMSCP:
        {
            if (!check_memscp_values_none(getMemscp<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_none(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropFbar_width(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_FBARRIER, sizeof(OPERAND_VALUES_REG32_FBARRIER) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMFNC:
        {
            if (!check_memfnc_values_none(getMemfnc<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMORD:
        {
            if (!check_memord_values_none(getMemord<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMSCP:
        {
            if (!check_memscp_values_none(getMemscp<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropLd(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) return false;
            if (!check_segment_values_any(getSegment<T>(inst))) return false;

            if (
                check_type_values_u_s_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_b128_roimg_rwimg_samp(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_D0:
        {
            if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) return false;
            if (!check_segment_values_any(getSegment<T>(inst))) return false;

            if (
                check_type_values_u_s_f(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_b128_roimg_rwimg_samp(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_ALIGN:
        {
            if (!check_align_values_any(getAlign<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_EQCLASS:
        {
            if (!validateEqclass(inst, PROP_EQCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropLda(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            if (!check_segment_values_any(getSegment<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropLdc(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_LAB_FUNC, sizeof(OPERAND_VALUES_LAB_FUNC) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropLdf(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_FBARRIER, sizeof(OPERAND_VALUES_FBARRIER) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropLd_image(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_CTYPE:
        {
            if (!check_type_values_u32(getCtype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_GEOM:
        {
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_ITYPE:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }
            if (!check_type_values_roimg_rwimg(getItype<T>(inst))) return false;

            if (
                check_type_values_roimg(getItype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_rwimg(getItype<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S1:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }
            if (!check_type_values_roimg_rwimg(getItype<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMAGE, sizeof(OPERAND_VALUES_REG64_IMAGE) / sizeof(unsigned), false)) return false;

            if (
                check_type_values_roimg(getItype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_ROIMAGE, sizeof(OPERAND_VALUES_REG64_ROIMAGE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_rwimg(getItype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S2:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }
            if (!check_type_values_roimg_rwimg(getItype<T>(inst))) return false;

            if (
                check_type_values_roimg(getItype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_rwimg(getItype<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropLerp(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u8x4(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropMad(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropMad24(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropMasklane(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_u32_b1(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b64(getType<T>(inst))) return false;
            if (!check_type_values_u32_b1(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropMax(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_FTZ:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;
            if (!check_ftz_values_any(getFtz<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
                if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_ROUNDING:
        {
            if (!check_rounding_values_none(getRounding<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropMov(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_roimg_rwimg_samp(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropMul(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_FTZ:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;
            if (!check_ftz_values_any(getFtz<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
                if (!check_ftz_values_none(getFtz<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_ftz_values_any(getFtz<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
                if (!check_packing_values_bin(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_ROUNDING:
        {
            if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_rounding_values_none(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_rounding_values_float(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
                if (!check_rounding_values_none(getRounding<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_rounding_values_float(getRounding<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropMul24(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropMulhi(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64_sx_ux(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_s32_u32_s64_u64_sx_ux(getType<T>(inst))) return false;

            if (
                check_type_values_s32_u32_s64_u64(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_sx_ux(getType<T>(inst))
               )
            {
                if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_FTZ:
        {
            if (!check_ftz_values_none(getFtz<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_ROUNDING:
        {
            if (!check_rounding_values_none(getRounding<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropTrig32(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f32(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropNfma(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropNop(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropNot(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b1_b32_b64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropTrig(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropNullptr(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_none(getStype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            if (!check_type_values_none(getStype<T>(inst))) return false;
            if (!check_segment_values_any(getSegment<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropPack(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_s32_u32_s64_u64_f(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_x(getType<T>(inst))) return false;
            if (!check_type_values_s32_u32_s64_u64_f(getStype<T>(inst))) return false;

            if (
                check_type_values_s8x_s16x_s32x(getType<T>(inst))
               )
            {
                if (!check_type_values_s32_s64(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s64x(getType<T>(inst))
               )
            {
                if (!check_type_values_s64(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_u8x_u16x_u32x(getType<T>(inst))
               )
            {
                if (!check_type_values_u32_u64(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_u64x(getType<T>(inst))
               )
            {
                if (!check_type_values_u64(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f16x(getType<T>(inst))
               )
            {
                if (!check_type_values_f16(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f32x(getType<T>(inst))
               )
            {
                if (!check_type_values_f32(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f64x(getType<T>(inst))
               )
            {
                if (!check_type_values_f64(getStype<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropPackcvt(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_f32(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u8x4(getType<T>(inst))) return false;
            if (!check_type_values_f32(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropPopcount(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_b32_b64(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_b32_b64(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropQueryimage(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_roimg_rwimg(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_roimg_rwimg(getStype<T>(inst))) return false;

            if (
                check_type_values_roimg(getStype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_rwimg(getStype<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S1:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_roimg_rwimg(getStype<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMAGE, sizeof(OPERAND_VALUES_REG64_IMAGE) / sizeof(unsigned), false)) return false;

            if (
                check_type_values_roimg(getStype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_ROIMAGE, sizeof(OPERAND_VALUES_REG64_ROIMAGE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_rwimg(getStype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropQuerysamplerboundary(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_samp(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_samp(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_SAMPLER, sizeof(OPERAND_VALUES_REG64_SAMPLER) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropQuerysampler(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_samp(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_samp(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_SAMPLER, sizeof(OPERAND_VALUES_REG64_SAMPLER) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropRdimage(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_CTYPE:
        {
            if (!check_type_values_s32_f32(getCtype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_GEOM:
        {
            if (!check_geom_values_1d_2d_3d_1da_2da(getGeom<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_ITYPE:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
            if (!check_type_values_roimg_rwimg(getItype<T>(inst))) return false;
            if (!check_type_values_s32_f32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1da_2da(getGeom<T>(inst))) return false;

            if (
                check_type_values_roimg(getItype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_rwimg(getItype<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            if (
                check_geom_values_1d(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S1:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
            if (!check_type_values_roimg_rwimg(getItype<T>(inst))) return false;
            if (!check_type_values_s32_f32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1da_2da(getGeom<T>(inst))) return false;
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMAGE, sizeof(OPERAND_VALUES_REG64_IMAGE) / sizeof(unsigned), false)) return false;

            if (
                check_type_values_roimg(getItype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_ROIMAGE, sizeof(OPERAND_VALUES_REG64_ROIMAGE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_rwimg(getItype<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            if (
                check_geom_values_1d(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S3:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
            if (!check_type_values_roimg_rwimg(getItype<T>(inst))) return false;
            if (!check_type_values_s32_f32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1da_2da(getGeom<T>(inst))) return false;

            if (
                check_type_values_roimg(getItype<T>(inst))
               )
            {
            }
            else if (
                check_type_values_rwimg(getItype<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            if (
                check_geom_values_1d(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_SAMPLER, sizeof(OPERAND_VALUES_REG64_SAMPLER) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSendlane(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_none(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b32(getType<T>(inst))) return false;
            if (!check_type_values_none(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_any(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropRet(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSad(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_u32_u8x4_u16x2(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32(getType<T>(inst))) return false;
            if (!check_type_values_u32_u8x4_u16x2(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSadhi(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_u8x4(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u16x2(getType<T>(inst))) return false;
            if (!check_type_values_u8x4(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSegmentp(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_u32_u64(getStype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_b1(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_b1(getType<T>(inst))) return false;
            if (!check_type_values_u32_u64(getStype<T>(inst))) return false;
            if (!check_segment_values_std(getSegment<T>(inst))) return false;
            if (!validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_MODEL, sizeof(STYPESIZE_VALUES_MODEL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropShift(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64_sx_ux(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropShuffle(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_x32_x64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSqrt(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_PACKING:
        {
            if (!check_type_values_f_fx(getType<T>(inst))) return false;

            if (
                check_type_values_f(getType<T>(inst))
               )
            {
                if (!check_packing_values_none(getPacking<T>(inst))) return false;
            }
            else if (
                check_type_values_fx(getType<T>(inst))
               )
            {
                if (!check_packing_values_p_s(getPacking<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_FTZ:
        {
            if (!check_ftz_values_any(getFtz<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_ROUNDING:
        {
            if (!check_rounding_values_float(getRounding<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSt(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) return false;
            if (!check_segment_values_writable(getSegment<T>(inst))) return false;

            if (
                check_type_values_u_s_f(getType<T>(inst))
               )
            {
            }
            else if (
                check_type_values_b128_roimg_rwimg_samp(getType<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S0:
        {
            if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) return false;
            if (!check_segment_values_writable(getSegment<T>(inst))) return false;

            if (
                check_type_values_u_s_f(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_type_values_b128_roimg_rwimg_samp(getType<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_ALIGN:
        {
            if (!check_align_values_any(getAlign<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_EQCLASS:
        {
            if (!validateEqclass(inst, PROP_EQCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_none(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSt_image(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_CTYPE:
        {
            if (!check_type_values_u32(getCtype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_GEOM:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
            }
            else
            {
                return false;
            }

            return true;
        }

        // Conditional Property
        case PROP_S2:
        {
            if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
            if (!check_type_values_u32(getCtype<T>(inst))) return false;
            if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;

            if (
                check_geom_values_1d_1db(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_2d_1da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
            }
            else if (
                check_geom_values_3d_2da(getGeom<T>(inst))
               )
            {
                if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_ITYPE:
        {
            if (!check_type_values_rwimg(getItype<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropS2f(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_u32_u64(getStype<T>(inst))) return false;

            return true;
        }

        // Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_SEGMENT:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;
            if (!check_type_values_u32_u64(getStype<T>(inst))) return false;
            if (!check_segment_values_std(getSegment<T>(inst))) return false;
            if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned), false)) return false;
            if (!validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_SEG, sizeof(STYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSync(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_none(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMFNC:
        {
            if (!check_memfnc_values_any(getMemfnc<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMORD:
        {
            if (!check_memord_values_any(getMemord<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_MEMSCP:
        {
            if (!check_memscp_values_any(getMemscp<T>(inst))) return false;

            return true;
        }

        // Plain Property
        case PROP_WIDTH:
        {
            if (!check_width_values_none(getWidth<T>(inst))) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropSyscall(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_u32_u64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_S0:
        {
            if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropUnpack(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_x(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_s32_u32_s64_u64_f(getType<T>(inst))) return false;
            if (!check_type_values_x(getStype<T>(inst))) return false;

            if (
                check_type_values_s32(getType<T>(inst))
               )
            {
                if (!check_type_values_s8x_s16x_s32x(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_s64(getType<T>(inst))
               )
            {
                if (!check_type_values_s8x_s16x_s32x_s64x(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_u32(getType<T>(inst))
               )
            {
                if (!check_type_values_u8x_u16x_u32x(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_u64(getType<T>(inst))
               )
            {
                if (!check_type_values_u8x_u16x_u32x_u64x(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f16(getType<T>(inst))
               )
            {
                if (!check_type_values_f16x(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f32(getType<T>(inst))
               )
            {
                if (!check_type_values_f32x(getStype<T>(inst))) return false;
            }
            else if (
                check_type_values_f64(getType<T>(inst))
               )
            {
                if (!check_type_values_f64x(getStype<T>(inst))) return false;
            }
            else
            {
                return false;
            }

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropUnpackcvt(T inst, unsigned propId)
{
    switch(propId)
    {
        // Primary Property
        case PROP_STYPE:
        {
            if (!check_type_values_u8x4(getStype<T>(inst))) return false;

            return true;
        }

        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_f32(getType<T>(inst))) return false;
            if (!check_type_values_u8x4(getStype<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM0123, sizeof(OPERAND_VALUES_IMM0123) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
template<class T> bool PropDescImpl::chkReqPropUnpackx(T inst, unsigned propId)
{
    switch(propId)
    {
        // Last Primary Property
        case PROP_TYPE:
        {
            if (!check_type_values_x32_x64(getType<T>(inst))) return false;

            return true;
        }

        // Dependent Property
        case PROP_D0:
        {
            if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S1:
        {
            if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S2:
        {
            if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S3:
        {
            if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

        // Dependent Property
        case PROP_S4:
        {
            if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

            return true;
        }

    default: 
        assert(false);
        return false;
    }
}
bool PropDescImpl::isValidProp(Inst inst, unsigned propId)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ABS):
        case (Brig::BRIG_OPCODE_NEG):
        {
            if (InstMod i = inst)
            {
                return chkReqPropNeg<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropNeg<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_ADD):
        case (Brig::BRIG_OPCODE_SUB):
        {
            if (InstMod i = inst)
            {
                return chkReqPropAdd<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropAdd<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_ALLOCA):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropAlloca<InstSeg>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_AND):
        case (Brig::BRIG_OPCODE_OR):
        case (Brig::BRIG_OPCODE_XOR):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropAnd<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_ARRIVEFBAR):
        case (Brig::BRIG_OPCODE_WAITFBAR):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropFbar_sync_width<InstBar>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropAtomic<InstAtomic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMICIMAGE):
        {
            InstAtomicImage i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropAtomic_image<InstAtomicImage>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMICIMAGENORET):
        {
            InstAtomicImage i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropAtomic_noret_image<InstAtomicImage>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMICNORET):
        {
            InstAtomic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropAtomic_noret<InstAtomic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_BARRIER):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropBarrier<InstBar>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITALIGN):
        case (Brig::BRIG_OPCODE_BYTEALIGN):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropAlign<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITEXTRACT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropBitextract<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITINSERT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropBitinsert<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITMASK):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropBitmask<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITREV):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropBitrev<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITSELECT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropBitselect<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_BORROW):
        case (Brig::BRIG_OPCODE_CARRY):
        case (Brig::BRIG_OPCODE_REM):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropRem<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_BRN):
        {
            InstBr i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropBrn<InstBr>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CALL):
        {
            InstBr i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropCall<InstBr>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CBR):
        {
            InstBr i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropCbr<InstBr>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CEIL):
        case (Brig::BRIG_OPCODE_FLOOR):
        case (Brig::BRIG_OPCODE_RINT):
        case (Brig::BRIG_OPCODE_TRUNC):
        {
            if (InstMod i = inst)
            {
                return chkReqPropCeil<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropCeil<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_CLASS):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropClass<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CLEARDETECTEXCEPT):
        case (Brig::BRIG_OPCODE_SETDETECTEXCEPT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSpec_except<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CLOCK):
        case (Brig::BRIG_OPCODE_DISPATCHID):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSpec_clock<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CMOV):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropCmov<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CMP):
        {
            InstCmp i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropCmp<InstCmp>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CODEBLOCKEND):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropCodeblockend<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_COMBINE):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropCombine<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_COPYSIGN):
        {
            if (InstMod i = inst)
            {
                return chkReqPropCopysign<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropCopysign<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_COUNTLANE):
        {
            InstLane i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropCountlane<InstLane>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_COUNTUPLANE):
        {
            InstLane i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropCountuplane<InstLane>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CUID):
        case (Brig::BRIG_OPCODE_DIM):
        case (Brig::BRIG_OPCODE_GETDETECTEXCEPT):
        case (Brig::BRIG_OPCODE_LANEID):
        case (Brig::BRIG_OPCODE_MAXCUID):
        case (Brig::BRIG_OPCODE_MAXWAVEID):
        case (Brig::BRIG_OPCODE_QID):
        case (Brig::BRIG_OPCODE_WAVEID):
        case (Brig::BRIG_OPCODE_WORKITEMFLATABSID):
        case (Brig::BRIG_OPCODE_WORKITEMFLATID):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSpec_reg<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE):
        case (Brig::BRIG_OPCODE_GRIDGROUPS):
        case (Brig::BRIG_OPCODE_GRIDSIZE):
        case (Brig::BRIG_OPCODE_WORKGROUPID):
        case (Brig::BRIG_OPCODE_WORKGROUPSIZE):
        case (Brig::BRIG_OPCODE_WORKITEMABSID):
        case (Brig::BRIG_OPCODE_WORKITEMID):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSpec_reg_dim<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_CVT):
        {
            InstCvt i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropCvt<InstCvt>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_DEBUGTRAP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropDebugtrap<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_DISPATCHPTR):
        case (Brig::BRIG_OPCODE_QPTR):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropAqlptr<InstSeg>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_DIV):
        {
            if (InstMod i = inst)
            {
                return chkReqPropDiv<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropDiv<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_EXPAND):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropExpand<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_FIRSTBIT):
        case (Brig::BRIG_OPCODE_LASTBIT):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropFirstbit<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_FMA):
        {
            if (InstMod i = inst)
            {
                return chkReqPropFma<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropFma<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_FRACT):
        {
            if (InstMod i = inst)
            {
                return chkReqPropFract<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropFract<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_FTOS):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropF2s<InstSeg>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNAPPEND):
        case (Brig::BRIG_OPCODE_GCNCONSUME):
        {
            InstAddr i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_append_consume<InstAddr>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_atomic<InstAtomic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNATOMICNORET):
        {
            InstAtomic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_atomic_noret<InstAtomic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNB32XCHG):
        case (Brig::BRIG_OPCODE_GCNB4XCHG):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_b4xchg<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNBFM):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_bfm<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNFLDEXP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_fldexp<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNFREXP_EXP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_frexp_exp<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNFREXP_MANT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_frexp_mant<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNLD):
        {
            InstMem i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_ld<InstMem>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMADS):
        case (Brig::BRIG_OPCODE_GCNMADU):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_mad<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMAX3):
        case (Brig::BRIG_OPCODE_GCNMED3):
        case (Brig::BRIG_OPCODE_GCNMIN3):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_min_max_med<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMQSAD):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_mqsad<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMQSAD4):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_mqsad4<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMSAD):
        case (Brig::BRIG_OPCODE_GCNSADD):
        case (Brig::BRIG_OPCODE_GCNSADW):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_msad<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNPRIORITY):
        case (Brig::BRIG_OPCODE_GCNSLEEP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_slp_prt<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNQSAD):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_qsad<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNREGIONALLOC):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_region_alloc<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNST):
        {
            InstMem i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_st<InstMem>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNTRIG_PREOP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropGcn_trig_preop<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_INITFBAR):
        case (Brig::BRIG_OPCODE_RELEASEFBAR):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropFbar_none<InstBar>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_JOINFBAR):
        case (Brig::BRIG_OPCODE_LEAVEFBAR):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropFbar_width<InstBar>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_LD):
        {
            InstMem i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropLd<InstMem>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDA):
        {
            InstAddr i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropLda<InstAddr>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDC):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropLdc<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDF):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropLdf<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDIMAGE):
        {
            InstImage i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropLd_image<InstImage>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_LERP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropLerp<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAD):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropMad<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAD24):
        case (Brig::BRIG_OPCODE_MAD24HI):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropMad24<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_MASKLANE):
        {
            InstLane i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropMasklane<InstLane>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAX):
        case (Brig::BRIG_OPCODE_MIN):
        {
            if (InstMod i = inst)
            {
                return chkReqPropMax<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropMax<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_MOV):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropMov<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_MUL):
        {
            if (InstMod i = inst)
            {
                return chkReqPropMul<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropMul<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_MUL24):
        case (Brig::BRIG_OPCODE_MUL24HI):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropMul24<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_MULHI):
        {
            if (InstMod i = inst)
            {
                return chkReqPropMulhi<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropMulhi<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_NCOS):
        case (Brig::BRIG_OPCODE_NEXP2):
        case (Brig::BRIG_OPCODE_NLOG2):
        case (Brig::BRIG_OPCODE_NSIN):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropTrig32<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_NFMA):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropNfma<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_NOP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropNop<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_NOT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropNot<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_NRCP):
        case (Brig::BRIG_OPCODE_NRSQRT):
        case (Brig::BRIG_OPCODE_NSQRT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropTrig<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_NULLPTR):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropNullptr<InstSeg>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_PACK):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropPack<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_PACKCVT):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropPackcvt<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_POPCOUNT):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropPopcount<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYIMAGEARRAY):
        case (Brig::BRIG_OPCODE_QUERYIMAGEDEPTH):
        case (Brig::BRIG_OPCODE_QUERYIMAGEFORMAT):
        case (Brig::BRIG_OPCODE_QUERYIMAGEHEIGHT):
        case (Brig::BRIG_OPCODE_QUERYIMAGEORDER):
        case (Brig::BRIG_OPCODE_QUERYIMAGEWIDTH):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropQueryimage<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYSAMPLERBOUNDARY):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropQuerysamplerboundary<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYSAMPLERCOORD):
        case (Brig::BRIG_OPCODE_QUERYSAMPLERFILTER):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropQuerysampler<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_RDIMAGE):
        {
            InstImage i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropRdimage<InstImage>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_RECEIVELANE):
        case (Brig::BRIG_OPCODE_SENDLANE):
        {
            InstLane i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSendlane<InstLane>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_RET):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropRet<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_SAD):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSad<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_SADHI):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSadhi<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_SEGMENTP):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSegmentp<InstSeg>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_SHL):
        case (Brig::BRIG_OPCODE_SHR):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropShift<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_SHUFFLE):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropShuffle<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_SQRT):
        {
            if (InstMod i = inst)
            {
                return chkReqPropSqrt<InstMod>(i, propId);
            }
            else if (InstBasic i = inst)
            {
                return chkReqPropSqrt<InstBasic>(i, propId);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_ST):
        {
            InstMem i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSt<InstMem>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_STIMAGE):
        {
            InstImage i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSt_image<InstImage>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_STOF):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropS2f<InstSeg>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_SYNC):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSync<InstBar>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_SYSCALL):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropSyscall<InstBasic>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACK):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropUnpack<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACKCVT):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropUnpackcvt<InstSourceType>(i, propId);
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACKHI):
        case (Brig::BRIG_OPCODE_UNPACKLO):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return chkReqPropUnpackx<InstBasic>(i, propId);
            break;
        } 
        default:
            assert(false); return false;
            break;
    }
} // PropDescImpl::isValidProp 

bool PropDescImpl::validatePrimaryProps(Inst inst)
{
    unsigned prm;
    unsigned sec;
    const unsigned* props = getProps(inst.opcode(), prm, sec);
    if (prm > 0) return isValidProp(inst, props[prm - 1]);
    assert(false);
    return false;
}

template<class T> bool PropDescImpl::validateReqNeg(T inst)
{
    if (!check_type_values_s32_s64_sx_f_fx(getType<T>(inst))) return false;
    if (!check_rounding_values_none(getRounding<T>(inst))) return false;
    if (!check_ftz_values_none(getFtz<T>(inst))) return false;

    if (
        check_type_values_s32_s64_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
    }
    else if (
        check_type_values_sx_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_p_s(getPacking<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqAdd(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;

    if (
        check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_rounding_values_none(getRounding<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_rounding_values_float(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_packing_values_bin(getPacking<T>(inst))) return false;
        if (!check_rounding_values_none(getRounding<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
        if (!check_rounding_values_float(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqAlloca(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_type_values_none(getStype<T>(inst))) return false;
    if (!check_segment_values_private(getSegment<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqAnd(T inst)
{
    if (!check_type_values_b1_b32_b64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqFbar_sync_width(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!check_memord_values_none(getMemord<T>(inst))) return false;
    if (!check_memscp_values_any(getMemscp<T>(inst))) return false;
    if (!check_memfnc_values_any(getMemfnc<T>(inst))) return false;
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_FBARRIER, sizeof(OPERAND_VALUES_REG32_FBARRIER) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqAtomic(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
    if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
    if (!check_segment_values_global_group_flat(getSegment<T>(inst))) return false;
    if (!check_memscp_values_any(getMemscp<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

    if (
        check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_ld(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_ld(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqAtomic_image(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
    if (!check_type_values_rwimg(getItype<T>(inst))) return false;
    if (!check_type_values_u32(getCtype<T>(inst))) return false;
    if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;
    if (!check_atmop_values_generic_exch(getAtmop<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

    if (
        check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;

    if (
        check_geom_values_1d_1db(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_2d_1da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_3d_2da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    return true;
}

template<class T> bool PropDescImpl::validateReqAtomic_noret_image(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
    if (!check_type_values_rwimg(getItype<T>(inst))) return false;
    if (!check_type_values_u32(getCtype<T>(inst))) return false;
    if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;
    if (!check_atmop_values_generic(getAtmop<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

    if (
        check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_and_or_xor(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

    if (
        check_geom_values_1d_1db(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_2d_1da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_3d_2da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    return true;
}

template<class T> bool PropDescImpl::validateReqAtomic_noret(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
    if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;
    if (!check_segment_values_global_group_flat(getSegment<T>(inst))) return false;
    if (!check_memscp_values_any(getMemscp<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

    if (
        check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_and_or_xor(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_st(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_st(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqBarrier(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!check_memord_values_none(getMemord<T>(inst))) return false;
    if (!check_memscp_values_any(getMemscp<T>(inst))) return false;
    if (!check_memfnc_values_any(getMemfnc<T>(inst))) return false;
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqAlign(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqBitextract(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqBitinsert(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqBitmask(T inst)
{
    if (!check_type_values_b32_b64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqBitrev(T inst)
{
    if (!check_type_values_b32_b64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqBitselect(T inst)
{
    if (!check_type_values_b32_b64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqRem(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqBrn(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_LABMODEL, sizeof(OPERAND_VALUES_REGMODEL_LABMODEL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

    if (
        validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
       )
    {
        if (!check_width_values_any(getWidth<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned), false)) return false;
    }
    else if (
        validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_LABMODEL, sizeof(OPERAND_VALUES_LABMODEL) / sizeof(unsigned), false)
       )
    {
        if (!check_width_values_all(getWidth<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    return true;
}

template<class T> bool PropDescImpl::validateReqCall(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_FUNCMODEL, sizeof(OPERAND_VALUES_REGMODEL_FUNCMODEL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_CALLTAB, sizeof(OPERAND_VALUES_NULL_CALLTAB) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

    if (
        validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
       )
    {
        if (!check_width_values_any(getWidth<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_CALLTAB, sizeof(OPERAND_VALUES_NULL_CALLTAB) / sizeof(unsigned), false)) return false;
    }
    else if (
        validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_FUNCMODEL, sizeof(OPERAND_VALUES_FUNCMODEL) / sizeof(unsigned), false)
       )
    {
        if (!check_width_values_all(getWidth<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    return true;
}

template<class T> bool PropDescImpl::validateReqCbr(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG1, sizeof(OPERAND_VALUES_REG1) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_LABMODEL, sizeof(OPERAND_VALUES_REGMODEL_LABMODEL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

    if (
        validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned), false)) return false;
    }
    else if (
        validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_LABMODEL, sizeof(OPERAND_VALUES_LABMODEL) / sizeof(unsigned), false)
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqCeil(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) return false;
    if (!check_rounding_values_none(getRounding<T>(inst))) return false;
    if (!check_ftz_values_any(getFtz<T>(inst))) return false;

    if (
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
    }
    else if (
        check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_p_s(getPacking<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqClass(T inst)
{
    if (!check_type_values_b1(getType<T>(inst))) return false;
    if (!check_type_values_f(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSpec_except(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSpec_clock(T inst)
{
    if (!check_type_values_u64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqCmov(T inst)
{
    if (!check_type_values_b1_b32_b64_x(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

    if (
        check_type_values_b1_b32_b64(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG1_IMM1, sizeof(OPERAND_VALUES_REG1_IMM1) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_x(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    return true;
}

template<class T> bool PropDescImpl::validateReqCmp(T inst)
{
    if (!check_type_values_b1_s32_u32_s64_u64_f_ux(getType<T>(inst))) return false;
    if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(getStype<T>(inst))) return false;
    if (!check_rounding_values_none(getRounding<T>(inst))) return false;

    if (
        check_type_values_b1_b32_s32_u32_b64_s64_u64_f(getStype<T>(inst))
       )
    {
        if (!check_type_values_b1_s32_u32_s64_u64_f(getType<T>(inst))) return false;
    }
    else if (
        check_type_values_s8x4_u8x4(getStype<T>(inst))
       )
    {
        if (!check_type_values_u8x4(getType<T>(inst))) return false;
    }
    else if (
        check_type_values_s8x8_u8x8(getStype<T>(inst))
       )
    {
        if (!check_type_values_u8x8(getType<T>(inst))) return false;
    }
    else if (
        check_type_values_s8x16_u8x16(getStype<T>(inst))
       )
    {
        if (!check_type_values_u8x16(getType<T>(inst))) return false;
    }
    else if (
        check_type_values_s16x2_u16x2_f16x2(getStype<T>(inst))
       )
    {
        if (!check_type_values_u16x2(getType<T>(inst))) return false;
    }
    else if (
        check_type_values_s16x4_u16x4_f16x4(getStype<T>(inst))
       )
    {
        if (!check_type_values_u16x4(getType<T>(inst))) return false;
    }
    else if (
        check_type_values_s16x8_u16x8_f16x8(getStype<T>(inst))
       )
    {
        if (!check_type_values_u16x8(getType<T>(inst))) return false;
    }
    else if (
        check_type_values_s32x2_u32x2_f32x2(getStype<T>(inst))
       )
    {
        if (!check_type_values_u32x2(getType<T>(inst))) return false;
    }
    else if (
        check_type_values_s32x4_u32x4_f32x4(getStype<T>(inst))
       )
    {
        if (!check_type_values_u32x4(getType<T>(inst))) return false;
    }
    else if (
        check_type_values_s64x2_u64x2_f64x2(getStype<T>(inst))
       )
    {
        if (!check_type_values_u64x(getType<T>(inst))) return false;
    }
    else
    {
        return false;
    }

    if (
        check_type_values_b1_b32_b64(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_operator_values_eq_ne(getOperator<T>(inst))) return false;
    }
    else if (
        check_type_values_s32_u32_s64_u64(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_operator_values_eq_ne_lt_le_gt_ge(getOperator<T>(inst))) return false;
    }
    else if (
        check_type_values_f(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_operator_values_0(getOperator<T>(inst))) return false;
    }
    else if (
        check_type_values_sx_ux(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
        if (!check_packing_values_pp(getPacking<T>(inst))) return false;
        if (!check_operator_values_eq_ne_lt_le_gt_ge(getOperator<T>(inst))) return false;
    }
    else if (
        check_type_values_fx(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
        if (!check_packing_values_pp(getPacking<T>(inst))) return false;
        if (!check_operator_values_0(getOperator<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqCodeblockend(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqCombine(T inst)
{
    if (!check_type_values_b64_b128(getType<T>(inst))) return false;
    if (!check_type_values_b32_b64(getStype<T>(inst))) return false;

    if (
        check_type_values_b64(getType<T>(inst)) &&
        check_type_values_b32(getStype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_b128(getType<T>(inst)) &&
        check_type_values_b64(getStype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_b128(getType<T>(inst)) &&
        check_type_values_b32(getStype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqCopysign(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) return false;
    if (!check_rounding_values_none(getRounding<T>(inst))) return false;
    if (!check_ftz_values_none(getFtz<T>(inst))) return false;

    if (
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
    }
    else if (
        check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqCountlane(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_type_values_u32_b1(getStype<T>(inst))) return false;
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqCountuplane(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_type_values_none(getStype<T>(inst))) return false;
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSpec_reg(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSpec_reg_dim(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM012, sizeof(OPERAND_VALUES_IMM012) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqCvt(T inst)
{
    if (!check_type_values_b1_s_u_f(getType<T>(inst))) return false;
    if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;

    if (
        check_type_values_b1(getType<T>(inst))
       )
    {
        if (!check_type_values_u_s_f(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_s8_u8(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s16_u16_s32_u32_s64_u64_f(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_s16_u16(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s8_u8_s32_u32_s64_u64_f(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_s32_u32(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s8_u8_s16_u16_s64_u64_f(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_s64_u64(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s8_u8_s16_u16_s32_u32_f(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_f16(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_f32(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_f64(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s_u_f(getStype<T>(inst))) return false;
    }
    else
    {
        return false;
    }

    if (
        check_type_values_b1_s_u(getStype<T>(inst)) &&
        check_type_values_b1_s_u(getType<T>(inst))
       )
    {
        if (!check_rounding_values_none(getRounding<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_b1(getStype<T>(inst)) &&
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_rounding_values_none(getRounding<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_s_u(getStype<T>(inst)) &&
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_rounding_values_float(getRounding<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_f(getStype<T>(inst)) &&
        check_type_values_b1(getType<T>(inst))
       )
    {
        if (!check_rounding_values_none(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_f(getStype<T>(inst)) &&
        check_type_values_s_u(getType<T>(inst))
       )
    {
        if (!check_rounding_values_int(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_f32(getStype<T>(inst)) &&
        check_type_values_f16(getType<T>(inst))
       )
    {
        if (!check_rounding_values_float(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_f64(getStype<T>(inst)) &&
        check_type_values_f16_f32(getType<T>(inst))
       )
    {
        if (!check_rounding_values_float(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_f(getStype<T>(inst)) &&
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_rounding_values_none(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_EXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_SEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqDebugtrap(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqAqlptr(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) return false;
    if (!check_type_values_none(getStype<T>(inst))) return false;
    if (!check_segment_values_global(getSegment<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqDiv(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_fx(getType<T>(inst))) return false;

    if (
        check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_rounding_values_none(getRounding<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_rounding_values_float(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
        if (!check_rounding_values_float(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqExpand(T inst)
{
    if (!check_type_values_b32_b64(getType<T>(inst))) return false;
    if (!check_type_values_b64_b128(getStype<T>(inst))) return false;

    if (
        check_type_values_b32(getType<T>(inst)) &&
        check_type_values_b64(getStype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_b32(getType<T>(inst)) &&
        check_type_values_b128(getStype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_b64(getType<T>(inst)) &&
        check_type_values_b128(getStype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqFirstbit(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_type_values_s32_u32_s64_u64(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqFma(T inst)
{
    if (!check_type_values_f(getType<T>(inst))) return false;
    if (!check_packing_values_none(getPacking<T>(inst))) return false;
    if (!check_rounding_values_float(getRounding<T>(inst))) return false;
    if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqFract(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) return false;
    if (!check_rounding_values_none(getRounding<T>(inst))) return false;
    if (!check_ftz_values_any(getFtz<T>(inst))) return false;

    if (
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
    }
    else if (
        check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_p_s(getPacking<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqF2s(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) return false;
    if (!check_type_values_u32_u64(getStype<T>(inst))) return false;
    if (!check_segment_values_std(getSegment<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;
    if (!validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_MODEL, sizeof(STYPESIZE_VALUES_MODEL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_append_consume(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_segment_values_gcn(getSegment<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_atomic(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
    if (!check_atmop_values_generic_exch_ld(getAtmop<T>(inst))) return false;
    if (!check_segment_values_gcn(getSegment<T>(inst))) return false;
    if (!check_memscp_values_any(getMemscp<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

    if (
        check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_ld(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_ld(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_atomic_noret(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) return false;
    if (!check_atmop_values_generic_st(getAtmop<T>(inst))) return false;
    if (!check_segment_values_gcn(getSegment<T>(inst))) return false;
    if (!check_memscp_values_any(getMemscp<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned), false)) return false;

    if (
        check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_and_or_xor(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) return false;
        if (!check_memord_values_any(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_atmop_values_st(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) return false;
        if (!check_memord_values_st(getMemord<T>(inst))) return false;
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_b4xchg(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_bfm(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32, sizeof(OPERAND_VALUES_REG32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_fldexp(T inst)
{
    if (!check_type_values_f32_f64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_frexp_exp(T inst)
{
    if (!check_type_values_f32_f64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32, sizeof(OPERAND_VALUES_REG32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_frexp_mant(T inst)
{
    if (!check_type_values_f32_f64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_ld(T inst)
{
    if (!check_type_values_u_s_f_b128(getType<T>(inst))) return false;
    if (!check_segment_values_gcn(getSegment<T>(inst))) return false;
    if (!check_align_values_any(getAlign<T>(inst))) return false;
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    if (!validateEqclass(inst, PROP_EQCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned), false)) return false;

    if (
        check_type_values_u_s_f(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_b128(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_mad(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMM64, sizeof(OPERAND_VALUES_REG64_IMM64) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_min_max_med(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32, sizeof(OPERAND_VALUES_REG32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_mqsad(T inst)
{
    if (!check_type_values_b64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_mqsad4(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REGV432, sizeof(OPERAND_VALUES_REGV432) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMM64, sizeof(OPERAND_VALUES_REG64_IMM64) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REGV432, sizeof(OPERAND_VALUES_REGV432) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_msad(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_slp_prt(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_qsad(T inst)
{
    if (!check_type_values_b64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_region_alloc(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_st(T inst)
{
    if (!check_type_values_u_s_f_b128(getType<T>(inst))) return false;
    if (!check_segment_values_gcn(getSegment<T>(inst))) return false;
    if (!check_align_values_any(getAlign<T>(inst))) return false;
    if (!check_width_values_none(getWidth<T>(inst))) return false;
    if (!validateEqclass(inst, PROP_EQCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

    if (
        check_type_values_u_s_f(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_b128(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    return true;
}

template<class T> bool PropDescImpl::validateReqGcn_trig_preop(T inst)
{
    if (!check_type_values_f64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqFbar_none(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!check_memord_values_none(getMemord<T>(inst))) return false;
    if (!check_memscp_values_none(getMemscp<T>(inst))) return false;
    if (!check_memfnc_values_none(getMemfnc<T>(inst))) return false;
    if (!check_width_values_none(getWidth<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_FBARRIER, sizeof(OPERAND_VALUES_REG32_FBARRIER) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqFbar_width(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!check_memord_values_none(getMemord<T>(inst))) return false;
    if (!check_memscp_values_none(getMemscp<T>(inst))) return false;
    if (!check_memfnc_values_none(getMemfnc<T>(inst))) return false;
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_FBARRIER, sizeof(OPERAND_VALUES_REG32_FBARRIER) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqLd(T inst)
{
    if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) return false;
    if (!check_segment_values_any(getSegment<T>(inst))) return false;
    if (!check_align_values_any(getAlign<T>(inst))) return false;
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    if (!validateEqclass(inst, PROP_EQCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned), false)) return false;

    if (
        check_type_values_u_s_f(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_b128_roimg_rwimg_samp(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqLda(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) return false;
    if (!check_segment_values_any(getSegment<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqLdc(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_LAB_FUNC, sizeof(OPERAND_VALUES_LAB_FUNC) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqLdf(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_FBARRIER, sizeof(OPERAND_VALUES_FBARRIER) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqLd_image(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
    if (!check_type_values_u32(getCtype<T>(inst))) return false;
    if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;

    if (
        check_geom_values_1d_1db(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_2d_1da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_3d_2da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!check_type_values_roimg_rwimg(getItype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMAGE, sizeof(OPERAND_VALUES_REG64_IMAGE) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

    if (
        check_type_values_roimg(getItype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_ROIMAGE, sizeof(OPERAND_VALUES_REG64_ROIMAGE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_rwimg(getItype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    return true;
}

template<class T> bool PropDescImpl::validateReqLerp(T inst)
{
    if (!check_type_values_u8x4(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqMad(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqMad24(T inst)
{
    if (!check_type_values_s32_u32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqMasklane(T inst)
{
    if (!check_type_values_b64(getType<T>(inst))) return false;
    if (!check_type_values_u32_b1(getStype<T>(inst))) return false;
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqMax(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;
    if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    if (!check_rounding_values_none(getRounding<T>(inst))) return false;

    if (
        check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqMov(T inst)
{
    if (!check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_roimg_rwimg_samp(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqMul(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) return false;
    if (!check_ftz_values_any(getFtz<T>(inst))) return false;

    if (
        check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_rounding_values_none(getRounding<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
        if (!check_rounding_values_float(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_packing_values_bin(getPacking<T>(inst))) return false;
        if (!check_rounding_values_none(getRounding<T>(inst))) return false;
        if (!check_ftz_values_none(getFtz<T>(inst))) return false;
    }
    else if (
        check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
        if (!check_rounding_values_float(getRounding<T>(inst))) return false;
        if (!check_ftz_values_any(getFtz<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqMul24(T inst)
{
    if (!check_type_values_s32_u32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqMulhi(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_sx_ux(getType<T>(inst))) return false;
    if (!check_rounding_values_none(getRounding<T>(inst))) return false;
    if (!check_ftz_values_none(getFtz<T>(inst))) return false;

    if (
        check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
    }
    else if (
        check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqTrig32(T inst)
{
    if (!check_type_values_f32(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqNfma(T inst)
{
    if (!check_type_values_f(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqNop(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqNot(T inst)
{
    if (!check_type_values_b1_b32_b64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqTrig(T inst)
{
    if (!check_type_values_f(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqNullptr(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) return false;
    if (!check_type_values_none(getStype<T>(inst))) return false;
    if (!check_segment_values_any(getSegment<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqPack(T inst)
{
    if (!check_type_values_x(getType<T>(inst))) return false;
    if (!check_type_values_s32_u32_s64_u64_f(getStype<T>(inst))) return false;

    if (
        check_type_values_s8x_s16x_s32x(getType<T>(inst))
       )
    {
        if (!check_type_values_s32_s64(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_s64x(getType<T>(inst))
       )
    {
        if (!check_type_values_s64(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_u8x_u16x_u32x(getType<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_u64x(getType<T>(inst))
       )
    {
        if (!check_type_values_u64(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_f16x(getType<T>(inst))
       )
    {
        if (!check_type_values_f16(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_f32x(getType<T>(inst))
       )
    {
        if (!check_type_values_f32(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_f64x(getType<T>(inst))
       )
    {
        if (!check_type_values_f64(getStype<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqPackcvt(T inst)
{
    if (!check_type_values_u8x4(getType<T>(inst))) return false;
    if (!check_type_values_f32(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqPopcount(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_type_values_b32_b64(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqQueryimage(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_type_values_roimg_rwimg(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMAGE, sizeof(OPERAND_VALUES_REG64_IMAGE) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

    if (
        check_type_values_roimg(getStype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_ROIMAGE, sizeof(OPERAND_VALUES_REG64_ROIMAGE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_rwimg(getStype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    return true;
}

template<class T> bool PropDescImpl::validateReqQuerysamplerboundary(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_type_values_samp(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_SAMPLER, sizeof(OPERAND_VALUES_REG64_SAMPLER) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqQuerysampler(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_type_values_samp(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_SAMPLER, sizeof(OPERAND_VALUES_REG64_SAMPLER) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqRdimage(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
    if (!check_type_values_roimg_rwimg(getItype<T>(inst))) return false;
    if (!check_type_values_s32_f32(getCtype<T>(inst))) return false;
    if (!check_geom_values_1d_2d_3d_1da_2da(getGeom<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMAGE, sizeof(OPERAND_VALUES_REG64_IMAGE) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_SAMPLER, sizeof(OPERAND_VALUES_REG64_SAMPLER) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;

    if (
        check_type_values_roimg(getItype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_ROIMAGE, sizeof(OPERAND_VALUES_REG64_ROIMAGE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_rwimg(getItype<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }

    if (
        check_geom_values_1d(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_2d_1da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_3d_2da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    return true;
}

template<class T> bool PropDescImpl::validateReqSendlane(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) return false;
    if (!check_type_values_none(getStype<T>(inst))) return false;
    if (!check_width_values_any(getWidth<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqRet(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSad(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) return false;
    if (!check_type_values_u32_u8x4_u16x2(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSadhi(T inst)
{
    if (!check_type_values_u16x2(getType<T>(inst))) return false;
    if (!check_type_values_u8x4(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSegmentp(T inst)
{
    if (!check_type_values_b1(getType<T>(inst))) return false;
    if (!check_type_values_u32_u64(getStype<T>(inst))) return false;
    if (!check_segment_values_std(getSegment<T>(inst))) return false;
    if (!validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_MODEL, sizeof(STYPESIZE_VALUES_MODEL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqShift(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_sx_ux(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqShuffle(T inst)
{
    if (!check_type_values_x32_x64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSqrt(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) return false;
    if (!check_rounding_values_float(getRounding<T>(inst))) return false;
    if (!check_ftz_values_any(getFtz<T>(inst))) return false;

    if (
        check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) return false;
    }
    else if (
        check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_p_s(getPacking<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSt(T inst)
{
    if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) return false;
    if (!check_segment_values_writable(getSegment<T>(inst))) return false;
    if (!check_align_values_any(getAlign<T>(inst))) return false;
    if (!check_width_values_none(getWidth<T>(inst))) return false;
    if (!validateEqclass(inst, PROP_EQCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned), false)) return false;

    if (
        check_type_values_u_s_f(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_type_values_b128_roimg_rwimg_samp(getType<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSt_image(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) return false;
    if (!check_type_values_u32(getCtype<T>(inst))) return false;
    if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) return false;

    if (
        check_geom_values_1d_1db(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_2d_1da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned), false)) return false;
    }
    else if (
        check_geom_values_3d_2da(getGeom<T>(inst))
       )
    {
        if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned), false)) return false;
    }
    else
    {
        return false;
    }
    if (!check_type_values_rwimg(getItype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_RWIMAGE, sizeof(OPERAND_VALUES_REG64_RWIMAGE) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqS2f(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) return false;
    if (!check_type_values_u32_u64(getStype<T>(inst))) return false;
    if (!check_segment_values_std(getSegment<T>(inst))) return false;
    if (!validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned), false)) return false;
    if (!validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_SEG, sizeof(STYPESIZE_VALUES_SEG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSync(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) return false;
    if (!check_memord_values_any(getMemord<T>(inst))) return false;
    if (!check_memscp_values_any(getMemscp<T>(inst))) return false;
    if (!check_memfnc_values_any(getMemfnc<T>(inst))) return false;
    if (!check_width_values_none(getWidth<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqSyscall(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqUnpack(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f(getType<T>(inst))) return false;
    if (!check_type_values_x(getStype<T>(inst))) return false;

    if (
        check_type_values_s32(getType<T>(inst))
       )
    {
        if (!check_type_values_s8x_s16x_s32x(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_s64(getType<T>(inst))
       )
    {
        if (!check_type_values_s8x_s16x_s32x_s64x(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_u32(getType<T>(inst))
       )
    {
        if (!check_type_values_u8x_u16x_u32x(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_u64(getType<T>(inst))
       )
    {
        if (!check_type_values_u8x_u16x_u32x_u64x(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_f16(getType<T>(inst))
       )
    {
        if (!check_type_values_f16x(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_f32(getType<T>(inst))
       )
    {
        if (!check_type_values_f32x(getStype<T>(inst))) return false;
    }
    else if (
        check_type_values_f64(getType<T>(inst))
       )
    {
        if (!check_type_values_f64x(getStype<T>(inst))) return false;
    }
    else
    {
        return false;
    }
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqUnpackcvt(T inst)
{
    if (!check_type_values_f32(getType<T>(inst))) return false;
    if (!check_type_values_u8x4(getStype<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM0123, sizeof(OPERAND_VALUES_IMM0123) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

template<class T> bool PropDescImpl::validateReqUnpackx(T inst)
{
    if (!check_type_values_x32_x64(getType<T>(inst))) return false;
    if (!validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    if (!validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned), false)) return false;
    return true;
}

bool PropDescImpl::isValidInst(Inst inst)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ABS):
        case (Brig::BRIG_OPCODE_NEG):
        {
            if (InstMod i = inst)
            {
                return validateReqNeg<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqNeg<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_ADD):
        case (Brig::BRIG_OPCODE_SUB):
        {
            if (InstMod i = inst)
            {
                return validateReqAdd<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqAdd<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_ALLOCA):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return validateReqAlloca<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_AND):
        case (Brig::BRIG_OPCODE_OR):
        case (Brig::BRIG_OPCODE_XOR):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqAnd<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ARRIVEFBAR):
        case (Brig::BRIG_OPCODE_WAITFBAR):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return validateReqFbar_sync_width<InstBar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqAtomic<InstAtomic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMICIMAGE):
        {
            InstAtomicImage i = inst;
            if (!i) { assert(false); return false; }
            return validateReqAtomic_image<InstAtomicImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMICIMAGENORET):
        {
            InstAtomicImage i = inst;
            if (!i) { assert(false); return false; }
            return validateReqAtomic_noret_image<InstAtomicImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMICNORET):
        {
            InstAtomic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqAtomic_noret<InstAtomic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BARRIER):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return validateReqBarrier<InstBar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITALIGN):
        case (Brig::BRIG_OPCODE_BYTEALIGN):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqAlign<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITEXTRACT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqBitextract<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITINSERT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqBitinsert<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITMASK):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqBitmask<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITREV):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqBitrev<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITSELECT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqBitselect<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BORROW):
        case (Brig::BRIG_OPCODE_CARRY):
        case (Brig::BRIG_OPCODE_REM):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqRem<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BRN):
        {
            InstBr i = inst;
            if (!i) { assert(false); return false; }
            return validateReqBrn<InstBr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CALL):
        {
            InstBr i = inst;
            if (!i) { assert(false); return false; }
            return validateReqCall<InstBr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CBR):
        {
            InstBr i = inst;
            if (!i) { assert(false); return false; }
            return validateReqCbr<InstBr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CEIL):
        case (Brig::BRIG_OPCODE_FLOOR):
        case (Brig::BRIG_OPCODE_RINT):
        case (Brig::BRIG_OPCODE_TRUNC):
        {
            if (InstMod i = inst)
            {
                return validateReqCeil<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqCeil<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_CLASS):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqClass<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CLEARDETECTEXCEPT):
        case (Brig::BRIG_OPCODE_SETDETECTEXCEPT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSpec_except<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CLOCK):
        case (Brig::BRIG_OPCODE_DISPATCHID):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSpec_clock<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CMOV):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqCmov<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CMP):
        {
            InstCmp i = inst;
            if (!i) { assert(false); return false; }
            return validateReqCmp<InstCmp>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CODEBLOCKEND):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqCodeblockend<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_COMBINE):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqCombine<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_COPYSIGN):
        {
            if (InstMod i = inst)
            {
                return validateReqCopysign<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqCopysign<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_COUNTLANE):
        {
            InstLane i = inst;
            if (!i) { assert(false); return false; }
            return validateReqCountlane<InstLane>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_COUNTUPLANE):
        {
            InstLane i = inst;
            if (!i) { assert(false); return false; }
            return validateReqCountuplane<InstLane>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CUID):
        case (Brig::BRIG_OPCODE_DIM):
        case (Brig::BRIG_OPCODE_GETDETECTEXCEPT):
        case (Brig::BRIG_OPCODE_LANEID):
        case (Brig::BRIG_OPCODE_MAXCUID):
        case (Brig::BRIG_OPCODE_MAXWAVEID):
        case (Brig::BRIG_OPCODE_QID):
        case (Brig::BRIG_OPCODE_WAVEID):
        case (Brig::BRIG_OPCODE_WORKITEMFLATABSID):
        case (Brig::BRIG_OPCODE_WORKITEMFLATID):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSpec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE):
        case (Brig::BRIG_OPCODE_GRIDGROUPS):
        case (Brig::BRIG_OPCODE_GRIDSIZE):
        case (Brig::BRIG_OPCODE_WORKGROUPID):
        case (Brig::BRIG_OPCODE_WORKGROUPSIZE):
        case (Brig::BRIG_OPCODE_WORKITEMABSID):
        case (Brig::BRIG_OPCODE_WORKITEMID):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSpec_reg_dim<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CVT):
        {
            InstCvt i = inst;
            if (!i) { assert(false); return false; }
            return validateReqCvt<InstCvt>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_DEBUGTRAP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqDebugtrap<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_DISPATCHPTR):
        case (Brig::BRIG_OPCODE_QPTR):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return validateReqAqlptr<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_DIV):
        {
            if (InstMod i = inst)
            {
                return validateReqDiv<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqDiv<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_EXPAND):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqExpand<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_FIRSTBIT):
        case (Brig::BRIG_OPCODE_LASTBIT):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqFirstbit<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_FMA):
        {
            if (InstMod i = inst)
            {
                return validateReqFma<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqFma<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_FRACT):
        {
            if (InstMod i = inst)
            {
                return validateReqFract<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqFract<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_FTOS):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return validateReqF2s<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNAPPEND):
        case (Brig::BRIG_OPCODE_GCNCONSUME):
        {
            InstAddr i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_append_consume<InstAddr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_atomic<InstAtomic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNATOMICNORET):
        {
            InstAtomic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_atomic_noret<InstAtomic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNB32XCHG):
        case (Brig::BRIG_OPCODE_GCNB4XCHG):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_b4xchg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNBFM):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_bfm<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNFLDEXP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_fldexp<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNFREXP_EXP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_frexp_exp<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNFREXP_MANT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_frexp_mant<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNLD):
        {
            InstMem i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_ld<InstMem>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMADS):
        case (Brig::BRIG_OPCODE_GCNMADU):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_mad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMAX3):
        case (Brig::BRIG_OPCODE_GCNMED3):
        case (Brig::BRIG_OPCODE_GCNMIN3):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_min_max_med<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMQSAD):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_mqsad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMQSAD4):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_mqsad4<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMSAD):
        case (Brig::BRIG_OPCODE_GCNSADD):
        case (Brig::BRIG_OPCODE_GCNSADW):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_msad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNPRIORITY):
        case (Brig::BRIG_OPCODE_GCNSLEEP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_slp_prt<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNQSAD):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_qsad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNREGIONALLOC):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_region_alloc<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNST):
        {
            InstMem i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_st<InstMem>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNTRIG_PREOP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqGcn_trig_preop<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_INITFBAR):
        case (Brig::BRIG_OPCODE_RELEASEFBAR):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return validateReqFbar_none<InstBar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_JOINFBAR):
        case (Brig::BRIG_OPCODE_LEAVEFBAR):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return validateReqFbar_width<InstBar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LD):
        {
            InstMem i = inst;
            if (!i) { assert(false); return false; }
            return validateReqLd<InstMem>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDA):
        {
            InstAddr i = inst;
            if (!i) { assert(false); return false; }
            return validateReqLda<InstAddr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDC):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqLdc<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDF):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqLdf<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDIMAGE):
        {
            InstImage i = inst;
            if (!i) { assert(false); return false; }
            return validateReqLd_image<InstImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LERP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqLerp<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAD):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqMad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAD24):
        case (Brig::BRIG_OPCODE_MAD24HI):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqMad24<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MASKLANE):
        {
            InstLane i = inst;
            if (!i) { assert(false); return false; }
            return validateReqMasklane<InstLane>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAX):
        case (Brig::BRIG_OPCODE_MIN):
        {
            if (InstMod i = inst)
            {
                return validateReqMax<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqMax<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_MOV):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqMov<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MUL):
        {
            if (InstMod i = inst)
            {
                return validateReqMul<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqMul<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_MUL24):
        case (Brig::BRIG_OPCODE_MUL24HI):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqMul24<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MULHI):
        {
            if (InstMod i = inst)
            {
                return validateReqMulhi<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqMulhi<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_NCOS):
        case (Brig::BRIG_OPCODE_NEXP2):
        case (Brig::BRIG_OPCODE_NLOG2):
        case (Brig::BRIG_OPCODE_NSIN):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqTrig32<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NFMA):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqNfma<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NOP):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqNop<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NOT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqNot<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NRCP):
        case (Brig::BRIG_OPCODE_NRSQRT):
        case (Brig::BRIG_OPCODE_NSQRT):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqTrig<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NULLPTR):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return validateReqNullptr<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_PACK):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqPack<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_PACKCVT):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqPackcvt<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_POPCOUNT):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqPopcount<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYIMAGEARRAY):
        case (Brig::BRIG_OPCODE_QUERYIMAGEDEPTH):
        case (Brig::BRIG_OPCODE_QUERYIMAGEFORMAT):
        case (Brig::BRIG_OPCODE_QUERYIMAGEHEIGHT):
        case (Brig::BRIG_OPCODE_QUERYIMAGEORDER):
        case (Brig::BRIG_OPCODE_QUERYIMAGEWIDTH):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqQueryimage<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYSAMPLERBOUNDARY):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqQuerysamplerboundary<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYSAMPLERCOORD):
        case (Brig::BRIG_OPCODE_QUERYSAMPLERFILTER):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqQuerysampler<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_RDIMAGE):
        {
            InstImage i = inst;
            if (!i) { assert(false); return false; }
            return validateReqRdimage<InstImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_RECEIVELANE):
        case (Brig::BRIG_OPCODE_SENDLANE):
        {
            InstLane i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSendlane<InstLane>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_RET):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqRet<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SAD):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSad<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SADHI):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSadhi<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SEGMENTP):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSegmentp<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SHL):
        case (Brig::BRIG_OPCODE_SHR):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqShift<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SHUFFLE):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqShuffle<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SQRT):
        {
            if (InstMod i = inst)
            {
                return validateReqSqrt<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return validateReqSqrt<InstBasic>(i);
            }
            else
            {
                assert(false); return false;
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_ST):
        {
            InstMem i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSt<InstMem>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_STIMAGE):
        {
            InstImage i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSt_image<InstImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_STOF):
        {
            InstSeg i = inst;
            if (!i) { assert(false); return false; }
            return validateReqS2f<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SYNC):
        {
            InstBar i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSync<InstBar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SYSCALL):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqSyscall<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACK):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqUnpack<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACKCVT):
        {
            InstSourceType i = inst;
            if (!i) { assert(false); return false; }
            return validateReqUnpackcvt<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACKHI):
        case (Brig::BRIG_OPCODE_UNPACKLO):
        {
            InstBasic i = inst;
            if (!i) { assert(false); return false; }
            return validateReqUnpackx<InstBasic>(i);
            break;
        } 
        default:
            assert(false); return false;
            break;
    }
} // PropDescImpl::isValidInst 

} // namespace HSAIL_ASM 
