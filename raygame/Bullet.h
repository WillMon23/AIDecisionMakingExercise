#pragma once
#include "Agent.h"
class Bullet : public Agent  {
public:
	void start() override;
	void update(float) override;
};
