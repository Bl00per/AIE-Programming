#include <iostream>

int main()
{
	char choice = '0';
	std::cin >> choice;

	switch (choice)
	{
	case '1':
		std::cout << "1" << std::endl;
		break;
	case '2':
		std::cout << "2 or 3" << std::endl;
		break;
	case '3':
		std::cout << "2 or 3" << std::endl;
		break;
	case '4':
		std::cout << "4" << std::endl;
		break;
	default:
		std::cout << "Invalid" << std::endl;
		break;
	}

	int x;
	int y = 0;

	std::cout << "Enter x." << std::endl;
	std::cin >> x;

	y = (x == 0) ? 0 : 10 / x;
	std::cout << "Y is equal to " << y << std::endl;


	system("Pause");
	std::cin.get();

	return 0;
}