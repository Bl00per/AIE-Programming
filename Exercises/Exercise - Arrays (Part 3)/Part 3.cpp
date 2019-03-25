#include <iostream>

int main()
{
	int data[10];

	for (int i = 0; i < 10; ++i) //Fills up the array up to 10
	{
		data[i] = 10 - i; //Counts down from 10 by taking i
		std::cout << data[i] << std::endl;
	}


	const int input_count = 5;
	int user_input[input_count] = { 0 };

	std::cout << "Enter 5 whole numbers.\n";
	//Gather user input
	for (int index = 0; index < input_count; ++index)
	{
		std::cin >> user_input[index];
	}
	//Print array backwards
	for (int index = input_count - 1; index >= 0; --index)
	{
		std::cout << user_input[index] << std::endl;
	}


	system("Pause");
	std::cin.get();

}