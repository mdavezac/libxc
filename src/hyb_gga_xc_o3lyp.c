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

#define XC_HYB_GGA_XC_O3LYP   404 /* hybrid using the optx functional */
#define XC_HYB_GGA_XC_X3LYP   411 /* hybrid by Xu and Goddard */


/*************************************************************/
static void
gga_xc_o3lyp_init(XC(func_type) *p)
{
  const FLOAT a = 0.1161, b = 0.9262, c = 0.8133, CC = 0.81, a1 = 1.05151;
  static int funcs_id  [4] = {XC_LDA_X, XC_GGA_X_OPTX, XC_LDA_C_VWN, XC_GGA_C_LYP};
  FLOAT funcs_coef[4];

  /* \Delta OPTX is not described in the paper, so there are multiple
     different plausible choices for the LDA exchange
     coefficient. This one gives the right energies.
   */
  funcs_coef[0] = b - a1*c;
  funcs_coef[1] = c;
  funcs_coef[2] = 1.0 - CC;
  funcs_coef[3] = CC;

  XC(mix_init)(p, 4, funcs_id, funcs_coef);
  XC(lda_c_vwn_set_params)(p->func_aux[2], 1);
  p->cam_alpha = a;
}

const XC(func_info_type) XC(func_info_hyb_gga_xc_o3lyp) = {
  XC_HYB_GGA_XC_O3LYP,
  XC_EXCHANGE_CORRELATION,
  "O3LYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Cohen2001_607, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-32, 1e-32, 0.0, 1e-32,
  gga_xc_o3lyp_init,
  NULL, NULL, NULL, NULL
};


/*************************************************************/
static void
gga_xc_x3lyp_init(XC(func_type) *p)
{
  const FLOAT a1=0.765, a2=0.235;
  const FLOAT a0=0.218, ax=0.709, ac=0.871;

  static int funcs_id[5] = {XC_LDA_X, XC_GGA_X_B88, XC_GGA_X_PW91, XC_LDA_C_VWN_RPA, XC_GGA_C_LYP};
  FLOAT funcs_coef[5];

  funcs_coef[0] = 1.0 - a0 - ax*(a1 + a2);
  funcs_coef[1] = ax*a1;
  funcs_coef[2] = ax*a2;
  funcs_coef[3] = 1.0 - ac;
  funcs_coef[4] = ac;

  XC(mix_init)(p, 5, funcs_id, funcs_coef);
  p->cam_alpha = a0;
}

const XC(func_info_type) XC(func_info_hyb_gga_xc_x3lyp) = {
  XC_HYB_GGA_XC_X3LYP,
  XC_EXCHANGE_CORRELATION,
  "X3LYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Xu2004_2673, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-32, 1e-32, 0.0, 1e-32,
  gga_xc_x3lyp_init,
  NULL, NULL, NULL, NULL
};
