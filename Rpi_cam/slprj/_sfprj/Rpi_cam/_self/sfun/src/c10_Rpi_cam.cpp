/* Include files */

#include "Rpi_cam_sfun.h"
#include "c10_Rpi_cam.h"
#include "mwmathutil.h"
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
  "#Rpi_cam:120"                       /* pathName */
};

static emlrtRSInfo c10_m_emlrtRSI{ 73, /* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Rpi_cam:120"                       /* pathName */
};

static emlrtRSInfo c10_o_emlrtRSI{ 74, /* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Rpi_cam:120"                       /* pathName */
};

static emlrtRSInfo c10_p_emlrtRSI{ 69, /* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Rpi_cam:120"                       /* pathName */
};

static emlrtRSInfo c10_q_emlrtRSI{ 70, /* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Rpi_cam:120"                       /* pathName */
};

static emlrtRSInfo c10_r_emlrtRSI{ 100,/* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Rpi_cam:120"                       /* pathName */
};

static emlrtRSInfo c10_s_emlrtRSI{ 128,/* lineNo */
  "Perception Unit/MATLAB Function1",  /* fcnName */
  "#Rpi_cam:120"                       /* pathName */
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
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_d_emlrtRTEI{ 47,/* lineNo */
  57,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_e_emlrtRTEI{ 47,/* lineNo */
  83,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_f_emlrtRTEI{ 47,/* lineNo */
  114,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_g_emlrtRTEI{ 47,/* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_h_emlrtRTEI{ 48,/* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_i_emlrtRTEI{ 48,/* lineNo */
  57,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_j_emlrtRTEI{ 48,/* lineNo */
  83,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_k_emlrtRTEI{ 48,/* lineNo */
  114,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_m_emlrtRTEI{ 48,/* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_o_emlrtRTEI{ 50,/* lineNo */
  32,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_p_emlrtRTEI{ 50,/* lineNo */
  58,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_q_emlrtRTEI{ 50,/* lineNo */
  84,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_r_emlrtRTEI{ 50,/* lineNo */
  116,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_s_emlrtRTEI{ 50,/* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_t_emlrtRTEI{ 51,/* lineNo */
  32,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_u_emlrtRTEI{ 51,/* lineNo */
  58,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_v_emlrtRTEI{ 51,/* lineNo */
  84,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_w_emlrtRTEI{ 51,/* lineNo */
  116,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_x_emlrtRTEI{ 51,/* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_y_emlrtRTEI{ 96,/* lineNo */
  40,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_ab_emlrtRTEI{ 96,/* lineNo */
  66,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_bb_emlrtRTEI{ 96,/* lineNo */
  92,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_cb_emlrtRTEI{ 96,/* lineNo */
  119,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_db_emlrtRTEI{ 96,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_eb_emlrtRTEI{ 97,/* lineNo */
  40,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_fb_emlrtRTEI{ 97,/* lineNo */
  66,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_gb_emlrtRTEI{ 97,/* lineNo */
  92,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_hb_emlrtRTEI{ 97,/* lineNo */
  119,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_ib_emlrtRTEI{ 97,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_jb_emlrtRTEI{ 124,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_kb_emlrtRTEI{ 124,/* lineNo */
  65,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_mb_emlrtRTEI{ 124,/* lineNo */
  91,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_ob_emlrtRTEI{ 124,/* lineNo */
  118,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_pb_emlrtRTEI{ 124,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_qb_emlrtRTEI{ 125,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_rb_emlrtRTEI{ 125,/* lineNo */
  65,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_sb_emlrtRTEI{ 125,/* lineNo */
  91,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_tb_emlrtRTEI{ 125,/* lineNo */
  118,                                 /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_ub_emlrtRTEI{ 125,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_vb_emlrtRTEI{ 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c10_wb_emlrtRTEI{ 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c10_xb_emlrtRTEI{ 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c10_yb_emlrtRTEI{ 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtBCInfo c10_emlrtBCI{ 0,    /* iFirst */
  MAX_int32_T,                         /* iLast */
  56,                                  /* lineNo */
  22,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_emlrtDCI{ 57,   /* lineNo */
  48,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_b_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  48,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_b_emlrtDCI{ 57, /* lineNo */
  70,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_c_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  70,                                  /* colNo */
  "good_lefty_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_d_emlrtBCI{ 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  61,                                  /* lineNo */
  23,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_c_emlrtDCI{ 62, /* lineNo */
  50,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_e_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  50,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_d_emlrtDCI{ 62, /* lineNo */
  73,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_f_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  73,                                  /* colNo */
  "good_righty_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_g_emlrtBCI{ 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  67,                                  /* lineNo */
  4,                                   /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_h_emlrtBCI{ 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  99,                                  /* lineNo */
  12,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_i_emlrtBCI{ 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  107,                                 /* lineNo */
  31,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_e_emlrtDCI{ 108,/* lineNo */
  58,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_j_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  58,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_f_emlrtDCI{ 108,/* lineNo */
  81,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_k_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  81,                                  /* colNo */
  "good_righty_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_g_emlrtDCI{ 109,/* lineNo */
  57,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_m_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  57,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_h_emlrtDCI{ 109,/* lineNo */
  84,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_o_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  84,                                  /* colNo */
  "good_righty_indexs",                /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_p_emlrtBCI{ 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  127,                                 /* lineNo */
  12,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c10_q_emlrtBCI{ 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  135,                                 /* lineNo */
  30,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_i_emlrtDCI{ 136,/* lineNo */
  56,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_r_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  136,                                 /* lineNo */
  56,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_j_emlrtDCI{ 136,/* lineNo */
  78,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_s_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  136,                                 /* lineNo */
  78,                                  /* colNo */
  "good_lefty_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_k_emlrtDCI{ 137,/* lineNo */
  57,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_t_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  57,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_m_emlrtDCI{ 137,/* lineNo */
  83,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_u_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  83,                                  /* colNo */
  "good_lefty_indexs",                 /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_o_emlrtDCI{ 57, /* lineNo */
  21,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_v_emlrtBCI{ 1,  /* iFirst */
  100000,                              /* iLast */
  57,                                  /* lineNo */
  21,                                  /* colNo */
  "left_lane_index",                   /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c10_p_emlrtDCI{ 109,/* lineNo */
  29,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_w_emlrtBCI{ 1,  /* iFirst */
  100000,                              /* iLast */
  109,                                 /* lineNo */
  29,                                  /* colNo */
  "left_lane_index",                   /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c10_q_emlrtDCI{ 136,/* lineNo */
  29,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_x_emlrtBCI{ 1,  /* iFirst */
  100000,                              /* iLast */
  136,                                 /* lineNo */
  29,                                  /* colNo */
  "left_lane_index",                   /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c10_r_emlrtDCI{ 62, /* lineNo */
  22,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_y_emlrtBCI{ 1,  /* iFirst */
  100000,                              /* iLast */
  62,                                  /* lineNo */
  22,                                  /* colNo */
  "right_lane_index",                  /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c10_s_emlrtDCI{ 108,/* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_ab_emlrtBCI{ 1, /* iFirst */
  100000,                              /* iLast */
  108,                                 /* lineNo */
  30,                                  /* colNo */
  "right_lane_index",                  /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c10_t_emlrtDCI{ 137,/* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_bb_emlrtBCI{ 1, /* iFirst */
  100000,                              /* iLast */
  137,                                 /* lineNo */
  30,                                  /* colNo */
  "right_lane_index",                  /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c10_u_emlrtDCI{ 93, /* lineNo */
  26,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_cb_emlrtBCI{ 1, /* iFirst */
  42,                                  /* iLast */
  93,                                  /* lineNo */
  26,                                  /* colNo */
  "rectangle_points",                  /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c10_v_emlrtDCI{ 94, /* lineNo */
  26,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_db_emlrtBCI{ 1, /* iFirst */
  42,                                  /* iLast */
  94,                                  /* lineNo */
  26,                                  /* colNo */
  "rectangle_points",                  /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c10_w_emlrtDCI{ 121,/* lineNo */
  26,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_eb_emlrtBCI{ 1, /* iFirst */
  42,                                  /* iLast */
  121,                                 /* lineNo */
  26,                                  /* colNo */
  "rectangle_points",                  /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c10_x_emlrtDCI{ 122,/* lineNo */
  26,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_fb_emlrtBCI{ 1, /* iFirst */
  42,                                  /* iLast */
  122,                                 /* lineNo */
  26,                                  /* colNo */
  "rectangle_points",                  /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  3                                    /* checkKind */
};

static emlrtECInfo c10_emlrtECI{ -1,   /* nDims */
  47,                                  /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_b_emlrtECI{ 1,  /* nDims */
  47,                                  /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_c_emlrtECI{ -1, /* nDims */
  48,                                  /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_d_emlrtECI{ 1,  /* nDims */
  48,                                  /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_e_emlrtECI{ -1, /* nDims */
  50,                                  /* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_f_emlrtECI{ 1,  /* nDims */
  50,                                  /* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_g_emlrtECI{ -1, /* nDims */
  51,                                  /* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_h_emlrtECI{ 1,  /* nDims */
  51,                                  /* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_ac_emlrtRTEI{ 56,/* lineNo */
  9,                                   /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_bc_emlrtRTEI{ 61,/* lineNo */
  9,                                   /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_i_emlrtECI{ -1, /* nDims */
  96,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_j_emlrtECI{ 1,  /* nDims */
  96,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_k_emlrtECI{ -1, /* nDims */
  97,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_m_emlrtECI{ 1,  /* nDims */
  97,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_cc_emlrtRTEI{ 107,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_o_emlrtECI{ -1, /* nDims */
  124,                                 /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_p_emlrtECI{ 1,  /* nDims */
  124,                                 /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_q_emlrtECI{ -1, /* nDims */
  125,                                 /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtECInfo c10_r_emlrtECI{ 1,  /* nDims */
  125,                                 /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtRTEInfo c10_dc_emlrtRTEI{ 135,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120"                       /* pName */
};

static emlrtBCInfo c10_gb_emlrtBCI{ -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  30,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_y_emlrtDCI{ 47, /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_hb_emlrtBCI{ -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  30,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_ab_emlrtDCI{ 48,/* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_ib_emlrtBCI{ -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  31,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_bb_emlrtDCI{ 50,/* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_jb_emlrtBCI{ -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  31,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_cb_emlrtDCI{ 51,/* lineNo */
  31,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_kb_emlrtBCI{ -1,/* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  39,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_db_emlrtDCI{ 96,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_mb_emlrtBCI{ -1,/* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  38,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_eb_emlrtDCI{ 124,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_ob_emlrtBCI{ -1,/* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  39,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_fb_emlrtDCI{ 97,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c10_pb_emlrtBCI{ -1,/* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  38,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c10_gb_emlrtDCI{ 125,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function1",  /* fName */
  "#Rpi_cam:120",                      /* pName */
  1                                    /* checkKind */
};

static char_T c10_cv[36]{ 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b',
  'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p',
  'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

/* Function Declarations */
static void initialize_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance);
static void initialize_params_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance);
static void mdl_start_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance);
static void mdl_terminate_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *
  chartInstance);
static void mdl_cleanup_runtime_resources_c10_Rpi_cam
  (SFc10_Rpi_camInstanceStruct *chartInstance);
static void enable_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance);
static void disable_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance);
static void sf_gateway_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance);
static void ext_mode_exec_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance);
static void c10_update_jit_animation_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance);
static void c10_do_animation_call_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance);
static void set_sim_state_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_st);
static void initSimStructsc10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance);
static void initSubchartIOPointersc10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance);
static void c10_eml_find(SFc10_Rpi_camInstanceStruct *chartInstance, boolean_T
  c10_x[307200], int32_T c10_i_data[], int32_T c10_i_size[1], int32_T
  c10_j_data[], int32_T c10_j_size[1]);
static void c10_indexShapeCheck(SFc10_Rpi_camInstanceStruct *chartInstance);
static real_T c10_mean(SFc10_Rpi_camInstanceStruct *chartInstance, const
  emlrtStack *c10_sp, real_T c10_x_data[], int32_T c10_x_size[1]);
static real_T c10_sumColumnB(SFc10_Rpi_camInstanceStruct *chartInstance, real_T
  c10_x_data[], int32_T c10_vlen);
static real_T c10_sumColumnB4(SFc10_Rpi_camInstanceStruct *chartInstance, real_T
  c10_x_data[], int32_T c10_vstart);
static real_T c10_b_sumColumnB(SFc10_Rpi_camInstanceStruct *chartInstance,
  real_T c10_x_data[], int32_T c10_vlen, int32_T c10_vstart);
static real_T c10_maximum(SFc10_Rpi_camInstanceStruct *chartInstance, const
  emlrtStack *c10_sp, real_T c10_x_data[], int32_T c10_x_size[1]);
static real_T c10_emlrt_marshallIn(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_nullptr, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static uint8_T c10_c_emlrt_marshallIn(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_nullptr, const char_T *c10_identifier);
static uint8_T c10_d_emlrt_marshallIn(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_slStringInitializeDynamicBuffers(SFc10_Rpi_camInstanceStruct
  *chartInstance);
static void c10_chart_data_browse_helper(SFc10_Rpi_camInstanceStruct
  *chartInstance, int32_T c10_ssIdNumber, const mxArray **c10_mxData, uint8_T
  *c10_isValueTooBig);
static void c10_and(SFc10_Rpi_camInstanceStruct *chartInstance, boolean_T
                    c10_b_in1_data[], int32_T c10_in1_size[1], boolean_T
                    c10_b_in2_data[], int32_T c10_in2_size[1], boolean_T
                    c10_in3_data[], int32_T c10_in3_size[1]);
static void c10_b_and(SFc10_Rpi_camInstanceStruct *chartInstance, boolean_T
                      c10_b_in1_data[], int32_T c10_in1_size[1], boolean_T
                      c10_b_in2_data[], int32_T c10_in2_size[1]);
static void init_dsm_address_info(SFc10_Rpi_camInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc10_Rpi_camInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance)
{
  sf_is_first_init_cond(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c10_doneDoubleBufferReInit = false;
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance)
{
}

static void mdl_start_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance)
{
}

static void mdl_setup_runtime_resources_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *
  chartInstance)
{
  static const int32_T c10_b_postfixPredicateTree[3]{ 0, 1, -3 };

  static const int32_T c10_postfixPredicateTree[3]{ 0, 1, -3 };

  static const int32_T c10_b_condTxtEndIdx[2]{ 4878, 4899 };

  static const int32_T c10_b_condTxtStartIdx[2]{ 4863, 4884 };

  static const int32_T c10_condTxtEndIdx[2]{ 3674, 3695 };

  static const int32_T c10_condTxtStartIdx[2]{ 3659, 3680 };

  static const uint32_T c10_decisionTxtEndIdx{ 0U };

  static const uint32_T c10_decisionTxtStartIdx{ 0U };

  sfSetAnimationVectors(chartInstance->S, chartInstance->c10_JITStateAnimation,
                        chartInstance->c10_JITTransitionAnimation);
  setDataBrowseFcn(chartInstance->S, (void *)&c10_chart_data_browse_helper);
  chartInstance->c10_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c10_RuntimeVar,
    &chartInstance->c10_IsDebuggerActive,
    &chartInstance->c10_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c10_mlFcnLineNumber, &chartInstance->c10_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c10_covrtInstance, 1U, 0U, 1U,
    24U);
  covrtChartInitFcn(chartInstance->c10_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c10_covrtInstance, 0U, 0U, false, false,
                    false, 0U, &c10_decisionTxtStartIdx, &c10_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c10_covrtInstance, 0U, 0, NULL, NULL, 0U,
                    NULL);
  covrtEmlInitFcn(chartInstance->c10_covrtInstance, "", 4U, 0U, 1U, 0U, 7U, 0U,
                  0U, 0U, 5U, 0U, 4U, 2U);
  covrtEmlFcnInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 50, -1, 6125);
  covrtEmlIfInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 0U, 2421, 2455,
                    2558, 2666, false);
  covrtEmlIfInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 1U, 2851, 2870, -1,
                    4045, false);
  covrtEmlIfInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 2U, 3545, 3583, -1,
                    3645, false);
  covrtEmlIfInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 3U, 3655, 3697, -1,
                    3751, false);
  covrtEmlIfInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 4U, 4051, 4070, -1,
                    5241, false);
  covrtEmlIfInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 5U, 4743, 4780, -1,
                    4841, false);
  covrtEmlIfInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 6U, 4859, 4901, -1,
                    4955, false);
  covrtEmlForInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 0U, 2097, 2142,
                     2253);
  covrtEmlForInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 1U, 2255, 2302,
                     2418);
  covrtEmlForInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 2U, 2828, 2846,
                     5315);
  covrtEmlForInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 3U, 3761, 3808,
                     4036);
  covrtEmlForInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 4U, 4965, 5010,
                     5232);
  covrtEmlMCDCInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 0U, 3658, 3696,
                      2U, 0U, c10_condTxtStartIdx, c10_condTxtEndIdx, 3U,
                      c10_postfixPredicateTree, false);
  covrtEmlMCDCInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 1U, 4862, 4900,
                      2U, 2U, c10_b_condTxtStartIdx, c10_b_condTxtEndIdx, 3U,
                      c10_b_postfixPredicateTree, false);
  covrtEmlRelationalInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 0U, 2424,
    2454, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 1U, 2855,
    2869, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 2U, 3548,
    3582, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 3U, 3659,
    3674, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 4U, 3680,
    3695, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 5U, 4055,
    4069, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 6U, 4746,
    4779, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 7U, 4863,
    4878, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c10_covrtInstance, 4U, 0U, 8U, 4884,
    4899, -1, 2U);
}

static void mdl_cleanup_runtime_resources_c10_Rpi_cam
  (SFc10_Rpi_camInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c10_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c10_covrtInstance);
}

static void enable_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance)
{
  emlrtStack c10_b_st;
  emlrtStack c10_c_st;
  emlrtStack c10_d_st;
  emlrtStack c10_st{ NULL,             /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c10_b_d1;
  real_T c10_b_error;
  real_T c10_b_j;
  real_T c10_count_left;
  real_T c10_count_right;
  real_T c10_d;
  real_T c10_d10;
  real_T c10_d11;
  real_T c10_d12;
  real_T c10_d13;
  real_T c10_d14;
  real_T c10_d15;
  real_T c10_d16;
  real_T c10_d17;
  real_T c10_d18;
  real_T c10_d2;
  real_T c10_d3;
  real_T c10_d4;
  real_T c10_d5;
  real_T c10_d6;
  real_T c10_d7;
  real_T c10_d8;
  real_T c10_d9;
  real_T c10_line_flag;
  real_T c10_o_i;
  real_T c10_win_x_high;
  real_T c10_win_x_low;
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
  int32_T c10_good_leftx_indexs_size[1];
  int32_T c10_good_lefty_indexs_size[1];
  int32_T c10_good_rightx_indexs_size[1];
  int32_T c10_good_righty_indexs_size[1];
  int32_T c10_h_tmp_size[1];
  int32_T c10_i_tmp_size[1];
  int32_T c10_ii_size[1];
  int32_T c10_j_tmp_size[1];
  int32_T c10_jj_size[1];
  int32_T c10_nonzerox_size[1];
  int32_T c10_nonzeroy_size[1];
  int32_T c10_tmp_size[1];
  int32_T c10_ab_loop_ub;
  int32_T c10_ac_loop_ub;
  int32_T c10_b_end;
  int32_T c10_b_i;
  int32_T c10_b_loop_ub;
  int32_T c10_b_partialTrueCount;
  int32_T c10_b_trueCount;
  int32_T c10_bb_loop_ub;
  int32_T c10_bc_loop_ub;
  int32_T c10_c_end;
  int32_T c10_c_i;
  int32_T c10_c_j;
  int32_T c10_c_loop_ub;
  int32_T c10_c_partialTrueCount;
  int32_T c10_c_trueCount;
  int32_T c10_cb_loop_ub;
  int32_T c10_cc_loop_ub;
  int32_T c10_d_end;
  int32_T c10_d_i;
  int32_T c10_d_j;
  int32_T c10_d_loop_ub;
  int32_T c10_d_partialTrueCount;
  int32_T c10_d_trueCount;
  int32_T c10_db_loop_ub;
  int32_T c10_dc_loop_ub;
  int32_T c10_e_end;
  int32_T c10_e_i;
  int32_T c10_e_j;
  int32_T c10_e_loop_ub;
  int32_T c10_e_partialTrueCount;
  int32_T c10_e_trueCount;
  int32_T c10_eb_loop_ub;
  int32_T c10_ec_loop_ub;
  int32_T c10_end;
  int32_T c10_f_end;
  int32_T c10_f_i;
  int32_T c10_f_loop_ub;
  int32_T c10_f_partialTrueCount;
  int32_T c10_f_trueCount;
  int32_T c10_fb_loop_ub;
  int32_T c10_fc_loop_ub;
  int32_T c10_g_end;
  int32_T c10_g_loop_ub;
  int32_T c10_g_trueCount;
  int32_T c10_gb_loop_ub;
  int32_T c10_gc_loop_ub;
  int32_T c10_h_end;
  int32_T c10_h_i;
  int32_T c10_h_loop_ub;
  int32_T c10_h_trueCount;
  int32_T c10_hb_loop_ub;
  int32_T c10_hc_loop_ub;
  int32_T c10_i;
  int32_T c10_i1;
  int32_T c10_i10;
  int32_T c10_i100;
  int32_T c10_i101;
  int32_T c10_i11;
  int32_T c10_i12;
  int32_T c10_i13;
  int32_T c10_i14;
  int32_T c10_i15;
  int32_T c10_i16;
  int32_T c10_i17;
  int32_T c10_i18;
  int32_T c10_i19;
  int32_T c10_i2;
  int32_T c10_i20;
  int32_T c10_i21;
  int32_T c10_i22;
  int32_T c10_i23;
  int32_T c10_i24;
  int32_T c10_i25;
  int32_T c10_i26;
  int32_T c10_i27;
  int32_T c10_i28;
  int32_T c10_i29;
  int32_T c10_i3;
  int32_T c10_i30;
  int32_T c10_i31;
  int32_T c10_i32;
  int32_T c10_i33;
  int32_T c10_i34;
  int32_T c10_i35;
  int32_T c10_i36;
  int32_T c10_i37;
  int32_T c10_i38;
  int32_T c10_i39;
  int32_T c10_i4;
  int32_T c10_i40;
  int32_T c10_i41;
  int32_T c10_i42;
  int32_T c10_i43;
  int32_T c10_i44;
  int32_T c10_i45;
  int32_T c10_i46;
  int32_T c10_i47;
  int32_T c10_i48;
  int32_T c10_i49;
  int32_T c10_i5;
  int32_T c10_i50;
  int32_T c10_i51;
  int32_T c10_i52;
  int32_T c10_i53;
  int32_T c10_i54;
  int32_T c10_i55;
  int32_T c10_i56;
  int32_T c10_i57;
  int32_T c10_i58;
  int32_T c10_i59;
  int32_T c10_i6;
  int32_T c10_i60;
  int32_T c10_i61;
  int32_T c10_i62;
  int32_T c10_i63;
  int32_T c10_i64;
  int32_T c10_i65;
  int32_T c10_i66;
  int32_T c10_i67;
  int32_T c10_i68;
  int32_T c10_i69;
  int32_T c10_i7;
  int32_T c10_i70;
  int32_T c10_i71;
  int32_T c10_i72;
  int32_T c10_i73;
  int32_T c10_i74;
  int32_T c10_i75;
  int32_T c10_i76;
  int32_T c10_i77;
  int32_T c10_i78;
  int32_T c10_i79;
  int32_T c10_i8;
  int32_T c10_i80;
  int32_T c10_i81;
  int32_T c10_i82;
  int32_T c10_i83;
  int32_T c10_i84;
  int32_T c10_i85;
  int32_T c10_i86;
  int32_T c10_i87;
  int32_T c10_i88;
  int32_T c10_i89;
  int32_T c10_i9;
  int32_T c10_i90;
  int32_T c10_i91;
  int32_T c10_i92;
  int32_T c10_i93;
  int32_T c10_i94;
  int32_T c10_i95;
  int32_T c10_i96;
  int32_T c10_i97;
  int32_T c10_i98;
  int32_T c10_i99;
  int32_T c10_i_loop_ub;
  int32_T c10_ib_loop_ub;
  int32_T c10_ic_loop_ub;
  int32_T c10_j;
  int32_T c10_j_i;
  int32_T c10_j_loop_ub;
  int32_T c10_jb_loop_ub;
  int32_T c10_jc_loop_ub;
  int32_T c10_k_i;
  int32_T c10_k_loop_ub;
  int32_T c10_kb_loop_ub;
  int32_T c10_kc_loop_ub;
  int32_T c10_loop_ub;
  int32_T c10_m_i;
  int32_T c10_m_loop_ub;
  int32_T c10_mb_loop_ub;
  int32_T c10_mc_loop_ub;
  int32_T c10_o_loop_ub;
  int32_T c10_ob_loop_ub;
  int32_T c10_p_i;
  int32_T c10_p_loop_ub;
  int32_T c10_partialTrueCount;
  int32_T c10_pb_loop_ub;
  int32_T c10_q_i;
  int32_T c10_q_loop_ub;
  int32_T c10_qb_loop_ub;
  int32_T c10_r_i;
  int32_T c10_r_loop_ub;
  int32_T c10_rb_loop_ub;
  int32_T c10_s_i;
  int32_T c10_s_loop_ub;
  int32_T c10_sb_loop_ub;
  int32_T c10_t_i;
  int32_T c10_t_loop_ub;
  int32_T c10_tb_loop_ub;
  int32_T c10_trueCount;
  int32_T c10_u_i;
  int32_T c10_u_loop_ub;
  int32_T c10_ub_loop_ub;
  int32_T c10_v_i;
  int32_T c10_v_loop_ub;
  int32_T c10_vb_loop_ub;
  int32_T c10_w_i;
  int32_T c10_w_loop_ub;
  int32_T c10_wb_loop_ub;
  int32_T c10_x_loop_ub;
  int32_T c10_xb_loop_ub;
  int32_T c10_y_loop_ub;
  int32_T c10_yb_loop_ub;
  c10_st.tls = chartInstance->c10_fEmlrtCtx;
  c10_b_st.prev = &c10_st;
  c10_b_st.tls = c10_st.tls;
  c10_c_st.prev = &c10_b_st;
  c10_c_st.tls = c10_b_st.tls;
  c10_d_st.prev = &c10_c_st;
  c10_d_st.tls = c10_c_st.tls;
  for (c10_i = 0; c10_i < 307200; c10_i++) {
    covrtSigUpdateFcn(chartInstance->c10_covrtInstance, 0U, static_cast<real_T>
                      ((*chartInstance->c10_binary_image)[c10_i]));
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_JITTransitionAnimation[0] = 0U;
  chartInstance->c10_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c10_covrtInstance, 4U, 0, 0);
  c10_x_location = 320.0;
  c10_b_st.site = &c10_k_emlrtRSI;
  c10_c_st.site = &c10_emlrtRSI;
  for (c10_i1 = 0; c10_i1 < 307200; c10_i1++) {
    chartInstance->c10_bv[c10_i1] = (*chartInstance->c10_binary_image)[c10_i1];
  }

  c10_eml_find(chartInstance, chartInstance->c10_bv, chartInstance->c10_ii_data,
               c10_ii_size, chartInstance->c10_jj_data, c10_jj_size);
  c10_nonzeroy_size[0] = c10_ii_size[0];
  c10_loop_ub = c10_ii_size[0] - 1;
  for (c10_i2 = 0; c10_i2 <= c10_loop_ub; c10_i2++) {
    chartInstance->c10_nonzeroy_data[c10_i2] = static_cast<real_T>
      (chartInstance->c10_ii_data[c10_i2]);
  }

  c10_nonzerox_size[0] = c10_jj_size[0];
  c10_b_loop_ub = c10_jj_size[0] - 1;
  for (c10_i3 = 0; c10_i3 <= c10_b_loop_ub; c10_i3++) {
    chartInstance->c10_nonzerox_data[c10_i3] = static_cast<real_T>
      (chartInstance->c10_jj_data[c10_i3]);
  }

  c10_tmp_size[0] = c10_nonzeroy_size[0];
  c10_c_loop_ub = c10_nonzeroy_size[0] - 1;
  for (c10_i4 = 0; c10_i4 <= c10_c_loop_ub; c10_i4++) {
    chartInstance->c10_tmp_data[c10_i4] = (chartInstance->
      c10_nonzeroy_data[c10_i4] >= 456.0);
  }

  c10_b_tmp_size[0] = c10_nonzeroy_size[0];
  c10_d_loop_ub = c10_nonzeroy_size[0] - 1;
  for (c10_i5 = 0; c10_i5 <= c10_d_loop_ub; c10_i5++) {
    chartInstance->c10_b_tmp_data[c10_i5] = (chartInstance->
      c10_nonzeroy_data[c10_i5] < 480.0);
  }

  if (c10_tmp_size[0] != c10_b_tmp_size[0]) {
    emlrtSizeEqCheck1DR2012b(c10_tmp_size[0], c10_b_tmp_size[0], &c10_emlrtECI,
      &c10_st);
  }

  c10_e_loop_ub = c10_tmp_size[0] - 1;
  for (c10_i6 = 0; c10_i6 <= c10_e_loop_ub; c10_i6++) {
    chartInstance->c10_tmp_data[c10_i6] = (chartInstance->c10_tmp_data[c10_i6] &&
      chartInstance->c10_b_tmp_data[c10_i6]);
  }

  c10_b_tmp_size[0] = c10_nonzerox_size[0];
  c10_f_loop_ub = c10_nonzerox_size[0] - 1;
  for (c10_i7 = 0; c10_i7 <= c10_f_loop_ub; c10_i7++) {
    chartInstance->c10_b_tmp_data[c10_i7] = (chartInstance->
      c10_nonzerox_data[c10_i7] >= 0.0);
  }

  if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
       (c10_b_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
      &c10_b_emlrtECI, &c10_st);
  }

  if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
    c10_g_loop_ub = c10_tmp_size[0] - 1;
    for (c10_i8 = 0; c10_i8 <= c10_g_loop_ub; c10_i8++) {
      chartInstance->c10_tmp_data[c10_i8] = (chartInstance->c10_tmp_data[c10_i8]
        && chartInstance->c10_b_tmp_data[c10_i8]);
    }
  } else {
    c10_b_and(chartInstance, chartInstance->c10_tmp_data, c10_tmp_size,
              chartInstance->c10_b_tmp_data, c10_b_tmp_size);
  }

  c10_b_tmp_size[0] = c10_nonzerox_size[0];
  c10_h_loop_ub = c10_nonzerox_size[0] - 1;
  for (c10_i9 = 0; c10_i9 <= c10_h_loop_ub; c10_i9++) {
    chartInstance->c10_b_tmp_data[c10_i9] = (chartInstance->
      c10_nonzerox_data[c10_i9] < 160.0);
  }

  if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
       (c10_b_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
      &c10_b_emlrtECI, &c10_st);
  }

  if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
    c10_c_tmp_size[0] = c10_tmp_size[0];
    c10_i_loop_ub = c10_tmp_size[0] - 1;
    for (c10_i10 = 0; c10_i10 <= c10_i_loop_ub; c10_i10++) {
      chartInstance->c10_c_tmp_data[c10_i10] = (chartInstance->
        c10_tmp_data[c10_i10] && chartInstance->c10_b_tmp_data[c10_i10]);
    }
  } else {
    c10_and(chartInstance, chartInstance->c10_c_tmp_data, c10_c_tmp_size,
            chartInstance->c10_tmp_data, c10_tmp_size,
            chartInstance->c10_b_tmp_data, c10_b_tmp_size);
  }

  c10_end = c10_c_tmp_size[0];
  c10_trueCount = 0;
  for (c10_b_i = 0; c10_b_i < c10_end; c10_b_i++) {
    if (chartInstance->c10_c_tmp_data[c10_b_i]) {
      c10_trueCount++;
    }
  }

  c10_good_leftx_indexs_size[0] = c10_trueCount;
  c10_partialTrueCount = 0;
  for (c10_c_i = 0; c10_c_i < c10_end; c10_c_i++) {
    if (chartInstance->c10_c_tmp_data[c10_c_i]) {
      c10_i11 = c10_nonzerox_size[0] - 1;
      c10_d = static_cast<real_T>(c10_c_i);
      if (c10_d != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c10_d)))) {
        emlrtIntegerCheckR2012b(c10_d, &c10_y_emlrtDCI, &c10_st);
      }

      c10_i13 = static_cast<int32_T>(muDoubleScalarFloor(c10_d));
      if ((c10_i13 < 0) || (c10_i13 > c10_i11)) {
        emlrtDynamicBoundsCheckR2012b(c10_i13, 0, c10_i11, &c10_gb_emlrtBCI,
          &c10_st);
      }

      chartInstance->c10_good_leftx_indexs_data[c10_partialTrueCount] =
        chartInstance->c10_nonzerox_data[c10_i13];
      c10_partialTrueCount++;
    }
  }

  c10_tmp_size[0] = c10_nonzeroy_size[0];
  c10_j_loop_ub = c10_nonzeroy_size[0] - 1;
  for (c10_i12 = 0; c10_i12 <= c10_j_loop_ub; c10_i12++) {
    chartInstance->c10_tmp_data[c10_i12] = (chartInstance->
      c10_nonzeroy_data[c10_i12] >= 456.0);
  }

  c10_b_tmp_size[0] = c10_nonzeroy_size[0];
  c10_k_loop_ub = c10_nonzeroy_size[0] - 1;
  for (c10_i14 = 0; c10_i14 <= c10_k_loop_ub; c10_i14++) {
    chartInstance->c10_b_tmp_data[c10_i14] = (chartInstance->
      c10_nonzeroy_data[c10_i14] < 480.0);
  }

  if (c10_tmp_size[0] != c10_b_tmp_size[0]) {
    emlrtSizeEqCheck1DR2012b(c10_tmp_size[0], c10_b_tmp_size[0], &c10_c_emlrtECI,
      &c10_st);
  }

  c10_m_loop_ub = c10_tmp_size[0] - 1;
  for (c10_i15 = 0; c10_i15 <= c10_m_loop_ub; c10_i15++) {
    chartInstance->c10_tmp_data[c10_i15] = (chartInstance->c10_tmp_data[c10_i15]
      && chartInstance->c10_b_tmp_data[c10_i15]);
  }

  c10_b_tmp_size[0] = c10_nonzerox_size[0];
  c10_o_loop_ub = c10_nonzerox_size[0] - 1;
  for (c10_i16 = 0; c10_i16 <= c10_o_loop_ub; c10_i16++) {
    chartInstance->c10_b_tmp_data[c10_i16] = (chartInstance->
      c10_nonzerox_data[c10_i16] >= 0.0);
  }

  if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
       (c10_b_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
      &c10_d_emlrtECI, &c10_st);
  }

  if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
    c10_p_loop_ub = c10_tmp_size[0] - 1;
    for (c10_i17 = 0; c10_i17 <= c10_p_loop_ub; c10_i17++) {
      chartInstance->c10_tmp_data[c10_i17] = (chartInstance->
        c10_tmp_data[c10_i17] && chartInstance->c10_b_tmp_data[c10_i17]);
    }
  } else {
    c10_b_and(chartInstance, chartInstance->c10_tmp_data, c10_tmp_size,
              chartInstance->c10_b_tmp_data, c10_b_tmp_size);
  }

  c10_b_tmp_size[0] = c10_nonzerox_size[0];
  c10_q_loop_ub = c10_nonzerox_size[0] - 1;
  for (c10_i18 = 0; c10_i18 <= c10_q_loop_ub; c10_i18++) {
    chartInstance->c10_b_tmp_data[c10_i18] = (chartInstance->
      c10_nonzerox_data[c10_i18] < 160.0);
  }

  if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
       (c10_b_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
      &c10_d_emlrtECI, &c10_st);
  }

  if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
    c10_d_tmp_size[0] = c10_tmp_size[0];
    c10_r_loop_ub = c10_tmp_size[0] - 1;
    for (c10_i19 = 0; c10_i19 <= c10_r_loop_ub; c10_i19++) {
      chartInstance->c10_d_tmp_data[c10_i19] = (chartInstance->
        c10_tmp_data[c10_i19] && chartInstance->c10_b_tmp_data[c10_i19]);
    }
  } else {
    c10_and(chartInstance, chartInstance->c10_d_tmp_data, c10_d_tmp_size,
            chartInstance->c10_tmp_data, c10_tmp_size,
            chartInstance->c10_b_tmp_data, c10_b_tmp_size);
  }

  c10_b_end = c10_d_tmp_size[0];
  c10_b_trueCount = 0;
  for (c10_d_i = 0; c10_d_i < c10_b_end; c10_d_i++) {
    if (chartInstance->c10_d_tmp_data[c10_d_i]) {
      c10_b_trueCount++;
    }
  }

  c10_good_lefty_indexs_size[0] = c10_b_trueCount;
  c10_b_partialTrueCount = 0;
  for (c10_e_i = 0; c10_e_i < c10_b_end; c10_e_i++) {
    if (chartInstance->c10_d_tmp_data[c10_e_i]) {
      c10_i20 = c10_nonzeroy_size[0] - 1;
      c10_b_d1 = static_cast<real_T>(c10_e_i);
      if (c10_b_d1 != static_cast<real_T>(static_cast<int32_T>
           (muDoubleScalarFloor(c10_b_d1)))) {
        emlrtIntegerCheckR2012b(c10_b_d1, &c10_ab_emlrtDCI, &c10_st);
      }

      c10_i22 = static_cast<int32_T>(muDoubleScalarFloor(c10_b_d1));
      if ((c10_i22 < 0) || (c10_i22 > c10_i20)) {
        emlrtDynamicBoundsCheckR2012b(c10_i22, 0, c10_i20, &c10_hb_emlrtBCI,
          &c10_st);
      }

      chartInstance->c10_good_lefty_indexs_data[c10_b_partialTrueCount] =
        chartInstance->c10_nonzeroy_data[c10_i22];
      c10_b_partialTrueCount++;
    }
  }

  c10_tmp_size[0] = c10_nonzeroy_size[0];
  c10_s_loop_ub = c10_nonzeroy_size[0] - 1;
  for (c10_i21 = 0; c10_i21 <= c10_s_loop_ub; c10_i21++) {
    chartInstance->c10_tmp_data[c10_i21] = (chartInstance->
      c10_nonzeroy_data[c10_i21] >= 456.0);
  }

  c10_b_tmp_size[0] = c10_nonzeroy_size[0];
  c10_t_loop_ub = c10_nonzeroy_size[0] - 1;
  for (c10_i23 = 0; c10_i23 <= c10_t_loop_ub; c10_i23++) {
    chartInstance->c10_b_tmp_data[c10_i23] = (chartInstance->
      c10_nonzeroy_data[c10_i23] < 480.0);
  }

  if (c10_tmp_size[0] != c10_b_tmp_size[0]) {
    emlrtSizeEqCheck1DR2012b(c10_tmp_size[0], c10_b_tmp_size[0], &c10_e_emlrtECI,
      &c10_st);
  }

  c10_u_loop_ub = c10_tmp_size[0] - 1;
  for (c10_i24 = 0; c10_i24 <= c10_u_loop_ub; c10_i24++) {
    chartInstance->c10_tmp_data[c10_i24] = (chartInstance->c10_tmp_data[c10_i24]
      && chartInstance->c10_b_tmp_data[c10_i24]);
  }

  c10_b_tmp_size[0] = c10_nonzerox_size[0];
  c10_v_loop_ub = c10_nonzerox_size[0] - 1;
  for (c10_i25 = 0; c10_i25 <= c10_v_loop_ub; c10_i25++) {
    chartInstance->c10_b_tmp_data[c10_i25] = (chartInstance->
      c10_nonzerox_data[c10_i25] >= 480.0);
  }

  if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
       (c10_b_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
      &c10_f_emlrtECI, &c10_st);
  }

  if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
    c10_w_loop_ub = c10_tmp_size[0] - 1;
    for (c10_i26 = 0; c10_i26 <= c10_w_loop_ub; c10_i26++) {
      chartInstance->c10_tmp_data[c10_i26] = (chartInstance->
        c10_tmp_data[c10_i26] && chartInstance->c10_b_tmp_data[c10_i26]);
    }
  } else {
    c10_b_and(chartInstance, chartInstance->c10_tmp_data, c10_tmp_size,
              chartInstance->c10_b_tmp_data, c10_b_tmp_size);
  }

  c10_b_tmp_size[0] = c10_nonzerox_size[0];
  c10_x_loop_ub = c10_nonzerox_size[0] - 1;
  for (c10_i27 = 0; c10_i27 <= c10_x_loop_ub; c10_i27++) {
    chartInstance->c10_b_tmp_data[c10_i27] = (chartInstance->
      c10_nonzerox_data[c10_i27] < 640.0);
  }

  if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
       (c10_b_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
      &c10_f_emlrtECI, &c10_st);
  }

  if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
    c10_e_tmp_size[0] = c10_tmp_size[0];
    c10_y_loop_ub = c10_tmp_size[0] - 1;
    for (c10_i28 = 0; c10_i28 <= c10_y_loop_ub; c10_i28++) {
      chartInstance->c10_e_tmp_data[c10_i28] = (chartInstance->
        c10_tmp_data[c10_i28] && chartInstance->c10_b_tmp_data[c10_i28]);
    }
  } else {
    c10_and(chartInstance, chartInstance->c10_e_tmp_data, c10_e_tmp_size,
            chartInstance->c10_tmp_data, c10_tmp_size,
            chartInstance->c10_b_tmp_data, c10_b_tmp_size);
  }

  c10_c_end = c10_e_tmp_size[0];
  c10_c_trueCount = 0;
  for (c10_f_i = 0; c10_f_i < c10_c_end; c10_f_i++) {
    if (chartInstance->c10_e_tmp_data[c10_f_i]) {
      c10_c_trueCount++;
    }
  }

  c10_good_rightx_indexs_size[0] = c10_c_trueCount;
  c10_c_partialTrueCount = 0;
  for (c10_h_i = 0; c10_h_i < c10_c_end; c10_h_i++) {
    if (chartInstance->c10_e_tmp_data[c10_h_i]) {
      c10_i29 = c10_nonzerox_size[0] - 1;
      c10_d2 = static_cast<real_T>(c10_h_i);
      if (c10_d2 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c10_d2)))) {
        emlrtIntegerCheckR2012b(c10_d2, &c10_bb_emlrtDCI, &c10_st);
      }

      c10_i31 = static_cast<int32_T>(muDoubleScalarFloor(c10_d2));
      if ((c10_i31 < 0) || (c10_i31 > c10_i29)) {
        emlrtDynamicBoundsCheckR2012b(c10_i31, 0, c10_i29, &c10_ib_emlrtBCI,
          &c10_st);
      }

      chartInstance->c10_good_rightx_indexs_data[c10_c_partialTrueCount] =
        chartInstance->c10_nonzerox_data[c10_i31];
      c10_c_partialTrueCount++;
    }
  }

  c10_tmp_size[0] = c10_nonzeroy_size[0];
  c10_ab_loop_ub = c10_nonzeroy_size[0] - 1;
  for (c10_i30 = 0; c10_i30 <= c10_ab_loop_ub; c10_i30++) {
    chartInstance->c10_tmp_data[c10_i30] = (chartInstance->
      c10_nonzeroy_data[c10_i30] >= 456.0);
  }

  c10_b_tmp_size[0] = c10_nonzeroy_size[0];
  c10_bb_loop_ub = c10_nonzeroy_size[0] - 1;
  for (c10_i32 = 0; c10_i32 <= c10_bb_loop_ub; c10_i32++) {
    chartInstance->c10_b_tmp_data[c10_i32] = (chartInstance->
      c10_nonzeroy_data[c10_i32] < 480.0);
  }

  if (c10_tmp_size[0] != c10_b_tmp_size[0]) {
    emlrtSizeEqCheck1DR2012b(c10_tmp_size[0], c10_b_tmp_size[0], &c10_g_emlrtECI,
      &c10_st);
  }

  c10_cb_loop_ub = c10_tmp_size[0] - 1;
  for (c10_i33 = 0; c10_i33 <= c10_cb_loop_ub; c10_i33++) {
    chartInstance->c10_tmp_data[c10_i33] = (chartInstance->c10_tmp_data[c10_i33]
      && chartInstance->c10_b_tmp_data[c10_i33]);
  }

  c10_b_tmp_size[0] = c10_nonzerox_size[0];
  c10_db_loop_ub = c10_nonzerox_size[0] - 1;
  for (c10_i34 = 0; c10_i34 <= c10_db_loop_ub; c10_i34++) {
    chartInstance->c10_b_tmp_data[c10_i34] = (chartInstance->
      c10_nonzerox_data[c10_i34] >= 480.0);
  }

  if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
       (c10_b_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
      &c10_h_emlrtECI, &c10_st);
  }

  if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
    c10_eb_loop_ub = c10_tmp_size[0] - 1;
    for (c10_i35 = 0; c10_i35 <= c10_eb_loop_ub; c10_i35++) {
      chartInstance->c10_tmp_data[c10_i35] = (chartInstance->
        c10_tmp_data[c10_i35] && chartInstance->c10_b_tmp_data[c10_i35]);
    }
  } else {
    c10_b_and(chartInstance, chartInstance->c10_tmp_data, c10_tmp_size,
              chartInstance->c10_b_tmp_data, c10_b_tmp_size);
  }

  c10_b_tmp_size[0] = c10_nonzerox_size[0];
  c10_fb_loop_ub = c10_nonzerox_size[0] - 1;
  for (c10_i36 = 0; c10_i36 <= c10_fb_loop_ub; c10_i36++) {
    chartInstance->c10_b_tmp_data[c10_i36] = (chartInstance->
      c10_nonzerox_data[c10_i36] < 640.0);
  }

  if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
       (c10_b_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
      &c10_h_emlrtECI, &c10_st);
  }

  if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
    c10_f_tmp_size[0] = c10_tmp_size[0];
    c10_gb_loop_ub = c10_tmp_size[0] - 1;
    for (c10_i37 = 0; c10_i37 <= c10_gb_loop_ub; c10_i37++) {
      chartInstance->c10_f_tmp_data[c10_i37] = (chartInstance->
        c10_tmp_data[c10_i37] && chartInstance->c10_b_tmp_data[c10_i37]);
    }
  } else {
    c10_and(chartInstance, chartInstance->c10_f_tmp_data, c10_f_tmp_size,
            chartInstance->c10_tmp_data, c10_tmp_size,
            chartInstance->c10_b_tmp_data, c10_b_tmp_size);
  }

  c10_d_end = c10_f_tmp_size[0];
  c10_d_trueCount = 0;
  for (c10_j_i = 0; c10_j_i < c10_d_end; c10_j_i++) {
    if (chartInstance->c10_f_tmp_data[c10_j_i]) {
      c10_d_trueCount++;
    }
  }

  c10_good_righty_indexs_size[0] = c10_d_trueCount;
  c10_d_partialTrueCount = 0;
  for (c10_k_i = 0; c10_k_i < c10_d_end; c10_k_i++) {
    if (chartInstance->c10_f_tmp_data[c10_k_i]) {
      c10_i38 = c10_nonzeroy_size[0] - 1;
      c10_d4 = static_cast<real_T>(c10_k_i);
      if (c10_d4 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c10_d4)))) {
        emlrtIntegerCheckR2012b(c10_d4, &c10_cb_emlrtDCI, &c10_st);
      }

      c10_i40 = static_cast<int32_T>(muDoubleScalarFloor(c10_d4));
      if ((c10_i40 < 0) || (c10_i40 > c10_i38)) {
        emlrtDynamicBoundsCheckR2012b(c10_i40, 0, c10_i38, &c10_jb_emlrtBCI,
          &c10_st);
      }

      chartInstance->c10_good_righty_indexs_data[c10_d_partialTrueCount] =
        chartInstance->c10_nonzeroy_data[c10_i40];
      c10_d_partialTrueCount++;
    }
  }

  if (c10_good_leftx_indexs_size[0] < 0) {
    emlrtDynamicBoundsCheckR2012b(c10_good_leftx_indexs_size[0], 0, MAX_int32_T,
      &c10_emlrtBCI, &c10_st);
  }

  c10_d3 = static_cast<real_T>(c10_good_leftx_indexs_size[0]);
  c10_i39 = static_cast<int32_T>(c10_d3);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c10_d3, mxDOUBLE_CLASS, c10_i39,
    &c10_ac_emlrtRTEI, &c10_st);
  for (c10_j = 0; c10_j < c10_i39; c10_j++) {
    c10_b_j = 1.0 + static_cast<real_T>(c10_j);
    covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 0, 1);
    if (c10_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c10_b_j)))) {
      emlrtIntegerCheckR2012b(c10_b_j, &c10_o_emlrtDCI, &c10_st);
    }

    c10_i42 = static_cast<int32_T>(c10_b_j);
    if ((c10_i42 < 1) || (c10_i42 > 100000)) {
      emlrtDynamicBoundsCheckR2012b(c10_i42, 1, 100000, &c10_v_emlrtBCI, &c10_st);
    }

    if (c10_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c10_b_j)))) {
      emlrtIntegerCheckR2012b(c10_b_j, &c10_emlrtDCI, &c10_st);
    }

    c10_i43 = static_cast<int32_T>(c10_b_j);
    if ((c10_i43 < 1) || (c10_i43 > c10_good_leftx_indexs_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c10_i43, 1, c10_good_leftx_indexs_size[0],
        &c10_b_emlrtBCI, &c10_st);
    }

    if (c10_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c10_b_j)))) {
      emlrtIntegerCheckR2012b(c10_b_j, &c10_b_emlrtDCI, &c10_st);
    }

    c10_i45 = static_cast<int32_T>(c10_b_j);
    if ((c10_i45 < 1) || (c10_i45 > c10_good_lefty_indexs_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c10_i45, 1, c10_good_lefty_indexs_size[0],
        &c10_c_emlrtBCI, &c10_st);
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 0, 0);
  if (c10_good_rightx_indexs_size[0] < 0) {
    emlrtDynamicBoundsCheckR2012b(c10_good_rightx_indexs_size[0], 0, MAX_int32_T,
      &c10_d_emlrtBCI, &c10_st);
  }

  c10_d5 = static_cast<real_T>(c10_good_rightx_indexs_size[0]);
  c10_i41 = static_cast<int32_T>(c10_d5);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c10_d5, mxDOUBLE_CLASS, c10_i41,
    &c10_bc_emlrtRTEI, &c10_st);
  for (c10_c_j = 0; c10_c_j < c10_i41; c10_c_j++) {
    c10_b_j = 1.0 + static_cast<real_T>(c10_c_j);
    covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 1, 1);
    if (c10_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c10_b_j)))) {
      emlrtIntegerCheckR2012b(c10_b_j, &c10_r_emlrtDCI, &c10_st);
    }

    c10_i44 = static_cast<int32_T>(c10_b_j);
    if ((c10_i44 < 1) || (c10_i44 > 100000)) {
      emlrtDynamicBoundsCheckR2012b(c10_i44, 1, 100000, &c10_y_emlrtBCI, &c10_st);
    }

    if (c10_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c10_b_j)))) {
      emlrtIntegerCheckR2012b(c10_b_j, &c10_c_emlrtDCI, &c10_st);
    }

    c10_i46 = static_cast<int32_T>(c10_b_j);
    if ((c10_i46 < 1) || (c10_i46 > c10_good_rightx_indexs_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c10_i46, 1, c10_good_rightx_indexs_size[0],
        &c10_e_emlrtBCI, &c10_st);
    }

    if (c10_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c10_b_j)))) {
      emlrtIntegerCheckR2012b(c10_b_j, &c10_d_emlrtDCI, &c10_st);
    }

    c10_i47 = static_cast<int32_T>(c10_b_j);
    if ((c10_i47 < 1) || (c10_i47 > c10_good_righty_indexs_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c10_i47, 1, c10_good_righty_indexs_size[0],
        &c10_f_emlrtBCI, &c10_st);
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 1, 0);
  if (c10_good_rightx_indexs_size[0] < 0) {
    emlrtDynamicBoundsCheckR2012b(c10_good_rightx_indexs_size[0], 0, MAX_int32_T,
      &c10_g_emlrtBCI, &c10_st);
  }

  c10_d6 = static_cast<real_T>(c10_good_rightx_indexs_size[0]);
  if (covrtEmlIfEval(chartInstance->c10_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c10_covrtInstance,
        4U, 0U, 0U, c10_d6, 30.0, -1, 4U, static_cast<int32_T>(c10_d6 > 30.0))))
  {
    c10_line_flag = 1.0;
    c10_b_st.site = &c10_p_emlrtRSI;
    c10_x_current = c10_mean(chartInstance, &c10_b_st,
      chartInstance->c10_good_rightx_indexs_data, c10_good_rightx_indexs_size);
    c10_b_st.site = &c10_q_emlrtRSI;
    c10_c_st.site = &c10_g_emlrtRSI;
    c10_d_st.site = &c10_h_emlrtRSI;
    c10_y_current = c10_maximum(chartInstance, &c10_d_st,
      chartInstance->c10_good_righty_indexs_data, c10_good_righty_indexs_size);
  } else {
    c10_line_flag = 2.0;
    c10_b_st.site = &c10_m_emlrtRSI;
    c10_x_current = c10_mean(chartInstance, &c10_b_st,
      chartInstance->c10_good_leftx_indexs_data, c10_good_leftx_indexs_size);
    c10_b_st.site = &c10_o_emlrtRSI;
    c10_c_st.site = &c10_g_emlrtRSI;
    c10_d_st.site = &c10_h_emlrtRSI;
    c10_y_current = c10_maximum(chartInstance, &c10_d_st,
      chartInstance->c10_good_lefty_indexs_data, c10_good_lefty_indexs_size);
  }

  c10_count_left = 0.0;
  c10_count_right = 0.0;
  for (c10_m_i = 0; c10_m_i < 20; c10_m_i++) {
    c10_o_i = 1.0 + static_cast<real_T>(c10_m_i);
    covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 2, 1);
    if (covrtEmlIfEval(chartInstance->c10_covrtInstance, 4U, 0, 1,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c10_covrtInstance, 4U, 0U, 1U,
                        c10_line_flag, 1.0, -1, 0U, static_cast<int32_T>
                        (c10_line_flag == 1.0)))) {
      c10_win_y_low = c10_y_current - (c10_o_i + 1.0) * 24.0;
      c10_win_y_high = c10_y_current - c10_o_i * 24.0;
      c10_win_x_low = c10_x_current - 40.0;
      c10_win_x_high = c10_x_current + 40.0;
      if (c10_o_i != static_cast<real_T>(static_cast<int32_T>
           (muDoubleScalarFloor(c10_o_i)))) {
        emlrtIntegerCheckR2012b(c10_o_i, &c10_u_emlrtDCI, &c10_st);
      }

      c10_i48 = static_cast<int32_T>(c10_o_i);
      if ((c10_i48 < 1) || (c10_i48 > 42)) {
        emlrtDynamicBoundsCheckR2012b(c10_i48, 1, 42, &c10_cb_emlrtBCI, &c10_st);
      }

      c10_d7 = 20.0 + c10_o_i;
      if (c10_d7 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c10_d7)))) {
        emlrtIntegerCheckR2012b(c10_d7, &c10_v_emlrtDCI, &c10_st);
      }

      c10_i50 = static_cast<int32_T>(c10_d7);
      if ((c10_i50 < 1) || (c10_i50 > 42)) {
        emlrtDynamicBoundsCheckR2012b(c10_i50, 1, 42, &c10_db_emlrtBCI, &c10_st);
      }

      c10_tmp_size[0] = c10_nonzeroy_size[0];
      c10_hb_loop_ub = c10_nonzeroy_size[0] - 1;
      for (c10_i52 = 0; c10_i52 <= c10_hb_loop_ub; c10_i52++) {
        chartInstance->c10_tmp_data[c10_i52] = (chartInstance->
          c10_nonzeroy_data[c10_i52] >= c10_win_y_low);
      }

      c10_b_tmp_size[0] = c10_nonzeroy_size[0];
      c10_jb_loop_ub = c10_nonzeroy_size[0] - 1;
      for (c10_i54 = 0; c10_i54 <= c10_jb_loop_ub; c10_i54++) {
        chartInstance->c10_b_tmp_data[c10_i54] =
          (chartInstance->c10_nonzeroy_data[c10_i54] < c10_win_y_high);
      }

      if (c10_tmp_size[0] != c10_b_tmp_size[0]) {
        emlrtSizeEqCheck1DR2012b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_i_emlrtECI, &c10_st);
      }

      c10_mb_loop_ub = c10_tmp_size[0] - 1;
      for (c10_i56 = 0; c10_i56 <= c10_mb_loop_ub; c10_i56++) {
        chartInstance->c10_tmp_data[c10_i56] = (chartInstance->
          c10_tmp_data[c10_i56] && chartInstance->c10_b_tmp_data[c10_i56]);
      }

      c10_b_tmp_size[0] = c10_nonzerox_size[0];
      c10_pb_loop_ub = c10_nonzerox_size[0] - 1;
      for (c10_i58 = 0; c10_i58 <= c10_pb_loop_ub; c10_i58++) {
        chartInstance->c10_b_tmp_data[c10_i58] =
          (chartInstance->c10_nonzerox_data[c10_i58] >= c10_win_x_low);
      }

      if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_b_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_j_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
        c10_rb_loop_ub = c10_tmp_size[0] - 1;
        for (c10_i60 = 0; c10_i60 <= c10_rb_loop_ub; c10_i60++) {
          chartInstance->c10_tmp_data[c10_i60] = (chartInstance->
            c10_tmp_data[c10_i60] && chartInstance->c10_b_tmp_data[c10_i60]);
        }
      } else {
        c10_b_and(chartInstance, chartInstance->c10_tmp_data, c10_tmp_size,
                  chartInstance->c10_b_tmp_data, c10_b_tmp_size);
      }

      c10_b_tmp_size[0] = c10_nonzerox_size[0];
      c10_tb_loop_ub = c10_nonzerox_size[0] - 1;
      for (c10_i62 = 0; c10_i62 <= c10_tb_loop_ub; c10_i62++) {
        chartInstance->c10_b_tmp_data[c10_i62] =
          (chartInstance->c10_nonzerox_data[c10_i62] < c10_win_x_high);
      }

      if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_b_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_j_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
        c10_g_tmp_size[0] = c10_tmp_size[0];
        c10_vb_loop_ub = c10_tmp_size[0] - 1;
        for (c10_i64 = 0; c10_i64 <= c10_vb_loop_ub; c10_i64++) {
          chartInstance->c10_g_tmp_data[c10_i64] = (chartInstance->
            c10_tmp_data[c10_i64] && chartInstance->c10_b_tmp_data[c10_i64]);
        }
      } else {
        c10_and(chartInstance, chartInstance->c10_g_tmp_data, c10_g_tmp_size,
                chartInstance->c10_tmp_data, c10_tmp_size,
                chartInstance->c10_b_tmp_data, c10_b_tmp_size);
      }

      c10_e_end = c10_g_tmp_size[0];
      c10_e_trueCount = 0;
      for (c10_p_i = 0; c10_p_i < c10_e_end; c10_p_i++) {
        if (chartInstance->c10_g_tmp_data[c10_p_i]) {
          c10_e_trueCount++;
        }
      }

      c10_good_rightx_indexs_size[0] = c10_e_trueCount;
      c10_e_partialTrueCount = 0;
      for (c10_r_i = 0; c10_r_i < c10_e_end; c10_r_i++) {
        if (chartInstance->c10_g_tmp_data[c10_r_i]) {
          c10_i66 = c10_nonzerox_size[0] - 1;
          c10_d9 = static_cast<real_T>(c10_r_i);
          if (c10_d9 != static_cast<real_T>(static_cast<int32_T>
               (muDoubleScalarFloor(c10_d9)))) {
            emlrtIntegerCheckR2012b(c10_d9, &c10_db_emlrtDCI, &c10_st);
          }

          c10_i70 = static_cast<int32_T>(muDoubleScalarFloor(c10_d9));
          if ((c10_i70 < 0) || (c10_i70 > c10_i66)) {
            emlrtDynamicBoundsCheckR2012b(c10_i70, 0, c10_i66, &c10_kb_emlrtBCI,
              &c10_st);
          }

          chartInstance->c10_good_rightx_indexs_data[c10_e_partialTrueCount] =
            chartInstance->c10_nonzerox_data[c10_i70];
          c10_e_partialTrueCount++;
        }
      }

      c10_tmp_size[0] = c10_nonzeroy_size[0];
      c10_xb_loop_ub = c10_nonzeroy_size[0] - 1;
      for (c10_i67 = 0; c10_i67 <= c10_xb_loop_ub; c10_i67++) {
        chartInstance->c10_tmp_data[c10_i67] = (chartInstance->
          c10_nonzeroy_data[c10_i67] >= c10_win_y_low);
      }

      c10_b_tmp_size[0] = c10_nonzeroy_size[0];
      c10_ac_loop_ub = c10_nonzeroy_size[0] - 1;
      for (c10_i71 = 0; c10_i71 <= c10_ac_loop_ub; c10_i71++) {
        chartInstance->c10_b_tmp_data[c10_i71] =
          (chartInstance->c10_nonzeroy_data[c10_i71] < c10_win_y_high);
      }

      if (c10_tmp_size[0] != c10_b_tmp_size[0]) {
        emlrtSizeEqCheck1DR2012b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_k_emlrtECI, &c10_st);
      }

      c10_cc_loop_ub = c10_tmp_size[0] - 1;
      for (c10_i74 = 0; c10_i74 <= c10_cc_loop_ub; c10_i74++) {
        chartInstance->c10_tmp_data[c10_i74] = (chartInstance->
          c10_tmp_data[c10_i74] && chartInstance->c10_b_tmp_data[c10_i74]);
      }

      c10_b_tmp_size[0] = c10_nonzerox_size[0];
      c10_ec_loop_ub = c10_nonzerox_size[0] - 1;
      for (c10_i76 = 0; c10_i76 <= c10_ec_loop_ub; c10_i76++) {
        chartInstance->c10_b_tmp_data[c10_i76] =
          (chartInstance->c10_nonzerox_data[c10_i76] >= c10_win_x_low);
      }

      if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_b_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_m_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
        c10_gc_loop_ub = c10_tmp_size[0] - 1;
        for (c10_i78 = 0; c10_i78 <= c10_gc_loop_ub; c10_i78++) {
          chartInstance->c10_tmp_data[c10_i78] = (chartInstance->
            c10_tmp_data[c10_i78] && chartInstance->c10_b_tmp_data[c10_i78]);
        }
      } else {
        c10_b_and(chartInstance, chartInstance->c10_tmp_data, c10_tmp_size,
                  chartInstance->c10_b_tmp_data, c10_b_tmp_size);
      }

      c10_b_tmp_size[0] = c10_nonzerox_size[0];
      c10_ic_loop_ub = c10_nonzerox_size[0] - 1;
      for (c10_i80 = 0; c10_i80 <= c10_ic_loop_ub; c10_i80++) {
        chartInstance->c10_b_tmp_data[c10_i80] =
          (chartInstance->c10_nonzerox_data[c10_i80] < c10_win_x_high);
      }

      if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_b_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_m_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
        c10_i_tmp_size[0] = c10_tmp_size[0];
        c10_kc_loop_ub = c10_tmp_size[0] - 1;
        for (c10_i82 = 0; c10_i82 <= c10_kc_loop_ub; c10_i82++) {
          chartInstance->c10_i_tmp_data[c10_i82] = (chartInstance->
            c10_tmp_data[c10_i82] && chartInstance->c10_b_tmp_data[c10_i82]);
        }
      } else {
        c10_and(chartInstance, chartInstance->c10_i_tmp_data, c10_i_tmp_size,
                chartInstance->c10_tmp_data, c10_tmp_size,
                chartInstance->c10_b_tmp_data, c10_b_tmp_size);
      }

      c10_g_end = c10_i_tmp_size[0];
      c10_g_trueCount = 0;
      for (c10_t_i = 0; c10_t_i < c10_g_end; c10_t_i++) {
        if (chartInstance->c10_i_tmp_data[c10_t_i]) {
          c10_g_trueCount++;
        }
      }

      c10_good_righty_indexs_size[0] = c10_g_trueCount;
      for (c10_v_i = 0; c10_v_i < c10_g_end; c10_v_i++) {
        if (chartInstance->c10_i_tmp_data[c10_v_i]) {
          c10_i84 = c10_nonzeroy_size[0] - 1;
          c10_d12 = static_cast<real_T>(c10_v_i);
          if (c10_d12 != static_cast<real_T>(static_cast<int32_T>
               (muDoubleScalarFloor(c10_d12)))) {
            emlrtIntegerCheckR2012b(c10_d12, &c10_fb_emlrtDCI, &c10_st);
          }

          c10_i86 = static_cast<int32_T>(muDoubleScalarFloor(c10_d12));
          if ((c10_i86 < 0) || (c10_i86 > c10_i84)) {
            emlrtDynamicBoundsCheckR2012b(c10_i86, 0, c10_i84, &c10_ob_emlrtBCI,
              &c10_st);
          }
        }
      }

      if (c10_good_rightx_indexs_size[0] < 0) {
        emlrtDynamicBoundsCheckR2012b(c10_good_rightx_indexs_size[0], 0,
          MAX_int32_T, &c10_h_emlrtBCI, &c10_st);
      }

      c10_d11 = static_cast<real_T>(c10_good_rightx_indexs_size[0]);
      if (covrtEmlIfEval(chartInstance->c10_covrtInstance, 4U, 0, 2,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c10_covrtInstance, 4U, 0U, 2U, c10_d11,
                          30.0, -1, 4U, static_cast<int32_T>(c10_d11 > 30.0))))
      {
        c10_b_st.site = &c10_r_emlrtRSI;
        c10_x_current = c10_mean(chartInstance, &c10_b_st,
          chartInstance->c10_good_rightx_indexs_data,
          c10_good_rightx_indexs_size);
      }

      if (covrtEmlCondEval(chartInstance->c10_covrtInstance, 4U, 0, 0,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c10_covrtInstance, 4U, 0U, 3U,
                            c10_win_y_low, 300.0, -1, 4U, static_cast<int32_T>
                            (c10_win_y_low > 300.0))) && covrtEmlCondEval
          (chartInstance->c10_covrtInstance, 4U, 0, 1,
           covrtRelationalopUpdateFcn(chartInstance->c10_covrtInstance, 4U, 0U,
            4U, c10_win_y_low, 340.0, -1, 2U, static_cast<int32_T>(c10_win_y_low
             < 340.0)))) {
        covrtEmlMcdcEval(chartInstance->c10_covrtInstance, 4U, 0, 0, true);
        covrtEmlIfEval(chartInstance->c10_covrtInstance, 4U, 0, 3, true);
        c10_x_location = c10_x_current - 220.0;
      } else {
        covrtEmlMcdcEval(chartInstance->c10_covrtInstance, 4U, 0, 0, false);
        covrtEmlIfEval(chartInstance->c10_covrtInstance, 4U, 0, 3, false);
      }

      c10_d15 = c10_count_right + 1.0;
      if (c10_good_rightx_indexs_size[0] < 0) {
        emlrtDynamicBoundsCheckR2012b(c10_good_rightx_indexs_size[0], 0,
          MAX_int32_T, &c10_i_emlrtBCI, &c10_st);
      }

      c10_d17 = static_cast<real_T>(c10_good_rightx_indexs_size[0]);
      c10_i88 = static_cast<int32_T>(c10_d17 + (1.0 - c10_d15));
      emlrtForLoopVectorCheckR2021a(c10_d15, 1.0, c10_d17, mxDOUBLE_CLASS,
        c10_i88, &c10_cc_emlrtRTEI, &c10_st);
      for (c10_d_j = 0; c10_d_j < c10_i88; c10_d_j++) {
        c10_b_j = c10_d15 + static_cast<real_T>(c10_d_j);
        covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 3, 1);
        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_s_emlrtDCI, &c10_st);
        }

        c10_i90 = static_cast<int32_T>(c10_b_j);
        if ((c10_i90 < 1) || (c10_i90 > 100000)) {
          emlrtDynamicBoundsCheckR2012b(c10_i90, 1, 100000, &c10_ab_emlrtBCI,
            &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_e_emlrtDCI, &c10_st);
        }

        c10_i92 = static_cast<int32_T>(c10_b_j);
        if ((c10_i92 < 1) || (c10_i92 > c10_good_rightx_indexs_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c10_i92, 1, c10_good_rightx_indexs_size
            [0], &c10_j_emlrtBCI, &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_f_emlrtDCI, &c10_st);
        }

        c10_i94 = static_cast<int32_T>(c10_b_j);
        if ((c10_i94 < 1) || (c10_i94 > c10_good_righty_indexs_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c10_i94, 1, c10_good_righty_indexs_size
            [0], &c10_k_emlrtBCI, &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_p_emlrtDCI, &c10_st);
        }

        c10_i96 = static_cast<int32_T>(c10_b_j);
        if ((c10_i96 < 1) || (c10_i96 > 100000)) {
          emlrtDynamicBoundsCheckR2012b(c10_i96, 1, 100000, &c10_w_emlrtBCI,
            &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_g_emlrtDCI, &c10_st);
        }

        c10_i98 = static_cast<int32_T>(c10_b_j);
        if ((c10_i98 < 1) || (c10_i98 > c10_good_rightx_indexs_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c10_i98, 1, c10_good_rightx_indexs_size
            [0], &c10_m_emlrtBCI, &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_h_emlrtDCI, &c10_st);
        }

        c10_i100 = static_cast<int32_T>(c10_b_j);
        if ((c10_i100 < 1) || (c10_i100 > c10_good_righty_indexs_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c10_i100, 1,
            c10_good_righty_indexs_size[0], &c10_o_emlrtBCI, &c10_st);
        }

        c10_count_right++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 3, 0);
    }

    if (covrtEmlIfEval(chartInstance->c10_covrtInstance, 4U, 0, 4,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c10_covrtInstance, 4U, 0U, 5U,
                        c10_line_flag, 2.0, -1, 0U, static_cast<int32_T>
                        (c10_line_flag == 2.0)))) {
      c10_win_y_low = c10_y_current - (c10_o_i + 1.0) * 24.0;
      c10_win_y_high = c10_y_current - c10_o_i * 24.0;
      c10_win_x_low = c10_x_current - 40.0;
      c10_win_x_high = c10_x_current + 40.0;
      if (c10_o_i != static_cast<real_T>(static_cast<int32_T>
           (muDoubleScalarFloor(c10_o_i)))) {
        emlrtIntegerCheckR2012b(c10_o_i, &c10_w_emlrtDCI, &c10_st);
      }

      c10_i49 = static_cast<int32_T>(c10_o_i);
      if ((c10_i49 < 1) || (c10_i49 > 42)) {
        emlrtDynamicBoundsCheckR2012b(c10_i49, 1, 42, &c10_eb_emlrtBCI, &c10_st);
      }

      c10_d8 = 20.0 + c10_o_i;
      if (c10_d8 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c10_d8)))) {
        emlrtIntegerCheckR2012b(c10_d8, &c10_x_emlrtDCI, &c10_st);
      }

      c10_i51 = static_cast<int32_T>(c10_d8);
      if ((c10_i51 < 1) || (c10_i51 > 42)) {
        emlrtDynamicBoundsCheckR2012b(c10_i51, 1, 42, &c10_fb_emlrtBCI, &c10_st);
      }

      c10_tmp_size[0] = c10_nonzeroy_size[0];
      c10_ib_loop_ub = c10_nonzeroy_size[0] - 1;
      for (c10_i53 = 0; c10_i53 <= c10_ib_loop_ub; c10_i53++) {
        chartInstance->c10_tmp_data[c10_i53] = (chartInstance->
          c10_nonzeroy_data[c10_i53] >= c10_win_y_low);
      }

      c10_b_tmp_size[0] = c10_nonzeroy_size[0];
      c10_kb_loop_ub = c10_nonzeroy_size[0] - 1;
      for (c10_i55 = 0; c10_i55 <= c10_kb_loop_ub; c10_i55++) {
        chartInstance->c10_b_tmp_data[c10_i55] =
          (chartInstance->c10_nonzeroy_data[c10_i55] < c10_win_y_high);
      }

      if (c10_tmp_size[0] != c10_b_tmp_size[0]) {
        emlrtSizeEqCheck1DR2012b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_o_emlrtECI, &c10_st);
      }

      c10_ob_loop_ub = c10_tmp_size[0] - 1;
      for (c10_i57 = 0; c10_i57 <= c10_ob_loop_ub; c10_i57++) {
        chartInstance->c10_tmp_data[c10_i57] = (chartInstance->
          c10_tmp_data[c10_i57] && chartInstance->c10_b_tmp_data[c10_i57]);
      }

      c10_b_tmp_size[0] = c10_nonzerox_size[0];
      c10_qb_loop_ub = c10_nonzerox_size[0] - 1;
      for (c10_i59 = 0; c10_i59 <= c10_qb_loop_ub; c10_i59++) {
        chartInstance->c10_b_tmp_data[c10_i59] =
          (chartInstance->c10_nonzerox_data[c10_i59] >= c10_win_x_low);
      }

      if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_b_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_p_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
        c10_sb_loop_ub = c10_tmp_size[0] - 1;
        for (c10_i61 = 0; c10_i61 <= c10_sb_loop_ub; c10_i61++) {
          chartInstance->c10_tmp_data[c10_i61] = (chartInstance->
            c10_tmp_data[c10_i61] && chartInstance->c10_b_tmp_data[c10_i61]);
        }
      } else {
        c10_b_and(chartInstance, chartInstance->c10_tmp_data, c10_tmp_size,
                  chartInstance->c10_b_tmp_data, c10_b_tmp_size);
      }

      c10_b_tmp_size[0] = c10_nonzerox_size[0];
      c10_ub_loop_ub = c10_nonzerox_size[0] - 1;
      for (c10_i63 = 0; c10_i63 <= c10_ub_loop_ub; c10_i63++) {
        chartInstance->c10_b_tmp_data[c10_i63] =
          (chartInstance->c10_nonzerox_data[c10_i63] < c10_win_x_high);
      }

      if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_b_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_p_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
        c10_h_tmp_size[0] = c10_tmp_size[0];
        c10_wb_loop_ub = c10_tmp_size[0] - 1;
        for (c10_i65 = 0; c10_i65 <= c10_wb_loop_ub; c10_i65++) {
          chartInstance->c10_h_tmp_data[c10_i65] = (chartInstance->
            c10_tmp_data[c10_i65] && chartInstance->c10_b_tmp_data[c10_i65]);
        }
      } else {
        c10_and(chartInstance, chartInstance->c10_h_tmp_data, c10_h_tmp_size,
                chartInstance->c10_tmp_data, c10_tmp_size,
                chartInstance->c10_b_tmp_data, c10_b_tmp_size);
      }

      c10_f_end = c10_h_tmp_size[0];
      c10_f_trueCount = 0;
      for (c10_q_i = 0; c10_q_i < c10_f_end; c10_q_i++) {
        if (chartInstance->c10_h_tmp_data[c10_q_i]) {
          c10_f_trueCount++;
        }
      }

      c10_good_leftx_indexs_size[0] = c10_f_trueCount;
      c10_f_partialTrueCount = 0;
      for (c10_s_i = 0; c10_s_i < c10_f_end; c10_s_i++) {
        if (chartInstance->c10_h_tmp_data[c10_s_i]) {
          c10_i68 = c10_nonzerox_size[0] - 1;
          c10_d10 = static_cast<real_T>(c10_s_i);
          if (c10_d10 != static_cast<real_T>(static_cast<int32_T>
               (muDoubleScalarFloor(c10_d10)))) {
            emlrtIntegerCheckR2012b(c10_d10, &c10_eb_emlrtDCI, &c10_st);
          }

          c10_i72 = static_cast<int32_T>(muDoubleScalarFloor(c10_d10));
          if ((c10_i72 < 0) || (c10_i72 > c10_i68)) {
            emlrtDynamicBoundsCheckR2012b(c10_i72, 0, c10_i68, &c10_mb_emlrtBCI,
              &c10_st);
          }

          chartInstance->c10_good_leftx_indexs_data[c10_f_partialTrueCount] =
            chartInstance->c10_nonzerox_data[c10_i72];
          c10_f_partialTrueCount++;
        }
      }

      c10_tmp_size[0] = c10_nonzeroy_size[0];
      c10_yb_loop_ub = c10_nonzeroy_size[0] - 1;
      for (c10_i69 = 0; c10_i69 <= c10_yb_loop_ub; c10_i69++) {
        chartInstance->c10_tmp_data[c10_i69] = (chartInstance->
          c10_nonzeroy_data[c10_i69] >= c10_win_y_low);
      }

      c10_b_tmp_size[0] = c10_nonzeroy_size[0];
      c10_bc_loop_ub = c10_nonzeroy_size[0] - 1;
      for (c10_i73 = 0; c10_i73 <= c10_bc_loop_ub; c10_i73++) {
        chartInstance->c10_b_tmp_data[c10_i73] =
          (chartInstance->c10_nonzeroy_data[c10_i73] < c10_win_y_high);
      }

      if (c10_tmp_size[0] != c10_b_tmp_size[0]) {
        emlrtSizeEqCheck1DR2012b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_q_emlrtECI, &c10_st);
      }

      c10_dc_loop_ub = c10_tmp_size[0] - 1;
      for (c10_i75 = 0; c10_i75 <= c10_dc_loop_ub; c10_i75++) {
        chartInstance->c10_tmp_data[c10_i75] = (chartInstance->
          c10_tmp_data[c10_i75] && chartInstance->c10_b_tmp_data[c10_i75]);
      }

      c10_b_tmp_size[0] = c10_nonzerox_size[0];
      c10_fc_loop_ub = c10_nonzerox_size[0] - 1;
      for (c10_i77 = 0; c10_i77 <= c10_fc_loop_ub; c10_i77++) {
        chartInstance->c10_b_tmp_data[c10_i77] =
          (chartInstance->c10_nonzerox_data[c10_i77] >= c10_win_x_low);
      }

      if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_b_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_r_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
        c10_hc_loop_ub = c10_tmp_size[0] - 1;
        for (c10_i79 = 0; c10_i79 <= c10_hc_loop_ub; c10_i79++) {
          chartInstance->c10_tmp_data[c10_i79] = (chartInstance->
            c10_tmp_data[c10_i79] && chartInstance->c10_b_tmp_data[c10_i79]);
        }
      } else {
        c10_b_and(chartInstance, chartInstance->c10_tmp_data, c10_tmp_size,
                  chartInstance->c10_b_tmp_data, c10_b_tmp_size);
      }

      c10_b_tmp_size[0] = c10_nonzerox_size[0];
      c10_jc_loop_ub = c10_nonzerox_size[0] - 1;
      for (c10_i81 = 0; c10_i81 <= c10_jc_loop_ub; c10_i81++) {
        chartInstance->c10_b_tmp_data[c10_i81] =
          (chartInstance->c10_nonzerox_data[c10_i81] < c10_win_x_high);
      }

      if ((c10_tmp_size[0] != c10_b_tmp_size[0]) && ((c10_tmp_size[0] != 1) &&
           (c10_b_tmp_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c10_tmp_size[0], c10_b_tmp_size[0],
          &c10_r_emlrtECI, &c10_st);
      }

      if (c10_tmp_size[0] == c10_b_tmp_size[0]) {
        c10_j_tmp_size[0] = c10_tmp_size[0];
        c10_mc_loop_ub = c10_tmp_size[0] - 1;
        for (c10_i83 = 0; c10_i83 <= c10_mc_loop_ub; c10_i83++) {
          chartInstance->c10_j_tmp_data[c10_i83] = (chartInstance->
            c10_tmp_data[c10_i83] && chartInstance->c10_b_tmp_data[c10_i83]);
        }
      } else {
        c10_and(chartInstance, chartInstance->c10_j_tmp_data, c10_j_tmp_size,
                chartInstance->c10_tmp_data, c10_tmp_size,
                chartInstance->c10_b_tmp_data, c10_b_tmp_size);
      }

      c10_h_end = c10_j_tmp_size[0];
      c10_h_trueCount = 0;
      for (c10_u_i = 0; c10_u_i < c10_h_end; c10_u_i++) {
        if (chartInstance->c10_j_tmp_data[c10_u_i]) {
          c10_h_trueCount++;
        }
      }

      c10_good_lefty_indexs_size[0] = c10_h_trueCount;
      for (c10_w_i = 0; c10_w_i < c10_h_end; c10_w_i++) {
        if (chartInstance->c10_j_tmp_data[c10_w_i]) {
          c10_i85 = c10_nonzeroy_size[0] - 1;
          c10_d14 = static_cast<real_T>(c10_w_i);
          if (c10_d14 != static_cast<real_T>(static_cast<int32_T>
               (muDoubleScalarFloor(c10_d14)))) {
            emlrtIntegerCheckR2012b(c10_d14, &c10_gb_emlrtDCI, &c10_st);
          }

          c10_i87 = static_cast<int32_T>(muDoubleScalarFloor(c10_d14));
          if ((c10_i87 < 0) || (c10_i87 > c10_i85)) {
            emlrtDynamicBoundsCheckR2012b(c10_i87, 0, c10_i85, &c10_pb_emlrtBCI,
              &c10_st);
          }
        }
      }

      if (c10_good_leftx_indexs_size[0] < 0) {
        emlrtDynamicBoundsCheckR2012b(c10_good_leftx_indexs_size[0], 0,
          MAX_int32_T, &c10_p_emlrtBCI, &c10_st);
      }

      c10_d13 = static_cast<real_T>(c10_good_leftx_indexs_size[0]);
      if (covrtEmlIfEval(chartInstance->c10_covrtInstance, 4U, 0, 5,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c10_covrtInstance, 4U, 0U, 6U, c10_d13,
                          30.0, -1, 4U, static_cast<int32_T>(c10_d13 > 30.0))))
      {
        c10_b_st.site = &c10_s_emlrtRSI;
        c10_x_current = c10_mean(chartInstance, &c10_b_st,
          chartInstance->c10_good_leftx_indexs_data, c10_good_leftx_indexs_size);
      }

      if (covrtEmlCondEval(chartInstance->c10_covrtInstance, 4U, 0, 2,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c10_covrtInstance, 4U, 0U, 7U,
                            c10_win_y_low, 300.0, -1, 4U, static_cast<int32_T>
                            (c10_win_y_low > 300.0))) && covrtEmlCondEval
          (chartInstance->c10_covrtInstance, 4U, 0, 3,
           covrtRelationalopUpdateFcn(chartInstance->c10_covrtInstance, 4U, 0U,
            8U, c10_win_y_low, 340.0, -1, 2U, static_cast<int32_T>(c10_win_y_low
             < 340.0)))) {
        covrtEmlMcdcEval(chartInstance->c10_covrtInstance, 4U, 0, 1, true);
        covrtEmlIfEval(chartInstance->c10_covrtInstance, 4U, 0, 6, true);
        c10_x_location = c10_x_current + 290.0;
      } else {
        covrtEmlMcdcEval(chartInstance->c10_covrtInstance, 4U, 0, 1, false);
        covrtEmlIfEval(chartInstance->c10_covrtInstance, 4U, 0, 6, false);
      }

      c10_d16 = c10_count_left + 1.0;
      if (c10_good_leftx_indexs_size[0] < 0) {
        emlrtDynamicBoundsCheckR2012b(c10_good_leftx_indexs_size[0], 0,
          MAX_int32_T, &c10_q_emlrtBCI, &c10_st);
      }

      c10_d18 = static_cast<real_T>(c10_good_leftx_indexs_size[0]);
      c10_i89 = static_cast<int32_T>(c10_d18 + (1.0 - c10_d16));
      emlrtForLoopVectorCheckR2021a(c10_d16, 1.0, c10_d18, mxDOUBLE_CLASS,
        c10_i89, &c10_dc_emlrtRTEI, &c10_st);
      for (c10_e_j = 0; c10_e_j < c10_i89; c10_e_j++) {
        c10_b_j = c10_d16 + static_cast<real_T>(c10_e_j);
        covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 4, 1);
        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_q_emlrtDCI, &c10_st);
        }

        c10_i91 = static_cast<int32_T>(c10_b_j);
        if ((c10_i91 < 1) || (c10_i91 > 100000)) {
          emlrtDynamicBoundsCheckR2012b(c10_i91, 1, 100000, &c10_x_emlrtBCI,
            &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_i_emlrtDCI, &c10_st);
        }

        c10_i93 = static_cast<int32_T>(c10_b_j);
        if ((c10_i93 < 1) || (c10_i93 > c10_good_leftx_indexs_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c10_i93, 1, c10_good_leftx_indexs_size[0],
            &c10_r_emlrtBCI, &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_j_emlrtDCI, &c10_st);
        }

        c10_i95 = static_cast<int32_T>(c10_b_j);
        if ((c10_i95 < 1) || (c10_i95 > c10_good_lefty_indexs_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c10_i95, 1, c10_good_lefty_indexs_size[0],
            &c10_s_emlrtBCI, &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_t_emlrtDCI, &c10_st);
        }

        c10_i97 = static_cast<int32_T>(c10_b_j);
        if ((c10_i97 < 1) || (c10_i97 > 100000)) {
          emlrtDynamicBoundsCheckR2012b(c10_i97, 1, 100000, &c10_bb_emlrtBCI,
            &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_k_emlrtDCI, &c10_st);
        }

        c10_i99 = static_cast<int32_T>(c10_b_j);
        if ((c10_i99 < 1) || (c10_i99 > c10_good_leftx_indexs_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c10_i99, 1, c10_good_leftx_indexs_size[0],
            &c10_t_emlrtBCI, &c10_st);
        }

        if (c10_b_j != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c10_b_j)))) {
          emlrtIntegerCheckR2012b(c10_b_j, &c10_m_emlrtDCI, &c10_st);
        }

        c10_i101 = static_cast<int32_T>(c10_b_j);
        if ((c10_i101 < 1) || (c10_i101 > c10_good_lefty_indexs_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c10_i101, 1, c10_good_lefty_indexs_size
            [0], &c10_u_emlrtBCI, &c10_st);
        }

        c10_count_left++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 4, 0);
    }

    c10_b_error = 340.0 - c10_x_location;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c10_covrtInstance, 4U, 0, 2, 0);
  *chartInstance->c10_error = c10_b_error;
  c10_do_animation_call_c10_Rpi_cam(chartInstance);
  covrtSigUpdateFcn(chartInstance->c10_covrtInstance, 1U,
                    *chartInstance->c10_error);
}

static void ext_mode_exec_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance)
{
}

static void c10_update_jit_animation_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance)
{
}

static void c10_do_animation_call_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance)
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
    &chartInstance->c10_is_active_c10_Rpi_cam, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_st)
{
  const mxArray *c10_u;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  *chartInstance->c10_error = c10_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 0)), "error");
  chartInstance->c10_is_active_c10_Rpi_cam = c10_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
     "is_active_c10_Rpi_cam");
  sf_mex_destroy(&c10_u);
  sf_mex_destroy(&c10_st);
}

static void initSimStructsc10_Rpi_cam(SFc10_Rpi_camInstanceStruct *chartInstance)
{
}

static void initSubchartIOPointersc10_Rpi_cam(SFc10_Rpi_camInstanceStruct
  *chartInstance)
{
}

static void c10_eml_find(SFc10_Rpi_camInstanceStruct *chartInstance, boolean_T
  c10_x[307200], int32_T c10_i_data[], int32_T c10_i_size[1], int32_T
  c10_j_data[], int32_T c10_j_size[1])
{
  int32_T c10_b_ii;
  int32_T c10_i;
  int32_T c10_i1;
  int32_T c10_idx;
  int32_T c10_jj;
  boolean_T c10_b;
  boolean_T c10_b_b1;
  boolean_T c10_exitg1;
  boolean_T c10_guard1;
  c10_idx = 0;
  c10_b_ii = 1;
  c10_jj = 1;
  c10_exitg1 = false;
  while ((!c10_exitg1) && (c10_jj <= 640)) {
    c10_guard1 = false;
    if (c10_x[(c10_b_ii + 480 * (c10_jj - 1)) - 1]) {
      c10_idx++;
      c10_i_data[c10_idx - 1] = c10_b_ii;
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
      c10_b_ii++;
      if (c10_b_ii > 480) {
        c10_b_ii = 1;
        c10_jj++;
      }
    }
  }

  c10_b = (c10_idx < 1);
  if (c10_b) {
    c10_i = 0;
  } else {
    c10_i = c10_idx;
  }

  c10_indexShapeCheck(chartInstance);
  c10_i_size[0] = c10_i;
  c10_b_b1 = (c10_idx < 1);
  if (c10_b_b1) {
    c10_i1 = 0;
  } else {
    c10_i1 = c10_idx;
  }

  c10_indexShapeCheck(chartInstance);
  c10_j_size[0] = c10_i1;
  c10_indexShapeCheck(chartInstance);
}

static void c10_indexShapeCheck(SFc10_Rpi_camInstanceStruct *chartInstance)
{
}

static real_T c10_mean(SFc10_Rpi_camInstanceStruct *chartInstance, const
  emlrtStack *c10_sp, real_T c10_x_data[], int32_T c10_x_size[1])
{
  const mxArray *c10_b_y{ nullptr };

  const mxArray *c10_c_y{ nullptr };

  real_T c10_d_y;
  real_T c10_s;
  int32_T c10_a;
  int32_T c10_b_ib;
  int32_T c10_b_vlen;
  int32_T c10_c_vlen;
  int32_T c10_d_vlen;
  int32_T c10_inb;
  int32_T c10_lidx;
  int32_T c10_nfb;
  int32_T c10_nleft;
  int32_T c10_vlen;
  boolean_T c10_b;
  if ((c10_x_size[0] == 1) || (static_cast<real_T>(c10_x_size[0]) != 1.0)) {
    c10_b = true;
  } else {
    c10_b = false;
  }

  if (!c10_b) {
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

  c10_vlen = c10_x_size[0];
  c10_b_vlen = c10_vlen;
  if ((c10_x_size[0] == 0) || (c10_b_vlen == 0)) {
    c10_d_y = 0.0;
  } else {
    c10_c_vlen = c10_b_vlen;
    c10_d_vlen = c10_c_vlen;
    if (c10_d_vlen < 4096) {
      c10_d_y = c10_sumColumnB(chartInstance, c10_x_data, c10_d_vlen);
    } else {
      c10_a = c10_d_vlen;
      c10_nfb = static_cast<int32_T>(static_cast<uint32_T>(c10_a) >> 12);
      c10_inb = c10_nfb << 12;
      c10_lidx = c10_inb;
      c10_nleft = c10_d_vlen - c10_inb;
      c10_s = c10_sumColumnB4(chartInstance, c10_x_data, 1);
      for (c10_b_ib = 2; c10_b_ib <= c10_nfb; c10_b_ib++) {
        c10_s += c10_sumColumnB4(chartInstance, c10_x_data, 1 + ((c10_b_ib - 1) <<
          12));
      }

      if (c10_nleft > 0) {
        c10_s += c10_b_sumColumnB(chartInstance, c10_x_data, c10_nleft, c10_lidx
          + 1);
      }

      c10_d_y = c10_s;
    }
  }

  return c10_d_y / static_cast<real_T>(c10_x_size[0]);
}

static real_T c10_sumColumnB(SFc10_Rpi_camInstanceStruct *chartInstance, real_T
  c10_x_data[], int32_T c10_vlen)
{
  real_T c10_b_y;
  real_T c10_c_y;
  real_T c10_y;
  int32_T c10_a;
  int32_T c10_b_k;
  int32_T c10_b_vlen;
  int32_T c10_b_vstart;
  int32_T c10_c_vlen;
  int32_T c10_d_k;
  int32_T c10_e_k;
  int32_T c10_f_k;
  int32_T c10_g_k;
  int32_T c10_h_k;
  int32_T c10_i;
  int32_T c10_i1;
  int32_T c10_i2;
  int32_T c10_i_k;
  int32_T c10_inb;
  int32_T c10_j_k;
  int32_T c10_k;
  int32_T c10_lidx;
  int32_T c10_nfb;
  int32_T c10_nleft;
  int32_T c10_vstart;
  if (c10_vlen <= 1024) {
    c10_b_vlen = c10_vlen - 1;
    c10_y = c10_x_data[0];
    c10_i = c10_b_vlen;
    c10_i1 = static_cast<uint16_T>(c10_i) - 1;
    for (c10_b_k = 0; c10_b_k <= c10_i1; c10_b_k++) {
      c10_f_k = c10_b_k;
      c10_y += c10_x_data[c10_f_k + 1];
    }
  } else {
    c10_a = c10_vlen;
    c10_nfb = static_cast<int32_T>(static_cast<uint32_T>(c10_a) >> 10);
    c10_inb = c10_nfb << 10;
    c10_y = c10_x_data[0];
    for (c10_k = 0; c10_k < 1023; c10_k++) {
      c10_e_k = c10_k;
      c10_y += c10_x_data[c10_e_k + 1];
    }

    for (c10_d_k = 2; c10_d_k <= c10_nfb; c10_d_k++) {
      c10_vstart = (c10_d_k - 1) << 10;
      c10_b_y = c10_x_data[c10_vstart];
      for (c10_g_k = 0; c10_g_k < 1023; c10_g_k++) {
        c10_h_k = c10_g_k;
        c10_b_y += c10_x_data[(c10_vstart + c10_h_k) + 1];
      }

      c10_y += c10_b_y;
    }

    if (c10_vlen > c10_inb) {
      c10_nleft = c10_vlen - c10_inb;
      c10_lidx = c10_inb;
      c10_c_vlen = c10_nleft - 1;
      c10_b_vstart = c10_lidx;
      c10_c_y = c10_x_data[c10_b_vstart];
      c10_i2 = c10_c_vlen - 1;
      for (c10_i_k = 0; c10_i_k <= c10_i2; c10_i_k++) {
        c10_j_k = c10_i_k;
        c10_c_y += c10_x_data[(c10_b_vstart + c10_j_k) + 1];
      }

      c10_y += c10_c_y;
    }
  }

  return c10_y;
}

static real_T c10_sumColumnB4(SFc10_Rpi_camInstanceStruct *chartInstance, real_T
  c10_x_data[], int32_T c10_vstart)
{
  real_T c10_psum1;
  real_T c10_psum2;
  real_T c10_psum3;
  real_T c10_psum4;
  int32_T c10_b_k;
  int32_T c10_i2;
  int32_T c10_i3;
  int32_T c10_i4;
  int32_T c10_k;
  c10_i2 = c10_vstart + 1023;
  c10_i3 = c10_vstart + 2047;
  c10_i4 = c10_vstart + 3071;
  c10_psum1 = c10_x_data[c10_vstart - 1];
  c10_psum2 = c10_x_data[c10_i2];
  c10_psum3 = c10_x_data[c10_i3];
  c10_psum4 = c10_x_data[c10_i4];
  for (c10_k = 0; c10_k < 1023; c10_k++) {
    c10_b_k = c10_k + 1;
    c10_psum1 += c10_x_data[(c10_vstart + c10_b_k) - 1];
    c10_psum2 += c10_x_data[c10_i2 + c10_b_k];
    c10_psum3 += c10_x_data[c10_i3 + c10_b_k];
    c10_psum4 += c10_x_data[c10_i4 + c10_b_k];
  }

  return (c10_psum1 + c10_psum2) + (c10_psum3 + c10_psum4);
}

static real_T c10_b_sumColumnB(SFc10_Rpi_camInstanceStruct *chartInstance,
  real_T c10_x_data[], int32_T c10_vlen, int32_T c10_vstart)
{
  real_T c10_b_y;
  real_T c10_c_y;
  real_T c10_y;
  int32_T c10_a;
  int32_T c10_b_k;
  int32_T c10_b_vlen;
  int32_T c10_b_vstart;
  int32_T c10_c_vlen;
  int32_T c10_c_vstart;
  int32_T c10_d_k;
  int32_T c10_d_vstart;
  int32_T c10_e_k;
  int32_T c10_e_vstart;
  int32_T c10_f_k;
  int32_T c10_g_k;
  int32_T c10_h_k;
  int32_T c10_i;
  int32_T c10_i1;
  int32_T c10_i_k;
  int32_T c10_inb;
  int32_T c10_j_k;
  int32_T c10_k;
  int32_T c10_lidx;
  int32_T c10_nfb;
  int32_T c10_nleft;
  if (c10_vlen <= 1024) {
    c10_b_vlen = c10_vlen - 1;
    c10_b_vstart = c10_vstart - 1;
    c10_y = c10_x_data[c10_b_vstart];
    c10_i = c10_b_vlen - 1;
    for (c10_k = 0; c10_k <= c10_i; c10_k++) {
      c10_d_k = c10_k;
      c10_y += c10_x_data[(c10_b_vstart + c10_d_k) + 1];
    }
  } else {
    c10_a = c10_vlen;
    c10_nfb = static_cast<int32_T>(static_cast<uint32_T>(c10_a) >> 10);
    c10_inb = c10_nfb << 10;
    c10_c_vstart = c10_vstart - 1;
    c10_y = c10_x_data[c10_c_vstart];
    for (c10_b_k = 0; c10_b_k < 1023; c10_b_k++) {
      c10_f_k = c10_b_k;
      c10_y += c10_x_data[(c10_c_vstart + c10_f_k) + 1];
    }

    for (c10_e_k = 2; c10_e_k <= c10_nfb; c10_e_k++) {
      c10_d_vstart = (c10_vstart + ((c10_e_k - 1) << 10)) - 1;
      c10_b_y = c10_x_data[c10_d_vstart];
      for (c10_g_k = 0; c10_g_k < 1023; c10_g_k++) {
        c10_h_k = c10_g_k;
        c10_b_y += c10_x_data[(c10_d_vstart + c10_h_k) + 1];
      }

      c10_y += c10_b_y;
    }

    if (c10_vlen > c10_inb) {
      c10_nleft = c10_vlen - c10_inb;
      c10_lidx = c10_vstart + c10_inb;
      c10_c_vlen = c10_nleft - 1;
      c10_e_vstart = c10_lidx - 1;
      c10_c_y = c10_x_data[c10_e_vstart];
      c10_i1 = c10_c_vlen - 1;
      for (c10_i_k = 0; c10_i_k <= c10_i1; c10_i_k++) {
        c10_j_k = c10_i_k;
        c10_c_y += c10_x_data[(c10_e_vstart + c10_j_k) + 1];
      }

      c10_y += c10_c_y;
    }
  }

  return c10_y;
}

static real_T c10_maximum(SFc10_Rpi_camInstanceStruct *chartInstance, const
  emlrtStack *c10_sp, real_T c10_x_data[], int32_T c10_x_size[1])
{
  static char_T c10_b_cv[39]{ 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  emlrtStack c10_st;
  const mxArray *c10_b_y{ nullptr };

  const mxArray *c10_c_y{ nullptr };

  const mxArray *c10_d_y{ nullptr };

  const mxArray *c10_y{ nullptr };

  real_T c10_b_ex;
  real_T c10_ex;
  int32_T c10_a;
  int32_T c10_b_last;
  int32_T c10_c;
  int32_T c10_k;
  int32_T c10_last;
  int32_T c10_nx;
  boolean_T c10_b;
  c10_st.prev = c10_sp;
  c10_st.tls = c10_sp->tls;
  c10_st.site = &c10_i_emlrtRSI;
  if ((c10_x_size[0] == 1) || (static_cast<real_T>(c10_x_size[0]) != 1.0)) {
    c10_b = true;
  } else {
    c10_b = false;
  }

  if (!c10_b) {
    c10_y = nullptr;
    sf_mex_assign(&c10_y, sf_mex_create("y", c10_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c10_c_y = nullptr;
    sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c10_st, &c10_d_emlrtMCI, "error", 0U, 2U, 14, c10_y, 14,
                sf_mex_call(&c10_st, nullptr, "getString", 1U, 1U, 14,
      sf_mex_call(&c10_st, nullptr, "message", 1U, 1U, 14, c10_c_y)));
  }

  if (!(static_cast<real_T>(c10_x_size[0]) >= 1.0)) {
    c10_b_y = nullptr;
    sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_b_cv, 10, 0U, 1U, 0U, 2, 1,
      39), false);
    c10_d_y = nullptr;
    sf_mex_assign(&c10_d_y, sf_mex_create("y", c10_b_cv, 10, 0U, 1U, 0U, 2, 1,
      39), false);
    sf_mex_call(&c10_st, &c10_e_emlrtMCI, "error", 0U, 2U, 14, c10_b_y, 14,
                sf_mex_call(&c10_st, nullptr, "getString", 1U, 1U, 14,
      sf_mex_call(&c10_st, nullptr, "message", 1U, 1U, 14, c10_d_y)));
  }

  c10_last = c10_x_size[0] - 1;
  c10_a = c10_last;
  c10_c = c10_a + 1;
  c10_nx = c10_c;
  if (c10_nx <= 2) {
    if (c10_nx == 1) {
      c10_ex = c10_x_data[0];
    } else if (c10_x_data[0] < c10_x_data[c10_last]) {
      c10_ex = c10_x_data[c10_last];
    } else {
      c10_ex = c10_x_data[0];
    }
  } else {
    c10_b_last = c10_last + 1;
    c10_b_ex = c10_x_data[0];
    for (c10_k = 2; c10_k <= c10_b_last; c10_k++) {
      if (c10_b_ex < c10_x_data[c10_k - 1]) {
        c10_b_ex = c10_x_data[c10_k - 1];
      }
    }

    c10_ex = c10_b_ex;
  }

  return c10_ex;
}

const mxArray *sf_c10_Rpi_cam_get_eml_resolved_functions_info()
{
  const mxArray *c10_nameCaptureInfo{ nullptr };

  c10_nameCaptureInfo = nullptr;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_create("nameCaptureInfo", nullptr,
    0, 0U, 1U, 0U, 2, 0, 1), false);
  return c10_nameCaptureInfo;
}

static real_T c10_emlrt_marshallIn(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_nullptr, const char_T *c10_identifier)
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

static real_T c10_b_emlrt_marshallIn(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_d;
  real_T c10_y;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static uint8_T c10_c_emlrt_marshallIn(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_nullptr, const char_T *c10_identifier)
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

static uint8_T c10_d_emlrt_marshallIn(SFc10_Rpi_camInstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_b_u;
  uint8_T c10_y;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_b_u, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_b_u;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_slStringInitializeDynamicBuffers(SFc10_Rpi_camInstanceStruct
  *chartInstance)
{
}

static void c10_chart_data_browse_helper(SFc10_Rpi_camInstanceStruct
  *chartInstance, int32_T c10_ssIdNumber, const mxArray **c10_mxData, uint8_T
  *c10_isValueTooBig)
{
  real_T c10_d;
  *c10_mxData = nullptr;
  *c10_mxData = nullptr;
  *c10_isValueTooBig = 0U;
  switch (c10_ssIdNumber) {
   case 6U:
    *c10_isValueTooBig = 1U;
    break;

   case 15U:
    c10_d = *chartInstance->c10_error;
    sf_mex_assign(c10_mxData, sf_mex_create("mxData", &c10_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }
}

static void c10_and(SFc10_Rpi_camInstanceStruct *chartInstance, boolean_T
                    c10_b_in1_data[], int32_T c10_in1_size[1], boolean_T
                    c10_b_in2_data[], int32_T c10_in2_size[1], boolean_T
                    c10_in3_data[], int32_T c10_in3_size[1])
{
  int32_T c10_b_in2_size[1];
  int32_T c10_aux_0_0;
  int32_T c10_aux_1_0;
  int32_T c10_b_loop_ub;
  int32_T c10_i;
  int32_T c10_i1;
  int32_T c10_i2;
  int32_T c10_loop_ub;
  int32_T c10_stride_0_0;
  int32_T c10_stride_1_0;
  if (c10_in3_size[0] == 1) {
    c10_b_in2_size[0] = c10_in2_size[0];
  } else {
    c10_b_in2_size[0] = c10_in3_size[0];
  }

  c10_stride_0_0 = static_cast<int32_T>(c10_in2_size[0] != 1);
  c10_stride_1_0 = static_cast<int32_T>(c10_in3_size[0] != 1);
  c10_aux_0_0 = 0;
  c10_aux_1_0 = 0;
  if (c10_in3_size[0] == 1) {
    c10_i = c10_in2_size[0];
  } else {
    c10_i = c10_in3_size[0];
  }

  c10_loop_ub = c10_i - 1;
  for (c10_i1 = 0; c10_i1 <= c10_loop_ub; c10_i1++) {
    chartInstance->c10_in2_data[c10_i1] = (c10_b_in2_data[c10_aux_0_0] &&
      c10_in3_data[c10_aux_1_0]);
    c10_aux_1_0 += c10_stride_1_0;
    c10_aux_0_0 += c10_stride_0_0;
  }

  c10_in1_size[0] = c10_b_in2_size[0];
  c10_b_loop_ub = c10_b_in2_size[0] - 1;
  for (c10_i2 = 0; c10_i2 <= c10_b_loop_ub; c10_i2++) {
    c10_b_in1_data[c10_i2] = chartInstance->c10_in2_data[c10_i2];
  }
}

static void c10_b_and(SFc10_Rpi_camInstanceStruct *chartInstance, boolean_T
                      c10_b_in1_data[], int32_T c10_in1_size[1], boolean_T
                      c10_b_in2_data[], int32_T c10_in2_size[1])
{
  int32_T c10_b_in1_size[1];
  int32_T c10_aux_0_0;
  int32_T c10_aux_1_0;
  int32_T c10_b_loop_ub;
  int32_T c10_i;
  int32_T c10_i1;
  int32_T c10_i2;
  int32_T c10_loop_ub;
  int32_T c10_stride_0_0;
  int32_T c10_stride_1_0;
  if (c10_in2_size[0] == 1) {
    c10_b_in1_size[0] = c10_in1_size[0];
  } else {
    c10_b_in1_size[0] = c10_in2_size[0];
  }

  c10_stride_0_0 = static_cast<int32_T>(c10_in1_size[0] != 1);
  c10_stride_1_0 = static_cast<int32_T>(c10_in2_size[0] != 1);
  c10_aux_0_0 = 0;
  c10_aux_1_0 = 0;
  if (c10_in2_size[0] == 1) {
    c10_i = c10_in1_size[0];
  } else {
    c10_i = c10_in2_size[0];
  }

  c10_loop_ub = c10_i - 1;
  for (c10_i1 = 0; c10_i1 <= c10_loop_ub; c10_i1++) {
    chartInstance->c10_in1_data[c10_i1] = (c10_b_in1_data[c10_aux_0_0] &&
      c10_b_in2_data[c10_aux_1_0]);
    c10_aux_1_0 += c10_stride_1_0;
    c10_aux_0_0 += c10_stride_0_0;
  }

  c10_in1_size[0] = c10_b_in1_size[0];
  c10_b_loop_ub = c10_b_in1_size[0] - 1;
  for (c10_i2 = 0; c10_i2 <= c10_b_loop_ub; c10_i2++) {
    c10_b_in1_data[c10_i2] = chartInstance->c10_in1_data[c10_i2];
  }
}

static void init_dsm_address_info(SFc10_Rpi_camInstanceStruct *chartInstance)
{
}

static void init_simulink_io_address(SFc10_Rpi_camInstanceStruct *chartInstance)
{
  chartInstance->c10_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
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
void sf_c10_Rpi_cam_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4115405528U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3581160057U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(417442325U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1286348557U);
}

mxArray *sf_c10_Rpi_cam_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "coder.internal.BoundedEmxArrayExternalDependency"));
  return(mxcell3p);
}

mxArray *sf_c10_Rpi_cam_jit_fallback_info(void)
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

mxArray *sf_c10_Rpi_cam_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_Rpi_cam(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9eg7o+lmw6GdF0i8A5acWFeUXQcMHFk7ku0PBgT"
    "L9EPs9CPhDFM0fIH5mcXxicklmWWp8sqFBfFBBZnxyYi6SvwB1RBl5"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_Rpi_cam_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sNExqAuYi5CVDBi103vU3CC";
}

static void sf_opaque_initialize_c10_Rpi_cam(void *chartInstanceVar)
{
  initialize_params_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*) chartInstanceVar);
  initialize_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_Rpi_cam(void *chartInstanceVar)
{
  enable_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_Rpi_cam(void *chartInstanceVar)
{
  disable_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_Rpi_cam(void *chartInstanceVar)
{
  sf_gateway_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c10_Rpi_cam(SimStruct* S)
{
  return get_sim_state_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c10_Rpi_cam(SimStruct* S, const mxArray *st)
{
  set_sim_state_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c10_Rpi_cam(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_Rpi_camInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Rpi_cam_optimization_info();
    }

    mdl_cleanup_runtime_resources_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*)
      chartInstanceVar);
    ((SFc10_Rpi_camInstanceStruct*) chartInstanceVar)->
      ~SFc10_Rpi_camInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c10_Rpi_cam(void *chartInstanceVar)
{
  mdl_start_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc10_Rpi_camInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c10_Rpi_cam(void *chartInstanceVar)
{
  mdl_terminate_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_Rpi_cam(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_Rpi_cam((SFc10_Rpi_camInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc10_Rpi_cam((SFc10_Rpi_camInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c10_Rpi_cam_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWM1u20YQXgmOUaetkUuQHgrE6KmXFg6MAjkEjW2KSgXYsRFKLtqLsSZH4sLLJb0/stQX6bH",
    "XPkofoei9BXrrrTl2lqIUlVblXSlIkxCgqCX57cx8O39L0ugcEzy28dz5hJBNvH6AZ5NMjjvVuD",
    "F3Tu5vkCfV+Je7hMR5AgMQken32Yj4HcJkp1TSTBH/Q9AMXoDKudEsFx3Rz92xTPRBgohxgiKX2",
    "kuuYpnhTFy2jYitZPVtyuI0SnPDk0OckCYngo//S25h9ClKbDEJsW4DJDqVuRmkbU4Hy1mQ+jpI",
    "Ib5UJvPmSoGOTGFNVceGa1ZwCEcQd4TSFFlQt9gbaaoh0CM/kq29Kpqi86zgjAp3rlOqIijQOzT",
    "0igR/T4xG9hzlorwLJqjOJaM8zHiQUumKPeWo5zG6NffmWWe6BRdmMGBiYNmVJgOB9qOfOHDVD/",
    "IhSDqAE+EnN7bWhaNygWd+6YjVLIMzKg9i9AMFiV8MogOriOLSQhen8cKCoBccOqor2RDXyDdvd",
    "GworZQ3TDbxJLUStpQbDnFV1Ypy27EIKOfKD9vNiyMYAi/lt6imK2An8j3ASrGkm6N32Mj1jH4j",
    "2JWBChvkImHuXjmsocoi8RwTvgOcZTYMIEGaZ6rPJrotjozSeRZg6LeOjhzl3cR2hAbZpzE452t",
    "JmQJUuPQrT7kJUzaQEI0s6dJK5xkmMbgSlKi+Ea3rXF4ix76F4RVXNhL80JAMoAUayiQXonefUW",
    "4cdc4UZmXrHj2FWdZPLmJt/KwEjmmcQmJrIONwjHkWJ3BdYmXL5wFaO2R63AIVS1a4RpLBhI7Fz",
    "7LUHRfQE5civxZtmWdR1cUs8SsAzBpUCixlh1hK5biNyrtpLeGqW2Z334bB8kw1pxfWN56BwGpo",
    "bbXVm8YYVaHAdhMVWgcbsR+wHRGKKY0t4DgsYyAp++B98qoP3ljQB3841wffq8bxo93zFwU7j+k",
    "kzu08u3PzfOTQT7vgyA0cmeGm18/n8I0FcsnctS5vq7lczyb+a1S4eZ4+rsnZqOE2K67Is5/+0H",
    "9v/Pj0s60nvyW//7mO/J+bfvuV7Wr86bRXmmXm4Y3kZd/95hY/eFDzAztWz8PR1YH5jn0VnLUO2",
    "aPdvWFvLwjK+V42luvbrOk7vb9j+zMM3DIPyLiTVPseO6Zm0o/b+R/P6bt5Cx9bc/5EyF9P18N/",
    "uV/HL+LrTo0vOwYpc1nz39X12NlfD++27vdrdtwv+/ZzarMznP87E2y/hjjzxb0r8t53PV+nfS7",
    "1403jyBvGrWufb11819/fXZLHSO39e2+xHWRJHvXpj942u34lfv3Lw2r89WxPHqSMJwt2BdVjbN",
    "z7i56+J/790pO/ab8WWv6qD6Hf7x0Iyse4DZhss6rbp9J+g5s9kkDV4r3W/1FPFvVJrv1Wr9v+4",
    "vEadekf19UAcg==",
    ""
  };

  static char newstr [1441] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c10_Rpi_cam(SimStruct *S)
{
  const char* newstr = sf_c10_Rpi_cam_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3869198080U));
  ssSetChecksum1(S,(2533685108U));
  ssSetChecksum2(S,(1007231551U));
  ssSetChecksum3(S,(3924124890U));
}

static void mdlRTW_c10_Rpi_cam(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c10_Rpi_cam(SimStruct *S)
{
  SFc10_Rpi_camInstanceStruct *chartInstance;
  chartInstance = (SFc10_Rpi_camInstanceStruct *)utMalloc(sizeof
    (SFc10_Rpi_camInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc10_Rpi_camInstanceStruct));
  chartInstance = new (chartInstance) SFc10_Rpi_camInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c10_Rpi_cam;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c10_Rpi_cam;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c10_Rpi_cam;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c10_Rpi_cam;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c10_Rpi_cam;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_Rpi_cam;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_Rpi_cam;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c10_Rpi_cam;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c10_Rpi_cam;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c10_Rpi_cam;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_Rpi_cam;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c10_Rpi_cam;
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

  mdl_setup_runtime_resources_c10_Rpi_cam(chartInstance);
}

void c10_Rpi_cam_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c10_Rpi_cam(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_Rpi_cam(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_Rpi_cam(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_Rpi_cam_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
