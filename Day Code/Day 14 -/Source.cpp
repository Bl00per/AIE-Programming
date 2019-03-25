#include <iostream>
#include "Player.h"

int main()
{
	Player* p1 = new Player("Iron-man", 100.0f, 10);
	Player* p2 = new Player();

	delete p1;

	std::cout << p2->m_name << std::endl;

	return 0;
}