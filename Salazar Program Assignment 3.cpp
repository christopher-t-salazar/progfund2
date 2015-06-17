//******************************************************************
// Programming Assignment 3
// Programmer: Christopher Salazar
// Completed : 06/16/2015
// Status    : Complete
//
// This program will help user balance his checkbook.
// Program is updated from previous assignment to include functions.
//******************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
void displayMenu();
void checkProcess(float&, float&, float&, int&);
void depositProcess(float&, float&, float&);

int main()
{
	float balance;				//User Balance
	float transAmount;			//Transaction Amount
	float totalCharge; 			//Total Charges
	int underBalance;			//Counter for under $800.00
	char userEntry; 			//User Choice Input
	const char PROCESS_CHECK = 'C';		//Process Check
	const char PROCESS_DEPOSIT = 'D';	//Process Deposit
	const char END_PROGRAM = 'E';		//End Program
	totalCharge = 0.0;			//Initalize Charges
	underBalance = 0;			//Initialize Counter

	cout << "****Checkbook Balancing Program****\n\n" << endl;
	cout << "Enter the beginning balance: ";
	cin >> balance;

	//Balance validation
	while (balance <= 0)
	{
		cout << "Error: Enter Beginning Balance again: ";
		cin >> balance;
	}

	//Do-While loop to drive menu/selection choices.
	do
	{
		//Calls to print menu.
		displayMenu();

		cout << "\nEnter a Transaction: ";
		cin >> userEntry;

		//If user decides to end program.
		if (userEntry == END_PROGRAM)
		{
			cout << "Processing end of month..." << endl;
			balance -= totalCharge;
			cout << "Final Balance: $" << balance << endl;
			exit(0);
		}

		cin >> transAmount;

		//Processing a check.
		if (userEntry == PROCESS_CHECK)
		{
			checkProcess(balance, transAmount, totalCharge, underBalance);
		}

		//Depositing a check.
		if (userEntry == PROCESS_DEPOSIT)
		{
			depositProcess(balance, transAmount, totalCharge);
			//Amount Validation
		}
	} while (userEntry != END_PROGRAM);

	//End program statements.
	cout << "Processing end of month" << endl;
	balance -= totalCharge;
	cout << "Final Balance: $" << balance << endl;
	return 0;
}

/*************************************
*This function displays menu choices.*
*************************************/
void displayMenu()
{
	cout << "\n~~~~Main Menu~~~~" << endl;
	cout << "C - Process a check. " << endl;
	cout << "D - Process a deposit." << endl;
	cout << "E - End the program." << endl;
}

/****************************************
*This function handles check processing.*
****************************************/
void checkProcess(float &bal, float &transAmt, float &ttlChge, int &underBal)
{
	const float CHECK_CHARGE = 0.25;	//Service Charges
	const float NEG_CHARGE = 25.00;		//Service Charge for negative balance
	const float BELOW_CHARGE = 5.00;	//Service Charge one time charge under $800.00

	cout << fixed << showpoint << setprecision(2);
	cout << "\n-----Transaction: Check-----" << endl;

	//Amount Validation
	while (transAmt <= 0)
	{
		cout << "Error: Please re-enter a valid transaction amount: ";
		cin >> transAmt;
	}

	//Print transaction amount.
	cout << "Processing check for $" << transAmt << endl;

	//Calculate and show user new balance
	bal -= transAmt;
	cout << "Balance: $" << bal << endl;

	//Calculating Charges
	//Check Processing Charge
	ttlChge += CHECK_CHARGE;
	cout << "Service Charge: $0.25 for a check" << endl;

	//One time fee if Balance falls under $800.00
	if (bal < 800 && underBal < 1)
	{
		ttlChge += BELOW_CHARGE;
		underBal++;
		cout << "Service Charge: $5.00 balance below $800.00" << endl;
	}

	//Service Charge of 25.00 if balance falls negative.
	if (bal < 0)
	{
		ttlChge += NEG_CHARGE;
		cout << "Service Charge: $25.00 for transaction resulting in" <<
			" a negative balance" << endl;
	}

	//Display total Charges
	cout << "Total service charges : $" << ttlChge << endl;
}

/********************************
*This function handles Deposits.*
********************************/
void depositProcess(float &bal, float &transAmt, float &ttlChge)
{
	//Amount Validation
	while (transAmt <= 0)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "Error: Please re-enter a valid transaction amount: ";
		cin >> transAmt;
	}

	//Calculating deposit and showing user new balance.
	bal += transAmt;
	cout << "\n-----Transaction: Deposit-----" << endl;
	cout << "Processing deposit for $" << transAmt << endl;
	cout << "Balance: $" << bal << endl;
	cout << "Total service charge: $" << ttlChge << endl;
}
