/*
 * =====================================================================================
 *
 *       Filename:  loli_cond.cpp
 *
 *    Description:  Cond of LoLi
 *
 *        Version:  1.0
 *        Created:  06/09/2014 05:44:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "header/loli.h"

loliObj* c_if(loliObj* exp, loliObj* a, loliObj* b, loliObj* env){
	if(!nilp(eval(exp, env))){
		return eval(a, env);
	}else{
		return eval(b, env);
	}
}

loliObj* c_if(loliObj* exp, loliObj* a, loliObj* env){
	if(!nilp(eval(exp, env))){
		return eval(a, env);
	}
}

loliObj* prim_if(loliObj* exp, loliObj* env){
	/* (if EXP
	 * 	A
	 * 	B)
	 * or
	 * (if EXP
	 * 	A) */
	exp = tail(exp);
	if(!nilp(tail(tail(exp)))){
		return c_if(head(exp), head(tail(exp)), head(tail(tail(exp))), env);
	}else{
		return c_if(head(exp), head(tail(exp)), env);
	}
}
