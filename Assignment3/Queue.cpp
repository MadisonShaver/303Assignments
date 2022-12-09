#include <queue>
#include <iostream>
#include "Queue.h"

using namespace std;

/** Outputs queue
		pre: q is not a reference, so it will not change the queue in main
		@param q is a queue made up of names
		post: queue gets outputted to user with each name on its own line
*/
void printQueue(queue<string> q)
{
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	cout << endl;
}

/**	Moves first element in the queue to the end
		pre: q is a reference, so it will be changed in main
		@param q is a queue made up of names
		post: first element in the queue gets removed from the front and added to the back
*/
void move_to_rear(queue<string> &q)
{
	string temp = q.front();
	q.pop();
	q.push(temp);
}

/** Checks if a string is a palindrome using recursion
		pre: start will always start as 0, end is one less than the size of a
		@param a is a name
		@param start is the starting index of a, adds 1 to it every recursive call
		@param end is the ending index of a, subtracts 1 from it every recursive call
		@return 1 if the name is a palindrome and 0 if it is not
*/
int palindrome(string a, int start, int end)
{
	if (end - start == 1 || start == end)
	{
		if (a[start] == a[end])
		{
			return 1;
		}
		return 0;
	}
	else
	{
		if (a[start] == a[end])
		{
			return palindrome(a, start + 1, end - 1);
		}
		return 0;
	}
}

/** Outputs a statement based on whether a is a palindrome or not
		pre: b is either 1 or 0
		@param b is based on the return value of palindrome()
		@param a is a string name
		post: Outputs that a is a palindrome or a is not a palindrome based what palindrome() returned
*/
void printPalindrome(int b, string a)
{
	if (b == 1)
	{
		cout << a << " is a palindrome." << endl << endl;
	}
	else
	{
		cout << a << " is not a palindrome." << endl << endl;
	}
}

/** Outputs a map using an iterator
		pre: map if pre-filled
		@param capitals is a map of states and their corresponding capitals
		post: outputs the capitals and states to user with each pair on its own line
*/
void printCapitals(map<string, string> capitals)
{
	for (map<string, string>::iterator itr = capitals.begin(); itr != capitals.end(); ++itr)
	{
		cout << itr->second << " is the capital of " << itr->first << "." << endl;
	}
	cout << endl;
}

/** Outputs a statement based on the user's input
		pre: map is pre-filled
		param@ capitals is a map of states and their corresponding capitals
		post: changes user input to start with a capital letter and the rest are lowercase, 
			then outputs the capital if the state was found in the map and not found if it was not
*/
void printUserCap(map<string, string> capitals)
{
	string userCap;
	cin >> userCap;

	userCap[0] = toupper(userCap[0]);					//changes first letter to uppercase
	for (int i = 1; i < userCap.size(); i++)
		userCap[i] = tolower(userCap[i]);				//changes the rest of the letters to lowercase

	map<string, string>::iterator itr = capitals.find(userCap);		//looks for user's input in map
	if (itr == capitals.end())
		cout << "State not found." << endl << endl;
	else
		cout << capitals[userCap] << endl << endl;
}