/*
 * =====================================================================================
 *
 *       Filename:  loli_types.cpp
 *
 *    Description:  The Type System of LoLi  
 *
 *        Version:  1.0
 *        Created:  04/04/2014 07:15:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_gc.h"


loliObj* mksym(std::string symName){
	loliObj *tmp = new (UseGC) loliObj(SYM);
	tmp->value = symName;
	return tmp;
}

loliObj* mkint(int number){
	loliObj *tmp = new (UseGC) loliObj(INT);
	tmp->value = std::to_string(number);
	return tmp;
}

loliObj* mkflt(double number){
	loliObj *tmp = new (UseGC) loliObj(FLT);
	tmp->value = std::to_string(number);
	return tmp;
}

loliObj* mkproc(loliObj::procedure &proc){
	loliObj *tmp = new (UseGC)loliObj(PROC);
	tmp->proc = proc;
	return tmp;
}
