/*
 * =====================================================================================
 *
 *       Filename:  loli_output.cpp
 *
 *    Description:  The output part of LoLi
 *
 *        Version:  1.0
 *        Created:  04/19/2014 05:13:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>

#include "header/loli.h"

std::string toString(loliObj* obj){
	switch(obj->type){
		case INT:
		case FLT:
		case SYM:
			return obj->value;
		case CONS:
			//	if(nilp(head(obj))){
			//		return "NIL";
			//			}else if(nilp(tail(obj))){
			//				return "(" + toString(head(obj)) + ")";
			//	}else{
			if(head(obj) == quote){
				return "'" + toString(head(tail(obj)));
			}else{
				return "(" + toString(head(obj)) + " . " + toString(tail(obj)) + ")";
			}
		case CHAR:
		case STRING:
			return obj->value;
		case PROC:
			return "<PROCEDURE>";
		case LAMBDA:
			return "<LAMBDA " + toString(obj->env) + ">";
	}
	return "";
	}
