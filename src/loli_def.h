/*
 * =====================================================================================
 *
 *       Filename:  loli_def.h
 *
 *    Description:  Basic define function
 *
 *        Version:  1.0
 *        Created:  06/04/2014 02:09:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_DEF_
#define __LOLI_DEF_

#include "loli.h"

extern bool c_def(loliObj* exp, loliObj* env);
extern loliObj* prim_def(loliObj* exp);

#endif
