/*
 * =====================================================================================
 *
 *       Filename:  loli_ast.cpp
 *
 *    Description:  AST of LoLi
 *
 *        Version:  1.0
 *        Created:  06/27/2014 05:55:47 AM
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
#include "include/loli_ast.h"

#include "../header/loli_gc.h"

loliNode* obj_to_tree(loliObj* exp, loliNode* p);

loliNode* obj_to_tree(loliObj* exp){
	if(exp->type != CONS){
		loliNode* tmp = new (UseGC) loliNode(LEAF);
		tmp->value = exp;
		return tmp;
	}else{
		loliNode* tmp = new (UseGC) loliNode(NODE);
		tmp->value = head(exp);
		tmp->child = obj_to_tree(tail(exp), tmp);
		return tmp;
	}
}

loliNode* obj_to_tree(loliObj* exp, loliNode* p){
	if(exp->type != CONS){
		loliNode* tmp = new (UseGC) loliNode(LEAF);
		tmp->value = exp;
		tmp->parent = p;
		return tmp;
	}else{
		loliNode* tmp = new (UseGC) loliNode(NODE);
		tmp->value = head(exp);
		tmp->parent = p;
		tmp->child = obj_to_tree(tail(exp), tmp);
		return tmp;
	}
}

std::string toString(loliNode* tree){
	if(tree->type == NODE){
		return toString(tree->value) + " |-> " + toString(tree->child);
	}else{
		return toString(tree->value) + " <| END\n";
	}
}
