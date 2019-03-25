#include <iostream>

int main()
{
	// main.cpp/main()
	// ...
	// Average of Five)
	float a, b, c, d, e; // Modify these variables below.
	float avg; // Modify this variable below.
	avg = a = b = c = d = e = 0.0f; // Initialize all to zero.
	// <Your work goes here>
	std::cout << "Please enter your five numbers with spaces inbetween." << std::endl;
	std::cin >> a >> b >> c >> d >> e;

	avg = (a + b + c + d + e) / 5;

	std::cout << "Average of Five)" << std::endl;
	std::cout << a << "," << b << "," << c << "," << d << "," << e << std::endl;
	std::cout << "avg: " << avg << std::endl;

	// ...

	// main.cpp/main()
	// ...
	// Number Swap)
	int x = 13;
	int y = 24;
	// <Your work goes here>
	x = 24;
	y = 13;
	std::cout << "Number Swap)" << std::endl;
	std::cout << "x is " << x << std::endl;
	std::cout << "y is " << y << std::endl;

	// ...

	system("Pause");
	std::cin.get();

	return 0;
}