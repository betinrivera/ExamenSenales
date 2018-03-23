#pragma once
#include "Modelo.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp" 


class Ventana : public Modelo {
public:
	Ventana();
	vec3 coordenadas;
};