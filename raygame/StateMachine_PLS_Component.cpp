#include "StateMachine_PLS_Component.h"
#include "Actor.h"
#include "Seek_PLS_Component.h"
#include "Wander_PLS_Component.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "GameManager.h"

void StateMachine_PLS_Component::start()
{
	Component::start();
	getOwner()->addComponent<MoveComponent>();
	m_seekComponent = getOwner()->getComponent<Seek_PLS_Component>();
	m_seekForce = m_seekComponent->getSteeringForce();

	m_wanderComponent = getOwner()->getComponent<Wander_PLS_Component>();
	m_wanderForce = 30;

	m_currentState = WANDER;
}

void StateMachine_PLS_Component::update(float deltaTime)
{
	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();
	float distanceFromBall = (ownerPos - GameManager::getInstance()->getBall()->getTransform()->getWorldPosition()).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;
	switch (m_currentState)
	{
	case SEEK_BALL:
		m_seekComponent->setSteeringForce(m_seekForce);
		m_seekComponent->setTarget(GameManager::getInstance()->getBall());
		m_wanderComponent->setSteeringForce(0);

		if (targetInRange)
			setCurrentState(SEEK);
		break;
	case WANDER:
		m_seekComponent->setSteeringForce(0);
		m_wanderComponent->setSteeringForce(m_wanderForce);

		if (targetInRange)
			setCurrentState(SEEK);
		break;
	case SEEK:
		m_seekComponent->setSteeringForce(m_seekForce);
		m_wanderComponent->setSteeringForce(0);

		if (!targetInRange)
			setCurrentState(WANDER);
		break;
	}
}
