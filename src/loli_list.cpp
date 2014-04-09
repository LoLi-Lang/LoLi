/*
 * =====================================================================================
 *
 *       Filename:  loli_list.cpp
 *
 *    Description:  The primitive list operations of LoLi
 *
 *        Version:  1.0
 *        Created:  04/08/2014 11:11:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

#include "loli_types.h"
#include "loli_cons.h"
#include "loli_symbols.h"

int prim_length(loliObj* lst){
	int tmp = 0;
	if(nilp(lst)){
		return 0;
	}else{
		return 1 + prim_length(tail(lst));
	}
}

//Append[(a (b . nil))] -> (a .... (b .... . nil))
loliObj* prim_append(loliObj* lst){
	if(nilp(head(lst))){
		return tail(lst);
	}
	if(head(lst)->type != CONS){
		std::cout<<"The first argument must be a CONS\n";
		return nil;
	}
	return cons(head(head(lst)), cons(tail(head(lst)), tail(lst)));
}
