/*
 * =====================================================================================
 *
 *       Filename:  loli_eval.cpp
 *
 *    Description:  Eval of LoLi
 *
 *        Version:  1.0
 *        Created:  07/18/2014 11:16:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_obj.h"
#include "include/loli_env.h"
#include "include/loli_util.h"

loliObj* eval_list(loliObj* list);

loliObj* c_eval(loliObj* exp){
	loliObj* env = exp->env;
	if(nilp(exp)){
		return nil;
	}
	switch(exp->type){
		case INT:
		case FLT:
		case CHAR:
		case STR:
		case _:
		case LAMBDA:
		case PROC:
			return exp;
		case SYM:
			if(nilp(env) || env == NULL){
				loliObj* r = lookup_top_env(exp);
				if(nilp(r)){
					loli_err("Symbol: " + toString(exp) + " is unbound.");
					return nil;
				}else{
					return r;
				}
			}else{
				loliObj* r = lookup_env(exp, env);
				if(nilp(r)){
					loli_err("Symbol: " + toString(exp) + " is unbound in its environment.");
					return nil;
				}else{
					return r;
				}
			}
		case CONS:
			return eval_list(exp);
	}
}

loliObj* eval_list(loliObj* lst){
	loliObj* car = head(lst);
	loliObj* cdr = tail(lst);
	loliObj* env = lst->env;
	return nil;
}
