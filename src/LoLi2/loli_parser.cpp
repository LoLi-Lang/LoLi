/*
 * =====================================================================================
 *
 *       Filename:  loli_parser.cpp
 *
 *    Description:  Parser of LoLi
 *
 *        Version:  1.0
 *        Created:  07/04/2014 03:07:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_obj.h"
#include "include/loli_util.h"

#include <string>
#include <iostream>

loliObj* parse_list(std::string str, loliObj* env);

loliObj* parse_string(std::string str, loliObj* env){
	while(isspace(str[0])){
		str = str.substr(1);
	}
	if(str[0] == '\0'){
		return nil;
	}
	if(str[0] == '\''){
		loliCons* tmp = CONS(quote, CONS(parse_string(str.substr(1), env), nil));
		tmp->env = env;
		return tmp;
	}
	if(str[0] == '\"'){
		for(ulong i = 1; i < str.length(); i++){
			if(str[i] == '\"'){
				loliString* tmp = STRING(str.substr(1, i - 1));
				tmp->env = env;
				return tmp;
			}
		}
		loliString* tmp = STRING(str.substr(1, str.length() - 2));
		tmp->env = env;
		return tmp;
	}
	if(str[0] == ':'){
		for(ulong i = 1; i < str.length(); i++){
			if(is_spchar(str[i])){
				if(i != 1){
					loliKey* tmp = KEY(str.substr(1, i));
					tmp->env = env;
					return tmp;
				}else{
					loli_err("Empty Keyword!");
					return nil;
				}
			}
		}
		loliKey* tmp = KEY(str.substr(1));
		tmp->env = env;
		return tmp;
	}
	if(str[0] == '('){
		auto* tmp = parse_list(str.substr(1, str.length() - 2), env);
		tmp->env = env;
		return tmp;
	}
	try{
		if(stol(str) == stold(str)){
			loliInt* tmp = INT(stol(str));
			tmp->env = env;
			return tmp;
		}else{
			loliFlt* tmp = FLT(stold(str));
			tmp->env = env;
			return tmp;
		}
	}catch(...){

	}
	for(ulong i = 0; i < str.length(); i++){
		if(isspace(str[i])){
			return SYM(str.substr(0, i));
		}
	}
	//Default return is a symbol
	loliSym* tmp = SYM(str);
	tmp->env = env;
	return tmp;
}

loliObj* parse_list(std::string str, loliObj* env){
	while(isspace(str[0])){
		str = str.substr(1);
	}
	if(str[0] == '\0'){
		return nil;
	}
	for(ulong i = 0; i < str.length(); i++){
		if(isspace(str[i])){
			loliObj* tmp = CONS(parse_string(str.substr(0, i), env), parse_list(str.substr(i + 1), env));
			tmp->env = env;
			return tmp;
		}
		if(str[i] == '('){
			std::string tmp = pairUp(str.substr(i));
			loliObj* tm = CONS(parse_string(tmp, env), parse_list(str.substr(i + tmp.length()), env));
			tm->env = env;
			return tm;
		}
	}
	if(parse_string(str, env)->nilp()){
		return CONS(nil, nil);
	}
	loliObj* tmp = CONS(parse_string(str, env), nil);
	tmp->env = env;
	return tmp;
}
