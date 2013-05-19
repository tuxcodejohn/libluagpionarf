## Process this file with automake to produce Makefile.in

# Build a libtool library, libhello.la for installation in libdir.
lib_LTLIBRARIES = libluagpionarf.la
libluagpionarf_la_SOURCES = gpionarf.c luaifac.c
libluagpionarf_la_CFLAGS  = $(LUASTUFF_CFLAGS)
libluagpionarf_la_LDFLAGS = $(LUASTUFF_LIBS) -version-info 1:0:0 

# dist_noinst_SCRIPTS = gpiosample.lua


dist-hook: ChangeLog

ChangeLog: configure.ac
	git log --stat --name-only --date=short --abbrev-commit > ChangeLog

