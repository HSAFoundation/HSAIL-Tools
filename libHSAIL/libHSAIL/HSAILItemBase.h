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
#pragma once
#ifndef INCLUDED_HSAIL_ITEM_BASE_H
#define INCLUDED_HSAIL_ITEM_BASE_H

#include "HSAILBrigContainer.h"
#include "HSAILTypeUtilities.h"
#include "HSAILUtilities.h"
#include "Brig.h"
#include "HSAILSRef.h"
#include <string>


namespace HSAIL_ASM {


template <typename Dst, typename Src> struct copy_const { typedef Dst type; };
template <typename Dst, typename Src> struct copy_const<Dst, const Src> { typedef const Dst type; };

template <typename T, typename Accessor>
class Ptr : public Accessor {
public:
    Ptr(const Accessor& a) : Accessor(a) {}

    // QT is T optionally qualified with const depending on Accessor::SectionType
    typedef typename copy_const<T,typename Accessor::SectionType>::type QT;
    QT* valuePtr()   const { return Accessor::section()->template getData<QT>(Accessor::offset()); }
    QT& operator*()  const { return *valuePtr(); }
    QT* operator->() const { return valuePtr(); }
};


template <typename SectionT>
class DirectAccessor {
public:
    typedef SectionT SectionType;
    DirectAccessor(SectionType *section, Offset offset) : m_section(section), m_offset(offset) {}
    BrigSectionImpl* section() const { return m_section; }
    Offset           offset()  const { return m_offset; }
private:
    SectionType *m_section;
    Offset       m_offset;
};

template <typename DstSectionType, typename SrcSectionType=DstSectionType>
class IndirectAccessor {
public:
    typedef DirectAccessor<SrcSectionType> OffsetAccessor;
    typedef DstSectionType SectionType;

    IndirectAccessor(DstSectionType* dstSection, SrcSectionType *srcSection, Offset srcOffset)
        : m_dstSection(dstSection)
        , m_srcOffsetPtr(OffsetAccessor(srcSection,srcOffset))
    {}

    Ptr<Offset,OffsetAccessor> srcOffsetPtr() const { return m_srcOffsetPtr; }

    SectionType* section() const { return m_dstSection; }
    Offset       offset()  const { return *m_srcOffsetPtr; }

private:
    DstSectionType*            m_dstSection;
    Ptr<Offset,OffsetAccessor> m_srcOffsetPtr;
};

template <typename ElemT, typename Accessor>
class DataItemInterface {
    typedef Ptr<Brig::BrigString,Accessor> PtrT;
    PtrT m_ptr;
public:
    DataItemInterface(const Accessor& r) : m_ptr(r) {}

    const PtrT& ptr() const { return m_ptr; }

    // QElemT is ElemT optionally qualified with const depending on Accessor::SectionType
    typedef typename copy_const<ElemT,typename Accessor::SectionType>::type QElemT;

    uint32_t numBytes() const { return m_ptr->byteCount; }
    uint32_t numElements() const { return numBytes() / sizeof(ElemT); }

    QElemT&  operator[](int index) const { return reinterpret_cast<QElemT*>(m_ptr->bytes)[index]; }
    QElemT*  begin() const { return &(*this)[0]; }
    QElemT*  end() const   { return begin()+numElements(); }
};



template <typename ElemT,
          typename SectionType=BrigSectionImpl,
          typename Acc=DirectAccessor<SectionType> >
class DataItemT : public DataItemInterface<ElemT,Acc> {
public:
    DataItemT(SectionType* section, Offset offset)
        : DataItemInterface<ElemT,Acc>( Acc(section,offset) )
    {}

    template <typename OtherT>
    operator DataItemT<OtherT>() const { return DataItemT<OtherT>(this->ptr().section(),this->ptr().offset()); }
};

template <typename ElemT,
          typename DstSectionType = StringSection,
          typename SrcSectionType = BrigSectionImpl,
          typename Acc            = IndirectAccessor<DstSectionType,SrcSectionType>
         >
class DataItemRefT : public DataItemInterface<ElemT,Acc> {
public:
    DataItemRefT(SrcSectionType* srcSection, Offset srcOffset)
        : DataItemInterface<ElemT,Acc>( Acc(&srcSection->container()->strings(), srcSection, srcOffset) )
    {}

    operator DataItemT<ElemT>() const { return DataItemT<ElemT>(this->ptr().section(),this->ptr().offset()); }

    template <typename OtherT>
    DataItemRefT& operator=(DataItemT<OtherT> item) {
        assert(item.ptr().section()==this->ptr().section());
        *this->ptr().srcOffsetPtr() = item.ptr().offset();
        return *this;
    }

    DataItemRefT& operator=(SRef str) {
        *this->ptr().srcOffsetPtr() = this->ptr().section()->addString(str);
        return *this;
    }
};

typedef DataItemT<uint8_t>    DataItem;
typedef DataItemRefT<uint8_t> DataItemRef;

class ArbitraryData
{
    std::vector<char> m_buffer;
public:
    SRef toSRef() const { return m_buffer.empty() ? SRef() : SRef(&m_buffer[0],&m_buffer[0]+m_buffer.size()); }

    template<typename T>
    void push_back(T t) {
        const char *p = reinterpret_cast<const char*>(&t);
        m_buffer.insert(m_buffer.end(),p,p+sizeof t);
    }

    template<typename T>
    size_t numElements() const { return m_buffer.size() / sizeof (T); }

    size_t numBytes() const { return m_buffer.size(); }
};

/*
template <typename Accessor>
class StringItem : public DataItem<char,Accessor> {
public:
    StringItem(const Accessor& r) : DataItem<char,Accessor>(r) {}

    // add some sugar
    uint32_t length() const { return numElements(); }
    operator SRef() const { return SRef(begin(),end()); }
};
*/



/// implement reference to a string table element from a brig item.
class StrRef {
    BrigSectionImpl * const m_refSection;
    Offset            m_offset2Ref;

    StrRef(); // not default-constructible

    typedef void (StrRef::*bool_type)() const;
    void toCompare() const {}

public:
    StrRef(const StrRef& rhs)
        : m_refSection(rhs.m_refSection)
        , m_offset2Ref(rhs.m_offset2Ref) { }

    /// constructor.
    /// @param refSection - section that contain item
    /// @param refOffset - offset inside refSection to the
    /// item's field that reference string (that is offset to offset)
    StrRef(BrigSectionImpl *refSection, Offset& refOffset)
        : m_refSection(refSection)
        , m_offset2Ref((Offset)(reinterpret_cast<char*>(&refOffset) - refSection->getData(0)))
    {
        assert(refSection);
    }

    /// access to the actual offset that reference the string.
    Offset& deref() { return *m_refSection->getData<Offset>(m_offset2Ref); }
    Offset deref() const { return *m_refSection->getData<Offset>(m_offset2Ref); }

    /// @name assignment operator. This operator actually adds string to the string section
    /// and make this reference point to it.
    /// @{
    StrRef& operator=(const char* src) {
        deref() = m_refSection->container()->strings().addString(SRef(src));
        return *this;
    }

    StrRef& operator=(const std::string& src) {
        deref() = m_refSection->container()->strings().addString(src);
        return *this;
    }

    StrRef& operator=(const SRef& src) {
        deref() = m_refSection->container()->strings().addString(src);
        return *this;
    }
    /// @}

    operator SRef() const { return m_refSection->container()->strings().getString(deref()); }

    /// return non-null if wrapper points to an item.
    operator bool_type() const { return deref() != 0 ? &StrRef::toCompare : NULL; }

    bool operator==(const StrRef& rhs) const { return deref()==rhs.deref(); }
    bool operator!=(const StrRef& rhs) const { return !(*this==rhs); }
};

template <typename OS>
OS& operator<<(OS& os, const StrRef& s) {
   os << static_cast<SRef>(s);
   return os;
}

/// implement reference one brig item from another.
/// @param Item - type of referenced item.
template <typename Item>
class ItemRef : public Item {
    BrigSectionImpl * m_refSection;
    Offset            m_offset2Ref;

private:
    ItemRef(); // not default-constructible
public:
    ItemRef(const ItemRef& rhs) // FIXME patch! this actually should be disabled.
        : Item(rhs)
        , m_refSection(rhs.m_refSection)
        , m_offset2Ref(rhs.m_offset2Ref)
    {
    }

    /// constructor.
    /// @param refSection - section containing item with reference.
    /// @param refOffset - offset inside refSection to the
    /// item's field that reference another item (that is offset to offset)
    ItemRef(BrigSectionImpl *refSection, Offset& refOffset)
        : Item(&refSection->container()->section<typename Item::Kind>(), refOffset)
        , m_refSection(refSection)
        , m_offset2Ref((Offset)(reinterpret_cast<char*>(&refOffset) - refSection->getData(0)))
    {
    }

    /// constructor. What is it?
    ItemRef(BrigSectionImpl *refSection)
        : Item(&refSection->container()->section<typename Item::Kind>(), 0)
        , m_refSection(refSection)
        , m_offset2Ref(0)
    {
    }

    template <typename Other>
    ItemRef<Other> asRefTo() {  // TBD095 needs relationship test
        return ItemRef<Other>(m_refSection,deref());
    }

    /// access to the actual offset that reference the Item.
    Offset& deref() { return *m_refSection->getData<Offset>(m_offset2Ref); }
    Offset deref() const { return *m_refSection->getData<Offset>(m_offset2Ref); }

    /// assignment operator. Assign reference to another brig item.
    /// @param Other - type of referenced item.
    template <typename Other>
    ItemRef<Item>& operator=(const Other& rhs) {
        Item::operator=(rhs);
        deref() = rhs.brigOffset();
        return *this;
    }
};

/// proxy for brig item value.
/// @param T - type of value.
template<typename T>
class ValRef {
    BrigSectionImpl * m_refSection;
    Offset            m_valOffset;
public:
    ValRef(); // not default-constructible
    ValRef(const ValRef&); // non-copyable
    /// constructor.
    /// @param refSection - section of the brig item.
    /// @param valPtr - pointer to item's value field.
    ValRef(BrigSectionImpl *refSection, T* valPtr)
        : m_refSection(refSection)
        , m_valOffset((Offset)(reinterpret_cast<char*>(valPtr) - refSection->getData(0)))
    {
    }

    /// @name set accessors.
    /// @{
    ValRef& operator=(T rhs) {
        *m_refSection->getData<T>(m_valOffset) = rhs;
        return *this;
    }
    ValRef& operator=(const ValRef& rhs) {
        return *this = static_cast<T>(rhs);
    }
    /// @}

    /// @name get accessors.
    /// @{
    T value() const { return *m_refSection->getData<T>(m_valOffset); }
    operator T() const { return value(); }
    /// @}

    /// or operator.
    ValRef& operator |= (T v) { return *this = *this | v; }
};

/// proxy for brig item enum value.
/// @param EnumT - enum type.
/// @param BuiltInT - underlying builtin type.
/// This proxy allows to save type information about
/// actual value type to use it in visitors.
template <typename EnumT, typename BuiltInT=int>
class EnumValRef : public ValRef<BuiltInT> {
public:
    EnumValRef();
    EnumValRef(BrigSectionImpl *refSection, BuiltInT* valPtr)
        : ValRef<BuiltInT>(refSection,valPtr) {}

    EnumValRef(BrigSectionImpl *refSection, EnumT* valPtr)
        : ValRef<BuiltInT>(refSection,reinterpret_cast<BuiltInT*>(valPtr)) {}

    EnumT enumValue() const { return static_cast<EnumT>(this->value()); }

    using ValRef<BuiltInT>::operator=;

    EnumValRef& operator=(EnumT rhs) {
        *this = static_cast<BuiltInT>(rhs);
        return *this;
    }
};

/// proxy for Bit Field values.
/// @param T - interface type, used to get/set bitfield.
/// @param firstBit - number of the least signinficand bit.
/// @param width - bit width of field.
template<typename T, unsigned firstBit, unsigned width>
class BFValRef {
    BrigSectionImpl * m_refSection;
    Offset            m_valOffset;

    // choose suitable underlying uint to represent bits
    typedef typename containing_uint<firstBit+width-1>::type BitsT;

    static const BitsT mask = ((static_cast<BitsT>(1) << width) - 1);
    static const BitsT shiftedMask = mask << firstBit;

public:
    BFValRef();
    BFValRef(const BFValRef&);
    BFValRef(BrigSectionImpl *refSection, void* valPtr)
        : m_refSection(refSection)
        , m_valOffset((Offset)(reinterpret_cast<char*>(valPtr) - refSection->getData(0)))
    {
    }

    BFValRef& operator=(T rhs) {
	    BitsT &v = *m_refSection->getData<BitsT>(m_valOffset);
	    v &= ~shiftedMask;
	    v |= (static_cast<BitsT>(rhs) & mask) << firstBit;
        return *this;
    }

    BFValRef& operator=(const BFValRef& rhs) {
        return *this = static_cast<T>(rhs);
    }

    operator T() const {
        return static_cast<T>((*m_refSection->getData<BitsT>(m_valOffset) >> firstBit) & mask);
    }
};

/// proxy for Bit Field value of 1bit length.
/// @param bit - number of the bit.
template<unsigned bit>
class BitValRef {
private:
    typedef uint8_t T;
	BFValRef<T, bit, 1> bf;
public:
	BitValRef();
	BitValRef(const BitValRef&);
	BitValRef(BrigSectionImpl *refSection, void* valPtr) : bf(refSection, valPtr) { }

	BitValRef& operator=(bool rhs) { bf = rhs ? 1u : 0u; return *this; }
	BitValRef& operator=(const BitValRef& rhs) { return *this = static_cast<bool>(rhs); }
	operator bool() const { return static_cast<T>(bf) != 0; }
};

/// base class for brig item wrapper.
/// @param SectionKind_ - base type of item (Directive,Instr,Operand)
class ItemBase {
	typedef void (ItemBase::*bool_type)() const;
    void toCompare() const {}
public:
	typedef BrigSectionImpl MySection;

protected:
    MySection* m_section;
    Offset     m_offset;

    template <typename DstItem, typename SrcItem>
    static DstItem& assignItem(DstItem& to, const SrcItem& from) {
   	bool is1or2 = is_1st_descendant_or_same_of_2nd<SrcItem, DstItem>::value;
        if (from && (is1or2 || DstItem::isAssignable(from))) {
            assert(!to || to.section() == from.section());
            to.reset(from.section(),from.brigOffset());
        } else {
            to.reset();
        }
        return to;
    }

    // this method allows correct assign DstItem i = ItemRef<SrcItem>()
    template <typename DstItem, typename SrcItem>
    static DstItem& assignItem(DstItem& to, const ItemRef<SrcItem>& from) {
        return assignItem<DstItem,SrcItem>(to,*static_cast<const SrcItem*>(&from));
    }

public:
    ItemBase()
        : m_section(0), m_offset(0) { }

    ItemBase(MySection *section, Offset offset)
        : m_section(section), m_offset(offset) { }

    /// return container this item belongs to.
    BrigContainer *container() const { return m_section->container(); }

    /// return section this item belongs to.
    MySection* section() const { return m_section; }

    /// return offset of the item in the section.
    Offset brigOffset() const { return m_offset;  }

    //operator bool() const { return m_section!=NULL && m_offset != 0; }

	/// return non-null if wrapper points to an item.
	operator bool_type() const { return m_offset != 0 ? &ItemBase::toCompare : NULL; }

    /// wrapper comparisons - return whether 2 wrappers point to the same item.
    bool operator==(const ItemBase& rhs) const { return m_offset == rhs.m_offset && m_section==rhs.m_section; }
    bool operator!=(const ItemBase& rhs) const { return !(*this==rhs); }

    /// low level reset.
    void reset(MySection* s=NULL, Offset o=0)
    {
        m_section = s;
        m_offset = o;
    }
    void reset(const ItemBase& rhs) {
    	m_section = rhs.m_section;
    	m_offset = rhs.m_offset;
    }

    /// @name Field proxies
    /// @{
    template<typename T>
    T valRef(const T* val) const { return *val; }

    template<typename T>
    ValRef<T> valRef(T *val) { return ValRef<T>(m_section, val); }

    template<typename T>
    ValRef<T> reinterpretValRef(void *val) { return ValRef<T>(m_section, reinterpret_cast<T*>(val)); }

    template <typename EnumT, typename BuiltInT>
    EnumValRef<EnumT,BuiltInT> enumValRef(BuiltInT *val) { return EnumValRef<EnumT,BuiltInT>(m_section, val); }

    template <typename EnumT, typename BuiltInT>
    EnumValRef<EnumT,BuiltInT> enumValRef(BuiltInT *val) const { return EnumValRef<EnumT,BuiltInT>(m_section, val); }

    template<typename T,unsigned firstBit,unsigned width>
    BFValRef<T,firstBit,width> bFValRef(void *val) { return BFValRef<T,firstBit,width>(m_section, val); }

    template<unsigned bit>
    BitValRef<bit> bitValRef(void *val) { return BitValRef<bit>(m_section, val); }

    SRef strRef(const Offset* ofs) const { return container()->getString(*ofs); }
    StrRef strRef(Offset *ofs) { return StrRef(m_section, *ofs); }

    template<typename OtherItem>
    OtherItem itemRef(const Offset *ofs) const { return OtherItem(container(),ofs); }
    template<typename Other>
    ItemRef<Other> itemRef(Offset *ofs) { return ItemRef<Other>(m_section, *ofs); }

    template<typename SubItem>
    SubItem subItem(void* subItem) { return SubItem(m_section,
    	(Offset)(reinterpret_cast<char*>(subItem) - m_section->getData(0))); }

    template<typename Other>
    ItemRef<Other> noItemRef() { return ItemRef<Other>(m_section); }

    DataItemRef dataItemRef(void *val) const {
        return DataItemRef(m_section,
            (Offset)(reinterpret_cast<char*>(val) - m_section->getData(0)));
    }

    template <typename ElemT>
    DataItemRefT<ElemT> dataItemRefT(void *val) const {
        return DataItemRefT<ElemT>(m_section,
            (Offset)(reinterpret_cast<char*>(val) - m_section->getData(0)));
    }

    /// @}

    /// annotate this item with source info.
    void annotate(const SourceInfo& si) {
        m_section->annotate(*this,si);
    }
    /// return associated SourceInfo. May be NULL.
    const SourceInfo* srcInfo() const {
        return m_section->sourceInfo(brigOffset());
    }
};

/// return true if SrcItem is of a DstItem type.
template <typename DstItem, typename SrcItem>
inline bool isa(SrcItem src) {
    DstItem dst = src;
    return dst!=false;
}

/// grows an item size. Item should be the last item in it's section.
/// Used primarily for items with trailing values to append.
/// @param item - the item
/// @param reqSize - new size (can be smaller than original item size)
/// @return new size of an item, may be smaller than reqSize.
template <typename Item>
unsigned grow(Item item, size_t reqSize) {
    return item.section()->grow(item,reqSize);
}

/// proxy for trailing values of a brig item.
/// Think of DirectiveVariableInit as an example: it consist of header and tail of init values.
/// @param Item - item wrapper type.
/// @param T - type of trailing values.
/// @param ValOffset - byte offset of first value inside item.
template<typename Item, typename T, size_t ValOffset>
class TrailingValues {
protected:
    Item item;
public:
    enum {
        MAX_NUM_ELEM = (65536 - 8 - ValOffset) / sizeof(T)
    };
    TrailingValues(const Item &rhs) : item(rhs) {
    }
    TrailingValues(const TrailingValues& rhs) : item(rhs.item) {
    }
    /// section this item belongs to.
    typename Item::MySection *section() const {
        return item.section();
    }
    /// container this item belongs to.
    BrigContainer* container() const {
        return item.container();
    }
    /// number of values.
    Offset size() const {
        return Item(item).elementCount();
    }

    /// pointer to the first value.
    const T* begin() const {
        return reinterpret_cast<const T*>(reinterpret_cast<const char*>(item.brig()) + ValOffset);
    }
    /// pointer beyound the last value.
    const T* end() const {
        return begin() + size();
    }
    /// value by index.
    const T& operator[](size_t index) const {
        return begin()[index];
    }

    T* begin() {
        return reinterpret_cast<T*>(reinterpret_cast<char*>(item.brig()) + ValOffset);
    }
    T* end() {
        return begin() + size();
    }
    T& operator[](size_t index) {
        return begin()[index];
    }

    /// modify size to reqNumElem.
    /// @param reqNumElem - required number of elements.
    /// returns number of allocated elements, can be smaller than reqNumElem.
    unsigned resize(size_t reqNumElem) {
        unsigned newNumElem;
        if (reqNumElem > item.elementCount()) {
            size_t const fitNumElem = (grow(item,ValOffset + reqNumElem*sizeof(T)) - ValOffset)/sizeof(T);
            newNumElem = (unsigned)std::min(reqNumElem,fitNumElem);
        } else {
            newNumElem = (unsigned)reqNumElem;
        }
        item.elementCount() = static_cast<uint16_t>(newNumElem);
        return newNumElem;
    }
    /// add value to the tail.
    /// @return whether allocation was successfull.
    bool push_back(const T& val) {
        Offset n = size();
        bool rc = (resize(n+1) == n+1);
        if (rc) {
            (*this)[n] = val;
        }
        return rc;
    }
};

/// proxy for the trailing list of offsets in a brig item.
/// Allow to obtain ItemRef of element in the list by index.
/// See OperandArgumentList as an example.
/// @param Item - item wrapper type.
/// @param ElemItem - type of item wrapper in the trailing list.
/// @param ValOffset - byte offset of the list inside item.
template<typename Item, typename ElemItem, size_t ValOffset>
class TrailingRefs {
    TrailingValues<Item, Offset, ValOffset> m_values;
public:
    TrailingRefs(const Item &rhs) : m_values(rhs) {}
    TrailingRefs(const TrailingRefs& rhs) : m_values(rhs.m_values) {}

    //ItemRef<ElemItem> begin() { return ItemRef<ElemItem>(m_values.section(), m_values.begin()); }
    //ItemRef<ElemItem> end()   { return ItemRef<ElemItem>(m_values.section(), m_values.end()); }

    Offset size() const { return m_values.size(); }

    ItemRef<ElemItem> operator[](unsigned index) {
        return ItemRef<ElemItem>(m_values.section(), m_values[index]);
    }
    /// modify size to reqNumElem.
    /// @param reqNumElem - required number of elements.
    /// @return number of allocated elements, can be smaller than reqNumElem.
    unsigned resize(unsigned numElem) {
        return m_values.resize(numElem);
    }
    /// add value to the tail.
    /// @return whether allocation was successfull.
    bool push_back(const ElemItem& val) {
        return m_values.push_back(val.brigOffset());
    }
};

template<typename Item, size_t ValOffset>
class TrailingStrRefs {
    TrailingValues<Item, Offset, ValOffset> m_values;
public:
    TrailingStrRefs(const Item &rhs) : m_values(rhs) {}
    TrailingStrRefs(const TrailingStrRefs& rhs) : m_values(rhs.m_values) {}

    Offset size() const { return m_values.size(); }

    StrRef operator[](unsigned index) {
        return StrRef(m_values.section(), m_values[index]);
    }
    /// modify size to reqNumElem.
    /// @param reqNumElem - required number of elements.
    /// @return number of allocated elements, can be smaller than reqNumElem.
    unsigned resize(unsigned numElem) {
        return m_values.resize(numElem);
    }
    /// add value to the tail.
    /// @return whether allocation was successfull.
    bool push_back(const SRef& str) {
        Offset offs = m_values.container()->strings().addString(str);
        return m_values.push_back(offs);
    }
};


} // namespace HSAIL_ASM

#endif //INCLUDED_HSAIL_ITEM_BASE_H

