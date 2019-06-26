#pragma once

#include "Renderer2D.h"
#include "Behaviour.h"
#include "vector_2.h"
#include <vector>

class Agent
{
public:
	Agent();
	virtual ~Agent();

	// Update the agent and its behaviours
	virtual void update(float deltaTime);

	// Draw the agent
	virtual void draw(aie::Renderer2D* renderer);

	// Add a behaviour to the agent
	void AddBehaviour(Behaviour* behaviour);

	// Movement functions
	void SetPosition(vector_2 position) { m_position = position; }
	vector_2 GetPosition() { return m_position; }
	void SetVelocity(vector_2 velocity) { m_velocity = velocity; }
	vector_2 GetVelocity() { return m_velocity; }

protected:
	std::vector<Behaviour*> m_BehaviourList;

	Behaviour* m_behaviour;

	vector_2 m_position;
	vector_2 m_velocity;
};

