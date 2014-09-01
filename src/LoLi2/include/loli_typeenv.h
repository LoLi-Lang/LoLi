/*
 * =====================================================================================
 *
 *       Filename:  loli_typeenv.h
 *
 *    Description:  Type Env of LoLi
 *
 *        Version:  1.0
 *        Created:  08/30/2014 06:57:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_TYPEENV_
#define __LOLI_TYPEENV_

#include "loli_obj.h"
#include "loli_util.h"
#include "loli_typeclass.h"

#define MAX_TYPES 8192

class typeEntry {
	public:
		loliSym* 	id;
		loliTypeClass* 	type;

		typeEntry(){}

		typeEntry(loliTypeClass* tp){
			id = SYM(tp->identifier);
			type = tp;
		}

		typeEntry(loliObj* i, loliTypeClass* tp){
			id = lsym(i);
			type = tp;
		}
};

class typeEnv {
	public:
		typeEntry 	types[MAX_TYPES];
		int 		count = 0;

		typeEnv(){
			count = 0;
		}

		bool isEmpty(){
			return count == 0;
		}

		bool isFull(){
			return count == MAX_TYPES;
		}

		typeEntry* queryType(loliObj* id){
			for(int i = 0; i < count; i++){
				if((&types[i])->id == lsym(id)){
					return &types[i];
				}
			}
			return NULL;
		}

		void addType(typeEntry* type){
			if(isFull()){
				loli_err("Type Space Overflow!");
				return;
			}
            if(queryType(type->id)){
                loli_err("Type Already Exists!");
            }
			types[++count] = *type;
		}

		void removeType(loliObj* id){
			if(!queryType(id)){
				for(int i = 0; i < count; i++){
					if((&types[i])->id == lsym(id)){
						for(int j = i; j < count; j++){
							types[j] = types[j + 1];
						}
						return;
					}
				}
            }
			loli_err("Type: " + id->toString() + " not found!");
		}

        void overrideType(typeEntry* type){
            if(queryType(type->id)){
                loli_err("Type cannot be overriden!");
                return;
            }else{
                for(int i = 0; i < count ; i++){
                    if((&types[i])->id == type->id){
                        types[i] = *type;
                        return;
                    }
                }
            }
        }
};

#endif
