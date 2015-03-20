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
#ifndef INCLUDED_HSAIL_BRIG_CONTAINER_H
#define INCLUDED_HSAIL_BRIG_CONTAINER_H

#include "HSAILSRef.h"
#include "Brig.h"
#include "HSAILUtilities.h"

#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>
#include <iosfwd>
#include <memory>
#include <limits>
#include <climits>
#include <stdint.h>

namespace HSAIL_ASM {

typedef unsigned Offset;

class Code;
class Operand;

/// this structure is used to pass source location for items. Text coordinates are zero based.
struct SourceInfo
{
    SourceInfo(int l=-1, int c=-1) : line(l), column(c) {}
    //const char  *d_fileName; // is this necessary? will we support include files eventually?
    // maybe refer to some source buffer/file object?
    // filename must refer to some temporary stringtable

    int line;
    int column;
};

template <typename Item> struct GetSectionID;

template <> struct GetSectionID<Code>      { static const BrigSectionIndex id=BRIG_SECTION_INDEX_CODE;       };
template <> struct GetSectionID<Operand>   { static const BrigSectionIndex id=BRIG_SECTION_INDEX_OPERAND;   };


/// implementation of a Brig section. This is a buffer of plain raw data
/// with insert/append/delete modificators.
/// Note that as the buffer is resizable, i.e. the data is movable,
/// appending a new item may invalidate all direct references to the data,
/// but not iterators, as iterators use offsets.
class BrigSectionImpl
{
public:
    typedef std::vector<char> Buffer; // TBD possibly switch to a more optimal container

    virtual void swapInData(Buffer& src) {
        assert(hasOwnBuffer());
        m_buffer.swap(src);
        m_sourceInfo.clear();
        syncWithBuffer();
    }

private:
    class BrigContainer    *m_container;

    const BrigSectionHeader* m_data;

    std::function<void()>       m_syncCallback;

    Buffer               m_buffer;

    typedef std::vector< std::pair<Offset, SourceInfo > > SectionSourceInfo;
    SectionSourceInfo    m_sourceInfo;

    bool hasOwnBuffer() const { return !m_buffer.empty(); }

    void syncWithBuffer() {
      m_data = (BrigSectionHeader*)&m_buffer[0];
      Offset end = static_cast<uint32_t>(m_buffer.size());
      assert(secHeader()->headerByteCount > 0);
      assert(secHeader()->headerByteCount <= end);
      secHeader()->byteCount = end;
      if (m_syncCallback) {
          m_syncCallback();
      }
    }

protected:
    // allow to swap only for 'final' classes
    void swapData(BrigSectionImpl& other) {
        assert(hasOwnBuffer() && other.hasOwnBuffer());
        m_buffer.swap(other.m_buffer);
        m_sourceInfo.swap(other.m_sourceInfo);
        syncWithBuffer();
        other.syncWithBuffer();
    }

public:

    BrigSectionHeader* secHeader() { return getData<BrigSectionHeader>(0); }
    const BrigSectionHeader* secHeader() const { return getData<BrigSectionHeader>(0); }

    /// first bytes of section are NUM_BYTES_RESERVED nulls.
    enum { ITEM_ALIGNMENT = 4 };

    /// constructor.
    /// @param container - parent container this section belongs to.
    BrigSectionImpl(SRef name, class BrigContainer *container=NULL);

    /// constructor.
    /// @param container - parent container this section belongs to.
    BrigSectionImpl(const void* ptr, class BrigContainer *container=NULL)
        : m_container(container)
        , m_data((const BrigSectionHeader*)ptr)
    {
    }

    virtual ~BrigSectionImpl() {
    }

    /// @name parent container this section belongs to.
    /// @{
    class BrigContainer* container() const { return m_container; }
    void container(class BrigContainer* c) { m_container = c; }
    /// @}

    /// returns whether section doesnt' contain items.
    bool isEmpty() const {
      return size() <= secHeader()->headerByteCount;
    }

    virtual void clear() {
        assert(hasOwnBuffer());
        m_buffer.resize(secHeader()->headerByteCount);
        syncWithBuffer();
        m_sourceInfo.clear();
    }

    void setData(const void* data) {
        clear();
        const BrigSectionHeader* header = (const BrigSectionHeader*)data;
        Buffer tmpBuf((const char*)data, (const char*)data + header->byteCount);
        m_buffer.swap(tmpBuf);
        syncWithBuffer();
    }

    void setSyncCallback(std::function<void()> f) {
        m_syncCallback = f;
    }

    void reserve(size_t numBytes) {
        assert(hasOwnBuffer());
        m_buffer.reserve(numBytes);
    }

    SRef name() {
      return SRef((const char*)secHeader()->name, (const char*)secHeader()->name + secHeader()->nameLength);
    }

    /// return offset from the beginning of the section for a data pointed by p.
    /// @param p - pointer to the section's data.
    Offset getOffset(const void* p) const { return (Offset)(reinterpret_cast<const char*>(p) - getData(0)); }

    /// @name return data from a given offset.
    /// @param T - type of the data requested.
    /// @return pointer to T.
    /// @{
    template <typename T>
    T* getData(Offset offset) { return reinterpret_cast<T*>(getData(offset)); }

    template <typename T>
    const T* getData(Offset offset) const { return reinterpret_cast<const T*>(getData(offset)); }
    /// @}

    char* getData(Offset offset) { return (char*)m_data + offset; }
    const char* getData(Offset offset) const { return (const char*)m_data + offset; }

    /// insert uninitialized data into the section.
    /// May invalidate pointers to the section data.
    /// @param offset - offset where data should be inserted.
    /// @param numBytes - number of bytes to be inserted.
    /// @param fill - filling value
    char* insertData(Offset offset, unsigned numBytes, char fill='\xFF') {
        assert(hasOwnBuffer());
        assert(offset <= m_buffer.size());
        m_buffer.insert(m_buffer.begin() + offset,numBytes,fill);
        syncWithBuffer();
        return getData(offset);
    }

    /// insert uninitialized data into the section.
    /// May invalidate pointers to the section data.
    /// @param offset - offset where data should be inserted.
    /// @param start - the begining of the data being inserted.
    /// @param end - the ending of the data being inserted.
    char* insertData(Offset offset, const char* start, const char* end) {
        assert(hasOwnBuffer());
        assert(offset <= m_buffer.size());
        m_buffer.insert(m_buffer.begin() + offset,start,end);
        syncWithBuffer();
        return getData(offset);
    }

    /// deletes data shifting the rest to the beginning of the section.
    /// @param offset - offset from where to start delete.
    /// @param numBytes - num bytes to delete.
    void deleteData(Offset   offset, unsigned numBytes) {
        assert(hasOwnBuffer());
        assert(offset + numBytes <= m_buffer.size());
        m_buffer.erase(m_buffer.begin() + offset,m_buffer.begin() + offset + numBytes);
        syncWithBuffer();
    }

    /// size of the section in bytes.
    Offset size() const { return (Offset)secHeader()->byteCount; }

    /// section data ptrs encapsulated in SRef
    SRef data() const { return SRef((const char*)m_data, (const char*)m_data + size()); }

    /// insert item of specified type at the specified offset.
    /// @param Item - item wrapper type.
    /// @param offset - offset to insert item.
    /// This method inserts plain C structure of Item::BrigType at the offset,
    /// default initialize its fields and return wrapper to access new item.
    template<class Item>
    Item insertAtOffset(Offset offset) {
        insertData(offset, sizeof(typename Item::BrigStruct));
        Item theItem(this, offset);
        theItem.initBrig();
        return theItem;
    }

    /// copy insert specified item at the specified offset.
    /// @param Item - item wrapper type.
    /// @param offset - offset to insert item.
    /// @param i - item to copy fields from.
    /// This method inserts plain C structure of Item::BrigType at the offset,
    /// copy fields from i and return wrapper to access new item.
    template<class Item>
    Item insertAtOffset(Offset offset, const Item& i) {
        const char * const src = reinterpret_cast<const char*>(i.brig());
        insertData(offset, src, src + i.brigSize());
        return Item(this, offset);
    }

    template<class Item>
    Item append() {
        return insertAtOffset<Item>(size());
    }

    template<class Item>
    Item append(const Item& i) {
        return insertAtOffset<Item>(size(),i);
    }

    template<class Item>
    Item append(const SourceInfo& si) {
        Item const res = insertAtOffset<Item>(size());
        annotate(res,si);
        return res;
    }

    template <typename Item>
    unsigned grow(Item item, size_t reqSize) {
        assert((item.brigOffset() + item.brig()->byteCount) == size());

        Offset const oldNumBytes = item.brig()->byteCount;
        Offset const newNumBytes = (Offset)std::min<size_t>(HSAIL_ASM::align(reqSize,ITEM_ALIGNMENT),(std::numeric_limits<uint16_t>::max)()-ITEM_ALIGNMENT);

        if (newNumBytes > oldNumBytes) {
            m_buffer.resize(item.brigOffset() + newNumBytes);
            syncWithBuffer();
            memset(reinterpret_cast<char*>(item.brig()) + oldNumBytes, 0, newNumBytes - oldNumBytes);
            item.brig()->byteCount = static_cast<uint16_t>(newNumBytes);
        }
        return item.brig()->byteCount;
    }

    template<class Item>
    Item item(const typename Item::BrigStruct* b) {
        // TBD assert bounds
        return Item(this, getOffset(b));
    }

    // TBD template here is redundand and 'i' arg should have
    // 'typename Item::Kind' type but its not defined at this point yet
    template<class Item>
    const SourceInfo* sourceInfo( const Item& i ) const {
        return sourceInfo(i.brigOffset());
    }

    const SourceInfo* sourceInfo(Offset o) const {
      if (o == 0) return NULL;
        SectionSourceInfo::const_iterator const p =
            std::lower_bound(m_sourceInfo.begin(),m_sourceInfo.end(),o,&BrigSectionImpl::xless);
        return p!=m_sourceInfo.end() && p->first==o ? &p->second : NULL;
    }

    // TBD template here is redundand and 'i' arg should have
    // 'typename Item::Kind' type but its not defined at this point yet
    template <class Item>
    void annotate(const Item& i, const SourceInfo& si) {
        Offset const ofs = i.brigOffset();
        // on write most of offsets come in ascending order
        // so do a shortcut check
        if (m_sourceInfo.empty() || m_sourceInfo.back().first < ofs) { // [1]
            m_sourceInfo.push_back(std::make_pair(ofs,si));
        } else {
            SectionSourceInfo::iterator const p =
                std::lower_bound(m_sourceInfo.begin(),m_sourceInfo.end(),ofs,&BrigSectionImpl::xless);
            assert(p!=m_sourceInfo.end()); // because of the [1] check
            if (p->first!=ofs) {
                m_sourceInfo.insert(p,std::make_pair(ofs,si));
            } else {
                p->second=si;
            }
        }
    }

private:
    // commented out because typename Item::Kind is not defined at this point TBD
    // static void assert_kind(typename Item::Kind *) {}
    // just to make sure we are operating on appropriate type

    static bool xless(const SectionSourceInfo::value_type& v,Offset o) {
        return v.first < o;
    }
};

SRef brigSectionNameById(int id);

template <typename Item, int ID_>
class BrigSection : public BrigSectionImpl
{
public:
    enum {
        ID = ID_
    };

    BrigSection(class BrigContainer* c=NULL)
      :  BrigSectionImpl(brigSectionNameById(ID), c)
    { }

    BrigSection(const void* ptr, class BrigContainer *container=NULL)
        : BrigSectionImpl(ptr,container) {}

    Item begin() { return Item(this, secHeader()->headerByteCount); }
    Item end() { return Item(this, size()); }

    void swapData(BrigSection& other) {
        BrigSectionImpl::swapData(other);
    }
};

class BrigSectionRaw: public BrigSectionImpl
{
public:

    BrigSectionRaw(SRef name, class BrigContainer* c=NULL) :  BrigSectionImpl(name, c) { }

    BrigSectionRaw(const void* data, class BrigContainer *container=NULL)
        : BrigSectionImpl(data, container) {}

    void swapData(BrigSectionRaw& other) {
        BrigSectionImpl::swapData(other);
    }

    SRef payload() const {
        return SRef(getData<char>(secHeader()->headerByteCount),
               getData<char>((Offset)secHeader()->byteCount));
    }
};

typedef BrigSection<Code,     BRIG_SECTION_INDEX_CODE>                   CodeSection;
typedef BrigSection<Operand,  BRIG_SECTION_INDEX_OPERAND>                OperandSection;

class DataSection : public BrigSectionImpl
{
    enum {
        ID = BRIG_SECTION_INDEX_DATA
    };

    std::vector< Offset > m_stringSet; // ordered by strings they point to
    void initStringSet();

public:
    DataSection(class BrigContainer *container=NULL)
      : BrigSectionImpl(brigSectionNameById(ID), container) {}

    DataSection(const void* ptr, class BrigContainer *container=NULL)
        : BrigSectionImpl(ptr,container)
    {
    }

    Offset addString(const SRef& newStr);

    // add without deduplication
    Offset addStringImpl(const SRef& newStr);

    SRef getString(Offset offset) const {
        assert(offset);
        const BrigData* s = getData<const BrigData>(offset);
        const char *begin = reinterpret_cast<const char*>(s->bytes);
        return SRef(begin,begin + s->byteCount);
    }

    virtual void clear() {
        BrigSectionImpl::clear();
        m_stringSet.clear();
    }

    void swapData(DataSection& other) {
        BrigSectionImpl::swapData(other);
        m_stringSet.swap(other.m_stringSet);
    }

    virtual void swapInData(Buffer& src) {
        BrigSectionImpl::swapInData(src);
        m_stringSet.clear();
    }

    const static size_t maxStringLen = UINT_MAX;
};

template<int id>
class BrigContainerSectionByIndex;

template<>
class BrigContainerSectionByIndex<BRIG_SECTION_INDEX_DATA> {
    typedef DataSection type;
};

template<>
class BrigContainerSectionByIndex<BRIG_SECTION_INDEX_CODE> {
    typedef CodeSection type;
};

template<>
class BrigContainerSectionByIndex<BRIG_SECTION_INDEX_OPERAND> {
    typedef OperandSection type;
};

class ReadAdapter;
class WriteAdapter;

/// container for Brig sections. This is a basically a set of sections that
/// comprise Brig.
class BrigContainer {
    // INSTANCE DATA
private:
    typedef std::vector< std::unique_ptr<BrigSectionImpl> > SectionVector;
    SectionVector m_sections;

    const BrigModuleHeader* m_brigModuleHeader;
    std::vector<char> m_brigModuleBuffer;

    void initSections(const BrigModuleHeader& brigModule,
                      BrigContainer::SectionVector& secs);


public:

    bool isROContainer() const { return m_brigModuleHeader!=nullptr; }
    bool isRWContainer() const { return !isROContainer(); }
    bool hasOwnBuffer() const { return !m_brigModuleBuffer.empty(); }

    BrigContainer(); // RW container

    BrigContainer(const BrigModuleHeader* brigModule); // RO container

    int validate(std::string *outErrorMessage, const SourceInfo **outSourceInfo);
    // Validate the structure of this BRIG container.
    // In case an error is found, fill the specified outErrorMessage with the information
    // on the error, and outSourceInfo with the location of the error in the source file,

    // if such information is available. Return zero on success, or a non-zero error code
    // in case of an error.

    inline int getNumSections() const { return (int)m_sections.size(); }

    DataSection&               strings();
    CodeSection&               code();
    OperandSection&            operands();
    BrigSectionRaw&            debugInfo();

    const DataSection&         strings()     const;
    const CodeSection&         code()        const;
    const OperandSection&      operands()    const;
    const BrigSectionRaw&      debugInfo()   const;

    BrigSectionImpl&           sectionById(int id) {
        return *m_sections[id];
    }

    const BrigSectionImpl&     sectionById(int id) const {
        return *m_sections[id];
    }

    int addSection(std::unique_ptr<BrigSectionImpl>&&);

    // Append a default-initialized item (i.e. an instruction, operand, directive or debug info) to
    // a corresponding section of this container, and return the appropriate item proxy.
    template<typename Item> Item append() {
        return sectionById(Item::SECTION).template append<Item>();
    }

    // the same with source info
    template<typename Item> Item append(const SourceInfo& si) {
        return sectionById(Item::SECTION).template append<Item>(si);
    }

    template<typename Item>
    const SourceInfo* sourceInfo( const Item& i ) const {
        return sectionById(Item::SECTION).sourceInfo(i);
    }

    Offset addString(const SRef& s) { return strings().addString(s); }
    SRef getString(Offset offset) const { return strings().getString(offset); }

    void patchDecl2Defs();
    //void optimizeOperands();

    void clear() {
        strings().clear();
        code().clear();
        operands().clear();
        m_sections.resize(BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED);
    }

    static int verifySection(int index, SRef data, std::ostream &errs);

    int loadSection(int index, BrigSectionImpl::Buffer& data, bool includesHeader, std::ostream &errs);

    void initSectionRaw(int index, SRef name);

    bool makeRO();

    void setContents(std::vector<char>& buf);

    const BrigModuleHeader* getBrigModuleHeader() const {
        assert(isROContainer());
        return m_brigModuleHeader;
    }

    BrigModule_t getBrigModule() {
        makeRO();
        // TODO should be const
        return const_cast<BrigModuleHeader*>(getBrigModuleHeader());
    }

    void setData(void *data, size_t size);

    bool write(WriteAdapter& w) const;
};

bool readContainer(ReadAdapter& r, BrigContainer& c, bool writeable=false);

// non-const
inline DataSection& BrigContainer::strings()  {
    return static_cast<DataSection&>(
        sectionById(BRIG_SECTION_INDEX_DATA));
}

inline CodeSection& BrigContainer::code() {
    return static_cast<CodeSection&>(
        sectionById(BRIG_SECTION_INDEX_CODE));
}
inline OperandSection& BrigContainer::operands() {
    return static_cast<OperandSection&>(
        sectionById(BRIG_SECTION_INDEX_OPERAND));
}

inline BrigSectionRaw& BrigContainer::debugInfo() {
    return static_cast<BrigSectionRaw&>(
        sectionById(BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED));
}

// const
inline const DataSection& BrigContainer::strings() const {
    return static_cast<const DataSection&>(
        sectionById(BRIG_SECTION_INDEX_DATA));
}

inline const CodeSection& BrigContainer::code() const {
    return static_cast<const CodeSection&>(
        sectionById(BRIG_SECTION_INDEX_CODE));
}

inline const OperandSection& BrigContainer::operands() const {
    return static_cast<const OperandSection&>(
        sectionById(BRIG_SECTION_INDEX_OPERAND));
}

inline const BrigSectionRaw& BrigContainer::debugInfo() const {
    return static_cast<const BrigSectionRaw&>(
        sectionById(BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED));
}

} // namespace HSAIL_ASM

#endif // INCLUDED_HSAIL_BRIG_CONTAINER_H

