#include "Room.h"
#include "GameDefines.h"
#include <iostream>

Room::Room()
{
	m_type = EMPTY;
	m_mapPosition.x = 0;
	m_mapPosition.y = 0;
}

Room::~Room()
{
}

void Room::setPosition(Point2D position)
{
	m_mapPosition = position;
}

void Room::setType(int type)
{
	m_type = type;
}

int Room::getType()
{
	return m_type;
}

void Room::draw()
{
	switch (m_type)
	{
	case EMPTY:
		std::cout << EMPTY_TILE;
		break;
	case ENEMY:
		std::cout << ENEMY_TILE;
		break;
	case TREASURE:
		std::cout << TREASURE_TILE;
		break;
	case FOOD:
		std::cout << FOOD_TILE;
		break;
	case ENTRANCE:
		std::cout << ENTRANCE_TILE;
		break;
	case EXIT:
		std::cout << EXIT_TILE;
		break;
	}
}

void Room::drawDescription()
{
	// Write description of current room
	switch (m_type)
	{
	case EMPTY:
		std::cout << INDENT << "You are in an empty meadow. There is nothing of note here." << std::endl;
		break;
	case ENEMY:
		std::cout << INDENT << "BEWARE. An enemy is approaching." << std::endl;
		break;
	case TREASURE:
		std::cout << INDENT << "Your journey has been rewarded. You have found some treasure" << std::endl;
		break;
	case FOOD:
		std::cout << INDENT << "At last! You collect some food to sustain you on your journey." << std::endl;
		break;
	case ENTRANCE:
		std::cout << INDENT << "The entrance you used to enter this maze is blocked. There is no going back." << std::endl;
		break;
	case EXIT:
		std::cout << INDENT << "Despite all odds, you made it to the exit. Congratulations." << std::endl;
		break;
	}
}

bool Room::executeCommand(int command)
{
	// Update the player's position using the input movement data
	switch (command)
	{
	case LOOK:
		std::cout << INDENT << "You look around, but see notihing worth mentioning" << std::endl;
		std::cout << INDENT << "Press 'Enter' to continue.";
		waitForInput();
		break;
	case FIGHT:
		std::cout << INDENT << "You could try to fight, but you don't have a weapon." << std::endl;
		std::cout << INDENT << "Press 'Enter' to continue.";
		waitForInput();
		break;
	default:
		std::cout << INDENT << "You try, but you just can't do it." << std::endl;
		std::cout << INDENT << "Press 'Enter' to continue.";
		waitForInput();
		break;
	}
	return false;
}

void Room::waitForInput()
{
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
}