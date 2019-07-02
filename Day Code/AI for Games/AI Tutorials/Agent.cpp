#include "Agent.h"
#include "Behaviour.h"

Agent::Agent(aie::Texture* texture, float x, float y) : m_texture(texture)
{
	m_position.x = x;
	m_position.y = y;
}


Agent::~Agent()
{
	for (auto it = m_BehaviourList.begin(); it != m_BehaviourList.end(); it++)
	{
		delete (*it);
	}
}

void Agent::AddBehaviour(Behaviour* behaviour)
{
	m_BehaviourList.push_back(behaviour);
}

void Agent::update(float deltaTime)
{
	for (auto it = m_BehaviourList.begin(); it != m_BehaviourList.end(); it++)
	{
		(*it)->update(this, deltaTime);
	}

	m_velocity.x += m_acceleration.x;
	m_velocity.y += m_acceleration.y;

	// Check if the vecolity is greater than the maxspeed for X position
	if (m_velocity.x > m_maxSpeed)
	{
		m_velocity.x = m_maxSpeed;
	}	
	else if (m_velocity.x < -m_maxSpeed)
	{
		m_velocity.x < -m_maxSpeed;
	}
	// Check if velocity is greater than the maxspeed for Y position
	else if (m_velocity.y > m_maxSpeed)
	{
		m_velocity.y = m_maxSpeed;
	}	
	else if (m_velocity.y < -m_maxSpeed)
	{
		m_velocity.y < -m_maxSpeed;
	}

	// Boundry check X
	if (m_position.x >= 1280)
	{
		m_position.x = 1280;
		m_acceleration = 0;
	}
	else if (m_position.x <= 0)
	{
		m_position.x = 0;
		m_acceleration = 0;
	}
	
	// Boundry check Y
	if (m_position.y >= 1280)
	{
		m_position.y = 1280;
		m_acceleration = 0;
	}
	else if (m_position.y <= 0)
	{
		m_position.y = 0;
		m_acceleration = 0;
	}

	m_acceleration.x = 0;
	m_acceleration.y = 0;

	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;
}

void Agent::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(m_texture, m_position.x, m_position.y);
}
