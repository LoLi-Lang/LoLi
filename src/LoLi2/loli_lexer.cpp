/*
 * =====================================================================================
 *
 *       Filename:  loli_lexer.cpp
 *
 *    Description:  Lexer of LoLi
 *
 *        Version:  1.0
 *        Created:  07/17/2014 11:19:20 AM
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
#include "include/loli_type.h"

loliObj* lexer_with_type(loliObj* exp, loliObj* env, loliType type);

loliObj* lexer(loliObj* exp, loliObj* env){
	if(exp->type == SYM){
		return lookup_env(exp, env);
	}else if(exp->type == CONS){

	}
	return exp;
}

loliObj* lexer_with_type(loliObj* exp, loliObj* env, loliType type){
	if(exp->type == SYM){
		if(!nilp(get_type(type, exp, env))){
			return get_type(type, exp, env);
		}
	}
	if(exp->type == type){
		return exp;
	}
	if(exp->type == CONS){
		if(head(exp)->type == LAMBDA){
			if(isType(head(exp)->LAMBDA.rtype, type)){
				
			}
		}
	}
	loli_err("Symbol not found");
	return nil;
}
