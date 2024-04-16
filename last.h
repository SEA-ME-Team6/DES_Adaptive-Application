//
//  last.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "last".
//
//  Model version              : 1.3
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Fri Apr 12 15:18:48 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: Intel->x86-64 (Windows64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef last_h_
#define last_h_
#include <stdbool.h>
#include <stdint.h>
// #include "complex_types.h"
#include "providedinterface_skeleton.h"
#include "requiredinterface_proxy.h"
#include <stddef.h>
#include "last_types.h"
#include <memory>
#include "ara/core/string_view.h"

// Class declaration for model last
class last final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_last_T {
    double EventReceive;               // '<Root>/Event Receive'
  };

  // Copy Constructor
  last(last const&) = delete;

  // Assignment Operator
  last& operator= (last const&) & = delete;

  // Move Constructor
  last(last &&) = delete;

  // Move Assignment Operator
  last& operator= (last &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  last();

  // Destructor
  ~last();

  // private data and function members
 private:
  // Block signals
  B_last_T last_B;
  std::shared_ptr<proxy::RequiredInterfaceProxy> RequiredPort;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;

  // private member function(s) for subsystem '<Root>'
  void RequiredPortIn1Receive(ara::com::SamplePtr< proxy::events::In1::
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
//  '<Root>' : 'last'
//  '<S1>'   : 'last/Subsystem'

#endif                                 // last_h_
