//===-- HSAILTestGenSample.h - HSAIL Test Generator Properties ------------===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_PROP_H
#define INCLUDED_HSAIL_TESTGEN_PROP_H

#include "HSAILInstProps.h"
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

namespace TESTGEN {

//=============================================================================
//=============================================================================
//=============================================================================
// Brig operands created for testing

enum BrigOperandId
{
    O_MINID = 0,

    O_CREG,
    O_SREG,
    O_DREG,
    O_QREG,

    O_CREGV2_SRC,
    O_SREGV2_SRC,
    O_DREGV2_SRC,

    O_CREGV3_SRC,
    O_SREGV3_SRC,
    O_DREGV3_SRC,

    O_CREGV4_SRC,
    O_SREGV4_SRC,
    O_DREGV4_SRC,

    O_CREGV2_DST,
    O_SREGV2_DST,
    O_DREGV2_DST,

    O_CREGV3_DST,
    O_SREGV3_DST,
    O_DREGV3_DST,

    O_CREGV4_DST,
    O_SREGV4_DST,
    O_DREGV4_DST,

    O_IMM1_X,
    O_IMM8_X,
    O_IMM16_X,
    O_IMM32_X,
    O_IMM64_X,
    O_IMM128_X,

    O_IMM32_0,
    O_IMM32_1,
    O_IMM32_2,
    O_IMM32_3,
    O_IMM32_4,

    O_WAVESIZE,

    O_LABELREF,
    O_FUNCTIONREF,
    O_FBARRIERREF,

    O_ADDRESS_GLOBAL_VAR,
    O_ADDRESS_READONLY_VAR,

    O_ADDRESS_GROUP_VAR,        // 32-bit segment
    O_ADDRESS_PRIVATE_VAR,      // 32-bit segment

    O_ADDRESS_GLOBAL_ROIMG,
    O_ADDRESS_GLOBAL_RWIMG,

    O_ADDRESS_READONLY_ROIMG,
    O_ADDRESS_READONLY_RWIMG,

    O_ADDRESS_GLOBAL_SAMP,
    O_ADDRESS_READONLY_SAMP,

    O_ADDRESS_FLAT_REG,     
    O_ADDRESS_FLAT_OFF,

    O_JUMPTAB,          // currently not used
    O_CALLTAB,          // currently not used

    O_NULL,

    O_MAXID
};

enum BrigEqClassId
{
    EQCLASS_MINID = 0,

    EQCLASS_0,
    EQCLASS_1,
    EQCLASS_2,
    EQCLASS_255,

    EQCLASS_MAXID
};

//=============================================================================
//=============================================================================
//=============================================================================
// Names of symbols used by operands

extern const char* NAME_FUNC;
extern const char* NAME_GLOBAL_VAR;
extern const char* NAME_GROUP_VAR;
extern const char* NAME_PRIVATE_VAR;
extern const char* NAME_READONLY_VAR;
extern const char* NAME_GLOBAL_ROIMG;
extern const char* NAME_GLOBAL_RWIMG;
extern const char* NAME_READONLY_ROIMG;
extern const char* NAME_READONLY_RWIMG;
extern const char* NAME_GLOBAL_SAMP; 
extern const char* NAME_READONLY_SAMP;
extern const char* NAME_FBARRIER;
extern const char* NAME_LABEL;

//=============================================================================
//=============================================================================
//=============================================================================

string prop2str(unsigned id);
string operand2str(unsigned id);
string val2str(unsigned id, unsigned val);

const unsigned* getValMapDesc(unsigned* size);

//=============================================================================

using namespace HSAIL_PROPS;

struct PropDeleter;

//=============================================================================
//=============================================================================
//=============================================================================
// Description of instruction property

class Prop
{
protected:
    const unsigned propId;

    vector<unsigned> pValues;   // Positive (valid) values this property may take
    vector<unsigned> nValues;   // All possible values for this property (both valid and invalid) 

    unsigned pPos;              // Current position in pValues
    unsigned nPos;              // Current position in nvalues
    
    friend struct PropDeleter;

    //==========================================================================
private:
    Prop(const Prop&); // non-copyable
    const Prop &operator=(const Prop &);  // not assignable

protected:
    Prop(unsigned id) : propId(id)
    {
        using namespace HSAIL_PROPS;
        assert(PROP_MINID <= id && id < PROP_MAXID);
        reset();
    }

public:
    virtual ~Prop() {}

    //==========================================================================
public:
    static Prop* create(unsigned propId, const unsigned* pVals, unsigned pValsNum, const unsigned* nVals, unsigned nValsNum);

    //==========================================================================
public:
    unsigned getPropId() const { return propId; }

    void reset() { resetPositive(); resetNegative(); }
    void resetPositive() { pPos = 0; }
    void resetNegative() { nPos = 0; }

    unsigned getCurrentPositive() const
    {
        assert(0 < pPos && pPos <= pValues.size());
        return pValues[pPos - 1];
    }

    unsigned getCurrentNegative() const
    {
        assert(0 < nPos && nPos <= nValues.size());
        return nValues[nPos - 1];
    }

    bool findNextPositive() { return pPos++ < pValues.size(); }
    bool findNextNegative() { return nPos++ < nValues.size(); }

    //==========================================================================
private:
    void init(const unsigned* pVals, unsigned pValsNum, const unsigned* nVals, unsigned nValsNum)
    {
        for (unsigned i = 0; i < pValsNum; ++i) appendPositive(pVals[i]);
        for (unsigned i = 0; i < nValsNum; ++i) appendNegative(nVals[i]); // NB: positive values may be excluded for neutral props 

        // This is to minimize deps from HDL-generated code
        std::sort(pValues.begin(), pValues.end());
        std::sort(nValues.begin(), nValues.end());
    }

    //==========================================================================
protected:
    bool isPositive(unsigned val) const         { return std::find(pValues.begin(), pValues.end(), val) != pValues.end(); }
    bool isNegative(unsigned val) const         { return std::find(nValues.begin(), nValues.end(), val) != nValues.end(); }
    
    virtual void appendPositive(unsigned val)   { if (!isPositive(val)) pValues.push_back(val); }
    virtual void appendNegative(unsigned val)   { if (!isNegative(val)) nValues.push_back(val); }

};

//=============================================================================
//=============================================================================
//=============================================================================

// Special container for non-brig properties
// Each HDL value is translated to a set of TestGen values (see valMapDesc)
class ExtProp : public Prop
{
private:
    static map<unsigned, const unsigned*> valMap; // HDL to TG translation 

private:
    ExtProp(const ExtProp&); // non-copyable
    const ExtProp &operator=(const ExtProp &);  // not assignable

    //==========================================================================
public:
    ExtProp(unsigned id) : Prop(id) { initValMap(); }
    virtual ~ExtProp() {}

    //==========================================================================
protected:
    virtual void appendPositive(unsigned val)
    {
        assert(VAL_MINID < val && val < VAL_MAXID);
        for (const unsigned* vals = translateVal(val); *vals != 0; ++vals) Prop::appendPositive(*vals);
    }

    virtual void appendNegative(unsigned val)
    {
        assert(VAL_MINID < val && val < VAL_MAXID);
        for (const unsigned* vals = translateVal(val); *vals != 0; ++vals) 
        {
            //F: This is to avoid problems with disassembler (it fails with assert if some operands are 0)
            if (PROP_D0 <= propId && propId <= PROP_S4 && *vals == O_NULL && !isPositive(*vals)) continue; 
            Prop::appendNegative(*vals); // replace "0" with INVALID_VAL_XXX
        }
    }

    //==========================================================================
    // HDL to TG mapping

private:
    static const unsigned* translateVal(unsigned hdlVal) //F need more abstract interface
    {
        assert(hdlVal != 0);
        assert(VAL_MINID < hdlVal && hdlVal < VAL_MAXID);
        assert(valMap.count(hdlVal) != 0);

        for (const unsigned* vals = valMap[hdlVal]; *vals != 0; ++vals) assert(*vals < O_MAXID); // this is for debugging only

        return valMap[hdlVal];
    }

    static void initValMap()
    {
        if (valMap.empty())
        {
            unsigned valMapSize;
            const unsigned* valMapDesc = getValMapDesc(&valMapSize);
            for (unsigned i = 0; i < valMapSize; ++i)
            {
                if (i == 0 || valMapDesc[i - 1] == 0)
                {
                    assert(valMapDesc[i] != 0);
                    assert(VAL_MINID < valMapDesc[i] && valMapDesc[i] < VAL_MAXID);
                    assert(valMap.count(valMapDesc[i]) == 0);

                    valMap[valMapDesc[i]] = valMapDesc + i + 1;
                }
            }
        }
    }
};

//=============================================================================
//=============================================================================
//=============================================================================

}; // namespace TESTGEN

#endif // INCLUDED_HSAIL_TESTGEN_PROP_H