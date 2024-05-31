//
//  control.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "control".
//
//  Model version              : 1.3
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Fri May 31 11:38:43 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#ifndef RTW_HEADER_control_h_
#define RTW_HEADER_control_h_
#include <stdbool.h>
#include <stdint.h>
#include "providedinterface_skeleton.h"
#include "requiredinterface_proxy.h"
#include <stddef.h>
#include <memory>

// Class declaration for model control
class control final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    double EventReceive;               // '<Root>/Event Receive'
  };

  // Copy Constructor
  control(control const&) = delete;

  // Assignment Operator
  control& operator= (control const&) & = delete;

  // Move Constructor
  control(control &&) = delete;

  // Move Assignment Operator
  control& operator= (control &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  control();

  // Destructor
  ~control();

  // private data and function members
 private:
  // Block states
  DW rtDW;
  std::shared_ptr<proxy::RequiredInterfaceProxy> RequiredPort;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;

  // private member function(s) for subsystem '<Root>'
  void RequiredPortLKASReceive(ara::com::SamplePtr< proxy::events::LKAS::
    SampleType const > elementPtr);
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
//  '<Root>' : 'control'

#endif                                 // RTW_HEADER_control_h_
