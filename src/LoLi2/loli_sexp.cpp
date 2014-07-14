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
sexp* SNIL = new (UseGC) sexp("NIL");
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
		return parse_cons(str.substr(1, str.length() - 2));
	}
	//Return SNIL when get a blank input
	return SNIL;
}

sexp* parse_cons(std::string str){
	while(isspace(str[0])){
		str = str.substr(1);
	}
	if(str[0] == '\0'){
		return SNIL;
	}
	sexp* tmp = new (UseGC) sexp("CONS");
	//TODO:
	//Finish the parser
	return END;
}
