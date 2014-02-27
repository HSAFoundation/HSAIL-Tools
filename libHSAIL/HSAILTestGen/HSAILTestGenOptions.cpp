
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

cl::opt<BrigMachineModel>
    machineModel("model",
            cl::desc("Machine model"),
            cl::init(BRIG_MACHINE_LARGE),
            cl::values(clEnumValN(BRIG_MACHINE_LARGE, "large", "Large model (default)"),
                       clEnumValN(BRIG_MACHINE_SMALL, "small", "Small model"),
                       clEnumValEnd));

cl::bits<InstSubsetType> 
    instSubset(cl::desc("Subset of instructions (standard HSAIL instructions if not specified)"),
            cl::values(clEnumValN(SUBSET_STD,   "std",   "Standard HSAIL instructions"),
                       clEnumValN(SUBSET_GCN,   "gcn",   "GCN extension"),
                       clEnumValN(SUBSET_IMAGE, "image", "IMAGE extension"),
                       clEnumValEnd));

cl::opt<DataType> 
    dataType("dataType", 
             cl::desc("Subset of HSAIL data types (all types by default)"),
             cl::init(DATA_TYPE_ALL),
             cl::values(clEnumValN(DATA_TYPE_REGULAR, "regular", "Regular (non-packed) types"),
                        clEnumValN(DATA_TYPE_PACKED,  "packed",  "Packed types"),
                        clEnumValN(DATA_TYPE_ALL,     "all",     "All types (default)"),
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
    dumpTestProps("dumpTestProps", 
            cl::desc("Dump test properties into testlist.txt (default); dump list of supported instructions if disabled"), 
            cl::init(true));

cl::opt<bool>
    enableImmOperands("enableImmOperands", 
            cl::desc("Enable tests with immediate operands (default); disabling immediate operands may be useful for LUA extension"), 
            cl::init(true),
            cl::Hidden);

cl::opt<std::string>
    extension("extension", 
            cl::desc("TestGen extension. Currently only 'LUA' extension is supported."), 
            cl::value_desc("extension"), 
            cl::init(""));

cl::opt<unsigned>
    wavesize("wavesize", 
            cl::desc("Set wavesize value for LUA tests (64 by default, 0 to disable)"), 
            cl::value_desc("Wavesize value"), 
            cl::init(64));

cl::opt<unsigned>
    rndTestNum("random", 
            cl::desc("Number of additional random values generated for each operand (0 by default)"), 
            cl::value_desc("number of random values"), 
            cl::init(0));

cl::opt<string>
    outputDirName(
            cl::Positional, 
            cl::desc("<output directory>"));

//==============================================================================
//==============================================================================
//==============================================================================

}; // namespace TESTGEN

