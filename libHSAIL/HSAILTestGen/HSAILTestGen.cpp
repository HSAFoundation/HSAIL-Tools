//===-- HSAILTestGen.cpp - HSAIL Test Generator ---------------------------===//
//
//===----------------------------------------------------------------------===//
//
// HSAIL Test Generator. (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#include "HSAILTestGenOptions.h"
#include "HSAILTestGenManager.h"

#include "HSAILValidatorBase.h"

#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Signals.h"
#include "llvm/Support/PrettyStackTrace.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/PathV2.h"

#include <iostream>
#include <string>

using std::string;
using HSAIL_ASM::PropValidator;

//==============================================================================
//==============================================================================
//==============================================================================

#define BRIG_TESTGEN_VERSION "2.1"

//==============================================================================
//==============================================================================
//==============================================================================

int genTests(string path)
{
    using namespace TESTGEN;

    bool existed = false;
    llvm::error_code ec;

    if (instSubset.getBits() == 0) instSubset.addValue(SUBSET_STD); // default value

    if (path.empty())
    {
        std::cerr << "Missing directory name\n";
        return 1;
    }
    else // Validate file name and add folder separator at the end
    {
        if (!llvm::sys::fs::exists(path))
        {
            std::cerr << "Directory " << path << " does not exist\n";
            return 1;
        }

        ec = llvm::sys::fs::is_directory(path, existed);
        if (ec != llvm::errc::success || !existed)
        {
            std::cerr << path << " must be a directory\n";
            return 1;
        }

        string::size_type len = path.length();
        if (len > 0 && !llvm::sys::path::is_separator(path[len - 1])) {
            path += llvm::sys::path::is_separator('\\')? "\\" : "/";
        }
    }

    if (testPackage == PACKAGE_SEPARATE)
    {
        if (testType == TYPE_NEGATIVE || testType == TYPE_ALL) 
        {
            std::cerr << "Warning: incompatible options; negative tests will not be generated\n";
            testType = TYPE_POSITIVE;
        }
    }

    if (extension.size() > 0 && testPackage != PACKAGE_SEPARATE)
    {
        std::cerr << "Warning: incompatible options; \"backend\" option ignored\n";
    }

    if (rndTestNum > 0 && testPackage != PACKAGE_SEPARATE)
    {
        std::cerr << "Warning: incompatible options;  \"random\" option ignored\n";
    }

    PropValidator::setMachineType(machineModel == MODEL_SMALL? Brig::BRIG_TYPE_B32 : Brig::BRIG_TYPE_B64); //F
    PropValidator::enableOperandsExpansion(expandRegs);

    int res;    
    try 
    {
        bool ok = true;

        if (testType == TYPE_POSITIVE || testType == TYPE_ALL)
        {
            ok &= TestGenManager(path, true).generate();
        }
        if (testType == TYPE_NEGATIVE || testType == TYPE_ALL)
        {
            ok &= TestGenManager(path, false).generate();
        }

        res = ok? 0 : 101;
    } 
    catch (const TestGenError& err) 
    {
        std::cerr << err.what() << "\n";
        res = 1;
    }

    return res;
}

//==============================================================================
//==============================================================================
//==============================================================================

static void printVersion() 
{
    std::cout << "HSAIL Test Generator.\n";
    std::cout << "  (C) AMD 2013, all rights reserved.\n";
    std::cout << "  Built " << __DATE__ << " (" << __TIME__ << ").\n";
    std::cout << "  Version " << BRIG_TESTGEN_VERSION << ".\n";

    std::cout << "  HSAIL version " << Brig::BRIG_VERSION_HSAIL_MAJOR << ':' << Brig::BRIG_VERSION_HSAIL_MINOR << ".\n";
    std::cout << "  BRIG version "  << Brig::BRIG_VERSION_BRIG_MAJOR  << ':' << Brig::BRIG_VERSION_BRIG_MINOR  << ".\n";
}

int main(int argc, char **argv) 
{
    llvm::sys::PrintStackTraceOnErrorSignal();
    llvm::PrettyStackTraceProgram X(argc, argv);

    llvm::cl::SetVersionPrinter(printVersion);
    llvm::cl::ParseCommandLineOptions(argc, argv, "HSAIL Test Generator\n");

    return genTests(TESTGEN::outputDirName);
}

//==============================================================================
//==============================================================================
//==============================================================================
// TODO:
//  - HDL should respect order in which prop values are described - this affects testing
//        - prop desc: affects negative testing (not much)
//        - inst desc: affects positive and negative testing (very much)
//  - separate HSAIL-specific code to simplify porting
//  - auto_ptr
//  - Prop::getNextPositive, etc: redesign using iterators
//  - Prop should be used by InstDesc only
//    - change API to make props scanning more transparent:
//      - cannot change prop X without first setting all previous props
//      - API should operate with 'cursor' which could be manipulated with limitations
//        - ++/-- (valid if previous pos was valid)
//        - assign(x) (valid if all props before X were initialized)
//        - X may be start, end, primary.end
//  - rewrite all possible code using STL algs
//  - get rid of Sample::get
//  - performance? use inline?
////////////////////////////////////////////////////////////////////////////////////
