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
//===-- HSAILValidator.cpp - HSAIL Validator ----------------------===//

#ifndef INCLUDED_HSAIL_VALIDATOR_H
#define INCLUDED_HSAIL_VALIDATOR_H

#include "HSAILBrigContainer.h"
#include "HSAILItemBase.h"
#include "HSAILItems.h"
#include <istream>
#include <string>

#define ENABLE_ADDRESS_SIZE_CHECK (0)

using std::istream;

namespace HSAIL_ASM {

//============================================================================

class ValidatorImpl;

class Validator {
    ValidatorImpl *impl;

    Validator(const Validator&); // non-copyable
    const Validator &operator=(const Validator &); // not assignable

    //==========================================================================
    // Public Validator API
public:
    Validator(BrigContainer &c);
    ~Validator();

    enum ValidationMode { VM_BrigNotLinked, VM_BrigLinked };
    bool validate(ValidationMode mode, bool disasmOnError = false) const;
         
    std::string getErrorMsg(istream *is) const;
    int getErrorCode() const;
};

} // namespace HSAIL_ASM

#endif
