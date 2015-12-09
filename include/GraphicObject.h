/*
 * GraphicObject.h
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */


#ifndef GRAPHICOBJECT_H_
#define GRAPHICOBJECT_H_

#include <list>
#include "Vertex.h"
#include "Transformation.h"
#include "BBox.h"

/**
 * Classe Objeto Gráfico. Representa um polígono no mundo.
 */
class GraphicObject {

private:

	//Atributos.

	/**
	 * Lista de objetos filhos.
	 */
	std::list<GraphicObject*> objects;
	/**
	 * Lista de vértices.
	 */
	std::list<Vertex*> vertices;
	/**
	 * Lista contendo os vértices transformados para fim de atualização da bbox após transformações.
	 * @see Readme - Tentativa de atualizar BBox após transformações.
	 */
	std::list<Vertex> transformedVertices;
	/**
	 * Flag para indicar se ocorreu mudança nos vértices/matriz de transformação do objeto.
	 */
	bool changed;
	/**
	 * Matriz de transformação do objeto.
	 */
	Transformation transformation;
	/**
	 * Matriz de transformação de todos os pais do objeto no grafo de cena.
	 */
	Transformation familyTransformation;
	/**
	 * Centro da bbox para base de rotação/escala.
	 */
	Vertex centerPoint;
	/**
	 * BBox do objeto.
	 */
	BBox bbox;
	/**
	 * Tipo de primitiva do objeto. GL_LINE_LOOP para polígono fechado e GL_LINE_STRIP para polígono aberto.
	 */
	int primitive;
	/**
	 * Matriz contendo os valores do RGB do objeto.
	 */
	float rgb[3];
	/**
	 * Espessura das linhas do objeto.
	 */
	float lineSize;
	/**
	 * Flag indicando se objeto está selecionado.
	 */
	bool selected;
	/**
	 * Matriz temporária de translação.
	 */
	Transformation tempTranslation;
	/**
	 * Matriz temporária de rotação.
	 */
	Transformation tempRotation;
	/**
	 * Matriz temporária de escala.
	 */
	Transformation tempScale;
	/**
	 * Matriz temporária de translação inversa.
	 */
	Transformation tempInverseTranslation;
	/**
	 * Matriz temporária de transformações globais.
	 */
	Transformation globalTransformation;

	//Métodos privados.

	/**
	 * Algoritmo ScanLine. Verifica se a posição x e y se encontram dentro do polígono.
	 * @param x posição x do clique
	 * @param y posição y do clique.
	 */
	bool checkScanLine(float x, float y);
	/**
	 * Desenha a BBox do objeto.
	 */
	void drawBBox();
	/**
	 * Atualiza os vértices transformados do objeto com a matriz de transformação do objeto e de sua família.
	 * @see Readme - Tentativa de atualizar BBox após transformações.
	 */
	void updateTransformedVertices();

public:

	//Métodos públicos.

	/**
	 * Construtor.
	 * @param primitive primitiva que indica o tipo do objeto.
	 */
	GraphicObject(int primitive);
	/**
	 * Destrutor.
	 */
	virtual ~GraphicObject();
	/**
	 * Desenha o objeto gráfico.
	 */
	void draw();
	/**
	 * Adiciona vértice ao objeto gráfico.
	 * @param *vertex ponteiro para o vértice que está sendo adicionado
	 */
	Vertex* addVertex(Vertex *vertex);
	/**
	 * Faz translação do objeto gráfico para as posições passadas.
	 * @param tX translação no eixo X.
	 * @param tY translação no eixo Y.
	 * @param tZ translação no eixo Z.
	 */
	void translate(float tX, float tY, float tZ);
	/**
	 * Faz rotação do objeto gráfico no eixo Z.
	 * @param degrees graus de rotação.
	 */
	void rotate(float degrees);
	/**
	 * Faz sscala do objeto gráfico.
	 * @param scale valor da escala em relação ao tamanho atual.
	 */
	void scale(float scale);
	/**
	 * Adiciona objeto gráfico filho.
	 * @param *object poteiro para o objeto gráfico filho.
	 */
	void addSon(GraphicObject *object);
	/**
	 * Verifica clique utilizando BBox e scanLine (se necessário) no objeto gráfico e em todos os seus filhos.
	 * @param x posição x do clique.
	 * @param y posição y do clique.
	 * @return Ponteiro para o objeto gráfico selecionado, ou NULL se ninguém foi selecionado.
	 */
	GraphicObject* checkClick(float x, float y);
	/**
	 * Verifica seleção de vértice no objeto gráfico e em todos os seus filhos.
	 * @param x posição x do clique.
	 * @para y posição y do clique.
	 * @return Ponteiro para o vértice selecionado, ou NULL se nenhum foi selecionado.
	 */
	Vertex* checkVertexClick(float x, float y);
	/**
	 * Muda cor do objeto para o RGB informado.
	 * @param r Red de 0.0f a 1.0f.
	 * @param g Green de 0.0f a 1.0f.
	 * @param b Blue de 0.0f a 1.0f.
	 */
	void changeColor(float r, float g, float b);
	/**
	 * Finaliza objeto gráfico que está sendo inserido.
	 */
	void finished();
	/**
	 * Seta estado do objeto gráfico para selecionado ou não-selecionado.
	 * @param selected flag indicando se o objeto gráfico está selecionado.
	 */
	void setSelected(bool selected);
	/**
	 * Remove o ponteiro se ele for filho do objeto gráfico.
	 * @param object ponteiro para o objeto que será removido.
	 */
	void removeIfPresent(GraphicObject* object);
	/**
	 * Remove o vértice.
	 * @param vertex ponteiro para o vértice que será removido.
	 */
	void removeVertex(Vertex* vertex);
	/**
	 * Adiciona transformação da família do grafo de cena.
	 * @transformation transformação acumulada de todas as gerações anteriores ao objeto gráfico.
	 * @see Readme - Tentativa de atualizar BBox após transformações.
	 */
	void addFamilyTransformation(Transformation transformation);
};

#endif /* GRAPHICOBJECT_H_ */
