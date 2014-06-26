/*
 * =====================================================================================
 *
 *       Filename:  loli_sexp.h
 *
 *    Description:  S-Expression
 *
 *        Version:  1.0
 *        Created:  06/25/2014 02:46:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_SEXP_
#define __LOLI_SEXP_

#include <string>

#include "loli_obj.h"

struct sexp {
	loliObj* 	value;
	sexp*		next;

	sexp(){}

	sexp(std::string value){
		this->value = to_sym(value);
		this->next = NULL;
	}
	
	std::string toString(){
		if(next != NULL){
			return ::toString(value) + " |-> " + next->toString();
		}else{
			return ::toString(value);
		}
	}
};

extern sexp* END;

extern sexp* to_sexp(std::string str);

#endif
