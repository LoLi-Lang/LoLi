/*
 * =====================================================================================
 *
 *       Filename:  loli_cbmi.cpp
 *
 *    Description:  Context Based Meaning Inference System
 *
 *        Version:  1.0
 *        Created:  07/21/2014 09:59:22 PM
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
#include "include/loli_type.h"
#include "include/loli_util.h"

loliObj* assign_value(loliObj* exp, loliObj* type);

loliObj* assign_value(loliObj* exp){
	//Assign value to S-Exp
	if(nilp(exp) || exp == NULL){
		return nil;
	}
	if(exp->type == SYM){
		if(exp->env == NULL || nilp(exp->env)){
			return lookup_top_env(exp);
		}else{
			return lookup_env(exp, exp->env);
		}
	}else if(is_int(exp) || is_flt(exp)){
		return exp;
	}else if(exp->type == CONS){
		loliObj* h = head(exp);
		if(h->type == SYM){
			loli_err(toString(h) + " is a symbol!");
			return nil;
		}
		loliObj* env = h->env;
		if(env == NULL || nilp(env)){
			env = top_env;
		}
		loliObj* v = get_type(LAMBDA, h, env);
		if(nilp(v)){
			v = get_type(PROC, h, env);
			if(nilp(v)){
				loli_err("No function bound to " + toString(head(h)));
				return nil;
			}
		}
	}
	return exp;
}

loliObj* assign_value(loliObj* exp, loliObj* type){
	if(nilp(exp)){
		return nil;
	}
	return exp;
}
