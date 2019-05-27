// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"

class Player : public Entity
{
public:
	static const int SCORE_LIMIT = 999999;

	Player();
	~Player();

	void addPoints(int points);
	void removePoints(int points);

	void damage(int amount);

	void reset();
	void upgradeShip();
	void impairShip();
	
	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

	int getUpgradeLevel() { return m_upgradeLevel; }
	int getScore() { return m_score; }
	int getHealth() { return m_health; }

	bool hasDied() { return m_hasDied; }		// has the player died during the last update
	bool isShooting() { return m_isShooting; }

private:
	Animation* m_upgrade1;
	Animation* m_upgrade2;

	int m_upgradeLevel;
	int m_maxUpgrade;

	int m_score;
		
	int m_power;
	int m_health;
	int m_maxHealth;
	float m_speed;

	bool m_isShooting;
	float m_cooldownTimer;

	bool m_hasDied;		// different from m_isAlive. hasDied lets us know if the player just died during the last update
};

#endif // _PLAYER_H_