#include "MainHeader.h"

//Displaying the top ten scores
void displayScores(int topScoresArray[MAXSCORES])
{
	loadScore(topScoresArray);

	cout << endl;
	cout << "		-----The tops scores-----" << endl;

	for (int i = 0; i < MAXSCORES; i++)
	{
		cout << "			" << topScoresArray[i] << endl;
	}
}