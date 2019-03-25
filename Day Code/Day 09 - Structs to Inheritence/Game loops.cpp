#include <iostream>

// Game rules: 2 player alternate at entering number between 1 and 50
// after each player has entered 5 numbers, some win condition tbd.
// Player cannot enter the same number as either's previous turns

int main()
{
	bool game_running = true;
	const int min_input = 1;
	const int max_input = 50;

	int player_ones_last_valid = 0;
	int player_twos_last_valid = 0;

	bool player_ones_turn = true;
	
	int turn_counter = 0;
	const int max_turns = 5;

	// Game loop starts here
	while (game_running)
	{		
		// User input and validation
		bool valid = false;
		while (!valid) // This is a whole players turn
		{
			// User instructions
			std::cout << "Player " << (player_ones_turn ? " 1 " : " 2 ") << " please enter a number between "
				<< min_input << " and " << max_input << ":\n";

			// Gather and validate input
			int input = 0;
			std::cin >> input;
			// Clean up the input buffer before validation
			std::cin.clear();
			std::cin.ignore(SHRT_MAX, '\n');

			if (input >= min_input && // Range check
				input <= max_input &&
				input != player_ones_last_valid && // Previous turn check
				input != player_twos_last_valid)
			{
				valid = true;

				// Store correctly
				if (player_ones_turn)
				{
					player_ones_last_valid = input;
				}
				else
				{
					player_twos_last_valid = input;
				}

				// Change player turn
				player_ones_turn = !player_ones_turn;
				if (player_ones_turn)
				{
					++turn_counter;
				}
			}

		}
		// Peasent win condition // Rows, Columns - Win or draw
		if (turn_counter == max_turns)
		{
			game_running = false;
		}

	}

	return 0;
}