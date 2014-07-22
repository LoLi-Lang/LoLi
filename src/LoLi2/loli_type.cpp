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
#include "include/loli_type.h"

loliObj* c_is_int(loliObj* obj){
	return is_int(obj) ? boolt : boolf;
}

loliObj* c_is_flt(loliObj* obj){
	return is_flt(obj) ? boolt : boolf;
}

loliObj* c_is_num(loliObj* obj){
	return is_flt(obj) || is_int(obj) ? boolt : boolf;
}

loliObj* c_is_sym(loliObj* obj){
	return is_sym(obj) ? boolt : boolf;
}

loliObj* c_is_proc(loliObj* obj){
	return is_proc(obj) ? boolt : boolf;
}

loliObj* c_is_cons(loliObj* obj){
	return is_cons(obj) ? boolt : boolf;
}

loliObj* c_is_lambda(loliObj* obj){
	return is_lambda(obj) ? boolt : boolf;
}

loliObj* c_is_char(loliObj* obj){
	return is_char(obj) ? boolt : boolf;
}

loliObj* c_is_str(loliObj* obj){
	return is_str(obj) ? boolt : boolf;
}

loliObj* c_is_bool(loliObj* obj){
	return is_bool(obj) ? boolt : boolf;
}

loliObj* c_is_key(loliObj* obj){
	return is_key(obj) ? boolt : boolf;
}

loliObj* c_is_type(loliObj* obj){
	return is_type(obj) ? boolt : boolf;
}

loliObj* c_is_obj(loliObj* obj){
	return boolt;
}

