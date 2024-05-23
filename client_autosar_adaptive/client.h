//
//  client.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "client".
//
//  Model version              : 1.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Thu May 23 14:43:32 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: AMD->x86-64 (Linux 64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef client_h_
#define client_h_
#include <stdbool.h>
#include <stdint.h>
// #include "complex_types.h"
#include "requiredinterface_proxy.h"
#include <stddef.h>
#include "client_types.h"
#include <memory>

// Class declaration for model client
class client final
{
  // public data and function members
 public:
  // Copy Constructor
  client(client const&) = delete;

  // Assignment Operator
  client& operator= (client const&) & = delete;

  // Move Constructor
  client(client &&) = delete;

  // Move Assignment Operator
  client& operator= (client &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  client();

  // Destructor
  ~client();

  // private data and function members
 private:
  std::shared_ptr<proxy::RequiredInterfaceProxy> RequiredPort;

  // private member function(s) for subsystem '<Root>'
  void RequiredPortSvcHandler(ara::com::ServiceHandleContainer< proxy::
    RequiredInterfaceProxy::HandleType > svcHandles, const ara::com::
    FindServiceHandle fsHandle);
  void RequiredPortIn1Receive(ara::com::SamplePtr< proxy::events::In1::
    SampleType const > elementPtr);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
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
//  '<Root>' : 'client'

#endif                                 // client_h_
