find_package(Perl REQUIRED)

set(libhsail_srcs
  Brig.h
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

set(generated_srcs
  ${generated_dir}/HSAILBrigInstUtils_gen.hpp
  ${generated_dir}/HSAILBrigPropsName_gen.hpp
  ${generated_dir}/HSAILBrigValidation_gen.hpp
  ${generated_dir}/HSAILItems_gen.hpp
  ${generated_dir}/HSAILScannerRules_gen.re2c
  ${generated_dir}/HSAILBrigPropsAcc_gen.hpp
  ${generated_dir}/HSAILBrigPropsVisitor_gen.hpp
  ${generated_dir}/HSAILInitBrig_gen.hpp
  ${generated_dir}/HSAILItemUtils_gen.hpp
  ${generated_dir}/HSAILScannerRules_gen_re2c.hpp
  ${generated_dir}/HSAILBrigPropsFastAcc_gen.hpp
  ${generated_dir}/HSAILBrigStaticChecks_gen.hpp
  ${generated_dir}/HSAILInstValidation_gen.hpp
  ${generated_dir}/HSAILParserUtilities_gen.hpp
  ${generated_dir}/HSAILTemplateUtilities_gen.hpp
  ${generated_dir}/HSAILBrigProps_gen.hpp
  ${generated_dir}/HSAILBrigUtilities_gen.hpp
  ${generated_dir}/HSAILItemImpls_gen.hpp
  ${generated_dir}/HSAILPropAccessors_gen.hpp
  ${generated_dir}/HSAILVisitItems_gen.hpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${generated_dir})

add_custom_command(
  OUTPUT ${generated_srcs}
  PRE_BUILD
  COMMAND ${PERL_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/generate.pl
                             -re2c ${RE2C_EXECUTABLE}
                             ${CMAKE_CURRENT_SOURCE_DIR}
                             ${generated_dir}
  DEPENDS Brig.h
  COMMENT "Generating libHSAIL sources"
)

if(BUILD_LIBBRIGDWARF)
  set(libbrigdwarf_srcs
    BrigDwarfGenerator.cpp
    hsa_dwarf.h
    BrigDwarfGenerator.h
    SectionHeaderTable.h
  )

  include_directories(${LIBELF_INCLUDE_DIRS})
  include_directories(${LIBDWARF_INCLUDE_DIRS})
else()
  set(libbrigdwarf_srcs)
endif()

add_custom_target(libhsail-includes ALL DEPENDS ${generated_srcs})
add_library(hsail ${libhsail_srcs} ${libbrigdwarf_srcs} ${generated_srcs})
add_dependencies(hsail libhsail-includes)

if(UNIX)
  target_link_libraries(hsail dl)
endif()
