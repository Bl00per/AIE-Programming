#include "zombie.h"
#include <iostream>
#include "Part 1.h"
#include <ctime>

int main()
{
	const size_t horde_size = 10;
	//zombie horde[horde_size]; //10 default zombies

	zombie fred(3, 2, "Forum Admin");
	zombie horde[horde_size]
	{
		{5,5, "Teacher"},
		{1,1, "Teacher"},
		fred,
	};

	srand(time(nullptr));
	bool more_than_one = true;
	int round_counter = 0;
	while (more_than_one)
	{
		++round_counter;
		std::cout << "Round: " << round_counter << "\n";
		//Battle 1 random vs 1 random
		int zombA = rand() % horde_size;
		int zombB = rand() % horde_size;


		horde[zombA].attack(horde[zombB]);

		//Check - Count number of living zombies 
		int counter = 0;
		more_than_one = false;
		for (size_t index = 0; index < horde_size; index++)
		{
			if (horde[index].get_health() > 0)
			{
				counter++;
				if (counter >= 2)
				{
					more_than_one = true;
					break;
				}
			}
		}
	}



	/*
	std::cout << fred.get_health() << std::endl;
	std::cout << fred.get_attack_value() << std::endl;
	std::cout << fred.get_occupation() << std::endl;
	*/

	fred.to_console();
	{
		zombie paul;
		
		fred.attack(paul);
		fred.attack(paul);
		fred.attack(paul);
		
		paul.to_console();
	}

	// An array of default zombies
	// While more than one zombie is alive
	// Pick two
	// One attacks other


	system("Pause");
	return 0;
}