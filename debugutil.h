#ifndef __DEBUGUTIL_H_
#define __DEBUGUTIL_H_
/*
 * =====================================================================================
 *
 *       Filename:  debugutil.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12.12.2009 01:48:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  johnättuxcodedotorg
 *
 * =====================================================================================
 */

#define DEBUG_IONARFLIB 1 //Do this in configure FIXME


#ifdef DEBUG_IONARFLIB
#include <stdio.h>
#define debugf(format, args...) do{fprintf(stderr, "%s:%d: " format "\n" , __FILE__,__LINE__ , ##args );}while(0)

/*uh... stack dump done poor*/ 
#define callerdetermine()   do{debugf("me addr: %p ! ",__builtin_return_address(0)); \
			     debugf("callers addr: %p ! ",__builtin_return_address(1)); \
			     debugf("callers² addr: %p ! ",__builtin_return_address(2));}while(0)
#else /*so if you don't want debug messages any longer*/
#define debugf(format, args...) do{;}while(0) 
#define callerdetermine() do{}while(0)

#endif  //DEBUG_IONARFLIB


#endif //__DEBUGUTIL_H_

