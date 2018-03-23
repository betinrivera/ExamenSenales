// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp" 

#include <iostream>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "Nave.h"
#include "Casa.h"
#include "Puerta.h"
#include "Ventana.h"
#include "Ave.h"


using namespace std;

GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint transformacionesID;


Modelo *figura;
Nave *nave;
Casa *casa;
Puerta *puerta;
Ventana *ventana;
Ave *ave;


Shader *shader;

//Declaración de ventana
GLFWwindow *window;

void actualizar() { 
	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	ave->MoverAve();
	/*int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS)
	{
		nave->rotarNave(0);
	}
	int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS)
	{
		nave->moverNave();
	}*/

}

void dibujar() {


	//figura->dibujar(GL_POLYGON);
	//nave->dibujar(GL_POLYGON);
	casa->dibujar(GL_POLYGON);
	puerta->dibujar(GL_POLYGON);
	ventana->dibujar(GL_POLYGON);
	ave->dibujar(GL_POLYGON);
}

void inicializarFigura() {
	figura = new Modelo();
	Vertice v1 =
	{ vec4(-1.0f,0.5f,0.0f, 1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	Vertice v2 =
	{ vec4(0.0f,-0.5f,0.0f, 1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	Vertice v3 =
	{ vec4(1.0f,0.5f,0.0f, 1.0f), vec4(1.0f,0.0f,1.0f,1.0f) };
	figura->vertices.push_back(v1);
	figura->vertices.push_back(v2);
	figura->vertices.push_back(v3);

}
void inicializarAve() {
	ave = new Ave();
	Vertice v1 =
	{ vec4(-0.9f,0.8f,0.0f, 1.0f), vec4(1.0f,1.0f,0.0f,1.0f) };
	Vertice v2 =
	{ vec4(-0.7f,0.8f,0.0f, 1.0f), vec4(1.0f,1.0f,0.0f,1.0f) };
	Vertice v3 =
	{ vec4(-0.8f,0.6f,0.0f, 1.0f), vec4(1.0f,1.0f,0.0f,1.0f) };
	ave->vertices.push_back(v1);
	ave->vertices.push_back(v2);
	ave->vertices.push_back(v3);

}

void inicializarCuadrado()
{
	nave = new Nave();
	Vertice ve1 =
	{ vec4(-0.1f,-0.1f,0.0f, 1.0f), vec4(0.0f,0.0f,0.0f,0.0f) };
	Vertice ve2 =
	{ vec4(0.0f,0.1f,0.0f, 1.0f), vec4(0.0f,0.0f,0.0f,0.0f) };
	Vertice ve3 =
	{ vec4(0.1f,-0.1f,0.0f, 1.0f), vec4(0.0f,0.0f,0.0f,0.0f) };
	nave->vertices.push_back(ve1);
	nave->vertices.push_back(ve2);
	nave->vertices.push_back(ve3);

}

void inicializarCasa() {
	casa = new Casa();
	Vertice ve1 =
	{ vec4(-0.4f, -0.2f, 0.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 0.0f) };
	Vertice ve2 =
	{ vec4(0.4f, -0.2f, 0.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 0.0f) };
	Vertice ve3 =
	{ vec4(0.4f, -0.9f, 0.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 0.0f) };
	Vertice ve4 =
	{ vec4(-0.4f, -0.9f, 0.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 0.0f) };

	casa->vertices.push_back(ve1);
	casa->vertices.push_back(ve2);
	casa->vertices.push_back(ve3);
	casa->vertices.push_back(ve4);

}
void inicializarPuerta() {
	puerta = new Puerta();
	Vertice ve1 =
	{ vec4(-0.2f, -0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f) };
	Vertice ve2 =
	{ vec4(0.2f, -0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f) };
	Vertice ve3 =
	{ vec4(0.2f, -0.9f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f) };
	Vertice ve4 =
	{ vec4(-0.2f, -0.9f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f) };

	puerta->vertices.push_back(ve1);
	puerta->vertices.push_back(ve2);
	puerta->vertices.push_back(ve3);
	puerta->vertices.push_back(ve4);

}
void inicializarVentana() {
	ventana = new Ventana();
	Vertice ve1 =
	{ vec4(-0.1f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f) };
	Vertice ve2 =
	{ vec4(0.1f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f) };
	Vertice ve3 =
	{ vec4(0.1f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f) };
	Vertice ve4 =
	{ vec4(-0.1f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f) };

	ventana->vertices.push_back(ve1);
	ventana->vertices.push_back(ve2);
	ventana->vertices.push_back(ve3);
	ventana->vertices.push_back(ve4);

}




int main()
{

	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicialización de GLFW
	if (!glfwInit()) {
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se creó bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}



	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;


	red = 0.0f, green = 0.4f, blue = 1.0f;

	//inicializarFigura();
	//inicializarCuadrado();

	inicializarCasa();
	inicializarPuerta();
	inicializarVentana();
	inicializarAve();

	//Crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";
	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID =
		glGetAttribLocation(shader->getID(), "posicion");
	colorID =
		glGetAttribLocation(shader->getID(), "color");
	transformacionesID =
		glGetUniformLocation(shader->getID(), "transformaciones");

	//Desenlazar shader
	shader->desenlazarShader();

	//figura->shader = shader;
	//figura->inicializarVertexArray(posicionID, colorID, transformacionesID);

	casa->shader = shader;
	casa->inicializarVertexArray(posicionID, colorID, transformacionesID);

	puerta->shader = shader;
	puerta->inicializarVertexArray(posicionID, colorID, transformacionesID);


	ventana->shader = shader;
	ventana->inicializarVertexArray(posicionID, colorID, transformacionesID);

	ave->shader = shader;
	ave->inicializarVertexArray(posicionID, colorID, transformacionesID);





	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

