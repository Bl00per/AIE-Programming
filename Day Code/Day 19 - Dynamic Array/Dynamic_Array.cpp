#include "Dynamic_Array.h"

int main(int a_arg_count, char** a_arguments)
{
	// Fixed size at compile time, required a const int size
	const int static_array_size = 10;
	int static_array[static_array_size]{ 0 };
	
	// Writing
	static_array[4] = 6; 
	// Reading
	if (static_array[2] == 2) 
	{

	}

	int m_dynamic_array = new int[static_array_size] { 0 };
	delete[] m_dynamic_array;
	m_dynamic_array = nullptr;

	Dynamic_Array<size_t> m_array;

	m_array.pop();
	m_array.pop();
	m_array.pop();

	m_array.push(10);
	m_array.push(10);
	m_array.push(10);
	m_array.push(10);
	m_array.push(100);


	return 0;
}
