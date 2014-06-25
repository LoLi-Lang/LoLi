/*
 * =====================================================================================
 *
 *       Filename:  loli_sexp.cpp
 *
 *    Description:  S-Expression
 *
 *        Version:  1.0
 *        Created:  06/25/2014 01:20:49 PM
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

struct sexp {
	std::string 	value;
	sexp*		next;

	sexp(){}

	sexp(std::string value){
		this.value = value;
		this.next = NULL;
	}
	
	std::string toString(){
		if(next != NULL){
			return value + " |-> " + next.toString();
		}else{
			return value;
		}
	}
}

sexp* END = new sexp("");
