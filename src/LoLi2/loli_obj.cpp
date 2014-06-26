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
#include "../header/loli_gc.h"

enum loliType {
	INT,
	FLT,
	SYM,
	CONS,
	LAMBDA,
	PROC,
	STR,
	CHAR
};

struct loliObj {
	
	typedef loliObj* (loliProc)(loliObj*);
	typedef loliObj* (loliProc)(loliObj*, loliObj*);
	typedef loliObj* (loliProc)(loliObj*, loliObj*, loliObj*);

	loliType 	type;

	union {
		struct {
			long long value;
		}INT; 
		struct {
			long double value;
		}FLT;

		struct {
			std::string name;
		}SYM;

		struct {
			loliObj* head;
			loliObj* tail;
		}CONS;

		struct {
			loliObj* arg;
			loliObj* types;
			loliObj* env;
			loliObj* exp;
		}LAMBDA;
		
		struct {
			loliProc* proc;
		}PROC;

		struct {
			std::string value;
		}STR;

		struct {
			char value;
		}CHAR;

	}value;

	loliObj(){}

	loliObj(loliType type){
		this.type = type;
	}

	std::string toString(){
		switch(this.type){
			case INT:
				return std::to_string(this.INT.value);
			case FLT:
				return std::to_string(this.FLT.value);
			case SYM:
				return this.SYM.name;
			case CONS:
				std::string tmp = "(" + this.CONS.head.toString();
				if(this.CONS.tail.type != CONS){
					return tmp + " . " + this.CONS.tail.toString() + ")";
				}else{
					return tmp + " " + this.CONS.tail.toString() + ")";
				}
			case LAMBDA:
				return "<LAMBDA EXP>";
			case PROC:
				return "<PROCEDURE>";
			case STR:
				return this.STR.value;
			case CHAR:
				return "#\\" + this.CHAR.value;
			default:
				return "";
		}
	}
};

loliObj* to_int(long long n){
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

loliObj* c_cons(loliObj* hd, loliObj* tl){
	loliObj* tmp = new (UseGC) loliObj(CONS);
	tmp->CONS.head = hd;
	tmp->CONS.tail = tl;
	return tmp;
}

loliObj* c_proc(loliProc* pr){
	loliObj* tmp = new (UseGC) loliObj(PROC);
	tmp->PROC.proc = pr;
	return tmp;
}

loliObj* to_string(std::string str){
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
	tmp->LAMBDA.types = types;
	tmp->LAMBDA.env = env;
	tmp->LAMBDA.exp = exp;
	return tmp;
}

loliObj* nil = to_sym("nil");
loliObj* t = to_sym("t");
