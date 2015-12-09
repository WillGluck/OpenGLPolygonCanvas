/*
 * Vertex.cpp
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#include "../include/Vertex.h"

Vertex::Vertex(float x, float y, float z, float w) : fatherObject(0) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vertex::~Vertex() {}

void Vertex::setX(float x) {
	this->x = x;
}

float Vertex::getX() {
	return this->x;
}

void Vertex::setY(float y) {
	this->y = y;
}

float Vertex::getY() {
	return this->y;
}

void Vertex::setZ(float w) {
	this->z = z;
}

float Vertex::getZ() {
	return this->z;
}

void Vertex::setW(float w) {
	this->z = z;
}

float Vertex::getW() {
	return this->w;
}

void Vertex::setFather(GraphicObject* fatherObject) {
	this->fatherObject = fatherObject;
}

GraphicObject* Vertex::getFather() {
	return this->fatherObject;
}

