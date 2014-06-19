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

#include "loli_types.h"

#include <string>

enum loliNodeType {
	NODE,
	LEAF
};

struct loliNode {
	loliNodeType	type;
	loliNode*	parent;
	loliObj*	obj;
	loliNode*	child;

	loliNode(loliObj* o){
		obj = o;
	}
};

extern loliNode* nilNode;

extern loliNode* toTree(loliObj* exp, loliNode* parent);
extern loliNode* toTree(loliObj* exp);
extern std::string nodeToString(loliNode* tree);

#endif
