/*
 * =====================================================================================
 *
 *       Filename:  loli_container.h
 *
 *    Description:  Containers of LoLi
 *
 *        Version:  1.0
 *        Created:  08/26/2014 09:49:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_CONTAINER_
#define __LOLI_CONTAINER_

#include "loli_obj.h"

class loliCons {
	loliObj* hd;
	loliObj* tl;

	loliObj* head(){
		return this->hd;
	}

	loliObj* tail(){
		return this->tl;
	}

	loliCons(){
		this->hd = nil;
		this->tl = nil;
	}

	loliCons(loliObj* o){
		this->hd = o;
		this->tl = nil;
	}

	loliCons(loliObj* h, loliObj* tl){
		this->hd = h;
		this->tl = tl;
	}
};

class loliLambda {
	loliObj* arg; //Arg List
	loliObj* rtype; //Return type
	loliObj* env;
	loliObj* exp;
};

class loliProc {
	loliProc* proc;
	loliObj* rtype;
	loliObj* itype;
};

#endif
