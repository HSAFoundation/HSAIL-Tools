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

#include "hsail_c.h"
#include "HSAILTool.h"

using namespace HSAIL_ASM;

extern "C" {

HSAIL_C_API brig_container_t brig_container_create_empty()
{
    return (brig_container_t) new Tool();
}

HSAIL_C_API brig_container_t brig_container_create_view(const void *brig_module, size_t size)
{
    return (brig_container_t) new Tool(brig_module, size);
}

HSAIL_C_API brig_container_t brig_container_create_copy(const void *brig_module, size_t size)
{
    return (brig_container_t) new Tool(brig_module, size, true);
}

static Tool* T(brig_container_t handle) { return (Tool*) handle; }

static int resultFrom(bool result) { return !result; }

HSAIL_C_API void* brig_container_get_brig_module(brig_container_t handle)
{
    return T(handle)->brigModule();
}

HSAIL_C_API unsigned brig_container_get_section_count(brig_container_t handle)
{
    return T(handle)->numSections();
}

HSAIL_C_API const char* brig_container_get_section_bytes(brig_container_t handle, int section_id)
{
    return T(handle)->sectionBytesById(section_id);
}

HSAIL_C_API size_t brig_container_get_section_size(brig_container_t handle, int section_id)
{
    return T(handle)->sectionSizeById(section_id);
}

HSAIL_C_API int brig_container_assemble_from_memory(brig_container_t handle, const char* text, size_t text_length, const char *options)
{
    return resultFrom(T(handle)->assembleFromMemory(text, text_length, options));
}

HSAIL_C_API int brig_container_assemble_from_file(brig_container_t handle, const char* filename, const char *options)
{
    return resultFrom(T(handle)->assembleFromFile(filename, options));
}

HSAIL_C_API int brig_container_disassemble_to_file(brig_container_t handle, const char* filename)
{
    return resultFrom(T(handle)->disassembleToFile(filename));
}

HSAIL_C_API int brig_container_load_from_mem(brig_container_t handle, const char* buf, size_t buf_length)
{
    return resultFrom(T(handle)->loadFromMem(buf, buf_length));
}

HSAIL_C_API int brig_container_load_from_file(brig_container_t handle, const char* filename)
{
    return resultFrom(T(handle)->loadFromFile(filename));
}

HSAIL_C_API int brig_container_save_to_file(brig_container_t handle, const char* filename)
{
    return resultFrom(T(handle)->saveToFile(filename));
}

HSAIL_C_API int brig_container_validate(brig_container_t handle)
{
    return resultFrom(T(handle)->validate());
}

HSAIL_C_API brig_code_section_offset brig_container_find_code_module_symbol_offset(brig_container_t handle, const char *symbol_name)
{
  return T(handle)->findCodeModuleSymbolOffset(symbol_name);
}

HSAIL_C_API const char* brig_container_get_error_text(brig_container_t handle)
{
    return T(handle)->output().c_str();
}

HSAIL_C_API void brig_container_destroy(brig_container_t handle)
{
    delete T(handle);
}

}
