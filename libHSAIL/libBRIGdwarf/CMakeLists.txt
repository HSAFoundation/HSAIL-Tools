add_library(
libbrigdwarf
BrigDwarfGenerator.cpp	                      hsa_dwarf.h
BrigDwarfGenerator.h	SectionHeaderTable.h
)

add_dependencies(libbrigdwarf libhsail)

include_directories(${CMAKE_SOURCE_DIR}/libHSAIL)
include_directories(${CMAKE_SOURCE_DIR}/libHSAIL/generated)
include_directories(${ELFTOOLCHAIN_PATH}/common)
include_directories(${ELFTOOLCHAIN_PATH}/common/win32)
include_directories(${LIBELF_PATH})
include_directories(${LIBDWARF_PATH})
include_directories(${LIBDWARF_PATH}/src)
