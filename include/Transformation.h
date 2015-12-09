/*
 * Transformation.h
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

#include "Vertex.h"

/**
 * Classe Transforma��o. Representa uma matriz de transforma��o de um objeto gr�fico e engloba todos os m�todos de transforma��o.
 */
class Transformation {

private:

	//Atributos.

	/**
	 * Matriz de transforma��o
	 */
	float matrix[16];
	/**
	 * Constante para transforma��o de graus para radianos.
	 */
	const static float DEG_TO_RAD = 0.017453292519943295769236907684886;

public:

	//Constutor e destrutor.

	Transformation();
	virtual ~Transformation();

	//M�todos p�blicos.

	/**
	 * Seta a matriz de transforma��o para identidade.
	 */
	void assignIdentity();
	/**
	 * Seta a matriz de transforma��o para a transla��o passada.
	 * @param tX transla��o no eixo x.
	 * @param tY transla��o no eixo y.
	 * @param tZ transla�ao no eixo z.
	 */
	void assignTranslation(float tX, float tY, float tZ);
	/**
	 * Seta a matriz de transforma��o para a escala passada.
	 * @param scale escala em todos os eixos.
	 */
	void assignScale(float scale);
	/**
	 * Seta a matriz de transforma��o para realizar a rota��o no eixo X nos graus passados.
	 * @param degrees graus da rota��o.
	 */
	void assignRotationX(float degrees);
	/**
	 * Seta a matriz de transforma��o para realizar a rota��o no eixo Y nos graus passados.
	 * @param degrees graus da rota��o.
	 */
	void assignRotationY(float degrees);
	/**
	 * Seta a matriz de transforma��o para realizar a rota��o no eixo Z nos graus passados.
	 * @param degrees graus da rota��o.
	 */
	void assignRotationZ(float degrees);
	/**
	 * Realiza a multiplica��o de matrizes entre as duas transforma��es.
	 * @param matrix Transforma��o que ser� multiplicada com a chamada.
	 * @return Nova matriz de transforma��o resultante.
	 */
	Transformation transformMatrix(Transformation matrix);
	/**
	 * Realiza a multiplica��o da matriz de transforma��o com o v�rtice passado, encontrando a posi��o real do ponto na tela.
	 * @param originVertex ponteiro para o v�rtice de origem que ser� transformado.
	 * @param destinationVertex ponteiro para o v�rtice destino que receber� o resultado da transforma��o.
	 * @see Readme - Tentativa de atualizar BBox ap�s transforma��es.
	 */
	void transformVector(Vertex* originVertex, Vertex* destinationVertex);
	/**
	 * Retorna a matriz de transforma��o de 16 posi��es para o buffer passado.
	 * @param matrix � o buffer que receber� c�pia da matriz de transforma��o do objeto.
	 */
	void getMatrix(float *matrix);
	/**
	 * Seta a matriz de transforma��o.
	 * @param matrix Array de 16 posi��es que ser� setada como a matriz de transforma��o.
	 */
	void setMatrix(float matrix[16]);
};

#endif /* TRANSFORMATION_H_ */
