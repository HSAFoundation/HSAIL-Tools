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

#include "Brig.h"

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

namespace hsail { namespace image {

#define IMAGE_EXTENSION_NAME "IMAGE"

//=============================================================================
//=============================================================================
//=============================================================================

#include "HSAILInstValidation_image_gen.hpp"

class ImageInstValidator : public hsail::image::InstValidator
{
public:
    ImageInstValidator(unsigned model, unsigned profile) : InstValidator(model, profile) {}
};

//=============================================================================
//=============================================================================
//=============================================================================

const ExtInstDesc imageDescTab[] =
{
    {"rdimage",          BRIG_OPCODE_RDIMAGE,          parseMnemoImage,            0},
    {"ldimage",          BRIG_OPCODE_LDIMAGE,          parseMnemoImage,            0},
    {"stimage",          BRIG_OPCODE_STIMAGE,          parseMnemoImage,            0},
    {"queryimage",       BRIG_OPCODE_QUERYIMAGE,       parseMnemoQueryImage,      -1},
    {"querysampler",     BRIG_OPCODE_QUERYSAMPLER,     parseMnemoQuerySampler,    -1},
    {"imagefence",       BRIG_OPCODE_IMAGEFENCE,       parseMnemoBasicNoType,     -1},
};

#define IMAGE_DESC_SIZE (sizeof(imageDescTab) / sizeof(ExtInstDesc))

//=============================================================================
//=============================================================================
//=============================================================================

class ImageExtension : public GenericExtension<ImageInstValidator>
{
public:

    virtual const char* getName() const 
    {
        return IMAGE_EXTENSION_NAME;
    }

    virtual bool isMnemoPrefix(const string& prefix) const
    {
        return prefix == "rdimage"      ||
               prefix == "ldimage"      ||
               prefix == "stimage"      ||  
               prefix == "queryimage"   || 
               prefix == "querysampler" ||
               prefix == "imagefence";
    }

    virtual Inst parseInstMnemo(const string& prefix, Scanner& scanner, Brigantine& bw, int* vx) const
    {
        const ExtInstDesc* desc = getInstDesc(prefix);
        assert(desc);

        return (desc->parser)(desc->opcode, scanner, bw, vx);
    }

    //=============================================================================
protected:
    virtual const char*         getMnemoSuffix(const char* name) const { return name; }
    virtual const ExtInstDesc*  getInstDescByIdx(unsigned idx)   const { return imageDescTab + idx; }
    virtual       unsigned      getInstNum()                     const { return IMAGE_DESC_SIZE; }
};

//=============================================================================
//=============================================================================
//=============================================================================

const Extension* getExtension()
{
    static const ImageExtension img;
    return &img;
}

class ImageExtensionRegistration 
{
public:
    ImageExtensionRegistration()
    {
        if (!registerExtension(getExtension())) { assert(false); }
    }
};

// Automatic registration of HSAIL IMAGE extension
// NB: does not work on Windows
const ImageExtensionRegistration imageExtensionRegistration;

//=============================================================================
//=============================================================================
//=============================================================================

}} // end of namespaces


