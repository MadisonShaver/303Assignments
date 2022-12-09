#include <queue>
#include <map>
#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	queue<string> names;	//start of part 1
	names.push("Lee");		//adding elements to the queue
	names.push("Julio");
	names.push("Ashton");
	names.push("Aissa");

	cout << "Before first element is moved to the rear:" << endl;
	printQueue(names);		//outputs queue before the first element is moved

	move_to_rear(names);	//moves first element is queue to the rear
	cout << "After first element was moved to the rear:" << endl;
	printQueue(names);		//outputs queue after moving the first element


	string name1 = "hannah", name2 = "riley", name3 = "pip";	//start of part 2
	int pal = palindrome(name1, 0, name1.length() - 1);			//checks if the name is a palindrome
	printPalindrome(pal, name1);								//outputs based on whether name is palindrome or not

	pal = palindrome(name2, 0, name2.length() - 1);
	printPalindrome(pal, name2);

	pal = palindrome(name3, 0, name3.length() - 1);
	printPalindrome(pal, name3);

	
	map<string, string> stateDataMap;				//start of part 5
	stateDataMap["Nebraska"] = "Lincoln";			//adds items to map
	stateDataMap["New York"] = "Albany";
	stateDataMap["Ohio"] = "Columbus";
	stateDataMap["California"] = "Sacramento";
	stateDataMap["Massachusetts"] = "Boston";
	stateDataMap["Texas"] = "Austin";

	printCapitals(stateDataMap);					//outputs items in map
	stateDataMap["California"] = "Los Angeles";
	printCapitals(stateDataMap);
	printUserCap(stateDataMap);						//outputs capital of state the user inputs

	return 0;
}