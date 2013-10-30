//===-- HSAILTestGenSample.h - HSAIL Test Generator Backend ---------------===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_BACKEND_H
#define INCLUDED_HSAIL_TESTGEN_BACKEND_H

#include "HSAILTestGenUtilities.h"
#include "HSAILItems.h"
#include "Brig.h"

#include <string>

namespace TESTGEN {

// ============================================================================
// TestGen Backend

// TestGen Backend is a component which extends TestGen functionality.
//
// The primary purpose of TestGen is to generate valid (or invalid) HSAIL
// instructions  with all possible combinations of modifiers and argument types.
// Each generated instruction may be regarded as a "template" for
// further customization.
//
// TestGen Backend may generate any number of tests for each instruction
// "template" provided by TestGen, for example:
//   - Disable tests generation for some opcodes or for instructions with
//     specific operands;
//   - generate several tests for each template replacing template arguments
//     with specific operands.
//
class TestGenBackend
{
private:
    static TestGenBackend *backend;

protected:
    unsigned testIdx;

    TestGenBackend() {}
    virtual ~TestGenBackend() {}

public:
    // Called to check if tests shall be generated for the specified instruction.
    // If returned value is true, there is at least one test in this group.
    //
    // inst: the instruction which will be generated for this test.
    //       Backend may inspect it but MUST NOT modify it.
    virtual bool startTestGroup(Inst inst) { testIdx = 0; return true; }

    // Called to generate data for the next test.
    // Return true if data for next test were generated; false if there are no more test data
    virtual bool genNextTestData() { return ++testIdx == 0; }

    // Called after the context is created but before generation of test kernel.
    // This is a convenient place for backend to prepare everything for test generation.
    // If something went wrong, backend may skip generation of the current test by returning false.
    // Note that such a failure does not cancel further test generation for the current test group.
    //
    // context:  BRIG context used for test generation.
    //           backend may save this context internally, however, it cannot be used after
    //           endKernelBody is called.
    // path:     path to the folder where tests will be saved, e.g. "d:\TEST\"
    //           It is guaranteed that the path ends with a separator "/" or "\"
    // testName: file name (without extension) which will be used for this test, e.g. "abs_000"
    // ext:      file extension, e.g. ".brig"
    // 
    // Return true on success and false if this test shall be skipped.
    //
    virtual bool startTest(BrigContext* context, string path, string fileName, string extension) { return true; }

    // Called to allow backend define test kernel arguments.
    // By default, no arguments are generated
    virtual void defKernelArgs() {}

    // Called after test kernel is defined but before generation of first kernel instruction.
    // This is a convenient place for backend to generate prologue code.
    virtual void startKernelBody() {}

    // Called just before generation of "ret" instruction for test kernel
    virtual void endKernelBody() {}

    // Called after generation of test instruction.
    // This is the place for backend to create a new test based on the specified instruction.
    //
    // inst: instruction being tested.
    //       Backend is allowed to modify this instruction, but some modifications may be unsafe.
    //       Safe modifications include:
    //       - replace register with another register of the same type
    //       - replace immediate constant with another constant of the same type
    virtual void makeTest(Inst inst) { }

    // Called just before context destruction
    // This is a good place for backend cleanup
    virtual void endTest() {}

    // Called when all test for the current instruction (i.e. test group) have been generated.
    // This is a good place for backend cleanup
    virtual void endTestGroup() {}

    static TestGenBackend* get(string name);
    static void dispose();
};

// ============================================================================

} // namespace TESTGEN

#endif // INCLUDED_HSAIL_TESTGEN_BACKEND_H
