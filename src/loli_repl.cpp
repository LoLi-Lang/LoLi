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

#include "loli_eval.h"
#include "loli_output.h"
#include "loli_parser.h"
#include "loli_types.h"
#include "loli_env.h"
#include "loli_read.h"

void eval(loliObj* env){
	std::cout << "LoLi > ";
	std::string input;
	std::cin >> input;
	//Pseudo code:
	//cout << toString(eval(parse(input))) <<endl;
}
