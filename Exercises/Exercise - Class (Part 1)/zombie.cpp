#include "zombie.h"

#include <iostream>

// Automatically called on instatiation
zombie::zombie()
{
	// Default values
	m_health = 5;
	m_attack = 1;
	m_occupation = "Lawyer";

	std::cout << "Constructor Called\n";
}

zombie::zombie(int a_health, int a_attack, std::string a_occupation)
{
	m_health = a_health;
	m_attack = a_attack;
	m_occupation = a_occupation;

	std::cout << "User Constructor Called\n";
}

// Automatically called when object goes out of screen
zombie::~zombie()
{
	std::cout << "Destructor Called\n";
}

// If cpy/paste
// 1. Remove semicolon
// 2. Scope function
// 3. { }
void zombie::to_console() const
{
	std::cout << get_health() << std::endl;
	std::cout << get_attack_value() << std::endl;
	std::cout << get_occupation() << std::endl;
}

/* Returns a read only copy of the current health
   without changing the zombie*/
const int zombie::get_health() const
{
	return m_health;
}

const int zombie::get_attack_value() const
{
	return m_attack;
}

const std::string zombie::get_occupation() const
{
	return m_occupation; // A const protected copy of a string
}

void zombie::set_health(const int a_health)
{
	m_health = a_health;
}
void zombie::set_attack_value(const int a_attack_value)
{
	m_attack = a_attack_value;
}

void zombie::take_damage(const int a_damage)
{
	m_health -= a_damage;
	if (m_health < 0)
	{
		m_health = 0;
	}
}

void zombie::attack(zombie& a_zombie) const
{
	a_zombie.take_damage(m_attack);
}