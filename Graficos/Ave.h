#pragma once
#pragma once
#include "Modelo.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp" 


class Ave : public Modelo {
public:
	Ave();
	vec3 coordenadas;
	float velocidad = 0.009f;
	void MoverAve();
};