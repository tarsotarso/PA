#include "Game.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
	case '0':
		this->prisma[0].SetColor(Color(1, 0, 0));
		this->prisma[1].SetColor(Color(1, 0, 0));
		this->prisma[2].SetColor(Color(1, 0, 0));
		this->prisma[3].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[4].SetColor(Color(1, 0, 0));
		this->prisma[5].SetColor(Color(1, 0, 0));
		this->prisma[6].SetColor(Color(1, 0, 0));
		break;
	case '1':
		this->prisma[0].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[1].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[2].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[3].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[4].SetColor(Color(1, 0.0, 0.0));
		this->prisma[5].SetColor(Color(1, 0.0, 0.0));
		this->prisma[6].SetColor(Color(0.13, 0.13, 0.13));
		
		break;
	case '2':
		this->prisma[0].SetColor(Color(1, 0, 0));
		this->prisma[1].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[2].SetColor(Color(1, 0, 0));
		this->prisma[3].SetColor(Color(1, 0, 0));
		this->prisma[4].SetColor(Color(1, 0, 0));
		this->prisma[5].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[6].SetColor(Color(1, 0, 0));
		break;
	case '3':
		this->prisma[0].SetColor(Color(1, 0, 0));
		this->prisma[1].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[2].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[3].SetColor(Color(1, 0, 0));
		this->prisma[4].SetColor(Color(1, 0, 0));
		this->prisma[5].SetColor(Color(1, 0, 0));
		this->prisma[6].SetColor(Color(1, 0, 0));
		break;
	case '4':
		this->prisma[0].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[1].SetColor(Color(1, 0, 0));
		this->prisma[2].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[3].SetColor(Color(1, 0, 0));
		this->prisma[4].SetColor(Color(1, 0, 0));
		this->prisma[5].SetColor(Color(1, 0, 0));
		this->prisma[6].SetColor(Color(0.13, 0.13, 0.13));
		break;
	case '5':
		this->prisma[0].SetColor(Color(1, 0, 0));
		this->prisma[1].SetColor(Color(1, 0, 0));
		this->prisma[2].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[3].SetColor(Color(1, 0, 0));
		this->prisma[4].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[5].SetColor(Color(1, 0, 0));
		this->prisma[6].SetColor(Color(1, 0, 0));
		break;
	case '6':
		this->prisma[0].SetColor(Color(1, 0, 0));
		this->prisma[1].SetColor(Color(1, 0, 0));
		this->prisma[2].SetColor(Color(1, 0, 0));
		this->prisma[3].SetColor(Color(1, 0, 0));
		this->prisma[4].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[5].SetColor(Color(1, 0, 0));
		this->prisma[6].SetColor(Color(1, 0, 0));
		break;
	case '7':
		this->prisma[0].SetColor(Color(1, 0, 0));
		this->prisma[1].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[2].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[3].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[4].SetColor(Color(1, 0, 0));
		this->prisma[5].SetColor(Color(1, 0, 0));
		this->prisma[6].SetColor(Color(0.13, 0.13, 0.13));
		break;
	case '8':
		this->prisma[0].SetColor(Color(1, 0, 0));
		this->prisma[1].SetColor(Color(1, 0, 0));
		this->prisma[2].SetColor(Color(1, 0, 0));
		this->prisma[3].SetColor(Color(1, 0, 0));
		this->prisma[4].SetColor(Color(1, 0, 0));
		this->prisma[5].SetColor(Color(1, 0, 0));
		this->prisma[6].SetColor(Color(1, 0, 0));
		break;
	case '9':
		this->prisma[0].SetColor(Color(1, 0, 0));
		this->prisma[1].SetColor(Color(1, 0, 0));
		this->prisma[2].SetColor(Color(0.13, 0.13, 0.13));
		this->prisma[3].SetColor(Color(1, 0, 0));
		this->prisma[4].SetColor(Color(1, 0, 0));
		this->prisma[5].SetColor(Color(1, 0, 0));
		this->prisma[6].SetColor(Color(1, 0, 0));
		break;
	}
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
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			switch (numerorandomprop2)
			{
			case(0):  //Size
				switch (randomvalue)
				{
				case(0):  //más              
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
				case(0):   //más
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
				case(0):    //más (angulos de rotación, no cifras entre 1 y 0)
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
				case(0):  //más              
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
				case(0):   //más
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
				case(0):    //más (angulos de rotación, no cifras entre 1 y 0)
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
				case(0):  //más              
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
				case(0):   //más
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
				case(0):    //más (angulos de rotación, no cifras entre 1 y 0)
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
void Game::Init() {  //Vector posicion          Vector color      Vector dimensiones       Vector Rotación       
	prisma[0] = Prisma(Vector3D(0, 1.2f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(1, 0.3f, 0.5f), Vector3D(30, 0, 0), 0.7);
	prisma[1] = Prisma(Vector3D(-0.55, 0.7f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(0.3f, 1, 0.5), Vector3D(8, 17, 0), 0.7);
	prisma[2] = Prisma(Vector3D(-0.55, -0.25, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(0.3, 1, 0.5), Vector3D(0, 17, 0), 0.7);
	prisma[3] = Prisma(Vector3D(0, 0.25, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(1, 0.3f, 0.5f), Vector3D(5, 0, 0), 0.7);
	prisma[4] = Prisma(Vector3D(0.55, 0.7f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(0.3, 1, 0.5), Vector3D(8, -17, 0), 0.7);
	prisma[5] = Prisma(Vector3D(0.55, -0.25, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(0.3, 1, 0.5), Vector3D(0, -17, 0), 0.7);
	prisma[6] = Prisma(Vector3D(0, -0.7f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(1, 0.3f, 0.5f), Vector3D(-20, 0, 0), 0.7);
	/*	prisma[0] = Prisma(Vector3D(0, 1.2f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(1, 0.3f, 0.5f), Vector3D(30, 0, 0), 0.7);
	prisma[1] = Prisma(Vector3D(-0.6f, 0.8f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(0.3f, 1, 0.5), Vector3D(0, 0, 0), 0.7);
	prisma[2] = Prisma(Vector3D(-0.6f, -0.3f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(0.3, 1, 0.5), Vector3D(0, 0, 0), 0.7);
	prisma[3] = Prisma(Vector3D(0, 0.25, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(1, 0.3f, 0.5f), Vector3D(0, 0, 0), 0.7);
	prisma[4] = Prisma(Vector3D(0.6f, 0.8f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(0.3, 1, 0.5), Vector3D(0, 0, 0), 0.7);
	prisma[5] = Prisma(Vector3D(0.6f, -0.3f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(0.3, 1, 0.5), Vector3D(0, 0, 0), 0.7);
	prisma[6] = Prisma(Vector3D(0, -0.7f, -3.5f), Color(0.13f, 0.13f, 0.13f), Vector3D(1, 0.3f, 0.5f), Vector3D(0, 0, 0), 0.7);*/
}

void Game::Render() { 
	this->GetTeapot().Render();
	this->GetCube().Render();
	this->GetCuboid().Render();
	this->GetSphere().Render();
	this->GetPrisma0().Render();
	this->GetPrisma1().Render();
	this->GetPrisma2().Render();
	this->GetPrisma3().Render();
	this->GetPrisma4().Render();
	this->GetPrisma5().Render();
	this->GetPrisma6().Render();
}

void Game::Update() { }

