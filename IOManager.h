/*
 * IOManager.h
 *
 *  Created on: Aug 3, 2015
 *      Author: msalar
 */

#ifndef IOMANAGER_H_
#define IOMANAGER_H_

#include <vector>
#include <string>

/**
 * This is just going to be a static class, so there is no need to instantiate it
 */
class IOManager {
public:
	static bool readFileToBuffer(std::string& path,std::vector<unsigned char>& buffer);
};

#endif /* IOMANAGER_H_ */
