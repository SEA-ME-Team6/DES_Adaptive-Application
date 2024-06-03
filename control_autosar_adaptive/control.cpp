//
//  control.cpp
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


#include "control.h"
#include <stdint.h>

void control::RequiredPortSvcHandler(ara::com::ServiceHandleContainer< proxy::
  RequiredInterfaceProxy::HandleType > svcHandles, const ara::com::
  FindServiceHandle fsHandle)
{
  if ((!RequiredPort) && (svcHandles.size() > 0U)) {
    RequiredPort = std::make_shared< proxy::RequiredInterfaceProxy >
      (*svcHandles.begin());
    RequiredPort->LKAS.Subscribe(1U);
    proxy::RequiredInterfaceProxy::StopFindService(fsHandle);
  }
}

void control::RequiredPortLKASReceive(ara::com::SamplePtr< proxy::events::LKAS::
  SampleType const > elementPtr)
{
  *elementPtr;
}

// Model step function
void control::step()
{
  std::shared_ptr<ara::core::Result<size_t>> resultPtr;
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->LKAS.GetNewSamples(std::move(std::bind(&control::
          RequiredPortLKASReceive, this, std::placeholders::_1)), 1U));
    if (resultPtr->HasValue()) {
      resultPtr->Value();
    }
  }
}

// Model initialize function
void control::initialize()
{
  // Initialize service requester instance - RequiredPort
  proxy::RequiredInterfaceProxy::StartFindService(std::move(std::bind(&control::
    RequiredPortSvcHandler, this, std::placeholders::_1, std::placeholders::_2)),
    ara::com::InstanceIdentifier(ara::core::StringView("1")));
}

// Model terminate function
void control::terminate()
{
  // (no terminate code required)
}

// Constructor
control::control()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
control::~control() = default;
