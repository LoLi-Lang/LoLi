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

#ifndef __LOLI_STACK_
#define __LOLI_STACK_

#include "loli_obj.h"
#include "loli_util.h"

#define STACK_SIZE 100

struct loliStack{
	loliObj stack[STACK_SIZE];
	int obj_in_stack;

	loliStack(){
		obj_in_stack = 0;
	}

	bool isEmpty(){
		return 0 == obj_in_stack;
	}

	bool isFull(){
		return obj_in_stack == STACK_SIZE;
	}

	void push_obj(loliObj* o){
		if(isFull()){
			loli_err("Stack Overflow");
			return;
		}
		stack[obj_in_stack++] = *o;
	}
	
	loliObj* pop_obj(){
		if(isEmpty()){
			loli_err("Stack Underflow");
			return NULL;
		}
		return &stack[obj_in_stack--];
	}
};

extern loliStack global_stack;
extern std::string stack_to_string(loliStack stack);

#endif
