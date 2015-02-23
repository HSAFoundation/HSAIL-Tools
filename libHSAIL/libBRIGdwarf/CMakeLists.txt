
#find_path(LIBDWARF_INCLUDE_DIR libdwarf.h)
#find_path(LIBELF_INCLUDE_DIR elf.h)
#find_library(LIBELF_LIB libelf)

include_directories(${CMAKE_SOURCE_DIR}/libHSAIL)
include_directories(${CMAKE_SOURCE_DIR}/libHSAIL/generated)


include_directories(${LIBELF_INCLUDE_DIRS})
include_directories(${LIBDWARF_PATH})
include_directories(${LIBDWARF_PATH}/src)

add_library(brigdwarf
  BrigDwarfGenerator.cpp
  hsa_dwarf.h
  BrigDwarfGenerator.h
  SectionHeaderTable.h
)

add_dependencies(brigdwarf HSAIL)
target_link_libraries(brigdwarf ${LIBELF_LIBRARIES})