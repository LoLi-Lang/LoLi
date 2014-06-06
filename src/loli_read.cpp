/*
 * =====================================================================================
 *
 *       Filename:  loli_read.cpp
 *
 *    Description:  Read and pair module of LoLi
 *
 *        Version:  1.0
 *        Created:  04/11/2014 02:43:34 AM
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
#include <fstream>

#include "header/loli.h"

std::string readPaired(int i, bool quote){ // i indicates the parentheses balance couting, quote indicated wheather between " or not
	std::string tmp;
	std::getline(std::cin, tmp);
	int p = i;
	bool q = quote;
	for(ulong j = 0; j < tmp.length(); j++){
		if(tmp[j] == '"'){
			q = !q;
		}
		if(tmp[j] == '('){
			if(!q)
				p = p + 1;
		}else if(tmp[j] == ')'){
			if(!q)
				p = p - 1;
		}
		if(p < 0){
			std::cout<<"Warning! Extra ) found that cannot pair up, ignored and returned"<<std::endl;
			tmp = tmp.substr(0, j);	//Temporary implementation, need to be modified after the error handling
			p = p + 1;
			break;
		}
	}
	if(p == 0 && !q){
		return tmp;
	}else{
		return tmp.append(readPaired(p, q));
	}
}

std::string readPaired(int i, bool quote, std::ifstream &stream){ // i indicates the parentheses balance couting, quote indicated wheather between " or not
	std::string tmp;
	std::getline(stream, tmp);
	int p = i;
	bool q = quote;
	for(ulong j = 0; j < tmp.length(); j++){
		if(tmp[j] == '"'){
			q = !q;
		}
		if(tmp[j] == '('){
			if(!q)
				p = p + 1;
		}else if(tmp[j] == ')'){
			if(!q)
				p = p - 1;
		}
		if(p < 0){
			std::cout<<"Warning! Extra ) found that cannot pair up, ignored and returned"<<std::endl;
			tmp = tmp.substr(0, j);	//Temporary implementation, need to be modified after the error handling
			p = p + 1;
			break;
		}
	}
	if(p == 0 && !q){
		return tmp;
	}else{
		return tmp.append(readPaired(p, q, stream));
	}
}
