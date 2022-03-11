#pragma once
#include "Component.h"
class StateMachineWMComponent :
    public Component
{
public:

    void start() override;
    void update(float deltatime) override;


};

