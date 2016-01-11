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
#ifndef INCLUDED_HSAIL_EXTENSION_H
#define INCLUDED_HSAIL_EXTENSION_H

#include "HSAILItems.h"
#include <cctype>
#include <algorithm>

using std::vector;

namespace HSAIL_ASM
{

class Scanner;
class Brigantine;

//=============================================================================
//=============================================================================
//=============================================================================
// Abstract interface with an extension
//
// An extension may define:
// - non-standard opcodes
// - non-standard values of standard instruction properties (these may also be declared and used in HDL)
// - extension may use existing HDL features to encode rules for validation
// - extension opcode should have the following form:
//            <vendor>_<extension>_<opcode>_<suff1>_<suff2>_...
//     - <vendor> must be a unique vendor name
//     - <extension> must be an extension name (unique for this vendor)
//     - <opcode> must be an opcode name (required to be unique when concatenated with suffices)
//     - <suff1>, <suff2> ... are optional opcode suffices
//     
// limitations
// - extension cannot define custom directives and operands
// - extension cannot define new instruction formats (but may extend existing formats)
//
//
class Extension
{
public:
    virtual ~Extension() {}

public:
    virtual const char* getName() const = 0;                            // Return extension name

                                                                        // Called to check if instruction 'prefix' matches this extension
    virtual bool        isMnemoPrefix(const string& prefix) const = 0;  // ('prefix' usually has the form <vendor>_<extension>)
    
                                                                        // Called after 'prefix' has been parsed and this extension
                                                                        // has been identified as the handler of the instruction being parsed.
                                                                        // This function should parse remaining parts of instruction
                                                                        // (usually in the form <opcode>_<suff>...), emit this instructions
                                                                        // in a valid format and return its proxy. 
    virtual Inst        parseInstMnemo(const string& prefix, Scanner& scanner, Brigantine& bw, int* vx) const = 0;

                                                                        // Convert property value to a string
    virtual const char* propVal2mnemo(unsigned prop, unsigned val) const = 0;

                                                                        // Convert property value to the name of a enum
    virtual const string propVal2enum(unsigned prop, unsigned val) const = 0;

                                                                        // NB: This function may be generated automatically from HDL description.
                                                                        //
                                                                        // This function returns type of the specified operand based on 
                                                                        // values of instruction fields, machine model and profile.
                                                                        // The specified instruction must be properly formed with 
                                                                        // all fields containing valid values.
                                                                        // It is recommended to call 'preValidateInst' before using this function.
                                                                        // The returned value is BRIG_TYPE_NONE in the following cases:
                                                                        // - the specified operand is not supported and must be null;
                                                                        // - the specified operand is optional (e.g. list of call targets);
                                                                        // - the specified operand is supported, but has no type (e.g. list of call arguments);
                                                                        // The returned value is BRIG_TYPE_INVALID in the following cases:
                                                                        // - type cannot be determined because of malformed instruction.
    virtual unsigned    getOperandType(Inst inst, unsigned operandIdx, unsigned machineModel, unsigned profile) const = 0;

                                                                        // NB: This function may be generated automatically from HDL description.
                                                                        //
                                                                        // Get default width value
    virtual unsigned    getDefWidth(Inst inst, unsigned machineModel, unsigned profile) const = 0;

                                                                        // NB: This function may be generated automatically from HDL description.
                                                                        //
                                                                        // Get default rounding value
    virtual unsigned    getDefRounding(Inst inst, unsigned machineModel, unsigned profile) const = 0;

    virtual unsigned    getDstOperandsNum(unsigned opcode) const = 0;   // Return number of destination operands

    virtual int         getVXIndex(unsigned opcode) const = 0;          // Get index of operand which has VX suffix in mnemo, -1 if none

                                                                        // Called to request an extension to disassemble the specified 
                                                                        // instruction. This is required only for highely irregular 
                                                                        // mnemonics. In most cases extensions should simply provide mappings of
                                                                        // non-standard Brig values to strings (propVal2mnemo) and rely on the
                                                                        // default disassembly engine (in this case the function shall return
                                                                        // an empty string).
    virtual string      getMnemo(Inst inst) const = 0;                  

                                                                        // NB: This function may be generated automatically from HDL description.
                                                                        //
                                                                        // This function may be used to validate instruction before requesting 
                                                                        // type of operands. It returns 0 for properly formed instructions and 
                                                                        // a string containing an error message for malformed instructions.
                                                                        // This function should be used to avoid cryptic error messages in case of 
                                                                        // malformed instructions. 
    virtual const char* preValidateInst(Inst inst, unsigned machineModel, unsigned profile) const = 0;

                                                                        // NB: This function may be generated automatically from HDL description.
                                                                        //
                                                                        // Validate the specified instruction.
    virtual bool        validateInst(Inst inst, unsigned model, unsigned profile) const = 0;

                                                                        // If the specified string 's' starts with an opcode mnemonic supported by
                                                                        // this extension, return this mnemonic. Otherwise, return 0.
    virtual const char* matchInstMnemo(const string& s) const = 0;
};

//=============================================================================
//=============================================================================
//=============================================================================

} // end namespace

#endif

