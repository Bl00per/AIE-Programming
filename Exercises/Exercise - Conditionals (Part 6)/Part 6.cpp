#include <iostream>

int main()
{
	char Calculator;
	float user_number1, user_number2;
	bool play = true; //Lets the user continue using the calculator
	char play_choice; //Lets the user decide if they want to continue using it

	while (play == true)
	{
		std::cout << "Please enter 2 numbers." << std::endl;
		std::cin >> user_number1 >> user_number2;

		std::cout << "Please enter an operator (+, -, *, /)" << std::endl;
		std::cin >> Calculator;

		switch (Calculator)
		{
		case '+':
			std::cout << user_number1 << " + " << user_number2 << " = " << user_number1 + user_number2 << std::endl;
			break;
		case '-':
			std::cout << user_number1 << " - " << user_number2 << " = " << user_number1 - user_number2 << std::endl;
			break;
		case '*':
			std::cout << user_number1 << " x " << user_number2 << " = " << user_number1 * user_number2 << std::endl;
			break;
		case '/':
			std::cout << user_number1 << " / " << user_number2 << " = " << user_number1 / user_number2 << std::endl; \
			break;
		default:
			std::cout << "Invalid please try again." << std::endl;
			break;
		}
		std::cout << "Would you like to calculate another equation? Enter (Y) to continue." << std::endl;
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