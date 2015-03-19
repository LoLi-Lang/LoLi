/*
 * =====================================================================================
 *
 *       Filename:  loli_eval.cpp
 *
 *    Description:  Eval of LoLi
 *
 *        Version:  1.0
 *        Created:  07/18/2014 11:16:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_obj.h"
#include "include/loli_env.h"
#include "include/loli_util.h"
#include "include/loli_apply.h"

#include <iostream>
#include <typeinfo>

loliObj* eval_list(loliObj* lst, loliObj* env);

loliObj* loliSym::eval(loliObj* e){
    this->type = typeSYM;
    if(this->name == "nil" || this == nil){
        return nil;
    }
    if(this->name == "t" || this == t){
        return t;
    }
    if(e->nilp() || e == NULL){
        loliObj* r = lookup_top_env(this);
        if(r->nilp()){
            loli_err("Symbol: " + this->toString() + " is not bound.");
            return nil;
        }else{
            return lcons(r)->head();
        }
    }else{
        loliObj* r = lookup_env(this, e);
        if(r->nilp()){
            loli_err("Symbol: " + this->toString() + " is not bound in its environment.");
            return nil;
        }else{
            return lcons(r)->head();
        }
    }
}

loliObj* loliCons::eval(loliObj* env){
    this->type = typeCONS;
    //   std::cout<<this->type->toString()<<std::endl;
    if(this->head() == SYM("if")){
        loliObj* cond = lcons(this->tail())->head();
        if(this->tail()->nilp()){
            loli_err("Need at least one expression for if");
            return nil;
        }
        loliObj* wt = lcons(lcons(this->tail())->tail())->head();
        loliObj* wf = lcons(lcons(lcons(this->tail())->tail())->tail())->head();
        if(cond->eval(env)==boolt){
            return wt->eval(top_env);
        }else if(cond->eval(env)==boolf){
            if(wf){
                return wf->eval(top_env);
            }else{
                return nil;
            }
        }else{
            loli_err("Condition error");
            return nil;
        }
    }
    return eval_list(this, env);
}

loliObj* eval_list(loliObj* lst, loliObj* env){
    loliObj* car = lcons(lst)->head()->eval(env);
    loliObj* cdr = lcons(lst)->tail();
    std::cout<<"HEAD: "<<car->toString()<<"\tTAIL: "<<cdr->toString()<<std::endl;
    //    std::cout<<cdr->type->toString()<<std::endl;
    if(lfunc(car)->rtype){
        if(lcons(lcons(lcons(cdr)->tail())->head())->hd == NULL){
            std::cout<<lcons(lcons(lcons(cdr)->tail())->head())->toString()<<std::endl;
            return c_apply(car, cdr->eval(env), env);
        }
        return c_apply(car, cdr, env);
    }
    else{
        loli_err(car->toString() + " is not a function!");
    }
    return nil;
}
