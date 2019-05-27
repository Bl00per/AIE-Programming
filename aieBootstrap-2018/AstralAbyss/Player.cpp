// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#include "Player.h"
#include "Input.h"
#include "Animation.h"
#include "defines.h"
#include <Renderer2D.h>

Player::Player() : Entity("./textures/ship_1.png", 2, 0.2f)
{
	m_upgrade1 = new Animation("./textures/ship_2.png", 2, 0.2f);
	m_upgrade2 = new Animation("./textures/ship_3.png", 2, 0.2f);

	reset();
}

Player::~Player()
{
	// Input memory handled externally
}

void Player::reset()
{
	m_maxHealth = 12;
	m_health = m_maxHealth;
	m_upgradeLevel = 1;
	m_maxUpgrade = 3;
	m_score = 0;
	m_speed = 100.0f;
	m_isAlive = true;
	m_isShooting = false;
	m_cooldownTimer = 0;
}

void Player::addPoints(int amount)
{
	m_score += amount;

	if (m_score > SCORE_LIMIT)
	{
		m_score = SCORE_LIMIT;
	}
}

void Player::removePoints(int amount)
{
	m_score -= amount;

	if (m_score < 0)
	{
		m_score = 0;
	}
}

void Player::damage(int amount)
{
	m_health -= amount;

	if (m_health < 1)
	{
		m_health = 0;
		impairShip();
	}
}

void Player::upgradeShip()
{
	if (m_upgradeLevel < m_maxUpgrade)
	{
		m_upgradeLevel++;
	}
}

void Player::impairShip()
{
	if (m_upgradeLevel > 0)
	{
		m_upgradeLevel--;
	}
	m_hasDied = true;
	m_isAlive = false;
}

void Player::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	m_hasDied = false;
	if (m_isAlive == false)
		return;

	// Horizontal movement input and extremes
	if (input->isKeyDown(aie::INPUT_KEY_LEFT)) // West
	{
		m_velocity.x = -m_speed;
		if (m_position.x < 0)
		{
			m_position.x = 0;
		}
	}
	else if (input->isKeyDown(aie::INPUT_KEY_RIGHT)) // East
	{
		m_velocity.x = m_speed;
		if (m_position.x > SCREEN_WIDTH)
		{
			m_position.x = SCREEN_WIDTH;
		}
	}
	else
	{
		m_velocity.x = 0.0f;
	}

	// Vertical movement input and extremes
	if (input->isKeyDown(aie::INPUT_KEY_UP)) // North
	{
		m_velocity.y = m_speed;
		if (m_position.y > MAX_Y_MOVE)
		{
			m_position.y = MAX_Y_MOVE;
		}
	}
	else if (input->isKeyDown(aie::INPUT_KEY_DOWN)) // South
	{
		m_velocity.y = -m_speed;
		if (m_position.y < MIN_Y_MOVE)
		{
			m_position.y = MIN_Y_MOVE;
		}
	}
	else
	{
		m_velocity.y = 0.0f;
	}

	// Shooting input
	m_isShooting = false;
	m_cooldownTimer += deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && m_cooldownTimer > SHOOT_COOLDOWN)
	{
		m_isShooting = true;
		m_cooldownTimer = 0;
	}

	Entity::update(deltaTime); // Call base function
}


void Player::draw(aie::Renderer2D* renderer)
{
	if (m_isAlive == false)
		return;

	renderer->setRenderColour(m_colour.r, m_colour.b, m_colour.g, m_colour.a);

	switch (m_upgradeLevel)
	{
	case 1:
		m_animation->draw(renderer, m_position.x, m_position.y);
		break;
	case 2:
		m_upgrade1->draw(renderer, m_position.x, m_position.y);
		break;
	case 3:
		m_upgrade2->draw(renderer, m_position.x, m_position.y);
		break;
	}
}