//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: test.cpp
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
#include "test.h"

// Model step function
void test::step()
{
  // (no output/update code required)
}

// Model initialize function
void test::initialize()
{
  // ConstCode for Outport: '<Root>/Out1'
  rtY.Out1 = 5.0;
}

// Constructor
test::test():
  rtY()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
test::~test() = default;

//
// File trailer for generated code.
//
// [EOF]
//
