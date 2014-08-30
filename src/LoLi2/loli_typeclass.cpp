/*
 * =====================================================================================
 *
 *       Filename:  loli_typeclass.cpp
 *
 *    Description:  Typeclass of LoLi
 *
 *        Version:  1.0
 *        Created:  08/30/2014 03:26:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "include/loli_env.h"
#include "include/loli_typeclass.h"

loliTypeClass* typeOBJ = new loliTypeClass("OBJ");
loliTypeClass* typeNUM = new loliTypeClass(typeOBJ, "NUM");
loliTypeClass* typeINT = new loliTypeClass(typeNUM, "INT");
loliTypeClass* typeFLT = new loliTypeClass(typeNUM, "FLT");
loliTypeClass* typeSYM = new loliTypeClass(typeOBJ, "SYM");
loliTypeClass* typeKEY = new loliTypeClass(typeOBJ, "KEY");
loliTypeClass* typeCONS = new loliTypeClass(typeOBJ, "CONS");
loliTypeClass* typeFN = new loliTypeClass(typeOBJ, "FUNC");
loliTypeClass* typeLAMBDA = new loliTypeClass(typeFN, "LAMBDA");
loliTypeClass* typePROC = new loliTypeClass(typeFN, "PROC");
loliTypeClass* typeCHAR = new loliTypeClass(typeOBJ, "CHAR");
loliTypeClass* typeSTRING = new loliTypeClass(typeOBJ, "STRING");
loliTypeClass* typeBOOL = new loliTypeClass(typeKEY, "BOOL");
