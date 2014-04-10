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

//GC
#include "gc/include/gc.h"
#include "gc/include/gc_cpp.h"
#include "gc/include/gc_allocator.h"

#include "loli_types.h"
#include "loli_symbols.h"

loliObj* cons(loliObj* hd, loliObj* tl){	//HD stands for HEAD, TL stands for TAIL
	loliObj * tmp = new (UseGC) loliObj(CONS);
	tmp->head = hd;
	tmp->tail = tl;
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
