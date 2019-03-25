#include <iostream>

int main()
{
	char c = 'T', d = 'S'; 
	char *p1 = &c; 
	char *p2 = &d; 
	char *p3;

	p3 = &d; 

	std::cout << "*p3 = " << *p3 << std::endl; // (1) S
	
	p3 = p1;
	
	std::cout << "*p3 = " << *p3; // (2) T
	std::cout << ", p3 = "<< p3 << std::endl; // (3) T
	
	*p1 = *p2;

	std::cout << "*p1 = " << *p1; // (4) S
	std::cout << ", p1 = " << p1 << std::endl; // (5) S


	system("Pause");
	return(0);
}