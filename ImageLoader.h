/*
 * ImageLoader.h
 *
 *  Created on: Aug 3, 2015
 *      Author: msalar
 */

#ifndef IMAGELOADER_H_
#define IMAGELOADER_H_

#include "GLTexture.h"
#include <string>
/**
 * This is a static class
 */
class ImageLoader {
public:
	static GLTexture loadPNG(std::string filePath);

};

#endif /* IMAGELOADER_H_ */
