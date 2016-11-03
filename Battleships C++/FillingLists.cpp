#include "MainHeader.h"

void fillingListOfShips(Ship listOfShips[], Ship listOfComputerShips[])
{
	ifstream inFile("ships.txt");

	for (int i = 0; i<MAXSHIPS; i++)
	{
		inFile >> listOfShips[i].name >> listOfShips[i].size >> listOfShips[i].alive >> listOfShips[i].identifier >> listOfShips[i].hits;
	}
	inFile.close();

	ifstream inFile2("ships.txt");
	for (int j = 0; j<MAXSHIPS; j++)
	{
		inFile2 >> listOfComputerShips[j].name >> listOfComputerShips[j].size >> listOfComputerShips[j].alive >> listOfComputerShips[j].identifier >> listOfComputerShips[j].hits;
	}
	inFile.close();
}
