#include <iostream>

int main()
{
	const int large_input_count = 10;
	int large_user_input[large_input_count] = { 0 };

	std::cout << "Enter 10 whole numbers.\n";
	//Gather user input
	for (int index = 0; index < large_input_count; ++index)
	{
		std::cin >> large_user_input[index];
	}

	//Find and print largest
	int largest = INT_MIN;
	int smallest = INT_MAX;
	for (int index = 0; index < large_input_count; ++index)
	{
		if (largest < large_user_input[index])
		{
			largest = large_user_input[index];
		}	
		if (smallest > large_user_input[index]) //Find and print smallest
		{
			smallest = large_user_input[index];
		}
	}
	std::cout << largest << " is the largest number." << std::endl;
	std::cout << smallest << " is the smallest number." << std::endl;


	system("Pause");
	std::cin.get();

}