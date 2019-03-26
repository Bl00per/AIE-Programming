#include <iostream>
#include "dynamic_array.h";


int main() {

	dynamic_array<int> my_array;

	my_array.push(1000);
	my_array.push(10);
	my_array.push(10);
	my_array.push(10);
	my_array.push(100);

	my_array.pop();



	return 0;
}

