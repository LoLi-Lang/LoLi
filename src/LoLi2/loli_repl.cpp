/*
 * =====================================================================================
 *
 *       Filename:  loli_repl.cpp
 *
 *    Description:  REPL of LoLi
 *
 *        Version:  1.0
 *        Created:  08/08/2014 10:28:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_obj.h"
#include "include/loli_env.h"
#include "include/loli_eval.h"
#include "include/loli_reader.h"

#include <iostream>

void c_repl(loliObj* env){
	std::cout<<"LoLi > ";
	std::string tmp = read_pair();
	std::cout<<tmp<<std::endl;
}

void c_repl(){
	c_repl(top_env);
}
