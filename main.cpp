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

//initialize income
/*BudgetClass::BudgetClass(double incomeValue, double billValue, double frivolityValue)
	: income(incomeValue), bill(billValue), frivolity(frivolityValue)
{
	testValue();
	//will check for nonnegative values
}

BudgetClass::BudgetClass()
	: income(0), bill(0), frivolity(0)
{
	testValue();
	//will check for nonnegative values
}

double BudgetClass::getNeeds(double incomeValue)
{
	double needs = incomeValue * 0.50;
	//needs covers 50% of income

	return(needs);
}

double BudgetClass::getWants(double incomeValue)
{
	double wants = incomeValue * 0.30;
	//wants covers 30% of income

	return(wants);
}

double BudgetClass::getSavings(double incomeValue)
{
	double savings = incomeValue * 0.20;
	//savings covers 20% of income

	return(savings);
}

double BudgetClass::getBills(double billValue)
{
	double bill = -billValue;
	//makes bill negative so you don't have to lazy bitch

	return(bill);
}

double BudgetClass::getFrivolity(double frivolityValue)
{
	double frivolity = -frivolityValue;
	//makes frivolity negative so you don't have to lazy bitch

	return(frivolity);
}

void BudgetClass::testValue()
{
	if (income < 0)
	{
		cout << "Error income inputs must be nonnegative;" << endl;
	}
}

void BudgetClass::appendIncome(ofstream& incomeStreamOut, double incomeValue)
{
	//set to two decimal places because thats how money works
	incomeStreamOut.setf(ios::fixed);
	incomeStreamOut.setf(ios::showpoint);
	incomeStreamOut.precision(2);

	//doesn't add income if zero
	if (incomeValue > 0)
	{
		cout << "Opening income_file.txt for appending...\n";
		incomeStreamOut.open("income_file.txt", ios::app);
		incomeStreamOut << incomeValue << endl;
		incomeStreamOut.close();
		cout << "Appending complete!\n";
		//append income_file with userIncome then close
	}
}

void BudgetClass::appendNeeds(ofstream& needsStreamOut, double needsValue)
{
	//set to two decimal places because that's how money works
	needsStreamOut.setf(ios::fixed);
	needsStreamOut.setf(ios::showpoint);
	needsStreamOut.precision(2);

	//doesn't append if there's nothing to append
	if (needsValue > 0)
	{
		cout << "Opening needs_file.txt for appending...\n";
		needsStreamOut.open("needs_file.txt", ios::app);
		needsStreamOut << needsValue << endl;
		needsStreamOut.close();
		cout << "Appending complete!\n";
		//append needs_file with needsAmount then close
	}
}

void BudgetClass::appendWants(ofstream& wantsStreamOut, double wantsValue)
{
	//sets to two decimal places because that's how money works
	wantsStreamOut.setf(ios::fixed);
	wantsStreamOut.setf(ios::showpoint);
	wantsStreamOut.precision(2);

	//doesn't append if theres nothing to append 
	if (wantsValue > 0)
	{
		cout << "Opening wants_file.txt for appending...\n";
		wantsStreamOut.open("wants_file.txt", ios::app);
		wantsStreamOut << wantsValue << endl;
		wantsStreamOut.close();
		cout << "Appending complete!\n";
		//append wants_file with wantsAmount then close
	}
}

void BudgetClass::appendSavings(ofstream& savingsStreamOut, double savingsValue)
{
	//sets to two decimal places because that's how money works
	savingsStreamOut.setf(ios::fixed);
	savingsStreamOut.setf(ios::showpoint);
	savingsStreamOut.precision(2);

	//doesn't append if there's nothing to append
	if (savingsValue > 0)
	{
		cout << "Opening savings_file.txt for appending...\n";
		savingsStreamOut.open("savings_file.txt", ios::app);
		savingsStreamOut << savingsValue << endl;
		savingsStreamOut.close();
		cout << "Appending complete!\n";
		//append savings_file.txt with savingsAmount then close
	}
}

void BudgetClass::appendBills(ofstream& billsStreamOut, double billsValue)
{
	//sets to two decimal places because that how money works
	billsStreamOut.setf(ios::fixed);
	billsStreamOut.setf(ios::showpoint);
	billsStreamOut.precision(2);

	//doesn't append if there's nothing to append
	if (billsValue < 0)
	{
		cout << "Opening needs_purchases_file.txt for appending...\n";
		billsStreamOut.open("needs_purchases_file.txt", ios::app);
		billsStreamOut << billsValue << endl;
		billsStreamOut.close();
		cout << "Appending complete!\n";
		//append needs_purchase_file.txt with bills amount
	}
}

void BudgetClass::appendFrivolity(ofstream& frivolityStreamOut, double frivolityValue)
{
	//sets to two decimal places because that how money works
	frivolityStreamOut.setf(ios::fixed);
	frivolityStreamOut.setf(ios::showpoint);
	frivolityStreamOut.precision(2);

	//doesn't append if there's nothing to append
	if (frivolityValue < 0)
	{
		cout << "Opening wants_purchases_files.txt for appending...\n";
		frivolityStreamOut.open("wants_purchases_files.txt", ios::app);
		frivolityStreamOut << frivolityValue << endl;
		frivolityStreamOut.close();
		cout << "Appending complete!\n";
		//append wants_purchases_files.txt with frivolity amount
	}
}*/
