/*
 * World.h
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "../include/Camera.h"
#include "../include/GraphicObject.h"

/**
 * @addtogroup World
 * @{
 * Atributos e m�todos que representam o mundo gr�fico. � o primeiro n�vel da aplia��o e possui o main.
 */

//atributos.

/**
 * Camera do usu�rio no mundo.
 */
Camera camera(-400.0f, 400.0f, -400.0f, 400.0f);
/**
 * Lista de objetos do mundo (primeiro n�vel do grafo de cena).
 */
std::list<GraphicObject*> objects;
/**
 * Flag indicando se o modo de inser��o est� ativo.
 */
bool insertionModeOn = false;
/**
 * Flag indicando se no modo de inser��o o pol�gono dever� ser aberto.
 */
bool polygonOpenOn = false;
/**
 * Flag indicando se no modo de inser��o o pol�gono que est� sendo inserido � filho.
 */
bool addingSon = false;
/**
 * Ponteiro para o objeto selecionado.
 */
GraphicObject* selectedObject = NULL;
/**
 * Ponteiro para o v�rtice selecionado.
 */
Vertex* selectedVertex = NULL;
/**
 * Altura da janela.
 */
int windowHeight = 500;
/**
 * Largura da janela.
 */
int windowWidth = 500;
/**
 * Float tempor�rio que guarda o x do clique.
 */
float oldX = 0.0f;
/**
 * Float tempor�rio que guarda o y do clique.
 */
float oldY = 0.0f;

//M�todos.

/**
 * Configura o display OpenGL.
 */
void configureDisplay();
/**
 * Mostra o SRU na tela para controle dos eixos.
 */
void displaySRU();
/**
 * Fun��o GLUT de display OPENGL.
 */
void display();
/**
 * Desenha todos os objetos presentes no mundo.
 */
void draw();
/**
 * Fun��o GLUT listener de mouse movement.
 * @param x valor x do mouse.
 * @param y valor y do mouse.
 */
void mouseMovement(int x, int y);
/**
 * Fun��o GLUT listener de mouse click.
 * @param button c�digo do bot�o clicado.
 * @param state estado do bot�o clicado.
 * @param x valor x do clique.
 * @param y valor y do clique.
 */
void mouseClick(int button, int state, int x, int y);
/**
 * Transforma posi��es de janela em posi��es do mundo OpenGL utilizando o m�todo gluUnProject.
 * @param Ponteiro para a posi��o janela x que retornar� o valor mundo OpenGL x.
 * @param Ponteiro para a posi��o janela y que retornar� o valor mundo OpenGL y.
 */
void transformToWorldCoordinates(float* x, float* y);
/**
 * Fun��o GLUT listener de keyboard click.
 * @param key tecla clicada.
 * @param x posi��o x do mouse quando a tecla for pressionada.
 * @param y posi��o y do mouse quando a tecla for pressionada.
 */
void keyboard(unsigned char key, int x, int y);
/**
 * Insere o v�rtice nas posi��es informadas.
 * @param x posi��o x no mundo.
 * @param y posi��o y no mundo.
 */
void insertVertex(int x, int y);
/**
 * Finaliza um pol�gono que est� sendo inserido.
 */
void finishPolygon();
/**
 * Verifica clique para sele��o de objetos ou v�rtices nas posi��es passadas.
 * @param x posi��o x do clique no mundo.
 * @param y posi��o y do clique no mundo.
 */
void checkClick(int x, int y);
/**
 * Adiciona um filho ao pol�gono selecionado.
 */
void addSon();
/**
 * Muda a cor do pol�gono selecionado.
 */
void changeColor();
/**
 * Rotaciona o pol�gono selecionado em 10 graus no eixo Z.
 */
void rotatePolygon();
/**
 * Escala o pol�gono selecionado em mais 10%.
 */
void scaleUpPolygon();
/**
 * Escala o pol�gono selecionado em menos 10%.
 */
void scaleDownPolygon();
/**
 * Move o pol�gono selecionado para as posi��es passadas.
 * @param movToX movimento X do pol�gono.
 * @param movToY movimento Y do pol�gono.
 */
void movePolygon(float movToX, float movToY);
/**
 * Remove o pol�gono selecionado.
 */
void removePolygon();
/**
 * Move o v�rtice selecionado para as posi��es passadas
 * @param movToX movimento X do v�rtice.
 * @param movToY movimento Y do v�rtice.
 */
void moveVertex(float movToX, float movToY);
/**
 * Remove o v�rtice selecionado.
 */
void removeVertex();

/**
 * @}
 */


#endif /* WORLD_H_ */
