#include "SeekBehaviour.h"

SeekBehaviour::SeekBehaviour(Agent* target) : m_target(target)
{
}


SeekBehaviour::~SeekBehaviour()
{
}

void SeekBehaviour::update(Agent* agent, float deltaTime)
{
	vector_2 direction = (m_target->m_position - agent->m_position).normalised();

	agent->m_acceleration = direction * agent->m_maxSpeed * deltaTime;
}