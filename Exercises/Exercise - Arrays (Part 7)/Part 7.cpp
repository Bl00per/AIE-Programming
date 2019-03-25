#include <iostream>

int main()
{
	const int days = 29;
	const int months = 5;
	int data[months][days];
	// Populating with random values
	for (int month_index = 0; month_index < months; ++month_index)
	{
		for (int days_index = 0; days_index < days; ++days_index)
		{
			data[month_index][days_index] = rand();
		}
	}
	// Sum of the ROWS!
	int sum = 0;
	for (int month_index = 0; month_index < months; ++month_index)
	{
		for (int days_index = 0; days_index < days; ++days_index)
		{
			sum += data[month_index][days_index];
		}
		// At THIS point
		std::cout << sum << "\n";
		sum = 0;
	}

	// Sum of the columns
	sum = 0;
	for (int days_index = 0; days_index < days; ++days_index)
	{
		for (int month_index = 0; month_index < months; ++month_index)
		{
			sum += data[month_index][days_index];
		}
		// At THIS point
		std::cout << sum << "\n";
		sum = 0;
	}

	system("Pause");
}