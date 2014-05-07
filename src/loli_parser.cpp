/*
 * =====================================================================================
 *
 *       Filename:  loli_parser.cpp
 *
 *    Description:  Parser of LoLi
 *
 *        Version:  1.0
 *        Created:  04/14/2014 01:33:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>

#include "loli.h"
#include <iostream>

loliObj* parse(std::string exp){
	const char* s = exp.c_str();
	while(*s){
		std::cout<<s<<std::endl;
		s++;
	}

	return nil;
}
