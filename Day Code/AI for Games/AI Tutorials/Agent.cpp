#include "Agent.h"



Agent::Agent()
{
}


Agent::~Agent()
{
}


void Agent::update(float deltaTime)
{
	m_velocity = 0.0f;

	for (int i = 0; i < m_BehaviourList.size(); i++)
	{
		m_behaviour->update(deltaTime);
	}
}

void Agent::draw(aie::Renderer2D* renderer)
{
	renderer->drawBox(m_position.x, m_position.y, 10, 10);
}