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
#ifndef INCLUDED_HSAIL_EXT_MANAGER_H
#define INCLUDED_HSAIL_EXT_MANAGER_H

#include "HSAILItems.h"
#include "HSAILExtension.h"
#include "HSAILInstProps.h"

#include <stdexcept>
#include <memory>
#include <vector>

using std::vector;

namespace HSAIL_ASM
{
//============================================================================
// Extension Manager 
//
// This component implements the following functionality:
// - registration of available extensions;
// - enabling and disabling extensions;
// - interface required for integration of extensions with libHSAIL.
//
// Parser, disassembler and validator use this component to control 
// which extensions are enabled and to query enabled extensions 
// about properties of instructions defined in these extensions.
//
// An application which utilize libHSAIL and want to use extensions
// should follow these steps:
//      1. Create an instance of extension manager.
//      2. Register available extensions with this instance of extension manager.
//         Note that registered extensions are enabled by default.
//      3. (Optional) disable unused extensions in this instance of extension manager.
//      4. Pass this instance of extension manager to other components.
//
class ExtManager
{
private:
    vector<const Extension*> extension;                     // registered extensions
    vector<uint8_t>          isEnabled;                     // flag indicating which extensions are enabled
    bool                     registrationComplete;          // flag indicating if this instance can register extensions

public:
    ExtManager();
    ExtManager(const ExtManager& mgr);
    const ExtManager& operator=(const ExtManager& mgr);
    bool registerExtension(const Extension* e);             // register an extension
    bool registerExtensions(const Extension** e);           // register a list of extensions

    //=======================================================================================================================
    //=======================================================================================================================
    // The following functions are intended for operations with extensions
    // The rest of interface functions can handle requests for both extensions and 'CORE' instructions
public:
    bool enable(const char* name,   bool flag = true);      // enable an extension
    bool enable(const string& name, bool flag = true);      // enable an extension
    bool disable(const char* name);                         // disable an extension
    bool disable(const string& name);                       // disable an extension
    void enableAll();                                       // enable all extensions
    void disableAll();                                      // disable all extensions

public:
    bool enabled(const char* name) const;                   // return flag indicating is extension 'name' is enabled
    bool enabled(const string& name) const;                 //
    void getEnabled(vector<string>& name) const;            // return names of enabled extensions in vector 'name'
    bool hasEnabled() const;                                // return a flag indicating if at least one extension has been enabled

public:
    const Extension* get(const char* name) const;           // Get extension by name (may be enabled or disabled)
    const Extension* get(const string& name) const;         // Get extension by name (may be enabled or disabled)

public:
    const Extension* getEnabled(const char* name) const;    // Get enabled extension by name
    const Extension* getEnabled(const string& name) const;  // Get enabled extension by name
    const Extension* getEnabled(unsigned opcode) const;     // Get enabled extension by instruction opcode

public:
                                                            // Called to check if there is an extension which can handle
                                                            // the instruction being parsed. If a suitable extension is found,
                                                            // it is called to parse the instruction, emit this instructions
                                                            // in a valid format and return its proxy. 
    Inst parseExtInstMnemo(Scanner& scanner, Brigantine& bw, int* vx) const;

                                                            // Called to check if there is an extension which want to disassemble 
                                                            // the mnemonic of specified instruction. This is required only for 
                                                            // highely irregular mnemonics. Most extensions provide mappings of
                                                            // non-standard Brig values to strings and rely on the default 
                                                            // disassembly engine (in this case the function returns an empty 
                                                            // string).
    string getExtInstMnemo(Inst inst) const;

    //=======================================================================================================================
    //=======================================================================================================================
    // The following are uniform interface functions (can be used with extensions, 'CORE' instructions and their properties)
public:
                                                            // return name of property value (0 if unknown or not used in HSAIL)
    const char* propVal2mnemo(unsigned prop, unsigned val) const;

                                                            // return name of property value even if it is not used in HSAIL (0 if unknown)
    const char* propVal2str(unsigned prop, unsigned val) const;

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
    unsigned getOperandType(Inst inst, unsigned operandIdx, unsigned machineModel, unsigned profile) const;

                                                            // This function may be used to validate instruction before requesting 
                                                            // type of operands. It returns 0 for properly formed instructions and 
                                                            // a string containing an error message for malformed instructions.
                                                            // This function should be used to avoid cryptic error messages in case of 
                                                            // malformed instructions. 
    const char* preValidateInst(Inst inst, unsigned machineModel, unsigned profile) const;

                                                            // Get default width value
    unsigned getDefWidth(Inst inst, unsigned machineModel, unsigned profile) const;

                                                            // Get default rounding value
    unsigned getDefRounding(Inst inst, unsigned machineModel, unsigned profile) const;
                                                            
    unsigned getDstOperandsNum(unsigned opcode) const;

    int getVXIndex(unsigned opcode) const;                  // Get index of vector operand shown in mnemonic as v2, v3 or v4

                                                            // Return true if 'val' value of property 'prop' is defined 
                                                            // in a disabled extension 'extName' and has value 'valName'
    bool isDisabledProp(unsigned prop, unsigned val, string& valName, string& extName) const;

                                                            // Validate specified instruction.
                                                            // Return false if instruction opcode is unknown or 
                                                            // defined in a disabled extension
    bool validateInst(Inst, unsigned, unsigned) const;

    //=======================================================================================================================
    //=======================================================================================================================
    // Autogenerated enum dumpers
public:

#include "HSAILBrigEnum2str_gen.hpp"

    //=======================================================================================================================
    //=======================================================================================================================
    // Helpers
private:
    bool isMnemoPrefix(const string& prefix) const;
    const string extEnum2str(unsigned prop, unsigned val) const;

private:
    int getIdx(const char* name) const;
    int getIdx(const string& name) const;

private:
    const Extension* getByPrefix(const string& prefix) const;
    const Extension* getByProp(unsigned prop, unsigned val) const;

private:
    unsigned size() const { return (unsigned)extension.size(); }

};

const ExtManager& noExtensions();
const ExtManager& registeredExtensions();
// Register with Extension Manager which is available via a call to registeredExtensions()
bool registerExtension(const Extension* e); 

} // end namespace

#endif

