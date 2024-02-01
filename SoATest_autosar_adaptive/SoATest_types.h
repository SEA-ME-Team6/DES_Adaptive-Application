//
//  SoATest_types.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "SoATest".
//
//  Model version              : 1.1
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Thu Feb  1 16:12:33 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: Intel->x86-64 (Windows64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef RTW_HEADER_SoATest_types_h_
#define RTW_HEADER_SoATest_types_h_
#include <stdint.h>
#include <stdbool.h>
#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

enum class QueuePolicy_T
  : int32_t {
  MSG_QUEUE_UNUSED = -1,               // Default value
  MSG_FIFO_QUEUE,
  MSG_LIFO_QUEUE,
  MSG_PRIORITY_QUEUE
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_real_T_
#define DEFINED_TYPEDEF_FOR_Msg_real_T_

struct Msg_real_T
{
  double fData;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Buffer_real_T_
#define DEFINED_TYPEDEF_FOR_Buffer_real_T_

struct Buffer_real_T
{
  bool fOccupied;
  Msg_real_T fMsg;
};

#endif
#endif                                 // RTW_HEADER_SoATest_types_h_
