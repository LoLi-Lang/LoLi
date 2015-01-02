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
#include <typeinfo>
#include <iostream>

//Macros
#define lnum(x) 	((loliNum*)x)
#define lint(x) 	((loliInt*)x)
#define lflt(x)		((loliFlt*)x)
#define lchar(x)	((loliChar*)x)
#define lstr(x) 	((loliString*)x)
#define lcons(x) 	((loliCons*)x)
#define lfunc(x) 	((loliFunction*)x)
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
#define LAMBDA(x, y, z) new loliLambda(x, y, z)

class loliObj;

extern loliObj* nil;
extern loliObj* t;
extern loliObj* quote;

extern loliObj* boolt;
extern loliObj* boolf;

class loliObj {
	public:	
		typedef loliObj* (loliProc)(loliObj*);
		loliTypeClass *type;
		loliObj* 	env;
		virtual std::string toString(){return "";}
		virtual int length(){return 1;}
		virtual loliObj* eval(loliObj* env){
            //For debug:
            std::cout<<type->toString()<<std::endl;
            return this;
        }
		virtual bool equal(loliObj* o){
            return this == o;
        }
        virtual loliTypeClass* getType(){
            return this->type;
        }
		bool nilp(){
			return this->equal(nil);
		}

		loliObj(){
            this->type = typeOBJ;
			env = nil;
		};
};

class loliNum : public loliObj { //Place holder
	public:
		loliTypeClass *type = typeNUM;

		virtual long double getValue(){return 0;}

		int length(){
			return 1;
		}

		loliObj* eval(loliObj* env) override {
            this->type = typeNUM;
            std::cout<<typeid(this).name()<<std::endl;
			return this;
		}
};

class loliInt : public loliNum {
	public:
		long int value;
		loliTypeClass *type = typeINT;

		long double getValue(){
			return this->value;
		}

		std::string toString(){
			return std::to_string(value);
		}

		loliInt(long int n){
            this->type = typeINT;
			value = n;
		}

		loliObj* eval(loliObj* env){
            this->type = typeINT;
            std::cout<<type->toString()<<std::endl;
			return this;
		}

		loliInt(){
			value = 0;
		}

		bool equal(loliObj* o){
            return ((loliInt*)o)->value == this->value;
		}
};

class loliFlt: public loliNum {
	public:
		long double value;
		loliTypeClass *type = typeFLT;

		long double getValue(){
			return this->value;
		}

		std::string toString(){
			return std::to_string(value);
		}

		loliFlt(long double n){
            this->type = typeFLT;
			value = n;
		}

		loliObj* eval(loliObj* env){
            this->type = typeFLT;
            std::cout<<this->getType()->toString()<<std::endl;
			return this;
		}

		loliFlt(){
			value = 0.0;
		}
		bool equal(loliObj* o){
            return ((loliFlt*)o)->value == this->value;
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
            this->type = typeSYM;
			name = v;
		}

		bool equal(loliObj* o){
            return lsym(o)->name == this->name;
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
            this->type = typeKEY;
			name = v;
		}

		bool equal(loliObj* o){
            return ((loliKey*)o)->name == this->name;
        }

		int length(){
			return 1;
		}

		loliObj* eval(loliObj* env) override {
            std::cout<<"Override\n";
            this->type = typeKEY;
            std::cout<<this->getType()->toString()<<std::endl;
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
            this->type = typeCONS;
			hd = nil;
			tl = nil;
		}

		loliCons(loliObj* obj){
            this->type = typeCONS;
			hd = obj;
			tl = nil;
		}

		loliCons(loliObj* hd, loliObj* tl){
            this->type = typeCONS;
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

		bool equal(loliObj* o){
            return (this->hd->equal(((loliCons* )o)->hd)) && (this->tl->equal(((loliCons*)o)->tl));
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
            this->type = typeFN;
            std::cout<<this->type->toString()<<std::endl;
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
            this->type = typePROC;
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
			return "<LAMBDA " + this->arg->toString() + " -> " + this->rtype->toString() + " >";
		}

		loliLambda(){}

		loliLambda(loliObj* r, loliObj* a, loliObj* e){
            this->type = typeLAMBDA;
			this->rtype = r;
			this->arg = a;
			this->exp = e;
		}
};

class loliChar: public loliObj {
	public:
		loliTypeClass *type = typeCHAR;

		char value;

		loliChar(){}

		loliChar(char c){
            this->type = typeCHAR;
			this->value = c;
		}

		std::string toString(){
			return "#\\" + std::to_string(value);
		}

		int length(){
			return 1;
		}

		loliObj* eval(loliObj* env){
            this->type = typeCHAR;
            std::cout<<this->type->toString()<<std::endl;
			return this;
		}
};

class loliString: public loliObj {
	public:
		loliTypeClass *type = typeSTRING;
		std::string value;

		loliString(){}

		loliString(std::string str){
            this->type = typeSTRING;
			this->value = str;
		}

		std::string toString(){
			return value;
		}

		int length(){
			return value.length();
		}

		loliObj* eval(loliObj* env){
            this->type = typeSTRING;
            std::cout<<this->type->toString()<<std::endl;
			return this;
		}
};

class loliBool: public loliKey {
	public:
		loliTypeClass *type = typeBOOL;
		bool value = false;

		loliBool(){}

		loliBool(bool b){
            this->type = typeBOOL;
			this->value = b;
			if(b){
				this->name = "true";
			}else{
				this->name = "false";
			}
		}
};

#endif
