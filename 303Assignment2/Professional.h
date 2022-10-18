#pragma once
#include "Employee.h"

class Professional : public Employee {
private:
	double payRate = 52000.00; //dollars per year
	double vacPerYear = 12; //days per year
	double healthPerc = 0.15; //15% taken out of paycheck
public:
	double pay();
	double vacDays();
	double healthIns();
};
