//
//  LaneGuidance.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "LaneGuidance".
//
//  Model version              : 9.0
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Wed Jan 24 16:40:53 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: Intel->x86-64 (Linux 64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef RTW_HEADER_LaneGuidance_h_
#define RTW_HEADER_LaneGuidance_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "providedinterface_skeleton.h"
#include "requiredinterface_proxy.h"
#include <stddef.h>
#include "LaneGuidance_types.h"
#include <memory>

// Class declaration for model LaneGuidance
class LaneGuidance final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_LaneGuidance_T {
    double EventReceive;               // '<Root>/Event Receive'
    double EventReceive1;              // '<Root>/Event Receive1'
    double EventReceive2;              // '<Root>/Event Receive2'
    double EventReceive3;              // '<Root>/Event Receive3'
    double EventReceive4;              // '<Root>/Event Receive4'
    double EventReceive5;              // '<Root>/Event Receive5'
  };

  // Copy Constructor
  LaneGuidance(LaneGuidance const&) = delete;

  // Assignment Operator
  LaneGuidance& operator= (LaneGuidance const&) & = delete;

  // Move Constructor
  LaneGuidance(LaneGuidance &&) = delete;

  // Move Assignment Operator
  LaneGuidance& operator= (LaneGuidance &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  LaneGuidance();

  // Destructor
  ~LaneGuidance();

  // private data and function members
 private:
  // Block signals
  B_LaneGuidance_T LaneGuidance_B;
  std::shared_ptr<proxy::RequiredInterfaceProxy> RequiredPort;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;

  // private member function(s) for subsystem '<S1>/IfActionSS'
  static void LaneGuidance_IfActionSS(double rtu_In1, double *rty_Out1);

  // private member function(s) for subsystem '<Root>'
  void RequiredPortLeftLaneDistanceReceive(ara::com::SamplePtr< proxy::events::
    LeftLaneDistance::SampleType const > elementPtr);
  void RequiredPortLeftTurnIndicatorReceive(ara::com::SamplePtr< proxy::events::
    LeftTurnIndicator::SampleType const > elementPtr);
  void RequiredPortLeftCarInBlindSpotReceive(ara::com::SamplePtr< proxy::events::
    LeftCarInBlindSpot::SampleType const > elementPtr);
  void RequiredPortRightLaneDistanceReceive(ara::com::SamplePtr< proxy::events::
    RightLaneDistance::SampleType const > elementPtr);
  void RequiredPortRightTurnIndicatorReceive(ara::com::SamplePtr< proxy::events::
    RightTurnIndicator::SampleType const > elementPtr);
  void RequiredPortRightCarInBlindSpotReceive(ara::com::SamplePtr< proxy::events::
    RightCarInBlindSpot::SampleType const > elementPtr);
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
//  '<Root>' : 'LaneGuidance'
//  '<S1>'   : 'LaneGuidance/LaneGuidanceAlgorithm'
//  '<S2>'   : 'LaneGuidance/LaneGuidanceAlgorithm/IfActionSS'
//  '<S3>'   : 'LaneGuidance/LaneGuidanceAlgorithm/IfActionSS1'
//  '<S4>'   : 'LaneGuidance/LaneGuidanceAlgorithm/IfActionSS2'
//  '<S5>'   : 'LaneGuidance/LaneGuidanceAlgorithm/IfActionSS3'
//  '<S6>'   : 'LaneGuidance/LaneGuidanceAlgorithm/IfActionSS4'
//  '<S7>'   : 'LaneGuidance/LaneGuidanceAlgorithm/IfActionSS5'

#endif                                 // RTW_HEADER_LaneGuidance_h_
