#include "Agent1.h"
#include "Agent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "WanderWMComponent.h"
#include "FleeWMComponent.h"
#include "Goal.h"
#include "GameManager.h"
#include "StateMachineWMComponent.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/player.png"));
	addComponent<StateMachineWMComponent>();
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent1::start()
{
	Character::start();
	//add steering behaviours here

	addComponent<MoveComponent>();
	addComponent(new WanderComponent(3.0f, 40.0f, 100.0f));
	addComponent<FleeComponent>();

}

void Agent1::update(float deltaTime)
{
	Character::update(deltaTime);
}

void Agent1::onDeath()
{
	Character::onDeath();

}
