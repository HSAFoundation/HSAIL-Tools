cmake_minimum_required(VERSION 2.6)

project(HSAIL-Tools)

if(MSVC)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

if(UNIX)
  add_compile_options(-fpic -Wall -Werror -std=c++11 -pthread -fno-rtti -fvisibility-inlines-hidden)
  add_definitions(-D__STDC_LIMIT_MACROS)
  add_definitions(-D__STDC_CONSTANT_MACROS)
  add_definitions(-D__STDC_FORMAT_MACROS)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")

include(CMakeDependentOption)

find_package(RE2C REQUIRED)

option(VENDOR_EXTENSIONS "Enable vendor extensions" ON)
message(STATUS "Vendor extensions: ${VENDOR_EXTENSIONS}")

cmake_dependent_option(AMD_EXTENSIONS "Enable AMD HSAIL extensions" ON "VENDOR_EXTENSIONS" OFF)
message(STATUS "AMD extensions: ${AMD_EXTENSIONS}")

option(BUILD_HSAILASM "Build HSAILAsm" ON)
message(STATUS "Building HSAILAsm: ${BUILD_HSAILASM}")

enable_testing()

add_subdirectory(libHSAIL)

if(AMD_EXTENSIONS)
  add_subdirectory(libHSAIL-AMD)
  add_definitions(-DAMD_EXTENSIONS)
endif()

# FIXME: We should check for a usable version of libelf / libdwarf.
if(BUILD_HSAILASM)
  add_subdirectory(HSAILAsm)
  add_subdirectory(tests/1.0/instruction)
  add_subdirectory(tests/1.0/syntax)
  add_subdirectory(tests/1.0/syntax_validation)
endif()

if(BUILD_HSAILTESTGEN)
  add_subdirectory(libTestGen)
  add_subdirectory(HSAILTestGen)
endif()
