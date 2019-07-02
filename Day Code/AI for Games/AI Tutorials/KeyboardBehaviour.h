#pragma once

#include "Behaviour.h"

class KeyboardBehaviour : public Behaviour
{
public:
	KeyboardBehaviour();
	~KeyboardBehaviour();

	void update(Agent* agent, float deltaTime);
};

