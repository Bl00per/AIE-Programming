#include <iostream>

int main()
{
	bool something = true;
	bool something_else = false;

	//If something ==true
	if (something)
	{
		std::cout << "Something\n";
	}

	// || if either are true
	if (something || something_else)
	{
		std::cout << "Seomthing OR something_else\n";
	}

	// && only if both/all are true
	if (something && something_else)
	{
		std:cout << "Something and something else\n";
	}

	// || or execute on first true
	// && and exit on first false
	int x = 5;
	int y = 6;
	int z = 7;

	// A
	if (x <= y)
	{
		std::cout << "A";
	}
	// B
	else if (x <= z)
	{
		std::cout << "B";
	}
	// C
	else // catch all
	{
		std::cout << "C";
	}

	char option = 0;
	option = std::cin.get();
	//std::cin >> option

	// Takes a int as type, including char
	switch ()
	{
	case 'a':
		break;
	case 'b':
		break;
	case 'c':
		break;
	default:
		std::cout << "a, b, or c not chosen\n";
		break;
	}

	return 0;
}