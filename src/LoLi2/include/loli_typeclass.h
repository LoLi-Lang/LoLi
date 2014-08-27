/*
 * =====================================================================================
 *
 *       Filename:  loli_typeclass.h
 *
 *    Description:  Typeclass of LoLi
 *
 *        Version:  1.0
 *        Created:  08/26/2014 06:32:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_TYPECLASS_
#define __LOLI_TYPECLASS_

#include "loli_obj.h"
#include <string>

class loliTypeClass;

extern loliTypeClass* typeOBJ;
extern loliTypeClass* typeNUM;
extern loliTypeClass* typeINT;
extern loliTypeClass* typeFLT;
extern loliTypeClass* typeSYM;
extern loliTypeClass* typeKEY;
extern loliTypeClass* typeCONS;
extern loliTypeClass* typeFN;
extern loliTypeClass* typePROC;
extern loliTypeClass* typeLAMBDA;
extern loliTypeClass* typeCHAR;
extern loliTypeClass* typeSTRING;
extern loliTypeClass* typeBOOL;

class loliTypeClass {
	public:
	loliTypeClass * parentType = typeOBJ;
	std::string identifier;

	std::string toString(){
		return identifier;
	}
	//Contructures:
	loliTypeClass(){
		this->parentType = NULL;
		this->identifier = "";
	}

	loliTypeClass(std::string id){
		this->parentType = NULL;
		this->identifier = id;
	}

	loliTypeClass(loliTypeClass* type, std::string id){
		this->parentType = type;
		this->identifier = id;
	}

	bool operator<=(loliTypeClass* o){
		if(o==typeOBJ){
			return true;
		}else{
			loliTypeClass* tmp = this;
			while(tmp != typeOBJ){
				if(tmp == o){
					delete tmp;
					return true;
				}else{
					tmp = tmp->parentType;
				}
			}
			delete tmp;
			return false;
		}
	}

	~loliTypeClass();
};


#endif
