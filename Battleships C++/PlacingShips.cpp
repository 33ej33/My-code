#include "MainHeader.h"

bool playerPlacingShips(int gameBoard[10][10], Ship listOfShips[], bool playerPlacing)
{
	playerPlacing = true;
	bool willFit = false;
	bool noBoat;
	bool shipPresent;

	int totalCheck = 0;

	int x = 0;
	int y = 0;

	int decision = 0;
	int direction = 0;
	int automatic;

	cout << "Now you will place your ships" << endl;
	cout << "You have 8 ships" << endl;
	cout << "3 Scouts, 2 Battleships ,2 Destroyers, 1 Aircraft Carier" << endl;

	//Placing the ships automatically
	cout << "\nDo you want your ships to be placed automatically?" << endl;
	cout << "Key in 1 for yes and 0 for no: ";
	cin >> automatic;
	//Checking if current input is valid
	automatic = checkingIntError(automatic);
	if (automatic < -1 || automatic > 1)
	{
		while (x < -1 || x > 1)
		{
			automatic = checkingIntError(automatic);
			cout << "\nYour input is invalid try again." << endl;
			cout << "Automatic: ";
			cin >> automatic;
		}
	}

	if (automatic == 1)
	{
		computerPlacingShips(gameBoard, listOfShips, playerPlacing, automatic);
		printintgBoard(gameBoard, playerPlacing, listOfShips);
	}
	else
	{

		for (int i = 0; i < MAXSHIPS; i++)
		{
			willFit = false;

			while (willFit == false)
			{
				decision = 0;
				direction = 0;
				noBoat = true;

				//Getting the starting possition of the ship
				cout << "Pick on the grid where do u want to place the ship - " << listOfShips[i].name << endl;
				cout << "X position : " << endl;
				cin >> x;
				//Checking if current input is valid
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
				cout << "Y position : " << endl;
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
				shipPresent = gettingShipPresent(y, x, gameBoard, listOfShips);
				if (shipPresent)
				{
					willFit = false;
					cout << "There is already a ship placed on that possition" << endl;
				}
				else
				{
					//Deciding if the ship is going to be horizontal or vertical
					if (listOfShips[i].size == 1)
					{
						willFit = true;
					}
					else if (listOfShips[i].size > 1)
					{
						cout << "Choose if u want to place it vertically '1' or horizontally '2' : " << endl;
						cin >> decision;
						//Input error check
						decision = checkingIntError(decision);
						if (decision < 0 || decision > 2)
						{
							while (decision < 0 || decision > 10)
							{
								decision = checkingIntError(decision);
								cout << "\nYour input is invalid try again." << endl;
								cout << "Decision: ";
								cin >> decision;
							}
						}
						//Deciding if the ship is going to be up, down, left or right
						if (decision == 1)
						{
							cout << "Choose if what direction do want to place it up '1' or down '2' : " << endl;
							cin >> direction;
							//Input error check
							direction = checkingIntError(direction);
							if (direction < 0 || direction > 2)
							{
								while (direction < 0 || direction > 10)
								{
									direction = checkingIntError(direction);
									cout << "\nYour input is invalid try again." << endl;
									cout << "Direction: ";
									cin >> direction;
								}
							}
						}
						if (decision == 2)
						{
							cout << "Choose if what direction do want to place it left '1' or right '2' : " << endl;
							cin >> direction;
							//Input error check
							direction = checkingIntError(direction);
							if (direction < 0 || direction > 2)
							{
								while (direction < 0 || direction > 10)
								{
									direction = checkingIntError(direction);
									cout << "\nYour input is invalid try again." << endl;
									cout << "Direction: ";
									cin >> direction;
								}
							}
						}
						//Vertical
						if (decision == 1)
						{
							//UP
							if (direction == 1)
							{
								for (int k = 1; k < listOfShips[i].size; k++)
								{
									shipPresent = gettingShipPresent(y - k, x, gameBoard, listOfShips);
									if (shipPresent)
									{
										willFit = false;
										noBoat = false;
										cout << "There is already a ship placed on that possition \n" << endl;
									}
								}
								if (noBoat == true)
								{
									if ((y - (listOfShips[i].size)) >= 0 && willFit == false)
									{
										willFit = true;
									}
									else
									{
										willFit = false;
										cout << "Your ship is off the board try again \n" << endl;
									}
								}
							}
							//Down
							else if (direction == 2)
							{
								for (int k = 1; k < listOfShips[i].size; k++)
								{
									shipPresent = gettingShipPresent(y + k, x, gameBoard, listOfShips);
									if (shipPresent)
									{
										willFit = false;
										noBoat = false;
										cout << "There is already a ship placed on that possition \n" << endl;
									}
								}
								if (noBoat == true)
								{
									if ((y + (listOfShips[i].size - 1)) < 11 && willFit == false)
									{
										willFit = true;
									}
									else
									{
										willFit = false;
										cout << "Your ship is off the board try again \n" << endl;
									}
								}
							}
						}
						//Horizontal
						else if (decision == 2)
						{
							//Left
							if (direction == 1)
							{
								for (int k = 1; k < listOfShips[i].size; k++)
								{
									shipPresent = gettingShipPresent(y, x - k, gameBoard, listOfShips);
									if (shipPresent)
									{
										willFit = false;
										noBoat = false;
										cout << "There is already a ship placed on that possition \n" << endl;
									}
								}
								if (noBoat == true)
								{
									if ((x - (listOfShips[i].size)) >= 0 && willFit == false)
									{
										willFit = true;
									}
									else
									{
										willFit = false;
										cout << "Your ship is off the board try again \n" << endl;
									}
								}
							}
							//Right
							else if (direction == 2)
							{
								for (int k = 1; k < listOfShips[i].size; k++)
								{
									shipPresent = gettingShipPresent(y, x + k, gameBoard, listOfShips);
									if (shipPresent)
									{
										willFit = false;
										noBoat = false;
										cout << "There is already a ship placed on that possition \n" << endl;
									}
								}
								if (noBoat == true)
								{
									if (((listOfShips[i].size - 1) + x) < 11 && willFit == false)
									{
										willFit = true;
									}
									else
									{
										willFit = false;
										cout << "Your ship is off the board try again \n" << endl;
									}
								}
							}
						}
					}
				}
			}
			changingBoard(decision, direction, x, y, i, gameBoard, listOfShips);

			printintgBoard(gameBoard, playerPlacing, listOfShips);
			cout << endl;
		}
	}


	playerPlacing = false;
	return playerPlacing;
}

void computerPlacingShips(int gameBoard[10][10], Ship listOfShips[], bool playerPlacing, int automatic)
{
	bool willFit = false;
	bool noBoat;
	bool shipPresent;

	int totalCheck = 0;

	int x = 0;
	int y = 0;

	int decision = 0;
	int direction = 0;
	if (automatic == 1)
	{
		cout << "Your ships are being placed.......\n" << endl;
	}
	else
	{
		cout << "Now the computer places their ships.......\n" << endl;
	}
	
	for (int i = 0; i < MAXSHIPS; i++)
	{
		willFit = false;

		while (willFit == false)
		{

			srand(time(0));

			decision = 0;
			direction = 0;
			noBoat = true;

			//Getting the starting possition of the ship
			x = 1 + (rand() % 10);
			y = 1 + (rand() % 10);

			shipPresent = gettingShipPresent(y, x, gameBoard, listOfShips);
			if (shipPresent)
			{
				willFit == false;
			}
			else
			{
				//Deciding if the ship is going to be horizontal or vertical
				if (listOfShips[i].size == 1)
				{
					willFit = true;
				}
				else if (listOfShips[i].size > 1)
				{
					decision = 1 + (rand() % 2);
					//Deciding if the ship is going to be up, down, left or right
					if (decision == 1)
					{
						direction = 1 + (rand() % 2);
					}
					if (decision == 2)
					{
						direction = 1 + (rand() % 2);
					}

					//Vertical
					if (decision == 1)
					{
						//UP
						if (direction == 1)
						{
							for (int k = 1; k < listOfShips[i].size; k++)
							{
								shipPresent = gettingShipPresent(y - k, x, gameBoard, listOfShips);
								if (shipPresent)
								{
									willFit = false;
									noBoat = false;
								}
							}
							if (noBoat == true)
							{
								if ((y - (listOfShips[i].size)) >= 0 && willFit == false)
								{
									willFit = true;
								}
								else
								{
									willFit = false;
								}
							}
						}
						//Down
						else if (direction == 2)
						{
							for (int k = 1; k < listOfShips[i].size; k++)
							{
								shipPresent = gettingShipPresent(y + k, x, gameBoard, listOfShips);
								if (shipPresent)
								{
									willFit = false;
									noBoat = false;
								}
							}
							if (noBoat == true)
							{
								if ((y + (listOfShips[i].size - 1)) < 11 && willFit == false)
								{
									willFit = true;
								}
								else
								{
									willFit = false;
								}
							}
						}
					}
					//Horizontal
					else if (decision == 2)
					{
						//Left
						if (direction == 1)
						{
							for (int k = 1; k < listOfShips[i].size; k++)
							{
								shipPresent = gettingShipPresent(y,x - k, gameBoard, listOfShips);
								if (shipPresent)
								{
									willFit = false;
									noBoat = false;
								}
							}
							if (noBoat == true)
							{
								if ((x - (listOfShips[i].size)) >= 0 && willFit == false)
								{
									willFit = true;
								}
								else
								{
									willFit = false;
								}
							}
						}
						//Right
						else if (direction == 2)
						{
							for (int k = 1; k < listOfShips[i].size; k++)
							{
								shipPresent = gettingShipPresent(y,x + k, gameBoard, listOfShips);
								if (shipPresent)
								{
									willFit = false;
									noBoat = false;
								}
							}
							if (noBoat == true)
							{
								if (((listOfShips[i].size - 1) + x) < 11 && willFit == false)
								{
									willFit = true;
								}
								else
								{
									willFit = false;
								}
							}
						}
					}
				}
			}
		}
		changingBoard(decision, direction, x, y, i, gameBoard, listOfShips);
	}
}

//Applying the ships to the board
void changingBoard(int decision, int direction, int x, int y, int i, int gameBoard[10][10], Ship listOfShips[])
{
	int ship;
	ship = listOfShips[i].identifier;
	listOfShips[i].alive = 1;
	//Setting the ships point on the board
	//Scout
	if (listOfShips[i].size == 1)
	{
		gameBoard[y][x] = ship;
	}
	//Battleship
	else if (listOfShips[i].size == 2)
	{
		gameBoard[y][x] = ship;

		if (decision == 1)
		{
			if (direction == 1)
			{
				gameBoard[y - 1][x] = ship;
			}
			if (direction == 2)
			{
				gameBoard[y + 1][x] = ship;
			}
		}
		if (decision == 2)
		{
			if (direction == 1)
			{
				gameBoard[y][x - 1] = ship;
			}
			if (direction == 2)
			{
				gameBoard[y][x + 1] = ship;
			}
		}
	}
	//Destroyer
	else if (listOfShips[i].size == 3)
	{
		gameBoard[y][x] = ship;
		for (int j = 1; j <= 2; j++)
		{
			if (decision == 1)
			{
				if (direction == 1)
				{
					gameBoard[y - j][x] = ship;
				}
				if (direction == 2)
				{
					gameBoard[y + j][x] = ship;
				}
			}
			if (decision == 2)
			{
				if (direction == 1)
				{
					gameBoard[y][x - j] = ship;
				}
				if (direction == 2)
				{
					gameBoard[y][x + j] = ship;
				}
			}
		}
	}
	//Aircraft Carier
	else if (listOfShips[i].size == 4)
	{
		gameBoard[y][x] = ship;
		for (int j = 1; j <= 3; j++)
		{
			if (decision == 1)
			{
				if (direction == 1)
				{
					gameBoard[y - j][x] = ship;
				}
				if (direction == 2)
				{
					gameBoard[y + j][x] = ship;
				}
			}
			if (decision == 2)
			{
				if (direction == 1)
				{
					gameBoard[y][x - j] = ship;
				}
				if (direction == 2)
				{
					gameBoard[y][x + j] = ship;
				}
			}
		}
	}
}

