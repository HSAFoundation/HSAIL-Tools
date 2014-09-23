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
unsigned align2num(unsigned arg);
const char* align2str(unsigned arg);
Brig::BrigAlignment num2align(uint64_t arg);
const char* allocation2str(unsigned arg);
const char* atomicOperation2str(unsigned arg);
const char* compareOperation2str(unsigned arg);
const char* controlDirective2str(unsigned arg);
const char* imageChannelOrder2str(unsigned arg);
const char* imageChannelType2str(unsigned arg);
bool isBrigGeometryDepth(unsigned geo);
unsigned getBrigGeometryDim(unsigned geo);
const char* imageGeometry2str(unsigned arg);
const char* imageQuery2str(unsigned arg);
bool isBodyOnly(Directive d);
bool isToplevelOnly(Directive d);
const char* kinds2str(unsigned arg);
int size_of_brig_record(unsigned arg);
const char* linkage2str(unsigned arg);
const char* machineModel2str(unsigned arg);
const char* memoryFenceSegments2str(unsigned arg);
const char* memoryOrder2str(unsigned arg);
const char* memoryScope2str(unsigned arg);
const char* memoryScope22str(unsigned arg);
bool instHasType(Brig::BrigOpcode16_t arg);
const char* opcode2str(unsigned arg);
int instNumDstOperands(Brig::BrigOpcode16_t arg);
const char* pack2str(unsigned arg);
const char* profile2str(unsigned arg);
unsigned getRegBits(Brig::BrigRegisterKind16_t arg);
const char* registerKind2str(unsigned arg);
const char* round2str(unsigned arg);
const char* samplerAddressing2str(unsigned arg);
const char* samplerCoordNormalization2str(unsigned arg);
const char* samplerFilter2str(unsigned arg);
const char* samplerQuery2str(unsigned arg);
const char* sectionIndex2str(unsigned arg);
const char* segment2str(unsigned arg);
const char* typeX2str(unsigned arg);
unsigned getBrigTypeNumBits(unsigned arg);
unsigned getBrigTypeNumBytes(unsigned arg);
const char* anyEnum2str( Brig::BrigAlignment arg );
const char* anyEnum2str( Brig::BrigAllocation arg );
const char* anyEnum2str( Brig::BrigAluModifierMask arg );
const char* anyEnum2str( Brig::BrigAtomicOperation arg );
const char* anyEnum2str( Brig::BrigCompareOperation arg );
const char* anyEnum2str( Brig::BrigControlDirective arg );
const char* anyEnum2str( Brig::BrigImageChannelOrder arg );
const char* anyEnum2str( Brig::BrigImageChannelType arg );
const char* anyEnum2str( Brig::BrigImageGeometry arg );
const char* anyEnum2str( Brig::BrigImageQuery arg );
const char* anyEnum2str( Brig::BrigKinds arg );
const char* anyEnum2str( Brig::BrigLinkage arg );
const char* anyEnum2str( Brig::BrigMachineModel arg );
const char* anyEnum2str( Brig::BrigMemoryFenceSegments arg );
const char* anyEnum2str( Brig::BrigMemoryModifierMask arg );
const char* anyEnum2str( Brig::BrigMemoryOrder arg );
const char* anyEnum2str( Brig::BrigMemoryScope arg );
const char* anyEnum2str( Brig::BrigMemoryScope2 arg );
const char* anyEnum2str( Brig::BrigOpcode arg );
const char* anyEnum2str( Brig::BrigPack arg );
const char* anyEnum2str( Brig::BrigProfile arg );
const char* anyEnum2str( Brig::BrigRegisterKind arg );
const char* anyEnum2str( Brig::BrigRound arg );
const char* anyEnum2str( Brig::BrigSamplerAddressing arg );
const char* anyEnum2str( Brig::BrigSamplerCoordNormalization arg );
const char* anyEnum2str( Brig::BrigSamplerFilter arg );
const char* anyEnum2str( Brig::BrigSamplerQuery arg );
const char* anyEnum2str( Brig::BrigSectionIndex arg );
const char* anyEnum2str( Brig::BrigSegCvtModifierMask arg );
const char* anyEnum2str( Brig::BrigSegment arg );
const char* anyEnum2str( Brig::BrigTypeX arg );
const char* anyEnum2str( Brig::BrigWidth arg );
inline ValRef<uint16_t> AluModifier::allBits() { return valRef(&brig()->allBits); }
inline BFValRef<Brig::BrigRound8_t,0,5> AluModifier::round() { return bFValRef<Brig::BrigRound8_t,0,5>(&brig()->allBits); }
inline BitValRef<5> AluModifier::ftz() { return bitValRef<5>(&brig()->allBits); }
inline StrRef DirectiveComment::name() { return strRef(&brig()->name); }
inline EnumValRef<Brig::BrigControlDirective,uint16_t> DirectiveControl::control() { return enumValRef<Brig::BrigControlDirective,uint16_t>(&brig()->control); }
inline ListRef<Operand> DirectiveControl::operands() { return listRef<Operand>(&brig()->operands); }
inline StrRef DirectiveExecutable::name() { return strRef(&brig()->name); }
inline ValRef<uint16_t> DirectiveExecutable::outArgCount() { return valRef(&brig()->outArgCount); }
inline ValRef<uint16_t> DirectiveExecutable::inArgCount() { return valRef(&brig()->inArgCount); }
inline ItemRef<Code> DirectiveExecutable::firstInArg() { return itemRef<Code>(&brig()->firstInArg); }
inline ItemRef<Code> DirectiveExecutable::firstCodeBlockEntry() { return itemRef<Code>(&brig()->firstCodeBlockEntry); }
inline ItemRef<Code> DirectiveExecutable::nextModuleEntry() { return itemRef<Code>(&brig()->nextModuleEntry); }
inline ValRef<uint32_t> DirectiveExecutable::codeBlockEntryCount() { return valRef(&brig()->codeBlockEntryCount); }
inline ExecutableModifier DirectiveExecutable::modifier() { return subItem<ExecutableModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigLinkage,uint8_t> DirectiveExecutable::linkage() { return enumValRef<Brig::BrigLinkage,uint8_t>(&brig()->linkage); }
inline StrRef DirectiveExtension::name() { return strRef(&brig()->name); }
inline StrRef DirectiveFbarrier::name() { return strRef(&brig()->name); }
inline ExecutableModifier DirectiveFbarrier::modifier() { return subItem<ExecutableModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigLinkage,uint8_t> DirectiveFbarrier::linkage() { return enumValRef<Brig::BrigLinkage,uint8_t>(&brig()->linkage); }
inline StrRef DirectiveLabel::name() { return strRef(&brig()->name); }
inline StrRef DirectiveLoc::filename() { return strRef(&brig()->filename); }
inline ValRef<uint32_t> DirectiveLoc::line() { return valRef(&brig()->line); }
inline ValRef<uint32_t> DirectiveLoc::column() { return valRef(&brig()->column); }
inline ListRef<Operand> DirectivePragma::operands() { return listRef<Operand>(&brig()->operands); }
inline StrRef DirectiveVariable::name() { return strRef(&brig()->name); }
inline ItemRef<Operand> DirectiveVariable::init() { return itemRef<Operand>(&brig()->init); }
inline ValRef<uint16_t> DirectiveVariable::type() { return valRef(&brig()->type); }
inline EnumValRef<Brig::BrigSegment,uint8_t> DirectiveVariable::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline EnumValRef<Brig::BrigAlignment,uint8_t> DirectiveVariable::align() { return enumValRef<Brig::BrigAlignment,uint8_t>(&brig()->align); }
inline UInt64 DirectiveVariable::dim() { return subItem<UInt64>(&brig()->dim); }
inline VariableModifier DirectiveVariable::modifier() { return subItem<VariableModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigLinkage,uint8_t> DirectiveVariable::linkage() { return enumValRef<Brig::BrigLinkage,uint8_t>(&brig()->linkage); }
inline EnumValRef<Brig::BrigAllocation,uint8_t> DirectiveVariable::allocation() { return enumValRef<Brig::BrigAllocation,uint8_t>(&brig()->allocation); }
inline ValRef<uint32_t> DirectiveVersion::hsailMajor() { return valRef(&brig()->hsailMajor); }
inline ValRef<uint32_t> DirectiveVersion::hsailMinor() { return valRef(&brig()->hsailMinor); }
inline ValRef<uint32_t> DirectiveVersion::brigMajor() { return valRef(&brig()->brigMajor); }
inline ValRef<uint32_t> DirectiveVersion::brigMinor() { return valRef(&brig()->brigMinor); }
inline EnumValRef<Brig::BrigProfile,uint8_t> DirectiveVersion::profile() { return enumValRef<Brig::BrigProfile,uint8_t>(&brig()->profile); }
inline EnumValRef<Brig::BrigMachineModel,uint8_t> DirectiveVersion::machineModel() { return enumValRef<Brig::BrigMachineModel,uint8_t>(&brig()->machineModel); }
inline EnumValRef<Brig::BrigOpcode,uint16_t> Inst::opcode() { return enumValRef<Brig::BrigOpcode,uint16_t>(&brig()->opcode); }
inline ValRef<uint16_t> Inst::type() { return valRef(&brig()->type); }
inline ListRef<Operand> Inst::operands() { return listRef<Operand>(&brig()->operands); }
inline Operand Inst::operand(int index) { return operands()[index]; }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstAddr::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstAtomic::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline EnumValRef<Brig::BrigMemoryOrder,uint8_t> InstAtomic::memoryOrder() { return enumValRef<Brig::BrigMemoryOrder,uint8_t>(&brig()->memoryOrder); }
inline EnumValRef<Brig::BrigMemoryScope,uint8_t> InstAtomic::memoryScope() { return enumValRef<Brig::BrigMemoryScope,uint8_t>(&brig()->memoryScope); }
inline EnumValRef<Brig::BrigAtomicOperation,uint8_t> InstAtomic::atomicOperation() { return enumValRef<Brig::BrigAtomicOperation,uint8_t>(&brig()->atomicOperation); }
inline ValRef<uint8_t> InstAtomic::equivClass() { return valRef(&brig()->equivClass); }
inline EnumValRef<Brig::BrigWidth,uint8_t> InstBr::width() { return enumValRef<Brig::BrigWidth,uint8_t>(&brig()->width); }
inline ValRef<uint16_t> InstCmp::sourceType() { return valRef(&brig()->sourceType); }
inline AluModifier InstCmp::modifier() { return subItem<AluModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigCompareOperation,uint8_t> InstCmp::compare() { return enumValRef<Brig::BrigCompareOperation,uint8_t>(&brig()->compare); }
inline EnumValRef<Brig::BrigPack,uint8_t> InstCmp::pack() { return enumValRef<Brig::BrigPack,uint8_t>(&brig()->pack); }
inline ValRef<uint16_t> InstCvt::sourceType() { return valRef(&brig()->sourceType); }
inline AluModifier InstCvt::modifier() { return subItem<AluModifier>(&brig()->modifier); }
inline ValRef<uint16_t> InstImage::imageType() { return valRef(&brig()->imageType); }
inline ValRef<uint16_t> InstImage::coordType() { return valRef(&brig()->coordType); }
inline EnumValRef<Brig::BrigImageGeometry,uint8_t> InstImage::geometry() { return enumValRef<Brig::BrigImageGeometry,uint8_t>(&brig()->geometry); }
inline ValRef<uint8_t> InstImage::equivClass() { return valRef(&brig()->equivClass); }
inline ValRef<uint16_t> InstLane::sourceType() { return valRef(&brig()->sourceType); }
inline EnumValRef<Brig::BrigWidth,uint8_t> InstLane::width() { return enumValRef<Brig::BrigWidth,uint8_t>(&brig()->width); }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstMem::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline EnumValRef<Brig::BrigAlignment,uint8_t> InstMem::align() { return enumValRef<Brig::BrigAlignment,uint8_t>(&brig()->align); }
inline ValRef<uint8_t> InstMem::equivClass() { return valRef(&brig()->equivClass); }
inline EnumValRef<Brig::BrigWidth,uint8_t> InstMem::width() { return enumValRef<Brig::BrigWidth,uint8_t>(&brig()->width); }
inline MemoryModifier InstMem::modifier() { return subItem<MemoryModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigMemoryOrder,uint8_t> InstMemFence::memoryOrder() { return enumValRef<Brig::BrigMemoryOrder,uint8_t>(&brig()->memoryOrder); }
inline EnumValRef<Brig::BrigMemoryScope,uint8_t> InstMemFence::globalSegmentMemoryScope() { return enumValRef<Brig::BrigMemoryScope,uint8_t>(&brig()->globalSegmentMemoryScope); }
inline EnumValRef<Brig::BrigMemoryScope,uint8_t> InstMemFence::groupSegmentMemoryScope() { return enumValRef<Brig::BrigMemoryScope,uint8_t>(&brig()->groupSegmentMemoryScope); }
inline EnumValRef<Brig::BrigMemoryScope,uint8_t> InstMemFence::imageSegmentMemoryScope() { return enumValRef<Brig::BrigMemoryScope,uint8_t>(&brig()->imageSegmentMemoryScope); }
inline AluModifier InstMod::modifier() { return subItem<AluModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigPack,uint8_t> InstMod::pack() { return enumValRef<Brig::BrigPack,uint8_t>(&brig()->pack); }
inline ValRef<uint16_t> InstQueryImage::imageType() { return valRef(&brig()->imageType); }
inline EnumValRef<Brig::BrigImageGeometry,uint8_t> InstQueryImage::geometry() { return enumValRef<Brig::BrigImageGeometry,uint8_t>(&brig()->geometry); }
inline EnumValRef<Brig::BrigImageQuery,uint8_t> InstQueryImage::imageQuery() { return enumValRef<Brig::BrigImageQuery,uint8_t>(&brig()->imageQuery); }
inline EnumValRef<Brig::BrigSamplerQuery,uint8_t> InstQuerySampler::samplerQuery() { return enumValRef<Brig::BrigSamplerQuery,uint8_t>(&brig()->samplerQuery); }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstQueue::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline EnumValRef<Brig::BrigMemoryOrder,uint8_t> InstQueue::memoryOrder() { return enumValRef<Brig::BrigMemoryOrder,uint8_t>(&brig()->memoryOrder); }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstSeg::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline ValRef<uint16_t> InstSegCvt::sourceType() { return valRef(&brig()->sourceType); }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstSegCvt::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline SegCvtModifier InstSegCvt::modifier() { return subItem<SegCvtModifier>(&brig()->modifier); }
inline ValRef<uint16_t> InstSignal::signalType() { return valRef(&brig()->signalType); }
inline EnumValRef<Brig::BrigMemoryOrder,uint8_t> InstSignal::memoryOrder() { return enumValRef<Brig::BrigMemoryOrder,uint8_t>(&brig()->memoryOrder); }
inline EnumValRef<Brig::BrigAtomicOperation,uint8_t> InstSignal::signalOperation() { return enumValRef<Brig::BrigAtomicOperation,uint8_t>(&brig()->signalOperation); }
inline ValRef<uint16_t> InstSourceType::sourceType() { return valRef(&brig()->sourceType); }
inline ValRef<uint8_t> ExecutableModifier::allBits() { return valRef(&brig()->allBits); }
inline BitValRef<0> ExecutableModifier::isDefinition() { return bitValRef<0>(&brig()->allBits); }
inline ValRef<uint8_t> MemoryModifier::allBits() { return valRef(&brig()->allBits); }
inline BitValRef<0> MemoryModifier::isConst() { return bitValRef<0>(&brig()->allBits); }
inline ItemRef<DirectiveVariable> OperandAddress::symbol() { return itemRef<DirectiveVariable>(&brig()->symbol); }
inline ItemRef<OperandReg> OperandAddress::reg() { return itemRef<OperandReg>(&brig()->reg); }
inline UInt64 OperandAddress::offset() { return subItem<UInt64>(&brig()->offset); }
inline ListRef<Code> OperandCodeList::elements() { return listRef<Code>(&brig()->elements); }
inline unsigned OperandCodeList::elementCount() { return elements().size(); }
inline Code OperandCodeList::elements(int index) { return elements()[index]; }
inline ItemRef<Code> OperandCodeRef::ref() { return itemRef<Code>(&brig()->ref); }
inline StrRef OperandData::data() { return strRef(&brig()->data); }
inline UInt64 OperandImageProperties::width() { return subItem<UInt64>(&brig()->width); }
inline UInt64 OperandImageProperties::height() { return subItem<UInt64>(&brig()->height); }
inline UInt64 OperandImageProperties::depth() { return subItem<UInt64>(&brig()->depth); }
inline UInt64 OperandImageProperties::array() { return subItem<UInt64>(&brig()->array); }
inline EnumValRef<Brig::BrigImageGeometry,uint8_t> OperandImageProperties::geometry() { return enumValRef<Brig::BrigImageGeometry,uint8_t>(&brig()->geometry); }
inline EnumValRef<Brig::BrigImageChannelOrder,uint8_t> OperandImageProperties::channelOrder() { return enumValRef<Brig::BrigImageChannelOrder,uint8_t>(&brig()->channelOrder); }
inline EnumValRef<Brig::BrigImageChannelType,uint8_t> OperandImageProperties::channelType() { return enumValRef<Brig::BrigImageChannelType,uint8_t>(&brig()->channelType); }
inline ListRef<Operand> OperandOperandList::elements() { return listRef<Operand>(&brig()->elements); }
inline unsigned OperandOperandList::elementCount() { return elements().size(); }
inline Operand OperandOperandList::elements(int index) { return elements()[index]; }
inline EnumValRef<Brig::BrigRegisterKind,uint16_t> OperandReg::regKind() { return enumValRef<Brig::BrigRegisterKind,uint16_t>(&brig()->regKind); }
inline ValRef<uint16_t> OperandReg::regNum() { return valRef(&brig()->regNum); }
inline EnumValRef<Brig::BrigSamplerCoordNormalization,uint8_t> OperandSamplerProperties::coord() { return enumValRef<Brig::BrigSamplerCoordNormalization,uint8_t>(&brig()->coord); }
inline EnumValRef<Brig::BrigSamplerFilter,uint8_t> OperandSamplerProperties::filter() { return enumValRef<Brig::BrigSamplerFilter,uint8_t>(&brig()->filter); }
inline EnumValRef<Brig::BrigSamplerAddressing,uint8_t> OperandSamplerProperties::addressing() { return enumValRef<Brig::BrigSamplerAddressing,uint8_t>(&brig()->addressing); }
inline StrRef OperandString::string() { return strRef(&brig()->string); }
inline ValRef<uint8_t> SegCvtModifier::allBits() { return valRef(&brig()->allBits); }
inline BitValRef<0> SegCvtModifier::isNoNull() { return bitValRef<0>(&brig()->allBits); }
inline ValRef<uint32_t> UInt64::lo() { return valRef(&brig()->lo); }
inline ValRef<uint32_t> UInt64::hi() { return valRef(&brig()->hi); }
inline UInt64& UInt64::operator=(uint64_t rhs) { lo() = (uint32_t)rhs; hi() = (uint32_t)(rhs >> 32); return *this; }
inline UInt64::operator uint64_t() { return ((uint64_t)hi()) << 32 | lo(); }
inline ValRef<uint8_t> VariableModifier::allBits() { return valRef(&brig()->allBits); }
inline BitValRef<0> VariableModifier::isDefinition() { return bitValRef<0>(&brig()->allBits); }
inline BitValRef<1> VariableModifier::isConst() { return bitValRef<1>(&brig()->allBits); }
inline BitValRef<2> VariableModifier::isArray() { return bitValRef<2>(&brig()->allBits); }
inline BitValRef<3> VariableModifier::isFlexArray() { return bitValRef<3>(&brig()->allBits); }
