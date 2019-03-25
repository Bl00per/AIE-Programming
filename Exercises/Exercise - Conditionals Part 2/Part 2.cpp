#include <iostream>

int main()
{
	float user_number_1;
	float user_number_2;

	std::cout << "Please enter 2 numbers." << std::endl;
	std::cin >> user_number_1;
	std::cin >> user_number_2;

	if (user_number_1 > user_number_2)
	{
		std::cout << user_number_1 << " is the larger number." << std::endl;
	}
	else
	{
		std::cout << user_number_2 << " is the larger number." << std::endl;
	}

	system("Pause");
	std::cin.get();

	return 0;
}