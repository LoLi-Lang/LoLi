/*
 * =====================================================================================
 *
 *       Filename:  loli_apply.cpp
 *
 *    Description:  Apply Of LoLi
 *
 *        Version:  1.0
 *        Created:  05/13/2014 06:34:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "header/loli.h"

#include <iostream>

loliObj* apply(loliObj* proc, loliObj* obj, loliObj* env){
//	std::cout<<"Proc: "<<toString(proc)<<std::endl<<"Arg: "<<toString(obj)<<std::endl;
	if(proc->type == PROC){
		obj->env = env;
		return proc->proc(obj, env);
	}
	if(proc->type == LAMBDA){
		loliObj* tmpe = env;
		for(loliObj* args = proc->env;!nilp(head(args));args = tail(args)){
			tmpe = cons(cons(head(args), head(obj)), tmpe);
//			std::cout<<"Args: "<<toString(head(args))<<" Val: "<<toString(head(obj))<<" Tmpe: "<<toString(tmpe)<<std::endl;
			obj = tail(obj);
		}
//		std::cout<<"Exp: "<<toString(proc->tail)<<std::endl;
		return eval(proc->tail, tmpe);
	}
	std::cout<<toString(proc)<<" Not a procedure!"<<std::endl;
	return nil;
}
