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

#include <string>

extern enum loliType;
extern struct loliObj;

//Constructors
extern loliObj* to_int(long long n);
extern loliObj* to_flt(long double n);
extern loliObj* to_sym(std::string n);
extern loliObj* c_cons(loliObj* hd, loliObj* tl);
extern loliObj* c_proc(loliProc* pr);
extern loliObj* to_string(std::string str);
extern loliObj* to_char(char ch);

#endif
