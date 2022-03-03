#pragma once

#include "ParticleSystem.h"

class EulerIntegrator
{
public:
	
	EulerIntegrator(ParticleSystem* particleSystem);
	~EulerIntegrator();

private:

	static void Step(ParticleSystem* particleSystem, float dt);

	ParticleSystem* _particleSystem;

};