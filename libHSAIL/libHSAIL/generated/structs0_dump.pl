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
$structs = {
             'BrigDirectiveLabel' => {
                                       'parent' => 'BrigDirective',
                                       'wname' => 'DirectiveLabel',
                                       'fields' => [
                                                     {
                                                       'wname' => 'byteCount',
                                                       'name' => 'byteCount',
                                                       'wtype' => 'ValRef<uint16_t>',
                                                       'type' => 'uint16_t',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'kind',
                                                       'enum' => 'BrigKinds',
                                                       'name' => 'kind',
                                                       'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                       'type' => 'BrigKinds16_t',
                                                       'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                     },
                                                     {
                                                       'wname' => 'name',
                                                       'name' => 'name',
                                                       'wtype' => 'StrRef',
                                                       'type' => 'BrigDataOffsetString32_t',
                                                       'defValue' => '0',
                                                       'acc' => 'strRef'
                                                     }
                                                   ],
                                       'align' => undef,
                                       'enum' => 'BRIG_KIND_DIRECTIVE_LABEL',
                                       'name' => 'BrigDirectiveLabel'
                                     },
             'BrigInstSignal' => {
                                   'parent' => 'BrigInst',
                                   'wname' => 'InstSignal',
                                   'fields' => [
                                                 {
                                                   'wname' => 'byteCount',
                                                   'name' => 'byteCount',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'uint16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'kind',
                                                   'enum' => 'BrigKinds',
                                                   'name' => 'kind',
                                                   'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                   'type' => 'BrigKinds16_t',
                                                   'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                 },
                                                 {
                                                   'wname' => 'opcode',
                                                   'enum' => 'BrigOpcode',
                                                   'name' => 'opcode',
                                                   'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                   'type' => 'BrigOpcode16_t',
                                                   'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                 },
                                                 {
                                                   'wname' => 'type',
                                                   'name' => 'type',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'BrigType16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'operands',
                                                   'name' => 'operands',
                                                   'wtype' => 'ListRef<Operand>',
                                                   'type' => 'BrigDataOffsetOperandList32_t',
                                                   'defValue' => '0',
                                                   'acc' => 'listRef<Operand>'
                                                 },
                                                 {
                                                   'wname' => 'signalType',
                                                   'name' => 'signalType',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'BrigType16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'memoryOrder',
                                                   'enum' => 'BrigMemoryOrder',
                                                   'name' => 'memoryOrder',
                                                   'wtype' => 'EnumValRef<Brig::BrigMemoryOrder,uint8_t>',
                                                   'type' => 'BrigMemoryOrder8_t',
                                                   'defValue' => 'Brig::BRIG_MEMORY_ORDER_RELAXED',
                                                   'acc' => 'enumValRef<Brig::BrigMemoryOrder,uint8_t>'
                                                 },
                                                 {
                                                   'wname' => 'signalOperation',
                                                   'enum' => 'BrigAtomicOperation',
                                                   'name' => 'signalOperation',
                                                   'wtype' => 'EnumValRef<Brig::BrigAtomicOperation,uint8_t>',
                                                   'type' => 'BrigAtomicOperation8_t',
                                                   'acc' => 'enumValRef<Brig::BrigAtomicOperation,uint8_t>'
                                                 }
                                               ],
                                   'align' => undef,
                                   'enum' => 'BRIG_KIND_INST_SIGNAL',
                                   'name' => 'BrigInstSignal'
                                 },
             'BrigOperandCodeList' => {
                                        'parent' => 'BrigOperand',
                                        'wname' => 'OperandCodeList',
                                        'fields' => [
                                                      {
                                                        'wname' => 'byteCount',
                                                        'name' => 'byteCount',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'kind',
                                                        'enum' => 'BrigKinds',
                                                        'name' => 'kind',
                                                        'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                        'type' => 'BrigKinds16_t',
                                                        'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                      },
                                                      {
                                                        'implcode' => [
                                                                        'inline unsigned KLASS::elementCount() { return elements().size(); }',
                                                                        'inline Code KLASS::elements(int index) { return elements()[index]; }'
                                                                      ],
                                                        'hcode' => [
                                                                     'unsigned elementCount();',
                                                                     'Code elements(int index);'
                                                                   ],
                                                        'name' => 'elements',
                                                        'defValue' => '0',
                                                        'acc' => 'listRef<Code>',
                                                        'wname' => 'elements',
                                                        'type' => 'BrigDataOffsetCodeList32_t',
                                                        'wtype' => 'ListRef<Code>'
                                                      }
                                                    ],
                                        'align' => undef,
                                        'enum' => 'BRIG_KIND_OPERAND_CODE_LIST',
                                        'name' => 'BrigOperandCodeList'
                                      },
             'BrigDirectiveExtension' => {
                                           'parent' => 'BrigDirective',
                                           'wname' => 'DirectiveExtension',
                                           'fields' => [
                                                         {
                                                           'wname' => 'byteCount',
                                                           'name' => 'byteCount',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'kind',
                                                           'enum' => 'BrigKinds',
                                                           'name' => 'kind',
                                                           'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                           'type' => 'BrigKinds16_t',
                                                           'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                         },
                                                         {
                                                           'wname' => 'name',
                                                           'name' => 'name',
                                                           'wtype' => 'StrRef',
                                                           'type' => 'BrigDataOffsetString32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'strRef'
                                                         }
                                                       ],
                                           'align' => undef,
                                           'enum' => 'BRIG_KIND_DIRECTIVE_EXTENSION',
                                           'name' => 'BrigDirectiveExtension'
                                         },
             'BrigOperandOperandList' => {
                                           'parent' => 'BrigOperand',
                                           'wname' => 'OperandOperandList',
                                           'fields' => [
                                                         {
                                                           'wname' => 'byteCount',
                                                           'name' => 'byteCount',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'kind',
                                                           'enum' => 'BrigKinds',
                                                           'name' => 'kind',
                                                           'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                           'type' => 'BrigKinds16_t',
                                                           'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                         },
                                                         {
                                                           'implcode' => [
                                                                           'inline unsigned KLASS::elementCount() { return elements().size(); }',
                                                                           'inline Operand KLASS::elements(int index) { return elements()[index]; }'
                                                                         ],
                                                           'hcode' => [
                                                                        'unsigned elementCount();',
                                                                        'Operand elements(int index);'
                                                                      ],
                                                           'name' => 'elements',
                                                           'defValue' => '0',
                                                           'acc' => 'listRef<Operand>',
                                                           'wname' => 'elements',
                                                           'type' => 'BrigDataOffsetOperandList32_t',
                                                           'wtype' => 'ListRef<Operand>'
                                                         }
                                                       ],
                                           'align' => undef,
                                           'enum' => 'BRIG_KIND_OPERAND_OPERAND_LIST',
                                           'name' => 'BrigOperandOperandList'
                                         },
             'BrigDirectiveVariable' => {
                                          'parent' => 'BrigDirective',
                                          'wname' => 'DirectiveVariable',
                                          'fields' => [
                                                        {
                                                          'wname' => 'byteCount',
                                                          'name' => 'byteCount',
                                                          'wtype' => 'ValRef<uint16_t>',
                                                          'type' => 'uint16_t',
                                                          'acc' => 'valRef'
                                                        },
                                                        {
                                                          'wname' => 'kind',
                                                          'enum' => 'BrigKinds',
                                                          'name' => 'kind',
                                                          'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                          'type' => 'BrigKinds16_t',
                                                          'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                        },
                                                        {
                                                          'wname' => 'name',
                                                          'name' => 'name',
                                                          'wtype' => 'StrRef',
                                                          'type' => 'BrigDataOffsetString32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'strRef'
                                                        },
                                                        {
                                                          'wname' => 'init',
                                                          'name' => 'init',
                                                          'wtype' => 'ItemRef<Operand>',
                                                          'type' => 'BrigOperandOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'itemRef<Operand>'
                                                        },
                                                        {
                                                          'wname' => 'type',
                                                          'name' => 'type',
                                                          'wtype' => 'ValRef<uint16_t>',
                                                          'type' => 'BrigType16_t',
                                                          'acc' => 'valRef'
                                                        },
                                                        {
                                                          'wname' => 'segment',
                                                          'enum' => 'BrigSegment',
                                                          'name' => 'segment',
                                                          'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                          'type' => 'BrigSegment8_t',
                                                          'defValue' => 'Brig::BRIG_SEGMENT_NONE',
                                                          'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                                        },
                                                        {
                                                          'wname' => 'align',
                                                          'enum' => 'BrigAlignment',
                                                          'name' => 'align',
                                                          'wtype' => 'EnumValRef<Brig::BrigAlignment,uint8_t>',
                                                          'type' => 'BrigAlignment8_t',
                                                          'defValue' => 'Brig::BRIG_ALIGNMENT_NONE',
                                                          'acc' => 'enumValRef<Brig::BrigAlignment,uint8_t>'
                                                        },
                                                        {
                                                          'wname' => 'dim',
                                                          'name' => 'dim',
                                                          'wtype' => 'UInt64',
                                                          'type' => 'BrigUInt64',
                                                          'acc' => 'subItem<UInt64>'
                                                        },
                                                        {
                                                          'wname' => 'modifier',
                                                          'name' => 'modifier',
                                                          'wtype' => 'VariableModifier',
                                                          'type' => 'BrigVariableModifier',
                                                          'acc' => 'subItem<VariableModifier>'
                                                        },
                                                        {
                                                          'wname' => 'linkage',
                                                          'enum' => 'BrigLinkage',
                                                          'name' => 'linkage',
                                                          'wtype' => 'EnumValRef<Brig::BrigLinkage,uint8_t>',
                                                          'type' => 'BrigLinkage8_t',
                                                          'defValue' => 'Brig::BRIG_LINKAGE_NONE',
                                                          'acc' => 'enumValRef<Brig::BrigLinkage,uint8_t>'
                                                        },
                                                        {
                                                          'wname' => 'allocation',
                                                          'enum' => 'BrigAllocation',
                                                          'name' => 'allocation',
                                                          'wtype' => 'EnumValRef<Brig::BrigAllocation,uint8_t>',
                                                          'type' => 'BrigAllocation8_t',
                                                          'defValue' => 'Brig::BRIG_ALLOCATION_NONE',
                                                          'acc' => 'enumValRef<Brig::BrigAllocation,uint8_t>'
                                                        },
                                                        {
                                                          'wname' => 'reserved',
                                                          'skip' => 1,
                                                          'name' => 'reserved',
                                                          'wtype' => 'ValRef<uint8_t>',
                                                          'type' => 'uint8_t',
                                                          'defValue' => '0',
                                                          'acc' => 'valRef'
                                                        }
                                                      ],
                                          'align' => undef,
                                          'enum' => 'BRIG_KIND_DIRECTIVE_VARIABLE',
                                          'name' => 'BrigDirectiveVariable'
                                        },
             'BrigInstMemFence' => {
                                     'parent' => 'BrigInst',
                                     'wname' => 'InstMemFence',
                                     'fields' => [
                                                   {
                                                     'wname' => 'byteCount',
                                                     'name' => 'byteCount',
                                                     'wtype' => 'ValRef<uint16_t>',
                                                     'type' => 'uint16_t',
                                                     'acc' => 'valRef'
                                                   },
                                                   {
                                                     'wname' => 'kind',
                                                     'enum' => 'BrigKinds',
                                                     'name' => 'kind',
                                                     'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                     'type' => 'BrigKinds16_t',
                                                     'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                   },
                                                   {
                                                     'wname' => 'opcode',
                                                     'enum' => 'BrigOpcode',
                                                     'name' => 'opcode',
                                                     'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                     'type' => 'BrigOpcode16_t',
                                                     'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                   },
                                                   {
                                                     'wname' => 'type',
                                                     'name' => 'type',
                                                     'wtype' => 'ValRef<uint16_t>',
                                                     'type' => 'BrigType16_t',
                                                     'acc' => 'valRef'
                                                   },
                                                   {
                                                     'wname' => 'operands',
                                                     'name' => 'operands',
                                                     'wtype' => 'ListRef<Operand>',
                                                     'type' => 'BrigDataOffsetOperandList32_t',
                                                     'defValue' => '0',
                                                     'acc' => 'listRef<Operand>'
                                                   },
                                                   {
                                                     'wname' => 'memoryOrder',
                                                     'enum' => 'BrigMemoryOrder',
                                                     'name' => 'memoryOrder',
                                                     'wtype' => 'EnumValRef<Brig::BrigMemoryOrder,uint8_t>',
                                                     'type' => 'BrigMemoryOrder8_t',
                                                     'defValue' => 'Brig::BRIG_MEMORY_ORDER_RELAXED',
                                                     'acc' => 'enumValRef<Brig::BrigMemoryOrder,uint8_t>'
                                                   },
                                                   {
                                                     'wname' => 'globalSegmentMemoryScope',
                                                     'enum' => 'BrigMemoryScope',
                                                     'name' => 'globalSegmentMemoryScope',
                                                     'wtype' => 'EnumValRef<Brig::BrigMemoryScope,uint8_t>',
                                                     'type' => 'BrigMemoryScope8_t',
                                                     'defValue' => 'Brig::BRIG_MEMORY_SCOPE_SYSTEM',
                                                     'acc' => 'enumValRef<Brig::BrigMemoryScope,uint8_t>'
                                                   },
                                                   {
                                                     'wname' => 'groupSegmentMemoryScope',
                                                     'enum' => 'BrigMemoryScope',
                                                     'name' => 'groupSegmentMemoryScope',
                                                     'wtype' => 'EnumValRef<Brig::BrigMemoryScope,uint8_t>',
                                                     'type' => 'BrigMemoryScope8_t',
                                                     'defValue' => 'Brig::BRIG_MEMORY_SCOPE_SYSTEM',
                                                     'acc' => 'enumValRef<Brig::BrigMemoryScope,uint8_t>'
                                                   },
                                                   {
                                                     'wname' => 'imageSegmentMemoryScope',
                                                     'enum' => 'BrigMemoryScope',
                                                     'name' => 'imageSegmentMemoryScope',
                                                     'wtype' => 'EnumValRef<Brig::BrigMemoryScope,uint8_t>',
                                                     'type' => 'BrigMemoryScope8_t',
                                                     'defValue' => 'Brig::BRIG_MEMORY_SCOPE_SYSTEM',
                                                     'acc' => 'enumValRef<Brig::BrigMemoryScope,uint8_t>'
                                                   }
                                                 ],
                                     'align' => undef,
                                     'enum' => 'BRIG_KIND_INST_MEM_FENCE',
                                     'name' => 'BrigInstMemFence'
                                   },
             'BrigDirectiveArgBlockStart' => {
                                               'parent' => 'BrigDirective',
                                               'wname' => 'DirectiveArgBlockStart',
                                               'fields' => [
                                                             {
                                                               'wname' => 'byteCount',
                                                               'name' => 'byteCount',
                                                               'wtype' => 'ValRef<uint16_t>',
                                                               'type' => 'uint16_t',
                                                               'acc' => 'valRef'
                                                             },
                                                             {
                                                               'wname' => 'kind',
                                                               'enum' => 'BrigKinds',
                                                               'name' => 'kind',
                                                               'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                               'type' => 'BrigKinds16_t',
                                                               'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                             }
                                                           ],
                                               'align' => undef,
                                               'enum' => 'BRIG_KIND_DIRECTIVE_ARG_BLOCK_START',
                                               'name' => 'BrigDirectiveArgBlockStart'
                                             },
             'BrigAluModifier' => {
                                    'wname' => 'AluModifier',
                                    'fields' => [
                                                  {
                                                    'wname' => 'allBits',
                                                    'name' => 'allBits',
                                                    'wtype' => 'ValRef<uint16_t>',
                                                    'type' => 'BrigAluModifier16_t',
                                                    'defValue' => '0',
                                                    'acc' => 'valRef'
                                                  },
                                                  {
                                                    'wname' => 'round',
                                                    'phantomof' => $structs->{'BrigAluModifier'}{'fields'}[0],
                                                    'enum' => 'BrigRound',
                                                    'name' => 'round',
                                                    'wtype' => 'BFValRef<Brig::BrigRound8_t,0,5>',
                                                    'type' => 'BrigRound8_t',
                                                    'acc' => 'bFValRef<Brig::BrigRound8_t,0,5>'
                                                  },
                                                  {
                                                    'wname' => 'ftz',
                                                    'phantomof' => $structs->{'BrigAluModifier'}{'fields'}[0],
                                                    'name' => 'ftz',
                                                    'wtype' => 'BitValRef<5>',
                                                    'type' => 'bool',
                                                    'acc' => 'bitValRef<5>'
                                                  }
                                                ],
                                    'isroot' => 'true',
                                    'align' => undef,
                                    'enum' => 'BRIG_KIND_ALU_MODIFIER',
                                    'name' => 'BrigAluModifier',
                                    'standalone' => 'true'
                                  },
             'BrigOperand' => {
                                'align' => undef,
                                'name' => 'BrigOperand',
                                'children' => {
                                                'BrigOperandAddress' => {
                                                                          'parent' => 'BrigOperand',
                                                                          'wname' => 'OperandAddress',
                                                                          'fields' => [
                                                                                        {
                                                                                          'wname' => 'byteCount',
                                                                                          'name' => 'byteCount',
                                                                                          'wtype' => 'ValRef<uint16_t>',
                                                                                          'type' => 'uint16_t',
                                                                                          'acc' => 'valRef'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'kind',
                                                                                          'enum' => 'BrigKinds',
                                                                                          'name' => 'kind',
                                                                                          'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                          'type' => 'BrigKinds16_t',
                                                                                          'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'symbol',
                                                                                          'name' => 'symbol',
                                                                                          'wtype' => 'ItemRef<DirectiveVariable>',
                                                                                          'type' => 'BrigCodeOffset32_t',
                                                                                          'defValue' => '0',
                                                                                          'acc' => 'itemRef<DirectiveVariable>'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'reg',
                                                                                          'name' => 'reg',
                                                                                          'wtype' => 'ItemRef<OperandReg>',
                                                                                          'type' => 'BrigOperandOffset32_t',
                                                                                          'defValue' => '0',
                                                                                          'acc' => 'itemRef<OperandReg>'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'offset',
                                                                                          'name' => 'offset',
                                                                                          'wtype' => 'UInt64',
                                                                                          'type' => 'BrigUInt64',
                                                                                          'acc' => 'subItem<UInt64>'
                                                                                        }
                                                                                      ],
                                                                          'align' => undef,
                                                                          'enum' => 'BRIG_KIND_OPERAND_ADDRESS',
                                                                          'name' => 'BrigOperandAddress'
                                                                        },
                                                'BrigOperandImageProperties' => {
                                                                                  'parent' => 'BrigOperand',
                                                                                  'wname' => 'OperandImageProperties',
                                                                                  'fields' => [
                                                                                                {
                                                                                                  'wname' => 'byteCount',
                                                                                                  'name' => 'byteCount',
                                                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                                                  'type' => 'uint16_t',
                                                                                                  'acc' => 'valRef'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'kind',
                                                                                                  'enum' => 'BrigKinds',
                                                                                                  'name' => 'kind',
                                                                                                  'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                                  'type' => 'BrigKinds16_t',
                                                                                                  'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'width',
                                                                                                  'name' => 'width',
                                                                                                  'wtype' => 'UInt64',
                                                                                                  'type' => 'BrigUInt64',
                                                                                                  'acc' => 'subItem<UInt64>'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'height',
                                                                                                  'name' => 'height',
                                                                                                  'wtype' => 'UInt64',
                                                                                                  'type' => 'BrigUInt64',
                                                                                                  'acc' => 'subItem<UInt64>'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'depth',
                                                                                                  'name' => 'depth',
                                                                                                  'wtype' => 'UInt64',
                                                                                                  'type' => 'BrigUInt64',
                                                                                                  'acc' => 'subItem<UInt64>'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'array',
                                                                                                  'name' => 'array',
                                                                                                  'wtype' => 'UInt64',
                                                                                                  'type' => 'BrigUInt64',
                                                                                                  'acc' => 'subItem<UInt64>'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'geometry',
                                                                                                  'enum' => 'BrigImageGeometry',
                                                                                                  'name' => 'geometry',
                                                                                                  'wtype' => 'EnumValRef<Brig::BrigImageGeometry,uint8_t>',
                                                                                                  'type' => 'BrigImageGeometry8_t',
                                                                                                  'defValue' => 'Brig::BRIG_GEOMETRY_UNKNOWN',
                                                                                                  'acc' => 'enumValRef<Brig::BrigImageGeometry,uint8_t>'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'channelOrder',
                                                                                                  'enum' => 'BrigImageChannelOrder',
                                                                                                  'name' => 'channelOrder',
                                                                                                  'wtype' => 'EnumValRef<Brig::BrigImageChannelOrder,uint8_t>',
                                                                                                  'type' => 'BrigImageChannelOrder8_t',
                                                                                                  'defValue' => 'Brig::BRIG_CHANNEL_ORDER_UNKNOWN',
                                                                                                  'acc' => 'enumValRef<Brig::BrigImageChannelOrder,uint8_t>'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'channelType',
                                                                                                  'enum' => 'BrigImageChannelType',
                                                                                                  'name' => 'channelType',
                                                                                                  'wtype' => 'EnumValRef<Brig::BrigImageChannelType,uint8_t>',
                                                                                                  'type' => 'BrigImageChannelType8_t',
                                                                                                  'defValue' => 'Brig::BRIG_CHANNEL_TYPE_UNKNOWN',
                                                                                                  'acc' => 'enumValRef<Brig::BrigImageChannelType,uint8_t>'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'reserved',
                                                                                                  'skip' => 1,
                                                                                                  'name' => 'reserved',
                                                                                                  'wtype' => 'ValRef<uint8_t>',
                                                                                                  'type' => 'uint8_t',
                                                                                                  'defValue' => '0',
                                                                                                  'acc' => 'valRef'
                                                                                                }
                                                                                              ],
                                                                                  'align' => undef,
                                                                                  'enum' => 'BRIG_KIND_OPERAND_IMAGE_PROPERTIES',
                                                                                  'name' => 'BrigOperandImageProperties'
                                                                                },
                                                'BrigOperandSamplerProperties' => {
                                                                                    'parent' => 'BrigOperand',
                                                                                    'wname' => 'OperandSamplerProperties',
                                                                                    'fields' => [
                                                                                                  {
                                                                                                    'wname' => 'byteCount',
                                                                                                    'name' => 'byteCount',
                                                                                                    'wtype' => 'ValRef<uint16_t>',
                                                                                                    'type' => 'uint16_t',
                                                                                                    'acc' => 'valRef'
                                                                                                  },
                                                                                                  {
                                                                                                    'wname' => 'kind',
                                                                                                    'enum' => 'BrigKinds',
                                                                                                    'name' => 'kind',
                                                                                                    'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                                    'type' => 'BrigKinds16_t',
                                                                                                    'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                                  },
                                                                                                  {
                                                                                                    'wname' => 'coord',
                                                                                                    'enum' => 'BrigSamplerCoordNormalization',
                                                                                                    'name' => 'coord',
                                                                                                    'wtype' => 'EnumValRef<Brig::BrigSamplerCoordNormalization,uint8_t>',
                                                                                                    'type' => 'BrigSamplerCoordNormalization8_t',
                                                                                                    'acc' => 'enumValRef<Brig::BrigSamplerCoordNormalization,uint8_t>'
                                                                                                  },
                                                                                                  {
                                                                                                    'wname' => 'filter',
                                                                                                    'enum' => 'BrigSamplerFilter',
                                                                                                    'name' => 'filter',
                                                                                                    'wtype' => 'EnumValRef<Brig::BrigSamplerFilter,uint8_t>',
                                                                                                    'type' => 'BrigSamplerFilter8_t',
                                                                                                    'acc' => 'enumValRef<Brig::BrigSamplerFilter,uint8_t>'
                                                                                                  },
                                                                                                  {
                                                                                                    'wname' => 'addressing',
                                                                                                    'enum' => 'BrigSamplerAddressing',
                                                                                                    'name' => 'addressing',
                                                                                                    'wtype' => 'EnumValRef<Brig::BrigSamplerAddressing,uint8_t>',
                                                                                                    'type' => 'BrigSamplerAddressing8_t',
                                                                                                    'defValue' => 'Brig::BRIG_ADDRESSING_CLAMP_TO_EDGE',
                                                                                                    'acc' => 'enumValRef<Brig::BrigSamplerAddressing,uint8_t>'
                                                                                                  },
                                                                                                  {
                                                                                                    'wname' => 'reserved',
                                                                                                    'skip' => 1,
                                                                                                    'name' => 'reserved',
                                                                                                    'wtype' => 'ValRef<uint8_t>',
                                                                                                    'type' => 'uint8_t',
                                                                                                    'defValue' => '0',
                                                                                                    'acc' => 'valRef'
                                                                                                  }
                                                                                                ],
                                                                                    'align' => undef,
                                                                                    'enum' => 'BRIG_KIND_OPERAND_SAMPLER_PROPERTIES',
                                                                                    'name' => 'BrigOperandSamplerProperties'
                                                                                  },
                                                'BrigOperandCodeList' => $structs->{'BrigOperandCodeList'},
                                                'BrigOperandData' => {
                                                                       'parent' => 'BrigOperand',
                                                                       'wname' => 'OperandData',
                                                                       'fields' => [
                                                                                     {
                                                                                       'wname' => 'byteCount',
                                                                                       'name' => 'byteCount',
                                                                                       'wtype' => 'ValRef<uint16_t>',
                                                                                       'type' => 'uint16_t',
                                                                                       'acc' => 'valRef'
                                                                                     },
                                                                                     {
                                                                                       'wname' => 'kind',
                                                                                       'enum' => 'BrigKinds',
                                                                                       'name' => 'kind',
                                                                                       'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                       'type' => 'BrigKinds16_t',
                                                                                       'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                     },
                                                                                     {
                                                                                       'wname' => 'data',
                                                                                       'name' => 'data',
                                                                                       'wtype' => 'StrRef',
                                                                                       'type' => 'BrigDataOffsetString32_t',
                                                                                       'defValue' => '0',
                                                                                       'acc' => 'strRef'
                                                                                     }
                                                                                   ],
                                                                       'align' => undef,
                                                                       'enum' => 'BRIG_KIND_OPERAND_DATA',
                                                                       'name' => 'BrigOperandData'
                                                                     },
                                                'BrigOperandOperandList' => $structs->{'BrigOperandOperandList'},
                                                'BrigOperandReg' => {
                                                                      'parent' => 'BrigOperand',
                                                                      'wname' => 'OperandReg',
                                                                      'fields' => [
                                                                                    {
                                                                                      'wname' => 'byteCount',
                                                                                      'name' => 'byteCount',
                                                                                      'wtype' => 'ValRef<uint16_t>',
                                                                                      'type' => 'uint16_t',
                                                                                      'acc' => 'valRef'
                                                                                    },
                                                                                    {
                                                                                      'wname' => 'kind',
                                                                                      'enum' => 'BrigKinds',
                                                                                      'name' => 'kind',
                                                                                      'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                      'type' => 'BrigKinds16_t',
                                                                                      'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                    },
                                                                                    {
                                                                                      'wname' => 'regKind',
                                                                                      'enum' => 'BrigRegisterKind',
                                                                                      'name' => 'regKind',
                                                                                      'wtype' => 'EnumValRef<Brig::BrigRegisterKind,uint16_t>',
                                                                                      'type' => 'BrigRegisterKind16_t',
                                                                                      'acc' => 'enumValRef<Brig::BrigRegisterKind,uint16_t>'
                                                                                    },
                                                                                    {
                                                                                      'wname' => 'regNum',
                                                                                      'name' => 'regNum',
                                                                                      'wtype' => 'ValRef<uint16_t>',
                                                                                      'type' => 'uint16_t',
                                                                                      'acc' => 'valRef'
                                                                                    }
                                                                                  ],
                                                                      'align' => undef,
                                                                      'enum' => 'BRIG_KIND_OPERAND_REG',
                                                                      'name' => 'BrigOperandReg'
                                                                    },
                                                'BrigOperandString' => {
                                                                         'parent' => 'BrigOperand',
                                                                         'wname' => 'OperandString',
                                                                         'fields' => [
                                                                                       {
                                                                                         'wname' => 'byteCount',
                                                                                         'name' => 'byteCount',
                                                                                         'wtype' => 'ValRef<uint16_t>',
                                                                                         'type' => 'uint16_t',
                                                                                         'acc' => 'valRef'
                                                                                       },
                                                                                       {
                                                                                         'wname' => 'kind',
                                                                                         'enum' => 'BrigKinds',
                                                                                         'name' => 'kind',
                                                                                         'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                         'type' => 'BrigKinds16_t',
                                                                                         'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                       },
                                                                                       {
                                                                                         'wname' => 'string',
                                                                                         'name' => 'string',
                                                                                         'wtype' => 'StrRef',
                                                                                         'type' => 'BrigDataOffsetString32_t',
                                                                                         'defValue' => '0',
                                                                                         'acc' => 'strRef'
                                                                                       }
                                                                                     ],
                                                                         'align' => undef,
                                                                         'enum' => 'BRIG_KIND_OPERAND_STRING',
                                                                         'name' => 'BrigOperandString'
                                                                       },
                                                'BrigOperandWavesize' => {
                                                                           'parent' => 'BrigOperand',
                                                                           'wname' => 'OperandWavesize',
                                                                           'fields' => [
                                                                                         {
                                                                                           'wname' => 'byteCount',
                                                                                           'name' => 'byteCount',
                                                                                           'wtype' => 'ValRef<uint16_t>',
                                                                                           'type' => 'uint16_t',
                                                                                           'acc' => 'valRef'
                                                                                         },
                                                                                         {
                                                                                           'wname' => 'kind',
                                                                                           'enum' => 'BrigKinds',
                                                                                           'name' => 'kind',
                                                                                           'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                           'type' => 'BrigKinds16_t',
                                                                                           'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                         }
                                                                                       ],
                                                                           'align' => undef,
                                                                           'enum' => 'BRIG_KIND_OPERAND_WAVESIZE',
                                                                           'name' => 'BrigOperandWavesize'
                                                                         },
                                                'BrigOperandCodeRef' => {
                                                                          'parent' => 'BrigOperand',
                                                                          'wname' => 'OperandCodeRef',
                                                                          'fields' => [
                                                                                        {
                                                                                          'wname' => 'byteCount',
                                                                                          'name' => 'byteCount',
                                                                                          'wtype' => 'ValRef<uint16_t>',
                                                                                          'type' => 'uint16_t',
                                                                                          'acc' => 'valRef'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'kind',
                                                                                          'enum' => 'BrigKinds',
                                                                                          'name' => 'kind',
                                                                                          'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                          'type' => 'BrigKinds16_t',
                                                                                          'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'ref',
                                                                                          'name' => 'ref',
                                                                                          'wtype' => 'ItemRef<Code>',
                                                                                          'type' => 'BrigCodeOffset32_t',
                                                                                          'defValue' => '0',
                                                                                          'acc' => 'itemRef<Code>'
                                                                                        }
                                                                                      ],
                                                                          'align' => undef,
                                                                          'enum' => 'BRIG_KIND_OPERAND_CODE_REF',
                                                                          'name' => 'BrigOperandCodeRef'
                                                                        }
                                              },
                                'section' => 'BRIG_SECTION_INDEX_OPERAND',
                                'generic' => 'true',
                                'wname' => 'Operand',
                                'isroot' => 'true',
                                'fields' => [
                                              {
                                                'wname' => 'byteCount',
                                                'name' => 'byteCount',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                'type' => 'BrigKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                              }
                                            ],
                                'enum' => 'BRIG_KIND_OPERAND'
                              },
             'BrigDirectiveControl' => {
                                         'parent' => 'BrigDirective',
                                         'wname' => 'DirectiveControl',
                                         'fields' => [
                                                       {
                                                         'wname' => 'byteCount',
                                                         'name' => 'byteCount',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'kind',
                                                         'enum' => 'BrigKinds',
                                                         'name' => 'kind',
                                                         'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                         'type' => 'BrigKinds16_t',
                                                         'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                       },
                                                       {
                                                         'wname' => 'control',
                                                         'enum' => 'BrigControlDirective',
                                                         'name' => 'control',
                                                         'wtype' => 'EnumValRef<Brig::BrigControlDirective,uint16_t>',
                                                         'type' => 'BrigControlDirective16_t',
                                                         'acc' => 'enumValRef<Brig::BrigControlDirective,uint16_t>'
                                                       },
                                                       {
                                                         'wname' => 'reserved',
                                                         'skip' => 1,
                                                         'name' => 'reserved',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'defValue' => '0',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'operands',
                                                         'name' => 'operands',
                                                         'wtype' => 'ListRef<Operand>',
                                                         'type' => 'BrigDataOffsetOperandList32_t',
                                                         'defValue' => '0',
                                                         'acc' => 'listRef<Operand>'
                                                       }
                                                     ],
                                         'align' => undef,
                                         'enum' => 'BRIG_KIND_DIRECTIVE_CONTROL',
                                         'name' => 'BrigDirectiveControl'
                                       },
             'BrigOperandString' => $structs->{'BrigOperand'}{'children'}{'BrigOperandString'},
             'BrigOperandImageProperties' => $structs->{'BrigOperand'}{'children'}{'BrigOperandImageProperties'},
             'BrigDirectiveSignature' => {
                                           'wname' => 'DirectiveSignature',
                                           'parent' => 'BrigDirectiveExecutable',
                                           'fields' => [
                                                         {
                                                           'wname' => 'byteCount',
                                                           'name' => 'byteCount',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'kind',
                                                           'enum' => 'BrigKinds',
                                                           'name' => 'kind',
                                                           'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                           'type' => 'BrigKinds16_t',
                                                           'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                         },
                                                         {
                                                           'wname' => 'name',
                                                           'name' => 'name',
                                                           'wtype' => 'StrRef',
                                                           'type' => 'BrigDataOffsetString32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'strRef'
                                                         },
                                                         {
                                                           'wname' => 'outArgCount',
                                                           'name' => 'outArgCount',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'inArgCount',
                                                           'name' => 'inArgCount',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'firstInArg',
                                                           'name' => 'firstInArg',
                                                           'wtype' => 'ItemRef<Code>',
                                                           'type' => 'BrigCodeOffset32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<Code>'
                                                         },
                                                         {
                                                           'wname' => 'firstCodeBlockEntry',
                                                           'name' => 'firstCodeBlockEntry',
                                                           'wtype' => 'ItemRef<Code>',
                                                           'type' => 'BrigCodeOffset32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<Code>'
                                                         },
                                                         {
                                                           'wname' => 'nextModuleEntry',
                                                           'name' => 'nextModuleEntry',
                                                           'wtype' => 'ItemRef<Code>',
                                                           'type' => 'BrigCodeOffset32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<Code>'
                                                         },
                                                         {
                                                           'wname' => 'codeBlockEntryCount',
                                                           'name' => 'codeBlockEntryCount',
                                                           'wtype' => 'ValRef<uint32_t>',
                                                           'type' => 'uint32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'modifier',
                                                           'name' => 'modifier',
                                                           'wtype' => 'ExecutableModifier',
                                                           'type' => 'BrigExecutableModifier',
                                                           'acc' => 'subItem<ExecutableModifier>'
                                                         },
                                                         {
                                                           'wname' => 'linkage',
                                                           'enum' => 'BrigLinkage',
                                                           'name' => 'linkage',
                                                           'wtype' => 'EnumValRef<Brig::BrigLinkage,uint8_t>',
                                                           'type' => 'BrigLinkage8_t',
                                                           'defValue' => 'Brig::BRIG_LINKAGE_NONE',
                                                           'acc' => 'enumValRef<Brig::BrigLinkage,uint8_t>'
                                                         },
                                                         {
                                                           'wname' => 'reserved',
                                                           'skip' => 1,
                                                           'name' => 'reserved',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         }
                                                       ],
                                           'align' => undef,
                                           'enum' => 'BRIG_KIND_DIRECTIVE_SIGNATURE',
                                           'name' => 'BrigDirectiveSignature'
                                         },
             'BrigDirectiveVersion' => {
                                         'parent' => 'BrigDirective',
                                         'wname' => 'DirectiveVersion',
                                         'fields' => [
                                                       {
                                                         'wname' => 'byteCount',
                                                         'name' => 'byteCount',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'kind',
                                                         'enum' => 'BrigKinds',
                                                         'name' => 'kind',
                                                         'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                         'type' => 'BrigKinds16_t',
                                                         'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                       },
                                                       {
                                                         'wname' => 'hsailMajor',
                                                         'enum' => 'BrigVersion',
                                                         'name' => 'hsailMajor',
                                                         'wtype' => 'ValRef<uint32_t>',
                                                         'type' => 'BrigVersion32_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'hsailMinor',
                                                         'enum' => 'BrigVersion',
                                                         'name' => 'hsailMinor',
                                                         'wtype' => 'ValRef<uint32_t>',
                                                         'type' => 'BrigVersion32_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'brigMajor',
                                                         'enum' => 'BrigVersion',
                                                         'name' => 'brigMajor',
                                                         'wtype' => 'ValRef<uint32_t>',
                                                         'type' => 'BrigVersion32_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'brigMinor',
                                                         'enum' => 'BrigVersion',
                                                         'name' => 'brigMinor',
                                                         'wtype' => 'ValRef<uint32_t>',
                                                         'type' => 'BrigVersion32_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'profile',
                                                         'enum' => 'BrigProfile',
                                                         'name' => 'profile',
                                                         'wtype' => 'EnumValRef<Brig::BrigProfile,uint8_t>',
                                                         'type' => 'BrigProfile8_t',
                                                         'defValue' => 'Brig::BRIG_PROFILE_FULL',
                                                         'acc' => 'enumValRef<Brig::BrigProfile,uint8_t>'
                                                       },
                                                       {
                                                         'wname' => 'machineModel',
                                                         'enum' => 'BrigMachineModel',
                                                         'name' => 'machineModel',
                                                         'wtype' => 'EnumValRef<Brig::BrigMachineModel,uint8_t>',
                                                         'type' => 'BrigMachineModel8_t',
                                                         'defValue' => 'Brig::BRIG_MACHINE_LARGE',
                                                         'acc' => 'enumValRef<Brig::BrigMachineModel,uint8_t>'
                                                       },
                                                       {
                                                         'wname' => 'reserved',
                                                         'skip' => 1,
                                                         'name' => 'reserved',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'defValue' => '0',
                                                         'acc' => 'valRef'
                                                       }
                                                     ],
                                         'align' => undef,
                                         'enum' => 'BRIG_KIND_DIRECTIVE_VERSION',
                                         'name' => 'BrigDirectiveVersion'
                                       },
             'BrigInstAtomic' => {
                                   'parent' => 'BrigInst',
                                   'wname' => 'InstAtomic',
                                   'fields' => [
                                                 {
                                                   'wname' => 'byteCount',
                                                   'name' => 'byteCount',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'uint16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'kind',
                                                   'enum' => 'BrigKinds',
                                                   'name' => 'kind',
                                                   'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                   'type' => 'BrigKinds16_t',
                                                   'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                 },
                                                 {
                                                   'wname' => 'opcode',
                                                   'enum' => 'BrigOpcode',
                                                   'name' => 'opcode',
                                                   'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                   'type' => 'BrigOpcode16_t',
                                                   'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                 },
                                                 {
                                                   'wname' => 'type',
                                                   'name' => 'type',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'BrigType16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'operands',
                                                   'name' => 'operands',
                                                   'wtype' => 'ListRef<Operand>',
                                                   'type' => 'BrigDataOffsetOperandList32_t',
                                                   'defValue' => '0',
                                                   'acc' => 'listRef<Operand>'
                                                 },
                                                 {
                                                   'wname' => 'segment',
                                                   'enum' => 'BrigSegment',
                                                   'name' => 'segment',
                                                   'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                   'type' => 'BrigSegment8_t',
                                                   'defValue' => 'Brig::BRIG_SEGMENT_NONE',
                                                   'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                                 },
                                                 {
                                                   'wname' => 'memoryOrder',
                                                   'enum' => 'BrigMemoryOrder',
                                                   'name' => 'memoryOrder',
                                                   'wtype' => 'EnumValRef<Brig::BrigMemoryOrder,uint8_t>',
                                                   'type' => 'BrigMemoryOrder8_t',
                                                   'defValue' => 'Brig::BRIG_MEMORY_ORDER_RELAXED',
                                                   'acc' => 'enumValRef<Brig::BrigMemoryOrder,uint8_t>'
                                                 },
                                                 {
                                                   'wname' => 'memoryScope',
                                                   'enum' => 'BrigMemoryScope',
                                                   'name' => 'memoryScope',
                                                   'wtype' => 'EnumValRef<Brig::BrigMemoryScope,uint8_t>',
                                                   'type' => 'BrigMemoryScope8_t',
                                                   'defValue' => 'Brig::BRIG_MEMORY_SCOPE_SYSTEM',
                                                   'acc' => 'enumValRef<Brig::BrigMemoryScope,uint8_t>'
                                                 },
                                                 {
                                                   'wname' => 'atomicOperation',
                                                   'enum' => 'BrigAtomicOperation',
                                                   'name' => 'atomicOperation',
                                                   'wtype' => 'EnumValRef<Brig::BrigAtomicOperation,uint8_t>',
                                                   'type' => 'BrigAtomicOperation8_t',
                                                   'acc' => 'enumValRef<Brig::BrigAtomicOperation,uint8_t>'
                                                 },
                                                 {
                                                   'wname' => 'equivClass',
                                                   'name' => 'equivClass',
                                                   'wtype' => 'ValRef<uint8_t>',
                                                   'type' => 'uint8_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'name' => 'reserved',
                                                   'defValue' => '0',
                                                   'acc' => 'valRef',
                                                   'size' => '3',
                                                   'wname' => 'reserved',
                                                   'skip' => 1,
                                                   'type' => 'uint8_t',
                                                   'wtype' => 'ValRef<uint8_t>'
                                                 }
                                               ],
                                   'align' => undef,
                                   'enum' => 'BRIG_KIND_INST_ATOMIC',
                                   'name' => 'BrigInstAtomic'
                                 },
             'BrigDirectiveNone' => {
                                      'parent' => 'BrigDirective',
                                      'wname' => 'DirectiveNone',
                                      'fields' => [
                                                    {
                                                      'wname' => 'byteCount',
                                                      'name' => 'byteCount',
                                                      'wtype' => 'ValRef<uint16_t>',
                                                      'type' => 'uint16_t',
                                                      'acc' => 'valRef'
                                                    },
                                                    {
                                                      'wname' => 'kind',
                                                      'enum' => 'BrigKinds',
                                                      'name' => 'kind',
                                                      'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                      'type' => 'BrigKinds16_t',
                                                      'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                    }
                                                  ],
                                      'align' => undef,
                                      'enum' => 'BRIG_KIND_NONE',
                                      'name' => 'BrigDirectiveNone'
                                    },
             'BrigMemoryModifier' => {
                                       'wname' => 'MemoryModifier',
                                       'fields' => [
                                                     {
                                                       'wname' => 'allBits',
                                                       'name' => 'allBits',
                                                       'wtype' => 'ValRef<uint8_t>',
                                                       'type' => 'BrigMemoryModifier8_t',
                                                       'defValue' => '0',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'isConst',
                                                       'phantomof' => $structs->{'BrigMemoryModifier'}{'fields'}[0],
                                                       'name' => 'isConst',
                                                       'wtype' => 'BitValRef<0>',
                                                       'type' => 'bool',
                                                       'acc' => 'bitValRef<0>'
                                                     }
                                                   ],
                                       'isroot' => 'true',
                                       'align' => undef,
                                       'enum' => 'BRIG_KIND_MEMORY_MODIFIER',
                                       'name' => 'BrigMemoryModifier',
                                       'standalone' => 'true'
                                     },
             'BrigInstSourceType' => {
                                       'parent' => 'BrigInst',
                                       'wname' => 'InstSourceType',
                                       'fields' => [
                                                     {
                                                       'wname' => 'byteCount',
                                                       'name' => 'byteCount',
                                                       'wtype' => 'ValRef<uint16_t>',
                                                       'type' => 'uint16_t',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'kind',
                                                       'enum' => 'BrigKinds',
                                                       'name' => 'kind',
                                                       'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                       'type' => 'BrigKinds16_t',
                                                       'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                     },
                                                     {
                                                       'wname' => 'opcode',
                                                       'enum' => 'BrigOpcode',
                                                       'name' => 'opcode',
                                                       'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                       'type' => 'BrigOpcode16_t',
                                                       'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                     },
                                                     {
                                                       'wname' => 'type',
                                                       'name' => 'type',
                                                       'wtype' => 'ValRef<uint16_t>',
                                                       'type' => 'BrigType16_t',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'operands',
                                                       'name' => 'operands',
                                                       'wtype' => 'ListRef<Operand>',
                                                       'type' => 'BrigDataOffsetOperandList32_t',
                                                       'defValue' => '0',
                                                       'acc' => 'listRef<Operand>'
                                                     },
                                                     {
                                                       'wname' => 'sourceType',
                                                       'name' => 'sourceType',
                                                       'wtype' => 'ValRef<uint16_t>',
                                                       'type' => 'BrigType16_t',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'reserved',
                                                       'skip' => 1,
                                                       'name' => 'reserved',
                                                       'wtype' => 'ValRef<uint16_t>',
                                                       'type' => 'uint16_t',
                                                       'defValue' => '0',
                                                       'acc' => 'valRef'
                                                     }
                                                   ],
                                       'align' => undef,
                                       'enum' => 'BRIG_KIND_INST_SOURCE_TYPE',
                                       'name' => 'BrigInstSourceType'
                                     },
             'BrigInstImage' => {
                                  'parent' => 'BrigInst',
                                  'wname' => 'InstImage',
                                  'fields' => [
                                                {
                                                  'wname' => 'byteCount',
                                                  'name' => 'byteCount',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'uint16_t',
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'kind',
                                                  'enum' => 'BrigKinds',
                                                  'name' => 'kind',
                                                  'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                  'type' => 'BrigKinds16_t',
                                                  'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                },
                                                {
                                                  'wname' => 'opcode',
                                                  'enum' => 'BrigOpcode',
                                                  'name' => 'opcode',
                                                  'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                  'type' => 'BrigOpcode16_t',
                                                  'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                },
                                                {
                                                  'wname' => 'type',
                                                  'name' => 'type',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'BrigType16_t',
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'operands',
                                                  'name' => 'operands',
                                                  'wtype' => 'ListRef<Operand>',
                                                  'type' => 'BrigDataOffsetOperandList32_t',
                                                  'defValue' => '0',
                                                  'acc' => 'listRef<Operand>'
                                                },
                                                {
                                                  'wname' => 'imageType',
                                                  'name' => 'imageType',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'BrigType16_t',
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'coordType',
                                                  'name' => 'coordType',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'BrigType16_t',
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'geometry',
                                                  'enum' => 'BrigImageGeometry',
                                                  'name' => 'geometry',
                                                  'wtype' => 'EnumValRef<Brig::BrigImageGeometry,uint8_t>',
                                                  'type' => 'BrigImageGeometry8_t',
                                                  'defValue' => 'Brig::BRIG_GEOMETRY_UNKNOWN',
                                                  'acc' => 'enumValRef<Brig::BrigImageGeometry,uint8_t>'
                                                },
                                                {
                                                  'wname' => 'equivClass',
                                                  'name' => 'equivClass',
                                                  'wtype' => 'ValRef<uint8_t>',
                                                  'type' => 'uint8_t',
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'reserved',
                                                  'skip' => 1,
                                                  'name' => 'reserved',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'uint16_t',
                                                  'defValue' => '0',
                                                  'acc' => 'valRef'
                                                }
                                              ],
                                  'align' => undef,
                                  'enum' => 'BRIG_KIND_INST_IMAGE',
                                  'name' => 'BrigInstImage'
                                },
             'BrigInstBr' => {
                               'parent' => 'BrigInst',
                               'wname' => 'InstBr',
                               'fields' => [
                                             {
                                               'wname' => 'byteCount',
                                               'name' => 'byteCount',
                                               'wtype' => 'ValRef<uint16_t>',
                                               'type' => 'uint16_t',
                                               'acc' => 'valRef'
                                             },
                                             {
                                               'wname' => 'kind',
                                               'enum' => 'BrigKinds',
                                               'name' => 'kind',
                                               'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                               'type' => 'BrigKinds16_t',
                                               'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                             },
                                             {
                                               'wname' => 'opcode',
                                               'enum' => 'BrigOpcode',
                                               'name' => 'opcode',
                                               'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                               'type' => 'BrigOpcode16_t',
                                               'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                             },
                                             {
                                               'wname' => 'type',
                                               'name' => 'type',
                                               'wtype' => 'ValRef<uint16_t>',
                                               'type' => 'BrigType16_t',
                                               'acc' => 'valRef'
                                             },
                                             {
                                               'wname' => 'operands',
                                               'name' => 'operands',
                                               'wtype' => 'ListRef<Operand>',
                                               'type' => 'BrigDataOffsetOperandList32_t',
                                               'defValue' => '0',
                                               'acc' => 'listRef<Operand>'
                                             },
                                             {
                                               'wname' => 'width',
                                               'enum' => 'BrigWidth',
                                               'name' => 'width',
                                               'wtype' => 'EnumValRef<Brig::BrigWidth,uint8_t>',
                                               'type' => 'BrigWidth8_t',
                                               'acc' => 'enumValRef<Brig::BrigWidth,uint8_t>'
                                             },
                                             {
                                               'name' => 'reserved',
                                               'defValue' => '0',
                                               'acc' => 'valRef',
                                               'size' => '3',
                                               'wname' => 'reserved',
                                               'skip' => 1,
                                               'type' => 'uint8_t',
                                               'wtype' => 'ValRef<uint8_t>'
                                             }
                                           ],
                               'align' => undef,
                               'enum' => 'BRIG_KIND_INST_BR',
                               'name' => 'BrigInstBr'
                             },
             'BrigInstSeg' => {
                                'parent' => 'BrigInst',
                                'wname' => 'InstSeg',
                                'fields' => [
                                              {
                                                'wname' => 'byteCount',
                                                'name' => 'byteCount',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                'type' => 'BrigKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                              },
                                              {
                                                'wname' => 'opcode',
                                                'enum' => 'BrigOpcode',
                                                'name' => 'opcode',
                                                'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                'type' => 'BrigOpcode16_t',
                                                'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                              },
                                              {
                                                'wname' => 'type',
                                                'name' => 'type',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'BrigType16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'operands',
                                                'name' => 'operands',
                                                'wtype' => 'ListRef<Operand>',
                                                'type' => 'BrigDataOffsetOperandList32_t',
                                                'defValue' => '0',
                                                'acc' => 'listRef<Operand>'
                                              },
                                              {
                                                'wname' => 'segment',
                                                'enum' => 'BrigSegment',
                                                'name' => 'segment',
                                                'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                'type' => 'BrigSegment8_t',
                                                'defValue' => 'Brig::BRIG_SEGMENT_NONE',
                                                'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                              },
                                              {
                                                'name' => 'reserved',
                                                'defValue' => '0',
                                                'acc' => 'valRef',
                                                'size' => '3',
                                                'wname' => 'reserved',
                                                'skip' => 1,
                                                'type' => 'uint8_t',
                                                'wtype' => 'ValRef<uint8_t>'
                                              }
                                            ],
                                'align' => undef,
                                'enum' => 'BRIG_KIND_INST_SEG',
                                'name' => 'BrigInstSeg'
                              },
             'BrigInstMem' => {
                                'parent' => 'BrigInst',
                                'wname' => 'InstMem',
                                'fields' => [
                                              {
                                                'wname' => 'byteCount',
                                                'name' => 'byteCount',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                'type' => 'BrigKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                              },
                                              {
                                                'wname' => 'opcode',
                                                'enum' => 'BrigOpcode',
                                                'name' => 'opcode',
                                                'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                'type' => 'BrigOpcode16_t',
                                                'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                              },
                                              {
                                                'wname' => 'type',
                                                'name' => 'type',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'BrigType16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'operands',
                                                'name' => 'operands',
                                                'wtype' => 'ListRef<Operand>',
                                                'type' => 'BrigDataOffsetOperandList32_t',
                                                'defValue' => '0',
                                                'acc' => 'listRef<Operand>'
                                              },
                                              {
                                                'wname' => 'segment',
                                                'enum' => 'BrigSegment',
                                                'name' => 'segment',
                                                'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                'type' => 'BrigSegment8_t',
                                                'defValue' => 'Brig::BRIG_SEGMENT_NONE',
                                                'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                              },
                                              {
                                                'wname' => 'align',
                                                'enum' => 'BrigAlignment',
                                                'name' => 'align',
                                                'wtype' => 'EnumValRef<Brig::BrigAlignment,uint8_t>',
                                                'type' => 'BrigAlignment8_t',
                                                'defValue' => 'Brig::BRIG_ALIGNMENT_NONE',
                                                'acc' => 'enumValRef<Brig::BrigAlignment,uint8_t>'
                                              },
                                              {
                                                'wname' => 'equivClass',
                                                'name' => 'equivClass',
                                                'wtype' => 'ValRef<uint8_t>',
                                                'type' => 'uint8_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'width',
                                                'enum' => 'BrigWidth',
                                                'name' => 'width',
                                                'wtype' => 'EnumValRef<Brig::BrigWidth,uint8_t>',
                                                'type' => 'BrigWidth8_t',
                                                'acc' => 'enumValRef<Brig::BrigWidth,uint8_t>'
                                              },
                                              {
                                                'wname' => 'modifier',
                                                'name' => 'modifier',
                                                'wtype' => 'MemoryModifier',
                                                'type' => 'BrigMemoryModifier',
                                                'acc' => 'subItem<MemoryModifier>'
                                              },
                                              {
                                                'name' => 'reserved',
                                                'defValue' => '0',
                                                'acc' => 'valRef',
                                                'size' => '3',
                                                'wname' => 'reserved',
                                                'skip' => 1,
                                                'type' => 'uint8_t',
                                                'wtype' => 'ValRef<uint8_t>'
                                              }
                                            ],
                                'align' => undef,
                                'enum' => 'BRIG_KIND_INST_MEM',
                                'name' => 'BrigInstMem'
                              },
             'BrigDirectiveKernel' => {
                                        'wname' => 'DirectiveKernel',
                                        'parent' => 'BrigDirectiveExecutable',
                                        'fields' => [
                                                      {
                                                        'wname' => 'byteCount',
                                                        'name' => 'byteCount',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'kind',
                                                        'enum' => 'BrigKinds',
                                                        'name' => 'kind',
                                                        'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                        'type' => 'BrigKinds16_t',
                                                        'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                      },
                                                      {
                                                        'wname' => 'name',
                                                        'name' => 'name',
                                                        'wtype' => 'StrRef',
                                                        'type' => 'BrigDataOffsetString32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'strRef'
                                                      },
                                                      {
                                                        'wname' => 'outArgCount',
                                                        'name' => 'outArgCount',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'defValue' => '0',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'inArgCount',
                                                        'name' => 'inArgCount',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'defValue' => '0',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'firstInArg',
                                                        'name' => 'firstInArg',
                                                        'wtype' => 'ItemRef<Code>',
                                                        'type' => 'BrigCodeOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<Code>'
                                                      },
                                                      {
                                                        'wname' => 'firstCodeBlockEntry',
                                                        'name' => 'firstCodeBlockEntry',
                                                        'wtype' => 'ItemRef<Code>',
                                                        'type' => 'BrigCodeOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<Code>'
                                                      },
                                                      {
                                                        'wname' => 'nextModuleEntry',
                                                        'name' => 'nextModuleEntry',
                                                        'wtype' => 'ItemRef<Code>',
                                                        'type' => 'BrigCodeOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<Code>'
                                                      },
                                                      {
                                                        'wname' => 'codeBlockEntryCount',
                                                        'name' => 'codeBlockEntryCount',
                                                        'wtype' => 'ValRef<uint32_t>',
                                                        'type' => 'uint32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'modifier',
                                                        'name' => 'modifier',
                                                        'wtype' => 'ExecutableModifier',
                                                        'type' => 'BrigExecutableModifier',
                                                        'acc' => 'subItem<ExecutableModifier>'
                                                      },
                                                      {
                                                        'wname' => 'linkage',
                                                        'enum' => 'BrigLinkage',
                                                        'name' => 'linkage',
                                                        'wtype' => 'EnumValRef<Brig::BrigLinkage,uint8_t>',
                                                        'type' => 'BrigLinkage8_t',
                                                        'defValue' => 'Brig::BRIG_LINKAGE_NONE',
                                                        'acc' => 'enumValRef<Brig::BrigLinkage,uint8_t>'
                                                      },
                                                      {
                                                        'wname' => 'reserved',
                                                        'skip' => 1,
                                                        'name' => 'reserved',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'defValue' => '0',
                                                        'acc' => 'valRef'
                                                      }
                                                    ],
                                        'align' => undef,
                                        'enum' => 'BRIG_KIND_DIRECTIVE_KERNEL',
                                        'name' => 'BrigDirectiveKernel'
                                      },
             'BrigInstCmp' => {
                                'parent' => 'BrigInst',
                                'wname' => 'InstCmp',
                                'fields' => [
                                              {
                                                'wname' => 'byteCount',
                                                'name' => 'byteCount',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                'type' => 'BrigKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                              },
                                              {
                                                'wname' => 'opcode',
                                                'enum' => 'BrigOpcode',
                                                'name' => 'opcode',
                                                'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                'type' => 'BrigOpcode16_t',
                                                'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                              },
                                              {
                                                'wname' => 'type',
                                                'name' => 'type',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'BrigType16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'operands',
                                                'name' => 'operands',
                                                'wtype' => 'ListRef<Operand>',
                                                'type' => 'BrigDataOffsetOperandList32_t',
                                                'defValue' => '0',
                                                'acc' => 'listRef<Operand>'
                                              },
                                              {
                                                'wname' => 'sourceType',
                                                'name' => 'sourceType',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'BrigType16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'modifier',
                                                'name' => 'modifier',
                                                'wtype' => 'AluModifier',
                                                'type' => 'BrigAluModifier',
                                                'acc' => 'subItem<AluModifier>'
                                              },
                                              {
                                                'wname' => 'compare',
                                                'enum' => 'BrigCompareOperation',
                                                'name' => 'compare',
                                                'wtype' => 'EnumValRef<Brig::BrigCompareOperation,uint8_t>',
                                                'type' => 'BrigCompareOperation8_t',
                                                'acc' => 'enumValRef<Brig::BrigCompareOperation,uint8_t>'
                                              },
                                              {
                                                'wname' => 'pack',
                                                'enum' => 'BrigPack',
                                                'name' => 'pack',
                                                'wtype' => 'EnumValRef<Brig::BrigPack,uint8_t>',
                                                'type' => 'BrigPack8_t',
                                                'defValue' => 'Brig::BRIG_PACK_NONE',
                                                'acc' => 'enumValRef<Brig::BrigPack,uint8_t>'
                                              },
                                              {
                                                'wname' => 'reserved',
                                                'skip' => 1,
                                                'name' => 'reserved',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'defValue' => '0',
                                                'acc' => 'valRef'
                                              }
                                            ],
                                'align' => undef,
                                'enum' => 'BRIG_KIND_INST_CMP',
                                'name' => 'BrigInstCmp'
                              },
             'BrigDirectiveIndirectFunction' => {
                                                  'wname' => 'DirectiveIndirectFunction',
                                                  'parent' => 'BrigDirectiveExecutable',
                                                  'fields' => [
                                                                {
                                                                  'wname' => 'byteCount',
                                                                  'name' => 'byteCount',
                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                  'type' => 'uint16_t',
                                                                  'acc' => 'valRef'
                                                                },
                                                                {
                                                                  'wname' => 'kind',
                                                                  'enum' => 'BrigKinds',
                                                                  'name' => 'kind',
                                                                  'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                  'type' => 'BrigKinds16_t',
                                                                  'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                },
                                                                {
                                                                  'wname' => 'name',
                                                                  'name' => 'name',
                                                                  'wtype' => 'StrRef',
                                                                  'type' => 'BrigDataOffsetString32_t',
                                                                  'defValue' => '0',
                                                                  'acc' => 'strRef'
                                                                },
                                                                {
                                                                  'wname' => 'outArgCount',
                                                                  'name' => 'outArgCount',
                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                  'type' => 'uint16_t',
                                                                  'defValue' => '0',
                                                                  'acc' => 'valRef'
                                                                },
                                                                {
                                                                  'wname' => 'inArgCount',
                                                                  'name' => 'inArgCount',
                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                  'type' => 'uint16_t',
                                                                  'defValue' => '0',
                                                                  'acc' => 'valRef'
                                                                },
                                                                {
                                                                  'wname' => 'firstInArg',
                                                                  'name' => 'firstInArg',
                                                                  'wtype' => 'ItemRef<Code>',
                                                                  'type' => 'BrigCodeOffset32_t',
                                                                  'defValue' => '0',
                                                                  'acc' => 'itemRef<Code>'
                                                                },
                                                                {
                                                                  'wname' => 'firstCodeBlockEntry',
                                                                  'name' => 'firstCodeBlockEntry',
                                                                  'wtype' => 'ItemRef<Code>',
                                                                  'type' => 'BrigCodeOffset32_t',
                                                                  'defValue' => '0',
                                                                  'acc' => 'itemRef<Code>'
                                                                },
                                                                {
                                                                  'wname' => 'nextModuleEntry',
                                                                  'name' => 'nextModuleEntry',
                                                                  'wtype' => 'ItemRef<Code>',
                                                                  'type' => 'BrigCodeOffset32_t',
                                                                  'defValue' => '0',
                                                                  'acc' => 'itemRef<Code>'
                                                                },
                                                                {
                                                                  'wname' => 'codeBlockEntryCount',
                                                                  'name' => 'codeBlockEntryCount',
                                                                  'wtype' => 'ValRef<uint32_t>',
                                                                  'type' => 'uint32_t',
                                                                  'defValue' => '0',
                                                                  'acc' => 'valRef'
                                                                },
                                                                {
                                                                  'wname' => 'modifier',
                                                                  'name' => 'modifier',
                                                                  'wtype' => 'ExecutableModifier',
                                                                  'type' => 'BrigExecutableModifier',
                                                                  'acc' => 'subItem<ExecutableModifier>'
                                                                },
                                                                {
                                                                  'wname' => 'linkage',
                                                                  'enum' => 'BrigLinkage',
                                                                  'name' => 'linkage',
                                                                  'wtype' => 'EnumValRef<Brig::BrigLinkage,uint8_t>',
                                                                  'type' => 'BrigLinkage8_t',
                                                                  'defValue' => 'Brig::BRIG_LINKAGE_NONE',
                                                                  'acc' => 'enumValRef<Brig::BrigLinkage,uint8_t>'
                                                                },
                                                                {
                                                                  'wname' => 'reserved',
                                                                  'skip' => 1,
                                                                  'name' => 'reserved',
                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                  'type' => 'uint16_t',
                                                                  'defValue' => '0',
                                                                  'acc' => 'valRef'
                                                                }
                                                              ],
                                                  'align' => undef,
                                                  'enum' => 'BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION',
                                                  'name' => 'BrigDirectiveIndirectFunction'
                                                },
             'BrigDirectiveExecutable' => {
                                            'parent' => 'BrigDirective',
                                            'align' => undef,
                                            'name' => 'BrigDirectiveExecutable',
                                            'children' => {
                                                            'BrigDirectiveKernel' => $structs->{'BrigDirectiveKernel'},
                                                            'BrigDirectiveSignature' => $structs->{'BrigDirectiveSignature'},
                                                            'BrigDirectiveIndirectFunction' => $structs->{'BrigDirectiveIndirectFunction'},
                                                            'BrigDirectiveFunction' => {
                                                                                         'wname' => 'DirectiveFunction',
                                                                                         'parent' => 'BrigDirectiveExecutable',
                                                                                         'fields' => [
                                                                                                       {
                                                                                                         'wname' => 'byteCount',
                                                                                                         'name' => 'byteCount',
                                                                                                         'wtype' => 'ValRef<uint16_t>',
                                                                                                         'type' => 'uint16_t',
                                                                                                         'acc' => 'valRef'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'kind',
                                                                                                         'enum' => 'BrigKinds',
                                                                                                         'name' => 'kind',
                                                                                                         'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                                         'type' => 'BrigKinds16_t',
                                                                                                         'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'name',
                                                                                                         'name' => 'name',
                                                                                                         'wtype' => 'StrRef',
                                                                                                         'type' => 'BrigDataOffsetString32_t',
                                                                                                         'defValue' => '0',
                                                                                                         'acc' => 'strRef'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'outArgCount',
                                                                                                         'name' => 'outArgCount',
                                                                                                         'wtype' => 'ValRef<uint16_t>',
                                                                                                         'type' => 'uint16_t',
                                                                                                         'defValue' => '0',
                                                                                                         'acc' => 'valRef'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'inArgCount',
                                                                                                         'name' => 'inArgCount',
                                                                                                         'wtype' => 'ValRef<uint16_t>',
                                                                                                         'type' => 'uint16_t',
                                                                                                         'defValue' => '0',
                                                                                                         'acc' => 'valRef'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'firstInArg',
                                                                                                         'name' => 'firstInArg',
                                                                                                         'wtype' => 'ItemRef<Code>',
                                                                                                         'type' => 'BrigCodeOffset32_t',
                                                                                                         'defValue' => '0',
                                                                                                         'acc' => 'itemRef<Code>'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'firstCodeBlockEntry',
                                                                                                         'name' => 'firstCodeBlockEntry',
                                                                                                         'wtype' => 'ItemRef<Code>',
                                                                                                         'type' => 'BrigCodeOffset32_t',
                                                                                                         'defValue' => '0',
                                                                                                         'acc' => 'itemRef<Code>'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'nextModuleEntry',
                                                                                                         'name' => 'nextModuleEntry',
                                                                                                         'wtype' => 'ItemRef<Code>',
                                                                                                         'type' => 'BrigCodeOffset32_t',
                                                                                                         'defValue' => '0',
                                                                                                         'acc' => 'itemRef<Code>'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'codeBlockEntryCount',
                                                                                                         'name' => 'codeBlockEntryCount',
                                                                                                         'wtype' => 'ValRef<uint32_t>',
                                                                                                         'type' => 'uint32_t',
                                                                                                         'defValue' => '0',
                                                                                                         'acc' => 'valRef'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'modifier',
                                                                                                         'name' => 'modifier',
                                                                                                         'wtype' => 'ExecutableModifier',
                                                                                                         'type' => 'BrigExecutableModifier',
                                                                                                         'acc' => 'subItem<ExecutableModifier>'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'linkage',
                                                                                                         'enum' => 'BrigLinkage',
                                                                                                         'name' => 'linkage',
                                                                                                         'wtype' => 'EnumValRef<Brig::BrigLinkage,uint8_t>',
                                                                                                         'type' => 'BrigLinkage8_t',
                                                                                                         'defValue' => 'Brig::BRIG_LINKAGE_NONE',
                                                                                                         'acc' => 'enumValRef<Brig::BrigLinkage,uint8_t>'
                                                                                                       },
                                                                                                       {
                                                                                                         'wname' => 'reserved',
                                                                                                         'skip' => 1,
                                                                                                         'name' => 'reserved',
                                                                                                         'wtype' => 'ValRef<uint16_t>',
                                                                                                         'type' => 'uint16_t',
                                                                                                         'defValue' => '0',
                                                                                                         'acc' => 'valRef'
                                                                                                       }
                                                                                                     ],
                                                                                         'align' => undef,
                                                                                         'enum' => 'BRIG_KIND_DIRECTIVE_FUNCTION',
                                                                                         'name' => 'BrigDirectiveFunction'
                                                                                       }
                                                          },
                                            'generic' => 'true',
                                            'wname' => 'DirectiveExecutable',
                                            'fields' => [
                                                          {
                                                            'wname' => 'byteCount',
                                                            'name' => 'byteCount',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'kind',
                                                            'enum' => 'BrigKinds',
                                                            'name' => 'kind',
                                                            'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                            'type' => 'BrigKinds16_t',
                                                            'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                          },
                                                          {
                                                            'wname' => 'name',
                                                            'name' => 'name',
                                                            'wtype' => 'StrRef',
                                                            'type' => 'BrigDataOffsetString32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'strRef'
                                                          },
                                                          {
                                                            'wname' => 'outArgCount',
                                                            'name' => 'outArgCount',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'defValue' => '0',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'inArgCount',
                                                            'name' => 'inArgCount',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'defValue' => '0',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'firstInArg',
                                                            'name' => 'firstInArg',
                                                            'wtype' => 'ItemRef<Code>',
                                                            'type' => 'BrigCodeOffset32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<Code>'
                                                          },
                                                          {
                                                            'wname' => 'firstCodeBlockEntry',
                                                            'name' => 'firstCodeBlockEntry',
                                                            'wtype' => 'ItemRef<Code>',
                                                            'type' => 'BrigCodeOffset32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<Code>'
                                                          },
                                                          {
                                                            'wname' => 'nextModuleEntry',
                                                            'name' => 'nextModuleEntry',
                                                            'wtype' => 'ItemRef<Code>',
                                                            'type' => 'BrigCodeOffset32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<Code>'
                                                          },
                                                          {
                                                            'wname' => 'codeBlockEntryCount',
                                                            'name' => 'codeBlockEntryCount',
                                                            'wtype' => 'ValRef<uint32_t>',
                                                            'type' => 'uint32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'modifier',
                                                            'name' => 'modifier',
                                                            'wtype' => 'ExecutableModifier',
                                                            'type' => 'BrigExecutableModifier',
                                                            'acc' => 'subItem<ExecutableModifier>'
                                                          },
                                                          {
                                                            'wname' => 'linkage',
                                                            'enum' => 'BrigLinkage',
                                                            'name' => 'linkage',
                                                            'wtype' => 'EnumValRef<Brig::BrigLinkage,uint8_t>',
                                                            'type' => 'BrigLinkage8_t',
                                                            'defValue' => 'Brig::BRIG_LINKAGE_NONE',
                                                            'acc' => 'enumValRef<Brig::BrigLinkage,uint8_t>'
                                                          },
                                                          {
                                                            'wname' => 'reserved',
                                                            'skip' => 1,
                                                            'name' => 'reserved',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'defValue' => '0',
                                                            'acc' => 'valRef'
                                                          }
                                                        ],
                                            'enum' => 'BRIG_KIND_DIRECTIVE_EXECUTABLE'
                                          },
             'BrigOperandWavesize' => $structs->{'BrigOperand'}{'children'}{'BrigOperandWavesize'},
             'BrigData' => {
                             'fields' => [
                                           {
                                             'name' => 'byteCount',
                                             'type' => 'uint32_t'
                                           },
                                           {
                                             'name' => 'bytes',
                                             'type' => 'uint8_t',
                                             'size' => '1'
                                           }
                                         ],
                             'align' => undef,
                             'nowrap' => 'true',
                             'name' => 'BrigData'
                           },
             'BrigSegCvtModifier' => {
                                       'wname' => 'SegCvtModifier',
                                       'fields' => [
                                                     {
                                                       'wname' => 'allBits',
                                                       'name' => 'allBits',
                                                       'wtype' => 'ValRef<uint8_t>',
                                                       'type' => 'BrigSegCvtModifier8_t',
                                                       'defValue' => '0',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'isNoNull',
                                                       'phantomof' => $structs->{'BrigSegCvtModifier'}{'fields'}[0],
                                                       'name' => 'isNoNull',
                                                       'wtype' => 'BitValRef<0>',
                                                       'type' => 'bool',
                                                       'acc' => 'bitValRef<0>'
                                                     }
                                                   ],
                                       'isroot' => 'true',
                                       'align' => undef,
                                       'enum' => 'BRIG_KIND_SEG_CVT_MODIFIER',
                                       'name' => 'BrigSegCvtModifier',
                                       'standalone' => 'true'
                                     },
             'BrigInst' => {
                             'parent' => 'BrigCode',
                             'align' => undef,
                             'name' => 'BrigInst',
                             'children' => {
                                             'BrigInstSignal' => $structs->{'BrigInstSignal'},
                                             'BrigInstMemFence' => $structs->{'BrigInstMemFence'},
                                             'BrigInstSegCvt' => {
                                                                   'parent' => 'BrigInst',
                                                                   'wname' => 'InstSegCvt',
                                                                   'fields' => [
                                                                                 {
                                                                                   'wname' => 'byteCount',
                                                                                   'name' => 'byteCount',
                                                                                   'wtype' => 'ValRef<uint16_t>',
                                                                                   'type' => 'uint16_t',
                                                                                   'acc' => 'valRef'
                                                                                 },
                                                                                 {
                                                                                   'wname' => 'kind',
                                                                                   'enum' => 'BrigKinds',
                                                                                   'name' => 'kind',
                                                                                   'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                   'type' => 'BrigKinds16_t',
                                                                                   'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                 },
                                                                                 {
                                                                                   'wname' => 'opcode',
                                                                                   'enum' => 'BrigOpcode',
                                                                                   'name' => 'opcode',
                                                                                   'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                                                   'type' => 'BrigOpcode16_t',
                                                                                   'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                                                 },
                                                                                 {
                                                                                   'wname' => 'type',
                                                                                   'name' => 'type',
                                                                                   'wtype' => 'ValRef<uint16_t>',
                                                                                   'type' => 'BrigType16_t',
                                                                                   'acc' => 'valRef'
                                                                                 },
                                                                                 {
                                                                                   'wname' => 'operands',
                                                                                   'name' => 'operands',
                                                                                   'wtype' => 'ListRef<Operand>',
                                                                                   'type' => 'BrigDataOffsetOperandList32_t',
                                                                                   'defValue' => '0',
                                                                                   'acc' => 'listRef<Operand>'
                                                                                 },
                                                                                 {
                                                                                   'wname' => 'sourceType',
                                                                                   'name' => 'sourceType',
                                                                                   'wtype' => 'ValRef<uint16_t>',
                                                                                   'type' => 'BrigType16_t',
                                                                                   'acc' => 'valRef'
                                                                                 },
                                                                                 {
                                                                                   'wname' => 'segment',
                                                                                   'enum' => 'BrigSegment',
                                                                                   'name' => 'segment',
                                                                                   'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                                                   'type' => 'BrigSegment8_t',
                                                                                   'defValue' => 'Brig::BRIG_SEGMENT_NONE',
                                                                                   'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                                                                 },
                                                                                 {
                                                                                   'wname' => 'modifier',
                                                                                   'name' => 'modifier',
                                                                                   'wtype' => 'SegCvtModifier',
                                                                                   'type' => 'BrigSegCvtModifier',
                                                                                   'acc' => 'subItem<SegCvtModifier>'
                                                                                 }
                                                                               ],
                                                                   'align' => undef,
                                                                   'enum' => 'BRIG_KIND_INST_SEG_CVT',
                                                                   'name' => 'BrigInstSegCvt'
                                                                 },
                                             'BrigInstAddr' => {
                                                                 'parent' => 'BrigInst',
                                                                 'wname' => 'InstAddr',
                                                                 'fields' => [
                                                                               {
                                                                                 'wname' => 'byteCount',
                                                                                 'name' => 'byteCount',
                                                                                 'wtype' => 'ValRef<uint16_t>',
                                                                                 'type' => 'uint16_t',
                                                                                 'acc' => 'valRef'
                                                                               },
                                                                               {
                                                                                 'wname' => 'kind',
                                                                                 'enum' => 'BrigKinds',
                                                                                 'name' => 'kind',
                                                                                 'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                 'type' => 'BrigKinds16_t',
                                                                                 'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                               },
                                                                               {
                                                                                 'wname' => 'opcode',
                                                                                 'enum' => 'BrigOpcode',
                                                                                 'name' => 'opcode',
                                                                                 'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                                                 'type' => 'BrigOpcode16_t',
                                                                                 'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                                               },
                                                                               {
                                                                                 'wname' => 'type',
                                                                                 'name' => 'type',
                                                                                 'wtype' => 'ValRef<uint16_t>',
                                                                                 'type' => 'BrigType16_t',
                                                                                 'acc' => 'valRef'
                                                                               },
                                                                               {
                                                                                 'wname' => 'operands',
                                                                                 'name' => 'operands',
                                                                                 'wtype' => 'ListRef<Operand>',
                                                                                 'type' => 'BrigDataOffsetOperandList32_t',
                                                                                 'defValue' => '0',
                                                                                 'acc' => 'listRef<Operand>'
                                                                               },
                                                                               {
                                                                                 'wname' => 'segment',
                                                                                 'enum' => 'BrigSegment',
                                                                                 'name' => 'segment',
                                                                                 'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                                                 'type' => 'BrigSegment8_t',
                                                                                 'defValue' => 'Brig::BRIG_SEGMENT_NONE',
                                                                                 'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                                                               },
                                                                               {
                                                                                 'name' => 'reserved',
                                                                                 'defValue' => '0',
                                                                                 'acc' => 'valRef',
                                                                                 'size' => '3',
                                                                                 'wname' => 'reserved',
                                                                                 'skip' => 1,
                                                                                 'type' => 'uint8_t',
                                                                                 'wtype' => 'ValRef<uint8_t>'
                                                                               }
                                                                             ],
                                                                 'align' => undef,
                                                                 'enum' => 'BRIG_KIND_INST_ADDR',
                                                                 'name' => 'BrigInstAddr'
                                                               },
                                             'BrigInstCvt' => {
                                                                'parent' => 'BrigInst',
                                                                'wname' => 'InstCvt',
                                                                'fields' => [
                                                                              {
                                                                                'wname' => 'byteCount',
                                                                                'name' => 'byteCount',
                                                                                'wtype' => 'ValRef<uint16_t>',
                                                                                'type' => 'uint16_t',
                                                                                'acc' => 'valRef'
                                                                              },
                                                                              {
                                                                                'wname' => 'kind',
                                                                                'enum' => 'BrigKinds',
                                                                                'name' => 'kind',
                                                                                'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                'type' => 'BrigKinds16_t',
                                                                                'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                              },
                                                                              {
                                                                                'wname' => 'opcode',
                                                                                'enum' => 'BrigOpcode',
                                                                                'name' => 'opcode',
                                                                                'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                                                'type' => 'BrigOpcode16_t',
                                                                                'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                                              },
                                                                              {
                                                                                'wname' => 'type',
                                                                                'name' => 'type',
                                                                                'wtype' => 'ValRef<uint16_t>',
                                                                                'type' => 'BrigType16_t',
                                                                                'acc' => 'valRef'
                                                                              },
                                                                              {
                                                                                'wname' => 'operands',
                                                                                'name' => 'operands',
                                                                                'wtype' => 'ListRef<Operand>',
                                                                                'type' => 'BrigDataOffsetOperandList32_t',
                                                                                'defValue' => '0',
                                                                                'acc' => 'listRef<Operand>'
                                                                              },
                                                                              {
                                                                                'wname' => 'sourceType',
                                                                                'name' => 'sourceType',
                                                                                'wtype' => 'ValRef<uint16_t>',
                                                                                'type' => 'BrigType16_t',
                                                                                'acc' => 'valRef'
                                                                              },
                                                                              {
                                                                                'wname' => 'modifier',
                                                                                'name' => 'modifier',
                                                                                'wtype' => 'AluModifier',
                                                                                'type' => 'BrigAluModifier',
                                                                                'acc' => 'subItem<AluModifier>'
                                                                              }
                                                                            ],
                                                                'align' => undef,
                                                                'enum' => 'BRIG_KIND_INST_CVT',
                                                                'name' => 'BrigInstCvt'
                                                              },
                                             'BrigInstQuerySampler' => {
                                                                         'parent' => 'BrigInst',
                                                                         'wname' => 'InstQuerySampler',
                                                                         'fields' => [
                                                                                       {
                                                                                         'wname' => 'byteCount',
                                                                                         'name' => 'byteCount',
                                                                                         'wtype' => 'ValRef<uint16_t>',
                                                                                         'type' => 'uint16_t',
                                                                                         'acc' => 'valRef'
                                                                                       },
                                                                                       {
                                                                                         'wname' => 'kind',
                                                                                         'enum' => 'BrigKinds',
                                                                                         'name' => 'kind',
                                                                                         'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                         'type' => 'BrigKinds16_t',
                                                                                         'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                       },
                                                                                       {
                                                                                         'wname' => 'opcode',
                                                                                         'enum' => 'BrigOpcode',
                                                                                         'name' => 'opcode',
                                                                                         'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                                                         'type' => 'BrigOpcode16_t',
                                                                                         'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                                                       },
                                                                                       {
                                                                                         'wname' => 'type',
                                                                                         'name' => 'type',
                                                                                         'wtype' => 'ValRef<uint16_t>',
                                                                                         'type' => 'BrigType16_t',
                                                                                         'acc' => 'valRef'
                                                                                       },
                                                                                       {
                                                                                         'wname' => 'operands',
                                                                                         'name' => 'operands',
                                                                                         'wtype' => 'ListRef<Operand>',
                                                                                         'type' => 'BrigDataOffsetOperandList32_t',
                                                                                         'defValue' => '0',
                                                                                         'acc' => 'listRef<Operand>'
                                                                                       },
                                                                                       {
                                                                                         'wname' => 'samplerQuery',
                                                                                         'enum' => 'BrigSamplerQuery',
                                                                                         'name' => 'samplerQuery',
                                                                                         'wtype' => 'EnumValRef<Brig::BrigSamplerQuery,uint8_t>',
                                                                                         'type' => 'BrigSamplerQuery8_t',
                                                                                         'acc' => 'enumValRef<Brig::BrigSamplerQuery,uint8_t>'
                                                                                       },
                                                                                       {
                                                                                         'name' => 'reserved',
                                                                                         'defValue' => '0',
                                                                                         'acc' => 'valRef',
                                                                                         'size' => '3',
                                                                                         'wname' => 'reserved',
                                                                                         'skip' => 1,
                                                                                         'type' => 'uint8_t',
                                                                                         'wtype' => 'ValRef<uint8_t>'
                                                                                       }
                                                                                     ],
                                                                         'align' => undef,
                                                                         'enum' => 'BRIG_KIND_INST_QUERY_SAMPLER',
                                                                         'name' => 'BrigInstQuerySampler'
                                                                       },
                                             'BrigInstQueryImage' => {
                                                                       'parent' => 'BrigInst',
                                                                       'wname' => 'InstQueryImage',
                                                                       'fields' => [
                                                                                     {
                                                                                       'wname' => 'byteCount',
                                                                                       'name' => 'byteCount',
                                                                                       'wtype' => 'ValRef<uint16_t>',
                                                                                       'type' => 'uint16_t',
                                                                                       'acc' => 'valRef'
                                                                                     },
                                                                                     {
                                                                                       'wname' => 'kind',
                                                                                       'enum' => 'BrigKinds',
                                                                                       'name' => 'kind',
                                                                                       'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                       'type' => 'BrigKinds16_t',
                                                                                       'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                     },
                                                                                     {
                                                                                       'wname' => 'opcode',
                                                                                       'enum' => 'BrigOpcode',
                                                                                       'name' => 'opcode',
                                                                                       'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                                                       'type' => 'BrigOpcode16_t',
                                                                                       'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                                                     },
                                                                                     {
                                                                                       'wname' => 'type',
                                                                                       'name' => 'type',
                                                                                       'wtype' => 'ValRef<uint16_t>',
                                                                                       'type' => 'BrigType16_t',
                                                                                       'acc' => 'valRef'
                                                                                     },
                                                                                     {
                                                                                       'wname' => 'operands',
                                                                                       'name' => 'operands',
                                                                                       'wtype' => 'ListRef<Operand>',
                                                                                       'type' => 'BrigDataOffsetOperandList32_t',
                                                                                       'defValue' => '0',
                                                                                       'acc' => 'listRef<Operand>'
                                                                                     },
                                                                                     {
                                                                                       'wname' => 'imageType',
                                                                                       'name' => 'imageType',
                                                                                       'wtype' => 'ValRef<uint16_t>',
                                                                                       'type' => 'BrigType16_t',
                                                                                       'acc' => 'valRef'
                                                                                     },
                                                                                     {
                                                                                       'wname' => 'geometry',
                                                                                       'enum' => 'BrigImageGeometry',
                                                                                       'name' => 'geometry',
                                                                                       'wtype' => 'EnumValRef<Brig::BrigImageGeometry,uint8_t>',
                                                                                       'type' => 'BrigImageGeometry8_t',
                                                                                       'defValue' => 'Brig::BRIG_GEOMETRY_UNKNOWN',
                                                                                       'acc' => 'enumValRef<Brig::BrigImageGeometry,uint8_t>'
                                                                                     },
                                                                                     {
                                                                                       'wname' => 'imageQuery',
                                                                                       'enum' => 'BrigImageQuery',
                                                                                       'name' => 'imageQuery',
                                                                                       'wtype' => 'EnumValRef<Brig::BrigImageQuery,uint8_t>',
                                                                                       'type' => 'BrigImageQuery8_t',
                                                                                       'acc' => 'enumValRef<Brig::BrigImageQuery,uint8_t>'
                                                                                     }
                                                                                   ],
                                                                       'align' => undef,
                                                                       'enum' => 'BRIG_KIND_INST_QUERY_IMAGE',
                                                                       'name' => 'BrigInstQueryImage'
                                                                     },
                                             'BrigInstMod' => {
                                                                'parent' => 'BrigInst',
                                                                'wname' => 'InstMod',
                                                                'fields' => [
                                                                              {
                                                                                'wname' => 'byteCount',
                                                                                'name' => 'byteCount',
                                                                                'wtype' => 'ValRef<uint16_t>',
                                                                                'type' => 'uint16_t',
                                                                                'acc' => 'valRef'
                                                                              },
                                                                              {
                                                                                'wname' => 'kind',
                                                                                'enum' => 'BrigKinds',
                                                                                'name' => 'kind',
                                                                                'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                'type' => 'BrigKinds16_t',
                                                                                'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                              },
                                                                              {
                                                                                'wname' => 'opcode',
                                                                                'enum' => 'BrigOpcode',
                                                                                'name' => 'opcode',
                                                                                'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                                                'type' => 'BrigOpcode16_t',
                                                                                'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                                              },
                                                                              {
                                                                                'wname' => 'type',
                                                                                'name' => 'type',
                                                                                'wtype' => 'ValRef<uint16_t>',
                                                                                'type' => 'BrigType16_t',
                                                                                'acc' => 'valRef'
                                                                              },
                                                                              {
                                                                                'wname' => 'operands',
                                                                                'name' => 'operands',
                                                                                'wtype' => 'ListRef<Operand>',
                                                                                'type' => 'BrigDataOffsetOperandList32_t',
                                                                                'defValue' => '0',
                                                                                'acc' => 'listRef<Operand>'
                                                                              },
                                                                              {
                                                                                'wname' => 'modifier',
                                                                                'name' => 'modifier',
                                                                                'wtype' => 'AluModifier',
                                                                                'type' => 'BrigAluModifier',
                                                                                'acc' => 'subItem<AluModifier>'
                                                                              },
                                                                              {
                                                                                'wname' => 'pack',
                                                                                'enum' => 'BrigPack',
                                                                                'name' => 'pack',
                                                                                'wtype' => 'EnumValRef<Brig::BrigPack,uint8_t>',
                                                                                'type' => 'BrigPack8_t',
                                                                                'defValue' => 'Brig::BRIG_PACK_NONE',
                                                                                'acc' => 'enumValRef<Brig::BrigPack,uint8_t>'
                                                                              },
                                                                              {
                                                                                'wname' => 'reserved',
                                                                                'skip' => 1,
                                                                                'name' => 'reserved',
                                                                                'wtype' => 'ValRef<uint8_t>',
                                                                                'type' => 'uint8_t',
                                                                                'defValue' => '0',
                                                                                'acc' => 'valRef'
                                                                              }
                                                                            ],
                                                                'align' => undef,
                                                                'enum' => 'BRIG_KIND_INST_MOD',
                                                                'name' => 'BrigInstMod'
                                                              },
                                             'BrigInstBasic' => {
                                                                  'parent' => 'BrigInst',
                                                                  'wname' => 'InstBasic',
                                                                  'fields' => [
                                                                                {
                                                                                  'wname' => 'byteCount',
                                                                                  'name' => 'byteCount',
                                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                                  'type' => 'uint16_t',
                                                                                  'acc' => 'valRef'
                                                                                },
                                                                                {
                                                                                  'wname' => 'kind',
                                                                                  'enum' => 'BrigKinds',
                                                                                  'name' => 'kind',
                                                                                  'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                  'type' => 'BrigKinds16_t',
                                                                                  'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                },
                                                                                {
                                                                                  'wname' => 'opcode',
                                                                                  'enum' => 'BrigOpcode',
                                                                                  'name' => 'opcode',
                                                                                  'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                                                  'type' => 'BrigOpcode16_t',
                                                                                  'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                                                },
                                                                                {
                                                                                  'wname' => 'type',
                                                                                  'name' => 'type',
                                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                                  'type' => 'BrigType16_t',
                                                                                  'acc' => 'valRef'
                                                                                },
                                                                                {
                                                                                  'wname' => 'operands',
                                                                                  'name' => 'operands',
                                                                                  'wtype' => 'ListRef<Operand>',
                                                                                  'type' => 'BrigDataOffsetOperandList32_t',
                                                                                  'defValue' => '0',
                                                                                  'acc' => 'listRef<Operand>'
                                                                                }
                                                                              ],
                                                                  'align' => undef,
                                                                  'enum' => 'BRIG_KIND_INST_BASIC',
                                                                  'name' => 'BrigInstBasic'
                                                                },
                                             'BrigInstAtomic' => $structs->{'BrigInstAtomic'},
                                             'BrigInstSourceType' => $structs->{'BrigInstSourceType'},
                                             'BrigInstImage' => $structs->{'BrigInstImage'},
                                             'BrigInstBr' => $structs->{'BrigInstBr'},
                                             'BrigInstMem' => $structs->{'BrigInstMem'},
                                             'BrigInstSeg' => $structs->{'BrigInstSeg'},
                                             'BrigInstQueue' => {
                                                                  'parent' => 'BrigInst',
                                                                  'wname' => 'InstQueue',
                                                                  'fields' => [
                                                                                {
                                                                                  'wname' => 'byteCount',
                                                                                  'name' => 'byteCount',
                                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                                  'type' => 'uint16_t',
                                                                                  'acc' => 'valRef'
                                                                                },
                                                                                {
                                                                                  'wname' => 'kind',
                                                                                  'enum' => 'BrigKinds',
                                                                                  'name' => 'kind',
                                                                                  'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                  'type' => 'BrigKinds16_t',
                                                                                  'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                },
                                                                                {
                                                                                  'wname' => 'opcode',
                                                                                  'enum' => 'BrigOpcode',
                                                                                  'name' => 'opcode',
                                                                                  'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                                                  'type' => 'BrigOpcode16_t',
                                                                                  'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                                                },
                                                                                {
                                                                                  'wname' => 'type',
                                                                                  'name' => 'type',
                                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                                  'type' => 'BrigType16_t',
                                                                                  'acc' => 'valRef'
                                                                                },
                                                                                {
                                                                                  'wname' => 'operands',
                                                                                  'name' => 'operands',
                                                                                  'wtype' => 'ListRef<Operand>',
                                                                                  'type' => 'BrigDataOffsetOperandList32_t',
                                                                                  'defValue' => '0',
                                                                                  'acc' => 'listRef<Operand>'
                                                                                },
                                                                                {
                                                                                  'wname' => 'segment',
                                                                                  'enum' => 'BrigSegment',
                                                                                  'name' => 'segment',
                                                                                  'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                                                  'type' => 'BrigSegment8_t',
                                                                                  'defValue' => 'Brig::BRIG_SEGMENT_NONE',
                                                                                  'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                                                                },
                                                                                {
                                                                                  'wname' => 'memoryOrder',
                                                                                  'enum' => 'BrigMemoryOrder',
                                                                                  'name' => 'memoryOrder',
                                                                                  'wtype' => 'EnumValRef<Brig::BrigMemoryOrder,uint8_t>',
                                                                                  'type' => 'BrigMemoryOrder8_t',
                                                                                  'defValue' => 'Brig::BRIG_MEMORY_ORDER_RELAXED',
                                                                                  'acc' => 'enumValRef<Brig::BrigMemoryOrder,uint8_t>'
                                                                                },
                                                                                {
                                                                                  'wname' => 'reserved',
                                                                                  'skip' => 1,
                                                                                  'name' => 'reserved',
                                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                                  'type' => 'uint16_t',
                                                                                  'defValue' => '0',
                                                                                  'acc' => 'valRef'
                                                                                }
                                                                              ],
                                                                  'align' => undef,
                                                                  'enum' => 'BRIG_KIND_INST_QUEUE',
                                                                  'name' => 'BrigInstQueue'
                                                                },
                                             'BrigInstCmp' => $structs->{'BrigInstCmp'},
                                             'BrigInstLane' => {
                                                                 'parent' => 'BrigInst',
                                                                 'wname' => 'InstLane',
                                                                 'fields' => [
                                                                               {
                                                                                 'wname' => 'byteCount',
                                                                                 'name' => 'byteCount',
                                                                                 'wtype' => 'ValRef<uint16_t>',
                                                                                 'type' => 'uint16_t',
                                                                                 'acc' => 'valRef'
                                                                               },
                                                                               {
                                                                                 'wname' => 'kind',
                                                                                 'enum' => 'BrigKinds',
                                                                                 'name' => 'kind',
                                                                                 'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                 'type' => 'BrigKinds16_t',
                                                                                 'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                               },
                                                                               {
                                                                                 'wname' => 'opcode',
                                                                                 'enum' => 'BrigOpcode',
                                                                                 'name' => 'opcode',
                                                                                 'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                                                                 'type' => 'BrigOpcode16_t',
                                                                                 'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                                                               },
                                                                               {
                                                                                 'wname' => 'type',
                                                                                 'name' => 'type',
                                                                                 'wtype' => 'ValRef<uint16_t>',
                                                                                 'type' => 'BrigType16_t',
                                                                                 'acc' => 'valRef'
                                                                               },
                                                                               {
                                                                                 'wname' => 'operands',
                                                                                 'name' => 'operands',
                                                                                 'wtype' => 'ListRef<Operand>',
                                                                                 'type' => 'BrigDataOffsetOperandList32_t',
                                                                                 'defValue' => '0',
                                                                                 'acc' => 'listRef<Operand>'
                                                                               },
                                                                               {
                                                                                 'wname' => 'sourceType',
                                                                                 'name' => 'sourceType',
                                                                                 'wtype' => 'ValRef<uint16_t>',
                                                                                 'type' => 'BrigType16_t',
                                                                                 'acc' => 'valRef'
                                                                               },
                                                                               {
                                                                                 'wname' => 'width',
                                                                                 'enum' => 'BrigWidth',
                                                                                 'name' => 'width',
                                                                                 'wtype' => 'EnumValRef<Brig::BrigWidth,uint8_t>',
                                                                                 'type' => 'BrigWidth8_t',
                                                                                 'acc' => 'enumValRef<Brig::BrigWidth,uint8_t>'
                                                                               },
                                                                               {
                                                                                 'wname' => 'reserved',
                                                                                 'skip' => 1,
                                                                                 'name' => 'reserved',
                                                                                 'wtype' => 'ValRef<uint8_t>',
                                                                                 'type' => 'uint8_t',
                                                                                 'defValue' => '0',
                                                                                 'acc' => 'valRef'
                                                                               }
                                                                             ],
                                                                 'align' => undef,
                                                                 'enum' => 'BRIG_KIND_INST_LANE',
                                                                 'name' => 'BrigInstLane'
                                                               }
                                           },
                             'generic' => 'true',
                             'wname' => 'Inst',
                             'fields' => [
                                           {
                                             'wname' => 'byteCount',
                                             'name' => 'byteCount',
                                             'wtype' => 'ValRef<uint16_t>',
                                             'type' => 'uint16_t',
                                             'acc' => 'valRef'
                                           },
                                           {
                                             'wname' => 'kind',
                                             'enum' => 'BrigKinds',
                                             'name' => 'kind',
                                             'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                             'type' => 'BrigKinds16_t',
                                             'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                           },
                                           {
                                             'wname' => 'opcode',
                                             'enum' => 'BrigOpcode',
                                             'name' => 'opcode',
                                             'wtype' => 'EnumValRef<Brig::BrigOpcode,uint16_t>',
                                             'type' => 'BrigOpcode16_t',
                                             'acc' => 'enumValRef<Brig::BrigOpcode,uint16_t>'
                                           },
                                           {
                                             'wname' => 'type',
                                             'name' => 'type',
                                             'wtype' => 'ValRef<uint16_t>',
                                             'type' => 'BrigType16_t',
                                             'acc' => 'valRef'
                                           },
                                           {
                                             'implcode' => [
                                                             'inline Operand KLASS::operand(int index) { return operands()[index]; }'
                                                           ],
                                             'hcode' => [
                                                          'Operand operand(int index);'
                                                        ],
                                             'name' => 'operands',
                                             'defValue' => '0',
                                             'acc' => 'listRef<Operand>',
                                             'wname' => 'operands',
                                             'type' => 'BrigDataOffsetOperandList32_t',
                                             'wtype' => 'ListRef<Operand>'
                                           }
                                         ],
                             'enum' => 'BRIG_KIND_INST'
                           },
             'BrigDirective' => {
                                  'parent' => 'BrigCode',
                                  'align' => undef,
                                  'name' => 'BrigDirective',
                                  'children' => {
                                                  'BrigDirectiveLabel' => $structs->{'BrigDirectiveLabel'},
                                                  'BrigDirectiveExtension' => $structs->{'BrigDirectiveExtension'},
                                                  'BrigDirectiveVariable' => $structs->{'BrigDirectiveVariable'},
                                                  'BrigDirectiveArgBlockStart' => $structs->{'BrigDirectiveArgBlockStart'},
                                                  'BrigDirectiveControl' => $structs->{'BrigDirectiveControl'},
                                                  'BrigDirectiveFunction' => $structs->{'BrigDirectiveExecutable'}{'children'}{'BrigDirectiveFunction'},
                                                  'BrigDirectiveSignature' => $structs->{'BrigDirectiveSignature'},
                                                  'BrigDirectiveArgBlockEnd' => {
                                                                                  'parent' => 'BrigDirective',
                                                                                  'wname' => 'DirectiveArgBlockEnd',
                                                                                  'fields' => [
                                                                                                {
                                                                                                  'wname' => 'byteCount',
                                                                                                  'name' => 'byteCount',
                                                                                                  'wtype' => 'ValRef<uint16_t>',
                                                                                                  'type' => 'uint16_t',
                                                                                                  'acc' => 'valRef'
                                                                                                },
                                                                                                {
                                                                                                  'wname' => 'kind',
                                                                                                  'enum' => 'BrigKinds',
                                                                                                  'name' => 'kind',
                                                                                                  'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                                  'type' => 'BrigKinds16_t',
                                                                                                  'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                                }
                                                                                              ],
                                                                                  'align' => undef,
                                                                                  'enum' => 'BRIG_KIND_DIRECTIVE_ARG_BLOCK_END',
                                                                                  'name' => 'BrigDirectiveArgBlockEnd'
                                                                                },
                                                  'BrigDirectiveLoc' => {
                                                                          'parent' => 'BrigDirective',
                                                                          'wname' => 'DirectiveLoc',
                                                                          'fields' => [
                                                                                        {
                                                                                          'wname' => 'byteCount',
                                                                                          'name' => 'byteCount',
                                                                                          'wtype' => 'ValRef<uint16_t>',
                                                                                          'type' => 'uint16_t',
                                                                                          'acc' => 'valRef'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'kind',
                                                                                          'enum' => 'BrigKinds',
                                                                                          'name' => 'kind',
                                                                                          'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                          'type' => 'BrigKinds16_t',
                                                                                          'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'filename',
                                                                                          'name' => 'filename',
                                                                                          'wtype' => 'StrRef',
                                                                                          'type' => 'BrigDataOffsetString32_t',
                                                                                          'defValue' => '0',
                                                                                          'acc' => 'strRef'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'line',
                                                                                          'name' => 'line',
                                                                                          'wtype' => 'ValRef<uint32_t>',
                                                                                          'type' => 'uint32_t',
                                                                                          'acc' => 'valRef'
                                                                                        },
                                                                                        {
                                                                                          'wname' => 'column',
                                                                                          'name' => 'column',
                                                                                          'wtype' => 'ValRef<uint32_t>',
                                                                                          'type' => 'uint32_t',
                                                                                          'defValue' => '1',
                                                                                          'acc' => 'valRef'
                                                                                        }
                                                                                      ],
                                                                          'align' => undef,
                                                                          'enum' => 'BRIG_KIND_DIRECTIVE_LOC',
                                                                          'name' => 'BrigDirectiveLoc'
                                                                        },
                                                  'BrigDirectiveVersion' => $structs->{'BrigDirectiveVersion'},
                                                  'BrigDirectiveNone' => $structs->{'BrigDirectiveNone'},
                                                  'BrigDirectiveComment' => {
                                                                              'parent' => 'BrigDirective',
                                                                              'wname' => 'DirectiveComment',
                                                                              'fields' => [
                                                                                            {
                                                                                              'wname' => 'byteCount',
                                                                                              'name' => 'byteCount',
                                                                                              'wtype' => 'ValRef<uint16_t>',
                                                                                              'type' => 'uint16_t',
                                                                                              'acc' => 'valRef'
                                                                                            },
                                                                                            {
                                                                                              'wname' => 'kind',
                                                                                              'enum' => 'BrigKinds',
                                                                                              'name' => 'kind',
                                                                                              'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                              'type' => 'BrigKinds16_t',
                                                                                              'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                            },
                                                                                            {
                                                                                              'wname' => 'name',
                                                                                              'name' => 'name',
                                                                                              'wtype' => 'StrRef',
                                                                                              'type' => 'BrigDataOffsetString32_t',
                                                                                              'defValue' => '0',
                                                                                              'acc' => 'strRef'
                                                                                            }
                                                                                          ],
                                                                              'align' => undef,
                                                                              'enum' => 'BRIG_KIND_DIRECTIVE_COMMENT',
                                                                              'name' => 'BrigDirectiveComment'
                                                                            },
                                                  'BrigDirectivePragma' => {
                                                                             'parent' => 'BrigDirective',
                                                                             'wname' => 'DirectivePragma',
                                                                             'fields' => [
                                                                                           {
                                                                                             'wname' => 'byteCount',
                                                                                             'name' => 'byteCount',
                                                                                             'wtype' => 'ValRef<uint16_t>',
                                                                                             'type' => 'uint16_t',
                                                                                             'acc' => 'valRef'
                                                                                           },
                                                                                           {
                                                                                             'wname' => 'kind',
                                                                                             'enum' => 'BrigKinds',
                                                                                             'name' => 'kind',
                                                                                             'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                             'type' => 'BrigKinds16_t',
                                                                                             'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                           },
                                                                                           {
                                                                                             'wname' => 'operands',
                                                                                             'name' => 'operands',
                                                                                             'wtype' => 'ListRef<Operand>',
                                                                                             'type' => 'BrigDataOffsetOperandList32_t',
                                                                                             'defValue' => '0',
                                                                                             'acc' => 'listRef<Operand>'
                                                                                           }
                                                                                         ],
                                                                             'align' => undef,
                                                                             'enum' => 'BRIG_KIND_DIRECTIVE_PRAGMA',
                                                                             'name' => 'BrigDirectivePragma'
                                                                           },
                                                  'BrigDirectiveFbarrier' => {
                                                                               'parent' => 'BrigDirective',
                                                                               'wname' => 'DirectiveFbarrier',
                                                                               'fields' => [
                                                                                             {
                                                                                               'wname' => 'byteCount',
                                                                                               'name' => 'byteCount',
                                                                                               'wtype' => 'ValRef<uint16_t>',
                                                                                               'type' => 'uint16_t',
                                                                                               'acc' => 'valRef'
                                                                                             },
                                                                                             {
                                                                                               'wname' => 'kind',
                                                                                               'enum' => 'BrigKinds',
                                                                                               'name' => 'kind',
                                                                                               'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                                                               'type' => 'BrigKinds16_t',
                                                                                               'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                                                             },
                                                                                             {
                                                                                               'wname' => 'name',
                                                                                               'name' => 'name',
                                                                                               'wtype' => 'StrRef',
                                                                                               'type' => 'BrigDataOffsetString32_t',
                                                                                               'defValue' => '0',
                                                                                               'acc' => 'strRef'
                                                                                             },
                                                                                             {
                                                                                               'wname' => 'modifier',
                                                                                               'name' => 'modifier',
                                                                                               'wtype' => 'ExecutableModifier',
                                                                                               'type' => 'BrigExecutableModifier',
                                                                                               'acc' => 'subItem<ExecutableModifier>'
                                                                                             },
                                                                                             {
                                                                                               'wname' => 'linkage',
                                                                                               'enum' => 'BrigLinkage',
                                                                                               'name' => 'linkage',
                                                                                               'wtype' => 'EnumValRef<Brig::BrigLinkage,uint8_t>',
                                                                                               'type' => 'BrigLinkage8_t',
                                                                                               'defValue' => 'Brig::BRIG_LINKAGE_NONE',
                                                                                               'acc' => 'enumValRef<Brig::BrigLinkage,uint8_t>'
                                                                                             },
                                                                                             {
                                                                                               'wname' => 'reserved',
                                                                                               'skip' => 1,
                                                                                               'name' => 'reserved',
                                                                                               'wtype' => 'ValRef<uint16_t>',
                                                                                               'type' => 'uint16_t',
                                                                                               'defValue' => '0',
                                                                                               'acc' => 'valRef'
                                                                                             }
                                                                                           ],
                                                                               'align' => undef,
                                                                               'enum' => 'BRIG_KIND_DIRECTIVE_FBARRIER',
                                                                               'name' => 'BrigDirectiveFbarrier'
                                                                             },
                                                  'BrigDirectiveKernel' => $structs->{'BrigDirectiveKernel'},
                                                  'BrigDirectiveIndirectFunction' => $structs->{'BrigDirectiveIndirectFunction'},
                                                  'BrigDirectiveExecutable' => $structs->{'BrigDirectiveExecutable'}
                                                },
                                  'generic' => 'true',
                                  'wname' => 'Directive',
                                  'fields' => [
                                                {
                                                  'wname' => 'byteCount',
                                                  'name' => 'byteCount',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'uint16_t',
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'kind',
                                                  'enum' => 'BrigKinds',
                                                  'name' => 'kind',
                                                  'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                                  'type' => 'BrigKinds16_t',
                                                  'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                                }
                                              ],
                                  'enum' => 'BRIG_KIND_DIRECTIVE'
                                },
             'BrigCode' => {
                             'align' => undef,
                             'name' => 'BrigCode',
                             'children' => {
                                             'BrigDirectiveLabel' => $structs->{'BrigDirectiveLabel'},
                                             'BrigInstSignal' => $structs->{'BrigInstSignal'},
                                             'BrigDirectiveExtension' => $structs->{'BrigDirectiveExtension'},
                                             'BrigDirectiveVariable' => $structs->{'BrigDirectiveVariable'},
                                             'BrigDirectiveArgBlockStart' => $structs->{'BrigDirectiveArgBlockStart'},
                                             'BrigInstMemFence' => $structs->{'BrigInstMemFence'},
                                             'BrigDirectiveControl' => $structs->{'BrigDirectiveControl'},
                                             'BrigDirectiveSignature' => $structs->{'BrigDirectiveSignature'},
                                             'BrigDirectiveVersion' => $structs->{'BrigDirectiveVersion'},
                                             'BrigInstAtomic' => $structs->{'BrigInstAtomic'},
                                             'BrigDirectiveNone' => $structs->{'BrigDirectiveNone'},
                                             'BrigInstSourceType' => $structs->{'BrigInstSourceType'},
                                             'BrigInstImage' => $structs->{'BrigInstImage'},
                                             'BrigInstBr' => $structs->{'BrigInstBr'},
                                             'BrigDirectiveKernel' => $structs->{'BrigDirectiveKernel'},
                                             'BrigInstSeg' => $structs->{'BrigInstSeg'},
                                             'BrigInstMem' => $structs->{'BrigInstMem'},
                                             'BrigInstCmp' => $structs->{'BrigInstCmp'},
                                             'BrigDirectiveExecutable' => $structs->{'BrigDirectiveExecutable'},
                                             'BrigDirectiveIndirectFunction' => $structs->{'BrigDirectiveIndirectFunction'},
                                             'BrigInst' => $structs->{'BrigInst'},
                                             'BrigDirective' => $structs->{'BrigDirective'},
                                             'BrigInstSegCvt' => $structs->{'BrigInst'}{'children'}{'BrigInstSegCvt'},
                                             'BrigDirectiveFunction' => $structs->{'BrigDirectiveExecutable'}{'children'}{'BrigDirectiveFunction'},
                                             'BrigInstAddr' => $structs->{'BrigInst'}{'children'}{'BrigInstAddr'},
                                             'BrigInstCvt' => $structs->{'BrigInst'}{'children'}{'BrigInstCvt'},
                                             'BrigInstQuerySampler' => $structs->{'BrigInst'}{'children'}{'BrigInstQuerySampler'},
                                             'BrigDirectiveArgBlockEnd' => $structs->{'BrigDirective'}{'children'}{'BrigDirectiveArgBlockEnd'},
                                             'BrigDirectiveLoc' => $structs->{'BrigDirective'}{'children'}{'BrigDirectiveLoc'},
                                             'BrigInstQueryImage' => $structs->{'BrigInst'}{'children'}{'BrigInstQueryImage'},
                                             'BrigInstMod' => $structs->{'BrigInst'}{'children'}{'BrigInstMod'},
                                             'BrigInstBasic' => $structs->{'BrigInst'}{'children'}{'BrigInstBasic'},
                                             'BrigDirectiveComment' => $structs->{'BrigDirective'}{'children'}{'BrigDirectiveComment'},
                                             'BrigDirectivePragma' => $structs->{'BrigDirective'}{'children'}{'BrigDirectivePragma'},
                                             'BrigDirectiveFbarrier' => $structs->{'BrigDirective'}{'children'}{'BrigDirectiveFbarrier'},
                                             'BrigInstQueue' => $structs->{'BrigInst'}{'children'}{'BrigInstQueue'},
                                             'BrigInstLane' => $structs->{'BrigInst'}{'children'}{'BrigInstLane'}
                                           },
                             'section' => 'BRIG_SECTION_INDEX_CODE',
                             'generic' => 'true',
                             'wname' => 'Code',
                             'isroot' => 'true',
                             'fields' => [
                                           {
                                             'wname' => 'byteCount',
                                             'name' => 'byteCount',
                                             'wtype' => 'ValRef<uint16_t>',
                                             'type' => 'uint16_t',
                                             'acc' => 'valRef'
                                           },
                                           {
                                             'wname' => 'kind',
                                             'enum' => 'BrigKinds',
                                             'name' => 'kind',
                                             'wtype' => 'EnumValRef<Brig::BrigKinds,uint16_t>',
                                             'type' => 'BrigKinds16_t',
                                             'acc' => 'enumValRef<Brig::BrigKinds,uint16_t>'
                                           }
                                         ],
                             'enum' => 'BRIG_KIND_CODE'
                           },
             'BrigInstSegCvt' => $structs->{'BrigInst'}{'children'}{'BrigInstSegCvt'},
             'BrigBase' => {
                             'fields' => [
                                           {
                                             'name' => 'byteCount',
                                             'type' => 'uint16_t'
                                           },
                                           {
                                             'name' => 'kind',
                                             'type' => 'BrigKinds16_t'
                                           }
                                         ],
                             'align' => undef,
                             'nowrap' => 'true',
                             'name' => 'BrigBase'
                           },
             'BrigVariableModifier' => {
                                         'wname' => 'VariableModifier',
                                         'fields' => [
                                                       {
                                                         'wname' => 'allBits',
                                                         'name' => 'allBits',
                                                         'wtype' => 'ValRef<uint8_t>',
                                                         'type' => 'BrigVariableModifier8_t',
                                                         'defValue' => '0',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'isDefinition',
                                                         'phantomof' => $structs->{'BrigVariableModifier'}{'fields'}[0],
                                                         'name' => 'isDefinition',
                                                         'wtype' => 'BitValRef<0>',
                                                         'type' => 'bool',
                                                         'acc' => 'bitValRef<0>'
                                                       },
                                                       {
                                                         'wname' => 'isConst',
                                                         'phantomof' => $structs->{'BrigVariableModifier'}{'fields'}[0],
                                                         'name' => 'isConst',
                                                         'wtype' => 'BitValRef<1>',
                                                         'type' => 'bool',
                                                         'acc' => 'bitValRef<1>'
                                                       },
                                                       {
                                                         'wname' => 'isArray',
                                                         'phantomof' => $structs->{'BrigVariableModifier'}{'fields'}[0],
                                                         'name' => 'isArray',
                                                         'wtype' => 'BitValRef<2>',
                                                         'type' => 'bool',
                                                         'acc' => 'bitValRef<2>'
                                                       },
                                                       {
                                                         'wname' => 'isFlexArray',
                                                         'phantomof' => $structs->{'BrigVariableModifier'}{'fields'}[0],
                                                         'name' => 'isFlexArray',
                                                         'wtype' => 'BitValRef<3>',
                                                         'type' => 'bool',
                                                         'acc' => 'bitValRef<3>'
                                                       }
                                                     ],
                                         'isroot' => 'true',
                                         'align' => undef,
                                         'enum' => 'BRIG_KIND_VARIABLE_MODIFIER',
                                         'name' => 'BrigVariableModifier',
                                         'standalone' => 'true'
                                       },
             'BrigDirectiveFunction' => $structs->{'BrigDirectiveExecutable'}{'children'}{'BrigDirectiveFunction'},
             'BrigInstAddr' => $structs->{'BrigInst'}{'children'}{'BrigInstAddr'},
             'BrigInstCvt' => $structs->{'BrigInst'}{'children'}{'BrigInstCvt'},
             'BrigOperandAddress' => $structs->{'BrigOperand'}{'children'}{'BrigOperandAddress'},
             'BrigInstQuerySampler' => $structs->{'BrigInst'}{'children'}{'BrigInstQuerySampler'},
             'BrigDirectiveArgBlockEnd' => $structs->{'BrigDirective'}{'children'}{'BrigDirectiveArgBlockEnd'},
             'BrigDirectiveLoc' => $structs->{'BrigDirective'}{'children'}{'BrigDirectiveLoc'},
             'BrigInstQueryImage' => $structs->{'BrigInst'}{'children'}{'BrigInstQueryImage'},
             'BrigInstMod' => $structs->{'BrigInst'}{'children'}{'BrigInstMod'},
             'BrigOperandSamplerProperties' => $structs->{'BrigOperand'}{'children'}{'BrigOperandSamplerProperties'},
             'BrigInstBasic' => $structs->{'BrigInst'}{'children'}{'BrigInstBasic'},
             'BrigOperandData' => $structs->{'BrigOperand'}{'children'}{'BrigOperandData'},
             'BrigDirectiveComment' => $structs->{'BrigDirective'}{'children'}{'BrigDirectiveComment'},
             'BrigDirectivePragma' => $structs->{'BrigDirective'}{'children'}{'BrigDirectivePragma'},
             'BrigOperandReg' => $structs->{'BrigOperand'}{'children'}{'BrigOperandReg'},
             'BrigUInt64' => {
                               'wname' => 'UInt64',
                               'fields' => [
                                             {
                                               'wname' => 'lo',
                                               'name' => 'lo',
                                               'wtype' => 'ValRef<uint32_t>',
                                               'type' => 'uint32_t',
                                               'defValue' => '0',
                                               'acc' => 'valRef'
                                             },
                                             {
                                               'implcode' => [
                                                               'inline KLASS& KLASS::operator=(uint64_t rhs) { lo() = (uint32_t)rhs; hi() = (uint32_t)(rhs >> 32); return *this; }',
                                                               'inline KLASS::operator uint64_t() { return ((uint64_t)hi()) << 32 | lo(); }'
                                                             ],
                                               'hcode' => [
                                                            'KLASS& operator=(uint64_t rhs);',
                                                            'operator uint64_t();'
                                                          ],
                                               'name' => 'hi',
                                               'defValue' => '0',
                                               'acc' => 'valRef',
                                               'wname' => 'hi',
                                               'type' => 'uint32_t',
                                               'wtype' => 'ValRef<uint32_t>'
                                             }
                                           ],
                               'isroot' => 'true',
                               'align' => undef,
                               'enum' => 'BRIG_KIND_U_INT64',
                               'name' => 'BrigUInt64',
                               'standalone' => 'true'
                             },
             'BrigDirectiveFbarrier' => $structs->{'BrigDirective'}{'children'}{'BrigDirectiveFbarrier'},
             'BrigInstQueue' => $structs->{'BrigInst'}{'children'}{'BrigInstQueue'},
             'BrigExecutableModifier' => {
                                           'wname' => 'ExecutableModifier',
                                           'fields' => [
                                                         {
                                                           'wname' => 'allBits',
                                                           'name' => 'allBits',
                                                           'wtype' => 'ValRef<uint8_t>',
                                                           'type' => 'BrigExecutableModifier8_t',
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'isDefinition',
                                                           'phantomof' => $structs->{'BrigExecutableModifier'}{'fields'}[0],
                                                           'name' => 'isDefinition',
                                                           'wtype' => 'BitValRef<0>',
                                                           'type' => 'bool',
                                                           'acc' => 'bitValRef<0>'
                                                         }
                                                       ],
                                           'isroot' => 'true',
                                           'align' => undef,
                                           'enum' => 'BRIG_KIND_EXECUTABLE_MODIFIER',
                                           'name' => 'BrigExecutableModifier',
                                           'standalone' => 'true'
                                         },
             'BrigInstLane' => $structs->{'BrigInst'}{'children'}{'BrigInstLane'},
             'BrigOperandCodeRef' => $structs->{'BrigOperand'}{'children'}{'BrigOperandCodeRef'}
           };
