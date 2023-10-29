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
				case(0):  //m�s              
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
				case(0):   //m�s
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
				case(0):    //m�s (angulos de rotaci�n, no cifras entre 1 y 0)
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
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			switch (numerorandomprop2)
			{
			case(0):  //Size
				switch (randomvalue)
				{
				case(0):  //m�s              
					this->cube.SetSize(this->cube.GetSize() + 0.1f);
					break;
				case(1):  //menos
					this->cube.SetSize(this->cube.GetSize() + -0.1f);
					break;
				}
				break;
			case(1):  //Position
				switch (randomvalue)
				{
				case(0):  //a un lado
					this->cube.SetPosition(Vector3D(cube.GetPosition().GetX() + 0.02, cube.GetPosition().GetY() + -0.02, cube.GetPosition().GetZ() + 0));
					break;
				case(1):  //regresa
					this->cube.SetPosition(Vector3D(cube.GetPosition().GetX() + -0.02, cube.GetPosition().GetY() + 0.02, cube.GetPosition().GetZ() + 0));
					break;
				}
				break;
			case(2):   //color
				switch (randomvalue)
				{
				case(0):   //m�s
					this->cube.SetColor(Color(cube.GetColor().GetX() + 0.1, cube.GetColor().GetY() + -0.1, cube.GetColor().GetZ() + 0.07));
					break;
				case(1):    //menos
					this->cube.SetColor(Color(cube.GetColor().GetX() + -0.1, cube.GetColor().GetY() + 0.1, cube.GetColor().GetZ() + -0.07));
					break;
				}
				break;
			case(3):    //rotation
				switch (randomvalue)
				{
				case(0):    //m�s (angulos de rotaci�n, no cifras entre 1 y 0)
					this->cube.SetRotation(Vector3D(cube.GetRotation().GetX() + 20, cube.GetRotation().GetY() + 10, cube.GetRotation().GetZ() + 20));
					break;
				case(1):    //menos
					this->cube.SetRotation(Vector3D(cube.GetRotation().GetX() + -20, cube.GetRotation().GetY() + -10, cube.GetRotation().GetZ() + -20));
					break;
				}
				break;
			}
		}
		break;
	case(2):                                       //Cuboid
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			switch (numerorandomprop2)
			{
			case(0):  //Size
				switch (randomvalue)
				{
				case(0):  //m�s              
					this->cuboid.SetSize(this->cuboid.GetSize() + 0.01f);
					break;
				case(1):  //menos
					this->cuboid.SetSize(this->cuboid.GetSize() + -0.01f);
					break;
				}
				break;
			case(1):  //Position
				switch (randomvalue)
				{
				case(0):  //a un lado
					this->cuboid.SetPosition(Vector3D(cuboid.GetPosition().GetX() + 0.02, cuboid.GetPosition().GetY() + -0.02, cuboid.GetPosition().GetZ() + 0));
					break;
				case(1):  //regresa
					this->cuboid.SetPosition(Vector3D(cuboid.GetPosition().GetX() + -0.02, cuboid.GetPosition().GetY() + 0.02, cuboid.GetPosition().GetZ() + 0));
					break;
				}
				break;
			case(2):   //color
				switch (randomvalue)
				{
				case(0):   //m�s
					this->cuboid.SetColor(Color(cuboid.GetColor().GetX() + 0.1, cuboid.GetColor().GetY() + -0.1, cuboid.GetColor().GetZ() + 0.07));
					break;
				case(1):    //menos
					this->cuboid.SetColor(Color(cuboid.GetColor().GetX() + -0.1, cuboid.GetColor().GetY() + 0.1, cuboid.GetColor().GetZ() + -0.07));
					break;
				}
				break;
			case(3):    //rotation
				switch (randomvalue)
				{
				case(0):    //m�s (angulos de rotaci�n, no cifras entre 1 y 0)
					this->cuboid.SetRotation(Vector3D(cuboid.GetRotation().GetX() + 15, cuboid.GetRotation().GetY() + 15,cuboid.GetRotation().GetZ() + 10));
					break;
				case(1):    //menos
					this->cuboid.SetRotation(Vector3D(cuboid.GetRotation().GetX() + -15,cuboid.GetRotation().GetY() + -15, cuboid.GetRotation().GetZ() + -10));
					break;
				}
				break;
			}
		}
		break;
	case(3):                                            //Sphere
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			switch (numerorandomprop1)
			{
			case(0):  //Size
				switch (randomvalue)
				{
				case(0):  //m�s              
					this->sphere.SetDimensions(Vector3D(sphere.GetDimensions().GetX() + 0.02, sphere.GetDimensions().GetY() + -0.002, sphere.GetDimensions().GetZ() + 0.002));
					break;
				case(1):  //menos
					this->sphere.SetDimensions(Vector3D(sphere.GetDimensions().GetX() + -0.02, sphere.GetDimensions().GetY() + 0.002, sphere.GetDimensions().GetZ() - 0.002));
					break;
				}
				break;
			case(1):  //Position
				switch (randomvalue)
				{
				case(0):  //a un lado
					this->sphere.SetPosition(Vector3D(sphere.GetPosition().GetX() + 0.02, sphere.GetPosition().GetY() + -0.02, sphere.GetPosition().GetZ() + 0));
					break;
				case(1):  //regresa
					this->sphere.SetPosition(Vector3D(sphere.GetPosition().GetX() + -0.02, sphere.GetPosition().GetY() + 0.02, sphere.GetPosition().GetZ() + 0));
					break;
				}
				break;
			case(2):   //color
				switch (randomvalue)
				{
				case(0):   //m�s
					this->sphere.SetColor(Color(sphere.GetColor().GetX() + 0.1, sphere.GetColor().GetY() + -0.1, sphere.GetColor().GetZ() + 0.07));
					break;
				case(1):    //menos
					this->sphere.SetColor(Color(sphere.GetColor().GetX() + -0.1, sphere.GetColor().GetY() + 0.1, sphere.GetColor().GetZ() + -0.07));
					break;
				}
				break;
			case(3):    //rotation
				switch (randomvalue)
				{
				case(0):    //m�s (angulos de rotaci�n, no cifras entre 1 y 0)
					this->sphere.SetRotation(Vector3D(sphere.GetRotation().GetX() + 10, sphere.GetRotation().GetY() + 10, sphere.GetRotation().GetZ() + 20));
					break;
				case(1):    //menos
					this->sphere.SetRotation(Vector3D(sphere.GetRotation().GetX() + -10, sphere.GetRotation().GetY() + -10, sphere.GetRotation().GetZ() + -20));
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

