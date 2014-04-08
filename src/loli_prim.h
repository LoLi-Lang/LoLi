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

//[NUM] -> NUM
extern loliObj* proc_sum(loliObj* lst);
extern loliObj* proc_mul(loliObj* lst);
extern loliObj* proc_sub(loliObj* lst);
extern loliObj* proc_div(loliObj* lst);

//NUM -> NUM
extern loliObj* proc_add1(loliObj* num);
extern loliObj* proc_sub1(loliObj* num);

//[NUM] -> NUM
extern loliObj* proc_mod(loliObj* lst);

//[NUM] -> SYM
extern loliObj* proc_greater(loliObj* lst);
extern loliObj* proc_lesser(loliObj* lst);

#endif
