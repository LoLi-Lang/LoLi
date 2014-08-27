/*
 * =====================================================================================
 *
 *       Filename:  loli_obj.cpp
 *
 *    Description:  Object of LoLi
 *
 *        Version:  1.0
 *        Created:  06/25/2014 03:19:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <string>
#include <iostream>
#include <sstream>
#include "../header/loli_gc.h"
#include "include/loli_obj.h"

loliObj* nil = new loliSym("nil");
loliObj* t = new loliSym("t");
loliObj* quote = new loliSym("quote");

loliObj* boolt = new loliBool(true);
loliObj* boolf = new loliBool(false);
