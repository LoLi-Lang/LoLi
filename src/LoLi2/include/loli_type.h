/*
 * =====================================================================================
 *
 *       Filename:  loli_type.h
 *
 *    Description:  Type of LoLi
 *
 *        Version:  1.0
 *        Created:  07/17/2014 01:45:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_TYPE_
#define __LOLI_TYPE_

#include "loli_obj.h"

extern loliObj* linteger;
extern loliObj* lfloat;
extern loliObj* lnumber;
extern loliObj* lsym;
extern loliObj* lcons;
extern loliObj* lproc;
extern loliObj* lstr;
extern loliObj* lchar;
extern loliObj* lobj;

extern bool isType(loliObj* sym, loliType type);

#endif
