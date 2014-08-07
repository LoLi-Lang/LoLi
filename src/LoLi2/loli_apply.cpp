/*
 * =====================================================================================
 *
 *       Filename:  loli_apply.cpp
 *
 *    Description:  Apply of LoLi
 *
 *        Version:  1.0
 *        Created:  08/06/2014 04:19:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_obj.h"
#include "include/loli_util.h"
#include "include/loli_eval.h"
#include "include/loli_env.h"

loliObj* c_apply (loliObj* fn, loliObj* args, loliObj* env){
	if(fn->type == PROC){
		return fn->PROC.proc(args);
	}else if(fn->type == LAMBDA){
		loliObj* tmpe = env;
		for(loliObj* e = fn->env; !nilp(head(e)); e = tail(e)){
			tmpe = add_to_env(to_env_entry(head(e), head(args)), tmpe);
			args = tail(args);
		}
		return c_eval(fn->LAMBDA.exp, tmpe);
	}else{
		loli_err(toString(fn) + " is not appliable!");
		return nil;
	}
}
