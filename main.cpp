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
	string answer1, answer2, answer3, answer4, answer5, answer6;
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

		if(answer2 == bill)
		{
			input.appendNeedsBills(outNeeds, billAmount, needsAmount);
			system("pause");
		} 
		else if(answer2 == frivolity)
		{
			input.appendWantsFrivolity(outWants, frivolityAmount, wantsAmount);
			system("pause");
		}
		else if (answer2 == emergency)
		{
			input.appendSavingsEmergency(outSavings, emergencyAmount, savingsAmount);
			system("pause");
		}
		
	}

	if (answer2 == no)
	{
		cout << "Great!" << endl;
	}

do
{
	cout << "Are all operations complete? (y/n)\n";
	cin >> answer3;

	if(answer3 == yes)
	{
		cout << "Goodbye!\n";
		exit(1);
	}
	else if (answer3 == no)
	{
		cout << "Would you like to view or edit files (edit/view)\n";
		cin >> answer4;

		if (answer4 == edit)
		{
			cout << "Which file would you like to edit?\n"
				<< "1 = savings_file.txt, 2 = needs_file.txt, 3 = wants_file.txt" << endl;
			cin >> answer5;

			if (answer5 == "1")
			{
				//make a file opener for savings
				cout << "Opening chosen file for editing/viewing...\n";
				
			}
			else if (answer5 == "2")
			{
				//make a file opener for needs
			}
			else if (answer5 == "3")
			{
				//make a file opener for wants
			}
		}
		else if (answer4 == view)
		{
			cout << "Which file would you like to view?\n"
				<< "1 = savings_file.txt, 2 = needs_file.txt, 3 = wants_file.txt" << endl;
			cin >> answer6;

			if (answer6 == "1")
			{
				//make a file opener for savings
			}
			else if (answer6 == "2")
			{
				//make a file opener for needs
			}
			else if (answer6 == "3")
			{
				//make a file opener for wants
			}
		}
	}
	
} while (answer3 == yes);

	return 0;
}