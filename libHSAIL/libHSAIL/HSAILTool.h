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

#ifndef INCLUDED_HSAIL_TOOL_H
#define INCLUDED_HSAIL_TOOL_H

#include <string>
#include <istream>
#include <sstream>
#include <memory>
#include "Brig.h"

struct BrigModuleHeader;
typedef BrigModuleHeader* BrigModule_t;

namespace HSAIL_ASM
{

class BrigContainer;

enum Action {
    NOACTION,
    HELP,
    VERSION,
    ASSEMBLE,
    DISASSEMBLE,
    VALIDATE,
    DECODE,
};

/*
 * Tool is a high-level interface to libHSAIL functionality and works
 * with HSAIL/BRIG modules as a whole without much internal details.
 *
 * Tool has associated BrigContainer normally owned by Tool
 * (although methods to release ownership is provided). Additionally,
 * BrigModule_t (hsa_ext_module_t) can be obtained and has same lifetime.
 * Note that once BrigModule_t is requested, the container becomes read-only.
 *
 * The typical usage of Tool includes
 * 1. Filling BrigContainer with data, either by initializing it in constructor
 *    or by using assemble* or load* methods.
 * 2. Optionally using BrigContainer after obtaining BrigModule_t and passing it
 *    elsewhere (read-only mode) or by modifying it directly through BrigContainer
 *    methods.
 * 3. Optionally validate BrigContainer using validate() method.
 * 4. Optionally, exporting data using disassemble* or save* methods. Alternatively,
 *    move ownership of container using containerRelease().
 * 5. The container is destroyed when Tool object is destroyed unless ownership
 *    has been released.
 */
class Tool
{
public:
    explicit Tool(BrigContainer* c = 0);
    explicit Tool(const void* brig_module, size_t size, bool copy = false);
    ~Tool();

    BrigContainer* container() { return m_container.get(); }
    BrigContainer* containerRelease() { return m_container.release(); }
    BrigModule_t brigModule();

    const std::string& output() const;
    std::string outputString() const;
    void clearOutput();

    bool getModuleInfo(BrigMachineModel8_t* machine_model, BrigProfile8_t* profile, BrigRound8_t* default_round_mode);
    unsigned numSections() const;
    const char *sectionBytesById(int section_id) const;
    size_t sectionSizeById(int section_id) const;
    unsigned findCodeModuleSymbolOffset(const char *symbol_name) const;

    bool assembleFromStream(std::istream& is, const std::string& opts = "", const std::string& sourceDir = "", const std::string& sourceFileName = "");
    bool assembleFromMemory(const char *text, size_t text_length, const std::string& opts = "", const std::string& sourceDir = "", const std::string& sourceFileName = "");
    bool assembleFromString(const std::string& text, const std::string& opts = "", const std::string& sourceDir = "", const std::string& sourceFileName = "");
    bool assembleFromFile(const std::string& filename, const std::string& opts = "");

    bool disassembleToFile(const std::string& filename, const std::string& opts = "");

    bool loadFromMem(const char* buf, size_t size);
    bool loadFromFile(const std::string& filename);

    bool saveToFile(const std::string& filename);

    bool validate();

    bool decodeToFile(const std::string& filename);

    bool printToolVersion();
    bool printToolHelp();

#ifdef WITH_LIBBRIGDWARF
    bool dumpDebugInfoToStream(std::ostream& out);
    bool dumpDebugInfoToFile(const std::string& filename);
#endif // WITH_LIBBRIGDWARF

    bool parseOptions(const std::string& opts, bool execute = false);

    bool execute(const std::string& opts);
    bool execute(int argc, char **argv);

    void SetEnableComments(bool enableComments) { this->EnableComments = enableComments; }
    void SetBif32();
    void SetBrig();
private:
    std::unique_ptr<BrigContainer> m_container;
    bool owned;
    std::ostringstream out;
    mutable std::string sout;

    Action action;
    std::string options;
    std::string InputFilename, OutputFilename;
    int FileFormat, FloatDisassemblyMode;
    bool IncludeSource, DisableValidator, DisableOperandOptimizer,
         EnableComments, DisasmInstOffset, DumpFormatError,
         RepeatForever;
#ifdef WITH_LIBBRIGDWARF
    bool EnableDebugInfo;
    std::string DebugInfoFilename;
#endif

    void initOptions();
    std::string outputFilename(const char *ext = 0) const;
    const char *outputExt() const;
};

}

#endif // INCLUDED_HSAIL_TOOL_H
