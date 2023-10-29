#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Cuboid.h"
#include "Sphere.h"

using namespace std;

class Game
{
private:
	Cube cube;
	Teapot teapot;
	Cuboid cuboid;
	Sphere sphere;

public:

	inline Cube GetCube() { return this->cube; }
	inline Cuboid GetCuboid() { return this->cuboid; }
	inline Teapot GetTeapot() { return this->teapot; }
	inline Sphere GetSphere() { return this->sphere; }

	Game() {}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};

