/* Include files */

#include "LKAS_sfun.h"
#include "c4_LKAS.h"
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
const int32_T CALL_EVENT = -1;

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c4_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI = { 239,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_c_emlrtMCI = { 242,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_d_emlrtMCI = { 406,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_e_emlrtMCI = { 417,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_f_emlrtMCI = { 444,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_g_emlrtMCI = { 78,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtMCInfo c4_h_emlrtMCI = { 398,/* lineNo */
  5,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtMCInfo c4_i_emlrtMCI = { 291,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtMCInfo c4_j_emlrtMCI = { 419,/* lineNo */
  15,                                  /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtMCInfo c4_k_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c4_m_emlrtMCI = { 239,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtMCInfo c4_o_emlrtMCI = { 18,/* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/mean.m"/* pName */
};

static emlrtMCInfo c4_p_emlrtMCI = { 26,/* lineNo */
  23,                                  /* colNo */
  "polyfit",                           /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pName */
};

static emlrtMCInfo c4_q_emlrtMCI = { 45,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtMCInfo c4_r_emlrtMCI = { 48,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtMCInfo c4_s_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtMCInfo c4_t_emlrtMCI = { 18,/* lineNo */
  27,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 150,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 151,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 162,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 166,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 173,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 179,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 187,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 442,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 528,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 543,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 23,/* lineNo */
  "union",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/union.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 94,/* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 238,/* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 241,/* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 74,/* lineNo */
  "issorted",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/issorted.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 95,/* lineNo */
  "issorted",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/issorted.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 112,/* lineNo */
  "issorted",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/issorted.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 556,/* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 82,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 140,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 148,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI = { 171,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_bb_emlrtRSI = { 176,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_cb_emlrtRSI = { 261,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_db_emlrtRSI = { 295,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_eb_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c4_fb_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_gb_emlrtRSI = { 138,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_hb_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_ib_emlrtRSI = { 254,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_jb_emlrtRSI = { 255,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_kb_emlrtRSI = { 49,/* lineNo */
  "mean",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/mean.m"/* pathName */
};

static emlrtRSInfo c4_mb_emlrtRSI = { 86,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c4_ob_emlrtRSI = { 107,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pathName */
};

static emlrtRSInfo c4_pb_emlrtRSI = { 22,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_qb_emlrtRSI = { 53,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_rb_emlrtRSI = { 57,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_sb_emlrtRSI = { 42,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_tb_emlrtRSI = { 183,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_ub_emlrtRSI = { 189,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_vb_emlrtRSI = { 178,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_wb_emlrtRSI = { 210,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_xb_emlrtRSI = { 32,/* lineNo */
  "polyfit",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pathName */
};

static emlrtRSInfo c4_yb_emlrtRSI = { 36,/* lineNo */
  "polyfit",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pathName */
};

static emlrtRSInfo c4_ac_emlrtRSI = { 47,/* lineNo */
  "polyfit",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pathName */
};

static emlrtRSInfo c4_bc_emlrtRSI = { 40,/* lineNo */
  "polyfit",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pathName */
};

static emlrtRSInfo c4_cc_emlrtRSI = { 61,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_dc_emlrtRSI = { 80,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_ec_emlrtRSI = { 85,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_fc_emlrtRSI = { 67,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_gc_emlrtRSI = { 63,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_hc_emlrtRSI = { 138,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_ic_emlrtRSI = { 143,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_jc_emlrtRSI = { 148,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_kc_emlrtRSI = { 151,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_mc_emlrtRSI = { 119,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_oc_emlrtRSI = { 174,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_pc_emlrtRSI = { 186,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_qc_emlrtRSI = { 189,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_rc_emlrtRSI = { 198,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_sc_emlrtRSI = { 202,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_tc_emlrtRSI = { 214,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_uc_emlrtRSI = { 229,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_vc_emlrtRSI = { 233,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_wc_emlrtRSI = { 255,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_xc_emlrtRSI = { 248,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_yc_emlrtRSI = { 23,/* lineNo */
  "xnrm2",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xnrm2.m"/* pathName */
};

static emlrtRSInfo c4_ad_emlrtRSI = { 38,/* lineNo */
  "xnrm2",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xnrm2.m"/* pathName */
};

static emlrtRSInfo c4_bd_emlrtRSI = { 23,/* lineNo */
  "ixamax",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/ixamax.m"/* pathName */
};

static emlrtRSInfo c4_cd_emlrtRSI = { 24,/* lineNo */
  "ixamax",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/ixamax.m"/* pathName */
};

static emlrtRSInfo c4_dd_emlrtRSI = { 30,/* lineNo */
  "xswap",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xswap.m"/* pathName */
};

static emlrtRSInfo c4_ed_emlrtRSI = { 20,/* lineNo */
  "xswap",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xswap.m"/* pathName */
};

static emlrtRSInfo c4_fd_emlrtRSI = { 20,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_gd_emlrtRSI = { 81,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_hd_emlrtRSI = { 41,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_id_emlrtRSI = { 53,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_jd_emlrtRSI = { 68,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_kd_emlrtRSI = { 71,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_md_emlrtRSI = { 37,/* lineNo */
  "xscal",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"/* pathName */
};

static emlrtRSInfo c4_od_emlrtRSI = { 31,/* lineNo */
  "xscal",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"/* pathName */
};

static emlrtRSInfo c4_pd_emlrtRSI = { 18,/* lineNo */
  "xscal",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xscal.m"/* pathName */
};

static emlrtRSInfo c4_qd_emlrtRSI = { 49,/* lineNo */
  "xscal",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"/* pathName */
};

static emlrtRSInfo c4_rd_emlrtRSI = { 50,/* lineNo */
  "xzlarf",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"/* pathName */
};

static emlrtRSInfo c4_sd_emlrtRSI = { 68,/* lineNo */
  "xzlarf",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"/* pathName */
};

static emlrtRSInfo c4_td_emlrtRSI = { 75,/* lineNo */
  "xzlarf",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"/* pathName */
};

static emlrtRSInfo c4_ud_emlrtRSI = { 103,/* lineNo */
  "xzlarf",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"/* pathName */
};

static emlrtRSInfo c4_vd_emlrtRSI = { 76,/* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_wd_emlrtRSI = { 64,/* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_xd_emlrtRSI = { 37,/* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_yd_emlrtRSI = { 71,/* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_ae_emlrtRSI = { 74,/* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_be_emlrtRSI = { 91,/* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_ce_emlrtRSI = { 45,/* lineNo */
  "xgerc",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xgerc.m"/* pathName */
};

static emlrtRSInfo c4_de_emlrtRSI = { 53,/* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xger.m"/* pathName */
};

static emlrtRSInfo c4_ee_emlrtRSI = { 45,/* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xger.m"/* pathName */
};

static emlrtRSInfo c4_fe_emlrtRSI = { 15,/* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xger.m"/* pathName */
};

static emlrtRSInfo c4_ge_emlrtRSI = { 41,/* lineNo */
  "xgerx",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xgerx.m"/* pathName */
};

static emlrtRSInfo c4_he_emlrtRSI = { 54,/* lineNo */
  "xgerx",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xgerx.m"/* pathName */
};

static emlrtRSInfo c4_ie_emlrtRSI = { 67,/* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xger.m"/* pathName */
};

static emlrtRSInfo c4_je_emlrtRSI = { 189,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_ke_emlrtRSI = { 119,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_me_emlrtRSI = { 128,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_oe_emlrtRSI = { 135,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_pe_emlrtRSI = { 138,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_qe_emlrtRSI = { 34,/* lineNo */
  "xunormqr",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo c4_re_emlrtRSI = { 31,/* lineNo */
  "xunormqr",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo c4_se_emlrtRSI = { 102,/* lineNo */
  "xunormqr",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo c4_te_emlrtRSI = { 18,/* lineNo */
  "xzunormqr",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzunormqr.m"/* pathName */
};

static emlrtRSInfo c4_ue_emlrtRSI = { 23,/* lineNo */
  "xzunormqr",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzunormqr.m"/* pathName */
};

static emlrtRSInfo c4_ve_emlrtRSI = { 29,/* lineNo */
  "xzunormqr",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzunormqr.m"/* pathName */
};

static emlrtRSInfo c4_we_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/shared/coder/coder/lib/+coder/+internal/warning.m"/* pathName */
};

static emlrtRSInfo c4_xe_emlrtRSI = { 13,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#LKAS:20"                           /* pathName */
};

static emlrtRSInfo c4_ye_emlrtRSI = { 38,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#LKAS:20"                           /* pathName */
};

static emlrtRSInfo c4_af_emlrtRSI = { 96,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#LKAS:20"                           /* pathName */
};

static emlrtRSInfo c4_bf_emlrtRSI = { 101,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#LKAS:20"                           /* pathName */
};

static emlrtRSInfo c4_cf_emlrtRSI = { 113,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#LKAS:20"                           /* pathName */
};

static emlrtRSInfo c4_df_emlrtRSI = { 114,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#LKAS:20"                           /* pathName */
};

static emlrtRTEInfo c4_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_b_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_c_emlrtRTEI = { 71,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_d_emlrtRTEI = { 71,/* lineNo */
  65,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_e_emlrtRTEI = { 71,/* lineNo */
  91,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_f_emlrtRTEI = { 71,/* lineNo */
  122,                                 /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_g_emlrtRTEI = { 71,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_h_emlrtRTEI = { 72,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_i_emlrtRTEI = { 72,/* lineNo */
  65,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_j_emlrtRTEI = { 72,/* lineNo */
  91,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_k_emlrtRTEI = { 72,/* lineNo */
  122,                                 /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_m_emlrtRTEI = { 72,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_o_emlrtRTEI = { 74,/* lineNo */
  40,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_p_emlrtRTEI = { 74,/* lineNo */
  66,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_q_emlrtRTEI = { 74,/* lineNo */
  92,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_r_emlrtRTEI = { 74,/* lineNo */
  124,                                 /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_s_emlrtRTEI = { 74,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_t_emlrtRTEI = { 75,/* lineNo */
  40,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_u_emlrtRTEI = { 75,/* lineNo */
  66,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_v_emlrtRTEI = { 75,/* lineNo */
  92,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_w_emlrtRTEI = { 75,/* lineNo */
  124,                                 /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_x_emlrtRTEI = { 75,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_y_emlrtRTEI = { 108,/* lineNo */
  1,                                   /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_ab_emlrtRTEI = { 109,/* lineNo */
  1,                                   /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_bb_emlrtRTEI = { 113,/* lineNo */
  18,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_cb_emlrtRTEI = { 113,/* lineNo */
  46,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_db_emlrtRTEI = { 114,/* lineNo */
  19,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_eb_emlrtRTEI = { 114,/* lineNo */
  48,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_fb_emlrtRTEI = { 525,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_gb_emlrtRTEI = { 151,/* lineNo */
  11,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_hb_emlrtRTEI = { 151,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_ib_emlrtRTEI = { 172,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c4_jb_emlrtRTEI = { 556,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_kb_emlrtRTEI = { 175,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_mb_emlrtRTEI = { 171,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_ob_emlrtRTEI = { 173,/* lineNo */
  11,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_pb_emlrtRTEI = { 173,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_qb_emlrtRTEI = { 179,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_rb_emlrtRTEI = { 649,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_sb_emlrtRTEI = { 650,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_tb_emlrtRTEI = { 654,/* lineNo */
  3,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_ub_emlrtRTEI = { 661,/* lineNo */
  3,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_vb_emlrtRTEI = { 416,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_wb_emlrtRTEI = { 417,/* lineNo */
  23,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_xb_emlrtRTEI = { 418,/* lineNo */
  27,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_yb_emlrtRTEI = { 403,/* lineNo */
  32,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_ac_emlrtRTEI = { 503,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_bc_emlrtRTEI = { 504,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_cc_emlrtRTEI = { 505,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_dc_emlrtRTEI = { 220,/* lineNo */
  24,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_ec_emlrtRTEI = { 221,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_fc_emlrtRTEI = { 222,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_gc_emlrtRTEI = { 161,/* lineNo */
  22,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_hc_emlrtRTEI = { 412,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_ic_emlrtRTEI = { 423,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_jc_emlrtRTEI = { 448,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_kc_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_mc_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_oc_emlrtRTEI = { 199,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_pc_emlrtRTEI = { 253,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_qc_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_rc_emlrtRTEI = { 254,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_sc_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_tc_emlrtRTEI = { 17,/* lineNo */
  20,                                  /* colNo */
  "vander",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/vander.m"/* pName */
};

static emlrtRTEInfo c4_uc_emlrtRTEI = { 36,/* lineNo */
  40,                                  /* colNo */
  "polyfit",                           /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pName */
};

static emlrtRTEInfo c4_vc_emlrtRTEI = { 92,/* lineNo */
  22,                                  /* colNo */
  "xgeqp3",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pName */
};

static emlrtRTEInfo c4_wc_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "xgeqp3",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pName */
};

static emlrtRTEInfo c4_xc_emlrtRTEI = { 119,/* lineNo */
  5,                                   /* colNo */
  "qrsolve",                           /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pName */
};

static emlrtBCInfo c4_emlrtBCI = { 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  80,                                  /* lineNo */
  30,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_b_emlrtBCI = { 0,/* iFirst */
  MAX_int32_T,                         /* iLast */
  85,                                  /* lineNo */
  31,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_c_emlrtBCI = { 0,/* iFirst */
  MAX_int32_T,                         /* iLast */
  95,                                  /* lineNo */
  12,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_d_emlrtBCI = { 0,/* iFirst */
  MAX_int32_T,                         /* iLast */
  100,                                 /* lineNo */
  12,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_emlrtDCI = { 81, /* lineNo */
  29,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_e_emlrtBCI = { 1,/* iFirst */
  100000,                              /* iLast */
  81,                                  /* lineNo */
  29,                                  /* colNo */
  "left_lane_index",                   /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_b_emlrtDCI = { 108,/* lineNo */
  44,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_f_emlrtBCI = { 1,/* iFirst */
  100000,                              /* iLast */
  108,                                 /* lineNo */
  44,                                  /* colNo */
  "left_lane_index",                   /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_c_emlrtDCI = { 86,/* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_g_emlrtBCI = { 1,/* iFirst */
  100000,                              /* iLast */
  86,                                  /* lineNo */
  30,                                  /* colNo */
  "right_lane_index",                  /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_d_emlrtDCI = { 109,/* lineNo */
  46,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_h_emlrtBCI = { 1,/* iFirst */
  100000,                              /* iLast */
  109,                                 /* lineNo */
  46,                                  /* colNo */
  "right_lane_index",                  /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_e_emlrtDCI = { 66,/* lineNo */
  26,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_i_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  66,                                  /* lineNo */
  26,                                  /* colNo */
  "rectangle_points",                  /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_f_emlrtDCI = { 67,/* lineNo */
  26,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_j_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  67,                                  /* lineNo */
  26,                                  /* colNo */
  "rectangle_points",                  /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  3                                    /* checkKind */
};

static emlrtECInfo c4_emlrtECI = { -1, /* nDims */
  71,                                  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtECInfo c4_b_emlrtECI = { 1,/* nDims */
  71,                                  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtECInfo c4_c_emlrtECI = { -1,/* nDims */
  72,                                  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtECInfo c4_d_emlrtECI = { 1,/* nDims */
  72,                                  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtECInfo c4_e_emlrtECI = { -1,/* nDims */
  74,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtECInfo c4_f_emlrtECI = { 1,/* nDims */
  74,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtECInfo c4_g_emlrtECI = { -1,/* nDims */
  75,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtECInfo c4_h_emlrtECI = { 1,/* nDims */
  75,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_yc_emlrtRTEI = { 80,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtRTEInfo c4_ad_emlrtRTEI = { 85,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20"                           /* pName */
};

static emlrtBCInfo c4_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  18,                                  /* colNo */
  "locs",                              /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  25,                                  /* colNo */
  "right_base",                        /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_g_emlrtDCI = { 17,/* lineNo */
  25,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_o_emlrtBCI = { 0,/* iFirst */
  MAX_int32_T,                         /* iLast */
  17,                                  /* lineNo */
  25,                                  /* colNo */
  "right_base(end)",                   /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  19,                                  /* colNo */
  "locs",                              /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_h_emlrtDCI = { 16,/* lineNo */
  19,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  38,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_i_emlrtDCI = { 71,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  38,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_j_emlrtDCI = { 72,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  39,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_k_emlrtDCI = { 74,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  39,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_m_emlrtDCI = { 75,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  38,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_o_emlrtDCI = { 81,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  60,                                  /* colNo */
  "good_lefty_indexs",                 /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_p_emlrtDCI = { 81,/* lineNo */
  60,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  39,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_q_emlrtDCI = { 86,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  62,                                  /* colNo */
  "good_righty_indexs",                /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_r_emlrtDCI = { 86,/* lineNo */
  62,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#LKAS:20",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  179,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_s_emlrtDCI = { 179,/* lineNo */
  17,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  179,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  539,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_t_emlrtDCI = { 539,/* lineNo */
  13,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  539,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  529,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_u_emlrtDCI = { 529,/* lineNo */
  17,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_eb_emlrtBCI = { 1,/* iFirst */
  1200,                                /* iLast */
  530,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_v_emlrtDCI = { 530,/* lineNo */
  12,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_fb_emlrtBCI = { 1,/* iFirst */
  1200,                                /* iLast */
  532,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_w_emlrtDCI = { 532,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_gb_emlrtBCI = { 1,/* iFirst */
  1200,                                /* iLast */
  532,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_x_emlrtDCI = { 532,/* lineNo */
  31,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  535,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_y_emlrtDCI = { 535,/* lineNo */
  17,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c4_ab_emlrtDCI = { 175,/* lineNo */
  32,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c4_bb_emlrtDCI = { 175,/* lineNo */
  32,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  173,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  179,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_cb_emlrtDCI = { 179,/* lineNo */
  11,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_kb_emlrtBCI = { 1,/* iFirst */
  1200,                                /* iLast */
  649,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_db_emlrtDCI = { 649,/* lineNo */
  9,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_mb_emlrtBCI = { 1,/* iFirst */
  1200,                                /* iLast */
  650,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_eb_emlrtDCI = { 650,/* lineNo */
  9,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c4_fb_emlrtDCI = { 172,/* lineNo */
  28,                                  /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c4_ob_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  503,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_gb_emlrtDCI = { 503,/* lineNo */
  13,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  503,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  504,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_hb_emlrtDCI = { 504,/* lineNo */
  15,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_rb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  504,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  505,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_ib_emlrtDCI = { 505,/* lineNo */
  23,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_tb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  505,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ub_emlrtBCI = { 1,/* iFirst */
  1200,                                /* iLast */
  443,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_jb_emlrtDCI = { 443,/* lineNo */
  12,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_vb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  498,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_kb_emlrtDCI = { 498,/* lineNo */
  58,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_wb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  500,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_mb_emlrtDCI = { 500,/* lineNo */
  14,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_xb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  452,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_ob_emlrtDCI = { 452,/* lineNo */
  14,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_yb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  466,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_pb_emlrtDCI = { 466,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_ac_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_qb_emlrtDCI = { 488,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_bc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  474,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_rb_emlrtDCI = { 474,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_cc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  479,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_sb_emlrtDCI = { 479,/* lineNo */
  25,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c4_tb_emlrtDCI = { 220,/* lineNo */
  41,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c4_ub_emlrtDCI = { 221,/* lineNo */
  31,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c4_vb_emlrtDCI = { 222,/* lineNo */
  31,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo c4_bd_emlrtRTEI = { 31,/* lineNo */
  13,                                  /* colNo */
  "vander",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/vander.m"/* pName */
};

static emlrtRTEInfo c4_cd_emlrtRTEI = { 27,/* lineNo */
  9,                                   /* colNo */
  "vander",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/vander.m"/* pName */
};

static emlrtRTEInfo c4_dd_emlrtRTEI = { 21,/* lineNo */
  9,                                   /* colNo */
  "vander",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/vander.m"/* pName */
};

static emlrtDCInfo c4_wb_emlrtDCI = { 17,/* lineNo */
  26,                                  /* colNo */
  "vander",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/vander.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c4_xb_emlrtDCI = { 92,/* lineNo */
  28,                                  /* colNo */
  "xgeqp3",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m",/* pName */
  4                                    /* checkKind */
};

static char_T c4_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
  't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F', 'a',
  'i', 'l', 'e', 'd' };

static char_T c4_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
  'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V', 'e',
  'c', 't', 'o', 'r' };

static char_T c4_cv2[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
  'e', 'm' };

static char_T c4_cv3[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E', 'r',
  'r', 'o', 'r', 'I', 'n', 'f', 'o' };

/* Function Declarations */
static void initialize_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void initialize_params_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void mdl_start_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void mdl_terminate_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c4_LKAS(SFc4_LKASInstanceStruct
  *chartInstance);
static void mdl_cleanup_runtime_resources_c4_LKAS(SFc4_LKASInstanceStruct
  *chartInstance);
static void enable_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void disable_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void sf_gateway_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void ext_mode_exec_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void c4_update_jit_animation_c4_LKAS(SFc4_LKASInstanceStruct
  *chartInstance);
static void c4_do_animation_call_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_LKAS(SFc4_LKASInstanceStruct
  *chartInstance);
static void set_sim_state_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance, const
  mxArray *c4_st);
static void initSimStructsc4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void initSubchartIOPointersc4_LKAS(SFc4_LKASInstanceStruct *chartInstance);
static void c4_findpeaks(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_Yin[1200], coder::array<real_T, 2U> &c4_Ypk,
  coder::array<real_T, 2U> &c4_Xpk);
static void c4_getAllPeaksCodegen(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_y[1200], coder::array<int32_T, 1U> &c4_iPk, coder::
  array<int32_T, 1U> &c4_iInf, coder::array<int32_T, 1U> &c4_iInflect);
static void c4_check_forloop_overflow_error(SFc4_LKASInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_overflow);
static void c4_do_vectors(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<int32_T, 1U> &c4_a, coder::array<int32_T, 1U>
  &c4_b, coder::array<int32_T, 1U> &c4_c, coder::array<int32_T, 1U> &c4_ia,
  coder::array<int32_T, 1U> &c4_b_ib);
static boolean_T c4_issorted(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<int32_T, 1U> &c4_b_x);
static void c4_indexShapeCheck(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_matrixSize);
static void c4_b_indexShapeCheck(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T c4_indexSize[2]);
static void c4_eml_find(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack
  *c4_sp, boolean_T c4_b_x[900000], coder::array<int32_T, 1U> &c4_i, coder::
  array<int32_T, 1U> &c4_j);
static real_T c4_mean(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack
                      *c4_sp, coder::array<real_T, 1U> &c4_b_x);
static real_T c4_sumColumnB(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<real_T, 1U> &c4_b_x, int32_T c4_vlen);
static real_T c4_sumColumnB4(SFc4_LKASInstanceStruct *chartInstance, coder::
  array<real_T, 1U> &c4_b_x, int32_T c4_col, int32_T c4_vstart);
static real_T c4_b_sumColumnB(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<real_T, 1U> &c4_b_x, int32_T c4_vlen, int32_T
  c4_vstart);
static void c4_polyfit(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack *
  c4_sp, coder::array<real_T, 1U> &c4_b_x, coder::array<real_T, 1U> &c4_y,
  real_T c4_p[3]);
static void c4_LSQFromQR(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<real_T, 2U> &c4_mb_A, coder::array<real_T, 1U>
  &c4_tau, int32_T c4_jpvt[3], coder::array<real_T, 1U> &c4_r_B, int32_T
  c4_rankA, real_T c4_u_Y[3]);
static void c4_warning(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack *
  c4_sp);
static void c4_b_warning(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp);
static real_T c4_emlrt_marshallIn(SFc4_LKASInstanceStruct *chartInstance, const
  mxArray *c4_nullptr, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_LKASInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint8_T c4_c_emlrt_marshallIn(SFc4_LKASInstanceStruct *chartInstance,
  const mxArray *c4_nullptr, const char_T *c4_identifier);
static uint8_T c4_d_emlrt_marshallIn(SFc4_LKASInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_slStringInitializeDynamicBuffers(SFc4_LKASInstanceStruct
  *chartInstance);
static void c4_chart_data_browse_helper(SFc4_LKASInstanceStruct *chartInstance,
  int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T *c4_isValueTooBig);
static const mxArray *c4_feval(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_b_feval(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack *
  c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static const mxArray *c4_c_feval(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_d_feval(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack *
  c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_and(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack
                   *c4_sp, coder::array<boolean_T, 1U> &c4_in1, coder::array<
                   boolean_T, 1U> &c4_in2, coder::array<boolean_T, 1U> &c4_in3);
static void c4_b_and(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack
                     *c4_sp, coder::array<boolean_T, 1U> &c4_in1, coder::array<
                     boolean_T, 1U> &c4_in2);
static int32_T c4_div_nzp_s32(SFc4_LKASInstanceStruct *chartInstance, int32_T
  c4_numerator, int32_T c4_denominator, int32_T c4_EMLOvCount_src_loc, uint32_T
  c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc);
static void init_dsm_address_info(SFc4_LKASInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_LKASInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c4_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "signal_toolbox", 2);
  sf_is_first_init_cond(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_doneDoubleBufferReInit = false;
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
}

static void mdl_start_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
}

static void mdl_setup_runtime_resources_c4_LKAS(SFc4_LKASInstanceStruct
  *chartInstance)
{
  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, chartInstance->c4_JITStateAnimation,
                        chartInstance->c4_JITTransitionAnimation);
  setDataBrowseFcn(chartInstance->S, (void *)&c4_chart_data_browse_helper);
  chartInstance->c4_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c4_RuntimeVar,
    &chartInstance->c4_IsDebuggerActive,
    &chartInstance->c4_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c4_mlFcnLineNumber, &chartInstance->c4_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    10U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 2U, 0U,
                  0U, 0U, 3U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 4896);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 3999, 4036, -1,
                    4114, false);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 4132, 4170, -1,
                    4250, false);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1702, 1722,
                     4265);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 3356, 3401,
                     3536);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 3546, 3593,
                     3733);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 4002,
    4035, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 4135,
    4169, -1, 4U);
}

static void mdl_cleanup_runtime_resources_c4_LKAS(SFc4_LKASInstanceStruct
  *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c4_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void enable_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
  coder::array<real_T, 2U> c4_actual_left_lane_index;
  coder::array<real_T, 2U> c4_actual_right_lane_index;
  coder::array<real_T, 2U> c4_locs;
  coder::array<real_T, 2U> c4_right_base;
  coder::array<real_T, 1U> c4_b_actual_left_lane_index;
  coder::array<real_T, 1U> c4_b_actual_right_lane_index;
  coder::array<real_T, 1U> c4_c_actual_left_lane_index;
  coder::array<real_T, 1U> c4_c_actual_right_lane_index;
  coder::array<real_T, 1U> c4_good_leftx_indexs;
  coder::array<real_T, 1U> c4_good_lefty_indexs;
  coder::array<real_T, 1U> c4_good_rightx_indexs;
  coder::array<real_T, 1U> c4_good_righty_indexs;
  coder::array<real_T, 1U> c4_nonzerox;
  coder::array<real_T, 1U> c4_nonzeroy;
  coder::array<int32_T, 1U> c4_b_ii;
  coder::array<int32_T, 1U> c4_jj;
  coder::array<boolean_T, 1U> c4_r;
  coder::array<boolean_T, 1U> c4_r1;
  coder::array<boolean_T, 1U> c4_r2;
  coder::array<boolean_T, 1U> c4_r3;
  coder::array<boolean_T, 1U> c4_r4;
  coder::array<boolean_T, 1U> c4_r5;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c4_base[1200];
  real_T c4_xleft[751];
  real_T c4_xright[751];
  real_T c4_p_left[3];
  real_T c4_p_right[3];
  real_T c4_b_d1;
  real_T c4_b_error;
  real_T c4_b_j;
  real_T c4_b_p_left;
  real_T c4_b_p_right;
  real_T c4_b_right_base;
  real_T c4_c_k;
  real_T c4_count_left;
  real_T c4_count_right;
  real_T c4_d;
  real_T c4_d10;
  real_T c4_d11;
  real_T c4_d12;
  real_T c4_d13;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  real_T c4_d6;
  real_T c4_d7;
  real_T c4_d8;
  real_T c4_d9;
  real_T c4_e_k;
  real_T c4_g_i;
  real_T c4_leftx_current;
  real_T c4_rightx_current;
  real_T c4_win_xleft_high;
  real_T c4_win_xleft_low;
  real_T c4_win_xright_high;
  real_T c4_win_xright_low;
  real_T c4_win_y_high;
  real_T c4_win_y_low;
  int32_T c4_nz[1200];
  int32_T c4_a;
  int32_T c4_ab_loop_ub;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_end;
  int32_T c4_b_i;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_partialTrueCount;
  int32_T c4_b_trueCount;
  int32_T c4_bb_loop_ub;
  int32_T c4_c_end;
  int32_T c4_c_i;
  int32_T c4_c_j;
  int32_T c4_c_loop_ub;
  int32_T c4_c_partialTrueCount;
  int32_T c4_c_trueCount;
  int32_T c4_cb_loop_ub;
  int32_T c4_d_end;
  int32_T c4_d_i;
  int32_T c4_d_j;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_d_partialTrueCount;
  int32_T c4_d_trueCount;
  int32_T c4_db_loop_ub;
  int32_T c4_e_end;
  int32_T c4_e_i;
  int32_T c4_e_j;
  int32_T c4_e_loop_ub;
  int32_T c4_e_partialTrueCount;
  int32_T c4_e_trueCount;
  int32_T c4_eb_loop_ub;
  int32_T c4_end;
  int32_T c4_f_i;
  int32_T c4_f_loop_ub;
  int32_T c4_fb_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_gb_loop_ub;
  int32_T c4_h_i;
  int32_T c4_h_loop_ub;
  int32_T c4_hb_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i100;
  int32_T c4_i101;
  int32_T c4_i102;
  int32_T c4_i103;
  int32_T c4_i104;
  int32_T c4_i105;
  int32_T c4_i106;
  int32_T c4_i107;
  int32_T c4_i108;
  int32_T c4_i109;
  int32_T c4_i11;
  int32_T c4_i110;
  int32_T c4_i111;
  int32_T c4_i112;
  int32_T c4_i113;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i9;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  int32_T c4_i99;
  int32_T c4_i_loop_ub;
  int32_T c4_ib_loop_ub;
  int32_T c4_ix;
  int32_T c4_iy;
  int32_T c4_j;
  int32_T c4_j_i;
  int32_T c4_j_loop_ub;
  int32_T c4_jb_loop_ub;
  int32_T c4_k;
  int32_T c4_k_i;
  int32_T c4_k_loop_ub;
  int32_T c4_kb_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_i;
  int32_T c4_m_loop_ub;
  int32_T c4_mb_loop_ub;
  int32_T c4_o_i;
  int32_T c4_o_loop_ub;
  int32_T c4_ob_loop_ub;
  int32_T c4_p_i;
  int32_T c4_p_loop_ub;
  int32_T c4_partialTrueCount;
  int32_T c4_q_i;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  int32_T c4_s_i;
  int32_T c4_s_loop_ub;
  int32_T c4_t_loop_ub;
  int32_T c4_trueCount;
  int32_T c4_u_loop_ub;
  int32_T c4_v_loop_ub;
  int32_T c4_w_loop_ub;
  int32_T c4_x_loop_ub;
  int32_T c4_xoffset;
  int32_T c4_xpageoffset;
  int32_T c4_y_loop_ub;
  int32_T c4_ypageoffset;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b_b;
  boolean_T c4_b_b1;
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  for (c4_i = 0; c4_i < 900000; c4_i++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 0U, static_cast<real_T>((*
      chartInstance->c4_binary_image)[c4_i]));
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  chartInstance->c4_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  c4_i1 = 0;
  c4_i2 = 0;
  for (c4_i3 = 0; c4_i3 < 1200; c4_i3++) {
    for (c4_i4 = 0; c4_i4 < 376; c4_i4++) {
      chartInstance->c4_x[c4_i4 + c4_i1] = (*chartInstance->c4_binary_image)
        [(c4_i4 + c4_i2) + 374];
    }

    c4_i1 += 376;
    c4_i2 += 750;
  }

  for (c4_b_i = 0; c4_b_i < 1200; c4_b_i++) {
    c4_c_i = c4_b_i;
    c4_xpageoffset = c4_c_i * 376 + 1;
    c4_ypageoffset = c4_c_i + 1;
    c4_ix = c4_xpageoffset - 1;
    c4_iy = c4_ypageoffset - 1;
    c4_nz[c4_iy] = static_cast<int32_T>(chartInstance->c4_x[c4_ix]);
    for (c4_k = 0; c4_k < 375; c4_k++) {
      c4_xoffset = (c4_xpageoffset + c4_k) + 1;
      c4_ix = c4_xoffset - 1;
      c4_iy = c4_ypageoffset - 1;
      c4_a = c4_nz[c4_iy];
      c4_b = static_cast<int32_T>(chartInstance->c4_x[c4_ix]);
      c4_b_a = c4_a;
      c4_b_a += static_cast<int32_T>(c4_b != 0);
      c4_nz[c4_iy] = c4_b_a;
    }
  }

  for (c4_i5 = 0; c4_i5 < 1200; c4_i5++) {
    c4_base[c4_i5] = static_cast<real_T>(c4_nz[c4_i5]);
  }

  c4_b_st.site = &c4_xe_emlrtRSI;
  c4_findpeaks(chartInstance, &c4_b_st, c4_base, c4_right_base, c4_locs);
  c4_i6 = c4_locs.size(1);
  c4_i7 = 1;
  if ((c4_i7 < 1) || (c4_i7 > c4_i6)) {
    emlrtDynamicBoundsCheckR2012b(c4_i7, 1, c4_i6, &c4_k_emlrtBCI, &c4_st);
  }

  c4_end = c4_locs.size(1);
  c4_trueCount = 0;
  for (c4_d_i = 0; c4_d_i < c4_end; c4_d_i++) {
    if (c4_locs[c4_d_i] - c4_locs[0] > 200.0) {
      c4_trueCount++;
    }
  }

  c4_right_base.set_size(static_cast<emlrtRTEInfo *>(NULL), &c4_st, 1,
    c4_trueCount);
  c4_partialTrueCount = 0;
  for (c4_e_i = 0; c4_e_i < c4_end; c4_e_i++) {
    if (c4_locs[c4_e_i] - c4_locs[0] > 200.0) {
      c4_i10 = c4_locs.size(1) - 1;
      c4_d = static_cast<real_T>(c4_e_i);
      if (c4_d != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_d)))) {
        emlrtIntegerCheckR2012b(c4_d, &c4_h_emlrtDCI, &c4_st);
      }

      c4_i11 = static_cast<int32_T>(muDoubleScalarFloor(c4_d));
      if ((c4_i11 < 0) || (c4_i11 > c4_i10)) {
        emlrtDynamicBoundsCheckR2012b(c4_i11, 0, c4_i10, &c4_p_emlrtBCI, &c4_st);
      }

      c4_right_base[c4_partialTrueCount] = c4_locs[c4_i11];
      c4_partialTrueCount++;
    }
  }

  c4_i8 = c4_right_base.size(1);
  c4_i9 = c4_right_base.size(1);
  if (c4_i9 < 0) {
    emlrtDynamicBoundsCheckR2012b(c4_i9, 0, MAX_int32_T, &c4_o_emlrtBCI, &c4_st);
  }

  c4_b_d1 = static_cast<real_T>(c4_i9);
  if (c4_b_d1 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
        (c4_b_d1)))) {
    emlrtIntegerCheckR2012b(c4_b_d1, &c4_g_emlrtDCI, &c4_st);
  }

  c4_i12 = static_cast<int32_T>(c4_b_d1);
  if ((c4_i12 < 1) || (c4_i12 > c4_i8)) {
    emlrtDynamicBoundsCheckR2012b(c4_i12, 1, c4_i8, &c4_m_emlrtBCI, &c4_st);
  }

  c4_b_right_base = c4_right_base[c4_i12 - 1];
  c4_leftx_current = c4_locs[0];
  c4_rightx_current = c4_b_right_base;
  for (c4_i13 = 0; c4_i13 < 200000; c4_i13++) {
    chartInstance->c4_left_lane_index[c4_i13] = 0.0;
  }

  for (c4_i14 = 0; c4_i14 < 200000; c4_i14++) {
    chartInstance->c4_right_lane_index[c4_i14] = 0.0;
  }

  c4_b_st.site = &c4_ye_emlrtRSI;
  c4_c_st.site = &c4_fb_emlrtRSI;
  for (c4_i15 = 0; c4_i15 < 900000; c4_i15++) {
    chartInstance->c4_bv[c4_i15] = (*chartInstance->c4_binary_image)[c4_i15];
  }

  c4_eml_find(chartInstance, &c4_c_st, chartInstance->c4_bv, c4_b_ii, c4_jj);
  c4_nonzeroy.set_size(&c4_emlrtRTEI, &c4_b_st, c4_b_ii.size(0));
  c4_loop_ub = c4_b_ii.size(0) - 1;
  for (c4_i16 = 0; c4_i16 <= c4_loop_ub; c4_i16++) {
    c4_nonzeroy[c4_i16] = static_cast<real_T>(c4_b_ii[c4_i16]);
  }

  c4_nonzerox.set_size(&c4_b_emlrtRTEI, &c4_b_st, c4_jj.size(0));
  c4_b_loop_ub = c4_jj.size(0) - 1;
  for (c4_i17 = 0; c4_i17 <= c4_b_loop_ub; c4_i17++) {
    c4_nonzerox[c4_i17] = static_cast<real_T>(c4_jj[c4_i17]);
  }

  c4_count_left = 0.0;
  c4_count_right = 0.0;
  for (c4_f_i = 0; c4_f_i < 10; c4_f_i++) {
    c4_g_i = static_cast<real_T>(c4_f_i);
    covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 0, 1);
    c4_win_y_low = 750.0 - (c4_g_i + 1.0) * 75.0;
    c4_win_y_high = 750.0 - c4_g_i * 75.0;
    c4_win_xleft_low = c4_leftx_current - 80.0;
    c4_win_xleft_high = c4_leftx_current + 80.0;
    c4_win_xright_low = c4_rightx_current - 80.0;
    c4_win_xright_high = c4_rightx_current + 80.0;
    c4_d2 = c4_g_i + 1.0;
    if (c4_d2 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d2)))) {
      emlrtIntegerCheckR2012b(c4_d2, &c4_e_emlrtDCI, &c4_st);
    }

    c4_i22 = static_cast<int32_T>(c4_d2);
    if ((c4_i22 < 1) || (c4_i22 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c4_i22, 1, 20, &c4_i_emlrtBCI, &c4_st);
    }

    c4_d3 = 11.0 + c4_g_i;
    if (c4_d3 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d3)))) {
      emlrtIntegerCheckR2012b(c4_d3, &c4_f_emlrtDCI, &c4_st);
    }

    c4_i25 = static_cast<int32_T>(c4_d3);
    if ((c4_i25 < 1) || (c4_i25 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c4_i25, 1, 20, &c4_j_emlrtBCI, &c4_st);
    }

    c4_r.set_size(&c4_c_emlrtRTEI, &c4_st, c4_nonzeroy.size(0));
    c4_d_loop_ub = c4_nonzeroy.size(0) - 1;
    for (c4_i29 = 0; c4_i29 <= c4_d_loop_ub; c4_i29++) {
      c4_r[c4_i29] = (c4_nonzeroy[c4_i29] >= c4_win_y_low);
    }

    c4_r1.set_size(&c4_d_emlrtRTEI, &c4_st, c4_nonzeroy.size(0));
    c4_g_loop_ub = c4_nonzeroy.size(0) - 1;
    for (c4_i32 = 0; c4_i32 <= c4_g_loop_ub; c4_i32++) {
      c4_r1[c4_i32] = (c4_nonzeroy[c4_i32] < c4_win_y_high);
    }

    c4_i33 = c4_r.size(0);
    c4_i35 = c4_r1.size(0);
    if (c4_i33 != c4_i35) {
      emlrtSizeEqCheck1DR2012b(c4_i33, c4_i35, &c4_emlrtECI, &c4_st);
    }

    c4_i_loop_ub = c4_r.size(0) - 1;
    for (c4_i36 = 0; c4_i36 <= c4_i_loop_ub; c4_i36++) {
      c4_r[c4_i36] = (c4_r[c4_i36] && c4_r1[c4_i36]);
    }

    c4_r1.set_size(&c4_e_emlrtRTEI, &c4_st, c4_nonzerox.size(0));
    c4_k_loop_ub = c4_nonzerox.size(0) - 1;
    for (c4_i38 = 0; c4_i38 <= c4_k_loop_ub; c4_i38++) {
      c4_r1[c4_i38] = (c4_nonzerox[c4_i38] >= c4_win_xleft_low);
    }

    c4_i40 = c4_r.size(0);
    c4_i41 = c4_r1.size(0);
    if ((c4_i40 != c4_i41) && ((c4_i40 != 1) && (c4_i41 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_i40, c4_i41, &c4_b_emlrtECI, &c4_st);
    }

    if (c4_r.size(0) == c4_r1.size(0)) {
      c4_o_loop_ub = c4_r.size(0) - 1;
      for (c4_i43 = 0; c4_i43 <= c4_o_loop_ub; c4_i43++) {
        c4_r[c4_i43] = (c4_r[c4_i43] && c4_r1[c4_i43]);
      }
    } else {
      c4_b_and(chartInstance, &c4_st, c4_r, c4_r1);
    }

    c4_r1.set_size(&c4_f_emlrtRTEI, &c4_st, c4_nonzerox.size(0));
    c4_p_loop_ub = c4_nonzerox.size(0) - 1;
    for (c4_i45 = 0; c4_i45 <= c4_p_loop_ub; c4_i45++) {
      c4_r1[c4_i45] = (c4_nonzerox[c4_i45] < c4_win_xleft_high);
    }

    c4_i47 = c4_r.size(0);
    c4_i48 = c4_r1.size(0);
    if ((c4_i47 != c4_i48) && ((c4_i47 != 1) && (c4_i48 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_i47, c4_i48, &c4_b_emlrtECI, &c4_st);
    }

    if (c4_r.size(0) == c4_r1.size(0)) {
      c4_r2.set_size(&c4_g_emlrtRTEI, &c4_st, c4_r.size(0));
      c4_q_loop_ub = c4_r.size(0) - 1;
      for (c4_i50 = 0; c4_i50 <= c4_q_loop_ub; c4_i50++) {
        c4_r2[c4_i50] = (c4_r[c4_i50] && c4_r1[c4_i50]);
      }
    } else {
      c4_and(chartInstance, &c4_st, c4_r2, c4_r, c4_r1);
    }

    c4_b_end = c4_r2.size(0);
    c4_b_trueCount = 0;
    for (c4_h_i = 0; c4_h_i < c4_b_end; c4_h_i++) {
      if (c4_r2[c4_h_i]) {
        c4_b_trueCount++;
      }
    }

    c4_good_leftx_indexs.set_size(static_cast<emlrtRTEInfo *>(NULL), &c4_st,
      c4_b_trueCount);
    c4_b_partialTrueCount = 0;
    for (c4_j_i = 0; c4_j_i < c4_b_end; c4_j_i++) {
      if (c4_r2[c4_j_i]) {
        c4_i51 = c4_nonzerox.size(0) - 1;
        c4_d4 = static_cast<real_T>(c4_j_i);
        if (c4_d4 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d4)))) {
          emlrtIntegerCheckR2012b(c4_d4, &c4_i_emlrtDCI, &c4_st);
        }

        c4_i53 = static_cast<int32_T>(muDoubleScalarFloor(c4_d4));
        if ((c4_i53 < 0) || (c4_i53 > c4_i51)) {
          emlrtDynamicBoundsCheckR2012b(c4_i53, 0, c4_i51, &c4_q_emlrtBCI,
            &c4_st);
        }

        c4_good_leftx_indexs[c4_b_partialTrueCount] = c4_nonzerox[c4_i53];
        c4_b_partialTrueCount++;
      }
    }

    c4_r.set_size(&c4_h_emlrtRTEI, &c4_st, c4_nonzeroy.size(0));
    c4_r_loop_ub = c4_nonzeroy.size(0) - 1;
    for (c4_i52 = 0; c4_i52 <= c4_r_loop_ub; c4_i52++) {
      c4_r[c4_i52] = (c4_nonzeroy[c4_i52] >= c4_win_y_low);
    }

    c4_r1.set_size(&c4_i_emlrtRTEI, &c4_st, c4_nonzeroy.size(0));
    c4_s_loop_ub = c4_nonzeroy.size(0) - 1;
    for (c4_i54 = 0; c4_i54 <= c4_s_loop_ub; c4_i54++) {
      c4_r1[c4_i54] = (c4_nonzeroy[c4_i54] < c4_win_y_high);
    }

    c4_i55 = c4_r.size(0);
    c4_i56 = c4_r1.size(0);
    if (c4_i55 != c4_i56) {
      emlrtSizeEqCheck1DR2012b(c4_i55, c4_i56, &c4_c_emlrtECI, &c4_st);
    }

    c4_t_loop_ub = c4_r.size(0) - 1;
    for (c4_i57 = 0; c4_i57 <= c4_t_loop_ub; c4_i57++) {
      c4_r[c4_i57] = (c4_r[c4_i57] && c4_r1[c4_i57]);
    }

    c4_r1.set_size(&c4_j_emlrtRTEI, &c4_st, c4_nonzerox.size(0));
    c4_u_loop_ub = c4_nonzerox.size(0) - 1;
    for (c4_i58 = 0; c4_i58 <= c4_u_loop_ub; c4_i58++) {
      c4_r1[c4_i58] = (c4_nonzerox[c4_i58] >= c4_win_xleft_low);
    }

    c4_i59 = c4_r.size(0);
    c4_i60 = c4_r1.size(0);
    if ((c4_i59 != c4_i60) && ((c4_i59 != 1) && (c4_i60 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_i59, c4_i60, &c4_d_emlrtECI, &c4_st);
    }

    if (c4_r.size(0) == c4_r1.size(0)) {
      c4_v_loop_ub = c4_r.size(0) - 1;
      for (c4_i61 = 0; c4_i61 <= c4_v_loop_ub; c4_i61++) {
        c4_r[c4_i61] = (c4_r[c4_i61] && c4_r1[c4_i61]);
      }
    } else {
      c4_b_and(chartInstance, &c4_st, c4_r, c4_r1);
    }

    c4_r1.set_size(&c4_k_emlrtRTEI, &c4_st, c4_nonzerox.size(0));
    c4_w_loop_ub = c4_nonzerox.size(0) - 1;
    for (c4_i62 = 0; c4_i62 <= c4_w_loop_ub; c4_i62++) {
      c4_r1[c4_i62] = (c4_nonzerox[c4_i62] < c4_win_xleft_high);
    }

    c4_i63 = c4_r.size(0);
    c4_i64 = c4_r1.size(0);
    if ((c4_i63 != c4_i64) && ((c4_i63 != 1) && (c4_i64 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_i63, c4_i64, &c4_d_emlrtECI, &c4_st);
    }

    if (c4_r.size(0) == c4_r1.size(0)) {
      c4_r3.set_size(&c4_m_emlrtRTEI, &c4_st, c4_r.size(0));
      c4_x_loop_ub = c4_r.size(0) - 1;
      for (c4_i65 = 0; c4_i65 <= c4_x_loop_ub; c4_i65++) {
        c4_r3[c4_i65] = (c4_r[c4_i65] && c4_r1[c4_i65]);
      }
    } else {
      c4_and(chartInstance, &c4_st, c4_r3, c4_r, c4_r1);
    }

    c4_c_end = c4_r3.size(0);
    c4_c_trueCount = 0;
    for (c4_k_i = 0; c4_k_i < c4_c_end; c4_k_i++) {
      if (c4_r3[c4_k_i]) {
        c4_c_trueCount++;
      }
    }

    c4_good_lefty_indexs.set_size(static_cast<emlrtRTEInfo *>(NULL), &c4_st,
      c4_c_trueCount);
    c4_c_partialTrueCount = 0;
    for (c4_m_i = 0; c4_m_i < c4_c_end; c4_m_i++) {
      if (c4_r3[c4_m_i]) {
        c4_i66 = c4_nonzeroy.size(0) - 1;
        c4_d5 = static_cast<real_T>(c4_m_i);
        if (c4_d5 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d5)))) {
          emlrtIntegerCheckR2012b(c4_d5, &c4_j_emlrtDCI, &c4_st);
        }

        c4_i68 = static_cast<int32_T>(muDoubleScalarFloor(c4_d5));
        if ((c4_i68 < 0) || (c4_i68 > c4_i66)) {
          emlrtDynamicBoundsCheckR2012b(c4_i68, 0, c4_i66, &c4_r_emlrtBCI,
            &c4_st);
        }

        c4_good_lefty_indexs[c4_c_partialTrueCount] = c4_nonzeroy[c4_i68];
        c4_c_partialTrueCount++;
      }
    }

    c4_r.set_size(&c4_o_emlrtRTEI, &c4_st, c4_nonzeroy.size(0));
    c4_y_loop_ub = c4_nonzeroy.size(0) - 1;
    for (c4_i67 = 0; c4_i67 <= c4_y_loop_ub; c4_i67++) {
      c4_r[c4_i67] = (c4_nonzeroy[c4_i67] >= c4_win_y_low);
    }

    c4_r1.set_size(&c4_p_emlrtRTEI, &c4_st, c4_nonzeroy.size(0));
    c4_ab_loop_ub = c4_nonzeroy.size(0) - 1;
    for (c4_i69 = 0; c4_i69 <= c4_ab_loop_ub; c4_i69++) {
      c4_r1[c4_i69] = (c4_nonzeroy[c4_i69] < c4_win_y_high);
    }

    c4_i70 = c4_r.size(0);
    c4_i71 = c4_r1.size(0);
    if (c4_i70 != c4_i71) {
      emlrtSizeEqCheck1DR2012b(c4_i70, c4_i71, &c4_e_emlrtECI, &c4_st);
    }

    c4_bb_loop_ub = c4_r.size(0) - 1;
    for (c4_i72 = 0; c4_i72 <= c4_bb_loop_ub; c4_i72++) {
      c4_r[c4_i72] = (c4_r[c4_i72] && c4_r1[c4_i72]);
    }

    c4_r1.set_size(&c4_q_emlrtRTEI, &c4_st, c4_nonzerox.size(0));
    c4_cb_loop_ub = c4_nonzerox.size(0) - 1;
    for (c4_i73 = 0; c4_i73 <= c4_cb_loop_ub; c4_i73++) {
      c4_r1[c4_i73] = (c4_nonzerox[c4_i73] >= c4_win_xright_low);
    }

    c4_i74 = c4_r.size(0);
    c4_i75 = c4_r1.size(0);
    if ((c4_i74 != c4_i75) && ((c4_i74 != 1) && (c4_i75 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_i74, c4_i75, &c4_f_emlrtECI, &c4_st);
    }

    if (c4_r.size(0) == c4_r1.size(0)) {
      c4_db_loop_ub = c4_r.size(0) - 1;
      for (c4_i76 = 0; c4_i76 <= c4_db_loop_ub; c4_i76++) {
        c4_r[c4_i76] = (c4_r[c4_i76] && c4_r1[c4_i76]);
      }
    } else {
      c4_b_and(chartInstance, &c4_st, c4_r, c4_r1);
    }

    c4_r1.set_size(&c4_r_emlrtRTEI, &c4_st, c4_nonzerox.size(0));
    c4_eb_loop_ub = c4_nonzerox.size(0) - 1;
    for (c4_i77 = 0; c4_i77 <= c4_eb_loop_ub; c4_i77++) {
      c4_r1[c4_i77] = (c4_nonzerox[c4_i77] < c4_win_xright_high);
    }

    c4_i78 = c4_r.size(0);
    c4_i79 = c4_r1.size(0);
    if ((c4_i78 != c4_i79) && ((c4_i78 != 1) && (c4_i79 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_i78, c4_i79, &c4_f_emlrtECI, &c4_st);
    }

    if (c4_r.size(0) == c4_r1.size(0)) {
      c4_r4.set_size(&c4_s_emlrtRTEI, &c4_st, c4_r.size(0));
      c4_fb_loop_ub = c4_r.size(0) - 1;
      for (c4_i80 = 0; c4_i80 <= c4_fb_loop_ub; c4_i80++) {
        c4_r4[c4_i80] = (c4_r[c4_i80] && c4_r1[c4_i80]);
      }
    } else {
      c4_and(chartInstance, &c4_st, c4_r4, c4_r, c4_r1);
    }

    c4_d_end = c4_r4.size(0);
    c4_d_trueCount = 0;
    for (c4_o_i = 0; c4_o_i < c4_d_end; c4_o_i++) {
      if (c4_r4[c4_o_i]) {
        c4_d_trueCount++;
      }
    }

    c4_good_rightx_indexs.set_size(static_cast<emlrtRTEInfo *>(NULL), &c4_st,
      c4_d_trueCount);
    c4_d_partialTrueCount = 0;
    for (c4_p_i = 0; c4_p_i < c4_d_end; c4_p_i++) {
      if (c4_r4[c4_p_i]) {
        c4_i81 = c4_nonzerox.size(0) - 1;
        c4_d6 = static_cast<real_T>(c4_p_i);
        if (c4_d6 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d6)))) {
          emlrtIntegerCheckR2012b(c4_d6, &c4_k_emlrtDCI, &c4_st);
        }

        c4_i83 = static_cast<int32_T>(muDoubleScalarFloor(c4_d6));
        if ((c4_i83 < 0) || (c4_i83 > c4_i81)) {
          emlrtDynamicBoundsCheckR2012b(c4_i83, 0, c4_i81, &c4_s_emlrtBCI,
            &c4_st);
        }

        c4_good_rightx_indexs[c4_d_partialTrueCount] = c4_nonzerox[c4_i83];
        c4_d_partialTrueCount++;
      }
    }

    c4_r.set_size(&c4_t_emlrtRTEI, &c4_st, c4_nonzeroy.size(0));
    c4_gb_loop_ub = c4_nonzeroy.size(0) - 1;
    for (c4_i82 = 0; c4_i82 <= c4_gb_loop_ub; c4_i82++) {
      c4_r[c4_i82] = (c4_nonzeroy[c4_i82] >= c4_win_y_low);
    }

    c4_r1.set_size(&c4_u_emlrtRTEI, &c4_st, c4_nonzeroy.size(0));
    c4_hb_loop_ub = c4_nonzeroy.size(0) - 1;
    for (c4_i84 = 0; c4_i84 <= c4_hb_loop_ub; c4_i84++) {
      c4_r1[c4_i84] = (c4_nonzeroy[c4_i84] < c4_win_y_high);
    }

    c4_i85 = c4_r.size(0);
    c4_i86 = c4_r1.size(0);
    if (c4_i85 != c4_i86) {
      emlrtSizeEqCheck1DR2012b(c4_i85, c4_i86, &c4_g_emlrtECI, &c4_st);
    }

    c4_ib_loop_ub = c4_r.size(0) - 1;
    for (c4_i87 = 0; c4_i87 <= c4_ib_loop_ub; c4_i87++) {
      c4_r[c4_i87] = (c4_r[c4_i87] && c4_r1[c4_i87]);
    }

    c4_r1.set_size(&c4_v_emlrtRTEI, &c4_st, c4_nonzerox.size(0));
    c4_jb_loop_ub = c4_nonzerox.size(0) - 1;
    for (c4_i88 = 0; c4_i88 <= c4_jb_loop_ub; c4_i88++) {
      c4_r1[c4_i88] = (c4_nonzerox[c4_i88] >= c4_win_xright_low);
    }

    c4_i89 = c4_r.size(0);
    c4_i90 = c4_r1.size(0);
    if ((c4_i89 != c4_i90) && ((c4_i89 != 1) && (c4_i90 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_i89, c4_i90, &c4_h_emlrtECI, &c4_st);
    }

    if (c4_r.size(0) == c4_r1.size(0)) {
      c4_kb_loop_ub = c4_r.size(0) - 1;
      for (c4_i91 = 0; c4_i91 <= c4_kb_loop_ub; c4_i91++) {
        c4_r[c4_i91] = (c4_r[c4_i91] && c4_r1[c4_i91]);
      }
    } else {
      c4_b_and(chartInstance, &c4_st, c4_r, c4_r1);
    }

    c4_r1.set_size(&c4_w_emlrtRTEI, &c4_st, c4_nonzerox.size(0));
    c4_mb_loop_ub = c4_nonzerox.size(0) - 1;
    for (c4_i92 = 0; c4_i92 <= c4_mb_loop_ub; c4_i92++) {
      c4_r1[c4_i92] = (c4_nonzerox[c4_i92] < c4_win_xright_high);
    }

    c4_i93 = c4_r.size(0);
    c4_i94 = c4_r1.size(0);
    if ((c4_i93 != c4_i94) && ((c4_i93 != 1) && (c4_i94 != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_i93, c4_i94, &c4_h_emlrtECI, &c4_st);
    }

    if (c4_r.size(0) == c4_r1.size(0)) {
      c4_r5.set_size(&c4_x_emlrtRTEI, &c4_st, c4_r.size(0));
      c4_ob_loop_ub = c4_r.size(0) - 1;
      for (c4_i95 = 0; c4_i95 <= c4_ob_loop_ub; c4_i95++) {
        c4_r5[c4_i95] = (c4_r[c4_i95] && c4_r1[c4_i95]);
      }
    } else {
      c4_and(chartInstance, &c4_st, c4_r5, c4_r, c4_r1);
    }

    c4_e_end = c4_r5.size(0);
    c4_e_trueCount = 0;
    for (c4_q_i = 0; c4_q_i < c4_e_end; c4_q_i++) {
      if (c4_r5[c4_q_i]) {
        c4_e_trueCount++;
      }
    }

    c4_good_righty_indexs.set_size(static_cast<emlrtRTEInfo *>(NULL), &c4_st,
      c4_e_trueCount);
    c4_e_partialTrueCount = 0;
    for (c4_s_i = 0; c4_s_i < c4_e_end; c4_s_i++) {
      if (c4_r5[c4_s_i]) {
        c4_i97 = c4_nonzeroy.size(0) - 1;
        c4_d8 = static_cast<real_T>(c4_s_i);
        if (c4_d8 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d8)))) {
          emlrtIntegerCheckR2012b(c4_d8, &c4_m_emlrtDCI, &c4_st);
        }

        c4_i99 = static_cast<int32_T>(muDoubleScalarFloor(c4_d8));
        if ((c4_i99 < 0) || (c4_i99 > c4_i97)) {
          emlrtDynamicBoundsCheckR2012b(c4_i99, 0, c4_i97, &c4_t_emlrtBCI,
            &c4_st);
        }

        c4_good_righty_indexs[c4_e_partialTrueCount] = c4_nonzeroy[c4_i99];
        c4_e_partialTrueCount++;
      }
    }

    c4_d7 = c4_count_left + 1.0;
    c4_i96 = c4_good_leftx_indexs.size(0);
    if (c4_i96 < 0) {
      emlrtDynamicBoundsCheckR2012b(c4_i96, 0, MAX_int32_T, &c4_emlrtBCI, &c4_st);
    }

    c4_d9 = static_cast<real_T>(c4_i96);
    c4_i98 = static_cast<int32_T>(c4_d9 + (1.0 - c4_d7));
    emlrtForLoopVectorCheckR2021a(c4_d7, 1.0, c4_d9, mxDOUBLE_CLASS, c4_i98,
      &c4_yc_emlrtRTEI, &c4_st);
    for (c4_j = 0; c4_j < c4_i98; c4_j++) {
      c4_b_j = c4_d7 + static_cast<real_T>(c4_j);
      covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 1, 1);
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_emlrtDCI, &c4_st);
      }

      c4_i101 = static_cast<int32_T>(c4_b_j);
      if ((c4_i101 < 1) || (c4_i101 > 100000)) {
        emlrtDynamicBoundsCheckR2012b(c4_i101, 1, 100000, &c4_e_emlrtBCI, &c4_st);
      }

      c4_c_j = c4_i101 - 1;
      c4_i103 = c4_good_leftx_indexs.size(0);
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_o_emlrtDCI, &c4_st);
      }

      c4_i105 = static_cast<int32_T>(c4_b_j);
      if ((c4_i105 < 1) || (c4_i105 > c4_i103)) {
        emlrtDynamicBoundsCheckR2012b(c4_i105, 1, c4_i103, &c4_u_emlrtBCI,
          &c4_st);
      }

      chartInstance->c4_left_lane_index[c4_c_j] = c4_good_leftx_indexs[c4_i105 -
        1];
      c4_i107 = c4_good_lefty_indexs.size(0);
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_p_emlrtDCI, &c4_st);
      }

      c4_i110 = static_cast<int32_T>(c4_b_j);
      if ((c4_i110 < 1) || (c4_i110 > c4_i107)) {
        emlrtDynamicBoundsCheckR2012b(c4_i110, 1, c4_i107, &c4_v_emlrtBCI,
          &c4_st);
      }

      chartInstance->c4_left_lane_index[100000 + c4_c_j] =
        c4_good_lefty_indexs[c4_i110 - 1];
      c4_count_left++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 1, 0);
    c4_d10 = c4_count_right + 1.0;
    c4_i100 = c4_good_rightx_indexs.size(0);
    if (c4_i100 < 0) {
      emlrtDynamicBoundsCheckR2012b(c4_i100, 0, MAX_int32_T, &c4_b_emlrtBCI,
        &c4_st);
    }

    c4_d11 = static_cast<real_T>(c4_i100);
    c4_i102 = static_cast<int32_T>(c4_d11 + (1.0 - c4_d10));
    emlrtForLoopVectorCheckR2021a(c4_d10, 1.0, c4_d11, mxDOUBLE_CLASS, c4_i102,
      &c4_ad_emlrtRTEI, &c4_st);
    for (c4_d_j = 0; c4_d_j < c4_i102; c4_d_j++) {
      c4_b_j = c4_d10 + static_cast<real_T>(c4_d_j);
      covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 2, 1);
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_c_emlrtDCI, &c4_st);
      }

      c4_i106 = static_cast<int32_T>(c4_b_j);
      if ((c4_i106 < 1) || (c4_i106 > 100000)) {
        emlrtDynamicBoundsCheckR2012b(c4_i106, 1, 100000, &c4_g_emlrtBCI, &c4_st);
      }

      c4_e_j = c4_i106 - 1;
      c4_i109 = c4_good_rightx_indexs.size(0);
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_q_emlrtDCI, &c4_st);
      }

      c4_i111 = static_cast<int32_T>(c4_b_j);
      if ((c4_i111 < 1) || (c4_i111 > c4_i109)) {
        emlrtDynamicBoundsCheckR2012b(c4_i111, 1, c4_i109, &c4_w_emlrtBCI,
          &c4_st);
      }

      chartInstance->c4_right_lane_index[c4_e_j] = c4_good_rightx_indexs[c4_i111
        - 1];
      c4_i112 = c4_good_righty_indexs.size(0);
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_r_emlrtDCI, &c4_st);
      }

      c4_i113 = static_cast<int32_T>(c4_b_j);
      if ((c4_i113 < 1) || (c4_i113 > c4_i112)) {
        emlrtDynamicBoundsCheckR2012b(c4_i113, 1, c4_i112, &c4_x_emlrtBCI,
          &c4_st);
      }

      chartInstance->c4_right_lane_index[100000 + c4_e_j] =
        c4_good_righty_indexs[c4_i113 - 1];
      c4_count_right++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 2, 0);
    c4_i104 = c4_good_leftx_indexs.size(0);
    if (c4_i104 < 0) {
      emlrtDynamicBoundsCheckR2012b(c4_i104, 0, MAX_int32_T, &c4_c_emlrtBCI,
        &c4_st);
    }

    c4_d12 = static_cast<real_T>(c4_i104);
    if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 0,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c4_covrtInstance, 4U, 0U, 0U, c4_d12,
                        40.0, -1, 4U, static_cast<int32_T>(c4_d12 > 40.0)))) {
      c4_b_st.site = &c4_af_emlrtRSI;
      c4_leftx_current = c4_mean(chartInstance, &c4_b_st, c4_good_leftx_indexs);
    }

    c4_i108 = c4_good_rightx_indexs.size(0);
    if (c4_i108 < 0) {
      emlrtDynamicBoundsCheckR2012b(c4_i108, 0, MAX_int32_T, &c4_d_emlrtBCI,
        &c4_st);
    }

    c4_d13 = static_cast<real_T>(c4_i108);
    if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 1,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c4_covrtInstance, 4U, 0U, 1U, c4_d13,
                        40.0, -1, 4U, static_cast<int32_T>(c4_d13 > 40.0)))) {
      c4_b_st.site = &c4_bf_emlrtRSI;
      c4_rightx_current = c4_mean(chartInstance, &c4_b_st, c4_good_rightx_indexs);
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 0, 0);
  c4_b_b = (c4_count_left < 1.0);
  c4_b_b1 = c4_b_b;
  c4_b2 = false;
  c4_b3 = (c4_b_b1 || c4_b2);
  if (c4_b3) {
    c4_i18 = 1;
    c4_i19 = 0;
  } else {
    c4_i18 = 1;
    if (c4_count_left != static_cast<real_T>(static_cast<int32_T>
         (muDoubleScalarFloor(c4_count_left)))) {
      emlrtIntegerCheckR2012b(c4_count_left, &c4_b_emlrtDCI, &c4_st);
    }

    c4_i20 = static_cast<int32_T>(c4_count_left);
    if ((c4_i20 < 1) || (c4_i20 > 100000)) {
      emlrtDynamicBoundsCheckR2012b(c4_i20, 1, 100000, &c4_f_emlrtBCI, &c4_st);
    }

    c4_i19 = c4_i20;
  }

  c4_actual_left_lane_index.set_size(&c4_y_emlrtRTEI, &c4_st, (c4_i19 - c4_i18)
    + 1, 2);
  for (c4_i21 = 0; c4_i21 < 2; c4_i21++) {
    c4_c_loop_ub = c4_i19 - c4_i18;
    for (c4_i23 = 0; c4_i23 <= c4_c_loop_ub; c4_i23++) {
      c4_actual_left_lane_index[c4_i23 + c4_actual_left_lane_index.size(0) *
        c4_i21] = chartInstance->c4_left_lane_index[((c4_i18 + c4_i23) + 100000 *
        c4_i21) - 1];
    }
  }

  c4_b4 = (c4_count_right < 1.0);
  c4_b5 = c4_b4;
  c4_b6 = false;
  c4_b7 = (c4_b5 || c4_b6);
  if (c4_b7) {
    c4_i24 = 1;
    c4_i26 = 0;
  } else {
    c4_i24 = 1;
    if (c4_count_right != static_cast<real_T>(static_cast<int32_T>
         (muDoubleScalarFloor(c4_count_right)))) {
      emlrtIntegerCheckR2012b(c4_count_right, &c4_d_emlrtDCI, &c4_st);
    }

    c4_i27 = static_cast<int32_T>(c4_count_right);
    if ((c4_i27 < 1) || (c4_i27 > 100000)) {
      emlrtDynamicBoundsCheckR2012b(c4_i27, 1, 100000, &c4_h_emlrtBCI, &c4_st);
    }

    c4_i26 = c4_i27;
  }

  c4_actual_right_lane_index.set_size(&c4_ab_emlrtRTEI, &c4_st, (c4_i26 - c4_i24)
    + 1, 2);
  for (c4_i28 = 0; c4_i28 < 2; c4_i28++) {
    c4_e_loop_ub = c4_i26 - c4_i24;
    for (c4_i30 = 0; c4_i30 <= c4_e_loop_ub; c4_i30++) {
      c4_actual_right_lane_index[c4_i30 + c4_actual_right_lane_index.size(0) *
        c4_i28] = chartInstance->c4_right_lane_index[((c4_i24 + c4_i30) + 100000
        * c4_i28) - 1];
    }
  }

  c4_b_actual_left_lane_index.set_size(&c4_bb_emlrtRTEI, &c4_st,
    c4_actual_left_lane_index.size(0));
  c4_f_loop_ub = c4_actual_left_lane_index.size(0) - 1;
  for (c4_i31 = 0; c4_i31 <= c4_f_loop_ub; c4_i31++) {
    c4_b_actual_left_lane_index[c4_i31] = c4_actual_left_lane_index[c4_i31 +
      c4_actual_left_lane_index.size(0)];
  }

  c4_c_actual_left_lane_index.set_size(&c4_cb_emlrtRTEI, &c4_st,
    c4_actual_left_lane_index.size(0));
  c4_h_loop_ub = c4_actual_left_lane_index.size(0) - 1;
  for (c4_i34 = 0; c4_i34 <= c4_h_loop_ub; c4_i34++) {
    c4_c_actual_left_lane_index[c4_i34] = c4_actual_left_lane_index[c4_i34];
  }

  c4_b_st.site = &c4_cf_emlrtRSI;
  c4_polyfit(chartInstance, &c4_b_st, c4_b_actual_left_lane_index,
             c4_c_actual_left_lane_index, c4_p_left);
  c4_b_actual_right_lane_index.set_size(&c4_db_emlrtRTEI, &c4_st,
    c4_actual_right_lane_index.size(0));
  c4_j_loop_ub = c4_actual_right_lane_index.size(0) - 1;
  for (c4_i37 = 0; c4_i37 <= c4_j_loop_ub; c4_i37++) {
    c4_b_actual_right_lane_index[c4_i37] = c4_actual_right_lane_index[c4_i37 +
      c4_actual_right_lane_index.size(0)];
  }

  c4_c_actual_right_lane_index.set_size(&c4_eb_emlrtRTEI, &c4_st,
    c4_actual_right_lane_index.size(0));
  c4_m_loop_ub = c4_actual_right_lane_index.size(0) - 1;
  for (c4_i39 = 0; c4_i39 <= c4_m_loop_ub; c4_i39++) {
    c4_c_actual_right_lane_index[c4_i39] = c4_actual_right_lane_index[c4_i39];
  }

  c4_b_st.site = &c4_df_emlrtRSI;
  c4_polyfit(chartInstance, &c4_b_st, c4_b_actual_right_lane_index,
             c4_c_actual_right_lane_index, c4_p_right);
  for (c4_i42 = 0; c4_i42 < 751; c4_i42++) {
    c4_xleft[c4_i42] = c4_p_left[0];
  }

  for (c4_b_k = 0; c4_b_k < 2; c4_b_k++) {
    c4_c_k = 2.0 + static_cast<real_T>(c4_b_k);
    c4_b_p_left = c4_p_left[static_cast<int32_T>(c4_c_k) - 1];
    for (c4_i46 = 0; c4_i46 < 751; c4_i46++) {
      c4_xleft[c4_i46] = static_cast<real_T>(c4_i46) * c4_xleft[c4_i46] +
        c4_b_p_left;
    }
  }

  for (c4_i44 = 0; c4_i44 < 751; c4_i44++) {
    c4_xright[c4_i44] = c4_p_right[0];
  }

  for (c4_d_k = 0; c4_d_k < 2; c4_d_k++) {
    c4_e_k = 2.0 + static_cast<real_T>(c4_d_k);
    c4_b_p_right = c4_p_right[static_cast<int32_T>(c4_e_k) - 1];
    for (c4_i49 = 0; c4_i49 < 751; c4_i49++) {
      c4_xright[c4_i49] = static_cast<real_T>(c4_i49) * c4_xright[c4_i49] +
        c4_b_p_right;
    }
  }

  c4_b_error = 600.0 - (c4_xleft[750] + c4_xright[750]) / 2.0;
  *chartInstance->c4_error = c4_b_error;
  c4_do_animation_call_c4_LKAS(chartInstance);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U,
                    *chartInstance->c4_error);
}

static void ext_mode_exec_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
}

static void c4_update_jit_animation_c4_LKAS(SFc4_LKASInstanceStruct
  *chartInstance)
{
}

static void c4_do_animation_call_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c4_LKAS(SFc4_LKASInstanceStruct
  *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", chartInstance->c4_error, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &chartInstance->c4_is_active_c4_LKAS,
    3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_LKAS(SFc4_LKASInstanceStruct *chartInstance, const
  mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_error = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "error");
  chartInstance->c4_is_active_c4_LKAS = c4_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 1)), "is_active_c4_LKAS");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void initSimStructsc4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
}

static void initSubchartIOPointersc4_LKAS(SFc4_LKASInstanceStruct *chartInstance)
{
}

static void c4_findpeaks(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_Yin[1200], coder::array<real_T, 2U> &c4_Ypk,
  coder::array<real_T, 2U> &c4_Xpk)
{
  static char_T c4_b_cv[50] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'c', 'o', 'l', 'o', 'n', '_', 's', 'c', 'a', 'l', 'a', 'r',
    'D', 'o', 'u', 'b', 'l', 'e', 'M', 'u', 's', 't', 'B', 'e', 'I', 'n', 't',
    'e', 'g', 'e', 'r', 'V', 'a', 'l', 'u', 'e', 'd' };

  static char_T c4_b_cv1[29] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'c', 'o', 'l', 'o', 'n', '_', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  static char_T c4_b_cv2[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  coder::array<real_T, 1U> c4_b_Xpk;
  coder::array<real_T, 1U> c4_b_Ypk;
  coder::array<int32_T, 2U> c4_r_y;
  coder::array<int32_T, 1U> c4_b_iPk;
  coder::array<int32_T, 1U> c4_c;
  coder::array<int32_T, 1U> c4_c_idx;
  coder::array<int32_T, 1U> c4_fPk;
  coder::array<int32_T, 1U> c4_iInfinite;
  coder::array<int32_T, 1U> c4_iPk;
  coder::array<int32_T, 1U> c4_idx;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_g_st;
  emlrtStack c4_h_st;
  emlrtStack c4_st;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_m_y = NULL;
  const mxArray *c4_o_y = NULL;
  const mxArray *c4_p_y = NULL;
  const mxArray *c4_q_y = NULL;
  const mxArray *c4_s_y = NULL;
  const mxArray *c4_t_y = NULL;
  real_T c4_b_y[1200];
  real_T c4_y[1200];
  real_T c4_dv[2];
  real_T c4_a;
  real_T c4_b_a;
  real_T c4_b_d;
  real_T c4_b_d1;
  real_T c4_b_x;
  real_T c4_base;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_d;
  real_T c4_d10;
  real_T c4_d11;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  real_T c4_d6;
  real_T c4_d7;
  real_T c4_d8;
  real_T c4_d9;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_e_b;
  real_T c4_e_x;
  real_T c4_f_b;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_g_b;
  real_T c4_g_x;
  real_T c4_h_b;
  real_T c4_h_x;
  real_T c4_h_y;
  real_T c4_j_y;
  real_T c4_k_y;
  real_T c4_pk;
  real_T c4_varargin_1;
  real_T c4_varargin_2;
  int32_T c4_iv[2];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_c;
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_n;
  int32_T c4_bma;
  int32_T c4_c_a;
  int32_T c4_c_bi;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_d_a;
  int32_T c4_d_loop_ub;
  int32_T c4_e_a;
  int32_T c4_e_loop_ub;
  int32_T c4_f_a;
  int32_T c4_f_loop_ub;
  int32_T c4_g_a;
  int32_T c4_g_loop_ub;
  int32_T c4_h_a;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_j;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_k_b;
  int32_T c4_loop_ub;
  int32_T c4_m_b;
  int32_T c4_n;
  int32_T c4_nPk;
  int32_T c4_nm1;
  int32_T c4_o_b;
  int32_T c4_p_b;
  int32_T c4_q_b;
  int32_T c4_span;
  int32_T c4_yk;
  boolean_T c4_b10;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b9;
  boolean_T c4_b_b1;
  boolean_T c4_b_b8;
  boolean_T c4_b_overflow;
  boolean_T c4_c_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_g_st.prev = &c4_f_st;
  c4_g_st.tls = c4_f_st.tls;
  c4_h_st.prev = &c4_g_st;
  c4_h_st.tls = c4_g_st.tls;
  for (c4_i = 0; c4_i < 1200; c4_i++) {
    c4_y[c4_i] = c4_Yin[c4_i];
  }

  c4_st.site = &c4_emlrtRSI;
  for (c4_i1 = 0; c4_i1 < 1200; c4_i1++) {
    c4_b_y[c4_i1] = c4_y[c4_i1];
  }

  c4_getAllPeaksCodegen(chartInstance, &c4_st, c4_b_y, c4_fPk, c4_iInfinite,
                        c4_idx);
  c4_st.site = &c4_b_emlrtRSI;
  c4_iPk.set_size(&c4_fb_emlrtRTEI, &c4_st, c4_fPk.size(0));
  c4_nPk = 0;
  c4_n = c4_fPk.size(0);
  c4_b_st.site = &c4_j_emlrtRSI;
  c4_b = c4_n;
  c4_b_b = c4_b;
  if (c4_b_b < 1) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_i_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st, c4_overflow);
  }

  for (c4_k = 0; c4_k < c4_n; c4_k++) {
    c4_b_k = c4_k;
    c4_i2 = c4_fPk.size(0);
    c4_d = static_cast<real_T>(c4_b_k + 1);
    if (c4_d != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d)))) {
      emlrtIntegerCheckR2012b(c4_d, &c4_u_emlrtDCI, &c4_st);
    }

    c4_i5 = static_cast<int32_T>(muDoubleScalarFloor(c4_d));
    if ((c4_i5 < 1) || (c4_i5 > c4_i2)) {
      emlrtDynamicBoundsCheckR2012b(c4_i5, 1, c4_i2, &c4_db_emlrtBCI, &c4_st);
    }

    c4_j = c4_fPk[c4_i5 - 1];
    c4_d2 = static_cast<real_T>(c4_j);
    if (c4_d2 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d2)))) {
      emlrtIntegerCheckR2012b(c4_d2, &c4_v_emlrtDCI, &c4_st);
    }

    c4_i9 = static_cast<int32_T>(muDoubleScalarFloor(c4_d2));
    if ((c4_i9 < 1) || (c4_i9 > 1200)) {
      emlrtDynamicBoundsCheckR2012b(c4_i9, 1, 1200, &c4_eb_emlrtBCI, &c4_st);
    }

    c4_pk = c4_y[c4_i9 - 1];
    if (c4_pk > rtMinusInf) {
      c4_d3 = static_cast<real_T>(c4_j - 1);
      if (c4_d3 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_d3)))) {
        emlrtIntegerCheckR2012b(c4_d3, &c4_w_emlrtDCI, &c4_st);
      }

      c4_i11 = static_cast<int32_T>(muDoubleScalarFloor(c4_d3));
      if ((c4_i11 < 1) || (c4_i11 > 1200)) {
        emlrtDynamicBoundsCheckR2012b(c4_i11, 1, 1200, &c4_fb_emlrtBCI, &c4_st);
      }

      c4_varargin_1 = c4_y[c4_i11 - 1];
      c4_d4 = static_cast<real_T>(c4_j + 1);
      if (c4_d4 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_d4)))) {
        emlrtIntegerCheckR2012b(c4_d4, &c4_x_emlrtDCI, &c4_st);
      }

      c4_i12 = static_cast<int32_T>(muDoubleScalarFloor(c4_d4));
      if ((c4_i12 < 1) || (c4_i12 > 1200)) {
        emlrtDynamicBoundsCheckR2012b(c4_i12, 1, 1200, &c4_gb_emlrtBCI, &c4_st);
      }

      c4_varargin_2 = c4_y[c4_i12 - 1];
      c4_d_x = c4_varargin_1;
      c4_d_y = c4_varargin_2;
      c4_e_x = c4_d_x;
      c4_f_y = c4_d_y;
      c4_f_x = c4_e_x;
      c4_h_y = c4_f_y;
      c4_a = c4_f_x;
      c4_h_b = c4_h_y;
      c4_g_x = c4_a;
      c4_j_y = c4_h_b;
      c4_h_x = c4_g_x;
      c4_k_y = c4_j_y;
      c4_base = muDoubleScalarMax(c4_h_x, c4_k_y);
      if (c4_pk - c4_base >= 0.0) {
        c4_nPk++;
        c4_i13 = c4_iPk.size(0);
        c4_d5 = static_cast<real_T>(c4_nPk);
        if (c4_d5 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d5)))) {
          emlrtIntegerCheckR2012b(c4_d5, &c4_y_emlrtDCI, &c4_st);
        }

        c4_i14 = static_cast<int32_T>(muDoubleScalarFloor(c4_d5));
        if ((c4_i14 < 1) || (c4_i14 > c4_i13)) {
          emlrtDynamicBoundsCheckR2012b(c4_i14, 1, c4_i13, &c4_hb_emlrtBCI,
            &c4_st);
        }

        c4_iPk[c4_i14 - 1] = c4_j;
      }
    }
  }

  c4_c_b = (c4_nPk < 1);
  c4_b_b1 = c4_c_b;
  c4_b2 = false;
  c4_b3 = (c4_b_b1 || c4_b2);
  if (c4_b3) {
    c4_i4 = 1;
    c4_i6 = 0;
  } else {
    c4_i3 = c4_iPk.size(0);
    if (c4_i3 < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, c4_i3, &c4_bb_emlrtBCI, &c4_st);
    }

    c4_i4 = 1;
    c4_b_d1 = static_cast<real_T>(c4_nPk);
    if (c4_b_d1 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_b_d1)))) {
      emlrtIntegerCheckR2012b(c4_b_d1, &c4_t_emlrtDCI, &c4_st);
    }

    c4_i8 = c4_iPk.size(0);
    if ((static_cast<int32_T>(muDoubleScalarFloor(c4_b_d1)) < 1) || (
         static_cast<int32_T>(muDoubleScalarFloor(c4_b_d1)) > c4_i8)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(muDoubleScalarFloor
        (c4_b_d1)), 1, c4_i8, &c4_cb_emlrtBCI, &c4_st);
    }

    c4_i6 = static_cast<int32_T>(muDoubleScalarFloor(c4_b_d1));
  }

  c4_b_iPk.set_size(&c4_gb_emlrtRTEI, &c4_st, (c4_i6 - c4_i4) + 1);
  c4_loop_ub = c4_i6 - c4_i4;
  for (c4_i7 = 0; c4_i7 <= c4_loop_ub; c4_i7++) {
    c4_b_iPk[c4_i7] = c4_iPk[(c4_i4 + c4_i7) - 1];
  }

  c4_iPk.set_size(&c4_hb_emlrtRTEI, &c4_st, c4_b_iPk.size(0));
  c4_b_loop_ub = c4_b_iPk.size(0) - 1;
  for (c4_i10 = 0; c4_i10 <= c4_b_loop_ub; c4_i10++) {
    c4_iPk[c4_i10] = c4_b_iPk[c4_i10];
  }

  c4_st.site = &c4_c_emlrtRSI;
  c4_b_st.site = &c4_k_emlrtRSI;
  c4_c_st.site = &c4_m_emlrtRSI;
  c4_d_st.site = &c4_o_emlrtRSI;
  c4_do_vectors(chartInstance, &c4_d_st, c4_iPk, c4_iInfinite, c4_c, c4_idx,
                c4_fPk);
  c4_st.site = &c4_d_emlrtRSI;
  c4_b_st.site = &c4_u_emlrtRSI;
  c4_b_d = static_cast<real_T>(c4_c.size(0));
  c4_c_st.site = &c4_v_emlrtRSI;
  c4_e_b = c4_b_d;
  c4_b_x = c4_e_b;
  c4_c_x = c4_b_x;
  c4_c_y = c4_c_x;
  c4_c_y = muDoubleScalarFloor(c4_c_y);
  if (c4_c_y == c4_e_b) {
    c4_b4 = true;
  } else {
    c4_b4 = false;
  }

  if (!c4_b4) {
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 50),
                  false);
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 50),
                  false);
    sf_mex_call(&c4_c_st, &c4_g_emlrtMCI, "error", 0U, 2U, 14, c4_e_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 1U, 14, c4_g_y)));
  }

  c4_d_st.site = &c4_w_emlrtRSI;
  c4_f_b = c4_e_b;
  c4_e_st.site = &c4_x_emlrtRSI;
  c4_g_b = c4_f_b;
  if ((c4_g_b <= 2.147483647E+9) && (c4_g_b >= -2.147483648E+9)) {
    c4_b5 = true;
  } else {
    c4_b5 = false;
  }

  if (!c4_b5) {
    c4_m_y = NULL;
    sf_mex_assign(&c4_m_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c4_o_y = NULL;
    sf_mex_assign(&c4_o_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    sf_mex_call(&c4_e_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_m_y, 14,
                sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_e_st, NULL, "message", 1U, 1U, 14, c4_o_y)));
  }

  c4_b_a = c4_f_b;
  c4_c_bi = static_cast<int32_T>(muDoubleScalarFloor(c4_b_a));
  c4_e_st.site = &c4_y_emlrtRSI;
  c4_j_b = c4_c_bi;
  c4_f_st.site = &c4_ab_emlrtRSI;
  c4_k_b = c4_j_b;
  c4_g_st.site = &c4_cb_emlrtRSI;
  c4_m_b = c4_k_b;
  if (c4_m_b < 1) {
    c4_b_n = 0;
  } else {
    c4_c_a = c4_m_b - 1;
    c4_bma = c4_c_a;
    if (!(c4_bma >= 0)) {
      c4_p_y = NULL;
      sf_mex_assign(&c4_p_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c4_q_y = NULL;
      sf_mex_assign(&c4_q_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c4_g_st, &c4_i_emlrtMCI, "error", 0U, 2U, 14, c4_p_y, 14,
                  sf_mex_call(&c4_g_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c4_g_st, NULL, "message", 1U, 1U, 14, c4_q_y)));
    }

    c4_d_a = c4_bma;
    c4_span = c4_d_a;
    c4_e_a = c4_span;
    c4_nm1 = c4_e_a;
    if (c4_nm1 < MAX_int32_T) {
      c4_b6 = true;
    } else {
      c4_b6 = false;
    }

    c4_h_st.site = &c4_db_emlrtRSI;
    c4_p = c4_b6;
    if (!c4_p) {
      c4_s_y = NULL;
      sf_mex_assign(&c4_s_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        21), false);
      c4_t_y = NULL;
      sf_mex_assign(&c4_t_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        21), false);
      sf_mex_call(&c4_h_st, &c4_j_emlrtMCI, "error", 0U, 2U, 14, c4_s_y, 14,
                  sf_mex_call(&c4_h_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c4_h_st, NULL, "message", 1U, 1U, 14, c4_t_y)));
    }

    c4_f_a = c4_nm1;
    c4_q_b = c4_f_a;
    c4_g_a = c4_q_b + 1;
    c4_b_n = c4_g_a;
  }

  c4_d6 = static_cast<real_T>(c4_b_n);
  if (!(c4_d6 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d6, &c4_fb_emlrtDCI, &c4_e_st);
  }

  c4_r_y.set_size(&c4_ib_emlrtRTEI, &c4_e_st, 1, static_cast<int32_T>
                  (muDoubleScalarFloor(c4_d6)));
  if (c4_b_n > 0) {
    c4_r_y[0] = 1;
    c4_yk = 1;
    c4_f_st.site = &c4_bb_emlrtRSI;
    c4_o_b = c4_b_n;
    c4_p_b = c4_o_b;
    if (c4_p_b < 2) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_p_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_g_st.site = &c4_i_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_g_st, c4_b_overflow);
    }

    for (c4_c_k = 2; c4_c_k <= c4_b_n; c4_c_k++) {
      c4_h_a = c4_yk + 1;
      c4_yk = c4_h_a;
      c4_r_y[c4_c_k - 1] = c4_yk;
    }
  }

  c4_idx.set_size(&c4_jb_emlrtRTEI, &c4_st, c4_r_y.size(1));
  c4_c_loop_ub = c4_r_y.size(1) - 1;
  for (c4_i15 = 0; c4_i15 <= c4_c_loop_ub; c4_i15++) {
    c4_idx[c4_i15] = c4_r_y[c4_i15];
  }

  if (static_cast<real_T>(c4_idx.size(0)) > 1200.0) {
    c4_fPk.set_size(&c4_mb_emlrtRTEI, c4_sp, 1200);
    c4_st.site = &c4_e_emlrtRSI;
    c4_indexShapeCheck(chartInstance, &c4_st, c4_idx.size(0));
    c4_b_idx = c4_idx.size(0);
    c4_c_idx.set_size(&c4_ob_emlrtRTEI, c4_sp, 1200);
    for (c4_i16 = 0; c4_i16 < 1200; c4_i16++) {
      c4_i17 = c4_i16 + 1;
      if ((c4_i17 < 1) || (c4_i17 > c4_b_idx)) {
        emlrtDynamicBoundsCheckR2012b(c4_i17, 1, c4_b_idx, &c4_ib_emlrtBCI,
          (emlrtConstCTX)c4_sp);
      }

      c4_c_idx[c4_i16] = c4_idx[c4_i17 - 1];
    }

    c4_idx.set_size(&c4_pb_emlrtRTEI, c4_sp, c4_c_idx.size(0));
    c4_d_loop_ub = c4_c_idx.size(0) - 1;
    for (c4_i18 = 0; c4_i18 <= c4_d_loop_ub; c4_i18++) {
      c4_idx[c4_i18] = c4_c_idx[c4_i18];
    }
  } else {
    c4_d7 = static_cast<real_T>(c4_idx.size(0));
    if (!(c4_d7 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c4_d7, &c4_ab_emlrtDCI, (emlrtConstCTX)c4_sp);
    }

    if (c4_d7 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d7)))) {
      emlrtIntegerCheckR2012b(c4_d7, &c4_bb_emlrtDCI, (emlrtConstCTX)c4_sp);
    }

    c4_dv[0] = c4_d7;
    c4_fPk.set_size(&c4_kb_emlrtRTEI, c4_sp, static_cast<int32_T>(c4_dv[0]));
  }

  c4_d8 = static_cast<real_T>(c4_fPk.size(0));
  c4_b7 = (c4_d8 < 1.0);
  c4_b_b8 = c4_b7;
  c4_b9 = false;
  c4_b10 = (c4_b_b8 || c4_b9);
  if (c4_b10) {
    c4_i20 = 1;
    c4_i22 = 0;
  } else {
    c4_i19 = c4_idx.size(0);
    c4_i21 = 1;
    if ((c4_i21 < 1) || (c4_i21 > c4_i19)) {
      emlrtDynamicBoundsCheckR2012b(c4_i21, 1, c4_i19, &c4_y_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_i20 = c4_i21;
    if (c4_d8 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d8)))) {
      emlrtIntegerCheckR2012b(c4_d8, &c4_s_emlrtDCI, (emlrtConstCTX)c4_sp);
    }

    c4_i23 = c4_idx.size(0);
    c4_i24 = static_cast<int32_T>(c4_d8);
    if ((c4_i24 < 1) || (c4_i24 > c4_i23)) {
      emlrtDynamicBoundsCheckR2012b(c4_i24, 1, c4_i23, &c4_ab_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_i22 = c4_i24;
  }

  c4_iv[0] = 1;
  c4_iv[1] = (c4_i22 - c4_i20) + 1;
  c4_st.site = &c4_f_emlrtRSI;
  c4_b_indexShapeCheck(chartInstance, &c4_st, c4_idx.size(0), c4_iv);
  c4_b_c = c4_c.size(0);
  c4_fPk.set_size(&c4_qb_emlrtRTEI, c4_sp, (c4_i22 - c4_i20) + 1);
  c4_e_loop_ub = c4_i22 - c4_i20;
  for (c4_i25 = 0; c4_i25 <= c4_e_loop_ub; c4_i25++) {
    c4_d9 = static_cast<real_T>(c4_idx[(c4_i20 + c4_i25) - 1]);
    if (c4_d9 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d9)))) {
      emlrtIntegerCheckR2012b(c4_d9, &c4_cb_emlrtDCI, (emlrtConstCTX)c4_sp);
    }

    c4_i27 = static_cast<int32_T>(muDoubleScalarFloor(c4_d9));
    if ((c4_i27 < 1) || (c4_i27 > c4_b_c)) {
      emlrtDynamicBoundsCheckR2012b(c4_i27, 1, c4_b_c, &c4_jb_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_fPk[c4_i25] = c4_c[c4_i27 - 1];
  }

  c4_st.site = &c4_g_emlrtRSI;
  c4_b_Ypk.set_size(&c4_rb_emlrtRTEI, &c4_st, c4_fPk.size(0));
  c4_f_loop_ub = c4_fPk.size(0) - 1;
  for (c4_i26 = 0; c4_i26 <= c4_f_loop_ub; c4_i26++) {
    c4_d10 = static_cast<real_T>(c4_fPk[c4_i26]);
    if (c4_d10 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d10)))) {
      emlrtIntegerCheckR2012b(c4_d10, &c4_db_emlrtDCI, &c4_st);
    }

    c4_i29 = static_cast<int32_T>(muDoubleScalarFloor(c4_d10));
    if ((c4_i29 < 1) || (c4_i29 > 1200)) {
      emlrtDynamicBoundsCheckR2012b(c4_i29, 1, 1200, &c4_kb_emlrtBCI, &c4_st);
    }

    c4_b_Ypk[c4_i26] = c4_y[c4_i29 - 1];
  }

  c4_b_Xpk.set_size(&c4_sb_emlrtRTEI, &c4_st, c4_fPk.size(0));
  c4_g_loop_ub = c4_fPk.size(0) - 1;
  for (c4_i28 = 0; c4_i28 <= c4_g_loop_ub; c4_i28++) {
    c4_d11 = static_cast<real_T>(c4_fPk[c4_i28]);
    if (c4_d11 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d11)))) {
      emlrtIntegerCheckR2012b(c4_d11, &c4_eb_emlrtDCI, &c4_st);
    }

    c4_i31 = static_cast<int32_T>(muDoubleScalarFloor(c4_d11));
    if ((c4_i31 < 1) || (c4_i31 > 1200)) {
      emlrtDynamicBoundsCheckR2012b(c4_i31, 1, 1200, &c4_mb_emlrtBCI, &c4_st);
    }

    c4_b_Xpk[c4_i28] = 1.0 + static_cast<real_T>(c4_i31 - 1);
  }

  c4_Ypk.set_size(&c4_tb_emlrtRTEI, &c4_st, 1, c4_b_Ypk.size(0));
  c4_h_loop_ub = c4_b_Ypk.size(0) - 1;
  for (c4_i30 = 0; c4_i30 <= c4_h_loop_ub; c4_i30++) {
    c4_Ypk[c4_i30] = c4_b_Ypk[c4_i30];
  }

  c4_Xpk.set_size(&c4_ub_emlrtRTEI, &c4_st, 1, c4_b_Xpk.size(0));
  c4_i_loop_ub = c4_b_Xpk.size(0) - 1;
  for (c4_i32 = 0; c4_i32 <= c4_i_loop_ub; c4_i32++) {
    c4_Xpk[c4_i32] = c4_b_Xpk[c4_i32];
  }
}

static void c4_getAllPeaksCodegen(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_y[1200], coder::array<int32_T, 1U> &c4_iPk, coder::
  array<int32_T, 1U> &c4_iInf, coder::array<int32_T, 1U> &c4_iInflect)
{
  coder::array<int32_T, 1U> c4_b_iInf;
  coder::array<int32_T, 1U> c4_b_iInflect;
  coder::array<int32_T, 1U> c4_b_iPk;
  real_T c4_b_d1;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d10;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  real_T c4_d6;
  real_T c4_d7;
  real_T c4_d8;
  real_T c4_d9;
  real_T c4_yk;
  real_T c4_ykfirst;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_k;
  int32_T c4_kfirst;
  int32_T c4_loop_ub;
  int32_T c4_nInf;
  int32_T c4_nInflect;
  int32_T c4_nPk;
  char_T c4_dir;
  char_T c4_previousdir;
  boolean_T c4_b;
  boolean_T c4_b10;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b9;
  boolean_T c4_b_b;
  boolean_T c4_b_b1;
  boolean_T c4_b_b11;
  boolean_T c4_b_b8;
  boolean_T c4_c_b;
  boolean_T c4_guard1;
  boolean_T c4_isinfyk;
  boolean_T c4_isinfykfirst;
  c4_iPk.set_size(&c4_vb_emlrtRTEI, c4_sp, 1200);
  c4_iInf.set_size(&c4_wb_emlrtRTEI, c4_sp, 1200);
  c4_iInflect.set_size(&c4_xb_emlrtRTEI, c4_sp, 1200);
  c4_nPk = 0;
  c4_nInf = 0;
  c4_nInflect = 0;
  c4_dir = 'n';
  c4_kfirst = 0;
  c4_ykfirst = rtInf;
  c4_isinfykfirst = true;
  for (c4_k = 0; c4_k < 1200; c4_k++) {
    c4_d = static_cast<real_T>(c4_k + 1);
    if (c4_d != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d)))) {
      emlrtIntegerCheckR2012b(c4_d, &c4_jb_emlrtDCI, (emlrtConstCTX)c4_sp);
    }

    c4_i1 = static_cast<int32_T>(muDoubleScalarFloor(c4_d));
    if ((c4_i1 < 1) || (c4_i1 > 1200)) {
      emlrtDynamicBoundsCheckR2012b(c4_i1, 1, 1200, &c4_ub_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_yk = c4_y[c4_i1 - 1];
    c4_b_x = c4_yk;
    c4_b_b = muDoubleScalarIsNaN(c4_b_x);
    if (c4_b_b) {
      c4_yk = rtInf;
      c4_isinfyk = true;
    } else {
      c4_c_x = c4_yk;
      c4_c_b = muDoubleScalarIsInf(c4_c_x);
      if (c4_c_b && (c4_yk > 0.0)) {
        c4_isinfyk = true;
        c4_nInf++;
        c4_i10 = c4_iInf.size(0);
        c4_d4 = static_cast<real_T>(c4_nInf);
        if (c4_d4 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d4)))) {
          emlrtIntegerCheckR2012b(c4_d4, &c4_ob_emlrtDCI, (emlrtConstCTX)c4_sp);
        }

        c4_i12 = static_cast<int32_T>(muDoubleScalarFloor(c4_d4));
        if ((c4_i12 < 1) || (c4_i12 > c4_i10)) {
          emlrtDynamicBoundsCheckR2012b(c4_i12, 1, c4_i10, &c4_xb_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_iInf[c4_i12 - 1] = c4_k + 1;
      } else {
        c4_isinfyk = false;
      }
    }

    if (c4_yk != c4_ykfirst) {
      c4_previousdir = c4_dir;
      if (c4_isinfyk || c4_isinfykfirst) {
        c4_dir = 'n';
        if (c4_kfirst >= 1) {
          c4_nInflect++;
          c4_i13 = c4_iInflect.size(0);
          c4_d5 = static_cast<real_T>(c4_nInflect);
          if (c4_d5 != static_cast<real_T>(static_cast<int32_T>
               (muDoubleScalarFloor(c4_d5)))) {
            emlrtIntegerCheckR2012b(c4_d5, &c4_pb_emlrtDCI, (emlrtConstCTX)c4_sp);
          }

          c4_i18 = static_cast<int32_T>(muDoubleScalarFloor(c4_d5));
          if ((c4_i18 < 1) || (c4_i18 > c4_i13)) {
            emlrtDynamicBoundsCheckR2012b(c4_i18, 1, c4_i13, &c4_yb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_iInflect[c4_i18 - 1] = c4_kfirst;
        }
      } else if (c4_yk < c4_ykfirst) {
        c4_dir = 'd';
        if (c4_previousdir != 'd') {
          c4_nInflect++;
          c4_i15 = c4_iInflect.size(0);
          c4_d7 = static_cast<real_T>(c4_nInflect);
          if (c4_d7 != static_cast<real_T>(static_cast<int32_T>
               (muDoubleScalarFloor(c4_d7)))) {
            emlrtIntegerCheckR2012b(c4_d7, &c4_rb_emlrtDCI, (emlrtConstCTX)c4_sp);
          }

          c4_i21 = static_cast<int32_T>(muDoubleScalarFloor(c4_d7));
          if ((c4_i21 < 1) || (c4_i21 > c4_i15)) {
            emlrtDynamicBoundsCheckR2012b(c4_i21, 1, c4_i15, &c4_bc_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_iInflect[c4_i21 - 1] = c4_kfirst;
          if (c4_previousdir == 'i') {
            c4_nPk++;
            c4_i24 = c4_iPk.size(0);
            c4_d9 = static_cast<real_T>(c4_nPk);
            if (c4_d9 != static_cast<real_T>(static_cast<int32_T>
                 (muDoubleScalarFloor(c4_d9)))) {
              emlrtIntegerCheckR2012b(c4_d9, &c4_sb_emlrtDCI, (emlrtConstCTX)
                c4_sp);
            }

            c4_i26 = static_cast<int32_T>(muDoubleScalarFloor(c4_d9));
            if ((c4_i26 < 1) || (c4_i26 > c4_i24)) {
              emlrtDynamicBoundsCheckR2012b(c4_i26, 1, c4_i24, &c4_cc_emlrtBCI,
                (emlrtConstCTX)c4_sp);
            }

            c4_iPk[c4_i26 - 1] = c4_kfirst;
          }
        }
      } else {
        c4_dir = 'i';
        if (c4_previousdir != 'i') {
          c4_nInflect++;
          c4_i14 = c4_iInflect.size(0);
          c4_d6 = static_cast<real_T>(c4_nInflect);
          if (c4_d6 != static_cast<real_T>(static_cast<int32_T>
               (muDoubleScalarFloor(c4_d6)))) {
            emlrtIntegerCheckR2012b(c4_d6, &c4_qb_emlrtDCI, (emlrtConstCTX)c4_sp);
          }

          c4_i20 = static_cast<int32_T>(muDoubleScalarFloor(c4_d6));
          if ((c4_i20 < 1) || (c4_i20 > c4_i14)) {
            emlrtDynamicBoundsCheckR2012b(c4_i20, 1, c4_i14, &c4_ac_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_iInflect[c4_i20 - 1] = c4_kfirst;
        }
      }

      c4_ykfirst = c4_yk;
      c4_kfirst = c4_k + 1;
      c4_isinfykfirst = c4_isinfyk;
    }
  }

  if (!c4_isinfykfirst) {
    c4_guard1 = false;
    if (c4_nInflect == 0) {
      c4_guard1 = true;
    } else {
      c4_i = c4_iInflect.size(0);
      c4_b_d1 = static_cast<real_T>(c4_nInflect);
      if (c4_b_d1 != static_cast<real_T>(static_cast<int32_T>
           (muDoubleScalarFloor(c4_b_d1)))) {
        emlrtIntegerCheckR2012b(c4_b_d1, &c4_kb_emlrtDCI, (emlrtConstCTX)c4_sp);
      }

      c4_i4 = static_cast<int32_T>(muDoubleScalarFloor(c4_b_d1));
      if ((c4_i4 < 1) || (c4_i4 > c4_i)) {
        emlrtDynamicBoundsCheckR2012b(c4_i4, 1, c4_i, &c4_vb_emlrtBCI,
          (emlrtConstCTX)c4_sp);
      }

      if (c4_iInflect[c4_i4 - 1] < 1200) {
        c4_guard1 = true;
      }
    }

    if (c4_guard1) {
      c4_nInflect++;
      c4_i5 = c4_iInflect.size(0);
      c4_d2 = static_cast<real_T>(c4_nInflect);
      if (c4_d2 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_d2)))) {
        emlrtIntegerCheckR2012b(c4_d2, &c4_mb_emlrtDCI, (emlrtConstCTX)c4_sp);
      }

      c4_i7 = static_cast<int32_T>(muDoubleScalarFloor(c4_d2));
      if ((c4_i7 < 1) || (c4_i7 > c4_i5)) {
        emlrtDynamicBoundsCheckR2012b(c4_i7, 1, c4_i5, &c4_wb_emlrtBCI,
          (emlrtConstCTX)c4_sp);
      }

      c4_iInflect[c4_i7 - 1] = 1200;
    }
  }

  c4_b = (c4_nPk < 1);
  c4_b_b1 = c4_b;
  c4_b2 = false;
  c4_b3 = (c4_b_b1 || c4_b2);
  if (c4_b3) {
    c4_i3 = 1;
    c4_i6 = 0;
  } else {
    c4_i2 = c4_iPk.size(0);
    if (c4_i2 < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, c4_i2, &c4_ob_emlrtBCI, (emlrtConstCTX)
        c4_sp);
    }

    c4_i3 = 1;
    c4_d3 = static_cast<real_T>(c4_nPk);
    if (c4_d3 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d3)))) {
      emlrtIntegerCheckR2012b(c4_d3, &c4_gb_emlrtDCI, (emlrtConstCTX)c4_sp);
    }

    c4_i9 = c4_iPk.size(0);
    if ((static_cast<int32_T>(muDoubleScalarFloor(c4_d3)) < 1) ||
        (static_cast<int32_T>(muDoubleScalarFloor(c4_d3)) > c4_i9)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(muDoubleScalarFloor
        (c4_d3)), 1, c4_i9, &c4_pb_emlrtBCI, (emlrtConstCTX)c4_sp);
    }

    c4_i6 = static_cast<int32_T>(muDoubleScalarFloor(c4_d3));
  }

  c4_b_iPk.set_size(&c4_yb_emlrtRTEI, c4_sp, (c4_i6 - c4_i3) + 1);
  c4_loop_ub = c4_i6 - c4_i3;
  for (c4_i8 = 0; c4_i8 <= c4_loop_ub; c4_i8++) {
    c4_b_iPk[c4_i8] = c4_iPk[(c4_i3 + c4_i8) - 1];
  }

  c4_iPk.set_size(&c4_ac_emlrtRTEI, c4_sp, c4_b_iPk.size(0));
  c4_b_loop_ub = c4_b_iPk.size(0) - 1;
  for (c4_i11 = 0; c4_i11 <= c4_b_loop_ub; c4_i11++) {
    c4_iPk[c4_i11] = c4_b_iPk[c4_i11];
  }

  c4_b4 = (c4_nInf < 1);
  c4_b5 = c4_b4;
  c4_b6 = false;
  c4_b7 = (c4_b5 || c4_b6);
  if (c4_b7) {
    c4_i17 = 1;
    c4_i19 = 0;
  } else {
    c4_i16 = c4_iInf.size(0);
    if (c4_i16 < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, c4_i16, &c4_qb_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_i17 = 1;
    c4_d8 = static_cast<real_T>(c4_nInf);
    if (c4_d8 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d8)))) {
      emlrtIntegerCheckR2012b(c4_d8, &c4_hb_emlrtDCI, (emlrtConstCTX)c4_sp);
    }

    c4_i23 = c4_iInf.size(0);
    if ((static_cast<int32_T>(muDoubleScalarFloor(c4_d8)) < 1) ||
        (static_cast<int32_T>(muDoubleScalarFloor(c4_d8)) > c4_i23)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(muDoubleScalarFloor
        (c4_d8)), 1, c4_i23, &c4_rb_emlrtBCI, (emlrtConstCTX)c4_sp);
    }

    c4_i19 = static_cast<int32_T>(muDoubleScalarFloor(c4_d8));
  }

  c4_b_iInf.set_size(&c4_yb_emlrtRTEI, c4_sp, (c4_i19 - c4_i17) + 1);
  c4_c_loop_ub = c4_i19 - c4_i17;
  for (c4_i22 = 0; c4_i22 <= c4_c_loop_ub; c4_i22++) {
    c4_b_iInf[c4_i22] = c4_iInf[(c4_i17 + c4_i22) - 1];
  }

  c4_iInf.set_size(&c4_bc_emlrtRTEI, c4_sp, c4_b_iInf.size(0));
  c4_d_loop_ub = c4_b_iInf.size(0) - 1;
  for (c4_i25 = 0; c4_i25 <= c4_d_loop_ub; c4_i25++) {
    c4_iInf[c4_i25] = c4_b_iInf[c4_i25];
  }

  c4_b_b8 = (c4_nInflect < 1);
  c4_b9 = c4_b_b8;
  c4_b10 = false;
  c4_b_b11 = (c4_b9 || c4_b10);
  if (c4_b_b11) {
    c4_i28 = 1;
    c4_i29 = 0;
  } else {
    c4_i27 = c4_iInflect.size(0);
    if (c4_i27 < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, c4_i27, &c4_sb_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_i28 = 1;
    c4_d10 = static_cast<real_T>(c4_nInflect);
    if (c4_d10 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d10)))) {
      emlrtIntegerCheckR2012b(c4_d10, &c4_ib_emlrtDCI, (emlrtConstCTX)c4_sp);
    }

    c4_i31 = c4_iInflect.size(0);
    if ((static_cast<int32_T>(muDoubleScalarFloor(c4_d10)) < 1) || (static_cast<
         int32_T>(muDoubleScalarFloor(c4_d10)) > c4_i31)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(muDoubleScalarFloor
        (c4_d10)), 1, c4_i31, &c4_tb_emlrtBCI, (emlrtConstCTX)c4_sp);
    }

    c4_i29 = static_cast<int32_T>(muDoubleScalarFloor(c4_d10));
  }

  c4_b_iInflect.set_size(&c4_yb_emlrtRTEI, c4_sp, (c4_i29 - c4_i28) + 1);
  c4_e_loop_ub = c4_i29 - c4_i28;
  for (c4_i30 = 0; c4_i30 <= c4_e_loop_ub; c4_i30++) {
    c4_b_iInflect[c4_i30] = c4_iInflect[(c4_i28 + c4_i30) - 1];
  }

  c4_iInflect.set_size(&c4_cc_emlrtRTEI, c4_sp, c4_b_iInflect.size(0));
  c4_f_loop_ub = c4_b_iInflect.size(0) - 1;
  for (c4_i32 = 0; c4_i32 <= c4_f_loop_ub; c4_i32++) {
    c4_iInflect[c4_i32] = c4_b_iInflect[c4_i32];
  }
}

static void c4_check_forloop_overflow_error(SFc4_LKASInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_overflow)
{
  static char_T c4_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c4_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  if (c4_overflow) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(c4_sp, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14, sf_mex_call
                (c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c4_sp, NULL,
      "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }
}

static void c4_do_vectors(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<int32_T, 1U> &c4_a, coder::array<int32_T, 1U>
  &c4_b, coder::array<int32_T, 1U> &c4_c, coder::array<int32_T, 1U> &c4_ia,
  coder::array<int32_T, 1U> &c4_b_ib)
{
  static char_T c4_b_cv[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u',
    'n', 's', 'o', 'r', 't', 'e', 'd', 'A' };

  static char_T c4_b_cv1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_',
    'u', 'n', 's', 'o', 'r', 't', 'e', 'd', 'B' };

  coder::array<int32_T, 1U> c4_b_ia;
  coder::array<int32_T, 1U> c4_c_ib;
  coder::array<int32_T, 1U> c4_f_c;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_d1;
  real_T c4_d;
  real_T c4_d2;
  real_T c4_d3;
  int32_T c4_iv[2];
  int32_T c4_ab_a;
  int32_T c4_ak;
  int32_T c4_b_a;
  int32_T c4_b_ak;
  int32_T c4_b_b;
  int32_T c4_b_bk;
  int32_T c4_b_c;
  int32_T c4_b_ialast;
  int32_T c4_b_iblast;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_na;
  int32_T c4_b_nb;
  int32_T c4_b_nx;
  int32_T c4_b_xkplus;
  int32_T c4_bb_a;
  int32_T c4_c_a;
  int32_T c4_c_bk;
  int32_T c4_c_c;
  int32_T c4_c_ialast;
  int32_T c4_c_iblast;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_nx;
  int32_T c4_c_xkplus;
  int32_T c4_cb_a;
  int32_T c4_d_a;
  int32_T c4_d_c;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_d_nx;
  int32_T c4_d_xkplus;
  int32_T c4_db_a;
  int32_T c4_e_a;
  int32_T c4_e_b;
  int32_T c4_e_c;
  int32_T c4_e_loop_ub;
  int32_T c4_e_nx;
  int32_T c4_eb_a;
  int32_T c4_f_a;
  int32_T c4_f_b;
  int32_T c4_f_loop_ub;
  int32_T c4_fb_a;
  int32_T c4_g_a;
  int32_T c4_g_b;
  int32_T c4_gb_a;
  int32_T c4_h_a;
  int32_T c4_h_b;
  int32_T c4_hb_a;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_iafirst;
  int32_T c4_ialast;
  int32_T c4_ib_a;
  int32_T c4_ibfirst;
  int32_T c4_iblast;
  int32_T c4_j_a;
  int32_T c4_j_b;
  int32_T c4_jb_a;
  int32_T c4_k;
  int32_T c4_k_a;
  int32_T c4_k_b;
  int32_T c4_kb_a;
  int32_T c4_loop_ub;
  int32_T c4_m_a;
  int32_T c4_m_b;
  int32_T c4_nc;
  int32_T c4_ncmax;
  int32_T c4_nia;
  int32_T c4_nib;
  int32_T c4_o_a;
  int32_T c4_p_a;
  int32_T c4_q_a;
  int32_T c4_r_a;
  int32_T c4_s_a;
  int32_T c4_t_a;
  int32_T c4_u_a;
  int32_T c4_v_a;
  int32_T c4_w_a;
  int32_T c4_x_a;
  int32_T c4_xkplus;
  int32_T c4_y_a;
  boolean_T c4_b10;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b9;
  boolean_T c4_b_b1;
  boolean_T c4_b_b11;
  boolean_T c4_b_b8;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_d_p;
  boolean_T c4_e_p;
  boolean_T c4_exitg1;
  boolean_T c4_f_p;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_na = c4_a.size(0);
  c4_b_nb = c4_b.size(0);
  c4_b_a = c4_b_na;
  c4_b_b = c4_b_nb;
  c4_ncmax = c4_b_a + c4_b_b;
  c4_d = static_cast<real_T>(c4_ncmax);
  if (!(c4_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d, &c4_tb_emlrtDCI, (emlrtConstCTX)c4_sp);
  }

  c4_iv[0] = static_cast<int32_T>(muDoubleScalarFloor(c4_d));
  c4_b_d1 = 1.0;
  if (!(c4_b_d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_b_d1, &c4_tb_emlrtDCI, (emlrtConstCTX)c4_sp);
  }

  c4_c.set_size(&c4_dc_emlrtRTEI, c4_sp, c4_iv[0]);
  c4_d2 = static_cast<real_T>(c4_b_na);
  if (!(c4_d2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d2, &c4_ub_emlrtDCI, (emlrtConstCTX)c4_sp);
  }

  c4_ia.set_size(&c4_ec_emlrtRTEI, c4_sp, static_cast<int32_T>
                 (muDoubleScalarFloor(c4_d2)));
  c4_d3 = static_cast<real_T>(c4_b_nb);
  if (!(c4_d3 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d3, &c4_vb_emlrtDCI, (emlrtConstCTX)c4_sp);
  }

  c4_b_ib.set_size(&c4_fc_emlrtRTEI, c4_sp, static_cast<int32_T>
                   (muDoubleScalarFloor(c4_d3)));
  c4_st.site = &c4_p_emlrtRSI;
  if (!c4_issorted(chartInstance, &c4_st, c4_a)) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c4_sp, &c4_b_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }

  c4_st.site = &c4_q_emlrtRSI;
  if (!c4_issorted(chartInstance, &c4_st, c4_b)) {
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c4_sp, &c4_c_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_d_y)));
  }

  c4_nc = -1;
  c4_nia = -1;
  c4_nib = 0;
  c4_iafirst = 1;
  c4_ialast = 1;
  c4_ibfirst = 1;
  c4_iblast = 1;
  while ((c4_ialast <= c4_b_na) && (c4_iblast <= c4_b_nb)) {
    c4_k = c4_ialast;
    c4_b_ialast = c4_k;
    c4_b_nx = c4_a.size(0);
    c4_ak = c4_a[c4_b_ialast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_b_ialast < c4_b_nx)) {
      c4_c_a = c4_b_ialast + 1;
      c4_b_c = c4_c_a - 1;
      c4_xkplus = c4_a[c4_b_c];
      c4_f_a = c4_xkplus;
      c4_e_b = c4_ak;
      c4_p = (c4_f_a == c4_e_b);
      if (c4_p) {
        c4_p_a = c4_b_ialast + 1;
        c4_b_ialast = c4_p_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_ialast = c4_b_ialast;
    c4_d_k = c4_iblast;
    c4_c_iblast = c4_d_k;
    c4_e_nx = c4_b.size(0);
    c4_c_bk = c4_b[c4_c_iblast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_c_iblast < c4_e_nx)) {
      c4_r_a = c4_c_iblast + 1;
      c4_e_c = c4_r_a - 1;
      c4_d_xkplus = c4_b[c4_e_c];
      c4_w_a = c4_d_xkplus;
      c4_j_b = c4_c_bk;
      c4_e_p = (c4_w_a == c4_j_b);
      if (c4_e_p) {
        c4_bb_a = c4_c_iblast + 1;
        c4_c_iblast = c4_bb_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_iblast = c4_c_iblast;
    c4_t_a = c4_ak;
    c4_h_b = c4_c_bk;
    c4_d_p = (c4_t_a == c4_h_b);
    if (c4_d_p) {
      c4_y_a = c4_nc + 1;
      c4_nc = c4_y_a;
      c4_c[c4_nc] = c4_ak;
      c4_cb_a = c4_nia + 1;
      c4_nia = c4_cb_a;
      c4_ia[c4_nia] = c4_iafirst;
      c4_fb_a = c4_b_ialast + 1;
      c4_ialast = c4_fb_a;
      c4_iafirst = c4_ialast;
      c4_ib_a = c4_c_iblast + 1;
      c4_iblast = c4_ib_a;
      c4_ibfirst = c4_iblast;
    } else {
      c4_x_a = c4_ak;
      c4_k_b = c4_c_bk;
      c4_ab_a = c4_x_a;
      c4_m_b = c4_k_b;
      c4_f_p = (c4_ab_a < c4_m_b);
      if (c4_f_p) {
        c4_eb_a = c4_nc + 1;
        c4_nc = c4_eb_a;
        c4_hb_a = c4_nia + 1;
        c4_nia = c4_hb_a;
        c4_c[c4_nc] = c4_ak;
        c4_ia[c4_nia] = c4_iafirst;
        c4_kb_a = c4_b_ialast + 1;
        c4_ialast = c4_kb_a;
        c4_iafirst = c4_ialast;
      } else {
        c4_db_a = c4_nc + 1;
        c4_nc = c4_db_a;
        c4_gb_a = c4_nib + 1;
        c4_nib = c4_gb_a;
        c4_c[c4_nc] = c4_c_bk;
        c4_b_ib[c4_nib - 1] = c4_ibfirst;
        c4_jb_a = c4_c_iblast + 1;
        c4_iblast = c4_jb_a;
        c4_ibfirst = c4_iblast;
      }
    }
  }

  while (c4_ialast <= c4_b_na) {
    c4_b_k = c4_ialast;
    c4_c_ialast = c4_b_k;
    c4_c_nx = c4_a.size(0);
    c4_b_ak = c4_a[c4_c_ialast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_c_ialast < c4_c_nx)) {
      c4_e_a = c4_c_ialast + 1;
      c4_c_c = c4_e_a - 1;
      c4_b_xkplus = c4_a[c4_c_c];
      c4_k_a = c4_b_xkplus;
      c4_f_b = c4_b_ak;
      c4_b_p = (c4_k_a == c4_f_b);
      if (c4_b_p) {
        c4_s_a = c4_c_ialast + 1;
        c4_c_ialast = c4_s_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_d_a = c4_nc + 1;
    c4_nc = c4_d_a;
    c4_j_a = c4_nia + 1;
    c4_nia = c4_j_a;
    c4_c[c4_nc] = c4_b_ak;
    c4_ia[c4_nia] = c4_iafirst;
    c4_q_a = c4_c_ialast + 1;
    c4_ialast = c4_q_a;
    c4_iafirst = c4_ialast;
  }

  while (c4_iblast <= c4_b_nb) {
    c4_c_k = c4_iblast;
    c4_b_iblast = c4_c_k;
    c4_d_nx = c4_b.size(0);
    c4_b_bk = c4_b[c4_b_iblast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_b_iblast < c4_d_nx)) {
      c4_h_a = c4_b_iblast + 1;
      c4_d_c = c4_h_a - 1;
      c4_c_xkplus = c4_b[c4_d_c];
      c4_o_a = c4_c_xkplus;
      c4_g_b = c4_b_bk;
      c4_c_p = (c4_o_a == c4_g_b);
      if (c4_c_p) {
        c4_v_a = c4_b_iblast + 1;
        c4_b_iblast = c4_v_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_g_a = c4_nc + 1;
    c4_nc = c4_g_a;
    c4_m_a = c4_nib + 1;
    c4_nib = c4_m_a;
    c4_c[c4_nc] = c4_b_bk;
    c4_b_ib[c4_nib - 1] = c4_ibfirst;
    c4_u_a = c4_b_iblast + 1;
    c4_iblast = c4_u_a;
    c4_ibfirst = c4_iblast;
  }

  if (c4_b_na > 0) {
    if (!(c4_nia + 1 <= c4_b_na)) {
      c4_e_y = NULL;
      sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c4_g_y = NULL;
      sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c4_sp, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_e_y, 14,
                  sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c4_sp, NULL, "message", 1U, 1U, 14, c4_g_y)));
    }

    c4_c_b = (c4_nia + 1 < 1);
    c4_b_b1 = c4_c_b;
    c4_b3 = false;
    c4_b5 = (c4_b_b1 || c4_b3);
    if (c4_b5) {
      c4_i = 1;
      c4_i1 = 0;
    } else {
      c4_i = 1;
      c4_i1 = c4_nia + 1;
    }

    c4_b_ia.set_size(&c4_gc_emlrtRTEI, c4_sp, (c4_i1 - c4_i) + 1);
    c4_loop_ub = c4_i1 - c4_i;
    for (c4_i6 = 0; c4_i6 <= c4_loop_ub; c4_i6++) {
      c4_b_ia[c4_i6] = c4_ia[(c4_i + c4_i6) - 1];
    }

    c4_ia.set_size(&c4_hc_emlrtRTEI, c4_sp, c4_b_ia.size(0));
    c4_d_loop_ub = c4_b_ia.size(0) - 1;
    for (c4_i9 = 0; c4_i9 <= c4_d_loop_ub; c4_i9++) {
      c4_ia[c4_i9] = c4_b_ia[c4_i9];
    }
  }

  if (c4_b_nb > 0) {
    if (!(c4_nib <= c4_b_nb)) {
      c4_f_y = NULL;
      sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c4_j_y = NULL;
      sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c4_sp, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_f_y, 14,
                  sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c4_sp, NULL, "message", 1U, 1U, 14, c4_j_y)));
    }

    c4_b2 = (c4_nib < 1);
    c4_b4 = c4_b2;
    c4_b7 = false;
    c4_b9 = (c4_b4 || c4_b7);
    if (c4_b9) {
      c4_i2 = 1;
      c4_i3 = 0;
    } else {
      c4_i2 = 1;
      c4_i3 = c4_nib;
    }

    c4_c_ib.set_size(&c4_gc_emlrtRTEI, c4_sp, (c4_i3 - c4_i2) + 1);
    c4_b_loop_ub = c4_i3 - c4_i2;
    for (c4_i7 = 0; c4_i7 <= c4_b_loop_ub; c4_i7++) {
      c4_c_ib[c4_i7] = c4_b_ib[(c4_i2 + c4_i7) - 1];
    }

    c4_b_ib.set_size(&c4_ic_emlrtRTEI, c4_sp, c4_c_ib.size(0));
    c4_e_loop_ub = c4_c_ib.size(0) - 1;
    for (c4_i10 = 0; c4_i10 <= c4_e_loop_ub; c4_i10++) {
      c4_b_ib[c4_i10] = c4_c_ib[c4_i10];
    }
  }

  if (c4_ncmax > 0) {
    if (!(c4_nc + 1 <= c4_ncmax)) {
      c4_h_y = NULL;
      sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c4_k_y = NULL;
      sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c4_sp, &c4_f_emlrtMCI, "error", 0U, 2U, 14, c4_h_y, 14,
                  sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c4_sp, NULL, "message", 1U, 1U, 14, c4_k_y)));
    }

    c4_b6 = (c4_nc + 1 < 1);
    c4_b_b8 = c4_b6;
    c4_b10 = false;
    c4_b_b11 = (c4_b_b8 || c4_b10);
    if (c4_b_b11) {
      c4_i4 = 1;
      c4_i5 = 0;
    } else {
      c4_i4 = 1;
      c4_i5 = c4_nc + 1;
    }

    c4_f_c.set_size(&c4_gc_emlrtRTEI, c4_sp, (c4_i5 - c4_i4) + 1);
    c4_c_loop_ub = c4_i5 - c4_i4;
    for (c4_i8 = 0; c4_i8 <= c4_c_loop_ub; c4_i8++) {
      c4_f_c[c4_i8] = c4_c[(c4_i4 + c4_i8) - 1];
    }

    c4_c.set_size(&c4_jc_emlrtRTEI, c4_sp, c4_f_c.size(0));
    c4_f_loop_ub = c4_f_c.size(0) - 1;
    for (c4_i11 = 0; c4_i11 <= c4_f_loop_ub; c4_i11++) {
      c4_c[c4_i11] = c4_f_c[c4_i11];
    }
  }
}

static boolean_T c4_issorted(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<int32_T, 1U> &c4_b_x)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  real_T c4_b_d1;
  real_T c4_d;
  real_T c4_d2;
  int32_T c4_subs[2];
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_dim;
  int32_T c4_b_k;
  int32_T c4_b_n;
  int32_T c4_b_nx;
  int32_T c4_b_varargin_1;
  int32_T c4_c_b;
  int32_T c4_c_dim;
  int32_T c4_c_k;
  int32_T c4_d_dim;
  int32_T c4_d_k;
  int32_T c4_dim;
  int32_T c4_e_b;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_k;
  int32_T c4_n;
  int32_T c4_varargin_1;
  int32_T c4_varargin_2;
  int32_T c4_x1;
  int32_T c4_x2;
  boolean_T c4_b_overflow;
  boolean_T c4_exitg1;
  boolean_T c4_exitg2;
  boolean_T c4_h_b;
  boolean_T c4_overflow;
  boolean_T c4_y;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_y = true;
  c4_dim = 2;
  if (static_cast<real_T>(c4_b_x.size(0)) != 1.0) {
    c4_dim = 1;
  }

  if (c4_dim <= 1) {
    c4_d = static_cast<real_T>(c4_b_x.size(c4_dim - 1));
  } else {
    c4_d = 1.0;
  }

  c4_b_nx = static_cast<int32_T>(c4_d);
  if ((c4_b_x.size(0) == 0) || (c4_b_nx == 1)) {
  } else {
    c4_st.site = &c4_r_emlrtRSI;
    c4_b_dim = c4_dim;
    if (c4_b_dim == 2) {
      if (c4_b_dim <= 1) {
        c4_b_d1 = static_cast<real_T>(c4_b_x.size(c4_b_dim - 1));
      } else {
        c4_b_d1 = 1.0;
      }

      c4_n = static_cast<int32_T>(c4_b_d1) - 2;
    } else {
      c4_n = 0;
    }

    c4_b_st.site = &c4_s_emlrtRSI;
    c4_b = c4_n + 1;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_i_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st, c4_overflow);
    }

    c4_k = 1;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k - 1 <= c4_n)) {
      c4_b_k = c4_k;
      c4_b_st.site = &c4_t_emlrtRSI;
      c4_c_dim = c4_b_dim;
      c4_varargin_1 = c4_b_k;
      if (c4_c_dim == 1) {
        if (c4_c_dim <= 1) {
          c4_d2 = static_cast<real_T>(c4_b_x.size(c4_c_dim - 1));
        } else {
          c4_d2 = 1.0;
        }

        c4_b_n = static_cast<int32_T>(c4_d2) - 1;
      } else {
        c4_b_n = c4_b_x.size(0);
      }

      c4_c_st.site = &c4_s_emlrtRSI;
      c4_c_b = c4_b_n;
      c4_e_b = c4_c_b;
      if (c4_e_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_e_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_d_st.site = &c4_i_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_d_st, c4_b_overflow);
      }

      c4_c_k = 1;
      c4_exitg2 = false;
      while ((!c4_exitg2) && (c4_c_k - 1 <= c4_b_n - 1)) {
        c4_d_k = c4_c_k;
        c4_d_dim = c4_c_dim - 1;
        c4_b_varargin_1 = c4_d_k;
        c4_varargin_2 = c4_varargin_1;
        c4_x1 = c4_b_x[c4_b_varargin_1 - 1];
        c4_subs[0] = c4_b_varargin_1;
        c4_subs[1] = c4_varargin_2;
        c4_subs[c4_d_dim]++;
        c4_x2 = c4_b_x[c4_subs[0] - 1];
        c4_subs[0] = c4_x1;
        c4_subs[1] = c4_x2;
        c4_a = c4_subs[0];
        c4_f_b = c4_subs[1];
        c4_b_a = c4_a;
        c4_g_b = c4_f_b;
        c4_h_b = (c4_b_a <= c4_g_b);
        c4_y = (c4_y && c4_h_b);
        if (!c4_y) {
          c4_exitg2 = true;
        } else {
          c4_c_k++;
        }
      }

      if (!c4_y) {
        c4_exitg1 = true;
      } else {
        c4_k++;
      }
    }
  }

  return c4_y;
}

static void c4_indexShapeCheck(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_matrixSize)
{
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_size1;
  boolean_T c4_b;
  boolean_T c4_b_c;
  boolean_T c4_c;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_size1 = c4_matrixSize;
  if (c4_size1 != 1) {
    c4_b = false;
  } else {
    c4_b = true;
  }

  if (c4_b) {
    c4_c = true;
  } else {
    c4_c = false;
  }

  c4_st.site = &c4_eb_emlrtRSI;
  c4_b_c = c4_c;
  if (c4_b_c) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c4_st, &c4_k_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }
}

static void c4_b_indexShapeCheck(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T c4_indexSize[2])
{
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_size1;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_c;
  boolean_T c4_c;
  boolean_T c4_nonSingletonDimFound;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_size1 = c4_matrixSize;
  if (c4_size1 != 1) {
    c4_b = false;
  } else {
    c4_b = true;
  }

  if (c4_b) {
    c4_nonSingletonDimFound = false;
    if (c4_indexSize[1] != 1) {
      c4_nonSingletonDimFound = true;
    }

    c4_b_b = c4_nonSingletonDimFound;
    if (c4_b_b) {
      c4_c = true;
    } else {
      c4_c = false;
    }
  } else {
    c4_c = false;
  }

  c4_st.site = &c4_eb_emlrtRSI;
  c4_b_c = c4_c;
  if (c4_b_c) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c4_st, &c4_k_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }
}

static void c4_eml_find(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack
  *c4_sp, boolean_T c4_b_x[900000], coder::array<int32_T, 1U> &c4_i, coder::
  array<int32_T, 1U> &c4_j)
{
  coder::array<int32_T, 1U> c4_b_j;
  coder::array<int32_T, 1U> c4_c_i;
  coder::array<boolean_T, 1U> c4_v;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_iv[2];
  int32_T c4_iv1[2];
  int32_T c4_iv2[2];
  int32_T c4_b_i;
  int32_T c4_b_ii;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_idx;
  int32_T c4_jj;
  int32_T c4_loop_ub;
  boolean_T c4_b;
  boolean_T c4_b10;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b9;
  boolean_T c4_b_b1;
  boolean_T c4_b_b11;
  boolean_T c4_b_b8;
  boolean_T c4_exitg1;
  boolean_T c4_guard1;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_gb_emlrtRSI;
  c4_idx = 0;
  c4_i.set_size(&c4_kc_emlrtRTEI, &c4_st, 900000);
  c4_j.set_size(&c4_mc_emlrtRTEI, &c4_st, 900000);
  c4_v.set_size(&c4_oc_emlrtRTEI, &c4_st, 900000);
  c4_b_ii = 0;
  c4_jj = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_jj + 1 <= 1200)) {
    c4_guard1 = false;
    if (c4_b_x[c4_b_ii + 750 * c4_jj]) {
      c4_idx++;
      c4_i[c4_idx - 1] = c4_b_ii + 1;
      c4_j[c4_idx - 1] = c4_jj + 1;
      c4_v[c4_idx - 1] = c4_b_x[c4_b_ii + 750 * c4_jj];
      if (c4_idx >= 900000) {
        c4_exitg1 = true;
      } else {
        c4_guard1 = true;
      }
    } else {
      c4_guard1 = true;
    }

    if (c4_guard1) {
      c4_b_ii++;
      if (c4_b_ii + 1 > 750) {
        c4_b_ii = 0;
        c4_jj++;
      }
    }
  }

  if (!(c4_idx <= 900000)) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c4_st, &c4_m_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }

  c4_b = (c4_idx < 1);
  c4_b_b1 = c4_b;
  c4_b2 = false;
  c4_b3 = (c4_b_b1 || c4_b2);
  if (c4_b3) {
    c4_b_i = 0;
    c4_i1 = 0;
  } else {
    c4_b_i = 0;
    c4_i1 = c4_idx;
  }

  c4_iv[0] = 1;
  c4_iv[1] = c4_i1 - c4_b_i;
  c4_b_st.site = &c4_hb_emlrtRSI;
  c4_b_indexShapeCheck(chartInstance, &c4_b_st, c4_i.size(0), c4_iv);
  c4_i2 = c4_b_i + 1;
  c4_c_i.set_size(&c4_pc_emlrtRTEI, &c4_st, (c4_i1 - c4_i2) + 1);
  c4_loop_ub = c4_i1 - c4_i2;
  for (c4_i3 = 0; c4_i3 <= c4_loop_ub; c4_i3++) {
    c4_c_i[c4_i3] = c4_i[(c4_i2 + c4_i3) - 1];
  }

  c4_i.set_size(&c4_qc_emlrtRTEI, &c4_st, c4_c_i.size(0));
  c4_b_loop_ub = c4_c_i.size(0) - 1;
  for (c4_i4 = 0; c4_i4 <= c4_b_loop_ub; c4_i4++) {
    c4_i[c4_i4] = c4_c_i[c4_i4];
  }

  c4_b4 = (c4_idx < 1);
  c4_b5 = c4_b4;
  c4_b6 = false;
  c4_b7 = (c4_b5 || c4_b6);
  if (c4_b7) {
    c4_i5 = 0;
    c4_i6 = 0;
  } else {
    c4_i5 = 0;
    c4_i6 = c4_idx;
  }

  c4_iv1[0] = 1;
  c4_iv1[1] = c4_i6 - c4_i5;
  c4_b_st.site = &c4_ib_emlrtRSI;
  c4_b_indexShapeCheck(chartInstance, &c4_b_st, c4_j.size(0), c4_iv1);
  c4_i7 = c4_i5 + 1;
  c4_b_j.set_size(&c4_rc_emlrtRTEI, &c4_st, (c4_i6 - c4_i7) + 1);
  c4_c_loop_ub = c4_i6 - c4_i7;
  for (c4_i8 = 0; c4_i8 <= c4_c_loop_ub; c4_i8++) {
    c4_b_j[c4_i8] = c4_j[(c4_i7 + c4_i8) - 1];
  }

  c4_j.set_size(&c4_sc_emlrtRTEI, &c4_st, c4_b_j.size(0));
  c4_d_loop_ub = c4_b_j.size(0) - 1;
  for (c4_i9 = 0; c4_i9 <= c4_d_loop_ub; c4_i9++) {
    c4_j[c4_i9] = c4_b_j[c4_i9];
  }

  c4_b_b8 = (c4_idx < 1);
  c4_b9 = c4_b_b8;
  c4_b10 = false;
  c4_b_b11 = (c4_b9 || c4_b10);
  if (c4_b_b11) {
    c4_i10 = 0;
    c4_i11 = 0;
  } else {
    c4_i10 = 0;
    c4_i11 = c4_idx;
  }

  c4_iv2[0] = 1;
  c4_iv2[1] = c4_i11 - c4_i10;
  c4_b_st.site = &c4_jb_emlrtRSI;
  c4_b_indexShapeCheck(chartInstance, &c4_b_st, c4_v.size(0), c4_iv2);
}

static real_T c4_mean(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack
                      *c4_sp, coder::array<real_T, 1U> &c4_b_x)
{
  static char_T c4_b_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  real_T c4_d_y;
  real_T c4_s;
  int32_T c4_a;
  int32_T c4_b_b;
  int32_T c4_b_ib;
  int32_T c4_b_vlen;
  int32_T c4_c_b;
  int32_T c4_c_vlen;
  int32_T c4_d_vlen;
  int32_T c4_inb;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  int32_T c4_vlen;
  boolean_T c4_b;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  if ((c4_b_x.size(0) == 1) || (static_cast<real_T>(c4_b_x.size(0)) != 1.0)) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(c4_sp, &c4_o_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  c4_st.site = &c4_kb_emlrtRSI;
  c4_vlen = c4_b_x.size(0);
  c4_b_st.site = &c4_mb_emlrtRSI;
  c4_b_vlen = c4_vlen;
  if ((c4_b_x.size(0) == 0) || (c4_b_vlen == 0)) {
    c4_d_y = 0.0;
  } else {
    c4_c_st.site = &c4_ob_emlrtRSI;
    c4_c_vlen = c4_b_vlen;
    c4_d_st.site = &c4_pb_emlrtRSI;
    c4_d_vlen = c4_c_vlen;
    if (c4_d_vlen < 4096) {
      c4_e_st.site = &c4_sb_emlrtRSI;
      c4_d_y = c4_sumColumnB(chartInstance, &c4_e_st, c4_b_x, c4_d_vlen);
    } else {
      c4_a = c4_d_vlen;
      c4_nfb = c4_div_nzp_s32(chartInstance, c4_a, 4096, 0, 0U, 0, 0);
      c4_inb = c4_nfb << 12;
      c4_lidx = c4_inb;
      c4_nleft = c4_d_vlen - c4_inb;
      c4_s = c4_sumColumnB4(chartInstance, c4_b_x, 1, 1);
      c4_e_st.site = &c4_qb_emlrtRSI;
      c4_b_b = c4_nfb;
      c4_c_b = c4_b_b;
      if (c4_c_b < 2) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_c_b > 2147483646);
      }

      if (c4_overflow) {
        c4_f_st.site = &c4_i_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_f_st, c4_overflow);
      }

      for (c4_b_ib = 2; c4_b_ib <= c4_nfb; c4_b_ib++) {
        c4_s += c4_sumColumnB4(chartInstance, c4_b_x, 1, 1 + ((c4_b_ib - 1) <<
          12));
      }

      if (c4_nleft > 0) {
        c4_e_st.site = &c4_rb_emlrtRSI;
        c4_s += c4_b_sumColumnB(chartInstance, &c4_e_st, c4_b_x, c4_nleft,
          c4_lidx + 1);
      }

      c4_d_y = c4_s;
    }
  }

  return c4_d_y / static_cast<real_T>(c4_b_x.size(0));
}

static real_T c4_sumColumnB(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<real_T, 1U> &c4_b_x, int32_T c4_vlen)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_b_y;
  real_T c4_c_y;
  real_T c4_y;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_vlen;
  int32_T c4_b_vstart;
  int32_T c4_c_b;
  int32_T c4_c_i0;
  int32_T c4_c_k;
  int32_T c4_c_vlen;
  int32_T c4_d_k;
  int32_T c4_e_b;
  int32_T c4_e_i0;
  int32_T c4_e_k;
  int32_T c4_f_b;
  int32_T c4_f_i0;
  int32_T c4_f_k;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i0;
  int32_T c4_i1;
  int32_T c4_i_k;
  int32_T c4_inb;
  int32_T c4_k;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  int32_T c4_vstart;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (c4_vlen <= 1024) {
    c4_st.site = &c4_vb_emlrtRSI;
    c4_b_vlen = c4_vlen - 1;
    c4_i0 = 0;
    c4_y = c4_b_x[c4_i0];
    c4_i = c4_b_vlen;
    c4_b_st.site = &c4_wb_emlrtRSI;
    c4_b = c4_i;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_i_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st, c4_overflow);
    }

    for (c4_c_k = 0; c4_c_k < c4_i; c4_c_k++) {
      c4_e_k = c4_c_k;
      c4_y += c4_b_x[(c4_i0 + c4_e_k) + 1];
    }
  } else {
    c4_a = c4_vlen;
    c4_nfb = c4_div_nzp_s32(chartInstance, c4_a, 1024, 0, 0U, 0, 0);
    c4_inb = c4_nfb << 10;
    c4_c_i0 = 0;
    c4_y = c4_b_x[c4_c_i0];
    for (c4_k = 0; c4_k < 1023; c4_k++) {
      c4_b_k = c4_k;
      c4_y += c4_b_x[(c4_c_i0 + c4_b_k) + 1];
    }

    c4_st.site = &c4_tb_emlrtRSI;
    c4_c_b = c4_nfb;
    c4_e_b = c4_c_b;
    if (c4_e_b < 2) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_e_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_b_st.site = &c4_i_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st, c4_b_overflow);
    }

    for (c4_d_k = 2; c4_d_k <= c4_nfb; c4_d_k++) {
      c4_vstart = (c4_d_k - 1) << 10;
      c4_e_i0 = c4_vstart;
      c4_b_y = c4_b_x[c4_e_i0];
      for (c4_f_k = 0; c4_f_k < 1023; c4_f_k++) {
        c4_g_k = c4_f_k;
        c4_b_y += c4_b_x[(c4_e_i0 + c4_g_k) + 1];
      }

      c4_y += c4_b_y;
    }

    if (c4_vlen > c4_inb) {
      c4_nleft = c4_vlen - c4_inb;
      c4_lidx = c4_inb;
      c4_st.site = &c4_ub_emlrtRSI;
      c4_c_vlen = c4_nleft - 1;
      c4_b_vstart = c4_lidx + 1;
      c4_f_i0 = c4_b_vstart - 1;
      c4_c_y = c4_b_x[c4_f_i0];
      c4_i1 = c4_c_vlen;
      c4_b_st.site = &c4_wb_emlrtRSI;
      c4_f_b = c4_i1;
      c4_g_b = c4_f_b;
      if (c4_g_b < 1) {
        c4_c_overflow = false;
      } else {
        c4_c_overflow = (c4_g_b > 2147483646);
      }

      if (c4_c_overflow) {
        c4_c_st.site = &c4_i_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st, c4_c_overflow);
      }

      for (c4_h_k = 0; c4_h_k < c4_i1; c4_h_k++) {
        c4_i_k = c4_h_k;
        c4_c_y += c4_b_x[(c4_f_i0 + c4_i_k) + 1];
      }

      c4_y += c4_c_y;
    }
  }

  return c4_y;
}

static real_T c4_sumColumnB4(SFc4_LKASInstanceStruct *chartInstance, coder::
  array<real_T, 1U> &c4_b_x, int32_T c4_col, int32_T c4_vstart)
{
  real_T c4_psum1;
  real_T c4_psum2;
  real_T c4_psum3;
  real_T c4_psum4;
  int32_T c4_b_k;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_k;
  c4_i1 = (c4_vstart + (c4_col - 1) * c4_b_x.size(0)) - 1;
  c4_i2 = c4_i1 + 1024;
  c4_i3 = c4_i1 + 2048;
  c4_i4 = c4_i1 + 3072;
  c4_psum1 = c4_b_x[c4_i1];
  c4_psum2 = c4_b_x[c4_i2];
  c4_psum3 = c4_b_x[c4_i3];
  c4_psum4 = c4_b_x[c4_i4];
  for (c4_k = 0; c4_k < 1023; c4_k++) {
    c4_b_k = 1 + c4_k;
    c4_psum1 += c4_b_x[c4_i1 + c4_b_k];
    c4_psum2 += c4_b_x[c4_i2 + c4_b_k];
    c4_psum3 += c4_b_x[c4_i3 + c4_b_k];
    c4_psum4 += c4_b_x[c4_i4 + c4_b_k];
  }

  return (c4_psum1 + c4_psum2) + (c4_psum3 + c4_psum4);
}

static real_T c4_b_sumColumnB(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<real_T, 1U> &c4_b_x, int32_T c4_vlen, int32_T
  c4_vstart)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_b_y;
  real_T c4_c_y;
  real_T c4_y;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_vlen;
  int32_T c4_b_vstart;
  int32_T c4_c_b;
  int32_T c4_c_i0;
  int32_T c4_c_k;
  int32_T c4_c_vlen;
  int32_T c4_c_vstart;
  int32_T c4_d_k;
  int32_T c4_d_vstart;
  int32_T c4_e_b;
  int32_T c4_e_i0;
  int32_T c4_e_k;
  int32_T c4_e_vstart;
  int32_T c4_f_b;
  int32_T c4_f_i0;
  int32_T c4_f_k;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i0;
  int32_T c4_i1;
  int32_T c4_i_k;
  int32_T c4_inb;
  int32_T c4_k;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (c4_vlen <= 1024) {
    c4_st.site = &c4_vb_emlrtRSI;
    c4_b_vlen = c4_vlen - 1;
    c4_b_vstart = c4_vstart;
    c4_i0 = c4_b_vstart - 1;
    c4_y = c4_b_x[c4_i0];
    c4_i = c4_b_vlen;
    c4_b_st.site = &c4_wb_emlrtRSI;
    c4_b = c4_i;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_i_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st, c4_overflow);
    }

    for (c4_c_k = 0; c4_c_k < c4_i; c4_c_k++) {
      c4_e_k = c4_c_k;
      c4_y += c4_b_x[(c4_i0 + c4_e_k) + 1];
    }
  } else {
    c4_a = c4_vlen;
    c4_nfb = c4_div_nzp_s32(chartInstance, c4_a, 1024, 0, 0U, 0, 0);
    c4_inb = c4_nfb << 10;
    c4_c_vstart = c4_vstart;
    c4_c_i0 = c4_c_vstart - 1;
    c4_y = c4_b_x[c4_c_i0];
    for (c4_k = 0; c4_k < 1023; c4_k++) {
      c4_b_k = c4_k;
      c4_y += c4_b_x[(c4_c_i0 + c4_b_k) + 1];
    }

    c4_st.site = &c4_tb_emlrtRSI;
    c4_c_b = c4_nfb;
    c4_e_b = c4_c_b;
    if (c4_e_b < 2) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_e_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_b_st.site = &c4_i_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st, c4_b_overflow);
    }

    for (c4_d_k = 2; c4_d_k <= c4_nfb; c4_d_k++) {
      c4_d_vstart = c4_vstart + ((c4_d_k - 1) << 10);
      c4_e_i0 = c4_d_vstart - 1;
      c4_b_y = c4_b_x[c4_e_i0];
      for (c4_f_k = 0; c4_f_k < 1023; c4_f_k++) {
        c4_g_k = c4_f_k;
        c4_b_y += c4_b_x[(c4_e_i0 + c4_g_k) + 1];
      }

      c4_y += c4_b_y;
    }

    if (c4_vlen > c4_inb) {
      c4_nleft = c4_vlen - c4_inb;
      c4_lidx = c4_vstart + c4_inb;
      c4_st.site = &c4_ub_emlrtRSI;
      c4_c_vlen = c4_nleft - 1;
      c4_e_vstart = c4_lidx;
      c4_f_i0 = c4_e_vstart - 1;
      c4_c_y = c4_b_x[c4_f_i0];
      c4_i1 = c4_c_vlen;
      c4_b_st.site = &c4_wb_emlrtRSI;
      c4_f_b = c4_i1;
      c4_g_b = c4_f_b;
      if (c4_g_b < 1) {
        c4_c_overflow = false;
      } else {
        c4_c_overflow = (c4_g_b > 2147483646);
      }

      if (c4_c_overflow) {
        c4_c_st.site = &c4_i_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st, c4_c_overflow);
      }

      for (c4_h_k = 0; c4_h_k < c4_i1; c4_h_k++) {
        c4_i_k = c4_h_k;
        c4_c_y += c4_b_x[(c4_f_i0 + c4_i_k) + 1];
      }

      c4_y += c4_c_y;
    }
  }

  return c4_y;
}

static void c4_polyfit(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack *
  c4_sp, coder::array<real_T, 1U> &c4_b_x, coder::array<real_T, 1U> &c4_y,
  real_T c4_p[3])
{
  static char_T c4_b_cv[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o', 'l',
    'y', 'f', 'i', 't', ':', 'X', 'Y', 'S', 'i', 'z', 'e', 'M', 'i', 's', 'm',
    'a', 't', 'c', 'h' };

  static char_T c4_b_cv1[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 'q', 'p', '3' };

  ptrdiff_t c4_jpvt_t[3];
  ptrdiff_t c4_info_t;
  ptrdiff_t c4_lda_t;
  ptrdiff_t c4_m_t;
  ptrdiff_t c4_n_t;
  coder::array<real_T, 2U> c4_e_V;
  coder::array<real_T, 1U> c4_r_B;
  coder::array<real_T, 1U> c4_tau;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_m_y = NULL;
  const mxArray *c4_p_y = NULL;
  const mxArray *c4_q_y = NULL;
  real_T c4_b_k;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_e_b;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_j_y;
  real_T c4_n;
  real_T c4_o_y;
  real_T c4_r_y;
  real_T c4_s_y;
  real_T c4_scale;
  real_T c4_tol;
  real_T c4_varargin_2;
  int32_T c4_jpvt[3];
  int32_T c4_b_tau[1];
  int32_T c4_a;
  int32_T c4_assumedRank;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_i;
  int32_T c4_b_info;
  int32_T c4_b_j;
  int32_T c4_b_loop_ub;
  int32_T c4_b_m;
  int32_T c4_b_minmn;
  int32_T c4_c_b;
  int32_T c4_c_i;
  int32_T c4_c_info;
  int32_T c4_c_k;
  int32_T c4_c_m;
  int32_T c4_c_ma;
  int32_T c4_d_k;
  int32_T c4_d_ma;
  int32_T c4_e_k;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_h_b;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i_k;
  int32_T c4_info;
  int32_T c4_j;
  int32_T c4_j_b;
  int32_T c4_j_k;
  int32_T c4_k;
  int32_T c4_k_b;
  int32_T c4_k_k;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_m_b;
  int32_T c4_m_k;
  int32_T c4_maxmn;
  int32_T c4_minmana;
  int32_T c4_minmn;
  int32_T c4_mn;
  int32_T c4_rr;
  int32_T c4_val;
  boolean_T c4_b;
  boolean_T c4_b_b1;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_overflow;
  boolean_T c4_c_p;
  boolean_T c4_d_overflow;
  boolean_T c4_d_p;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  if (!(static_cast<real_T>(c4_b_x.size(0)) == static_cast<real_T>(c4_y.size(0))))
  {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    sf_mex_call(c4_sp, &c4_p_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  c4_st.site = &c4_xb_emlrtRSI;
  c4_n = static_cast<real_T>(c4_b_x.size(0));
  if (!(c4_n >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_n, &c4_wb_emlrtDCI, &c4_st);
  }

  c4_e_V.set_size(&c4_tc_emlrtRTEI, &c4_st, static_cast<int32_T>(c4_n), 3);
  c4_b = (c4_e_V.size(0) == 0);
  if (!c4_b) {
    c4_i = static_cast<int32_T>(c4_n);
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c4_n, mxDOUBLE_CLASS, c4_i,
      &c4_dd_emlrtRTEI, &c4_st);
    for (c4_k = 0; c4_k < c4_i; c4_k++) {
      c4_b_k = 1.0 + static_cast<real_T>(c4_k);
      c4_e_V[(static_cast<int32_T>(c4_b_k) + (c4_e_V.size(0) << 1)) - 1] = 1.0;
    }

    c4_i2 = static_cast<int32_T>(c4_n);
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c4_n, mxDOUBLE_CLASS, c4_i2,
      &c4_cd_emlrtRTEI, &c4_st);
    for (c4_c_k = 0; c4_c_k < c4_i2; c4_c_k++) {
      c4_b_k = 1.0 + static_cast<real_T>(c4_c_k);
      c4_e_V[(static_cast<int32_T>(c4_b_k) + c4_e_V.size(0)) - 1] = c4_b_x[
        static_cast<int32_T>(c4_b_k) - 1];
    }

    c4_i3 = static_cast<int32_T>(c4_n);
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c4_n, mxDOUBLE_CLASS, c4_i3,
      &c4_bd_emlrtRTEI, &c4_st);
    for (c4_d_k = 0; c4_d_k < c4_i3; c4_d_k++) {
      c4_b_k = 1.0 + static_cast<real_T>(c4_d_k);
      c4_e_V[static_cast<int32_T>(c4_b_k) - 1] = c4_b_x[static_cast<int32_T>
        (c4_b_k) - 1] * c4_e_V[(static_cast<int32_T>(c4_b_k) + c4_e_V.size(0)) -
        1];
    }
  }

  c4_st.site = &c4_yb_emlrtRSI;
  c4_r_B.set_size(&c4_uc_emlrtRTEI, &c4_st, c4_y.size(0));
  c4_loop_ub = c4_y.size(0) - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_r_B[c4_i1] = c4_y[c4_i1];
  }

  c4_b_st.site = &c4_cc_emlrtRSI;
  c4_c_ma = c4_e_V.size(0);
  c4_c_st.site = &c4_gc_emlrtRSI;
  c4_m = c4_c_ma;
  c4_d_ma = c4_e_V.size(0);
  c4_minmana = muIntScalarMin_sint32(c4_d_ma, 3);
  c4_d = static_cast<real_T>(c4_minmana);
  if (!(c4_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d, &c4_xb_emlrtDCI, &c4_c_st);
  }

  c4_tau.set_size(&c4_vc_emlrtRTEI, &c4_c_st, static_cast<int32_T>
                  (muDoubleScalarFloor(c4_d)));
  c4_b_b1 = (c4_e_V.size(0) == 0);
  if (c4_b_b1 || (c4_m < 1)) {
    c4_b_tau[0] = c4_tau.size(0);
    c4_tau.set_size(&c4_wc_emlrtRTEI, &c4_c_st, c4_b_tau[0]);
    c4_b_loop_ub = c4_b_tau[0] - 1;
    for (c4_i5 = 0; c4_i5 <= c4_b_loop_ub; c4_i5++) {
      c4_tau[c4_i5] = 0.0;
    }

    for (c4_e_k = 0; c4_e_k < 3; c4_e_k++) {
      c4_f_k = c4_e_k;
      c4_jpvt[c4_f_k] = c4_f_k + 1;
    }
  } else {
    for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
      c4_jpvt_t[c4_i4] = (ptrdiff_t)0;
    }

    c4_lda_t = (ptrdiff_t)c4_d_ma;
    c4_m_t = (ptrdiff_t)c4_m;
    c4_n_t = (ptrdiff_t)3;
    c4_info_t = LAPACKE_dgeqp3(102, c4_m_t, c4_n_t, &(c4_e_V.data())[0],
      c4_lda_t, &c4_jpvt_t[0], &(c4_tau.data())[0]);
    c4_info = (int32_T)c4_info_t;
    c4_d_st.site = &c4_hc_emlrtRSI;
    c4_b_info = c4_info;
    c4_c_info = c4_b_info;
    c4_b_p = (c4_c_info != 0);
    if (c4_b_p) {
      c4_c_p = true;
      c4_val = c4_b_info;
      c4_d_p = false;
      if (c4_val == -4) {
        c4_d_p = true;
      }

      if (!c4_d_p) {
        if (c4_b_info == -1010) {
          c4_h_y = NULL;
          sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          c4_m_y = NULL;
          sf_mex_assign(&c4_m_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          sf_mex_call(&c4_d_st, &c4_q_emlrtMCI, "error", 0U, 2U, 14, c4_h_y, 14,
                      sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_d_st, NULL, "message", 1U, 1U, 14, c4_m_y)));
        } else {
          c4_g_y = NULL;
          sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1,
            33), false);
          c4_k_y = NULL;
          sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1,
            33), false);
          c4_p_y = NULL;
          sf_mex_assign(&c4_p_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2,
            1, 14), false);
          c4_q_y = NULL;
          sf_mex_assign(&c4_q_y, sf_mex_create("y", &c4_b_info, 6, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call(&c4_d_st, &c4_r_emlrtMCI, "error", 0U, 2U, 14, c4_g_y, 14,
                      sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_d_st, NULL, "message", 1U, 3U, 14, c4_k_y, 14,
                        c4_p_y, 14, c4_q_y)));
        }
      }
    } else {
      c4_c_p = false;
    }

    if (c4_c_p) {
      for (c4_j = 0; c4_j < 3; c4_j++) {
        c4_b_j = c4_j;
        c4_d_st.site = &c4_ic_emlrtRSI;
        c4_c_b = c4_m;
        c4_g_b = c4_c_b;
        if (c4_g_b < 1) {
          c4_b_overflow = false;
        } else {
          c4_b_overflow = (c4_g_b > 2147483646);
        }

        if (c4_b_overflow) {
          c4_e_st.site = &c4_i_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_e_st, c4_b_overflow);
        }

        for (c4_b_i = 0; c4_b_i < c4_m; c4_b_i++) {
          c4_c_i = c4_b_i;
          c4_e_V[c4_b_j * c4_d_ma + c4_c_i] = rtNaN;
        }
      }

      c4_b_minmn = muIntScalarMin_sint32(c4_m, 3);
      c4_d_st.site = &c4_jc_emlrtRSI;
      c4_b_b = c4_b_minmn;
      c4_f_b = c4_b_b;
      if (c4_f_b < 1) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_f_b > 2147483646);
      }

      if (c4_overflow) {
        c4_e_st.site = &c4_i_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st, c4_overflow);
      }

      for (c4_h_k = 0; c4_h_k < c4_b_minmn; c4_h_k++) {
        c4_f_k = c4_h_k;
        c4_tau[c4_f_k] = rtNaN;
      }

      c4_i6 = c4_b_minmn + 1;
      c4_d_st.site = &c4_kc_emlrtRSI;
      c4_a = c4_i6;
      c4_k_b = c4_minmana;
      c4_b_a = c4_a;
      c4_m_b = c4_k_b;
      if (c4_b_a > c4_m_b) {
        c4_d_overflow = false;
      } else {
        c4_d_overflow = (c4_m_b > 2147483646);
      }

      if (c4_d_overflow) {
        c4_e_st.site = &c4_i_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st, c4_d_overflow);
      }

      for (c4_k_k = c4_i6; c4_k_k <= c4_minmana; c4_k_k++) {
        c4_tau[c4_k_k - 1] = 0.0;
      }

      for (c4_m_k = 0; c4_m_k < 3; c4_m_k++) {
        c4_f_k = c4_m_k;
        c4_jpvt[c4_f_k] = c4_f_k + 1;
      }
    } else {
      for (c4_g_k = 0; c4_g_k < 3; c4_g_k++) {
        c4_f_k = c4_g_k;
        c4_jpvt[c4_f_k] = (int32_T)c4_jpvt_t[c4_f_k];
      }
    }
  }

  c4_rr = 0;
  c4_b_m = c4_e_V.size(0);
  if (c4_b_m < 3) {
    c4_minmn = c4_b_m;
    c4_maxmn = 3;
  } else {
    c4_minmn = 3;
    c4_maxmn = c4_b_m;
  }

  if (c4_minmn > 0) {
    c4_varargin_2 = 2.2204460492503131E-15 * static_cast<real_T>(c4_maxmn);
    c4_d_y = c4_varargin_2;
    c4_e_y = c4_d_y;
    c4_f_y = c4_e_y;
    c4_e_b = c4_f_y;
    c4_j_y = c4_e_b;
    c4_o_y = c4_j_y;
    c4_scale = muDoubleScalarMin(1.4901161193847656E-8, c4_o_y);
    c4_c_x = c4_e_V[0];
    c4_d_x = c4_c_x;
    c4_e_x = c4_d_x;
    c4_r_y = muDoubleScalarAbs(c4_e_x);
    c4_tol = c4_scale * c4_r_y;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_rr < c4_minmn)) {
      c4_f_x = c4_e_V[c4_rr + c4_e_V.size(0) * c4_rr];
      c4_g_x = c4_f_x;
      c4_h_x = c4_g_x;
      c4_s_y = muDoubleScalarAbs(c4_h_x);
      if (!(c4_s_y <= c4_tol)) {
        c4_rr++;
      } else {
        c4_exitg1 = true;
      }
    }
  }

  c4_b_st.site = &c4_dc_emlrtRSI;
  c4_assumedRank = 0;
  c4_c_m = c4_e_V.size(0);
  if (c4_c_m < 3) {
    c4_mn = c4_c_m;
  } else {
    c4_mn = 3;
  }

  if (c4_mn > 0) {
    c4_c_st.site = &c4_je_emlrtRSI;
    c4_h_b = c4_mn;
    c4_j_b = c4_h_b;
    if (c4_j_b < 1) {
      c4_c_overflow = false;
    } else {
      c4_c_overflow = (c4_j_b > 2147483646);
    }

    if (c4_c_overflow) {
      c4_d_st.site = &c4_i_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_d_st, c4_c_overflow);
    }

    for (c4_i_k = 0; c4_i_k < c4_mn; c4_i_k++) {
      c4_j_k = c4_i_k;
      if (c4_e_V[c4_j_k + c4_e_V.size(0) * c4_j_k] != 0.0) {
        c4_assumedRank++;
      }
    }
  }

  c4_b_st.site = &c4_ec_emlrtRSI;
  c4_LSQFromQR(chartInstance, &c4_b_st, c4_e_V, c4_tau, c4_jpvt, c4_r_B,
               c4_assumedRank, c4_p);
  if (static_cast<real_T>(c4_b_x.size(0)) <= 2.0) {
    c4_st.site = &c4_bc_emlrtRSI;
    c4_warning(chartInstance, &c4_st);
  } else if (c4_rr <= 2) {
    c4_st.site = &c4_ac_emlrtRSI;
    c4_b_warning(chartInstance, &c4_st);
  }
}

static void c4_LSQFromQR(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, coder::array<real_T, 2U> &c4_mb_A, coder::array<real_T, 1U>
  &c4_tau, int32_T c4_jpvt[3], coder::array<real_T, 1U> &c4_r_B, int32_T
  c4_rankA, real_T c4_u_Y[3])
{
  static char_T c4_b_cv[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'o',
    'r', 'm', 'q', 'r' };

  ptrdiff_t c4_info_t;
  ptrdiff_t c4_lda_t;
  ptrdiff_t c4_ncc_t;
  ptrdiff_t c4_nrc_t;
  ptrdiff_t c4_nrf_t;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  real_T c4_b_x;
  real_T c4_y;
  real_T c4_z;
  int32_T c4_s_B[1];
  int32_T c4_b_b;
  int32_T c4_b_i;
  int32_T c4_b_info;
  int32_T c4_c_b;
  int32_T c4_c_i;
  int32_T c4_c_info;
  int32_T c4_d_i;
  int32_T c4_e_b;
  int32_T c4_f_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_info;
  int32_T c4_j;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_mn;
  int32_T c4_pj;
  int32_T c4_val;
  boolean_T c4_b;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_overflow;
  boolean_T c4_c_p;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  for (c4_i = 0; c4_i < 3; c4_i++) {
    c4_u_Y[c4_i] = 0.0;
  }

  c4_st.site = &c4_ke_emlrtRSI;
  c4_b_st.site = &c4_re_emlrtRSI;
  c4_m = c4_mb_A.size(0);
  if (c4_m < 3) {
    c4_mn = c4_m;
  } else {
    c4_mn = 3;
  }

  c4_b = (c4_mb_A.size(0) == 0);
  if ((!c4_b) && (c4_r_B.size(0) != 0)) {
    c4_nrc_t = (ptrdiff_t)c4_r_B.size(0);
    c4_ncc_t = (ptrdiff_t)1;
    c4_nrf_t = (ptrdiff_t)c4_mn;
    c4_lda_t = (ptrdiff_t)c4_m;
    c4_info_t = LAPACKE_dormqr(102, 'L', 'T', c4_nrc_t, c4_ncc_t, c4_nrf_t,
      &(c4_mb_A.data())[0], c4_lda_t, &(c4_tau.data())[0], &(c4_r_B.data())[0],
      c4_nrc_t);
    c4_info = (int32_T)c4_info_t;
    c4_c_st.site = &c4_se_emlrtRSI;
    c4_b_info = c4_info;
    c4_c_info = c4_b_info;
    c4_p = (c4_c_info != 0);
    if (c4_p) {
      c4_b_p = true;
      c4_val = c4_b_info;
      c4_c_p = false;
      if (c4_val == -7) {
        c4_c_p = true;
      } else if (c4_val == -9) {
        c4_c_p = true;
      } else if (c4_val == -10) {
        c4_c_p = true;
      }

      if (!c4_c_p) {
        if (c4_b_info == -1010) {
          c4_c_y = NULL;
          sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          c4_e_y = NULL;
          sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          sf_mex_call(&c4_c_st, &c4_q_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                      sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_c_st, NULL, "message", 1U, 1U, 14, c4_e_y)));
        } else {
          c4_b_y = NULL;
          sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1,
            33), false);
          c4_d_y = NULL;
          sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1,
            33), false);
          c4_f_y = NULL;
          sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2,
            1, 14), false);
          c4_g_y = NULL;
          sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_b_info, 6, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call(&c4_c_st, &c4_r_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                      sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_c_st, NULL, "message", 1U, 3U, 14, c4_d_y, 14,
                        c4_f_y, 14, c4_g_y)));
        }
      }
    } else {
      c4_b_p = false;
    }

    if (c4_b_p) {
      c4_s_B[0] = c4_r_B.size(0);
      c4_r_B.set_size(&c4_xc_emlrtRTEI, &c4_b_st, c4_s_B[0]);
      c4_loop_ub = c4_s_B[0] - 1;
      for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
        c4_r_B[c4_i1] = rtNaN;
      }
    }
  }

  c4_st.site = &c4_me_emlrtRSI;
  c4_b_b = c4_rankA;
  c4_c_b = c4_b_b;
  if (c4_c_b < 1) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_c_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_i_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st, c4_overflow);
  }

  for (c4_b_i = 0; c4_b_i < c4_rankA; c4_b_i++) {
    c4_c_i = c4_b_i;
    c4_u_Y[c4_jpvt[c4_c_i] - 1] = c4_r_B[c4_c_i];
  }

  c4_st.site = &c4_oe_emlrtRSI;
  c4_b_overflow = false;
  if (c4_b_overflow) {
    c4_b_st.site = &c4_i_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st, c4_b_overflow);
  }

  for (c4_j = c4_rankA; c4_j >= 1; c4_j--) {
    c4_pj = c4_jpvt[c4_j - 1] - 1;
    c4_b_x = c4_u_Y[c4_pj];
    c4_y = c4_mb_A[(c4_j + c4_mb_A.size(0) * (c4_j - 1)) - 1];
    c4_z = c4_b_x / c4_y;
    c4_u_Y[c4_pj] = c4_z;
    c4_i2 = c4_j - 2;
    c4_st.site = &c4_pe_emlrtRSI;
    c4_e_b = c4_i2 + 1;
    c4_f_b = c4_e_b;
    if (c4_f_b < 1) {
      c4_c_overflow = false;
    } else {
      c4_c_overflow = (c4_f_b > 2147483646);
    }

    if (c4_c_overflow) {
      c4_b_st.site = &c4_i_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st, c4_c_overflow);
    }

    for (c4_d_i = 0; c4_d_i <= c4_i2; c4_d_i++) {
      c4_c_i = c4_d_i;
      c4_u_Y[c4_jpvt[c4_c_i] - 1] -= c4_u_Y[c4_pj] * c4_mb_A[c4_c_i +
        c4_mb_A.size(0) * (c4_j - 1)];
    }
  }
}

static void c4_warning(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack *
  c4_sp)
{
  static char_T c4_msgID[28] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o',
    'l', 'y', 'f', 'i', 't', ':', 'P', 'o', 'l', 'y', 'N', 'o', 't', 'U', 'n',
    'i', 'q', 'u', 'e' };

  static char_T c4_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 28),
                false);
  c4_st.site = &c4_we_emlrtRSI;
  c4_b_feval(chartInstance, &c4_st, c4_y, c4_feval(chartInstance, &c4_st, c4_b_y,
              c4_c_y));
}

static void c4_b_warning(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp)
{
  static char_T c4_msgID[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o',
    'l', 'y', 'f', 'i', 't', ':', 'R', 'e', 'p', 'e', 'a', 't', 'e', 'd', 'P',
    'o', 'i', 'n', 't', 's', 'O', 'r', 'R', 'e', 's', 'c', 'a', 'l', 'e' };

  static char_T c4_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 38),
                false);
  c4_st.site = &c4_we_emlrtRSI;
  c4_d_feval(chartInstance, &c4_st, c4_y, c4_c_feval(chartInstance, &c4_st,
              c4_b_y, c4_c_y));
}

const mxArray *sf_c4_LKAS_get_eml_resolved_functions_info()
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static real_T c4_emlrt_marshallIn(SFc4_LKASInstanceStruct *chartInstance, const
  mxArray *c4_nullptr, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  c4_thisId.fIdentifier = const_cast<const char_T *>(c4_identifier);
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nullptr), &c4_thisId);
  sf_mex_destroy(&c4_nullptr);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_LKASInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_d;
  real_T c4_y;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static uint8_T c4_c_emlrt_marshallIn(SFc4_LKASInstanceStruct *chartInstance,
  const mxArray *c4_nullptr, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  c4_thisId.fIdentifier = const_cast<const char_T *>(c4_identifier);
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nullptr), &c4_thisId);
  sf_mex_destroy(&c4_nullptr);
  return c4_y;
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_LKASInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_u;
  uint8_T c4_y;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b_u, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_b_u;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_slStringInitializeDynamicBuffers(SFc4_LKASInstanceStruct
  *chartInstance)
{
}

static void c4_chart_data_browse_helper(SFc4_LKASInstanceStruct *chartInstance,
  int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T *c4_isValueTooBig)
{
  real_T c4_d;
  *c4_mxData = NULL;
  *c4_mxData = NULL;
  *c4_isValueTooBig = 0U;
  switch (c4_ssIdNumber) {
   case 6U:
    *c4_isValueTooBig = 1U;
    break;

   case 8U:
    c4_d = *chartInstance->c4_error;
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", &c4_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }
}

static const mxArray *c4_feval(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  const mxArray *c4_m = NULL;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static void c4_b_feval(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack *
  c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static const mxArray *c4_c_feval(SFc4_LKASInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  const mxArray *c4_m = NULL;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static void c4_d_feval(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack *
  c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static void c4_and(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack
                   *c4_sp, coder::array<boolean_T, 1U> &c4_in1, coder::array<
                   boolean_T, 1U> &c4_in2, coder::array<boolean_T, 1U> &c4_in3)
{
  coder::array<boolean_T, 1U> c4_b_in2;
  int32_T c4_aux_0_0;
  int32_T c4_aux_1_0;
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  int32_T c4_stride_0_0;
  int32_T c4_stride_1_0;
  if (c4_in3.size(0) == 1) {
    c4_i = c4_in2.size(0);
  } else {
    c4_i = c4_in3.size(0);
  }

  c4_b_in2.set_size(&c4_x_emlrtRTEI, c4_sp, c4_i);
  c4_stride_0_0 = static_cast<int32_T>(c4_in2.size(0) != 1);
  c4_stride_1_0 = static_cast<int32_T>(c4_in3.size(0) != 1);
  c4_aux_0_0 = 0;
  c4_aux_1_0 = 0;
  if (c4_in3.size(0) == 1) {
    c4_i1 = c4_in2.size(0);
  } else {
    c4_i1 = c4_in3.size(0);
  }

  c4_loop_ub = c4_i1 - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_b_in2[c4_i2] = (c4_in2[c4_aux_0_0] && c4_in3[c4_aux_1_0]);
    c4_aux_1_0 += c4_stride_1_0;
    c4_aux_0_0 += c4_stride_0_0;
  }

  c4_in1.set_size(&c4_x_emlrtRTEI, c4_sp, c4_b_in2.size(0));
  c4_b_loop_ub = c4_b_in2.size(0) - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_in1[c4_i3] = c4_b_in2[c4_i3];
  }
}

static void c4_b_and(SFc4_LKASInstanceStruct *chartInstance, const emlrtStack
                     *c4_sp, coder::array<boolean_T, 1U> &c4_in1, coder::array<
                     boolean_T, 1U> &c4_in2)
{
  coder::array<boolean_T, 1U> c4_b_in1;
  int32_T c4_aux_0_0;
  int32_T c4_aux_1_0;
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  int32_T c4_stride_0_0;
  int32_T c4_stride_1_0;
  if (c4_in2.size(0) == 1) {
    c4_i = c4_in1.size(0);
  } else {
    c4_i = c4_in2.size(0);
  }

  c4_b_in1.set_size(&c4_x_emlrtRTEI, c4_sp, c4_i);
  c4_stride_0_0 = static_cast<int32_T>(c4_in1.size(0) != 1);
  c4_stride_1_0 = static_cast<int32_T>(c4_in2.size(0) != 1);
  c4_aux_0_0 = 0;
  c4_aux_1_0 = 0;
  if (c4_in2.size(0) == 1) {
    c4_i1 = c4_in1.size(0);
  } else {
    c4_i1 = c4_in2.size(0);
  }

  c4_loop_ub = c4_i1 - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_b_in1[c4_i2] = (c4_in1[c4_aux_0_0] && c4_in2[c4_aux_1_0]);
    c4_aux_1_0 += c4_stride_1_0;
    c4_aux_0_0 += c4_stride_0_0;
  }

  c4_in1.set_size(&c4_x_emlrtRTEI, c4_sp, c4_b_in1.size(0));
  c4_b_loop_ub = c4_b_in1.size(0) - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_in1[c4_i3] = c4_b_in1[c4_i3];
  }
}

static int32_T c4_div_nzp_s32(SFc4_LKASInstanceStruct *chartInstance, int32_T
  c4_numerator, int32_T c4_denominator, int32_T c4_EMLOvCount_src_loc, uint32_T
  c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc)
{
  int32_T c4_quotient;
  uint32_T c4_absDenominator;
  uint32_T c4_absNumerator;
  uint32_T c4_tempAbsQuotient;
  boolean_T c4_quotientNeedsNegation;
  if (c4_numerator < 0) {
    c4_absNumerator = ~static_cast<uint32_T>(c4_numerator) + 1U;
  } else {
    c4_absNumerator = static_cast<uint32_T>(c4_numerator);
  }

  if (c4_denominator < 0) {
    c4_absDenominator = ~static_cast<uint32_T>(c4_denominator) + 1U;
  } else {
    c4_absDenominator = static_cast<uint32_T>(c4_denominator);
  }

  c4_quotientNeedsNegation = (static_cast<int32_T>(c4_numerator < 0) !=
    static_cast<int32_T>(c4_denominator < 0));
  c4_tempAbsQuotient = c4_absNumerator / c4_absDenominator;
  if (c4_quotientNeedsNegation) {
    c4_quotient = -static_cast<int32_T>(c4_tempAbsQuotient);
  } else {
    c4_quotient = static_cast<int32_T>(c4_tempAbsQuotient);
  }

  return c4_quotient;
}

static void init_dsm_address_info(SFc4_LKASInstanceStruct *chartInstance)
{
}

static void init_simulink_io_address(SFc4_LKASInstanceStruct *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_binary_image = (boolean_T (*)[900000])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c4_error = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_LKAS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1213458069U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2460365869U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2387220226U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(263585466U);
}

mxArray *sf_c4_LKAS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,4);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "coder.internal.EmxArrayExternalDependency"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "coder.internal.BoundedEmxArrayExternalDependency"));
  return(mxcell3p);
}

mxArray *sf_c4_LKAS_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_vars");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("Ypk");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_LKAS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_LKAS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Cg7o+lmw6GdF0i8A5acWFeUXQcMHFk7UdAdp+i"
    "H2exDwhyCaP0D8zOL4xOSSzLLU+GSTeB9vx2Ak80AAAEyJF6Y="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_LKAS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sXiHR1KYXBAGeyWcfXtx4ND";
}

static void sf_opaque_initialize_c4_LKAS(void *chartInstanceVar)
{
  initialize_params_c4_LKAS((SFc4_LKASInstanceStruct*) chartInstanceVar);
  initialize_c4_LKAS((SFc4_LKASInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_LKAS(void *chartInstanceVar)
{
  enable_c4_LKAS((SFc4_LKASInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_LKAS(void *chartInstanceVar)
{
  disable_c4_LKAS((SFc4_LKASInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_LKAS(void *chartInstanceVar)
{
  sf_gateway_c4_LKAS((SFc4_LKASInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_LKAS(SimStruct* S)
{
  return get_sim_state_c4_LKAS((SFc4_LKASInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_LKAS(SimStruct* S, const mxArray *st)
{
  set_sim_state_c4_LKAS((SFc4_LKASInstanceStruct*)sf_get_chart_instance_ptr(S),
                        st);
}

static void sf_opaque_cleanup_runtime_resources_c4_LKAS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_LKASInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_LKAS_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_LKAS((SFc4_LKASInstanceStruct*)
      chartInstanceVar);
    ((SFc4_LKASInstanceStruct*) chartInstanceVar)->~SFc4_LKASInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_LKAS(void *chartInstanceVar)
{
  mdl_start_c4_LKAS((SFc4_LKASInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc4_LKASInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c4_LKAS(void *chartInstanceVar)
{
  mdl_terminate_c4_LKAS((SFc4_LKASInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_LKAS(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_LKAS((SFc4_LKASInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc4_LKAS((SFc4_LKASInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_LKAS_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWMtu20YUHQmO2wRNkCyKeFGg2RTopkCKBkUWRWpZj0SIHRumnLjdGOPhlTjwcMjMQ5b6I/2",
    "FIr+RTT6hiwJd9Ae6zK69Q1GKQKvyjBSkSQhQ1JA8cx9zH2dIat09gscNPLe2CNnE66d41snkuF",
    "KOa3Pn5P4G+aEcv7pGCMtiGICMbL/PRyTskDY9oIqmmoQfkqZwCDoT1vBMdmU/88dy2QcFkuEEe",
    "aZMkFzNUyu4POtYyZxk/SzhLImSzIp4Byek8b4U4/+Sm1tzgBJbXAEzHYDYJCqzg6Qj6GC5F5Q5",
    "bybAzrRNg32lwUQ2d6bqPSsMzwW0R8C6UhuKXtCX2BsZaqBpRmFOdvbqaIrO0lxwKv19nVAdQY7",
    "RYeAoj/F33xr0nqdclHfKJTWZ4lS0U9FMqPLFHgjUcw/DWgT72aSmBad2MOBy4LyrbAoS7cc48f",
    "BVv5kNQdEB7MswucxZ1x4VCzyLS0+s4Sk8parBMA40xGE5iAGsI4pLCz2cJggLkp4K6Oqe4kNco",
    "9C60XWptFLdsOkkkvRK2EJue4irqleU22GySYXQYdhelu/CEEQhv0UNXQE7kR8A1prHvQyjw2Vu",
    "YPZbyZ9bKLHNTMbcPyqHFVTRJJ5gwfeA89SlAcTo5pnqs4kuyyOrTZY2MfVbu7ue8i5iu9KA6lM",
    "G3vVaUa4BFS7iKlBuzLVLJESjl0xhpfcMkxxcCUp038rWeabO0MehjeGNr1wmhKEhHkALDBRFro",
    "3R/ZQK66lzqrEqu/A40lhlw+Qi1uXPSmBGWQKx64FcwB7WWZzAd4m1a58NtHbIzbgFmime+2aSx",
    "YKOzc95qTfO4UieyexcdlSWRiWLWRJXAFg1qJLYynawlapxB5X301rB815R3UMJg/MzNYKeuth4",
    "CBK7obPVdW/KMKvaEukmKrQONuK/IB2RmmuDFHDcLnIgLnjwffKGB28s4MGfzPHgm+WY3TvZfdy",
    "ICvzdOfxnHjx6yr+X4cgFHJnhptev5/C1BXLJ3LUq72p9uZ51/FcrcdtzuOsVORsV3Gbpo79eku",
    "0XW9cPb//5z69/fP/5V+vI/60etk+5UY6/mHKkWUUeXiha7t1Hl6z/7cr6u7E+5o8Ov3380/FO4",
    "yGMn7H+sRnde9Iq5ntdW65vvaLv9P4dx8swYYv8V6wbl/sdN6Z2wsOr8bp5iT+uzsUTIX//uB7+",
    "zrZPvlyp+MuNQalMVeL3beoRhvdb91sVO24VfP2EuqoMJ9MKcDEvV43zUNyHIu9j1/Nt2ufTP94",
    "1jrxj3Lr2hfbFD/39u0vqGKm8f/M9tmNZHQ3hR++bXb+TMP7yZTl+MNuLNxMu4gW7gfIxEvb+oq",
    "cfSXy/DvTflK+1nf/KD6A/f9eQVIyR/k+2V+XtA+W+vc0eKaB68R7r/+gni3iSL9866nW+ub9GX",
    "/oX7Kn8pw==",
    ""
  };

  static char newstr [1437] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_LKAS(SimStruct *S)
{
  const char* newstr = sf_c4_LKAS_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1073791971U));
  ssSetChecksum1(S,(1376589994U));
  ssSetChecksum2(S,(2550128407U));
  ssSetChecksum3(S,(622147292U));
}

static void mdlRTW_c4_LKAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_LKAS(SimStruct *S)
{
  SFc4_LKASInstanceStruct *chartInstance;
  chartInstance = (SFc4_LKASInstanceStruct *)utMalloc(sizeof
    (SFc4_LKASInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_LKASInstanceStruct));
  chartInstance = new (chartInstance) SFc4_LKASInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_LKAS;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_LKAS;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_LKAS;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c4_LKAS;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_LKAS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_LKAS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_LKAS;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_LKAS;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_LKAS;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_LKAS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_LKAS;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_LKAS;
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

  mdl_setup_runtime_resources_c4_LKAS(chartInstance);
}

void c4_LKAS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_LKAS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_LKAS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_LKAS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_LKAS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
