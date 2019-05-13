#include <iostream>
#include "vector_2.h"

struct MyStruct
{
	int potato = 3;
	int tomato = 7;
};

union CFMEU
{
	int health;
	float cucumber;
};

int main(void)
{
	//CFMEU u;
	//u.health = 10;
	//u.cucumber = 5.0f;

	//std::cout << u.health << std::endl;
	//std::cout << u.cucumber << std::endl;


	//MyStruct ms{ 5, 8 };
	//std::cout << ms.potato << std::endl;
	//std::cout << ms.tomato << std::endl;

	vector_2 v;

	v.x = 2.0f;
	v.y = 2.0f;
	std::cout << v.data[0] << std::endl;
	std::cout << v.data[1] << std::endl;

	//v[0] = 2.5f;
	//std::cout << v[0] << std::endl;

	//float* ptr_v = ((float*)v);
	//std::cout << *ptr_v << std::endl;

	// Assert test
	//v[3] = 2.5f;

	vector_2 result = v + v;
	result = result - result;
	result = v + v;
	result = result * 4.0f;
	result = result / 2.0f;

	result = 5.0f * result;

	vector_2 copy(result);
	copy += copy;
	copy -= copy;
	copy *= 2.0f;
	copy /= 3.0f;

	copy = { 3,4 };
	std::cout << copy.square_magnitude() << std::endl;
	std::cout << copy.magnitude() << std::endl;

	vector_2 norman = copy.normalized();
	copy.normalize();

	if (norman == copy)
	{
		std::cout << "Success!" << std::endl;
	}

	return 0;
}