/*
 * =====================================================================================
 *
 *       Filename:  loli_main.cpp
 *
 *    Description:  The entrance of LoLi
 *
 *        Version:  1.0
 *        Created:  07/11/2014 05:19:25 PM
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
#include <cstring>

#include "include/loli_repl.h"
#include "include/loli_obj.h"
#include "include/loli_env.h"
#include "include/loli_prim.h"

#define VERSION "Dev alpha 1"

void showHelp();

loliObj* initTopEnv();

int main(int argc, char** argv){
	if(argc >= 2){
		if(strcmp(argv[1], "--eval") == 0){
			//Eval from command line
			std::cout<<"EVAL"<<std::endl;
			return 0;
		}else if(strcmp(argv[1], "--help") == 0){
			showHelp();
			return 0;
		}else if(strcmp(argv[1], "--version") == 0){
			//Version
			std::cout<<"LoLi Interpreter: version "<<VERSION<<std::endl;
			return 0;
		}else if(strcmp(argv[1], "--file") == 0){
			//File
			std::cout<<"FILE"<<std::endl;
			return 0;
		}else if(strcmp(argv[1], "--repl") == 0){
			//REPL
			loliObj* env = initTopEnv();
			c_repl();
		}
	}else{
		std::cout<<"Please add an option"<<std::endl;
		showHelp();
		return 1;
	}
}

void showHelp(){
	std::cout<<"LoLi is a free software, you can do whatever you want with it under the GPLv3 or any higher version."<<std::endl<< \
		"Usage: loli [option] [filename]\n \
		\t--eval\tEvaluate an expression\n \
		\t--file\tEvaluate a file\n \
		\t--repl\tEnter the repl\n \
		\t--help\tShow help\n \
		\t--version\tDisplay the current version\n" \
		<<std::endl;
}

loliObj* initTopEnv(){
	loliObj* tmp = top_env;
	
	return tmp;
}
