#pragma once

#include "Behaviour.h"

class SeekBehaviour : public Behaviour
{
public:
	SeekBehaviour();
	virtual ~SeekBehaviour();

	virtual vector_2 update(Agent* agent, float deltaTime);
	void SetTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target;
};

