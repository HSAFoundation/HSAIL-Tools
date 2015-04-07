include_directories(${PROJECT_SOURCE_DIR}/libHSAIL)
include_directories(${PROJECT_BINARY_DIR}/libHSAIL/generated)

include_directories(${LIBELF_INCLUDE_DIRS})
include_directories(${LLVM_PATH}/include)

if(UNIX)
  include_directories(${LLVM_PATH}/linux/include)
else()
  include_directories(${LLVM_PATH}/win32/include)
endif()

add_executable(HSAILasm HSAILAsm.cpp)
target_link_libraries(HSAILasm hsail)
add_dependencies(HSAILasm libhsail-includes)

# FIXME: We also need to get the link dependencies of the libLLVMSupport
target_link_libraries(HSAILasm ${LLVM_SUPPORT_LIB})

find_library(CURSES_LIB curses)

#include(LLVM-Config.cmake)

if(BUILD_LIBBRIGDWARF)
  target_link_libraries(HSAILasm ${LIBELF_LIBRARIES})
  target_link_libraries(HSAILasm ${LIBDWARF_LIBRARIES})
endif()

if(CURSES_LIB)
  # FIXME: Find dependencies pulled in by LLVMSupport
  target_link_libraries(HSAILasm ${CURSES_LIB})
endif()

install(TARGETS HSAILasm
  RUNTIME DESTINATION bin
)
