/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Rpi_cam_types.h
 *
 * Code generated for Simulink model 'Rpi_cam'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Mar  4 13:32:08 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rpi_cam_types_h_
#define RTW_HEADER_Rpi_cam_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_R8QzEYwpw8e27L6oLfGi5D
#define struct_tag_R8QzEYwpw8e27L6oLfGi5D

struct tag_R8QzEYwpw8e27L6oLfGi5D
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  int32_T PixelFormatEnum;
  int32_T displayId;
};

#endif                                 /* struct_tag_R8QzEYwpw8e27L6oLfGi5D */

#ifndef typedef_codertarget_linux_blocks_SDL2_T
#define typedef_codertarget_linux_blocks_SDL2_T

typedef struct tag_R8QzEYwpw8e27L6oLfGi5D codertarget_linux_blocks_SDL2_T;

#endif                             /* typedef_codertarget_linux_blocks_SDL2_T */

#ifndef struct_tag_3Et4NpskkIDj0Z1ASuM5XC
#define struct_tag_3Et4NpskkIDj0Z1ASuM5XC

struct tag_3Et4NpskkIDj0Z1ASuM5XC
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

#endif                                 /* struct_tag_3Et4NpskkIDj0Z1ASuM5XC */

#ifndef typedef_codertarget_raspi_internal_Ra_T
#define typedef_codertarget_raspi_internal_Ra_T

typedef struct tag_3Et4NpskkIDj0Z1ASuM5XC codertarget_raspi_internal_Ra_T;

#endif                             /* typedef_codertarget_raspi_internal_Ra_T */

/* Parameters (default storage) */
typedef struct P_Rpi_cam_T_ P_Rpi_cam_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Rpi_cam_T RT_MODEL_Rpi_cam_T;

#endif                                 /* RTW_HEADER_Rpi_cam_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
