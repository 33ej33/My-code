#include "MainHeader.h"

// Function to initialize players gameboard.
void creatingBoard(int gameBoard[10][10])
{
	// create a blank board   
	for (int x = 1; x <= 10; x++)
	{
		for (int y = 1; y <= 10; y++)
		{
			gameBoard[x][y] = empty;
		}
	}
}
// Function to initialize computers gameboard.
void creatingComputerBoard(int gameBoard[10][10])
{
	// create a blank board   
	for (int x = 1; x <= 10; x++)
	{
		for (int y = 1; y <= 10; y++)
		{
			gameBoard[x][y] = empty;
		}
	}
}
//Printing the actual board on the screen
void printintgBoard(int gameBoard[10][10], bool playerPlacing, Ship listOfShips[])
{
	bool shipPresent;
	//letter coordinates
	for (int j = 1; j <= 10; j++) 
	{ 
		cout << setw(5) << j;
	}
	cout << endl;
	//number coordinates
	for (int i = 1; i <= 10; i++) 
	{ 
		if (i == 10)
		{
			cout << i;
		}
		else
		{
			cout << " " << i;
		}
		for (int j = 1; j <= 10; j++)
		{
			shipPresent = gettingShipPresent(i, j, gameBoard, listOfShips);
			if (playerPlacing && shipPresent)
			{
				cout << setw(5) << "S|";
			}
			else if (shipPresent || gameBoard[i][j] == empty)
			{
				cout << setw(5) << " |";
			}
			else if (gameBoard[i][j] == missed) 
			{
				cout << setw(5) << "O|";
			}
			else if (gameBoard[i][j] == hit) 
			{
				cout << setw(5) << "X|";
			}
		}
		cout << "\n";
	}
}