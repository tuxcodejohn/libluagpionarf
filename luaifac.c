#include <lualib.h>
#include <lauxlib.h>
#include "gpionarf.h"


static int 
l_gpionarf (lua_State *L) {
	int n = lua_gettop(L);    /* number of arguments */
	int gpio, val;
	lua_Number res;
	gpio  = luaL_checkint (L,1);
	val  = luaL_checkint (L,2);
	res = (lua_Number) set_gpio_toval (gpio, val);
	lua_pushnumber(L, res);         
	return 1;                   /* number of results */
}

static const struct luaL_reg 
mylib [] = {
	{"gpionarf", l_gpionarf},
	{NULL, NULL}  /* sentinel */
};

int luaopen_gpionarf (lua_State *L) 
{
	luaL_openlib(L, "gpionarf", mylib, 0);
	return 1;
}
