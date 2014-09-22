/*
 * =====================================================================================
 *
 *       Filename:  loli_env.h
 *
 *    Description:  Env of LoLi
 *
 *        Version:  1.0
 *        Created:  07/17/2014 01:15:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_ENV_
#define __LOLI_ENV_

#include "loli_obj.h"
#include "loli_typeclass.h"

extern loliCons* top_env;

extern loliCons* to_env_entry(loliObj* sym, loliObj* value);
extern loliCons* add_to_env(loliObj* obj, loliObj* env);
extern loliObj* add_to_top_env(loliObj* obj);
extern loliObj* lookup_env(loliObj* sym, loliObj* env);
extern loliObj* lookup_top_env(loliObj* sym);
extern loliObj* get_type(loliTypeClass* type, loliObj* sym, loliObj* env);

//Primitive functions:
extern loliObj* c_def(loliObj* obj);
extern loliObj* c_set(loliObj* obj);

#endif
