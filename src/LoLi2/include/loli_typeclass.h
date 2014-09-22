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
#include <iostream>
#include <typeinfo>

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
	std::string identifier = "";
    std::type_info ti;

	const std::string toString(){
		return identifier;
	}
	//Contructures:
	loliTypeClass(){
		this->parentType = typeOBJ;
		this->identifier = "";
	}

	loliTypeClass(std::string id){
		this->parentType = typeOBJ;
		this->identifier = id;
	}

	loliTypeClass(loliTypeClass* type, std::string id){
		this->parentType = type;
		this->identifier = id;
	}

	bool isFrom(loliTypeClass* o){
        //when typeA <= typeB, typeA is an inheritor of typeB, e.g. typeINT <= typeNUM
        std::cout<<this->toString()<<"\t"<<o->toString()<<std::endl;
        if(this==typeOBJ && o!=typeOBJ){
            return false;
        }
        if(o==typeOBJ){
            return true;
        }else{
            if(o == this){
                return true;
            }else{
                return this->parentType->isFrom(o);
            }
        }
    }

    ~loliTypeClass(){}
};


#endif
