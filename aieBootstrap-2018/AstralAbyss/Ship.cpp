// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#include "Ship.h"
#include "defines.h"

Ship::Ship(glm::vec2 position, int points, int power) : Entity("./textures/enemy_1.png", 2, 0.2f),
	m_points(points), m_power(power)
{
	m_position = position;
	m_colour = glm::vec4(1, 0, 0, 1);
	m_maxHealth = 1;
	m_health = m_maxHealth;
	m_velocity = glm::vec2(-50.0f, 0);
	m_isAlive = true;
	m_isShooting = false;	
	m_shootTimer = 0;
}

Ship::~Ship()
{
}

void Ship::reset()
{
}

void Ship::damage(int amount)
{
	m_health -= amount;

	if (m_health < 1)
	{
		m_health = 0;
	}
}

void Ship::repair()
{
	m_health = m_maxHealth;
}

void Ship::update(float deltaTime) 
{
	// Check location and health
	if (m_position.x < 0.0f - m_size.x)
	{
		m_isAlive = false;
	}

	if (m_health == 0)
	{
		m_isAlive = false;
	}

	// Shooting
	m_isShooting = false;
	m_shootTimer += deltaTime;
	if (m_shootTimer > ENEMY_SHOOT_COOLDOWN)
	{
		m_isShooting = true;
		m_shootTimer = 0;
	}

	Entity::update(deltaTime); // Call base function
}
