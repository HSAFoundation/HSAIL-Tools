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
const char* atomicOperation2str(unsigned arg);
const char* compareOperation2str(unsigned arg);
const char* controlDirective2str(unsigned arg);
int size_of_directive(unsigned arg);
bool isToplevelOnly(Directive d);
bool isBodyOnly(Directive d);
const char* imageFormat2str(unsigned arg);
const char* imageGeometry2str(unsigned arg);
const char* imageOrder2str(unsigned arg);
int size_of_inst(unsigned arg);
const char* linkage2str(unsigned arg);
const char* machineModel2str(unsigned arg);
const char* memoryFence2str(unsigned arg);
const char* memorySemantic2str(unsigned arg);
const char* opcode2str(unsigned arg);
bool doesSupportMemorySemantic(Brig::BrigOpcode16_t arg);
Brig::BrigMemoryFence8_t getDefFence(Brig::BrigOpcode16_t arg);
int size_of_operand(unsigned arg);
const char* pack2str(unsigned arg);
const char* profile2str(unsigned arg);
const char* round2str(unsigned arg);
const char* samplerBoundaryMode2str(unsigned arg);
const char* samplerFilter2str(unsigned arg);
const char* segment2str(unsigned arg);
int brigtype_get_length(unsigned arg);
const char* typeX2str(unsigned arg);
const char* anyEnum2str( Brig::BrigAluModifierMask arg );
const char* anyEnum2str( Brig::BrigAtomicOperation arg );
const char* anyEnum2str( Brig::BrigCompareOperation arg );
const char* anyEnum2str( Brig::BrigControlDirective arg );
const char* anyEnum2str( Brig::BrigDirectiveKinds arg );
const char* anyEnum2str( Brig::BrigImageFormat arg );
const char* anyEnum2str( Brig::BrigImageGeometry arg );
const char* anyEnum2str( Brig::BrigImageOrder arg );
const char* anyEnum2str( Brig::BrigInstKinds arg );
const char* anyEnum2str( Brig::BrigLinkage arg );
const char* anyEnum2str( Brig::BrigMachineModel arg );
const char* anyEnum2str( Brig::BrigMemoryFence arg );
const char* anyEnum2str( Brig::BrigMemoryModifierMask arg );
const char* anyEnum2str( Brig::BrigMemorySemantic arg );
const char* anyEnum2str( Brig::BrigOpcode arg );
const char* anyEnum2str( Brig::BrigOperandKinds arg );
const char* anyEnum2str( Brig::BrigPack arg );
const char* anyEnum2str( Brig::BrigProfile arg );
const char* anyEnum2str( Brig::BrigRound arg );
const char* anyEnum2str( Brig::BrigSamplerBoundaryMode arg );
const char* anyEnum2str( Brig::BrigSamplerFilter arg );
const char* anyEnum2str( Brig::BrigSegment arg );
const char* anyEnum2str( Brig::BrigTypeX arg );
const char* anyEnum2str( Brig::BrigWidth arg );
const char* anyEnum2str( Brig::OldGcnOpcodes arg );
inline ValRef<uint16_t> AluModifier::allBits() { return valRef(&brig()->allBits); }
inline BFValRef<Brig::BrigRound8_t,0,4> AluModifier::round() { return bFValRef<Brig::BrigRound8_t,0,4>(&brig()->allBits); }
inline BitValRef<4> AluModifier::ftz() { return bitValRef<4>(&brig()->allBits); }
inline ValRef<uint16_t> Directive::size() { return valRef(&brig()->size); }
inline EnumValRef<Brig::BrigDirectiveKinds,uint16_t> Directive::kind() { return enumValRef<Brig::BrigDirectiveKinds,uint16_t>(&brig()->kind); }
inline ValRef<uint16_t> BlockNumeric::type() { return valRef(&brig()->type); }
inline ValRef<uint32_t> BlockNumeric::elementCount() { return valRef(&brig()->elementCount); }
inline DataItemRef BlockNumeric::data() { return dataItemRef(&brig()->data); }
template<typename T> inline DataItemRefT<T> BlockNumeric::dataAs() { return DataItemRefT<T>(*this); }
inline ValRef<uint32_t> BlockNumeric::dataAs() { return valRef(&brig()->data); }
inline StrRef BlockString::string() { return strRef(&brig()->string); }
inline ItemRef<Inst> DirectiveCode::code() { return itemRef<Inst>(&brig()->code); }
inline StrRef BlockStart::name() { return strRef(&brig()->name); }
inline StrRef DirectiveCallableBase::name() { return strRef(&brig()->name); }
inline ValRef<uint16_t> DirectiveCallableBase::inArgCount() { return valRef(&brig()->inArgCount); }
inline ValRef<uint16_t> DirectiveCallableBase::outArgCount() { return valRef(&brig()->outArgCount); }
inline ItemRef<Directive> DirectiveExecutable::firstInArg() { return itemRef<Directive>(&brig()->firstInArg); }
inline ItemRef<Directive> DirectiveExecutable::firstScopedDirective() { return itemRef<Directive>(&brig()->firstScopedDirective); }
inline ItemRef<Directive> DirectiveExecutable::nextTopLevelDirective() { return itemRef<Directive>(&brig()->nextTopLevelDirective); }
inline ValRef<uint32_t> DirectiveExecutable::instCount() { return valRef(&brig()->instCount); }
inline ExecutableModifier DirectiveExecutable::modifier() { return subItem<ExecutableModifier>(&brig()->modifier); }
inline ValRef<uint16_t> DirectiveSignature::inCount() { return valRef(&brig()->inArgCount); }
inline ValRef<uint16_t> DirectiveSignature::outCount() { return valRef(&brig()->outArgCount); }
inline DirectiveSignatureArguments DirectiveSignature::args() { return DirectiveSignatureArguments(*this); }
inline DirectiveSignatureArgument DirectiveSignature::args(int index) { return subItem<DirectiveSignatureArgument>(&brig()->args[index]); }
inline StrRef DirectiveComment::name() { return strRef(&brig()->name); }
inline EnumValRef<Brig::BrigControlDirective,uint16_t> DirectiveControl::control() { return enumValRef<Brig::BrigControlDirective,uint16_t>(&brig()->control); }
inline ValRef<uint16_t> DirectiveControl::type() { return valRef(&brig()->type); }
inline ValRef<uint16_t> DirectiveControl::elementCount() { return valRef(&brig()->valueCount); }
inline ControlValues DirectiveControl::values() { return ControlValues(*this); }
inline ItemRef<Operand> DirectiveControl::values(int index) { return itemRef<Operand>(&brig()->values[index]); }
inline StrRef DirectiveExtension::name() { return strRef(&brig()->name); }
inline StrRef DirectiveFbarrier::name() { return strRef(&brig()->name); }
inline ValRef<uint32_t> DirectiveFile::fileid() { return valRef(&brig()->fileid); }
inline StrRef DirectiveFile::filename() { return strRef(&brig()->filename); }
inline ValRef<uint32_t> DirectiveImageInit::width() { return valRef(&brig()->width); }
inline ValRef<uint32_t> DirectiveImageInit::height() { return valRef(&brig()->height); }
inline ValRef<uint32_t> DirectiveImageInit::depth() { return valRef(&brig()->depth); }
inline ValRef<uint32_t> DirectiveImageInit::array() { return valRef(&brig()->array); }
inline EnumValRef<Brig::BrigImageOrder,uint8_t> DirectiveImageInit::order() { return enumValRef<Brig::BrigImageOrder,uint8_t>(&brig()->order); }
inline EnumValRef<Brig::BrigImageFormat,uint8_t> DirectiveImageInit::format() { return enumValRef<Brig::BrigImageFormat,uint8_t>(&brig()->format); }
inline StrRef DirectiveLabel::name() { return strRef(&brig()->name); }
inline ItemRef<DirectiveLabel> DirectiveLabelList::label() { return itemRef<DirectiveLabel>(&brig()->label); }
inline ValRef<uint16_t> DirectiveLabelList::elementCount() { return valRef(&brig()->labelCount); }
inline LabelList DirectiveLabelList::labels() { return LabelList(*this); }
inline ItemRef<DirectiveLabel> DirectiveLabelList::labels(int index) { return itemRef<DirectiveLabel>(&brig()->labels[index]); }
inline ValRef<uint32_t> DirectiveLoc::fileid() { return valRef(&brig()->fileid); }
inline ValRef<uint32_t> DirectiveLoc::line() { return valRef(&brig()->line); }
inline ValRef<uint32_t> DirectiveLoc::column() { return valRef(&brig()->column); }
inline StrRef DirectivePragma::name() { return strRef(&brig()->name); }
inline StrRef DirectiveSymbol::name() { return strRef(&brig()->name); }
inline ItemRef<Directive> DirectiveSymbol::init() { return itemRef<Directive>(&brig()->init); }
inline ValRef<uint16_t> DirectiveSymbol::type() { return valRef(&brig()->type); }
inline EnumValRef<Brig::BrigSegment,uint8_t> DirectiveSymbol::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline ValRef<uint8_t> DirectiveSymbol::align() { return valRef(&brig()->align); }
inline ValRef<uint32_t> DirectiveSymbol::dimLo() { return valRef(&brig()->dimLo); }
inline ValRef<uint64_t> DirectiveSymbol::dim() { return reinterpretValRef<uint64_t>(&brig()->dimLo); }
inline ValRef<uint32_t> DirectiveSymbol::dimHi() { return valRef(&brig()->dimHi); }
inline SymbolModifier DirectiveSymbol::modifier() { return subItem<SymbolModifier>(&brig()->modifier); }
inline ItemRef<DirectiveImageInit> DirectiveImage::init() { return itemRef<DirectiveImageInit>(&brig()->init); }
inline ItemRef<DirectiveSamplerInit> DirectiveSampler::init() { return itemRef<DirectiveSamplerInit>(&brig()->init); }
inline DataItemRef DirectiveVariableInit::data() { return dataItemRef(&brig()->data); }
template<typename T> inline DataItemRefT<T> DirectiveVariableInit::dataAs() { return DataItemRefT<T>(*this); }
inline ValRef<uint32_t> DirectiveVariableInit::dataAs() { return valRef(&brig()->data); }
inline ValRef<uint32_t> DirectiveVariableInit::elementCount() { return valRef(&brig()->elementCount); }
inline ValRef<uint16_t> DirectiveVariableInit::type() { return valRef(&brig()->type); }
inline EnumValRef<Brig::BrigVersion,uint32_t> DirectiveVersion::hsailMajor() { return enumValRef<Brig::BrigVersion,uint32_t>(&brig()->hsailMajor); }
inline EnumValRef<Brig::BrigVersion,uint32_t> DirectiveVersion::hsailMinor() { return enumValRef<Brig::BrigVersion,uint32_t>(&brig()->hsailMinor); }
inline EnumValRef<Brig::BrigVersion,uint32_t> DirectiveVersion::brigMajor() { return enumValRef<Brig::BrigVersion,uint32_t>(&brig()->brigMajor); }
inline EnumValRef<Brig::BrigVersion,uint32_t> DirectiveVersion::brigMinor() { return enumValRef<Brig::BrigVersion,uint32_t>(&brig()->brigMinor); }
inline EnumValRef<Brig::BrigProfile,uint8_t> DirectiveVersion::profile() { return enumValRef<Brig::BrigProfile,uint8_t>(&brig()->profile); }
inline EnumValRef<Brig::BrigMachineModel,uint8_t> DirectiveVersion::machineModel() { return enumValRef<Brig::BrigMachineModel,uint8_t>(&brig()->machineModel); }
inline SamplerModifier DirectiveSamplerInit::modifier() { return subItem<SamplerModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigSamplerBoundaryMode,uint8_t> DirectiveSamplerInit::boundaryU() { return enumValRef<Brig::BrigSamplerBoundaryMode,uint8_t>(&brig()->boundaryU); }
inline EnumValRef<Brig::BrigSamplerBoundaryMode,uint8_t> DirectiveSamplerInit::boundaryV() { return enumValRef<Brig::BrigSamplerBoundaryMode,uint8_t>(&brig()->boundaryV); }
inline EnumValRef<Brig::BrigSamplerBoundaryMode,uint8_t> DirectiveSamplerInit::boundaryW() { return enumValRef<Brig::BrigSamplerBoundaryMode,uint8_t>(&brig()->boundaryW); }
inline ValRef<uint16_t> DirectiveSignatureArgument::type() { return valRef(&brig()->type); }
inline ValRef<uint8_t> DirectiveSignatureArgument::align() { return valRef(&brig()->align); }
inline SymbolModifier DirectiveSignatureArgument::modifier() { return subItem<SymbolModifier>(&brig()->modifier); }
inline ValRef<uint32_t> DirectiveSignatureArgument::dimLo() { return valRef(&brig()->dimLo); }
inline ValRef<uint64_t> DirectiveSignatureArgument::dim() { return reinterpretValRef<uint64_t>(&brig()->dimLo); }
inline ValRef<uint32_t> DirectiveSignatureArgument::dimHi() { return valRef(&brig()->dimHi); }
inline ValRef<uint8_t> ExecutableModifier::allBits() { return valRef(&brig()->allBits); }
inline BFValRef<Brig::BrigLinkage8_t,0,2> ExecutableModifier::linkage() { return bFValRef<Brig::BrigLinkage8_t,0,2>(&brig()->allBits); }
inline BitValRef<2> ExecutableModifier::isDeclaration() { return bitValRef<2>(&brig()->allBits); }
inline ValRef<uint16_t> Inst::size() { return valRef(&brig()->size); }
inline EnumValRef<Brig::BrigInstKinds,uint16_t> Inst::kind() { return enumValRef<Brig::BrigInstKinds,uint16_t>(&brig()->kind); }
inline EnumValRef<Brig::BrigOpcode,uint16_t> Inst::opcode() { return enumValRef<Brig::BrigOpcode,uint16_t>(&brig()->opcode); }
inline ValRef<uint16_t> Inst::type() { return valRef(&brig()->type); }
inline ItemRef<Operand> Inst::operand(int index) { return itemRef<Operand>(&brig()->operands[index]); }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstAddr::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstAtomic::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline EnumValRef<Brig::BrigMemorySemantic,uint8_t> InstAtomic::memorySemantic() { return enumValRef<Brig::BrigMemorySemantic,uint8_t>(&brig()->memorySemantic); }
inline EnumValRef<Brig::BrigAtomicOperation,uint8_t> InstAtomic::atomicOperation() { return enumValRef<Brig::BrigAtomicOperation,uint8_t>(&brig()->atomicOperation); }
inline ValRef<uint16_t> InstAtomicImage::imageType() { return valRef(&brig()->imageType); }
inline ValRef<uint16_t> InstAtomicImage::coordType() { return valRef(&brig()->coordType); }
inline EnumValRef<Brig::BrigImageGeometry,uint8_t> InstAtomicImage::geometry() { return enumValRef<Brig::BrigImageGeometry,uint8_t>(&brig()->geometry); }
inline EnumValRef<Brig::BrigAtomicOperation,uint8_t> InstAtomicImage::atomicOperation() { return enumValRef<Brig::BrigAtomicOperation,uint8_t>(&brig()->atomicOperation); }
inline EnumValRef<Brig::BrigMemoryFence,uint8_t> InstBar::memoryFence() { return enumValRef<Brig::BrigMemoryFence,uint8_t>(&brig()->memoryFence); }
inline EnumValRef<Brig::BrigWidth,uint8_t> InstBar::width() { return enumValRef<Brig::BrigWidth,uint8_t>(&brig()->width); }
inline AluModifier InstBr::modifier() { return subItem<AluModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigWidth,uint8_t> InstBr::width() { return enumValRef<Brig::BrigWidth,uint8_t>(&brig()->width); }
inline ValRef<uint16_t> InstCmp::sourceType() { return valRef(&brig()->sourceType); }
inline AluModifier InstCmp::modifier() { return subItem<AluModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigCompareOperation,uint8_t> InstCmp::compare() { return enumValRef<Brig::BrigCompareOperation,uint8_t>(&brig()->compare); }
inline EnumValRef<Brig::BrigPack,uint8_t> InstCmp::pack() { return enumValRef<Brig::BrigPack,uint8_t>(&brig()->pack); }
inline ValRef<uint16_t> InstCvt::sourceType() { return valRef(&brig()->sourceType); }
inline AluModifier InstCvt::modifier() { return subItem<AluModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigMemoryFence,uint8_t> InstFbar::memoryFence() { return enumValRef<Brig::BrigMemoryFence,uint8_t>(&brig()->memoryFence); }
inline EnumValRef<Brig::BrigWidth,uint8_t> InstFbar::width() { return enumValRef<Brig::BrigWidth,uint8_t>(&brig()->width); }
inline ValRef<uint16_t> InstImage::imageType() { return valRef(&brig()->imageType); }
inline ValRef<uint16_t> InstImage::coordType() { return valRef(&brig()->coordType); }
inline EnumValRef<Brig::BrigImageGeometry,uint8_t> InstImage::geometry() { return enumValRef<Brig::BrigImageGeometry,uint8_t>(&brig()->geometry); }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstMem::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline MemoryModifier InstMem::modifier() { return subItem<MemoryModifier>(&brig()->modifier); }
inline ValRef<uint8_t> InstMem::equivClass() { return valRef(&brig()->equivClass); }
inline EnumValRef<Brig::BrigWidth,uint8_t> InstMem::width() { return enumValRef<Brig::BrigWidth,uint8_t>(&brig()->width); }
inline AluModifier InstMod::modifier() { return subItem<AluModifier>(&brig()->modifier); }
inline EnumValRef<Brig::BrigPack,uint8_t> InstMod::pack() { return enumValRef<Brig::BrigPack,uint8_t>(&brig()->pack); }
inline ValRef<uint16_t> InstSeg::sourceType() { return valRef(&brig()->sourceType); }
inline EnumValRef<Brig::BrigSegment,uint8_t> InstSeg::segment() { return enumValRef<Brig::BrigSegment,uint8_t>(&brig()->segment); }
inline ItemRef<Operand> InstSourceType::operands(int index) { return itemRef<Operand>(&brig()->operands[index]); }
inline ValRef<uint16_t> InstSourceType::sourceType() { return valRef(&brig()->sourceType); }
inline ValRef<uint16_t> InstNone::size() { return valRef(&brig()->size); }
inline EnumValRef<Brig::BrigInstKinds,uint16_t> InstNone::kind() { return enumValRef<Brig::BrigInstKinds,uint16_t>(&brig()->kind); }
inline ValRef<uint16_t> MemoryModifier::allBits() { return valRef(&brig()->allBits); }
inline BFValRef<Brig::BrigSamplerModifier8_t,0,4> MemoryModifier::semantic() { return bFValRef<Brig::BrigSamplerModifier8_t,0,4>(&brig()->allBits); }
inline BitValRef<4> MemoryModifier::aligned() { return bitValRef<4>(&brig()->allBits); }
inline ValRef<uint16_t> Operand::size() { return valRef(&brig()->size); }
inline EnumValRef<Brig::BrigOperandKinds,uint16_t> Operand::kind() { return enumValRef<Brig::BrigOperandKinds,uint16_t>(&brig()->kind); }
inline ItemRef<DirectiveSymbol> OperandAddress::symbol() { return itemRef<DirectiveSymbol>(&brig()->symbol); }
inline StrRef OperandAddress::reg() { return strRef(&brig()->reg); }
inline ValRef<uint32_t> OperandAddress::offsetLo() { return valRef(&brig()->offsetLo); }
inline ValRef<uint64_t> OperandAddress::offset() { return reinterpretValRef<uint64_t>(&brig()->offsetLo); }
inline ValRef<uint32_t> OperandAddress::offsetHi() { return valRef(&brig()->offsetHi); }
inline ValRef<uint16_t> OperandAddress::type() { return valRef(&brig()->type); }
inline ValRef<uint16_t> OperandImmed::type() { return valRef(&brig()->type); }
inline ValRef<uint16_t> OperandImmed::byteCount() { return valRef(&brig()->byteCount); }
inline ValRef<uint8_t> OperandImmed::bytes(int index) { return valRef(&brig()->bytes[index]); }
inline ValRef<uint16_t> OperandList::elementCount() { return valRef(&brig()->elementCount); }
inline RefList OperandList::elements() { return RefList(*this); }
inline ItemRef<Directive> OperandList::elements(int index) { return itemRef<Directive>(&brig()->elements[index]); }
inline ItemRef<Directive> OperandRef::ref() { return itemRef<Directive>(&brig()->ref); }
inline ItemRef<DirectiveSymbol> OperandArgumentRef::arg() { return itemRef<DirectiveSymbol>(&brig()->ref); }
inline ItemRef<DirectiveFbarrier> OperandFbarrierRef::fbar() { return itemRef<DirectiveFbarrier>(&brig()->ref); }
inline ItemRef<DirectiveFunction> OperandFunctionRef::fn() { return itemRef<DirectiveFunction>(&brig()->ref); }
inline ItemRef<DirectiveLabel> OperandLabelRef::asLabel() { return itemRef<DirectiveLabel>(&brig()->ref); }
inline ItemRef<DirectiveCallableBase> OperandSignatureRef::sig() { return itemRef<DirectiveCallableBase>(&brig()->ref); }
inline StrRef OperandReg::reg() { return strRef(&brig()->reg); }
inline ValRef<uint16_t> OperandReg::type() { return valRef(&brig()->type); }
inline ValRef<uint16_t> OperandRegVector::type() { return valRef(&brig()->type); }
inline ValRef<uint16_t> OperandRegVector::regCount() { return valRef(&brig()->regCount); }
inline ValRef<uint16_t> OperandRegVector::elementCount() { return valRef(&brig()->regCount); }
inline RegVecStrList OperandRegVector::regs() { return RegVecStrList(*this); }
inline StrRef OperandRegVector::regs(int index) { return strRef(&brig()->regs[index]); }
inline ValRef<uint16_t> OperandWavesize::type() { return valRef(&brig()->type); }
inline ValRef<uint8_t> SamplerModifier::allBits() { return valRef(&brig()->allBits); }
inline BFValRef<Brig::BrigSamplerFilter8_t,0,6> SamplerModifier::filter() { return bFValRef<Brig::BrigSamplerFilter8_t,0,6>(&brig()->allBits); }
inline BitValRef<6> SamplerModifier::isUnnormalized() { return bitValRef<6>(&brig()->allBits); }
inline ValRef<uint8_t> SymbolModifier::allBits() { return valRef(&brig()->allBits); }
inline BFValRef<Brig::BrigLinkage8_t,0,2> SymbolModifier::linkage() { return bFValRef<Brig::BrigLinkage8_t,0,2>(&brig()->allBits); }
inline BitValRef<2> SymbolModifier::isDeclaration() { return bitValRef<2>(&brig()->allBits); }
inline BitValRef<3> SymbolModifier::isConst() { return bitValRef<3>(&brig()->allBits); }
inline BitValRef<4> SymbolModifier::isArray() { return bitValRef<4>(&brig()->allBits); }
inline BitValRef<5> SymbolModifier::isFlexArray() { return bitValRef<5>(&brig()->allBits); }
