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
#include "../header/loli_gc.h"

sexp* END = new sexp("");

loliObj* judge(std::string str){
	//Determine a str
	if(str == ""){
		return nil;
	}
	if(str[0] == '('){
		bool q = false;
		for(ulong i = 0; i < str.length(); i++){
			if(str[i] == '"'){
				q = !q;
			}
			if(isspace(str[i]) && !q){
				return c_cons(judge(str.substr(1, i)), judge("(" + str.substr(i)));
			}
			if(str[i] == ')' && !q){
				return judge(str.substr(1, i-1));
			}
		}
	}
	if(str[0] == '"'){
		return to_string(str.substr(1, str.length() - 1));
	}
	if(str[0] == '\''){
		return c_cons(quote, c_cons(to_sym(str), nil));
	}
	try{
		if(stol(str) == stold(str)){
			return to_int(stol(str));
		}else{
			return to_flt(stold(str));
		}
	}catch(...){

	}
	return to_sym(str);
}

sexp* to_sexp(std::string str){
	//From a paired string to S-Exp
	sexp* tmp = new (UseGC) sexp();
	while(isspace(str[0])){
		str = str.substr(1);
	}
	if(str[0] == '\0'){
		return END;
	}

	if(str[0] != '(' && str[0] != '"'){
		for(ulong i = 0; i < str.length(); i++){
			if(isspace(str[i])){
				tmp->value = judge(str.substr(0, i));
				tmp->next = END;
				return tmp;
			}
		}
		tmp->value = judge(str);
		tmp->next = END;
		return tmp;
	}

	if(str[0] == '"'){
		for(ulong i = 1; i < str.length(); i++){
			if(str[i] == '"'){
				tmp->value = judge(str.substr(0, i));
				tmp->next = END;
				return tmp;
			}
		}
		tmp->value = judge(str);
		tmp->next = END;
		return tmp;
	}

	if(str[0] == '('){
		bool q = false;
		for(ulong i = 0; i < str.length(); i++){
			if(str[i] == '"'){
				q = !q;
			}
			if(str[i] == ')' && !q){
				tmp->value = judge(str.substr(0, i));
				if(i != str.length()){
					tmp->next = to_sexp("(" + str.substr(i));
				}else{
					tmp->next = END;
				}
				return tmp;
			}
		}
	}
	return NULL;
}
