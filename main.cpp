//main.cpp
#include <iostream>   // std input and output
#include <fstream>    // input and output from files or disk
#include <string>     // String Processing Functions
#include <iomanip>    // stream manipulators to format streams of data
#include <cmath>      // Math Functions
#include <cctype>     // test characters for certain properties, convert case
#include <cstdlib>    // Conversions Numbers to text, memory allocation
#include <ctime>      // Time and date functions
#include <climits>    // contains the integeral size limits of the system
#include <cfloat>     // contains the floating point size limits of the system

#include "BudgetClass.h"

using namespace std;

int main()
{

#pragma region HEADER
	cout << "\n*******************************************************\n";
	cout << "*   Author: Arianna Gaskins\n";
	cout << "*	 Program: 50/30/20 Budget\n";
	printf("*   Program created on %s at %s\n", __DATE__, __TIME__);
	cout << "*******************************************************\n\n";
#pragma endregion comment

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	system("pause");

	ofstream outIncome, outNeeds, outWants, outSavings, outBills, outFrivolity;

	double userIncome, userBill, userFrivolity;
	//declares income, bill, and frivolity for user input

	string answer1, answer2;
	string yes("y"), no("n"), bill("bill"), frivolity("frivolity");

	BudgetClass input(userIncome, userBill, userFrivolity), inputD;

	//returns needs, wants, and savings values
	//also returns bills and frivolous purchases
	double needsAmount = input.getNeeds(userIncome);
	double wantsAmount = input.getWants(userIncome);
	double savingsAmount = input.getSavings(userIncome);
	double billAmount = input.getBills(userBill);
	double frivolityAmount = input.getFrivolity(userFrivolity);

	//establishes funtion pointer type
	typedef void (*fn_ptr)(ofstream&, double);

	//jumptable array for pointing to each function as needed
	//going to change to switch statements
	fn_ptr appendAppendix[6];
	appendAppendix[0] = input.appendIncome;
	appendAppendix[1] = input.appendNeeds;
	appendAppendix[2] = input.appendWants;
	appendAppendix[3] = input.appendSavings;
	appendAppendix[4] = input.appendBills;
	appendAppendix[5] = input.appendFrivolity;

	cout << "Please enter this week's income: " << endl;
	cin >> userIncome;

	//append everything affected by the income and pause inbetween so it doesn't look scary 
	appendAppendix[0](outIncome, userIncome);
	system("pause");

	appendAppendix[1](outNeeds, needsAmount);
	system("pause");

	appendAppendix[2](outWants, wantsAmount);
	system("pause");

	appendAppendix[3](outSavings, savingsAmount);
	system("pause");

	cout << "Did you purchase anything that you'd like to log here? (y/n) \n";
	cin >> answer1;

	if (answer1 == yes)
	{
		cout << "What kind of purchase was it? (bill/frivolity) /n";
		cin >> answer2;

		if (answer2 == bill)
		{
			//asks for user input for bill amount
			cout << "Please enter bill amount below (*note positive numbers only): \n";
			cin >> userBill;

			//append bill
			appendAppendix[4](outBills, billAmount);
		}
		else if (answer2 == frivolity)
		{
			//asks for user input for frivolous purchase amount
			cout << "Please enter the frivolous purchase amount (*note positive numbers only): \n";
			cin >> userFrivolity;

			//append frivolity
			appendAppendix[5](outFrivolity, frivolityAmount);
		}

	}
	else if (answer1 == no)
	{
		cout << "Good job! Save that money!" << endl;
	}



	return 0;
}