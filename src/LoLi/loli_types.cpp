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
#include <sstream>

#include "header/loli.h"
#include "header/loli_gc.h"

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

loliObj* mkflt(long double number){
	loliObj *tmp = new (UseGC) loliObj(FLT);
	std::stringstream ss;
	ss << number;
	std::string n;
	ss >> n;
	tmp->value = n;
	//tmp->value = std::to_string(number);
	return tmp;
}

loliObj* mkproc(loliObj::procedure &proc){
	loliObj *tmp = new (UseGC)loliObj(PROC);
	tmp->proc = proc;
	return tmp;
}

bool equals(loliObj* a, loliObj* b){
	if((a->type == b->type) && (a->value == b->value)){
		return true;
	}
	return false;
}

loliObj* prim_equals(loliObj* obj, loliObj* env){
	if(equals(head(obj), head(tail(obj)))){
		return t;
	}else{
		return nil;
	}
}
