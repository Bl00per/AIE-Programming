#include <iostream>
#include "binary_tree.h"

int main()
{
	binary_tree<int> bt;
	bt.insert(10);
	bt.insert(6);
	bt.insert(15);
	bt.insert(14);
	bt.insert(5);

	std::cout << bt.find(8) << std::endl;
	std::cout << bt.find(10) << std::endl;
	std::cout << bt.find(6) << std::endl;
	std::cout << bt.find(15) << std::endl;
	std::cout << bt.find(14) << std::endl;
	std::cout << bt.find(5) << std::endl;



	return 0;
}