/*
 * =====================================================================================
 *
 *       Filename:  loli_env.h
 *
 *    Description:  Environment of LoLi
 *
 *        Version:  1.0
 *        Created:  04/17/2014 02:34:28 AM
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

#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"
#include "loli_ast.h"

extern loliObj* top_env;
extern loliObj* mkEnvProc(loliObj* sym, loliObj* type, loliObj* proc);
extern void addToEnv(loliObj* env, loliObj* obj);
extern loliObj* lookup(loliObj* sym, loliObj* env);

#endif
