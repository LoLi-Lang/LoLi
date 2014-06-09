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
#include <iostream>

#include "header/loli.h"

loliObj* parseList(std::string exp);

loliObj* parse(std::string exp){
	while(isspace(exp[0])){
		exp = exp.substr(1);
	}
	if(exp[0] == '\0'){
		return nil;
	}
	if(exp[0] == '('){
		//		std::cout<<exp.substr(1, exp.length() - 2)<<std::endl;
		return parseList(exp.substr(1, exp.length() - 2));
		//CONS
	}else if(exp[0] == '\''){
		//Q-EXP
		return cons(quote, cons(parse(exp.substr(1, exp.length() - 1)), nil));
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

std::string pairUp(std::string exp){
	int p = 0;
	bool q = false;
	for(ulong j = 0; j < exp.length(); j++){
		if(exp[j] == '"'){
			q = !q;
		}
		if(exp[j] == '('){
			if(!q)
				p = p + 1;
		}else if(exp[j] == ')'){
			if(!q)
				p = p - 1;
		}
		if(p == 0 && !q){
			return exp.substr(0, j + 1);
		}
	}
	return exp;
}

loliObj* parseList(std::string exp){
	//	std::cout<<exp<<std::endl;
	while(isspace(exp[0])){
		exp = exp.substr(1);
	}
	if(exp[0] == EOF){
		return nil;
	}
	for(ulong i = 0; i < exp.length(); i++){
		if(isspace(exp[i])){
			return cons(parse(exp.substr(0, i)), parseList(exp.substr(i+1)));
		}
		if(exp[i] == '('){
			std::string tmp = pairUp(exp.substr(i));
			return cons(parse(tmp), parseList(exp.substr(i + tmp.length())));
		}
	}
	return cons(parse(exp), nil);
}
