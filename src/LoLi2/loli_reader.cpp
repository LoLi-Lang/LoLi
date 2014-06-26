/*
 * =====================================================================================
 *
 *       Filename:  loli_reader.cpp
 *
 *    Description:  Reader of LoLi
 *
 *        Version:  1.0
 *        Created:  06/26/2014 06:36:29 PM
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
#include <fstream>

#include "include/loli_obj.h"
#include "include/loli_util.h"

std::string read_pair(int i, bool quote){
	std::string tmp;
	std::getline(std::cin, tmp);
	int p = i;
	bool q = quote;
	for(ulong j = 0; j < tmp.length(); j++){
		if(tmp[j] == ';'){
			//Comment
			tmp = tmp.substr(0, j);
			break;
		}
		if(tmp[j] == '"'){
			//Quote
			q = !q;
		}
		if(tmp[j] == '('){
			if(!q){
				p = p + 1;
			}
		}else if(tmp[j] == ')'){
			if(!q){
				p = p - 1;
			}
		}
		if(p < 0){
			loli_err("Warning! Unpaired ) found!");
			tmp = tmp.substr(0, j);
			p = p + 1;
			break;
		}
	}
	if(p == 0 && !q){
		return tmp;
	}else{
		return tmp.append(read_pair(p, q));
	}
}

std::string read_pair(){
	return read_pair(0, false);
}

std::string read_pair(int i, bool quote, std::ifstream &stream){
	std::string tmp;
	std::getline(stream, tmp);
	int p = i;
	bool q = quote;
	for(ulong j = 0; j < tmp.length(); j++){
		if(tmp[j] == ';'){
			//Comment
			tmp = tmp.substr(0, j);
			break;
		}
		if(tmp[j] == '"'){
			//Quote
			q = !q;
		}
		if(tmp[j] == '('){
			if(!q){
				p = p + 1;
			}
		}else if(tmp[j] == ')'){
			if(!q){
				p = p - 1;
			}
		}
		if(p < 0){
			loli_err("Warning! Unpaired ) found!");
			tmp = tmp.substr(0, j);
			p = p + 1;
			break;
		}
	}
	if(p == 0 && !q){
		return tmp;
	}else{
		return tmp.append(read_pair(p, q, stream));
	}
}
