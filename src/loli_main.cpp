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

#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"
#include "loli_prim.h"
#include "loli_list.h"
#include "loli_ast.h"

int main(int argc, char * argv[]){
	std::cout<<nil->value<<std::endl;
	std::cout<<t->value<<std::endl;
//	std::cout<<mkflt(1.2356).value<<std::endl;
//	loliObj* c = cons(t, nil);
//	loliObj* b = cons(t, c);
//	std::cout<<tail(tail(b))->value<<std::endl;
	std::cout<<"CREATING TEST:"<<std::endl;
	loliObj* test = cons(mksym("a"), cons(mkint(3), cons(mkint(0), nil)));
//	std::cout<<"TEST HEAD: "<<head(test).value<<std::endl;
//	std::cout<<"SUM (1 2 3): "<<proc_sum(test)->value<<std::endl;
	std::cout<<"SUB (\"a\" 3 0): "<<proc_sub(test)->value<<std::endl;
//	std::cout<<"MUL (1 2 3): "<<proc_mul(test)->value<<std::endl;
	std::cout<<"DIV (\"a\" 3 0): "<<proc_div(test)->value<<std::endl;
	std::cout<<"MOD (\"a\" 3 0): "<<proc_mod(test)->value<<std::endl;
	std::cout<<"Length of (\"a\" 3 0) is: "<<prim_length(test)<<std::endl;
	loliObj* testSUM = mkproc(proc_sum);
	//cleanUp();
	//delete test;
	exit(0);
}
