#pragma once
#include "GL/glut.h"
#include "Vector3D.h"
#include "Color.h"

class Sphere
{
private:
	Vector3D position;
	Color color;
	Vector3D size;
	Vector3D rotation;

public:
	Sphere() : position(2.2f, -1.4f, -3.5f), color(0, 1, 1),
		size(0.25, 30, 30), rotation(1.0, 0.5, 1.0) {}

	Vector3D GetPosition() const { return this->position; }
	Color GetColor() const { return this->color; }
	Vector3D GetDimensions() const { return this->size; }
	Vector3D GetRotation() const { return this->rotation; }

	void SetPosition(const Vector3D& positionToSet) { this->position = positionToSet; }
	void SetColor(const Color& colortToSet) { this->color = colortToSet; }
	void SetDimensions(const Vector3D& dimensionsToSet) { this->size = dimensionsToSet; }
	void SetRotation(const Vector3D& rotationToSet) { this->rotation = rotationToSet; }

	void Render();
};
