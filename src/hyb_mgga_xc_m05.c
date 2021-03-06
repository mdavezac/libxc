/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.
  
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
  
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "util.h"

#define XC_HYB_MGGA_XC_M05      438  /* M05 functional from Minnesota                                */
#define XC_HYB_MGGA_XC_M05_2X   439  /* M05-2X functional from Minnesota                             */
#define XC_HYB_MGGA_XC_B88B95   440  /* Mixture of B88 with BC95 (B1B95)                             */
#define XC_HYB_MGGA_XC_B86B95   441  /* Mixture of B86 with BC95                                     */
#define XC_HYB_MGGA_XC_PW86B95  442  /* Mixture of PW86 with BC95                                    */
#define XC_HYB_MGGA_XC_BB1K     443  /* Mixture of B88 with BC95 from Zhao and Truhlar               */
#define XC_HYB_MGGA_XC_MPW1B95  445  /* Mixture of mPW91 with BC95 from Zhao and Truhlar             */
#define XC_HYB_MGGA_XC_MPWB1K   446  /* Mixture of mPW91 with BC95 for kinetics                      */
#define XC_HYB_MGGA_XC_X1B95    447  /* Mixture of X with BC95                                       */
#define XC_HYB_MGGA_XC_XB1K     448  /* Mixture of X with BC95 for kinetics                          */
#define XC_HYB_MGGA_XC_M06_HF   444  /* M06-HF functional from Minnesota                             */
#define XC_HYB_MGGA_XC_M06      449  /* M06 functional from Minnesota                                */
#define XC_HYB_MGGA_XC_M06_2X   450  /* M06-2X functional from Minnesota                             */
#define XC_HYB_MGGA_XC_PW6B95   451  /* Mixture of PW91 with BC95 from Zhao and Truhlar              */
#define XC_HYB_MGGA_XC_PWB6K    452  /* Mixture of PW91 with BC95 from Zhao and Truhlar for kinetics */
#define XC_MGGA_XC_TPSSLYP1W    242  /* Functionals fitted for water                                 */

/*************************************************************/
void
XC(hyb_mgga_xc_m05_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_MGGA_X_M05, XC_MGGA_C_M05};
  static FLOAT funcs_coef[2] = {1.0 - 0.28, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.28;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_m05) = {
  XC_HYB_MGGA_XC_M05,
  XC_EXCHANGE_CORRELATION,
  "Minnesota M05 functional",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2005_161103, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_m05_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_m05_2x_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_MGGA_X_M05_2X, XC_MGGA_C_M05_2X};
  static FLOAT funcs_coef[2] = {1.0 - 0.56, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.56;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_m05_2x) = {
  XC_HYB_MGGA_XC_M05_2X,
  XC_EXCHANGE_CORRELATION,
  "Minnesota M05-2X functional",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2006_364, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_m05_2x_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_b88b95_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_B88, XC_MGGA_C_BC95};
  static FLOAT funcs_coef[2] = {1.0 - 0.28, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.28;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_b88b95) = {
  XC_HYB_MGGA_XC_B88B95,
  XC_EXCHANGE_CORRELATION,
  "Mixture of B88 with BC95 (B1B95)",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Becke1996_1040, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_b88b95_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_b86b95_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_B86, XC_MGGA_C_BC95};
  static FLOAT funcs_coef[2] = {1.0 - 0.28, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.28;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_b86b95) = {
  XC_HYB_MGGA_XC_B86B95,
  XC_EXCHANGE_CORRELATION,
  "Mixture of B86 with BC95",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Becke1996_1040, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_b86b95_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_pw86b95_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_PW86, XC_MGGA_C_BC95};
  static FLOAT funcs_coef[2] = {1.0 - 0.29, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.29;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_pw86b95) = {
  XC_HYB_MGGA_XC_PW86B95,
  XC_EXCHANGE_CORRELATION,
  "Mixture of PW86 with BC95",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Becke1996_1040, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_pw86b95_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_bb1k_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_B88, XC_MGGA_C_BC95};
  static FLOAT funcs_coef[2] = {1.0 - 0.42, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.42;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_bb1k) = {
  XC_HYB_MGGA_XC_BB1K,
  XC_EXCHANGE_CORRELATION,
  "Mixture of B88 with BC95 from Zhao and Truhlar",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2004_2715, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_bb1k_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_mpw1b95_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_MPW91, XC_MGGA_C_BC95};
  static FLOAT funcs_coef[2] = {1.0 - 0.31, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.31;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_mpw1b95) = {
  XC_HYB_MGGA_XC_MPW1B95,
  XC_EXCHANGE_CORRELATION,
  "Mixture of mPW91 with BC95 from Zhao and Truhlar",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2004_6908, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_mpw1b95_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_mpwb1k_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_MPW91, XC_MGGA_C_BC95};
  static FLOAT funcs_coef[2] = {1.0 - 0.44, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.44;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_mpwb1k) = {
  XC_HYB_MGGA_XC_MPWB1K,
  XC_EXCHANGE_CORRELATION,
  "Mixture of mPW91 with BC95 for kinetics",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2004_6908, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_mpwb1k_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_x1b95_init)(XC(func_type) *p)
{
  const FLOAT a1=0.675, a2=0.235, a0=0.30;

  static int   funcs_id  [3] = {XC_GGA_X_B88, XC_GGA_X_PW91, XC_MGGA_C_BC95};
  FLOAT funcs_coef[3];

  funcs_coef[0] = a0*a1;
  funcs_coef[1] = a0*a2;
  funcs_coef[2] = 1.0;

  XC(mix_init)(p, 3, funcs_id, funcs_coef);
  p->cam_alpha = a0;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_x1b95) = {
  XC_HYB_MGGA_XC_X1B95,
  XC_EXCHANGE_CORRELATION,
  "Mixture of X with BC95",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2004_6908, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_x1b95_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_xb1k_init)(XC(func_type) *p)
{
  const FLOAT a1=0.675, a2=0.235, a0=0.43;

  static int   funcs_id  [3] = {XC_GGA_X_B88, XC_GGA_X_PW91, XC_MGGA_C_BC95};
  FLOAT funcs_coef[3];

  funcs_coef[0] = a0*a1;
  funcs_coef[1] = a0*a2;
  funcs_coef[2] = 1.0;

  XC(mix_init)(p, 3, funcs_id, funcs_coef);
  p->cam_alpha = a0;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_xb1k) = {
  XC_HYB_MGGA_XC_XB1K,
  XC_EXCHANGE_CORRELATION,
  "Mixture of X with BC95 for kinetics",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2004_6908, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_xb1k_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_m06_hf_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_MGGA_X_M06_HF, XC_MGGA_C_M06_HF};
  FLOAT funcs_coef[2] = {1.0, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 1.0;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_m06_hf) = {
  XC_HYB_MGGA_XC_M06_HF,
  XC_EXCHANGE_CORRELATION,
  "Minnesota M06-HF functional",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2006_13126, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  MIN_DENS, MIN_GRAD, MIN_TAU, MIN_ZETA,
  XC(hyb_mgga_xc_m06_hf_init),
  NULL, NULL, NULL, NULL
};


/*************************************************************/
void
XC(hyb_mgga_xc_m06_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_MGGA_X_M06, XC_MGGA_C_M06};
  FLOAT funcs_coef[2] = {1.0, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.27;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_m06) = {
  XC_HYB_MGGA_XC_M06,
  XC_EXCHANGE_CORRELATION,
  "Minnesota M06 functional",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2008_215, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  MIN_DENS, MIN_GRAD, MIN_TAU, MIN_ZETA,
  XC(hyb_mgga_xc_m06_init),
  NULL, NULL, NULL, NULL
};


/*************************************************************/
void
XC(hyb_mgga_xc_m06_2x_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_MGGA_X_M06_2X, XC_MGGA_C_M06_2X};
  FLOAT funcs_coef[2] = {1.0, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  p->cam_alpha = 0.54;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_m06_2x) = {
  XC_HYB_MGGA_XC_M06_2X,
  XC_EXCHANGE_CORRELATION,
  "Minnesota M06-2X functional",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2008_215, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  MIN_DENS, MIN_GRAD, MIN_TAU, MIN_ZETA,
  XC(hyb_mgga_xc_m06_2x_init),
  NULL, NULL, NULL, NULL
};


/*************************************************************/
void
XC(hyb_mgga_xc_pw6b95_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_PW91, XC_MGGA_C_BC95};
  static FLOAT funcs_coef[2] = {1.0 - 0.28, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  XC(gga_x_pw91_set_params2)(p->func_aux[0], 0.00538, 1.7382/(X2S*X2S), 3.8901);
  XC(mgga_c_bc95_set_params)(p->func_aux[1], 0.03668, 0.00262);
  p->cam_alpha = 0.28;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_pw6b95) = {
  XC_HYB_MGGA_XC_PW6B95,
  XC_EXCHANGE_CORRELATION,
  "Mixture of PW91 with BC95 from Zhao and Truhlar",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2005_5656, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_pw6b95_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
void
XC(hyb_mgga_xc_pwb6k_init)(XC(func_type) *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_PW91, XC_MGGA_C_BC95};
  static FLOAT funcs_coef[2] = {1.0 - 0.46, 1.0};

  XC(mix_init)(p, 2, funcs_id, funcs_coef);
  XC(gga_x_pw91_set_params2)(p->func_aux[0], 0.00539, 1.7077/(X2S*X2S), 4.0876);
  XC(mgga_c_bc95_set_params)(p->func_aux[1], 0.04120, 0.00353);
  p->cam_alpha = 0.46;
}

const XC(func_info_type) XC(func_info_hyb_mgga_xc_pwb6k) = {
  XC_HYB_MGGA_XC_PWB6K,
  XC_EXCHANGE_CORRELATION,
  "Mixture of PW91 with BC95 from Zhao and Truhlar for kinetics",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2005_5656, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-32, 1e-32, 1e-32, 1e-32,
  XC(hyb_mgga_xc_pwb6k_init),
  NULL, NULL, NULL, NULL,
};


/*************************************************************/
static void
mgga_xc_tpsslyp1w_init(XC(func_type) *p)
{
  static int   funcs_id  [3] = {XC_LDA_C_VWN, XC_MGGA_X_TPSS, XC_GGA_C_LYP};
  static FLOAT funcs_coef[3] = {1.0 - 74.0/100.0, 1.0, 74.0/100.0};

  XC(mix_init)(p, 3, funcs_id, funcs_coef);
}

const XC(func_info_type) XC(func_info_mgga_xc_tpsslyp1w) = {
  XC_MGGA_XC_TPSSLYP1W,
  XC_EXCHANGE_CORRELATION,
  "TPSSLYP1W",
  XC_FAMILY_MGGA,
  {&xc_ref_Dahlke2005_15677, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-32, 1e-32, 0.0, 1e-32,
  mgga_xc_tpsslyp1w_init, 
  NULL, NULL, NULL, NULL
};
