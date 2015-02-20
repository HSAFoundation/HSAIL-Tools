add_library(
${libhsailname}
Brig.h			 HSAILFloats.cpp	 HSAILUtilities.h
Brig_new.hpp		 HSAILFloats.h		 HSAILValidator.cpp
CMakeLists.txt		 HSAILInstProps.h	 HSAILValidator.h
                         HSAILItemBase.h	 HSAILValidatorBase.cpp
HSAILBrigContainer.cpp	 HSAILItems.cpp		 HSAILValidatorBase.h
HSAILBrigContainer.h	 HSAILItems.h		 HSAILb128_t.h
HSAILBrigInstr.hdl	 HSAILParser.cpp	 
HSAILBrigObjectFile.cpp  HSAILParser.h		 
HSAILBrigObjectFile.h	 HSAILSRef.h		 
HSAILBrigantine.cpp	 HSAILScanner.cpp	 
HSAILBrigantine.h	 HSAILScanner.h		 
HSAILConvertors.h	 HSAILScannerRules.cpp	 hsail_c.cpp
HSAILDisassembler.cpp	                         hsail_c.h
HSAILDisassembler.h	 HSAILScope.h		 
HSAILDump.cpp		 HSAILTypeUtilities.h
HSAILDump.h		 HSAILUtilities.cpp
)

add_custom_target(libhsail-includes
  perl ${CMAKE_SOURCE_DIR}/libHSAIL/generate.pl ${CMAKE_SOURCE_DIR}/libHSAIL ${CMAKE_SOURCE_DIR}/libHSAIL/generated
)

add_dependencies(${libhsailname} libhsail-includes)

include_directories(${CMAKE_SOURCE_DIR}/libHSAIL)
include_directories(${CMAKE_SOURCE_DIR}/libHSAIL/generated)

if(UNIX)
target_link_libraries(${libhsailname} dl)
endif()
