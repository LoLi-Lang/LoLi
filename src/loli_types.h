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

//#ifndef __LOLI_CONS_
//#include "loli_cons.h"
//#endif

//#ifndef __LOLI_SYMS_
//#include "loli_symbols.h"
//#endif

enum loliType {
	SYM,	//Symbol
	INT,	//Integer
	FLT,	//Float Number
	CONS, 	//Cons
	PROC, 	//Procedure
	CHAR, 	//Character
	STRING,	//String
	LAMBDA,	//Lambda Expression
	_	//Wildcard
};

struct loliObj {
	typedef loliObj* (procedure)(loliObj *);
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

extern loliObj* mksym(std::string symName);
extern loliObj* mkint(int number);
extern loliObj* mkflt(double number);
extern loliObj* mkproc(loliObj::procedure &proc);

#endif
