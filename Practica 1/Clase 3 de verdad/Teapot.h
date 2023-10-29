#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"

class Teapot
{
private:
	Vector3D position;
	Color color;
	Vector3D rotation;


	float size;

public:
	Teapot() : position(-2.2f, 1.4f, -3.5f), color(0,0,1),
		rotation(40.0, -45.0, 30.0), size(0.25) {}

	Vector3D GetPosition() const { return this->position; }
	Color GetColor() const { return this->color; }
	Vector3D GetRotation() const { return this->rotation; }
	float GetSize() const { return this->size; }

	void SetPosition(const Vector3D& positionToSet) { this->position = positionToSet; }
	void SetColor(const Color& colortToSet) { this->color = colortToSet; }
	void SetRotation(const Vector3D& rotationToSet) { this->rotation = rotationToSet; }
	void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();
};

