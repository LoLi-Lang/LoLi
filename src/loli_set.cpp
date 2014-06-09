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
	if(nilp(getType(head(tail(exp))->type, head(exp), env))){
		auto tmp = addToEnv(env, cons(head(tail(exp)), eval(head(tail(tail(exp))), env))); 
		*env = *tmp;
		return head(tail(exp));
	}else{
		*getType(head(tail(exp))->type, head(exp), env) = *exp;
		return exp;
	}
}
