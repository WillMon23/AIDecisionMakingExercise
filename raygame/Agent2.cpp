#include "Agent2.h"
#include "SpriteComponent.h"
#include "GameManager.h"
#include "Goal.h"
#include "StateMachine_PLS_Component.h"
#include "MoveComponent.h"
#include "Seek_PLS_Component.h"
#include "Wander_PLS_Component.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/enemy.png"));
	m_seekComponent = new Seek_PLS_Component();
	m_seekComponent->setSteeringForce(50);
	getComponent<MoveComponent>()->setMaxSpeed(20);
	addComponent(m_seekComponent);
	m_wanderComponent = new Wander_PLS_Component(500, 200, 100);
	addComponent(m_wanderComponent);
	addComponent<StateMachine_PLS_Component>();

	
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent2::start()
{
	Character::start(); 
	//add steering behaviours here
	
	m_seekComponent->setTarget(GameManager::getInstance()->getAgent1());
	
}

void Agent2::update(float deltaTime)
{
	Character::update(deltaTime);

	/*if (getHasBall())
		*/
	//m_seekComponent->setTarget(GameManager::getInstance()->getAgent1());
}

void Agent2::onDeath()
{
	Character::onDeath();

}