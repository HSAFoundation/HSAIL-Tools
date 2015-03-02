cmake_minimum_required(VERSION 2.6)

project(HSAIL-Tools)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")

option(BUILD_LIBBRIGDWARF "Build libbrigdwarf" ON)
option(BUILD_HSAILASM "Build HSAILAsm" ON)

find_package(LibElf REQUIRED)
find_package(LibDwarf REQUIRED)

find_library(LLVM_SUPPORT_LIB LLVMSupport)


if(MSVC)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

if(UNIX)
  #FIXME: Should set -fno-rtti etc. from LLVM config flags.
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${EXTRA_CFLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_CFLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread -D __STDC_LIMIT_MACROS -D __STDC_CONSTANT_MACROS  -D __STDC_FORMAT_MACROS -fno-rtti")
endif()

if(UNIX)
set(libhsailname hsail)
else()
set(libhsailname libhsail)
endif()

add_subdirectory(libHSAIL)

if(BUILD_LIBBRIGDWARF)
  add_definitions(-DWITH_LIBBRIGDWARF=1)
  add_subdirectory(libBRIGdwarf)
endif()

if(BUILD_HSAILASM)
  add_subdirectory(HSAILAsm)
endif()
