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

#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"

int main(int argc, char * argv[]){
	std::cout<<nil.value<<std::endl;
	std::cout<<t.value<<std::endl;
	std::cout<<mkflt(1.2356).value<<std::endl;
	auto c = cons(t, nil);
	auto b = cons(t, c);
	std::cout<<tail(tail(b)).value<<std::endl;
}
