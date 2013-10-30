//===-- HSAILTestGenManager.h - HSAIL Test Generator Manager ------------===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_MANAGER_H
#define INCLUDED_HSAIL_TESTGEN_MANAGER_H

#include "HSAILTestGenOptions.h"
#include "HSAILTestGenContext.h"
#include "HSAILTestGenPropDesc.h"
#include "HSAILTestGenInstDesc.h"
#include "HSAILTestGenProvider.h"
#include "HSAILTestGenBackend.h"
#include "HSAILTestGenNavigator.h"
#include "HSAILTestGenDump.h"

#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>

using std::ostringstream;

namespace TESTGEN {

//==============================================================================
//==============================================================================
//==============================================================================

//F
#define HSAIL_TEST_NAME "hsail_tests"
#define POSITIVE_SUFF   "_p"
#define NEGATIVE_SUFF   "_n"
#define BRIG_EXT        ".brig"

//==============================================================================
//==============================================================================
//==============================================================================
// This class manages test generation, selects a format to save and interacts with backend 

class TestGenManager
{
private:
    const bool isPositive;          // test type: positive or negative
    const string testPath;          // where to save .brig
    std::string opName;             // opcode of instruction being processed
    TestGenBackend *backend;        // backend 

    Context* context;
    unsigned testIdx;               // current test index (used for LUA tests only)
    unsigned testCnt;               // total number of generated tests
    unsigned failedCnt;             // total number of faile dests (used in selftest mode only)

    TestGenNavigator navigator;     // a component used to categorize and filter out tests

    //==========================================================================

public:
    TestGenManager(string path, bool testType) : testIdx(0), testCnt(0), failedCnt(0), isPositive(testType), testPath(path), navigator(path)
    {
        assert(!testPath.empty());

        if (testPackage == PACKAGE_SINGLE)
        {
            context = new Context(getFullTestName());
            context->defineTestKernel();
        }

        backend = TestGenBackend::get(extension);
    }

    ~TestGenManager()
    {
        if (testPackage == PACKAGE_SINGLE) 
        {
            saveContext(context);
            delete context;
        }

        TestGenBackend::dispose();

        if (testCnt == 0 && (instSubset.isSet(SUBSET_STD) || instSubset.isSet(SUBSET_GCN) || instSubset.isSet(SUBSET_IMAGE)))
        {
            std::cerr << "Warning: no tests were generated, check \"filter\" option\n";
        }

        if (testPackage == PACKAGE_INTERNAL) // Report results of self-validation
        {
            const char* testType = (isPositive? "Positive" : "Negative");

            if (failedCnt == 0) 
            {
                std::cerr << testType << " tests passed\n";
            }
            else 
            {
                std::cerr << "*** " << testType << " tests failed! (" << (testCnt - failedCnt) << " passed, " << failedCnt << " failed)\n";
            }
        }
    }

    //==========================================================================

public:
    bool generate()
    {
        unsigned num;
        const unsigned* opcodes = PropDesc::getOpcodes(num);
        for (unsigned i = 0; i < num; ++i)
        {
            unsigned opcode = opcodes[i];

            // filter out opcodes as specified by 'filter' option
            if (!navigator.isOpcodeEnabled(opcode)) continue;

            // skip generation of tests for special opcodes
            if (opcode == Brig::BRIG_OPCODE_CALL) continue;         //F: generalize
            if (opcode == Brig::BRIG_OPCODE_CODEBLOCKEND) continue; //F: generalize
            if (opcode == Brig::BRIG_OPCODE_NOP)  continue;         //F: generalize

            if (InstDesc::isStdOpcode(opcode)   && !instSubset.isSet(SUBSET_STD))   continue;
            if (InstDesc::isGcnOpcode(opcode)   && !instSubset.isSet(SUBSET_GCN))   continue;
            if (InstDesc::isImageOpcode(opcode) && !instSubset.isSet(SUBSET_IMAGE)) continue;

            // Regular tests generation. For instructions which may be encoded 
            // using InstBasic and InstMod formats, only InstMod version is generated.
            if (instVariants & VARIANT_MOD)
            {
                std::auto_ptr<TestGen> desc(TestGen::create(opcode));
                generateTests(*desc);
            }

            // Optional generation of InstBasic version for instructions encoded in InstMod format
            if (InstDesc::getFormat(opcode) == Brig::BRIG_INST_MOD && (instVariants & VARIANT_BASIC))
            {
                std::auto_ptr<TestGen> basicDesc(TestGen::create(opcode, true));
                generateTests(*basicDesc); // for InstBasic format
            }
        }

        return !isFailed();
    }

    //==========================================================================
private:

    void generateTests(TestGen& desc)
    {
        if (isPositive)
        {
            genPositiveTests(desc);
        }
        else
        {
            genNegativeTests(desc);
        }
    }

    void genPositiveTests(TestGen& test)
    {
        for (bool start = true; test.nextPrimarySet(start); start = false)
        {
            finalizePositiveSample(test, true);

            for (; test.nextSecondarySet(); )
            {
                finalizePositiveSample(test, false);
            }
        }
    }

    // NB: 'nextSecondarySet' is not called for negative tests to avoid 
    // generation of large number of identical tests
    void genNegativeTests(TestGen& test)
    {
        for (bool start = true; test.nextPrimarySet(start); start = false)
        {
            // Provide a reference to original valid sample (for inspection purpose)
            if (testPackage == PACKAGE_SINGLE && enableComments) createPositiveTest(test, true);

            unsigned id;
            unsigned val;
            for (test.resetNegativeSet(); test.nextNegativeSet(&id, &val); )
            {
                finalizeNegativeSample(test, id, val);
            }
        }
    }

    //==========================================================================
private:

    void finalizePositiveSample(TestGen& test, bool start)
    {
        const Sample positiveSample = test.getPositiveSample();
        Inst inst = positiveSample.getInst();
        
        assert(PropDesc::isValidInst(inst));

        if (testPackage == PACKAGE_SINGLE)
        {
            if (navigator.isTestEnabled(inst))
            {
                createPositiveTest(test, start);
                ++testCnt;
            }
        }
        else if (testPackage == PACKAGE_INTERNAL)
        {
            if (navigator.isTestEnabled(inst)) 
            {
                Context* ctx = new Context(getFullTestName(), positiveSample);
                ctx->defineTestKernel();
                ctx->cloneSample(positiveSample);
                validateContext(ctx);
                delete ctx;
                ++testCnt;
            }
        }
        else // testPackage == PACKAGE_SEPARATE
        {
            assert(testPackage == PACKAGE_SEPARATE);

            if (!backend->startTestGroup(inst)) return;

            if (!initTestGroup(inst)) return;

            for (;;)
            {
                Context* ctx = new Context(getFullTestName(), positiveSample);
                if (backend->startTest(ctx, getTestPath(), getTestName(), BRIG_EXT))
                {
                    ctx->defineTestKernel();
                    backend->defKernelArgs();

                    ctx->registerTestKernelArgs();
                    backend->startKernelBody();

                    Sample res = ctx->cloneSample(positiveSample);
                    backend->makeTest(res.getInst());
                    backend->endKernelBody();

                    saveContext(ctx);
                    navigator.registerTest(inst.opcode(), testIdx++);
                    ++testCnt;
                }
                
                delete ctx;
                backend->endTest();
                if (!backend->genNextTestData()) break;
            }
            backend->endTestGroup();
        }
    }

    bool initTestGroup(Inst inst)
    {
        assert(testPackage == PACKAGE_SEPARATE);

        if (!navigator.startTest(inst)) return false;

        const char* instName = opcode2str(inst.opcode());
        if (opName != instName)
        {
            testIdx = 0;
            opName = instName;
        }

        return true;
    }

    //==========================================================================
private:

    void finalizeNegativeSample(TestGen& test, unsigned id, unsigned val)
    {
        assert(PropDesc::isValidInst(test.getPositiveSample().getInst()));
        assert(!PropDesc::isValidInst(test.getNegativeSample().getInst()));

        Sample negativeSample = test.getNegativeSample();

        if (navigator.isTestEnabled(negativeSample.getInst()))
        {
            if (testPackage == PACKAGE_SINGLE)
            {
                createNegativeTest(test, id, val);
            }
            else if (testPackage == PACKAGE_INTERNAL)
            {
                Context* ctx = new Context(getFullTestName(), negativeSample);
                ctx->defineTestKernel();
                Sample invalid = ctx->cloneSample(negativeSample, id, val);
                assert(!PropDesc::isValidInst(invalid.getInst()));
                validateContext(ctx);
                delete ctx;
            }
            else // testPackage == PACKAGE_SEPARATE
            {
                // NB: PACKAGE_SEPARATE is not supported for negative tests
                assert(testPackage == PACKAGE_SEPARATE);
                assert(false);
            }

            ++testCnt;
        }
    }

    //==========================================================================

    void createPositiveTest(TestGen& test, bool start)
    {
        assert(testPackage == PACKAGE_SINGLE);

        if (start)
        {
            string note;
            if (instVariants & VARIANT_BASIC) {
                if (test.getFormat() == Brig::BRIG_INST_MOD)
                    note = " (InstMod format)";
                if (test.getFormat() == Brig::BRIG_INST_BASIC && test.isBasicVariant())
                    note = " (InstBasic format)";
            }
        
            context->emitComment("// ");
            context->emitComment((isPositive? "// Next sample" : "// Next valid sample") + note);
            context->emitComment("// ");

            context->cloneSample(test.getPositiveSample());

            context->emitComment("// ");
        }
        else
        {
            context->cloneSample(test.getPositiveSample());
        }
    }

    void createNegativeTest(TestGen& test, unsigned id, unsigned val)
    {
        assert(testPackage == PACKAGE_SINGLE);

        Sample negativeSample = test.getNegativeSample();
        Sample invalid = context->cloneSample(negativeSample, id, val);
        assert(!PropDesc::isValidInst(invalid.getInst()));
    }

    //==========================================================================
private:

    void saveContext(Context* ctx)
    {
        assert(testPackage == PACKAGE_SEPARATE || testPackage == PACKAGE_SINGLE);
        assert(ctx);

        ctx->finalizeTestKernel();
        ctx->save();
    }

    void validateContext(Context* ctx)
    {
        assert(testPackage == PACKAGE_INTERNAL);
        assert(ctx);

        ctx->finalizeTestKernel();

        // validation must pass on positive tests and fail on negative tests
        if (ctx->validate() != isPositive) 
        {
            failedCnt++;
            ctx->save(); // Save failed tests
        }
    }

    bool isFailed() { return failedCnt > 0; }

    //==========================================================================
private:

    string getFullTestName()
    {
        if (testPackage == PACKAGE_SINGLE)
        {
            return testPath + HSAIL_TEST_NAME + ((isPositive)? POSITIVE_SUFF : NEGATIVE_SUFF) + BRIG_EXT;
        }
        else if (testPackage == PACKAGE_INTERNAL)
        {
            ostringstream s;
            s << testPath << HSAIL_TEST_NAME << ((isPositive)? POSITIVE_SUFF : NEGATIVE_SUFF) << "_" << std::setw(6) << std::setfill('0') << testCnt << BRIG_EXT;
            return s.str();
        }
        else // testPackage == PACKAGE_SEPARATE
        {
            assert(testPackage == PACKAGE_SEPARATE);
            return getTestPath() + getTestName() + BRIG_EXT;
        }
    }

    string getTestPath()
    {
        assert(testPackage == PACKAGE_SEPARATE);

        return navigator.getTestPath();
    }

    string getTestName()
    {
        assert(testPackage == PACKAGE_SEPARATE);

        ostringstream s;
        s << opName << "_" << std::setw(5) << std::setfill('0') << testIdx;
        return s.str();
    }
};

//==============================================================================
//==============================================================================
//==============================================================================

}; // namespace TESTGEN 

#endif // INCLUDED_HSAIL_TESTGEN_MANAGER_H