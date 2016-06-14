/*
 * Sprite.h
 *
 *  Created on: Jul 21, 2015
 *      Author: msalar
 */

#ifndef SPRITE_H_
#define SPRITE_H_
#include <GL/glew.h>
#include "GLTexture.h"

#include <string>

//A 2D quad that can be rendered to the screen
class Sprite
{
public:
    Sprite();
    ~Sprite();

    void init(float x, float y, float width, float height,std::string textrePath);

    void draw();

private:
    float _x;
    float _y;
    float _width;
    float _height;
    GLuint _vboID;
    GLTexture _texture;

};



#endif /* SPRITE_H_ */
