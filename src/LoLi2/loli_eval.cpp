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
#include "include/loli_apply.h"

#include <iostream>

loliObj* eval_list(loliObj* lst);
loliObj* eval_list(loliObj* lst, loliObj* env);

loliObj* c_eval(loliObj* exp);

loliObj* c_eval(loliObj* exp, loliObj* env){
	if(nilp(exp)){
		return nil;
	}
	switch(exp->type){
		case INT:
		case FLT:
		case CHAR:
		case STR:
		case LAMBDA:
		case BOOL:
		case PROC:
		case KEY:
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
			if(head(exp)->equals(to_sym("if"))){
				loliObj* cond = head(tail(exp));
				if(nilp(tail(exp))){
					loli_err("Need at least one expression for if");
					return nil;
				}
				loliObj* wt = head(tail(tail(exp)));
				loliObj* wf = head(tail(tail(tail(exp))));
				if(c_eval(cond, env)->equals(boolt)){
					return c_eval(wt);
				}else if(c_eval(cond, env)->equals(boolf)){
					if(wf){
						return c_eval(wf);
					}else{
						return nil;
					}
				}else{
					loli_err("Condition error");
					return nil;
				}
			}
			return eval_list(exp, env);
	}
}

loliObj* c_eval(loliObj* exp){
	return c_eval(exp, exp->env);
}

loliObj* eval_list(loliObj* lst){
	return eval_list(lst, lst->env);
}

loliObj* eval_list(loliObj* lst, loliObj* env){
	loliObj* car = head(lst);
	loliObj* cdr = tail(lst);
	std::cout<<"HEAD: "<<toString(car)<<"\tTAIL: "<<toString(cdr)<<std::endl;
	try{
		return c_apply(get_type(PROC, car, env) ,cdr, env);
	}catch(...){
		loli_err("No matching function");
	}
	return nil;
}
