/*
 * =====================================================================================
 *
 *       Filename:  loli_obj.cpp
 *
 *    Description:  Object of LoLi
 *
 *        Version:  1.0
 *        Created:  06/25/2014 03:19:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <string>
#include <iostream>
#include <sstream>
#include "../header/loli_gc.h"
#include "include/loli_obj.h"

loliObj* to_int(long int n){
	loliObj* tmp = new (UseGC) loliObj(INT);
	tmp->INT.value = n;
	return tmp;
}

loliObj* to_flt(long double n){
	loliObj* tmp = new (UseGC) loliObj(FLT);
	tmp->FLT.value = n;
	return tmp;
}

loliObj* to_sym(std::string n){
	loliObj* tmp = new (UseGC) loliObj(SYM);
	tmp->SYM.name = n;
	return tmp;
}

loliObj* to_key(std::string n){
	loliObj* tmp = new (UseGC) loliObj(KEY);
	tmp->KEY.value= n;
	return tmp;
}

loliObj* c_cons(loliObj* hd, loliObj* tl){
	loliObj* tmp = new (UseGC) loliObj(CONS);
	tmp->CONS.head = hd;
	tmp->CONS.tail = tl;
	return tmp;
}

loliObj* c_proc(loliObj::loliProc* pr, loliObj* itype, loliObj* rtype){
	loliObj* tmp = new (UseGC) loliObj(PROC);
	tmp->PROC.proc = pr;
	tmp->PROC.itype = itype;
	tmp->PROC.rtype = rtype;
	return tmp;
}

loliObj* to_lstring(std::string str){
	loliObj* tmp = new (UseGC) loliObj(STR);
	tmp->STR.value = str;
	return tmp;
}

loliObj* to_char(char ch){
	loliObj* tmp = new (UseGC) loliObj(CHAR);
	tmp->CHAR.value = ch;
	return tmp;
}

loliObj* c_lambda(loliObj* arg, loliObj* types, loliObj* env, loliObj* exp){
	loliObj* tmp = new (UseGC) loliObj(LAMBDA);
	tmp->LAMBDA.arg = arg;
	tmp->LAMBDA.itype = head(types);
	tmp->LAMBDA.rtype = head(tail(types));
	tmp->LAMBDA.env = env;
	tmp->LAMBDA.exp = exp;
	return tmp;
}

loliObj* to_bool(bool b){
	loliObj* tmp = new (UseGC) loliObj(BOOL);
	tmp->BOOL.value = b;
	return tmp;
}

loliObj* head(loliObj* o){
	return o->CONS.head;
}

loliObj* tail(loliObj* o){
	return o->CONS.tail;
}

loliObj* nil = to_sym("nil");
loliObj* t = to_sym("t");
loliObj* quote = to_sym("quote");

loliObj* boolt = to_bool(true);
loliObj* boolf = to_bool(false);

std::string toString(loliObj* obj){
	switch(obj->type){
		case INT:
			{
				return std::to_string(obj->INT.value);
			}
		case FLT:
			return std::to_string(obj->FLT.value);
		case SYM:
			return obj->SYM.name;
		case CONS:{
			std::string tmp = "(" + toString(obj->CONS.head);
			if(obj->CONS.tail->type != CONS){
				return tmp + " . " + toString(obj->CONS.tail) + ")";
			}else{
				return tmp + " " + toString(obj->CONS.tail) + ")";
			}
			return ""; //Blank
		}
		case LAMBDA:
			return "<LAMBDA EXP " + toString(obj->LAMBDA.arg) + " Return Type: " + toString(obj->LAMBDA.rtype) + ">";
		case PROC:
			return "<PROCEDUE Return Type: " + toString(obj->PROC.rtype) +">";
		case STR:
			return obj->STR.value;
		case CHAR:{
			std::stringstream ss;
			ss << "#\\" << obj->CHAR.value;
			std::string c;
			ss >> c;
			return c;
		}
		case KEY:
			return ":" + obj->KEY.value;
		case BOOL:
			return obj->BOOL.value ? "TRUE" : "FALSE";
		case TYPE:
			return "Type: " + toString(obj->TYPE.name) + " " + toString(obj->TYPE.def);
	}
}

std::string toString(loliType ty){
	switch(ty){
		case INT:
			return "Integer";
		case FLT:
			return "Float";
		case SYM:
			return "Symbol";
		case CONS:
			return "Cons";
		case LAMBDA:
			return "Lambda";
		case PROC:
			return "Procedure";
		case STR:
			return "String";
		case CHAR:
			return "Character";
		case BOOL:
			return "Boolean";
		case KEY:
			return "Keyword";
		case TYPE:
			return "Type";
	}
}

int length(loliObj* obj){
	if(nilp(obj)){
		return 0;
	}
	switch(obj->type){
		case loliType::CONS:
			return 1 + length(obj->CONS.tail);
		case loliType::STR:
			return obj->STR.value.length();
		default:
			return 1;
	}
}

bool nilp(loliObj* obj){
	return obj->equals(nil);
}
