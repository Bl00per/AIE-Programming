#pragma once

#include "Behaviour.h"

class KeyboardBehaviour : public Behaviour
{
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();

	virtual vector_2 update(Agent* agent, float deltaTime);
};

