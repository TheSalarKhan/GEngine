/*
 * TextureCache.cpp
 *
 *  Created on: Aug 6, 2015
 *      Author: msalar
 */

#include "TextureCache.h"
#include "ImageLoader.h"

namespace Engine {

TextureCache::TextureCache() {
	// TODO Auto-generated constructor stub

}

TextureCache::~TextureCache() {
	// TODO Auto-generated destructor stub
}


GLTexture TextureCache::getTexture(std::string texturePath) {
	//Scan the map, if the texture is found return the texture, else crash the game with a fatal error.

	//std::map<std::string,GLTexture>::iterator mit = _textureMap.find(texturePath); << Instead of having a long name
	//we can use auto keyword

	//mit for map iterator

	/*
	 * The auto keyword is used to auto detect the type of the L value by the type returned from the R value.
	 */

	//Lookup the texture if it is in the map
	auto mit = _textureMap.find(texturePath);

	//If we did not find the texture
	if(mit == _textureMap.end()) {
		// Load the new texture from IO
		GLTexture newTexture = ImageLoader::loadPNG(texturePath); // Load the texture

		//There are two ways of inserting things in a map
		//1)
//		std::pair<std::string,GLTexture> newPair(texturePath,newTexture);
//		_textureMap.insert(newPair);
		//2) This is more concise
		_textureMap.insert(make_pair(texturePath,newTexture));


		return newTexture;
	}

	//mit is actually pointing to a pair, mit->first will give us the key and mit->second will give us the value.
	return mit->second;
}

}
