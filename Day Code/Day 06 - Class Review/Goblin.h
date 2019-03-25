#pragma once

// Global const buffer length
const size_t buffer_length = 80;

class Goblin
{
public:
	// Can only make fully formed goblins
	Goblin(char a_name[], int a_health);

	// Prevent blank initialization
	Goblin() {}; // = delete;

	// Name and Health Accessors
	const int get_health() const;
	const char* const get_name() const;
	const int get_damage() const;

	// Deal this goblins damage to another goblin
	void attack(Goblin& a_target) const;

private:
	int health = 0; // Whole number
	char name[buffer_length]{ '\0' };
	int damage = 2;
};




