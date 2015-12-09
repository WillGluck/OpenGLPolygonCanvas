/*
 * BBox.cpp
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#include "../include/BBox.h"
#include <iostream>

BBox::BBox() {
	this->yMin = 0.0f;
	this->yMax = 0.0f;
	this->xMin = 0.0f;
	this->xMax = 0.0f;
}

BBox::~BBox() {}

void BBox::calculateBBox(std::list<Vertex> vertices) {
	std::list<Vertex>::iterator it = vertices.begin();
	this->xMin = this->xMax = (*it).getX();
	this->yMin = this->yMax = (*it).getY();
	++it;
	for (; it != vertices.end(); ++it) {
		if (this->xMax < (*it).getX()) this->xMax = (*it).getX();
		else if (this->xMin > (*it).getX()) this->xMin = (*it).getX();
		if (this->yMax < (*it).getY()) this->yMax = (*it).getY();
		else if (this->yMin > (*it).getY()) this->yMin = (*it).getY();
	}
}

bool BBox::insideBBox(float x, float y) {
	bool isInside = (x >= this->xMin && x <= this->xMax)
				& (y >= this->yMin && y <= this->yMax);
	return isInside;
}

Vertex BBox::getCenter() {
	Vertex vertex((this->xMax + this->xMin)/2, (this->yMax + this->yMin)/2, 0.0f, 1.0f);
	return vertex;
}

float BBox::getXMin() {
	return this->xMin;
}

float BBox::getXMax() {
	return this->xMax;
}

float BBox::getYMin() {
	return this->yMin;
}

float BBox::getYMax() {
	return this->yMax;
}
