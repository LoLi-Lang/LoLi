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
#include "../header/loli_gc.h"

#include <string>

loliObj* parse_list(std::string str);

loliObj* parse_string(std::string str){
	while(isspace(str[0])){
		str = str.substr(1);
	}
	if(str[0] == '\0'){
		return nil;
	}
	if(str[0] == '\''){
		return c_cons(quote, c_cons(parse_string(str.substr(1)), nil));
	}
	if(str[0] == '\"'){
		for(ulong i = 1; i < str.length(); i++){
			if(str[i] == '\"'){
				return to_lstring(str.substr(1, i - 1));
			}
		}
		return to_lstring(str.substr(1, str.length() - 2));
	}
	if(str[0] == '('){
		return parse_list(str.substr(1, str.length() - 2));
	}
	try{
		if(stol(str) == stold(str)){
			return to_int(stol(str));
		}else{
			return to_flt(stold(str));
		}
	}catch(...){

	}
	for(ulong i = 0; i < str.length(); i++){
		if(isspace(str[i])){
			return to_sym(str.substr(0, i));
		}
	}
	//Default return is a symbol
	return to_sym(str);
}

loliObj* parse_list(std::string str){
	while(isspace(str[0])){
		str = str.substr(1);
	}
	if(str[0] == '\0'){
		return nil;
	}
	for(ulong i = 0; i < str.length(); i++){
		if(isspace(str[i])){
			return c_cons(parse_string(str.substr(0, i)), parse_list(str.substr(i + 1)));
		}
		if(str[i] == '('){
			std::string tmp = pairUp(str.substr(i));
			return c_cons(parse_string(tmp), parse_list(str.substr(i + tmp.length())));
		}
	}
	if(nilp(parse_string(str))){
		return nil;
	}
	return c_cons(parse_string(str), nil);
}
