//
//  ultrasonic.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "ultrasonic".
//
//  Model version              : 1.8
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Fri May 31 12:04:09 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#ifndef RTW_HEADER_ultrasonic_h_
#define RTW_HEADER_ultrasonic_h_
#include <stdbool.h>
#include <stdint.h>
#include "MW_Raspi_PulseIn.h"
#include "MW_gpio.h"
#include "linuxTimeLogger.h"
#include "providedinterface_skeleton.h"
#include <stddef.h>
#include <memory>
#ifndef struct_sensors_raspberrypi_UltrasonicBlock
#define struct_sensors_raspberrypi_UltrasonicBlock

struct sensors_raspberrypi_UltrasonicBlock
{
  bool matlabCodegenIsDeleted;
  int32_t isInitialized;
  bool isSetupComplete;
  double SampleTime;
};

#endif                            // struct_sensors_raspberrypi_UltrasonicBlock

// Class declaration for model ultrasonic
class ultrasonic final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    sensors_raspberrypi_UltrasonicBlock obj;// '<Root>/Ultrasonic Sensor'
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
  DW rtDW;
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

#endif                                 // RTW_HEADER_ultrasonic_h_
