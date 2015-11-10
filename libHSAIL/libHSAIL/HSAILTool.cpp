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

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#else
#include <unistd.h>
#endif
#include <fstream>

#include "HSAILTool.h"
#include "HSAILBrigContainer.h"
#include "HSAILBrigObjectFile.h"
#include "HSAILParser.h"
#include "HSAILDisassembler.h"
#include "HSAILValidator.h"
#include "HSAILDump.h"
#ifdef WITH_LIBBRIGDWARF
#include "BrigDwarfGenerator.h"
#endif
#include <iostream>

#define BRIG_ASM_VERSION "3.0"

namespace HSAIL_ASM
{

Tool::Tool(BrigContainer* c)
  : m_container(c ? c : new BrigContainer()),
    owned(c == 0)
{
    initOptions();
}

Tool::Tool(const void* brig_module, size_t size, bool copy)
  : m_container(copy ? new BrigContainer() : new BrigContainer((BrigModule_t) brig_module)),
    owned(copy)
{
    initOptions();
    if (copy) {
      m_container->setData(brig_module, size);
    }
}

Tool::~Tool()
{
  if (!owned) { m_container.release(); }
}

const std::string& Tool::output() const { sout = out.str(); return sout; }

std::string Tool::outputString() const { sout = out.str(); return sout; }

void Tool::clearOutput() { out.str(""); }

BrigModule_t Tool::brigModule() { return m_container->getBrigModule(); }

bool Tool::getModuleInfo(BrigMachineModel8_t* machine_model, BrigProfile8_t* profile, BrigRound8_t* default_round_mode)
{
  HSAIL_ASM::Code start = m_container->code().begin();
  assert(start.kind() == BRIG_KIND_DIRECTIVE_MODULE);

  HSAIL_ASM::DirectiveModule mod = start;
  *machine_model = mod.machineModel().enumValue();
  *profile = mod.profile().enumValue();
  *default_round_mode = mod.defaultFloatRound().enumValue();
  return true;
}

unsigned Tool::numSections() const { return m_container->getNumSections(); }

const char *Tool::sectionBytesById(int section_id) const { return m_container->sectionById(section_id).data().begin; }

size_t Tool::sectionSizeById(int section_id) const { return m_container->sectionById(section_id).size(); }

unsigned Tool::findCodeModuleSymbolOffset(const char *symbol_name) const
{
    for (Code d = m_container->code().begin(), e = m_container->code().end(); d != e; ) {
        if (DirectiveExecutable e = d) {
            if (e.name().str() == symbol_name) { return e.brigOffset(); }
            d = e.nextModuleEntry(); // Skip to next top level directive.
        } else if (DirectiveVariable v = d) {
            if (v.name().str() == symbol_name) { return v.brigOffset(); }
            d = d.next(); // Skip to next directive.
        } else {
            d = d.next(); // Skip to next directive.
        }
    }
    return 0;
}

bool Tool::assembleFromStream(std::istream& is, const std::string& opts, const std::string& sourceDir, const std::string& sourceFileName)
{
    if (!parseOptions(opts)) { return false; }
    Scanner s(is, true);
    Parser p(s, *m_container);
    try {
        p.parseSource();
    } catch (const SyntaxError& e) {
        e.print(out, is);
        out << std::endl;
        return false;
    }
    if (!DisableValidator) {
        Validator v(*m_container);
        if (!v.validate(DumpFormatError)) {
            out << v.getErrorMsg(&is) << std::endl;
            return false;
        }
    }
#ifdef WITH_LIBBRIGDWARF
    if (EnableDebugInfo) {
        std::stringstream ssVersion;
        ssVersion << "HSAIL Assembler (C) AMD 2015, all rights reserved, ";
        ssVersion << "HSAIL version ";
        ssVersion << BRIG_VERSION_HSAIL_MAJOR << ':' << BRIG_VERSION_HSAIL_MINOR;

        std::string srcDir = sourceDir, srcFileName = sourceFileName;
        if (srcDir.empty()) { srcDir = "<unknown source dir>"; }
        if (srcFileName.empty()) { srcFileName = "<unknown source file>"; }
        std::string source(s.getPlainText());
        std::unique_ptr<BrigDebug::BrigDwarfGenerator> pBdig(
            BrigDebug::BrigDwarfGenerator::Create(ssVersion.str(),
                                                   srcDir,
                                                   srcFileName,
                                                   IncludeSource, source, opts));
        pBdig->log(&out);
        if (!pBdig->generate(*m_container)) { return false; }
        if (!pBdig->storeInBrig(*m_container)) { return false; }
        if (!DebugInfoFilename.empty()) { dumpDebugInfoToFile(DebugInfoFilename); }
    }
#endif
    if (IncludeSource) {
      p.saveSourceToContainer();
    }
    return true;
}

bool Tool::assembleFromMemory(const char *text, size_t text_length, const std::string& opts, const std::string& sourceDir, const std::string& sourceFileName)
{
    std::istringstream is(std::string(text, text_length));
    return assembleFromStream(is, opts, sourceDir, sourceFileName);
}

bool Tool::assembleFromString(const std::string& text, const std::string& opts, const std::string& sourceDir, const std::string& sourceFileName)
{
    std::istringstream is(text);
    return assembleFromStream(is, opts, sourceDir, sourceFileName);
}

bool Tool::assembleFromFile(const std::string& filename, const std::string& opts)
{
    std::ifstream ifs(filename, std::ifstream::in | std::ifstream::binary);
    if ((!ifs.is_open()) || ifs.bad()) {
        out << "Error: Failed to open "<< filename << std::endl;
        return false;
    }
    char *cwd = getcwd(0, 0);
    bool result = assembleFromStream(ifs, opts, cwd, filename);
    free(cwd);
    return result;
}

bool Tool::disassembleToStream(std::ostream& os, const std::string& opts)
{
    if (!parseOptions(opts)) { return false; }
    if (!DisableValidator) {
        Validator v(*m_container);
        if (!v.validate(DumpFormatError)) {
            out << v.getErrorMsg(0) << std::endl;
            return false;
        }
    }
    Disassembler d(*m_container);
    d.setOutputOptions(0);
    std::stringstream ss;
    d.setOutputOptions(static_cast<unsigned>(FloatDisassemblyMode) | (DisasmInstOffset ? static_cast<unsigned>(Disassembler::PrintInstOffset) : 0u));
    d.log(out);
    if (0 != d.run(os)) { // Has error.
        return false;
    }
    return true;
}

bool Tool::disassembleToFile(const std::string& filename, const std::string& opts)
{
    std::ofstream ofs(filename);
    if (!ofs.is_open() || ofs.bad()) {
        out << "Error: Failed to dump BRIG to " << filename << std::endl;
        return false;
    }
    return disassembleToStream(ofs, opts);
}

bool Tool::loadFromMem(const char* buf, size_t size, bool writable)
{
    if (0 != BrigIO::load(*m_container, FileFormat, BrigIO::memoryReadingAdapter(buf, size, out), writable)) {
        return false;
    }
    return true;
}

bool Tool::loadFromFile(const std::string& filename, bool writable)
{
    if (0 != BrigIO::load(*m_container, FileFormat, BrigIO::fileReadingAdapter(filename.c_str(), out), writable)) {
        return false;
    }
    return true;
}

bool Tool::saveToFile(const std::string& filename)
{
    if (FileFormat == FILE_FORMAT_AUTO) { FileFormat = FILE_FORMAT_BRIG; }
    if (0 != BrigIO::save(*m_container, FileFormat, BrigIO::fileWritingAdapter(filename.c_str(), out))) {
        return false;
    }
#ifdef WITH_LIBBRIGDWARF
    if (!DebugInfoFilename.empty()) { dumpDebugInfoToFile(DebugInfoFilename); }
#endif // WITH_LIBBRIGDWARF
    return true;
}

bool Tool::validate()
{
    Validator v(*m_container);
    if (!v.validate(true)) {
        out << v.getErrorMsg(0) << std::endl;
        return false;
    }
    return true;
}

bool Tool::decodeToFile(const std::string& filename)
{
    std::ofstream ofs(filename);
    if (!ofs.is_open() || ofs.bad()) {
        out << "Error: Failed to dump BRIG to " << filename << std::endl;
        return false;
    }
    dump(*m_container, ofs);
    return true;
}

bool Tool::printToolVersion()
{
    out << "HSAIL Assembler and Disassembler." << std::endl;
    out << "  (C) AMD 2015, all rights reserved." << std::endl;
    out << "  Built " << __DATE__ << " (" << __TIME__ << ")." << std::endl;
    out << "  Version " << BRIG_ASM_VERSION << "." << std::endl;
    out << "  HSAIL version " << BRIG_VERSION_HSAIL_MAJOR << ':' << BRIG_VERSION_HSAIL_MINOR << "." << std::endl;
    out << "  BRIG version "  << BRIG_VERSION_BRIG_MAJOR  << ':' << BRIG_VERSION_BRIG_MINOR  << "." << std::endl;
    return true;
}

bool Tool::printToolHelp()
{
  out <<
    "HSAIL Assembler and Disassembler." << std::endl <<
    std::endl <<
    "Usage: HSAILAsm [-assemble|-disassemble|-decode|-version|-help] [options] [input file]" << std::endl <<
    std::endl <<
    "Action to perform:" << std::endl <<
    "  -assemble          - Assemble a .hsail file (default)" << std::endl <<
    "  -disassemble       - Disassemble an .brig file" << std::endl <<
    "  -version           - Display version information" << std::endl <<
    "  -decode            - Decode contents of .brig file in YAML format" << std::endl <<
    "  -help              - Display this help" << std::endl <<
    std::endl <<
    "Options:" << std::endl <<
    "  -bif32             - Use BIF in ELF32 container format" << std::endl <<
    "  -bif64             - Use BIF in ELF64 container format" << std::endl <<
    "  -brig              - Use BRIG format" << std::endl <<
    "  -enable-comments   - Enable Comments in BRIG" << std::endl <<
    "  -g                 - Enable debug info generation for assemble" << std::endl <<
    "  -include-source    - Include HSAIL text in debug information" << std::endl <<
    "  -o <filename>      - Set output filename (if not specified, input file name with appropriate extension is used)" << std::endl <<
    "  -odebug <filename> - Set debug information dump filename and enable dump" << std::endl <<
    "  -floatraw          - Set float disassembly mode to 0[DFH]rawbits" << std::endl <<
    "  -floatc99          - Set float disassembly mode to +-0xX.XXXp+-DD C99 format" << std::endl <<
    "  -floatdec          - Set float disassembly mode to decimal form" << std::endl;
    return true;
}

bool Tool::dumpDebugInfoToStream(std::ostream& out)
{
#ifdef WITH_LIBBRIGDWARF
    int index = m_container->brigSectionIdByName("hsa_debug");
    if (index < 0) {
      out << "Error: Failed to find debug info section to dump." << std::endl;
      return false;
    }
    SRef data = (static_cast<BrigSectionRaw&>(m_container->sectionById(index))).payload();
    out.write(data.begin, data.length());
    return !out.bad();
#else // WITH_LIBBRIGDWARF
    assert(!"Debug info is not enabled in libHSAIL");
    return false;
#endif // WITH_LIBBRIGDWARF
}

bool Tool::dumpDebugInfoToFile(const std::string& filename)
{
#ifdef WITH_LIBBRIGDWARF
    std::ofstream ofs(filename, std::ofstream::binary);
    if (!ofs.is_open() || ofs.bad()) {
        out << "Error: Failed to dump debug info to " << filename << std::endl;
        return false;
    }
    bool result = dumpDebugInfoToStream(ofs);
    ofs.close();
    return result;
#else // WITH_LIBBRIGDWARF
    assert(!"Debug info is not enabled in libHSAIL");
    return false;
#endif // WITH_LIBBRIGDWARF
}

void Tool::initOptions()
{
    action = NOACTION;
    InputFilename.clear();
    OutputFilename.clear();
    FileFormat = FILE_FORMAT_AUTO;
    IncludeSource = false;
    DisableValidator = false;
    DisableOperandOptimizer = false;
    EnableComments = false;
    DisasmInstOffset = false;
    DumpFormatError = false;
    FloatDisassemblyMode = FloatDisassemblyModeRawBits;
    RepeatForever = false;
    EnableDebugInfo = false;
    DebugInfoFilename.clear();
}

static inline std::string getEnv(const char *var)
{
    const char *v = getenv(var);
    return v ? std::string(v) : "";
}

bool Tool::parseOptions(const std::string& opts, bool execute)
{
    std::string xopts(opts);
    std::string aopts = getEnv("LIBHSAIL_OPTIONS_APPEND");
    std::string oopts = getEnv("LIBHSAIL_OPTIONS");
    if (!aopts.empty()) { xopts += " "; xopts += aopts; } // Append to options set by user.
    if (!oopts.empty()) { xopts = oopts; } // Override any options set by user.

    if (this->options == xopts) { return true; }
    this->options = xopts;

    if (!aopts.empty() || !oopts.empty()) {
      out <<
        "Using libHSAIL options (" <<
        (!oopts.empty() ? "override from env variable LIBHSAIL_OPTIONS)" : "append from env variable LIBHSAIL_OPTIONS_APPEND)") <<
        ": '" << xopts << "'" << std::endl;
    }
    if (execute) { initOptions(); }

    std::istringstream iss(xopts);
    std::string opt;
    while (iss >> opt) {
        if (opt == "-disable-validator") { DisableValidator = true; }
#ifdef WITH_LIBBRIGDWARF
        else if (opt == "-g") { EnableDebugInfo = true; }
        else if (opt == "-odebug") { if (!(iss >> DebugInfoFilename)) { out << "Error: Expected debug info file name after -odebug" << std::endl; return false; } }
        else if (opt == "-include-source") { IncludeSource = true; }
#endif // WITH_LIBBRIGDWARF
        else if (execute && opt == "-version") { action = VERSION; }
        else if (execute && opt == "-help") { action = HELP; }
        else if (execute && opt == "-assemble") { action = ASSEMBLE; }
        else if (execute && opt == "-disassemble") { action = DISASSEMBLE; }
        else if (execute && opt == "-validate") { action = VALIDATE; }
        else if (execute && opt == "-decode") { action = DECODE; }
        else if (execute && opt == "-o") { if (!(iss >> OutputFilename)) { out << "Error: Expected output file name after -o" << std::endl; return false; } }
        else if (opt == "-bif32") { FileFormat = FILE_FORMAT_BIF | FILE_FORMAT_ELF32; }
        else if (opt == "-bif64") { FileFormat = FILE_FORMAT_BIF | FILE_FORMAT_ELF64; }
        else if (opt == "-brig") { FileFormat = FILE_FORMAT_BRIG; }
        else if (opt == "-disable-operand-optimizer") { DisableOperandOptimizer = true; }
        else if (opt == "-enable-comments") { EnableComments = true; }
        else if (opt == "-float-disassembly-mode") {
        }
        else if (opt == "-disasm-inst-offset") { DisasmInstOffset = true; }
        else if (opt == "-dump-format-error") { DumpFormatError = true; }
        else if (execute && InputFilename.empty()) { InputFilename = opt; }
        else {
          out << "Error: Invalid libHSAIL option: " + opt << std::endl;
          return false;
        }
    }
    return true;
}

const char *Tool::outputExt() const
{
    switch (action) {
    case ASSEMBLE:
      switch (FileFormat & FILE_FORMAT_MASK) {
      case FILE_FORMAT_BRIG: return ".brig";
      case FILE_FORMAT_BIF: return ".bif";
      default: assert(false); return "<invalidext>";
      }
      return (FileFormat == FILE_FORMAT_BRIG) ? ".brig" : ".bif";
    case DISASSEMBLE:
      return ".hsail";
    case DECODE:
      return ".yaml";
    default:
      assert(false);
      return "<invalidext>";
    }
}

std::string Tool::outputFilename(const char *ext) const
{
    if (!OutputFilename.empty()) { return OutputFilename; }

    // Not defined, generate using InputFilename
    string fileName = InputFilename;
    string::size_type const pos = fileName.find_last_of('.');

    if (!ext) { ext = outputExt(); }
    if (pos != string::npos && pos > 0 &&
        fileName.rfind(ext, pos) == string::npos) {
        fileName.replace(pos, string::npos, ext);
    } else {
        fileName.append(ext);
    }

    return fileName;
}

void Tool::SetBif32()
{
    FileFormat = FILE_FORMAT_BIF | FILE_FORMAT_ELF32;
}

void Tool::SetBrig()
{
    FileFormat = FILE_FORMAT_BRIG;
}

bool Tool::execute(const std::string& opts)
{
    int pass = 0;
    bool result = false;
    do {
        if (parseOptions(opts, true)) {
            if (action == NOACTION && !InputFilename.empty()) { action = ASSEMBLE; }
            switch (action) {
            case VERSION:
              result = printToolVersion();
              break;
            case HELP:
              result = printToolHelp();
              break;
            case ASSEMBLE:
              if (InputFilename.empty()) { out << "Error: No input file specified." << std::endl; result = false; break; }
              if (FileFormat == FILE_FORMAT_AUTO) { FileFormat = FILE_FORMAT_BRIG; }
              result = assembleFromFile(InputFilename, opts) && saveToFile(outputFilename());
              break;
            case DISASSEMBLE:
              if (InputFilename.empty()) { out << "Error: No input file specified." << std::endl; result = false; break; }
              result = loadFromFile(InputFilename) && disassembleToFile(outputFilename(), opts);
              break;
            case VALIDATE:
              result = loadFromFile(InputFilename) && validate();
              break;
            case DECODE:
              if (InputFilename.empty()) { out << "Error: No input file specified." << std::endl; result = false; break; }
              result = loadFromFile(InputFilename) && decodeToFile(outputFilename());
              break;
            case NOACTION:
              out << "Error: No action specified (-help for help)." << std::endl;
              result = false;
              break;
            default:
              out << "Error: Invalid action specified: " << action << std::endl;
              assert(false);
              result = false;
              break;
            }
            if (RepeatForever) {
                out << "Pass " << pass++ << ", result " << result << std::endl;
            }
        }
        std::cout << output();
    } while (RepeatForever);
    return result;
}

bool Tool::execute(int argc, char **argv)
{
  std::ostringstream oss;
  for (int i = 1; i < argc; ++i) {
    oss << argv[i];
    if (i != argc - 1) { oss << " "; }
  }
  return execute(oss.str());
}


}
