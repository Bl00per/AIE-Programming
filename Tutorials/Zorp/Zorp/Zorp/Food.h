#pragma once

class Food {
public:
	Food() : m_healthPoints{ 10 } {}
	~Food() {}

	int getHP() { return m_healthPoints; }

private:
	int m_healthPoints;
};