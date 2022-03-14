#pragma once
#include "SteeringComponent.h"
class Seek_PLS_Component :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

