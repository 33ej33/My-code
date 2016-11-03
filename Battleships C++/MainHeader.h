#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Ship
{
	string name;
	int size;
	int alive;
	int identifier;
	int hits;
};

//Game board array options
const int empty = 0;
const int missed = 2;
const int hit = 3;

const int MAXSHIPS = 8;
const int MAXSCORES = 10;

// Defining the fucntions
bool gettingShipPresent(int y, int x, int gameBoard[10][10], Ship listOfShips[]);
//Filling lists of ships
void fillingListOfShips(Ship listOfShips[], Ship listOfComputerShips[]);
//Placing ships 
bool playerPlacingShips(int gameBoard[10][10], Ship listOfShips[], bool playerPlacing);
void computerPlacingShips(int gameBoard[10][10], Ship listOfComputerShips[], bool playerPlacing, int automatic);
void changingBoard(int decision, int direction, int x, int y, int i, int gameBoard[10][10], Ship listOfShips[]);
//The board
void creatingBoard(int gameBoard[10][10]);
void creatingComputerBoard(int gameBoard[10][10]);
void printintgBoard(int gameBoard[10][10], bool playerPlacing, Ship listOfShips[]);
//Playing
int computersTurn(int playerGameBoard[10][10], Ship listOfPlayerShips[], int playerShipCounter);
void playing(int playerGameBoard[10][10], int computerGameBoard[10][10], Ship listOfPlayerShips[], Ship listOfComputerShips[MAXSHIPS], bool playerPlacing, int topScoresArray[10]);
//Saving and Loading
void saveScore(int score, int topScoresArray[MAXSCORES]);
void loadScore(int topScoresArray[MAXSCORES]);
//Displaying top scores
void displayScores(int topScoresArray[MAXSCORES]);
//Error check
int checkingIntError(int choice);