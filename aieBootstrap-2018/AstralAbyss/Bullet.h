// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#ifndef _BULLET_H_
#define _BULLET_H_

#include "Entity.h"

enum BULLET_TYPE
{
	ENEMY_BULLET,
	PLAYER_LEVEL1,
	PLAYER_LEVEL2,
	PLAYER_LEVEL3,
};

class Bullet : public Entity
{
public:
	Bullet(glm::vec2 position, BULLET_TYPE type, int damage, glm::vec2 velocity);			// equates to the 'power' of the ship that fires the bullet
	~Bullet();

	unsigned int getDamage() { return m_damage; }
	bool isEnemyBullet() { return (m_type == ENEMY_BULLET) ? true : false; }

	void update(float deltaTime);

private:
	unsigned int m_damage;
	BULLET_TYPE m_type;
};

#endif // _BULLET_H_