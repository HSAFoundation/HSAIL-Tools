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
#include "HSAILScope.h"
#include "HSAILBrigantine.h"

#include <algorithm>
#include <iostream>


namespace HSAIL_ASM {

BrigContainer::BrigContainer()
{
    m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new DataSection(this)));
    m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new CodeSection(this)));
    m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new OperandSection(this)));
}

BrigContainer::BrigContainer(const void *dataData,
              const void *codeData,
              const void *operandData,
              const void *debugData)
{
    m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new DataSection(dataData, this)));
    m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new CodeSection(codeData, this)));
    m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new OperandSection(operandData, this)));
    if (debugData) {
        m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new BrigSectionRaw(debugData, this)));
    }
}

BrigContainer::BrigContainer(const Brig::BrigModule* brigModule) {
    assert(brigModule->sectionCount >= Brig::BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED);
    m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new DataSection(brigModule->section[Brig::BRIG_SECTION_INDEX_DATA], this)));
    m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new CodeSection(brigModule->section[Brig::BRIG_SECTION_INDEX_CODE], this)));
    m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new OperandSection(brigModule->section[Brig::BRIG_SECTION_INDEX_OPERAND], this)));
    for(unsigned i=3; i<brigModule->sectionCount; ++i) {
        m_sections.push_back(std::unique_ptr<BrigSectionImpl>(new BrigSectionRaw(brigModule->section[i], this)));
    }
}

SRef brigSectionNameById(int id)
{
  switch(id) {
  case Brig::BRIG_SECTION_INDEX_DATA:
    return SRef("hsa_data");
  case Brig::BRIG_SECTION_INDEX_CODE:
    return SRef("hsa_code");
  case Brig::BRIG_SECTION_INDEX_OPERAND:
    return SRef("hsa_operand");
  default:
    assert(0);
    return SRef();
  }
}


BrigSectionImpl::BrigSectionImpl(SRef name, class BrigContainer *container)
    : m_container(container)
{
    // m_buffer.reserve(1024*1024);
    unsigned headerByteCount = (unsigned)(sizeof(Brig::BrigSectionHeader) - 1 + name.length());
    headerByteCount = (headerByteCount + ITEM_ALIGNMENT - 1) & ~(ITEM_ALIGNMENT - 1);
    m_buffer.resize(headerByteCount);
    m_data = (Brig::BrigSectionHeader*)&m_buffer[0];
    secHeader()->byteCount = headerByteCount;
    secHeader()->headerByteCount = headerByteCount;
    secHeader()->nameLength = (unsigned)name.length();
    memcpy(&secHeader()->name, name.begin, name.length());
}

void BrigContainer::initSectionRaw(int index, SRef name)
{
    assert(index >= Brig::BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED);
    if (index >= getNumSections()) {
        m_sections.resize(index+1);
    }
    m_sections[index] = std::unique_ptr<BrigSectionImpl>(new BrigSectionRaw(name, this));
}

int BrigContainer::verifySection(int index, SRef data, std::ostream &errs)
{
    if (data.length() == 0) {
        if (index < Brig::BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED) {
            errs << "Mandatory section #" << index << " is empty" << std::endl;
            return 1;
        } else {
            return 0;
        }
    } else {
        const Brig::BrigSectionHeader *header = (const Brig::BrigSectionHeader*)data.begin;
        if (data.length() <= sizeof(Brig::BrigSectionHeader)
            || header->headerByteCount < sizeof(Brig::BrigSectionHeader)
            || data.length() < header->headerByteCount
            || header->headerByteCount < 3*sizeof(uint32_t) + header->nameLength)
        {
            errs << "Malformed header in section #" << index << std::endl;
            return 1;
        }
        if (data.length() != header->byteCount) {
            errs << "Section byteCount mismatch in section #" << index << std::endl;
            return 1;
        }
        if (index < Brig::BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED) {
            if (SRef((char*)header->name, (char*)header->name + header->nameLength) != brigSectionNameById(index)) {
                errs << "Section name mismatch in section #" << index << std::endl;
                return 1;
            }
        }
    }
    return 0;
}

int BrigContainer::loadSection(int index, BrigSectionImpl::Buffer& data, std::ostream &errs)
{
    if (verifySection(index, data, errs)) {
        return 1;
    }
    if (index >= Brig::BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED) {
        initSectionRaw(index, "dummy"); // \todo1.0
    }
    sectionById(index).swapInData(data);
    return 0;
}

class StringRefComparer
{
    DataSection& m_section;
public:
    StringRefComparer(DataSection* section) : m_section(*section) {}
    bool operator()(Offset testStrOfs,const SRef& key) {
        return m_section.getString(testStrOfs) < key;
    }
    bool operator()(Offset testStrOfs,Offset key) {
        return m_section.getString(testStrOfs) <  m_section.getString(key);
    }
};

void DataSection::initStringSet()
{
    const char * const s_begin = getData(secHeader()->headerByteCount);
    const char * const s_end   = getData(secHeader()->byteCount);
    size_t const hdrSize = offsetof(Brig::BrigData,bytes);
    for (const char *p = s_begin; p < s_end;
         p += hdrSize + align(reinterpret_cast<const Brig::BrigData*>(p)->byteCount,ITEM_ALIGNMENT)) { // TBD095 make this cleaner
         m_stringSet.push_back( getOffset(p) );
    }
    std::sort(m_stringSet.begin(),m_stringSet.end(),StringRefComparer(this));
}

Offset DataSection::addString(const SRef& newStr)
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

    Offset res = addStringImpl(newStr);
    m_stringSet.insert(i, res);
    return res;
}

Offset DataSection::addStringImpl(const SRef& newStr)
{
    size_t const allocSize = align(newStr.length(),ITEM_ALIGNMENT);
    size_t const hdrSize = offsetof(Brig::BrigData,bytes);

    Offset const secEndOffset = (Offset)size();
    Brig::BrigData* s = reinterpret_cast<Brig::BrigData*>(insertData(secEndOffset,static_cast<unsigned>(hdrSize + allocSize)));

    zeroPaddedCopy(s->bytes,newStr.begin,newStr.length(),allocSize);
    s->byteCount = static_cast<uint32_t>(newStr.length());

    return secEndOffset;
}


template <typename Item>
class RefPatcher
{
    typedef std::map<Offset,Offset> Map;
    const Map& m_old2new;

    void patchRef(Offset& ref) const {
        if (ref!=0) {
            Map::const_iterator f = m_old2new.find(ref);
            if (f!=m_old2new.end()) {
                ref = (*f).second;
            }
        }
    }

    // \todo1.0: we are preventing deduping of lists in ListRef
    // implementation and using this to make lists mutable.

    // A better implementation would assume that lists are immutable and
    // copy them duting update. However this is a rather elaborate task.

    template<typename I>
    void visit(ListRef<I> list, Item*) const {
      int size = list.size();
      for(int i=0; i<size; ++i) {
        patchRef(list.writeAccess(i).deref());
      }
    }

    template <typename I>
    void visit(ListRef<I> list, ...) const { }

    template <typename I>
    void visit(ItemRef<I> ref, Item*) const { patchRef(ref.deref()); }

    template <typename I>
    void visit(ItemRef<I>, ... ) const {}

public:
    RefPatcher(const std::map<Offset,Offset>& map)
        : m_old2new(map) {}

    template <typename I>
    void operator() ( ItemRef<I> ref, ...) const { visit(ref, reinterpret_cast<I*>(0)); }

    template <typename I>
    void operator() ( ListRef<I> ref, ...) const { visit(ref, reinterpret_cast<I*>(0)); }

    template <typename T>
    void operator() ( const T&, ... ) const {} // all others
};

class CollectExternDefs
{
    Scope& m_scope;
    template <typename Dir>
    void record(Dir d) {
        assert(isGlobalName(d.name()));
        if (d.linkage()==Brig::BRIG_LINKAGE_PROGRAM) {
            if (!d.modifier().isDefinition()) {
                m_scope.add(d.name(),d);
            } else {
                m_scope.replaceOtherwiseAdd(d.name(),d);
            }
        }
    }
public:
    CollectExternDefs(Scope& scope)
        : m_scope(scope)
    {}
    Code operator()(DirectiveVariable v) {
        record(v);
        return v.next();
    }
    Code operator()(DirectiveFbarrier v) {
        record(v);
        return v.next();
    }
    Code operator()(DirectiveFunction fx) {
        record(fx);
        return fx.nextModuleEntry();
    }
    Code operator()(DirectiveIndirectFunction fx) {
        record(fx);
        return fx.nextModuleEntry();
    }
    Code operator()(DirectiveKernel k) {
        record(k);
        return k.nextModuleEntry();
    }
    Code operator()(DirectiveSignature sig) {
        return sig.nextModuleEntry();
    }
    Code operator()(Code d) {
        return d.next();
    }
};


class MakeDecl2DefMap
{
    std::map<Offset,Offset>& m_decl2def;
    Scope&                   m_overallScope;

    std::unique_ptr<Scope>     m_moduleScope;

    template <typename Dir>
    void record(Dir d) {
        assert(m_moduleScope.get()!=NULL);
        assert(isGlobalName(d.name()));
        if (!d.modifier().isDefinition()) {
            Dir decl = d;
            bool const isFirstInModule = m_moduleScope->add(decl.name(),decl);
            if (isFirstInModule && decl.linkage() == Brig::BRIG_LINKAGE_PROGRAM) {
                Directive def = m_overallScope.get<Directive>(decl.name());
                if (def) {
                    m_decl2def[ decl.brigOffset() ] = def.brigOffset();
                } // else // TBD report symbol not defined
            }
        } else {
            Dir def = d;
            Directive decl = m_moduleScope->get<Directive>(def.name());
            if (decl) {
                m_decl2def[ decl.brigOffset() ] = def.brigOffset();
            } else {
                m_moduleScope->add(def.name(),def);
            }
        }
    }
    void resetModuleScope() {
        m_moduleScope.reset(new Scope(m_overallScope.container()));
    }

public:
    MakeDecl2DefMap(std::map<Offset,Offset>& decl2def, Scope& overallScope)
        : m_decl2def(decl2def)
        , m_overallScope(overallScope) {
        resetModuleScope();
    }
    Code operator()(DirectiveVersion v) {
        resetModuleScope();
        return v.next();
    }
    Code operator()(DirectiveVariable v) {
        record(v);
        return v.next();
    }
    Code operator()(DirectiveFbarrier v) {
        record(v);
        return v.next();
    }
    Code operator()(DirectiveFunction fx) {
        record(fx);
        return fx.nextModuleEntry();
    }
    Code operator()(DirectiveIndirectFunction fx) {
        record(fx);
        return fx.nextModuleEntry();
    }
    Code operator()(DirectiveKernel k) {
        record(k);
        return k.nextModuleEntry();
    }
    Code operator()(DirectiveSignature sig) {
        return sig.nextModuleEntry();
    }
    Code operator()(Code d) {
        return d.next();
    }
};

void BrigContainer::patchDecl2Defs() {
    std::map<Offset,Offset> decl2defMap;
    {
        Scope overallScope(this);
        {
            CollectExternDefs collectDefs(overallScope);
            for (Code d = code().begin(), e = code().end(); d != e; ) {
                d = dispatchByItemKind<Code,Code>(d,collectDefs);
            }
        }
        MakeDecl2DefMap makeDecl2DefMap(decl2defMap,overallScope);
        for (Code d = code().begin(), e = code().end(); d != e; ) {
            d = dispatchByItemKind<Code,Code>(d,makeDecl2DefMap);
        }
    }

    RefPatcher<Code> refPatcher(decl2defMap);
    for (Operand o = operands().begin(), e = operands().end(); o != e; o = o.next()) {
        enumerateFields(o,refPatcher);
    }
}

const Brig::BrigModule*
BrigContainer::getBrigModule() {
    using namespace Brig;
    m_brigModuleBuffer.resize(offsetof(BrigModule, section) + sizeof(BrigSectionHeader*) * getNumSections());
    BrigModule* module = (BrigModule*)&m_brigModuleBuffer[0];
    module->sectionCount = getNumSections();
    for(int i=0; i<getNumSections(); ++i) {
        module->section[i] = (BrigSectionHeader*)sectionById(i).getData(0);
    }
    return module;
}


}
