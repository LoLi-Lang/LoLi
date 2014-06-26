/*
 * =====================================================================================
 *
 *       Filename:  loli_ast.h
 *
 *    Description:  AST of LoLi
 *
 *        Version:  1.0
 *        Created:  06/27/2014 05:56:42 AM
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

#include <string>

#include "loli_obj.h"

enum nodeType{
	NODE,
	LEAF
};

struct loliNode{
	loliNode* parent;
	loliObj* value;
	loliNode* child;
	nodeType type;

	loliNode(){}

	loliNode(nodeType ty){
		type = ty;
		parent = NULL;
		child = NULL;
	}
};

extern loliNode* obj_to_tree(loliObj* exp);
extern loliNode* obj_to_tree(loliObj* exp, loliNode* p);

extern std::string toString(loliNode* tree);

#endif
