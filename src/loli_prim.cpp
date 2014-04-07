/*
 * =====================================================================================
 *
 *       Filename:  loli_prim.cpp
 *
 *    Description:  The primitive functions of LoLi
 *
 *        Version:  1.0
 *        Created:  04/07/2014 12:33:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <string>

#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"

loliObj* proc_sum(loliObj* lst){
	double tmp = 0;
	for(loliObj* e = lst;!nilp(e);e = tail(e)){
		if(head(e)->type == INT || (head(e)->type == FLT)){
			tmp = tmp + std::stod(head(e)->value);
		}
	}
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

loliObj* proc_mul(loliObj* lst){
	double tmp = 1;
	for(loliObj* e = lst;!nilp(e);e = tail(e)){
		if(head(e)->type == INT || (head(e)->type == FLT)){
			tmp = tmp * std::stod(head(e)->value);
		}
	}
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

loliObj* proc_sub(loliObj* lst){
	if(nilp(lst)){
		return mkint(0);
	}
	double tmp = std::stoi(head(lst)->value);
	for(loliObj* e = tail(lst);!nilp(e);e = tail(e)){
		if(head(e)->type == INT || (head(e)->type == FLT)){
			tmp = tmp - std::stod(head(e)->value);
		}
	}
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

loliObj* proc_div(loliObj* lst){
	if(nilp(lst)){
		return mkint(0);
	}
	double tmp = std::stoi(head(lst)->value);
	for(loliObj* e = tail(lst);!nilp(e);e = tail(e)){
		if(head(e)->type == INT || (head(e)->type == FLT)){
			tmp = tmp / std::stod(head(e)->value);
		}
	}
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

loliObj* proc_add1(loliObj* num){
	double tmp = std::stod(num->value) + 1;
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

loliObj* proc_sub1(loliObj* num){
	double tmp = std::stod(num->value) - 1;
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}
