/*
 * =====================================================================================
 *
 *       Filename:  loli_eval.cpp
 *
 *    Description:  Evaluation part of LoLi
 *
 *        Version:  1.0
 *        Created:  04/11/2014 03:00:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include "loli_types.h"
#include "loli_cons.h"
#include "loli_symbols.h"
#include "loli_cbmi.h"
#include "loli_env.h"
#include "loli_apply.h"

loliObj* lookupList(loliObj* lst, loliObj*);

loliObj* eval(loliObj* obj, loliObj* env){
	if(nilp(obj)){
		return nil;
	}else{
		switch(obj->type){
			case INT:
			case FLT:
				return obj;
			case CONS:
				if(equals(head(obj), quote)){
					return tail(obj);
				}else if(equals(head(obj), lambda)){
					return mklambda(obj);
				}else if(head(obj)->type == LAMBDA){
					return apply(head(obj), lookupList(tail(obj), env), env);
				}else if(head(obj)->type == CONS){
					return eval(cons(eval(head(obj), env), tail(obj)), env);
				}
				return apply(getType(PROC, head(obj), env), lookupList(tail(obj), env), env);
			case SYM:
				if(nilp(lookup(obj, env))){
					return mksym("Symbol Unbound!");
				}else{
					return tail(head(lookup(obj, env)));
				}
			case CHAR:
			case STRING:
			case PROC:
			case LAMBDA:
				return obj;
			default:
				return nil;
		}
	}
}

loliObj* lookupList(loliObj* lst, loliObj* env){
	if(nilp(lst)){
		return nil;
	}else{
		if(head(lst)->type != SYM){
			return cons(eval(head(lst), env), lookupList(tail(lst), env));
		}else{
			return cons(eval(tail(head(lookup(head(lst), env))), env), lookupList(tail(lst), env));
		}
	}
	return nil;
}
