/*
 * =====================================================================================
 *
 *       Filename:  loli_file.h
 *
 *    Description:  File Reader of LoLi
 *
 *        Version:  1.0
 *        Created:  06/04/2014 08:04:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_FILE_
#define __LOLI_FILE_


#include <iostream>
#include <fstream>
#include <string>

#include "loli.h"

extern bool readFile(std::string fileName, loliObj* env);

#endif
