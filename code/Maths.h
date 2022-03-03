#pragma once

#include <glm\glm.hpp>

class Plane {
public:

	Plane(glm::vec4* mapEquation);
	~Plane();

	void normalizePlane();
	void checkCollision();

private:

	glm::vec4* _mapEquation;

};

