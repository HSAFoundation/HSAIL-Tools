//===-- HSAILTestGenInstDesc.h - HSAIL Test Generator - Decsription of Instructions ===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_INST_DESC_H
#define INCLUDED_HSAIL_TESTGEN_INST_DESC_H

#include "HSAILTestGenProp.h"
#include "HSAILTestGenPropDesc.h"
#include "HSAILUtilities.h"
#include "HSAILInstProps.h"

#include <cassert>
#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;

namespace TESTGEN {

using namespace HSAIL_PROPS;

//==============================================================================
//==============================================================================
//==============================================================================

struct PropDeleter { void operator()(Prop* ptr) { delete ptr; } };

//==============================================================================
//==============================================================================
//==============================================================================
// Description of an HSAIL instruction. Consist of a set of properties and
// their values.

class InstDesc
{
private:
    // Mapping of abstract HDL property values (e.g. 'reg') 
    // to actual TestGen values (e.g. '$c0', '$d1' etc).
    // Used for non-brig properties only.
    static map<unsigned, unsigned*> valMap;

    friend class Prop;

private:
    const unsigned opcode;  // Instruction opcode
    const unsigned format;  // Instruction format
    
    // Each instruction is described as a set of abstract properties each
    // of which has a set of valid and invalid values. Note that the set of valid values 
    // may depend on on values of other properties. Consequently, all properties
    // fall into one of two categories: primary and secondary.
    // - set of valid values of a primary property depends only on values of other primary properties.
    // - set of valid values of a secondary property depends only on values of primary properties.
    // Order of primary properties specified by PropDesc must be preserved;
    // this order is essential for proper test generation.

    vector<Prop*> prmProp;  // Primary properties
    vector<Prop*> secProp;  // Secondary propertiess

    //==========================================================================

private:
    InstDesc(const InstDesc&); // non-copyable
    const InstDesc &operator=(const InstDesc &);  // not assignable

    //==========================================================================

protected:
    InstDesc(unsigned fmt, unsigned opc) : opcode(opc), format(fmt) { initProps(); }

public:
    ~InstDesc()
    {
        std::for_each(prmProp.begin(), prmProp.end(), PropDeleter());
        std::for_each(secProp.begin(), secProp.end(), PropDeleter());
    }

    //==========================================================================

public:
    static bool isStdOpcode(unsigned opcode)   { return !isGcnOpcode(opcode) && !isImageOpcode(opcode); }
    static bool isGcnOpcode(unsigned opcode)   { return HSAIL_ASM::isGcnInst(opcode); }
    static bool isImageOpcode(unsigned opcode) { return HSAIL_ASM::isImageInst(opcode); }
    static unsigned getFormat(unsigned opcode) { return PropDesc::getFormat(opcode); }

public:
    unsigned getOpcode() const { return opcode; }
    unsigned getFormat() const { return format; }

    //==========================================================================

protected:
    unsigned getPrmPropNum()        const { return (unsigned)prmProp.size(); } //F: use iterators
    Prop*    getPrmProp(unsigned i) const { assert(i < prmProp.size()); return prmProp[i]; }
    unsigned getSecPropNum()        const { return (unsigned)secProp.size(); }
    Prop*    getSecProp(unsigned i) const { assert(i < secProp.size()); return secProp[i]; }

    bool removeProp(unsigned propId) { return removeProp(propId, prmProp) || removeProp(propId, secProp); }

    //==========================================================================

private:

    void initProps()
    { 
        unsigned prmPropsNum;
        unsigned secPropsNum;
        const unsigned* props = PropDesc::getProps(opcode, prmPropsNum, secPropsNum);

        assert(props && prmPropsNum > 0 && secPropsNum > 0);

        for (unsigned i = 0; i < prmPropsNum + secPropsNum; ++i)
        {
            unsigned propId = props[i];
            assert(PROP_MINID <= propId && propId < PROP_MAXID);

            unsigned pValsNum;
            const unsigned* pVals = PropDesc::getPropVals(opcode, propId, pValsNum);  // values supported by instruction
            assert(pVals && pValsNum > 0);

            unsigned nValsNum;
            const unsigned* nVals = PropDesc::getPropVals(propId, nValsNum);          // all values of this property
            assert(nVals && nValsNum > 0);

            if (pValsNum == 1 && *pVals == OPERAND_VAL_NULL && searchType == SEARCH_OPTIMAL) // minimize tests number
            {
                nValsNum = 1;
                nVals = pVals;
            }

            Prop* p = Prop::create(propId, pVals, pValsNum, nVals, nValsNum);
        
            if (i < prmPropsNum) 
            {
                prmProp.push_back(p); 
            }
            else
            {
                secProp.push_back(p);
            }
        }
    }

    //==========================================================================

private:
    bool removeProp(unsigned propId, vector<Prop*> &prop)
    {
        assert(PROP_MINID <= propId && propId < PROP_MAXID);

        for (vector<Prop*>::iterator it = prop.begin(); it != prop.end(); ++it) //F replace with STL
        {
            if ((*it)->getPropId() == propId) 
            {
                delete (*it);
                prop.erase(it);
                return true;
            }
        }
        return false;
    }

}; // class InstDesc

//==============================================================================
//==============================================================================
//==============================================================================

}; // namespace TESTGEN

#endif // INCLUDED_HSAIL_TESTGEN_INST_DESC_H