/*
 * =====================================================================================
 *
 *       Filename:  loli_let.cpp
 *
 *    Description:  Let of LoLi
 *
 *        Version:  1.0
 *        Created:  06/16/2014 09:04:51 PM
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

loliObj* prim_let(loliObj* exp, loliObj* env){
	/*
	 * (let ((SYM VAL)
	 * 	 (SYM VAL)
	 * 	 ...)
	 * 	 (EXP))
	 */
	exp = tail(exp);
//	std::cout<<toString(exp)<<std::endl;
	loliObj* tmpenv = env;
	auto tmpdef = head(exp);
	auto tmpexp = head(tail(exp));
	for(;!nilp(tmpdef);tmpdef = tail(tmpdef)){
		tmpenv = cons(cons(head(head(tmpdef)), head(tail(head(tmpdef)))), tmpenv);
	}
	return eval(tmpexp, tmpenv);
}
