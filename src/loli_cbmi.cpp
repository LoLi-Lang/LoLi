/*
 * =====================================================================================
 *
 *       Filename:  loli_cbmi.cpp
 *
 *    Description:  The Context Based Meaning Inference
 *
 *        Version:  1.0
 *        Created:  04/27/2014 02:14:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include "loli_env.h"
#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_list.h"
#include "loli_cons.h"

loliObj* getType(loliType type, loliObj* sym, loliObj* env){
	loliObj* tmp = lookup(sym, env);
	for(;!nilp(tmp);tmp = tail(tmp)){
		if(head(tail(head(tmp)))->type == type){
			return head(tmp);
		}
	}
	return nil;
}
