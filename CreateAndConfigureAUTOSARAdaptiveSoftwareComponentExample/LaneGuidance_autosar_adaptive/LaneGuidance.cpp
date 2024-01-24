//
//  LaneGuidance.cpp
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


#include "LaneGuidance.h"
#include <stdint.h>

//
// Output and update for action system:
//    '<S1>/IfActionSS'
//    '<S1>/IfActionSS1'
//    '<S1>/IfActionSS2'
//    '<S1>/IfActionSS3'
//    '<S1>/IfActionSS4'
//    '<S1>/IfActionSS5'
//
void LaneGuidance::LaneGuidance_IfActionSS(double rtu_In1, double *rty_Out1)
{
  // SignalConversion generated from: '<S2>/In1'
  *rty_Out1 = rtu_In1;
}

void LaneGuidance::RequiredPortLeftLaneDistanceReceive(ara::com::SamplePtr<
  proxy::events::LeftLaneDistance::SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive'
  LaneGuidance_B.EventReceive = *elementPtr;
}

void LaneGuidance::RequiredPortLeftTurnIndicatorReceive(ara::com::SamplePtr<
  proxy::events::LeftTurnIndicator::SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive1'
  LaneGuidance_B.EventReceive1 = *elementPtr;
}

void LaneGuidance::RequiredPortLeftCarInBlindSpotReceive(ara::com::SamplePtr<
  proxy::events::LeftCarInBlindSpot::SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive2'
  LaneGuidance_B.EventReceive2 = *elementPtr;
}

void LaneGuidance::RequiredPortRightLaneDistanceReceive(ara::com::SamplePtr<
  proxy::events::RightLaneDistance::SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive3'
  LaneGuidance_B.EventReceive3 = *elementPtr;
}

void LaneGuidance::RequiredPortRightTurnIndicatorReceive(ara::com::SamplePtr<
  proxy::events::RightTurnIndicator::SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive4'
  LaneGuidance_B.EventReceive4 = *elementPtr;
}

void LaneGuidance::RequiredPortRightCarInBlindSpotReceive(ara::com::SamplePtr<
  proxy::events::RightCarInBlindSpot::SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive5'
  LaneGuidance_B.EventReceive5 = *elementPtr;
}

// Model step function
void LaneGuidance::step()
{
  std::shared_ptr<ara::core::Result<size_t>> resultPtr;
  double rtb_Merge1;
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->LeftLaneDistance.GetNewSamples(std::move(std::bind
         (&LaneGuidance::RequiredPortLeftLaneDistanceReceive, this, std::
          placeholders::_1)), 1U));
    resultPtr->ValueOrThrow();
  }

  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->LeftTurnIndicator.GetNewSamples(std::move(std::bind
         (&LaneGuidance::RequiredPortLeftTurnIndicatorReceive, this, std::
          placeholders::_1)), 1U));
    resultPtr->ValueOrThrow();
  }

  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->LeftCarInBlindSpot.GetNewSamples(std::move(std::bind
         (&LaneGuidance::RequiredPortLeftCarInBlindSpotReceive, this, std::
          placeholders::_1)), 1U));
    resultPtr->ValueOrThrow();
  }

  // If: '<S1>/If' incorporates:
  //   Constant: '<S1>/Constant'
  //   Constant: '<S1>/Constant1'
  //   Constant: '<S1>/Constant2'

  if (LaneGuidance_B.EventReceive2 > 0.0) {
    // Outputs for IfAction SubSystem: '<S1>/IfActionSS' incorporates:
    //   ActionPort: '<S2>/Action Port'

    LaneGuidance_IfActionSS(1.0, &rtb_Merge1);

    // End of Outputs for SubSystem: '<S1>/IfActionSS'
  } else if ((LaneGuidance_B.EventReceive1 == 0.0) &&
             (LaneGuidance_B.EventReceive < 0.1)) {
    // Outputs for IfAction SubSystem: '<S1>/IfActionSS1' incorporates:
    //   ActionPort: '<S3>/Action Port'

    LaneGuidance_IfActionSS(0.0, &rtb_Merge1);

    // End of Outputs for SubSystem: '<S1>/IfActionSS1'
  } else {
    // Outputs for IfAction SubSystem: '<S1>/IfActionSS2' incorporates:
    //   ActionPort: '<S4>/Action Port'

    LaneGuidance_IfActionSS(1.0, &rtb_Merge1);

    // End of Outputs for SubSystem: '<S1>/IfActionSS2'
  }

  // End of If: '<S1>/If'

  // Send: '<Root>/Event Send'
  // Send event
  ProvidedPort->LeftHazardIndicator.Send(rtb_Merge1);
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->RightLaneDistance.GetNewSamples(std::move(std::bind
         (&LaneGuidance::RequiredPortRightLaneDistanceReceive, this, std::
          placeholders::_1)), 1U));
    resultPtr->ValueOrThrow();
  }

  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->RightTurnIndicator.GetNewSamples(std::move(std::bind
         (&LaneGuidance::RequiredPortRightTurnIndicatorReceive, this, std::
          placeholders::_1)), 1U));
    resultPtr->ValueOrThrow();
  }

  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->RightCarInBlindSpot.GetNewSamples(std::move(std::bind
         (&LaneGuidance::RequiredPortRightCarInBlindSpotReceive, this, std::
          placeholders::_1)), 1U));
    resultPtr->ValueOrThrow();
  }

  // If: '<S1>/If1' incorporates:
  //   Constant: '<S1>/Constant'
  //   Constant: '<S1>/Constant1'
  //   Constant: '<S1>/Constant2'

  if (LaneGuidance_B.EventReceive5 > 0.0) {
    // Outputs for IfAction SubSystem: '<S1>/IfActionSS3' incorporates:
    //   ActionPort: '<S5>/Action Port'

    LaneGuidance_IfActionSS(1.0, &rtb_Merge1);

    // End of Outputs for SubSystem: '<S1>/IfActionSS3'
  } else if ((LaneGuidance_B.EventReceive4 == 0.0) &&
             (LaneGuidance_B.EventReceive3 < 0.1)) {
    // Outputs for IfAction SubSystem: '<S1>/IfActionSS4' incorporates:
    //   ActionPort: '<S6>/Action Port'

    LaneGuidance_IfActionSS(0.0, &rtb_Merge1);

    // End of Outputs for SubSystem: '<S1>/IfActionSS4'
  } else {
    // Outputs for IfAction SubSystem: '<S1>/IfActionSS5' incorporates:
    //   ActionPort: '<S7>/Action Port'

    LaneGuidance_IfActionSS(1.0, &rtb_Merge1);

    // End of Outputs for SubSystem: '<S1>/IfActionSS5'
  }

  // End of If: '<S1>/If1'

  // Send: '<Root>/Event Send1'
  // Send event
  ProvidedPort->RightHazardIndicator.Send(rtb_Merge1);
}

// Model initialize function
void LaneGuidance::initialize()
{
  {
    ara::com::ServiceHandleContainer< proxy::RequiredInterfaceProxy::HandleType >
      handles;
    std::shared_ptr<ara::core::Result<ara::com::ServiceHandleContainer< proxy::
      RequiredInterfaceProxy::HandleType >>> resultPtr;

    // Initialize service provider instance - ProvidedPort
    ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::
      com::InstanceIdentifier(ara::core::StringView("2")), ara::com::
      MethodCallProcessingMode::kEventSingleThread);
    ProvidedPort->OfferService();

    // Initialize service requester instance - RequiredPort
    resultPtr = std::make_shared< ara::core::Result<ara::com::
      ServiceHandleContainer< proxy::RequiredInterfaceProxy::HandleType >> >
      (proxy::RequiredInterfaceProxy::FindService(ara::com::InstanceIdentifier
        (ara::core::StringView("1"))));
    if (resultPtr->HasValue()) {
      handles = resultPtr->Value();
      if (handles.size() > 0U) {
        RequiredPort = std::make_shared< proxy::RequiredInterfaceProxy >
          (*handles.begin());

        // Subscribe events
        RequiredPort->LeftCarInBlindSpot.Subscribe(1U);
        RequiredPort->LeftLaneDistance.Subscribe(1U);
        RequiredPort->LeftTurnIndicator.Subscribe(1U);
        RequiredPort->RightCarInBlindSpot.Subscribe(1U);
        RequiredPort->RightLaneDistance.Subscribe(1U);
        RequiredPort->RightTurnIndicator.Subscribe(1U);
      }
    }
  }
}

// Model terminate function
void LaneGuidance::terminate()
{
  ProvidedPort->StopOfferService();
}

// Constructor
LaneGuidance::LaneGuidance():
  LaneGuidance_B()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
LaneGuidance::~LaneGuidance() = default;
