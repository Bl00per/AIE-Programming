#include <iostream>


float Half(float number);

int main()
{
	float number = 16.721f;
	float result = Half(number); //result is 8.3605
	std::cout << "Half of " << number << " is: " << result << std::endl;

	system("Pause");
}

float Half(float number)
{
	float result = number / 2;
	return(result);
}