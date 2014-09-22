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
#include "include/loli_prim.h"
#include "include/loli_env.h"
#include "include/loli_typeclass.h"

using namespace std;

int main(){
    add_to_top_env(to_env_entry(SYM("nil"), nil));
    add_to_top_env(to_env_entry(SYM("t"), t));
    add_to_top_env(to_env_entry(SYM("quote"), quote));
    add_to_top_env(to_env_entry(SYM("+"), PROC(c_plus, KEY("NUM"), KEY("NUM"))));
    auto lop = SYM("+");
    loliSym* lsp = SYM("+");
    if(lsym(lsp)->equal(lop)){
        cout<<"Equal!"<<endl;
    }else{
        cout<<lsp->name<<"\t"<<lsym(lop)->name<<endl;
        if(lsym(lop)->name == lsp->name){
            cout<<"Name equal!"<<endl;
        }
    }
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
