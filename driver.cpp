//driver.cpp
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

//initialize income
BudgetClass::BudgetClass(double incomeValue, double billValue, double frivolityValue, double emergencyValue)
	: income(incomeValue), bill(billValue), frivolity(frivolityValue), emergency(emergencyValue)
{
	testValue();
	//will check for nonnegative values
}

BudgetClass::BudgetClass()
	: income(0), bill(0), frivolity(0), emergency(0)
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
	//double wants = incomeValue * 0.30;
	//wants covers 30% of income

	return(9.99);
}

double BudgetClass::getSavings(double incomeValue)
{
	//double savings = incomeValue * 0.20;
	//savings covers 20% of income

	return(9.99);
}

double BudgetClass::getBills(double billValue)
{
	//double bill = -billValue;
	//makes bill negative so you don't have to lazy bitch

	return(9.99);
}

double BudgetClass::getFrivolity(double frivolityValue)
{
	//double frivolity = -frivolityValue;
	//makes frivolity negative so you don't have to lazy bitch

	return(9.99);
}

double BudgetClass::getEmergency(double emergencyValue)
{
	//double emergency = -emergencyValue;
	//makes emergency negative so you don't have to lazy bitch

	return(9.99);
}

void BudgetClass::testValue()
{
	/*if (income < 0)
	{
		cout << "Error income inputs must be nonnegative;" << endl;
	}*/
}

void BudgetClass::appendIncome(ofstream& incomeStreamOut, double incomeValue)
{
    /*
	//set to two decimal places because thats how money works
	incomeStreamOut.setf(ios::fixed);
	incomeStreamOut.setf(ios::showpoint);
	incomeStreamOut.precision(2);

	//doesn't add income if zero
	if (incomeValue > 0)
	{
		cout << "Opening income_file.txt for appending...\n";
		incomeStreamOut.open("income_file.txt", ios::app);

		//so we can know if the file opening fails
		if (incomeStreamOut.fail())
		{
			cout << "Opening income_file.txt failed. \n";
			exit(1);
		}

		incomeStreamOut << "$" << incomeValue << endl;
		incomeStreamOut.close();
		cout << "Appending complete!\n";
		//append income_file with userIncome then close
	}*/
}

void BudgetClass::appendNeeds(ofstream& needsStreamOut, double needsValue)
{
    /*
	//set to two decimal places because that's how money works
	needsStreamOut.setf(ios::fixed);
	needsStreamOut.setf(ios::showpoint);
	needsStreamOut.precision(2);

	//doesn't append if there's nothing to append
	if (needsValue > 0)
	{
		cout << "Opening needs_file.txt for appending...\n";
		needsStreamOut.open("needs_file.txt", ios::app);

		//so we can know if the file opening fails
		if (needsStreamOut.fail())
		{
			cout << "Opening needs_file.txt failed. \n";
			exit(1);
		}

		needsStreamOut << "$" << needsValue << endl;
		needsStreamOut.close();
		cout << "Appending complete!\n";
		//append needs_file with needsAmount then close
	}*/
}

void BudgetClass::appendWants(ofstream& wantsStreamOut, double wantsValue)
{
    /*
	//sets to two decimal places because that's how money works
	wantsStreamOut.setf(ios::fixed);
	wantsStreamOut.setf(ios::showpoint);
	wantsStreamOut.precision(2);

	//doesn't append if theres nothing to append 
	if (wantsValue > 0)
	{
		cout << "Opening wants_file.txt for appending...\n";
		wantsStreamOut.open("wants_file.txt", ios::app);

		//so we can know if the file opening fails
		if (wantsStreamOut.fail())
		{
			cout << "Opening wants_file.txt failed. \n";
			exit(1);
		}

		wantsStreamOut << "$" << wantsValue << endl;
		wantsStreamOut.close();
		cout << "Appending complete!\n";
		//append wants_file with wantsAmount then close
	}*/
}

void BudgetClass::appendSavings(ofstream& savingsStreamOut, double savingsValue)
{
    /*
	//sets to two decimal places because that's how money works
	savingsStreamOut.setf(ios::fixed);
	savingsStreamOut.setf(ios::showpoint);
	savingsStreamOut.precision(2);

	//doesn't append if there's nothing to append
	if (savingsValue > 0)
	{
		cout << "Opening savings_file.txt for appending...\n";
		savingsStreamOut.open("savings_file.txt", ios::app);

		//so we can know if the file opening fails
		if (savingsStreamOut.fail())
		{
			cout << "Opening savings_file.txt failed. \n";
			exit(1);
		}

		savingsStreamOut << "$" << savingsValue << endl;
		savingsStreamOut.close();
		cout << "Appending complete!\n";
		//append savings_file.txt with savingsAmount then close
	}*/
}

void BudgetClass::appendNeedsBills(ofstream& needsStreamOut, double billsValue, double needsValue)
{
    /*
	//sets to two decimal places because that how money works
	needsStreamOut.setf(ios::fixed);
	needsStreamOut.setf(ios::showpoint);
	needsStreamOut.precision(2);

	//doesn't append if there's nothing to append
	if (billsValue < 0)
	{
		cout << "Opening needs_file.txt for appending...\n";
		needsStreamOut.open("needs_file.txt", ios::app);

		//so we can know if the file opening fails
		if (needsStreamOut.fail())
		{
			cout << "Opening needs_file.txt failed. \n";
			exit(1);
		}

		needsStreamOut << "$" << billsValue + needsValue << endl;
		needsStreamOut.close();
		cout << "Appending complete!\n";
		//append needs_file.txt with bills amount
	}*/
}

void BudgetClass::appendWantsFrivolity(ofstream& wantsStreamOut, double frivolityValue, double wantsValue)
{
    /*
	//sets to two decimal places because that how money works
	wantsStreamOut.setf(ios::fixed);
	wantsStreamOut.setf(ios::showpoint);
	wantsStreamOut.precision(2);

	//doesn't append if there's nothing to append
	if (frivolityValue < 0)
	{
		cout << "Opening wants_files.txt for appending...\n";
		wantsStreamOut.open("wants_files.txt", ios::app);

		//so we can know if the file opening fails
		if (wantsStreamOut.fail())
		{
			cout << "Opening wants_file.txt failed. \n";
			exit(1);
		}

		wantsStreamOut << "$" << frivolityValue + wantsValue << endl;
		wantsStreamOut.close();
		cout << "Appending complete!\n";
		//append wants_purchases_files.txt with frivolity amount
	}*/
}

void appendSavingsEmergency(ofstream& savingsStreamOut, double emergencyValue, double savingsValue)
{
    /*
	//sets to two decimal places because that's how money works
	savingsStreamOut.setf(ios::fixed);
	savingsStreamOut.setf(ios::showpoint);
	savingsStreamOut.precision(2);

	//doesn't append if there's nothing to append
	if (savingsValue > 0)
	{
		cout << "Opening savings_file.txt for appending...\n";
		savingsStreamOut.open("savings_file.txt", ios::app);

		//so we can know if the file opening fails
		if (savingsStreamOut.fail())
		{
			cout << "Opening savings_file.txt failed. \n";
			exit(1);
		}

		savingsStreamOut << "$" << emergencyValue + savingsValue << endl;
		savingsStreamOut.close();
		cout << "Appending complete!\n";
		//append savings_file.txt with savingsAmount then close
	}*/
}