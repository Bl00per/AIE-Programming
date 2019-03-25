#include <iostream>


float max(float a, float b); // Lets the rest of the code know that these variables exist

 float main() {
	float a, b; // Lets the block of code in here know a & b exist

	std::cout << "Please enter 2 different numbers.\n";
	std::cin >> a >> b;

	float result = max(a, b); // Function call

	std::cout << "The smaller number is: " << result << std::endl;
	
	system("Pause");
}

float max(float a, float b) // Function definition
{
	return (a < b ? a : b); // This is where the algorithm goes
}



