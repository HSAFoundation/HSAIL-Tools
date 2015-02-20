add_library(
libbrigdwarf
BrigDwarfGenerator.cpp	                      hsa_dwarf.h
BrigDwarfGenerator.h	SectionHeaderTable.h
)

add_dependencies(libbrigdwarf ${libhsailname})

include_directories(${CMAKE_SOURCE_DIR}/libHSAIL)
include_directories(${CMAKE_SOURCE_DIR}/libHSAIL/generated)
include_directories(${ELFTOOLCHAIN_PATH}/common)
if(WIN32)
include_directories(${ELFTOOLCHAIN_PATH}/common/win32)
endif()
include_directories(${LIBELF_PATH})
include_directories(${LIBDWARF_PATH})
include_directories(${LIBDWARF_PATH}/src)
