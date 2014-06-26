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

#include "include/loli_obj.h"
#include "include/loli_sexp.h"
#include "include/loli_util.h"
#include "include/loli_stack.h"

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
}
