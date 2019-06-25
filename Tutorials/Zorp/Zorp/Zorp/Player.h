#pragma once
#include "Point2D.h"
#include <vector>

class Powerup;
class Room;
class Enemy;

class Player
{
public:
	Player();
	Player(int x, int y);
	~Player();

	void addPowerup(Powerup* pPowerup);

	void setPosition(const Point2D& position);
	Point2D getPosition();
	void draw();
	void drawInventory();
	void executeCommand(int command, Room* pRoom);



private:
	void pickup(Room* pRoom);
	void attack(Enemy* pEnemy);

	Point2D m_mapPosition;

	std::vector<Powerup*> m_powerups;

	int m_healthPoints;
	int m_attackPoints;
	int m_defendPoints;
};

