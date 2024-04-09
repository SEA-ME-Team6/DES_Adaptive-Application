/* Include files */

#include "Adaptive_Event_send_sfun.h"
#include "c10_Adaptive_Event_send.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
const int32_T CALL_EVENT{ -1 };

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c10_emlrtMCI{ 122,  /* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c10_b_emlrtMCI{ 18, /* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/mean.m"/* pName */
};

static emlrtMCInfo c10_c_emlrtMCI{ 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c10_d_emlrtMCI{ 28, /* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c10_e_emlrtMCI{ 134,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRSInfo c10_emlrtRSI{ 35,   /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c10_b_emlrtRSI{ 138,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c10_c_emlrtRSI{ 253,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c10_d_emlrtRSI{ 254,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c10_e_emlrtRSI{ 255,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c10_f_emlrtRSI{ 42, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c10_g_emlrtRSI{ 15, /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo c10_h_emlrtRSI{ 44, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c10_i_emlrtRSI{ 79, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c10_j_emlrtRSI{ 20, /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c10_k_emlrtRSI{ 25, /* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Adaptive_Event_send:120"           /* pathName */
};

static emlrtRSInfo c10_m_emlrtRSI{ 73, /* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Adaptive_Event_send:120"           /* pathName */
};

static emlrtRSInfo c10_o_emlrtRSI{ 74, /* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Adaptive_Event_send:120"           /* pathName */
};

static emlrtRSInfo c10_p_emlrtRSI{ 69, /* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Adaptive_Event_send:120"           /* pathName */
};

static emlrtRSInfo c10_q_emlrtRSI{ 70, /* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Adaptive_Event_send:120"           /* pathName */
};

static emlrtRSInfo c10_r_emlrtRSI{ 100,/* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Adaptive_Event_send:120"           /* pathName */
};

static emlrtRSInfo c10_s_emlrtRSI{ 128,/* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Adaptive_Event_send:120"           /* pathName */
};

static emlrtRTEInfo c10_emlrtRTEI{ 36, /* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c10_b_emlrtRTEI{ 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c10_c_emlrtRTEI{ 47,/* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_d_emlrtRTEI{ 47,/* lineNo */
  57,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_e_emlrtRTEI{ 47,/* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_f_emlrtRTEI{ 47,/* lineNo */
  83,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_g_emlrtRTEI{ 47,/* lineNo */
  114,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_h_emlrtRTEI{ 48,/* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_i_emlrtRTEI{ 50,/* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_j_emlrtRTEI{ 50,/* lineNo */
  84,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_k_emlrtRTEI{ 50,/* lineNo */
  116,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_m_emlrtRTEI{ 51,/* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_o_emlrtRTEI{ 73,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_p_emlrtRTEI{ 44,/* lineNo */
  18,                                  /* colNo */
  "minOrMax",                          /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pName */
};

static emlrtRTEInfo c10_q_emlrtRTEI{ 69,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_r_emlrtRTEI{ 96,/* lineNo */
  40,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_s_emlrtRTEI{ 96,/* lineNo */
  66,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_t_emlrtRTEI{ 96,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_u_emlrtRTEI{ 96,/* lineNo */
  92,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_v_emlrtRTEI{ 96,/* lineNo */
  119,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_w_emlrtRTEI{ 97,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_x_emlrtRTEI{ 100,/* lineNo */
  25,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_y_emlrtRTEI{ 124,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_ab_emlrtRTEI{ 124,/* lineNo */
  65,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_bb_emlrtRTEI{ 124,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_cb_emlrtRTEI{ 124,/* lineNo */
  91,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_db_emlrtRTEI{ 124,/* lineNo */
  118,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_eb_emlrtRTEI{ 125,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_fb_emlrtRTEI{ 128,/* lineNo */
  25,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_gb_emlrtRTEI{ 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c10_hb_emlrtRTEI{ 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c10_ib_emlrtRTEI{ 138,/* lineNo */
  10,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c10_jb_emlrtRTEI{ 138,/* lineNo */
  12,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtBCInfo c10_emlrtBCI{ -1,   /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  48,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_b_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  70,                                  /* colNo */
  "good_lefty_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_c_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  50,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_d_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  73,                                  /* colNo */
  "good_righty_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_e_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  58,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_f_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  81,                                  /* colNo */
  "good_righty_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_g_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  57,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_h_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  84,                                  /* colNo */
  "good_righty_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_i_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  136,                                 /* lineNo */
  56,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_j_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  136,                                 /* lineNo */
  78,                                  /* colNo */
  "good_lefty_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_k_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  57,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_m_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  83,                                  /* colNo */
  "good_lefty_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_o_emlrtBCI{ 1,  /* iFirst */
  100000,                              /* iLast */
  57,                                  /* lineNo */
  21,                                  /* colNo */
  "left_lane_index",                   /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c10_p_emlrtBCI{ 1,  /* iFirst */
  100000,                              /* iLast */
  136,                                 /* lineNo */
  29,                                  /* colNo */
  "left_lane_index",                   /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c10_q_emlrtBCI{ 1,  /* iFirst */
  100000,                              /* iLast */
  62,                                  /* lineNo */
  22,                                  /* colNo */
  "right_lane_index",                  /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c10_r_emlrtBCI{ 1,  /* iFirst */
  100000,                              /* iLast */
  108,                                 /* lineNo */
  30,                                  /* colNo */
  "right_lane_index",                  /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  3                                    /* checkKind */
};

static emlrtECInfo c10_emlrtECI{ -1,   /* nDims */
  47,                                  /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_b_emlrtECI{ 1,  /* nDims */
  47,                                  /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_c_emlrtECI{ -1, /* nDims */
  48,                                  /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_d_emlrtECI{ 1,  /* nDims */
  48,                                  /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_e_emlrtECI{ -1, /* nDims */
  50,                                  /* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_f_emlrtECI{ 1,  /* nDims */
  50,                                  /* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_g_emlrtECI{ -1, /* nDims */
  51,                                  /* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_h_emlrtECI{ 1,  /* nDims */
  51,                                  /* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_i_emlrtECI{ -1, /* nDims */
  96,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_j_emlrtECI{ 1,  /* nDims */
  96,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_k_emlrtECI{ -1, /* nDims */
  97,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_m_emlrtECI{ 1,  /* nDims */
  97,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_kb_emlrtRTEI{ 107,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_o_emlrtECI{ -1, /* nDims */
  124,                                 /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_p_emlrtECI{ 1,  /* nDims */
  124,                                 /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_q_emlrtECI{ -1, /* nDims */
  125,                                 /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtECInfo c10_r_emlrtECI{ 1,  /* nDims */
  125,                                 /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtRTEInfo c10_mb_emlrtRTEI{ 135,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120"           /* pName */
};

static emlrtBCInfo c10_s_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  30,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_t_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  30,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_u_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  31,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_v_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  31,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_w_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  39,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_x_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  38,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_y_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  39,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_ab_emlrtBCI{ -1,/* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  38,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Adaptive_Event_send:120",          /* pName */
  0                                    /* checkKind */
};

static char_T c10_cv[36]{ 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b',
  'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p',
  'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

/* Function Declarations */
static void initialize_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void initialize_params_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void mdl_start_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void mdl_terminate_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void enable_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void disable_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void sf_gateway_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void ext_mode_exec_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void c10_do_animation_call_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void set_sim_state_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance, const mxArray *c10_st);
static void initSimStructsc10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void initSubchartIOPointersc10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance);
static void c10_eml_find(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
  boolean_T c10_x[307200], int32_T c10_i_data[], int32_T c10_i_size[1], int32_T
  c10_j_data[], int32_T c10_j_size[1]);
static void c10_indexShapeCheck(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance);
static real_T c10_mean(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
  const emlrtStack *c10_sp, real_T c10_x_data[], int32_T c10_x_size[1]);
static real_T c10_sumColumnB(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, real_T c10_x_data[], int32_T c10_vlen);
static real_T c10_sumColumnB4(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, real_T c10_x_data[], int32_T c10_vstart);
static real_T c10_b_sumColumnB(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, real_T c10_x_data[], int32_T c10_vlen, int32_T c10_vstart);
static real_T c10_maximum(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
  const emlrtStack *c10_sp, real_T c10_x_data[], int32_T c10_x_size[1]);
static real_T c10_emlrt_marshallIn(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, const mxArray *c10_nullptr, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static uint8_T c10_c_emlrt_marshallIn(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, const mxArray *c10_nullptr, const char_T *c10_identifier);
static uint8_T c10_d_emlrt_marshallIn(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_and(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
                    boolean_T c10_b_in1_data[], int32_T c10_in1_size[1],
                    boolean_T c10_b_in2_data[], int32_T c10_in2_size[1],
                    boolean_T c10_in3_data[], int32_T c10_in3_size[1]);
static void c10_b_and(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
                      boolean_T c10_b_in1_data[], int32_T c10_in1_size[1],
                      boolean_T c10_b_in2_data[], int32_T c10_in2_size[1]);
static int32_T c10_div_nzp_s32(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, int32_T c10_numerator, int32_T c10_denominator, int32_T
  c10_EMLOvCount_src_loc, uint32_T c10_ssid_src_loc, int32_T c10_offset_src_loc,
  int32_T c10_length_src_loc);
static void init_dsm_address_info(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
  sf_is_first_init_cond(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c10_doneDoubleBufferReInit = false;
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
}

static void mdl_start_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
}

static void mdl_setup_runtime_resources_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
  sfSetAnimationVectors(chartInstance->S, chartInstance->c10_JITStateAnimation,
                        chartInstance->c10_JITTransitionAnimation);
}

static void mdl_cleanup_runtime_resources_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
}

static void enable_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
  emlrtStack c10_b_st;
  emlrtStack c10_c_st;
  emlrtStack c10_d_st;
  emlrtStack c10_st{ NULL,             /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c10_count_left;
  real_T c10_count_right;
  real_T c10_win_y_high;
  real_T c10_win_y_low;
  real_T c10_x_current;
  real_T c10_x_location;
  real_T c10_y_current;
  int32_T c10_b_tmp_size[1];
  int32_T c10_c_tmp_size[1];
  int32_T c10_d_tmp_size[1];
  int32_T c10_e_tmp_size[1];
  int32_T c10_f_tmp_size[1];
  int32_T c10_g_tmp_size[1];
  int32_T c10_h_tmp_size[1];
  int32_T c10_i_tmp_size[1];
  int32_T c10_ii_size[1];
  int32_T c10_j_tmp_size[1];
  int32_T c10_jj_size[1];
  int32_T c10_k_tmp_size[1];
  int32_T c10_m_tmp_size[1];
  int32_T c10_nonzeroy_size[1];
  int32_T c10_tmp_size[1];
  int32_T c10_b_trueCount;
  int32_T c10_c_trueCount;
  int32_T c10_d_trueCount;
  int32_T c10_end;
  int32_T c10_i;
  int32_T c10_line_flag;
  int32_T c10_loop_ub;
  int32_T c10_nonzerox_size_idx_0;
  int32_T c10_nonzeroy_size_idx_0;
  int32_T c10_partialTrueCount;
  int32_T c10_trueCount;
  c10_st.tls = chartInstance->c10_fEmlrtCtx;
  c10_b_st.prev = &c10_st;
  c10_b_st.tls = c10_st.tls;
  c10_c_st.prev = &c10_b_st;
  c10_c_st.tls = c10_b_st.tls;
  c10_d_st.prev = &c10_c_st;
  c10_d_st.tls = c10_c_st.tls;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_JITTransitionAnimation[0] = 0U;
  chartInstance->c10_sfEvent = CALL_EVENT;
  c10_x_location = 320.0;
  c10_b_st.site = &c10_k_emlrtRSI;
  c10_c_st.site = &c10_emlrtRSI;
  c10_eml_find(chartInstance, *chartInstance->c10_binary_image,
               chartInstance->c10_ii_data, c10_ii_size,
               chartInstance->c10_jj_data, c10_jj_size);
  c10_nonzeroy_size_idx_0 = c10_ii_size[0];
  c10_loop_ub = c10_ii_size[0];
  for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
    chartInstance->c10_nonzeroy_data[c10_end] = chartInstance->
      c10_ii_data[c10_end];
  }

  c10_nonzerox_size_idx_0 = c10_jj_size[0];
  c10_loop_ub = c10_jj_size[0];
  for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
    chartInstance->c10_ii_data[c10_end] = chartInstance->c10_jj_data[c10_end];
  }

  c10_tmp_size[0] = c10_ii_size[0];
  for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
    chartInstance->c10_i_tmp_data[c10_end] = (chartInstance->
      c10_nonzeroy_data[c10_end] >= 456);
  }

  for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
    chartInstance->c10_j_tmp_data[c10_end] = (chartInstance->
      c10_nonzeroy_data[c10_end] < 480);
  }

  c10_b_tmp_size[0] = c10_ii_size[0];
  c10_loop_ub = c10_ii_size[0];
  for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
    chartInstance->c10_k_tmp_data[c10_end] = (chartInstance->
      c10_i_tmp_data[c10_end] && chartInstance->c10_j_tmp_data[c10_end]);
  }

  c10_c_tmp_size[0] = c10_jj_size[0];
  for (c10_end = 0; c10_end < c10_nonzerox_size_idx_0; c10_end++) {
    chartInstance->c10_m_tmp_data[c10_end] = (chartInstance->c10_ii_data[c10_end]
      >= 0);
  }

  if ((c10_ii_size[0] != c10_jj_size[0]) && ((c10_ii_size[0] != 1) &&
       (c10_jj_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_ii_size[0], c10_jj_size[0], &c10_b_emlrtECI,
      &c10_st);
  }

  if (c10_ii_size[0] == c10_jj_size[0]) {
    c10_loop_ub = c10_ii_size[0];
    for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
      chartInstance->c10_k_tmp_data[c10_end] = (chartInstance->
        c10_k_tmp_data[c10_end] && chartInstance->c10_m_tmp_data[c10_end]);
    }
  } else {
    c10_b_and(chartInstance, chartInstance->c10_k_tmp_data, c10_b_tmp_size,
              chartInstance->c10_m_tmp_data, c10_c_tmp_size);
  }

  c10_d_tmp_size[0] = c10_jj_size[0];
  for (c10_end = 0; c10_end < c10_nonzerox_size_idx_0; c10_end++) {
    chartInstance->c10_o_tmp_data[c10_end] = (chartInstance->c10_ii_data[c10_end]
      < 160);
  }

  if ((c10_b_tmp_size[0] != c10_jj_size[0]) && ((c10_b_tmp_size[0] != 1) &&
       (c10_jj_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_b_tmp_size[0], c10_jj_size[0],
      &c10_b_emlrtECI, &c10_st);
  }

  if (c10_b_tmp_size[0] == c10_jj_size[0]) {
    c10_e_tmp_size[0] = c10_b_tmp_size[0];
    c10_loop_ub = c10_b_tmp_size[0];
    for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
      chartInstance->c10_p_tmp_data[c10_end] = (chartInstance->
        c10_k_tmp_data[c10_end] && chartInstance->c10_o_tmp_data[c10_end]);
    }
  } else {
    c10_and(chartInstance, chartInstance->c10_p_tmp_data, c10_e_tmp_size,
            chartInstance->c10_k_tmp_data, c10_b_tmp_size,
            chartInstance->c10_o_tmp_data, c10_d_tmp_size);
  }

  c10_end = c10_e_tmp_size[0] - 1;
  c10_trueCount = 0;
  for (c10_i = 0; c10_i <= c10_end; c10_i++) {
    if (chartInstance->c10_p_tmp_data[c10_i]) {
      c10_trueCount++;
    }
  }

  c10_partialTrueCount = 0;
  for (c10_i = 0; c10_i <= c10_end; c10_i++) {
    if (chartInstance->c10_p_tmp_data[c10_i]) {
      chartInstance->c10_tmp_data[c10_partialTrueCount] = c10_i;
      c10_partialTrueCount++;
    }
  }

  for (c10_end = 0; c10_end < c10_trueCount; c10_end++) {
    if (chartInstance->c10_tmp_data[c10_end] > c10_nonzerox_size_idx_0 - 1) {
      emlrtDynamicBoundsCheckR2012b(chartInstance->c10_tmp_data[c10_end], 0,
        c10_nonzerox_size_idx_0 - 1, &c10_s_emlrtBCI, &c10_st);
    }
  }

  c10_b_tmp_size[0] = c10_ii_size[0];
  c10_loop_ub = c10_ii_size[0];
  for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
    chartInstance->c10_k_tmp_data[c10_end] = (chartInstance->
      c10_i_tmp_data[c10_end] && chartInstance->c10_j_tmp_data[c10_end]);
  }

  if ((c10_ii_size[0] != c10_c_tmp_size[0]) && ((c10_ii_size[0] != 1) &&
       (c10_c_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_ii_size[0], c10_c_tmp_size[0],
      &c10_d_emlrtECI, &c10_st);
  }

  if (c10_ii_size[0] == c10_c_tmp_size[0]) {
    c10_loop_ub = c10_ii_size[0];
    for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
      chartInstance->c10_k_tmp_data[c10_end] = (chartInstance->
        c10_k_tmp_data[c10_end] && chartInstance->c10_m_tmp_data[c10_end]);
    }
  } else {
    c10_b_and(chartInstance, chartInstance->c10_k_tmp_data, c10_b_tmp_size,
              chartInstance->c10_m_tmp_data, c10_c_tmp_size);
  }

  if ((c10_b_tmp_size[0] != c10_d_tmp_size[0]) && ((c10_b_tmp_size[0] != 1) &&
       (c10_d_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_b_tmp_size[0], c10_d_tmp_size[0],
      &c10_d_emlrtECI, &c10_st);
  }

  if (c10_b_tmp_size[0] == c10_d_tmp_size[0]) {
    c10_f_tmp_size[0] = c10_b_tmp_size[0];
    c10_loop_ub = c10_b_tmp_size[0];
    for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
      chartInstance->c10_q_tmp_data[c10_end] = (chartInstance->
        c10_k_tmp_data[c10_end] && chartInstance->c10_o_tmp_data[c10_end]);
    }
  } else {
    c10_and(chartInstance, chartInstance->c10_q_tmp_data, c10_f_tmp_size,
            chartInstance->c10_k_tmp_data, c10_b_tmp_size,
            chartInstance->c10_o_tmp_data, c10_d_tmp_size);
  }

  c10_end = c10_f_tmp_size[0] - 1;
  c10_b_trueCount = 0;
  for (c10_i = 0; c10_i <= c10_end; c10_i++) {
    if (chartInstance->c10_q_tmp_data[c10_i]) {
      c10_b_trueCount++;
    }
  }

  c10_partialTrueCount = 0;
  for (c10_i = 0; c10_i <= c10_end; c10_i++) {
    if (chartInstance->c10_q_tmp_data[c10_i]) {
      chartInstance->c10_b_tmp_data[c10_partialTrueCount] = c10_i;
      c10_partialTrueCount++;
    }
  }

  for (c10_end = 0; c10_end < c10_b_trueCount; c10_end++) {
    if (chartInstance->c10_b_tmp_data[c10_end] > c10_nonzeroy_size_idx_0 - 1) {
      emlrtDynamicBoundsCheckR2012b(chartInstance->c10_b_tmp_data[c10_end], 0,
        c10_nonzeroy_size_idx_0 - 1, &c10_t_emlrtBCI, &c10_st);
    }
  }

  c10_b_tmp_size[0] = c10_ii_size[0];
  c10_loop_ub = c10_ii_size[0];
  for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
    chartInstance->c10_k_tmp_data[c10_end] = (chartInstance->
      c10_i_tmp_data[c10_end] && chartInstance->c10_j_tmp_data[c10_end]);
  }

  c10_c_tmp_size[0] = c10_jj_size[0];
  for (c10_end = 0; c10_end < c10_nonzerox_size_idx_0; c10_end++) {
    chartInstance->c10_m_tmp_data[c10_end] = (chartInstance->c10_ii_data[c10_end]
      >= 480);
  }

  if ((c10_ii_size[0] != c10_jj_size[0]) && ((c10_ii_size[0] != 1) &&
       (c10_jj_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_ii_size[0], c10_jj_size[0], &c10_f_emlrtECI,
      &c10_st);
  }

  if (c10_ii_size[0] == c10_jj_size[0]) {
    c10_loop_ub = c10_ii_size[0];
    for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
      chartInstance->c10_k_tmp_data[c10_end] = (chartInstance->
        c10_k_tmp_data[c10_end] && chartInstance->c10_m_tmp_data[c10_end]);
    }
  } else {
    c10_b_and(chartInstance, chartInstance->c10_k_tmp_data, c10_b_tmp_size,
              chartInstance->c10_m_tmp_data, c10_c_tmp_size);
  }

  c10_d_tmp_size[0] = c10_jj_size[0];
  for (c10_end = 0; c10_end < c10_nonzerox_size_idx_0; c10_end++) {
    chartInstance->c10_o_tmp_data[c10_end] = (chartInstance->c10_ii_data[c10_end]
      < 640);
  }

  if ((c10_b_tmp_size[0] != c10_jj_size[0]) && ((c10_b_tmp_size[0] != 1) &&
       (c10_jj_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_b_tmp_size[0], c10_jj_size[0],
      &c10_f_emlrtECI, &c10_st);
  }

  if (c10_b_tmp_size[0] == c10_jj_size[0]) {
    c10_g_tmp_size[0] = c10_b_tmp_size[0];
    c10_loop_ub = c10_b_tmp_size[0];
    for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
      chartInstance->c10_r_tmp_data[c10_end] = (chartInstance->
        c10_k_tmp_data[c10_end] && chartInstance->c10_o_tmp_data[c10_end]);
    }
  } else {
    c10_and(chartInstance, chartInstance->c10_r_tmp_data, c10_g_tmp_size,
            chartInstance->c10_k_tmp_data, c10_b_tmp_size,
            chartInstance->c10_o_tmp_data, c10_d_tmp_size);
  }

  c10_end = c10_g_tmp_size[0] - 1;
  c10_c_trueCount = 0;
  for (c10_i = 0; c10_i <= c10_end; c10_i++) {
    if (chartInstance->c10_r_tmp_data[c10_i]) {
      c10_c_trueCount++;
    }
  }

  c10_partialTrueCount = 0;
  for (c10_i = 0; c10_i <= c10_end; c10_i++) {
    if (chartInstance->c10_r_tmp_data[c10_i]) {
      chartInstance->c10_c_tmp_data[c10_partialTrueCount] = c10_i;
      c10_partialTrueCount++;
    }
  }

  for (c10_end = 0; c10_end < c10_c_trueCount; c10_end++) {
    if (chartInstance->c10_c_tmp_data[c10_end] > c10_nonzerox_size_idx_0 - 1) {
      emlrtDynamicBoundsCheckR2012b(chartInstance->c10_c_tmp_data[c10_end], 0,
        c10_nonzerox_size_idx_0 - 1, &c10_u_emlrtBCI, &c10_st);
    }
  }

  c10_loop_ub = c10_ii_size[0];
  for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
    chartInstance->c10_i_tmp_data[c10_end] = (chartInstance->
      c10_i_tmp_data[c10_end] && chartInstance->c10_j_tmp_data[c10_end]);
  }

  if ((c10_ii_size[0] != c10_c_tmp_size[0]) && ((c10_ii_size[0] != 1) &&
       (c10_c_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_ii_size[0], c10_c_tmp_size[0],
      &c10_h_emlrtECI, &c10_st);
  }

  if (c10_ii_size[0] == c10_c_tmp_size[0]) {
    c10_loop_ub = c10_ii_size[0];
    for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
      chartInstance->c10_i_tmp_data[c10_end] = (chartInstance->
        c10_i_tmp_data[c10_end] && chartInstance->c10_m_tmp_data[c10_end]);
    }
  } else {
    c10_b_and(chartInstance, chartInstance->c10_i_tmp_data, c10_tmp_size,
              chartInstance->c10_m_tmp_data, c10_c_tmp_size);
  }

  if ((c10_tmp_size[0] != c10_d_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
       (c10_d_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_d_tmp_size[0],
      &c10_h_emlrtECI, &c10_st);
  }

  if (c10_tmp_size[0] == c10_d_tmp_size[0]) {
    c10_h_tmp_size[0] = c10_tmp_size[0];
    c10_loop_ub = c10_tmp_size[0];
    for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
      chartInstance->c10_s_tmp_data[c10_end] = (chartInstance->
        c10_i_tmp_data[c10_end] && chartInstance->c10_o_tmp_data[c10_end]);
    }
  } else {
    c10_and(chartInstance, chartInstance->c10_s_tmp_data, c10_h_tmp_size,
            chartInstance->c10_i_tmp_data, c10_tmp_size,
            chartInstance->c10_o_tmp_data, c10_d_tmp_size);
  }

  c10_end = c10_h_tmp_size[0] - 1;
  c10_d_trueCount = 0;
  for (c10_i = 0; c10_i <= c10_end; c10_i++) {
    if (chartInstance->c10_s_tmp_data[c10_i]) {
      c10_d_trueCount++;
    }
  }

  c10_partialTrueCount = 0;
  for (c10_i = 0; c10_i <= c10_end; c10_i++) {
    if (chartInstance->c10_s_tmp_data[c10_i]) {
      chartInstance->c10_d_tmp_data[c10_partialTrueCount] = c10_i;
      c10_partialTrueCount++;
    }
  }

  for (c10_end = 0; c10_end < c10_d_trueCount; c10_end++) {
    if (chartInstance->c10_d_tmp_data[c10_end] > c10_nonzeroy_size_idx_0 - 1) {
      emlrtDynamicBoundsCheckR2012b(chartInstance->c10_d_tmp_data[c10_end], 0,
        c10_nonzeroy_size_idx_0 - 1, &c10_v_emlrtBCI, &c10_st);
    }
  }

  for (c10_loop_ub = 0; c10_loop_ub < c10_trueCount; c10_loop_ub++) {
    if ((c10_loop_ub + 1 < 1) || (c10_loop_ub + 1 > 100000)) {
      emlrtDynamicBoundsCheckR2012b(c10_loop_ub + 1, 1, 100000, &c10_o_emlrtBCI,
        &c10_st);
    }

    if ((c10_loop_ub + 1 < 1) || (c10_loop_ub + 1 > c10_trueCount)) {
      emlrtDynamicBoundsCheckR2012b(c10_loop_ub + 1, 1, c10_trueCount,
        &c10_emlrtBCI, &c10_st);
    }

    if ((c10_loop_ub + 1 < 1) || (c10_loop_ub + 1 > c10_b_trueCount)) {
      emlrtDynamicBoundsCheckR2012b(c10_loop_ub + 1, 1, c10_b_trueCount,
        &c10_b_emlrtBCI, &c10_st);
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c10_loop_ub = 0; c10_loop_ub < c10_c_trueCount; c10_loop_ub++) {
    if ((c10_loop_ub + 1 < 1) || (c10_loop_ub + 1 > 100000)) {
      emlrtDynamicBoundsCheckR2012b(c10_loop_ub + 1, 1, 100000, &c10_q_emlrtBCI,
        &c10_st);
    }

    if ((c10_loop_ub + 1 < 1) || (c10_loop_ub + 1 > c10_c_trueCount)) {
      emlrtDynamicBoundsCheckR2012b(c10_loop_ub + 1, 1, c10_c_trueCount,
        &c10_c_emlrtBCI, &c10_st);
    }

    if ((c10_loop_ub + 1 < 1) || (c10_loop_ub + 1 > c10_d_trueCount)) {
      emlrtDynamicBoundsCheckR2012b(c10_loop_ub + 1, 1, c10_d_trueCount,
        &c10_d_emlrtBCI, &c10_st);
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  if (c10_c_trueCount > 30) {
    c10_line_flag = 1;
    c10_ii_size[0] = c10_c_trueCount;
    for (c10_end = 0; c10_end < c10_c_trueCount; c10_end++) {
      chartInstance->c10_nonzerox_data[c10_end] = static_cast<real_T>
        (chartInstance->c10_ii_data[chartInstance->c10_c_tmp_data[c10_end]]);
    }

    c10_b_st.site = &c10_p_emlrtRSI;
    c10_x_current = c10_mean(chartInstance, &c10_b_st,
      chartInstance->c10_nonzerox_data, c10_ii_size);
    c10_b_st.site = &c10_q_emlrtRSI;
    c10_c_st.site = &c10_g_emlrtRSI;
    c10_nonzeroy_size[0] = c10_d_trueCount;
    for (c10_end = 0; c10_end < c10_d_trueCount; c10_end++) {
      chartInstance->c10_nonzerox_data[c10_end] = static_cast<real_T>
        (chartInstance->c10_nonzeroy_data[chartInstance->c10_d_tmp_data[c10_end]]);
    }

    c10_d_st.site = &c10_h_emlrtRSI;
    c10_y_current = c10_maximum(chartInstance, &c10_d_st,
      chartInstance->c10_nonzerox_data, c10_nonzeroy_size);
  } else {
    c10_line_flag = 2;
    c10_ii_size[0] = c10_trueCount;
    for (c10_end = 0; c10_end < c10_trueCount; c10_end++) {
      chartInstance->c10_nonzerox_data[c10_end] = static_cast<real_T>
        (chartInstance->c10_ii_data[chartInstance->c10_tmp_data[c10_end]]);
    }

    c10_b_st.site = &c10_m_emlrtRSI;
    c10_x_current = c10_mean(chartInstance, &c10_b_st,
      chartInstance->c10_nonzerox_data, c10_ii_size);
    c10_b_st.site = &c10_o_emlrtRSI;
    c10_c_st.site = &c10_g_emlrtRSI;
    c10_nonzeroy_size[0] = c10_b_trueCount;
    for (c10_end = 0; c10_end < c10_b_trueCount; c10_end++) {
      chartInstance->c10_nonzerox_data[c10_end] = static_cast<real_T>
        (chartInstance->c10_nonzeroy_data[chartInstance->c10_b_tmp_data[c10_end]]);
    }

    c10_d_st.site = &c10_h_emlrtRSI;
    c10_y_current = c10_maximum(chartInstance, &c10_d_st,
      chartInstance->c10_nonzerox_data, c10_nonzeroy_size);
  }

  c10_count_left = 0.0;
  c10_count_right = 0.0;
  for (c10_i = 0; c10_i < 20; c10_i++) {
    if (c10_line_flag == 1) {
      c10_win_y_low = c10_y_current - ((static_cast<real_T>(c10_i) + 1.0) + 1.0)
        * 24.0;
      c10_win_y_high = c10_y_current - (static_cast<real_T>(c10_i) + 1.0) * 24.0;
      c10_tmp_size[0] = c10_nonzeroy_size_idx_0;
      for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
        chartInstance->c10_i_tmp_data[c10_end] = (static_cast<real_T>
          (chartInstance->c10_nonzeroy_data[c10_end]) >= c10_win_y_low);
      }

      for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
        chartInstance->c10_j_tmp_data[c10_end] = (static_cast<real_T>
          (chartInstance->c10_nonzeroy_data[c10_end]) < c10_win_y_high);
      }

      c10_b_tmp_size[0] = c10_nonzeroy_size_idx_0;
      for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
        chartInstance->c10_k_tmp_data[c10_end] = (chartInstance->
          c10_i_tmp_data[c10_end] && chartInstance->c10_j_tmp_data[c10_end]);
      }

      c10_c_tmp_size[0] = c10_nonzerox_size_idx_0;
      for (c10_end = 0; c10_end < c10_nonzerox_size_idx_0; c10_end++) {
        chartInstance->c10_m_tmp_data[c10_end] = (static_cast<real_T>
          (chartInstance->c10_ii_data[c10_end]) >= c10_x_current - 40.0);
      }

      if ((c10_nonzeroy_size_idx_0 != c10_nonzerox_size_idx_0) &&
          ((c10_nonzeroy_size_idx_0 != 1) && (c10_nonzerox_size_idx_0 != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_nonzeroy_size_idx_0,
          c10_nonzerox_size_idx_0, &c10_j_emlrtECI, &c10_st);
      }

      if (c10_nonzeroy_size_idx_0 == c10_nonzerox_size_idx_0) {
        for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
          chartInstance->c10_k_tmp_data[c10_end] =
            (chartInstance->c10_k_tmp_data[c10_end] &&
             chartInstance->c10_m_tmp_data[c10_end]);
        }
      } else {
        c10_b_and(chartInstance, chartInstance->c10_k_tmp_data, c10_b_tmp_size,
                  chartInstance->c10_m_tmp_data, c10_c_tmp_size);
      }

      c10_d_tmp_size[0] = c10_nonzerox_size_idx_0;
      for (c10_end = 0; c10_end < c10_nonzerox_size_idx_0; c10_end++) {
        chartInstance->c10_o_tmp_data[c10_end] = (static_cast<real_T>
          (chartInstance->c10_ii_data[c10_end]) < c10_x_current + 40.0);
      }

      if ((c10_b_tmp_size[0] != c10_nonzerox_size_idx_0) && ((c10_b_tmp_size[0]
            != 1) && (c10_nonzerox_size_idx_0 != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_b_tmp_size[0], c10_nonzerox_size_idx_0,
          &c10_j_emlrtECI, &c10_st);
      }

      if (c10_b_tmp_size[0] == c10_nonzerox_size_idx_0) {
        c10_i_tmp_size[0] = c10_b_tmp_size[0];
        c10_loop_ub = c10_b_tmp_size[0];
        for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
          chartInstance->c10_t_tmp_data[c10_end] =
            (chartInstance->c10_k_tmp_data[c10_end] &&
             chartInstance->c10_o_tmp_data[c10_end]);
        }
      } else {
        c10_and(chartInstance, chartInstance->c10_t_tmp_data, c10_i_tmp_size,
                chartInstance->c10_k_tmp_data, c10_b_tmp_size,
                chartInstance->c10_o_tmp_data, c10_d_tmp_size);
      }

      c10_end = c10_i_tmp_size[0] - 1;
      c10_trueCount = 0;
      for (c10_loop_ub = 0; c10_loop_ub <= c10_end; c10_loop_ub++) {
        if (chartInstance->c10_t_tmp_data[c10_loop_ub]) {
          c10_trueCount++;
        }
      }

      c10_partialTrueCount = 0;
      for (c10_loop_ub = 0; c10_loop_ub <= c10_end; c10_loop_ub++) {
        if (chartInstance->c10_t_tmp_data[c10_loop_ub]) {
          chartInstance->c10_e_tmp_data[c10_partialTrueCount] = c10_loop_ub;
          c10_partialTrueCount++;
        }
      }

      for (c10_end = 0; c10_end < c10_trueCount; c10_end++) {
        if (chartInstance->c10_e_tmp_data[c10_end] > c10_nonzerox_size_idx_0 - 1)
        {
          emlrtDynamicBoundsCheckR2012b(chartInstance->c10_e_tmp_data[c10_end],
            0, c10_nonzerox_size_idx_0 - 1, &c10_w_emlrtBCI, &c10_st);
        }
      }

      for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
        chartInstance->c10_i_tmp_data[c10_end] = (chartInstance->
          c10_i_tmp_data[c10_end] && chartInstance->c10_j_tmp_data[c10_end]);
      }

      if ((c10_nonzeroy_size_idx_0 != c10_c_tmp_size[0]) &&
          ((c10_nonzeroy_size_idx_0 != 1) && (c10_c_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_nonzeroy_size_idx_0, c10_c_tmp_size[0],
          &c10_m_emlrtECI, &c10_st);
      }

      if (c10_nonzeroy_size_idx_0 == c10_c_tmp_size[0]) {
        for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
          chartInstance->c10_i_tmp_data[c10_end] =
            (chartInstance->c10_i_tmp_data[c10_end] &&
             chartInstance->c10_m_tmp_data[c10_end]);
        }
      } else {
        c10_b_and(chartInstance, chartInstance->c10_i_tmp_data, c10_tmp_size,
                  chartInstance->c10_m_tmp_data, c10_c_tmp_size);
      }

      if ((c10_tmp_size[0] != c10_d_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_d_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_d_tmp_size[0],
          &c10_m_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_d_tmp_size[0]) {
        c10_k_tmp_size[0] = c10_tmp_size[0];
        c10_loop_ub = c10_tmp_size[0];
        for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
          chartInstance->c10_v_tmp_data[c10_end] =
            (chartInstance->c10_i_tmp_data[c10_end] &&
             chartInstance->c10_o_tmp_data[c10_end]);
        }
      } else {
        c10_and(chartInstance, chartInstance->c10_v_tmp_data, c10_k_tmp_size,
                chartInstance->c10_i_tmp_data, c10_tmp_size,
                chartInstance->c10_o_tmp_data, c10_d_tmp_size);
      }

      c10_end = c10_k_tmp_size[0] - 1;
      c10_b_trueCount = 0;
      for (c10_loop_ub = 0; c10_loop_ub <= c10_end; c10_loop_ub++) {
        if (chartInstance->c10_v_tmp_data[c10_loop_ub]) {
          c10_b_trueCount++;
        }
      }

      c10_partialTrueCount = 0;
      for (c10_loop_ub = 0; c10_loop_ub <= c10_end; c10_loop_ub++) {
        if (chartInstance->c10_v_tmp_data[c10_loop_ub]) {
          chartInstance->c10_g_tmp_data[c10_partialTrueCount] = c10_loop_ub;
          c10_partialTrueCount++;
        }
      }

      for (c10_end = 0; c10_end < c10_b_trueCount; c10_end++) {
        if (chartInstance->c10_g_tmp_data[c10_end] > c10_nonzeroy_size_idx_0 - 1)
        {
          emlrtDynamicBoundsCheckR2012b(chartInstance->c10_g_tmp_data[c10_end],
            0, c10_nonzeroy_size_idx_0 - 1, &c10_y_emlrtBCI, &c10_st);
        }
      }

      if (c10_trueCount > 30) {
        c10_ii_size[0] = c10_trueCount;
        for (c10_end = 0; c10_end < c10_trueCount; c10_end++) {
          chartInstance->c10_nonzerox_data[c10_end] = static_cast<real_T>
            (chartInstance->c10_ii_data[chartInstance->c10_e_tmp_data[c10_end]]);
        }

        c10_b_st.site = &c10_r_emlrtRSI;
        c10_x_current = c10_mean(chartInstance, &c10_b_st,
          chartInstance->c10_nonzerox_data, c10_ii_size);
      }

      if ((c10_win_y_low > 300.0) && (c10_win_y_low < 340.0)) {
        c10_x_location = c10_x_current - 260.0;
      }

      c10_win_y_low = c10_count_right + 1.0;
      c10_end = static_cast<int32_T>(static_cast<real_T>(c10_trueCount) + (1.0 -
        (c10_count_right + 1.0)));
      emlrtForLoopVectorCheckR2021a(c10_count_right + 1.0, 1.0,
        static_cast<real_T>(c10_trueCount), mxDOUBLE_CLASS, c10_end,
        &c10_kb_emlrtRTEI, &c10_st);
      for (c10_loop_ub = 0; c10_loop_ub < c10_end; c10_loop_ub++) {
        c10_win_y_high = c10_win_y_low + static_cast<real_T>(c10_loop_ub);
        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > 100000)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            100000, &c10_r_emlrtBCI, &c10_st);
        }

        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > c10_trueCount)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            c10_trueCount, &c10_e_emlrtBCI, &c10_st);
        }

        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > c10_b_trueCount)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            c10_b_trueCount, &c10_f_emlrtBCI, &c10_st);
        }

        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > c10_trueCount)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            c10_trueCount, &c10_g_emlrtBCI, &c10_st);
        }

        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > c10_b_trueCount)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            c10_b_trueCount, &c10_h_emlrtBCI, &c10_st);
        }

        c10_count_right++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    }

    if (c10_line_flag == 2) {
      c10_win_y_low = c10_y_current - ((static_cast<real_T>(c10_i) + 1.0) + 1.0)
        * 24.0;
      c10_win_y_high = c10_y_current - (static_cast<real_T>(c10_i) + 1.0) * 24.0;
      c10_tmp_size[0] = c10_nonzeroy_size_idx_0;
      for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
        chartInstance->c10_i_tmp_data[c10_end] = (static_cast<real_T>
          (chartInstance->c10_nonzeroy_data[c10_end]) >= c10_win_y_low);
      }

      for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
        chartInstance->c10_j_tmp_data[c10_end] = (static_cast<real_T>
          (chartInstance->c10_nonzeroy_data[c10_end]) < c10_win_y_high);
      }

      c10_b_tmp_size[0] = c10_nonzeroy_size_idx_0;
      for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
        chartInstance->c10_k_tmp_data[c10_end] = (chartInstance->
          c10_i_tmp_data[c10_end] && chartInstance->c10_j_tmp_data[c10_end]);
      }

      c10_c_tmp_size[0] = c10_nonzerox_size_idx_0;
      for (c10_end = 0; c10_end < c10_nonzerox_size_idx_0; c10_end++) {
        chartInstance->c10_m_tmp_data[c10_end] = (static_cast<real_T>
          (chartInstance->c10_ii_data[c10_end]) >= c10_x_current - 40.0);
      }

      if ((c10_nonzeroy_size_idx_0 != c10_nonzerox_size_idx_0) &&
          ((c10_nonzeroy_size_idx_0 != 1) && (c10_nonzerox_size_idx_0 != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_nonzeroy_size_idx_0,
          c10_nonzerox_size_idx_0, &c10_p_emlrtECI, &c10_st);
      }

      if (c10_nonzeroy_size_idx_0 == c10_nonzerox_size_idx_0) {
        for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
          chartInstance->c10_k_tmp_data[c10_end] =
            (chartInstance->c10_k_tmp_data[c10_end] &&
             chartInstance->c10_m_tmp_data[c10_end]);
        }
      } else {
        c10_b_and(chartInstance, chartInstance->c10_k_tmp_data, c10_b_tmp_size,
                  chartInstance->c10_m_tmp_data, c10_c_tmp_size);
      }

      c10_d_tmp_size[0] = c10_nonzerox_size_idx_0;
      for (c10_end = 0; c10_end < c10_nonzerox_size_idx_0; c10_end++) {
        chartInstance->c10_o_tmp_data[c10_end] = (static_cast<real_T>
          (chartInstance->c10_ii_data[c10_end]) < c10_x_current + 40.0);
      }

      if ((c10_b_tmp_size[0] != c10_nonzerox_size_idx_0) && ((c10_b_tmp_size[0]
            != 1) && (c10_nonzerox_size_idx_0 != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_b_tmp_size[0], c10_nonzerox_size_idx_0,
          &c10_p_emlrtECI, &c10_st);
      }

      if (c10_b_tmp_size[0] == c10_nonzerox_size_idx_0) {
        c10_j_tmp_size[0] = c10_b_tmp_size[0];
        c10_loop_ub = c10_b_tmp_size[0];
        for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
          chartInstance->c10_u_tmp_data[c10_end] =
            (chartInstance->c10_k_tmp_data[c10_end] &&
             chartInstance->c10_o_tmp_data[c10_end]);
        }
      } else {
        c10_and(chartInstance, chartInstance->c10_u_tmp_data, c10_j_tmp_size,
                chartInstance->c10_k_tmp_data, c10_b_tmp_size,
                chartInstance->c10_o_tmp_data, c10_d_tmp_size);
      }

      c10_end = c10_j_tmp_size[0] - 1;
      c10_trueCount = 0;
      for (c10_loop_ub = 0; c10_loop_ub <= c10_end; c10_loop_ub++) {
        if (chartInstance->c10_u_tmp_data[c10_loop_ub]) {
          c10_trueCount++;
        }
      }

      c10_partialTrueCount = 0;
      for (c10_loop_ub = 0; c10_loop_ub <= c10_end; c10_loop_ub++) {
        if (chartInstance->c10_u_tmp_data[c10_loop_ub]) {
          chartInstance->c10_f_tmp_data[c10_partialTrueCount] = c10_loop_ub;
          c10_partialTrueCount++;
        }
      }

      for (c10_end = 0; c10_end < c10_trueCount; c10_end++) {
        if (chartInstance->c10_f_tmp_data[c10_end] > c10_nonzerox_size_idx_0 - 1)
        {
          emlrtDynamicBoundsCheckR2012b(chartInstance->c10_f_tmp_data[c10_end],
            0, c10_nonzerox_size_idx_0 - 1, &c10_x_emlrtBCI, &c10_st);
        }
      }

      for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
        chartInstance->c10_i_tmp_data[c10_end] = (chartInstance->
          c10_i_tmp_data[c10_end] && chartInstance->c10_j_tmp_data[c10_end]);
      }

      if ((c10_nonzeroy_size_idx_0 != c10_c_tmp_size[0]) &&
          ((c10_nonzeroy_size_idx_0 != 1) && (c10_c_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_nonzeroy_size_idx_0, c10_c_tmp_size[0],
          &c10_r_emlrtECI, &c10_st);
      }

      if (c10_nonzeroy_size_idx_0 == c10_c_tmp_size[0]) {
        for (c10_end = 0; c10_end < c10_nonzeroy_size_idx_0; c10_end++) {
          chartInstance->c10_i_tmp_data[c10_end] =
            (chartInstance->c10_i_tmp_data[c10_end] &&
             chartInstance->c10_m_tmp_data[c10_end]);
        }
      } else {
        c10_b_and(chartInstance, chartInstance->c10_i_tmp_data, c10_tmp_size,
                  chartInstance->c10_m_tmp_data, c10_c_tmp_size);
      }

      if ((c10_tmp_size[0] != c10_d_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_d_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_d_tmp_size[0],
          &c10_r_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_d_tmp_size[0]) {
        c10_m_tmp_size[0] = c10_tmp_size[0];
        c10_loop_ub = c10_tmp_size[0];
        for (c10_end = 0; c10_end < c10_loop_ub; c10_end++) {
          chartInstance->c10_w_tmp_data[c10_end] =
            (chartInstance->c10_i_tmp_data[c10_end] &&
             chartInstance->c10_o_tmp_data[c10_end]);
        }
      } else {
        c10_and(chartInstance, chartInstance->c10_w_tmp_data, c10_m_tmp_size,
                chartInstance->c10_i_tmp_data, c10_tmp_size,
                chartInstance->c10_o_tmp_data, c10_d_tmp_size);
      }

      c10_end = c10_m_tmp_size[0] - 1;
      c10_b_trueCount = 0;
      for (c10_loop_ub = 0; c10_loop_ub <= c10_end; c10_loop_ub++) {
        if (chartInstance->c10_w_tmp_data[c10_loop_ub]) {
          c10_b_trueCount++;
        }
      }

      c10_partialTrueCount = 0;
      for (c10_loop_ub = 0; c10_loop_ub <= c10_end; c10_loop_ub++) {
        if (chartInstance->c10_w_tmp_data[c10_loop_ub]) {
          chartInstance->c10_h_tmp_data[c10_partialTrueCount] = c10_loop_ub;
          c10_partialTrueCount++;
        }
      }

      for (c10_end = 0; c10_end < c10_b_trueCount; c10_end++) {
        if (chartInstance->c10_h_tmp_data[c10_end] > c10_nonzeroy_size_idx_0 - 1)
        {
          emlrtDynamicBoundsCheckR2012b(chartInstance->c10_h_tmp_data[c10_end],
            0, c10_nonzeroy_size_idx_0 - 1, &c10_ab_emlrtBCI, &c10_st);
        }
      }

      if (c10_trueCount > 30) {
        c10_ii_size[0] = c10_trueCount;
        for (c10_end = 0; c10_end < c10_trueCount; c10_end++) {
          chartInstance->c10_nonzerox_data[c10_end] = static_cast<real_T>
            (chartInstance->c10_ii_data[chartInstance->c10_f_tmp_data[c10_end]]);
        }

        c10_b_st.site = &c10_s_emlrtRSI;
        c10_x_current = c10_mean(chartInstance, &c10_b_st,
          chartInstance->c10_nonzerox_data, c10_ii_size);
      }

      if ((c10_win_y_low > 300.0) && (c10_win_y_low < 340.0)) {
        c10_x_location = c10_x_current + 260.0;
      }

      c10_win_y_low = c10_count_left + 1.0;
      c10_end = static_cast<int32_T>(static_cast<real_T>(c10_trueCount) + (1.0 -
        (c10_count_left + 1.0)));
      emlrtForLoopVectorCheckR2021a(c10_count_left + 1.0, 1.0,
        static_cast<real_T>(c10_trueCount), mxDOUBLE_CLASS, c10_end,
        &c10_mb_emlrtRTEI, &c10_st);
      for (c10_loop_ub = 0; c10_loop_ub < c10_end; c10_loop_ub++) {
        c10_win_y_high = c10_win_y_low + static_cast<real_T>(c10_loop_ub);
        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > 100000)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            100000, &c10_p_emlrtBCI, &c10_st);
        }

        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > c10_trueCount)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            c10_trueCount, &c10_i_emlrtBCI, &c10_st);
        }

        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > c10_b_trueCount)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            c10_b_trueCount, &c10_j_emlrtBCI, &c10_st);
        }

        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > c10_trueCount)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            c10_trueCount, &c10_k_emlrtBCI, &c10_st);
        }

        if ((static_cast<int32_T>(c10_win_y_high) < 1) || (static_cast<int32_T>
             (c10_win_y_high) > c10_b_trueCount)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c10_win_y_high), 1,
            c10_b_trueCount, &c10_m_emlrtBCI, &c10_st);
        }

        c10_count_left++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    }

    c10_win_y_low = 320.0 - c10_x_location;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  *chartInstance->c10_error = c10_win_y_low;
  c10_do_animation_call_c10_Adaptive_Event_send(chartInstance);
}

static void ext_mode_exec_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
  c10_do_animation_call_c10_Adaptive_Event_send(chartInstance);
}

static void c10_do_animation_call_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
  const mxArray *c10_b_y{ nullptr };

  const mxArray *c10_c_y{ nullptr };

  const mxArray *c10_st;
  const mxArray *c10_y{ nullptr };

  c10_st = nullptr;
  c10_st = nullptr;
  c10_y = nullptr;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(2, 1), false);
  c10_b_y = nullptr;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", chartInstance->c10_error, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_c_y = nullptr;
  sf_mex_assign(&c10_c_y, sf_mex_create("y",
    &chartInstance->c10_is_active_c10_Adaptive_Event_send, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  *chartInstance->c10_error = c10_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 0)), "error");
  chartInstance->c10_is_active_c10_Adaptive_Event_send = c10_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
     "is_active_c10_Adaptive_Event_send");
  sf_mex_destroy(&c10_u);
  sf_mex_destroy(&c10_st);
}

static void initSimStructsc10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
}

static void initSubchartIOPointersc10_Adaptive_Event_send
  (SFc10_Adaptive_Event_sendInstanceStruct *chartInstance)
{
}

static void c10_eml_find(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
  boolean_T c10_x[307200], int32_T c10_i_data[], int32_T c10_i_size[1], int32_T
  c10_j_data[], int32_T c10_j_size[1])
{
  int32_T c10_idx;
  int32_T c10_ii;
  int32_T c10_jj;
  boolean_T c10_exitg1;
  boolean_T c10_guard1;
  c10_idx = 0;
  c10_ii = 1;
  c10_jj = 1;
  c10_exitg1 = false;
  while ((!c10_exitg1) && (c10_jj <= 640)) {
    c10_guard1 = false;
    if (c10_x[(c10_ii + 480 * (c10_jj - 1)) - 1]) {
      c10_idx++;
      c10_i_data[c10_idx - 1] = c10_ii;
      c10_j_data[c10_idx - 1] = c10_jj;
      if (c10_idx >= 307200) {
        c10_exitg1 = true;
      } else {
        c10_guard1 = true;
      }
    } else {
      c10_guard1 = true;
    }

    if (c10_guard1) {
      c10_ii++;
      if (c10_ii > 480) {
        c10_ii = 1;
        c10_jj++;
      }
    }
  }

  c10_indexShapeCheck(chartInstance);
  if (c10_idx < 1) {
    c10_i_size[0] = 0;
  } else {
    c10_i_size[0] = c10_idx;
  }

  c10_indexShapeCheck(chartInstance);
  if (c10_idx < 1) {
    c10_j_size[0] = 0;
  } else {
    c10_j_size[0] = c10_idx;
  }

  c10_indexShapeCheck(chartInstance);
}

static void c10_indexShapeCheck(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance)
{
}

static real_T c10_mean(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
  const emlrtStack *c10_sp, real_T c10_x_data[], int32_T c10_x_size[1])
{
  const mxArray *c10_b_y{ nullptr };

  const mxArray *c10_c_y{ nullptr };

  real_T c10_s;
  int32_T c10_ib;
  int32_T c10_inb;
  int32_T c10_nfb;
  int32_T c10_nleft;
  if ((c10_x_size[0] == 1) || (c10_x_size[0] != 1)) {
  } else {
    c10_b_y = nullptr;
    sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c10_c_y = nullptr;
    sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(c10_sp, &c10_b_emlrtMCI, "error", 0U, 2U, 14, c10_b_y, 14,
                sf_mex_call(c10_sp, nullptr, "getString", 1U, 1U, 14,
      sf_mex_call(c10_sp, nullptr, "message", 1U, 1U, 14, c10_c_y)));
  }

  if (c10_x_size[0] == 0) {
    c10_s = 0.0;
  } else if (c10_x_size[0] < 4096) {
    c10_s = c10_sumColumnB(chartInstance, c10_x_data, c10_x_size[0]);
  } else {
    c10_nfb = static_cast<int32_T>(static_cast<uint32_T>(c10_x_size[0]) >> 12);
    c10_inb = c10_nfb << 12;
    c10_nleft = c10_x_size[0] - c10_inb;
    c10_s = c10_sumColumnB4(chartInstance, c10_x_data, 1);
    for (c10_ib = 2; c10_ib <= c10_nfb; c10_ib++) {
      c10_s += c10_sumColumnB4(chartInstance, c10_x_data, ((c10_ib - 1) << 12) +
        1);
    }

    if (c10_nleft > 0) {
      c10_s += c10_b_sumColumnB(chartInstance, c10_x_data, c10_nleft, c10_inb +
        1);
    }
  }

  return c10_s / static_cast<real_T>(c10_x_size[0]);
}

static real_T c10_sumColumnB(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, real_T c10_x_data[], int32_T c10_vlen)
{
  real_T c10_b_y;
  real_T c10_y;
  int32_T c10_b_k;
  int32_T c10_inb;
  int32_T c10_k;
  int32_T c10_nfb;
  int32_T c10_vstart;
  if (c10_vlen <= 1024) {
    c10_y = c10_x_data[0];
    c10_nfb = static_cast<uint16_T>(c10_vlen - 1);
    for (c10_k = 0; c10_k < c10_nfb; c10_k++) {
      c10_y += c10_x_data[c10_k + 1];
    }
  } else {
    c10_nfb = c10_div_nzp_s32(chartInstance, c10_vlen, 1024, 0, 0U, 0, 0);
    c10_inb = c10_nfb << 10;
    c10_y = c10_x_data[0];
    for (c10_k = 0; c10_k < 1023; c10_k++) {
      c10_y += c10_x_data[c10_k + 1];
    }

    for (c10_k = 2; c10_k <= c10_nfb; c10_k++) {
      c10_vstart = (c10_k - 1) << 10;
      c10_b_y = c10_x_data[c10_vstart];
      for (c10_b_k = 0; c10_b_k < 1023; c10_b_k++) {
        c10_b_y += c10_x_data[(c10_vstart + c10_b_k) + 1];
      }

      c10_y += c10_b_y;
    }

    if (c10_vlen > c10_inb) {
      c10_b_y = c10_x_data[c10_inb];
      c10_nfb = c10_vlen - c10_inb;
      for (c10_k = 0; c10_k <= c10_nfb - 2; c10_k++) {
        c10_b_y += c10_x_data[(c10_inb + c10_k) + 1];
      }

      c10_y += c10_b_y;
    }
  }

  return c10_y;
}

static real_T c10_sumColumnB4(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, real_T c10_x_data[], int32_T c10_vstart)
{
  real_T c10_psum1;
  real_T c10_psum2;
  real_T c10_psum3;
  real_T c10_psum4;
  int32_T c10_k;
  c10_psum1 = c10_x_data[c10_vstart - 1];
  c10_psum2 = c10_x_data[c10_vstart + 1023];
  c10_psum3 = c10_x_data[c10_vstart + 2047];
  c10_psum4 = c10_x_data[c10_vstart + 3071];
  for (c10_k = 0; c10_k < 1023; c10_k++) {
    c10_psum1 += c10_x_data[c10_vstart + c10_k];
    c10_psum2 += c10_x_data[(c10_vstart + c10_k) + 1024];
    c10_psum3 += c10_x_data[(c10_vstart + c10_k) + 2048];
    c10_psum4 += c10_x_data[(c10_vstart + c10_k) + 3072];
  }

  return (c10_psum1 + c10_psum2) + (c10_psum3 + c10_psum4);
}

static real_T c10_b_sumColumnB(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, real_T c10_x_data[], int32_T c10_vlen, int32_T c10_vstart)
{
  real_T c10_b_y;
  real_T c10_y;
  int32_T c10_b_k;
  int32_T c10_b_vstart;
  int32_T c10_inb;
  int32_T c10_k;
  int32_T c10_nfb;
  if (c10_vlen <= 1024) {
    c10_y = c10_x_data[c10_vstart - 1];
    for (c10_k = 0; c10_k <= c10_vlen - 2; c10_k++) {
      c10_y += c10_x_data[c10_vstart + c10_k];
    }
  } else {
    c10_nfb = c10_div_nzp_s32(chartInstance, c10_vlen, 1024, 0, 0U, 0, 0);
    c10_inb = c10_nfb << 10;
    c10_y = c10_x_data[c10_vstart - 1];
    for (c10_k = 0; c10_k < 1023; c10_k++) {
      c10_y += c10_x_data[c10_vstart + c10_k];
    }

    for (c10_k = 2; c10_k <= c10_nfb; c10_k++) {
      c10_b_vstart = c10_vstart + ((c10_k - 1) << 10);
      c10_b_y = c10_x_data[c10_b_vstart - 1];
      for (c10_b_k = 0; c10_b_k < 1023; c10_b_k++) {
        c10_b_y += c10_x_data[c10_b_vstart + c10_b_k];
      }

      c10_y += c10_b_y;
    }

    if (c10_vlen > c10_inb) {
      c10_b_vstart = c10_vstart + c10_inb;
      c10_b_y = c10_x_data[c10_b_vstart - 1];
      c10_nfb = c10_vlen - c10_inb;
      for (c10_k = 0; c10_k <= c10_nfb - 2; c10_k++) {
        c10_b_y += c10_x_data[c10_b_vstart + c10_k];
      }

      c10_y += c10_b_y;
    }
  }

  return c10_y;
}

static real_T c10_maximum(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
  const emlrtStack *c10_sp, real_T c10_x_data[], int32_T c10_x_size[1])
{
  static char_T c10_b_cv[39]{ 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  emlrtStack c10_st;
  const mxArray *c10_b_y{ nullptr };

  const mxArray *c10_c_y{ nullptr };

  const mxArray *c10_d_y{ nullptr };

  const mxArray *c10_y{ nullptr };

  real_T c10_ex;
  int32_T c10_k;
  int32_T c10_last;
  c10_st.prev = c10_sp;
  c10_st.tls = c10_sp->tls;
  c10_st.site = &c10_i_emlrtRSI;
  if ((c10_x_size[0] == 1) || (c10_x_size[0] != 1)) {
  } else {
    c10_y = nullptr;
    sf_mex_assign(&c10_y, sf_mex_create("y", c10_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c10_b_y = nullptr;
    sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c10_st, &c10_d_emlrtMCI, "error", 0U, 2U, 14, c10_y, 14,
                sf_mex_call(&c10_st, nullptr, "getString", 1U, 1U, 14,
      sf_mex_call(&c10_st, nullptr, "message", 1U, 1U, 14, c10_b_y)));
  }

  if (!(c10_x_size[0] >= 1)) {
    c10_c_y = nullptr;
    sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_b_cv, 10, 0U, 1U, 0U, 2, 1,
      39), false);
    c10_d_y = nullptr;
    sf_mex_assign(&c10_d_y, sf_mex_create("y", c10_b_cv, 10, 0U, 1U, 0U, 2, 1,
      39), false);
    sf_mex_call(&c10_st, &c10_e_emlrtMCI, "error", 0U, 2U, 14, c10_c_y, 14,
                sf_mex_call(&c10_st, nullptr, "getString", 1U, 1U, 14,
      sf_mex_call(&c10_st, nullptr, "message", 1U, 1U, 14, c10_d_y)));
  }

  c10_last = c10_x_size[0];
  if (c10_x_size[0] <= 2) {
    if (c10_x_size[0] == 1) {
      c10_ex = c10_x_data[0];
    } else if (c10_x_data[0] < c10_x_data[c10_x_size[0] - 1]) {
      c10_ex = c10_x_data[c10_x_size[0] - 1];
    } else {
      c10_ex = c10_x_data[0];
    }
  } else {
    c10_ex = c10_x_data[0];
    for (c10_k = 2; c10_k <= c10_last; c10_k++) {
      if (c10_ex < c10_x_data[c10_k - 1]) {
        c10_ex = c10_x_data[c10_k - 1];
      }
    }
  }

  return c10_ex;
}

const mxArray *sf_c10_Adaptive_Event_send_get_eml_resolved_functions_info()
{
  const mxArray *c10_nameCaptureInfo{ nullptr };

  c10_nameCaptureInfo = nullptr;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_create("nameCaptureInfo", nullptr,
    0, 0U, 1U, 0U, 2, 0, 1), false);
  return c10_nameCaptureInfo;
}

static real_T c10_emlrt_marshallIn(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, const mxArray *c10_nullptr, const char_T *c10_identifier)
{
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  c10_thisId.fIdentifier = const_cast<const char_T *>(c10_identifier);
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nullptr),
    &c10_thisId);
  sf_mex_destroy(&c10_nullptr);
  return c10_y;
}

static real_T c10_b_emlrt_marshallIn(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_d;
  real_T c10_y;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static uint8_T c10_c_emlrt_marshallIn(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, const mxArray *c10_nullptr, const char_T *c10_identifier)
{
  emlrtMsgIdentifier c10_thisId;
  uint8_T c10_y;
  c10_thisId.fIdentifier = const_cast<const char_T *>(c10_identifier);
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nullptr),
    &c10_thisId);
  sf_mex_destroy(&c10_nullptr);
  return c10_y;
}

static uint8_T c10_d_emlrt_marshallIn(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_b_u;
  uint8_T c10_y;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_b_u, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_b_u;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_and(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
                    boolean_T c10_b_in1_data[], int32_T c10_in1_size[1],
                    boolean_T c10_b_in2_data[], int32_T c10_in2_size[1],
                    boolean_T c10_in3_data[], int32_T c10_in3_size[1])
{
  int32_T c10_aux_0_0;
  int32_T c10_aux_1_0;
  int32_T c10_i;
  int32_T c10_in2_size_idx_0;
  int32_T c10_loop_ub;
  int32_T c10_stride_0_0;
  int32_T c10_stride_1_0;
  if (c10_in3_size[0] == 1) {
    c10_in2_size_idx_0 = c10_in2_size[0];
  } else {
    c10_in2_size_idx_0 = c10_in3_size[0];
  }

  c10_stride_0_0 = static_cast<int32_T>(c10_in2_size[0] != 1);
  c10_stride_1_0 = static_cast<int32_T>(c10_in3_size[0] != 1);
  c10_aux_0_0 = 0;
  c10_aux_1_0 = 0;
  if (c10_in3_size[0] == 1) {
    c10_loop_ub = c10_in2_size[0];
  } else {
    c10_loop_ub = c10_in3_size[0];
  }

  for (c10_i = 0; c10_i < c10_loop_ub; c10_i++) {
    chartInstance->c10_in2_data[c10_i] = (c10_b_in2_data[c10_aux_0_0] &&
      c10_in3_data[c10_aux_1_0]);
    c10_aux_1_0 += c10_stride_1_0;
    c10_aux_0_0 += c10_stride_0_0;
  }

  c10_in1_size[0] = c10_in2_size_idx_0;
  for (c10_i = 0; c10_i < c10_in2_size_idx_0; c10_i++) {
    c10_b_in1_data[c10_i] = chartInstance->c10_in2_data[c10_i];
  }
}

static void c10_b_and(SFc10_Adaptive_Event_sendInstanceStruct *chartInstance,
                      boolean_T c10_b_in1_data[], int32_T c10_in1_size[1],
                      boolean_T c10_b_in2_data[], int32_T c10_in2_size[1])
{
  int32_T c10_aux_0_0;
  int32_T c10_aux_1_0;
  int32_T c10_i;
  int32_T c10_in1_size_idx_0;
  int32_T c10_loop_ub;
  int32_T c10_stride_0_0;
  int32_T c10_stride_1_0;
  if (c10_in2_size[0] == 1) {
    c10_in1_size_idx_0 = c10_in1_size[0];
  } else {
    c10_in1_size_idx_0 = c10_in2_size[0];
  }

  c10_stride_0_0 = static_cast<int32_T>(c10_in1_size[0] != 1);
  c10_stride_1_0 = static_cast<int32_T>(c10_in2_size[0] != 1);
  c10_aux_0_0 = 0;
  c10_aux_1_0 = 0;
  if (c10_in2_size[0] == 1) {
    c10_loop_ub = c10_in1_size[0];
  } else {
    c10_loop_ub = c10_in2_size[0];
  }

  for (c10_i = 0; c10_i < c10_loop_ub; c10_i++) {
    chartInstance->c10_in1_data[c10_i] = (c10_b_in1_data[c10_aux_0_0] &&
      c10_b_in2_data[c10_aux_1_0]);
    c10_aux_1_0 += c10_stride_1_0;
    c10_aux_0_0 += c10_stride_0_0;
  }

  c10_in1_size[0] = c10_in1_size_idx_0;
  for (c10_i = 0; c10_i < c10_in1_size_idx_0; c10_i++) {
    c10_b_in1_data[c10_i] = chartInstance->c10_in1_data[c10_i];
  }
}

static int32_T c10_div_nzp_s32(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance, int32_T c10_numerator, int32_T c10_denominator, int32_T
  c10_EMLOvCount_src_loc, uint32_T c10_ssid_src_loc, int32_T c10_offset_src_loc,
  int32_T c10_length_src_loc)
{
  int32_T c10_quotient;
  uint32_T c10_absDenominator;
  uint32_T c10_absNumerator;
  boolean_T c10_quotientNeedsNegation;
  if (c10_numerator < 0) {
    c10_absNumerator = ~static_cast<uint32_T>(c10_numerator) + 1U;
  } else {
    c10_absNumerator = static_cast<uint32_T>(c10_numerator);
  }

  if (c10_denominator < 0) {
    c10_absDenominator = ~static_cast<uint32_T>(c10_denominator) + 1U;
  } else {
    c10_absDenominator = static_cast<uint32_T>(c10_denominator);
  }

  c10_quotientNeedsNegation = (static_cast<int32_T>(c10_numerator < 0) !=
    static_cast<int32_T>(c10_denominator < 0));
  c10_absNumerator /= c10_absDenominator;
  if (c10_quotientNeedsNegation) {
    c10_quotient = -static_cast<int32_T>(c10_absNumerator);
  } else {
    c10_quotient = static_cast<int32_T>(c10_absNumerator);
  }

  return c10_quotient;
}

static void init_dsm_address_info(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance)
{
}

static void init_simulink_io_address(SFc10_Adaptive_Event_sendInstanceStruct
  *chartInstance)
{
  chartInstance->c10_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c10_binary_image = (boolean_T (*)[307200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c10_error = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c10_Adaptive_Event_send_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1787205339U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1602677806U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1762436881U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1074264320U);
}

mxArray *sf_c10_Adaptive_Event_send_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "coder.internal.BoundedEmxArrayExternalDependency"));
  return(mxcell3p);
}

mxArray *sf_c10_Adaptive_Event_send_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_vars");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("i");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c10_Adaptive_Event_send_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_Adaptive_Event_send(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDmYGJgYAPRQMzEAAGsUD4jVIwRLs4CF1cA4pLKglSQeHFRsmcKkM5LzAXzE0s"
    "rPPPS8sHmWzAgzGfDYj4jkvmcUHEI+GBPmX49B3T9LFj0syLpF4DyU4uK8oug4QMLJ/LdoeBAmX"
    "6I/REE/KGI5g8QP7M4PjG5JLMsNT7Z0CDeMSWxAMxxLUvNK4kvTs1LQTIfBACWhB2P"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_Adaptive_Event_send_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "s3JNoAUqDBbrXw6DMPTqSaG";
}

static void sf_opaque_initialize_c10_Adaptive_Event_send(void *chartInstanceVar)
{
  initialize_params_c10_Adaptive_Event_send
    ((SFc10_Adaptive_Event_sendInstanceStruct*) chartInstanceVar);
  initialize_c10_Adaptive_Event_send((SFc10_Adaptive_Event_sendInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_Adaptive_Event_send(void *chartInstanceVar)
{
  enable_c10_Adaptive_Event_send((SFc10_Adaptive_Event_sendInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_Adaptive_Event_send(void *chartInstanceVar)
{
  disable_c10_Adaptive_Event_send((SFc10_Adaptive_Event_sendInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_Adaptive_Event_send(void *chartInstanceVar)
{
  sf_gateway_c10_Adaptive_Event_send((SFc10_Adaptive_Event_sendInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c10_Adaptive_Event_send(SimStruct*
  S)
{
  return get_sim_state_c10_Adaptive_Event_send
    ((SFc10_Adaptive_Event_sendInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c10_Adaptive_Event_send(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c10_Adaptive_Event_send((SFc10_Adaptive_Event_sendInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c10_Adaptive_Event_send(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_Adaptive_Event_sendInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Adaptive_Event_send_optimization_info();
    }

    mdl_cleanup_runtime_resources_c10_Adaptive_Event_send
      ((SFc10_Adaptive_Event_sendInstanceStruct*) chartInstanceVar);
    ((SFc10_Adaptive_Event_sendInstanceStruct*) chartInstanceVar)->
      ~SFc10_Adaptive_Event_sendInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c10_Adaptive_Event_send(void *chartInstanceVar)
{
  mdl_start_c10_Adaptive_Event_send((SFc10_Adaptive_Event_sendInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc10_Adaptive_Event_sendInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c10_Adaptive_Event_send(void
  *chartInstanceVar)
{
  mdl_terminate_c10_Adaptive_Event_send((SFc10_Adaptive_Event_sendInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_Adaptive_Event_send(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_Adaptive_Event_send
      ((SFc10_Adaptive_Event_sendInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc10_Adaptive_Event_send
      ((SFc10_Adaptive_Event_sendInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c10_Adaptive_Event_send_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrtWM2OG0UQ7l1tVgmCKDc4IJEIKeICWoiEciCwXv8Eo3XWYuwl4rJqz5Q9Lfd0z/aPd827cIV",
    "X4BE48ACceAIOHDlSPR471qxjd9tSSBAjjcc9M19X1df110P22h2Cx108H79HyCFeb+O5T2bHrX",
    "K8t3TO7h+QL8rxr28REssERiAiOxyyaxJ2CJt1qaKZJuGHoBl8C1pya5gUbTGU/lgmhqBAxDhBL",
    "pUJkqtZZjkT45YVsZOsv0tZnEaptDw5wQlpcib49GVyc2u6KLHBFMSmBZCYVEk7SlucjtazoMxV",
    "PYV4rG0WzJUGE9ncmao7lhuWc2heQ9wW2lBkQW+wNzLUQN1ch5Hs7NXRHC2znDMq/LlOqY4gR+8",
    "w0M8T/D2zBtnzlIvyBkxQIxWjvJnxekqVL7bLUc8OujUP5tlkpgEDOxoxMXLsKpuBQPvRTzy4Gt",
    "blBBQdwZkIkxs765rXxQIv/NITa1gG51TVYvQDDUlYDKID64ji0kIPpwnCgqADDm3dU2yCaxSaN",
    "9oulLbKGzabeZLeClvIbU5wVfWWcluxqFPOdRi2J/NTmAAv5DeooVtgZ/IDwFqzpCfRO1zkBka/",
    "FezSQomtS5Ewf6+cVFBFkXiGCd8DzjIXBpAgzQvVFxNtiiOrjczqGPqN01NPeTexbWFADWkM3vl",
    "aUaYBFS78KlBuwrQLJEQjS6aw0nuGWQxuBSV6aEXjSqoxchxaGF5w5SIhDA3JCBpgoEhyTfTuc8",
    "qtp86Zxqzs3KOvMcuGyUWsi5+twDGNU0hcDWQcOphncQLfJdaufNbQ2gkz0wboWLHcN5IsJnQsf",
    "o6l3jSHvhgLeSVaSmZR2cWs8SsAzBpUCSxlJ1hK1bSFyvtpreCyV2T30IbB8UwNpwPnG09BYDV0",
    "trrqTWOMqqbAdhMV2gUbsR+wHRGaaYMt4LRZxEBS9MFfkxd98MGKPvjdpT74XjmOPz26qCUU12Q",
    "CF0UAX2gQs/mOluZ726Ovnvfj63DkBo4scPPrR0v4vRVyydK1Ku/O/no99/HfXok7XsK9U5FzUM",
    "Edlpw9/PGzsyd//nY+UH+Mf/r54Ye7yP9lP2zfcrccvz/vmRYZenIjiW3rD/rRN89krX/ZOBmo5",
    "1efNzrd3mVEnxbz3d6g735F3/n9+65PwwAu8oGK20m5/3Fjamd9ebGPW9L3cAMfd5b8iZC/vtoN",
    "/8lxFb+Kr1sVvtwYlJKq4r/b63H/eDf8TP7zDXY8qNjxoOjfL2hcJIGXZYSbcbqt34fi3hR5/+P",
    "818GnnrxqHHnFuF3tC62Tb/r7R2vyGqm8f+81tmNdHg3pl143u34nYf3MB+X4y8VevZ4ynqzYLZ",
    "SPsaEfrnr6H/HvvwP5m/dvTcdf+YH0+0c1QfkUtwez7Vd5u6vct7nFIwVUr96D/Rv1ZFXf5Nt/9",
    "Xutjx/vUJf+AWoBCeI=",
    ""
  };

  static char newstr [1445] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c10_Adaptive_Event_send(SimStruct *S)
{
  const char* newstr = sf_c10_Adaptive_Event_send_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1328717094U));
  ssSetChecksum1(S,(1456270397U));
  ssSetChecksum2(S,(1809740386U));
  ssSetChecksum3(S,(589735846U));
}

static void mdlRTW_c10_Adaptive_Event_send(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c10_Adaptive_Event_send(SimStruct *S)
{
  SFc10_Adaptive_Event_sendInstanceStruct *chartInstance;
  chartInstance = (SFc10_Adaptive_Event_sendInstanceStruct *)utMalloc(sizeof
    (SFc10_Adaptive_Event_sendInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc10_Adaptive_Event_sendInstanceStruct));
  chartInstance = new (chartInstance) SFc10_Adaptive_Event_sendInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_Adaptive_Event_send;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_Adaptive_Event_send;
  chartInstance->chartInfo.mdlStart =
    sf_opaque_mdl_start_c10_Adaptive_Event_send;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c10_Adaptive_Event_send;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c10_Adaptive_Event_send;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_Adaptive_Event_send;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_Adaptive_Event_send;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_Adaptive_Event_send;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_Adaptive_Event_send;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_Adaptive_Event_send;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_Adaptive_Event_send;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_Adaptive_Event_send;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c10_Adaptive_Event_send(chartInstance);
}

void c10_Adaptive_Event_send_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c10_Adaptive_Event_send(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_Adaptive_Event_send(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_Adaptive_Event_send(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_Adaptive_Event_send_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
