#pragma once
#include "GL/glut.h"
#include "Vector3D.h"
#include "Color.h"

class Prisma
{
private:
	Vector3D position;
	Color color;
	Vector3D dimensions;
	Vector3D rotation;

	float size;

public:
	Prisma() : position(0.0f, 0.0f, 0.0f), color(0.0, 0.0, 0.0), dimensions(1.0, 1.0, 1.0), rotation(0.0, 0.0, 0.0), size(1) {}

	Prisma(Vector3D posicion, Color color, 
		Vector3D dimensiones, Vector3D rotacion, float tamano): 
		position(posicion), color(color),
		dimensions(dimensiones), rotation(rotacion), size(tamano) {}

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

