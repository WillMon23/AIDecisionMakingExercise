#pragma once
#include "Component.h"

class WanderComponent;
class StateMachineWMComponent :
    public Component
{
public:

    void start() override;
    void update(float deltatime) override;

private:
    WanderComponent* m_wanderComp;
};

