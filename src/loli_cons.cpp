/*
 * =====================================================================================
 *
 *       Filename:  loli_cons.cpp
 *
 *    Description:  Functions of operating cons
 *
 *        Version:  1.0
 *        Created:  04/05/2014 02:13:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

#include "header/loli.h"
#include "header/loli_gc.h"

loliObj* cons(loliObj* hd, loliObj* tl){	//HD stands for HEAD, TL stands for TAIL
	loliObj * tmp = new (UseGC) loliObj(CONS);
	tmp->head = hd;
	tmp->tail = tl;
	return tmp;
}

loliObj* prim_cons(loliObj* exp, loliObj* env){	//HD stands for HEAD, TL stands for TAIL
	loliObj * tmp = new (UseGC) loliObj(CONS);
	tmp->head = head(exp);
	tmp->tail = head(tail(exp));
	return tmp;
}

loliObj* head(loliObj* cons){
	if(cons->type == CONS){
		return cons->head;
	}else{
		return nil;
	}
}

loliObj* tail(loliObj* cons){
	if(cons->type == CONS){
		return cons->tail;
	}else{
		return nil;
	}
}

loliObj* prim_head(loliObj* cons, loliObj* env){
	if(cons->type != CONS){
		std::cout<<"Error! Need a CONS obj!"<<std::endl;
		return nil;
	}
	return head(head(cons));
}

loliObj* prim_tail(loliObj* cons, loliObj* env){
	if(cons->type != CONS){
		std::cout<<"Error! Need a CONS obj!"<<std::endl;
		return nil;
	}
	return tail(head(cons));
}
