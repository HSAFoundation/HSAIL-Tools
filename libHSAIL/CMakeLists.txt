find_package(Perl REQUIRED)

find_package(LibElf)

if(LIBELF_FOUND)
  find_package(LibDwarf)
endif()

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
  HSAILTool.h
  HSAILTypeUtilities.h
  HSAILUtilities.h
  HSAILValidator.h
  HSAILValidatorBase.h
  HSAILb128_t.h
  hsail_c.h
  HSAILExtension.h
  HSAILGenericExtension.h
  HSAILExtManager.h
  HSAILImageExt.h
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
  HSAILTool.cpp
  HSAILUtilities.cpp
  HSAILValidator.cpp
  HSAILValidatorBase.cpp
  hsail_c.cpp
  HSAILExtManager.cpp
  HSAILInstProps.cpp
  HSAILImageExt.cpp
  generate.pl
  HDLProcessor.pl
  HSAILCore.hdl
  HSAILImage.hdl
  HSAILDefs.hdl
  BrigMeta.info
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
  ${generated_dir}/HSAILScannerRules_gen_re2c.hpp
  ${generated_dir}/HSAILBrigPropsFastAcc_gen.hpp
  ${generated_dir}/HSAILBrigStaticChecks_gen.hpp
  ${generated_dir}/HSAILInstValidation_core_gen.hpp
  ${generated_dir}/HSAILInstValidation_image_gen.hpp
  ${generated_dir}/HSAILParserUtilities_gen.hpp
  ${generated_dir}/HSAILTemplateUtilities_gen.hpp
  ${generated_dir}/HSAILBrigProps_gen.hpp
  ${generated_dir}/HSAILBrigUtilities_gen.hpp
  ${generated_dir}/HSAILItemImpls_gen.hpp
  ${generated_dir}/HSAILPropAccessors_gen.hpp
  ${generated_dir}/HSAILBrigEnum2str_gen.hpp
  ${generated_dir}/HSAILVisitItems_gen.hpp
)

set(generated_srcs
  ${generated_headers}
  ${generated_dir}/HSAILScannerRules_gen.re2c
)

set(libHSAIL-PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${libHSAIL-PATH})
include_directories(${generated_dir})

add_custom_command(
  OUTPUT ${generated_srcs}
  PRE_BUILD
  COMMAND ${PERL_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/generate.pl
                             -re2c ${RE2C_EXECUTABLE}
                             ${CMAKE_CURRENT_SOURCE_DIR}
                             ${generated_dir}
  DEPENDS
    Brig.h
    HSAILCore.hdl
    HSAILImage.hdl
    HSAILDefs.hdl
    BrigMeta.info
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
if(BUILD_LIBBRIGDWARF)
  add_definitions(-DWITH_LIBBRIGDWARF=1)
endif()
add_dependencies(hsail libhsail-includes)

target_include_directories(hsail PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${generated_dir})

if(UNIX)
  target_link_libraries(hsail dl)
endif()
if(BUILD_LIBBRIGDWARF)
  target_link_libraries(hsail dwarf)
  target_link_libraries(hsail elf)
endif()

install(TARGETS hsail
  ARCHIVE DESTINATION lib COMPONENT libhsail
  LIBRARY DESTINATION lib COMPONENT libhsail
)

install(FILES ${libhsail_public_headers} ${generated_headers} DESTINATION include/libHSAIL COMPONENT libhsail)
