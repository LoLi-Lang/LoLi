/*
 * =====================================================================================
 *
 *       Filename:  loli_cbmi.cpp
 *
 *    Description:  Context Based Meaning Inference System
 *
 *        Version:  1.0
 *        Created:  07/21/2014 09:59:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_obj.h"
#include "include/loli_env.h"
#include "include/loli_type.h"
#include "include/loli_util.h"

loliObj* build_sexp(loliObj* orig){
	if(nilp(orig)){
		return nil;
	}
	if(is_sym(orig)){
		loliObj* tmp;
		if(orig->env != NULL || !nilp(orig->env)){
			tmp = lookup_env(orig, orig->env);
		}else{
			tmp = lookup_top_env(orig);
		}
		if(nilp(tmp)){
			loli_err("Symbol " + toString(orig) + " is unbound!");
		}
		return tmp;
	}
	if(is_int(orig) || is_flt(orig)){
		return orig;
	}
	if(is_cons(orig)){
		
	}
	return orig;
}



