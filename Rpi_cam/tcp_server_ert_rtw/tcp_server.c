/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tcp_server.c
 *
 * Code generated for Simulink model 'tcp_server'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue May 28 16:07:19 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tcp_server.h"
#include "tcp_server_types.h"
#include "tcp_server_private.h"
#include "rtwtypes.h"
#include <math.h>

/* Block states (default storage) */
DW_tcp_server_T tcp_server_DW;

/* Real-time model */
static RT_MODEL_tcp_server_T tcp_server_M_;
RT_MODEL_tcp_server_T *const tcp_server_M = &tcp_server_M_;

/* Forward declaration for local functions */
static void tcp_server_SystemCore_setup(codertarget_raspi_internal_Ra_T *obj);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void tcp_server_SystemCore_setup(codertarget_raspi_internal_Ra_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T ipaddr[7];
  uint8_T isLittleEndian;
  static const char_T ipaddr_0[7] = "Server";

  /* Start for MATLABSystem: '<S1>/TCP//IP Receive' */
  obj->isInitialized = 1;
  obj->isServer_ = 1.0;
  for (i = 0; i < 7; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

  /* Start for MATLABSystem: '<S1>/TCP//IP Receive' */
  tmp = rt_roundd_snf(obj->isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  /* Start for MATLABSystem: '<S1>/TCP//IP Receive' */
  TCPStreamSetup(8000, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&isLittleEndian);
}

/* Model step function */
void tcp_server_step(void)
{
  real_T tmp;
  int16_T errorNo;
  uint16_T tmp_0;
  int8_T b_varargout_2;
  uint8_T b_varargout_1;

  /* MATLABSystem: '<S1>/TCP//IP Receive' */
  tmp = rt_roundd_snf(tcp_server_DW.obj.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  TCPStreamStepRecv(&b_varargout_1, &b_varargout_2, 1,
                    tcp_server_DW.obj.connStream_, &errorNo, tmp_0);

  /* End of MATLABSystem: '<S1>/TCP//IP Receive' */
}

/* Model initialize function */
void tcp_server_initialize(void)
{
  /* Start for MATLABSystem: '<S1>/TCP//IP Receive' */
  tcp_server_SystemCore_setup(&tcp_server_DW.obj);
}

/* Model terminate function */
void tcp_server_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
