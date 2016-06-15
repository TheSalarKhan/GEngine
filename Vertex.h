/*
 * Vertex.h
 *
 *  Created on: Aug 2, 2015
 *      Author: msalar
 */

#ifndef VERTEX_H_
#define VERTEX_H_

namespace Engine {

/**
 * This struct will encapsulate per vertex data.
 * Considerations:
 * 1) Since this data will be uploaded to the GPU. It must be as short as possible
 * 2) The size of this struct in bytes must be a multiple of four, else some alignment issues
 * might arise.
 */

struct Position {
	float x;
	float y;
};
struct Color {
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
};

struct UV {
	float u;
	float v;
};

struct Vertex {
	/* This is old school
	float position[2]; // 4 * 2 = 8 bytes
	GLubyte color[4]; // 1 * 4 = 4 bytes : 8+4 = 12 bytes (Aligned) */

	//This is how we do it B-)
	Position position;
	Color color;

	//Texture UV co-ordinates
	UV uv;

	void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}

	void setUV(float u,float v) {
		uv.u =u;
		uv.v =v;
	}

	void setPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}
};

}



#endif /* VERTEX_H_ */
