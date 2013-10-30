#include "HSAILTestGenDataProvider.h"

#include "HSAILTestGenOptions.h"

#include <limits>
#include <iostream>
#include <vector>

using std::vector;
using std::numeric_limits;

namespace TESTGEN {

//==============================================================================
//==============================================================================
//==============================================================================
// Interface with container which holds test data

class OperandTestData 
{
    //==========================================================================
private:
    // Used to keep all instances of test data (except for predefined).
    // All these instances are deleted by 'clean' when test generation finishes.
    //
    // It is important to keep all instances of test data because they may be created 
    // for temporary purposes and are not easy to track automatically.
    // For example:
    //      SRCT(S32.ADD(7).XCL(8))
    // "S32.ADD(7)" creates a temporary object used as a base for ".XCL(8)"
    // 
    static vector<OperandTestData*> tmpData; 

    //==========================================================================
public:
    OperandTestData() {}
    virtual ~OperandTestData() {}

public:
    virtual unsigned getType() = 0;
    virtual unsigned getSize() = 0;
    virtual Val getVal(unsigned idx) = 0;

    virtual void dump() = 0;

    //==========================================================================
protected:
    static void registerData(OperandTestData* td) { tmpData.push_back(td); }

public:
    static void clean() { for (vector<OperandTestData*>::iterator it = tmpData.begin(); it != tmpData.end(); ++it) delete *it; tmpData.clear(); }
};

//==============================================================================
//==============================================================================
//==============================================================================

vector<OperandTestData*> OperandTestData::tmpData;

//==============================================================================
//==============================================================================
//==============================================================================
// Container implementation

template<typename T>
class OperandTestDataImpl : public OperandTestData // Container for test data
{
    //==========================================================================
private:
    unsigned size;      // number of standard test values (NOT including randomly-generated)
    unsigned xsize;     // number of values which must NOT be tested

    // NB: values in both arrays are unique!
    T *values;          // test values [standard,random]
    T *xvalues;         // values which must NOT be tested (e.g. because of unspecified behavior)

    //==========================================================================
public:
    OperandTestDataImpl(unsigned sz, unsigned xsz, const T *vs,  const T *xvs, OperandTestDataImpl<T>* base = 0) : values(0), xvalues(0), size(sz), xsize(xsz)
    {
        assert((sz > 0 && vs) || (xsz > 0 && xvs));

        if (base)
        {
            size += base->size;   // copy base values only
            xsize += base->xsize;
        }
        assert(size > 0); // expected at least one value

        values = new T[size + rndTestNum];
        xvalues = (xsize > 0)? new T[xsize] : 0;

        size = 0;
        xsize = 0;

        // NB: add excluded values first to filter out regular values
        if (base) for (unsigned i = 0; i < base->xsize; ++i) addXclValue(base->xvalues[i]);
        for (unsigned i = 0; i < xsz; ++i) addXclValue(xvs[i]);

        // Add regular values but filter out excluded values which should not be tested
        if (base) for (unsigned i = 0; i < base->size; ++i)  addStdValue(base->values[i]);
        for (unsigned i = 0; i < sz; ++i)  addStdValue(vs[i]);

        assert(size > 0); // expected at least one value
        for (unsigned i = 0; i < rndTestNum; ++i) addRndValue(size + i);
    }

    ~OperandTestDataImpl()
    {
        delete[] values;
        delete[] xvalues;
    }

    //==========================================================================
    // The following interface functions are used for description of test data in 
    // the table labelled with BEGIN_TEST_DATA ... END_TEST_DATA.
    // These functions allow construction of custom sets of test data based on 
    // predefined sets for standard data types.

    // Create a set of values of base type but replace base test values with specified values. Used by 'NEW'.
    OperandTestDataImpl<T>& reset(T x)                          { T values[] = {x};                  return resetValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& reset(T x1, T x2)                   { T values[] = {x1, x2};             return resetValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& reset(T x1, T x2, T x3)             { T values[] = {x1, x2, x3};         return resetValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& reset(T x1, T x2, T x3, T x4)       { T values[] = {x1, x2, x3, x4};     return resetValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& reset(T x1, T x2, T x3, T x4, T x5) { T values[] = {x1, x2, x3, x4, x5}; return resetValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& resetValues(unsigned sz, T* values) { OperandTestDataImpl<T>* res = new OperandTestDataImpl<T>(sz, 0, values, 0, 0); registerData(res); return *res; }
    OperandTestDataImpl<T>& resetList(unsigned sz, T* values)   { OperandTestDataImpl<T>* res = new OperandTestDataImpl<T>(sz / sizeof(T), 0, values, 0, 0); registerData(res); return *res; }

    // Create a set of values of base type; copy base test values and add specified values. Used by 'ADD'.
    OperandTestDataImpl<T>& clone(T x)                          { T values[] = {x};                  return cloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& clone(T x1, T x2)                   { T values[] = {x1, x2};             return cloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& clone(T x1, T x2, T x3)             { T values[] = {x1, x2, x3};         return cloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& clone(T x1, T x2, T x3, T x4)       { T values[] = {x1, x2, x3, x4};     return cloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& clone(T x1, T x2, T x3, T x4, T x5) { T values[] = {x1, x2, x3, x4, x5}; return cloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& cloneValues(unsigned sz, T* values) { OperandTestDataImpl<T>* res = new OperandTestDataImpl<T>(sz, 0, values, 0, this); registerData(res); return *res; }
    OperandTestDataImpl<T>& cloneList(unsigned sz, T* values)   { OperandTestDataImpl<T>* res = new OperandTestDataImpl<T>(sz / sizeof(T), 0, values, 0, this); registerData(res); return *res; }

    // Create a set of values of base type; clone base test values but remove specified values. Used by 'XCL'.
    OperandTestDataImpl<T>& xclone(T x)                          { T values[] = {x};                  return xcloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& xclone(T x1, T x2)                   { T values[] = {x1, x2};             return xcloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& xclone(T x1, T x2, T x3)             { T values[] = {x1, x2, x3};         return xcloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& xclone(T x1, T x2, T x3, T x4)       { T values[] = {x1, x2, x3, x4};     return xcloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& xclone(T x1, T x2, T x3, T x4, T x5) { T values[] = {x1, x2, x3, x4, x5}; return xcloneValues(sizeof(values) / sizeof(T), values); }
    OperandTestDataImpl<T>& xcloneValues(unsigned sz, T* values) { OperandTestDataImpl<T>* res = new OperandTestDataImpl<T>(0, sz, 0, values, this); registerData(res); return *res; }

    //==========================================================================

    unsigned getType()     { assert(size > 0 && values); return Val(*values).getType(); } // Is there another way to do this?
    unsigned getSize()     { return size + rndTestNum; }
    Val getVal(unsigned i) { assert(i < size + rndTestNum); return Val(values[i]); }

    void dump()
    {
        std::cout << "======================================================\n";
        std::cout << "type = " << getType() << "\n";

        std::cout << "standard values = [";
        for (unsigned i = 0; i < size; ++i)
        {
            if (i > 0) std::cout << ", ";
            std::cout << values[i];
        }
        std::cout << "]\n";

        std::cout << "random values = [";
        for (unsigned i = 0; i < rndTestNum; ++i)
        {
            if (i > 0) std::cout << ", ";
            std::cout << values[size + i];
        }
        std::cout << "]\n";

        std::cout << "negative = [";
        for (unsigned i = 0; i < xsize; ++i)
        {
            if (i > 0) std::cout << ", ";
            std::cout << xvalues[i];
        }
        std::cout << "]\n";
    }

    //==========================================================================
private:
    bool isNan(T val) { return Val(val).isNan(); }
    
    bool eq(T val1, T val2) 
    { 
        if (isNan(val1) || isNan(val2))
        {
            return isNan(val1) && isNan(val2); 
        }
        else if (val1 == 0 && val2 == 0)        // -0.0 != +0.0
        {
            return Val(val1).isPositiveZero() == Val(val2).isPositiveZero();
        }
        else
        {
            return val1 == val2; 
        }
    }

    bool isStdValue(T val)
    {
        for (unsigned i = 0; i < size; ++i) if (eq(val, values[i])) return true;
        return false;
    }
    bool isXclValue(T val)
    {
        for (unsigned i = 0; i < xsize; ++i) if (eq(val, xvalues[i])) return true;
        return false;
    }

    // NB: excluded values should be added first, so they MUST NOT intersect with regular values!
    void addXclValue(T val) { assert(!isStdValue(val)); if (!isXclValue(val)) xvalues[xsize++] = Val(val).normalize(); }

    void addStdValue(T val) { if (!isStdValue(val) && !isXclValue(val)) values[size++] = Val(val).normalize(); }

    void addRndValue(unsigned idx)
    {
        Val v(*values); // Create properly typed value
        for (v.randomize(); isStdValue(v) || isXclValue(v); v.randomize()); // filter out duplicated and excluded values
        values[idx] = v.normalize();
    }
};

//==============================================================================
//==============================================================================
//==============================================================================
// Factory for generation of predefined sets of test data (for standard HSAIL types)

class OperandTestDataFactory
{
    //==========================================================================
    // Indices of standard data types
private:
    enum
    {
        IDX_b1_t  = 1,
        IDX_b8_t,
        IDX_b16_t,
        IDX_b32_t,
        IDX_b64_t,

        IDX_u8_t,
        IDX_u16_t,
        IDX_u32_t,
        IDX_u64_t,

        IDX_s8_t,
        IDX_s16_t,
        IDX_s32_t,
        IDX_s64_t,

        IDX_f32_t,
        IDX_f64_t,

        //
        // IDX_f16_t,   // Postponed
        // IDX_s8x4_t,  // Postponed
        // ...

        TSZ // Table size
    };

    static OperandTestData* predefined[TSZ]; // tets data for standard data types

    //==========================================================================
public:
    template<typename T>
    static OperandTestDataImpl<T>* create(unsigned sz, const T *vs)
    {
        return new OperandTestDataImpl<T>(sz, 0, vs, 0, 0);
    }

    static void dump(OperandTestData* data)
    {
        data->dump();
    }

    static void init();
    static void clean();

    static OperandTestData& get(unsigned type)
    {
        using namespace Brig;
        switch(type)
        {
        case BRIG_TYPE_B1:  return *predefined[IDX_b1_t];
        case BRIG_TYPE_B8:  return *predefined[IDX_b8_t];
        case BRIG_TYPE_B16: return *predefined[IDX_b16_t];
        case BRIG_TYPE_B32: return *predefined[IDX_b32_t];
        case BRIG_TYPE_B64: return *predefined[IDX_b64_t];

        case BRIG_TYPE_U8:  return *predefined[IDX_u8_t];
        case BRIG_TYPE_U16: return *predefined[IDX_u16_t];
        case BRIG_TYPE_U32: return *predefined[IDX_u32_t];
        case BRIG_TYPE_U64: return *predefined[IDX_u64_t];

        case BRIG_TYPE_S8:  return *predefined[IDX_s8_t];
        case BRIG_TYPE_S16: return *predefined[IDX_s16_t];
        case BRIG_TYPE_S32: return *predefined[IDX_s32_t];
        case BRIG_TYPE_S64: return *predefined[IDX_s64_t];

        case BRIG_TYPE_F32: return *predefined[IDX_f32_t];
        case BRIG_TYPE_F64: return *predefined[IDX_f64_t];

        // case Brigf16: return *predefined[IDX_f16_t];    // Postponed
        // case Brigs8x4: return *predefined[IDX_s8x4_t];  // Postponed
        // ...

        default:
            throw TestGenError("OperandTestDataFactory: unsupported data type");
        }
    }
};

OperandTestData* OperandTestDataFactory::predefined[TSZ];

void OperandTestDataFactory::clean()
{
    for (int i = 0; i < TSZ; ++i)
    {
        delete predefined[i];
        predefined[i] = 0;
    }
}

//==============================================================================
//==============================================================================
//==============================================================================
// Iterator implementation

TestDataIterator::TestDataIterator() : data(0), idx(0) {}
void TestDataIterator::init(OperandTestData* td) { assert(td); data = td; }

void TestDataIterator::reset()       { idx = 0; }
bool TestDataIterator::next()        { return ++idx < data->getSize(); }
bool TestDataIterator::empty() const { return data == 0; }
Val  TestDataIterator::get()   const { assert(idx < data->getSize()); return data->getVal(idx); }

//==============================================================================
//==============================================================================
//==============================================================================
// TestDataProvider implementation

TestDataProvider::TestDataProvider(unsigned opType) : type(opType), firstSrcOperand(1) {}

TestDataProvider* TestDataProvider::defIterators(unsigned n, unsigned first /*=1*/)
{
    assert(n > 0 && first + n < 5);

    firstSrcOperand = first;

    for (unsigned i = 0; i < n; ++i)
    {
        initTestData(firstSrcOperand + i, &OperandTestDataFactory::get(type));
    }

    return this;
}

TestDataProvider* TestDataProvider::def(OperandTestData &d1) { return def(1, &d1, 0, 0, 0); }
TestDataProvider* TestDataProvider::def(OperandTestData &d1, OperandTestData &d2) { return def(1, &d1, &d2, 0, 0); }
TestDataProvider* TestDataProvider::def(OperandTestData &d1, OperandTestData &d2, OperandTestData &d3) { return def(1, &d1, &d2, &d3, 0); }
TestDataProvider* TestDataProvider::def(OperandTestData &d1, OperandTestData &d2, OperandTestData &d3, OperandTestData &d4) { return def(1, &d1, &d2, &d3, &d4); }

TestDataProvider* TestDataProvider::def(unsigned first, OperandTestData &d1) { return def(first, &d1, 0, 0, 0); }
TestDataProvider* TestDataProvider::def(unsigned first, OperandTestData &d1, OperandTestData &d2) { return def(first, &d1, &d2, 0, 0); }
TestDataProvider* TestDataProvider::def(unsigned first, OperandTestData &d1, OperandTestData &d2, OperandTestData &d3) { return def(first, &d1, &d2, &d3, 0); }
TestDataProvider* TestDataProvider::def(unsigned first, OperandTestData &d1, OperandTestData &d2, OperandTestData &d3, OperandTestData &d4) { return def(first, &d1, &d2, &d3, &d4); }

TestDataProvider* TestDataProvider::def(unsigned first, OperandTestData* d1, OperandTestData* d2, OperandTestData* d3, OperandTestData* d4)
{
    assert(d1);
    assert(first < 5);

    firstSrcOperand = first;

    initTestData(firstSrcOperand + 0, d1);
    initTestData(firstSrcOperand + 1, d2);
    initTestData(firstSrcOperand + 2, d3);
    initTestData(firstSrcOperand + 3, d4);

    return this;
}

void TestDataProvider::initTestData(unsigned idx, OperandTestData* d1)
{
    if (d1)
    {
        assert(idx < 5);
        assert(idx == firstSrcOperand || testData[idx - 1].hasData()); // no gaps

        testData[idx].setData(d1);
        lastSrcOperand = idx;
    }
}

void TestDataProvider::registerOperand(unsigned i, unsigned dim, bool lock)
{
    testData[i].registerData(lock? &lockedOperands : &groupedOperands, dim);
}

bool TestDataProvider::next() 
{ 
    return groupedOperands.next(); 
}

bool TestDataProvider::nextBundle()
{
    if (groupedOperands.next()) {
        return true; 
    } else { 
        groupedOperands.reset();
        return lockedOperands.next();
    }
}

void TestDataProvider::reset()
{
    lockedOperands.reset();
    groupedOperands.reset();
}

Val TestDataProvider::getSrcValue(unsigned argIdx)
{
    assert(0 <= argIdx && argIdx <= 4);

    return testData[argIdx].hasData()? testData[argIdx].get() : Val();
}

// Return properties of the current instruction
int TestDataProvider::getFirstSrcOperandIdx() { return firstSrcOperand; }     // First src operand index (usually 1)
int TestDataProvider::getDstOperandIdx()      { return firstSrcOperand - 1; } // Dst operand index, -1 if none
                                                                              
int TestDataProvider::getFirstOperandIdx()    { return 0; }                   // First operand index (usually this is the index of dst operand = 0)
int TestDataProvider::getLastOperandIdx()     { return lastSrcOperand; }      // Last operand index

void TestDataProvider::init()                 { OperandTestDataFactory::init(); }
void TestDataProvider::clean()                { OperandTestDataFactory::clean(); OperandTestData::clean(); }

//=============================================================================
//=============================================================================
//=============================================================================

#define B1T  (static_cast<OperandTestDataImpl<b1_t>&> (OperandTestDataFactory::get(BRIG_TYPE_B1)))
#define B8T  (static_cast<OperandTestDataImpl<b8_t>&> (OperandTestDataFactory::get(BRIG_TYPE_B8)))
#define B16T (static_cast<OperandTestDataImpl<b16_t>&>(OperandTestDataFactory::get(BRIG_TYPE_B16)))
#define B32T (static_cast<OperandTestDataImpl<b32_t>&>(OperandTestDataFactory::get(BRIG_TYPE_B32)))
#define B64T (static_cast<OperandTestDataImpl<b64_t>&>(OperandTestDataFactory::get(BRIG_TYPE_B64)))

#define U8T  (static_cast<OperandTestDataImpl<u8_t>&> (OperandTestDataFactory::get(BRIG_TYPE_U8)))
#define U16T (static_cast<OperandTestDataImpl<u16_t>&>(OperandTestDataFactory::get(BRIG_TYPE_U16)))
#define U32T (static_cast<OperandTestDataImpl<u32_t>&>(OperandTestDataFactory::get(BRIG_TYPE_U32)))
#define U64T (static_cast<OperandTestDataImpl<u64_t>&>(OperandTestDataFactory::get(BRIG_TYPE_U64)))

#define S8T  (static_cast<OperandTestDataImpl<s8_t>&> (OperandTestDataFactory::get(BRIG_TYPE_S8)))
#define S16T (static_cast<OperandTestDataImpl<s16_t>&>(OperandTestDataFactory::get(BRIG_TYPE_S16)))
#define S32T (static_cast<OperandTestDataImpl<s32_t>&>(OperandTestDataFactory::get(BRIG_TYPE_S32)))
#define S64T (static_cast<OperandTestDataImpl<s64_t>&>(OperandTestDataFactory::get(BRIG_TYPE_S64)))

#define F32T (static_cast<OperandTestDataImpl<f32_t>&>(OperandTestDataFactory::get(BRIG_TYPE_F32)))
#define F64T (static_cast<OperandTestDataImpl<f64_t>&>(OperandTestDataFactory::get(BRIG_TYPE_F64)))

#define BEGIN_TEST_DATA \
    TestDataProvider* TestDataProvider::getProvider(unsigned opcode, unsigned type, unsigned srcNum)\
    {\
        using namespace Brig;\
        switch(opcode)\
        {\
        default: {{

#define END_TEST_DATA \
            } return 0; }\
        }\
        return 0;\
    }

#define INST(inst) } return 0; } case Brig::BRIG_OPCODE_##inst: { switch(type) {
#define TYPE(t) case BRIG_TYPE_##t:
#define SRC_TYPE(t) case BRIG_TYPE_##t:

#define SRCN return (new TestDataProvider(type))->defIterators
#define SRCT return (new TestDataProvider(type))->def
#define ADD clone
#define ADDL(x) cloneList(sizeof(x), x)
#define XCL xclone
#define NEW reset
#define NEWL(x) resetList(sizeof(x), x)

#define REGISTER_TEST_VALUES(type) \
    predefined[IDX_##type] = create<type>(sizeof(vals_##type) / sizeof(type), vals_##type); /*predefined[IDX_##type]->dump();*/

#define DCL_TEST_SET(type) \
    const type vals_##type[]


//=============================================================================
//=============================================================================
//=============================================================================
// Description of test values

#include "HSAILTestGenLuaTestData.h"

//==============================================================================
//==============================================================================
//==============================================================================
// Initialization of test data for standard data types

void OperandTestDataFactory::init()
{
    for (int i = 0; i < TSZ; ++i) predefined[i] = 0;

    DCL_TEST_SET(b1_t)   = TEST_DATA_b1_t;
    DCL_TEST_SET(b8_t)   = TEST_DATA_b8_t;
    DCL_TEST_SET(b16_t)  = TEST_DATA_b16_t;
    DCL_TEST_SET(b32_t)  = TEST_DATA_b32_t;
    DCL_TEST_SET(b64_t)  = TEST_DATA_b64_t;

    DCL_TEST_SET(u8_t)   = TEST_DATA_u8_t;
    DCL_TEST_SET(u16_t)  = TEST_DATA_u16_t;
    DCL_TEST_SET(u32_t)  = TEST_DATA_u32_t;
    DCL_TEST_SET(u64_t)  = TEST_DATA_u64_t;

    DCL_TEST_SET(s8_t)   = TEST_DATA_s8_t;
    DCL_TEST_SET(s16_t)  = TEST_DATA_s16_t;
    DCL_TEST_SET(s32_t)  = TEST_DATA_s32_t;
    DCL_TEST_SET(s64_t)  = TEST_DATA_s64_t;

    DCL_TEST_SET(f32_t)  = TEST_DATA_f32_t;
    DCL_TEST_SET(f64_t)  = TEST_DATA_f64_t;

    REGISTER_TEST_VALUES(b1_t);
    REGISTER_TEST_VALUES(b8_t);
    REGISTER_TEST_VALUES(b16_t);
    REGISTER_TEST_VALUES(b32_t);
    REGISTER_TEST_VALUES(b64_t);

    REGISTER_TEST_VALUES(u8_t);
    REGISTER_TEST_VALUES(u16_t);
    REGISTER_TEST_VALUES(u32_t);
    REGISTER_TEST_VALUES(u64_t);

    REGISTER_TEST_VALUES(s8_t);
    REGISTER_TEST_VALUES(s16_t);
    REGISTER_TEST_VALUES(s32_t);
    REGISTER_TEST_VALUES(s64_t);

    REGISTER_TEST_VALUES(f32_t);
    REGISTER_TEST_VALUES(f64_t);

    // REGISTER_TEST_VALUES(f16_t);   // Postponed
    // REGISTER_TEST_VALUES(s8x4_t);  // Postponed
    // ...
}

//==============================================================================
//==============================================================================
//==============================================================================

} // namespace TESTGEN
