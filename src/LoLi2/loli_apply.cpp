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
#include "include/loli_typeclass.h"

#include <iostream>

loliObj* c_apply (loliObj* fn, loliObj* args, loliObj* env){
    std::cout<<fn->toString()<<"\t"<<fn->type->toString()<<std::endl;
	if(lproc(fn)->proc){
        std::cout<<"PROC:\t"<<&(lproc(fn)->proc)<<std::endl;
		return lproc(fn)->proc(args);
	}else if(llambda(fn)->exp){
        std::cout<<"LAMBDA"<<std::endl;
		loliObj* tmpe = env;
		for(loliObj* e = fn->env;!lcons(e)->head()->nilp() ; e = lcons(e)->tail()){
			tmpe = add_to_env(to_env_entry(lcons(e)->head(), lcons(args)->head()), tmpe);
			args = lcons(args)->tail();
		}
		return llambda(fn)->exp->eval(tmpe);
	}else{
		loli_err(fn->toString() + " is not appliable!");
		return nil;
	}
}
