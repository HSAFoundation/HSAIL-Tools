// University of Illinois/NCSA
// Open Source License
//
// Copyright (c) 2013-2015, Advanced Micro Devices, Inc.
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
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iosfwd>
#include <iterator>
#include <set>
#include <vector>

#include "HSAILDisassembler.h"
#include "HSAILDump.h"
#include "HSAILItems.h"
#include "HSAILSRef.h"

namespace HSAIL_ASM {

//--------------------------------------------------------------------------------------------
// YamlStreambuf

class YamlStreambuf : public std::streambuf {
private:
    static const unsigned INDENTATION_SIZE = 2;

    std::ostream* basicStream;
    std::streambuf* basicBuf;

    unsigned indentLevel;
    bool atLineStart;
    bool inArray;

protected:
    virtual int_type overflow(int_type ch) override {
        if (atLineStart && ch != '\n') {
            std::string indent(INDENTATION_SIZE * indentLevel, ' ');
            basicBuf->sputn(indent.data(), indent.size());
            atLineStart = false;
            if (inArray) {
                basicBuf->sputn("- ", 2);
            }
        } else if (ch == '\n') {
            atLineStart = true;
        }
        return basicBuf->sputc(ch);
    }

public:
    explicit YamlStreambuf(std::ostream& stream)
        : basicStream(&stream),
          basicBuf(stream.rdbuf()),
          indentLevel(0),
          atLineStart(true),
          inArray(false)
    {
        basicStream->rdbuf(this);
    }

    virtual ~YamlStreambuf() {
        basicStream->rdbuf(basicBuf);
    }

    void indent() {
        ++indentLevel;
    }

    void unindent() {
        if (indentLevel > 0) {
            --indentLevel;
        }
    }

    void setInArray(bool inArray_ = true) {
        inArray = inArray_;
    }
};

//--------------------------------------------------------------------------------------------
// ItemCollector

struct ItemOffsetLess {
    bool operator() (ItemBase first, ItemBase second) const {
        return first.brigOffset() < second.brigOffset();
    }
};

bool itemValid(ItemBase item) {
    return item && (item.brigOffset() < item.section()->size());
}

class ItemCollector {
private:
    std::set<Code, ItemOffsetLess> m_code;
    std::set<Operand, ItemOffsetLess> m_operands;
    std::set<Offset> m_data;

    // not copyable
    ItemCollector(const ItemCollector&);
    ItemCollector& operator=(const ItemCollector&);

public:
    template <typename Item>
    explicit ItemCollector(Item item) {
        if (itemValid(item)) {
            dispatchByItemKind(item, *this);
        }
    }

    template <typename Item>
    void operator()(Item item) {
        appendItem(item);
        enumerateFields(item, *this);
    }

    template <typename ValueType>
    void operator()(const ValueType& v, const char* name) {}

    void operator()(const StrRef& strRef, const char* name) {
        appendItem(strRef.deref());
    }

    template <typename Item>
    void operator()(const ItemRef<Item>& iref, const char* name) {
        appendItem(static_cast<Item>(iref));
    }

    template <typename Item>
    void operator()(const ListRef<Item>& lref, const char* name) {
        appendItem(lref.deref());
        for (int i = 0; i < lref.size(); ++i) {
            appendItem(lref[i]);
        }
    }

    std::vector<Code> code() const {
        std::vector<Code> vcode(m_code.begin(), m_code.end());
        std::sort(vcode.begin(), vcode.end(), ItemOffsetLess());
        return vcode;
    }

    std::vector<Operand> operands() const {
        std::vector<Operand> voperands(m_operands.begin(), m_operands.end());
        std::sort(voperands.begin(), voperands.end(), ItemOffsetLess());
        return voperands;
    }

    std::vector<Offset> data() const {
        std::vector<Offset> vdata(m_data.begin(), m_data.end());
        std::sort(vdata.begin(), vdata.end());
        return vdata;
    }

private:
    template <typename Item>
    BrigSectionIndex appendItem(Item item) {
        if (!item) {
            return BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED;
        }
        if (static_cast<BrigSectionIndex>(Item::SECTION) == BRIG_SECTION_INDEX_CODE) {
            if (m_code.count(item) == 0) {
                m_code.insert(item);
                dispatchByItemKind(item, *this);
            }
            return BRIG_SECTION_INDEX_CODE;
        } else if (static_cast<BrigSectionIndex>(Item::SECTION) == BRIG_SECTION_INDEX_OPERAND) {
            if (m_operands.count(item) == 0) {
                m_operands.insert(item);
                dispatchByItemKind(item, *this);
            }
            return BRIG_SECTION_INDEX_OPERAND;
        }
        assert(false);
        return BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED;
    }

    BrigSectionIndex appendItem(Offset offset) {
        m_data.insert(offset);
        return BRIG_SECTION_INDEX_DATA;
    }
};

//----------------------------------------------------------------------------------------------
// BrigDumper

class BrigDumper {
private:
    std::ostream& s;
    YamlStreambuf sbuf;

    // not copyable
    BrigDumper(const BrigDumper&);
    BrigDumper& operator=(const BrigDumper&);

public:
    explicit BrigDumper(std::ostream& s_): s(s_), sbuf(s) { }

    void dump(BrigContainer& c) {
        dumpPrologue(c);
        dumpSection(c.code());
        s.flush();
        dumpSection(c.operands());
        s.flush();
        dumpDataSection(c.strings());
        s.flush();
    }

    template <typename Item>
    void dump(Item item) {
        BrigContainer* c = item.container();
        const ItemCollector collector(item);
        dumpSection(c->code(), collector.code(), false);
        s.flush();
        dumpSection(c->operands(), collector.operands(), false);
        s.flush();
        dumpDataSection(c->strings(), collector.data(), false);
        s.flush();
    }

    // dump item
    template <typename Item>
    void operator()(Item item) {
        s << Item::kindName() << ": {";
        dumpItemBase(item.brigOffset(), item.byteCount());
        enumerateFields(item, *this);
        s << "}\n";
    }

    // dump field
    template <typename ValueType>
    void operator()(const ValueType& v, const char* name) {
        s << ", " << name << ": ";
        dumpValue(v);
    }

private:
    static std::string SectionName(BrigSectionIndex section) {
        switch (section) {
        case BRIG_SECTION_INDEX_DATA: return "Data";
        case BRIG_SECTION_INDEX_CODE: return "Code";
        case BRIG_SECTION_INDEX_OPERAND: return "Operands";
        default:
            assert(false);
            return "";
        }
    }

    template <typename Item>
    void dumpSection(BrigSection<Item, Item::SECTION>& section, bool dumpHeader = true) {
        dumpSectionPrologue(static_cast<BrigSectionIndex>(Item::SECTION), section.secHeader(), dumpHeader);
        for (Item i = section.begin(), end = section.end(); i != end; i = i.next()) {
            dispatchByItemKind(i, *this);
        }
        dumpSectionEpilogue();
    }

    template <typename Item>
    void dumpSection(const BrigSectionImpl& section, const std::vector<Item>& vector, bool dumpHeader = true) {
        if (vector.size() == 0) {
            return;
        }
        const BrigSectionHeader* header = section.secHeader();
        dumpSectionPrologue(static_cast<BrigSectionIndex>(Item::SECTION), header, dumpHeader);
        for (unsigned i = 0; i < vector.size(); ++i) {
            Item item = vector[i];
            if (!itemValid(item)) {
                continue;
            }
            dispatchByItemKind(item, *this);
        }
        dumpSectionEpilogue();
    }

    void dumpDataSection(DataSection& section, bool dumpHeader = true) {
        dumpSectionPrologue(BRIG_SECTION_INDEX_DATA, section.secHeader());
        for (DataSectionIterator it = section.begin(), end =section.end(); it != end; ++it) {
            dumpDataItem(it.offset(), *it);
        }
        dumpSectionEpilogue();
    }

    void dumpDataSection(DataSection& section, const std::vector<Offset>& vector, bool dumpHeader = true) {
        if (vector.size() == 0) {
            return;
        }
        dumpSectionPrologue(BRIG_SECTION_INDEX_DATA, section.secHeader(), dumpHeader);
        for (unsigned i = 0; i < vector.size(); ++i) {
            Offset offset = vector[i];
            dumpDataItem(offset, section.getString(offset));
        }
        dumpSectionEpilogue();
    }

    void dumpPrologue(BrigContainer& c) {
        s << "---\n";
        BrigModule_t header = c.getBrigModule();
        dumpModuleHeader(header);
        dumpSectionIndex(c, header->sectionIndex);
    }

    void dumpSectionPrologue(BrigSectionIndex index, const BrigSectionHeader* header, bool dumpHeader = true) {
        s << SectionName(index) << ":\n";
        sbuf.indent();
        sbuf.setInArray();
        if (dumpHeader) {
            dumpSectionHeader(header);
        }
    }

    void dumpSectionEpilogue() {
        sbuf.unindent();
        sbuf.setInArray(false);
    }

    void dumpModuleHeader(const BrigModuleHeader* header) {
        s << "ModuleHeader: {";
        s << "major: "; dumpValue(header->brigMajor); s << ", ";
        s << "minor: "; dumpValue(header->brigMinor); s << ", ";
        s << "byteCount: "; dumpValue(header->byteCount); s << ", ";
        s << "hash: ";
        dumpValue(
            SRef(reinterpret_cast<const char *>(&header->hash[0]),
                 reinterpret_cast<const char *>(&header->hash[63])));
        s << ", ";
        s << "sectionCount: "; dumpValue(header->sectionCount); s << ", ";
        s << "sectionIndex: "; dumpValue(header->sectionIndex);
        s << "}\n";
    }

    void dumpSectionIndex(BrigContainer& c, uint64_t sectionIndexOffset) {
        BrigModule_t module = c.getBrigModule();
        uint64_t* sectionIndex = reinterpret_cast<uint64_t *>(module) + (sectionIndexOffset / sizeof(uint64_t));
        s << "SectionIndex: [";
        for (int i = 0; i < c.getNumSections(); ++i) {
            if (i > 0) {
                s << ", ";
            }
            s << SectionName(static_cast<BrigSectionIndex>(i)) << ": ";
            dumpValue(sectionIndex[i]);
        }
        s << "]\n";
    }

    void dumpSectionHeader(const BrigSectionHeader* header) {
        s << "ByteCount: ";
        dumpValue(header->byteCount);
        s << "\n";
    }

    void dumpItemBase(Offset offset, unsigned byteCount) {
        s << "offset: ";
        dumpValue(offset);
        s << ", byteCount: ";
        dumpValue(byteCount);
    }

    void dumpRef(BrigSectionIndex section, Offset offset) {
        s << SectionName(static_cast<BrigSectionIndex>(section)) << "@" << offset;
    }

    void dumpDataItem(Offset offset, const SRef& sref) {
        s << "BrigData: {";
        dumpItemBase(offset, static_cast<unsigned>(sref.length()));
        s << ", value: ";
        dumpValue(sref);
        s << "}\n";
    }

    template <typename ValueType>
    void dumpValue(ValueType v) {
        s << v;
    }

    void dumpValue(bool b) { s << (b ? "true" : "false"); }
    void dumpValue(f16_t arg) { printFloatValue(s, FloatDisassemblyModeDecimal, arg); }
    void dumpValue(f32_t arg) { printFloatValue(s, FloatDisassemblyModeDecimal, arg); }
    void dumpValue(f64_t arg) { printFloatValue(s, FloatDisassemblyModeDecimal, arg); }
    void dumpValue(char arg) { s << static_cast<int>(arg); }
    void dumpValue(signed char arg) { s << static_cast<int>(arg); }
    void dumpValue(unsigned char arg) { s << static_cast<int>(arg); }

    template <size_t BFSize>
    void dumpValue(std::bitset<BFSize> bset) { s << "0b" << bset; }

    void dumpValue(const StrRef& strRef) {
        dumpRef(BRIG_SECTION_INDEX_DATA, strRef.deref());
    }

    template <typename Item>
    void dumpItem(Item i) {
        if (i) {
            dumpRef(static_cast<BrigSectionIndex>(Item::SECTION), i.brigOffset());
        } else {
            dumpValue(0);
        }
    }

    template <typename Item>
    void dumpValue(const ItemRef<Item>& iref) {
        dumpItem(static_cast<Item>(iref));
    }

    template <typename T>
    void dumpValue(const ValRef<T>& vref) {
        dumpValue(static_cast<T>(vref));
    }

    template <typename EnumT, typename BuiltInT>
    void dumpValue(const EnumValRef<EnumT, BuiltInT>& eref) {
        s << anyEnum2str(eref.enumValue());
    }

    template <typename T, unsigned firstBit, unsigned width>
    void dumpValue(const BFValRef<T, firstBit, width>& bfref) {
        T bf(static_cast<T>(bfref));
        dumpValue(std::bitset<width>(bf));
    }

    template <unsigned bit>
    void dumpValue(const BitValRef<bit>& bref) {
        dumpValue(static_cast<bool>(bref));
    }

    template <typename Item>
    void dumpValue(const ListRef<Item>& lref) {
        s << "[";
        for (int i = 0; i < lref.size(); ++i) {
            if (i > 0) {
                s << ", ";
            }
            dumpItem(lref[i]);
        }
        s << "]";
    }

    void dumpValue(const SRef& sref) {
        s << '\"';
        for(const char *p = sref.begin; p != sref.end; ++p) {
            unsigned char const c = static_cast<unsigned char>(*p);
            switch (c) {
            case '\a': s << "\\a"; break;
            case '\b': s << "\\b"; break;
            case '\f': s << "\\f"; break;
            case '\n': s << "\\n"; break;
            case '\r': s << "\\r"; break;
            case '\t': s << "\\t"; break;
            case '\"': s << "\\\""; break;
            case '\\': s << "\\\\"; break;
            default:
                if (c  >= 32 && c < 127) {
                    s << c;
                } else {
                    s << "\\x" << std::setw(2) << std::setfill('0') << static_cast<unsigned>(c);
                }
            break;
            }
        }
        s << '\"';
    }
};

void dump(BrigContainer &c, std::ostream& out) {
    BrigDumper dumper(out);
    dumper.dump(c);
}

void dumpItem(std::ostream& out, Code item) {
    BrigDumper dumper(out);
    dumper.dump(item);
}

void dumpItem(std::ostream& out, Operand item) {
    BrigDumper dumper(out);
    dumper.dump(item);
}

void dumpItem(std::ostream& out, Offset offset, BrigSectionImpl* section, BrigSectionIndex id) {
    BrigDumper dumper(out);
    // ToDo: add support for dumping separate item from data section
    if (id == BRIG_SECTION_INDEX_CODE) {
        dumper.dump(Code(section, offset));
    } else if (id == BRIG_SECTION_INDEX_OPERAND) {
        dumper.dump(Operand(section, offset));
    } else { // dump whole BrigContainer
        dumper.dump(*section->container());
    }
}

} // end namespace