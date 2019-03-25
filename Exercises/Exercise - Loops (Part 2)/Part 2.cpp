#include <iostream>

int main()
{

	std::cout << "0 to 100" << std::endl;
	std::cin.get();

	for (int index = 0; index <= 100; ++index)
	{
		std::cout << index << std::endl;
	}

	std::cout << "Print Fizz for multiples of 3" << std::endl;
	std::cin.get();

	for (int index = 0; index <= 100; ++index)
	{
		if (index % 3 == 0)
		{
			std::cout << "Fizzy boy" << std::endl;
		}
		std::cout << index << std::endl;
	}

	std::cout << "Print Buzz for multiples of 5" << std::endl;
	std::cin.get();

	for (int index = 0; index <= 100; ++index)
	{
		if (index % 5 == 0)
		{
			std::cout << "Buzzy boy" << std::endl;
		}
		std::cout << index << std::endl;
	}

	std::cout << "Print FizzBuzz for multiples of 3 and 5" << std::endl;
	std::cin.get();

	for (int index = 0; index <= 100; ++index)
	{
		if (index % 3 == 0 || index % 5 == 0)
		{
			std::cout << "FizzyBuzzy boy" << std::endl;
		}
		std::cout << index << std::endl;
	}

	std::cout << "Project Eula Problem" << std::endl;
	std::cin.get();


	int number = 0;
	for (int index = 0; index <= 1000; ++index)
	{
		if (index % 3 == 0 || index % 5 == 0)
		{
			number
		}
		std::cout << index << std::endl;
	}
	std::cout << number;
	

	system("Pause");
	std::cin.get();

	return 0;
}