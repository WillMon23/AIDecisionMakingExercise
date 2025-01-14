#include "Wander_PLS_Component.h"
#include "Transform2D.h"
#include "Actor.h"
#include "Agent.h"
#include "MoveComponent.h"
#include <time.h>

Wander_PLS_Component::Wander_PLS_Component(float circleDistance, float circleRadius, float wanderForce)
{
	m_circleDistance = circleDistance;
	m_circleRadius = circleRadius;
	srand(time(NULL));
}

MathLibrary::Vector2 Wander_PLS_Component::calculateForce()
{
	if (getSteeringForce() == 0)
		return { 0, 0 };
	//Find the agents position and heading
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 heading = getAgent()->getMoveComponent()->getVelocity().getNormalized();

	//Find the circles position in front of agent
	m_circlePosition = ownerPosition + (heading * m_circleDistance);

	//Find a random vector on the circle
	float randNum = (rand() % 201);
	MathLibrary::Vector2 randDirection = MathLibrary::Vector2(cos(randNum), sin(randNum)) * m_circleRadius;

	//Add the random vector to the circle position to get a new random point on the circle
	m_target = randDirection + m_circlePosition;

	//Seek to the random point
	MathLibrary::Vector2 desiredVelocity = MathLibrary::Vector2::normalize(m_target - ownerPosition) * getSteeringForce();
	MathLibrary::Vector2 force = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return force;
}
