#pragma once
#include <iostream>
using namespace std;

class Employee { //abstract class to provide layout of Professional and Nonprofessional classes
private:
	double payRate; 
	double vacPerYear; 
	double healthPerc; 
public:
	virtual double pay() = 0;
	virtual double vacDays() = 0;
	virtual double healthIns() = 0;

	void printOptions() //this will be the same for both classes
	{
		cout << "Choose what you would like to do." << endl;
		cout << "p - check how much money you have made" << endl;
		cout << "v - check how many vacation days you have" << endl;
		cout << "h - check how much money has gone into your health insurance" << endl;
		cout << "e - exit to the beginning" << endl;
		cout << "q - quit and leave the program" << endl << endl;
	}
};