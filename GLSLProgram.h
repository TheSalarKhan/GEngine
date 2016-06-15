/*
 * GLSLProgram.h
 *
 *  Created on: Jul 21, 2015
 *      Author: msalar
 */

#ifndef GLSLPROGRAM_H_
#define GLSLPROGRAM_H_
#include <string>
#include <GL/glew.h>
#include <fstream>
#include <vector>
#include <iostream>
#include "Errors.h"

namespace Engine {
class GLSLProgram {
public:
	GLSLProgram();
	virtual ~GLSLProgram();

	void compileShaders(const std::string& vertexShaderFile,
			const std::string& fragmentShaderFile);
	void linkShaders();
	void addAttribute(const std::string& attributeName);

	GLint getUniformResourceLocation(const std::string& uniformName);

	void use();
	void unUse();
private:
	GLuint _programID;
	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
	int _numAttributes;

	void compileShader(const std::string filePath, GLuint id);
};

}
#endif /* GLSLPROGRAM_H_ */
