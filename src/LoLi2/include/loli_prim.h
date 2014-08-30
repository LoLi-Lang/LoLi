/*
 * =====================================================================================
 *
 *       Filename:  loli_prim.cpp
 *
 *    Description:  Prim of LoLi
 *
 *        Version:  1.0
 *        Created:  08/17/2014 08:20:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_PRIM_
#define __LOLI_PRIM_

#include "loli_obj.h"

extern loliNum* c_plu(loliObj* obj);
extern loliNum* c_sub(loliObj* obj);
extern loliNum* c_mul(loliObj* obj);
extern loliNum* c_div(loliObj* obj);
extern loliObj* c_quote(loliObj* obj);

#endif
