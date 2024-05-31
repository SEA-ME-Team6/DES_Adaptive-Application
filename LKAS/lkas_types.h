//
//  lkas_types.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "lkas".
//
//  Model version              : 1.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Fri May 31 15:31:56 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: Intel->x86-64 (Windows64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef lkas_types_h_
#define lkas_types_h_
#include <stdbool.h>
#include <stdint.h>
#include <array>
#ifndef struct_codertarget_raspi_internal_Raspiv4l2Capture_lkas_T
#define struct_codertarget_raspi_internal_Raspiv4l2Capture_lkas_T

struct codertarget_raspi_internal_Raspiv4l2Capture_lkas_T
{
  bool matlabCodegenIsDeleted;
  int32_t isInitialized;
  bool isSetupComplete;
  double Brightness;
  double Saturation;
  double Contrast;
  double Sharpness;
  double CameraZoom;
  double ManualFocus;
  double CameraPan;
  double CameraTilt;
  double BrightnessInternal;
  double SaturationInternal;
  double ContrastInternal;
  double SharpnessInternal;
  double CameraZoomInternal;
  double ManualFocusInternal;
  double CameraPanInternal;
  double CameraTiltInternal;
  bool EnableManualFocusInternal;
};

#endif             // struct_codertarget_raspi_internal_Raspiv4l2Capture_lkas_T

#ifndef struct_c_projective2d_lkas_T
#define struct_c_projective2d_lkas_T

struct c_projective2d_lkas_T
{
  std::array<double, 9> T;
};

#endif                                 // struct_c_projective2d_lkas_T

#ifndef struct_vision_internal_blocks_Warp_lkas_T
#define struct_vision_internal_blocks_Warp_lkas_T

struct vision_internal_blocks_Warp_lkas_T
{
  int32_t isInitialized;
  c_projective2d_lkas_T TformProjective;
};

#endif                             // struct_vision_internal_blocks_Warp_lkas_T
#endif                                 // lkas_types_h_
