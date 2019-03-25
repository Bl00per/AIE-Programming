#include <iostream>

//Your function called SumArray goes here
int SumArray(int integer_array[], int length);

int main()
{
	int integer_array[5] = { 7, 3, 2, 4, 9 };
	int result = SumArray(integer_array, 5); //result = 25
	std::cout << result << std::endl;

	system("Pause");
}



int SumArray(int integer_array[], int length)
{
	int result = 0;
	for (int index = 0; index < length; index++)
	{
		result += integer_array[index];
		std::cout << integer_array[index] << std::endl;
	}
	return (result);
}
