/*
 * Camera.cpp
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#include "../include/Camera.h"

Camera::Camera(float yMin, float yMax, float xMin, float xMax) {
	this->yMin = yMin;
	this->yMax = yMax;
	this->xMin = xMin;
	this->xMax = xMax;
}

Camera::~Camera() {}

float Camera::getYMin() {
	return this->yMin;
}

float Camera::getYMax() {
	return this->xMax;
}

float Camera::getXMin() {
	return this->xMin;
}

float Camera::getXMax() {
	return this->xMax;
}

