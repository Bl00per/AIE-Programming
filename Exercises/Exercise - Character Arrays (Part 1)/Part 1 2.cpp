#include <iostream>

int main()
{
	//const size_t name_length = 80;
	//char full_name[name_length] = { '\0' };


	//std::cout << "Please enter your full name: \n";
	//std::cin.getline(full_name, name_length);

	//std::cout << "Your full name is: " << full_name << "\n\n";

	//std::cout << "Your full name printed backwards is: ";
	//for (int index = strlen(full_name) - 1; index >= 0; index--)
	//{
	//	std::cout << full_name[index];
	//}
	//std::cout << "\n";


	const size_t buffer_size = 80;
	const size_t name_count = 5;
	char name_list[name_count][buffer_size]{ '\0' };

	// Five buffers of length 80 to store names

	// Enter 5 names
	std::cout << "Enter " << name_count << " names for storage: \n";
	for (size_t index = 0; index < name_count; index++)
	{
		std::cout << "Enter a name: ";
		std::cin.getline(name_list[index], buffer_size);
	}

	// For counting down, consider the negative consequences (signed int [size_t])
	for (int index = name_count - 1; index >= 0; index--)
	{
		for (int char_index = strlen(name_list[index]) - 1; char_index >= 0; char_index--)
		{
			std::cout << name_list[index];
		}
		std::cout << "\n";
	}

	system("Pause");
	return 0;
}

// Definition / Implementation
void print_array(int a_array[], size_t a_size)
{
	size_t entries_per_line = 10;

	for (size_t i = 0; i < a_size; i++)
	{
		std::cout << a_array[i] << ((i % entries_per_line == entries_per_line - 1) ? "\n" : "\t");
	}
}