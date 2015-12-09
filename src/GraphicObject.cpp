/*
 * GraphicObject.cpp
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#include <GL/glu.h>
#include <iterator>
#include <iostream>
#include <math.h>

#include "../include/GraphicObject.h"

GraphicObject::GraphicObject(int primitive) : centerPoint(0.0f, 0.0f, 0.0f, 1.0f) {
	this->primitive = primitive;
	this->lineSize = 2.0f;
	this->selected = false;
	this->changed = false;
	this->transformation.assignIdentity();
	this->familyTransformation.assignIdentity();
	for (int i = 0; i < 3; ++i) this->rgb[i] = 0.0f;
}

GraphicObject::~GraphicObject() {
	std::list<Vertex*>::iterator itVertices;
	for (itVertices = this->vertices.begin(); itVertices != this->vertices.end(); ++itVertices) {
		delete(*itVertices);
		*itVertices = NULL;
	}
	std::list<GraphicObject*>::iterator itObjects;
	for (itObjects = this->objects.begin(); itObjects != this->objects.end(); ++itObjects) {
		delete(*itObjects);
		*itObjects = NULL;
	}
}

void GraphicObject::draw() {
	float tempMatrix[16];
	transformation.getMatrix(tempMatrix);
	std::list<Vertex*>::iterator it;
	glPushMatrix();
		glMultMatrixf(tempMatrix);
		glColor3f(rgb[0], rgb[1], rgb[2]);
		glLineWidth(2.0f);
		glBegin(this->primitive);
		for (it = this->vertices.begin(); it != this->vertices.end(); ++it) {
			glVertex2f((*it)->getX(), (*it)->getY());
		}
		glEnd();
		if (this->objects.size() > 0) {
			std::list<GraphicObject*>::iterator it2;
			for (it2 = this->objects.begin(); it2 != this->objects.end(); ++it2) {
				(*it2)->addFamilyTransformation(this->transformation.transformMatrix(familyTransformation));
				(*it2)->draw();
			}
		}
	glPopMatrix();
	if (this->selected) {
		this->drawBBox();
	}
}

void GraphicObject::drawBBox() {

	this->updateTransformedVertices();
	this->bbox.calculateBBox(this->transformedVertices);

	glPushMatrix();
	glLoadIdentity();
	glColor3f(0.0f, 0.f, 0.0f);
	glLineWidth(1.0f);
	glBegin(GL_LINE_LOOP);
		glVertex2f(this->bbox.getXMin(), this->bbox.getYMin());
		glVertex2f(this->bbox.getXMin(), this->bbox.getYMax());
		glVertex2f(this->bbox.getXMax(), this->bbox.getYMax());
		glVertex2f(this->bbox.getXMax(), this->bbox.getYMin());
	glEnd();
	glPopMatrix();
}

void GraphicObject::updateTransformedVertices() {
	std::list<Vertex*>::iterator it;
	this->transformedVertices.clear();
	std::list<Vertex>::iterator transformIt = this->transformedVertices.end();

//	XXX Implementação para arrumar BBox (se comentar, descomente bloco seguinte)
////////////////////////////////////////////////////////////////////////////////////////
	Transformation tempTransformation;
	tempTransformation.assignIdentity();
	tempTransformation = this->familyTransformation.transformMatrix(transformation);


	for (it = this->vertices.begin(); it != this->vertices.end(); ++it) {
		Vertex vertex(0.0f, 0.0f, 0.0f, 1.0f);
		tempTransformation.transformVector(*it, &vertex);
		this->transformedVertices.insert(transformIt, vertex);
	}
//  XXX implementação sem recalcular BBox (se descomentar, comente bloco anterior)
/////////////////////////////////////////////////////////////////////////////////////////
//	for (it = this->vertices.begin(); it != this->vertices.end(); ++it) {
//		Vertex vertex((*it)->getX(), (*it)->getY(), 0.0f, 1.0f);
//		this->transformedVertices.insert(transformIt, vertex);
//	}
/////////////////////////////////////////////////////////////////////////////////////////

	this->bbox.calculateBBox(this->transformedVertices);
	changed = false;
}

Vertex* GraphicObject::addVertex(Vertex *vertex) {
	std::list<Vertex*>::iterator it = this->vertices.end();

	if (this->vertices.size() == 0) {
		this->vertices.insert(it, vertex);
	} else {
		--it;
		if (*it != vertex) {
			++it;
			this->vertices.insert(it, vertex);
		} else {
			++it;
		}
	}
	Vertex *newVertex = new Vertex(vertex->getX(), vertex->getY(), vertex->getZ(), vertex->getW());
	this->vertices.insert(it, newVertex);
	this->changed = true;
	return newVertex;
}

void GraphicObject::translate(float tX, float tY, float tZ) {

	Transformation translate;
	translate.assignTranslation(tX, tY, tZ);
	float tempMatrix[16];
	this->transformation.getMatrix(tempMatrix);
	tempMatrix[12] = tX;
	tempMatrix[13] = tY;
	tempMatrix[14] = tZ;
	this->transformation.setMatrix(tempMatrix);

	changed = true;
}

void GraphicObject::rotate(float radius) {

	globalTransformation.assignIdentity();
	//Vertex centerPoint = this->bbox.getCenter();

	tempTranslation.assignTranslation(-centerPoint.getX(), -centerPoint.getY(), 0.0f);
	globalTransformation = tempTranslation.transformMatrix(globalTransformation);

	tempRotation.assignRotationZ(radius);
	globalTransformation= tempRotation.transformMatrix(globalTransformation);

	tempInverseTranslation.assignTranslation(centerPoint.getX(), centerPoint.getY(), 0.0f);
	globalTransformation = tempInverseTranslation.transformMatrix(globalTransformation);

	transformation = transformation.transformMatrix(globalTransformation);

	changed = true;
}

void GraphicObject::scale(float scale) {

	globalTransformation.assignIdentity();
	//Vertex centerPoint = this->bbox.getCenter();

	tempTranslation.assignTranslation(-centerPoint.getX(), -centerPoint.getY(), 0.0f);
	globalTransformation = tempTranslation.transformMatrix(globalTransformation);

	tempRotation.assignScale(scale);
	globalTransformation= tempRotation.transformMatrix(globalTransformation);

	tempInverseTranslation.assignTranslation(centerPoint.getX(), centerPoint.getY(), 0.0f);
	globalTransformation = tempInverseTranslation.transformMatrix(globalTransformation);

	transformation = transformation.transformMatrix(globalTransformation);

	changed = true;
}

void GraphicObject::addSon(GraphicObject *object) {
	std::list<GraphicObject*>::iterator it = this->objects.end();
	object->addFamilyTransformation(this->transformation);
	this->objects.insert(it, object);
}

GraphicObject* GraphicObject::checkClick(float x, float y) {

	this->updateTransformedVertices();

	GraphicObject* object = NULL;
	if (this->bbox.insideBBox(x, y)) {
		if (this->checkScanLine(x, y)) {
			object = this;
		}
	}
	if (object == NULL) {

		std::list<GraphicObject*>::iterator it = this->objects.begin();
		while(object == NULL && it != this->objects.end()) {
			object = (*it)->checkClick(x, y);
			++it;
		}
	}
	return object;
}

bool GraphicObject::checkScanLine(float x, float y) {

	int intersections = 0;
	float tI = 0.0f;
	float xI = 0.0f;
	std::list<Vertex>::iterator it = this->transformedVertices.begin();
	std::list<Vertex>::iterator tempIt = this->transformedVertices.begin();

	for (it = this->transformedVertices.begin(); it != this->transformedVertices.end(); ++it) {

		Vertex vertexOne = (*it);
		Vertex vertexTwo(0.0f, 0.0f, 0.0f, 1.0f);
		++it;

		if (it == this->transformedVertices.end()) {
			vertexTwo = (*tempIt);
		} else {
			vertexTwo = (*it);
		}

		--it;

		tI = (y - vertexOne.getY()) / (vertexTwo.getY() - vertexOne.getY());
		if (tI >= 0 && tI <= 1) {
			xI = vertexOne.getX() + ((vertexTwo.getX() - vertexOne.getX()) * tI);
			if (xI >= x) ++intersections;
		}
	}
	return (intersections % 2 != 0);
}

Vertex* GraphicObject::checkVertexClick(float x, float y) {

	Vertex* vertex = NULL;

	std::list<Vertex*>::iterator it;
	for (it = this->vertices.begin(); it != this->vertices.end(); ++it) {


//	XXX Implementação para selecionar vértice mesmo dps da transformação (se comentar, descomente bloco seguinte)
		Vertex tempTransformedVertex(0.0f, 0.0f, 0.0f, 1.0f);
		this->familyTransformation.transformMatrix(transformation).transformVector(*it, &tempTransformedVertex);
		float xDistance = fabsf(tempTransformedVertex.getX() - x);
		float yDistance = fabsf(tempTransformedVertex.getY() - y);
////////////////////////////////////////////////////////////////////////////////////////
//  XXX Implementação para ignorar transformação (se descomentar, comente bloco anterior)
//
//		float xDistance = fabsf((*it)->getX() - x);
//		float yDistance = fabsf((*it)->getX() - y);
////////////////////////////////////////////////////////////////////////////////////////
		if (xDistance <= 20.0f && yDistance <= 20.0f) {
			vertex = *it;
			vertex->setFather(this);
			return vertex;
		}
	}
	std::list<GraphicObject*>::iterator sonsIt;
	for (sonsIt = this->objects.begin(); sonsIt != this->objects.end(); ++sonsIt) {
		vertex = (*sonsIt)->checkVertexClick(x, y);
		if (vertex != NULL) break;
	}
	return vertex;
}


void GraphicObject::removeVertex(Vertex* vertex) {
	std::list<Vertex*>::iterator it;
	for (it = this->vertices.begin(); it != this->vertices.end(); ++it) {
		if (vertex == *it) {
			this->vertices.remove(*it);
			delete *it;
			vertex = *it = NULL;
			break;
		}
	}
	changed = true;
}

void GraphicObject::changeColor(float r, float g, float b) {
	this->rgb[0] = r;
	this->rgb[1] = g;
	this->rgb[2] = b;
}

void GraphicObject::setSelected(bool selected) {
	this->selected = selected;
}

void GraphicObject::finished() {
	this->updateTransformedVertices();
	this->bbox.calculateBBox(this->transformedVertices);
	this->centerPoint = this->bbox.getCenter();
}

void GraphicObject::removeIfPresent(GraphicObject* object) {
	std::list<GraphicObject*>::iterator it;
	for (it = this->objects.begin(); it != this->objects.end(); ++it) {
		if (*it == object) {
			this->objects.remove(object);
			delete object;
			object = *it = NULL;
		} else {
			(*it)->removeIfPresent(object);
		}
		if (object == NULL){
			return;
		}
	}
}

void GraphicObject::addFamilyTransformation(Transformation transformation) {
	this->familyTransformation = transformation;
}


