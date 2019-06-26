#include "SeekBehaviour.h"

SeekBehaviour::SeekBehaviour()
{
}


SeekBehaviour::~SeekBehaviour()
{
}

vector_2 SeekBehaviour::update(Agent* agent, float deltaTime)
{
	if (m_target == nullptr)
		return vector_2{ 0,0 };

	//Get this agent’s position
	agent->GetPosition();
	//Get the position of the target agent
	m_target->GetPosition();

	//Calculate the vector describing the direction to the target and normalize it
	vector_2 direction = m_target->GetPosition() - agent->GetPosition();
	direction.normalise();
	//Multiply the direction by the speed we want the agent to move
	direction *= 5.0f;
	//Subtract the agent’s current velocity from the result to get the force we need to apply
	vector_2 force = m_target->GetVelocity() - direction;
	//return the force
	return force;
}