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
#pragma once
#ifndef INCLUDED_HSAIL_ITEMS_H
#define INCLUDED_HSAIL_ITEMS_H

#include "HSAILItemBase.h"
#include "HSAILFloats.h"

namespace HSAIL_ASM {

class Code;
class Operand;
typedef ListRef<Code> CodeListRef;
typedef ListRef<Operand> OperandListRef;

#include "HSAILItems_gen.hpp"

#include "HSAILItemImpls_gen.hpp"

#include "HSAILVisitItems_gen.hpp"

// shortcut for "final" classes
template<typename RetType, typename Visitor, typename Item>
inline RetType dispatchByItemKind_gen(Item item, Visitor& vis) {
    return vis(item); // just self visit
}

template <typename RetType, typename Item, typename Visitor>
inline RetType dispatchByItemKind(Item item, Visitor& vis) {
    return dispatchByItemKind_gen<RetType,Visitor>(item,vis);
}

template <typename RetType, typename Item, typename Visitor>
inline RetType dispatchByItemKind(Item item, const Visitor& vis) {
    return dispatchByItemKind_gen<RetType,const Visitor>(item,vis);
}

template <typename Item, typename Visitor>
inline void dispatchByItemKind(Item item, Visitor& vis) {
    dispatchByItemKind_gen<void,Visitor>(item,vis);
}

template <typename Item, typename Visitor>
inline void dispatchByItemKind(Item item, const Visitor& vis) {
    dispatchByItemKind_gen<void,const Visitor>(item,vis);
}


// enumerateFieldsImpl is a level of indirection between
// enumerateFields and enumerateFields_gen to allow
// customized behaviour for specific items

// by default - just call enumerateFields_gen version
template <typename Visitor,typename Item>
inline void enumerateFieldsImpl(Item item, Visitor& vis) {
    enumerateFields_gen(item, vis);
}


template<class Visitor>
class FieldEnumerator {
    Visitor& vis;
public:
    FieldEnumerator(Visitor& vis_) : vis(vis_) { }
    template<typename Item>
    void operator()(Item obj) {
        enumerateFieldsImpl<Visitor>(obj, vis);
    }
};

// enumerateFields dispatches visitor to the actual item kind (like a dynamic_cast)
template <typename Item, typename Visitor>
inline void enumerateFields(Item item, Visitor& vis) {
    FieldEnumerator<Visitor> fieldEnum(vis);
    dispatchByItemKind(item,fieldEnum);
}

// version for const Visitor
template <typename Item, typename Visitor>
inline void enumerateFields(Item item, const Visitor& vis) {
    FieldEnumerator<const Visitor> fieldEnum(vis);
    dispatchByItemKind(item,fieldEnum);
}

} // namespace HSAIL_ASM

#endif // INCLUDED_HSAIL_ITEMS_H

