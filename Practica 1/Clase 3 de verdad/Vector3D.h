#pragma once
#include "GL/glut.h"

class Vector3D
{
private:
	float x;
	float y;
	float z;

public:
	Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3D(float x,float y, float z) : x(x), y(y), z(z) {}
	

	inline float GetX() const { return this->x; }
	inline float GetY() const { return this->y; }
	inline float GetZ() const { return this->z; }

	inline void SetX(float xToSet) { this->x = xToSet; }
	inline void SetY(float yToSet) { this->y = yToSet; }
	inline void SetZ(float zToSet) { this->z = zToSet; }

};

