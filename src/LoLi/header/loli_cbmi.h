/*
 * =====================================================================================
 *
 *       Filename:  loli_cbmi.h
 *
 *    Description:  The Context Based Meaning Inference Header
 *
 *        Version:  1.0
 *        Created:  04/27/2014 02:21:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#ifndef __LOLI_CBMI_
#define __LOLI_CBMI_

#include "loli_types.h"

extern loliObj* getType(loliType type, loliObj* obj, loliObj* env);

extern loliObj* get_cons(loliObj* sym, loliObj* env);
extern loliObj* get_int(loliObj* sym, loliObj* env);
extern loliObj* get_flt(loliObj* sym, loliObj* env);
extern loliObj* get_sym(loliObj* sym, loliObj* env);
extern loliObj* get_proc(loliObj* sym, loliObj* env);
extern loliObj* get_lambda(loliObj* sym, loliObj* env);

#endif
