/*
 * =====================================================================================
 *
 *       Filename:  loli_spchar.cpp
 *
 *    Description:  Special Char of LoLi
 *
 *        Version:  1.0
 *        Created:  07/06/2014 04:38:57 PM
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

bool is_spchar(char c){
	std::cout<<c<<std::endl;
	return ( (c == '(') || \
		 (c == ')') || \
		 (c == '\'') || \
		 (c == '\"') || \
		 isspace(c) );
}
