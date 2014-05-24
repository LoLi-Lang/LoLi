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

loliObj* parseList(std::string exp);

loliObj* parse(std::string exp){
//	for(int i = 0; i < exp.length(); i++){
//		std::cout<<exp[i]<<std::endl;
//		
//		
//	}
	if(exp[0] == EOF){
		exit(0);
	}
	if(exp[0] == '('){
//		std::cout<<exp.substr(1, exp.length() - 2)<<std::endl;
		return parseList(exp.substr(1, exp.length() - 2));
		//CONS
	}else if(exp[0] == '\''){
		//Q-EXP
		return cons(quote, parse(exp.substr(1, exp.length() - 1)));
	}else{
		try{
			if(stoi(exp) == stod(exp))
			return mkint(stoi(exp));
		}catch(...){}

		try{
			return mkflt(stod(exp));
		}catch(...){}

		for(ulong i = 0; i < exp.length(); i++){
			if(isspace(exp[i])){
//				std::cout<<exp.substr(0, i)<<std::endl;
				return mksym(exp.substr(0, i));
			}
		}
		return mksym(exp);
	}

	return nil;
}

loliObj* parseList(std::string exp){
//	std::cout<<exp<<std::endl;
	if(exp[0] == EOF){
		return nil;
	}
	for(ulong i = 0; i < exp.length(); i++){
		if(isspace(exp[i])){
//			std::cout<<exp.substr(0, i)<<std::endl;
			return cons(parse(exp.substr(0, i)), parseList(exp.substr(i+1)));
		}
	}
	return cons(parse(exp), nil);
}
