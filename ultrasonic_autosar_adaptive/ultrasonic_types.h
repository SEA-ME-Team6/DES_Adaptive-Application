//
//  ultrasonic_types.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "ultrasonic".
//
//  Model version              : 1.2
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Mon Jun  3 19:16:19 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef ultrasonic_types_h_
#define ultrasonic_types_h_
#include <stdbool.h>
#include <stdint.h>
#ifndef struct_sensors_raspberrypi_UltrasonicBlock_ultrasonic_T
#define struct_sensors_raspberrypi_UltrasonicBlock_ultrasonic_T

struct sensors_raspberrypi_UltrasonicBlock_ultrasonic_T
{
  bool matlabCodegenIsDeleted;
  int32_t isInitialized;
  bool isSetupComplete;
  double SampleTime;
};

#endif               // struct_sensors_raspberrypi_UltrasonicBlock_ultrasonic_T
#endif                                 // ultrasonic_types_h_
