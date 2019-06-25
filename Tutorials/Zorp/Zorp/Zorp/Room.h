#pragma once
#include "Point2D.h"

class Powerup;
class Player;
class Enemy;
class Food;

class Room
{
public:
	Room();
	~Room();

	void setPosition(Point2D position);
	void setType(int type); 
	void setEnemy(Enemy* pEnemy) { m_enemy = pEnemy; }
	void setPowerup(Powerup* pPowerup) { m_powerup = pPowerup; }
	void setFood(Food* pFood) { m_food = pFood; }

	int getType();
	Enemy* getEnemy() { return m_enemy; }
	Powerup* getPowerup() { return m_powerup; }
	Food* getFood() { return m_food; }

	void draw();
	void drawDescription();

private:
	Point2D m_mapPosition;
	int m_type;

	Powerup* m_powerup;
	Enemy* m_enemy;
	Food* m_food;
};

