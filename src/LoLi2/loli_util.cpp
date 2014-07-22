/*
 * =====================================================================================
 *
 *       Filename:  loli_util.cpp
 *
 *    Description:  Utilities of LoLi
 *
 *        Version:  1.0
 *        Created:  06/26/2014 06:46:23 PM
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
#include "include/loli_obj.h"

void loli_err(std::string err){
	std::cerr<<err<<std::endl;
}

std::string pairUp(std::string str){
	int p = 0;
	bool q = false;
	for(ulong j = 0; j < str.length(); j++){
		if(str[j] == '"'){
			q = !q;
		}
		if(str[j] == '('){
			if(!q)
				p = p + 1;
		}else if(str[j] == ')'){
			if(!q)
				p = p - 1;
		}
		if(p == 0 && !q){
			return str.substr(0, j + 1);
		}
	}
	return str;
}

bool is_spchar(char c){
//	std::cout<<c<<std::endl;
	return ( (c == '(') || \
		 (c == ')') || \
		 (c == '\'') || \
		 (c == '\"') || \
		 isspace(c) );
}
