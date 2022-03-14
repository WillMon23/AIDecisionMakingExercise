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
	setPhase(PHASEONE);
	getOwner()->getComponent<FleeComponent>()->setTarget((Actor*)GameManager::getInstance()->getAgent2());
}

void StateMachineWMComponent::update(float deltatime)
{
	setEnemiesPoints(GameManager::getInstance()->getAgent1Points());
	if (getEnemiesPoints() > 0)
		setPhase(PHASETWO);
	
	
	switch (getPhase()) {
	case PHASEONE:
		getOwner()->getComponent<FleeComponent>()->setForce(0);
		break;
	case PHASETWO:
		getOwner()->getComponent<SpriteComponent>()->setPath("Images/newShip.png");
		getOwner()->getTransform()->setScale({ 100, 100 });
		getOwner()->getComponent<WanderComponent>()->setSteeringForce(0);
		break;
	case PHASETHREE:
		break;
	}
	
	
}
