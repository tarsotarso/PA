#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"

class Cube
{
private:
	Vector3D position;
	Color color;
	Vector3D dimensions;
	Vector3D rotation;

	float size;

public:
	Cube() : position(2.2f, 1.4f, -3.5f), color(1, 1, 0),
		dimensions(0.5, 0.5, 0.5), rotation(1.0, 0.5, 1.0), size(0.7) {}

	Vector3D GetPosition() const { return this->position; }
	Color GetColor() const { return this->color; }
	Vector3D GetDimensions() const { return this->dimensions; }
	Vector3D GetRotation() const { return this->rotation; }
	float GetSize() const { return this->size; }

	void SetPosition(const Vector3D& positionToSet) { this->position = positionToSet; }
	void SetColor(const Color& colortToSet) { this->color = colortToSet; }
	void SetDimensions(const Vector3D& dimensionsToSet) { this->dimensions = dimensionsToSet; }
	void SetRotation(const Vector3D& rotationToSet) { this->rotation = rotationToSet; }
	void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();

};