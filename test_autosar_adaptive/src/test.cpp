//
//  test.cpp
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

#include "test.h"
#include <stdint.h>
#include <string>

void test::RequiredPortIn1Receive(ara::com::SamplePtr< proxy::events::In1::SampleType const > elementPtr)
{
  // Receive: '<S1>/Event Receive'
  test_B.EventReceive = *elementPtr;
}

// Model step function
void test::step()
{
  std::shared_ptr<ara::core::Result<size_t>> resultPtr;
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->In1.GetNewSamples(std::move(std::bind(&test::RequiredPortIn1Receive, this, std::placeholders::_1)), 1U));
    resultPtr->ValueOrThrow();
  }

  // Send: '<S2>/Event Send'
  // Send event
  ProvidedPort->Out1.Send(test_B.EventReceive);
}

// Model initialize function
void test::initialize()
{
    ara::com::ServiceHandleContainer< proxy::RequiredInterfaceProxy::HandleType >handles;
    std::shared_ptr<ara::core::Result<ara::com::ServiceHandleContainer< proxy::RequiredInterfaceProxy::HandleType >>> resultPtr;

    // Initialize service provider instance - ProvidedPort
    ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::com::InstanceIdentifier(std::string("2")), ara::com::MethodCallProcessingMode::kEventSingleThread);
    ProvidedPort->OfferService();

    // Initialize service requester instance - RequiredPort
    resultPtr = std::make_shared< ara::core::Result<ara::com::ServiceHandleContainer< proxy::RequiredInterfaceProxy::HandleType >> >
      (proxy::RequiredInterfaceProxy::FindService(ara::com::InstanceIdentifier(std::string("1"))));
    if (resultPtr->HasValue()) {
      handles = resultPtr->Value();
      if (handles.size() > 0U) {
        RequiredPort = std::make_shared< proxy::RequiredInterfaceProxy >(*handles.begin());

        // Subscribe event
        RequiredPort->In1.Subscribe(1U);
      }
    }
}

// Model terminate function
// void test::terminate()
// {
//   ProvidedPort->StopOfferService();
// }

// Constructor
test::test():
  test_B()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
test::~test() = default;
