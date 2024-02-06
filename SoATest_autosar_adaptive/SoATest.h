//
//  SoATest.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "SoATest".
//
//  Model version              : 1.2
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Tue Feb  6 15:42:31 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: AMD->x86-64 (Linux 64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef RTW_HEADER_SoATest_h_
#define RTW_HEADER_SoATest_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "providedinterface_skeleton.h"
#include <stddef.h>
#include "SoATest_types.h"
#include <memory>

// Class declaration for model SoATest
class SoATest final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B {
    double EventReceive;               // '<S1>/Event Receive'
  };

  // Block states (default storage) for system '<Root>'
  struct DW {
    Buffer_real_T Queue_InsertedFor_Receiver_at_inport_0_Queue;// synthesized block 
  };

  // Invariant block signals (default storage)
  struct ConstB {
    double Gain;                       // '<S2>/Gain'
  };

  // Copy Constructor
  SoATest(SoATest const&) = delete;

  // Assignment Operator
  SoATest& operator= (SoATest const&) & = delete;

  // Move Constructor
  SoATest(SoATest &&) = delete;

  // Move Assignment Operator
  SoATest& operator= (SoATest &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  SoATest();

  // Destructor
  ~SoATest();

  // private data and function members
 private:
  // Block signals
  B rtB;

  // Block states
  DW rtDW;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;

  // private member function(s) for subsystem '<Root>'
  Msg_real_T SoATest_createMsg(const double *data);
  bool SoATest_push(Buffer_real_T *q, const Msg_real_T *element);
  int32_t EventReceive_SendData(const double *data);
  bool SoATest_pop(Buffer_real_T *q, Msg_real_T *elementOut);
  int32_t EventReceive_RecvData(double *data);
};

extern const SoATest::ConstB rtConstB; // constant block i/o

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
//  '<Root>' : 'SoATest'
//  '<S1>'   : 'SoATest/Receiver'
//  '<S2>'   : 'SoATest/Sender'

#endif                                 // RTW_HEADER_SoATest_h_
