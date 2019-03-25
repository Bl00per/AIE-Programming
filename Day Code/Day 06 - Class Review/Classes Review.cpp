#include "Goblin.h"
#include <iostream>

int main()
{
	const size_t clan_size = 3;
	const int default_health = 5;

	Goblin clan[clan_size];

	std::cout << "Enter the names of " << clan_size << " Goblins:\n";
	for (size_t index = 0; index < clan_size; index++)
	{
		std::cout << "Enter a name: ";
		char buffer[buffer_length];
		std::cin.getline(buffer, buffer_length);

		int input_health = 0;
		bool valid_input = false;
		while (!valid_input)
		{
			std::cout << "Enter health for " << buffer << ": ";
			std::cin >> input_health;

			if (input_health > 0) // SANITY CHECK!
			{
				valid_input = true;
			}

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}

		clan[index] = Goblin(buffer, input_health);
		std::cout << clan[index].get_name() << " with " 
			<< clan[index].get_health() << " health has been created.\n";
	}

	// Dirty fighting
	clan[0].attack(clan[1]);
	clan[1].attack(clan[0]);

	system("Pause");
	return 0;
}