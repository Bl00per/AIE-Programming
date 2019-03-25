#include <iostream>

int main()
{
	int matrix[3][3];
	for (int index = 0; index < 3; ++index)
	{
		for (int inner_index = 0; index < inner_index < 3; ++inner_index)
		{
			matrix[index][inner_index] = index * 3 + inner_index + 1;
		}
	}

	for (int index = 0; index < 9; ++index)
	{
		std::cout << matrix[0][index] << " ";
	}
	for (int index = 0; index < 3; ++index)
	{
		for (int inner_index = 0; index < inner_index < 3; ++inner_index)
		{
			std::cout << matrix[index][inner_index] << " ";
		}
		std::cout << "\n";
	}


	system("Pause");
	std::cin.get();

}