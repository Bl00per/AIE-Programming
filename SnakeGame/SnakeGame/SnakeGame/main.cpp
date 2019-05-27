#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;

void setup();
void draw();
void input();
void logic();
void clearScreen();

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

int main()
{
	setup();
	while (!gameOver)
	{
		draw();
		input();
		logic();
		
	}

	return 0;
}


void setup()
{
	srand(time(nullptr));
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw()
{
	clearScreen();
	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				std::cout << "#";
			}

			if (i == y && j == x)
			{
				std::cout << "O";
			}
			else if (i == fruitY && j == fruitX)
			{
				std::cout << "F";
			}
			else
			{
				std::cout << " ";
			}

			if (j == width - 1)
			{
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	std::cout << "Score: " << score << std::endl;
}

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		default:
			break;
		}
	}
}

void logic()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width || x <= 0 || y > height || y <= 0)
		gameOver = true;
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}

// Function to clear the screen
void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}