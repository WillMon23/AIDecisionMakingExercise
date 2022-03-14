#pragma once
#include "Component.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "Actor.h"

class FleeComponent : public Component {
public:
	void update(float deltaTime)override;

	Actor* getTarget() { return m_target; };
	float  getForce() { return m_force; };

	void setTarget(Actor* target) { m_target = target; };
	void setForce(float force) { m_force = force; };

	bool getActive() { return m_active; };
	void setActive(bool active) { m_active = active; }

private:
	Actor* m_target;
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_desiredVelocity;
	bool m_active = false;
	float m_force;
};

