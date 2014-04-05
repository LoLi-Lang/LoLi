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

#include "loli_types.h"

loliObj cons(loliObj hd, loliObj tl){	//HD stands for HEAD, TL stands for TAIL
	loliObj tmp;
	tmp.type = CONS;
	tmp.head = &hd;
	tmp.tail = &tl;
	return tmp;
}

loliObj head(loliObj cons){
	if(cons.type == CONS){
		return *cons.head;
	}
}

loliObj tail(loliObj cons){
	if(cons.type == CONS){
		return *cons.tail;
	}
}
