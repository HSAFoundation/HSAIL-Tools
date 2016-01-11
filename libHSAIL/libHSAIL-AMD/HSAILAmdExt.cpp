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

#include "HSAILAmdExt.h"
#include "HSAILImageExt.h"

namespace amd { namespace hsail { 

#define AMD_EXTENSIONS_NUM (2)

static const Extension* amdExtensions[AMD_EXTENSIONS_NUM + 1];

const Extension** getExtensions()
{
    const Extension** e = amdExtensions;
    if (!*e)
    {
        *e++ = gcn::getExtension();
        *e++ = mipmap::getExtension();
        *e++ = 0;

        assert(amdExtensions + AMD_EXTENSIONS_NUM + 1 == e);
    }
    return amdExtensions;
}

class AmdExtManager : public ExtManager 
{
public:
    AmdExtManager() 
    {
        registerExtension(gcn::getExtension());
        registerExtension(mipmap::getExtension());
    }
};

const ExtManager& extensions()
{
    static const AmdExtManager amdExtMgr;
    return amdExtMgr;
}

class AmdExtensionsRegistration
{
public:
    AmdExtensionsRegistration() 
    {
        if (!registerExtension(gcn::getExtension())) { assert(false); }
        if (!registerExtension(mipmap::getExtension())) { assert(false); }
    }
};

// Automatic registration of AMD extensions
// NB: does not work on Windows
const AmdExtensionsRegistration amdExtRegistration;

void registerExtensions()
{
    extensions();
}

}} // end of namespaces

