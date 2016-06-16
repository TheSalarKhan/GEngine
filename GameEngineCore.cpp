/*
 * GameEngineCore.cpp
 *
 *  Created on: Jun 15, 2016
 *      Author: salar
 */

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "GameEngineCore.h"

namespace Engine {
int init() {
	//Initialize SDL Sub Systems
	SDL_Init(SDL_INIT_EVERYTHING);

	//Enable double buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	return 0;
}

}
