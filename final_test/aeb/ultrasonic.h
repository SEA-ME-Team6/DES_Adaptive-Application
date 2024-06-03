//
//  ultrasonic.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "ultrasonic".
//
//  Model version              : 2.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Mon Jun  3 22:46:50 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#ifndef ultrasonic_h_
#define ultrasonic_h_
#include <stdbool.h>
#include <stdint.h>
#include <cmath>
#include "MW_Raspi_PulseIn.h"
#include "MW_gpio.h"
#include "linuxTimeLogger.h"
#include "MW_TCPSendReceive.h"
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

#ifndef struct_codertarget_raspi_internal_RaspiTCPReceive
#define struct_codertarget_raspi_internal_RaspiTCPReceive

struct codertarget_raspi_internal_RaspiTCPReceive
{
  int32_t isInitialized;
  uint16_t connStream_;
  double isServer_;
};

#endif                     // struct_codertarget_raspi_internal_RaspiTCPReceive

// Class declaration for model ultrasonic
class ultrasonic final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    codertarget_raspi_internal_RaspiTCPReceive obj_l;// '<Root>/TCP//IP Receive' 
    sensors_raspberrypi_UltrasonicBlock obj;// '<S1>/Ultrasonic Sensor'
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

  // private member function(s) for subsystem '<Root>'
  void SystemCore_setup(codertarget_raspi_internal_RaspiTCPReceive *obj);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination


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
//  '<S1>'   : 'ultrasonic/Enabled Subsystem'
//  '<S2>'   : 'ultrasonic/Enabled Subsystem/MATLAB Function'

#endif                                 // ultrasonic_h_
