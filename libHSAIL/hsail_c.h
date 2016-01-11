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

#ifndef __BRIG_C_API_H__
#define __BRIG_C_API_H__

#ifdef LIBHSAIL_DLL
#define HSAIL_C_API __declspec(dllimport)
#else
#define HSAIL_C_API
#endif

/**
 * @file hsail_c.h
 * HSAIL C API
 */

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Opaque BRIG container struct.
 */
struct brig_container_struct;

/**
 * BRIG container handle.
 */
typedef struct brig_container_struct* brig_container_t;

/**
 * Offset in BRIG code section
 */
typedef uint32_t brig_code_section_offset;

/**
 * Create an empty BRIG cointainer.
 *
 * @return - BRIG container handle.
 */
HSAIL_C_API brig_container_t brig_container_create_empty();

/**
 * Create an BRIG cointainer with the specified used-owned data.
 *
 * @param data_bytes - pointer to data section.
 * @param data_size - data section size in bytes.
 * @param code_bytes - pointer to code section.
 * @param code_size - code section size in bytes.
 * @param operand_bytes - pointer to operand section.
 * @param operand_size - operand section size in bytes.
 * @param debug_bytes - pointer to debug section. May be null.
 * @param debug_size - string section size in bytes.
 *
 * @return - BRIG container handle.
 */
HSAIL_C_API brig_container_t brig_container_create_view(const void *brig_module, size_t size);

/**
 * Create an BRIG cointainer with a copy of the specified data which
 * will be managed by this container.
 *
 * @param data_bytes - pointer to data section.
 * @param data_size - data section size in bytes.
 * @param code_bytes - pointer to code section.
 * @param code_size - code section size in bytes.
 * @param operand_bytes - pointer to operand section.
 * @param operand_size - operand section size in bytes.
 * @param debug_bytes - pointer to debug section. May be null.
 * @param debug_size - string section size in bytes.
 *
 * @return - BRIG container handle. *
 * @return - BRIG container handle.
 */
HSAIL_C_API brig_container_t brig_container_create_copy(const void* brig_module, size_t size);

/**
 * Obtain the section count for a BRIG container.
 *
 * @param handle - BRIG container handle
 *
 * @return - section count
 */
HSAIL_C_API unsigned brig_container_get_section_count(brig_container_t handle);

/**
 * Obtain the data of a section of a BRIG container.
 *
 * @param handle - BRIG container handle
 * @param section_id - section ID.
 *
 * @return - pointer to BRIG section data.
 */
HSAIL_C_API const char* brig_container_get_section_bytes(brig_container_t handle, int section_id);

/**
 * Obtain the size of a section of a BRIG container.
 *
 * @param handle - BRIG container handle
 * @param section_id - section ID.
 *
 * @return - section size in bytes.
 */
HSAIL_C_API size_t      brig_container_get_section_size(brig_container_t handle, int section_id);

/**
 * Assemble HSAIL text from memory buffer and store it in a BRIG container.
 *
 * @param handle - BRIG container handle.
 * @param text - pointer to HSAIL text in memory (does not have to be null terminated).
 * @param text_length - length of the HSAIL text in bytes.
 *
 * @return zero on success, or a non-zero error code on failure. Use brig_container_get_error_text() to receive further error info.
 */
HSAIL_C_API int         brig_container_assemble_from_memory(brig_container_t handle, const char* text, size_t text_length, const char *options);

/**
 * Assemble HSAIL text from a file and store it in a BRIG container.
 *
 * @param handle - BRIG container handle.
 * @param filename - name of the file containing HSAIL text.
 *
 * @return zero on success, or a non-zero error code on failure. Use brig_container_get_error_text() to receive further error info.
 */
HSAIL_C_API int         brig_container_assemble_from_file(brig_container_t handle, const char* filename, const char *options);

/**
 * Disassemble a BRIG container and save HSAIL text to a file.
 *
 * @param handle - BRIG container handle.
 * @param filename - name of the file where HSAIL text will be saved.
 *
 * @return zero on success, or a non-zero error code on failure. Use brig_container_get_error_text() to receive further error info.
 */
HSAIL_C_API int         brig_container_disassemble_to_file(brig_container_t handle, const char* filename);

/**
 * Load a BRIG container from an ELF memory buffer (.brig or .bif).
 *
 * @param handle - BRIG container handle.
 * @param elf_bytes - pointer to the ELF memory buffer.
 * @param elf_length - length of the ELF data in bytes
 *
 * @return zero on success, or a non-zero error code on failure. Use brig_container_get_error_text() to receive further error info.
 */
HSAIL_C_API int         brig_container_load_from_mem(brig_container_t handle, const char* elf_bytes, size_t elf_length);

/**
 * Load a BRIG container from an ELF file (.brig or .bif).
 *
 * @param handle - BRIG container handle.
 * @param filename - name of the ELF file
 *
 * @return zero on success, or a non-zero error code on failure. Use brig_container_get_error_text() to receive further error info.
 */
HSAIL_C_API int         brig_container_load_from_file(brig_container_t handle, const char* filename);

/**
 * Save a BRIG container into an ELF file (32-bit .brig).
 *
 * @param handle - BRIG container handle.
 * @param filename - name of the ELF file
 *
 * @return zero on success, or a non-zero error code on failure. Use brig_container_get_error_text() to receive further error info.
 */
HSAIL_C_API int         brig_container_save_to_file(brig_container_t handle, const char* filename);

/**
 * Validate a program in a BRIG container.
 *
 * @param handle - BRIG container handle.
 *
 * @return zero if the program is valid, or a non-zero error code otherwise. Use brig_container_get_error_text() to receive further info on invalid BRIG.
 */
HSAIL_C_API int         brig_container_validate(brig_container_t handle);

/**
 * Obtain a pointer to BrigModule corresponding to this container (as void*)
 *
 * The container cannot be modified after this function is called and
 * it owns the module, so the pointer is only valid until brig_container_destroy.
 *
 * @param handle - BRIG container handle.
 *
 * @return - the pointer to BrigModuleHeader.
 */
HSAIL_C_API void* brig_container_get_brig_module(brig_container_t handle);

/**
  *
  */
HSAIL_C_API brig_code_section_offset brig_container_find_code_module_symbol_offset(brig_container_t handle, const char *symbol_name);

/**
 * Obtain error message text.
 *
 * @param handle - BRIG container handle.
 *
 * @return - the most recent error message produced by libHSAIL C API functions operating on the specified container.
 */
HSAIL_C_API const char* brig_container_get_error_text(brig_container_t handle);

/**
 * Destroy the specified BRIG container.
 *
 * @param handle - BRIG container handle.
 */
HSAIL_C_API void        brig_container_destroy(brig_container_t handle);

#ifdef __cplusplus
}
#endif

#endif // __BRIG_C_API_H__
