/*
 * =====================================================================================
 *
 *       Filename:  loli_cbmi.cpp
 *
 *    Description:  The Context Based Meaning Inference
 *
 *        Version:  1.0
 *        Created:  04/27/2014 02:14:10 AM
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

loliObj* getType(loliType type, loliObj* sym, loliObj* env){
	loliObj* tmp = lookup(sym, env);
//	std::cout<<toString(sym)<<" @ "<<toString(env)<<std::endl;
	for(;!nilp(tmp);tmp = tail(tmp)){
//		std::cout<<toString(head(tmp))<<std::endl;
		if(tail(head(tmp))->type == type){
			return tail(head(tmp));
		}
	}
	return nil;
}

loliObj* get_cons(loliObj* sym, loliObj* env){
	return getType(CONS, head(sym), env);
}

loliObj* get_int(loliObj* sym, loliObj* env){
	return getType(INT, head(sym), env);
}

loliObj* get_flt(loliObj* sym, loliObj* env){
	return getType(FLT, head(sym), env);
}

loliObj* get_sym(loliObj* sym, loliObj* env){
	return getType(SYM, head(sym), env);
}

loliObj* get_proc(loliObj* sym, loliObj* env){
	return getType(PROC, head(sym), env);
}

loliObj* get_lambda(loliObj* sym, loliObj* env){
	return getType(LAMBDA, head(sym), env);
}
