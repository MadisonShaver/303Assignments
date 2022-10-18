#include <iostream>
#include <stdexcept>
#include "Professional.h"
#include "Nonprofessional.h"
using namespace std;

int main()
{
	cin.exceptions(ios_base::failbit);
	int empType; //professional (1) or nonprofessional (2)
	char userChoice;

	do
	{
		bool go = true;

		while (go)
		{

			try {
				cout << "Are you a (1)professional or (2)nonprofessional employee?" << endl;
				cout << "Please choose 1 or 2." << endl;
				cin >> empType;

				if (empType != 1 && empType != 2)
					throw out_of_range("You did not choose 1 or 2. Try again.");

				go = false;
			}
			catch (ios_base::failure) //runs if incorrect type was entered
			{
				cout << "Invalid input. Try again." << endl;
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
			}
			catch (out_of_range& ex) //runs if incorrect int is entered
			{
				cout << ex.what() << endl;
			}
			catch (...) //catches any other error
			{
				cout << "An unknown error occured. Try again." << endl;
			}
		}

		if (empType == 1)
		{
			Professional emp;

			do
			{
				emp.printOptions();
				cin >> userChoice;

				switch (userChoice)
				{
				case 'p':
				{
					double payCheck = emp.pay(); //calculates pay for time period that user enters
					cout << "You have earned $" << payCheck << endl << endl;
					break;
				}
				case 'v':
				{
					double vac = emp.vacDays(); //calculates vacation days for time period that user enters
					cout << "You have " << vac << " vacation days." << endl << endl;
					break;
				}
				case 'h':
				{
					double health = emp.healthIns(); //calculates health insurance contribution based on time period user enters
					cout << "$" << health << " has been allocated for health insurance." << endl << endl;
					break;
				}
				case 'e': //exits back to the beginning of the program (exits inner loop)
				{
					break; 
				}
				case 'q': //exits entire program (inner and outer loop)
				{
					break; 
				}
				default: //catches any other input
				{
					cout << "You did not enter a valid option. Try again." << endl << endl;
					break;
				}
				}
			} while (userChoice != 'e' && userChoice != 'q');

		}
		else if (empType == 2)
		{
			Nonprofessional emp;

			do
			{
				emp.printOptions();
				cin >> userChoice;

				switch (userChoice)
				{
				case 'p':
				{
					double payCheck = emp.pay(); //calculates pay for time period that user enters
					cout << "You have earned $" << payCheck << endl << endl;
					break;
				}
				case 'v':
				{
					double vac = emp.vacDays(); //calculates vacation days for time period that user enters
					cout << "You have " << vac << " vacation days." << endl << endl;
					break;
				}
				case 'h':
				{
					double health = emp.healthIns(); //calculates health insurance contribution based on time period user enters
					cout << "$" << health << " has been allocated for health insurance." << endl << endl;
					break;
				}
				case 'e': //exits back to the beginning of the program (exits inner loop)
				{
					break;
				}
				case 'q': //exits entire program (inner and outer loop)
				{
					break;
				}
				default: //catches any other input
				{
					cout << "You did not enter a valid option. Try again." << endl << endl;
					break;
				}
				}
			} while (userChoice != 'e' && userChoice != 'q');

		}
	} while (userChoice != 'q');
	
	return 0;
}