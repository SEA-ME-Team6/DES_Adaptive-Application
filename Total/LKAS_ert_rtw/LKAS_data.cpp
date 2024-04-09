//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: LKAS_data.cpp
//
// Code generated for Simulink model 'LKAS'.
//
// Model version                  : 12.33
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Feb 28 11:59:13 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Emulation hardware selection:
//    Differs from embedded hardware (MATLAB Host)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "LKAS.h"

// Block parameters (default storage)
P rtP = {
  // Mask Parameter: PIDController_D
  //  Referenced by: '<S28>/Derivative Gain'

  0.012,

  // Mask Parameter: PIDController_I
  //  Referenced by: '<S31>/Integral Gain'

  0.02,

  // Mask Parameter: PIDController_InitialConditionForFilter
  //  Referenced by: '<S29>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForIntegrator
  //  Referenced by: '<S34>/Integrator'

  0.0,

  // Mask Parameter: PIDController_Kb
  //  Referenced by: '<S27>/Kb'

  1.0,

  // Mask Parameter: PIDController_LowerSaturationLimit
  //  Referenced by: '<S41>/Saturation'

  -1.5707963267948966,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S37>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S39>/Proportional Gain'

  0.015,

  // Mask Parameter: PIDController_UpperSaturationLimit
  //  Referenced by: '<S41>/Saturation'

  1.5707963267948966,

  // Mask Parameter: EstimateGeometricTransformation_distanceAlg
  //  Referenced by: '<S2>/Estimate Geometric Transformation'

  2.5,

  // Mask Parameter: EstimateGeometricTransformation_sampleNum
  //  Referenced by: '<S2>/Estimate Geometric Transformation'

  500U,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S34>/Integrator'

  0.2,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S29>/Filter'

  0.2
};

//
// File trailer for generated code.
//
// [EOF]
//
