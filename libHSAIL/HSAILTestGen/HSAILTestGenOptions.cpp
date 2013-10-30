
#include "HSAILTestGenOptions.h"

using namespace llvm;

namespace TESTGEN {

//==============================================================================
//==============================================================================
//==============================================================================
// Command-line Options

// NB: LLVM does not handle options properly: "-positive -negative" is considered valid; first option is simply ignored
cl::opt<TestType>
    testType(cl::desc("Tests type"),
            cl::desc("Set type of generated tests"),
            cl::init(TYPE_POSITIVE),
            cl::values(clEnumValN(TYPE_POSITIVE, "positive", "Generate positive tests (default)"),
                       clEnumValN(TYPE_NEGATIVE, "negative", "Generate negative tests"),
                       clEnumValN(TYPE_ALL,      "all",      "Generate both positive and negative tests"),
                       clEnumValEnd));

cl::opt<PackageType>
    testPackage("package",
            cl::desc("Tests packaging"),
            cl::init(PACKAGE_SEPARATE),
            cl::values(clEnumValN(PACKAGE_SEPARATE, "separate", "Each test is saved in a separate file (default)"),
                       clEnumValN(PACKAGE_SINGLE,   "single",   "All tests are saved in one file"),
                       clEnumValN(PACKAGE_INTERNAL, "internal", "Tests are not saved but passed to validator internally"),
                       clEnumValEnd));

cl::opt<SearchType>
    searchType("search",
            cl::desc("Number of generated tests"),
            cl::init(SEARCH_OPTIMAL),
            cl::values(clEnumValN(SEARCH_OPTIMAL,    "optimal",    "Optimal number of tests suitable for most purposes (default)"),
                       clEnumValN(SEARCH_EXHAUSTIVE, "exhaustive", "Maximum number of tests generated using exhaustive search"),
                       clEnumValEnd));

cl::opt<MachineModelType>
    machineModel("model",
            cl::desc("Machine model"),
            cl::init(MODEL_LARGE),
            cl::values(clEnumValN(MODEL_LARGE, "large", "Large model (default)"),
                       clEnumValN(MODEL_SMALL, "small", "Small model"),
                       clEnumValEnd));

cl::bits<InstSubsetType> 
    instSubset(cl::desc("Subset of instructions (standard HSAIL instructions if not specified)"),
            cl::values(clEnumValN(SUBSET_STD,   "std",   "Standard HSAIL instructions"),
                       clEnumValN(SUBSET_GCN,   "gcn",   "GCN extension"),
                       clEnumValN(SUBSET_IMAGE, "image", "IMAGE extension"),
                       clEnumValEnd));

cl::opt<InstVariantsType> 
    instVariants("variants", 
            cl::desc("Instructions formats to use when there is a choice (for instructions encoded in instMod/InstBasic formats)"),
            cl::init(VARIANT_MOD),
            cl::values(clEnumValN(VARIANT_MOD,   "mod",   "InstMod format (default)"),
                       clEnumValN(VARIANT_BASIC, "basic", "InstBasic format. NB: tests for instructions in other formats are NOT generated!"),
                       clEnumValN(VARIANT_ALL,   "all",   "Both InstBasic and InstMod formats"),
                       clEnumValEnd));

cl::list<string>
    testFilter("filter", 
            cl::CommaSeparated, 
            cl::desc("Test filter - a list of comma-separated properties test instruction must match (empty by default)"));

cl::opt<bool>
    enableComments("comments", 
            cl::desc("Enable comments generation (default)"), 
            cl::init(true));

cl::opt<bool>
    group("group", 
            cl::desc("Group as many LUA tests as possible into bundles executed together (default)"), 
            cl::init(true));

cl::opt<bool>
    expandRegs("expandRegs", 
            cl::desc("Enable registers expansion for instructions CVT, LD and ST (default)"), 
            cl::init(true));

cl::opt<bool>
    dumpTestProps("dumpTestProps", 
            cl::desc("Dump test properties into testlist.txt (default); dump list of supported instructions if disabled"), 
            cl::init(true));

cl::opt<std::string>
    extension("extension", 
            cl::desc("TestGen extension. Currently only 'LUA' extension is supported."), 
            cl::value_desc("extension"), 
            cl::init(""));

cl::opt<unsigned>
    rndTestNum("random", 
            cl::desc("Number of additional random values generated for each operand (0 by default)"), 
            cl::value_desc("number of random values"), 
            cl::init(0), 
            cl::Hidden);

cl::opt<string>
    outputDirName(
            cl::Positional, 
            cl::desc("<output directory>"));

//==============================================================================
//==============================================================================
//==============================================================================

}; // namespace TESTGEN

