//******************************************************************
// Programming Assignment 2
// Programmer: Christopher Salazar
// Completed : 06/11/2015
// Status    : Complete
//
// This program will help user balance his checkout.
//******************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double balance;  													//User Balance
	double transAmount;												//Transaction amount
	double totalCharge; 											//Total Charges
	const double serviceCharge = 0.25;				//Service Charges
	char userEntry;  													//User Choice Input
	const char choice1 = 'C';									//Process Check
	const char choice2 = 'D';									//Process Deposit
	const char choice3 = 'E';									//End Program


	cout << "****Checkbook Balancing Program****\n\n" << endl;
	cout << "Enter the beginning balance: ";
	cin >> balance;

	while (balance <= 0)
	{
		cout <<"Error: Enter Beginning Balance again: ";
		cin >> balance;
	}

//Do-While loop to drive menu/selection choices.
	do
	{
		cout << "\n~~~~Commands~~~~" << endl;
		cout << "C - Process a check. " << endl;
		cout << "D - Process a deposit." << endl;
		cout << "E - End the program." << endl;
		cout << "\nEnter Transaction Type: ";
		cin >> userEntry;

		while (userEntry != choice1 && userEntry != choice2 && userEntry != choice3)
		{
			cout << "Error: Please enter a correct Transaction Type: ";
			cin >> userEntry;
		}
		if (userEntry == choice1)
		{
			cout << "Enter transaction amount:";
			cin >> transAmount;
			while (transAmount <=0) 
			{
				cout << "Error: Please re-enter a valid transaction amount: "
				cin <<transAmount;
			}
			cout << "Processing check for" << transAmount <<endl;
		}
	} while(userEntry != choice3);
	return 0;

}
