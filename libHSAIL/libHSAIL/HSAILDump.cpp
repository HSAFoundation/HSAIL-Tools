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
#include "HSAILDump.h"
#include "HSAILBrigContainer.h"
#include "HSAILDisassembler.h"
#include "HSAILItems.h"
#include "HSAILSRef.h"

#include <iosfwd>
#include <iomanip>

namespace HSAIL_ASM
{

static void dumpStr(std::ostream& s, SRef str) {
    for(const char *p = str.begin; p != str.end; ++p) {
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
                s << "\\x" << std::setw(2) << std::setfill('0') << c;
            }
        break;
        }
    }
}

class BrigDumper {
    std::ostream& s;
public:
    BrigDumper(std::ostream& _s) : s(_s) { }

    // item printer
    template <typename Item>
    void operator()(Item item) {

        s << "\n"
            << KindTag<typename Item::Kind>::tag << "@" << item.brigOffset() << " "
            << Item::kindName() << "(" << item.kind() << ") "
            << "byteCount=" << item.byteCount();

        const SourceInfo *si = item.srcInfo();
        if (si) {
            s << " // " << si->line << ":" << si->column;
        }
        s << "\n\t";

        enumerateFields(item, *this);
        s << "\n";
    }

    // field printer
    template <typename T>
    void operator()(const T& v, const char* name, int index = -1) {
        s << name;
        if (index != -1) { s << "[" << index << "]"; }
        s << "=";
        printValue(v);
        s << "; ";
    }

private:

    template<typename T> struct KindTag { };

    template<typename T>
    void pValue(const T& arg)      { s << arg; }

    void pValue(f16_t arg)         { printFloatValue(s, FloatDisassemblyModeDecimal, arg); }
    void pValue(f32_t arg)         { printFloatValue(s, FloatDisassemblyModeDecimal, arg); }
    void pValue(f64_t arg)         { printFloatValue(s, FloatDisassemblyModeDecimal, arg); }
    void pValue(char arg)          { s << (int)arg; }
    void pValue(signed char arg)   { s << (int)arg; }
    void pValue(unsigned char arg) { s << (int)arg; }

    template <typename T, size_t N>
    void pValue(const MySmallArray<T,N>& arg) {
        s << '_' << typeX2str(CType2Brig<T,N>::value) << '(';
        for(int i=N-1; i>0; --i) {
            pValue(arg[i]);
            s << ",";
        }
        pValue(arg[0]);
        s << ")";
    }

    template<typename T>
    void printItemRef(const ItemRef<T>& v) {
        s << KindTag<typename T::Kind>::tag << "@" << v.brigOffset();
    }

    template <typename ElemT>
    void printValueList(const ElemT* begin, const ElemT* end) {
        const ElemT* const preEnd = std::min(begin+10,end);
        s << "{ ";
        if (begin!=preEnd) {
            const ElemT* p;
            for(p = begin; p != (preEnd-1); ++p) {
                pValue(*p);
                s << ", ";
            }
            pValue(*p);

            if ((p+1) < end) {
               s << ", ..." << (end - p) << " elems";
            }
        }
        s << " }";
    }

/*    template <typename Item, typename T, size_t ValOffset>
    void printTrailingRefs(TrailingRefs<Item,T,ValOffset> values) {
        s << "{ ";
        unsigned const size = values.size();
        if (size>0) {
            unsigned i;
            for(i=0; i<size-1; ++i) {
                printItemRef(values[i]);
                s << ",";
            }
            printItemRef(values[i]);
        }
        s << " }";
    }*/

    void printValue(const StrRef& v) {
        s << "S@" << v.deref();
        if (v) {
          s << "=\""; dumpStr(s,v); s << '"';
        }
    }

    template<typename T>
    void printValue(const ValRef<T>& v) {
        pValue((T)v);
    }

    template<typename EnumT,typename BuiltInT>
    void printValue(const EnumValRef<EnumT,BuiltInT>& v) {
        s << anyEnum2str(v.enumValue()) << "(";
        pValue(v.value());
        s << ")";
    }

    template<typename T,unsigned firstBit,unsigned width>
    void printValue(const BFValRef<T,firstBit,width>& v) {
        pValue((T)v);
    }

    template<unsigned bit>
    void printValue(const BitValRef<bit>& v) {
        pValue((bool)v);
    }

    template <typename Item>
    void printValue(const ItemRef<Item>& iref) {
        printItemRef(iref);
    }
    template <typename Item>
    void printValue(const ListRef<Item>& list) {
        unsigned size = list.size();
        s << KindTag<typename Item::Kind>::tag << "@" << "{";
        for(unsigned i=0; i < size; ++i) {
            if (i) s << ", ";
            Item item = list[i];
            s << item.brigOffset();
        }
        s << "}";
    }

    /*template <typename Item, typename T, size_t ValOffset>
    void printValue(const TrailingValues<Item,T,ValOffset>& values) {
        printValueList(values.begin(),values.end());
    }

    template <typename Item, typename T, size_t ValOffset>
    void printValue(const TrailingRefs<Item,T,ValOffset>& values) {
        printTrailingRefs(values);
    }

    template <typename Item, size_t ValOffset>
    void printValue(const TrailingStrRefs<Item,ValOffset>& values) {
        // TBD095 print str list
    }

    template <typename ElemT>
    void printValue(const DataItemT<ElemT>& data) {
        printValueList(data.begin(),data.end());
    }

    void printValue(const DirectiveSignatureArguments& ) {
        // TODO
    }*/
};

template<> struct BrigDumper::KindTag<Code>    { static const char tag = 'C'; };
template<> struct BrigDumper::KindTag<Operand> { static const char tag =   'O'; };


template <typename Item>
void dumpItem_t(std::ostream& out, Item item) {
    BrigDumper dumper(out);
    dispatchByItemKind(item,dumper);
}

void dumpItem(std::ostream& out, Code item) { dumpItem_t(out,item); }
void dumpItem(std::ostream& out, Operand item) { dumpItem_t(out,item); }

void dump(BrigContainer &c, std::ostream& out) {
    for(Code i = c.code().begin(); i != c.code().end(); i = i.next())
    {
        dumpItem(out, i);
    }
    for(Operand i = c.operands().begin(); i != c.operands().end(); i = i.next())
    {
        dumpItem(out, i);
    }
}

} // end namespace