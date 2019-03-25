#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	//const char*
	char name[] = "Will";
	char large_buffer[64] = "Will";
	
	std::cout << strlen(name) << "\n";
	char surname[] = "Hart";
	
	int compare = strcmp(name, surname); //-1 lhs first alphabetically
	std::cout << compare << "\n";
	compare = strcmp(surname, name); // 1 rhs first alphabetically
	std::cout << compare << "\n";
	compare = strcmp(name, name); // 0 the same
	std::cout << compare << "\n";

	char buffer[256] = "abcdefghijklmnopqrstuvwxyz";
	strcpy(buffer, name); // oNly copies over till source null

	strcat(buffer, surname);


	system("Pause");
	return 0;
}