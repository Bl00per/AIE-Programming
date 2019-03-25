#include <iostream>


int main()
{
	//Column x Row
	int grid_array[3][3];

	int counter = 1;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			grid_array[i][j] = counter;
			++counter;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << grid_array[i][j] << " ";
		}
		std::cout << "\n";
	}
	system("Pause");
}