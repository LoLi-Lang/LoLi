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

#include "header/loli.h"

loliObj* lookupList(loliObj* lst, loliObj* env);

loliObj* eval(loliObj* obj, loliObj* env){
//	std::cout<<nodeToString(toTree(obj))<<std::endl;
	std::cout<<"EVAL: "<<toString(obj)<<std::endl;
//	for(loliObj* tmp = obj; !nilp(tmp); tmp = tail(tmp)){
//		if(tmp->type!=CONS){
//			push(tmp);
//		}else{
//			push(head(tmp));
//		}
//	}
//	reverseStack();
//	printStack();
	if(nilp(obj)){
		return nil;
	}else{
		//obj->env = env;
		switch(obj->type){
			case INT:
			case FLT:
				return obj;
			case CONS:
				if(equals(head(obj), quote)){
					return obj;
				}else if(equals(head(obj), lambda)){
					return mklambda(obj);
				}else if(equals(head(obj), set)){
					return prim_set(obj, env);
				}else if(head(obj)->type == LAMBDA){
					return apply(head(obj), lookupList(tail(obj), env), env);
				}else if(head(obj)->type == CONS){
					return eval(cons(eval(head(obj), env), tail(obj)), env);
				}else if(equals(head(obj), ldef)){
					if(nilp(getType(head(tail(obj))->type, head(obj), env))){
						*env = *addToEnv(env, cons(head(tail(obj)), eval(head(tail(tail(obj))), env))); 
						return head(tail(obj));
					}else{
						return mksym("Variable already exist!");
					}
				}else if(equals(head(obj), lif)){
					return prim_if(obj, env);
				}else if(equals(head(obj), llet)){
					return prim_let(obj, env);
				}
				if(!nilp(getType(PROC, head(obj), env))){
					return apply(getType(PROC, head(obj), env), lookupList(tail(obj), env), env);
				}else{
					return apply(getType(LAMBDA, head(obj), env), lookupList(tail(obj), env), env);
				}
			case SYM:
				if(nilp(lookup(obj, env))){
					return mksym("Symbol Unbound!");
				}else{
			//		return eval(tail(head(lookup(obj, env))), env);
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
//		if(head(lst)->type != SYM){
			return cons(eval(head(lst), env), lookupList(tail(lst), env));
//		}else{
//			return cons(eval(tail(head(lookup(head(lst), env))), env), lookupList(tail(lst), env));
//		}
	}
	return nil;
}
