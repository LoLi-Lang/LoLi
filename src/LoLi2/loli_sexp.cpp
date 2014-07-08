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

sexp* END = new sexp("END");
sexp* QUOTE = new sexp("QUOTE");
sexp* EOC = new sexp("EOC");

loliObj* judge(std::string str){
//	std::cout<<"\n\tJudge: " << str<< std::endl;
	while(isspace(str[0])){
		str = str.substr(1);
	}
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
				//return c_cons(judge(str.substr(1, i)), judge("(" + str.substr(i)));
				return c_cons(judge(str.substr(1, i)), c_cons(judge(str.substr(i)), nil));
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
	while(isspace(str[0])){
		str = str.substr(1);
	}
//	std::cout<<"\n\tTo SExp: "<<str<<std::endl;
	if(str[0] == '\0'){
		return END;
	}
	if(str[0] == '('){
		str = str.substr(1);
		while(isspace(str[0])){
			str = str.substr(1);
		}
		str = "(" + str;
		if(str[1] == ')' || str[1] == '\0'){
			std::cout<<"NIL"<<std::endl;
			return END;
		}
//		std::cout<<"\n\tCons: "<<str<<std::endl;
		sexp* tmp;
		for(ulong i = 1; i < str.length(); i++){
//			std::cout<<"\t\t"<<str[i]<<std::endl;
			if(is_spchar(str[i])){
				std::string t = str.substr(1, i - 1);
				if(t[0] == '\0'){
					tmp = new (UseGC) sexp("NEXT");
				}else if(str[i] == ')'){
					tmp = new (UseGC) sexp(t);
					sexp* tt = new (UseGC) sexp("EOC");
					tt->next = to_sexp("(" + str.substr(i + 1));
					tmp->next = tt;	
					return tmp;
				}else{
					tmp = new (UseGC) sexp(t);
				}
				tmp->next = to_sexp("(" + str.substr(i + 1));
				return tmp;
			}
		}
	}else if(str[0] == '\''){
		sexp* tmp = new (UseGC) sexp("QUOTE");
		tmp->next = to_sexp(str.substr(1));
		return tmp;
	}else{
//		std::cout<<"Symbol or Number"<<std::endl;
		for(ulong i = 0; i < str.length(); i++){
			if(is_spchar(str[i])){
				return new (UseGC) sexp(str.substr(0, i));
			}
		}
		return new sexp(str);
	}
}
