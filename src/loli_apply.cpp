/*
 * =====================================================================================
 *
 *       Filename:  loli_apply.cpp
 *
 *    Description:  Apply Of LoLi
 *
 *        Version:  1.0
 *        Created:  05/13/2014 06:34:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "loli.h"

loliObj* apply(loliObj* proc, loliObj* obj){
	return proc->proc(obj);
}
