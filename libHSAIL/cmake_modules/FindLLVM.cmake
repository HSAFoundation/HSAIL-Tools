cmake_minimum_required(VERSION 2.8.8)


find_program(LLVM_CONFIG_EXE NAMES "llvm-config")
execute_process(COMMAND ${LLVM_CONFIG_EXE} --libdir OUTPUT_VARIABLE LLVM_LIB_DIR
         OUTPUT_STRIP_TRAILING_WHITESPACE )

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION} dir ${LLVM_DIR}")

find_library(LLVM_SUPPORT_LIB LLVMSupport PATHS ${LLVM_LIB_DIR})
