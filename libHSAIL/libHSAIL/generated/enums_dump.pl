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
$enums = {
           'BrigVersion' => {
                              'entries' => [
                                             {
                                               'name' => 'BRIG_VERSION_HSAIL_MAJOR',
                                               'val' => '0'
                                             },
                                             {
                                               'name' => 'BRIG_VERSION_HSAIL_MINOR',
                                               'val' => '20131224'
                                             },
                                             {
                                               'name' => 'BRIG_VERSION_BRIG_MAJOR',
                                               'val' => '0'
                                             },
                                             {
                                               'name' => 'BRIG_VERSION_BRIG_MINOR',
                                               'val' => '20131224'
                                             }
                                           ],
                              'nowrap' => 'true',
                              'name' => 'BrigVersion',
                              'nodump' => 'true'
                            },
           'BrigImageFormat' => {
                                  'mnemo#calcState' => 'done',
                                  'mnemo#deps' => [],
                                  'entries' => [
                                                 {
                                                   'name' => 'BRIG_FORMAT_SNORM_INT8',
                                                   'mnemo' => 'snorm_int8',
                                                   'val' => '0'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_SNORM_INT16',
                                                   'mnemo' => 'snorm_int16',
                                                   'val' => '1'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNORM_INT8',
                                                   'mnemo' => 'unorm_int8',
                                                   'val' => '2'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNORM_INT16',
                                                   'mnemo' => 'unorm_int16',
                                                   'val' => '3'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNORM_SHORT_565',
                                                   'mnemo' => 'unorm_short_565',
                                                   'val' => '4'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNORM_SHORT_555',
                                                   'mnemo' => 'unorm_short_555',
                                                   'val' => '5'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNORM_SHORT_101010',
                                                   'mnemo' => 'unorm_short_101010',
                                                   'val' => '6'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_SIGNED_INT8',
                                                   'mnemo' => 'signed_int8',
                                                   'val' => '7'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_SIGNED_INT16',
                                                   'mnemo' => 'signed_int16',
                                                   'val' => '8'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_SIGNED_INT32',
                                                   'mnemo' => 'signed_int32',
                                                   'val' => '9'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNSIGNED_INT8',
                                                   'mnemo' => 'unsigned_int8',
                                                   'val' => '10'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNSIGNED_INT16',
                                                   'mnemo' => 'unsigned_int16',
                                                   'val' => '11'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNSIGNED_INT32',
                                                   'mnemo' => 'unsigned_int32',
                                                   'val' => '12'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_HALF_FLOAT',
                                                   'mnemo' => 'half_float',
                                                   'val' => '13'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_FLOAT',
                                                   'mnemo' => 'float',
                                                   'val' => '14'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNORM_INT24',
                                                   'mnemo' => 'unorm_int24',
                                                   'val' => '15'
                                                 },
                                                 {
                                                   'name' => 'BRIG_FORMAT_UNKNOWN',
                                                   'mnemo' => ''
                                                 }
                                               ],
                                  'name' => 'BrigImageFormat',
                                  'mnemo_scanner' => 'ImageFormat',
                                  'mnemo' => sub { "DUMMY" }
                                },
           'BrigControlDirective' => {
                                       'mnemo#calcState' => 'done',
                                       'mnemo#deps' => [],
                                       'entries' => [
                                                      {
                                                        'skip' => 'true',
                                                        'name' => 'BRIG_CONTROL_NONE',
                                                        'mnemo' => 'none',
                                                        'val' => '0'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_ENABLEBREAKEXCEPTIONS',
                                                        'mnemo' => 'enablebreakexceptions',
                                                        'val' => '1'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_ENABLEDETECTEXCEPTIONS',
                                                        'mnemo' => 'enabledetectexceptions',
                                                        'val' => '2'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_MAXDYNAMICGROUPSIZE',
                                                        'mnemo' => 'maxdynamicgroupsize',
                                                        'val' => '3'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_MAXFLATGRIDSIZE',
                                                        'mnemo' => 'maxflatgridsize',
                                                        'val' => '4'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_MAXFLATWORKGROUPSIZE',
                                                        'mnemo' => 'maxflatworkgroupsize',
                                                        'val' => '5'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU',
                                                        'mnemo' => 'requestedworkgroupspercu',
                                                        'val' => '6'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_REQUIREDDIM',
                                                        'mnemo' => 'requireddim',
                                                        'val' => '7'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_REQUIREDGRIDSIZE',
                                                        'mnemo' => 'requiredgridsize',
                                                        'val' => '8'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_REQUIREDWORKGROUPSIZE',
                                                        'mnemo' => 'requiredworkgroupsize',
                                                        'val' => '9'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS',
                                                        'mnemo' => 'requirenopartialworkgroups',
                                                        'val' => '10'
                                                      }
                                                    ],
                                       'name' => 'BrigControlDirective',
                                       'mnemo' => sub { "DUMMY" },
                                       'mnemo_token' => 'EControl'
                                     },
           'BrigSamplerModifierMask' => {
                                          'entries' => [
                                                         {
                                                           'name' => 'BRIG_SAMPLER_FILTER',
                                                           'val' => '63'
                                                         },
                                                         {
                                                           'name' => 'BRIG_SAMPLER_COORD',
                                                           'val' => '64'
                                                         },
                                                         {
                                                           'name' => 'BRIG_SAMPLER_COORD_UNNORMALIZED',
                                                           'val' => '64'
                                                         }
                                                       ],
                                          'name' => 'BrigSamplerModifierMask',
                                          'nodump' => 'true'
                                        },
           'BrigRound' => {
                            'mnemo_fn' => 'round2str',
                            'entries' => [
                                           {
                                             'name' => 'BRIG_ROUND_NONE',
                                             'val' => '0'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_FLOAT_NEAR_EVEN',
                                             'mnemo' => 'near',
                                             'val' => '1'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_FLOAT_ZERO',
                                             'mnemo' => 'zero',
                                             'val' => '2'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_FLOAT_PLUS_INFINITY',
                                             'mnemo' => 'up',
                                             'val' => '3'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_FLOAT_MINUS_INFINITY',
                                             'mnemo' => 'down',
                                             'val' => '4'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_NEAR_EVEN',
                                             'mnemo' => 'neari',
                                             'val' => '5'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_ZERO',
                                             'mnemo' => 'zeroi',
                                             'val' => '6'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_PLUS_INFINITY',
                                             'mnemo' => 'upi',
                                             'val' => '7'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_MINUS_INFINITY',
                                             'mnemo' => 'downi',
                                             'val' => '8'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_NEAR_EVEN_SAT',
                                             'mnemo' => 'neari_sat',
                                             'val' => '9'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_ZERO_SAT',
                                             'mnemo' => 'zeroi_sat',
                                             'val' => '10'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT',
                                             'mnemo' => 'upi_sat',
                                             'val' => '11'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT',
                                             'mnemo' => 'downi_sat',
                                             'val' => '12     '
                                           }
                                         ],
                            'name' => 'BrigRound',
                            'mnemo' => 'true',
                            'mnemo_token' => '_EMRound'
                          },
           'BrigTypeX' => {
                            'dispatch_proto' => 'template<typename RetType, typename Visitor>
RetType dispatchByType_gen(unsigned type, Visitor& v)',
                            'length_switch' => 'true',
                            'entries' => [
                                           {
                                             'length' => 0,
                                             'dispatch' => 'v.visitNone(type)',
                                             'name' => 'BRIG_TYPE_NONE',
                                             'mnemo' => '',
                                             'val' => '0'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'length' => '8',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U8> >()',
                                             'name' => 'BRIG_TYPE_U8',
                                             'mnemo' => 'u8',
                                             'val' => '1'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'length' => '16',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U16> >()',
                                             'name' => 'BRIG_TYPE_U16',
                                             'mnemo' => 'u16',
                                             'val' => '2'
                                           },
                                           {
                                             'ctype' => 'uint32_t',
                                             'length' => '32',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U32> >()',
                                             'name' => 'BRIG_TYPE_U32',
                                             'mnemo' => 'u32',
                                             'val' => '3'
                                           },
                                           {
                                             'ctype' => 'uint64_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U64> >()',
                                             'name' => 'BRIG_TYPE_U64',
                                             'mnemo' => 'u64',
                                             'val' => '4'
                                           },
                                           {
                                             'ctype' => 'int8_t',
                                             'length' => '8',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S8> >()',
                                             'name' => 'BRIG_TYPE_S8',
                                             'mnemo' => 's8',
                                             'val' => '5'
                                           },
                                           {
                                             'ctype' => 'int16_t',
                                             'length' => '16',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S16> >()',
                                             'name' => 'BRIG_TYPE_S16',
                                             'mnemo' => 's16',
                                             'val' => '6'
                                           },
                                           {
                                             'ctype' => 'int32_t',
                                             'length' => '32',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S32> >()',
                                             'name' => 'BRIG_TYPE_S32',
                                             'mnemo' => 's32',
                                             'val' => '7'
                                           },
                                           {
                                             'ctype' => 'int64_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S64> >()',
                                             'name' => 'BRIG_TYPE_S64',
                                             'mnemo' => 's64',
                                             'val' => '8'
                                           },
                                           {
                                             'ctype' => 'f16_t',
                                             'length' => '16',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F16> >()',
                                             'name' => 'BRIG_TYPE_F16',
                                             'mnemo' => 'f16',
                                             'val' => '9'
                                           },
                                           {
                                             'ctype' => 'float',
                                             'length' => '32',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F32> >()',
                                             'name' => 'BRIG_TYPE_F32',
                                             'mnemo' => 'f32',
                                             'val' => '10'
                                           },
                                           {
                                             'ctype' => 'double',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F64> >()',
                                             'name' => 'BRIG_TYPE_F64',
                                             'mnemo' => 'f64',
                                             'val' => '11'
                                           },
                                           {
                                             'ctype' => 'bool',
                                             'length' => '1',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B1> >()',
                                             'name' => 'BRIG_TYPE_B1',
                                             'mnemo' => 'b1',
                                             'val' => '12'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'length' => '8',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B8> >()',
                                             'name' => 'BRIG_TYPE_B8',
                                             'mnemo' => 'b8',
                                             'val' => '13'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'length' => '16',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B16> >()',
                                             'name' => 'BRIG_TYPE_B16',
                                             'mnemo' => 'b16',
                                             'val' => '14'
                                           },
                                           {
                                             'ctype' => 'uint32_t',
                                             'length' => '32',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B32> >()',
                                             'name' => 'BRIG_TYPE_B32',
                                             'mnemo' => 'b32',
                                             'val' => '15'
                                           },
                                           {
                                             'ctype' => 'uint64_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B64> >()',
                                             'name' => 'BRIG_TYPE_B64',
                                             'mnemo' => 'b64',
                                             'val' => '16'
                                           },
                                           {
                                             'ctype' => 'b128_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B128> >()',
                                             'name' => 'BRIG_TYPE_B128',
                                             'mnemo' => 'b128',
                                             'val' => '17'
                                           },
                                           {
                                             'length' => 0,
                                             'dispatch' => 'v.visitNone(type)',
                                             'name' => 'BRIG_TYPE_SAMP',
                                             'mnemo' => 'samp',
                                             'val' => '18'
                                           },
                                           {
                                             'length' => 0,
                                             'dispatch' => 'v.visitNone(type)',
                                             'name' => 'BRIG_TYPE_ROIMG',
                                             'mnemo' => 'roimg',
                                             'val' => '19'
                                           },
                                           {
                                             'length' => 0,
                                             'dispatch' => 'v.visitNone(type)',
                                             'name' => 'BRIG_TYPE_RWIMG',
                                             'mnemo' => 'rwimg',
                                             'val' => '20'
                                           },
                                           {
                                             'length' => '32',
                                             'dispatch' => 'v.visitNone(type)',
                                             'name' => 'BRIG_TYPE_SIG32',
                                             'mnemo' => 'sig32',
                                             'val' => '21'
                                           },
                                           {
                                             'length' => '64',
                                             'dispatch' => 'v.visitNone(type)',
                                             'name' => 'BRIG_TYPE_SIG64',
                                             'mnemo' => 'sig64',
                                             'val' => '22'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'length' => '32',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U8X4> >()',
                                             'name' => 'BRIG_TYPE_U8X4',
                                             'mnemo' => 'u8x4',
                                             'val' => 'BRIG_TYPE_U8  | BRIG_TYPE_PACK_32'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U8X8> >()',
                                             'name' => 'BRIG_TYPE_U8X8',
                                             'mnemo' => 'u8x8',
                                             'val' => 'BRIG_TYPE_U8  | BRIG_TYPE_PACK_64'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U8X16> >()',
                                             'name' => 'BRIG_TYPE_U8X16',
                                             'mnemo' => 'u8x16',
                                             'val' => 'BRIG_TYPE_U8  | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'length' => '32',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U16X2> >()',
                                             'name' => 'BRIG_TYPE_U16X2',
                                             'mnemo' => 'u16x2',
                                             'val' => 'BRIG_TYPE_U16 | BRIG_TYPE_PACK_32'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U16X4> >()',
                                             'name' => 'BRIG_TYPE_U16X4',
                                             'mnemo' => 'u16x4',
                                             'val' => 'BRIG_TYPE_U16 | BRIG_TYPE_PACK_64'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U16X8> >()',
                                             'name' => 'BRIG_TYPE_U16X8',
                                             'mnemo' => 'u16x8',
                                             'val' => 'BRIG_TYPE_U16 | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'uint32_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U32X2> >()',
                                             'name' => 'BRIG_TYPE_U32X2',
                                             'mnemo' => 'u32x2',
                                             'val' => 'BRIG_TYPE_U32 | BRIG_TYPE_PACK_64'
                                           },
                                           {
                                             'ctype' => 'uint32_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U32X4> >()',
                                             'name' => 'BRIG_TYPE_U32X4',
                                             'mnemo' => 'u32x4',
                                             'val' => 'BRIG_TYPE_U32 | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'uint64_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U64X2> >()',
                                             'name' => 'BRIG_TYPE_U64X2',
                                             'mnemo' => 'u64x2',
                                             'val' => 'BRIG_TYPE_U64 | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'int8_t',
                                             'length' => '32',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S8X4> >()',
                                             'name' => 'BRIG_TYPE_S8X4',
                                             'mnemo' => 's8x4',
                                             'val' => 'BRIG_TYPE_S8  | BRIG_TYPE_PACK_32'
                                           },
                                           {
                                             'ctype' => 'int8_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S8X8> >()',
                                             'name' => 'BRIG_TYPE_S8X8',
                                             'mnemo' => 's8x8',
                                             'val' => 'BRIG_TYPE_S8  | BRIG_TYPE_PACK_64'
                                           },
                                           {
                                             'ctype' => 'int8_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S8X16> >()',
                                             'name' => 'BRIG_TYPE_S8X16',
                                             'mnemo' => 's8x16',
                                             'val' => 'BRIG_TYPE_S8  | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'int16_t',
                                             'length' => '32',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S16X2> >()',
                                             'name' => 'BRIG_TYPE_S16X2',
                                             'mnemo' => 's16x2',
                                             'val' => 'BRIG_TYPE_S16 | BRIG_TYPE_PACK_32'
                                           },
                                           {
                                             'ctype' => 'int16_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S16X4> >()',
                                             'name' => 'BRIG_TYPE_S16X4',
                                             'mnemo' => 's16x4',
                                             'val' => 'BRIG_TYPE_S16 | BRIG_TYPE_PACK_64'
                                           },
                                           {
                                             'ctype' => 'int16_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S16X8> >()',
                                             'name' => 'BRIG_TYPE_S16X8',
                                             'mnemo' => 's16x8',
                                             'val' => 'BRIG_TYPE_S16 | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'int32_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S32X2> >()',
                                             'name' => 'BRIG_TYPE_S32X2',
                                             'mnemo' => 's32x2',
                                             'val' => 'BRIG_TYPE_S32 | BRIG_TYPE_PACK_64'
                                           },
                                           {
                                             'ctype' => 'int32_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S32X4> >()',
                                             'name' => 'BRIG_TYPE_S32X4',
                                             'mnemo' => 's32x4',
                                             'val' => 'BRIG_TYPE_S32 | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'int64_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S64X2> >()',
                                             'name' => 'BRIG_TYPE_S64X2',
                                             'mnemo' => 's64x2',
                                             'val' => 'BRIG_TYPE_S64 | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'f16_t',
                                             'length' => '32',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F16X2> >()',
                                             'name' => 'BRIG_TYPE_F16X2',
                                             'mnemo' => 'f16x2',
                                             'val' => 'BRIG_TYPE_F16 | BRIG_TYPE_PACK_32'
                                           },
                                           {
                                             'ctype' => 'f16_t',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F16X4> >()',
                                             'name' => 'BRIG_TYPE_F16X4',
                                             'mnemo' => 'f16x4',
                                             'val' => 'BRIG_TYPE_F16 | BRIG_TYPE_PACK_64'
                                           },
                                           {
                                             'ctype' => 'f16_t',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F16X8> >()',
                                             'name' => 'BRIG_TYPE_F16X8',
                                             'mnemo' => 'f16x8',
                                             'val' => 'BRIG_TYPE_F16 | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'float',
                                             'length' => '64',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F32X2> >()',
                                             'name' => 'BRIG_TYPE_F32X2',
                                             'mnemo' => 'f32x2',
                                             'val' => 'BRIG_TYPE_F32 | BRIG_TYPE_PACK_64'
                                           },
                                           {
                                             'ctype' => 'float',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F32X4> >()',
                                             'name' => 'BRIG_TYPE_F32X4',
                                             'mnemo' => 'f32x4',
                                             'val' => 'BRIG_TYPE_F32 | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'ctype' => 'double',
                                             'length' => '128',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F64X2> >()',
                                             'name' => 'BRIG_TYPE_F64X2',
                                             'mnemo' => 'f64x2',
                                             'val' => 'BRIG_TYPE_F64 | BRIG_TYPE_PACK_128'
                                           },
                                           {
                                             'length' => 0,
                                             'dispatch' => 'v.visitNone(type)',
                                             'skip' => 'true',
                                             'name' => 'BRIG_TYPE_INVALID',
                                             'mnemo' => 'invalid',
                                             'val' => '-1 '
                                           }
                                         ],
                            'dispatch#calcState' => 'done',
                            'mnemo' => sub { "DUMMY" },
                            'length_proto' => 'int brigtype_get_length(unsigned arg)',
                            'length_default' => 'return 0',
                            'dispatch_arg' => 'type',
                            'length#deps' => [],
                            'mnemo_token' => '_EMType',
                            'mnemo#deps' => [],
                            'dispatch_switch' => 'true',
                            'dispatch' => sub { "DUMMY" },
                            'name' => 'BrigTypeX',
                            'dispatch_incfile' => 'TemplateUtilities',
                            'dispatch_default' => 'return v.visitNone(type)',
                            'mnemo#calcState' => 'done',
                            'length' => sub { "DUMMY" },
                            'dispatch#deps' => [],
                            'length#calcState' => 'done'
                          },
           'BrigOpcode' => {
                             'entries' => [
                                            {
                                              'psopnd' => 'NoOperands',
                                              'name' => 'BRIG_OPCODE_NOP',
                                              'mnemo' => 'nop',
                                              'val' => '0',
                                              'opcodeparser' => 'parseMnemoNop',
                                              'opndparser' => '&Parser::parseNoOperands',
                                              'k' => 'NOP',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NOP>                   (inst)',
                                              'hasType' => 'false',
                                              'pscode' => 'Nop'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CODEBLOCKEND',
                                              'mnemo' => 'codeblockend',
                                              'val' => '1',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CODEBLOCKEND>          (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ABS',
                                              'mnemo' => 'abs',
                                              'val' => '2',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ABS>                   (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ADD',
                                              'mnemo' => 'add',
                                              'val' => '3',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ADD>                   (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BORROW',
                                              'mnemo' => 'borrow',
                                              'val' => '4',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BORROW>                (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CARRY',
                                              'mnemo' => 'carry',
                                              'val' => '5',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CARRY>                 (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CEIL',
                                              'mnemo' => 'ceil',
                                              'val' => '6',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CEIL>                  (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_COPYSIGN',
                                              'mnemo' => 'copysign',
                                              'val' => '7',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_COPYSIGN>              (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_DIV',
                                              'mnemo' => 'div',
                                              'val' => '8',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_DIV>                   (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_FLOOR',
                                              'mnemo' => 'floor',
                                              'val' => '9',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_FLOOR>                 (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_FMA',
                                              'mnemo' => 'fma',
                                              'val' => '10',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_FMA>                   (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_FRACT',
                                              'mnemo' => 'fract',
                                              'val' => '11',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_FRACT>                 (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MAD',
                                              'mnemo' => 'mad',
                                              'val' => '12',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MAD>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MAX',
                                              'mnemo' => 'max',
                                              'val' => '13',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MAX>                   (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MIN',
                                              'mnemo' => 'min',
                                              'val' => '14',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MIN>                   (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MUL',
                                              'mnemo' => 'mul',
                                              'val' => '15',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MUL>                   (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MULHI',
                                              'mnemo' => 'mulhi',
                                              'val' => '16',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MULHI>                 (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NEG',
                                              'mnemo' => 'neg',
                                              'val' => '17',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NEG>                   (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_REM',
                                              'mnemo' => 'rem',
                                              'val' => '18',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_REM>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_RINT',
                                              'mnemo' => 'rint',
                                              'val' => '19',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_RINT>                  (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SQRT',
                                              'mnemo' => 'sqrt',
                                              'val' => '20',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SQRT>                  (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SUB',
                                              'mnemo' => 'sub',
                                              'val' => '21',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SUB>                   (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_TRUNC',
                                              'mnemo' => 'trunc',
                                              'val' => '22',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_TRUNC>                 (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MAD24',
                                              'mnemo' => 'mad24',
                                              'val' => '23',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MAD24>                 (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MAD24HI',
                                              'mnemo' => 'mad24hi',
                                              'val' => '24',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MAD24HI>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MUL24',
                                              'mnemo' => 'mul24',
                                              'val' => '25',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MUL24>                 (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MUL24HI',
                                              'mnemo' => 'mul24hi',
                                              'val' => '26',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MUL24HI>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SHL',
                                              'mnemo' => 'shl',
                                              'val' => '27',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SHL>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SHR',
                                              'mnemo' => 'shr',
                                              'val' => '28',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SHR>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_AND',
                                              'mnemo' => 'and',
                                              'val' => '29',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_AND>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NOT',
                                              'mnemo' => 'not',
                                              'val' => '30',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NOT>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_OR',
                                              'mnemo' => 'or',
                                              'val' => '31',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_OR>                    (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_POPCOUNT',
                                              'mnemo' => 'popcount',
                                              'val' => '32',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_POPCOUNT>              (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_XOR',
                                              'mnemo' => 'xor',
                                              'val' => '33',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_XOR>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BITEXTRACT',
                                              'mnemo' => 'bitextract',
                                              'val' => '34',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BITEXTRACT>            (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BITINSERT',
                                              'mnemo' => 'bitinsert',
                                              'val' => '35',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BITINSERT>             (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BITMASK',
                                              'mnemo' => 'bitmask',
                                              'val' => '36',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BITMASK>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BITREV',
                                              'mnemo' => 'bitrev',
                                              'val' => '37',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BITREV>                (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BITSELECT',
                                              'mnemo' => 'bitselect',
                                              'val' => '38',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BITSELECT>             (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_FIRSTBIT',
                                              'mnemo' => 'firstbit',
                                              'val' => '39',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_FIRSTBIT>              (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LASTBIT',
                                              'mnemo' => 'lastbit',
                                              'val' => '40',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LASTBIT>               (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_COMBINE',
                                              'mnemo' => 'combine',
                                              'val' => '41',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_COMBINE>               (HSAIL_ASM::InstSourceType(inst))',
                                              'mnemo_token' => 'EInstruction_Vx',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_EXPAND',
                                              'mnemo' => 'expand',
                                              'val' => '42',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_EXPAND>                (HSAIL_ASM::InstSourceType(inst))',
                                              'mnemo_token' => 'EInstruction_Vx',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LDA',
                                              'mnemo' => 'lda',
                                              'val' => '43',
                                              'opcodeparser' => 'parseMnemoAddr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'ADDR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LDA>                   (HSAIL_ASM::InstAddr(inst))',
                                              'pscode' => 'Addr'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LDC',
                                              'mnemo' => 'ldc',
                                              'val' => '44',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LDC>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MOV',
                                              'mnemo' => 'mov',
                                              'val' => '45',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MOV>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SHUFFLE',
                                              'mnemo' => 'shuffle',
                                              'val' => '46',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SHUFFLE>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_UNPACKHI',
                                              'mnemo' => 'unpackhi',
                                              'val' => '47',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_UNPACKHI>              (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_UNPACKLO',
                                              'mnemo' => 'unpacklo',
                                              'val' => '48',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_UNPACKLO>              (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_PACK',
                                              'mnemo' => 'pack',
                                              'val' => '49',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_PACK>                  (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_UNPACK',
                                              'mnemo' => 'unpack',
                                              'val' => '50',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_UNPACK>                (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CMOV',
                                              'mnemo' => 'cmov',
                                              'val' => '51',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CMOV>                  (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CLASS',
                                              'mnemo' => 'class',
                                              'val' => '52',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CLASS>                 (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NCOS',
                                              'mnemo' => 'ncos',
                                              'val' => '53',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NCOS>                  (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NEXP2',
                                              'mnemo' => 'nexp2',
                                              'val' => '54',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NEXP2>                 (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NFMA',
                                              'mnemo' => 'nfma',
                                              'val' => '55',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NFMA>                  (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NLOG2',
                                              'mnemo' => 'nlog2',
                                              'val' => '56',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NLOG2>                 (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NRCP',
                                              'mnemo' => 'nrcp',
                                              'val' => '57',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NRCP>                  (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NRSQRT',
                                              'mnemo' => 'nrsqrt',
                                              'val' => '58',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NRSQRT>                (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NSIN',
                                              'mnemo' => 'nsin',
                                              'val' => '59',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NSIN>                  (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NSQRT',
                                              'mnemo' => 'nsqrt',
                                              'val' => '60',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NSQRT>                 (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BITALIGN',
                                              'mnemo' => 'bitalign',
                                              'val' => '61',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BITALIGN>              (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BYTEALIGN',
                                              'mnemo' => 'bytealign',
                                              'val' => '62',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BYTEALIGN>             (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_PACKCVT',
                                              'mnemo' => 'packcvt',
                                              'val' => '63',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_PACKCVT>               (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_UNPACKCVT',
                                              'mnemo' => 'unpackcvt',
                                              'val' => '64',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_UNPACKCVT>             (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LERP',
                                              'mnemo' => 'lerp',
                                              'val' => '65',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LERP>                  (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SAD',
                                              'mnemo' => 'sad',
                                              'val' => '66',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SAD>                   (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SADHI',
                                              'mnemo' => 'sadhi',
                                              'val' => '67',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SADHI>                 (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SEGMENTP',
                                              'mnemo' => 'segmentp',
                                              'val' => '68',
                                              'opcodeparser' => 'parseMnemoSegCvt',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SEG_CVT',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SEGMENTP>              (HSAIL_ASM::InstSegCvt(inst))',
                                              'pscode' => 'SegCvt'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_FTOS',
                                              'mnemo' => 'ftos',
                                              'val' => '69',
                                              'opcodeparser' => 'parseMnemoSegCvt',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SEG_CVT',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_FTOS>                  (HSAIL_ASM::InstSegCvt(inst))',
                                              'pscode' => 'SegCvt'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_STOF',
                                              'mnemo' => 'stof',
                                              'val' => '70',
                                              'opcodeparser' => 'parseMnemoSegCvt',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SEG_CVT',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_STOF>                  (HSAIL_ASM::InstSegCvt(inst))',
                                              'pscode' => 'SegCvt'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CMP',
                                              'mnemo' => 'cmp',
                                              'val' => '71',
                                              'opcodeparser' => 'parseMnemoCmp',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'CMP',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CMP>                   (HSAIL_ASM::InstCmp(inst))',
                                              'ftz' => 'true',
                                              'pscode' => 'Cmp'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CVT',
                                              'mnemo' => 'cvt',
                                              'val' => '72',
                                              'opcodeparser' => 'parseMnemoCvt',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'CVT',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CVT>                   (HSAIL_ASM::InstCvt(inst))',
                                              'ftz' => 'true',
                                              'pscode' => 'Cvt'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LD',
                                              'mnemo' => 'ld',
                                              'val' => '73',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LD>                    (HSAIL_ASM::InstMem(inst))',
                                              'semsupport' => 'true',
                                              'has_memory_order' => 'true',
                                              'mnemo_token' => 'EInstruction_Vx',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ST',
                                              'mnemo' => 'st',
                                              'val' => '74',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ST>                    (HSAIL_ASM::InstMem(inst))',
                                              'semsupport' => 'true',
                                              'has_memory_order' => 'true',
                                              'mnemo_token' => 'EInstruction_Vx',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ATOMIC',
                                              'mnemo' => 'atomic',
                                              'val' => '75',
                                              'opcodeparser' => 'parseMnemoAtomic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'ATOMIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ATOMIC>                (HSAIL_ASM::InstAtomic(inst))',
                                              'pscode' => 'Atomic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ATOMICNORET',
                                              'mnemo' => 'atomicnoret',
                                              'val' => '76',
                                              'opcodeparser' => 'parseMnemoAtomic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'ATOMIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ATOMICNORET>           (HSAIL_ASM::InstAtomic(inst))',
                                              'pscode' => 'Atomic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SIGNAL',
                                              'mnemo' => 'signal',
                                              'val' => '77',
                                              'opcodeparser' => 'parseMnemoSignal',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SIGNAL',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SIGNAL>                (HSAIL_ASM::InstSignal(inst))',
                                              'pscode' => 'Signal'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SIGNALNORET',
                                              'mnemo' => 'signalnoret',
                                              'val' => '78',
                                              'opcodeparser' => 'parseMnemoSignal',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SIGNAL',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SIGNALNORET>           (HSAIL_ASM::InstSignal(inst))',
                                              'pscode' => 'Signal'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MEMFENCE',
                                              'mnemo' => 'memfence',
                                              'val' => '79',
                                              'opcodeparser' => 'parseMnemoMemFence',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'MEM_FENCE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MEMFENCE>              (HSAIL_ASM::InstMemFence(inst))',
                                              'pscode' => 'MemFence'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_RDIMAGE',
                                              'mnemo' => 'rdimage',
                                              'val' => '80',
                                              'opcodeparser' => 'parseMnemoImage',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'IMAGE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_RDIMAGE>               (HSAIL_ASM::InstImage(inst))',
                                              'pscode' => 'Image'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LDIMAGE',
                                              'mnemo' => 'ldimage',
                                              'val' => '81',
                                              'opcodeparser' => 'parseMnemoImage',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'IMAGE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LDIMAGE>               (HSAIL_ASM::InstImage(inst))',
                                              'pscode' => 'Image'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_STIMAGE',
                                              'mnemo' => 'stimage',
                                              'val' => '82',
                                              'opcodeparser' => 'parseMnemoImage',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'IMAGE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_STIMAGE>               (HSAIL_ASM::InstImage(inst))',
                                              'pscode' => 'Image'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ATOMICIMAGE',
                                              'mnemo' => 'atomicimage',
                                              'val' => '83',
                                              'opcodeparser' => 'parseMnemoAtomicImage',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'ATOMIC_IMAGE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ATOMICIMAGE>           (HSAIL_ASM::InstAtomicImage(inst))',
                                              'pscode' => 'AtomicImage'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ATOMICIMAGENORET',
                                              'mnemo' => 'atomicimagenoret',
                                              'val' => '84',
                                              'opcodeparser' => 'parseMnemoAtomicImage',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'ATOMIC_IMAGE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ATOMICIMAGENORET>      (HSAIL_ASM::InstAtomicImage(inst))',
                                              'pscode' => 'AtomicImage'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUERYIMAGEARRAY',
                                              'mnemo' => 'queryimagearray',
                                              'val' => '85',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEARRAY>       (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUERYIMAGEDEPTH',
                                              'mnemo' => 'queryimagedepth',
                                              'val' => '86',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEDEPTH>       (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUERYIMAGEFORMAT',
                                              'mnemo' => 'queryimageformat',
                                              'val' => '87',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEFORMAT>      (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUERYIMAGEHEIGHT',
                                              'mnemo' => 'queryimageheight',
                                              'val' => '88',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEHEIGHT>      (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUERYIMAGEORDER',
                                              'mnemo' => 'queryimageorder',
                                              'val' => '89',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEORDER>       (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUERYIMAGEWIDTH',
                                              'mnemo' => 'queryimagewidth',
                                              'val' => '90',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUERYIMAGEWIDTH>       (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUERYSAMPLERBOUNDARY',
                                              'mnemo' => 'querysamplerboundary',
                                              'val' => '91',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUERYSAMPLERBOUNDARY>  (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUERYSAMPLERCOORD',
                                              'mnemo' => 'querysamplercoord',
                                              'val' => '92',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUERYSAMPLERCOORD>     (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUERYSAMPLERFILTER',
                                              'mnemo' => 'querysamplerfilter',
                                              'val' => '93',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUERYSAMPLERFILTER>    (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CBR',
                                              'mnemo' => 'cbr',
                                              'val' => '94',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CBR>                   (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BRN',
                                              'mnemo' => 'brn',
                                              'val' => '95',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BRN>                   (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_BARRIER',
                                              'mnemo' => 'barrier',
                                              'val' => '96',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_BARRIER>               (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_WAVEBARRIER',
                                              'mnemo' => 'wavebarrier',
                                              'val' => '97',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_WAVEBARRIER>           (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ARRIVEFBAR',
                                              'mnemo' => 'arrivefbar',
                                              'val' => '98',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ARRIVEFBAR>            (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_INITFBAR',
                                              'mnemo' => 'initfbar',
                                              'val' => '99',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_INITFBAR>              (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_JOINFBAR',
                                              'mnemo' => 'joinfbar',
                                              'val' => '100',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_JOINFBAR>              (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LEAVEFBAR',
                                              'mnemo' => 'leavefbar',
                                              'val' => '101',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LEAVEFBAR>             (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_RELEASEFBAR',
                                              'mnemo' => 'releasefbar',
                                              'val' => '102',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_RELEASEFBAR>           (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_WAITFBAR',
                                              'mnemo' => 'waitfbar',
                                              'val' => '103',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_WAITFBAR>              (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LDF',
                                              'mnemo' => 'ldf',
                                              'val' => '104',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LDF>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ACTIVELANECOUNT',
                                              'mnemo' => 'activelanecount',
                                              'val' => '105',
                                              'opcodeparser' => 'parseMnemoLane',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'LANE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ACTIVELANECOUNT>       (HSAIL_ASM::InstLane(inst))',
                                              'pscode' => 'Lane'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ACTIVELANEID',
                                              'mnemo' => 'activelaneid',
                                              'val' => '106',
                                              'opcodeparser' => 'parseMnemoLane',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'LANE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ACTIVELANEID>          (HSAIL_ASM::InstLane(inst))',
                                              'pscode' => 'Lane'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ACTIVELANEMASK',
                                              'mnemo' => 'activelanemask',
                                              'val' => '107',
                                              'opcodeparser' => 'parseMnemoLane',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'LANE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ACTIVELANEMASK>        (HSAIL_ASM::InstLane(inst))',
                                              'pscode' => 'Lane'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ACTIVELANESHUFFLE',
                                              'mnemo' => 'activelaneshuffle',
                                              'val' => '108',
                                              'opcodeparser' => 'parseMnemoLane',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'LANE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ACTIVELANESHUFFLE>     (HSAIL_ASM::InstLane(inst))',
                                              'pscode' => 'Lane'
                                            },
                                            {
                                              'psopnd' => 'CallOperands',
                                              'name' => 'BRIG_OPCODE_CALL',
                                              'mnemo' => 'call',
                                              'val' => '109',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseCallOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CALL>                  (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_RET',
                                              'mnemo' => 'ret',
                                              'val' => '110',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_RET>                   (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ALLOCA',
                                              'mnemo' => 'alloca',
                                              'val' => '111',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ALLOCA>                (HSAIL_ASM::InstMem(inst))',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_ADDQUEUEWRITEINDEX',
                                              'mnemo' => 'addqueuewriteindex',
                                              'val' => '112',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_ADDQUEUEWRITEINDEX>    (HSAIL_ASM::InstQueue(inst))',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CASQUEUEWRITEINDEX',
                                              'mnemo' => 'casqueuewriteindex',
                                              'val' => '113',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CASQUEUEWRITEINDEX>    (HSAIL_ASM::InstQueue(inst))',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CLEARDETECTEXCEPT',
                                              'mnemo' => 'cleardetectexcept',
                                              'val' => '114',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CLEARDETECTEXCEPT>     (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CLOCK',
                                              'mnemo' => 'clock',
                                              'val' => '115',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CLOCK>                 (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CUID',
                                              'mnemo' => 'cuid',
                                              'val' => '116',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CUID>                  (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_CURRENTWORKGROUPSIZE',
                                              'mnemo' => 'currentworkgroupsize',
                                              'val' => '117',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_CURRENTWORKGROUPSIZE>  (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_DEBUGTRAP',
                                              'mnemo' => 'debugtrap',
                                              'val' => '118',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_DEBUGTRAP>             (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_DIM',
                                              'mnemo' => 'dim',
                                              'val' => '119',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_DIM>                   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GETDETECTEXCEPT',
                                              'mnemo' => 'getdetectexcept',
                                              'val' => '120',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GETDETECTEXCEPT>       (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GRIDGROUPS',
                                              'mnemo' => 'gridgroups',
                                              'val' => '121',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GRIDGROUPS>            (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GRIDSIZE',
                                              'mnemo' => 'gridsize',
                                              'val' => '122',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GRIDSIZE>              (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LANEID',
                                              'mnemo' => 'laneid',
                                              'val' => '123',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LANEID>                (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LDQUEUEREADINDEX',
                                              'mnemo' => 'ldqueuereadindex',
                                              'val' => '124',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LDQUEUEREADINDEX>      (HSAIL_ASM::InstQueue(inst))',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_LDQUEUEWRITEINDEX',
                                              'mnemo' => 'ldqueuewriteindex',
                                              'val' => '125',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_LDQUEUEWRITEINDEX>     (HSAIL_ASM::InstQueue(inst))',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MAXCUID',
                                              'mnemo' => 'maxcuid',
                                              'val' => '126',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MAXCUID>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_MAXWAVEID',
                                              'mnemo' => 'maxwaveid',
                                              'val' => '127',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_MAXWAVEID>             (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_NULLPTR',
                                              'mnemo' => 'nullptr',
                                              'val' => '128',
                                              'opcodeparser' => 'parseMnemoSeg',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SEG',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_NULLPTR>               (HSAIL_ASM::InstSeg(inst))',
                                              'pscode' => 'Seg'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_PACKETCOMPLETIONSIG',
                                              'mnemo' => 'packetcompletionsig',
                                              'val' => '129',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_PACKETCOMPLETIONSIG>   (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_PACKETID',
                                              'mnemo' => 'packetid',
                                              'val' => '130',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_PACKETID>              (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUEUEID',
                                              'mnemo' => 'queueid',
                                              'val' => '131',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUEUEID>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_QUEUEPTR',
                                              'mnemo' => 'queueptr',
                                              'val' => '132',
                                              'opcodeparser' => 'parseMnemoSeg',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SEG',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_QUEUEPTR>              (HSAIL_ASM::InstSeg(inst))',
                                              'pscode' => 'Seg'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SERVICEQUEUEPTR',
                                              'mnemo' => 'servicequeueptr',
                                              'val' => '133',
                                              'opcodeparser' => 'parseMnemoSeg',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'SEG',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SERVICEQUEUEPTR>       (HSAIL_ASM::InstSeg(inst))',
                                              'pscode' => 'Seg'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_SETDETECTEXCEPT',
                                              'mnemo' => 'setdetectexcept',
                                              'val' => '134',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_SETDETECTEXCEPT>       (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_STQUEUEWRITEINDEX',
                                              'mnemo' => 'stqueuewriteindex',
                                              'val' => '135',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_STQUEUEWRITEINDEX>     (HSAIL_ASM::InstQueue(inst))',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_WAVEID',
                                              'mnemo' => 'waveid',
                                              'val' => '136',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_WAVEID>                (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_WORKGROUPID',
                                              'mnemo' => 'workgroupid',
                                              'val' => '137',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_WORKGROUPID>           (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_WORKGROUPSIZE',
                                              'mnemo' => 'workgroupsize',
                                              'val' => '138',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_WORKGROUPSIZE>         (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_WORKITEMABSID',
                                              'mnemo' => 'workitemabsid',
                                              'val' => '139',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_WORKITEMABSID>         (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_WORKITEMFLATABSID',
                                              'mnemo' => 'workitemflatabsid',
                                              'val' => '140',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_WORKITEMFLATABSID>     (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_WORKITEMFLATID',
                                              'mnemo' => 'workitemflatid',
                                              'val' => '141',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_WORKITEMFLATID>        (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_WORKITEMID',
                                              'mnemo' => 'workitemid',
                                              'val' => '142',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_WORKITEMID>            (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMADU',
                                              'mnemo' => 'gcn_madu',
                                              'val' => '(1u << 15) |  0',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMADU>               (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMADS',
                                              'mnemo' => 'gcn_mads',
                                              'val' => '(1u << 15) |  1',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMADS>               (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMAX3',
                                              'mnemo' => 'gcn_max3',
                                              'val' => '(1u << 15) |  2',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMAX3>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMIN3',
                                              'mnemo' => 'gcn_min3',
                                              'val' => '(1u << 15) |  3',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMIN3>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMED3',
                                              'mnemo' => 'gcn_med3',
                                              'val' => '(1u << 15) |  4',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMED3>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNFLDEXP',
                                              'mnemo' => 'gcn_fldexp',
                                              'val' => '(1u << 15) |  5',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNFLDEXP>             (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNFREXP_EXP',
                                              'mnemo' => 'gcn_frexp_exp',
                                              'val' => '(1u << 15) |  6',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNFREXP_EXP>          (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNFREXP_MANT',
                                              'mnemo' => 'gcn_frexp_mant',
                                              'val' => '(1u << 15) |  7',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNFREXP_MANT>         (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNTRIG_PREOP',
                                              'mnemo' => 'gcn_trig_preop',
                                              'val' => '(1u << 15) |  8',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNTRIG_PREOP>         (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNBFM',
                                              'mnemo' => 'gcn_bfm',
                                              'val' => '(1u << 15) |  9',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNBFM>                (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNLD',
                                              'mnemo' => 'gcn_ld',
                                              'val' => '(1u << 15) | 10',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNLD>                 (HSAIL_ASM::InstMem(inst))',
                                              'semsupport' => 'true',
                                              'has_memory_order' => 'true',
                                              'mnemo_token' => 'EInstruction_Vx',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNST',
                                              'mnemo' => 'gcn_st',
                                              'val' => '(1u << 15) | 11',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNST>                 (HSAIL_ASM::InstMem(inst))',
                                              'semsupport' => 'true',
                                              'has_memory_order' => 'true',
                                              'mnemo_token' => 'EInstruction_Vx',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNATOMIC',
                                              'mnemo' => 'gcn_atomic',
                                              'val' => '(1u << 15) | 12',
                                              'opcodeparser' => 'parseMnemoAtomic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'ATOMIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNATOMIC>             (HSAIL_ASM::InstAtomic(inst))',
                                              'pscode' => 'Atomic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNATOMICNORET',
                                              'mnemo' => 'gcn_atomicNoRet',
                                              'val' => '(1u << 15) | 13',
                                              'opcodeparser' => 'parseMnemoAtomic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'ATOMIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNATOMICNORET>        (HSAIL_ASM::InstAtomic(inst))',
                                              'pscode' => 'Atomic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNSLEEP',
                                              'mnemo' => 'gcn_sleep',
                                              'val' => '(1u << 15) | 14',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNSLEEP>              (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNPRIORITY',
                                              'mnemo' => 'gcn_priority',
                                              'val' => '(1u << 15) | 15',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNPRIORITY>           (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNREGIONALLOC',
                                              'mnemo' => 'gcn_region_alloc',
                                              'val' => '(1u << 15) | 16',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNREGIONALLOC>        (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMSAD',
                                              'mnemo' => 'gcn_msad',
                                              'val' => '(1u << 15) | 17',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMSAD>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNQSAD',
                                              'mnemo' => 'gcn_qsad',
                                              'val' => '(1u << 15) | 18',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNQSAD>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMQSAD',
                                              'mnemo' => 'gcn_mqsad',
                                              'val' => '(1u << 15) | 19',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMQSAD>              (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMQSAD4',
                                              'mnemo' => 'gcn_mqsad4',
                                              'val' => '(1u << 15) | 20',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMQSAD4>             (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNSADW',
                                              'mnemo' => 'gcn_sadw',
                                              'val' => '(1u << 15) | 21',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNSADW>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNSADD',
                                              'mnemo' => 'gcn_sadd',
                                              'val' => '(1u << 15) | 22',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNSADD>               (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNCONSUME',
                                              'mnemo' => 'gcn_atomic_consume',
                                              'val' => '(1u << 15) | 23',
                                              'opcodeparser' => 'parseMnemoAddr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'ADDR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNCONSUME>            (HSAIL_ASM::InstAddr(inst))',
                                              'pscode' => 'Addr'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNAPPEND',
                                              'mnemo' => 'gcn_atomic_append',
                                              'val' => '(1u << 15) | 24',
                                              'opcodeparser' => 'parseMnemoAddr',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'ADDR',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNAPPEND>             (HSAIL_ASM::InstAddr(inst))',
                                              'pscode' => 'Addr'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNB4XCHG',
                                              'mnemo' => 'gcn_b4xchg',
                                              'val' => '(1u << 15) | 25',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNB4XCHG>             (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNB32XCHG',
                                              'mnemo' => 'gcn_b32xchg',
                                              'val' => '(1u << 15) | 26',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNB32XCHG>            (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMAX',
                                              'mnemo' => 'gcn_max',
                                              'val' => '(1u << 15) | 27',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMAX>                (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'psopnd' => 'Operands',
                                              'name' => 'BRIG_OPCODE_GCNMIN',
                                              'mnemo' => 'gcn_min',
                                              'val' => '(1u << 15) | 28',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'opndparser' => '&Parser::parseOperands',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.template visitOpcode<BRIG_OPCODE_GCNMIN>                (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            }
                                          ],
                             'mnemo' => sub { "DUMMY" },
                             'opcodeparser#deps' => [
                                                      'pscode'
                                                    ],
                             'opcodeparser_incfile' => 'ParserUtilities',
                             'opcodeparser' => sub { "DUMMY" },
                             'opndparser#calcState' => 'done',
                             'opcodevis_arg' => 'inst.opcode()',
                             'k' => sub { "DUMMY" },
                             'opndparser_default' => 'return NULL',
                             'tdcaption' => 'Instruction Opcodes',
                             'hasType_proto' => 'bool instHasType(Brig::BrigOpcode16_t arg)',
                             'k#calcState' => 'done',
                             'opcodevis_switch' => 'true',
                             'opndparser_incfile' => 'ParserUtilities',
                             'pscode' => sub { "DUMMY" },
                             'opcodeparser#calcState' => 'done',
                             'opcodevis_proto' => 'template <typename RetType, typename Visitor> RetType visitOpcode_gen(HSAIL_ASM::Inst inst, Visitor& vis)',
                             'ftz_incfile' => 'ItemUtils',
                             'opcodevis#deps' => [
                                                   'pscode'
                                                 ],
                             'pscode#deps' => [
                                                'k'
                                              ],
                             'hasType#deps' => [
                                                 'k'
                                               ],
                             'opcodeparser_default' => 'return NULL',
                             'hasType_default' => 'return true',
                             'name' => 'BrigOpcode',
                             'psopnd' => sub { "DUMMY" },
                             'opndparser_switch' => 'true',
                             'psopnd#deps' => [],
                             'mnemo#calcState' => 'done',
                             'has_memory_order#calcState' => 'done',
                             'opcodevis' => sub { "DUMMY" },
                             'hasType_switch' => 'true',
                             'ftz' => sub { "DUMMY" },
                             'ftz_default' => 'return false',
                             'hasType' => sub { "DUMMY" },
                             'opcodevis#calcState' => 'done',
                             'k#deps' => [],
                             'ftz#deps' => [
                                             'k'
                                           ],
                             'ftz_switch' => 'true',
                             'semsupport#calcState' => 'done',
                             'ftz_proto' => 'inline bool instSupportsFtz(Brig::BrigOpcode16_t arg)',
                             'opndparser_proto' => 'Parser::OperandParser Parser::getOperandParser(Brig::BrigOpcode16_t arg)',
                             'opcodevis_incfile' => 'ItemUtils',
                             'psopnd#calcState' => 'done',
                             'mnemo_token' => 'EInstruction',
                             'has_memory_order' => sub { "DUMMY" },
                             'semsupport' => sub { "DUMMY" },
                             'opndparser#deps' => [
                                                    'psopnd'
                                                  ],
                             'mnemo#deps' => [],
                             'pscode#calcState' => 'done',
                             'opcodeparser_switch' => 'true',
                             'mnemo_scanner' => 'Instructions',
                             'semsupport#deps' => [
                                                    'has_memory_order'
                                                  ],
                             'ftz#calcState' => 'done',
                             'opcodeparser_proto' => 'OpcodeParser getOpcodeParser(Brig::BrigOpcode16_t arg)',
                             'opndparser' => sub { "DUMMY" },
                             'opcodevis_default' => 'return RetType()',
                             'hasType#calcState' => 'done',
                             'has_memory_order#deps' => []
                           },
           'BrigSegment' => {
                              'mnemo#calcState' => 'done',
                              'mnemo#deps' => [],
                              'entries' => [
                                             {
                                               'name' => 'BRIG_SEGMENT_NONE',
                                               'mnemo' => '',
                                               'val' => '0'
                                             },
                                             {
                                               'name' => 'BRIG_SEGMENT_FLAT',
                                               'mnemo' => '',
                                               'val' => '1'
                                             },
                                             {
                                               'name' => 'BRIG_SEGMENT_GLOBAL',
                                               'mnemo' => 'global',
                                               'val' => '2'
                                             },
                                             {
                                               'name' => 'BRIG_SEGMENT_READONLY',
                                               'mnemo' => 'readonly',
                                               'val' => '3'
                                             },
                                             {
                                               'name' => 'BRIG_SEGMENT_KERNARG',
                                               'mnemo' => 'kernarg',
                                               'val' => '4'
                                             },
                                             {
                                               'name' => 'BRIG_SEGMENT_GROUP',
                                               'mnemo' => 'group',
                                               'val' => '5'
                                             },
                                             {
                                               'name' => 'BRIG_SEGMENT_PRIVATE',
                                               'mnemo' => 'private',
                                               'val' => '6'
                                             },
                                             {
                                               'name' => 'BRIG_SEGMENT_SPILL',
                                               'mnemo' => 'spill',
                                               'val' => '7'
                                             },
                                             {
                                               'name' => 'BRIG_SEGMENT_ARG',
                                               'mnemo' => 'arg',
                                               'val' => '8'
                                             },
                                             {
                                               'name' => 'BRIG_SEGMENT_EXTSPACE0',
                                               'mnemo' => 'region',
                                               'val' => '9'
                                             }
                                           ],
                              'name' => 'BrigSegment',
                              'mnemo' => sub { "DUMMY" },
                              'mnemo_token' => '_EMSegment'
                            },
           'BrigAluModifierMask' => {
                                      'entries' => [
                                                     {
                                                       'name' => 'BRIG_ALU_ROUND',
                                                       'val' => '15'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ALU_FTZ',
                                                       'val' => '16'
                                                     }
                                                   ],
                                      'name' => 'BrigAluModifierMask'
                                    },
           'BrigSamplerCoord' => {
                                   'entries' => [
                                                  {
                                                    'name' => 'BRIG_COORD_NORMALIZED',
                                                    'val' => '0'
                                                  },
                                                  {
                                                    'name' => 'BRIG_COORD_UNNORMALIZED',
                                                    'val' => '1'
                                                  }
                                                ],
                                   'name' => 'BrigSamplerCoord'
                                 },
           'BrigAlignment' => {
                                'entries' => [
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_NONE',
                                                 'val' => '0'
                                               },
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_1',
                                                 'val' => '1'
                                               },
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_2',
                                                 'val' => '2'
                                               },
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_4',
                                                 'val' => '3'
                                               },
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_8',
                                                 'val' => '4'
                                               },
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_16',
                                                 'val' => '5'
                                               },
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_32',
                                                 'val' => '6'
                                               },
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_64',
                                                 'val' => '7'
                                               },
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_128',
                                                 'val' => '8'
                                               }
                                             ],
                                'name' => 'BrigAlignment'
                              },
           'BrigPack' => {
                           'mnemo#calcState' => 'done',
                           'mnemo#deps' => [],
                           'entries' => [
                                          {
                                            'name' => 'BRIG_PACK_NONE',
                                            'mnemo' => '',
                                            'val' => '0'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_PP',
                                            'mnemo' => 'pp',
                                            'val' => '1'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_PS',
                                            'mnemo' => 'ps',
                                            'val' => '2'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_SP',
                                            'mnemo' => 'sp',
                                            'val' => '3'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_SS',
                                            'mnemo' => 'ss',
                                            'val' => '4'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_S',
                                            'mnemo' => 's',
                                            'val' => '5'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_P',
                                            'mnemo' => 'p',
                                            'val' => '6'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_PPSAT',
                                            'mnemo' => 'pp_sat',
                                            'val' => '7'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_PSSAT',
                                            'mnemo' => 'ps_sat',
                                            'val' => '8'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_SPSAT',
                                            'mnemo' => 'sp_sat',
                                            'val' => '9'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_SSSAT',
                                            'mnemo' => 'ss_sat',
                                            'val' => '10'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_SSAT',
                                            'mnemo' => 's_sat',
                                            'val' => '11'
                                          },
                                          {
                                            'name' => 'BRIG_PACK_PSAT',
                                            'mnemo' => 'p_sat',
                                            'val' => '12'
                                          }
                                        ],
                           'tdcaption' => 'Packing',
                           'name' => 'BrigPack',
                           'mnemo' => sub { "DUMMY" },
                           'mnemo_token' => '_EMPacking'
                         },
           'BrigCompareOperation' => {
                                       'mnemo#calcState' => 'done',
                                       'mnemo#deps' => [],
                                       'entries' => [
                                                      {
                                                        'name' => 'BRIG_COMPARE_EQ',
                                                        'mnemo' => 'eq',
                                                        'val' => '0'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_NE',
                                                        'mnemo' => 'ne',
                                                        'val' => '1'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_LT',
                                                        'mnemo' => 'lt',
                                                        'val' => '2'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_LE',
                                                        'mnemo' => 'le',
                                                        'val' => '3'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_GT',
                                                        'mnemo' => 'gt',
                                                        'val' => '4'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_GE',
                                                        'mnemo' => 'ge',
                                                        'val' => '5'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_EQU',
                                                        'mnemo' => 'equ',
                                                        'val' => '6'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_NEU',
                                                        'mnemo' => 'neu',
                                                        'val' => '7'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_LTU',
                                                        'mnemo' => 'ltu',
                                                        'val' => '8'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_LEU',
                                                        'mnemo' => 'leu',
                                                        'val' => '9'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_GTU',
                                                        'mnemo' => 'gtu',
                                                        'val' => '10'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_GEU',
                                                        'mnemo' => 'geu',
                                                        'val' => '11'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_NUM',
                                                        'mnemo' => 'num',
                                                        'val' => '12'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_NAN',
                                                        'mnemo' => 'nan',
                                                        'val' => '13'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SEQ',
                                                        'mnemo' => 'seq',
                                                        'val' => '14'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SNE',
                                                        'mnemo' => 'sne',
                                                        'val' => '15'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SLT',
                                                        'mnemo' => 'slt',
                                                        'val' => '16'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SLE',
                                                        'mnemo' => 'sle',
                                                        'val' => '17'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SGT',
                                                        'mnemo' => 'sgt',
                                                        'val' => '18'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SGE',
                                                        'mnemo' => 'sge',
                                                        'val' => '19'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SGEU',
                                                        'mnemo' => 'sgeu',
                                                        'val' => '20'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SEQU',
                                                        'mnemo' => 'sequ',
                                                        'val' => '21'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SNEU',
                                                        'mnemo' => 'sneu',
                                                        'val' => '22'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SLTU',
                                                        'mnemo' => 'sltu',
                                                        'val' => '23'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SLEU',
                                                        'mnemo' => 'sleu',
                                                        'val' => '24'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SNUM',
                                                        'mnemo' => 'snum',
                                                        'val' => '25'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SNAN',
                                                        'mnemo' => 'snan',
                                                        'val' => '26'
                                                      },
                                                      {
                                                        'name' => 'BRIG_COMPARE_SGTU',
                                                        'mnemo' => 'sgtu',
                                                        'val' => '27'
                                                      }
                                                    ],
                                       'tdcaption' => 'Comparison Operators',
                                       'name' => 'BrigCompareOperation',
                                       'mnemo' => sub { "DUMMY" },
                                       'mnemo_token' => '_EMCompare'
                                     },
           'BrigSymbolModifierMask' => {
                                         'entries' => [
                                                        {
                                                          'name' => 'BRIG_SYMBOL_LINKAGE',
                                                          'val' => '3'
                                                        },
                                                        {
                                                          'name' => 'BRIG_SYMBOL_DECLARATION',
                                                          'val' => '4'
                                                        },
                                                        {
                                                          'name' => 'BRIG_SYMBOL_CONST',
                                                          'val' => '8'
                                                        },
                                                        {
                                                          'name' => 'BRIG_SYMBOL_ARRAY',
                                                          'val' => '16'
                                                        },
                                                        {
                                                          'name' => 'BRIG_SYMBOL_FLEX_ARRAY',
                                                          'val' => '32'
                                                        }
                                                      ],
                                         'name' => 'BrigSymbolModifierMask',
                                         'nodump' => 'true'
                                       },
           'BrigOperandKinds' => {
                                   'entries' => [
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandImmed)',
                                                    'wname' => 'OperandImmed',
                                                    'name' => 'BRIG_OPERAND_IMMED',
                                                    'val' => '0'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandWavesize)',
                                                    'wname' => 'OperandWavesize',
                                                    'name' => 'BRIG_OPERAND_WAVESIZE',
                                                    'val' => '1'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandReg)',
                                                    'wname' => 'OperandReg',
                                                    'name' => 'BRIG_OPERAND_REG',
                                                    'val' => '2'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandRegVector)',
                                                    'wname' => 'OperandRegVector',
                                                    'name' => 'BRIG_OPERAND_REG_VECTOR',
                                                    'val' => '3'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandAddress)',
                                                    'wname' => 'OperandAddress',
                                                    'name' => 'BRIG_OPERAND_ADDRESS',
                                                    'val' => '4'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandArgumentList)',
                                                    'wname' => 'OperandArgumentList',
                                                    'name' => 'BRIG_OPERAND_ARGUMENT_LIST',
                                                    'val' => '5'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandFunctionList)',
                                                    'wname' => 'OperandFunctionList',
                                                    'name' => 'BRIG_OPERAND_FUNCTION_LIST',
                                                    'val' => '6'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandFbarrierRef)',
                                                    'wname' => 'OperandFbarrierRef',
                                                    'name' => 'BRIG_OPERAND_FBARRIER_REF',
                                                    'val' => '7'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandFunctionRef)',
                                                    'wname' => 'OperandFunctionRef',
                                                    'name' => 'BRIG_OPERAND_FUNCTION_REF',
                                                    'val' => '8'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandLabelRef)',
                                                    'wname' => 'OperandLabelRef',
                                                    'name' => 'BRIG_OPERAND_LABEL_REF',
                                                    'val' => '9'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandLabelTargetsRef)',
                                                    'wname' => 'OperandLabelTargetsRef',
                                                    'name' => 'BRIG_OPERAND_LABEL_TARGETS_REF',
                                                    'val' => '10'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandSignatureRef)',
                                                    'wname' => 'OperandSignatureRef',
                                                    'name' => 'BRIG_OPERAND_SIGNATURE_REF',
                                                    'val' => '11'
                                                  },
                                                  {
                                                    'sizeof' => 'sizeof(BrigOperandLabelVariableRef)',
                                                    'wname' => 'OperandLabelVariableRef',
                                                    'name' => 'BRIG_OPERAND_LABEL_VARIABLE_REF',
                                                    'val' => '12'
                                                  }
                                                ],
                                   'sizeof#deps' => [
                                                      'wname'
                                                    ],
                                   'name' => 'BrigOperandKinds',
                                   'wname#deps' => [],
                                   'sizeof_proto' => 'int size_of_operand(unsigned arg)',
                                   'sizeof' => sub { "DUMMY" },
                                   'wname' => sub { "DUMMY" },
                                   'sizeof#calcState' => 'done',
                                   'sizeof_switch' => 'true',
                                   'wname#calcState' => 'done',
                                   'sizeof_default' => 'return -1'
                                 },
           'BrigImageGeometry' => {
                                    'mnemo#calcState' => 'done',
                                    'mnemo#deps' => [],
                                    'entries' => [
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_1D',
                                                     'mnemo' => '1d',
                                                     'val' => '0'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_2D',
                                                     'mnemo' => '2d',
                                                     'val' => '1'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_3D',
                                                     'mnemo' => '3d',
                                                     'val' => '2'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_1DA',
                                                     'mnemo' => '1da',
                                                     'val' => '3'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_1DB',
                                                     'mnemo' => '1db',
                                                     'val' => '4'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_2DA',
                                                     'mnemo' => '2da',
                                                     'val' => '5'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_UNKNOWN',
                                                     'mnemo' => ''
                                                   }
                                                 ],
                                    'tdcaption' => 'Geometry',
                                    'name' => 'BrigImageGeometry',
                                    'mnemo' => sub { "DUMMY" },
                                    'mnemo_token' => '_EMGeom'
                                  },
           'BrigLinkage' => {
                              'mnemo#calcState' => 'done',
                              'mnemo#deps' => [],
                              'entries' => [
                                             {
                                               'name' => 'BRIG_LINKAGE_NONE',
                                               'mnemo' => '',
                                               'val' => '0'
                                             },
                                             {
                                               'name' => 'BRIG_LINKAGE_STATIC',
                                               'mnemo' => 'static',
                                               'val' => '1'
                                             },
                                             {
                                               'name' => 'BRIG_LINKAGE_EXTERN',
                                               'mnemo' => 'extern',
                                               'val' => '2'
                                             }
                                           ],
                              'name' => 'BrigLinkage',
                              'mnemo' => sub { "DUMMY" }
                            },
           'BrigSamplerFilter' => {
                                    'mnemo#calcState' => 'done',
                                    'mnemo#deps' => [],
                                    'entries' => [
                                                   {
                                                     'name' => 'BRIG_FILTER_NEAREST',
                                                     'mnemo' => 'nearest',
                                                     'val' => '0'
                                                   },
                                                   {
                                                     'name' => 'BRIG_FILTER_LINEAR',
                                                     'mnemo' => 'linear',
                                                     'val' => '1'
                                                   }
                                                 ],
                                    'name' => 'BrigSamplerFilter',
                                    'mnemo' => sub { "DUMMY" }
                                  },
           'BrigMemoryFenceSegments' => {
                                          'entries' => [
                                                         {
                                                           'name' => 'BRIG_MEMORY_FENCE_NONE',
                                                           'val' => '0'
                                                         },
                                                         {
                                                           'name' => 'BRIG_MEMORY_FENCE_GROUP',
                                                           'val' => '1'
                                                         },
                                                         {
                                                           'name' => 'BRIG_MEMORY_FENCE_GLOBAL',
                                                           'val' => '2'
                                                         },
                                                         {
                                                           'name' => 'BRIG_MEMORY_FENCE_BOTH',
                                                           'val' => '3'
                                                         }
                                                       ],
                                          'name' => 'BrigMemoryFenceSegments'
                                        },
           'BrigMemoryOrder' => {
                                  'mnemo#calcState' => 'done',
                                  'mnemo#deps' => [],
                                  'entries' => [
                                                 {
                                                   'name' => 'BRIG_MEMORY_ORDER_NONE',
                                                   'mnemo' => '',
                                                   'val' => '0'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_ORDER_RELAXED',
                                                   'mnemo' => 'rlx',
                                                   'val' => '1'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_ORDER_ACQUIRE',
                                                   'mnemo' => 'acq',
                                                   'val' => '2'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_ORDER_RELEASE',
                                                   'mnemo' => 'rel',
                                                   'val' => '3'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_ORDER_ACQUIRE_RELEASE',
                                                   'mnemo' => 'ar',
                                                   'val' => '4         '
                                                 }
                                               ],
                                  'name' => 'BrigMemoryOrder',
                                  'mnemo' => sub { "DUMMY" },
                                  'mnemo_token' => '_EMMemoryOrder'
                                },
           'BrigMachineModel' => {
                                   'mnemo#calcState' => 'done',
                                   'mnemo#deps' => [],
                                   'entries' => [
                                                  {
                                                    'name' => 'BRIG_MACHINE_SMALL',
                                                    'mnemo' => '$small',
                                                    'val' => '0'
                                                  },
                                                  {
                                                    'name' => 'BRIG_MACHINE_LARGE',
                                                    'mnemo' => '$large',
                                                    'val' => '1'
                                                  },
                                                  {
                                                    'skip' => 'true',
                                                    'name' => 'BRIG_MACHINE_UNDEF',
                                                    'mnemo' => '$undef',
                                                    'val' => '2  '
                                                  }
                                                ],
                                   'name' => 'BrigMachineModel',
                                   'mnemo' => sub { "DUMMY" },
                                   'mnemo_token' => 'ETargetMachine'
                                 },
           'BrigDirectiveKinds' => {
                                     'isToplevelOnly#calcState' => 'done',
                                     'isBodyOnly#calcState' => 'done',
                                     'isBodyOnly_proto' => 'bool isBodyOnly(Directive d)',
                                     'entries' => [
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveArgScopeEnd)',
                                                      'wname' => 'DirectiveArgScopeEnd',
                                                      'isBodyOnly' => 'true',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_ARG_SCOPE_END',
                                                      'val' => '0'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveArgScopeStart)',
                                                      'wname' => 'DirectiveArgScopeStart',
                                                      'isBodyOnly' => 'true',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_ARG_SCOPE_START',
                                                      'val' => '1'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigBlockEnd)',
                                                      'wname' => 'BlockEnd',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_BLOCK_END',
                                                      'val' => '2'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigBlockNumeric)',
                                                      'wname' => 'BlockNumeric',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_BLOCK_NUMERIC',
                                                      'val' => '3'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigBlockStart)',
                                                      'wname' => 'BlockStart',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_BLOCK_START',
                                                      'val' => '4'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigBlockString)',
                                                      'wname' => 'BlockString',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_BLOCK_STRING',
                                                      'val' => '5'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveComment)',
                                                      'wname' => 'DirectiveComment',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_COMMENT',
                                                      'val' => '6'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveControl)',
                                                      'wname' => 'DirectiveControl',
                                                      'isBodyOnly' => 'true',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_CONTROL',
                                                      'val' => '7'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveExtension)',
                                                      'wname' => 'DirectiveExtension',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'true',
                                                      'name' => 'BRIG_DIRECTIVE_EXTENSION',
                                                      'val' => '8'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveFbarrier)',
                                                      'wname' => 'DirectiveFbarrier',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_FBARRIER',
                                                      'val' => '9'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveFunction)',
                                                      'wname' => 'DirectiveFunction',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'true',
                                                      'name' => 'BRIG_DIRECTIVE_FUNCTION',
                                                      'val' => '10'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveImageInit)',
                                                      'wname' => 'DirectiveImageInit',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'true',
                                                      'name' => 'BRIG_DIRECTIVE_IMAGE_INIT',
                                                      'val' => '11'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveKernel)',
                                                      'wname' => 'DirectiveKernel',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'true',
                                                      'name' => 'BRIG_DIRECTIVE_KERNEL',
                                                      'val' => '12'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveLabel)',
                                                      'wname' => 'DirectiveLabel',
                                                      'isBodyOnly' => 'true',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_LABEL',
                                                      'val' => '13'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveLabelInit)',
                                                      'wname' => 'DirectiveLabelInit',
                                                      'isBodyOnly' => 'true',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_LABEL_INIT',
                                                      'val' => '14'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveLabelTargets)',
                                                      'wname' => 'DirectiveLabelTargets',
                                                      'isBodyOnly' => 'true',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_LABEL_TARGETS',
                                                      'val' => '15'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveLoc)',
                                                      'wname' => 'DirectiveLoc',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_LOC',
                                                      'val' => '16'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectivePragma)',
                                                      'wname' => 'DirectivePragma',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_PRAGMA',
                                                      'val' => '17'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveSamplerInit)',
                                                      'wname' => 'DirectiveSamplerInit',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'true',
                                                      'name' => 'BRIG_DIRECTIVE_SAMPLER_INIT',
                                                      'val' => '18'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveSignature)',
                                                      'wname' => 'DirectiveSignature',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'true',
                                                      'name' => 'BRIG_DIRECTIVE_SIGNATURE',
                                                      'val' => '19'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveVariable)',
                                                      'wname' => 'DirectiveVariable',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_VARIABLE',
                                                      'val' => '20'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveVariableInit)',
                                                      'wname' => 'DirectiveVariableInit',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'false',
                                                      'name' => 'BRIG_DIRECTIVE_VARIABLE_INIT',
                                                      'val' => '21'
                                                    },
                                                    {
                                                      'sizeof' => 'sizeof(BrigDirectiveVersion)',
                                                      'wname' => 'DirectiveVersion',
                                                      'isBodyOnly' => 'false',
                                                      'isToplevelOnly' => 'true',
                                                      'name' => 'BRIG_DIRECTIVE_VERSION',
                                                      'val' => '22          '
                                                    }
                                                  ],
                                     'sizeof#deps' => [
                                                        'wname'
                                                      ],
                                     'isToplevelOnly#deps' => [],
                                     'isBodyOnly_arg' => 'd.brig()->kind',
                                     'sizeof' => sub { "DUMMY" },
                                     'wname' => sub { "DUMMY" },
                                     'sizeof#calcState' => 'done',
                                     'sizeof_switch' => 'true',
                                     'isToplevelOnly_switch' => 'true',
                                     'isToplevelOnly_arg' => 'd.brig()->kind',
                                     'name' => 'BrigDirectiveKinds',
                                     'isToplevelOnly' => sub { "DUMMY" },
                                     'wname#deps' => [],
                                     'isBodyOnly_default' => 'assert(false); return false',
                                     'sizeof_proto' => 'int size_of_directive(unsigned arg)',
                                     'isToplevelOnly_default' => 'assert(false); return false',
                                     'isToplevelOnly_proto' => 'bool isToplevelOnly(Directive d)',
                                     'isBodyOnly#deps' => [],
                                     'isBodyOnly' => sub { "DUMMY" },
                                     'wname#calcState' => 'done',
                                     'sizeof_default' => 'return -1',
                                     'isBodyOnly_switch' => 'true'
                                   },
           'BrigImageOrder' => {
                                 'mnemo#calcState' => 'done',
                                 'mnemo#deps' => [],
                                 'entries' => [
                                                {
                                                  'name' => 'BRIG_ORDER_R',
                                                  'mnemo' => 'r',
                                                  'val' => '0'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_A',
                                                  'mnemo' => 'a',
                                                  'val' => '1'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_RX',
                                                  'mnemo' => 'rx',
                                                  'val' => '2'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_RG',
                                                  'mnemo' => 'rg',
                                                  'val' => '3'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_RGX',
                                                  'mnemo' => 'rgx',
                                                  'val' => '4'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_RA',
                                                  'mnemo' => 'ra',
                                                  'val' => '5'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_RGB',
                                                  'mnemo' => 'rgb',
                                                  'val' => '6'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_RGBA',
                                                  'mnemo' => 'rgba',
                                                  'val' => '7'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_RGBX',
                                                  'mnemo' => 'rgbx',
                                                  'val' => '8'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_BGRA',
                                                  'mnemo' => 'bgra',
                                                  'val' => '9'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_ARGB',
                                                  'mnemo' => 'argb',
                                                  'val' => '10'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_INTENSITY',
                                                  'mnemo' => 'intensity',
                                                  'val' => '11'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_LUMINANCE',
                                                  'mnemo' => 'luminance',
                                                  'val' => '12'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_SRGB',
                                                  'mnemo' => 'srgb',
                                                  'val' => '13'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_SRGBX',
                                                  'mnemo' => 'srgbx',
                                                  'val' => '14'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_SRGBA',
                                                  'mnemo' => 'srgba',
                                                  'val' => '15'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_SBGRA',
                                                  'mnemo' => 'sbgra',
                                                  'val' => '16'
                                                },
                                                {
                                                  'name' => 'BRIG_ORDER_UNKNOWN',
                                                  'mnemo' => ''
                                                }
                                              ],
                                 'name' => 'BrigImageOrder',
                                 'mnemo_scanner' => 'ImageOrder',
                                 'mnemo' => sub { "DUMMY" }
                               },
           'BrigMemoryModifierMask' => {
                                         'entries' => [
                                                        {
                                                          'name' => 'BRIG_MEMORY_CONST',
                                                          'val' => '1'
                                                        }
                                                      ],
                                         'name' => 'BrigMemoryModifierMask'
                                       },
           'BrigProfile' => {
                              'mnemo#calcState' => 'done',
                              'mnemo#deps' => [],
                              'entries' => [
                                             {
                                               'name' => 'BRIG_PROFILE_BASE',
                                               'mnemo' => '$base',
                                               'val' => '0'
                                             },
                                             {
                                               'name' => 'BRIG_PROFILE_FULL',
                                               'mnemo' => '$full',
                                               'val' => '1'
                                             }
                                           ],
                              'name' => 'BrigProfile',
                              'mnemo' => sub { "DUMMY" },
                              'mnemo_token' => 'ETargetProfile'
                            },
           'BrigSignalOperation' => {
                                      'mnemo#calcState' => 'done',
                                      'mnemo#deps' => [],
                                      'entries' => [
                                                     {
                                                       'name' => 'BRIG_SIGNAL_ADD',
                                                       'mnemo' => 'add',
                                                       'val' => '0'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_AND',
                                                       'mnemo' => 'and',
                                                       'val' => '1'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_CAS',
                                                       'mnemo' => 'cas',
                                                       'val' => '2'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_DEC',
                                                       'mnemo' => 'dec',
                                                       'val' => '3'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_EXCH',
                                                       'mnemo' => 'exch',
                                                       'val' => '4'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_INC',
                                                       'mnemo' => 'inc',
                                                       'val' => '5'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_LD',
                                                       'mnemo' => 'ld',
                                                       'val' => '6'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_MAX',
                                                       'mnemo' => 'max',
                                                       'val' => '7'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_MIN',
                                                       'mnemo' => 'min',
                                                       'val' => '8'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_OR',
                                                       'mnemo' => 'or',
                                                       'val' => '9'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_ST',
                                                       'mnemo' => 'st',
                                                       'val' => '10'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_SUB',
                                                       'mnemo' => 'sub',
                                                       'val' => '11'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_XOR',
                                                       'mnemo' => 'xor',
                                                       'val' => '12'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_WAIT_EQ',
                                                       'mnemo' => 'wait_eq',
                                                       'val' => '13'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_WAIT_NE',
                                                       'mnemo' => 'wait_ne',
                                                       'val' => '14'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_WAIT_LT',
                                                       'mnemo' => 'wait_lt',
                                                       'val' => '15'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_WAIT_GTE',
                                                       'mnemo' => 'wait_gte',
                                                       'val' => '16'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_WAITTIMEOUT_EQ',
                                                       'mnemo' => 'waittimeout_eq',
                                                       'val' => '17'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_WAITTIMEOUT_NE',
                                                       'mnemo' => 'waittimeout_ne',
                                                       'val' => '18'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_WAITTIMEOUT_LT',
                                                       'mnemo' => 'waittimeout_lt',
                                                       'val' => '19'
                                                     },
                                                     {
                                                       'name' => 'BRIG_SIGNAL_WAITTIMEOUT_GTE',
                                                       'mnemo' => 'waittimeout_gte',
                                                       'val' => '20'
                                                     }
                                                   ],
                                      'mnemo_context' => 'Brig::BRIG_INST_SIGNAL',
                                      'name' => 'BrigSignalOperation',
                                      'mnemo' => sub { "DUMMY" },
                                      'mnemo_token' => '_EMSignalOp'
                                    },
           'BrigSamplerBoundaryMode' => {
                                          'mnemo#calcState' => 'done',
                                          'mnemo#deps' => [],
                                          'entries' => [
                                                         {
                                                           'name' => 'BRIG_BOUNDARY_UNDEFINED',
                                                           'mnemo' => 'undefined',
                                                           'val' => '0'
                                                         },
                                                         {
                                                           'name' => 'BRIG_BOUNDARY_CLAMP',
                                                           'mnemo' => 'clamp',
                                                           'val' => '1'
                                                         },
                                                         {
                                                           'name' => 'BRIG_BOUNDARY_BORDER',
                                                           'mnemo' => 'border',
                                                           'val' => '2'
                                                         },
                                                         {
                                                           'name' => 'BRIG_BOUNDARY_WRAP',
                                                           'mnemo' => 'wrap',
                                                           'val' => '3'
                                                         },
                                                         {
                                                           'name' => 'BRIG_BOUNDARY_MIRROR',
                                                           'mnemo' => 'mirror',
                                                           'val' => '4'
                                                         },
                                                         {
                                                           'name' => 'BRIG_BOUNDARY_MIRRORONCE',
                                                           'mnemo' => 'mirroronce',
                                                           'val' => '5'
                                                         }
                                                       ],
                                          'name' => 'BrigSamplerBoundaryMode',
                                          'mnemo' => sub { "DUMMY" },
                                          'mnemo_token' => 'ESamplerBoundaryMode'
                                        },
           'BrigExecuteableModifierMask' => {
                                              'entries' => [
                                                             {
                                                               'name' => 'BRIG_EXECUTABLE_LINKAGE',
                                                               'val' => '3'
                                                             },
                                                             {
                                                               'name' => 'BRIG_EXECUTABLE_DECLARATION',
                                                               'val' => '4'
                                                             }
                                                           ],
                                              'name' => 'BrigExecuteableModifierMask',
                                              'nodump' => 'true'
                                            },
           'BrigAtomicOperation' => {
                                      'mnemo#deps' => [],
                                      'entries' => [
                                                     {
                                                       'name' => 'BRIG_ATOMIC_ADD',
                                                       'mnemo' => 'add',
                                                       'val' => '0'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_AND',
                                                       'mnemo' => 'and',
                                                       'val' => '1'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_CAS',
                                                       'mnemo' => 'cas',
                                                       'val' => '2'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_DEC',
                                                       'mnemo' => 'dec',
                                                       'val' => '3'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_EXCH',
                                                       'mnemo' => 'exch',
                                                       'val' => '4'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_INC',
                                                       'mnemo' => 'inc',
                                                       'val' => '5'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_LD',
                                                       'mnemo' => 'ld',
                                                       'val' => '6'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_MAX',
                                                       'mnemo' => 'max',
                                                       'val' => '7'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_MIN',
                                                       'mnemo' => 'min',
                                                       'val' => '8'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_OR',
                                                       'mnemo' => 'or',
                                                       'val' => '9'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_ST',
                                                       'mnemo' => 'st',
                                                       'val' => '10'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_SUB',
                                                       'mnemo' => 'sub',
                                                       'val' => '11'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_XOR',
                                                       'mnemo' => 'xor',
                                                       'val' => '12'
                                                     }
                                                   ],
                                      'name' => 'BrigAtomicOperation',
                                      'mnemo' => sub { "DUMMY" },
                                      'mnemo#calcState' => 'done',
                                      'tdcaption' => 'Atomic Operations',
                                      'mnemo_context' => 'Brig::BRIG_INST_ATOMIC',
                                      'mnemo_token' => '_EMAtomicOp'
                                    },
           'BrigSegCvtModifierMask' => {
                                         'entries' => [
                                                        {
                                                          'name' => 'BRIG_SEGCVT_NONULL',
                                                          'mnemo' => 'nonull',
                                                          'val' => '1                          '
                                                        }
                                                      ],
                                         'name' => 'BrigSegCvtModifierMask'
                                       },
           'BrigMemoryScope' => {
                                  'mnemo#calcState' => 'done',
                                  'mnemo#deps' => [],
                                  'entries' => [
                                                 {
                                                   'name' => 'BRIG_MEMORY_SCOPE_NONE',
                                                   'mnemo' => '',
                                                   'val' => '0'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_SCOPE_WAVEFRONT',
                                                   'mnemo' => 'wv',
                                                   'val' => '1'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_SCOPE_WORKGROUP',
                                                   'mnemo' => 'wg',
                                                   'val' => '2'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_SCOPE_COMPONENT',
                                                   'mnemo' => 'cmp',
                                                   'val' => '3'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_SCOPE_SYSTEM',
                                                   'mnemo' => 'sys',
                                                   'val' => '4                      '
                                                 }
                                               ],
                                  'name' => 'BrigMemoryScope',
                                  'mnemo' => sub { "DUMMY" },
                                  'mnemo_token' => '_EMMemoryScope'
                                },
           'BrigPackedTypeBits' => {
                                     'entries' => [
                                                    {
                                                      'name' => 'BRIG_TYPE_PACK_SHIFT',
                                                      'val' => '5'
                                                    },
                                                    {
                                                      'name' => 'BRIG_TYPE_BASE_MASK',
                                                      'val' => '(1 << BRIG_TYPE_PACK_SHIFT) - 1'
                                                    },
                                                    {
                                                      'name' => 'BRIG_TYPE_PACK_MASK',
                                                      'val' => '3 << BRIG_TYPE_PACK_SHIFT'
                                                    },
                                                    {
                                                      'name' => 'BRIG_TYPE_PACK_NONE',
                                                      'val' => '0 << BRIG_TYPE_PACK_SHIFT'
                                                    },
                                                    {
                                                      'name' => 'BRIG_TYPE_PACK_32',
                                                      'val' => '1 << BRIG_TYPE_PACK_SHIFT'
                                                    },
                                                    {
                                                      'name' => 'BRIG_TYPE_PACK_64',
                                                      'val' => '2 << BRIG_TYPE_PACK_SHIFT'
                                                    },
                                                    {
                                                      'name' => 'BRIG_TYPE_PACK_128',
                                                      'val' => '3 << BRIG_TYPE_PACK_SHIFT'
                                                    }
                                                  ],
                                     'name' => 'BrigPackedTypeBits',
                                     'nodump' => 'true'
                                   },
           'BrigInstKinds' => {
                                'entries' => [
                                               {
                                                 'sizeof' => 'sizeof(BrigInstNone)',
                                                 'wname' => 'InstNone',
                                                 'skip' => 'true',
                                                 'name' => 'BRIG_INST_NONE',
                                                 'val' => '0'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstBasic)',
                                                 'wname' => 'InstBasic',
                                                 'name' => 'BRIG_INST_BASIC',
                                                 'val' => '1'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstAtomic)',
                                                 'wname' => 'InstAtomic',
                                                 'name' => 'BRIG_INST_ATOMIC',
                                                 'val' => '2'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstAtomicImage)',
                                                 'wname' => 'InstAtomicImage',
                                                 'name' => 'BRIG_INST_ATOMIC_IMAGE',
                                                 'val' => '3'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstBr)',
                                                 'wname' => 'InstBr',
                                                 'name' => 'BRIG_INST_BR',
                                                 'val' => '4'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstCmp)',
                                                 'wname' => 'InstCmp',
                                                 'name' => 'BRIG_INST_CMP',
                                                 'val' => '5'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstCvt)',
                                                 'wname' => 'InstCvt',
                                                 'name' => 'BRIG_INST_CVT',
                                                 'val' => '6'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstImage)',
                                                 'wname' => 'InstImage',
                                                 'name' => 'BRIG_INST_IMAGE',
                                                 'val' => '7'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstLane)',
                                                 'wname' => 'InstLane',
                                                 'name' => 'BRIG_INST_LANE',
                                                 'val' => '8'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstMem)',
                                                 'wname' => 'InstMem',
                                                 'name' => 'BRIG_INST_MEM',
                                                 'val' => '9'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstMemFence)',
                                                 'wname' => 'InstMemFence',
                                                 'name' => 'BRIG_INST_MEM_FENCE',
                                                 'val' => '10'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstAddr)',
                                                 'wname' => 'InstAddr',
                                                 'name' => 'BRIG_INST_ADDR',
                                                 'val' => '11'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstMod)',
                                                 'wname' => 'InstMod',
                                                 'name' => 'BRIG_INST_MOD',
                                                 'val' => '12'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstQueue)',
                                                 'wname' => 'InstQueue',
                                                 'name' => 'BRIG_INST_QUEUE',
                                                 'val' => '13'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstSeg)',
                                                 'wname' => 'InstSeg',
                                                 'name' => 'BRIG_INST_SEG',
                                                 'val' => '14'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstSegCvt)',
                                                 'wname' => 'InstSegCvt',
                                                 'name' => 'BRIG_INST_SEG_CVT',
                                                 'val' => '15'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstSignal)',
                                                 'wname' => 'InstSignal',
                                                 'name' => 'BRIG_INST_SIGNAL',
                                                 'val' => '16'
                                               },
                                               {
                                                 'sizeof' => 'sizeof(BrigInstSourceType)',
                                                 'wname' => 'InstSourceType',
                                                 'name' => 'BRIG_INST_SOURCE_TYPE',
                                                 'val' => '17'
                                               }
                                             ],
                                'sizeof#deps' => [
                                                   'wname'
                                                 ],
                                'name' => 'BrigInstKinds',
                                'wname#deps' => [],
                                'sizeof_proto' => 'int size_of_inst(unsigned arg)',
                                'sizeof' => sub { "DUMMY" },
                                'wname' => sub { "DUMMY" },
                                'sizeof#calcState' => 'done',
                                'sizeof_switch' => 'true',
                                'wname#calcState' => 'done',
                                'sizeof_default' => 'return -1'
                              },
           'BrigWidth' => {
                            'entries' => [
                                           {
                                             'name' => 'BRIG_WIDTH_NONE',
                                             'val' => '0'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_1',
                                             'val' => '1'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_2',
                                             'val' => '2'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_4',
                                             'val' => '3'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_8',
                                             'val' => '4'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_16',
                                             'val' => '5'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_32',
                                             'val' => '6'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_64',
                                             'val' => '7'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_128',
                                             'val' => '8'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_256',
                                             'val' => '9'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_512',
                                             'val' => '10'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_1024',
                                             'val' => '11'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_2048',
                                             'val' => '12'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_4096',
                                             'val' => '13'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_8192',
                                             'val' => '14'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_16384',
                                             'val' => '15'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_32768',
                                             'val' => '16'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_65536',
                                             'val' => '17'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_131072',
                                             'val' => '18'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_262144',
                                             'val' => '19'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_524288',
                                             'val' => '20'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_1048576',
                                             'val' => '21'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_2097152',
                                             'val' => '22'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_4194304',
                                             'val' => '23'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_8388608',
                                             'val' => '24'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_16777216',
                                             'val' => '25'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_33554432',
                                             'val' => '26'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_67108864',
                                             'val' => '27'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_134217728',
                                             'val' => '28'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_268435456',
                                             'val' => '29'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_536870912',
                                             'val' => '30'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_1073741824',
                                             'val' => '31'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_2147483648',
                                             'val' => '32'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_WAVESIZE',
                                             'val' => '33'
                                           },
                                           {
                                             'name' => 'BRIG_WIDTH_ALL',
                                             'val' => '34'
                                           }
                                         ],
                            'name' => 'BrigWidth'
                          }
         };
