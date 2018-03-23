#include "stdafx.h"
#include "Ave.h"

Ave::Ave() {

	coordenadas = vec3(0.0f, 0.0f, 0.0f);
	transformaciones = mat4(1.0f);
}

void Ave::MoverAve() {

	vec3 traslacion =
		vec3(0.1f * velocidad, 0.0f, 0.0f);



	transformaciones =
		translate(transformaciones, traslacion);


	/*if (traslacion == vec3(0.9f, 0.0f, 0.0f))
	{
		transformaciones =
			translate(transformaciones, vec3(-0.9f, 0.0f, 0.0f));
	}*/

	coordenadas += traslacion;

	/*if (coordenadas.x >= 0.9) {
		traslacion = vec3(-0.1f * velocidad, 0.0f, 0.0f);
		transformaciones =
			translate(transformaciones, traslacion);
	}*/

}
