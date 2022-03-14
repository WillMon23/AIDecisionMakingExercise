#include "StateMachineWMComponent.h"
#include "SteeringComponent.h"
#include "WanderWMComponent.h"
#include "FleeWMComponent.h"
#include "SpriteComponent.h"
#include "GameManager.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "Actor.h"

void StateMachineWMComponent::start()
{
	setPhase(PHASETWO);
	getOwner()->getComponent<FleeComponent>()->setTarget((Actor*)GameManager::getInstance()->getAgent2());
}

void StateMachineWMComponent::update(float deltatime)
{
	setEnemiesPoints(GameManager::getInstance()->getAgent2Points());
	if (getEnemiesPoints() == 1)
		setPhase(PHASETWO);
	if (getEnemiesPoints() == 2)
		setPhase(PHASETHREE);
	
	
	switch (getPhase()) {
	case PHASEONE:
		break;
	case PHASETWO:
		getOwner()->getComponent<SpriteComponent>()->setPath("Images/newShip.png");
		getOwner()->getTransform()->setScale({ 100, 100 });
		getOwner()->getComponent<WanderComponent>()->setSteeringForce(0);
		getOwner()->getComponent<MoveComponent>()->setVelocity({ 1,1 });
		getOwner()->getComponent<MoveComponent>()->setMaxSpeed(400.0f);
		break;
	case PHASETHREE:
		getOwner()->getComponent<FleeComponent>()->setActive(true);
		break;
	}
	
	
}
