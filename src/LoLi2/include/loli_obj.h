/*
 * =====================================================================================
 *
 *       Filename:  loli_obj.h
 *
 *    Description:  Object of LoLi
 *
 *        Version:  1.0
 *        Created:  06/26/2014 10:09:32 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_OBJ_
#define __LOLI_OBJ_

#include <string>


enum loliType {
	INT,
	FLT,
	SYM,
	CONS,
	LAMBDA,
	PROC,
	STR,
	CHAR,
	_
};

struct loliObj {
	
	bool 		inUse; //Reserved for GC

	typedef loliObj* (loliProc)(loliObj*);

	loliType 	type;

	struct {
		long int value;
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
		loliObj* rtype;
		loliObj* env;
		loliObj* exp;
	}LAMBDA;

	struct {
		loliProc* proc;
		loliObj* rtype;
	}PROC;

	struct {
		std::string value;
	}STR;

	struct {
		char value;
	}CHAR;

	loliObj(loliType type){
		this->type = type;
	}

	loliObj(){}

	bool equals(loliObj* o){
		if(o->type != this->type){
			return false;
		}else{
			switch(type){
				case loliType::INT:
					return o->INT.value == this->INT.value;
				case loliType::FLT:
					return o->FLT.value == this->FLT.value;
				case loliType::SYM:
					return o->SYM.name == this->SYM.name;
				case loliType::CHAR:
					return o->CHAR.value == this->CHAR.value;
				case loliType::STR:
					return o->STR.value == this->STR.value;
				case loliType::PROC:
					return o->PROC.proc == this->PROC.proc &&\
					       o->PROC.rtype == this->PROC.rtype;
				case loliType::CONS:
					return o->CONS.head == this->CONS.head && o->CONS.tail == this->CONS.tail;
				case loliType::LAMBDA:
					return o->LAMBDA.arg == this->LAMBDA.arg &&\
					       o->LAMBDA.rtype == this->LAMBDA.rtype &&\
					       o->LAMBDA.env == this->LAMBDA.env &&\
					       o->LAMBDA.exp == this->LAMBDA.exp;
				case loliType::_:
					return this==o;

			}
		}
	}
};

//Constructors
extern loliObj* to_int(long int n);
extern loliObj* to_flt(long double n);
extern loliObj* to_sym(std::string n);
extern loliObj* c_cons(loliObj* hd, loliObj* tl);
extern loliObj* c_proc(loliObj::loliProc* pr);
extern loliObj* to_lstring(std::string str);
extern loliObj* to_char(char ch);
extern loliObj* c_lambda(loliObj* arg, loliObj* types, loliObj* env, loliObj* exp);

extern loliObj* head(loliObj* o);
extern loliObj* tail(loliObj* o);

extern loliObj* nil;
extern loliObj* t;
extern loliObj* quote;

extern std::string toString(loliObj* obj);
extern std::string toString(loliType ty);

extern int length(loliObj* obj);
extern bool nilp(loliObj* obj);

#endif
