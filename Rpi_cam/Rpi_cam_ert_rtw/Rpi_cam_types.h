//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Rpi_cam_types.h
//
// Code generated for Simulink model 'Rpi_cam'.
//
// Model version                  : 1.104
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Mar 15 11:10:11 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Rpi_cam_types_h_
#define RTW_HEADER_Rpi_cam_types_h_
#include "rtwtypes.h"
#ifndef struct_codertarget_linux_blocks_SDL2VideoDisplay
#define struct_codertarget_linux_blocks_SDL2VideoDisplay

struct codertarget_linux_blocks_SDL2VideoDisplay
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  int32_T PixelFormatEnum;
  int32_T displayId;
};

#endif                      // struct_codertarget_linux_blocks_SDL2VideoDisplay

#ifndef struct_codertarget_raspi_internal_Raspiv4l2Capture
#define struct_codertarget_raspi_internal_Raspiv4l2Capture

struct codertarget_raspi_internal_Raspiv4l2Capture
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T Brightness;
  real_T Saturation;
  real_T Contrast;
  real_T Sharpness;
  real_T CameraZoom;
  real_T ManualFocus;
  real_T CameraPan;
  real_T CameraTilt;
  real_T BrightnessInternal;
  real_T SaturationInternal;
  real_T ContrastInternal;
  real_T SharpnessInternal;
  real_T CameraZoomInternal;
  real_T ManualFocusInternal;
  real_T CameraPanInternal;
  real_T CameraTiltInternal;
  boolean_T EnableManualFocusInternal;
};

#endif                    // struct_codertarget_raspi_internal_Raspiv4l2Capture

#ifndef struct_c_projective2d
#define struct_c_projective2d

struct c_projective2d
{
  real_T T[9];
};

#endif                                 // struct_c_projective2d

#ifndef struct_vision_internal_blocks_Warp
#define struct_vision_internal_blocks_Warp

struct vision_internal_blocks_Warp
{
  int32_T isInitialized;
  c_projective2d TformProjective;
};

#endif                                 // struct_vision_internal_blocks_Warp

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 // struct_emxArray_boolean_T

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 // struct_emxArray_int32_T

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 // struct_emxArray_real_T

// Parameters (default storage)
typedef struct P_ P;

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

#endif                                 // RTW_HEADER_Rpi_cam_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
