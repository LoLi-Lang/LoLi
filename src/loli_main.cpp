/*
 * =====================================================================================
 *
 *       Filename:  loli_main.cpp
 *
 *    Description:  The main part (aka. the entence of LoLi)
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

loliObj* proc_sum(loliObj* lst){
	double tmp = 0;
	for(loliObj* e = lst;!nilp(e);e = tail(e)){
		if(head(e)->type == INT){
			std::cout<<"SUM HEAD: "<<std::stoi(head(e)->value)<<std::endl;
			tmp = tmp + std::stoi(head(e)->value);
			std::cout<<"TMP: "<<tmp<<std::endl;
		}else if(head(e)->type == FLT){
			std::cout<<"SUM HEAD: "<<std::stod(head(e)->value)<<std::endl;
			tmp = tmp + std::stod(head(e)->value);
			std::cout<<"TMP: "<<tmp<<std::endl;
		}
	}
	std::cout<<"TMP: "<<tmp<<std::endl;
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

int main(int argc, char * argv[]){
	std::cout<<nil->value<<std::endl;
	std::cout<<t->value<<std::endl;
//	std::cout<<mkflt(1.2356).value<<std::endl;
	auto c = cons(t, nil);
	auto b = cons(t, c);
	std::cout<<tail(tail(b))->value<<std::endl;
	loliObj* test = cons(mkint(1), cons(mkint(2), cons(mkint(3), nil)));
//	std::cout<<"TEST HEAD: "<<head(test).value<<std::endl;
	std::cout<<proc_sum(test)->value<<std::endl;
}
