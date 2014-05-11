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
//	for(int i = 0; i < exp.length(); i++){
//		std::cout<<exp[i]<<std::endl;
//		
//		
//	}
	if(exp[0] == '('){
		//CONS
	}else if(exp[0] == '\''){
		//Q-EXP
	}else{
		for(int i = 0; i < exp.length(); i++){
			if(isspace(exp[i])){
				std::cout<<exp.substr(0, i)<<std::endl;
				return mksym(exp.substr(0, i));
			}
		}
		return mksym(exp);
	}

	return nil;
}
