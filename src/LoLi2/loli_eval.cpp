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

loliObj* eval_list(loliObj* lst, loliObj* env);

loliObj* loliSym::eval(loliObj* env){
    std::cout<<typeOBJ->toString()<<std::endl;
	if(env->nilp() || env == NULL){
		loliObj* r = lookup_top_env(this);
		if(r->nilp()){
			loli_err("Symbol: " + this->toString() + " is unbound.");
			return nil;
		}else{
			return r;
		}
	}else{
		loliObj* r = lookup_env(this, env);
		if(r->nilp()){
			loli_err("Symbol: " + this->toString() + " is unbound in its environment.");
			return nil;
		}else{
			return r;
		}
	}
}

loliObj* loliCons::eval(loliObj* env){
    std::cout<<typeOBJ->toString()<<std::endl;
    if(this->head() == SYM("if")){
		loliObj* cond = lcons(this->tail())->head();
		if(this->tail()->nilp()){
			loli_err("Need at least one expression for if");
			return nil;
		}
		loliObj* wt = lcons(lcons(this->tail())->tail())->head();
		loliObj* wf = lcons(lcons(lcons(this->tail())->tail())->tail())->head();
		if(cond->eval(env)==boolt){
			return wt->eval(top_env);
		}else if(cond->eval(env)==boolf){
			if(wf){
				return wf->eval(top_env);
			}else{
				return nil;
			}
		}else{
			loli_err("Condition error");
			return nil;
		}
	}
	return eval_list(this, env);
}

loliObj* eval_list(loliObj* lst, loliObj* env){
	loliObj* car = lcons(lst)->head()->eval(env);
	loliObj* cdr = lcons(lst)->tail();
	std::cout<<"HEAD: "<<car->toString()<<"\tTAIL: "<<cdr->toString()<<std::endl;
    if(car->type->isFrom(typeFN)){
            return c_apply(car, cdr, env);
    }else{
            loli_err(car->toString() + " is not a function!");
    }
	return nil;
}
