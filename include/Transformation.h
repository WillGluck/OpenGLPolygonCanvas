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
 * Classe Transformação. Representa uma matriz de transformação de um objeto gráfico e engloba todos os métodos de transformação.
 */
class Transformation {

private:

	//Atributos.

	/**
	 * Matriz de transformação
	 */
	float matrix[16];
	/**
	 * Constante para transformação de graus para radianos.
	 */
	const static float DEG_TO_RAD = 0.017453292519943295769236907684886;

public:

	//Constutor e destrutor.

	Transformation();
	virtual ~Transformation();

	//Métodos públicos.

	/**
	 * Seta a matriz de transformação para identidade.
	 */
	void assignIdentity();
	/**
	 * Seta a matriz de transformação para a translação passada.
	 * @param tX translação no eixo x.
	 * @param tY translação no eixo y.
	 * @param tZ translaçao no eixo z.
	 */
	void assignTranslation(float tX, float tY, float tZ);
	/**
	 * Seta a matriz de transformação para a escala passada.
	 * @param scale escala em todos os eixos.
	 */
	void assignScale(float scale);
	/**
	 * Seta a matriz de transformação para realizar a rotação no eixo X nos graus passados.
	 * @param degrees graus da rotação.
	 */
	void assignRotationX(float degrees);
	/**
	 * Seta a matriz de transformação para realizar a rotação no eixo Y nos graus passados.
	 * @param degrees graus da rotação.
	 */
	void assignRotationY(float degrees);
	/**
	 * Seta a matriz de transformação para realizar a rotação no eixo Z nos graus passados.
	 * @param degrees graus da rotação.
	 */
	void assignRotationZ(float degrees);
	/**
	 * Realiza a multiplicação de matrizes entre as duas transformações.
	 * @param matrix Transformação que será multiplicada com a chamada.
	 * @return Nova matriz de transformação resultante.
	 */
	Transformation transformMatrix(Transformation matrix);
	/**
	 * Realiza a multiplicação da matriz de transformação com o vértice passado, encontrando a posição real do ponto na tela.
	 * @param originVertex ponteiro para o vértice de origem que será transformado.
	 * @param destinationVertex ponteiro para o vértice destino que receberá o resultado da transformação.
	 * @see Readme - Tentativa de atualizar BBox após transformações.
	 */
	void transformVector(Vertex* originVertex, Vertex* destinationVertex);
	/**
	 * Retorna a matriz de transformação de 16 posições para o buffer passado.
	 * @param matrix É o buffer que receberá cópia da matriz de transformação do objeto.
	 */
	void getMatrix(float *matrix);
	/**
	 * Seta a matriz de transformação.
	 * @param matrix Array de 16 posições que será setada como a matriz de transformação.
	 */
	void setMatrix(float matrix[16]);
};

#endif /* TRANSFORMATION_H_ */
