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
                                               'val' => '20140528'
                                             },
                                             {
                                               'name' => 'BRIG_VERSION_BRIG_MAJOR',
                                               'val' => '0'
                                             },
                                             {
                                               'name' => 'BRIG_VERSION_BRIG_MINOR',
                                               'val' => '20140528'
                                             }
                                           ],
                              'nowrap' => 'true',
                              'name' => 'BrigVersion',
                              'nodump' => 'true'
                            },
           'BrigImageQuery' => {
                                 'mnemo#calcState' => 'done',
                                 'mnemo#deps' => [],
                                 'entries' => [
                                                {
                                                  'name' => 'BRIG_IMAGE_QUERY_WIDTH',
                                                  'mnemo' => 'width',
                                                  'val' => '0'
                                                },
                                                {
                                                  'name' => 'BRIG_IMAGE_QUERY_HEIGHT',
                                                  'mnemo' => 'height',
                                                  'val' => '1'
                                                },
                                                {
                                                  'name' => 'BRIG_IMAGE_QUERY_DEPTH',
                                                  'mnemo' => 'depth',
                                                  'val' => '2'
                                                },
                                                {
                                                  'name' => 'BRIG_IMAGE_QUERY_ARRAY',
                                                  'mnemo' => 'array',
                                                  'val' => '3'
                                                },
                                                {
                                                  'name' => 'BRIG_IMAGE_QUERY_CHANNELORDER',
                                                  'mnemo' => 'channelorder',
                                                  'val' => '4'
                                                },
                                                {
                                                  'name' => 'BRIG_IMAGE_QUERY_CHANNELTYPE',
                                                  'mnemo' => 'channeltype',
                                                  'val' => '5'
                                                }
                                              ],
                                 'name' => 'BrigImageQuery',
                                 'mnemo' => sub { "DUMMY" }
                               },
           'BrigMemoryScope2' => {
                                   'mnemo#deps' => [],
                                   'entries' => [
                                                  {
                                                    'name' => 'BRIG_MEMORY_SCOPE2_NONE',
                                                    'mnemo' => '',
                                                    'val' => '0'
                                                  },
                                                  {
                                                    'name' => 'BRIG_MEMORY_SCOPE2_WORKITEM',
                                                    'mnemo' => 'wi',
                                                    'val' => '1'
                                                  },
                                                  {
                                                    'name' => 'BRIG_MEMORY_SCOPE2_WAVEFRONT',
                                                    'mnemo' => 'wv',
                                                    'val' => '2'
                                                  },
                                                  {
                                                    'name' => 'BRIG_MEMORY_SCOPE2_WORKGROUP',
                                                    'mnemo' => 'wg',
                                                    'val' => '3'
                                                  },
                                                  {
                                                    'name' => 'BRIG_MEMORY_SCOPE2_COMPONENT',
                                                    'mnemo' => 'cmp',
                                                    'val' => '4'
                                                  },
                                                  {
                                                    'name' => 'BRIG_MEMORY_SCOPE2_SYSTEM',
                                                    'mnemo' => 'sys',
                                                    'val' => '5 '
                                                  }
                                                ],
                                   'name' => 'BrigMemoryScope2',
                                   'mnemo_scanner' => 'Instructions',
                                   'mnemo' => sub { "DUMMY" },
                                   'mnemo#calcState' => 'done',
                                   'mnemo_context' => 'EMemoryScopeContext',
                                   'mnemo_token' => 'EMemoryScope'
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
           'BrigVariableModifierMask' => {
                                           'entries' => [
                                                          {
                                                            'name' => 'BRIG_SYMBOL_DEFINITION',
                                                            'val' => '1'
                                                          },
                                                          {
                                                            'name' => 'BRIG_SYMBOL_CONST',
                                                            'val' => '2'
                                                          },
                                                          {
                                                            'name' => 'BRIG_SYMBOL_ARRAY',
                                                            'val' => '4'
                                                          },
                                                          {
                                                            'name' => 'BRIG_SYMBOL_FLEX_ARRAY',
                                                            'val' => '8'
                                                          }
                                                        ],
                                           'name' => 'BrigVariableModifierMask',
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
                                             'val' => '12'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN',
                                             'mnemo' => 'sneari',
                                             'val' => '13'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_SIGNALLING_ZERO',
                                             'mnemo' => 'szeroi',
                                             'val' => '14'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY',
                                             'mnemo' => 'supi',
                                             'val' => '15'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY',
                                             'mnemo' => 'sdowni',
                                             'val' => '16'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN_SAT',
                                             'mnemo' => 'sneari_sat',
                                             'val' => '17'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_SIGNALLING_ZERO_SAT',
                                             'mnemo' => 'szeroi_sat',
                                             'val' => '18'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY_SAT',
                                             'mnemo' => 'supi_sat',
                                             'val' => '19'
                                           },
                                           {
                                             'name' => 'BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY_SAT',
                                             'mnemo' => 'sdowni_sat',
                                             'val' => '20 '
                                           }
                                         ],
                            'name' => 'BrigRound',
                            'mnemo' => 'true',
                            'mnemo_token' => '_EMRound'
                          },
           'BrigSamplerQuery' => {
                                   'mnemo#calcState' => 'done',
                                   'mnemo#deps' => [],
                                   'entries' => [
                                                  {
                                                    'name' => 'BRIG_SAMPLER_QUERY_ADDRESSING',
                                                    'mnemo' => 'addressing',
                                                    'val' => '0'
                                                  },
                                                  {
                                                    'name' => 'BRIG_SAMPLER_QUERY_COORD',
                                                    'mnemo' => 'coord',
                                                    'val' => '1'
                                                  },
                                                  {
                                                    'name' => 'BRIG_SAMPLER_QUERY_FILTER',
                                                    'mnemo' => 'filter',
                                                    'val' => '2'
                                                  }
                                                ],
                                   'name' => 'BrigSamplerQuery',
                                   'mnemo' => sub { "DUMMY" },
                                   'mnemo_token' => '_EMSamplerQuery'
                                 },
           'BrigTypeX' => {
                            'dispatch_proto' => 'template<typename RetType, typename Visitor>
RetType dispatchByType_gen(unsigned type, Visitor& v)',
                            'entries' => [
                                           {
                                             'dispatch' => 'v.visitNone(type)',
                                             'name' => 'BRIG_TYPE_NONE',
                                             'mnemo' => '',
                                             'val' => '0'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U8> >()',
                                             'numBytes' => '1',
                                             'name' => 'BRIG_TYPE_U8',
                                             'mnemo' => 'u8',
                                             'val' => '1',
                                             'numBits' => '8'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U16> >()',
                                             'numBytes' => '2',
                                             'name' => 'BRIG_TYPE_U16',
                                             'mnemo' => 'u16',
                                             'val' => '2',
                                             'numBits' => '16'
                                           },
                                           {
                                             'ctype' => 'uint32_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U32> >()',
                                             'numBytes' => '4',
                                             'name' => 'BRIG_TYPE_U32',
                                             'mnemo' => 'u32',
                                             'val' => '3',
                                             'numBits' => '32'
                                           },
                                           {
                                             'ctype' => 'uint64_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U64> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_U64',
                                             'mnemo' => 'u64',
                                             'val' => '4',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'int8_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S8> >()',
                                             'numBytes' => '1',
                                             'name' => 'BRIG_TYPE_S8',
                                             'mnemo' => 's8',
                                             'val' => '5',
                                             'numBits' => '8'
                                           },
                                           {
                                             'ctype' => 'int16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S16> >()',
                                             'numBytes' => '2',
                                             'name' => 'BRIG_TYPE_S16',
                                             'mnemo' => 's16',
                                             'val' => '6',
                                             'numBits' => '16'
                                           },
                                           {
                                             'ctype' => 'int32_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S32> >()',
                                             'numBytes' => '4',
                                             'name' => 'BRIG_TYPE_S32',
                                             'mnemo' => 's32',
                                             'val' => '7',
                                             'numBits' => '32'
                                           },
                                           {
                                             'ctype' => 'int64_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S64> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_S64',
                                             'mnemo' => 's64',
                                             'val' => '8',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'f16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F16> >()',
                                             'numBytes' => '2',
                                             'name' => 'BRIG_TYPE_F16',
                                             'mnemo' => 'f16',
                                             'val' => '9',
                                             'numBits' => '16'
                                           },
                                           {
                                             'ctype' => 'float',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F32> >()',
                                             'numBytes' => '4',
                                             'name' => 'BRIG_TYPE_F32',
                                             'mnemo' => 'f32',
                                             'val' => '10',
                                             'numBits' => '32'
                                           },
                                           {
                                             'ctype' => 'double',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F64> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_F64',
                                             'mnemo' => 'f64',
                                             'val' => '11',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'bool',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B1> >()',
                                             'numBytes' => '1',
                                             'name' => 'BRIG_TYPE_B1',
                                             'mnemo' => 'b1',
                                             'val' => '12',
                                             'numBits' => '1'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B8> >()',
                                             'numBytes' => '1',
                                             'name' => 'BRIG_TYPE_B8',
                                             'mnemo' => 'b8',
                                             'val' => '13',
                                             'numBits' => '8'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B16> >()',
                                             'numBytes' => '2',
                                             'name' => 'BRIG_TYPE_B16',
                                             'mnemo' => 'b16',
                                             'val' => '14',
                                             'numBits' => '16'
                                           },
                                           {
                                             'ctype' => 'uint32_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B32> >()',
                                             'numBytes' => '4',
                                             'name' => 'BRIG_TYPE_B32',
                                             'mnemo' => 'b32',
                                             'val' => '15',
                                             'numBits' => '32'
                                           },
                                           {
                                             'ctype' => 'uint64_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B64> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_B64',
                                             'mnemo' => 'b64',
                                             'val' => '16',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'b128_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_B128> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_B128',
                                             'mnemo' => 'b128',
                                             'val' => '17',
                                             'numBits' => '128'
                                           },
                                           {
                                             'dispatch' => 'v.visitNone(type)',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_SAMP',
                                             'mnemo' => 'samp',
                                             'val' => '18',
                                             'numBits' => '64'
                                           },
                                           {
                                             'dispatch' => 'v.visitNone(type)',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_ROIMG',
                                             'mnemo' => 'roimg',
                                             'val' => '19',
                                             'numBits' => '64'
                                           },
                                           {
                                             'dispatch' => 'v.visitNone(type)',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_WOIMG',
                                             'mnemo' => 'woimg',
                                             'val' => '20',
                                             'numBits' => '64'
                                           },
                                           {
                                             'dispatch' => 'v.visitNone(type)',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_RWIMG',
                                             'mnemo' => 'rwimg',
                                             'val' => '21',
                                             'numBits' => '64'
                                           },
                                           {
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_SIG32> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_SIG32',
                                             'mnemo' => 'sig32',
                                             'val' => '22',
                                             'numBits' => '64'
                                           },
                                           {
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_SIG64> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_SIG64',
                                             'mnemo' => 'sig64',
                                             'val' => '23',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U8X4> >()',
                                             'numBytes' => '4',
                                             'name' => 'BRIG_TYPE_U8X4',
                                             'mnemo' => 'u8x4',
                                             'val' => 'BRIG_TYPE_U8 | BRIG_TYPE_PACK_32',
                                             'numBits' => '32'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U8X8> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_U8X8',
                                             'mnemo' => 'u8x8',
                                             'val' => 'BRIG_TYPE_U8 | BRIG_TYPE_PACK_64',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'uint8_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U8X16> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_U8X16',
                                             'mnemo' => 'u8x16',
                                             'val' => 'BRIG_TYPE_U8 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U16X2> >()',
                                             'numBytes' => '4',
                                             'name' => 'BRIG_TYPE_U16X2',
                                             'mnemo' => 'u16x2',
                                             'val' => 'BRIG_TYPE_U16 | BRIG_TYPE_PACK_32',
                                             'numBits' => '32'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U16X4> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_U16X4',
                                             'mnemo' => 'u16x4',
                                             'val' => 'BRIG_TYPE_U16 | BRIG_TYPE_PACK_64',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'uint16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U16X8> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_U16X8',
                                             'mnemo' => 'u16x8',
                                             'val' => 'BRIG_TYPE_U16 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'uint32_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U32X2> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_U32X2',
                                             'mnemo' => 'u32x2',
                                             'val' => 'BRIG_TYPE_U32 | BRIG_TYPE_PACK_64',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'uint32_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U32X4> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_U32X4',
                                             'mnemo' => 'u32x4',
                                             'val' => 'BRIG_TYPE_U32 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'uint64_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_U64X2> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_U64X2',
                                             'mnemo' => 'u64x2',
                                             'val' => 'BRIG_TYPE_U64 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'int8_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S8X4> >()',
                                             'numBytes' => '4',
                                             'name' => 'BRIG_TYPE_S8X4',
                                             'mnemo' => 's8x4',
                                             'val' => 'BRIG_TYPE_S8 | BRIG_TYPE_PACK_32',
                                             'numBits' => '32'
                                           },
                                           {
                                             'ctype' => 'int8_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S8X8> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_S8X8',
                                             'mnemo' => 's8x8',
                                             'val' => 'BRIG_TYPE_S8 | BRIG_TYPE_PACK_64',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'int8_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S8X16> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_S8X16',
                                             'mnemo' => 's8x16',
                                             'val' => 'BRIG_TYPE_S8 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'int16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S16X2> >()',
                                             'numBytes' => '4',
                                             'name' => 'BRIG_TYPE_S16X2',
                                             'mnemo' => 's16x2',
                                             'val' => 'BRIG_TYPE_S16 | BRIG_TYPE_PACK_32',
                                             'numBits' => '32'
                                           },
                                           {
                                             'ctype' => 'int16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S16X4> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_S16X4',
                                             'mnemo' => 's16x4',
                                             'val' => 'BRIG_TYPE_S16 | BRIG_TYPE_PACK_64',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'int16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S16X8> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_S16X8',
                                             'mnemo' => 's16x8',
                                             'val' => 'BRIG_TYPE_S16 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'int32_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S32X2> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_S32X2',
                                             'mnemo' => 's32x2',
                                             'val' => 'BRIG_TYPE_S32 | BRIG_TYPE_PACK_64',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'int32_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S32X4> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_S32X4',
                                             'mnemo' => 's32x4',
                                             'val' => 'BRIG_TYPE_S32 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'int64_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_S64X2> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_S64X2',
                                             'mnemo' => 's64x2',
                                             'val' => 'BRIG_TYPE_S64 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'f16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F16X2> >()',
                                             'numBytes' => '4',
                                             'name' => 'BRIG_TYPE_F16X2',
                                             'mnemo' => 'f16x2',
                                             'val' => 'BRIG_TYPE_F16 | BRIG_TYPE_PACK_32',
                                             'numBits' => '32'
                                           },
                                           {
                                             'ctype' => 'f16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F16X4> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_F16X4',
                                             'mnemo' => 'f16x4',
                                             'val' => 'BRIG_TYPE_F16 | BRIG_TYPE_PACK_64',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'f16_t',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F16X8> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_F16X8',
                                             'mnemo' => 'f16x8',
                                             'val' => 'BRIG_TYPE_F16 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'float',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F32X2> >()',
                                             'numBytes' => '8',
                                             'name' => 'BRIG_TYPE_F32X2',
                                             'mnemo' => 'f32x2',
                                             'val' => 'BRIG_TYPE_F32 | BRIG_TYPE_PACK_64',
                                             'numBits' => '64'
                                           },
                                           {
                                             'ctype' => 'float',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F32X4> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_F32X4',
                                             'mnemo' => 'f32x4',
                                             'val' => 'BRIG_TYPE_F32 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'ctype' => 'double',
                                             'dispatch' => 'v.template visit< BrigType<BRIG_TYPE_F64X2> >()',
                                             'numBytes' => '16',
                                             'name' => 'BRIG_TYPE_F64X2',
                                             'mnemo' => 'f64x2',
                                             'val' => 'BRIG_TYPE_F64 | BRIG_TYPE_PACK_128',
                                             'numBits' => '128'
                                           },
                                           {
                                             'dispatch' => 'v.visitNone(type)',
                                             'skip' => 'true',
                                             'name' => 'BRIG_TYPE_INVALID',
                                             'mnemo' => 'invalid',
                                             'val' => '-1 '
                                           }
                                         ],
                            'numBits#deps' => [],
                            'dispatch#calcState' => 'done',
                            'mnemo' => sub { "DUMMY" },
                            'numBytes#deps' => [
                                                 'numBits'
                                               ],
                            'numBits_switch' => 'true',
                            'dispatch_arg' => 'type',
                            'numBytes#calcState' => 'done',
                            'mnemo_token' => '_EMType',
                            'mnemo#deps' => [],
                            'numBits#calcState' => 'done',
                            'dispatch' => sub { "DUMMY" },
                            'numBits_proto' => 'unsigned getBrigTypeNumBits(unsigned arg)',
                            'dispatch_switch' => 'true',
                            'numBits_default' => 'assert(0); return 0',
                            'numBytes' => sub { "DUMMY" },
                            'numBytes_default' => 'assert(0); return 0',
                            'name' => 'BrigTypeX',
                            'numBytes_proto' => 'unsigned getBrigTypeNumBytes(unsigned arg)',
                            'numBytes_switch' => 'true',
                            'dispatch_incfile' => 'TemplateUtilities',
                            'dispatch_default' => 'return v.visitNone(type)',
                            'mnemo#calcState' => 'done',
                            'dispatch#deps' => [],
                            'numBits' => sub { "DUMMY" }
                          },
           'BrigOpcode' => {
                             'vecOpndIndex_proto' => 'int vecOpndIndex(Brig::BrigOpcode16_t arg)',
                             'numdst' => sub { "DUMMY" },
                             'entries' => [
                                            {
                                              'name' => 'BRIG_OPCODE_NOP',
                                              'mnemo' => 'nop',
                                              'val' => '0',
                                              'opcodeparser' => 'parseMnemoNop',
                                              'k' => 'NOP',
                                              'opcodevis' => 'vis.visitOpcode_NOP                            (inst)',
                                              'hasType' => 'false',
                                              'pscode' => 'Nop'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_ABS',
                                              'mnemo' => 'abs',
                                              'val' => '1',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_ABS                            (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_ADD',
                                              'mnemo' => 'add',
                                              'val' => '2',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_ADD                            (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_BORROW                         (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_BORROW',
                                              'mnemo' => 'borrow',
                                              'val' => '3',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_CARRY                          (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_CARRY',
                                              'mnemo' => 'carry',
                                              'val' => '4',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_CEIL',
                                              'mnemo' => 'ceil',
                                              'val' => '5',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_CEIL                           (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_COPYSIGN',
                                              'mnemo' => 'copysign',
                                              'val' => '6',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_COPYSIGN                       (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_DIV',
                                              'mnemo' => 'div',
                                              'val' => '7',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_DIV                            (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_FLOOR',
                                              'mnemo' => 'floor',
                                              'val' => '8',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_FLOOR                          (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_FMA',
                                              'mnemo' => 'fma',
                                              'val' => '9',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_FMA                            (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_FRACT',
                                              'mnemo' => 'fract',
                                              'val' => '10',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_FRACT                          (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_MAD                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_MAD',
                                              'mnemo' => 'mad',
                                              'val' => '11',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_MAX',
                                              'mnemo' => 'max',
                                              'val' => '12',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_MAX                            (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_MIN',
                                              'mnemo' => 'min',
                                              'val' => '13',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_MIN                            (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_MUL',
                                              'mnemo' => 'mul',
                                              'val' => '14',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_MUL                            (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_MULHI',
                                              'mnemo' => 'mulhi',
                                              'val' => '15',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_MULHI                          (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_NEG',
                                              'mnemo' => 'neg',
                                              'val' => '16',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_NEG                            (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_REM                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_REM',
                                              'mnemo' => 'rem',
                                              'val' => '17',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_RINT',
                                              'mnemo' => 'rint',
                                              'val' => '18',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_RINT                           (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_SQRT',
                                              'mnemo' => 'sqrt',
                                              'val' => '19',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_SQRT                           (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_SUB',
                                              'mnemo' => 'sub',
                                              'val' => '20',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_SUB                            (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_TRUNC',
                                              'mnemo' => 'trunc',
                                              'val' => '21',
                                              'opcodeparser' => 'parseMnemoBasicOrMod',
                                              'k' => 'BASIC_OR_MOD',
                                              'opcodevis' => 'vis.visitOpcode_TRUNC                          (inst)',
                                              'ftz' => 'true',
                                              'pscode' => 'BasicOrMod'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_MAD24                          (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_MAD24',
                                              'mnemo' => 'mad24',
                                              'val' => '22',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_MAD24HI                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_MAD24HI',
                                              'mnemo' => 'mad24hi',
                                              'val' => '23',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_MUL24                          (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_MUL24',
                                              'mnemo' => 'mul24',
                                              'val' => '24',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_MUL24HI                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_MUL24HI',
                                              'mnemo' => 'mul24hi',
                                              'val' => '25',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_SHL                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_SHL',
                                              'mnemo' => 'shl',
                                              'val' => '26',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_SHR                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_SHR',
                                              'mnemo' => 'shr',
                                              'val' => '27',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_AND                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_AND',
                                              'mnemo' => 'and',
                                              'val' => '28',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_NOT                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_NOT',
                                              'mnemo' => 'not',
                                              'val' => '29',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_OR                             (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_OR',
                                              'mnemo' => 'or',
                                              'val' => '30',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_POPCOUNT                       (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_POPCOUNT',
                                              'mnemo' => 'popcount',
                                              'val' => '31',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_XOR                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_XOR',
                                              'mnemo' => 'xor',
                                              'val' => '32',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_BITEXTRACT                     (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_BITEXTRACT',
                                              'mnemo' => 'bitextract',
                                              'val' => '33',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_BITINSERT                      (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_BITINSERT',
                                              'mnemo' => 'bitinsert',
                                              'val' => '34',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_BITMASK                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_BITMASK',
                                              'mnemo' => 'bitmask',
                                              'val' => '35',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_BITREV                         (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_BITREV',
                                              'mnemo' => 'bitrev',
                                              'val' => '36',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_BITSELECT                      (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_BITSELECT',
                                              'mnemo' => 'bitselect',
                                              'val' => '37',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_FIRSTBIT                       (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_FIRSTBIT',
                                              'mnemo' => 'firstbit',
                                              'val' => '38',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_LASTBIT                        (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_LASTBIT',
                                              'mnemo' => 'lastbit',
                                              'val' => '39',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'vecOpndIndex' => '1',
                                              'name' => 'BRIG_OPCODE_COMBINE',
                                              'mnemo' => 'combine',
                                              'val' => '40',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_COMBINE                        (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'vecOpndIndex' => '0',
                                              'name' => 'BRIG_OPCODE_EXPAND',
                                              'mnemo' => 'expand',
                                              'val' => '41',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_EXPAND                         (HSAIL_ASM::InstSourceType(inst))',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'ADDR',
                                              'opcodevis' => 'vis.visitOpcode_LDA                            (HSAIL_ASM::InstAddr(inst))',
                                              'name' => 'BRIG_OPCODE_LDA',
                                              'mnemo' => 'lda',
                                              'val' => '42',
                                              'opcodeparser' => 'parseMnemoAddr',
                                              'pscode' => 'Addr'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_MOV                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_MOV',
                                              'mnemo' => 'mov',
                                              'val' => '43',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_SHUFFLE                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_SHUFFLE',
                                              'mnemo' => 'shuffle',
                                              'val' => '44',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_UNPACKHI                       (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_UNPACKHI',
                                              'mnemo' => 'unpackhi',
                                              'val' => '45',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_UNPACKLO                       (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_UNPACKLO',
                                              'mnemo' => 'unpacklo',
                                              'val' => '46',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_PACK                           (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_PACK',
                                              'mnemo' => 'pack',
                                              'val' => '47',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_UNPACK                         (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_UNPACK',
                                              'mnemo' => 'unpack',
                                              'val' => '48',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_CMOV                           (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_CMOV',
                                              'mnemo' => 'cmov',
                                              'val' => '49',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_CLASS                          (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_CLASS',
                                              'mnemo' => 'class',
                                              'val' => '50',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_NCOS                           (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_NCOS',
                                              'mnemo' => 'ncos',
                                              'val' => '51',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_NEXP2                          (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_NEXP2',
                                              'mnemo' => 'nexp2',
                                              'val' => '52',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_NFMA                           (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_NFMA',
                                              'mnemo' => 'nfma',
                                              'val' => '53',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_NLOG2                          (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_NLOG2',
                                              'mnemo' => 'nlog2',
                                              'val' => '54',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_NRCP                           (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_NRCP',
                                              'mnemo' => 'nrcp',
                                              'val' => '55',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_NRSQRT                         (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_NRSQRT',
                                              'mnemo' => 'nrsqrt',
                                              'val' => '56',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_NSIN                           (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_NSIN',
                                              'mnemo' => 'nsin',
                                              'val' => '57',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_NSQRT                          (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_NSQRT',
                                              'mnemo' => 'nsqrt',
                                              'val' => '58',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_BITALIGN                       (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_BITALIGN',
                                              'mnemo' => 'bitalign',
                                              'val' => '59',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_BYTEALIGN                      (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_BYTEALIGN',
                                              'mnemo' => 'bytealign',
                                              'val' => '60',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_PACKCVT                        (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_PACKCVT',
                                              'mnemo' => 'packcvt',
                                              'val' => '61',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_UNPACKCVT                      (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_UNPACKCVT',
                                              'mnemo' => 'unpackcvt',
                                              'val' => '62',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_LERP                           (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_LERP',
                                              'mnemo' => 'lerp',
                                              'val' => '63',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_SAD                            (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_SAD',
                                              'mnemo' => 'sad',
                                              'val' => '64',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'SOURCE_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_SADHI                          (HSAIL_ASM::InstSourceType(inst))',
                                              'name' => 'BRIG_OPCODE_SADHI',
                                              'mnemo' => 'sadhi',
                                              'val' => '65',
                                              'opcodeparser' => 'parseMnemoSourceType',
                                              'pscode' => 'SourceType'
                                            },
                                            {
                                              'k' => 'SEG_CVT',
                                              'opcodevis' => 'vis.visitOpcode_SEGMENTP                       (HSAIL_ASM::InstSegCvt(inst))',
                                              'name' => 'BRIG_OPCODE_SEGMENTP',
                                              'mnemo' => 'segmentp',
                                              'val' => '66',
                                              'opcodeparser' => 'parseMnemoSegCvt',
                                              'pscode' => 'SegCvt'
                                            },
                                            {
                                              'k' => 'SEG_CVT',
                                              'opcodevis' => 'vis.visitOpcode_FTOS                           (HSAIL_ASM::InstSegCvt(inst))',
                                              'name' => 'BRIG_OPCODE_FTOS',
                                              'mnemo' => 'ftos',
                                              'val' => '67',
                                              'opcodeparser' => 'parseMnemoSegCvt',
                                              'pscode' => 'SegCvt'
                                            },
                                            {
                                              'k' => 'SEG_CVT',
                                              'opcodevis' => 'vis.visitOpcode_STOF                           (HSAIL_ASM::InstSegCvt(inst))',
                                              'name' => 'BRIG_OPCODE_STOF',
                                              'mnemo' => 'stof',
                                              'val' => '68',
                                              'opcodeparser' => 'parseMnemoSegCvt',
                                              'pscode' => 'SegCvt'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_CMP',
                                              'mnemo' => 'cmp',
                                              'val' => '69',
                                              'opcodeparser' => 'parseMnemoCmp',
                                              'k' => 'CMP',
                                              'opcodevis' => 'vis.visitOpcode_CMP                            (HSAIL_ASM::InstCmp(inst))',
                                              'ftz' => 'true',
                                              'pscode' => 'Cmp'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_CVT',
                                              'mnemo' => 'cvt',
                                              'val' => '70',
                                              'opcodeparser' => 'parseMnemoCvt',
                                              'k' => 'CVT',
                                              'opcodevis' => 'vis.visitOpcode_CVT                            (HSAIL_ASM::InstCvt(inst))',
                                              'ftz' => 'true',
                                              'pscode' => 'Cvt'
                                            },
                                            {
                                              'vecOpndIndex' => '0',
                                              'name' => 'BRIG_OPCODE_LD',
                                              'mnemo' => 'ld',
                                              'val' => '71',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.visitOpcode_LD                             (HSAIL_ASM::InstMem(inst))',
                                              'semsupport' => 'true',
                                              'has_memory_order' => 'true',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'numdst' => '0',
                                              'vecOpndIndex' => '0',
                                              'name' => 'BRIG_OPCODE_ST',
                                              'mnemo' => 'st',
                                              'val' => '72',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.visitOpcode_ST                             (HSAIL_ASM::InstMem(inst))',
                                              'semsupport' => 'true',
                                              'has_memory_order' => 'true',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'k' => 'ATOMIC',
                                              'opcodevis' => 'vis.visitOpcode_ATOMIC                         (HSAIL_ASM::InstAtomic(inst))',
                                              'name' => 'BRIG_OPCODE_ATOMIC',
                                              'mnemo' => 'atomic',
                                              'val' => '73',
                                              'opcodeparser' => 'parseMnemoAtomic',
                                              'pscode' => 'Atomic'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_ATOMICNORET',
                                              'mnemo' => 'atomicnoret',
                                              'val' => '74',
                                              'opcodeparser' => 'parseMnemoAtomic',
                                              'k' => 'ATOMIC',
                                              'opcodevis' => 'vis.visitOpcode_ATOMICNORET                    (HSAIL_ASM::InstAtomic(inst))',
                                              'pscode' => 'Atomic'
                                            },
                                            {
                                              'k' => 'SIGNAL',
                                              'opcodevis' => 'vis.visitOpcode_SIGNAL                         (HSAIL_ASM::InstSignal(inst))',
                                              'name' => 'BRIG_OPCODE_SIGNAL',
                                              'mnemo' => 'signal',
                                              'val' => '75',
                                              'opcodeparser' => 'parseMnemoSignal',
                                              'pscode' => 'Signal'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_SIGNALNORET',
                                              'mnemo' => 'signalnoret',
                                              'val' => '76',
                                              'opcodeparser' => 'parseMnemoSignal',
                                              'k' => 'SIGNAL',
                                              'opcodevis' => 'vis.visitOpcode_SIGNALNORET                    (HSAIL_ASM::InstSignal(inst))',
                                              'pscode' => 'Signal'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_MEMFENCE',
                                              'mnemo' => 'memfence',
                                              'val' => '77',
                                              'opcodeparser' => 'parseMnemoMemFence',
                                              'k' => 'MEM_FENCE',
                                              'opcodevis' => 'vis.visitOpcode_MEMFENCE                       (HSAIL_ASM::InstMemFence(inst))',
                                              'pscode' => 'MemFence'
                                            },
                                            {
                                              'vecOpndIndex' => '0',
                                              'name' => 'BRIG_OPCODE_RDIMAGE',
                                              'mnemo' => 'rdimage',
                                              'val' => '78',
                                              'opcodeparser' => 'parseMnemoImage',
                                              'k' => 'IMAGE',
                                              'opcodevis' => 'vis.visitOpcode_RDIMAGE                        (HSAIL_ASM::InstImage(inst))',
                                              'pscode' => 'Image'
                                            },
                                            {
                                              'vecOpndIndex' => '0',
                                              'name' => 'BRIG_OPCODE_LDIMAGE',
                                              'mnemo' => 'ldimage',
                                              'val' => '79',
                                              'opcodeparser' => 'parseMnemoImage',
                                              'k' => 'IMAGE',
                                              'opcodevis' => 'vis.visitOpcode_LDIMAGE                        (HSAIL_ASM::InstImage(inst))',
                                              'pscode' => 'Image'
                                            },
                                            {
                                              'numdst' => '0',
                                              'vecOpndIndex' => '0',
                                              'name' => 'BRIG_OPCODE_STIMAGE',
                                              'mnemo' => 'stimage',
                                              'val' => '80',
                                              'opcodeparser' => 'parseMnemoImage',
                                              'k' => 'IMAGE',
                                              'opcodevis' => 'vis.visitOpcode_STIMAGE                        (HSAIL_ASM::InstImage(inst))',
                                              'pscode' => 'Image'
                                            },
                                            {
                                              'k' => 'QUERY_IMAGE',
                                              'opcodevis' => 'vis.visitOpcode_QUERYIMAGE                     (HSAIL_ASM::InstQueryImage(inst))',
                                              'name' => 'BRIG_OPCODE_QUERYIMAGE',
                                              'mnemo' => 'queryimage',
                                              'val' => '81',
                                              'opcodeparser' => 'parseMnemoQueryImage',
                                              'pscode' => 'QueryImage'
                                            },
                                            {
                                              'k' => 'QUERY_SAMPLER',
                                              'opcodevis' => 'vis.visitOpcode_QUERYSAMPLER                   (HSAIL_ASM::InstQuerySampler(inst))',
                                              'name' => 'BRIG_OPCODE_QUERYSAMPLER',
                                              'mnemo' => 'querysampler',
                                              'val' => '82',
                                              'opcodeparser' => 'parseMnemoQuerySampler',
                                              'pscode' => 'QuerySampler'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_CBR',
                                              'mnemo' => 'cbr',
                                              'val' => '83',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_CBR                            (HSAIL_ASM::InstBr(inst))',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_BR',
                                              'mnemo' => 'br',
                                              'val' => '84',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_BR                             (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'psopnd' => 'SbrOperands',
                                              'name' => 'BRIG_OPCODE_SBR',
                                              'mnemo' => 'sbr',
                                              'val' => '85',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseSbrOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_SBR                            (HSAIL_ASM::InstBr(inst))',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_BARRIER',
                                              'mnemo' => 'barrier',
                                              'val' => '86',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_BARRIER                        (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_WAVEBARRIER',
                                              'mnemo' => 'wavebarrier',
                                              'val' => '87',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_WAVEBARRIER                    (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_ARRIVEFBAR',
                                              'mnemo' => 'arrivefbar',
                                              'val' => '88',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_ARRIVEFBAR                     (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_INITFBAR',
                                              'mnemo' => 'initfbar',
                                              'val' => '89',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_INITFBAR                       (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_JOINFBAR',
                                              'mnemo' => 'joinfbar',
                                              'val' => '90',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_JOINFBAR                       (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_LEAVEFBAR',
                                              'mnemo' => 'leavefbar',
                                              'val' => '91',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_LEAVEFBAR                      (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_RELEASEFBAR',
                                              'mnemo' => 'releasefbar',
                                              'val' => '92',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_RELEASEFBAR                    (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_WAITFBAR',
                                              'mnemo' => 'waitfbar',
                                              'val' => '93',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_WAITFBAR                       (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_LDF                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_LDF',
                                              'mnemo' => 'ldf',
                                              'val' => '94',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'LANE',
                                              'opcodevis' => 'vis.visitOpcode_ACTIVELANECOUNT                (HSAIL_ASM::InstLane(inst))',
                                              'name' => 'BRIG_OPCODE_ACTIVELANECOUNT',
                                              'mnemo' => 'activelanecount',
                                              'val' => '95',
                                              'opcodeparser' => 'parseMnemoLane',
                                              'pscode' => 'Lane'
                                            },
                                            {
                                              'k' => 'LANE',
                                              'opcodevis' => 'vis.visitOpcode_ACTIVELANEID                   (HSAIL_ASM::InstLane(inst))',
                                              'name' => 'BRIG_OPCODE_ACTIVELANEID',
                                              'mnemo' => 'activelaneid',
                                              'val' => '96',
                                              'opcodeparser' => 'parseMnemoLane',
                                              'pscode' => 'Lane'
                                            },
                                            {
                                              'vecOpndIndex' => '0',
                                              'name' => 'BRIG_OPCODE_ACTIVELANEMASK',
                                              'mnemo' => 'activelanemask',
                                              'val' => '97',
                                              'opcodeparser' => 'parseMnemoLane',
                                              'k' => 'LANE',
                                              'opcodevis' => 'vis.visitOpcode_ACTIVELANEMASK                 (HSAIL_ASM::InstLane(inst))',
                                              'pscode' => 'Lane'
                                            },
                                            {
                                              'k' => 'LANE',
                                              'opcodevis' => 'vis.visitOpcode_ACTIVELANESHUFFLE              (HSAIL_ASM::InstLane(inst))',
                                              'name' => 'BRIG_OPCODE_ACTIVELANESHUFFLE',
                                              'mnemo' => 'activelaneshuffle',
                                              'val' => '98',
                                              'opcodeparser' => 'parseMnemoLane',
                                              'pscode' => 'Lane'
                                            },
                                            {
                                              'numdst' => '0',
                                              'psopnd' => 'CallOperands',
                                              'name' => 'BRIG_OPCODE_CALL',
                                              'mnemo' => 'call',
                                              'val' => '99',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseCallOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_CALL                           (HSAIL_ASM::InstBr(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'psopnd' => 'CallOperands',
                                              'name' => 'BRIG_OPCODE_SCALL',
                                              'mnemo' => 'scall',
                                              'val' => '100',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseCallOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_SCALL                          (HSAIL_ASM::InstBr(inst))',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'numdst' => '0',
                                              'psopnd' => 'CallOperands',
                                              'name' => 'BRIG_OPCODE_ICALL',
                                              'mnemo' => 'icall',
                                              'val' => '101',
                                              'opcodeparser' => 'parseMnemoBr',
                                              'opndparser' => '&Parser::parseCallOperands',
                                              'k' => 'BR',
                                              'opcodevis' => 'vis.visitOpcode_ICALL                          (HSAIL_ASM::InstBr(inst))',
                                              'pscode' => 'Br'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_LDI                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_LDI',
                                              'mnemo' => 'ldi',
                                              'val' => '102',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_RET',
                                              'mnemo' => 'ret',
                                              'val' => '103',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_RET                            (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.visitOpcode_ALLOCA                         (HSAIL_ASM::InstMem(inst))',
                                              'name' => 'BRIG_OPCODE_ALLOCA',
                                              'mnemo' => 'alloca',
                                              'val' => '104',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_CURRENTWORKGROUPSIZE           (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_CURRENTWORKGROUPSIZE',
                                              'mnemo' => 'currentworkgroupsize',
                                              'val' => '105',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_DIM                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_DIM',
                                              'mnemo' => 'dim',
                                              'val' => '106',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GRIDGROUPS                     (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GRIDGROUPS',
                                              'mnemo' => 'gridgroups',
                                              'val' => '107',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GRIDSIZE                       (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GRIDSIZE',
                                              'mnemo' => 'gridsize',
                                              'val' => '108',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_PACKETCOMPLETIONSIG            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_PACKETCOMPLETIONSIG',
                                              'mnemo' => 'packetcompletionsig',
                                              'val' => '109',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_PACKETID                       (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_PACKETID',
                                              'mnemo' => 'packetid',
                                              'val' => '110',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_WORKGROUPID                    (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_WORKGROUPID',
                                              'mnemo' => 'workgroupid',
                                              'val' => '111',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_WORKGROUPSIZE                  (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_WORKGROUPSIZE',
                                              'mnemo' => 'workgroupsize',
                                              'val' => '112',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_WORKITEMABSID                  (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_WORKITEMABSID',
                                              'mnemo' => 'workitemabsid',
                                              'val' => '113',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_WORKITEMFLATABSID              (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_WORKITEMFLATABSID',
                                              'mnemo' => 'workitemflatabsid',
                                              'val' => '114',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_WORKITEMFLATID                 (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_WORKITEMFLATID',
                                              'mnemo' => 'workitemflatid',
                                              'val' => '115',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_WORKITEMID                     (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_WORKITEMID',
                                              'mnemo' => 'workitemid',
                                              'val' => '116',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_CLEARDETECTEXCEPT',
                                              'mnemo' => 'cleardetectexcept',
                                              'val' => '117',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_CLEARDETECTEXCEPT              (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GETDETECTEXCEPT                (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GETDETECTEXCEPT',
                                              'mnemo' => 'getdetectexcept',
                                              'val' => '118',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_SETDETECTEXCEPT',
                                              'mnemo' => 'setdetectexcept',
                                              'val' => '119',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_SETDETECTEXCEPT                (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.visitOpcode_ADDQUEUEWRITEINDEX             (HSAIL_ASM::InstQueue(inst))',
                                              'name' => 'BRIG_OPCODE_ADDQUEUEWRITEINDEX',
                                              'mnemo' => 'addqueuewriteindex',
                                              'val' => '120',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_AGENTCOUNT                     (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_AGENTCOUNT',
                                              'mnemo' => 'agentcount',
                                              'val' => '121',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_AGENTID                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_AGENTID',
                                              'mnemo' => 'agentid',
                                              'val' => '122',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.visitOpcode_CASQUEUEWRITEINDEX             (HSAIL_ASM::InstQueue(inst))',
                                              'name' => 'BRIG_OPCODE_CASQUEUEWRITEINDEX',
                                              'mnemo' => 'casqueuewriteindex',
                                              'val' => '123',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_LDK                            (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_LDK',
                                              'mnemo' => 'ldk',
                                              'val' => '124',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.visitOpcode_LDQUEUEREADINDEX               (HSAIL_ASM::InstQueue(inst))',
                                              'name' => 'BRIG_OPCODE_LDQUEUEREADINDEX',
                                              'mnemo' => 'ldqueuereadindex',
                                              'val' => '125',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.visitOpcode_LDQUEUEWRITEINDEX              (HSAIL_ASM::InstQueue(inst))',
                                              'name' => 'BRIG_OPCODE_LDQUEUEWRITEINDEX',
                                              'mnemo' => 'ldqueuewriteindex',
                                              'val' => '126',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_QUEUEID                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_QUEUEID',
                                              'mnemo' => 'queueid',
                                              'val' => '127',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_QUEUEPTR                       (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_QUEUEPTR',
                                              'mnemo' => 'queueptr',
                                              'val' => '128',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_STQUEUEREADINDEX',
                                              'mnemo' => 'stqueuereadindex',
                                              'val' => '129',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.visitOpcode_STQUEUEREADINDEX               (HSAIL_ASM::InstQueue(inst))',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_STQUEUEWRITEINDEX',
                                              'mnemo' => 'stqueuewriteindex',
                                              'val' => '130',
                                              'opcodeparser' => 'parseMnemoQueue',
                                              'k' => 'QUEUE',
                                              'opcodevis' => 'vis.visitOpcode_STQUEUEWRITEINDEX              (HSAIL_ASM::InstQueue(inst))',
                                              'pscode' => 'Queue'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_CLOCK                          (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_CLOCK',
                                              'mnemo' => 'clock',
                                              'val' => '131',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_CUID                           (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_CUID',
                                              'mnemo' => 'cuid',
                                              'val' => '132',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'numdst' => '0',
                                              'name' => 'BRIG_OPCODE_DEBUGTRAP',
                                              'mnemo' => 'debugtrap',
                                              'val' => '133',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_DEBUGTRAP                      (HSAIL_ASM::InstBasic(inst))',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GROUPBASEPTR                   (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GROUPBASEPTR',
                                              'mnemo' => 'groupbaseptr',
                                              'val' => '134',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_KERNARGBASEPTR                 (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_KERNARGBASEPTR',
                                              'mnemo' => 'kernargbaseptr',
                                              'val' => '135',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_LANEID                         (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_LANEID',
                                              'mnemo' => 'laneid',
                                              'val' => '136',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_MAXCUID                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_MAXCUID',
                                              'mnemo' => 'maxcuid',
                                              'val' => '137',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_MAXWAVEID                      (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_MAXWAVEID',
                                              'mnemo' => 'maxwaveid',
                                              'val' => '138',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'SEG',
                                              'opcodevis' => 'vis.visitOpcode_NULLPTR                        (HSAIL_ASM::InstSeg(inst))',
                                              'name' => 'BRIG_OPCODE_NULLPTR',
                                              'mnemo' => 'nullptr',
                                              'val' => '139',
                                              'opcodeparser' => 'parseMnemoSeg',
                                              'pscode' => 'Seg'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_WAVEID                         (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_WAVEID',
                                              'mnemo' => 'waveid',
                                              'val' => '140',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_GCNMADU',
                                              'mnemo' => 'gcn_madu',
                                              'val' => '(1u << 15) | 0',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_GCNMADU                        (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_GCNMADS',
                                              'mnemo' => 'gcn_mads',
                                              'val' => '(1u << 15) | 1',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_GCNMADS                        (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNMAX3                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNMAX3',
                                              'mnemo' => 'gcn_max3',
                                              'val' => '(1u << 15) | 2',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNMIN3                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNMIN3',
                                              'mnemo' => 'gcn_min3',
                                              'val' => '(1u << 15) | 3',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNMED3                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNMED3',
                                              'mnemo' => 'gcn_med3',
                                              'val' => '(1u << 15) | 4',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNFLDEXP                      (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNFLDEXP',
                                              'mnemo' => 'gcn_fldexp',
                                              'val' => '(1u << 15) | 5',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNFREXP_EXP                   (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNFREXP_EXP',
                                              'mnemo' => 'gcn_frexp_exp',
                                              'val' => '(1u << 15) | 6',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNFREXP_MANT                  (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNFREXP_MANT',
                                              'mnemo' => 'gcn_frexp_mant',
                                              'val' => '(1u << 15) | 7',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNTRIG_PREOP                  (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNTRIG_PREOP',
                                              'mnemo' => 'gcn_trig_preop',
                                              'val' => '(1u << 15) | 8',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNBFM                         (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNBFM',
                                              'mnemo' => 'gcn_bfm',
                                              'val' => '(1u << 15) | 9',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'vecOpndIndex' => '0',
                                              'name' => 'BRIG_OPCODE_GCNLD',
                                              'mnemo' => 'gcn_ld',
                                              'val' => '(1u << 15) | 10',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.visitOpcode_GCNLD                          (HSAIL_ASM::InstMem(inst))',
                                              'semsupport' => 'true',
                                              'has_memory_order' => 'true',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'vecOpndIndex' => '0',
                                              'name' => 'BRIG_OPCODE_GCNST',
                                              'mnemo' => 'gcn_st',
                                              'val' => '(1u << 15) | 11',
                                              'opcodeparser' => 'parseMnemoMem',
                                              'k' => 'MEM',
                                              'opcodevis' => 'vis.visitOpcode_GCNST                          (HSAIL_ASM::InstMem(inst))',
                                              'semsupport' => 'true',
                                              'has_memory_order' => 'true',
                                              'pscode' => 'Mem'
                                            },
                                            {
                                              'k' => 'ATOMIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNATOMIC                      (HSAIL_ASM::InstAtomic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNATOMIC',
                                              'mnemo' => 'gcn_atomic',
                                              'val' => '(1u << 15) | 12',
                                              'opcodeparser' => 'parseMnemoAtomic',
                                              'pscode' => 'Atomic'
                                            },
                                            {
                                              'k' => 'ATOMIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNATOMICNORET                 (HSAIL_ASM::InstAtomic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNATOMICNORET',
                                              'mnemo' => 'gcn_atomicNoRet',
                                              'val' => '(1u << 15) | 13',
                                              'opcodeparser' => 'parseMnemoAtomic',
                                              'pscode' => 'Atomic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNSLEEP                       (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNSLEEP',
                                              'mnemo' => 'gcn_sleep',
                                              'val' => '(1u << 15) | 14',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNPRIORITY                    (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNPRIORITY',
                                              'mnemo' => 'gcn_priority',
                                              'val' => '(1u << 15) | 15',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_GCNREGIONALLOC',
                                              'mnemo' => 'gcn_region_alloc',
                                              'val' => '(1u << 15) | 16',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_GCNREGIONALLOC                 (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNMSAD                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNMSAD',
                                              'mnemo' => 'gcn_msad',
                                              'val' => '(1u << 15) | 17',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNQSAD                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNQSAD',
                                              'mnemo' => 'gcn_qsad',
                                              'val' => '(1u << 15) | 18',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNMQSAD                       (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNMQSAD',
                                              'mnemo' => 'gcn_mqsad',
                                              'val' => '(1u << 15) | 19',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'name' => 'BRIG_OPCODE_GCNMQSAD4',
                                              'mnemo' => 'gcn_mqsad4',
                                              'val' => '(1u << 15) | 20',
                                              'opcodeparser' => 'parseMnemoBasicNoType',
                                              'k' => 'BASIC_NO_TYPE',
                                              'opcodevis' => 'vis.visitOpcode_GCNMQSAD4                      (HSAIL_ASM::InstBasic(inst))',
                                              'hasType' => 'false',
                                              'pscode' => 'BasicNoType'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNSADW                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNSADW',
                                              'mnemo' => 'gcn_sadw',
                                              'val' => '(1u << 15) | 21',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNSADD                        (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNSADD',
                                              'mnemo' => 'gcn_sadd',
                                              'val' => '(1u << 15) | 22',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'ADDR',
                                              'opcodevis' => 'vis.visitOpcode_GCNCONSUME                     (HSAIL_ASM::InstAddr(inst))',
                                              'name' => 'BRIG_OPCODE_GCNCONSUME',
                                              'mnemo' => 'gcn_atomic_consume',
                                              'val' => '(1u << 15) | 23',
                                              'opcodeparser' => 'parseMnemoAddr',
                                              'pscode' => 'Addr'
                                            },
                                            {
                                              'k' => 'ADDR',
                                              'opcodevis' => 'vis.visitOpcode_GCNAPPEND                      (HSAIL_ASM::InstAddr(inst))',
                                              'name' => 'BRIG_OPCODE_GCNAPPEND',
                                              'mnemo' => 'gcn_atomic_append',
                                              'val' => '(1u << 15) | 24',
                                              'opcodeparser' => 'parseMnemoAddr',
                                              'pscode' => 'Addr'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNB4XCHG                      (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNB4XCHG',
                                              'mnemo' => 'gcn_b4xchg',
                                              'val' => '(1u << 15) | 25',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNB32XCHG                     (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNB32XCHG',
                                              'mnemo' => 'gcn_b32xchg',
                                              'val' => '(1u << 15) | 26',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNMAX                         (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNMAX',
                                              'mnemo' => 'gcn_max',
                                              'val' => '(1u << 15) | 27',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            },
                                            {
                                              'k' => 'BASIC',
                                              'opcodevis' => 'vis.visitOpcode_GCNMIN                         (HSAIL_ASM::InstBasic(inst))',
                                              'name' => 'BRIG_OPCODE_GCNMIN',
                                              'mnemo' => 'gcn_min',
                                              'val' => '(1u << 15) | 28',
                                              'opcodeparser' => 'parseMnemoBasic',
                                              'pscode' => 'Basic'
                                            }
                                          ],
                             'opcodevis_arg' => 'inst.opcode()',
                             'opndparser_default' => 'return &Parser::parseOperands',
                             'tdcaption' => 'Instruction Opcodes',
                             'hasType_proto' => 'bool instHasType(Brig::BrigOpcode16_t arg)',
                             'opndparser_incfile' => 'ParserUtilities',
                             'pscode' => sub { "DUMMY" },
                             'opcodeparser#calcState' => 'done',
                             'ftz_incfile' => 'ItemUtils',
                             'opcodevis#deps' => [
                                                   'pscode'
                                                 ],
                             'pscode#deps' => [
                                                'k'
                                              ],
                             'opcodeparser_default' => 'return parseMnemoBasic',
                             'vecOpndIndex' => sub { "DUMMY" },
                             'hasType_default' => 'return true',
                             'name' => 'BrigOpcode',
                             'psopnd' => sub { "DUMMY" },
                             'vecOpndIndex#deps' => [],
                             'opndparser_switch' => 'true',
                             'psopnd#deps' => [],
                             'mnemo#calcState' => 'done',
                             'has_memory_order#calcState' => 'done',
                             'opcodevis' => sub { "DUMMY" },
                             'ftz' => sub { "DUMMY" },
                             'hasType' => sub { "DUMMY" },
                             'k#deps' => [],
                             'ftz#deps' => [
                                             'k'
                                           ],
                             'ftz_switch' => 'true',
                             'semsupport#calcState' => 'done',
                             'ftz_proto' => 'inline bool instSupportsFtz(Brig::BrigOpcode16_t arg)',
                             'opndparser_proto' => 'Parser::OperandParser Parser::getOperandParser(Brig::BrigOpcode16_t arg)',
                             'vecOpndIndex#calcState' => 'done',
                             'vecOpndIndex_incfile' => 'ParserUtilities',
                             'psopnd#calcState' => 'done',
                             'numdst#calcState' => 'done',
                             'mnemo_token' => 'EInstruction',
                             'has_memory_order' => sub { "DUMMY" },
                             'opndparser#deps' => [
                                                    'psopnd'
                                                  ],
                             'pscode#calcState' => 'done',
                             'opcodeparser_switch' => 'true',
                             'mnemo_scanner' => 'Instructions',
                             'semsupport#deps' => [
                                                    'has_memory_order'
                                                  ],
                             'numdst#deps' => [],
                             'opcodeparser_proto' => 'OpcodeParser getOpcodeParser(Brig::BrigOpcode16_t arg)',
                             'opndparser' => sub { "DUMMY" },
                             'opcodevis_default' => 'return RetType()',
                             'hasType#calcState' => 'done',
                             'has_memory_order#deps' => [],
                             'opcodeparser#deps' => [
                                                      'pscode'
                                                    ],
                             'mnemo' => sub { "DUMMY" },
                             'opcodeparser_incfile' => 'ParserUtilities',
                             'opcodeparser' => sub { "DUMMY" },
                             'opndparser#calcState' => 'done',
                             'k' => sub { "DUMMY" },
                             'opcodevis_switch' => 'true',
                             'k#calcState' => 'done',
                             'opcodevis_proto' => 'template <typename RetType, typename Visitor> RetType visitOpcode_gen(HSAIL_ASM::Inst inst, Visitor& vis)',
                             'hasType#deps' => [
                                                 'k'
                                               ],
                             'hasType_switch' => 'true',
                             'vecOpndIndex_default' => 'return -1',
                             'ftz_default' => 'return false',
                             'opcodevis#calcState' => 'done',
                             'vecOpndIndex_switch' => 'true',
                             'numdst_proto' => 'int instNumDstOperands(Brig::BrigOpcode16_t arg)',
                             'opcodevis_incfile' => 'ItemUtils',
                             'semsupport' => sub { "DUMMY" },
                             'mnemo#deps' => [],
                             'numdst_default' => 'return 1',
                             'ftz#calcState' => 'done',
                             'mnemo_context' => 'EDefaultContext',
                             'numdst_switch' => 'true'
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
                              'mnemo_context' => 'EInstModifierContext',
                              'name' => 'BrigSegment',
                              'mnemo' => sub { "DUMMY" },
                              'mnemo_token' => '_EMSegment'
                            },
           'BrigAluModifierMask' => {
                                      'entries' => [
                                                     {
                                                       'name' => 'BRIG_ALU_ROUND',
                                                       'val' => '31'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ALU_FTZ',
                                                       'val' => '32'
                                                     }
                                                   ],
                                      'name' => 'BrigAluModifierMask'
                                    },
           'BrigAlignment' => {
                                'bytes' => sub { "DUMMY" },
                                'bytes_switch' => 'true',
                                'rbytes#calcState' => 'done',
                                'entries' => [
                                               {
                                                 'name' => 'BRIG_ALIGNMENT_NONE',
                                                 'mnemo' => 'none',
                                                 'val' => '0',
                                                 'no_mnemo' => 'true'
                                               },
                                               {
                                                 'bytes' => '1',
                                                 'name' => 'BRIG_ALIGNMENT_1',
                                                 'mnemo' => '',
                                                 'val' => '1',
                                                 'rbytes' => '1'
                                               },
                                               {
                                                 'bytes' => '2',
                                                 'name' => 'BRIG_ALIGNMENT_2',
                                                 'mnemo' => '2',
                                                 'val' => '2',
                                                 'rbytes' => '2'
                                               },
                                               {
                                                 'bytes' => '4',
                                                 'name' => 'BRIG_ALIGNMENT_4',
                                                 'mnemo' => '4',
                                                 'val' => '3',
                                                 'rbytes' => '4'
                                               },
                                               {
                                                 'bytes' => '8',
                                                 'name' => 'BRIG_ALIGNMENT_8',
                                                 'mnemo' => '8',
                                                 'val' => '4',
                                                 'rbytes' => '8'
                                               },
                                               {
                                                 'bytes' => '16',
                                                 'name' => 'BRIG_ALIGNMENT_16',
                                                 'mnemo' => '16',
                                                 'val' => '5',
                                                 'rbytes' => '16'
                                               },
                                               {
                                                 'bytes' => '32',
                                                 'name' => 'BRIG_ALIGNMENT_32',
                                                 'mnemo' => '32',
                                                 'val' => '6',
                                                 'rbytes' => '32'
                                               },
                                               {
                                                 'bytes' => '64',
                                                 'name' => 'BRIG_ALIGNMENT_64',
                                                 'mnemo' => '64',
                                                 'val' => '7',
                                                 'rbytes' => '64'
                                               },
                                               {
                                                 'bytes' => '128',
                                                 'name' => 'BRIG_ALIGNMENT_128',
                                                 'mnemo' => '128',
                                                 'val' => '8',
                                                 'rbytes' => '128'
                                               },
                                               {
                                                 'bytes' => '256',
                                                 'name' => 'BRIG_ALIGNMENT_256',
                                                 'mnemo' => '256',
                                                 'val' => '9',
                                                 'rbytes' => '256'
                                               },
                                               {
                                                 'skip' => 'true',
                                                 'name' => 'BRIG_ALIGNMENT_LAST',
                                                 'mnemo' => 'last'
                                               },
                                               {
                                                 'skip' => 'true',
                                                 'name' => 'BRIG_ALIGNMENT_MAX',
                                                 'mnemo' => 'max',
                                                 'val' => 'BRIG_ALIGNMENT_LAST - 1 '
                                               }
                                             ],
                                'rbytes_reverse' => 'true',
                                'mnemo' => sub { "DUMMY" },
                                'bytes_default' => 'assert(false); return -1',
                                'rbytes_default' => 'return BRIG_ALIGNMENT_LAST',
                                'bytes#deps' => [],
                                'bytes_proto' => 'unsigned align2num(unsigned arg)',
                                'rbytes_proto' => 'Brig::BrigAlignment num2align(uint64_t arg)',
                                'mnemo_proto' => 'const char* align2str(unsigned arg)',
                                'rbytes#deps' => [
                                                   'bytes'
                                                 ],
                                'mnemo#deps' => [],
                                'name' => 'BrigAlignment',
                                'bytes#calcState' => 'done',
                                'mnemo#calcState' => 'done',
                                'rbytes_switch' => 'true',
                                'rbytes' => sub { "DUMMY" }
                              },
           'BrigRegisterKind' => {
                                   'mnemo#deps' => [],
                                   'bits#deps' => [],
                                   'entries' => [
                                                  {
                                                    'name' => 'BRIG_REGISTER_CONTROL',
                                                    'mnemo' => '$c',
                                                    'bits' => '1',
                                                    'val' => '0'
                                                  },
                                                  {
                                                    'name' => 'BRIG_REGISTER_SINGLE',
                                                    'mnemo' => '$s',
                                                    'bits' => '32',
                                                    'val' => '1'
                                                  },
                                                  {
                                                    'name' => 'BRIG_REGISTER_DOUBLE',
                                                    'mnemo' => '$d',
                                                    'bits' => '64',
                                                    'val' => '2'
                                                  },
                                                  {
                                                    'name' => 'BRIG_REGISTER_QUAD',
                                                    'mnemo' => '$q',
                                                    'bits' => '128',
                                                    'val' => '3     '
                                                  }
                                                ],
                                   'name' => 'BrigRegisterKind',
                                   'mnemo' => sub { "DUMMY" },
                                   'bits_switch' => 'true',
                                   'mnemo#calcState' => 'done',
                                   'bits#calcState' => 'done',
                                   'bits' => sub { "DUMMY" },
                                   'bits_proto' => 'unsigned getRegBits(Brig::BrigRegisterKind16_t arg)',
                                   'bits_default' => 'return (unsigned)-1'
                                 },
           'BrigKinds' => {
                            'isToplevelOnly#calcState' => 'done',
                            'isBodyOnly#calcState' => 'done',
                            'isBodyOnly_proto' => 'bool isBodyOnly(Directive d)',
                            'entries' => [
                                           {
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_NONE',
                                             'mnemo' => 'None',
                                             'val' => '0x0000',
                                             'sizeof' => 'sizeof(BrigNone)',
                                             'wname' => 'None',
                                             'skip' => 'true',
                                             'isBodyOnly' => 'false'
                                           },
                                           {
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_BEGIN',
                                             'mnemo' => 'DirectiveBegin',
                                             'val' => '0x1000',
                                             'sizeof' => 'sizeof(BrigDirectiveBegin)',
                                             'wname' => 'DirectiveBegin',
                                             'skip' => 'true',
                                             'isBodyOnly' => 'false'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveArgBlockEnd)',
                                             'wname' => 'DirectiveArgBlockEnd',
                                             'isBodyOnly' => 'true',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_ARG_BLOCK_END',
                                             'mnemo' => 'DirectiveArgBlockEnd',
                                             'val' => '0x1000'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveArgBlockStart)',
                                             'wname' => 'DirectiveArgBlockStart',
                                             'isBodyOnly' => 'true',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_ARG_BLOCK_START',
                                             'mnemo' => 'DirectiveArgBlockStart',
                                             'val' => '0x1001'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveComment)',
                                             'wname' => 'DirectiveComment',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_COMMENT',
                                             'mnemo' => 'DirectiveComment',
                                             'val' => '0x1002'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveControl)',
                                             'wname' => 'DirectiveControl',
                                             'isBodyOnly' => 'true',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_CONTROL',
                                             'mnemo' => 'DirectiveControl',
                                             'val' => '0x1003'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveExtension)',
                                             'wname' => 'DirectiveExtension',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'true',
                                             'name' => 'BRIG_KIND_DIRECTIVE_EXTENSION',
                                             'mnemo' => 'DirectiveExtension',
                                             'val' => '0x1004'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveFbarrier)',
                                             'wname' => 'DirectiveFbarrier',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_FBARRIER',
                                             'mnemo' => 'DirectiveFbarrier',
                                             'val' => '0x1005'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveFunction)',
                                             'wname' => 'DirectiveFunction',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'true',
                                             'name' => 'BRIG_KIND_DIRECTIVE_FUNCTION',
                                             'mnemo' => 'DirectiveFunction',
                                             'val' => '0x1006'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveIndirectFunction)',
                                             'wname' => 'DirectiveIndirectFunction',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'true',
                                             'name' => 'BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION',
                                             'mnemo' => 'DirectiveIndirectFunction',
                                             'val' => '0x1007'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveKernel)',
                                             'wname' => 'DirectiveKernel',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'true',
                                             'name' => 'BRIG_KIND_DIRECTIVE_KERNEL',
                                             'mnemo' => 'DirectiveKernel',
                                             'val' => '0x1008'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveLabel)',
                                             'wname' => 'DirectiveLabel',
                                             'isBodyOnly' => 'true',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_LABEL',
                                             'mnemo' => 'DirectiveLabel',
                                             'val' => '0x1009'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveLoc)',
                                             'wname' => 'DirectiveLoc',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_LOC',
                                             'mnemo' => 'DirectiveLoc',
                                             'val' => '0x100a'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectivePragma)',
                                             'wname' => 'DirectivePragma',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_PRAGMA',
                                             'mnemo' => 'DirectivePragma',
                                             'val' => '0x100b'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveSignature)',
                                             'wname' => 'DirectiveSignature',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'true',
                                             'name' => 'BRIG_KIND_DIRECTIVE_SIGNATURE',
                                             'mnemo' => 'DirectiveSignature',
                                             'val' => '0x100c'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveVariable)',
                                             'wname' => 'DirectiveVariable',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_VARIABLE',
                                             'mnemo' => 'DirectiveVariable',
                                             'val' => '0x100d'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigDirectiveVersion)',
                                             'wname' => 'DirectiveVersion',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'true',
                                             'name' => 'BRIG_KIND_DIRECTIVE_VERSION',
                                             'mnemo' => 'DirectiveVersion',
                                             'val' => '0x100e'
                                           },
                                           {
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_DIRECTIVE_END',
                                             'mnemo' => 'DirectiveEnd',
                                             'val' => '0x100f',
                                             'sizeof' => 'sizeof(BrigDirectiveEnd)',
                                             'wname' => 'DirectiveEnd',
                                             'skip' => 'true',
                                             'isBodyOnly' => 'false'
                                           },
                                           {
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_BEGIN',
                                             'mnemo' => 'InstBegin',
                                             'val' => '0x2000',
                                             'sizeof' => 'sizeof(BrigInstBegin)',
                                             'wname' => 'InstBegin',
                                             'skip' => 'true',
                                             'isBodyOnly' => 'false'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstAddr)',
                                             'wname' => 'InstAddr',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_ADDR',
                                             'mnemo' => 'InstAddr',
                                             'val' => '0x2000'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstAtomic)',
                                             'wname' => 'InstAtomic',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_ATOMIC',
                                             'mnemo' => 'InstAtomic',
                                             'val' => '0x2001'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstBasic)',
                                             'wname' => 'InstBasic',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_BASIC',
                                             'mnemo' => 'InstBasic',
                                             'val' => '0x2002'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstBr)',
                                             'wname' => 'InstBr',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_BR',
                                             'mnemo' => 'InstBr',
                                             'val' => '0x2003'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstCmp)',
                                             'wname' => 'InstCmp',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_CMP',
                                             'mnemo' => 'InstCmp',
                                             'val' => '0x2004'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstCvt)',
                                             'wname' => 'InstCvt',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_CVT',
                                             'mnemo' => 'InstCvt',
                                             'val' => '0x2005'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstImage)',
                                             'wname' => 'InstImage',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_IMAGE',
                                             'mnemo' => 'InstImage',
                                             'val' => '0x2006'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstLane)',
                                             'wname' => 'InstLane',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_LANE',
                                             'mnemo' => 'InstLane',
                                             'val' => '0x2007'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstMem)',
                                             'wname' => 'InstMem',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_MEM',
                                             'mnemo' => 'InstMem',
                                             'val' => '0x2008'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstMemFence)',
                                             'wname' => 'InstMemFence',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_MEM_FENCE',
                                             'mnemo' => 'InstMemFence',
                                             'val' => '0x2009'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstMod)',
                                             'wname' => 'InstMod',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_MOD',
                                             'mnemo' => 'InstMod',
                                             'val' => '0x200a'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstQueryImage)',
                                             'wname' => 'InstQueryImage',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_QUERY_IMAGE',
                                             'mnemo' => 'InstQueryImage',
                                             'val' => '0x200b'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstQuerySampler)',
                                             'wname' => 'InstQuerySampler',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_QUERY_SAMPLER',
                                             'mnemo' => 'InstQuerySampler',
                                             'val' => '0x200c'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstQueue)',
                                             'wname' => 'InstQueue',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_QUEUE',
                                             'mnemo' => 'InstQueue',
                                             'val' => '0x200d'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstSeg)',
                                             'wname' => 'InstSeg',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_SEG',
                                             'mnemo' => 'InstSeg',
                                             'val' => '0x200e'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstSegCvt)',
                                             'wname' => 'InstSegCvt',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_SEG_CVT',
                                             'mnemo' => 'InstSegCvt',
                                             'val' => '0x200f'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstSignal)',
                                             'wname' => 'InstSignal',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_SIGNAL',
                                             'mnemo' => 'InstSignal',
                                             'val' => '0x2010'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigInstSourceType)',
                                             'wname' => 'InstSourceType',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_SOURCE_TYPE',
                                             'mnemo' => 'InstSourceType',
                                             'val' => '0x2011'
                                           },
                                           {
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_INST_END',
                                             'mnemo' => 'InstEnd',
                                             'val' => '0x2012',
                                             'sizeof' => 'sizeof(BrigInstEnd)',
                                             'wname' => 'InstEnd',
                                             'skip' => 'true',
                                             'isBodyOnly' => 'false'
                                           },
                                           {
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_BEGIN',
                                             'mnemo' => 'OperandBegin',
                                             'val' => '0x3000',
                                             'sizeof' => 'sizeof(BrigOperandBegin)',
                                             'wname' => 'OperandBegin',
                                             'skip' => 'true',
                                             'isBodyOnly' => 'false'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandAddress)',
                                             'wname' => 'OperandAddress',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_ADDRESS',
                                             'mnemo' => 'OperandAddress',
                                             'val' => '0x3000'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandData)',
                                             'wname' => 'OperandData',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_DATA',
                                             'mnemo' => 'OperandData',
                                             'val' => '0x3001'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandCodeList)',
                                             'wname' => 'OperandCodeList',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_CODE_LIST',
                                             'mnemo' => 'OperandCodeList',
                                             'val' => '0x3002'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandCodeRef)',
                                             'wname' => 'OperandCodeRef',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_CODE_REF',
                                             'mnemo' => 'OperandCodeRef',
                                             'val' => '0x3003'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandImageProperties)',
                                             'wname' => 'OperandImageProperties',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_IMAGE_PROPERTIES',
                                             'mnemo' => 'OperandImageProperties',
                                             'val' => '0x3004'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandOperandList)',
                                             'wname' => 'OperandOperandList',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_OPERAND_LIST',
                                             'mnemo' => 'OperandOperandList',
                                             'val' => '0x3005'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandReg)',
                                             'wname' => 'OperandReg',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_REG',
                                             'mnemo' => 'OperandReg',
                                             'val' => '0x3006'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandSamplerProperties)',
                                             'wname' => 'OperandSamplerProperties',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_SAMPLER_PROPERTIES',
                                             'mnemo' => 'OperandSamplerProperties',
                                             'val' => '0x3007'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandString)',
                                             'wname' => 'OperandString',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_STRING',
                                             'mnemo' => 'OperandString',
                                             'val' => '0x3008'
                                           },
                                           {
                                             'sizeof' => 'sizeof(BrigOperandWavesize)',
                                             'wname' => 'OperandWavesize',
                                             'isBodyOnly' => 'false',
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_WAVESIZE',
                                             'mnemo' => 'OperandWavesize',
                                             'val' => '0x3009'
                                           },
                                           {
                                             'isToplevelOnly' => 'false',
                                             'name' => 'BRIG_KIND_OPERAND_END',
                                             'mnemo' => 'OperandEnd',
                                             'val' => '0x300a ',
                                             'sizeof' => 'sizeof(BrigOperandEnd)',
                                             'wname' => 'OperandEnd',
                                             'skip' => 'true',
                                             'isBodyOnly' => 'false'
                                           }
                                         ],
                            'sizeof#deps' => [
                                               'wname'
                                             ],
                            'isToplevelOnly#deps' => [],
                            'isBodyOnly_arg' => 'd.brig()->kind',
                            'mnemo' => sub { "DUMMY" },
                            'sizeof' => sub { "DUMMY" },
                            'wname' => sub { "DUMMY" },
                            'sizeof#calcState' => 'done',
                            'sizeof_switch' => 'true',
                            'isToplevelOnly_switch' => 'true',
                            'isToplevelOnly_arg' => 'd.brig()->kind',
                            'mnemo#deps' => [
                                              'wname'
                                            ],
                            'isToplevelOnly' => sub { "DUMMY" },
                            'name' => 'BrigKinds',
                            'wname#deps' => [],
                            'isBodyOnly_default' => 'assert(false); return false',
                            'sizeof_proto' => 'int size_of_brig_record(unsigned arg)',
                            'isToplevelOnly_default' => 'assert(false); return false',
                            'mnemo#calcState' => 'done',
                            'isToplevelOnly_proto' => 'bool isToplevelOnly(Directive d)',
                            'isBodyOnly#deps' => [],
                            'isBodyOnly' => sub { "DUMMY" },
                            'wname#calcState' => 'done',
                            'sizeof_default' => 'return -1',
                            'isBodyOnly_switch' => 'true'
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
                                                     'name' => 'BRIG_GEOMETRY_2DA',
                                                     'mnemo' => '2da',
                                                     'val' => '4'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_1DB',
                                                     'mnemo' => '1db',
                                                     'val' => '5'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_2DDEPTH',
                                                     'mnemo' => '2ddepth',
                                                     'val' => '6'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_2DADEPTH',
                                                     'mnemo' => '2dadepth',
                                                     'val' => '7'
                                                   },
                                                   {
                                                     'name' => 'BRIG_GEOMETRY_UNKNOWN',
                                                     'mnemo' => ''
                                                   }
                                                 ],
                                    'tdcaption' => 'Geometry',
                                    'name' => 'BrigImageGeometry',
                                    'mnemo' => sub { "DUMMY" },
                                    'mnemo_token' => 'EImageGeometry'
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
                                               'name' => 'BRIG_LINKAGE_PROGRAM',
                                               'mnemo' => 'program',
                                               'val' => '1'
                                             },
                                             {
                                               'name' => 'BRIG_LINKAGE_MODULE',
                                               'mnemo' => 'module',
                                               'val' => '2'
                                             },
                                             {
                                               'name' => 'BRIG_LINKAGE_FUNCTION',
                                               'mnemo' => 'function',
                                               'val' => '3'
                                             },
                                             {
                                               'name' => 'BRIG_LINKAGE_ARG',
                                               'mnemo' => 'arg',
                                               'val' => '4'
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
                                          'mnemo#calcState' => 'done',
                                          'mnemo#deps' => [],
                                          'entries' => [
                                                         {
                                                           'name' => 'BRIG_MEMORY_FENCE_SEGMENT_GLOBAL',
                                                           'mnemo' => 'global',
                                                           'val' => '0'
                                                         },
                                                         {
                                                           'name' => 'BRIG_MEMORY_FENCE_SEGMENT_GROUP',
                                                           'mnemo' => 'group',
                                                           'val' => '1'
                                                         },
                                                         {
                                                           'name' => 'BRIG_MEMORY_FENCE_SEGMENT_IMAGE',
                                                           'mnemo' => 'image',
                                                           'val' => '2'
                                                         },
                                                         {
                                                           'skip' => 'true',
                                                           'name' => 'BRIG_MEMORY_FENCE_SEGMENT_LAST',
                                                           'mnemo' => 'last',
                                                           'val' => '3 '
                                                         }
                                                       ],
                                          'mnemo_context' => 'EInstModifierInstFenceContext',
                                          'name' => 'BrigMemoryFenceSegments',
                                          'mnemo' => sub { "DUMMY" },
                                          'mnemo_token' => '_EMMemoryFenceSegments'
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
                                                   'name' => 'BRIG_MEMORY_ORDER_SC_ACQUIRE',
                                                   'mnemo' => 'scacq',
                                                   'val' => '2'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_ORDER_SC_RELEASE',
                                                   'mnemo' => 'screl',
                                                   'val' => '3'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE',
                                                   'mnemo' => 'scar',
                                                   'val' => '4 '
                                                 }
                                               ],
                                  'name' => 'BrigMemoryOrder',
                                  'mnemo' => sub { "DUMMY" },
                                  'mnemo_token' => '_EMMemoryOrder'
                                },
           'BrigSamplerAddressing' => {
                                        'mnemo#calcState' => 'done',
                                        'mnemo#deps' => [],
                                        'entries' => [
                                                       {
                                                         'name' => 'BRIG_ADDRESSING_UNDEFINED',
                                                         'mnemo' => 'undefined',
                                                         'val' => '0'
                                                       },
                                                       {
                                                         'name' => 'BRIG_ADDRESSING_CLAMP_TO_EDGE',
                                                         'mnemo' => 'clamp_to_edge',
                                                         'val' => '1'
                                                       },
                                                       {
                                                         'name' => 'BRIG_ADDRESSING_CLAMP_TO_BORDER',
                                                         'mnemo' => 'clamp_to_border',
                                                         'val' => '2'
                                                       },
                                                       {
                                                         'name' => 'BRIG_ADDRESSING_REPEAT',
                                                         'mnemo' => 'repeat',
                                                         'val' => '3'
                                                       },
                                                       {
                                                         'name' => 'BRIG_ADDRESSING_MIRRORED_REPEAT',
                                                         'mnemo' => 'mirrored_repeat',
                                                         'val' => '4'
                                                       }
                                                     ],
                                        'name' => 'BrigSamplerAddressing',
                                        'mnemo' => sub { "DUMMY" },
                                        'mnemo_token' => 'ESamplerAddressingMode'
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
                                                    'val' => '2 '
                                                  }
                                                ],
                                   'name' => 'BrigMachineModel',
                                   'mnemo' => sub { "DUMMY" },
                                   'mnemo_token' => 'ETargetMachine'
                                 },
           'BrigSamplerCoordNormalization' => {
                                                'mnemo#calcState' => 'done',
                                                'mnemo#deps' => [],
                                                'entries' => [
                                                               {
                                                                 'name' => 'BRIG_COORD_UNNORMALIZED',
                                                                 'mnemo' => 'unnormalized',
                                                                 'val' => '0'
                                                               },
                                                               {
                                                                 'name' => 'BRIG_COORD_NORMALIZED',
                                                                 'mnemo' => 'normalized',
                                                                 'val' => '1'
                                                               }
                                                             ],
                                                'name' => 'BrigSamplerCoordNormalization',
                                                'mnemo' => sub { "DUMMY" },
                                                'mnemo_token' => 'ESamplerCoord'
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
                                             },
                                             {
                                               'skip' => 'true',
                                               'name' => 'BRIG_PROFILE_UNDEF',
                                               'mnemo' => '$undef',
                                               'val' => '2 '
                                             }
                                           ],
                              'name' => 'BrigProfile',
                              'mnemo' => sub { "DUMMY" },
                              'mnemo_token' => 'ETargetProfile'
                            },
           'BrigImageChannelType' => {
                                       'mnemo#calcState' => 'done',
                                       'mnemo#deps' => [],
                                       'entries' => [
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_SNORM_INT8',
                                                        'mnemo' => 'snorm_int8',
                                                        'val' => '0'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_SNORM_INT16',
                                                        'mnemo' => 'snorm_int16',
                                                        'val' => '1'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNORM_INT8',
                                                        'mnemo' => 'unorm_int8',
                                                        'val' => '2'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNORM_INT16',
                                                        'mnemo' => 'unorm_int16',
                                                        'val' => '3'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNORM_INT24',
                                                        'mnemo' => 'unorm_int24',
                                                        'val' => '4'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNORM_SHORT_555',
                                                        'mnemo' => 'unorm_short_555',
                                                        'val' => '5'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNORM_SHORT_565',
                                                        'mnemo' => 'unorm_short_565',
                                                        'val' => '6'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNORM_INT_101010',
                                                        'mnemo' => 'unorm_int_101010',
                                                        'val' => '7'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_SIGNED_INT8',
                                                        'mnemo' => 'signed_int8',
                                                        'val' => '8'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_SIGNED_INT16',
                                                        'mnemo' => 'signed_int16',
                                                        'val' => '9'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_SIGNED_INT32',
                                                        'mnemo' => 'signed_int32',
                                                        'val' => '10'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNSIGNED_INT8',
                                                        'mnemo' => 'unsigned_int8',
                                                        'val' => '11'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNSIGNED_INT16',
                                                        'mnemo' => 'unsigned_int16',
                                                        'val' => '12'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNSIGNED_INT32',
                                                        'mnemo' => 'unsigned_int32',
                                                        'val' => '13'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_HALF_FLOAT',
                                                        'mnemo' => 'half_float',
                                                        'val' => '14'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_FLOAT',
                                                        'mnemo' => 'float',
                                                        'val' => '15'
                                                      },
                                                      {
                                                        'name' => 'BRIG_CHANNEL_TYPE_UNKNOWN',
                                                        'mnemo' => ''
                                                      }
                                                    ],
                                       'name' => 'BrigImageChannelType',
                                       'mnemo' => sub { "DUMMY" },
                                       'mnemo_token' => 'EImageFormat'
                                     },
           'BrigSectionIndex' => {
                                   'mnemo#calcState' => 'done',
                                   'mnemo#deps' => [],
                                   'entries' => [
                                                  {
                                                    'name' => 'BRIG_SECTION_INDEX_DATA',
                                                    'mnemo' => 'hsa_data',
                                                    'val' => '0'
                                                  },
                                                  {
                                                    'name' => 'BRIG_SECTION_INDEX_CODE',
                                                    'mnemo' => 'hsa_code',
                                                    'val' => '1'
                                                  },
                                                  {
                                                    'name' => 'BRIG_SECTION_INDEX_OPERAND',
                                                    'mnemo' => 'hsa_operand',
                                                    'val' => '2'
                                                  },
                                                  {
                                                    'name' => 'BRIG_SECTION_INDEX_BEGIN_IMPLEMENTATION_DEFINED',
                                                    'mnemo' => 'hsa_begin_implementation_defined',
                                                    'val' => '3'
                                                  },
                                                  {
                                                    'skip' => 'true',
                                                    'name' => 'BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED',
                                                    'mnemo' => 'hsa_implementation_defined',
                                                    'val' => 'BRIG_SECTION_INDEX_BEGIN_IMPLEMENTATION_DEFINED '
                                                  }
                                                ],
                                   'name' => 'BrigSectionIndex',
                                   'mnemo' => sub { "DUMMY" }
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
                                                       'name' => 'BRIG_ATOMIC_EXCH',
                                                       'mnemo' => 'exch',
                                                       'val' => '3'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_LD',
                                                       'mnemo' => 'ld',
                                                       'val' => '4'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_MAX',
                                                       'mnemo' => 'max',
                                                       'val' => '5'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_MIN',
                                                       'mnemo' => 'min',
                                                       'val' => '6'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_OR',
                                                       'mnemo' => 'or',
                                                       'val' => '7'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_ST',
                                                       'mnemo' => 'st',
                                                       'val' => '8'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_SUB',
                                                       'mnemo' => 'sub',
                                                       'val' => '9'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WRAPDEC',
                                                       'mnemo' => 'wrapdec',
                                                       'val' => '10'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WRAPINC',
                                                       'mnemo' => 'wrapinc',
                                                       'val' => '11'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_XOR',
                                                       'mnemo' => 'xor',
                                                       'val' => '12'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WAIT_EQ',
                                                       'mnemo' => 'wait_eq',
                                                       'val' => '13'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WAIT_NE',
                                                       'mnemo' => 'wait_ne',
                                                       'val' => '14'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WAIT_LT',
                                                       'mnemo' => 'wait_lt',
                                                       'val' => '15'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WAIT_GTE',
                                                       'mnemo' => 'wait_gte',
                                                       'val' => '16'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WAITTIMEOUT_EQ',
                                                       'mnemo' => 'waittimeout_eq',
                                                       'val' => '17'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WAITTIMEOUT_NE',
                                                       'mnemo' => 'waittimeout_ne',
                                                       'val' => '18'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WAITTIMEOUT_LT',
                                                       'mnemo' => 'waittimeout_lt',
                                                       'val' => '19'
                                                     },
                                                     {
                                                       'name' => 'BRIG_ATOMIC_WAITTIMEOUT_GTE',
                                                       'mnemo' => 'waittimeout_gte',
                                                       'val' => '20'
                                                     }
                                                   ],
                                      'name' => 'BrigAtomicOperation',
                                      'mnemo' => sub { "DUMMY" },
                                      'mnemo#calcState' => 'done',
                                      'tdcaption' => 'Atomic Operations',
                                      'mnemo_context' => 'EInstModifierInstAtomicContext',
                                      'mnemo_token' => '_EMAtomicOp'
                                    },
           'BrigSegCvtModifierMask' => {
                                         'entries' => [
                                                        {
                                                          'name' => 'BRIG_SEG_CVT_NONULL',
                                                          'mnemo' => 'nonull',
                                                          'val' => '1 '
                                                        }
                                                      ],
                                         'name' => 'BrigSegCvtModifierMask'
                                       },
           'BrigImageChannelOrder' => {
                                        'mnemo#calcState' => 'done',
                                        'mnemo#deps' => [],
                                        'entries' => [
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_A',
                                                         'mnemo' => 'a',
                                                         'val' => '0'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_R',
                                                         'mnemo' => 'r',
                                                         'val' => '1'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_RX',
                                                         'mnemo' => 'rx',
                                                         'val' => '2'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_RG',
                                                         'mnemo' => 'rg',
                                                         'val' => '3'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_RGX',
                                                         'mnemo' => 'rgx',
                                                         'val' => '4'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_RA',
                                                         'mnemo' => 'ra',
                                                         'val' => '5'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_RGB',
                                                         'mnemo' => 'rgb',
                                                         'val' => '6'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_RGBX',
                                                         'mnemo' => 'rgbx',
                                                         'val' => '7'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_RGBA',
                                                         'mnemo' => 'rgba',
                                                         'val' => '8'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_BGRA',
                                                         'mnemo' => 'bgra',
                                                         'val' => '9'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_ARGB',
                                                         'mnemo' => 'argb',
                                                         'val' => '10'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_ABGR',
                                                         'mnemo' => 'abgr',
                                                         'val' => '11'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_SRGB',
                                                         'mnemo' => 'srgb',
                                                         'val' => '12'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_SRGBX',
                                                         'mnemo' => 'srgbx',
                                                         'val' => '13'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_SRGBA',
                                                         'mnemo' => 'srgba',
                                                         'val' => '14'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_SBGRA',
                                                         'mnemo' => 'sbgra',
                                                         'val' => '15'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_INTENSITY',
                                                         'mnemo' => 'intensity',
                                                         'val' => '16'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_LUMINANCE',
                                                         'mnemo' => 'luminance',
                                                         'val' => '17'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_DEPTH',
                                                         'mnemo' => 'depth',
                                                         'val' => '18'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_DEPTH_STENCIL',
                                                         'mnemo' => 'depth_stencil',
                                                         'val' => '19'
                                                       },
                                                       {
                                                         'name' => 'BRIG_CHANNEL_ORDER_UNKNOWN',
                                                         'mnemo' => ''
                                                       }
                                                     ],
                                        'mnemo_context' => 'EImageOrderContext',
                                        'name' => 'BrigImageChannelOrder',
                                        'mnemo' => sub { "DUMMY" },
                                        'mnemo_token' => 'EImageOrder'
                                      },
           'BrigAllocation' => {
                                 'mnemo#calcState' => 'done',
                                 'mnemo#deps' => [],
                                 'entries' => [
                                                {
                                                  'name' => 'BRIG_ALLOCATION_NONE',
                                                  'mnemo' => '',
                                                  'val' => '0'
                                                },
                                                {
                                                  'name' => 'BRIG_ALLOCATION_PROGRAM',
                                                  'mnemo' => 'program',
                                                  'val' => '1'
                                                },
                                                {
                                                  'name' => 'BRIG_ALLOCATION_AGENT',
                                                  'mnemo' => 'agent',
                                                  'val' => '2'
                                                },
                                                {
                                                  'name' => 'BRIG_ALLOCATION_AUTOMATIC',
                                                  'mnemo' => 'automatic',
                                                  'val' => '3'
                                                }
                                              ],
                                 'name' => 'BrigAllocation',
                                 'mnemo' => sub { "DUMMY" },
                                 'mnemo_token' => 'EAllocKind'
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
                                                   'name' => 'BRIG_MEMORY_SCOPE_WORKITEM',
                                                   'mnemo' => 'wi',
                                                   'val' => '1'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_SCOPE_WAVEFRONT',
                                                   'mnemo' => 'wv',
                                                   'val' => '2'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_SCOPE_WORKGROUP',
                                                   'mnemo' => 'wg',
                                                   'val' => '3'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_SCOPE_COMPONENT',
                                                   'mnemo' => 'cmp',
                                                   'val' => '4'
                                                 },
                                                 {
                                                   'name' => 'BRIG_MEMORY_SCOPE_SYSTEM',
                                                   'mnemo' => 'sys',
                                                   'val' => '5 '
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
           'BrigExecutableModifierMask' => {
                                             'entries' => [
                                                            {
                                                              'name' => 'BRIG_EXECUTABLE_DEFINITION',
                                                              'val' => '1'
                                                            }
                                                          ],
                                             'name' => 'BrigExecutableModifierMask',
                                             'nodump' => 'true'
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
