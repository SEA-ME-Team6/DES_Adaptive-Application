//
//  Adaptive_Event_send.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Adaptive_Event_send".
//
//  Model version              : 1.109
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Tue Mar 19 14:13:20 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#ifndef RTW_HEADER_Adaptive_Event_send_h_
#define RTW_HEADER_Adaptive_Event_send_h_
#include <stdbool.h>
#include <stdint.h>
#include "providedinterface_skeleton.h"
#include <stddef.h>
#include <memory>

// Class declaration for model Adaptive_Event_send
class Adaptive_Event_send final
{
  // public data and function members
 public:
  // Copy Constructor
  Adaptive_Event_send(Adaptive_Event_send const&) = delete;

  // Assignment Operator
  Adaptive_Event_send& operator= (Adaptive_Event_send const&) & = delete;

  // Move Constructor
  Adaptive_Event_send(Adaptive_Event_send &&) = delete;

  // Move Assignment Operator
  Adaptive_Event_send& operator= (Adaptive_Event_send &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Adaptive_Event_send();

  // Destructor
  ~Adaptive_Event_send();

  // private data and function members
 private:
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
//  '<Root>' : 'Adaptive_Event_send'

#endif                                 // RTW_HEADER_Adaptive_Event_send_h_
