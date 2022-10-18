#include <iostream>
#include <fstream>
#include "Assignment1.h"
using namespace std;

int main()
{
	char userChoice = 'y';
	int nums[150], currSize = 100; //currSize is the size of the array not including the 0s at the end
	fillArr(nums, 150, currSize); //initializes nums
	printArr(nums, 150, currSize);

	while (userChoice != 'q')
	{
		cout << "What would you like to do?" << endl;
		cout << "s - search for integer in array" << endl;
		cout << "c - change an integer in array" << endl;
		cout << "a - add an integer to array" << endl;
		cout << "d - delete an integer from array" << endl;
		cout << "q - quit" << endl;
		cin >> userChoice;

		switch (userChoice)
		{
		case 's':
		{
			int index = checkArr(nums, 150); //searches for integer of user's choosing

			if (index == -1) //integer not found
				cout << "Number not found in the array." << endl; 
			else
				cout << "Number found at index " << index << "." << endl;

			break;
		}
		case 'c':
		{
			modArray(nums, 150); //changes an integer at index of user's choosing to new integer of user's choosing
			printArr(nums, 150, currSize);
			break;
		}
		case 'a':
		{
			if (currSize >= 150) //cannot make array larger than it already is
				cout << "You have too many integers. You must delete one before adding another." << endl;
			else
				currSize = addEnd(nums, 150, currSize); //changes next element (0) to a new integer of user's choosing and adds 1 to currSize

			printArr(nums, 150, currSize);
			break;
		}
		case 'd':
		{
			if (currSize <= 0) //all integers are 0
				cout << "There are no more integers in the array. You must add one before deleting another." << endl;
			else
				currSize = removeInt(nums, 150, currSize); //changes element of user's choosing to 0 and moves it to the ends, subtracts 1 from currSize

			printArr(nums, 150, currSize);
			break;
		}
		case 'q': 
		{
			break;
		}
		default:
		{
			cout << "You did not enter a valid option." << endl;
			break;
		}
		}
	}
}
