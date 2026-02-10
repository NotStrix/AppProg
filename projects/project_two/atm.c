/*
Jose Rosario
ECE Applications Programming
Fall 2025
Project Two: ATM

This program simulates a simple ATM machine. It prompts the user to enter a PIN,
then allows them to check their balance, withdraw money, or deposit money based on their input.
*/

#include <stdio.h>

int main() {
    int pin = 2160; // Correct PIN needed to continue
    int inputPin; // Variable to store user input PIN
    double balance = 2025.02; // Initial balance
    int selectOption; 
    double withdraw; 
    double deposit; 

    printf("Enter PIN: \n");
    scanf("%d", &inputPin); // Gets user input PIN
    if (inputPin != pin) {  // Check if PIN is correct
        printf("Invalid PIN--cannot login!\n");
    } 
    else {
        printf("Successful login! Select option\n");
        printf("(1 - check balance, 2 - withdraw money, 3 - deposit money):\n");
        scanf("%d", &selectOption);  // Gets user option
        
// All processes based on user option
    if (selectOption == 1) {  // Execute balance check
        printf("Current balance = $%.2lf\n", balance); 
    } 
    else if (selectOption == 2) {
        printf("Enter amount to withdraw: ");
        scanf("%lf", &withdraw);
        if (withdraw < 0) { // Checks if withdraw amount is valid
            printf("Invalid withdrawal amount $%.2lf\n", withdraw);  // Invalid due to negative amount
        }
        else if (withdraw > balance) { // Checks if withdraw amount exceeds balance
            printf("Cannot withdraw $%.2lf--balance too low\n", withdraw); 
        }
        else { // Execute withdrawal due to valid amount
            balance -= withdraw;
            printf("Withdrawing $%.2lf, new balance = $%.2lf", withdraw, balance);
        }
    }
    else if (selectOption == 3) { // Execute deposit 
        printf("Enter amount to deposit: ");
        scanf("%lf", &deposit);
        if (deposit <= 0) { // Checks if deposit amount is valid
            printf("Invalid deposit amount $%.2lf\n", deposit); 
        }
        else { // Execute deposit due to valid amount
            balance += deposit;
            printf("Depositing $%.2lf, new balance = $%.2lf", deposit, balance);
        }
    }
    else { // Invalid option entered
        printf("Invalid option %d\n", selectOption); 
    }
    }

    return 0;
}