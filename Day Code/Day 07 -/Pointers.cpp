#include <iostream>

void funct(char* a_char[], int a_size)
{
	
}

int main(int a_arguement_count, char** a_argument_list)
{
	int m_x = 10;
	std::cout << &m_x << '\n'; // Address of local variable
	std::cout << &main << '\n'; // Address of scoped function
	int* ptr_x = &m_x; // Copies the address into the pointer
	std::cout << ptr_x << '\n'; // The value of a pointer is the arress it points to
	std::cout << &ptr_x << '\n'; // The address where the pointer(address) is stored
	int** ptr_ptr_x = &ptr_x; // This will be used later

	float* ptr_flt = new float(3.14159f);
	std::cout << "Address of pi approx: " << ptr_flt << '\n';
	//Dereference a pointer to access the value
	std::cout << "Value of address of pi approx: " << *ptr_flt << '\n';
	*ptr_flt = -1.0f;// Dereferencing a raw pointer gives read/write access
	std::cout << "Value of address of pi is now: " << *ptr_flt << '\n';
	delete ptr_flt;
	ptr_flt = nullptr;

	int* ptr_y = new int(20);   // New allocation
	std::cout << ptr_y << '\n'; // Requires 
	delete ptr_y;				// Deallocation (delete)
	ptr_y = nullptr;			// Prevents the data from allocating it anything

	// Old array
	const int buffer_size = 80;
	char input_buffer[buffer_size]{ 0 };


	char name[] = "Adam";
	char* ptr_name = new char[5]{ 0 };
	strcpy(ptr_name, name);



	int input_size = 0;
	std::cin >> input_size;
	char* other_buffer = new char[1];

	// Raw memory dump
	//for (int i = 0; i < input_size; ++i)
	//{
	//	std::cout << other_buffer[i];
	//}
	delete[] other_buffer;



	system("Pause");
	return(0);
}