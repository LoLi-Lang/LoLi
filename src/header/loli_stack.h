/*
 * =====================================================================================
 *
 *       Filename:  loli_stack.h
 *
 *    Description:  Stack of LoLi
 *
 *        Version:  1.0
 *        Created:  06/19/2014 11:29:43 AM
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

#include "loli.h"

#include <vector>

extern loliObj loli_stack[];
extern int obj_in_stack;

extern bool isStackEmpty();
extern bool isStackFull();

extern void printStack();

extern loliObj* pop();
extern void push(loliObj* obj);

#endif
