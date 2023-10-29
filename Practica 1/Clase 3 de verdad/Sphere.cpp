#include "Sphere.h"

void Sphere::Render (){
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glColor3f(this->GetColor().GetX(), this->GetColor().GetY(), this->GetColor().GetZ());
	glutSolidSphere(this->GetDimensions().GetX(), this->GetDimensions().GetY(), this->GetDimensions().GetZ());
	glRotatef(this->GetRotation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotation().GetZ(), 0.0, 0.0, 1.0);
	glPopMatrix();
}

//radio, slices, slacks

