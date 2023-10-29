#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Cuboid.h"
#include "Sphere.h"
#include "Prisma.h"

using namespace std;

class Game
{
private:

	Cube cube;
	Teapot teapot;
	Cuboid cuboid;
	Sphere sphere;
	Prisma prisma[7];

public:
	
	inline Cube GetCube() { return this->cube; }
	inline Cuboid GetCuboid() { return this->cuboid; }
	inline Teapot GetTeapot() { return this->teapot; }
	inline Sphere GetSphere() { return this->sphere; }
	inline Prisma GetPrisma0() { return this->prisma[0]; }
	inline Prisma GetPrisma1() { return this->prisma[1]; }
	inline Prisma GetPrisma2() { return this->prisma[2]; }
	inline Prisma GetPrisma3() { return this->prisma[3]; }
	inline Prisma GetPrisma4() { return this->prisma[4]; }
	inline Prisma GetPrisma5() { return this->prisma[5]; }
	inline Prisma GetPrisma6() { return this->prisma[6]; }
	
	Game() {}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};

