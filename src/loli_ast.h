/*
 * =====================================================================================
 *
 *       Filename:  loli_ast.h
 *
 *    Description:  AST of LoLi
 *
 *        Version:  1.0
 *        Created:  04/14/2014 01:38:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_AST_
#define __LOLI_AST_

#include <vector>

#include "loli_types.h"
#include "loli_symbols.h"

struct node {

	typedef std::vector<node> nodeLst;

	loliObj*	value;
	node* 		parent;
	nodeLst		child;


	node(loliObj* v) : value (v) {}

	node(loliObj* v, nodeLst c) : value (v), child (c) {}

	node(loliObj* v, nodeLst c, node* p) : value (v), child (c), parent (p) {}

	node() : value (nil) {}
};

extern node* NIL;

#endif
