/*
 * =====================================================================================
 *
 *       Filename:  loli_symbols.cpp
 *
 *    Description:  The Internal Symbols of LoLi
 *
 *        Version:  1.0
 *        Created:  04/05/2014 01:23:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "loli_types.h"

loliObj nil = mksym("nil");
loliObj t = mksym("t");

bool nilp(loliObj o){
	if(o.type == SYM && o.value == "nil"){
		return true;
	}
	return false;
}
