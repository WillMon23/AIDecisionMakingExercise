#include "WanderWMComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "Actor.h"
#include <time.h>

WanderComponent::WanderComponent(float circleDistance, float circleRadius, float wanderForce) : SteeringComponent::SteeringComponent(nullptr, wanderForce)
{
	m_circleDistance = circleDistance;
	m_circleRadius = circleRadius;

	srand(time(0));
}

MathLibrary::Vector2 WanderComponent::calculateForce()
{
	if (getSteeringForce() == 0)
		return { 0,0 };

	//Find the agents position and heading
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 heading = getAgent()->getMoveComponent()->getVelocity().getNormalized();

	//Find the circles position in front of the agent
	float magnitude = heading.getMagnitude();
	m_circlePos = ownerPosition + (heading * m_circleDistance);

	//Find a random vector on the circle 
	float randNum1 = (rand() % 201) - 100;
	float randNum2 = (rand() % 201) - 100;

	//Add the random vector to the circle position to get a new random point on the circle 
	MathLibrary::Vector2 randDirection = MathLibrary::Vector2((float)cos(randNum1), (float)sin(randNum2)).normalize() * m_circleRadius;

	//Seek to the random point 
	m_target = randDirection + m_circlePos;
	MathLibrary::Vector2 desiredVelocity = MathLibrary::Vector2::normalize(m_target - ownerPosition) * getSteeringForce();
	MathLibrary::Vector2 force = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return force;
}