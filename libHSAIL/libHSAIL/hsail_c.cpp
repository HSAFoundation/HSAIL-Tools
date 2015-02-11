#include "hsail_c.h"
#include <fstream>
#include <sstream>
#include "HSAILBrigContainer.h"
#include "HSAILBrigObjectFile.h"
#include "HSAILParser.h"
#include "HSAILDisassembler.h"
#include "HSAILValidator.h"

using namespace HSAIL_ASM;

namespace {

struct Api {
    BrigContainer   container;
    std::string     errorText;

    Api()
    : container()
    , errorText()
    {
    }

    Api(const void *data_bytes,
        const void *code_bytes,
        const void *operand_bytes,
        const void * debug_bytes)
    : container(
            data_bytes,
            code_bytes,
            operand_bytes,
            debug_bytes)
    , errorText()
    {
    }
};

static int assemble(brig_container_t handle, std::istream& is)
{
    try {
        Scanner s(is, true);
        Parser p(s, ((Api*)handle)->container);
        p.parseSource();
    }
    catch(const SyntaxError& e) {
        std::stringstream ss;
        e.print(ss, is);
        ((Api*)handle)->errorText = ss.str();
        return 1;
    }
    Validator v(((Api*)handle)->container);
    if (!v.validate(true)) {
        std::stringstream ss;
        ss << v.getErrorMsg(&is) << "\n";
        int rc = v.getErrorCode();
        ((Api*)handle)->errorText = ss.str();
        return rc;
    }
    return 0;
}

}

extern "C" {

HSAIL_C_API brig_container_t brig_container_create_empty()
{
    return (brig_container_t)new Api();
}

HSAIL_C_API brig_container_t brig_container_create_view(
    const void *data_bytes,
    const void *code_bytes,
    const void *operand_bytes,
    const void* debug_bytes)
{
    return (brig_container_t)new Api(
            data_bytes,
            code_bytes,
            operand_bytes,
            debug_bytes);
}

HSAIL_C_API brig_container_t brig_container_create_copy(
                            const char *data_bytes,
                            const char *code_bytes,
                            const char *operand_bytes,
                            const char* debug_bytes)
{
  Api *api = new Api;
  api->container.strings().setData(data_bytes);
  api->container.code().setData(code_bytes);
  api->container.operands().setData(operand_bytes);
  if (debug_bytes) { api->container.debugInfo().setData(debug_bytes); }
  return (brig_container_t)api;
}

HSAIL_C_API void* brig_container_get_brig_module(brig_container_t handle)
{
    return (void*)(((Api*)handle)->container.getBrigModule());
}

HSAIL_C_API unsigned brig_container_get_section_count(brig_container_t handle)
{
    return (unsigned)(((Api*)handle)->container.getNumSections());
}

HSAIL_C_API const char* brig_container_get_section_bytes(brig_container_t handle, int section_id)
{
    return ((Api*)handle)->container.sectionById(section_id).data().begin;
}

HSAIL_C_API size_t brig_container_get_section_size(brig_container_t handle, int section_id)
{
    return ((Api*)handle)->container.sectionById(section_id).size();
}

HSAIL_C_API int brig_container_assemble_from_memory(brig_container_t handle, const char* text, size_t text_length)
{
    std::string s((char*)text, text_length);
    std::istringstream is(s);
    return assemble(handle, is);
}

HSAIL_C_API int brig_container_assemble_from_file(brig_container_t handle, const char* filename)
{
    std::ifstream ifs(filename, std::ifstream::in | std::ifstream::binary);
    std::stringstream ss;
    if ((!ifs.is_open()) || ifs.bad()) {
        ss << "Could not open "<< filename;
        ((Api*)handle)->errorText = ss.str();
        return 1;
    }
    return assemble(handle, ifs);
}

HSAIL_C_API int brig_container_disassemble_to_file(brig_container_t handle, const char* filename)
{
    Disassembler d(((Api*)handle)->container);
    d.setOutputOptions(0);
    std::stringstream ss;
    d.log(ss);
    int rc = d.run(filename);
    ((Api*)handle)->errorText = ss.str();
    return rc;
}

HSAIL_C_API int brig_container_load_from_mem(brig_container_t handle, const char* buf, size_t buf_length)
{
    std::stringstream ss;
    int rc = BrigIO::load(((Api*)handle)->container, FILE_FORMAT_AUTO, BrigIO::memoryReadingAdapter(buf, buf_length, ss));
    ((Api*)handle)->errorText = ss.str();
    return rc;
}

HSAIL_C_API int brig_container_load_from_file(brig_container_t handle, const char* filename)
{
    std::stringstream ss;
    int rc = BrigIO::load(((Api*)handle)->container, FILE_FORMAT_AUTO, BrigIO::fileReadingAdapter(filename, ss));
    ((Api*)handle)->errorText = ss.str();
    return rc;
}

HSAIL_C_API int brig_container_save_to_file(brig_container_t handle, const char* filename)
{
    std::stringstream ss;
    int rc = BrigIO::save(((Api*)handle)->container, FILE_FORMAT_BRIG | FILE_FORMAT_ELF32, BrigIO::fileWritingAdapter(filename, ss));
    ((Api*)handle)->errorText = ss.str();
    return rc;
}

HSAIL_C_API int brig_container_validate(brig_container_t handle)
{
    std::stringstream ss;
    Validator v(((Api*)handle)->container);
    if (!v.validate(true)) {
        ss << v.getErrorMsg(0) << "\n";
        int rc = v.getErrorCode();
        ((Api*)handle)->errorText = ss.str();
        return rc;
    }
    return 0;
}

HSAIL_C_API brig_code_section_offset brig_container_find_code_module_symbol_offset(brig_container_t handle, const char *symbol_name)
{
  BrigContainer& c = ((Api*)handle)->container;
  for (Code d = c.code().begin(), e = c.code().end(); d != e; ) {
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

HSAIL_C_API const char* brig_container_get_error_text(brig_container_t handle) {
    return ((Api*)handle)->errorText.c_str();
}

HSAIL_C_API void brig_container_destroy(brig_container_t handle)
{
    delete (Api*)handle;
}

}
