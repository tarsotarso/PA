#include "BOX.h"
#include <IGL/IGlib.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

//Variables globales

// Variables globales para los vectores de cámara
glm::vec3 Cop = glm::vec3(0.0f, 0.0f, 3.0f);  // Posición de la cámara
glm::vec3 LookAt = glm::vec3(0.0f, 0.0f, -1.0f); // Punto de mira
glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);  // Vector "arriba"

// Función para construir la matriz de vista
glm::mat4 CalculateViewMatrix(glm::vec3 eye, glm::vec3 center, glm::vec3 up)
{
    glm::vec3 forward = glm::normalize(center - eye);
    glm::vec3 right = glm::normalize(glm::cross(forward, up));
    glm::vec3 newUp = glm::cross(right, forward);

    glm::mat4 viewMatrix(1.0f);
    viewMatrix[0][0] = right.x;
    viewMatrix[1][0] = right.y;
    viewMatrix[2][0] = right.z;
    viewMatrix[0][1] = newUp.x;
    viewMatrix[1][1] = newUp.y;
    viewMatrix[2][1] = newUp.z;
    viewMatrix[0][2] = -forward.x;
    viewMatrix[1][2] = -forward.y;
    viewMatrix[2][2] = -forward.z;
    viewMatrix[3][0] = -glm::dot(right, eye);
    viewMatrix[3][1] = -glm::dot(newUp, eye);
    viewMatrix[3][2] = glm::dot(forward, eye);

    return viewMatrix;
}



//Idenficadores de los objetos de la escena
int objId = -1;
int objId2 = -1;

//Declaración de CB
void resizeFunc(int width, int height);
void idleFunc();
void keyboardFunc(unsigned char key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void mouseMotionFunc(int x, int y);

float convert(float degree)
{
	static float pi = 3.14159265359f;
	return (degree * (pi / 180.0f));
}

int main(int argc, char** argv)
{
	std::locale::global(std::locale("spanish"));// acentos ;)

	if (!IGlib::init("../shaders_P1/shader.v6.vert", "../shaders_P1/shader.v6.frag"))
		return -1;


	//Se ajusta la cámara
	//Si no se da valor se cojen valores por defecto
	glm::mat4 model = glm::mat4(1.);
	glm::mat4 model2 = glm::mat4(1.);
	glm::mat4 view = glm::mat4(1.);

	//view[3].z = -6.f;

	glm::mat4 viewMatrix = CalculateViewMatrix(Cop, LookAt, Up);

	IGlib::setViewMat(viewMatrix);

	//Creamos el objeto que vamos a visualizar
	objId = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex, 
			cubeVertexPos, cubeVertexColor, cubeVertexNormal,cubeVertexTexCoord, cubeVertexTangent);

	objId2 = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex,
		cubeVertexPos, cubeVertexColor, cubeVertexNormal, cubeVertexTexCoord, cubeVertexTangent);

	IGlib::setModelMat(objId, model);
	IGlib::setModelMat(objId2, model2);

	//Incluir texturas aquí.
	IGlib::addColorTex(objId, "../img/color.png");
	IGlib::addColorTex(objId2, "../img/color.png");
	

  //CBs
  IGlib::setResizeCB(resizeFunc);
  IGlib::setIdleCB(idleFunc);
  IGlib::setKeyboardCB(keyboardFunc);
  IGlib::setMouseCB(mouseFunc);
  IGlib::setMouseMoveCB(mouseMotionFunc);

	
	//Mainloop
	IGlib::mainLoop();
	IGlib::destroy();
	return 0;
}

void resizeFunc(int width, int height)
{	
	//Ajusta el aspect ratio al tamaño de la ventana
	float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
	float FoV = 65.0f;
	float n = 0.5f;
	float f = 20.0f;
	
	float t = n * tan(FoV);
	float b = -t;
	float r = t * aspectRatio;
	float l = -r;

	glm::mat4 proj = glm::mat4(0.);

	proj[0].x = convert((2.0f * n) / (r - l));
	//proj[0].z = (r + l) / (r - l);                //Es igual a 0 
	proj[1].y = convert((2.0f * n) / (t - b));
	//proj[1].z = (t + b) / (t - b);                //Es igual a 0
	proj[2].z = convert(- (f + n) / (f - n));
	proj[2].w = convert(- (2.0f * f * n) / (f - n));
	proj[3].z = convert(- 1.0f);

	IGlib::setProjMat(proj);
}

void idleFunc()
{
	static float angle = 0.0f;    
	angle += (angle < 2.0f * 3.1415992) ? 0.05 : -angle;

	static float radio = 3.0f;        //tenemos que crear un movimiento de traslación para el segundo objeto

	static float orbitaX = radio * cos(angle);        //como tiene que orbitar en primer objeto en torno al eje y, en el plano XZ.
	static float orbitaZ = radio * sin(angle);

	glm::mat4 model = glm::rotate(glm::mat4(1.f), angle, glm::vec3(1.f,1.f,0.f));
	IGlib::setModelMat(objId, model);

	//el rotate tiene que estar antes del translate                                                                             //solo rota e su eje y
	glm::mat4 model2 = glm::rotate(glm::mat4(1.f), angle, glm::vec3(0.f, 1.f, 0.f)) * glm::translate(glm::mat4(1.0f),glm::vec3(orbitaX, 0.f, orbitaZ));   
	IGlib::setModelMat(objId2, model2);
}

void keyboardFunc(unsigned char key, int x, int y)
{
	static glm::mat4 view = glm::mat4(1.);
	float velocidad = 0.1f;

	switch (key)
	{
	case 'w':  // Avanzar
		Cop += 0.1f * (LookAt - Cop);
		break;
	case 's':  // Retroceder
		Cop -= 0.1f * (LookAt - Cop);
		break;
		// Agrega más casos para otras teclas según tus necesidades
	case 'a':
		glm::vec3 right = glm::normalize(glm::cross(LookAt - Cop, Up));
		Cop -= 0.1f * right;
		break;
	case 'd':
		right = glm::normalize(glm::cross(LookAt - Cop, Up));
		Cop += 0.1f * right;
		break;
	case 'n':

		break;
	case 'm':

		break;

	default:
		break;
	}
	glm::mat4 viewMatrix = CalculateViewMatrix(Cop, LookAt, Up);
	IGlib::setViewMat(viewMatrix);

	/*Implementación del movimiento de la cámara en primera persona. Para este ejercicio, os pedimos que recalculéis
la matriz View cada vez que el usuario presione una de las teclas asociadas al movimiento de la cámara. ***Importante***: debéis
recalcular esta matriz en lugar de actualizarla; por este motivo, la matriz NO debe ser declarada como una variable global. En
su lugar, declararemos como globales el CoP, el vector lookat y el vector up de la cámara en coordenadas del mundo virtual. Estos
valores deben actualizarse según los eventos de teclado. Una vez actualizados, debéis calcular la matriz View. ***Importante***: No
debéis utilizar funciones auxiliares de librerías externas. No obstante, podéis utilizar las funciones de glm que permiten transponer
e invertir matrices (si es necesario) y la función *rotate* para rotar los vectores correspondientes antes de calcular la matriz View.
Deberéis implementar los siguientes movimientos de forma obligatoria: avance, retroceso, desplazamiento lateral izquierdo, desplazamiento
lateral derecho, giro a la derecha y giro a la izquierda. Opcionalmente, podéis implementar los giros hacia arriba y hacia abajo, pero la
implementación se complica ligeramente.*/
	std::cout << "Se ha pulsado la tecla " << key << std::endl << std::endl;
}




void mouseFunc(int button, int state, int x, int y)
{
	if (state==0)
		std::cout << "Se ha pulsado el botón ";
	else
		std::cout << "Se ha soltado el botón ";
	
	if (button == 0) std::cout << "de la izquierda del ratón " << std::endl;
	if (button == 1) std::cout << "central del ratón " << std::endl;
	if (button == 2) std::cout << "de la derecha del ratón " << std::endl;

	std::cout << "en la posición " << x << " " << y << std::endl << std::endl;
}

void mouseMotionFunc(int x, int y)
{
}
