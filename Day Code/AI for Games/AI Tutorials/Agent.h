#pragma once

#include "Renderer2D.h"
#include "vector_2.h"
#include <vector>

class Behaviour;

class Agent
{
public:
	Agent(aie::Texture* texture, float x, float y);
	~Agent();

	// Update the agent and its behaviours
	virtual void update(float deltaTime);

	// Draw the agent
	virtual void draw(aie::Renderer2D* renderer);

	// Add a behaviour to the agent
	void AddBehaviour(Behaviour* behaviour);

protected:
	std::vector<Behaviour*> m_BehaviourList;
	aie::Texture* m_texture;

public:
	float m_maxSpeed;

	vector_2 m_acceleration;
	vector_2 m_position;
	vector_2 m_velocity;
};

