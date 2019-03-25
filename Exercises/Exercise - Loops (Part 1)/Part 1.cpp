#include <iostream>

int main()
{

	std::cout << "100 to 0" << std::endl;
	std::cin.get();

	for (int index = 100; index >= 0; --index)
	{
		std::cout << index << std::endl;
	}

	std::cout << "Inlcude 0 but not 100" << std::endl;
	std::cin.get();

	for (int index = 99; index >= 0; --index)
	{
		std::cout << index << std::endl;
	}

	std::cout << "Inlcude 100 but not 0" << std::endl;
	std::cin.get();

	for (int index = 100; index > 0; --index)
	{
		std::cout << index << std::endl;
	}

	std::cout << "Decrement by 2" << std::endl;
	std::cin.get();

	for (int index = 100; index >= 0; index -= 2)
	{
		std::cout << index << std::endl;
	}

	system("Pause");
	std::cin.get();

	return 0;
}