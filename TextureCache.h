/*
 * TextureCache.h
 *
 *  Created on: Aug 6, 2015
 *      Author: msalar
 */

#ifndef TEXTURECACHE_H_
#define TEXTURECACHE_H_


#include <map>

#include "GLTexture.h"


namespace Engine {
class TextureCache {
public:
	TextureCache();
	virtual ~TextureCache();

	GLTexture getTexture(std::string texturePath);

private:
	std::map<std::string,GLTexture> _textureMap;
};

}

#endif /* TEXTURECACHE_H_ */
