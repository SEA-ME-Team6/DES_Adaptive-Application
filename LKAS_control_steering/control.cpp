//
//  control.cpp
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


#include "control.h"
#include <stdint.h>

void control::RequiredPortLKASReceive(ara::com::SamplePtr< proxy::events::LKAS::
  SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive'
  rtDW.EventReceive = *elementPtr;
}

// Model step function
void control::step()
{
  std::shared_ptr<ara::core::Result<size_t>> resultPtr;
  double rtb_Gain;
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->LKAS.GetNewSamples(std::move(std::bind(&control::
          RequiredPortLKASReceive, this, std::placeholders::_1)), 1U));
    resultPtr->ValueOrThrow();
  }

  // Gain: '<Root>/Gain'
  rtb_Gain = 0.008 * rtDW.EventReceive;

  // Send: '<Root>/Event Send'
  // Send event
  ProvidedPort->Steering.Send(rtb_Gain);
}

// Model initialize function
void control::initialize()
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
        RequiredPort->LKAS.Subscribe(1U);
      }
    }
  }
}

// Model terminate function
void control::terminate()
{
  ProvidedPort->StopOfferService();
}

// Constructor
control::control():
  rtDW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
control::~control() = default;
