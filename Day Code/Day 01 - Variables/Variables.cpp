#include <iostream>

int main()
{
	//Varible declarations
	//Whole Quantity. Student, pixel (whole numbers)
	short s_health = 10;
	int i_health = 100;
	long int l_health = 100000000000;

	//Floating point (decimal numbers)
	float f_percentage = 50.0f;
	double d_percentage = 50.00005;

	//<type> <name> = <Optional Assignment>
	int n_health = 100;
	n_health = 900;
	i_health = n_health;
	//Primitive types are assigned by copy. =

	//Math time :(

	int A, B;
	// + - * / (Operators)
	A = 10;
	B = 3;
	int result = A / B; //10 / 3 
	int mod_result = A % B; //Remainder Modulo
	float decimal_result = A / B;
	//float decimal_result = A / (float B);


	std::cout << "MyText\n\t\a";
	std::cout << result << "\n";
	std::cout << decimal_result << "\n";
	std::cout << mod_result << "\n";

	float answer0 = 1.0f / 2;
	float answer1 = 1 / 2.0f;
	float answer2 = 1.0f / 2.0f;
	std::cout << answer0 << "\n";
	std::cout << answer1 << "\n";
	std::cout << answer2 << "\n";

	//Will wait until enter is pressed to pause
	std::cout << std::endl << "Press 'Enter' to exit the program." << std::endl;
	std::cin.get();

	return 0;
}