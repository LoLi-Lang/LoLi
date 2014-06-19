/*
 * =====================================================================================
 *
 *       Filename:  stack_test.cpp
 *
 *    Description:  Test of LoLi stack
 *
 *        Version:  1.0
 *        Created:  06/19/2014 11:33:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "header/loli.h"
#include "header/loli_stack.h"

#include <iostream>

int main(){
	std::cout<<"Begin"<<std::endl;
	push(nil);
	push(t);
	push(cons(mksym("test"), mksym("233")));
	std::cout<<"Done push"<<std::endl;
	printStack();
	std::cout<<toString(pop())<<std::endl;
	std::cout<<toString(pop())<<std::endl;
	std::cout<<toString(pop())<<std::endl;
}
