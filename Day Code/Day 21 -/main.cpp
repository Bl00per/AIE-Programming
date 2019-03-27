#include <iostream>
#include "dynamic_array.h"
#include "linked_list.h"

int main(int a_arg_count, char** a_arguments)
{
	dynamic_array<char> d;
	// Pushes letters
	for (size_t i = 65 ; i < 90; i++)
	{
		d.push(i);
	}

	char name[] = "Will";
	d.insert(name, 4, 20);

	d.remove(1, 26);

	d.trim();

	linked_list<char> ll;
	for (size_t i = 65; i < 90; i++)
	{
		if (i % 2)
		{
		ll.pushFront(i);
		}
		else
		{
		ll.pushBack(i);
		}
	}

	for (size_t i = 0; i < 5; i++)
	{
		ll.insert('7', 13);
	}

	ll.erase(14);

	ll.remove('7');


	return 0;
}