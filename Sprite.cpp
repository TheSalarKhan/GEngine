#include "Sprite.h"

#include "Vertex.h"
#include <cstddef>
#include "ResourceManager.h"


namespace Engine {
Sprite::Sprite() : _x(0),_y(0),_width(0),_height(0),_vboID(0)
{
    //Always initialize your buffer IDs to 0
}


Sprite::~Sprite()
{
    //Always remember to delete your buffers when
    //you are done!
    if (_vboID != 0) {
        glDeleteBuffers(1, &_vboID);
    }
}

//Initializes the sprite VBO. x, y, width, and height are
//in the normalized device coordinate space. so, [-1, 1]
void Sprite::init(float x, float y, float width, float height,std::string texturePath) {
    //Set up our private vars
    _x = x;
    _y = y;
    _width = width;
    _height = height;

    //Load the texture,using the texture cache
    _texture = ResourceManager::getTexture(texturePath);

    //Generate the buffer if it hasn't already been generated
    if (_vboID == 0) {
        glGenBuffers(1, &_vboID);
    }

    //This array will hold our vertex data.
    //We need 6 vertices, and each vertex has 2
    //floats for X and Y
    Vertex vertexData[6];
//    Vertex vertices[6];

    //First Triangle
    vertexData[0].setPosition(x + width,y + height);
    vertexData[0].setUV(1.0f,1.0f);

    vertexData[1].setPosition(x ,y + height);
    vertexData[1].setUV(0.0f,1.0f);

    vertexData[2].setPosition(x ,y );
    vertexData[2].setUV(0.0f,0.0f);


    //Second Triangle
    vertexData[3].setPosition(x ,y );
    vertexData[3].setUV(0.0f,0.0f);

    vertexData[4].setPosition(x + width,y);
    vertexData[4].setUV(1.0f,0.0f);

    vertexData[5].setPosition(x + width,y + height);
    vertexData[5].setUV(1.0f,1.0f);


    for(int i=0;i<6;i++) {
    	vertexData[i].setColor(255,0,255,255);
    }


    vertexData[1].setColor(255,0,0,255);

    vertexData[5].setColor(0,255,0,255);


    //Tell opengl to bind our vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    //Upload the data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    //Unbind the buffer (optional)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//Draws the sprite to the screen
void Sprite::draw() {

	//bind the texture
	glBindTexture(GL_TEXTURE_2D,_texture.id);
    //bind the buffer object
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);

    //Tell opengl that we want to use the first
    //attribute array. We only need one array right
    //now since we are only using position.
    glEnableVertexAttribArray(0);
//    glEnableClientState(GL_VERTEX_ARRAY);

    //Point opengl to the data in our VBO. We will learn
    //more on this later
    //glVertexAttribPointer(attrib,units,type,normalize?,stride,offset)
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex,position));
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void *)offsetof(Vertex,color));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex,uv));
//    glVertexPointer(2, GL_FLOAT, 0, 0);

    //Draw the 6 vertices to the screen
    glDrawArrays(GL_TRIANGLES, 0, 6);

    //Disable the vertex attrib array. This is not optional.
    glDisableVertexAttribArray(0);
//    glDisableClientState(GL_VERTEX_ARRAY);

    //Unbind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
}
