/*
 * =====================================================================================
 *
 *       Filename:  loli_lambda.cpp
 *
 *    Description:  Lambda of LoLi
 *
 *        Version:  1.0
 *        Created:  06/02/2014 09:20:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

#include "loli.h"
#include "loli_gc.h"

loliObj* mklambda(loliObj* exp){
	exp = tail(exp);
	loliObj *tmp = new (UseGC) loliObj(LAMBDA);
	tmp->type = LAMBDA;
	tmp->env = head(exp);
//	tmp->head = head(tail(exp)); //using head as the Type def
	tmp->tail = head(tail(exp)); //using tail as the Expression
	return tmp;
}
