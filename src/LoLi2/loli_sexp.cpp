/*
 * =====================================================================================
 *
 *       Filename:  loli_sexp.cpp
 *
 *    Description:  S-Expression
 *
 *        Version:  1.0
 *        Created:  06/25/2014 01:20:49 PM
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

#include "include/loli_sexp.h"
#include "include/loli_obj.h"
#include "include/loli_util.h"
#include "../header/loli_gc.h"

sexp* END = new (UseGC) sexp("END");
sexp* SNIL = new (UseGC) sexp("SNIL");
//Parser String -> SEXP

sexp* parse_cons(std::string str);

sexp* to_sexp(std::string str){
	while(isspace(str[0])){
		str = str.substr(1);
	}
	if(str[0] == '\0'){
		return END;
	}
	if(!is_spchar(str[0])){
		for(ulong i = 0; i < str.length(); i++){
			if(is_spchar(str[i])){
				sexp* tmp = new (UseGC) sexp(str.substr(0, i));
				tmp->next = END;
				return tmp;
			}
		}
		sexp* tmp = new (UseGC) sexp(str);
		tmp->next = END;
		return tmp;
	}
	if(str[0] == '\''){
		sexp* tmp = new (UseGC) sexp("QUOTE");
		tmp->next = to_sexp(str.substr(1));
		return tmp;
	}
	if(str[0] == '\"'){
		sexp* tmp = new (UseGC) sexp("STR");
		for(ulong i = 1; i < str.length(); i++){
			if(str[i] == '\"'){
				tmp->next = new (UseGC) sexp(str.substr(1, i - 1));
				tmp->next->next = END;
				return tmp;
			}
		}
	}
	if(str[0] == '('){
		sexp* tmp = new (UseGC) sexp("CONS");
		tmp->next = parse_cons(str.substr(1, str.length() - 2));
		return tmp;
	}
	//Return SNIL when get a blank input
	return END;
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

sexp* parse_cons(std::string str){
	while(isspace(str[0])){
		str = str.substr(1);
	}
	std::cout<<"Parse CONS: " <<str<<std::endl;
	if(str[0] == '\0'){
		sexp* tmp;
		tmp = SNIL;
		tmp->next = END;
		return tmp;
	}
	//TODO:
	//Finish the parser
	for(ulong i = 0; i < str.length(); i++){
		if(isspace(str[i])){
			sexp* tmp;
			tmp = to_sexp(str.substr(0, i));
			tmp->next = parse_cons(str.substr(i + 1));
			return tmp;
		}
		if(str[i] == '('){
			sexp* tmp;
			std::string t = pairUp(str.substr(i));
			tmp = to_sexp(t);
			std::cout<<tmp->toString()<<std::endl;
			tmp->next = parse_cons(str.substr(i + t.length()));
			return tmp;
		}
	}
	//Default return
	if(to_sexp(str) == SNIL){
		return SNIL;
	}
	sexp* tmp;
	tmp = to_sexp(str);
	tmp->next = SNIL;
	tmp->next->next = END;
	return tmp;
}
