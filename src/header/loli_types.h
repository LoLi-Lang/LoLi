/*
 * =====================================================================================
 *
 *       Filename:  loli_types.h
 *
 *    Description:  The Type System of LoLi
 *
 *        Version:  1.0
 *        Created:  04/04/2014 07:47:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_TYPES_
#define __LOLI_TYPES_

#include <string>

enum loliType {
	SYM,	//Symbol
	INT,	//Integer
	FLT,	//Float Number
	CONS, 	//Cons
	PROC, 	//Procedure
	CHAR, 	//Character
	STRING,	//String
	LAMBDA	//Lambda Expression
};

struct loliObj {
	typedef loliObj* (procedure)(loliObj *, loliObj *);
	loliType	type;
	std::string 	value;
	loliObj *	head;
	loliObj * 	tail;
	loliObj * 	env;
	procedure * 	proc;

	loliObj(loliType tp){
		type = tp;
	}
};

extern loliObj *mksym(std::string symName);
extern loliObj* mkint(int number);
extern loliObj* mkflt(long double number);
extern loliObj* mkproc(loliObj::procedure &proc);
extern bool equals(loliObj* a, loliObj* b);
extern loliObj* prim_equals(loliObj* obj, loliObj* env);

#endif
