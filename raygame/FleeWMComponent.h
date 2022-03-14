#pragma once
#include "Component.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "Actor.h"

class FleeComponent : public SteeringComponent {
public:

	MathLibrary::Vector2 calculateForce() override;

	Actor* getTarget() { return m_target; };
	float  getForce() { return m_force; };

	void setTarget(Actor* target) { m_target = target; };
	void setForce(float force) { m_force = force; };

private:
	Actor* m_target;
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_desiredVelocity;
	float m_force;
};

MathLibrary::Vector2 FleeComponent::calculateForce() {
	getOwner()->getTransform()->setWorldPostion(position);