#include <iostream>
#include <ctime>

// Function prototype / DECLARATION
// <return type> <function name> ( <arguments> );
void print_array(int a_array[], size_t a_size);
void print_array(char a_array[], size_t a_size);
 

int main()
{
	/*
	// c - strings zero null terminated character arrays
	const size_t buffer_length = 80;
	char name[buffer_length]{ '\0' }; // '\0' == 0


	const size_t name_count = 5;
	char names_list[name_count][buffer_length]{ '\0' };

	// Five buffers of length 80 to store names
	
	// Enter 5 names
	std::cout << "Enter " << name_count << " names for storage: \n";
	for (size_t index = 0; index < name_count; index++)
	{
		std::cout << "Enter a name: ";
		std::cin.getline(names_list[index], buffer_length);
	}

	// For counting down, consider the negative consequences (signed int [size_t])
	for (int index = name_count - 1; index >= 0; index--)
	{
		for (int char_index = strlen(names_list[index]) - 1; char_index>= 0; char_index--)
		{
			std::cout << names_list[index];
		}
		std::cout << "\n";
	}
	*/

	//<type> <main> = <Optional Initialisations>;
	// = assignment operator (copy)
	int student = 20;
	float coffee_percentage = 5.5f; // That 'f' tells our compiler we knew float and mean it.
	bool awake = true;

	// if ( <conditional statement> )
	if (awake)
	{
		std::cout << "Adam is awake! \n\t\a";
	}

	size_t length = 5;
	// for ( <initial conditions> ; <conditional statement> ; <loop incrementation> )
	for (size_t i = 0; i < length; i++) // size_t 
	{
		std::cout << "\a"; // Alarm while in loop
	}

	// while ( <conditional> )
	while (awake)
	{
		if (awake)
		{
			awake = !awake;
		}
	}

	// Seeds rng with pc's current time 0 offset
	srand(time(nullptr));

	// const allows for static array creation of this size
	const size_t size = 100;
	// <type> <name>[<Optinal size>] = <Optional Initialisation> 
	int random_numbers[size]{ 0 };
	int arry[]{ 0,1,2,3,4,5,6 };
	
	int range = 101;

	// Filling array with random data
	for (size_t i = 0; i < size; i++)
	{
		random_numbers[i] = rand() % range - (range / 2);
	}

	for (size_t i = 0; i < size; i++)
	{
		std::cout << random_numbers[i] << "\n"; // !((bool)(i % 10)) ? "\n" : " ";
	}

	//Bubble sort!
	// Collection of unsorted data
	// while unsorted
	// Counted through start to finish
	// compared current index with next
	// swapped if need
	// if we looped without a swap, we were ordered.
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (size_t i = 0; i < size - 1; i++)
		{
			//Swapsies
			int temp = random_numbers[i];
			random_numbers[i] = random_numbers[i + 1];
			random_numbers[i + 1] = temp;
			sorted = false;
		}
	}
	
	print_array(random_numbers, size);

	// Total bounds
	int left = 0; // Left min
	int right = size - 1; // Right max

	int found_at = -1; // Final found index of target
	bool searching = true; // Loop control

	// User instructionn and target aquisition
	int target = i;
	std::cout << "Please enter the number to search for: ";
	std::cin >> target;

	for (int i = -50; i <= 50; i++)
	{
		while (left <= right)
		{
			int middle = (left + right) / 2; // Find the midpoint of currect range

			if (random_numbers[middle] == target)
			{
				found_at = middle;
			}

			if (random_numbers[middle] < target) { left = middle + 1; } // Move left goal post
			if (random_numbers[middle] > target) { right = middle - 1; } // Move right goal post
		}
	}
	
	std::cout << i << " was found at " << found_at << "\n";

	system("Pause");
	return 0;
}	

//// Definition / Implementation
//void print_array(int a_array[], size_t a_size)
//{
//	size_t entries_per_line = 10;
//
//	for (size_t i = 0; i < a_size; i++)
//	{
//		std::cout << a_array[i] << ((i % entries_per_line == entries_per_line - 1) ? "\n" : "\t");
//	}
//}