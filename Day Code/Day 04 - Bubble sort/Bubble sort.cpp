/*
5. Create the following program
that demonstrates the use of strlen, strcmp, strcat and  strcpy:

	a. Ask the user to enter a username. Only let the program continue
	if the username contains the sequence ‘usr’ within it.

	Finding a substring
*/
#include <iostream>

void bubble_sort(char array[]);
int sub_string(char a_searchable[], char a_sub_string[]);

int main()
{
	const size_t buffer_size = 80;
	char search_string[buffer_size]{ 0 };
	char user_buffer[buffer_size]{ 0 };

	std::cout << "Enter Username: ";
	std::cin.getline(user_buffer, buffer_size);

	std::cout << "Enter Substring: ";
	std::cin.getline(search_string, buffer_size);

	std::cout << sub_string(user_buffer, search_string) << "\n";

	bubble_sort(user_buffer);
	std::cout << user_buffer;

	system("pause");
	return 0;
}

int sub_string(char a_searchable[], char a_sub_string[])
{
	bool success = false;
	size_t user_size = strlen(a_searchable);
	size_t sub_string_size = strlen(a_sub_string);

	for (size_t index = 0; index < user_size; index++)
	{
		for (size_t inner_index = 0; inner_index < sub_string_size; inner_index++)
		{
			if (a_searchable[index + inner_index] != a_sub_string[inner_index])
			{
				break;
			}
			// We got to the end of the sub string, therefore success
			if (inner_index == sub_string_size - 1)
			{
				return index;
			}
		}
	}
	return -1;
}


void bubble_sort(char array[])
{
	// Flag for swap occurance
	bool swap_flag = true;
	while (swap_flag)
	{
		swap_flag = false;
		// Run the length of the array - 1
		for (size_t index = 0; index < strlen(array) - 1; index++)
		{
			// Check with neighbour
			if (array[index] > array[index + 1])
			{
				// Swap with neighbour
				int temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				// Reset flag
				swap_flag = true;
			}
		}
	}
}


//Manual but slow way
//if (user_buffer[index] == 'u')
//		{
//			if (user_buffer[index + 1] == 's')
//			{
//				if (user_buffer[index + 2] == 'r')
//				{
//
//				}
//			}
//		}