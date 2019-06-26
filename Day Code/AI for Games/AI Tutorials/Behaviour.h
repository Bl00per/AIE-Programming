#pragma once

#include "Agent.h"

class Behaviour
{
public:
	// Empty constructors and destructors for base class
	Behaviour() {}
	virtual ~Behaviour() {}

	// Pure virtual function for executing the behaviour
	virtual vector_2 update(Agent* agent, float deltaTime) = 0;
};

