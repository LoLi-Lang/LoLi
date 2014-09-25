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
#include <typeinfo>

using namespace std;

loliTypeClass* typeOBJ = new loliTypeClass("OBJ", typeid(loliObj*).name());
loliTypeClass* typeNUM = new loliTypeClass(typeOBJ, "NUM", typeid(loliNum*).name());
loliTypeClass* typeINT = new loliTypeClass(typeNUM, "INT", typeid(loliInt*).name());
loliTypeClass* typeFLT = new loliTypeClass(typeNUM, "FLT", typeid(loliFlt*).name());
loliTypeClass* typeSYM = new loliTypeClass(typeOBJ, "SYM", typeid(loliSym*).name());
loliTypeClass* typeKEY = new loliTypeClass(typeOBJ, "KEY", typeid(loliKey*).name());
loliTypeClass* typeCONS = new loliTypeClass(typeOBJ, "CONS", typeid(loliCons*).name());
loliTypeClass* typeFN = new loliTypeClass(typeOBJ, "FUNC", typeid(loliFunction*).name());
loliTypeClass* typeLAMBDA = new loliTypeClass(typeFN, "LAMBDA", typeid(loliLambda*).name());
loliTypeClass* typePROC = new loliTypeClass(typeFN, "PROC", typeid(loliPrim*).name());
loliTypeClass* typeCHAR = new loliTypeClass(typeOBJ, "CHAR", typeid(loliChar*).name());
loliTypeClass* typeSTRING = new loliTypeClass(typeOBJ, "STRING", typeid(loliString*).name());
loliTypeClass* typeBOOL = new loliTypeClass(typeKEY, "BOOL", typeid(loliBool*).name());
