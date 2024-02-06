//
//  SoATest.cpp
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


#include "SoATest.h"
#include <stdint.h>
#include "SoATest_types.h"
#include <stdbool.h>

Msg_real_T SoATest::SoATest_createMsg(const double *data)
{
  Msg_real_T msg;

  // DiscreteEventSubgraph generated from: '<Root>/Receiver'
  msg.fData = *data;
  return msg;
}

bool SoATest::SoATest_push(Buffer_real_T *q, const Msg_real_T *element)
{
  // Queue generated from: '<Root>/Receiver'
  q->fMsg = *element;
  q->fOccupied = true;
  return true;
}

int32_t SoATest::EventReceive_SendData(const double *data)
{
  Msg_real_T msg;
  int32_t status{ 1 };

  // DiscreteEventSubgraph generated from: '<Root>/Receiver' incorporates:
  //   Send: '<S2>/Event Send'

  msg = SoATest_createMsg(data);

  // Queue generated from: '<Root>/Receiver' incorporates:
  //   DiscreteEventSubgraph generated from: '<Root>/Receiver'

  if (SoATest_push(&rtDW.Queue_InsertedFor_Receiver_at_inport_0_Queue, &msg)) {
    status = 0;
  }

  // End of Queue generated from: '<Root>/Receiver'
  return status;
}

bool SoATest::SoATest_pop(Buffer_real_T *q, Msg_real_T *elementOut)
{
  bool isPop;

  // Queue generated from: '<Root>/Receiver'
  if (!q->fOccupied) {
    isPop = false;
  } else {
    *elementOut = q->fMsg;
    q->fOccupied = false;
    isPop = true;
  }

  // End of Queue generated from: '<Root>/Receiver'
  return isPop;
}

int32_t SoATest::EventReceive_RecvData(double *data)
{
  Msg_real_T msg;
  int32_t status{ 1 };

  // Queue generated from: '<Root>/Receiver' incorporates:
  //   DiscreteEventSubgraph generated from: '<Root>/Receiver'

  if (SoATest_pop(&rtDW.Queue_InsertedFor_Receiver_at_inport_0_Queue, &msg)) {
    status = 0;
    *data = msg.fData;
  }

  // End of Queue generated from: '<Root>/Receiver'
  return status;
}

// Model step function
void SoATest::step()
{
  double rtb_Gain;

  // Send: '<S2>/Event Send'
  EventReceive_SendData(&rtConstB.Gain);

  // Receive: '<S1>/Event Receive'
  EventReceive_RecvData(&rtB.EventReceive);

  // Gain: '<S1>/Gain'
  rtb_Gain = 4.0 * rtB.EventReceive;

  // Send: '<S1>/Event Send'
  // Send event
  ProvidedPort->Out1.Send(rtb_Gain);
}

// Model initialize function
void SoATest::initialize()
{
  // Initialize service provider instance - ProvidedPort
  ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::
    com::InstanceIdentifier(ara::core::StringView("1")), ara::com::
    MethodCallProcessingMode::kEventSingleThread);
  ProvidedPort->OfferService();
}

// Model terminate function
void SoATest::terminate()
{
  ProvidedPort->StopOfferService();
}

// Constructor
SoATest::SoATest():
  rtB(),
  rtDW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
SoATest::~SoATest() = default;
