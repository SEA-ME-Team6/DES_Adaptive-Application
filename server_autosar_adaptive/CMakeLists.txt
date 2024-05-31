cmake_minimum_required(VERSION 3.12)
project(test)

# This AUTOSAR Adaptive Platform requires C++14
set(CMAKE_CXX_STANDARD 14)
# Enable 'rdyamic' switch to export the executable's symbols for debugging
set(CMAKE_ENABLE_EXPORTS 1)

find_package(Threads REQUIRED)
find_package(Boost 1.55 COMPONENTS system thread log REQUIRED)
find_package(vsomeip3 REQUIRED)

include_directories(
    ${Boost_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/ara/com
    ${CMAKE_SOURCE_DIR}/ara/core
    # ${CMAKE_SOURCE_DIR}/ara/diag
    # ${CMAKE_SOURCE_DIR}/ara/exec
    ${CMAKE_SOURCE_DIR}/ara/log
    ${CMAKE_SOURCE_DIR}/slprj/autosar_adaptive/_sharedutils
)

file(GLOB ARA_COM_SOURCES "${CMAKE_SOURCE_DIR}/ara/com/*.cpp")
file(GLOB ARA_COM_VSOMEIP_SOURCES "${CMAKE_SOURCE_DIR}/ara/com/vsomeip/*.cpp")
file(GLOB ARA_CORE_SOURCES "${CMAKE_SOURCE_DIR}/ara/core/*.cpp")
# file(GLOB ARA_DIAG_SOURCES "${CMAKE_SOURCE_DIR}/ara/diag/*.cpp")
# file(GLOB ARA_EXEC_SOURCES "${CMAKE_SOURCE_DIR}/ara/exec/*.cpp")
file(GLOB ARA_LOG_SOURCES "${CMAKE_SOURCE_DIR}/ara/log/*.cpp")

add_executable(${PROJECT_NAME}
    main.cpp
    server.cpp
    ${ARA_COM_SOURCES}
    ${ARA_COM_VSOMEIP_SOURCES}
    ${ARA_CORE_SOURCES}
    # ${ARA_DIAG_SOURCES}
    # ${ARA_EXEC_SOURCES}
    ${ARA_LOG_SOURCES}
)

target_link_libraries(${PROJECT_NAME} 
    Threads::Threads
    ${Boost_LIBRARIES}
    vsomeip3
)

##
add_executable(lkas  /root/Documents/MATLAB/SupportPackages/R2024a/toolbox/realtime/targets/linux/src/MW_v4l2_cam.c
    /root/Documents/MATLAB/SupportPackages/R2024a/toolbox/realtime/targets/linux/src/MW_availableWebcam.c
    ${MATLAB_ROOT}/toolbox/vision/visionrt/vipsvd/svd_d_rt.c
    ${MATLAB_ROOT}/toolbox/vision/visionrt/vipsvd/svd_helper_rt.c
    ${MATLAB_ROOT}/toolbox/vision/visionrt/vipendian/is_little_endian_rt.c
    ${START_DIR}/lkas_autosar_adaptive/lkas.cpp
    ${START_DIR}/lkas_autosar_adaptive/main.cpp)

target_link_libraries(lkas PRIVATE ${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64/libmwara_com_22_11.so
${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64/libmwara_exec_22_11.so
${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64/libmwara_log_22_11.so
${SPKG_ROOT}/toolbox/coder/ara/mw_ara/libraries/glnxa64/libmwara_per_22_11.so
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