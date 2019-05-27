// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#ifndef _SHIP_H_
#define _SHIP_H_

#include "Entity.h"

class Ship : public Entity
{
public:
	Ship(glm::vec2 position, int points, int power);
	~Ship();

	void reset();
	void damage(int amount);
	void repair();
	
	void setPoints(int points) { m_points = points; }
	void setPower(int power) { m_power = power; }
	void setMaxHealth(int health) { m_health = health; }
	
	bool isShooting() { return m_isShooting; }
		
	int getPoints() { return m_points; }
	int getPower() { return m_power; }
	int getHealth() { return m_health; }
	
	void update(float deltaTime);	

protected:

	int m_points;	// number of points player gets for shooting this ship
	int m_power;
	int m_health;
	int m_maxHealth;
	bool m_isShooting;
	float m_shootTimer;
};

#endif // _SHIP_H_