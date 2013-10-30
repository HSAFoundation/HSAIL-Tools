#ifndef INCLUDED_HSAIL_TESTGEN_DATA_PROVIDER_H
#define INCLUDED_HSAIL_TESTGEN_DATA_PROVIDER_H

#include "HSAILTestGenVal.h"
#include "HSAILTestGenUtilities.h"

#include <vector>
using std::vector;

namespace TESTGEN {

class OperandTestData; // Interface with container

//==============================================================================
//==============================================================================
//==============================================================================
// Iterator for accessing test data

class TestDataIterator
{
    //==========================================================================
private:
    OperandTestData* data;              // Class providing interface with test data
    unsigned idx;                       // Current iterator position 

    //==========================================================================
public:
    TestDataIterator();
    void init(OperandTestData* td);

    //==========================================================================
public:
    void reset();                       // Reset iterator position
    bool next();                        // Shift to next data element and report status
    bool empty() const;                 // Check if there are any test data
    Val  get()   const;                 // Get current test data element
};

//==============================================================================
//==============================================================================
//==============================================================================
// Generator which creates all possible combinations of test data for its operands

class TestDataGenerator
{
    //==========================================================================
private:
    vector<TestDataIterator*> iterator; // Providers of test data for each operand
                                        // NB: Indices in this vector have nothing 
                                        //     to do with actual operand indices

    unsigned pos;                       // Current position

    //==========================================================================
public:
    TestDataGenerator() : pos(0) { iterator.reserve(4); }

    void add(TestDataIterator* data)
    {
        assert(data);
        assert(!data->empty());
        iterator.push_back(data);
    }

    //==========================================================================
public:
    unsigned size() const { return static_cast<unsigned>(iterator.size());   }
    bool empty()    const { return size() == 0; }   // Check if there are any test data available

    void reset()                                    // Reset iterator position
    {
        pos = empty()? 0 : size() - 1;
        for (unsigned i = 0; i < size(); ++i) reset(i);
    }

    bool next()                                     // Shift to next set of test data and report status
    {
        if (empty()) return false;

        for(;;) // Find next combination of test values (using exhaustive search)
        {
            assert(0 <= pos && pos < size());
            assert(!empty(pos));

            if (next(pos)) 
            {
                pos = size() - 1;
                return true;
            }

            if (pos == 0) return false; // no more combinations found
            reset(pos);
            --pos;
        }
    }

private:
    //==========================================================================
    bool empty(unsigned idx) const { assert(idx < size()); return iterator[idx]->empty(); }
    bool next (unsigned idx)       { assert(idx < size()); return iterator[idx]->next(); }
    void reset(unsigned idx)       { assert(idx < size()); iterator[idx]->reset(); }
};

//==============================================================================
//==============================================================================
//==============================================================================
// Test data for one operand. 
// Used to represent both scalar and vector operands.
// Scalars have one test value; vectors have up to four test values.

class TestDataWrapper
{
private:
    TestDataIterator data[4];   // Iterators (number of used iterators is specified by 'dim')
    OperandTestData* td;        // Test data (all iterators use the same set of test data)
    unsigned dim;               // Number of values: 1 for scalars; 2-4 for vectors

public:
    TestDataWrapper() : dim(0), td(0) {}
    bool hasData() const { return td != 0; } 
    void setData(OperandTestData* td) { this->td = td; }
    void registerData(TestDataGenerator* gen, unsigned dim)
    {
        assert(1 <= dim && dim <= 4);
        assert(this->dim == 0);
        this->dim = dim;
        for (unsigned i = 0; i < dim; ++i) 
        {
            data[i].init(td);
            gen->add(data + i);
        }
    }

public:
    Val get()
    {
        assert(1 <= dim && dim <= 4);
        if (dim == 1) return data[0].get();
        return Val(dim, get(0), get(1), get(2), get(3));
    }

private:
    Val get(unsigned i) { return (i < dim)? data[i].get() : Val(); }
};

//==============================================================================
//==============================================================================
//==============================================================================
// Provider of test data for all source operands. 
// By default, all operands have the same type, but this may be customized for
// each instruction.
// Instances of this class provide the following service:
// - generation of test values for each operand (including random values)
// - generation of all combinations of values for all operands
// NOTES:
// - type of test values and their standard/custom values are described 
//   in file HSAILTestGenLuaTestData.h

class TestDataProvider
{
    //==========================================================================
private:
    unsigned type;                          // Type of data provided (by default, it is used for all src operands)

    unsigned firstSrcOperand;               // Index of first source operand
    unsigned lastSrcOperand;                // Index of last source operand

    TestDataWrapper testData[5];            // Wrappers that provide access to test data for each operand
                                            // NB: Index in this array corresponds to operand index

    // Generators which create all possible combinations of test data
    // for src operands. Two generators are required to enable grouping.
    // Grouping allow use of one HSAIL test with several groups of test 
    // data defined in LUA script. Note that some HSAIL tests may 
    // include some embedded test data (i.e. imm operands); test
    // values for these operands cannot change and must be locked.

    TestDataGenerator lockedOperands;       // Generator for operands with locked values
    TestDataGenerator groupedOperands;      // Generator for operands whose values may be grouped

    //==========================================================================
    // Public interface 
public:
                                           
    void registerOperand(unsigned i, unsigned dim, bool lock); // Define properties of i-th operand
    bool next();                                // Switch to the next set of test data in the current bundle
    bool nextBundle();                          // Switch to the next bundle of test data
    void reset();                               // Reset 

    Val getSrcValue(unsigned argIdx);           // Return current value for the specified argument

    // Return properties of the current instruction:

    int getFirstSrcOperandIdx();                // Return index of first src operand
    int getDstOperandIdx();                     // Return index of dst operand (-1) if none

    int getFirstOperandIdx();                   // Get index of the first operand (hiden operands are excluded)
    int getLastOperandIdx();                    // Get index of the last operand (hiden operands are excluded)

    //==========================================================================
public:

    static TestDataProvider* getProvider(unsigned opcode, unsigned type, unsigned srcNum = 0);

    static void init();
    static void clean();

    //==========================================================================
private:
    TestDataProvider(unsigned opType);

    // Define standard iterator (each of the same type) for 'n' arguments (first, first+1, ...first+n-1)
    TestDataProvider* defIterators(unsigned n, unsigned first = 1);

    // Define iterators based on specified test data; first source argument must have index 1.
    TestDataProvider* def(OperandTestData &d1);
    TestDataProvider* def(OperandTestData &d1, OperandTestData &d2);
    TestDataProvider* def(OperandTestData &d1, OperandTestData &d2, OperandTestData &d3);
    TestDataProvider* def(OperandTestData &d1, OperandTestData &d2, OperandTestData &d3, OperandTestData &d4);

    // Define iterators based on specified test data; first source argument must have index 'first'.
    TestDataProvider* def(unsigned first, OperandTestData &d1);
    TestDataProvider* def(unsigned first, OperandTestData &d1, OperandTestData &d2);
    TestDataProvider* def(unsigned first, OperandTestData &d1, OperandTestData &d2, OperandTestData &d3);
    TestDataProvider* def(unsigned first, OperandTestData &d1, OperandTestData &d2, OperandTestData &d3, OperandTestData &d4);

    // Define iterators based on specified test data; first source argument must have index 'first'.
    TestDataProvider* def(unsigned first, OperandTestData* d1, OperandTestData* d2 = 0, OperandTestData* d3 = 0, OperandTestData* d4 = 0);

    void initTestData(unsigned idx, OperandTestData* d1);
};

//==============================================================================
//==============================================================================
//==============================================================================

} // namespace TESTGEN

#endif // INCLUDED_HSAIL_TESTGEN_DATA_PROVIDER_H
