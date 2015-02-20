add_executable(HSAILasm
  HSAILAsm.cpp
)

add_dependencies(HSAILasm ${libhsailname})

include_directories(${CMAKE_SOURCE_DIR}/libHSAIL)
include_directories(${CMAKE_SOURCE_DIR}/libHSAIL/generated)
target_link_libraries(HSAILasm ${libhsailname})

if(BUILD_LIBBRIGDWARF)
add_dependencies(HSAILasm libbrigdwarf)
include_directories(${CMAKE_SOURCE_DIR}/libBRIGdwarf)
target_link_libraries(HSAILasm libbrigdwarf)
target_link_libraries(HSAILasm ${LIBELF_LIB_PATH}/libelf${LIB_EXT})
target_link_libraries(HSAILasm ${LIBDWARF_LIB_PATH}/libdwarf${LIB_EXT})
endif()

include_directories(${LLVM_PATH}/include)
if(UNIX)
include_directories(${LLVM_PATH}/linux/include)
else()
include_directories(${LLVM_PATH}/win32/include)
endif()
target_link_libraries(HSAILasm ${LLVM_SUPPORT_LIB_DIR}/LLVMSupport${LIB_EXT})

