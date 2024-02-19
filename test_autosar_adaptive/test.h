//
//  test.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "test".
//
//  Model version              : 1.3
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Tue Feb 13 13:02:19 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: Intel->x86-64 (Windows64)
//  Code generation objective: MISRA C:2012 guidelines
//  Validation result: Not run


#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <stdbool.h>
#include <stdint.h>
// #include "complex_types.h"
// #include "providedinterface_skeleton.h"
// #include "requiredinterface_proxy.h"
#include "test_types.h"
#include <stddef.h>
#include <memory>

// Class declaration for model test
class test final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_test_T {
    double EventReceive;               // '<S1>/Event Receive'
  };

  // Copy Constructor
  test(test const&) = delete;

  // Assignment Operator
  test& operator= (test const&) & = delete;

  // Move Constructor
  test(test &&) = delete;

  // Move Assignment Operator
  test& operator= (test &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  // void step();

  // model terminate function
  // void terminate();

  // Constructor
  test();

  // Destructor
  ~test();

  // private data and function members
 private:
  // Block signals
  B_test_T test_B;
  // std::shared_ptr<proxy::RequiredInterfaceProxy> RequiredPort;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;

  // private member function(s) for subsystem '<Root>'
  // void RequiredPortIn1Receive(ara::com::SamplePtr< proxy::events::In1::
  //   SampleType const > elementPtr);
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
//  '<S1>'   : 'test/Subsystem'
//  '<S2>'   : 'test/Subsystem1'

#endif                                 // RTW_HEADER_test_h_
