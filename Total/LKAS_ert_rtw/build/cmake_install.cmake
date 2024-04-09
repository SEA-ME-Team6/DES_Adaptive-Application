# Install script for directory: /home/seame-workstation09/DES_Adaptive-Application/Total/LKAS_ert_rtw

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/seame-workstation09/DES_Adaptive-Application/Total")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/LKAS_ert_rtw/objects-Release/LKAS_objects" TYPE FILE FILES
    "usr/local/MATLAB/R2023b/toolbox/shared/spc/src_ml/extern/src/DAHostLib_rtw.c.o"
    "usr/local/MATLAB/R2023b/toolbox/shared/dsp/vision/matlab/include/HostLib_MMFile.c.o"
    "usr/local/MATLAB/R2023b/toolbox/shared/dsp/vision/matlab/include/HostLib_Multimedia.c.o"
    "usr/local/MATLAB/R2023b/toolbox/vision/visionrt/vipsvd/svd_d_rt.c.o"
    "usr/local/MATLAB/R2023b/toolbox/vision/visionrt/vipsvd/svd_helper_rt.c.o"
    "usr/local/MATLAB/R2023b/toolbox/vision/visionrt/vipendian/is_little_endian_rt.c.o"
    "LKAS.cpp.o"
    "LKAS_data.cpp.o"
    FILES_FROM_DIR "/home/seame-workstation09/DES_Adaptive-Application/Total/LKAS_ert_rtw/build/CMakeFiles/LKAS_objects.dir/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE OPTIONAL FILES "/home/seame-workstation09/DES_Adaptive-Application/Total/LKAS_ert_rtw/build/LKAS")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/LKAS_ert_rtw/export" TYPE FILE FILES "/home/seame-workstation09/DES_Adaptive-Application/Total/LKAS_ert_rtw/build/LKAS.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/LKAS_ert_rtw/export/LKASTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/LKAS_ert_rtw/export/LKASTargets.cmake"
         "/home/seame-workstation09/DES_Adaptive-Application/Total/LKAS_ert_rtw/build/CMakeFiles/Export/f4b2ce366b8c37264ce77d474370b073/LKASTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/LKAS_ert_rtw/export/LKASTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/LKAS_ert_rtw/export/LKASTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/LKAS_ert_rtw/export" TYPE FILE FILES "/home/seame-workstation09/DES_Adaptive-Application/Total/LKAS_ert_rtw/build/CMakeFiles/Export/f4b2ce366b8c37264ce77d474370b073/LKASTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/LKAS_ert_rtw/export" TYPE FILE FILES "/home/seame-workstation09/DES_Adaptive-Application/Total/LKAS_ert_rtw/build/CMakeFiles/Export/f4b2ce366b8c37264ce77d474370b073/LKASTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/seame-workstation09/DES_Adaptive-Application/Total/LKAS_ert_rtw/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
