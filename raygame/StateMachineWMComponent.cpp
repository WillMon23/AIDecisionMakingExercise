#include "StateMachineWMComponent.h"
#include "SteeringComponent.h"
#include "WanderWMComponent.h"
#include "MoveComponent.h"
#include "Actor.h"

void StateMachineWMComponent::start()
{
	getOwner()->addComponent<MoveComponent>();
	getOwner()->addComponent(new WanderComponent(5.0f, 20.0f, 200.0f));
	getOwner()->getComponent<MoveComponent>()->setMaxSpeed(10.0f);
}

void StateMachineWMComponent::update(float deltatime)
{
}
