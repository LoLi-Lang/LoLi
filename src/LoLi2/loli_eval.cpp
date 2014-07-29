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

loliObj* eval_list(loliObj* lst);

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
		case LAMBDA:
		case BOOL:
		case TYPE:
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
				switch(cond->type){
					case CONS:
						switch(head(cond)->type){
							case PROC:
								if(!head(cond)->PROC.rtype->equals(to_key("BOOL"))){
									loli_err("Error! Need a BOOL for if, but get a " + toString(head(cond)->PROC.rtype));
									return nil;
								}else{
									if(c_eval(cond)->equals(boolt)){
										return c_eval(wt);
									}else{
										if(!nilp(wf) || wf != NULL){
											return c_eval(wf);}
										else{
											return nil;
										}
									}
								}
							case LAMBDA:
								if(!head(cond)->LAMBDA.rtype->equals(to_key("BOOL"))){
									loli_err("Error! Need a BOOL for if, but get a " + toString(head(cond)->LAMBDA.rtype));
									return nil;
								}else{
									if(c_eval(cond)->equals(boolt)){
										return c_eval(wt);
									}else{
										if(!nilp(wf) || wf != NULL){
											return c_eval(wf);}
										else{
											return nil;
										}
									}
								}
							default:
								loli_err("Error! Need a BOOL for if, but get a " + toString(head(cond)->type));
								return nil;
						}
					case BOOL:
						if(cond->equals(boolt)){
							return c_eval(wt);
						}else{
							if(!nilp(wf) || wf != NULL){
								return c_eval(wf);}
							else{
								return nil;
							}
						}
					default:
						loli_err("Error! Need a BOOL for if, but get a " + toString(cond->type));
						return nil;
				}
			}
			return eval_list(exp);
	}
}

loliObj* eval_list(loliObj* lst){
	loliObj* car = head(lst);
	loliObj* cdr = tail(lst);
	loliObj* env = lst->env;
	return nil;
}
