find_package(Perl REQUIRED)

set(libhsail_public_headers
  Brig.h
  HSAILBrigContainer.h
  HSAILBrigObjectFile.h
  HSAILBrigantine.h
  HSAILConvertors.h
  HSAILDisassembler.h
  HSAILDump.h
  HSAILFloats.h
  HSAILInstProps.h
  HSAILItemBase.h
  HSAILItems.h
  HSAILParser.h
  HSAILSRef.h
  HSAILScanner.h
  HSAILScope.h
  HSAILTypeUtilities.h
  HSAILUtilities.h
  HSAILValidator.h
  HSAILValidatorBase.h
  HSAILb128_t.h
  hsail_c.h
)

set(libhsail_srcs
  HSAILBrigContainer.cpp
  HSAILBrigObjectFile.cpp
  HSAILBrigantine.cpp
  HSAILDisassembler.cpp
  HSAILDump.cpp
  HSAILFloats.cpp
  HSAILItems.cpp
  HSAILParser.cpp
  HSAILScanner.cpp
  HSAILScannerRules.cpp
  HSAILScannerRules.re2c
  HSAILUtilities.cpp
  HSAILValidator.cpp
  HSAILValidatorBase.cpp
  hsail_c.cpp
)

set(generated_dir ${CMAKE_CURRENT_BINARY_DIR}/generated)

set(generated_headers
  ${generated_dir}/HSAILBrigInstUtils_gen.hpp
  ${generated_dir}/HSAILBrigPropsName_gen.hpp
  ${generated_dir}/HSAILBrigValidation_gen.hpp
  ${generated_dir}/HSAILItems_gen.hpp
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

set(generated_srcs
  ${generated_headers}
  ${generated_dir}/HSAILScannerRules_gen.re2c
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

  list(APPEND libhsail_public_headers
    BrigDwarfGenerator.h
    hsa_dwarf.h
  )

  include_directories(${LIBELF_INCLUDE_DIRS})
  include_directories(${LIBDWARF_INCLUDE_DIRS})
else()
  set(libbrigdwarf_srcs)
endif()

add_custom_target(libhsail-includes ALL DEPENDS ${generated_srcs})
add_library(hsail ${libhsail_srcs} ${libhsail_public_headers} ${libbrigdwarf_srcs} ${generated_headers})
add_dependencies(hsail libhsail-includes)

if(UNIX)
  target_link_libraries(hsail dl)
endif()

install(TARGETS hsail
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

install(FILES ${libhsail_public_headers} ${generated_headers} DESTINATION include/libHSAIL)
