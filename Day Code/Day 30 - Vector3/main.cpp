#include <iostream>
#include "vector_3.h"

int main(void)
{
	vector_3 v;

	v.x = 2.0f;
	v.y = 3.0f;
	v.z = 4.0f;
	std::cout << v.data[0] << std::endl;
	std::cout << v.data[1] << std::endl;
	std::cout << v.data[2] << std::endl;

	vector_3 result = v + v + v;
	result = result - result - result;
	result = v + v + v;
	result = result * 4.0f;
	result = result / 2.0f;

	result = 5.0f * result;

	vector_3 copy(result);
	copy += copy;
	copy -= copy;
	copy *= 2.0f;
	copy /= 3.0f;

	copy = { 3,4 };
	std::cout << copy.square_magnitude() << std::endl;
	std::cout << copy.magnitude() << std::endl;

	vector_3 norman = copy.normalized();
	copy.normalize();

	if (norman == copy)
	{
		std::cout << "Success!" << std::endl;
	}

	system("Pause");
	return 0;
}