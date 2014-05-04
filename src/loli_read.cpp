/*
 * =====================================================================================
 *
 *       Filename:  loli_read.cpp
 *
 *    Description:  Read and pair module of LoLi
 *
 *        Version:  1.0
 *        Created:  04/11/2014 02:43:34 AM
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

std::string readPaired(int i, bool quote){ // i indicates the parentheses balance couting, quote indicated wheather between " or not
	std::string tmp;
	std::getline(std::cin, tmp);
	int p = i;
	bool q = quote;
	const char* s = tmp.c_str();
	while(*s){
		if(*s == '"'){
			q = !q;
		}
		if(*s == '('){
			if(!q)
				p = p + 1;
		}else if(*s == ')'){
			if(!q)
				p = p - 1;
		}
		if(p < 0){
			std::cout<<"Error! Extra ) found that cannot pair up"<<std::endl;
			return "";	//Temporary implementation, need to be modified after the error handling
		}
		s++;
	}
	if(p == 0 && !q){
		return tmp;
	}else{
		return tmp.append(readPaired(p, q));
	}
}

//int main(){
//	std::cout<<readPaired(0, false)<<std::endl;
//}
