//#include <iostream>
//
//int main()
//{
//
//
//
//	const int Rows = 3;
//	const int Columns = 3;
//	char arry[Rows][Columns] = 
//	{
//		{ '1', '2', '3' },
//		{ '4', '5', '6' },
//		{ '7', '8', '9' }
//	};
//
//	
//
//	int user_input;
//	std::cin >> user_input;
//
//
//
//	//arry[][user_input] = 'X';
//
//	for (size_t index = 0; index < Rows; index++)
//	{
//		for (size_t jndex = 0; jndex < Columns; jndex++)
//		{
//			std::cout << arry[index][jndex] << ' ';
//		}
//		std::cout << std::endl;
//	}
//
//
//	// Initialise the display to a line
//	const int out_buffer_size = 80;
//	char out_buffer[out_buffer_size]{ 0 };
//
//	// Creates a bunch of characters up until the buffer size with -1 for the buffer size
//	for (int index = 0; index < out_buffer_size - 1; ++index)
//	{
//		out_buffer[index] = '-';
//	}
//
//	// Arbitary loop
//	for (int index = 0; index < 10; ++index)
//	{
//		// Prints the line of characters
//		std::cout << out_buffer << "\n";
//
//		// Asks the user for what position they would like to change to 'A'
//		int position;
//		std::cin >> position;
//		// Changes the character at user position to 'A'
//		out_buffer[position] = 'A';
//
//		system("cls");
//	}
//
//	std::cout << out_buffer << "\n";
//
//
//	system("pause");
//	return 0;
//}








/*   TIC TAC TOE TESTING   */

#include <iostream>

using namespace std;

void displayBoard(char b[][3], int size);
void grabInput(char player);
void updateBoard(char b[3][3], int /*size*/, char player, char currentMove);
void checkWin();
void checkDraw();
bool isPlaying = true; //Not necessary but I'll keep it for future changes
bool hasWon = false;
bool hasDrawn = false;

char player = 'X';
char player2 = 'O';
char activePlayer = player;
char currentMove;

char b[3][3] =
{
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
};

int main()
{
	displayBoard(b, 3);

	while (isPlaying && !hasWon && !hasDrawn)
	{
		grabInput(activePlayer);
		char tile = b[0][currentMove - '1'];

		if (currentMove < '1' || currentMove >	'9')
			cout << "No such square.\n";

		else
		{
			if (tile == 'X' || tile == 'O')
			{
				cout << "Invalid Move\n";
			}
			else
			{
				updateBoard(b, 3, activePlayer, currentMove);
				checkWin();
				checkDraw();
			}

		}

		if (hasWon)
			system("pause");
		else
			displayBoard(b, 3);

		if (activePlayer == player) activePlayer = player2;
		else activePlayer = player;
	}

}

void displayBoard(char b[3][3], int size)
{
	system("cls");
	cout << "::Tic Tac Toe::\n\n";

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			cout << b[x][y];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void grabInput(char player)
{
	cout << "Enter your move " << player << ": ";
	cin >> currentMove;
}

void updateBoard(char b[3][3], int /*size*/, char player, char currentMove)
{
	if (currentMove > '0' && currentMove <= '9')
		b[0][currentMove - '1'] = player;
}

void checkWin()
{
	if (b[0][0] == 'X' && b[0][1] == 'X' && b[0][2] == 'X')
	{
		cout << "\nPlayer 1 Wins!\n\n";
		hasWon = true;
	}
	if (b[1][0] == 'X' && b[1][1] == 'X' && b[1][2] == 'X')
	{
		cout << "\nPlayer 1 Wins!\n\n";
		hasWon = true;
	}
	if (b[2][0] == 'X' && b[2][1] == 'X' && b[2][2] == 'X')
	{
		cout << "\nPlayer 1 Wins!\n\n";
		hasWon = true;
	}

	if (b[0][0] == 'X' && b[1][0] == 'X' && b[2][0] == 'X')
	{
		cout << "\nPlayer 1 Wins!\n\n";
		hasWon = true;
	}
	if (b[0][1] == 'X' && b[1][1] == 'X' && b[2][1] == 'X')
	{
		cout << "\nPlayer 1 Wins!\n\n";
		hasWon = true;
	}
	if (b[0][2] == 'X' && b[1][2] == 'X' && b[2][2] == 'X')
	{
		cout << "\nPlayer 1 Wins!\n\n";
		hasWon = true;
	}

	if (b[0][0] == 'X' && b[1][1] == 'X' && b[2][2] == 'X')
	{
		cout << "\nPlayer 1 Wins!\n\n";
		hasWon = true;
	}
	if (b[0][2] == 'X' && b[1][1] == 'X' && b[2][0] == 'X')
	{
		cout << "\nPlayer 1 Wins!\n\n";
		hasWon = true;
	}


	if (b[0][0] == 'O' && b[0][1] == 'O' && b[0][2] == 'O')
	{
		cout << "\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[1][0] == 'O' && b[1][1] == 'O' && b[1][2] == 'O')
	{
		cout << "\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[2][0] == 'O' && b[2][1] == 'O' && b[2][2] == 'O')
	{
		cout << "\nPlayer Wins!\n\n";
		hasWon = true;
	}

	if (b[0][0] == 'O' && b[1][0] == 'O' && b[2][0] == 'O')
	{
		cout << "\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[0][1] == 'O' && b[1][1] == 'O' && b[2][1] == 'O')
	{
		cout << "\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[0][2] == 'O' && b[1][2] == 'O' && b[2][2] == 'O')
	{
		cout << "\nPlayer Wins!\n\n";
		hasWon = true;
	}

	if (b[0][0] == 'O' && b[1][1] == 'O' && b[2][2] == 'O')
	{
		cout << "\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[0][2] == 'O' && b[1][1] == 'O' && b[2][0] == 'O')
	{
		cout << "\nPlayer Wins!\n\n";
		hasWon = true;
	}

}

void checkDraw()
{
	if (b[0][0] != '1' && b[0][1] != '2' && b[0][2] != '3' && b[1][0] != '4' && b[1][1] != '5' && b[1][2] != '6' &&
		b[2][0] != '7' && b[2][1] != '8' && b[2][2] != '9' && !hasWon)
		hasDrawn = true;
	if (hasDrawn)
	{
		cout << "\nThe game is a draw!\n\n";
		system("pause");
	}
}





/*   CREATING ARRAYS   */

//#include <iostream>
//#include <iomanip> // std::setw sets the amount of blank spaces before output (e.g. "      6")
//
//int main()
//{
//	const size_t M = 10;
//	const size_t N = 20;
//	int a[M][N] = {};
//
//	// User enters amount of desired rows and columns and checks to make sure they aren't exceding the boundries
//	std::cout << "Enter number of rows: (less than " << M << "): ";
//
//	size_t Rows;
//
//	std::cin >> Rows;
//
//	if (!(Rows < M) || (Rows == 0)) Rows = M - 1;
//
//	std::cout << "Enter number of columns: (less than " << N << "): ";
//
//	size_t Columns;
//
//	std::cin >> Columns;
//
//	if (!(Columns < N) || (Columns == 0)) Columns = N - 1;
//
//	std::cout << std::endl;
//
//	// Entering the numbers into the array
//	for (size_t i = 0; i < Rows; i++)
//	{
//		std::cout << "Enter " << Columns << " numbers for the row " << i << ": ";
//		for (size_t j = 0; j < Columns; j++)
//		{
//			std::cin >> a[i][j];
//		}
//	}
//	
//	// Math
//	for (size_t j = 0; j < Columns; j++)
//	{
//		a[Rows][j] = 1;
//	}
//	
//	for (size_t i = 0; i < Rows; i++)
//	{
//		for (size_t j = 0; j < Columns; j++)
//		{
//			a[i][Columns] += a[i][j];
//			//a[m][j] *= a[i][j];
//		}
//	}
//
//	std::cout << std::endl;
//
//	// Displaying the array
//	for (size_t i = 0; i < Rows; i++) // Rows
//	{
//		for (size_t j = 0; j < Columns + 1; j++) // Columns
//		{
//			std::cout << std::setw(3) << a[i][j] << ' ';
//		}
//		std::cout << '\n';
//	}
//
//	std::cout << std::endl;
//
//	system("Pause");
//}