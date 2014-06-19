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

#include "header/loli.h"
#include "header/loli_gc.h"

#include <string>

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

loliNode* nilNode = new (UseGC)loliNode(nil);

loliNode* toTree(loliObj* exp, loliNode* parent){
	if(nilp(exp)){
		loliNode* tmpn = nilNode;
		tmpn->type = LEAF;
		tmpn->parent = parent;
		tmpn->child = nilNode;
		return tmpn;
	}
	loliNode* tmp = new (UseGC) loliNode(head(exp));
	tmp->type = NODE;
	tmp->parent = parent;
	tmp->child = toTree(tail(exp), tmp);
	return tmp;
}

loliNode* toTree(loliObj* exp){
	return toTree(exp, nilNode);
}

std::string nodeToString(loliNode* tree){
	if(tree->type == LEAF){
		return "LEAF";
	}
	return "node: " + toString(tree->obj) + " child:\n" + nodeToString(tree->child);
}
