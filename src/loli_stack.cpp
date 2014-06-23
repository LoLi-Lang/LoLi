/*
 * =====================================================================================
 *
 *       Filename:  loli_stack.cpp
 *
 *    Description:  Stack of LoLi
 *
 *        Version:  1.0
 *        Created:  06/19/2014 11:06:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "header/loli.h"
#include "header/loli_gc.h"

#include <iostream>

#define STACKS 100

loliObj loli_stack[STACKS];
int obj_in_stack = 0;

bool isStackEmpty(){
	return obj_in_stack == 0;
}

bool isStackFull(){
	return obj_in_stack == STACKS;
}

void printStack(){
	for(int i = 0; i < obj_in_stack; i++){
		std::cout<<"Stack["<< i + 1 <<"] : " << toString(&loli_stack[i])<<std::endl;
	}
}

loliObj* pop(){
	if(isStackEmpty()){
		std::cout<<"Error: Stack is empty!"<<std::endl;
		return NULL;
	}
	return &loli_stack[--obj_in_stack];
}

void push(loliObj* obj){
	if(isStackFull()){
		std::cout<<"Error: Stack Overflow!"<<std::endl;
		return;
	}
	loli_stack[obj_in_stack++] = *obj;
}

void flushStack(){
	obj_in_stack = 0;
}

void reverseStack(){
	loliObj tmp[STACKS];
	for(int i = obj_in_stack; i > 0; i--){
		tmp[obj_in_stack - i] = loli_stack[i - 1];
	}
	for(int i = 0; i < obj_in_stack; i++){
		loli_stack[i] = tmp[i];
	}
}
