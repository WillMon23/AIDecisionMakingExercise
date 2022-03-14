#pragma once
#include "SteeringComponent.h"
class WanderComponent :
    public SteeringComponent
{
public:
    WanderComponent(float circleDistance, float circleRadius, float wanderForce);
    WanderComponent();
    MathLibrary::Vector2 calculateForce() override;

    void setCircleDistance(float value) { m_circleDistance = value; };
    void setCircleRadius(float value) { m_circleRadius = value; };

private:
    float m_circleDistance = 0;
    float m_circleRadius = 0;
    float m_wanderAngle = 0;

    MathLibrary::Vector2 m_target;
    MathLibrary::Vector2 m_circlePos;

};

