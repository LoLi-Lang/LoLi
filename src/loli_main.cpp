/*
 * =====================================================================================
 *
 *       Filename:  loli_main.cpp
 *
 *    Description:  The main part (aka. the entrance of LoLi)
 *
 *        Version:  1.0
 *        Created:  04/05/2014 01:45:34 AM
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

#include "loli.h"

void loli_init_tl(){
	top_env = addToEnv(top_env, cons(mksym("a"), mkint(10)));
	top_env = addToEnv(top_env, cons(t, t));
	top_env = addToEnv(top_env, cons(nil, nil));
	top_env = addToEnv(top_env, cons(mksym("top_env"), top_env));

	std::cout<<toString(top_env)<<std::endl;
}

int main(int argc, char * argv[]){
	std::cout<<"LoLi PRPR!\nLoLi is a Free Software and you can do whatever you want with it under the licence GPLv3"<<std::endl;
	loli_init_tl();
	while(true){
		repl(top_env);
	}
	exit(0);
}
