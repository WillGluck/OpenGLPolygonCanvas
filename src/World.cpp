/*
 * World.cpp
 *
 *  Created on: 16/04/2015
 *      Author: bigwi_000
 */

#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <list>
#include <stdio.h>

#include <iostream>

#include "../include/World.h"
#include "../include/KeyboardMap.h"

const int font=(int)GLUT_BITMAP_9_BY_15;
char s[30];

void configureDisplay() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(camera.getXMin(), camera.getXMax(), camera.getYMin(), camera.getYMax());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_LIGHTING);
}

void displaySRU() {
	glLineWidth(1.0f);
	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-400.0f, 0.0f);
		glVertex2f(400.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.0f, -400.0f);
		glVertex2f(0.0f, 400.0f);
	glEnd();
}

void display() {
	configureDisplay();
	displaySRU();
	draw();
	glutSwapBuffers();
}

void draw() {
	std::list<GraphicObject*>::iterator it;
	for (it = objects.begin(); it != objects.end(); ++it) {
		(*it)->draw();
	}
}

void mouseMovement(int x, int y) {

	float worldX = (float) x;
	float worldY = (float) y;

	transformToWorldCoordinates(&worldX, &worldY);

	if (selectedVertex != NULL) {
		moveVertex(worldX, worldY);
	} else if (selectedObject != NULL) {
		movePolygon((worldX), (worldY)); //TODO verificar "pulo"
	}

	glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {

	if (state == GLUT_DOWN) {

		float worldX = (float) x;
		float worldY = (float) y;

		transformToWorldCoordinates(&worldX, &worldY);
		oldX = worldX;
		oldY = worldY;

		if (insertionModeOn) {
			insertVertex(worldX, worldY);
		} else {
			checkClick(worldX, worldY);
		}
	}
	glutPostRedisplay();
}

void transformToWorldCoordinates(float *x, float *y) {

	GLint viewport[4]; //var to hold the viewport info
	GLdouble modelview[16]; //var to hold the modelview info
	GLdouble projection[16]; //var to hold the projection matrix info
	GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
	GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

	glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info
	glGetDoublev( GL_PROJECTION_MATRIX, projection ); //get the projection matrix info
	glGetIntegerv( GL_VIEWPORT, viewport ); //get the viewport info

	winX = *x;
	winY = (float)viewport[3] - *y;
	winZ = 0;

	//get the world coordinates from the screen coordinates
	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

	*x = worldX;
	*y = worldY;
}

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case CHANGE_MODE:
			finishPolygon();
			insertionModeOn = !insertionModeOn;
			std::cout << "Mudou para modo de " << (insertionModeOn ? "Inserção" : "Manipulação") << "\n";
			std::cout.flush();
			addingSon = false;
			break;
		case CHANGE_POLYGON:
			polygonOpenOn = !polygonOpenOn;
			std::cout << "Desenhando polígonos " << (polygonOpenOn ? "Abertos" : "Fechados") << "\n";
			std::cout.flush();
			break;
		case ROTATE: rotatePolygon(); break;
		case SCALE_UP:	scaleUpPolygon(); break;
		case SCALE_DOWN: scaleDownPolygon(); break;
		case FINISH: finishPolygon(); break;
		case CHANGE_COLOR: changeColor(); break;
		case REMOVE: removePolygon(); break;
		case ADD_SON: addSon(); break;
		case REMOVE_VERTEX: removeVertex(); break;
	}
	glutPostRedisplay();
}

void changeColor() {
	if (selectedObject != NULL) {
		selectedObject->changeColor(
				(float)rand() / (RAND_MAX + 1.0f),
				(float)rand() / (RAND_MAX + 1.0f),
				(float)rand() / (RAND_MAX + 1.0f));
	}
}

void insertVertex(int x, int y) {

	if (selectedObject == NULL || (selectedObject != NULL && addingSon)) {
		GraphicObject* object = new GraphicObject(polygonOpenOn ? GL_LINE_STRIP : GL_LINE_LOOP);
		if (addingSon) {
			selectedObject->addSon(object);
			selectedObject->setSelected(false);
			addingSon = false;
		} else {
			std::list<GraphicObject*>::iterator it = objects.end();
			objects.insert(it, object);
		}
		selectedObject = object;
		selectedVertex = selectedObject->addVertex(new Vertex(x, y, 0.0f, 1.0f));
	} else {
		selectedVertex = selectedObject->addVertex(selectedVertex);
	}
}

void finishPolygon() {
	if (insertionModeOn && selectedObject != NULL) {
		selectedObject->finished();
		std::cout << "Finalizando polígono \n";
		std::cout.flush();
	}
	selectedObject = NULL;
	selectedVertex = NULL;
}

void checkClick(int x, int y) {
	std::list<GraphicObject*>::iterator it;
	GraphicObject* object = NULL;

	if (selectedObject != NULL) {
		selectedObject->setSelected(false);
		selectedObject = NULL;
	}

	for (it = objects.begin(); it != objects.end(); ++it) {
		object = (*it)->checkClick(x, y);
		if (object != NULL) {
			selectedObject = object;
			selectedObject->setSelected(true);
			break;
		}
	}

	for (it = objects.begin(); it != objects.end(); ++it) {
		selectedVertex = (*it)->checkVertexClick(x, y);
		if (selectedVertex != NULL) {
			std::cout << "Vértice selecionado\n";
			std::cout.flush();
			break;
		}
	}
}

void addSon() {
	if (selectedObject != NULL) {
		if (insertionModeOn) {
			selectedObject->finished();
			std::cout << "Finalizando polígono";
			std::cout.flush();
		}
		insertionModeOn = true;
		addingSon = true;
		std::cout << "Inserindo filho \n";
		std::cout.flush();
	}
}

void rotatePolygon() {
	if (!insertionModeOn && selectedObject != NULL) {
		selectedObject->rotate(10.0f);
	}
}

void scaleUpPolygon() {
	if (!insertionModeOn && selectedObject != NULL) {
		selectedObject->scale(1.1f);
	}
}

void scaleDownPolygon() {
	if (!insertionModeOn && selectedObject != NULL) {
		selectedObject->scale(0.9f);
	}
}

void movePolygon(float movToX, float movToY) {
	if (!insertionModeOn && selectedObject != NULL) {
		selectedObject->translate(movToX, movToY, 0.0f);
	}
}

void removePolygon() {
	if (!insertionModeOn && selectedObject != NULL) {
		std::list<GraphicObject*>::iterator it;
		for (it = objects.begin(); it != objects.end(); ++it) {

			if (*it == selectedObject) {
				objects.remove(selectedObject);
				delete selectedObject;
				selectedObject = *(it) = NULL;
			} else {
				(*it)->removeIfPresent(selectedObject);
			}
			if (selectedObject == NULL){
				return;
			}
		}
		std::cout << "Polígono removido\n";
		std::cout.flush();
	}
}

void moveVertex(float movToX, float movToY) {
	selectedVertex->setX(movToX);
	selectedVertex->setY(movToY);
}

void removeVertex() {
	if (!insertionModeOn && selectedVertex != NULL ) {
		GraphicObject* object = selectedVertex->getFather();
		std::cout.flush();
		object->removeVertex(selectedVertex);
		selectedVertex = NULL;
		std::cout << "Vértice removido\n";
		std::cout.flush();
	}
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(300, 250);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Exercicio N3");
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMovement);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	std::list<GraphicObject*>::iterator it;
	for (it = objects.begin(); it != objects.end(); ++it) {
		delete (*it);
		*it = NULL;
	}


	return 0;
}

