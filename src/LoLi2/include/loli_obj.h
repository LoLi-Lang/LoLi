/*
 * =====================================================================================
 *
 *       Filename:  loli_obj.h
 *
 *    Description:  Object of LoLi
 *
 *        Version:  1.0
 *        Created:  06/26/2014 10:09:32 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_OBJ_
#define __LOLI_OBJ_

#include "loli_typeclass.h"
#include <string>

//Macros
#define lnum(x) 	((loliNum*)x)
#define lint(x) 	((loliInt*)x)
#define lflt(x)		((loliFlt*)x)
#define lchar(x)	((loliChar*)x)
#define lstr(x) 	((loliString*)x)
#define lcons(x) 	((loliCons*)x)
#define lproc(x) 	((loliPrim*)x)
#define llambda(x) 	((loliLambda*)x)
#define lsym(x) 	((loliSym*)x)
#define lkey(x) 	((loliKey*)x)
#define lbool(x) 	((loliBool*)x)

#define INT(x)		new loliInt(x)
#define FLT(x)		new loliFlt(x)
#define SYM(x)		new loliSym(x)
#define KEY(x)		new loliKey(x)
#define CHAR(x)		new loliChar(x)
#define STRING(x)	new loliString(x)
#define sCONS(x)	new loliCons(x) //Single Cons
#define CONS(x, y)	new loliCons(x, y)
#define PROC(x, y, z)	new loliPrim(x, y, z)
#define LAMBDA(x, y, z, w) new loliLambda(x, y, z, w)

class loliObj;

extern loliObj* nil;

class loliObj {
	public:	
		typedef loliObj* (loliProc)(loliObj*);
		loliTypeClass *type = typeOBJ;
		loliObj* 	env;
		virtual std::string toString(){return "";}
		virtual int length(){return 1;}
		virtual loliObj* eval(loliObj* env){return this;}
		virtual bool operator==(loliObj* o){return *this == o;}
		bool operator!=(loliObj* o){
			return !(this==o);
		}
		bool nilp(){
			return this==nil;
		}

		loliObj(){
			env = nil;
		};
};

class loliNum : public loliObj { //Place holder
	public:
		loliTypeClass *type = typeNUM;
		double value;

		int length(){
			return 1;
		}

		loliObj* eval(loliObj* env){
			return this;
		}
};

class loliInt : public loliNum {
	public:
		long int value;
		loliTypeClass *type = typeINT;

		std::string toString(){
			return std::to_string(value);
		}

		loliInt(long int n){
			value = n;
		}

		loliInt(){
			value = 0;
		}

		bool operator==(loliObj* o){
			if(o->type == this->type){
				return ((loliInt*)o)->value == this->value;
			}else{
				return false;
			}
		}
};

class loliFlt: public loliNum {
	public:
		long double value;
		loliTypeClass *type = typeFLT;

		std::string toString(){
			return std::to_string(value);
		}

		loliFlt(long double n){
			value = n;
		}

		loliFlt(){
			value = 0.0;
		}
		bool operator==(loliObj* o){
			if(o->type == this->type){
				return ((loliFlt*)o)->value == this->value;
			}else{
				return false;
			}
		}
};

class loliSym: public loliObj {
	public:
		std::string name = "";
		loliTypeClass *type = typeSYM;

		std::string toString(){
			return name;
		}

		loliSym(){}

		loliSym(std::string v){
			name = v;
		}

		bool operator==(loliObj* o){
			if(o->type == this->type){
				return ((loliSym*)o)->name == this->name;
			}else{
				return false;
			}
		}

		int length(){
			return 1;
		}

		loliObj* eval(loliObj* env);
};

class loliKey: public loliObj {
	public:
		std::string name = "";
		loliTypeClass *type = typeKEY;

		std::string toString(){
			return ":" + name;
		}

		loliKey(){}

		loliKey(std::string v){
			name = v;
		}

		bool operator==(loliObj* o){
			if(o->type == this->type){
				return ((loliKey*)o)->name == this->name;
			}else{
				return false;
			}
		}

		int length(){
			return 1;
		}

		loliObj* eval(loliObj* env){
			return this;
		}
};

class loliCons: public loliObj {
	public:
		loliObj* hd;
		loliObj* tl;
		loliTypeClass *type = typeCONS;

		std::string toString(){
			std::string tmp = "(" + hd->toString();
			if(tl->type != typeCONS){
				return tmp + " . " + tl->toString() + ")";
			}else{
				return tmp + " " + tl->toString() + ")";
			}
			return ""; //Blank
		}

		int length(){
			return 1 + tl->length();
		}

		loliCons(){
			hd = nil;
			tl = nil;
		}

		loliCons(loliObj* obj){
			hd = obj;
			tl = nil;
		}

		loliCons(loliObj* hd, loliObj* tl){
			this->hd = hd;
			this->tl = tl;
		}

		void setHead(loliObj* o){
			hd = o;
		}

		void setTail(loliObj* o){
			tl = o;
		}

		loliObj* head(){
			return hd;
		}

		loliObj* tail(){
			return tl;
		}

		bool operator==(loliObj* o){
			if(o->type == this->type){
				return (this->hd == ((loliCons* )o)->hd) && (this->tl == ((loliCons*)o)->tl);
			}else{
				return false;
			}
		}

		loliObj* eval(loliObj* env);
};

class loliFunction: public loliObj { //Place Holder
	public:
		loliTypeClass *type = typeFN;

		loliObj* rtype;

		int length(){
			return 1;
		}

		loliFunction(){}

		loliObj* eval(loliObj* env){
			return this;
		}
};

class loliPrim: public loliFunction {
	public:
		loliTypeClass *type = typePROC;
		loliObj::loliProc* proc;
		loliObj* itype;

		std::string toString(){
			return "<Procedure " + rtype->toString() + " >";
		}

		loliPrim(){}

		loliPrim(loliObj::loliProc* p, loliObj* r, loliObj* i){
			this->proc = p;
			this->rtype = r;
			this->itype = i;
		}
};

class loliLambda: public loliFunction {
	public: 
		loliTypeClass *type = typeLAMBDA;
		loliObj* arg;
		loliObj* exp;

		std::string toString(){
			return "<LAMBDA " + arg->toString() + " -> " + rtype->toString() + " >";
		}

		loliLambda(){}

		loliLambda(loliObj* rtype, loliObj* arg, loliObj* exp, loliObj* env){
			this->rtype = rtype;
			this->arg = arg;
			this->exp = exp;
			this->env = env;
		}
};

class loliChar: public loliObj {
	public:
		loliTypeClass *type = typeCHAR;

		char value;

		loliChar(){}

		loliChar(char c){
			this->value = c;
		}

		std::string toString(){
			return "#\\" + std::to_string(value);
		}

		int length(){
			return 1;
		}

		loliObj* eval(loliObj* env){
			return this;
		}
};

class loliString: public loliObj {
	public:
		loliTypeClass *type = typeSTRING;
		std::string value;

		loliString(){}

		loliString(std::string str){
			this->value = str;
		}

		std::string toString(){
			return value;
		}

		int length(){
			return value.length();
		}

		loliObj* eval(loliObj* env){
			return this;
		}
};

class loliBool: public loliKey {
	public:
		loliTypeClass *type = typeBOOL;
		bool value = false;

		loliBool(){}

		loliBool(bool b){
			this->value = b;
			if(b){
				this->name = "true";
			}else{
				this->name = "false";
			}
		}
};

extern loliObj* t;
extern loliObj* quote;

extern loliObj* boolt;
extern loliObj* boolf;

#endif
