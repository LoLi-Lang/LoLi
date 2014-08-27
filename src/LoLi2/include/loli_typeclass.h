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

template <class T>
class loliTypeClass {
	loliTypeClass * parentType;
	std::string identifier;
	T value;

	//Contructures:
	loliTypeClass(){
		this->value = NULL;
		this->parentType = NULL;
		this->identifier = "";
	}

	loliTypeClass(T value, std::string id){
		this->value = value;
		this->parentType = NULL;
		this->identifier = id;
	}

	loliTypeClass(loliTypeClass* type, std::string id){
		this->value = NULL;
		this->parentType = type;
		this->identifier = id;
	}

	loliTypeClass(T value, loliTypeClass* p, std::string id){
		this->value = value;
		this->parentType = p;
		this->identifier = id;
	}

	~loliTypeClass();
};

#endif
