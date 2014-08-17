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

loliObj* c_plu(loliObj* obj){
	double tmp = 0;
	for(loliObj* o = obj; !nilp(o); o = tail(o)){
		switch(head(o)->type){
			case INT:
				tmp = tmp + head(o)->INT.value;
				break;
			case FLT:
				tmp = tmp + head(o)->FLT.value;
				break;
			default:
				loli_err(toString(head(o)) + " is not a number!");
				return nil;
		}
	}
	if((long) tmp == tmp){
		return to_int((long)tmp);
	}else{
		return to_flt(tmp);
	}
}

loliObj* c_mul(loliObj* obj){
	double tmp = 1;
	for(loliObj* o = obj; !nilp(o); o = tail(o)){
		switch(head(o)->type){
			case INT:
				tmp = tmp * head(o)->INT.value;
				break;
			case FLT:
				tmp = tmp * head(o)->FLT.value;
				break;
			default:
				loli_err(toString(head(o)) + " is not a number!");
				return nil;
		}
	}
	if((long) tmp == tmp){
		return to_int((long)tmp);
	}else{
		return to_flt(tmp);
	}
}

loliObj* c_sub(loliObj* obj){
	double tmp;
	switch(head(obj)->type){
		case INT:
			tmp = obj->INT.value;
			break;
		case FLT:
			tmp = obj->FLT.value;
			break;
		default:
			loli_err(toString(head(obj)) + " is not a number!");
	}
	for(loliObj* o = tail(obj); !nilp(o); o = tail(o)){
		switch(head(o)->type){
			case INT:
				tmp = tmp - head(o)->INT.value;
				break;
			case FLT:
				tmp = tmp - head(o)->FLT.value;
				break;
			default:
				loli_err(toString(head(o)) + " is not a number!");
				return nil;
		}
	}
	if((long) tmp == tmp){
		return to_int((long)tmp);
	}else{
		return to_flt(tmp);
	}
}

loliObj* c_div(loliObj* obj){
	double tmp;
	switch(head(obj)->type){
		case INT:
			tmp = obj->INT.value;
			break;
		case FLT:
			tmp = obj->FLT.value;
			break;
		default:
			loli_err(toString(head(obj)) + " is not a number!");
	}
	for(loliObj* o = tail(obj); !nilp(o); o = tail(o)){
		switch(head(o)->type){
			case INT:
				if(head(o)->INT.value == 0){
					loli_err("Error, division by zero");
					return nil;
				}
				tmp = tmp / head(o)->INT.value;
				break;
			case FLT:
				if(head(o)->FLT.value == 0){
					loli_err("Error, division by zero");
					return nil;
				}
				tmp = tmp / head(o)->FLT.value;
				break;
			default:
				loli_err(toString(head(o)) + " is not a number!");
				return nil;
		}
	}
	if((long) tmp == tmp){
		return to_int((long)tmp);
	}else{
		return to_flt(tmp);
	}
}

loliObj* c_quote(loliObj* obj){
	return head(obj);
}
