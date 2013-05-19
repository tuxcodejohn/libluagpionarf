dnl Process this file with autoconf to produce a configure script

AC_INIT([luaionarf], 0.1, [john@tuxcode.org])
dnl AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([foreign no-dist-gzip dist-xz])
LT_INIT([disable-static])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])


PKG_CHECK_MODULES([LUASTUFF],[lua5.1])

dnl Lua 5.1
dnl AX_PROG_LUA(501)
dnl AC_SUBST(LUA)

dnl Generate output files
AC_CONFIG_MACRO_DIR(m4)
AC_CONFIG_FILES(Makefile)
AC_OUTPUT
