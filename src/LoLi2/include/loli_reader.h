/*
 * =====================================================================================
 *
 *       Filename:  loli_reader.h
 *
 *    Description:  Reader of LoLi
 *
 *        Version:  1.0
 *        Created:  06/27/2014 04:11:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_READER_
#define __LOLI_READER_

#include <string>
#include <fstream>

extern std::string read_pair(int i, bool quote);
extern std::string read_pair();
extern std::string read_pair(int i, bool quote, std::ifstream &stream);

#endif
