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

#include <iostream>

loliObj* apply(loliObj* proc, loliObj* obj){
	std::cout<<std::endl<<"Arg: "<<toString(obj)<<std::endl;
	if(proc->type != PROC){
		std::cout<<toString(proc)<<" Not a procedure!"<<std::endl;
		return nil;
	}
	return proc->proc(obj);
}
