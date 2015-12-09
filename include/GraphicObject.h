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
 * Classe Objeto Gr�fico. Representa um pol�gono no mundo.
 */
class GraphicObject {

private:

	//Atributos.

	/**
	 * Lista de objetos filhos.
	 */
	std::list<GraphicObject*> objects;
	/**
	 * Lista de v�rtices.
	 */
	std::list<Vertex*> vertices;
	/**
	 * Lista contendo os v�rtices transformados para fim de atualiza��o da bbox ap�s transforma��es.
	 * @see Readme - Tentativa de atualizar BBox ap�s transforma��es.
	 */
	std::list<Vertex> transformedVertices;
	/**
	 * Flag para indicar se ocorreu mudan�a nos v�rtices/matriz de transforma��o do objeto.
	 */
	bool changed;
	/**
	 * Matriz de transforma��o do objeto.
	 */
	Transformation transformation;
	/**
	 * Matriz de transforma��o de todos os pais do objeto no grafo de cena.
	 */
	Transformation familyTransformation;
	/**
	 * Centro da bbox para base de rota��o/escala.
	 */
	Vertex centerPoint;
	/**
	 * BBox do objeto.
	 */
	BBox bbox;
	/**
	 * Tipo de primitiva do objeto. GL_LINE_LOOP para pol�gono fechado e GL_LINE_STRIP para pol�gono aberto.
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
	 * Flag indicando se objeto est� selecionado.
	 */
	bool selected;
	/**
	 * Matriz tempor�ria de transla��o.
	 */
	Transformation tempTranslation;
	/**
	 * Matriz tempor�ria de rota��o.
	 */
	Transformation tempRotation;
	/**
	 * Matriz tempor�ria de escala.
	 */
	Transformation tempScale;
	/**
	 * Matriz tempor�ria de transla��o inversa.
	 */
	Transformation tempInverseTranslation;
	/**
	 * Matriz tempor�ria de transforma��es globais.
	 */
	Transformation globalTransformation;

	//M�todos privados.

	/**
	 * Algoritmo ScanLine. Verifica se a posi��o x e y se encontram dentro do pol�gono.
	 * @param x posi��o x do clique
	 * @param y posi��o y do clique.
	 */
	bool checkScanLine(float x, float y);
	/**
	 * Desenha a BBox do objeto.
	 */
	void drawBBox();
	/**
	 * Atualiza os v�rtices transformados do objeto com a matriz de transforma��o do objeto e de sua fam�lia.
	 * @see Readme - Tentativa de atualizar BBox ap�s transforma��es.
	 */
	void updateTransformedVertices();

public:

	//M�todos p�blicos.

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
	 * Desenha o objeto gr�fico.
	 */
	void draw();
	/**
	 * Adiciona v�rtice ao objeto gr�fico.
	 * @param *vertex ponteiro para o v�rtice que est� sendo adicionado
	 */
	Vertex* addVertex(Vertex *vertex);
	/**
	 * Faz transla��o do objeto gr�fico para as posi��es passadas.
	 * @param tX transla��o no eixo X.
	 * @param tY transla��o no eixo Y.
	 * @param tZ transla��o no eixo Z.
	 */
	void translate(float tX, float tY, float tZ);
	/**
	 * Faz rota��o do objeto gr�fico no eixo Z.
	 * @param degrees graus de rota��o.
	 */
	void rotate(float degrees);
	/**
	 * Faz sscala do objeto gr�fico.
	 * @param scale valor da escala em rela��o ao tamanho atual.
	 */
	void scale(float scale);
	/**
	 * Adiciona objeto gr�fico filho.
	 * @param *object poteiro para o objeto gr�fico filho.
	 */
	void addSon(GraphicObject *object);
	/**
	 * Verifica clique utilizando BBox e scanLine (se necess�rio) no objeto gr�fico e em todos os seus filhos.
	 * @param x posi��o x do clique.
	 * @param y posi��o y do clique.
	 * @return Ponteiro para o objeto gr�fico selecionado, ou NULL se ningu�m foi selecionado.
	 */
	GraphicObject* checkClick(float x, float y);
	/**
	 * Verifica sele��o de v�rtice no objeto gr�fico e em todos os seus filhos.
	 * @param x posi��o x do clique.
	 * @para y posi��o y do clique.
	 * @return Ponteiro para o v�rtice selecionado, ou NULL se nenhum foi selecionado.
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
	 * Finaliza objeto gr�fico que est� sendo inserido.
	 */
	void finished();
	/**
	 * Seta estado do objeto gr�fico para selecionado ou n�o-selecionado.
	 * @param selected flag indicando se o objeto gr�fico est� selecionado.
	 */
	void setSelected(bool selected);
	/**
	 * Remove o ponteiro se ele for filho do objeto gr�fico.
	 * @param object ponteiro para o objeto que ser� removido.
	 */
	void removeIfPresent(GraphicObject* object);
	/**
	 * Remove o v�rtice.
	 * @param vertex ponteiro para o v�rtice que ser� removido.
	 */
	void removeVertex(Vertex* vertex);
	/**
	 * Adiciona transforma��o da fam�lia do grafo de cena.
	 * @transformation transforma��o acumulada de todas as gera��es anteriores ao objeto gr�fico.
	 * @see Readme - Tentativa de atualizar BBox ap�s transforma��es.
	 */
	void addFamilyTransformation(Transformation transformation);
};

#endif /* GRAPHICOBJECT_H_ */
