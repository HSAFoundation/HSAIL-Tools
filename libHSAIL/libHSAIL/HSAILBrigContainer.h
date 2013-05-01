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
#include "brig.h"
#include "HSAILUtilities.h"

#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iosfwd>
#include <limits>
#include <climits>
#include <stdint.h>

namespace HSAIL_ASM {

typedef unsigned Offset;

class Directive;
class Inst;
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

enum SectionID {
    BRIG_SECTION_STRINGS,
    BRIG_SECTION_DIRECTIVES,
    BRIG_SECTION_CODE,
    BRIG_SECTION_OPERANDS,
    BRIG_SECTION_DEBUG,
    NUM_BRIG_SECTIONS
};


template <typename Item> struct GetSectionID;

template <> struct GetSectionID<Inst>      { static const SectionID id=BRIG_SECTION_CODE;       };
template <> struct GetSectionID<Operand>   { static const SectionID id=BRIG_SECTION_OPERANDS;   };
template <> struct GetSectionID<Directive> { static const SectionID id=BRIG_SECTION_DIRECTIVES; };

/// implementation of a Brig section. This is a buffer of plain raw data
/// with insert/append/delete modificators.
/// Note that as the buffer is resizable, i.e. the data is movable,
/// appending a new item may invalidate all direct references to the data,
/// but not iterators, as iterators use offsets.
class BrigSectionImpl
{
public:
    typedef std::vector<char> Buffer; // TBD possibly switch to a more optimal container

private:
    class BrigContainer *m_container;

    char                *m_data;
    char                *m_dataEnd;

    Buffer               m_buffer;

    typedef std::vector< std::pair<Offset, SourceInfo > > SectionSourceInfo;
    SectionSourceInfo    m_sourceInfo;

    bool hasOwnBuffer() const { return !m_buffer.empty(); }

    void syncPtrsWithBuffer() {
        m_data = &m_buffer[0];
        m_dataEnd = m_data + m_buffer.size();
    }

protected:
    // allow to swap only for 'final' classes
    void swapData(BrigSectionImpl& other) {
        assert(hasOwnBuffer() && other.hasOwnBuffer());
        m_buffer.swap(other.m_buffer);
        m_sourceInfo.swap(other.m_sourceInfo);
        syncPtrsWithBuffer();
        other.syncPtrsWithBuffer();
    }

public:

    /// first bytes of section are NUM_BYTES_RESERVED nulls.
    enum { NUM_BYTES_RESERVED = 4 };
    enum { ITEM_ALIGNMENT = 4 };

    /// constructor.
    /// @param container - parent container this section belongs to.
    BrigSectionImpl(class BrigContainer *container=NULL)
        : m_container(container)
    {
        m_buffer.resize(NUM_BYTES_RESERVED);
        syncPtrsWithBuffer();
    }

    /// constructor.
    /// @param container - parent container this section belongs to.
    BrigSectionImpl(char *data, size_t size, class BrigContainer *container=NULL)
        : m_container(container)
        , m_data(data)
        , m_dataEnd(data+size)
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
    bool isEmpty() const { return size() <= NUM_BYTES_RESERVED; }

    virtual void clear() {
        assert(hasOwnBuffer());
        m_buffer.clear();
        m_buffer.resize(NUM_BYTES_RESERVED);
        m_sourceInfo.clear();
        syncPtrsWithBuffer();
    }

    void setData(const char* data, size_t numBytes) {
        clear();
        Buffer tmpBuf(data, data+numBytes);
        m_buffer.swap(tmpBuf);
        syncPtrsWithBuffer();
    }

    void reserve(size_t numBytes) {
        assert(hasOwnBuffer());
        m_buffer.reserve(numBytes);
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

    char* getData(Offset offset) { return m_data + offset; }
    const char* getData(Offset offset) const { return m_data + offset; }

    /// insert uninitialized data into the section.
    /// May invalidate pointers to the section data.
    /// @param offset - offset where data should be inserted.
    /// @param numBytes - number of bytes to be inserted.
    /// @param fill - filling value
    char* insertData(Offset offset, unsigned numBytes, char fill='\xFF') {
        assert(hasOwnBuffer());
        assert(offset <= m_buffer.size());
        m_buffer.insert(m_buffer.begin() + offset,numBytes,fill);
        syncPtrsWithBuffer();
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
        syncPtrsWithBuffer();
        return getData(offset);
    }

    /// deletes data shifting the rest to the beginning of the section.
    /// @param offset - offset from where to start delete.
    /// @param numBytes - num bytes to delete.
    void deleteData(Offset   offset, unsigned numBytes) {
        assert(hasOwnBuffer());
        assert(offset + numBytes <= m_buffer.size());
        m_buffer.erase(m_buffer.begin() + offset,m_buffer.begin() + offset + numBytes);
        syncPtrsWithBuffer();
    }

    /// size of the section in bytes.
    Offset size() const { return (Offset)(m_dataEnd - m_data); }

    /// direct access to buffer for load/store operations.
    const Buffer& bufferImpl() const { return m_buffer; }

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
        assert((item.brigOffset() + item.brig()->size) == size());

        Offset const oldNumBytes = item.brig()->size;
        Offset const newNumBytes = (Offset)std::min<size_t>(HSAIL_ASM::align(reqSize,ITEM_ALIGNMENT),std::numeric_limits<uint16_t>::max()-ITEM_ALIGNMENT);

        if (newNumBytes > oldNumBytes) {
            m_buffer.resize(item.brigOffset() + newNumBytes);
            syncPtrsWithBuffer();
            memset(reinterpret_cast<char*>(item.brig()) + oldNumBytes, 0, newNumBytes - oldNumBytes);
            item.brig()->size = static_cast<uint16_t>(newNumBytes);
        }
        return item.brig()->size;
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

template <typename Item, int ID_>
class BrigSection : public BrigSectionImpl
{
public:
    enum {
        ID = ID_
    };

    BrigSection(class BrigContainer* c=NULL) :  BrigSectionImpl(c) { }

    BrigSection(char *data, size_t size, class BrigContainer *container=NULL)
        : BrigSectionImpl(data,size,container) {}

    Item begin() { return Item(this, NUM_BYTES_RESERVED); }
    Item end() { return Item(this, size()); }

    void swapData(BrigSection& other) {
        BrigSectionImpl::swapData(other);
    }
};

typedef BrigSection<Inst,     BRIG_SECTION_CODE>       CodeSection;
typedef BrigSection<Directive,BRIG_SECTION_DIRECTIVES> DirectivesSection;
typedef BrigSection<Operand,  BRIG_SECTION_OPERANDS>   OperandsSection;
typedef BrigSection<Directive,BRIG_SECTION_DEBUG>      DebugChunksSection;

class StringSection : public BrigSectionImpl
{
    enum {
        ID = BRIG_SECTION_STRINGS
    };
    std::vector< Offset > m_stringSet; // ordered by strings they point to
    void initStringSet();
public:
    StringSection(class BrigContainer *container=NULL)
        : BrigSectionImpl(container) {}

    StringSection(char *data, size_t size, class BrigContainer *container=NULL)
        : BrigSectionImpl(data,size,container) {}

    Offset addString(const SRef& newStr);
    SRef getString(Offset offset) const {
        const Brig::BrigString* s = getData<const Brig::BrigString>(offset);
        const char *begin = reinterpret_cast<const char*>(s->bytes);
        return SRef(begin,begin + s->byteCount);
    }

    virtual void clear() {
        BrigSectionImpl::clear();
        m_stringSet.clear();
    }

    void swapData(StringSection& other) {
        BrigSectionImpl::swapData(other);
        m_stringSet.swap(other.m_stringSet);
    }

    const static size_t maxStringLen = UINT_MAX;
};

/// container for Brig sections. This is a basically a set of sections that
/// comprise Brig.
class BrigContainer {
    // INSTANCE DATA
private:
    StringSection       m_strings;
    CodeSection         m_insts;
    DirectivesSection   m_directives;
    OperandsSection     m_operands;
    DebugChunksSection  m_dChunks;

public:

    BrigContainer() {
        m_strings.container(this);
        m_insts.container(this);
        m_directives.container(this);
        m_operands.container(this);
        m_dChunks.container(this);
    }

    BrigContainer(char *stringData,     size_t stringsSize,
                  char *directivesData, size_t directivesSize,
                  char *instData,       size_t instSize,
                  char *operandData,    size_t operandSize,
                  char *debugData,      size_t debugSize)
        : m_strings(stringData,stringsSize)
        , m_insts(instData,instSize)
        , m_directives(directivesData,directivesSize)
        , m_operands(operandData,operandSize)
        , m_dChunks(debugData,debugSize)
    {
        m_strings.container(this);
        m_insts.container(this);
        m_directives.container(this);
        m_operands.container(this);
        m_dChunks.container(this);
    }

    int validate(std::string *outErrorMessage, const SourceInfo **outSourceInfo);
    // Validate the structure of this BRIG container.
    // In case an error is found, fill the specified outErrorMessage with the information
    // on the error, and outSourceInfo with the location of the error in the source file,

    // if such information is available. Return zero on success, or a non-zero error code
    // in case of an error.

    CodeSection&               insts();
    CodeSection&               code();
    DirectivesSection&         directives();
    OperandsSection&           operands();
    DebugChunksSection&        debugChunks();
    StringSection&             strings();

    const CodeSection&         insts()       const;
    const CodeSection&         code()        const;
    const DirectivesSection&   directives()  const;
    const OperandsSection&     operands()    const;
    const DebugChunksSection&  debugChunks() const;
    const StringSection&       strings()     const;

    template <SectionID id>        BrigSectionImpl& sectionById();
    template <SectionID id>  const BrigSectionImpl& sectionById() const;

    BrigSectionImpl&           sectionById(int id);
    const BrigSectionImpl&     sectionById(int id) const;

    template <typename Item>       BrigSectionImpl& section() {
        return sectionById< GetSectionID< typename Item::Kind >::id >();
    }
    template <typename Item> const BrigSectionImpl& section() const {
        return sectionById< GetSectionID< typename Item::Kind >::id >();
    }

    // Append a default-initialized item (i.e. an instruction, operand, directive or debug info) to
    // a corresponding section of this container, and return the appropriate item proxy.
    template<typename Item> Item append() {
        return section< typename Item::Kind >().append<Item>();
    }

    // the same with source info
    template<typename Item> Item append(const SourceInfo& si) {
        return section< typename Item::Kind >().append<Item>(si);
    }

    template<typename Item>
    const SourceInfo* sourceInfo( const Item& i ) const {
        return section< typename Item::Kind >().sourceInfo(i);
    }

    Offset addString(const SRef& s) { return strings().addString(s); }
    SRef getString(Offset offset) const { return m_strings.getString(offset); }

    void optimizeOperands();
    void ExtractDebugInformationToStream( std::ostream & out );

    void clear() {
        m_strings.clear();
        m_insts.clear();
        m_directives.clear();
        m_operands.clear();
        m_dChunks.clear();
    }
};

// non-const
inline CodeSection&                        BrigContainer::insts()              { return m_insts; }
inline CodeSection&                        BrigContainer::code()               { return m_insts; }
inline DirectivesSection&                  BrigContainer::directives()         { return m_directives; }
inline OperandsSection&                    BrigContainer::operands()           { return m_operands; }
inline DebugChunksSection&                 BrigContainer::debugChunks()        { return m_dChunks; }
inline StringSection&                      BrigContainer::strings()            { return m_strings; }

template <> inline BrigSectionImpl&        BrigContainer::sectionById<BRIG_SECTION_CODE>()       { return m_insts; }
template <> inline BrigSectionImpl&        BrigContainer::sectionById<BRIG_SECTION_DIRECTIVES>() { return m_directives; }
template <> inline BrigSectionImpl&        BrigContainer::sectionById<BRIG_SECTION_OPERANDS>()   { return m_operands; }
template <> inline BrigSectionImpl&        BrigContainer::sectionById<BRIG_SECTION_DEBUG>()      { return m_dChunks; }
template <> inline BrigSectionImpl&        BrigContainer::sectionById<BRIG_SECTION_STRINGS>()    { return m_strings; }

// const
inline const CodeSection&                  BrigContainer::insts()              const { return m_insts; }
inline const CodeSection&                  BrigContainer::code()               const { return m_insts; }
inline const DirectivesSection&            BrigContainer::directives()         const { return m_directives; }
inline const OperandsSection&              BrigContainer::operands()           const { return m_operands; }
inline const DebugChunksSection&           BrigContainer::debugChunks()        const { return m_dChunks; }
inline const StringSection&                BrigContainer::strings()            const { return m_strings; }

template <> inline const BrigSectionImpl&  BrigContainer::sectionById<BRIG_SECTION_CODE>()       const { return m_insts; }
template <> inline const BrigSectionImpl&  BrigContainer::sectionById<BRIG_SECTION_DIRECTIVES>() const { return m_directives; }
template <> inline const BrigSectionImpl&  BrigContainer::sectionById<BRIG_SECTION_OPERANDS>()   const { return m_operands; }
template <> inline const BrigSectionImpl&  BrigContainer::sectionById<BRIG_SECTION_DEBUG>()      const { return m_dChunks; }
template <> inline const BrigSectionImpl&  BrigContainer::sectionById<BRIG_SECTION_STRINGS>()    const { return m_strings; }

} // namespace HSAIL_ASM

#endif // INCLUDED_HSAIL_BRIG_CONTAINER_H
