## Process this file with automake to produce Makefile.in

## Copyright (C) 2002 M. Marques, A. Castro, A. Rubio, G. Bertsch
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation; either version 2, or (at your option)
## any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
## 02110-1301, USA.
##
## $Id: Makefile.am 12344 2016-04-20 21:03:16Z lehtola $

bin_PROGRAMS = xc-info
noinst_PROGRAMS = genwiki

xc_info_SOURCES = xc-info.c
xc_info_LDADD = libxc.la -lm
xc_info_LDFLAGS =

genwiki_SOURCES = genwiki.c
genwiki_LDADD = libxc.la -lm
genwiki_LDFLAGS =

lib_LTLIBRARIES = libxc.la

libxc_la_FUNC_SOURCES = \
	special_functions.c bessel.c expint_e1.c integrate.c util.c	\
	mix_func.c func_info.c functionals.c version.c \
	lda.c \
        lda_x.c lda_x_1d.c lda_x_2d.c lda_c_wigner.c lda_c_gombas.c	\
	lda_c_rpa.c lda_c_hl.c lda_c_vwn.c lda_c_pz.c lda_c_pw.c	\
	lda_c_ml1.c lda_c_rc04.c lda_xc_teter93.c lda_c_1d_csc.c	\
	lda_c_1d_loos.c lda_c_2d_amgb.c lda_c_2d_prm.c stoll.c		\
	lda_k_tf.c lda_xc_zlp.c lda_xc_ksdt.c                           \
	gga.c \
	gga_x_lg93.c gga_x_pbe.c gga_x_rpbe.c gga_x_pbea.c		\
	gga_x_mpbe.c gga_x_herman.c gga_x_b86.c gga_x_b88.c		\
	gga_x_g96.c gga_x_pw86.c gga_x_pw91.c gga_x_optx.c		\
	gga_x_airy.c gga_x_c09x.c gga_x_dk87.c gga_x_ft97.c		\
	gga_x_wc.c gga_x_am05.c gga_x_bayesian.c gga_x_kt.c		\
	gga_x_htbs.c gga_c_pbe.c gga_c_lyp.c gga_c_p86.c gga_c_pw91.c	\
	gga_c_am05.c gga_c_lm.c gga_c_wl.c gga_c_wi.c gga_x_lb.c	\
	gga_xc_b97.c gga_xc_edf1.c gga_xc_1w.c gga_c_optc.c		\
	gga_c_tca.c gga_x_bpccac.c gga_x_sogga11.c gga_c_sogga11.c	\
	gga_xc_th.c gga_x_wpbeh.c gga_x_hjs.c gga_x_ityh.c		\
	gga_x_sfat.c gga_x_ev93.c gga_x_ak13.c gga_x_q2d.c gga_c_q2d.c	\
	gga_x_ssb_sw.c gga_c_ft97.c gga_c_op.c gga_x_n12.c		\
	gga_x_lv_rpw86.c gga_x_2d_b86.c gga_x_2d_b86_mgc.c		\
	gga_x_2d_b88.c gga_x_2d_pbe.c gga_k_tflw.c gga_k_pearson.c	\
	gga_k_ol1.c gga_k_ol2.c gga_k_dk.c gga_k_meyer.c gga_x_vmt.c	\
	gga_x_hcth_a.c gga_x_cap.c \
	gga_xc_oblyp_d.c hyb_gga_xc_b3lyp.c hyb_gga_xc_o3lyp.c		\
	hyb_gga_xc_pbeh.c hyb_gga_xc_b1wc.c 				\
	hyb_gga_xc_hse.c hyb_gga_xc_cam_b3lyp.c				\
	hyb_gga_xc_camy_blyp.c hyb_gga_xc_camy_b3lyp.c			\
	hyb_gga_xc_lcy_pbe.c hyb_gga_xc_lcy_blyp.c gga_xc_vv10.c \
	hyb_gga_xc_edf2.c \
	mgga.c \
	mgga_x_lta.c mgga_x_tpss.c mgga_x_br89.c mgga_x_gvt4.c	\
	mgga_x_m06l.c mgga_x_tau_hcth.c mgga_x_2d_prhg07.c	\
	mgga_x_pkzb.c mgga_x_m05.c mgga_x_m08.c mgga_x_ms.c	\
	mgga_x_mn12.c mgga_x_mk00.c mgga_c_vsxc.c mgga_c_pkzb.c	\
	mgga_c_bc95.c mgga_c_m08.c mgga_c_cc06.c mgga_c_cs.c	\
	mgga_xc_otpss_d.c mgga_xc_zlp.c hyb_mgga_xc_m05.c	\
	mgga_x_mbeef.c mgga_xc_b97mv.c mgga_x_scan.c mgga_c_scan.c \
	hyb_mgga_xc_tpssh.c mgga_x_mvs.c hyb_mgga_x_mvsh.c

libxc_la_FUNC_SINGLE_SOURCES = $(libxc_la_FUNC_SOURCES:.c=_s.c)

libxc_la_SOURCES = references.c $(libxc_la_FUNC_SOURCES)
libxc_la_LDFLAGS = -version-info $(XC_LT_VERSION)

if COMPILE_SINGLE
  nodist_libxc_la_SOURCES = $(libxc_la_FUNC_SINGLE_SOURCES)
endif

if COMPILE_FORTRAN
  lib_LTLIBRARIES += libxcf90.la

  libxcf90_la_SOURCES = xc_f.c
  nodist_libxcf90_la_SOURCES = libxc_funcs.f90 libxc.f90
if COMPILE_SINGLE
    nodist_libxcf90_la_SOURCES += xc_f_s.c libxc_s.f90
endif

  # libtool stuff
  libxcf90_la_LDFLAGS = -version-info $(XC_LT_VERSION)
  libxcf90_la_LIBADD = libxc.la

  # this is a hack to go around buggy libtool/automake versions
  libxcf90_la_LIBTOOLFLAGS = --tag=F77
endif

if COMPILE_FORTRAN03
  lib_LTLIBRARIES += libxcf03.la

  nodist_libxcf03_la_SOURCES = libxcf03.f90
if COMPILE_SINGLE
    nodist_libxcf03_la_SOURCES += libxcf03_s.f90
endif

  # libtool stuff
  libxcf03_la_LDFLAGS = -version-info $(XC_LT_VERSION)
  libxcf03_la_LIBADD = libxc.la

  # this is a hack to go around buggy libtool/automake versions
  libxcf03_la_LIBTOOLFLAGS = --tag=F77
endif


# this is a hack to go around buggy libtool/automake versions
LTFCCOMPILE = $(LIBTOOL) --mode=compile --tag=F77 $(FC) $(AM_FCFLAGS) $(FCFLAGS)
FCLINK = $(LIBTOOL) --mode=link --tag=F77 $(FCLD) $(AM_FCFLAGS) $(FCFLAGS) \
         $(AM_LDFLAGS) $(LDFLAGS) -o $@

dist_noinst_SCRIPTS = get_funcs.pl

noinst_HEADERS = \
	string_f.h references.h util.h work_lda.c \
	work_gga_x.c work_gga_c.c \
	work_mgga_x.c work_mgga_c.c \
	libxc_master.F90 libxc_master.F03
include_HEADERS = xc.h xc_config.h xc_unconfig.h
nodist_include_HEADERS = xc_funcs.h

if COMPILE_SINGLE
  include_HEADERS += xc_s.h
endif

BUILT_SOURCES = xc_funcs.h

## declare fortran modules so they are installed
if COMPILE_FORTRAN

if F90_MOD_UPPERCASE
  LIBFUNCMOD = LIBXC_FUNCS_M.@ax_cv_f90_modext@
else
  LIBFUNCMOD = libxc_funcs_m.@ax_cv_f90_modext@
endif
nodist_include_HEADERS += $(LIBFUNCMOD)

# Double precision modules are always compiled
if F90_MOD_UPPERCASE
  XCLIBMODS = XC_F90_LIB_M.@ax_cv_f90_modext@ XC_F90_TYPES_M.@ax_cv_f90_modext@
else
  XCLIBMODS = xc_f90_lib_m.@ax_cv_f90_modext@ xc_f90_types_m.@ax_cv_f90_modext@
endif
nodist_include_HEADERS += $(XCLIBMODS)

if COMPILE_SINGLE

if F90_MOD_UPPERCASE
  LIBSFUNCMOD = LIBXC_S_FUNCS_M.@ax_cv_f90_modext@
else
  LIBSFUNCMOD = libxc_s_funcs_m.@ax_cv_f90_modext@
endif
nodist_include_HEADERS += $(LIBSFUNCMOD)

if F90_MOD_UPPERCASE
  XCLIBMODS_S = XC_S_F90_LIB_M.@ax_cv_f90_modext@ XC_S_F90_TYPES_M.@ax_cv_f90_modext@
else
  XCLIBMODS_S = xc_s_f90_lib_m.@ax_cv_f90_modext@ xc_s_f90_types_m.@ax_cv_f90_modext@
endif
nodist_include_HEADERS += $(XCLIBMODS_S)

endif # COMPILE_SINGLE

endif # COMPILE_FORTRAN


if COMPILE_FORTRAN03

# Double precision modules are always compiled
if F90_MOD_UPPERCASE
  XCF03LIBMODS = XC_F03_LIB_M.@ax_cv_f90_modext@
else
  XCF03LIBMODS = xc_f03_lib_m.@ax_cv_f90_modext@
endif
nodist_include_HEADERS += $(XCF03LIBMODS)

if COMPILE_SINGLE

if F90_MOD_UPPERCASE
  XCF03LIBMODS_S = XC_S_F03_LIB_M.@ax_cv_f90_modext@
else
  XCF03LIBMODS_S = xc_s_f03_lib_m.@ax_cv_f90_modext@
endif
nodist_include_HEADERS += $(XCF03LIBMODS_S)

endif # COMPILE_SINGLE

endif # COMPILE_FORTRAN03


SUFFIXES = _s.c
.c_s.c:
	@CPP@ -D SINGLE_PRECISION @CPPFLAGS@ $(INCLUDES) $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $< > $*_s.c

CLEANFILES = *~ *.bak *.mod *.il *.d *.pc* ifc* funcs_*.c funcs.h \
	libxc.f90 libxc_funcs.f90 libxcf03.f90 libxc_inc.f03 xc_funcs.h *_s.c *_s.f90 libxc_docs.txt

xc_funcs.h libxc_inc.f03 libxc_funcs.f90 funcs_lda.c funcs_gga.c funcs_hyb_gga.c funcs_mgga.c funcs_hyb_mgga.c funcs_key.c: get_funcs.pl
	$(srcdir)/get_funcs.pl $(srcdir) $(top_builddir)/src

#These files are in the repository, and the command below should be run to update them whenever references are changed.
#references.c references.h: get_references.pl ../libxc.bib
references:
	$(srcdir)/get_references.pl $(srcdir)/../libxc.bib

LTPREF = $(subst xc_f.lo,,$(firstword $(am_libxcf90_la_OBJECTS)))
# Surprisingly, libtool/automake do not seem to provide a macro or variable for what the object names will be,
# so we have to extract it ourselves. LTPREF=libxcf90_la-, or blank for older libtool/automake versions.
# Produces these warnings on some systems. Does not seem to matter.
#src/Makefile.am:140: subst xc_f.lo,,$(firstword $(am_libxcf90_la_OBJECTS: non-POSIX variable name
#src/Makefile.am:140: (probably a GNU make extension)

$(LIBFUNCMOD) $(LIBSFUNCMOD): $(LTPREF)libxc_funcs.lo

libxc.f90 : libxc_master.F90
	@FCCPP@ @CPPFLAGS@ $(AM_CPPFLAGS) $(srcdir)/libxc_master.F90 > $(top_builddir)/src/libxc.f90
	@if [ "@F90_ACCEPTS_LINE_NUMBERS@" = "no" ]; then \
		grep -v "^#" $(top_builddir)/src/libxc.f90 > $(top_builddir)/src/libxc.f91; \
		mv -f $(top_builddir)/src/libxc.f91 $(top_builddir)/src/libxc.f90; \
	fi
libxc_s.f90 : libxc_master.F90
	@FCCPP@ -D SINGLE_PRECISION @CPPFLAGS@ $(AM_CPPFLAGS) $(srcdir)/libxc_master.F90 > $(top_builddir)/src/libxc_s.f90
	@if [ "@F90_ACCEPTS_LINE_NUMBERS@" = "no" ]; then \
		grep -v "^#" $(top_builddir)/src/libxc_s.f90 > $(top_builddir)/src/libxc_s.f91; \
		mv -f $(top_builddir)/src/libxc_s.f91 $(top_builddir)/src/libxc_s.f90; \
	fi

$(LTPREF)libxc.lo   $(LTPREF)libxc.o   : $(LIBFUNCMOD)
$(LTPREF)libxc_s.lo $(LTPREF)libxc_s.o : $(LIBSFUNCMOD)

$(XCLIBMODS)   : $(LTPREF)libxc.lo
$(XCLIBMODS_S) : $(LTPREF)libxc_s.lo


LTPREF03 = $(subst libxcf03.lo,,$(firstword $(nodist_libxcf03_la_OBJECTS)))
libxcf03.f90 : libxc_master.F03 libxc_inc.f03
	@FCCPP@ @CPPFLAGS@ $(AM_CPPFLAGS) -I$(top_builddir)/src $(srcdir)/libxc_master.F03 > $(top_builddir)/src/libxcf03.f90
	@if [ "@F90_ACCEPTS_LINE_NUMBERS@" = "no" ]; then \
		grep -v "^#" $(top_builddir)/src/libxcf03.f90 > $(top_builddir)/src/libxcf03.f91; \
		mv -f $(top_builddir)/src/libxcf03.f91 $(top_builddir)/src/libxcf03.f90; \
	fi
libxcf03_s.f90 : libxc_master.F03 libxc_inc.f03
	@FCCPP@ -D SINGLE_PRECISION @CPPFLAGS@ $(AM_CPPFLAGS) -I$(top_builddir)/src $(srcdir)/libxc_master.F03 > $(top_builddir)/src/libxcf03_s.f90
	@if [ "@F90_ACCEPTS_LINE_NUMBERS@" = "no" ]; then \
		grep -v "^#" $(top_builddir)/src/libxcf03_s.f90 > $(top_builddir)/src/libxcf03_s.f91; \
		mv -f $(top_builddir)/src/libxcf03_s.f91 $(top_builddir)/src/libxcf03_s.f90; \
	fi

$(XCF03LIBMODS)   : $(LTPREF03)libxcf03.lo
$(XCF03LIBMODS_S) : $(LTPREF03)libxcf03_s.lo
