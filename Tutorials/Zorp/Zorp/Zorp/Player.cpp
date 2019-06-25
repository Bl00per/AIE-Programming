#include "Player.h"
#include "GameDefines.h"
#include "Room.h"
#include "Powerup.h"
#include "Enemy.h"
#include "Food.h"
#include <iostream>
#include <algorithm>



Player::Player() : m_mapPosition{ 0,0 }, m_healthPoints{ 100 }, m_attackPoints{ 20 }, m_defendPoints{ 20 }
{
}

Player::Player(int x, int y) : m_mapPosition{ x,y }, m_healthPoints{ 100 }, m_attackPoints{ 20 }, m_defendPoints{ 20 }
{
}

Player::~Player()
{}

void Player::setPosition(const Point2D& position)
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

	//for (auto it = m_powerups.begin(); it < m_powerups.end(); it++)
	//{
	//	std::cout << (*it)->getName() << "\t";
	//}
}

void Player::drawInventory()
{
	std::cout << INDENT;
	for (auto it = m_powerups.begin(); it < m_powerups.end(); it++)
	{
		std::cout << (*it)->getName() << "\t";
	}
	std::cout << std::endl << std::endl;
}

void Player::executeCommand(int command, Room* pRoom)
{
	switch (command)
	{
	case EAST:
		if (m_mapPosition.x < MAZE_WIDTH - 1)
			m_mapPosition.x++;
		return;
	case WEST:
		if (m_mapPosition.x > 0)
			m_mapPosition.x--;
		return;
	case NORTH:
		if (m_mapPosition.y > 0)
			m_mapPosition.y--;
		return;
	case SOUTH:
		if (m_mapPosition.y < MAZE_HEIGHT - 1)
			m_mapPosition.y++;
		return;
	case LOOK:
		if (pRoom->getEnemy() != nullptr)
		{
			std::cout << INDENT << "LOOK OUT! An emey is approaching." << std::endl;
		}
		else if (pRoom->getPowerup() != nullptr)
		{
			std::cout << INDENT << "There is some treasure here. It looks small enough to pick up." << std::endl;
		}
		else if (pRoom->getFood() != nullptr)
		{
			std::cout << INDENT << "There is some food here. It should be edible." << std::endl;
		}
		else
		{
			std::cout << INDENT << "You look around, but see nothing worth mentioning." << std::endl;
		}
		break;
	case FIGHT:
		attack(pRoom->getEnemy());
		break;
	case PICKUP:
		pickup(pRoom);
		break;
	default:
		// The direction was not valid
		// Do nothing, go back to the top of the loop and ask again
		std::cout << INDENT << "You try, but you just can't do it." << std::endl;
		break;
	}
	std::cout << INDENT << "Press 'Enter' to continue.";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
	return;
}

void Player::addPowerup(Powerup* pPowerup)
{
	m_powerups.push_back(pPowerup);

	std::sort(m_powerups.begin(), m_powerups.end(), Powerup::compare);
}

void Player::pickup(Room* pRoom)
{
	if (pRoom->getPowerup() != nullptr)
	{
		std::cout << INDENT << "You pick up the " << pRoom->getPowerup()->getName() << std::endl;
		// Add the powerup to the player's inventory
		addPowerup(pRoom->getPowerup());
		// Remove the powerup from the room
		// (but don't delete it, the player owns it now)
		pRoom->setPowerup(nullptr);
	}
	else if (pRoom->getFood() != nullptr)
	{
		// Eat the food
		m_healthPoints += pRoom->getFood()->getHP();
		std::cout << INDENT << "You feel refreshed. Your health is now " << m_healthPoints << std::endl;
		// Remove the food from the room
		pRoom->setFood(nullptr);
	}
	else
	{
		std::cout << INDENT << "There is nothing here to pickup." << std::endl;
	}
}

void Player::attack(Enemy* pEnemy)
{
	if (pEnemy == nullptr)
	{
		std::cout << INDENT << "There is no one here you can fight with." << std::endl;
	}
	else
	{
		pEnemy->onAttacked(m_attackPoints);

		if (pEnemy->isAlive() == false)
		{
			std::cout << INDENT << "You fight a grue and kill it." << std::endl;
		}
		else
		{
			int damage = pEnemy->getAT() - m_defendPoints;
			m_healthPoints -= damage;

			std::cout << INDENT << "You fight a grue and take " << damage <<
				" points of damage. Your health is now at " << m_healthPoints << std::endl;
			std::cout << INDENT << "The grue has " << pEnemy->getHP() << " health remaining." << std::endl;
		}
	}
}