#pragma once

class Player
{
public:
	// Constructor
	Player();
	// Overloaded Constructor
	Player(const char* name, float health, int score);
	// Copy Constructor
	Player(const Player& p);

	// Destructor
	~Player();

	// store player's name
	char* m_name;
	// store player's health
	float m_health;
	// store player's score
	int m_score;
};

