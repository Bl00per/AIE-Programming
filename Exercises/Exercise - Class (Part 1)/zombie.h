#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>


class zombie
{
public:
	// (Default) Constructor (Because no arguments)
	zombie();

	// User Constructor at instatiation
	zombie(int a_health, int a_attack, std::string a_occupation);

	// Destructor
	~zombie();

	// Member Function
	// Writes member data to console
	void to_console() const;

	/*Accessors*/
	// Const int - Don't alter the returned value
	// () const - function does not change the object
	const int get_health() const;
	const int get_attack_value() const;
	const std::string get_occupation() const;

	/*Setters*/
	void set_health(int a_health);
	void set_attack_value(int a_attack_value);

	void attack(zombie& a_zombie) const;

private:
	// Whole number of remaining hitpoints
	int m_health;
	// Whole number of attack points
	int m_attack;
	// Previous job description 
	std::string m_occupation;

	void take_damage(const int a_damage);

};

#endif // !ZOMBIE _H
