#include <iostream>
#include "Game.h"


void main()
{
	Game game;

	if (game.startup() == false)
		return;

	// Game loop
	while (!game.isGameOver())
	{
		game.draw();

		game.update();
	} // End game loop

	std::cout << std::endl << INDENT << "Press 'Enter' to exit the program.";
	std::cin.clear(); 
	std::cin.ignore(std::cin.rdbuf()->in_avail()); 
	std::cin.get();
}

