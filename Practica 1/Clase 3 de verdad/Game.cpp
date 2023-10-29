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
	
	int numerorandomobj = rand() % 4;
	int numerorandomprop1 = rand() % 4;
	int numerorandomprop2 = rand() % 5;
	int randomvalue = rand() % 2;
	
	switch (numerorandomobj)
	{
	case (0):   //Teapot
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			switch (numerorandomprop1) 
			{
			case(0):  //Size
				switch (randomvalue)
				{
				case(0):  //más              
					this->teapot.SetSize(this->teapot.GetSize() + 0.01f);
					break;
				case(1):  //menos
					this->teapot.SetSize(this->teapot.GetSize() + -0.01f);
					break;
				}
				break;
			case(1):  //Position
				switch (randomvalue)
				{
				case(0):  //a un lado
					this->teapot.SetPosition(Vector3D(teapot.GetPosition().GetX() + 0.02, teapot.GetPosition().GetY() + -0.02, teapot.GetPosition().GetZ() + 0));
					break;
				case(1):  //regresa
					this->teapot.SetPosition(Vector3D(teapot.GetPosition().GetX() + -0.02, teapot.GetPosition().GetY() + 0.02, teapot.GetPosition().GetZ() + 0));
					break;
				}
				break;
			case(2):   //color
				switch (randomvalue)
				{
				case(0):   //más
					this->teapot.SetColor(Color(teapot.GetColor().GetX() + 0.1, teapot.GetColor().GetY() + -0.1, teapot.GetColor().GetZ() + 0.07));
					break;
				case(1):    //menos
					this->teapot.SetColor(Color(teapot.GetColor().GetX() + -0.1, teapot.GetColor().GetY() + 0.1, teapot.GetColor().GetZ() + -0.07));
					break;
				}
				break;
			case(3):    //rotation
				switch (randomvalue)
				{
				case(0):    //más (angulos de rotación, no cifras entre 1 y 0)
					this->teapot.SetRotation(Vector3D(teapot.GetRotation().GetX() + 10, teapot.GetRotation().GetY() + 10, teapot.GetRotation().GetZ() + 20));    
					break;
				case(1):    //menos
					this->teapot.SetRotation(Vector3D(teapot.GetRotation().GetX() + -10, teapot.GetRotation().GetY() + -10, teapot.GetRotation().GetZ() + -20));
					break;
				}
				break;
			}
		}
		break;
	case(1):                                       //Cube
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			switch (numerorandomprop2)
			{
			case(0):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			case(1):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			case(2):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			case(3):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			}
		}
		break;
	case(2):                                       //Cuboid
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			switch (numerorandomprop2)
			{
			case(0):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			case(1):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			case(2):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			case(3):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			}
		}
		break;
	case(3):                                            //Sphere
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			switch (numerorandomprop1)
			{
			case(0):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			case(1):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			case(2):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
			case(3):
				switch (randomvalue)
				{
				case(0):

					break;
				case(1):

					break;
				}
				break;
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

