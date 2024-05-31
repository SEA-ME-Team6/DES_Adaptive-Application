//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ultrasonic.h
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
#ifndef RTW_HEADER_ultrasonic_h_
#define RTW_HEADER_ultrasonic_h_
#include "rtwtypes.h"
#include "MW_TCPSendReceive.h"
#include "MW_Raspi_PulseIn.h"
#include "MW_gpio.h"
#include "linuxTimeLogger.h"
#include "ultrasonic_types.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block states (default storage) for system '<Root>'
struct DW_ultrasonic_T {
  codertarget_raspi_internal_RaspiTCPSend_ultrasonic_T obj;// '<Root>/TCP//IP Send1' 
  sensors_raspberrypi_UltrasonicBlock_ultrasonic_T obj_l;// '<Root>/Ultrasonic Sensor1' 
};

// Parameters (default storage)
struct P_ultrasonic_T_ {
  real_T UltrasonicSensor1_SampleTime; // Expression: -1
                                          //  Referenced by: '<Root>/Ultrasonic Sensor1'

};

// Real-time Model Data Structure
struct tag_RTM_ultrasonic_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_ultrasonic_T ultrasonic_P;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_ultrasonic_T ultrasonic_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void ultrasonic_initialize(void);
  extern void ultrasonic_step(void);
  extern void ultrasonic_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_ultrasonic_T *const ultrasonic_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
//  '<S1>'   : 'ultrasonic/MATLAB Function'

#endif                                 // RTW_HEADER_ultrasonic_h_

//
// File trailer for generated code.
//
// [EOF]
//
