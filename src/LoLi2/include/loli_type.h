/*
 * =====================================================================================
 *
 *       Filename:  loli_type.h
 *
 *    Description:  Type of LoLi
 *
 *        Version:  1.0
 *        Created:  07/17/2014 01:45:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_TYPE_
#define __LOLI_TYPE_

#define is_int(obj) obj->type == INT
#define is_flt(obj) obj->type == FLT
#define is_sym(obj) obj->type == SYM
#define is_proc(obj) obj->type == PROC
#define is_cons(obj) obj->type == CONS
#define is_lambda(obj) obj->type == LAMBDA
#define	is_char(obj) obj->type == CHAR
#define	is_str(obj) obj->type == CHAR
#define	is_bool(obj) obj->type == BOOL 
#define	is_type(obj) obj->type == TYPE 
#define	is_key(obj) obj->type == KEY 

#include "loli_obj.h"

extern loliObj* c_is_int(loliObj* obj);
extern loliObj* c_is_flt(loliObj* obj);
extern loliObj* c_is_sym(loliObj* obj);
extern loliObj* c_is_proc(loliObj* obj);
extern loliObj* c_is_lambda(loliObj* obj);
extern loliObj* c_is_char(loliObj* obj);
extern loliObj* c_is_str(loliObj* obj);
extern loliObj* c_is_cons(loliObj* obj);
extern loliObj* c_is_num(loliObj* obj);
extern loliObj* c_is_bool(loliObj* obj);
extern loliObj* c_is_type(loliObj* obj);
extern loliObj* c_is_obj(loliObj* obj);

loliKey* to_key(std::string k){
    return new loliKey(k);
}
loliObj* kint = to_key("INT");
loliObj* kflt = to_key("FLT");
loliObj* knum = to_key("NUM");
loliObj* ksym = to_key("SYM");
loliObj* kcons = to_key("CONS");
loliObj* kproc = to_key("PROC");
loliObj* klambda = to_key("LAMBDA");
loliObj* kchar = to_key("CHAR");
loliObj* kstr = to_key("STRING");
loliObj* kbool = to_key("BOOL");
loliObj* kkey = to_key("KEYWORD");
loliObj* kobj = to_key("_");

#endif
