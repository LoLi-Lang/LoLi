/*
 * =====================================================================================
 *
 *       Filename:  loli_ast.cpp
 *
 *    Description:  Abstract Syntax Tree of LoLi
 *
 *        Version:  1.0
 *        Created:  04/14/2014 01:34:12 AM *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"
#include "loli_list.h"
#include "loli_ast.h"
#include "loli_gc.h"

/* 
 * LoLi-AST Rule:
 * Parent Node must be Verb (Function / Lambda Expression)
 * Children Node must be Noun that the Verb can take (SYM / INT / FLT / Etc.)
 * E.g.:
 * 		V
 * 	       / \
 * 	      V   V
 * 	     /   / \
 * 	    N    N  N
 *      (V (V N) (V N N))
 */


bool isEnd(loliObj* tree){
	if(nilp(tree->tail)){
		return true;
	}
	return false;
}


