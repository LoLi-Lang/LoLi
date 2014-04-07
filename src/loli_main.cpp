/*
 * =====================================================================================
 *
 *       Filename:  loli_main.cpp
 *
 *    Description:  The main part (aka. the entrence of LoLi)
 *
 *        Version:  1.0
 *        Created:  04/05/2014 01:45:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"
#include "loli_prim.h"

int main(int argc, char * argv[]){
	std::cout<<nil->value<<std::endl;
	std::cout<<t->value<<std::endl;
//	std::cout<<mkflt(1.2356).value<<std::endl;
	auto c = cons(t, nil);
	auto b = cons(t, c);
	std::cout<<tail(tail(b))->value<<std::endl;
	loliObj* test = cons(mkint(1), cons(mkint(2), cons(mkint(3), nil)));
//	std::cout<<"TEST HEAD: "<<head(test).value<<std::endl;
	std::cout<<"SUM (1 2 3): "<<proc_sum(test)->value<<std::endl;
	std::cout<<"SUB (1 2 3): "<<proc_sub(test)->value<<std::endl;
	std::cout<<"MUL (1 2 3): "<<proc_mul(test)->value<<std::endl;
	std::cout<<"DIV (1 2 3): "<<proc_div(test)->value<<std::endl;
}
