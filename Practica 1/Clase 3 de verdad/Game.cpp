#include "Game.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "Tecla Pulsada: " << key << endl;
}

void Game::ProcessMouseMovement(int x, int y)
{
	//de momento no hacemos nada...
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	srand(time(NULL));
	int numerorandomobj = rand() % 1;
	int numerorandomprop = rand() % 1;
	int randomvalue = rand() % 2;
	switch (numerorandomobj)
	{
	case (0):
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			switch (numerorandomprop)
			{
			case(0):
				switch (randomvalue)
				{
				case(0):
					this->teapot.SetSize(this->teapot.GetSize() + 0.01f);
					break;
				case(1):
					this->teapot.SetSize(this->teapot.GetSize() + -0.01f);
					break;
				}
				break;
			case(1):
				break;
			case(2):
				break;
			case(3):
				break;
			}
		}
		break;
	case(1):
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			switch (numerorandomprop)
			{
			
			}
		}
		break;
	case(2):
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			switch (numerorandomprop)
			{

			}
		}
		break;
	case(3):
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			switch (numerorandomprop)
			{
			
			}
		}
		break;
	}
	
	cout << "Click: " << button << endl;
}
void Game::Init() { }

void Game::Render() { 
	this->GetTeapot().Render();
	this->GetCube().Render();
	this->GetCuboid().Render();
	this->GetSphere().Render();
}

void Game::Update() { }

