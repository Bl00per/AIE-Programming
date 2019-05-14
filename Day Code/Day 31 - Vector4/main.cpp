#include <iostream>
#include "vector_4.h"

int main(void)
{
	vector_4 v = { 2, 3, 4 };

	std::cout << v.data[0] << std::endl;
	std::cout << v.data[1] << std::endl;
	std::cout << v.data[2] << std::endl;

	vector_4 result = v + v;
	result = result - result;
	result = v + v;
	result = result * 4.0f;
	result = result / 2.0f;

	result = 5.0f * result;

	vector_4 copy(result);
	copy += copy;
	copy -= copy;
	copy *= 2.0f;
	copy /= 3.0f;

	copy = { 3,4 };
	std::cout << copy.square_magnitude() << std::endl;
	std::cout << copy.magnitude() << std::endl;

	vector_4 norman = copy.normalized();
	copy.normalize();

	if (norman == copy)
	{
		std::cout << "Success!" << std::endl;
	}

	system("Pause");
	return 0;
}