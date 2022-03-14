#pragma once
#include "Component.h"

enum Phase {
    PHASEONE,
    PHASETWO,
    PHASETHREE
};
class WanderComponent;
class SpriteComponent;
class MoveComponent;
class StateMachineWMComponent :
    public Component
{
public:

    void start() override;
    void update(float deltatime) override;

    Phase getPhase() { return m_currentPhase; };
    void setPhase(Phase phase) { m_currentPhase = phase; };

    int getEnemiesPoints() { return m_enemiesPoints; };
    void setEnemiesPoints(int points) { m_enemiesPoints = points; };

private:
    WanderComponent* m_wanderComp;
    SpriteComponent* m_spriteComp;
    MoveComponent* m_moveComp;
    Phase m_currentPhase;
    int m_enemiesPoints;
};

