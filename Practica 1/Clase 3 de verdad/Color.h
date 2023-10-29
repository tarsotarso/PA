#pragma once
#include "GL/glut.h"

class Color
{
private:
	float r;
	float g;
	float b;

public:
	Color() : r(1.0f), g(0.0f), b(0.0f) {}
	Color(float x, float y, float z) : r(x), g(y), b(z) {}


	inline float GetX() const { return this->r; }
	inline float GetY() const { return this->g; }
	inline float GetZ() const { return this->b; }

	inline void SetX(float xToSet) { this->r = xToSet; }
	inline void SetY(float yToSet) { this->g = yToSet; }
	inline void SetZ(float zToSet) { this->b = zToSet; }

};

