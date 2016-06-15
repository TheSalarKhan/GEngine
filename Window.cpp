/*
 * Window.cpp
 *
 *  Created on: Jun 15, 2016
 *      Author: salar
 */

#include "Window.h"


namespace Engine {
Window::Window() {
	// TODO Auto-generated constructor stub

}

Window::~Window() {
	// TODO Auto-generated destructor stub
}


int Window::create(std::string windowName,int screenWidth,int screenHeight, unsigned int currentFlags) {

	Uint32 flags = SDL_WINDOW_OPENGL;

	if(currentFlags & INVISIBLE) {
		flags |= SDL_WINDOW_HIDDEN;
	}

	if(currentFlags & 	FULLSCREEN) {
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	}


	if(currentFlags & BORDERLESS) {
		flags |= SDL_WINDOW_BORDERLESS;
	}



	//Initialize window
	_sdlWindow = SDL_CreateWindow(
				windowName.c_str(), // Title of the window
				SDL_WINDOWPOS_CENTERED, // x position of the window
				SDL_WINDOWPOS_CENTERED, // y position of the window
				screenWidth, // width in pixels
				screenHeight, // height " "
				flags); // Some FLAG, but here's where we tell that we will be doing some OpenGL
		if(_sdlWindow == nullptr) {
			Errors::fatalError("SDL Window could not be initialized",NULL);
		}

		//Initialize SDL_GL context
		SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
		if(glContext == nullptr) {
			Errors::fatalError("SDL_GL context could not be created",_sdlWindow);
		}

		//Initialize GLEW
		GLenum error = glewInit();
		if(error != GLEW_OK) {
			Errors::fatalError("Failed to initialize GLEW", _sdlWindow);
		}

		//Enable Vertical Sync
		SDL_GL_SetSwapInterval(1);

		std::printf("*** OPEN GL VERSION *** %s\n",glGetString(GL_VERSION));

		//set clear color
		glClearColor(0.0f,0.0f,1.0f,0.0f);

}


void Window::swapBuffer() {
	SDL_GL_SwapWindow(_sdlWindow); // Swap the buffer for the window now
}
}
