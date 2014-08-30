/*
 * =====================================================================================
 *
 *       Filename:  loli_prim.cpp
 *
 *    Description:  Primitive Functions of LoLi
 *
 *        Version:  1.0
 *        Created:  07/18/2014 01:08:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_obj.h"
#include "include/loli_util.h"
#include "include/loli_typeclass.h"

loliNum* c_plus(loliObj* obj){
	double tmp = 0;
	for(loliObj* o = obj; !o->nilp(); o = lcons(o)->tail()){
		if(lcons(o)->head()->type <= typeNUM){
			tmp = tmp + lnum(lcons(o)->head())->getValue();
		}
		else{
			loli_err(lcons(o)->head()->toString() + " is not a number!");
			return INT(0);
		}
	}
	if((long) tmp == tmp){
		return INT((long)tmp);
	}else{
		return FLT(tmp);
	}
}

loliNum* c_mult(loliObj* obj){
	double tmp = 0;
	for(loliObj* o = obj; !o->nilp(); o = lcons(o)->tail()){
		if(lcons(o)->head()->type <= typeNUM){
			tmp = tmp * lnum(lcons(o)->head())->getValue();
		}
		else{
			loli_err(lcons(o)->head()->toString() + " is not a number!");
			return INT(0);
		}
	}
	if((long) tmp == tmp){
		return INT((long)tmp);
	}else{
		return FLT(tmp);
	}
}

loliNum* c_sub(loliObj* obj){
	double tmp = 0;
	for(loliObj* o = obj; !o->nilp(); o = lcons(o)->tail()){
		if(lcons(o)->head()->type <= typeNUM){
			tmp = tmp - lnum(lcons(o)->head())->getValue();
		}
		else{
			loli_err(lcons(o)->head()->toString() + " is not a number!");
			return INT(0);
		}
	}
	if((long) tmp == tmp){
		return INT((long)tmp);
	}else{
		return FLT(tmp);
	}
}

loliNum* c_div(loliObj* obj){
	double tmp = 0;
	for(loliObj* o = obj; !o->nilp(); o = lcons(o)->tail()){
		if(lcons(o)->head()->type <= typeNUM){
			if(lnum(lcons(o)->head())->getValue() != 0){
			tmp = tmp / lnum(lcons(o)->head())->getValue();
			}else{
				loli_err("Error! Divide by ZERO!");
				return INT(0);
			}
		}
		else{
			loli_err(lcons(o)->head()->toString() + " is not a number!");
			return INT(0);
		}
	}
	if((long) tmp == tmp){
		return INT((long)tmp);
	}else{
		return FLT(tmp);
	}
}

loliObj* c_quote(loliObj* obj){
	return lcons(obj)->head();
}
