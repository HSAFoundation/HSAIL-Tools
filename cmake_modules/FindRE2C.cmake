# - Find re2c executable and provides macros to generate custom build rules
# The module defines the following variables:
#
#  RE2C_EXECUTABLE - path to the bison program
#  RE2C_VERSION - version of bison
#  RE2C_FOUND - true if the program was found
#
find_program(RE2C_EXECUTABLE NAMES re2c DOC "path to re2c executable")
mark_as_advanced(RE2C_EXECUTABLE)

if(RE2C_EXECUTABLE)

	execute_process(COMMAND ${RE2C_EXECUTABLE} --vernum
		RESULT_VARIABLE RE2C_version_result
		OUTPUT_VARIABLE RE2C_version_output
		ERROR_VARIABLE RE2C_version_error
		OUTPUT_STRIP_TRAILING_WHITESPACE)

	if(RE2C_version_result EQUAL 0)
		message(SEND_ERROR "Command \"${RE2C_EXECUTABLE} --vernum\" failed with output:\n${RE2C_version_error}")
	else()
		set(RE2C_VERSION ${RE2C_version_output})
	endif()

	macro(RE2C_TARGET Re2cInput Re2cOutput Args)
		set(RE2C_EXECUTABLE_opts ${Args})

		ADD_CUSTOM_COMMAND(OUTPUT ${Re2cOutput}
        COMMAND ${RE2C_EXECUTABLE}
        ARGS ${RE2C_EXECUTABLE_opts} -o ${Re2cOutput} ${Re2cInput}
        DEPENDS ${Re2cInput}
        COMMENT "[RE2C] Building re2c scanner with re2c ${RE2C_VERSION}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

	endmacro(RE2C_TARGET)
endif(RE2C_EXECUTABLE)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(RE2C DEFAULT_MSG RE2C_EXECUTABLE)
