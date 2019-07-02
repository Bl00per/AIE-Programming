#pragma once

#include "Behaviour.h"

class Agent;

class SeekBehaviour : public Behaviour
{
public:
	SeekBehaviour(Agent* target);
	~SeekBehaviour();

	void update(Agent* agent, float deltaTime);

private:
	Agent* m_target;
};

