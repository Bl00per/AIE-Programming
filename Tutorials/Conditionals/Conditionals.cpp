#include <iostream>

void main()
{
	char vWeather = '0';// character to hold user weather choice.
	bool play = true;//to keep running program unless user
	char playChoice;//to keep the choice of user for continuing this program

	while (play == true)
	{
		//offer the choice for picking a weather
		std::cout << "Pick weather: S = Summer, W = Winter, P = Spring, A = Autumn" << std::endl;
		//store the weather choice in this variable
		std::cin >> vWeather;

		//lets see what we have in Weather choice
		switch (vWeather)
		{
		case 'S': //in each case we see if user have made any available
			std::cout << "Weather is set to Summer" << std::endl;
			break;
		case 'W'://so if user have picked winter or not
			std::cout << "Weather is set to Winter" << std::endl;
			break;
		case 'P'://or user have chosen spring
			std::cout << "Weather is set to Spring" << std::endl;
			break;
		case 'A':
			std::cout << "Weather is set to Autumn" << std::endl;
			break;
		default://if not a valid entry was found in user input
			std::cout << "Please pick the right weather type." << std::endl;
			break;
		}
		std::cout << "Do you want to pick another weather? Enter (Y) to continue." << std::endl;
		std::cin >> playChoice;
		//in this if statement we are lettinguser enter small letter or capital letter
		if (playChoice == 'y' || playChoice == 'Y')
		{
			play = true;//we set this true if we want to run while loop again
		}
		else
		{
			play = false;//setting 'play' to false we exit out loop
		}
	}//this is end of while loop

}