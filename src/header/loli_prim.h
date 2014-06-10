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
extern loliObj* proc_sum(loliObj* lst, loliObj* env);
extern loliObj* proc_mul(loliObj* lst, loliObj* env);
extern loliObj* proc_sub(loliObj* lst, loliObj* env);
extern loliObj* proc_div(loliObj* lst, loliObj* env);

//NUM -> NUM
extern loliObj* proc_add1(loliObj* num, loliObj* env);
extern loliObj* proc_sub1(loliObj* num, loliObj* env);

//[NUM] -> NUM
extern loliObj* proc_mod(loliObj* lst, loliObj* env);

//[NUM] -> SYM
extern loliObj* proc_greater(loliObj* lst, loliObj* env);
extern loliObj* proc_lesser(loliObj* lst, loliObj* env);

extern loliObj* proc_exit(loliObj* dum, loliObj* env);

extern loliObj* proc_atom(loliObj* obj, loliObj* env);

#endif
