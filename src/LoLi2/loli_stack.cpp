/*
 * =====================================================================================
 *
 *       Filename:  loli_stack.cpp
 *
 *    Description:  Stack of LoLi
 *
 *        Version:  1.0
 *        Created:  06/26/2014 06:31:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>

#include "include/loli_obj.h"
#include "include/loli_stack.h"
#include "include/loli_util.h"

loliStack global_stack;

std::string stack_to_string(loliStack stack){
	std::string tmp = "";
	for(int i = 0 ; i < stack.obj_in_stack; i++){
		tmp = tmp + "Stack [" + std::to_string(i) + "]: " + (&stack.stack[i])->toString() + "\n";
	}
	return tmp;
}
