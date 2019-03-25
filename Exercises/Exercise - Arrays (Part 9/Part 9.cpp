#include <iostream>
#include <iomanip>

int main()
{
	//3 dragons, 7 days.
	//3x7 array

	const int M = 7;
	const int N = 3;
	int food_array[M][N + 1] = {};

	size_t Rows = M;
	size_t Columns = N;

	// Entering the numbers into the array
	for (size_t i = 0; i < Rows; i++)
	{
		std::cout << "How much food did each dragons eat for Day " << i + 1 << ": ";
		for (size_t j = 0; j < Columns; j++)
		{
			std::cin >> food_array[i][j];
		}
	}

	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < Columns; j++)
		{
			food_array[i][Columns] += food_array[i][j];
			//food_array[m][j] *= food_array[i][j]; //Multiplication
		}
	}

	std::cout << std::endl;

	// Displaying the array
	std::cout << " Dr1 Dr2 Dr3 TTL:" << ' ';
	std::cout << '\n';
	for (size_t i = 0; i < Rows; i++) // Rows
	{
		for (size_t j = 0; j < Columns + 1; j++) // Columns
		{
			std::cout << std::setw(3) << food_array[i][j] << ' ';
		}
		std::cout << '\n';
	}

	std::cout << std::endl;

	// Average amount ( / 3 )
	std::cout << " Avg:\n";
	int result = 0;
	for (size_t i = 0; i < Rows; i++) // Rows
	{
		for (size_t j = 0; j < 1; j++) // Columns
		{
			result = food_array[i][Columns] / 3;
			std::cout << std::setw(3) << result;
		}
		std::cout << '\n';
	}

	std::cout << std::endl;


	/*
	- average amount of food eaten per day by any one dragon
	- the greatest amount of food eaten during one day and which dragon that was
	- the least amount of food eaten during one day and which dragon that was
	*/

	system("Pause");
}
