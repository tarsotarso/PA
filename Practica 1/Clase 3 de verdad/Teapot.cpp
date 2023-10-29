#include "Teapot.h"


void Teapot::Render() {
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glColor3f(this->GetColor().GetX(), this->GetColor().GetY(), this->GetColor().GetZ());
	glRotatef(this->GetRotation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotation().GetZ(), 0.0, 0.0, 1.0);
	glutSolidTeapot(this->GetSize());
	glPopMatrix();
}