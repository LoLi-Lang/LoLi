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

#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"

string toString(loliObj* obj){
	switch(obj->type){
		case INT:
		case FLT:
		case SYM:
			return obj->value;
		case CONS:
			if(nilp(head(obj))){
				return "NIL";
			}else if(nilp(tail(obj))){
				return "(" + toString(head(obj)) + ")";
			}else{
				return "(" + toString(head(obj)) + " . " + toString(tail(obj)) + ")";
			}
		case PROC:
			return "<PROCEDURE>";
		case LAMBDA:
			return "<LAMBDA>";
	}
}
