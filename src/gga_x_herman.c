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
#include <assert.h>
#include "util.h"

#define XC_GGA_X_HERMAN          104 /* Herman et al original GGA                  */

void XC(gga_x_herman_enhance)
  (const XC(func_type) *p, int order, FLOAT x, 
   FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{
  static const FLOAT beta  = 0.003/X_FACTOR_C;

  *f = 1.0 + beta*x*x;
  
  if(order < 1) return;

  *dfdx  = 2.0*beta*x;

  if(order < 2) return;

  *d2fdx2 = 2.0*beta;

  if(order < 3) return;

  *d3fdx3 = 0.0;
}

#define func XC(gga_x_herman_enhance)
#include "work_gga_x.c"

const XC(func_info_type) XC(func_info_gga_x_herman) = {
  XC_GGA_X_HERMAN,
  XC_EXCHANGE,
  "Herman Xalphabeta GGA",
  XC_FAMILY_GGA,
  {&xc_ref_Herman1969_807, &xc_ref_Herman1969_827, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC | XC_FLAGS_HAVE_KXC,
  1e-32, 1e-32, 0.0, 1e-32,
  NULL, NULL, NULL,
  work_gga_x,
  NULL
};
