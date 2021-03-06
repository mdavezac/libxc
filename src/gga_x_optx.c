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

#define XC_GGA_X_OPTX         110 /* Handy & Cohen OPTX 01                          */

typedef struct{
  FLOAT a, b, gamma;
} gga_x_optx_params;


static void 
gga_x_optx_init(XC(func_type) *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_x_optx_params));

  XC(gga_x_optx_set_params)(p, 1.05151, 1.43169/X_FACTOR_C, 0.006);
}


void 
XC(gga_x_optx_set_params)(XC(func_type) *p, FLOAT a, FLOAT b, FLOAT gamma)
{
  gga_x_optx_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_x_optx_params *) (p->params);

  params->a     = a;
  params->b     = b;
  params->gamma = gamma;
}


void XC(gga_x_optx_enhance)
  (const XC(func_type) *p, int order, FLOAT x, 
   FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{
  FLOAT a, b, gamma;
  FLOAT num, dnum, d2num, den, u, du, d2u, d3u;

  assert(p->params != NULL);
  a     = ((gga_x_optx_params *) (p->params))->a;
  b     = ((gga_x_optx_params *) (p->params))->b;
  gamma = ((gga_x_optx_params *) (p->params))->gamma;

  num = gamma*x*x;
  den = 1.0 + num;
  u  = num/den;

  *f = a + b*u*u;
  
  if(order < 1) return;

  dnum = 2.0*gamma*x;
  du   = DFRACTION(num, dnum, den, dnum);

  *dfdx  = 2.0*b*u*du;

  if(order < 2) return;

  d2num = 2.0*gamma;
  d2u   = D2FRACTION(num, dnum, d2num, den, dnum, d2num);

  *d2fdx2 = 2.0*b*(du*du + u*d2u);

  if(order < 3) return;

  d3u = D3FRACTION(num, dnum, d2num, 0.0, den, dnum, d2num, 0.0);

  *d3fdx3 = 2.0*b*(3.0*du*d2u + u*d3u);
}


#define func XC(gga_x_optx_enhance)
#include "work_gga_x.c"

const XC(func_info_type) XC(func_info_gga_x_optx) = {
  XC_GGA_X_OPTX,
  XC_EXCHANGE,
  "Handy & Cohen OPTX 01",
  XC_FAMILY_GGA,
  {&xc_ref_Handy2001_403, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC | XC_FLAGS_HAVE_KXC,
  1e-32, 1e-32, 0.0, 1e-32,
  gga_x_optx_init,
  NULL, NULL,
  work_gga_x,
  NULL
};
