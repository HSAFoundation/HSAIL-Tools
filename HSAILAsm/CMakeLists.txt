add_executable(HSAILasm HSAILAsm.cpp)

target_link_libraries(HSAILasm hsail)

if(AMD_EXTENSIONS)
  target_link_libraries(HSAILasm hsail-amd)
endif()

find_library(CURSES_LIB curses)

if(BUILD_LIBBRIGDWARF)
  include_directories(${LIBELF_INCLUDE_DIRS})

  target_link_libraries(HSAILasm ${LIBELF_LIBRARIES})
  target_link_libraries(HSAILasm ${LIBDWARF_LIBRARIES})
endif()

if(CURSES_LIB)
  target_link_libraries(HSAILasm ${CURSES_LIB})
endif()
if(UNIX)
  target_link_libraries(HSAILasm tinfo pthread)
endif()

install(TARGETS HSAILasm
  RUNTIME DESTINATION bin COMPONENT libhsail
)

set(HSAILASM $<TARGET_FILE:HSAILasm>)
set(test "${PROJECT_SOURCE_DIR}/tests/1.0/simple.hsail")

add_test(NAME HSAILAsm-help
         COMMAND ${HSAILASM} -help
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME HSAILAsm-version
         COMMAND ${HSAILASM} -version
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME HSAILAsm-assemble
         COMMAND ${HSAILASM} -assemble ${test} -o test.brig
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME HSAILAsm-disassemble
         COMMAND ${HSAILASM} -disassemble test.brig
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME HSAILAsm-decode
         COMMAND ${HSAILASM} -decode test.brig -o test.yaml
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

if(BUILD_LIBBRIGDWARF)
add_test(NAME HSAILAsm-assemble-g
         COMMAND ${HSAILASM} -assemble -g ${test} -o test-g.brig
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME HSAILAsm-disassemble-g
         COMMAND ${HSAILASM} -disassemble test-g.brig
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME HSAILAsm-assemble-g-odebug
         COMMAND ${HSAILASM} -assemble -g ${test} -odebug test-g.dbg -o test-g.brig
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME HSAILAsm-assemble-g-include-source
         COMMAND ${HSAILASM} -assemble -g -include-source ${test} -o test-g.brig
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

endif()
