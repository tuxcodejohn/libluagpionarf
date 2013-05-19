## Process this file with automake to produce Makefile.in

# Build a libtool library, libhello.la for installation in libdir.
lib_LTLIBRARIES = libluagpio.la
libluagpio_la_SOURCES = gpionarf.c luaifac.c
libluagpio_la_LDFLAGS = -version-info 1:0:0


dist_noinst_SCRIPTS = gpiosample.lua


dist-hook: ChangeLog

ChangeLog: configure.ac
	git log --stat --name-only --date=short --abbrev-commit > ChangeLog

