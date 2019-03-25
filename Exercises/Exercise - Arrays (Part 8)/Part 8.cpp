#include <iostream>
#include <ctime>

int main()
{
	//Player health of 5 characters
	int attack_count = 5;
	const int health_count = 5;
	int player_health[health_count] = { 100,100,100,100,100 };
	int player_choice = 0;

	// Random number generator
	srand((unsigned)time(0));
	int attack_random = 0;
	bool is_valid = false;
	
	while (!is_valid)
	{
		for (int i = 0; i < attack_count; i++)
		{
			//Ask the user to enter a number (0-4) to select a character to be attacked
			std::cout << "Which character would you like to take the blow? (0 - 4): ";
			std::cin >> player_choice;

			if (player_choice > 4 || player_choice < 0)
			{
				std::cout << "Invalid number. Please input a correct number.\n";
			}

			// Deciding attack damage
			for (int index = 0; index < 1; index++)
			{
				attack_random = (rand() % 100 + 1);
			}

			//Dealing damage to the player_choice
			if (player_health[player_choice] < 0)
			{
				std::cout << "That character cannot be attacked anymore\n";
				--i;
			}
			else
			{
				player_health[player_choice] -= attack_random;
				std::cout << "Character " << player_choice << " was hit for " << attack_random << " damage!\n";
			}


			if (attack_count == 5)
			{
				is_valid = true;
			}
		}
	}
	//Printing out all the health

	std::cout << "Final Health Count: \n";
	for (int y = 0; y < health_count; y++)
	{
		std::cout << player_health[y] << std::endl;
	}






	system("Pause");
}