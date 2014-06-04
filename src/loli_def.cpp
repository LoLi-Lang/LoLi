/*
 * =====================================================================================
 *
 *       Filename:  loli_def.cpp
 *
 *    Description:  Basic define function
 *
 *        Version:  1.0
 *        Created:  06/04/2014 01:48:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

#include "loli.h"

loliObj* prim_def(loliObj* exp){
	std::cout<<"Exp: "<<toString(exp)<<" Env: "<<std::endl;
	top_env = addToEnv(top_env, exp);
	return head(exp);
}
