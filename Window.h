/*
 * Window.h
 *
 *  Created on: Jun 15, 2016
 *      Author: salar
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include "Errors.h"
namespace Engine {

enum WindowFlags {INVISIBLE=0x1, FULLSCREEN=0x2, BORDERLESS=0x4};

class Window {
public:
	Window();
	virtual ~Window();

	int create(std::string windowName,int screenWidth,int screenHeight, unsigned int currentFlags);

	int getScreenWidth() { return _screenWidth;}
	int getScreenHeight() { return _screenHeight;}


	void swapBuffer();
private:
	SDL_Window* _sdlWindow;


	int _screenWidth;
	int _screenHeight;
};

}

#endif /* WINDOW_H_ */
