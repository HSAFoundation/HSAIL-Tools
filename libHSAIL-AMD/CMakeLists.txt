find_package(Perl REQUIRED)

set(libhsail_amd_public_headers
    Brig_amd.h
    HSAILAmdExt.h
)

set(libhsail_amd_srcs
    gcn.cpp
    mipmap.cpp
    HSAILAmdExt.cpp
    dg.cpp
    gcn.hdl
    mipmap.hdl
    dg.hdl
)

set(generated_dir ${CMAKE_CURRENT_BINARY_DIR}/generated)
file(MAKE_DIRECTORY ${generated_dir})

set(amd_generated_headers
    ${generated_dir}/InstValidation_gcn_gen.hpp
    ${generated_dir}/InstValidation_mipmap_gen.hpp
    ${generated_dir}/InstValidation_dg_gen.hpp
)

set(amd_generated_srcs
    ${amd_generated_headers}
)

set(libHSAIL-PATH ${CMAKE_CURRENT_SOURCE_DIR}/../libHSAIL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${generated_dir})

add_custom_command(
    OUTPUT ${amd_generated_srcs}
    PRE_BUILD
    COMMAND ${PERL_EXECUTABLE} ${libHSAIL-PATH}/HDLProcessor.pl -target=validator ${libHSAIL-PATH}/HSAILDefs.hdl ${CMAKE_CURRENT_SOURCE_DIR}/gcn.hdl    > ${generated_dir}/InstValidation_gcn_gen.hpp
    COMMAND ${PERL_EXECUTABLE} ${libHSAIL-PATH}/HDLProcessor.pl -target=validator ${libHSAIL-PATH}/HSAILDefs.hdl ${CMAKE_CURRENT_SOURCE_DIR}/mipmap.hdl > ${generated_dir}/InstValidation_mipmap_gen.hpp
    COMMAND ${PERL_EXECUTABLE} ${libHSAIL-PATH}/HDLProcessor.pl -target=validator ${libHSAIL-PATH}/HSAILDefs.hdl ${CMAKE_CURRENT_SOURCE_DIR}/dg.hdl     > ${generated_dir}/InstValidation_dg_gen.hpp
    DEPENDS
      ${libHSAIL-PATH}/Brig.h
      gcn.hdl mipmap.hdl dg.hdl
    COMMENT "Generating GCN and MIPMAP validators"
)

add_library(hsail-amd ${libhsail_amd_srcs} ${libhsail_amd_public_headers} ${amd_generated_headers})

add_dependencies(hsail-amd libhsail-includes)

target_include_directories(hsail-amd PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${generated_dir})
target_link_libraries(hsail-amd hsail)

install(TARGETS hsail-amd
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(FILES ${libhsail_amd_public_headers} DESTINATION include/libHSAIL-AMD)
