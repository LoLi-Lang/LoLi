/*
 * =====================================================================================
 *
 *       Filename:  loli_prim.h
 *
 *    Description:  The primitive functions of LoLi
 *
 *        Version:  1.0
 *        Created:  04/07/2014 12:35:05 AM
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

#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"

extern loliObj* proc_sum(loliObj* lst);
extern loliObj* proc_mul(loliObj* lst);
extern loliObj* proc_sub(loliObj* lst);
extern loliObj* proc_div(loliObj* lst);

#endif
