#include "StateMachine_PLS_Component.h"
#include "Actor.h"
#include "Seek_PLS_Component.h"
//#include "WanderComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"

void StateMachine_PLS_Component::start()
{
	Component::start();
	getOwner()->addComponent<MoveComponent>();
	m_seekComponent = getOwner()->getComponent<Seek_PLS_Component>();
	m_seekForce = m_seekComponent->getSteeringForce();

	//m_wanderComponent = getOwner()->getComponent<WanderComponent>();
	//m_wanderForce = m_wanderComponent->getSteeringForce();

	m_currentState = SEEK;
}

void StateMachine_PLS_Component::update(float deltaTime)
{
	Actor* test = m_seekComponent->getTarget();
	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;
	switch (m_currentState)
	{
	case IDLE:
		m_seekComponent->setSteeringForce(0);
		//m_wanderComponent->setSteeringForce(0);

		if (targetInRange)
			setCurrentState(SEEK);
		break;
	case WANDER:
		m_seekComponent->setSteeringForce(0);
		//m_wanderComponent->setSteeringForce(m_wanderForce);

		if (targetInRange)
			setCurrentState(SEEK);
		break;
	case SEEK:
		m_seekComponent->setSteeringForce(m_seekForce);
		//m_wanderComponent->setSteeringForce(0);

		if (!targetInRange)
			setCurrentState(WANDER);
		break;
	}
}
