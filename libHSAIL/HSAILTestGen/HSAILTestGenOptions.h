//===-- HSAILTestGenOptions.h - HSAIL Test Generator Options --------------===//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef INCLUDED_HSAIL_TESTGEN_OPTIONS_H
#define INCLUDED_HSAIL_TESTGEN_OPTIONS_H

#include "llvm/Support/CommandLine.h"
#include <string>

using std::string;

namespace TESTGEN {

//==============================================================================
//==============================================================================
//==============================================================================

enum TestType 
{
    TYPE_POSITIVE = 0x1,
    TYPE_NEGATIVE = 0x2,
    TYPE_ALL      = TYPE_POSITIVE | TYPE_NEGATIVE
};

enum PackageType 
{
    PACKAGE_SINGLE   = 0x1,
    PACKAGE_SEPARATE = 0x2,
    PACKAGE_INTERNAL = 0x3
};

enum InstVariantsType
{
    VARIANT_BASIC = 0x1,
    VARIANT_MOD   = 0x2,
    VARIANT_ALL   = VARIANT_BASIC | VARIANT_MOD,
};

enum InstSubsetType 
{
    SUBSET_STD   = 0x0,
    SUBSET_GCN   = 0x1,
    SUBSET_IMAGE = 0x2,
};

enum MachineModelType 
{
    MODEL_SMALL  = 0x1,
    MODEL_LARGE  = 0x2,
};

enum SearchType 
{
    SEARCH_OPTIMAL    = 0x1,
    SEARCH_EXHAUSTIVE = 0x2
};

//==============================================================================
//==============================================================================
//==============================================================================
// Command-line options

extern llvm::cl::opt<TestType>            testType;
extern llvm::cl::opt<PackageType>         testPackage;
extern llvm::cl::opt<SearchType>          searchType;
extern llvm::cl::opt<MachineModelType>    machineModel;
extern llvm::cl::bits<InstSubsetType>     instSubset;
extern llvm::cl::opt<InstVariantsType>    instVariants;
extern llvm::cl::opt<bool>                group;
extern llvm::cl::opt<bool>                expandRegs;
extern llvm::cl::opt<bool>                enableComments;
extern llvm::cl::opt<bool>                dumpTestProps;
extern llvm::cl::opt<string>              extension;
extern llvm::cl::opt<unsigned>            rndTestNum;
extern llvm::cl::opt<string>              outputDirName;
extern llvm::cl::list<string>             testFilter;

//==============================================================================
//==============================================================================
//==============================================================================

}; // namespace TESTGEN

#endif // INCLUDED_HSAIL_TESTGEN_OPTIONS_H