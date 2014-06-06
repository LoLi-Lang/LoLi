/*
 * =====================================================================================
 *
 *       Filename:  loli_env.cpp
 *
 *    Description:  Environment of LoLi
 *
 *        Version:  1.0
 *        Created:  04/11/2014 03:04:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

#include "header/loli.h"

//loliObj* top_env = cons(cons(cons(nil , nil), cons(cons(t , t), nil)));
//loliObj* top_env = nil;

loliObj* mkEnvProc(loliObj* sym, loliObj* type, loliObj* proc){
	loliObj* tmp = cons(sym, cons(type, proc));
	return tmp;
}

loliObj* addToEnv(loliObj* env, loliObj* obj){
//	std::cout<<"ENV: "<<toString(env)<<" OBJ: "<<toString(obj)<<std::endl;
	if(nilp(env)){
		return cons(obj, nil);
	}
	if(head(head(env))->value < head(obj)->value){
		return cons(head(env), addToEnv(tail(env), obj));
	}else{
		return cons(obj, env);
	}
}

loliObj* lookup(loliObj* sym, loliObj* env){
//	std::cout<<"ENV: "<<toString(env)<<" OBJ: "<<toString(sym)<<std::endl;
	if(nilp(env)){
		return nil;
	}else{
		if(head(head(env))->value == sym->value){
			return cons(head(env), lookup(sym, tail(env)));
		}else{
			return lookup(sym, tail(env));
		}
	}
	return nil;
}
