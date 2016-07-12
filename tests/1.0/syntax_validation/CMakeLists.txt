if (SYNTAX_VALIDATION_TESTS)

set(HSAILASM $<TARGET_FILE:HSAILasm>)
if (MSVC)
  set(RUNTEST ${CMAKE_CURRENT_SOURCE_DIR}/run_test.cmd)
else()
  set(RUNTEST ${CMAKE_CURRENT_SOURCE_DIR}/run_test)
endif()

set(test_dir ${CMAKE_CURRENT_BINARY_DIR}/tests)
file(MAKE_DIRECTORY ${test_dir})

add_custom_command(
  OUTPUT
    ${test_dir}/_testinfo.txt
  PRE_BUILD
  COMMAND ${PERL_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/testgen.pl
    ${CMAKE_CURRENT_SOURCE_DIR}/hsail_negative_tests.txt
    ${test_dir}
  DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/hsail_negative_tests.txt
  COMMENT "Generating syntax validation tests"
)

add_custom_target(generate-syntax-validation-tests ALL DEPENDS ${test_dir}/_testinfo.txt)

set(golden_dir ${CMAKE_CURRENT_BINARY_DIR}/golden)
file(MAKE_DIRECTORY ${golden_dir})

message("Extracting golden files for syntax validation tests")
execute_process(
  COMMAND unzip -u ${CMAKE_CURRENT_SOURCE_DIR}/golden.zip
  OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/golden.out
  ERROR_FILE  ${CMAKE_CURRENT_BINARY_DIR}/golden.err
  WORKING_DIRECTORY ${golden_dir}
)

macro(syntax_validation_test name)
  add_test(NAME 1.0/syntax_validation/${name}
           COMMAND ${RUNTEST} ${HSAILASM} ${name}
                   ${test_dir} ${golden_dir}
           WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endmacro()

macro(syntax_validation_test_f fname)
  get_filename_component(fext ${fname} EXT)
  get_filename_component(name ${fname} NAME_WE)
  get_filename_component(fdir ${fname} DIRECTORY)
  syntax_validation_test(${name})
endmacro()

file(GLOB files ${golden_dir}/*.log)
foreach(file ${files})
  file(RELATIVE_PATH fname ${golden_dir} ${file})
  syntax_validation_test_f(${fname})
endforeach()

endif()
