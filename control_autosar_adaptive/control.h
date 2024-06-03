//
//  control.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "control".
//
//  Model version              : 2.4
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Mon Jun  3 13:52:06 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: AMD->x86-64 (Linux 64)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#ifndef control_h_
#define control_h_
#include <stdbool.h>
#include <stdint.h>
#include "requiredinterface_proxy.h"
#include <stddef.h>
#include <memory>

// Class declaration for model control
class control final
{
  // public data and function members
 public:
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
  static void terminate();

  // Constructor
  control();

  // Destructor
  ~control();

  // private data and function members
 private:
  std::shared_ptr<proxy::RequiredInterfaceProxy> RequiredPort;

  // private member function(s) for subsystem '<Root>'
  void RequiredPortSvcHandler(ara::com::ServiceHandleContainer< proxy::
    RequiredInterfaceProxy::HandleType > svcHandles, const ara::com::
    FindServiceHandle fsHandle);
  void RequiredPortLKASReceive(ara::com::SamplePtr< proxy::events::LKAS::
    SampleType const > elementPtr);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Gain' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination


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

#endif                                 // control_h_
