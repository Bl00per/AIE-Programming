#include "Player.h"
#include <iostream>
#include <cstring>

Player::Player()
{
	std::cout << "Default constructor" << std::endl;
	// created a character array on the heap (free-storage)
	// m_name holds the memory address of the new character array on the heap
	m_name = new char[10];
	strcpy(m_name, "");
	m_health = 0.0f;
	m_score = 0;
}

Player::Player(const char* name, float health, int score)
{
	std::cout << "Overloaded constructor" << std::endl;
	// get the size of the name
	int bufferSize = strlen(name);
	// created a character array on the heap (free-storage)
	// m_name holds the memory address of the new character array on the heap
	// size of the array will be based on characters in the name
	m_name = new char[bufferSize + 1];
	// copy the name to the variable
	strcpy(m_name, name);

	m_health = health;
	m_score = score;
}

Player::Player(const Player & p)
{
	std::cout << "Copy constructor" << std::endl;
	
	// set this is true for shallow copy, false for deep copy
	bool shallowCopy = true;

	// shallow copy
	if (shallowCopy) 
	{
		std::cout << "doing Shallow copy" << std::endl;
		// stores the same memory address of another player's name
		m_name = p.m_name;
		m_health = p.m_health;
		m_score = p.m_score;
	}

	// deep copy
	else 
	{
		std::cout << "doing deep copy" << std::endl;
		int bufferSize = strlen(p.m_name);
		// created a character array on the heap (free-storage)
		// m_name holds the memory address of the new character array on the heap
		m_name = new char[bufferSize + 1];
		// copying the name (just the value) from another player
		strcpy(m_name, p.m_name);
		m_health = p.m_health;
		m_score = p.m_score;
	}
}


Player::~Player()
{
	std::cout << "Destructor" << std::endl;
	// deletes the name
	delete m_name;
	m_name = nullptr;
}
