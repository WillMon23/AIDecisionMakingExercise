#pragma once
#include "Component.h"

enum State
{
	IDLE,
	WANDER,
	SEEK
};

class Seek_PLS_Component;
class Wander_PLS_Component;

class StateMachine_PLS_Component :
	public Component
{
public:
	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }

	void start() override;
	void update(float deltaTime) override;

private:
	State m_currentState;
	Seek_PLS_Component* m_seekComponent;
	//Wander_PLS_Component* m_wanderComponent;
	float m_seekForce;
	float m_wanderForce;
	float m_seekRange = 800;
};

