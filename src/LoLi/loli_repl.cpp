/*
 * =====================================================================================
 *
 *       Filename:  loli_repl.cpp
 *
 *    Description:  The Read-Eval-Print Part
 *
 *        Version:  1.0
 *        Created:  04/20/2014 01:33:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <string>
#include <iostream>
#include <cstdio>

#include "header/loli.h"

void repl(loliObj* env){
	std::cout << "LoLi > ";
	std::string input;
	input = readPaired(0, false);
	if(input[0] == '\0'){
		return;
	}
	std::cout<<toString(eval(parse(input), env))<<std::endl;
//	printStack();
//	flushStack();
}
