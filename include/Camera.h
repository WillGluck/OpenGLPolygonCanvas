/*
 * Camera.h
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#ifndef CAMERA_H_
#define CAMERA_H_

/**
 * Camera. Representa a visão do usuário no espaço gráfico.
 */
class Camera {

private:

	//Atributos.

	/**
	 * Y mínimo da câmera.
	 */
	float yMin;
	/**
	 * Y máximo da câmera.
	 */
	float yMax;
	/**
	 * X mínimo da câmera.
	 */
	float xMin;
	/**
	 * X máximo da câmera.
	 */
	float xMax;

public:

	//Constutore e destrutor.

	/**
	 * Construtor.
	 * @param yMin valor mínimo de y.
	 * @param yMax valor máximo de y.
	 * @param xMin valor mínimo de x.
	 * @param xMax valor máximo de x.
	 */
	Camera(float yMin, float yMax, float xMin, float xMax);
	/**
	 * Destutor.
	 */
	virtual ~Camera();

	//Métodos públicos.

	/**
	 * @return Y mínimo da câmera.
	 */
	float getYMin();
	/**
	 * @return Y máximo da câmera.
	 */
	float getYMax();
	/**
	 * @return X mínimo da câmera.
	 */
	float getXMin();
	/**
	 * @return X máximo da câmera.
	 */
	float getXMax();

};

#endif /* CAMERA_H_ */
