/*
 * Camera2d.h
 *
 *  Created on: Jun 16, 2016
 *      Author: salar
 */

#ifndef CAMERA2D_H_
#define CAMERA2D_H_
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Engine {

class Camera2d {
public:
	Camera2d();
	virtual ~Camera2d();

	void update();

	void init(int screenWidth,int screenHeight);

	//setters
	void setPosition(const glm::vec2& newPosition) {
		_position = newPosition;
		_needsMatrixUpdate = true;
	}
	void setScale(float newScale) {
		_scale = newScale;
		_needsMatrixUpdate = true;
	}

	//getters
	glm::vec2 getPosition() { return _position;}
	float getScale() { return _scale; }
	glm::mat4 getCameraMatrix() { return _cameraMatrix; }

private:
	// do we need to update the matrix?
	bool _needsMatrixUpdate;
	glm::vec2 _position;

	/**
	 * An orthographic projection matrix maps the real world co-ordinates to
	 * normalized device co-ordinates.
	 *
	 * We'll calculate this matrix and send it to our shader where it will be
	 * multiplied with the vertices.
	 * in our case this is a 4x4
	 */
	glm::mat4 _cameraMatrix;

	// for zoom in and zoom out.
	float _scale;




	int _screenWidth,_screenHeight;

	glm::mat4 _orthoMatrix;
};

} /* namespace Engine */

#endif /* CAMERA2D_H_ */
