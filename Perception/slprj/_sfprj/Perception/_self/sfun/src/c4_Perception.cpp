/* Include files */

#include "Perception_sfun.h"
#include "c4_Perception.h"
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
static emlrtMCInfo c4_emlrtMCI{ 87,    /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI{ 239, /* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_c_emlrtMCI{ 242, /* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_d_emlrtMCI{ 406, /* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_e_emlrtMCI{ 417, /* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_f_emlrtMCI{ 444, /* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtMCInfo c4_g_emlrtMCI{ 78,  /* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtMCInfo c4_h_emlrtMCI{ 398, /* lineNo */
  5,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtMCInfo c4_i_emlrtMCI{ 122, /* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c4_j_emlrtMCI{ 18,  /* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/mean.m"/* pName */
};

static emlrtMCInfo c4_k_emlrtMCI{ 26,  /* lineNo */
  23,                                  /* colNo */
  "polyfit",                           /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pName */
};

static emlrtMCInfo c4_m_emlrtMCI{ 45,  /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtMCInfo c4_o_emlrtMCI{ 48,  /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtMCInfo c4_p_emlrtMCI{ 13,  /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtMCInfo c4_q_emlrtMCI{ 18,  /* lineNo */
  27,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI{ 150,   /* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI{ 151, /* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI{ 162, /* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI{ 166, /* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI{ 173, /* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI{ 179, /* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI{ 528, /* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI{ 20,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI{ 543, /* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI{ 23,  /* lineNo */
  "union",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/union.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI{ 94,  /* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI{ 238, /* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI{ 241, /* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI{ 74,  /* lineNo */
  "issorted",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/issorted.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI{ 95,  /* lineNo */
  "issorted",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/issorted.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI{ 112, /* lineNo */
  "issorted",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/issorted.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI{ 556, /* lineNo */
  "findpeaks",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI{ 28,  /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI{ 82,  /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI{ 140, /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI{ 42,  /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI{ 35,  /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI{ 138, /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI{ 253,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_bb_emlrtRSI{ 254,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_cb_emlrtRSI{ 255,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_db_emlrtRSI{ 49, /* lineNo */
  "mean",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/mean.m"/* pathName */
};

static emlrtRSInfo c4_eb_emlrtRSI{ 86, /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c4_fb_emlrtRSI{ 107,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pathName */
};

static emlrtRSInfo c4_gb_emlrtRSI{ 22, /* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_hb_emlrtRSI{ 57, /* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_ib_emlrtRSI{ 42, /* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_jb_emlrtRSI{ 189,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_kb_emlrtRSI{ 178,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_mb_emlrtRSI{ 210,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_ob_emlrtRSI{ 36, /* lineNo */
  "polyfit",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pathName */
};

static emlrtRSInfo c4_pb_emlrtRSI{ 47, /* lineNo */
  "polyfit",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pathName */
};

static emlrtRSInfo c4_qb_emlrtRSI{ 40, /* lineNo */
  "polyfit",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/polyfit.m"/* pathName */
};

static emlrtRSInfo c4_rb_emlrtRSI{ 61, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_sb_emlrtRSI{ 80, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_tb_emlrtRSI{ 85, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_ub_emlrtRSI{ 63, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_vb_emlrtRSI{ 138,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_wb_emlrtRSI{ 143,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_xb_emlrtRSI{ 148,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_yb_emlrtRSI{ 119,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_ac_emlrtRSI{ 174,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_bc_emlrtRSI{ 189,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_cc_emlrtRSI{ 30, /* lineNo */
  "xswap",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xswap.m"/* pathName */
};

static emlrtRSInfo c4_dc_emlrtRSI{ 20, /* lineNo */
  "xswap",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xswap.m"/* pathName */
};

static emlrtRSInfo c4_ec_emlrtRSI{ 81, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_fc_emlrtRSI{ 41, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_gc_emlrtRSI{ 68, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_hc_emlrtRSI{ 71, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_ic_emlrtRSI{ 37, /* lineNo */
  "xscal",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"/* pathName */
};

static emlrtRSInfo c4_jc_emlrtRSI{ 49, /* lineNo */
  "xscal",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xscal.m"/* pathName */
};

static emlrtRSInfo c4_kc_emlrtRSI{ 68, /* lineNo */
  "xzlarf",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"/* pathName */
};

static emlrtRSInfo c4_mc_emlrtRSI{ 75, /* lineNo */
  "xzlarf",                            /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzlarf.m"/* pathName */
};

static emlrtRSInfo c4_oc_emlrtRSI{ 76, /* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_pc_emlrtRSI{ 64, /* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_qc_emlrtRSI{ 37, /* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_rc_emlrtRSI{ 71, /* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_sc_emlrtRSI{ 91, /* lineNo */
  "xgemv",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xgemv.m"/* pathName */
};

static emlrtRSInfo c4_tc_emlrtRSI{ 45, /* lineNo */
  "xgerc",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xgerc.m"/* pathName */
};

static emlrtRSInfo c4_uc_emlrtRSI{ 53, /* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xger.m"/* pathName */
};

static emlrtRSInfo c4_vc_emlrtRSI{ 45, /* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xger.m"/* pathName */
};

static emlrtRSInfo c4_wc_emlrtRSI{ 15, /* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xger.m"/* pathName */
};

static emlrtRSInfo c4_xc_emlrtRSI{ 41, /* lineNo */
  "xgerx",                             /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/xgerx.m"/* pathName */
};

static emlrtRSInfo c4_yc_emlrtRSI{ 67, /* lineNo */
  "xger",                              /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xger.m"/* pathName */
};

static emlrtRSInfo c4_ad_emlrtRSI{ 189,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_bd_emlrtRSI{ 119,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_cd_emlrtRSI{ 128,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_dd_emlrtRSI{ 138,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_ed_emlrtRSI{ 31, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo c4_fd_emlrtRSI{ 102,/* lineNo */
  "xunormqr",                          /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo c4_gd_emlrtRSI{ 18, /* lineNo */
  "xzunormqr",                         /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/xzunormqr.m"/* pathName */
};

static emlrtRSInfo c4_hd_emlrtRSI{ 14, /* lineNo */
  "warning",                           /* fcnName */
  "/usr/local/MATLAB/R2023b/toolbox/shared/coder/coder/lib/+coder/+internal/warning.m"/* pathName */
};

static emlrtRSInfo c4_id_emlrtRSI{ 13, /* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#Perception:9"                      /* pathName */
};

static emlrtRSInfo c4_jd_emlrtRSI{ 41, /* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#Perception:9"                      /* pathName */
};

static emlrtRSInfo c4_kd_emlrtRSI{ 103,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#Perception:9"                      /* pathName */
};

static emlrtRSInfo c4_md_emlrtRSI{ 108,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#Perception:9"                      /* pathName */
};

static emlrtRSInfo c4_od_emlrtRSI{ 121,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#Perception:9"                      /* pathName */
};

static emlrtRSInfo c4_pd_emlrtRSI{ 122,/* lineNo */
  "Perception Unit/MATLAB Function3",  /* fcnName */
  "#Perception:9"                      /* pathName */
};

static emlrtRTEInfo c4_emlrtRTEI{ 36,  /* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_b_emlrtRTEI{ 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_c_emlrtRTEI{ 74,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_d_emlrtRTEI{ 74,/* lineNo */
  65,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_e_emlrtRTEI{ 74,/* lineNo */
  91,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_f_emlrtRTEI{ 74,/* lineNo */
  122,                                 /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_g_emlrtRTEI{ 74,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_h_emlrtRTEI{ 75,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_i_emlrtRTEI{ 75,/* lineNo */
  65,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_j_emlrtRTEI{ 75,/* lineNo */
  91,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_k_emlrtRTEI{ 75,/* lineNo */
  122,                                 /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_m_emlrtRTEI{ 75,/* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_o_emlrtRTEI{ 77,/* lineNo */
  40,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_p_emlrtRTEI{ 77,/* lineNo */
  66,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_q_emlrtRTEI{ 77,/* lineNo */
  92,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_r_emlrtRTEI{ 77,/* lineNo */
  124,                                 /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_s_emlrtRTEI{ 77,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_t_emlrtRTEI{ 78,/* lineNo */
  40,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_u_emlrtRTEI{ 78,/* lineNo */
  66,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_v_emlrtRTEI{ 78,/* lineNo */
  92,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_w_emlrtRTEI{ 78,/* lineNo */
  124,                                 /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_x_emlrtRTEI{ 78,/* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_y_emlrtRTEI{ 115,/* lineNo */
  1,                                   /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_ab_emlrtRTEI{ 116,/* lineNo */
  1,                                   /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_bb_emlrtRTEI{ 121,/* lineNo */
  18,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_cb_emlrtRTEI{ 121,/* lineNo */
  46,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_db_emlrtRTEI{ 122,/* lineNo */
  19,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_eb_emlrtRTEI{ 122,/* lineNo */
  48,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_fb_emlrtRTEI{ 416,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_gb_emlrtRTEI{ 417,/* lineNo */
  23,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_hb_emlrtRTEI{ 418,/* lineNo */
  27,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_ib_emlrtRTEI{ 503,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_jb_emlrtRTEI{ 504,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_kb_emlrtRTEI{ 525,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_mb_emlrtRTEI{ 539,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_ob_emlrtRTEI{ 151,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_pb_emlrtRTEI{ 162,/* lineNo */
  43,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_qb_emlrtRTEI{ 172,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c4_rb_emlrtRTEI{ 556,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_sb_emlrtRTEI{ 175,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_tb_emlrtRTEI{ 171,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_ub_emlrtRTEI{ 173,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_vb_emlrtRTEI{ 179,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_wb_emlrtRTEI{ 649,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_xb_emlrtRTEI{ 650,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_yb_emlrtRTEI{ 654,/* lineNo */
  3,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_ac_emlrtRTEI{ 661,/* lineNo */
  3,                                   /* colNo */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m"/* pName */
};

static emlrtRTEInfo c4_bc_emlrtRTEI{ 220,/* lineNo */
  24,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_cc_emlrtRTEI{ 221,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_dc_emlrtRTEI{ 222,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_ec_emlrtRTEI{ 412,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_fc_emlrtRTEI{ 423,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_gc_emlrtRTEI{ 448,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo c4_hc_emlrtRTEI{ 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_ic_emlrtRTEI{ 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_jc_emlrtRTEI{ 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_kc_emlrtRTEI{ 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_mc_emlrtRTEI{ 17,/* lineNo */
  20,                                  /* colNo */
  "vander",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/vander.m"/* pName */
};

static emlrtRTEInfo c4_oc_emlrtRTEI{ 61,/* lineNo */
  1,                                   /* colNo */
  "qrsolve",                           /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pName */
};

static emlrtRTEInfo c4_pc_emlrtRTEI{ 85,/* lineNo */
  26,                                  /* colNo */
  "qrsolve",                           /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pName */
};

static emlrtRTEInfo c4_qc_emlrtRTEI{ 1,/* lineNo */
  25,                                  /* colNo */
  "xgeqp3",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pName */
};

static emlrtRTEInfo c4_rc_emlrtRTEI{ 119,/* lineNo */
  5,                                   /* colNo */
  "qrsolve",                           /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pName */
};

static emlrtRTEInfo c4_sc_emlrtRTEI{ 92,/* lineNo */
  22,                                  /* colNo */
  "xgeqp3",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pName */
};

static emlrtRTEInfo c4_tc_emlrtRTEI{ 97,/* lineNo */
  5,                                   /* colNo */
  "xgeqp3",                            /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pName */
};

static emlrtBCInfo c4_emlrtBCI{ 0,     /* iFirst */
  MAX_int32_T,                         /* iLast */
  83,                                  /* lineNo */
  30,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_b_emlrtBCI{ 0,   /* iFirst */
  MAX_int32_T,                         /* iLast */
  88,                                  /* lineNo */
  31,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_c_emlrtBCI{ 0,   /* iFirst */
  MAX_int32_T,                         /* iLast */
  102,                                 /* lineNo */
  12,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_d_emlrtBCI{ 0,   /* iFirst */
  MAX_int32_T,                         /* iLast */
  107,                                 /* lineNo */
  12,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_emlrtDCI{ 84,    /* lineNo */
  29,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_e_emlrtBCI{ 1,   /* iFirst */
  100000,                              /* iLast */
  84,                                  /* lineNo */
  29,                                  /* colNo */
  "left_lane_index",                   /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_b_emlrtDCI{ 115, /* lineNo */
  44,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_f_emlrtBCI{ 1,   /* iFirst */
  100000,                              /* iLast */
  115,                                 /* lineNo */
  44,                                  /* colNo */
  "left_lane_index",                   /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_c_emlrtDCI{ 89,  /* lineNo */
  30,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_g_emlrtBCI{ 1,   /* iFirst */
  100000,                              /* iLast */
  89,                                  /* lineNo */
  30,                                  /* colNo */
  "right_lane_index",                  /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_d_emlrtDCI{ 116, /* lineNo */
  46,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_h_emlrtBCI{ 1,   /* iFirst */
  100000,                              /* iLast */
  116,                                 /* lineNo */
  46,                                  /* colNo */
  "right_lane_index",                  /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_e_emlrtDCI{ 69,  /* lineNo */
  26,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_i_emlrtBCI{ 1,   /* iFirst */
  20,                                  /* iLast */
  69,                                  /* lineNo */
  26,                                  /* colNo */
  "rectangle_points",                  /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_f_emlrtDCI{ 70,  /* lineNo */
  26,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_j_emlrtBCI{ 1,   /* iFirst */
  20,                                  /* iLast */
  70,                                  /* lineNo */
  26,                                  /* colNo */
  "rectangle_points",                  /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  3                                    /* checkKind */
};

static emlrtECInfo c4_emlrtECI{ -1,    /* nDims */
  74,                                  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtECInfo c4_b_emlrtECI{ 1,   /* nDims */
  74,                                  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtECInfo c4_c_emlrtECI{ -1,  /* nDims */
  75,                                  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtECInfo c4_d_emlrtECI{ 1,   /* nDims */
  75,                                  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtECInfo c4_e_emlrtECI{ -1,  /* nDims */
  77,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtECInfo c4_f_emlrtECI{ 1,   /* nDims */
  77,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtECInfo c4_g_emlrtECI{ -1,  /* nDims */
  78,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtECInfo c4_h_emlrtECI{ 1,   /* nDims */
  78,                                  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_uc_emlrtRTEI{ 83,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtRTEInfo c4_vc_emlrtRTEI{ 88,/* lineNo */
  17,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9"                      /* pName */
};

static emlrtBCInfo c4_k_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  18,                                  /* colNo */
  "locs",                              /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_m_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  25,                                  /* colNo */
  "right_base",                        /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_g_emlrtDCI{ 17,  /* lineNo */
  25,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_o_emlrtBCI{ 0,   /* iFirst */
  MAX_int32_T,                         /* iLast */
  17,                                  /* lineNo */
  25,                                  /* colNo */
  "right_base(end)",                   /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_p_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  19,                                  /* colNo */
  "locs",                              /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_h_emlrtDCI{ 16,  /* lineNo */
  19,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_q_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  38,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_i_emlrtDCI{ 74,  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_r_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  38,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_j_emlrtDCI{ 75,  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_s_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  39,                                  /* colNo */
  "nonzerox",                          /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_k_emlrtDCI{ 77,  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_t_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  39,                                  /* colNo */
  "nonzeroy",                          /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_m_emlrtDCI{ 78,  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_u_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  38,                                  /* colNo */
  "good_leftx_indexs",                 /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_o_emlrtDCI{ 84,  /* lineNo */
  38,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_v_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  60,                                  /* colNo */
  "good_lefty_indexs",                 /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_p_emlrtDCI{ 84,  /* lineNo */
  60,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_w_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  39,                                  /* colNo */
  "good_rightx_indexs",                /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_q_emlrtDCI{ 89,  /* lineNo */
  39,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_x_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  62,                                  /* colNo */
  "good_righty_indexs",                /* aName */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_r_emlrtDCI{ 89,  /* lineNo */
  62,                                  /* colNo */
  "Perception Unit/MATLAB Function3",  /* fName */
  "#Perception:9",                     /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_y_emlrtBCI{ -1,  /* iFirst */
  -1,                                  /* iLast */
  539,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ab_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  539,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  466,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  474,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_db_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_eb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  500,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  479,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  503,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  505,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ib_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  179,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  179,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  529,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_mb_emlrtBCI{ 1,  /* iFirst */
  1200,                                /* iLast */
  530,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ob_emlrtBCI{ 1,  /* iFirst */
  1200,                                /* iLast */
  532,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pb_emlrtBCI{ 1,  /* iFirst */
  1200,                                /* iLast */
  532,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  535,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rb_emlrtBCI{ -1, /* iFirst */
  -1,                                  /* iLast */
  179,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "/usr/local/MATLAB/R2023b/toolbox/signal/signal/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static char_T c4_cv[12]{ 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm', 'e',
  'm' };

static char_T c4_cv1[33]{ 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b',
  'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E', 'r', 'r',
  'o', 'r', 'I', 'n', 'f', 'o' };

/* Function Declarations */
static void initialize_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance);
static void initialize_params_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance);
static void mdl_start_c4_Perception(SFc4_PerceptionInstanceStruct *chartInstance);
static void mdl_terminate_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c4_Perception
  (SFc4_PerceptionInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_Perception
  (SFc4_PerceptionInstanceStruct *chartInstance);
static void enable_c4_Perception(SFc4_PerceptionInstanceStruct *chartInstance);
static void disable_c4_Perception(SFc4_PerceptionInstanceStruct *chartInstance);
static void sf_gateway_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance);
static void ext_mode_exec_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance);
static void c4_update_jit_animation_c4_Perception(SFc4_PerceptionInstanceStruct *
  chartInstance);
static void c4_do_animation_call_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_Perception(SFc4_PerceptionInstanceStruct *
  chartInstance);
static void set_sim_state_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void initSimStructsc4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance);
static void initSubchartIOPointersc4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance);
static void c4_findpeaks(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_Yin[1200], real_T c4_Ypk_data[], int32_T
  c4_Ypk_size[2], real_T c4_Xpk_data[], int32_T c4_Xpk_size[2]);
static void c4_check_forloop_overflow_error(SFc4_PerceptionInstanceStruct
  *chartInstance, const emlrtStack *c4_sp);
static void c4_do_vectors(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_b_a_data[], int32_T c4_a_size[1], int32_T
  c4_b_b_data[], int32_T c4_b_size[1], int32_T c4_c_data[], int32_T c4_c_size[1],
  int32_T c4_ia_data[], int32_T c4_ia_size[1], int32_T c4_ib_data[], int32_T
  c4_ib_size[1]);
static boolean_T c4_issorted(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_x_size[1]);
static void c4_indexShapeCheck(SFc4_PerceptionInstanceStruct *chartInstance);
static void c4_b_indexShapeCheck(SFc4_PerceptionInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T c4_indexSize[2]);
static void c4_eml_find(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, boolean_T c4_b_x[900000], int32_T c4_i_data[], int32_T
  c4_i_size[1], int32_T c4_j_data[], int32_T c4_j_size[1]);
static real_T c4_mean(SFc4_PerceptionInstanceStruct *chartInstance, const
                      emlrtStack *c4_sp, real_T c4_x_data[], int32_T c4_x_size[1]);
static real_T c4_sumColumnB(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_x_data[], int32_T c4_vlen);
static real_T c4_sumColumnB4(SFc4_PerceptionInstanceStruct *chartInstance,
  real_T c4_x_data[], int32_T c4_vstart);
static real_T c4_b_sumColumnB(SFc4_PerceptionInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_x_data[], int32_T c4_vlen, int32_T
  c4_vstart);
static void c4_polyfit(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_x_data[], int32_T c4_x_size[1], real_T c4_y_data[],
  int32_T c4_y_size[1], real_T c4_p[3]);
static void c4_qrsolve(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_c_A_data[], int32_T c4_b_A_size[2], real_T
  c4_c_B_data[], int32_T c4_b_B_size[1], real_T c4_m_Y[3], int32_T *c4_rankA);
static void c4_xgeqp3(SFc4_PerceptionInstanceStruct *chartInstance, const
                      emlrtStack *c4_sp, real_T c4_c_A_data[], int32_T
                      c4_b_A_size[2], real_T c4_d_A_data[], int32_T c4_c_A_size
                      [2], real_T c4_tau_data[], int32_T c4_tau_size[1], int32_T
                      c4_jpvt[3]);
static void c4_LSQFromQR(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_c_A_data[], int32_T c4_b_A_size[2], real_T
  c4_tau_data[], int32_T c4_jpvt[3], real_T c4_c_B_data[], int32_T c4_b_B_size[1],
  int32_T c4_rankA, real_T c4_m_Y[3]);
static void c4_warning(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp);
static void c4_b_warning(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp);
static real_T c4_emlrt_marshallIn(SFc4_PerceptionInstanceStruct *chartInstance,
  const mxArray *c4_nullptr, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_PerceptionInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint8_T c4_c_emlrt_marshallIn(SFc4_PerceptionInstanceStruct
  *chartInstance, const mxArray *c4_nullptr, const char_T *c4_identifier);
static uint8_T c4_d_emlrt_marshallIn(SFc4_PerceptionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_slStringInitializeDynamicBuffers(SFc4_PerceptionInstanceStruct
  *chartInstance);
static void c4_chart_data_browse_helper(SFc4_PerceptionInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig);
static const mxArray *c4_feval(SFc4_PerceptionInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_b_feval(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static const mxArray *c4_c_feval(SFc4_PerceptionInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_d_feval(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_b_xgeqp3(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_c_A_data[], int32_T c4_b_A_size[2], real_T
  c4_tau_data[], int32_T c4_tau_size[1], int32_T c4_jpvt[3]);
static void c4_and(SFc4_PerceptionInstanceStruct *chartInstance, boolean_T
                   c4_b_in1_data[], int32_T c4_in1_size[1], boolean_T
                   c4_b_in2_data[], int32_T c4_in2_size[1], boolean_T
                   c4_in3_data[], int32_T c4_in3_size[1]);
static void c4_b_and(SFc4_PerceptionInstanceStruct *chartInstance, boolean_T
                     c4_b_in1_data[], int32_T c4_in1_size[1], boolean_T
                     c4_b_in2_data[], int32_T c4_in2_size[1]);
static void init_dsm_address_info(SFc4_PerceptionInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_PerceptionInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance)
{
  emlrtStack c4_st{ NULL,              /* site */
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

static void initialize_params_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance)
{
}

static void mdl_start_c4_Perception(SFc4_PerceptionInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance)
{
}

static void mdl_setup_runtime_resources_c4_Perception
  (SFc4_PerceptionInstanceStruct *chartInstance)
{
  static const uint32_T c4_decisionTxtEndIdx{ 0U };

  static const uint32_T c4_decisionTxtStartIdx{ 0U };

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
                     "eML_blk_kernel", 0, -1, 5695);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 4276, 4313, -1,
                    4391, false);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 4409, 4447, -1,
                    4527, false);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1769, 1789,
                     4542);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 3423, 3468,
                     3603);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 3613, 3660,
                     3800);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 4279,
    4312, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 4412,
    4446, -1, 4U);
}

static void mdl_cleanup_runtime_resources_c4_Perception
  (SFc4_PerceptionInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c4_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void enable_c4_Perception(SFc4_PerceptionInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_Perception(SFc4_PerceptionInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st{ NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c4_base[1200];
  real_T c4_locs_data[1200];
  real_T c4_right_base_data[1200];
  real_T c4_xleft[751];
  real_T c4_xright[751];
  real_T c4_p_left[3];
  real_T c4_p_right[3];
  real_T c4_b_d1;
  real_T c4_b_error;
  real_T c4_b_j;
  real_T c4_b_p_left;
  real_T c4_b_p_right;
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
  real_T c4_right_base;
  real_T c4_rightx_current;
  real_T c4_win_xleft_high;
  real_T c4_win_xleft_low;
  real_T c4_win_xright_high;
  real_T c4_win_xright_low;
  real_T c4_win_y_high;
  real_T c4_win_y_low;
  int32_T c4_nz[1200];
  int32_T c4_actual_left_lane_index_size[2];
  int32_T c4_actual_right_lane_index_size[2];
  int32_T c4_locs_size[2];
  int32_T c4_right_base_size[2];
  int32_T c4_b_actual_left_lane_index_size[1];
  int32_T c4_b_actual_right_lane_index_size[1];
  int32_T c4_b_tmp_size[1];
  int32_T c4_c_actual_left_lane_index_size[1];
  int32_T c4_c_actual_right_lane_index_size[1];
  int32_T c4_c_tmp_size[1];
  int32_T c4_d_tmp_size[1];
  int32_T c4_e_tmp_size[1];
  int32_T c4_f_tmp_size[1];
  int32_T c4_good_leftx_indexs_size[1];
  int32_T c4_good_lefty_indexs_size[1];
  int32_T c4_good_rightx_indexs_size[1];
  int32_T c4_good_righty_indexs_size[1];
  int32_T c4_ii_size[1];
  int32_T c4_jj_size[1];
  int32_T c4_nonzerox_size[1];
  int32_T c4_nonzeroy_size[1];
  int32_T c4_tmp_size[1];
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
  int32_T c4_i8;
  int32_T c4_i9;
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
  int32_T c4_r_i;
  int32_T c4_r_loop_ub;
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

  c4_b_st.site = &c4_id_emlrtRSI;
  c4_findpeaks(chartInstance, &c4_b_st, c4_base, c4_right_base_data,
               c4_right_base_size, c4_locs_data, c4_locs_size);
  c4_i6 = 1;
  if ((c4_i6 < 1) || (c4_i6 > c4_locs_size[1])) {
    emlrtDynamicBoundsCheckR2012b(c4_i6, 1, c4_locs_size[1], &c4_k_emlrtBCI,
      &c4_st);
  }

  c4_end = c4_locs_size[1];
  c4_trueCount = 0;
  for (c4_d_i = 0; c4_d_i < c4_end; c4_d_i++) {
    if (c4_locs_data[c4_d_i] - c4_locs_data[0] > 200.0) {
      c4_trueCount++;
    }
  }

  c4_right_base_size[1] = c4_trueCount;
  c4_partialTrueCount = 0;
  for (c4_e_i = 0; c4_e_i < c4_end; c4_e_i++) {
    if (c4_locs_data[c4_e_i] - c4_locs_data[0] > 200.0) {
      c4_i7 = c4_locs_size[1] - 1;
      c4_b_d1 = static_cast<real_T>(c4_e_i);
      if (c4_b_d1 != static_cast<real_T>(static_cast<int32_T>
           (muDoubleScalarFloor(c4_b_d1)))) {
        emlrtIntegerCheckR2012b(c4_b_d1, &c4_h_emlrtDCI, &c4_st);
      }

      c4_i9 = static_cast<int32_T>(muDoubleScalarFloor(c4_b_d1));
      if ((c4_i9 < 0) || (c4_i9 > c4_i7)) {
        emlrtDynamicBoundsCheckR2012b(c4_i9, 0, c4_i7, &c4_p_emlrtBCI, &c4_st);
      }

      c4_right_base_data[c4_partialTrueCount] = c4_locs_data[c4_i9];
      c4_partialTrueCount++;
    }
  }

  if (c4_right_base_size[1] < 0) {
    emlrtDynamicBoundsCheckR2012b(c4_right_base_size[1], 0, MAX_int32_T,
      &c4_o_emlrtBCI, &c4_st);
  }

  c4_d = static_cast<real_T>(c4_right_base_size[1]);
  if (c4_d != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor(c4_d))))
  {
    emlrtIntegerCheckR2012b(c4_d, &c4_g_emlrtDCI, &c4_st);
  }

  c4_i8 = static_cast<int32_T>(c4_d);
  if ((c4_i8 < 1) || (c4_i8 > c4_right_base_size[1])) {
    emlrtDynamicBoundsCheckR2012b(c4_i8, 1, c4_right_base_size[1],
      &c4_m_emlrtBCI, &c4_st);
  }

  c4_right_base = c4_right_base_data[c4_i8 - 1];
  c4_leftx_current = c4_locs_data[0];
  c4_rightx_current = c4_right_base;
  for (c4_i10 = 0; c4_i10 < 200000; c4_i10++) {
    chartInstance->c4_left_lane_index[c4_i10] = 0.0;
  }

  for (c4_i11 = 0; c4_i11 < 200000; c4_i11++) {
    chartInstance->c4_right_lane_index[c4_i11] = 0.0;
  }

  c4_b_st.site = &c4_jd_emlrtRSI;
  c4_c_st.site = &c4_x_emlrtRSI;
  for (c4_i12 = 0; c4_i12 < 900000; c4_i12++) {
    chartInstance->c4_bv[c4_i12] = (*chartInstance->c4_binary_image)[c4_i12];
  }

  c4_eml_find(chartInstance, &c4_c_st, chartInstance->c4_bv,
              chartInstance->c4_ii_data, c4_ii_size, chartInstance->c4_jj_data,
              c4_jj_size);
  c4_nonzeroy_size[0] = c4_ii_size[0];
  c4_loop_ub = c4_ii_size[0] - 1;
  for (c4_i13 = 0; c4_i13 <= c4_loop_ub; c4_i13++) {
    chartInstance->c4_nonzeroy_data[c4_i13] = static_cast<real_T>
      (chartInstance->c4_ii_data[c4_i13]);
  }

  c4_nonzerox_size[0] = c4_jj_size[0];
  c4_b_loop_ub = c4_jj_size[0] - 1;
  for (c4_i14 = 0; c4_i14 <= c4_b_loop_ub; c4_i14++) {
    chartInstance->c4_nonzerox_data[c4_i14] = static_cast<real_T>
      (chartInstance->c4_jj_data[c4_i14]);
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

    c4_i19 = static_cast<int32_T>(c4_d2);
    if ((c4_i19 < 1) || (c4_i19 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c4_i19, 1, 20, &c4_i_emlrtBCI, &c4_st);
    }

    c4_d3 = 11.0 + c4_g_i;
    if (c4_d3 != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
          (c4_d3)))) {
      emlrtIntegerCheckR2012b(c4_d3, &c4_f_emlrtDCI, &c4_st);
    }

    c4_i22 = static_cast<int32_T>(c4_d3);
    if ((c4_i22 < 1) || (c4_i22 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c4_i22, 1, 20, &c4_j_emlrtBCI, &c4_st);
    }

    c4_tmp_size[0] = c4_nonzeroy_size[0];
    c4_d_loop_ub = c4_nonzeroy_size[0] - 1;
    for (c4_i26 = 0; c4_i26 <= c4_d_loop_ub; c4_i26++) {
      chartInstance->c4_tmp_data[c4_i26] = (chartInstance->
        c4_nonzeroy_data[c4_i26] >= c4_win_y_low);
    }

    c4_b_tmp_size[0] = c4_nonzeroy_size[0];
    c4_g_loop_ub = c4_nonzeroy_size[0] - 1;
    for (c4_i29 = 0; c4_i29 <= c4_g_loop_ub; c4_i29++) {
      chartInstance->c4_b_tmp_data[c4_i29] = (chartInstance->
        c4_nonzeroy_data[c4_i29] < c4_win_y_high);
    }

    if (c4_tmp_size[0] != c4_b_tmp_size[0]) {
      emlrtSizeEqCheck1DR2012b(c4_tmp_size[0], c4_b_tmp_size[0], &c4_emlrtECI,
        &c4_st);
    }

    c4_i_loop_ub = c4_tmp_size[0] - 1;
    for (c4_i31 = 0; c4_i31 <= c4_i_loop_ub; c4_i31++) {
      chartInstance->c4_tmp_data[c4_i31] = (chartInstance->c4_tmp_data[c4_i31] &&
        chartInstance->c4_b_tmp_data[c4_i31]);
    }

    c4_b_tmp_size[0] = c4_nonzerox_size[0];
    c4_k_loop_ub = c4_nonzerox_size[0] - 1;
    for (c4_i33 = 0; c4_i33 <= c4_k_loop_ub; c4_i33++) {
      chartInstance->c4_b_tmp_data[c4_i33] = (chartInstance->
        c4_nonzerox_data[c4_i33] >= c4_win_xleft_low);
    }

    if ((c4_tmp_size[0] != c4_b_tmp_size[0]) && ((c4_tmp_size[0] != 1) &&
         (c4_b_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_tmp_size[0], c4_b_tmp_size[0],
        &c4_b_emlrtECI, &c4_st);
    }

    if (c4_tmp_size[0] == c4_b_tmp_size[0]) {
      c4_o_loop_ub = c4_tmp_size[0] - 1;
      for (c4_i35 = 0; c4_i35 <= c4_o_loop_ub; c4_i35++) {
        chartInstance->c4_tmp_data[c4_i35] = (chartInstance->c4_tmp_data[c4_i35]
          && chartInstance->c4_b_tmp_data[c4_i35]);
      }
    } else {
      c4_b_and(chartInstance, chartInstance->c4_tmp_data, c4_tmp_size,
               chartInstance->c4_b_tmp_data, c4_b_tmp_size);
    }

    c4_b_tmp_size[0] = c4_nonzerox_size[0];
    c4_p_loop_ub = c4_nonzerox_size[0] - 1;
    for (c4_i37 = 0; c4_i37 <= c4_p_loop_ub; c4_i37++) {
      chartInstance->c4_b_tmp_data[c4_i37] = (chartInstance->
        c4_nonzerox_data[c4_i37] < c4_win_xleft_high);
    }

    if ((c4_tmp_size[0] != c4_b_tmp_size[0]) && ((c4_tmp_size[0] != 1) &&
         (c4_b_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_tmp_size[0], c4_b_tmp_size[0],
        &c4_b_emlrtECI, &c4_st);
    }

    if (c4_tmp_size[0] == c4_b_tmp_size[0]) {
      c4_c_tmp_size[0] = c4_tmp_size[0];
      c4_q_loop_ub = c4_tmp_size[0] - 1;
      for (c4_i40 = 0; c4_i40 <= c4_q_loop_ub; c4_i40++) {
        chartInstance->c4_c_tmp_data[c4_i40] = (chartInstance->
          c4_tmp_data[c4_i40] && chartInstance->c4_b_tmp_data[c4_i40]);
      }
    } else {
      c4_and(chartInstance, chartInstance->c4_c_tmp_data, c4_c_tmp_size,
             chartInstance->c4_tmp_data, c4_tmp_size,
             chartInstance->c4_b_tmp_data, c4_b_tmp_size);
    }

    c4_b_end = c4_c_tmp_size[0];
    c4_b_trueCount = 0;
    for (c4_h_i = 0; c4_h_i < c4_b_end; c4_h_i++) {
      if (chartInstance->c4_c_tmp_data[c4_h_i]) {
        c4_b_trueCount++;
      }
    }

    c4_good_leftx_indexs_size[0] = c4_b_trueCount;
    c4_b_partialTrueCount = 0;
    for (c4_j_i = 0; c4_j_i < c4_b_end; c4_j_i++) {
      if (chartInstance->c4_c_tmp_data[c4_j_i]) {
        c4_i42 = c4_nonzerox_size[0] - 1;
        c4_d4 = static_cast<real_T>(c4_j_i);
        if (c4_d4 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d4)))) {
          emlrtIntegerCheckR2012b(c4_d4, &c4_i_emlrtDCI, &c4_st);
        }

        c4_i44 = static_cast<int32_T>(muDoubleScalarFloor(c4_d4));
        if ((c4_i44 < 0) || (c4_i44 > c4_i42)) {
          emlrtDynamicBoundsCheckR2012b(c4_i44, 0, c4_i42, &c4_q_emlrtBCI,
            &c4_st);
        }

        chartInstance->c4_good_leftx_indexs_data[c4_b_partialTrueCount] =
          chartInstance->c4_nonzerox_data[c4_i44];
        c4_b_partialTrueCount++;
      }
    }

    c4_tmp_size[0] = c4_nonzeroy_size[0];
    c4_r_loop_ub = c4_nonzeroy_size[0] - 1;
    for (c4_i43 = 0; c4_i43 <= c4_r_loop_ub; c4_i43++) {
      chartInstance->c4_tmp_data[c4_i43] = (chartInstance->
        c4_nonzeroy_data[c4_i43] >= c4_win_y_low);
    }

    c4_b_tmp_size[0] = c4_nonzeroy_size[0];
    c4_s_loop_ub = c4_nonzeroy_size[0] - 1;
    for (c4_i45 = 0; c4_i45 <= c4_s_loop_ub; c4_i45++) {
      chartInstance->c4_b_tmp_data[c4_i45] = (chartInstance->
        c4_nonzeroy_data[c4_i45] < c4_win_y_high);
    }

    if (c4_tmp_size[0] != c4_b_tmp_size[0]) {
      emlrtSizeEqCheck1DR2012b(c4_tmp_size[0], c4_b_tmp_size[0], &c4_c_emlrtECI,
        &c4_st);
    }

    c4_t_loop_ub = c4_tmp_size[0] - 1;
    for (c4_i46 = 0; c4_i46 <= c4_t_loop_ub; c4_i46++) {
      chartInstance->c4_tmp_data[c4_i46] = (chartInstance->c4_tmp_data[c4_i46] &&
        chartInstance->c4_b_tmp_data[c4_i46]);
    }

    c4_b_tmp_size[0] = c4_nonzerox_size[0];
    c4_u_loop_ub = c4_nonzerox_size[0] - 1;
    for (c4_i47 = 0; c4_i47 <= c4_u_loop_ub; c4_i47++) {
      chartInstance->c4_b_tmp_data[c4_i47] = (chartInstance->
        c4_nonzerox_data[c4_i47] >= c4_win_xleft_low);
    }

    if ((c4_tmp_size[0] != c4_b_tmp_size[0]) && ((c4_tmp_size[0] != 1) &&
         (c4_b_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_tmp_size[0], c4_b_tmp_size[0],
        &c4_d_emlrtECI, &c4_st);
    }

    if (c4_tmp_size[0] == c4_b_tmp_size[0]) {
      c4_v_loop_ub = c4_tmp_size[0] - 1;
      for (c4_i48 = 0; c4_i48 <= c4_v_loop_ub; c4_i48++) {
        chartInstance->c4_tmp_data[c4_i48] = (chartInstance->c4_tmp_data[c4_i48]
          && chartInstance->c4_b_tmp_data[c4_i48]);
      }
    } else {
      c4_b_and(chartInstance, chartInstance->c4_tmp_data, c4_tmp_size,
               chartInstance->c4_b_tmp_data, c4_b_tmp_size);
    }

    c4_b_tmp_size[0] = c4_nonzerox_size[0];
    c4_w_loop_ub = c4_nonzerox_size[0] - 1;
    for (c4_i49 = 0; c4_i49 <= c4_w_loop_ub; c4_i49++) {
      chartInstance->c4_b_tmp_data[c4_i49] = (chartInstance->
        c4_nonzerox_data[c4_i49] < c4_win_xleft_high);
    }

    if ((c4_tmp_size[0] != c4_b_tmp_size[0]) && ((c4_tmp_size[0] != 1) &&
         (c4_b_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_tmp_size[0], c4_b_tmp_size[0],
        &c4_d_emlrtECI, &c4_st);
    }

    if (c4_tmp_size[0] == c4_b_tmp_size[0]) {
      c4_d_tmp_size[0] = c4_tmp_size[0];
      c4_x_loop_ub = c4_tmp_size[0] - 1;
      for (c4_i50 = 0; c4_i50 <= c4_x_loop_ub; c4_i50++) {
        chartInstance->c4_d_tmp_data[c4_i50] = (chartInstance->
          c4_tmp_data[c4_i50] && chartInstance->c4_b_tmp_data[c4_i50]);
      }
    } else {
      c4_and(chartInstance, chartInstance->c4_d_tmp_data, c4_d_tmp_size,
             chartInstance->c4_tmp_data, c4_tmp_size,
             chartInstance->c4_b_tmp_data, c4_b_tmp_size);
    }

    c4_c_end = c4_d_tmp_size[0];
    c4_c_trueCount = 0;
    for (c4_k_i = 0; c4_k_i < c4_c_end; c4_k_i++) {
      if (chartInstance->c4_d_tmp_data[c4_k_i]) {
        c4_c_trueCount++;
      }
    }

    c4_good_lefty_indexs_size[0] = c4_c_trueCount;
    c4_c_partialTrueCount = 0;
    for (c4_m_i = 0; c4_m_i < c4_c_end; c4_m_i++) {
      if (chartInstance->c4_d_tmp_data[c4_m_i]) {
        c4_i51 = c4_nonzeroy_size[0] - 1;
        c4_d5 = static_cast<real_T>(c4_m_i);
        if (c4_d5 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d5)))) {
          emlrtIntegerCheckR2012b(c4_d5, &c4_j_emlrtDCI, &c4_st);
        }

        c4_i53 = static_cast<int32_T>(muDoubleScalarFloor(c4_d5));
        if ((c4_i53 < 0) || (c4_i53 > c4_i51)) {
          emlrtDynamicBoundsCheckR2012b(c4_i53, 0, c4_i51, &c4_r_emlrtBCI,
            &c4_st);
        }

        chartInstance->c4_good_lefty_indexs_data[c4_c_partialTrueCount] =
          chartInstance->c4_nonzeroy_data[c4_i53];
        c4_c_partialTrueCount++;
      }
    }

    c4_tmp_size[0] = c4_nonzeroy_size[0];
    c4_y_loop_ub = c4_nonzeroy_size[0] - 1;
    for (c4_i52 = 0; c4_i52 <= c4_y_loop_ub; c4_i52++) {
      chartInstance->c4_tmp_data[c4_i52] = (chartInstance->
        c4_nonzeroy_data[c4_i52] >= c4_win_y_low);
    }

    c4_b_tmp_size[0] = c4_nonzeroy_size[0];
    c4_ab_loop_ub = c4_nonzeroy_size[0] - 1;
    for (c4_i54 = 0; c4_i54 <= c4_ab_loop_ub; c4_i54++) {
      chartInstance->c4_b_tmp_data[c4_i54] = (chartInstance->
        c4_nonzeroy_data[c4_i54] < c4_win_y_high);
    }

    if (c4_tmp_size[0] != c4_b_tmp_size[0]) {
      emlrtSizeEqCheck1DR2012b(c4_tmp_size[0], c4_b_tmp_size[0], &c4_e_emlrtECI,
        &c4_st);
    }

    c4_bb_loop_ub = c4_tmp_size[0] - 1;
    for (c4_i55 = 0; c4_i55 <= c4_bb_loop_ub; c4_i55++) {
      chartInstance->c4_tmp_data[c4_i55] = (chartInstance->c4_tmp_data[c4_i55] &&
        chartInstance->c4_b_tmp_data[c4_i55]);
    }

    c4_b_tmp_size[0] = c4_nonzerox_size[0];
    c4_cb_loop_ub = c4_nonzerox_size[0] - 1;
    for (c4_i56 = 0; c4_i56 <= c4_cb_loop_ub; c4_i56++) {
      chartInstance->c4_b_tmp_data[c4_i56] = (chartInstance->
        c4_nonzerox_data[c4_i56] >= c4_win_xright_low);
    }

    if ((c4_tmp_size[0] != c4_b_tmp_size[0]) && ((c4_tmp_size[0] != 1) &&
         (c4_b_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_tmp_size[0], c4_b_tmp_size[0],
        &c4_f_emlrtECI, &c4_st);
    }

    if (c4_tmp_size[0] == c4_b_tmp_size[0]) {
      c4_db_loop_ub = c4_tmp_size[0] - 1;
      for (c4_i57 = 0; c4_i57 <= c4_db_loop_ub; c4_i57++) {
        chartInstance->c4_tmp_data[c4_i57] = (chartInstance->c4_tmp_data[c4_i57]
          && chartInstance->c4_b_tmp_data[c4_i57]);
      }
    } else {
      c4_b_and(chartInstance, chartInstance->c4_tmp_data, c4_tmp_size,
               chartInstance->c4_b_tmp_data, c4_b_tmp_size);
    }

    c4_b_tmp_size[0] = c4_nonzerox_size[0];
    c4_eb_loop_ub = c4_nonzerox_size[0] - 1;
    for (c4_i58 = 0; c4_i58 <= c4_eb_loop_ub; c4_i58++) {
      chartInstance->c4_b_tmp_data[c4_i58] = (chartInstance->
        c4_nonzerox_data[c4_i58] < c4_win_xright_high);
    }

    if ((c4_tmp_size[0] != c4_b_tmp_size[0]) && ((c4_tmp_size[0] != 1) &&
         (c4_b_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_tmp_size[0], c4_b_tmp_size[0],
        &c4_f_emlrtECI, &c4_st);
    }

    if (c4_tmp_size[0] == c4_b_tmp_size[0]) {
      c4_e_tmp_size[0] = c4_tmp_size[0];
      c4_fb_loop_ub = c4_tmp_size[0] - 1;
      for (c4_i59 = 0; c4_i59 <= c4_fb_loop_ub; c4_i59++) {
        chartInstance->c4_e_tmp_data[c4_i59] = (chartInstance->
          c4_tmp_data[c4_i59] && chartInstance->c4_b_tmp_data[c4_i59]);
      }
    } else {
      c4_and(chartInstance, chartInstance->c4_e_tmp_data, c4_e_tmp_size,
             chartInstance->c4_tmp_data, c4_tmp_size,
             chartInstance->c4_b_tmp_data, c4_b_tmp_size);
    }

    c4_d_end = c4_e_tmp_size[0];
    c4_d_trueCount = 0;
    for (c4_o_i = 0; c4_o_i < c4_d_end; c4_o_i++) {
      if (chartInstance->c4_e_tmp_data[c4_o_i]) {
        c4_d_trueCount++;
      }
    }

    c4_good_rightx_indexs_size[0] = c4_d_trueCount;
    c4_d_partialTrueCount = 0;
    for (c4_p_i = 0; c4_p_i < c4_d_end; c4_p_i++) {
      if (chartInstance->c4_e_tmp_data[c4_p_i]) {
        c4_i60 = c4_nonzerox_size[0] - 1;
        c4_d6 = static_cast<real_T>(c4_p_i);
        if (c4_d6 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d6)))) {
          emlrtIntegerCheckR2012b(c4_d6, &c4_k_emlrtDCI, &c4_st);
        }

        c4_i62 = static_cast<int32_T>(muDoubleScalarFloor(c4_d6));
        if ((c4_i62 < 0) || (c4_i62 > c4_i60)) {
          emlrtDynamicBoundsCheckR2012b(c4_i62, 0, c4_i60, &c4_s_emlrtBCI,
            &c4_st);
        }

        chartInstance->c4_good_rightx_indexs_data[c4_d_partialTrueCount] =
          chartInstance->c4_nonzerox_data[c4_i62];
        c4_d_partialTrueCount++;
      }
    }

    c4_tmp_size[0] = c4_nonzeroy_size[0];
    c4_gb_loop_ub = c4_nonzeroy_size[0] - 1;
    for (c4_i61 = 0; c4_i61 <= c4_gb_loop_ub; c4_i61++) {
      chartInstance->c4_tmp_data[c4_i61] = (chartInstance->
        c4_nonzeroy_data[c4_i61] >= c4_win_y_low);
    }

    c4_b_tmp_size[0] = c4_nonzeroy_size[0];
    c4_hb_loop_ub = c4_nonzeroy_size[0] - 1;
    for (c4_i63 = 0; c4_i63 <= c4_hb_loop_ub; c4_i63++) {
      chartInstance->c4_b_tmp_data[c4_i63] = (chartInstance->
        c4_nonzeroy_data[c4_i63] < c4_win_y_high);
    }

    if (c4_tmp_size[0] != c4_b_tmp_size[0]) {
      emlrtSizeEqCheck1DR2012b(c4_tmp_size[0], c4_b_tmp_size[0], &c4_g_emlrtECI,
        &c4_st);
    }

    c4_ib_loop_ub = c4_tmp_size[0] - 1;
    for (c4_i64 = 0; c4_i64 <= c4_ib_loop_ub; c4_i64++) {
      chartInstance->c4_tmp_data[c4_i64] = (chartInstance->c4_tmp_data[c4_i64] &&
        chartInstance->c4_b_tmp_data[c4_i64]);
    }

    c4_b_tmp_size[0] = c4_nonzerox_size[0];
    c4_jb_loop_ub = c4_nonzerox_size[0] - 1;
    for (c4_i65 = 0; c4_i65 <= c4_jb_loop_ub; c4_i65++) {
      chartInstance->c4_b_tmp_data[c4_i65] = (chartInstance->
        c4_nonzerox_data[c4_i65] >= c4_win_xright_low);
    }

    if ((c4_tmp_size[0] != c4_b_tmp_size[0]) && ((c4_tmp_size[0] != 1) &&
         (c4_b_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_tmp_size[0], c4_b_tmp_size[0],
        &c4_h_emlrtECI, &c4_st);
    }

    if (c4_tmp_size[0] == c4_b_tmp_size[0]) {
      c4_kb_loop_ub = c4_tmp_size[0] - 1;
      for (c4_i66 = 0; c4_i66 <= c4_kb_loop_ub; c4_i66++) {
        chartInstance->c4_tmp_data[c4_i66] = (chartInstance->c4_tmp_data[c4_i66]
          && chartInstance->c4_b_tmp_data[c4_i66]);
      }
    } else {
      c4_b_and(chartInstance, chartInstance->c4_tmp_data, c4_tmp_size,
               chartInstance->c4_b_tmp_data, c4_b_tmp_size);
    }

    c4_b_tmp_size[0] = c4_nonzerox_size[0];
    c4_mb_loop_ub = c4_nonzerox_size[0] - 1;
    for (c4_i67 = 0; c4_i67 <= c4_mb_loop_ub; c4_i67++) {
      chartInstance->c4_b_tmp_data[c4_i67] = (chartInstance->
        c4_nonzerox_data[c4_i67] < c4_win_xright_high);
    }

    if ((c4_tmp_size[0] != c4_b_tmp_size[0]) && ((c4_tmp_size[0] != 1) &&
         (c4_b_tmp_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(c4_tmp_size[0], c4_b_tmp_size[0],
        &c4_h_emlrtECI, &c4_st);
    }

    if (c4_tmp_size[0] == c4_b_tmp_size[0]) {
      c4_f_tmp_size[0] = c4_tmp_size[0];
      c4_ob_loop_ub = c4_tmp_size[0] - 1;
      for (c4_i68 = 0; c4_i68 <= c4_ob_loop_ub; c4_i68++) {
        chartInstance->c4_f_tmp_data[c4_i68] = (chartInstance->
          c4_tmp_data[c4_i68] && chartInstance->c4_b_tmp_data[c4_i68]);
      }
    } else {
      c4_and(chartInstance, chartInstance->c4_f_tmp_data, c4_f_tmp_size,
             chartInstance->c4_tmp_data, c4_tmp_size,
             chartInstance->c4_b_tmp_data, c4_b_tmp_size);
    }

    c4_e_end = c4_f_tmp_size[0];
    c4_e_trueCount = 0;
    for (c4_q_i = 0; c4_q_i < c4_e_end; c4_q_i++) {
      if (chartInstance->c4_f_tmp_data[c4_q_i]) {
        c4_e_trueCount++;
      }
    }

    c4_good_righty_indexs_size[0] = c4_e_trueCount;
    c4_e_partialTrueCount = 0;
    for (c4_r_i = 0; c4_r_i < c4_e_end; c4_r_i++) {
      if (chartInstance->c4_f_tmp_data[c4_r_i]) {
        c4_i69 = c4_nonzeroy_size[0] - 1;
        c4_d8 = static_cast<real_T>(c4_r_i);
        if (c4_d8 != static_cast<real_T>(static_cast<int32_T>
             (muDoubleScalarFloor(c4_d8)))) {
          emlrtIntegerCheckR2012b(c4_d8, &c4_m_emlrtDCI, &c4_st);
        }

        c4_i71 = static_cast<int32_T>(muDoubleScalarFloor(c4_d8));
        if ((c4_i71 < 0) || (c4_i71 > c4_i69)) {
          emlrtDynamicBoundsCheckR2012b(c4_i71, 0, c4_i69, &c4_t_emlrtBCI,
            &c4_st);
        }

        chartInstance->c4_good_righty_indexs_data[c4_e_partialTrueCount] =
          chartInstance->c4_nonzeroy_data[c4_i71];
        c4_e_partialTrueCount++;
      }
    }

    c4_d7 = c4_count_left + 1.0;
    if (c4_good_leftx_indexs_size[0] < 0) {
      emlrtDynamicBoundsCheckR2012b(c4_good_leftx_indexs_size[0], 0, MAX_int32_T,
        &c4_emlrtBCI, &c4_st);
    }

    c4_d9 = static_cast<real_T>(c4_good_leftx_indexs_size[0]);
    c4_i70 = static_cast<int32_T>(c4_d9 + (1.0 - c4_d7));
    emlrtForLoopVectorCheckR2021a(c4_d7, 1.0, c4_d9, mxDOUBLE_CLASS, c4_i70,
      &c4_uc_emlrtRTEI, &c4_st);
    for (c4_j = 0; c4_j < c4_i70; c4_j++) {
      c4_b_j = c4_d7 + static_cast<real_T>(c4_j);
      covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 1, 1);
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_emlrtDCI, &c4_st);
      }

      c4_i72 = static_cast<int32_T>(c4_b_j);
      if ((c4_i72 < 1) || (c4_i72 > 100000)) {
        emlrtDynamicBoundsCheckR2012b(c4_i72, 1, 100000, &c4_e_emlrtBCI, &c4_st);
      }

      c4_d_j = c4_i72 - 1;
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_o_emlrtDCI, &c4_st);
      }

      c4_i74 = static_cast<int32_T>(c4_b_j);
      if ((c4_i74 < 1) || (c4_i74 > c4_good_leftx_indexs_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c4_i74, 1, c4_good_leftx_indexs_size[0],
          &c4_u_emlrtBCI, &c4_st);
      }

      chartInstance->c4_left_lane_index[c4_d_j] =
        chartInstance->c4_good_leftx_indexs_data[c4_i74 - 1];
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_p_emlrtDCI, &c4_st);
      }

      c4_i76 = static_cast<int32_T>(c4_b_j);
      if ((c4_i76 < 1) || (c4_i76 > c4_good_lefty_indexs_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c4_i76, 1, c4_good_lefty_indexs_size[0],
          &c4_v_emlrtBCI, &c4_st);
      }

      chartInstance->c4_left_lane_index[100000 + c4_d_j] =
        chartInstance->c4_good_lefty_indexs_data[c4_i76 - 1];
      c4_count_left++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 1, 0);
    c4_d10 = c4_count_right + 1.0;
    if (c4_good_rightx_indexs_size[0] < 0) {
      emlrtDynamicBoundsCheckR2012b(c4_good_rightx_indexs_size[0], 0,
        MAX_int32_T, &c4_b_emlrtBCI, &c4_st);
    }

    c4_d11 = static_cast<real_T>(c4_good_rightx_indexs_size[0]);
    c4_i73 = static_cast<int32_T>(c4_d11 + (1.0 - c4_d10));
    emlrtForLoopVectorCheckR2021a(c4_d10, 1.0, c4_d11, mxDOUBLE_CLASS, c4_i73,
      &c4_vc_emlrtRTEI, &c4_st);
    for (c4_c_j = 0; c4_c_j < c4_i73; c4_c_j++) {
      c4_b_j = c4_d10 + static_cast<real_T>(c4_c_j);
      covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 2, 1);
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_c_emlrtDCI, &c4_st);
      }

      c4_i75 = static_cast<int32_T>(c4_b_j);
      if ((c4_i75 < 1) || (c4_i75 > 100000)) {
        emlrtDynamicBoundsCheckR2012b(c4_i75, 1, 100000, &c4_g_emlrtBCI, &c4_st);
      }

      c4_e_j = c4_i75 - 1;
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_q_emlrtDCI, &c4_st);
      }

      c4_i77 = static_cast<int32_T>(c4_b_j);
      if ((c4_i77 < 1) || (c4_i77 > c4_good_rightx_indexs_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c4_i77, 1, c4_good_rightx_indexs_size[0],
          &c4_w_emlrtBCI, &c4_st);
      }

      chartInstance->c4_right_lane_index[c4_e_j] =
        chartInstance->c4_good_rightx_indexs_data[c4_i77 - 1];
      if (c4_b_j != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_b_j)))) {
        emlrtIntegerCheckR2012b(c4_b_j, &c4_r_emlrtDCI, &c4_st);
      }

      c4_i78 = static_cast<int32_T>(c4_b_j);
      if ((c4_i78 < 1) || (c4_i78 > c4_good_righty_indexs_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c4_i78, 1, c4_good_righty_indexs_size[0],
          &c4_x_emlrtBCI, &c4_st);
      }

      chartInstance->c4_right_lane_index[100000 + c4_e_j] =
        chartInstance->c4_good_righty_indexs_data[c4_i78 - 1];
      c4_count_right++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 2, 0);
    if (c4_good_leftx_indexs_size[0] < 0) {
      emlrtDynamicBoundsCheckR2012b(c4_good_leftx_indexs_size[0], 0, MAX_int32_T,
        &c4_c_emlrtBCI, &c4_st);
    }

    c4_d12 = static_cast<real_T>(c4_good_leftx_indexs_size[0]);
    if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 0,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c4_covrtInstance, 4U, 0U, 0U, c4_d12,
                        40.0, -1, 4U, static_cast<int32_T>(c4_d12 > 40.0)))) {
      c4_b_st.site = &c4_kd_emlrtRSI;
      c4_leftx_current = c4_mean(chartInstance, &c4_b_st,
        chartInstance->c4_good_leftx_indexs_data, c4_good_leftx_indexs_size);
    }

    if (c4_good_rightx_indexs_size[0] < 0) {
      emlrtDynamicBoundsCheckR2012b(c4_good_rightx_indexs_size[0], 0,
        MAX_int32_T, &c4_d_emlrtBCI, &c4_st);
    }

    c4_d13 = static_cast<real_T>(c4_good_rightx_indexs_size[0]);
    if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 1,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c4_covrtInstance, 4U, 0U, 1U, c4_d13,
                        40.0, -1, 4U, static_cast<int32_T>(c4_d13 > 40.0)))) {
      c4_b_st.site = &c4_md_emlrtRSI;
      c4_rightx_current = c4_mean(chartInstance, &c4_b_st,
        chartInstance->c4_good_rightx_indexs_data, c4_good_rightx_indexs_size);
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 0, 0);
  c4_b_b = (c4_count_left < 1.0);
  c4_b_b1 = c4_b_b;
  c4_b2 = false;
  c4_b3 = (c4_b_b1 || c4_b2);
  if (c4_b3) {
    c4_i15 = 1;
    c4_i16 = 0;
  } else {
    c4_i15 = 1;
    if (c4_count_left != static_cast<real_T>(static_cast<int32_T>
         (muDoubleScalarFloor(c4_count_left)))) {
      emlrtIntegerCheckR2012b(c4_count_left, &c4_b_emlrtDCI, &c4_st);
    }

    c4_i17 = static_cast<int32_T>(c4_count_left);
    if ((c4_i17 < 1) || (c4_i17 > 100000)) {
      emlrtDynamicBoundsCheckR2012b(c4_i17, 1, 100000, &c4_f_emlrtBCI, &c4_st);
    }

    c4_i16 = c4_i17;
  }

  c4_actual_left_lane_index_size[0] = (c4_i16 - c4_i15) + 1;
  for (c4_i18 = 0; c4_i18 < 2; c4_i18++) {
    c4_c_loop_ub = c4_i16 - c4_i15;
    for (c4_i20 = 0; c4_i20 <= c4_c_loop_ub; c4_i20++) {
      chartInstance->c4_actual_left_lane_index_data[c4_i20 +
        c4_actual_left_lane_index_size[0] * c4_i18] =
        chartInstance->c4_left_lane_index[((c4_i15 + c4_i20) + 100000 * c4_i18)
        - 1];
    }
  }

  c4_b4 = (c4_count_right < 1.0);
  c4_b5 = c4_b4;
  c4_b6 = false;
  c4_b7 = (c4_b5 || c4_b6);
  if (c4_b7) {
    c4_i21 = 1;
    c4_i23 = 0;
  } else {
    c4_i21 = 1;
    if (c4_count_right != static_cast<real_T>(static_cast<int32_T>
         (muDoubleScalarFloor(c4_count_right)))) {
      emlrtIntegerCheckR2012b(c4_count_right, &c4_d_emlrtDCI, &c4_st);
    }

    c4_i24 = static_cast<int32_T>(c4_count_right);
    if ((c4_i24 < 1) || (c4_i24 > 100000)) {
      emlrtDynamicBoundsCheckR2012b(c4_i24, 1, 100000, &c4_h_emlrtBCI, &c4_st);
    }

    c4_i23 = c4_i24;
  }

  c4_actual_right_lane_index_size[0] = (c4_i23 - c4_i21) + 1;
  for (c4_i25 = 0; c4_i25 < 2; c4_i25++) {
    c4_e_loop_ub = c4_i23 - c4_i21;
    for (c4_i27 = 0; c4_i27 <= c4_e_loop_ub; c4_i27++) {
      chartInstance->c4_actual_right_lane_index_data[c4_i27 +
        c4_actual_right_lane_index_size[0] * c4_i25] =
        chartInstance->c4_right_lane_index[((c4_i21 + c4_i27) + 100000 * c4_i25)
        - 1];
    }
  }

  c4_b_actual_left_lane_index_size[0] = c4_actual_left_lane_index_size[0];
  c4_f_loop_ub = c4_actual_left_lane_index_size[0] - 1;
  for (c4_i28 = 0; c4_i28 <= c4_f_loop_ub; c4_i28++) {
    chartInstance->c4_b_actual_left_lane_index_data[c4_i28] =
      chartInstance->c4_actual_left_lane_index_data[c4_i28 +
      c4_actual_left_lane_index_size[0]];
  }

  c4_c_actual_left_lane_index_size[0] = c4_actual_left_lane_index_size[0];
  c4_h_loop_ub = c4_actual_left_lane_index_size[0] - 1;
  for (c4_i30 = 0; c4_i30 <= c4_h_loop_ub; c4_i30++) {
    chartInstance->c4_c_actual_left_lane_index_data[c4_i30] =
      chartInstance->c4_actual_left_lane_index_data[c4_i30];
  }

  c4_b_st.site = &c4_od_emlrtRSI;
  c4_polyfit(chartInstance, &c4_b_st,
             chartInstance->c4_b_actual_left_lane_index_data,
             c4_b_actual_left_lane_index_size,
             chartInstance->c4_c_actual_left_lane_index_data,
             c4_c_actual_left_lane_index_size, c4_p_left);
  c4_b_actual_right_lane_index_size[0] = c4_actual_right_lane_index_size[0];
  c4_j_loop_ub = c4_actual_right_lane_index_size[0] - 1;
  for (c4_i32 = 0; c4_i32 <= c4_j_loop_ub; c4_i32++) {
    chartInstance->c4_b_actual_right_lane_index_data[c4_i32] =
      chartInstance->c4_actual_right_lane_index_data[c4_i32 +
      c4_actual_right_lane_index_size[0]];
  }

  c4_c_actual_right_lane_index_size[0] = c4_actual_right_lane_index_size[0];
  c4_m_loop_ub = c4_actual_right_lane_index_size[0] - 1;
  for (c4_i34 = 0; c4_i34 <= c4_m_loop_ub; c4_i34++) {
    chartInstance->c4_c_actual_right_lane_index_data[c4_i34] =
      chartInstance->c4_actual_right_lane_index_data[c4_i34];
  }

  c4_b_st.site = &c4_pd_emlrtRSI;
  c4_polyfit(chartInstance, &c4_b_st,
             chartInstance->c4_b_actual_right_lane_index_data,
             c4_b_actual_right_lane_index_size,
             chartInstance->c4_c_actual_right_lane_index_data,
             c4_c_actual_right_lane_index_size, c4_p_right);
  for (c4_i36 = 0; c4_i36 < 751; c4_i36++) {
    c4_xleft[c4_i36] = c4_p_left[0];
  }

  for (c4_b_k = 0; c4_b_k < 2; c4_b_k++) {
    c4_c_k = static_cast<real_T>(c4_b_k) + 2.0;
    c4_b_p_left = c4_p_left[static_cast<int32_T>(c4_c_k) - 1];
    for (c4_i39 = 0; c4_i39 < 751; c4_i39++) {
      c4_xleft[c4_i39] = static_cast<real_T>(c4_i39) * c4_xleft[c4_i39] +
        c4_b_p_left;
    }
  }

  for (c4_i38 = 0; c4_i38 < 751; c4_i38++) {
    c4_xright[c4_i38] = c4_p_right[0];
  }

  for (c4_d_k = 0; c4_d_k < 2; c4_d_k++) {
    c4_e_k = static_cast<real_T>(c4_d_k) + 2.0;
    c4_b_p_right = c4_p_right[static_cast<int32_T>(c4_e_k) - 1];
    for (c4_i41 = 0; c4_i41 < 751; c4_i41++) {
      c4_xright[c4_i41] = static_cast<real_T>(c4_i41) * c4_xright[c4_i41] +
        c4_b_p_right;
    }
  }

  c4_b_error = 600.0 - (c4_xleft[750] + c4_xright[750]) / 2.0;
  *chartInstance->c4_error = c4_b_error;
  c4_do_animation_call_c4_Perception(chartInstance);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U,
                    *chartInstance->c4_error);
}

static void ext_mode_exec_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance)
{
}

static void c4_update_jit_animation_c4_Perception(SFc4_PerceptionInstanceStruct *
  chartInstance)
{
}

static void c4_do_animation_call_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c4_Perception(SFc4_PerceptionInstanceStruct *
  chartInstance)
{
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_c_y{ nullptr };

  const mxArray *c4_st;
  const mxArray *c4_y{ nullptr };

  c4_st = nullptr;
  c4_st = nullptr;
  c4_y = nullptr;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_b_y = nullptr;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", chartInstance->c4_error, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = nullptr;
  sf_mex_assign(&c4_c_y, sf_mex_create("y",
    &chartInstance->c4_is_active_c4_Perception, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_error = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "error");
  chartInstance->c4_is_active_c4_Perception = c4_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_Perception");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void initSimStructsc4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance)
{
}

static void initSubchartIOPointersc4_Perception(SFc4_PerceptionInstanceStruct
  *chartInstance)
{
}

static void c4_findpeaks(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_Yin[1200], real_T c4_Ypk_data[], int32_T
  c4_Ypk_size[2], real_T c4_Xpk_data[], int32_T c4_Xpk_size[2])
{
  static char_T c4_b_cv[50]{ 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'c', 'o', 'l', 'o', 'n', '_', 's', 'c', 'a', 'l', 'a', 'r',
    'D', 'o', 'u', 'b', 'l', 'e', 'M', 'u', 's', 't', 'B', 'e', 'I', 'n', 't',
    'e', 'g', 'e', 'r', 'V', 'a', 'l', 'u', 'e', 'd' };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  const mxArray *c4_h_y{ nullptr };

  const mxArray *c4_j_y{ nullptr };

  real_T c4_b_Xpk_data[1200];
  real_T c4_b_Ypk_data[1200];
  real_T c4_y[1200];
  real_T c4_dv[2];
  real_T c4_a;
  real_T c4_b_a;
  real_T c4_b_d;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_base;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_d;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_e_b;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_b;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_g_b;
  real_T c4_g_x;
  real_T c4_g_y;
  real_T c4_h_x;
  real_T c4_pk;
  real_T c4_varargin_1;
  real_T c4_varargin_2;
  real_T c4_yk;
  real_T c4_ykfirst;
  int32_T c4_iPk_data[2400];
  int32_T c4_idx_data[2400];
  int32_T c4_y_data[2400];
  int32_T c4_b_iPk_data[1200];
  int32_T c4_fPk_data[1200];
  int32_T c4_iFinite_data[1200];
  int32_T c4_iInfinite_data[1200];
  int32_T c4_iv[2];
  int32_T c4_y_size[2];
  int32_T c4_b_Xpk_size[1];
  int32_T c4_b_Ypk_size[1];
  int32_T c4_b_iPk_size[1];
  int32_T c4_fPk_size[1];
  int32_T c4_iFinite_size[1];
  int32_T c4_iInfinite_size[1];
  int32_T c4_iPk_size[1];
  int32_T c4_idx_size[1];
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_n;
  int32_T c4_b_nPk;
  int32_T c4_b_yk;
  int32_T c4_bma;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_bi;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_d_a;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_e_a;
  int32_T c4_e_loop_ub;
  int32_T c4_f_a;
  int32_T c4_f_loop_ub;
  int32_T c4_g_a;
  int32_T c4_g_loop_ub;
  int32_T c4_h_a;
  int32_T c4_h_b;
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
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_iPk;
  int32_T c4_j;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_k_b;
  int32_T c4_kfirst;
  int32_T c4_loop_ub;
  int32_T c4_m_b;
  int32_T c4_n;
  int32_T c4_nInflect;
  int32_T c4_nPk;
  int32_T c4_nm1;
  int32_T c4_span;
  char_T c4_dir;
  char_T c4_previousdir;
  boolean_T c4_b;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b_b1;
  boolean_T c4_isinfykfirst;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  for (c4_i = 0; c4_i < 1200; c4_i++) {
    c4_y[c4_i] = c4_Yin[c4_i];
  }

  c4_st.site = &c4_emlrtRSI;
  c4_nPk = 0;
  c4_nInflect = 0;
  c4_dir = 'n';
  c4_kfirst = 0;
  c4_ykfirst = rtInf;
  c4_isinfykfirst = true;
  for (c4_k = 0; c4_k < 1200; c4_k++) {
    c4_yk = c4_y[c4_k];
    if (c4_yk != c4_ykfirst) {
      c4_previousdir = c4_dir;
      if (c4_isinfykfirst) {
        c4_dir = 'n';
        if (c4_kfirst >= 1) {
          c4_nInflect++;
          if ((c4_nInflect < 1) || (c4_nInflect > 1200)) {
            emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 1200, &c4_bb_emlrtBCI,
              &c4_st);
          }

          c4_fPk_data[c4_nInflect - 1] = c4_kfirst;
        }
      } else if (c4_yk < c4_ykfirst) {
        c4_dir = 'd';
        if (c4_previousdir != 'd') {
          c4_nInflect++;
          if ((c4_nInflect < 1) || (c4_nInflect > 1200)) {
            emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 1200, &c4_cb_emlrtBCI,
              &c4_st);
          }

          c4_fPk_data[c4_nInflect - 1] = c4_kfirst;
          if (c4_previousdir == 'i') {
            c4_nPk++;
            if ((c4_nPk < 1) || (c4_nPk > 1200)) {
              emlrtDynamicBoundsCheckR2012b(c4_nPk, 1, 1200, &c4_fb_emlrtBCI,
                &c4_st);
            }

            c4_iFinite_data[c4_nPk - 1] = c4_kfirst;
          }
        }
      } else {
        c4_dir = 'i';
        if (c4_previousdir != 'i') {
          c4_nInflect++;
          if ((c4_nInflect < 1) || (c4_nInflect > 1200)) {
            emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 1200, &c4_db_emlrtBCI,
              &c4_st);
          }

          c4_fPk_data[c4_nInflect - 1] = c4_kfirst;
        }
      }

      c4_ykfirst = c4_yk;
      c4_kfirst = c4_k + 1;
      c4_isinfykfirst = false;
    }
  }

  if ((!c4_isinfykfirst) && ((c4_nInflect == 0) || (c4_fPk_data[c4_nInflect - 1]
        < 1200))) {
    c4_nInflect++;
    if ((c4_nInflect < 1) || (c4_nInflect > 1200)) {
      emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 1200, &c4_eb_emlrtBCI,
        &c4_st);
    }
  }

  c4_b = (c4_nPk < 1);
  if (c4_b) {
    c4_i1 = -1;
  } else {
    if ((c4_nPk < 1) || (c4_nPk > 1200)) {
      emlrtDynamicBoundsCheckR2012b(c4_nPk, 1, 1200, &c4_gb_emlrtBCI, &c4_st);
    }

    c4_i1 = c4_nPk - 1;
  }

  c4_iFinite_size[0] = c4_i1 + 1;
  c4_iInfinite_size[0] = 0;
  c4_b_b1 = (c4_nInflect < 1);
  if ((!c4_b_b1) && ((c4_nInflect < 1) || (c4_nInflect > 1200))) {
    emlrtDynamicBoundsCheckR2012b(c4_nInflect, 1, 1200, &c4_hb_emlrtBCI, &c4_st);
  }

  c4_st.site = &c4_b_emlrtRSI;
  c4_iPk_size[0] = c4_iFinite_size[0];
  c4_b_nPk = 0;
  c4_n = c4_iFinite_size[0];
  c4_b_st.site = &c4_g_emlrtRSI;
  c4_b_b = c4_n;
  c4_c_b = c4_b_b;
  if (c4_c_b < 1) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_c_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_h_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  c4_i2 = static_cast<uint16_T>(c4_n) - 1;
  for (c4_b_k = 0; c4_b_k <= c4_i2; c4_b_k++) {
    c4_c_k = c4_b_k;
    c4_i3 = c4_c_k + 1;
    if ((c4_i3 < 1) || (c4_i3 > c4_iFinite_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i3, 1, c4_iFinite_size[0],
        &c4_kb_emlrtBCI, &c4_st);
    }

    c4_j = c4_iFinite_data[c4_i3 - 1];
    if ((c4_j < 1) || (c4_j > 1200)) {
      emlrtDynamicBoundsCheckR2012b(c4_j, 1, 1200, &c4_mb_emlrtBCI, &c4_st);
    }

    c4_pk = c4_y[c4_j - 1];
    c4_i6 = c4_j - 1;
    if ((c4_i6 < 1) || (c4_i6 > 1200)) {
      emlrtDynamicBoundsCheckR2012b(c4_i6, 1, 1200, &c4_ob_emlrtBCI, &c4_st);
    }

    c4_varargin_1 = c4_y[c4_i6 - 1];
    c4_i8 = c4_j + 1;
    if ((c4_i8 < 1) || (c4_i8 > 1200)) {
      emlrtDynamicBoundsCheckR2012b(c4_i8, 1, 1200, &c4_pb_emlrtBCI, &c4_st);
    }

    c4_varargin_2 = c4_y[c4_i8 - 1];
    c4_b_x = c4_varargin_1;
    c4_b_y = c4_varargin_2;
    c4_c_x = c4_b_x;
    c4_c_y = c4_b_y;
    c4_d_x = c4_c_x;
    c4_d_y = c4_c_y;
    c4_a = c4_d_x;
    c4_f_b = c4_d_y;
    c4_g_x = c4_a;
    c4_f_y = c4_f_b;
    c4_h_x = c4_g_x;
    c4_g_y = c4_f_y;
    c4_base = muDoubleScalarMax(c4_h_x, c4_g_y);
    if (c4_pk - c4_base >= 0.0) {
      c4_b_nPk++;
      if ((c4_b_nPk < 1) || (c4_b_nPk > c4_iPk_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c4_b_nPk, 1, c4_iPk_size[0],
          &c4_qb_emlrtBCI, &c4_st);
      }

      c4_b_iPk_data[c4_b_nPk - 1] = c4_j;
    }
  }

  c4_b2 = (c4_b_nPk < 1);
  if (c4_b2) {
    c4_i4 = 0;
  } else {
    if (c4_iPk_size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, c4_iPk_size[0], &c4_y_emlrtBCI, &c4_st);
    }

    if ((c4_b_nPk < 1) || (c4_b_nPk > c4_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_b_nPk, 1, c4_iPk_size[0], &c4_ab_emlrtBCI,
        &c4_st);
    }

    c4_i4 = c4_b_nPk;
  }

  c4_iPk_size[0] = c4_i4;
  c4_b_iPk_size[0] = c4_iPk_size[0];
  c4_loop_ub = c4_iPk_size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_loop_ub; c4_i5++) {
    c4_iPk_data[c4_i5] = c4_b_iPk_data[c4_i5];
  }

  c4_st.site = &c4_c_emlrtRSI;
  c4_iPk_size[0] = c4_b_iPk_size[0];
  c4_b_loop_ub = c4_b_iPk_size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_b_loop_ub; c4_i7++) {
    c4_b_iPk_data[c4_i7] = c4_iPk_data[c4_i7];
  }

  c4_b_st.site = &c4_i_emlrtRSI;
  c4_c_st.site = &c4_j_emlrtRSI;
  c4_d_st.site = &c4_k_emlrtRSI;
  c4_do_vectors(chartInstance, &c4_d_st, c4_b_iPk_data, c4_iPk_size,
                c4_iInfinite_data, c4_iInfinite_size, c4_iPk_data, c4_b_iPk_size,
                c4_fPk_data, c4_fPk_size, c4_iFinite_data, c4_iFinite_size);
  c4_st.site = &c4_d_emlrtRSI;
  c4_b_st.site = &c4_s_emlrtRSI;
  c4_d = static_cast<real_T>(c4_b_iPk_size[0]);
  c4_c_st.site = &c4_t_emlrtRSI;
  c4_e_b = c4_d;
  c4_e_x = c4_e_b;
  c4_f_x = c4_e_x;
  c4_e_y = c4_f_x;
  if (c4_e_y == c4_e_b) {
    c4_b3 = true;
  } else {
    c4_b3 = false;
  }

  if (!c4_b3) {
    c4_h_y = nullptr;
    sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 50),
                  false);
    c4_j_y = nullptr;
    sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 50),
                  false);
    sf_mex_call(&c4_c_st, &c4_g_emlrtMCI, "error", 0U, 2U, 14, c4_h_y, 14,
                sf_mex_call(&c4_c_st, nullptr, "getString", 1U, 1U, 14,
      sf_mex_call(&c4_c_st, nullptr, "message", 1U, 1U, 14, c4_j_y)));
  }

  c4_g_b = c4_e_b;
  c4_b_a = c4_g_b;
  c4_c_bi = static_cast<int32_T>(muDoubleScalarFloor(c4_b_a));
  c4_h_b = c4_c_bi;
  c4_j_b = c4_h_b;
  c4_k_b = c4_j_b;
  if (c4_k_b < 1) {
    c4_b_n = 0;
  } else {
    c4_c_a = c4_k_b - 1;
    c4_bma = c4_c_a;
    c4_d_a = c4_bma;
    c4_span = c4_d_a;
    c4_e_a = c4_span;
    c4_nm1 = static_cast<uint16_T>(c4_e_a);
    c4_f_a = c4_nm1;
    c4_m_b = c4_f_a;
    c4_g_a = c4_m_b + 1;
    c4_b_n = c4_g_a;
  }

  c4_y_size[1] = c4_b_n;
  if (c4_b_n > 0) {
    c4_y_data[0] = 1;
    c4_b_yk = 1;
    for (c4_d_k = 2; c4_d_k <= c4_b_n; c4_d_k++) {
      c4_h_a = c4_b_yk + 1;
      c4_b_yk = c4_h_a;
      c4_y_data[c4_d_k - 1] = c4_b_yk;
    }
  }

  c4_idx_size[0] = c4_y_size[1];
  c4_c_loop_ub = c4_y_size[1] - 1;
  for (c4_i9 = 0; c4_i9 <= c4_c_loop_ub; c4_i9++) {
    c4_idx_data[c4_i9] = c4_y_data[c4_i9];
  }

  if (static_cast<real_T>(c4_idx_size[0]) > 1200.0) {
    c4_fPk_size[0] = 1200;
    c4_st.site = &c4_e_emlrtRSI;
    c4_indexShapeCheck(chartInstance);
    c4_idx_size[0] = 1200;
  } else {
    c4_dv[0] = static_cast<real_T>(c4_idx_size[0]);
    c4_fPk_size[0] = static_cast<int32_T>(c4_dv[0]);
  }

  c4_b_d = static_cast<real_T>(c4_fPk_size[0]);
  c4_b4 = (c4_b_d < 1.0);
  if (c4_b4) {
    c4_i11 = 0;
  } else {
    c4_i10 = 1;
    if ((c4_i10 < 1) || (c4_i10 > c4_idx_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i10, 1, c4_idx_size[0], &c4_jb_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_i12 = static_cast<int32_T>(c4_b_d);
    if ((c4_i12 < 1) || (c4_i12 > c4_idx_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i12, 1, c4_idx_size[0], &c4_ib_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_i11 = c4_i12;
  }

  c4_iv[0] = 1;
  c4_iv[1] = c4_i11;
  c4_st.site = &c4_f_emlrtRSI;
  c4_b_indexShapeCheck(chartInstance, &c4_st, c4_idx_size[0], c4_iv);
  c4_iPk = c4_b_iPk_size[0];
  c4_fPk_size[0] = c4_i11;
  c4_d_loop_ub = c4_i11 - 1;
  for (c4_i13 = 0; c4_i13 <= c4_d_loop_ub; c4_i13++) {
    if ((c4_idx_data[c4_i13] < 1) || (c4_idx_data[c4_i13] > c4_iPk)) {
      emlrtDynamicBoundsCheckR2012b(c4_idx_data[c4_i13], 1, c4_iPk,
        &c4_rb_emlrtBCI, (emlrtConstCTX)c4_sp);
    }

    c4_fPk_data[c4_i13] = c4_iPk_data[c4_idx_data[c4_i13] - 1];
  }

  c4_b_Ypk_size[0] = c4_fPk_size[0];
  c4_e_loop_ub = c4_fPk_size[0] - 1;
  for (c4_i14 = 0; c4_i14 <= c4_e_loop_ub; c4_i14++) {
    c4_b_Ypk_data[c4_i14] = c4_y[c4_fPk_data[c4_i14] - 1];
  }

  c4_b_Xpk_size[0] = c4_fPk_size[0];
  c4_f_loop_ub = c4_fPk_size[0] - 1;
  for (c4_i15 = 0; c4_i15 <= c4_f_loop_ub; c4_i15++) {
    c4_b_Xpk_data[c4_i15] = 1.0 + static_cast<real_T>(c4_fPk_data[c4_i15] - 1);
  }

  c4_Ypk_size[0] = 1;
  c4_Ypk_size[1] = c4_b_Ypk_size[0];
  c4_g_loop_ub = c4_b_Ypk_size[0] - 1;
  for (c4_i16 = 0; c4_i16 <= c4_g_loop_ub; c4_i16++) {
    c4_Ypk_data[c4_i16] = c4_b_Ypk_data[c4_i16];
  }

  c4_Xpk_size[0] = 1;
  c4_Xpk_size[1] = c4_b_Xpk_size[0];
  c4_h_loop_ub = c4_b_Xpk_size[0] - 1;
  for (c4_i17 = 0; c4_i17 <= c4_h_loop_ub; c4_i17++) {
    c4_Xpk_data[c4_i17] = c4_b_Xpk_data[c4_i17];
  }
}

static void c4_check_forloop_overflow_error(SFc4_PerceptionInstanceStruct
  *chartInstance, const emlrtStack *c4_sp)
{
  static char_T c4_b_cv[34]{ 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c4_b_cv1[5]{ 'i', 'n', 't', '3', '2' };

  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_c_y{ nullptr };

  const mxArray *c4_y{ nullptr };

  c4_y = nullptr;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c4_b_y = nullptr;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c4_c_y = nullptr;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c4_sp, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14, sf_mex_call
              (c4_sp, nullptr, "getString", 1U, 1U, 14, sf_mex_call(c4_sp,
    nullptr, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
}

static void c4_do_vectors(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_b_a_data[], int32_T c4_a_size[1], int32_T
  c4_b_b_data[], int32_T c4_b_size[1], int32_T c4_c_data[], int32_T c4_c_size[1],
  int32_T c4_ia_data[], int32_T c4_ia_size[1], int32_T c4_ib_data[], int32_T
  c4_ib_size[1])
{
  static char_T c4_b_cv[33]{ 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u',
    'n', 's', 'o', 'r', 't', 'e', 'd', 'A' };

  static char_T c4_b_cv1[33]{ 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u',
    'n', 's', 'o', 'r', 't', 'e', 'd', 'B' };

  static char_T c4_cv2[30]{ 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  emlrtStack c4_st;
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_c_y{ nullptr };

  const mxArray *c4_d_y{ nullptr };

  const mxArray *c4_e_y{ nullptr };

  const mxArray *c4_f_y{ nullptr };

  const mxArray *c4_g_y{ nullptr };

  const mxArray *c4_h_y{ nullptr };

  const mxArray *c4_j_y{ nullptr };

  const mxArray *c4_k_y{ nullptr };

  const mxArray *c4_y{ nullptr };

  int32_T c4_iv[2];
  int32_T c4_a;
  int32_T c4_ab_a;
  int32_T c4_ak;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_ak;
  int32_T c4_b_bk;
  int32_T c4_b_c;
  int32_T c4_b_ialast;
  int32_T c4_b_iblast;
  int32_T c4_b_k;
  int32_T c4_b_na;
  int32_T c4_b_nb;
  int32_T c4_b_nx;
  int32_T c4_b_xkplus;
  int32_T c4_bb_a;
  int32_T c4_c;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_bk;
  int32_T c4_c_c;
  int32_T c4_c_ialast;
  int32_T c4_c_iblast;
  int32_T c4_c_k;
  int32_T c4_c_nx;
  int32_T c4_c_xkplus;
  int32_T c4_cb_a;
  int32_T c4_d_a;
  int32_T c4_d_c;
  int32_T c4_d_k;
  int32_T c4_d_nx;
  int32_T c4_d_xkplus;
  int32_T c4_db_a;
  int32_T c4_e_a;
  int32_T c4_e_b;
  int32_T c4_e_nx;
  int32_T c4_eb_a;
  int32_T c4_f_a;
  int32_T c4_f_b;
  int32_T c4_fb_a;
  int32_T c4_g_a;
  int32_T c4_g_b;
  int32_T c4_gb_a;
  int32_T c4_h_a;
  int32_T c4_h_b;
  int32_T c4_hb_a;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i_a;
  int32_T c4_iafirst;
  int32_T c4_ialast;
  int32_T c4_ib_a;
  int32_T c4_ibfirst;
  int32_T c4_iblast;
  int32_T c4_j_a;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_k_a;
  int32_T c4_k_b;
  int32_T c4_m_a;
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
  boolean_T c4_b2;
  boolean_T c4_b_b;
  boolean_T c4_b_b1;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_d_p;
  boolean_T c4_e_p;
  boolean_T c4_exitg1;
  boolean_T c4_f_p;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_na = c4_a_size[0];
  c4_b_nb = c4_b_size[0];
  c4_a = c4_b_na;
  c4_b = c4_b_nb;
  c4_ncmax = c4_a + c4_b;
  c4_iv[0] = c4_ncmax;
  c4_c_size[0] = c4_iv[0];
  c4_ia_size[0] = c4_b_na;
  c4_ib_size[0] = c4_b_nb;
  c4_st.site = &c4_m_emlrtRSI;
  if (!c4_issorted(chartInstance, &c4_st, c4_b_a_data, c4_a_size)) {
    c4_y = nullptr;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c4_b_y = nullptr;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c4_sp, &c4_b_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(c4_sp, nullptr, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, nullptr, "message", 1U, 1U, 14, c4_b_y)));
  }

  c4_st.site = &c4_o_emlrtRSI;
  if (!c4_issorted(chartInstance, &c4_st, c4_b_b_data, c4_b_size)) {
    c4_c_y = nullptr;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c4_d_y = nullptr;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c4_sp, &c4_c_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                sf_mex_call(c4_sp, nullptr, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, nullptr, "message", 1U, 1U, 14, c4_d_y)));
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
    c4_b_nx = c4_a_size[0];
    c4_ak = c4_b_a_data[c4_b_ialast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_b_ialast < c4_b_nx)) {
      c4_b_a = c4_b_ialast + 1;
      c4_c = c4_b_a - 1;
      c4_xkplus = c4_b_a_data[c4_c];
      c4_e_a = c4_xkplus;
      c4_c_b = c4_ak;
      c4_p = (c4_e_a == c4_c_b);
      if (c4_p) {
        c4_m_a = c4_b_ialast + 1;
        c4_b_ialast = c4_m_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_ialast = c4_b_ialast;
    c4_d_k = c4_iblast;
    c4_c_iblast = c4_d_k;
    c4_e_nx = c4_b_size[0];
    c4_c_bk = c4_b_b_data[c4_c_iblast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_c_iblast < c4_e_nx)) {
      c4_p_a = c4_c_iblast + 1;
      c4_d_c = c4_p_a - 1;
      c4_d_xkplus = c4_b_b_data[c4_d_c];
      c4_u_a = c4_d_xkplus;
      c4_h_b = c4_c_bk;
      c4_e_p = (c4_u_a == c4_h_b);
      if (c4_e_p) {
        c4_y_a = c4_c_iblast + 1;
        c4_c_iblast = c4_y_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_iblast = c4_c_iblast;
    c4_r_a = c4_ak;
    c4_g_b = c4_c_bk;
    c4_d_p = (c4_r_a == c4_g_b);
    if (c4_d_p) {
      c4_w_a = c4_nc + 1;
      c4_nc = c4_w_a;
      c4_c_data[c4_nc] = c4_ak;
      c4_ab_a = c4_nia + 1;
      c4_nia = c4_ab_a;
      c4_ia_data[c4_nia] = c4_iafirst;
      c4_db_a = c4_b_ialast + 1;
      c4_ialast = c4_db_a;
      c4_iafirst = c4_ialast;
      c4_gb_a = c4_c_iblast + 1;
      c4_iblast = c4_gb_a;
      c4_ibfirst = c4_iblast;
    } else {
      c4_v_a = c4_ak;
      c4_j_b = c4_c_bk;
      c4_x_a = c4_v_a;
      c4_k_b = c4_j_b;
      c4_f_p = (c4_x_a < c4_k_b);
      if (c4_f_p) {
        c4_cb_a = c4_nc + 1;
        c4_nc = c4_cb_a;
        c4_fb_a = c4_nia + 1;
        c4_nia = c4_fb_a;
        c4_c_data[c4_nc] = c4_ak;
        c4_ia_data[c4_nia] = c4_iafirst;
        c4_ib_a = c4_b_ialast + 1;
        c4_ialast = c4_ib_a;
        c4_iafirst = c4_ialast;
      } else {
        c4_bb_a = c4_nc + 1;
        c4_nc = c4_bb_a;
        c4_eb_a = c4_nib + 1;
        c4_nib = c4_eb_a;
        c4_c_data[c4_nc] = c4_c_bk;
        c4_ib_data[c4_nib - 1] = c4_ibfirst;
        c4_hb_a = c4_c_iblast + 1;
        c4_iblast = c4_hb_a;
        c4_ibfirst = c4_iblast;
      }
    }
  }

  while (c4_ialast <= c4_b_na) {
    c4_b_k = c4_ialast;
    c4_c_ialast = c4_b_k;
    c4_c_nx = c4_a_size[0];
    c4_b_ak = c4_b_a_data[c4_c_ialast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_c_ialast < c4_c_nx)) {
      c4_d_a = c4_c_ialast + 1;
      c4_b_c = c4_d_a - 1;
      c4_b_xkplus = c4_b_a_data[c4_b_c];
      c4_i_a = c4_b_xkplus;
      c4_e_b = c4_b_ak;
      c4_b_p = (c4_i_a == c4_e_b);
      if (c4_b_p) {
        c4_q_a = c4_c_ialast + 1;
        c4_c_ialast = c4_q_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_c_a = c4_nc + 1;
    c4_nc = c4_c_a;
    c4_h_a = c4_nia + 1;
    c4_nia = c4_h_a;
    c4_c_data[c4_nc] = c4_b_ak;
    c4_ia_data[c4_nia] = c4_iafirst;
    c4_o_a = c4_c_ialast + 1;
    c4_ialast = c4_o_a;
    c4_iafirst = c4_ialast;
  }

  while (c4_iblast <= c4_b_nb) {
    c4_c_k = c4_iblast;
    c4_b_iblast = c4_c_k;
    c4_d_nx = c4_b_size[0];
    c4_b_bk = c4_b_b_data[c4_b_iblast - 1];
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_b_iblast < c4_d_nx)) {
      c4_g_a = c4_b_iblast + 1;
      c4_c_c = c4_g_a - 1;
      c4_c_xkplus = c4_b_b_data[c4_c_c];
      c4_k_a = c4_c_xkplus;
      c4_f_b = c4_b_bk;
      c4_c_p = (c4_k_a == c4_f_b);
      if (c4_c_p) {
        c4_t_a = c4_b_iblast + 1;
        c4_b_iblast = c4_t_a;
      } else {
        c4_exitg1 = true;
      }
    }

    c4_f_a = c4_nc + 1;
    c4_nc = c4_f_a;
    c4_j_a = c4_nib + 1;
    c4_nib = c4_j_a;
    c4_c_data[c4_nc] = c4_b_bk;
    c4_ib_data[c4_nib - 1] = c4_ibfirst;
    c4_s_a = c4_b_iblast + 1;
    c4_iblast = c4_s_a;
    c4_ibfirst = c4_iblast;
  }

  if (c4_b_na > 0) {
    if (!(c4_nia + 1 <= c4_b_na)) {
      c4_e_y = nullptr;
      sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c4_g_y = nullptr;
      sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c4_sp, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_e_y, 14,
                  sf_mex_call(c4_sp, nullptr, "getString", 1U, 1U, 14,
        sf_mex_call(c4_sp, nullptr, "message", 1U, 1U, 14, c4_g_y)));
    }

    c4_b_b = (c4_nia + 1 < 1);
    if (c4_b_b) {
      c4_i = 0;
    } else {
      c4_i = c4_nia + 1;
    }

    c4_ia_size[0] = c4_i;
  }

  if (c4_b_nb > 0) {
    if (!(c4_nib <= c4_b_nb)) {
      c4_f_y = nullptr;
      sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c4_j_y = nullptr;
      sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c4_sp, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_f_y, 14,
                  sf_mex_call(c4_sp, nullptr, "getString", 1U, 1U, 14,
        sf_mex_call(c4_sp, nullptr, "message", 1U, 1U, 14, c4_j_y)));
    }

    c4_b_b1 = (c4_nib < 1);
    if (c4_b_b1) {
      c4_i1 = 0;
    } else {
      c4_i1 = c4_nib;
    }

    c4_ib_size[0] = c4_i1;
  }

  if (c4_ncmax > 0) {
    if (!(c4_nc + 1 <= c4_ncmax)) {
      c4_h_y = nullptr;
      sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c4_k_y = nullptr;
      sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c4_sp, &c4_f_emlrtMCI, "error", 0U, 2U, 14, c4_h_y, 14,
                  sf_mex_call(c4_sp, nullptr, "getString", 1U, 1U, 14,
        sf_mex_call(c4_sp, nullptr, "message", 1U, 1U, 14, c4_k_y)));
    }

    c4_b2 = (c4_nc + 1 < 1);
    if (c4_b2) {
      c4_i2 = 0;
    } else {
      c4_i2 = c4_nc + 1;
    }

    c4_c_size[0] = c4_i2;
  }
}

static boolean_T c4_issorted(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, int32_T c4_x_data[], int32_T c4_x_size[1])
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  real_T c4_b_d1;
  real_T c4_d;
  int32_T c4_subs[2];
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_dim;
  int32_T c4_b_k;
  int32_T c4_b_n;
  int32_T c4_b_nx;
  int32_T c4_c_b;
  int32_T c4_c_dim;
  int32_T c4_c_k;
  int32_T c4_d_dim;
  int32_T c4_dim;
  int32_T c4_e_b;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_k;
  int32_T c4_n;
  int32_T c4_varargin_1;
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
  if (static_cast<real_T>(c4_x_size[0]) != 1.0) {
    c4_dim = 1;
  }

  if (c4_dim <= 1) {
    c4_d = static_cast<real_T>(c4_x_size[0]);
  } else {
    c4_d = 1.0;
  }

  c4_b_nx = static_cast<int32_T>(c4_d);
  if ((c4_x_size[0] == 0) || (c4_b_nx == 1)) {
  } else {
    c4_st.site = &c4_p_emlrtRSI;
    c4_b_dim = c4_dim;
    if (c4_b_dim == 2) {
      c4_n = 0;
    } else {
      c4_n = 1;
    }

    c4_b_st.site = &c4_q_emlrtRSI;
    c4_b = c4_n;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_h_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    c4_i = static_cast<uint8_T>(c4_n) - 1;
    c4_k = 0;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k <= c4_i)) {
      c4_b_st.site = &c4_r_emlrtRSI;
      c4_c_dim = c4_b_dim;
      c4_y = true;
      if (c4_c_dim == 1) {
        c4_b_d1 = static_cast<real_T>(c4_x_size[0]);
        c4_b_n = static_cast<int32_T>(c4_b_d1) - 1;
      } else {
        c4_b_n = c4_x_size[0];
      }

      c4_c_st.site = &c4_q_emlrtRSI;
      c4_c_b = c4_b_n;
      c4_e_b = c4_c_b;
      if (c4_e_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_e_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_d_st.site = &c4_h_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
      }

      c4_i1 = static_cast<uint16_T>(c4_b_n) - 1;
      c4_b_k = 1;
      c4_exitg2 = false;
      while ((!c4_exitg2) && (c4_b_k - 1 <= c4_i1)) {
        c4_c_k = c4_b_k;
        c4_d_dim = c4_c_dim - 1;
        c4_varargin_1 = c4_c_k;
        c4_x1 = c4_x_data[c4_varargin_1 - 1];
        c4_subs[0] = c4_varargin_1;
        c4_subs[1] = 1;
        c4_subs[c4_d_dim]++;
        c4_x2 = c4_x_data[c4_subs[0] - 1];
        c4_subs[0] = c4_x1;
        c4_subs[1] = c4_x2;
        c4_a = c4_subs[0];
        c4_f_b = c4_subs[1];
        c4_b_a = c4_a;
        c4_g_b = c4_f_b;
        c4_h_b = (c4_b_a <= c4_g_b);
        c4_y = c4_h_b;
        if (!c4_y) {
          c4_exitg2 = true;
        } else {
          c4_b_k++;
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

static void c4_indexShapeCheck(SFc4_PerceptionInstanceStruct *chartInstance)
{
}

static void c4_b_indexShapeCheck(SFc4_PerceptionInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T c4_indexSize[2])
{
  static char_T c4_b_cv[30]{ 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c4_st;
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_y{ nullptr };

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

  c4_st.site = &c4_w_emlrtRSI;
  c4_b_c = c4_c;
  if (c4_b_c) {
    c4_y = nullptr;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_b_y = nullptr;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c4_st, &c4_i_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, nullptr, "getString", 1U, 1U, 14,
      sf_mex_call(&c4_st, nullptr, "message", 1U, 1U, 14, c4_b_y)));
  }
}

static void c4_eml_find(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, boolean_T c4_b_x[900000], int32_T c4_i_data[], int32_T
  c4_i_size[1], int32_T c4_j_data[], int32_T c4_j_size[1])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_iv[2];
  int32_T c4_iv1[2];
  int32_T c4_iv2[2];
  int32_T c4_b_ii;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_idx;
  int32_T c4_jj;
  boolean_T c4_b;
  boolean_T c4_b2;
  boolean_T c4_b_b1;
  boolean_T c4_exitg1;
  boolean_T c4_guard1;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_y_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_idx = 0;
  c4_b_ii = 1;
  c4_jj = 1;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_jj <= 1200)) {
    c4_guard1 = false;
    if (c4_b_x[(c4_b_ii + 750 * (c4_jj - 1)) - 1]) {
      c4_idx++;
      c4_i_data[c4_idx - 1] = c4_b_ii;
      c4_j_data[c4_idx - 1] = c4_jj;
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
      if (c4_b_ii > 750) {
        c4_b_ii = 1;
        c4_jj++;
      }
    }
  }

  c4_b = (c4_idx < 1);
  if (c4_b) {
    c4_i = 0;
  } else {
    c4_i = c4_idx;
  }

  c4_iv[0] = 1;
  c4_iv[1] = c4_i;
  c4_b_st.site = &c4_ab_emlrtRSI;
  c4_b_indexShapeCheck(chartInstance, &c4_b_st, 900000, c4_iv);
  c4_i_size[0] = c4_i;
  c4_b_b1 = (c4_idx < 1);
  if (c4_b_b1) {
    c4_i1 = 0;
  } else {
    c4_i1 = c4_idx;
  }

  c4_iv1[0] = 1;
  c4_iv1[1] = c4_i1;
  c4_b_st.site = &c4_bb_emlrtRSI;
  c4_b_indexShapeCheck(chartInstance, &c4_b_st, 900000, c4_iv1);
  c4_j_size[0] = c4_i1;
  c4_b2 = (c4_idx < 1);
  if (c4_b2) {
    c4_i2 = 0;
  } else {
    c4_i2 = c4_idx;
  }

  c4_iv2[0] = 1;
  c4_iv2[1] = c4_i2;
  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_b_indexShapeCheck(chartInstance, &c4_b_st, 900000, c4_iv2);
}

static real_T c4_mean(SFc4_PerceptionInstanceStruct *chartInstance, const
                      emlrtStack *c4_sp, real_T c4_x_data[], int32_T c4_x_size[1])
{
  static char_T c4_b_cv[36]{ 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_c_y{ nullptr };

  real_T c4_d_y;
  real_T c4_s;
  int32_T c4_a;
  int32_T c4_b_ib;
  int32_T c4_b_vlen;
  int32_T c4_c_vlen;
  int32_T c4_d_vlen;
  int32_T c4_inb;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  int32_T c4_vlen;
  boolean_T c4_b;
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
  if ((c4_x_size[0] == 1) || (static_cast<real_T>(c4_x_size[0]) != 1.0)) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_b_y = nullptr;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c4_c_y = nullptr;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(c4_sp, &c4_j_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(c4_sp, nullptr, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, nullptr, "message", 1U, 1U, 14, c4_c_y)));
  }

  c4_st.site = &c4_db_emlrtRSI;
  c4_vlen = c4_x_size[0];
  c4_b_st.site = &c4_eb_emlrtRSI;
  c4_b_vlen = c4_vlen;
  if ((c4_x_size[0] == 0) || (c4_b_vlen == 0)) {
    c4_d_y = 0.0;
  } else {
    c4_c_st.site = &c4_fb_emlrtRSI;
    c4_c_vlen = c4_b_vlen;
    c4_d_st.site = &c4_gb_emlrtRSI;
    c4_d_vlen = c4_c_vlen;
    if (c4_d_vlen < 4096) {
      c4_e_st.site = &c4_ib_emlrtRSI;
      c4_d_y = c4_sumColumnB(chartInstance, &c4_e_st, c4_x_data, c4_d_vlen);
    } else {
      c4_a = c4_d_vlen;
      c4_nfb = static_cast<int32_T>(static_cast<uint32_T>(c4_a) >> 12);
      c4_inb = c4_nfb << 12;
      c4_lidx = c4_inb;
      c4_nleft = c4_d_vlen - c4_inb;
      c4_s = c4_sumColumnB4(chartInstance, c4_x_data, 1);
      for (c4_b_ib = 2; c4_b_ib <= c4_nfb; c4_b_ib++) {
        c4_s += c4_sumColumnB4(chartInstance, c4_x_data, 1 + ((c4_b_ib - 1) <<
          12));
      }

      if (c4_nleft > 0) {
        c4_e_st.site = &c4_hb_emlrtRSI;
        c4_s += c4_b_sumColumnB(chartInstance, &c4_e_st, c4_x_data, c4_nleft,
          c4_lidx + 1);
      }

      c4_d_y = c4_s;
    }
  }

  return c4_d_y / static_cast<real_T>(c4_x_size[0]);
}

static real_T c4_sumColumnB(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_x_data[], int32_T c4_vlen)
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
  int32_T c4_c_k;
  int32_T c4_c_vlen;
  int32_T c4_d_k;
  int32_T c4_e_b;
  int32_T c4_e_k;
  int32_T c4_f_k;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i_k;
  int32_T c4_inb;
  int32_T c4_k;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  int32_T c4_vstart;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (c4_vlen <= 1024) {
    c4_st.site = &c4_kb_emlrtRSI;
    c4_b_vlen = c4_vlen - 1;
    c4_y = c4_x_data[0];
    c4_i = c4_b_vlen;
    c4_b_st.site = &c4_mb_emlrtRSI;
    c4_b = c4_i;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_h_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    c4_i1 = static_cast<uint16_T>(c4_i) - 1;
    for (c4_f_k = 0; c4_f_k <= c4_i1; c4_f_k++) {
      c4_g_k = c4_f_k;
      c4_y += c4_x_data[c4_g_k + 1];
    }
  } else {
    c4_a = c4_vlen;
    c4_nfb = static_cast<int32_T>(static_cast<uint32_T>(c4_a) >> 10);
    c4_inb = c4_nfb << 10;
    c4_y = c4_x_data[0];
    for (c4_k = 0; c4_k < 1023; c4_k++) {
      c4_c_k = c4_k;
      c4_y += c4_x_data[c4_c_k + 1];
    }

    for (c4_b_k = 2; c4_b_k <= c4_nfb; c4_b_k++) {
      c4_vstart = (c4_b_k - 1) << 10;
      c4_b_y = c4_x_data[c4_vstart];
      for (c4_d_k = 0; c4_d_k < 1023; c4_d_k++) {
        c4_e_k = c4_d_k;
        c4_b_y += c4_x_data[(c4_vstart + c4_e_k) + 1];
      }

      c4_y += c4_b_y;
    }

    if (c4_vlen > c4_inb) {
      c4_nleft = c4_vlen - c4_inb;
      c4_lidx = c4_inb;
      c4_st.site = &c4_jb_emlrtRSI;
      c4_c_vlen = c4_nleft - 1;
      c4_b_vstart = c4_lidx;
      c4_c_y = c4_x_data[c4_b_vstart];
      c4_i2 = c4_c_vlen;
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_c_b = c4_i2;
      c4_e_b = c4_c_b;
      if (c4_e_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_e_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_c_st.site = &c4_h_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_h_k = 0; c4_h_k < c4_i2; c4_h_k++) {
        c4_i_k = c4_h_k;
        c4_c_y += c4_x_data[(c4_b_vstart + c4_i_k) + 1];
      }

      c4_y += c4_c_y;
    }
  }

  return c4_y;
}

static real_T c4_sumColumnB4(SFc4_PerceptionInstanceStruct *chartInstance,
  real_T c4_x_data[], int32_T c4_vstart)
{
  real_T c4_psum1;
  real_T c4_psum2;
  real_T c4_psum3;
  real_T c4_psum4;
  int32_T c4_b_k;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_k;
  c4_i2 = c4_vstart + 1023;
  c4_i3 = c4_vstart + 2047;
  c4_i4 = c4_vstart + 3071;
  c4_psum1 = c4_x_data[c4_vstart - 1];
  c4_psum2 = c4_x_data[c4_i2];
  c4_psum3 = c4_x_data[c4_i3];
  c4_psum4 = c4_x_data[c4_i4];
  for (c4_k = 0; c4_k < 1023; c4_k++) {
    c4_b_k = c4_k + 1;
    c4_psum1 += c4_x_data[(c4_vstart + c4_b_k) - 1];
    c4_psum2 += c4_x_data[c4_i2 + c4_b_k];
    c4_psum3 += c4_x_data[c4_i3 + c4_b_k];
    c4_psum4 += c4_x_data[c4_i4 + c4_b_k];
  }

  return (c4_psum1 + c4_psum2) + (c4_psum3 + c4_psum4);
}

static real_T c4_b_sumColumnB(SFc4_PerceptionInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_x_data[], int32_T c4_vlen, int32_T
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
  int32_T c4_c_k;
  int32_T c4_c_vlen;
  int32_T c4_c_vstart;
  int32_T c4_d_k;
  int32_T c4_d_vstart;
  int32_T c4_e_b;
  int32_T c4_e_k;
  int32_T c4_e_vstart;
  int32_T c4_f_k;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i_k;
  int32_T c4_inb;
  int32_T c4_k;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (c4_vlen <= 1024) {
    c4_st.site = &c4_kb_emlrtRSI;
    c4_b_vlen = c4_vlen - 1;
    c4_b_vstart = c4_vstart - 1;
    c4_y = c4_x_data[c4_b_vstart];
    c4_i = c4_b_vlen;
    c4_b_st.site = &c4_mb_emlrtRSI;
    c4_b = c4_i;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_h_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    for (c4_f_k = 0; c4_f_k < c4_i; c4_f_k++) {
      c4_g_k = c4_f_k;
      c4_y += c4_x_data[(c4_b_vstart + c4_g_k) + 1];
    }
  } else {
    c4_a = c4_vlen;
    c4_nfb = static_cast<int32_T>(static_cast<uint32_T>(c4_a) >> 10);
    c4_inb = c4_nfb << 10;
    c4_c_vstart = c4_vstart - 1;
    c4_y = c4_x_data[c4_c_vstart];
    for (c4_k = 0; c4_k < 1023; c4_k++) {
      c4_c_k = c4_k;
      c4_y += c4_x_data[(c4_c_vstart + c4_c_k) + 1];
    }

    for (c4_b_k = 2; c4_b_k <= c4_nfb; c4_b_k++) {
      c4_d_vstart = (c4_vstart + ((c4_b_k - 1) << 10)) - 1;
      c4_b_y = c4_x_data[c4_d_vstart];
      for (c4_d_k = 0; c4_d_k < 1023; c4_d_k++) {
        c4_e_k = c4_d_k;
        c4_b_y += c4_x_data[(c4_d_vstart + c4_e_k) + 1];
      }

      c4_y += c4_b_y;
    }

    if (c4_vlen > c4_inb) {
      c4_nleft = c4_vlen - c4_inb;
      c4_lidx = c4_vstart + c4_inb;
      c4_st.site = &c4_jb_emlrtRSI;
      c4_c_vlen = c4_nleft - 1;
      c4_e_vstart = c4_lidx - 1;
      c4_c_y = c4_x_data[c4_e_vstart];
      c4_i1 = c4_c_vlen;
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_c_b = c4_i1;
      c4_e_b = c4_c_b;
      if (c4_e_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_e_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_c_st.site = &c4_h_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_h_k = 0; c4_h_k < c4_i1; c4_h_k++) {
        c4_i_k = c4_h_k;
        c4_c_y += c4_x_data[(c4_e_vstart + c4_i_k) + 1];
      }

      c4_y += c4_c_y;
    }
  }

  return c4_y;
}

static void c4_polyfit(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_x_data[], int32_T c4_x_size[1], real_T c4_y_data[],
  int32_T c4_y_size[1], real_T c4_p[3])
{
  static char_T c4_b_cv[29]{ 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o', 'l',
    'y', 'f', 'i', 't', ':', 'X', 'Y', 'S', 'i', 'z', 'e', 'M', 'i', 's', 'm',
    'a', 't', 'c', 'h' };

  emlrtStack c4_st;
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_y{ nullptr };

  real_T c4_b_k;
  real_T c4_n;
  int32_T c4_V_size[2];
  int32_T c4_c_k;
  int32_T c4_d_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  int32_T c4_rr;
  boolean_T c4_b;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  if (!(static_cast<real_T>(c4_x_size[0]) == static_cast<real_T>(c4_y_size[0])))
  {
    c4_y = nullptr;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c4_b_y = nullptr;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    sf_mex_call(c4_sp, &c4_k_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(c4_sp, nullptr, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, nullptr, "message", 1U, 1U, 14, c4_b_y)));
  }

  c4_n = static_cast<real_T>(c4_x_size[0]);
  c4_V_size[0] = static_cast<int32_T>(c4_n);
  c4_V_size[1] = 3;
  c4_b = (c4_V_size[0] == 0);
  if (!c4_b) {
    c4_i = static_cast<int32_T>(c4_n) - 1;
    for (c4_k = 0; c4_k <= c4_i; c4_k++) {
      c4_b_k = static_cast<real_T>(c4_k) + 1.0;
      chartInstance->c4_V_data[(static_cast<int32_T>(c4_b_k) + (c4_V_size[0] <<
        1)) - 1] = 1.0;
    }

    c4_i1 = static_cast<int32_T>(c4_n) - 1;
    for (c4_c_k = 0; c4_c_k <= c4_i1; c4_c_k++) {
      c4_b_k = static_cast<real_T>(c4_c_k) + 1.0;
      chartInstance->c4_V_data[(static_cast<int32_T>(c4_b_k) + c4_V_size[0]) - 1]
        = c4_x_data[static_cast<int32_T>(c4_b_k) - 1];
    }

    c4_i2 = static_cast<int32_T>(c4_n) - 1;
    for (c4_d_k = 0; c4_d_k <= c4_i2; c4_d_k++) {
      c4_b_k = static_cast<real_T>(c4_d_k) + 1.0;
      chartInstance->c4_V_data[static_cast<int32_T>(c4_b_k) - 1] = c4_x_data[
        static_cast<int32_T>(c4_b_k) - 1] * chartInstance->c4_V_data[(
        static_cast<int32_T>(c4_b_k) + c4_V_size[0]) - 1];
    }
  }

  c4_st.site = &c4_ob_emlrtRSI;
  c4_qrsolve(chartInstance, &c4_st, chartInstance->c4_V_data, c4_V_size,
             c4_y_data, c4_y_size, c4_p, &c4_rr);
  if (static_cast<real_T>(c4_x_size[0]) <= 2.0) {
    c4_st.site = &c4_qb_emlrtRSI;
    c4_warning(chartInstance, &c4_st);
  } else if (c4_rr <= 2) {
    c4_st.site = &c4_pb_emlrtRSI;
    c4_b_warning(chartInstance, &c4_st);
  }
}

static void c4_qrsolve(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_c_A_data[], int32_T c4_b_A_size[2], real_T
  c4_c_B_data[], int32_T c4_b_B_size[1], real_T c4_m_Y[3], int32_T *c4_rankA)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_tau_data[3];
  real_T c4_b;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_g_x;
  real_T c4_g_y;
  real_T c4_scale;
  real_T c4_tol;
  real_T c4_varargin_2;
  real_T c4_y;
  int32_T c4_jpvt[3];
  int32_T c4_c_A_size[2];
  int32_T c4_c_B_size[1];
  int32_T c4_tau_size[1];
  int32_T c4_assumedRank;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_m;
  int32_T c4_c_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_maxmn;
  int32_T c4_minmn;
  int32_T c4_mn;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_c_A_size[0] = c4_b_A_size[0];
  c4_c_A_size[1] = 3;
  c4_loop_ub = c4_b_A_size[0] * 3 - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    chartInstance->c4_A_data[c4_i] = c4_c_A_data[c4_i];
  }

  c4_st.site = &c4_rb_emlrtRSI;
  c4_b_xgeqp3(chartInstance, &c4_st, chartInstance->c4_A_data, c4_c_A_size,
              c4_tau_data, c4_tau_size, c4_jpvt);
  *c4_rankA = 0;
  c4_m = c4_c_A_size[0];
  if (c4_m < 3) {
    c4_minmn = c4_m;
    c4_maxmn = 3;
  } else {
    c4_minmn = 3;
    c4_maxmn = c4_m;
  }

  if (c4_minmn > 0) {
    c4_varargin_2 = 2.2204460492503131E-15 * static_cast<real_T>(c4_maxmn);
    c4_y = c4_varargin_2;
    c4_b_y = c4_y;
    c4_c_y = c4_b_y;
    c4_b = c4_c_y;
    c4_d_y = c4_b;
    c4_e_y = c4_d_y;
    c4_scale = c4_e_y;
    c4_b_x = chartInstance->c4_A_data[0];
    c4_c_x = c4_b_x;
    c4_d_x = c4_c_x;
    c4_f_y = muDoubleScalarAbs(c4_d_x);
    c4_tol = c4_scale * c4_f_y;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (*c4_rankA < c4_minmn)) {
      c4_e_x = chartInstance->c4_A_data[*c4_rankA + c4_c_A_size[0] * *c4_rankA];
      c4_f_x = c4_e_x;
      c4_g_x = c4_f_x;
      c4_g_y = muDoubleScalarAbs(c4_g_x);
      if (!(c4_g_y <= c4_tol)) {
        (*c4_rankA)++;
      } else {
        c4_exitg1 = true;
      }
    }
  }

  c4_st.site = &c4_sb_emlrtRSI;
  c4_assumedRank = 0;
  c4_b_m = c4_c_A_size[0];
  if (c4_b_m < 3) {
    c4_mn = c4_b_m;
  } else {
    c4_mn = 3;
  }

  if (c4_mn > 0) {
    c4_b_st.site = &c4_ad_emlrtRSI;
    c4_b_b = c4_mn;
    c4_c_b = c4_b_b;
    if (c4_c_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_h_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    c4_i2 = static_cast<uint8_T>(c4_mn) - 1;
    for (c4_k = 0; c4_k <= c4_i2; c4_k++) {
      c4_b_k = c4_k;
      if (chartInstance->c4_A_data[c4_b_k + c4_c_A_size[0] * c4_b_k] != 0.0) {
        c4_assumedRank++;
      }
    }
  }

  c4_c_B_size[0] = c4_b_B_size[0];
  c4_b_loop_ub = c4_b_B_size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_b_loop_ub; c4_i1++) {
    chartInstance->c4_B_data[c4_i1] = c4_c_B_data[c4_i1];
  }

  c4_st.site = &c4_tb_emlrtRSI;
  c4_LSQFromQR(chartInstance, &c4_st, chartInstance->c4_A_data, c4_c_A_size,
               c4_tau_data, c4_jpvt, chartInstance->c4_B_data, c4_c_B_size,
               c4_assumedRank, c4_m_Y);
}

static void c4_xgeqp3(SFc4_PerceptionInstanceStruct *chartInstance, const
                      emlrtStack *c4_sp, real_T c4_c_A_data[], int32_T
                      c4_b_A_size[2], real_T c4_d_A_data[], int32_T c4_c_A_size
                      [2], real_T c4_tau_data[], int32_T c4_tau_size[1], int32_T
                      c4_jpvt[3])
{
  int32_T c4_i;
  int32_T c4_loop_ub;
  c4_c_A_size[0] = c4_b_A_size[0];
  c4_c_A_size[1] = 3;
  c4_loop_ub = c4_b_A_size[0] * 3 - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_d_A_data[c4_i] = c4_c_A_data[c4_i];
  }

  c4_b_xgeqp3(chartInstance, c4_sp, c4_d_A_data, c4_c_A_size, c4_tau_data,
              c4_tau_size, c4_jpvt);
}

static void c4_LSQFromQR(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_c_A_data[], int32_T c4_b_A_size[2], real_T
  c4_tau_data[], int32_T c4_jpvt[3], real_T c4_c_B_data[], int32_T c4_b_B_size[1],
  int32_T c4_rankA, real_T c4_m_Y[3])
{
  static char_T c4_b_cv[14]{ 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'o',
    'r', 'm', 'q', 'r' };

  ptrdiff_t c4_info_t;
  ptrdiff_t c4_lda_t;
  ptrdiff_t c4_ncc_t;
  ptrdiff_t c4_nrc_t;
  ptrdiff_t c4_nrf_t;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_c_y{ nullptr };

  const mxArray *c4_d_y{ nullptr };

  const mxArray *c4_e_y{ nullptr };

  const mxArray *c4_f_y{ nullptr };

  const mxArray *c4_g_y{ nullptr };

  real_T c4_b_x;
  real_T c4_y;
  real_T c4_z;
  int32_T c4_o_B[1];
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
  int32_T c4_i3;
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
    c4_m_Y[c4_i] = 0.0;
  }

  c4_st.site = &c4_bd_emlrtRSI;
  c4_b_st.site = &c4_ed_emlrtRSI;
  c4_m = c4_b_A_size[0];
  if (c4_m < 3) {
    c4_mn = c4_m;
  } else {
    c4_mn = 3;
  }

  c4_b = (c4_b_A_size[0] == 0);
  if ((!c4_b) && (c4_b_B_size[0] != 0)) {
    c4_nrc_t = (ptrdiff_t)c4_b_B_size[0];
    c4_ncc_t = (ptrdiff_t)1;
    c4_nrf_t = (ptrdiff_t)c4_mn;
    c4_lda_t = (ptrdiff_t)c4_m;
    c4_info_t = LAPACKE_dormqr(102, 'L', 'T', c4_nrc_t, c4_ncc_t, c4_nrf_t,
      &c4_c_A_data[0], c4_lda_t, &c4_tau_data[0], &c4_c_B_data[0], c4_nrc_t);
    c4_info = (int32_T)c4_info_t;
    c4_c_st.site = &c4_fd_emlrtRSI;
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
          c4_c_y = nullptr;
          sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          c4_e_y = nullptr;
          sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          sf_mex_call(&c4_c_st, &c4_m_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                      sf_mex_call(&c4_c_st, nullptr, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_c_st, nullptr, "message", 1U, 1U, 14, c4_e_y)));
        } else {
          c4_b_y = nullptr;
          sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1,
            33), false);
          c4_d_y = nullptr;
          sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1,
            33), false);
          c4_f_y = nullptr;
          sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2,
            1, 14), false);
          c4_g_y = nullptr;
          sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_b_info, 6, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call(&c4_c_st, &c4_o_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                      sf_mex_call(&c4_c_st, nullptr, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_c_st, nullptr, "message", 1U, 3U, 14, c4_d_y, 14,
                        c4_f_y, 14, c4_g_y)));
        }
      }
    } else {
      c4_b_p = false;
    }

    if (c4_b_p) {
      c4_o_B[0] = c4_b_B_size[0];
      c4_loop_ub = c4_o_B[0] - 1;
      for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
        c4_c_B_data[c4_i1] = rtNaN;
      }
    }
  }

  c4_st.site = &c4_cd_emlrtRSI;
  c4_b_b = c4_rankA;
  c4_c_b = c4_b_b;
  if (c4_c_b < 1) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_c_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_h_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  for (c4_b_i = 0; c4_b_i < c4_rankA; c4_b_i++) {
    c4_c_i = c4_b_i;
    c4_m_Y[c4_jpvt[c4_c_i] - 1] = c4_c_B_data[c4_c_i];
  }

  for (c4_j = c4_rankA; c4_j >= 1; c4_j--) {
    c4_pj = c4_jpvt[c4_j - 1] - 1;
    c4_b_x = c4_m_Y[c4_pj];
    c4_y = c4_c_A_data[(c4_j + c4_b_A_size[0] * (c4_j - 1)) - 1];
    c4_z = c4_b_x / c4_y;
    c4_m_Y[c4_pj] = c4_z;
    c4_i2 = c4_j - 1;
    c4_st.site = &c4_dd_emlrtRSI;
    c4_e_b = c4_i2;
    c4_f_b = c4_e_b;
    if (c4_f_b < 1) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_f_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_b_st.site = &c4_h_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    c4_i3 = static_cast<uint8_T>(c4_i2) - 1;
    for (c4_d_i = 0; c4_d_i <= c4_i3; c4_d_i++) {
      c4_c_i = c4_d_i;
      c4_m_Y[c4_jpvt[c4_c_i] - 1] -= c4_m_Y[c4_pj] * c4_c_A_data[c4_c_i +
        c4_b_A_size[0] * (c4_j - 1)];
    }
  }
}

static void c4_warning(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp)
{
  static char_T c4_msgID[28]{ 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o', 'l',
    'y', 'f', 'i', 't', ':', 'P', 'o', 'l', 'y', 'N', 'o', 't', 'U', 'n', 'i',
    'q', 'u', 'e' };

  static char_T c4_b_cv[7]{ 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_b_cv1[7]{ 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_c_y{ nullptr };

  const mxArray *c4_y{ nullptr };

  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = nullptr;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = nullptr;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = nullptr;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 28),
                false);
  c4_st.site = &c4_hd_emlrtRSI;
  c4_b_feval(chartInstance, &c4_st, c4_y, c4_feval(chartInstance, &c4_st, c4_b_y,
              c4_c_y));
}

static void c4_b_warning(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp)
{
  static char_T c4_msgID[38]{ 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o', 'l',
    'y', 'f', 'i', 't', ':', 'R', 'e', 'p', 'e', 'a', 't', 'e', 'd', 'P', 'o',
    'i', 'n', 't', 's', 'O', 'r', 'R', 'e', 's', 'c', 'a', 'l', 'e' };

  static char_T c4_b_cv[7]{ 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_b_cv1[7]{ 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_c_y{ nullptr };

  const mxArray *c4_y{ nullptr };

  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = nullptr;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = nullptr;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = nullptr;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 38),
                false);
  c4_st.site = &c4_hd_emlrtRSI;
  c4_d_feval(chartInstance, &c4_st, c4_y, c4_c_feval(chartInstance, &c4_st,
              c4_b_y, c4_c_y));
}

const mxArray *sf_c4_Perception_get_eml_resolved_functions_info()
{
  const mxArray *c4_nameCaptureInfo{ nullptr };

  c4_nameCaptureInfo = nullptr;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", nullptr, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static real_T c4_emlrt_marshallIn(SFc4_PerceptionInstanceStruct *chartInstance,
  const mxArray *c4_nullptr, const char_T *c4_identifier)
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

static real_T c4_b_emlrt_marshallIn(SFc4_PerceptionInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_d;
  real_T c4_y;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static uint8_T c4_c_emlrt_marshallIn(SFc4_PerceptionInstanceStruct
  *chartInstance, const mxArray *c4_nullptr, const char_T *c4_identifier)
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

static uint8_T c4_d_emlrt_marshallIn(SFc4_PerceptionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_u;
  uint8_T c4_y;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b_u, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_b_u;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_slStringInitializeDynamicBuffers(SFc4_PerceptionInstanceStruct
  *chartInstance)
{
}

static void c4_chart_data_browse_helper(SFc4_PerceptionInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig)
{
  real_T c4_d;
  *c4_mxData = nullptr;
  *c4_mxData = nullptr;
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

static const mxArray *c4_feval(SFc4_PerceptionInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  const mxArray *c4_m{ nullptr };

  c4_m = nullptr;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, nullptr, "feval", 1U, 2U, 14,
    sf_mex_dup(c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static void c4_b_feval(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  sf_mex_call(c4_sp, nullptr, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static const mxArray *c4_c_feval(SFc4_PerceptionInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  const mxArray *c4_m{ nullptr };

  c4_m = nullptr;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, nullptr, "feval", 1U, 2U, 14,
    sf_mex_dup(c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static void c4_d_feval(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  sf_mex_call(c4_sp, nullptr, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static void c4_b_xgeqp3(SFc4_PerceptionInstanceStruct *chartInstance, const
  emlrtStack *c4_sp, real_T c4_c_A_data[], int32_T c4_b_A_size[2], real_T
  c4_tau_data[], int32_T c4_tau_size[1], int32_T c4_jpvt[3])
{
  static char_T c4_b_cv[14]{ 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 'q', 'p', '3' };

  ptrdiff_t c4_jpvt_t[3];
  ptrdiff_t c4_info_t;
  ptrdiff_t c4_lda_t;
  ptrdiff_t c4_m_t;
  ptrdiff_t c4_n_t;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_c_y{ nullptr };

  const mxArray *c4_d_y{ nullptr };

  const mxArray *c4_e_y{ nullptr };

  const mxArray *c4_f_y{ nullptr };

  const mxArray *c4_y{ nullptr };

  int32_T c4_tau[1];
  int32_T c4_b_b;
  int32_T c4_b_i;
  int32_T c4_b_info;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_c_b;
  int32_T c4_c_i;
  int32_T c4_c_info;
  int32_T c4_c_k;
  int32_T c4_c_ma;
  int32_T c4_d_k;
  int32_T c4_d_ma;
  int32_T c4_e_b;
  int32_T c4_e_k;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_info;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_minmana;
  int32_T c4_minmn;
  int32_T c4_val;
  boolean_T c4_b;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_c_ma = c4_b_A_size[0];
  c4_st.site = &c4_ub_emlrtRSI;
  c4_m = c4_c_ma;
  c4_d_ma = c4_b_A_size[0];
  c4_minmana = muIntScalarMin_sint32(c4_d_ma, 3);
  c4_tau_size[0] = c4_minmana;
  c4_b = (c4_b_A_size[0] == 0);
  if (c4_b || (c4_m < 1)) {
    c4_tau[0] = c4_tau_size[0];
    c4_tau_size[0] = c4_tau[0];
    c4_loop_ub = c4_tau[0] - 1;
    for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
      c4_tau_data[c4_i1] = 0.0;
    }

    for (c4_k = 0; c4_k < 3; c4_k++) {
      c4_b_k = c4_k;
      c4_jpvt[c4_b_k] = c4_b_k + 1;
    }
  } else {
    for (c4_i = 0; c4_i < 3; c4_i++) {
      c4_jpvt_t[c4_i] = (ptrdiff_t)0;
    }

    c4_lda_t = (ptrdiff_t)c4_d_ma;
    c4_m_t = (ptrdiff_t)c4_m;
    c4_n_t = (ptrdiff_t)3;
    c4_info_t = LAPACKE_dgeqp3(102, c4_m_t, c4_n_t, &c4_c_A_data[0], c4_lda_t,
      &c4_jpvt_t[0], &c4_tau_data[0]);
    c4_info = (int32_T)c4_info_t;
    c4_b_st.site = &c4_vb_emlrtRSI;
    c4_b_info = c4_info;
    c4_c_info = c4_b_info;
    c4_p = (c4_c_info != 0);
    if (c4_p) {
      c4_b_p = true;
      c4_val = c4_b_info;
      c4_c_p = false;
      if (c4_val == -4) {
        c4_c_p = true;
      }

      if (!c4_c_p) {
        if (c4_b_info == -1010) {
          c4_b_y = nullptr;
          sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          c4_d_y = nullptr;
          sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          sf_mex_call(&c4_b_st, &c4_m_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                      sf_mex_call(&c4_b_st, nullptr, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_b_st, nullptr, "message", 1U, 1U, 14, c4_d_y)));
        } else {
          c4_y = nullptr;
          sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1,
            33), false);
          c4_c_y = nullptr;
          sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1,
            33), false);
          c4_e_y = nullptr;
          sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2,
            1, 14), false);
          c4_f_y = nullptr;
          sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_b_info, 6, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call(&c4_b_st, &c4_o_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                      sf_mex_call(&c4_b_st, nullptr, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_b_st, nullptr, "message", 1U, 3U, 14, c4_c_y, 14,
                        c4_e_y, 14, c4_f_y)));
        }
      }
    } else {
      c4_b_p = false;
    }

    if (c4_b_p) {
      for (c4_j = 0; c4_j < 3; c4_j++) {
        c4_b_j = c4_j;
        c4_b_st.site = &c4_wb_emlrtRSI;
        c4_c_b = c4_m;
        c4_f_b = c4_c_b;
        if (c4_f_b < 1) {
          c4_b_overflow = false;
        } else {
          c4_b_overflow = (c4_f_b > 2147483646);
        }

        if (c4_b_overflow) {
          c4_c_st.site = &c4_h_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
        }

        for (c4_b_i = 0; c4_b_i < c4_m; c4_b_i++) {
          c4_c_i = c4_b_i;
          c4_c_A_data[c4_b_j * c4_d_ma + c4_c_i] = rtNaN;
        }
      }

      c4_minmn = muIntScalarMin_sint32(c4_m, 3);
      c4_b_st.site = &c4_xb_emlrtRSI;
      c4_b_b = c4_minmn;
      c4_e_b = c4_b_b;
      if (c4_e_b < 1) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_e_b > 2147483646);
      }

      if (c4_overflow) {
        c4_c_st.site = &c4_h_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      c4_i2 = static_cast<uint8_T>(c4_minmn) - 1;
      for (c4_d_k = 0; c4_d_k <= c4_i2; c4_d_k++) {
        c4_b_k = c4_d_k;
        c4_tau_data[c4_b_k] = rtNaN;
      }

      c4_i3 = c4_minmn;
      for (c4_e_k = c4_i3 + 1; c4_e_k <= c4_minmana; c4_e_k++) {
        c4_tau_data[c4_e_k - 1] = 0.0;
      }

      for (c4_f_k = 0; c4_f_k < 3; c4_f_k++) {
        c4_b_k = c4_f_k;
        c4_jpvt[c4_b_k] = c4_b_k + 1;
      }
    } else {
      for (c4_c_k = 0; c4_c_k < 3; c4_c_k++) {
        c4_b_k = c4_c_k;
        c4_jpvt[c4_b_k] = (int32_T)c4_jpvt_t[c4_b_k];
      }
    }
  }
}

static void c4_and(SFc4_PerceptionInstanceStruct *chartInstance, boolean_T
                   c4_b_in1_data[], int32_T c4_in1_size[1], boolean_T
                   c4_b_in2_data[], int32_T c4_in2_size[1], boolean_T
                   c4_in3_data[], int32_T c4_in3_size[1])
{
  int32_T c4_b_in2_size[1];
  int32_T c4_aux_0_0;
  int32_T c4_aux_1_0;
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_loop_ub;
  int32_T c4_stride_0_0;
  int32_T c4_stride_1_0;
  if (c4_in3_size[0] == 1) {
    c4_b_in2_size[0] = c4_in2_size[0];
  } else {
    c4_b_in2_size[0] = c4_in3_size[0];
  }

  c4_stride_0_0 = static_cast<int32_T>(c4_in2_size[0] != 1);
  c4_stride_1_0 = static_cast<int32_T>(c4_in3_size[0] != 1);
  c4_aux_0_0 = 0;
  c4_aux_1_0 = 0;
  if (c4_in3_size[0] == 1) {
    c4_i = c4_in2_size[0];
  } else {
    c4_i = c4_in3_size[0];
  }

  c4_loop_ub = c4_i - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    chartInstance->c4_in2_data[c4_i1] = (c4_b_in2_data[c4_aux_0_0] &&
      c4_in3_data[c4_aux_1_0]);
    c4_aux_1_0 += c4_stride_1_0;
    c4_aux_0_0 += c4_stride_0_0;
  }

  c4_in1_size[0] = c4_b_in2_size[0];
  c4_b_loop_ub = c4_b_in2_size[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_b_loop_ub; c4_i2++) {
    c4_b_in1_data[c4_i2] = chartInstance->c4_in2_data[c4_i2];
  }
}

static void c4_b_and(SFc4_PerceptionInstanceStruct *chartInstance, boolean_T
                     c4_b_in1_data[], int32_T c4_in1_size[1], boolean_T
                     c4_b_in2_data[], int32_T c4_in2_size[1])
{
  int32_T c4_b_in1_size[1];
  int32_T c4_aux_0_0;
  int32_T c4_aux_1_0;
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_loop_ub;
  int32_T c4_stride_0_0;
  int32_T c4_stride_1_0;
  if (c4_in2_size[0] == 1) {
    c4_b_in1_size[0] = c4_in1_size[0];
  } else {
    c4_b_in1_size[0] = c4_in2_size[0];
  }

  c4_stride_0_0 = static_cast<int32_T>(c4_in1_size[0] != 1);
  c4_stride_1_0 = static_cast<int32_T>(c4_in2_size[0] != 1);
  c4_aux_0_0 = 0;
  c4_aux_1_0 = 0;
  if (c4_in2_size[0] == 1) {
    c4_i = c4_in1_size[0];
  } else {
    c4_i = c4_in2_size[0];
  }

  c4_loop_ub = c4_i - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    chartInstance->c4_in1_data[c4_i1] = (c4_b_in1_data[c4_aux_0_0] &&
      c4_b_in2_data[c4_aux_1_0]);
    c4_aux_1_0 += c4_stride_1_0;
    c4_aux_0_0 += c4_stride_0_0;
  }

  c4_in1_size[0] = c4_b_in1_size[0];
  c4_b_loop_ub = c4_b_in1_size[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_b_loop_ub; c4_i2++) {
    c4_b_in1_data[c4_i2] = chartInstance->c4_in1_data[c4_i2];
  }
}

static void init_dsm_address_info(SFc4_PerceptionInstanceStruct *chartInstance)
{
}

static void init_simulink_io_address(SFc4_PerceptionInstanceStruct
  *chartInstance)
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
void sf_c4_Perception_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2473821306U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1551895779U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3996870331U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4270227645U);
}

mxArray *sf_c4_Perception_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,3);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "coder.internal.BoundedEmxArrayExternalDependency"));
  return(mxcell3p);
}

mxArray *sf_c4_Perception_jit_fallback_info(void)
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

mxArray *sf_c4_Perception_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_Perception(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Cg7o+lmw6GdF0i8A5acWFeUXQcMHFk7UdAdp+i"
    "H2exDwhziaP0D8zOL4xOSSzLLU+GST+IDUouTUgpLM/Dy4vwB05hqg"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Perception_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "szw8o7s5ZITgkPQ9K5deTmE";
}

static void sf_opaque_initialize_c4_Perception(void *chartInstanceVar)
{
  initialize_params_c4_Perception((SFc4_PerceptionInstanceStruct*)
    chartInstanceVar);
  initialize_c4_Perception((SFc4_PerceptionInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_Perception(void *chartInstanceVar)
{
  enable_c4_Perception((SFc4_PerceptionInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_Perception(void *chartInstanceVar)
{
  disable_c4_Perception((SFc4_PerceptionInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_Perception(void *chartInstanceVar)
{
  sf_gateway_c4_Perception((SFc4_PerceptionInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_Perception(SimStruct* S)
{
  return get_sim_state_c4_Perception((SFc4_PerceptionInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_Perception(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c4_Perception((SFc4_PerceptionInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_Perception(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_PerceptionInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Perception_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_Perception((SFc4_PerceptionInstanceStruct*)
      chartInstanceVar);
    ((SFc4_PerceptionInstanceStruct*) chartInstanceVar)->
      ~SFc4_PerceptionInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_Perception(void *chartInstanceVar)
{
  mdl_start_c4_Perception((SFc4_PerceptionInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc4_PerceptionInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c4_Perception(void *chartInstanceVar)
{
  mdl_terminate_c4_Perception((SFc4_PerceptionInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Perception(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Perception((SFc4_PerceptionInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc4_Perception((SFc4_PerceptionInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_Perception_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWN1uG0UUHltpRCmNeoEEF5WaC4S4QaqAKkFC0NQ/1JAQw9pF6k002T32jjw7s50fJ6647UP",
    "0DXgU7hESj8ENUi85s167ZmOcGTsqbVdar2d3vznnfHP+Zkmtc0Tw2MFz90NCtvH6Dp51Mj2ule",
    "Pawjm9v0W+Kse/vUtILBMYgojsYMDOSdghbNalimaahB+CZvATaMmtYVJ0xED6Y5kYgAIR4wS5V",
    "CZIrmaZ5UyM2lbETrL+OWVxGqXS8uQBTkiTY8En/yU3t6aLEptMQWzaAIlJlbTDtM3pcDULypw1",
    "UohH2mbBXGkwkc2dqfrIcsNyDq1ziDtCG4os6EvsjQw10DDnYSQ7e3U0Q8ss54wKf65TqiPI0Ts",
    "M9PMEf4+tQfY85aK8UyaokYpR3sp4I6XKF9vlqOcRujUP5tlkpgmndjhkYujYVTYDgfajn3hwNW",
    "jIMSg6hGMRJjd21rXOiwWe+6Un1rAMHlF1EKMfaEjCYhAdWEcUlxZ6OE0QFgQ95dDRPcXGuEahe",
    "aPjQmmtvGGzqSfptbCF3NYYV1WvKbcdiwblXIdhezI/hDHwQn6TGroGdio/AKw1S3oSvcNFbmD0",
    "W8GeWCixDSkS5u+V4wqqKBI/YML3gLPMhQEkSPNc9flEl8WR1UZmDQz95uGhp7yL2I4woAY0Bu9",
    "8rSjTgAoXfhUoN2HaBRKikSVTWOk9wzQG14ISPbCieSbVCDkOLQwvuXKREIaGZAhNMFAkuRZ69y",
    "PKrafOmcas7NyjrzHLhslFrIuftcAxjVNIXA1kHI4wz+IEvkusXfk8QGvHzEyaoGPFct9IspjQs",
    "fg5lnqTHPpiJOSZaCuZRWUXs8KvADBrUCWwlD3AUqombVTeT2sFT3pFdg9tGBzP1HB66nzjWxBY",
    "DZ2trnrTGKOqJbDdRIU2wUbsKbYjQjNtsAWctIoYSIo++D552QdvLemDby70wbfKcfzFSRdUDHm",
    "ZX9w8dxfmec+jnyYeOHIBR+a42fWTBXxtiVyycK3Ku15frWcd/9VK3CJPNytytiq47ZKr/t83fn",
    "/+0S9/fLz37LP3v9vrbiL/13rYfmWnHN+e9UrzzDy+kLzcuw8v8YMPKn7gxvrp2b7c0/ced3rDU",
    "ffHL7+/l0AvaxXzvait1rde0Xd2f9f1Zxi4RR5QcScp9z1uTO20H3fz7y/ou30JH9cX/ImQv77Z",
    "DL97v4pfxte1Cl9uDEpJVfHfq9QjDL/+ujN9Ql12hpN/Z4KdK4izUNybIu9t1/Mq7fOpH68aR14",
    "xblP7Quvim/7+3RV5jFTev/Ua21G9rtsfvW52/UnC+pc75fjr+Z68kTKeLNkVlI+xcR8se/qW+P",
    "eLQP5mdbvl+Cs/hD7+/EBQPsFtwHSbVd7uKvcNbv5IAdXL91r/Rz1Z1if59lv9XvvT/Q3q0j+zn",
    "wIZ",
    ""
  };

  static char newstr [1429] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_Perception(SimStruct *S)
{
  const char* newstr = sf_c4_Perception_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3540776277U));
  ssSetChecksum1(S,(3581682841U));
  ssSetChecksum2(S,(847591206U));
  ssSetChecksum3(S,(1345800724U));
}

static void mdlRTW_c4_Perception(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_Perception(SimStruct *S)
{
  SFc4_PerceptionInstanceStruct *chartInstance;
  chartInstance = (SFc4_PerceptionInstanceStruct *)utMalloc(sizeof
    (SFc4_PerceptionInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_PerceptionInstanceStruct));
  chartInstance = new (chartInstance) SFc4_PerceptionInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_Perception;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_Perception;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_Perception;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c4_Perception;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_Perception;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_Perception;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_Perception;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_Perception;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_Perception;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_Perception;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Perception;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_Perception;
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

  mdl_setup_runtime_resources_c4_Perception(chartInstance);
}

void c4_Perception_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_Perception(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Perception(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Perception(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Perception_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
