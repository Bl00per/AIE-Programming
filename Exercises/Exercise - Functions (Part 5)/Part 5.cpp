#include <iostream>
#include <ctime>



enum coin_state
{
	none,
	heads,
	tails
};


//Simulates the tossing of a coin
coin_state coin_toss();

int head_count = 0;
int tail_count = 0;

int main()
{
	srand(time(0));//Enables better randomish

	

	std::cout << "How many times would you like to flip the coin\n";
	int flips = 0;
	std::cin >> flips;

	for (int flip_count = 0; flip_count < flips; ++flip_count)
	{
		coin_toss();
	}

	std::cout << "Heads: " << head_count << std::endl;
	std::cout << "Tails: " << tail_count << std::endl;

	system("Pause");
	return 0;
}

coin_state coin_toss()
{
	int result = rand() % 2; // 0 - RAND_MAX ~32,000
	// 1 - 6 I would % 6. 0 - 5
	switch (result)
	{
	case(0):
		std::cout << "Heads\n";
		++head_count;
		break;
	case(1):
		std::cout << "Tails\n";
		++tail_count;
		break;
	default:
		std::cout << "Invalid coin state found...\n";
		break;
	}
	return none;
}