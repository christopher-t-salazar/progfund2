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
	double balance;  								//User Balance
	double transAmount;								//Transaction amount
	double totalCharge; 							//Total Charges
	const double serviceCharge = 0.25;				//Service Charges
	char userEntry;  								//User Choice Input
	const char choice1 = 'C';						//Process Check
	const char choice2 = 'D';						//Process Deposit
	const char choice3 = 'E';						//End Program
	totalCharge = 0.0;								//Initalize Charges


	cout << "****Checkbook Balancing Program****\n\n" << endl;
	cout << "Enter the beginning balance: ";
	cin >> balance;

	while (balance <=0)
	{
		cout <<"Error: Enter Beginning Balance again: ";
		cin >> balance;
	}

//Do-While loop to drive menu/selection choices.
	do
	{
		cout << "\n~~~~Main Menu~~~~" << endl;
		cout << "C - Process a check. " << endl;
		cout << "D - Process a deposit." << endl;
		cout << "E - End the program." << endl;
		cout << "\nEnter Transaction Type: ";
		cin >> userEntry;

//User Input Validation for Menu choice
		while (userEntry != choice1 && userEntry != choice2 && userEntry != choice3)
		{
			cout << "Error: Please enter a correct Transaction Type: ";
			cin >> userEntry;
		}

//Statements for processing a check.
		if (userEntry == choice1)
		{
			cout <<"\n----Process a check----" << endl;
			cout << "Enter transaction amount: ";
			cin >> transAmount;
//Amount Validation
			while (transAmount <=0)
			{
				cout << "Error: Please re-enter a valid transaction amount: ";
				cin >> transAmount;
			}
			cout << "Processing check for $" << fixed << showpoint << setprecision(2)
				<< transAmount << endl;
			cout << "Balance: $" << fixed << showpoint << setprecision(2)
				<< balance - transAmount << endl;
			cout << "Service charge: $0.25 for a check." << endl;
			totalCharge += serviceCharge;
			cout << "Total service charge: $" << fixed << showpoint << setprecision(2)
				<< totalCharge << endl;
		}

//Statements for depositing a check.
		if (userEntry == choice2)
		{
			cout << "\n----Process a deposit----" << endl;
			cout << "Enter transaction amount: ";
			cin >> transAmount;
//Amount Validation
			while (transAmount <=0)
			{
				cout << "Error: Please re-enter a valid transaction amount: ";
				cin >> transAmount;
			}
			cout << "Processing deposit for $" << fixed << showpoint
				<< setprecision(2) << transAmount << endl;
			cout << "Balance: $" << fixed << showpoint << setprecision(2)
				<< balance + transAmount << endl;
			cout << "Total service charge: $"<< fixed << showpoint << setprecision(2)
				<< totalCharge << endl;
		}
	} while(userEntry != choice3);

//End program statements.
	cout << "Processing end of month" << endl;
	balance -= totalCharge;
	cout << "Final Balance: $" << fixed << showpoint << setprecision(2)
		<< balance << endl;
	return 0;
}
