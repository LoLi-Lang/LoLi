/*
 * =====================================================================================
 *
 *       Filename:  loli_file.cpp
 *
 *    Description:  File Reader of LoLi
 *
 *        Version:  1.0
 *        Created:  06/04/2014 07:32:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <fstream>
#include <string>

#include "header/loli.h"

bool readFile(std::string fileName, loliObj* env){
	std::ifstream file(fileName);
	if(!file){
		std::cout<<"Fail to read file!"<<std::endl;
		return false;
	}
	while(file){
		std::string input = readPaired(0, false, file);
		if(input[0] == '\0'){
			std::cout<<"\nEOF"<<std::endl;
			return true;
		}
		std::cout<<toString(eval(parse(input), env))<<std::endl;
	}
	std::cout<<"\nEOF"<<std::endl;
	file.close();
	return true;
}
