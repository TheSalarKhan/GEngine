/*
 * ResourceManager.h
 *
 *  Created on: Aug 6, 2015
 *      Author: msalar
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "TextureCache.h"
#include <string>
/**
 * A static class to manage resources like textures etc. It Implements simple caching
 */
class ResourceManager {
public:
	static GLTexture getTexture(std::string texturePath);
private:
	//Remember that you need to declare the static variables twice once in the .h  file
	// and once in the .cpp file.
	static TextureCache _textureCache;
};

#endif /* RESOURCEMANAGER_H_ */
