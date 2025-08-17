#include <iostream>
#include "InvestmentCalculator.h"

using namespace std;

int main() {
    double initialAmount, monthlyDeposit, annualInterest;
    int years;

    // Greet the user and explain what the program does
    cout << "Welcome to the Airgead Banking Investment Calculator!\n";
    cout << "This tool will help you visualize how your investment grows over time.\n\n";

    // Get and validate user input
    cout << "Initial Investment Amount: $";
    cin >> initialAmount;
    while (initialAmount <= 0) {
        cout << "Please enter an amount greater than 0: $";
        cin >> initialAmount;
    }

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    while (monthlyDeposit < 0) {
        cout << "Monthly deposit can’t be negative. Please re-enter: $";
        cin >> monthlyDeposit;
    }

    cout << "Annual Interest Rate (in %): ";
    cin >> annualInterest;
    while (annualInterest <= 0) {
        cout << "Interest rate must be greater than 0: ";
        cin >> annualInterest;
    }

    cout << "Number of Years: ";
    cin >> years;
    while (years <= 0) {
        cout << "Please enter at least 1 year: ";
        cin >> years;
    }

    cout << "\nGenerating your investment report... Press Enter to continue.";
    cin.ignore();
    cin.get();

    // Create the calculator object using user input
    InvestmentCalculator calculator(initialAmount, monthlyDeposit, annualInterest, years);

    // Display both investment reports
    calculator.displayYearlyReportNoDeposit();
    calculator.displayYearlyReportWithDeposit();

    cout << "\nThank you for using the Airgead Banking tool. Goodbye!\n";
    return 0;
}