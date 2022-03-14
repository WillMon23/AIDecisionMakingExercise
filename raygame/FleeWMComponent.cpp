#include "FleeWMComponent.h"

void FleeComponent::update(float deltaTime) {
	Component::update(deltaTime);

	if (getActive())
	{
		//Sets the owener position to this veriable
		MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();
		//Sets max speed for easy access 
		setForce(20.0f);

		m_velocity = getOwner()->getComponent<MoveComponent>()->getVelocity().getNormalized();

		//Tries to creat a desired velocity bey getiing the targets curent position and subtracting that by 
		m_desiredVelocity = (position - getTarget()->getTransform()->getWorldPosition()).getNormalized();

		//After getiing the desired velocity multiply that velocty by a force 
		m_desiredVelocity = m_desiredVelocity * getForce();

		//
		MathLibrary::Vector2 steeringForce = m_desiredVelocity + m_velocity;

		m_velocity = m_velocity + steeringForce * deltaTime * getForce();

		position = position + m_velocity * deltaTime;

		getOwner()->getTransform()->setWorldPostion(position);
	}
}