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
#include "include/loli_sexp.h"
#include "include/loli_util.h"
#include "include/loli_stack.h"
#include "include/loli_reader.h"
#include "include/loli_ast.h"

using namespace std;

int main(){
	cout<<"Testing CHAR: " << toString(to_char('a')) <<endl;
	cout<<"Testing INT: " << toString(to_int(100000000)) << endl;
	cout<<"Testing FLOAT: " << toString(to_flt(123.456789))<< endl;
	cout<<"Testing SYM: " << toString(to_sym("SYM"))<< endl;
	cout<<"Testing CONS: " << toString(c_cons(t, nil)) <<endl;
	loli_err("Test Err");
	cout<<"Testing CONS: " << toString(c_cons(t, c_cons(t, nil))) <<endl;
	global_stack.push_obj(to_int(10000));
	global_stack.push_obj(to_flt(123.456));
	global_stack.push_obj(to_sym("test"));
	global_stack.push_obj(c_cons(t, nil));
	cout<<"Test Stack: \n" << stack_to_string(global_stack);
	loliObj* test = c_cons(to_sym("a"), c_cons(to_sym("b"), c_cons(to_sym("c"), c_cons(to_sym("d"), nil))));
	cout<<"Length of "<< toString(test)<<": "<< length(test)<<endl;
	while(true){
		cout<<"Get Input: ";
		string tmp = read_pair();
		cout<<"Test SExp: \n" << to_sexp(tmp)->toString()<<endl;
	}
}
