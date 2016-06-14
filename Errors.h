/*
 * Errors.h
 *
 *  Created on: Jul 21, 2015
 *      Author: msalar
 */

#ifndef ERRORS_H_
#define ERRORS_H_

#include <cstdlib>
#include <string>
#include <SDL2/SDL.h>

class Errors {
public:
	Errors();
	virtual ~Errors();
	static void fatalError(std::string errorString,SDL_Window* window);
};

#endif /* ERRORS_H_ */
