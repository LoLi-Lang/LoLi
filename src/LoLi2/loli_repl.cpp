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
#include "include/loli_util.h"
#include "include/loli_parser.h"

#include <iostream>

void c_repl(loliObj* env){
	while(true){
		std::cout<<"LoLi > ";
		std::string input = read_pair();
		try{
			//EVAL
			loliObj* exp = parse_string(input, env);
			std::cout<<toString(c_eval(exp))<<std::endl;
		}catch(...){
			loli_err("Error while evaluating: \n" + input);
			break;
		}
	}
}

void c_repl(){
	c_repl(top_env);
}
