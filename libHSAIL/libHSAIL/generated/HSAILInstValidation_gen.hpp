// University of Illinois/NCSA
// Open Source License
// 
// Copyright (c) 2013, Advanced Micro Devices, Inc.
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

using HSAIL_ASM::Inst;

namespace HSAIL_ASM {

class InstValidator : public InstValidatorBase 
{
public:
    InstValidator(unsigned type) : InstValidatorBase(type) {}
    void validateInst(Inst inst);

private:
    static unsigned ALIGN_VALUES_ANY[];
    static unsigned ATMOP_VALUES_ADD_AND_CAS_DEC_EXCH_INC_MAX_MIN_OR_SUB_XOR[];
    static unsigned ATMOP_VALUES_ADD_AND_CAS_DEC_INC_MAX_MIN_OR_SUB_XOR[];
    static unsigned ATMOP_VALUES_ADD_SUB_MIN_MAX[];
    static unsigned ATMOP_VALUES_AND_OR_XOR_EXCH[];
    static unsigned ATMOP_VALUES_AND_OR_XOR[];
    static unsigned ATMOP_VALUES_CAS[];
    static unsigned ATMOP_VALUES_INC_DEC[];
    static unsigned FTZ_VALUES_NONE[];
    static unsigned FTZ_VALUES_ANY[];
    static unsigned GEOM_VALUES_1D[];
    static unsigned GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA[];
    static unsigned GEOM_VALUES_1D_2D_3D_1DA_2DA[];
    static unsigned GEOM_VALUES_1D_1DB[];
    static unsigned GEOM_VALUES_2D_1DA[];
    static unsigned GEOM_VALUES_3D_2DA[];
    static unsigned MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL[];
    static unsigned MSEM_VALUES_REG_ACQ_PARTACQ[];
    static unsigned MSEM_VALUES_REG_REL_PARTREL[];
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
    static unsigned OPERAND_VALUES_REG1_IMM1[];
    static unsigned OPERAND_VALUES_IMM32[];
    static unsigned OPERAND_VALUES_REG1_REG32_IMM32[];
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
    static unsigned SYNC_VALUES_BOTH_GLOBAL_GROUP_NONE_PARTIAL_PARTIALBOTH[];
    static unsigned SYNC_VALUES_NONE[];
    static unsigned TYPE_VALUES_B1[];
    static unsigned TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_ROIMG_RWIMG_SAMP[];
    static unsigned TYPE_VALUES_B1_B32_B64[];
    static unsigned TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_X[];
    static unsigned TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_UX[];
    static unsigned TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F[];
    static unsigned TYPE_VALUES_B1_B32_B64_X[];
    static unsigned TYPE_VALUES_B1_S_U_F[];
    static unsigned TYPE_VALUES_B1_S_U[];
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
    static unsigned TYPE_VALUES_S32_U32_F32[];
    static unsigned TYPE_VALUES_U32_F32[];
    static unsigned TYPE_VALUES_F32X[];
    static unsigned TYPE_VALUES_S32X2_U32X2_F32X2[];
    static unsigned TYPE_VALUES_S32X4_U32X4_F32X4[];
    static unsigned TYPE_VALUES_F64[];
    static unsigned TYPE_VALUES_F64X[];
    static unsigned TYPE_VALUES_S64X2_U64X2_F64X2[];
    static unsigned TYPE_VALUES_NONE[];
    static unsigned TYPE_VALUES_ROIMG_RWIMG[];
    static unsigned TYPE_VALUES_RWIMG[];
    static unsigned TYPE_VALUES_S_U[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64_SX_UX[];
    static unsigned TYPE_VALUES_S8X_S16X_S32X_S64X[];
    static unsigned TYPE_VALUES_SX_UX[];
    static unsigned TYPE_VALUES_S8X_S16X_S32X[];
    static unsigned TYPE_VALUES_S32[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64[];
    static unsigned TYPE_VALUES_S32_U32[];
    static unsigned TYPE_VALUES_S64[];
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
    static unsigned TYPE_VALUES_U64X2[];
    static unsigned TYPE_VALUES_U8X16[];
    static unsigned TYPE_VALUES_U8X4[];
    static unsigned TYPE_VALUES_U8X8[];
    static unsigned TYPESIZE_VALUES_MODEL[];
    static unsigned TYPESIZE_VALUES_SEG[];
    static unsigned WIDTH_VALUES_ANY[];
    static unsigned WIDTH_VALUES_ALL[];
    static unsigned WIDTH_VALUES_NONE[];

private:
    static bool check_align_values_any(unsigned val);
    static bool check_atmop_values_add_and_cas_dec_exch_inc_max_min_or_sub_xor(unsigned val);
    static bool check_atmop_values_add_and_cas_dec_inc_max_min_or_sub_xor(unsigned val);
    static bool check_atmop_values_add_sub_min_max(unsigned val);
    static bool check_atmop_values_and_or_xor_exch(unsigned val);
    static bool check_atmop_values_and_or_xor(unsigned val);
    static bool check_atmop_values_cas(unsigned val);
    static bool check_atmop_values_inc_dec(unsigned val);
    static bool check_ftz_values_none(unsigned val);
    static bool check_ftz_values_any(unsigned val);
    static bool check_geom_values_1d(unsigned val);
    static bool check_geom_values_1d_2d_3d_1db_1da_2da(unsigned val);
    static bool check_geom_values_1d_2d_3d_1da_2da(unsigned val);
    static bool check_geom_values_1d_1db(unsigned val);
    static bool check_geom_values_2d_1da(unsigned val);
    static bool check_geom_values_3d_2da(unsigned val);
    static bool check_msem_values_reg_acq_acqrel_partacqrel(unsigned val);
    static bool check_msem_values_reg_acq_partacq(unsigned val);
    static bool check_msem_values_reg_rel_partrel(unsigned val);
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
    static bool check_sync_values_both_global_group_none_partial_partialboth(unsigned val);
    static bool check_sync_values_none(unsigned val);
    static bool check_type_values_b1(unsigned val);
    static bool check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_roimg_rwimg_samp(unsigned val);
    static bool check_type_values_b1_b32_b64(unsigned val);
    static bool check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(unsigned val);
    static bool check_type_values_b1_b32_s32_u32_b64_s64_u64_f_ux(unsigned val);
    static bool check_type_values_b1_b32_s32_u32_b64_s64_u64_f(unsigned val);
    static bool check_type_values_b1_b32_b64_x(unsigned val);
    static bool check_type_values_b1_s_u_f(unsigned val);
    static bool check_type_values_b1_s_u(unsigned val);
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
    static bool check_type_values_s32_u32_f32(unsigned val);
    static bool check_type_values_u32_f32(unsigned val);
    static bool check_type_values_f32x(unsigned val);
    static bool check_type_values_s32x2_u32x2_f32x2(unsigned val);
    static bool check_type_values_s32x4_u32x4_f32x4(unsigned val);
    static bool check_type_values_f64(unsigned val);
    static bool check_type_values_f64x(unsigned val);
    static bool check_type_values_s64x2_u64x2_f64x2(unsigned val);
    static bool check_type_values_none(unsigned val);
    static bool check_type_values_roimg_rwimg(unsigned val);
    static bool check_type_values_rwimg(unsigned val);
    static bool check_type_values_s_u(unsigned val);
    static bool check_type_values_s32_u32_s64_u64_sx_ux(unsigned val);
    static bool check_type_values_s8x_s16x_s32x_s64x(unsigned val);
    static bool check_type_values_sx_ux(unsigned val);
    static bool check_type_values_s8x_s16x_s32x(unsigned val);
    static bool check_type_values_s32(unsigned val);
    static bool check_type_values_s32_u32_s64_u64(unsigned val);
    static bool check_type_values_s32_u32(unsigned val);
    static bool check_type_values_s64(unsigned val);
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
    static bool check_type_values_u64x2(unsigned val);
    static bool check_type_values_u8x16(unsigned val);
    static bool check_type_values_u8x4(unsigned val);
    static bool check_type_values_u8x8(unsigned val);
    static bool check_width_values_any(unsigned val);
    static bool check_width_values_all(unsigned val);
    static bool check_width_values_none(unsigned val);

private:
    template<class T> bool req_add(T inst);
    template<class T> bool req_align(T inst);
    template<class T> bool req_alloca(T inst);
    template<class T> bool req_and(T inst);
    template<class T> bool req_atomic(T inst);
    template<class T> bool req_atomic_image(T inst);
    template<class T> bool req_atomic_noret(T inst);
    template<class T> bool req_atomic_noret_image(T inst);
    template<class T> bool req_barrier(T inst);
    template<class T> bool req_bitextract(T inst);
    template<class T> bool req_bitinsert(T inst);
    template<class T> bool req_bitmask(T inst);
    template<class T> bool req_bitrev(T inst);
    template<class T> bool req_bitselect(T inst);
    template<class T> bool req_brn(T inst);
    template<class T> bool req_call(T inst);
    template<class T> bool req_cbr(T inst);
    template<class T> bool req_ceil(T inst);
    template<class T> bool req_class(T inst);
    template<class T> bool req_cmov(T inst);
    template<class T> bool req_cmp(T inst);
    template<class T> bool req_combine(T inst);
    template<class T> bool req_copysign(T inst);
    template<class T> bool req_countlane(T inst);
    template<class T> bool req_countuplane(T inst);
    template<class T> bool req_cvt(T inst);
    template<class T> bool req_d0_s1(T inst);
    template<class T> bool req_d0_s1_s2(T inst);
    template<class T> bool req_d0_s1_s2_s3(T inst);
    template<class T> bool req_debugtrap(T inst);
    template<class T> bool req_dispatchptr(T inst);
    template<class T> bool req_div(T inst);
    template<class T> bool req_expand(T inst);
    template<class T> bool req_f2s(T inst);
    template<class T> bool req_fbar_none(T inst);
    template<class T> bool req_fbar_sync_width(T inst);
    template<class T> bool req_fbar_width(T inst);
    template<class T> bool req_firstbit(T inst);
    template<class T> bool req_fma(T inst);
    template<class T> bool req_fract(T inst);
    template<class T> bool req_gcn_append_consume(T inst);
    template<class T> bool req_gcn_atomic(T inst);
    template<class T> bool req_gcn_atomic_noret(T inst);
    template<class T> bool req_gcn_b4xchg(T inst);
    template<class T> bool req_gcn_bfm(T inst);
    template<class T> bool req_gcn_fldexp(T inst);
    template<class T> bool req_gcn_frexp_exp(T inst);
    template<class T> bool req_gcn_frexp_mant(T inst);
    template<class T> bool req_gcn_ld(T inst);
    template<class T> bool req_gcn_mad(T inst);
    template<class T> bool req_gcn_min_max_med(T inst);
    template<class T> bool req_gcn_mqsad(T inst);
    template<class T> bool req_gcn_mqsad4(T inst);
    template<class T> bool req_gcn_msad(T inst);
    template<class T> bool req_gcn_qsad(T inst);
    template<class T> bool req_gcn_region_alloc(T inst);
    template<class T> bool req_gcn_slp_prt(T inst);
    template<class T> bool req_gcn_st(T inst);
    template<class T> bool req_gcn_trig_preop(T inst);
    template<class T> bool req_ld(T inst);
    template<class T> bool req_ld_image(T inst);
    template<class T> bool req_ld_st_image(T inst);
    template<class T> bool req_lda(T inst);
    template<class T> bool req_ldc(T inst);
    template<class T> bool req_ldf(T inst);
    template<class T> bool req_lerp(T inst);
    template<class T> bool req_mad(T inst);
    template<class T> bool req_mad24(T inst);
    template<class T> bool req_masklane(T inst);
    template<class T> bool req_max(T inst);
    template<class T> bool req_mov(T inst);
    template<class T> bool req_mul(T inst);
    template<class T> bool req_mul24(T inst);
    template<class T> bool req_mulhi(T inst);
    template<class T> bool req_neg(T inst);
    template<class T> bool req_nfma(T inst);
    template<class T> bool req_nop(T inst);
    template<class T> bool req_not(T inst);
    template<class T> bool req_pack(T inst);
    template<class T> bool req_packcvt(T inst);
    template<class T> bool req_popcount(T inst);
    template<class T> bool req_ptr(T inst);
    template<class T> bool req_queryimage(T inst);
    template<class T> bool req_querysampler(T inst);
    template<class T> bool req_rdimage(T inst);
    template<class T> bool req_rem(T inst);
    template<class T> bool req_ret(T inst);
    template<class T> bool req_s2f(T inst);
    template<class T> bool req_sad(T inst);
    template<class T> bool req_sadhi(T inst);
    template<class T> bool req_segmentp(T inst);
    template<class T> bool req_sendlane(T inst);
    template<class T> bool req_shift(T inst);
    template<class T> bool req_shuffle(T inst);
    template<class T> bool req_spec_clock(T inst);
    template<class T> bool req_spec_except(T inst);
    template<class T> bool req_spec_reg(T inst);
    template<class T> bool req_spec_reg_dim(T inst);
    template<class T> bool req_sqrt(T inst);
    template<class T> bool req_st(T inst);
    template<class T> bool req_st_image(T inst);
    template<class T> bool req_sync(T inst);
    template<class T> bool req_syscall(T inst);
    template<class T> bool req_trig(T inst);
    template<class T> bool req_trig32(T inst);
    template<class T> bool req_unpack(T inst);
    template<class T> bool req_unpackcvt(T inst);
    template<class T> bool req_unpackx(T inst);

}; // class InstValidator 

unsigned InstValidator::ALIGN_VALUES_ANY[] = {
    0,
    1
};

unsigned InstValidator::ATMOP_VALUES_ADD_AND_CAS_DEC_EXCH_INC_MAX_MIN_OR_SUB_XOR[] = {
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

unsigned InstValidator::ATMOP_VALUES_ADD_AND_CAS_DEC_INC_MAX_MIN_OR_SUB_XOR[] = {
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

unsigned InstValidator::ATMOP_VALUES_ADD_SUB_MIN_MAX[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_SUB
};

unsigned InstValidator::ATMOP_VALUES_AND_OR_XOR_EXCH[] = {
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_XOR
};

unsigned InstValidator::ATMOP_VALUES_AND_OR_XOR[] = {
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_XOR
};

unsigned InstValidator::ATMOP_VALUES_CAS[] = {
    Brig::BRIG_ATOMIC_CAS
};

unsigned InstValidator::ATMOP_VALUES_INC_DEC[] = {
    Brig::BRIG_ATOMIC_DEC,
    Brig::BRIG_ATOMIC_INC
};

unsigned InstValidator::FTZ_VALUES_NONE[] = {
    0
};

unsigned InstValidator::FTZ_VALUES_ANY[] = {
    0,
    1
};

unsigned InstValidator::GEOM_VALUES_1D[] = {
    Brig::BRIG_GEOMETRY_1D
};

unsigned InstValidator::GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA[] = {
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_1DB,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D
};

unsigned InstValidator::GEOM_VALUES_1D_2D_3D_1DA_2DA[] = {
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D
};

unsigned InstValidator::GEOM_VALUES_1D_1DB[] = {
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DB
};

unsigned InstValidator::GEOM_VALUES_2D_1DA[] = {
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_2D
};

unsigned InstValidator::GEOM_VALUES_3D_2DA[] = {
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D
};

unsigned InstValidator::MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL[] = {
    Brig::BRIG_SEMANTIC_ACQUIRE,
    Brig::BRIG_SEMANTIC_ACQUIRE_RELEASE,
    Brig::BRIG_SEMANTIC_PARTIAL_ACQUIRE_RELEASE,
    Brig::BRIG_SEMANTIC_REGULAR
};

unsigned InstValidator::MSEM_VALUES_REG_ACQ_PARTACQ[] = {
    Brig::BRIG_SEMANTIC_ACQUIRE,
    Brig::BRIG_SEMANTIC_PARTIAL_ACQUIRE,
    Brig::BRIG_SEMANTIC_REGULAR
};

unsigned InstValidator::MSEM_VALUES_REG_REL_PARTREL[] = {
    Brig::BRIG_SEMANTIC_PARTIAL_RELEASE,
    Brig::BRIG_SEMANTIC_REGULAR,
    Brig::BRIG_SEMANTIC_RELEASE
};

unsigned InstValidator::OPERAND_VALUES_ADDRSEG[] = {
    OPERAND_VAL_ADDR_SEG
};

unsigned InstValidator::OPERAND_VALUES_ADDRTSEG[] = {
    OPERAND_VAL_ADDR_TSEG
};

unsigned InstValidator::OPERAND_VALUES_ARGLIST[] = {
    OPERAND_VAL_ARGLIST
};

unsigned InstValidator::OPERAND_VALUES_NULL_CALLTAB[] = {
    OPERAND_VAL_CALLTAB,
    OPERAND_VAL_NULL
};

unsigned InstValidator::OPERAND_VALUES_FBARRIER[] = {
    OPERAND_VAL_FBARRIER
};

unsigned InstValidator::OPERAND_VALUES_REG32_FBARRIER[] = {
    OPERAND_VAL_FBARRIER,
    OPERAND_VAL_REG_32
};

unsigned InstValidator::OPERAND_VALUES_FUNCMODEL[] = {
    OPERAND_VAL_FUNC
};

unsigned InstValidator::OPERAND_VALUES_LAB_FUNC[] = {
    OPERAND_VAL_FUNC,
    OPERAND_VAL_LAB
};

unsigned InstValidator::OPERAND_VALUES_REGMODEL_FUNCMODEL[] = {
    OPERAND_VAL_FUNC,
    OPERAND_VAL_REG
};

unsigned InstValidator::OPERAND_VALUES_IMM[] = {
    OPERAND_VAL_IMM
};

unsigned InstValidator::OPERAND_VALUES_REG_IMM[] = {
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG
};

unsigned InstValidator::OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP[] = {
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4
};

unsigned InstValidator::OPERAND_VALUES_REG1_IMM1[] = {
    OPERAND_VAL_IMM_1,
    OPERAND_VAL_REG_1
};

unsigned InstValidator::OPERAND_VALUES_IMM32[] = {
    OPERAND_VAL_IMM_32
};

unsigned InstValidator::OPERAND_VALUES_REG1_REG32_IMM32[] = {
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_1,
    OPERAND_VAL_REG_32
};

unsigned InstValidator::OPERAND_VALUES_REG32_IMM32[] = {
    OPERAND_VAL_IMM_32,
    OPERAND_VAL_REG_32
};

unsigned InstValidator::OPERAND_VALUES_REG64_IMM64[] = {
    OPERAND_VAL_IMM_64,
    OPERAND_VAL_REG_64
};

unsigned InstValidator::OPERAND_VALUES_NULL_JUMPTAB[] = {
    OPERAND_VAL_JUMPTAB,
    OPERAND_VAL_NULL
};

unsigned InstValidator::OPERAND_VALUES_LABMODEL[] = {
    OPERAND_VAL_LAB
};

unsigned InstValidator::OPERAND_VALUES_REGMODEL_LABMODEL[] = {
    OPERAND_VAL_LAB,
    OPERAND_VAL_REG
};

unsigned InstValidator::OPERAND_VALUES_NULL[] = {
    OPERAND_VAL_NULL
};

unsigned InstValidator::OPERAND_VALUES_REG[] = {
    OPERAND_VAL_REG
};

unsigned InstValidator::OPERAND_VALUES_REGEXP_REGVEXP[] = {
    OPERAND_VAL_REG,
    OPERAND_VAL_REG_V2,
    OPERAND_VAL_REG_V3,
    OPERAND_VAL_REG_V4
};

unsigned InstValidator::OPERAND_VALUES_REG1[] = {
    OPERAND_VAL_REG_1
};

unsigned InstValidator::OPERAND_VALUES_REG32[] = {
    OPERAND_VAL_REG_32
};

unsigned InstValidator::OPERAND_VALUES_REG64[] = {
    OPERAND_VAL_REG_64
};

unsigned InstValidator::OPERAND_VALUES_REGV2CTYPE[] = {
    OPERAND_VAL_REG_V2
};

unsigned InstValidator::OPERAND_VALUES_REGV3CTYPE[] = {
    OPERAND_VAL_REG_V3
};

unsigned InstValidator::OPERAND_VALUES_REGV4[] = {
    OPERAND_VAL_REG_V4
};

unsigned InstValidator::OPERAND_VALUES_REGV432[] = {
    OPERAND_VAL_REG_V4_32
};

unsigned InstValidator::OPERATOR_VALUES_0[] = {
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

unsigned InstValidator::OPERATOR_VALUES_EQ_NE_LT_LE_GT_GE[] = {
    Brig::BRIG_COMPARE_EQ,
    Brig::BRIG_COMPARE_GE,
    Brig::BRIG_COMPARE_GT,
    Brig::BRIG_COMPARE_LE,
    Brig::BRIG_COMPARE_LT,
    Brig::BRIG_COMPARE_NE
};

unsigned InstValidator::OPERATOR_VALUES_EQ_NE[] = {
    Brig::BRIG_COMPARE_EQ,
    Brig::BRIG_COMPARE_NE
};

unsigned InstValidator::PACKING_VALUES_NONE[] = {
    Brig::BRIG_PACK_NONE
};

unsigned InstValidator::PACKING_VALUES_P_S[] = {
    Brig::BRIG_PACK_P,
    Brig::BRIG_PACK_S
};

unsigned InstValidator::PACKING_VALUES_PP[] = {
    Brig::BRIG_PACK_PP
};

unsigned InstValidator::PACKING_VALUES_BIN[] = {
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PPSAT,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_PSSAT,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SPSAT,
    Brig::BRIG_PACK_SS,
    Brig::BRIG_PACK_SSSAT
};

unsigned InstValidator::PACKING_VALUES_BINNOSAT[] = {
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SS
};

unsigned InstValidator::ROUNDING_VALUES_FLOAT[] = {
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO
};

unsigned InstValidator::ROUNDING_VALUES_INT[] = {
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN_SAT,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_ZERO,
    Brig::BRIG_ROUND_INTEGER_ZERO_SAT
};

unsigned InstValidator::ROUNDING_VALUES_NONE[] = {
    Brig::BRIG_ROUND_NONE
};

unsigned InstValidator::SEGMENT_VALUES_GCN[] = {
    Brig::BRIG_SEGMENT_EXTSPACE0
};

unsigned InstValidator::SEGMENT_VALUES_ANY[] = {
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL
};

unsigned InstValidator::SEGMENT_VALUES_WRITABLE[] = {
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_SPILL
};

unsigned InstValidator::SEGMENT_VALUES_STD[] = {
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL
};

unsigned InstValidator::SEGMENT_VALUES_GLOBAL_GROUP_FLAT[] = {
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP
};

unsigned InstValidator::SEGMENT_VALUES_GLOBAL[] = {
    Brig::BRIG_SEGMENT_GLOBAL
};

unsigned InstValidator::SEGMENT_VALUES_PRIVATE[] = {
    Brig::BRIG_SEGMENT_PRIVATE
};

unsigned InstValidator::STYPESIZE_VALUES_MODEL[] = {
    STYPESIZE_VAL_MODEL
};

unsigned InstValidator::STYPESIZE_VALUES_SEG[] = {
    STYPESIZE_VAL_SEG
};

unsigned InstValidator::SYNC_VALUES_BOTH_GLOBAL_GROUP_NONE_PARTIAL_PARTIALBOTH[] = {
    Brig::BRIG_FENCE_BOTH,
    Brig::BRIG_FENCE_GLOBAL,
    Brig::BRIG_FENCE_GROUP,
    Brig::BRIG_FENCE_NONE,
    Brig::BRIG_FENCE_PARTIAL,
    Brig::BRIG_FENCE_PARTIAL_BOTH
};

unsigned InstValidator::SYNC_VALUES_NONE[] = {
    Brig::BRIG_FENCE_NONE
};

unsigned InstValidator::TYPE_VALUES_B1[] = {
    Brig::BRIG_TYPE_B1
};

unsigned InstValidator::TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_ROIMG_RWIMG_SAMP[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_B32_B64[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64
};

unsigned InstValidator::TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_X[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_UX[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
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

unsigned InstValidator::TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_B32_B64_X[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_S_U_F[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_S_U[] = {
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

unsigned InstValidator::TYPE_VALUES_B128[] = {
    Brig::BRIG_TYPE_B128
};

unsigned InstValidator::TYPE_VALUES_B64_B128[] = {
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_B64
};

unsigned InstValidator::TYPE_VALUES_U_S_F_B128_ROIMG_RWIMG_SAMP[] = {
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

unsigned InstValidator::TYPE_VALUES_U_S_F_B128[] = {
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

unsigned InstValidator::TYPE_VALUES_B128_ROIMG_RWIMG_SAMP[] = {
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_SAMP
};

unsigned InstValidator::TYPE_VALUES_B32[] = {
    Brig::BRIG_TYPE_B32
};

unsigned InstValidator::TYPE_VALUES_B32_B64[] = {
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64
};

unsigned InstValidator::TYPE_VALUES_B32_S32_U32_B64_S64_U64[] = {
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned InstValidator::TYPE_VALUES_B64[] = {
    Brig::BRIG_TYPE_B64
};

unsigned InstValidator::TYPE_VALUES_F16[] = {
    Brig::BRIG_TYPE_F16
};

unsigned InstValidator::TYPE_VALUES_F_FX[] = {
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

unsigned InstValidator::TYPE_VALUES_S32_S64_SX_F_FX[] = {
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

unsigned InstValidator::TYPE_VALUES_S32_U32_S64_U64_F_X[] = {
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

unsigned InstValidator::TYPE_VALUES_S32_U32_S64_U64_F_FX[] = {
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

unsigned InstValidator::TYPE_VALUES_F16_F32[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32
};

unsigned InstValidator::TYPE_VALUES_F[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64
};

unsigned InstValidator::TYPE_VALUES_U_S_F[] = {
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

unsigned InstValidator::TYPE_VALUES_S32_S64_F[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64
};

unsigned InstValidator::TYPE_VALUES_S32_U32_S64_U64_F[] = {
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned InstValidator::TYPE_VALUES_F16X[] = {
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8
};

unsigned InstValidator::TYPE_VALUES_FX[] = {
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_F64X2
};

unsigned InstValidator::TYPE_VALUES_SX_FX[] = {
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

unsigned InstValidator::TYPE_VALUES_X[] = {
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

unsigned InstValidator::TYPE_VALUES_X32_X64[] = {
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

unsigned InstValidator::TYPE_VALUES_S16X2_U16X2_F16X2[] = {
    Brig::BRIG_TYPE_F16X2,
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_U16X2
};

unsigned InstValidator::TYPE_VALUES_S16X4_U16X4_F16X4[] = {
    Brig::BRIG_TYPE_F16X4,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_U16X4
};

unsigned InstValidator::TYPE_VALUES_S16X8_U16X8_F16X8[] = {
    Brig::BRIG_TYPE_F16X8,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_U16X8
};

unsigned InstValidator::TYPE_VALUES_F32[] = {
    Brig::BRIG_TYPE_F32
};

unsigned InstValidator::TYPE_VALUES_F32_F64[] = {
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64
};

unsigned InstValidator::TYPE_VALUES_S32_U32_F32[] = {
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32
};

unsigned InstValidator::TYPE_VALUES_U32_F32[] = {
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_U32
};

unsigned InstValidator::TYPE_VALUES_F32X[] = {
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_F32X4
};

unsigned InstValidator::TYPE_VALUES_S32X2_U32X2_F32X2[] = {
    Brig::BRIG_TYPE_F32X2,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_U32X2
};

unsigned InstValidator::TYPE_VALUES_S32X4_U32X4_F32X4[] = {
    Brig::BRIG_TYPE_F32X4,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_U32X4
};

unsigned InstValidator::TYPE_VALUES_F64[] = {
    Brig::BRIG_TYPE_F64
};

unsigned InstValidator::TYPE_VALUES_F64X[] = {
    Brig::BRIG_TYPE_F64X2
};

unsigned InstValidator::TYPE_VALUES_S64X2_U64X2_F64X2[] = {
    Brig::BRIG_TYPE_F64X2,
    Brig::BRIG_TYPE_S64X2,
    Brig::BRIG_TYPE_U64X2
};

unsigned InstValidator::TYPE_VALUES_NONE[] = {
    Brig::BRIG_TYPE_NONE
};

unsigned InstValidator::TYPE_VALUES_ROIMG_RWIMG[] = {
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG
};

unsigned InstValidator::TYPE_VALUES_RWIMG[] = {
    Brig::BRIG_TYPE_RWIMG
};

unsigned InstValidator::TYPE_VALUES_S_U[] = {
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8
};

unsigned InstValidator::TYPE_VALUES_S32_U32_S64_U64_SX_UX[] = {
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

unsigned InstValidator::TYPE_VALUES_S8X_S16X_S32X_S64X[] = {
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

unsigned InstValidator::TYPE_VALUES_SX_UX[] = {
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

unsigned InstValidator::TYPE_VALUES_S8X_S16X_S32X[] = {
    Brig::BRIG_TYPE_S16X2,
    Brig::BRIG_TYPE_S16X4,
    Brig::BRIG_TYPE_S16X8,
    Brig::BRIG_TYPE_S32X2,
    Brig::BRIG_TYPE_S32X4,
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_S8X8
};

unsigned InstValidator::TYPE_VALUES_S32[] = {
    Brig::BRIG_TYPE_S32
};

unsigned InstValidator::TYPE_VALUES_S32_U32_S64_U64[] = {
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned InstValidator::TYPE_VALUES_S32_U32[] = {
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32
};

unsigned InstValidator::TYPE_VALUES_S64[] = {
    Brig::BRIG_TYPE_S64
};

unsigned InstValidator::TYPE_VALUES_S8X16_U8X16[] = {
    Brig::BRIG_TYPE_S8X16,
    Brig::BRIG_TYPE_U8X16
};

unsigned InstValidator::TYPE_VALUES_S8X4_U8X4[] = {
    Brig::BRIG_TYPE_S8X4,
    Brig::BRIG_TYPE_U8X4
};

unsigned InstValidator::TYPE_VALUES_S8X8_U8X8[] = {
    Brig::BRIG_TYPE_S8X8,
    Brig::BRIG_TYPE_U8X8
};

unsigned InstValidator::TYPE_VALUES_SAMP[] = {
    Brig::BRIG_TYPE_SAMP
};

unsigned InstValidator::TYPE_VALUES_U16X2[] = {
    Brig::BRIG_TYPE_U16X2
};

unsigned InstValidator::TYPE_VALUES_U8X_U16X_U32X_U64X[] = {
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

unsigned InstValidator::TYPE_VALUES_U8X_U16X_U32X[] = {
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U16X4,
    Brig::BRIG_TYPE_U16X8,
    Brig::BRIG_TYPE_U32X2,
    Brig::BRIG_TYPE_U32X4,
    Brig::BRIG_TYPE_U8X16,
    Brig::BRIG_TYPE_U8X4,
    Brig::BRIG_TYPE_U8X8
};

unsigned InstValidator::TYPE_VALUES_U32_U8X4_U16X2[] = {
    Brig::BRIG_TYPE_U16X2,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U8X4
};

unsigned InstValidator::TYPE_VALUES_U16X4[] = {
    Brig::BRIG_TYPE_U16X4
};

unsigned InstValidator::TYPE_VALUES_U16X8[] = {
    Brig::BRIG_TYPE_U16X8
};

unsigned InstValidator::TYPE_VALUES_U32[] = {
    Brig::BRIG_TYPE_U32
};

unsigned InstValidator::TYPE_VALUES_U32_U64[] = {
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
};

unsigned InstValidator::TYPE_VALUES_U32X2[] = {
    Brig::BRIG_TYPE_U32X2
};

unsigned InstValidator::TYPE_VALUES_U32X4[] = {
    Brig::BRIG_TYPE_U32X4
};

unsigned InstValidator::TYPE_VALUES_U64[] = {
    Brig::BRIG_TYPE_U64
};

unsigned InstValidator::TYPE_VALUES_U64X2[] = {
    Brig::BRIG_TYPE_U64X2
};

unsigned InstValidator::TYPE_VALUES_U8X16[] = {
    Brig::BRIG_TYPE_U8X16
};

unsigned InstValidator::TYPE_VALUES_U8X4[] = {
    Brig::BRIG_TYPE_U8X4
};

unsigned InstValidator::TYPE_VALUES_U8X8[] = {
    Brig::BRIG_TYPE_U8X8
};

unsigned InstValidator::TYPESIZE_VALUES_MODEL[] = {
    TYPESIZE_VAL_MODEL
};

unsigned InstValidator::TYPESIZE_VALUES_SEG[] = {
    TYPESIZE_VAL_SEG
};

unsigned InstValidator::WIDTH_VALUES_ANY[] = {
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

unsigned InstValidator::WIDTH_VALUES_ALL[] = {
    Brig::BRIG_WIDTH_ALL
};

unsigned InstValidator::WIDTH_VALUES_NONE[] = {
    Brig::BRIG_WIDTH_NONE
};

bool InstValidator::check_align_values_any(unsigned val)
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

bool InstValidator::check_atmop_values_add_and_cas_dec_exch_inc_max_min_or_sub_xor(unsigned val)
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

bool InstValidator::check_atmop_values_add_and_cas_dec_inc_max_min_or_sub_xor(unsigned val)
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

bool InstValidator::check_atmop_values_add_sub_min_max(unsigned val)
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

bool InstValidator::check_atmop_values_and_or_xor_exch(unsigned val)
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

bool InstValidator::check_atmop_values_and_or_xor(unsigned val)
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

bool InstValidator::check_atmop_values_cas(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ATOMIC_CAS:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_atmop_values_inc_dec(unsigned val)
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

bool InstValidator::check_ftz_values_none(unsigned val)
{
    switch(val)
    {    
    case 0:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_ftz_values_any(unsigned val)
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

bool InstValidator::check_geom_values_1d(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_GEOMETRY_1D:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_geom_values_1d_2d_3d_1db_1da_2da(unsigned val)
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

bool InstValidator::check_geom_values_1d_2d_3d_1da_2da(unsigned val)
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

bool InstValidator::check_geom_values_1d_1db(unsigned val)
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

bool InstValidator::check_geom_values_2d_1da(unsigned val)
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

bool InstValidator::check_geom_values_3d_2da(unsigned val)
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

bool InstValidator::check_msem_values_reg_acq_acqrel_partacqrel(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEMANTIC_ACQUIRE:
    case Brig::BRIG_SEMANTIC_ACQUIRE_RELEASE:
    case Brig::BRIG_SEMANTIC_PARTIAL_ACQUIRE_RELEASE:
    case Brig::BRIG_SEMANTIC_REGULAR:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_msem_values_reg_acq_partacq(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEMANTIC_ACQUIRE:
    case Brig::BRIG_SEMANTIC_PARTIAL_ACQUIRE:
    case Brig::BRIG_SEMANTIC_REGULAR:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_msem_values_reg_rel_partrel(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEMANTIC_PARTIAL_RELEASE:
    case Brig::BRIG_SEMANTIC_REGULAR:
    case Brig::BRIG_SEMANTIC_RELEASE:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_operator_values_0(unsigned val)
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

bool InstValidator::check_operator_values_eq_ne_lt_le_gt_ge(unsigned val)
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

bool InstValidator::check_operator_values_eq_ne(unsigned val)
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

bool InstValidator::check_packing_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_PACK_NONE:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_packing_values_p_s(unsigned val)
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

bool InstValidator::check_packing_values_pp(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_PACK_PP:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_packing_values_bin(unsigned val)
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

bool InstValidator::check_packing_values_binnosat(unsigned val)
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

bool InstValidator::check_rounding_values_float(unsigned val)
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

bool InstValidator::check_rounding_values_int(unsigned val)
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

bool InstValidator::check_rounding_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_ROUND_NONE:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_segment_values_gcn(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_EXTSPACE0:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_segment_values_any(unsigned val)
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

bool InstValidator::check_segment_values_writable(unsigned val)
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

bool InstValidator::check_segment_values_std(unsigned val)
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

bool InstValidator::check_segment_values_global_group_flat(unsigned val)
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

bool InstValidator::check_segment_values_global(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_GLOBAL:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_segment_values_private(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_SEGMENT_PRIVATE:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_sync_values_both_global_group_none_partial_partialboth(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_FENCE_BOTH:
    case Brig::BRIG_FENCE_GLOBAL:
    case Brig::BRIG_FENCE_GROUP:
    case Brig::BRIG_FENCE_NONE:
    case Brig::BRIG_FENCE_PARTIAL:
    case Brig::BRIG_FENCE_PARTIAL_BOTH:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_sync_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_FENCE_NONE:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_b1(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B1:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_roimg_rwimg_samp(unsigned val)
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

bool InstValidator::check_type_values_b1_b32_b64(unsigned val)
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

bool InstValidator::check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(unsigned val)
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

bool InstValidator::check_type_values_b1_b32_s32_u32_b64_s64_u64_f_ux(unsigned val)
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

bool InstValidator::check_type_values_b1_b32_s32_u32_b64_s64_u64_f(unsigned val)
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

bool InstValidator::check_type_values_b1_b32_b64_x(unsigned val)
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

bool InstValidator::check_type_values_b1_s_u_f(unsigned val)
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

bool InstValidator::check_type_values_b1_s_u(unsigned val)
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

bool InstValidator::check_type_values_b128(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B128:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_b64_b128(unsigned val)
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

bool InstValidator::check_type_values_u_s_f_b128_roimg_rwimg_samp(unsigned val)
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

bool InstValidator::check_type_values_u_s_f_b128(unsigned val)
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

bool InstValidator::check_type_values_b128_roimg_rwimg_samp(unsigned val)
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

bool InstValidator::check_type_values_b32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B32:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_b32_b64(unsigned val)
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

bool InstValidator::check_type_values_b32_s32_u32_b64_s64_u64(unsigned val)
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

bool InstValidator::check_type_values_b64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_B64:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_f16(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F16:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_f_fx(unsigned val)
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

bool InstValidator::check_type_values_s32_s64_sx_f_fx(unsigned val)
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

bool InstValidator::check_type_values_s32_u32_s64_u64_f_x(unsigned val)
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

bool InstValidator::check_type_values_s32_u32_s64_u64_f_fx(unsigned val)
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

bool InstValidator::check_type_values_f16_f32(unsigned val)
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

bool InstValidator::check_type_values_f(unsigned val)
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

bool InstValidator::check_type_values_u_s_f(unsigned val)
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

bool InstValidator::check_type_values_s32_s64_f(unsigned val)
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

bool InstValidator::check_type_values_s32_u32_s64_u64_f(unsigned val)
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

bool InstValidator::check_type_values_f16x(unsigned val)
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

bool InstValidator::check_type_values_fx(unsigned val)
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

bool InstValidator::check_type_values_sx_fx(unsigned val)
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

bool InstValidator::check_type_values_x(unsigned val)
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

bool InstValidator::check_type_values_x32_x64(unsigned val)
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

bool InstValidator::check_type_values_s16x2_u16x2_f16x2(unsigned val)
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

bool InstValidator::check_type_values_s16x4_u16x4_f16x4(unsigned val)
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

bool InstValidator::check_type_values_s16x8_u16x8_f16x8(unsigned val)
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

bool InstValidator::check_type_values_f32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F32:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_f32_f64(unsigned val)
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

bool InstValidator::check_type_values_s32_u32_f32(unsigned val)
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

bool InstValidator::check_type_values_u32_f32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_U32:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_f32x(unsigned val)
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

bool InstValidator::check_type_values_s32x2_u32x2_f32x2(unsigned val)
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

bool InstValidator::check_type_values_s32x4_u32x4_f32x4(unsigned val)
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

bool InstValidator::check_type_values_f64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F64:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_f64x(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_F64X2:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_s64x2_u64x2_f64x2(unsigned val)
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

bool InstValidator::check_type_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_NONE:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_roimg_rwimg(unsigned val)
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

bool InstValidator::check_type_values_rwimg(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_RWIMG:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_s_u(unsigned val)
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

bool InstValidator::check_type_values_s32_u32_s64_u64_sx_ux(unsigned val)
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

bool InstValidator::check_type_values_s8x_s16x_s32x_s64x(unsigned val)
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

bool InstValidator::check_type_values_sx_ux(unsigned val)
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

bool InstValidator::check_type_values_s8x_s16x_s32x(unsigned val)
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

bool InstValidator::check_type_values_s32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S32:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_s32_u32_s64_u64(unsigned val)
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

bool InstValidator::check_type_values_s32_u32(unsigned val)
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

bool InstValidator::check_type_values_s64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_S64:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_s8x16_u8x16(unsigned val)
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

bool InstValidator::check_type_values_s8x4_u8x4(unsigned val)
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

bool InstValidator::check_type_values_s8x8_u8x8(unsigned val)
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

bool InstValidator::check_type_values_samp(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_SAMP:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u16x2(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U16X2:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u8x_u16x_u32x_u64x(unsigned val)
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

bool InstValidator::check_type_values_u8x_u16x_u32x(unsigned val)
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

bool InstValidator::check_type_values_u32_u8x4_u16x2(unsigned val)
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

bool InstValidator::check_type_values_u16x4(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U16X4:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u16x8(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U16X8:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u32(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U32:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u32_u64(unsigned val)
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

bool InstValidator::check_type_values_u32x2(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U32X2:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u32x4(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U32X4:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u64(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U64:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u64x2(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U64X2:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u8x16(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U8X16:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u8x4(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U8X4:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_type_values_u8x8(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_TYPE_U8X8:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_width_values_any(unsigned val)
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

bool InstValidator::check_width_values_all(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_WIDTH_ALL:
        return true;
    default: 
        return false;
    }
}

bool InstValidator::check_width_values_none(unsigned val)
{
    switch(val)
    {    
    case Brig::BRIG_WIDTH_NONE:
        return true;
    default: 
        return false;
    }
}

//================================================================================
//  Req add = {
//      type = s32, u32, s64, u64, f, x;
//      {type = s32, u32, s64, u64; ? packing = none; rounding = none; ftz = none;}
//      {type = f; ? packing = none; rounding = float; ftz = any;}
//      {type = sx, ux; ? packing = bin; rounding = none; ftz = none;}
//      {type = fx; ? packing = bin_nosat; rounding = float; ftz = any;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_add(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F_X, sizeof(TYPE_VALUES_S32_U32_S64_U64_F_X) / sizeof(unsigned));
    }

    if (
            check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_rounding_values_none(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_rounding_values_float(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_packing_values_bin(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_BIN, sizeof(PACKING_VALUES_BIN) / sizeof(unsigned));
        }
        if (!check_rounding_values_none(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_BINNOSAT, sizeof(PACKING_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        if (!check_rounding_values_float(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req align = {
//      type = b32;
//      d0_s1_s2_s3;
//  }
template<class T> bool InstValidator::req_align(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    req_d0_s1_s2_s3(inst);
    return true;
}

//================================================================================
//  Req alloca = {
//      type = u32;
//      stype = none;
//      segment = private;
//      s0 = reg;
//      s1 = reg, imm;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_alloca(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_none(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_segment_values_private(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_PRIVATE, sizeof(SEGMENT_VALUES_PRIVATE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req and = {
//      type = b1, b32, b64;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_and(T inst)
{
    if (!check_type_values_b1_b32_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_B32_B64, sizeof(TYPE_VALUES_B1_B32_B64) / sizeof(unsigned));
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req atomic = {
//      type = b32, s32, u32, b64, s64, u64;
//      atmop = add, and, cas, dec, exch, inc, max, min, or, sub, xor;
//      segment = global, group, flat;
//      msem = reg, acq, acq_rel, part_acq_rel;
//      {atmop = cas; ? type = b32, b64; s3 = reg, imm;}
//      {atmop = and, or, xor, exch; ? type = b32, b64; s3 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; s3 = null;}
//      {atmop = inc, dec; ? type = u32, u64; s3 = null;}
//      ;
//      d0 = reg;
//      s1 = addr_seg;
//      s2 = reg, imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_atomic(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_atmop_values_add_and_cas_dec_exch_inc_max_min_or_sub_xor(getAtmop<T>(inst))) {
        brigPropError(inst, PROP_ATMOP, getAtmop<T>(inst), ATMOP_VALUES_ADD_AND_CAS_DEC_EXCH_INC_MAX_MIN_OR_SUB_XOR, sizeof(ATMOP_VALUES_ADD_AND_CAS_DEC_EXCH_INC_MAX_MIN_OR_SUB_XOR) / sizeof(unsigned));
    }
    if (!check_segment_values_global_group_flat(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL_GROUP_FLAT, sizeof(SEGMENT_VALUES_GLOBAL_GROUP_FLAT) / sizeof(unsigned));
    }
    if (!check_msem_values_reg_acq_acqrel_partacqrel(getMsem<T>(inst))) {
        brigPropError(inst, PROP_MSEM, getMsem<T>(inst), MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL, sizeof(MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL) / sizeof(unsigned));
    }

    if (
            check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATMOP);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req atomic_image = {
//      type = b32, s32, u32, b64, s64, u64;
//      itype = rwimg;
//      ctype = u32;
//      geom = 1d, 2d, 3d, 1db, 1da, 2da;
//      atmop = add, and, cas, dec, exch, inc, max, min, or, sub, xor;
//      {atmop = cas; ? type = b32, b64; s4 = reg, imm;}
//      {atmop = and, or, xor, exch; ? type = b32, b64; s4 = null;}
//      {atmop = inc, dec; ? type = u32, u64; s4 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; s4 = null;}
//      ;
//      d0 = reg;
//      s1 = reg_64;
//      s3 = reg, imm;
//      {geom = 1d, 1db; ? s2 = reg_ctype;}
//      {geom = 2d, 1da; ? s2 = reg_v2_ctype;}
//      {geom = 3d, 2da; ? s2 = reg_v3_ctype;}
//      ;
//  }
template<class T> bool InstValidator::req_atomic_image(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_type_values_rwimg(getItype<T>(inst))) {
        brigPropError(inst, PROP_ITYPE, getItype<T>(inst), TYPE_VALUES_RWIMG, sizeof(TYPE_VALUES_RWIMG) / sizeof(unsigned));
    }
    if (!check_type_values_u32(getCtype<T>(inst))) {
        brigPropError(inst, PROP_CTYPE, getCtype<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) {
        brigPropError(inst, PROP_GEOM, getGeom<T>(inst), GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA, sizeof(GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA) / sizeof(unsigned));
    }
    if (!check_atmop_values_add_and_cas_dec_exch_inc_max_min_or_sub_xor(getAtmop<T>(inst))) {
        brigPropError(inst, PROP_ATMOP, getAtmop<T>(inst), ATMOP_VALUES_ADD_AND_CAS_DEC_EXCH_INC_MAX_MIN_OR_SUB_XOR, sizeof(ATMOP_VALUES_ADD_AND_CAS_DEC_EXCH_INC_MAX_MIN_OR_SUB_XOR) / sizeof(unsigned));
    }

    if (
            check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S4, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATMOP);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));

    if (
            check_geom_values_1d_1db(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_geom_values_2d_1da(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned));
    }
    else if (
            check_geom_values_3d_2da(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_GEOM);
    }
    return true;
}

//================================================================================
//  Req atomic_noret = {
//      type = b32, s32, u32, b64, s64, u64;
//      atmop = add, and, cas, dec, inc, max, min, or, sub, xor;
//      segment = global, group, flat;
//      msem = reg, acq, acq_rel, part_acq_rel;
//      {atmop = cas; ? type = b32, b64; s2 = reg, imm;}
//      {atmop = and, or, xor; ? type = b32, b64; s2 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; s2 = null;}
//      {atmop = inc, dec; ? type = u32, u64; s2 = null;}
//      ;
//      s0 = addr_seg;
//      s1 = reg, imm;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_atomic_noret(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_atmop_values_add_and_cas_dec_inc_max_min_or_sub_xor(getAtmop<T>(inst))) {
        brigPropError(inst, PROP_ATMOP, getAtmop<T>(inst), ATMOP_VALUES_ADD_AND_CAS_DEC_INC_MAX_MIN_OR_SUB_XOR, sizeof(ATMOP_VALUES_ADD_AND_CAS_DEC_INC_MAX_MIN_OR_SUB_XOR) / sizeof(unsigned));
    }
    if (!check_segment_values_global_group_flat(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL_GROUP_FLAT, sizeof(SEGMENT_VALUES_GLOBAL_GROUP_FLAT) / sizeof(unsigned));
    }
    if (!check_msem_values_reg_acq_acqrel_partacqrel(getMsem<T>(inst))) {
        brigPropError(inst, PROP_MSEM, getMsem<T>(inst), MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL, sizeof(MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL) / sizeof(unsigned));
    }

    if (
            check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATMOP);
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req atomic_noret_image = {
//      type = b32, s32, u32, b64, s64, u64;
//      itype = rwimg;
//      ctype = u32;
//      geom = 1d, 2d, 3d, 1db, 1da, 2da;
//      atmop = add, and, cas, dec, inc, max, min, or, sub, xor;
//      {atmop = cas; ? type = b32, b64; s3 = reg, imm;}
//      {atmop = and, or, xor; ? type = b32, b64; s3 = null;}
//      {atmop = inc, dec; ? type = u32, u64; s3 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; s3 = null;}
//      ;
//      s0 = reg_64;
//      s2 = reg, imm;
//      s4 = null;
//      {geom = 1d, 1db; ? s1 = reg_ctype;}
//      {geom = 2d, 1da; ? s1 = reg_v2_ctype;}
//      {geom = 3d, 2da; ? s1 = reg_v3_ctype;}
//      ;
//  }
template<class T> bool InstValidator::req_atomic_noret_image(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_type_values_rwimg(getItype<T>(inst))) {
        brigPropError(inst, PROP_ITYPE, getItype<T>(inst), TYPE_VALUES_RWIMG, sizeof(TYPE_VALUES_RWIMG) / sizeof(unsigned));
    }
    if (!check_type_values_u32(getCtype<T>(inst))) {
        brigPropError(inst, PROP_CTYPE, getCtype<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) {
        brigPropError(inst, PROP_GEOM, getGeom<T>(inst), GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA, sizeof(GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA) / sizeof(unsigned));
    }
    if (!check_atmop_values_add_and_cas_dec_inc_max_min_or_sub_xor(getAtmop<T>(inst))) {
        brigPropError(inst, PROP_ATMOP, getAtmop<T>(inst), ATMOP_VALUES_ADD_AND_CAS_DEC_INC_MAX_MIN_OR_SUB_XOR, sizeof(ATMOP_VALUES_ADD_AND_CAS_DEC_INC_MAX_MIN_OR_SUB_XOR) / sizeof(unsigned));
    }

    if (
            check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATMOP);
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            check_geom_values_1d_1db(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_geom_values_2d_1da(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned));
    }
    else if (
            check_geom_values_3d_2da(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_GEOM);
    }
    return true;
}

//================================================================================
//  Req barrier = {
//      type = none;
//      sync = both, global, group, none, partial, partial_both;
//      width = any;
//      s0 = null;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_barrier(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_sync_values_both_global_group_none_partial_partialboth(getSync<T>(inst))) {
        brigPropError(inst, PROP_SYNC, getSync<T>(inst), SYNC_VALUES_BOTH_GLOBAL_GROUP_NONE_PARTIAL_PARTIALBOTH, sizeof(SYNC_VALUES_BOTH_GLOBAL_GROUP_NONE_PARTIAL_PARTIALBOTH) / sizeof(unsigned));
    }
    if (!check_width_values_any(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req bitextract = {
//      type = s32, u32, s64, u64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_32, imm_32;
//      s3 = reg_32, imm_32;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_bitextract(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req bitinsert = {
//      type = s32, u32, s64, u64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = reg_32, imm_32;
//      s4 = reg_32, imm_32;
//  }
template<class T> bool InstValidator::req_bitinsert(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req bitmask = {
//      type = b32, b64;
//      d0 = reg;
//      s1 = reg_32, imm_32;
//      s2 = reg_32, imm_32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_bitmask(T inst)
{
    if (!check_type_values_b32_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req bitrev = {
//      type = b32, b64;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_bitrev(T inst)
{
    if (!check_type_values_b32_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
    }
    req_d0_s1(inst);
    return true;
}

//================================================================================
//  Req bitselect = {
//      type = b32, b64;
//      d0_s1_s2_s3;
//  }
template<class T> bool InstValidator::req_bitselect(T inst)
{
    if (!check_type_values_b32_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
    }
    req_d0_s1_s2_s3(inst);
    return true;
}

//================================================================================
//  Req brn = {
//      type = none;
//      rounding = none;
//      ftz = none;
//      width = any;
//      s0 = reg_model, lab_model;
//      s1 = null, jumptab;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//      {s0 = reg_model; ? width = any; s1 = null, jumptab;}
//      {s0 = lab_model; ? width = all; s1 = null;}
//      ;
//  }
template<class T> bool InstValidator::req_brn(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_ftz_values_none(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_any(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_LABMODEL, sizeof(OPERAND_VALUES_REGMODEL_LABMODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
       )
    {
        if (!check_width_values_any(getWidth<T>(inst))) {
            brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned));
    }
    else if (
            validateOperand(inst, PROP_S0, OPERAND_ATTR_MODEL, OPERAND_VALUES_LABMODEL, sizeof(OPERAND_VALUES_LABMODEL) / sizeof(unsigned), false)
       )
    {
        if (!check_width_values_all(getWidth<T>(inst))) {
            brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ALL, sizeof(WIDTH_VALUES_ALL) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_S0);
    }
    return true;
}

//================================================================================
//  Req call = {
//      type = none;
//      rounding = none;
//      ftz = none;
//      width = any;
//      s0 = arglist;
//      s1 = reg_model, func_model;
//      s2 = arglist;
//      s3 = null, calltab;
//      s4 = null;
//      {s1 = reg_model; ? width = any; s3 = null, calltab;}
//      {s1 = func_model; ? width = all; s3 = null;}
//      ;
//  }
template<class T> bool InstValidator::req_call(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_ftz_values_none(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_any(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_FUNCMODEL, sizeof(OPERAND_VALUES_REGMODEL_FUNCMODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_CALLTAB, sizeof(OPERAND_VALUES_NULL_CALLTAB) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
       )
    {
        if (!check_width_values_any(getWidth<T>(inst))) {
            brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_CALLTAB, sizeof(OPERAND_VALUES_NULL_CALLTAB) / sizeof(unsigned));
    }
    else if (
            validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_FUNCMODEL, sizeof(OPERAND_VALUES_FUNCMODEL) / sizeof(unsigned), false)
       )
    {
        if (!check_width_values_all(getWidth<T>(inst))) {
            brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ALL, sizeof(WIDTH_VALUES_ALL) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_S1);
    }
    return true;
}

//================================================================================
//  Req cbr = {
//      type = none;
//      rounding = none;
//      ftz = none;
//      width = any;
//      s0 = reg_1;
//      s1 = reg_model, lab_model;
//      s2 = null, jumptab;
//      s3 = null;
//      s4 = null;
//      {s1 = reg_model; ? s2 = null, jumptab;}
//      {s1 = lab_model; ? s2 = null;}
//      ;
//  }
template<class T> bool InstValidator::req_cbr(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_ftz_values_none(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_any(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG1, sizeof(OPERAND_VALUES_REG1) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REGMODEL_LABMODEL, sizeof(OPERAND_VALUES_REGMODEL_LABMODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned), false)
       )
    {
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL_JUMPTAB, sizeof(OPERAND_VALUES_NULL_JUMPTAB) / sizeof(unsigned));
    }
    else if (
            validateOperand(inst, PROP_S1, OPERAND_ATTR_MODEL, OPERAND_VALUES_LABMODEL, sizeof(OPERAND_VALUES_LABMODEL) / sizeof(unsigned), false)
       )
    {
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_S1);
    }
    return true;
}

//================================================================================
//  Req ceil = {
//      type = f, fx;
//      rounding = none;
//      ftz = any;
//      {type = f; ? packing = none;}
//      {type = fx; ? packing = p, s;}
//      ;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_ceil(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F_FX, sizeof(TYPE_VALUES_F_FX) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_ftz_values_any(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }

    if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_p_s(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_P_S, sizeof(PACKING_VALUES_P_S) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1(inst);
    return true;
}

//================================================================================
//  Req class = {
//      type = b1;
//      stype = f;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = reg_32, imm_32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_class(T inst)
{
    if (!check_type_values_b1(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1, sizeof(TYPE_VALUES_B1) / sizeof(unsigned));
    }
    if (!check_type_values_f(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_F, sizeof(TYPE_VALUES_F) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req cmov = {
//      type = b1, b32, b64, x;
//      d0 = reg;
//      s2 = reg, imm;
//      s3 = reg, imm;
//      s4 = null;
//      {type = b1, b32, b64; ? s1 = reg_1, imm_1;}
//      {type = x; ? s1 = reg, imm;}
//      ;
//  }
template<class T> bool InstValidator::req_cmov(T inst)
{
    if (!check_type_values_b1_b32_b64_x(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_B32_B64_X, sizeof(TYPE_VALUES_B1_B32_B64_X) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            check_type_values_b1_b32_b64(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG1_IMM1, sizeof(OPERAND_VALUES_REG1_IMM1) / sizeof(unsigned));
    }
    else if (
            check_type_values_x(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    return true;
}

//================================================================================
//  Req cmp = {
//      type = b1, b32, s32, u32, b64, s64, u64, f, ux;
//      stype = b1, b32, s32, u32, b64, s64, u64, f, x;
//      rounding = none;
//      {stype = b1, b32, s32, u32, b64, s64, u64, f; ? type = b1, b32, s32, u32, b64, s64, u64, f;}
//      {stype = s8x4, u8x4; ? type = u8x4;}
//      {stype = s8x8, u8x8; ? type = u8x8;}
//      {stype = s8x16, u8x16; ? type = u8x16;}
//      {stype = s16x2, u16x2, f16x2; ? type = u16x2;}
//      {stype = s16x4, u16x4, f16x4; ? type = u16x4;}
//      {stype = s16x8, u16x8, f16x8; ? type = u16x8;}
//      {stype = s32x2, u32x2, f32x2; ? type = u32x2;}
//      {stype = s32x4, u32x4, f32x4; ? type = u32x4;}
//      {stype = s64x2, u64x2, f64x2; ? type = u64x2;}
//      ;
//      {stype = b1, b32, b64; ? ftz = none; packing = none; operator = eq, ne;}
//      {stype = s32, u32, s64, u64; ? ftz = none; packing = none; operator = eq, ne, lt, le, gt, ge;}
//      {stype = f; ? ftz = any; packing = none; operator = eq, equ, ge, geu, gt, gtu, le, leu, lt, ltu, nan, ne, neu, num, seq, sequ, sge, sgeu, sgt, sgtu, sle, sleu, slt, sltu, snan, sne, sneu, snum;}
//      {stype = sx, ux; ? ftz = none; packing = pp; operator = eq, ne, lt, le, gt, ge;}
//      {stype = fx; ? ftz = any; packing = pp; operator = eq, equ, ge, geu, gt, gtu, le, leu, lt, ltu, nan, ne, neu, num, seq, sequ, sge, sgeu, sgt, sgtu, sle, sleu, slt, sltu, snan, sne, sneu, snum;}
//      ;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = reg_stype, imm_stype;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_cmp(T inst)
{
    if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f_ux(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_UX, sizeof(TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_UX) / sizeof(unsigned));
    }
    if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_X, sizeof(TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_X) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }

    if (
            check_type_values_b1_b32_s32_u32_b64_s64_u64_f(getStype<T>(inst))
       )
    {
        if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F, sizeof(TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s8x4_u8x4(getStype<T>(inst))
       )
    {
        if (!check_type_values_u8x4(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X4, sizeof(TYPE_VALUES_U8X4) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s8x8_u8x8(getStype<T>(inst))
       )
    {
        if (!check_type_values_u8x8(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X8, sizeof(TYPE_VALUES_U8X8) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s8x16_u8x16(getStype<T>(inst))
       )
    {
        if (!check_type_values_u8x16(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X16, sizeof(TYPE_VALUES_U8X16) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s16x2_u16x2_f16x2(getStype<T>(inst))
       )
    {
        if (!check_type_values_u16x2(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U16X2, sizeof(TYPE_VALUES_U16X2) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s16x4_u16x4_f16x4(getStype<T>(inst))
       )
    {
        if (!check_type_values_u16x4(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U16X4, sizeof(TYPE_VALUES_U16X4) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s16x8_u16x8_f16x8(getStype<T>(inst))
       )
    {
        if (!check_type_values_u16x8(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U16X8, sizeof(TYPE_VALUES_U16X8) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s32x2_u32x2_f32x2(getStype<T>(inst))
       )
    {
        if (!check_type_values_u32x2(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32X2, sizeof(TYPE_VALUES_U32X2) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s32x4_u32x4_f32x4(getStype<T>(inst))
       )
    {
        if (!check_type_values_u32x4(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32X4, sizeof(TYPE_VALUES_U32X4) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s64x2_u64x2_f64x2(getStype<T>(inst))
       )
    {
        if (!check_type_values_u64x2(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U64X2, sizeof(TYPE_VALUES_U64X2) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_STYPE);
    }

    if (
            check_type_values_b1_b32_b64(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_operator_values_eq_ne(getOperator<T>(inst))) {
            brigPropError(inst, PROP_OPERATOR, getOperator<T>(inst), OPERATOR_VALUES_EQ_NE, sizeof(OPERATOR_VALUES_EQ_NE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s32_u32_s64_u64(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_operator_values_eq_ne_lt_le_gt_ge(getOperator<T>(inst))) {
            brigPropError(inst, PROP_OPERATOR, getOperator<T>(inst), OPERATOR_VALUES_EQ_NE_LT_LE_GT_GE, sizeof(OPERATOR_VALUES_EQ_NE_LT_LE_GT_GE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_operator_values_0(getOperator<T>(inst))) {
            brigPropError(inst, PROP_OPERATOR, getOperator<T>(inst), OPERATOR_VALUES_0, sizeof(OPERATOR_VALUES_0) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_sx_ux(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_packing_values_pp(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_PP, sizeof(PACKING_VALUES_PP) / sizeof(unsigned));
        }
        if (!check_operator_values_eq_ne_lt_le_gt_ge(getOperator<T>(inst))) {
            brigPropError(inst, PROP_OPERATOR, getOperator<T>(inst), OPERATOR_VALUES_EQ_NE_LT_LE_GT_GE, sizeof(OPERATOR_VALUES_EQ_NE_LT_LE_GT_GE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getStype<T>(inst))
       )
    {
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
        if (!check_packing_values_pp(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_PP, sizeof(PACKING_VALUES_PP) / sizeof(unsigned));
        }
        if (!check_operator_values_0(getOperator<T>(inst))) {
            brigPropError(inst, PROP_OPERATOR, getOperator<T>(inst), OPERATOR_VALUES_0, sizeof(OPERATOR_VALUES_0) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_STYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req combine = {
//      type = b64, b128;
//      stype = b32, b64;
//      {type = b64; stype = b32; ? s1 = reg_v2_stype;}
//      {type = b128; stype = b64; ? s1 = reg_v2_stype;}
//      {type = b128; stype = b32; ? s1 = reg_v4_stype;}
//      ;
//      d0 = reg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_combine(T inst)
{
    if (!check_type_values_b64_b128(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B64_B128, sizeof(TYPE_VALUES_B64_B128) / sizeof(unsigned));
    }
    if (!check_type_values_b32_b64(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
    }

    if (
            check_type_values_b64(getType<T>(inst)) &&
            check_type_values_b32(getStype<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128(getType<T>(inst)) &&
            check_type_values_b64(getStype<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128(getType<T>(inst)) &&
            check_type_values_b32(getStype<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_STYPE, PROP_TYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req copysign = {
//      type = f, fx;
//      rounding = none;
//      ftz = none;
//      {type = f; ? packing = none;}
//      {type = fx; ? packing = bin_nosat;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_copysign(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F_FX, sizeof(TYPE_VALUES_F_FX) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_ftz_values_none(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }

    if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_BINNOSAT, sizeof(PACKING_VALUES_BINNOSAT) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req countlane = {
//      type = u32;
//      d0 = reg;
//      s1 = reg_1, reg_32, imm_32;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_countlane(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG1_REG32_IMM32, sizeof(OPERAND_VALUES_REG1_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req countuplane = {
//      type = u32;
//      d0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_countuplane(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req cvt = {
//      type = b1, s, u, f;
//      stype = b1, s, u, f;
//      {stype = b1, s, u; type = b1, s, u; ? rounding = none; ftz = none;}
//      {stype = b1; type = f; ? rounding = none; ftz = none;}
//      {stype = s, u; type = f; ? rounding = float; ftz = none;}
//      {stype = f; type = b1; ? rounding = none; ftz = any;}
//      {stype = f; type = s, u; ? rounding = int; ftz = any;}
//      {stype = f32; type = f16; ? rounding = float; ftz = any;}
//      {stype = f64; type = f16, f32; ? rounding = float; ftz = any;}
//      {stype = f; type = f; ? rounding = none; ftz = any;}
//      ;
//      d0 = reg_exp;
//      s1 = reg_sexp, imm_sexp;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_cvt(T inst)
{
    if (!check_type_values_b1_s_u_f(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_S_U_F, sizeof(TYPE_VALUES_B1_S_U_F) / sizeof(unsigned));
    }
    if (!check_type_values_b1_s_u_f(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_B1_S_U_F, sizeof(TYPE_VALUES_B1_S_U_F) / sizeof(unsigned));
    }

    if (
            check_type_values_b1_s_u(getStype<T>(inst)) &&
            check_type_values_b1_s_u(getType<T>(inst))
       )
    {
        if (!check_rounding_values_none(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_b1(getStype<T>(inst)) &&
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_rounding_values_none(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s_u(getStype<T>(inst)) &&
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_rounding_values_float(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f(getStype<T>(inst)) &&
            check_type_values_b1(getType<T>(inst))
       )
    {
        if (!check_rounding_values_none(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f(getStype<T>(inst)) &&
            check_type_values_s_u(getType<T>(inst))
       )
    {
        if (!check_rounding_values_int(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_INT, sizeof(ROUNDING_VALUES_INT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f32(getStype<T>(inst)) &&
            check_type_values_f16(getType<T>(inst))
       )
    {
        if (!check_rounding_values_float(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f64(getStype<T>(inst)) &&
            check_type_values_f16_f32(getType<T>(inst))
       )
    {
        if (!check_rounding_values_float(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f(getStype<T>(inst)) &&
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_rounding_values_none(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_STYPE, PROP_TYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_EXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_SEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req d0_s1 = {
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_d0_s1(T inst)
{
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req d0_s1_s2 = {
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_d0_s1_s2(T inst)
{
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req d0_s1_s2_s3 = {
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = reg, imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_d0_s1_s2_s3(T inst)
{
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req debugtrap = {
//      type = u32;
//      s0 = imm;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_debugtrap(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req dispatchptr = {
//      type = u32, u64;
//      stype = none;
//      segment = global;
//      typesize = seg;
//      s0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_dispatchptr(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_type_values_none(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_segment_values_global(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL, sizeof(SEGMENT_VALUES_GLOBAL) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req div = {
//      type = s32, u32, s64, u64, f, fx;
//      {type = s32, u32, s64, u64; ? packing = none; rounding = none; ftz = none;}
//      {type = f; ? packing = none; rounding = float; ftz = any;}
//      {type = fx; ? packing = bin_nosat; rounding = float; ftz = any;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_div(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F_FX, sizeof(TYPE_VALUES_S32_U32_S64_U64_F_FX) / sizeof(unsigned));
    }

    if (
            check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_rounding_values_none(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_rounding_values_float(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_BINNOSAT, sizeof(PACKING_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        if (!check_rounding_values_float(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req expand = {
//      type = b32, b64;
//      stype = b64, b128;
//      {type = b32; stype = b64; ? d0 = reg_v2;}
//      {type = b32; stype = b128; ? d0 = reg_v4;}
//      {type = b64; stype = b128; ? d0 = reg_v2;}
//      ;
//      s1 = reg_stype, imm_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_expand(T inst)
{
    if (!check_type_values_b32_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
    }
    if (!check_type_values_b64_b128(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_B64_B128, sizeof(TYPE_VALUES_B64_B128) / sizeof(unsigned));
    }

    if (
            check_type_values_b32(getType<T>(inst)) &&
            check_type_values_b64(getStype<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned));
    }
    else if (
            check_type_values_b32(getType<T>(inst)) &&
            check_type_values_b128(getStype<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned));
    }
    else if (
            check_type_values_b64(getType<T>(inst)) &&
            check_type_values_b128(getStype<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_STYPE, PROP_TYPE);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req f2s = {
//      type = u32, u64;
//      stype = u32, u64;
//      segment = std;
//      typesize = seg;
//      stypesize = model;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_f2s(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_type_values_u32_u64(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_std(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_STD, sizeof(SEGMENT_VALUES_STD) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned));
    validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_MODEL, sizeof(STYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req fbar_none = {
//      type = none;
//      sync = none;
//      width = none;
//      s0 = reg_32, fbarrier;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_fbar_none(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_sync_values_none(getSync<T>(inst))) {
        brigPropError(inst, PROP_SYNC, getSync<T>(inst), SYNC_VALUES_NONE, sizeof(SYNC_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_none(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_NONE, sizeof(WIDTH_VALUES_NONE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_FBARRIER, sizeof(OPERAND_VALUES_REG32_FBARRIER) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req fbar_sync_width = {
//      type = none;
//      sync = both, global, group, none, partial, partial_both;
//      width = any;
//      s0 = reg_32, fbarrier;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_fbar_sync_width(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_sync_values_both_global_group_none_partial_partialboth(getSync<T>(inst))) {
        brigPropError(inst, PROP_SYNC, getSync<T>(inst), SYNC_VALUES_BOTH_GLOBAL_GROUP_NONE_PARTIAL_PARTIALBOTH, sizeof(SYNC_VALUES_BOTH_GLOBAL_GROUP_NONE_PARTIAL_PARTIALBOTH) / sizeof(unsigned));
    }
    if (!check_width_values_any(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_FBARRIER, sizeof(OPERAND_VALUES_REG32_FBARRIER) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req fbar_width = {
//      type = none;
//      sync = none;
//      width = any;
//      s0 = reg_32, fbarrier;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_fbar_width(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_sync_values_none(getSync<T>(inst))) {
        brigPropError(inst, PROP_SYNC, getSync<T>(inst), SYNC_VALUES_NONE, sizeof(SYNC_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_any(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_FBARRIER, sizeof(OPERAND_VALUES_REG32_FBARRIER) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req firstbit = {
//      type = u32;
//      stype = s32, u32, s64, u64;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_firstbit(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_s32_u32_s64_u64(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req fma = {
//      type = f;
//      packing = none;
//      rounding = float;
//      ftz = any;
//      d0_s1_s2_s3;
//  }
template<class T> bool InstValidator::req_fma(T inst)
{
    if (!check_type_values_f(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F, sizeof(TYPE_VALUES_F) / sizeof(unsigned));
    }
    if (!check_packing_values_none(getPacking<T>(inst))) {
        brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_rounding_values_float(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
    }
    if (!check_ftz_values_any(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    req_d0_s1_s2_s3(inst);
    return true;
}

//================================================================================
//  Req fract = {
//      type = f, fx;
//      rounding = none;
//      ftz = any;
//      {type = f; ? packing = none;}
//      {type = fx; ? packing = p, s;}
//      ;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_fract(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F_FX, sizeof(TYPE_VALUES_F_FX) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_ftz_values_any(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }

    if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_p_s(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_P_S, sizeof(PACKING_VALUES_P_S) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1(inst);
    return true;
}

//================================================================================
//  Req gcn_append_consume = {
//      type = u32;
//      segment = gcn;
//      d0 = reg;
//      s1 = addr_seg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_append_consume(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_segment_values_gcn(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GCN, sizeof(SEGMENT_VALUES_GCN) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_atomic = {
//      type = b32, s32, u32, b64, s64, u64;
//      atmop = add, and, cas, dec, exch, inc, max, min, or, sub, xor;
//      segment = gcn;
//      msem = reg, acq, acq_rel, part_acq_rel;
//      {atmop = cas; ? type = b32, b64; s3 = reg, imm;}
//      {atmop = and, or, xor, exch; ? type = b32, b64; s3 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; s3 = null;}
//      {atmop = inc, dec; ? type = u32, u64; s3 = null;}
//      ;
//      d0 = reg;
//      s1 = addr_seg;
//      s2 = reg, imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_atomic(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_atmop_values_add_and_cas_dec_exch_inc_max_min_or_sub_xor(getAtmop<T>(inst))) {
        brigPropError(inst, PROP_ATMOP, getAtmop<T>(inst), ATMOP_VALUES_ADD_AND_CAS_DEC_EXCH_INC_MAX_MIN_OR_SUB_XOR, sizeof(ATMOP_VALUES_ADD_AND_CAS_DEC_EXCH_INC_MAX_MIN_OR_SUB_XOR) / sizeof(unsigned));
    }
    if (!check_segment_values_gcn(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GCN, sizeof(SEGMENT_VALUES_GCN) / sizeof(unsigned));
    }
    if (!check_msem_values_reg_acq_acqrel_partacqrel(getMsem<T>(inst))) {
        brigPropError(inst, PROP_MSEM, getMsem<T>(inst), MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL, sizeof(MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL) / sizeof(unsigned));
    }

    if (
            check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor_exch(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATMOP);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_atomic_noret = {
//      type = b32, s32, u32, b64, s64, u64;
//      atmop = add, and, cas, dec, inc, max, min, or, sub, xor;
//      segment = gcn;
//      msem = reg, acq, acq_rel, part_acq_rel;
//      {atmop = cas; ? type = b32, b64; s2 = reg, imm;}
//      {atmop = and, or, xor; ? type = b32, b64; s2 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; s2 = null;}
//      {atmop = inc, dec; ? type = u32, u64; s2 = null;}
//      ;
//      s0 = addr_seg;
//      s1 = reg, imm;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_atomic_noret(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_atmop_values_add_and_cas_dec_inc_max_min_or_sub_xor(getAtmop<T>(inst))) {
        brigPropError(inst, PROP_ATMOP, getAtmop<T>(inst), ATMOP_VALUES_ADD_AND_CAS_DEC_INC_MAX_MIN_OR_SUB_XOR, sizeof(ATMOP_VALUES_ADD_AND_CAS_DEC_INC_MAX_MIN_OR_SUB_XOR) / sizeof(unsigned));
    }
    if (!check_segment_values_gcn(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GCN, sizeof(SEGMENT_VALUES_GCN) / sizeof(unsigned));
    }
    if (!check_msem_values_reg_acq_acqrel_partacqrel(getMsem<T>(inst))) {
        brigPropError(inst, PROP_MSEM, getMsem<T>(inst), MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL, sizeof(MSEM_VALUES_REG_ACQ_ACQREL_PARTACQREL) / sizeof(unsigned));
    }

    if (
            check_atmop_values_cas(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_inc_dec(getAtmop<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATMOP);
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_b4xchg = {
//      type = b32;
//      d0 = reg;
//      s1 = reg;
//      s2 = imm_32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_b4xchg(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_bfm = {
//      type = b32;
//      d0 = reg_32;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_bfm(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32, sizeof(OPERAND_VALUES_REG32) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_fldexp = {
//      type = f32, f64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_32, imm_32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_fldexp(T inst)
{
    if (!check_type_values_f32_f64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F32_F64, sizeof(TYPE_VALUES_F32_F64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_frexp_exp = {
//      type = f32, f64;
//      d0 = reg_32;
//      s1 = reg, imm;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_frexp_exp(T inst)
{
    if (!check_type_values_f32_f64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F32_F64, sizeof(TYPE_VALUES_F32_F64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32, sizeof(OPERAND_VALUES_REG32) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_frexp_mant = {
//      type = f32, f64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_frexp_mant(T inst)
{
    if (!check_type_values_f32_f64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F32_F64, sizeof(TYPE_VALUES_F32_F64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_ld = {
//      type = u, s, f, b128;
//      segment = gcn;
//      msem = reg, acq, part_acq;
//      align = any;
//      width = any;
//      {type = u, s, f; ? d0 = reg_exp, reg_v_exp;}
//      {type = b128; ? d0 = reg;}
//      ;
//      s1 = addr_tseg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_ld(T inst)
{
    if (!check_type_values_u_s_f_b128(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U_S_F_B128, sizeof(TYPE_VALUES_U_S_F_B128) / sizeof(unsigned));
    }
    if (!check_segment_values_gcn(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GCN, sizeof(SEGMENT_VALUES_GCN) / sizeof(unsigned));
    }
    if (!check_msem_values_reg_acq_partacq(getMsem<T>(inst))) {
        brigPropError(inst, PROP_MSEM, getMsem<T>(inst), MSEM_VALUES_REG_ACQ_PARTACQ, sizeof(MSEM_VALUES_REG_ACQ_PARTACQ) / sizeof(unsigned));
    }
    if (!check_align_values_any(getAlign<T>(inst))) {
        brigPropError(inst, PROP_ALIGN, getAlign<T>(inst), ALIGN_VALUES_ANY, sizeof(ALIGN_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_width_values_any(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
    }

    if (
            check_type_values_u_s_f(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_mad = {
//      type = b32;
//      d0 = reg_64;
//      s1 = reg_32, imm_32;
//      s2 = reg_32, imm_32;
//      s3 = reg_64, imm_64;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_mad(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMM64, sizeof(OPERAND_VALUES_REG64_IMM64) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_min_max_med = {
//      type = s32, u32, f32;
//      d0 = reg_32;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = reg, imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_min_max_med(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_F32, sizeof(TYPE_VALUES_S32_U32_F32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32, sizeof(OPERAND_VALUES_REG32) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_mqsad = {
//      type = b64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_32, imm_32;
//      s3 = reg;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_mqsad(T inst)
{
    if (!check_type_values_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B64, sizeof(TYPE_VALUES_B64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_mqsad4 = {
//      type = b32;
//      d0 = reg_v4_32;
//      s1 = reg_64, imm_64;
//      s2 = reg, imm;
//      s3 = reg_v4_32;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_mqsad4(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NONE, OPERAND_VALUES_REGV432, sizeof(OPERAND_VALUES_REGV432) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64_IMM64, sizeof(OPERAND_VALUES_REG64_IMM64) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REGV432, sizeof(OPERAND_VALUES_REGV432) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_msad = {
//      type = b32;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = reg, imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_msad(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_qsad = {
//      type = b64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = reg, imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_qsad(T inst)
{
    if (!check_type_values_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B64, sizeof(TYPE_VALUES_B64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_region_alloc = {
//      type = b32;
//      s0 = imm_32;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_region_alloc(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_slp_prt = {
//      type = u32;
//      s0 = reg, imm;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_slp_prt(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_st = {
//      type = u, s, f, b128;
//      segment = gcn;
//      msem = reg, rel, part_rel;
//      align = any;
//      width = none;
//      s1 = addr_tseg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//      {type = u, s, f; ? s0 = reg_exp, reg_v_exp, imm_exp;}
//      {type = b128; ? s0 = reg;}
//      ;
//  }
template<class T> bool InstValidator::req_gcn_st(T inst)
{
    if (!check_type_values_u_s_f_b128(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U_S_F_B128, sizeof(TYPE_VALUES_U_S_F_B128) / sizeof(unsigned));
    }
    if (!check_segment_values_gcn(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GCN, sizeof(SEGMENT_VALUES_GCN) / sizeof(unsigned));
    }
    if (!check_msem_values_reg_rel_partrel(getMsem<T>(inst))) {
        brigPropError(inst, PROP_MSEM, getMsem<T>(inst), MSEM_VALUES_REG_REL_PARTREL, sizeof(MSEM_VALUES_REG_REL_PARTREL) / sizeof(unsigned));
    }
    if (!check_align_values_any(getAlign<T>(inst))) {
        brigPropError(inst, PROP_ALIGN, getAlign<T>(inst), ALIGN_VALUES_ANY, sizeof(ALIGN_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_width_values_none(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_NONE, sizeof(WIDTH_VALUES_NONE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            check_type_values_u_s_f(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    return true;
}

//================================================================================
//  Req gcn_trig_preop = {
//      type = f64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = imm_32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_trig_preop(T inst)
{
    if (!check_type_values_f64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F64, sizeof(TYPE_VALUES_F64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_IMM32, sizeof(OPERAND_VALUES_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ld = {
//      type = u, s, f, b128, roimg, rwimg, samp;
//      segment = any;
//      msem = reg, acq, part_acq;
//      align = any;
//      width = any;
//      {type = u, s, f; ? d0 = reg_exp, reg_v_exp;}
//      {type = b128, roimg, rwimg, samp; ? d0 = reg;}
//      ;
//      s1 = addr_tseg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ld(T inst)
{
    if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U_S_F_B128_ROIMG_RWIMG_SAMP, sizeof(TYPE_VALUES_U_S_F_B128_ROIMG_RWIMG_SAMP) / sizeof(unsigned));
    }
    if (!check_segment_values_any(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_ANY, sizeof(SEGMENT_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_msem_values_reg_acq_partacq(getMsem<T>(inst))) {
        brigPropError(inst, PROP_MSEM, getMsem<T>(inst), MSEM_VALUES_REG_ACQ_PARTACQ, sizeof(MSEM_VALUES_REG_ACQ_PARTACQ) / sizeof(unsigned));
    }
    if (!check_align_values_any(getAlign<T>(inst))) {
        brigPropError(inst, PROP_ALIGN, getAlign<T>(inst), ALIGN_VALUES_ANY, sizeof(ALIGN_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_width_values_any(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY, sizeof(WIDTH_VALUES_ANY) / sizeof(unsigned));
    }

    if (
            check_type_values_u_s_f(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128_roimg_rwimg_samp(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ld_image = {
//      ld_st_image;
//      itype = roimg, rwimg;
//      d0 = reg_v4;
//      s1 = reg_64;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ld_image(T inst)
{
    req_ld_st_image(inst);
    if (!check_type_values_roimg_rwimg(getItype<T>(inst))) {
        brigPropError(inst, PROP_ITYPE, getItype<T>(inst), TYPE_VALUES_ROIMG_RWIMG, sizeof(TYPE_VALUES_ROIMG_RWIMG) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ld_st_image = {
//      type = s32, u32, f32;
//      ctype = u32;
//      geom = 1d, 2d, 3d, 1db, 1da, 2da;
//      {geom = 1d, 1db; ? s2 = reg_ctype;}
//      {geom = 2d, 1da; ? s2 = reg_v2_ctype;}
//      {geom = 3d, 2da; ? s2 = reg_v3_ctype;}
//      ;
//  }
template<class T> bool InstValidator::req_ld_st_image(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_F32, sizeof(TYPE_VALUES_S32_U32_F32) / sizeof(unsigned));
    }
    if (!check_type_values_u32(getCtype<T>(inst))) {
        brigPropError(inst, PROP_CTYPE, getCtype<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_geom_values_1d_2d_3d_1db_1da_2da(getGeom<T>(inst))) {
        brigPropError(inst, PROP_GEOM, getGeom<T>(inst), GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA, sizeof(GEOM_VALUES_1D_2D_3D_1DB_1DA_2DA) / sizeof(unsigned));
    }

    if (
            check_geom_values_1d_1db(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_geom_values_2d_1da(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned));
    }
    else if (
            check_geom_values_3d_2da(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_GEOM);
    }
    return true;
}

//================================================================================
//  Req lda = {
//      type = u32, u64;
//      segment = any;
//      typesize = seg;
//      d0 = reg;
//      s1 = addr_seg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_lda(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_any(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_ANY, sizeof(SEGMENT_VALUES_ANY) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ldc = {
//      type = u32, u64;
//      typesize = model;
//      d0 = reg;
//      s1 = lab, func;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ldc(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_LAB_FUNC, sizeof(OPERAND_VALUES_LAB_FUNC) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ldf = {
//      type = u32;
//      s0 = reg;
//      s1 = fbarrier;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ldf(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_FBARRIER, sizeof(OPERAND_VALUES_FBARRIER) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req lerp = {
//      type = u8x4;
//      d0_s1_s2_s3;
//  }
template<class T> bool InstValidator::req_lerp(T inst)
{
    if (!check_type_values_u8x4(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X4, sizeof(TYPE_VALUES_U8X4) / sizeof(unsigned));
    }
    req_d0_s1_s2_s3(inst);
    return true;
}

//================================================================================
//  Req mad = {
//      type = s32, u32, s64, u64;
//      d0_s1_s2_s3;
//  }
template<class T> bool InstValidator::req_mad(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
    }
    req_d0_s1_s2_s3(inst);
    return true;
}

//================================================================================
//  Req mad24 = {
//      type = s32, u32;
//      d0_s1_s2_s3;
//  }
template<class T> bool InstValidator::req_mad24(T inst)
{
    if (!check_type_values_s32_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32, sizeof(TYPE_VALUES_S32_U32) / sizeof(unsigned));
    }
    req_d0_s1_s2_s3(inst);
    return true;
}

//================================================================================
//  Req masklane = {
//      type = b64;
//      d0 = reg;
//      s1 = reg_1, reg_32, imm_32;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_masklane(T inst)
{
    if (!check_type_values_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B64, sizeof(TYPE_VALUES_B64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG1_REG32_IMM32, sizeof(OPERAND_VALUES_REG1_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req max = {
//      type = s32, u32, s64, u64, f, x;
//      ftz = any;
//      rounding = none;
//      {type = s32, u32, s64, u64; ? packing = none; ftz = none;}
//      {type = f; ? packing = none; ftz = any;}
//      {type = sx, ux; ? packing = bin_nosat; ftz = none;}
//      {type = fx; ? packing = bin_nosat; ftz = any;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_max(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F_X, sizeof(TYPE_VALUES_S32_U32_S64_U64_F_X) / sizeof(unsigned));
    }
    if (!check_ftz_values_any(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }

    if (
            check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_BINNOSAT, sizeof(PACKING_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_BINNOSAT, sizeof(PACKING_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req mov = {
//      type = b1, b32, b64, b128, s32, u32, s64, u64, f, roimg, rwimg, samp;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_mov(T inst)
{
    if (!check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_roimg_rwimg_samp(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_ROIMG_RWIMG_SAMP, sizeof(TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_ROIMG_RWIMG_SAMP) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req mul = {
//      type = s32, u32, s64, u64, f, x;
//      ftz = any;
//      {type = s32, u32, s64, u64; ? packing = none; rounding = none; ftz = none;}
//      {type = f; ? packing = none; rounding = float; ftz = any;}
//      {type = sx, ux; ? packing = bin; rounding = none; ftz = none;}
//      {type = fx; ? packing = bin_nosat; rounding = float; ftz = any;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_mul(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F_X, sizeof(TYPE_VALUES_S32_U32_S64_U64_F_X) / sizeof(unsigned));
    }
    if (!check_ftz_values_any(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }

    if (
            check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_rounding_values_none(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_rounding_values_float(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_packing_values_bin(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_BIN, sizeof(PACKING_VALUES_BIN) / sizeof(unsigned));
        }
        if (!check_rounding_values_none(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_ftz_values_none(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_BINNOSAT, sizeof(PACKING_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        if (!check_rounding_values_float(getRounding<T>(inst))) {
            brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
        }
        if (!check_ftz_values_any(getFtz<T>(inst))) {
            brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req mul24 = {
//      type = s32, u32;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_mul24(T inst)
{
    if (!check_type_values_s32_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32, sizeof(TYPE_VALUES_S32_U32) / sizeof(unsigned));
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req mulhi = {
//      type = s32, u32, s64, u64, sx, ux;
//      rounding = none;
//      ftz = none;
//      {type = s32, u32, s64, u64; ? packing = none;}
//      {type = sx, ux; ? packing = bin_nosat;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_mulhi(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_sx_ux(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_SX_UX, sizeof(TYPE_VALUES_S32_U32_S64_U64_SX_UX) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_ftz_values_none(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }

    if (
            check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_packing_values_binnosat(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_BINNOSAT, sizeof(PACKING_VALUES_BINNOSAT) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req neg = {
//      type = s32, s64, sx, f, fx;
//      rounding = none;
//      ftz = none;
//      {type = s32, s64, f; ? packing = none;}
//      {type = sx, fx; ? packing = s, p;}
//      ;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_neg(T inst)
{
    if (!check_type_values_s32_s64_sx_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_S64_SX_F_FX, sizeof(TYPE_VALUES_S32_S64_SX_F_FX) / sizeof(unsigned));
    }
    if (!check_rounding_values_none(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_NONE, sizeof(ROUNDING_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_ftz_values_none(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }

    if (
            check_type_values_s32_s64_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_sx_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_p_s(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_P_S, sizeof(PACKING_VALUES_P_S) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1(inst);
    return true;
}

//================================================================================
//  Req nfma = {
//      type = f;
//      d0_s1_s2_s3;
//  }
template<class T> bool InstValidator::req_nfma(T inst)
{
    if (!check_type_values_f(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F, sizeof(TYPE_VALUES_F) / sizeof(unsigned));
    }
    req_d0_s1_s2_s3(inst);
    return true;
}

//================================================================================
//  Req nop = {
//      type = none;
//      s0 = null;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_nop(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req not = {
//      type = b1, b32, b64;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_not(T inst)
{
    if (!check_type_values_b1_b32_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_B32_B64, sizeof(TYPE_VALUES_B1_B32_B64) / sizeof(unsigned));
    }
    req_d0_s1(inst);
    return true;
}

//================================================================================
//  Req pack = {
//      type = x;
//      stype = s32, u32, s64, u64, f;
//      {stype = s32; ? type = s8x, s16x, s32x;}
//      {stype = s64; ? type = s8x, s16x, s32x, s64x;}
//      {stype = u32; ? type = u8x, u16x, u32x;}
//      {stype = u64; ? type = u8x, u16x, u32x, u64x;}
//      {stype = f16; ? type = f16x;}
//      {stype = f32; ? type = f32x;}
//      {stype = f64; ? type = f64x;}
//      ;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_stype, imm_stype;
//      s3 = reg_32, imm_32;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_pack(T inst)
{
    if (!check_type_values_x(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_X, sizeof(TYPE_VALUES_X) / sizeof(unsigned));
    }
    if (!check_type_values_s32_u32_s64_u64_f(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F, sizeof(TYPE_VALUES_S32_U32_S64_U64_F) / sizeof(unsigned));
    }

    if (
            check_type_values_s32(getStype<T>(inst))
       )
    {
        if (!check_type_values_s8x_s16x_s32x(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S8X_S16X_S32X, sizeof(TYPE_VALUES_S8X_S16X_S32X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s64(getStype<T>(inst))
       )
    {
        if (!check_type_values_s8x_s16x_s32x_s64x(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S8X_S16X_S32X_S64X, sizeof(TYPE_VALUES_S8X_S16X_S32X_S64X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_u32(getStype<T>(inst))
       )
    {
        if (!check_type_values_u8x_u16x_u32x(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X_U16X_U32X, sizeof(TYPE_VALUES_U8X_U16X_U32X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_u64(getStype<T>(inst))
       )
    {
        if (!check_type_values_u8x_u16x_u32x_u64x(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X_U16X_U32X_U64X, sizeof(TYPE_VALUES_U8X_U16X_U32X_U64X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f16(getStype<T>(inst))
       )
    {
        if (!check_type_values_f16x(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F16X, sizeof(TYPE_VALUES_F16X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f32(getStype<T>(inst))
       )
    {
        if (!check_type_values_f32x(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F32X, sizeof(TYPE_VALUES_F32X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f64(getStype<T>(inst))
       )
    {
        if (!check_type_values_f64x(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F64X, sizeof(TYPE_VALUES_F64X) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_STYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req packcvt = {
//      type = u8x4;
//      stype = f32;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = reg_stype, imm_stype;
//      s3 = reg_stype, imm_stype;
//      s4 = reg_stype, imm_stype;
//  }
template<class T> bool InstValidator::req_packcvt(T inst)
{
    if (!check_type_values_u8x4(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X4, sizeof(TYPE_VALUES_U8X4) / sizeof(unsigned));
    }
    if (!check_type_values_f32(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_F32, sizeof(TYPE_VALUES_F32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req popcount = {
//      type = u32;
//      stype = b32, b64;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_popcount(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_b32_b64(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ptr = {
//      type = u32, u64;
//      stype = none;
//      segment = any;
//      typesize = seg;
//      s0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ptr(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_type_values_none(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_segment_values_any(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_ANY, sizeof(SEGMENT_VALUES_ANY) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req queryimage = {
//      type = u32;
//      stype = roimg, rwimg;
//      d0 = reg;
//      s1 = reg_64;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_queryimage(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_roimg_rwimg(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_ROIMG_RWIMG, sizeof(TYPE_VALUES_ROIMG_RWIMG) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req querysampler = {
//      type = u32;
//      stype = samp;
//      d0 = reg;
//      s1 = reg_64;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_querysampler(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_samp(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_SAMP, sizeof(TYPE_VALUES_SAMP) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req rdimage = {
//      type = s32, u32, f32;
//      itype = roimg, rwimg;
//      ctype = u32, f32;
//      geom = 1d, 2d, 3d, 1da, 2da;
//      d0 = reg_v4;
//      s1 = reg_64;
//      s2 = reg_64;
//      s4 = null;
//      {geom = 1d; ? s3 = reg_ctype;}
//      {geom = 2d, 1da; ? s3 = reg_v2_ctype;}
//      {geom = 3d, 2da; ? s3 = reg_v3_ctype;}
//      ;
//  }
template<class T> bool InstValidator::req_rdimage(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_F32, sizeof(TYPE_VALUES_S32_U32_F32) / sizeof(unsigned));
    }
    if (!check_type_values_roimg_rwimg(getItype<T>(inst))) {
        brigPropError(inst, PROP_ITYPE, getItype<T>(inst), TYPE_VALUES_ROIMG_RWIMG, sizeof(TYPE_VALUES_ROIMG_RWIMG) / sizeof(unsigned));
    }
    if (!check_type_values_u32_f32(getCtype<T>(inst))) {
        brigPropError(inst, PROP_CTYPE, getCtype<T>(inst), TYPE_VALUES_U32_F32, sizeof(TYPE_VALUES_U32_F32) / sizeof(unsigned));
    }
    if (!check_geom_values_1d_2d_3d_1da_2da(getGeom<T>(inst))) {
        brigPropError(inst, PROP_GEOM, getGeom<T>(inst), GEOM_VALUES_1D_2D_3D_1DA_2DA, sizeof(GEOM_VALUES_1D_2D_3D_1DA_2DA) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            check_geom_values_1d(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_geom_values_2d_1da(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV2CTYPE, sizeof(OPERAND_VALUES_REGV2CTYPE) / sizeof(unsigned));
    }
    else if (
            check_geom_values_3d_2da(getGeom<T>(inst))
       )
    {
        validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REGV3CTYPE, sizeof(OPERAND_VALUES_REGV3CTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_GEOM);
    }
    return true;
}

//================================================================================
//  Req rem = {
//      type = s32, u32, s64, u64;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_rem(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req ret = {
//      type = none;
//      s0 = null;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ret(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req s2f = {
//      type = u32, u64;
//      stype = u32, u64;
//      segment = std;
//      typesize = model;
//      stypesize = seg;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_s2f(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_type_values_u32_u64(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_std(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_STD, sizeof(SEGMENT_VALUES_STD) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_SEG, sizeof(STYPESIZE_VALUES_SEG) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req sad = {
//      type = u32;
//      stype = u32, u8x4, u16x2;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = reg_stype, imm_stype;
//      s3 = reg_32, imm_32;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_sad(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_u32_u8x4_u16x2(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_U32_U8X4_U16X2, sizeof(TYPE_VALUES_U32_U8X4_U16X2) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req sadhi = {
//      type = u16x2;
//      stype = u8x4;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = reg_stype, imm_stype;
//      s3 = reg_32, imm_32;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_sadhi(T inst)
{
    if (!check_type_values_u16x2(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U16X2, sizeof(TYPE_VALUES_U16X2) / sizeof(unsigned));
    }
    if (!check_type_values_u8x4(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_U8X4, sizeof(TYPE_VALUES_U8X4) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req segmentp = {
//      type = b1;
//      stype = u32, u64;
//      segment = std;
//      stypesize = model;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_segmentp(T inst)
{
    if (!check_type_values_b1(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1, sizeof(TYPE_VALUES_B1) / sizeof(unsigned));
    }
    if (!check_type_values_u32_u64(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_std(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_STD, sizeof(SEGMENT_VALUES_STD) / sizeof(unsigned));
    }
    validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_MODEL, sizeof(STYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req sendlane = {
//      type = b32;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_sendlane(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req shift = {
//      type = s32, u32, s64, u64, sx, ux;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_32, imm_32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_shift(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_sx_ux(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_SX_UX, sizeof(TYPE_VALUES_S32_U32_S64_U64_SX_UX) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req shuffle = {
//      type = x_32, x_64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_shuffle(T inst)
{
    if (!check_type_values_x32_x64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_X32_X64, sizeof(TYPE_VALUES_X32_X64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req spec_clock = {
//      type = u64;
//      d0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_spec_clock(T inst)
{
    if (!check_type_values_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U64, sizeof(TYPE_VALUES_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req spec_except = {
//      type = u32;
//      s0 = imm;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_spec_except(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req spec_reg = {
//      type = u32;
//      d0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_spec_reg(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req spec_reg_dim = {
//      type = u32;
//      d0 = reg;
//      s1 = imm;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_spec_reg_dim(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req sqrt = {
//      type = f, fx;
//      rounding = float;
//      ftz = any;
//      {type = f; ? packing = none;}
//      {type = fx; ? packing = p, s;}
//      ;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_sqrt(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F_FX, sizeof(TYPE_VALUES_F_FX) / sizeof(unsigned));
    }
    if (!check_rounding_values_float(getRounding<T>(inst))) {
        brigPropError(inst, PROP_ROUNDING, getRounding<T>(inst), ROUNDING_VALUES_FLOAT, sizeof(ROUNDING_VALUES_FLOAT) / sizeof(unsigned));
    }
    if (!check_ftz_values_any(getFtz<T>(inst))) {
        brigPropError(inst, PROP_FTZ, getFtz<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }

    if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_packing_values_none(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_NONE, sizeof(PACKING_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_packing_values_p_s(getPacking<T>(inst))) {
            brigPropError(inst, PROP_PACKING, getPacking<T>(inst), PACKING_VALUES_P_S, sizeof(PACKING_VALUES_P_S) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1(inst);
    return true;
}

//================================================================================
//  Req st = {
//      type = u, s, f, b128, roimg, rwimg, samp;
//      segment = writable;
//      msem = reg, rel, part_rel;
//      align = any;
//      width = none;
//      s1 = addr_tseg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//      {type = u, s, f; ? s0 = reg_exp, reg_v_exp, imm_exp;}
//      {type = b128, roimg, rwimg, samp; ? s0 = reg;}
//      ;
//  }
template<class T> bool InstValidator::req_st(T inst)
{
    if (!check_type_values_u_s_f_b128_roimg_rwimg_samp(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U_S_F_B128_ROIMG_RWIMG_SAMP, sizeof(TYPE_VALUES_U_S_F_B128_ROIMG_RWIMG_SAMP) / sizeof(unsigned));
    }
    if (!check_segment_values_writable(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_WRITABLE, sizeof(SEGMENT_VALUES_WRITABLE) / sizeof(unsigned));
    }
    if (!check_msem_values_reg_rel_partrel(getMsem<T>(inst))) {
        brigPropError(inst, PROP_MSEM, getMsem<T>(inst), MSEM_VALUES_REG_REL_PARTREL, sizeof(MSEM_VALUES_REG_REL_PARTREL) / sizeof(unsigned));
    }
    if (!check_align_values_any(getAlign<T>(inst))) {
        brigPropError(inst, PROP_ALIGN, getAlign<T>(inst), ALIGN_VALUES_ANY, sizeof(ALIGN_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_width_values_none(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_NONE, sizeof(WIDTH_VALUES_NONE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_ADDRTSEG, sizeof(OPERAND_VALUES_ADDRTSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            check_type_values_u_s_f(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_EXP, OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP, sizeof(OPERAND_VALUES_REGEXP_REGVEXP_IMMEXP) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128_roimg_rwimg_samp(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    return true;
}

//================================================================================
//  Req st_image = {
//      ld_st_image;
//      itype = rwimg;
//      s0 = reg_v4;
//      s1 = reg_64;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_st_image(T inst)
{
    req_ld_st_image(inst);
    if (!check_type_values_rwimg(getItype<T>(inst))) {
        brigPropError(inst, PROP_ITYPE, getItype<T>(inst), TYPE_VALUES_RWIMG, sizeof(TYPE_VALUES_RWIMG) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REGV4, sizeof(OPERAND_VALUES_REGV4) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_REG64, sizeof(OPERAND_VALUES_REG64) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req sync = {
//      type = none;
//      sync = both, global, group, none, partial, partial_both;
//      width = none;
//      s0 = null;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_sync(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_sync_values_both_global_group_none_partial_partialboth(getSync<T>(inst))) {
        brigPropError(inst, PROP_SYNC, getSync<T>(inst), SYNC_VALUES_BOTH_GLOBAL_GROUP_NONE_PARTIAL_PARTIALBOTH, sizeof(SYNC_VALUES_BOTH_GLOBAL_GROUP_NONE_PARTIAL_PARTIALBOTH) / sizeof(unsigned));
    }
    if (!check_width_values_none(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_NONE, sizeof(WIDTH_VALUES_NONE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req syscall = {
//      type = u32, u64;
//      s0 = reg;
//      s1 = imm;
//      s2 = reg, imm;
//      s3 = reg, imm;
//      s4 = reg, imm;
//  }
template<class T> bool InstValidator::req_syscall(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req trig = {
//      type = f;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_trig(T inst)
{
    if (!check_type_values_f(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F, sizeof(TYPE_VALUES_F) / sizeof(unsigned));
    }
    req_d0_s1(inst);
    return true;
}

//================================================================================
//  Req trig32 = {
//      type = f32;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_trig32(T inst)
{
    if (!check_type_values_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F32, sizeof(TYPE_VALUES_F32) / sizeof(unsigned));
    }
    req_d0_s1(inst);
    return true;
}

//================================================================================
//  Req unpack = {
//      type = s32, u32, s64, u64, f;
//      stype = x;
//      {type = s32; ? stype = s8x, s16x, s32x;}
//      {type = s64; ? stype = s8x, s16x, s32x, s64x;}
//      {type = u32; ? stype = u8x, u16x, u32x;}
//      {type = u64; ? stype = u8x, u16x, u32x, u64x;}
//      {type = f16; ? stype = f16x;}
//      {type = f32; ? stype = f32x;}
//      {type = f64; ? stype = f64x;}
//      ;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = reg_32, imm_32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_unpack(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F, sizeof(TYPE_VALUES_S32_U32_S64_U64_F) / sizeof(unsigned));
    }
    if (!check_type_values_x(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_X, sizeof(TYPE_VALUES_X) / sizeof(unsigned));
    }

    if (
            check_type_values_s32(getType<T>(inst))
       )
    {
        if (!check_type_values_s8x_s16x_s32x(getStype<T>(inst))) {
            brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_S8X_S16X_S32X, sizeof(TYPE_VALUES_S8X_S16X_S32X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s64(getType<T>(inst))
       )
    {
        if (!check_type_values_s8x_s16x_s32x_s64x(getStype<T>(inst))) {
            brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_S8X_S16X_S32X_S64X, sizeof(TYPE_VALUES_S8X_S16X_S32X_S64X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_u32(getType<T>(inst))
       )
    {
        if (!check_type_values_u8x_u16x_u32x(getStype<T>(inst))) {
            brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_U8X_U16X_U32X, sizeof(TYPE_VALUES_U8X_U16X_U32X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_u64(getType<T>(inst))
       )
    {
        if (!check_type_values_u8x_u16x_u32x_u64x(getStype<T>(inst))) {
            brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_U8X_U16X_U32X_U64X, sizeof(TYPE_VALUES_U8X_U16X_U32X_U64X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f16(getType<T>(inst))
       )
    {
        if (!check_type_values_f16x(getStype<T>(inst))) {
            brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_F16X, sizeof(TYPE_VALUES_F16X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f32(getType<T>(inst))
       )
    {
        if (!check_type_values_f32x(getStype<T>(inst))) {
            brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_F32X, sizeof(TYPE_VALUES_F32X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f64(getType<T>(inst))
       )
    {
        if (!check_type_values_f64x(getStype<T>(inst))) {
            brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_F64X, sizeof(TYPE_VALUES_F64X) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_REG32_IMM32, sizeof(OPERAND_VALUES_REG32_IMM32) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req unpackcvt = {
//      type = f32;
//      stype = u8x4;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = imm;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_unpackcvt(T inst)
{
    if (!check_type_values_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F32, sizeof(TYPE_VALUES_F32) / sizeof(unsigned));
    }
    if (!check_type_values_u8x4(getStype<T>(inst))) {
        brigPropError(inst, PROP_STYPE, getStype<T>(inst), TYPE_VALUES_U8X4, sizeof(TYPE_VALUES_U8X4) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_NOEXP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REG_IMM, sizeof(OPERAND_VALUES_REG_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NOEXP, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req unpackx = {
//      type = x_32, x_64;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_unpackx(T inst)
{
    if (!check_type_values_x32_x64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_X32_X64, sizeof(TYPE_VALUES_X32_X64) / sizeof(unsigned));
    }
    req_d0_s1_s2(inst);
    return true;
}

void InstValidator::validateInst(Inst inst)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ABS):
        {
            if (InstMod i = inst)
            {
                req_neg<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_neg<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_ADD):
        {
            if (InstMod i = inst)
            {
                req_add<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_add<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_ALLOCA):
        {
            InstSeg i = inst;
            if (!i) { invalidFormat(inst, "InstSeg"); }
            req_alloca<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_AND):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_and<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ARRIVEFBAR):
        {
            InstFbar i = inst;
            if (!i) { invalidFormat(inst, "InstFbar"); }
            req_fbar_sync_width<InstFbar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { invalidFormat(inst, "InstAtomic"); }
            req_atomic<InstAtomic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMICIMAGE):
        {
            InstAtomicImage i = inst;
            if (!i) { invalidFormat(inst, "InstAtomicImage"); }
            req_atomic_image<InstAtomicImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMICIMAGENORET):
        {
            InstAtomicImage i = inst;
            if (!i) { invalidFormat(inst, "InstAtomicImage"); }
            req_atomic_noret_image<InstAtomicImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_ATOMICNORET):
        {
            InstAtomic i = inst;
            if (!i) { invalidFormat(inst, "InstAtomic"); }
            req_atomic_noret<InstAtomic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BARRIER):
        {
            InstBar i = inst;
            if (!i) { invalidFormat(inst, "InstBar"); }
            req_barrier<InstBar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITALIGN):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_align<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITEXTRACT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_bitextract<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITINSERT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_bitinsert<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITMASK):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_bitmask<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITREV):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_bitrev<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BITSELECT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_bitselect<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BORROW):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_rem<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BRN):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_brn<InstBr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_BYTEALIGN):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_align<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CALL):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_call<InstBr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CARRY):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_rem<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CBR):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_cbr<InstBr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CEIL):
        {
            if (InstMod i = inst)
            {
                req_ceil<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_ceil<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_CLASS):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_class<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CLEARDETECTEXCEPT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_except<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CLOCK):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_clock<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CMOV):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_cmov<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CMP):
        {
            InstCmp i = inst;
            if (!i) { invalidFormat(inst, "InstCmp"); }
            req_cmp<InstCmp>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_COMBINE):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_combine<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_COPYSIGN):
        {
            if (InstMod i = inst)
            {
                req_copysign<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_copysign<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_COUNTLANE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_countlane<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_COUNTUPLANE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_countuplane<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CUID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg_dim<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_CVT):
        {
            InstCvt i = inst;
            if (!i) { invalidFormat(inst, "InstCvt"); }
            req_cvt<InstCvt>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_DEBUGTRAP):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_debugtrap<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_DIM):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_DISPATCHID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_clock<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_DISPATCHPTR):
        {
            InstSeg i = inst;
            if (!i) { invalidFormat(inst, "InstSeg"); }
            req_dispatchptr<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_DIV):
        {
            if (InstMod i = inst)
            {
                req_div<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_div<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_EXPAND):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_expand<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_FIRSTBIT):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_firstbit<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_FLOOR):
        {
            if (InstMod i = inst)
            {
                req_ceil<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_ceil<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_FMA):
        {
            if (InstMod i = inst)
            {
                req_fma<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_fma<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_FRACT):
        {
            if (InstMod i = inst)
            {
                req_fract<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_fract<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_FTOS):
        {
            InstSeg i = inst;
            if (!i) { invalidFormat(inst, "InstSeg"); }
            req_f2s<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNAPPEND):
        {
            InstAddr i = inst;
            if (!i) { invalidFormat(inst, "InstAddr"); }
            req_gcn_append_consume<InstAddr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { invalidFormat(inst, "InstAtomic"); }
            req_gcn_atomic<InstAtomic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNATOMICNORET):
        {
            InstAtomic i = inst;
            if (!i) { invalidFormat(inst, "InstAtomic"); }
            req_gcn_atomic_noret<InstAtomic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNB32XCHG):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_b4xchg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNB4XCHG):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_b4xchg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNBFM):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_bfm<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNCONSUME):
        {
            InstAddr i = inst;
            if (!i) { invalidFormat(inst, "InstAddr"); }
            req_gcn_append_consume<InstAddr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNFLDEXP):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_fldexp<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNFREXP_EXP):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_frexp_exp<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNFREXP_MANT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_frexp_mant<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNLD):
        {
            InstMem i = inst;
            if (!i) { invalidFormat(inst, "InstMem"); }
            req_gcn_ld<InstMem>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMADS):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_mad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMADU):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_mad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMAX3):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_min_max_med<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMED3):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_min_max_med<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMIN3):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_min_max_med<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMQSAD):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_mqsad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMQSAD4):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_mqsad4<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNMSAD):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_msad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNPRIORITY):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_slp_prt<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNQSAD):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_qsad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNREGIONALLOC):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_region_alloc<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNSADD):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_msad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNSADW):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_msad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNSLEEP):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_slp_prt<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNST):
        {
            InstMem i = inst;
            if (!i) { invalidFormat(inst, "InstMem"); }
            req_gcn_st<InstMem>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GCNTRIG_PREOP):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_trig_preop<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GETDETECTEXCEPT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GRIDGROUPS):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg_dim<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_GRIDSIZE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg_dim<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_INITFBAR):
        {
            InstFbar i = inst;
            if (!i) { invalidFormat(inst, "InstFbar"); }
            req_fbar_none<InstFbar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_JOINFBAR):
        {
            InstFbar i = inst;
            if (!i) { invalidFormat(inst, "InstFbar"); }
            req_fbar_width<InstFbar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LANEID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LASTBIT):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_firstbit<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LD):
        {
            InstMem i = inst;
            if (!i) { invalidFormat(inst, "InstMem"); }
            req_ld<InstMem>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDA):
        {
            InstAddr i = inst;
            if (!i) { invalidFormat(inst, "InstAddr"); }
            req_lda<InstAddr>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDC):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_ldc<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDF):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_ldf<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LDIMAGE):
        {
            InstImage i = inst;
            if (!i) { invalidFormat(inst, "InstImage"); }
            req_ld_image<InstImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LEAVEFBAR):
        {
            InstFbar i = inst;
            if (!i) { invalidFormat(inst, "InstFbar"); }
            req_fbar_width<InstFbar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_LERP):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_lerp<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAD):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_mad<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAD24):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_mad24<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAD24HI):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_mad24<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MASKLANE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_masklane<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAX):
        {
            if (InstMod i = inst)
            {
                req_max<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_max<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_MAXCUID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MAXWAVEID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MIN):
        {
            if (InstMod i = inst)
            {
                req_max<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_max<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_MOV):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_mov<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MUL):
        {
            if (InstMod i = inst)
            {
                req_mul<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_mul<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_MUL24):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_mul24<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MUL24HI):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_mul24<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_MULHI):
        {
            if (InstMod i = inst)
            {
                req_mulhi<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_mulhi<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_NCOS):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_trig32<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NEG):
        {
            if (InstMod i = inst)
            {
                req_neg<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_neg<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_NEXP2):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_trig32<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NFMA):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_nfma<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NLOG2):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_trig32<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NOP):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_nop<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NOT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_not<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NRCP):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_trig<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NRSQRT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_trig<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NSIN):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_trig32<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NSQRT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_trig<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_NULLPTR):
        {
            InstSeg i = inst;
            if (!i) { invalidFormat(inst, "InstSeg"); }
            req_ptr<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_OR):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_and<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_PACK):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_pack<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_PACKCVT):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_packcvt<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_POPCOUNT):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_popcount<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QPTR):
        {
            InstSeg i = inst;
            if (!i) { invalidFormat(inst, "InstSeg"); }
            req_ptr<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYIMAGEARRAY):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_queryimage<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYIMAGEDEPTH):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_queryimage<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYIMAGEFORMAT):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_queryimage<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYIMAGEHEIGHT):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_queryimage<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYIMAGEORDER):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_queryimage<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYIMAGEWIDTH):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_queryimage<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYSAMPLERCOORD):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_querysampler<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_QUERYSAMPLERFILTER):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_querysampler<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_RDIMAGE):
        {
            InstImage i = inst;
            if (!i) { invalidFormat(inst, "InstImage"); }
            req_rdimage<InstImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_RECEIVELANE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_sendlane<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_RELEASEFBAR):
        {
            InstFbar i = inst;
            if (!i) { invalidFormat(inst, "InstFbar"); }
            req_fbar_none<InstFbar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_REM):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_rem<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_RET):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_ret<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_RINT):
        {
            if (InstMod i = inst)
            {
                req_ceil<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_ceil<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_SAD):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_sad<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SADHI):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_sadhi<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SEGMENTP):
        {
            InstSeg i = inst;
            if (!i) { invalidFormat(inst, "InstSeg"); }
            req_segmentp<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SENDLANE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_sendlane<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SETDETECTEXCEPT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_except<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SHL):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_shift<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SHR):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_shift<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SHUFFLE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_shuffle<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SQRT):
        {
            if (InstMod i = inst)
            {
                req_sqrt<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_sqrt<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_ST):
        {
            InstMem i = inst;
            if (!i) { invalidFormat(inst, "InstMem"); }
            req_st<InstMem>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_STIMAGE):
        {
            InstImage i = inst;
            if (!i) { invalidFormat(inst, "InstImage"); }
            req_st_image<InstImage>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_STOF):
        {
            InstSeg i = inst;
            if (!i) { invalidFormat(inst, "InstSeg"); }
            req_s2f<InstSeg>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SUB):
        {
            if (InstMod i = inst)
            {
                req_add<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_add<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_SYNC):
        {
            InstBar i = inst;
            if (!i) { invalidFormat(inst, "InstBar"); }
            req_sync<InstBar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_SYSCALL):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_syscall<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_TRUNC):
        {
            if (InstMod i = inst)
            {
                req_ceil<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                req_ceil<InstBasic>(i);
            }
            else
            {
                invalidFormat(inst, "InstBasic or InstMod");
            }
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACK):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_unpack<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACKCVT):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_unpackcvt<InstSourceType>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACKHI):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_unpackx<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_UNPACKLO):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_unpackx<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_WAITFBAR):
        {
            InstFbar i = inst;
            if (!i) { invalidFormat(inst, "InstFbar"); }
            req_fbar_sync_width<InstFbar>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_WAVEID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_WORKGROUPID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg_dim<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_WORKGROUPSIZE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg_dim<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_WORKITEMABSID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg_dim<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_WORKITEMFLATABSID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_WORKITEMFLATID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_WORKITEMID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_reg_dim<InstBasic>(i);
            break;
        } 
        case (Brig::BRIG_OPCODE_XOR):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_and<InstBasic>(i);
            break;
        } 
        default:
            validate(inst, false, "Invalid instruction opcode");
            break;
    }
} // InstValidator::validateInst 
} // namespace HSAIL_ASM 
