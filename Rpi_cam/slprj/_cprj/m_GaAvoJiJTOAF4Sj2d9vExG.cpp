/* Include files */

#include "modelInterface.h"
#include "m_GaAvoJiJTOAF4Sj2d9vExG.hpp"
#include <string.h>

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI{ 1,        /* lineNo */
  "RaspiTCPSend",                      /* fcnName */
  "/home/seame-workstation09/Documents/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/raspberrypi/+codertarget/+raspi"
  "/+internal/RaspiTCPSend.p"          /* pathName */
};

static emlrtRSInfo b_emlrtRSI{ 1,      /* lineNo */
  "TCPSend",                           /* fcnName */
  "/home/seame-workstation09/Documents/MATLAB/SupportPackages/R2023b/toolbox/realtime/targets/linux/+codertarget/+linux/+blocks/TCP"
  "Send.p"                             /* pathName */
};

static emlrtRSInfo c_emlrtRSI{ 1,      /* lineNo */
  "TCPSend",                           /* fcnName */
  "/home/seame-workstation09/Documents/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/shared_linuxservices/+sharedlin"
  "ux/TCPSend.p"                       /* pathName */
};

static emlrtRSInfo d_emlrtRSI{ 1,      /* lineNo */
  "System",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"/* pathName */
};

static emlrtRSInfo e_emlrtRSI{ 1,      /* lineNo */
  "SystemProp",                        /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"/* pathName */
};

static emlrtRSInfo f_emlrtRSI{ 1,      /* lineNo */
  "SystemCore",                        /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"/* pathName */
};

static emlrtRSInfo g_emlrtRSI{ 12,     /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo h_emlrtRSI{ 31,     /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo i_emlrtRSI{ 33,     /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo j_emlrtRSI{ 38,     /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo k_emlrtRSI{ 19,     /* lineNo */
  "swapbytes",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datatypes/swapbytes.m"/* pathName */
};

static emlrtMCInfo emlrtMCI{ 1,        /* lineNo */
  1,                                   /* colNo */
  "SystemCore",                        /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"/* pName */
};

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance);
static void mw__internal__call__setup(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const emlrtStack *sp);
static codertarget_raspi_internal_RaspiTCPSend *RaspiTCPSend_RaspiTCPSend
  (codertarget_raspi_internal_RaspiTCPSend *obj);
static void SystemCore_setup(const emlrtStack *sp,
  codertarget_raspi_internal_RaspiTCPSend *obj);
static void SystemCore_checkTunablePropChange(const emlrtStack *sp,
  codertarget_raspi_internal_RaspiTCPSend *obj);
static void mw__internal__call__reset(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const emlrtStack *sp);
static void mw__internal__call__step(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const emlrtStack *sp, real_T b_u0);
static const mxArray *emlrt_marshallOut(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance);
static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance);
static void emlrt_marshallIn(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const emlrtStack *sp, const mxArray *u);
static codertarget_raspi_internal_RaspiTCPSend b_emlrt_marshallIn(const
  emlrtStack *sp, const mxArray *b_nullptr, const char_T *identifier);
static codertarget_raspi_internal_RaspiTCPSend c_emlrt_marshallIn(const
  emlrtStack *sp, const mxArray *u, const emlrtMsgIdentifier *parentId);
static int32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static uint8_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_nullptr, const char_T *identifier);
static void cgxe_mdl_set_sim_state(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const mxArray *st);
static const mxArray *message(const emlrtStack *sp, const mxArray *m1, const
  mxArray *m2, emlrtMCInfo *location);
static const mxArray *getString(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location);
static void error(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                  emlrtMCInfo *location);
static const mxArray *b_message(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location);
static int32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static uint8_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void init_simulink_io_address(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance)
{
  emlrtStack st{ NULL,                 /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  init_simulink_io_address(moduleInstance);
  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__call__setup(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_initialize(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance)
{
  emlrtStack st{ NULL,                 /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__call__reset(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_outputs(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance)
{
  emlrtStack st{ NULL,                 /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__call__step(moduleInstance, &st, *moduleInstance->u0);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_update(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)
{
}

static void cgxe_mdl_derivative(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)
{
}

static void cgxe_mdl_enable(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)
{
}

static void cgxe_mdl_disable(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)
{
}

static void cgxe_mdl_terminate(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance)
{
  cgxertSetGcb(moduleInstance->S, -1, -1);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void mw__internal__call__setup(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &g_emlrtRSI;
    RaspiTCPSend_RaspiTCPSend(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &h_emlrtRSI;
  SystemCore_setup(&st, &moduleInstance->sysobj);
}

static codertarget_raspi_internal_RaspiTCPSend *RaspiTCPSend_RaspiTCPSend
  (codertarget_raspi_internal_RaspiTCPSend *obj)
{
  codertarget_raspi_internal_RaspiTCPSend *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  b_obj = obj;
  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  b_obj->isLittleEnd_ = 0U;
  c_st.site = &c_emlrtRSI;
  d_st.site = &d_emlrtRSI;
  e_st.site = &e_emlrtRSI;
  d_st.site = &d_emlrtRSI;
  b_obj->TunablePropsChanged = false;
  e_st.site = &f_emlrtRSI;
  b_obj->isInitialized = 0;
  c_st.site = &c_emlrtRSI;
  return b_obj;
}

static void SystemCore_setup(const emlrtStack *sp,
  codertarget_raspi_internal_RaspiTCPSend *obj)
{
  static const int32_T iv[2]{ 1, 51 };

  static const int32_T iv1[2]{ 1, 51 };

  static const int32_T iv2[2]{ 1, 5 };

  static char_T b_u[51]{ 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's', 't',
    'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e', 'd',
    'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e', 'a',
    's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  static char_T d_u[5]{ 's', 'e', 't', 'u', 'p' };

  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[51];
  char_T c_u[5];
  st.prev = sp;
  st.tls = sp->tls;
  if (obj->isInitialized != 0) {
    for (i = 0; i < 51; i++) {
      u[i] = b_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 51, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 51; i++) {
      u[i] = b_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 51, m, &u[0]);
    emlrtAssign(&b_y, m);
    for (i = 0; i < 5; i++) {
      c_u[i] = d_u[i];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 5, m, &c_u[0]);
    emlrtAssign(&c_y, m);
    st.site = &f_emlrtRSI;
    error(&st, y, getString(&st, message(&st, b_y, c_y, &emlrtMCI), &emlrtMCI),
          &emlrtMCI);
  }

  obj->isInitialized = 1;
  st.site = &f_emlrtRSI;
  SystemCore_checkTunablePropChange(&st, obj);
  obj->TunablePropsChanged = false;
}

static void SystemCore_checkTunablePropChange(const emlrtStack *sp,
  codertarget_raspi_internal_RaspiTCPSend *obj)
{
  static const int32_T iv[2]{ 1, 44 };

  static const int32_T iv1[2]{ 1, 44 };

  static char_T b_u[44]{ 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's', 't',
    'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a', 'b',
    'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd', 'e',
    'g', 'e', 'n' };

  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[44];
  st.prev = sp;
  st.tls = sp->tls;
  if (obj->TunablePropsChanged) {
    for (i = 0; i < 44; i++) {
      u[i] = b_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 44, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 44; i++) {
      u[i] = b_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 44, m, &u[0]);
    emlrtAssign(&b_y, m);
    st.site = &f_emlrtRSI;
    error(&st, y, getString(&st, b_message(&st, b_y, &emlrtMCI), &emlrtMCI),
          &emlrtMCI);
  }
}

static void mw__internal__call__reset(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const emlrtStack *sp)
{
  static const int32_T iv[2]{ 1, 45 };

  static const int32_T iv1[2]{ 1, 44 };

  static const int32_T iv2[2]{ 1, 45 };

  static const int32_T iv3[2]{ 1, 44 };

  static const int32_T iv4[2]{ 1, 5 };

  static char_T c_u[45]{ 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's', 't',
    'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e', 'd',
    'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  static char_T d_u[44]{ 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's', 't',
    'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a', 'b',
    'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd', 'e',
    'g', 'e', 'n' };

  static char_T f_u[5]{ 'r', 'e', 's', 'e', 't' };

  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[45];
  char_T b_u[44];
  char_T e_u[5];
  boolean_T tunablePropChangedBeforeResetImpl;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &g_emlrtRSI;
    RaspiTCPSend_RaspiTCPSend(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &i_emlrtRSI;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i = 0; i < 45; i++) {
      u[i] = c_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 45; i++) {
      u[i] = c_u[i];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&c_y, m);
    for (i = 0; i < 5; i++) {
      e_u[i] = f_u[i];
    }

    e_y = NULL;
    m = emlrtCreateCharArray(2, &iv4[0]);
    emlrtInitCharArrayR2013a(&st, 5, m, &e_u[0]);
    emlrtAssign(&e_y, m);
    b_st.site = &f_emlrtRSI;
    error(&b_st, y, getString(&b_st, message(&b_st, c_y, e_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }

  tunablePropChangedBeforeResetImpl = moduleInstance->sysobj.TunablePropsChanged;
  if (static_cast<int32_T>(tunablePropChangedBeforeResetImpl) !=
      static_cast<int32_T>(moduleInstance->sysobj.TunablePropsChanged)) {
    for (i = 0; i < 44; i++) {
      b_u[i] = d_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&st, 44, m, &b_u[0]);
    emlrtAssign(&b_y, m);
    for (i = 0; i < 44; i++) {
      b_u[i] = d_u[i];
    }

    d_y = NULL;
    m = emlrtCreateCharArray(2, &iv3[0]);
    emlrtInitCharArrayR2013a(&st, 44, m, &b_u[0]);
    emlrtAssign(&d_y, m);
    b_st.site = &f_emlrtRSI;
    error(&b_st, b_y, getString(&b_st, b_message(&b_st, d_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }
}

static void mw__internal__call__step(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const emlrtStack *sp, real_T b_u0)
{
  static const int32_T iv[2]{ 1, 45 };

  static const int32_T iv1[2]{ 1, 45 };

  static const int32_T iv2[2]{ 1, 4 };

  static char_T b_u[45]{ 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's', 't',
    'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e', 'd',
    'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  static char_T d_u[4]{ 's', 't', 'e', 'p' };

  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  real_T x;
  int32_T b_j1;
  char_T u[45];
  char_T c_u[4];
  uint8_T b_y[8];
  uint8_T xtmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &g_emlrtRSI;
    RaspiTCPSend_RaspiTCPSend(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &j_emlrtRSI;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (b_j1 = 0; b_j1 < 45; b_j1++) {
      u[b_j1] = b_u[b_j1];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&y, m);
    for (b_j1 = 0; b_j1 < 45; b_j1++) {
      u[b_j1] = b_u[b_j1];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&c_y, m);
    for (b_j1 = 0; b_j1 < 4; b_j1++) {
      c_u[b_j1] = d_u[b_j1];
    }

    d_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(&st, 4, m, &c_u[0]);
    emlrtAssign(&d_y, m);
    b_st.site = &f_emlrtRSI;
    error(&b_st, y, getString(&b_st, message(&b_st, c_y, d_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }

  if (moduleInstance->sysobj.isInitialized != 1) {
    b_st.site = &f_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    SystemCore_setup(&c_st, &moduleInstance->sysobj);
  }

  b_st.site = &f_emlrtRSI;
  if (moduleInstance->sysobj.TunablePropsChanged) {
    moduleInstance->sysobj.TunablePropsChanged = false;
  }

  b_st.site = &f_emlrtRSI;
  if (moduleInstance->sysobj.isLittleEnd_ == 1) {
    c_st.site = &c_emlrtRSI;
    d_st.site = &k_emlrtRSI;
    memcpy((void *)&b_y[0], (void *)&b_u0, (uint32_T)((size_t)8 * sizeof(uint8_T)));
    for (b_j1 = 0; b_j1 < 4; b_j1++) {
      xtmp = b_y[b_j1];
      b_y[b_j1] = b_y[7 - b_j1];
      b_y[7 - b_j1] = xtmp;
    }

    d_st.site = &k_emlrtRSI;
    memcpy((void *)&x, (void *)&b_y[0], (uint32_T)((size_t)1 * sizeof(real_T)));
  }

  b_st.site = &f_emlrtRSI;
  SystemCore_checkTunablePropChange(&b_st, &moduleInstance->sysobj);
}

static const mxArray *emlrt_marshallOut(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance)
{
  static const char_T *sv[3]{ "isInitialized", "TunablePropsChanged",
    "isLittleEnd_" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *m;
  const mxArray *y;
  int32_T u;
  uint8_T c_u;
  boolean_T b_u;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 3, (const char_T **)&sv[0]));
  u = moduleInstance->sysobj.isInitialized;
  c_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *static_cast<int32_T *>(emlrtMxGetData(m)) = u;
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, "isInitialized", c_y, 0);
  b_u = moduleInstance->sysobj.TunablePropsChanged;
  d_y = NULL;
  m = emlrtCreateLogicalScalar(b_u);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(b_y, 0, "TunablePropsChanged", d_y, 1);
  c_u = moduleInstance->sysobj.isLittleEnd_;
  e_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *static_cast<uint8_T *>(emlrtMxGetData(m)) = c_u;
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(b_y, 0, "isLittleEnd_", e_y, 2);
  emlrtSetCell(y, 0, b_y);
  f_y = NULL;
  m = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&f_y, m);
  emlrtSetCell(y, 1, f_y);
  return y;
}

static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance)
{
  const mxArray *st;
  st = NULL;
  emlrtAssign(&st, emlrt_marshallOut(moduleInstance));
  return st;
}

static void emlrt_marshallIn(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const emlrtStack *sp, const mxArray *u)
{
  emlrtMsgIdentifier thisId;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  thisId.fIdentifier = "sysobj";
  moduleInstance->sysobj = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((void *)
    sp, &thisId, u, 0)), "sysobj");
  thisId.fIdentifier = "sysobj_not_empty";
  moduleInstance->sysobj_not_empty = g_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetCell((void *)sp, &thisId, u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
}

static codertarget_raspi_internal_RaspiTCPSend b_emlrt_marshallIn(const
  emlrtStack *sp, const mxArray *b_nullptr, const char_T *identifier)
{
  codertarget_raspi_internal_RaspiTCPSend y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static codertarget_raspi_internal_RaspiTCPSend c_emlrt_marshallIn(const
  emlrtStack *sp, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims{ 0 };

  static const char_T *fieldNames[3]{ "isInitialized", "TunablePropsChanged",
    "isLittleEnd_" };

  codertarget_raspi_internal_RaspiTCPSend y;
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 3, (const char_T **)
    &fieldNames[0], 0U, (const void *)&dims);
  thisId.fIdentifier = "isInitialized";
  y.isInitialized = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 0, "isInitialized")), &thisId);
  thisId.fIdentifier = "TunablePropsChanged";
  y.TunablePropsChanged = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 1, "TunablePropsChanged")), &thisId);
  thisId.fIdentifier = "isLittleEnd_";
  y.isLittleEnd_ = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 2, "isLittleEnd_")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static uint8_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  uint8_T y;
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_nullptr, const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static void cgxe_mdl_set_sim_state(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance, const mxArray *st)
{
  emlrtStack b_st{ NULL,               /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  b_st.tls = moduleInstance->emlrtRootTLSGlobal;
  emlrt_marshallIn(moduleInstance, &b_st, emlrtAlias(st));
  emlrtDestroyArray(&st);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *m1, const
  mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
    "message", true, location);
}

static const mxArray *getString(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "getString",
    true, location);
}

static void error(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                  emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 2, &pArrays[0], "error",
                        true, location);
}

static const mxArray *b_message(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "message",
    true, location);
}

static int32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{ 0 };

  int32_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "int32", false, 0U, (
    const void *)&dims);
  ret = *static_cast<int32_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{ 0 };

  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "logical", false, 0U, (
    const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static uint8_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{ 0 };

  uint8_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint8", false, 0U, (
    const void *)&dims);
  ret = *static_cast<uint8_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

static void init_simulink_io_address(InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S, int_T tid)
{
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S)
{
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S, int_T tid)
{
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S)
{
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static mxArray* getSimState_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) cgxe_mdl_get_sim_state(moduleInstance);
  return mxSS;
}

static void setSimState_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_set_sim_state(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S)
{
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S)
{
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S)
{
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S)
{
  InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *moduleInstance =
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG *)calloc(1, sizeof
    (InstanceStruct_GaAvoJiJTOAF4Sj2d9vExG));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_GaAvoJiJTOAF4Sj2d9vExG);
  ssSetmdlInitializeConditions(S, mdlInitialize_GaAvoJiJTOAF4Sj2d9vExG);
  ssSetmdlUpdate(S, mdlUpdate_GaAvoJiJTOAF4Sj2d9vExG);
  ssSetmdlDerivatives(S, mdlDerivatives_GaAvoJiJTOAF4Sj2d9vExG);
  ssSetmdlTerminate(S, mdlTerminate_GaAvoJiJTOAF4Sj2d9vExG);
  ssSetmdlEnable(S, mdlEnable_GaAvoJiJTOAF4Sj2d9vExG);
  ssSetmdlDisable(S, mdlDisable_GaAvoJiJTOAF4Sj2d9vExG);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S)
{
}

void method_dispatcher_GaAvoJiJTOAF4Sj2d9vExG(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_GaAvoJiJTOAF4Sj2d9vExG(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_GaAvoJiJTOAF4Sj2d9vExG(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_GaAvoJiJTOAF4Sj2d9vExG(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_GaAvoJiJTOAF4Sj2d9vExG(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: GaAvoJiJTOAF4Sj2d9vExG.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_GaAvoJiJTOAF4Sj2d9vExG_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  mxArray * elem_10;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateCellMatrix(1,1);
  elem_9 = mxCreateString("codertarget.raspi.internal.RaspiTCPSend");
  mxSetCell(elem_8,0,elem_9);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_10 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_10);
  return mxBIArgs;
}

mxArray *cgxe_GaAvoJiJTOAF4Sj2d9vExG_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("thirdPartyLibs");
  mxArray* incompatibleSymbol = mxCreateString(
    "codertarget.raspi.internal.RaspiTCPSend");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
