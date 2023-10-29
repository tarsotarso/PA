#include <iostream>
#include <GL/glut.h>
#include <string>
#include "Game.h"

using namespace std;

// Constantes //

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 300;
const int WINDOW_POSITION_Y = 400;
const char TITLE[] = "Parte 1";
const GLclampf RED = 0.569;
const GLclampf GREEN = 0.812;
const GLclampf BLUE = 0.941;
const GLclampf ALPHA = 1;

// Variables //
int fullScreenMode;

//Usando GAME//

Game game;

void writeLine(string text) 
{
	cout << text << endl;
}

void initGraphics()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(RED, GREEN, BLUE, ALPHA);
	game.Init();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.Render();

	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) height = 1;
	GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, aspectRatio, 1.0f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
}

void idle()
{
	game.Update();
	glutPostRedisplay();
}

void keyPressed(unsigned char key, int px, int py)
{
	game.ProcessKeyPressed(key, px, py);
	glutPostRedisplay();
}

void mouseMoved(int x, int y)
{
	game.ProcessMouseMovement(x, y);
	glutPostRedisplay();
}

void mouseClicked(int button, int state, int x, int y)
{
	game.ProcessMouseClick(button, state, x, y);
	glutPostRedisplay();
}

void specialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_F11:
		fullScreenMode = !fullScreenMode;
		if (fullScreenMode)
		{
			glutFullScreen();
		}
		else
		{
			glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
			glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
		}
		break;
	}
}
int main(int argc, char** argv)
{
	writeLine("OPEN GL HELLO WORLD");

	writeLine("CREATING WINDOW");

	glutInit(&argc, argv);                                                   //Inicialización del GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);               //Doble buffer, rgba y dep           
	glutInitWindowSize(800, 600);            //Tamaño inicial de la ventana                         
	glutInitWindowPosition(100, 100);            //Posición inicial de la ventana
	glutCreateWindow("Practica 1");                //Crea una ventana con el titulo dado

	writeLine("Funciones de tratamiento de eventos...");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);      //tratamiendo del evento de repintado de la pagina
	glutKeyboardFunc(keyPressed);
	glutMotionFunc(mouseMoved);
	glutSpecialFunc(specialKey);
	glutMouseFunc(mouseClicked);
	glutIdleFunc(idle);

	//inicialización de los gráficos
	writeLine("iniciando graficos...");
	initGraphics();

	writeLine("LOOP...");
	glutMainLoop();
}
