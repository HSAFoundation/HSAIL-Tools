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
#ifndef INCLUDED_HSAIL_GENERIC_EXTENSION_H
#define INCLUDED_HSAIL_GENERIC_EXTENSION_H

#include "HSAILParser.h"
#include "HSAILExtension.h"
#include "HSAILInstProps.h"
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::ostringstream;

namespace HSAIL_ASM
{

//=============================================================================
//=============================================================================
//=============================================================================
// Generic implementation of an extension

struct ExtInstDesc
{
    const char*   name;       // instruction name
    unsigned      opcode;     // instruction opcode
    OpcodeParser  parser;     // parser for instruction mnemo (i.e. name and suffices)
    int           vxIndex;    // index of operand which has VX suffix in mnemo, -1 if none
};

template<class Validator> class GenericExtension : public Extension
{
public:
    virtual const ExtInstDesc* parseOpcode(Scanner& scanner) const
    {
        string opcode = scanner.scan().text();
        const ExtInstDesc* desc = getInstDesc(opcode);

        while (!desc && scanner.peek().kind() == EExtInstSuff)
        {
            opcode += scanner.scan().text();
            desc = getInstDesc(opcode);
        }

        if (desc)
        {
            for(;;) // search for the longest opcode name
            {
                string suffix = scanner.peek().text();
                const ExtInstDesc* desc_suff = getInstDesc(opcode + suffix);
                if (!desc_suff || suffix.empty()) break;
                scanner.scan();
                desc = desc_suff;
            }
            return desc;
        }
        else
        {
            scanner.syntaxError(string("invalid ") + getName() + " extension opcode");
            return 0;
        }
    }

    virtual Inst parseInstMnemo(const string& prefix, Scanner& scanner, Brigantine& bw, int* vx) const
    {
        const ExtInstDesc* desc = parseOpcode(scanner);
        return (desc->parser)(desc->opcode, scanner, bw, vx);
    }

    virtual string getMnemo(Inst inst) const
    {
        assert(inst);

        return ""; // use default disassembler engine
    }

    virtual bool validateInst(Inst inst, unsigned model, unsigned profile) const
    {
        assert(inst);
        assert(model == BRIG_MACHINE_SMALL || model == BRIG_MACHINE_LARGE);
        assert(profile == BRIG_PROFILE_BASE  || profile == BRIG_PROFILE_FULL);

        if (getInstDesc(inst.opcode()) != 0)
        {
            Validator iv(model, profile);
            iv.validateInst(inst);
            return true;
        }
        return false;
    }

    virtual unsigned getOperandType(Inst inst, unsigned operandIdx, unsigned machineModel, unsigned profile) const
    {
        assert(inst);
        assert(operandIdx < MAX_OPERANDS_NUM);
        assert(machineModel == BRIG_MACHINE_SMALL || machineModel == BRIG_MACHINE_LARGE);
        assert(profile == BRIG_PROFILE_BASE  || profile == BRIG_PROFILE_FULL);

        return Validator(machineModel, profile).getOperandType(inst, operandIdx);
    }

    virtual const char* preValidateInst(Inst inst, unsigned machineModel, unsigned profile) const
    {
        assert(inst);
        assert(machineModel == BRIG_MACHINE_SMALL || machineModel == BRIG_MACHINE_LARGE);
        assert(profile == BRIG_PROFILE_BASE  || profile == BRIG_PROFILE_FULL);

        return Validator(machineModel, profile).preValidateInst(inst);
    }

    virtual unsigned getDefWidth(Inst inst, unsigned machineModel, unsigned profile) const
    {
        assert(inst);
        assert(machineModel == BRIG_MACHINE_SMALL || machineModel == BRIG_MACHINE_LARGE);
        assert(profile == BRIG_PROFILE_BASE  || profile == BRIG_PROFILE_FULL);

        return Validator(machineModel, profile).getDefWidth(inst);
    }

    virtual unsigned getDefRounding(Inst inst, unsigned machineModel, unsigned profile) const
    {
        assert(inst);
        assert(machineModel == BRIG_MACHINE_SMALL || machineModel == BRIG_MACHINE_LARGE);
        assert(profile == BRIG_PROFILE_BASE  || profile == BRIG_PROFILE_FULL);

        return Validator(machineModel, profile).getDefRounding(inst);
    }

    virtual unsigned getDstOperandsNum(unsigned opcode) const { return 1; }

    virtual int getVXIndex(unsigned opcode) const
    {
        const ExtInstDesc* desc = getInstDesc(opcode);
        return desc? desc->vxIndex : -1;
    }

    virtual const char* propVal2mnemo(unsigned prop, unsigned val) const
    {
        using namespace HSAIL_PROPS;

        assert(PROP_MINID < prop && prop < PROP_MAXID);

        if (prop == PROP_OPCODE)
        {
            const ExtInstDesc* desc = getInstDesc(val);
            if (desc) return desc->name;
        }
        return 0;
    }

    struct Normalizer { void operator() (char& elem) const { elem = std::toupper(elem); } };

    virtual const string propVal2enum(unsigned prop, unsigned val) const
    {
        using namespace HSAIL_PROPS;

        assert(PROP_MINID < prop && prop < PROP_MAXID);

        if (prop == PROP_OPCODE)
        {
            const ExtInstDesc* desc = getInstDesc(val);
            if (desc)
            {
                string name = desc->name;
                std::for_each(name.begin(), name.end(), Normalizer());
                return "BRIG_OPCODE_" + name;
            }
        }
        return "";
    }

    //=============================================================================
protected:
    string stdPropVal2mnemo(unsigned prop, unsigned val, unsigned df1 = -1, unsigned df2 = -1) const
    {
        using namespace HSAIL_PROPS;

        assert(PROP_MINID < prop && prop < PROP_MAXID);

        if (val == df1 || val == df2) return "";
        const char* result = HSAIL_ASM::stdPropVal2mnemo(prop, val);
        if (result != NULL) return result;
        else return invalid(prop2str(prop), val);
    }

    string invalid(const char* type, unsigned val) const 
    {
        ostringstream os;
        os << "/*Invalid " << type << " value " << val << "*/";
        return os.str();
    }

    //=============================================================================
public:
    virtual const char* matchInstMnemo(const string& s) const
    {
        unsigned instNum = getInstNum();
        for (unsigned i = 0; i < instNum; ++i)
        {
            const ExtInstDesc* desc = getInstDescByIdx(i);
            if (s.find(desc->name) != string::npos) return desc->name;
        }
        return 0;
    }

    //=============================================================================
protected:
    virtual const ExtInstDesc* getInstDesc(unsigned opcode) const
    {
        unsigned instNum = getInstNum();
        for (unsigned i = 0; i < instNum; ++i)
        {
            const ExtInstDesc* desc = getInstDescByIdx(i);
            if (opcode == desc->opcode) return desc;
        }
        return 0;
    }

    virtual const ExtInstDesc* getInstDesc(const string& mnemo) const
    {
        unsigned instNum = getInstNum();
        for (unsigned i = 0; i < instNum; ++i)
        {
            const ExtInstDesc* desc = getInstDescByIdx(i);
            if (mnemo == getMnemoSuffix(desc->name)) return desc;
        }
        return 0;
    }

    //=============================================================================
protected:
                                                                        // Given a full opcode mnemo in the form
                                                                        //     <vendor>_<extension>_<opcode>_<suff1>_<suff2>_...
                                                                        // skip <vendor> and <extension> prefixes
    virtual const char*         getMnemoSuffix(const char* name) const = 0;

                                                                        // Return instruction description by its index
                                                                        // in the range [0, getInstNum() - 1]
    virtual const ExtInstDesc*  getInstDescByIdx(unsigned idx) const = 0;

                                                                        // Return number of instructions in this extension
    virtual       unsigned      getInstNum() const = 0;
};

//=============================================================================
//=============================================================================
//=============================================================================

} // end namespace

#endif

