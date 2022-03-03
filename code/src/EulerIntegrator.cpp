#include "EulerIntegrator.h"

EulerIntegrator::EulerIntegrator(ParticleSystem* particleSystem)
{
	_particleSystem = particleSystem;

	glm::vec3 previousPosition = { 0.f,0.f,0.f };
	glm::vec3 currentPosition = { 0.f,0.f,0.f };

	glm::vec3 previousVelocity = { 0.f,0.f,0.f };
	glm::vec3 currentVelocity = { 0.f,0.f,0.f };
}

EulerIntegrator::~EulerIntegrator()
{
	delete _particleSystem;
}

void EulerIntegrator::Step(ParticleSystem* particleSystem, float dt)
{
	glm::vec3 previousPosition;
	glm::vec3 currentPosition;

	glm::vec3 previousVelocity;
	glm::vec3 currentVelocity;

	glm::vec3 acceleration = { 0.0f, -9.81f, 0.0f };

	// Logic to make particles fall down
	for (int i = 0; i < particleSystem->GetNumberOfParticles(); i++)
	{
		// Update previous position & velocity
		previousPosition = particleSystem->GetParticlePosition(i);
		previousVelocity = particleSystem->GetParticleVelocity(i);

		// Update position
		currentPosition[0] = previousPosition[0] + dt * previousVelocity[0];
		currentPosition[1] = previousPosition[1] + dt * previousVelocity[1];
		currentPosition[2] = previousPosition[2] + dt * previousVelocity[2];

		// Update velocity
		currentVelocity[0] = previousVelocity[0] + dt * acceleration[0];
		currentVelocity[1] = previousVelocity[1] + dt * acceleration[1];
		currentVelocity[2] = previousVelocity[2] + dt * acceleration[2];

		// Update the paricle's position
		particleSystem->SetParticlePosition(i, currentPosition);
		particleSystem->SetParticleVelocity(i, currentVelocity);
	}

}
