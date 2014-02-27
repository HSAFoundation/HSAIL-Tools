// University of Illinois/NCSA
// Open Source License
//
// Copyright (c) 2013, Advanced Micro Devices, Inc.
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
static_assert(offsetof(Brig::BrigAluModifier, allBits) == 0, "bad alignment in Brig::BrigAluModifier");
static_assert(offsetof(Brig::BrigAluModifier, allBits)+sizeof(((Brig::BrigAluModifier*)0)->allBits) == sizeof(Brig::BrigAluModifier), "bad alignment in Brig::BrigAluModifier");

static_assert(offsetof(Brig::BrigDirective, size) == 0, "bad alignment in Brig::BrigDirective");
static_assert(offsetof(Brig::BrigDirective, kind)+sizeof(((Brig::BrigDirective*)0)->kind) == sizeof(Brig::BrigDirective), "bad alignment in Brig::BrigDirective");

static_assert(offsetof(Brig::BrigBlockEnd, size) == 0, "bad alignment in Brig::BrigBlockEnd");
static_assert(offsetof(Brig::BrigBlockEnd, kind)+sizeof(((Brig::BrigBlockEnd*)0)->kind) == sizeof(Brig::BrigBlockEnd), "bad alignment in Brig::BrigBlockEnd");

static_assert(offsetof(Brig::BrigBlockNumeric, size) == 0, "bad alignment in Brig::BrigBlockNumeric");
static_assert(offsetof(Brig::BrigBlockNumeric, kind)+sizeof(((Brig::BrigBlockNumeric*)0)->kind) == offsetof(Brig::BrigBlockNumeric,type), "bad alignment in Brig::BrigBlockNumeric");
static_assert(offsetof(Brig::BrigBlockNumeric, type)+sizeof(((Brig::BrigBlockNumeric*)0)->type) == offsetof(Brig::BrigBlockNumeric,reserved), "bad alignment in Brig::BrigBlockNumeric");
static_assert(offsetof(Brig::BrigBlockNumeric, reserved)+sizeof(((Brig::BrigBlockNumeric*)0)->reserved) == offsetof(Brig::BrigBlockNumeric,elementCount), "bad alignment in Brig::BrigBlockNumeric");
static_assert(offsetof(Brig::BrigBlockNumeric, elementCount)+sizeof(((Brig::BrigBlockNumeric*)0)->elementCount) == offsetof(Brig::BrigBlockNumeric,data), "bad alignment in Brig::BrigBlockNumeric");
static_assert(offsetof(Brig::BrigBlockNumeric, data)+sizeof(((Brig::BrigBlockNumeric*)0)->data) == sizeof(Brig::BrigBlockNumeric), "bad alignment in Brig::BrigBlockNumeric");

static_assert(offsetof(Brig::BrigBlockString, size) == 0, "bad alignment in Brig::BrigBlockString");
static_assert(offsetof(Brig::BrigBlockString, kind)+sizeof(((Brig::BrigBlockString*)0)->kind) == offsetof(Brig::BrigBlockString,string), "bad alignment in Brig::BrigBlockString");
static_assert(offsetof(Brig::BrigBlockString, string)+sizeof(((Brig::BrigBlockString*)0)->string) == sizeof(Brig::BrigBlockString), "bad alignment in Brig::BrigBlockString");

static_assert(offsetof(Brig::BrigDirectiveCode, size) == 0, "bad alignment in Brig::BrigDirectiveCode");
static_assert(offsetof(Brig::BrigDirectiveCode, kind)+sizeof(((Brig::BrigDirectiveCode*)0)->kind) == offsetof(Brig::BrigDirectiveCode,code), "bad alignment in Brig::BrigDirectiveCode");
static_assert(offsetof(Brig::BrigDirectiveCode, code)+sizeof(((Brig::BrigDirectiveCode*)0)->code) == sizeof(Brig::BrigDirectiveCode), "bad alignment in Brig::BrigDirectiveCode");

static_assert(offsetof(Brig::BrigBlockStart, size) == 0, "bad alignment in Brig::BrigBlockStart");
static_assert(offsetof(Brig::BrigBlockStart, kind)+sizeof(((Brig::BrigBlockStart*)0)->kind) == offsetof(Brig::BrigBlockStart,code), "bad alignment in Brig::BrigBlockStart");
static_assert(offsetof(Brig::BrigBlockStart, code)+sizeof(((Brig::BrigBlockStart*)0)->code) == offsetof(Brig::BrigBlockStart,name), "bad alignment in Brig::BrigBlockStart");
static_assert(offsetof(Brig::BrigBlockStart, name)+sizeof(((Brig::BrigBlockStart*)0)->name) == sizeof(Brig::BrigBlockStart), "bad alignment in Brig::BrigBlockStart");

static_assert(offsetof(Brig::BrigDirectiveArgScopeEnd, size) == 0, "bad alignment in Brig::BrigDirectiveArgScopeEnd");
static_assert(offsetof(Brig::BrigDirectiveArgScopeEnd, kind)+sizeof(((Brig::BrigDirectiveArgScopeEnd*)0)->kind) == offsetof(Brig::BrigDirectiveArgScopeEnd,code), "bad alignment in Brig::BrigDirectiveArgScopeEnd");
static_assert(offsetof(Brig::BrigDirectiveArgScopeEnd, code)+sizeof(((Brig::BrigDirectiveArgScopeEnd*)0)->code) == sizeof(Brig::BrigDirectiveArgScopeEnd), "bad alignment in Brig::BrigDirectiveArgScopeEnd");

static_assert(offsetof(Brig::BrigDirectiveArgScopeStart, size) == 0, "bad alignment in Brig::BrigDirectiveArgScopeStart");
static_assert(offsetof(Brig::BrigDirectiveArgScopeStart, kind)+sizeof(((Brig::BrigDirectiveArgScopeStart*)0)->kind) == offsetof(Brig::BrigDirectiveArgScopeStart,code), "bad alignment in Brig::BrigDirectiveArgScopeStart");
static_assert(offsetof(Brig::BrigDirectiveArgScopeStart, code)+sizeof(((Brig::BrigDirectiveArgScopeStart*)0)->code) == sizeof(Brig::BrigDirectiveArgScopeStart), "bad alignment in Brig::BrigDirectiveArgScopeStart");

static_assert(offsetof(Brig::BrigDirectiveCallableBase, size) == 0, "bad alignment in Brig::BrigDirectiveCallableBase");
static_assert(offsetof(Brig::BrigDirectiveCallableBase, kind)+sizeof(((Brig::BrigDirectiveCallableBase*)0)->kind) == offsetof(Brig::BrigDirectiveCallableBase,code), "bad alignment in Brig::BrigDirectiveCallableBase");
static_assert(offsetof(Brig::BrigDirectiveCallableBase, code)+sizeof(((Brig::BrigDirectiveCallableBase*)0)->code) == offsetof(Brig::BrigDirectiveCallableBase,name), "bad alignment in Brig::BrigDirectiveCallableBase");
static_assert(offsetof(Brig::BrigDirectiveCallableBase, name)+sizeof(((Brig::BrigDirectiveCallableBase*)0)->name) == offsetof(Brig::BrigDirectiveCallableBase,inArgCount), "bad alignment in Brig::BrigDirectiveCallableBase");
static_assert(offsetof(Brig::BrigDirectiveCallableBase, inArgCount)+sizeof(((Brig::BrigDirectiveCallableBase*)0)->inArgCount) == offsetof(Brig::BrigDirectiveCallableBase,outArgCount), "bad alignment in Brig::BrigDirectiveCallableBase");
static_assert(offsetof(Brig::BrigDirectiveCallableBase, outArgCount)+sizeof(((Brig::BrigDirectiveCallableBase*)0)->outArgCount) == sizeof(Brig::BrigDirectiveCallableBase), "bad alignment in Brig::BrigDirectiveCallableBase");

static_assert(offsetof(Brig::BrigDirectiveExecutable, size) == 0, "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, kind)+sizeof(((Brig::BrigDirectiveExecutable*)0)->kind) == offsetof(Brig::BrigDirectiveExecutable,code), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, code)+sizeof(((Brig::BrigDirectiveExecutable*)0)->code) == offsetof(Brig::BrigDirectiveExecutable,name), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, name)+sizeof(((Brig::BrigDirectiveExecutable*)0)->name) == offsetof(Brig::BrigDirectiveExecutable,inArgCount), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, inArgCount)+sizeof(((Brig::BrigDirectiveExecutable*)0)->inArgCount) == offsetof(Brig::BrigDirectiveExecutable,outArgCount), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, outArgCount)+sizeof(((Brig::BrigDirectiveExecutable*)0)->outArgCount) == offsetof(Brig::BrigDirectiveExecutable,firstInArg), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, firstInArg)+sizeof(((Brig::BrigDirectiveExecutable*)0)->firstInArg) == offsetof(Brig::BrigDirectiveExecutable,firstScopedDirective), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, firstScopedDirective)+sizeof(((Brig::BrigDirectiveExecutable*)0)->firstScopedDirective) == offsetof(Brig::BrigDirectiveExecutable,nextTopLevelDirective), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, nextTopLevelDirective)+sizeof(((Brig::BrigDirectiveExecutable*)0)->nextTopLevelDirective) == offsetof(Brig::BrigDirectiveExecutable,instCount), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, instCount)+sizeof(((Brig::BrigDirectiveExecutable*)0)->instCount) == offsetof(Brig::BrigDirectiveExecutable,modifier), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, modifier)+sizeof(((Brig::BrigDirectiveExecutable*)0)->modifier) == offsetof(Brig::BrigDirectiveExecutable,reserved), "bad alignment in Brig::BrigDirectiveExecutable");
static_assert(offsetof(Brig::BrigDirectiveExecutable, reserved)+sizeof(((Brig::BrigDirectiveExecutable*)0)->reserved) == sizeof(Brig::BrigDirectiveExecutable), "bad alignment in Brig::BrigDirectiveExecutable");

static_assert(offsetof(Brig::BrigDirectiveFunction, size) == 0, "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, kind)+sizeof(((Brig::BrigDirectiveFunction*)0)->kind) == offsetof(Brig::BrigDirectiveFunction,code), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, code)+sizeof(((Brig::BrigDirectiveFunction*)0)->code) == offsetof(Brig::BrigDirectiveFunction,name), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, name)+sizeof(((Brig::BrigDirectiveFunction*)0)->name) == offsetof(Brig::BrigDirectiveFunction,inArgCount), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, inArgCount)+sizeof(((Brig::BrigDirectiveFunction*)0)->inArgCount) == offsetof(Brig::BrigDirectiveFunction,outArgCount), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, outArgCount)+sizeof(((Brig::BrigDirectiveFunction*)0)->outArgCount) == offsetof(Brig::BrigDirectiveFunction,firstInArg), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, firstInArg)+sizeof(((Brig::BrigDirectiveFunction*)0)->firstInArg) == offsetof(Brig::BrigDirectiveFunction,firstScopedDirective), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, firstScopedDirective)+sizeof(((Brig::BrigDirectiveFunction*)0)->firstScopedDirective) == offsetof(Brig::BrigDirectiveFunction,nextTopLevelDirective), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, nextTopLevelDirective)+sizeof(((Brig::BrigDirectiveFunction*)0)->nextTopLevelDirective) == offsetof(Brig::BrigDirectiveFunction,instCount), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, instCount)+sizeof(((Brig::BrigDirectiveFunction*)0)->instCount) == offsetof(Brig::BrigDirectiveFunction,modifier), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, modifier)+sizeof(((Brig::BrigDirectiveFunction*)0)->modifier) == offsetof(Brig::BrigDirectiveFunction,reserved), "bad alignment in Brig::BrigDirectiveFunction");
static_assert(offsetof(Brig::BrigDirectiveFunction, reserved)+sizeof(((Brig::BrigDirectiveFunction*)0)->reserved) == sizeof(Brig::BrigDirectiveFunction), "bad alignment in Brig::BrigDirectiveFunction");

static_assert(offsetof(Brig::BrigDirectiveKernel, size) == 0, "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, kind)+sizeof(((Brig::BrigDirectiveKernel*)0)->kind) == offsetof(Brig::BrigDirectiveKernel,code), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, code)+sizeof(((Brig::BrigDirectiveKernel*)0)->code) == offsetof(Brig::BrigDirectiveKernel,name), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, name)+sizeof(((Brig::BrigDirectiveKernel*)0)->name) == offsetof(Brig::BrigDirectiveKernel,inArgCount), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, inArgCount)+sizeof(((Brig::BrigDirectiveKernel*)0)->inArgCount) == offsetof(Brig::BrigDirectiveKernel,outArgCount), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, outArgCount)+sizeof(((Brig::BrigDirectiveKernel*)0)->outArgCount) == offsetof(Brig::BrigDirectiveKernel,firstInArg), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, firstInArg)+sizeof(((Brig::BrigDirectiveKernel*)0)->firstInArg) == offsetof(Brig::BrigDirectiveKernel,firstScopedDirective), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, firstScopedDirective)+sizeof(((Brig::BrigDirectiveKernel*)0)->firstScopedDirective) == offsetof(Brig::BrigDirectiveKernel,nextTopLevelDirective), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, nextTopLevelDirective)+sizeof(((Brig::BrigDirectiveKernel*)0)->nextTopLevelDirective) == offsetof(Brig::BrigDirectiveKernel,instCount), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, instCount)+sizeof(((Brig::BrigDirectiveKernel*)0)->instCount) == offsetof(Brig::BrigDirectiveKernel,modifier), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, modifier)+sizeof(((Brig::BrigDirectiveKernel*)0)->modifier) == offsetof(Brig::BrigDirectiveKernel,reserved), "bad alignment in Brig::BrigDirectiveKernel");
static_assert(offsetof(Brig::BrigDirectiveKernel, reserved)+sizeof(((Brig::BrigDirectiveKernel*)0)->reserved) == sizeof(Brig::BrigDirectiveKernel), "bad alignment in Brig::BrigDirectiveKernel");

static_assert(offsetof(Brig::BrigDirectiveSignature, size) == 0, "bad alignment in Brig::BrigDirectiveSignature");
static_assert(offsetof(Brig::BrigDirectiveSignature, kind)+sizeof(((Brig::BrigDirectiveSignature*)0)->kind) == offsetof(Brig::BrigDirectiveSignature,code), "bad alignment in Brig::BrigDirectiveSignature");
static_assert(offsetof(Brig::BrigDirectiveSignature, code)+sizeof(((Brig::BrigDirectiveSignature*)0)->code) == offsetof(Brig::BrigDirectiveSignature,name), "bad alignment in Brig::BrigDirectiveSignature");
static_assert(offsetof(Brig::BrigDirectiveSignature, name)+sizeof(((Brig::BrigDirectiveSignature*)0)->name) == offsetof(Brig::BrigDirectiveSignature,inArgCount), "bad alignment in Brig::BrigDirectiveSignature");
static_assert(offsetof(Brig::BrigDirectiveSignature, inArgCount)+sizeof(((Brig::BrigDirectiveSignature*)0)->inArgCount) == offsetof(Brig::BrigDirectiveSignature,outArgCount), "bad alignment in Brig::BrigDirectiveSignature");
static_assert(offsetof(Brig::BrigDirectiveSignature, outArgCount)+sizeof(((Brig::BrigDirectiveSignature*)0)->outArgCount) == offsetof(Brig::BrigDirectiveSignature,args), "bad alignment in Brig::BrigDirectiveSignature");
static_assert(offsetof(Brig::BrigDirectiveSignature, args)+sizeof(((Brig::BrigDirectiveSignature*)0)->args) == sizeof(Brig::BrigDirectiveSignature), "bad alignment in Brig::BrigDirectiveSignature");

static_assert(offsetof(Brig::BrigDirectiveComment, size) == 0, "bad alignment in Brig::BrigDirectiveComment");
static_assert(offsetof(Brig::BrigDirectiveComment, kind)+sizeof(((Brig::BrigDirectiveComment*)0)->kind) == offsetof(Brig::BrigDirectiveComment,code), "bad alignment in Brig::BrigDirectiveComment");
static_assert(offsetof(Brig::BrigDirectiveComment, code)+sizeof(((Brig::BrigDirectiveComment*)0)->code) == offsetof(Brig::BrigDirectiveComment,name), "bad alignment in Brig::BrigDirectiveComment");
static_assert(offsetof(Brig::BrigDirectiveComment, name)+sizeof(((Brig::BrigDirectiveComment*)0)->name) == sizeof(Brig::BrigDirectiveComment), "bad alignment in Brig::BrigDirectiveComment");

static_assert(offsetof(Brig::BrigDirectiveControl, size) == 0, "bad alignment in Brig::BrigDirectiveControl");
static_assert(offsetof(Brig::BrigDirectiveControl, kind)+sizeof(((Brig::BrigDirectiveControl*)0)->kind) == offsetof(Brig::BrigDirectiveControl,code), "bad alignment in Brig::BrigDirectiveControl");
static_assert(offsetof(Brig::BrigDirectiveControl, code)+sizeof(((Brig::BrigDirectiveControl*)0)->code) == offsetof(Brig::BrigDirectiveControl,control), "bad alignment in Brig::BrigDirectiveControl");
static_assert(offsetof(Brig::BrigDirectiveControl, control)+sizeof(((Brig::BrigDirectiveControl*)0)->control) == offsetof(Brig::BrigDirectiveControl,type), "bad alignment in Brig::BrigDirectiveControl");
static_assert(offsetof(Brig::BrigDirectiveControl, type)+sizeof(((Brig::BrigDirectiveControl*)0)->type) == offsetof(Brig::BrigDirectiveControl,reserved), "bad alignment in Brig::BrigDirectiveControl");
static_assert(offsetof(Brig::BrigDirectiveControl, reserved)+sizeof(((Brig::BrigDirectiveControl*)0)->reserved) == offsetof(Brig::BrigDirectiveControl,valueCount), "bad alignment in Brig::BrigDirectiveControl");
static_assert(offsetof(Brig::BrigDirectiveControl, valueCount)+sizeof(((Brig::BrigDirectiveControl*)0)->valueCount) == offsetof(Brig::BrigDirectiveControl,values), "bad alignment in Brig::BrigDirectiveControl");
static_assert(offsetof(Brig::BrigDirectiveControl, values)+sizeof(((Brig::BrigDirectiveControl*)0)->values) == sizeof(Brig::BrigDirectiveControl), "bad alignment in Brig::BrigDirectiveControl");

static_assert(offsetof(Brig::BrigDirectiveExtension, size) == 0, "bad alignment in Brig::BrigDirectiveExtension");
static_assert(offsetof(Brig::BrigDirectiveExtension, kind)+sizeof(((Brig::BrigDirectiveExtension*)0)->kind) == offsetof(Brig::BrigDirectiveExtension,code), "bad alignment in Brig::BrigDirectiveExtension");
static_assert(offsetof(Brig::BrigDirectiveExtension, code)+sizeof(((Brig::BrigDirectiveExtension*)0)->code) == offsetof(Brig::BrigDirectiveExtension,name), "bad alignment in Brig::BrigDirectiveExtension");
static_assert(offsetof(Brig::BrigDirectiveExtension, name)+sizeof(((Brig::BrigDirectiveExtension*)0)->name) == sizeof(Brig::BrigDirectiveExtension), "bad alignment in Brig::BrigDirectiveExtension");

static_assert(offsetof(Brig::BrigDirectiveFbarrier, size) == 0, "bad alignment in Brig::BrigDirectiveFbarrier");
static_assert(offsetof(Brig::BrigDirectiveFbarrier, kind)+sizeof(((Brig::BrigDirectiveFbarrier*)0)->kind) == offsetof(Brig::BrigDirectiveFbarrier,code), "bad alignment in Brig::BrigDirectiveFbarrier");
static_assert(offsetof(Brig::BrigDirectiveFbarrier, code)+sizeof(((Brig::BrigDirectiveFbarrier*)0)->code) == offsetof(Brig::BrigDirectiveFbarrier,name), "bad alignment in Brig::BrigDirectiveFbarrier");
static_assert(offsetof(Brig::BrigDirectiveFbarrier, name)+sizeof(((Brig::BrigDirectiveFbarrier*)0)->name) == sizeof(Brig::BrigDirectiveFbarrier), "bad alignment in Brig::BrigDirectiveFbarrier");

static_assert(offsetof(Brig::BrigDirectiveImageInit, size) == 0, "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, kind)+sizeof(((Brig::BrigDirectiveImageInit*)0)->kind) == offsetof(Brig::BrigDirectiveImageInit,code), "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, code)+sizeof(((Brig::BrigDirectiveImageInit*)0)->code) == offsetof(Brig::BrigDirectiveImageInit,width), "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, width)+sizeof(((Brig::BrigDirectiveImageInit*)0)->width) == offsetof(Brig::BrigDirectiveImageInit,height), "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, height)+sizeof(((Brig::BrigDirectiveImageInit*)0)->height) == offsetof(Brig::BrigDirectiveImageInit,depth), "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, depth)+sizeof(((Brig::BrigDirectiveImageInit*)0)->depth) == offsetof(Brig::BrigDirectiveImageInit,array), "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, array)+sizeof(((Brig::BrigDirectiveImageInit*)0)->array) == offsetof(Brig::BrigDirectiveImageInit,geometry), "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, geometry)+sizeof(((Brig::BrigDirectiveImageInit*)0)->geometry) == offsetof(Brig::BrigDirectiveImageInit,order), "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, order)+sizeof(((Brig::BrigDirectiveImageInit*)0)->order) == offsetof(Brig::BrigDirectiveImageInit,format), "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, format)+sizeof(((Brig::BrigDirectiveImageInit*)0)->format) == offsetof(Brig::BrigDirectiveImageInit,reserved), "bad alignment in Brig::BrigDirectiveImageInit");
static_assert(offsetof(Brig::BrigDirectiveImageInit, reserved)+sizeof(((Brig::BrigDirectiveImageInit*)0)->reserved) == sizeof(Brig::BrigDirectiveImageInit), "bad alignment in Brig::BrigDirectiveImageInit");

static_assert(offsetof(Brig::BrigDirectiveLabel, size) == 0, "bad alignment in Brig::BrigDirectiveLabel");
static_assert(offsetof(Brig::BrigDirectiveLabel, kind)+sizeof(((Brig::BrigDirectiveLabel*)0)->kind) == offsetof(Brig::BrigDirectiveLabel,code), "bad alignment in Brig::BrigDirectiveLabel");
static_assert(offsetof(Brig::BrigDirectiveLabel, code)+sizeof(((Brig::BrigDirectiveLabel*)0)->code) == offsetof(Brig::BrigDirectiveLabel,name), "bad alignment in Brig::BrigDirectiveLabel");
static_assert(offsetof(Brig::BrigDirectiveLabel, name)+sizeof(((Brig::BrigDirectiveLabel*)0)->name) == sizeof(Brig::BrigDirectiveLabel), "bad alignment in Brig::BrigDirectiveLabel");

static_assert(offsetof(Brig::BrigDirectiveLabelInit, size) == 0, "bad alignment in Brig::BrigDirectiveLabelInit");
static_assert(offsetof(Brig::BrigDirectiveLabelInit, kind)+sizeof(((Brig::BrigDirectiveLabelInit*)0)->kind) == offsetof(Brig::BrigDirectiveLabelInit,code), "bad alignment in Brig::BrigDirectiveLabelInit");
static_assert(offsetof(Brig::BrigDirectiveLabelInit, code)+sizeof(((Brig::BrigDirectiveLabelInit*)0)->code) == offsetof(Brig::BrigDirectiveLabelInit,labelCount), "bad alignment in Brig::BrigDirectiveLabelInit");
static_assert(offsetof(Brig::BrigDirectiveLabelInit, labelCount)+sizeof(((Brig::BrigDirectiveLabelInit*)0)->labelCount) == offsetof(Brig::BrigDirectiveLabelInit,reserved), "bad alignment in Brig::BrigDirectiveLabelInit");
static_assert(offsetof(Brig::BrigDirectiveLabelInit, reserved)+sizeof(((Brig::BrigDirectiveLabelInit*)0)->reserved) == offsetof(Brig::BrigDirectiveLabelInit,labels), "bad alignment in Brig::BrigDirectiveLabelInit");
static_assert(offsetof(Brig::BrigDirectiveLabelInit, labels)+sizeof(((Brig::BrigDirectiveLabelInit*)0)->labels) == sizeof(Brig::BrigDirectiveLabelInit), "bad alignment in Brig::BrigDirectiveLabelInit");

static_assert(offsetof(Brig::BrigDirectiveLabelTargets, size) == 0, "bad alignment in Brig::BrigDirectiveLabelTargets");
static_assert(offsetof(Brig::BrigDirectiveLabelTargets, kind)+sizeof(((Brig::BrigDirectiveLabelTargets*)0)->kind) == offsetof(Brig::BrigDirectiveLabelTargets,code), "bad alignment in Brig::BrigDirectiveLabelTargets");
static_assert(offsetof(Brig::BrigDirectiveLabelTargets, code)+sizeof(((Brig::BrigDirectiveLabelTargets*)0)->code) == offsetof(Brig::BrigDirectiveLabelTargets,name), "bad alignment in Brig::BrigDirectiveLabelTargets");
static_assert(offsetof(Brig::BrigDirectiveLabelTargets, name)+sizeof(((Brig::BrigDirectiveLabelTargets*)0)->name) == offsetof(Brig::BrigDirectiveLabelTargets,labelCount), "bad alignment in Brig::BrigDirectiveLabelTargets");
static_assert(offsetof(Brig::BrigDirectiveLabelTargets, labelCount)+sizeof(((Brig::BrigDirectiveLabelTargets*)0)->labelCount) == offsetof(Brig::BrigDirectiveLabelTargets,reserved), "bad alignment in Brig::BrigDirectiveLabelTargets");
static_assert(offsetof(Brig::BrigDirectiveLabelTargets, reserved)+sizeof(((Brig::BrigDirectiveLabelTargets*)0)->reserved) == offsetof(Brig::BrigDirectiveLabelTargets,labels), "bad alignment in Brig::BrigDirectiveLabelTargets");
static_assert(offsetof(Brig::BrigDirectiveLabelTargets, labels)+sizeof(((Brig::BrigDirectiveLabelTargets*)0)->labels) == sizeof(Brig::BrigDirectiveLabelTargets), "bad alignment in Brig::BrigDirectiveLabelTargets");

static_assert(offsetof(Brig::BrigDirectiveLoc, size) == 0, "bad alignment in Brig::BrigDirectiveLoc");
static_assert(offsetof(Brig::BrigDirectiveLoc, kind)+sizeof(((Brig::BrigDirectiveLoc*)0)->kind) == offsetof(Brig::BrigDirectiveLoc,code), "bad alignment in Brig::BrigDirectiveLoc");
static_assert(offsetof(Brig::BrigDirectiveLoc, code)+sizeof(((Brig::BrigDirectiveLoc*)0)->code) == offsetof(Brig::BrigDirectiveLoc,filename), "bad alignment in Brig::BrigDirectiveLoc");
static_assert(offsetof(Brig::BrigDirectiveLoc, filename)+sizeof(((Brig::BrigDirectiveLoc*)0)->filename) == offsetof(Brig::BrigDirectiveLoc,line), "bad alignment in Brig::BrigDirectiveLoc");
static_assert(offsetof(Brig::BrigDirectiveLoc, line)+sizeof(((Brig::BrigDirectiveLoc*)0)->line) == offsetof(Brig::BrigDirectiveLoc,column), "bad alignment in Brig::BrigDirectiveLoc");
static_assert(offsetof(Brig::BrigDirectiveLoc, column)+sizeof(((Brig::BrigDirectiveLoc*)0)->column) == sizeof(Brig::BrigDirectiveLoc), "bad alignment in Brig::BrigDirectiveLoc");

static_assert(offsetof(Brig::BrigDirectivePragma, size) == 0, "bad alignment in Brig::BrigDirectivePragma");
static_assert(offsetof(Brig::BrigDirectivePragma, kind)+sizeof(((Brig::BrigDirectivePragma*)0)->kind) == offsetof(Brig::BrigDirectivePragma,code), "bad alignment in Brig::BrigDirectivePragma");
static_assert(offsetof(Brig::BrigDirectivePragma, code)+sizeof(((Brig::BrigDirectivePragma*)0)->code) == offsetof(Brig::BrigDirectivePragma,name), "bad alignment in Brig::BrigDirectivePragma");
static_assert(offsetof(Brig::BrigDirectivePragma, name)+sizeof(((Brig::BrigDirectivePragma*)0)->name) == sizeof(Brig::BrigDirectivePragma), "bad alignment in Brig::BrigDirectivePragma");

static_assert(offsetof(Brig::BrigDirectiveVariable, size) == 0, "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, kind)+sizeof(((Brig::BrigDirectiveVariable*)0)->kind) == offsetof(Brig::BrigDirectiveVariable,code), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, code)+sizeof(((Brig::BrigDirectiveVariable*)0)->code) == offsetof(Brig::BrigDirectiveVariable,name), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, name)+sizeof(((Brig::BrigDirectiveVariable*)0)->name) == offsetof(Brig::BrigDirectiveVariable,init), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, init)+sizeof(((Brig::BrigDirectiveVariable*)0)->init) == offsetof(Brig::BrigDirectiveVariable,type), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, type)+sizeof(((Brig::BrigDirectiveVariable*)0)->type) == offsetof(Brig::BrigDirectiveVariable,segment), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, segment)+sizeof(((Brig::BrigDirectiveVariable*)0)->segment) == offsetof(Brig::BrigDirectiveVariable,align), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, align)+sizeof(((Brig::BrigDirectiveVariable*)0)->align) == offsetof(Brig::BrigDirectiveVariable,dimLo), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, dimLo)+sizeof(((Brig::BrigDirectiveVariable*)0)->dimLo) == offsetof(Brig::BrigDirectiveVariable,dimHi), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, dimHi)+sizeof(((Brig::BrigDirectiveVariable*)0)->dimHi) == offsetof(Brig::BrigDirectiveVariable,modifier), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, modifier)+sizeof(((Brig::BrigDirectiveVariable*)0)->modifier) == offsetof(Brig::BrigDirectiveVariable,reserved), "bad alignment in Brig::BrigDirectiveVariable");
static_assert(offsetof(Brig::BrigDirectiveVariable, reserved)+sizeof(((Brig::BrigDirectiveVariable*)0)->reserved) == sizeof(Brig::BrigDirectiveVariable), "bad alignment in Brig::BrigDirectiveVariable");

static_assert(offsetof(Brig::BrigDirectiveVariableInit, size) == 0, "bad alignment in Brig::BrigDirectiveVariableInit");
static_assert(offsetof(Brig::BrigDirectiveVariableInit, kind)+sizeof(((Brig::BrigDirectiveVariableInit*)0)->kind) == offsetof(Brig::BrigDirectiveVariableInit,code), "bad alignment in Brig::BrigDirectiveVariableInit");
static_assert(offsetof(Brig::BrigDirectiveVariableInit, code)+sizeof(((Brig::BrigDirectiveVariableInit*)0)->code) == offsetof(Brig::BrigDirectiveVariableInit,data), "bad alignment in Brig::BrigDirectiveVariableInit");
static_assert(offsetof(Brig::BrigDirectiveVariableInit, data)+sizeof(((Brig::BrigDirectiveVariableInit*)0)->data) == offsetof(Brig::BrigDirectiveVariableInit,elementCount), "bad alignment in Brig::BrigDirectiveVariableInit");
static_assert(offsetof(Brig::BrigDirectiveVariableInit, elementCount)+sizeof(((Brig::BrigDirectiveVariableInit*)0)->elementCount) == offsetof(Brig::BrigDirectiveVariableInit,type), "bad alignment in Brig::BrigDirectiveVariableInit");
static_assert(offsetof(Brig::BrigDirectiveVariableInit, type)+sizeof(((Brig::BrigDirectiveVariableInit*)0)->type) == offsetof(Brig::BrigDirectiveVariableInit,reserved), "bad alignment in Brig::BrigDirectiveVariableInit");
static_assert(offsetof(Brig::BrigDirectiveVariableInit, reserved)+sizeof(((Brig::BrigDirectiveVariableInit*)0)->reserved) == sizeof(Brig::BrigDirectiveVariableInit), "bad alignment in Brig::BrigDirectiveVariableInit");

static_assert(offsetof(Brig::BrigDirectiveVersion, size) == 0, "bad alignment in Brig::BrigDirectiveVersion");
static_assert(offsetof(Brig::BrigDirectiveVersion, kind)+sizeof(((Brig::BrigDirectiveVersion*)0)->kind) == offsetof(Brig::BrigDirectiveVersion,code), "bad alignment in Brig::BrigDirectiveVersion");
static_assert(offsetof(Brig::BrigDirectiveVersion, code)+sizeof(((Brig::BrigDirectiveVersion*)0)->code) == offsetof(Brig::BrigDirectiveVersion,hsailMajor), "bad alignment in Brig::BrigDirectiveVersion");
static_assert(offsetof(Brig::BrigDirectiveVersion, hsailMajor)+sizeof(((Brig::BrigDirectiveVersion*)0)->hsailMajor) == offsetof(Brig::BrigDirectiveVersion,hsailMinor), "bad alignment in Brig::BrigDirectiveVersion");
static_assert(offsetof(Brig::BrigDirectiveVersion, hsailMinor)+sizeof(((Brig::BrigDirectiveVersion*)0)->hsailMinor) == offsetof(Brig::BrigDirectiveVersion,brigMajor), "bad alignment in Brig::BrigDirectiveVersion");
static_assert(offsetof(Brig::BrigDirectiveVersion, brigMajor)+sizeof(((Brig::BrigDirectiveVersion*)0)->brigMajor) == offsetof(Brig::BrigDirectiveVersion,brigMinor), "bad alignment in Brig::BrigDirectiveVersion");
static_assert(offsetof(Brig::BrigDirectiveVersion, brigMinor)+sizeof(((Brig::BrigDirectiveVersion*)0)->brigMinor) == offsetof(Brig::BrigDirectiveVersion,profile), "bad alignment in Brig::BrigDirectiveVersion");
static_assert(offsetof(Brig::BrigDirectiveVersion, profile)+sizeof(((Brig::BrigDirectiveVersion*)0)->profile) == offsetof(Brig::BrigDirectiveVersion,machineModel), "bad alignment in Brig::BrigDirectiveVersion");
static_assert(offsetof(Brig::BrigDirectiveVersion, machineModel)+sizeof(((Brig::BrigDirectiveVersion*)0)->machineModel) == offsetof(Brig::BrigDirectiveVersion,reserved), "bad alignment in Brig::BrigDirectiveVersion");
static_assert(offsetof(Brig::BrigDirectiveVersion, reserved)+sizeof(((Brig::BrigDirectiveVersion*)0)->reserved) == sizeof(Brig::BrigDirectiveVersion), "bad alignment in Brig::BrigDirectiveVersion");

static_assert(offsetof(Brig::BrigDirectiveSamplerInit, size) == 0, "bad alignment in Brig::BrigDirectiveSamplerInit");
static_assert(offsetof(Brig::BrigDirectiveSamplerInit, kind)+sizeof(((Brig::BrigDirectiveSamplerInit*)0)->kind) == offsetof(Brig::BrigDirectiveSamplerInit,modifier), "bad alignment in Brig::BrigDirectiveSamplerInit");
static_assert(offsetof(Brig::BrigDirectiveSamplerInit, modifier)+sizeof(((Brig::BrigDirectiveSamplerInit*)0)->modifier) == offsetof(Brig::BrigDirectiveSamplerInit,boundaryU), "bad alignment in Brig::BrigDirectiveSamplerInit");
static_assert(offsetof(Brig::BrigDirectiveSamplerInit, boundaryU)+sizeof(((Brig::BrigDirectiveSamplerInit*)0)->boundaryU) == offsetof(Brig::BrigDirectiveSamplerInit,boundaryV), "bad alignment in Brig::BrigDirectiveSamplerInit");
static_assert(offsetof(Brig::BrigDirectiveSamplerInit, boundaryV)+sizeof(((Brig::BrigDirectiveSamplerInit*)0)->boundaryV) == offsetof(Brig::BrigDirectiveSamplerInit,boundaryW), "bad alignment in Brig::BrigDirectiveSamplerInit");
static_assert(offsetof(Brig::BrigDirectiveSamplerInit, boundaryW)+sizeof(((Brig::BrigDirectiveSamplerInit*)0)->boundaryW) == sizeof(Brig::BrigDirectiveSamplerInit), "bad alignment in Brig::BrigDirectiveSamplerInit");

static_assert(offsetof(Brig::BrigDirectiveSignatureArgument, type) == 0, "bad alignment in Brig::BrigDirectiveSignatureArgument");
static_assert(offsetof(Brig::BrigDirectiveSignatureArgument, align)+sizeof(((Brig::BrigDirectiveSignatureArgument*)0)->align) == offsetof(Brig::BrigDirectiveSignatureArgument,modifier), "bad alignment in Brig::BrigDirectiveSignatureArgument");
static_assert(offsetof(Brig::BrigDirectiveSignatureArgument, modifier)+sizeof(((Brig::BrigDirectiveSignatureArgument*)0)->modifier) == offsetof(Brig::BrigDirectiveSignatureArgument,dimLo), "bad alignment in Brig::BrigDirectiveSignatureArgument");
static_assert(offsetof(Brig::BrigDirectiveSignatureArgument, dimLo)+sizeof(((Brig::BrigDirectiveSignatureArgument*)0)->dimLo) == offsetof(Brig::BrigDirectiveSignatureArgument,dimHi), "bad alignment in Brig::BrigDirectiveSignatureArgument");
static_assert(offsetof(Brig::BrigDirectiveSignatureArgument, dimHi)+sizeof(((Brig::BrigDirectiveSignatureArgument*)0)->dimHi) == sizeof(Brig::BrigDirectiveSignatureArgument), "bad alignment in Brig::BrigDirectiveSignatureArgument");

static_assert(offsetof(Brig::BrigExecutableModifier, allBits) == 0, "bad alignment in Brig::BrigExecutableModifier");
static_assert(offsetof(Brig::BrigExecutableModifier, allBits)+sizeof(((Brig::BrigExecutableModifier*)0)->allBits) == sizeof(Brig::BrigExecutableModifier), "bad alignment in Brig::BrigExecutableModifier");

static_assert(offsetof(Brig::BrigInst, size) == 0, "bad alignment in Brig::BrigInst");
static_assert(offsetof(Brig::BrigInst, kind)+sizeof(((Brig::BrigInst*)0)->kind) == offsetof(Brig::BrigInst,opcode), "bad alignment in Brig::BrigInst");
static_assert(offsetof(Brig::BrigInst, opcode)+sizeof(((Brig::BrigInst*)0)->opcode) == offsetof(Brig::BrigInst,type), "bad alignment in Brig::BrigInst");
static_assert(offsetof(Brig::BrigInst, type)+sizeof(((Brig::BrigInst*)0)->type) == offsetof(Brig::BrigInst,operands), "bad alignment in Brig::BrigInst");
static_assert(offsetof(Brig::BrigInst, operands)+sizeof(((Brig::BrigInst*)0)->operands) == sizeof(Brig::BrigInst), "bad alignment in Brig::BrigInst");

static_assert(offsetof(Brig::BrigInstAddr, size) == 0, "bad alignment in Brig::BrigInstAddr");
static_assert(offsetof(Brig::BrigInstAddr, kind)+sizeof(((Brig::BrigInstAddr*)0)->kind) == offsetof(Brig::BrigInstAddr,opcode), "bad alignment in Brig::BrigInstAddr");
static_assert(offsetof(Brig::BrigInstAddr, opcode)+sizeof(((Brig::BrigInstAddr*)0)->opcode) == offsetof(Brig::BrigInstAddr,type), "bad alignment in Brig::BrigInstAddr");
static_assert(offsetof(Brig::BrigInstAddr, type)+sizeof(((Brig::BrigInstAddr*)0)->type) == offsetof(Brig::BrigInstAddr,operands), "bad alignment in Brig::BrigInstAddr");
static_assert(offsetof(Brig::BrigInstAddr, operands)+sizeof(((Brig::BrigInstAddr*)0)->operands) == offsetof(Brig::BrigInstAddr,segment), "bad alignment in Brig::BrigInstAddr");
static_assert(offsetof(Brig::BrigInstAddr, segment)+sizeof(((Brig::BrigInstAddr*)0)->segment) == offsetof(Brig::BrigInstAddr,reserved), "bad alignment in Brig::BrigInstAddr");
static_assert(offsetof(Brig::BrigInstAddr, reserved)+sizeof(((Brig::BrigInstAddr*)0)->reserved) == sizeof(Brig::BrigInstAddr), "bad alignment in Brig::BrigInstAddr");

static_assert(offsetof(Brig::BrigInstAtomic, size) == 0, "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, kind)+sizeof(((Brig::BrigInstAtomic*)0)->kind) == offsetof(Brig::BrigInstAtomic,opcode), "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, opcode)+sizeof(((Brig::BrigInstAtomic*)0)->opcode) == offsetof(Brig::BrigInstAtomic,type), "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, type)+sizeof(((Brig::BrigInstAtomic*)0)->type) == offsetof(Brig::BrigInstAtomic,operands), "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, operands)+sizeof(((Brig::BrigInstAtomic*)0)->operands) == offsetof(Brig::BrigInstAtomic,segment), "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, segment)+sizeof(((Brig::BrigInstAtomic*)0)->segment) == offsetof(Brig::BrigInstAtomic,memoryOrder), "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, memoryOrder)+sizeof(((Brig::BrigInstAtomic*)0)->memoryOrder) == offsetof(Brig::BrigInstAtomic,memoryScope), "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, memoryScope)+sizeof(((Brig::BrigInstAtomic*)0)->memoryScope) == offsetof(Brig::BrigInstAtomic,atomicOperation), "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, atomicOperation)+sizeof(((Brig::BrigInstAtomic*)0)->atomicOperation) == offsetof(Brig::BrigInstAtomic,equivClass), "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, equivClass)+sizeof(((Brig::BrigInstAtomic*)0)->equivClass) == offsetof(Brig::BrigInstAtomic,reserved), "bad alignment in Brig::BrigInstAtomic");
static_assert(offsetof(Brig::BrigInstAtomic, reserved)+sizeof(((Brig::BrigInstAtomic*)0)->reserved) == sizeof(Brig::BrigInstAtomic), "bad alignment in Brig::BrigInstAtomic");

static_assert(offsetof(Brig::BrigInstAtomicImage, size) == 0, "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, kind)+sizeof(((Brig::BrigInstAtomicImage*)0)->kind) == offsetof(Brig::BrigInstAtomicImage,opcode), "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, opcode)+sizeof(((Brig::BrigInstAtomicImage*)0)->opcode) == offsetof(Brig::BrigInstAtomicImage,type), "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, type)+sizeof(((Brig::BrigInstAtomicImage*)0)->type) == offsetof(Brig::BrigInstAtomicImage,operands), "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, operands)+sizeof(((Brig::BrigInstAtomicImage*)0)->operands) == offsetof(Brig::BrigInstAtomicImage,imageType), "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, imageType)+sizeof(((Brig::BrigInstAtomicImage*)0)->imageType) == offsetof(Brig::BrigInstAtomicImage,coordType), "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, coordType)+sizeof(((Brig::BrigInstAtomicImage*)0)->coordType) == offsetof(Brig::BrigInstAtomicImage,geometry), "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, geometry)+sizeof(((Brig::BrigInstAtomicImage*)0)->geometry) == offsetof(Brig::BrigInstAtomicImage,atomicOperation), "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, atomicOperation)+sizeof(((Brig::BrigInstAtomicImage*)0)->atomicOperation) == offsetof(Brig::BrigInstAtomicImage,equivClass), "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, equivClass)+sizeof(((Brig::BrigInstAtomicImage*)0)->equivClass) == offsetof(Brig::BrigInstAtomicImage,reserved), "bad alignment in Brig::BrigInstAtomicImage");
static_assert(offsetof(Brig::BrigInstAtomicImage, reserved)+sizeof(((Brig::BrigInstAtomicImage*)0)->reserved) == sizeof(Brig::BrigInstAtomicImage), "bad alignment in Brig::BrigInstAtomicImage");

static_assert(offsetof(Brig::BrigInstBasic, size) == 0, "bad alignment in Brig::BrigInstBasic");
static_assert(offsetof(Brig::BrigInstBasic, kind)+sizeof(((Brig::BrigInstBasic*)0)->kind) == offsetof(Brig::BrigInstBasic,opcode), "bad alignment in Brig::BrigInstBasic");
static_assert(offsetof(Brig::BrigInstBasic, opcode)+sizeof(((Brig::BrigInstBasic*)0)->opcode) == offsetof(Brig::BrigInstBasic,type), "bad alignment in Brig::BrigInstBasic");
static_assert(offsetof(Brig::BrigInstBasic, type)+sizeof(((Brig::BrigInstBasic*)0)->type) == offsetof(Brig::BrigInstBasic,operands), "bad alignment in Brig::BrigInstBasic");
static_assert(offsetof(Brig::BrigInstBasic, operands)+sizeof(((Brig::BrigInstBasic*)0)->operands) == sizeof(Brig::BrigInstBasic), "bad alignment in Brig::BrigInstBasic");

static_assert(offsetof(Brig::BrigInstBr, size) == 0, "bad alignment in Brig::BrigInstBr");
static_assert(offsetof(Brig::BrigInstBr, kind)+sizeof(((Brig::BrigInstBr*)0)->kind) == offsetof(Brig::BrigInstBr,opcode), "bad alignment in Brig::BrigInstBr");
static_assert(offsetof(Brig::BrigInstBr, opcode)+sizeof(((Brig::BrigInstBr*)0)->opcode) == offsetof(Brig::BrigInstBr,type), "bad alignment in Brig::BrigInstBr");
static_assert(offsetof(Brig::BrigInstBr, type)+sizeof(((Brig::BrigInstBr*)0)->type) == offsetof(Brig::BrigInstBr,operands), "bad alignment in Brig::BrigInstBr");
static_assert(offsetof(Brig::BrigInstBr, operands)+sizeof(((Brig::BrigInstBr*)0)->operands) == offsetof(Brig::BrigInstBr,width), "bad alignment in Brig::BrigInstBr");
static_assert(offsetof(Brig::BrigInstBr, width)+sizeof(((Brig::BrigInstBr*)0)->width) == offsetof(Brig::BrigInstBr,reserved), "bad alignment in Brig::BrigInstBr");
static_assert(offsetof(Brig::BrigInstBr, reserved)+sizeof(((Brig::BrigInstBr*)0)->reserved) == sizeof(Brig::BrigInstBr), "bad alignment in Brig::BrigInstBr");

static_assert(offsetof(Brig::BrigInstCmp, size) == 0, "bad alignment in Brig::BrigInstCmp");
static_assert(offsetof(Brig::BrigInstCmp, kind)+sizeof(((Brig::BrigInstCmp*)0)->kind) == offsetof(Brig::BrigInstCmp,opcode), "bad alignment in Brig::BrigInstCmp");
static_assert(offsetof(Brig::BrigInstCmp, opcode)+sizeof(((Brig::BrigInstCmp*)0)->opcode) == offsetof(Brig::BrigInstCmp,type), "bad alignment in Brig::BrigInstCmp");
static_assert(offsetof(Brig::BrigInstCmp, type)+sizeof(((Brig::BrigInstCmp*)0)->type) == offsetof(Brig::BrigInstCmp,operands), "bad alignment in Brig::BrigInstCmp");
static_assert(offsetof(Brig::BrigInstCmp, operands)+sizeof(((Brig::BrigInstCmp*)0)->operands) == offsetof(Brig::BrigInstCmp,sourceType), "bad alignment in Brig::BrigInstCmp");
static_assert(offsetof(Brig::BrigInstCmp, sourceType)+sizeof(((Brig::BrigInstCmp*)0)->sourceType) == offsetof(Brig::BrigInstCmp,modifier), "bad alignment in Brig::BrigInstCmp");
static_assert(offsetof(Brig::BrigInstCmp, modifier)+sizeof(((Brig::BrigInstCmp*)0)->modifier) == offsetof(Brig::BrigInstCmp,compare), "bad alignment in Brig::BrigInstCmp");
static_assert(offsetof(Brig::BrigInstCmp, compare)+sizeof(((Brig::BrigInstCmp*)0)->compare) == offsetof(Brig::BrigInstCmp,pack), "bad alignment in Brig::BrigInstCmp");
static_assert(offsetof(Brig::BrigInstCmp, pack)+sizeof(((Brig::BrigInstCmp*)0)->pack) == offsetof(Brig::BrigInstCmp,reserved), "bad alignment in Brig::BrigInstCmp");
static_assert(offsetof(Brig::BrigInstCmp, reserved)+sizeof(((Brig::BrigInstCmp*)0)->reserved) == sizeof(Brig::BrigInstCmp), "bad alignment in Brig::BrigInstCmp");

static_assert(offsetof(Brig::BrigInstCvt, size) == 0, "bad alignment in Brig::BrigInstCvt");
static_assert(offsetof(Brig::BrigInstCvt, kind)+sizeof(((Brig::BrigInstCvt*)0)->kind) == offsetof(Brig::BrigInstCvt,opcode), "bad alignment in Brig::BrigInstCvt");
static_assert(offsetof(Brig::BrigInstCvt, opcode)+sizeof(((Brig::BrigInstCvt*)0)->opcode) == offsetof(Brig::BrigInstCvt,type), "bad alignment in Brig::BrigInstCvt");
static_assert(offsetof(Brig::BrigInstCvt, type)+sizeof(((Brig::BrigInstCvt*)0)->type) == offsetof(Brig::BrigInstCvt,operands), "bad alignment in Brig::BrigInstCvt");
static_assert(offsetof(Brig::BrigInstCvt, operands)+sizeof(((Brig::BrigInstCvt*)0)->operands) == offsetof(Brig::BrigInstCvt,sourceType), "bad alignment in Brig::BrigInstCvt");
static_assert(offsetof(Brig::BrigInstCvt, sourceType)+sizeof(((Brig::BrigInstCvt*)0)->sourceType) == offsetof(Brig::BrigInstCvt,modifier), "bad alignment in Brig::BrigInstCvt");
static_assert(offsetof(Brig::BrigInstCvt, modifier)+sizeof(((Brig::BrigInstCvt*)0)->modifier) == sizeof(Brig::BrigInstCvt), "bad alignment in Brig::BrigInstCvt");

static_assert(offsetof(Brig::BrigInstImage, size) == 0, "bad alignment in Brig::BrigInstImage");
static_assert(offsetof(Brig::BrigInstImage, kind)+sizeof(((Brig::BrigInstImage*)0)->kind) == offsetof(Brig::BrigInstImage,opcode), "bad alignment in Brig::BrigInstImage");
static_assert(offsetof(Brig::BrigInstImage, opcode)+sizeof(((Brig::BrigInstImage*)0)->opcode) == offsetof(Brig::BrigInstImage,type), "bad alignment in Brig::BrigInstImage");
static_assert(offsetof(Brig::BrigInstImage, type)+sizeof(((Brig::BrigInstImage*)0)->type) == offsetof(Brig::BrigInstImage,operands), "bad alignment in Brig::BrigInstImage");
static_assert(offsetof(Brig::BrigInstImage, operands)+sizeof(((Brig::BrigInstImage*)0)->operands) == offsetof(Brig::BrigInstImage,imageType), "bad alignment in Brig::BrigInstImage");
static_assert(offsetof(Brig::BrigInstImage, imageType)+sizeof(((Brig::BrigInstImage*)0)->imageType) == offsetof(Brig::BrigInstImage,coordType), "bad alignment in Brig::BrigInstImage");
static_assert(offsetof(Brig::BrigInstImage, coordType)+sizeof(((Brig::BrigInstImage*)0)->coordType) == offsetof(Brig::BrigInstImage,geometry), "bad alignment in Brig::BrigInstImage");
static_assert(offsetof(Brig::BrigInstImage, geometry)+sizeof(((Brig::BrigInstImage*)0)->geometry) == offsetof(Brig::BrigInstImage,equivClass), "bad alignment in Brig::BrigInstImage");
static_assert(offsetof(Brig::BrigInstImage, equivClass)+sizeof(((Brig::BrigInstImage*)0)->equivClass) == offsetof(Brig::BrigInstImage,reserved), "bad alignment in Brig::BrigInstImage");
static_assert(offsetof(Brig::BrigInstImage, reserved)+sizeof(((Brig::BrigInstImage*)0)->reserved) == sizeof(Brig::BrigInstImage), "bad alignment in Brig::BrigInstImage");

static_assert(offsetof(Brig::BrigInstLane, size) == 0, "bad alignment in Brig::BrigInstLane");
static_assert(offsetof(Brig::BrigInstLane, kind)+sizeof(((Brig::BrigInstLane*)0)->kind) == offsetof(Brig::BrigInstLane,opcode), "bad alignment in Brig::BrigInstLane");
static_assert(offsetof(Brig::BrigInstLane, opcode)+sizeof(((Brig::BrigInstLane*)0)->opcode) == offsetof(Brig::BrigInstLane,type), "bad alignment in Brig::BrigInstLane");
static_assert(offsetof(Brig::BrigInstLane, type)+sizeof(((Brig::BrigInstLane*)0)->type) == offsetof(Brig::BrigInstLane,operands), "bad alignment in Brig::BrigInstLane");
static_assert(offsetof(Brig::BrigInstLane, operands)+sizeof(((Brig::BrigInstLane*)0)->operands) == offsetof(Brig::BrigInstLane,sourceType), "bad alignment in Brig::BrigInstLane");
static_assert(offsetof(Brig::BrigInstLane, sourceType)+sizeof(((Brig::BrigInstLane*)0)->sourceType) == offsetof(Brig::BrigInstLane,width), "bad alignment in Brig::BrigInstLane");
static_assert(offsetof(Brig::BrigInstLane, width)+sizeof(((Brig::BrigInstLane*)0)->width) == offsetof(Brig::BrigInstLane,reserved), "bad alignment in Brig::BrigInstLane");
static_assert(offsetof(Brig::BrigInstLane, reserved)+sizeof(((Brig::BrigInstLane*)0)->reserved) == sizeof(Brig::BrigInstLane), "bad alignment in Brig::BrigInstLane");

static_assert(offsetof(Brig::BrigInstMem, size) == 0, "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, kind)+sizeof(((Brig::BrigInstMem*)0)->kind) == offsetof(Brig::BrigInstMem,opcode), "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, opcode)+sizeof(((Brig::BrigInstMem*)0)->opcode) == offsetof(Brig::BrigInstMem,type), "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, type)+sizeof(((Brig::BrigInstMem*)0)->type) == offsetof(Brig::BrigInstMem,operands), "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, operands)+sizeof(((Brig::BrigInstMem*)0)->operands) == offsetof(Brig::BrigInstMem,segment), "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, segment)+sizeof(((Brig::BrigInstMem*)0)->segment) == offsetof(Brig::BrigInstMem,align), "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, align)+sizeof(((Brig::BrigInstMem*)0)->align) == offsetof(Brig::BrigInstMem,equivClass), "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, equivClass)+sizeof(((Brig::BrigInstMem*)0)->equivClass) == offsetof(Brig::BrigInstMem,width), "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, width)+sizeof(((Brig::BrigInstMem*)0)->width) == offsetof(Brig::BrigInstMem,modifier), "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, modifier)+sizeof(((Brig::BrigInstMem*)0)->modifier) == offsetof(Brig::BrigInstMem,reserved), "bad alignment in Brig::BrigInstMem");
static_assert(offsetof(Brig::BrigInstMem, reserved)+sizeof(((Brig::BrigInstMem*)0)->reserved) == sizeof(Brig::BrigInstMem), "bad alignment in Brig::BrigInstMem");

static_assert(offsetof(Brig::BrigInstMemFence, size) == 0, "bad alignment in Brig::BrigInstMemFence");
static_assert(offsetof(Brig::BrigInstMemFence, kind)+sizeof(((Brig::BrigInstMemFence*)0)->kind) == offsetof(Brig::BrigInstMemFence,opcode), "bad alignment in Brig::BrigInstMemFence");
static_assert(offsetof(Brig::BrigInstMemFence, opcode)+sizeof(((Brig::BrigInstMemFence*)0)->opcode) == offsetof(Brig::BrigInstMemFence,type), "bad alignment in Brig::BrigInstMemFence");
static_assert(offsetof(Brig::BrigInstMemFence, type)+sizeof(((Brig::BrigInstMemFence*)0)->type) == offsetof(Brig::BrigInstMemFence,operands), "bad alignment in Brig::BrigInstMemFence");
static_assert(offsetof(Brig::BrigInstMemFence, operands)+sizeof(((Brig::BrigInstMemFence*)0)->operands) == offsetof(Brig::BrigInstMemFence,segments), "bad alignment in Brig::BrigInstMemFence");
static_assert(offsetof(Brig::BrigInstMemFence, segments)+sizeof(((Brig::BrigInstMemFence*)0)->segments) == offsetof(Brig::BrigInstMemFence,memoryOrder), "bad alignment in Brig::BrigInstMemFence");
static_assert(offsetof(Brig::BrigInstMemFence, memoryOrder)+sizeof(((Brig::BrigInstMemFence*)0)->memoryOrder) == offsetof(Brig::BrigInstMemFence,memoryScope), "bad alignment in Brig::BrigInstMemFence");
static_assert(offsetof(Brig::BrigInstMemFence, memoryScope)+sizeof(((Brig::BrigInstMemFence*)0)->memoryScope) == offsetof(Brig::BrigInstMemFence,reserved), "bad alignment in Brig::BrigInstMemFence");
static_assert(offsetof(Brig::BrigInstMemFence, reserved)+sizeof(((Brig::BrigInstMemFence*)0)->reserved) == sizeof(Brig::BrigInstMemFence), "bad alignment in Brig::BrigInstMemFence");

static_assert(offsetof(Brig::BrigInstMod, size) == 0, "bad alignment in Brig::BrigInstMod");
static_assert(offsetof(Brig::BrigInstMod, kind)+sizeof(((Brig::BrigInstMod*)0)->kind) == offsetof(Brig::BrigInstMod,opcode), "bad alignment in Brig::BrigInstMod");
static_assert(offsetof(Brig::BrigInstMod, opcode)+sizeof(((Brig::BrigInstMod*)0)->opcode) == offsetof(Brig::BrigInstMod,type), "bad alignment in Brig::BrigInstMod");
static_assert(offsetof(Brig::BrigInstMod, type)+sizeof(((Brig::BrigInstMod*)0)->type) == offsetof(Brig::BrigInstMod,operands), "bad alignment in Brig::BrigInstMod");
static_assert(offsetof(Brig::BrigInstMod, operands)+sizeof(((Brig::BrigInstMod*)0)->operands) == offsetof(Brig::BrigInstMod,modifier), "bad alignment in Brig::BrigInstMod");
static_assert(offsetof(Brig::BrigInstMod, modifier)+sizeof(((Brig::BrigInstMod*)0)->modifier) == offsetof(Brig::BrigInstMod,pack), "bad alignment in Brig::BrigInstMod");
static_assert(offsetof(Brig::BrigInstMod, pack)+sizeof(((Brig::BrigInstMod*)0)->pack) == offsetof(Brig::BrigInstMod,reserved), "bad alignment in Brig::BrigInstMod");
static_assert(offsetof(Brig::BrigInstMod, reserved)+sizeof(((Brig::BrigInstMod*)0)->reserved) == sizeof(Brig::BrigInstMod), "bad alignment in Brig::BrigInstMod");

static_assert(offsetof(Brig::BrigInstQueue, size) == 0, "bad alignment in Brig::BrigInstQueue");
static_assert(offsetof(Brig::BrigInstQueue, kind)+sizeof(((Brig::BrigInstQueue*)0)->kind) == offsetof(Brig::BrigInstQueue,opcode), "bad alignment in Brig::BrigInstQueue");
static_assert(offsetof(Brig::BrigInstQueue, opcode)+sizeof(((Brig::BrigInstQueue*)0)->opcode) == offsetof(Brig::BrigInstQueue,type), "bad alignment in Brig::BrigInstQueue");
static_assert(offsetof(Brig::BrigInstQueue, type)+sizeof(((Brig::BrigInstQueue*)0)->type) == offsetof(Brig::BrigInstQueue,operands), "bad alignment in Brig::BrigInstQueue");
static_assert(offsetof(Brig::BrigInstQueue, operands)+sizeof(((Brig::BrigInstQueue*)0)->operands) == offsetof(Brig::BrigInstQueue,segment), "bad alignment in Brig::BrigInstQueue");
static_assert(offsetof(Brig::BrigInstQueue, segment)+sizeof(((Brig::BrigInstQueue*)0)->segment) == offsetof(Brig::BrigInstQueue,memoryOrder), "bad alignment in Brig::BrigInstQueue");
static_assert(offsetof(Brig::BrigInstQueue, memoryOrder)+sizeof(((Brig::BrigInstQueue*)0)->memoryOrder) == offsetof(Brig::BrigInstQueue,reserved), "bad alignment in Brig::BrigInstQueue");
static_assert(offsetof(Brig::BrigInstQueue, reserved)+sizeof(((Brig::BrigInstQueue*)0)->reserved) == sizeof(Brig::BrigInstQueue), "bad alignment in Brig::BrigInstQueue");

static_assert(offsetof(Brig::BrigInstSeg, size) == 0, "bad alignment in Brig::BrigInstSeg");
static_assert(offsetof(Brig::BrigInstSeg, kind)+sizeof(((Brig::BrigInstSeg*)0)->kind) == offsetof(Brig::BrigInstSeg,opcode), "bad alignment in Brig::BrigInstSeg");
static_assert(offsetof(Brig::BrigInstSeg, opcode)+sizeof(((Brig::BrigInstSeg*)0)->opcode) == offsetof(Brig::BrigInstSeg,type), "bad alignment in Brig::BrigInstSeg");
static_assert(offsetof(Brig::BrigInstSeg, type)+sizeof(((Brig::BrigInstSeg*)0)->type) == offsetof(Brig::BrigInstSeg,operands), "bad alignment in Brig::BrigInstSeg");
static_assert(offsetof(Brig::BrigInstSeg, operands)+sizeof(((Brig::BrigInstSeg*)0)->operands) == offsetof(Brig::BrigInstSeg,segment), "bad alignment in Brig::BrigInstSeg");
static_assert(offsetof(Brig::BrigInstSeg, segment)+sizeof(((Brig::BrigInstSeg*)0)->segment) == offsetof(Brig::BrigInstSeg,reserved), "bad alignment in Brig::BrigInstSeg");
static_assert(offsetof(Brig::BrigInstSeg, reserved)+sizeof(((Brig::BrigInstSeg*)0)->reserved) == sizeof(Brig::BrigInstSeg), "bad alignment in Brig::BrigInstSeg");

static_assert(offsetof(Brig::BrigInstSegCvt, size) == 0, "bad alignment in Brig::BrigInstSegCvt");
static_assert(offsetof(Brig::BrigInstSegCvt, kind)+sizeof(((Brig::BrigInstSegCvt*)0)->kind) == offsetof(Brig::BrigInstSegCvt,opcode), "bad alignment in Brig::BrigInstSegCvt");
static_assert(offsetof(Brig::BrigInstSegCvt, opcode)+sizeof(((Brig::BrigInstSegCvt*)0)->opcode) == offsetof(Brig::BrigInstSegCvt,type), "bad alignment in Brig::BrigInstSegCvt");
static_assert(offsetof(Brig::BrigInstSegCvt, type)+sizeof(((Brig::BrigInstSegCvt*)0)->type) == offsetof(Brig::BrigInstSegCvt,operands), "bad alignment in Brig::BrigInstSegCvt");
static_assert(offsetof(Brig::BrigInstSegCvt, operands)+sizeof(((Brig::BrigInstSegCvt*)0)->operands) == offsetof(Brig::BrigInstSegCvt,sourceType), "bad alignment in Brig::BrigInstSegCvt");
static_assert(offsetof(Brig::BrigInstSegCvt, sourceType)+sizeof(((Brig::BrigInstSegCvt*)0)->sourceType) == offsetof(Brig::BrigInstSegCvt,segment), "bad alignment in Brig::BrigInstSegCvt");
static_assert(offsetof(Brig::BrigInstSegCvt, segment)+sizeof(((Brig::BrigInstSegCvt*)0)->segment) == offsetof(Brig::BrigInstSegCvt,modifier), "bad alignment in Brig::BrigInstSegCvt");
static_assert(offsetof(Brig::BrigInstSegCvt, modifier)+sizeof(((Brig::BrigInstSegCvt*)0)->modifier) == sizeof(Brig::BrigInstSegCvt), "bad alignment in Brig::BrigInstSegCvt");

static_assert(offsetof(Brig::BrigInstSignal, size) == 0, "bad alignment in Brig::BrigInstSignal");
static_assert(offsetof(Brig::BrigInstSignal, kind)+sizeof(((Brig::BrigInstSignal*)0)->kind) == offsetof(Brig::BrigInstSignal,opcode), "bad alignment in Brig::BrigInstSignal");
static_assert(offsetof(Brig::BrigInstSignal, opcode)+sizeof(((Brig::BrigInstSignal*)0)->opcode) == offsetof(Brig::BrigInstSignal,type), "bad alignment in Brig::BrigInstSignal");
static_assert(offsetof(Brig::BrigInstSignal, type)+sizeof(((Brig::BrigInstSignal*)0)->type) == offsetof(Brig::BrigInstSignal,operands), "bad alignment in Brig::BrigInstSignal");
static_assert(offsetof(Brig::BrigInstSignal, operands)+sizeof(((Brig::BrigInstSignal*)0)->operands) == offsetof(Brig::BrigInstSignal,signalType), "bad alignment in Brig::BrigInstSignal");
static_assert(offsetof(Brig::BrigInstSignal, signalType)+sizeof(((Brig::BrigInstSignal*)0)->signalType) == offsetof(Brig::BrigInstSignal,memoryOrder), "bad alignment in Brig::BrigInstSignal");
static_assert(offsetof(Brig::BrigInstSignal, memoryOrder)+sizeof(((Brig::BrigInstSignal*)0)->memoryOrder) == offsetof(Brig::BrigInstSignal,signalOperation), "bad alignment in Brig::BrigInstSignal");
static_assert(offsetof(Brig::BrigInstSignal, signalOperation)+sizeof(((Brig::BrigInstSignal*)0)->signalOperation) == sizeof(Brig::BrigInstSignal), "bad alignment in Brig::BrigInstSignal");

static_assert(offsetof(Brig::BrigInstSourceType, size) == 0, "bad alignment in Brig::BrigInstSourceType");
static_assert(offsetof(Brig::BrigInstSourceType, kind)+sizeof(((Brig::BrigInstSourceType*)0)->kind) == offsetof(Brig::BrigInstSourceType,opcode), "bad alignment in Brig::BrigInstSourceType");
static_assert(offsetof(Brig::BrigInstSourceType, opcode)+sizeof(((Brig::BrigInstSourceType*)0)->opcode) == offsetof(Brig::BrigInstSourceType,type), "bad alignment in Brig::BrigInstSourceType");
static_assert(offsetof(Brig::BrigInstSourceType, type)+sizeof(((Brig::BrigInstSourceType*)0)->type) == offsetof(Brig::BrigInstSourceType,operands), "bad alignment in Brig::BrigInstSourceType");
static_assert(offsetof(Brig::BrigInstSourceType, operands)+sizeof(((Brig::BrigInstSourceType*)0)->operands) == offsetof(Brig::BrigInstSourceType,sourceType), "bad alignment in Brig::BrigInstSourceType");
static_assert(offsetof(Brig::BrigInstSourceType, sourceType)+sizeof(((Brig::BrigInstSourceType*)0)->sourceType) == offsetof(Brig::BrigInstSourceType,reserved), "bad alignment in Brig::BrigInstSourceType");
static_assert(offsetof(Brig::BrigInstSourceType, reserved)+sizeof(((Brig::BrigInstSourceType*)0)->reserved) == sizeof(Brig::BrigInstSourceType), "bad alignment in Brig::BrigInstSourceType");

static_assert(offsetof(Brig::BrigInstNone, size) == 0, "bad alignment in Brig::BrigInstNone");
static_assert(offsetof(Brig::BrigInstNone, kind)+sizeof(((Brig::BrigInstNone*)0)->kind) == sizeof(Brig::BrigInstNone), "bad alignment in Brig::BrigInstNone");

static_assert(offsetof(Brig::BrigMemoryModifier, allBits) == 0, "bad alignment in Brig::BrigMemoryModifier");
static_assert(offsetof(Brig::BrigMemoryModifier, allBits)+sizeof(((Brig::BrigMemoryModifier*)0)->allBits) == sizeof(Brig::BrigMemoryModifier), "bad alignment in Brig::BrigMemoryModifier");

static_assert(offsetof(Brig::BrigOperand, size) == 0, "bad alignment in Brig::BrigOperand");
static_assert(offsetof(Brig::BrigOperand, kind)+sizeof(((Brig::BrigOperand*)0)->kind) == sizeof(Brig::BrigOperand), "bad alignment in Brig::BrigOperand");

static_assert(offsetof(Brig::BrigOperandAddress, size) == 0, "bad alignment in Brig::BrigOperandAddress");
static_assert(offsetof(Brig::BrigOperandAddress, kind)+sizeof(((Brig::BrigOperandAddress*)0)->kind) == offsetof(Brig::BrigOperandAddress,symbol), "bad alignment in Brig::BrigOperandAddress");
static_assert(offsetof(Brig::BrigOperandAddress, symbol)+sizeof(((Brig::BrigOperandAddress*)0)->symbol) == offsetof(Brig::BrigOperandAddress,reg), "bad alignment in Brig::BrigOperandAddress");
static_assert(offsetof(Brig::BrigOperandAddress, reg)+sizeof(((Brig::BrigOperandAddress*)0)->reg) == offsetof(Brig::BrigOperandAddress,offsetLo), "bad alignment in Brig::BrigOperandAddress");
static_assert(offsetof(Brig::BrigOperandAddress, offsetLo)+sizeof(((Brig::BrigOperandAddress*)0)->offsetLo) == offsetof(Brig::BrigOperandAddress,offsetHi), "bad alignment in Brig::BrigOperandAddress");
static_assert(offsetof(Brig::BrigOperandAddress, offsetHi)+sizeof(((Brig::BrigOperandAddress*)0)->offsetHi) == sizeof(Brig::BrigOperandAddress), "bad alignment in Brig::BrigOperandAddress");

static_assert(offsetof(Brig::BrigOperandImmed, size) == 0, "bad alignment in Brig::BrigOperandImmed");
static_assert(offsetof(Brig::BrigOperandImmed, kind)+sizeof(((Brig::BrigOperandImmed*)0)->kind) == offsetof(Brig::BrigOperandImmed,reserved), "bad alignment in Brig::BrigOperandImmed");
static_assert(offsetof(Brig::BrigOperandImmed, reserved)+sizeof(((Brig::BrigOperandImmed*)0)->reserved) == offsetof(Brig::BrigOperandImmed,byteCount), "bad alignment in Brig::BrigOperandImmed");

static_assert(offsetof(Brig::BrigOperandList, size) == 0, "bad alignment in Brig::BrigOperandList");
static_assert(offsetof(Brig::BrigOperandList, kind)+sizeof(((Brig::BrigOperandList*)0)->kind) == offsetof(Brig::BrigOperandList,reserved), "bad alignment in Brig::BrigOperandList");
static_assert(offsetof(Brig::BrigOperandList, reserved)+sizeof(((Brig::BrigOperandList*)0)->reserved) == offsetof(Brig::BrigOperandList,elementCount), "bad alignment in Brig::BrigOperandList");
static_assert(offsetof(Brig::BrigOperandList, elementCount)+sizeof(((Brig::BrigOperandList*)0)->elementCount) == offsetof(Brig::BrigOperandList,elements), "bad alignment in Brig::BrigOperandList");
static_assert(offsetof(Brig::BrigOperandList, elements)+sizeof(((Brig::BrigOperandList*)0)->elements) == sizeof(Brig::BrigOperandList), "bad alignment in Brig::BrigOperandList");

static_assert(offsetof(Brig::BrigOperandArgumentList, size) == 0, "bad alignment in Brig::BrigOperandArgumentList");
static_assert(offsetof(Brig::BrigOperandArgumentList, kind)+sizeof(((Brig::BrigOperandArgumentList*)0)->kind) == offsetof(Brig::BrigOperandArgumentList,reserved), "bad alignment in Brig::BrigOperandArgumentList");
static_assert(offsetof(Brig::BrigOperandArgumentList, reserved)+sizeof(((Brig::BrigOperandArgumentList*)0)->reserved) == offsetof(Brig::BrigOperandArgumentList,elementCount), "bad alignment in Brig::BrigOperandArgumentList");
static_assert(offsetof(Brig::BrigOperandArgumentList, elementCount)+sizeof(((Brig::BrigOperandArgumentList*)0)->elementCount) == offsetof(Brig::BrigOperandArgumentList,elements), "bad alignment in Brig::BrigOperandArgumentList");
static_assert(offsetof(Brig::BrigOperandArgumentList, elements)+sizeof(((Brig::BrigOperandArgumentList*)0)->elements) == sizeof(Brig::BrigOperandArgumentList), "bad alignment in Brig::BrigOperandArgumentList");

static_assert(offsetof(Brig::BrigOperandFunctionList, size) == 0, "bad alignment in Brig::BrigOperandFunctionList");
static_assert(offsetof(Brig::BrigOperandFunctionList, kind)+sizeof(((Brig::BrigOperandFunctionList*)0)->kind) == offsetof(Brig::BrigOperandFunctionList,reserved), "bad alignment in Brig::BrigOperandFunctionList");
static_assert(offsetof(Brig::BrigOperandFunctionList, reserved)+sizeof(((Brig::BrigOperandFunctionList*)0)->reserved) == offsetof(Brig::BrigOperandFunctionList,elementCount), "bad alignment in Brig::BrigOperandFunctionList");
static_assert(offsetof(Brig::BrigOperandFunctionList, elementCount)+sizeof(((Brig::BrigOperandFunctionList*)0)->elementCount) == offsetof(Brig::BrigOperandFunctionList,elements), "bad alignment in Brig::BrigOperandFunctionList");
static_assert(offsetof(Brig::BrigOperandFunctionList, elements)+sizeof(((Brig::BrigOperandFunctionList*)0)->elements) == sizeof(Brig::BrigOperandFunctionList), "bad alignment in Brig::BrigOperandFunctionList");

static_assert(offsetof(Brig::BrigOperandRef, size) == 0, "bad alignment in Brig::BrigOperandRef");
static_assert(offsetof(Brig::BrigOperandRef, kind)+sizeof(((Brig::BrigOperandRef*)0)->kind) == offsetof(Brig::BrigOperandRef,ref), "bad alignment in Brig::BrigOperandRef");
static_assert(offsetof(Brig::BrigOperandRef, ref)+sizeof(((Brig::BrigOperandRef*)0)->ref) == sizeof(Brig::BrigOperandRef), "bad alignment in Brig::BrigOperandRef");

static_assert(offsetof(Brig::BrigOperandFbarrierRef, size) == 0, "bad alignment in Brig::BrigOperandFbarrierRef");
static_assert(offsetof(Brig::BrigOperandFbarrierRef, kind)+sizeof(((Brig::BrigOperandFbarrierRef*)0)->kind) == offsetof(Brig::BrigOperandFbarrierRef,ref), "bad alignment in Brig::BrigOperandFbarrierRef");
static_assert(offsetof(Brig::BrigOperandFbarrierRef, ref)+sizeof(((Brig::BrigOperandFbarrierRef*)0)->ref) == sizeof(Brig::BrigOperandFbarrierRef), "bad alignment in Brig::BrigOperandFbarrierRef");

static_assert(offsetof(Brig::BrigOperandFunctionRef, size) == 0, "bad alignment in Brig::BrigOperandFunctionRef");
static_assert(offsetof(Brig::BrigOperandFunctionRef, kind)+sizeof(((Brig::BrigOperandFunctionRef*)0)->kind) == offsetof(Brig::BrigOperandFunctionRef,ref), "bad alignment in Brig::BrigOperandFunctionRef");
static_assert(offsetof(Brig::BrigOperandFunctionRef, ref)+sizeof(((Brig::BrigOperandFunctionRef*)0)->ref) == sizeof(Brig::BrigOperandFunctionRef), "bad alignment in Brig::BrigOperandFunctionRef");

static_assert(offsetof(Brig::BrigOperandLabelRef, size) == 0, "bad alignment in Brig::BrigOperandLabelRef");
static_assert(offsetof(Brig::BrigOperandLabelRef, kind)+sizeof(((Brig::BrigOperandLabelRef*)0)->kind) == offsetof(Brig::BrigOperandLabelRef,label), "bad alignment in Brig::BrigOperandLabelRef");
static_assert(offsetof(Brig::BrigOperandLabelRef, label)+sizeof(((Brig::BrigOperandLabelRef*)0)->label) == sizeof(Brig::BrigOperandLabelRef), "bad alignment in Brig::BrigOperandLabelRef");

static_assert(offsetof(Brig::BrigOperandLabelTargetsRef, size) == 0, "bad alignment in Brig::BrigOperandLabelTargetsRef");
static_assert(offsetof(Brig::BrigOperandLabelTargetsRef, kind)+sizeof(((Brig::BrigOperandLabelTargetsRef*)0)->kind) == offsetof(Brig::BrigOperandLabelTargetsRef,targets), "bad alignment in Brig::BrigOperandLabelTargetsRef");
static_assert(offsetof(Brig::BrigOperandLabelTargetsRef, targets)+sizeof(((Brig::BrigOperandLabelTargetsRef*)0)->targets) == sizeof(Brig::BrigOperandLabelTargetsRef), "bad alignment in Brig::BrigOperandLabelTargetsRef");

static_assert(offsetof(Brig::BrigOperandLabelVariableRef, size) == 0, "bad alignment in Brig::BrigOperandLabelVariableRef");
static_assert(offsetof(Brig::BrigOperandLabelVariableRef, kind)+sizeof(((Brig::BrigOperandLabelVariableRef*)0)->kind) == offsetof(Brig::BrigOperandLabelVariableRef,symbol), "bad alignment in Brig::BrigOperandLabelVariableRef");
static_assert(offsetof(Brig::BrigOperandLabelVariableRef, symbol)+sizeof(((Brig::BrigOperandLabelVariableRef*)0)->symbol) == sizeof(Brig::BrigOperandLabelVariableRef), "bad alignment in Brig::BrigOperandLabelVariableRef");

static_assert(offsetof(Brig::BrigOperandSignatureRef, size) == 0, "bad alignment in Brig::BrigOperandSignatureRef");
static_assert(offsetof(Brig::BrigOperandSignatureRef, kind)+sizeof(((Brig::BrigOperandSignatureRef*)0)->kind) == offsetof(Brig::BrigOperandSignatureRef,ref), "bad alignment in Brig::BrigOperandSignatureRef");
static_assert(offsetof(Brig::BrigOperandSignatureRef, ref)+sizeof(((Brig::BrigOperandSignatureRef*)0)->ref) == sizeof(Brig::BrigOperandSignatureRef), "bad alignment in Brig::BrigOperandSignatureRef");

static_assert(offsetof(Brig::BrigOperandReg, size) == 0, "bad alignment in Brig::BrigOperandReg");
static_assert(offsetof(Brig::BrigOperandReg, kind)+sizeof(((Brig::BrigOperandReg*)0)->kind) == offsetof(Brig::BrigOperandReg,reg), "bad alignment in Brig::BrigOperandReg");
static_assert(offsetof(Brig::BrigOperandReg, reg)+sizeof(((Brig::BrigOperandReg*)0)->reg) == sizeof(Brig::BrigOperandReg), "bad alignment in Brig::BrigOperandReg");

static_assert(offsetof(Brig::BrigOperandRegVector, size) == 0, "bad alignment in Brig::BrigOperandRegVector");
static_assert(offsetof(Brig::BrigOperandRegVector, kind)+sizeof(((Brig::BrigOperandRegVector*)0)->kind) == offsetof(Brig::BrigOperandRegVector,reserved), "bad alignment in Brig::BrigOperandRegVector");
static_assert(offsetof(Brig::BrigOperandRegVector, reserved)+sizeof(((Brig::BrigOperandRegVector*)0)->reserved) == offsetof(Brig::BrigOperandRegVector,regCount), "bad alignment in Brig::BrigOperandRegVector");
static_assert(offsetof(Brig::BrigOperandRegVector, regCount)+sizeof(((Brig::BrigOperandRegVector*)0)->regCount) == offsetof(Brig::BrigOperandRegVector,regs), "bad alignment in Brig::BrigOperandRegVector");
static_assert(offsetof(Brig::BrigOperandRegVector, regs)+sizeof(((Brig::BrigOperandRegVector*)0)->regs) == sizeof(Brig::BrigOperandRegVector), "bad alignment in Brig::BrigOperandRegVector");

static_assert(offsetof(Brig::BrigOperandWavesize, size) == 0, "bad alignment in Brig::BrigOperandWavesize");
static_assert(offsetof(Brig::BrigOperandWavesize, kind)+sizeof(((Brig::BrigOperandWavesize*)0)->kind) == sizeof(Brig::BrigOperandWavesize), "bad alignment in Brig::BrigOperandWavesize");

static_assert(offsetof(Brig::BrigSamplerModifier, allBits) == 0, "bad alignment in Brig::BrigSamplerModifier");
static_assert(offsetof(Brig::BrigSamplerModifier, allBits)+sizeof(((Brig::BrigSamplerModifier*)0)->allBits) == sizeof(Brig::BrigSamplerModifier), "bad alignment in Brig::BrigSamplerModifier");

static_assert(offsetof(Brig::BrigSegCvtModifier, allBits) == 0, "bad alignment in Brig::BrigSegCvtModifier");
static_assert(offsetof(Brig::BrigSegCvtModifier, allBits)+sizeof(((Brig::BrigSegCvtModifier*)0)->allBits) == sizeof(Brig::BrigSegCvtModifier), "bad alignment in Brig::BrigSegCvtModifier");

static_assert(offsetof(Brig::BrigSymbolModifier, allBits) == 0, "bad alignment in Brig::BrigSymbolModifier");
static_assert(offsetof(Brig::BrigSymbolModifier, allBits)+sizeof(((Brig::BrigSymbolModifier*)0)->allBits) == sizeof(Brig::BrigSymbolModifier), "bad alignment in Brig::BrigSymbolModifier");

