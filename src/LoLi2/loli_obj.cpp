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
};

loliObj* to_int(long long n){
	loliObj* tmp = new (UseGC) loliObj*(INT);
	tmp->integer.value = n;
	return tmp;
}
