/*
 * =====================================================================================
 *
 *       Filename:  loli2test.cpp
 *
 *    Description:  Test of LoLi 2
 *
 *        Version:  1.0
 *        Created:  06/26/2014 02:20:22 PM
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
#include "include/loli_util.h"
#include "include/loli_stack.h"
#include "include/loli_reader.h"
#include "include/loli_parser.h"
#include "include/loli_eval.h"
#include "include/loli_env.h"

using namespace std;

int main(){
	global_stack.push_obj(to_int(10000));
	global_stack.push_obj(to_flt(123.456));
	global_stack.push_obj(to_sym("test"));
	global_stack.push_obj(c_cons(t, nil));
	do{
		cout<<toString(global_stack.pop_obj())<<endl;
	}while(!global_stack.isEmpty());
	loliObj* test = c_cons(to_sym("a"), c_cons(to_sym("b"), c_cons(to_sym("c"), c_cons(to_sym("d"), nil))));
	cout<<"Length of "<< toString(test)<<": "<< length(test)<<endl;
	while(true){
		cout<<"Get Input: ";
		string tmp = read_pair();
		cout<<"Input: "<<tmp<<endl;
		loliObj* i = parse_string(tmp, top_env);
		cout<<toString(i)<<endl;
		cout<<"Test Eval: \n" << toString(c_eval(i))<<endl;
	}
}
