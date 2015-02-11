cmake_minimum_required (VERSION 2.6)

project (HSAIL-Tools)

if(UNIX)
  set(LIB_EXT .a)
else()
  set(LIB_EXT .lib)
endif()

if(MSVC)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

if(UNIX)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${EXTRA_CFLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_CFLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread -D __STDC_LIMIT_MACROS -D __STDC_CONSTANT_MACROS  -D __STDC_FORMAT_MACROS")
endif()

add_subdirectory(libHSAIL)

if(BUILD_LIBBRIGDWARF)
add_definitions(-DWITH_LIBBRIGDWARF=1)
add_subdirectory(libBRIGdwarf)
endif()

if(BUILD_HSAILASM)
add_subdirectory(HSAILAsm)
endif()
