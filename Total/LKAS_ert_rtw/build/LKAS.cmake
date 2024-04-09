include("${CMAKE_CURRENT_LIST_DIR}/LKASTargets.cmake")
set(LKAS_OBJECTS_TOK_INC_DIRS_ALL
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/toolbox/shared/spc/src_ml/extern/include
    ${MATLAB_ROOT}/toolbox/shared/dsp/vision/matlab/include
    ${MATLAB_ROOT}/extern/include/multimedia
    ${MATLAB_ROOT}/toolbox/vision/include
    ${MATLAB_ROOT}/toolbox/vision/visionrt/export/include
    ${MATLAB_ROOT}/toolbox/vision/visionrt/export/include/visionrt
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert
    ${MATLAB_ROOT}/toolbox/coder/rtiostream/src/utils
    ${MATLAB_ROOT}/toolbox/target/codertarget/rtos/inc)
foreach(TOKDIR_LOOP IN LISTS LKAS_OBJECTS_TOK_INC_DIRS_ALL)
    if(IS_DIRECTORY ${TOKDIR_LOOP})
        list(APPEND LKAS_OBJECTS_TOK_INC_DIRS ${TOKDIR_LOOP})
    endif()
endforeach()
target_include_directories(LKAS::LKAS_objects INTERFACE ${LKAS_OBJECTS_TOK_INC_DIRS})
