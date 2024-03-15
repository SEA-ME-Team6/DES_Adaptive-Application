//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Rpi_cam_private.h
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
#ifndef RTW_HEADER_Rpi_cam_private_h_
#define RTW_HEADER_Rpi_cam_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Rpi_cam_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void makeConstraintMatrix_Projective_D_D(const real_T pts1[], const
  real_T pts2[], uint32_T sampleNum, uint32_T maxSampleNum, real_T constraint[]);
extern void normPts_D_D(const real_T pts[], const uint32_T samples[], uint32_T
  ptsNum, uint32_T sampleNum, real_T ptsNorm[], real_T scale[], real_T cents[]);

#endif                                 // RTW_HEADER_Rpi_cam_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
