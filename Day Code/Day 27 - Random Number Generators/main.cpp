// C-Style
#include <cstdlib> // access to srand() and rand()
#include <ctime> // time().. since the 70's no one remembers
// Pseudo Random Number Sequence - Deterministic polynomial

#include <iostream>

int main(void)
{
	srand(time(nullptr)); // Seed Rand.
	// Seeded with current time
	// Should happen once, but only once.

	for (size_t i = 0; i < 10; i++)
	{
		int result = rand(); // 0 - ~32000
		std::cout << result << std::endl;
	}

	// Range based RNG
	int dice_roll = (rand() % 6); // 0 - 5
	int dice_roll_two = (rand() % 6) + 1; // 1 - 6

	// result = rand() % range_count + range_offset;

	int result = rand() % 11 - 5; // -5 - +5

	return 0;
}