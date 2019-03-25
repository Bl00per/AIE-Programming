#include <iostream>

/* @brief Function searches first string for any characters of the second string
	and returns true if found.
   @param a_original[] String to search through
   @param a_char_array[] Array of characters to look for
   @return True if any characters of char array found in original
*/
bool char_array_contains(char a_original[], char a_char_array[]);

int main()
{
	// Literal characters to check for
	char symbol[] = " `~!@#$%^&*()-_=+\\|]}[{;:'\",<.>/?";
	char capital[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char digit[] = "0123456789";
	const size_t minimum_password_length = 8;

	// Set a buffer size
	const size_t buffer_size = 80;

	// Set up storage
	char name[buffer_size]{ '\0' };
	char password[buffer_size]{ '\0' };

	// Input buffer for sane password checking
	char input_buffer[buffer_size]{ '\0' };

	// User instructions - Name
	std::cout << "Please enter user name: " << std::endl;
	// Spaces unhandled
	//std::cin >> name; // reads until white space
	std::cin.getline(name, buffer_size); // Entire line is user name

	bool is_valid = false;
	while (!is_valid)
	{

		// User instructions - Password
		std::cout << "Please enter password containing at least capital, a number, and a symbol: " << std::endl;
		std::cin.getline(password, buffer_size); // Entire line is password

		// Lenght check
		size_t password_length = strlen(password);
		if (password_length >= minimum_password_length)
		{
			std::cout << "Password length ok...\n";
		}
		else
		{
			std::cout << "Password too short...\n";
		}

		// Check password for characters
		bool has_capital = char_array_contains(password, capital);
		bool has_symbol = char_array_contains(password, symbol);
		bool has_digit = char_array_contains(password, digit);

		/** Let my user know how they did **/
		// Validity information
		if (has_capital)
		{
			std::cout << "Password has capital...\n";
		}
		else
		{
			std::cout << "Password missing capital...\n";
		}

		if (has_symbol)
		{
			std::cout << "Password has symbol...\n";
		}
		else
		{
			std::cout << "Password missing symbol...\n";
		}

		if (has_digit)
		{
			std::cout << "Password has digit...\n";
		}
		else
		{
			std::cout << "Password missing digit...\n";
		}

		// Final output
		if ((password_length >= minimum_password_length) && has_capital && has_digit && has_symbol)
		{
			std::cout << "Password is valid\n";
			is_valid = true;
		}
		else
		{
			std::cout << "Password is INVALID\n";
		}
	}
	system("pause");
	return 0;
}

bool char_array_contains(char a_original[], char a_char_array[])
{
	// Initial loop data
	size_t original_length = strlen(a_original);
	size_t char_array_length = strlen(a_char_array);

	for (size_t i = 0; i < original_length; i++)
	{
		for (size_t j = 0; j < char_array_length; j++)
		{
			if (a_original[i] == a_char_array[j])
			{
				return true;
			}
		}
	}
	return false;
}