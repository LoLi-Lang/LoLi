/*
 * =====================================================================================
 *
 *       Filename:  loli_ast.cpp
 *
 *    Description:  Abstract Syntax Tree of LoLi
 *
 *        Version:  1.0
 *        Created:  04/14/2014 01:34:12 AM
 *       Revision:  none
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

//GC
#include "gc/include/gc.h"
#include "gc/include/gc_cpp.h"
#include "gc/include/gc_allocator.h"

node* NIL = new (UseGC) node(nil);

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


