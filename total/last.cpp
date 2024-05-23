//
//  last.cpp
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


#include "last.h"
#include <stdint.h>

void last::RequiredPortSvcHandler(ara::com::ServiceHandleContainer< proxy::RequiredInterfaceProxy::HandleType > svcHandles, const ara::com::FindServiceHandle fsHandle)
{
	if ((!RequiredPort) && (svcHandles.size() > 0U)) {
		RequiredPort = std::make_shared< proxy::RequiredInterfaceProxy > (*svcHandles.begin());
		RequiredPort->In1.Subscribe(1U);
		// proxy::RequiredInterfaceProxy::StopFindService(fsHandle);
	}
}

void last::RequiredPortIn1Receive(ara::com::SamplePtr< proxy::events::In1::SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive'
  last_B.EventReceive = *elementPtr;
}

// Model step function
void last::step()
{
  std::shared_ptr<ara::core::Result<size_t>> resultPtr;
  double rtb_Gain;
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->In1.GetNewSamples(std::move(std::bind(&last::RequiredPortIn1Receive, this, std::placeholders::_1)), 1U));
    if (resultPtr->HasValue()) {
      resultPtr->Value();
    }
  }

  // Gain: '<S1>/Gain'
  rtb_Gain = 2.0 * last_B.EventReceive;

  // Send: '<Root>/Event Send'
  // Send event
  ProvidedPort->Out1.Send(rtb_Gain);
}

// Model initialize function
void last::initialize()
{
    ara::com::ServiceHandleContainer< proxy::RequiredInterfaceProxy::HandleType >
      handles;
    std::shared_ptr<ara::core::Result<ara::com::ServiceHandleContainer< proxy::
      RequiredInterfaceProxy::HandleType >>> resultPtr;

    // Initialize service provider instance - ProvidedPort
    ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::com::InstanceIdentifier(std::string("2")), ara::com::MethodCallProcessingMode::kEventSingleThread);
    ProvidedPort->OfferService();

	// Initialize service requester instance - RequiredPort
	proxy::RequiredInterfaceProxy::StartFindService(std::move(std::bind(&last::RequiredPortSvcHandler, this, std::placeholders::_1, std::placeholders::_2)), ara::com::InstanceIdentifier(std::string("1")));

}

// Model terminate function
void last::terminate()
{
  ProvidedPort->StopOfferService();
}

// Constructor
last::last():
  last_B()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
last::~last() = default;
