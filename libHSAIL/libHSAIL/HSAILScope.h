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
#ifndef INCLUDED_HSAIL_SCOPE_H
#define INCLUDED_HSAIL_SCOPE_H

namespace HSAIL_ASM {

class Scope {
    typedef std::map<std::string, Offset> Map;
    Map            d_map;
    BrigContainer* d_container_p;

public:
    // TBD READING FUNCTIONALITY (LOAD KERN/FUNC/GLOBAL INTO THIS)
    Scope(BrigContainer* container)
        : d_container_p(container)
    {
    }

    BrigContainer* container() const { return d_container_p; }

    template<typename Item>
    Item get(const SRef& name);

    template<typename Item>
    bool add(const SRef& name, const Item& item);

    template<typename Item>
    bool replaceOtherwiseAdd(const SRef& name, const Item& item);
};

template<typename Item>
Item Scope::get(const SRef& name) {
    Map::iterator p = d_map.find(std::string(name.begin, name.end));
    if (p != d_map.end()) {
        return typename Item::Kind(d_container_p, p->second);
    }
    else {
        return Item();
    }
}

template<typename Item>
bool Scope::add(const SRef& name, const Item& item) {
    std::pair<Map::iterator, bool> res =
        d_map.insert(std::make_pair(std::string(name.begin,name.end), item.brigOffset()));
    return res.second;
}

template<typename Item>
bool Scope::replaceOtherwiseAdd(const SRef& name, const Item& item) {
    std::pair<Map::iterator, bool> res =
        d_map.insert(std::make_pair(std::string(name.begin,name.end), item.brigOffset()));
    if (res.second==false) {
        (*res.first).second = item.brigOffset();
    }
    return res.second;
}

} // namespace HSAIL_ASM

#endif // INCLUDED_HSAIL_SCOPE_H

