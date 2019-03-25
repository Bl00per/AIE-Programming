#include <iostream>

int main()
{
	// main.cpp/main()
	// ...
	// Area of a Rectangle)
	float rectWidth = 0.0f; // Modify this variable below.
	float rectHeight = 0.0f; // Modify this variable below.
	float rectArea = 0.0f; // Modify this variable below.
	// <Your work goes here>
	std::cout << "Please enter your desired width." << std::endl;
	std::cin >> rectWidth;
	std::cout << "Please enter your desired height." << std::endl;
	std::cin >> rectHeight;

	rectArea = rectWidth * rectHeight;

	std::cout << "Area of a Rectangle)" << std::endl;
	std::cout << "H: " << rectHeight << " , W: " << rectWidth << std::endl;
	std::cout << "Area: " << rectArea << std::endl;

	// ...

	//Will wait until enter is pressed to pause
	system("Pause");
	std::cin.get();

	return 0;
}
