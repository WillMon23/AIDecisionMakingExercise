#include "StateMachineWMComponent.h"
#include "MoveComponent.h"
#include "WanderWMComponent.h"
#include "Actor.h"

void StateMachineWMComponent::start()
{
	getOwner()->addComponent<MoveComponent>();
	getOwner()->addComponent<WanderComponent>();
	getOwner()->getComponent<MoveComponent>()->setMaxSpeed(100.0f);
}

void StateMachineWMComponent::update(float deltatime)
{
}
