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

#include "Brig_amd.h"

#include "HSAILScanner.h"
#include "HSAILParser.h"
#include "HSAILItems.h"
#include "HSAILBrigantine.h"
#include "HSAILInstProps.h"
#include "HSAILGenericExtension.h"

#include "HSAILValidatorBase.h"

#include <sstream>

using namespace HSAIL_ASM;
using namespace HSAIL_PROPS;

using std::ostringstream;

namespace amd { namespace hsail { namespace mipmap {

//=============================================================================
//=============================================================================
//=============================================================================

#include "InstValidation_mipmap_gen.hpp"

static const char* query2mnemo(unsigned prop, unsigned val)
{
    return (prop == PROP_IMAGEQUERY && val == BRIG_IMAGE_QUERY_AMD_MIPMAP_NUMMIPLEVELS)? AMD_MIPMAP_QUERY : 0;
}

class MipmapInstValidator : public amd::hsail::mipmap::InstValidator
{
public:
    MipmapInstValidator(unsigned model, unsigned profile) : InstValidator(model, profile) {}

public:
    virtual const char* propValExt2mnemo(unsigned prop, unsigned val) const { return query2mnemo(prop, val); }
};

//=============================================================================
//=============================================================================
//=============================================================================

Inst parseMnemoMipMapQueryImage(unsigned opCode, Scanner& scanner, Brigantine& bw, int*);

const ExtInstDesc mipmapDescTab[] =
{
    {"amd_mipmap_rdimagelod",          BRIG_OPCODE_AMD_MIPMAP_RDIMAGELOD,          parseMnemoImage,            0},
    {"amd_mipmap_rdimagegrad",         BRIG_OPCODE_AMD_MIPMAP_RDIMAGEGRAD,         parseMnemoImage,            0},
    {"amd_mipmap_ldimagemip",          BRIG_OPCODE_AMD_MIPMAP_LDIMAGEMIP,          parseMnemoImage,            0},
    {"amd_mipmap_stimagemip",          BRIG_OPCODE_AMD_MIPMAP_STIMAGEMIP,          parseMnemoImage,            0},
    {"amd_mipmap_queryimage",          BRIG_OPCODE_AMD_MIPMAP_QUERYIMAGE,          parseMnemoMipMapQueryImage,-1},
};

#define MIPMAP_DESC_SIZE (sizeof(mipmapDescTab) / sizeof(ExtInstDesc))

class MipMapExtension : public GenericExtension<MipmapInstValidator>
{
    //=============================================================================
    //=============================================================================
    //=============================================================================
public:

    virtual const char* getName() const 
    {
        return AMD_MIPMAP_EXTENSION_NAME;
    }

    virtual bool isMnemoPrefix(const string& prefix) const
    {
        return (prefix == AMD_MIPMAP_EXTENSION_OPCODE_PREFIX);
    }

    virtual const char* propVal2mnemo(unsigned prop, unsigned val) const
    {
        const char* s = query2mnemo(prop, val);
        return s? s : GenericExtension::propVal2mnemo(prop, val);
    }

    virtual unsigned getDstOperandsNum(unsigned opcode) const { return (opcode == BRIG_OPCODE_AMD_MIPMAP_STIMAGEMIP)? 0 : 1; }

    virtual const string propVal2enum(unsigned prop, unsigned val) const
    {
        if (prop == PROP_IMAGEQUERY && val == BRIG_IMAGE_QUERY_AMD_MIPMAP_NUMMIPLEVELS) return "BRIG_IMAGE_QUERY_AMD_MIPMAP_NUMMIPLEVELS";
        return GenericExtension::propVal2enum(prop, val);
    }

    //=============================================================================
    //=============================================================================
    //=============================================================================
protected:
    virtual const char*         getMnemoSuffix(const char* name) const { return name + strlen(AMD_MIPMAP_EXTENSION_OPCODE_PREFIX); }
    virtual const ExtInstDesc*  getInstDescByIdx(unsigned idx)   const { return mipmapDescTab + idx; }
    virtual       unsigned      getInstNum()                     const { return MIPMAP_DESC_SIZE; }
};

//=============================================================================
//=============================================================================
//=============================================================================

Inst parseMnemoMipMapQueryImage(unsigned opCode, Scanner& scanner, Brigantine& bw, int* vx)
{
    unsigned  const geom    = scanner.eatToken(EMGeom);
    string    const query   = scanner.scan().text();

    if (query != "_" AMD_MIPMAP_QUERY) scanner.syntaxError("invalid image query");

    unsigned  const dstType = scanner.eatToken(EMType);
    unsigned  const imgType = scanner.eatToken(EMType);

    scanner.eatToken(EMNone);
    // parse done

    InstQueryImage inst    = bw.addInst<InstQueryImage>(opCode,dstType);
    inst.geometry()        = geom;
    inst.imageQuery()      = BRIG_IMAGE_QUERY_AMD_MIPMAP_NUMMIPLEVELS;
    inst.imageType()       = imgType;

    return inst;
}

//=============================================================================
//=============================================================================
//=============================================================================

const Extension* getExtension()
{
  static const MipMapExtension mipmap;
  return &mipmap;
}

//=============================================================================
//=============================================================================
//=============================================================================

}}} // end of namespaces


