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
    cout<<typeOBJ->toString()<<endl;
    cout<<typeNUM->toString()<<endl;
    cout<<typeINT->toString()<<endl;
    cout<<typeFLT->toString()<<endl;
    cout<<typeSYM->toString()<<endl;
    loliObj* test = CONS(SYM("a"), CONS(SYM("b"), CONS(SYM("c"), sCONS(SYM("d")))));
    cout<<"Length of "<< test->toString()<<": "<< test->length()<<endl;
    add_to_top_env(to_env_entry(SYM("nil"), nil));
    add_to_top_env(to_env_entry(SYM("t"), t));
    add_to_top_env(to_env_entry(SYM("quote"), quote));
    add_to_top_env(to_env_entry(KEY("true"), boolt));
    add_to_top_env(to_env_entry(KEY("false"), boolf));
    while(true){
        cout<<"Get Input: ";
        string tmp = read_pair();
        //	cout<<"Input: "<<tmp<<endl;
        while(isspace(tmp[0])){
            tmp=tmp.substr(1);
        }
        if(tmp[0] != '\0'){
            loliObj* i = parse_string(tmp, top_env);
            cout<<"Test Eval: \n" << i->eval(top_env)->toString()<<endl;
        }
    }
}
