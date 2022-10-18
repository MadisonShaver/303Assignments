#include <iostream>
#include "Nonprofessional.h"
using namespace std;

//assume user = employee (both words are used interchangeably).

/** Calculates how much the employee should be paid
	pre: user enters a positive integer or double
	@return how much the employee should be paid based on their pay rate and hours they worked
*/
double Nonprofessional::pay()
{
	double hours;

	cout << "How many hours have you worked?" << endl;
	cin >> hours;

	return hours * payRate;
}

/** Asks user how many days they have worked and calculates the number of vacation days they
		should have
	pre: user should enter a positive integer or double
	@return number of vacation days the employee should receive based on how many vacation
		days they get per year and days they worked
*/
double Nonprofessional::vacDays()
{
	double days;

	cout << "How many days have you worked?" << endl;
	cin >> days;

	return (vacPerYear / 260) * days;
}

/* Calculates how much money was allocated to the user's health insurance
	pre: none
	@return amount of money allocated to health insurance based on user's pay, hours user
		worked, and the percentage of paycheck that goes toward health insurance
*/
double Nonprofessional::healthIns()
{
	double check = this->pay();
	return check * healthPerc;
}