#include <iostream>

int main(int a_argument, char a_)
{
	// Set up the CRT debug flags for memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	/* @brief name_list holds the address of the start of the list of names
	*/
	char** name_list;


	short name_list_length = 0;

	/* @brief list length validation
	*/
	bool valid_list_length = false;

	// Press the user until a valid input is recieved
	while (!valid_list_length)
	{
		// Query the user for how many names we want to store
		std::cout << "How many names would you like to store? \n";
		std::cin >> name_list_length;

		// If input is within valid range... continue
		if ((name_list_length > 1) && (name_list_length <= SHRT_MAX))
		{
			valid_list_length = true;
		}
		else
		{
			std::cout << "Invalid list length\n";
			std::cin.clear(); // Clears IO error flags
			//Clears the input stream of all characters on this line
			std::cin.ignore(SHRT_MAX, '\n');
		}
	}

	// Create space for the array of pointers and initialise all to null
	name_list = new char*[name_list_length] {nullptr};

	// Input buffer declaration and empty initialization
	const size_t buffer_length = 80;
	char input_buffer[buffer_length]{ '\0' };

	// Loop and read length number of names
	for (size_t index = 0; index < name_list_length; index++)
	{
		// Index + 1 because users dont count from 0
		std::cout << "Please enter name " << (index + 1) << ": ";
		std::cin.getline(input_buffer, buffer_length - 1); // Buffer length -1 to ensure null termination
		std::cin.ignore(SHRT_MAX, '\n'); // If input stream > buffer length, discard the rest

		// Valid character count
		size_t input_length = strlen(input_buffer);
		name_list[index] = new char[];
		strcpy(name_list[index], input_buffer);
	}

	// Loop for length times
	// New location of buffer length
	// Copy from buffer ot heap

	// Clean up allocations
	for (size_t index = 0; index < name_list_length; index++)
	{
		delete[] name_list[index];
	}

	// Clean up pointer list
	delete[] name_list;

	system("Pause");
	return 0;
}