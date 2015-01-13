/*
 * =====================================================================================
 *
 *       Filename:  loli_set.cpp
 *
 *    Description:  Set of LoLi
 *
 *        Version:  1.0
 *        Created:  06/09/2014 10:37:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "header/loli.h"

#include <iostream>

loliObj* prim_set(loliObj* exp, loliObj* env){ //(set! obj val)
	exp = tail(exp);
	if(nilp(getType(head(tail(exp))->type, head(exp), env))){
		return mksym("Symbol not defined!");
	}else{
		*getType(head(tail(exp))->type, head(exp), env) = *eval(head(tail(exp)), env);
		return exp;
	}
}
