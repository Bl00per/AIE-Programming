#include "Enemy.h"

void Enemy::onAttacked(int attackPoints)
{
	m_healthPoints -= attackPoints - m_defendPoints;
	if (m_healthPoints < 0)
		m_healthPoints = 0;
}
