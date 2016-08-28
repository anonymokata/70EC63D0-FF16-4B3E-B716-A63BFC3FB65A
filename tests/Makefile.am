## Process this file with automake to produce Makefile.in

TESTS = \
  check_romancalc
  
check_PROGRAMS = check_romancalc

check_romancalc_SOURCES = \
  check_romancalc.h \
  check_romancalc.c \
  check_romancalc_main.c

check_romancalc_CFLAGS = @CHECK_CFLAGS@

check_romancalc_LDADD = $(top_builddir)/src/libromancalc.la @CHECK_LIBS@
