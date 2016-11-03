#include "MainHeader.h"

void loadScore(int topScoresArray[MAXSCORES])
{
	ifstream inFile("scores.txt");
	for (int i = 0; i < MAXSCORES; i++)
	{
		inFile >> topScoresArray[i];
	}
}

void saveScore(int score, int topScoresArray[MAXSCORES])
{
	for (int i = 0; i < MAXSCORES; i++)
	{
		if (topScoresArray[i] > score)
		{
			topScoresArray[i] = score;
			break;
		}
	}
	ofstream  outFile("scores.txt");
	for (int i = 0; i < MAXSCORES; i++)
	{
		outFile << topScoresArray[i];
	}
}