//===-- HSAILTestGenSample.h - HSAIL Test Generator - Navigator ------------===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_NAVIGATOR_H
#define INCLUDED_HSAIL_TESTGEN_NAVIGATOR_H

#include "HSAILTestGenUtilities.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace TESTGEN {

class TestGenNavigatorImpl;

//==============================================================================
//==============================================================================
//==============================================================================
// Categorization and filtration of tests

class TestGenNavigator
{
private:
    TestGenNavigatorImpl* impl;

public:
    TestGenNavigator(string path);
    ~TestGenNavigator();

public:
    bool isOpcodeEnabled(unsigned opcode) const;
    bool isTestEnabled(Inst inst);

public:
    bool startTest(Inst inst);
    void registerTest(unsigned opcode, unsigned idx);
    string getTestPath();
};

//==============================================================================
//==============================================================================
//==============================================================================

} // namespace TESTGEN

#endif // INCLUDED_HSAIL_TESTGEN_NAVIGATOR_H
