/*
 * =====================================================================================
 *
 *       Filename:  loli_eval.cpp
 *
 *    Description:  Evaluation part of LoLi
 *
 *        Version:  1.0
 *        Created:  04/11/2014 03:00:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include "loli_types.h"
#include "loli_cons.h"
#include "loli_symbols.h"

loliObj* eval(loliObj* obj, loliObj* env){
	if(nilp(obj)){
		return nil;
	}else{
		switch(obj->type){
			case INT:
			case FLT:
				return obj;
			case CONS:
			case SYM:
			case CHAR:
			case STRING:
			case PROC:
				return obj;
			default:
				return nil;
		}
	}
}
