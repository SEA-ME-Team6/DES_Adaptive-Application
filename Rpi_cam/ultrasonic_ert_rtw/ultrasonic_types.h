//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ultrasonic_types.h
//
// Code generated for Simulink model 'ultrasonic'.
//
// Model version                  : 1.8
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Apr 18 14:01:03 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ultrasonic_types_h_
#define RTW_HEADER_ultrasonic_types_h_
#include "rtwtypes.h"
#ifndef struct_codertarget_raspi_internal_RaspiTCPSend_ultrasonic_T
#define struct_codertarget_raspi_internal_RaspiTCPSend_ultrasonic_T

struct codertarget_raspi_internal_RaspiTCPSend_ultrasonic_T
{
  int32_T isInitialized;
  uint16_T connStream_;
  real_T isServer_;
  uint8_T isLittleEnd_;
};

#endif           // struct_codertarget_raspi_internal_RaspiTCPSend_ultrasonic_T

#ifndef struct_sensors_raspberrypi_UltrasonicBlock_ultrasonic_T
#define struct_sensors_raspberrypi_UltrasonicBlock_ultrasonic_T

struct sensors_raspberrypi_UltrasonicBlock_ultrasonic_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif               // struct_sensors_raspberrypi_UltrasonicBlock_ultrasonic_T

// Parameters (default storage)
typedef struct P_ultrasonic_T_ P_ultrasonic_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ultrasonic_T RT_MODEL_ultrasonic_T;

#endif                                 // RTW_HEADER_ultrasonic_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
