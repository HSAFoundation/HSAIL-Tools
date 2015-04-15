// University of Illinois/NCSA
// Open Source License
//
// Copyright (c) 2013-2015, Advanced Micro Devices, Inc.
// All rights reserved.
//
// Developed by:
//
//     HSA Team
//
//     Advanced Micro Devices, Inc
//
//     www.amd.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal with
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimers.
//
//     * Redistributions in binary form must reproduce the above copyright notice,
//       this list of conditions and the following disclaimers in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the names of the LLVM Team, University of Illinois at
//       Urbana-Champaign, nor the names of its contributors may be used to
//       endorse or promote products derived from this Software without specific
//       prior written permission.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE
// SOFTWARE.
//===----------------------------------------------------------------------===//
//
// HSAIL Assembler/disassembler
//
//===----------------------------------------------------------------------===//
#define DEBUG_TYPE "hsailasm"
#include "llvm/Support/CommandLine.h"
#ifdef _DEBUG
#ifdef DEBUG
#undef DEBUG
#endif
#include "llvm/Support/Debug.h"
#else
#define DEBUG(x)
#endif
#include "llvm/Support/PrettyStackTrace.h"
#include "llvm/Support/Signals.h"

#include "HSAILItems.h"
#include "HSAILDisassembler.h"
#include "HSAILParser.h"
#include "HSAILBrigObjectFile.h"
#include "HSAILValidator.h"
#include "HSAILUtilities.h"
#include "HSAILDump.h"

#ifdef WITH_LIBBRIGDWARF
#include "BrigDwarfGenerator.h"
#endif

#ifdef _WIN32
extern "C" {
    int __setargv(void);
    int _setargv(void) { return __setargv(); }
}
#include <direct.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <fstream>
#include <sstream>

using namespace HSAIL_ASM;
using namespace llvm;
using std::string;

// ============================================================================

#define BRIG_ASM_VERSION "3.0"

// ============================================================================

enum ActionType {
    AC_Assemble,
    AC_Disassemble,
};

static cl::opt<ActionType>
    Action(cl::desc("Action to perform:"),
           cl::init(AC_Assemble),
           cl::values(clEnumValN(AC_Assemble, "assemble", "Assemble a .hsail file (default)"),
                      clEnumValN(AC_Disassemble, "disassemble", "Disassemble an .brig file"),
                      clEnumValEnd));

static cl::opt<std::string>
    InputFilename(cl::Positional, cl::desc("<input file>"), cl::Required);

static cl::opt<std::string>
    OutputFilename("o", cl::desc("Output filename (if not specified, input file name with appropriate extension is used)"), cl::value_desc("filename"), cl::init(""));

static cl::opt<bool>
    Bif32FileFormat("bif32", cl::init(false), cl::desc("generate assembled output in BIF3.0 format using elf32 container"));

static cl::opt<bool>
    Bif64FileFormat("bif64", cl::init(false), cl::desc("generate assembled output in BIF3.0 format using elf64 container"));

static cl::opt<bool>
    DisableOperandOptimizer("disable-operand-optimizer", cl::Hidden, cl::desc("Disable Operand Optimizer"));

static cl::opt<bool>
    DisableValidator("disable-validator", cl::Hidden, cl::desc("Disable Brig Validator"));

static cl::opt<bool>
    ValidateLinkedCode("validate-linked-code", cl::Hidden, cl::desc("Enable validation rules for linked BRIG"));
    // Allows disassembly of linked BRIG with enabled validation

static cl::opt<bool>
    EnableComments("enable-comments", cl::desc("Enable Comments in Brig"));

static cl::opt<bool>
    EnableDebugInfo("g", cl::init(false), cl::desc("Enable debug info generation (assembler only)"));

static cl::opt<std::string>
    DebugInfoFilename("odebug", cl::desc("Debug Info filename"), cl::value_desc("filename"), cl::init(""));

static cl::opt<bool>
    RepeatForever("repeat-forever", cl::ReallyHidden, cl::desc("Repeat forever (for profiling)"));

static cl::opt<EFloatDisassemblyMode>
    FloatDisassemblyMode(cl::desc("float disassembly mode:"),
           cl::init(FloatDisassemblyModeRawBits),
           cl::values(clEnumValN(FloatDisassemblyModeRawBits,  "floatraw", "print in form 0[DFH]rawbits"),
                      clEnumValN(FloatDisassemblyModeC99,      "floatc99", "print in form +-0xX.XXXp+-DD C99 format"),
                      clEnumValN(FloatDisassemblyModeDecimal,  "floatdec", "print in decimal form"),
                      clEnumValEnd));
static cl::opt<bool>
    DisasmInstOffset("disasm-inst-offset", cl::Hidden, cl::desc("print Brig instruction offset as comment to an instruction on disassembly"));

static cl::opt<bool>
    DumpFormatError("dump-format-error", cl::Hidden, cl::desc("Dump items which do not pass validation (experimental)"));

static cl::opt<bool>
    SaveSourceText("include-source", cl::init(false), cl::desc("Save assembly source text in BRIG"));


// ============================================================================

static string getOutputFileName(const char* ext) {
    if (!OutputFilename.empty())
        return OutputFilename;

    // not defined, generate using InputFileName
    string fileName = InputFilename;
    string::size_type const pos = fileName.find_last_of('.');

    if (pos != string::npos && pos > 0 && 
        fileName.rfind(ext, pos) == string::npos) {
        fileName.replace(pos, string::npos, ext);
    } else
        fileName.append(ext);

    return fileName;
}

static int ValidateContainer(BrigContainer &c, std::istream *is) {
    if (!DisableValidator) {
        Validator vld(c);
        if (!vld.validate(DumpFormatError)) {
            std::cerr << vld.getErrorMsg(is) << '\n';
            return vld.getErrorCode();
        }
    }
    return 0;
}

static std::string GetCurrentWorkingDirectory()
{
    char * pCwd( 0 );

#ifdef _WIN32
    pCwd = _getcwd( 0, 0 );
#else
    pCwd = getcwd( 0, 0 );
#endif

    if ( pCwd == 0 )
        return std::string( "" );

    std::string cwd( pCwd, pCwd + strlen( pCwd ) );
    free( pCwd );
    return cwd;
}

// search for a BlockString with a name of "hsa_dwarf_debug", this marks
// the beginning of a group of BlockNumerics which make up the elf container
//
// Input: any directive inside the debug section
//        the debug section
// Returns: the directive following the matching BlockString (the beginning of
//          the BlockNumerics), or the end directive of the section if no
//          matching BlockString is found
//
static void DumpDebugInfoToFile( BrigContainer & c )
{
    std::ofstream ofs( (const char*)(DebugInfoFilename.c_str()), std::ofstream::binary );
    if ( ! ofs.is_open() || ofs.bad() )
        std::cout << "Could not create output debug info file " << DebugInfoFilename << ", not dumping debug info\n";
    else {
      SRef data = c.debugInfo().payload();
      ofs.write(data.begin, data.length());
    }
}


// ============================================================================

static int AssembleInput() {

    using namespace std;
    using namespace HSAIL_ASM;

    std::ifstream ifs((const char*)(InputFilename.c_str()), ifstream::in | ifstream::binary);
    if ((!ifs.is_open()) || ifs.bad()) {
        std::cout << "Could not open file "<<InputFilename.c_str()<<". Exiting...\n";
        return 1;
    }

    BrigContainer c;

    try {
        Scanner s(ifs,!EnableComments);
        Parser p(s, c);
        p.parseSource(SaveSourceText);
    }
    catch (const SyntaxError& e) {
        e.print(cerr,ifs);
        return 1;
    }

    int res = ValidateContainer(c, &ifs);
    if (res) return res;

    if ( EnableDebugInfo ) {
#ifdef WITH_LIBBRIGDWARF
        std::stringstream ssVersion;
        ssVersion << "HSAIL Assembler (C) AMD 2015, all rights reserved, ";
        ssVersion << "Version " << BRIG_ASM_VERSION;
        ssVersion << ", HSAIL version ";
        ssVersion << BRIG_VERSION_HSAIL_MAJOR << ':' << BRIG_VERSION_HSAIL_MINOR;

        std::unique_ptr<BrigDebug::BrigDwarfGenerator> pBdig(
            BrigDebug::BrigDwarfGenerator::Create( ssVersion.str(),
                                                   GetCurrentWorkingDirectory(),
                                                   InputFilename ) );
        pBdig->generate( c );
        pBdig->storeInBrig( c );
#else
        assert(!"libBrigDwarf not enabled");
#endif
    }

    if ( DebugInfoFilename.size() > 0 )
        DumpDebugInfoToFile( c );

    DEBUG(HSAIL_ASM::dump(c, std::cout));

    int const fmt = Bif64FileFormat ? FILE_FORMAT_BIF | FILE_FORMAT_ELF64 :
                    Bif32FileFormat ? FILE_FORMAT_BIF | FILE_FORMAT_ELF32 :
                    FILE_FORMAT_BRIG;
    const std::string& out = getOutputFileName(fmt==FILE_FORMAT_BRIG ? ".brig" : ".bif");
    return BrigIO::save(c, fmt, BrigIO::fileWritingAdapter(out.c_str()));
}

static int DisassembleInput() {
    BrigContainer c;
    if (BrigIO::load(c, FILE_FORMAT_AUTO, 
                     BrigIO::fileReadingAdapter(InputFilename.c_str()))) {
      return 1;
    }

    DEBUG(HSAIL_ASM::dump(c, std::cout));

    int res = ValidateContainer(c, NULL);
    if (res) return res;

    Disassembler disasm(c);
    disasm.setOutputOptions(static_cast<unsigned>(FloatDisassemblyMode)
      | (DisasmInstOffset ? static_cast<unsigned>(Disassembler::PrintInstOffset) : 0u));
    disasm.log(std::cerr);

    if ( DebugInfoFilename.size() > 0 )
        DumpDebugInfoToFile( c );
    std::string ofn = getOutputFileName(".hsail");
    if (ofn == "-") {
        return disasm.run(std::cout);
    } else {
        return disasm.run(ofn.c_str());
    }
}

static int Repeat(int (*func)()) {
    int pass = 0;
    while(1) {
        int rc = func();
        if (!RepeatForever) return rc;
        std::cout << "pass " << ++pass << std::endl;
    }
}

// ============================================================================

static void printVersion() {
    std::cout << "HSAIL Assembler and Disassembler.\n";
    std::cout << "  (C) AMD 2015, all rights reserved.\n";
    std::cout << "  Built " << __DATE__ << " (" << __TIME__ << ").\n";
    std::cout << "  Version " << BRIG_ASM_VERSION << ".\n";

    std::cout << "  HSAIL version " << BRIG_VERSION_HSAIL_MAJOR << ':' << BRIG_VERSION_HSAIL_MINOR << ".\n";
    std::cout << "  BRIG version "  << BRIG_VERSION_BRIG_MAJOR  << ':' << BRIG_VERSION_BRIG_MINOR  << ".\n";
}

int main(int argc, char **argv) {

    // Enable this to enable finegrained heap checks
    // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF );

    sys::PrintStackTraceOnErrorSignal();
    PrettyStackTraceProgram X(argc, argv);

    cl::SetVersionPrinter(printVersion);
    cl::ParseCommandLineOptions(argc, argv, "HSAIL Assembler/Disassembler\n");
    DEBUG(EnableComments=true);

    switch (Action) {
    default:
    case AC_Assemble:
        return Repeat(AssembleInput);
    case AC_Disassemble:
        return Repeat(DisassembleInput);
    }

    return 0;
}

// ============================================================================

