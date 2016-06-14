/*
 * Errors.cpp
 *
 *  Created on: Jul 21, 2015
 *      Author: msalar
 */

#include "Errors.h"

Errors::Errors() {
	// TODO Auto-generated constructor stub

}

Errors::~Errors() {
	// TODO Auto-generated destructor stub
}

void Errors::fatalError(std::string errorString,SDL_Window* window)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
							 "Fatal error! Application halted",
							 errorString.c_str(),
							 window);
	SDL_Quit(); // Call this function from anywhere, and you will close the SDL subsystems
	exit(0);

}
