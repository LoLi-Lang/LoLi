/*
 * =====================================================================================
 *
 *       Filename:  loli_lambda.cpp
 *
 *    Description:  Lambda of LoLi
 *
 *        Version:  1.0
 *        Created:  09/26/2014 03:33:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_obj.h"
#include "include/loli_typeclass.h"

#include <iostream>

loliObj* c_lambda(loliObj* exp){
    auto s = lcons(exp)->head(); //Return type
    auto a = lcons(lcons(exp)->tail())->head(); //Arg List   
    auto e = lcons(lcons(lcons(exp)->tail())->tail())->head(); //Exp

    std::cout<<s->toString()<<"\t"<<a->toString()<<"\t"<<e->toString()<<std::endl;

    return LAMBDA(lkey(s), a, e);
}
