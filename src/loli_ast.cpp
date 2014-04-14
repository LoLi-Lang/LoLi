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

node* NIL = new (UseGC) node(nil);


