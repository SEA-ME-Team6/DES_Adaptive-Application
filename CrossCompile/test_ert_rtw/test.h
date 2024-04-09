//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: test.h
//
// Code generated for Simulink model 'test'.
//
// Model version                  : 1.1
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Mar 26 12:59:12 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (32-bit)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include "rtwtypes.h"

// Class declaration for model test
class test final
{
  // public data and function members
 public:
  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T Out1;                       // '<Root>/Out1'
  };

  // Copy Constructor
  test(test const&) = delete;

  // Assignment Operator
  test& operator= (test const&) & = delete;

  // Move Constructor
  test(test &&) = delete;

  // Move Assignment Operator
  test& operator= (test &&) = delete;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  static void step();

  // Constructor
  test();

  // Destructor
  ~test();
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'test'

#endif                                 // RTW_HEADER_test_h_

//
// File trailer for generated code.
//
// [EOF]
//
