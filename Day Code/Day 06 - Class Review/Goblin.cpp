#include "Goblin.h"
#include <iostream>


Goblin::Goblin(char a_name[], int a_health)
{
	health = a_health;
	strcpy(name, a_name); // Deep copy of the character array

}


const int Goblin::get_health() const
{
	return health;
}

const char* const Goblin::get_name() const
{
	return name;
}

const int Goblin::get_damage() const
{
	return damage;
}

void Goblin::attack(Goblin& a_target) const
{
	a_target.health -= damage;
	std::cout << name << " damages " << a_target.name <<
		" for " << damage << ".\n";
}
