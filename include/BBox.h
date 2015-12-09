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
 * BBox. Representa a BBox de um objecto gráfico.
 */
class BBox {

private:

	//Atributos.

	/**
	 * Y mínimo do objecto gráfico.
	 */
	float yMin;
	/**
	 * Y máximo do objecto gráfico.
	 */
	float yMax;
	/**
	 * X mínimo do objecto gráfico.
	 */
	float xMin;
	/**
	 * X máximo do objecto gráfico.
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

	//Métodos públicos.

	/**
	 * Cálculo da bbox. Recebe uma lista de vértices e atualiza os mínimos e máximos para x e y.
	 * @param vertices é uma lista de vértices do objeto gráfico.
	 */
	void calculateBBox(std::list<Vertex> vertices);
	/**
	 * Checa clique. Verifica se as posições x,y passadas se encontram dentro da BBox.
	 * @param x é o valor x do clique.
	 * @param y é o valor y do clique.
	 */
	bool insideBBox(float x, float y);
	/**
	 * @return O centro da bbox.
	 */
	Vertex getCenter();
	/**
	 * @return O x mínimo da bbox.
	 */
	float getXMin();
	/**
	 * @return O x máximo da bbox.
	 */
	float getXMax();
	/**
	 * @return O y mínimo da bbox.
	 */
	float getYMin();
	/**
	 * @return O y máximo da bbox.
	 */
	float getYMax();
};

#endif /* BBOX_H_ */
