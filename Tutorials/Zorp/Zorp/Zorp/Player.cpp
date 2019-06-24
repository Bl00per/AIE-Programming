#include "Player.h"
#include "GameDefines.h"
#include <iostream>



Player::Player()
{
	m_mapPosition.x = 0;
	m_mapPosition.y = 0;
}

Player::Player(int x, int y)
{
	m_mapPosition.x = x;
	m_mapPosition.y = y;
}

Player::~Player()
{
}

void Player::setPosition(Point2D position)
{
	m_mapPosition = position;
}

Point2D Player::getPosition()
{
	return m_mapPosition;
}

void Player::draw()
{
	std::cout << PLAYER_TILE;
}

bool Player::executeCommand(int command)
{
	switch (command)
	{
	case EAST:
		if (m_mapPosition.x < MAZE_WIDTH - 1)
			m_mapPosition.x++;
		return true;
	case WEST:
		if (m_mapPosition.x > 0)
			m_mapPosition.x--;
		return true;
	case NORTH:
		if (m_mapPosition.y > 0)
			m_mapPosition.y--;
		return true;
	case SOUTH:
		if (m_mapPosition.y < MAZE_HEIGHT - 1)
			m_mapPosition.y++;
		return true;
	}
	return false;
}