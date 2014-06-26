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
	CHAR
};

struct loliObj {
	
	typedef loliObj* (loliProc)(loliObj*);

	loliType 	type;

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

	loliObj(loliType type){
		this->type = type;
	}

};


//Constructors
extern loliObj* to_int(long long n);
extern loliObj* to_flt(long double n);
extern loliObj* to_sym(std::string n);
extern loliObj* c_cons(loliObj* hd, loliObj* tl);
extern loliObj* c_proc(loliObj::loliProc* pr);
extern loliObj* to_string(std::string str);
extern loliObj* to_char(char ch);
extern loliObj* c_lambda(loliObj* arg, loliObj* types, loliObj* env, loliObj* exp);

extern loliObj* nil;
extern loliObj* t;

extern std::string toString(loliObj* obj);

#endif
