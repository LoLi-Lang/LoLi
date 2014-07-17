/*
 * =====================================================================================
 *
 *       Filename:  loli_parser.h
 *
 *    Description:  Parser of LoLi
 *
 *        Version:  1.0
 *        Created:  07/17/2014 11:12:19 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_PARSER_
#define __LOLI_PARSER_

#include <string>
#include "loli_obj.h"

extern loliObj* parse_string(std::string str);
extern loliObj* parse_list(std::string str);

#endif
