/*
 * Transformation.cpp
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#include <cstring>
#include <math.h>
#include "../include/Transformation.h"

using namespace std;

Transformation::Transformation() {
	this->assignIdentity();
}

Transformation::~Transformation() {}

void Transformation::assignIdentity() {
	for (int i = 0; i < 16; i++) {
		this->matrix[i] = 0;
	}
	this->matrix[0] = this->matrix[5] = this->matrix[10] = this->matrix[15] = 1.0f;
}

void Transformation::assignTranslation(float tX, float tY, float tZ) {
	this->assignIdentity();
	this->matrix[12] = tX;
	this->matrix[13] = tY;
	this->matrix[14] = tZ;
}

void Transformation::assignScale(float scale) {
	this->assignIdentity();
	this->matrix[0] = scale;
	this->matrix[5] = scale;
	this->matrix[10] = scale;
}

void Transformation::assignRotationX(float radius) {
	this->assignIdentity();
	this->matrix[5] = cos(radius * DEG_TO_RAD);
	this->matrix[6] = -sin(radius * DEG_TO_RAD);
	this->matrix[9] = sin(radius * DEG_TO_RAD);
	this->matrix[10] = cos(radius * DEG_TO_RAD);
}

void Transformation::assignRotationY(float radius) {
	this->matrix[0] = cos(radius * DEG_TO_RAD);
	this->matrix[2] = -sin(radius * DEG_TO_RAD);
	this->matrix[8] = sin(radius * DEG_TO_RAD);
	this->matrix[10] = cos(radius * DEG_TO_RAD);
}

void Transformation::assignRotationZ(float radius) {
	this->matrix[0] = cos(radius * DEG_TO_RAD);
	this->matrix[1] = sin(radius * DEG_TO_RAD);
	this->matrix[4] = -sin(radius * DEG_TO_RAD);
	this->matrix[5] = cos(radius * DEG_TO_RAD);
}

Transformation Transformation::transformMatrix(Transformation matrix) {
	float tempMatrix[16];
	float resultMatrix[16];
	matrix.getMatrix(tempMatrix);
	for (int i = 0; i < 16; ++i) {
		resultMatrix[i] =	this->matrix[i%4] * tempMatrix[i/4*4] + this->matrix[(i%4)+4] * tempMatrix[i/4*4+1]
				+ this->matrix[(i%4)+8] * tempMatrix[i/4*4+2]+ this->matrix[(i%4)+12] * tempMatrix[i/4*4+3];
	}
	Transformation result;
	result.setMatrix(resultMatrix);
	return result;
}

void Transformation::transformVector(Vertex* originVertex, Vertex* destinationVertex) {
	destinationVertex->setX(matrix[0] * originVertex->getX() + matrix[4] * originVertex->getY()
			+ matrix[8] * originVertex->getZ() + matrix[12] * originVertex->getW());
	destinationVertex->setY(matrix[1] * originVertex->getX() + matrix[5] * originVertex->getY()
			+ matrix[9] * originVertex->getZ() + matrix[13] * originVertex->getW());
	destinationVertex->setZ(matrix[2] * originVertex->getX() + matrix[6] * originVertex->getY()
			+ matrix[10] * originVertex->getZ() + matrix[14] * originVertex->getW());
	destinationVertex->setW(matrix[3] * originVertex->getX() + matrix[7] * originVertex->getY()
			+ matrix[11] * originVertex->getZ() + matrix[15] * originVertex->getW());
}

void Transformation::getMatrix(float* matrix) {
	std::memcpy((void*) matrix, (void*) this->matrix , sizeof(float) * 16);
}

void Transformation::setMatrix(float matrix[16]) {
	for (int i = 0; i < 16; ++i) {
		this->matrix[i] = matrix[i];
	}
}

