/*
 * =====================================================================================
 *
 *       Filename:  loli_type.cpp
 *
 *    Description:  Type of LoLi
 *
 *        Version:  1.0
 *        Created:  07/17/2014 01:37:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_obj.h"

loliObj* linteger = to_sym("int");
loliObj* lfloat = to_sym("flt");
loliObj* lnumber = to_sym("num");
loliObj* lsym = to_sym("sym");
loliObj* lcons = to_sym("cons");
loliObj* lproc = to_sym("proc");
loliObj* lstr = to_sym("str");
loliObj* lchar = to_sym("char");
loliObj* lobj = to_sym("_");

bool isType(loliObj* sym, loliType type){
	if(sym->equals(lobj)){
		return true;
	}
	switch(type){
		case INT:
			return sym->equals(linteger) || sym->equals(lnumber);
		case FLT:
			return sym->equals(lfloat) || sym->equals(lnumber);
		case SYM:
			return sym->equals(lsym);
		case PROC:
		case LAMBDA:
			return sym->equals(lproc);
		case CONS:
			return sym->equals(lcons);
		case CHAR:
			return sym->equals(lchar);
		case STR:
			return sym->equals(lstr);
		case _:
			return true;
	}
}

loliObj* c_get_type(loliObj* obj){
	return to_sym(toString(head(obj)->type));
}
