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


#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"
#include "loli_ast.h"

loliObj* top_env = cons(cons(nil, nil), nil);

loliObj* mkEnvProc(loliObj* sym, loliObj* type, loliObj* proc){
	loliObj* tmp = cons(sym, cons(type, proc));
	return tmp;
}

loliObj* addToEnv(loliObj* env, loliObj* obj){
	if(head(head(env))->value < head(obj)->value){
		return cons(head(env), addToEnv(tail(env), obj));
	}else{
		return cons(obj, env);
	}
}

loliObj* lookup(loliObj* sym, loliObj* env){
	if(nilp(env)){
		return nil;
	}else{
		if(head(head(env))->value == sym->value){
			return cons(head(env), lookup(sym, tail(env)));
		}else if(head(head(env))->value > sym->value){
			return nil;
		}
	}
}
