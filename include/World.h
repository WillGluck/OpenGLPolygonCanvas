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
 * Atributos e métodos que representam o mundo gráfico. É o primeiro nível da apliação e possui o main.
 */

//atributos.

/**
 * Camera do usuário no mundo.
 */
Camera camera(-400.0f, 400.0f, -400.0f, 400.0f);
/**
 * Lista de objetos do mundo (primeiro nível do grafo de cena).
 */
std::list<GraphicObject*> objects;
/**
 * Flag indicando se o modo de inserção está ativo.
 */
bool insertionModeOn = false;
/**
 * Flag indicando se no modo de inserção o polígono deverá ser aberto.
 */
bool polygonOpenOn = false;
/**
 * Flag indicando se no modo de inserção o polígono que está sendo inserido é filho.
 */
bool addingSon = false;
/**
 * Ponteiro para o objeto selecionado.
 */
GraphicObject* selectedObject = NULL;
/**
 * Ponteiro para o vértice selecionado.
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
 * Float temporário que guarda o x do clique.
 */
float oldX = 0.0f;
/**
 * Float temporário que guarda o y do clique.
 */
float oldY = 0.0f;

//Métodos.

/**
 * Configura o display OpenGL.
 */
void configureDisplay();
/**
 * Mostra o SRU na tela para controle dos eixos.
 */
void displaySRU();
/**
 * Função GLUT de display OPENGL.
 */
void display();
/**
 * Desenha todos os objetos presentes no mundo.
 */
void draw();
/**
 * Função GLUT listener de mouse movement.
 * @param x valor x do mouse.
 * @param y valor y do mouse.
 */
void mouseMovement(int x, int y);
/**
 * Função GLUT listener de mouse click.
 * @param button código do botão clicado.
 * @param state estado do botão clicado.
 * @param x valor x do clique.
 * @param y valor y do clique.
 */
void mouseClick(int button, int state, int x, int y);
/**
 * Transforma posições de janela em posições do mundo OpenGL utilizando o método gluUnProject.
 * @param Ponteiro para a posição janela x que retornará o valor mundo OpenGL x.
 * @param Ponteiro para a posição janela y que retornará o valor mundo OpenGL y.
 */
void transformToWorldCoordinates(float* x, float* y);
/**
 * Função GLUT listener de keyboard click.
 * @param key tecla clicada.
 * @param x posição x do mouse quando a tecla for pressionada.
 * @param y posição y do mouse quando a tecla for pressionada.
 */
void keyboard(unsigned char key, int x, int y);
/**
 * Insere o vértice nas posições informadas.
 * @param x posição x no mundo.
 * @param y posição y no mundo.
 */
void insertVertex(int x, int y);
/**
 * Finaliza um polígono que está sendo inserido.
 */
void finishPolygon();
/**
 * Verifica clique para seleção de objetos ou vértices nas posições passadas.
 * @param x posição x do clique no mundo.
 * @param y posição y do clique no mundo.
 */
void checkClick(int x, int y);
/**
 * Adiciona um filho ao polígono selecionado.
 */
void addSon();
/**
 * Muda a cor do polígono selecionado.
 */
void changeColor();
/**
 * Rotaciona o polígono selecionado em 10 graus no eixo Z.
 */
void rotatePolygon();
/**
 * Escala o polígono selecionado em mais 10%.
 */
void scaleUpPolygon();
/**
 * Escala o polígono selecionado em menos 10%.
 */
void scaleDownPolygon();
/**
 * Move o polígono selecionado para as posições passadas.
 * @param movToX movimento X do polígono.
 * @param movToY movimento Y do polígono.
 */
void movePolygon(float movToX, float movToY);
/**
 * Remove o polígono selecionado.
 */
void removePolygon();
/**
 * Move o vértice selecionado para as posições passadas
 * @param movToX movimento X do vértice.
 * @param movToY movimento Y do vértice.
 */
void moveVertex(float movToX, float movToY);
/**
 * Remove o vértice selecionado.
 */
void removeVertex();

/**
 * @}
 */


#endif /* WORLD_H_ */
