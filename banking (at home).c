/*/*
== Banking - Savings Account ==

Author	: Daniel Lifchitz
Date	:
Revision:
Workshop: #6 At-Home

*/

#include <stdio.h>


// Structure Declaration for account
struct account
{
	int accNumber;				// Account number
	double balance;				// Balance of the account
};

/*  Function to add an amount if positive-valued */
//

double balanceup(double balance, double amount) {



	if (amount > 0) {

		balance = balance + amount;
		return balance;

	}
	else {

		return balance;
	}
}


/* Function to calculate the interest rate*/
//
double interestCalc(double balance, double rate)
{

	balance = (balance * (rate / 100));
	return balance;



}

/* Function to deduct an amount if positive-valued*/

double balancedown(double balance, double amount) {



	if (amount > 0) {

		balance = balance - amount;
		return balance;

	}
	else {

		return balance;
	}
}







/* main program */
int main(void)
{
	
	// Number of accounts
	int option;											// Hold the selection
	int tmp, i;
	float amount;
	double calcInterest;
	// Initialize the struct account array with opening balance
	struct account acct[] = { { 11111111, 123.45 },{ 22222222, 12365.50 },{ 33333333,0 },{ 44444444,1475 },{ 55555555,25000.65 } };
	double rate;
	double service_charge;

	printf("***** Welcome to Savings Account Banking *****\n\n");

	do
	{
		// Print the option list
		printf("1.) Deposit \n");
		printf("2.) Withdraw\n");
		printf("3.) Apply monthly interest earnings to all accounts\n");
		printf("4.) Apply service charges to all accounts\n");
		printf("5.) Account Summary\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");

		// Waiting for the input
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0: // Exit the program
			break;

		case 1: // Deposit

			printf("-- Make a deposit --\n");
			printf("\n");
			printf("Enter account number: ");
			scanf("%8d", &tmp);



			for (i = 0; i < 5; i++)
			{
				if (acct[i].accNumber == tmp)
				{


					printf("Enter amount to deposit (CAD): ");
					scanf("%f", &amount);
					acct[i].balance = balanceup(acct[i].balance, amount);
					printf("Current balance is : %.2f\n", acct[i].balance);
					printf("\n");
					break;
				}

			}
			if (acct[i].accNumber != tmp)
			{
				printf("ERROR: Account number does not exist.\n");
				printf("\n");
				break;
			}
			break;




		case 2: // Withdraw funds
				//@HOME
			printf("-- Withdraw funds --\n");
			printf("\n");
			printf("Enter account number: ");
			scanf("%8d", &tmp);



			for (i = 0; i < 5; i++)
			{
				if (acct[i].accNumber == tmp)
				{


					printf("Enter amount to withdraw (CAD): ");
					scanf("%f", &amount);
					
					if (amount > acct[i].balance)
					{
						printf("Withdrawal failed. You only have : %.2f in your account\n", acct[i].balance);
						printf("\n");
						break;
					}

					acct[i].balance = balancedown(acct[i].balance, amount);
					printf("Current balance is : %.2f\n", acct[i].balance);
					printf("\n");
					break;
				}

			}
			if (acct[i].accNumber != tmp)
			{
				printf("ERROR: Account number does not exist.\n");
				printf("\n");
				break;
			}
			break;





		case 3: // Apply interest earnings to all accounts
				//@IN-LAB
		
			printf("-- Add monthly interest earnings to all accounts --\n");
			printf("\n");
			printf("Account# New Balance Interest Earnings (M)\n");
			printf("-------- ----------- ---------------------\n");

			for (i = 0; i < 5; i++)
			{
				{
					if (acct[i].balance < 500)

						rate = 0.99;

					else if (acct[i].balance == 12365.50 || acct[i].balance == 25000.65)

						rate = 2.49;

					else if (500 < acct[i].balance || acct[i].balance < 1500)

						rate = 1.66;


				}


				calcInterest = interestCalc(acct[i].balance, rate);
				acct[i].balance = balanceup(acct[i].balance, calcInterest);
				printf("%8d %11.2lf %21.2lf\n", acct[i].accNumber, acct[i].balance, calcInterest);

			}
			printf("\n");
			break;



		case 4: // Apply Service Charges
				//@HOME
			
			printf("-- Apply service charges to all accounts --\n");
			printf("\n");
			printf("Account# New Balance Service charges (M)\n");
			printf("-------- ----------- -------------------\n");

			for (i = 0; i < 5; i++)
			{
				{
					if (acct[i].balance < 1500)

						service_charge = 7.50;


					else if (acct[i].balance > 1500)

						service_charge = 2.50;


				}


				//calcInterest = interestCalc(acct[i].balance, rate);
				acct[i].balance = balancedown(acct[i].balance, service_charge);
				printf("%8d %11.2lf %19.2lf\n", acct[i].accNumber, acct[i].balance, service_charge);

			}
			printf("\n");
			break;



		case 5: // Display Account Information



			printf("-- Account information --\n");
			printf("\n");
			printf("Account# Balance   ");
			printf("\n-------- ----------\n");

			for (i = 0; i < 5; i++)
			{

				printf("%8d %10.2lf\n", acct[i].accNumber, acct[i].balance);
				
			}

			printf("\n");
		
		//default:
			//printf("Error: Please enter a valid option to continue\n\n");
			//break;
		}


	} while (option != 0);


	return 0;
}

