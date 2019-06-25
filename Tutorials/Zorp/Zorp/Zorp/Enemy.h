#pragma once
#include "Point2D.h"

class Enemy
{
public:
	Enemy() : m_healthPoints{ 20 }, m_attackPoints{ 10 }, m_defendPoints{ 5 } {}
	~Enemy() {};

	void setPosition(const Point2D& position) { m_mapPosition = position; }
	Point2D getPosition() { return  m_mapPosition; }

	int getHP() { return m_healthPoints; }
	int getAT() { return m_attackPoints; }
	int getDF() { return m_defendPoints; }

	bool isAlive() { return (m_healthPoints > 0); }

	void onAttacked(int attackPoints);

private:
	Point2D m_mapPosition;

	int m_healthPoints;
	int m_attackPoints;
	int m_defendPoints;
};

