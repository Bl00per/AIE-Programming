#include <iostream>

int main()
{
	// main.cpp/main()
	// ...
	// A) 14
	int numberA = 5;
	numberA = 9;
	numberA = 11;
	numberA = 14;
	std::cout << "A) " << numberA << std::endl;
	// ...

	// main.cpp/main()
	// ...
	// B) 9
	int numberB = 10;
	numberB = 9;
	int thingB = 55;
	thingB = 22;
	std::cout << "B) " << numberB << std::endl;
	// ...

	// main.cpp/main()
	// ...
	// C) 21
	int numberC = 3;
	numberC = 7;
	numberC = 1;
	int somethingC = 23;
	somethingC = 21;
	numberC = somethingC;
	std::cout << "C) " << numberC << std::endl;
	// ...

	// main.cpp/main()
	// ...
	// D) 3
	int numberD = 1;
	int somethingD = 3;
	numberD = somethingD;
	std::cout << "D) " << somethingD << std::endl;
	// ...

	// main.cpp/main()
	// ...
	// E) 6
	int x = 13;
	x = x / 2;
	std::cout << "E) " << x << std::endl;
	// ...

	// main.cpp/main()
	// ...
	// F) 6.5
	float y = 13;
	y = y / 2;
	std::cout << "F)" << y << std::endl;
	// ...

	// main.cpp/main()
	// ...
	// Celsius to Fahrenheit)
	float degCelsius = 78.0f;
	float degFahrenheit = 0.0f; // Modify this variable below.
	// <Your work goes here>
	degFahrenheit = float(172.4f);
	std::cout << "Celsius to Fahrenheit)" << std::endl;
	std::cout << "Celsius: " << degCelsius << std::endl;
	std::cout << "Fahrenheit: " << degFahrenheit << std::endl;

	std::cin >> degCelsius;
	degFahrenheit = (degCelsius * 9 / 5) + 32;
	std::cout << degCelsius << "C is " << degFahrenheit << "F\n";
	// ...

	//Will wait until enter is pressed to pause
	system("Pause");
	std::cin.get();

	return 0;
}