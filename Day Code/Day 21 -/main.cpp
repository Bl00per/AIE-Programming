#include <iostream>
#include "dynamic_array.h"
#include "linked_list.h"
#include <crtdbg.h>


int main() {
	// Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Assign the vectors for dynamic array and linked list
	dynamic_array<int> my_array;
	linked_list<int> *my_list = new linked_list<int>();

	my_array.push(10);
	my_array.push(10);
	my_array.push(10);
	my_array.push(100);

	my_array.pop();


	my_list->pushBack(100);
	my_list->pushBack(200);
	my_list->pushBack(400);
	my_list->pushBack(600);
	my_list->pushBack(800);
	my_list->pushBack(1000);
	my_list->pushFront(50);
	// This value is going to the be the first one
	// because it was called last
	my_list->pushFront(123);

	// Inserts the value 500 at index 3
	my_list->insert(500, 3);

	my_list->remove(5);

	std::cout << "First element: " << my_list->first() << std::endl;
	std::cout << "Last element: " << my_list->last() << std::endl;

	std::cout << "Amount of elements: " << my_list->count() << std::endl;



	// Auto 'automatically' figures out which 
	//identifier (int, char, etc.) or class to use
	for (auto* iter = my_list->begin()->m_next; iter != my_list->end(); iter = iter->m_next)
	{
		std::cout << iter->m_data << '\n';
	}

	system("Pause");
	return 0;
}

