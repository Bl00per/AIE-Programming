#include <iostream>

bool is_odd(int a_number);
int addition(int a, int b);
float addition(float a, float b);
void print_int(int a_print_me);

int main()
{
	int y = 10 + addition(3.5f, 5.1f);
	bool was_odd = is_odd(6);

	//int z = integer_addition(
	//				integer_addition(3, 5),
	//				integer_addition(5, 10));

	return 0;
}

bool is_odd(int a_number)
{
	if(a_number % 2 == 1)
	{
		return true;
	}
	return false;
}

float addition(float a, float b)
{
	a = 10.0f;
	float result = a + b;
	return result;
}
	
void print_int(int a_print_me)
{
	std::cout << a_print_me << "\n";
}