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
#include <map>

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
struct environment;

struct loliObj {
	loliType type;
	std::string value;
	loliObj * head;
	loliObj * tail;	//Array For HEAD and TAIL
	environment * env;
	typedef loliObj (*procedure)(loliObj &);
	typedef std::map<std::string, loliObj> map;

};

extern loliObj mksym(std::string symName);
extern loliObj mkint(int number);
extern loliObj mkflt(double number);

#endif
