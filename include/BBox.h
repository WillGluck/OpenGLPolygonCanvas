/*
 * BBox.h
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */


#ifndef BBOX_H_
#define BBOX_H_

#include <list>
#include "Vertex.h"
#include "Transformation.h"

/**
 * BBox. Representa a BBox de um objecto gr�fico.
 */
class BBox {

private:

	//Atributos.

	/**
	 * Y m�nimo do objecto gr�fico.
	 */
	float yMin;
	/**
	 * Y m�ximo do objecto gr�fico.
	 */
	float yMax;
	/**
	 * X m�nimo do objecto gr�fico.
	 */
	float xMin;
	/**
	 * X m�ximo do objecto gr�fico.
	 */
	float xMax;

public:

	//Constutor e destutor.

	/**
	 * Construtor
	 */
	BBox();
	/**
	 * Destrutor
	 */
	virtual ~BBox();

	//M�todos p�blicos.

	/**
	 * C�lculo da bbox. Recebe uma lista de v�rtices e atualiza os m�nimos e m�ximos para x e y.
	 * @param vertices � uma lista de v�rtices do objeto gr�fico.
	 */
	void calculateBBox(std::list<Vertex> vertices);
	/**
	 * Checa clique. Verifica se as posi��es x,y passadas se encontram dentro da BBox.
	 * @param x � o valor x do clique.
	 * @param y � o valor y do clique.
	 */
	bool insideBBox(float x, float y);
	/**
	 * @return O centro da bbox.
	 */
	Vertex getCenter();
	/**
	 * @return O x m�nimo da bbox.
	 */
	float getXMin();
	/**
	 * @return O x m�ximo da bbox.
	 */
	float getXMax();
	/**
	 * @return O y m�nimo da bbox.
	 */
	float getYMin();
	/**
	 * @return O y m�ximo da bbox.
	 */
	float getYMax();
};

#endif /* BBOX_H_ */
