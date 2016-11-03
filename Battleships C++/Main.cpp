#include "MainHeader.h"
int main(int argc, char** argv)
{
	// Two-dimensional array for gameboard.
	int playerGameBoard[10][10];
	int computerGameBoard[10][10];

	int topScoresArray[10];

	Ship listOfPlayerShips[MAXSHIPS];
	Ship listOfComputerShips[MAXSHIPS];

	bool playerPlacing = false;

	int automatic = 0;

	//Loading the scores into the top score array
	loadScore(topScoresArray);

	int choice = 0;
	bool valid = false;
	cout << "		-------------------------------------------------" << endl;
	cout << "		|		Welcome to Battleships		|" << endl;
	cout << "		-------------------------------------------------" << endl;

	while (valid == false)
	{
		//Main Menu
		cout << "1 - Play" << endl
			<< "2 - Scores" << endl
			//<< ""
			<< "3 - Exit" << endl
			<< "Key in your choice" << endl;
		cin >> choice;
		cout << endl;

		if (choice == 1)
		{
			creatingBoard(playerGameBoard);
			creatingComputerBoard(computerGameBoard);
			fillingListOfShips(listOfPlayerShips, listOfComputerShips);
			printintgBoard(playerGameBoard, playerPlacing, listOfPlayerShips);
			playerPlacing = playerPlacingShips(playerGameBoard, listOfPlayerShips, playerPlacing);
			computerPlacingShips(computerGameBoard, listOfComputerShips, playerPlacing, automatic);
			playing(playerGameBoard, computerGameBoard, listOfPlayerShips, listOfComputerShips, playerPlacing, topScoresArray);
		}
		else if (choice == 2)
		{
			displayScores(topScoresArray);
		}
		else if (choice == 3)
		{
			valid = true;
			return 0;
		}
		else
		{
			choice = checkingIntError(choice);
			if (choice < 0 || choice > 3)
			{
				cout << "Your choice was not valid try again.\n" << endl;
			}
		}
	}
	return 0;
}

//Cheking if there is a ship on the picked possition 
bool gettingShipPresent(int y, int x, int gameBoard[10][10], Ship listOfShips[])
{
	bool shipPresent = false;

	for (int i = 0; i < MAXSHIPS; i++)
	{
		if (listOfShips[i].identifier == gameBoard[y][x])
		{
			shipPresent = true;
			break;
		}
		else
		{
			shipPresent = false;
		}
	}
	return shipPresent;
}




