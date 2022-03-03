#include "Maths.h"

Plane::Plane(glm::vec4* mapEquation)
{
	_mapEquation = mapEquation;
}

Plane::~Plane()
{
	delete _mapEquation;
}
