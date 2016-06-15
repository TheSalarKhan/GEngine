/*
 * IOManager.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: msalar
 */

#include "IOManager.h"

#include <fstream>

namespace Engine {

bool IOManager::readFileToBuffer(std::string& filePath,std::vector<unsigned char>& buffer) {
	std::ifstream file(filePath,std::ios::binary);
	if(file.fail()) {
		perror(filePath.c_str());
		return false;
	}

	//put the cursor to the end
	file.seekg(0,std::ios::end);

	//to get the file size
	//and then return the cursor to the beginning
	int fileSize = file.tellg();
	file.seekg(0,std::ios::beg);

	//Just to be safe and not include any file header bytes
	fileSize -= file.tellg();

	//resize the buffer
	buffer.resize(fileSize);

	file.read((char *)&(buffer[0]), // although our data is in unsigned char, we pretend that it is char while reading
			fileSize);

	file.close();

	return true;
}

}
