/*
 * =====================================================================================
 *
 *       Filename:  loli_typeenv.h
 *
 *    Description:  Type Env of LoLi
 *
 *        Version:  1.0
 *        Created:  08/30/2014 06:57:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_TYPEENV_
#define __LOLI_TYPEENV_

#include "loli_obj.h"
#include "loli_typeclass.h"

class typeEntry {
	public:
	loliSym* 	id;
	loliTypeClass* 	type;

	typeEntry(){}

	typeEntry(loliTypeClass* tp){
		id = SYM(tp->identifier);
		type = tp;
	}

	typeEntry(loliObj* i, loliTypeClass* tp){
		id = lsym(i);
		type = tp;
	}
};

#endif
