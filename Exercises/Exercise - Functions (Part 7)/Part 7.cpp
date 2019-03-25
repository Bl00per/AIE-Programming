#include <iostream>

int SumTo(int N);

int main()
{
	//Need an array that counts up to N and produces to the sum of the array
	int N = 3;

	int result = SumTo(3); //result = 1 + 2 + 3 = 6
	std::cout << result << std::endl;

	result = SumTo(15); //result should now be 120
	std::cout << result << std::endl;


	system("Pause");

}

int SumTo(int N)
{
	int result = 0;
	for (int index = 1; index <= N; ++index)
	{
		result  += index;
		std::cout << result << std::endl;
		
	}
	return (result);
}
