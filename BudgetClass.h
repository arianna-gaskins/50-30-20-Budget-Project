//BudgetClass.h
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class BudgetClass
{
	public:

		BudgetClass(double incomeValue, double billValue, double frivolityValue);
		//initializes income and purchases

		BudgetClass();
		//random default constructor until I figure out if I need constructors

		//BudgetClass operator = (const BudgetClass& randomVariable);
		//copy constructor cuz I might need that shit, also fix it dafuq

		//~BudgetClass();
		//destructor for the reset

		//double getIncome();
		//this function will get user input of income

		double getNeeds(double incomeValue);
		//will return needs value

		double getWants(double incomeValue);
		//will return wants value

		double getSavings(double incomeValue);
		//will return savings value

		double getBills(double billValue);
		//will return bills value

		double getFrivolity(double frivolityValue);
		//will return frivolity value

		void appendIncome(ofstream& incomeStreamOut, double incomeValue);
		//will append income_file.txt

		void appendNeeds(ofstream& needsStreamOut, double needsValue);
		//will append needs_file.txt

		void appendWants(ofstream& wantsStreamOut, double wantsValue);
		//will append wants_file.txt

		void appendSavings(ofstream& savingsStreamOut, double savingsValue);
		//will append savings_file.txt

		void appendBills(ofstream& billsStreamOut, double billsValue);
		//will append needs_purchase_file.txt with bills

		void appendFrivolity(ofstream& frivolityStreamOut, double frivolityValue);
		//will append wants_purchase_file.txt with frivolous purchases

		//void editOrView();
		//will ask if user wants to edit or view file if nothing is entered


	private:
		
		double income, needs, wants, savings, bill, frivolity;
		//values n shit

		void testValue();
		//will check for nonnegative values

		//void chooseEditFile();
		//redirects the user to append/edit the file of their choice

		//void chooseViewFile();
		//redirects the user to view the file of their choice

		//ofstream outIncome, outNeeds, outWants, outSavings;
		//declares file output streams for different categories
};
