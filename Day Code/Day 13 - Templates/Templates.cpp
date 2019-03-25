// Templates in C++
// Template is a blueprint or formula for creating generic class or a function
// examples - writing a code to swap two items that can be an object or primitive data types

#include <iostream>
#include "MyArray.h"

// Function Template
// A generic function that can be used for different data types
// Create a generic function to find the greatest value
template <typename T/*, typename U*/>
T Maximum(T a, T b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}


int main() {
	std::cout << Maximum<int>(10, 13.5f) << std::endl;
	std::cout << Maximum<float>(2.5f, 1.4f) << std::endl;
	std::cout << Maximum<char>('A', 'B') << std::endl;

	int arr[5] = { 10, 20, 30, 40, 50 };
	float Farr[5] = { 10.5f, 20.1f, 30.2f, 40.1f, 50.5f };

	MyArray<int> myArr(arr, 5);
	MyArray<float>myFArr(Farr, 5);

	for (int i = 0; i < 5; ++i) {
		std::cout << myArr[i] << std::endl;
	}
	for (int i = 0; i < 5; ++i) {
		std::cout << myFArr[i] << std::endl;
	}


	std::cout << arr[1] << std::endl;

	return 0;
}