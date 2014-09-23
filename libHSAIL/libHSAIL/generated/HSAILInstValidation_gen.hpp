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

class InstValidator : public PropValidator
{
public:
    InstValidator(unsigned model, unsigned profile) : PropValidator(model, profile) {}
    void validateInst(Inst inst);

public:
    unsigned getOperand0Attr(Inst inst);

private:
    template<class T> unsigned operand0_to_attr_signal_noret(T inst);

public:
    unsigned getOperand1Attr(Inst inst);

private:
    template<class T> unsigned operand1_to_attr_cmov(T inst);
    template<class T> unsigned operand1_to_attr_signal(T inst);

public:
    unsigned getOperand2Attr(Inst inst);

private:
    template<class T> unsigned operand2_to_attr_atomic(T inst);
    template<class T> unsigned operand2_to_attr_atomic_noret(T inst);
    template<class T> unsigned operand2_to_attr_gcn_atomic(T inst);
    template<class T> unsigned operand2_to_attr_gcn_atomic_noret(T inst);
    template<class T> unsigned operand2_to_attr_signal(T inst);
    template<class T> unsigned operand2_to_attr_signal_noret(T inst);

public:
    unsigned getOperand3Attr(Inst inst);

private:
    template<class T> unsigned operand3_to_attr_atomic(T inst);
    template<class T> unsigned operand3_to_attr_gcn_atomic(T inst);
    template<class T> unsigned operand3_to_attr_signal(T inst);

public:
    unsigned getOperand4Attr(Inst inst);

private:

public:
    unsigned getRoundAttr(Inst inst);

private:
    template<class T> unsigned round_to_attr_add(T inst);
    template<class T> unsigned round_to_attr_cvt(T inst);
    template<class T> unsigned round_to_attr_div(T inst);
    template<class T> unsigned round_to_attr_mul(T inst);

public:
    unsigned getWidthAttr(Inst inst);

private:

private:
    static unsigned ALIGN_VALUES_ANY[];
    static unsigned ATMOP_VALUES_GENERIC_ATOMIC_EXCH_LD[];
    static unsigned ATMOP_VALUES_GENERIC_EXCH_LD_WAIT_WAITTIMEOUT[];
    static unsigned ATMOP_VALUES_GENERIC_ATOMIC_ST[];
    static unsigned ATMOP_VALUES_GENERIC_ST[];
    static unsigned ATMOP_VALUES_ADD_SUB_MIN_MAX[];
    static unsigned ATMOP_VALUES_ADD_SUB[];
    static unsigned ATMOP_VALUES_AND_OR_XOR_EXCH[];
    static unsigned ATMOP_VALUES_AND_OR_XOR[];
    static unsigned ATMOP_VALUES_CAS[];
    static unsigned ATMOP_VALUES_LD[];
    static unsigned ATMOP_VALUES_ST[];
    static unsigned ATMOP_VALUES_WAIT[];
    static unsigned ATMOP_VALUES_WAITTIMEOUT[];
    static unsigned ATMOP_VALUES_WRAPINC_WRAPDEC[];
    static unsigned COMPARE_VALUES_0[];
    static unsigned COMPARE_VALUES_EQ_NE_LT_LE_GT_GE[];
    static unsigned COMPARE_VALUES_EQ_NE[];
    static unsigned CONST_VALUES_NONE[];
    static unsigned CONST_VALUES_ANY[];
    static unsigned EQCLASS_VALUES_0[];
    static unsigned EQCLASS_VALUES_ANY[];
    static unsigned FTZ_VALUES_NONE[];
    static unsigned FTZ_VALUES_ANY[];
    static unsigned GEOMETRY_VALUES_1D[];
    static unsigned GEOMETRY_VALUES_ANY[];
    static unsigned GEOMETRY_VALUES_1D_2D_3D_1DA_2DA_2DDEPTH_2DADEPTH[];
    static unsigned GEOMETRY_VALUES_1D_1DB[];
    static unsigned GEOMETRY_VALUES_2D_1DA[];
    static unsigned GEOMETRY_VALUES_1DA_2DA_2DADEPTH[];
    static unsigned GEOMETRY_VALUES_2D_3D_2DA_2DDEPTH_2DADEPTH[];
    static unsigned GEOMETRY_VALUES_3D_2DA[];
    static unsigned GEOMETRY_VALUES_2DADEPTH[];
    static unsigned GEOMETRY_VALUES_2DDEPTH[];
    static unsigned GEOMETRY_VALUES_3D[];
    static unsigned IPROP_VALUES_ARRAY[];
    static unsigned IPROP_VALUES_ANY[];
    static unsigned IPROP_VALUES_WIDTH_CHANNELTYPE_CHANNELORDER[];
    static unsigned IPROP_VALUES_DEPTH[];
    static unsigned IPROP_VALUES_HEIGHT[];
    static unsigned MEMORD_VALUES_LD[];
    static unsigned MEMORD_VALUES_ANY[];
    static unsigned MEMORD_VALUES_ST[];
    static unsigned MEMORD_VALUES_ACQ_REL_AR[];
    static unsigned MEMORD_VALUES_AR[];
    static unsigned MEMSCP_VALUES_NONE_WV_WG_CMP_SYS[];
    static unsigned MEMSCP_VALUES_WV_WG_CMP_SYS[];
    static unsigned MEMSCP_VALUES_NONE[];
    static unsigned MEMSCP_VALUES_NONE_WV_WG[];
    static unsigned MEMSCP_VALUES_NONE_WI_WV_WG[];
    static unsigned MEMSCP_VALUES_WV_WG[];
    static unsigned MEMSCP_VALUES_WI_WV_WG[];
    static unsigned NONULL_VALUES_ANY[];
    static unsigned OPERAND_VALUES_ADDRSEG[];
    static unsigned OPERAND_VALUES_ARGLIST[];
    static unsigned OPERAND_VALUES_CALLTAB[];
    static unsigned OPERAND_VALUES_CNSTB32[];
    static unsigned OPERAND_VALUES_REGU32_CNSTU32[];
    static unsigned OPERAND_VALUES_FBARRIERU32[];
    static unsigned OPERAND_VALUES_REGU32_FBARRIERU32[];
    static unsigned OPERAND_VALUES_FUNC[];
    static unsigned OPERAND_VALUES_IFUNC[];
    static unsigned OPERAND_VALUES_IMM[];
    static unsigned OPERAND_VALUES_REGSTYPE_IMMSTYPE[];
    static unsigned OPERAND_VALUES_REG_VECTOR_IMM[];
    static unsigned OPERAND_VALUES_IMM0T2U32[];
    static unsigned OPERAND_VALUES_IMM0T3U32[];
    static unsigned OPERAND_VALUES_JUMPTAB[];
    static unsigned OPERAND_VALUES_KERNEL[];
    static unsigned OPERAND_VALUES_LAB[];
    static unsigned OPERAND_VALUES_NULL[];
    static unsigned OPERAND_VALUES_REG[];
    static unsigned OPERAND_VALUES_REG_VECTOR[];
    static unsigned OPERAND_VALUES_SIGNATURE[];
    static unsigned OPERAND_VALUES_VEC2STYPE[];
    static unsigned OPERAND_VALUES_VEC3CTYPE[];
    static unsigned OPERAND_VALUES_VEC4[];
    static unsigned PACK_VALUES_NONE[];
    static unsigned PACK_VALUES_P_S[];
    static unsigned PACK_VALUES_PP[];
    static unsigned PACK_VALUES_BIN[];
    static unsigned PACK_VALUES_BINNOSAT[];
    static unsigned ROUND_VALUES_FLOAT[];
    static unsigned ROUND_VALUES_INT[];
    static unsigned ROUND_VALUES_NONE[];
    static unsigned SEGMENT_VALUES_GCN[];
    static unsigned SEGMENT_VALUES_ARG[];
    static unsigned SEGMENT_VALUES_ANY[];
    static unsigned SEGMENT_VALUES_WRITABLE[];
    static unsigned SEGMENT_VALUES_GROUP_PRIVATE_READONLY_KERNARG_SPILL_ARG[];
    static unsigned SEGMENT_VALUES_FLAT_GLOBAL[];
    static unsigned SEGMENT_VALUES_GLOBAL_GROUP_FLAT[];
    static unsigned SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE_FLAT_KERNARG_READONLY[];
    static unsigned SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE[];
    static unsigned SEGMENT_VALUES_GROUP[];
    static unsigned SEGMENT_VALUES_PRIVATE[];
    static unsigned SPROP_VALUES_ANY[];
    static unsigned STYPESIZE_VALUES_MODEL[];
    static unsigned STYPESIZE_VALUES_SEG[];
    static unsigned TYPE_VALUES_B1[];
    static unsigned TYPE_VALUES_2[];
    static unsigned TYPE_VALUES_1[];
    static unsigned TYPE_VALUES_0[];
    static unsigned TYPE_VALUES_B1_B32_B64_B128[];
    static unsigned TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_OPAQUE[];
    static unsigned TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F[];
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
    static unsigned TYPE_VALUES_B128[];
    static unsigned TYPE_VALUES_B64_B128[];
    static unsigned TYPE_VALUES_U_S_F_B128_OPAQUE[];
    static unsigned TYPE_VALUES_U_S_F_B128[];
    static unsigned TYPE_VALUES_B128_OPAQUE[];
    static unsigned TYPE_VALUES_B128_SIG[];
    static unsigned TYPE_VALUES_B32[];
    static unsigned TYPE_VALUES_B32_B64[];
    static unsigned TYPE_VALUES_B32_S32_U32_B64_S64_U64[];
    static unsigned TYPE_VALUES_B32_S32_U32[];
    static unsigned TYPE_VALUES_B64[];
    static unsigned TYPE_VALUES_B64_S64_U64[];
    static unsigned TYPE_VALUES_F16[];
    static unsigned TYPE_VALUES_F_FX[];
    static unsigned TYPE_VALUES_S32_S64_SX_F_FX[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64_F_X[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64_F_FX[];
    static unsigned TYPE_VALUES_F16_F32[];
    static unsigned TYPE_VALUES_F[];
    static unsigned TYPE_VALUES_S_U_F[];
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
    static unsigned TYPE_VALUES_S32_U32_F32_F64[];
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
    static unsigned TYPE_VALUES_OPAQUE[];
    static unsigned TYPE_VALUES_IMG[];
    static unsigned TYPE_VALUES_ROIMG_RWIMG_WOIMG[];
    static unsigned TYPE_VALUES_WOIMG_RWIMG[];
    static unsigned TYPE_VALUES_S_U[];
    static unsigned TYPE_VALUES_S16_U16[];
    static unsigned TYPE_VALUES_S32_U32_S64_U64_SX_UX[];
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
    static unsigned TYPE_VALUES_SIG32[];
    static unsigned TYPE_VALUES_SIG32_SIG64[];
    static unsigned TYPE_VALUES_SIG64[];
    static unsigned TYPE_VALUES_U16X2[];
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
    static unsigned TYPESIZE_VALUES_ATOMIC[];
    static unsigned TYPESIZE_VALUES_MODEL[];
    static unsigned TYPESIZE_VALUES_SEG[];
    static unsigned TYPESIZE_VALUES_SIGNAL[];
    static unsigned WIDTH_VALUES_ANY1[];
    static unsigned WIDTH_VALUES_ALL[];
    static unsigned WIDTH_VALUES_NONE[];
    static unsigned WIDTH_VALUES_WAVESIZE[];

private:
    static bool check_align_values_any(unsigned val);
    static bool check_atmop_values_generic_atomic_exch_ld(unsigned val);
    static bool check_atmop_values_generic_exch_ld_wait_waittimeout(unsigned val);
    static bool check_atmop_values_generic_atomic_st(unsigned val);
    static bool check_atmop_values_generic_st(unsigned val);
    static bool check_atmop_values_add_sub_min_max(unsigned val);
    static bool check_atmop_values_add_sub(unsigned val);
    static bool check_atmop_values_and_or_xor_exch(unsigned val);
    static bool check_atmop_values_and_or_xor(unsigned val);
    static bool check_atmop_values_cas(unsigned val);
    static bool check_atmop_values_ld(unsigned val);
    static bool check_atmop_values_st(unsigned val);
    static bool check_atmop_values_wait(unsigned val);
    static bool check_atmop_values_waittimeout(unsigned val);
    static bool check_atmop_values_wrapinc_wrapdec(unsigned val);
    static bool check_compare_values_0(unsigned val);
    static bool check_compare_values_eq_ne_lt_le_gt_ge(unsigned val);
    static bool check_compare_values_eq_ne(unsigned val);
    static bool check_const_values_none(unsigned val);
    static bool check_const_values_any(unsigned val);
    static bool check_ftz_values_none(unsigned val);
    static bool check_ftz_values_any(unsigned val);
    static bool check_geometry_values_1d(unsigned val);
    static bool check_geometry_values_any(unsigned val);
    static bool check_geometry_values_1d_2d_3d_1da_2da_2ddepth_2dadepth(unsigned val);
    static bool check_geometry_values_1d_1db(unsigned val);
    static bool check_geometry_values_2d_1da(unsigned val);
    static bool check_geometry_values_1da_2da_2dadepth(unsigned val);
    static bool check_geometry_values_2d_3d_2da_2ddepth_2dadepth(unsigned val);
    static bool check_geometry_values_3d_2da(unsigned val);
    static bool check_geometry_values_2dadepth(unsigned val);
    static bool check_geometry_values_2ddepth(unsigned val);
    static bool check_geometry_values_3d(unsigned val);
    static bool check_iprop_values_array(unsigned val);
    static bool check_iprop_values_any(unsigned val);
    static bool check_iprop_values_width_channeltype_channelorder(unsigned val);
    static bool check_iprop_values_depth(unsigned val);
    static bool check_iprop_values_height(unsigned val);
    static bool check_memord_values_ld(unsigned val);
    static bool check_memord_values_any(unsigned val);
    static bool check_memord_values_st(unsigned val);
    static bool check_memord_values_acq_rel_ar(unsigned val);
    static bool check_memord_values_ar(unsigned val);
    static bool check_memscp_values_none_wv_wg_cmp_sys(unsigned val);
    static bool check_memscp_values_wv_wg_cmp_sys(unsigned val);
    static bool check_memscp_values_none(unsigned val);
    static bool check_memscp_values_none_wv_wg(unsigned val);
    static bool check_memscp_values_none_wi_wv_wg(unsigned val);
    static bool check_memscp_values_wv_wg(unsigned val);
    static bool check_memscp_values_wi_wv_wg(unsigned val);
    static bool check_nonull_values_any(unsigned val);
    static bool check_pack_values_none(unsigned val);
    static bool check_pack_values_p_s(unsigned val);
    static bool check_pack_values_pp(unsigned val);
    static bool check_pack_values_bin(unsigned val);
    static bool check_pack_values_binnosat(unsigned val);
    static bool check_round_values_float(unsigned val);
    static bool check_round_values_int(unsigned val);
    static bool check_round_values_none(unsigned val);
    static bool check_segment_values_gcn(unsigned val);
    static bool check_segment_values_arg(unsigned val);
    static bool check_segment_values_any(unsigned val);
    static bool check_segment_values_writable(unsigned val);
    static bool check_segment_values_group_private_readonly_kernarg_spill_arg(unsigned val);
    static bool check_segment_values_flat_global(unsigned val);
    static bool check_segment_values_global_group_flat(unsigned val);
    static bool check_segment_values_global_group_private_flat_kernarg_readonly(unsigned val);
    static bool check_segment_values_global_group_private(unsigned val);
    static bool check_segment_values_group(unsigned val);
    static bool check_segment_values_private(unsigned val);
    static bool check_sprop_values_any(unsigned val);
    static bool check_type_values_b1(unsigned val);
    static bool check_type_values_2(unsigned val);
    static bool check_type_values_1(unsigned val);
    static bool check_type_values_0(unsigned val);
    static bool check_type_values_b1_b32_b64_b128(unsigned val);
    static bool check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_opaque(unsigned val);
    static bool check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f(unsigned val);
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
    static bool check_type_values_b128(unsigned val);
    static bool check_type_values_b64_b128(unsigned val);
    static bool check_type_values_u_s_f_b128_opaque(unsigned val);
    static bool check_type_values_u_s_f_b128(unsigned val);
    static bool check_type_values_b128_opaque(unsigned val);
    static bool check_type_values_b128_sig(unsigned val);
    static bool check_type_values_b32(unsigned val);
    static bool check_type_values_b32_b64(unsigned val);
    static bool check_type_values_b32_s32_u32_b64_s64_u64(unsigned val);
    static bool check_type_values_b32_s32_u32(unsigned val);
    static bool check_type_values_b64(unsigned val);
    static bool check_type_values_b64_s64_u64(unsigned val);
    static bool check_type_values_f16(unsigned val);
    static bool check_type_values_f_fx(unsigned val);
    static bool check_type_values_s32_s64_sx_f_fx(unsigned val);
    static bool check_type_values_s32_u32_s64_u64_f_x(unsigned val);
    static bool check_type_values_s32_u32_s64_u64_f_fx(unsigned val);
    static bool check_type_values_f16_f32(unsigned val);
    static bool check_type_values_f(unsigned val);
    static bool check_type_values_s_u_f(unsigned val);
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
    static bool check_type_values_s32_u32_f32_f64(unsigned val);
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
    static bool check_type_values_opaque(unsigned val);
    static bool check_type_values_img(unsigned val);
    static bool check_type_values_roimg_rwimg_woimg(unsigned val);
    static bool check_type_values_woimg_rwimg(unsigned val);
    static bool check_type_values_s_u(unsigned val);
    static bool check_type_values_s16_u16(unsigned val);
    static bool check_type_values_s32_u32_s64_u64_sx_ux(unsigned val);
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
    static bool check_type_values_sig32(unsigned val);
    static bool check_type_values_sig32_sig64(unsigned val);
    static bool check_type_values_sig64(unsigned val);
    static bool check_type_values_u16x2(unsigned val);
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
    static bool check_width_values_any1(unsigned val);
    static bool check_width_values_all(unsigned val);
    static bool check_width_values_none(unsigned val);
    static bool check_width_values_wavesize(unsigned val);

private:
    template<class T> bool req_activelanecount(T inst);
    template<class T> bool req_activelaneid(T inst);
    template<class T> bool req_activelanemask(T inst);
    template<class T> bool req_activelaneshuffle(T inst);
    template<class T> bool req_add(T inst);
    template<class T> bool req_addq(T inst);
    template<class T> bool req_align(T inst);
    template<class T> bool req_alloca(T inst);
    template<class T> bool req_and(T inst);
    template<class T> bool req_atomic(T inst);
    template<class T> bool req_atomic_noret(T inst);
    template<class T> bool req_barrier(T inst);
    template<class T> bool req_basic_dst_u32(T inst);
    template<class T> bool req_basic_dst_u32_dim(T inst);
    template<class T> bool req_basic_dst_u32_u64(T inst);
    template<class T> bool req_basic_dst_u32_u64_dim(T inst);
    template<class T> bool req_bitextract(T inst);
    template<class T> bool req_bitinsert(T inst);
    template<class T> bool req_bitmask(T inst);
    template<class T> bool req_bitrev(T inst);
    template<class T> bool req_bitselect(T inst);
    template<class T> bool req_br(T inst);
    template<class T> bool req_call(T inst);
    template<class T> bool req_casq(T inst);
    template<class T> bool req_cbr(T inst);
    template<class T> bool req_ceil(T inst);
    template<class T> bool req_class(T inst);
    template<class T> bool req_cmov(T inst);
    template<class T> bool req_cmp(T inst);
    template<class T> bool req_combine(T inst);
    template<class T> bool req_copysign(T inst);
    template<class T> bool req_cvt(T inst);
    template<class T> bool req_d0_s1(T inst);
    template<class T> bool req_d0_s1_s2(T inst);
    template<class T> bool req_d0_s1_s2_s3(T inst);
    template<class T> bool req_debugtrap(T inst);
    template<class T> bool req_div(T inst);
    template<class T> bool req_expand(T inst);
    template<class T> bool req_f2s(T inst);
    template<class T> bool req_fbar_none(T inst);
    template<class T> bool req_fbar_width(T inst);
    template<class T> bool req_firstbit(T inst);
    template<class T> bool req_fma(T inst);
    template<class T> bool req_fract(T inst);
    template<class T> bool req_gcn_append_consume(T inst);
    template<class T> bool req_gcn_atomic(T inst);
    template<class T> bool req_gcn_atomic_noret(T inst);
    template<class T> bool req_gcn_b4xchg(T inst);
    template<class T> bool req_gcn_bfm(T inst);
    template<class T> bool req_gcn_div_relaxed(T inst);
    template<class T> bool req_gcn_fldexp(T inst);
    template<class T> bool req_gcn_frexp_exp(T inst);
    template<class T> bool req_gcn_frexp_mant(T inst);
    template<class T> bool req_gcn_ld(T inst);
    template<class T> bool req_gcn_mads(T inst);
    template<class T> bool req_gcn_madu(T inst);
    template<class T> bool req_gcn_min_max(T inst);
    template<class T> bool req_gcn_min_max_med3(T inst);
    template<class T> bool req_gcn_mqsad(T inst);
    template<class T> bool req_gcn_mqsad4(T inst);
    template<class T> bool req_gcn_msad(T inst);
    template<class T> bool req_gcn_qsad(T inst);
    template<class T> bool req_gcn_region_alloc(T inst);
    template<class T> bool req_gcn_slp_prt(T inst);
    template<class T> bool req_gcn_st(T inst);
    template<class T> bool req_gcn_trig_preop(T inst);
    template<class T> bool req_icall(T inst);
    template<class T> bool req_ld(T inst);
    template<class T> bool req_ld_image(T inst);
    template<class T> bool req_ld_st_image(T inst);
    template<class T> bool req_lda(T inst);
    template<class T> bool req_ldf(T inst);
    template<class T> bool req_ldi(T inst);
    template<class T> bool req_ldk(T inst);
    template<class T> bool req_ldq(T inst);
    template<class T> bool req_lerp(T inst);
    template<class T> bool req_mad(T inst);
    template<class T> bool req_mad24(T inst);
    template<class T> bool req_max(T inst);
    template<class T> bool req_memfence(T inst);
    template<class T> bool req_mov(T inst);
    template<class T> bool req_mul(T inst);
    template<class T> bool req_mul24(T inst);
    template<class T> bool req_mulhi(T inst);
    template<class T> bool req_neg(T inst);
    template<class T> bool req_nfma(T inst);
    template<class T> bool req_nop(T inst);
    template<class T> bool req_not(T inst);
    template<class T> bool req_nullptr(T inst);
    template<class T> bool req_pack(T inst);
    template<class T> bool req_packcvt(T inst);
    template<class T> bool req_packet(T inst);
    template<class T> bool req_popcount(T inst);
    template<class T> bool req_ptr_model(T inst);
    template<class T> bool req_queryimage(T inst);
    template<class T> bool req_querysampler(T inst);
    template<class T> bool req_rdimage(T inst);
    template<class T> bool req_rem(T inst);
    template<class T> bool req_ret(T inst);
    template<class T> bool req_s2f(T inst);
    template<class T> bool req_sad(T inst);
    template<class T> bool req_sadhi(T inst);
    template<class T> bool req_sbr(T inst);
    template<class T> bool req_scall(T inst);
    template<class T> bool req_segmentp(T inst);
    template<class T> bool req_shift(T inst);
    template<class T> bool req_shuffle(T inst);
    template<class T> bool req_signal(T inst);
    template<class T> bool req_signal_noret(T inst);
    template<class T> bool req_spec_clock(T inst);
    template<class T> bool req_spec_except(T inst);
    template<class T> bool req_sqrt(T inst);
    template<class T> bool req_st(T inst);
    template<class T> bool req_st_image(T inst);
    template<class T> bool req_stq(T inst);
    template<class T> bool req_trig(T inst);
    template<class T> bool req_trig32(T inst);
    template<class T> bool req_unpack(T inst);
    template<class T> bool req_unpackcvt(T inst);
    template<class T> bool req_unpackx(T inst);
    template<class T> bool req_wavebarrier(T inst);

}; // class InstValidator

unsigned InstValidator::ALIGN_VALUES_ANY[] = {
    Brig::BRIG_ALIGNMENT_1,
    Brig::BRIG_ALIGNMENT_128,
    Brig::BRIG_ALIGNMENT_16,
    Brig::BRIG_ALIGNMENT_2,
    Brig::BRIG_ALIGNMENT_256,
    Brig::BRIG_ALIGNMENT_32,
    Brig::BRIG_ALIGNMENT_4,
    Brig::BRIG_ALIGNMENT_64,
    Brig::BRIG_ALIGNMENT_8
};

unsigned InstValidator::ATMOP_VALUES_GENERIC_ATOMIC_EXCH_LD[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_LD,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_WRAPDEC,
    Brig::BRIG_ATOMIC_WRAPINC,
    Brig::BRIG_ATOMIC_XOR
};

unsigned InstValidator::ATMOP_VALUES_GENERIC_EXCH_LD_WAIT_WAITTIMEOUT[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_EXCH,
    Brig::BRIG_ATOMIC_LD,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_WAIT_EQ,
    Brig::BRIG_ATOMIC_WAIT_GTE,
    Brig::BRIG_ATOMIC_WAIT_LT,
    Brig::BRIG_ATOMIC_WAIT_NE,
    Brig::BRIG_ATOMIC_WAITTIMEOUT_EQ,
    Brig::BRIG_ATOMIC_WAITTIMEOUT_GTE,
    Brig::BRIG_ATOMIC_WAITTIMEOUT_LT,
    Brig::BRIG_ATOMIC_WAITTIMEOUT_NE,
    Brig::BRIG_ATOMIC_XOR
};

unsigned InstValidator::ATMOP_VALUES_GENERIC_ATOMIC_ST[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_ST,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_WRAPDEC,
    Brig::BRIG_ATOMIC_WRAPINC,
    Brig::BRIG_ATOMIC_XOR
};

unsigned InstValidator::ATMOP_VALUES_GENERIC_ST[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_AND,
    Brig::BRIG_ATOMIC_CAS,
    Brig::BRIG_ATOMIC_OR,
    Brig::BRIG_ATOMIC_ST,
    Brig::BRIG_ATOMIC_SUB,
    Brig::BRIG_ATOMIC_XOR
};

unsigned InstValidator::ATMOP_VALUES_ADD_SUB_MIN_MAX[] = {
    Brig::BRIG_ATOMIC_ADD,
    Brig::BRIG_ATOMIC_MAX,
    Brig::BRIG_ATOMIC_MIN,
    Brig::BRIG_ATOMIC_SUB
};

unsigned InstValidator::ATMOP_VALUES_ADD_SUB[] = {
    Brig::BRIG_ATOMIC_ADD,
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

unsigned InstValidator::ATMOP_VALUES_LD[] = {
    Brig::BRIG_ATOMIC_LD
};

unsigned InstValidator::ATMOP_VALUES_ST[] = {
    Brig::BRIG_ATOMIC_ST
};

unsigned InstValidator::ATMOP_VALUES_WAIT[] = {
    Brig::BRIG_ATOMIC_WAIT_EQ,
    Brig::BRIG_ATOMIC_WAIT_GTE,
    Brig::BRIG_ATOMIC_WAIT_LT,
    Brig::BRIG_ATOMIC_WAIT_NE
};

unsigned InstValidator::ATMOP_VALUES_WAITTIMEOUT[] = {
    Brig::BRIG_ATOMIC_WAITTIMEOUT_EQ,
    Brig::BRIG_ATOMIC_WAITTIMEOUT_GTE,
    Brig::BRIG_ATOMIC_WAITTIMEOUT_LT,
    Brig::BRIG_ATOMIC_WAITTIMEOUT_NE
};

unsigned InstValidator::ATMOP_VALUES_WRAPINC_WRAPDEC[] = {
    Brig::BRIG_ATOMIC_WRAPDEC,
    Brig::BRIG_ATOMIC_WRAPINC
};

unsigned InstValidator::COMPARE_VALUES_0[] = {
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

unsigned InstValidator::COMPARE_VALUES_EQ_NE_LT_LE_GT_GE[] = {
    Brig::BRIG_COMPARE_EQ,
    Brig::BRIG_COMPARE_GE,
    Brig::BRIG_COMPARE_GT,
    Brig::BRIG_COMPARE_LE,
    Brig::BRIG_COMPARE_LT,
    Brig::BRIG_COMPARE_NE
};

unsigned InstValidator::COMPARE_VALUES_EQ_NE[] = {
    Brig::BRIG_COMPARE_EQ,
    Brig::BRIG_COMPARE_NE
};

unsigned InstValidator::CONST_VALUES_NONE[] = {
    0
};

unsigned InstValidator::CONST_VALUES_ANY[] = {
    0,
    1
};

unsigned InstValidator::EQCLASS_VALUES_0[] = {
    EQCLASS_VAL_0
};

unsigned InstValidator::EQCLASS_VALUES_ANY[] = {
    EQCLASS_VAL_ANY
};

unsigned InstValidator::FTZ_VALUES_NONE[] = {
    0
};

unsigned InstValidator::FTZ_VALUES_ANY[] = {
    0,
    1
};

unsigned InstValidator::GEOMETRY_VALUES_1D[] = {
    Brig::BRIG_GEOMETRY_1D
};

unsigned InstValidator::GEOMETRY_VALUES_ANY[] = {
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_1DB,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_2DADEPTH,
    Brig::BRIG_GEOMETRY_2DDEPTH,
    Brig::BRIG_GEOMETRY_3D
};

unsigned InstValidator::GEOMETRY_VALUES_1D_2D_3D_1DA_2DA_2DDEPTH_2DADEPTH[] = {
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_2DADEPTH,
    Brig::BRIG_GEOMETRY_2DDEPTH,
    Brig::BRIG_GEOMETRY_3D
};

unsigned InstValidator::GEOMETRY_VALUES_1D_1DB[] = {
    Brig::BRIG_GEOMETRY_1D,
    Brig::BRIG_GEOMETRY_1DB
};

unsigned InstValidator::GEOMETRY_VALUES_2D_1DA[] = {
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_2D
};

unsigned InstValidator::GEOMETRY_VALUES_1DA_2DA_2DADEPTH[] = {
    Brig::BRIG_GEOMETRY_1DA,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_2DADEPTH
};

unsigned InstValidator::GEOMETRY_VALUES_2D_3D_2DA_2DDEPTH_2DADEPTH[] = {
    Brig::BRIG_GEOMETRY_2D,
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_2DADEPTH,
    Brig::BRIG_GEOMETRY_2DDEPTH,
    Brig::BRIG_GEOMETRY_3D
};

unsigned InstValidator::GEOMETRY_VALUES_3D_2DA[] = {
    Brig::BRIG_GEOMETRY_2DA,
    Brig::BRIG_GEOMETRY_3D
};

unsigned InstValidator::GEOMETRY_VALUES_2DADEPTH[] = {
    Brig::BRIG_GEOMETRY_2DADEPTH
};

unsigned InstValidator::GEOMETRY_VALUES_2DDEPTH[] = {
    Brig::BRIG_GEOMETRY_2DDEPTH
};

unsigned InstValidator::GEOMETRY_VALUES_3D[] = {
    Brig::BRIG_GEOMETRY_3D
};

unsigned InstValidator::IPROP_VALUES_ARRAY[] = {
    Brig::BRIG_IMAGE_QUERY_ARRAY
};

unsigned InstValidator::IPROP_VALUES_ANY[] = {
    Brig::BRIG_IMAGE_QUERY_ARRAY,
    Brig::BRIG_IMAGE_QUERY_CHANNELORDER,
    Brig::BRIG_IMAGE_QUERY_CHANNELTYPE,
    Brig::BRIG_IMAGE_QUERY_DEPTH,
    Brig::BRIG_IMAGE_QUERY_HEIGHT,
    Brig::BRIG_IMAGE_QUERY_WIDTH
};

unsigned InstValidator::IPROP_VALUES_WIDTH_CHANNELTYPE_CHANNELORDER[] = {
    Brig::BRIG_IMAGE_QUERY_CHANNELORDER,
    Brig::BRIG_IMAGE_QUERY_CHANNELTYPE,
    Brig::BRIG_IMAGE_QUERY_WIDTH
};

unsigned InstValidator::IPROP_VALUES_DEPTH[] = {
    Brig::BRIG_IMAGE_QUERY_DEPTH
};

unsigned InstValidator::IPROP_VALUES_HEIGHT[] = {
    Brig::BRIG_IMAGE_QUERY_HEIGHT
};

unsigned InstValidator::MEMORD_VALUES_LD[] = {
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE
};

unsigned InstValidator::MEMORD_VALUES_ANY[] = {
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SC_RELEASE
};

unsigned InstValidator::MEMORD_VALUES_ST[] = {
    Brig::BRIG_MEMORY_ORDER_RELAXED,
    Brig::BRIG_MEMORY_ORDER_SC_RELEASE
};

unsigned InstValidator::MEMORD_VALUES_ACQ_REL_AR[] = {
    Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE,
    Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE,
    Brig::BRIG_MEMORY_ORDER_SC_RELEASE
};

unsigned InstValidator::MEMORD_VALUES_AR[] = {
    Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE
};

unsigned InstValidator::MEMSCP_VALUES_NONE_WV_WG_CMP_SYS[] = {
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_NONE,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WAVEFRONT,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP
};

unsigned InstValidator::MEMSCP_VALUES_WV_WG_CMP_SYS[] = {
    Brig::BRIG_MEMORY_SCOPE_COMPONENT,
    Brig::BRIG_MEMORY_SCOPE_SYSTEM,
    Brig::BRIG_MEMORY_SCOPE_WAVEFRONT,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP
};

unsigned InstValidator::MEMSCP_VALUES_NONE[] = {
    Brig::BRIG_MEMORY_SCOPE_NONE
};

unsigned InstValidator::MEMSCP_VALUES_NONE_WV_WG[] = {
    Brig::BRIG_MEMORY_SCOPE_NONE,
    Brig::BRIG_MEMORY_SCOPE_WAVEFRONT,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP
};

unsigned InstValidator::MEMSCP_VALUES_NONE_WI_WV_WG[] = {
    Brig::BRIG_MEMORY_SCOPE_NONE,
    Brig::BRIG_MEMORY_SCOPE_WAVEFRONT,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
    Brig::BRIG_MEMORY_SCOPE_WORKITEM
};

unsigned InstValidator::MEMSCP_VALUES_WV_WG[] = {
    Brig::BRIG_MEMORY_SCOPE_WAVEFRONT,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP
};

unsigned InstValidator::MEMSCP_VALUES_WI_WV_WG[] = {
    Brig::BRIG_MEMORY_SCOPE_WAVEFRONT,
    Brig::BRIG_MEMORY_SCOPE_WORKGROUP,
    Brig::BRIG_MEMORY_SCOPE_WORKITEM
};

unsigned InstValidator::NONULL_VALUES_ANY[] = {
    0,
    1
};

unsigned InstValidator::OPERAND_VALUES_ADDRSEG[] = {
    OPERAND_VAL_ADDR
};

unsigned InstValidator::OPERAND_VALUES_ARGLIST[] = {
    OPERAND_VAL_ARGLIST
};

unsigned InstValidator::OPERAND_VALUES_CALLTAB[] = {
    OPERAND_VAL_CALLTAB
};

unsigned InstValidator::OPERAND_VALUES_CNSTB32[] = {
    OPERAND_VAL_CNST
};

unsigned InstValidator::OPERAND_VALUES_REGU32_CNSTU32[] = {
    OPERAND_VAL_CNST,
    OPERAND_VAL_REG
};

unsigned InstValidator::OPERAND_VALUES_FBARRIERU32[] = {
    OPERAND_VAL_FBARRIER
};

unsigned InstValidator::OPERAND_VALUES_REGU32_FBARRIERU32[] = {
    OPERAND_VAL_FBARRIER,
    OPERAND_VAL_REG
};

unsigned InstValidator::OPERAND_VALUES_FUNC[] = {
    OPERAND_VAL_FUNC
};

unsigned InstValidator::OPERAND_VALUES_IFUNC[] = {
    OPERAND_VAL_IFUNC
};

unsigned InstValidator::OPERAND_VALUES_IMM[] = {
    OPERAND_VAL_IMM
};

unsigned InstValidator::OPERAND_VALUES_REGSTYPE_IMMSTYPE[] = {
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG
};

unsigned InstValidator::OPERAND_VALUES_REG_VECTOR_IMM[] = {
    OPERAND_VAL_IMM,
    OPERAND_VAL_REG,
    OPERAND_VAL_VEC_2,
    OPERAND_VAL_VEC_3,
    OPERAND_VAL_VEC_4
};

unsigned InstValidator::OPERAND_VALUES_IMM0T2U32[] = {
    OPERAND_VAL_IMM0T2
};

unsigned InstValidator::OPERAND_VALUES_IMM0T3U32[] = {
    OPERAND_VAL_IMM0T3
};

unsigned InstValidator::OPERAND_VALUES_JUMPTAB[] = {
    OPERAND_VAL_JUMPTAB
};

unsigned InstValidator::OPERAND_VALUES_KERNEL[] = {
    OPERAND_VAL_KERNEL
};

unsigned InstValidator::OPERAND_VALUES_LAB[] = {
    OPERAND_VAL_LAB
};

unsigned InstValidator::OPERAND_VALUES_NULL[] = {
    OPERAND_VAL_NULL
};

unsigned InstValidator::OPERAND_VALUES_REG[] = {
    OPERAND_VAL_REG
};

unsigned InstValidator::OPERAND_VALUES_REG_VECTOR[] = {
    OPERAND_VAL_REG,
    OPERAND_VAL_VEC_2,
    OPERAND_VAL_VEC_3,
    OPERAND_VAL_VEC_4
};

unsigned InstValidator::OPERAND_VALUES_SIGNATURE[] = {
    OPERAND_VAL_SIGNATURE
};

unsigned InstValidator::OPERAND_VALUES_VEC2STYPE[] = {
    OPERAND_VAL_VEC_2
};

unsigned InstValidator::OPERAND_VALUES_VEC3CTYPE[] = {
    OPERAND_VAL_VEC_3
};

unsigned InstValidator::OPERAND_VALUES_VEC4[] = {
    OPERAND_VAL_VEC_4
};

unsigned InstValidator::PACK_VALUES_NONE[] = {
    Brig::BRIG_PACK_NONE
};

unsigned InstValidator::PACK_VALUES_P_S[] = {
    Brig::BRIG_PACK_P,
    Brig::BRIG_PACK_S
};

unsigned InstValidator::PACK_VALUES_PP[] = {
    Brig::BRIG_PACK_PP
};

unsigned InstValidator::PACK_VALUES_BIN[] = {
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PPSAT,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_PSSAT,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SPSAT,
    Brig::BRIG_PACK_SS,
    Brig::BRIG_PACK_SSSAT
};

unsigned InstValidator::PACK_VALUES_BINNOSAT[] = {
    Brig::BRIG_PACK_PP,
    Brig::BRIG_PACK_PS,
    Brig::BRIG_PACK_SP,
    Brig::BRIG_PACK_SS
};

unsigned InstValidator::ROUND_VALUES_FLOAT[] = {
    Brig::BRIG_ROUND_FLOAT_MINUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_NEAR_EVEN,
    Brig::BRIG_ROUND_FLOAT_PLUS_INFINITY,
    Brig::BRIG_ROUND_FLOAT_ZERO
};

unsigned InstValidator::ROUND_VALUES_INT[] = {
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN_SAT,
    Brig::BRIG_ROUND_INTEGER_NEAR_EVEN,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN_SAT,
    Brig::BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN,
    Brig::BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY_SAT,
    Brig::BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY,
    Brig::BRIG_ROUND_INTEGER_SIGNALLING_ZERO_SAT,
    Brig::BRIG_ROUND_INTEGER_SIGNALLING_ZERO,
    Brig::BRIG_ROUND_INTEGER_ZERO_SAT,
    Brig::BRIG_ROUND_INTEGER_ZERO
};

unsigned InstValidator::ROUND_VALUES_NONE[] = {
    Brig::BRIG_ROUND_NONE
};

unsigned InstValidator::SEGMENT_VALUES_GCN[] = {
    Brig::BRIG_SEGMENT_EXTSPACE0
};

unsigned InstValidator::SEGMENT_VALUES_ARG[] = {
    Brig::BRIG_SEGMENT_ARG
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

unsigned InstValidator::SEGMENT_VALUES_GROUP_PRIVATE_READONLY_KERNARG_SPILL_ARG[] = {
    Brig::BRIG_SEGMENT_ARG,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY,
    Brig::BRIG_SEGMENT_SPILL
};

unsigned InstValidator::SEGMENT_VALUES_FLAT_GLOBAL[] = {
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL
};

unsigned InstValidator::SEGMENT_VALUES_GLOBAL_GROUP_FLAT[] = {
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP
};

unsigned InstValidator::SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE_FLAT_KERNARG_READONLY[] = {
    Brig::BRIG_SEGMENT_FLAT,
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_KERNARG,
    Brig::BRIG_SEGMENT_PRIVATE,
    Brig::BRIG_SEGMENT_READONLY
};

unsigned InstValidator::SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE[] = {
    Brig::BRIG_SEGMENT_GLOBAL,
    Brig::BRIG_SEGMENT_GROUP,
    Brig::BRIG_SEGMENT_PRIVATE
};

unsigned InstValidator::SEGMENT_VALUES_GROUP[] = {
    Brig::BRIG_SEGMENT_GROUP
};

unsigned InstValidator::SEGMENT_VALUES_PRIVATE[] = {
    Brig::BRIG_SEGMENT_PRIVATE
};

unsigned InstValidator::SPROP_VALUES_ANY[] = {
    Brig::BRIG_SAMPLER_QUERY_ADDRESSING,
    Brig::BRIG_SAMPLER_QUERY_COORD,
    Brig::BRIG_SAMPLER_QUERY_FILTER
};

unsigned InstValidator::STYPESIZE_VALUES_MODEL[] = {
    STYPESIZE_VAL_MODEL
};

unsigned InstValidator::STYPESIZE_VALUES_SEG[] = {
    STYPESIZE_VAL_SEG
};

unsigned InstValidator::TYPE_VALUES_B1[] = {
    Brig::BRIG_TYPE_B1
};

unsigned InstValidator::TYPE_VALUES_2[] = {
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
    Brig::BRIG_TYPE_SIG32,
    Brig::BRIG_TYPE_SIG64,
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
    Brig::BRIG_TYPE_WOIMG
};

unsigned InstValidator::TYPE_VALUES_1[] = {
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
    Brig::BRIG_TYPE_SIG32,
    Brig::BRIG_TYPE_SIG64,
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
    Brig::BRIG_TYPE_WOIMG
};

unsigned InstValidator::TYPE_VALUES_0[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_B16,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_B8,
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
    Brig::BRIG_TYPE_SIG32,
    Brig::BRIG_TYPE_SIG64,
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
    Brig::BRIG_TYPE_WOIMG
};

unsigned InstValidator::TYPE_VALUES_B1_B32_B64_B128[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_B64
};

unsigned InstValidator::TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_OPAQUE[] = {
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
    Brig::BRIG_TYPE_SIG32,
    Brig::BRIG_TYPE_SIG64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_WOIMG
};

unsigned InstValidator::TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_B128,
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

unsigned InstValidator::TYPE_VALUES_B1_S16_U16_S32_U32_S64_U64_F[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_S8_U8_S16_U16_S32_U32_F[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_S8_U8_S16_U16_S64_U64_F[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_S8_U8_S32_U32_S64_U64_F[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_S32_U32_S64_U64_F_UX[] = {
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

unsigned InstValidator::TYPE_VALUES_B1_S32_U32_S64_U64_F[] = {
    Brig::BRIG_TYPE_B1,
    Brig::BRIG_TYPE_F16,
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64
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

unsigned InstValidator::TYPE_VALUES_U_S_F_B128_OPAQUE[] = {
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
    Brig::BRIG_TYPE_SIG32,
    Brig::BRIG_TYPE_SIG64,
    Brig::BRIG_TYPE_U16,
    Brig::BRIG_TYPE_U32,
    Brig::BRIG_TYPE_U64,
    Brig::BRIG_TYPE_U8,
    Brig::BRIG_TYPE_WOIMG
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

unsigned InstValidator::TYPE_VALUES_B128_OPAQUE[] = {
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_SAMP,
    Brig::BRIG_TYPE_SIG32,
    Brig::BRIG_TYPE_SIG64,
    Brig::BRIG_TYPE_WOIMG
};

unsigned InstValidator::TYPE_VALUES_B128_SIG[] = {
    Brig::BRIG_TYPE_B128,
    Brig::BRIG_TYPE_SIG32,
    Brig::BRIG_TYPE_SIG64
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

unsigned InstValidator::TYPE_VALUES_B32_S32_U32[] = {
    Brig::BRIG_TYPE_B32,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32
};

unsigned InstValidator::TYPE_VALUES_B64[] = {
    Brig::BRIG_TYPE_B64
};

unsigned InstValidator::TYPE_VALUES_B64_S64_U64[] = {
    Brig::BRIG_TYPE_B64,
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U64
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

unsigned InstValidator::TYPE_VALUES_S_U_F[] = {
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

unsigned InstValidator::TYPE_VALUES_S32_U32_F32_F64[] = {
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_F64,
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_U32
};

unsigned InstValidator::TYPE_VALUES_S32_F32[] = {
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32
};

unsigned InstValidator::TYPE_VALUES_S32_U32_F32[] = {
    Brig::BRIG_TYPE_F32,
    Brig::BRIG_TYPE_S32,
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

unsigned InstValidator::TYPE_VALUES_ROIMG[] = {
    Brig::BRIG_TYPE_ROIMG
};

unsigned InstValidator::TYPE_VALUES_ROIMG_RWIMG[] = {
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG
};

unsigned InstValidator::TYPE_VALUES_OPAQUE[] = {
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_SAMP,
    Brig::BRIG_TYPE_SIG32,
    Brig::BRIG_TYPE_SIG64,
    Brig::BRIG_TYPE_WOIMG
};

unsigned InstValidator::TYPE_VALUES_IMG[] = {
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_SAMP,
    Brig::BRIG_TYPE_WOIMG
};

unsigned InstValidator::TYPE_VALUES_ROIMG_RWIMG_WOIMG[] = {
    Brig::BRIG_TYPE_ROIMG,
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_WOIMG
};

unsigned InstValidator::TYPE_VALUES_WOIMG_RWIMG[] = {
    Brig::BRIG_TYPE_RWIMG,
    Brig::BRIG_TYPE_WOIMG
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

unsigned InstValidator::TYPE_VALUES_S16_U16[] = {
    Brig::BRIG_TYPE_S16,
    Brig::BRIG_TYPE_U16
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

unsigned InstValidator::TYPE_VALUES_S32_S64[] = {
    Brig::BRIG_TYPE_S32,
    Brig::BRIG_TYPE_S64
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

unsigned InstValidator::TYPE_VALUES_S64_U64[] = {
    Brig::BRIG_TYPE_S64,
    Brig::BRIG_TYPE_U64
};

unsigned InstValidator::TYPE_VALUES_S64X[] = {
    Brig::BRIG_TYPE_S64X2
};

unsigned InstValidator::TYPE_VALUES_S8_U8[] = {
    Brig::BRIG_TYPE_S8,
    Brig::BRIG_TYPE_U8
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

unsigned InstValidator::TYPE_VALUES_SIG32[] = {
    Brig::BRIG_TYPE_SIG32
};

unsigned InstValidator::TYPE_VALUES_SIG32_SIG64[] = {
    Brig::BRIG_TYPE_SIG32,
    Brig::BRIG_TYPE_SIG64
};

unsigned InstValidator::TYPE_VALUES_SIG64[] = {
    Brig::BRIG_TYPE_SIG64
};

unsigned InstValidator::TYPE_VALUES_U16X2[] = {
    Brig::BRIG_TYPE_U16X2
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

unsigned InstValidator::TYPESIZE_VALUES_ATOMIC[] = {
    TYPESIZE_VAL_ATOMIC
};

unsigned InstValidator::TYPESIZE_VALUES_MODEL[] = {
    TYPESIZE_VAL_MODEL
};

unsigned InstValidator::TYPESIZE_VALUES_SEG[] = {
    TYPESIZE_VAL_SEG
};

unsigned InstValidator::TYPESIZE_VALUES_SIGNAL[] = {
    TYPESIZE_VAL_SIGNAL
};

unsigned InstValidator::WIDTH_VALUES_ANY1[] = {
    Brig::BRIG_WIDTH_1024,
    Brig::BRIG_WIDTH_1048576,
    Brig::BRIG_WIDTH_1073741824,
    Brig::BRIG_WIDTH_128,
    Brig::BRIG_WIDTH_131072,
    Brig::BRIG_WIDTH_134217728,
    Brig::BRIG_WIDTH_16384,
    Brig::BRIG_WIDTH_16777216,
    Brig::BRIG_WIDTH_16,
    Brig::BRIG_WIDTH_1,
    Brig::BRIG_WIDTH_2048,
    Brig::BRIG_WIDTH_2097152,
    Brig::BRIG_WIDTH_2147483648,
    Brig::BRIG_WIDTH_256,
    Brig::BRIG_WIDTH_262144,
    Brig::BRIG_WIDTH_268435456,
    Brig::BRIG_WIDTH_2,
    Brig::BRIG_WIDTH_32768,
    Brig::BRIG_WIDTH_32,
    Brig::BRIG_WIDTH_33554432,
    Brig::BRIG_WIDTH_4096,
    Brig::BRIG_WIDTH_4194304,
    Brig::BRIG_WIDTH_4,
    Brig::BRIG_WIDTH_512,
    Brig::BRIG_WIDTH_524288,
    Brig::BRIG_WIDTH_536870912,
    Brig::BRIG_WIDTH_64,
    Brig::BRIG_WIDTH_65536,
    Brig::BRIG_WIDTH_67108864,
    Brig::BRIG_WIDTH_8192,
    Brig::BRIG_WIDTH_8388608,
    Brig::BRIG_WIDTH_8,
    Brig::BRIG_WIDTH_ALL,
    Brig::BRIG_WIDTH_WAVESIZE
};

unsigned InstValidator::WIDTH_VALUES_ALL[] = {
    Brig::BRIG_WIDTH_ALL
};

unsigned InstValidator::WIDTH_VALUES_NONE[] = {
    Brig::BRIG_WIDTH_NONE
};

unsigned InstValidator::WIDTH_VALUES_WAVESIZE[] = {
    Brig::BRIG_WIDTH_WAVESIZE
};

bool InstValidator::check_align_values_any(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ALIGNMENT_1:
    case Brig::BRIG_ALIGNMENT_128:
    case Brig::BRIG_ALIGNMENT_16:
    case Brig::BRIG_ALIGNMENT_2:
    case Brig::BRIG_ALIGNMENT_256:
    case Brig::BRIG_ALIGNMENT_32:
    case Brig::BRIG_ALIGNMENT_4:
    case Brig::BRIG_ALIGNMENT_64:
    case Brig::BRIG_ALIGNMENT_8:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_atmop_values_generic_atomic_exch_ld(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_ADD:
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_CAS:
    case Brig::BRIG_ATOMIC_EXCH:
    case Brig::BRIG_ATOMIC_LD:
    case Brig::BRIG_ATOMIC_MAX:
    case Brig::BRIG_ATOMIC_MIN:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_SUB:
    case Brig::BRIG_ATOMIC_WRAPDEC:
    case Brig::BRIG_ATOMIC_WRAPINC:
    case Brig::BRIG_ATOMIC_XOR:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_atmop_values_generic_exch_ld_wait_waittimeout(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_ADD:
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_CAS:
    case Brig::BRIG_ATOMIC_EXCH:
    case Brig::BRIG_ATOMIC_LD:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_SUB:
    case Brig::BRIG_ATOMIC_WAIT_EQ:
    case Brig::BRIG_ATOMIC_WAIT_GTE:
    case Brig::BRIG_ATOMIC_WAIT_LT:
    case Brig::BRIG_ATOMIC_WAIT_NE:
    case Brig::BRIG_ATOMIC_WAITTIMEOUT_EQ:
    case Brig::BRIG_ATOMIC_WAITTIMEOUT_GTE:
    case Brig::BRIG_ATOMIC_WAITTIMEOUT_LT:
    case Brig::BRIG_ATOMIC_WAITTIMEOUT_NE:
    case Brig::BRIG_ATOMIC_XOR:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_atmop_values_generic_atomic_st(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_ADD:
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_CAS:
    case Brig::BRIG_ATOMIC_MAX:
    case Brig::BRIG_ATOMIC_MIN:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_ST:
    case Brig::BRIG_ATOMIC_SUB:
    case Brig::BRIG_ATOMIC_WRAPDEC:
    case Brig::BRIG_ATOMIC_WRAPINC:
    case Brig::BRIG_ATOMIC_XOR:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_atmop_values_generic_st(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_ADD:
    case Brig::BRIG_ATOMIC_AND:
    case Brig::BRIG_ATOMIC_CAS:
    case Brig::BRIG_ATOMIC_OR:
    case Brig::BRIG_ATOMIC_ST:
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

bool InstValidator::check_atmop_values_add_sub(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_ADD:
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

bool InstValidator::check_atmop_values_ld(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_LD:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_atmop_values_st(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_ST:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_atmop_values_wait(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_WAIT_EQ:
    case Brig::BRIG_ATOMIC_WAIT_GTE:
    case Brig::BRIG_ATOMIC_WAIT_LT:
    case Brig::BRIG_ATOMIC_WAIT_NE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_atmop_values_waittimeout(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_WAITTIMEOUT_EQ:
    case Brig::BRIG_ATOMIC_WAITTIMEOUT_GTE:
    case Brig::BRIG_ATOMIC_WAITTIMEOUT_LT:
    case Brig::BRIG_ATOMIC_WAITTIMEOUT_NE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_atmop_values_wrapinc_wrapdec(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ATOMIC_WRAPDEC:
    case Brig::BRIG_ATOMIC_WRAPINC:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_compare_values_0(unsigned val)
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

bool InstValidator::check_compare_values_eq_ne_lt_le_gt_ge(unsigned val)
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

bool InstValidator::check_compare_values_eq_ne(unsigned val)
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

bool InstValidator::check_const_values_none(unsigned val)
{
    switch(val)
    {
    case 0:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_const_values_any(unsigned val)
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

bool InstValidator::check_geometry_values_1d(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_GEOMETRY_1D:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_geometry_values_any(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_GEOMETRY_1D:
    case Brig::BRIG_GEOMETRY_1DA:
    case Brig::BRIG_GEOMETRY_1DB:
    case Brig::BRIG_GEOMETRY_2D:
    case Brig::BRIG_GEOMETRY_2DA:
    case Brig::BRIG_GEOMETRY_2DADEPTH:
    case Brig::BRIG_GEOMETRY_2DDEPTH:
    case Brig::BRIG_GEOMETRY_3D:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_geometry_values_1d_2d_3d_1da_2da_2ddepth_2dadepth(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_GEOMETRY_1D:
    case Brig::BRIG_GEOMETRY_1DA:
    case Brig::BRIG_GEOMETRY_2D:
    case Brig::BRIG_GEOMETRY_2DA:
    case Brig::BRIG_GEOMETRY_2DADEPTH:
    case Brig::BRIG_GEOMETRY_2DDEPTH:
    case Brig::BRIG_GEOMETRY_3D:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_geometry_values_1d_1db(unsigned val)
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

bool InstValidator::check_geometry_values_2d_1da(unsigned val)
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

bool InstValidator::check_geometry_values_1da_2da_2dadepth(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_GEOMETRY_1DA:
    case Brig::BRIG_GEOMETRY_2DA:
    case Brig::BRIG_GEOMETRY_2DADEPTH:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_geometry_values_2d_3d_2da_2ddepth_2dadepth(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_GEOMETRY_2D:
    case Brig::BRIG_GEOMETRY_2DA:
    case Brig::BRIG_GEOMETRY_2DADEPTH:
    case Brig::BRIG_GEOMETRY_2DDEPTH:
    case Brig::BRIG_GEOMETRY_3D:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_geometry_values_3d_2da(unsigned val)
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

bool InstValidator::check_geometry_values_2dadepth(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_GEOMETRY_2DADEPTH:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_geometry_values_2ddepth(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_GEOMETRY_2DDEPTH:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_geometry_values_3d(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_GEOMETRY_3D:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_iprop_values_array(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_IMAGE_QUERY_ARRAY:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_iprop_values_any(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_IMAGE_QUERY_ARRAY:
    case Brig::BRIG_IMAGE_QUERY_CHANNELORDER:
    case Brig::BRIG_IMAGE_QUERY_CHANNELTYPE:
    case Brig::BRIG_IMAGE_QUERY_DEPTH:
    case Brig::BRIG_IMAGE_QUERY_HEIGHT:
    case Brig::BRIG_IMAGE_QUERY_WIDTH:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_iprop_values_width_channeltype_channelorder(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_IMAGE_QUERY_CHANNELORDER:
    case Brig::BRIG_IMAGE_QUERY_CHANNELTYPE:
    case Brig::BRIG_IMAGE_QUERY_WIDTH:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_iprop_values_depth(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_IMAGE_QUERY_DEPTH:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_iprop_values_height(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_IMAGE_QUERY_HEIGHT:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memord_values_ld(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_ORDER_RELAXED:
    case Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memord_values_any(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_ORDER_RELAXED:
    case Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE:
    case Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE:
    case Brig::BRIG_MEMORY_ORDER_SC_RELEASE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memord_values_st(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_ORDER_RELAXED:
    case Brig::BRIG_MEMORY_ORDER_SC_RELEASE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memord_values_acq_rel_ar(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE:
    case Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE:
    case Brig::BRIG_MEMORY_ORDER_SC_RELEASE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memord_values_ar(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memscp_values_none_wv_wg_cmp_sys(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_SCOPE_COMPONENT:
    case Brig::BRIG_MEMORY_SCOPE_NONE:
    case Brig::BRIG_MEMORY_SCOPE_SYSTEM:
    case Brig::BRIG_MEMORY_SCOPE_WAVEFRONT:
    case Brig::BRIG_MEMORY_SCOPE_WORKGROUP:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memscp_values_wv_wg_cmp_sys(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_SCOPE_COMPONENT:
    case Brig::BRIG_MEMORY_SCOPE_SYSTEM:
    case Brig::BRIG_MEMORY_SCOPE_WAVEFRONT:
    case Brig::BRIG_MEMORY_SCOPE_WORKGROUP:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memscp_values_none(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_SCOPE_NONE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memscp_values_none_wv_wg(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_SCOPE_NONE:
    case Brig::BRIG_MEMORY_SCOPE_WAVEFRONT:
    case Brig::BRIG_MEMORY_SCOPE_WORKGROUP:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memscp_values_none_wi_wv_wg(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_SCOPE_NONE:
    case Brig::BRIG_MEMORY_SCOPE_WAVEFRONT:
    case Brig::BRIG_MEMORY_SCOPE_WORKGROUP:
    case Brig::BRIG_MEMORY_SCOPE_WORKITEM:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memscp_values_wv_wg(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_SCOPE_WAVEFRONT:
    case Brig::BRIG_MEMORY_SCOPE_WORKGROUP:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_memscp_values_wi_wv_wg(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_MEMORY_SCOPE_WAVEFRONT:
    case Brig::BRIG_MEMORY_SCOPE_WORKGROUP:
    case Brig::BRIG_MEMORY_SCOPE_WORKITEM:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_nonull_values_any(unsigned val)
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

bool InstValidator::check_pack_values_none(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_PACK_NONE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_pack_values_p_s(unsigned val)
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

bool InstValidator::check_pack_values_pp(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_PACK_PP:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_pack_values_bin(unsigned val)
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

bool InstValidator::check_pack_values_binnosat(unsigned val)
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

bool InstValidator::check_round_values_float(unsigned val)
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

bool InstValidator::check_round_values_int(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT:
    case Brig::BRIG_ROUND_INTEGER_MINUS_INFINITY:
    case Brig::BRIG_ROUND_INTEGER_NEAR_EVEN_SAT:
    case Brig::BRIG_ROUND_INTEGER_NEAR_EVEN:
    case Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT:
    case Brig::BRIG_ROUND_INTEGER_PLUS_INFINITY:
    case Brig::BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY_SAT:
    case Brig::BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY:
    case Brig::BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN_SAT:
    case Brig::BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN:
    case Brig::BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY_SAT:
    case Brig::BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY:
    case Brig::BRIG_ROUND_INTEGER_SIGNALLING_ZERO_SAT:
    case Brig::BRIG_ROUND_INTEGER_SIGNALLING_ZERO:
    case Brig::BRIG_ROUND_INTEGER_ZERO_SAT:
    case Brig::BRIG_ROUND_INTEGER_ZERO:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_round_values_none(unsigned val)
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

bool InstValidator::check_segment_values_arg(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_SEGMENT_ARG:
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

bool InstValidator::check_segment_values_group_private_readonly_kernarg_spill_arg(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_SEGMENT_ARG:
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

bool InstValidator::check_segment_values_flat_global(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_SEGMENT_FLAT:
    case Brig::BRIG_SEGMENT_GLOBAL:
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

bool InstValidator::check_segment_values_global_group_private_flat_kernarg_readonly(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_SEGMENT_FLAT:
    case Brig::BRIG_SEGMENT_GLOBAL:
    case Brig::BRIG_SEGMENT_GROUP:
    case Brig::BRIG_SEGMENT_KERNARG:
    case Brig::BRIG_SEGMENT_PRIVATE:
    case Brig::BRIG_SEGMENT_READONLY:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_segment_values_global_group_private(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_SEGMENT_GLOBAL:
    case Brig::BRIG_SEGMENT_GROUP:
    case Brig::BRIG_SEGMENT_PRIVATE:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_segment_values_group(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_SEGMENT_GROUP:
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

bool InstValidator::check_sprop_values_any(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_SAMPLER_QUERY_ADDRESSING:
    case Brig::BRIG_SAMPLER_QUERY_COORD:
    case Brig::BRIG_SAMPLER_QUERY_FILTER:
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

bool InstValidator::check_type_values_2(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_B16:
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
    case Brig::BRIG_TYPE_B8:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_NONE:
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_SAMP:
    case Brig::BRIG_TYPE_SIG32:
    case Brig::BRIG_TYPE_SIG64:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
    case Brig::BRIG_TYPE_WOIMG:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_1(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_B16:
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
    case Brig::BRIG_TYPE_B8:
    case Brig::BRIG_TYPE_F16:
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_NONE:
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_SAMP:
    case Brig::BRIG_TYPE_SIG32:
    case Brig::BRIG_TYPE_SIG64:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
    case Brig::BRIG_TYPE_WOIMG:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_0(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_B16:
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
    case Brig::BRIG_TYPE_B8:
    case Brig::BRIG_TYPE_F16X2:
    case Brig::BRIG_TYPE_F16X4:
    case Brig::BRIG_TYPE_F16X8:
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F32X2:
    case Brig::BRIG_TYPE_F32X4:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_F64X2:
    case Brig::BRIG_TYPE_NONE:
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_S16:
    case Brig::BRIG_TYPE_S16X2:
    case Brig::BRIG_TYPE_S16X4:
    case Brig::BRIG_TYPE_S16X8:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S32X2:
    case Brig::BRIG_TYPE_S32X4:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_S64X2:
    case Brig::BRIG_TYPE_S8:
    case Brig::BRIG_TYPE_S8X16:
    case Brig::BRIG_TYPE_S8X4:
    case Brig::BRIG_TYPE_S8X8:
    case Brig::BRIG_TYPE_SAMP:
    case Brig::BRIG_TYPE_SIG32:
    case Brig::BRIG_TYPE_SIG64:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U16X2:
    case Brig::BRIG_TYPE_U16X4:
    case Brig::BRIG_TYPE_U16X8:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U32X2:
    case Brig::BRIG_TYPE_U32X4:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U64X2:
    case Brig::BRIG_TYPE_U8:
    case Brig::BRIG_TYPE_U8X16:
    case Brig::BRIG_TYPE_U8X4:
    case Brig::BRIG_TYPE_U8X8:
    case Brig::BRIG_TYPE_WOIMG:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_b1_b32_b64_b128(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_B1:
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_B64:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_opaque(unsigned val)
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
    case Brig::BRIG_TYPE_SIG32:
    case Brig::BRIG_TYPE_SIG64:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_WOIMG:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f(unsigned val)
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
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_S64:
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

bool InstValidator::check_type_values_b1_s16_u16_s32_u32_s64_u64_f(unsigned val)
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

bool InstValidator::check_type_values_b1_s8_u8_s16_u16_s32_u32_f(unsigned val)
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

bool InstValidator::check_type_values_b1_s8_u8_s16_u16_s64_u64_f(unsigned val)
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

bool InstValidator::check_type_values_b1_s8_u8_s32_u32_s64_u64_f(unsigned val)
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

bool InstValidator::check_type_values_b1_s32_u32_s64_u64_f_ux(unsigned val)
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

bool InstValidator::check_type_values_b1_s32_u32_s64_u64_f(unsigned val)
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

bool InstValidator::check_type_values_u_s_f_b128_opaque(unsigned val)
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
    case Brig::BRIG_TYPE_SIG32:
    case Brig::BRIG_TYPE_SIG64:
    case Brig::BRIG_TYPE_U16:
    case Brig::BRIG_TYPE_U32:
    case Brig::BRIG_TYPE_U64:
    case Brig::BRIG_TYPE_U8:
    case Brig::BRIG_TYPE_WOIMG:
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

bool InstValidator::check_type_values_b128_opaque(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_SAMP:
    case Brig::BRIG_TYPE_SIG32:
    case Brig::BRIG_TYPE_SIG64:
    case Brig::BRIG_TYPE_WOIMG:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_b128_sig(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_B128:
    case Brig::BRIG_TYPE_SIG32:
    case Brig::BRIG_TYPE_SIG64:
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

bool InstValidator::check_type_values_b32_s32_u32(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_B32:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_U32:
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

bool InstValidator::check_type_values_b64_s64_u64(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_B64:
    case Brig::BRIG_TYPE_S64:
    case Brig::BRIG_TYPE_U64:
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

bool InstValidator::check_type_values_s_u_f(unsigned val)
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

bool InstValidator::check_type_values_s32_u32_f32_f64(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_F32:
    case Brig::BRIG_TYPE_F64:
    case Brig::BRIG_TYPE_S32:
    case Brig::BRIG_TYPE_U32:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_s32_f32(unsigned val)
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

bool InstValidator::check_type_values_roimg(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_ROIMG:
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

bool InstValidator::check_type_values_opaque(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_SAMP:
    case Brig::BRIG_TYPE_SIG32:
    case Brig::BRIG_TYPE_SIG64:
    case Brig::BRIG_TYPE_WOIMG:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_img(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_SAMP:
    case Brig::BRIG_TYPE_WOIMG:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_roimg_rwimg_woimg(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_ROIMG:
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_WOIMG:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_woimg_rwimg(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_RWIMG:
    case Brig::BRIG_TYPE_WOIMG:
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

bool InstValidator::check_type_values_s16_u16(unsigned val)
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

bool InstValidator::check_type_values_s32_s64(unsigned val)
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

bool InstValidator::check_type_values_s64_u64(unsigned val)
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

bool InstValidator::check_type_values_s64x(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_S64X2:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_s8_u8(unsigned val)
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

bool InstValidator::check_type_values_sig32(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_SIG32:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_sig32_sig64(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_SIG32:
    case Brig::BRIG_TYPE_SIG64:
        return true;
    default:
        return false;
    }
}

bool InstValidator::check_type_values_sig64(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_TYPE_SIG64:
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

bool InstValidator::check_width_values_any1(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_WIDTH_1024:
    case Brig::BRIG_WIDTH_1048576:
    case Brig::BRIG_WIDTH_1073741824:
    case Brig::BRIG_WIDTH_128:
    case Brig::BRIG_WIDTH_131072:
    case Brig::BRIG_WIDTH_134217728:
    case Brig::BRIG_WIDTH_16384:
    case Brig::BRIG_WIDTH_16777216:
    case Brig::BRIG_WIDTH_16:
    case Brig::BRIG_WIDTH_1:
    case Brig::BRIG_WIDTH_2048:
    case Brig::BRIG_WIDTH_2097152:
    case Brig::BRIG_WIDTH_2147483648:
    case Brig::BRIG_WIDTH_256:
    case Brig::BRIG_WIDTH_262144:
    case Brig::BRIG_WIDTH_268435456:
    case Brig::BRIG_WIDTH_2:
    case Brig::BRIG_WIDTH_32768:
    case Brig::BRIG_WIDTH_32:
    case Brig::BRIG_WIDTH_33554432:
    case Brig::BRIG_WIDTH_4096:
    case Brig::BRIG_WIDTH_4194304:
    case Brig::BRIG_WIDTH_4:
    case Brig::BRIG_WIDTH_512:
    case Brig::BRIG_WIDTH_524288:
    case Brig::BRIG_WIDTH_536870912:
    case Brig::BRIG_WIDTH_64:
    case Brig::BRIG_WIDTH_65536:
    case Brig::BRIG_WIDTH_67108864:
    case Brig::BRIG_WIDTH_8192:
    case Brig::BRIG_WIDTH_8388608:
    case Brig::BRIG_WIDTH_8:
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

bool InstValidator::check_width_values_wavesize(unsigned val)
{
    switch(val)
    {
    case Brig::BRIG_WIDTH_WAVESIZE:
        return true;
    default:
        return false;
    }
}

//================================================================================
//  Req activelanecount = {
//      type = u32;
//      stype = b1;
//      width = any_1;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_activelanecount(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_b1(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B1, sizeof(TYPE_VALUES_B1) / sizeof(unsigned));
    }
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req activelaneid = {
//      type = u32;
//      stype = none;
//      width = any_1;
//      d0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_activelaneid(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_none(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req activelanemask = {
//      type = b64;
//      stype = b1;
//      width = any_1;
//      d0 = vec_4;
//      s1 = reg_stype, imm_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_activelanemask(T inst)
{
    if (!check_type_values_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B64, sizeof(TYPE_VALUES_B64) / sizeof(unsigned));
    }
    if (!check_type_values_b1(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B1, sizeof(TYPE_VALUES_B1) / sizeof(unsigned));
    }
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req activelaneshuffle = {
//      type = b1, b32, b64, b128;
//      stype = none;
//      width = any_1;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_u32, imm_u32;
//      s3 = reg, imm;
//      s4 = reg_b1, imm_b1;
//  }
template<class T> bool InstValidator::req_activelaneshuffle(T inst)
{
    if (!check_type_values_b1_b32_b64_b128(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_B32_B64_B128, sizeof(TYPE_VALUES_B1_B32_B64_B128) / sizeof(unsigned));
    }
    if (!check_type_values_none(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_B1, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req add = {
//      type = s32, u32, s64, u64, f, x;
//      {type = s32, u32, s64, u64; ? pack = none; round = none; ftz = none;}
//      {type = f; ? pack = none; round = float; ftz = any;}
//      {type = sx, ux; ? pack = bin; round = none; ftz = none;}
//      {type = fx; ? pack = bin_nosat; round = float; ftz = any;}
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
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else if (
            check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_pack_values_bin(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_BIN, sizeof(PACK_VALUES_BIN) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_pack_values_binnosat(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_BINNOSAT, sizeof(PACK_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req addq = {
//      type = u64;
//      segment = flat, global;
//      memord = any;
//      d0 = reg;
//      s1 = addr_seg;
//      s2 = reg, imm;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_addq(T inst)
{
    if (!check_type_values_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U64, sizeof(TYPE_VALUES_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_flat_global(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_FLAT_GLOBAL, sizeof(SEGMENT_VALUES_FLAT_GLOBAL) / sizeof(unsigned));
    }
    if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
        brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
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
//      segment = private;
//      align = any;
//      const = none;
//      eqclass = 0;
//      width = none;
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
    if (!check_segment_values_private(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_PRIVATE, sizeof(SEGMENT_VALUES_PRIVATE) / sizeof(unsigned));
    }
    if (!check_align_values_any(getAlign<T>(inst))) {
        brigPropError(inst, PROP_ALIGN, getAlign<T>(inst), ALIGN_VALUES_ANY, sizeof(ALIGN_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_const_values_none(getIsConst<T>(inst))) {
        brigPropError(inst, PROP_ISCONST, getIsConst<T>(inst), CONST_VALUES_NONE, sizeof(CONST_VALUES_NONE) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_0, sizeof(EQCLASS_VALUES_0) / sizeof(unsigned));
    if (!check_width_values_none(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_NONE, sizeof(WIDTH_VALUES_NONE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
//      atmop = generic, atomic, exch, ld;
//      segment = global, group, flat;
//      eqclass = any;
//      typesize = atomic;
//      {atmop = cas; ? type = b32, b64; memord = any; s2 = reg, imm; s3 = reg, imm;}
//      {atmop = and, or, xor, exch; ? type = b32, b64; memord = any; s2 = reg, imm; s3 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; memord = any; s2 = reg, imm; s3 = null;}
//      {atmop = wrapinc, wrapdec; ? type = u32, u64; memord = any; s2 = reg, imm; s3 = null;}
//      {atmop = ld; ? type = b32, b64; memord = ld; s2 = null; s3 = null;}
//      ;
//      {segment = global, flat; ? memscp = wv, wg, cmp, sys;}
//      {segment = group; ? memscp = wv, wg;}
//      ;
//      d0 = reg;
//      s1 = addr_seg;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_atomic(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_atmop_values_generic_atomic_exch_ld(getAtomicOperation<T>(inst))) {
        brigPropError(inst, PROP_ATOMICOPERATION, getAtomicOperation<T>(inst), ATMOP_VALUES_GENERIC_ATOMIC_EXCH_LD, sizeof(ATMOP_VALUES_GENERIC_ATOMIC_EXCH_LD) / sizeof(unsigned));
    }
    if (!check_segment_values_global_group_flat(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL_GROUP_FLAT, sizeof(SEGMENT_VALUES_GLOBAL_GROUP_FLAT) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned));

    if (
            check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor_exch(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_ld(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_ld(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_LD, sizeof(MEMORD_VALUES_LD) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATOMICOPERATION);
    }

    if (
            check_segment_values_flat_global(getSegment<T>(inst))
       )
    {
        if (!check_memscp_values_wv_wg_cmp_sys(getMemoryScope<T>(inst))) {
            brigPropError(inst, PROP_MEMORYSCOPE, getMemoryScope<T>(inst), MEMSCP_VALUES_WV_WG_CMP_SYS, sizeof(MEMSCP_VALUES_WV_WG_CMP_SYS) / sizeof(unsigned));
        }
    }
    else if (
            check_segment_values_group(getSegment<T>(inst))
       )
    {
        if (!check_memscp_values_wv_wg(getMemoryScope<T>(inst))) {
            brigPropError(inst, PROP_MEMORYSCOPE, getMemoryScope<T>(inst), MEMSCP_VALUES_WV_WG, sizeof(MEMSCP_VALUES_WV_WG) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_SEGMENT);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req atomic_noret = {
//      type = b32, s32, u32, b64, s64, u64;
//      atmop = generic, atomic, st;
//      segment = global, group, flat;
//      eqclass = any;
//      typesize = atomic;
//      {atmop = cas; ? type = b32, b64; memord = any; s2 = reg, imm;}
//      {atmop = and, or, xor; ? type = b32, b64; memord = any; s2 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; memord = any; s2 = null;}
//      {atmop = wrapinc, wrapdec; ? type = u32, u64; memord = any; s2 = null;}
//      {atmop = st; ? type = b32, b64; memord = st; s2 = null;}
//      ;
//      {segment = global, flat; ? memscp = wv, wg, cmp, sys;}
//      {segment = group; ? memscp = wv, wg;}
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
    if (!check_atmop_values_generic_atomic_st(getAtomicOperation<T>(inst))) {
        brigPropError(inst, PROP_ATOMICOPERATION, getAtomicOperation<T>(inst), ATMOP_VALUES_GENERIC_ATOMIC_ST, sizeof(ATMOP_VALUES_GENERIC_ATOMIC_ST) / sizeof(unsigned));
    }
    if (!check_segment_values_global_group_flat(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL_GROUP_FLAT, sizeof(SEGMENT_VALUES_GLOBAL_GROUP_FLAT) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned));

    if (
            check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_st(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_st(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ST, sizeof(MEMORD_VALUES_ST) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATOMICOPERATION);
    }

    if (
            check_segment_values_flat_global(getSegment<T>(inst))
       )
    {
        if (!check_memscp_values_wv_wg_cmp_sys(getMemoryScope<T>(inst))) {
            brigPropError(inst, PROP_MEMORYSCOPE, getMemoryScope<T>(inst), MEMSCP_VALUES_WV_WG_CMP_SYS, sizeof(MEMSCP_VALUES_WV_WG_CMP_SYS) / sizeof(unsigned));
        }
    }
    else if (
            check_segment_values_group(getSegment<T>(inst))
       )
    {
        if (!check_memscp_values_wv_wg(getMemoryScope<T>(inst))) {
            brigPropError(inst, PROP_MEMORYSCOPE, getMemoryScope<T>(inst), MEMSCP_VALUES_WV_WG, sizeof(MEMSCP_VALUES_WV_WG) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_SEGMENT);
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req barrier = {
//      type = none;
//      width = any_all;
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
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req basic_dst_u32 = {
//      type = u32;
//      d0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_basic_dst_u32(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req basic_dst_u32_dim = {
//      type = u32;
//      d0 = reg;
//      s1 = imm0T2_u32;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_basic_dst_u32_dim(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_U32, OPERAND_VALUES_IMM0T2U32, sizeof(OPERAND_VALUES_IMM0T2U32) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req basic_dst_u32_u64 = {
//      type = u32, u64;
//      d0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_basic_dst_u32_u64(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req basic_dst_u32_u64_dim = {
//      type = u32, u64;
//      d0 = reg;
//      s1 = imm0T2_u32;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_basic_dst_u32_u64_dim(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_U32, OPERAND_VALUES_IMM0T2U32, sizeof(OPERAND_VALUES_IMM0T2U32) / sizeof(unsigned));
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
//      s2 = reg_u32, imm_u32;
//      s3 = reg_u32, imm_u32;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_bitextract(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req bitinsert = {
//      type = s32, u32, s64, u64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = reg_u32, imm_u32;
//      s4 = reg_u32, imm_u32;
//  }
template<class T> bool InstValidator::req_bitinsert(T inst)
{
    if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req bitmask = {
//      type = b32, b64;
//      d0 = reg;
//      s1 = reg_u32, imm_u32;
//      s2 = reg_u32, imm_u32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_bitmask(T inst)
{
    if (!check_type_values_b32_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
//  Req br = {
//      type = none;
//      width = all;
//      s0 = lab;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_br(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_all(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ALL, sizeof(WIDTH_VALUES_ALL) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_LAB, sizeof(OPERAND_VALUES_LAB) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req call = {
//      type = none;
//      width = all;
//      s0 = arglist;
//      s1 = func;
//      s2 = arglist;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_call(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_all(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ALL, sizeof(WIDTH_VALUES_ALL) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_FUNC, sizeof(OPERAND_VALUES_FUNC) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req casq = {
//      type = u64;
//      segment = flat, global;
//      memord = any;
//      d0 = reg;
//      s1 = addr_seg;
//      s2 = reg, imm;
//      s3 = reg, imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_casq(T inst)
{
    if (!check_type_values_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U64, sizeof(TYPE_VALUES_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_flat_global(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_FLAT_GLOBAL, sizeof(SEGMENT_VALUES_FLAT_GLOBAL) / sizeof(unsigned));
    }
    if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
        brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req cbr = {
//      type = b1;
//      width = any_1;
//      s0 = reg, imm;
//      s1 = lab;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_cbr(T inst)
{
    if (!check_type_values_b1(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1, sizeof(TYPE_VALUES_B1) / sizeof(unsigned));
    }
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_LAB, sizeof(OPERAND_VALUES_LAB) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ceil = {
//      type = f, fx;
//      round = none;
//      ftz = any;
//      {type = f; ? pack = none;}
//      {type = fx; ? pack = p, s;}
//      ;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_ceil(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F_FX, sizeof(TYPE_VALUES_F_FX) / sizeof(unsigned));
    }
    validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
    validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));

    if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_pack_values_p_s(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_P_S, sizeof(PACK_VALUES_P_S) / sizeof(unsigned));
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
//      s2 = reg_u32, cnst_u32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_class(T inst)
{
    if (!check_type_values_b1(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1, sizeof(TYPE_VALUES_B1) / sizeof(unsigned));
    }
    if (!check_type_values_f(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_F, sizeof(TYPE_VALUES_F) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_U32, OPERAND_VALUES_REGU32_CNSTU32, sizeof(OPERAND_VALUES_REGU32_CNSTU32) / sizeof(unsigned));
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
//      {type = b1, b32, b64; ? s1 = reg_b1, imm_b1;}
//      {type = x; ? s1 = reg_p2u, imm_p2u;}
//      ;
//  }
template<class T> bool InstValidator::req_cmov(T inst)
{
    if (!check_type_values_b1_b32_b64_x(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_B32_B64_X, sizeof(TYPE_VALUES_B1_B32_B64_X) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            check_type_values_b1_b32_b64(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_B1, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else if (
            check_type_values_x(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_P2U, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    return true;
}

//================================================================================
//  Req cmp = {
//      type = b1, s32, u32, s64, u64, f, ux;
//      stype = b1, b32, s32, u32, b64, s64, u64, f, x;
//      round = none;
//      {stype = b1, b32, s32, u32, b64, s64, u64, f; ? type = b1, s32, u32, s64, u64, f;}
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
//      {stype = b1, b32, b64; ? ftz = none; pack = none; compare = eq, ne;}
//      {stype = s32, u32, s64, u64; ? ftz = none; pack = none; compare = eq, ne, lt, le, gt, ge;}
//      {stype = f; ? ftz = any; pack = none; compare = eq, equ, ge, geu, gt, gtu, le, leu, lt, ltu, nan, ne, neu, num, seq, sequ, sge, sgeu, sgt, sgtu, sle, sleu, slt, sltu, snan, sne, sneu, snum;}
//      {stype = sx, ux; ? ftz = none; pack = pp; compare = eq, ne, lt, le, gt, ge;}
//      {stype = fx; ? ftz = any; pack = pp; compare = eq, equ, ge, geu, gt, gtu, le, leu, lt, ltu, nan, ne, neu, num, seq, sequ, sge, sgeu, sgt, sgtu, sle, sleu, slt, sltu, snan, sne, sneu, snum;}
//      ;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = reg_stype, imm_stype;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_cmp(T inst)
{
    if (!check_type_values_b1_s32_u32_s64_u64_f_ux(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_S32_U32_S64_U64_F_UX, sizeof(TYPE_VALUES_B1_S32_U32_S64_U64_F_UX) / sizeof(unsigned));
    }
    if (!check_type_values_b1_b32_s32_u32_b64_s64_u64_f_x(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_X, sizeof(TYPE_VALUES_B1_B32_S32_U32_B64_S64_U64_F_X) / sizeof(unsigned));
    }
    validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));

    if (
            check_type_values_b1_b32_s32_u32_b64_s64_u64_f(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_b1_s32_u32_s64_u64_f(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_S32_U32_S64_U64_F, sizeof(TYPE_VALUES_B1_S32_U32_S64_U64_F) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s8x4_u8x4(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_u8x4(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X4, sizeof(TYPE_VALUES_U8X4) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s8x8_u8x8(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_u8x8(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X8, sizeof(TYPE_VALUES_U8X8) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s8x16_u8x16(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_u8x16(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U8X16, sizeof(TYPE_VALUES_U8X16) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s16x2_u16x2_f16x2(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_u16x2(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U16X2, sizeof(TYPE_VALUES_U16X2) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s16x4_u16x4_f16x4(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_u16x4(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U16X4, sizeof(TYPE_VALUES_U16X4) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s16x8_u16x8_f16x8(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_u16x8(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U16X8, sizeof(TYPE_VALUES_U16X8) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s32x2_u32x2_f32x2(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_u32x2(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32X2, sizeof(TYPE_VALUES_U32X2) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s32x4_u32x4_f32x4(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_u32x4(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32X4, sizeof(TYPE_VALUES_U32X4) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s64x2_u64x2_f64x2(getSourceType<T>(inst))
       )
    {
        if (!check_type_values_u64x2(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U64X2, sizeof(TYPE_VALUES_U64X2) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_SOURCETYPE);
    }

    if (
            check_type_values_b1_b32_b64(getSourceType<T>(inst))
       )
    {
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_compare_values_eq_ne(getCompare<T>(inst))) {
            brigPropError(inst, PROP_COMPARE, getCompare<T>(inst), COMPARE_VALUES_EQ_NE, sizeof(COMPARE_VALUES_EQ_NE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s32_u32_s64_u64(getSourceType<T>(inst))
       )
    {
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_compare_values_eq_ne_lt_le_gt_ge(getCompare<T>(inst))) {
            brigPropError(inst, PROP_COMPARE, getCompare<T>(inst), COMPARE_VALUES_EQ_NE_LT_LE_GT_GE, sizeof(COMPARE_VALUES_EQ_NE_LT_LE_GT_GE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f(getSourceType<T>(inst))
       )
    {
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_compare_values_0(getCompare<T>(inst))) {
            brigPropError(inst, PROP_COMPARE, getCompare<T>(inst), COMPARE_VALUES_0, sizeof(COMPARE_VALUES_0) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_sx_ux(getSourceType<T>(inst))
       )
    {
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
        if (!check_pack_values_pp(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_PP, sizeof(PACK_VALUES_PP) / sizeof(unsigned));
        }
        if (!check_compare_values_eq_ne_lt_le_gt_ge(getCompare<T>(inst))) {
            brigPropError(inst, PROP_COMPARE, getCompare<T>(inst), COMPARE_VALUES_EQ_NE_LT_LE_GT_GE, sizeof(COMPARE_VALUES_EQ_NE_LT_LE_GT_GE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getSourceType<T>(inst))
       )
    {
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
        if (!check_pack_values_pp(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_PP, sizeof(PACK_VALUES_PP) / sizeof(unsigned));
        }
        if (!check_compare_values_0(getCompare<T>(inst))) {
            brigPropError(inst, PROP_COMPARE, getCompare<T>(inst), COMPARE_VALUES_0, sizeof(COMPARE_VALUES_0) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_SOURCETYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req combine = {
//      type = b64, b128;
//      stype = b32, b64;
//      {type = b64; stype = b32; ? s1 = vec_2_stype;}
//      {type = b128; stype = b64; ? s1 = vec_2_stype;}
//      {type = b128; stype = b32; ? s1 = vec_4_stype;}
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
    if (!check_type_values_b32_b64(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
    }

    if (
            check_type_values_b64(getType<T>(inst)) &&
            check_type_values_b32(getSourceType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128(getType<T>(inst)) &&
            check_type_values_b64(getSourceType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128(getType<T>(inst)) &&
            check_type_values_b32(getSourceType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_SOURCETYPE, PROP_TYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req copysign = {
//      type = f, fx;
//      round = none;
//      ftz = none;
//      {type = f; ? pack = none;}
//      {type = fx; ? pack = bin_nosat;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_copysign(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F_FX, sizeof(TYPE_VALUES_F_FX) / sizeof(unsigned));
    }
    validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
    validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));

    if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_pack_values_binnosat(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_BINNOSAT, sizeof(PACK_VALUES_BINNOSAT) / sizeof(unsigned));
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
//  Req cvt = {
//      type = b1, s, u, f;
//      stype = b1, s, u, f;
//      {type = b1; ? stype = s, u, f;}
//      {type = s8, u8; ? stype = b1, s16, u16, s32, u32, s64, u64, f;}
//      {type = s16, u16; ? stype = b1, s8, u8, s32, u32, s64, u64, f;}
//      {type = s32, u32; ? stype = b1, s8, u8, s16, u16, s64, u64, f;}
//      {type = s64, u64; ? stype = b1, s8, u8, s16, u16, s32, u32, f;}
//      {type = f16; ? stype = b1, b128, b16, b32, b64, b8, f16x2, f16x4, f16x8, f32, f32x2, f32x4, f64, f64x2, none, roimg, rwimg, s16, s16x2, s16x4, s16x8, s32, s32x2, s32x4, s64, s64x2, s8, s8x16, s8x4, s8x8, samp, sig32, sig64, u16, u16x2, u16x4, u16x8, u32, u32x2, u32x4, u64, u64x2, u8, u8x16, u8x4, u8x8, woimg;}
//      {type = f32; ? stype = b1, b128, b16, b32, b64, b8, f16, f16x2, f16x4, f16x8, f32x2, f32x4, f64, f64x2, none, roimg, rwimg, s16, s16x2, s16x4, s16x8, s32, s32x2, s32x4, s64, s64x2, s8, s8x16, s8x4, s8x8, samp, sig32, sig64, u16, u16x2, u16x4, u16x8, u32, u32x2, u32x4, u64, u64x2, u8, u8x16, u8x4, u8x8, woimg;}
//      {type = f64; ? stype = b1, b128, b16, b32, b64, b8, f16, f16x2, f16x4, f16x8, f32, f32x2, f32x4, f64x2, none, roimg, rwimg, s16, s16x2, s16x4, s16x8, s32, s32x2, s32x4, s64, s64x2, s8, s8x16, s8x4, s8x8, samp, sig32, sig64, u16, u16x2, u16x4, u16x8, u32, u32x2, u32x4, u64, u64x2, u8, u8x16, u8x4, u8x8, woimg;}
//      ;
//      {stype = b1, s, u; type = b1, s, u; ? round = none; ftz = none;}
//      {stype = b1; type = f; ? round = none; ftz = none;}
//      {stype = s, u; type = f; ? round = float; ftz = none;}
//      {stype = f; type = b1; ? round = none; ftz = any;}
//      {stype = f; type = s, u; ? round = int; ftz = any;}
//      {stype = f32; type = f16; ? round = float; ftz = any;}
//      {stype = f64; type = f16, f32; ? round = float; ftz = any;}
//      {stype = f; type = f; ? round = none; ftz = any;}
//      ;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_cvt(T inst)
{
    if (!check_type_values_b1_s_u_f(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_S_U_F, sizeof(TYPE_VALUES_B1_S_U_F) / sizeof(unsigned));
    }
    if (!check_type_values_b1_s_u_f(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B1_S_U_F, sizeof(TYPE_VALUES_B1_S_U_F) / sizeof(unsigned));
    }

    if (
            check_type_values_b1(getType<T>(inst))
       )
    {
        if (!check_type_values_s_u_f(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_S_U_F, sizeof(TYPE_VALUES_S_U_F) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s8_u8(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s16_u16_s32_u32_s64_u64_f(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B1_S16_U16_S32_U32_S64_U64_F, sizeof(TYPE_VALUES_B1_S16_U16_S32_U32_S64_U64_F) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s16_u16(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s8_u8_s32_u32_s64_u64_f(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B1_S8_U8_S32_U32_S64_U64_F, sizeof(TYPE_VALUES_B1_S8_U8_S32_U32_S64_U64_F) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s32_u32(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s8_u8_s16_u16_s64_u64_f(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B1_S8_U8_S16_U16_S64_U64_F, sizeof(TYPE_VALUES_B1_S8_U8_S16_U16_S64_U64_F) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s64_u64(getType<T>(inst))
       )
    {
        if (!check_type_values_b1_s8_u8_s16_u16_s32_u32_f(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B1_S8_U8_S16_U16_S32_U32_F, sizeof(TYPE_VALUES_B1_S8_U8_S16_U16_S32_U32_F) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f16(getType<T>(inst))
       )
    {
        if (!check_type_values_0(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_0, sizeof(TYPE_VALUES_0) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f32(getType<T>(inst))
       )
    {
        if (!check_type_values_1(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_1, sizeof(TYPE_VALUES_1) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f64(getType<T>(inst))
       )
    {
        if (!check_type_values_2(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_2, sizeof(TYPE_VALUES_2) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }

    if (
            check_type_values_b1_s_u(getSourceType<T>(inst)) &&
            check_type_values_b1_s_u(getType<T>(inst))
       )
    {
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_b1(getSourceType<T>(inst)) &&
            check_type_values_f(getType<T>(inst))
       )
    {
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_s_u(getSourceType<T>(inst)) &&
            check_type_values_f(getType<T>(inst))
       )
    {
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_f(getSourceType<T>(inst)) &&
            check_type_values_b1(getType<T>(inst))
       )
    {
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else if (
            check_type_values_f(getSourceType<T>(inst)) &&
            check_type_values_s_u(getType<T>(inst))
       )
    {
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_INT, sizeof(ROUND_VALUES_INT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else if (
            check_type_values_f32(getSourceType<T>(inst)) &&
            check_type_values_f16(getType<T>(inst))
       )
    {
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else if (
            check_type_values_f64(getSourceType<T>(inst)) &&
            check_type_values_f16_f32(getType<T>(inst))
       )
    {
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else if (
            check_type_values_f(getSourceType<T>(inst)) &&
            check_type_values_f(getType<T>(inst))
       )
    {
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_SOURCETYPE, PROP_TYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req debugtrap = {
//      type = u32;
//      s0 = reg, imm;
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
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req div = {
//      type = s32, u32, s64, u64, f, fx;
//      {type = s32, u32, s64, u64; ? pack = none; round = none; ftz = none;}
//      {type = f; ? pack = none; round = float; ftz = any;}
//      {type = fx; ? pack = bin_nosat; round = float; ftz = any;}
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
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_pack_values_binnosat(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_BINNOSAT, sizeof(PACK_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
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
//      {type = b32; stype = b64; ? d0 = vec_2;}
//      {type = b32; stype = b128; ? d0 = vec_4;}
//      {type = b64; stype = b128; ? d0 = vec_2;}
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
    if (!check_type_values_b64_b128(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B64_B128, sizeof(TYPE_VALUES_B64_B128) / sizeof(unsigned));
    }

    if (
            check_type_values_b32(getType<T>(inst)) &&
            check_type_values_b64(getSourceType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else if (
            check_type_values_b32(getType<T>(inst)) &&
            check_type_values_b128(getSourceType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
    }
    else if (
            check_type_values_b64(getType<T>(inst)) &&
            check_type_values_b128(getSourceType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_SOURCETYPE, PROP_TYPE);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req f2s = {
//      type = u32, u64;
//      stype = u32, u64;
//      segment = global, group, private;
//      nonull = any;
//      typesize = seg;
//      stypesize = model;
//      d0 = reg;
//      s1 = reg_stype, cnst_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_f2s(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_type_values_u32_u64(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_global_group_private(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE, sizeof(SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE) / sizeof(unsigned));
    }
    if (!check_nonull_values_any(getIsNoNull<T>(inst))) {
        brigPropError(inst, PROP_ISNONULL, getIsNoNull<T>(inst), NONULL_VALUES_ANY, sizeof(NONULL_VALUES_ANY) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned));
    validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_MODEL, sizeof(STYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGU32_CNSTU32, sizeof(OPERAND_VALUES_REGU32_CNSTU32) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req fbar_none = {
//      type = none;
//      s0 = reg_u32, fbarrier_u32;
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
    validateOperand(inst, PROP_S0, OPERAND_ATTR_U32, OPERAND_VALUES_REGU32_FBARRIERU32, sizeof(OPERAND_VALUES_REGU32_FBARRIERU32) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req fbar_width = {
//      type = none;
//      width = any_ws;
//      s0 = reg_u32, fbarrier_u32;
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
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_U32, OPERAND_VALUES_REGU32_FBARRIERU32, sizeof(OPERAND_VALUES_REGU32_FBARRIERU32) / sizeof(unsigned));
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
    if (!check_type_values_s32_u32_s64_u64(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req fma = {
//      type = f;
//      pack = none;
//      round = float;
//      ftz = any;
//      d0_s1_s2_s3;
//  }
template<class T> bool InstValidator::req_fma(T inst)
{
    if (!check_type_values_f(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F, sizeof(TYPE_VALUES_F) / sizeof(unsigned));
    }
    if (!check_pack_values_none(getPackEx<T>(inst))) {
        brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
    }
    validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
    validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    req_d0_s1_s2_s3(inst);
    return true;
}

//================================================================================
//  Req fract = {
//      type = f, fx;
//      round = none;
//      ftz = any;
//      {type = f; ? pack = none;}
//      {type = fx; ? pack = p, s;}
//      ;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_fract(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F_FX, sizeof(TYPE_VALUES_F_FX) / sizeof(unsigned));
    }
    validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
    validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));

    if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_pack_values_p_s(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_P_S, sizeof(PACK_VALUES_P_S) / sizeof(unsigned));
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_atomic = {
//      type = b32, s32, u32, b64, s64, u64;
//      atmop = generic, atomic, exch, ld;
//      segment = gcn;
//      memscp = wv, wg, cmp, sys;
//      eqclass = any;
//      typesize = atomic;
//      {atmop = cas; ? type = b32, b64; memord = any; s2 = reg, imm; s3 = reg, imm;}
//      {atmop = and, or, xor, exch; ? type = b32, b64; memord = any; s2 = reg, imm; s3 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; memord = any; s2 = reg, imm; s3 = null;}
//      {atmop = wrapinc, wrapdec; ? type = u32, u64; memord = any; s2 = reg, imm; s3 = null;}
//      {atmop = ld; ? type = b32, b64; memord = ld; s2 = null; s3 = null;}
//      ;
//      d0 = reg;
//      s1 = addr_seg;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_atomic(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_atmop_values_generic_atomic_exch_ld(getAtomicOperation<T>(inst))) {
        brigPropError(inst, PROP_ATOMICOPERATION, getAtomicOperation<T>(inst), ATMOP_VALUES_GENERIC_ATOMIC_EXCH_LD, sizeof(ATMOP_VALUES_GENERIC_ATOMIC_EXCH_LD) / sizeof(unsigned));
    }
    if (!check_segment_values_gcn(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GCN, sizeof(SEGMENT_VALUES_GCN) / sizeof(unsigned));
    }
    if (!check_memscp_values_wv_wg_cmp_sys(getMemoryScope<T>(inst))) {
        brigPropError(inst, PROP_MEMORYSCOPE, getMemoryScope<T>(inst), MEMSCP_VALUES_WV_WG_CMP_SYS, sizeof(MEMSCP_VALUES_WV_WG_CMP_SYS) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned));

    if (
            check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor_exch(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_ld(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_ld(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_LD, sizeof(MEMORD_VALUES_LD) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATOMICOPERATION);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_atomic_noret = {
//      type = b32, s32, u32, b64, s64, u64;
//      atmop = generic, atomic, st;
//      segment = gcn;
//      memscp = wv, wg, cmp, sys;
//      eqclass = any;
//      typesize = atomic;
//      {atmop = cas; ? type = b32, b64; memord = any; s2 = reg, imm;}
//      {atmop = and, or, xor; ? type = b32, b64; memord = any; s2 = null;}
//      {atmop = add, sub, min, max; ? type = s32, u32, s64, u64; memord = any; s2 = null;}
//      {atmop = wrapinc, wrapdec; ? type = u32, u64; memord = any; s2 = null;}
//      {atmop = st; ? type = b32, b64; memord = st; s2 = null;}
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
    if (!check_atmop_values_generic_atomic_st(getAtomicOperation<T>(inst))) {
        brigPropError(inst, PROP_ATOMICOPERATION, getAtomicOperation<T>(inst), ATMOP_VALUES_GENERIC_ATOMIC_ST, sizeof(ATMOP_VALUES_GENERIC_ATOMIC_ST) / sizeof(unsigned));
    }
    if (!check_segment_values_gcn(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GCN, sizeof(SEGMENT_VALUES_GCN) / sizeof(unsigned));
    }
    if (!check_memscp_values_wv_wg_cmp_sys(getMemoryScope<T>(inst))) {
        brigPropError(inst, PROP_MEMORYSCOPE, getMemoryScope<T>(inst), MEMSCP_VALUES_WV_WG_CMP_SYS, sizeof(MEMSCP_VALUES_WV_WG_CMP_SYS) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_ATOMIC, sizeof(TYPESIZE_VALUES_ATOMIC) / sizeof(unsigned));

    if (
            check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_u32_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_st(getAtomicOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_st(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ST, sizeof(MEMORD_VALUES_ST) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_ATOMICOPERATION);
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_b4xchg = {
//      type = b32;
//      d0 = reg;
//      s1 = reg;
//      s2 = imm;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_b4xchg(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_bfm = {
//      type = b32;
//      d0 = reg;
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_div_relaxed = {
//      type = f32;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_gcn_div_relaxed(T inst)
{
    if (!check_type_values_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F32, sizeof(TYPE_VALUES_F32) / sizeof(unsigned));
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req gcn_fldexp = {
//      type = f32, f64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_s32, imm_s32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_fldexp(T inst)
{
    if (!check_type_values_f32_f64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F32_F64, sizeof(TYPE_VALUES_F32_F64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_S32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_frexp_exp = {
//      type = f32, f64;
//      d0 = reg_s32;
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_S32, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_ld = {
//      type = u, s, f, b128;
//      segment = gcn;
//      align = any;
//      const = none;
//      eqclass = any;
//      width = any_1;
//      {type = u, s, f; ? d0 = reg, vector;}
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
    if (!check_align_values_any(getAlign<T>(inst))) {
        brigPropError(inst, PROP_ALIGN, getAlign<T>(inst), ALIGN_VALUES_ANY, sizeof(ALIGN_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_const_values_none(getIsConst<T>(inst))) {
        brigPropError(inst, PROP_ISCONST, getIsConst<T>(inst), CONST_VALUES_NONE, sizeof(CONST_VALUES_NONE) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }

    if (
            check_type_values_s_u_f(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG_VECTOR, sizeof(OPERAND_VALUES_REG_VECTOR) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_TSEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_mads = {
//      type = b32;
//      d0 = reg_s64;
//      s1 = reg_s32, imm_s32;
//      s2 = reg_s32, imm_s32;
//      s3 = reg_s64, imm_s64;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_mads(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_S64, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_S32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_S32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_S64, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_madu = {
//      type = b32;
//      d0 = reg_u64;
//      s1 = reg_u32, imm_u32;
//      s2 = reg_u32, imm_u32;
//      s3 = reg_u64, imm_u64;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_madu(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_U64, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_U64, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_min_max = {
//      type = s32, u32, f32, f64;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_gcn_min_max(T inst)
{
    if (!check_type_values_s32_u32_f32_f64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_F32_F64, sizeof(TYPE_VALUES_S32_U32_F32_F64) / sizeof(unsigned));
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req gcn_min_max_med3 = {
//      type = s32, u32, f32;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg, imm;
//      s3 = reg, imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_min_max_med3(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_F32, sizeof(TYPE_VALUES_S32_U32_F32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_mqsad = {
//      type = b64;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_b32, imm_b32;
//      s3 = reg;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_mqsad(T inst)
{
    if (!check_type_values_b64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B64, sizeof(TYPE_VALUES_B64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_B32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_mqsad4 = {
//      type = b32;
//      d0 = vec_4;
//      s1 = reg_b64, imm_b64;
//      s2 = reg, imm;
//      s3 = vec_4;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_mqsad4(T inst)
{
    if (!check_type_values_b32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32, sizeof(TYPE_VALUES_B32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_B64, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req gcn_region_alloc = {
//      type = b32;
//      s0 = imm_u32;
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
    validateOperand(inst, PROP_S0, OPERAND_ATTR_U32, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned));
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
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
//      align = any;
//      const = none;
//      eqclass = any;
//      width = none;
//      s1 = addr_tseg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//      {type = u, s, f; ? s0 = reg, vector, imm;}
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
    if (!check_align_values_any(getAlign<T>(inst))) {
        brigPropError(inst, PROP_ALIGN, getAlign<T>(inst), ALIGN_VALUES_ANY, sizeof(ALIGN_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_const_values_none(getIsConst<T>(inst))) {
        brigPropError(inst, PROP_ISCONST, getIsConst<T>(inst), CONST_VALUES_NONE, sizeof(CONST_VALUES_NONE) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    if (!check_width_values_none(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_NONE, sizeof(WIDTH_VALUES_NONE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_TSEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            check_type_values_s_u_f(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG_VECTOR_IMM, sizeof(OPERAND_VALUES_REG_VECTOR_IMM) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
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
//      s2 = imm_u32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_gcn_trig_preop(T inst)
{
    if (!check_type_values_f64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F64, sizeof(TYPE_VALUES_F64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_U32, OPERAND_VALUES_IMM, sizeof(OPERAND_VALUES_IMM) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req icall = {
//      type = u32, u64;
//      width = any_1;
//      typesize = model;
//      s0 = arglist;
//      s1 = reg;
//      s2 = arglist;
//      s3 = signature;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_icall(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_SIGNATURE, sizeof(OPERAND_VALUES_SIGNATURE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ld = {
//      type = u, s, f, b128, opaque;
//      segment = any;
//      align = any;
//      const = any;
//      eqclass = any;
//      width = any_1;
//      {type = u, s, f; ? d0 = reg, vector;}
//      {type = b128, opaque; ? d0 = reg;}
//      ;
//      {segment = global, flat; ? const = any;}
//      {segment = group, private, readonly, kernarg, spill, arg; ? const = none;}
//      ;
//      s1 = addr_tseg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ld(T inst)
{
    if (!check_type_values_u_s_f_b128_opaque(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U_S_F_B128_OPAQUE, sizeof(TYPE_VALUES_U_S_F_B128_OPAQUE) / sizeof(unsigned));
    }
    if (!check_segment_values_any(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_ANY, sizeof(SEGMENT_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_align_values_any(getAlign<T>(inst))) {
        brigPropError(inst, PROP_ALIGN, getAlign<T>(inst), ALIGN_VALUES_ANY, sizeof(ALIGN_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_const_values_any(getIsConst<T>(inst))) {
        brigPropError(inst, PROP_ISCONST, getIsConst<T>(inst), CONST_VALUES_ANY, sizeof(CONST_VALUES_ANY) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }

    if (
            check_type_values_s_u_f(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG_VECTOR, sizeof(OPERAND_VALUES_REG_VECTOR) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128_opaque(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }

    if (
            check_segment_values_flat_global(getSegment<T>(inst))
       )
    {
        if (!check_const_values_any(getIsConst<T>(inst))) {
            brigPropError(inst, PROP_ISCONST, getIsConst<T>(inst), CONST_VALUES_ANY, sizeof(CONST_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_segment_values_group_private_readonly_kernarg_spill_arg(getSegment<T>(inst))
       )
    {
        if (!check_const_values_none(getIsConst<T>(inst))) {
            brigPropError(inst, PROP_ISCONST, getIsConst<T>(inst), CONST_VALUES_NONE, sizeof(CONST_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_SEGMENT);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_TSEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ld_image = {
//      ld_st_image;
//      itype = roimg, rwimg;
//      {geometry = 1d, 1db; ? d0 = vec_4; s2 = reg_ctype;}
//      {geometry = 2d, 1da; ? d0 = vec_4; s2 = vec_2_ctype;}
//      {geometry = 3d, 2da; ? d0 = vec_4; s2 = vec_3_ctype;}
//      {geometry = 2ddepth; ? d0 = reg; s2 = vec_2_ctype;}
//      {geometry = 2dadepth; ? d0 = reg; s2 = vec_3_ctype;}
//      ;
//      s1 = reg_itype;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ld_image(T inst)
{
    req_ld_st_image(inst);
    if (!check_type_values_roimg_rwimg(getImageType<T>(inst))) {
        brigPropError(inst, PROP_IMAGETYPE, getImageType<T>(inst), TYPE_VALUES_ROIMG_RWIMG, sizeof(TYPE_VALUES_ROIMG_RWIMG) / sizeof(unsigned));
    }

    if (
            check_geometry_values_1d_1db(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_2d_1da(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_3d_2da(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC3CTYPE, sizeof(OPERAND_VALUES_VEC3CTYPE) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_2ddepth(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_2dadepth(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC3CTYPE, sizeof(OPERAND_VALUES_VEC3CTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_GEOMETRY);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_ITYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ld_st_image = {
//      type = s32, u32, f32;
//      ctype = u32;
//      geometry = any;
//      eqclass = any;
//  }
template<class T> bool InstValidator::req_ld_st_image(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_F32, sizeof(TYPE_VALUES_S32_U32_F32) / sizeof(unsigned));
    }
    if (!check_type_values_u32(getCoordType<T>(inst))) {
        brigPropError(inst, PROP_COORDTYPE, getCoordType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_geometry_values_any(getGeometry<T>(inst))) {
        brigPropError(inst, PROP_GEOMETRY, getGeometry<T>(inst), GEOMETRY_VALUES_ANY, sizeof(GEOMETRY_VALUES_ANY) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req lda = {
//      type = u32, u64;
//      segment = global, group, private, flat, kernarg, readonly;
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
    if (!check_segment_values_global_group_private_flat_kernarg_readonly(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE_FLAT_KERNARG_READONLY, sizeof(SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE_FLAT_KERNARG_READONLY) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ldf = {
//      type = u32;
//      s0 = reg;
//      s1 = fbarrier_u32;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ldf(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_U32, OPERAND_VALUES_FBARRIERU32, sizeof(OPERAND_VALUES_FBARRIERU32) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ldi = {
//      type = u32, u64;
//      typesize = model;
//      d0 = reg;
//      s1 = ifunc;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ldi(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_IFUNC, sizeof(OPERAND_VALUES_IFUNC) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ldk = {
//      type = u32, u64;
//      typesize = model;
//      d0 = reg;
//      s1 = kernel;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ldk(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_KERNEL, sizeof(OPERAND_VALUES_KERNEL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ldq = {
//      type = u64;
//      segment = flat, global;
//      memord = rlx, acq;
//      d0 = reg;
//      s1 = addr_seg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ldq(T inst)
{
    if (!check_type_values_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U64, sizeof(TYPE_VALUES_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_flat_global(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_FLAT_GLOBAL, sizeof(SEGMENT_VALUES_FLAT_GLOBAL) / sizeof(unsigned));
    }
    if (!check_memord_values_ld(getMemoryOrder<T>(inst))) {
        brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_LD, sizeof(MEMORD_VALUES_LD) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
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
//  Req max = {
//      type = s32, u32, s64, u64, f, x;
//      round = none;
//      {type = s32, u32, s64, u64; ? pack = none; ftz = none;}
//      {type = f; ? pack = none; ftz = any;}
//      {type = sx, ux; ? pack = bin_nosat; ftz = none;}
//      {type = fx; ? pack = bin_nosat; ftz = any;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_max(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F_X, sizeof(TYPE_VALUES_S32_U32_S64_U64_F_X) / sizeof(unsigned));
    }
    validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));

    if (
            check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else if (
            check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_pack_values_binnosat(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_BINNOSAT, sizeof(PACK_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_pack_values_binnosat(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_BINNOSAT, sizeof(PACK_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    req_d0_s1_s2(inst);
    return true;
}

//================================================================================
//  Req memfence = {
//      type = none;
//      memord = acq, rel, ar;
//      memscpglobal = none, wv, wg, cmp, sys;
//      memscpgroup = none, wv, wg;
//      memscpimage = none, wi, wv, wg;
//      {memscpimage = none; ? }
//      {memscpimage = wi, wv, wg; ? memscpglobal = none; memscpgroup = none; memord = ar;}
//      ;
//      {memscpglobal = none; memscpgroup = none; ? memscpimage = wi, wv, wg;}
//      {memscpimage = none; memscpgroup = none; ? memscpglobal = wv, wg, cmp, sys;}
//      {memscpglobal = none; memscpimage = none; ? memscpgroup = wv, wg;}
//      {memscpimage = none, wi, wv, wg; ? }
//      ;
//      s0 = null;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_memfence(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_memord_values_acq_rel_ar(getMemoryOrder<T>(inst))) {
        brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ACQ_REL_AR, sizeof(MEMORD_VALUES_ACQ_REL_AR) / sizeof(unsigned));
    }
    if (!check_memscp_values_none_wv_wg_cmp_sys(getGlobalSegmentMemoryScope<T>(inst))) {
        brigPropError(inst, PROP_GLOBALSEGMENTMEMORYSCOPE, getGlobalSegmentMemoryScope<T>(inst), MEMSCP_VALUES_NONE_WV_WG_CMP_SYS, sizeof(MEMSCP_VALUES_NONE_WV_WG_CMP_SYS) / sizeof(unsigned));
    }
    if (!check_memscp_values_none_wv_wg(getGroupSegmentMemoryScope<T>(inst))) {
        brigPropError(inst, PROP_GROUPSEGMENTMEMORYSCOPE, getGroupSegmentMemoryScope<T>(inst), MEMSCP_VALUES_NONE_WV_WG, sizeof(MEMSCP_VALUES_NONE_WV_WG) / sizeof(unsigned));
    }
    if (!check_memscp_values_none_wi_wv_wg(getImageSegmentMemoryScope<T>(inst))) {
        brigPropError(inst, PROP_IMAGESEGMENTMEMORYSCOPE, getImageSegmentMemoryScope<T>(inst), MEMSCP_VALUES_NONE_WI_WV_WG, sizeof(MEMSCP_VALUES_NONE_WI_WV_WG) / sizeof(unsigned));
    }

    if (
            check_memscp_values_none(getImageSegmentMemoryScope<T>(inst))
       )
    {
        }
    else if (
            check_memscp_values_wi_wv_wg(getImageSegmentMemoryScope<T>(inst))
       )
    {
        if (!check_memscp_values_none(getGlobalSegmentMemoryScope<T>(inst))) {
            brigPropError(inst, PROP_GLOBALSEGMENTMEMORYSCOPE, getGlobalSegmentMemoryScope<T>(inst), MEMSCP_VALUES_NONE, sizeof(MEMSCP_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_memscp_values_none(getGroupSegmentMemoryScope<T>(inst))) {
            brigPropError(inst, PROP_GROUPSEGMENTMEMORYSCOPE, getGroupSegmentMemoryScope<T>(inst), MEMSCP_VALUES_NONE, sizeof(MEMSCP_VALUES_NONE) / sizeof(unsigned));
        }
        if (!check_memord_values_ar(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_AR, sizeof(MEMORD_VALUES_AR) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_IMAGESEGMENTMEMORYSCOPE);
    }

    if (
            check_memscp_values_none(getGlobalSegmentMemoryScope<T>(inst)) &&
            check_memscp_values_none(getGroupSegmentMemoryScope<T>(inst))
       )
    {
        if (!check_memscp_values_wi_wv_wg(getImageSegmentMemoryScope<T>(inst))) {
            brigPropError(inst, PROP_IMAGESEGMENTMEMORYSCOPE, getImageSegmentMemoryScope<T>(inst), MEMSCP_VALUES_WI_WV_WG, sizeof(MEMSCP_VALUES_WI_WV_WG) / sizeof(unsigned));
        }
    }
    else if (
            check_memscp_values_none(getImageSegmentMemoryScope<T>(inst)) &&
            check_memscp_values_none(getGroupSegmentMemoryScope<T>(inst))
       )
    {
        if (!check_memscp_values_wv_wg_cmp_sys(getGlobalSegmentMemoryScope<T>(inst))) {
            brigPropError(inst, PROP_GLOBALSEGMENTMEMORYSCOPE, getGlobalSegmentMemoryScope<T>(inst), MEMSCP_VALUES_WV_WG_CMP_SYS, sizeof(MEMSCP_VALUES_WV_WG_CMP_SYS) / sizeof(unsigned));
        }
    }
    else if (
            check_memscp_values_none(getGlobalSegmentMemoryScope<T>(inst)) &&
            check_memscp_values_none(getImageSegmentMemoryScope<T>(inst))
       )
    {
        if (!check_memscp_values_wv_wg(getGroupSegmentMemoryScope<T>(inst))) {
            brigPropError(inst, PROP_GROUPSEGMENTMEMORYSCOPE, getGroupSegmentMemoryScope<T>(inst), MEMSCP_VALUES_WV_WG, sizeof(MEMSCP_VALUES_WV_WG) / sizeof(unsigned));
        }
    }
    else if (
            check_memscp_values_none_wi_wv_wg(getImageSegmentMemoryScope<T>(inst))
       )
    {
        }
    else 
    {
        invalidVariant(inst, PROP_GLOBALSEGMENTMEMORYSCOPE, PROP_GROUPSEGMENTMEMORYSCOPE, PROP_IMAGESEGMENTMEMORYSCOPE);
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req mov = {
//      type = b1, b32, b64, b128, s32, u32, s64, u64, f, opaque;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//      {type = b1, b32, b64, b128, s32, u32, s64, u64, f; ? s1 = reg, imm;}
//      {type = opaque; ? s1 = reg;}
//      ;
//  }
template<class T> bool InstValidator::req_mov(T inst)
{
    if (!check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f_opaque(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_OPAQUE, sizeof(TYPE_VALUES_B1_B32_B64_B128_S32_U32_S64_U64_F_OPAQUE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            check_type_values_b1_b32_b64_b128_s32_u32_s64_u64_f(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else if (
            check_type_values_opaque(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    return true;
}

//================================================================================
//  Req mul = {
//      type = s32, u32, s64, u64, f, x;
//      {type = s32, u32, s64, u64; ? pack = none; round = none; ftz = none;}
//      {type = f; ? pack = none; round = float; ftz = any;}
//      {type = sx, ux; ? pack = bin; round = none; ftz = none;}
//      {type = fx; ? pack = bin_nosat; round = float; ftz = any;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_mul(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f_x(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F_X, sizeof(TYPE_VALUES_S32_U32_S64_U64_F_X) / sizeof(unsigned));
    }

    if (
            check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
    }
    else if (
            check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_pack_values_bin(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_BIN, sizeof(PACK_VALUES_BIN) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_pack_values_binnosat(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_BINNOSAT, sizeof(PACK_VALUES_BINNOSAT) / sizeof(unsigned));
        }
        validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
        validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));
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
//      round = none;
//      ftz = none;
//      {type = s32, u32, s64, u64; ? pack = none;}
//      {type = sx, ux; ? pack = bin_nosat;}
//      ;
//      d0_s1_s2;
//  }
template<class T> bool InstValidator::req_mulhi(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_sx_ux(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_SX_UX, sizeof(TYPE_VALUES_S32_U32_S64_U64_SX_UX) / sizeof(unsigned));
    }
    validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
    validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));

    if (
            check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_sx_ux(getType<T>(inst))
       )
    {
        if (!check_pack_values_binnosat(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_BINNOSAT, sizeof(PACK_VALUES_BINNOSAT) / sizeof(unsigned));
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
//      round = none;
//      ftz = none;
//      {type = s32, s64, f; ? pack = none;}
//      {type = sx, fx; ? pack = s, p;}
//      ;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_neg(T inst)
{
    if (!check_type_values_s32_s64_sx_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_S64_SX_F_FX, sizeof(TYPE_VALUES_S32_S64_SX_F_FX) / sizeof(unsigned));
    }
    validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_NONE, sizeof(ROUND_VALUES_NONE) / sizeof(unsigned));
    validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_NONE, sizeof(FTZ_VALUES_NONE) / sizeof(unsigned));

    if (
            check_type_values_s32_s64_f(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_sx_fx(getType<T>(inst))
       )
    {
        if (!check_pack_values_p_s(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_P_S, sizeof(PACK_VALUES_P_S) / sizeof(unsigned));
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
//  Req nullptr = {
//      type = u32, u64;
//      segment = flat, global, readonly, group, private, kernarg;
//      typesize = seg;
//      s0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_nullptr(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_global_group_private_flat_kernarg_readonly(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE_FLAT_KERNARG_READONLY, sizeof(SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE_FLAT_KERNARG_READONLY) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SEG, sizeof(TYPESIZE_VALUES_SEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req pack = {
//      type = x;
//      stype = s32, u32, s64, u64, f;
//      {type = s8x, s16x, s32x; ? stype = s32;}
//      {type = s64x; ? stype = s64;}
//      {type = u8x, u16x, u32x; ? stype = u32;}
//      {type = u64x; ? stype = u64;}
//      {type = f16x; ? stype = f16;}
//      {type = f32x; ? stype = f32;}
//      {type = f64x; ? stype = f64;}
//      ;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_stype, imm_stype;
//      s3 = reg_u32, imm_u32;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_pack(T inst)
{
    if (!check_type_values_x(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_X, sizeof(TYPE_VALUES_X) / sizeof(unsigned));
    }
    if (!check_type_values_s32_u32_s64_u64_f(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F, sizeof(TYPE_VALUES_S32_U32_S64_U64_F) / sizeof(unsigned));
    }

    if (
            check_type_values_s8x_s16x_s32x(getType<T>(inst))
       )
    {
        if (!check_type_values_s32(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_S32, sizeof(TYPE_VALUES_S32) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s64x(getType<T>(inst))
       )
    {
        if (!check_type_values_s64(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_S64, sizeof(TYPE_VALUES_S64) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_u8x_u16x_u32x(getType<T>(inst))
       )
    {
        if (!check_type_values_u32(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_u64x2(getType<T>(inst))
       )
    {
        if (!check_type_values_u64(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U64, sizeof(TYPE_VALUES_U64) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f16x(getType<T>(inst))
       )
    {
        if (!check_type_values_f16(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_F16, sizeof(TYPE_VALUES_F16) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f32x(getType<T>(inst))
       )
    {
        if (!check_type_values_f32(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_F32, sizeof(TYPE_VALUES_F32) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f64x(getType<T>(inst))
       )
    {
        if (!check_type_values_f64(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_F64, sizeof(TYPE_VALUES_F64) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
    if (!check_type_values_f32(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_F32, sizeof(TYPE_VALUES_F32) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req packet = {
//      type = sig32, sig64;
//      typesize = signal;
//      s0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_packet(T inst)
{
    if (!check_type_values_sig32_sig64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_SIG32_SIG64, sizeof(TYPE_VALUES_SIG32_SIG64) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_SIGNAL, sizeof(TYPESIZE_VALUES_SIGNAL) / sizeof(unsigned));
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
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
    if (!check_type_values_b32_b64(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req ptr_model = {
//      type = u32, u64;
//      typesize = model;
//      s0 = reg;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_ptr_model(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req queryimage = {
//      type = u32;
//      itype = roimg, rwimg, woimg;
//      geometry = any;
//      iprop = any;
//      {iprop = width, channeltype, channelorder; ? geometry = any;}
//      {iprop = depth; ? geometry = 3d;}
//      {iprop = array; ? geometry = 1da, 2da, 2dadepth;}
//      {iprop = height; ? geometry = 2d, 3d, 2da, 2ddepth, 2dadepth;}
//      ;
//      d0 = reg;
//      s1 = reg_itype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_queryimage(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_roimg_rwimg_woimg(getImageType<T>(inst))) {
        brigPropError(inst, PROP_IMAGETYPE, getImageType<T>(inst), TYPE_VALUES_ROIMG_RWIMG_WOIMG, sizeof(TYPE_VALUES_ROIMG_RWIMG_WOIMG) / sizeof(unsigned));
    }
    if (!check_geometry_values_any(getGeometry<T>(inst))) {
        brigPropError(inst, PROP_GEOMETRY, getGeometry<T>(inst), GEOMETRY_VALUES_ANY, sizeof(GEOMETRY_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_iprop_values_any(getImageQuery<T>(inst))) {
        brigPropError(inst, PROP_IMAGEQUERY, getImageQuery<T>(inst), IPROP_VALUES_ANY, sizeof(IPROP_VALUES_ANY) / sizeof(unsigned));
    }

    if (
            check_iprop_values_width_channeltype_channelorder(getImageQuery<T>(inst))
       )
    {
        if (!check_geometry_values_any(getGeometry<T>(inst))) {
            brigPropError(inst, PROP_GEOMETRY, getGeometry<T>(inst), GEOMETRY_VALUES_ANY, sizeof(GEOMETRY_VALUES_ANY) / sizeof(unsigned));
        }
    }
    else if (
            check_iprop_values_depth(getImageQuery<T>(inst))
       )
    {
        if (!check_geometry_values_3d(getGeometry<T>(inst))) {
            brigPropError(inst, PROP_GEOMETRY, getGeometry<T>(inst), GEOMETRY_VALUES_3D, sizeof(GEOMETRY_VALUES_3D) / sizeof(unsigned));
        }
    }
    else if (
            check_iprop_values_array(getImageQuery<T>(inst))
       )
    {
        if (!check_geometry_values_1da_2da_2dadepth(getGeometry<T>(inst))) {
            brigPropError(inst, PROP_GEOMETRY, getGeometry<T>(inst), GEOMETRY_VALUES_1DA_2DA_2DADEPTH, sizeof(GEOMETRY_VALUES_1DA_2DA_2DADEPTH) / sizeof(unsigned));
        }
    }
    else if (
            check_iprop_values_height(getImageQuery<T>(inst))
       )
    {
        if (!check_geometry_values_2d_3d_2da_2ddepth_2dadepth(getGeometry<T>(inst))) {
            brigPropError(inst, PROP_GEOMETRY, getGeometry<T>(inst), GEOMETRY_VALUES_2D_3D_2DA_2DDEPTH_2DADEPTH, sizeof(GEOMETRY_VALUES_2D_3D_2DA_2DDEPTH_2DADEPTH) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_IMAGEQUERY);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_ITYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req querysampler = {
//      type = u32;
//      sprop = any;
//      d0 = reg;
//      s1 = reg_samp;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_querysampler(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_sprop_values_any(getSamplerQuery<T>(inst))) {
        brigPropError(inst, PROP_SAMPLERQUERY, getSamplerQuery<T>(inst), SPROP_VALUES_ANY, sizeof(SPROP_VALUES_ANY) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_SAMP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req rdimage = {
//      type = s32, u32, f32;
//      itype = roimg;
//      ctype = s32, f32;
//      geometry = 1d, 2d, 3d, 1da, 2da, 2ddepth, 2dadepth;
//      eqclass = any;
//      s1 = reg_itype;
//      s2 = reg_samp;
//      s4 = null;
//      {geometry = 1d; ? d0 = vec_4; s3 = reg_ctype;}
//      {geometry = 2d, 1da; ? d0 = vec_4; s3 = vec_2_ctype;}
//      {geometry = 3d, 2da; ? d0 = vec_4; s3 = vec_3_ctype;}
//      {geometry = 2ddepth; ? d0 = reg; s3 = vec_2_ctype;}
//      {geometry = 2dadepth; ? d0 = reg; s3 = vec_3_ctype;}
//      ;
//  }
template<class T> bool InstValidator::req_rdimage(T inst)
{
    if (!check_type_values_s32_u32_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_F32, sizeof(TYPE_VALUES_S32_U32_F32) / sizeof(unsigned));
    }
    if (!check_type_values_roimg(getImageType<T>(inst))) {
        brigPropError(inst, PROP_IMAGETYPE, getImageType<T>(inst), TYPE_VALUES_ROIMG, sizeof(TYPE_VALUES_ROIMG) / sizeof(unsigned));
    }
    if (!check_type_values_s32_f32(getCoordType<T>(inst))) {
        brigPropError(inst, PROP_COORDTYPE, getCoordType<T>(inst), TYPE_VALUES_S32_F32, sizeof(TYPE_VALUES_S32_F32) / sizeof(unsigned));
    }
    if (!check_geometry_values_1d_2d_3d_1da_2da_2ddepth_2dadepth(getGeometry<T>(inst))) {
        brigPropError(inst, PROP_GEOMETRY, getGeometry<T>(inst), GEOMETRY_VALUES_1D_2D_3D_1DA_2DA_2DDEPTH_2DADEPTH, sizeof(GEOMETRY_VALUES_1D_2D_3D_1DA_2DA_2DDEPTH_2DADEPTH) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_ITYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_SAMP, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));

    if (
            check_geometry_values_1d(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_2d_1da(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_3d_2da(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC3CTYPE, sizeof(OPERAND_VALUES_VEC3CTYPE) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_2ddepth(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_2dadepth(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC3CTYPE, sizeof(OPERAND_VALUES_VEC3CTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_GEOMETRY);
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
//      segment = global, group, private;
//      nonull = any;
//      typesize = model;
//      stypesize = seg;
//      d0 = reg;
//      s1 = reg_stype, cnst_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_s2f(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_type_values_u32_u64(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_global_group_private(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE, sizeof(SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE) / sizeof(unsigned));
    }
    if (!check_nonull_values_any(getIsNoNull<T>(inst))) {
        brigPropError(inst, PROP_ISNONULL, getIsNoNull<T>(inst), NONULL_VALUES_ANY, sizeof(NONULL_VALUES_ANY) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_SEG, sizeof(STYPESIZE_VALUES_SEG) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGU32_CNSTU32, sizeof(OPERAND_VALUES_REGU32_CNSTU32) / sizeof(unsigned));
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
//      s3 = reg_u32, imm_u32;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_sad(T inst)
{
    if (!check_type_values_u32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32, sizeof(TYPE_VALUES_U32) / sizeof(unsigned));
    }
    if (!check_type_values_u32_u8x4_u16x2(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U32_U8X4_U16X2, sizeof(TYPE_VALUES_U32_U8X4_U16X2) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
//      s3 = reg, imm;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_sadhi(T inst)
{
    if (!check_type_values_u16x2(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U16X2, sizeof(TYPE_VALUES_U16X2) / sizeof(unsigned));
    }
    if (!check_type_values_u8x4(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U8X4, sizeof(TYPE_VALUES_U8X4) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req sbr = {
//      type = u32, u64;
//      width = any_1;
//      s0 = reg, imm;
//      s1 = jumptab;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_sbr(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_JUMPTAB, sizeof(OPERAND_VALUES_JUMPTAB) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req scall = {
//      type = u32, u64;
//      width = any_1;
//      s0 = arglist;
//      s1 = reg, imm;
//      s2 = arglist;
//      s3 = calltab;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_scall(T inst)
{
    if (!check_type_values_u32_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_width_values_any1(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_ANY1, sizeof(WIDTH_VALUES_ANY1) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_ARGLIST, sizeof(OPERAND_VALUES_ARGLIST) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_CALLTAB, sizeof(OPERAND_VALUES_CALLTAB) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req segmentp = {
//      type = b1;
//      stype = u32, u64;
//      segment = global, group, private;
//      nonull = any;
//      stypesize = model;
//      d0 = reg;
//      s1 = reg_stype, cnst_stype;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_segmentp(T inst)
{
    if (!check_type_values_b1(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B1, sizeof(TYPE_VALUES_B1) / sizeof(unsigned));
    }
    if (!check_type_values_u32_u64(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U32_U64, sizeof(TYPE_VALUES_U32_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_global_group_private(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE, sizeof(SEGMENT_VALUES_GLOBAL_GROUP_PRIVATE) / sizeof(unsigned));
    }
    if (!check_nonull_values_any(getIsNoNull<T>(inst))) {
        brigPropError(inst, PROP_ISNONULL, getIsNoNull<T>(inst), NONULL_VALUES_ANY, sizeof(NONULL_VALUES_ANY) / sizeof(unsigned));
    }
    validateStypesize(inst, PROP_STYPESIZE, STYPESIZE_ATTR_NONE, STYPESIZE_VALUES_MODEL, sizeof(STYPESIZE_VALUES_MODEL) / sizeof(unsigned));
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGU32_CNSTU32, sizeof(OPERAND_VALUES_REGU32_CNSTU32) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req shift = {
//      type = s32, u32, s64, u64, sx, ux;
//      d0 = reg;
//      s1 = reg, imm;
//      s2 = reg_u32, imm_u32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_shift(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_sx_ux(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_SX_UX, sizeof(TYPE_VALUES_S32_U32_S64_U64_SX_UX) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
//      s3 = cnst_b32;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_shuffle(T inst)
{
    if (!check_type_values_x32_x64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_X32_X64, sizeof(TYPE_VALUES_X32_X64) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_B32, OPERAND_VALUES_CNSTB32, sizeof(OPERAND_VALUES_CNSTB32) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req signal = {
//      type = b32, s32, u32, b64, s64, u64;
//      sigtype = sig32, sig64;
//      sigop = generic, exch, ld, wait, waittimeout;
//      memord = any;
//      typesize = model;
//      {type = b32, s32, u32; ? sigtype = sig32; s1 = reg_sig32;}
//      {type = b64, s64, u64; ? sigtype = sig64; s1 = reg_sig64;}
//      ;
//      {sigop = ld; ? type = b32, b64; memord = ld; s2 = null; s3 = null;}
//      {sigop = and, or, xor, exch; ? type = b32, b64; memord = any; s2 = reg, imm; s3 = null;}
//      {sigop = cas; ? type = b32, b64; memord = any; s2 = reg, imm; s3 = reg, imm;}
//      {sigop = add, sub; ? type = s32, u32, s64, u64; memord = any; s2 = reg, imm; s3 = null;}
//      {sigop = wait; ? type = s32, s64; memord = wait; s2 = reg, imm; s3 = null;}
//      {sigop = waittimeout; ? type = s32, s64; memord = wait; s2 = reg, imm; s3 = reg_u64, imm_u64;}
//      ;
//      d0 = reg;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_signal(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_type_values_sig32_sig64(getSignalType<T>(inst))) {
        brigPropError(inst, PROP_SIGNALTYPE, getSignalType<T>(inst), TYPE_VALUES_SIG32_SIG64, sizeof(TYPE_VALUES_SIG32_SIG64) / sizeof(unsigned));
    }
    if (!check_atmop_values_generic_exch_ld_wait_waittimeout(getSignalOperation<T>(inst))) {
        brigPropError(inst, PROP_SIGNALOPERATION, getSignalOperation<T>(inst), ATMOP_VALUES_GENERIC_EXCH_LD_WAIT_WAITTIMEOUT, sizeof(ATMOP_VALUES_GENERIC_EXCH_LD_WAIT_WAITTIMEOUT) / sizeof(unsigned));
    }
    if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
        brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned));

    if (
            check_type_values_b32_s32_u32(getType<T>(inst))
       )
    {
        if (!check_type_values_sig32(getSignalType<T>(inst))) {
            brigPropError(inst, PROP_SIGNALTYPE, getSignalType<T>(inst), TYPE_VALUES_SIG32, sizeof(TYPE_VALUES_SIG32) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S1, OPERAND_ATTR_SIG32, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_type_values_b64_s64_u64(getType<T>(inst))
       )
    {
        if (!check_type_values_sig64(getSignalType<T>(inst))) {
            brigPropError(inst, PROP_SIGNALTYPE, getSignalType<T>(inst), TYPE_VALUES_SIG64, sizeof(TYPE_VALUES_SIG64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S1, OPERAND_ATTR_SIG64, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }

    if (
            check_atmop_values_ld(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_ld(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_LD, sizeof(MEMORD_VALUES_LD) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor_exch(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_cas(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_wait(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_s32_s64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_S64, sizeof(TYPE_VALUES_S32_S64) / sizeof(unsigned));
        }
        if (!check_memord_values_ld(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_LD, sizeof(MEMORD_VALUES_LD) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_waittimeout(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_s32_s64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_S64, sizeof(TYPE_VALUES_S32_S64) / sizeof(unsigned));
        }
        if (!check_memord_values_ld(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_LD, sizeof(MEMORD_VALUES_LD) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
        validateOperand(inst, PROP_S3, OPERAND_ATTR_U64, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_SIGNALOPERATION);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req signal_noret = {
//      type = b32, s32, u32, b64, s64, u64;
//      sigtype = sig32, sig64;
//      sigop = generic, st;
//      memord = any;
//      typesize = model;
//      {type = b32, s32, u32; ? sigtype = sig32; s0 = reg_sig32;}
//      {type = b64, s64, u64; ? sigtype = sig64; s0 = reg_sig64;}
//      ;
//      {sigop = st; ? type = b32, b64; memord = st; s2 = null;}
//      {sigop = and, or, xor; ? type = b32, b64; memord = any; s2 = null;}
//      {sigop = cas; ? type = b32, b64; memord = any; s2 = reg, imm;}
//      {sigop = add, sub; ? type = s32, u32, s64, u64; memord = any; s2 = null;}
//      ;
//      s1 = reg, imm;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_signal_noret(T inst)
{
    if (!check_type_values_b32_s32_u32_b64_s64_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_S32_U32_B64_S64_U64, sizeof(TYPE_VALUES_B32_S32_U32_B64_S64_U64) / sizeof(unsigned));
    }
    if (!check_type_values_sig32_sig64(getSignalType<T>(inst))) {
        brigPropError(inst, PROP_SIGNALTYPE, getSignalType<T>(inst), TYPE_VALUES_SIG32_SIG64, sizeof(TYPE_VALUES_SIG32_SIG64) / sizeof(unsigned));
    }
    if (!check_atmop_values_generic_st(getSignalOperation<T>(inst))) {
        brigPropError(inst, PROP_SIGNALOPERATION, getSignalOperation<T>(inst), ATMOP_VALUES_GENERIC_ST, sizeof(ATMOP_VALUES_GENERIC_ST) / sizeof(unsigned));
    }
    if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
        brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
    }
    validateTypesize(inst, PROP_TYPESIZE, TYPESIZE_ATTR_NONE, TYPESIZE_VALUES_MODEL, sizeof(TYPESIZE_VALUES_MODEL) / sizeof(unsigned));

    if (
            check_type_values_b32_s32_u32(getType<T>(inst))
       )
    {
        if (!check_type_values_sig32(getSignalType<T>(inst))) {
            brigPropError(inst, PROP_SIGNALTYPE, getSignalType<T>(inst), TYPE_VALUES_SIG32, sizeof(TYPE_VALUES_SIG32) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S0, OPERAND_ATTR_SIG32, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_type_values_b64_s64_u64(getType<T>(inst))
       )
    {
        if (!check_type_values_sig64(getSignalType<T>(inst))) {
            brigPropError(inst, PROP_SIGNALTYPE, getSignalType<T>(inst), TYPE_VALUES_SIG64, sizeof(TYPE_VALUES_SIG64) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S0, OPERAND_ATTR_SIG64, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }

    if (
            check_atmop_values_st(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_st(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ST, sizeof(MEMORD_VALUES_ST) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_and_or_xor(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_cas(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_b32_b64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_B32_B64, sizeof(TYPE_VALUES_B32_B64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    }
    else if (
            check_atmop_values_add_sub(getSignalOperation<T>(inst))
       )
    {
        if (!check_type_values_s32_u32_s64_u64(getType<T>(inst))) {
            brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64, sizeof(TYPE_VALUES_S32_U32_S64_U64) / sizeof(unsigned));
        }
        if (!check_memord_values_any(getMemoryOrder<T>(inst))) {
            brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ANY, sizeof(MEMORD_VALUES_ANY) / sizeof(unsigned));
        }
        validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_SIGNALOPERATION);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
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
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req spec_except = {
//      type = u32;
//      s0 = cnst;
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
    validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_CNSTB32, sizeof(OPERAND_VALUES_CNSTB32) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req sqrt = {
//      type = f, fx;
//      round = float;
//      ftz = any;
//      {type = f; ? pack = none;}
//      {type = fx; ? pack = p, s;}
//      ;
//      d0_s1;
//  }
template<class T> bool InstValidator::req_sqrt(T inst)
{
    if (!check_type_values_f_fx(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F_FX, sizeof(TYPE_VALUES_F_FX) / sizeof(unsigned));
    }
    validateRound(inst, PROP_ROUND, getRoundEx<T>(inst), ROUND_VALUES_FLOAT, sizeof(ROUND_VALUES_FLOAT) / sizeof(unsigned));
    validateFtz(inst, PROP_FTZ, getFtzEx<T>(inst), FTZ_VALUES_ANY, sizeof(FTZ_VALUES_ANY) / sizeof(unsigned));

    if (
            check_type_values_f(getType<T>(inst))
       )
    {
        if (!check_pack_values_none(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_NONE, sizeof(PACK_VALUES_NONE) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_fx(getType<T>(inst))
       )
    {
        if (!check_pack_values_p_s(getPackEx<T>(inst))) {
            brigPropError(inst, PROP_PACK, getPackEx<T>(inst), PACK_VALUES_P_S, sizeof(PACK_VALUES_P_S) / sizeof(unsigned));
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
//      type = u, s, f, b128, opaque;
//      segment = writable;
//      align = any;
//      const = none;
//      eqclass = any;
//      width = none;
//      {type = u, s, f; ? s0 = reg, vector, imm;}
//      {type = b128, sig; ? s0 = reg;}
//      {type = img; ? s0 = reg; segment = arg;}
//      ;
//      s1 = addr_tseg;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_st(T inst)
{
    if (!check_type_values_u_s_f_b128_opaque(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U_S_F_B128_OPAQUE, sizeof(TYPE_VALUES_U_S_F_B128_OPAQUE) / sizeof(unsigned));
    }
    if (!check_segment_values_writable(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_WRITABLE, sizeof(SEGMENT_VALUES_WRITABLE) / sizeof(unsigned));
    }
    if (!check_align_values_any(getAlign<T>(inst))) {
        brigPropError(inst, PROP_ALIGN, getAlign<T>(inst), ALIGN_VALUES_ANY, sizeof(ALIGN_VALUES_ANY) / sizeof(unsigned));
    }
    if (!check_const_values_none(getIsConst<T>(inst))) {
        brigPropError(inst, PROP_ISCONST, getIsConst<T>(inst), CONST_VALUES_NONE, sizeof(CONST_VALUES_NONE) / sizeof(unsigned));
    }
    validateEqclass(inst, PROP_EQUIVCLASS, EQCLASS_ATTR_NONE, EQCLASS_VALUES_ANY, sizeof(EQCLASS_VALUES_ANY) / sizeof(unsigned));
    if (!check_width_values_none(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_NONE, sizeof(WIDTH_VALUES_NONE) / sizeof(unsigned));
    }

    if (
            check_type_values_s_u_f(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG_VECTOR_IMM, sizeof(OPERAND_VALUES_REG_VECTOR_IMM) / sizeof(unsigned));
    }
    else if (
            check_type_values_b128_sig(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_type_values_img(getType<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
        if (!check_segment_values_arg(getSegment<T>(inst))) {
            brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_ARG, sizeof(SEGMENT_VALUES_ARG) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_TSEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req st_image = {
//      ld_st_image;
//      itype = woimg, rwimg;
//      {geometry = 1d, 1db; ? s0 = vec_4; s2 = reg_ctype;}
//      {geometry = 2d, 1da; ? s0 = vec_4; s2 = vec_2_ctype;}
//      {geometry = 3d, 2da; ? s0 = vec_4; s2 = vec_3_ctype;}
//      {geometry = 2ddepth; ? s0 = reg; s2 = vec_2_ctype;}
//      {geometry = 2dadepth; ? s0 = reg; s2 = vec_3_ctype;}
//      ;
//      s1 = reg_itype;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_st_image(T inst)
{
    req_ld_st_image(inst);
    if (!check_type_values_woimg_rwimg(getImageType<T>(inst))) {
        brigPropError(inst, PROP_IMAGETYPE, getImageType<T>(inst), TYPE_VALUES_WOIMG_RWIMG, sizeof(TYPE_VALUES_WOIMG_RWIMG) / sizeof(unsigned));
    }

    if (
            check_geometry_values_1d_1db(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_2d_1da(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_3d_2da(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_VEC4, sizeof(OPERAND_VALUES_VEC4) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC3CTYPE, sizeof(OPERAND_VALUES_VEC3CTYPE) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_2ddepth(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC2STYPE, sizeof(OPERAND_VALUES_VEC2STYPE) / sizeof(unsigned));
    }
    else if (
            check_geometry_values_2dadepth(getGeometry<T>(inst))
       )
    {
        validateOperand(inst, PROP_S0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
        validateOperand(inst, PROP_S2, OPERAND_ATTR_CTYPE, OPERAND_VALUES_VEC3CTYPE, sizeof(OPERAND_VALUES_VEC3CTYPE) / sizeof(unsigned));
    }
    else 
    {
        invalidVariant(inst, PROP_GEOMETRY);
    }
    validateOperand(inst, PROP_S1, OPERAND_ATTR_ITYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    return true;
}

//================================================================================
//  Req stq = {
//      type = u64;
//      segment = flat, global;
//      memord = rlx, rel;
//      s0 = addr_seg;
//      s1 = reg, imm;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_stq(T inst)
{
    if (!check_type_values_u64(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_U64, sizeof(TYPE_VALUES_U64) / sizeof(unsigned));
    }
    if (!check_segment_values_flat_global(getSegment<T>(inst))) {
        brigPropError(inst, PROP_SEGMENT, getSegment<T>(inst), SEGMENT_VALUES_FLAT_GLOBAL, sizeof(SEGMENT_VALUES_FLAT_GLOBAL) / sizeof(unsigned));
    }
    if (!check_memord_values_st(getMemoryOrder<T>(inst))) {
        brigPropError(inst, PROP_MEMORYORDER, getMemoryOrder<T>(inst), MEMORD_VALUES_ST, sizeof(MEMORD_VALUES_ST) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_SEG, OPERAND_VALUES_ADDRSEG, sizeof(OPERAND_VALUES_ADDRSEG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
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
//      {type = s64; ? stype = s64x;}
//      {type = u32; ? stype = u8x, u16x, u32x;}
//      {type = u64; ? stype = u64x;}
//      {type = f16; ? stype = f16x;}
//      {type = f32; ? stype = f32x;}
//      {type = f64; ? stype = f64x;}
//      ;
//      d0 = reg;
//      s1 = reg_stype, imm_stype;
//      s2 = reg_u32, imm_u32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_unpack(T inst)
{
    if (!check_type_values_s32_u32_s64_u64_f(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_S32_U32_S64_U64_F, sizeof(TYPE_VALUES_S32_U32_S64_U64_F) / sizeof(unsigned));
    }
    if (!check_type_values_x(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_X, sizeof(TYPE_VALUES_X) / sizeof(unsigned));
    }

    if (
            check_type_values_s32(getType<T>(inst))
       )
    {
        if (!check_type_values_s8x_s16x_s32x(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_S8X_S16X_S32X, sizeof(TYPE_VALUES_S8X_S16X_S32X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_s64(getType<T>(inst))
       )
    {
        if (!check_type_values_s64x(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_S64X, sizeof(TYPE_VALUES_S64X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_u32(getType<T>(inst))
       )
    {
        if (!check_type_values_u8x_u16x_u32x(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U8X_U16X_U32X, sizeof(TYPE_VALUES_U8X_U16X_U32X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_u64(getType<T>(inst))
       )
    {
        if (!check_type_values_u64x2(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U64X2, sizeof(TYPE_VALUES_U64X2) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f16(getType<T>(inst))
       )
    {
        if (!check_type_values_f16x(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_F16X, sizeof(TYPE_VALUES_F16X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f32(getType<T>(inst))
       )
    {
        if (!check_type_values_f32x(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_F32X, sizeof(TYPE_VALUES_F32X) / sizeof(unsigned));
        }
    }
    else if (
            check_type_values_f64(getType<T>(inst))
       )
    {
        if (!check_type_values_f64x(getSourceType<T>(inst))) {
            brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_F64X, sizeof(TYPE_VALUES_F64X) / sizeof(unsigned));
        }
    }
    else 
    {
        invalidVariant(inst, PROP_TYPE);
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_U32, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
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
//      s2 = imm0T3_u32;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_unpackcvt(T inst)
{
    if (!check_type_values_f32(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_F32, sizeof(TYPE_VALUES_F32) / sizeof(unsigned));
    }
    if (!check_type_values_u8x4(getSourceType<T>(inst))) {
        brigPropError(inst, PROP_SOURCETYPE, getSourceType<T>(inst), TYPE_VALUES_U8X4, sizeof(TYPE_VALUES_U8X4) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_D0, OPERAND_ATTR_DTYPE, OPERAND_VALUES_REG, sizeof(OPERAND_VALUES_REG) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_STYPE, OPERAND_VALUES_REGSTYPE_IMMSTYPE, sizeof(OPERAND_VALUES_REGSTYPE_IMMSTYPE) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_U32, OPERAND_VALUES_IMM0T3U32, sizeof(OPERAND_VALUES_IMM0T3U32) / sizeof(unsigned));
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

//================================================================================
//  Req wavebarrier = {
//      type = none;
//      width = wavesize;
//      s0 = null;
//      s1 = null;
//      s2 = null;
//      s3 = null;
//      s4 = null;
//  }
template<class T> bool InstValidator::req_wavebarrier(T inst)
{
    if (!check_type_values_none(getType<T>(inst))) {
        brigPropError(inst, PROP_TYPE, getType<T>(inst), TYPE_VALUES_NONE, sizeof(TYPE_VALUES_NONE) / sizeof(unsigned));
    }
    if (!check_width_values_wavesize(getWidth<T>(inst))) {
        brigPropError(inst, PROP_WIDTH, getWidth<T>(inst), WIDTH_VALUES_WAVESIZE, sizeof(WIDTH_VALUES_WAVESIZE) / sizeof(unsigned));
    }
    validateOperand(inst, PROP_S0, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S1, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S2, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S3, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
    validateOperand(inst, PROP_S4, OPERAND_ATTR_NONE, OPERAND_VALUES_NULL, sizeof(OPERAND_VALUES_NULL) / sizeof(unsigned));
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
        case (Brig::BRIG_OPCODE_ACTIVELANECOUNT):
        {
            InstLane i = inst;
            if (!i) { invalidFormat(inst, "InstLane"); }
            req_activelanecount<InstLane>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_ACTIVELANEID):
        {
            InstLane i = inst;
            if (!i) { invalidFormat(inst, "InstLane"); }
            req_activelaneid<InstLane>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_ACTIVELANEMASK):
        {
            InstLane i = inst;
            if (!i) { invalidFormat(inst, "InstLane"); }
            req_activelanemask<InstLane>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_ACTIVELANESHUFFLE):
        {
            InstLane i = inst;
            if (!i) { invalidFormat(inst, "InstLane"); }
            req_activelaneshuffle<InstLane>(i);
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
        case (Brig::BRIG_OPCODE_ADDQUEUEWRITEINDEX):
        {
            InstQueue i = inst;
            if (!i) { invalidFormat(inst, "InstQueue"); }
            req_addq<InstQueue>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_AGENTCOUNT):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_AGENTID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_ALLOCA):
        {
            InstMem i = inst;
            if (!i) { invalidFormat(inst, "InstMem"); }
            req_alloca<InstMem>(i);
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
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_fbar_width<InstBr>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_ATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { invalidFormat(inst, "InstAtomic"); }
            req_atomic<InstAtomic>(i);
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
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_barrier<InstBr>(i);
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
        case (Brig::BRIG_OPCODE_BR):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_br<InstBr>(i);
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
        case (Brig::BRIG_OPCODE_CASQUEUEWRITEINDEX):
        {
            InstQueue i = inst;
            if (!i) { invalidFormat(inst, "InstQueue"); }
            req_casq<InstQueue>(i);
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
        case (Brig::BRIG_OPCODE_CUID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32_dim<InstBasic>(i);
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
            req_basic_dst_u32<InstBasic>(i);
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
            InstSegCvt i = inst;
            if (!i) { invalidFormat(inst, "InstSegCvt"); }
            req_f2s<InstSegCvt>(i);
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
        case (Brig::BRIG_OPCODE_GCNDIVRELAXED):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_div_relaxed<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNDIVRELAXEDNARROW):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_div_relaxed<InstBasic>(i);
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
            req_gcn_mads<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNMADU):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_madu<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNMAX):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_min_max<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNMAX3):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_min_max_med3<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNMED3):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_min_max_med3<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNMIN):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_min_max<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNMIN3):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_gcn_min_max_med3<InstBasic>(i);
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
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GRIDGROUPS):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32_dim<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GRIDSIZE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32_dim<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GROUPBASEPTR):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_ICALL):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_icall<InstBr>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_INITFBAR):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_fbar_none<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_JOINFBAR):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_fbar_width<InstBr>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_KERNARGBASEPTR):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_ptr_model<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_LANEID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32<InstBasic>(i);
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
        case (Brig::BRIG_OPCODE_LDF):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_ldf<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_LDI):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_ldi<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_LDIMAGE):
        {
            InstImage i = inst;
            if (!i) { invalidFormat(inst, "InstImage"); }
            req_ld_image<InstImage>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_LDK):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_ldk<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_LDQUEUEREADINDEX):
        {
            InstQueue i = inst;
            if (!i) { invalidFormat(inst, "InstQueue"); }
            req_ldq<InstQueue>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_LDQUEUEWRITEINDEX):
        {
            InstQueue i = inst;
            if (!i) { invalidFormat(inst, "InstQueue"); }
            req_ldq<InstQueue>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_LEAVEFBAR):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_fbar_width<InstBr>(i);
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
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_MAXWAVEID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_MEMFENCE):
        {
            InstMemFence i = inst;
            if (!i) { invalidFormat(inst, "InstMemFence"); }
            req_memfence<InstMemFence>(i);
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
            req_nullptr<InstSeg>(i);
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
        case (Brig::BRIG_OPCODE_PACKETCOMPLETIONSIG):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_packet<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_PACKETID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_spec_clock<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_POPCOUNT):
        {
            InstSourceType i = inst;
            if (!i) { invalidFormat(inst, "InstSourceType"); }
            req_popcount<InstSourceType>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_QUERYIMAGE):
        {
            InstQueryImage i = inst;
            if (!i) { invalidFormat(inst, "InstQueryImage"); }
            req_queryimage<InstQueryImage>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_QUERYSAMPLER):
        {
            InstQuerySampler i = inst;
            if (!i) { invalidFormat(inst, "InstQuerySampler"); }
            req_querysampler<InstQuerySampler>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_QUEUEID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_QUEUEPTR):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_ptr_model<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_RDIMAGE):
        {
            InstImage i = inst;
            if (!i) { invalidFormat(inst, "InstImage"); }
            req_rdimage<InstImage>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_RELEASEFBAR):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_fbar_none<InstBasic>(i);
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
        case (Brig::BRIG_OPCODE_SBR):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_sbr<InstBr>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_SCALL):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_scall<InstBr>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_SEGMENTP):
        {
            InstSegCvt i = inst;
            if (!i) { invalidFormat(inst, "InstSegCvt"); }
            req_segmentp<InstSegCvt>(i);
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
        case (Brig::BRIG_OPCODE_SIGNAL):
        {
            InstSignal i = inst;
            if (!i) { invalidFormat(inst, "InstSignal"); }
            req_signal<InstSignal>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_SIGNALNORET):
        {
            InstSignal i = inst;
            if (!i) { invalidFormat(inst, "InstSignal"); }
            req_signal_noret<InstSignal>(i);
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
            InstSegCvt i = inst;
            if (!i) { invalidFormat(inst, "InstSegCvt"); }
            req_s2f<InstSegCvt>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_STQUEUEREADINDEX):
        {
            InstQueue i = inst;
            if (!i) { invalidFormat(inst, "InstQueue"); }
            req_stq<InstQueue>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_STQUEUEWRITEINDEX):
        {
            InstQueue i = inst;
            if (!i) { invalidFormat(inst, "InstQueue"); }
            req_stq<InstQueue>(i);
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
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_fbar_width<InstBr>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_WAVEBARRIER):
        {
            InstBr i = inst;
            if (!i) { invalidFormat(inst, "InstBr"); }
            req_wavebarrier<InstBr>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_WAVEID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_WORKGROUPID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32_dim<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_WORKGROUPSIZE):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32_dim<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_WORKITEMABSID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32_u64_dim<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_WORKITEMFLATABSID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32_u64<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_WORKITEMFLATID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_WORKITEMID):
        {
            InstBasic i = inst;
            if (!i) { invalidFormat(inst, "InstBasic"); }
            req_basic_dst_u32_dim<InstBasic>(i);
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

template<class T> unsigned InstValidator::operand0_to_attr_signal_noret(T inst)
{
    if (
        check_type_values_b32_s32_u32(getType<T>(inst))
       )
    {
            return OPERAND_ATTR_SIG32;
    }
    if (
        check_type_values_b64_s64_u64(getType<T>(inst))
       )
    {
            return OPERAND_ATTR_SIG64;
    }
    return OPERAND_ATTR_INVALID;
}

unsigned InstValidator::getOperand0Attr(Inst inst)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ABS): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ACTIVELANECOUNT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ACTIVELANEID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ACTIVELANEMASK): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ACTIVELANESHUFFLE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ADD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ADDQUEUEWRITEINDEX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_AGENTCOUNT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_AGENTID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ALLOCA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_AND): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ARRIVEFBAR): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_ATOMIC): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ATOMICNORET): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_BARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITALIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITEXTRACT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITINSERT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITMASK): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITREV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITSELECT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BORROW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BYTEALIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CARRY): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CASQUEUEWRITEINDEX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CBR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CEIL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CLASS): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CLEARDETECTEXCEPT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CLOCK): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CMOV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CMP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_COMBINE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_COPYSIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CUID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CVT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_DEBUGTRAP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_DIM): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_DIV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_EXPAND): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FIRSTBIT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FLOOR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FMA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FRACT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FTOS): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNAPPEND): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNATOMIC): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNATOMICNORET): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_GCNB32XCHG): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNB4XCHG): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNBFM): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNCONSUME): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXED): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXEDNARROW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNFLDEXP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNFREXP_EXP): return OPERAND_ATTR_S32;
        case (Brig::BRIG_OPCODE_GCNFREXP_MANT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNLD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMADS): return OPERAND_ATTR_S64;
        case (Brig::BRIG_OPCODE_GCNMADU): return OPERAND_ATTR_U64;
        case (Brig::BRIG_OPCODE_GCNMAX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMAX3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMED3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMIN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMIN3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMQSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMQSAD4): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNPRIORITY): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNQSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNREGIONALLOC): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_GCNSADD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNSADW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNSLEEP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNST): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNTRIG_PREOP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GETDETECTEXCEPT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GRIDGROUPS): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GRIDSIZE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GROUPBASEPTR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ICALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_INITFBAR): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_JOINFBAR): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_KERNARGBASEPTR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LANEID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LASTBIT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LDA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LDF): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LDI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LDIMAGE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LDK): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LDQUEUEREADINDEX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LDQUEUEWRITEINDEX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_LEAVEFBAR): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_LERP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD24): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD24HI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAXCUID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAXWAVEID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MEMFENCE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MIN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MOV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MUL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MUL24): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MUL24HI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MULHI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NCOS): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NEG): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NEXP2): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NFMA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NLOG2): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NOP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NOT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NRCP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NRSQRT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NSIN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NSQRT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NULLPTR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_OR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_PACK): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_PACKCVT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_PACKETCOMPLETIONSIG): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_PACKETID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_POPCOUNT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_QUERYIMAGE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_QUERYSAMPLER): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_QUEUEID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_QUEUEPTR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_RDIMAGE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_RELEASEFBAR): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_REM): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_RET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RINT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SADHI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SBR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SCALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SEGMENTP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SETDETECTEXCEPT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SHL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SHR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SHUFFLE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SIGNAL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SIGNALNORET):
        {
            InstSignal i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand0_to_attr_signal_noret<InstSignal>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_SQRT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ST): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_STIMAGE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_STOF): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_STQUEUEREADINDEX): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_STQUEUEWRITEINDEX): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_SUB): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_TRUNC): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_UNPACK): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_UNPACKCVT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_UNPACKHI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_UNPACKLO): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_WAITFBAR): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_WAVEBARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAVEID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_WORKGROUPID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_WORKGROUPSIZE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_WORKITEMABSID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_WORKITEMFLATABSID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_WORKITEMFLATID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_WORKITEMID): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_XOR): return OPERAND_ATTR_DTYPE;
        default:
            return OPERAND_ATTR_INVALID;
            break;
    }
} // InstValidator::getOperand0Attr

template<class T> unsigned InstValidator::operand1_to_attr_cmov(T inst)
{
    if (
        check_type_values_b1_b32_b64(getType<T>(inst))
       )
    {
            return OPERAND_ATTR_B1;
    }
    if (
        check_type_values_x(getType<T>(inst))
       )
    {
            return OPERAND_ATTR_P2U;
    }
    return OPERAND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::operand1_to_attr_signal(T inst)
{
    if (
        check_type_values_b32_s32_u32(getType<T>(inst))
       )
    {
            return OPERAND_ATTR_SIG32;
    }
    if (
        check_type_values_b64_s64_u64(getType<T>(inst))
       )
    {
            return OPERAND_ATTR_SIG64;
    }
    return OPERAND_ATTR_INVALID;
}

unsigned InstValidator::getOperand1Attr(Inst inst)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ABS): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ACTIVELANECOUNT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_ACTIVELANEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANEMASK): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_ACTIVELANESHUFFLE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ADD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ADDQUEUEWRITEINDEX): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_AGENTCOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_AGENTID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ALLOCA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_AND): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ARRIVEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ATOMIC): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_ATOMICNORET): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITALIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITEXTRACT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITINSERT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITMASK): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_BITREV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITSELECT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BORROW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BYTEALIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CARRY): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CASQUEUEWRITEINDEX): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_CBR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CEIL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CLASS): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_CLEARDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CLOCK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CMOV):
        {
            InstBasic i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand1_to_attr_cmov<InstBasic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_CMP): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_COMBINE): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_COPYSIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CUID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_CVT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_DEBUGTRAP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DIM): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DIV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_EXPAND): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_FIRSTBIT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_FLOOR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FMA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FRACT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FTOS): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_GCNAPPEND): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_GCNATOMIC): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_GCNATOMICNORET): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNB32XCHG): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNB4XCHG): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNBFM): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNCONSUME): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXED): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXEDNARROW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNFLDEXP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNFREXP_EXP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNFREXP_MANT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNLD): return OPERAND_ATTR_TSEG;
        case (Brig::BRIG_OPCODE_GCNMADS): return OPERAND_ATTR_S32;
        case (Brig::BRIG_OPCODE_GCNMADU): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_GCNMAX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMAX3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMED3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMIN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMIN3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMQSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMQSAD4): return OPERAND_ATTR_B64;
        case (Brig::BRIG_OPCODE_GCNMSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNPRIORITY): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNQSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNREGIONALLOC): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNSADD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNSADW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNSLEEP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNST): return OPERAND_ATTR_TSEG;
        case (Brig::BRIG_OPCODE_GCNTRIG_PREOP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GETDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GRIDGROUPS): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_GRIDSIZE): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_GROUPBASEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ICALL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_INITFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_JOINFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_KERNARGBASEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LANEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LASTBIT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_LD): return OPERAND_ATTR_TSEG;
        case (Brig::BRIG_OPCODE_LDA): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_LDF): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_LDI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDIMAGE): return OPERAND_ATTR_ITYPE;
        case (Brig::BRIG_OPCODE_LDK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDQUEUEREADINDEX): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_LDQUEUEWRITEINDEX): return OPERAND_ATTR_SEG;
        case (Brig::BRIG_OPCODE_LEAVEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LERP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD24): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD24HI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAXCUID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAXWAVEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MEMFENCE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MIN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MOV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MUL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MUL24): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MUL24HI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MULHI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NCOS): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NEG): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NEXP2): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NFMA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NLOG2): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NOP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NOT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NRCP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NRSQRT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NSIN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NSQRT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NULLPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_OR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_PACK): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_PACKCVT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_PACKETCOMPLETIONSIG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_PACKETID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_POPCOUNT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_QUERYIMAGE): return OPERAND_ATTR_ITYPE;
        case (Brig::BRIG_OPCODE_QUERYSAMPLER): return OPERAND_ATTR_SAMP;
        case (Brig::BRIG_OPCODE_QUEUEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUEUEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RDIMAGE): return OPERAND_ATTR_ITYPE;
        case (Brig::BRIG_OPCODE_RELEASEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_REM): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_RET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RINT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SAD): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_SADHI): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_SBR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SCALL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SEGMENTP): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_SETDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SHL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SHR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SHUFFLE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SIGNAL):
        {
            InstSignal i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand1_to_attr_signal<InstSignal>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_SIGNALNORET): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SQRT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ST): return OPERAND_ATTR_TSEG;
        case (Brig::BRIG_OPCODE_STIMAGE): return OPERAND_ATTR_ITYPE;
        case (Brig::BRIG_OPCODE_STOF): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_STQUEUEREADINDEX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_STQUEUEWRITEINDEX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SUB): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_TRUNC): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_UNPACK): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_UNPACKCVT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_UNPACKHI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_UNPACKLO): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_WAITFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAVEBARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAVEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKGROUPID): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_WORKGROUPSIZE): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_WORKITEMABSID): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_WORKITEMFLATABSID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMFLATID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMID): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_XOR): return OPERAND_ATTR_DTYPE;
        default:
            return OPERAND_ATTR_INVALID;
            break;
    }
} // InstValidator::getOperand1Attr

template<class T> unsigned InstValidator::operand2_to_attr_atomic(T inst)
{
    if (
        check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_and_or_xor_exch(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_ld(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    return OPERAND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::operand2_to_attr_atomic_noret(T inst)
{
    if (
        check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_and_or_xor(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_st(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    return OPERAND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::operand2_to_attr_gcn_atomic(T inst)
{
    if (
        check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_and_or_xor_exch(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_ld(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    return OPERAND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::operand2_to_attr_gcn_atomic_noret(T inst)
{
    if (
        check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_and_or_xor(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_st(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    return OPERAND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::operand2_to_attr_signal(T inst)
{
    if (
        check_atmop_values_ld(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_and_or_xor_exch(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_cas(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_add_sub(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_wait(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_waittimeout(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    return OPERAND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::operand2_to_attr_signal_noret(T inst)
{
    if (
        check_atmop_values_st(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_and_or_xor(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_cas(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_add_sub(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    return OPERAND_ATTR_INVALID;
}

unsigned InstValidator::getOperand2Attr(Inst inst)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ABS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANECOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANEMASK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANESHUFFLE): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_ADD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ADDQUEUEWRITEINDEX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_AGENTCOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_AGENTID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ALLOCA): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_AND): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ARRIVEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand2_to_attr_atomic<InstAtomic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_ATOMICNORET):
        {
            InstAtomic i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand2_to_attr_atomic_noret<InstAtomic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_BARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITALIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITEXTRACT): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_BITINSERT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITMASK): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_BITREV): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITSELECT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BORROW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BYTEALIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CARRY): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CASQUEUEWRITEINDEX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CBR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CEIL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CLASS): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_CLEARDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CLOCK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CMOV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CMP): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_COMBINE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_COPYSIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CUID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CVT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DEBUGTRAP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DIM): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DIV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_EXPAND): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FIRSTBIT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FLOOR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FMA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FRACT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FTOS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNAPPEND): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand2_to_attr_gcn_atomic<InstAtomic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNATOMICNORET):
        {
            InstAtomic i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand2_to_attr_gcn_atomic_noret<InstAtomic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNB32XCHG): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNB4XCHG): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNBFM): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNCONSUME): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXED): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXEDNARROW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNFLDEXP): return OPERAND_ATTR_S32;
        case (Brig::BRIG_OPCODE_GCNFREXP_EXP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNFREXP_MANT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNLD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMADS): return OPERAND_ATTR_S32;
        case (Brig::BRIG_OPCODE_GCNMADU): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_GCNMAX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMAX3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMED3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMIN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMIN3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMQSAD): return OPERAND_ATTR_B32;
        case (Brig::BRIG_OPCODE_GCNMQSAD4): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNPRIORITY): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNQSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNREGIONALLOC): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNSADD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNSADW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNSLEEP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNST): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNTRIG_PREOP): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_GETDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GRIDGROUPS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GRIDSIZE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GROUPBASEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ICALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_INITFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_JOINFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_KERNARGBASEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LANEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LASTBIT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDA): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDF): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDIMAGE): return OPERAND_ATTR_CTYPE;
        case (Brig::BRIG_OPCODE_LDK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDQUEUEREADINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDQUEUEWRITEINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LEAVEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LERP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD24): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD24HI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAXCUID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAXWAVEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MEMFENCE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MIN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MOV): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MUL): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MUL24): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MUL24HI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MULHI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NCOS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NEG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NEXP2): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NFMA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NLOG2): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NOP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NOT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NRCP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NRSQRT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NSIN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NSQRT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NULLPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_OR): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_PACK): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_PACKCVT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_PACKETCOMPLETIONSIG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_PACKETID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_POPCOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUERYIMAGE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUERYSAMPLER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUEUEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUEUEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RDIMAGE): return OPERAND_ATTR_SAMP;
        case (Brig::BRIG_OPCODE_RELEASEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_REM): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_RET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RINT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SAD): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_SADHI): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_SBR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SCALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SEGMENTP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SETDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SHL): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_SHR): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_SHUFFLE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SIGNAL):
        {
            InstSignal i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand2_to_attr_signal<InstSignal>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_SIGNALNORET):
        {
            InstSignal i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand2_to_attr_signal_noret<InstSignal>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_SQRT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ST): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STIMAGE): return OPERAND_ATTR_CTYPE;
        case (Brig::BRIG_OPCODE_STOF): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STQUEUEREADINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STQUEUEWRITEINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SUB): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_TRUNC): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_UNPACK): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_UNPACKCVT): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_UNPACKHI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_UNPACKLO): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_WAITFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAVEBARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAVEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKGROUPID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKGROUPSIZE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMABSID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMFLATABSID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMFLATID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_XOR): return OPERAND_ATTR_DTYPE;
        default:
            return OPERAND_ATTR_INVALID;
            break;
    }
} // InstValidator::getOperand2Attr

template<class T> unsigned InstValidator::operand3_to_attr_atomic(T inst)
{
    if (
        check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_and_or_xor_exch(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_ld(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    return OPERAND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::operand3_to_attr_gcn_atomic(T inst)
{
    if (
        check_atmop_values_cas(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_and_or_xor_exch(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_add_sub_min_max(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_wrapinc_wrapdec(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_ld(getAtomicOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    return OPERAND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::operand3_to_attr_signal(T inst)
{
    if (
        check_atmop_values_ld(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_and_or_xor_exch(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_cas(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_DTYPE;
    }
    if (
        check_atmop_values_add_sub(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_wait(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_NONE;
    }
    if (
        check_atmop_values_waittimeout(getSignalOperation<T>(inst))
       )
    {
            return OPERAND_ATTR_U64;
    }
    return OPERAND_ATTR_INVALID;
}

unsigned InstValidator::getOperand3Attr(Inst inst)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ABS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANECOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANEMASK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANESHUFFLE): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_ADD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ADDQUEUEWRITEINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_AGENTCOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_AGENTID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ALLOCA): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_AND): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ARRIVEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand3_to_attr_atomic<InstAtomic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_ATOMICNORET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITALIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BITEXTRACT): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_BITINSERT): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_BITMASK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITREV): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITSELECT): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_BORROW): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BYTEALIGN): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CARRY): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CASQUEUEWRITEINDEX): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CBR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CEIL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CLASS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CLEARDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CLOCK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CMOV): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_CMP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_COMBINE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_COPYSIGN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CUID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CVT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DEBUGTRAP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DIM): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DIV): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_EXPAND): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FIRSTBIT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FLOOR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FMA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_FRACT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FTOS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNAPPEND): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNATOMIC):
        {
            InstAtomic i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand3_to_attr_gcn_atomic<InstAtomic>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_GCNATOMICNORET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNB32XCHG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNB4XCHG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNBFM): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNCONSUME): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXED): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXEDNARROW): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNFLDEXP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNFREXP_EXP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNFREXP_MANT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNLD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMADS): return OPERAND_ATTR_S64;
        case (Brig::BRIG_OPCODE_GCNMADU): return OPERAND_ATTR_U64;
        case (Brig::BRIG_OPCODE_GCNMAX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMAX3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMED3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMIN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMIN3): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMQSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMQSAD4): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNMSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNPRIORITY): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNQSAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNREGIONALLOC): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNSADD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNSADW): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_GCNSLEEP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNST): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNTRIG_PREOP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GETDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GRIDGROUPS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GRIDSIZE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GROUPBASEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ICALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_INITFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_JOINFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_KERNARGBASEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LANEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LASTBIT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDA): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDF): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDIMAGE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDQUEUEREADINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDQUEUEWRITEINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LEAVEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LERP): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD24): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAD24HI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_MAX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAXCUID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAXWAVEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MEMFENCE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MIN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MOV): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MUL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MUL24): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MUL24HI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MULHI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NCOS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NEG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NEXP2): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NFMA): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_NLOG2): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NOP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NOT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NRCP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NRSQRT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NSIN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NSQRT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NULLPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_OR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_PACK): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_PACKCVT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_PACKETCOMPLETIONSIG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_PACKETID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_POPCOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUERYIMAGE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUERYSAMPLER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUEUEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUEUEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RDIMAGE): return OPERAND_ATTR_CTYPE;
        case (Brig::BRIG_OPCODE_RELEASEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_REM): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RINT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SAD): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_SADHI): return OPERAND_ATTR_DTYPE;
        case (Brig::BRIG_OPCODE_SBR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SCALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SEGMENTP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SETDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SHL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SHR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SHUFFLE): return OPERAND_ATTR_B32;
        case (Brig::BRIG_OPCODE_SIGNAL):
        {
            InstSignal i = inst;
            if (!i) { return OPERAND_ATTR_INVALID; }
            return operand3_to_attr_signal<InstSignal>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_SIGNALNORET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SQRT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ST): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STIMAGE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STOF): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STQUEUEREADINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STQUEUEWRITEINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SUB): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_TRUNC): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_UNPACK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_UNPACKCVT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_UNPACKHI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_UNPACKLO): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAITFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAVEBARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAVEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKGROUPID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKGROUPSIZE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMABSID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMFLATABSID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMFLATID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_XOR): return OPERAND_ATTR_NONE;
        default:
            return OPERAND_ATTR_INVALID;
            break;
    }
} // InstValidator::getOperand3Attr

unsigned InstValidator::getOperand4Attr(Inst inst)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ABS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANECOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANEMASK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ACTIVELANESHUFFLE): return OPERAND_ATTR_B1;
        case (Brig::BRIG_OPCODE_ADD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ADDQUEUEWRITEINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_AGENTCOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_AGENTID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ALLOCA): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_AND): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ARRIVEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ATOMIC): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ATOMICNORET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITALIGN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITEXTRACT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITINSERT): return OPERAND_ATTR_U32;
        case (Brig::BRIG_OPCODE_BITMASK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITREV): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BITSELECT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BORROW): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_BYTEALIGN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CARRY): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CASQUEUEWRITEINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CBR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CEIL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CLASS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CLEARDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CLOCK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CMOV): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CMP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_COMBINE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_COPYSIGN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CUID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CURRENTWORKGROUPSIZE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CVT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DEBUGTRAP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DIM): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_DIV): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_EXPAND): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FIRSTBIT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FLOOR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FMA): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FRACT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FTOS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNAPPEND): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNATOMIC): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNATOMICNORET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNB32XCHG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNB4XCHG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNBFM): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNCONSUME): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXED): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNDIVRELAXEDNARROW): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNFLDEXP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNFREXP_EXP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNFREXP_MANT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNLD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMADS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMADU): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMAX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMAX3): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMED3): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMIN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMIN3): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMQSAD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMQSAD4): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNMSAD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNPRIORITY): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNQSAD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNREGIONALLOC): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNSADD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNSADW): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNSLEEP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNST): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GCNTRIG_PREOP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GETDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GRIDGROUPS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GRIDSIZE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_GROUPBASEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ICALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_INITFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_JOINFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_KERNARGBASEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LANEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LASTBIT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDA): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDF): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDIMAGE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDQUEUEREADINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LDQUEUEWRITEINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LEAVEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_LERP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAD24): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAD24HI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAXCUID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAXWAVEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MEMFENCE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MIN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MOV): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MUL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MUL24): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MUL24HI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MULHI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NCOS): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NEG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NEXP2): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NFMA): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NLOG2): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NOP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NOT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NRCP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NRSQRT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NSIN): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NSQRT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NULLPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_OR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_PACK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_PACKCVT): return OPERAND_ATTR_STYPE;
        case (Brig::BRIG_OPCODE_PACKETCOMPLETIONSIG): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_PACKETID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_POPCOUNT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUERYIMAGE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUERYSAMPLER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUEUEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_QUEUEPTR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RDIMAGE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RELEASEFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_REM): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RINT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SAD): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SADHI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SBR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SCALL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SEGMENTP): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SETDETECTEXCEPT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SHL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SHR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SHUFFLE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SIGNAL): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SIGNALNORET): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SQRT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ST): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STIMAGE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STOF): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STQUEUEREADINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_STQUEUEWRITEINDEX): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SUB): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_TRUNC): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_UNPACK): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_UNPACKCVT): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_UNPACKHI): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_UNPACKLO): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAITFBAR): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAVEBARRIER): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAVEID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKGROUPID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKGROUPSIZE): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMABSID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMFLATABSID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMFLATID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WORKITEMID): return OPERAND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_XOR): return OPERAND_ATTR_NONE;
        default:
            return OPERAND_ATTR_INVALID;
            break;
    }
} // InstValidator::getOperand4Attr

template<class T> unsigned InstValidator::round_to_attr_add(T inst)
{
    if (
        check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NONE;
    }
    if (
        check_type_values_f(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NEAR;
    }
    if (
        check_type_values_sx_ux(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NONE;
    }
    if (
        check_type_values_fx(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NEAR;
    }
    return ROUND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::round_to_attr_cvt(T inst)
{
    if (
        check_type_values_b1_s_u(getSourceType<T>(inst)) &&
        check_type_values_b1_s_u(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NONE;
    }
    if (
        check_type_values_b1(getSourceType<T>(inst)) &&
        check_type_values_f(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NONE;
    }
    if (
        check_type_values_s_u(getSourceType<T>(inst)) &&
        check_type_values_f(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NEAR;
    }
    if (
        check_type_values_f(getSourceType<T>(inst)) &&
        check_type_values_b1(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NONE;
    }
    if (
        check_type_values_f(getSourceType<T>(inst)) &&
        check_type_values_s_u(getType<T>(inst))
       )
    {
            return ROUND_ATTR_ZERO;
    }
    if (
        check_type_values_f32(getSourceType<T>(inst)) &&
        check_type_values_f16(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NEAR;
    }
    if (
        check_type_values_f64(getSourceType<T>(inst)) &&
        check_type_values_f16_f32(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NEAR;
    }
    if (
        check_type_values_f(getSourceType<T>(inst)) &&
        check_type_values_f(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NONE;
    }
    return ROUND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::round_to_attr_div(T inst)
{
    if (
        check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NONE;
    }
    if (
        check_type_values_f(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NEAR;
    }
    if (
        check_type_values_fx(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NEAR;
    }
    return ROUND_ATTR_INVALID;
}

template<class T> unsigned InstValidator::round_to_attr_mul(T inst)
{
    if (
        check_type_values_s32_u32_s64_u64(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NONE;
    }
    if (
        check_type_values_f(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NEAR;
    }
    if (
        check_type_values_sx_ux(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NONE;
    }
    if (
        check_type_values_fx(getType<T>(inst))
       )
    {
            return ROUND_ATTR_NEAR;
    }
    return ROUND_ATTR_INVALID;
}

unsigned InstValidator::getRoundAttr(Inst inst)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ABS): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ADD):
        {
            if (InstMod i = inst)
            {
                return round_to_attr_add<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return round_to_attr_add<InstBasic>(i);
            }
            else
            {
                return ROUND_ATTR_INVALID;
            }
            break;
        }
        case (Brig::BRIG_OPCODE_CEIL): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CMP): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_COPYSIGN): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_CVT):
        {
            InstCvt i = inst;
            if (!i) { return ROUND_ATTR_INVALID; }
            return round_to_attr_cvt<InstCvt>(i);
            break;
        }
        case (Brig::BRIG_OPCODE_DIV):
        {
            if (InstMod i = inst)
            {
                return round_to_attr_div<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return round_to_attr_div<InstBasic>(i);
            }
            else
            {
                return ROUND_ATTR_INVALID;
            }
            break;
        }
        case (Brig::BRIG_OPCODE_FLOOR): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_FMA): return ROUND_ATTR_NEAR;
        case (Brig::BRIG_OPCODE_FRACT): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MAX): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MIN): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_MUL):
        {
            if (InstMod i = inst)
            {
                return round_to_attr_mul<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return round_to_attr_mul<InstBasic>(i);
            }
            else
            {
                return ROUND_ATTR_INVALID;
            }
            break;
        }
        case (Brig::BRIG_OPCODE_MULHI): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_NEG): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_RINT): return ROUND_ATTR_NONE;
        case (Brig::BRIG_OPCODE_SQRT): return ROUND_ATTR_NEAR;
        case (Brig::BRIG_OPCODE_SUB):
        {
            if (InstMod i = inst)
            {
                return round_to_attr_add<InstMod>(i);
            }
            else if (InstBasic i = inst)
            {
                return round_to_attr_add<InstBasic>(i);
            }
            else
            {
                return ROUND_ATTR_INVALID;
            }
            break;
        }
        case (Brig::BRIG_OPCODE_TRUNC): return ROUND_ATTR_NONE;
        default:
            return ROUND_ATTR_INVALID;
            break;
    }
} // InstValidator::getRoundAttr

unsigned InstValidator::getWidthAttr(Inst inst)
{
    switch (inst.opcode())
    {
        case (Brig::BRIG_OPCODE_ACTIVELANECOUNT): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_ACTIVELANEID): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_ACTIVELANEMASK): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_ACTIVELANESHUFFLE): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_ALLOCA): return WIDTH_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ARRIVEFBAR): return WIDTH_ATTR_WAVESIZE;
        case (Brig::BRIG_OPCODE_BARRIER): return WIDTH_ATTR_ALL;
        case (Brig::BRIG_OPCODE_BR): return WIDTH_ATTR_ALL;
        case (Brig::BRIG_OPCODE_CALL): return WIDTH_ATTR_ALL;
        case (Brig::BRIG_OPCODE_CBR): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_GCNLD): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_GCNST): return WIDTH_ATTR_NONE;
        case (Brig::BRIG_OPCODE_ICALL): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_JOINFBAR): return WIDTH_ATTR_WAVESIZE;
        case (Brig::BRIG_OPCODE_LD): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_LEAVEFBAR): return WIDTH_ATTR_WAVESIZE;
        case (Brig::BRIG_OPCODE_SBR): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_SCALL): return WIDTH_ATTR_1;
        case (Brig::BRIG_OPCODE_ST): return WIDTH_ATTR_NONE;
        case (Brig::BRIG_OPCODE_WAITFBAR): return WIDTH_ATTR_WAVESIZE;
        case (Brig::BRIG_OPCODE_WAVEBARRIER): return WIDTH_ATTR_WAVESIZE;
        default:
            return WIDTH_ATTR_INVALID;
            break;
    }
} // InstValidator::getWidthAttr


} // namespace HSAIL_ASM
