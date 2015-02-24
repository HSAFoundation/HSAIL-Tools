
include_directories(${PROJECT_SOURCE_DIR}/libHSAIL)
include_directories(${PROJECT_BINARY_DIR}/libHSAIL/generated)

include_directories(${LIBELF_INCLUDE_DIRS})
include_directories(${LIBDWARF_PATH})
include_directories(${LIBDWARF_PATH}/src)

add_library(brigdwarf
  BrigDwarfGenerator.cpp
  hsa_dwarf.h
  BrigDwarfGenerator.h
  SectionHeaderTable.h
)

target_link_libraries(brigdwarf hsail ${LIBELF_LIBRARIES})
add_dependencies(brigdwarf libhsail-includes)
