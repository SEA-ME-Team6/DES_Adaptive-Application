###########################################################################
# CMakeLists.txt generated for component control
# Product type: executable
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(control)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


# Set directory properties.
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT control)

###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR .. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT /usr/local/MATLAB/R2024a CACHE PATH "")

# Additional variables that are defined conditionally.
if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()
if(APPLE)
    if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL x86_64)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/maci64)
    elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL arm64)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/maca64)
    endif()
elseif(UNIX AND ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL x86_64) AND ("${CMAKE_SYSTEM_NAME}" STREQUAL Linux))
    list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/glnxa64)
elseif(WIN32 AND ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL AMD64))
    if(MSVC)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/extern/lib/win64/microsoft)
    elseif(MINGW)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/extern/lib/win64/mingw64)
    endif()
    list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/win64
        ${MATLAB_ROOT}/lib/win64)
endif()



# Add common link_directories, including any platform-specific paths under 
# MATLAB_ROOT.
set(EXTRA_SYSLIB_PATHS ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64
    ${SPKG_ROOT}/bin/glnxa64/dlt-daemon/lib
    ${SPKG_ROOT}/bin/glnxa64/vsomeip/lib)
list(APPEND CMAKE_LIBRARY_PATH ${EXTRA_SYSLIB_PATHS})
link_directories(${EXTRA_SYSLIB_PATHS})
if(DEFINED MATLAB_ROOT_SYSLIB_PATHS)
    list(APPEND CMAKE_LIBRARY_PATH ${MATLAB_ROOT_SYSLIB_PATHS})
    link_directories(${MATLAB_ROOT_SYSLIB_PATHS})
endif()
if(DEFINED MATLAB_ROOT_SYSINCLUDE_PATHS)
    list(APPEND CMAKE_INCLUDE_PATH ${MATLAB_ROOT_SYSINCLUDE_PATHS})
endif()



###########################################################################
## Required packages
###########################################################################
find_package(Threads REQUIRED)

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})
find_library(LIB_DL NAMES dl libdl REQUIRED)
find_library(LIB_RT NAMES rt librt REQUIRED)

###########################################################################
## Target definition and commands
###########################################################################

# Include upstream components that need to be built as part of the current 
# project using the add_subdirectory command.
if(NOT TARGET rtwshared)
    add_subdirectory(../slprj/autosar_adaptive/_sharedutils ${BINARY_START_DIR}/slprj/autosar_adaptive/_sharedutils)
endif()

# Definition of target "control".
add_executable(control  ${START_DIR}/control_autosar_adaptive/control.cpp
    ${START_DIR}/control_autosar_adaptive/main.cpp)

# Set properties for target "control".
set_target_properties(control PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>")

# Specify language features required for target "control".
target_compile_features(control PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target "control".
target_compile_definitions(control PRIVATE -DMODEL=control
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=1
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=1
    -DINTEGER_CODE=0
    -DMT=0
    -DARA_VER_21_11
    -DENABLE_VSOMEIP)

# Specify compiler flags for target "control".
target_compile_options(control PRIVATE -std=c++11
    $<$<NOT:$<BOOL:${CMAKE_BUILD_TYPE}>>:-O3 -DNDEBUG>)

# Specify include directories for target "control".
target_include_directories(control PRIVATE ${START_DIR}
    ${START_DIR}/control_autosar_adaptive
    ${MATLAB_ROOT}/toolbox/coder/simulinkcoder/src/executor
    ${START_DIR}/control_autosar_adaptive/stub/aragen
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert
    ${START_DIR}/slprj/autosar_adaptive/_sharedutils
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/headers/glnxa64/21_11
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/headers/glnxa64/ud_ipc
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/headers/glnxa64/dds_util
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/headers/glnxa64/com_factory
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/headers/glnxa64/log_utils
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/headers/glnxa64/manifest_utils
    ${SPKG_ROOT}/bin/glnxa64/dlt-daemon/include
    ${SPKG_ROOT}/bin/glnxa64/vsomeip/include)

# Specify library link dependencies for target "control". CMake generator 
# expressions are used to create a CMakeLists.txt file that supports 
# multiple platforms with differently named system library dependencies.
target_link_libraries(control PRIVATE ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64/libmwara_com_21_11.so
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64/libmwara_exec_21_11.so
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64/libmwara_log_21_11.so
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64/libmwara_per_21_11.so
    ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64/libmwara_manifest_utils.so
    ${MATLAB_ROOT}/bin/glnxa64/libmwboost_thread.so.1.78.0
    ${MATLAB_ROOT}/bin/glnxa64/libmwboost_chrono.so.1.78.0
    ${MATLAB_ROOT}/bin/glnxa64/libmwboost_timer.so.1.78.0
    ${MATLAB_ROOT}/bin/glnxa64/libmwboost_filesystem.so.1.78.0
    ${MATLAB_ROOT}/bin/glnxa64/libsqlite3.so.3
    ${SPKG_ROOT}/bin/glnxa64/dlt-daemon/lib/libdlt.so
    ${SPKG_ROOT}/bin/glnxa64/dlt-daemon/lib/libdlt.so.2
    ${SPKG_ROOT}/bin/glnxa64/vsomeip/lib/libvsomeip3.so.3
    ${SPKG_ROOT}/bin/glnxa64/vsomeip/lib/libvsomeip3-sd.so.3
    ${SPKG_ROOT}/bin/glnxa64/vsomeip/lib/libvsomeip3-cfg.so.3
    rtwshared
    ${LIB_DL}
    ${LIB_RT}
    Threads::Threads
    $<$<BOOL:${FOUND_LIBM}>:m>
    $<$<BOOL:${WIN32}>:kernel32>
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<BOOL:${WIN32}>:mswsock>
    $<$<BOOL:${WIN32}>:advapi32>)

# Extract DWARF debug symbols into a separate file when building 
# executable programs for Apple platforms.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:control>;--flat,"
                "true"
        >)
    add_custom_command(TARGET control
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS control.dwarf)
endif()


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET control POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:control>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(control)
endif()
