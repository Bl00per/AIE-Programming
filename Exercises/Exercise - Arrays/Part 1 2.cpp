#include <iostream>

int main()
{
	int numbers[10] = { 0, 0, 1, 0, 0, 1, 0, 0, 1, 1 }; // Valid
	int matrix[5] = { 1, 2, 3, 4, 5, 6, 7 }; // Invalid
	double radii[10] = {3.2, 4.7}; // Valid
	int table[7] = { 2, , , 27, , 45, 39 }; // Invalid
	char codes[] = { 'A', 'X', '1', '2', 's' }; // Invalid
	int blanks[]; // Invalid
	int collection[-20]; // Invalid
	int hours[3] = 8, 12, 16; // Invalid


	
	//Given the following array definition:
	int values[] = { 2, 6, 10, 14 };

	//What does each of the following display ?
	std::cout << values[2] << std::endl; //10
	std::cout << ++values[0] << std::endl; //3
	std::cout << values[1]++ << std::endl; //6
	int x = 2;
	std::cout << values[++x] << std::endl; //14
	std::cout << values[4] << std::endl; //-858993460


	system("Pause");
	std::cin.get();

	return 0;
}