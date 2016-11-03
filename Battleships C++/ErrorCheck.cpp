#include "MainHeader.h"

//Dealing with user entering a valid option 
int checkingIntError(int choice)
{
	int counter = 0;
	while (cin.fail())
	{
		if (counter == 0)
		{
			cout << "\nThe option u have entered is not valid, try again." << endl;
			cout << "choice: ";
			counter ++;
		}
		cin.clear(); //Clear errors
		cin.ignore();//Resets current input
		cin >> choice;
	}
	return choice;
}