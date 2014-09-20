/*
 * =====================================================================================
 *
 *       Filename:  loli_env.cpp
 *
 *    Description:  Env of LoLi
 *
 *        Version:  1.0
 *        Created:  07/17/2014 12:02:03 PM
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
#include "include/loli_util.h"

#include <iostream>

loliObj* top_env = nil;

loliObj* to_env_entry(loliObj* sym, loliObj* value){
	return CONS(sym, value);
}

loliObj* add_to_env(loliObj* obj, loliObj* env){
	return CONS(obj, env);
}

void add_to_top_env(loliObj* obj){
	top_env = add_to_env(obj, top_env);
}

loliObj* lookup_env(loliObj* sym, loliObj* env){
	loliObj* result = nil;
	for(auto e = env; !e->nilp(); e = lcons(e)->tail()){
        std::cout<<lcons(e)->head()->toString()<<std::endl;
        std::cout<<lcons(lcons(e)->head())->head()->type->toString()<<std::endl;
		if(lsym(lcons(lcons(e)->head())->head()) == lsym(sym)){
			result = CONS(lcons(lcons(e)->head())->tail(), result);
		}
	}
	return result;
}

loliObj* lookup_top_env(loliObj* sym){
	return lookup_env(sym, top_env);
}

loliObj* get_type(loliTypeClass* type, loliObj* sym, loliObj* env){
	loliObj* tmp = lookup_env(sym, env);
	if(tmp->nilp()){
		return nil;
	}
	for(loliObj* e = tmp; !e->nilp(); e = lcons(e)->tail()){
		if(lcons(e)->head()->type <= type){
			return lcons(e)->head();
		}
	}
	return nil;
}

loliObj* c_def(loliObj* obj){
	loliObj* sym = lsym(lcons(obj)->head());
	loliObj* value = lcons(lcons(obj)->tail())->head();
	if(!get_type(value->type, sym, top_env)->nilp()){
		loli_err("Object: "+ sym->toString()  +" already exist, use set! to change the value");
		return nil;
	}else{
		add_to_top_env(to_env_entry(sym, value));
		return value;
	}
}

loliObj* c_set(loliObj* obj){
	loliObj* sym = lsym(lcons(obj)->head());
	loliObj* value = lcons(lcons(obj)->tail())->head();
	if(get_type(value->type, sym, top_env)->nilp()){
		loli_err("Symbol: "+ sym->toString() +" is not defined with this type, ues def to define");
		return nil;
	}else{
		*get_type(value->type, sym, top_env) = *to_env_entry(sym, value);
		return to_env_entry(sym, value);
	}
}
