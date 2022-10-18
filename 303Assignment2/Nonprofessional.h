#pragma once
#include "Employee.h"

class Nonprofessional : public Employee {
private:
	double payRate = 15; //dollars per hour
	double vacPerYear = 6; //days per year
	double healthPerc = 0.09; //9% taken out of paycheck
public:
	double pay();
	double vacDays();
	double healthIns();
};
