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
             'BrigDirectiveExtension' => {
                                           'wname' => 'DirectiveExtension',
                                           'parent' => 'BrigDirectiveCode',
                                           'fields' => [
                                                         {
                                                           'wname' => 'size',
                                                           'name' => 'size',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'kind',
                                                           'enum' => 'BrigDirectiveKinds',
                                                           'name' => 'kind',
                                                           'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                           'type' => 'BrigDirectiveKinds16_t',
                                                           'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                         },
                                                         {
                                                           'wname' => 'code',
                                                           'name' => 'code',
                                                           'wtype' => 'ItemRef<Inst>',
                                                           'type' => 'BrigCodeOffset32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<Inst>'
                                                         },
                                                         {
                                                           'wname' => 'name',
                                                           'name' => 'name',
                                                           'wtype' => 'StrRef',
                                                           'type' => 'BrigStringOffset32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'strRef'
                                                         }
                                                       ],
                                           'align' => undef,
                                           'enum' => 'BRIG_DIRECTIVE_EXTENSION',
                                           'name' => 'BrigDirectiveExtension',
                                           'comments' => [
                                                           '/// @}',
                                                           '/// extension directive.'
                                                         ]
                                         },
             'BrigOperandArgumentList' => {
                                            'wname' => 'OperandArgumentList',
                                            'parent' => 'BrigOperandList',
                                            'fields' => [
                                                          {
                                                            'wname' => 'size',
                                                            'name' => 'size',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'kind',
                                                            'enum' => 'BrigOperandKinds',
                                                            'name' => 'kind',
                                                            'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                            'type' => 'BrigOperandKinds16_t',
                                                            'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
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
                                                            'wname' => 'elementCount',
                                                            'name' => 'elementCount',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'defValue' => '0',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wspecial' => 'ArgumentRefList',
                                                            'name' => 'elements',
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<Directive>',
                                                            'size' => '1',
                                                            'wname' => 'elements',
                                                            'type' => 'BrigDirectiveOffset32_t',
                                                            'wtype' => 'ItemRef<Directive>'
                                                          }
                                                        ],
                                            'align' => undef,
                                            'enum' => 'BRIG_OPERAND_ARGUMENT_LIST',
                                            'name' => 'BrigOperandArgumentList'
                                          },
             'BrigInstMemFence' => {
                                     'parent' => 'BrigInst',
                                     'wname' => 'InstMemFence',
                                     'fields' => [
                                                   {
                                                     'wname' => 'size',
                                                     'name' => 'size',
                                                     'wtype' => 'ValRef<uint16_t>',
                                                     'type' => 'uint16_t',
                                                     'acc' => 'valRef'
                                                   },
                                                   {
                                                     'wname' => 'kind',
                                                     'enum' => 'BrigInstKinds',
                                                     'name' => 'kind',
                                                     'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                     'type' => 'BrigInstKinds16_t',
                                                     'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                     'defValue' => 'Brig::BRIG_TYPE_NONE',
                                                     'acc' => 'valRef'
                                                   },
                                                   {
                                                     'wname' => 'operand',
                                                     'name' => 'operands',
                                                     'wtype' => 'ItemRef<Operand>',
                                                     'type' => 'BrigOperandOffset32_t',
                                                     'defValue' => '0',
                                                     'acc' => 'itemRef<Operand>',
                                                     'size' => '5'
                                                   },
                                                   {
                                                     'wname' => 'segments',
                                                     'enum' => 'BrigMemoryFenceSegments',
                                                     'name' => 'segments',
                                                     'wtype' => 'EnumValRef<Brig::BrigMemoryFenceSegments,uint8_t>',
                                                     'type' => 'BrigMemoryFenceSegments8_t',
                                                     'acc' => 'enumValRef<Brig::BrigMemoryFenceSegments,uint8_t>'
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
                                     'enum' => 'BRIG_INST_MEM_FENCE',
                                     'name' => 'BrigInstMemFence'
                                   },
             'BrigOperandFunctionList' => {
                                            'wname' => 'OperandFunctionList',
                                            'parent' => 'BrigOperandList',
                                            'fields' => [
                                                          {
                                                            'wname' => 'size',
                                                            'name' => 'size',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'kind',
                                                            'enum' => 'BrigOperandKinds',
                                                            'name' => 'kind',
                                                            'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                            'type' => 'BrigOperandKinds16_t',
                                                            'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
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
                                                            'wname' => 'elementCount',
                                                            'name' => 'elementCount',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'defValue' => '0',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wspecial' => 'FunctionRefList',
                                                            'name' => 'elements',
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<Directive>',
                                                            'size' => '1',
                                                            'wname' => 'elements',
                                                            'type' => 'BrigDirectiveOffset32_t',
                                                            'wtype' => 'ItemRef<Directive>'
                                                          }
                                                        ],
                                            'align' => undef,
                                            'enum' => 'BRIG_OPERAND_FUNCTION_LIST',
                                            'name' => 'BrigOperandFunctionList',
                                            'comments' => [
                                                            '/// list of arguments. (in, out function arguments).'
                                                          ]
                                          },
             'BrigOperand' => {
                                'align' => undef,
                                'name' => 'BrigOperand',
                                'children' => [
                                                'BrigOperandAddress',
                                                'BrigOperandSignatureRef',
                                                'BrigOperandFbarrierRef',
                                                'BrigOperandLabelRef',
                                                'BrigOperandImmed',
                                                'BrigOperandArgumentList',
                                                'BrigOperandReg',
                                                'BrigOperandFunctionList',
                                                'BrigOperandFunctionRef',
                                                'BrigOperandRef',
                                                'BrigOperandLabelTargetsRef',
                                                'BrigOperandLabelVariableRef',
                                                'BrigOperandRegVector',
                                                'BrigOperandWavesize',
                                                'BrigOperandList'
                                              ],
                                'generic' => 'true',
                                'wname' => 'Operand',
                                'isroot' => 'true',
                                'fields' => [
                                              {
                                                'wname' => 'size',
                                                'name' => 'size',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigOperandKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                'type' => 'BrigOperandKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                              }
                                            ],
                                'enum' => 'BRIG_OPERAND'
                              },
             'BrigDirectiveControl' => {
                                         'wname' => 'DirectiveControl',
                                         'parent' => 'BrigDirectiveCode',
                                         'fields' => [
                                                       {
                                                         'wname' => 'size',
                                                         'name' => 'size',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'kind',
                                                         'enum' => 'BrigDirectiveKinds',
                                                         'name' => 'kind',
                                                         'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                         'type' => 'BrigDirectiveKinds16_t',
                                                         'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                       },
                                                       {
                                                         'wname' => 'code',
                                                         'name' => 'code',
                                                         'wtype' => 'ItemRef<Inst>',
                                                         'type' => 'BrigCodeOffset32_t',
                                                         'defValue' => '0',
                                                         'acc' => 'itemRef<Inst>'
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
                                                         'wname' => 'type',
                                                         'name' => 'type',
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
                                                       },
                                                       {
                                                         'wname' => 'elementCount',
                                                         'name' => 'valueCount',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'defValue' => '0',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wspecial' => 'ControlValues',
                                                         'name' => 'values',
                                                         'defValue' => '0',
                                                         'acc' => 'itemRef<Operand>',
                                                         'size' => '1',
                                                         'wname' => 'values',
                                                         'type' => 'BrigOperandOffset32_t',
                                                         'wtype' => 'ItemRef<Operand>'
                                                       }
                                                     ],
                                         'align' => undef,
                                         'enum' => 'BRIG_DIRECTIVE_CONTROL',
                                         'name' => 'BrigDirectiveControl',
                                         'comments' => [
                                                         '/// control directive.'
                                                       ]
                                       },
             'BrigDirectiveCallableBase' => {
                                              'parent' => 'BrigDirectiveCode',
                                              'align' => undef,
                                              'name' => 'BrigDirectiveCallableBase',
                                              'children' => [
                                                              'BrigDirectiveKernel',
                                                              'BrigDirectiveSignature',
                                                              'BrigDirectiveExecutable',
                                                              'BrigDirectiveFunction'
                                                            ],
                                              'generic' => 'true',
                                              'wname' => 'DirectiveCallableBase',
                                              'fields' => [
                                                            {
                                                              'wname' => 'size',
                                                              'name' => 'size',
                                                              'wtype' => 'ValRef<uint16_t>',
                                                              'type' => 'uint16_t',
                                                              'acc' => 'valRef'
                                                            },
                                                            {
                                                              'wname' => 'kind',
                                                              'enum' => 'BrigDirectiveKinds',
                                                              'name' => 'kind',
                                                              'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                              'type' => 'BrigDirectiveKinds16_t',
                                                              'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                            },
                                                            {
                                                              'wname' => 'code',
                                                              'name' => 'code',
                                                              'wtype' => 'ItemRef<Inst>',
                                                              'type' => 'BrigCodeOffset32_t',
                                                              'defValue' => '0',
                                                              'acc' => 'itemRef<Inst>'
                                                            },
                                                            {
                                                              'wname' => 'name',
                                                              'name' => 'name',
                                                              'wtype' => 'StrRef',
                                                              'type' => 'BrigStringOffset32_t',
                                                              'defValue' => '0',
                                                              'acc' => 'strRef'
                                                            },
                                                            {
                                                              'wname' => 'inArgCount',
                                                              'name' => 'inArgCount',
                                                              'wtype' => 'ValRef<uint16_t>',
                                                              'type' => 'uint16_t',
                                                              'acc' => 'valRef'
                                                            },
                                                            {
                                                              'wname' => 'outArgCount',
                                                              'name' => 'outArgCount',
                                                              'wtype' => 'ValRef<uint16_t>',
                                                              'type' => 'uint16_t',
                                                              'acc' => 'valRef'
                                                            }
                                                          ],
                                              'enum' => 'BRIG_DIRECTIVE_CALLABLE_BASE'
                                            },
             'BrigDirectiveVersion' => {
                                         'wname' => 'DirectiveVersion',
                                         'parent' => 'BrigDirectiveCode',
                                         'fields' => [
                                                       {
                                                         'wname' => 'size',
                                                         'name' => 'size',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'kind',
                                                         'enum' => 'BrigDirectiveKinds',
                                                         'name' => 'kind',
                                                         'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                         'type' => 'BrigDirectiveKinds16_t',
                                                         'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                       },
                                                       {
                                                         'wname' => 'code',
                                                         'name' => 'code',
                                                         'wtype' => 'ItemRef<Inst>',
                                                         'type' => 'BrigCodeOffset32_t',
                                                         'defValue' => '0',
                                                         'acc' => 'itemRef<Inst>'
                                                       },
                                                       {
                                                         'wname' => 'hsailMajor',
                                                         'enum' => 'BrigVersion',
                                                         'name' => 'hsailMajor',
                                                         'wtype' => 'EnumValRef<Brig::BrigVersion,uint32_t>',
                                                         'type' => 'BrigVersion32_t',
                                                         'acc' => 'enumValRef<Brig::BrigVersion,uint32_t>',
                                                         'novisit' => 'true'
                                                       },
                                                       {
                                                         'wname' => 'hsailMinor',
                                                         'enum' => 'BrigVersion',
                                                         'name' => 'hsailMinor',
                                                         'wtype' => 'EnumValRef<Brig::BrigVersion,uint32_t>',
                                                         'type' => 'BrigVersion32_t',
                                                         'acc' => 'enumValRef<Brig::BrigVersion,uint32_t>',
                                                         'novisit' => 'true'
                                                       },
                                                       {
                                                         'wname' => 'brigMajor',
                                                         'enum' => 'BrigVersion',
                                                         'name' => 'brigMajor',
                                                         'wtype' => 'EnumValRef<Brig::BrigVersion,uint32_t>',
                                                         'type' => 'BrigVersion32_t',
                                                         'acc' => 'enumValRef<Brig::BrigVersion,uint32_t>',
                                                         'novisit' => 'true'
                                                       },
                                                       {
                                                         'wname' => 'brigMinor',
                                                         'enum' => 'BrigVersion',
                                                         'name' => 'brigMinor',
                                                         'wtype' => 'EnumValRef<Brig::BrigVersion,uint32_t>',
                                                         'type' => 'BrigVersion32_t',
                                                         'acc' => 'enumValRef<Brig::BrigVersion,uint32_t>',
                                                         'novisit' => 'true'
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
                                         'enum' => 'BRIG_DIRECTIVE_VERSION',
                                         'name' => 'BrigDirectiveVersion'
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
                                       'enum' => 'BRIG_MEMORY_MODIFIER',
                                       'name' => 'BrigMemoryModifier',
                                       'standalone' => 'true'
                                     },
             'BrigInstBr' => {
                               'parent' => 'BrigInst',
                               'wname' => 'InstBr',
                               'fields' => [
                                             {
                                               'wname' => 'size',
                                               'name' => 'size',
                                               'wtype' => 'ValRef<uint16_t>',
                                               'type' => 'uint16_t',
                                               'acc' => 'valRef'
                                             },
                                             {
                                               'wname' => 'kind',
                                               'enum' => 'BrigInstKinds',
                                               'name' => 'kind',
                                               'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                               'type' => 'BrigInstKinds16_t',
                                               'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                               'wname' => 'operand',
                                               'name' => 'operands',
                                               'wtype' => 'ItemRef<Operand>',
                                               'type' => 'BrigOperandOffset32_t',
                                               'defValue' => '0',
                                               'acc' => 'itemRef<Operand>',
                                               'size' => '5'
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
                                               'size' => 3,
                                               'wname' => 'reserved',
                                               'skip' => 1,
                                               'type' => 'uint8_t',
                                               'wtype' => 'ValRef<uint8_t>'
                                             }
                                           ],
                               'align' => undef,
                               'enum' => 'BRIG_INST_BR',
                               'name' => 'BrigInstBr'
                             },
             'BrigOperandFunctionRef' => {
                                           'wname' => 'OperandFunctionRef',
                                           'parent' => 'BrigOperandRef',
                                           'fields' => [
                                                         {
                                                           'wname' => 'size',
                                                           'name' => 'size',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'kind',
                                                           'enum' => 'BrigOperandKinds',
                                                           'name' => 'kind',
                                                           'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                           'type' => 'BrigOperandKinds16_t',
                                                           'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                         },
                                                         {
                                                           'wname' => 'fn',
                                                           'name' => 'ref',
                                                           'wtype' => 'ItemRef<DirectiveFunction>',
                                                           'type' => 'BrigDirectiveOffset32_t',
                                                           'comments' => [
                                                                           '// overridden, was ItemRef<Directive> ref'
                                                                         ],
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<DirectiveFunction>'
                                                         }
                                                       ],
                                           'align' => undef,
                                           'enum' => 'BRIG_OPERAND_FUNCTION_REF',
                                           'name' => 'BrigOperandFunctionRef'
                                         },
             'BrigDirectiveSignatureArgument' => {
                                                   'align' => undef,
                                                   'name' => 'BrigDirectiveSignatureArgument',
                                                   'comments' => [
                                                                   '/// element describing properties of function signature argument.'
                                                                 ],
                                                   'wname' => 'DirectiveSignatureArgument',
                                                   'isroot' => 'true',
                                                   'fields' => [
                                                                 {
                                                                   'wname' => 'type',
                                                                   'name' => 'type',
                                                                   'wtype' => 'ValRef<uint16_t>',
                                                                   'type' => 'BrigType16_t',
                                                                   'acc' => 'valRef'
                                                                 },
                                                                 {
                                                                   'wname' => 'align',
                                                                   'enum' => 'BrigAlignment',
                                                                   'name' => 'align',
                                                                   'wtype' => 'EnumValRef<Brig::BrigAlignment,uint8_t>',
                                                                   'type' => 'BrigAlignment8_t',
                                                                   'acc' => 'enumValRef<Brig::BrigAlignment,uint8_t>'
                                                                 },
                                                                 {
                                                                   'wname' => 'modifier',
                                                                   'name' => 'modifier',
                                                                   'wtype' => 'SymbolModifier',
                                                                   'type' => 'BrigSymbolModifier',
                                                                   'acc' => 'subItem<SymbolModifier>'
                                                                 },
                                                                 {
                                                                   'wname' => 'dimLo',
                                                                   'name' => 'dimLo',
                                                                   'wtype' => 'ValRef<uint32_t>',
                                                                   'type' => 'uint32_t',
                                                                   'acc' => 'valRef'
                                                                 },
                                                                 {
                                                                   'wname' => 'dim',
                                                                   'phantomof' => $structs->{'BrigDirectiveSignatureArgument'}{'fields'}[3],
                                                                   'name' => 'dim',
                                                                   'wtype' => 'ValRef<uint64_t>',
                                                                   'type' => 'uint64_t',
                                                                   'acc' => 'reinterpretValRef<uint64_t>'
                                                                 },
                                                                 {
                                                                   'wname' => 'dimHi',
                                                                   'name' => 'dimHi',
                                                                   'wtype' => 'ValRef<uint32_t>',
                                                                   'type' => 'uint32_t',
                                                                   'acc' => 'valRef'
                                                                 }
                                                               ],
                                                   'enum' => 'BRIG_DIRECTIVE_SIGNATURE_ARGUMENT',
                                                   'standalone' => 'true'
                                                 },
             'BrigInstCmp' => {
                                'parent' => 'BrigInst',
                                'wname' => 'InstCmp',
                                'fields' => [
                                              {
                                                'wname' => 'size',
                                                'name' => 'size',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigInstKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                'type' => 'BrigInstKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                'wname' => 'operand',
                                                'name' => 'operands',
                                                'wtype' => 'ItemRef<Operand>',
                                                'type' => 'BrigOperandOffset32_t',
                                                'defValue' => '0',
                                                'acc' => 'itemRef<Operand>',
                                                'size' => '5'
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
                                'enum' => 'BRIG_INST_CMP',
                                'name' => 'BrigInstCmp'
                              },
             'BrigOperandList' => {
                                    'parent' => 'BrigOperand',
                                    'align' => undef,
                                    'name' => 'BrigOperandList',
                                    'children' => [
                                                    'BrigOperandFunctionList',
                                                    'BrigOperandArgumentList'
                                                  ],
                                    'generic' => 'true',
                                    'wname' => 'OperandList',
                                    'fields' => [
                                                  {
                                                    'wname' => 'size',
                                                    'name' => 'size',
                                                    'wtype' => 'ValRef<uint16_t>',
                                                    'type' => 'uint16_t',
                                                    'acc' => 'valRef'
                                                  },
                                                  {
                                                    'wname' => 'kind',
                                                    'enum' => 'BrigOperandKinds',
                                                    'name' => 'kind',
                                                    'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                    'type' => 'BrigOperandKinds16_t',
                                                    'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
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
                                                    'wname' => 'elementCount',
                                                    'name' => 'elementCount',
                                                    'wtype' => 'ValRef<uint16_t>',
                                                    'type' => 'uint16_t',
                                                    'defValue' => '0',
                                                    'acc' => 'valRef'
                                                  },
                                                  {
                                                    'wspecial' => 'RefList',
                                                    'name' => 'elements',
                                                    'defValue' => '0',
                                                    'acc' => 'itemRef<Directive>',
                                                    'size' => '1',
                                                    'wname' => 'elements',
                                                    'type' => 'BrigDirectiveOffset32_t',
                                                    'wtype' => 'ItemRef<Directive>'
                                                  }
                                                ],
                                    'enum' => 'BRIG_OPERAND_LIST'
                                  },
             'BrigInstNone' => {
                                 'wname' => 'InstNone',
                                 'fields' => [
                                               {
                                                 'wname' => 'size',
                                                 'name' => 'size',
                                                 'wtype' => 'ValRef<uint16_t>',
                                                 'type' => 'uint16_t',
                                                 'acc' => 'valRef'
                                               },
                                               {
                                                 'wname' => 'kind',
                                                 'enum' => 'BrigInstKinds',
                                                 'name' => 'kind',
                                                 'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                 'type' => 'BrigInstKinds16_t',
                                                 'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
                                               }
                                             ],
                                 'isroot' => 'true',
                                 'align' => undef,
                                 'enum' => 'BRIG_INST_NONE',
                                 'name' => 'BrigInstNone',
                                 'standalone' => 'true'
                               },
             'BrigInstBase' => {
                                 'fields' => [
                                               {
                                                 'name' => 'size',
                                                 'type' => 'uint16_t'
                                               },
                                               {
                                                 'name' => 'kind',
                                                 'type' => 'BrigInstKinds16_t'
                                               },
                                               {
                                                 'name' => 'opcode',
                                                 'type' => 'BrigOpcode16_t'
                                               },
                                               {
                                                 'name' => 'type',
                                                 'type' => 'BrigType16_t'
                                               },
                                               {
                                                 'name' => 'operands',
                                                 'type' => 'BrigOperandOffset32_t',
                                                 'size' => '5'
                                               }
                                             ],
                                 'align' => undef,
                                 'nowrap' => 'true',
                                 'name' => 'BrigInstBase'
                               },
             'BrigDirectiveLabelTargets' => {
                                              'wname' => 'DirectiveLabelTargets',
                                              'parent' => 'BrigDirectiveCode',
                                              'fields' => [
                                                            {
                                                              'wname' => 'size',
                                                              'name' => 'size',
                                                              'wtype' => 'ValRef<uint16_t>',
                                                              'type' => 'uint16_t',
                                                              'acc' => 'valRef'
                                                            },
                                                            {
                                                              'wname' => 'kind',
                                                              'enum' => 'BrigDirectiveKinds',
                                                              'name' => 'kind',
                                                              'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                              'type' => 'BrigDirectiveKinds16_t',
                                                              'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                            },
                                                            {
                                                              'wname' => 'code',
                                                              'name' => 'code',
                                                              'wtype' => 'ItemRef<Inst>',
                                                              'type' => 'BrigCodeOffset32_t',
                                                              'defValue' => '0',
                                                              'acc' => 'itemRef<Inst>'
                                                            },
                                                            {
                                                              'wname' => 'name',
                                                              'name' => 'name',
                                                              'wtype' => 'StrRef',
                                                              'type' => 'BrigStringOffset32_t',
                                                              'defValue' => '0',
                                                              'acc' => 'strRef'
                                                            },
                                                            {
                                                              'wname' => 'elementCount',
                                                              'name' => 'labelCount',
                                                              'wtype' => 'ValRef<uint16_t>',
                                                              'type' => 'uint16_t',
                                                              'defValue' => '0',
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
                                                            },
                                                            {
                                                              'wspecial' => 'LabelTargetsList',
                                                              'name' => 'labels',
                                                              'defValue' => '0',
                                                              'acc' => 'itemRef<DirectiveLabel>',
                                                              'size' => '1',
                                                              'wname' => 'labels',
                                                              'type' => 'BrigDirectiveOffset32_t',
                                                              'wtype' => 'ItemRef<DirectiveLabel>'
                                                            }
                                                          ],
                                              'align' => undef,
                                              'enum' => 'BRIG_DIRECTIVE_LABEL_TARGETS',
                                              'name' => 'BrigDirectiveLabelTargets'
                                            },
             'BrigDirective' => {
                                  'align' => undef,
                                  'name' => 'BrigDirective',
                                  'children' => [
                                                  'BrigDirectiveLabel',
                                                  'BrigBlockEnd',
                                                  'BrigDirectiveLabelTargets',
                                                  'BrigDirectiveArgScopeStart',
                                                  'BrigDirectiveImageInit',
                                                  'BrigBlockStart',
                                                  'BrigDirectiveExtension',
                                                  'BrigDirectiveVariable',
                                                  'BrigDirectiveArgScopeEnd',
                                                  'BrigDirectiveControl',
                                                  'BrigDirectiveSamplerInit',
                                                  'BrigBlockNumeric',
                                                  'BrigDirectiveFunction',
                                                  'BrigDirectiveVariableInit',
                                                  'BrigDirectiveSignature',
                                                  'BrigDirectiveLoc',
                                                  'BrigBlockString',
                                                  'BrigDirectiveCallableBase',
                                                  'BrigDirectiveVersion',
                                                  'BrigDirectiveCode',
                                                  'BrigDirectiveComment',
                                                  'BrigDirectivePragma',
                                                  'BrigDirectiveKernel',
                                                  'BrigDirectiveFbarrier',
                                                  'BrigDirectiveLabelInit',
                                                  'BrigDirectiveExecutable'
                                                ],
                                  'comments' => [
                                                  '/// @addtogroup Directives',
                                                  '/// @{',
                                                  '/// base class for all directive items.'
                                                ],
                                  'generic' => 'true',
                                  'wname' => 'Directive',
                                  'isroot' => 'true',
                                  'fields' => [
                                                {
                                                  'wname' => 'size',
                                                  'name' => 'size',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'uint16_t',
                                                  'comments' => [
                                                                  '/// item size.'
                                                                ],
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'kind',
                                                  'enum' => 'BrigDirectiveKinds',
                                                  'name' => 'kind',
                                                  'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                  'type' => 'BrigDirectiveKinds16_t',
                                                  'comments' => [
                                                                  '/// item kind. One of BrigDirectiveKinds enum values.'
                                                                ],
                                                  'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                }
                                              ],
                                  'enum' => 'BRIG_DIRECTIVE'
                                },
             'BrigBlockStart' => {
                                   'wname' => 'BlockStart',
                                   'parent' => 'BrigDirectiveCode',
                                   'fields' => [
                                                 {
                                                   'wname' => 'size',
                                                   'name' => 'size',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'uint16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'kind',
                                                   'enum' => 'BrigDirectiveKinds',
                                                   'name' => 'kind',
                                                   'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                   'type' => 'BrigDirectiveKinds16_t',
                                                   'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                 },
                                                 {
                                                   'wname' => 'code',
                                                   'name' => 'code',
                                                   'wtype' => 'ItemRef<Inst>',
                                                   'type' => 'BrigCodeOffset32_t',
                                                   'defValue' => '0',
                                                   'acc' => 'itemRef<Inst>'
                                                 },
                                                 {
                                                   'wname' => 'name',
                                                   'name' => 'name',
                                                   'wtype' => 'StrRef',
                                                   'type' => 'BrigStringOffset32_t',
                                                   'defValue' => '0',
                                                   'acc' => 'strRef'
                                                 }
                                               ],
                                   'align' => undef,
                                   'enum' => 'BRIG_DIRECTIVE_BLOCK_START',
                                   'name' => 'BrigBlockStart',
                                   'comments' => [
                                                   '/// start block of data.'
                                                 ]
                                 },
             'BrigDirectiveImageInit' => {
                                           'wname' => 'DirectiveImageInit',
                                           'parent' => 'BrigDirectiveCode',
                                           'fields' => [
                                                         {
                                                           'wname' => 'size',
                                                           'name' => 'size',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'kind',
                                                           'enum' => 'BrigDirectiveKinds',
                                                           'name' => 'kind',
                                                           'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                           'type' => 'BrigDirectiveKinds16_t',
                                                           'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                         },
                                                         {
                                                           'wname' => 'code',
                                                           'name' => 'code',
                                                           'wtype' => 'ItemRef<Inst>',
                                                           'type' => 'BrigCodeOffset32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<Inst>'
                                                         },
                                                         {
                                                           'wname' => 'width',
                                                           'name' => 'width',
                                                           'wtype' => 'ValRef<uint32_t>',
                                                           'type' => 'uint32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'height',
                                                           'name' => 'height',
                                                           'wtype' => 'ValRef<uint32_t>',
                                                           'type' => 'uint32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'depth',
                                                           'name' => 'depth',
                                                           'wtype' => 'ValRef<uint32_t>',
                                                           'type' => 'uint32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'array',
                                                           'name' => 'array',
                                                           'wtype' => 'ValRef<uint32_t>',
                                                           'type' => 'uint32_t',
                                                           'defValue' => '0',
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
                                                           'wname' => 'order',
                                                           'enum' => 'BrigImageOrder',
                                                           'name' => 'order',
                                                           'wtype' => 'EnumValRef<Brig::BrigImageOrder,uint8_t>',
                                                           'type' => 'BrigImageOrder8_t',
                                                           'defValue' => 'Brig::BRIG_ORDER_UNKNOWN',
                                                           'acc' => 'enumValRef<Brig::BrigImageOrder,uint8_t>'
                                                         },
                                                         {
                                                           'wname' => 'format',
                                                           'enum' => 'BrigImageFormat',
                                                           'name' => 'format',
                                                           'wtype' => 'EnumValRef<Brig::BrigImageFormat,uint8_t>',
                                                           'type' => 'BrigImageFormat8_t',
                                                           'defValue' => 'Brig::BRIG_FORMAT_UNKNOWN',
                                                           'acc' => 'enumValRef<Brig::BrigImageFormat,uint8_t>'
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
                                           'enum' => 'BRIG_DIRECTIVE_IMAGE_INIT',
                                           'name' => 'BrigDirectiveImageInit'
                                         },
             'BrigInstSegCvt' => {
                                   'parent' => 'BrigInst',
                                   'wname' => 'InstSegCvt',
                                   'fields' => [
                                                 {
                                                   'wname' => 'size',
                                                   'name' => 'size',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'uint16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'kind',
                                                   'enum' => 'BrigInstKinds',
                                                   'name' => 'kind',
                                                   'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                   'type' => 'BrigInstKinds16_t',
                                                   'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                   'name' => 'operands',
                                                   'comments' => [
                                                                   '// overridden, was ItemRef<Operand> operand'
                                                                 ],
                                                   'defValue' => '0',
                                                   'acc' => 'itemRef<Operand>',
                                                   'size' => '5',
                                                   'wname' => 'operands',
                                                   'type' => 'BrigOperandOffset32_t',
                                                   'wtype' => 'ItemRef<Operand>'
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
                                                   'defValue' => '0',
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
                                   'enum' => 'BRIG_INST_SEG_CVT',
                                   'name' => 'BrigInstSegCvt'
                                 },
             'BrigDirectiveFunction' => {
                                          'wname' => 'DirectiveFunction',
                                          'parent' => 'BrigDirectiveExecutable',
                                          'fields' => [
                                                        {
                                                          'wname' => 'size',
                                                          'name' => 'size',
                                                          'wtype' => 'ValRef<uint16_t>',
                                                          'type' => 'uint16_t',
                                                          'acc' => 'valRef'
                                                        },
                                                        {
                                                          'wname' => 'kind',
                                                          'enum' => 'BrigDirectiveKinds',
                                                          'name' => 'kind',
                                                          'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                          'type' => 'BrigDirectiveKinds16_t',
                                                          'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                        },
                                                        {
                                                          'wname' => 'code',
                                                          'name' => 'code',
                                                          'wtype' => 'ItemRef<Inst>',
                                                          'type' => 'BrigCodeOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'itemRef<Inst>'
                                                        },
                                                        {
                                                          'wname' => 'name',
                                                          'name' => 'name',
                                                          'wtype' => 'StrRef',
                                                          'type' => 'BrigStringOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'strRef'
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
                                                          'wname' => 'outArgCount',
                                                          'name' => 'outArgCount',
                                                          'wtype' => 'ValRef<uint16_t>',
                                                          'type' => 'uint16_t',
                                                          'defValue' => '0',
                                                          'acc' => 'valRef'
                                                        },
                                                        {
                                                          'wname' => 'firstInArg',
                                                          'name' => 'firstInArg',
                                                          'wtype' => 'ItemRef<Directive>',
                                                          'type' => 'BrigDirectiveOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'itemRef<Directive>'
                                                        },
                                                        {
                                                          'wname' => 'firstScopedDirective',
                                                          'name' => 'firstScopedDirective',
                                                          'wtype' => 'ItemRef<Directive>',
                                                          'type' => 'BrigDirectiveOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'itemRef<Directive>'
                                                        },
                                                        {
                                                          'wname' => 'nextTopLevelDirective',
                                                          'name' => 'nextTopLevelDirective',
                                                          'wtype' => 'ItemRef<Directive>',
                                                          'type' => 'BrigDirectiveOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'itemRef<Directive>'
                                                        },
                                                        {
                                                          'wname' => 'instCount',
                                                          'name' => 'instCount',
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
                                                          'name' => 'reserved',
                                                          'defValue' => '0',
                                                          'acc' => 'valRef',
                                                          'size' => 3,
                                                          'wname' => 'reserved',
                                                          'skip' => 1,
                                                          'type' => 'uint8_t',
                                                          'wtype' => 'ValRef<uint8_t>'
                                                        }
                                                      ],
                                          'align' => undef,
                                          'enum' => 'BRIG_DIRECTIVE_FUNCTION',
                                          'name' => 'BrigDirectiveFunction',
                                          'comments' => [
                                                          '/// function directive.'
                                                        ]
                                        },
             'BrigOperandBase' => {
                                    'fields' => [
                                                  {
                                                    'name' => 'size',
                                                    'type' => 'uint16_t'
                                                  },
                                                  {
                                                    'name' => 'kind',
                                                    'type' => 'BrigOperandKinds16_t'
                                                  }
                                                ],
                                    'align' => undef,
                                    'nowrap' => 'true',
                                    'name' => 'BrigOperandBase'
                                  },
             'BrigInstCvt' => {
                                'parent' => 'BrigInst',
                                'wname' => 'InstCvt',
                                'fields' => [
                                              {
                                                'wname' => 'size',
                                                'name' => 'size',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigInstKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                'type' => 'BrigInstKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                'wname' => 'operand',
                                                'name' => 'operands',
                                                'wtype' => 'ItemRef<Operand>',
                                                'type' => 'BrigOperandOffset32_t',
                                                'defValue' => '0',
                                                'acc' => 'itemRef<Operand>',
                                                'size' => '5'
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
                                'enum' => 'BRIG_INST_CVT',
                                'name' => 'BrigInstCvt'
                              },
             'BrigDirectiveLoc' => {
                                     'wname' => 'DirectiveLoc',
                                     'parent' => 'BrigDirectiveCode',
                                     'fields' => [
                                                   {
                                                     'wname' => 'size',
                                                     'name' => 'size',
                                                     'wtype' => 'ValRef<uint16_t>',
                                                     'type' => 'uint16_t',
                                                     'acc' => 'valRef'
                                                   },
                                                   {
                                                     'wname' => 'kind',
                                                     'enum' => 'BrigDirectiveKinds',
                                                     'name' => 'kind',
                                                     'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                     'type' => 'BrigDirectiveKinds16_t',
                                                     'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                   },
                                                   {
                                                     'wname' => 'code',
                                                     'name' => 'code',
                                                     'wtype' => 'ItemRef<Inst>',
                                                     'type' => 'BrigCodeOffset32_t',
                                                     'defValue' => '0',
                                                     'acc' => 'itemRef<Inst>'
                                                   },
                                                   {
                                                     'wname' => 'filename',
                                                     'name' => 'filename',
                                                     'wtype' => 'StrRef',
                                                     'type' => 'BrigStringOffset32_t',
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
                                     'enum' => 'BRIG_DIRECTIVE_LOC',
                                     'name' => 'BrigDirectiveLoc'
                                   },
             'BrigInstMod' => {
                                'parent' => 'BrigInst',
                                'wname' => 'InstMod',
                                'fields' => [
                                              {
                                                'wname' => 'size',
                                                'name' => 'size',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigInstKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                'type' => 'BrigInstKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                'wname' => 'operand',
                                                'name' => 'operands',
                                                'wtype' => 'ItemRef<Operand>',
                                                'type' => 'BrigOperandOffset32_t',
                                                'defValue' => '0',
                                                'acc' => 'itemRef<Operand>',
                                                'size' => '5'
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
                                'enum' => 'BRIG_INST_MOD',
                                'name' => 'BrigInstMod'
                              },
             'BrigString' => {
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
                               'name' => 'BrigString'
                             },
             'BrigOperandImmed' => {
                                     'parent' => 'BrigOperand',
                                     'wname' => 'OperandImmed',
                                     'fields' => [
                                                   {
                                                     'wname' => 'size',
                                                     'name' => 'size',
                                                     'wtype' => 'ValRef<uint16_t>',
                                                     'type' => 'uint16_t',
                                                     'acc' => 'valRef'
                                                   },
                                                   {
                                                     'wname' => 'kind',
                                                     'enum' => 'BrigOperandKinds',
                                                     'name' => 'kind',
                                                     'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                     'type' => 'BrigOperandKinds16_t',
                                                     'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
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
                                                     'wname' => 'byteCount',
                                                     'name' => 'byteCount',
                                                     'wtype' => 'ValRef<uint16_t>',
                                                     'type' => 'uint16_t',
                                                     'acc' => 'valRef'
                                                   },
                                                   {
                                                     'noaligncheck' => 'true',
                                                     'name' => 'bytes',
                                                     'acc' => 'valRef',
                                                     'novisit' => 'true',
                                                     'size' => 1,
                                                     'wname' => 'bytes',
                                                     'type' => 'uint8_t',
                                                     'wtype' => 'ValRef<uint8_t>'
                                                   }
                                                 ],
                                     'align' => undef,
                                     'enum' => 'BRIG_OPERAND_IMMED',
                                     'name' => 'BrigOperandImmed'
                                   },
             'BrigInstBasic' => {
                                  'parent' => 'BrigInst',
                                  'wname' => 'InstBasic',
                                  'fields' => [
                                                {
                                                  'wname' => 'size',
                                                  'name' => 'size',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'uint16_t',
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'kind',
                                                  'enum' => 'BrigInstKinds',
                                                  'name' => 'kind',
                                                  'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                  'type' => 'BrigInstKinds16_t',
                                                  'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                  'wname' => 'operand',
                                                  'name' => 'operands',
                                                  'wtype' => 'ItemRef<Operand>',
                                                  'type' => 'BrigOperandOffset32_t',
                                                  'defValue' => '0',
                                                  'acc' => 'itemRef<Operand>',
                                                  'size' => '5'
                                                }
                                              ],
                                  'align' => undef,
                                  'enum' => 'BRIG_INST_BASIC',
                                  'name' => 'BrigInstBasic'
                                },
             'BrigDirectivePragma' => {
                                        'wname' => 'DirectivePragma',
                                        'parent' => 'BrigDirectiveCode',
                                        'fields' => [
                                                      {
                                                        'wname' => 'size',
                                                        'name' => 'size',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'kind',
                                                        'enum' => 'BrigDirectiveKinds',
                                                        'name' => 'kind',
                                                        'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                        'type' => 'BrigDirectiveKinds16_t',
                                                        'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                      },
                                                      {
                                                        'wname' => 'code',
                                                        'name' => 'code',
                                                        'wtype' => 'ItemRef<Inst>',
                                                        'type' => 'BrigCodeOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<Inst>'
                                                      },
                                                      {
                                                        'wname' => 'name',
                                                        'name' => 'name',
                                                        'wtype' => 'StrRef',
                                                        'type' => 'BrigStringOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'strRef'
                                                      }
                                                    ],
                                        'align' => undef,
                                        'enum' => 'BRIG_DIRECTIVE_PRAGMA',
                                        'name' => 'BrigDirectivePragma'
                                      },
             'BrigDirectiveFbarrier' => {
                                          'wname' => 'DirectiveFbarrier',
                                          'parent' => 'BrigDirectiveCode',
                                          'fields' => [
                                                        {
                                                          'wname' => 'size',
                                                          'name' => 'size',
                                                          'wtype' => 'ValRef<uint16_t>',
                                                          'type' => 'uint16_t',
                                                          'acc' => 'valRef'
                                                        },
                                                        {
                                                          'wname' => 'kind',
                                                          'enum' => 'BrigDirectiveKinds',
                                                          'name' => 'kind',
                                                          'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                          'type' => 'BrigDirectiveKinds16_t',
                                                          'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                        },
                                                        {
                                                          'wname' => 'code',
                                                          'name' => 'code',
                                                          'wtype' => 'ItemRef<Inst>',
                                                          'type' => 'BrigCodeOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'itemRef<Inst>'
                                                        },
                                                        {
                                                          'wname' => 'name',
                                                          'name' => 'name',
                                                          'wtype' => 'StrRef',
                                                          'type' => 'BrigStringOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'strRef'
                                                        }
                                                      ],
                                          'align' => undef,
                                          'enum' => 'BRIG_DIRECTIVE_FBARRIER',
                                          'name' => 'BrigDirectiveFbarrier'
                                        },
             'BrigInstQueue' => {
                                  'parent' => 'BrigInst',
                                  'wname' => 'InstQueue',
                                  'fields' => [
                                                {
                                                  'wname' => 'size',
                                                  'name' => 'size',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'uint16_t',
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'kind',
                                                  'enum' => 'BrigInstKinds',
                                                  'name' => 'kind',
                                                  'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                  'type' => 'BrigInstKinds16_t',
                                                  'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                  'name' => 'operands',
                                                  'comments' => [
                                                                  '// overridden, was ItemRef<Operand> operand'
                                                                ],
                                                  'defValue' => '0',
                                                  'acc' => 'itemRef<Operand>',
                                                  'size' => '5',
                                                  'wname' => 'operands',
                                                  'type' => 'BrigOperandOffset32_t',
                                                  'wtype' => 'ItemRef<Operand>'
                                                },
                                                {
                                                  'wname' => 'segment',
                                                  'enum' => 'BrigSegment',
                                                  'name' => 'segment',
                                                  'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                  'type' => 'BrigSegment8_t',
                                                  'defValue' => '0',
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
                                  'enum' => 'BRIG_INST_QUEUE',
                                  'name' => 'BrigInstQueue'
                                },
             'BrigOperandRegVector' => {
                                         'parent' => 'BrigOperand',
                                         'wname' => 'OperandRegVector',
                                         'fields' => [
                                                       {
                                                         'wname' => 'size',
                                                         'name' => 'size',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'kind',
                                                         'enum' => 'BrigOperandKinds',
                                                         'name' => 'kind',
                                                         'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                         'type' => 'BrigOperandKinds16_t',
                                                         'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
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
                                                         'wname' => 'regCount',
                                                         'name' => 'regCount',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'defValue' => '0',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'elementCount',
                                                         'phantomof' => $structs->{'BrigOperandRegVector'}{'fields'}[3],
                                                         'name' => 'elementCount',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wspecial' => 'RegVecStrList',
                                                         'name' => 'regs',
                                                         'defValue' => '0',
                                                         'acc' => 'strRef',
                                                         'size' => '1',
                                                         'wname' => 'regs',
                                                         'type' => 'BrigStringOffset32_t',
                                                         'wtype' => 'StrRef'
                                                       }
                                                     ],
                                         'align' => undef,
                                         'enum' => 'BRIG_OPERAND_REG_VECTOR',
                                         'name' => 'BrigOperandRegVector'
                                       },
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
                                                           'wname' => 'linkage',
                                                           'phantomof' => $structs->{'BrigExecutableModifier'}{'fields'}[0],
                                                           'name' => 'linkage',
                                                           'wtype' => 'BFValRef<Brig::BrigLinkage8_t,0,2>',
                                                           'type' => 'BrigLinkage',
                                                           'acc' => 'bFValRef<Brig::BrigLinkage8_t,0,2>'
                                                         },
                                                         {
                                                           'wname' => 'isDeclaration',
                                                           'phantomof' => $structs->{'BrigExecutableModifier'}{'fields'}[0],
                                                           'name' => 'isDeclaration',
                                                           'wtype' => 'BitValRef<2>',
                                                           'type' => 'bool',
                                                           'acc' => 'bitValRef<2>'
                                                         }
                                                       ],
                                           'isroot' => 'true',
                                           'align' => undef,
                                           'enum' => 'BRIG_EXECUTABLE_MODIFIER',
                                           'name' => 'BrigExecutableModifier',
                                           'standalone' => 'true'
                                         },
             'BrigInstLane' => {
                                 'parent' => 'BrigInst',
                                 'wname' => 'InstLane',
                                 'fields' => [
                                               {
                                                 'wname' => 'size',
                                                 'name' => 'size',
                                                 'wtype' => 'ValRef<uint16_t>',
                                                 'type' => 'uint16_t',
                                                 'acc' => 'valRef'
                                               },
                                               {
                                                 'wname' => 'kind',
                                                 'enum' => 'BrigInstKinds',
                                                 'name' => 'kind',
                                                 'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                 'type' => 'BrigInstKinds16_t',
                                                 'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                 'wname' => 'operand',
                                                 'name' => 'operands',
                                                 'wtype' => 'ItemRef<Operand>',
                                                 'type' => 'BrigOperandOffset32_t',
                                                 'defValue' => '0',
                                                 'acc' => 'itemRef<Operand>',
                                                 'size' => '5'
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
                                 'enum' => 'BRIG_INST_LANE',
                                 'name' => 'BrigInstLane'
                               },
             'BrigBlockEnd' => {
                                 'wname' => 'BlockEnd',
                                 'parent' => 'BrigDirective',
                                 'fields' => [
                                               {
                                                 'wname' => 'size',
                                                 'name' => 'size',
                                                 'wtype' => 'ValRef<uint16_t>',
                                                 'type' => 'uint16_t',
                                                 'acc' => 'valRef'
                                               },
                                               {
                                                 'wname' => 'kind',
                                                 'enum' => 'BrigDirectiveKinds',
                                                 'name' => 'kind',
                                                 'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                 'type' => 'BrigDirectiveKinds16_t',
                                                 'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                               }
                                             ],
                                 'align' => undef,
                                 'enum' => 'BRIG_DIRECTIVE_BLOCK_END',
                                 'name' => 'BrigBlockEnd',
                                 'comments' => [
                                                 '/// end of block.'
                                               ]
                               },
             'BrigDirectiveLabel' => {
                                       'wname' => 'DirectiveLabel',
                                       'parent' => 'BrigDirectiveCode',
                                       'fields' => [
                                                     {
                                                       'wname' => 'size',
                                                       'name' => 'size',
                                                       'wtype' => 'ValRef<uint16_t>',
                                                       'type' => 'uint16_t',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'kind',
                                                       'enum' => 'BrigDirectiveKinds',
                                                       'name' => 'kind',
                                                       'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                       'type' => 'BrigDirectiveKinds16_t',
                                                       'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                     },
                                                     {
                                                       'wname' => 'code',
                                                       'name' => 'code',
                                                       'wtype' => 'ItemRef<Inst>',
                                                       'type' => 'BrigCodeOffset32_t',
                                                       'defValue' => '0',
                                                       'acc' => 'itemRef<Inst>'
                                                     },
                                                     {
                                                       'wname' => 'name',
                                                       'name' => 'name',
                                                       'wtype' => 'StrRef',
                                                       'type' => 'BrigStringOffset32_t',
                                                       'defValue' => '0',
                                                       'acc' => 'strRef'
                                                     }
                                                   ],
                                       'align' => undef,
                                       'enum' => 'BRIG_DIRECTIVE_LABEL',
                                       'name' => 'BrigDirectiveLabel',
                                       'comments' => [
                                                       '/// label directive'
                                                     ]
                                     },
             'BrigOperandFbarrierRef' => {
                                           'wname' => 'OperandFbarrierRef',
                                           'parent' => 'BrigOperandRef',
                                           'fields' => [
                                                         {
                                                           'wname' => 'size',
                                                           'name' => 'size',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'kind',
                                                           'enum' => 'BrigOperandKinds',
                                                           'name' => 'kind',
                                                           'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                           'type' => 'BrigOperandKinds16_t',
                                                           'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                         },
                                                         {
                                                           'wname' => 'fbar',
                                                           'name' => 'ref',
                                                           'wtype' => 'ItemRef<DirectiveFbarrier>',
                                                           'type' => 'BrigDirectiveOffset32_t',
                                                           'comments' => [
                                                                           '// overridden, was ItemRef<Directive> ref'
                                                                         ],
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<DirectiveFbarrier>'
                                                         }
                                                       ],
                                           'align' => undef,
                                           'enum' => 'BRIG_OPERAND_FBARRIER_REF',
                                           'name' => 'BrigOperandFbarrierRef'
                                         },
             'BrigInstSignal' => {
                                   'parent' => 'BrigInst',
                                   'wname' => 'InstSignal',
                                   'fields' => [
                                                 {
                                                   'wname' => 'size',
                                                   'name' => 'size',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'uint16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'kind',
                                                   'enum' => 'BrigInstKinds',
                                                   'name' => 'kind',
                                                   'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                   'type' => 'BrigInstKinds16_t',
                                                   'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                   'wname' => 'operand',
                                                   'name' => 'operands',
                                                   'wtype' => 'ItemRef<Operand>',
                                                   'type' => 'BrigOperandOffset32_t',
                                                   'defValue' => '0',
                                                   'acc' => 'itemRef<Operand>',
                                                   'size' => '5'
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
                                                   'enum' => 'BrigSignalOperation',
                                                   'name' => 'signalOperation',
                                                   'wtype' => 'EnumValRef<Brig::BrigSignalOperation,uint8_t>',
                                                   'type' => 'BrigSignalOperation8_t',
                                                   'acc' => 'enumValRef<Brig::BrigSignalOperation,uint8_t>'
                                                 }
                                               ],
                                   'align' => undef,
                                   'enum' => 'BRIG_INST_SIGNAL',
                                   'name' => 'BrigInstSignal'
                                 },
             'BrigDirectiveVariable' => {
                                          'wname' => 'DirectiveVariable',
                                          'parent' => 'BrigDirectiveCode',
                                          'fields' => [
                                                        {
                                                          'wname' => 'size',
                                                          'name' => 'size',
                                                          'wtype' => 'ValRef<uint16_t>',
                                                          'type' => 'uint16_t',
                                                          'acc' => 'valRef'
                                                        },
                                                        {
                                                          'wname' => 'kind',
                                                          'enum' => 'BrigDirectiveKinds',
                                                          'name' => 'kind',
                                                          'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                          'type' => 'BrigDirectiveKinds16_t',
                                                          'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                        },
                                                        {
                                                          'wname' => 'code',
                                                          'name' => 'code',
                                                          'wtype' => 'ItemRef<Inst>',
                                                          'type' => 'BrigCodeOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'itemRef<Inst>'
                                                        },
                                                        {
                                                          'wname' => 'name',
                                                          'name' => 'name',
                                                          'wtype' => 'StrRef',
                                                          'type' => 'BrigStringOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'strRef'
                                                        },
                                                        {
                                                          'wname' => 'init',
                                                          'name' => 'init',
                                                          'wtype' => 'ItemRef<Directive>',
                                                          'type' => 'BrigDirectiveOffset32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'itemRef<Directive>'
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
                                                          'defValue' => '0',
                                                          'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                                        },
                                                        {
                                                          'wname' => 'align',
                                                          'enum' => 'BrigAlignment',
                                                          'name' => 'align',
                                                          'wtype' => 'EnumValRef<Brig::BrigAlignment,uint8_t>',
                                                          'type' => 'BrigAlignment8_t',
                                                          'defValue' => '0',
                                                          'acc' => 'enumValRef<Brig::BrigAlignment,uint8_t>'
                                                        },
                                                        {
                                                          'wname' => 'dimLo',
                                                          'name' => 'dimLo',
                                                          'wtype' => 'ValRef<uint32_t>',
                                                          'type' => 'uint32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'valRef'
                                                        },
                                                        {
                                                          'wname' => 'dim',
                                                          'phantomof' => $structs->{'BrigDirectiveVariable'}{'fields'}[8],
                                                          'name' => 'dim',
                                                          'wtype' => 'ValRef<uint64_t>',
                                                          'type' => 'uint64_t',
                                                          'acc' => 'reinterpretValRef<uint64_t>'
                                                        },
                                                        {
                                                          'wname' => 'dimHi',
                                                          'name' => 'dimHi',
                                                          'wtype' => 'ValRef<uint32_t>',
                                                          'type' => 'uint32_t',
                                                          'defValue' => '0',
                                                          'acc' => 'valRef'
                                                        },
                                                        {
                                                          'wname' => 'modifier',
                                                          'name' => 'modifier',
                                                          'wtype' => 'SymbolModifier',
                                                          'type' => 'BrigSymbolModifier',
                                                          'acc' => 'subItem<SymbolModifier>'
                                                        },
                                                        {
                                                          'name' => 'reserved',
                                                          'defValue' => '0',
                                                          'acc' => 'valRef',
                                                          'size' => 3,
                                                          'wname' => 'reserved',
                                                          'skip' => 1,
                                                          'type' => 'uint8_t',
                                                          'wtype' => 'ValRef<uint8_t>'
                                                        }
                                                      ],
                                          'align' => undef,
                                          'enum' => 'BRIG_DIRECTIVE_VARIABLE',
                                          'name' => 'BrigDirectiveVariable'
                                        },
             'BrigDirectiveArgScopeEnd' => {
                                             'wname' => 'DirectiveArgScopeEnd',
                                             'parent' => 'BrigDirectiveCode',
                                             'fields' => [
                                                           {
                                                             'wname' => 'size',
                                                             'name' => 'size',
                                                             'wtype' => 'ValRef<uint16_t>',
                                                             'type' => 'uint16_t',
                                                             'acc' => 'valRef'
                                                           },
                                                           {
                                                             'wname' => 'kind',
                                                             'enum' => 'BrigDirectiveKinds',
                                                             'name' => 'kind',
                                                             'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                             'type' => 'BrigDirectiveKinds16_t',
                                                             'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                           },
                                                           {
                                                             'wname' => 'code',
                                                             'name' => 'code',
                                                             'wtype' => 'ItemRef<Inst>',
                                                             'type' => 'BrigCodeOffset32_t',
                                                             'defValue' => '0',
                                                             'acc' => 'itemRef<Inst>'
                                                           }
                                                         ],
                                             'align' => undef,
                                             'enum' => 'BRIG_DIRECTIVE_ARG_SCOPE_END',
                                             'name' => 'BrigDirectiveArgScopeEnd'
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
                                                    'wtype' => 'BFValRef<Brig::BrigRound8_t,0,4>',
                                                    'type' => 'BrigRound8_t',
                                                    'acc' => 'bFValRef<Brig::BrigRound8_t,0,4>'
                                                  },
                                                  {
                                                    'wname' => 'ftz',
                                                    'phantomof' => $structs->{'BrigAluModifier'}{'fields'}[0],
                                                    'name' => 'ftz',
                                                    'wtype' => 'BitValRef<4>',
                                                    'type' => 'bool',
                                                    'acc' => 'bitValRef<4>'
                                                  }
                                                ],
                                    'isroot' => 'true',
                                    'align' => undef,
                                    'enum' => 'BRIG_ALU_MODIFIER',
                                    'name' => 'BrigAluModifier',
                                    'standalone' => 'true'
                                  },
             'BrigOperandLabelTargetsRef' => {
                                               'wname' => 'OperandLabelTargetsRef',
                                               'parent' => 'BrigOperandRef',
                                               'fields' => [
                                                             {
                                                               'wname' => 'size',
                                                               'name' => 'size',
                                                               'wtype' => 'ValRef<uint16_t>',
                                                               'type' => 'uint16_t',
                                                               'acc' => 'valRef'
                                                             },
                                                             {
                                                               'wname' => 'kind',
                                                               'enum' => 'BrigOperandKinds',
                                                               'name' => 'kind',
                                                               'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                               'type' => 'BrigOperandKinds16_t',
                                                               'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                             },
                                                             {
                                                               'wname' => 'targets',
                                                               'name' => 'targets',
                                                               'wtype' => 'ItemRef<DirectiveLabelTargets>',
                                                               'type' => 'BrigDirectiveOffset32_t',
                                                               'defValue' => '0',
                                                               'acc' => 'itemRef<DirectiveLabelTargets>'
                                                             }
                                                           ],
                                               'align' => undef,
                                               'enum' => 'BRIG_OPERAND_LABEL_TARGETS_REF',
                                               'name' => 'BrigOperandLabelTargetsRef'
                                             },
             'BrigDirectiveVariableInit' => {
                                              'wname' => 'DirectiveVariableInit',
                                              'parent' => 'BrigDirectiveCode',
                                              'fields' => [
                                                            {
                                                              'wname' => 'size',
                                                              'name' => 'size',
                                                              'wtype' => 'ValRef<uint16_t>',
                                                              'type' => 'uint16_t',
                                                              'acc' => 'valRef'
                                                            },
                                                            {
                                                              'wname' => 'kind',
                                                              'enum' => 'BrigDirectiveKinds',
                                                              'name' => 'kind',
                                                              'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                              'type' => 'BrigDirectiveKinds16_t',
                                                              'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                            },
                                                            {
                                                              'wname' => 'code',
                                                              'name' => 'code',
                                                              'wtype' => 'ItemRef<Inst>',
                                                              'type' => 'BrigCodeOffset32_t',
                                                              'defValue' => '0',
                                                              'acc' => 'itemRef<Inst>'
                                                            },
                                                            {
                                                              'wname' => 'data',
                                                              'name' => 'data',
                                                              'wtype' => 'DataItemRef',
                                                              'type' => 'BrigDataOffset32_t',
                                                              'acc' => 'dataItemRef',
                                                              'novisit' => 'true'
                                                            },
                                                            {
                                                              'wspecial' => 'DataItemRefT',
                                                              'name' => 'dataAs',
                                                              'acc' => 'valRef',
                                                              'novisit' => 'true',
                                                              'phantomof' => $structs->{'BrigDirectiveVariableInit'}{'fields'}[3],
                                                              'wname' => 'dataAs',
                                                              'type' => 'BrigDataOffset32_t',
                                                              'wtype' => 'ValRef<uint32_t>',
                                                              'wspecialgeneric' => 'true'
                                                            },
                                                            {
                                                              'wname' => 'elementCount',
                                                              'name' => 'elementCount',
                                                              'wtype' => 'ValRef<uint32_t>',
                                                              'type' => 'uint32_t',
                                                              'defValue' => '0',
                                                              'acc' => 'valRef'
                                                            },
                                                            {
                                                              'wname' => 'type',
                                                              'name' => 'type',
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
                                              'enum' => 'BRIG_DIRECTIVE_VARIABLE_INIT',
                                              'name' => 'BrigDirectiveVariableInit'
                                            },
             'BrigOperandSignatureRef' => {
                                            'wname' => 'OperandSignatureRef',
                                            'parent' => 'BrigOperandRef',
                                            'fields' => [
                                                          {
                                                            'wname' => 'size',
                                                            'name' => 'size',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'kind',
                                                            'enum' => 'BrigOperandKinds',
                                                            'name' => 'kind',
                                                            'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                            'type' => 'BrigOperandKinds16_t',
                                                            'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                          },
                                                          {
                                                            'wname' => 'sig',
                                                            'name' => 'ref',
                                                            'wtype' => 'ItemRef<DirectiveCallableBase>',
                                                            'type' => 'BrigDirectiveOffset32_t',
                                                            'comments' => [
                                                                            '// overridden, was ItemRef<Directive> ref'
                                                                          ],
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<DirectiveCallableBase>'
                                                          }
                                                        ],
                                            'align' => undef,
                                            'enum' => 'BRIG_OPERAND_SIGNATURE_REF',
                                            'name' => 'BrigOperandSignatureRef'
                                          },
             'BrigDirectiveSignature' => {
                                           'wname' => 'DirectiveSignature',
                                           'parent' => 'BrigDirectiveCallableBase',
                                           'fields' => [
                                                         {
                                                           'wname' => 'size',
                                                           'name' => 'size',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'kind',
                                                           'enum' => 'BrigDirectiveKinds',
                                                           'name' => 'kind',
                                                           'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                           'type' => 'BrigDirectiveKinds16_t',
                                                           'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                         },
                                                         {
                                                           'wname' => 'code',
                                                           'name' => 'code',
                                                           'wtype' => 'ItemRef<Inst>',
                                                           'type' => 'BrigCodeOffset32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<Inst>'
                                                         },
                                                         {
                                                           'wname' => 'name',
                                                           'name' => 'name',
                                                           'wtype' => 'StrRef',
                                                           'type' => 'BrigStringOffset32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'strRef'
                                                         },
                                                         {
                                                           'wname' => 'inCount',
                                                           'name' => 'inArgCount',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'comments' => [
                                                                           '// overridden, was ValRef<uint16_t> inArgCount'
                                                                         ],
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'outCount',
                                                           'name' => 'outArgCount',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'comments' => [
                                                                           '// overridden, was ValRef<uint16_t> outArgCount'
                                                                         ],
                                                           'defValue' => '0',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'args',
                                                           'wspecial' => 'DirectiveSignatureArguments',
                                                           'name' => 'args',
                                                           'wtype' => 'DirectiveSignatureArgument',
                                                           'type' => 'BrigDirectiveSignatureArgument',
                                                           'acc' => 'subItem<DirectiveSignatureArgument>',
                                                           'size' => '1'
                                                         }
                                                       ],
                                           'align' => undef,
                                           'enum' => 'BRIG_DIRECTIVE_SIGNATURE',
                                           'name' => 'BrigDirectiveSignature',
                                           'comments' => [
                                                           '/// function signature.'
                                                         ]
                                         },
             'BrigBlockString' => {
                                    'wname' => 'BlockString',
                                    'parent' => 'BrigDirective',
                                    'fields' => [
                                                  {
                                                    'wname' => 'size',
                                                    'name' => 'size',
                                                    'wtype' => 'ValRef<uint16_t>',
                                                    'type' => 'uint16_t',
                                                    'acc' => 'valRef'
                                                  },
                                                  {
                                                    'wname' => 'kind',
                                                    'enum' => 'BrigDirectiveKinds',
                                                    'name' => 'kind',
                                                    'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                    'type' => 'BrigDirectiveKinds16_t',
                                                    'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                  },
                                                  {
                                                    'wname' => 'string',
                                                    'name' => 'string',
                                                    'wtype' => 'StrRef',
                                                    'type' => 'BrigStringOffset32_t',
                                                    'defValue' => '0',
                                                    'acc' => 'strRef'
                                                  }
                                                ],
                                    'align' => undef,
                                    'enum' => 'BRIG_DIRECTIVE_BLOCK_STRING',
                                    'name' => 'BrigBlockString',
                                    'comments' => [
                                                    '/// string inside block.'
                                                  ]
                                  },
             'BrigDirectiveCode' => {
                                      'parent' => 'BrigDirective',
                                      'align' => undef,
                                      'name' => 'BrigDirectiveCode',
                                      'children' => [
                                                      'BrigDirectiveLabel',
                                                      'BrigDirectiveLabelTargets',
                                                      'BrigDirectiveArgScopeStart',
                                                      'BrigDirectiveImageInit',
                                                      'BrigBlockStart',
                                                      'BrigDirectiveExtension',
                                                      'BrigDirectiveVariable',
                                                      'BrigDirectiveArgScopeEnd',
                                                      'BrigDirectiveControl',
                                                      'BrigDirectiveFunction',
                                                      'BrigDirectiveVariableInit',
                                                      'BrigDirectiveLoc',
                                                      'BrigDirectiveSignature',
                                                      'BrigDirectiveCallableBase',
                                                      'BrigDirectiveVersion',
                                                      'BrigDirectiveComment',
                                                      'BrigDirectivePragma',
                                                      'BrigDirectiveKernel',
                                                      'BrigDirectiveFbarrier',
                                                      'BrigDirectiveLabelInit',
                                                      'BrigDirectiveExecutable'
                                                    ],
                                      'comments' => [
                                                      '/// base class for directives that positioned in instruction stream.'
                                                    ],
                                      'generic' => 'true',
                                      'wname' => 'DirectiveCode',
                                      'fields' => [
                                                    {
                                                      'wname' => 'size',
                                                      'name' => 'size',
                                                      'wtype' => 'ValRef<uint16_t>',
                                                      'type' => 'uint16_t',
                                                      'acc' => 'valRef'
                                                    },
                                                    {
                                                      'wname' => 'kind',
                                                      'enum' => 'BrigDirectiveKinds',
                                                      'name' => 'kind',
                                                      'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                      'type' => 'BrigDirectiveKinds16_t',
                                                      'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                    },
                                                    {
                                                      'wname' => 'code',
                                                      'name' => 'code',
                                                      'wtype' => 'ItemRef<Inst>',
                                                      'type' => 'BrigCodeOffset32_t',
                                                      'defValue' => '0',
                                                      'comments' => [
                                                                      '/// Location in the instruction stream corresponding to this directive.'
                                                                    ],
                                                      'acc' => 'itemRef<Inst>'
                                                    }
                                                  ],
                                      'enum' => 'BRIG_DIRECTIVE_CODE'
                                    },
             'BrigInstAtomic' => {
                                   'parent' => 'BrigInst',
                                   'wname' => 'InstAtomic',
                                   'fields' => [
                                                 {
                                                   'wname' => 'size',
                                                   'name' => 'size',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'uint16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'kind',
                                                   'enum' => 'BrigInstKinds',
                                                   'name' => 'kind',
                                                   'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                   'type' => 'BrigInstKinds16_t',
                                                   'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                   'wname' => 'operand',
                                                   'name' => 'operands',
                                                   'wtype' => 'ItemRef<Operand>',
                                                   'type' => 'BrigOperandOffset32_t',
                                                   'defValue' => '0',
                                                   'acc' => 'itemRef<Operand>',
                                                   'size' => '5'
                                                 },
                                                 {
                                                   'wname' => 'segment',
                                                   'enum' => 'BrigSegment',
                                                   'name' => 'segment',
                                                   'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                   'type' => 'BrigSegment8_t',
                                                   'defValue' => '0',
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
                                                   'size' => 3,
                                                   'wname' => 'reserved',
                                                   'skip' => 1,
                                                   'type' => 'uint8_t',
                                                   'wtype' => 'ValRef<uint8_t>'
                                                 }
                                               ],
                                   'align' => undef,
                                   'enum' => 'BRIG_INST_ATOMIC',
                                   'name' => 'BrigInstAtomic'
                                 },
             'BrigInstSourceType' => {
                                       'parent' => 'BrigInst',
                                       'wname' => 'InstSourceType',
                                       'fields' => [
                                                     {
                                                       'wname' => 'size',
                                                       'name' => 'size',
                                                       'wtype' => 'ValRef<uint16_t>',
                                                       'type' => 'uint16_t',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'kind',
                                                       'enum' => 'BrigInstKinds',
                                                       'name' => 'kind',
                                                       'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                       'type' => 'BrigInstKinds16_t',
                                                       'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                       'name' => 'operands',
                                                       'comments' => [
                                                                       '// overridden, was ItemRef<Operand> operand'
                                                                     ],
                                                       'defValue' => '0',
                                                       'acc' => 'itemRef<Operand>',
                                                       'size' => '5',
                                                       'wname' => 'operands',
                                                       'type' => 'BrigOperandOffset32_t',
                                                       'wtype' => 'ItemRef<Operand>'
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
                                       'enum' => 'BRIG_INST_SOURCE_TYPE',
                                       'name' => 'BrigInstSourceType'
                                     },
             'BrigSymbolModifier' => {
                                       'wname' => 'SymbolModifier',
                                       'fields' => [
                                                     {
                                                       'wname' => 'allBits',
                                                       'name' => 'allBits',
                                                       'wtype' => 'ValRef<uint8_t>',
                                                       'type' => 'BrigSymbolModifier8_t',
                                                       'defValue' => '0',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'linkage',
                                                       'phantomof' => $structs->{'BrigSymbolModifier'}{'fields'}[0],
                                                       'name' => 'linkage',
                                                       'wtype' => 'BFValRef<Brig::BrigLinkage8_t,0,2>',
                                                       'type' => 'BrigLinkage',
                                                       'acc' => 'bFValRef<Brig::BrigLinkage8_t,0,2>'
                                                     },
                                                     {
                                                       'wname' => 'isDeclaration',
                                                       'phantomof' => $structs->{'BrigSymbolModifier'}{'fields'}[0],
                                                       'name' => 'isDeclaration',
                                                       'wtype' => 'BitValRef<2>',
                                                       'type' => 'bool',
                                                       'acc' => 'bitValRef<2>'
                                                     },
                                                     {
                                                       'wname' => 'isConst',
                                                       'phantomof' => $structs->{'BrigSymbolModifier'}{'fields'}[0],
                                                       'name' => 'isConst',
                                                       'wtype' => 'BitValRef<3>',
                                                       'type' => 'bool',
                                                       'acc' => 'bitValRef<3>'
                                                     },
                                                     {
                                                       'wname' => 'isArray',
                                                       'phantomof' => $structs->{'BrigSymbolModifier'}{'fields'}[0],
                                                       'name' => 'isArray',
                                                       'wtype' => 'BitValRef<4>',
                                                       'type' => 'bool',
                                                       'acc' => 'bitValRef<4>'
                                                     },
                                                     {
                                                       'wname' => 'isFlexArray',
                                                       'phantomof' => $structs->{'BrigSymbolModifier'}{'fields'}[0],
                                                       'name' => 'isFlexArray',
                                                       'wtype' => 'BitValRef<5>',
                                                       'type' => 'bool',
                                                       'acc' => 'bitValRef<5>'
                                                     }
                                                   ],
                                       'isroot' => 'true',
                                       'align' => undef,
                                       'enum' => 'BRIG_SYMBOL_MODIFIER',
                                       'name' => 'BrigSymbolModifier',
                                       'standalone' => 'true'
                                     },
             'BrigInstImage' => {
                                  'parent' => 'BrigInst',
                                  'wname' => 'InstImage',
                                  'fields' => [
                                                {
                                                  'wname' => 'size',
                                                  'name' => 'size',
                                                  'wtype' => 'ValRef<uint16_t>',
                                                  'type' => 'uint16_t',
                                                  'acc' => 'valRef'
                                                },
                                                {
                                                  'wname' => 'kind',
                                                  'enum' => 'BrigInstKinds',
                                                  'name' => 'kind',
                                                  'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                  'type' => 'BrigInstKinds16_t',
                                                  'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                  'wname' => 'operand',
                                                  'name' => 'operands',
                                                  'wtype' => 'ItemRef<Operand>',
                                                  'type' => 'BrigOperandOffset32_t',
                                                  'defValue' => '0',
                                                  'acc' => 'itemRef<Operand>',
                                                  'size' => '5'
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
                                  'enum' => 'BRIG_INST_IMAGE',
                                  'name' => 'BrigInstImage'
                                },
             'BrigDirectiveKernel' => {
                                        'wname' => 'DirectiveKernel',
                                        'parent' => 'BrigDirectiveExecutable',
                                        'fields' => [
                                                      {
                                                        'wname' => 'size',
                                                        'name' => 'size',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'kind',
                                                        'enum' => 'BrigDirectiveKinds',
                                                        'name' => 'kind',
                                                        'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                        'type' => 'BrigDirectiveKinds16_t',
                                                        'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                      },
                                                      {
                                                        'wname' => 'code',
                                                        'name' => 'code',
                                                        'wtype' => 'ItemRef<Inst>',
                                                        'type' => 'BrigCodeOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<Inst>'
                                                      },
                                                      {
                                                        'wname' => 'name',
                                                        'name' => 'name',
                                                        'wtype' => 'StrRef',
                                                        'type' => 'BrigStringOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'strRef'
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
                                                        'wname' => 'outArgCount',
                                                        'name' => 'outArgCount',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'defValue' => '0',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'firstInArg',
                                                        'name' => 'firstInArg',
                                                        'wtype' => 'ItemRef<Directive>',
                                                        'type' => 'BrigDirectiveOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<Directive>'
                                                      },
                                                      {
                                                        'wname' => 'firstScopedDirective',
                                                        'name' => 'firstScopedDirective',
                                                        'wtype' => 'ItemRef<Directive>',
                                                        'type' => 'BrigDirectiveOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<Directive>'
                                                      },
                                                      {
                                                        'wname' => 'nextTopLevelDirective',
                                                        'name' => 'nextTopLevelDirective',
                                                        'wtype' => 'ItemRef<Directive>',
                                                        'type' => 'BrigDirectiveOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<Directive>'
                                                      },
                                                      {
                                                        'wname' => 'instCount',
                                                        'name' => 'instCount',
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
                                                        'name' => 'reserved',
                                                        'defValue' => '0',
                                                        'acc' => 'valRef',
                                                        'size' => 3,
                                                        'wname' => 'reserved',
                                                        'skip' => 1,
                                                        'type' => 'uint8_t',
                                                        'wtype' => 'ValRef<uint8_t>'
                                                      }
                                                    ],
                                        'align' => undef,
                                        'enum' => 'BRIG_DIRECTIVE_KERNEL',
                                        'name' => 'BrigDirectiveKernel',
                                        'comments' => [
                                                        '/// kernel directive.'
                                                      ]
                                      },
             'BrigInstMem' => {
                                'parent' => 'BrigInst',
                                'wname' => 'InstMem',
                                'fields' => [
                                              {
                                                'wname' => 'size',
                                                'name' => 'size',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigInstKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                'type' => 'BrigInstKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                'wname' => 'operand',
                                                'name' => 'operands',
                                                'wtype' => 'ItemRef<Operand>',
                                                'type' => 'BrigOperandOffset32_t',
                                                'defValue' => '0',
                                                'acc' => 'itemRef<Operand>',
                                                'size' => '5'
                                              },
                                              {
                                                'wname' => 'segment',
                                                'enum' => 'BrigSegment',
                                                'name' => 'segment',
                                                'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                'type' => 'BrigSegment8_t',
                                                'defValue' => '0',
                                                'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                              },
                                              {
                                                'wname' => 'align',
                                                'enum' => 'BrigAlignment',
                                                'name' => 'align',
                                                'wtype' => 'EnumValRef<Brig::BrigAlignment,uint8_t>',
                                                'type' => 'BrigAlignment8_t',
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
                                                'size' => 3,
                                                'wname' => 'reserved',
                                                'skip' => 1,
                                                'type' => 'uint8_t',
                                                'wtype' => 'ValRef<uint8_t>'
                                              }
                                            ],
                                'align' => undef,
                                'enum' => 'BRIG_INST_MEM',
                                'name' => 'BrigInstMem'
                              },
             'BrigInstSeg' => {
                                'parent' => 'BrigInst',
                                'wname' => 'InstSeg',
                                'fields' => [
                                              {
                                                'wname' => 'size',
                                                'name' => 'size',
                                                'wtype' => 'ValRef<uint16_t>',
                                                'type' => 'uint16_t',
                                                'acc' => 'valRef'
                                              },
                                              {
                                                'wname' => 'kind',
                                                'enum' => 'BrigInstKinds',
                                                'name' => 'kind',
                                                'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                'type' => 'BrigInstKinds16_t',
                                                'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                'wname' => 'operand',
                                                'name' => 'operands',
                                                'wtype' => 'ItemRef<Operand>',
                                                'type' => 'BrigOperandOffset32_t',
                                                'defValue' => '0',
                                                'acc' => 'itemRef<Operand>',
                                                'size' => '5'
                                              },
                                              {
                                                'wname' => 'segment',
                                                'enum' => 'BrigSegment',
                                                'name' => 'segment',
                                                'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                'type' => 'BrigSegment8_t',
                                                'defValue' => '0',
                                                'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                              },
                                              {
                                                'name' => 'reserved',
                                                'defValue' => '0',
                                                'acc' => 'valRef',
                                                'size' => 3,
                                                'wname' => 'reserved',
                                                'skip' => 1,
                                                'type' => 'uint8_t',
                                                'wtype' => 'ValRef<uint8_t>'
                                              }
                                            ],
                                'align' => undef,
                                'enum' => 'BRIG_INST_SEG',
                                'name' => 'BrigInstSeg'
                              },
             'BrigDirectiveLabelInit' => {
                                           'wname' => 'DirectiveLabelInit',
                                           'parent' => 'BrigDirectiveCode',
                                           'fields' => [
                                                         {
                                                           'wname' => 'size',
                                                           'name' => 'size',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'acc' => 'valRef'
                                                         },
                                                         {
                                                           'wname' => 'kind',
                                                           'enum' => 'BrigDirectiveKinds',
                                                           'name' => 'kind',
                                                           'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                           'type' => 'BrigDirectiveKinds16_t',
                                                           'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                         },
                                                         {
                                                           'wname' => 'code',
                                                           'name' => 'code',
                                                           'wtype' => 'ItemRef<Inst>',
                                                           'type' => 'BrigCodeOffset32_t',
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<Inst>'
                                                         },
                                                         {
                                                           'wname' => 'elementCount',
                                                           'name' => 'labelCount',
                                                           'wtype' => 'ValRef<uint16_t>',
                                                           'type' => 'uint16_t',
                                                           'defValue' => '0',
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
                                                         },
                                                         {
                                                           'wspecial' => 'LabelInitList',
                                                           'name' => 'labels',
                                                           'defValue' => '0',
                                                           'acc' => 'itemRef<DirectiveLabel>',
                                                           'size' => '1',
                                                           'wname' => 'labels',
                                                           'type' => 'BrigDirectiveOffset32_t',
                                                           'wtype' => 'ItemRef<DirectiveLabel>'
                                                         }
                                                       ],
                                           'align' => undef,
                                           'enum' => 'BRIG_DIRECTIVE_LABEL_INIT',
                                           'name' => 'BrigDirectiveLabelInit'
                                         },
             'BrigDirectiveExecutable' => {
                                            'parent' => 'BrigDirectiveCallableBase',
                                            'align' => undef,
                                            'name' => 'BrigDirectiveExecutable',
                                            'children' => [
                                                            'BrigDirectiveKernel',
                                                            'BrigDirectiveFunction'
                                                          ],
                                            'comments' => [
                                                            '/// common ancestor class for kernel/function directives.'
                                                          ],
                                            'generic' => 'true',
                                            'wname' => 'DirectiveExecutable',
                                            'fields' => [
                                                          {
                                                            'wname' => 'size',
                                                            'name' => 'size',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'kind',
                                                            'enum' => 'BrigDirectiveKinds',
                                                            'name' => 'kind',
                                                            'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                            'type' => 'BrigDirectiveKinds16_t',
                                                            'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                          },
                                                          {
                                                            'wname' => 'code',
                                                            'name' => 'code',
                                                            'wtype' => 'ItemRef<Inst>',
                                                            'type' => 'BrigCodeOffset32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<Inst>'
                                                          },
                                                          {
                                                            'wname' => 'name',
                                                            'name' => 'name',
                                                            'wtype' => 'StrRef',
                                                            'type' => 'BrigStringOffset32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'strRef'
                                                          },
                                                          {
                                                            'wname' => 'inArgCount',
                                                            'name' => 'inArgCount',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'outArgCount',
                                                            'name' => 'outArgCount',
                                                            'wtype' => 'ValRef<uint16_t>',
                                                            'type' => 'uint16_t',
                                                            'acc' => 'valRef'
                                                          },
                                                          {
                                                            'wname' => 'firstInArg',
                                                            'name' => 'firstInArg',
                                                            'wtype' => 'ItemRef<Directive>',
                                                            'type' => 'BrigDirectiveOffset32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<Directive>'
                                                          },
                                                          {
                                                            'wname' => 'firstScopedDirective',
                                                            'name' => 'firstScopedDirective',
                                                            'wtype' => 'ItemRef<Directive>',
                                                            'type' => 'BrigDirectiveOffset32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<Directive>'
                                                          },
                                                          {
                                                            'wname' => 'nextTopLevelDirective',
                                                            'name' => 'nextTopLevelDirective',
                                                            'wtype' => 'ItemRef<Directive>',
                                                            'type' => 'BrigDirectiveOffset32_t',
                                                            'defValue' => '0',
                                                            'acc' => 'itemRef<Directive>'
                                                          },
                                                          {
                                                            'wname' => 'instCount',
                                                            'name' => 'instCount',
                                                            'wtype' => 'ValRef<uint32_t>',
                                                            'type' => 'uint32_t',
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
                                            'enum' => 'BRIG_DIRECTIVE_EXECUTABLE'
                                          },
             'BrigInstAtomicImage' => {
                                        'parent' => 'BrigInst',
                                        'wname' => 'InstAtomicImage',
                                        'fields' => [
                                                      {
                                                        'wname' => 'size',
                                                        'name' => 'size',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'kind',
                                                        'enum' => 'BrigInstKinds',
                                                        'name' => 'kind',
                                                        'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                        'type' => 'BrigInstKinds16_t',
                                                        'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                        'wname' => 'operand',
                                                        'name' => 'operands',
                                                        'wtype' => 'ItemRef<Operand>',
                                                        'type' => 'BrigOperandOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<Operand>',
                                                        'size' => '5'
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
                                        'enum' => 'BRIG_INST_ATOMIC_IMAGE',
                                        'name' => 'BrigInstAtomicImage'
                                      },
             'BrigOperandWavesize' => {
                                        'parent' => 'BrigOperand',
                                        'wname' => 'OperandWavesize',
                                        'fields' => [
                                                      {
                                                        'wname' => 'size',
                                                        'name' => 'size',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'kind',
                                                        'enum' => 'BrigOperandKinds',
                                                        'name' => 'kind',
                                                        'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                        'type' => 'BrigOperandKinds16_t',
                                                        'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                      }
                                                    ],
                                        'align' => undef,
                                        'enum' => 'BRIG_OPERAND_WAVESIZE',
                                        'name' => 'BrigOperandWavesize'
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
                                       'enum' => 'BRIG_SEG_CVT_MODIFIER',
                                       'name' => 'BrigSegCvtModifier',
                                       'standalone' => 'true'
                                     },
             'BrigDirectiveArgScopeStart' => {
                                               'wname' => 'DirectiveArgScopeStart',
                                               'parent' => 'BrigDirectiveCode',
                                               'fields' => [
                                                             {
                                                               'wname' => 'size',
                                                               'name' => 'size',
                                                               'wtype' => 'ValRef<uint16_t>',
                                                               'type' => 'uint16_t',
                                                               'acc' => 'valRef'
                                                             },
                                                             {
                                                               'wname' => 'kind',
                                                               'enum' => 'BrigDirectiveKinds',
                                                               'name' => 'kind',
                                                               'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                               'type' => 'BrigDirectiveKinds16_t',
                                                               'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                             },
                                                             {
                                                               'wname' => 'code',
                                                               'name' => 'code',
                                                               'wtype' => 'ItemRef<Inst>',
                                                               'type' => 'BrigCodeOffset32_t',
                                                               'defValue' => '0',
                                                               'acc' => 'itemRef<Inst>'
                                                             }
                                                           ],
                                               'align' => undef,
                                               'enum' => 'BRIG_DIRECTIVE_ARG_SCOPE_START',
                                               'name' => 'BrigDirectiveArgScopeStart'
                                             },
             'BrigInst' => {
                             'align' => undef,
                             'name' => 'BrigInst',
                             'children' => [
                                             'BrigInstSignal',
                                             'BrigInstMemFence',
                                             'BrigInstSegCvt',
                                             'BrigInstAddr',
                                             'BrigInstCvt',
                                             'BrigInstMod',
                                             'BrigInstBasic',
                                             'BrigInstAtomic',
                                             'BrigInstSourceType',
                                             'BrigInstBr',
                                             'BrigInstImage',
                                             'BrigInstMem',
                                             'BrigInstSeg',
                                             'BrigInstQueue',
                                             'BrigInstCmp',
                                             'BrigInstAtomicImage',
                                             'BrigInstLane'
                                           ],
                             'generic' => 'true',
                             'wname' => 'Inst',
                             'isroot' => 'true',
                             'fields' => [
                                           {
                                             'wname' => 'size',
                                             'name' => 'size',
                                             'wtype' => 'ValRef<uint16_t>',
                                             'type' => 'uint16_t',
                                             'acc' => 'valRef'
                                           },
                                           {
                                             'wname' => 'kind',
                                             'enum' => 'BrigInstKinds',
                                             'name' => 'kind',
                                             'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                             'type' => 'BrigInstKinds16_t',
                                             'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                             'wname' => 'operand',
                                             'name' => 'operands',
                                             'wtype' => 'ItemRef<Operand>',
                                             'type' => 'BrigOperandOffset32_t',
                                             'defValue' => '0',
                                             'acc' => 'itemRef<Operand>',
                                             'size' => '5'
                                           }
                                         ],
                             'enum' => 'BRIG_INST'
                           },
             'BrigSamplerModifier' => {
                                        'wname' => 'SamplerModifier',
                                        'fields' => [
                                                      {
                                                        'wname' => 'allBits',
                                                        'name' => 'allBits',
                                                        'wtype' => 'ValRef<uint8_t>',
                                                        'type' => 'BrigSamplerModifier8_t',
                                                        'defValue' => '0',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'filter',
                                                        'phantomof' => $structs->{'BrigSamplerModifier'}{'fields'}[0],
                                                        'name' => 'filter',
                                                        'wtype' => 'BFValRef<Brig::BrigSamplerFilter8_t,0,6>',
                                                        'type' => 'BrigSamplerFilter',
                                                        'acc' => 'bFValRef<Brig::BrigSamplerFilter8_t,0,6>'
                                                      },
                                                      {
                                                        'wname' => 'isUnnormalized',
                                                        'phantomof' => $structs->{'BrigSamplerModifier'}{'fields'}[0],
                                                        'name' => 'isUnnormalized',
                                                        'wtype' => 'BitValRef<6>',
                                                        'type' => 'bool',
                                                        'acc' => 'bitValRef<6>'
                                                      }
                                                    ],
                                        'isroot' => 'true',
                                        'align' => undef,
                                        'enum' => 'BRIG_SAMPLER_MODIFIER',
                                        'name' => 'BrigSamplerModifier',
                                        'standalone' => 'true'
                                      },
             'BrigDirectiveSamplerInit' => {
                                             'wname' => 'DirectiveSamplerInit',
                                             'parent' => 'BrigDirective',
                                             'fields' => [
                                                           {
                                                             'wname' => 'size',
                                                             'name' => 'size',
                                                             'wtype' => 'ValRef<uint16_t>',
                                                             'type' => 'uint16_t',
                                                             'acc' => 'valRef'
                                                           },
                                                           {
                                                             'wname' => 'kind',
                                                             'enum' => 'BrigDirectiveKinds',
                                                             'name' => 'kind',
                                                             'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                             'type' => 'BrigDirectiveKinds16_t',
                                                             'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                           },
                                                           {
                                                             'wname' => 'modifier',
                                                             'name' => 'modifier',
                                                             'wtype' => 'SamplerModifier',
                                                             'type' => 'BrigSamplerModifier',
                                                             'acc' => 'subItem<SamplerModifier>'
                                                           },
                                                           {
                                                             'wname' => 'boundaryU',
                                                             'enum' => 'BrigSamplerBoundaryMode',
                                                             'name' => 'boundaryU',
                                                             'wtype' => 'EnumValRef<Brig::BrigSamplerBoundaryMode,uint8_t>',
                                                             'type' => 'BrigSamplerBoundaryMode8_t',
                                                             'defValue' => 'Brig::BRIG_BOUNDARY_CLAMP',
                                                             'acc' => 'enumValRef<Brig::BrigSamplerBoundaryMode,uint8_t>'
                                                           },
                                                           {
                                                             'wname' => 'boundaryV',
                                                             'enum' => 'BrigSamplerBoundaryMode',
                                                             'name' => 'boundaryV',
                                                             'wtype' => 'EnumValRef<Brig::BrigSamplerBoundaryMode,uint8_t>',
                                                             'type' => 'BrigSamplerBoundaryMode8_t',
                                                             'defValue' => 'Brig::BRIG_BOUNDARY_CLAMP',
                                                             'acc' => 'enumValRef<Brig::BrigSamplerBoundaryMode,uint8_t>'
                                                           },
                                                           {
                                                             'wname' => 'boundaryW',
                                                             'enum' => 'BrigSamplerBoundaryMode',
                                                             'name' => 'boundaryW',
                                                             'wtype' => 'EnumValRef<Brig::BrigSamplerBoundaryMode,uint8_t>',
                                                             'type' => 'BrigSamplerBoundaryMode8_t',
                                                             'defValue' => 'Brig::BRIG_BOUNDARY_CLAMP',
                                                             'acc' => 'enumValRef<Brig::BrigSamplerBoundaryMode,uint8_t>'
                                                           }
                                                         ],
                                             'align' => undef,
                                             'enum' => 'BRIG_DIRECTIVE_SAMPLER_INIT',
                                             'name' => 'BrigDirectiveSamplerInit'
                                           },
             'BrigBlockNumeric' => {
                                     'wname' => 'BlockNumeric',
                                     'parent' => 'BrigDirective',
                                     'fields' => [
                                                   {
                                                     'wname' => 'size',
                                                     'name' => 'size',
                                                     'wtype' => 'ValRef<uint16_t>',
                                                     'type' => 'uint16_t',
                                                     'acc' => 'valRef'
                                                   },
                                                   {
                                                     'wname' => 'kind',
                                                     'enum' => 'BrigDirectiveKinds',
                                                     'name' => 'kind',
                                                     'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                     'type' => 'BrigDirectiveKinds16_t',
                                                     'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                   },
                                                   {
                                                     'wname' => 'type',
                                                     'name' => 'type',
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
                                                   },
                                                   {
                                                     'wname' => 'elementCount',
                                                     'name' => 'elementCount',
                                                     'wtype' => 'ValRef<uint32_t>',
                                                     'type' => 'uint32_t',
                                                     'defValue' => '0',
                                                     'acc' => 'valRef'
                                                   },
                                                   {
                                                     'wname' => 'data',
                                                     'name' => 'data',
                                                     'wtype' => 'DataItemRef',
                                                     'type' => 'BrigDataOffset32_t',
                                                     'acc' => 'dataItemRef',
                                                     'novisit' => 'true'
                                                   },
                                                   {
                                                     'wspecial' => 'DataItemRefT',
                                                     'name' => 'dataAs',
                                                     'acc' => 'valRef',
                                                     'novisit' => 'true',
                                                     'phantomof' => $structs->{'BrigBlockNumeric'}{'fields'}[5],
                                                     'wname' => 'dataAs',
                                                     'type' => 'BrigDataOffset32_t',
                                                     'wtype' => 'ValRef<uint32_t>',
                                                     'wspecialgeneric' => 'true'
                                                   }
                                                 ],
                                     'align' => undef,
                                     'enum' => 'BRIG_DIRECTIVE_BLOCK_NUMERIC',
                                     'name' => 'BrigBlockNumeric',
                                     'comments' => [
                                                     '/// numeric data inside block.'
                                                   ]
                                   },
             'BrigInstAddr' => {
                                 'parent' => 'BrigInst',
                                 'wname' => 'InstAddr',
                                 'fields' => [
                                               {
                                                 'wname' => 'size',
                                                 'name' => 'size',
                                                 'wtype' => 'ValRef<uint16_t>',
                                                 'type' => 'uint16_t',
                                                 'acc' => 'valRef'
                                               },
                                               {
                                                 'wname' => 'kind',
                                                 'enum' => 'BrigInstKinds',
                                                 'name' => 'kind',
                                                 'wtype' => 'EnumValRef<Brig::BrigInstKinds,uint16_t>',
                                                 'type' => 'BrigInstKinds16_t',
                                                 'acc' => 'enumValRef<Brig::BrigInstKinds,uint16_t>'
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
                                                 'wname' => 'operand',
                                                 'name' => 'operands',
                                                 'wtype' => 'ItemRef<Operand>',
                                                 'type' => 'BrigOperandOffset32_t',
                                                 'defValue' => '0',
                                                 'acc' => 'itemRef<Operand>',
                                                 'size' => '5'
                                               },
                                               {
                                                 'wname' => 'segment',
                                                 'enum' => 'BrigSegment',
                                                 'name' => 'segment',
                                                 'wtype' => 'EnumValRef<Brig::BrigSegment,uint8_t>',
                                                 'type' => 'BrigSegment8_t',
                                                 'defValue' => '0',
                                                 'acc' => 'enumValRef<Brig::BrigSegment,uint8_t>'
                                               },
                                               {
                                                 'name' => 'reserved',
                                                 'defValue' => '0',
                                                 'acc' => 'valRef',
                                                 'size' => 3,
                                                 'wname' => 'reserved',
                                                 'skip' => 1,
                                                 'type' => 'uint8_t',
                                                 'wtype' => 'ValRef<uint8_t>'
                                               }
                                             ],
                                 'align' => undef,
                                 'enum' => 'BRIG_INST_ADDR',
                                 'name' => 'BrigInstAddr'
                               },
             'BrigOperandAddress' => {
                                       'parent' => 'BrigOperand',
                                       'wname' => 'OperandAddress',
                                       'fields' => [
                                                     {
                                                       'wname' => 'size',
                                                       'name' => 'size',
                                                       'wtype' => 'ValRef<uint16_t>',
                                                       'type' => 'uint16_t',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'kind',
                                                       'enum' => 'BrigOperandKinds',
                                                       'name' => 'kind',
                                                       'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                       'type' => 'BrigOperandKinds16_t',
                                                       'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                     },
                                                     {
                                                       'wname' => 'symbol',
                                                       'name' => 'symbol',
                                                       'wtype' => 'ItemRef<DirectiveVariable>',
                                                       'type' => 'BrigDirectiveOffset32_t',
                                                       'defValue' => '0',
                                                       'acc' => 'itemRef<DirectiveVariable>'
                                                     },
                                                     {
                                                       'wname' => 'reg',
                                                       'name' => 'reg',
                                                       'wtype' => 'StrRef',
                                                       'type' => 'BrigStringOffset32_t',
                                                       'defValue' => '0',
                                                       'acc' => 'strRef'
                                                     },
                                                     {
                                                       'wname' => 'offsetLo',
                                                       'name' => 'offsetLo',
                                                       'wtype' => 'ValRef<uint32_t>',
                                                       'type' => 'uint32_t',
                                                       'acc' => 'valRef'
                                                     },
                                                     {
                                                       'wname' => 'offset',
                                                       'phantomof' => $structs->{'BrigOperandAddress'}{'fields'}[4],
                                                       'name' => 'offset',
                                                       'wtype' => 'ValRef<uint64_t>',
                                                       'type' => 'uint64_t',
                                                       'acc' => 'reinterpretValRef<uint64_t>'
                                                     },
                                                     {
                                                       'wname' => 'offsetHi',
                                                       'name' => 'offsetHi',
                                                       'wtype' => 'ValRef<uint32_t>',
                                                       'type' => 'uint32_t',
                                                       'acc' => 'valRef'
                                                     }
                                                   ],
                                       'align' => undef,
                                       'enum' => 'BRIG_OPERAND_ADDRESS',
                                       'name' => 'BrigOperandAddress'
                                     },
             'BrigOperandLabelRef' => {
                                        'wname' => 'OperandLabelRef',
                                        'parent' => 'BrigOperandRef',
                                        'fields' => [
                                                      {
                                                        'wname' => 'size',
                                                        'name' => 'size',
                                                        'wtype' => 'ValRef<uint16_t>',
                                                        'type' => 'uint16_t',
                                                        'acc' => 'valRef'
                                                      },
                                                      {
                                                        'wname' => 'kind',
                                                        'enum' => 'BrigOperandKinds',
                                                        'name' => 'kind',
                                                        'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                        'type' => 'BrigOperandKinds16_t',
                                                        'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                      },
                                                      {
                                                        'wname' => 'label',
                                                        'name' => 'label',
                                                        'wtype' => 'ItemRef<DirectiveLabel>',
                                                        'type' => 'BrigDirectiveOffset32_t',
                                                        'defValue' => '0',
                                                        'acc' => 'itemRef<DirectiveLabel>'
                                                      }
                                                    ],
                                        'align' => undef,
                                        'enum' => 'BRIG_OPERAND_LABEL_REF',
                                        'name' => 'BrigOperandLabelRef'
                                      },
             'BrigDirectiveComment' => {
                                         'wname' => 'DirectiveComment',
                                         'parent' => 'BrigDirectiveCode',
                                         'fields' => [
                                                       {
                                                         'wname' => 'size',
                                                         'name' => 'size',
                                                         'wtype' => 'ValRef<uint16_t>',
                                                         'type' => 'uint16_t',
                                                         'acc' => 'valRef'
                                                       },
                                                       {
                                                         'wname' => 'kind',
                                                         'enum' => 'BrigDirectiveKinds',
                                                         'name' => 'kind',
                                                         'wtype' => 'EnumValRef<Brig::BrigDirectiveKinds,uint16_t>',
                                                         'type' => 'BrigDirectiveKinds16_t',
                                                         'acc' => 'enumValRef<Brig::BrigDirectiveKinds,uint16_t>'
                                                       },
                                                       {
                                                         'wname' => 'code',
                                                         'name' => 'code',
                                                         'wtype' => 'ItemRef<Inst>',
                                                         'type' => 'BrigCodeOffset32_t',
                                                         'defValue' => '0',
                                                         'acc' => 'itemRef<Inst>'
                                                       },
                                                       {
                                                         'wname' => 'name',
                                                         'name' => 'name',
                                                         'wtype' => 'StrRef',
                                                         'type' => 'BrigStringOffset32_t',
                                                         'defValue' => '0',
                                                         'acc' => 'strRef'
                                                       }
                                                     ],
                                         'align' => undef,
                                         'enum' => 'BRIG_DIRECTIVE_COMMENT',
                                         'name' => 'BrigDirectiveComment',
                                         'comments' => [
                                                         '/// comment directive.'
                                                       ]
                                       },
             'BrigOperandReg' => {
                                   'parent' => 'BrigOperand',
                                   'wname' => 'OperandReg',
                                   'fields' => [
                                                 {
                                                   'wname' => 'size',
                                                   'name' => 'size',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'uint16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'kind',
                                                   'enum' => 'BrigOperandKinds',
                                                   'name' => 'kind',
                                                   'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                   'type' => 'BrigOperandKinds16_t',
                                                   'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                 },
                                                 {
                                                   'wname' => 'reg',
                                                   'name' => 'reg',
                                                   'wtype' => 'StrRef',
                                                   'type' => 'BrigStringOffset32_t',
                                                   'defValue' => '0',
                                                   'acc' => 'strRef'
                                                 }
                                               ],
                                   'align' => undef,
                                   'enum' => 'BRIG_OPERAND_REG',
                                   'name' => 'BrigOperandReg'
                                 },
             'BrigDirectiveBase' => {
                                      'fields' => [
                                                    {
                                                      'name' => 'size',
                                                      'type' => 'uint16_t'
                                                    },
                                                    {
                                                      'name' => 'kind',
                                                      'type' => 'BrigDirectiveKinds16_t'
                                                    },
                                                    {
                                                      'name' => 'code',
                                                      'type' => 'BrigCodeOffset32_t'
                                                    }
                                                  ],
                                      'align' => undef,
                                      'nowrap' => 'true',
                                      'name' => 'BrigDirectiveBase'
                                    },
             'BrigOperandRef' => {
                                   'parent' => 'BrigOperand',
                                   'align' => undef,
                                   'name' => 'BrigOperandRef',
                                   'children' => [
                                                   'BrigOperandSignatureRef',
                                                   'BrigOperandFbarrierRef',
                                                   'BrigOperandFunctionRef',
                                                   'BrigOperandLabelRef',
                                                   'BrigOperandLabelTargetsRef',
                                                   'BrigOperandLabelVariableRef'
                                                 ],
                                   'generic' => 'true',
                                   'wname' => 'OperandRef',
                                   'fields' => [
                                                 {
                                                   'wname' => 'size',
                                                   'name' => 'size',
                                                   'wtype' => 'ValRef<uint16_t>',
                                                   'type' => 'uint16_t',
                                                   'acc' => 'valRef'
                                                 },
                                                 {
                                                   'wname' => 'kind',
                                                   'enum' => 'BrigOperandKinds',
                                                   'name' => 'kind',
                                                   'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                   'type' => 'BrigOperandKinds16_t',
                                                   'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                 },
                                                 {
                                                   'wname' => 'ref',
                                                   'name' => 'ref',
                                                   'wtype' => 'ItemRef<Directive>',
                                                   'type' => 'BrigDirectiveOffset32_t',
                                                   'defValue' => '0',
                                                   'acc' => 'itemRef<Directive>'
                                                 }
                                               ],
                                   'enum' => 'BRIG_OPERAND_REF'
                                 },
             'BrigOperandLabelVariableRef' => {
                                                'wname' => 'OperandLabelVariableRef',
                                                'parent' => 'BrigOperandRef',
                                                'fields' => [
                                                              {
                                                                'wname' => 'size',
                                                                'name' => 'size',
                                                                'wtype' => 'ValRef<uint16_t>',
                                                                'type' => 'uint16_t',
                                                                'acc' => 'valRef'
                                                              },
                                                              {
                                                                'wname' => 'kind',
                                                                'enum' => 'BrigOperandKinds',
                                                                'name' => 'kind',
                                                                'wtype' => 'EnumValRef<Brig::BrigOperandKinds,uint16_t>',
                                                                'type' => 'BrigOperandKinds16_t',
                                                                'acc' => 'enumValRef<Brig::BrigOperandKinds,uint16_t>'
                                                              },
                                                              {
                                                                'wname' => 'symbol',
                                                                'name' => 'symbol',
                                                                'wtype' => 'ItemRef<DirectiveVariable>',
                                                                'type' => 'BrigDirectiveOffset32_t',
                                                                'defValue' => '0',
                                                                'acc' => 'itemRef<DirectiveVariable>'
                                                              }
                                                            ],
                                                'align' => undef,
                                                'enum' => 'BRIG_OPERAND_LABEL_VARIABLE_REF',
                                                'name' => 'BrigOperandLabelVariableRef'
                                              }
           };
