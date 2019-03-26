#include "linked_list.h"
#include <list>

int main(int a_arg_count, char** a_arguments)
{


	linked_list my_list;
	my_list.push(10); //0
	my_list.push(20); //1
	my_list.push(30); //2
	// Where insertion should take place
	my_list.push(40); //3
	my_list.push(100); //4

	my_list.insert(-10000, 3);
	my_list.remove(2);

	return 0;
}