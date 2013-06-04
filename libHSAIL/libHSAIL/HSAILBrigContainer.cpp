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
#include "HSAILBrigContainer.h"
#include "Brig.h"
#include "HSAILItems.h"

#include <algorithm>
#include <iostream>


namespace HSAIL_ASM {

const BrigSectionImpl& BrigContainer::sectionById(int id) const {
    switch(id) {
    case BRIG_SECTION_CODE:
        return m_insts;
    case BRIG_SECTION_DIRECTIVES:
        return m_directives;
    case BRIG_SECTION_OPERANDS:
        return m_operands;
    case BRIG_SECTION_DEBUG:
        return m_dChunks;
    case BRIG_SECTION_STRINGS:
        return m_strings;
    default:
        assert(0);
        return *(BrigSectionImpl*)0;
    }
}

BrigSectionImpl& BrigContainer::sectionById(int id)  {
    return const_cast<BrigSectionImpl&>(const_cast<const BrigContainer*>(this)->sectionById(id));
}

class StringRefComparer
{
    StringSection& m_section;
public:
    StringRefComparer(StringSection* section) : m_section(*section) {}
    bool operator()(Offset testStrOfs,const SRef& key) {
        return m_section.getString(testStrOfs) < key;
    }
    bool operator()(Offset testStrOfs,Offset key) {
        return m_section.getString(testStrOfs) <  m_section.getString(key);
    }
};

void StringSection::initStringSet()
{
    const char * const s_begin = getData(NUM_BYTES_RESERVED);
    const char * const s_end   = getData(size());
    size_t const hdrSize = offsetof(Brig::BrigString,bytes);
    for (const char *p = s_begin; p < s_end;
         p += hdrSize + align(reinterpret_cast<const Brig::BrigString*>(p)->byteCount,ITEM_ALIGNMENT)) { // TBD095 make this cleaner
         m_stringSet.push_back( getOffset(p) );
    }
    std::sort(m_stringSet.begin(),m_stringSet.end(),StringRefComparer(this));
}

Offset StringSection::addString(const SRef& newStr)
{
    if (m_stringSet.empty() && !isEmpty()) {
        initStringSet();
    }
    std::vector<Offset>::iterator const i = std::lower_bound(
        m_stringSet.begin(),m_stringSet.end(),
        newStr,StringRefComparer(this));

    if (i!=m_stringSet.end() && getString(*i)==newStr) {
        return *i;
    }

    size_t const allocSize = align(newStr.length(),ITEM_ALIGNMENT);
    size_t const hdrSize = offsetof(Brig::BrigString,bytes);

    Offset const secEndOffset = (Offset)size();
    Brig::BrigString* s = reinterpret_cast<Brig::BrigString*>(insertData(secEndOffset,static_cast<unsigned>(hdrSize + allocSize)));

    zeroPaddedCopy(s->bytes,newStr.begin,newStr.length(),allocSize);
    s->byteCount = static_cast<uint32_t>(newStr.length());

    m_stringSet.insert(i,secEndOffset);
    return secEndOffset;
}

template <typename Item>
class RefPatcher
{
    const std::map<Offset,Offset>& m_old2new;

    template <typename I>
    void patchRef(ItemRef<I> i) const {
        Brig::BrigOperandOffset32_t const o = i.deref();
        if (o!=0) {
            std::map<Brig::BrigOperandOffset32_t,Brig::BrigOperandOffset32_t>::const_iterator const f = m_old2new.find(o);
            if (f!=m_old2new.end()) {
                i.deref() = (*f).second;
            }
        }
    }

    template <typename I>
    void visit(ItemRef<I> ref,Item*) const { patchRef(ref); }
    template <typename T>
    void visit(T,...) const {}

public:
    RefPatcher(const std::map<Offset,Offset>& map)
        : m_old2new(map) {}

    template <typename I>
    void operator() ( ItemRef<I> ref, const char*, int x=0) const { visit(ref,reinterpret_cast<I*>(NULL)); }

    template <typename I, typename T, size_t ValOffset>
    void operator() ( TrailingRefs<I,T,ValOffset> values,const char*, int x=0) const {
        for(unsigned i=0; i<values.size(); ++i) {
            visit(values[i],reinterpret_cast<T*>(NULL));
        }
    }

    template <typename T>
    void operator() ( T, const char*, int x=0) const {} // all others
};


bool operator < (OperandReg r1,  OperandReg r2)
{
    // since strings are unique we can compare raw offsets instead of string text
    return r1.brig()->reg < r2.brig()->reg;
}

/*
bool operator < (OperandIndirect i1,  OperandIndirect i2)
{
    OperandReg r1 = i1.reg();
    OperandReg r2 = i2.reg();

    if (!r1) {
        return !r2 ? i1.offset() < i2.offset() : true;
    }
    if (!r2) {
        return false;
    }
    return r1 < r2 || ( !(r2 < r1) && i1.offset() < i2.offset() ) ;
}*/

class CopyIfNotThere
{
    typedef std::vector<Brig::BrigOperandOffset32_t>    SetContainer;

    OperandsSection&  m_newSection;
    std::map<Offset,Offset>& m_old2new; // old offset -> new offset

    // one lookup table for each operand kind, this could be done using typelists
    SetContainer             m_regLookup;
    //SetContainer             m_indRegLookup;

    void recordMapping(Offset oldOffset,Offset newOffset) {
        bool const res = m_old2new.insert(std::make_pair(oldOffset,newOffset)).second;
        assert(res);
    }

    Brig::BrigOperandOffset32_t copy(Operand o) {
        Brig::BrigOperandOffset32_t secEnd = m_newSection.size();
        m_newSection.insertAtOffset(secEnd,o);
        recordMapping(o.brigOffset(),secEnd);
        return secEnd;
    }

    template <typename Item>
    class BrigItemLess : public std::binary_function< Brig::BrigOperandOffset32_t, Item, bool >
    {
        typename Item::MySection& m_section;
    public:
        BrigItemLess(typename Item::MySection& s) : m_section(s) {}
        bool operator() ( Brig::BrigOperandOffset32_t o1, Item i2 ) const { return Item(&m_section,o1) < i2; }
    };

    template <typename Item>
    void copyIfNotThere(Item item, std::vector<Brig::BrigOperandOffset32_t>& lookup) {
        SetContainer::iterator found =
            std::lower_bound(lookup.begin(),lookup.end(),item, BrigItemLess<Item>(m_newSection) );
        if (found!=lookup.end()) {
            Item foundItem(&m_newSection,*found);
            if (!(item < foundItem)) {
                recordMapping(item.brigOffset(),foundItem.brigOffset());
                return;
            }
        }
        Brig::BrigOperandOffset32_t ofs = copy(item);
        lookup.insert(found,ofs);
    }

public:
    CopyIfNotThere(OperandsSection& newSection, std::map<Offset,Offset>& old2new)
        : m_newSection(newSection)
        , m_old2new(old2new) {}

    void operator()( OperandReg o ) {
        copyIfNotThere(o,m_regLookup);
    }
	// TBD095 other operands collapse
    /*void operator()( OperandIndirect o ) {
        copyIfNotThere(o,m_indRegLookup);
    }*/
    void operator()( Operand o ) {
        copy(o); // just copy the rest
    }
};

void BrigContainer::optimizeOperands()
{
    OperandsSection newSection(this);
    newSection.reserve(operands().size());

    std::map<Offset,Offset> old2new;
    {
        CopyIfNotThere copyIfNotThere(newSection,old2new);
        for (Operand o = operands().begin(), e = operands().end(); o != e; o = o.next()) {
            dispatchByItemKind(o,copyIfNotThere);
        }
    }

    // Patch all references using old2new map
    // refs inbetween operands
    RefPatcher<Operand> refPatcher(old2new);
    for (Operand o = newSection.begin(), e = newSection.end(); o != e; o = o.next()) {
        enumerateFields(o,refPatcher);
    }
    // refs from instructions
    for (Inst i = insts().begin(), e = insts().end(); i != e; i = i.next()) {
        enumerateFields(i,refPatcher);
    }
    // refs from directives (DirectiveControl)
    for (Directive d = directives().begin(), e = directives().end(); d != e; d = d.next()) {
        enumerateFields(d,refPatcher);
    }

    operands().swapData(newSection);
}

// search for a BlockString with a name of "hsa_dwarf_debug", this marks
// the beginning of a group of BlockNumerics which make up the elf container
//
// Input: any directive inside the debug section
//        end of debug section
// Returns: the directive following the matching BlockString (the beginning of
//          the BlockNumerics), or the end directive of the section if no
//          matching BlockString is found
//
static Directive findHsaDwarfDebugBlock( Directive d, Directive d_end )
{
    for ( ; d != d_end ; d = d.next() )
    {
        if  ( d.brig()->kind == Brig::BRIG_DIRECTIVE_BLOCK_STRING )
        {
            BlockString bStr( d );
            if ( bStr.string() == "hsa_dwarf_debug" )
                return d.next();
        }
    }
    return d;
}

// extracts the BlockNumeric data, appending it to the accumulated dbg bytes
//
// Input: d: a BlockNumeric directive
//        d_end: end of debug section
//        the dbg info data container
//
// Returns: the first non-BlockNumeric directive following "d" or the end
//          of the section
//
static Directive extractDataFromHsaDwarfDebugBlock( Directive d,
                                                    Directive d_end,
                                                    std::ostream & out )
{
    for ( ; d != d_end && (d.brig()->kind == Brig::BRIG_DIRECTIVE_BLOCK_NUMERIC); d = d.next() ) {
        BlockNumeric bNumeric( d );
        // append the blocknumeric's bytes to the dbg stream
        //
        out.write( (const char *)bNumeric.data().begin(), bNumeric.data().numElements() );
    }
    return d;
}

static Directive extractDataFromHsaDwarfDebugBlock( Directive d,
                                                    Directive d_end,
                                                    std::vector<char> & out )
{
    for ( ; d != d_end && (d.brig()->kind == Brig::BRIG_DIRECTIVE_BLOCK_NUMERIC); d = d.next() ) {
        BlockNumeric bNumeric( d );
        // append the blocknumeric's bytes to the dbg stream
        //
        out.insert(out.end(), bNumeric.data().begin(), bNumeric.data().end());
    }
    return d;
}



// The hsa BRIG DWARF debug information is an ELF disk-image bytestream stored
// in a block in the Brig container's .debug section with a BlockString value
// of "hsa_dwarf_debug".
// Find this block, concatenate the byteValues of all the
// BlockNumerics (all are Brig::BRIG_TYPE_B8), and write out to a binary file.
//
// format of hsa_dwarf_debug blocks (required!):
// BlockStart, BlockString ("hsa_dwarf_debug"), BlockNumeric, ..., BlockEnd
//
// Any other formats/arrangements of blocks are skipped.
//
void BrigContainer::ExtractDebugInformationToStream( std::ostream & out )
{
    for ( Directive d = this->debugChunks().begin(), d_end = this->debugChunks().end(); d != d_end; )
    {
        d = findHsaDwarfDebugBlock( d, d_end );
        d = extractDataFromHsaDwarfDebugBlock( d, d_end, out );
    }
}

void BrigContainer::ExtractDebugInformationToVector( std::vector<char> & out )
{
    for ( Directive d = this->debugChunks().begin(), d_end = this->debugChunks().end(); d != d_end; )
    {
        d = findHsaDwarfDebugBlock( d, d_end );
        d = extractDataFromHsaDwarfDebugBlock( d, d_end, out );
    }
}

}
