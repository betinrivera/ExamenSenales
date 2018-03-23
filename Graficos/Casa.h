#pragma once
#include "Modelo.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp" 


class Casa : public Modelo {
public:
	Casa();
	vec3 coordenadas;
};