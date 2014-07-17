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

#include "loli_obj.cpp"
#include "loli_util.cpp"

loliObj* top_env = nil;

loliObj* to_env_entry(loliObj* sym, loliObj* value){
	return c_cons(sym, value);
}

loliObj* add_to_env(loliObj* obj, loliObj* env){
	return c_cons(obj, env);
}

void add_to_top_env(loliObj* obj){
	top_env = add_to_env(obj, top_env);
}

loliObj* lookup_env(loliObj* sym, loliObj* env){
	loliObj* result = nil;
	for(loliObj* e = env; !nilp(e); e = tail(e)){
		if(head(head(e))->equals(sym)){
			result = c_cons(tail(head(e)), result);
		}
	}
	return result;
}

loliObj* lookup_top_env(loliObj* sym){
	return lookup_env(sym, top_env);
}

loliObj* get_type(loliType type, loliObj* sym, loliObj* env){
	loliObj* tmp = lookup_env(sym, env);
	if(nilp(tmp)){
		return nil;
	}
	for(loliObj* e = tmp; !nilp(e); e = tail(e)){
		if(head(e)->type == type){
			return head(e);
		}
	}
	return nil;
}

loliObj* c_def(loliObj* obj){
	loliObj* sym = head(obj);
	loliObj* value = head(tail(obj));
	if(!nilp(get_type(value->type, sym, top_env))){
		loli_err("Object: "+ toString(sym)  +" already exist, use set! to change the value");
		return nil;
	}else{
		add_to_top_env(to_env_entry(sym, value));
		return value;
	}
}

loliObj* c_set(loliObj* obj){
	loliObj* sym = head(obj);
	loliObj* value = head(tail(obj));
	if(nilp(get_type(value->type, sym, top_env))){
		loli_err("Symbol: "+ toString(sym) +" is not defined with this type, ues def to define");
		return nil;
	}else{
		*get_type(value->type, sym, top_env) = *to_env_entry(sym, value);
		return to_env_entry(sym, value);
	}
}
