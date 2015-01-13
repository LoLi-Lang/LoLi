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
#include <iostream>
#include <cmath>

#include "header/loli.h"

loliObj* proc_sum(loliObj* lst, loliObj* env){
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

loliObj* proc_mul(loliObj* lst, loliObj* env){
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

loliObj* proc_sub(loliObj* lst, loliObj* env){
	while(true){
		if(nilp(lst)){
			return mkint(0);
		}
		if(head(lst)->type == INT || (head(lst)->type == FLT)){
			break;
		}
		lst = tail(lst);
	}
	double tmp = std::stod(head(lst)->value);
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

loliObj* proc_div(loliObj* lst, loliObj* env){
	while(true){
		if(nilp(lst)){
			return mkint(0);
		}
		if(head(lst)->type == INT || (head(lst)->type == FLT)){
			break;
		}
		lst = tail(lst);
	}
	double tmp = std::stod(head(lst)->value);
	for(loliObj* e = tail(lst);!nilp(e);e = tail(e)){
		if(head(e)->type == INT || (head(e)->type == FLT)){
			if(std::stod(head(e)->value) != 0){
				tmp = tmp / std::stod(head(e)->value);
			}else{
				std::cout<<"\nWarnning: Cannot be ZERO, ignored\n";
			}
		}
	}
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

loliObj* proc_add1(loliObj* num, loliObj* env){
	double tmp;
	try{
		tmp = std::stod(head(num)->value) + 1;
	}catch(...){
		std::cout<<toString(num)<<" is an invalid argument!"<<std::endl;
		return nil;
	}
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

loliObj* proc_sub1(loliObj* num, loliObj* env){
	double tmp;
	try{
		tmp = std::stod(head(num)->value) - 1;
	}catch(...){
		std::cout<<toString(num)<<" is an invalid argument!"<<std::endl;
		return nil;
	}
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

loliObj* proc_mod(loliObj* lst, loliObj* env){
	while(true){
		if(nilp(lst)){
			return mkint(0);
		}
		if(head(lst)->type == INT || (head(lst)->type == FLT)){
			break;
		}
		lst = tail(lst);
	}
	double tmp = std::stod(head(lst)->value);
	for(loliObj* e = tail(lst);!nilp(e);e = tail(e)){
		if(head(e)->type == INT || (head(e)->type == FLT)){
			if(std::stod(head(e)->value) != 0){
				tmp = fmod(tmp, std::stod(head(e)->value));
			}else{
				std::cout<<"\nWarnning: Cannot be ZERO, ignored\n";
			}
		}
	}
	if((int)tmp == tmp){
		return mkint((int)tmp);
	}
	return mkflt(tmp);
}

loliObj* proc_greater(loliObj* lst, loliObj* env){
	while(true){
		if(nilp(lst)){
			return mkint(0);
		}
		if(head(lst)->type == INT || (head(lst)->type == FLT)){
			break;
		}
		lst = tail(lst);
	}
	double tmp = std::stod(head(lst)->value);
	for(loliObj* e = tail(lst);!nilp(e);e = tail(e)){
		if(head(e)->type == INT || (head(e)->type == FLT)){
			if(tmp <= std::stod(head(e)->value)){
				return nil;
			}
		}
	}
	return t;
}

loliObj* proc_lesser(loliObj* lst, loliObj* env){
	while(true){
		if(nilp(lst)){
			return mkint(0);
		}
		if(head(lst)->type == INT || (head(lst)->type == FLT)){
			break;
		}
		lst = tail(lst);
	}
	double tmp = std::stod(head(lst)->value);
	for(loliObj* e = tail(lst);!nilp(e);e = tail(e)){
		if(head(e)->type == INT || (head(e)->type == FLT)){
			if(tmp >= std::stod(head(e)->value)){
				return nil;
			}
		}
	}
	return t;
}

loliObj* proc_exit(loliObj* dum, loliObj* env){
	//Dummy input, do nothing
	exit(0);
}

loliObj* proc_atom(loliObj* obj, loliObj* env){
	if(head(obj)->type == CONS){
		return nil;
	}else{
		return t;
	}
}
