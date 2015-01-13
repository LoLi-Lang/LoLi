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

loliObj* applyList(loliObj* lst, loliObj* env, loliType ot){
	//Apply from a symbol list (unevaled list)
	if(nilp(get_lambda(head(lst))) || nilp(get_proc(head(lst)))){
		std::cout<<"Error: the first element of list is not a Procedure!"<<std::endl;
		return nil;
	}
	if(equals(head(lst), quote)){
		return lst;
	}
	auto procLst = cons(get_lambda(head(lst)), cons(get_proc(head(lst)), nil));
	loliObj* proc;
	if(ot != _){
		if((head(procLst)->outType == ot) && (head(tail(procLst))->outType == ot) && \
				(head(procLst)->inType == head(tail(procLst))->inType)){
			std::cout<<"Error: type conflict! More than one procedure exist!"<<std::endl;
			return nil;
		}
		if((head(procLst)->outType != ot) && (head(tail(procLst))->outType != ot)){
			std::cout<<"Error: no procedure matches the type requirement!"<<std::endl;
			return nil;
		}
		head(procLst)->outType == ot ? proc = head(procLst) : proc = head(tail(procLst));
	}
	bool tt = true;
	!nilp(head(procLst)) ? proc = head(procLst) : proc = head(tail(procLst));
	for(auto arg = tail(lst); tail(arg)->type == CONS; arg = tail(arg)){
		if(head(arg)->type != CONS){
			tt = tt && head(arg)->type == proc->inType;
		}else{
			tt = tt && !nilp(arg, env, tt->inType);
		}
	}
	if(!tt){
		std::cout<<"Error: some arguments don't match the requirement of the procedure!"<<std::endl;
		std::cout<<"Detail: "<<proc->inType<<" needed, but not all of argmuments match"<<std::endl;
		return nil;
	}

}
