#include <iostream>

// Enumeration in C++ is a user-defined data type. 
// It is used to assign names to integral constants, the names make a program easy to read and maintain

// Define an enumeration using keyword 'enum' followed by the name
// the values inside the enum are constant, by default they start from 0, 1, 2...

// Variable of type enum can also be defined in two ways
// facts about initialization of an enum
// 1. Two enum names can have same value
// 2. if we don not explicitly assign values to enum names, the compiler by default assigns values starting from 0
// 3. We can assign values to some name in any order. All unassigned names get value as value of previous name plus one
// 4. the value must in the range of minimum possible integer value to maximum possible integer value
// 5. All enum constants must be unique in their scope.

// Why enumerations are used in programming?
// An enum variable take only one value out of many possible values.

enum State {
	Play = 42,
	Options = 50,
	Exit = 60
};

int main()
{


	int options = 0;
	while (true) {
		std::cout << "Enter '42' to play, '50' for options, 60 to exit the game";
		std::cin >> options;
		switch (options) {
			// switches to play mode
		case State::Play:
			std::cout << "Playing the game!" << std::endl;
			break;
			// switches to the options screen
		case State::Options:
			std::cout << "Options screen" << std::endl;
			break;
			// exit from the application
		case State::Exit:
			return 0;
		}
	}
}