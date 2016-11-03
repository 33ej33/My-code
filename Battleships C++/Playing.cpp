#include "MainHeader.h"

void playing(int playerGameBoard[10][10], int computerGameBoard[10][10], Ship listOfPlayerShips[], Ship listOfComputerShips[MAXSHIPS], bool playerPlacing, int topScoresArray[10])
{
	int x = 0;
	int y = 0;
	int score = 0;
	int playerShipCounter = 0;
	int computerShipCounter = 0;
	bool nowPlaying = true;
	bool shipPresent;
	int seePlayersBoard;
	int playerMoves = 0;
	int seeBoardCounter = 0;

	//Display computers board
	printintgBoard(computerGameBoard, playerPlacing, listOfComputerShips);

	while (nowPlaying)
	{
		bool same = true;
		while (same)
		{
			if (seeBoardCounter == 5)
			{
				//Showing the players board
				cout << "\nDo you want to see your board?" << endl;
				cout << "Key in 1 for yes and 0 for no: ";
				cin >> seePlayersBoard;
				//Checking if current input is valid
				seePlayersBoard = checkingIntError(seePlayersBoard);
				if (seePlayersBoard < -1 || seePlayersBoard > 1)
				{
					while (seePlayersBoard < -1 || seePlayersBoard > 1)
					{
						cout << "\nYour input is invalid try again." << endl;
						cout << ": ";
						cin >> seePlayersBoard;
					}
				}

				if (seePlayersBoard == 1)
				{
					cout << "\nPlayers board." << endl;
					printintgBoard(playerGameBoard, playerPlacing, listOfPlayerShips);
				}
				seeBoardCounter = 0;
			}
			else
			{
				//Getting the position of the shot
				cout << "\nPick an X possition were you want to shoot: " << endl;
				cin >> x;
				//Input error check
				x = checkingIntError(x);
				if (x < 0 || x > 10)
				{
					while (x < 0 || x > 10)
					{
						x = checkingIntError(x);
						cout << "\nYour input is invalid try again." << endl;
						cout << "X: ";
						cin >> x;
					}
				}
				cout << "Pick an Y possition were you want to shoot: " << endl;
				cin >> y;
				//Input error check
				y = checkingIntError(y);
				if (y < 0 || y > 10)
				{
					while (y < 0 || y > 10)
					{
						y = checkingIntError(y);
						cout << "\nYour input is invalid try again." << endl;
						cout << "Y: ";
						cin >> y;
					}
				}
				if (computerGameBoard[y][x] != hit && computerGameBoard[y][x] != missed)
				{
					same = false;
					playerMoves++;
					seeBoardCounter++;
				}
				else if (computerGameBoard[y][x] == empty)
				{
					same = false;
					playerMoves++;
					seeBoardCounter++;
				}
				else
				{
					cout << "You have already fired on that position. \n" << endl;
				}
			}
		}
		shipPresent = gettingShipPresent(y, x, computerGameBoard, listOfComputerShips);
		if (shipPresent)
		{
			cout << "You have made a hit. \n" << endl;
			for (int i = 0; i < MAXSHIPS; i++)
			{
				if (listOfComputerShips[i].identifier == computerGameBoard[y][x])
				{
					listOfComputerShips[i].hits++;
					if (listOfComputerShips[i].size == listOfComputerShips[i].hits)
					{
						cout << "The ship : " << listOfComputerShips[i].name << " has been destroyed. \n" << endl;
						computerShipCounter++;
						cout << "The computer has " << MAXSHIPS - playerShipCounter << " ships left. \n" << endl;
					}
					break;
				}
			}
			computerGameBoard[y][x] = hit;
		}
		else if (computerGameBoard[y][x] == empty)
		{
			computerGameBoard[y][x] = missed;
			cout << "You have missed." << endl;
		}
		cout << "\nComputers board." << endl;
		printintgBoard(computerGameBoard, playerPlacing, listOfComputerShips);
		playerShipCounter = computersTurn(playerGameBoard, listOfPlayerShips, playerShipCounter);

		//Game ending
		if (computerShipCounter == MAXSHIPS)
		{
			cout << "You have won by destroying all of the enemy ships. \n" << endl;
			cout << "You have made " << playerMoves << " moves" << endl;
			fillingListOfShips(listOfComputerShips, listOfComputerShips);
			fillingListOfShips(listOfPlayerShips, listOfPlayerShips);
			score = playerMoves;
			saveScore(score, topScoresArray);
			nowPlaying = false;
		}
		if (playerShipCounter == MAXSHIPS)
		{
			cout << "The computer has won have by destroying all of your ships. \n" << endl;
			nowPlaying = false;
		}
	}
}
//Computers turn
int computersTurn(int playerGameBoard[10][10], Ship listOfPlayerShips[], int playerShipCounter)
{
	int x = 0;
	int y = 0;
	bool same = true;
	bool shipPresent;
	cout << "\nComputers turn" << endl;

	while (same)
	{
		//Getting the position of the shot
		x = 1 + (rand() % 10);
		y = 1 + (rand() % 10);
		if (playerGameBoard[y][x] != hit && playerGameBoard[y][x] != missed)
		{
			same = false;
		}
	}
	shipPresent = gettingShipPresent(y, x, playerGameBoard, listOfPlayerShips);
	if (shipPresent)
	{
		cout << "Computer has made a hit. \n" << endl;
		for (int i = 0; i < MAXSHIPS; i++)
		{
			if (listOfPlayerShips[i].identifier == playerGameBoard[y][x])
			{
				listOfPlayerShips[i].hits++;
				if (listOfPlayerShips[i].size == listOfPlayerShips[i].hits)
				{
					cout << "The ship : " << listOfPlayerShips[i].name << " has been destroyed. \n" << endl;
					playerShipCounter++;
					cout << "The player has " << MAXSHIPS - playerShipCounter << " ships left. \n" << endl;
				}
				break;
			}
		}
		playerGameBoard[y][x] = hit;
	}
	else if (playerGameBoard[y][x] == empty)
	{
		playerGameBoard[y][x] = missed;
		cout << "Computer has missed. \n" << endl;
	}
	return playerShipCounter;
}

