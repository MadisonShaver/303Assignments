#include <iostream>
#include <fstream>
#include <tuple>
#include "Assignment1.h"
using namespace std;

/** Fills the array with original values
	pre: size, currSize are positive
	@param nums is an empty array
	@param size is the permanent size of nums
	@param currSize is the size of nums excluding 0s at the end
	post: array gets 100 elements filled from a file, fills the rest with zeros 
*/
void fillArr(int nums[], int size, int currSize)
{
	ifstream input;
	input.open("integers.txt");

	for (int i = 0; i < currSize; i++)
	{
		input >> nums[i];
	}
	input.close();

	for (int i = currSize; i < size; i++)
	{
		nums[i] = 0;
	}
}

/** Prints array
	pre: size, currSize are positive
	@param nums is an array filled with integers
	@param size is the permanent size of nums
	@param currSize is the size of nums excluding 0s at the end
	post: array gets printed to the user separated by commas
*/
void printArr(int nums[], int size, int currSize)
{
	cout << "Array is: ";

	for (int i = 0; i < currSize - 1; i++)
	{
		cout << nums[i] << ", ";
	}

	cout << nums[currSize - 1] << endl << endl;
}

/** Searches array for integer of users choosing
	pre: size is positive
	@param nums is an array filled with integers
	@param size is the permanent size of nums
	@return the index of the integer the user wanted to search for, -1 if not found
*/
int checkArr(int nums[], int size)
{
	int userInt;
	cout << "Enter an integer to search for." << endl;
	cin >> userInt;

	for (int i = 0; i < size; i++)
	{
		if (nums[i] == userInt)
			return i;
	}
	return -1;
}

/** Changes an integer at an index of the user's choosing
	pre: size is positive
	@param nums is an array filled with integers
	@param size is the permanent size of nums
	post: an integer at index of user's choosing is changed to a new integer of user's choosing
*/
void modArray(int nums[], int size)
{
	int modIndex, newInt;
	cout << "What is the index of the number you would like to change (0 - 99)?" << endl;
	cin >> modIndex;
	
	while (modIndex < 0 || modIndex > 99)
	{
		cout << "Your number is not within the range (0 - 99). Try again." << endl;
		cin >> modIndex;
	}

	cout << "What number would you like to put there instead?" << endl;
	cin >> newInt;

	cout << "Old integer was " << nums[modIndex] << "." << endl;
	cout << "New integer is " << newInt << "." << endl;
	nums[modIndex] = newInt;
}

/** Changes the first 0 to an integer of the user's choosing (gives the impression of adding to the array)
	pre: size, currSize are positive, currSize is less than size
	@param nums is an array filled with integers
	@param size is the permanent size of nums
	@param currSize is the size of nums excluding 0s at the end
	@return the new currSize to change currSize in main (1 added to currSize)
*/
int addEnd(int nums[], int size, int currSize)
{
	int userNum;
	cout << "What number would you like to add to the array?" << endl;
	cin >> userNum;
	nums[currSize] = userNum;
	return currSize + 1;
}

/** Changes an integer at the index of the user's choosing to 0 and moves it to the end
	pre: size, currSize are positive, currSize is not 0
	@param nums is an array filled with integers
	@param size is the permanent size of nums
	@param currSize is the size of nums excluding 0s at the end
	@return the new currSize to change currSize in main (1 subtracted from currSize)
*/
int removeInt(int nums[], int size, int currSize)
{
	int userInd, temp;
	cout << "What is the index of the number you would like to remove?" << endl;
	cin >> userInd;
	nums[userInd] = 0;

	for (int i = userInd; i < currSize; i++)
	{
		temp = nums[i];
		nums[i] = nums[i + 1];
		nums[i + 1] = temp;
	}

	return currSize - 1;
}