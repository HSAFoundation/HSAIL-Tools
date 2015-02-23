
find_package(Perl REQUIRED)

add_library(hsail
  Brig.h
  Brig_new.hpp
  HSAILb128_t.h
  HSAILBrigantine.cpp
  HSAILBrigantine.h
  HSAILBrigContainer.cpp
  HSAILBrigContainer.h
  HSAILBrigInstr.hdl
  HSAILBrigObjectFile.cpp
  HSAILBrigObjectFile.h
  hsail_c.cpp
  hsail_c.h
  HSAILConvertors.h
  HSAILDisassembler.cpp
  HSAILDisassembler.h
  HSAILDump.cpp
  HSAILDump.h
  HSAILFloats.cpp
  HSAILFloats.h
  HSAILInstProps.h
  HSAILItemBase.h
  HSAILItems.cpp
  HSAILItems.h
  HSAILParser.cpp
  HSAILParser.h
  HSAILScanner.cpp
  HSAILScanner.h
  HSAILScannerRules.cpp
  HSAILScope.h
  HSAILSRef.h
  HSAILTypeUtilities.h
  HSAILUtilities.cpp
  HSAILUtilities.h
  HSAILValidatorBase.cpp
  HSAILValidatorBase.h
  HSAILValidator.cpp
  HSAILValidator.h
)

set(generated_dir ${CMAKE_CURRENT_BINARY_DIR}/generated)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${generated_dir})

add_custom_target(libhsail-includes
  ${PERL_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/generate.pl
                     ${CMAKE_CURRENT_SOURCE_DIR}
                     ${generated_dir}
)

add_dependencies(hsail libhsail-includes)

if(UNIX)
  target_link_libraries(hsail dl)
endif()
