#include "Game.h"
#include "Enemy.h"
#include "Food.h"
#include "Powerup.h"
#include <iostream>
#include <random>
#include <time.h>

Game::Game() : m_gameOver{ false }
{
}

Game::~Game()
{
	delete[] m_powerups;
	delete[] m_enemies;
	delete[] m_food;
}

bool Game::startup()
{
	srand(time(nullptr));

	initializeMap();
	initializeEnemies();
	initializePowerups();
	initializeFood();

	m_player.setPosition(Point2D{ 0,0 });

	return true;
}

void Game::update()
{
	Point2D playerPos = m_player.getPosition();

	if (m_map[playerPos.y][playerPos.x].getType() == EXIT)
	{
		m_gameOver = true;
		return;
	}

	int command = getCommand();

	if (command == QUIT)
	{
		m_gameOver = true;
		return;
	}

	m_player.executeCommand(command, &m_map[playerPos.y][playerPos.x]);

	for (int i = 0; i < m_enemyCount; i++)
	{
		if (m_enemies[i].isAlive() == false)
		{
			Point2D pos = m_enemies[i].getPosition();
			m_map[pos.y][pos.x].setEnemy(nullptr);
		}
	}
}

void Game::draw()
{
	system("cls");

	Point2D playerPos = m_player.getPosition();

	drawWelcomeMessage();

	// List the directions the player can take
	drawValidDirections();

	// Draw the description of the current room
	m_map[playerPos.y][playerPos.x].drawDescription();

	// Redraw the map
	drawMap();

	// Draw the player's inventory
	m_player.drawInventory();
}

bool Game::isGameOver()
{
	return m_gameOver;
}

void Game::drawWelcomeMessage()
{
	std::cout << INDENT << INDENT << "Welcome to ZORP!" << std::endl;
	std::cout << INDENT << "ZORP is a game of adventure, danger, and low cunning." << std::endl;
	std::cout << INDENT << "It is definitely not related to any other text-based adventure game." << std::endl << std::endl;
}

void Game::drawMap()
{
	Point2D position = m_player.getPosition();

	std::cout << std::endl;
	std::cout << std::endl;
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		std::cout << INDENT;
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			if (position.x == x && position.y == y)
			{
				// Draw the player's position on the map
				m_player.draw();
				continue;
			}

			m_map[y][x].draw();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Game::drawValidDirections()
{
	Point2D position = m_player.getPosition();

	// List the directions the player can take
	std::cout << INDENT << "You can see the paths leading to the " <<
		((position.x > 0) ? "west, " : "") <<
		((position.x < MAZE_WIDTH - 1) ? "east, " : "") <<
		((position.y > 0) ? "north, " : "") <<
		((position.y < MAZE_HEIGHT - 1) ? "south, " : "") << std::endl;
}

int Game::getCommand()
{
	// For now, we can't read a command longer than 50 cahracters
	char input[50] = "\0";

	std::cout << INDENT << "Enter a command:" << INDENT;

	// Clear the input buffer, ready for player input
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> input;

	bool bMove = false;
	bool bPickup = false;
	while (input)
	{
		if (strcmp(input, "move") == 0)
		{
			bMove = true;
		}
		else if (bMove = true)
		{
			if (strcmp(input, "north") == 0)
				return NORTH;
			if (strcmp(input, "south") == 0)
				return SOUTH;
			if (strcmp(input, "east") == 0)
				return EAST;
			if (strcmp(input, "west") == 0)
				return WEST;
		}

		if (strcmp(input, "look") == 0)
		{
			return LOOK;
		}

		if (strcmp(input, "fight") == 0)
		{
			return FIGHT;
		}

		if (strcmp(input, "exit") == 0)
		{
			return QUIT;
		}

		if (strcmp(input, "pick") == 0)
		{
			bPickup = true;
		}
		else if (bPickup == true)
		{
			if (strcmp(input, "up") == 0)
				return PICKUP;
		}

		char next = std::cin.peek();
		if (next == '\n' || next == EOF)
			break;
		std::cin >> input;
	}

	return 0;
}


void Game::initializeMap()
{
	// Set room positions
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			m_map[y][x].setPosition(Point2D{ x, y });
		}
	}

	// Set the entrance and exit of the maze
	m_map[0][0].setType(ENTRANCE);
	m_map[MAZE_HEIGHT - 1][MAZE_WIDTH - 1].setType(EXIT);
}

void Game::initializeEnemies()
{
	// Create a dynamic array of enemies
	// (the number of enemies will change every game)
	m_enemyCount = 1 + rand() % 4;
	m_enemies = new Enemy[m_enemyCount];

	// Randomly place the enemies in rooms on the map
	for (int i = 0; i < m_enemyCount; i++)
	{
		// A bit of math ensures the enemies wont spawn directly
		// on or next to the entrance
		int x = 2 + (rand() % (MAZE_WIDTH - 3));
		int y = 2 + (rand() % (MAZE_HEIGHT - 3));

		m_enemies[i].setPosition(Point2D{ x,y });
		m_map[y][x].setEnemy(&m_enemies[i]);
	}
}

void Game::initializePowerups()
{
	// Create some powerups
	m_powerupCount = 3;
	m_powerups = new Powerup[m_powerupCount];

	// Randomly place the powerups in the map
	for (int i = 0; i < m_powerupCount; i++)
	{
		char name[30] = "";
		int x = rand() % (MAZE_WIDTH - 1);
		int y = rand() % (MAZE_HEIGHT - 1);

		float HP = 1;
		float AT = 1;
		float DF = 1;
		
		switch (i)
		{
		case 0:
			strcpy(name, "potion of ");
			m_powerups[i].getHealthMultiplier();
			break;
		case 1:
			strcpy(name, "sword of ");
			m_powerups[i].getAttackMultiplier();
			break;
		case 2:
			strcpy(name, "shield of ");
			m_powerups[i].getDefenceMultiplier();
			break;
		}

		strncat(name, itemNames[(rand() % 15)], 30);
		m_powerups[i].setName(name);
		m_map[y][x].setPowerup(&m_powerups[i]);
	}
}

void Game::initializeFood()
{
	// Create some food
	m_foodCount = 3;
	m_food = new Food[m_foodCount];

	// Randomly place the food in the map
	for (int i = 0; i < m_foodCount; i++)
	{
		int x = rand() % (MAZE_WIDTH - 1);
		int y = rand() % (MAZE_HEIGHT - 1);
		m_map[y][x].setFood(&m_food[i]);
	}
}