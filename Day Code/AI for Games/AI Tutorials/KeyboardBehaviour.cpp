#include "KeyboardBehaviour.h"
#include "Input.h"

KeyboardBehaviour::KeyboardBehaviour()
{
}


KeyboardBehaviour::~KeyboardBehaviour()
{
}

void KeyboardBehaviour::update(Agent* agent, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	// If either UP or DOWN is pressed, apply a force to the acceleration in the Y position
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		agent->m_acceleration.y += agent->m_maxSpeed * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		agent->m_acceleration.y -= agent->m_maxSpeed * deltaTime;

	// If neither are pressed then reduce the acceleration
	if (!(input->isKeyDown(aie::INPUT_KEY_UP)) && !(input->isKeyDown(aie::INPUT_KEY_DOWN)))
	{
		agent->m_acceleration.y -= agent->m_velocity.y * deltaTime;
	}

	// If either LEFT or RIGHT is pressed, apply a force to the acceleration in the X position
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		agent->m_acceleration.x -= agent->m_maxSpeed * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		agent->m_acceleration.x += agent->m_maxSpeed * deltaTime;

	// If neither are pressed then reduce the acceleration
	if (!(input->isKeyDown(aie::INPUT_KEY_LEFT)) && !(input->isKeyDown(aie::INPUT_KEY_RIGHT)))
	{
		agent->m_acceleration.x -= agent->m_velocity.x * deltaTime;
	}
}
