/*
 * Camera2d.cpp
 *
 *  Created on: Jun 16, 2016
 *      Author: salar
 */

#include "Camera2d.h"

namespace Engine {

Camera2d::Camera2d() :
		_position(0.0f,0.0f),
		_cameraMatrix(1.0f),
		_needsMatrixUpdate(1),
		_screenWidth(500),
		_screenHeight(500),
		_orthoMatrix(1.0f),
		_scale(1.0f)
{
	// TODO Auto-generated constructor stub

}

Camera2d::~Camera2d() {
	// TODO Auto-generated destructor stub
}


void Camera2d::init(int screenWidth,int screenHeight) {
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;

	// Build ortho matrix: left,right,bottom,top limits
	_orthoMatrix = glm::ortho(0.0f,(float) _screenWidth,0.0f,(float) _screenHeight);

	// The ortho matrix is calculated everytime the screen changes size.

}

void Camera2d::update() {

	if(_needsMatrixUpdate) {

		//Camera Scaling
		glm::vec3 scale(_scale,_scale,0.0f);
		// Multiply the scaling vector by an identity matrix and then multiply the
		// Identity matrix with camera matrix.
		_cameraMatrix = glm::scale(glm::mat4(1.0f),scale) * _orthoMatrix;


		//Camera Translation
		glm::vec3 translate(-_position.x,-_position.y ,0.0f);
		_cameraMatrix = glm::translate(_cameraMatrix,translate);
		/** If we need to update the matrix.


		// We first scale our view port.
		glm::vec3 scale(_scale,_scale,0.0f);

		// glm::scale will scale the orthoMatrix by scale
		_cameraMatrix = glm::scale(_orthoMatrix,scale);

		// we first translate our view port by what out _position is.

		// for the translation vector we use -ve values
		// so that when we move to the left everything moves to the
		// right. keeping z=0.0f
		glm::vec3 translate(-_position.x,-_position.y,0.0f);

		// translate the ortho matrix by translate.
		_cameraMatrix = glm::translate(_cameraMatrix,translate);

		_needsMatrixUpdate = false;*/





	}
}





} /* namespace Engine */
