/*
 * Camera.h
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#ifndef CAMERA_H_
#define CAMERA_H_

/**
 * Camera. Representa a vis�o do usu�rio no espa�o gr�fico.
 */
class Camera {

private:

	//Atributos.

	/**
	 * Y m�nimo da c�mera.
	 */
	float yMin;
	/**
	 * Y m�ximo da c�mera.
	 */
	float yMax;
	/**
	 * X m�nimo da c�mera.
	 */
	float xMin;
	/**
	 * X m�ximo da c�mera.
	 */
	float xMax;

public:

	//Constutore e destrutor.

	/**
	 * Construtor.
	 * @param yMin valor m�nimo de y.
	 * @param yMax valor m�ximo de y.
	 * @param xMin valor m�nimo de x.
	 * @param xMax valor m�ximo de x.
	 */
	Camera(float yMin, float yMax, float xMin, float xMax);
	/**
	 * Destutor.
	 */
	virtual ~Camera();

	//M�todos p�blicos.

	/**
	 * @return Y m�nimo da c�mera.
	 */
	float getYMin();
	/**
	 * @return Y m�ximo da c�mera.
	 */
	float getYMax();
	/**
	 * @return X m�nimo da c�mera.
	 */
	float getXMin();
	/**
	 * @return X m�ximo da c�mera.
	 */
	float getXMax();

};

#endif /* CAMERA_H_ */
