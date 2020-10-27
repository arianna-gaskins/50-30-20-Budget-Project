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

	ofstream outIncome, outNeeds, outWants, outSavings, outBills, outFrivolity, outEmergency;

	double userIncome, userBill, userFrivolity, userEmergency;
	//declares income, bill, and frivolity for user input

	//answer types listed
	string answer1, answer2, answer3, answer4;
	string yes("y"), no("n"), bill("bill"), frivolity("frivolity"), emergency("emergency"), 
		edit("edit"), view("view");

	BudgetClass input(userIncome, userBill, userFrivolity, userEmergency), inputD;

	//returns needs, wants, and savings values
	//also returns bills and frivolous purchases
	double needsAmount = input.getNeeds(userIncome);
	double wantsAmount = input.getWants(userIncome);
	double savingsAmount = input.getSavings(userIncome);
	double billAmount = input.getBills(userBill);
	double frivolityAmount = input.getFrivolity(userFrivolity);
	double emergencyAmount = input.getEmergency(userEmergency);

	cout << "Please enter this week's income: " << endl;
	cin >> userIncome;

	input.appendIncome(outIncome, userIncome);
	system("pause");

	input.appendNeeds(outNeeds, needsAmount);
	system("pause");

	input.appendWants(outWants, wantsAmount);
	system("pause");

	input.appendSavings(outSavings, savingsAmount);
	system("pause");

	cout << "Did you purchase anything that you'd like to log here? (y/n) \n";
	cin >> answer1;

	if (answer1 == yes)
	{
		cout << "What kind of purchase was it? (bill/frivolity/emergency) \n";
		cin >> answer2;

		if(answer3 == bill)
		{
			input.appendNeedsBills(outNeeds, billAmount, needsAmount);
			system("pause");
		} 
		else if(answer3 == frivolity)
		{
			input.appendWantsFrivolity(outWants, frivolityAmount, wantsAmount);
			system("pause");
		}
		else if (answer3 == emergency)
		{
			input.appendSavingsEmergency(outSavings, emergencyAmount, savingsAmount);
			system("pause");
		}
		
	}

	if (answer3 == no)
	{
		cout << "Great!" << endl;
	}

	return 0;
}