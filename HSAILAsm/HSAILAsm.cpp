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

#include "HSAILTool.h"
#include "HSAILExtManager.h"
#include "HSAILImageExt.h"
#ifdef AMD_EXTENSIONS
#include "HSAILAmdExt.h"
#endif // AMD_EXTENSIONS

#ifdef _MSC_VER
#include <Windows.h>
#endif // _MSC_VER

using namespace HSAIL_ASM;

#ifdef _MSC_VER
/// AvoidMessageBoxHook - Emulates hitting "retry" from an "abort, retry,
/// ignore" CRT debug report dialog.  "retry" raises an exception which
/// ultimately triggers our stack dumper.
static int
AvoidMessageBoxHook(int ReportType, char *Message, int *Return) {
  // Set *Return to the retry code for the return value of _CrtDbgReport:
  // http://msdn.microsoft.com/en-us/library/8hyw4sy7(v=vs.71).aspx
  // This may also trigger just-in-time debugging via DebugBreak().
  if (Return)
    *Return = 1;
  // Don't call _CrtDbgReport.
  return TRUE;
}
#endif

void DisableSystemDialogsOnCrash() {
#ifdef _MSC_VER
  // We're already handling writing a "something went wrong" message.
  _set_abort_behavior(0, _WRITE_ABORT_MSG);
  // Disable Dr. Watson.
  _set_abort_behavior(0, _CALL_REPORTFAULT);
  _CrtSetReportHook(AvoidMessageBoxHook);

  // Disable standard error dialog box.
  SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX |
               SEM_NOOPENFILEERRORBOX);
  _set_error_mode(_OUT_TO_STDERR);
#endif
}

int main(int argc, char **argv) {

    // Enable this to enable finegrained heap checks
    // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF );

    DisableSystemDialogsOnCrash();

#ifdef AMD_EXTENSIONS
    amd::hsail::registerExtensions();
#endif // AMD_EXTENSIONS

    Tool tool;

#if defined(DEBUG) || defined(_DEBUG) || defined(NDEBUG)
    tool.SetEnableComments(true);
#endif

    return tool.execute(argc, argv) ? 0 : 1;
}
