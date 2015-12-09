/*
 * Vertex.h
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#ifndef VERTEX_H_
#define VERTEX_H_

class GraphicObject;

class Vertex {

private:
	float x;
	float y;
	float z;
	float w;
	GraphicObject* fatherObject;

public:

	Vertex(float x, float y, float z, float w);
	virtual ~Vertex();

	void setX(float x);
	float getX();
	void setY(float y);
	float getY();
	void setZ(float Z);
	float getZ();
	void setW(float w);
	float getW();
	void setFather(GraphicObject* fatherObject);
	GraphicObject* getFather();
};

#endif /* VERTEX_H_ */
