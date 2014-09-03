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
#include "include/loli_typeclass.h"

using namespace std;

int main(){
    if(typeINT->isFrom(typeNUM)){
        cout<<"INT <= NUM"<<endl;
    }
	loliObj* test = CONS(SYM("a"), CONS(SYM("b"), CONS(SYM("c"), sCONS(SYM("d")))));
	cout<<"Length of "<< test->toString()<<": "<< test->length()<<endl;
	while(true){
		cout<<"Get Input: ";
		string tmp = read_pair();
	//	cout<<"Input: "<<tmp<<endl;
		loliObj* i = parse_string(tmp, top_env);
	//	cout<<toString(i)<<endl;
		cout<<"Test Eval: \n" << i->eval(top_env)->toString()<<endl;
	}
}
