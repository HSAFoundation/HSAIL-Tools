
find_package(Perl REQUIRED)

set(libhsail_srcs
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

set(generated_srcs
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILBrigInstUtils_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILBrigPropsName_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILBrigValidation_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILItems_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILScannerRules_gen.re2c
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILBrigPropsAcc_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILBrigPropsVisitor_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILInitBrig_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILItemUtils_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILScannerRules_gen_re2c.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILBrigPropsFastAcc_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILBrigStaticChecks_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILInstValidation_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILParserUtilities_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILTemplateUtilities_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILBrigProps_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILBrigUtilities_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILItemImpls_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILPropAccessors_gen.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/HSAILVisitItems_gen.hpp
)


set(generated_dir ${CMAKE_CURRENT_BINARY_DIR}/generated)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${generated_dir})

add_custom_command(
  OUTPUT ${generated_srcs}
  PRE_BUILD
  COMMAND ${PERL_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/generate.pl
                             ${CMAKE_CURRENT_SOURCE_DIR}
                             ${generated_dir}
  DEPENDS Brig_new.hpp
  COMMENT "Generating libHSAIL sources"
)

add_custom_target(libhsail-includes ALL DEPENDS ${generated_srcs})
add_library(hsail ${libhsail_srcs} ${generated_srcs})
add_dependencies(hsail libhsail-includes)

if(UNIX)
  target_link_libraries(hsail dl)
endif()
