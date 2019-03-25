#include <iostream>

int MinInArray(int integer_array[], int length);

int main()
{
	int integer_array[7] = { 10, 15, 7, 4, 13, 19, 8 };
	int result = MinInArray(integer_array, 7); //result = 4
	std::cout << result << std::endl;

	system("Pause");
}

int MinInArray(int integer_array[], int length)
{
	int smallest = integer_array[0];
	for (int index = 0; index < length; index++)
	{
		if (integer_array[index] < smallest)
		{
			smallest = integer_array[index];
		}
	}
	return (smallest);
}
