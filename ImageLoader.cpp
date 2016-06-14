/*
 * ImageLoader.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: msalar
 */

#include "ImageLoader.h"
#include "picopng.h"
#include "Errors.h"
#include "IOManager.h"

GLTexture ImageLoader::loadPNG(std::string filePath) {
	GLTexture texture = {}; // initialize everything to zero
	std::vector<unsigned char> in;
	std::vector<unsigned char> out;

	unsigned long width,height;

	if (IOManager::readFileToBuffer(filePath,in) == false) {
		Errors::fatalError("Failed to load PNG file "+filePath+" to buffer.",nullptr);
	}



	int errorCode = decodePNG(out,width,height,&(in[0]),in.size());

	texture.width = width;
	texture.height = height;

	if(errorCode != 0) { // for a non-zero error code
		Errors::fatalError("picopng's decodePNG failed with error code "+ std::to_string(errorCode), nullptr);
	}


	glGenTextures(1,&(texture.id));

	glBindTexture(GL_TEXTURE_2D, texture.id);

	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,&(out[0]));

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);

	//Unbind the texture
	glBindTexture(GL_TEXTURE_2D, texture.id);

	return texture;
}
