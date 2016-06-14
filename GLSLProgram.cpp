/*
 * GLSLProgram.cpp
 *
 *  Created on: Jul 21, 2015
 *      Author: msalar
 */

#include "GLSLProgram.h"


GLSLProgram::GLSLProgram() : _programID(0) , _vertexShaderID(0), _fragmentShaderID(0), _numAttributes(0) {
}

GLSLProgram::~GLSLProgram() {
}

/**
 * This method compiles the shaders for our Sprite.
 */
void GLSLProgram::compileShaders(const std::string& vertexShaderFile,const std::string& fragmentShaderFile) {
	//Get the program object ID
	//Before compiling any shaders we must always get the program ID
		_programID = glCreateProgram();

	//Get a vertex shader ID
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if(_vertexShaderID == 0)
		Errors::fatalError("Could not create vertex shader.",NULL);

	//Get a fragment shader ID
	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		if(_fragmentShaderID == 0)
			Errors::fatalError("Could not create fragment shader.",NULL);

		//Compile the vertex shader
		compileShader(vertexShaderFile,_vertexShaderID);

		//Compile the fragment shader
		compileShader(fragmentShaderFile,_fragmentShaderID);
}

void GLSLProgram::compileShader(std::string filePath, GLuint shaderID) {
	//Open the file containing shader code
	std::ifstream shaderFile(filePath);
	if(shaderFile.fail()) {
		perror(filePath.c_str());
		Errors::fatalError("Failed to open vertex shader file",NULL);
	}

	//Read the contents of the file line by line
	std::string vertexFileContents = "";
	std::string line;
	while(std::getline(shaderFile,line)) {
		vertexFileContents += line + "\n";
	}
	shaderFile.close();

	// Compile the shader
	const char *hack = vertexFileContents.c_str();
	glShaderSource(shaderID,
			1, // How many sources
			&hack, // pointer to array of shader strings
			nullptr); // array of sizes of each string
	glCompileShader(shaderID);

	//Now we check for the status of the compilation
	GLint status = 0;
	glGetShaderiv(shaderID,GL_COMPILE_STATUS,&status);
	if(status == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(shaderID,GL_INFO_LOG_LENGTH, &maxLength);
		//The length also includes the null character
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(shaderID,maxLength,&maxLength,&errorLog[0]);
		//Use the info now.

		//Exit with failure
		glDeleteShader(shaderID); // Don't leak the shader
		std::printf("ERROR: %s\n",&errorLog[0]);
		Errors::fatalError("Vertex shader failed to compile read the console for error details.",nullptr);

		return;
	}
}

void GLSLProgram::addAttribute(const std::string& attributeName) {
	glBindAttribLocation(_programID,_numAttributes,attributeName.c_str());
	_numAttributes++;
}





void GLSLProgram::linkShaders() {
	//Now that the shaders have been compiled as seperate entities
	//Its time to link them into one entity

	//Attach our shaders to our program
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	//Link the program
	glLinkProgram(_programID);

	//Verify the linking
	GLint isLinked = 0;
	glGetProgramiv(_programID,GL_LINK_STATUS,&isLinked);
	if(isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		//The max length includes the null character
		std::vector<char> infoLog(maxLength);
		glGetProgramInfoLog(_programID,maxLength,&maxLength,&infoLog[0]);

		//Don't leak the program
		glDeleteProgram(_programID);
		//Don't leak shaders either
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);

		Errors::fatalError("Failed to link the shaders, read the console for details",NULL);

		std::printf("ERROR: %s\n",&infoLog[0]);

		return;
	}

	//Detach the shaders after a successful link
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}


void GLSLProgram::use() {
	//Load this program on the graphics card
	glUseProgram(_programID);

	for(int i=0; i< _numAttributes;i++) {
		glEnableVertexAttribArray(i);
	}
}
void GLSLProgram::unUse() {
	glUseProgram(0);

	for(int i=0; i< _numAttributes;i++) {
			glDisableVertexAttribArray(i);
	}
}


GLint GLSLProgram::getUniformResourceLocation(const std::string& uniformName) {
	GLint location = glGetUniformLocation(_programID, uniformName.c_str());
	if(location == GL_INVALID_INDEX) {
		Errors::fatalError("Uniform \'"+uniformName+"\' not found in shader",nullptr);
	}

	return location;
}
