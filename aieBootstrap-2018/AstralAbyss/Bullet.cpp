// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#include "Bullet.h"
#include "Animation.h"
#include "defines.h"

Bullet::Bullet(glm::vec2 position, BULLET_TYPE type, int damage, glm::vec2 velocity) : m_damage(damage)
{
	m_position = position;
	m_velocity = velocity;
	m_type = type;

	switch (type)
	{
	case ENEMY_BULLET:
		setAnimation("./textures/enemy_bullet_1.png", 1, 1);
		break;
	case PLAYER_LEVEL1:
		setAnimation("./textures/ship_bullet_1.png", 1, 1);
		break;
	case PLAYER_LEVEL2:
		setAnimation("./textures/ship_bullet_2.png", 1, 1);
		break;
	case PLAYER_LEVEL3:
		setAnimation("./textures/ship_bullet_3.png", 1, 1);
		break;
	}
	
}

Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime)
{
	Entity::update(deltaTime); // Call base function

	// Check Extremes
	if (m_position.x < 0) {
		m_isAlive = false;
	}
	
	if (m_position.x > SCREEN_WIDTH) {
		m_isAlive = false;
	}

	if (m_position.y < 0) {
		m_isAlive = false;
	}

	if (m_position.y > SCREEN_HEIGHT) {
		m_isAlive = false;
	}	
}