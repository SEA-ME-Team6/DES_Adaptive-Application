//
//  ultrasonic.h
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


#ifndef ultrasonic_h_
#define ultrasonic_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "MW_Raspi_PulseIn.h"
#include "MW_gpio.h"
#include "linuxTimeLogger.h"
#include "providedinterface_skeleton.h"
#include <stddef.h>
#include "ultrasonic_types.h"
#include <memory>

// Class declaration for model ultrasonic
class ultrasonic final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_ultrasonic_T {
    sensors_raspberrypi_UltrasonicBlock_ultrasonic_T obj;// '<Root>/Ultrasonic Sensor' 
  };

  // Copy Constructor
  ultrasonic(ultrasonic const&) = delete;

  // Assignment Operator
  ultrasonic& operator= (ultrasonic const&) & = delete;

  // Move Constructor
  ultrasonic(ultrasonic &&) = delete;

  // Move Assignment Operator
  ultrasonic& operator= (ultrasonic &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  ultrasonic();

  // Destructor
  ~ultrasonic();

  // private data and function members
 private:
  // Block states
  DW_ultrasonic_T ultrasonic_DW;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;
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
//  '<Root>' : 'ultrasonic'
//  '<S1>'   : 'ultrasonic/MATLAB Function'

#endif                                 // ultrasonic_h_
