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
	top_env = addToEnv(top_env, cons(mksym("a"), mkflt(10.0011011)));
	top_env = addToEnv(top_env, cons(t, t));
	top_env = addToEnv(top_env, cons(nil, nil));
	top_env = addToEnv(top_env, cons(quote, quote));
	top_env = addToEnv(top_env, cons(mksym("top_env"), top_env));

	//Creating Primitive Operators
	loliObj* loli_sum = mkproc(proc_sum);
	loliObj* loli_mul = mkproc(proc_mul);
	loliObj* loli_sub = mkproc(proc_sub);
	loliObj* loli_div = mkproc(proc_div);
	loliObj* loli_add1 = mkproc(proc_add1);
	loliObj* loli_sub1 = mkproc(proc_sub1);
	loliObj* loli_mod = mkproc(proc_mod);
	loliObj* loli_greater = mkproc(proc_greater);
	loliObj* loli_lesser = mkproc(proc_lesser);
	loliObj* loli_exit = mkproc(proc_exit);
	
	top_env = addToEnv(top_env, cons(mksym("+"), loli_sum));
	top_env = addToEnv(top_env, cons(mksym("*"), loli_mul));
	top_env = addToEnv(top_env, cons(mksym("-"), loli_sub));
	top_env = addToEnv(top_env, cons(mksym("/"), loli_div));
	top_env = addToEnv(top_env, cons(mksym("add1"), loli_add1));
	top_env = addToEnv(top_env, cons(mksym("sub1"), loli_sub1));
	top_env = addToEnv(top_env, cons(mksym("mod"), loli_mod));
	top_env = addToEnv(top_env, cons(mksym(">"), loli_greater));
	top_env = addToEnv(top_env, cons(mksym("<"), loli_lesser));
	top_env = addToEnv(top_env, cons(mksym("exit"), loli_exit));

	loliObj* test = cons(mkint(1), cons(mkflt(2.5), cons(mkint(5), nil)));

	std::cout<<toString(apply(loli_sum, test))<<"\t"<<toString(apply(loli_mul, test))<<"\n"<<toString(apply(loli_sub, test))<<"\t"<<toString(apply(loli_div, test))<<std::endl;

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
