#include <iostream>

struct Coordinate
{
	char letter;
	unsigned short number;
};

class Co0rd
{
private:
	char letter;
	unsigned short number;

public:
	Co0rd(char a_letter, unsigned short a_number) : letter(a_letter), number(a_number) {}
	void print() {
		char buff[2] = { letter, '\0' };
		std::cout << buff << ", " << number << '\n';
	}
};



// Gross generalisation
// Struct is raw data on the stack - Operations are performed by the program - Procedural
// Class is functional data on the heap - Operations are performed within the object - OOP

int main()
{
	int i = 5.2f;// Implicit cast
	int j = (int)5.2f; // C style
	int k = (5.2f); // C++ style

	// Explicit cast
	float  f = f / (float)2
		;
	int* p_j = &j;
	float* p_j = (float*)p_j; // Treat binary fr=or int j as binary float = #cstyle

	std::cout << j << '\n';
	std::cout << p_j << '\n';
	std::cout << f_j << '\n';



	Coordinate home{ 'J', 2 };
	home.letter = 'A';
	home.number = 5;

	Coordinate path[]{ 
		{'A', 6},
		{'B', 5},
		{'J', 3},
		{'K', 8} 	
	};

	Coordinate newHomie = home;
	newHomie.letter = 'G';

	Co0rd c('J', 2);

	return 0;
}