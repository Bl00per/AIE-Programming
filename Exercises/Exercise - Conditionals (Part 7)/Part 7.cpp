#include <iostream>

int main()
{
	char months;
	bool play = true; //Lets the user continue using the calculator
	char play_choice; //Lets the user decide if they want to continue using it

	while (play == true)
	{
		std::cout << "How many days are in each month?" << std::endl << std::endl;
		std::cout << "Please enter number for a month of the year (1 = Jan, 2 = Feb, 3 = Mar, etc.)" << std::endl;
		std::cin >> months;

		switch (months)
		{
		case '1' :
			std::cout << "There are 31 days in January."  << std::endl;
			break;
		case '2':
			std::cout << "There are 28 days in February." << std::endl;
			break;
		case '3':
			std::cout << "There are 31 days in March." << std::endl;
			break;
		case '4':
			std::cout << "There are 30 days in April." << std::endl;
			break;
		case '5':
			std::cout << "There are 31 days in May." << std::endl;
			break;
		case '6':
			std::cout << "There are 30 days in June." << std::endl;
			break;
		case '7':
			std::cout << "There are 31 days in July." << std::endl;
			break;
		case '8':
			std::cout << "There are 31 days in August." << std::endl;
			break;
		case '9':
			std::cout << "There are 30 days in September." << std::endl;
			break;
		case '10':
			std::cout << "There are 31 days in October." << std::endl;
			break;
		case '11':
			std::cout << "There are 30 days in November." << std::endl;
			break;
		case '12':
			std::cout << "There are 31 days in December." << std::endl;
			break;
		default:
			std::cout << "Error. Please try again." << std::endl;
			break;
		}
		std::cout << "Would you like to use this program again? Enter (Y) to continue." << std::endl;
		std::cin >> play_choice;
		if (play_choice == 'y' || play_choice == 'Y')
		{
			play = true; //Keeps the calculator going
		}
		else
		{
			play = false; //Quits the program
		}
	}//End of while loop
}